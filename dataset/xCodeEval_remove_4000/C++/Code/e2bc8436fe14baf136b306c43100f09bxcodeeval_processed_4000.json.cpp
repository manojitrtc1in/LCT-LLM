




















    vector<type> name(size);                                                                                                                                   \
    IN(name)


    vector<vector<type>> name(h, vector<type>(w));                                                                                                             \
    IN(name)


    vector<vector<vector<vector<type>>>> name(a, vector<vector<vector<type>>>(b, vector<vector<type>>(c, vector<type>(id1))))





using namespace std;
string YES[2] = {"NO", "YES"};
string Yes[2] = {"No", "Yes"};
string yes[2] = {"no", "yes"};
template <class T> using pq = priority_queue<T>;
template <class T> using pqg = priority_queue<T, vector<T>, greater<T>>;


    int id1;                                                                                                                                           \
    IN(id1)

    ll id1;                                                                                                                                            \
    IN(id1)

    string id1;                                                                                                                                        \
    IN(id1)

    char id1;                                                                                                                                          \
    IN(id1)

    double id1;                                                                                                                                        \
    IN(id1)
int scan() { return getchar(); }
void scan(int &a) { cin >> a; }
void scan(long long &a) { cin >> a; }
void scan(char &a) { cin >> a; }
void scan(double &a) { cin >> a; }
void scan(string &a) { cin >> a; }
template <class T, class S> void scan(pair<T, S> &p) { scan(p.first), scan(p.second); }
template <class T> void scan(vector<T> &);
template <class T> void scan(vector<T> &a) {
    for(auto &i : a) scan(i);
}
template <class T> void scan(T &a) { cin >> a; }
void IN() {}
template <class Head, class... Tail> void IN(Head &head, Tail &... tail) {
    scan(head);
    IN(tail...);
}
template <class T, class S> inline bool chmax(T &a, S b) {
    if(a < b) {
        a = b;
        return 1;
    }
    return 0;
}
template <class T, class S> inline bool chmin(T &a, S b) {
    if(a > b) {
        a = b;
        return 1;
    }
    return 0;
}
vi iota(int n) {
    vi a(n);
    iota(all(a), 0);
    return a;
}
template <typename T> vi iota(vector<T> &a, bool greater = false) {
    vi res(a.size());
    iota(all(res), 0);
    sort(all(res), [&](int i, int j) {
        if(greater) return a[i] > a[j];
        return a[i] < a[j];
    });
    return res;
}

vector<pll> factor(ll x) {
    vector<pll> ans;
    for(ll i = 2; i * i <= x; i++)
        if(x % i == 0) {
            ans.push_back({i, 1});
            while((x /= i) % i == 0) ans.back().second++;
        }
    if(x != 1) ans.push_back({x, 1});
    return ans;
}
template <class T> vector<T> divisor(T x) {
    vector<T> ans;
    for(T i = 1; i * i <= x; i++)
        if(x % i == 0) {
            ans.pb(i);
            if(i * i != x) ans.pb(x / i);
        }
    return ans;
}
template <typename T> void zip(vector<T> &x) {
    vector<T> y = x;
    sort(all(y));
    for(int i = 0; i < x.size(); ++i) { x[i] = lb(y, x[i]); }
}
int popcount(ll x) { return __builtin_popcountll(x); }
struct Setup_io {
    Setup_io() {
        ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
        cout << fixed << setprecision(15);
    }
} setup_io;
int in() {
    int x;
    cin >> x;
    return x;
}
ll lin() {
    unsigned long long x;
    cin >> x;
    return x;
}

template <typename T> struct edge {
    int from, to;
    T cost;
    int id;
    edge(int to, T cost) : from(-1), to(to), cost(cost) {}
    edge(int from, int to, T cost) : from(from), to(to), cost(cost) {}
    edge(int from, int to, T cost, int id) : from(from), to(to), cost(cost), id(id) {}
    edge &operator=(const int &x) {
        to = x;
        return *this;
    }
    operator int() const { return to; }
};
template <typename T> using Edges = vector<edge<T>>;

