#ifndef LRMODEL_H
#define LRMODEL_H

#include <string>
#include "Tables/Table.h"

class LRModel {
public:
    double estimate(double x);
    void fit(tables::Table& table, float trainingRatio, std::string xCol, std::string yCol);
    double getB1();
    void setB1(double b1);
    double getB0();
    void setB0(double b0);

private:
    double b1;
    double b0;
};

#endif
