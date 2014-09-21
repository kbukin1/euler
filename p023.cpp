#include <iostream>
#include <set>
#include <map>

void find_divs(unsigned n, std::set<unsigned>& div) {
    for (unsigned i = 1; i < n; ++i) {
        if ((n % i) == 0) {
            div.insert(i);
        }
    }
}

bool ab(unsigned n) {

    static std::map<unsigned, bool> mem;

    if (mem.find(n) != mem.end()) {
        return mem[n];
    }

    std::set<unsigned> div;

    find_divs(n, div);
    std::set<unsigned>::const_iterator end = div.end();

    unsigned sum = 0;
    for (std::set<unsigned>::const_iterator iter = div.begin(); iter != end; ++iter) {
        sum += *iter;
    }

    mem[n] = sum > n;
     return mem[n];
    //return sum > n;
}

bool comp(unsigned n) {
    for (unsigned i = 1; i <n; ++i) {
        if (ab(i) && ab(n-i)) {
            return true;
        }
    }
    return false;
}

int main() {

    const unsigned N = 28123;
    // const unsigned N = 3000;

    unsigned sum = 0;
    for (unsigned i = 1; i < N; ++i) {
        if (!comp(i)) { 
            sum += i;
        }
    }

    std::cout << sum << std::endl;

    return 0;
}

