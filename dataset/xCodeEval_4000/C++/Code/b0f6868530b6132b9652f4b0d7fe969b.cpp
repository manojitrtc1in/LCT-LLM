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

const LD kEps = 1e-9;
const LD kPi = 2 * acos(0);
LD Sq(LD x) {
  return x * x;
}
struct Point {
  LD x, y;
  Point() {}
  Point(LD a, LD b) : x(a), y(b) {}
  Point(const Point& a) : x(a.x), y(a.y) {}
  void operator=(const Point& a) { x = a.x; y = a.y; }
  Point operator+(const Point& a) const { Point p(x + a.x, y + a.y); return p; }
  Point operator-(const Point& a) const { Point p(x - a.x, y - a.y); return p; }
  Point operator*(LD a) const { Point p(x * a, y * a); return p; }
  Point operator/(LD a) const { assert(abs(a) > kEps); Point p(x / a, y / a); return p; }
  Point& operator+=(const Point& a) { x += a.x; y += a.y; return *this; }
  Point& operator-=(const Point& a) { x -= a.x; y -= a.y; return *this; }
  Point& operator*=(LD a) { x *= a; y *= a; return *this;}
  Point& operator/=(LD a) { assert(abs(a) > kEps); x /= a; y /= a; return *this; }
  
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
    return sqrt(Sq(x) + Sq(y));
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
  LD SqNorm() {
    return x * x + y * y;
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
    return kPi * Sq(r);
  }
  LD Perimeter() const {
    return 2 * kPi * r;
  }
  LD Diameter() const {
    return 2 * r;
  }
  Point RotateRightMost(LD ang) const {
    return center + Point{r * cos(ang), r * sin(ang)};
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
    LD norm = sqrt(Sq(A) + Sq(B));
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
  

  static vector<Point> InterCircleCircle(Circle a, Circle b) {
    if (a.r + kEps < b.r) {
      swap(a, b);
    }
    if (a == b) {
      return vector<Point>{a.RotateRightMost(0), a.RotateRightMost(2 * kPi / 3),
          a.RotateRightMost(4 * kPi / 3)};
    }
    Point diff = b.center - a.center;
    LD dis = diff.Norm();
    LD ang = diff.Angle();
    LD longest = max(max(a.r, b.r), dis);
    LD per = a.r + b.r + dis;
    if (2 * longest > per + kEps) {
      return vector<Point>();
    }
    if (abs(2 * longest - per) < 2 * kEps) {
      return vector<Point>{a.RotateRightMost(ang)};
    }
    LD ang_dev = acos((Sq(a.r) + Sq(dis) - Sq(b.r)) / (2 * a.r * dis));
    return vector<Point>{a.RotateRightMost(ang - ang_dev), a.RotateRightMost(ang + ang_dev)};
  }
  
  static vector<Point> InterLineLine(Line& a, Line& b) { 

    Point vec_a = a[1] - a[0];
    Point vec_b1 = b[1] - a[0];
    Point vec_b0 = b[0] - a[0]; 
    LD tr_area = vec_b1.CrossProd(vec_b0);
    LD quad_area = vec_b1.CrossProd(vec_a) + vec_a.CrossProd(vec_b0);
    if (abs(quad_area) < kEps) { 

      if (PtBelongToLine(b, a[0])) {
        return {a[0], a[1]};
      } else {
        return {};
      }
    }
    return {a[0] + vec_a * (tr_area / quad_area)};
  } 
  
  static Point ProjPointToLine(Point p, Line l) { 

    Point diff = l[1] - l[0];
    return l[0] + diff * (diff.DotProd(p - l[0]) / diff.DotProd(diff));
  }
  
  static Point ReflectPtWRTLine(Point p, Line l) {
    Point proj = ProjPointToLine(p, l);
    return proj * 2 - p;
  }
  
  static vector<Point> InterCircleLine(Circle c, Line l) { 

    Point proj = ProjPointToLine(c.center, l);
    LD dis_proj = c.center.Dist(proj);
    if (dis_proj > c.r + kEps) { return vector<Point>(); }
    LD a = sqrt(max((LD)0, Sq(c.r) - Sq(dis_proj)));
    Point dir = l[1] - l[0];
    LD dir_norm = dir.Norm();
    vector<Point> cands{proj + dir * (a / dir_norm), proj - dir * (a / dir_norm)};
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

    LD d = c.center.Dist(p);
    if (d < c.r - kEps) { return {}; }
    if (d < c.r + kEps) { return {p}; }
    LD from_cent = (p - c.center).Angle();
    LD ang_dev = acos(c.r / d);
    return {c.RotateRightMost(from_cent - ang_dev), c.RotateRightMost(from_cent + ang_dev)};
  }
  
  

  static vector<Line> OuterTangents(Circle c1, Circle c2) {
    if (c1 == c2) { return {}; } 

    if (c1.r < c2.r) { swap(c1, c2); }
    if (c2.r + c1.center.Dist(c2.center) < c1.r - kEps) { return {}; }
    if (abs(c1.r - c2.r) < kEps) {
      Point diff = c2.center - c1.center;
      Point R = diff.Rotate(kPi / 2) * (c1.r / diff.Norm()); 
      return {{c1.center + R, c2.center + R}, {c1.center - R, c2.center - R}};
    }
    Point I = c1.center + (c2.center - c1.center) * (c1.r / (c1.r - c2.r)); 
    if (c2.r + c1.center.Dist(c2.center) < c1.r + kEps) {
      return {{I, I + (c2.center - c1.center).Rotate(kPi / 2)}};
    }
    vector<Point> to1 = TangencyPtsToCircle(c1, I);
    vector<Point> to2 = TangencyPtsToCircle(c2, I);
    vector<Line> res{{to1[0], to2[0]}, {to1[1], to2[1]}};
    assert(Utils::PtBelongToLine(res[0], I));
    assert(Utils::PtBelongToLine(res[1], I));
    return res;
  }
    
  

  

  

  

  static vector<Line> InnerTangents(Circle c1, Circle c2) {
    if (c1 == c2) { return {}; } 

    if (c1.r < c2.r) { swap(c1, c2); }
    LD d = c1.center.Dist(c2.center);
    if (d < c1.r + c2.r - kEps) { return {}; }
    Point I = c1.center + (c2.center - c1.center) * (c1.r / (c1.r + c2.r));
    if (d < c1.r + c2.r + kEps) {
      return {{I, I + (c2.center - c1.center).Rotate(kPi / 2)}};
    }
    vector<Point> to1 = TangencyPtsToCircle(c1, I);
    vector<Point> to2 = TangencyPtsToCircle(c2, I);
    vector<Line> res{{to1[0], to2[0]}, {to1[1], to2[1]}};
    assert(Utils::PtBelongToLine(res[0], I));
    assert(Utils::PtBelongToLine(res[1], I));
    return res;
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
      vector<Point> p = InterLineLine(l1, l2);
      if (PtBelongToSeg(l1, p[0]) && PtBelongToSeg(l2, p[0])) { return p; }
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
    LD d = c1.center.Dist(c2.center);
    if (c1.r + c2.r < d + kEps) {
      return 0;
    }
    if (c1.r - c2.r > d - kEps) {
      return kPi * Sq(c2.r);
    }
    LD alfa = acos((Sq(d) + Sq(c1.r) - Sq(c2.r)) / (2 * d * c1.r));
    LD beta = acos((Sq(d) + Sq(c2.r) - Sq(c1.r)) / (2 * d * c2.r));
    return alfa * Sq(c1.r) + beta * Sq(c2.r) - sin(2 * alfa) * Sq(c1.r) / 2 - sin(2 * beta) * Sq(c2.r) / 2;
  }
  
  static Line RadAxis(Circle c1, Circle c2) {
    LD d = c1.center.Dist(c2.center);
    LD a = (Sq(c1.r) - Sq(c2.r) + Sq(d)) / (2 * d);
    Point Q = c1.center + (c2.center - c1.center) * (a / d);
    Point R = Q + (c2.center - c1.center).Rotate(kPi / 2);
    return Line(Q, R);
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
  

  

  

  vector<vector<Point>> MakeConvexHull() { 

    vector<vector<Point>> one_way_hull(2);
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
      if (SZ(H) > 1 && (H[0] - H.back()).IsZero()) { H.pop_back(); }
    }
    pts.clear();
    for (auto p : one_way_hull[1]) {
      pts.push_back(p);
    }
    for (int i = SZ(one_way_hull[0]) - 2; i >= 1; i--) {
      pts.push_back(one_way_hull[0][i]);
    }
    return one_way_hull;
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
  
  

  

  

  vector<int> Tangents(Point p) { 

    vector<int> res;
    REP (tr, 2) {
      auto GrThan = [&](int fir, int sec) { 

        return p.CrossProd(pts[sec], pts[fir]) > kEps;
      };
      bool up = false;
      int cr = 0;
      if (SZ(pts) >= 2) { cr = p.CrossProd(pts[0], pts[1]); }
      if (abs(cr) < kEps && SZ(pts) >= 3) { cr = p.CrossProd(pts[0], pts[2]); }
      up = (cr > 0);
      VI bd{1, SZ(pts) - 1};
      int faj = 0;
      while (bd[0] + 6 <= bd[1]) { 

        VI h(2);
        REP (hh, 2) { h[hh] = (bd[0] + bd[1] + bd[hh]) / 3; }
        if (!GrThan(h[up ^ tr], 0) ^ tr) { bd[up ^ tr] = h[up ^ tr]; }
        else {
          int gr = GrThan(h[0], h[1]);
          bd[gr ^ tr] = h[gr ^ tr];
        }
      }
      FOR (i, bd[0], bd[1]) {
        if (GrThan(i, faj) ^ tr) {
          faj = i;
        }
      }
      res.PB(faj);
    }
    return res;
  }
};

struct ConvexPolHalves { 

  vector<vector<Point>> chains; 

  bool BelongTo(Point p) { 

    if (SZ(chains[0]) == 1) {
      return (chains[0][0] - p).IsZero();
    }
    if (p.x  + kEps < chains[0][0].x || p.x - kEps > chains[0].back().x) { return false; }
    REP (tr, 2) {
      int kl = 0, kp = SZ(chains[tr]) - 2, faj = 0;
      while (kl <= kp) {
        int aktc = (kl + kp) / 2;
        if (chains[tr][aktc].x < p.x + kEps) {
          kl = aktc + 1;
          faj = aktc;
        } else {
          kp = aktc - 1;
        }
      }
      Point fir = chains[tr][faj], sec = chains[tr][faj + 1];
      if (abs(fir.x - sec.x) < kEps) {
        if (tr == 0) { if (sec.y + kEps < p.y) { return false; } }
        else { if (fir.y - kEps > p.y) { return false; } }
      } else {
        LD cr = fir.CrossProd(sec, p);
        if (abs(cr) < kEps) { return true; }
        if ((cr > 0) ^ tr) { return false; }
      }
    }
    return true;
  }
};

struct PointInt {
  int x, y;
  PointInt operator-(const PointInt& a) const { return {x - a.x, y - a.y};  }
  int CrossProd(const PointInt& a) const {
    return x * a.y - y * a.x;
  }
  int CrossProd(PointInt a, PointInt b) const {
    a = a - *this;
    b = b - *this;
    return a.CrossProd(b);
  }
};
  

const int N = 2e3 + 5;
PointInt red_int[N], blue_int[N];
Point orig_red[N], orig_blue[N], fake_red[N], fake_blue[N];
    
int32_t main() {

  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  cerr << fixed << setprecision(10);
  cin.tie(0);
  

  
  int red_cnt, blue_cnt;
  cin>>red_cnt>>blue_cnt;
  RE (i, red_cnt) {
    int x, y;
    cin>>x>>y;
    red_int[i] = {x, y};
    orig_red[i] = {(LD)x, (LD)y};
  }
  RE (i, blue_cnt) {
    int x, y;
    cin>>x>>y;
    blue_int[i] = {x, y};
    orig_blue[i] = {(LD)x, (LD)y};
  }
  RE (i, red_cnt) {
    PointInt best = blue_int[1];
    RE (j, blue_cnt) {
      if (red_int[i].CrossProd(blue_int[j], best) <= 0) {
        best = blue_int[j];
      }
    }
    int was_neg = 0, was_pos = 0;
    RE (j, blue_cnt) {
      int cr = red_int[i].CrossProd(best, blue_int[j]);
      if (cr < 0) {
        was_neg = 1;
      }
      if (cr > 0) {
        was_pos = 1;
      }
    }
    if (was_neg == 0 || was_pos == 0) {
      cout<<"-1\n";
      return 0;
    }
  }
  debug("finite");
  
  LD res = 0;
  const int Rad = 1e4;
  function<Point(Point)> Inversion = [&](Point p) {
    LD old_norm = p.Norm();
    LD new_norm = Rad * Rad / old_norm;
    return p * (new_norm / old_norm);
  };
  function<void(Line)> Relax = [&](Line l) {
    Point orig = {0, 0};
    Point proj = Utils::ProjPointToLine(orig, l);
    maxi(res, Rad * Rad / (2 * proj.Norm()));
  };
  
  RE (orig, blue_cnt) {
    RE (i, red_cnt) {
      fake_red[i] = orig_red[i] - orig_blue[orig];
      fake_red[i] = Inversion(fake_red[i]);
    }
    Polygon blue_hull;
    RE (i, blue_cnt) {
      fake_blue[i] = orig_blue[i] - orig_blue[orig];
      if (i != orig) {
        fake_blue[i] = Inversion(fake_blue[i]);
        blue_hull.Add(fake_blue[i]);
      }
    }
    ConvexPolHalves pol_halves{blue_hull.MakeConvexHull()};
    VI mults(SZ(blue_hull.pts));
    RE (i, red_cnt) {
      if (pol_halves.BelongTo(fake_red[i])) { continue; }
      vector<int> tangents = blue_hull.Tangents(fake_red[i]);
      Point L = blue_hull.pts[tangents[0]];
      Point R = blue_hull.pts[tangents[1]];
      Relax({fake_red[i], L});
      Relax({fake_red[i], R});
      mults[tangents[0]]++;
      mults[tangents[1]]--;
      if (tangents[0] > tangents[1]) {
        mults[0]++;
      }
    }
    int cur = 0;
    REP (i, SZ(blue_hull.pts)) {
      cur += mults[i];
      assert(cur >= 0);
      if (cur) {
        Relax({blue_hull.pts[i], blue_hull.pts[blue_hull.next(i)]});
      }
    }
  }
  cout<<res<<endl;
      
      
    
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  return 0;
}