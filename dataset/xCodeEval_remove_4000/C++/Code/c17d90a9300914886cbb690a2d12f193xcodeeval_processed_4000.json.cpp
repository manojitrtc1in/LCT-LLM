


using namespace std;













using ld=long double;
using lli=long long;
using vi=vector<lli>;
using graph=vector<vi>;


const double PI=2*acos(0.0);

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
template <class F> istream& operator >> (istream& is, Point<F>& point) {
  return is >> point.x >> point.y; }
template <class F> ostream& operator << (ostream& os, const Point<F>& point) {
  return os << point.x << ' ' << point.y; }
template <class F> inline Point<F> makePoint(const F& x, const F& y) { return Point<F>(x, y); }
template <class F> void swap(Point<F>& lhs, Point<F>& rhs) { lhs.swap(rhs); }



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

FUNC2(operator <=, Point<F1>& lhs, Point<F2>& rhs, !(lhs > rhs))
FUNC2(operator <, Point<F1>& lhs, Point<F2>& rhs,lhs.y < rhs.y || (lhs.y == rhs.y && lhs.x < rhs.x))
FUNC2(operator >=, Point<F1>& lhs, Point<F2>& rhs, !(lhs < rhs))
FUNC2(operator >, Point<F1>& lhs, Point<F2>& rhs, rhs < lhs)


FUNC1(angle, Point<F>& point, atan2(point.y, point.x))
FUNC2(angle, Point<F1>& lhs, Point<F2>& rhs, atan2(lhs ^ rhs, lhs * rhs))
FUNC3(angle, Point<F1>& lhs, Point<F2>& rhs, Point<F3>& origin,angle(lhs - origin, rhs - origin))
FUNC3(rotate, Point<F1>& point, F2& angleSin, F3& angleCos,makePoint(angleCos * point.x - angleSin * point.y,angleSin * point.x + angleCos * point.y))
FUNC2(rotate, Point<F1>& point, F2& angle, rotate(point, sin(angle), cos(angle)))
FUNC3(rotate, Point<F1>& point, F2& angle, Point<F3>& origin,origin + rotate(point - origin, angle))
FUNC1(perp, Point<F>& point, makePoint(-point.y, point.x))

FUNC1(abs, Point<F>& point, point * point)

FUNC1(norm, Point<F>& point, sqrt(abs(point)))
FUNC2(dist, Point<F1>& lhs, Point<F2>& rhs, norm(lhs - rhs))
FUNC2(dist2, Point<F1>& lhs, Point<F2>& rhs, abs(lhs - rhs))
FUNC2(bisector, Point<F1>& lhs, Point<F2>& rhs, lhs * norm(rhs) + rhs * norm(lhs))

template <class F>bool half(Point<F> p) { assert(p.x != 0 || p.y != 0); return p.y > 0 || (p.y == 0 && p.x < 0);}
template <class F>void polarSort(vector<Point<F>> &v,Point<F> o) {sort(v.begin(), v.end(), [o](Point<F> v, Point<F> w) { return make_tuple(half(v-o), 0) <make_tuple(half(w-o), v-o^w-o);});}





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
template <class F>
inline Line<F> makeLine(lli a,lli b,lli c){if(a==0)return makeLine(Point<F>(0,-1.0*c/b),Point<F>(1,-1.0*c/b));
  else if(b==0) return makeLine(Point<F>(-1.0*c/a,0),Point<F>(-1.0*c/a,1));else return makeLine(Point<F>(0,-1.0*(c)/b),Point<F>(1,-1.0*(a+c)/b));}
template <class F>
inline Line<F> makeLine(const Point<F>& a, const Point<F>& b, bool twoPoints = true){return Line<F>(a, b, twoPoints);}
template <class F> void swap(Line<F>& lhs, Line<F>& rhs) { lhs.swap(rhs); }
template <class F1, class F2> bool onLine(const Point<F1>& point, const Line<F2>& line) {if (!line) return point == line.a;return ((point - line.a) ^ line.ab) == 0;}
template <class F1, class F2> bool onSegment(const Point<F1>& point, const Line<F2>& seg) {if (!seg) return point == seg.a;
  auto vecta = seg.a - point, vectb = seg.b() - point;return (vecta ^ vectb) == 0 && (vecta * vectb) <= 0;}
template <class F1, class F2> using distF = decltype(sqrt(F1() + F2()));
template <class F1, class F2> distF<F1, F2> distLine(const Point<F1>& point, const Line<F2>& line) {
  if (!line) return dist(point, line.a);return abs((point - line.a) ^ line.ab) / norm(line.ab);}
template <class F1, class F2> distF<F1, F2> distRay(const Point<F1>& point, const Line<F2>& ray) {
  if (((point - ray.a) * ray.ab) <= 0) return dist(point, ray.a);return distLine(point, ray);}

