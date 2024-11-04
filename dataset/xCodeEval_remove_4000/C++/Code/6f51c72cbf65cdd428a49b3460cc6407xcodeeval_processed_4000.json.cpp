


























using namespace std;
typedef long long ll;
typedef long double LD;
typedef pair<int, int> PII;
typedef pair<ll, ll> PLL;
typedef vector<int> VI;
typedef vector<ll> VLL;
typedef vector<pair<int, int> > VPII;
typedef vector<pair<ll, ll> > VPLL;

template<class C> void mini(C&a4, C b4){a4=min(a4, b4); }
template<class C> void maxi(C&a4, C b4){a4=max(a4, b4); }
template<class T1, class T2>
ostream& operator<< (ostream &out, pair<T1, T2> pair) { return out << "(" << pair.first << ", " << pair.second << ")";}
const int N = 1e3 + 5;
const ll M = 1e9 + 7;
ll dp[N][N];
ll is_in[N][N];
const LD id8 = 1e-9;
const LD kPi = 2 * acos(0);
struct Point {
  LD x, y;
  Point(LD a = 0, LD b = 0) : x(a), y(b) {}
  Point(const Point& a) : x(a.x), y(a.y) {}
  void operator=(const Point& a) { x = a.x; y = a.y; }
  Point operator+(const Point& a) const { Point p(x + a.x, y + a.y); return p; }
  Point operator-(const Point& a) const { Point p(x - a.x, y - a.y); return p; }
  Point operator*(LD a) const { Point p(x * a, y * a); return p; }
  Point operator/(LD a) const { assert(a > id8); Point p(x / a, y / a); return p; }
  Point& operator+=(const Point& a) { x += a.x; y += a.y; return *this; }
  Point& operator-=(const Point& a) { x -= a.x; y -= a.y; return *this; }
  Point& operator*=(LD a) { x *= a; y *= a; return *this;}
  Point& operator/=(LD a) { assert(a > id8); x /= a; y /= a; return *this; }
  
