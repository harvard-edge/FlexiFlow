import seaborn as sns
import matplotlib.pyplot as plt
import os
from lifetime_modeling import *
import matplotlib.patches as mpatches
import textwrap

workload_params_dict = {
    "Food Spoilage Detection": {"lifetime_yrs": 1/52, "inf_freq": 365},      # 1x/day for 1 week
    "Cardiotocography": {"lifetime_yrs": 0.75, "inf_freq": 365*24*4},        # 4x/hour for 9 months (wearable monitor)
    "Arrhythmia Detection": {"lifetime_yrs": 2/52, "inf_freq": 365*24*60},   # 1x/min for 2 weeks (continuous ECG patch)
    "Water Quality Monitoring": {"lifetime_yrs": 7/365, "inf_freq": 365/7},  # 1x over 7 days (single use strip, 7 days to not mess up bounds)
    "HVAC Control": {"lifetime_yrs": 20, "inf_freq": 365*24},                # 1x/hour for 20 years (building sensor)
    "Package Tracking": {"lifetime_yrs": 3/52, "inf_freq": 365*24},          # 1x/hour for 3 weeks (disposable tracker)
    "Gesture Recognition": {"lifetime_yrs": 2, "inf_freq": 365*24*60*4},     # 1x/15sec for 2 years (wearable)
    "Air Pollution Monitoring": {"lifetime_yrs": 4, "inf_freq": 365*24},     # 1x/hour for 4 years (outdoor station)
    "Malodor Classification": {"lifetime_yrs": 4, "inf_freq": 365},          # 1x/day for 4 years (clothing sensor)
    "Smart Irrigation Control": {"lifetime_yrs": 0.5, "inf_freq": 365/3},    # 1x/3 days for 6 months (field sensor)
}

