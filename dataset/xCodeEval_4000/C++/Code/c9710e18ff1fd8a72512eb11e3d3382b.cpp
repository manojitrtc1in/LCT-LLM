#include <bits/stdc++.h>
#define MP make_pair
#define PB push_back
#define int long long
#define st first
#define nd second
#define rd third
#define FOR(i, a, b) for(int i =(a); i <=(b); ++i)
#define RE(i, n) FOR(i, 1, n)
#define FORD(i, a, b) for(int i = (a); i >= (b); --i)
#define REP(i, n) for(int i = 0;i <(n); ++i)
#define VAR(v, i) __typeof(i) v=(i)
#define FORE(i, c) for(VAR(i, (c).begin()); i != (c).end(); ++i)
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
using namespace std;
template<typename TH> void _dbg(const char* sdbg, TH h) { cerr<<sdbg<<"="<<h<<"\n"; }
template<typename TH, typename... TA> void _dbg(const char* sdbg, TH h, TA... t) {
  while(*sdbg != ',')cerr<<*sdbg++; cerr<<"="<<h<<","; _dbg(sdbg+1, t...);
}
#ifdef LOCAL
#define debug(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
#define debugv(x) {{cerr <<#x <<" = "; FORE(itt, (x)) cerr <<*itt <<", "; cerr <<"\n"; }}
#else
#define debug(...) (__VA_ARGS__)
#define debugv(x)
#define cerr if(0)cout
#endif
#define make(type, x) type x; cin>>x;
#define make2(type, x, y) type x, y; cin>>x>>y;
#define make3(type, x, y, z) type x, y, z; cin>>x>>y>>z;
#define make4(type, x, y, z, t) type x, y, z, t; cin>>x>>y>>z>>t;
#define next ____next
#define prev ____prev
#define left ____left
#define hash ____hash
typedef long long ll;
typedef long double LD;
typedef pair<int, int> PII;
typedef pair<ll, ll> PLL;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<ll> VLL;
typedef vector<pair<int, int> > VPII;
typedef vector<pair<ll, ll> > VPLL;

template<class C> void mini(C&a4, C b4){a4=min(a4, b4); }
template<class C> void maxi(C&a4, C b4){a4=max(a4, b4); }
template<class T1, class T2>
ostream& operator<< (ostream &out, pair<T1, T2> pair) { return out << "(" << pair.first << ", " << pair.second << ")";}
template<class A, class B, class C> struct Triple { A first; B second; C third;
  bool operator<(const Triple& t) const { if (st != t.st) return st < t.st; if (nd != t.nd) return nd < t.nd; return rd < t.rd; } };
template<class T> void ResizeVec(T&, vector<int>) {}
template<class T> void ResizeVec(vector<T>& vec, vector<int> sz) {
  vec.resize(sz[0]); sz.erase(sz.begin()); if (sz.empty()) { return; }
  for (T& v : vec) { ResizeVec(v, sz); }
}
typedef Triple<int, int, int> TIII;
template<class A, class B, class C>
ostream& operator<< (ostream &out, Triple<A, B, C> t) { return out << "(" << t.st << ", " << t.nd << ", " << t.rd << ")"; }
template<class T> ostream& operator<<(ostream& out, vector<T> vec) { out<<"("; for (auto& v: vec) out<<v<<", "; return out<<")"; }

typedef long double LD;
const LD kEps = 1e-9;
const LD kPi = 2 * acos(0);
struct Point {
  LD x, y;
  Point(LD a = 0, LD b = 0) : x(a), y(b) {}
  Point(const Point& a) : x(a.x), y(a.y) {}
  void operator=(const Point& a) { x = a.x; y = a.y; }
  Point operator+(const Point& a) const { Point p(x + a.x, y + a.y); return p; }
  Point operator-(const Point& a) const { Point p(x - a.x, y - a.y); return p; }
  Point operator*(LD a) const { Point p(x * a, y * a); return p; }
  Point operator/(LD a) const { assert(a > kEps); Point p(x / a, y / a); return p; }
  Point& operator+=(const Point& a) { x += a.x; y += a.y; return *this; }
  Point& operator-=(const Point& a) { x -= a.x; y -= a.y; return *this; }
  Point& operator*=(LD a) { x *= a; y *= a; return *this;}
  Point& operator/=(LD a) { assert(a > kEps); x /= a; y /= a; return *this; }
  
