#include<SimpleMC3.h>
#include<Random1.h>
#include<cmath>

double SimpleMonteCarlo3(const VanillaOption& TheOption,
    double Spot,
    double Vol,
    double r,
    unsigned long NumberOfPaths) {
    double Expiry = TheOption.GetExpiry();
    double variance = Vol * Vol * Expiry;
    double rootVariance = std::sqrt(variance);
    double itoCorrection = -0.5 * variance;

    double movedSpot = Spot * std::exp(r * Expiry + itoCorrection);
    double thisSpot;
    double runningSum = 0;

    for (unsigned long i = 0;i < NumberOfPaths;i++) {
        double thisGaussian = GetOneGaussianByBoxMuller();
        thisSpot = movedSpot * exp(rootVariance * thisGaussian);
        double thisPayOff = TheOption.OptionPayOff(thisSpot);
        runningSum += thisPayOff;

    }
    double mean = runningSum / NumberOfPaths;
    mean *= std::exp(-r * Expiry);
    return mean;

}