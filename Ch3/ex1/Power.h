#pragma once

#include<PayOff2.h>

class PayOffPower : public PayOff {
public:
    PayOffPower(double Strike_,unsigned long Power_);

    virtual double operator()(double Spot)const;
    virtual ~PayOffPower() {}
private:
    double Strike;
    unsigned long Power;

};