  bool IsZero() const {
    return abs(x) < kEps && abs(y) < kEps;
  }
  bool operator==(const Point& a) const {
    return (*this - a).IsZero();
  }
  LD CrossProd(const Point& a) const {
    return x * a.y - y * a.x;
  }
  LD CrossProd(Point a, Point b) const {
    a -= *this;
    b -= *this;
    return a.CrossProd(b);
  }
  LD DotProd(const Point& a) const {
    return x * a.x + y * a.y;
  }
  LD Norm() const {
    return sqrt(x * x + y * y);
  }
  void NormalizeSelf() {
    *this /= Norm();
  }
  Point Normalize() {
    Point res(*this);
    res.NormalizeSelf();
    return res;
  }
  LD Dist(const Point& a) const {
    return (*this - a).Norm();
  }
  LD Angle() const {
    return atan2(y, x);
  }
  void RotateSelf(LD angle) {
    LD c = cos(angle);
    LD s = sin(angle);
    LD nx = x * c - y * s;
    LD ny = y * c + x * s;
    y = ny;
    x = nx;
  }
  Point Rotate(LD angle) const {
    Point res(*this);
    res.RotateSelf(angle);
    return res;
  }
  static bool LexCmp(const Point& a, const Point& b) {
    if (abs(a.x - b.x) > kEps) {
      return a.x < b.x;
    }
    return a.y < b.y;
  }
  friend ostream& operator<<(ostream& out, Point m);
};

ostream& operator<<(ostream& out, Point p) {
  out << "(" << p.x << ", " << p.y << ")";
  return out;
}

struct Circle {
  Point center;
  LD r;
  Circle(LD x, LD y, LD rad) {
    center = Point(x, y);
    r = rad;
  }
  Circle(const Point& a, LD rad) : center(a), r(rad) {}
  LD Area() const {
    return kPi * r * r;
  }
  LD Perimeter() const {
    return 2 * kPi * r;
  }
  LD Diameter() const {
    return 2 * r;
  }
  Point RotateRightMost(LD ang) const {
    Point right_most(r, 0);
    Point res = right_most.Rotate(ang);
    return center + res;
  }
  bool operator==(const Circle& c) const {
    return center == c.center && abs(r - c.r) < kEps;
  }
};

struct Line {
  Point p[2];
  bool is_seg;
  Line(Point a, Point b, bool is_seg_ = false) {
    p[0] = a;
    p[1] = b;
    is_seg = is_seg_;
  }
  Line() {
  }
  Point& operator[](int a) {
    return p[a];
  }
  static bool VectorsInOneHalfPlaneCmp(Line a, Line b) {
    return (a[1] - a[0]).CrossProd(b[1] - b[0]) > 0;
  }
  Point NormalVector() {
    Point perp = p[1] - p[0];
    perp.RotateSelf(kPi / 2);
    perp.NormalizeSelf();
    return perp;
  }
  
  

  vector<LD> LineEqNormLD() { 

    LD A = p[1].y - p[0].y;
    LD B = p[0].x - p[1].x;
    LD C = -(A * p[0].x + B * p[0].y);
    assert(abs(A * p[1].x + B * p[1].y + C) < kEps);
    LD norm = sqrt(A * A + B * B);
    vector<LD> res{A, B, C};
    for (auto& x : res) { x /= norm; }
    if (A < -kEps || (abs(A) < kEps && B < -kEps)) {
      for (auto& x : res) { x *= -1; }
    }
    return res;
  }
  
  

  vector<int> LineEqNormInt() { 

    int A = round(p[1].y - p[0].y);
    int B = round(p[0].x - p[1].x);
    int C = -(A * p[0].x + B * p[0].y);
    int gcd = abs(__gcd(A, __gcd(B, C)));
    vector<int> res{A, B, C};
    for (auto& x : res) { x /= gcd; }
    if (A < 0 || (A == 0 && B < 0)) {
      for (auto& x : res) { x *= -1; }
    }
    return res;
  }
};

struct Utils {
  

  

