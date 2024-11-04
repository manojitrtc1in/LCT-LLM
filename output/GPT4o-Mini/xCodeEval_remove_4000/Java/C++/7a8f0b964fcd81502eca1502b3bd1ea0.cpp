#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
#include <string>
#include <limits>
#include <iomanip>
#include <thread>
#include <random>
#include <sstream>

using namespace std;

const double EPS = 1e-7;
const double PI = acos(-1.0);
long long id11 = LLONG_MIN;

class id9 {
public:
    double x, y;

    id9() : x(0.0), y(0.0) {}
    id9(double x, double y) : x(x), y(y) {}

    id9& set(double x, double y) {
        this->x = x;
        this->y = y;
        return *this;
    }

    id9 copy() const {
        return id9(x, y);
    }

    id9 add(const id9& v) const {
        return id9(x + v.x, y + v.y);
    }

    id9 sub(const id9& v) const {
        return id9(x - v.x, y - v.y);
    }

    id9 mul(double K) const {
        return id9(K * x, K * y);
    }

    double len() const {
        return sqrt(x * x + y * y);
    }

    double scalarProduct(const id9& v) const {
        return x * v.x + y * v.y;
    }

    double crossProduct(const id9& v) const {
        return x * v.y - v.x * y;
    }

    id9 rotate(double angle) const {
        double cosA = cos(angle);
        double sinA = sin(angle);
        return id9(x * cosA - y * sinA, x * sinA + y * cosA);
    }

    bool operator==(const id9& p) const {
        return abs(x - p.x) < EPS && abs(y - p.y) < EPS;
    }

    string toString() const {
        stringstream ss;
        ss << fixed << setprecision(3) << "(" << x << ", " << y << ")";
        return ss.str();
    }
};

class id5 {
public:
    id9 p1, p2;
    double A, B, C;

    id5(const id9& p1, const id9& p2) : p1(p1), p2(p2) {
        set(p1, p2);
    }

    void set(const id9& p1, const id9& p2) {
        this->p1 = p1;
        this->p2 = p2;
        A = p2.y - p1.y;
        B = p1.x - p2.x;
        C = -(A * p1.x + B * p1.y);
    }

    double calc(const id9& p) const {
        return A * p.x + B * p.y + C;
    }

    bool lay(const id9& p) const {
        return abs(this->calc(p)) < EPS;
    }

    bool contains(const id9& p) const {
        if (!lay(p)) return false;
        return (0.0 <= getT(p) && getT(p) <= 1.0);
    }

    double getT(const id9& p) const {
        if (!lay(p)) return NAN;
        if (abs(A) > EPS) return (p.y - p1.y) / A;
        if (abs(B) > EPS) return (p1.x - p.x) / B;
        throw runtime_error("Bad line");
    }
};

class id6 {
public:
    id9 c;
    double r;

    id6(const id9& c, double r) : c(c), r(r) {}

    bool lay(const id9& p) const {
        return (r - dist(c, p) >= -EPS && dist(c, p) - r <= EPS);
    }

    bool contains(const id9& p) const {
        return dist(c, p) < r + EPS;
    }
};

class Main {
public:
    ifstream in;
    ofstream out;
    double rP, vP, omegaP;
    id9 pp, ps;
    double vs;
    id6 star;

    Main() {
        in.open("input.txt");
        out.open("output.txt");
    }

    void run() {
        double xp, yp;
        in >> xp >> yp;
        pp.set(xp, yp);
        rP = sqrt(xp * xp + yp * yp);
        in >> vP;

        ps.set(nextDouble(), nextDouble());
        vs = nextDouble();

        double tvp = 1;
        vP /= tvp;
        vs /= tvp;

        omegaP = vP / rP;
        star = id6(id9(0.0, 0.0), nextDouble());

        double ans = 3e6;
        double left = 0;
        double right = ans;

        for (int it = 0; it < 10000; it++) {
            double mid = 0.5 * (left + right);
            if (can(mid)) {
                right = mid;
                ans = min(ans, mid);
            } else {
                left = mid;
            }
        }

        out << ans / tvp << endl;
    }

    bool can(double t) {
        return id4(ps, pp.rotate(t * vP / rP)) < t * vs;
    }

    double id4(const id9& p1, const id9& p2) {
        if (hasCSC(p1, p2, star)) {
            id9 tp1 = id10(p1, star);
            id9 tp2 = id10(p2, star);
            double ret = numeric_limits<double>::max();
            ret = min(ret, id1(p1, p2, tp1, tp2));
            return ret;
        }
        return dist(p1, p2);
    }

    bool hasCSC(const id9& p1, const id9& p2, const id6& c) {
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

    double id1(const id9& p1, const id9& p2, const id9& tp1, const id9& tp2) {
        double phi = acos(max(-1.0, min(1.0, tp1.scalarProduct(tp2) / tp1.len() / tp2.len())));
        return dist(p1, tp1) + dist(p2, tp2) + star.r * phi;
    }

    double dist(const id9& p1, const id9& p2) const {
        return sqrt(sqr(p2.x - p1.x) + sqr(p2.y - p1.y));
    }

    double nextDouble() {
        double value;
        in >> value;
        return value;
    }

    double sqr(double x) const {
        return x * x;
    }
};

int main() {
    Main main;
    main.run();
    return 0;
}
