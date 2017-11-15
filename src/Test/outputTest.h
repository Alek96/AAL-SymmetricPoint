#ifndef OUTPUTTEST_H
#define OUTPUTREST_H

#include <vector>
#include <iostream>

class OutputTest
{
public:
    OutputTest();
    friend std::ostream& operator<<(std::ostream&, const OutputTest&);

    void addResult(double time, bool correct=false);
    void addResult(bool coreect, double time=0);
    void setTimeEnable(bool);
    void setCorrectionEnable(bool);
    double getMaxTime() const;
    int getSize() const;
    double getArithmeticAverageTime() const;

private:
    std::vector<bool> correct;
    std::vector<double> time;
    int _countCorrectTest;
    bool _time;
    bool _correction;
};

#endif
