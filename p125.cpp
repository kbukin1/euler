#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <numeric>

#include <string.h>
#include <stdio.h>

typedef unsigned long long Int;

std::map<std::pair<Int, Int>, Int> S;

Int sum(Int from, Int to) {
    --from;

#if 0 
    if (S.find(std::make_pair(from, to)) != S.end())
        return S[std::make_pair(from, to)];
#endif

    Int sf = from * (from + 1) * (2 * from + 1) / 6;
    Int st = to * (to + 1) * (2 * to + 1) / 6;

    // S[std::make_pair(from, to)] = st - sf;

    return st - sf;
}

bool sum_of_squares(Int n) {
    for (Int i = 1; i*i  < n; ++i) {
        for (Int j = 1; j < i ; ++j) {
            if (n == sum(j, i)) {
                // std::cout << j << ".." << i <<std::endl;
                return true;
            }
        }
    }

    return false;
}

int amain() {

    Int sum = 0;
    Int count = 0;

    //for(Int o = 0, s = 1, e = 10; o < 4; ++o, s*=10, e *= 10) {
    for(Int o = 0, s = 1, e = 10; o < 2; ++o, s*=10, e *= 10) {
        for (Int n = s; n < e; ++n) {
            Int pola = n * 10 + n % 10;
            Int polb = n;

            Int nd = n;
            for (Int i = 0; i < o; ++i) {
                pola *= 10;
                polb *= 10;

                nd = nd / 10;
                pola += nd % 10;
                polb += nd % 10;
            }

#if 1
            //if (pola < 100000000)  {
             if (pola < 1000)  {
                // std::cout << pola << std::endl;
                if (sum_of_squares(pola))  {
                    std::cout << pola << std::endl;
                    sum += pola;
                    ++count;
                }
            }

            //if (polb < 100000000) {
            if (polb < 1000) {
                // std::cout << polb << std::endl;
                if (sum_of_squares(polb)) {
                    std::cout << polb << std::endl;
                    sum += polb;
                    ++count;
                }
            }
#endif
            // std::cout << o << " " << pola << ":" << polb << std::endl;
        }

    }

    std::cout << "Sum=" << sum << std::endl;
    std::cout << "Count=" << count << std::endl;

    return 0;
}

bool pol(Int n) {
    char num[32];
    sprintf(num, "%d", n);
    size_t size = strlen(num);
    size_t hsize = strlen(num)/2;

    if (size == 1)
        return true;

    for (size_t i = 0; i < hsize; ++i) {
        if (num[i] != num[size - 1 - i]) {
            return false;
        }
    }
    return true;
}

int main() {
    std::vector<Int> squares;

    //const Int N = 1000;
    const Int N = 100000000;

    for (Int i = 1, p = 0; i * i + p * p < N; p = i, ++i) {
        squares.push_back(i * i);
    }

    std::set<Int> nums;

    for (Int i = 0; i < squares.size(); ++i) {
        Int s = 0;
        for (Int j = i; j < squares.size(); ++j) {
            s += squares[j];
            if (s >= N)
                break;

            if (j != i && pol(s)) {
                nums.insert(s);
                // std::cout << s << std::endl;
            }
        }
    }

    std::copy(nums.begin(), nums.end(), std::ostream_iterator<Int>(std::cout, "\n"));

    Int S=0;
    std::set<Int>::const_iterator end = nums.end();
    for (std::set<Int>::const_iterator i = nums.begin(); i != end; ++i) {
        S += *i;
    }

    std::cout << "Sum=" << S << std::endl;
    // std::cout << "Sum=" << std::accumulate(nums.begin(), nums.end(), 0) <<  std::endl;

}

