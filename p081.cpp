#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <limits>  
#include <assert.h>

typedef int Int;
//typedef unsigned long long int Int;
//typedef signed long long int Int;

int main() {

    std::fstream m ("matrix.txt");

    std::vector<std::vector<Int> > grid;
    Int last_size = 0;
    Int tot = 0;
    for (std::string line; getline(m, line);) {
        std::stringstream ss(line);

        Int i;
        char temp;
        std::vector<Int> row;
        while (ss >> i) {
            row.push_back(i);
            tot += i;
            ss >> temp;
        }

        assert(row.size() == last_size || last_size == 0);
        last_size = row.size();

        grid.push_back(row);
    }

    std::vector<Int> mv(grid.size() + 1, std::numeric_limits<Int>::max());

    mv[1] = 0;

    for (Int i = 0; i < grid.size(); ++i) {
        for (Int j = 0; j < last_size; ++j) {
            mv[j + 1] = std::min(mv[j+1], mv[j]) + grid[i][j];
            // std::cout << i << " " << j << " " << mv[j+1] << std::endl;
        }
    }

    std::cout << "sum: " << mv[grid.size()] << std::endl;
    std::cout << "tot: " << tot << std::endl;

    return 0;
}

