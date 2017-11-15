#include "outputTest.h"

#include <algorithm>

OutputTest::OutputTest()
    : _countCorrectTest(0), _time(false), _correction(false)
{}

std::ostream& operator<<(std::ostream& os, const OutputTest& output)
{
    if(output._correction || output._time) {
        for(int i=0; i<output.correct.size(); ++i) {
            os << i+1 << ":\t";
            if( output._correction ) {
                if(output.correct[i])
                    os << "OK   \t";
                else
                    os << "WRONG\t";
            }
            if( output._time ) {
                os << "time: " << output.time[i] << "\t";
            }
            os << "\n";
        }
    }

    if( output._correction )
        os << output._countCorrectTest << "/" << output.correct.size() << "\n";
    return os;
}

void OutputTest::addResult(double time, bool correct)
{
    (this->time).push_back(time);
    (this->correct).push_back(correct);
    if(correct)
        ++_countCorrectTest;
}

void OutputTest::addResult(bool correct, double time)
{
    (this->time).push_back(time);
    (this->correct).push_back(correct);
    if(correct)
        ++_countCorrectTest;
}

void OutputTest::setTimeEnable(bool time)
{
    _time = time;
}

void OutputTest::setCorrectionEnable(bool correction)
{
    _correction = correction;
}

double OutputTest::getMaxTime() const
{
    double maxTime = 0;
    std::for_each(time.begin(), time.end(), [&](double t) { maxTime = std::max(maxTime, t); } );
}

int OutputTest::getSize() const
{
    return correct.size();
}

double OutputTest::getArithmeticAverageTime() const
{
    double ar = 0;
    std::for_each(time.begin(), time.end(), [&](double t) { ar += t; } );
    return ar / time.size();
}
