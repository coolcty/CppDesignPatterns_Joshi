#include <Random1.h>
#include <iostream>
#include <cmath>

using namespace std;

double SimpleMonteCarlo1(double Expiry,
						 double Strike1,
						 double Strike2,
						 double Spot,
						 double Vol,
						 double r,
						 unsigned long NumberOfPaths)
{
	double variance = Vol * Vol * Expiry;
	double rootVariance = sqrt(variance);
	double itoCorrection = -0.5 * variance;
	double movedSpot = Spot * exp(r * Expiry + itoCorrection);
	double thisSpot;
	double runningSum = 0;

	for (unsigned long i = 0; i < NumberOfPaths; i++)
	{
		double thisGaussian = GetOneGaussianByBoxMuller();
		thisSpot = movedSpot * exp(rootVariance * thisGaussian);
		double thisPayoff = Strike1<=thisSpot && thisSpot<=Strike2 ?1:0;
		runningSum += thisPayoff;
	}
	double mean = runningSum / NumberOfPaths;
	mean *= exp(-r * Expiry);
	return mean;
}

int main()
{
	double Expiry;
	double Strike1;
	double Strike2;
	double Spot;
	double Vol;
	double r;
	unsigned long NumberOfPaths;
	cout << "\nEnter expiry\n";
	cin >> Expiry;

	cout << "\nEnter strike1\n";
	cin >> Strike1;
	cout << "\nEnter strike2\n";
	cin >> Strike2;

	cout << "\nEnter spot\n";
	cin >> Spot;
	cout << "\nEnter vol\n";
	cin >> Vol;
	cout << "\nr\n";
	cin >> r;
	cout << "\nNumber of paths\n";
	cin >> NumberOfPaths;
	double result = SimpleMonteCarlo1(Expiry,
									  Strike1,
									  Strike2,
									  Spot,
									  Vol,
									  r,
									  NumberOfPaths);
	cout << "the price is " << result << "\n";
	double tmp;
	cin >> tmp;
	return 0;
}
