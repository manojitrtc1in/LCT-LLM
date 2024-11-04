
using namespace std;
typedef int DB;
typedef long long ll;
const int maxn = 200010;
const DB PI = acos(double(-1));
const DB INF = 1e9;
const DB EPS = 0;

inline ll sqr(const DB &v) { return 1LL * v * v; }
inline int sgn(const ll &v) { return v < -EPS ? -1 : v > EPS; }

struct PT
{
	DB x, y;
	PT(DB x = 0, DB y = 0) : x(x), y(y) {}
	PT operator+(const PT &d) const { return PT(x + d.x, y + d.y); }
	PT& operator+=(const PT &d) { x += d.x, y += d.y; return *this; }
	PT operator-(const PT &d) const { return PT(x - d.x, y - d.y); }
	PT& operator-=(const PT &d) { x -= d.x, y -= d.y; return *this; }
	friend PT operator-(const PT &p) { return PT(-p.x, -p.y); }
	PT operator*(const DB &c) const { return PT(x * c, y * c); }
	friend PT operator*(const DB &c, const PT &p) { return p * c; }
	PT& operator*=(const DB &c) { x *= c, y *= c; return *this; }
	PT operator/(const DB &c) const { return PT(x / c, y / c); }
	PT& operator/=(const DB &c) { x /= c, y /= c; return *this; }
	bool operator<(const PT &o) const { return sgn(x - o.x) ? sgn(x - o.x) < 0 : sgn(y - o.y) < 0; }
	bool operator==(const PT &o) const { return !sgn(x - o.x) && !sgn(y - o.y); }
	bool operator!=(const PT &o) const { return sgn(x - o.x) || sgn(y - o.y); }
}pt[maxn], qt[maxn], cpt[maxn], cqt[maxn];

DB norm(const PT &v) { return sqrt(sqr(v.x) + sqr(v.y)); }
ll norm2(const PT &v) { return sqr(v.x) + sqr(v.y); }
DB norm(const PT &p1, const PT &p2) { return norm(p1 - p2); }
ll norm2(const PT &p1, const PT &p2) { return norm2(p1 - p2); }

ll vect(const PT &v1, const PT &v2) { return 1LL * v1.x * v2.y - 1LL * v2.x * v1.y; }
ll vect(const PT &p, const PT &p1, const PT &p2) { return vect(p1 - p, p2 - p); }
ll scal(const PT &v1, const PT &v2) { return 1LL * v1.x * v2.x + 1LL * v1.y * v2.y; }
ll scal(const PT &p, const PT &p1, const PT &p2) { return scal(p1 - p, p2 - p); }

int sect(const PT &p)
{
	if (sgn(p.x) == 0 && sgn(p.y) == 0) return 0;
	if (sgn(p.x) == 0) return sgn(p.y) > 0 ? 2 : 4;
	if (sgn(p.y) == 0) return sgn(p.x) > 0 ? 1 : 3;
	if (sgn(p.x) == 1) return sgn(p.y) == 1 ? 1 : 4;
	return sgn(p.y) == 1 ? 2 : 3;
}

DB ang(const PT &v) { return atan2(v.y, v.x); }
DB ang(const PT &o, const PT &p) { return ang(p - o); }
DB ang(const PT &p, const PT &p1, const PT &p2)
{
	DB dy = vect(p, p1, p2);
	DB dx = scal(p, p1, p2);
	if (!sgn(dy)) dy = 0;
	if (!sgn(dx)) dx = 0;
	return atan2(dy, dx);
}
DB ang2(const PT &p, const PT &p1, const PT &p2) { return acos(scal(p, p1, p2) / norm(p, p1) / norm(p, p2)); }

PT proj(const PT &p, const PT &p1, const PT &p2) { return p1 + (p2 - p1) * scal(p1, p, p2) / norm2(p1, p2); }
PT rot(const PT &v, const DB &t) { return PT(v.x * cos(t) - v.y * sin(t), v.x * sin(t) + v.y * cos(t)); }
PT rot(const PT &p, const PT &o, const DB &t) { return rot(p - o, t) + o; }
PT polar(const PT &o, const DB &r, const DB &t) { return o + r * PT(cos(t), sin(t)); }

PT normalVector(const PT &v) { return PT(-v.y, v.x); }
PT normalVector(const PT &p1, const PT &p2) { return normalVector(p2 - p1); }

void makeLine(const DB &a, const DB &b, const DB &c, PT &p1, PT &p2)
{
	if(sgn(a)) p1 = PT(-c / a, 0);
	else p1 = PT(0, -c / b);
	p2 = p1 + PT(b, -a);
}

DB id2(const PT &p, const PT &p1, const PT &p2) { return fabs(vect(p, p1, p2)) / norm(p1, p2); }
DB id8(const PT &p, const PT &p1, const PT &p2) {
	if (sgn(scal(p1, p, p2)) < 0) return norm(p, p1);
	if (sgn(scal(p2, p, p1)) < 0) return norm(p, p2);
	return id2(p, p1, p2);
}

