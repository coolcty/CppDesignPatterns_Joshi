#pragma once

#include<PayOff3.h>

class PayOffBridge
{
public:
    PayOffBridge(const PayOffBridge& original);
    PayOffBridge(const PayOff& innnerPayOff);

    inline double operator()(double Spot)const;
    ~PayOffBridge();
    PayOffBridge& operator=(const PayOffBridge& original);

private:
    PayOff* ThePayOffPtr;
};

inline double PayOffBridge::operator()(double Spot)const{
    return (*ThePayOffPtr)(Spot);
}