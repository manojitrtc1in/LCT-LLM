
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;


const int N = 200005, M = 1000000007, BIG = 0x3f3f3f3f;

const double PI = 3.14159265358979323846, EPS = 0.0000000001;

struct Point_ll {
  ll x, y;
  Point_ll() {}
  Point_ll(ll x, ll y) : x(x), y(y) {}
};
bool operator == (const Point_ll& p1, const Point_ll& p2) {
  return p1.x == p2.x && p1.y == p2.y;
}
istream& operator >> (istream& is, Point_ll& _a) { is >> _a.x >> _a.y; return is; }
ostream& operator << (ostream& os, Point_ll& _a) { os << _a.x << " " << _a.y; return os; }

struct Point {
  double x, y;
  Point() {}
  Point(double x, double y) : x(x), y(y) {}
  Point Rotate(double theta) { 

    double rad = theta * PI / 180.;
    return { x * cos(rad) - y * sin(rad), x * sin(rad) + y * cos(rad) };
  }
  Point Rotate_Around(double theta, const Point& axis) { 

    double rad = theta * PI / 180.;
    return { (x - axis.x) * cos(rad) - (y - axis.y) * sin(rad) + axis.x,
      (x - axis.x) * sin(rad) + (y - axis.y) * cos(rad) + axis.y };
  }
};
bool operator == (const Point& p1, const Point& p2) {
  return (fabs(p1.x - p2.x) < EPS) && (fabs(p1.y - p2.y) < EPS);
}
istream& operator >> (istream& is, Point& _a) { is >> _a.x >> _a.y; return is; }
ostream& operator << (ostream& os, Point& _a) { os << _a.x << " " << _a.y; return os; }

double id7(const Point& _a, const Point& _b) {
  return hypot(_a.x - _b.x, _a.y - _b.y);
}

struct Line { 

  double a, b, c;
  Line() {}
  Line(double a, double b, double c) : a(a), b(b), c(c) {}
  Line(const Point& _a, const Point& _b) {
    if (fabs(_a.x - _b.x) < EPS) {
      a = 1;
      b = 0;
      c = -_a.x;
    }
    else {
      a = -(_a.y - _b.y) / (_a.x - _b.x);
      b = 1.;
      c = -(a * _a.x) - _a.y;
    }
  }
};

Line id2(const Line& _a, const Point& _p) {
  double sl = 1. / (_a.a / _a.b);
  double cc = _p.y - sl * _p.x;
  return Line(-sl, 1, -cc);
}

bool id14(const Line& _a, const Line& _b) {
  return (fabs(_a.a - _b.a) < EPS) && (fabs(_a.b - _b.b) < EPS);
}

bool operator == (const Line& _a, const Line& _b) {
  return id14(_a, _b) && (fabs(_a.c - _b.c) < EPS);
}

Point Intersection(const Line& _a, const Line& _b) {
  Point ans;
  ans.x = (_b.b * _a.c - _a.b * _b.c) / (_b.a * _a.b - _a.a * _b.b);
  ans.y = fabs(_a.b) > EPS ? -(_a.a * ans.x + _a.c) : -(_b.a * ans.x + _b.c) / _b.b;
  return ans;
}

struct Vec {
  double x, y;
  Vec() {}
  Vec(double x, double y) : x(x), y(y) {}
  Vec(const Point& _a, const Point& _b) : x(_b.x - _a.x), y(_b.y - _a.y) {}
  Vec Scale(double _s) const { return { x * _s, y * _s }; }
  double Squared_Norm() { return x * x + y * y; }
};
double operator * (const Vec& _a, const Vec& _b) { return _a.x * _b.x + _a.y * _b.y; }
double Cross_Product(const Vec& _a, const Vec& _b) { return _a.x * _b.y - _a.y * _b.x; }
double Cross_Product(const Point& _a, const Point& _b) { return _a.x * _b.y - _a.y * _b.x; }

Point Translate(const Point& _p, const Vec& _v) { return { _p.x + _v.x, _p.y + _v.y }; }

Point id1(const Point& _p, const Point& _a, const Point& _b) {
  Vec ap(_a, _p), ab(_a, _b);
  double u = ap * ab / ab.Squared_Norm();
  return Translate(_a, ab.Scale(u));
}

double id13(const Point& _p, const Point& _a, const Point& _b) {
  return id7(_p, id1(_p, _a, _b));
}

Point id12(const Point& _p, const Point& _a, const Point& _b) {
  Vec ap(_a, _p), ab(_a, _b);
  double u = ap * ab / ab.Squared_Norm();
  if (u < 0.0)
    return { _a.x, _a.y };
  if (u > 1.0)
    return { _b.x, _b.y };
  return Translate(_a, ab.Scale(u));
}

double id9(const Point& _p, const Point& _a, const Point& _b) {
  return id7(_p, id12(_p, _a, _b));
}

