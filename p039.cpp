#include <map>
#include <set>
#include <iostream>


int main() {

    // const int P = 120;
    const int P = 1000;

    typedef std::map<int, std::set<std::set<int> > > Map;
    Map p;

    bool done_n = false;
    bool done_m = false;
    bool done_k = false;
    bool added_k = false;

    for (int n = 1; !done_n; ++n) {
        added_k = false;
        for (int m = n+1; !done_m; ++m) {
            int a = m*m - n*n;
            int b = 2 * m * n;
            int c = m*m + n*n;

            done_k = false;
            added_k = false;
            for (int k = 1; !done_k; ++k) {
                int perim_loc = k*(a+b+c);
                if (perim_loc <= P) {
                    std::set<int> t;
                    t.insert(k*a);
                    t.insert(k*b);
                    t.insert(k*c);
                    if (p.find(perim_loc) != p.end()) {
                        p[perim_loc].insert(t);
                    } else {
                        std::set<std::set<int> > temp;
                        temp.insert(t);
                        p[perim_loc] = temp;
                    }
                    added_k = true;
                }
                else {
                    done_k = true;
                }
            }

            if (!added_k)
                done_m = true;
        }
        if (!added_k)
            done_n = true;
    }
    // std::cout << a << " " << b << " " << c << std::endl;
    // std::cout << p[1000].size() << std::endl;

    size_t max_v = 0;
    int max_k = 0;

    Map::const_iterator end = p.end();
    for (Map::const_iterator i = p.begin(); i != end; ++i) {
        if (i->second.size() > max_v) {
            max_v = i->second.size();
            max_k = i->first;
        }
    }

    std::cout << "M: " << max_v << std::endl;
    std::cout << "k: " << max_k << std::endl;
    return 0;
}

