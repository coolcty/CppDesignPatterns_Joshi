/*
g++ *.cpp
*/

/*
Version using smart pointer with piecewiseconstant parameter
*/
#include"includes/SimpleMC6.h"
#include<iostream>
using namespace std;
#include"includes/Vanilla3.h"
#include<vector>


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
    //cout << "\nEnter vol\n";
    //cin >> Vol;
    cout << "\nr\n";
    cin >> r;
    cout << "\nNumber of paths\n";
    cin >> NumberOfPaths;
    PayOffCall thePayOff(Strike);
    VanillaOption theOption(thePayOff, Expiry);
    auto Times = vector<double>({ 0,1,2,3,4,5,6,7,8,9,10 });
    auto Constants = vector<double>({ 0.1,0.2,0.3,0.4,0.5,0.6,0.7,0.8,0.9,0.1 });
    ParametersPiecewiseConstant VolParam(Times, Constants);
    ParametersConstant rParam(r);


    for (int i = 0;i < 10;i++) {

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