double Angle(const Point& _a, const Point& _o, const Point& _b) { 

  Vec oa(_o, _a), ob(_o, _b);
  return acos(oa * ob / sqrt(oa.Squared_Norm() * ob.Squared_Norm()));
}

double id8(const Point& _a) {
  if (fabs(_a.x) < EPS) {
    if (fabs(_a.y) < EPS)
      return 0;
    if (_a.y > 0)
      return PI / 2.;
    return 3. * PI / 2.;
  }
  else if (fabs(_a.y) < EPS) {
    if (_a.x > 0)
      return 0;
    return PI;
  }
  double ans = atan(_a.y / _a.x);
  if (_a.y < 0)
    ans += PI;
  return ans;
}

bool id0(const Point& _p, const Point& _a, const Point& _b) {
  

  return Cross_Product(Vec(_a, _b), Vec(_a, _p)) > 0;
}

bool Collinear(const Point& _p, const Point& _a, const Point& _b) {
  

  return fabs(Cross_Product(Vec(_a, _b), Vec(_a, _p))) < EPS;
}

struct Circle {
  double radius, area, id15;
  Point possible_center1, possible_center2;
  Circle(double radius) : radius(radius) {}
  void Init() {
    area = PI * radius * radius;
    id15 = 2. * PI * radius;
  }
  bool Get_Center(const Point& p1, const Point& p2) {
    double dSq = (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y);
    double det = radius * radius / dSq - 0.25;
    if (det < 0.)
      return 0;
    double h = sqrt(det);
    possible_center1.x = (p1.x + p2.x) * .5 + (p1.y - p2.y) * h;
    possible_center1.y = (p1.y + p2.y) * .5 + (p2.x - p1.x) * h;
    possible_center2.x = (p1.x + p2.x) * .5 + (p2.y - p1.y) * h;
    possible_center2.y = (p1.y + p2.y) * .5 + (p1.x - p2.x) * h;
    return 1;
  }
};

struct Triangle {
  Point p1, p2, p3;
  double area, s1, s2, s3, semip;
  void Init() {
    semip = (s1 + s2 + s3) / 2;
    area = sqrt(semip * (semip - s1) * (semip - s2) * (semip - s3));
  }
  Triangle(double s1, double s2, double s3)
    : s1(s1), s2(s2), s3(s3) {
    Init();
  }
  Triangle(const Point& p1, const Point& p2, const Point& p3)
    : p1(p1), p2(p2), p3(p3) {
    s1 = id7(p1, p2);
    s2 = id7(p2, p3);
    s3 = id7(p1, p3);
    Init();
  }
  double Incircle_Radius() { return area / semip; }
  double Circumcircle_Radius() { return s1 * s2 * s3 / (4. * area); }
  Point Circumcircle_Center() {
    Point ans;
    Point mid1 = Point((p1.x + p2.x) / 2, (p1.y + p2.y) / 2);
    Point mid2 = Point((p2.x + p3.x) / 2, (p2.y + p3.y) / 2);
    Line per1 = id2(Line(p1, p2), mid1);
    Line per2 = id2(Line(p2, p3), mid2);
    return Intersection(per1, per2);
  }
  Point Incircle_Center() {
    double ratio = s1 / s3;
    Point p = Translate(p2, Vec(p2, p3).Scale(ratio / (1 + ratio)));
    ratio = s1 / s2;
    p = Translate(p1, Vec(p1, p3).Scale(ratio / (1 + ratio)));
    return Intersection(Line(p1, p), Line(p2, p));
  }
};

struct Rectangle {
  Point_ll bottom_left, top_right;
  Rectangle() {}
  Rectangle(const Point_ll& bottom_left, const Point_ll& top_right)
    : bottom_left(bottom_left), top_right(top_right) {}
  operator bool() { 

    return bottom_left.x < top_right.x&& bottom_left.y < top_right.y;
  }
};
bool operator == (const Rectangle& r1, const Rectangle& r2) {
  return r1.bottom_left == r2.bottom_left && r1.top_right == r2.top_right;
}
istream& operator >> (istream& is, Rectangle& _a) {
  is >> _a.bottom_left >> _a.top_right;
  return is;
}
ostream& operator << (ostream& os, Rectangle& _a) {
  os << _a.bottom_left << " " << _a.top_right;
  return os;
}

Rectangle Intersection(const Rectangle& r1, const Rectangle& r2) {
  return Rectangle(
    { max(r1.bottom_left.x, r2.bottom_left.x),
      max(r1.bottom_left.y, r2.bottom_left.y) },
    { min(r1.top_right.x, r2.top_right.x),
      min(r1.top_right.y, r2.top_right.y) });
}