def plot_all_workloads_best_system_region(
    carbon_intensity = 367,
    core_freq = 10000,
    workload_params_dict = {},  # dict: workload -> dict with keys 'lifetime_yrs', 'inf_freq'
    output_pdf="plots/all_workloads_best_system_region.pdf",
    subplot_order=None,    # Optional: list of workloads in desired order
    ncols=5,
    nrows=2,
    title_wrap_width=16,   # Number of characters before wrapping workload names
    hashes_grey = False,
    whitespace = 0,
    title_top = False
):
    """
    Args:
        workload_params_dict: dict mapping workload name to dict with keys 'lifetime_yrs' and 'inf_freq'
            Example: {
                "workload1": {"lifetime_yrs": 2, "inf_freq": 1000},
                "workload2": {"lifetime_yrs": 1, "inf_freq": 500},
                ...
            }
        carbon_intensity: float
        core_freq: float
        output_pdf: str, path to save PDF (if not empty)
        subplot_order: list of workload names, determines subplot order (optional)
        ncols: int, number of columns in subplot grid
        nrows: int, number of rows in subplot grid
        title_wrap_width: int, max characters per line for workload name
    """
    sns.set_theme(style="whitegrid", font_scale=1.2, rc={"axes.facecolor": "white"})
    # Determine order of workloads
    if subplot_order is not None:
        workloads = subplot_order
    else:
        workloads = list(embodied_values.keys())
    n = len(workloads)

    # Make a grid with more whitespace between subplots
    fig, axes = plt.subplots(
        nrows, ncols, 
        figsize=(3 * ncols, 3 * nrows), 
        gridspec_kw=dict(wspace=whitespace, hspace=whitespace)
    )
    axes = axes.flatten()

    for i, workload in enumerate(workloads):
        if i >= len(axes):
            break  # Don't plot more than grid allows
        ax = axes[i]
        # Remove axis labels for all subplots
        ax.set_xlabel("")
        ax.set_ylabel("")
        # Determine subplot row and column
        row = i // ncols
        col = i % ncols
        
        ax.tick_params(labelleft=False, labelbottom = False)
        if whitespace == 0:
            if col == 0 and row == nrows-1:
                ax.tick_params(labelleft=True, labelbottom=True, left=True, bottom=True)
        else:
            if col == 0:
                ax.tick_params(labelleft=True, left=True)
            if row == nrows-1:
                ax.tick_params(labelbottom=True, bottom=True)

        # Get params for this workload
        params = workload_params_dict.get(workload, {})
        lifetime_yrs = params.get("lifetime_yrs", 1)
        inf_freq = params.get("inf_freq", 1)
        x, y, mask = plot_best_system_region_map_ax(
            ax=ax,
            workload_choice=workload,
            lifetime_yrs=lifetime_yrs,
            inf_freq=inf_freq,
            carbon_intensity=carbon_intensity,
            core_freq=core_freq,
            hashes_grey=hashes_grey
        )

        if title_top == False:
            # Wrap long workload names and center vertically
            wrapped_workload = "\n".join(textwrap.wrap(str(workload), width=title_wrap_width))
            num_lines = wrapped_workload.count('\n') + 1
            # Center the text vertically by adjusting y based on number of lines
            ax.text(
                0.5, 0.5, wrapped_workload,
                transform=ax.transAxes,
                ha='center', va='center',
                fontsize=18, fontweight='bold',
                color='black',
                bbox=dict(facecolor='white', alpha=0.5, edgecolor='none', boxstyle='round,pad=0.2')
            )
        else:
            ax.set_title(str(workload))
        # Remove legend from all subplots
        ax.legend().remove()
        # Add a visible border to each subplot
        for spine in ax.spines.values():
            spine.set_visible(True)
            spine.set_linewidth(2)
            spine.set_color('black')

    # Hide any unused subplots
    for j in range(i+1, len(axes)):
        fig.delaxes(axes[j])
    # Remove any axes and titles labels from all subplots
    for ax in axes:
        ax.set_xlabel("")
        ax.set_ylabel("")
        if title_top == False:
            ax.set_title("")

    # Add one shared x and y label, with x label shifted left
    if whitespace == 0:
        fig.supxlabel("Application Lifetime (years)", fontsize=18, x = 0.52, y = 0.05)
        fig.supylabel("Task Frequency (Program Executions/Year)", fontsize=18, x=-0.01, y=0.55)
    else:
        fig.supxlabel("Application Lifetime (years)", fontsize=18, x = 0.5, y = -0.12)
        fig.supylabel("Task Frequency (Program Executions/Year)", fontsize=18, x=-0.05, y=0.5)

    # Use seaborn color palette for legend handles
    palette = sns.color_palette("colorblind", n_colors=len(system_colors))
    legend_handles = [
        plt.Line2D([0], [0], marker='o', color='w', markerfacecolor=palette[i], markersize=15, label=system)
        for i, system in enumerate(system_colors.keys())
    ]
    # Add a red star for "Example Usecase"
    legend_handles.append(
        plt.Line2D([0], [0], marker='*', color='w', markerfacecolor='red', markeredgecolor='red', markersize=18, label="Example Usecase")
    )


    crosshatch_patch = mpatches.Patch(facecolor='grey' if hashes_grey else 'none', hatch='xx', label='Task Freq. Not Possible', edgecolor='black')
    legend_handles.append(crosshatch_patch)
    legend_labels = list(system_colors.keys()) + ["Example Use Case", "Task Freq. Not Possible"]
    fig.legend(
        legend_handles, legend_labels,
        loc='upper center', ncol=len(legend_labels),
        bbox_to_anchor=(0.5, 1.1 if title_top == False else 1.13), fontsize=16, frameon=False
    )

    # Remove all whitespace around and between subplots
    plt.subplots_adjust(left=0, right=1, top=1, bottom=0, wspace=0, hspace=0)
    plt.tight_layout(pad=0)

    # Ensure the output directory exists and save if requested
    if output_pdf:
        os.makedirs(os.path.dirname(output_pdf), exist_ok=True)
        plt.savefig(output_pdf, format="pdf", bbox_inches='tight')
    plt.close(fig)

if __name__ == '__main__':
    whitespace = 0.2

    load_execution_time_from_csv("timing.csv")
    load_embodied_values_from_csv("embodied-carbon.csv")
    load_memory_from_csv("memory.csv")

    plot_all_workloads_best_system_region(
        workload_params_dict=workload_params_dict,
        carbon_intensity=367,
        core_freq=10000,
        output_pdf=f"plots/all_workloads_best_system_region{"" if whitespace == 0 else "_whitespace"}.pdf",
        hashes_grey=False,
        whitespace=whitespace
    )
    plot_all_workloads_best_system_region(
        workload_params_dict=workload_params_dict,
        carbon_intensity=367,
        core_freq=10000,
        output_pdf=f"plots/all_workloads_best_system_region_grey_region{"" if whitespace == 0 else "_whitespace"}.pdf",
        hashes_grey=True,
        whitespace=whitespace
    )
    plot_all_workloads_best_system_region(
        workload_params_dict=workload_params_dict,
        carbon_intensity=367,
        core_freq=10000,
        output_pdf=f"plots/all_workloads_best_system_region_title_top{"" if whitespace == 0 else "_whitespace"}.pdf",
        hashes_grey=False,
        whitespace=whitespace,
        title_top=True
    )
    plot_all_workloads_best_system_region(
        workload_params_dict=workload_params_dict,
        carbon_intensity=367,
        core_freq=10000,
        output_pdf=f"plots/all_workloads_best_system_region_grey_region_title_top{"" if whitespace == 0 else "_whitespace"}.pdf",
        hashes_grey=True,
        whitespace=whitespace,
        title_top=True
    )
