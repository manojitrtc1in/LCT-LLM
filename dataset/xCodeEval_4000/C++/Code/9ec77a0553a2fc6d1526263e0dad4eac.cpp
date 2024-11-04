#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
#define rint register int
#define rll register ll 
#define pii pair<int, int>
#define pll pair<ll, ll>




const ll inf = 1e8;


#define fors(i, a, b) for (rll i = (a); i <= (b); ++i)
#define _fors(i, a, b) for (rll i = (a); i >= (b); --i)
#define mp(a, b) make_pair(a, b)
#define mem(A, b) memset(A, b, sizeof(A))
#define all(X) (X).begin(), (X).end()
#define pb push_back 



const double PI = 3.141592653589793;

struct Point {
  double x, y;
  Point(double x = 0, double y = 0) : x(x), y(y) {}
};

typedef Point Vector;

Vector operator + (Vector A, Vector B) {
  return Vector(A.x + B.x, A.y + B.y);
}

Vector operator - (Point A, Point B) {
  return Vector(A.x - B.x, A.y - B.y);
}

Vector operator * (Vector A, double p) {
  return Vector(A.x * p, A.y * p);
}

Vector operator / (Vector A, double p) {
  return Vector(A.x / p, A.y / p);
}

const double eps = 1e-8;

int dcmp(double x) {
  if (fabs(x) < eps) return 0;
  else return x < 0 ? -1 : 1;
}

bool operator == (const Point& a, const Point& b) {
  return dcmp(a.x - b.x) == 0 && dcmp(a.y - b.y) == 0;
}

bool operator < (const Point& a, const Point& b) {
  if (dcmp(a.x - b.x) == 0) return a.y < b.y;
  return a.x < b.x;
}

double Dot(Vector A, Vector B) {
  return A.x * B.x + A.y * B.y;
}

double Length(Vector A) {
  return sqrt(Dot(A, A));
}

double Angle(Vector A, Vector B) {
  return acos(Dot(A, B) / Length(A) / Length(B));
}

double Cross(Vector A, Vector B) {
  return A.x * B.y - A.y * B.x;
}

double Area2(Point A, Point B, Point C) {
  return Cross(B-A, C-A);
}

Vector Rotate(Vector A, double rad) {
  return Vector(A.x*cos(rad) - A.y*sin(rad), A.x*sin(rad) + A.y*cos(rad));
}

Vector Normal(Vector A) {
  double L = Length(A);
  return Vector(-A.y / L, A.x / L);
}

Point GetLineIntersection(Point P, Vector v, Point Q, Vector w) {
  Vector u = P - Q;
  double t = Cross(w, u) / Cross(v, w);
  return P + v*t;
}

double DistanceToLine(Point P, Point A, Point B) {
  Vector v1 = B - A, v2 = P - A;
  return fabs(Cross(v1, v2) / Length(v1));
}

double DistanceToSegment(Point P, Point A, Point B) {
  if (A == B) return Length(P-A);
  Vector v1 = B - A, v2 = P - A, v3 = P - B;
  if (dcmp(Dot(v1, v2)) < 0) return Length(v2);
  else if (dcmp(Dot(v1, v3) > 0)) return Length(v3);
  else return fabs(Cross(v1, v2)) / Length(v1);
}

Point GetLineProjection(Point P, Point A, Point B) {
  Vector v = B - A;
  return A + v * (Dot(v, P - A) / Dot(v, v));
}

bool SegmentProperIntersection(Point a1, Point a2, Point b1, Point b2) {
  double c1 = Cross(a2 - a1, b1 - a1);
  double c2 = Cross(a2 - a1, b2 - a1);
  double c3 = Cross(b2 - b1, a1 - b1);
  double c4 = Cross(b2 - b1, a2 - b1);
  return dcmp(c1) * dcmp(c2) < 0 && dcmp(c3) * dcmp(c4) < 0;
}

bool OnSegment(Point p, Point a1, Point a2) {
  return dcmp(Cross(a1-p, a2-p)) == 0 && dcmp(Dot(a1-p, a2-p)) <= 0;
}

