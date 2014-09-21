#include <iostream>
#include <math.h>

bool is_prime(long long int x) {
    if ((x % 2) == 0)
        return false;

    long long unsigned int ub = sqrt(double(x)) + 1;
    for (int i = 3; i < ub; i+=2) {
        if ((x%i) == 0) {
            return false;
        }
    }

    return true;
}

int main() {
    const int N = 10001;
    const long long unsigned max_int = 0xffffffffffffffffll;

    for (long long unsigned i = 2, j=0; i < max_int; ++i) {
        if (i == max_int) {
            std::cout << "MAX out\n";
            return 1;
        }

        if (is_prime(i)) {
            ++j;
            std::cout << "found " << i << "," << j << std::endl;
            if (j == N) {
                std::cout << "P=" << i << std::endl;
                return 0;
            }
        }
    }

    return 1;
}

