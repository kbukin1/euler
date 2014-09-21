#include <iostream>
#include <vector>

struct Cmp {
    bool operator() (const std::pair<int, int>& a, const std::pair<int, int>& b) const {
        return a.second != b.second ? a.second < b.second : a.first < b.first;
    }
} cmp;

int main() {

    const int N = 100000 + 1;
    //const int N = 10 + 1;

    // -------------------------------------------
    // seive
    std::vector<int> p(N);
    std::fill(p.begin(), p.end(), 1);
    p[0] = p[1] = 0;
    for (int i = 2; i < N; ) {
        while (!p[i])
            ++i;
        for (int j = 2 * i; j < N; j += i)
            p[j] = 0;
        ++i;
    }

    std::vector<int> prim;
    for (int i = 0; i < N; ++i) 
        if (p[i])
            prim.push_back(i);

    std::cout << "prims are done\n";

    // -------------------------------------------
    // init
    std::vector<std::pair<int, int> > n;
    for (int i = 0; i < N; ++i) {
        n.push_back(std::make_pair(i, 1));
    }

    // -------------------------------------------
    // rads
    for (int i = 1; i < n.size(); ++i) {
        int val = i;
        // for (int j = 0; j < prim.size(); ++j) {
        for (int j = 0; prim[j] <= val && val != 1; ++j) {
            if (val % prim[j] == 0) {
                val /= prim[j];
                n[i].second *= prim[j];
                while (val % prim[j] == 0)
                    val /= prim[j];
            }
        }
    }

    std::cout << "rads are done\n";

#if 0 
    for (int i = 1; i < n.size(); ++i) {
        std::cout << n[i].first << " " << n[i].second << " " << i << std::endl;
    }
#endif

    std::sort(n.begin(), n.end(), cmp);

    std::cout << "sort is done\n";

#if 0 
    for (int i = 1; i < n.size(); ++i) {
        std::cout << n[i].first << " " << n[i].second << " " << i << std::endl;
    }
#endif

    //std::cout << n[6].first << std::endl;
    std::cout << n[10000].first << std::endl;

    return 0;
}
