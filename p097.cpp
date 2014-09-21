#include <iostream>

typedef unsigned long long int Int;

int main() {

    Int N = 7830457;

    Int sum = 1;

    for (Int i = 0; i < N; ++i) {
        sum *= 2;
        sum %= 10000000000llu;
        // std::cout << sum << std::endl;
    }

    sum = 28433 * sum + 1;

    std::cout << "sum: " << (sum % 10000000000llu) << std::endl;
}

