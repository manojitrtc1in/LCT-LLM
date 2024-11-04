#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

const double epsilon = 1e-8;

class Point {
public:
    double x, y;

    Point(double x = 0, double y = 0) : x(x), y(y) {}

    bool operator==(const Point& other) const {
        return abs(x - other.x) < epsilon && abs(y - other.y) < epsilon;
    }

    bool operator!=(const Point& other) const {
        return !(*this == other);
    }

    double distance(const Point& other) const {
        double dx = x - other.x;
        double dy = y - other.y;
        return sqrt(dx * dx + dy * dy);
    }

    double angle() const {
        return atan2(y, x);
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
        return abs(value(point)) < epsilon;
    }

    double value(const Point& point) const {
        return a * point.x + b * point.y + c;
    }

    bool parallel(const Line& other) const {
        return abs(a * other.b - b * other.a) < epsilon;
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
        double dx = a.x - b.x;
        double dy = a.y - b.y;
        return sqrt(dx * dx + dy * dy);
    }

    double distance(const Point& point) const {
        double length = this->length();
        double left = point.distance(a);
        if (length < epsilon) {
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
        return abs(line.value(point)) / length;
    }

    bool contains(const Point& point, bool includeEnds) const {
        if (point == a || point == b) {
            return includeEnds;
        }
        Line line(a, b);
        if (!line.contains(point)) {
            return false;
        }
        Line perpendicular(a, line.angle() + M_PI / 2);
        double aValue = perpendicular.value(a);
        double bValue = perpendicular.value(b);
        double pointValue = perpendicular.value(point);
        return (aValue < pointValue && pointValue < bValue) || (bValue < pointValue && pointValue < aValue);
    }

    Line line() const {
        return Line(a, b);
    }

    Point middle() const {
        return Point((a.x + b.x) / 2, (a.y + b.y) / 2);
    }

    Point intersect(const Line& line) const {
        Line selfLine = this->line();
        Point intersection = selfLine.intersect(line);
        if (contains(intersection, true)) {
            return intersection;
        }
        return Point();
    }

    double distance(const Segment& other) const {
        Line line = this->line();
        Line otherLine = other.line();
        Point p = line.intersect(otherLine);
        if (p != Point() && contains(p, true) && other.contains(p, true)) {
            return 0;
        }
        return min(min(other.distance(a), other.distance(b)), min(distance(other.a), distance(other.b)));
    }
};

int main() {
    cout << "Hello world!" << endl;
    return 0;
}
