#include <iostream>
#include <string.h>
#include <stdio.h>

typedef unsigned long long Int;
//typedef int Int;

bool is_bouncy(Int n) {
    char s[12];

    sprintf(s, "%llu", n);
    Int size = strlen(s);

    bool inc = true;
    for (Int i = 0; i < (size-1); ++i) {
        if (s[i] > s[i+1]) {
            inc = false;
            break;
        }
    }

    if (inc)
        return false;

    bool dec = true;
    for (Int i = 0; i < (size-1); ++i) {
        if (s[i] < s[i+1]) {
            dec = false;
            break;
        }
    }

    if (dec)
        return false;

    return true;
}

int main() {

    Int b = 0;

    // for (Int i = 1; i < 21782; ++i) {
    for (Int i = 1; i < 100000000; ++i) {
        if (is_bouncy(i))
            b++;

        if (b != 0) {
#if 0
            // std::cout << double(b)/double(i) << std::endl;
            std::cout << b << "/" << i << std::endl;
            if ((i / b == 9) && (i % b == 0)) {
                std::cout << i << std::endl;
            }
#endif
            if (double(b)/double(i) == .99) {
                std::cout << i << std::endl;
            }
        }
    }

    return 0;
}
