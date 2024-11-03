#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

const double EPSILON = 1e-8;

class Point {
public:
    double x, y;

    Point(double x = 0, double y = 0) : x(x), y(y) {}

    bool operator==(const Point& other) const {
        return fabs(x - other.x) < EPSILON && fabs(y - other.y) < EPSILON;
    }

    bool operator!=(const Point& other) const {
        return !(*this == other);
    }

    double distance(const Point& other) const {
        double dx = x - other.x;
        double dy = y - other.y;
        return sqrt(dx * dx + dy * dy);
    }
};

class Line {
public:
    double a, b, c;

    Line(const Point& p1, const Point& p2) {
        a = p2.y - p1.y;
        b = p1.x - p2.x;
        c = -a * p1.x - b * p1.y;
    }

    bool contains(const Point& point) const {
        return fabs(a * point.x + b * point.y + c) < EPSILON;
    }

    bool parallel(const Line& other) const {
        return fabs(a * other.b - b * other.a) < EPSILON;
    }

    Point intersect(const Line& other) const {
        if (parallel(other)) {
            return Point();
        }
        double determinant = b * other.a - a * other.b;
        double x = (c * other.b - b * other.c) / determinant;
        double y = (a * other.c - c * other.a) / determinant;
        return Point(x, y);
    }
};

class Segment {
public:
    Point a, b;

    Segment(const Point& a, const Point& b) : a(a), b(b) {}

    double length() const {
        return a.distance(b);
    }

    double distance(const Point& point) const {
        double length = this->length();
        double left = point.distance(a);
        if (length < EPSILON) {
            return left;
        }
        double right = point.distance(b);
        if (left * left > right * right + length * length) {
            return right;
        }
        if (right * right > left * left + length * length) {
            return left;
        }
        Line line(a, b);
        return fabs(line.a * point.x + line.b * point.y + line.c) / sqrt(line.a * line.a + line.b * line.b);
    }

    bool contains(const Point& point, bool includeEnds) const {
        if (point == a || point == b) {
            return includeEnds;
        }
        if (a == b) {
            return false;
        }
        Line line(a, b);
        if (!line.contains(point)) {
            return false;
        }
        Line perpendicular(line.b, -line.a, line.a * a.y - line.b * a.x);
        double aValue = perpendicular.a * a.x + perpendicular.b * a.y + perpendicular.c;
        double bValue = perpendicular.a * b.x + perpendicular.b * b.y + perpendicular.c;
        double pointValue = perpendicular.a * point.x + perpendicular.b * point.y + perpendicular.c;
        return (aValue < pointValue && pointValue < bValue) || (bValue < pointValue && pointValue < aValue);
    }
};

int main() {
    // Your code here
    return 0;
}
