#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <set>

typedef std::vector<int> Raw;
typedef std::vector<Raw> Matrix;

struct MValue {
    int i, j, *p;
    MValue(int ai, int aj, int* ap) : i(ai), j(aj), p(ap) {}
};

struct ValCmp {
    bool operator() (const MValue& a, const MValue& b) const { return *a.p < *b.p; }
} cmp;

void print_matrix(const Matrix m) {
    std::cout << std::endl;
    for (size_t i = 0; i < m.size(); ++i) {
        for (size_t j = 0; j < m[0].size(); ++j) {
            std::cout << std::setw(2) << m[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

#if 0
bool block_structure(const Matrix& m) {
    for (size_t k = 1; k < m.size(); ++k) {
        bool found = false;
        for (size_t i = 0; i < k && !found; ++i) {
            for (size_t j = k; j < m.size() && !found; ++j) {
                if (m[i][j])
                    found = true;
            }
        }

        if (!found)
            return true;
    }

    return false;
}
#endif

void find_conn(int index, const Matrix& m,  std::set<int>& conn, std::set<int>& visited) {
    for (int i = 0; i < m[index].size(); ++i) {
        if (m[index][i]) {
            conn.insert(i);
        }
    }
    visited.insert(index);

    if (conn.size() == (m.size()))
        return;

    for (std::set<int>::const_iterator iter = conn.begin(); iter != conn.end(); ++iter) {
        if (visited.find(*iter) == visited.end()) {
            find_conn(*iter, m, conn, visited);
            if (conn.size() == (m.size()))
                return;
        }
    }
}

bool block_structure(const Matrix& m) {
    int index = 0;
    std::set<int> conn, visited;

    conn.insert(index);
    find_conn(index, m, conn, visited);

    return conn.size() != (m.size()) ? true : false;
}

int main() {
    // std::ifstream in("p107_network_s.txt");
    std::ifstream in("p107_network.txt");

    Matrix matrix;

    for (std::string line; getline(in, line); ) {
        std::stringstream ss(line);

        
        Raw raw;
        for (std::string val; getline(ss, val, ','); ) {
            int nval = 0;
            if (val != "-") {
                std::stringstream sval(val);
                sval >> nval;
            }

            raw.push_back(nval);
            // std::cout << nval << std::endl;
        }
        matrix.push_back(raw);
    }


    int weight = 0;
    std::vector<MValue> vals;
    for (size_t i = 0; i < matrix.size(); ++i) {
        for (size_t j = i; j < matrix[0].size(); ++j) {
            weight += matrix[i][j];
            vals.push_back(MValue(i, j, &( matrix[i][j])));
        }
    }

    for (size_t i = 0; i < vals.size(); ++i) { std::cout << *vals[i].p << " "; }
    std::cout << std::endl;
    std::sort(vals.begin(), vals.end(), cmp);
    for (size_t i = 0; i < vals.size(); ++i) { std::cout << *vals[i].p << " "; }
    std::cout << std::endl;

    // print_matrix(matrix);
    std::cout << "Before: " << weight << std::endl;

    for (int k = vals.size() - 1; k >= 0; --k) { 
        MValue& v = vals[k];
        int value = *v.p;
        matrix[v.i][v.j]=0;
        matrix[v.j][v.i]=0;

        if (block_structure(matrix)) {
            matrix[v.i][v.j]=value;
            matrix[v.j][v.i]=value;
        }
    }

    weight = 0;
    for (size_t i = 0; i < matrix.size(); ++i) {
        for (size_t j = i; j < matrix[0].size(); ++j) {
            weight += matrix[i][j];
        }
    }

    // print_matrix(matrix);
    std::cout << "After: " << weight << std::endl;

}