  static vector<Point> InterCircleCircle(Circle& a, Circle& b) {
    Circle* c = &a;
    Circle* d = &b;
    if (a.r + kEps < b.r) {
      swap(c, d);
    }
    if (a == b) {
      return vector<Point>{a.RotateRightMost(0), a.RotateRightMost(2 * kPi / 3),
          a.RotateRightMost(4 * kPi / 3)};
    }
    Point diff = d->center - c->center;
    LD dis = diff.Norm();
    LD ang = diff.Angle();
    LD longest = max(max(c->r, d->r), dis);
    if (2 * longest > c->r + d->r + dis + kEps) {
      return vector<Point>();
    }
    if (abs(2 * longest - c->r - d->r - dis) < 2 * kEps) {
      return vector<Point>{c->RotateRightMost(ang)};
    }
    LD proj_diff = (c->r * c->r - d->r * d->r) / dis;
    LD r1_proj = (dis + proj_diff) / 2;
    LD ang_deviation = acos(r1_proj / c->r);
    LD ang1 = ang - ang_deviation;
    LD ang2 = ang + ang_deviation;
    return vector<Point>{c->RotateRightMost(ang1), c->RotateRightMost(ang2)};
  }
  
  

  static Point InterLineLine(Line& a, Line& b) { 

    Point vec_a = a[1] - a[0];
    Point vec_b1 = b[1] - a[0];
    Point vec_b0 = b[0] - a[0]; 
    LD tr_area = vec_b1.CrossProd(vec_b0);
    LD quad_area = vec_b1.CrossProd(vec_a) + vec_a.CrossProd(vec_b0);






    return Point(a[0] + vec_a * (tr_area / quad_area));
  }








































    
    
  

  static Point ProjPointToLine(Point p, Line l) { 

    l[0] -= p;
    l[1] -= p;
    Point normal = l.NormalVector();
    normal *= normal.DotProd(l[0]);
    return normal + p;
  }
  
  static Point ReflectPtWRTLine(Point p, Line l) {
    Point proj = ProjPointToLine(p, l);
    return proj * 2 - p;
  }
  
  static vector<Point> InterCircleLine(Circle c, Line l) { 

    Point proj = ProjPointToLine(c.center, l);
    LD dis_proj = c.center.Dist(proj);
    if (dis_proj > c.r + kEps) { return vector<Point>(); }
    LD a = sqrt(c.r * c.r - dis_proj * dis_proj);
    Point dir = l[1] - l[0];
    dir.NormalizeSelf();
    vector<Point> cands{proj + dir * a, proj - dir * a};
    if (cands[0].Dist(cands[1]) < kEps) { return vector<Point>{proj}; }
    return cands;
  }
  
  static bool PtBelongToLine(Line l, Point p) {
    return abs(l[0].CrossProd(l[1], p)) < kEps;
  }
  
  static bool PtBelongToSeg(Line l, Point p) { 

    return abs(p.Dist(l[0]) + p.Dist(l[1]) - l[0].Dist(l[1])) < kEps;
  }
  
  static vector<Point> InterCircleSeg(Circle c, Line l) { 

    vector<Point> from_line = InterCircleLine(c, l);
    vector<Point> res;
    for (auto p : from_line) {
      if (PtBelongToSeg(l, p)) { res.PB(p); }
    }
    return res;
  }
  
  static vector<Point> TangencyPtsToCircle(Circle c, Point p) { 

    assert(c.center.Dist(p) > c.r + kEps); 

    Point mid = (c.center + p) / 2;
    Circle aux_circ = Circle(mid, c.center.Dist(p) / 2);
    return InterCircleCircle(aux_circ, c);
  }
  
  static bool AreParallel(Line l1, Line l2) { 

    return abs(l1[0].CrossProd(l2[0], l1[1]) - l1[0].CrossProd(l2[1], l1[1])) < kEps;
  }
  
  

  

