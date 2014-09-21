#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <string>


int main() {

    std::fstream mp("triangle.txt");

    std::vector<std::vector<int> > triangle;
    for (std::string line; getline(mp, line); ) {
        std::vector<int> level;
        std::stringstream ss(line);
        int val;
        while (ss >> val) {
            // std::cout << val << " ";
            level.push_back(val);
        }
        // std::cout << std::endl;
        triangle.push_back(level);
    }

    for (int i = triangle.size() - 1; i > 0; --i) {
        for (int j = 0; j < i; ++j) {
            triangle[i-1][j] += triangle[i][j] > triangle[i][j+1] ? triangle[i][j] : triangle[i][j+1];
        }
    }

    std::cout << "max: " << triangle[0][0]; 

    return 0;
}

