#include "Random1.h"
#include<cstdlib>
#include<cmath>

double GetOneGaussianBySummation()
{
    double result = 0;
    for (unsigned long j = 0; j < 12; j++)
        result += rand() / (double)RAND_MAX;
    result -= 6.0;
    return result;
}

double GetOneGaussianByBoxMuller()
{
    double result;

    double x, y;

    double sizeSquared;
    do {
        x = 2.0 * rand() / (double)RAND_MAX - 1;
        y = 2.0 * rand() / (double)RAND_MAX - 1;
        sizeSquared = x * x + y * y;
    } while (sizeSquared >= 1.0|| sizeSquared==0);
    result = x * sqrt(-2 * log(sizeSquared) / sizeSquared);

    return result;
}
