import numpy as np
import seaborn as sns
import matplotlib.pyplot as plt
from matplotlib.lines import Line2D
import ipywidgets as widgets
from ipywidgets import interact, FloatSlider, IntSlider, Dropdown
from lifetime_modeling import *
import pandas as pd

STAR_SIZE = 350
X_SIZE = 100
TEXT_SIZE = 18

workload_accuracies = {
    "DT-Small": 414 / 555,
    "DT-Medium": 465 / 555,
    "DT-Large": 528 / 555,
    "KNN-Large": 549 / 555,
    "KNN-Medium": 547 / 555,
    "KNN-Small": 535 / 555,
    "LR": 545 / 555,
    "MLP": 507 / 555
}


def plot_accuracy_vs_carbon(
    lifetime_years, 
    tasks_per_year, 
    carbon_intensity,
    ax,
    text_size=TEXT_SIZE, 
    save_pdf=None
):
    carbon_intensity = float(carbon_intensity) / 3600 / 1000000

    # Build a DataFrame for seaborn
    records = []
    for workload, acc in workload_accuracies.items():
        footprints = []
        for variant in ['Serv', 'Qerv', 'Herv']:
            footprint = compute_total_carbon(variant, workload, lifetime_years, tasks_per_year, carbon_intensity, 10000)[2]
            footprints.append((variant, footprint))
        # Find the variant with the smallest footprint
        min_footprint = min(footprints, key=lambda x: x[1])[1]
        footprints.sort(key=lambda x: x[1], reverse=True)
        for variant, footprint in footprints:
            is_pareto = (footprint == min_footprint) and (workload not in ["MLP", "KNN-Small"])
            marker = '*' if is_pareto else 'x'
            size = STAR_SIZE if is_pareto else X_SIZE
            label = workload if (footprint == min_footprint) else ""
            records.append({
                "Accuracy": acc,
                "Carbon": footprint,
                "Variant": variant,
                "Workload": workload,
                "Pareto": is_pareto,
                "Marker": marker,
                "Size": size,
                "Label": label,
                "Color": system_colors[variant]
            })

    df = pd.DataFrame(records)
    show_plot = False

    ax.set_yscale('log')

    # Only plot custom markers (no dot underneath)
    for marker, group in df.groupby("Marker"):
        for _, row in group.iterrows():
            ax.scatter(
                row["Accuracy"], row["Carbon"],
                c=row["Color"],
                s=row["Size"],
                marker=row["Marker"],
                alpha=0.9,
                edgecolor="k" if row["Marker"] == '*' else None,
                zorder=2 if row["Marker"] == '*' else 1,
                linewidths = 2 if row["Marker"] == '*' else 3
            )

    for _, row in df.iterrows():
        if row["Label"]:
            # Place DT-Small label top right, others top left
            if row["Label"] in ["DT-Small", "DT-Medium"]:
                xytext = (8, 0)
                ha = 'left'
                va = 'top'
            else:
                xytext = (-8, 0)
                ha = 'right'
                va = 'top'
            ax.annotate(
                row["Label"],
                (row["Accuracy"], row["Carbon"]),
                textcoords="offset points",
                xytext=xytext,
                ha=ha,
                va=va,
                fontsize=text_size-2  # Use half the text_size for annotation
            )

    # Custom legend for the variants and marker types
    legend_elements = [
        Line2D([0], [0], marker='*', color='w', label='Pareto-Optimal', markerfacecolor='gray', markeredgecolor='k', markersize=16, linestyle='None'),
        Line2D([0], [0], marker='x', color='w', label='Not Pareto-Optimal', markerfacecolor='gray', markeredgecolor='k', markersize=12, linestyle='None'),
        Line2D([0], [0], marker='o', color='w', label='Serv', markerfacecolor='tab:blue', markersize=10, linestyle='None'),
        Line2D([0], [0], marker='o', color='w', label='Qerv', markerfacecolor='tab:orange', markersize=10, linestyle='None'),
        Line2D([0], [0], marker='o', color='w', label='Herv', markerfacecolor='tab:green', markersize=10, linestyle='None')
    ]
    ax.legend(handles=legend_elements, fontsize=text_size, title_fontsize=text_size)

    ax.set_xlabel("Accuracy", fontsize=text_size)
    ax.set_ylabel(f"Total Carbon Footprint (gCO2e)", fontsize=text_size)
    # ax.set_title("Accuracy vs. Carbon Footprint", fontsize=text_size)
    ax.tick_params(axis='x', labelsize=text_size)
    ax.tick_params(axis='y', labelsize=text_size)
    ax.grid(True)
    plt.tight_layout()
    if save_pdf is not None:
        plt.savefig(save_pdf, bbox_inches='tight')
    
    return df

if __name__ == "__main__":
    TEXT_SIZE = 23
    STAR_SIZE = 600
    X_SIZE = 300
    plt.rcParams.update({
        "axes.titlesize": TEXT_SIZE,
        "axes.labelsize": TEXT_SIZE,
        "xtick.labelsize": TEXT_SIZE-2,
        "ytick.labelsize": TEXT_SIZE-2,
        "legend.fontsize": TEXT_SIZE,
        "figure.titlesize": TEXT_SIZE
    }) 
    load_execution_time_from_csv("timing-ablation.csv")
    load_embodied_values_from_csv("embodied-carbon-ablation.csv")
    load_memory_from_csv("memory-ablation.csv")

    fig, ax = plt.subplots(figsize=(10, 6))
    plot_accuracy_vs_carbon(1, 365, 367, ax=ax, save_pdf="plots/kernel_ablation.pdf",text_size=TEXT_SIZE)
