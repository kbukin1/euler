#include <iostream>
#include <cmath>
#include <math.h>

typedef unsigned long long Int;

int main() {

    // const Int N = 300;
    const Int N = 2000000000;

    for (Int i = 2; i < N; ++i) {
        double temp;
#if 1
        Int tn = i * (i +1)/2;

        double pn = (1. + sqrt(1 + 24 * tn))/6.;
        if (std::modf(pn, &temp) == 0) {
            double hn = (1. + sqrt(1 + 8 * tn))/4.;
            if (std::modf(hn, &temp) == 0) {
                std::cout << "Found: " <<  tn << std::endl;
                if (tn != 40755)
                    return 0;
            }
        }
#endif
#if 0
        Int tp = i * (3 * i - 1)/2;
        double D = sqrt(1 + 8 * tp);

        if (std::modf((D+1.)/4., &temp) == 0 && std::modf((D - 1.)/2., &temp) == 0) {
            std::cout << "Found: " <<  tp << std::endl;
            if (tp != 40755)
                return 0;
        }
#endif

    }

    return 0;
}
