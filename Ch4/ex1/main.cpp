
#include<ctime>
#include<iostream>
#include <iomanip>


int main(int argc, char const* argv[])
{
    for (size_t i = 1; i < 10000000000000000; i *= 2)
    {
        std::clock_t c_start;
        std::clock_t c_end;
        c_start = std::clock();
        for (size_t j = 0; j < 10000; j++)
        {
            double* arrayd = new double[i]{};
            arrayd[i-1]=0;
            delete[] arrayd;
        }


        c_end = std::clock();

        std::cout << std::fixed << std::setprecision(2) << "dynamic method CPU time used for size " << i << " : "
            << 1000.0 * (c_end - c_start) / CLOCKS_PER_SEC << " ms"<<std::endl;


        c_start = std::clock();
        for (size_t j = 0; j < 10000; j++)
        {
            double arrays[i]={};
            arrays[i-1]=0;
        }
        c_end = std::clock();

        std::cout << std::fixed << std::setprecision(2) << "static method CPU time used for size " << i << " : "
            << 1000.0 * (c_end - c_start) / CLOCKS_PER_SEC << " ms"<<std::endl;
    }
}

