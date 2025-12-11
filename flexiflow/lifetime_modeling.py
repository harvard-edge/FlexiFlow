import numpy as np
import pandas as pd
import seaborn as sns
import matplotlib.pyplot as plt
from matplotlib.colors import ListedColormap
import matplotlib.patches as mpatches

# Define global variables for max and min values
MIN_LIFETIME = 0.01
MAX_LIFETIME = 20
MIN_INF_FREQ = 1
MAX_INF_FREQ = 365*100000
MIN_CORE_FREQ = 1000
MAX_CORE_FREQ = 100000

system_colors = {'Serv': '#4c72b0', 'Qerv': '#dd8452', 'Herv': '#55a868'}

# -------------------------
# 1) Define Internal Data
# -------------------------
system_specs = {
    "Serv": {"area": 2.93, "power": 17.7451},
    "Qerv": {"area": 3.68, "power": 21.0650},
    "Herv": {"area": 4.50, "power": 24.9934},
}

rf_sram = 128 # Implementing register file in SRAM for space-saving

# Define SRAM and LPROM constants (in bits)
sram_power = 0.0018
sram_area = 0.00176
lprom_power = 0 # negligible
lprom_area = 0.000359
sram_overhead_power = 0.0002 # per bit
sram_overhead_area = 0.0003 # per bit

# Global dictionaries for memory values
sram = {}
lprom = {}

def load_memory_from_csv(csv_path="memory.csv"):
    global sram, lprom
    df = pd.read_csv(csv_path)
    temp_sram = {}
    temp_lprom = {}
    for _, row in df.iterrows():
        workload = row["Workload"]
        temp_sram[workload] = int(row["sram"])
        temp_lprom[workload] = int(row["lprom"])
    sram.clear()
    sram.update(temp_sram)
    lprom.clear()
    lprom.update(temp_lprom)

# Define carbon intensity values for each power source
# gCO2 eq / kWhr
# Source: https://www.eia.gov/tools/faqs/faq.php?id=74&t=11
# And: https://www.energy.gov/eere/wind/articles/how-wind-can-help-us-breathe-easier
carbon_intensity_values = {
    "US Avg (2023)": "367",
    "Petroleum": "1116",
    "Coal": "1048",
    "Solar": "28",
    "Nuclear": "13",
    "Wind": "12",
    "Custom": ""
}

# These need to be loaded in
execution_time = {}
embodied_values = {}

def load_embodied_values_from_csv(csv_path="embodied-carbon.csv"):
    global embodied_values
    df = pd.read_csv(csv_path)
    temp_embodied_values = {}
    # Build the embodied_values dictionary from the DataFrame
    for _, row in df.iterrows():
        workload = row["Workload"]
        cpu = row["CPU Design"]
        min_val = row["Carbon Footprint Min (gCO2e)"]
        max_val = row["Carbon Footprint Max (gCO2e)"]
        if workload not in temp_embodied_values:
            temp_embodied_values[workload] = {}
        temp_embodied_values[workload][cpu] = {
            "Carbon Footprint Min (gCO2e)": min_val,
            "Carbon Footprint Max (gCO2e)": max_val
        }
    embodied_values.clear()
    embodied_values.update(temp_embodied_values)
    

def load_execution_time_from_csv(csv_path="timing.csv"):
    global execution_time
    df = pd.read_csv(csv_path)
    temp_execution_time = {}
    for _, row in df.iterrows():
        workload = row["Workload"]
        temp_execution_time[workload] = {
            "Serv": float(row["Serv"]),
            "Qerv": float(row["Qerv"]),
            "Herv": float(row["Herv"]),
        }
    execution_time.clear()
    execution_time.update(temp_execution_time)
    return execution_time

