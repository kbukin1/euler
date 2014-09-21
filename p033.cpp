#include <iostream>

int main() {

    unsigned sn = 1;
    unsigned sd = 1;

    for (unsigned denum = 11; denum < 100; ++denum) {
        for (unsigned num = 11; num < denum; ++num) {
            unsigned na = num/10;
            unsigned nb = num%10;
            unsigned da = denum/10;
            unsigned db = denum%10;

            if (na == 0 || nb == 0 || da == 0 || db == 0)
                continue;

            unsigned nc = 0;
            unsigned dc = 0;
            if (na == da) {
                nc = nb;
                dc = db;
            }
            else if (na == db) {
                nc = nb;
                dc = da;
            } 
            else if (nb == db) {
                nc = na;
                dc = da;
            } 
            else if (nb == da) {
                nc = na;
                dc = db;
            } 

            if (nc != 0 && dc != 0) {
                if (double(num)/double(denum) == double(nc)/double(dc)) {
                    std::cout << num << "/" << denum << std::endl;

                    sn *= nc;
                    sd *= dc;
                }
            }
        }
    }

    std::cout << sn << "/" << sd << std::endl;

    return 0;
}

