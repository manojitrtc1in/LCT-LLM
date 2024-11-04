#include <bits/stdc++.h>




#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

using namespace std;

typedef vector<int> vi;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef pair<int, int> pii;
typedef pair<long long, long long> PLL;
typedef pair<int, PII> TIII;
typedef long long LL;
typedef long long ll;
typedef unsigned long long ULL;
typedef long double ld;
typedef vector<LL> VLL;
typedef vector<VLL> VVLL;

#define FOR(i, s, n) for (int i = s; i < (int)n; ++i)
#define REP(i, n) FOR(i, 0, n)
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define trav(a, x) for (auto &a : x)
#define all(x) x.begin(), x.end()

#define MOD 1000000007

template<class T1, class T2> inline bool chmax(T1 &a, T2 b) {if (a < b) {a = b; return true;} return false;}
template<class T1, class T2> inline bool chmin(T1 &a, T2 b) {if (a > b) {a = b; return true;} return false;}
const double EPS = 1e-9, PI = acos(-1);
const double pi = 3.141592653589793238462643383279;


typedef string::const_iterator State;
template< int mod >
struct ModInt {
  int x;

  ModInt() : x(0) {}

  ModInt(int64_t y) : x(y >= 0 ? y % mod : (mod - (-y) % mod) % mod) {}

  ModInt &operator+=(const ModInt &p) {
    if((x += p.x) >= mod) x -= mod;
    return *this;
  }

  ModInt &operator-=(const ModInt &p) {
    if((x += mod - p.x) >= mod) x -= mod;
    return *this;
  }

  ModInt &operator*=(const ModInt &p) {
    x = (int) (1LL * x * p.x % mod);
    return *this;
  }

  ModInt &operator/=(const ModInt &p) {
    *this *= p.inverse();
    return *this;
  }

  ModInt operator-() const { return ModInt(-x); }

  ModInt operator+(const ModInt &p) const { return ModInt(*this) += p; }

  ModInt operator-(const ModInt &p) const { return ModInt(*this) -= p; }

  ModInt operator*(const ModInt &p) const { return ModInt(*this) *= p; }

  ModInt operator/(const ModInt &p) const { return ModInt(*this) /= p; }

  bool operator==(const ModInt &p) const { return x == p.x; }

  bool operator!=(const ModInt &p) const { return x != p.x; }

  ModInt inverse() const {
    int a = x, b = mod, u = 1, v = 0, t;
    while(b > 0) {
      t = a / b;
      swap(a -= t * b, b);
      swap(u -= t * v, v);
    }
    return ModInt(u);
  }

  ModInt pow(int64_t n) const {
    ModInt ret(1), mul(x);
    while(n > 0) {
      if(n & 1) ret *= mul;
      mul *= mul;
      n >>= 1;
    }
    return ret;
  }

  friend ostream &operator<<(ostream &os, const ModInt &p) {
    return os << p.x;
  }

  friend istream &operator>>(istream &is, ModInt &a) {
    int64_t t;
    is >> t;
    a = ModInt< mod >(t);
    return (is);
  }

  static int get_mod() { return mod; }
};

using modint = ModInt< 998244353 >;
template< typename T >
struct Combination {
  vector< T > _fact, _rfact, _inv;

  Combination(int sz) : _fact(sz + 1), _rfact(sz + 1), _inv(sz + 1) {
    _fact[0] = _rfact[sz] = _inv[0] = 1;
    for(int i = 1; i <= sz; i++) _fact[i] = _fact[i - 1] * i;
    _rfact[sz] /= _fact[sz];
    for(int i = sz - 1; i >= 0; i--) _rfact[i] = _rfact[i + 1] * (i + 1);
    for(int i = 1; i <= sz; i++) _inv[i] = _rfact[i] * _fact[i - 1];
  }

  inline T fact(int k) const { return _fact[k]; }

  inline T rfact(int k) const { return _rfact[k]; }

