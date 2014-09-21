#include <iostream>
#include <iterator>
#include <string>
#include <vector>
#include <set>
#include <fstream>
#include <sstream>

int main() {

    std::fstream w("words.txt");

    std::vector<std::string> words;
    size_t max_len = 0;
    for (std::string line; getline(w, line); ) {
        std::stringstream ss(line);

        for (std::string word; getline(ss, word, ','); ) {
            words.push_back(word.substr(1, word.size() - 2));
            max_len = std::max(max_len, word.size() - 2);
        }
    }

    std::set<int> tn;
    for (int i = 1; i*(i+1)/2 <= max_len * ('Z' - 'A' + 1); ++i)
        tn.insert(i*(i+1)/2);

    // std::cout << max_len;
    int tot = 0;
    for (int i = 0; i < words.size(); ++i) {
        int val = 0;
        for (int j = 0; j < words[i].size(); ++j) {
            val += words[i][j] - 'A' + 1;
        }

        if (tn.find(val) != tn.end()) {
            std::cout << words[i] << std::endl;
            ++tot;
        }
    }

    std::cout << "tot: " << tot;

    // std::copy(words.begin(), words.end(), std::ostream_iterator<std::string>(std::cout, " "));

    return 0;
}

