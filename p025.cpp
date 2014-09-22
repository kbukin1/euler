#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

int main() {

    const int D = 1000;
    std::vector<int> fib[3];

    fib[0].push_back(1);
    fib[1].push_back(1);
    fib[2].push_back(0);

    for (int i = 0, d = 3; true ; ++i, ++d) {
        int a = i % 3;
        int b = (i+1) % 3;
        int c = (i+2) % 3;

        // adding leading zeros
        for (int j = 0; j < (fib[b].size() - fib[a].size()); ++j) {
            fib[a].push_back(0);
        }
        for (int j = 0; j < (fib[c].size() - fib[a].size()); ++j) {
            fib[c].push_back(0);
        }

        int carry = 0;
        for (int j = 0; j < fib[a].size(); ++j) {
            int temp = fib[a][j] + fib[b][j] + carry;

            if (temp > 9) {
                fib[c][j] = temp % 10;
                carry = temp / 10;
            }
            else {
                fib[c][j] = temp;
                carry = 0;
            }
        }

        while (carry) {
            fib[c].push_back(carry % 10);
            carry /= 10;
        }

        if (fib[c].size() >= D) {
            std::cout << "c=" << c << ", d=" << d << std::endl;
            break;
        }
    }

    for (int i = 0; i < 3; ++i) {
        std::cout << "fib[" << i << "]=";
        std::copy(fib[i].rbegin(), fib[i].rend(), std::ostream_iterator<int>(std::cout));
        std::cout << std::endl;
    }

    return 0;
}

