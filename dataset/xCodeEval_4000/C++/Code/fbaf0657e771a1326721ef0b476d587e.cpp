#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cmath>
#include<iomanip>
#include<cassert>

using namespace std;

namespace geometry2d {

	

	const double EPS = 1e-10;

	

	

	int sgn(const double a) {
		return (a < -EPS ? -1 : (a > EPS ? +1 : 0));
	}

	struct Point {
		


		double x, y;
		Point(double _x, double _y) {
			x = _x, y = _y;
		}
		Point() {
			x = 0, y = 0;
		}

		Point operator+() const {
			return *this;
		}
		Point operator-() const {
			return{ -x, -y };
		}
		Point operator+ (const Point& b) const {
			return{ x + b.x, y + b.y };
		}
		Point operator- (const Point& b) const {
			return{ x - b.x, y - b.y };
		}
		Point operator* (const double b) const {
			return{ x * b, y * b };
		}
		Point operator/ (const double b) const {
			return{ x / b, y / b };
		}
		Point operator+= (const Point& b) {
			x += b.x, y += b.y;
			return *this;
		}
		Point operator-= (const Point& b) {
			x -= b.x, y -= b.y;
			return *this;
		}
		Point operator*= (const double b) {
			x *= b, y *= b;
			return *this;
		}
		Point operator/= (const double b) {
			x /= b, y /= b;
			return *this;
		}
		bool operator== (const Point& b) {
			return b.x == x && b.y == y;
		}

		double lengthSquare() const {
			return (x * x + y * y);
		}
		double length() const {
			return std::sqrt(lengthSquare());
		}
		double dot(const Point& b) const {
			return x * b.x + y * b.y;
		}
		double cross(const Point& b) const {
			

			return x * b.y - y * b.x;
		}
		double distanceFrom(const Point& b) const {
			return std::sqrt((x - b.x) * (x - b.x) + (y - b.y) * (y - b.y));
		}
		Point normalized() const {
			return{ x / length(), y / length() };
		}
		bool isZero() const {
			return sgn(x) == 0 && sgn(y) == 0;
		}
		

		Point normalUnitVector() const {
			return{ -normalized().y, normalized().x };
		}
		

		Point rotation(double arg) const {
			double cs = cos(arg), sn = sin(arg);
			return Point(x * cs - y * sn, x * sn + y * cs);
		}
		

		double angle() const {
			return atan2(y, x);
		}
	};

	inline Point operator*(double a, const Point& b) {
		return{ b.x * a, b.y * a };
	}

	template <class Char>
	inline std::basic_ostream<Char>& operator <<(std::basic_ostream<Char>& os, const Point& v)
	{
		return os << Char('(') << v.x << Char(',') << v.y << Char(')');
	}

	template <class Char>
	inline std::basic_istream<Char>& operator >> (std::basic_istream<Char>& is, Point& v)
	{
		return is >> v.x >> v.y;
	}

	

	const Point error_val = { 114514.0, -191981.0 };

	inline bool operator==(const Point& a, const Point& b) {
		return (sgn(a.x - b.x) == 0 && sgn(a.y - b.y) == 0);
	}

	inline bool operator!=(const Point& a, const Point& b) {
		return !(a == b);
	}

	

	inline bool operator<(const Point& a, const Point& b) {
		if (sgn(a.x - b.x) != 0)return sgn(a.x - b.x) < 0;
		else return sgn(a.y - b.y) < 0;
	}

	
	int iSP(const Point& a, const Point& b, const Point& c) {
		int flg = sgn((b - a).cross(c - a));
		if (flg == 1) {
			return +1;
		}
		else if (flg == -1) {
			return -1;
		}
		else {
			

			if (sgn((b - a).dot(c - b)) > 0)
				return +2;
			

			else if (sgn((a - b).dot(c - a)) > 0)
				return -2;
			

			else
				return 0;
		}
	}

	

