










namespace lib {
  using namespace std;

  template<typename T>
  struct Epsilon {
    T eps;
    Epsilon(T eps) : eps(eps) {}

    template<typename G,
             typename enable_if<!is_integral<G>::value>::type* = nullptr>
    int operator()(G a, G b = 0) const {
      return a + eps < b ? -1 : (b + eps < a ? 1 : 0);
    }

    template<typename G,
             typename enable_if<is_integral<G>::value>::type* = nullptr>
   int operator()(G a, G b = 0) const {
     return a < b ? -1 : (a > b ? 1 : 0);
   }
  };
}




  lib::Epsilon<T>* lib::geo::GeometryEpsilon<T>::eps \
    = new lib::Epsilon<T>((x));




namespace lib {
  using namespace std;
namespace geo {
  template<typename T>
  struct GeometryEpsilon {
    static Epsilon<T>* eps;
    template<typename G>
    int operator()(G a, G b = 0) const {
      return (*eps)(a, b);
    }
  };

  GEOMETRY_EPSILON(int, 0);
  GEOMETRY_EPSILON(long long, 0);
}  

}  







namespace lib {
  using namespace std;
namespace geo {
namespace trig {
  double cos(double x) { return cos(x); }
  double sin(double x) { return sin(x); }
}  

}  

}  




namespace lib {
  using namespace std;
namespace geo {
namespace plane {
  namespace {
    template<typename T>
    bool scalar_between(T a, T o, T b) {
      if(a > b)
        swap(a, b);
      return GEOMETRY_COMPARE(T, a, o) <= 0
        && GEOMETRY_COMPARE(T, o, b) <= 0;
    }
    
    template<typename T>
    bool id3(T a, T o, T b) {
      if(a > b) 
        swap(a, b);
      int x = GEOMETRY_COMPARE(T, a, o);
      int y = GEOMETRY_COMPARE(T, o, b);
      return x <= 0 && y <= 0 && (x < 0 || y < 0);
    }
  }