using Tree = vector<vector<int>>;
using Graph = vector<vector<int>>;
template <class T> using Wgraph = vector<vector<edge<T>>>;
Graph getG(int n, int m = -1, bool directed = false, int margin = 1) {
    Tree res(n);
    if(m == -1) m = n - 1;
    while(m--) {
        int a, b;
        cin >> a >> b;
        a -= margin, b -= margin;
        res[a].emplace_back(b);
        if(!directed) res[b].emplace_back(a);
    }
    return move(res);
}
template <class T> Wgraph<T> id3(int n, int m = -1, bool directed = false, int margin = 1) {
    Wgraph<T> res(n);
    if(m == -1) m = n - 1;
    while(m--) {
        int a, b;
        T c;
        cin >> a >> b >> c;
        a -= margin, b -= margin;
        res[a].emplace_back(b, c);
        if(!directed) res[b].emplace_back(a, c);
    }
    return move(res);
}




    INT(testcases);                                                                                                                                            \
    while(testcases--)
template <class T> ostream &operator<<(ostream &os, const vector<T> &v) {
    for(auto &e : v) cout << e << " ";
    cout << endl;
    return os;
}
template <class T, class S> ostream &operator<<(ostream &os, const pair<T, S> &p) {
    cout << "(" << p.fi << ", " << p.se << ")";
    return os;
}
template <class S, class T> string to_string(pair<S, T> p) { return "(" + to_string(p.first) + "," + to_string(p.second) + ")"; }
template <class A> string to_string(A v) {
    if(v.empty()) return "{}";
    string ret = "{";
    for(auto &x : v) ret += to_string(x) + ",";
    ret.back() = '}';
    return ret;
}

void dump() { cerr << endl; }
template <class Head, class... Tail> void dump(Head head, Tail... tail) {
    cerr << to_string(head) << " ";
    dump(tail...);
}




    cout << 
    dump(x)



mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int rnd(int n) { return uniform_int_distribution<int>(0, n - 1)(rng); }



template <typename T> static constexpr T inf = numeric_limits<T>::max() / 2;


using Real = long double;
using Point = complex<Real>;
const Real EPS = 1e-8, PI = acos(-1);

inline bool eq(Real a, Real b) { return fabs(b - a) < EPS; }

Point operator*(const Point &p, const Real &d) { return Point(real(p) * d, imag(p) * d); }

istream &operator>>(istream &is, Point &p) {
    Real a, b;
    is >> a >> b;
    p = Point(a, b);
    return is;
}

ostream &operator<<(ostream &os, Point &p) { return os << fixed << setprecision(10) << p.real() << " " << p.imag(); }



Point rotate(Real theta, const Point &p) { return Point(cos(theta) * p.real() - sin(theta) * p.imag(), sin(theta) * p.real() + cos(theta) * p.imag()); }

Real id0(Real r) { return (r * 180.0 / PI); }

Real id2(Real d) { return (d * PI / 180.0); }



Real get_angle(const Point &a, const Point &b, const Point &c) {
    const Point v(b - a), w(c - b);
    Real alpha = atan2(v.imag(), v.real()), beta = atan2(w.imag(), w.real());
    if(alpha > beta) swap(alpha, beta);
    Real theta = (beta - alpha);
    return min(theta, 2 * acos(-1) - theta);
}

namespace std {
bool operator<(const Point &a, const Point &b) { return a.real() != b.real() ? a.real() < b.real() : a.imag() < b.imag(); }
} 


struct Line {
    Point a, b;

    Line() = default;

    Line(Point a, Point b) : a(a), b(b) {}

    Line(Real A, Real B, Real C) 

    {
        if(eq(A, 0))
            a = Point(0, C / B), b = Point(1, C / B);
        else if(eq(B, 0))
            b = Point(C / A, 0), b = Point(C / A, 1);
        else
            a = Point(0, C / B), b = Point(C / A, 0);
    }

