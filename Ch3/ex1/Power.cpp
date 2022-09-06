#include<Power.h>

PayOffPower::PayOffPower(double Strike_, unsigned long Power_):Strike(Strike_),Power(Power_){}

double PayOffPower::operator()(double Spot)const{
    double SpotPower=1;
    for (unsigned long i = 0; i < Power; i++)
    {
        SpotPower*=Spot;
    }
    
    return SpotPower>=Strike ? SpotPower-Strike:0;
}