#include<iostream>
#include<cstdio>
#include<fstream>
#include<queue>
#include<cmath>
#include<algorithm>
#include<assert.h>

using namespace std;

const long double eps = 1e-9, pi = acos(-1);
const int OO = (1 << 30);

template <class F>
struct Point {
    F x, y;
    Point() : x(0), y(0) {}
    Point(const F& x, const F& y) : x(x), y(y) {}

    void swap(Point& other) {using std::swap; swap(x, other.x); swap(y, other.y); }
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
template <class F> int sgn(F val) { return (F(0) < val) - (val < F(0)); }

#define FUNC1(name, arg, expr) \
template <class F> inline auto name(const arg) -> decltype(expr) { return expr; }
#define FUNC2(name, arg1, arg2, expr) \
template <class F1, class F2> \
inline auto name(const arg1, const arg2) -> decltype(expr) { return expr; }
#define FUNC3(name, arg1, arg2, arg3, expr) \
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

template <class F1, class F2, class F3>
distF<F1, F2> distSegment(const Point<F1>& point, const Line<F2>& seg, Point<F3>& pos) {
    if (((point - seg.a) * seg.ab) <= 0){pos = seg.a; return dist(point, seg.a);}
    if (((point - seg.b()) * seg.ab) >= 0){pos = seg.b(); return dist(point, seg.b());}
    projection(point, seg, pos);
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
bool intersectLines(const Line<F1>& lhs, const Line<F2>& rhs, Point<F3>& res) {
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

template <class F1, class F2>
bool intersect(Line<F1>& seg1, Line<F2>& seg2){
    int c1, c2, c3, c4;
    c1 = ccw(seg2.a, seg1.b(), seg1.a);
    c2 = ccw(seg2.b(), seg1.b(), seg1.a);
    c3 =  ccw(seg1.a, seg2.b(), seg2.a);
    c4 = ccw(seg1.b(), seg2.b(), seg2.a);
    if(c1 != c2 && c3 != c4) return true;
    if(c1 == 0 && onSegment(seg2.a, seg1)) return true;
    else if(c2 == 0 && onSegment(seg2.b(), seg1)) return true;
    else if(c3 == 0 && onSegment(seg1.a, seg2)) return true;
    else if(c4 == 0 && onSegment(seg1.b(), seg2)) return true;
    return false;
}

template <class F1, class F2, class F3>
bool intersectClosedSegments(const Line<F1>& lhs, const Line<F2>& rhs, Point<F3>& res) {
    return intersectLines<1, 1, 1, 1>(lhs, rhs, res);
}

template <class F1, class F2, class F3>
bool intersectSegments(const Line<F1>& lhs, const Line<F2>& rhs, Line<F3>& res) {
    auto s = lhs.ab ^ rhs.ab;
    auto ls = (rhs.a - lhs.a) ^ rhs.ab;
    if (s == 0) {
        if (ls != 0) return false;
        auto lhsa = lhs.a, lhsb = lhs.b();
        auto rhsa = rhs.a, rhsb = rhs.b();
        if (lhsa > lhsb) swap(lhsa, lhsb);
        if (rhsa > rhsb) swap(rhsa, rhsb);
        res = Line<F3>(max(lhsa, rhsa), min(lhsb, rhsb));
        return res.ab >= Point<F3>();
    }
    auto rs = (rhs.a - lhs.a) ^ lhs.ab;
    if (s < 0) s = -s, ls = -ls, rs = -rs;
    bool intersect = 0 <= ls && ls <= s && 0 <= rs && rs <= s;
    if (intersect)
        res = Line<F3>(lhs.a + lhs.ab * static_cast<F3>(ls) / s, Point<F3>());
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
void sortByAngle(Iterator first, Iterator last, const Point<F>& origin) {
    first = partition(first, last, [&origin](const decltype(*first)& point) {
        return point == origin; });
    auto pivot = partition(first, last, [&origin](const decltype(*first)& point) {
        return point > origin; });
    AngleCompare<F> acmp(origin);
    sort(first, pivot, acmp);
    sort(pivot, last, acmp);
}




template <class F>
struct Point3d {
    F x, y, z;
    Point3d() : x(0), y(0), z(0) {}
    Point3d(const F& x, const F& y, const F& z) : x(x), y(y), z(z) {}

    void swap(Point3d& other) {using std::swap; swap(x, other.x); swap(y, other.y); swap(z, other.z);}
    template <class F1> explicit operator Point3d<F1> () const {
        return Point3d<F1>(static_cast<F1>(x), static_cast<F1>(y), static_cast<F1>(z));}
    template <class F1> Point3d& operator = (const Point3d<F1>& other) {
        x = other.x; y = other.y; z = other.z; return *this; }
    template <class F1> Point3d& operator += (const Point3d<F1>& other) {
        x += other.x; y += other.y; z += other.z; return *this; }
    template <class F1> Point3d& operator -= (const Point3d<F1>& other) {
        x -= other.x; y -= other.y; z -= other.z; return *this; }
    template <class F1> Point3d& operator *= (const F1& factor) {
        x *= factor; y *= factor; z *= factor; return *this; }
    template <class F1> Point3d& operator /= (const F1& factor) {
        x /= factor; y /= factor; z /= factor; return *this; }
};

template <class F> istream& operator >> (istream& is, Point3d<F>& point) {
    return is >> point.x >> point.y >> point.z; }
template <class F> ostream& operator << (ostream& os, const Point3d<F>& point) {
    return os << point.x << ' ' << point.y << ' ' << point.z; }

template <class F> inline Point3d<F> makePoint(const F& x, const F& y, const F& z) { return Point3d<F>(x, y, z); }
template <class F> void swap(Point3d<F>& lhs, Point3d<F>& rhs) { lhs.swap(rhs); }

FUNC1(operator -, Point3d<F>& point, makePoint(-point.x, -point.y, -point.z))
FUNC2(operator +, Point3d<F1>& lhs, Point3d<F2>& rhs, makePoint(lhs.x + rhs.x, lhs.y + rhs.y, lhs.z + rhs.z))
FUNC2(operator -, Point3d<F1>& lhs, Point3d<F2>& rhs, makePoint(lhs.x - rhs.x, lhs.y - rhs.y, lhs.z - rhs.z))
FUNC2(operator *, F1& factor, Point3d<F2>& rhs, makePoint(factor * rhs.x, factor * rhs.y, factor * rhs.z))
FUNC2(operator *, Point3d<F1>& lhs, F2& factor, makePoint(lhs.x * factor, lhs.y * factor, lhs.z * factor))
FUNC2(operator /, Point3d<F1>& lhs, F2& factor, makePoint(lhs.x / factor, lhs.y / factor, lhs.z / factor))

FUNC2(operator *, Point3d<F1>& lhs, Point3d<F2>& rhs, lhs.x * rhs.x + lhs.y * rhs.y + lhs.z * rhs.z)
FUNC2(operator ^, Point3d<F1>& lhs, Point3d<F2>& rhs, lhs.y * rhs.z - lhs.z * rhs.y - lhs.z * rhs.x + lhs.x * rhs.z + lhs.x * rhs.y - lhs.y * rhs.x);

FUNC2(operator ==, Point3d<F1>& lhs, Point3d<F2>& rhs, (lhs.x == rhs.x && lhs.y == rhs.y && lhs.z == rhs.z))
FUNC2(operator !=, Point3d<F1>& lhs, Point3d<F2>& rhs, !(lhs == rhs))

FUNC2(operator <, Point3d<F1>& lhs, Point3d<F2>& rhs,
      lhs.x < rhs.x || (lhs.x == rhs.x && lhs.y < rhs.y) || (lhs.x == rhs.x && lhs.y == rhs.y && lhs.z < rhs.z))
FUNC2(operator >, Point3d<F1>& lhs, Point3d<F2>& rhs, rhs < lhs)
FUNC2(operator <=, Point3d<F1>& lhs, Point3d<F2>& rhs, !(lhs > rhs))
FUNC2(operator >=, Point3d<F1>& lhs, Point3d<F2>& rhs, !(lhs < rhs))

FUNC1(abs, Point3d<F>& point, point * point)
FUNC1(norm, Point3d<F>& point, sqrt(abs(point)))
FUNC2(dist, Point3d<F1>& lhs, Point3d<F2>& rhs, norm(lhs - rhs))
FUNC2(dist2, Point3d<F1>& lhs, Point3d<F2>& rhs, abs(lhs - rhs))

#undef FUNC1
#undef FUNC2
#undef FUNC3







struct line{
	Point<int> st, ed;
    long long a, b, c;
    line(): a(0), b(0), c(0){}
    line(Point<int> p1, Point<int> p2){
    	if(p1 == p2){
    		st = p1;
    		ed = p2;
    		a = b = c = 0;
    	}else{
			int dx, dy, gcd;
			dx = p2.x - p1.x, dy = p2.y - p1.y;
			gcd = __gcd(abs(dx), abs(dy));
			dx /= gcd, dy /= gcd;
			a = dy;
			b = -dx;
			c = dx * p1.y - dy * p1.x;
    	}
    }
    line(int _a, int _b, int _c) : a(_a), b(_b), c(_c){
        int gcd = __gcd(abs(a), abs(b));
        a /= gcd, b /= gcd, c /= gcd;
    }
    friend istream& operator >>(istream& in, line& l){
        in >> l.a >> l.b >> l.c;
        int gcd = __gcd(abs(l.a), abs(l.b));
        l.a /= gcd, l.b /= gcd, l.c /= gcd;
        return in;
    }
    friend ostream& operator <<(ostream& out, line& l){
        out << l.a << " " << l.b << " " << l.c;
        return out;
    }
    operator bool () const { return st != ed;}
};

line makeline(Point<int> st, Point<int> ed){return line(st, ed);}

bool operator ==(const line& lhs, const line& rhs){ return lhs.a == rhs.a && lhs.b == rhs.b && lhs.c == rhs.c;}
bool operator !=(const line& lhs, const line& rhs){return !(lhs == rhs);}

bool operator <(const line& lhs, const line& rhs){return lhs.a < rhs.a || (lhs.a == rhs.a && lhs.b < rhs.b) || (lhs.a == rhs.a && lhs.b == rhs.b && lhs.c < rhs.c);}
bool operator <=(const line& lhs, const line& rhs){return (lhs < rhs) || (lhs == rhs);}
bool operator >(const line& lhs, const line& rhs){return rhs < lhs;}
bool operator >=(const line& lhs, const line& rhs){return (lhs > rhs) || (lhs == rhs);}

int orientation(const line& l, Point<int> p){
	return sgn(l.a * p.x + l.b * p.y + l.c);
}

bool intersectLines(line& l1, line& l2, Point<long double>& p){ 

    if(l1.a == l2.a && l1.b == l2.b) return false;
    p.x = ((long double)l1.b * l2.c - l2.b * l1.c) / (l2.b * l1.a - l1.b * l2.a);
    if(l1.b != 0)   p.y = -((long double)l1.a * p.x + l1.c) / l1.b;
    else            p.y = -((long double)l2.a * p.x + l2.c) / l2.b;
    return true;
}







template <class F> using Polygon = vector<Point<F>>;
inline int prev(int i, int n) { return i == 0 ? n-1 : i-1; }
inline int next(int i, int n) { return i == n-1 ? 0 : i+1; }

template <class F>
F area(const Polygon<F>& poly) {
  int n = static_cast<int>(poly.size());
  F area = F(0);
  for (int i = 0; i < n; ++i)
    area += poly[i].x * (poly[next(i, n)].y - poly[prev(i, n)].y);
  return area;
}

template <class F>
bool orientation(const Polygon<F>& poly) {
  int n = static_cast<int>(poly.size());
  int i = static_cast<int>(min_element(begin(poly), end(poly)) - begin(poly));
  return ccw(poly[prev(i, n)], poly[next(i, n)], poly[i]) > 0;
}

template <class F>
Polygon<F> convexHull(Polygon<F> points) {
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
int pointVsTriangle(const Point<F1>& point, const Polygon<F2>& triangle) {
  assert(triangle.size() == 3);
  int signs[3];
  for (int i = 0; i < 3; ++i)
    signs[i] = sgn(ccw(point, triangle[next(i, 3)], triangle[i]));
  if (signs[0] == signs[1] && signs[1] == signs[2]) return -1;
  for (int i = 0; i < 3; ++i) if (signs[i] * signs[next(i, 3)] == -1) return 1;
  return 0;
}

template<class F>
int top(Polygon<F> poly){
	int indx = -1;
	F maxY = -OO;
	for(int i = 0 ; i < (int)poly.size() ; i++){
		if(maxY < poly[i].y){
			maxY = poly[i].y;
			indx = i;
		}else if(maxY == poly[i].y && poly[i].x > poly[indx].x){
			indx = i;
		}
	}
	return indx;
}

template<class F>
int bottom(Polygon<F> poly){
	int indx;
	F minY = OO;
	for(int i = 0 ; i < (int)poly.size() ; i++){
		if(minY > poly[i].y){
			minY = poly[i].y;
			indx = i;
		}else if(minY == poly[i].y && poly[i].x < poly[indx].x){
			indx = i;
		}
	}
	return indx;
}

template<class F>
void makeReady(Polygon<F>& poly){
	int b;
	Polygon<F> temp;
	b = bottom(poly);
	for(int i = b ; i >= 0 ; i--){temp.push_back(poly[i]);}
	for(int i = (int)poly.size() - 1 ; i > b ; i--){temp.push_back(poly[i]);}
	for(int i = 0 ; i < (int)poly.size() ; i++){poly[i] = temp[i];}
}

template <class F1, class F2>
int pointVsConvexPolygon(const Point<F1>& point, const Polygon<F2>& poly, int top) {
	if (point < poly[0] || point > poly[top]) return 1;
  auto orientation = ccw((point), poly[top], poly[0]);
  if (orientation == 0) {
    if (point == poly[0] || point == poly[top]) return 0;
    return top == 1 || top + 1 == (int)poly.size() ? 0 : -1;
  }
  if (orientation < 0) {
    auto itr = lower_bound(begin(poly) + 1, begin(poly) + top, point);
    return sgn(ccw(itr[0], (point), itr[-1]));
  } else {
    auto itl = upper_bound(poly.rbegin(), poly.rend() - top-1, point);
    return sgn(ccw(itl == poly.rbegin() ? poly[0] : itl[-1], (point), itl[0]));
  }
}

int main() {






	std::ios::sync_with_stdio(0), cin.tie(0);

	int n, m, t;
	cin >> n;
	Point<long long> p;
	Polygon<long long> poly1, poly2;
	for(int i = 0 ; i < n ; i++){
		cin >> p;
		poly1.push_back(p);
	}
	cin >> m;
	for(int i = 0 ; i < m ; i++){
		cin >> p;
		poly2.push_back(p);
	}

	makeReady(poly1);
	t = top(poly1);

	for(int i = 0, ret ; i < m ; i++){
		ret = pointVsConvexPolygon(poly2[i], poly1, t);
		if(ret != -1){
			cout << "NO";
			return 0;
		}
	}
	cout << "YES";
	return 0;
}
