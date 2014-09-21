#include <iostream>

typedef unsigned long long Int;

int main() {
#if 0
    Int as = 6;
    Int al = 8;

    for (Int i = 1; i < 30; ++i) {
        Int ps = 1;
        Int pl = 1;

        for (Int j = 0; j < i; ++j) {
            ps *= as;
            pl *= al;
        }

        std::cout << i << ": " << ((ps + pl) % 49) << "  " << (ps + pl)<< std::endl;
    }
#endif

    int sum = 0;
    for (int i = 3; i <= 1000; ++i) {
        // sum += i*(i-1);
        sum += 2*i*((i-1) / 2);
    }

    std::cout << sum << std::endl;
}

