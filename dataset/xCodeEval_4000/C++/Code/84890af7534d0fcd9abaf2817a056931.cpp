#include<bits/stdc++.h>
#define ALL(X)        X.begin(),X.end()
#define FOR(I,A,B)    for(int (I) = (A); (I) <= (B); (I)++)
#define FORW(I,A,B)   for(int (I) = (A); (I) < (B);  (I)++)
#define FORD(I,A,B)   for(int (I) = (A); (I) >= (B); (I)--)
#define CLEAR(X)      memset(X,0,sizeof(X))
#define SIZE(X)       int(X.size())
#define CONTAINS(A,X) (A.find(X) != A.end())
#define PB            push_back
#define MP            make_pair
#define X             first
#define Y             second
#ifdef LOCAL
    #define D(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
#else
    #define D(...) ;
    #define cerr if(0)cout
#endif
using namespace std;
template<typename T, typename U> ostream& operator << (ostream& os, const pair<T, U> &_p) { return os << "(" << _p.X << "," << _p.Y << ")"; }
template<typename T> ostream& operator << (ostream &os, const vector<T>& _V) { bool f = true; os << "["; for(auto v: _V) { os << (f ? "" : ",") << v; f = false; } return os << "]"; }
template<typename T> ostream& operator << (ostream &os, const set<T>& _S) { bool f = true; os << "("; for(auto s: _S) { os << (f ? "" : ",") << s; f = false; } return os << ")"; }
template<typename T, typename U> ostream& operator << (ostream &os, const map<T, U>& _M) { return os << set<pair<T, U>>(ALL(_M)); }
template<class TH> void _dbg(const char *sdbg, TH h){ cerr<<sdbg<<'='<<h<<endl; }template<class TH, class... TA> void _dbg(const char *sdbg, TH h, TA... a) { while(*sdbg!=',')cerr<<*sdbg++;cerr<<'='<<h<<", "; _dbg(sdbg+1, a...); }

typedef signed long long slong;
typedef long double ldouble;
const slong INF = 1000000100;
const ldouble EPS = 1e-10;

const ldouble PI = asinl(1.0) * 2;
typedef pair<ldouble,ldouble> point;
typedef pair<point, point> segment;
inline bool is_zero(const ldouble &x) { return -EPS <= x and x <= EPS; }
inline point operator + (const point &a, const point &b) { return point(a.X + b.X, a.Y + b.Y); }
inline point operator - (const point &a, const point &b) { return point(a.X - b.X, a.Y - b.Y); }
inline point operator * (const point &a, ldouble t) { return point(a.X * t, a.Y * t); }
inline point operator / (const point &a, ldouble t) { return point(a.X / t, a.Y / t);  }

inline ldouble cp(const point &a, const point &b) {
    return a.X * b.Y - a.Y * b.X;
}

inline ldouble dp(const point &a, const point &b) {
    return a.X * b.X + a.Y * b.Y;
}

inline ldouble distance(const point &a, const point &b) {
    return sqrtl((b.X - a.X) * (b.X - a.X) + (b.Y - a.Y) * (b.Y - a.Y));
}

inline bool on_right(const point &a, const point &b, const point &c) {
    return cp(c - a, b - a) > EPS;
}

double polygon_area(const vector<point> &A) {
    ldouble result = 0.0;
    if(SIZE(A) <= 2) return 0;
    FORW(i,2,SIZE(A)) result += cp(A[i] - A[0], A[i-1] - A[0]);
    return abs(result / 2);
}

point projection(const point &p, const segment &u) {
    return u.X + (u.Y - u.X) * (dp(p - u.X, u.Y - u.X) / dp(u.Y - u.X, u.Y - u.X));
}

inline bool between(const point &a, const point &b, const point &c) {
    return min(b.X,c.X) - a.X < EPS and a.X - max(b.X,c.X) < EPS
        and min(b.Y,c.Y) - a.Y < EPS and a.Y - max(b.Y,c.Y) < EPS;
}

