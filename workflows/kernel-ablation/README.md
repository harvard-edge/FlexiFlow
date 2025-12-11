# Kernel Ablation Case Study: Food Spoilage Detection

This directory contains a case study on the Food Spoilage Detection benchmark, exploring different software kernel implementations and their impact on accuracy and performance.

The following table summarizes the provided implementations and their resulting accuracies:

| Kernel Implementation | Accuracy |
| --------------------- | -------- |
| [Decision Tree (Small)](src/decision_tree_small.c) | 74.6% |
| [Decision Tree (Medium)](src/decision_tree_medium.c) | 83.8% |
| [Decision Tree (Large)](src/decision_tree_large.c) | 95.1% |
| [K-Nearest Neighbors (Small)](src/knn_small.c) | 96.4% |
| [K-Nearest Neighbors (Medium)](src/knn_medium.c) | 98.6% |
| [K-Nearest Neighbors (Large)](src/knn_large.c) | 98.9% |
| [Logistic Regression](src/logistic_regression.c) | 98.2% |
| [MLP](src/mlp.c) | 91.4% |
