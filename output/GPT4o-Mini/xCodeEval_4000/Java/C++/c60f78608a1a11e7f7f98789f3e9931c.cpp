#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <iterator>
#include <cmath>
#include <iomanip>
#include <functional>
#include <sstream>
#include <queue>
#include <string>
#include <cassert>

using namespace std;

const long BIG = 1000000007;

class Point {
public:
    static const function<bool(const Point&, const Point&)> COMPARATOR_X;
    static const function<bool(const Point&, const Point&)> COMPARATOR_Y;
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
};

const function<bool(const Point&, const Point&)> Point::COMPARATOR_X = [](const Point& a, const Point& b) {
    return a.getX() < b.getX();
};