  inline T inv(int k) const { return _inv[k]; }

  T P(int n, int r) const {
    if(r < 0 || n < r) return 0;
    return fact(n) * rfact(n - r);
  }

  T C(int p, int q) const {
    if(q < 0 || p < q) return 0;
    return fact(p) * rfact(q) * rfact(p - q);
  }

  T H(int n, int r) const {
    if(n < 0 || r < 0) return (0);
    return r == 0 ? 1 : C(n + r - 1, r);
  }
};
ll GCD(ll a, ll b){
  return (b==0)?a:GCD(b, a%b);
}
ll LCM(ll a, ll b){
  return a/GCD(a, b) * b;
}
using Point = complex< double >;
bool eq(double a, double b){ return fabs(a-b) < EPS; }
namespace std {
  bool operator<(const Point a, const Point b) {
    if(eq(a.real(),b.real())) return a.imag() < b.imag();
    return a.real() < b.real();
  }
}

istream &operator>> (istream &is, Point &p) {
  double a, b;
  is >> a >> b;
  p = Point(a, b);
  return is;
}

ostream &operator<< (ostream &os, Point &p) {
  return os << fixed << setprecision(10) << p.real() << " " << p.imag();
}

bool operator<(const Point &a, const Point &b) {
  return a.real() != b.real() ? a.real() < b.real() : a.imag() < b.imag();
}









Point rotate(double phi, const Point &p) {
  double x = p.real(), y = p.imag();
  return Point(x * cos(phi) - y * sin(phi), x * sin(phi) + y * cos(phi));
}

double radian_to_degree(double r) {
  return (r * 180.0 / PI);
}

double degree_to_radian(double d) {
  return (d * PI / 180.0);
}

struct Line{
  Point a, b;

  Line() = default;

  Line(Point a, Point b) : a(a), b(b){}

  Line(double A, double B, double C){
    

    if(eq(A, 0)){
      a = Point(0, C/B), b = Point(1, C/B);
    }else if(eq(B, 0)){
      a = Point(C/A, 0), b = Point(C/A, 1);
    }else{
      a = Point(0, C/B), b = Point(C/A, 0);
    }
  }

  friend istream &operator>>(istream &is, Line &a) {
    return is >> a.a >> a.b;
  }
  friend ostream &operator<<(ostream &os, Line &a) {
    return os << a.a << " to " << a.b;
  }
};

struct Segment: Line {
  Segment() = default;

  Segment(Point a, Point b) : Line(a, b) {}
};

struct Circle {
  Point p;
  double r;

  Circle() = default;

  Circle(Point p, double r): p(p), r(r){}
};

using Points = vector<Point>;
using Polygon = vector<Point>;
using Segments = vector<Segment>;
using Lines = vector<Line>;
using Circles = vector<Circle>;

double cross(const Point &a, const Point &b) {
  return a.real() * b.imag() - a.imag() * b.real();
}

double dot(const Point& a, const Point &b) {
  return a.real() * b.real() + a.imag() * b.imag();
}



Point projection(const Line &l, const Point &p){
  double t = dot(p - l.a, l.a-l.b) / norm(l.a - l.b);
  return l.a + (l.a - l.b) * t;
}

Point projection(const Segment &l, const Point &p){
  double t = dot(p - l.a, l.b-l.a) / norm(l.a - l.b);
  return l.a + (l.b - l.a) * t;
}

Point reflection(const Line &l, const Point &p){
  return p + (projection(l, p) - p) * 2.0;
}

int ccw(const Point &a, const Point &b, const Point &c) {
  if(cross(b-a, c-a) > EPS) return 1;   

  if(cross(b-a, c-a) < -EPS) return -1; 

  if(dot(b-a, c-a) < -EPS) return 2;    

  if(norm(b-a) < norm(c-a) - EPS) return -2;  

  return 0;                         

}

