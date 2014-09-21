#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <iterator>

int main() {

    typedef unsigned int uchar;
    //typedef unsigned char uchar;

    std::ifstream in("p059_cipher.txt");

    if (!in.is_open())
        return 1;

    std::vector<uchar> bytes;
    for (std::string line; getline(in, line); ) {
        std::stringstream ss(line);

        for (std::string b; getline(ss, b, ','); ) {
            std::istringstream tb(b);
            uchar value;
            tb >> value;
            bytes.push_back(value);
        }

    }

    // typedef unsigned char uchar;

    // uchar pass[3];
    bool stop = false;
    for (uchar i = 'a'; i <= 'z'; ++i) {
        for (uchar j = 'a'; j <= 'z'; ++j) {
            for (uchar k = 'a'; k <= 'z'; ++k) {
                bool non_found = false;

                // pass[0] = i;
                // pass[1] = j;
                // pass[2] = k;

                stop = false;
                for (size_t c = 0; c < bytes.size(); c += 3) {
                    if ((bytes[c] ^ i) < ' ' || (bytes[c] ^ i) > '~' ||
                        (bytes[c+1] ^ j) < ' ' || (bytes[c+1] ^ j) > '~' ||
                        (bytes[c+2] ^ k) < ' ' || (bytes[c+2] ^ k) > '~' ) {
                        stop = true;
                        break;
                    }
                }

                if (!stop) {
                    unsigned int long long sum = 0;
                    for (size_t c = 0; c < bytes.size(); c+=3) {
                        sum += (bytes[c] ^ i) + (bytes[c+1] ^ j) + (bytes[c+2] ^ k);
                    }
                    std::cout << "S: " << bytes.size() << "," << sum << std::endl;
                    std::cout << "K: " << (char) i << (char) j << (char) k << std::endl;
                    for (size_t c = 0; c < bytes.size(); c+=3) {
                        std::cout << (char)(bytes[c] ^ i) 
                                  << (char)(bytes[c+1] ^ j)
                                  << (char)(bytes[c+2] ^ k);
                    }
                    std::cout << "\n\n\n";
                }

                //tbytes = bytes;
                //std::cout << "\n\n\n";
            }
        }
    }

    std::copy(bytes.begin(), bytes.end(), std::ostream_iterator<uchar>(std::cout, "\n"));
}

