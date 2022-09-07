#include"includes/PayOff3.h"
#include<algorithm>
#include<memory>


PayOffCall::PayOffCall(double Strike_):Strike(Strike_){}

double PayOffCall:: operator()(double Spot)const{
    return std::max(Spot-Strike,0.0);
}

std::unique_ptr<PayOff> PayOffCall::clone()const{
    return std::make_unique<PayOffCall>(*this);
}

PayOffPut::PayOffPut(double Strike_):Strike(Strike_){}

double PayOffPut:: operator()(double Spot)const{
    return std::max(Spot-Strike,0.0);
}

std::unique_ptr<PayOff> PayOffPut::clone()const{
    return std::make_unique<PayOffPut>(*this);
}

