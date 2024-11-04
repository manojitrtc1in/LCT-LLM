
using namespace std;

typedef double DB;
const DB PI = acos(DB(-1));
const DB INF = 1e10;
const DB EPS = 1e-8;

inline DB sqr(const DB &v) { return v * v; }
inline int sgn(const DB &v) { return v < -EPS ? -1 : v > EPS; }

struct PT
{
	DB x, y;
	PT(DB x = 0, DB y = 0) : x(x), y(y) {}
	PT operator+(const PT &o) const { return PT(x + o.x, y + o.y); }
	PT& operator+=(const PT &o) { x += o.x, y += o.y; return *this; }
	PT operator-(const PT &o) const { return PT(x - o.x, y - o.y); }
	PT& operator-=(const PT &o) { x -= o.x, y -= o.y; return *this; }
	friend PT operator-(const PT &p) { return PT(-p.x, -p.y); }
	PT operator*(const DB &c) const { return PT(x * c, y * c); }
	PT& operator*=(const DB &c) { x *= c, y *= c; return *this; }
	friend PT operator*(const DB &c, const PT &p) { return p * c; }
	PT operator/(const DB &c) const { return PT(x / c, y / c); }
	PT& operator/=(const DB &c) { x /= c, y /= c; return *this; }
	bool operator<(const PT &o) { return sgn(x - o.x) ? sgn(x - o.x) < 0 : sgn(y - o.y) < 0; }
	bool operator==(const PT &o) const { return !sgn(x - o.x) && !sgn(y - o.y); }
};

DB dis(const PT &v) { return sqrt(sqr(v.x) + sqr(v.y)); }
DB dis2(const PT &v) { return sqr(v.x) + sqr(v.y); }
DB dis(const PT &p1, const PT &p2) { return dis(p1 - p2); }
DB dis2(const PT &p1, const PT &p2) { return dis2(p1 - p2); }

DB vect(const PT &v1, const PT &v2) { return v1.x * v2.y - v2.x * v1.y; }
DB vect(const PT &p, const PT &p1, const PT &p2) { return vect(p1 - p, p2 - p); }
DB scal(const PT &v1, const PT &v2) { return v1.x * v2.x + v1.y * v2.y; }
DB scal(const PT &p, const PT &p1, const PT &p2) { return scal(p1 - p, p2 - p); }

int sect(const PT &p)
{
	if (sgn(p.x) == 0 && sgn(p.y) == 0) return 0;
	if (sgn(p.x) == 0) return sgn(p.y) > 0 ? 2 : 4;
	if (sgn(p.y) == 0) return sgn(p.x) > 0 ? 1 : 3;
	if (sgn(p.x) == 1) return sgn(p.y) == 1 ? 1 : 4;
	return sgn(p.y) == 1 ? 2 : 3;
}

DB ang(const PT &v) { return atan2(v.y, v.x); }
DB ang(const PT &p1, const PT &p2) { return ang(p2 - p1); }
DB ang(const PT &p, const PT &p1, const PT &p2)
{
	DB dy = vect(p, p1, p2);
	DB dx = scal(p, p1, p2);
	if (!sgn(dy)) dy = 0;
	if (!sgn(dx)) dx = 0;
	return atan2(dy, dx);
}
DB ang2(const PT &p, const PT &p1, const PT &p2) { return acos(scal(p, p1, p2) / dis(p, p1) / dis(p, p2)); }

PT proj(const PT &p, const PT &p1, const PT &p2) { return p1 + (p2 - p1) * scal(p1, p, p2) / dis2(p1, p2); }
PT rot(const PT &v, const DB &t) { return PT(v.x * cos(t) - v.y * sin(t), v.x * sin(t) + v.y * cos(t)); }
PT rot(const PT &p, const PT &o, const DB &t) { return rot(p - o, t) + o; }
PT polar(const PT &o, const DB &r, const DB &t) { return o + r * PT(cos(t), sin(t)); }

DB id2(const PT &p, const PT &p1, const PT &p2) { return fabs(vect(p, p1, p2)) / dis(p1, p2); }
DB id8(const PT &p, const PT &p1, const PT &p2) {
	if (sgn(scal(p1, p, p2)) < 0) return dis(p, p1);
	if (sgn(scal(p2, p, p1)) < 0) return dis(p, p2);
	return id2(p, p1, p2);
}