	int angletype(const Point& a, const Point& b, const Point& c) {
		auto v = (a - b).dot(c - b);
		if (sgn(v) > 0)return 0;
		else if (sgn(v) == 0)return 1;
		else return 2;
	}

	

	namespace line2d {

		

		struct Line {

			

			Point begin, end;

			Line() {
				begin = Point(), end = Point();
			}

			Line(const Point& b, const Point& e) {
				begin = b, end = e;
			}

			

			Line(const double a, const double b, const double c) {
				if (sgn(a) == 0 && sgn(b) == 0) {
					assert(-1);
				}

				if (sgn(b) == 0) {
					

					begin = Point(-c / a, 0.0);
					end = Point(-c / a, 1.0);
				}
				else {
					

					begin = Point(0, -c / b);
					end = Point(1.0, -(a + c) / b);
				}
			}

			Point vec() const {
				return end - begin;
			}

			Point countervec() const {
				return begin - end;
			}

		};

		

		typedef Line Ray;
		

		typedef Line Segment;


		

		Point lineIntersection(const Line& l1, const Line& l2) {
			if (sgn(l1.vec().cross(l2.vec())) == 0)return error_val;

			Point ret;
			ret = l1.begin + l1.vec() *
				abs((l2.end - l1.begin).cross(l2.vec()) / l1.vec().cross(l2.vec()));
			return ret;
		}

		

		

		pair<bool, Point> segmentIntersection(const Segment& s1, const Segment& s2) {

			if (iSP(s1.begin, s1.end, s2.begin) * iSP(s1.begin, s1.end, s2.end) <= 0 &&
				iSP(s2.begin, s2.end, s1.begin) * iSP(s2.begin, s2.end, s1.end) <= 0) {

				

				if (s1.vec().cross(s2.vec()) == 0)
					return make_pair(true, error_val);
				else 

					return make_pair(true, lineIntersection(s1, s2));

			}
			return make_pair(false, error_val);
		}


		

		double distanceBetweenPointAndLine(const Point& p, const Line& l) {
			return abs(l.vec().cross(p - l.begin) / l.vec().length());
		}

		

		double distanceBetweenPointAndRay(const Point& p, const Ray& r) {
			

			if (sgn((p - r.begin).dot(r.vec())) < 0)
				return r.begin.distanceFrom(p);
			return abs(r.vec().cross(p - r.begin) / r.vec().length());
		}

		

		double distanceBetweenPointAndSegment(const Point& p, const Segment& s) {
			if (sgn(s.vec().dot(p - s.begin)) < 0 || sgn(s.countervec().dot(p - s.end)) < 0) {
				

				return min(p.distanceFrom(s.begin), p.distanceFrom(s.end));
			}
			return distanceBetweenPointAndLine(p, s);
		}

		

		double distanceBetweenSegmentAndSegment(const Segment& s1, const Segment& s2) {
			if (segmentIntersection(s1, s2).first)return 0;


			double ans = distanceBetweenPointAndSegment(s1.begin, s2);
			ans = min(ans, distanceBetweenPointAndSegment(s1.end, s2));
			ans = min(ans, distanceBetweenPointAndSegment(s2.begin, s1));
			ans = min(ans, distanceBetweenPointAndSegment(s2.end, s1));
			return ans;
		}

		

		

		Point projection(const Point& a, const Line& l) {
			Point ret;
			ret = l.begin +
				l.vec().normalized() * (a - l.begin).dot(l.vec()) / l.vec().length();
			return ret;
		}

		

		Point reflection(const Point& a, const Line& l) {
			Point ret;
			ret = a + 2 * (projection(a, l) - a);
			return ret;
		}
	}

	namespace circle2d {

		struct Circle {
			Point o;
			double r;

			Circle() {
				o = Point();
				r = 0;
			}

			Circle(const Point& C, const double& R) {
				o = C, r = R;
			}
		};

		

		

