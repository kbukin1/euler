#include <iostream>
#include <vector>
#include <iterator>
#include <numeric> 

int do_chain(int n, std::vector<int>& ch) {
    if (n == 89) {
        if (n < ch.size())
            ch[n] = 1;
        return 1;
    }

    if (n == 1) {
        if (n < ch.size())
            ch[n] = 0;
        return 0;
    }

    if (n < ch.size() && ch[n] >= 0) {
        return ch[n];
    }

    int sum = 0;
    for (int val = n; val; val /= 10) {
        int temp = val % 10;
        sum += temp * temp;
    }

    int val = do_chain(sum, ch);
    if (n < ch.size()) {
        ch[n] = val;
    }
    
    return val;
}

int main() {

    const int N = 10000000;
    // std::vector<int> chain(N, -1);
    std::vector<int> chain(567, -1);
    chain[0] = 0;

    int sum = 0;
    for (int i = 1; i < N; ++i) {
        sum += do_chain(i, chain);
    }

    // std::copy(chain.begin(), chain.end(), std::ostream_iterator<int>(std::cout, " "));
    // std::cout << "\n";

    // sum = std::accumulate (chain.begin(), chain.end(), sum);
    std::cout << "sum: " << sum << std::endl;
}