def compute_total_carbon(
    system: str,
    workload: str,
    lifetime_yrs: float,
    inf_freq: float, # per year
    carbon_intensity: float,
    core_freq: float
):
    """
    Compute the total carbon footprint of a given system with the user-specified parameters.
    Returns (embodied_carbon, operational_carbon, total_carbon).
    """
    sram_bytes = sram[workload] + rf_sram
    lprom_bytes = lprom[workload]

    # 1) Calculate total area (Precomputed in CSV)
    # core_area = system_specs[system]["area"]
    # device_area = core_area + (sram_area + sram_overhead_area) * sram_bytes * 8 + lprom_area * lprom_bytes * 8
    # 2) Embodied carbon (Precomputed in CSV)
    embodied_carbon = embodied_values[workload][system]["Carbon Footprint Max (gCO2e)"]
    # 3) Operational carbon
    system_power = system_specs[system]["power"]
    total_power = system_power + (sram_power + sram_overhead_power) * sram_bytes * 8 + lprom_power * lprom_bytes * 8

    # Convert lifetime in years to total inferences:
    total_inferences = inf_freq * lifetime_yrs
    time_per_inference = execution_time[workload][system] / core_freq  # Adjusted with core frequency
    total_energy = total_power * time_per_inference * total_inferences
    operational_carbon = total_energy * carbon_intensity

    total_carbon = embodied_carbon + operational_carbon

    return embodied_carbon, operational_carbon, total_carbon

def plot_total_carbon_vs_lifetime_ax(ax, workload_choice, lifetime_yrs, inf_freq, carbon_intensity, core_freq):
    """
    Plot total carbon vs. device lifetime for each system on the given axis.
    """
    carbon_intensity = float(carbon_intensity) / 3600 / 1000000
    core_freq = float(core_freq)

    lifetimes = np.linspace(MIN_LIFETIME, MAX_LIFETIME, 50)
    plot_data = []
    for system in system_specs:
        total_carbons = []
        for lifetime in lifetimes:
            _, _, total = compute_total_carbon(system, workload_choice, lifetime, inf_freq, carbon_intensity, core_freq)
            total_carbons.append(total)
        plot_data.append(pd.DataFrame({
            "Lifetime": lifetimes,
            "Total Carbon": total_carbons,
            "System": system
        }))
    df_plot = pd.concat(plot_data, ignore_index=True)
    sns.lineplot(data=df_plot, x="Lifetime", y="Total Carbon", hue="System", palette=system_colors, ax=ax)
    ax.axvline(x=lifetime_yrs, color='gray', linestyle ='--', linewidth=1)
    ax.set_title(f"Total Carbon vs. Lifetime\nWorkload: {workload_choice}")
    ax.set_xlabel("Lifetime (years)")
    ax.set_ylabel("Total Carbon Footprint (gCO₂-eq)")
    ax.legend()

def plot_total_carbon_vs_frequency_ax(ax, workload_choice, lifetime_yrs, inf_freq, carbon_intensity, core_freq):
    """
    Plot total carbon vs. inference frequency for each system on the given axis.
    """
    carbon_intensity = float(carbon_intensity) / 3600 / 1000000
    core_freq = float(core_freq)

    inf_frequencies = np.logspace(np.log10(MIN_INF_FREQ), np.log10(MAX_INF_FREQ), 50)
    max_found_valid_freq = MIN_INF_FREQ
    valid_frequencies_any = []
    plot_data = []

    for system in system_specs:
        total_carbons = []
        valid_frequencies = []
        for freq in inf_frequencies:
            if execution_time[workload_choice][system] / core_freq <= 365 * 3600 / freq:
                _, _, total = compute_total_carbon(system, workload_choice, lifetime_yrs, freq, carbon_intensity, core_freq)
                total_carbons.append(total)
                valid_frequencies.append(freq)
                max_found_valid_freq = max(max_found_valid_freq, freq)
            else:
                break
        valid_frequencies_any.extend(valid_frequencies)
        plot_data.append(pd.DataFrame({
            "Frequency": valid_frequencies,
            "Total Carbon": total_carbons,
            "System": system
        }))

    if len(valid_frequencies_any) > 0:
        df_plot = pd.concat(plot_data, ignore_index=True)
        sns.lineplot(data=df_plot, x="Frequency", y="Total Carbon", hue="System", palette=system_colors, ax=ax, legend=True)
        ax.axvline(x=inf_freq, color='gray', linestyle ='--', linewidth=1)
        ax.set_xscale('log')
        ax.set_yscale('log')
        ax.set_title(f"Total Carbon vs. Task Frequency\nWorkload: {workload_choice}")
        ax.set_xlabel("Task Frequency (tasks/year)")
        ax.set_ylabel("Total Carbon Footprint (gCO₂-eq)")
        ax.legend()
    else:
        ax.set_title(f"No valid frequencies for {workload_choice} between {MIN_INF_FREQ} and {MAX_INF_FREQ} tasks/year")

