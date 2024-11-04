#include <bits/stdc++.h>
#include "chrono"

using namespace std;

#define ALL(x) x.begin(), x.end()
#define bits(x) __builtin_popcount(x)
#define bitsll(x) __builtin_popcountll(x)
#define precision(a) fixed << setprecision(a)

typedef long long ll;
typedef long double ld;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef pair < int, int > pii;
typedef vector < int > vi;

template < class T >
inline T sqr(T x) {
    return x * x;
}

template < class T >
inline bool isSquare(T x) {
    T y = sqrt(x + 0.5);
    return (y * y) == x;
}

template < class T1, class T2 >
inline T1 gcd(T1 a, T2 b) {
    return b ? gcd(b, a % b) : a;
}

template < class T1, class T2 >
inline T1 eqMin(T1 &x, const T2 &y) {
    if (T1(y) < x)
        return x = y;
    return x;
}

template < class T1, class T2 >
inline T1 eqMax(T1 &x, const T2 &y) {
    if (T1(y) > x)
        return x = y;
    return x;
}

template < class T1, class T2 >
inline T1 min(const T1 &x, const T2 &y) {
    return x < (T1) y ? x : (T1) y;
}

template < class T1, class T2 >
inline T1 max(T1 &x, const T2 &y) {
    return x > (T1) y ? x : (T1) y;
}

template < typename T >
inline T getint() {
    T x = 0, p = 1;
    char ch;
    do {
        ch = getchar();
    } while (ch <= ' ');
    if (ch == '-')
        p = -1, ch = getchar();
    while (ch >= '0' && ch <= '9')
        x = x * 10 + ch - '0', ch = getchar();
    return x * p;
}

struct _flag_t {
    string val;
}
const _1d{", "}, _2d{"\n  "};
_flag_t _flag = _1d;

ostream &operator<<(ostream &os, _flag_t flag) {
    _flag = flag;
    return os;
}

template < class CharT, class Traits, class It >
basic_ostream < CharT, Traits > &
_out(basic_ostream < CharT, Traits > &os, It f, It l) {
    if (f == l) return os << "{}";
    _flag_t cur_flag = _flag;
    os << _1d << "{ " << *f;
    for (; ++f != l; os << cur_flag.val << *f);
    return os << " }\n";
}

template < class CharT, class Traits, class C >
auto operator<<(basic_ostream < CharT, Traits > &os, C const &cont)
-> decltype(begin(cont), end(cont), cont.size(), os) { return _out(os, begin(cont), end(cont)); }

template < class X, class Y >
ostream &operator<<(ostream &os, pair < X, Y > const &p) { return os << "[" << p.first << ", " << p.second << "]"; }

template < class X, class Y, class Z >
ostream &operator<<(ostream &os, tuple < X, Y, Z > const &p) {
    return os << "[" << get < 0 >(p) << ", " << get < 1 >(p) << ", " << get < 2 >(p) << "]";
}

const double PI = acos(-1);
const ld epsilon = 1E-9;
const double EPS = 1e-8;
const int INF = (int) 2e9;
const int MOD = (int) 1e9 + 7;
const int MAXN = (int) 30;
using ld = long double;


struct Segment;

pair < int, int > solve(const vector < Segment > &a);

ld det2(ld a, ld b, ld c, ld d) { return a * d - b * c; }

ld det3(ld a, ld b, ld c, ld d, ld e, ld f, ld g, ld h, ld j) {
    return a * e * j + g * b * f + c * d * h - c * e * g - a * h * f - j * b * d;
}

struct Point {
    ld x, y, z;

    Point(ld x = 0, ld y = 0, ld z = 0) : x(x), y(y), z(z) {}

    Point operator-(const Point &rhs) const {
        return {x - rhs.x, y - rhs.y, z - rhs.z};
    }

    Point operator*(const Point &rhs) const {
        return {y * rhs.z - rhs.y * z, rhs.x * z - x * rhs.z, x * rhs.y - rhs.x * y};
    }

    ld operator%(const Point &rhs) const {
        return x * rhs.x + y * rhs.y + z * rhs.z;
    }
};

ostream &operator<<(ostream &os, Point const &p) {
    return os << "(" << p.x << "; " << p.y << "; " << p.z << ")\n";
}

struct Line2D {
    ld a, b, c;

    Line2D(ld a = 0, ld b = 0, ld c = 0) :
            a(a), b(b), c(c) {}

