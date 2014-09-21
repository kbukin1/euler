#include <iostream>
#include <vector>
#include <set>

std::set<int> rad(int val, const std::vector<int>& prim) {
    std::set<int>  ret;
    for (int j = 0; prim[j] <= val && val != 1; ++j) {
        if (val % prim[j] == 0) {
            val /= prim[j];
            ret.insert(prim[j]);
            while (val % prim[j] == 0)
                val /= prim[j];
        }
    }

    return ret;
}

int main() {

    const int N = 1000;

    // -------------------------------------------
    // seive
    std::vector<int> p(2*N);
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
    for (int i = 0; i < p.size(); ++i) 
        if (p[i])
            prim.push_back(i);

    std::cout << "sieve is done\n";

    for (int a = 2; a < N; ++a) {
        std::set<int> rad_a = rad(a, prim);
        for (int b = a+1; b < N ; ++b) {
            bool ab_coprimes = true;
            std::set<int> rad_b = rad(b, prim);

            std::set<int>::const_iterator ra_end = rad_a.end();
            for (std::set<int>::const_iterator ia = rad_a.begin(); ia != ra_end && ab_coprimes; ++ia) {
                if (rad_b.find(*ia) != rad_b.end())
                    ab_coprimes = false;
            }

            if (ab_coprimes) {
                int c = a + b;
                std::set<int> rad_c = rad(c, prim);
                bool abc_coprimes = true;

                for (std::set<int>::const_iterator ia = rad_a.begin(); ia != ra_end && abc_coprimes; ++ia) {
                    if (rad_c.find(*ia) != rad_c.end())
                        abc_coprimes = false;
                }

                if (abc_coprimes) {
                    std::set<int> rad_abc = rad( a * b * c, prim);

                    int rad_product = 1;
                    std::set<int>::const_iterator end = rad_abc.end();
                    for (std::set<int>::const_iterator i = rad_abc.begin(); i != end ; ++i) {
                        rad_product *= *i;
                    }

                    if (rad_product < c && c < N) {
                        std::cout << a << " " << b << " " << c << std::endl;
                    }
                }
            }

        }
    }

    return 0;
}
