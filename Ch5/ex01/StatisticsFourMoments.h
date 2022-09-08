#pragma once
#include"MCStatistics.h"

class StatisticsFourMoments : public StatisticsMC{
    public:
    StatisticsFourMoments();
    virtual void DumpOneResult(double result);
    virtual std::vector<std::vector<double>> GetResultsSoFar()const;
    virtual StatisticsMC* clone()const;

private:
    double RunningSum, RunningP2Sum, RunningP3Sum, RunningP4Sum;
    unsigned long PathsDone;
};