  static vector<Point> InterSegs(Line l1, Line l2) { 

    if (!Point::LexCmp(l1[0], l1[1])) { swap(l1[0], l1[1]); }
    if (!Point::LexCmp(l2[0], l2[1])) { swap(l2[0], l2[1]); }
    if (AreParallel(l1, l2)) {
      if (!PtBelongToLine(l1, l2[0])) { return vector<Point>(); }
      vector<Point> ends(2);
      for (int tr = 0; tr < 2; tr++) {
        if (Point::LexCmp(l1[tr], l2[tr]) ^ tr) {
          ends[tr] = l2[tr];
        } else {
          ends[tr] = l1[tr];
        }
      }
      if ((ends[1] - ends[0]).IsZero()) {
        ends.pop_back();
      }
      if (SZ(ends) == 2 && Point::LexCmp(ends[1], ends[0])) { return vector<Point>(); }
      return ends;
    } else {
      Point p = InterLineLine(l1, l2);
      if (PtBelongToSeg(l1, p) && PtBelongToSeg(l2, p)) { return vector<Point>{p}; }
      return vector<Point>();
    }
  }
  static LD Angle(Point P, Point Q, Point R) { 

    LD ang2 = (P - Q).Angle();
    LD ang1 = (R - Q).Angle();
    LD ans = ang1 - ang2;
    if (ans < kEps) {
      ans += 2 * kPi;
    }
    return ans;
  }
  
  

  static LD DiskInterArea(Circle c1, Circle c2) { 

    if (c1.r < c2.r) {
      swap(c1, c2);
    }
    LD dist = c1.center.Dist(c2.center);
    if (c1.r + c2.r < dist + kEps) {
      return 0;
    }
    if (c1.r - c2.r > dist - kEps) {
      return kPi * c2.r * c2.r;
    }
    vector<Point> inters = Utils::InterCircleCircle(c1, c2);
    LD cross = (inters[0] - c1.center).CrossProd(inters[1] - c1.center);
    if (cross < kEps) {
      swap(inters[0], inters[1]);
    }
    LD res = 0;
    LD ang1 = Angle(inters[0], c1.center, inters[1]);
    res += ang1 * c1.r * c1.r;
    LD ang2 = Angle(inters[1], c2.center, inters[0]);
    res += ang2 * c2.r * c2.r;
    res -= (inters[0] - c1.center).CrossProd(inters[1] - c1.center) + (inters[1] - c2.center).CrossProd(inters[0] - c2.center);
    return res / 2;
  }
};

struct Polygon {
  vector<Point> pts;
  Polygon(vector<Point> pts_) : pts(pts_) {}
  Polygon() : Polygon(vector<Point>()) {}
  void Add(Point p) {
    pts.push_back(p);
  }
  double Area() {
    double area = 0;
    for (int i = 0; i < SZ(pts); i++) {
      area += pts[i].CrossProd(pts[(i + 1) % SZ(pts)]);
    }
    area /= 2;
    return area;
  }
  void OrientCounterclockwise() {
    if (Area() < 0) {
      reverse(pts.begin(), pts.end());
    }
  }
  int next(int a) {
    if (a + 1 < SZ(pts)) {
      return a + 1;
    }
    return 0;
  }
  pair<int, int> FurthestPair() { 

    MakeConvexHull();
    OrientCounterclockwise();
    int furth = 1;
    pair<int, int> best_pair = make_pair(0, 0);
    double best_dis = 0;
    for (int i = 0; i < SZ(pts); i++) {
      Point side = pts[next(i)] - pts[i];
      while (side.CrossProd(pts[furth] - pts[i]) < side.CrossProd(pts[next(furth)] - pts[i])) {
        furth = next(furth);
      }
      vector<int> vec{i, next(i)};
      for (auto ind : vec) {
        if (pts[ind].Dist(pts[furth]) > best_dis) {
          best_pair = make_pair(ind, furth);
          best_dis = pts[ind].Dist(pts[furth]);
        }
      }
      cerr<<"Furthest from: "<<pts[i]<<"-"<<pts[next(i)]<<" is "<<pts[furth]<<endl;
    }
    return best_pair;
  }
  void MakeConvexHull() { 

    vector<Point> one_way_hull[2];
    sort(pts.begin(), pts.end(), Point::LexCmp);
    for (int dir = -1; dir <= 1; dir += 2) {
      int hull_num = (dir + 1) / 2;
      auto& H = one_way_hull[hull_num];
      one_way_hull[hull_num].push_back(pts[0]);
      if (SZ(pts) > 1) {
        H.push_back(pts[1]);
      }
      for (int i = 2; i < SZ(pts); i++) {
        while (SZ(H) >= 2 &&
            dir * (pts[i] - H[SZ(H) - 2]).CrossProd(H.back() - H[SZ(H) - 2]) > -kEps) {
          H.pop_back();
        }
        H.push_back(pts[i]);
      }
    }
    pts.clear();
    for (auto p : one_way_hull[1]) {
      pts.push_back(p);
    }
    for (int i = SZ(one_way_hull[0]) - 2; i >= 1; i--) {
      pts.push_back(one_way_hull[0][i]);
    }
  }
  vector<vector<bool>> InsideDiagonalsMatrix() { 

    int n = pts.size();
    vector<vector<bool>> res(n, vector<bool>(n));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        Line diag(pts[i], pts[j]);
        if (i == j || abs(i - j) == 1 || abs(i - j) == n - 1) { continue; }
        res[i][j] = 1;
        for (int k = 0; k < n; k++) {
          int kk = next(k);
          Line side(pts[k], pts[kk]);
          if (k == i || k == j || kk == i || kk == j) { continue; }
          vector<Point> inter = Utils::InterSegs(diag, side);
          if (SZ(inter)) { res[i][j] = 0; }
        }
        int act = next(i);
        LD areas[2] = {0, 0};
        int passed_j = 0;
        while (act != i) {
          passed_j |= (act == j);
          areas[passed_j] += pts[i].CrossProd(pts[act], pts[next(act)]);
          act = next(act);
        }
        if (areas[0] * areas[1] < kEps) {
          res[i][j] = 0;
        }
      }
    }
    return res;
  }
};