		vector<Point> intersectionCircleAndLine(const Circle& c, const line2d::Line& l) {
			

			if (sgn(line2d::distanceBetweenPointAndLine(c.o, l) - c.r) > 0) {
				return vector<Point>();
			}
			else if (sgn(line2d::distanceBetweenPointAndLine(c.o, l)) == 0) {
				

				vector<Point> ret;
				ret.push_back(c.o + l.vec().normalized() * c.r);
				ret.push_back(c.o - l.vec().normalized() * c.r);
				return ret;
			}
			else {

				

				Point H = line2d::projection(c.o, l);
				vector<Point> ret;

				ret.push_back(
					H + (c.o - H).normalUnitVector() *
					sqrt(max(0.0, pow(c.r, 2) - pow(line2d::distanceBetweenPointAndLine(c.o, l), 2)))
				);
				ret.push_back(
					H - (c.o - H).normalUnitVector() *
					sqrt(max(0.0, pow(c.r, 2) - pow(line2d::distanceBetweenPointAndLine(c.o, l), 2)))
				);
				return ret;
			}
		}

		

		

		vector<Point> intersectionCircleAndSegment(const Circle& c, const line2d::Segment& s) {
			auto tmp = intersectionCircleAndLine(c, s);
			vector<Point> ret;
			for (int i = 0; i < tmp.size(); i++) {
				if (sgn(line2d::distanceBetweenPointAndSegment(tmp[i], s)) == 0)
					ret.push_back(tmp[i]);
			}
			return ret;
		}

		
		pair<int, vector<Point>> intersectionCircleAndCircle(const Circle& c1, const Circle& c2) {
			Point d = c2.o - c1.o;
			vector<Point> ret;
			int mode;

			

			if (sgn(d.length() - c1.r - c2.r) > 0 || sgn(d.length() - abs(c1.r - c2.r)) < 0) {
				if (sgn(d.length() - c1.r - c2.r) > 0)mode = +4;
				else {
					if (sgn(c1.r - c2.r) > 0)mode = +1;
					else mode = -1;
				}
				return make_pair(mode, ret);
			}
			else {
				if (sgn(d.length() - c1.r - c2.r) == 0)mode = +3;
				else if (sgn(d.length() - (c1.r + c2.r)) < 0 &&
					sgn(d.length() - abs(c1.r - c2.r)) > 0)mode = +2;
				else mode = 0;
			}
			double AH = (pow(c1.r, 2) - pow(c2.r, 2) + d.lengthSquare()) / (2.0 * d.length());
			double CH = sqrt(max(0.0, pow(c1.r, 2) - pow(AH, 2)));

			ret.push_back(c1.o + d.normalized() * AH + d.normalUnitVector() * CH);
			if (mode != 0 && mode != +3)
				ret.push_back(c1.o + d.normalized() * AH - d.normalUnitVector() * CH);
			return make_pair(mode, ret);
		}

		

		

		vector<Point> tangentToCircle(const Point& p, const Circle& c) {
			if (sgn(c.o.distanceFrom(p) - c.r) < 0) {
				

				return vector<Point>();
			}
			return intersectionCircleAndCircle(c,
				Circle(p,
					sqrt(max(0.0, (p - c.o).lengthSquare() - pow(c.r, 2))))
			).second;
		}

