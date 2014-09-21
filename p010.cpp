#include <iostream>
#include <vector>
#include <iterator>
#include <numeric>
#include <math.h>

typedef unsigned long long Int;

int main() {

    //const Int N = 10;
    const Int N = 2000000;

    std::vector<Int> p(N, 1);
    p[0] = 0;
    p[1] = 0;

    Int ub = sqrt(double(N)) + 1;
    for (Int i = 2; i < ub; ++i) {
        if (p[i] == 1) {
            for (Int j = i * i; j < N; j += i) {
                p[j] = 0;
            }
        }
    }

    // std::fill(p.begin() + ub, p.begin() + N, 0);

    // std::copy(p.begin(), p.end(), std::ostream_iterator<Int>(std::cout, " "));

    Int sum = 0;
    for (Int i = 0; i < N; ++i) {
        if (p[i] != 0)
            sum += i;
    }
    std::cout << "sum: " << sum;

    return 0;
}
