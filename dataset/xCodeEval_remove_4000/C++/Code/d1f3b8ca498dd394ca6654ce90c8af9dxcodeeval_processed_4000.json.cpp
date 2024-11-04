














using namespace std;
template<typename TH> void _dbg(const char* sdbg, TH h) { cerr<<sdbg<<"="<<h<<"\n"; }
template<typename TH, typename... TA> void _dbg(const char* sdbg, TH h, TA... t) {
  while(*sdbg != ',')cerr<<*sdbg++; cerr<<"="<<h<<","; _dbg(sdbg+1, t...);
}
















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
const LD id7 = 1e-12;
const LD kPi = 2 * acos(0);
struct Point {
  LD x, y;
  Point(LD a = 0, LD b = 0) : x(a), y(b) {}
  Point(const Point& a) : x(a.x), y(a.y) {}
  void operator=(const Point& a) { x = a.x; y = a.y; }
  Point operator+(const Point& a) const { Point p(x + a.x, y + a.y); return p; }
  Point operator-(const Point& a) const { Point p(x - a.x, y - a.y); return p; }
  Point operator*(LD a) const { Point p(x * a, y * a); return p; }
  Point operator/(LD a) const { assert(a > id7); Point p(x / a, y / a); return p; }
  Point& operator+=(const Point& a) { x += a.x; y += a.y; return *this; }
  Point& operator-=(const Point& a) { x -= a.x; y -= a.y; return *this; }
  Point& operator*=(LD a) { x *= a; y *= a; return *this;}
  Point& operator/=(LD a) { assert(a > id7); x /= a; y /= a; return *this; }
  
  bool IsZero() const {
    return fabs(x) < id7 && fabs(y) < id7;
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
    if (fabs(a.x - b.x) > id7) {
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
 
struct Line {
  Point p[2];
  Point diff;
  bool is_seg;
  Line(Point a, Point b, bool id6 = false) {
    p[0] = a;
    p[1] = b;
    is_seg = id6;
    diff = b - a;
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
    assert(fabs(A * p[1].x + B * p[1].y + C) < id7);
    LD norm = sqrt(A * A + B * B);
    vector<LD> res{A, B, C};
    for (auto& x : res) { x /= norm; }
    if (A < -id7 || (fabs(A) < id7 && B < -id7)) {
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
    Point id2(r, 0);
    Point res = id2.Rotate(ang);
    return center + res;
  }
  bool operator==(const Circle& c) const {
    return center == c.center && fabs(r - c.r) < id7;
  }
};
 struct Utils {
  static vector<Point> InterCircleCircle(Circle& a, Circle& b) {
    Circle* c = &a;
    Circle* d = &b;
    if (a.r + id7 < b.r) {
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
    if (2 * longest > c->r + d->r + dis + id7) {
      return vector<Point>();
    }
    if (fabs(2 * longest - c->r - d->r - dis) < 2 * id7) {
      return vector<Point>{c->RotateRightMost(ang)};
    }
    LD proj_diff = (c->r * c->r - d->r * d->r) / dis;
    LD id5 = (dis + proj_diff) / 2;
    LD id0 = acos(id5 / c->r);
    LD ang1 = ang - id0;
    LD ang2 = ang + id0;
    return vector<Point>{c->RotateRightMost(ang1), c->RotateRightMost(ang2)};
  }
  static Point InterLineLine(Line& a, Line& b) { 

    Point vec_a = a[1] - a[0];
    Point id3 = b[1] - a[0];
    Point id4 = b[0] - a[0]; 
    LD tr_area = id3.CrossProd(id4);
    LD quad_area = id3.CrossProd(vec_a) + vec_a.CrossProd(id4);






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
    if (dis_proj > c.r + id7) { return vector<Point>(); }
    LD a = sqrt(c.r * c.r - dis_proj * dis_proj);
    Point dir = l[1] - l[0];
    dir.NormalizeSelf();
    vector<Point> cands{proj + dir * a, proj - dir * a};
    if (cands[0].Dist(cands[1]) < id7) { return vector<Point>{proj}; }
    return cands;
  }
  
  static bool PtBelongToLine(Line l, Point p) {
    return fabs(l[0].CrossProd(l[1], p)) < id7;
  }
  
  static bool PtBelongToSeg(Line l, Point p) { 

    return fabs(p.Dist(l[0]) + p.Dist(l[1]) - l[0].Dist(l[1])) < id7;
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

    assert(c.center.Dist(p) > c.r + id7); 

    Point mid = (c.center + p) / 2;
    Circle id1 = Circle(mid, c.center.Dist(p) / 2);
    return InterCircleCircle(id1, c);
  }
  
  static bool AreParallel(Line l1, Line l2) { 

    return fabs(l1[0].CrossProd(l2[0], l1[1]) - l1[0].CrossProd(l2[1], l1[1])) < id7;
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
    if (ans < id7) {
      ans += 2 * kPi;
    }
    return ans;
  }
  static LD DiskInterArea(Circle c1, Circle c2) { 

    if (c1.r < c2.r) {
      swap(c1, c2);
    }
    LD dist = c1.center.Dist(c2.center);
    if (c1.r + c2.r < dist + id7) {
      return 0;
    }
    if (c1.r - c2.r > dist - id7) {
      return kPi * c2.r * c2.r;
    }
    vector<Point> inters = Utils::InterCircleCircle(c1, c2);
    LD cross = (inters[0] - c1.center).CrossProd(inters[1] - c1.center);
    if (cross < id7) {
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
const int N = 2e3 + 5;
Line line[N];

int main() {


  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  cerr << fixed << setprecision(10);
  cin.tie(0);
  

  
  int n;
  cin>>n;
  int through_orig = 0;
  vector<Line> lines;
  RE (i, n) {
    int a, b, c;
    cin>>a>>b>>c;
    if (c == 0) {
      through_orig++;
      continue;
    }
    

    if (a == 0) {
      line[i] = Line({0, 1. * c / b}, {1, 1. * c / b});
    } else if (b == 0) {
      line[i] = Line({1. * c / a, 0}, {1. * c / a, 1});
    } else {
      line[i] = Line({0, 1. * c / b}, {1, 1. * (c - a) / b});
    }






    lines.PB(line[i]);
  }
  int to_add = 0;
  Point orig{0, 0};
  int po2 = through_orig * (through_orig - 1) / 2;
  int ans = (n - through_orig) * po2 + po2 * (through_orig - 2) / 3;
  for (int ii = 0; ii < SZ(lines); ii++) {
    vector<LD> angs;
    for (int jj = 0; jj < SZ(lines); jj++) {
      if (ii == jj) { continue; }
      Point inter = Utils::InterLineLine(lines[ii], lines[jj]);
      
      
      if (inter.CrossProd(lines[jj].diff) > 0) {
        angs.PB(Utils::Angle(orig, inter, inter + lines[jj].diff));
      } else {
        angs.PB(Utils::Angle(orig, inter, inter - lines[jj].diff));
      }
    }
    angs.PB(-10);
    sort(ALL(angs));
    angs.PB(10);
    debugv(angs);
    int last = 0;
    for (int i = 1; i < SZ(angs); i++) {
      if (abs(angs[i] - angs[i - 1]) < id7) {
        last++;
      } else {
        to_add += last * (last - 1) / 2;
        last = 1;
      }
    }
  }
  assert(to_add % 3 == 0);
  cout<<ans + to_add / 3<< endl;
  
  
  


  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  return 0;
}