#include <iostream>
#include <cmath>
#include <math.h>

int main(){

    const int N = 1000000;

    for (int j = 1; j < N; ++j) {
        for (int k = 1; k < j; ++k)  {
            int pj = j * (3 * j - 1) / 2;
            int pk = k * (3 * k - 1) / 2;
            double cd = (sqrt(1 + 24 * (double(pj) - double(pk))) + 1)/6;
            double cs = (sqrt(1 + 24 * (double(pj) + double(pk))) + 1)/6;

            double temp;
            if (std::modf(cd, &temp) == 0 && std::modf(cs, &temp) == 0) {
                std::cout << "Found j: " << j << std::endl;
                std::cout << "Found k: " << k << std::endl;
                std::cout << "Found pj: " << pj << std::endl;
                std::cout << "Found pk: " << pk << std::endl;
                std::cout << "Found cd: " << cd << std::endl;
                std::cout << "Found cs: " << cs << std::endl;
                return 0;
            }
        }
    }

    return 1;

}