bool onLine(const PT &p, const PT &p1, const PT &p2) { return !sgn(vect(p, p1, p2)); }
bool onSeg(const PT &p, const PT &p1, const PT &p2) { return onLine(p, p1, p2) && sgn(scal(p, p1, p2)) <= 0; }
bool inAngle(const PT &p, const PT &p0, const PT &p1, const PT &p2)
{
	DB d0 = vect(p0, p1, p2);
	DB d1 = vect(p0, p1, p);
	DB d2 = vect(p0, p2, p);
	if (sgn(d0) >= 0) return sgn(d1) >= 0 && sgn(d2) <= 0;
	return sgn(d1) >= 0 || sgn(d2) <= 0;
}
int id13(const PT &p, const PT q[], int n)
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
	if (!sgn(s1 - s2)) return !sgn(s1) ? 1 : 2;
	p = p3 - (p4 - p3) * s1 / (s2 - s1);
	return 0;
}

int id0(const PT &p1, const PT &p2, const PT &p3, const PT &p4, PT &p)
{
	

	int ret = id6(p1, p2, p3, p4, p);
	if (ret == 0 && (onSeg(p, p1, p2) && onSeg(p, p3, p4))) return 0;
	if (ret == 1 && (onSeg(p1, p3, p4) || onSeg(p2, p3, p4))) return 1;
	return 2;
}

int inPolygon(const PT &p, const PT q[], int n)
{
	

	int c = 0;
	PT r = PT(INF, INF * sqrt(3)), t;
	for (int i = 0; i < n; ++i) {
		if (onLine(p, q[i], q[(i + 1) % n])) return 2;
		if (!id0(p, r, q[i], q[(i + 1) % n], t)) ++c;
	}
	return c % 2;
}