		vector<geometry2d::line2d::Line> tangentBetweenCircleAndCircle(const Circle& c1, const Circle& c2) {
			vector<geometry2d::line2d::Line> ret;
			if (sgn(abs(c1.r - c2.r) - (c1.o - c2.o).length()) > 0) {
				

				return ret;
			}
			double d = (c1.o - c2.o).length();
			for (double s : {-1.0, 1.0}) {
				

				if (d == abs(c1.r + c2.r * s)) {
					geometry2d::line2d::Line tmp;
					tmp.begin = c1.o +
						(sgn(c1.r + c2.r * s) >= 0 ?
							(c2.o - c1.o).normalized() * c1.r :
							(c1.o - c2.o).normalized() * c1.r
							);
					tmp.end = tmp.begin + (c2.o - c1.o).normalUnitVector();

					ret.push_back(tmp);
					return ret;
				}
				else if (sgn(d - (c1.r + c2.r * s)) > 0) {
					double cs = (c1.r + c2.r * s) / d;

					double sn = sqrt(max(0.0, 1 - cs * cs));

					Point U = (c2.o - c1.o).normalized(), V = U.normalUnitVector();
					U *= cs, V *= sn;
					geometry2d::line2d::Line tmp1, tmp2;
					tmp1 = geometry2d::line2d::Line(c1.o + (U + V) * c1.r, c2.o - (U + V) * c2.r * s);
					tmp2 = geometry2d::line2d::Line(c1.o + (U - V) * c1.r, c2.o - (U - V) * c2.r * s);
					ret.push_back(tmp1), ret.push_back(tmp2);

				}
			}
			return ret;
		}

	}

	

	namespace polygon2d {

		typedef vector<Point> Polygon;


									  

									  

									  

		vector<Point> convexHull(vector<Point>& p, bool f) {


			sort(p.begin(), p.end());

			vector<Point> ret(2 * p.size());
			int k = 0;


					  

			for (int i = 0; i < p.size(); i++) {
				while (k > 1 &&
					((!f && iSP(ret[k - 2], ret[k - 1], p[i]) != +1) ||
						(f && iSP(ret[k - 2], ret[k - 1], p[i]) == -1)))k--;
				ret[k] = p[i];
				k++;
			}

			

			for (int i = p.size() - 2, t = k; i >= 0; i--) {
				while (k > t &&
					((!f && iSP(ret[k - 2], ret[k - 1], p[i]) != +1) ||
						(f && iSP(ret[k - 2], ret[k - 1], p[i]) == -1)))k--;
				ret[k] = p[i];
				k++;
			}
			ret.resize(k - 1);

			return ret;
		}

		

		double polygonArea(const Polygon& p) {
			double ret = 0;
			for (int i = 0; i < p.size(); i++) {
				ret += p[i].cross(p[(i + 1) % p.size()]);
			}
			return ret / 2.0;
		}

		

		

		

		

		int enclose(const Polygon& pol, const Point& poi) {
			int cnt = 0;
			for (int i = 0; i < pol.size(); i++) {
				Point u = pol[i] - poi, v = pol[(i + 1) % pol.size()] - poi;

				if (sgn(u.cross(v)) == 0 && sgn(u.dot(v)) <= 0) {
					return 2;
				}

				if (sgn(u.y - v.y) > 0)swap(u, v);
				if (sgn(u.y) <= 0 && sgn(v.y) > 0 && sgn(u.cross(v)) > 0)cnt++;

			}
			return cnt % 2 ? 1 : 0;
		}

		int enclose2(const Polygon& pol, const Point& poi) {
			line2d::Ray ray(poi, poi + Point(11.4, 5.14)); 

			int cnt = 0;
			for (int i = 0; i < pol.size(); i++) {
				line2d::Segment s(pol[i], pol[(i + 1) % pol.size()]);

				if (sgn(line2d::distanceBetweenPointAndSegment(poi, s)) == 0) {
					return 2;
				}

				

				Point vi = line2d::lineIntersection(s, ray);
				if (vi == error_val)continue;
				

				

				if (sgn(line2d::distanceBetweenPointAndRay(vi, ray)) == 0 &&
					sgn(line2d::distanceBetweenPointAndSegment(vi, s)) == 0 &&
					s.begin != vi && s.end != vi)cnt++;

			}
			return cnt % 2 ? 1 : 0;
		}

		

