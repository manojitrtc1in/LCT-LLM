




























using namespace std;
using namespace __gnu_pbds;
template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

typedef long long ll;
typedef long double ld;
typedef double db;
typedef string str;

typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef pair<db, db> pd;

typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<ll> vl;
typedef vector<db> vd;
typedef vector<str> vs;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<pd> vpd;



























mt19937 rng((uint32_t) chrono::steady_clock::now().time_since_epoch().count());

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }
template<class T> using V = vector<T>;







template<typename T, typename S> ostream& operator << (ostream &os, const pair<T, S> &p) { return os << "(" << p.first << ", " << p.second << ")"; }
template<typename C, typename T = decay<decltype(*begin(declval<C>()))>, typename enable_if<!is_same<C, string>::value>::type* = nullptr>
ostream& operator << (ostream &os, const C &c) { bool f = true; os << "{"; for (const auto &x : c) { if (!f) os << ", "; f = false; os << x; } return os << "}"; }
template<typename T> void debug(string s, T x) { cerr << s << " = " << x << "\n"; }
template<typename T, typename... Args> void debug(string s, T x, Args... args) { cerr << s.substr(0, s.find(',')) << " = " << x << " | "; debug(s.substr(s.find(',') + 2), args...); }

constexpr int pct(int x) { return __builtin_popcount(x); }
constexpr int bits(int x) { return 31 - __builtin_clz(x); } 


namespace input {
    template<class T> void re(complex<T>& x);
    template<class T1, class T2> void re(pair<T1, T2>& p);
    template<class T> void re(vector<T>& a);
    template<class T, int SZ> void re(array<T, SZ>& a);
    template<class T> void re(T& x) { cin >> x; }
    void re(double& x) { string t; re(t); x = stod(t); }
    void re(ld& x) { string t; re(t); x = stold(t); }
    template<class T, class... Ts> void re(T& t, Ts&... ts) {
        re(t); re(ts...); }
    template<class T> void re(complex<T>& x) { T a, b; re(a, b); x = cd(a, b); }
    template<class T1, class T2> void re(pair<T1, T2>& p) { re(p.f, p.s); }
    template<class T> void re(vector<T>& a) { F0R(i, sz(a)) re(a[i]); }
    template<class T, int SZ> void re(array<T, SZ>& a) { F0R(i, SZ) re(a[i]); }
}

using namespace input;

namespace output {
    void pr(int x) { cout << x; }
    void pr(long x) { cout << x; }
    void pr(ll x) { cout << x; }
    void pr(unsigned x) { cout << x; }
    void pr(unsigned long x) { cout << x; }
    void pr(unsigned long long x) { cout << x; }
    void pr(float x) { cout << x; }
    void pr(double x) { cout << x; }
    void pr(ld x) { cout << x; }
    void pr(char x) { cout << x; }
    void pr(const char* x) { cout << x; }
    void pr(const string& x) { cout << x; }
    void pr(bool x) { pr(x ? "true" : "false"); }
    template<class T> void pr(const complex<T>& x) { cout << x; }
    template<class T1, class T2> void pr(const pair<T1, T2>& x);
    template<class T> void pr(const T& x);
    template<class T, class... Ts> void pr(const T& t, const Ts&... ts) {
        pr(t); pr(ts...); }
    template<class T1, class T2> void pr(const pair<T1,T2>& x) {
        pr("{", x.f, ", ", x.s, "}"); }
    template<class T> void pr(const T& x) {
        pr("{"); 

        bool fst = 1; for (const auto& a: x) pr(!fst ? ", " : "", a), fst = 0;
        pr("}"); }
    void ps() { pr("\n"); } 

    template<class T, class... Ts> void ps(const T& t, const Ts&... ts) {
        pr(t); if (sizeof...(ts)) pr(" "); ps(ts...); }
    void pc() { pr("]\n"); } 

