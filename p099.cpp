#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <math.h>

typedef long double Double;

int main() {
    std::fstream f("base.txt");

    Double m = 0;
    int N = 0;
    int i = 0;
    for (std::string line; getline(f, line); ) {
        ++i;

        std::stringstream l(line);
        int base, exp;
        char sep;

        l >> base;
        l >> sep;
        l >> exp;
        
        Double cmp = Double(exp) * log(Double(base));

        if (m < cmp) {
            m = cmp;
            N = i;
        }
        std::cout << cmp << std::endl;
    }

    std::cout << N << std::endl;
}