    friend ostream &operator<<(ostream &os, Line &p) { return os << p.a << " to " << p.b; }

    friend istream &operator>>(istream &is, Line &a) { return is >> a.a >> a.b; }
};

struct Segment : Line {
    Segment() = default;

    Segment(Point a, Point b) : Line(a, b) {}
};

struct Circle {
    Point p;
    Real r;

    Circle() = default;

    Circle(Point p, Real r) : p(p), r(r) {}
};

using Points = vector<Point>;
using Polygon = vector<Point>;
using Segments = vector<Segment>;
using Lines = vector<Line>;
using Circles = vector<Circle>;

Real cross(const Point &a, const Point &b) { return real(a) * imag(b) - imag(a) * real(b); }

Real dot(const Point &a, const Point &b) { return real(a) * real(b) + imag(a) * imag(b); }





int ccw(const Point &a, Point b, Point c) {
    b = b - a, c = c - a;
    if(cross(b, c) > EPS) return +1;  

    if(cross(b, c) < -EPS) return -1; 

    if(dot(b, c) < 0) return +2;      

    if(norm(b) < norm(c)) return -2;  

    return 0;                         

}





bool parallel(const Line &a, const Line &b) { return eq(cross(a.b - a.a, b.b - b.a), 0.0); }





bool orthogonal(const Line &a, const Line &b) { return eq(dot(a.a - a.b, b.a - b.b), 0.0); }







Point projection(const Line &l, const Point &p) {
    double t = dot(p - l.a, l.a - l.b) / norm(l.a - l.b);
    return l.a + (l.a - l.b) * t;
}

Point projection(const Segment &l, const Point &p) {
    double t = dot(p - l.a, l.a - l.b) / norm(l.a - l.b);
    return l.a + (l.a - l.b) * t;
}







Point reflection(const Line &l, const Point &p) { return p + (projection(l, p) - p) * 2.0; }

bool intersect(const Line &l, const Point &p) { return abs(ccw(l.a, l.b, p)) != 1; }

bool intersect(const Line &l, const Line &m) { return abs(cross(l.b - l.a, m.b - m.a)) > EPS || abs(cross(l.b - l.a, m.b - l.a)) < EPS; }

bool intersect(const Segment &s, const Point &p) { return ccw(s.a, s.b, p) == 0; }

bool intersect(const Line &l, const Segment &s) { return cross(l.b - l.a, s.a - l.a) * cross(l.b - l.a, s.b - l.a) < EPS; }

Real distance(const Line &l, const Point &p);

bool intersect(const Circle &c, const Line &l) { return distance(l, c.p) <= c.r + EPS; }

bool intersect(const Circle &c, const Point &p) { return abs(abs(p - c.p) - c.r) < EPS; }



bool intersect(const Segment &s, const Segment &t) { return ccw(s.a, s.b, t.a) * ccw(s.a, s.b, t.b) <= 0 && ccw(t.a, t.b, s.a) * ccw(t.a, t.b, s.b) <= 0; }

int intersect(const Circle &c, const Segment &l) {
    if(norm(projection(l, c.p) - c.p) - c.r * c.r > EPS) return 0;
    auto d1 = abs(c.p - l.a), d2 = abs(c.p - l.b);
    if(d1 < c.r + EPS && d2 < c.r + EPS) return 0;
    if(d1 < c.r - EPS && d2 > c.r + EPS || d1 > c.r + EPS && d2 < c.r - EPS) return 1;
    const Point h = projection(l, c.p);
    if(dot(l.a - h, l.b - h) < 0) return 2;
    return 0;
}



int intersect(Circle c1, Circle c2) {
    if(c1.r < c2.r) swap(c1, c2);
    Real d = abs(c1.p - c2.p);
    if(c1.r + c2.r < d) return 4;
    if(eq(c1.r + c2.r, d)) return 3;
    if(c1.r - c2.r < d) return 2;
    if(eq(c1.r - c2.r, d)) return 1;
    return 0;
}