		int enclose3(const Polygon& pol, const Point& poi) {
			double ang = 0;
			for (int i = 0; i < pol.size(); i++) {

				

				if (sgn(line2d::distanceBetweenPointAndSegment(poi,
					line2d::Segment(pol[i], pol[(i + 1) % pol.size()]))) == 0) {
					return 2;
				}

				Point u = (pol[i] - poi), v = (pol[(i + 1) % pol.size()] - poi);
				double ASIN = u.cross(v) / u.length() / v.length();
				if (angletype(pol[i], poi, pol[(i + 1) % pol.size()]) == 2) {
					

					double tmp = asin(max(-1.0, min(ASIN, 1.0)));
					if (sgn(tmp) > 0)ang += (acos(-1) - tmp);
					else ang += (-acos(-1) - tmp);
				}
				else {
					ang += asin(max(-1.0, min(ASIN, 1.0)));
				}
			}

			

			

			if (sgn(ang - acos(-1)) > 0) {
				return 1;
			}
			else return 0;
		}

		

		Point centerOfGravity(const Polygon& p) {
			if (p.size() <= 2)return error_val;
			Point ret;
			for (int i = 0; i < p.size(); i++) {
				Point u = p[i], v = p[(i + 1) % p.size()];
				ret += Point((u.x + v.x) / 3, (u.y + v.y) / 3) * u.cross(v);
			}
			double S = polygonArea(p);
			cout << S << endl;
			ret /= 2.0, ret /= S;
			return ret;
		}

		

		Point incenter(const Polygon& p) {
			if (p.size() != 3)return error_val;
			Point a = p[0], b = p[1], c = p[2];
			Point f, e;

			f = b + (c - b) * (b - a).length() / ((b - a).length() + (c - a).length());
			e = c + (a - c) * (c - b).length() / ((c - b).length() + (a - b).length());
			return line2d::lineIntersection(line2d::Line(b, e), line2d::Line(a, f));
		}

		

		Point circumcenter(const Polygon& p) {
			if (p.size() != 3)return error_val;
			Point a = p[0], b = p[1], c = p[2];

			line2d::Line d, e;
			d = line2d::Line((b + a) / 2.0, (b + a) / 2.0 + (b - a).normalUnitVector());
			e = line2d::Line((c + a) / 2.0, (c + a) / 2.0 + (c - a).normalUnitVector());
			return line2d::lineIntersection(d, e);
		}

		

		Point orthocenter(const Polygon& p) {
			if (p.size() != 3)return error_val;
			Point a = p[0], b = p[1], c = p[2];

			Point d, e;
			d = line2d::projection(c, line2d::Line(a, b));
			e = line2d::projection(a, line2d::Line(b, c));
			return line2d::lineIntersection(line2d::Line(d, c), line2d::Line(e, a));
		}

	}

}

int main() {
	const double pi = acos(-1);

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;

		double radius = 1.0 / 2 / sin(pi / (2 * n));
		vector < geometry2d::Point> pgon(2 * n);
		for (int i = 0; i < 2 * n; i++) {
			pgon[i] = geometry2d::Point(radius * cos(2 * pi * ((double)i / (double)(2 * n))), 
				radius * sin(2 * pi * ((double)i / (double)(2 * n))));
		}

		auto getsquare = [&](vector<geometry2d::Point>& p, double arg) {
			double xM = -114514, xm = 114514, yM = -114514, ym = 114514;
			for (int i = 0; i < 2 * n; i++) {
				geometry2d::Point tmp = p[i].rotation(arg);
				xM = max(xM, tmp.x), xm = min(xm, tmp.x);
				yM = max(yM, tmp.y), ym = min(ym, tmp.y);
			}
			return max(xM - xm, yM - ym);
		};

		double u = pi / (n * 2), l = 0.0;
		for (int i = 0; i < 100; i++) {
			double m1 = (u + l * 2) / 3.0, m2 = (u * 2 + l) / 3.0;
			if (getsquare(pgon, m1) > getsquare(pgon, m2)) {
				l = m1;
			}
			else u = m2;
		}
		cout << setprecision(10) << getsquare(pgon, u) << "\n";
	}
	return 0;
}