typedef vector<Point> Polygon;

int isPointInPolygon(const Point& p, const Polygon& poly){
  int n = poly.size();
  int wn = 0;
  for(int i = 0; i < n; i++){
    const Point& p1 = poly[i];
    const Point& p2 = poly[(i+1)%n];
    if(p1 == p || p2 == p || OnSegment(p, p1, p2)) return -1; 

    int k = dcmp(Cross(p2-p1, p-p1));
    int d1 = dcmp(p1.y - p.y);
    int d2 = dcmp(p2.y - p.y);
    if(k > 0 && d1 <= 0 && d2 > 0) wn++;
    if(k < 0 && d2 <= 0 && d1 > 0) wn--;
  }
  if (wn != 0) return 1; 

  return 0; 

}

bool isDiagonal(const Polygon& poly, int a, int b) {
  int n = poly.size();
  for(int i = 0; i < n; i++)
    if(i != a && i != b && OnSegment(poly[i], poly[a], poly[b])) return false; 

  for(int i = 0; i < n; i++)
    if(SegmentProperIntersection(poly[i], poly[(i+1)%n], poly[a], poly[b])) return false; 

  Point midp = (poly[a] + poly[b]) * 0.5;
  return (isPointInPolygon(midp, poly) == 1); 

}

double ConvexPolygonArea(Point* p, int n) {
  double area = 0;
  for(int i = 1; i < n-1; i++) area += Cross(p[i] - p[0], p[i+1] - p[0]);
  return area/2;
}

double PolygonArea(Point* p, int n) {
  double area = 0;
  for (int i = 1; i < n-1; i++) area += Cross(p[i] - p[0], p[i+1] - p[0]);
  return area/2;
}

struct Circle {
  Point c;
  double r;
  Circle() {}
  Circle(Point c, double r): c(c), r(r) {}
  Point point(double a) {
    return Point(c.x + cos(a)*r, c.y + sin(a)*r);
  }
};

struct Line {
  Point P;
  Vector v;
  double ang;
  Line() {}
  Line(Point P, Vector v): P(P), v(v) { ang = atan2(v.y, v.x); }
  bool operator < (const Line& L) const {
    return dcmp(ang - L.ang) < 0;
  }
  Point point(double t) {
    return P + v*t;
  }
};

int GetLineCircleIntersection(Line L, Circle C, double& t1, double& t2, vector<Point>& sol) {
  double a = L.v.x, b = L.P.x - C.c.x, c = L.v.y, d = L.P.y - C.c.y;
  double e = a*a + c*c, f = 2*(a*b + c*d), g = b*b + d*d - C.r*C.r;
  double delta = f*f - 4*e*g;
  if (dcmp(delta) < 0) return 0;
  if (dcmp(delta) == 0) {
    t1 = t2 = -f / (2 * e); sol.pb(L.point(t1));
    return 1;
  }
  t1 = (-f - sqrt(delta)) / (2 * e); sol.pb(L.point(t1));
  t2 = (-f + sqrt(delta)) / (2 * e); sol.pb(L.point(t2));
  return 2;
}

double angle(Vector v) {
  return atan2(v.y, v.x);
}

int GetCircleCircleIntersection(Circle C1, Circle C2, vector<Point>& sol) {
  double d = Length(C1.c - C2.c);
  if (dcmp(d) == 0) {
    if (dcmp(C1.r - C2.r) == 0) return -1;
    return 0;
  }
  if (dcmp(C1.r + C2.r - d) < 0) return 0;
  if (dcmp(fabs(C1.r - C2.r) - d) > 0) return 0;
  double a = angle(C2.c - C1.c);
  double da = acos((C1.r*C1.r + d*d - C2.r*C2.r) / (2*C1.r*d));
  Point p1 = C1.point(a-da), p2 = C1.point(a+da);
  sol.pb(p1);
  if (p1 == p2) return 1;
  sol.pb(p2);
  return 2;
}

