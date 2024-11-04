














using namespace std;
template<typename TH> void _dbg(const char* sdbg, TH h) { cerr<<sdbg<<"="<<h<<"\n"; }
template<typename TH, typename... TA> void _dbg(const char* sdbg, TH h, TA... t) {
  while(*sdbg != ',')cerr<<*sdbg++; cerr<<"="<<h<<","; _dbg(sdbg+1, t...);
}












typedef long long ll;
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
template<class T> ostream& operator<<(ostream& out, set<T> vec) { out<<"("; for (auto& v: vec) out<<v<<", "; return out<<")"; }
template<class L, class R> ostream& operator<<(ostream& out, map<L, R> vec) { out<<"("; for (auto& v: vec) out<<v<<", "; return out<<")"; }

typedef int LD;
const LD id7 = 1e-9;
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
  Point operator/(LD a) const { assert(abs(a) > id7); Point p(x / a, y / a); return p; }
  Point& operator+=(const Point& a) { x += a.x; y += a.y; return *this; }
  Point& operator-=(const Point& a) { x -= a.x; y -= a.y; return *this; }
  Point& operator*=(LD a) { x *= a; y *= a; return *this;}
  Point& operator/=(LD a) { assert(abs(a) > id7); x /= a; y /= a; return *this; }
  
  bool IsZero() const {
    return abs(x) < id7 && abs(y) < id7;
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
    if (abs(a.x - b.x) > id7) {
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
    return center == c.center && abs(r - c.r) < id7;
  }
};

