#include <iostream>
#include <vector>
#include <iterator>
#include <numeric>


int main() {

    // const int N = 20;
    const int N = 10000;

    std::vector<int> p(N, 1);
    p[0] = 0;
    p[1] = 0;

    for (int i = 2; i*i < N; ++i) {
        if (p[i] != 0) {
            for (int j = i * i; j < N; j += i)
                p[j] = 0;
        }
    }

    for (int i = 3; i < N; i += 2) {
        if (p[i] == 0) {
            bool found = false;
            for (int j = 1; i > 2 * j * j; ++j) {
                if (p[i - 2 * j * j] != 0) {
                    found = true;
                    break;
                }
            }

            if (!found) {
                std::cout << "!found: " << i << std::endl;
                return 0;
            }
        }
    }

    // std::copy(p.begin(), p.end(), std::ostream_iterator<int>(std::cout, " " ));
    return 1;
}