int GetTangents(Point p, Circle C, Vector* v) {
  Vector u = C.c - p;
  double dist = Length(u);
  if (dist < C.r) return 0;
  else if (dcmp(dist - C.r) == 0) {
    v[0] = Rotate(u, PI / 2);
    return 1;
  }
  else {
    double ang = asin(C.r / dist);
    v[0] = Rotate(u, -ang);
    v[1] = Rotate(u, +ang);
    return 2;
  }
}

int GetTangents(Circle A, Circle B, Point* a, Point* b) {
  int cnt = 0;
  if (A.r < B.r) { swap(A, B); swap(a, b); }
  double d2 = (A.c.x-B.c.x)*(A.c.x-B.c.x) + (A.c.y-B.c.y)*(A.c.y-B.c.y);
  double rdiff = A.r - B.r;
  double rsum = A.r + B.r;
  if (d2 < rdiff * rdiff) return 0;
  double base = atan2(B.c.y - A.c.y, B.c.x - A.c.x);
  if (dcmp(d2) == 0 && dcmp(A.r-B.r) == 0) return -1;
  if (dcmp(d2-rdiff*rdiff) == 0) {
    a[cnt] = A.point(base);
    b[cnt] = B.point(base);
    cnt++;
    return 1;
  }
  double ang = acos((A.r-B.r) / sqrt(d2));
  a[cnt] = A.point(base+ang);
  b[cnt] = B.point(base+ang);
  cnt++;
  a[cnt] = A.point(base-ang);
  b[cnt] = B.point(base-ang);
  cnt++;
  if (dcmp(d2-rsum*rsum) == 0) {
    a[cnt] = A.point(base);
    b[cnt] = B.point(PI+base);
    cnt++;
  }
  else if (d2 > rsum*rsum) {
    ang = acos((A.r+B.r) / sqrt(d2));
    a[cnt] = A.point(base+ang);
    b[cnt] = B.point(base+ang);
    cnt++;
    a[cnt] = A.point(PI+base-ang);
    b[cnt] = B.point(PI+base-ang);
    cnt++;
  }
  return cnt;
}

Vector GetAngleBisectorDefinition(Point p, Point lef, Point rig) {
  int res = dcmp(Cross(rig - p, lef - p));
  if (res == 0) return lef - p;
  if (res < 0) swap(lef, rig);
  return Rotate(rig - p, 0.5*Angle(rig - p, lef - p)); 
}

Circle CircumscribedCircle(Point p1, Point p2, Point p3) {
  double Bx = p2.x-p1.x, By = p2.y-p1.y;
  double Cx = p3.x-p1.x, Cy = p3.y-p1.y;
  double D = 2*(Bx*Cy-By-Cx);
  double cx = (Cy*(Bx*Bx+By*By) - By*(Cx*Cx+Cy*Cy)) / D + p1.x;
  double cy = (Bx*(Cx*Cx+Cy*Cy) - Cx*(Bx*Bx+By*By)) / D + p1.y;
  Point p = Point(cx, cy);
  return Circle(p, Length(p1-p));
}

Circle InscribedCircle(Point p1, Point p2, Point p3) {
  double a = Length(p2-p3);
  double b = Length(p3-p1);
  double c = Length(p1-p2);
  Point p = (p1*a+p2*b+p3*c) / (a+b+c);
  return Circle(p, DistanceToSegment(p, p1, p2));
}

int IsPointInPolygon(Point p, Polygon poly) {
  int wn = 0;
  int n = poly.size();
  fors(i, 0, n-1) {
    if (OnSegment(p, poly[i], poly[(i+1)%n]) || p == poly[i] || p == poly[(i+1)%n]) return -1;
    int k = dcmp(Cross(poly[(i+1)%n]-poly[i], p-poly[i]));
    int d1 = dcmp(poly[i].y - p.y);
    int d2 = dcmp(poly[(i+1)%n].y - p.y);
    if (k > 0 && d1 <= 0 && d2 > 0) wn++;
    if (k < 0 && d2 <= 0 && d1 > 0) wn--;
  }
  if (wn) return 1;
  return 0;
}

