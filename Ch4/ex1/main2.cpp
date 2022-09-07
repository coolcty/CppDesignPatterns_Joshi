
#include<ctime>
#include<iostream>
#include <iomanip>
#pragma GCC push_options
#pragma GCC optimize ("O0")
int a[]={65536,131072,262144,524288,1048576};

int main(int argc, char const* argv[])
{
    
        std::clock_t c_start;
        std::clock_t c_end;
        c_start = std::clock();
        int i=a[3];
        for (size_t j = 0; j < 10000; j++)
        {
            double* arrayd = new double[i];
            //arrayd[i-1]=0;
            delete[] arrayd;
        }


        c_end = std::clock();

        std::cout << std::fixed << std::setprecision(2) << "dynamic method CPU time used for size " << i << " : "
            << 1000.0 * (c_end - c_start) / CLOCKS_PER_SEC << " ms"<<std::endl;


        c_start = std::clock();
        for (size_t j = 0; j < 10000; j++)
        {
            double arrays[i];
            //arrays[i-1]=0;
        }
        c_end = std::clock();

        std::cout << std::fixed << std::setprecision(2) << "static method CPU time used for size " << i << " : "
            << 1000.0 * (c_end - c_start) / CLOCKS_PER_SEC << " ms"<<std::endl;
    
}
#pragma GCC pop_options