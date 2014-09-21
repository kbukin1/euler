#include <iostream>
#include <map>

typedef std::map<int, int> Map;

Map digits(int i) {
    Map m;

    for (int val = i; val; val /= 10) {
        int digit = val % 10;
        if (m.find(digit) == m.end())
            m[digit] = 1;
        else
            m[digit] += 1;
    }

    return m;
}

bool cmp_maps(const Map& m1, Map& m2) {
    if (m1.size() != m2.size())
        return false;

    for (Map::const_iterator i = m1.begin(); i != m1.end(); ++i) {
        if (m2.find(i->first) == m2.end())
            return false;
        else {
            if (m2[i->first] != i->second)
                return false;
        }
    }

    return true;
}

int main() {

#if 1
    //const int N = 100;
    const int N = 1000000;

    for (int order = 1; order < N; order *= 10) {
    //for (int order = 10000; order < N; order *= 10) {
        const int min = 10 * order;
        const int max = 17 * order;
        for (int i = min; i <= max; ++i) {
            // std::cout << i << std::endl;
            Map m1 = digits(i);

            bool found = true;
            for (int m = 2; m < 7; ++m) {
                Map m2 = digits(m * i);
                if (!cmp_maps(m1, m2)) {
                    found = false;
                    break;
                }
            }

            if (found) {
                std::cout << "Found: " << i << std::endl;
                return 0;
            }
        }
    }
#endif

    //std::map<int, int> m1 = digits(125874);
    //std::map<int, int> m2 = digits(2*125874);
    //std::cout << cmp_maps(m1, m2) << std::endl;
    
    //std::map<int, int> m1 = digits(100255);
    //std::map<int, int> m2 = digits(2*100255);
    //std::cout << cmp_maps(m1, m2) << std::endl;

    return 0;
}

