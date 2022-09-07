#pragma once
#include<memory>

class PayOff
{
public:
    PayOff(){};

    virtual double operator()(double Spot)const=0;
    virtual ~PayOff(){}
    virtual std::unique_ptr<PayOff> clone()const=0;
    private:
};

class PayOffCall : public PayOff{
public:
    PayOffCall(double Strike_);

    virtual double operator()(double Spot)const;
    virtual ~PayOffCall(){}
    virtual std::unique_ptr<PayOff> clone() const;
private:
    double Strike;
};

class PayOffPut :public PayOff{
public:
    PayOffPut(double Strike_);

    virtual double operator()(double Spot)const;
    virtual ~PayOffPut(){};
    virtual std::unique_ptr<PayOff> clone()const;

private:
    double Strike;
};
