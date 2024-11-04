#include<complex>
#include <vector>
#include <algorithm>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <bitset>
#include <string>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <limits>
#include <climits>
#include <time.h>
#include <cstdio>
#include <numeric>
#define LL long long
#define LD long double
#define rei(x) scanf("%d",&x)
#define reii(x,y) scanf("%d%d",&x,&y)
#define reiii(x,y,z) scanf("%d%d%d",&x,&y,&z)

#define rel(x) scanf("%lld",&x);

#define ref(x) scanf("%lf",&x)
#define rec(x) scanf("%c",&x)
#define res(x) scanf("%s",x)
#define fi first
#define se second
#define pb push_back
#define f(i, a, b) for(int i = a; i <= b; i++)
#define ms(Arr) memset(Arr,0,sizeof(Arr));
#define CLR(arr,val)  memset(arr,val,sizeof(arr))
#define bit(a , b) (((a)>>(b))&1)
#define fin freopen("in.txt","r",stdin)
#define fout freopen("out.txt","w",stdout)
#define fout1 freopen("out1.txt","w",stdout)
#define ftest freopen("in.txt","w",stdout)
#define lson (id << 1)
#define rson (id << 1 | 1)
#define ls (i << 1)
#define rs (i << 1 | 1)
using namespace std;
const int INF = 0x3f3f3f3f;
const LL mod = 1000000009;
const double e = 2.718281828459;
typedef pair<int, int> Pii;
typedef pair<LL, LL> Pll;




LL gcd(LL a, LL b)
{
	if (!b)return a;
	return gcd(b, a%b);
}

LL gcd1(int a, int b)
{
	if (!b)return a;
	return gcd(b, a%b);
}


LL pow_mod(LL a, LL b, LL c)
{
	LL ans = 1;
	a = a % c;
	while (b > 0)
	{
		if (b % 2 == 1)
			ans = (ans * a) % c;
		b = b / 2;
		a = (a * a) % c;
	}
	return ans;
}


int pow_int(int a, int b)
{
	int ans = 1;
	while (b > 0)
	{
		if (b % 2 == 1)
			ans = ans * a;
		b = b / 2;
		a = a * a;
	}
	return ans;
}

LL pow_llong(LL a, LL b)
{
	LL ans = 1;
	while (b > 0)
	{
		if (b % 2 == 1)
			ans = ans * a;
		b = b / 2;
		a = a * a;
	}
	return ans;
}

const int dx[9] = { 0, 1, 1, 1, 0,-1,-1,-1, 0 };
const int dy[9] = { 0, 1, 0,-1,-1,-1, 0, 1, 1 };

int Scan()
{
	int res = 0, flag = 0;
	char ch;
	if ((ch = getchar()) == '-')
	{
		flag = 1;
	}
	else if (ch >= '0' && ch <= '9')
	{
		res = ch - '0';
	}
	while ((ch = getchar()) >= '0' && ch <= '9')
	{
		res = res * 10 + (ch - '0');
	}
	return flag ? -res : res;
}

void Out(int a)
{
	if (a < 0)
	{
		putchar('-');
		a = -a;
	}
	if (a >= 10)
	{
		Out(a / 10);
	}
	putchar(a % 10 + '0');
}

LL jc_mod(LL a, LL b, LL mod)
{
	LL ans = 1;
	b = max(b, a - b);
	for (LL i = a; i > b; i--)
	{
		ans *= i;
		ans %= mod;
	}
	return ans;
}

double lg(double a)
{
	return (log(a) / log(10.0));
}

int lowbit(int x)
{
	return x & -x;
}


















