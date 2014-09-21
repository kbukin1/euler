#include <iostream>

typedef unsigned long long uint64;

uint64 fact(uint64 n) {
    uint64 ret = 1;
    for (uint64 i = 2; i <= n; ++i) {
        ret *= i;
    }
    return ret;
}

int main() {

    uint64 start = 10; // 10
    uint64 end   = 10000000ull; // 10^7

    for (uint64 i = start; i < end; ++i) {
        uint64 is = 0;
        for (uint64 curr = i; curr > 0; curr/=10) {
            is += fact(curr % 10);
        }
        if (i == is) 
            std::cout << i << std::endl;
    }

    return 0;
}

