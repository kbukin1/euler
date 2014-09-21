#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>

typedef unsigned long long Int;

int main_wrong() {

    const Int N = 12000 + 1;
    //const Int N = 8 + 1;
    std::vector<Int> phi(N);

    for (Int i = 1; i < phi.size(); ++i)
        phi[i] = i;


    for (Int i = 2; i < phi.size(); ++i) {
        if (i == phi[i]) {
            for (Int j = i; j < phi.size(); j += i) {
                phi[j] /= i;
                phi[j] *= (i - 1);
            }
        }
    }

    // std::copy(phi.begin(), phi.end(), std::ostream_iterator<Int>(std::cout, "\n"));
    Int sum = 0;
    for (Int i = 1; i < phi.size(); ++i) {
        double d = double(phi[i])/2. - double(phi[i])/3.;
        std::cout << "i=" << i << " phi=" << phi[i] << " " << Int(d + .5) << std::endl;
        sum += Int(d+.5);
    }

    std::cout << sum << std::endl;

    return 0;
}

int gcd(int a, int b) {
    if (a == 1 || b == 1)
        return 1;

    if (a == b)
        return a;

    if (a > b) {
        a %= b;
        if (a == 0)
            return b;
    } else {
        b %= a;
        if (b == 0)
            return a;
    }

    return a > b ? gcd(a - b, b) : gcd(a, b -a);
}

int main() {

    //const int N = 8;
    const int N = 12000;

    int counter = 0;

    for (int i = 5; i <=N; ++i) {
        // std::cout << i << std::endl;
        for (int j = i/3+1 ; j <(i-1)/2 + 1; ++j) {
            // std::cout << "trying " << j << " " << i << std::endl;
            int d = gcd(i, j);
            if (d == 1) {
                //double f = double(j)/double(i);
                //if (f < .5 && f > double(1)/double(3)) {
                    // std::cout << j << "/" << i << " f=" << f << std::endl;
                    // std::cout << j << "/" << i << std::endl;
                    ++counter;
                //}
            }
        }
    }

    std::cout << counter << std::endl;

    return 0;
}