inline int read()
{
	int f = 1, x = 0; char ch = getchar();
	while (ch<'0' || ch>'9') { if (ch == '-')f = -1; ch = getchar(); }
	while (ch >= '0'&&ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x*f;
}



















#define MAXNN 100010
void lisan(int *x, int n) {
	

	int data[MAXNN];
	f(i, 1, n)data[i] = x[i];
	sort(data + 1, data + 1 + n);

	int o = unique(data + 1, data + 1 + n) - data - 1;

	f(i, 1, n)x[i] = lower_bound(data + 1, data + 1 + o, x[i]) - data;

}
















LL calc(int M)
{
	return 1;
}
int sanfen(int L, int R)
{
	int M, RM;
	while (L + 1 < R)
	{
		M = (L + R) / 2;
		RM = (M + R) / 2;
		if (calc(M) < calc(RM)) 

			R = RM;
		else
			L = M;
	}
	return L;
}







int CaculateWeekDay(int y, int m, int d)
{
	if (m == 1 || m == 2) {
		m += 12;
		y--;
	}
	int iWeek = (d + 2 * m + 3 * (m + 1) / 5 + y + y / 4 - y / 100 + y / 400) % 7;
	return iWeek;
}








using namespace std;
typedef pair<int, int> pii;
const double pi = 4 * atan(1);
const double eps = 1e-10;

inline int dcmp(double x) { if (fabs(x) < eps) return 0; else return x < 0 ? -1 : 1; }
inline double getDistance(double x, double y) { return sqrt(x * x + y * y); }
inline double torad(double deg) { return deg / 180 * pi; }

struct Point {
	double x, y;
	Point(double x = 0, double y = 0) : x(x), y(y) {}
	void read() { scanf("%lf%lf", &x, &y); }
	void write() { printf("%f %f", x, y); }

	bool operator == (const Point& u) const { return dcmp(x - u.x) == 0 && dcmp(y - u.y) == 0; }
	bool operator != (const Point& u) const { return !(*this == u); }
	bool operator < (const Point& u) const { return dcmp(x - u.x) < 0 || (dcmp(x - u.x) == 0 && dcmp(y - u.y) < 0); }
	bool operator > (const Point& u) const { return u < *this; }
	bool operator <= (const Point& u) const { return *this < u || *this == u; }
	bool operator >= (const Point& u) const { return *this > u || *this == u; }
	Point operator + (const Point& u) { return Point(x + u.x, y + u.y); }
	Point operator - (const Point& u) { return Point(x - u.x, y - u.y); }
	Point operator * (const double u) { return Point(x * u, y * u); }
	Point operator / (const double u) { return Point(x / u, y / u); }
	double operator ^ (const Point& u) { return x*u.y - y*u.x; }
};
typedef Point Vector;
typedef vector<Point> Polygon;

struct Line {
	double a, b, c;
	Line(double a = 0, double b = 0, double c = 0) : a(a), b(b), c(c) {}
};

struct DirLine {
	Point p;
	Vector v;
	double ang;
	DirLine() {}
	DirLine(Point p, Vector v) : p(p), v(v) { ang = atan2(v.y, v.x); }
	bool operator < (const DirLine& u) const { return ang < u.ang; }
};

struct Circle {
	Point o;
	double r;
	Circle() {}
	Circle(Point o, double r = 0) : o(o), r(r) {}
	void read() { o.read(), scanf("%lf", &r); }
	Point point(double rad) { return Point(o.x + cos(rad)*r, o.y + sin(rad)*r); }
	double getArea(double rad) { return rad * r * r / 2; }
};


namespace Punctual {
	double getDistance(Point a, Point b) { double x = a.x - b.x, y = a.y - b.y; return sqrt(x*x + y*y); }
};


namespace Vectorial {
	
	long double getDot(Vector a, Vector b) { return (long double) a.x * b.x + (long double)a.y * b.y; }

	
	double getCross(Vector a, Vector b) { return a.x * b.y - a.y * b.x; }

	long double getLength(Vector a) { return sqrtl(getDot(a, a)); }
	long double getPLength(Vector a) { return getDot(a, a); }
	double getAngle(Vector u) { return atan2(u.y, u.x); }
	double getAngle(Vector a, Vector b) { return acos(getDot(a, b) / getLength(a) / getLength(b)); }
	Vector rotate(Vector a, double rad) { return Vector(a.x*cos(rad) - a.y*sin(rad), a.x*sin(rad) + a.y*cos(rad)); }
	
	Vector getNormal(Vector a) { double l = getLength(a); return Vector(-a.y / l, a.x / l); }
};

namespace ComplexVector {
	typedef complex<double> Point;
	typedef Point Vector;

	double getDot(Vector a, Vector b) { return real(conj(a)*b); }
	double getCross(Vector a, Vector b) { return imag(conj(a)*b); }
	Vector rotate(Vector a, double rad) { return a*exp(Point(0, rad)); }
};

namespace Linear {
	using namespace Vectorial;

	Line getLine(double x1, double y1, double x2, double y2) { return Line(y2 - y1, x1 - x2, y1*x2 - x1*y2); }
	Line getLine(double a, double b, Point u) { return Line(a, -b, u.y * b - u.x * a); }

	bool getIntersection(Line p, Line q, Point& o) {
		if (fabs(p.a * q.b - q.a * p.b) < eps)
			return false;
		o.x = (q.c * p.b - p.c * q.b) / (p.a * q.b - q.a * p.b);
		o.y = (q.c * p.a - p.c * q.a) / (p.b * q.a - q.b * p.a);
		return true;
	}

	
	bool getIntersection(Point p, Vector v, Point q, Vector w, Point& o) {
		if (dcmp(getCross(v, w)) == 0) return false;
		Vector u = p - q;
		double k = getCross(w, u) / getCross(v, w);
		o = p + v * k;
		return true;
	}

	
	double getDistanceToLine(Point p, Point a, Point b) { return fabs(getCross(b - a, p - a) / getLength(b - a)); }
	double getDistanceToSegment(Point p, Point a, Point b) {
		if (a == b) return getLength(p - a);
		Vector v1 = b - a, v2 = p - a, v3 = p - b;
		if (dcmp(getDot(v1, v2)) < 0) return getLength(v2);
		else if (dcmp(getDot(v1, v3)) > 0) return getLength(v3);
		else return fabs(getCross(v1, v2) / getLength(v1));
	}

	
	Point getPointToLine(Point p, Point a, Point b) { Vector v = b - a; return a + v*(getDot(v, p - a) / getDot(v, v)); }

	
	bool haveIntersection(Point a1, Point a2, Point b1, Point b2) {
		double c1 = getCross(a2 - a1, b1 - a1), c2 = getCross(a2 - a1, b2 - a1), c3 = getCross(b2 - b1, a1 - b1), c4 = getCross(b2 - b1, a2 - b1);
		return dcmp(c1)*dcmp(c2) < 0 && dcmp(c3)*dcmp(c4) < 0;
	}

	
	bool onSegment(Point p, Point a, Point b) { return dcmp(getCross(a - p, b - p)) == 0 && dcmp(getDot(a - p, b - p)) < 0; }
	bool onLeft(DirLine l, Point p) { return dcmp(l.v ^ (p - l.p)) >= 0; }
}

namespace Triangular {
	using namespace Vectorial;

	double getAngle(double a, double b, double c) { return acos((a*a + b*b - c*c) / (2 * a*b)); }
	double getArea(double a, double b, double c) { double s = (a + b + c) / 2; return sqrt(s*(s - a)*(s - b)*(s - c)); }
	double getArea(double a, double h) { return a * h / 2; }
	double getArea(Point a, Point b, Point c) { return fabs(getCross(b - a, c - a)) / 2; }
	double getDirArea(Point a, Point b, Point c) { return getCross(b - a, c - a) / 2; }
};

namespace Polygonal {
	using namespace Vectorial;
	using namespace Linear;

	double getArea(Point* p, int n) {
		double ret = 0;
		for (int i = 0; i < n - 1; i++)
			ret += (p[i] - p[0]) ^ (p[i + 1] - p[0]);
		return ret / 2;
	}

	
	int getConvexHull(Point* p, int n, Point* ch) {
		sort(p, p + n);
		int m = 0;
		for (int i = 0; i < n; i++) {
			
			

			while (m > 1 && dcmp(getCross(ch[m - 1] - ch[m - 2], p[i] - ch[m - 1])) <= 0) m--;
			ch[m++] = p[i];
		}
		int k = m;
		for (int i = n - 2; i >= 0; i--) {
			
			

			while (m > k && dcmp(getCross(ch[m - 1] - ch[m - 2], p[i] - ch[m - 2])) <= 0) m--;
			ch[m++] = p[i];
		}
		if (n > 1) m--;
		return m;
	}

	int isPointInPolygon(Point o, Point* p, int n) {
		int wn = 0;
		for (int i = 0; i < n; i++) {
			int j = (i + 1) % n;
			if (onSegment(o, p[i], p[j]) || o == p[i]) return 0; 

			int k = dcmp(getCross(p[j] - p[i], o - p[i]));
			int d1 = dcmp(p[i].y - o.y);
			int d2 = dcmp(p[j].y - o.y);
			if (k > 0 && d1 <= 0 && d2 > 0) wn++;
			if (k < 0 && d2 <= 0 && d1 > 0) wn--;
		}
		return wn ? -1 : 1;
	}

	
	void rotatingCalipers(Point *p, int n, vector<pii>& sol) {
		sol.clear();
		int j = 1; p[n] = p[0];
		for (int i = 0; i < n; i++) {
			while (getCross(p[j + 1] - p[i + 1], p[i] - p[i + 1]) > getCross(p[j] - p[i + 1], p[i] - p[i + 1]))
				j = (j + 1) % n;
			sol.push_back(make_pair(i, j));
			sol.push_back(make_pair(i + 1, j + 1));
		}
	}

	void rotatingCalipersGetRectangle(Point *p, int n, double& area, double& perimeter) {
		p[n] = p[0];
		int l = 1, r = 1, j = 1;
		area = perimeter = 1e20;

		for (int i = 0; i < n; i++) {
			Vector v = (p[i + 1] - p[i]) / getLength(p[i + 1] - p[i]);
			while (dcmp(getDot(v, p[r%n] - p[i]) - getDot(v, p[(r + 1) % n] - p[i])) < 0) r++;
			while (j < r || dcmp(getCross(v, p[j%n] - p[i]) - getCross(v, p[(j + 1) % n] - p[i])) < 0) j++;
			while (l < j || dcmp(getDot(v, p[l%n] - p[i]) - getDot(v, p[(l + 1) % n] - p[i])) > 0) l++;
			double w = getDot(v, p[r%n] - p[i]) - getDot(v, p[l%n] - p[i]);
			double h = getDistanceToLine(p[j%n], p[i], p[i + 1]);
			area = min(area, w * h);
			perimeter = min(perimeter, 2 * w + 2 * h);
		}
	}

	
	
	Polygon cutPolygon(Polygon u, Point a, Point b) {
		Polygon ret;
		int n = u.size();
		for (int i = 0; i < n; i++) {
			Point c = u[i], d = u[(i + 1) % n];
			if (dcmp((b - a) ^ (c - a)) >= 0) ret.push_back(c);
			if (dcmp((b - a) ^ (c - d)) != 0) {
				Point t;
				getIntersection(a, b - a, c, d - c, t);
				if (onSegment(t, c, d))
					ret.push_back(t);
			}
		}
		return ret;
	}

	
	int halfPlaneIntersection(DirLine* li, int n, Point* poly) {
		sort(li, li + n);

		int first, last;
		Point* p = new Point[n];
		DirLine* q = new DirLine[n];
		q[first = last = 0] = li[0];

		for (int i = 1; i < n; i++) {
			while (first < last && !onLeft(li[i], p[last - 1])) last--;
			while (first < last && !onLeft(li[i], p[first])) first++;
			q[++last] = li[i];

			if (dcmp(q[last].v ^ q[last - 1].v) == 0) {
				last--;
				if (onLeft(q[last], li[i].p)) q[last] = li[i];
			}

			if (first < last)
				getIntersection(q[last - 1].p, q[last - 1].v, q[last].p, q[last].v, p[last - 1]);
		}

		while (first < last && !onLeft(q[first], p[last - 1])) last--;
		if (last - first <= 1) { delete[] p; delete[] q; return 0; }
		getIntersection(q[last].p, q[last].v, q[first].p, q[first].v, p[last]);

		int m = 0;
		for (int i = first; i <= last; i++) poly[m++] = p[i];
		delete[] p; delete[] q;
		return m;
	}

	
	Polygon simplify(const Polygon& poly) {
		Polygon ret;
		int n = poly.size();
		for (int i = 0; i < n; i++) {
			Point a = poly[i];
			Point b = poly[(i + 1) % n];
			Point c = poly[(i + 2) % n];
			if (dcmp((b - a) ^ (c - b)) != 0 && (ret.size() == 0 || b != ret[ret.size() - 1]))
				ret.push_back(b);
		}
		return ret;
	}
};

namespace Circular {
	using namespace Linear;
	using namespace Vectorial;
	using namespace Triangular;

	
	int getLineCircleIntersection(Point p, Point q, Circle O, double& t1, double& t2, vector<Point>& sol) {
		Vector v = q - p;
		
		

		double a = v.x, b = p.x - O.o.x, c = v.y, d = p.y - O.o.y;
		double e = a*a + c*c, f = 2 * (a*b + c*d), g = b*b + d*d - O.r*O.r;
		double delta = f*f - 4 * e*g;
		if (dcmp(delta) < 0) return 0;
		if (dcmp(delta) == 0) {
			t1 = t2 = -f / (2 * e);
			sol.push_back(p + v * t1);
			return 1;
		}

		t1 = (-f - sqrt(delta)) / (2 * e); sol.push_back(p + v * t1);
		t2 = (-f + sqrt(delta)) / (2 * e); sol.push_back(p + v * t2);
		return 2;
	}

	
	int getCircleCircleIntersection(Circle o1, Circle o2, vector<Point>& sol) {
		double d = getLength(o1.o - o2.o);

		if (dcmp(d) == 0) {
			if (dcmp(o1.r - o2.r) == 0) return -1;
			return 0;
		}

		if (dcmp(o1.r + o2.r - d) < 0) return 0;
		if (dcmp(fabs(o1.r - o2.r) - d) > 0) return 0;

		double a = getAngle(o2.o - o1.o);
		double da = acos((o1.r*o1.r + d*d - o2.r*o2.r) / (2 * o1.r*d));

		Point p1 = o1.point(a - da), p2 = o1.point(a + da);

		sol.push_back(p1);
		if (p1 == p2) return 1;
		sol.push_back(p2);
		return 2;
	}

	
	int getTangents(Point p, Circle o, Vector* v) {
		Vector u = o.o - p;
		double d = getLength(u);
		if (d < o.r) return 0;
		else if (dcmp(d - o.r) == 0) {
			v[0] = rotate(u, pi / 2);
			return 1;
		}
		else {
			double ang = asin(o.r / d);
			v[0] = rotate(u, -ang);
			v[1] = rotate(u, ang);
			return 2;
		}
	}

	
	
	int getTangents(Circle o1, Circle o2, Point* a, Point* b) {
		int cnt = 0;
		if (o1.r < o2.r) { swap(o1, o2); swap(a, b); }
		double d2 = getLength(o1.o - o2.o); d2 = d2 * d2;
		double rdif = o1.r - o2.r, rsum = o1.r + o2.r;
		if (d2 < rdif * rdif) return 0;
		if (dcmp(d2) == 0 && dcmp(o1.r - o2.r) == 0) return -1;

		double base = getAngle(o2.o - o1.o);
		if (dcmp(d2 - rdif * rdif) == 0) {
			a[cnt] = o1.point(base); b[cnt] = o2.point(base); cnt++;
			return cnt;
		}

		double ang = acos(rdif / sqrt(d2));
		a[cnt] = o1.point(base + ang); b[cnt] = o2.point(base + ang); cnt++;
		a[cnt] = o1.point(base - ang); b[cnt] = o2.point(base - ang); cnt++;

		if (dcmp(d2 - rsum * rsum) == 0) {
			a[cnt] = o1.point(base); b[cnt] = o2.point(base); cnt++;
		}
		else if (d2 > rsum * rsum) {
			double ang = acos(rsum / sqrt(d2));
			a[cnt] = o1.point(base + ang); b[cnt] = o2.point(pi + base + ang); cnt++;
			a[cnt] = o1.point(base - ang); b[cnt] = o2.point(pi + base - ang); cnt++;
		}
		return cnt;
	}

	
	Circle CircumscribedCircle(Point p1, Point p2, Point p3) {
		double Bx = p2.x - p1.x, By = p2.y - p1.y;
		double Cx = p3.x - p1.x, Cy = p3.y - p1.y;
		double D = 2 * (Bx * Cy - By * Cx);
		double cx = (Cy * (Bx * Bx + By * By) - By * (Cx * Cx + Cy * Cy)) / D + p1.x;
		double cy = (Bx * (Cx * Cx + Cy * Cy) - Cx * (Bx * Bx + By * By)) / D + p1.y;
		Point p = Point(cx, cy);
		return Circle(p, getLength(p1 - p));
	}

	
	Circle InscribedCircle(Point p1, Point p2, Point p3) {
		double a = getLength(p2 - p3);
		double b = getLength(p3 - p1);
		double c = getLength(p1 - p2);
		Point p = (p1 * a + p2 * b + p3 * c) / (a + b + c);
		return Circle(p, getDistanceToLine(p, p1, p2));
	}

	
	double getPublicAreaToTriangle(Circle O, Point a, Point b) {
		if (dcmp((a - O.o) ^ (b - O.o)) == 0) return 0;
		int sig = 1;
		double da = getPLength(O.o - a), db = getPLength(O.o - b);
		if (dcmp(da - db) > 0) {
			swap(da, db);
			swap(a, b);
			sig = -1;
		}

		double t1, t2;
		vector<Point> sol;
		int n = getLineCircleIntersection(a, b, O, t1, t2, sol);

		if (dcmp(da - O.r*O.r) <= 0) {
			if (dcmp(db - O.r*O.r) <= 0)  return getDirArea(O.o, a, b) * sig;

			int k = 0;
			if (getPLength(sol[0] - b) > getPLength(sol[1] - b)) k = 1;

			double ret = getArea(O.o, a, sol[k]) + O.getArea(getAngle(sol[k] - O.o, b - O.o));
			double tmp = (a - O.o) ^ (b - O.o);
			return ret * sig * dcmp(tmp);
		}

		double d = getDistanceToSegment(O.o, a, b);
		if (dcmp(d - O.r) >= 0) {
			double ret = O.getArea(getAngle(a - O.o, b - O.o));
			double tmp = (a - O.o) ^ (b - O.o);
			return ret * sig * dcmp(tmp);
		}


		double k1 = O.r / getLength(a - O.o), k2 = O.r / getLength(b - O.o);
		Point p = O.o + (a - O.o) * k1, q = O.o + (b - O.o) * k2;
		double ret1 = O.getArea(getAngle(p - O.o, q - O.o));
		double ret2 = O.getArea(getAngle(sol[0] - O.o, sol[1] - O.o)) - getArea(O.o, sol[0], sol[1]);
		double ret = (ret1 - ret2), tmp = (a - O.o) ^ (b - O.o);
		return ret * sig * dcmp(tmp);
	}

	double getPublicAreaToPolygon(Circle O, Point* p, int n) {
		if (dcmp(O.r) == 0) return 0;
		double area = 0;
		for (int i = 0; i < n; i++) {
			int u = (i + 1) % n;
			area += getPublicAreaToTriangle(O, p[i], p[u]);
		}
		return fabs(area);
	}
};

using namespace Polygonal;
const int maxn = 105;

int N, M;
double X[maxn], Y[maxn], PX[maxn], PY[maxn];

void init() {
	double x, y;
	scanf("%d%d", &N, &M);
	for (int i = 1; i <= N; i++) {
		X[i] = Y[i] = PX[i] = PY[i] = 0;
		for (int j = 1; j <= M; j++) {
			scanf("%lf%lf", &x, &y);
			X[i] += x, Y[i] += y;
			PX[i] += x*x, PY[i] += y*y;
		}
	}
}

int gatr[40010];    

int find(int x)
{
	if (gatr[x] == x)
		return x;
	gatr[x] = find(gatr[x]);
	return gatr[x];
}
void merge(int a, int b)
{
	int fa = find(a);
	int fb = find(b);
	if (fa != fb)
	{
		gatr[fb] = fa;
	}
}





int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.precision(10);
	cout << fixed;
	double x1, y1, x2, y2;
	double v, t;
	double vx, vy, wx, wy;
	cin >> x1 >> y1 >> x2 >> y2 >> v >> t >> vx >> vy >> wx >> wy;
	long double l = 0.0, r = 1e9;
	while (r - l >= 1e-9)
	{
		long double mid = 0.5 * (l + r);
		long double x = x1 + min(mid, (long double)t) * vx + max((long double)0.0, (long double)mid - t) * wx;
		LD y = y1 + min(mid, (long double)t) * vy + max((long double)0.0, (long double)mid - t) * wy;
		(hypotl(x - x2, y - y2) < mid * v ? r : l) = mid;
	}
	cout << l << endl;
	return 0;
}

 				    	   	  	 		  		    			