#ifndef LRMODEL_H
#define LRMODEL_H

#include <string>

class LRModel {
public:
    int estimate(int x);
    void train();
    int getB1();
    int getB0();
    std::string getDataPath();
    void setDataPath(std::string dataPath);

private:
    int b1;
    int b0;
    std::string dataPath;
};

#endif