    template<class T, class... Ts> void pc(const T& t, const Ts&... ts) {
        pr(t); if (sizeof...(ts)) pr(", "); pc(ts...); }
}

using namespace output;

namespace io {
    void setIn(string s) { freopen(s.c_str(), "r", stdin); }
    void setOut(string s) { freopen(s.c_str(), "w", stdout); }
    void setIO(string s = "") {
        cin.sync_with_stdio(0); cin.tie(0);
        if (sz(s)) { setIn(s + ".in"), setOut(s + ".out"); }
    }
}

using namespace io;

const int MOD = 1e9 + 7; 

const ld PI = acos((ld) -1);

typedef std::decay <decltype(MOD)>::type mod_t;
struct mi {
    mod_t val;
    explicit operator mod_t() const { return val; }
    mi() { val = 0; }
    mi(const long long& v) {
        val = (-MOD <= v && v <= MOD) ? v : v % MOD;
        if (val < 0) val += MOD; }
    friend std::istream& operator >> (std::istream& in, mi& a) { 
        long long x; std::cin >> x; a = mi(x); return in; }
    friend std::ostream& operator << (std::ostream& os, const mi& a) { return os << a.val; }
    friend void pr(const mi& a) { pr(a.val); }
    friend void re(mi& a) { ll x; re(x); a = mi(x); }
    friend bool operator == (const mi& a, const mi& b) { return a.val == b.val; }
    friend bool operator != (const mi& a, const mi& b) { return !(a == b); }    
    friend bool operator < (const mi& a, const mi& b) { return a.val < b.val; }
    friend bool operator > (const mi& a, const mi& b) { return a.val > b.val; }
    friend bool operator <= (const mi& a, const mi& b) { return a.val <= b.val; }
    friend bool operator >= (const mi& a, const mi& b) { return a.val >= b.val; }
    mi operator - () const { return mi(-val); }
    mi& operator += (const mi& m) {
        if ((val += m.val) >= MOD) val -= MOD;
        return *this; }
    mi& operator -= (const mi& m) {
        if ((val -= m.val) < 0) val += MOD;
        return *this; }
    mi& operator *= (const mi& m) { val = (long long) val * m.val % MOD;
        return *this; }
    friend mi pow(mi a, long long p) {
        mi ans = 1; assert(p >= 0);
        for (; p; p /= 2, a *= a) if (p & 1) ans *= a;
        return ans; }
    friend mi inv(const mi& a) { assert(a != 0); return pow(a, MOD - 2); }
    mi& operator /= (const mi& m) { return (*this) *= inv(m); }
    friend mi operator + (mi a, const mi& b) { return a += b; }
    friend mi operator - (mi a, const mi& b) { return a -= b; }
    friend mi operator * (mi a, const mi& b) { return a *= b; }
    friend mi operator / (mi a, const mi& b) { return a /= b; }
};
typedef pair<mi, mi> pmi;
typedef vector<mi> vmi;
typedef vector<pmi> vpmi;
template <typename T> struct Point {
public:
    T x, y;
    Point() : x(0), y(0) {}
    Point(T x_, T y_) : x(x_), y(y_) {}
    template <typename U> explicit Point(const Point<U>& p) : x(p.x), y(p.y) {}
    Point(const std::pair<T, T>& p) : x(p.first), y(p.second) {}
    Point(const std::complex<T>& p) : x(real(p)), y(imag(p)) {}
    explicit operator std::pair<T, T> () const { return std::pair<T, T>(x, y); }
    explicit operator std::complex<T> () const { return std::complex<T>(x, y); }

    friend std::ostream& operator << (std::ostream& o, const Point& p) { 
        return o << '(' << p.x << ',' << p.y << ')'; }
    friend std::istream& operator >> (std::istream& i, Point& p) { return i >> p.x >> p.y; }
    friend bool operator == (const Point& a, const Point& b) { return a.x == b.x && a.y == b.y; }
    friend bool operator != (const Point& a, const Point& b) { return !(a == b); }
    friend bool operator < (const Point& a, const Point& b) { 
        return (a.x != b.x ? a.x < b.x : a.y < b.y); }

    friend T norm(const Point& a) { return a.x * a.x + a.y * a.y; }
    friend T abs(const Point& p) { return std::hypot(p.x, p.y); }
    friend T unit(const Point& a) { if (a == Point()) return a; return a / abs(a); }
    friend Point conj(const Point& a) { return Point(a.x, -a.y); }
    friend Point perp(const Point& a) { return Point(-a.y, a.x); }
    friend long double arg(const Point& p) { return atan2(p.y, p.x); }
    friend Point dir(long double angle) { return Point(cos(angle), sin(angle)); }

    Point& operator += (const Point& p) { x += p.x, y += p.y; return *this; }
    Point& operator -= (const Point& p) { x -= p.x, y -= p.y; return *this; }
    Point& operator *= (const T& t) { x *= t, y *= t; return *this; }
    Point& operator /= (const T& t) { x /= t, y /= t; return *this; }
    Point& operator *= (const Point& t) { 
        Point res = Point(x, y) * t; x = res.x, y = res.y; return *this; }
    Point& operator /= (const Point& t) { 
        Point res = Point(x, y) / t; x = res.x, y = res.y; return *this; }

    friend Point operator + (const Point& a, const Point& b) { return Point(a.x + b.x, a.y + b.y); }
    friend Point operator - (const Point& a, const Point& b) { return Point(a.x - b.x, a.y - b.y); }
    friend Point operator * (const Point& a, const T& t) { return Point(a.x * t, a.y * t); }
    friend Point operator * (const T& t ,const Point& a) { return Point(t * a.x, t * a.y); }
    friend Point operator / (const Point& a, const T& t) { return Point(a.x / t, a.y / t); }
    friend Point operator * (const Point& a, const Point& b) { 
        return Point(a.x * b.x - a.y * b.y, a.y * b.x + a.x * b.y); }
    friend Point operator / (const Point& a, const Point& b) { 
        return Point(a * conj(b) / norm(b)); }

    friend T int_norm(const Point& a) { return __gcd(a.x, a.y); }
    friend T int_unit(const Point& a) { if (a == Point()) return a; return a / int_norm(a); }

    friend T cross(const Point& a, const Point& b) { return a.x * b.y - a.y * b.x; }
    friend T dot(const Point& a, const Point& b) { return a.x * b.x + a.y * b.y; }
    friend T area(const Point& a, const Point& b, const Point& c) { return cross(b - a, c - a); }

    

    friend Point rotation(const Point& a, const Point& b) { return Point(dot(a, b), cross(a, b)); }

    friend bool same_dir(const Point& a, const Point& b) { return cross(a, b) == 0 && dot(a, b) > 0; }

    

    friend bool id6(const Point& a, const Point& b) { 
        auto c = cross(a, b); return c ? (c < 0) : (dot(a, b) < 0); }

    

    friend bool angle_less(const Point& base, const Point& s, const Point& t) {
        int r = id6(base, s) - id6(base, t);
        return r ? (r < 0) : (0 < cross(s, t));
    }

    friend bool angle_cmp(const Point& base) {
        return [base](const Point& s, const Point& t) { return angle_less(base, s, t); };
    }
    friend bool id3(const Point& center, const Point& dir) {
        return [center, dir](const Point& s, const Point& t) -> bool { 
            return angle_less(dir, s - center, t - center); };
    }

    

    friend int angle_between(const Point& s, const Point& t, const Point& p) {
        if (same_dir(p, s) || same_dir(p, t)) return 0;
        return angle_less(s, p, t) ? 1 : -1;
    }
};

