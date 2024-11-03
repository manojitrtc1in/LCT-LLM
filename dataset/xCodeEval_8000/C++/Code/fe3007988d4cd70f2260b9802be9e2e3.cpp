#include <bits/stdc++.h>
#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <set>
#include <map>
#include <list>
#include <stack>
#include <queue>
#include <deque>
#include <vector>
#include <algorithm>
#include <functional>
#include <climits>
#include <cassert>

namespace fastIO {
  #define BUF_SIZE 100000
  

  bool IOerror = 0;
  inline char nc() {
    static char buf[BUF_SIZE], *p1 = buf + BUF_SIZE, *pend = buf + BUF_SIZE;
    if(p1 == pend) {
      p1 = buf;
      pend = buf + fread(buf, 1, BUF_SIZE, stdin);
      if(pend == p1) {
        IOerror = true;
        return -1;
      }
    }
    return *p1++;
  }
  inline bool blank(char ch) {
    return ch == ' ' || ch == '\n' || ch == '\r' || ch == '\t';
  }
  inline bool read(auto &x) {   

    bool ne = false;
    char ch;
    while(blank(ch = nc()));
    if(ch == '-') ne = true, ch = nc();
    if(IOerror) { return false; }
    for(x = ch - '0'; (ch = nc()) >= '0' && ch <= '9'; x = x * 10 + ch - '0');
    if(ne) x = -x;
    return true;
  }
  #undef BUF_SIZE
};
using namespace fastIO;

using namespace std;
#define mp make_pair
#define pb push_back
#define debug(__, x) cerr << "Case #" << ++__ << ": " << x << endl
#define Debug(__, x, y) cerr << "Case #" << ++__ << ": " << x << " " << y << endl

typedef set<int, greater<int> > gset;
typedef set<int, greater<int> >::iterator gsetit;
typedef multiset<pair<int, int>, greater<pair<int, int> > > gpmset;
typedef multiset<pair<int, int>, greater<pair<int, int> > >::iterator gpmsetit;

int __ = 0;
const double eps = 1e-5;
const int inf = 0x3f3f3f3f;
const int Inf = INT_MAX;


const long long mod = 1000000007;


const double GAMA = 0.57721566490153286060651209; 
const double PI   = 3.14159265358979323846264338;

int sgn(double x) { return abs(x) < eps ? 0 : (x > 0 ? 1 : -1); }
char itoc(int x) { return x >= 0 && x <= 9 ? x + '0' : x - 10 + 'a'; }
int ctoi(char c) { return c >= '0' && c <= '9' ? c - '0' : c - 'a' + 10; }
long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }
long long quickPow(long long a, long long p, long long mod) {
  long long pro = 1LL;
  a %= mod;
  while(p) {
    if(p & 1) { pro = pro * a % mod; }
    a = a * a % mod;  p >>= 1;
  }
  return pro;
}

struct Point {  

  double x, y;
  Point(const double &x = 0, const double &y = 0) : x(x), y(y) {}
  friend Point operator + (const Point &a, const Point &b) { return Point(a.x + b.x, a.y + b.y); }
  friend Point operator - (const Point &a, const Point &b) { return Point(a.x - b.x, a.y - b.y); }
  friend Point operator * (const double &c, const Point &a) { return Point(c * a.x, c * a.y); }  

  friend Point operator * (const Point &a, const double &c) { return Point(c * a.x, c * a.y); }  

  friend Point operator / (const Point &a, const double &c) { return Point(a.x / c, a.y / c); }
  friend Point rotate(const Point &v, double theta) {  

    return Point(v.x * cos(theta) - v.y * sin(theta), v.x * sin(theta) + v.y * cos(theta)); 
  }
  friend Point rotateAroundPoint(Point &v, Point &p, double theta) {
    return rotate(v - p, theta) + p;
  }
  friend bool operator == (const Point &a, const Point &b) {
    return !sgn(a.x - b.x) && !sgn(a.y - b.y);
  }
  friend bool operator < (const Point &a, const Point &b) {
    return sgn(a.x - b.x) < 0 || (!sgn(a.x - b.x) && sgn(a.y - b.y) < 0);
  }
  double norm() { return sqrt(x * x + y * y); }   

  friend double det(const Point &a, const Point &b) { return a.x * b.y - a.y * b.x; }   

  friend double dot(const Point &a, const Point &b) { return a.x * b.x + a.y * b.y; }   

