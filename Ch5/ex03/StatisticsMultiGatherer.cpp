#include"StatisticsMultiGatherer.h"
#include"MCStatistics.h"
#include<cmath>
#include<algorithm>


StatisticsMultiGatherer::StatisticsMultiGatherer(std::vector<std::unique_ptr<StatisticsMC>>& Gatherers_) : PathsDone(0) {
    for (auto&& Gatherer : Gatherers_) {
        Gatherers.push_back(std::make_unique<StatisticsMC>(Gatherer->clone()));
    }
}

void StatisticsMultiGatherer::DumpOneResult(double result) {
    for (auto&& Gatherer : Gatherers)Gatherer->DumpOneResult(result);
    PathsDone++;
}

std::vector<std::vector<double>> StatisticsMultiGatherer::GetResultsSoFar()const {
    std::vector<std::vector<double>> results;
    for(auto&& Gatherer:Gatherers){
        auto && s=Gatherer->GetResultsSoFar();
        results.insert(results.end(),s.begin(),s.end());
    }
    return results;
}

StatisticsMC* StatisticsMultiGatherer::clone()const {
    return new StatisticsMultiGatherer(*this);
}