namespace Geometry2D {

template <class T> int sign(T x) { return (x > 0) - (x < 0); }
template <class T> Point<T> reflect(const Point<T>& p, const Point<T>& a, const Point<T>& b) {
        return a + conj((p - a) / (b - a)) * (b - a); }
template <class T> Point<T> foot( const Point<T>& p, const Point<T>& a, const Point<T>& b) {
        return (p + reflect(p, a, b)) / (T) 2; }
template <class T> bool on_segment(Point<T> p, Point<T> a, Point<T> b) {
    return area(a, b, p) == 0 && dot(p - a, p - b) <= 0; }

template <class T>
std::vector<Point<T>> id0(Point<T> a, Point<T> b, Point<T> c, Point<T> d) {
    T x = area(a, b, c), y = area(a, b, d);
    T X = area(c, d, a), Y = area(c, d, b);
    if (sign(x) * sign(y) < 0 && sign(X) * sign(Y) < 0)
        return {(d * x - c * y) / (x - y)};
    std::set<Point<T>> s;
    if (on_segment(a, c, d))
        s.insert(a);
    if (on_segment(b, c, d))
        s.insert(b);
    if (on_segment(c, a, b))
        s.insert(c);
    if (on_segment(d, a, b))
        s.insert(d);
    return {s.begin(), s.end()};
}

template <class T> Point<T> extension(Point<T> a, Point<T> b, Point<T> c, Point<T> d) {
    T x = cross(a, b, c);
    T y = cross(a, b, d);
    return (d * x - c * y) / (x - y);
}

template <class T> std::pair<int, Point<T>> id2(Point<T> a, Point<T> b, Point<T> c, Point<T> d) {
    

    if (cross(b - a, d - c) == 0)
        return {-(cross(a, c, d) == 0), Point<T>()};
    else 
        return {1, extend(a, b, c, d)};
}

template <class T> T line_dist(Point<T> p, Point<T> a, Point<T> b) {
    return abs(area(p, a, b)) / abs(a - b); }

template <class T> T id5(Point<T> p, Point<T> a, Point<T> b) {
    if (dot(p - a, b - a) <= 0)
        return abs(p - a);
    if (dot(p - b, a - b) <= 0)
        return abs(p - b);
    return line_dist(p, a, b);
}

template <class T> T id1(Point<T> a, Point<T> b, Point<T> c, Point<T> d) {
    std::vector<Point<T>> v = id0(a, b, c, d);
    if (!v.empty())
        return 0;
    return std::min({id5(a, c, d), id5(b, c, d), 
        id5(c, a, b), id5(d, a, b)});
}

template <class T> std::pair<Point<T>, T> id4(const std::vector<Point<T>> v) {
    

    Point<T> centroid(0, 0);
    T area = 0;
    for (int i = 0; i < (int) v.size(); i++) {
        int j = (i + 1) % ((int) v.size());
        T a = cross(v[i], v[j]);
        centroid += a * (v[i] + v[j]);
        area += a;
    }
    return {centroid / area / (T) 3, area / 2};
}

template<class T> int polygon_point(const std::vector<Point<T>>& p, Point<T> z) {
    

    int n = (int) p.size();
    int ans = 0;
    for (int i = 0; i < n; i++) {
        Point<T> x = p[i], y = p[(i + 1) % n];
        if (x.y > y.y) 
            std::swap(x, y);
        if (on_segment(z, x, y))
            return 0;
        ans ^= (x.y <= z.y && y.y > z.y && area(z, x, y) > 0);
    }
    return ans ? 1 : -1;
}

}

using P = Point<ll>;
int n;
vector<P> v;

int main() {
    int n; re(n);
    v.resize(n);
    id7(i, n) re(v[i]);
    vector<bool> used(n);
    used[0] = 1;
    vi ord; ord.eb(0);
    id7(i, n-1) {
        pl best = {-1, 0};
        id7(j, n) {
            if (used[j]) continue;
            ckmax(best, {norm(v[ord.back()]-v[j]), j});
        }
        ord.eb(best.s);
        used[best.s] = true;
    }
    trav(t, ord) pr(t+1, " ");
    ps();
    return 0;
}