    Line2D(const Point &p, const Point &q) : a(q.y - p.y), b(p.x - q.x), c(q.x * p.y - q.y * p.x) {}
};

ostream &operator<<(ostream &os, Line2D const &p) {
    return os << p.a << "x + " << p.b << "y + " << p.c << " = 0 \n";
}

struct Line3D {
    ld x, a, y, b, z, c;

    Line3D(ld x = 0, ld a = 0, ld y = 0, ld b = 0, ld z = 0, ld c = 0) :
            x(x), a(a), y(y), b(b), z(z), c(c) {}

    Line3D(const Point &_1, const Point &_0) :
            x(_1.x), a(_0.x - _1.x),
            y(_1.y), b(_0.y - _1.y),
            z(_1.z), c(_0.z - _1.z) {}
};

ostream &operator<<(ostream &os, Line3D const &p) {
    return os << " / x - " << p.x << " = " << p.a << " * alpha \n"
              << "<  y - " << p.y << " = " << p.b << " * alpha \n"
              << " \\ z - " << p.z << " = " << p.c << " * alpha \n";
}

struct Plane {
    ld a, b, c, d;

    Plane(ld a = 0, ld b = 0, ld c = 0, ld d = 0) :
            a(a), b(b), c(c), d(d) {}

    Plane(const Point &_0, const Point &_1, const Point &_2) {
        ld x10 = _1.x - _0.x, x20 = _2.x - _0.x;
        ld y10 = _1.y - _0.y, y20 = _2.y - _0.y;
        ld z10 = _1.z - _0.z, z20 = _2.z - _0.z;
        a = det2(y10, z10, y20, z20);
        b = det2(z10, z20, x10, x20);
        c = det2(x10, x20, y10, y20);
        d = -_0.x * a - _0.y * b - _0.z * c;
    }
};

ostream &operator<<(ostream &os, Plane const &p) {
    return os << p.a << "x + " << p.b << "y + " << p.c << "z + " << p.d << " = 0 \n";
}

struct Segment {
    Point p, q;
    int id;

    Segment(Point p = {0, 0, 0}, Point q = {0, 0, 0}, int id = 0) : p(p), q(q), id(id) {}

    ld get_y(double x) const {
        if (abs(p.x - q.x) < epsilon) return p.y;
        return p.y + (q.y - p.y) * (x - p.x) / (q.x - p.x);
    }

    bool intersect(Segment a, Point &ans) {
        id = 0;
        a.id = 1;
        if (solve({{p, q, id}, a}) == pii{-1, -1}) {
            return false;
        } else {
            auto[A, B, C] = Line2D(p, q);
            auto[D, E, F] = Line2D(a.p, a.q);
            if (A * E == B * D && A * F == D * C && B * F == E * C) {
                ans = {max(min(p.x, q.x), min(a.p.x, a.q.x)), max(min(p.y, q.y), min(a.p.y, a.q.y))};
            } else ans = {(B * F - C * E) / (E * A - B * D), (A * F - D * C) / (D * B - A * E)};
            return true;
        }
    }
};

struct Rectangle {
    Point l, r;

    Rectangle(Point l, Point r) :
            l(l), r(r) {}
};

ostream &operator<<(ostream &os, Rectangle const &p) {
    return os << p.l.x << " " << p.l.y << "  " << p.r.x << " " << p.r.y << "\n";
}



bool find_intersect2D(Line2D _1, Line2D _2, Point ans) {
    ld zn = _2.b * _1.a - _1.b * _2.a;
    if (_1.a * _2.b == _2.a * _1.b && _1.a * _2.c == _2.a * _1.c) {
        if (_1.a == 0) return ans = {0, -_1.c / _1.b}, true;
        else return ans = {-_1.c / _1.a, 0}, true;
    }
    if (zn == 0)return false;
    return ans = {(_2.c * _1.b - _1.c * _2.b) / zn, (_1.a * _2.c - _2.a * _1.c) / (-zn)}, false;
}

