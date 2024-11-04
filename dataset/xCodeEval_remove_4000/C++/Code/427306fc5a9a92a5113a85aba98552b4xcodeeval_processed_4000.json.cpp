
using namespace std;
typedef long long ll;
typedef long long ll1;
const ll MAX=1e6+5;
ll MOD=1e9+7;
ll MOD1=1e9+7;


















using namespace __gnu_pbds;


ll add(ll a,ll b){if((ll1)a+b>=MOD)return (ll1)a+b-MOD;return a+b;}
ll mul(ll a,ll b){return ((ll1)a*b)%MOD;}
ll sub(ll a,ll b){if(a>=b)return a-b;return a-b+MOD;}
ll add1(ll a,ll b){return ((ll1)a+b)%MOD1;}
ll mul1(ll a,ll b){return ((ll1)a*b)%MOD1;}


template <class F>
struct Point {
  F x, y;
  Point() : x(0), y(0) {}
  Point(const F& x, const F& y) : x(x), y(y) {}
 
  void swap(Point& other) { using std::swap; swap(x, other.x); swap(y, other.y); }
  template <class F1> explicit operator Point<F1> () const {
    return Point<F1>(static_cast<F1>(x), static_cast<F1>(y)); }
  template <class F1> Point& operator = (const Point<F1>& other) {
    x = other.x; y = other.y; return *this; }
  template <class F1> Point& operator += (const Point<F1>& other) {
    x += other.x; y += other.y; return *this; }
  template <class F1> Point& operator -= (const Point<F1>& other) {
    x -= other.x; y -= other.y; return *this; }
  template <class F1> Point& operator *= (const F1& factor) {
    x *= factor; y *= factor; return *this; }
  template <class F1> Point& operator /= (const F1& factor) {
    x /= factor; y /= factor; return *this; }
};
 
template <class F> int read(Point<F>& point) { return read(point.x, point.y) / 2; }
template <class F> int write(const Point<F>& point) { return write(point.x, point.y); }
 
template <class F> istream& operator >> (istream& is, Point<F>& point) {
  return is >> point.x >> point.y; }
template <class F> ostream& operator << (ostream& os, const Point<F>& point) {
  return os << point.x << ' ' << point.y; }
 
template <class F> inline Point<F> makePoint(const F& x, const F& y) { return Point<F>(x, y); }
template <class F> void swap(Point<F>& lhs, Point<F>& rhs) { lhs.swap(rhs); }
 

template <class F> inline auto name(const arg) -> decltype(expr) { return expr; }

template <class F1, class F2> \
inline auto name(const arg1, const arg2) -> decltype(expr) { return expr; }

template <class F1, class F2, class F3> \
inline auto name(const arg1, const arg2, const arg3) -> decltype(expr) { return expr; }
 
FUNC1(operator -, Point<F>& point, makePoint(-point.x, -point.y))
FUNC2(operator +, Point<F1>& lhs, Point<F2>& rhs, makePoint(lhs.x + rhs.x, lhs.y + rhs.y))
FUNC2(operator -, Point<F1>& lhs, Point<F2>& rhs, makePoint(lhs.x - rhs.x, lhs.y - rhs.y))
FUNC2(operator *, F1& factor, Point<F2>& rhs, makePoint(factor * rhs.x, factor * rhs.y))
FUNC2(operator *, Point<F1>& lhs, F2& factor, makePoint(lhs.x * factor, lhs.y * factor))
FUNC2(operator /, Point<F1>& lhs, F2& factor, makePoint(lhs.x / factor, lhs.y / factor))
 
FUNC2(operator *, Point<F1>& lhs, Point<F2>& rhs, lhs.x * rhs.x + lhs.y * rhs.y)
FUNC2(operator ^, Point<F1>& lhs, Point<F2>& rhs, lhs.x * rhs.y - lhs.y * rhs.x)
 


FUNC2(ccw, Point<F1>& lhs, Point<F2>& rhs, rhs ^ lhs)
FUNC3(ccw, Point<F1>& lhs, Point<F2>& rhs, Point<F3>& origin, ccw(lhs - origin, rhs - origin))
 
FUNC2(operator ==, Point<F1>& lhs, Point<F2>& rhs, lhs.x == rhs.x && lhs.y == rhs.y)
FUNC2(operator !=, Point<F1>& lhs, Point<F2>& rhs, !(lhs == rhs))
 
FUNC2(operator <, Point<F1>& lhs, Point<F2>& rhs,
    lhs.y < rhs.y || (lhs.y == rhs.y && lhs.x < rhs.x))
FUNC2(operator >, Point<F1>& lhs, Point<F2>& rhs, rhs < lhs)
FUNC2(operator <=, Point<F1>& lhs, Point<F2>& rhs, !(lhs > rhs))
FUNC2(operator >=, Point<F1>& lhs, Point<F2>& rhs, !(lhs < rhs))
 