  friend double dis(const Point &a, const Point &b) {   

    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y)); 
  }
  friend Point intersection(Point u1, Point u2, Point v1, Point v2) {  

    return u1 + (u2 - u1) * det(u1 - v1, v1 - v2) / det(u1 - u2, v1 - v2);  
  }
  double arg() { return atan2(y, x); }  

  friend double arg_2(Point u, Point v) { return acos(dot(u, v) / (u.norm() * v.norm())); }  

  friend double arg_3(const Point &a, const Point &b, const Point &c) { return arg_2(a - b, c - b); }  

};

typedef Point Vec;

struct Line {
  Point s, t;
  Line(const Point &s = Point(), const Point &t = Point()) : s(s), t(t) {}
  Point vec() const { return t - s; }  

  double norm() const { return vec().norm(); }  

  bool pointOnLine(const Point &p) { return sgn(det(p - s, t - s) == 0); }   

  bool pointOnSeg(const Point &p) { return pointOnLine(p) && sgn(dot(p - s, p - t)) <= 0; } 

  bool pointOnSegInterval(const Point &p) { return pointOnLine(p) && sgn(dot(p - s, p - t) < 0); } 

  Point pedalPointLine(const Point &p) { return s + vec() * ((dot(p - s, vec()) / norm()) / norm()); } 

  double disPointLine(const Point &p) { return fabs(det(p - s, vec()) / norm()); }  

  

  double disPointSeg(const Point &p) {
    if(sgn(dot(p - s, t - s)) < 0) return (p - s).norm();
    if(sgn(dot(p - t, s - t)) < 0) return (p - t).norm();
    return disPointLine(p);
  }
  

  int relation(const Point &p) { return sgn(det(t - s, p - s)); } 
  

  bool sameSide(const Point &a, const Point &b) { return relation(a) == relation(b); }
  

  Point symPoint(const Point &p) { 
    return 2.0 * s - p + 2.0 * (t - s) * dot(p - s, t - s) / ((t.x - s.x) * (t.x - s.x) + (t.y - s.y) * (t.y - s.y)); 
  }
  

  friend bool isParallel(const Line &l1, const Line &l2) { return sgn(det(l1.vec(), l2.vec())) == 0; }
  

  friend Point lineIntersection(const Line &l1, const Line &l2) {
    double s1 = det(l1.s - l2.s, l2.vec());
    double s2 = det(l1.t - l2.s, l2.vec());
    return (l1.t * s1 - l1.s * s2) / (s1 - s2);
  }
  

  friend Point getLineIntersection(const Line &u, const Line &v) {
    return u.s + (u.t - u.s) * det(u.s - v.s, v.s - v.t) / det(u.s - u.t, v.s - v.t);
  }
  

  friend bool isSegIntersection(Line l1, Line l2) {
    if(!sgn(det(l2.s - l1.s, l1.vec())) && !sgn(det(l2.t - l1.t, l1.vec()))) {
      return l1.pointOnSeg(l2.s) || l1.pointOnSeg(l2.t) || l2.pointOnSeg(l1.s) || l2.pointOnSeg(l1.t);
    }
    return !l1.sameSide(l2.s, l2.t) && !l2.sameSide(l1.s, l1.t);
  }
  

  friend Line move(const Line &l, const double &d) {
    Point t = l.vec(); t = t / t.norm(); t = rotate(t, PI / 2);
    return Line(l.s + t * d, l.t + t * d);
  }
  

  friend double disSegSeg(Line &l1, Line &l2) {
    double d1, d2, d3, d4;
    if(isSegIntersection(l1, l2)) return 0;
    else {
      d1 = l2.disPointSeg(l1.s);
      d2 = l2.disPointSeg(l1.t);
      d3 = l1.disPointSeg(l2.s);
      d4 = l1.disPointSeg(l2.t);
      return min(min(d1, d2), min(d3, d4));
    }
  }
  

  friend double argLineLine(Line l1, Line l2) {
    Point u = l1.t - l1.s; Point v = l2.t - l2.s;
    return acos(dot(u, v) / (u.norm() * v.norm()));
  }
};

struct Triangle {
  Triangle(const Point &a, const Point &b, const Point &c) : a(a), b(b), c(c) {};
  Point a, b, c;
  double getArea() { return det(b - a, c - a) * sin(arg_2(b - c, c - a)); }
  

  Point outCenter() {
    Line u,v;
    u.s = (a + b) / 2;
    u.t.x = u.s.x - a.y + b.y;
    u.t.y = u.s.y + a.x - b.x;
    v.s = (a + c) / 2;
    v.t.x = v.s.x - a.y + c.y;
    v.t.y = v.s.y + a.x - c.x;
    return lineIntersection(u, v);
  }
  

