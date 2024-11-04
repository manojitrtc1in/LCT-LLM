#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <iterator>
#include <cmath>
#include <iomanip>
#include <sstream>
#include <functional>

using namespace std;

const long BIG = 1000000007;

class Point {
public:
    int index;
    int x;
    int y;

    Point(int index, int x, int y) : index(index), x(x), y(y) {}

    int getX() const {
        return x;
    }

    int getY() const {
        return y;
    }

    bool operator<(const Point& other) const {
        return tie(x, y) < tie(other.x, other.y);
    }
};

long modMultiply(long a, long b) {
    return (a * b) % BIG;
}

long modAdd(long a, long b) {
    return (a + b) % BIG;
}

long modSubtract(long a, long b) {
    return (a - b + BIG) % BIG;
}

long id12(int a) {
    long result = 1;
    for (int index = 0; index < a; index++) {
        result = modMultiply(result, 2);
    }
    return result;
}

int countLines(const set<Point>& points) {
    set<int> xs, ys;
    for (const Point& point : points) {
        xs.insert(point.getX());
        ys.insert(point.getY());
    }
    return xs.size() + ys.size();
}

void solve() {
    int n;
    cin >> n;
    vector<Point> points;
    map<int, set<Point>> id3;

    for (int index = 0; index < n; index++) {
        int x, y;
        cin >> x >> y;
        Point point(index, x, y);
        points.push_back(point);
        id3[y].insert(point);
    }

    map<int, Point*> id49;
    for (const auto& [key, set] : id3) {
        Point* lastX = nullptr;
        for (const Point& point : set) {
            if (lastX != nullptr) {
                // Create edge between point and lastX (not implemented)
            }
            lastX = new Point(point);
            Point* lastY = id49[point.getX()];
            if (lastY != nullptr) {
                // Create edge between point and lastY (not implemented)
            }
