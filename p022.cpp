#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <assert.h>

int main() {

    std::ifstream in("names.txt");

    if (!in.is_open())
        return 1;

    std::vector<std::string> names;
    for (std::string line; getline(in, line); ) {
        std::stringstream ss(line);

        for (std::string name; getline(ss, name, ','); ) {
            size_t s = name.find_first_not_of('"');
            size_t e = name.find_last_not_of('"');

            assert(s != std::string::npos && e != std::string::npos);
            names.push_back(name.substr(s, e));
        }
    }

    std::sort(names.begin(), names.end());

    unsigned tot = 0;

    std::vector<std::string>::size_type size = names.size();
    for (std::vector<std::string>::size_type i = 0; i < size; ++i) {
        int nw = 0;
        for (size_t ni = 0; ni < names[i].size(); ++ni) {
           nw += names[i][ni] - 'A' + 1; 
        }

        tot += nw * (i + 1);
    }

    std::cout << tot << std::endl;

    // std::copy(names.begin(), names.end(), std::ostream_iterator<std::string>(std::cout, "\n"));

    return 0;
}

