#include "LRModel.h"
#include "Tables/Table.h"
#include <cmath>
#include <string>
#include <iostream>

double LRModel::estimate(double x) {
    return b0 + (b1 * x);
}

void LRModel::fit(tables::Table& table, std::string xCol, std::string yCol) {
    double xSum;
    double ySum;

    xSum = table.sum<double>(xCol);
    ySum = table.sum<double>(yCol);

    std::cout << "HERE" << "\n";

    // Calculate numerator and denominator for b1
    double b1Numerator = 0;
    double b1Denominator = 0;
    for (int i = 0; i < table.height(); i++) {
        b1Numerator += (table.at<double>(xCol, i) - xSum) * (table.at<double>(yCol, i) - ySum);
        b1Denominator += pow(table.at<double>(xCol, i) - xSum, 2);
    }
    b1 = b1Numerator / b1Denominator;
    b0 = ySum - (b1 * xSum);
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