int id7(const PT &o, const DB &r, const PT &p1, const PT &p2, PT q[] = NULL)
{
	DB a = norm2(p1, p2);
	DB b = scal(p1, o, p2);
	DB c = norm2(o, p1) - sqr(r);
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
	DB d = norm(o1, o2);
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

PT innerCenter(const PT &a, const PT &b, const PT &c)
{
	DB A = norm(b, c);
	DB B = norm(c, a);
	DB C = norm(a, b);
	return PT((A * a.x + B * b.x + C * c.x) / (A + B + C), (A * a.y + B * b.y + C * c.y) / (A + B + C));
}
PT outerCenter(const PT &a, const PT &b, const PT &c)
{
	DB d1 = (norm2(a) - norm2(b)) / 2;
	DB d2 = (norm2(a) - norm2(c)) / 2;
	DB x = (d1 * (a.y - c.y) - d2 * (a.y - b.y)) / vect(a - b, a - c);
	DB y = (d1 * (a.x - c.x) - d2 * (a.x - b.x)) / vect(a - c, a - b);
	return PT(x, y);
}
PT gravityCenter(const PT p[], int n)
{
	PT o;
	for (int i = 0; i < n; ++i)
		o += p[i];
	return o / n;
}

DB id10(const PT &p1, const DB &r1, const PT &p2, const DB &r2)
{
	DB d = norm(p1 - p2);
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

DB id11(const PT p[], int n)
{
	DB S = 0;
	for (int i = 0; i < n; ++i) S += vect(p[i], p[(i + 1) % n]);
	return fabs(S) / 2;
}

int id9(const PT p[], int n, const PT &s, const PT &e, PT q[])
{
	int m = 0;
	for (int i = 0; i < n; ++i) {
		if (sgn(vect(s, e, p[i])) > 0) q[m++] = p[i];
		int lf = id6(s, e, p[i], p[(i + 1) % n], q[m]);
		if (!lf && onSeg(q[m], p[i], p[(i + 1) % n]) && q[m] != p[(i + 1) % n]) ++m;
		else if (lf == 1) q[m++] = p[i];
	}
	return m;
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
		int s1 = sect(e - s), s2 = sect(o.e - o.s);
		if (s1 != s2) return s1 < s2;
		int f = sgn(vect(e - s, o.e - o.s));
		return f ? f > 0 : o.contain(s);
	}
	bool operator==(const HP &o) const
	{
		return sect(e - s) == sect(o.e - o.s) && sgn(vect(e - s, o.e - o.s)) == 0;
	}
	int contain(const PT &p) const { return sgn(vect(s, e, p)) > 0; }
};

int id4(HP h[], int n)
{
	auto intersection = [](const HP &h1, const HP &h2)
	{
		PT ret;
		id6(h1.s, h1.e, h2.s, h2.e, ret);
		return ret;
	};
	h[n++] = HP(PT(0, 0), PT(INF, 0));
	h[n++] = HP(PT(INF, 0), PT(INF, INF));
	h[n++] = HP(PT(INF, INF), PT(0, INF));
	h[n++] = HP(PT(0, INF), PT(0, 0));
	sort(h, h + n), n = unique(h, h + n) - h;
	int l = 0, r = 0;
	for (int i = 0; i < n; ++i) {
		for (; r - l >= 2 && !h[i].contain(intersection(h[r - 2], h[r - 1])); --r);
		for (; r - l >= 2 && !h[i].contain(intersection(h[l], h[l + 1])); ++l);
		if (r - l < 2 || h[l].contain(intersection(h[r - 1], h[i]))) h[r++] = h[i];
	}
	for (int i = l; i < r; ++i) h[i - l] = h[i];
	return r - l;
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
	bool operator!=(const PT3 &o) const { return sgn(x - o.x) || sgn(y - o.y) || sgn(z - o.z); }
};

DB norm(const PT3 &v) { return sqrt(sqr(v.x) + sqr(v.y) + sqr(v.z)); }
DB norm2(const PT3 &v) { return sqr(v.x) + sqr(v.y) + sqr(v.z); }
DB norm(const PT3 &p1, const PT3 &p2) { return norm(p1 - p2); }
DB norm2(const PT3 &p1, const PT3 &p2) { return norm2(p1 - p2); }

PT3 vect(const PT3 &v1, const PT3 &v2) { return PT3(v1.y * v2.z - v2.y * v1.z, -(v1.x * v2.z - v2.x * v1.z), v1.x * v2.y - v2.x * v1.y); }
PT3 vect(const PT3 &p, const PT3 &p1, const PT3 &p2) { return vect(p1 - p, p2 - p); }
DB scal(const PT3 &v1, const PT3 &v2) { return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z; }
DB scal(const PT3 &p, const PT3 &p1, const PT3 &p2) { return scal(p1 - p, p2 - p); }

PT3 normalVector(const PT3 &v1, const PT3 &v2) { return vect(v1, v2); }
PT3 normalVector(const PT3 &p1, const PT3 &p2, const PT3 & p3) { return normalVector(p2 - p1, p3 - p1); }

DB id12(const PT3 &p, const DB &a, const DB &b, const DB &c, const DB &d) { return fabs(a * p.x + b * p.y + c * p.z + d) / sqrt(sqr(a) + sqr(b) + sqr(c)); }

void makePlane(const PT3 &p1, const PT3 &p2, const PT3 &p3, DB &a, DB &b, DB &c, DB &d)
{
	PT3 q = vect(p1, p2, p3);
	a = q.x, b = q.y, c = q.z;
	d = -(a * p1.x + b * p1.y + c * p1.z);
}

DB id11(const PT3 p[], int n)
{
	PT3 sv;
	for (int i = 0; i < n; ++i)
		sv += vect(p[i], p[(i + 1) % n]);
	PT3 nv = normalVector(p[0], p[1], p[2]);
	nv /= norm(nv);
	return fabs(scal(nv, sv)) / 2;
}


ll d1[maxn], d2[maxn];
ll d3[maxn], d4[maxn];
int save1[maxn], save2[maxn];

ll pi[maxn];

void calc_pi(ll *pat, int pn) {
	int q;
	pi[1] = q = 0;
	for(int i = 1; i < pn; i++) {
		for(; q && pat[i] != pat[q]; q = pi[q]);
		
		if(pat[i] == pat[q]) q++;
		pi[i + 1] = q;
	}
}
int KMP(ll *pat, int pn, ll *txt, int tn, int* save) {
	calc_pi(pat, pn);
	int q = 0;
	int ind = 0;
	for(int i = 0; i < tn; i++) {
		for(; q & txt[i] != pat[q]; q = pi[q]);
		if(txt[i] == pat[q]) q++;
		if(q == pn) {
			q = pi[q];
			save[ind++] = i;
		}
	}
	return ind;
}



int main(){
	ios_base :: sync_with_stdio(0);
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < n; i++)
		cin >> pt[i].x >> pt[i].y;
	for(int i = 0; i < m; i++)
		cin >> qt[i].x >> qt[i].y;
	n = id5(pt, n, cpt);
	m = id5(qt, m, cqt);
	for(int i = 0; i < n; i++)
		d1[i] = norm2(cpt[i], cpt[(i + 1) % n]);
	for(int i = n; i < 2 * n; i++)
		d1[i] = d1[i - n];
	for(int i = 0; i < m; i++)
		d2[i] = norm2(cqt[i], cqt[(i + 1) % n]);
	for(int i = 0; i < n; i++)
		d3[i] = scal(cpt[i], cpt[(i - 1 + n) % n], cpt[(i + 1) % n]);
	for(int i = n; i < 2 * n; i++)
		d3[i] = d3[i - n];
	for(int i = 0; i < m; i++)
		d4[i] = scal(cqt[i], cqt[(i - 1 + n) % n], cqt[(i + 1) % n]);
	if(n != m)
		cout << "NO" << endl;
	else{
		int sz1 = KMP(d2, m, d1, 2 * n, save1);
		int sz2 = KMP(d4, m, d3, 2 * n, save2);
		int flag = 0;
		for(int i = 0; i < sz1; i++){
			int id = lower_bound(save2, save2 + sz2, save1[i]) - save2;
			if(save2[id] == save1[i]){
				flag = 1;
				break;
			}
		}
		if(flag)
			puts("YES");
		else
			puts("NO");
	}
	return 0;
}
