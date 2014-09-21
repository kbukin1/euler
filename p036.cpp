#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

template <class T>
bool is_pal(T b, T e) {
    --e;
    while (b < e) {
        if (*b != *e) {
            return false;
        }
        ++b;
        --e;
    }

    return true;
}

void fill_digits(unsigned n, unsigned base, std::vector<unsigned>& res) {
    while (n >= base) {
        res.push_back(n % base);
        n /= base;
    }
    res.push_back(n);
}

int main() {

    unsigned sum = 0;
    for (unsigned i = 1; i < 1000000; ++i) {
        std::vector<unsigned> b10;
        fill_digits(i, 10, b10);
         
        std::vector<unsigned> b2;
        fill_digits(i, 2, b2);

        if (is_pal(b10.begin(), b10.end()) && is_pal(b2.begin(), b2.end()))
            sum += i;

    }

    std::cout << sum << std::endl;

    // std::copy(v.begin(), v.end(), std::ostream_iterator<unsigned>(std::cout, " "));


    return 0;
}