Real distance(const Point &a, const Point &b) { return abs(a - b); }

Real distance(const Line &l, const Point &p) { return abs(p - projection(l, p)); }

Real distance(const Line &l, const Line &m) { return intersect(l, m) ? 0 : distance(l, m.a); }

Real distance(const Segment &s, const Point &p) {
    Point r = projection(s, p);
    if(intersect(s, r)) return abs(r - p);
    return min(abs(s.a - p), abs(s.b - p));
}



Real distance(const Segment &a, const Segment &b) {
    if(intersect(a, b)) return 0;
    return min({distance(a, b.a), distance(a, b.b), distance(b, a.a), distance(b, a.b)});
}

Real distance(const Line &l, const Segment &s) {
    if(intersect(l, s)) return 0;
    return min(distance(l, s.a), distance(l, s.b));
}

Point crosspoint(const Line &l, const Line &m) {
    Real A = cross(l.b - l.a, m.b - m.a);
    Real B = cross(l.b - l.a, l.b - m.a);
    if(eq(abs(A), 0.0) && eq(abs(B), 0.0)) return m.a;
    return m.a + (m.b - m.a) * B / A;
}



Point crosspoint(const Segment &l, const Segment &m) { return crosspoint(Line(l), Line(m)); }



pair<Point, Point> crosspoint(const Circle &c, const Line l) {
    Point pr = projection(l, c.p);
    Point e = (l.b - l.a) / abs(l.b - l.a);
    if(eq(distance(l, c.p), c.r)) return {pr, pr};
    double base = sqrt(c.r * c.r - norm(pr - c.p));
    return {pr - e * base, pr + e * base};
}

pair<Point, Point> crosspoint(const Circle &c, const Segment &l) {
    Line aa = Line(l.a, l.b);
    if(intersect(c, l) == 2) return crosspoint(c, aa);
    auto ret = crosspoint(c, aa);
    if(dot(l.a - ret.first, l.b - ret.first) < 0)
        ret.second = ret.first;
    else
        ret.first = ret.second;
    return ret;
}



pair<Point, Point> crosspoint(const Circle &c1, const Circle &c2) {
    Real d = abs(c1.p - c2.p);
    Real a = acos((c1.r * c1.r + d * d - c2.r * c2.r) / (2 * c1.r * d));
    Real t = atan2(c2.p.imag() - c1.p.imag(), c2.p.real() - c1.p.real());
    Point p1 = c1.p + Point(cos(t + a) * c1.r, sin(t + a) * c1.r);
    Point p2 = c1.p + Point(cos(t - a) * c1.r, sin(t - a) * c1.r);
    return {p1, p2};
}

int main() {
    INT(n, q);
    Points P(n);
    rep(i, n) cin >> P[i];
    Point g;
    {
        ld w = 0;
        rep(i, n - 2) {
            Point G = (P[0] + P[i + 1] + P[i + 2]) / (ld)3;
            ld S = abs(cross(P[i + 1] - P[0], P[i + 2] - P[0]));
            g += G * S, w += S;
        }
        g /= w;
    }
    vector<long double> angles(n);
    {
        rep(i, n) {
            auto p = P[i] - g;
            P[i] -= g;
            angles[i] = atan2(-P[i].real(), P[i].imag());
        }
    }
    long double theta = 0;
    multiset<int> pins({0, 1});
    auto get = [&](int i) { return rotate(-theta, P[i]) + g; };
    

    while(q--) {
        INT(t);
        if(t == 1) {
            INT(x, y);
            x--, y--;
            pins.erase(pins.lower_bound(x));
            int now = *pins.begin();
            auto p = get(now);
            theta = angles[now];
            g = p - rotate(-theta, P[now]);
            pins.emplace(y);
        } else {
            INT(x);
            auto p = get(x - 1);
            cout << p.real() << " " << p.imag() << endl;
        }
    }
}