inline bool on_segment(const point &p, const segment &u) {
    return between(p, u.X, u.Y) and is_zero(cp(u.X - p, u.Y - p));
}

inline ldouble distance_point_line(const point &p, const segment &u) {
    return abs(cp(p - u.X, p - u.Y) / distance(u.X, u.Y));
}

inline ldouble distance_point_segment(const point &p, const segment &u) {
    if(on_segment(projection(p, u), u)) return abs(distance_point_line(p, u));
    else return min(distance(u.X, p), distance(u.Y, p));
}

inline ldouble angle(const point &a, const point &o, const point &b) {
    ldouble result = atan2l((b - o).Y, (b - o).X) - atan2l((a - o).Y, (a - o).X);
    if(result < 0) result += 2 * PI;
    return result;
}

inline point point_reflection(const point &p, const point &s) {
    return p + (s - p) * 2;
}

inline point axial_reflection(const point &p, const segment &u) {
    return point_reflection(p, projection(p, u));
}


vector<point> convex_hull(vector<point> A) {
    vector<point> R;
    sort(ALL(A));
    R.push_back(A[0]);
    FOR(_,0,1) {
        int t = SIZE(R);
        FORW(i,1,SIZE(A)) {
            while(SIZE(R) > t and !on_right(A[i], R.back(), R.rbegin()[1])) R.pop_back();
            R.push_back(A[i]);
        }
        reverse(ALL(A));
    }
    if(SIZE(R) > 1) R.pop_back();
    return move(R);
}

inline point rotate90_origin(const point &p) {
    return point(p.Y, -p.X);
}

inline point rotate90(const point &p, const point &o) {
    return o + rotate90_origin(p - o);
}

inline point rotate_origin(const point &p, ldouble theta) {
    theta = -theta;
    ldouble s = sinl(theta);
    ldouble c = cosl(theta);
    return point(p.X * c - p.Y * s, p.X * s + p.Y * c);
}

inline point rotate(const point &p, const point &o, ldouble theta) {
    return o + rotate_origin(p - o, theta);
}

bool parallel(const segment &u, const segment &v) {
    return is_zero(cp(u.Y - u.X, v.Y - v.X));
}

bool perpendicular(const segment &u, const segment &v) {
    return is_zero(dp(u.Y - u.X, v.Y - v.X));
}

segment segment_bisector(const segment &u) {
    point p = (u.X + u.Y) / 2;
    return segment(p, rotate90(u.Y, p));
}

segment bisector(const point &a, const point &o, const point &b) {
    ldouble c = distance(o, b) / distance(o, a);
    return segment(o, b + (a - o) * c);
}

pair<bool, point> intersection_line_line(const segment &u, const segment &v) {
    ldouble p = cp(u.Y - v.X, u.Y - u.X);
    ldouble q = cp(v.Y - v.X, u.Y - u.X);
    if(is_zero(q)) return {false, point()};
    return {true, v.X + (v.Y - v.X) * (p / q)};
}

pair<bool, point> intersection_line_segment(const segment &u, const segment &v) {
    auto R = intersection_line_line(u, v);
    if(!R.X) return {false, point()};
    if(!between(R.Y, v.X, v.Y)) return {false, point()};
    return R;
}

pair<bool, point> intersection_segment_segment(const segment &u, const segment &v) {
    auto R = intersection_line_line(u, v);
    if(!R.X) return {false, point()};
    if(!between(R.Y, u.X, u.Y)) return {false, point()};
    if(!between(R.Y, v.X, v.Y)) return {false, point()};
    return R;
}

ldouble diameter(vector<point> P) {
    P = convex_hull(P);
    ldouble result = 0;
    int j = 0, n = SIZE(P);
    if(n == 1) return 0;
    if(n == 2) return distance(P[0], P[1]);
    FORW(i,0,n) {
        while(true) {
            result = max(result, distance(P[i], P[j]));
            if(cp(P[(i+1)%n] - P[i], P[(j+1)%n] - P[j]) > EPS) break;
            j = (j + 1) % n;
        }
    }
    return result;
}


