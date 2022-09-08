#pragma once
#include"MCStatistics.h"
#include<vector>
#include<memory>

class StatisticsMultiGatherer : public StatisticsMC {
public:
    StatisticsMultiGatherer(std::vector<std::unique_ptr<StatisticsMC>>& Gatherers_);
    virtual void DumpOneResult(double result);
    virtual std::vector<std::vector<double>> GetResultsSoFar()const;
    virtual StatisticsMC* clone()const;

private:
    std::vector<std::unique_ptr<StatisticsMC>> Gatherers; 
    unsigned long PathsDone;
};