struct Polygon {
  vector<Point> vp;
  Polygon() {}
  void Add(const Point& _p) {
    vp.push_back(_p);
  }
  double Perimeter() {
    double ans = 0.0;
    for (int i = 0; i < (int)vp.size() - 1; i++)
      ans += id7(vp[i], vp[i + 1]);
    return ans;
  }
  double Area() {
    double ans = 0.0, x1, y1, x2, y2;
    for (int i = 0; i < (int)vp.size() - 1; i++) {
      x1 = vp[i].x;
      x2 = vp[i + 1].x;
      y1 = vp[i].y;
      y2 = vp[i + 1].y;
      ans += (x1 * y2 - x2 * y1);
    }
    return fabs(ans) / 2.0;
  }
  bool Convex() {
    int sz = (int)vp.size();
    if (sz <= 3)
      return 0;
    bool isLeft = id0(vp[2], vp[0], vp[1]);
    for (int i = 1; i < sz - 1; i++)
      if (id0(vp[(i + 2) == sz ? 1 : i + 2], vp[i], vp[i + 1]) != isLeft)
        return 0;
    return 1;
  }
  bool Contains_Point(const Point& _p) {
    if ((int)vp.size() == 0)
      return 0;
    double sum = 0;
    for (int i = 0; i < (int)vp.size() - 1; i++) {
      if (id0(vp[i + 1], _p, vp[i]))
        sum += Angle(vp[i], _p, vp[i + 1]);
      else
        sum -= Angle(vp[i], _p, vp[i + 1]);
    }
    return fabs(fabs(sum) - 2. * PI) < EPS;
  }
  Point Line_Intersect_Seg(const Point& _p, const Point& _q, const Point& _A, const Point& _B) {
    double a, b, c, u, v;
    a = _B.y - _A.y;
    b = _A.x - _B.x;
    c = _B.x * _A.y - _A.x * _B.y;
    u = fabs(a * _p.x + b * _p.y + c);
    v = fabs(a * _q.x + b * _q.y + c);
    return Point((_p.x * v + _q.x * u) / (u + v), (_p.y * v + _q.y * u) / (u + v));
  }
  Polygon Cut_Polygon(const Point& _a, const Point& _b) {
    Polygon ans;
    for (int i = 0; i < (int)vp.size(); i++) {
      double left1 = Cross_Product(Vec(_a, _b), Vec(_a, vp[i])), left2 = 0;
      if (i != (int)vp.size() - 1) left2 = Cross_Product(Vec(_a, _b), Vec(_a, vp[i + 1]));
      if (left1 > -EPS)
        ans.Add(vp[i]);
      if (left1 * left2 < -EPS)
        ans.Add(Line_Intersect_Seg(vp[i], vp[i + 1], _a, _b));
    }
    if (!ans.vp.empty() && !(ans.vp.back() == ans.vp.front()))
      ans.Add(ans.vp.front());
    return ans;
  }
};

vector<Point> id5(vector<Point> vp) { 

  int i, j, n = (int)vp.size();
  if (n <= 3) {
    if (!(vp[0] == vp[n - 1]))
      vp.push_back(vp[0]);
    return vp;
  }
  int P0 = 0;
  for (i = 1; i < n; i++)
    if (vp[i].y < vp[P0].y || (vp[i].y == vp[P0].y && vp[i].x > vp[P0].x))
      P0 = i;
  swap(vp[0], vp[P0]);
  sort(vp.begin() + 1, vp.end(), [vp](const Point& _a, const Point& _b) {
    if (Collinear(vp[0], _a, _b))
      return id7(vp[0], _a) < id7(vp[0], _b);
    double id4 = _a.x - vp[0].x, id10 = _a.y - vp[0].y;
    double id3 = _b.x - vp[0].x, id6 = _b.y - vp[0].y;
    return (atan2(id10, id4) - atan2(id6, id3)) < 0;
    });
  vector<Point> ans;
  ans.push_back(vp[n - 1]);
  ans.push_back(vp[0]);
  ans.push_back(vp[1]);
  i = 2;
  while (i < n) {
    j = (int)ans.size() - 1;
    if (id0(vp[i], ans[j - 1], ans[j]))
      ans.push_back(vp[i++]);
    else
      ans.pop_back();
  }
  return ans;
}

double id11(const vector<Point> vertices) {
  double sum = 0.;
  for (int i = 0; i < vertices.size(); i++)
    sum += Cross_Product(vertices[i], vertices[(i + 1) % vertices.size()]);
  return abs(sum) / 2.0;
}


int n;
vector<Point> p;

bool Read() {
  cin >> n;
  if (cin.eof())
    return 0;
  p.resize(n);
  for (int i = 0; i < n; i++)
    cin >> p[i];

  return 1;
}

void Process() {
  p.push_back(p[0]);
  p.push_back(p[1]);
  double ans = 1e16;
  for (int i = 0; i < n; i++)
    ans = min(ans, id9(p[i + 1], p[i], p[i + 2]));
  ans /= 2.;
  cout << fixed << setprecision(10) << ans << "\n";
}

int main() {
  FASTIO();

  while (Read())
    Process();

  return 0;
}