bool in_polygon(const vector<point> &P, int right_id, point p) {
    point x = P[0];
    point y = P[right_id];
    if(p < x or p > y) return false;
    ldouble t = cp(p - x, y - x);
    if(t > EPS) {
        auto it = lower_bound(P.begin() + 1, P.begin() + right_id, p);
        return !on_right(*it, p, it[-1]);
    } else if(t < -EPS) {
        auto it = upper_bound(P.rbegin(), P.rend() - right_id-1, p);
        return !on_right(it == P.rbegin() ? P[0] : it[-1], p, *it);
    } else {
        return on_segment(p, segment(x, y));
    }
}

inline ldouble sq_length(const point &p) {
    return p.X * p.X + p.Y * p.Y;
}

inline ldouble length(const point &p) {
    return sqrtl(sq_length(p));
}

inline point norm(const point &p) {
    ldouble l = length(p);
    return point(p.X / l, p.Y / l);
}

inline int type(const point &p) {
    return p.Y > EPS or (p.Y >= -EPS && p.X > EPS);
}

bool compare_angle(const point &a, const point &b) {
    int at = type(a), bt = type(b);
    if(at != bt) return at < bt;
    ldouble prod = cp(a, b);
    if(abs(prod) > EPS) return prod > EPS;
    return sq_length(a) < sq_length(b) - EPS;
}

struct line {
    point o, v;
    line(const point &a, const point &b): o(a), v(norm(b-a)) {}
};

bool operator < (const line &a, const line &l) {
    if(!(a.v == l.v)) return compare_angle(a.v, l.v);
    return cp(a.v, l.o - a.o) < -EPS;
}

inline segment to_segment(const line &a) {
    return segment(a.o, a.o + a.v);
}

inline ldouble distance_point_line(const point &p, const line &u) {
    return cp(p - u.o, p - (u.o + u.v));
}

vector<point> halfcoat(vector<line> h) {
    const static int MAXN = 300020;
    static const ldouble Z = 1e9;
    static point p[MAXN];
    static point box[4] = {
        point(Z, -Z),
        point(Z, Z),
        point(-Z, Z),
        point(-Z, -Z)
    };
    FORW(i,0,4) h.PB(line(box[i], box[(i+1)%4]));
    int n = SIZE(h), z = 0;
    sort(ALL(h));
    FORW(i,0,n) if(i == 0 or !(h[i].v == h[i-1].v)) h[z++] = h[i];
    n = z;
    int m = 0, del = 0;
    FORW(i,1,n) {
        while(m > del and distance_point_line(p[m-1], h[i]) <= EPS) --m;
        while(m > del and distance_point_line(p[del], h[i]) <= EPS) ++del;
        if(del == m and cp(h[m].v, h[i].v) < EPS) return {};
        point q = intersection_line_line(to_segment(h[i]), to_segment(h[m])).Y;
        if(distance_point_line(q, h[del]) >= -EPS) p[m++] = q, h[m] = h[i];
    }
    rotate(p, p + del, p + m);
    rotate(h.begin(), h.begin() + del, h.end());
    m -= del;
    if(m == 0) return {};
    point q = intersection_line_line(to_segment(h[0]), to_segment(h[m])).Y;
    p[m++] = q;
    return vector<point>(p, p+m);
}

typedef pair<point, ldouble> circle;

inline int triangle_inequality(ldouble p, ldouble q, ldouble r) {
    int a = p + q - r;
    int b = p + r - q;
    int c = q + r - p;
    if(a < -EPS or b < -EPS or c < -EPS) return -1;
    if(a < EPS or b < EPS or c < EPS) return 0;
    return 1;
}

pair<bool, circle> inside_circle(const point &a, const point &b, const point &c) {
    if(abs(cp(b - a, c - a)) < EPS) return {false, circle()};
    segment p = segment_bisector(segment(a, b));
    segment q = segment_bisector(segment(a, c));
    auto w = intersection_line_line(p, q);
    return {true, circle(w.Y, distance(w.Y, a))};
}

