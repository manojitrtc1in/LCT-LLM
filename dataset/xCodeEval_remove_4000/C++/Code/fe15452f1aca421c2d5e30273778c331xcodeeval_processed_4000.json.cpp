
using namespace std;





















typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<pi> vii;
const int MOD = (int) 1e9 + 7;
const int id13 = 119 << 23 | 1;
const int INF = (int) 1e9 + 23111992;
const ll LINF = (ll) 1e18 + 23111992;
const ld PI = acos((ld) -1);
const ld EPS = 1e-9;
inline ll gcd(ll a, ll b) {ll r; while (b) {r = a % b; a = b; b = r;} return a;}
inline ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}
inline ll fpow(ll n, ll k, int p = MOD) {ll r = 1; for (; k; k >>= 1) {if (k & 1) r = r * n % p; n = n * n % p;} return r;}
template<class T> inline int chkmin(T& a, const T& val) {return val < a ? a = val, 1 : 0;}
template<class T> inline int chkmax(T& a, const T& val) {return a < val ? a = val, 1 : 0;}
inline ull isqrt(ull k) {ull r = sqrt(k) + 1; while (r * r > k) r--; return r;}
inline ll id18(ll k) {ll r = cbrt(k) + 1; while (r * r * r > k) r--; return r;}
inline void addmod(int& a, int val, int p = MOD) {if ((a = (a + val)) >= p) a -= p;}
inline void submod(int& a, int val, int p = MOD) {if ((a = (a - val)) < 0) a += p;}
inline int mult(int a, int b, int p = MOD) {return (ll) a * b % p;}
inline int inv(int a, int p = MOD) {return fpow(a, p - 2, p);}
inline int sign(ld x) {return x < -EPS ? -1 : x > +EPS;}
inline int sign(ld x, ld y) {return sign(x - y);}
mt19937 mt(chrono::high_resolution_clock::now().time_since_epoch().count());
inline int mrand() {return abs((int) mt());}
inline int mrand(int k) {return abs((int) mt()) % k;}
template<typename X> void debug(X x) { cerr << x << "] "; }
template<typename X, typename ...Y> void debug(X x, Y... y) { cerr << x << " "; debug(y...); }







struct point_t {
  double x, y;
  point_t() : x(0), y(0) {}
  point_t(double x, double y) : x(x), y(y) {}
  point_t(const point_t& p) : x(p.x), y(p.y) {}
  int operator < (const point_t& rhs) const {return make_pair(y, x) < make_pair(rhs.y, rhs.x);}
  int operator == (const point_t& rhs) const {return make_pair(y, x) == make_pair(rhs.y, rhs.x);}
  point_t operator + (const point_t& p) const {return point_t(x + p.x, y + p.y);}
  point_t operator - (const point_t& p) const {return point_t(x - p.x, y - p.y);}
  point_t operator * (double c) const {return point_t(x * c, y * c);}
  point_t operator / (double c) const {return point_t(x / c, y / c);}
};
double cross(point_t p, point_t q) {return p.x * q.y - p.y * q.x;}
double area(point_t a, point_t b, point_t c) {return fabs(cross(a, b) + cross(b, c) + cross(c, a)) / 2;}
double area2(point_t a, point_t b, point_t c) {return cross(a, b) + cross(b, c) + cross(c, a);}
double dot(point_t p, point_t q) {return p.x * q.x + p.y * q.y;}
double dist(point_t p, point_t q) {return sqrt(dot(p - q, p - q));}
double dist2(point_t p, point_t q) {return dot(p - q, p - q);}
point_t id6(point_t p) {return point_t(-p.y, p.x);}
point_t id10(point_t p) {return point_t(p.y, -p.x);}
point_t id1(point_t p, double t) {return point_t(p.x * cos(t) - p.y * sin(t), p.x * sin(t) + p.y * cos(t));}
int sign(double x) {return x < -EPS ? -1 : x > EPS;}
int sign(double x, double y) {return sign(x - y);}
ostream& operator << (ostream& os, const point_t& p) {
  os << "(" << p.x << "," << p.y << ")";
  return os;
}



point_t id8(point_t a, point_t b, point_t c) {
  return a + (b - a) * dot(c - a, b - a) / dot(b - a, b - a);
}
point_t id11(point_t a, point_t b, point_t c) {
  double r = dot(b - a, b - a);
  if (fabs(r) < EPS) return a;
  r = dot(c - a, b - a) / r;
  if (r < 0) return a;
  if (r > 1) return b;
  return a + (b - a) * r;
}
double id0(point_t a, point_t b, point_t c) {
  return dist(c, id11(a, b, c));
}


double id2(double x, double y, double z, double a, double b, double c, double d) {
  return fabs(a * x + b * y + c * z - d) / sqrt(a * a + b * b + c * c);
}


