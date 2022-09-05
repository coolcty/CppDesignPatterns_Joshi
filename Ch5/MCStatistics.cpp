#include<MCStatistics.h>

StatisticsMean::StatisticsMean() :RunningSum(0), PathsDone(0) {

}
void StatisticsMean::DumpOneResult(double result) {
    RunningSum += result;
    PathsDone++;
}
std::vector<std::vector<double>> StatisticsMean::GetResultsSoFar()const {
    std::vector<std::vector<double>> Results(1);
    Results[0].resize(1);
    Results[0][0] = RunningSum / PathsDone; return Results;
}
StatisticsMC* StatisticsMean::clone()const{
    return new StatisticsMean(*this);
}