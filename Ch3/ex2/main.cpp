/*
requires DoubleDigital.cpp
PayOff2.cpp
Random1.cpp
SimpleMC2.cpp
*/


/*
compile method:
g++ main.cpp InputOption.cpp ../SimpleMC2.cpp ../ex1/Power.cpp ../PayOff2.cpp ../DoubleDigital.cpp ../../Ch1/Random1.cpp -I ../includes -I ../../Ch1/includes -I ../ex1/
*/
#include<SimpleMC2.h>
#include<Power.h>
#include<iostream>
using namespace std;

PayOff* ChoosePayOff();
int main()
{
    double Expiry;

    double Spot;

    double Vol;
    double r;
    unsigned long NumberOfPaths;
    PayOff* theChosedPayOff = ChoosePayOff();
    cout << "\nEnter expiry\n";
    cin >> Expiry;
    cout << "\nEnter spot\n";
    cin >> Spot;
    cout << "\nEnter vol\n";
    cin >> Vol;
    cout << "\nr\n";
    cin >> r;
    cout << "\nNumber of paths\n";
    cin >> NumberOfPaths;

    double result = SimpleMonteCarlo2(*theChosedPayOff,
        Expiry,
        Spot,
        Vol,
        r,
        NumberOfPaths);
    cout << "\nthe price is " << result << "\n";
    double tmp;
    cin >> tmp;
    delete theChosedPayOff;
    return 0;
}