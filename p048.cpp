#include <iostream>

typedef unsigned long long Int;

int main() {

    const Int N = 1000;
    const Int M = 10000000000ull;

    Int sum = 0;
    for (Int i = 1; i <= N; ++i) {
        Int term = 1;
        for (Int j = 1; j <= i; ++j) {
            term *= i;
            term %= M;
        }

        sum += term;
        sum %= M;
    }

    std::cout << "sum: " << sum << std::endl;

    return 0;
}