FUNC1(angle, Point<F>& point, atan2(point.y, point.x))
FUNC2(angle, Point<F1>& lhs, Point<F2>& rhs, atan2(lhs ^ rhs, lhs * rhs))
FUNC3(angle, Point<F1>& lhs, Point<F2>& rhs, Point<F3>& origin,
      angle(lhs - origin, rhs - origin))
FUNC3(rotate, Point<F1>& point, F2& angleSin, F3& angleCos,
      makePoint(angleCos * point.x - angleSin * point.y,
                angleSin * point.x + angleCos * point.y))
FUNC2(rotate, Point<F1>& point, F2& angle, rotate(point, sin(angle), cos(angle)))
FUNC3(rotate, Point<F1>& point, F2& angle, Point<F3>& origin,
      origin + rotate(point - origin, angle))
FUNC1(perp, Point<F>& point, makePoint(-point.y, point.x))
 


FUNC1(abs, Point<F>& point, point * point)
FUNC1(norm, Point<F>& point, sqrt(abs(point)))
FUNC2(dist, Point<F1>& lhs, Point<F2>& rhs, norm(lhs - rhs))
FUNC2(dist2, Point<F1>& lhs, Point<F2>& rhs, abs(lhs - rhs))
FUNC2(bisector, Point<F1>& lhs, Point<F2>& rhs, lhs * norm(rhs) + rhs * norm(lhs))
 



template <class F>
struct Line {
  Point<F> a, ab;
  Line() : a(), ab() {}
  Line(const Point<F>& a, const Point<F>& b, bool twoPoints = true)
    : a(a), ab(twoPoints ? b - a : b) {}
  Line(const F& xa, const F& ya, const F& xb, const F& yb)
    : a(xa, ya), ab(xb - xa, yb - ya) {}
 
  void swap(Line& other) { using std::swap; swap(a, other.a); swap(ab, other.ab); }
  template <class F1> explicit operator Line<F1> () const {
    return Line<F1>(Point<F1>(a), Point<F1>(ab), false); }
  template <class F1> Line& operator = (const Line<F1>& other) {
    a = other.a; ab = other.ab; return *this; }
 
  Point<F> b() const { return a + ab; }
  operator bool () const { return ab != Point<F>(); }
};
 
template <class F> int read(Line<F>& line) {
  int res = read(line.a, line.ab) / 2;
  return line.ab -= line.a, res;
}
 
template <class F>
inline Line<F> makeLine(const Point<F>& a, const Point<F>& b, bool twoPoints = true) {
  return Line<F>(a, b, twoPoints);
}
 
template <class F> void swap(Line<F>& lhs, Line<F>& rhs) { lhs.swap(rhs); }
template <class F1, class F2>
bool onLine(const Point<F1>& point, const Line<F2>& line) {
  if (!line) return point == line.a;
  return ((point - line.a) ^ line.ab) == 0;
}
template <class F1, class F2>
bool onSegment(const Point<F1>& point, const Line<F2>& seg) {
  if (!seg) return point == seg.a;
  auto vecta = seg.a - point, vectb = seg.b() - point;
  return (vecta ^ vectb) == 0 && (vecta * vectb) <= 0;
}
template <class F1, class F2> using distF = decltype(sqrt(F1() + F2()));
 
template <class F1, class F2>
distF<F1, F2> distLine(const Point<F1>& point, const Line<F2>& line) {
  if (!line) return dist(point, line.a);
  return abs((point - line.a) ^ line.ab) / norm(line.ab);
}
template <class F1, class F2>
distF<F1, F2> distSegment(const Point<F1>& point, const Line<F2>& seg) {
  if (((point - seg.a) * seg.ab) <= 0) return dist(point, seg.a);
  if (((point - seg.b()) * seg.ab) >= 0) return dist(point, seg.b());
  return distLine(point, seg);
}
template <class F1, class F2, class F3>
void projection(const Point<F1>& point, const Line<F2>& line, Point<F3>& res) {
  res = line.a;
  if (line) res += line.ab * static_cast<F3>((point - line.a) * line.ab) / abs(line.ab);
}
 
template <class F1, class F2, class F3>
void reflection(const Point<F1>& point, const Line<F2>& line, Point<F3>& res) {
  projection(point, line, res);
  res = 2 * res - point;
}
template <class F1, class F2, class F3>
void closest(const Point<F1>& point, const Line<F2>& seg, Point<F3>& res) {
  if (((point - seg.a) * seg.ab) <= 0) res = seg.a;
  else if (((point - seg.b()) * seg.ab) >= 0) res = seg.b();
  else projection(point, seg, res);
}
template <int TYPE> struct EndpointChecker {};
template <> struct EndpointChecker<0> {  

  template <class F> bool operator ()(const F& a, const F& b) const { return true; }};
