#include"StatisticsFourMoments.h"
#include<cmath>


StatisticsFourMoments::StatisticsFourMoments() :RunningSum(0), RunningP2Sum(0), RunningP3Sum(0), RunningP4Sum(0),PathsDone(0) {
}

void StatisticsFourMoments::DumpOneResult(double result) {
    double increment = result;
    RunningSum += increment;
    increment *= result;
    RunningP2Sum += increment;
    increment *= result;
    RunningP3Sum += increment;
    increment *= result;
    RunningP4Sum += increment;
    PathsDone++;
}
/*
http://rovdownloads.com/attachments/newsletters/Newsletter%2003%20-%20Understanding%20the%20Forecast%20Statistics%20and%20Four%20Moments%20(4P).pdf
*/
std::vector<std::vector<double>> StatisticsFourMoments::GetResultsSoFar()const {
    double x = RunningSum / PathsDone;

    double StandardDeviation = std::sqrt((RunningP2Sum - x * RunningP4Sum) / (PathsDone - 1));
    double Skew = (RunningP3Sum - 3 * RunningP2Sum * x + 2 * RunningSum * x * x) * PathsDone / (PathsDone - 1) / (PathsDone - 2) / StandardDeviation / StandardDeviation / StandardDeviation;
    double ExcessKurtosis = ((RunningP4Sum - 4 * RunningP3Sum * x + 6 * RunningP2Sum * x * x - 3 * RunningSum * x * x * x) / StandardDeviation / StandardDeviation / StandardDeviation / StandardDeviation) * PathsDone * (PathsDone + 1) / (PathsDone - 1) / (PathsDone - 2) / (PathsDone - 3) - 3 * (PathsDone - 1) * (PathsDone - 1) / (PathsDone - 2) / (PathsDone - 3);

    return std::vector<std::vector<double>>(1,std::vector<double>({x,StandardDeviation,Skew,ExcessKurtosis}));
}

StatisticsMC* StatisticsFourMoments::clone()const {
    return new StatisticsFourMoments(*this);
}

