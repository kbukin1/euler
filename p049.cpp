#include <iostream>
#include <vector>
#include <numeric>
#include <iterator>
#include <map>

bool perm (int a, int b, int c) {
    std::map<int, int> sa, sb, sc;

    for (int i = 0; i < 4; ++i) {
        if (sa.find(a % 10) == sa.end())
            sa[a % 10] = 1;
        else
            sa[a % 10] += 1;

        if (sb.find(b % 10) == sb.end())
            sb[b % 10] = 1;
        else
            sb[b % 10] += 1;

        if (sc.find(c % 10) == sc.end())
            sc[c % 10] = 1;
        else
            sc[c % 10] += 1;


        a /= 10;
        b /= 10;
        c /= 10;
    }


    for (std::map<int, int>::const_iterator i = sa.begin(); i != sa.end(); ++i) {
        if (i->second != sb[i->first] || i->second != sc[i->first])
            return false;
    }

    return true;

}

int main() {
    const int N = 10000;

    std::vector<int> p(N, 1);
    p[0] = 0;
    p[1] = 0;

    for (int i = 2; i*i < N; ++i) {
        if (p[i] == 1) {
            for (int j = i*i; j < N; j += i)
                p[j] = 0;
        }
    }

    for (int i = 1000; i < N; ++i) {
        if (p[i] != 0) {
            for (int j = i+1; j < N; ++j) {
                if (p[j] != 0 && ((j+(j-i)) < N) && p[j+(j-i)] != 0) {
                    if (perm(i, j, j+(j-i)))
                        std::cout << i << " " << j << " " << (j+(j-i)) << std::endl;
                }
            }
        }
    }

    // std::copy(p.begin(), p.end(), std::ostream_iterator<int>(std::cout, " "));

    return 0;
}

