#include <iostream>
#include <vector>

bool is_reversible(int i) {
    if ((i % 10) == 0)
        return false;

    int val1 = i;
    int val2 = 0;

    for (int order = 1; val1; ) {
        val2 = (10 * val2) + (val1 % 10);
        val1 /= 10;
    }

    for(int sum = val2 + i ; sum ; sum /= 10) {
        int d = sum % 10;
        // if (((d & 1) == 0) && (d != 0))
        if (((d & 1) == 0))
            return false;
    }

    return true;
}


int main() {

    // int const N = 1000000000;
    int const N = 1000;
    int const NH = N/2;

    int sum = 0;
    for(int i = 10; i <= N; ++i) {
        if ((i % 1000000) == 0)
            std::cout << i << std::endl;

        if (is_reversible(i)) {
            // sum += i != NH ? 2 : 1;
            std::cout << i << std::endl;
            sum += 1;
        }
    }

    std::cout << "sum: " << sum << std::endl;

    return 0;
}