  template<typename T, typename Large = T>
  struct Point {
    T x, y;
    Point() : x(0), y(0) {}
    Point(T x, T y) : x(x), y(y) {}
    template<typename G, typename H>
    explicit operator Point<G, H>() const {
      return Point<G, H>((G)x, (G)y);
    }
    Point& operator+=(const Point& rhs) {
      x += rhs.x, y += rhs.y;
      return *this;
    }
    Point& operator-=(const Point& rhs) {
      x -= rhs.x, y -= rhs.y;
      return *this;
    }
    Point& operator*=(T k) {
      x *= k, y *= k;
      return *this;
    }
    Point& operator/=(T k) {
      x /= k, y /= k;
      return *this;
    }
    Point operator+(const Point& rhs) const {
      Point res = *this;
      return res += rhs;
    }
    Point operator-(const Point& rhs) const {
      Point res = *this;
      return res -= rhs;
    }
    Point operator*(T k) const {
      Point res = *this;
      return res *= k;
    }
    Point operator/(T k) const {
      Point res = *this;
      return res /= k;
    }
    inline friend Point convolve(const Point& a, const Point& b) {
      return Point(a.x * b.x - a.y * b.y, a.x * b.y + b.x * a.y);
    }
    inline friend Large cross(const Point& a, const Point& b) {
      return (Large)a.x*b.y - (Large)a.y*b.x;
    }
    inline friend Large dot(const Point& a, const Point& b) {
      return (Large)a.x*b.x + (Large)a.y*b.y;
    }
    friend int ccw(const Point& a, const Point& b, const Point& c) {
      return GEOMETRY_COMPARE0(Large, cross(b-a,c-a));
    }
    friend Large norm(const Point& a) {
      return sqrtl(dot(a, a));
    }
    friend Large norm_sq(const Point& a) {
      return dot(a, a);
    }
    bool is_null() const {
      return GEOMETRY_COMPARE0(Large, norm_sq(*this)) == 0;
    }
    bool is_versor() const {
      return GEOMETRY_COMPARE(Large, norm_sq(*this), (Large)1) == 0;
    }
    static Point polar(Large d, Large theta) {
      return Point(trig::cos(theta) * d, trig::sin(theta) * d);
    }
    friend Point rotate(const Point& a, Large theta) {
      return convolve(a, polar((Large)1, theta));
    }
    friend Point ortho(const Point& a) {
      return Point(-a.y, a.x);
    }
    inline friend Point normalized(const Point& a, Large k) {
      return a.is_null() ? Point() : a / norm(a) * k; 
    }
    inline friend Point versor(const Point& a) {
      return normalized(a, (Large)1);
    }
    friend bool collinear(const Point& a, const Point& b) {
      return GEOMETRY_COMPARE0(Large, cross(a, b)) == 0;
    }
    friend bool collinear(const Point& a, const Point& b, const Point& c) {
      return collinear(b - a, c - a);
    } 
    friend Point project(const Point& a, const Point& v) {
      return dot(a, v) * v / norm_sq(v);
    }
    template<typename G = T,
             typename enable_if<!is_integral<G>::value>::type* = nullptr>
    friend Point reflect(const Point& a, const Point& v) {
      Point n = versor(v);
      return a - n * 2 * dot(n, v);
    }
    friend bool between(const Point& a, const Point& b, const Point& c) {
      return collinear(a, b, c) && GEOMETRY_COMPARE0(Large, dot(a - b, c - b)) <= 0; 
    }
    friend bool id1(const Point& a, const Point& b, const Point& c) {
      return collinear(a, b, c) && GEOMETRY_COMPARE0(Large, dot(a - b, c - b)) < 0; 
    }
    friend bool id2(const Point a, const Point& o, const Point& b) {
      return scalar_between(a.x, o.x, b.x) && scalar_between(a.y, o.y, b.y);
    }
    friend bool id0(const Point& a, const Point& o, const Point& b) {
      return scalar_between(a.x, o.x, b.x) && scalar_between(a.y, o.y, b.y);
    }
    friend Large dist(const Point& a, const Point& b) {
      return norm(a - b);
    }
    friend bool operator==(const Point& a, const Point& b) {
      return GEOMETRY_COMPARE(T, a.x, b.x) == 0
        && GEOMETRY_COMPARE(T, a.y, b.y) == 0;
    }
    friend bool operator!=(const Point& a, const Point& b) {
      return !(a == b);
    }
    friend bool operator<(const Point& a, const Point& b) {
      return tie(a.x, a.y) < tie(b.x, b.y);
    }
  };

  template<typename T, typename Large = T>
  struct Rectangle {
    typedef Point<T, Large> point;

    T minx, miny, maxx, maxy;
    Rectangle() {
      minx = miny = numeric_limits<T>::max();
      maxx = maxy = numeric_limits<T>::min();
    }

    Rectangle(const initializer_list<point>& points) : Rectangle() {
      for(const auto& p : points) {
        minx = min(minx, p.x);
        maxx = max(maxx, p.x);
        miny = min(miny, p.y);
        maxy = max(maxy, p.y);
      }
    }

    bool contains(const point& p) const {
      return GEOMETRY_COMPARE(T, minx, p.x) <= 0
          && GEOMETRY_COMPARE(T, p.x, maxx) <= 0
          && GEOMETRY_COMPARE(T, miny, p.y) <= 0
          && GEOMETRY_COMPARE(T, p.y, maxy) <= 0;
    }
  };

