#include<DoubleDigital2.h>

PayOffDoubleDigital::PayOffDoubleDigital(double LowerLevel_,double UpperLevel_):LowerLevel(LowerLevel_),UpperLevel(UpperLevel_){}

double PayOffDoubleDigital::operator()(double Spot)const{
    return Spot<=LowerLevel && Spot>=UpperLevel ? 0:1;
}

PayOff* PayOffDoubleDigital::clone()const{
    return new PayOffDoubleDigital(*this);
}