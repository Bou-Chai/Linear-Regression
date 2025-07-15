#include <iostream>
#include <string>
#include <vector>
#include "Tables/Table.h"
#include "LRModel.h"

int main() {
    tables::Table table;
    LRModel model;

    table.loadCSV("../../data/house-price.csv");
    table.toDouble("bathrooms");
    table.toDouble("price");

    // Remove all rows that have price as 0
    for (int i = 0; i < table.height(); i++) {
        if (table.at<double>("price", i) == 0) {
            table.removeRow(i);
        }
    }

    // Fit model to data
    model.fit(table, "bathrooms", "price");
    std::cout << "B1: " << model.getB1() << "\n";
    std::cout << "B0: " << model.getB0() << "\n";
    std::cout << "Estimate: " << model.estimate(3) << "\n";

    return 0;
}
