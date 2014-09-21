#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <numeric>


typedef unsigned long long Int;

// std::map<std::pair<Int, Int>, Int> E;

Int egcd(Int n, Int d) {
    if (n == 1 || d == 1)
        return 1;

    if (n == d)
        return n;

#if 0
    if (E.find(std::make_pair(n, d)) != E.end())
        return E[std::make_pair(n, d)];
#endif

    if (n > d) {
        n %= d;
        if (n == 0)
            return d;
    } else {
        d %= n;
        if (d == 0)
            return n;
    }

#if 0
    Int ret = n > d ? egcd(n-d, d) : egcd(n, d-n);
    E[std::make_pair(n, d)] = ret;
    return ret;
#endif
    return n > d ? egcd(n-d, d) : egcd(n, d-n);
}

Int igcd(Int n, Int d) {
    if (n == 1 || d == 1)
        return 1;

    if (n == d)
        return n;

    while (n != 1 && d != 1) {
        if (n > d) {
            n %= d;
            if (n == 0)
                return d;
        } else {
            d %= n;
            if (d == 0)
                return n;
        }
    }

    return 1;
}

int main_bad() {

    std::map<Int, std::set<Int> > found;

    for (Int i = 1; i <= 10000; ++i) {
    //for (Int i = 1; i <= 8; ++i) {
        std::cout << "i=" << i << std::endl;
        for (Int j = 1; j < i; ++j) {
            Int n = j;
            Int d = i;
            Int gcd = igcd(n, d);

            if (gcd != 1) {
                n /= gcd;
                d /= gcd;
            }

            if (found.find(n) == found.end()) {
                found[n] = std::set<Int>();
            }

            found[n].insert(d);
        }
    }

    Int sum = 0;
    for (std::map<Int, std::set<Int> >::const_iterator iter = found.begin(); 
            iter != found.end(); 
            ++iter) 
    {
        sum += iter->second.size();
    }

    std::cout << sum << std::endl;

    return 0;
}

int main() {
    std::vector<Int> p(1000000+1);

    for (Int i = 1; i < p.size(); ++i) {
        p[i] = i;
    }

    for (Int i = 2; i < p.size(); ++i) {
        if (p[i] == i) {
            for (Int j = i; j < p.size(); j += i) {
                p[j] /= i;
                p[j] *= (i-1);
            }
        }
    }

    std::cout << (std::accumulate(p.begin(), p.end(), Int(0))-1) << std::endl;
}

