#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <string>
#include <sstream>

using namespace std;

const long long inf = 1e10;
const long long mod = 998244353;
const long long num = 1e9 + 7;

class pair1 {
public:
    int x, y;

    pair1(int a, int i) : x(a), y(i) {}

    bool operator<(const pair1& other) const {
        return x < other.x;
    }

    string toString() const {
        return to_string(x) + " " + to_string(y);
    }
};

long long inver(long long x) {
    long long a = x;
    long long e = mod - 2;
    long long res = 1;
    while (e > 0) {
        if (e & 1) {
            res = (res * a) % mod;
        }
        a = (a * a) % mod;
        e >>= 1;
    }
    return res % mod;
}

class eq {
public:
    long long x, y, z;

    eq(long long x, long long y, long long z) : x(x), y(y), z(z) {}

    string toString() const {
        return to_string(x) + " " + to_string(y) + " " + to_string(z);
    }
};

void seive() {
    vector<int> si(1000001, 0);
    vector<int> primes;
    int N = 1000001;
    si[1] = 1;
    for (int i = 2; i < N; i++) {
        if (si[i] == 0) {
            si[i] = i;
            primes.push_back(i);
        }
        for (int j = 0; j < primes.size() && primes[j] <= si[i] && (i * primes[j]) < N; j++)
            si[primes[j] * i] = primes[j];
    }
}

class Vector {
public:
    double x, y;

    Vector(double a, double b) : x(a), y(b) {}

    Vector(Point a, Point b) : x(b.x - a.x), y(b.y - a.y) {}

    Vector scale(double s) {
        return Vector(x * s, y * s);
    }

    double dot(Vector v) {
        return (x * v.x + y * v.y);
    }

    double cross(Vector v) {
        return x * v.y - y * v.x;
    }

    double norm2() {
        return x * x + y * y;
    }

    Vector reverse() {
        return Vector(-x, -y);
    }

    Vector normalize() {
        double d = sqrt(norm2());
        return scale(1 / d);
    }
};

class Line {
public:
    static const double INF;
    static const double EPS;

    double a, b, c;

    Line(Point p, Point q) {
        if (fabs(p.x - q.x) < EPS) {
            a = 1;
            b = 0;
            c = -p.x;
        } else {
            a = (p.y - q.y) / (q.x - p.x);
            b = 1.0;
            c = -(a * p.x + p.y);
        }
    }

    Line(Point p, double m) {
        a = -m;
        b = 1;
        c = -(a * p.x + p.y);
    }

    bool parallel(Line l) {
        return fabs(a - l.a) < EPS && fabs(b - l.b) < EPS;
    }

    bool same(Line l) {
        return parallel(l) && fabs(c - l.c) < EPS;
    }

    Point intersect(Line l) {
        if (parallel(l))
            return Point(0, 0); // or handle as needed
        double x = (b * l.c - c * l.b) / (a * l.b - b * l.a);
        double y;
        if (fabs(b) < EPS)
            y = -l.a * x - l.c;
        else
            y = -a * x - c;

        return Point(x, y);
    }

    Point closestPoint(Point p) {
        if (fabs(b) < EPS)
            return Point(-c, p.y);
        if (fabs(a) < EPS)
            return Point(p.x, -c);
        return intersect(Line(p, 1 / a));
    }
};

class Polygon {
public:
    static const double EPS;
    vector<Point> g;

    Polygon(vector<Point> o) : g(o) {}

    double perimeter() {
        double sum = 0.0;
        for (size_t i = 0; i < g.size() - 1; ++i)
            sum += g[i].dist(g[i + 1]);
        return sum;
    }

    double area() {
        double area = 0.0;
        for (size_t i = 0; i < g.size() - 1; ++i)
            area += g[i].x * g[i + 1].y - g[i].y * g[i + 1].x;
        return fabs(area) / 2.0;
    }

    bool id1() {
        if (g.size() <= 3)
            return false;
        bool ccw = Point::ccw(g[g.size() - 2], g[0], g[1]);

        for (size_t i = 1; i < g.size() - 1; ++i)
            if (Point::ccw(g[i - 1], g[i], g[i + 1]) != ccw)
                return false;
        return true;
    }

    bool inside(Point p) {
        double sum = 0.0;
        for (size_t i = 0; i < g.size() - 1; ++i) {
            double angle = Point::angle(g[i], p, g[i + 1]);
            if ((fabs(angle) < EPS || fabs(angle - M_PI) < EPS) && p.between(g[i], g[i + 1]))
                return true;
            if (Point::ccw(p, g[i], g[i + 1]))
                sum += angle;
            else
                sum -= angle;
        }

        return fabs(2 * M_PI - fabs(sum)) < EPS;
    }

    Polygon cutPolygon(Point a, Point b) {
        vector<Point> ans(g.size() * 2);
        Line l(a, b);
        Vector v(a, b);

        int size = 0;
        for (size_t i = 0; i < g.size(); ++i) {
            double left1 = v.cross(Vector(a, g[i]));
            double left2 = (i == g.size() - 1) ? 0 : v.cross(Vector(a, g[i + 1]));

            if (left1 + EPS > 0)
                ans[size++] = g[i];
            if (left1 * left2 + EPS < 0)
                ans[size++] = l.intersect(Line(g[i], g[i + 1]));
        }

        if (size != 0 && ans[0] != ans[size - 1])
            ans[size++] = ans[0];
        return Polygon(vector<Point>(ans.begin(), ans.begin() + size));
    }