  Point inCenter() {
    Line u, v;
    u.s = a;
    double m = atan2(b.y - a.y, b.x - a.x);
    double n = atan2(c.y - a.y, c.x - a.x);
    u.t.x = u.s.x + cos((m + n) / 2);
    u.t.y = u.s.y + sin((m + n) / 2);
    v.s = b;
    m = atan2(a.y - b.y, a.x - b.x);
    n = atan2(c.y - b.y, c.x - b.x);
    v.t.x = v.s.x + cos((m + n) / 2);
    v.t.y = v.s.y + sin((m + n) / 2);
    return lineIntersection(u, v);
  }
  

  Point perpenCenter(){
    Line u, v;
    u.s = c;
    u.t.x = u.s.x - a.y + b.y;
    u.t.y = u.s.y + a.x - b.x;
    v.s = b;
    v.t.x = v.s.x - a.y + c.y;
    v.t.y = v.s.y + a.x - c.x;
    return lineIntersection(u, v);
  }

  

  

  

  Point baryCenter() {
      Line u((a + b) / 2, c), v((a + c) / 2, b);
      return lineIntersection(u, v);
  }

  

  Point fermentPoint(){
    if(arg_3(a, b, c) >= 2 * PI / 3) return b;
    if(arg_3(b, a, c) >= 2 * PI / 3) return a;
    if(arg_3(a, c, b) >= 2 * PI / 3) return c;
    Point ab = (a + b) / 2, ac = (a + c) / 2;
    Point z1 = sqrt(3.0) * (a - ab), z2 = sqrt(3.0) * (a - ac);
    z1 = rotate(z1, PI / 2);
    z2 = rotate(z2, PI / 2);
    if(arg_2(z1, c - ab) < PI / 2){
        z1.x = -z1.x; z1.y = -z1.y;
    }
    if(arg_2(z2, b - ac) < PI / 2){
        z2.x = -z2.x; z2.y = -z2.y;
    }
    return intersection(c, ab + z1, b, ac + z2);
  }
  

  Point FermatPoint() {
    Point u, v;
    double step = fabs(a.x) + fabs(a.y) + fabs(b.x) + fabs(b.y) + fabs(c.x) + fabs(c.y);
    u = (a + b + c) / 3;
    while(step > 1e-10) 
      for(int k = 0; k < 10; step /= 2, ++k)
      for(int i = -1; i <= 1; ++i)
      for(int j = -1; j <= 1; ++j){
      v.x = u.x + step * i;
      v.y = u.y + step * j;
      if(dis(u, a) + dis(u, b) + dis(u, c) > dis(v, a) + dis(v, b) + dis(v, c)) u = v;
    }
    return u;
  }
};

struct Polygon {
  #define _next(i) ((i + 1) % n)
  int n;
  vector<Point> p;
  

  Polygon(int n = 0): n(n) { p.resize(n); }
  

  double perimeter() { 
    double sum = 0; 
    for(int i = 0; i < n; ++i) sum += (p[_next(i)] - p[i]).norm();
    return sum;
  }
  

  double area() { 
    double sum = 0;
    for(int i = 0; i < n; ++i) sum += det(p[i], p[_next(i)]);
    return fabs(sum) / 2;
  } 

  

  int pointIn(const Point &t){
    int num = 0;
    for(int i = 0; i < n; i++) {
      if(Line(p[i], p[_next(i)]).pointOnSeg(t)) return 2;
      int k = sgn(det(p[_next(i)] - p[i], t - p[i]));
      int d1 = sgn(p[i].y - t.y);
      int d2 = sgn(p[_next(i)].y - t.y);
      if (k > 0 && d1 <= 0 && d2 > 0) num++;
      if (k < 0 && d2 <= 0 && d1 > 0) num--;
    }
    return num % 2;
  }
  

  Point baryCenter(){
    Point ans;
    if(sgn(area()) == 0) return ans;
    for(int i = 0; i < n; ++i)
      ans = ans + (p[i] + p[_next(i)]) * det(p[i], p[_next(i)]);
    return ans / area() / 6 + eps; 

  }
  

  bool isConvex(){ 

    int s[3]= {1, 1, 1};
    for(int i = 0; i < n && (s[0] || s[2]) && s[1]; ++i) {
      s[1 + sgn(det(p[_next(i)] - p[i], p[_next(_next(i))] - p[i]))] = 0;
    }
    return (s[0] || s[2]) && s[1];
  }
  bool isConvex_3(){ 

    int s[3] = {1, 1, 1};
    for (int i = 0; i < n && (s[0] || s[2]); ++i) {
      s[1 + sgn(det(p[_next(i)] - p[i], p[_next(_next(i))] - p[i]))] = 0;
    }
    return (s[0]||s[2]);
  }
  