const int N = 5e4 + 5;
Line l[N];
int was[N];
const int M = 1 << 17;
int drz[M];
int magic(int n) {
  return n - (n & (n - 1));
}
void Add(int a, int v) {
  while (a < M) {
    drz[a] += v;
    a += magic(a);
  }
}
int Sum(int a) {
  int sum = 0;
  while (a) {
    sum += drz[a];
    a -= magic(a);
  }
  return sum;
}
#undef int
int main() {
#define int long long

  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  cerr << fixed << setprecision(1);
  cin.tie(0);
  

  
  int n;
  cin>>n;
  int m;
  LD x, y;
  cin>>x>>y>>m;
  x /= 1000;
  y /= 1000;
  Point q{x, y};
  RE (i, n) {
    LD a, b;
    cin>>a>>b;
    a /= 1000;
    b /= 1000;
    l[i] = {{0, b}, {1, a + b}};
  }
  LD kl = 0, kp = 1e10;
  int max_iter = 100;
  RE (iter, max_iter) {
    LD aktc = (kl + kp) / 2;
    Circle c{q, aktc};
    vector<pair<LD, int>> evs;
    RE (i, n) {
      vector<Point> inters = Utils::InterCircleLine(c, l[i]);
      if (SZ(inters) == 2) {
        REP (tr, 2) {
          evs.PB({(inters[tr] - q).Angle(), i});
        }
      }
    }
    sort(ALL(evs));
    LD sum = 0;
    LD found = 0;
    set<PII> secik;
    debugv(evs);
    for (int ii = 0; ii < SZ(evs); ii++) {
      int nr = evs[ii].nd;
      if (was[nr]) {
        Add(was[nr], -1);
        found += Sum(ii + 1) - Sum(was[nr]);
        if (max_iter == iter) {
          secik.erase({-was[nr], nr});
          for (auto it : secik) {
            if (it.st > -was[nr]) {
              break;
            }
            LD diss = q.Dist(Utils::InterLineLine(l[it.nd], l[nr]));
            if (diss > 1e-7) {
              sum += diss;
            }
          }
        }
        was[nr] = 0;
      } else {
        was[nr] = ii + 1;
        if (max_iter == iter) {
          secik.insert({-was[nr], nr});      
        }
        Add(was[nr], 1);
      }
    }
    debug(aktc, found, kl, kp);
    if (iter == max_iter) {
      debug(aktc);
      if (aktc > 1e-9) {
        cout<<sum + (m - found) * aktc<<endl;
      } else {
        cout<<"0\n";
      }
    }
    if (found < m) {
      kl = aktc;
    } else {
      kp = aktc;
    }
  }
  return 0;
}
