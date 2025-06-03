#include <iostream>
#include <string>
#include <vector>
#include "CSVParse/CSVParser.h"
#include "DataTables/DataTable.h"

int main() {
    DataTable dataTable;
    CSVParser parser;
    
    dataTable.setTableMatrix(parser.parse("./advertising.csv"));
/*
    if (dataTable.empty()) {
        std::cout << "No data" << "\n";
        return 0;
    }
*/
    dataTable.at(7, 3) = 7777;

    for (int i = 0; i < dataTable.getHeight(); i++) {
        std::cout << "|";
        for (int j = 0; j < dataTable.at(i).size(); j++) {
            std::cout << dataTable.at(i, j) << "|";
        }
        std::cout << std::endl;
    }

    std::cout << "Sum: " << dataTable.sumCol(0) << "\n";
    return 0;
}
