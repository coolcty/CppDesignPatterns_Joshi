#include<ConvergenceTable.h>
using namespace std;

ConvergenceTable::ConvergenceTable(const Wrapper<StatisticsMC>& Inner_) :Inner(Inner_) {
    StoppingPoint = 2;
    PathsDone = 0;
}
StatisticsMC* ConvergenceTable::clone()const {
    return new ConvergenceTable(*this);
}
void ConvergenceTable::DumpOneResult(double result) {
    Inner->DumpOneResult(result);
    PathsDone++;

    if (PathsDone == StoppingPoint) {
        StoppingPoint *= 2;
        vector<vector<double>> thisResult(Inner->GetResultsSoFar());
        //???????????????????????????????????????????????????????????????????
        for (unsigned long i = 0; i < thisResult.size(); i++)
        {
            thisResult[i].push_back(PathsDone);
            ResultsSoFar.push_back(thisResult[i]);
        }

    }
    return;
}
vector<vector<double>> ConvergenceTable::GetResultsSoFar()const {
    vector<vector<double>> tmp(ResultsSoFar);

    if (PathsDone * 2 != StoppingPoint) {
        vector<vector<double>> thisResult(Inner->GetResultsSoFar());
        for (unsigned long i = 0; i < thisResult.size(); i++)
        {
            thisResult[i].push_back(PathsDone);
            tmp.push_back(thisResult[i]);
        }

    }
    return tmp;
}