template <> struct EndpointChecker<1> {  

  template <class F> bool operator ()(const F& a, const F& b) const { return a <= b; }};
template <> struct EndpointChecker<2> {  

  template <class F> bool operator ()(const F& a, const F& b) const { return a < b; }};
 
template <int LA, int LB, int RA, int RB, class F1, class F2, class F3>
bool id0(const Line<F1>& lhs, const Line<F2>& rhs, Point<F3>& res,double &i,double &j) {
  assert(lhs && rhs);
  auto s = lhs.ab ^ rhs.ab;
  if (s == 0) return false;
  auto ls = (rhs.a - lhs.a) ^ rhs.ab;
  auto rs = (rhs.a - lhs.a) ^ lhs.ab;
  if (s < 0) s = -s, ls = -ls, rs = -rs;
  bool intersect =
    EndpointChecker<LA>()(decltype(ls)(0), ls) && EndpointChecker<LB>()(ls, s) &&
    EndpointChecker<RA>()(decltype(rs)(0), rs) && EndpointChecker<RB>()(rs, s);
  i=(double)ls/s;
  j=(double)rs/s;
  if (intersect) res = lhs.a + lhs.ab * static_cast<F3>(ls) / s;
  return intersect;
}
template <class F>
struct AngleCompare {
  const Point<F> origin;
  const bool zero;
 
  AngleCompare(const Point<F>& origin = Point<F>())
    : origin(origin), zero(origin == Point<F>()) {}
 
  template <class F1, class F2>
  bool operator () (const Point<F1>& lhs, const Point<F2>& rhs) const {
    return zero ? ccw(lhs, rhs) < 0 : ccw(lhs, rhs, origin) < 0;
  }
};
 
template <class Iterator, class F>
void id1(Iterator first, Iterator last, const Point<F>& origin) {
  first = partition(first, last, [&origin](const decltype(*first)& point) {
    return point == origin; });
  auto pivot = partition(first, last, [&origin](const decltype(*first)& point) {
    return point > origin; });
  AngleCompare<F> acmp(origin);
  sort(first, pivot, acmp);
  sort(pivot, last, acmp);
}
ll u,v;
bool touched(double t,ll x,ll y)
{
  if((x-t*v)*u>y*v || abs((x-t*v)*u-y*v)<=1e-10)return 0;
  return 1;
}
Point<ll>arr[MAX];
int main()
{
    boost;
    cout<<fixed<<setprecision(12);
    
      freopen("input.txt","r",stdin);
      freopen("output01.txt","w",stdout);
    
    ll n,w;
    cin>>n>>w>>v>>u;
    Point<ll>lm,rm,um,bm;
    vector<Point<ll>>tl,tr,br,bl;
    for(int i=0;i<n;i++){
      cin>>arr[i];
      if(!i){
        lm=arr[i],rm=arr[i],um=arr[i],bm=arr[i];
        continue;
      }
      if(arr[i].x<lm.x || (arr[i].x==lm.x && arr[i].y<lm.y))lm=arr[i];
      if(arr[i].y<bm.y || (arr[i].y==bm.y && arr[i].x<bm.x))bm=arr[i];
      if(arr[i].y>um.y || (arr[i].y==um.y && arr[i].x<um.x))um=arr[i];
      if(arr[i].x>rm.x || (arr[i].x==lm.x && arr[i].y<rm.y))rm=arr[i];
    }
    

    reverse(arr,arr+n);
    int i;
    for(i=0;i<n;i++){
      if(arr[i]==lm)break;
    }
    while(arr[i%n]!=um){
      tl.pb(arr[(i)%n]);
      i++;
    }
    tl.pb(arr[i%n]);
    while(arr[i%n]!=rm){
      tr.pb(arr[i%n]);
      i++;
    }
    tr.pb(arr[i%n]);
    while(arr[i%n]!=bm){
      br.pb(arr[i%n]);
      i++;
    }
    br.pb(arr[i%n]);
    while(arr[i%n]!=lm){
      bl.pb(arr[i%n]);
      i++;
    }
    bl.pb(arr[i%n]);
    reverse(br.begin(),br.end());
    

    

    double t=0;
    bool flg=0;
    if(touched(t,tl[0].x,tl[0].y))flg=1;
    if(!flg)t+=(double)tl[0].y/u;
    

    for(int i=1;i<tl.size();i++){
      if(touched(t,tl[i].x,tl[i].y-tl[i-1].y))flg=1;
      if(!flg)t+=(double)(tl[i].y-tl[i-1].y)/u;
    }
    t=0;
   

    if(!flg)cout<<(double)w/u;
    else{
      t=max((double)br[0].y/u,(double)br[0].x/v);
      

      for(int i=1;i<br.size();i++){
        t+=max((br[i].x-v*t)/v,(double)(br[i].y-br[i-1].y)/u);
      }
      t+=(double)(w-br.back().y)/u;
       cout<<t;
    }
}