template <class F1, class F2> distF<F1, F2> distSegment(const Point<F1>& point, const Line<F2>& seg) {
  if (((point - seg.a) * seg.ab) <= 0) return dist(point, seg.a);if (((point - seg.b()) * seg.ab) >= 0) return dist(point, seg.b());return distLine(point, seg);}
template <class F1, class F2, class F3> void projection(const Point<F1>& point, const Line<F2>& line, Point<F3>& res) {
  res = line.a;if (line) res += line.ab * static_cast<F3>((point - line.a) * line.ab) / abs(line.ab);}
template <class F1, class F2, class F3> void closest(const Point<F1>& point, const Line<F2>& seg, Point<F3>& res) {
  if (((point - seg.a) * seg.ab) <= 0) res = seg.a;else if (((point - seg.b()) * seg.ab) >= 0) res = seg.b();else projection(point, seg, res);}

template <int TYPE> struct EndpointChecker {};
template <> struct EndpointChecker<0> {  

  template <class F> bool operator ()(const F& a, const F& b) const { return true; }};
template <> struct EndpointChecker<1> {  

  template <class F> bool operator ()(const F& a, const F& b) const { return a <= b; }};
template <> struct EndpointChecker<2> {  

  template <class F> bool operator ()(const F& a, const F& b) const { return a < b; }};
template <int LA, int LB, int RA, int RB, class F1, class F2, class F3>
bool id4(const Line<F1>& lhs, const Line<F2>& rhs, Point<F3>& res) {
  assert(lhs && rhs);
  auto s = lhs.ab ^ rhs.ab;
  if (s == 0) return false;

  auto ls = (rhs.a - lhs.a) ^ rhs.ab;
  auto rs = (rhs.a - lhs.a) ^ lhs.ab;
  if (s < 0) s = -s, ls = -ls, rs = -rs;
  bool intersect =
    EndpointChecker<LA>()(decltype(ls)(0), ls) && EndpointChecker<LB>()(ls, s) &&
    EndpointChecker<RA>()(decltype(rs)(0), rs) && EndpointChecker<RB>()(rs, s);
  if (intersect) res = lhs.a + lhs.ab * static_cast<F3>(ls) / s;
  return intersect;
}
template <class F1, class F2, class F3>
bool id7(const Line<F1>& lhs, const Line<F2>& rhs, Point<F3>& res) {
  return id4<1, 1, 1, 1>(lhs, rhs, res);}

template <class F1, class F2, class F3>
bool id18(const Line<F1>& lhs, const Line<F2>& rhs, Point<F3>& res) {
  return id4<1, 0, 1, 0>(lhs, rhs, res);}

template <class F> using Polygon = vector<Point<F>>;
inline int prev(int i, int n) { return i == 0 ? n-1 : i-1; }
inline int next(int i, int n) { return i == n-1 ? 0 : i+1; }
template <class T> inline int sgn(const T& x) { return (T(0) < x) - (x < T(0)); }

template <class F> bool orientation(const Polygon<F>& poly) {
  int n = static_cast<int>(poly.size());
  int i = static_cast<int>(min_element(begin(poly), end(poly)) - begin(poly));
  return ccw(poly[prev(i, n)], poly[next(i, n)], poly[i]) > 0;
}

template <class F>
F area(const Polygon<F>& poly) {
  int n = static_cast<int>(poly.size());
  F area = F(0);
  for (int i = 0; i < n; ++i)
    area += poly[i].x * (poly[next(i, n)].y - poly[prev(i, n)].y);
  return area;
}