  long long borderPointNum() {
    long long num = 0;
    for(int i = 0; i < n; ++i) {
      num += __gcd((long long)fabs(p[_next(i)].x - p[i].x), (long long)fabs(p[_next(i)].y - p[i].y));
    }
    return num;
  }
  

  long long inSidePointNum() { return (long long)(area()) + 1 - borderPointNum() / 2; }
  inline int dot_online_in(Point p, Point l1, Point l2){
    return sgn(det(p - l2,l1 - l2)) && (l1.x - p.x) * (l2.x - p.x) < eps && (l1.y - p.y) * (l2.y - p.y) < eps;
  }
  

  int insidePolygon(Line l){
    vector<Point> t;
    Point tt, l1 = l.s, l2 = l.t;
    if(!pointIn(l.s) || !pointIn(l.t)) return 0;
    for(int i = 0; i < n; ++i) {
      if(l.sameSide(p[i], p[(i+1) % n]) && l.sameSide(p[i], p[(i+1) % n]))  return 0;
      else if(dot_online_in(l1, p[i], p[(i+1) % n])) t.push_back(l1);
      else if(dot_online_in(l2, p[i], p[(i+1) % n])) t.push_back(l2);
      else if(dot_online_in(p[i], l1, l2)) t.push_back(p[i]);
    }
    for(int i = 0; i < t.size(); ++i) {
      for (int j = i + 1; j < t.size(); ++j) {
        if (!pointIn((t[i] + t[j]) / 2)) return 0;
      }
    }
    return 1;
  }
};

struct Convex : public Polygon {
  Convex(int n = 0) : Polygon(n) {}
  


  

  bool isUnique(vector<Point> &v) {
    if(sgn(area()) == 0) return 0;
    for(int i = 0; i < n; ++i) {
      Line l(p[i], p[_next(i)]);
      bool flag = 0;
      for(int j = 0; j < v.size(); ++j) {
        if(l.pointOnSegInterval(v[j])){
          flag = 1;
          break;
        }
      }
      if (!flag) return 0;
    }
    return 1;
  }
  

  bool containon(const Point &a) {
    for(int sign = 0, i = 0; i < n; ++i) {
      int x = sgn(det(p[i] - a, p[_next(i)] - a));
      if(x == 0) continue; 

      if(!sign) sign = x;
      else if(sign != x) return 0;
    }
    return 1;
  }
  

  bool containologn(const Point &a){
    Point g = (p[0] + p[n / 3] + p[2.0 * n / 3]) / 3.0;
    int l = 0, r = n;
    while(l + 1 < r) {
      int m = (l + r) >> 1;
      if(sgn(det(p[l] - g, p[m] - g)) > 0) {
        if(sgn(det(p[l] - g, a - g)) >= 0 && sgn(det(p[m] - g, a - g)) < 0) r = m;
        else l = m;
      } else {
        if(sgn(det(p[l] - g, a - g)) < 0 && sgn(det(p[m] - g, a - g)) >= 0) l = m;
        else r = m;
      }
    }
    return sgn(det(p[r % n] - a, p[l] - a)) - 1;
  }
  

  int fir, sec; 

  double diameter() {
    double mx = 0;
    if(n == 1){
      fir = sec = 0;
      return mx;
    }
    for(int i = 0, j = 1; i < n; ++i){
      while(sgn(det(p[_next(i)] - p[i], p[j] - p[i]) - det(p[_next(i)] - p[i], p[_next(j)] - p[i])) < 0) {
        j = _next(j);
      }
      double d = dis(p[i], p[j]);
      if(d > mx) {
        mx = d;
        fir = i;
        sec = j;
      }
      d = dis(p[_next(i)], p[_next(j)]);
      if(d > mx) {
        mx = d;
        fir = _next(i);
        sec = _next(j);
      }
    }
    return mx;
  }

  

  vector<double> ang; 

  bool isinitangle;
  int finda(const double &x) { return upper_bound(ang.begin(), ang.end(), x) - ang.begin(); }
  double getAngle(const Point &p) { 

    double res = atan2(p.y, p.x);   



    if(res < -PI / 2 + eps) res += 2 * PI; 

    return res;
  }
  void initAngle() {
    for(int i = 0; i < n; ++i) {
      ang.push_back(getAngle(p[_next(i)] - p[i]));
    }
    isinitangle = 1;
  }
  bool isxLine(const Line &l){
    if(!isinitangle) initAngle();
    int i = finda(getAngle(l.t - l.s));
    int j = finda(getAngle(l.s - l.t));
    if(sgn(det(l.t - l.s, p[i] - l.s) * det(l.t - l.s, p[j] - l.s) >= 0)) return 0;
    return 1;
  }
};

