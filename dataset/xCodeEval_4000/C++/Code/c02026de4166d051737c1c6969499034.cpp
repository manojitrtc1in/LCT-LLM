#include <bits/stdc++.h>

#define f first
#define s second
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define ll long long
#define db double
#define ld long double
#define pii pair<int, int>
#define pll pair<ll, ll>
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define input(a) for (auto& el : a) cin >> el;
#define output(a) cout << '!'; for (auto& el : a) cout << el << ' '; cout << '\n'; cout.flush();
#define sz(el) int(el.size())
#define sq(a) ((a) * (a))
#define re(c) int(c - 'a')
  

#define forn(i,n) for (int i = 0; i < n; ++i)
#define rforn(i,n) for (int i = n - 1; i >= 0; --i)
#define bn '\n'
#define vi vector<int>
#define vii vector<vi>
#define vl vector<ll>
#define vll vector<vl>
#define G vector<vector<pii>>
#define GVE vector<vector<edge>>
#define usi unordered_set<int>
#define usp set<pii>


using namespace std;

const int INF = 1'000'000'017;
const ll LLINF = 1'000'000'000'000'000'017LL;
const ld inf = 1.0 / 0.0;
const ld eps = 1e-9;
const int MOD = 1'000'000'007;




namespace geometry {
    const ld PI = atan2(0, -1);
    const ld EPS = 1e-18;

    struct Point {
        ld x, y;

        Point() {}

        Point(ld x, ld y) : x(x), y(y) {}

        bool operator==(Point a) {
            return abs(x - a.x) < EPS && abs(y - a.y) < EPS;
        }

        bool operator!=(Point a) {
            return (x - a.x) > EPS || (y - a.y) > EPS;
        }

        bool operator<(Point a) {
            return x < a.x || (x == a.x && y < a.y);
        }

        bool operator>(Point a) {
            return x > a.x || (x == a.x && y > a.y);
        }

        Point operator+(Point a) {
            return {x + a.x, y + a.y};
        }

        Point operator-(Point a) {
            return {x - a.x, y - a.y};
        }

        Point operator*(ld a) {
            return {x * a, y * a};
        }

        Point operator/(ld a) {
            return {x / a, y / a};
        }
    };

    struct Vector {
        ld x, y;

        Vector() {}

        Vector(ld x, ld y) : x(x), y(y) {}

        Vector(Point a) : x(a.x), y(a.y) {}

        Vector(Point a, Point b) : x(b.x - a.x), y(b.y - a.y) {}

        Vector operator-() {
            return {-x, -y};
        }

        Vector operator+(Vector a) {
            return {x + a.x, y + a.y};
        }

        void operator+=(Vector a) {
            x += a.x;
            y += a.y;
        }

        Vector operator-(Vector a) {
            return {x - a.x, y - a.y};
        }

        void operator-=(Vector a) {
            x -= a.x;
            y -= a.y;
        }

        ld operator*(Vector a) {
            return a.x * x + a.y * y;
        }

        ld operator%(Vector a) {
            return a.y * x - a.x * y;
        }

        Vector operator*(ld r) {
            return {x * r, y * r};
        }

        void operator*=(ld r) {
            x *= r;
            y *= r;
        }

        Vector operator/(ld r) {
            return {x / r, y / r};
        }

        void operator/=(ld r) {
            x /= r;
            y /= r;
        }

        ld len() {
            return sqrt(x * x + y * y);
        }
    };

    struct Line {
        ld a, b, c;

        Line() {}

        Line(ld a, ld b, ld c) : a(a), b(b), c(c) {}

        Line(Point a, Point b) : a(b.y - a.y), b(a.x - b.x), c(a.y * b.x - a.x * b.y) {}

        Line(Point p, Vector v) : a(v.y), b(-v.x), c(p.y * v.x - p.x * v.y) {}

        bool operator==(Line x) {
            return (abs(a * x.b - b * x.a) < EPS && abs(a * x.c - c * x.a) < EPS);
        }
    };

    struct Circle {
        Point c;
        ld r;

        Circle() {}

        Circle(Point c, ld r) : c(c), r(r) {}
    };

    ld angle(Vector v, Vector u) {
        return abs(atan2(v % u, v * u));
    }

    ld angleOrient(Vector v, Vector u) {
        return atan2(v % u, v * u);
    }

    ld ptLine(Point a, Line line) {
        return line.a * a.x + line.b * a.y + line.c;
    }

    ld dist(Point a, Point b) {
        return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
    }

    ld dist(Point a, Line line) {
        return abs(ptLine(a, line)) / sqrt(line.a * line.a + line.b * line.b);
    }

    ld ordist(Point a, Line line) {
        return ptLine(a, line) / sqrt(line.a * line.a + line.b * line.b);
    }

