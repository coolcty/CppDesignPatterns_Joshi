#include<PayOff2.h>
#include<DoubleDigital.h>
#include<Power.h>
#include<string>
#include<iostream>




PayOff* ChoosePayOff() {
    std::string s;
    std::cout << "\nEnter PayOff\n";
    std::cin >> s;

    if (s == "Put") {
        double Strike;
        std::cout << "\nEnter strike\n";
        std::cin >> Strike;
        return new PayOffPut(Strike);
    }
    else if (s == "Call") {
        double Strike;
        std::cout << "\nEnter strike\n";
        std::cin >> Strike;
        return new PayOffCall(Strike);
    }
    else if (s == "DoubleDigital") {
        double Low, Up;
        std::cout << "\nEnter low barrier\n";
        std::cin >> Low;
        std::cout << "\nEnter up barrier\n";
        std::cin >> Up;
        return new PayOffDoubleDigital(Low, Up);
    }
    else if (s == "Power") {
        double Strike;
        unsigned long Power;
        std::cout << "\nEnter strike\n";
        std::cin >> Strike;
        std::cout << "\nEnter power\n";
        std::cin >> Power;
        return new PayOffPower(Strike, Power);
    }else{
        std::cout<<"Unknown payoff\n";
        return nullptr;
    }

}