  bool IsZero() const {
    return fabs(x) < id8 && fabs(y) < id8;
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
    if (fabs(a.x - b.x) > id8) {
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
    Point id3(r, 0);
    Point res = id3.Rotate(ang);
    return center + res;
  }
  bool operator==(const Circle& c) const {
    return center == c.center && fabs(r - c.r) < id8;
  }
};

struct Line {
  Point p[2];
  bool is_seg;
  Line(Point a, Point b, bool id7 = false) {
    p[0] = a;
    p[1] = b;
    is_seg = id7;
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
    assert(fabs(A * p[1].x + B * p[1].y + C) < id8);
    LD norm = sqrt(A * A + B * B);
    vector<LD> res{A, B, C};
    for (auto& x : res) { x /= norm; }
    if (A < -id8 || (fabs(A) < id8 && B < -id8)) {
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
    if (a.r + id8 < b.r) {
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
    if (2 * longest > c->r + d->r + dis + id8) {
      return vector<Point>();
    }
    if (fabs(2 * longest - c->r - d->r - dis) < 2 * id8) {
      return vector<Point>{c->RotateRightMost(ang)};
    }
    LD proj_diff = (c->r * c->r - d->r * d->r) / dis;
    LD id6 = (dis + proj_diff) / 2;
    LD id0 = acos(id6 / c->r);
    LD ang1 = ang - id0;
    LD ang2 = ang + id0;
    return vector<Point>{c->RotateRightMost(ang1), c->RotateRightMost(ang2)};
  }
  static Point InterLineLine(Line& a, Line& b) { 

    Point vec_a = a[1] - a[0];
    Point id4 = b[1] - a[0];
    Point id5 = b[0] - a[0]; 
    LD tr_area = id4.CrossProd(id5);
    LD quad_area = id4.CrossProd(vec_a) + vec_a.CrossProd(id5);






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
    if (dis_proj > c.r + id8) { return vector<Point>(); }
    LD a = sqrt(c.r * c.r - dis_proj * dis_proj);
    Point dir = l[1] - l[0];
    dir.NormalizeSelf();
    vector<Point> cands{proj + dir * a, proj - dir * a};
    if (cands[0].Dist(cands[1]) < id8) { return vector<Point>{proj}; }
    return cands;
  }
  
  static bool PtBelongToLine(Line l, Point p) {
    return fabs(l[0].CrossProd(l[1], p)) < id8;
  }
  
  static bool PtBelongToSeg(Line l, Point p) { 

    return fabs(p.Dist(l[0]) + p.Dist(l[1]) - l[0].Dist(l[1])) < id8;
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

    assert(c.center.Dist(p) > c.r + id8); 

    Point mid = (c.center + p) / 2;
    Circle id1 = Circle(mid, c.center.Dist(p) / 2);
    return InterCircleCircle(id1, c);
  }
  
  static bool AreParallel(Line l1, Line l2) { 

    return fabs(l1[0].CrossProd(l2[0], l1[1]) - l1[0].CrossProd(l2[1], l1[1])) < id8;
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
    if (ans < id8) {
      ans += 2 * kPi;
    }
    return ans;
  }
  static LD DiskInterArea(Circle c1, Circle c2) { 

    if (c1.r < c2.r) {
      swap(c1, c2);
    }
    LD dist = c1.center.Dist(c2.center);
    if (c1.r + c2.r < dist + id8) {
      return 0;
    }
    if (c1.r - c2.r > dist - id8) {
      return kPi * c2.r * c2.r;
    }
    vector<Point> inters = Utils::InterCircleCircle(c1, c2);
    LD cross = (inters[0] - c1.center).CrossProd(inters[1] - c1.center);
    if (cross < id8) {
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
      int id2 = (dir + 1) / 2;
      auto& H = one_way_hull[id2];
      one_way_hull[id2].push_back(pts[0]);
      if (SZ(pts) > 1) {
        H.push_back(pts[1]);
      }
      for (int i = 2; i < SZ(pts); i++) {
        while (SZ(H) >= 2 &&
            dir * (pts[i] - H[SZ(H) - 2]).CrossProd(H.back() - H[SZ(H) - 2]) > -id8) {
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
        if (areas[0] * areas[1] < id8) {
          res[i][j] = 0;
        }
      }
    }
    return res;
  }
};

int main() {
  

  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  double beg = 1.0 * clock() / CLOCKS_PER_SEC;
  
  make(int, n);
  Polygon poly;
  RE (i, n) {
    make2(int, y, x);
    

    poly.Add({y, x});
  }
 










































































































































  auto inn = poly.InsideDiagonalsMatrix();


  REP (i, n) {
    REP (j, n) {
      is_in[i + 1][j + 1] = inn[i][j];
    }
  }
  RE (i, n) {
    is_in[i][1 + i % n] = is_in[1 + i % n][i] = 1;
  }
  RE (i, n) {
    RE (j, n) {
      cerr<<is_in[i][j];
    }
    cerr<<"\n";
  }
  for (int i = 1; i <= n; i++) {
    int ii = 1 + i % n;
    dp[i][ii] = 1;
  }
  for (int dl = 2; dl <= n - 1; dl++) {
    for (int i = 1; i <= n; i++) {
      int ii = 1 + (i + dl - 1) % n;
      int mid = 1 + i % n;
      while (mid != ii) {
        if (is_in[i][mid] && is_in[mid][ii]) {
          dp[i][ii] = (dp[i][ii] + dp[i][mid] * dp[mid][ii]) % M;
        }
        mid = 1 + mid % n;
      }
      if (is_in[i][ii] == 0) {
        dp[i][ii] = 0;
      }
    }
  }
  assert(dp[2][1] == dp[1][n]);
  RE (i, n) {
    RE (j, n) {
      assert(is_in[i][j] == is_in[j][i]);
    }
  }
  cout<<dp[2][1]<<endl;
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  

  return 0;
}