Convex ConvexHull(vector<Point> &a){ 

  Convex res(2 * a.size() + 7);      

  sort(a.begin(), a.end());
  a.erase(unique(a.begin(), a.end()), a.end()); 

  int m = 0;
  for(int i = 0; i < a.size(); ++i) {
    

    while(m > 1 && sgn(det(res.p[m - 1] - res.p[m - 2], a[i] - res.p[m - 2])) <= 0) m--;
    res.p[m++] = a[i];
  }
  int k = m;
  for(int i = a.size() - 2; i >= 0; --i) {
    while(m > k && sgn(det(res.p[m - 1] - res.p[m - 2], a[i] - res.p[m - 2])) <= 0) m--;
    res.p[m++] = a[i];
  }
  if(m > 1) m--;
  res.p.resize(m);
  res.n = m;
  return res;
}

struct HalfPlane: public Line { 

  

  double a, b, c;
  

  HalfPlane(const Point &s = Point(), const Point &t = Point()): Line(s, t) {
    a = t.y - s.y;
    b = s.x - t.x;
    c = det(t, s);
  }
  HalfPlane(double a, double b, double c) : a(a), b(b), c(c) {}
  

  double calc(const Point &p) const { return p.x * a + p.y * b + c; }
  

  friend Point halfxLine(const HalfPlane &h, const Line &l){
    Point res;
    double t1 = h.calc(l.s), t2 = h.calc(l.t);
    res.x = (t2 * l.s.x - t1 * l.t.x) / (t2 - t1);
    res.y = (t2 * l.s.y - t1 * l.t.y) / (t2 - t1);
    return res;
  }
  

  friend Point halfxHalf(const HalfPlane &h1, const HalfPlane &h2){
    return Point((h1.b * h2.c - h1.c * h2.b) / (h1.a * h2.b - h2.a * h1.b) + eps,
                 (h1.a * h2.c - h2.a * h1.c) / (h1.b * h2.a - h1.a * h2.b) + eps);
  }
  

  friend Convex halfxConvex(const HalfPlane &h, const Convex &c){
    Convex res;
    for(int i = 0; i < c.n; ++i) {
      if(h.calc(c.p[i]) < -eps) {
        res.p.push_back(c.p[i]);
      } else {
        int j = i - 1;
        if(j < 0) j = c.n - 1;
        if(h.calc(c.p[j]) < -eps) {
          res.p.push_back(halfxLine(h, Line(c.p[j], c.p[i])));
        }
        j = i + 1;
        if(j == c.n) j = 0;
        if(h.calc(c.p[j]) < -eps) {
          res.p.push_back(halfxLine(h, Line(c.p[i], c.p[j])));
        }
      }
    }
    res.n = res.p.size();
    return res;
  }
  

  friend int satisfy(const Point &p, const HalfPlane &h){ return sgn(det(p - h.s, h.t - h.s)) <= 0; }
  friend bool operator < (const HalfPlane &h1, const HalfPlane &h2) {
    int res = sgn(h1.vec().arg() - h2.vec().arg());
    return res == 0 ? satisfy(h1.s, h2) : res < 0;
  }
  

  friend Convex halfx(vector<HalfPlane> &v) {
    sort(v.begin(), v.end());
    deque<HalfPlane> q;
    deque<Point> ans;
    q.push_back(v[0]);
    for(int i = 1; i < v.size(); ++i) {
      if(sgn(v[i].vec().arg() - v[i - 1].vec().arg()) == 0) continue;
      while(ans.size() > 0 && !satisfy(ans.back(), v[i])) {
        ans.pop_back(); q.pop_back();
      }
      while(ans.size() > 0 && !satisfy(ans.front(), v[i])) {
        ans.pop_front(); q.pop_front();
      }
      ans.push_back(lineIntersection(q.back(), v[i]));
      q.push_back(v[i]);
    }
    while(ans.size() > 0 && !satisfy(ans.back(), q.front())) {
      ans.pop_back(); q.pop_back();
    }
    while(ans.size() > 0 && !satisfy(ans.front(), q.back())) {
      ans.pop_front(); q.pop_front();
    }
    ans.push_back(lineIntersection(q.back(), q.front()));
    Convex c(ans.size());
    int i = 0;
    for(deque<Point>::iterator it = ans.begin(); it != ans.end(); ++it, ++i) {
      c.p[i] = *it;
    }
    return c;
  }
};


