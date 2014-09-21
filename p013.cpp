#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <iterator>


int main() {

    std::fstream l("large.txt");

    std::vector<std::string> num_list;
    for (std::string line; getline(l, line); ) {
        num_list.push_back(line);
    }

    const int unit_w = 5;
    const int unit_max = 100000;
    int full_w = num_list[0].size();
    int unit_n = full_w / unit_w;

    std::vector<int> digits;
    int carry = 0;
    for (int j = 0; j < unit_n; ++j) {
        int sum_c = carry;
        for (int i = 0; i < num_list.size(); ++i) {
            std::stringstream unit_ss(num_list[i].substr(full_w - (j+1) * unit_w, unit_w));
            int unit_val;
            unit_ss >> unit_val;

            // std::cout << unit_val << std::endl;
            sum_c += unit_val;
        }
        // std::cout << "================\n";
        digits.push_back(sum_c % unit_max);
        carry = sum_c / unit_max;
    }
    // std::cout << carry << std::endl;

    std::cout << "sum: " << carry << ", " << digits[digits.size() - 1] << "," << digits[digits.size() - 2] << std::endl;

    // std::copy(num_list.begin(), num_list.end(), std::ostream_iterator<std::string>(std::cout, "\n"));

    return 0;
}
