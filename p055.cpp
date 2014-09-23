#include <iostream>
#include <vector>
#include <iterator>

typedef unsigned char Uint;

static bool is_lychrel(const std::vector<Uint>& n, Uint cnt) {
    if (cnt > 49)
        return true;

    std::vector<Uint> rn(n.rbegin(), n.rend());

    std::vector<Uint> sum(n.size());

    Uint carry = 0;
    for (Uint i = 0; i < n.size(); ++i) {
        Uint temp = n[i] + rn[i] + carry;

        if (temp > 9) {
            sum[i] = temp % 10;
            carry = temp / 10;
        } else {
            sum[i] = temp;
            carry = 0;
        }
    }     

    while (carry) {
        sum.push_back(carry % 10);
        carry /= 10;
    }

    bool palindrome = true;
    for (int i = 0; i < sum.size()/2; ++i){
        if (sum[i] != sum[sum.size() - i - 1])
            palindrome = false;
    }

    // std::cout << "cnt=" << (int)cnt << std::endl;
    // std::copy(sum.rbegin(), sum.rend(), std::ostream_iterator<int>(std::cout));
    // std::cout << std::endl;

    return palindrome ? false : is_lychrel(sum, ++cnt);
}

int main() {

    int cnt = 0;
    for (int i = 1; i < 10000; ++i) {
        std::vector<Uint> v;
        int temp = i;
        while (temp) {
            v.push_back(temp % 10);
            temp /= 10;
        }

        if (is_lychrel(v, 0))
            ++cnt;
    }

    std::cout << "Lychrel's cnt: " << cnt << std::endl;

    return 0;
}
