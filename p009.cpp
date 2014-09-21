#include <assert.h>
#include <iostream>
#include <iterator>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;
typedef long long int Int;
typedef vector<vector<Int> > combinations;

int log2(Int a) {
    int bits=0;
    while (a!=0) {
        ++bits;
        a>>=1;
    };
    return bits;
}

bool mul_is_safe(Int a, Int b) {
    int a_bits=log2(a); 
    int b_bits=log2(b);
    return a_bits+b_bits <= 8 * sizeof(Int);
}

Int fact(Int from, Int to) {
    Int ret = 1;
    for (Int i = from; i <= to; i++) {
        assert(mul_is_safe(ret, i));
        ret *= i;
    }
    return ret;
}

combinations partAll(int n, int w) {
    assert(n > 0 && w > 0);

    // cout << "n=" << n << " w=" << w << endl;
    
    combinations ret;
    if (w == 1) {
        vector<Int> pv;
        pv.push_back(n);
        ret.push_back(pv);
        return ret;
    }

    for (int i = n-w+1; i > 0 ; i--) {
        combinations comb = partAll(n-i, w-1);
        for (int j = 0; j < comb.size(); j++) {
            comb[j].push_back(i);
            ret.push_back(comb[j]);
        }
    }

    for (int i = 0; i < ret.size(); i++)
        for (int j = 0; j < ret[i].size(); j++)
            sort(ret[i].begin(), ret[i].end());

    return ret;
}

combinations uniqPart(const combinations& comb) {
    set<vector<Int> > uniq_comb;
    copy(comb.begin(), comb.end(), inserter(uniq_comb, uniq_comb.begin()));

    combinations ret;

    for (set<vector<Int> >::const_iterator iter = uniq_comb.begin();
            iter != uniq_comb.end(); ++iter) {
        vector<Int> temp;
        for (int j = 0; j < iter->size(); j++) {
            temp.push_back((*iter)[j]);
        }
        ret.push_back(temp);
    }
    return ret;
}

Int countPermuations(const vector<Int> vect) {
    Int denom = 1;
    set<Int> uniq_el;
    copy(vect.begin(), vect.end(), inserter(uniq_el, uniq_el.begin()));

    for (set<Int>::const_iterator iter = uniq_el.begin(); iter != uniq_el.end(); ++iter) {
        denom *= fact(1, count(vect.begin(), vect.end(), *iter));
    }

    return fact(1, vect.size()) / denom;
}

Int countPermuations(const combinations& comb) {
    Int ret = 0;
    for (int i = 0; i < comb.size(); ++i) {
        ret += countPermuations(comb[i]);
    }
    return ret;
}

void printComb(const combinations& comb) {
    for (int i = 0; i < comb.size(); i++) {
        copy(comb[i].begin(), comb[i].end(), ostream_iterator<Int>(cout, " "));
        cout << endl;
    }
}

int main() {
    assert(sizeof(Int) == 8);

    combinations comb = uniqPart(partAll(1000, 3));
    // printComb(comb);

    for (int i = 0; i < comb.size(); i++) {
        Int a = comb[i][0];
        Int b = comb[i][1];
        Int c = comb[i][2];

        if (a * a + b * b == c * c) {
            cout << "a=" << a << " b=" << b << " c=" << c << endl;
            cout << "abc=" << a*b*c << endl;
        }
    }
        

    /*
    Int total = 0;
    const int N = 15;
    for (int i = 1; i <= N; i++) {
        combinations comb = uniqPart(partAll(N, i));
        Int perm = countPermuations(comb);
        total += perm;
        cout << "Perm for " << i << " partitions: " << perm << endl;
        printComb(comb);
        cout << endl;
    }
    cout << "Total: " << total << endl;
    */

    return 0;
}

