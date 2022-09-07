#pragma once
#include<memory>
#include"PayOff3.h"

class PayOffBridge
{
public:
    PayOffBridge(const PayOffBridge& original);
    PayOffBridge(const PayOff& innnerPayOff);

    inline double operator()(double Spot)const;
    //~PayOffBridge();
    PayOffBridge& operator=(const PayOffBridge& original);

private:
    std::unique_ptr<PayOff> ThePayOffPtr;
};

inline double PayOffBridge::operator()(double Spot)const{
    return (*ThePayOffPtr)(Spot);
}