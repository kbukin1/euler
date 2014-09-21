#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <math.h>

int main() {

    typedef unsigned long long uint;

    //const uint N = 30;
    //  const uint N = 10000000ull;
    const uint N = 100000000ull;
    //const uint sN = (uint)::sqrt(N);
    const uint sN = N/2;

    uint *p = new uint[N];
    std::fill(p, p + N, 1);

    p[0] = p[1] = 0;
    uint i = 2;
    uint j = 2*i;
    while (i < sN) {
        for (j = 2 * i; j < N; j += i) { 
            p[j] = 0;
        }

        ++i;
        while(!p[i])
            ++i;
    }

    std::cout << "--\n";

    // std::set<uint> pr;
    std::vector<uint> pr;
    for (uint i = 2; i < N; ++i) { 
        if (p[i]) {
            // pr.insert(i);
            pr.push_back(i);
            // std::cout << i << std::endl;
        }
    }

    std::cout << "NP: " << pr.size() << std::endl;

    uint counter = 0;

    for (i = 4; i < N; ++i) {
        
    }
#if 1
    for (i = 0; i < pr.size(); ++i) {
        // for (uint j = i; j < pr.size(); ++j) {
        for (uint j = i; pr[i] * pr[j] < N; ++j) {
            // uint prod = pr[i] * pr[j];
            //if (prod < N) {
                //std::cout << prod << std::endl;
                ++counter;
            //}
        }
    }
#endif

#if 0
    // std::set<uint>::const_iterator end = pr.end(); 
    std::vector<uint>::const_iterator end = pr.end(); 
    for (i = 0; i < N; ++i) {
        // for (std::set<uint>::const_iterator iter = pr.begin(); iter != end; ++iter) {
        for (std::vector<uint>::const_iterator iter = pr.begin(); iter != end; ++iter) {
            // if ((i % *iter == 0) && pr.count(i/(*iter))) {
            if ((i % *iter == 0) && std::find(pr.begin(), pr.end(), i/(*iter)) != pr.end()){
                // std::cout << "  " << i << std::endl;
                ++counter;
                break;
            }
        }
    }
#endif

    std::cout << "C: " << counter << std::endl;

    return 0;
}

