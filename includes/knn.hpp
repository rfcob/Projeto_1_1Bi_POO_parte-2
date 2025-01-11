#ifndef KNN_HPP
#define KNN_HPP

#include <vector>
#include <string>
#include "read_csv.h"

using std::vector;
using std::string;

class KNN {
private:
    int k;
    vector<vector<float>> training_data;
    vector<int> training_labels;
    vector<vector<float>> test_data;
    vector<int> test_labels;

public:
    KNN();
    KNN(int k);
    ~KNN();

    void fit(const vector<vector<float>> &data, const vector<int> &labels);
    void fit_from_files(const string &data_file, const string &label_file);
    void split_data(float test_ratio);
    vector<int> predict(const vector<vector<float>> &data);
    vector<int> predict_test();
    const vector<int>& get_test_labels() const;
    float calculate_accuracy(const vector<int> &predictions, const vector<int> &true_labels);

private:
    float calculate_distance(const vector<float> &a, const vector<float> &b);
};

#endif