int ConvexHull(Point* p, int n, Point* ch) {
  sort(p, p+n);
  int m = 0;
  fors(i, 0, n-1) {
    while (m > 1 && dcmp(Cross(ch[m-1]-ch[m-2], p[i]-ch[m-2])) < 0) m--;
    ch[m++] = p[i];
  }
  int k = m;
  _fors(i, n-2, 0) {
    while (m > k && dcmp(Cross(ch[m-1]-ch[m-2], p[i]-ch[m-2])) < 0) m--;
    ch[m++] = p[i];
  }
  if (n > 1) m--;
  return m;
}

double GetDiameter(Point* ch, int n) {
  if (n == 1) return 0.0;
  if (n == 2) return Length(ch[0]-ch[1]);
  int j = 2;
  double ret = 0.0;
  fors(i, 0, n-1) {
    while (Cross(ch[i] - ch[(i+1)%n], ch[(i+1)%n] - ch[j]) < Cross(ch[i] - ch[(i+1)%n], ch[(i+1)%n] - ch[(j+1)%n])) j = (j + 1) % n;
    ret = max(Length(ch[i] - ch[j]), Length(ch[(i+1)%n] - ch[j]));
  }
  return ret;
}

bool OnLeft(Line L, Point p) {
  return dcmp(Cross(L.v, p - L.P)) > 0;
}

Point GetIntersection(Line a, Line b) {
  Vector u = a.P - b.P;
  double t = Cross(b.v, u) / Cross(a.v, b.v);
  return a.P + a.v*t;
}

int HalfplaneIntersection(Line* L, int n, Point* poly) {
  sort(L, L + n);
  int first, last;
  Point *p = new Point[n];
  Line *q = new Line[n];
  q[first=last=0] = L[0];
  fors(i, 1, n-1) {
    while (first < last && !OnLeft(L[i], p[last-1])) last--;
    while (first < last && !OnLeft(L[i], p[first])) first++;
    q[++last] = L[i];
    if (fabs(Cross(q[last].v, q[last-1].v)) < eps) {
      last--;
      if (OnLeft(q[last], L[i].P)) q[last] = L[i];
    }
    if (first < last) p[last-1] = GetIntersection(q[last-1], q[last]);
  }
  while (first < last && !OnLeft(q[first], p[last-1])) last--;
  if (last - first <= 1) return 0;
  p[last] = GetIntersection(q[last], q[first]);
  int m = 0;
  fors(i, first, last) poly[m++] = p[i];
  return m;
}

bool isint(double a, int& p) {
  int t = a;
  if (!dcmp(t-a)) { p = t; return true; }
  if (!dcmp(t-a-1)) { p = t - 1; return true; }
  if (!dcmp(t-a+1)) { p = t + 1; return true; }
  return false;
}

Point A[1005], B[1005];
set<pii> s, sall;
int n;

int gcd(int a, int b) {
  return b == 0 ? a : gcd(b, a%b);
}

int main() {  
  

  

  ios::sync_with_stdio(false); 
  cin.tie(0);
  
  ll ans = 0;
  cin >> n;
  fors(i, 1, n) {
    int ux, uy, vx, vy;
    cin >> ux >> uy >> vx >> vy;
    if (ux == vx) ans += abs(uy - vy) + 1;
    else if (uy == vy) ans += abs(ux - vx) + 1;
    else ans += (ll)(gcd(abs(ux-vx), abs(uy-vy)) + 1);
    A[i] = Point(ux, uy), B[i] = Point(vx, vy);
  }
  fors(i, 1, n) {
    fors(j, 1, n) {
      if (dcmp(Cross(A[i]-B[i], A[j]-B[j])) == 0) continue;
      Point tp = GetLineIntersection(A[i], A[i]-B[i], A[j], A[j]-B[j]);
      int tx, ty;
      if (!(isint(tp.x, tx) && isint(tp.y, ty))) continue;
      tp = Point(tx, ty); 
      if (OnSegment(tp, A[i], B[i]) && OnSegment(tp, A[j], B[j])) {
        s.insert(mp(tx, ty));
        sall.insert(mp(tx, ty));
      }
    }
    ans -= (ll)s.size();
    s.clear();
  }
  ans += (ll)sall.size();
  cout << ans << endl;
  

  return 0;
}