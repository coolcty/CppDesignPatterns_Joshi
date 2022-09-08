#include"SimpleMC7withTerminator.h"
#include<Random1.h>
#include<cmath>

void SimpleMonteCarlo5(const VanillaOption& TheOption,
    double Spot,
    const Parameters& Vol,
    const Parameters& r,
   
    StatisticsMC& gatherer,TerminatorInner& Terminator) {
    double Expiry = TheOption.GetExpiry();
    double variance = Vol.IntegralSquare(0, Expiry);
    double rootVariance = std::sqrt(variance);
    double itoCorrection=-0.5*variance;
    double movedSpot=Spot*std::exp(r.Integral(0,Expiry));
    double thisSpot;
    double discounting=exp(-r.Integral(0,Expiry));

    while (Terminator.IfContinue())
    {
        double thisGaussian = GetOneGaussianByBoxMuller();
        thisSpot=movedSpot*exp(rootVariance*thisGaussian);
        double thisPayOff=TheOption.OptionPayOff(thisSpot);
        gatherer.DumpOneResult(thisPayOff*discounting);
    }
    return;    
}