Convex core(const Polygon &a) {
  Convex res;
  res.p.push_back(Point(-inf, -inf));
  res.p.push_back(Point(inf, -inf));
  res.p.push_back(Point(inf, inf));
  res.p.push_back(Point(-inf, inf));
  res.n = 4;
  for(int i = 0; i < a.n; i++) {
    res = halfxConvex(HalfPlane(a.p[i], a.p[(i + 1) % a.n]), res);
  }
  return res;
}


Convex convexxConvex(Convex &c1, Convex &c2){
  vector<HalfPlane> h;
  for(int i = 0; i < c1.p.size(); ++i) {
    h.push_back(HalfPlane(c1.p[i], c1.p[(i + 1) % c1.p.size()]));
  }
  for(int i = 0; i < c2.p.size(); i++) {
    h.push_back(HalfPlane(c2.p[i], c2.p[(i + 1) % c2.p.size()]));
  }
  return halfx(h);
}

double sqr(double x) { return x * x; }
double mysqrt(double n) { return sqrt(max(0.0, n)); } 

struct Circle {
  Point o;
  double r;
  Circle(Point o = Point(), double r = 0): o(o), r(r) {}
  bool operator == (const Circle &c){ return o == c.o && !sgn(r - c.r); }
  double area() { return PI * r * r; }
  double perimeter(){ return r * PI * 2; }
  

  bool pointIn(const Point &p){ return sgn((p - o).norm() - r) < 0; }
  

  friend int isLineCircleIntersection(Line L, Circle c) { return L.disPointLine(c.o) < c.r + eps; }
  

  friend int isSegCircleIntersection(Line L, Circle c){
    double t1 = dis(c.o, L.s) - c.r, t2 = dis(c.o, L.t) - c.r;
    Point t = c.o;
    if(t1 < eps || t2 < eps) return t1 > -eps || t2 > -eps;
    t.x += L.s.y - L.t.y;
    t.y += L.t.x - L.s.x;
    return det(L.s - t,c.o - t) * det(L.t - t,c.o - t) < eps && L.disPointLine(c.o) < c.r + eps;
  }
  

  friend int isCirCirIntersection(Circle c1, Circle c2) {
    return dis(c1.o, c2.o) < c1.r + c2.r + eps && dis(c1.o, c2.o) > fabs(c1.r - c2.r) - eps;
  }
  

  friend Point dotPointCircle(Point p, Circle C){
    Point u, v, c = C.o;
    if(dis(p, c) < eps) return p;
    u.x = c.x + C.r * fabs(c.x - p.x) / dis(c, p);
    u.y = c.y + C.r * fabs(c.y - p.y) / dis(c, p) * ((c.x - p.x) * (c.y - p.y) < 0 ? -1 : 1);
    v.x = c.x - C.r * fabs(c.x - p.x) / dis(c, p);
    v.y = c.y - C.r * fabs(c.y - p.y) / dis(c, p) * ((c.x - p.x) * (c.y - p.y) < 0 ? -1 : 1);
    return dis(u, p) < dis(v, p) ? u : v;
  }
  

  friend vector<Point> segCircleIntersection(const Line &l, const Circle &c) {
    double dx = l.t.x - l.s.x, dy = l.t.y - l.s.y;
    double A = dx * dx + dy * dy;
    double B = 2 * dx * (l.s.x - c.o.x) + 2 * dy * (l.s.y - c.o.y);
    double C = sqr(l.s.x - c.o.x) + sqr(l.s.y - c.o.y) - sqr(c.r);
    double delta = B * B - 4 * A * C;
    vector<Point> res;
    if(A < eps) return res;
    if(sgn(delta) >= 0) 

    {
      

      double w1 = (-B - mysqrt(delta)) / (2 * A);
      double w2 = (-B + mysqrt(delta)) / (2 * A);
      if(sgn(w1 - 1) <= 0 && sgn(w1) >= 0) {
        res.push_back(l.s + w1 * (l.t - l.s));
      }
      if(sgn(w2 - 1) <= 0 && sgn(w2) >= 0 && fabs(w1-w2)>eps) {
        res.push_back(l.s + w2 * (l.t - l.s));
      }
    }
    return res;
  }
  

  friend vector<Point> lineCircleIntersection(const Line &l, const Circle &c) {
    double dx = l.t.x - l.s.x, dy = l.t.y - l.s.y;
    double A = dx * dx + dy * dy;
    double B = 2 * dx * (l.s.x - c.o.x) + 2 * dy * (l.s.y - c.o.y);
    double C = sqr(l.s.x - c.o.x) + sqr(l.s.y - c.o.y) - sqr(c.r);
    double delta = B * B - 4 * A * C;
    vector<Point> res;
    if(A < eps) return res;
    if(sgn(delta) >= 0) 

    {
      double w1 = (-B - mysqrt(delta)) / (2 * A);
      double w2 = (-B + mysqrt(delta)) / (2 * A);
      res.push_back(l.s + w1 * (l.t - l.s));
      if(fabs(w1 - w2) > eps)
      res.push_back(l.s + w2 * (l.t - l.s));
    }
    return res;
  }
  