    static Polygon id4(vector<Point> points) {
        int n = points.size();
        sort(points.begin(), points.end());
        vector<Point> ans(n * 2);
        int size = 0, start = 0;

        for (int i = 0; i < n; i++) {
            Point p = points[i];
            while (size - start >= 2 && !Point::ccw(ans[size - 2], ans[size - 1], p))
                --size;
            ans[size++] = p;
        }
        start = --size;

        for (int i = n - 1; i >= 0; i--) {
            Point p = points[i];
            while (size - start >= 2 && !Point::ccw(ans[size - 2], ans[size - 1], p))
                --size;
            ans[size++] = p;
        }

        return Polygon(vector<Point>(ans.begin(), ans.begin() + size));
    }

    Point centroid() {
        double cx = 0.0, cy = 0.0;
        for (size_t i = 0; i < g.size() - 1; i++) {
            double x1 = g[i].x, y1 = g[i].y;
            double x2 = g[i + 1].x, y2 = g[i + 1].y;

            double f = x1 * y2 - x2 * y1;
            cx += (x1 + x2) * f;
            cy += (y1 + y2) * f;
        }
        double area = area();

        cx /= 6.0 * area;
        cy /= 6.0 * area;
        return Point(cx, cy);
    }
};

class Point {
public:
    static const double EPS;

    double x, y;

    Point(double a, double b) : x(a), y(b) {}

    bool operator<(const Point& p) const {
        if (fabs(x - p.x) > EPS)
            return x < p.x;
        if (fabs(y - p.y) > EPS)
            return y < p.y;
        return false;
    }

    double dist(Point p) {
        return sqrt(sq(x - p.x) + sq(y - p.y));
    }

    static double sq(double x) {
        return x * x;
    }

    Point rotate(double angle) {
        double c = cos(angle), s = sin(angle);
        return Point(x * c - y * s, x * s + y * c);
    }

    Point rotate(double theta, Point p) {
        Vector v(p, Point(0, 0));
        return translate(v).rotate(theta).translate(v.reverse());
    }

    Point translate(Vector v) {
        return Point(x + v.x, y + v.y);
    }

    bool between(Point p, Point q) {
        return x < max(p.x, q.x) + EPS && x + EPS > min(p.x, q.x) && y < max(p.y, q.y) + EPS && y + EPS > min(p.y, q.y);
    }

    static bool ccw(Point p, Point q, Point r) {
        return Vector(p, q).cross(Vector(p, r)) > 0;
    }

    static double angle(Point a, Point o, Point b) {
        Vector oa = Vector(o, a), ob = Vector(o, b);
        return acos(oa.dot(ob) / sqrt(oa.norm2() * ob.norm2()));
    }
};

long long fac(int n) {
    if (n == 0)
        return 1;
    if (n == 1)
        return 1;
    long long ans = 1;
    for (int i = 1; i <= n; i++)
        ans = (i % mod * ans % mod) % mod;
    return ans % mod;
}

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

class pair {
public:
    int num;
    int v;

    pair(int n, int v) : num(n), v(v) {}

    bool operator<(const pair& other) const {
        return v < other.v;
    }

    string toString() const {
        return to_string(num) + " " + to_string(v);
    }
};

class unionfind {
public:
    vector<int> p;
    vector<int> size;

    unionfind(int n) : p(n), size(n, 1) {
        for (int i = 0; i < n; i++) {
            p[i] = i;
        }
    }

    int findSet(int v) {
        if (v == p[v])
            return v;
        return p[v] = findSet(p[v]);
    }

    bool sameSet(int a, int b) {
        return findSet(a) == findSet(b);
    }

    int max() {
        return *max_element(size.begin(), size.end());
    }

    void combine(int a, int b) {
        a = findSet(a);
        b = findSet(b);
        if (a == b)
            return;
        if (size[a] > size[b]) {
            p[b] = a;
            size[a] += size[b];
        } else {
            p[a] = b;
            size[b] += size[a];
        }
    }
};

class Scanner {
public:
    string line;
    istringstream iss;

    Scanner() {}

    void readLine() {
        getline(cin, line);
        iss.clear();
        iss.str(line);
    }

    string next() {
        string s;
        iss >> s;
        return s;
    }

    int nextInt() {
        int x;
        iss >> x;
        return x;
    }

    double nextDouble() {
        double x;
        iss >> x;
        return x;
    }

    char nextChar() {
        char c;
        iss >> c;
        return c;
    }

    long long nextLong() {
        long long x;
        iss >> x;
        return x;
    }

    bool ready() {
        return !iss.eof();
    }
};

int main() {
    Scanner sc;
    int t;
    cin >> t;
    while (t--) {
        int n, k, d;
        cin >> n >> k >> d;
        vector<int> a(n);
        unordered_map<int, int> hm;
        vector<int> occ(n + 1, 0);
        int id = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            if (hm.find(a[i]) == hm.end()) {
                hm[a[i]] = id++;
            }
        }
        for (int i = 0; i < n; i++)
            a[i] = hm[a[i]];
        int ans = 0;
        for (int i = 0; i < d; i++) {
            occ[a[i]]++;
            if (occ[a[i]] == 1)
                ans++;
        }
        int ansl = ans;
        for (int i = d; i < n; i++) {
            int ans1 = ansl;
            occ[a[i]]++;
            if (occ[a[i]] == 1)
                ans1++;
            occ[a[i - d]]--;
            if (occ[a[i - d]] == 0)
                ans1--;
            ans = min(ans, ans1);
            ansl = ans1;
        }
        cout << ans << endl;
    }
    return 0;
}
