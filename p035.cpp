#include <iostream>
#include <math.h>

static bool is_prime(unsigned n) {
    if (n == 1)
        return false;

    if (n & 1 == 0)
        return false;

    if (n == 2)
        return true;

    for (unsigned i = 2; i * i <= n; ++i) {
        if (n % i == 0)
            return false;
    }
    return true;
}

static inline unsigned rot(unsigned n, unsigned order) {
    unsigned temp =  pow(10, order );
    return n/10 + pow(10, order) * (n%10);
}

static bool is_circular(unsigned n) {
    unsigned order = 0;
    for (unsigned temp = n; temp > 10; temp /= 10) {
        ++order;
    }

    unsigned r = rot(n, order);
    for (unsigned i = 0; i < order; ++i, r = rot(r, order)) {
        if (!is_prime(r)) {
            return false;
        }
    }

    return true;
}

int main() {
    unsigned count = 0;

    for (unsigned i = 1; i < 1000000; ++i) {
    //for (unsigned i = 831799; i < 831899; ++i) {
        if (is_prime(i) && is_circular(i)) {
            ++count;
            std::cout << i << std::endl;
        }
    }

    std::cout << count << std::endl;

    return 0;
}

