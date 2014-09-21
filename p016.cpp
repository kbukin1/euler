#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <numeric>

using namespace std;

void doubleVec(vector<int>& vec) {

    int carry = 0;
    bool too_small = false;

    for (int i = 0; i < vec.size(); i++) {
        int this_carry = 0;
        if (vec[i] + vec[i] + carry > 9) {
            this_carry = 1;
            if (i == vec.size() - 1)
                too_small = true;
        }
        else
            this_carry = 0;

        vec[i] = (vec[i] + vec[i] + carry) % 10;
        carry = this_carry;
    }

    if (too_small)
        vec.push_back(1);
}

int main() {
    vector<int> v;
    v.push_back(2);

    const int power = 1000;
    for (int i = 0; i < power-1; i++) {
        doubleVec(v);
    }
    
    cout << "Res: " << endl;

    copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));

    cout << "\nSum: " << accumulate(v.begin(), v.end(), 0) << endl;
}

