#include <iostream>

int maken(int a, int b, int c) {
    return a * 100000 + b * 10000 + c * 1000 +
           c * 100 + b * 10 + a;
}

bool checkn(int n) {
    for (int i = 100; i < 999; ++i) {
        if ((n % i) == 0) {
            int m = n/i;
            if (m >= 100 && m <= 999) {
                return true;
            }
        }
    }
    return false;
}

int main() {

    for (int i = 9; i >= 0; --i) {
        for (int j = 9; j >= 0; --j) {
            for (int k = 9; k >= 0; --k) {
                int N = maken(i, j, k);
                // std::cout << "Trying " << N << std::endl;
                if (checkn(N)) {
                    std::cout << "N: " << N << std::endl;
                    return 0;
                }
            }
        }
    }

    return 1;
}

