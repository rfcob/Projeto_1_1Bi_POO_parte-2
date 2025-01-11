#include "knn.hpp"
#include "read_csv.h"
#include <cmath>
#include <algorithm>
#include <random>

KNN::KNN() : k(5) {}
KNN::KNN(int k) : k(k) {}
KNN::~KNN() {}

void KNN::fit(const vector<vector<float>> &data, const vector<int> &labels) {
    training_data = data;
    training_labels = labels;
}

void KNN::fit_from_files(const string &data_file, const string &label_file) {
    read_csv data_reader(data_file, "float");
    read_csv label_reader(label_file, "int");

    data_reader.toList(1);
    label_reader.toList(1);

    int rows = data_reader.get_nbrLines();
    int cols = data_reader.get_nbrCols();

    float **data_matrix = data_reader.get_floatMatrix();
    int **label_matrix = label_reader.get_intMatrix();

    training_data.resize(rows, vector<float>(cols));
    training_labels.resize(rows);

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            training_data[i][j] = data_matrix[i][j];
        }
        training_labels[i] = label_matrix[i][0];
    }
}

void KNN::split_data(float test_ratio) {
    int total_size = training_data.size();
    int test_size = static_cast<int>(total_size * test_ratio);

    vector<int> indices(total_size);
    for (int i = 0; i < total_size; ++i) {
        indices[i] = i;
    }

    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(indices.begin(), indices.end(), g);

    test_data.clear();
    test_labels.clear();

    for (int i = 0; i < test_size; ++i) {
        test_data.push_back(training_data[indices[i]]);
        test_labels.push_back(training_labels[indices[i]]);
    }

    vector<vector<float>> new_training_data;
    vector<int> new_training_labels;

    for (int i = test_size; i < total_size; ++i) {
        new_training_data.push_back(training_data[indices[i]]);
        new_training_labels.push_back(training_labels[indices[i]]);
    }

    training_data = std::move(new_training_data);
    training_labels = std::move(new_training_labels);
}

vector<int> KNN::predict(const vector<vector<float>> &data) {
    vector<int> predictions;

    for (const auto &example : data) {
        vector<std::pair<float, int>> distances;

        for (size_t i = 0; i < training_data.size(); ++i) {
            float dist = calculate_distance(example, training_data[i]);
            distances.push_back({dist, training_labels[i]});
        }

        std::sort(distances.begin(), distances.end());

        vector<int> votes(k);
        for (int i = 0; i < k; ++i) {
            votes[i] = distances[i].second;
        }

        std::sort(votes.begin(), votes.end());
        int majority_label = votes[0];
        int max_count = 1, current_count = 1;

        for (size_t i = 1; i < votes.size(); ++i) {
            if (votes[i] == votes[i - 1]) {
                current_count++;
                if (current_count > max_count) {
                    max_count = current_count;
                    majority_label = votes[i];
                }
            } else {
                current_count = 1;
            }
        }

        predictions.push_back(majority_label);
    }

    return predictions;
}

vector<int> KNN::predict_test() {
    return predict(test_data);
}

const vector<int>& KNN::get_test_labels() const {
    return test_labels;
}

float KNN::calculate_accuracy(const vector<int> &predictions, const vector<int> &true_labels) {
    if (predictions.size() != true_labels.size()) {
        throw std::invalid_argument("Predictions and true labels must have the same size");
    }

    int correct_count = 0;
    for (size_t i = 0; i < predictions.size(); ++i) {
        if (predictions[i] == true_labels[i]) {
            correct_count++;
        }
    }

    return static_cast<float>(correct_count) / predictions.size();
}

float KNN::calculate_distance(const vector<float> &a, const vector<float> &b) {
    float sum = 0.0;
    for (size_t i = 0; i < a.size(); ++i) {
        sum += (a[i] - b[i]) * (a[i] - b[i]);
    }
    return std::sqrt(sum);
}