#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

typedef signed long long Int;

Int collatz(Int i, std::vector<Int>& c) {
    if (i < c.size() && c[i] >= 0)
        return c[i];

    Int val = 1;
    
    if (i & 1) 
        val += collatz(3 * i + 1, c); 
    else
        val += collatz(i/2, c);

    if (i < c.size())
        c[i] = val;

    return val;
}


int main() {

    const Int N = 1000000;
    //const Int N = 20;

    std::vector<Int> c(N, -1);
    c[1] = 1;

    for (Int i = 1; i < N; ++i) {
        // collatz(i, c);

        if ((i % 100000) == 0)
            std::cout << i << std::endl;

        if (c[i] < 0) {
            Int val = 1;
            for (Int temp = i; temp != 1; temp = (temp & 1) ? 3 * temp + 1 : temp / 2, val++) {
            }
            c[i] = val;
        }
    }

    // std::copy(c.begin(), c.end(), std::ostream_iterator<Int>(std::cout, " "));

    std::vector<Int>::iterator mp = std::max_element(c.begin(), c.end());
    std::cout << "max is @ " << std::distance(c.begin(), mp);

    std::cout << std::endl;


    return 0;
}

