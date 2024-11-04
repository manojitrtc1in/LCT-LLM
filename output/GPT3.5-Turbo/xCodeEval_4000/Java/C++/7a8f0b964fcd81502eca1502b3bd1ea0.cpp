#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

const double EPS = 1e-7;

struct Point2D {
    double x, y;

    Point2D() : x(0.0), y(0.0) {}

    Point2D(double x, double y) : x(x), y(y) {}

    Point2D operator+(const Point2D& other) const {
        return Point2D(x + other.x, y + other.y);
    }

    Point2D operator-(const Point2D& other) const {
        return Point2D(x - other.x, y - other.y);
    }

    Point2D operator*(double scalar) const {
        return Point2D(x * scalar, y * scalar);
    }

    Point2D operator/(double scalar) const {
        return Point2D(x / scalar, y / scalar);
    }

    double len() const {
        return sqrt(x * x + y * y);
    }

    Point2D normalize(double newLen = 1.0) const {
        double len = this->len();
        return Point2D(x * newLen / len, y * newLen / len);
    }

    double scalarProduct(const Point2D& other) const {
        return x * other.x + y * other.y;
    }

    double crossProduct(const Point2D& other) const {
        return x * other.y - y * other.x;
    }

    Point2D rotate90() const {
        return Point2D(-y, x);
    }

    Point2D rotate(double angle) const {
        double cosVal = cos(angle);
        double sinVal = sin(angle);
        return Point2D(x * cosVal - y * sinVal, x * sinVal + y * cosVal);
    }
};

struct Line2D {
    Point2D p1, p2;
    double A, B, C;

    Line2D(const Point2D& p1, const Point2D& p2) : p1(p1), p2(p2) {
        A = p2.y - p1.y;
        B = p1.x - p2.x;
        C = -(A * p1.x + B * p1.y);
    }

    double calc(const Point2D& p) const {
        return A * p.x + B * p.y + C;
    }

    bool lay(const Point2D& p) const {
        return abs(calc(p)) < EPS;
    }

    bool contains(const Point2D& p) const {
        if (!lay(p)) {
            return false;
        }
        return p1.x <= p.x && p.x <= p2.x && p1.y <= p.y && p.y <= p2.y;
    }

    double getT(const Point2D& p) const {
        if (!lay(p)) {
            return NAN;
        }
        if (abs(A) > EPS) {
            return (p.y - p1.y) / A;
        }
        if (abs(B) > EPS) {
            return (p1.x - p.x) / B;
        }
        throw runtime_error("Bad line");
    }

    Point2D getPoint(double t) const {
        return Point2D(p1.x - B * t, p1.y + A * t);
    }

    Point2D dir() const {
        return Point2D(-B, A);
    }

    Point2D normal() const {
        return Point2D(A, B);
    }

    Point2D projection(const Point2D& p) const {
        double t = (B * (p1.x - p.x) - A * (p1.y - p.y)) / (A * A + B * B);
        return Point2D(p1.x - B * t, p1.y + A * t);
    }
};

struct Circle2D {
    Point2D c;
    double r;

    Circle2D(const Point2D& c, double r) : c(c), r(r) {}

    double area() const {
        return M_PI * r * r;
    }

    bool lay(const Point2D& p) const {
        return r - EPS <= (p - c).len() && (p - c).len() <= r + EPS;
    }

    bool contains(const Point2D& p) const {
        return (p - c).len() < r + EPS;
    }
};

double sqr(double x) {
    return x * x;
}

double dist(const Point2D& p1, const Point2D& p2) {
    return sqrt(sqr(p2.x - p1.x) + sqr(p2.y - p1.y));
}

double distPlanetar(const Point2D& p1, const Point2D& p2, const Circle2D& star) {
    if (hasCSC(p1, p2, star)) {
        vector<Point2D> tp1 = tppc(p1, star);
        vector<Point2D> tp2 = tppc(p2, star);

        double ret = 1e100;

        ret = min(ret, distWithStar(p1, p2, tp1[0], tp2[0]));
        ret = min(ret, distWithStar(p1, p2, tp1[0], tp2[1]));
        ret = min(ret, distWithStar(p1, p2, tp1[1], tp2[0]));
        ret = min(ret, distWithStar(p1, p2, tp1[1], tp2[1]));

        return ret;
    }

    return dist(p1, p2);
}

bool hasCSC(const Point2D& p1, const Point2D& p2, const Circle2D& c) {
    double A = p2.y - p1.y;
    double B = p1.x - p2.x;
    double d = A * A + B * B;

    double dist = 0.0;

    if (abs(d) < EPS) {
        dist = dist(p1, c.c);
    } else {
        double t = (B * (p1.x - c.c.x) - A * (p1.y - c.c.y)) / d;
        if (0.0 <= t && t <= 1.0) {
            dist = sqrt(sqr(p1.x - B * t - c.c.x) + sqr(p1.y + A * t - c.c.y));
        } else {
            dist = min(dist(p1, c.c), dist(p2, c.c));
        }
    }

    return dist <= c.r + EPS;
}

vector<Point2D> tppc(const Point2D& p, const Circle2D& c) {
    double d = dist(p, c.c);
    double cosVal = c.r / d;
    double sinVal = sqrt(1.0 - cosVal * cosVal);
    Point2D v = (p - c.c).normalize(c.r);
    return {v.rotate(cosVal, sinVal), v.rotate(cosVal, -sinVal)};
}

double distWithStar(const Point2D& p1, const Point2D& p2, const Point2D& tp1, const Point2D& tp2, const Circle2D& star) {
    double phi = acos(max(-1.0, min(1.0, tp1.scalarProduct(tp2) / tp1.len() / tp2.len())));
    return dist(p1, tp1) + dist(p2, tp2) + star.r * phi;
}

bool can(double t, const Point2D& ps, const Point2D& pp, double rP, double vP, double omegaP, double vs, const Circle2D& star) {
    return distPlanetar(ps, pp.rotate(t * vP / rP), star) < t * vs;
}

double binarySearch(double left, double right, const Point2D& ps, const Point2D& pp, double rP, double vP, double omegaP, double vs, const Circle2D& star) {
    double ans = 3e6;

    for (int it = 0; it < 10000; it++) {
        double mid = 0.5 * (left + right);

        if (can(mid, ps, pp, rP, vP, omegaP, vs, star)) {
            right = mid;
            ans = min(ans, mid);
        } else {
            left = mid;
        }
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    double xp, yp, rP, vP, omegaP, vs, tvp;
    Point2D pp, ps;
    Circle2D star;

    cin >> xp >> yp >> rP >> vP >> omegaP >> ps.x >> ps.y >> vs >> tvp;
    pp = Point2D(xp, yp);
    rP = sqrt(xp * xp + yp * yp);
    vP /= tvp;
    vs /= tvp;
    omegaP = vP / rP;
    cin >> star.c.x >> star.c.y >> star.r;

    double ans = binarySearch(0, 3e6, ps, pp, rP, vP, omegaP, vs, star);

    cout << fixed << setprecision(10) << ans / tvp << endl;

    return 0;
}