  template<typename T, typename Large = T>
  struct Line {
    typedef Point<T, Large> point;
    typedef Line<T, Large> line;
    point a, b;
    Line(point a, point b) : a(a), b(b) {}
    template<typename G, typename H>
    explicit operator Line<G, H>() const {
      return Line<G, H>(Point<G, H>(a), Point<G, H>(b));
    }
    friend point project(const point& p, const line& v) {
      return project(p, v.b - v.a) + v.a;
    }
    friend bool collinear(const line& u, const line& v) {
      return collinear(u.a, u.b, v.a) && collinear(u.a, u.b, v.b);
    }
    friend bool parallel(const line& u, const line& v) {
      return collinear(u.b - u.a, v.b - v.a);
    }
    friend pair<point, bool> intersect(const line& l1, const line& l2) {
      Large c1 = cross(l2.a - l1.a, l1.b - l1.a);
      Large c2 = cross(l2.b - l1.a, l1.b - l1.a);
      if(GEOMETRY_COMPARE0(Large, c1 - c2) == 0)
        return {{}, false};
      return {(l2.b * c1 - l2.a * c2) / (c1 - c2), true};
    }
  };

  template<typename T, typename Large = T>
  struct Ray : Line<T, Large> {
    typedef Point<T, Large> point;
    typedef Line<T, Large> line;
    typedef Ray<T, Large> ray;
    using line::a;
    using line::b;

    Ray(point a, point direction) : line(a, a + direction) {}

    static ray from_points(point a, point b) { return ray(a, b - a); }
    point direction() const { return b - a; }
    point direction_versor() const { return versor(direction()); }

    line as_line() const { return line(a, b); }
    explicit operator line() const { return as_line(); }

    template<typename G, typename H>
    explicit operator Ray<G, H>() const {
      return Ray<G, H>(Point<G, H>(a), Point<G, H>(b));
    }

    bool contains(const point& p) const {
      return collinear(a, b, p) &&
        GEOMETRY_COMPARE0(Large, dot(p - a, b - a)) >= 0;
    }

    bool strictly_contains(const point& p) const {
      return collinear(a, b, p) &&
        GEOMETRY_COMPARE0(Large, dot(p - a, b - a)) > 0;
    }

    bool collinear_contains(const point& p) const {
      point dir = direction();
      int dx = GEOMETRY_COMPARE0(T, dir.x);
      if(dx == 0)
        return GEOMETRY_COMPARE0(T, dir.y) * GEOMETRY_COMPARE0(T, p.y - a.y) >= 0;
      else
        return dx * GEOMETRY_COMPARE0(T, p.x - a.x) >= 0;
    }

    bool collinear_strictly_contains(const point& p) const {
      point dir = direction();
      int dx = GEOMETRY_COMPARE0(T, dir.x);
      if(dx == 0)
        return GEOMETRY_COMPARE0(T, dir.y) * GEOMETRY_COMPARE0(T, p.y - a.y) > 0;
      else
        return dx * GEOMETRY_COMPARE0(T, p.x - a.x) > 0;
    }

    friend pair<point, bool> intersect(const ray& a, const ray& b) {
      auto p = intersect(a.as_line(), b.as_line());
      if(!p.second)
        return {{}, false};
      if(!a.collinear_contains(p.first) || !b.collinear_contains(p.first))
        return {{}, false};
      return p;
    }
  };

  template<typename T, typename Large = T>
  struct Segment : Line<T, Large> {
    typedef Point<T, Large> point;
    typedef Line<T, Large> line;
    typedef Segment<T, Large> segment;
    typedef Ray<T, Large> ray;
    using line::a;
    using line::b;

    Segment(point a, point b) : Line<T, Large>(a, b) {}
    line as_line() const { return line(a, b); }
    explicit operator line() const { return as_line(); }

    template<typename G, typename H>
    explicit operator Segment<G, H>() const {
      return Segment<G, H>(Point<G, H>(a), Point<G, H>(b));
    }

    bool contains(const point& p) const {
      return between(a, p, b);
    }

    bool strictly_contains(const point& p) const {
      return id1(a, p, b);
    }

    bool collinear_contains(const point& p) const {
      return id2(a, p, b);
    }

    bool collinear_strictly_contains(const point& p) const {
      return id0(a, p, b);
    }

