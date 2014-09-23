#include <iostream>
#include <algorithm>
#include <iterator>
#include <math.h>

int main() {

    int n[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    size_t ns = sizeof(n)/sizeof(n[0]);

    unsigned long long sum = 0;
    do {

        int n1 = 100*n[1] + 10*n[2] + n[3];
        int n2 = 100*n[2] + 10*n[3] + n[4];
        int n3 = 100*n[3] + 10*n[4] + n[5];
        int n4 = 100*n[4] + 10*n[5] + n[6];
        int n5 = 100*n[5] + 10*n[6] + n[7];
        int n6 = 100*n[6] + 10*n[7] + n[8];
        int n7 = 100*n[7] + 10*n[8] + n[9];
                       
        if ((n1 % 2) == 0 &&
            (n2 % 3) == 0 && 
            (n3 % 5) == 0 && 
            (n4 % 7) == 0 && 
            (n5 % 11) == 0 && 
            (n6 % 13) == 0 && 
            (n7 % 17) == 0) 
        {
            std::copy(n, n+ns, std::ostream_iterator<int>(std::cout));
            std::cout << std::endl;

            for (int i = 0; i < 10; ++i) {
                sum += (unsigned long long)::pow(10, ns - i - 1) * n[i];
            }
        }

    } while (std::next_permutation(n, n + ns));

    std::cout << "Sum: " << sum << std::endl;

    return 0;
}

