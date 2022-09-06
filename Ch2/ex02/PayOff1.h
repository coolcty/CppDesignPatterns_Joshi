#pragma once

class PayOff
{
public:
    enum OptionType { call, put ,digital,doubledigital};
    PayOff(double Strike_, OptionType TheOptionsType_);
    PayOff(double Strike1_,double Strike2_, OptionType TheOptionsType_);
    double operator()(double Spot)const;
private:
    double Strike;
    double Strike1,Strike2;
    OptionType TheOptionsType;
};
