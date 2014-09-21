#include <iostream>
#include <map>

static unsigned pd1(unsigned n) {
    unsigned sum = 1;
    unsigned step = (n & 1) ? 2 : 1;
    unsigned init = (n & 1) ? 3 : 2;
    for (unsigned i = init; i * i <= n; i += step) {
        if (n % i == 0) {
            sum += i + n / i;
        }
    }

    return sum;
}

// http://mathschallenge.net/index.php?section=faq&ref=number/sum_of_divisors
static unsigned pd2(unsigned n) {
    unsigned sum = 1;
    unsigned step = (n & 1) ? 2 : 1;
    unsigned init = (n & 1) ? 3 : 2;
    unsigned curr = n;
    for (unsigned i = init; i < n; i += step) { // XXX up-to sqrt(n) ? 
        if (curr % i == 0) {
            unsigned temp = i * i;
            curr /= i;
            while (curr % i == 0) {
                temp *= i;
                curr /= i;
            }
            sum *= (temp - 1)/(i - 1); // XXX no need to divide if "while" did not work
        }
    }

    return curr == n ? 1 : sum - n;
}

static unsigned pd3(unsigned n) {
    unsigned sum = 1;

    unsigned XXX = n;

    int i = 2;
    bool prime = true;
    while (i  <= n && n > 1) {
        if (n % i == 0) {
            prime = false;
            unsigned temp = i * i;
            n /= i;
            while (n % i == 0) {
                temp *= i;
                n /= i;
            }
            sum *= (temp - 1)/(i-1);
        }

        i = i == 2 ? 3 : i + 2;
    }

    return prime ? 1 : sum - XXX;
}

static inline unsigned d(unsigned n) {
    static std::map<unsigned, unsigned> cd;
    if (cd.find(n) != cd.end()) {
        return cd[n];
    }

    // SWITCH!
    unsigned sum = pd3(n);

    cd[n] = sum;
    return sum;
}


int main() {
    // pd3(10);

    unsigned sum = 0;
    //for (unsigned i = 1; i < 10000; ++i) {
    for (unsigned i = 1; i < 10000; ++i) {
        unsigned d_i  = d(i);
        unsigned d_ii = d(d_i);

        if (d_ii == i && d_i != i) {
            sum += i;
        }
    }

    //std::cout << d(284) << std::endl;
    std::cout << sum << std::endl;

    return 0;
}