template <class F>
Polygon<F> id10(Polygon<F> points) {
  sort(begin(points), end(points));
  Polygon<F> hull;
  hull.reserve(points.size() + 1);
  for (int phase = 0; phase < 2; ++phase) {
    auto start = hull.size();
    for (auto& point : points) {
      while (hull.size() >= start+2 &&
             ccw(point, hull.back(), hull[hull.size()-2]) <= 0)
        hull.pop_back();
      hull.push_back(point);
    }
    hull.pop_back();
    reverse(begin(points), end(points));
  }
  if (hull.size() == 2 && hull[0] == hull[1]) hull.pop_back();
  return hull;
}
template <class F1, class F2>
int id1(const Point<F1>& point, const Polygon<F2>& poly, int top) {
  if (point < poly[0] || point > poly[top]) return 1;
  auto orientation = ccw(point, poly[top], poly[0]);
  if (orientation == 0) {
    if (point == poly[0] || point == poly[top]) return 0;
    return top == 1 || top + 1 == poly.size() ? 0 : -1;
  } else if (orientation < 0) {
    auto itRight = lower_bound(begin(poly) + 1, begin(poly) + top, point);
    return sgn(ccw(itRight[0], point, itRight[-1]));
  } else {
    auto itLeft = upper_bound(poly.rbegin(), poly.rend() - top-1, point);
    return sgn(ccw(itLeft == poly.rbegin() ? poly[0] : itLeft[-1], point, itLeft[0]));
  }
}
template <class F1, class F2>
int id9(const Point<F1>& point, const Polygon<F2>& poly) {
  int n = static_cast<int>(poly.size()), id15 = 0;
  for (int i = 0; i < n; ++i) {
    if (point == poly[i]) return 0;
    int j = next(i, n);
    if (poly[i].y == point.y && poly[j].y == point.y) {
      if (min(poly[i].x, poly[j].x) <= point.x &&
          point.x <= max(poly[i].x, poly[j].x)) return 0;
    } else {
      bool below = poly[i].y < point.y;
      if (below != (poly[j].y < point.y)) {
        auto orientation = ccw(point, poly[j], poly[i]);
        if (orientation == 0) return 0;
        if (below == (orientation > 0)) id15 += below ? 1 : -1;
      }
    }
  }
  return id15 == 0 ? 1 : -1;
}
template <class F, class Function>
int id2(const Polygon<F>& poly, Function direction) {
  int n = static_cast<int>(poly.size()), left = 0, id16;
  auto vertexCmp = [&poly, direction](int i, int j) {
    return sgn(ccw(direction(poly[j]), poly[j] - poly[i])); };
  auto isExtreme = [n, vertexCmp](int i, int& id5) {
    return (id5 = vertexCmp(next(i, n), i)) >= 0 && vertexCmp(i, prev(i, n)) < 0; };
  for (int right = isExtreme(0, id16) ? 1 : n; left + 1 < right;) {
    int middle = (left + right) / 2, id11;
    if (isExtreme(middle, id11)) return middle;
    if (id16 != id11 ? id16 < id11
        : id16 == vertexCmp(left, middle)) right = middle;
    else left = middle, id16 = id11;
  }
  return left;
}

template <class F1, class F2>
pair<int, int> id17(const Point<F1>& point, const Polygon<F2>& poly) {
  return {
    id2(poly, [&point](const Point<F2>& q) { return q - point; }),
    id2(poly, [&point](const Point<F2>& q) { return point - q; })};
}

template <class F1, class F2, class F3>
bool id8(const Line<F1>& line, const Polygon<F2>& poly, Line<F3>& res) {
  assert(line);
  int right = id2(poly, [&line](const Point<F2>&) { return line.ab; });
  int left = id2(poly, [&line](const Point<F2>&) { return -line.ab; });
  auto vertexCmp = [&line](const Point<F2>& vertex) {
    return sgn(ccw(line.ab, vertex - line.a)); };
  int id12 = vertexCmp(poly[right]), id16 = vertexCmp(poly[left]);
  if (id12 < 0 || id16 > 0) return false;
  auto id13 = [&line, &poly, vertexCmp](int first, int last,int id14, Point<F3>& res) {
    int n = static_cast<int>(poly.size());
    while (next(first, n) != last) {
      int middle = (first + last + (first < last ? 0 : n)) / 2;
      if (middle >= n) middle -= n;
      if (vertexCmp(poly[middle]) == id14) first = middle;
      else last = middle;
    }
    id4<0, 0, 0, 0>(line, makeLine(poly[first], poly[last]), res);
  };
  id13(left, right, id16, res.a);
  id13(right, left, id12, res.ab);
  res.ab -= res.a;
  return true;
}

template <class F1, class F2, class F = distF<F1, F2>>
F id6(const Line<F1>& line, Polygon<F2>& poly) {
  assert(line);
  if (!orientation(poly)) reverse(poly.begin() + 1, poly.end());
  F tSum = F(0);
  int n = static_cast<int>(poly.size());
  auto id3 = [&line, &poly](int i) { return sgn(line.ab ^ (poly[i] - line.a)); };
  int id0 = id3(n - 1), id5 = id3(0), id19;
  for (int i = 0; i < n; ++i, id0 = id5, id5 = id19) {
    id19 = id3(next(i, n));
    if (id5 == 0) {
      if (id0 == 0) {
        if (id19 != 0 && id19 == sgn((poly[i] - poly[prev(i, n)]) * line.ab))
          tSum += id19 * static_cast<F>((poly[i] - line.a) * line.ab) / abs(line.ab);
      } else {
        if ((id19 != 0 && id19 != id0) ||
            (id19 == 0 && id0 == sgn((poly[next(i, n)] - poly[i]) * line.ab)))
          tSum -= id0 * static_cast<F>((poly[i] - line.a) * line.ab) / abs(line.ab);
      }
    } else if (id19 == -id5) {
      auto vect = poly[next(i, n)] - poly[i];
      tSum += id19 * static_cast<F>((poly[i] - line.a) ^ vect) / (line.ab ^ vect);
    }
  }
  return tSum * norm(line.ab);
}

signed main(){
	boost;
	int n,m;
	cin>>n>>m;
	Polygon<ld> mypol(n);
	fr(i,n){cin>>mypol[i];}
	fr(i,m){
		Point<ld> p1,p2;cin>>p1>>p2;
		Line<ld> curline(p2,p1);
		cout<<fixed<<setprecision(20)<<id6<ld,ld,ld>(curline,mypol)<<endl;
	}
}	