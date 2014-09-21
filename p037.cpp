#include <iostream>
#include <vector>
#include <iterator>
#include <numeric>

int main() {

    const int N = 2000000;
    std::vector<int> p(N, 1);
    p[0] = 0;
    p[1] = 0;

    for (int i = 2; i*i < N; ++i) {
        if (p[i] != 0) {
            for (int j = i * i; j  < N; j += i) {
                p[j] = 0;
            }
        }
    }

    int n = 0;
    int sum = 0;
    for (int i = 10; i < N; ++i) {
        if (p[i] != 0) {
            // right to left
            int val = i / 10;
            int order = 1;
            bool r2l_passed = true;
            for (; val != 0; val /= 10, order *= 10) {
                if (p[val] == 0){
                    r2l_passed = false;
                    break;
                }
            }
            
            // left to right
            if (r2l_passed) {
                val = i;
                for (int i = order; i != 1; i /= 10) {
                   int temp = val - (val % i);
                   val -= temp;
                   if (p[val] == 0) {
                       r2l_passed = false;
                   }
                }
            }

            if (r2l_passed) {
                sum += i;
                std::cout << "n=" << ++n << " " << i << std::endl;
            }
        }
    }

    std::cout << "sum: " << sum;

    // std::copy(p.begin(), p.end(), std::ostream_iterator<int>(std::cout, " "));
}
