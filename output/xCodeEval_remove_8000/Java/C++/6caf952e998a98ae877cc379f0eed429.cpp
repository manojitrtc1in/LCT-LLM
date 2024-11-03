#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

struct Point {
    double x;
    double y;

    Point(double x, double y) : x(x), y(y) {}

    double distance(const Point& other) const {
        double dx = x - other.x;
        double dy = y - other.y;
        return sqrt(dx * dx + dy * dy);
    }

    double angle() const {
        return atan2(y, x);
    }

    Line line(const Point& other) const {
        double a = other.y - y;
        double b = x - other.x;
        double c = -a * x - b * y;
        return Line(a, b, c);
    }
};

struct Line {
    double a;
    double b;
    double c;

    Line(double a, double b, double c) : a(a), b(b), c(c) {}

    Point intersect(const Line& other) const {
        if (parallel(other))
            return Point(NAN, NAN);
        double det = a * other.b - b * other.a;
        double x = (c * other.b - b * other.c) / det;
        double y = (a * other.c - c * other.a) / det;
        return Point(x, y);
    }

    bool parallel(const Line& other) const {
        return abs(a * other.b - b * other.a) < 1e-8;
    }

    bool contains(const Point& point) const {
        return abs(value(point)) < 1e-8;
    }

    double value(const Point& point) const {
        return a * point.x + b * point.y + c;
    }

    Line perpendicular(const Point& point) const {
        return Line(-b, a, b * point.x - a * point.y);
    }
};

struct Segment {
    Point a;
    Point b;

    Segment(const Point& a, const Point& b) : a(a), b(b) {}

    double length() const {
        double dx = a.x - b.x;
        double dy = a.y - b.y;
        return sqrt(dx * dx + dy * dy);
    }

    double distance(const Point& point) const {
        double length = this->length();
        double left = point.distance(a);
        if (length < 1e-8)
            return left;
        double right = point.distance(b);
        if (left * left > right * right + length * length)
            return right;
        if (right * right > left * left + length * length)
            return left;
        return point.distance(line());
    }

    Line line() const {
        return a.line(b);
    }

    bool contains(const Point& point, bool includeEnds) const {
        if (a == point || b == point)
            return includeEnds;
        if (a == b)
            return false;
        Line line = this->line();
        if (!line.contains(point))
            return false;
        Line perpendicular = line.perpendicular(a);
        double aValue = perpendicular.value(a);
        double bValue = perpendicular.value(b);
        double pointValue = perpendicular.value(point);
        return (aValue < pointValue && pointValue < bValue) || (bValue < pointValue && pointValue < aValue);
    }

    Point intersect(const Line& line) const {
        Line selfLine = this->line();
        Point intersect = selfLine.intersect(line);
        if (intersect == Point(NAN, NAN))
            return Point(NAN, NAN);
        if (contains(intersect, true))
            return intersect;
        return Point(NAN, NAN);
    }

    double distance(const Segment& other) const {
        Line line = this->line();
        Line otherLine = other.line();
        Point p = line.intersect(otherLine);
        if (p != Point(NAN, NAN) && contains(p, true) && other.contains(p, true))
            return 0;
        return min(min(other.distance(a), other.distance(b)), min(distance(other.a), distance(other.b)));
    }
};

int main() {
    cout << "Hello world!" << endl;
    return 0;
}