    ld dist(Point p, Point a, Point b, bool p1, bool p2) {
        if (p1 && Vector(a, p) * Vector(a, b) < 0) {
            return dist(p, a);
        }
        if (p2 && Vector(b, p) * Vector(b, a) < 0) {
            return dist(p, b);
        }
        return dist(p, Line(a, b));
    }

    int part(Point a) {
        if (a.x >= 0) {
            return (a.y >= 0 ? 1 : 4);
        }
        else {
            return (a.y >= 0 ? 2 : 3);
        }
    }

    int prt(Point& a, Point& c) {  

        if (a.x >= c.x) {
            return (a.y >= c.y ? 1 : 2);
        }
        else {
            return (a.y > c.y ? 1 : 2);
        }
    }

    void norm(Vector& a, ld r) {  

        ld d = sqrt(a.x * a.x + a.y * a.y);
        a.x /= d;
        a.y /= d;
        a.x *= r;
        a.y *= r;
    }

    bool intersect(Line a, Line b, Point& p) {
        if (a.a * b.b - b.a * a.b == 0) {
            return 0;
        }
        p = Point((b.c * a.b - a.c * b.b) / (a.a * b.b - b.a * a.b), (a.a * b.c - b.a * a.c) / (b.a * a.b - a.a * b.b));
        return 1;
    }

    Line angle90(Line a, Point b) {
        return Line(b, Point(b.x + a.a, b.y + a.b));
    }

    bool sign_check(ld a, ld b) {  

        return (a >= 0 && b >= 0) || (a <= 0 && b <= 0);
    }

    bool between(Point& a, Point& b, Point& c) {
        return min(a.x, c.x) <= b.x && b.x <= max(a.x, c.x) && min(a.y, c.y) <= b.y && b.y <= max(a.y, c.y);
    }

    bool intersect(Point a, Point b, Point c, Point d) {
        Vector v1(a, b), v2(c, d), u1(a, c), u2(a, d), u3(c, a), u4(c, b);
        if (sign_check((v1 % u1), (v1 % u2)) && sign_check((v2 % u3), (v2 % u4))) {
            if (ptLine(c, Line(a, b)) == 0 && ptLine(d, Line(a, b)) == 0 && !between(a, c, b) && !between(a, d, b) && !between(c, a, d) && !between(c, b, d)) {
                return 0;
            }
            else {
                return 1;
            }
        }
        else {
            return 0;
        }
    }

    bool dot_circle_seg(Point a, Point c, Point b, Point p) {  

        Vector ca(c, a), ap(a, p), ab(a, b), ba(b, a), cb(c, b), bp(b, p), cp(c, p), pc(p, c), pa(p, a), pb(p, b);
        return (cp % ca == 0 && pc * pa < 0) || (cp % cb == 0 && pc * pb < 0) || c == p || a == p || b == p ||
        (sign_check((ca % ap), (ca % ab)) && sign_check((cb % bp), (cb % ba)) && !sign_check((ca % ap), (cb % bp)));
    }

    int into(vector<Point>& pts, Point a, int n) {  

        if (!dot_circle_seg(pts[1], pts[0], pts[n - 1], a)) {
            return 0;
        }
        int left = 1, right = n - 1;
        while (left < right - 1) {
            int mid = (left + right) / 2;
            if (dot_circle_seg(pts[left], pts[0], pts[mid], a)) {
                right = mid;
            }
            else {
                left = mid;
            }
        }
        return dot_circle_seg(pts[left], pts[0], pts[right], a) && dot_circle_seg(pts[0], pts[left], pts[right], a);
    }

    Point operator+(Point a, Vector v) {
        return {a.x + v.x, a.y + v.y};
    }

    Point operator-(Point a, Vector v) {
        return {a.x - v.x, a.y - v.y};
    }

    int intersect(Circle c, Line s, vector<Point>& pts) {
        ld d = dist(c.c, s);
        Vector v(s.a, s.b);
        norm(v, d);
        Point p1 = c.c + v, p2 = c.c - v;
        if (d > c.r) {
            return 0;
        }
        else if (abs(d - c.r) < EPS) {
            if (abs(ptLine(p1, s)) < EPS) {
                pts.emplace_back(p1);
            }
            else {
                pts.emplace_back(p2);
            }
            return 1;
        }
        else {
            if (abs(ptLine(p2, s)) < EPS) {
                p1 = p2;
            }
            Vector u(-s.b, s.a);
            ld q = sqrt(c.r * c.r - d * d);
            norm(u, q);
            Point p3 = p1 + u, p4 = p1 - u;
            pts.emplace_back(p3);
            pts.emplace_back(p4);
            return 2;
        }
    }

