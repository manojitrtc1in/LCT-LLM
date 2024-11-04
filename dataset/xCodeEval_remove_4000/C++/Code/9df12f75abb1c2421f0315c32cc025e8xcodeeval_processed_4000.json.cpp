

using namespace std;

const long double eps = 1e-9, pi = acos(-1);

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



FUNC2(ccw, Point<F1>& lhs, Point<F2>& rhs, sgn(rhs ^ lhs))
FUNC3(ccw, Point<F1>& lhs, Point<F2>& rhs, Point<F3>& origin, ccw(lhs - origin, rhs - origin))

FUNC2(operator ==, Point<F1>& lhs, Point<F2>& rhs, fabs(lhs.x - rhs.x) < eps && fabs(lhs.y - rhs.y) < eps)
FUNC2(operator !=, Point<F1>& lhs, Point<F2>& rhs, !(lhs == rhs))

FUNC2(operator <, Point<F1>& lhs, Point<F2>& rhs,
      lhs.x < rhs.x || (lhs.x == rhs.x && lhs.y < rhs.y))
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
bool id0(const Line<F1>& lhs, const Line<F2>& rhs, Point<F3>& res) {
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
bool id1(const Line<F1>& lhs, const Line<F2>& rhs, Point<F3>& res) {
    return id0<1, 1, 1, 1>(lhs, rhs, res);
}

template <class F1, class F2, class F3>
bool id2(const Line<F1>& lhs, const Line<F2>& rhs, Line<F3>& res) {
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
void id3(Iterator first, Iterator last, const Point<F>& origin) {
    first = partition(first, last, [&origin](const decltype(*first)& point) {
        return point == origin; });
    auto pivot = partition(first, last, [&origin](const decltype(*first)& point) {
        return point > origin; });
    AngleCompare<F> acmp(origin);
    sort(first, pivot, acmp);
    sort(pivot, last, acmp);
}




template <class F>
struct id4 {
    F x, y, z;
    id4() : x(0), y(0), z(0) {}
    id4(const F& x, const F& y, const F& z) : x(x), y(y), z(z) {}

    void swap(id4& other) {using std::swap; swap(x, other.x); swap(y, other.y); swap(z, other.z);}
    template <class F1> explicit operator id4<F1> () const {
        return id4<F1>(static_cast<F1>(x), static_cast<F1>(y), static_cast<F1>(z));}
    template <class F1> id4& operator = (const id4<F1>& other) {
        x = other.x; y = other.y; z = other.z; return *this; }
    template <class F1> id4& operator += (const id4<F1>& other) {
        x += other.x; y += other.y; z += other.z; return *this; }
    template <class F1> id4& operator -= (const id4<F1>& other) {
        x -= other.x; y -= other.y; z -= other.z; return *this; }
    template <class F1> id4& operator *= (const F1& factor) {
        x *= factor; y *= factor; z *= factor; return *this; }
    template <class F1> id4& operator /= (const F1& factor) {
        x /= factor; y /= factor; z /= factor; return *this; }
};

template <class F> istream& operator >> (istream& is, id4<F>& point) {
    return is >> point.x >> point.y >> point.z; }
template <class F> ostream& operator << (ostream& os, const id4<F>& point) {
    return os << point.x << ' ' << point.y << ' ' << point.z; }

template <class F> inline id4<F> makePoint(const F& x, const F& y, const F& z) { return id4<F>(x, y, z); }
template <class F> void swap(id4<F>& lhs, id4<F>& rhs) { lhs.swap(rhs); }

FUNC1(operator -, id4<F>& point, makePoint(-point.x, -point.y, -point.z))
FUNC2(operator +, id4<F1>& lhs, id4<F2>& rhs, makePoint(lhs.x + rhs.x, lhs.y + rhs.y, lhs.z + rhs.z))
FUNC2(operator -, id4<F1>& lhs, id4<F2>& rhs, makePoint(lhs.x - rhs.x, lhs.y - rhs.y, lhs.z - rhs.z))
FUNC2(operator *, F1& factor, id4<F2>& rhs, makePoint(factor * rhs.x, factor * rhs.y, factor * rhs.z))
FUNC2(operator *, id4<F1>& lhs, F2& factor, makePoint(lhs.x * factor, lhs.y * factor, lhs.z * factor))
FUNC2(operator /, id4<F1>& lhs, F2& factor, makePoint(lhs.x / factor, lhs.y / factor, lhs.z / factor))

FUNC2(operator *, id4<F1>& lhs, id4<F2>& rhs, lhs.x * rhs.x + lhs.y * rhs.y + lhs.z * rhs.z)
FUNC2(operator ^, id4<F1>& lhs, id4<F2>& rhs, lhs.y * rhs.z - lhs.z * rhs.y - lhs.z * rhs.x + lhs.x * rhs.z + lhs.x * rhs.y - lhs.y * rhs.x);

FUNC2(operator ==, id4<F1>& lhs, id4<F2>& rhs, (lhs.x == rhs.x && lhs.y == rhs.y && lhs.z == rhs.z))
FUNC2(operator !=, id4<F1>& lhs, id4<F2>& rhs, !(lhs == rhs))

FUNC2(operator <, id4<F1>& lhs, id4<F2>& rhs,
      lhs.x < rhs.x || (lhs.x == rhs.x && lhs.y < rhs.y) || (lhs.x == rhs.x && lhs.y == rhs.y && lhs.z < rhs.z))
FUNC2(operator >, id4<F1>& lhs, id4<F2>& rhs, rhs < lhs)
FUNC2(operator <=, id4<F1>& lhs, id4<F2>& rhs, !(lhs > rhs))
FUNC2(operator >=, id4<F1>& lhs, id4<F2>& rhs, !(lhs < rhs))

FUNC1(abs, id4<F>& point, point * point)
FUNC1(norm, id4<F>& point, sqrt(abs(point)))
FUNC2(dist, id4<F1>& lhs, id4<F2>& rhs, norm(lhs - rhs))
FUNC2(dist2, id4<F1>& lhs, id4<F2>& rhs, abs(lhs - rhs))











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

line makeLine(Point<int> st, Point<int> ed){return line(st, ed);}

bool operator ==(const line& lhs, const line& rhs){ return lhs.a == rhs.a && lhs.b == rhs.b && lhs.c == rhs.c;}
bool operator !=(const line& lhs, const line& rhs){return !(lhs == rhs);}

bool operator <(const line& lhs, const line& rhs){return lhs.a < rhs.a || (lhs.a == rhs.a && lhs.b < rhs.b) || (lhs.a == rhs.a && lhs.b == rhs.b && lhs.c < rhs.c);}
bool operator <=(const line& lhs, const line& rhs){return (lhs < rhs) || (lhs == rhs);}
bool operator >(const line& lhs, const line& rhs){return rhs < lhs;}
bool operator >=(const line& lhs, const line& rhs){return (lhs > rhs) || (lhs == rhs);}

int orientation(const line& l, Point<int> p){
	return sgn(l.a * p.x + l.b * p.y + l.c);
}

bool id0(line& l1, line& l2, Point<long double>& p){ 

    if(l1.a == l2.a && l1.b == l2.b) return false;
    p.x = ((long double)l1.b * l2.c - l2.b * l1.c) / (l2.b * l1.a - l1.b * l2.a);
    if(l1.b != 0)   p.y = -((long double)l1.a * p.x + l1.c) / l1.b;
    else            p.y = -((long double)l2.a * p.x + l2.c) / l2.b;
    return true;
}





bool SQRT(int x, int& y){
	int middle, l = 1, r = 1005;
	while(l <= r){
		middle = (l + r) / 2;
		if(middle * middle == x){ y = middle; return true;}
		else if(middle * middle < x){ l = middle + 1;}
		else {r = middle - 1;}
	}
	return false;
}

int main(){




	int a, b, d, n, gcd;
	cin >> a >> b;
	if(a > b) swap(a, b);
	gcd = __gcd(a, b);
	n = a / gcd;
	d = b / gcd;
	for(int x = 1, y ; x < b ; x++){
		if(SQRT(b * b - x * x, y)){
			if(x % d == 0 && y % d == 0){
				cout << "YES\n";
				cout << "0 0\n" << x << ' ' << y << '\n' << (-y * n) / d << ' ' << (x * n) / d;
				return 0;
			}
		}
	}
	cout << "NO";
	return 0;
}