bool parallel(const Line &a, const Line &b){
  return eq(cross(a.a-a.b, b.a-b.b), 0.0);
}
bool orthogonal(const Line &a, const Line &b){
  return eq(dot(a.a-a.b, b.a-b.b), 0.0);
}
enum { OUT, ON, IN };

int contains(const Polygon& Q, const Point& p){
  bool in = false;
  for(int i=0; i<Q.size(); i++){
    Point a = Q[i] - p, b = Q[(i+1)%Q.size()]-p;
    if(a.imag() > b.imag()) swap(a, b);
    if(a.imag() <= 0 && 0 < b.imag() && cross(a, b) < 0) in = !in;
    if(cross(a, b) == 0 && dot(a, b) <= 0) return ON;
  }
  return in ? IN : OUT;
}
bool intersect(const Segment &s, const Point &p){
  return ccw(s.a, s.b, p) == 0;
}



bool intersect(const Line &a, const Line &b) {
  if(parallel(a, b)) return 0;
  return 1;
}



bool intersect(const Segment &a, const Segment &b) {
  return ccw(a.a, a.b, b.a) * ccw(a.a, a.b, b.b) <= 0 && ccw(b.a, b.b, a.a) * ccw(b.a, b.b, a.b) <= 0;
}

bool intersect(const Line &l, const Segment &s) {
  
}

Point crosspoint(const Line &a, const Line &b){
  double d = cross(b.b-b.a, a.b-a.a);
  if(eq(d, 0.0)) return Point(1e9, 1e9); 
  
  return a.a + (a.b - a.a) * cross(b.b-b.a, b.b-a.a) / d;
}

Point crosspoint(const Segment &a, const Segment &b){
  return crosspoint(Line(a.a, a.b), Line(b.a, b.b));
}
double distance(const Point &a, const Point &b){
  return abs(a - b);
}
double distance(const Line &l, const Point &p){
  return abs( cross(p - l.a, l.b-l.a) / abs(l.b-l.a) );
}
double distance(const Segment &s, const Point &p){
  Point r = projection(s, p);
  if(intersect(s, r)) return abs(r-p);
  return min(abs(s.a - p), abs(s.b - p));
}










double distance(const Segment &a, const Segment &b) {
  return intersect(a, b) ? 0 : min({distance(a, b.a), distance(a, b.b), distance(b, a.a), distance(b, a.b)});
}


vector<Point> crosspointCC(Circle C1, Circle C2){
  vector<Point> ps;
  Point ab = C2.p - C1.p;
  double d = abs(ab);
  double rc = (C1.r * C1.r + d * d - C2.r * C2.r) / (2 * d);
  if(eq(d, 0) || C1.r < abs(rc)) return ps;

  double rs = sqrt(C1.r * C1.r - rc*rc);

  Point abN = ab * Point(0, rs/d);
  Point cp = C1.p + rc / d * ab;
  ps.push_back(cp + abN);
  if(!eq(norm(abN), 0))ps.push_back(cp-abN);
  return ps;
}

vector<Point> crosspointCL(Circle C, Line l){
  Point p = projection(l, C.p);

  Point e = (l.b-l.a)/abs(l.b-l.a);
  if(eq(distance(l, C.p), C.r)) {
    return vector<Point>{p, p};
  }
  double base = sqrt(C.r*C.r-norm(p-C.p));
  
  return vector<Point>{p+e*base, p-e*base};
}




long double AreaofCC(Circle& C1, Circle& C2){
  if(C1.r > C2.r) swap(C1, C2);
  long double nor = norm(C1.p - C2.p);
  long double dist = sqrtl(nor);
  
  if(C1.r + C2.r < dist+EPS) return 0;

  if(dist + C1.r < C2.r + EPS) return C1.r * C1.r * PI;

  long double theta1 = acosl((nor + C1.r*C1.r - C2.r * C2.r)/(2*C1.r*dist));

  long double theta2 = acosl((nor + C2.r*C2.r - C1.r * C1.r)/(2*C2.r*dist));
  
  return (theta1 - sinl(theta1+ theta1) *0.5) * C1.r * C1.r + (theta2 - sinl(theta2+theta2) *0.5) * C2.r * C2.r;
}


