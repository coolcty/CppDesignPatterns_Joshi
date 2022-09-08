#include"StatisticsValueAtRisk.h"
#include<cmath>


StatisticsValueAtRisk::StatisticsValueAtRisk(double Level_) :Level(Level_), PathsDone(0) {
}

void StatisticsValueAtRisk::DumpOneResult(double result) {
    Sample.insert(result);
    PathsDone++;
}

std::vector<std::vector<double>> StatisticsValueAtRisk::GetResultsSoFar()const {
    auto s = Sample.begin();
    int position = PathsDone * Level;
    for (size_t i = 0; i < position; i++)s++;
    return std::vector<std::vector<double>>(1, std::vector<double>({ -(*s) }));
}

StatisticsMC* StatisticsValueAtRisk::clone()const {
    return new StatisticsValueAtRisk(*this);
}