  friend vector<Point> cirCirIntersection(Circle a, Circle b) {
    Point c1 = a.o, c2 = b.o;
    double r1 = a.r, r2 = b.r;
    vector<Point> vec;
    if(dis(a.o, b.o) + eps > a.r + b.r && dis(a.o, b.o) < fabs(a.r - b.r) + eps) return vec;
    Line L;
    double t = (1.0 + (sqr(a.r) - sqr(b.r)) / sqr(dis(a.o, b.o))) / 2;
    L.s = c1 + (b.o - a.o) * t;
    L.t.x = L.s.x + a.o.y - b.o.y;
    L.t.y = L.s.y - a.o.x + b.o.x;
    return lineCircleIntersection(L, a);
  }
  

  

  friend vector<Point> tangentPointCircle(Point poi, Circle C) {
    Point o = C.o; double r = C.r;
    vector<Point> vec;
    double dist = (poi - o).norm();
    if(dist < r - eps) return vec;
    if(fabs(dist - r) < eps) {
      vec.push_back(poi); return vec;
    }
    Point res1, res2;
    double line = sqrt((poi.x - o .x) * (poi.x - o.x) + (poi.y - o.y) * (poi.y - o.y));
    double angle = acos(r / line);
    Point unitVector, lin;
    lin.x = poi.x - o.x;
    lin.y = poi.y - o.y;
    unitVector.x = lin.x / sqrt(lin.x * lin.x + lin.y * lin.y) * r;
    unitVector.y = lin.y / sqrt(lin.x * lin.x + lin.y * lin.y) * r;
    res1 = rotate(unitVector, -angle) + o;
    res2 = rotate(unitVector, angle) + o;
    vec.push_back(res1);
    vec.push_back(res2);
    return vec;
  }
  

  double sectorArea(const Point &a, const Point &b) const {
    double theta = atan2(a.y, a.x) - atan2(b.y, b.x);
    while(theta < 0) theta += 2 * PI;
    while(theta > 2.0 * PI) theta -= 2 * PI;
    theta = min(theta, 2.0 * PI - theta);
    return sgn(det(a, b)) * theta * r * r / 2.0; 
  }
  

  double areaSegCircle(const Line &L) const {
    Point a = L.s, b = L.t;
    vector<Point> p = segCircleIntersection(Line(a, b), *this);
    bool ina = sgn((a - o).norm() - r) < 0;
    bool inb = sgn((b - o).norm() - r) < 0;
    if(ina) {
      if(inb) return det(a - o, b - o) / 2;
      else return det(a - o, p[0] - o) / 2 + sectorArea(p[0] - o, b - o);
    } else{
      if(inb) return det(p[0] - o, b - o) / 2 + sectorArea(a - o, p[0] - o);
      else {
        if(p.size() == 2) {
          return sectorArea(a - o, p[0] - o) + sectorArea(p[1] - o, b - o) + det(p[0] - o, p[1] - o) / 2;
        } else {
          return sectorArea(a - o, b - o);
        }
      }
    }
  }

  

  friend double areaPolygonCircle(const Circle &c, const Polygon &a) {
    int n = a.p.size();
    double ans = 0;
    for(int i = 0; i < n; ++i) {
      if(sgn(det(a.p[i] - c.o, a.p[_next(i)] - c.o)) == 0) { continue; }
      ans += c.areaSegCircle((a.p[i], a.p[_next(i)]));
    }
    return ans;
  }
  

  friend double areaCircleCircle(const Circle &A, const Circle &B) {
    double ans = 0.0;
    Circle M = (A.r > B.r) ? A : B;
    Circle N = (A.r > B.r) ? B : A;
    double D = dis(M.o, N.o);
    if((D < M.r + N.r) && (D > M.r - N.r)) {
      double alpha = 2.0 * acos((M.r * M.r + D * D - N.r * N.r) / (2.0 * M.r * D));
      double beta  = 2.0 * acos((N.r * N.r + D * D - M.r * M.r) / (2.0 * N.r * D));
      ans = (alpha / (2 * PI)) * M.area() + (beta / (2 * PI)) * N.area() - 0.5 * M.r * M.r * sin(alpha) - 0.5 * N.r * N.r * sin(beta);
    } else if(D <= M.r - N.r) {
      ans = N.area();
    }
    return ans;
  }

  