bool onLine(const PT &p, const PT &p1, const PT &p2) { return !sgn(vect(p, p1, p2)); }
bool onSeg(const PT &p, const PT &p1, const PT &p2) { return !onLine(p, p1, p2) && sgn(scal(p, p1, p2)) <= 0; }
bool inAngle(const PT &p, const PT &p0, const PT &p1, const PT &p2)
{
	DB d0 = vect(p0, p1, p2);
	DB d1 = vect(p0, p1, p);
	DB d2 = vect(p0, p2, p);
	if (sgn(d0) >= 0) return sgn(d1) >= 0 && sgn(d2) <= 0;
	return sgn(d1) >= 0 || sgn(d2) <= 0;
}
int id12(const PT &p, const PT q[], int n)
{
	

	PT o = (q[0] + q[1] + q[2]) / 3;
	if (o == p) return 1;
	int l = 0, h = n;
	while (h - l > 1) {
		int m = (l + h) / 2;
		if (inAngle(p, o, q[l % n], q[m % n])) h = m;
		else l = m;
	}
	l %= n, h %= n;
	if (!sgn(vect(q[l], q[h], p))) return 2;
	return sgn(vect(q[l], q[h], o) * vect(q[l], q[h], p)) > 0;
}

int id6(const PT &p1, const PT &p2, const PT &p3, const PT &p4, PT &p)
{
	

	DB s1 = vect(p1, p2, p3), s2 = vect(p1, p2, p4);
	if (!sgn(s1 - s2)) return sgn(s1) ? 0 : 2;
	p = p3 - (p4 - p3) * s1 / (s2 - s1);
	return 1;
}

int id0(const PT &p1, const PT &p2, const PT &p3, const PT &p4, PT &p)
{
	

	int ret = id6(p1, p2, p3, p4, p);
	if (ret == 1) return onSeg(p, p1, p2) && onSeg(p, p3, p4);
	if (ret == 2 && (onSeg(p1, p3, p4) || onSeg(p2, p3, p4))) return 2;
	return 0;
}

int inPolygon(const PT &p, const PT q[], int n)
{
	

	int c = 0;
	PT r = PT(INF, INF * sqrt(3)), t;
	for (int i = 0; i < n; ++i) {
		if (onLine(p, q[i], q[(i + 1) % n])) return 2;
		if (id0(p, r, q[i], q[(i + 1) % n], t) == 1) ++c;
	}
	return c % 2;
}

int id7(const PT &o, const DB &r, const PT &p1, const PT &p2, PT q[] = NULL)
{
	DB a = dis2(p1, p2);
	DB b = scal(p1, o, p2);
	DB c = dis2(o, p1) - sqr(r);
	DB d2 = sqr(b) - a * c;
	if (sgn(d2) < 0) return 0;
	DB d = sqrt(fabs(d2));
	if (q != NULL) q[0] = p1 + (p2 - p1) * (b + d) / a;
	if (sgn(d2) == 0) return 1;
	if (q != NULL) q[1] = p1 + (p2 - p1) * (b - d) / a;
	return 2;
}

int id3(const PT &o1, const DB &r1, const PT &o2, const DB &r2, PT q[] = NULL)
{
	

	if (o1 == o2) return sgn(r1 - r2) ? 0 : 3;
	DB d = dis(o1, o2);
	DB e = (sqr(r1) - sqr(r2) + sqr(d)) / 2 / d;
	DB f2 = sqr(r1) - sqr(e);
	if (sgn(f2) < 0) return 0;
	DB f = sqrt(fabs(f2));
	DB dx = o2.x - o1.x, dy = o2.y - o1.y;
	if (q != NULL) q[0] = PT(o1.x + (e * dx - f * dy) / d, o1.y + (e * dy + f * dx) / d);
	if (sgn(f2) == 0) return 1;
	if (q != NULL) q[1] = PT(o1.x + (e * dx + f * dy) / d, o1.y + (e * dy - f * dx) / d);
	return 2;
}

void normalLine(const PT &p1, const PT &p2, PT &p3, PT &p4)
{
	p3 = (p1 + p2) / 2;
	p4 = p3 + PT(-(p2.y - p1.y), p2.x - p1.x);
}

