#include "LRModel.h"
#include "Tables/Table.h"
#include <cmath>
#include <string>
#include <iostream>

double LRModel::estimate(double x) {
    return b0 + (b1 * x);
}

void LRModel::fit(tables::Table& table, float trainingRatio, std::string xCol, std::string yCol) {
    double xMean;
    double yMean;
    int testStartIndex = (int)(table.height() * trainingRatio);

    xMean = table.col<double>(xCol).getMean(0, testStartIndex);
    yMean = table.col<double>(yCol).getMean(0, testStartIndex);

    // Calculate numerator and denominator for b1
    double b1Numerator = 0;
    double b1Denominator = 0;
    for (int i = 0; i < (int)(table.height() * trainingRatio); i++) {
        b1Numerator += (table.at<double>(xCol, i) - xMean) * (table.at<double>(yCol, i) - yMean);
        b1Denominator += pow(table.at<double>(xCol, i) - xMean, 2);
    }
    b1 = b1Numerator / b1Denominator;
    b0 = yMean - (b1 * xMean);
}

double LRModel::getB1() {
    return b1;
}

void LRModel::setB1(double b1) {
    this->b1 = b1;
}

double LRModel::getB0() {
    return b0;
}

void LRModel::setB0(double b0) {
    this->b0 = b0;
}
