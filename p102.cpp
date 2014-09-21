#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

static bool same_side(long long int sx, long long int sy, long long int ex, long long int ey, long long int px, long long int py, long long int qx, long long int qy) {
    long long int pz = (ex - sx) * (py - sy) - (px - sx) * (ey - sy);
    long long int qz = (ex - sx) * (qy - sy) - (qx - sx) * (ey - sy);

    return pz * qz > 0;
}

static long long int contains_origin(long long int ax, long long int ay, long long int bx, long long int by, long long int cx, long long int cy) {

    return same_side(ax, ay, bx, by, cx, cy, 0, 0) &&
           same_side(bx, by, cx, cy, ax, ay, 0, 0) &&
           same_side(cx, cy, ax, ay, bx, by, 0, 0);
}

int main() {
    std::fstream triangles("triangles.txt");

    long long int sum;
    for (std::string line; getline(triangles, line); ) {
        std::stringstream tr(line);

        long long int ax, ay, bx, by, cx, cy;
        char temp;

        tr >> ax >> temp >> ay >> temp >> bx >> temp >> by >> temp >> cx >> temp >> cy;

        sum += contains_origin(ax, ay, bx, by, cx, cy);
    }

    std::cout << "sum: " << sum << std::endl;

    return 0;
}