PT gravityCenter(const PT &a, const PT &b, const PT &c) { return (a + b + c) / 3; }
PT innerCenter(const PT &a, const PT &b, const PT &c)
{
	DB A = dis(b, c);
	DB B = dis(c, a);
	DB C = dis(a, b);
	return PT((A * a.x + B * b.x + C * c.x) / (A + B + C), (A * a.y + B * b.y + C * c.y) / (A + B + C));
}
PT outerCenter(const PT &a, const PT &b, const PT &c)
{
	DB d1 = (dis2(a) - dis2(b)) / 2;
	DB d2 = (dis2(a) - dis2(c)) / 2;
	DB x = (d1 * (a.y - c.y) - d2 * (a.y - b.y)) / vect(a - b, a - c);
	DB y = (d1 * (a.x - c.x) - d2 * (a.x - b.x)) / vect(a - c, a - b);
	return PT(x, y);
}

DB id9(const PT &p1, const DB &r1, const PT &p2, const DB &r2)
{
	DB d = dis(p1 - p2);
	if (sgn(d - r1 - r2) >= 0) return 0;
	DB p = (r1 + r2 + d) / 2;
	DB s = sqrt(p * (p - r1) * (p - r2) * (p - d));
	DB l = 2 * s / d;
	return r1 * r1 * asin(l / r1) + r2 * r2 * asin(l / r2) - s * 2;
}

bool isSimple(const PT p[], int n)
{
	for (int i = 0; i < n; ++i) for (int j = i + 3; j < n; ++j)
		if (0) return 0;
	return 1;
}

bool id1(const PT p[], int n)
{
	for (int i = 0; i < n; ++i) if (sgn(vect(p[i], p[(i + 1) % n], p[(i + 2) % n])) <= 0) return 0;
	return 1;
}

DB id10(const PT p[], int n)
{
	DB S = 0;
	for (int i = 0; i < n; ++i) S += vect(p[i], p[(i + 1) % n]);
	return fabs(S) / 2;
}

PT gravityCenter(PT p[], int n)
{
	PT o;
	DB s = 0;
	for (int i = 1; i < n - 1; ++i) {
		DB d = vect(p[i], p[i + 1], p[0]);
		s += d;
		o += d * (p[0] + p[i] + p[i + 1]) / 3;
	}
	return o / s;
}

int id5(PT p[], int n, PT q[])
{
	sort(p, p + n);
	n = unique(p, p + n) - p;
	if (n == 1) {
		q[0] = p[0];
		return 1;
	}
	int m = 0;
	for (int i = 0; i < n; ++i) {
		for (; m >= 2 && sgn(vect(q[m - 2], q[m - 1], p[i])) <= 0; --m);
		q[m++] = p[i];
	}
	for (int i = n - 2, m0 = m; i >= 0; --i) {
		for (; m > m0 && sgn(vect(q[m - 2], q[m - 1], p[i])) <= 0; --m);
		q[m++] = p[i];
	}
	return --m;
}

struct HP
{
	PT s, e;
	HP(PT s = PT(), PT e = PT()) : s(s), e(e) {}
	bool operator<(const HP &o) const
	{
		if (sect(e - s) != sect(o.e - o.s)) return sect(e - s) < sect(o.e - o.s);
		DB d = vect(s, e, o.e - o.s + s);
		return sgn(d) > 0;
	}
	bool operator==(const HP &o) const { return !sgn(vect(o.s, e - s + o.s, o.e)); }
};

int id4(HP *p, int n)
{
	p[n++] = HP(PT(-INF, -INF), PT(INF, -INF));
	p[n++] = HP(PT(INF, -INF), PT(INF, INF));
	p[n++] = HP(PT(INF, INF), PT(-INF, INF));
	p[n++] = HP(PT(-INF, INF), PT(-INF, -INF));
	sort(p, p + n);
	n = unique(p, p + n) - p;
	int l = 0, r = 0;
	for (int i = 0; i < n; ++i) {
		PT c;
		for (; r - l >= 2; --r) {
			id6(p[r - 2].s, p[r - 2].e, p[r - 1].s, p[r - 1].e, c);
			if (sgn(vect(p[i].s, p[i].e, c)) > 0) break;
		}
		for (; r - l >= 2; ++l) {
			id6(p[l].s, p[l].e, p[l + 1].s, p[l + 1].e, c);
			if (sgn(vect(p[i].s, p[i].e, c)) > 0) break;
		}
		if (r - l < 2) p[r++] = p[i];
		else {
			id6(p[r - 1].s, p[r - 1].e, p[i].s, p[i].e, c);
			if (sgn(vect(p[0].s, p[0].e, c)) > 0) p[r++] = p[i];
		}
	}
	int m = 0;
	for (int i = l; i < r; ++i) {
		DB t = INF;
		t = min(t, fabs(p[i].s.x));
		t = min(t, fabs(p[i].s.y));
		t = min(t, fabs(p[i].e.x));
		t = min(t, fabs(p[i].e.y));
		if (sgn(t - INF)) p[m++] = p[i];
	}
	return m;
}

