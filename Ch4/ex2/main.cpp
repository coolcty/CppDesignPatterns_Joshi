/*
g++ main.cpp SimpleMC6.cpp Vanilla3.cpp Parameters.cpp PayOff3.cpp PayOffBridge.cpp Random1.cpp -I ./includes
*/

/*
Version using smart pointer
*/
#include"includes/SimpleMC6.h"
#include<iostream>
using namespace std;
#include"includes/Vanilla3.h"


int main()
{
    double Expiry;
    double Strike;
    double Spot;
    double Vol;
    double r;
    unsigned long NumberOfPaths;
    cout << "\nEnter expiry\n";
    cin >> Expiry;
    cout << "\nStrike\n";
    cin >> Strike;
    cout << "\nEnter spot\n";
    cin >> Spot;
    cout << "\nEnter vol\n";
    cin >> Vol;
    cout << "\nr\n";
    cin >> r;
    cout << "\nNumber of paths\n";
    cin >> NumberOfPaths;
    PayOffCall thePayOff(Strike);
    VanillaOption theOption(thePayOff, Expiry);
    ParametersConstant VolParam(Vol);
    ParametersConstant rParam(r);
    for(int i=0;i<10;i++){
    
    double result = SimpleMonteCarlo4(theOption,
        Spot,
        VolParam,
        rParam,
        NumberOfPaths);

    cout << "\nthe call price is " << result << "\n";
    VanillaOption secondOption(theOption);
    result = SimpleMonteCarlo4(secondOption,
        Spot,
        VolParam,
        rParam,
        NumberOfPaths);
    cout << "\nthe call price is " << result << "\n";
    PayOffPut otherPayOff(Strike);
    VanillaOption thirdOption(otherPayOff, Expiry);
    theOption = thirdOption;
    result = SimpleMonteCarlo4(theOption,
        Spot,
        VolParam,
        rParam,
        NumberOfPaths);
    cout << "\nthe put price is " << result << "\n";

    }
    double tmp;
    cin >> tmp;
    return 0;
}
