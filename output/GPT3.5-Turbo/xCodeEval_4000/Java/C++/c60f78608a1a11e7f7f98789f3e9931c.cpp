#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

struct Point {
    int x;
    int y;
};

bool operator<(const Point& p1, const Point& p2) {
    return p1.x < p2.x || (p1.x == p2.x && p1.y < p2.y);
}

int countLines(set<Point>& points) {
    set<int> xs;
    set<int> ys;
    for (const Point& point : points) {
        xs.insert(point.x);
        ys.insert(point.y);
    }
    return xs.size() + ys.size();
}

long long modMultiply(long long a, long long b, long long mod) {
    return (a * b) % mod;
}

long long modAdd(long long a, long long b, long long mod) {
    return (a + b) % mod;
}

long long modSubtract(long long a, long long b, long long mod) {
    return (a - b + mod) % mod;
}