bool find_intersect3D(Plane _1, Plane _2, Line3D &ans) {
    ld a1 = _1.a, b1 = _1.b, c1 = _1.c, d1 = _1.d;
    ld a2 = _2.a, b2 = _2.b, c2 = _2.c, d2 = _2.d;
    if (a1 * b2 == a2 * b1 && a1 * c2 == c1 * a2 && a1 * d2 == a2 * d1 &&
        b1 * c2 == c1 * b2 && b1 * d2 == b2 * d1 && c1 * d2 == c2 * d1) {
        if (a1 == 0 && a2 == 0 && b1 == 0 && b2 == 0)
            return ans = {0, 1,
                          0, 0,
                          -d1 / c1, 0}, true;
        else {
            return ans = {0, b1,
                          -d1 / a1 / b1, -a1,
                          0, 0}, true;
        }
    }
    if (a1 * b2 == a2 * b1 && a1 * c2 == c1 * a2 && b1 * c2 == c1 * b2)
        return false;
    ld z, x, y;
    if (a1 * b2 == a2 * b1) {
        x = 0;
        Line2D line1 = {b1, c1, d1}, line2 = {b2, c2, d2};
        Point q;
        find_intersect2D(line1, line2, q);
        y = q.x;
        z = q.y;
    } else if (c1 * b2 == c2 * b1) {
        y = 0;
        Line2D line1 = {a1, c1, d1}, line2 = {a2, c2, d2};
        Point q;
        find_intersect2D(line1, line2, q);
        x = q.x;
        z = q.y;
    } else {
        z = 0;
        Line2D line1 = {a1, b1, d1}, line2 = {a2, b2, d2};
        Point q;
        find_intersect2D(line1, line2, q);
        x = q.x;
        y = q.y;
    }
    Point p1 = {a1, b1, c1}, p2 = {a2, b2, c2};
    auto[a, b, c] = p1 * p2;
    return ans = {x, a, y, b, z, c}, true;
}

bool if_intersect(Line3D line, Plane plane) {
    auto[q, x, w, y, e, z] = line;
    auto[a, b, c, d] = plane;
    if (x * a + y * b + z * c != 0)
        return true;
    else
        return a * q + b * w + c * e + d == 0;
}

bool find_intersect3D(Line3D line, Plane plane, Point &ans) {
    if (!if_intersect(line, plane))return false;
    auto[x0, a0, y0, b0, z0, c0] = line;
    auto[a1, b1, c1, d1] = plane;
    Point abc0 = {a0, b0, c0}, abc1 = {a1, b1, c1}, xyz0 = {x0, y0, z0};
    ld alpha = -(d1 + abc1 % xyz0) / (abc0 % abc1);
    return ans = {a0 * alpha + x0, b0 * alpha + y0, c0 * alpha + z0}, true;
}

ld dist_2_lines3D(Line3D line1, Line3D line2) {
    auto[x1, l1, y1, m1, z1, n1] = line1;
    auto[x2, l2, y2, m2, z2, n2] = line2;
    Point vect = {l1, m1, n1};
    if (l1 * n2 == l2 * n1 && l1 * m2 == l2 * m1 && n1 * m2 == n2 * m1) {
        ld mat1 = det2(x2 - x1, y2 - y2, l1, m1), mat2 = det2(y2 - y1, z2 - z1, m1, n1),
                mat3 = det2(z2 - z1, x2 - x1, n1, l1);
        return sqrt(mat1 * mat1 + mat2 * mat2 + mat3 * mat3) / sqrt(vect % vect);
    } else {
        ld chislit = det3(x2 - x1, y2 - y1, z2 - z1, l1, m1, n1, l2, m2, n2);
        ld mat1 = det2(l1, l2, m1, m2), mat2 = det2(m1, m2, n1, n2), mat3 = det2(n1, n2, l1, l2);
        return chislit / sqrt(mat1 * mat1 + mat2 * mat2 + mat3 * mat3);
    }
}



bool intersect1d(double l1, double r1, double l2, double r2) {
    if (l1 > r1) swap(l1, r1);
    if (l2 > r2) swap(l2, r2);
    return max(l1, l2) <= min(r1, r2) + epsilon;
}

