#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>  
#include <numeric>  

int main() {

    typedef unsigned int Uint;
    const int N = 100;

    std::vector<int> p;
    p.push_back(1);

    for (Uint i = 2; i < N+1; ++i) {

        Uint carry = 0;
        for (Uint j = 0; j < p.size(); ++j) {
            Uint temp = p[j] * i + carry;

            if (temp > 9) {
                p[j] = temp % 10;
                carry = temp / 10;
            }
            else {
                p[j] = temp;
                carry = 0;
            }

        }

        while (carry) {
            p.push_back(carry % 10);
            carry /= 10;
        }

        // std::cout << "i=" << i << " : ";
        // std::copy(p.rbegin(), p.rend(), std::ostream_iterator<Uint>(std::cout));
        // std::cout << "\n";
    }

    std::cout << "Sum: " << std::accumulate(p.begin(), p.end(), 0) << std::endl;

    return 0;
}