Polygon convex_hull(Polygon &p)
{
    int n = (int)p.size(), k = 0;
    if (n <= 2)
        return p;
    sort(p.begin(), p.end());
    vector<Point> ch(n * 2);

    for (int i = 0; i < n; ch[k++] = p[i++])
    {
        while (k >= 2 && cross(ch[k - 1] - ch[k - 2], p[i] - ch[k - 1]) < 0)
            --k;
    }

    for (int i = n - 2, t = k + 1; i >= 0; ch[k++] = p[i--])
    {
        while (k >= t && cross(ch[k - 1] - ch[k - 2], p[i] - ch[k - 1]) < 0)
            --k;
    }
    ch.resize(k - 1);
    return ch;
}
double convex_diameter(const Polygon &p)
{
    int n = (int)p.size();
    if (n == 2)
        return abs(p[0] - p[1]);

    int is = 0, js = 0;
    for (int i = 1; i < n; ++i)
    {
        if (imag(p[i]) > imag(p[is]))
            is = i;
        if (imag(p[i]) < imag(p[js]))
            js = i;
    }

    double res = abs(p[is] - p[js]);
    int i, maxi, j, maxj;
    i = maxi = is;
    j = maxj = js;
    do
    {
        if (cross(p[(i + 1) % n] - p[i], p[(j + 1) % n] - p[j]) >= 0)
            j = (j + 1) % n;
        else
            i = (i + 1) % n;
        res = max(res, abs(p[i] - p[j]));
    } while (i != is || j != js);
    return res;
}

Polygon convex_cut(const Polygon &p, const Line l)
{
    Polygon ret;
    for (int i = 0; i < p.size(); ++i)
    {
        Point now = p[i], nxt = p[(i + 1) % p.size()];
        if (ccw(l.a, l.b, now) != -1) 

            ret.push_back(now);
        if (ccw(l.a, l.b, now) * ccw(l.a, l.b, nxt) < 0)
        {
            ret.push_back(crosspoint(Line(now, nxt), l));
        }
    }
    return (ret);
}
double closestpair(Points &a, int l, int r){
  if(r-l<=1) return 1e20;
  int mid = (l+r)/2;

  double X = a[mid].real();
  double d = min(closestpair(a, l, mid), closestpair(a, mid, r));
  inplace_merge(a.begin()+l, a.begin()+mid, a.begin()+r, [](const Point& pa, const Point& pb){
    return pa.imag() < pb.imag();
  });

  Points b;
  for(int i=l; i<r; i++){
    if(abs(a[i].real()-X) >= d) continue;
    for(int j=b.size()-1; j>=0; j--){
      if(abs((a[i]-b[j]).imag()) >= d) break;
      d = min(d, abs(a[i]-b[j]));
    }
    b.push_back(a[i]);
  }
  return d;
}



int intersectionCC(Circle c1, Circle c2){
  if(c1.r > c2.r) swap(c1, c2);
  double d1 = abs(c1.p-c2.p); 
  double d2 = c1.r + c2.r;
  if(d1 > d2) return 4; 
  else if(d1 == d2) return 3; 
  else{
    if(c2.r == c1.r + d1) return 1; 
    else if(c2.r > c1.r + d1) return 0; 
    else return 2; 
  }
}


double Area(Points &g){
  double res = 0;
  int n = g.size();
  REP(i,n){
    res += cross(g[i], g[(i+1)%n]);
  }
  return res/2.0;
}