int vec(const Point &a, const Point &b, const Point &c) {
    ld s = (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
    return abs(s) < epsilon ? 0 : s > 0 ? +1 : -1;
}

bool intersect(const Segment &a, const Segment &b) {
    return intersect1d(a.p.x, a.q.x, b.p.x, b.q.x)
           && intersect1d(a.p.y, a.q.y, b.p.y, b.q.y)
           && vec(a.p, a.q, b.p) * vec(a.p, a.q, b.q) <= 0
           && vec(b.p, b.q, a.p) * vec(b.p, b.q, a.q) <= 0;
}

bool operator<(const Segment &a, const Segment &b) {
    ld x = max(min(a.p.x, a.q.x), min(b.p.x, b.q.x));
    return a.get_y(x) < b.get_y(x) - epsilon;
}

struct event {
    ld x;
    int tp, id;

    event() {}

    event(ld x, int tp, int id)
            : x(x), tp(tp), id(id) {}

    bool operator<(const event &e) const {
        if (abs(x - e.x) > epsilon) return x < e.x;
        return tp > e.tp;
    }
};

set < Segment > s;
vector < set < Segment >::iterator > where;

inline set < Segment >::iterator prev(set < Segment >::iterator it) {
    return it == s.begin() ? s.end() : --it;
}

inline set < Segment >::iterator next(set < Segment >::iterator it) {
    return ++it;
}

pair < int, int > solve(const vector < Segment > &a) {
    int n = (int) a.size();
    vector < event > e;
    for (int i = 0; i < n; ++i) {
        e.push_back(event(min(a[i].p.x, a[i].q.x), +1, i));
        e.push_back(event(max(a[i].p.x, a[i].q.x), -1, i));
    }
    sort(e.begin(), e.end());
    s.clear();
    where.resize(a.size());
    for (size_t i = 0; i < e.size(); ++i) {
        int id = e[i].id;
        if (e[i].tp == +1) {
            set < Segment >::iterator
                    nxt = s.lower_bound(a[id]),
                    prv = prev(nxt);
            if (nxt != s.end() && intersect(*nxt, a[id]))
                return make_pair(nxt->id, id);
            if (prv != s.end() && intersect(*prv, a[id]))
                return make_pair(prv->id, id);
            where[id] = s.insert(nxt, a[id]);
        } else {
            set < Segment >::iterator
                    nxt = next(where[id]),
                    prv = prev(where[id]);
            if (nxt != s.end() && prv != s.end() && intersect(*nxt, *prv))
                return make_pair(prv->id, nxt->id);
            s.erase(where[id]);
        }
    }
    return make_pair(-1, -1);
}




int32_t main() {
    ios_base::sync_with_stdio(false);
    multiset < pair < int, char > > x, y;
    vector < Rectangle > rect;
    int n;
    cin >> n;
    for (int q = 0; q < n; q++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        x.insert({a, 'l'});
        x.insert({c, 'r'});
        y.insert({b, 'l'});
        y.insert({d, 'r'});
        rect.push_back({(Point) {a, b}, (Point) {c, d}});
    }
    auto it_x = x.begin();
    int count = 0;
    bool wasx = false;
    while (count != n - 1) {
        if (it_x->second == 'l')count++;
        if (it_x->second == 'r') {
            count--;
            wasx = true;
        }
        it_x++;
    }
    it_x--;
    while (++it_x != x.end() && (it_x)->second == 'l');

    auto it_y = y.begin();

    bool wasy = false;
    count = 0;
    while (count != n - 1) {
        if (it_y->second == 'l')count++;
        if (it_y->second == 'r') {
            count--;
            wasy = true;
        }
        it_y++;
    }
    it_y--;
    while (++it_y != y.end() && (it_y)->second == 'l');
    int ax = it_x->first, ay = it_y->first;
    int count_all = 0;
    for (int q = 0; q < n; q++) {
        if (ax <= int(rect[q].r.x) && ax >= int(rect[q].l.x) &&
            ay >= int(rect[q].l.y) && ay <= int(rect[q].r.y))
            count_all++;
    }
    if (count_all >= n - 1)return cout << it_x->first << " " << it_y->first, 0;
    if (!wasx)while (++it_x != x.end() && (it_x)->second == 'l');
    if (!wasy)while (++it_y != y.end() && (it_y)->second == 'l');
    int bx = ax, by = it_y->first;
    count_all = 0;
    for (int q = 0; q < n; q++) {
        if (bx <= int(rect[q].r.x) && bx >= int(rect[q].l.x) &&
            by >= int(rect[q].l.y) && by <= int(rect[q].r.y))
            count_all++;
    }
    if (count_all >= n - 1)return cout << bx << " " << by, 0;
    count_all = 0;
    bx = it_x->first;
    by = ay;
    for (int q = 0; q < n; q++) {
        if (bx <= int(rect[q].r.x) && bx >= int(rect[q].l.x) &&
            by >= int(rect[q].l.y) && by <= int(rect[q].r.y))
            count_all++;
    }
    if (count_all >= n - 1)return cout << bx << " " << by, 0;

    cout << it_x->first << " " << it_y->first;


}