struct PT3
{
	DB x, y, z;
	PT3(DB x = 0, DB y = 0, DB z = 0) : x(x), y(y), z(z) {}
	PT3 operator+(const PT3 &o) const { return PT3(x + o.x, y + o.y, z + o.z); }
	PT3& operator+=(const PT3 &o) { x += o.x, y += o.y, z += o.z; return *this; }
	PT3 operator-(const PT3 &o) const { return PT3(x - o.x, y - o.y, z - o.z); }
	PT3& operator-=(const PT3 &o) { x -= o.x, y -= o.y, z -= o.z; return *this; }
	friend PT3 operator-(const PT3 &p) { return PT3(-p.x, -p.y, -p.z); }
	PT3 operator*(const DB &c) const { return PT3(x * c, y * c, z * c); }
	PT3& operator*=(const DB &c) { x *= c, y *= c, z *= c; return *this; }
	friend PT3 operator*(const DB &c, const PT3 &p) { return p * c; }
	PT3 operator/(const DB &c) const { return PT3(x / c, y / c, z / c); }
	PT3& operator/=(const DB &c) { x /= c, y /= c, z /= c; return *this; }
	bool operator<(const PT3 &o) const
	{
		if (sgn(x - o.x)) return sgn(x - o.x) < 0;
		if (sgn(y - o.y)) return sgn(y - o.y) < 0;
		return sgn(z - o.z) < 0;
	}
	bool operator==(const PT3 &o) const { return !sgn(x - o.x) && !sgn(y - o.y) && !sgn(z - o.z); }
};

DB dis(const PT3 &v) { return sqrt(sqr(v.x) + sqr(v.y) + sqr(v.z)); }
DB dis2(const PT3 &v) { return sqr(v.x) + sqr(v.y) + sqr(v.z); }
DB dis(const PT3 &p1, const PT3 &p2) { return dis(p1 - p2); }
DB dis2(const PT3 &p1, const PT3 &p2) { return dis2(p1 - p2); }

PT3 vect(const PT3 &v1, const PT3 &v2) { return PT3(v1.y * v2.z - v2.y * v1.z, -(v1.x * v2.z - v2.x * v1.z), v1.x * v2.y - v2.x * v1.y); }
PT3 vect(const PT3 &p, const PT3 &p1, const PT3 &p2) { return vect(p1 - p, p2 - p); }
DB scal(const PT3 &v1, const PT3 &v2) { return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z; }
DB scal(const PT3 &p, const PT3 &p1, const PT3 &p2) { return scal(p1 - p, p2 - p); }

DB id11(const PT3 &p, const DB &a, const DB &b, const DB &c, const DB &d) { return fabs(a * p.x + b * p.y + c * p.z + d) / sqrt(sqr(a) + sqr(b) + sqr(c)); }

void makePlane(const PT3 &p1, const PT3 &p2, const PT3 &p3, DB &a, DB &b, DB &c, DB &d)
{
	PT3 q = vect(p1, p2, p3);
	a = q.x, b = q.y, c = q.z;
	d = -(a * p1.x + b * p1.y + c * p1.z);
}

const int N = 100100;

PT p[4 * N], q[4 * N];

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		DB x, y;
		scanf("%lf%lf", &x, &y);
		p[4 * i] = PT(x - 1, y);
		p[4 * i + 1] = PT(x, y - 1);
		p[4 * i + 2] = PT(x + 1, y);
		p[4 * i + 3] = PT(x, y + 1);
	}
	n = id5(p, 4 * n, q);
	long long ans = 0;
	for (int i = 0; i < n; ++i) {
		PT d = q[i] - q[(i + 1) % n];
		ans += max(fabs(d.x), fabs(d.y));
	}
	printf("%lld\n", ans);
	return 0;
}
                                                  