#include"PayOff1.h"
#include<algorithm>

PayOff::PayOff(double Strike_, OptionType TheOptionsType_) :Strike(Strike_), TheOptionsType(TheOptionsType_) {
}
PayOff::PayOff(double Strike1_,double Strike2_, OptionType TheOptionsType_) :Strike1(Strike1_), Strike2(Strike2_),TheOptionsType(TheOptionsType_) {
}

double PayOff::operator()(double spot)const{
    switch (TheOptionsType)
    {
    case call:
        return std::max(spot-Strike,0.0);
    case put:
        return std::max(Strike-spot,0.0);
    case digital:
        return spot-Strike>=0?1:0;
    case doubledigital:
        return spot-Strike1>=0 && Strike2-spot>=0 ?1:0;
    default:
        throw("unknown option type found");
    }
}