    friend pair<point, bool> intersect(const segment& s, const line& l) {
      auto p = intersect(s.as_line(), l);
      if(!p.second)
        return {{}, false};
      if(!s.collinear_contains(p.first))
        return {{}, false};
      return p;
    }

    friend pair<point, bool> intersect(const segment& s, const ray& r) {
      auto p = intersect(s.as_line(), r.as_line());
      if(!p.second)
        return {{}, false};
      if(!s.collinear_contains(p.first) || !r.collinear_contains(p.first))
        return {{}, false};
      return p;
    }

    friend pair<point, bool> intersect(const segment& s1, const segment& s2) {
      auto p = intersect(s1, s2.as_line());
      if(!p.second)
        return {{}, false};
      if(!s2.collinear_contains(p.first))
        return {{}, false};
      return p;
    }
  };
}  


  template<typename T, typename Large = T>
  struct CartesianPlane {
    typedef plane::Point<T, Large> point;
    typedef plane::Line<T, Large> line;
    typedef plane::Rectangle<T, Large> rectangle;
    typedef plane::Segment<T, Large> segment;
    typedef plane::Ray<T, Large> ray;
  };

}  

}  




using namespace std;










int gcd(int a, int b) { return b == 0 ? a : gcd(b, a%b); }
int power(int x, int p, int MOD) {
    if(p == 0) return 1%MOD;
    if(p == 1) return x%MOD;
    int res = power(x, p/2, MOD);
    res = (long long)res*res%MOD;
    if(p&1) res = (long long)res*x%MOD;
    return res;
}

typedef pair<int, int> ii;
typedef long double LD;
typedef vector<int> vi;

const LD EPS = 1e-9;
GEOMETRY_EPSILON(LD, EPS);

using namespace lib::geo;
using IG = lib::geo::CartesianPlane<int>;
using FG = lib::geo::CartesianPlane<LD>;
using Point = IG::point;

int go(int dx, int dy) {
  return gcd(abs(dx), abs(dy)) + 1;
}

int safe_round(double x) {
  if(x < 0) return x - 0.5;
  return x + 0.5;
}

struct Segment {
  Point a, b;
  int idx;

  bool contains(const Point& p) const {
    return cross(b - a, p - a) == 0
      && dot(p - a, p - b) <= 0;
  }

  int count() const {
    return go(a.x - b.x, a.y - b.y);
  }

  Point integer_intersection(const Segment& rhs, bool& exists) const {
    auto pz = intersect((FG::segment)IG::segment(a, b), (FG::segment)IG::segment(rhs.a, rhs.b));
    if(!pz.second) {
      exists = false;
      return Point();
    }
    Point q = {safe_round(pz.ff.x), safe_round(pz.ff.y)};
    for(int i = -1; i <= 1; i++) {
      for(int j = -1; j <= 1; j++) {
        Point w = {q.x + i, q.y + j};
        if(contains(w) && rhs.contains(w)) {
          exists = true;
          return w;
        }
      }
    }

    exists = false;
    return Point();
  }
};

int32_t main(){
  iopt;
  int n;
  cin >> n;

  vector<Segment> s(n);

  int ans = 0;
  for(int i = 0; i < n; i++) {
    cin >> s[i].a.x >> s[i].a.y >> s[i].b.x >> s[i].b.y;
    ans += s[i].count();
    s[i].idx = i;
  }

  set<pair<Point, int>> st;
  map<Point, int> h;
  for(int i = 0; i < n; i++) {
    for(int j = i+1; j < n; j++) {
      bool ok;
      Point q = s[i].integer_intersection(s[j], ok);
      if(ok) {
        pair<Point, int> p1 = {q, i};
        if(st.insert(p1).second)
          h[q]++;
        pair<Point, int> p2 = {q, j};
        if(st.insert(p2).second)
          h[q]++;
      }
    }
  }

  for(auto p : h) ans -= p.second - 1;

  cout << ans << endl;
}
