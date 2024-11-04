#include <cstring>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <utility>
using namespace std;

#define _inline(f...) f() __attribute__((always_inline)); f
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
const int INF = 10000000;
const double EPS = 1e-8;

_inline(int cmp)(double x, double y = 0, double tol = EPS) {
  return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

struct point {
  double x, y;
  point(double x = 0, double y = 0): x(x), y(y) {}
  
  point operator +(point q) { return point(x + q.x, y + q.y); }
  point operator -(point q) { return point(x - q.x, y - q.y); }
  point operator *(double t) { return point(x * t, y * t); }
  point operator /(double t) { return point(x / t, y / t); }
  double operator *(point q) { return x * q.x + y * q.y; }
  double operator %(point q) { return x * q.y - y * q.x; }
  int cmp(point q) const {
    if (int t = ::cmp(x, q.x)) return t;
    return ::cmp(y, q.y);
  }
  bool operator ==(point q) const { return cmp(q) == 0; }
  bool operator !=(point q) const { return cmp(q) != 0; }
  bool operator < (point q) const { return cmp(q) < 0; }
  friend ostream& operator <<(ostream& o, point p) {
    return o << "(" << p.x << ", " << p.y << ")";
  }
  
  static point pivot;
};

point point::pivot;

double abs(point p) { return hypot(p.x, p.y); }
double arg(point p) { return atan2(p.y, p.x); }

typedef vector<point> polygon;
typedef pair<point, double> circle;

_inline(int ccw)(point p, point q, point r) {
  return cmp((p-r) % (q-r));
}









_inline(double angle)(point p, point q, point r) {
  point u = p - q, v = r - q;
  return atan2(u % v, u * v);
}

double dist2(point p, point q) { return ((p-q) *  (p-q)); }


point rotateCCW90(point p) { return point(-p.y,p.x); }
point rotateCW90(point p) { return point(p.y,-p.x); }
point rotateCCW(point p, double t) { 
  return point(p.x*cos(t)-p.y*sin(t), p.x*sin(t)+p.y*cos(t)); 
}











point projectPointLine(point a, point b, point c) {
  return a + (b-a)*((c-a)* (b-a))/ ((b-a) * (b-a));
}


point projectPointSegment(point a, point b, point c) {
  double r = ((b-a) * (b-a));
  if (fabs(r) < EPS) return a;
  r = ((c-a) * (b-a))/r;
  if (r < 0) return a;
  if (r > 1) return b;
  return a + (b-a)*r;
}





bool between(point p, point q, point r) {
  return ccw(p, q, r) == 0 && cmp((p - q) * (r - q)) <= 0;
}



double distancePointSegment(point a, point b, point c) {
  return sqrt(dist2(c, projectPointSegment(a, b, c)));
}


double distancePointPlane(double x, double y, double z,
			  double a, double b, double c, double d){
  return fabs(a*x+b*y+c*z-d)/sqrt(a*a+b*b+c*c);
}


bool linesParallel(point a, point b, point c, point d) { 
  return fabs((b-a) % ( c-d)) < EPS; 
}
bool linesCollinear(point a, point b, point c, point d) { 
  return linesParallel(a, b, c, d)
    && fabs((a-b) % (a-c)) < EPS
    && fabs((c-d) % (c-a)) < EPS; 
}





bool seg_intersect(point p, point q, point r, point s) {
  point A = q - p, B = s - r, C = r - p, D = s - q;
  int a = cmp(A % C) + 2 * cmp(A % D);
  int b = cmp(B % C) + 2 * cmp(B % D);
  if (a == 3 || a == -3 || b == 3 || b == -3) return false;
  if (a || b || p == r || p == s || q == r || q == s) return true;
  int t = (p < r) + (p < s) + (q < r) + (q < s);
  return t != 0 && t != 4;
}





point line_intersect(point p, point q, point r, point s) {
  point a = q - p, b = s - r, c = point(p % q, r % s);
  return point(point(a.x, b.x) % c, point(a.y, b.y) % c) / (a % b);
}















bool circle2PtsRad(point p1, point p2, double r, point &c) {
  double d2 = (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y);
  double det = ((r * r) / d2) - 0.25;
  if (det < 0.0) return false;
  double h = sqrt(det);
  c.x = (p1.x + p2.x) * 0.5 + (p1.y - p2.y) * h;
  c.y = (p1.y + p2.y) * 0.5 + (p2.x - p1.x) * h;
  return true; 
}





point computeCircleCenter(point a, point b, point c) {
  b=(a+b)/2;
  c=(a+c)/2;
  return line_intersect(b, b+rotateCW90(a-b), c, c+rotateCW90(a-c));
}







point computeCircleIncenter(point a , point b, point c){
  point d = b + rotateCCW(c-b,angle(c,b,a)/2);
  point e = c + rotateCCW(a-c,angle(a,c,b)/2);
  return line_intersect(b,d,c,e);
}





vector<point> circleLineIntersection(point a, point b, point c, double r) {
  vector<point> ret;
  b = b-a;
  a = a-c;
  double A = b *  b;
  double B = a *  b;
  double C = (a * a) - r*r;
  double D = B*B - A*C;
  if (D < -EPS) return ret;
  ret.push_back(c+a+b*(-B+sqrt(D+EPS))/A);
  if (D > EPS)
    ret.push_back(c+a+b*(-B-sqrt(D))/A);
  return ret;
}





vector<point> circleCircleIntersection(point a, point b, double r, double R) {
  vector<point> ret;
  double d = sqrt(dist2(a, b));
  if (d > r+R || d+min(r, R) < max(r, R)) return ret;
  double x = (d*d-R*R+r*r)/(2*d);
  double y = sqrt(r*r-x*x);
  point v = (b-a)/d;
  ret.push_back(a+v*x + rotateCCW90(v)*y);
  if (y > 0)
    ret.push_back(a+v*x - rotateCCW90(v)*y);
  return ret;
}





vector<  point > tangentSegments(point c, double r,  point p){
  vector< point  > resp;
  point toCenter = c - p;
  if( cmp(r - sqrt(dist2(toCenter , point(0,0)))) <= 0 ){
    resp.push_back(p);
    resp.push_back(p);
    return resp;
  }
  double angle = asin(r/sqrt(dist2(toCenter , point(0,0))));
  point uni = toCenter / sqrt(dist2(toCenter , point(0,0)));
  double tam = sqrt(dist2(toCenter , point(0,0)) - r *r);
  point origi = uni * tam;
  point p1 = p + rotateCCW(origi,angle);
  resp.push_back(p1);
  point p2 = p + rotateCCW(origi,-angle);
  resp.push_back(p2);
  return resp;
}
















int in_poly(point p, polygon& T) {
  double a = 0; int N = T.size();
  for (int i = 0; i < N; i++) {
    if (between(T[i], p, T[(i+1) % N])) return -1;
    a += angle(T[i], p, T[(i+1) % N]);
  }
  return cmp(a) != 0;
}







double poly_area(polygon& T) {
  double s = 0; int n = T.size();
  for (int i = 0; i < n; i++)
    s += T[i] % T[(i+1) % n];
  return s / 2;
}




point computeCentroid(vector<point> &p) {
  point c(0,0);
  double scale = 6.0 * poly_area(p);
  for (int i = 0; i < p.size(); i++){
    int j = (i+1) % p.size();
    c = c + (p[i]+p[j])*(p[i].x*p[j].y - p[j].x*p[i].y);
  }
  return c / scale;
}





bool radial_lt(point p, point q) {
  point P = p - point::pivot, Q = q - point::pivot;
  double R = P % Q;
  if (cmp(R)) return R > 0;
  return cmp(P * P, Q * Q) < 0;
}






polygon convex_hull(vector<point>& T) {
  int j = 0, k, n = T.size(); polygon U(n);
  point::pivot = *min_element(all(T));
  sort(all(T), radial_lt);
  for (k = n-2; k >= 0 && ccw(T[0], T[n-1], T[k]) == 0; k--);
  reverse((k+1) + all(T));
  for (int i = 0; i < n; i++) {
    

    while (j > 1 && ccw(U[j-1], U[j-2], T[i]) >= 0) j--;
    U[j++] = T[i];
  }
  U.erase(j + all(U));
  return U;
}








polygon poly_intersect(polygon& P, polygon& Q) {
  int m = Q.size(), n = P.size();
  int a = 0, b = 0, aa = 0, ba = 0, inflag = 0;
  polygon R;
  while ((aa < n || ba < m) && aa < 2*n && ba < 2*m) {
    point p1 = P[a], p2 = P[(a+1) % n], q1 = Q[b], q2 = Q[(b+1) % m];
    point A = p2 - p1, B = q2 - q1;
    int cross = cmp(A % B), ha = ccw(p2, q2, p1), hb = ccw(q2, p2, q1);
    if (cross == 0 && ccw(p1, q1, p2) == 0 && cmp(A * B) < 0) {
      if (between(p1, q1, p2)) R.push_back(q1);
      if (between(p1, q2, p2)) R.push_back(q2);
      if (between(q1, p1, q2)) R.push_back(p1);
      if (between(q1, p2, q2)) R.push_back(p2);
      if (R.size() < 2) return polygon();
      inflag = 1; break;
    } else if (cross != 0 && seg_intersect(p1, p2, q1, q2)) {
      if (inflag == 0) aa = ba = 0;
      R.push_back(line_intersect(p1, p2, q1, q2));
      inflag = (hb > 0) ? 1 : -1;
    }
    if (cross == 0 && hb < 0 && ha < 0) return R;
    bool t = cross == 0 && hb == 0 && ha == 0;
    if (t ? (inflag == 1) : (cross >= 0) ? (ha <= 0) : (hb > 0)) {
      if (inflag == -1) R.push_back(q2);
      ba++; b++; b %= m;
    } else {
      if (inflag == 1) R.push_back(p2);
      aa++; a++; a %= n;
    }
  }
  if (inflag == 0) {
    if (in_poly(P[0], Q)) return P;
    if (in_poly(Q[0], P)) return Q;
  }
  R.erase(unique(all(R)), R.end());
  if (R.size() > 1 && R.front() == R.back()) R.pop_back();
  return R;
}




const double PI = acos(-1);
int xp,yp,vp,x,y,v,r;

point origin = point(0,0);
int pode(point loc, double time){
  point nave = point(x,y);
  if(cmp( distancePointSegment(loc,nave,origin) , r ) >= 0 ){
  return cmp(time ,  abs(nave-loc)/v ) >= 0 ;
  } else {

    double distN = sqrt(dist2(nave,origin) - r * r);
    double distL = sqrt(dist2(loc,origin) - r * r);
    double angNOL = fabs(angle(nave,origin,loc)) - fabs(atan(distN/r)) - fabs(atan(distL/r));
    double menor = distN + distL + fabs(r*angNOL) ;

     return cmp(time , menor/v ) >= 0 ;
  }
}

int main(){ 
  cin >> xp >> yp >> vp >> x >> y  >> v >> r;
  int cont = 1000000;
  double R = hypot(yp, xp );
  double initial = atan2(yp, xp);
  double bot = 0;
  double timeTot = 1000000.0;
  double t1 = (2 * PI * R) / vp;
  

  double top = timeTot;
  while (top - bot > EPS) {
    double mid = (top + bot) / 2;
    

    


    

    

    double angle = ((2 * PI * mid ) / t1) + initial; 
    point loc = point( cos(angle) * R , sin(angle ) * R);
    

    if( pode(loc, mid) ){
      

      top = mid - EPS;
    } else {
      

      bot = mid + EPS;
    }
    

  }
  printf("%.7f\n",bot);
  return 0;
}
