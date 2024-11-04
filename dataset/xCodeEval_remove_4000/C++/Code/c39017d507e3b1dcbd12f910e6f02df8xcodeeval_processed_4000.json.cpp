
using namespace std;
typedef long long ll;
typedef long long ll1;
typedef long double ld;
const ld pi=atan((ld)1)*4;
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
FUNC1(norm, Point<F>& point, sqrtl(abs(point)))
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
bool id1(const Line<F1>& lhs, const Line<F2>& rhs, Point<F3>& res,double &i,double &j) {
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
void id3(Iterator first, Iterator last, const Point<F>& origin) {
  first = partition(first, last, [&origin](const decltype(*first)& point) {
    return point == origin; });
  auto pivot = partition(first, last, [&origin](const decltype(*first)& point) {
    return point > origin; });
  AngleCompare<F> acmp(origin);
  sort(first, pivot, acmp);
  sort(pivot, last, acmp);
}
template<class F>
int id2(F a){if(sizeof(a)==4)return 32-__builtin_clz(a);return 64-__builtin_clzll(a);}


Point<ll> arr[MAX];
bool comp(Point<ll>a ,Point<ll>b)
{
  return (a.x==b.x)?a.y<b.y:a.x<b.x;
}
bool comp1(Point<ll> a,Point<ll> b)
{
    return (a.y==b.y)?a.x<b.x:a.y>b.y;
}
short sgnx[MAX],sgny[MAX];




pair<Point<ll>,Point<ll>> closest_distance(ll l,ll r)
{
    if(r-l<=3){
      debug2(l,r);
      ll d=2e18;
      pair<Point<ll>,Point<ll>>p;
      for(int i=l;i<=r;i++)
        for(int j=i+1;j<=r;j++)
          if(dist2(arr[i],arr[j])<d){
            d=dist2(arr[i],arr[j]);
            p={arr[i],arr[j]};
          }
      debug2(p.fi,p.se);
      return p;
    }
    debug2(l,r);
    ll mid=(l+r)>>1;
    vector<Point<ll>>v1,v2;
    pair<Point<ll>,Point<ll>>p,p1;
    auto u=closest_distance(l,mid);
    auto v=closest_distance(mid+1,r);
    ll d;
    if(dist2(u.fi,u.se)<dist2(v.fi,v.se)){
      p=u;
      d=dist2(u.fi,u.se);
    }
    else {
      p=v;
      d=dist2(v.fi,v.se);
    }
    for(int i=l;i<=mid;i++)if(((arr[i].x-arr[mid].x)*(arr[i].x-arr[mid].x))<=d)v1.pb(arr[i]);
    for(int i=mid+1;i<=r;i++)if(((arr[i].x-arr[mid].x)*(arr[i].x-arr[mid].x))<=d)v2.pb(arr[i]);
    sort(v1.begin(),v1.end(),comp1);
    sort(v2.begin(),v2.end(),comp1);
    ll lcurr=0,rcurr=0;
    ll d1=2e18;
    for(int i=0;i<v1.size();i++){
       

        while(rcurr<v2.size() && ((v1[i].y-v2[rcurr].y)*(v1[i].y-v2[rcurr].y)<d || v1[i].y<=v2[rcurr].y))rcurr++;
        while(lcurr<v2.size() && (v2[lcurr].y-v1[i].y)*(v2[lcurr].y-v1[i].y)>d && v2[lcurr].y>=v1[i].y)lcurr++;
        for(int j=lcurr;j<rcurr;j++){
           

            if(d1>dist2(v2[j],v1[i])){
              p1={v2[j],v1[i]};
              d1=dist2(v2[j],v1[i]);
            }
        }
    }
    if(d1==2e18)return p;
    if(dist2(p.fi,p.se)<dist2(p1.fi,p1.se))return p;
    return p1;
}
map<Point<ll>,ll>mp;
void id0(int a)
{
  if(sgnx[a]==1 && sgny[a]==1)cout<<1;
  if(sgnx[a]==-1 && sgny[a]==1)cout<<2;
  if(sgnx[a]==1 && sgny[a]==-1)cout<<3;
  if(sgnx[a]==-1 && sgny[a]==-1)cout<<4;
}
void id4(int b)
{
  if(sgnx[b]==1 && sgny[b]==1)cout<<4;
  if(sgnx[b]==-1 && sgny[b]==1)cout<<3;
  if(sgnx[b]==1 && sgny[b]==-1)cout<<2;
  if(sgnx[b]==-1 && sgny[b]==-1)cout<<1;
}
int main()
{
    boost;
    cout<<fixed<<setprecision(12);
    
      freopen("input.txt","r",stdin);
      freopen("output.txt","w",stdout);
    
    ll n;
    cin>>n;
    ll a,b;
    pair<Point<ll>,Point<ll>>p;
    bool flg=0;
    for(int i=0;i<n;i++){
      cin>>arr[i];
      if(arr[i].x<0)sgnx[i]=-1;
      else sgnx[i]=1;
      if(arr[i].y<0)sgny[i]=-1;
      else sgny[i]=1;
      arr[i].x=abs(arr[i].x);
      arr[i].y=abs(arr[i].y);
      if(mp.count(arr[i])){
        flg=1;
        a=i,b=mp[arr[i]];
        break;
      }
      mp[arr[i]]=i;
    }
    sort(arr,arr+n,comp);
    if(!flg){p=closest_distance(0,n-1);
      a=mp[p.fi],b=mp[p.se];
    }
    debug2(a,b);
    cout<<a+1<<' ';
    id0(a);
    cout<<' ';
    cout<<b+1<<' ';
    id4(b);


}