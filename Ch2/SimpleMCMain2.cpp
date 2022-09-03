/*
requires
PayOff1.cpp
Random1.cpp,
SimpleMC.cpp,
*/
#include<SimpleMC.h>
#include<iostream>
#include <chrono>
using namespace std;
int main()
{
    double Expiry;
    double Strike, Strike1, Strike2;
    double Spot;
    double Vol;
    double r;
    unsigned long NumberOfPaths;
    cout << "\nEnter expiry\n";
    cin >> Expiry;
    cout << "\nEnter strike\n";
    cin >> Strike;
    cout << "\nEnter Strike1\n";
    cin >> Strike1;
    cout << "\nEnter Strike2\n";
    cin >> Strike2;
    cout << "\nEnter spot\n";
    cin >> Spot;
    cout << "\nEnter vol\n";
    cin >> Vol;
    cout << "\nr\n";
    cin >> r;

    cout << "\nNumber of paths\n";
    cin >> NumberOfPaths;

    auto start = std::chrono::high_resolution_clock::now();

    PayOff callPayOff(Strike, PayOff::call);
    PayOff putPayOff(Strike, PayOff::put);
    PayOff digitalPayOff(Strike, PayOff::digital);
    PayOff doubleDigitalPayOff(Strike1, Strike2, PayOff::doubledigital);
    double resultCall = SimpleMonteCarlo2(callPayOff,
        Expiry,
        Spot,
        Vol,
        r,
        NumberOfPaths);
    double resultPut = SimpleMonteCarlo2(putPayOff,
        Expiry,
        Spot,
        Vol,
        r,
        NumberOfPaths);
    double resultDigital = SimpleMonteCarlo2(digitalPayOff,
        Expiry,
        Spot,
        Vol,
        r,
        NumberOfPaths);
    double resultDoubleDigital = SimpleMonteCarlo2(doubleDigitalPayOff,
        Expiry,
        Spot,
        Vol,
        r,
        NumberOfPaths);

    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    cout << "the prices are "
        << resultCall
        << " for the call and "
        << resultDigital
        << " for the digital and "
        << resultDoubleDigital
        << " for the double digital and "
        << resultPut
        << " for the put\n";
    cout << "Time taken by function: "
        << duration.count() << " microseconds" << endl;
    double tmp;
    cin >> tmp;
    return 0;
}