    int intersect(Circle c1, Circle c2, vector<Point>& pts) {
        if (c1.r > c2.r) {
            swap(c1, c2);
        }
        if (c1.c == c2.c && c1.r == c2.r) {
            return 3;
        }
        else if (c1.r < c2.r - dist(c1.c, c2.c)) {
            return 0;
        }
        else {
            Line s(2 * (c2.c.x - c1.c.x), 2 * (c2.c.y - c1.c.y),
                   c1.c.x * c1.c.x + c1.c.y * c1.c.y - c2.c.x * c2.c.x - c2.c.y * c2.c.y - c1.r * c1.r + c2.r * c2.r);
            return intersect(c1, s, pts);
        }
    }

    int tangent(Circle c, Point p, vector<Point>& pts) {
        ld d = dist(c.c, p);
        if (d * d - c.r * c.r < 0) {
            return 0;
        }
        Circle tmp(p, sqrt(d * d - c.r * c.r));
        return intersect(c, tmp, pts);
    }

    vector<Point> convexHull(vector<Point> p) {  

        Point opt = *min_element(all(p));
        sort(all(p), [&opt](const Point& a, const Point& b) {
            int t = Vector(opt, a) % Vector(opt, b);
            return (t == 0 ? dist(opt, a) < dist(opt, b) : t > 0);
        });
        p.resize(unique(all(p)) - p.begin());
        vector<Point> ans;
        for (auto& el : p) {
            while (sz(ans) > 1 && Vector(ans[sz(ans) - 2], ans.back()) % Vector(ans.back(), el) <= 0) {
                ans.pop_back();
            }
            ans.eb(el);
        }
        return ans;
    }

    ld per(vector<Point> p) {
        p.eb(p[0]);
        ld ans = 0;
        for (int i = 0; i < sz(p) - 1; ++i) {
            ans += dist(p[i], p[i + 1]);
        }
        return ans;
    }

    ld sup(vector<Point> p) {
        p.eb(p[0]);
        ld ans = 0;
        Point opt(0, 0);
        for (int i = 0; i < sz(p) - 1; ++i) {
            ans += Vector(opt, p[i]) % Vector(opt, p[i + 1]);
        }
        return ans / 2;
    }

    istream& operator>>(istream& in, Point& a) {
        return (in >> a.x >> a.y);
    }

    ostream& operator<<(ostream& out, Point& a) {
        return (out << a.x << ' ' << a.y << '\n');
    }

    istream& operator>>(istream& in, Vector& a) {
        return (in >> a.x >> a.y);
    }

    ostream& operator<<(ostream& out, Vector& a) {
        return (out << a.x << ' ' << a.y << '\n');
    }

    istream& operator>>(istream& in, Line& a) {
        return (in >> a.a >> a.b >> a.c);
    }

    ostream& operator<<(ostream& out, Line& a) {
        return (out << a.a << ' ' << a.b << ' ' << a.c << '\n');
    }

    istream& operator>>(istream& in, Circle& a) {
        return (in >> a.c >> a.r);
    }

    ostream& operator<<(ostream& out, Circle& a) {
        return (out << a.c << a.r << '\n');
    }
}

using namespace geometry;

const int N = 4000;
int n;

Point pts[N];
int pos[N];

void fnd(Point& x, Point& y, ld need) {
    Line l(x, y);
    
    int left = 0, right = n;
    while (left < right - 1) {
        int mid = left + right >> 1;
        if (ordist(pts[mid], l) <= need + EPS) {
            left = mid;
        }
        else {
            right = mid;
        }
    }
    if (ordist(pts[left], l) >= need - EPS && ordist(pts[left], l) <= need + EPS) {
        cout << "Yes\n";
        cout << x << y << pts[left];
        exit(0);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << setprecision(0) << fixed;

    ll s;
    cin >> n >> s;
    s <<= 1;
    for (int i = 0; i < n; ++i) {
        cin >> pts[i];
    }
    sort(pts, pts + n);
    iota(pos, pos + n, 0);
    vector<pii> q;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            q.eb(i, j);
        }
    }
    sort(all(q), [](pii& a, pii& b) {
        return Vector(pts[a.f], pts[a.s]) % Vector(pts[b.f], pts[b.s]) > 0;
    });
    for (pii& el : q) {
        swap(pts[pos[el.f]], pts[pos[el.s]]);
        swap(pos[el.f], pos[el.s]);
        fnd(pts[pos[el.s]], pts[pos[el.f]], s / dist(pts[pos[el.f]], pts[pos[el.s]]));
        fnd(pts[pos[el.s]], pts[pos[el.f]], -s / dist(pts[pos[el.f]], pts[pos[el.s]]));
    }
    cout << "No";
    return 0;
}