int LinesParallel(point_t a, point_t b, point_t c, point_t d) {
  return fabs(cross(b - a, c - d)) < EPS;
}
int id14(point_t a, point_t b, point_t c, point_t d) {
  return LinesParallel(a, b, c, d) && fabs(cross(a - b, a - c)) < EPS && fabs(cross(c - d, c - a)) < EPS;
}


int SegmentsIntersect(point_t a, point_t b, point_t c, point_t d) {
  if (id14(a, b, c, d)) {
    if (dist2(a, c) < EPS || dist2(a, d) < EPS || dist2(b, c) < EPS || dist2(b, d) < EPS) return 1;
    if (dot(c - a, c - b) > 0 && dot(d - a, d - b) > 0 && dot(c - b, d - b) > 0) return 0;
    return 1;
  }
  if (cross(d - a, b - a) * cross(c - a, b - a) > 0) return 0;
  if (cross(a - c, d - c) * cross(b - c, d - c) > 0) return 0;
  return 1;
}








point_t id9(point_t a, point_t b, point_t c, point_t d) {
  b = b - a; d = c - d; c = c - a;
  return a + b * cross(c, d) / cross(b, d);
}


point_t id16(point_t a, point_t b, point_t c) {
  b = (a + b) / 2;
  c = (a + c) / 2;
  return id9(b, b + id10(a - b), c, c + id10(a - c));
}






int id12(const vector<point_t>& p, point_t q) {
  int c = 0;
  for (int i = 0; i < p.size(); i++) {
    int j = (i + 1) % p.size();
    if ((p[i].y <= q.y && q.y < p[j].y || p[j].y <= q.y && q.y < p[i].y) && q.x < p[i].x + (p[j].x - p[i].x) * (q.y - p[i].y) / (p[j].y - p[i].y)) c = !c;
  }
  return c;
}



int id17(vector<point_t>& p, point_t q) {
  int a = 1, b = p.size() - 1, c;
  if (Det(p[0], p[a], p[b]) > 0) swap(a, b);
  

  if (Det(p[0], p[a], q) >= 0 || Det(p[0], p[b], q) <= 0) return 0;
  while(abs(a - b) > 1) {
    c = (a + b) / 2;
    if (Det(p[0], p[c], q) > 0) b = c; else a = c;
  }
  

  return Det(p[a], p[b], q) < 0;
}


int id5(const vector<point_t>& p, point_t q) {
  for (int i = 0; i < p.size(); i++) if (dist2(id11(p[i], p[(i + 1) % p.size()], q), q) < EPS) return 1;
  return 0;
}


vector<point_t> id3(point_t a, point_t b, point_t c, double r) {
  vector<point_t> res;
  b = b - a; a = a - c;
  double A = dot(b, b);
  double B = dot(a, b);
  double C = dot(a, a) - r * r;
  double D = B * B - A * C;
  if (D < -EPS) return res;
  res.push_back(c + a + b * (-B + sqrt(D + EPS)) / A);
  if (D > EPS) res.push_back(c + a + b * (-B - sqrt(D)) / A);
  return res;
}


vector<point_t> id7(point_t a, point_t b, double r, double R) {
  vector<point_t> res;
  double d = sqrt(dist2(a, b));
  if (d > r + R || d + min(r, R) < max(r, R)) return res;
  double x = (d * d - R * R + r * r) / (2 * d);
  double y = sqrt(r * r - x * x);
  point_t v = (b - a) / d;
  res.push_back(a + v * x + id6(v) * y);
  if (y > 0) res.push_back(a + v * x - id6(v) * y);
  return res;
}








double id4(const vector<point_t>& p) {
  double area = 0;
  for(int i = 0; i < p.size(); i++) {
    int j = (i + 1) % p.size();
    area += p[i].x * p[j].y - p[j].x * p[i].y;
  }
  return area / 2.0;
}
double ComputeArea(const vector<point_t>& p) {
  return fabs(id4(p));
}
point_t id15(const vector<point_t>& p) {
  point_t c(0, 0);
  double scale = 6.0 * id4(p);
  for (int i = 0; i < p.size(); i++) {
    int j = (i + 1) % p.size();
    c = c + (p[i] + p[j]) * (p[i].x * p[j].y - p[j].x * p[i].y);
  }
  return c / scale;
}


int IsSimple(const vector<point_t>& p) {
  for (int i = 0; i < p.size(); i++) {
    for (int k = i + 1; k < p.size(); k++) {
      int j = (i + 1) % p.size();
      int l = (k + 1) % p.size();
      if (i == l || j == k) continue;
      if (SegmentsIntersect(p[i], p[j], p[k], p[l])) return 0;
    }
  }
  return 1;
}
double Angle(point_t a) {
  double PI = acos((double) - 1);
  if (a.x == 0) {
    if (a.y > 0) return PI / 2;
    return 3 * PI / 2;
  }
  if (a.y == 0) {
    if (a.x > 0) return 0;
    return PI;
  }
  double res = atan(a.y / a.x);
  if (a.x < 0) return res + PI;
  if (a.y < 0) return res + 2 * PI;
  return res;
}

