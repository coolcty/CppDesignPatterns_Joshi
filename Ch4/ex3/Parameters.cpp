#include"includes/Parameters.h"
#include<vector>
#include<algorithm>

Parameters::Parameters(const ParametersInner& innerObject) {
    InnerObjectPtr = innerObject.clone();
}

Parameters::Parameters(const Parameters& original) {
    InnerObjectPtr = original.InnerObjectPtr->clone();
}

Parameters& Parameters::operator=(const Parameters& original) {
    if (this != &original) {
        //delete InnerObjectPtr;
        InnerObjectPtr = original.InnerObjectPtr->clone();
    }
    return *this;
}
/*
Parameters:: ~Parameters() {
    delete InnerObjectPtr;
}
*/


double Parameters::Mean(double time1, double time2)const {
    double total = Integral(time1, time2);
    return total / (time2 - time1);
}
double Parameters::RootMeanSqure(double time1, double time2)const {
    double total = IntegralSquare(time1, time2);
    return total / (time2 - time1);
}

ParametersConstant::ParametersConstant(double constant) {
    Constant = constant;
    ConstantSquare = constant * constant;
}

std::unique_ptr<ParametersInner> ParametersConstant::clone()const {
    return std::make_unique<ParametersConstant>(*this);
}
double ParametersConstant::Integral(double time1, double time2)const {
    return (time2 - time1) * Constant;
}
double ParametersConstant::IntegralSquare(double time1, double time2)const {
    return (time2 - time1) * ConstantSquare;
}

ParametersPiecewiseConstant::ParametersPiecewiseConstant(std::vector<double>& times_, std::vector<double>& constants_) :Times(times_), Constants(constants_), ConstantsSquare(constants_) {
    std::for_each(ConstantsSquare.begin(), ConstantsSquare.end(), [](auto& n) { n *= n; });
}
std::unique_ptr<ParametersInner> ParametersPiecewiseConstant::clone()const {
    return std::make_unique<ParametersPiecewiseConstant>(*this);
}
double ParametersPiecewiseConstant::Integral(double time1, double time2)const {
    double result;
    if (time1 < Times[0])time1 = Times[0];
    if (time2 > Times.back())time2 = Times.back();
    for (size_t i = 1; Times[i] <= time2 && i + 1 < Times.size(); i++)
    {
        if (Times[i] > time1) {
            result += (Times[i] - time1) * Constants[i - 1];
            time1 = Times[i];
        }
        if (Times[i + 1] > time2) {
            result += (time2 - time1) * Constants[i];
            break;
        }
    }
    return result;
}

double ParametersPiecewiseConstant::IntegralSquare(double time1, double time2)const {
    double result;
    if (time1 < Times[0])time1 = Times[0];
    if (time2 > Times.back())time2 = Times.back();
    for (size_t i = 1; Times[i] <= time2 && i + 1 < Times.size(); i++)
    {
        if (Times[i] > time1) {
            result += (Times[i] - time1) * ConstantsSquare[i - 1];
            time1 = Times[i];
        }
        if (Times[i + 1] > time2) {
            result += (time2 - time1) * ConstantsSquare[i];
            break;
        }
    }
    return result;
}

