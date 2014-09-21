#include <iostream>
#include <algorithm>

typedef unsigned long long Int;

inline static double mabs(double n) {
    return n >= 0 ? n : -n;
}

Int msqrt(Int n) {
    double xc = n/2;
    double xp = -1;

    do {
        // std::cout << xc << std::endl;
        xp = xc;
        xc = (xc + double(n)/xc)/2.;
    } while (mabs(xc - xp) >= 1);

    return Int(xc);
}

int main_slow() {


    Int sp = 0;
    Int sc = 0;

    for (Int i = 10; i < 10000; i += 1) {
    //for (Int i = 1000000000000; i < 2000000000000; ++i) {
        //std::cout << i << std::endl;
        sp = sp == 0 ? (i-1)*(i-1) : sc;
        sc = i*i;

        Int D = sp + sc;

        Int s = msqrt(D);
        if (s * s == D) {
            int rr = 1 + s;
            if ((rr & 1) == 0) {
                std::cout << "total=" << i << std::endl;
                std::cout << "blue=" << (rr >> 1) << std::endl;
                // exit(1);
            }
        }
    }

    return 0;
}


int main() {

    Int b = 15;
    Int N = 21;

    Int target = 1000000000000;

    while (N < target) {
        Int bt = 3 * b + 2 * N - 2;
        Int Nt = 4 * b + 3 * N - 3;

        b = bt;
        N = Nt;
    }

    std::cout << b << std::endl;

    return 0;
}