  Circle getCircle3(const Point &p0, const Point &p1, const Point &p2) {
    double a1 = p1.x - p0.x, b1 = p1.y - p0.y, c1 = (a1 * a1 + b1 * b1) / 2;
    double a2 = p2.x - p0.x, b2 = p2.y - p0.y, c2 = (a2 * a2 + b2 * b2) / 2;
    double d = a1 * b2 - a2 * b1;
    Point o(p0.x + (c1 * b2 - c2 * b1) / d, p0.y + (a1 * c2 - a2 * c1) / d);
    return Circle(o, (o - p0).norm());
  }
  

  Circle getCircle2(const Point &p0, const Point &p1) {
    Point o((p0.x + p1.x) / 2, (p0.y + p1.y) / 2);
    return Circle(o, (o - p0).norm());
  }
  

  Circle minCirCover(vector<Point> &a) {
    int n = a.size();
    Circle c(a[0], 0);
    for(int i = 1; i < n; ++i) {
      if (!c.pointIn(a[i])) {
        c.o = a[i];
        c.r = 0;
        for(int j = 0; j < i; ++j) {
          if (!c.pointIn(a[j])) {
            c = getCircle2(a[i], a[j]);
            for(int k = 0; k < j; ++k) {
              if (!c.pointIn(a[k])) {
                c = getCircle3(a[i], a[j], a[k]);
              }
            }
          }
        }
      }
    }
    return c;
  }
  

  friend double lengthSegInCircle(Line a, Circle c) {
    if(c.pointIn(a.s) && c.pointIn(a.t)) return a.norm();
    vector<Point> vec = segCircleIntersection(a, c);
    if(vec.size() == 0) return 0;
    if(vec.size() == 1) {
      if(c.pointIn(a.s)) return dis(vec[0], a.s);
      if(c.pointIn(a.t)) return dis(vec[0], a.t);
      return 0;
    }
    return dis(vec[0], vec[1]);
  }
  

  friend double lengthPolygonInCircle(Polygon a, Circle c) {
    double ans=0;
    for(int i = 0;i<a.n; ++i) {
    Line li; li.s = a.p[i]; li.t = a.p[(i+1) % a.n];
      ans += lengthSegInCircle(li, c);
    }
    return ans;
  }
  

  friend double lengthCircleInCircle(Circle a, Circle b) {
    if(a.r > b.r && a.r - b.r + eps > dis(a.o, b.o)) return b.perimeter();
    vector<Point> vec = cirCirIntersection(a, b);
    if(vec.size() < 2) return 0;
    Line l1 = (vec[0], b.o), l2 = (vec[1], b.o);
    double ans = b.r * arg_3(vec[0], b.o, vec[1]);
    if(b.r >= a.r || !a.pointIn(b.o)) return b.r * ans;
    return b.perimeter() - ans;
  }
};

const int MAXN  = 5000 + 7;
Point p[MAXN];
double inline getArea(const Point &a, const Point &b, const Point &c) {
  return abs((b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x));
}

int main() {
  #ifdef Zonda_R
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
  #endif
  int n;
  double s;
  scanf("%d %lf", &n, &s);
  for(int i = 0; i < n; ++i) {
    scanf("%lf %lf", &p[i].x, &p[i].y);
  }
  sort(p, p + n, [&](Point &a, Point &b) {
    return a.x == b.x ? a.y < b.y : a.x < b.x;
  });
  unique(p, p + n);
  int a = 0, b = 1, c = 2;
  double ss = Triangle(p[a], p[b], p[c]).getArea();
  while(true) {
    bool check = false;
    for(int i = 0; i < n; ++i) {
      double tt = getArea(p[a], p[b], p[i]);
      if(tt > ss) { ss = tt; c = i; check = true; }
    }
    for(int i = 0; i < n; ++i) {
      double tt = getArea(p[a], p[c], p[i]);
      if(tt > ss) { ss = tt; b = i; check = true; }
    }
    for(int i = 0; i < n; ++i) {
      double tt = getArea(p[b], p[c], p[i]);
      if(tt > ss) { ss = tt; a = i; check = true; }
    }
    if(!check) break;
  }
  printf("%.0f %.0f\n", p[b].x + p[c].x - p[a].x, p[b].y + p[c].y - p[a].y);
  printf("%.0f %.0f\n", p[b].x + p[a].x - p[c].x, p[b].y + p[a].y - p[c].y);
  printf("%.0f %.0f\n", p[a].x + p[c].x - p[b].x, p[a].y + p[c].y - p[b].y);
  return 0;
}