inline bool in_circle(const point &p, const circle &c) {
    return distance(p, c.X) - c.Y < -EPS;
}

inline bool on_circle(const point &p, const circle &c) {
    return abs(distance(p, c.X) - c.Y) < EPS;
}

vector<point> circle_line(const circle &c, const segment &u) {
    segment v(c.X, c.X + (rotate90(u.Y, u.X) - u.X) * (c.Y / distance(u.X, u.Y)));
    ldouble x = distance_point_line(c.X, u) / c.Y; 

    if(abs(x) - 1.0 > EPS) return vector<point>();
    if(abs(abs(x) - 1.0) < EPS) return vector<point>{v.Y};
    ldouble theta = acosl(x);
    if(abs(theta) < EPS) return vector<point>{rotate(v.Y, c.X, theta)};
    return vector<point>{rotate(v.Y, c.X, theta), rotate(v.Y, c.X, -theta)};
}

vector<point> circle_circle(const circle &p, const circle &q) {
    ldouble d = distance(p.X, q.X);
    int t = triangle_inequality(d, p.Y, q.Y);
    if(t == -1) return {};
    if(t == 0) return circle_line(q, segment(p.X, q.X));
    ldouble theta = acosl((p.Y*p.Y + d*d - q.Y*q.Y) / (2*d*p.Y));
    point r = p.X + (q.X - p.X) * (p.Y / d);
    point r1 = rotate(r, p.X, theta);
    point r2 = rotate(r, p.X, -theta);
    if(r1 == r2) return {r1};
    return {r1, r2};
}

pair<segment,segment> circle_tangent(const circle &c, const point &p) {
    ldouble theta = asinl(c.Y / distance(p, c.X));
    segment r1, r2;
    r1.X = p;
    r2.X = p;
    r1.Y = rotate(c.X, p, theta);
    r2.Y = rotate(c.X, p, -theta);
    r1.Y = projection(c.X, r1);
    r2.Y = projection(c.X, r2);
    return MP(r1, r2);
}



ldouble circle_line_area(const circle &c, segment u) {
    vector<point> P = circle_line(c, u);
    if(SIZE(P) <= 1) return on_right(u.X, u.Y, c.X) ? c.Y * c.Y * PI : 0;
    bool negate = false;
    if(on_right(u.X, u.Y, c.X)) {
        negate = true;
        swap(u.X, u.Y);
    }
    ldouble theta = angle(P[0], c.X, P[1]);
    ldouble a = abs(theta * c.Y * c.Y);
    ldouble b = abs(cp(P[0] - c.X, P[1] - c.X));
    ldouble result = (a - b) / 2;
    if(negate) result = c.Y * c.Y * PI - result;
    return result;
}

ldouble circle_circle_area(circle p, circle q) {
    ldouble d = distance(p.X, q.X);
    if(d > p.Y + q.Y - EPS) return 0;
    if(d + q.Y < p.Y + EPS) return q.Y * q.Y * PI;
    if(d + p.Y < q.Y + EPS) return p.Y * p.Y * PI;
    vector<point> P = circle_circle(p, q);
    ldouble result = 0;
    FOR(_,1,2) {
        ldouble theta = acosl((q.Y * q.Y + d * d - p.Y * p.Y) / (2 * q.Y * d));
        ldouble s = theta * q.Y * q.Y;
        ldouble t = q.Y * q.Y * sinl(theta) * cosl(theta);
        result += s - t;
        swap(p, q);
    }
    return result;
}

void read_data() {
    vector<circle> cs;
    FOR(i,1,2) {
        int x, y, r;
        scanf("%d %d %d", &x, &y, &r);
        cs.PB(circle(point(x, y), r));
    }
    FOR(i,1,2) {
        cout << setprecision(20) << fixed << circle_circle_area(cs[0], cs[1]) << endl;
        exit(0);
        swap(cs[0], cs[1]);
    }
}

void solve() {

}

int main() {


    read_data();
    solve();
}