pair<Point, double> incircle_of_a_Triangle(Points &p){

  double a = abs(p[1]-p[2]), b = abs(p[2]-p[0]), c = abs(p[0]-p[1]);
  double s = (a+b+c) / 2.0;
  double S = sqrtl(s*(s-a)*(s-b)*(s-c));
  double r = S/s; 
  
  Point pp = (a*p[0]+b*p[1]+c*p[2])/(a+b+c);
  return make_pair(pp, r);
} 


pair<Point, double> circumscribed_circle_of_a_triangle(Points &p){

  Point m1((p[0]+p[1])/2.0), m2((p[1]+p[2])/2.0);
  Point v((p[1]-p[0]).imag(), (p[0]-p[1]).real()), w((p[1]-p[2]).imag(), (p[2]-p[1]).real());

  Line l1(m1, Point(v+m1)), l2(m2, Point(w+m2));

  Point x = crosspoint(l1, l2);
  double r = abs(x-p[0]);
  return make_pair(x, r);
}


Points tangent_to_a_circle(Point p, Circle C){
  Points ps;
  double d = abs(C.p-p);
  if(eq(d,0)){
    ps.push_back(p);
  }else if(d>EPS){
    
    double d2 = sqrt(d*d-C.r*C.r);
    
    long double theta = acosl(d2/d);
    

    Point pp = C.p - p;
    Point p2 = rotate(-theta, pp);

    Point e = p2/abs(p2);
    Point ppp = e*d2;
    ps.push_back(p + ppp);
    p2 = rotate(theta, pp);
    e = p2/abs(p2);
    ppp = e*d2;
    ps.push_back(p + ppp);
    
  }
  return ps;
}

Lines tangent(Circle C1, Circle C2){
  Lines ls;
  if(C1.r < C2.r) swap(C1, C2);
  double d = norm(C1.p - C2.p);
  if(eq(d, 0)) return ls;
  Point u = (C2.p - C1.p) / sqrt(d);
  Point v = rotate(pi/2, u);

  for(double s: {-1, 1}) {
    double h = (C1.r + s * C2.r) / sqrt(d);
    if(eq(1-h*h, 0)) {
      ls.emplace_back(C1.p + u * C1.r, C1.p + (u+v) * C1.r);
    }else if(1-h*h>0){
      Point uu = u*h, vv = v*sqrt(1-h*h);
      ls.emplace_back(C1.p + (uu+vv) * C1.r, C2.p - (uu+vv) * C2.r * s);
      ls.emplace_back(C1.p + (uu-vv) * C1.r, C2.p - (uu-vv) * C2.r * s);
    }
  }
  return ls;
}
Line bisector(Point a, Point b){
    Point A = (a+b)*Point(0.5, 0); 
    return Line(A, A+(b-a)*Point(0, PI/2));
}

Polygon voronoi_cell(Polygon Q, Points P, int s){
    REP(i,P.size()){
        if(i!=s){
            Q = convex_cut(Q, bisector(P[s], P[i]));
        }
    }
    return Q;
}
int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(10);
  
  
  vector<double> ans(210, 10000000);
  for(int i=1; i<=199; i+=2){
    double n; n = i;
    double angle = pi/(n*2.0);
    double res1 = 0.5 / sin(angle) * 2;
    
    Polygon p;
    Point pa(res1/2, 0);
    for(int i=0; i<2*n; i++){
      p.push_back(pa);
      pa = rotate(pi/n, pa);  
    }
    for(int t = 0; t < 180; t++){
      double miy = 1000000000;
      double mxy = -1000000000;
      double mix = 1000000000;
      double mxx = -1000000000;
      for(int j=0; j<p.size(); j++){
        chmax(mxx, p[j].real());
        chmax(mxy, p[j].imag());
        chmin(mix, p[j].real());
        chmin(miy, p[j].imag());

        p[j] = rotate(pi/180,p[j]);
      }
      

      ans[i] = min(ans[i], max(mxx-mix, mxy-miy));
    }
  }
  int t; cin >> t;
  while(t--){
    int n; cin >> n;
    cout << ans[n] << endl;
  }
  return 0;
}