void chemthan() {
  auto psort = [&] (vector<point_t>& pts) {
    point_t M;
    FOR(i, 0, sz(pts)) {
      M = M + pts[i] / sz(pts);
    }
    sort(all(pts), [&] (point_t a, point_t b) {
        a = a - M, b = b - M;
        int fa = 0 < a.x || (a.x == 0 && 0 < a.y);
        int fb = 0 < b.x || (b.x == 0 && 0 < b.y);
        if (fa != fb) return fa;
        return 0 < cross(a, b) ? 1 : 0;
        }
        );
  };
  auto calc = [&] (point_t A, point_t B, point_t C) {
    vector<point_t> pts = {A, B, C};
    psort(pts);
    A = pts[0], B = pts[1], C = pts[2];
    point_t D = B + id1(A - B, PI / 3);
    point_t E = C + id1(B - C, PI / 3);
    point_t O = id9(C, D, A, E);
    double res = 1e9;
    for (point_t X : {A, B, C, O}) {
      chkmin(res, dist(X, A) + dist(X, B) + dist(X, C));
    }
    return res;
  };
  vector<point_t> pts(3);
  FOR(i, 0, 3) cin >> pts[i].x >> pts[i].y;
  psort(pts);
  auto check = [&] (point_t A, point_t B, point_t C, double r) {
    point_t D = B + id1(A - B, PI / 3);
    point_t U(INF, INF);
    point_t V(INF, INF);
    for (point_t X : id3(A, C, D, r)) {
      if (0 < cross(A - X, B - X)) {
        U = X - D;
      }
    }
    for (point_t X : id3(B, C, D, r)) {
      if (0 < cross(A - X, B - X)) {
        V = X - D;
      }
    }
    if (U == point_t(INF, INF) || V == point_t(INF, INF)) {
      return 0;
    }
    assert(!sign(dist(U + D, D), r));
    assert(!sign(dist(V + D, D), r));
    double u = Angle(U);
    double v = Angle(V);
    {
      double lo = 0, hi = 1;
      FOR(it, 0, 100) {
        double mi = (lo + hi) / 2;
        double w = v + (u - v) * mi;
        point_t E = D + point_t(cos(w), sin(w)) * r;
        if (dist(E, B) + dist(E, C) < r) {
          lo = mi;
        }
        else {
          hi = mi;
        }
      }
      double mi = (lo + hi) / 2;
      double w = v + (u - v) * mi;
      point_t E = D + point_t(cos(w), sin(w)) * r;
      if (sign(mi) && sign(mi, 1)) {
        assert(!sign(dist(E, B) + dist(E, C), r));
      }
      if (sign(calc(A, B, E), r) <= 0 && sign(calc(B, C, E), r) <= 0 && sign(calc(C, A, E), r) <= 0) {
        return 1;
      }
    }
    {
      double lo = 0, hi = 1;
      FOR(it, 0, 100) {
        double mi = (lo + hi) / 2;
        double w = v + (u - v) * mi;
        point_t E = D + point_t(cos(w), sin(w)) * r;
        if (r < dist(E, A) + dist(E, C)) {
          lo = mi;
        }
        else {
          hi = mi;
        }
      }
      double mi = (lo + hi) / 2;
      double w = v + (u - v) * mi;
      point_t E = D + point_t(cos(w), sin(w)) * r;
      if (sign(mi) && sign(mi, 1)) {
        assert(!sign(dist(E, A) + dist(E, C), r));
      }
      if (sign(calc(A, B, E), r) <= 0 && sign(calc(B, C, E), r) <= 0 && sign(calc(C, A, E), r) <= 0) {
        return 1;
      }
    }
    return 0;
  };
  double lo = 0, hi = 1e5;
  FOR(i, 0, 3) {
    int j = (i + 1) % 3;
    int k = (j + 1) % 3;
    chkmin(hi, dist(pts[i], pts[j]) + dist(pts[i], pts[k]));
    chkmax(lo, dist(pts[i], pts[j]));
  }
  FOR(it, 0, 100) {
    double mi = (lo + hi) / 2;
    int found = 0;
    FOR(i, 0, 3) {
      int j = (i + 1) % 3;
      int k = (j + 1) % 3;
      if (check(pts[i], pts[j], pts[k], mi)) {
        found = 1;
        break;
      }
    }
    if (!found) {
      lo = mi;
    }
    else {
      hi = mi;
    }
  }
  cout << prec(9) << (lo + hi) / 2 << "\n";
}

int32_t main(int32_t argc, char* argv[]) {
  ios_base::sync_with_stdio(0), cin.tie(0);
  if (argc > 1) {
    assert(freopen(argv[1], "r", stdin));
  }
  if (argc > 2) {
    assert(freopen(argv[2], "wb", stdout));
  }
  chemthan();
  cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
  return 0;
}
