#include <iostream>
#include <vector>
#include <set>
#include <map>

typedef unsigned long long Uint;

const std::set<Uint>& rad(Uint val, const std::vector<Uint>& prim) {
    static std::map<Uint, std::set<Uint> > rads;

    if (rads.find(val) != rads.end())
        return rads[val];

    std::set<Uint>  ret;
    Uint val_loc = val;
    for (Uint j = 0; prim[j] <= val_loc && val_loc != 1; ++j) {
        if (val_loc % prim[j] == 0) {
            val_loc /= prim[j];
            ret.insert(prim[j]);
            while (val_loc % prim[j] == 0)
                val_loc /= prim[j];
        }
    }

    rads[val] = ret;
    return rads[val];
}

int main() {

    const Uint N = 1000;
    //const Uint N = 120000;

    // -------------------------------------------
    // seive
    std::vector<Uint> p(N);
    std::fill(p.begin(), p.end(), 1);
    p[0] = p[1] = 0;
    for (Uint i = 2; i < N; ) {
        while (!p[i])
            ++i;
        for (Uint j = 2 * i; j < N; j += i)
            p[j] = 0;
        ++i;
    }

    std::vector<Uint> prim;
    for (Uint i = 0; i < p.size(); ++i) 
        if (p[i])
            prim.push_back(i);

    std::cout << "sieve is done\n";

    Uint sum_c = 0;
    for (Uint a = 1; a < N; ++a) {
        const std::set<Uint>& rad_a = rad(a, prim);
        std::set<Uint>::const_iterator ra_end = rad_a.end();

        Uint step = (a & 1) ? 1 : 2; // if a is even b ought to be odd
        Uint b_end = N - a;
        for (Uint b = a+1; b < b_end ; b += step) {
            Uint c = a + b;

            if ((c & 1) == 0 && ((a & 1) == 0 || (b & 1) == 0))
                continue;

            bool ab_coprimes = true;
            const std::set<Uint>& rad_b = rad(b, prim);

            for (std::set<Uint>::const_iterator ia = rad_a.begin(); ia != ra_end && ab_coprimes; ++ia) {
                if (rad_b.find(*ia) != rad_b.end())
                    ab_coprimes = false;
            }

            if (ab_coprimes) {
                bool abc_coprimes = true;
                const std::set<Uint>& rad_c = rad(c, prim);

                std::set<Uint>::const_iterator rc_end = rad_c.end();
                for (std::set<Uint>::const_iterator ic = rad_c.begin(); ic != rc_end && abc_coprimes; ++ic) {
                    if (rad_a.find(*ic) != rad_a.end())
                        abc_coprimes = false;
                    if (rad_b.find(*ic) != rad_b.end())
                        abc_coprimes = false;
                }

                if (abc_coprimes) {
                    const std::set<Uint>& rad_abc = rad( a * b * c, prim);

                    Uint rad_product = 1;
                    std::set<Uint>::const_iterator end = rad_abc.end();
                    for (std::set<Uint>::const_iterator i = rad_abc.begin(); i != end ; ++i) {
                        rad_product *= *i;
                    }

                    if (rad_product < c) {
                        std::cout << a << " " << b << " " << c << "  " << rad_product << std::endl;
                        sum_c += c;
                    }
                }
            }
        }
    }


    std::cout << "sum_c: " << sum_c << std::endl;

    return 0;
}
