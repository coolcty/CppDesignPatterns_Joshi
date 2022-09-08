#pragma once
#include"MCStatistics.h"
#include<set>

class StatisticsValueAtRisk : public StatisticsMC{
    public:
    StatisticsValueAtRisk(double Level_);
    virtual void DumpOneResult(double result);
    virtual std::vector<std::vector<double>> GetResultsSoFar()const;
    virtual StatisticsMC* clone()const;

private:
    std::set<double> Sample;
    double Level;
    unsigned long PathsDone;
};