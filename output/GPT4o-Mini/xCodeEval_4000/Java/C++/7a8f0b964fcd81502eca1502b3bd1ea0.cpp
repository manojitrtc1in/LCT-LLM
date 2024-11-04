#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
#include <iomanip>
#include <limits>
#include <string>
#include <sstream>
#include <random>
#include <algorithm>

using namespace std;

const double EPS = 1e-7;
const double PI = acos(-1.0);
const long long INF = 1e18;

class Point2D {
public:
    double x, y;

    Point2D() : x(0.0), y(0.0) {}

    Point2D(double x, double y) : x(x), y(y) {}

    Point2D set(double x, double y) {
        this->x = x;
        this->y = y;
        return *this;
    }

    Point2D add(const Point2D& v) const {
        return Point2D(x + v.x, y + v.y);
    }

    Point2D sub(const Point2D& v) const {
        return Point2D(x - v.x, y - v.y);
    }

    double len() const {
        return sqrt(x * x + y * y);
    }

    Point2D normalize(double newLen = 1.0) const {
        return Point2D(x * newLen / len(), y * newLen / len());
    }

    double scalarProduct(const Point2D& v) const {
        return x * v.x + y * v.y;
    }

    double dist(const Point2D& p) const {
        return sqrt(sqr(p.x - x) + sqr(p.y - y));
    }

    static double sqr(double x) {
        return x * x;
    }

    bool equals(const Point2D& p) const {
        return abs(x - p.x) < EPS && abs(y - p.y) < EPS;
    }
};

class Circle2D {
public:
    Point2D c;
    double r;

    Circle2D(Point2D c, double r) : c(c), r(r) {}

    bool contains(const Point2D& p) const {
        return c.dist(p) < r + EPS;
    }
};

class Main {
public:
    static long long initTime;
    static default_random_engine rnd;

    void run() {
        double xp, yp, vP, vs;
        cin >> xp >> yp;
        Point2D pp(xp, yp);
        double rP = sqrt(xp * xp + yp * yp);
        cin >> vP;
        Point2D ps;
        cin >> ps.x >> ps.y;
        cin >> vs;

        double tvp = 1;
        vP /= tvp;
        vs /= tvp;

        double omegaP = vP / rP;
        Circle2D star(Point2D(0.0, 0.0), 0.0); // Placeholder for radius
        double ans = 3e6;

        double left = 0;
        double right = ans;

        for (int it = 0; it < 10000; it++) {
            double mid = 0.5 * (left + right);
            if (can(mid, ps, pp, star, vP, vs)) {
                right = mid;
                ans = min(ans, mid);
            } else {
                left = mid;
            }
        }

        cout << fixed << setprecision(10) << ans / tvp << endl;
    }

    bool can(double t, const Point2D& ps, const Point2D& pp, const Circle2D& star, double vP, double vs) {
        return distPlanetar(ps, pp.rotate(t * vP / pp.len()), star) < t * vs;
    }

    double distPlanetar(const Point2D& p1, const Point2D& p2, const Circle2D& star) {
        if (hasCSC(p1, p2, star)) {
            // Placeholder for intersection logic
            return 0; // Replace with actual distance calculation
        }
        return p1.dist(p2);
    }

    bool hasCSC(const Point2D& p1, const Point2D& p2, const Circle2D& c) {
        double A = p2.y - p1.y;
        double B = p1.x - p2.x;
        double d = A * A + B * B;

        double dist = 0.0;

        if (abs(d) < EPS) {
            dist = p1.dist(c.c);
        } else {
            double t = (B * (p1.x - c.c.x) - A * (p1.y - c.c.y)) / d;
            if (0.0 <= t && t <= 1.0) {
                dist = sqrt(Point2D::sqr(p1.x - B * t - c.c.x) + Point2D::sqr(p1.y + A * t - c.c.y));
            } else {
                dist = min(p1.dist(c.c), p2.dist(c.c));
            }
        }

        return dist <= c.r + EPS;
    }
};

long long Main::initTime = 0;
default_random_engine Main::rnd(7777L);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Main().run();

    return 0;
}
