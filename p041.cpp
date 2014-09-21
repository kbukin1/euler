#include <iostream>
#include <vector>
#include <set>
#include <iterator>
#include <numeric>

typedef unsigned long long Int;

int main() {

    //const Int N = 2144;
    //const Int N = 10000000ull;
    // const Int N = 1000000000ull;
    const Int N = 10000000ull;

    std::cout << "hi\n";
    std::vector<Int> p(N, 1);
    p[0] = 0;
    p[1] = 0;

    for (Int i = 0; i*i < N; ++i) {
        if ((i % 1000) == 0)
            std::cout << i << "\n";

        if (p[i] != 0) {
            for (int j = i * i; j < N; j += i) {
                p[j] = 0;
            }
        }
    }

    std::cout << "primes are calculated\n";

    for (Int i = (N-1); i > 0; --i) {
        if (p[i] != 0) {
            std::set<Int> d;
            bool found = true;
            for (Int val = i; val != 0; val /= 10) {
                int temp = val % 10;
                if (d.find(temp) != d.end()) {
                    found = false;
                    break;
                }
                else 
                    d.insert(temp);
            }

            if (found) 
                for (int j = 1; j <= d.size(); ++j) {
                    if (d.find(j) == d.end()) {
                        found = false;
                        break;                       
                    }
                }

            if (found) {
                std::cout << "Found: " << i << std::endl;
                return 0;
            }
        }
    }

    // std::copy(p.begin(), p.end(), std::ostream_iterator<Int>(std::cout, " "));
    return 1;
}