def plot_total_carbon_vs_num_inferences_ax(ax, workload_choice, lifetime_yrs, inf_freq, carbon_intensity, core_freq):
    """
    Plot total carbon vs. number of inferences for each system on the given axis.
    """
    carbon_intensity = float(carbon_intensity) / 3600 / 1000000
    core_freq = float(core_freq)

    inferences = np.logspace(np.log10(MIN_INF_FREQ * MIN_LIFETIME), np.log10(MAX_INF_FREQ * MAX_LIFETIME), 50)
    plot_data = []
    for system in system_specs:
        total_carbons = []
        for inf in inferences:
            lt = inf / inf_freq
            _, _, total = compute_total_carbon(system, workload_choice, lt, inf_freq, carbon_intensity, core_freq)
            total_carbons.append(total)
        plot_data.append(pd.DataFrame({
            "Inferences": inferences,
            "Total Carbon": total_carbons,
            "System": system
        }))
    df_plot = pd.concat(plot_data, ignore_index=True)
    sns.lineplot(data=df_plot, x="Inferences", y="Total Carbon", hue="System", palette=system_colors, ax=ax)
    ax.axvline(x=inf_freq * lifetime_yrs, color='gray', linestyle='--', linewidth=1)
    ax.set_xscale('log')
    ax.set_yscale('log')
    ax.set_title(f"Total Carbon vs. Number of Executed Tasks\nWorkload: {workload_choice}")
    ax.set_xlabel("Number of Tasks")
    ax.set_ylabel("Total Carbon Footprint (gCO₂-eq)")
    ax.legend()

