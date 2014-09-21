#include <iostream>
#include <numeric>
#include <math.h>

typedef unsigned long long Int;

Int div_num(Int n) {

    Int up = Int(1 + sqrt(double(n)));

    Int ret = 2;
    for (Int i = 2; i < up; ++i) {
        if ((n % i) == 0)
            ret += 2;
    }

    return ret;
}

int main(){

    // const Int N = 7;
    const Int N = 2000000;

    for (Int i = 1; i <= N; ++i) {
        // Int tn = i * (i + 1) / 2;
        // Int d = div_num(tn);
        Int d;
        if ((i & 1))
            d = div_num(i) * div_num((i+1)/2);
        else
            d = div_num(i/2) * div_num(i+1);

        if (d > 500) {
            Int tn = i * (i + 1) / 2;
            std::cout << tn << ": " << d << std::endl;
            return 0;
        }
    }

    return 1;
}
