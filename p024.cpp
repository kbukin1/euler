#include <iostream>
#include <algorithm>

int main() {

    char str [] = "0123456789";

    const int N = 1000000;
    for (int i = 1; i < N; i++)
        std::next_permutation(str, str+sizeof(str)-1);

    std::cout << N << "th perm: " << str << std::endl;

    return 0;
}