def plot_best_system_region_map_ax(ax, workload_choice, lifetime_yrs, inf_freq, carbon_intensity, core_freq, hashes_grey = False):
    """
    Plot a 2D region map of best system choice for a grid of (lifetime, inference frequency) on the given axis.
    Uses fill_between to color regions between system intersection contours.
    """
    carbon_intensity = float(carbon_intensity) / 3600 / 1000000
    core_freq = float(core_freq)

    # Create a fine grid for smooth contours
    lifetime_grid = np.logspace(np.log10(MIN_LIFETIME), np.log10(MAX_LIFETIME), 200)
    inf_freq_grid = np.logspace(np.log10(MIN_INF_FREQ), np.log10(MAX_INF_FREQ), 200)
    X, Y = np.meshgrid(lifetime_grid, inf_freq_grid)
    systems = list(system_specs.keys())

    carbon_values = np.ones((len(systems), len(inf_freq_grid), len(lifetime_grid))) * np.inf
    max_found_valid_freq = MIN_INF_FREQ
    for sys_idx, sys_name in enumerate(systems):
        for i, freq in enumerate(inf_freq_grid):
            for j, lt in enumerate(lifetime_grid):
                _, _, total = compute_total_carbon(sys_name, workload_choice, lt, freq, carbon_intensity, core_freq)
                carbon_values[sys_idx, i, j] = total
                if execution_time[workload_choice][sys_name] / core_freq <= 365 * 3600 / freq:
                    max_found_valid_freq = max(max_found_valid_freq, freq)

    best_indices = np.argmin(carbon_values, axis=0)

    # SERV - QERV Intersection

    # Draw SERV-QERV intersection contour (only where either is best)
    diff_serv_qerv = carbon_values[0] - carbon_values[1]
    mask_serv_qerv = (best_indices == 0) | (best_indices == 1)
    masked_diff_serv_qerv = np.ma.masked_where(~mask_serv_qerv, diff_serv_qerv)
    serv_qerv_contour = ax.contour(
        X, Y, masked_diff_serv_qerv, levels=[0], colors='black', linestyles='-', linewidths=2,zorder=3
    )

    # Draw QERV-HERV intersection contour (only where either is best)
    diff_qerv_herv = carbon_values[1] - carbon_values[2]
    mask_qerv_herv = (best_indices == 2) | (best_indices == 1)
    masked_diff_qerv_herv = np.ma.masked_where(~mask_qerv_herv, diff_qerv_herv)
    qerv_herv_contour = ax.contour(
        X, Y, masked_diff_qerv_herv, levels=[0], colors='black', linestyles='-', linewidths=2,zorder=3
    )

    # To fill regions between/around the contours, we need to extract the contour lines as (x, y) arrays,
    # interpolate them onto the same x-grid, and use fill_between.

    # Helper to extract a single contour line as (x, y) arrays, and extend to plot bounds if needed
    def get_contour_line(contour):
        # contour: a QuadContourSet object from ax.contour
        # In recent matplotlib, QuadContourSet has attribute 'collections', but if not, use 'allsegs'
        # Try to use 'collections' if available, else fallback to 'allsegs'
        paths = None
        if hasattr(contour, "collections"):
            if len(contour.collections) == 0:
                return None, None
            paths = contour.collections[0].get_paths()
        elif hasattr(contour, "allsegs"):
            # allsegs is a list of lists of arrays: allsegs[level][segment][point]
            # We want the first level (should be only one, since we used levels=[0])
            if len(contour.allsegs) == 0 or len(contour.allsegs[0]) == 0:
                return None, None
            # Find the longest segment
            segments = contour.allsegs[0]
            max_seg = max(segments, key=lambda seg: seg.shape[0])
            x, y = max_seg[:, 0], max_seg[:, 1]
            sort_idx = np.argsort(x)
            x, y = x[sort_idx], y[sort_idx]
        else:
            return None, None

        if paths is not None:
            if len(paths) == 0:
                return None, None
            # Take the longest path (in case of multiple)
            max_path = max(paths, key=lambda p: p.vertices.shape[0])
            x, y = max_path.vertices[:, 0], max_path.vertices[:, 1]
            # Sort by x for fill_between
            sort_idx = np.argsort(x)
            x, y = x[sort_idx], y[sort_idx]

        # Now, extend the contour to the bounds if needed
        # Use the global lifetime_grid for bounds
        x_min, x_max = MIN_LIFETIME, MAX_LIFETIME
        # If the contour doesn't start at x_min, extend it horizontally at the edge y-value
        if x[0] > x_min:
            x = np.insert(x, 0, x_min)
            y = np.insert(y, 0, y[0])
        # If the contour doesn't end at x_max, extend it horizontally at the edge y-value
        if x[-1] < x_max:
            x = np.append(x, x_max)
            y = np.append(y, y[-1])
        return x, y

    # Get (x, y) for SERV-QERV and QERV-HERV contours
    x_sq, y_sq = get_contour_line(serv_qerv_contour)
    x_qh, y_qh = get_contour_line(qerv_herv_contour)

    # Use the lifetime_grid as the x-axis for fill_between
    x_fill = lifetime_grid

    # Helper to interpolate contour y-values onto x_fill
    def interp_contour(xc, yc):
        if xc is None or yc is None or len(xc) < 2:
            return np.full_like(x_fill, np.nan)
        # Remove duplicate x values for interpolation
        unique_x, idx = np.unique(xc, return_index=True)
        unique_y = yc[idx]
        # Only interpolate within the range of the contour
        y_interp = np.interp(x_fill, unique_x, unique_y, left=np.nan, right=np.nan)
        return y_interp

    y_sq_interp = interp_contour(x_sq, y_sq)
    y_qh_interp = interp_contour(x_qh, y_qh)

    # Fill SERV region: from bottom (min inf freq) to SERV-QERV contour
    ax.fill_between(
        x_fill,
        MIN_INF_FREQ * np.ones_like(x_fill),
        y_sq_interp,
        where=~np.isnan(y_sq_interp),
        color=system_colors['Serv'],
        alpha=0.5,
        zorder=0
    )

    # Fill QERV region: between SERV-QERV and QERV-HERV contours
    ax.fill_between(
        x_fill,
        y_sq_interp,
        y_qh_interp,
        where=~np.isnan(y_sq_interp) & ~np.isnan(y_qh_interp) & (y_qh_interp > y_sq_interp),
        color=system_colors['Qerv'],
        alpha=0.5,
        zorder=1
    )

    # Fill HERV region: from QERV-HERV contour to top (max inf freq)
    ax.fill_between(
        x_fill,
        y_qh_interp,
        MAX_INF_FREQ * np.ones_like(x_fill),
        where=~np.isnan(y_qh_interp),
        color=system_colors['Herv'],
        alpha=0.5,
        zorder=0
    )

    # Add legend handles
    handles = [
        plt.Line2D([0], [0], marker='o', color='w', label='Serv', markersize=10, markerfacecolor=system_colors['Serv']),
        plt.Line2D([0], [0], marker='o', color='w', label='Qerv', markersize=10, markerfacecolor=system_colors['Qerv']),
        plt.Line2D([0], [0], marker='o', color='w', label='Herv', markersize=10, markerfacecolor=system_colors['Herv']),
    ]

    # Mask for infeasible frequencies
    freq_mask = Y > max_found_valid_freq
    hatch_mask = np.where(freq_mask, 1, np.nan)
    if hashes_grey:
        ax.contourf(X, Y, hatch_mask, levels=[0.5, 1.5], colors='grey', hatches=['xx'],zorder=2)._hatch_color=(0,0,0,1)
        crosshatch_patch = mpatches.Patch(facecolor='grey', hatch='xx', label='Task Freq. Not Possible', edgecolor='black')
    else:
        ax.contourf(X, Y, hatch_mask, levels=[0.5, 1.5], colors='none', hatches=['xx'],zorder=2)._hatch_color=(0,0,0,1)
        crosshatch_patch = mpatches.Patch(facecolor='none', hatch='xx', label='Task Freq. Not Possible', edgecolor='black')
    handles.append(crosshatch_patch)
    ax.legend(handles=handles, title="Systems", loc='lower left')

    # Plot a star marker at the currently selected lifetime & inference frequency
    ax.plot([lifetime_yrs], [inf_freq], marker='*', color='red', markersize=10, zorder=3)

    ax.set_xscale('log')
    ax.set_yscale('log')
    ax.set_title("Best System Choice by (Lifetime, Task Freq)")
    ax.set_xlabel("Lifetime (years)")
    ax.set_ylabel("Task Frequency (tasks/year)")

    # Make grid lines more visible
    # Only show major gridlines (powers of ten), solid lines
    ax.grid(True, which='major', color='gray', linestyle='-', linewidth=1.2, alpha=0.7, zorder=5)

    return X, Y, hatch_mask


def plot_carbon_vs_lifetime(workload_choice, lifetime_yrs, inf_freq, carbon_intensity, core_freq):
    """
    Plot all carbon plots for the given parameters in a 2x2 grid of subplots.
    Returns the matplotlib Figure object.
    """
    fig, axs = plt.subplots(2, 2, figsize=(16, 12))
    plt.subplots_adjust(hspace=0.3, wspace=0.25)

    plot_total_carbon_vs_lifetime_ax(axs[0, 0], workload_choice, lifetime_yrs, inf_freq, carbon_intensity, core_freq)
    plot_total_carbon_vs_frequency_ax(axs[0, 1], workload_choice, lifetime_yrs, inf_freq, carbon_intensity, core_freq)
    plot_total_carbon_vs_num_inferences_ax(axs[1, 0], workload_choice, lifetime_yrs, inf_freq, carbon_intensity, core_freq)
    plot_best_system_region_map_ax(axs[1, 1], workload_choice, lifetime_yrs, inf_freq, carbon_intensity, core_freq)

    # Optionally, set a main title
    fig.suptitle(f"Carbon Footprint Analysis for {workload_choice}", fontsize=18)
    return fig