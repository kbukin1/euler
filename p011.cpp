#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

int main() {

    std::fstream g("grid.txt");

    std::vector<std::vector<int> > grid;
    for (std::string line; getline(g, line); ) {
        std::stringstream ss(line);

        int num;
        std::vector<int> row;
        while (ss >> num) {
            // std::cout << num << " ";
            row.push_back(num);
        }
        grid.push_back(row);
    }

    int w = grid[0].size();
    int h = grid.size();
    int block = 4;

    unsigned long long N = 1;
    unsigned long long temp = 1;

#if 1
    // horizontal
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < (w-block); ++j) {
            temp = 1;
            for (int k = 0; k < block; ++k) {
                temp *= grid[i][j+k];
            }
            N = std::max(N, temp);
        }
    }
    std::cout << "max1: " << N << std::endl;

    // vertical
    for (int i = 0; i < w; ++i) {
        // std::cout << "i=" << i << std::endl;
        for (int j = 0; j < (h-block); ++j) {
            // std::cout << "   j=" << j << std::endl;
            temp = 1;
            for (int k = 0; k < block; ++k) {
                temp *= grid[j+k][i];
            }
            N = std::max(N, temp);
            // std::cout << i << " " << j << " " << N << std::endl;
        }
    }
    std::cout << "max2: " << N << std::endl;
#endif

    // maj diag
    for (int i = 0; i < (w-block); ++i) {
        for (int j = 0; j < (h-block); ++j) {
            temp = 1;
            for (int k = 0; k < block; ++k) {
                temp *= grid[j+k][i+k];
            }
            N = std::max(N, temp);
        }
    }
    std::cout << "max3: " << N << std::endl;

    // min diag
    for (int i = 0; i < (w-block); ++i) {
        for (int j = 3; j < h; ++j) {
            temp = 1;
            for (int k = 0; k < block; ++k) {
                temp *= grid[j-k][i+k];
            }
            N = std::max(N, temp);
        }
    }
    std::cout << "max4: " << N << std::endl;


    return 0;
}