struct Line {
  Point p[2];
  bool is_seg;
  Line(Point a, Point b, bool id6 = false) {
    p[0] = a;
    p[1] = b;
    is_seg = id6;
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
    assert(abs(A * p[1].x + B * p[1].y + C) < id7);
    LD norm = sqrt(Sq(A) + Sq(B));
    vector<LD> res{A, B, C};
    for (auto& x : res) { x /= norm; }
    if (A < -id7 || (abs(A) < id7 && B < -id7)) {
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
    if (a.r + id7 < b.r) {
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
    if (2 * longest > per + id7) {
      return vector<Point>();
    }
    if (abs(2 * longest - per) < 2 * id7) {
      return vector<Point>{a.RotateRightMost(ang)};
    }
    LD ang_dev = acos((Sq(a.r) + Sq(dis) - Sq(b.r)) / (2 * a.r * dis));
    return vector<Point>{a.RotateRightMost(ang - ang_dev), a.RotateRightMost(ang + ang_dev)};
  }
  
  static vector<Point> InterLineLine(Line& a, Line& b) { 

    Point vec_a = a[1] - a[0];
    Point id2 = b[1] - a[0];
    Point id4 = b[0] - a[0]; 
    LD tr_area = id2.CrossProd(id4);
    LD quad_area = id2.CrossProd(vec_a) + vec_a.CrossProd(id4);
    if (abs(quad_area) < id7) { 

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
    if (dis_proj > c.r + id7) { return vector<Point>(); }
    LD a = sqrt(max((LD)0, Sq(c.r) - Sq(dis_proj)));
    Point dir = l[1] - l[0];
    LD dir_norm = dir.Norm();
    vector<Point> cands{proj + dir * (a / dir_norm), proj - dir * (a / dir_norm)};
    if (cands[0].Dist(cands[1]) < id7) { return vector<Point>{proj}; }
    return cands;
  }
  
  static bool PtBelongToLine(Line l, Point p) {
    return abs(l[0].CrossProd(l[1], p)) < id7;
  }
  
  static bool PtBelongToSeg(Line l, Point p) { 

    return abs(p.Dist(l[0]) + p.Dist(l[1]) - l[0].Dist(l[1])) < id7;
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
    if (d < c.r - id7) { return {}; }
    if (d < c.r + id7) { return {p}; }
    LD from_cent = (p - c.center).Angle();
    LD ang_dev = acos(c.r / d);
    return {c.RotateRightMost(from_cent - ang_dev), c.RotateRightMost(from_cent + ang_dev)};
  }
  
  

  static vector<Line> OuterTangents(Circle c1, Circle c2) {
    if (c1 == c2) { return {}; } 

    if (c1.r < c2.r) { swap(c1, c2); }
    if (c2.r + c1.center.Dist(c2.center) < c1.r - id7) { return {}; }
    if (abs(c1.r - c2.r) < id7) {
      Point diff = c2.center - c1.center;
      Point R = diff.Rotate(kPi / 2) * (c1.r / diff.Norm()); 
      return {{c1.center + R, c2.center + R}, {c1.center - R, c2.center - R}};
    }
    Point I = c1.center + (c2.center - c1.center) * (c1.r / (c1.r - c2.r)); 
    if (c2.r + c1.center.Dist(c2.center) < c1.r + id7) {
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
    if (d < c1.r + c2.r - id7) { return {}; }
    Point I = c1.center + (c2.center - c1.center) * (c1.r / (c1.r + c2.r));
    if (d < c1.r + c2.r + id7) {
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

    return abs(l1[0].CrossProd(l2[0], l1[1]) - l1[0].CrossProd(l2[1], l1[1])) < id7;
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
    if (ans < id7) {
      ans += 2 * kPi;
    }
    return ans;
  }
  
  

  

  

  static LD DiskInterArea(Circle c1, Circle c2) { 

    if (c1.r < c2.r) {
      swap(c1, c2);
    }
    LD d = c1.center.Dist(c2.center);
    if (c1.r + c2.r < d + id7) {
      return 0;
    }
    if (c1.r - c2.r > d - id7) {
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

    vector<vector<Point>> id3(2);
    sort(pts.begin(), pts.end(), Point::LexCmp);
    for (int dir = -1; dir <= 1; dir += 2) {
      int id0 = (dir + 1) / 2;
      auto& H = id3[id0];
      id3[id0].push_back(pts[0]);
      if (SZ(pts) > 1) {
        H.push_back(pts[1]);
      }
      for (int i = 2; i < SZ(pts); i++) {
        while (SZ(H) >= 2 &&
            dir * (pts[i] - H[SZ(H) - 2]).CrossProd(H.back() - H[SZ(H) - 2]) >= 0) {
          H.pop_back();
        }
        H.push_back(pts[i]);
      }
      if (SZ(H) > 1 && (H[0] - H.back()).IsZero()) { H.pop_back(); }
    }
    pts.clear();
    for (auto p : id3[1]) {
      pts.push_back(p);
    }
    for (int i = SZ(id3[0]) - 2; i >= 1; i--) {
      pts.push_back(id3[0][i]);
    }
    return id3;
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
        if (areas[0] * areas[1] < id7) {
          res[i][j] = 0;
        }
      }
    }
    return res;
  }
  
  

  

  

  vector<Point> Tangents(Point p) { 

    vector<Point> res;
    REP (tr, 2) {
      auto GrThan = [&](int fir, int sec) { 

        return p.CrossProd(pts[sec], pts[fir]) > id7;
      };
      bool up = false;
      int cr = 0;
      if (SZ(pts) >= 2) { cr = p.CrossProd(pts[0], pts[1]); }
      if (abs(cr) < id7 && SZ(pts) >= 3) { cr = p.CrossProd(pts[0], pts[2]); }
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
      res.PB(pts[faj]);
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
    if (p.x  + id7 < chains[0][0].x || p.x - id7 > chains[0].back().x) { return false; }
    REP (tr, 2) {
      int kl = 0, kp = SZ(chains[tr]) - 2, faj = 0;
      while (kl <= kp) {
        int aktc = (kl + kp) / 2;
        if (chains[tr][aktc].x < p.x + id7) {
          kl = aktc + 1;
          faj = aktc;
        } else {
          kp = aktc - 1;
        }
      }
      Point fir = chains[tr][faj], sec = chains[tr][faj + 1];
      if (abs(fir.x - sec.x) < id7) {
        if (tr == 0) { if (sec.y + id7 < p.y) { return false; } }
        else { if (fir.y - id7 > p.y) { return false; } }
      } else {
        LD cr = fir.CrossProd(sec, p);
        if (abs(cr) < id7) { return true; }
        if ((cr > 0) ^ tr) { return false; }
      }
    }
    return true;
  }
};



bool InUpper(Point a) {
  if (abs(a.y) > id7) {
    return a.y > 0;
  }
  return a.x > 0;
}

bool angle_cmp(const Point a, const Point b) {
  bool u = InUpper(a);
  bool v = InUpper(b);
  return u!=v ? u : a.CrossProd(b)>0;
}


LD cross(Point a, Point b, Point c, Point d) {
  return (d - c).CrossProd(a - c) / (d - c).CrossProd(a - b);
}

struct ClipLine { 

  ClipLine(Point A, Point B) : al(A), bl(B), a(A), b(B) {};
  Point al,bl; 

  mutable Point a,b; 

  Point dir() const { return bl - al; }
  bool operator<(const ClipLine& l) const { return angle_cmp(dir(),l.dir()); }
  Point cross(const ClipLine& l) {
    return al + (bl - al) * ::cross(al, bl, l.al, l.bl);
  }
  bool left(Point p) {
    return (bl - al).CrossProd(p - al) > 0;
  }
};

struct Clip {
  Clip(LD r) : area(4*r*r) {
    Point a{-r,-r}, b{r,-r}, c{r,r}, d{-r,r};
    lines = {ClipLine(a,b), ClipLine(b,c), ClipLine(c,d), ClipLine(d,a)};
  }

  void insert(Line l) { insert(ClipLine(l[0], l[1])); }
  
  void insert(ClipLine l) {
    assert(abs(l.dir().SqNorm()) > id7);
    find(l);
    while (size() && !l.left(it->a) && !l.left(it->b)) { erase(); }
    if (size()) {
      while (prev(), size() && !l.left(it->a) && !l.left(it->b)) { erase(); }
    }
    if (size() && (!l.left(it->a) || !l.left(it->b))) {
      l.a = l.cross(*it);
      area -= l.a.CrossProd(it->b)*.5; it->b = l.a; next();
      l.b = l.cross(*it);
      if ((l.a-l.b).SqNorm() < id7) {
        l.b = l.a;
      }
      area -= it->a.CrossProd(l.b) * .5;
      it->a = l.b;
      if (!(l.a - l.b).IsZero()) {
        area += l.a.CrossProd(l.b)*.5;
        lines.insert(l);
      }
    }
    

  }

  void find(const ClipLine &l) {
    it = lines.lower_bound(l);
    if (it == lines.end()) { it = lines.begin(); }
  }

  void recalculate() {
    area = 0; for (const ClipLine &l : lines) area += l.a.CrossProd(l.b);
    area *= .5;
  }

  int size() { return lines.size(); }
  void next() { if(++it==lines.end()) it = lines.begin(); }
  void prev() { if(it==lines.begin()) it = lines.end(); --it; }
  void erase() {
      assert(it!=lines.end());
      area -= it->a.CrossProd(it->b)*.5;
      it = lines.erase(it);
      if(it==lines.end()) it = lines.begin();
  }
  typename set<ClipLine>::iterator it;
  set<ClipLine> lines;
  LD area;
};





Point Bary(Point A, Point B, Point C, LD a, LD b, LD c) {
    return (A * a + B * b + C * c) / (a + b + c);
}

Point Centroid(Point A, Point B, Point C) {
    return Bary(A, B, C, 1, 1, 1);
}

Point id1(Point A, Point B, Point C) {
    LD a = (B - C).SqNorm(), b = (C - A).SqNorm(), c = (A - B).SqNorm();
    return Bary(A, B, C, a * (b + c - a), b * (c + a - b), c * (a + b - c));
}

Point Incenter(Point A, Point B, Point C) {
    return Bary(A, B, C, (B - C).Norm(), (A - C).Norm(), (A - B).Norm());
}

Point id5(Point A, Point B, Point C) {
    LD a = (B - C).SqNorm(), b = (C - A).SqNorm(), c = (A - B).SqNorm();
    return Bary(A, B, C, (a+b-c)*(c+a-b), (b+c-a)*(a+b-c), (c+a-b)*(b+c-a));
}

Point Excenter(Point A, Point B, Point C) { 

    LD a = (B - C).Norm(), b = (A - C).Norm(), c = (A - B).Norm();
    return Bary(A, B, C, -a, b, c);
}

VI ToVI(Polygon& poly) {
  vector<Point>& pts = poly.pts;
  int n = SZ(pts);
  pts.PB(pts[0]);
  pts.PB(pts[1]);
  VI res;
  RE (i, n) {
    Point D = pts[i] - pts[i - 1];
    res.PB(Sq(D.x) + Sq(D.y));
    res.PB(pts[i - 1].CrossProd(pts[i], pts[i + 1]));
  }
  return res;
}

int32_t main() {

  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  cerr << fixed << setprecision(10);
  cin.tie(0);
  

  
  int nn, mm;
  cin>>nn>>mm;
  VI ns{nn, mm};
  vector<Polygon> polys(2);
  REP (tr, 2) {
    REP (d, ns[tr]) {
      int x, y;
      cin>>x>>y;
      polys[tr].Add({x, y});
    }
    polys[tr].MakeConvexHull();
  }
  debug(polys[0].pts, polys[1].pts);
  VI s1 = ToVI(polys[0]);
  VI s2 = ToVI(polys[1]);
  debug(s1, s2);
  
  if (SZ(s1) != SZ(s2)) {
    cout<<"NO\n";
    return 0;
  }
  int n = SZ(s2);
  s2.PB(-1);
  REP (tr, 2) {
    REP (i, n) {
      s2.PB(s1[i]);
    }
  }
  s2.PB(-2);
  s2.insert(s2.begin(), -3);
  int m = 2 * n;
  

    

  VI& wz = s2;
  
    int dl=m+n+1;
  debug(dl, SZ(wz));  
  VI pre(dl + 2);
    for(int i=2; i<=dl; i++)
    {
        int akt=pre[i-1];
        while(wz[akt+1]!=wz[i] && akt)
        {
            akt=pre[akt];
        }
        if(wz[akt+1]==wz[i])
        {
            pre[i]=akt+1;
        }
    }
    for(int i=n+1; i<=dl; i++)
    {
        if(pre[i]==n)
        {
            cout<<"YES\n";
            return 0;
        }
    }
  cout<<"NO\n";
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  return 0;
}