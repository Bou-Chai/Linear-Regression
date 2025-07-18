#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <iomanip>
#include "Tables/Table.h"
#include "LRModel.h"
#include "Tables/Evaluation.h"

int main() {
    tables::Table table;
    LRModel model;
    float trainingRatio = 0.6;
    float testingRatio = 1 - trainingRatio;
    std::string feature = "X";
    std::string target = "Y";

    table.loadCSV("../../tests/data/insurance.csv");
    table.toDouble(feature);
    table.toDouble(target);
/*
    // Remove all rows that have price as 0
    for (int i = 0; i < table.height(); i++) {
        if (table.at<double>(target, i) == 0) {
            table.removeRow(i);
        }
    }
*/
    // Fit model to data
    model.fit(table, trainingRatio, feature, target);
    std::cout << "B1: " << model.getB1() << "\n";
    std::cout << "B0: " << model.getB0() << "\n";

    // Get the first index of the test data
    int testStartIndex = (int)(table.height() * trainingRatio);
    // Get mean of training data
    int trainingMean = table.col<double>(target).getMean(0, testStartIndex);

    // Get target test (actual) data
    tables::Column<double> yTest = table.col<double>(target).getRange(testStartIndex, table.height());

    // Get target model prediction data
    tables::Column<double> yPredictedM;
    for (int i = testStartIndex; i < table.height(); i++) {
        yPredictedM.add(model.estimate(table.at<double>(feature, i)));
        yTest;
    }

    // Get target zero-rule prediction data
    tables::Column<double> yPredictedZR;
    for (int i = 0; i < yTest.size(); i++) {
        yPredictedZR.add(trainingMean);
    }

    // Calculate and display performance metrics
    std::cout << "MAE of 0-R: " << tables::eval::mae(yTest, yPredictedZR) << "\n";
    std::cout << "RMSE of 0-R: " << tables::eval::rmse(yTest, yPredictedZR) << "\n";
    std::cout << "MAE of model: " << tables::eval::mae(yTest, yPredictedM) << "\n";
    std::cout << "RMSE of model: " << tables::eval::rmse(yTest, yPredictedM) << "\n";

    return 0;
}
