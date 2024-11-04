
using namespace std;

typedef double DB;
const DB PI = acos(DB(-1));
const DB INF = 1e10;
const DB EPS = 1e-8;

inline DB sqr(DB x) {
	return x * x;
}

struct PT {
	DB x, y;

	PT() {}
	PT(DB x, DB y) : x(x), y(y) {}
	
	void in() {
		double _x, _y;
		scanf("%lf%lf", &_x, &_y);
		x = _x, y = _y;
	}
};

bool operator<(const PT& p1, const PT& p2) {
	if (fabs(p1.x - p2.x) > EPS) return p1.x < p2.x;
	return p1.y + EPS < p2.y;
}

bool operator==(const PT& p1, const PT& p2) {
	return fabs(p1.x - p2.x) < EPS && fabs(p1.y - p2.y) < EPS;
}

PT operator+(PT p1, PT p2) {
	return PT(p1.x + p2.x, p1.y + p2.y);
}

PT operator-(PT p1, PT p2) {
	return PT(p1.x - p2.x, p1.y - p2.y);
}

PT operator*(PT p, DB c) {
	return PT(p.x * c, p.y * c);
}

PT operator/(PT p, DB c) {
	return PT(p.x / c, p.y / c);
}

DB dis(PT p) {
	return sqrt(sqr(p.x) + sqr(p.y));
}

DB dis2(PT p) {
	return sqr(p.x) + sqr(p.y);
}

PT rot(PT p, DB t) {
	return PT(p.x * cos(t) - p.y * sin(t), p.x * sin(t) + p.y * cos(t));
}

PT polar(PT p, DB r, DB t) {
	return PT(p.x + r * cos(t), p.y + r * sin(t));
}

DB dis2(PT p1, PT p2) {
	return sqr(p1.x - p2.x) + sqr(p1.y - p2.y);
}

DB dis(PT p1, PT p2) {
	return sqrt(dis2(p1, p2));
}

DB vect(PT p1, PT p2) {
	return p1.x * p2.y - p2.x * p1.y;
}

DB scal(PT p1, PT p2) {
	return p1.x * p2.x + p1.y * p2.y;
}

DB getAngle(PT p1, PT p2) {
	return atan2(p2.y - p1.y, p2.x - p1.x);
}

DB vect(PT p, PT p1, PT p2) {
	return vect(p1 - p, p2 - p);
}

DB scal(PT p, PT p1, PT p2) {
	return scal(p1 - p, p2 - p);
}

DB getAngle(PT p, PT p1, PT p2) {
	return getAngle(p, p2) - getAngle(p, p1);
}

DB id0(PT p, PT p1, PT p2) {
	return acos(scal(p, p1, p2) / dis(p, p1) / dis(p, p2));
}

DB id1(PT p, PT p1, PT p2) {
	return fabs(vect(p, p1, p2)) / dis(p1, p2);
}

DB id7(PT p, PT p1, PT p2) {
	if (scal(p1, p, p2) < 0) return dis(p, p1);
	if (scal(p2, p, p1) < 0) return dis(p, p2);
	return id1(p, p1, p2);
}

bool onLine(PT p, PT p1, PT p2) {
	return fabs(vect(p1 - p, p2 - p)) < EPS;
}

bool onSeg(PT p, PT p1, PT p2) {
	if (!onLine(p, p1, p2)) return 0;
	return (p1.x - p.x) * (p2.x - p.x) < EPS && (p1.y - p.y) * (p2.y - p.y) < EPS;
}

bool cross(PT p1, PT p2, PT p3, PT p4) {
	return vect(p1, p2, p3) * vect(p1, p2, p4) < -EPS && vect(p3, p4, p1) * vect(p3, p4, p2) < -EPS;
}

bool common(PT p1, PT p2, PT p3, PT p4) {
	if (max(p1.x, p2.x) + EPS < min(p3.x, p4.x) || max(p3.x, p4.x) + EPS < min(p1.x, p2.x)) return 0;
	if (max(p1.y, p2.y) + EPS < min(p3.y, p4.y) || max(p3.y, p4.y) + EPS < min(p1.y, p2.y)) return 0;
	return vect(p1, p2, p3) * vect(p1, p2, p4) < EPS && vect(p3, p4, p1) * vect(p3, p4, p2) < EPS;
}

PT projection(PT a, PT b, PT p) {
	return a + (a - b) * (scal(p - a, a - b) / dis2(a - b));
}

int id4(PT p1, PT p2, PT p3, PT p4, PT& p) {
	DB s1 = vect(p1, p2, p3), s2 = vect(p1, p2, p4);
	if (fabs(s1 - s2) < EPS) {
		if (fabs(s1) < EPS) return 2;
		return 0;
	}
	p = p3 + (p4 - p3) * s1 / (s1 - s2);
	return 1;
}

int id6(PT p, DB r, PT p1, PT p2, PT *q) {
	DB a, b, c, d2, d;

	a = dis2(p1, p2);
	b = scal(p1, p, p2);
	c = dis2(p, p1) - sqr(r);
	d2 = sqr(b) - a * c;
	if (d2 < -EPS) return 0;
	d = sqrt(fabs(d2));
	q[0] = p1 + (p2 - p1) * (b + d) / a;
	if (d2 < EPS) return 1;
	q[1] = p1 + (p2 - p1) * (b - d) / a;
	return 2;
}

int id2(PT p1, DB r1, PT p2, DB r2, PT *q) {
	DB dx, dy, d, e, f2, f;

	dx = p2.x - p1.x, dy = p2.y - p1.y;
	d = dis(p1, p2);
	e = (sqr(r1) - sqr(r2) + sqr(d)) / 2 / d;
	f2 = sqr(r1) - sqr(e);
	if (f2 < -EPS) return 0;
	f = sqrt(fabs(f2));
	q[0] = PT(p1.x + (e * dx - f * dy) / d, p1.y + (e * dy + f * dx) / d);
	if (f2 < EPS) return 1;
	q[1] = PT(p1.x + (e * dx + f * dy) / d, p1.y + (e * dy - f * dx) / d);
	return 2;
}

DB calcArea(PT *p, int n) {
	DB rlt = 0;
	for (int i = 0; i < n; i++) rlt += vect(p[i], p[(i + 1) % n]);
	return rlt / 2;
}

int inPolygon(PT p, PT *q, int m) {
	PT p1, p2;
	int k = 0;
	for (int i = 0; i < m; i++) {
		p1 = q[i], p2 = q[(i + 1) % m];
		if (onSeg(p, p1, p2)) return 2;
		if (p1.y > p2.y) swap(p1, p2);
		if (p1.y < p.y + EPS && p.y + EPS < p2.y && vect(p, p1, p2) > 0) k++;
	}
	return k % 2;
}

inline int sgn(DB a) { return a > EPS ? 1 : a < -EPS ? -1 : 0; }

bool id9(PT *p, int n, PT q) {

	bool ccw = vect(p[1] - p[0], p[2] - p[1]) > EPS;
	int below = sgn(vect(q - p[0], p[n - 1] - p[0]));
	if (ccw && below < 0) return 0;
	if (!ccw && below > 0) return 0;
	int lo = 0, hi = n - 1;
	while (hi - lo > 1) {
		int mid = (hi + lo) >> 1;
		int s1 = sgn(vect(p[mid] - p[lo], q - p[lo]));
		int s2 = sgn(vect(q - p[hi], p[mid] - p[hi]));
		bool f1 = ccw ? (s1 >= 0) : (s1 <= 0);
		bool f2 = ccw ? (s2 >= 0) : (s2 <= 0);
		if (f1 && f2) return 1;
		if (!f1 && !f2) return 0;
		if (f1) lo = mid;
		else hi = mid;
	}
	return 0;
}







bool id10(PT *p, int n, PT P, int &L, int &R) {
	if (id9(p, n, P)) return 0;
	for (int T = 0; T < 2; T++) {
		auto check = [&](int fir, int sec) { return vect(P, p[sec], p[fir]) > EPS; };
		bool up = false;
		DB cr = 0;
		if (n >= 2) { cr = vect(P, p[0], p[1]); }
		if (fabs(cr) < EPS && n >= 3) { cr = vect(P, p[0], p[2]); }
		up = (cr > EPS);
		int bd[] = {1, n - 1};
		int ans = 0;
		while (bd[0] + 6 <= bd[1]) {
			int h[2];
			for (int hh = 0; hh < 2; hh++) { h[hh] = (bd[0] + bd[1] + bd[hh]) / 3; }
			if (!check(h[up ^ T], 0) ^ T) { bd[up ^ T] = h[up ^ T]; }
			else {
				int gr = check(h[0], h[1]);
				bd[gr ^ T] = h[gr ^ T];
			}
		}
		for (int i = bd[0]; i <= bd[1]; i++) {
			if (check(i, ans) ^ T) ans = i;
		}
		T ? R = ans : L = ans;
	}
	return 1;
}

int id8(PT p1, PT p2, PT p3, PT p4, PT& p) {
	DB s1 = vect(p1, p2, p3), s2 = vect(p1, p2, p4);
	p = p3 + (p4 - p3) * s1 / (s1 - s2);
	if (s1 * s2 > -EPS) return 0;
	return 1;
}

int cutPolygon(PT *p, int n, PT p1, PT p2, PT *q) {
	int m = 0;
	for (int i = 0; i < n; i++) {
		if (vect(p[i], p1, p2) > -EPS) q[m++] = p[i];
		if (id8(p1, p2, p[i], p[(i + 1) % n], q[m])) m++;
	}
	return m;
}

int id5(PT *p, int n, PT p1, PT p2, PT *q) {
	assert(dis(p1, p2) > EPS);
	p1 = p1 + (p1 - p2) * 1e8;
	int L, R;
	assert(id10(p, n, p1, L, R));
	if (vect(p[R], p1, p2) > -EPS) {
		for (int i = 0; i < n; i++) q[i] = p[i];
		return n;
	}
	if (vect(p[L], p1, p2) < -EPS) return 0;
	int st = L, en = R;
	if (en < st) en += n;
	while (st < en) {
		int md = (st + en) / 2;
		if (vect(p[md % n], p1, p2) > EPS) st = md + 1;
		else en = md;
	}
	int T = st % n;
	st = R, en = L;
	if (en < st) en += n;
	while (st < en) {
		int md = (st + en) / 2;
		if (vect(p[md % n], p1, p2) < EPS) st = md + 1;
		else en = md;
	}
	int F = st % n;
	int qn = 0;
	for (int i = F; i != T; i = (i + 1) % n) q[qn++] = p[i];
	id8(p1, p2, p[(T - 1 + n) % n], p[T], q[qn]), qn++;
	id8(p1, p2, p[(F - 1 + n) % n], p[F], q[qn]);
	if (dis(q[qn], q[qn - 1]) > EPS) qn++;
	return qn;
}

DB id3(PT p, PT *q, int m) {
	if (inPolygon(p, q, m)) return 0;
	DB rlt = INF;
	for (int i = 0; i < m; i++) rlt = min(rlt, id7(p, q[i], q[(i + 1) % m]));
	return rlt;
}

DB dis(PT *p, int n, PT *q, int m) {
	DB rlt;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (common(p[i], p[(i + 1) % n], q[j], q[(j + 1) % m])) return 0;
		}
	}
	if (inPolygon(p[0], q, m) || inPolygon(q[0], p, n)) return 0;

	rlt = INF;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			rlt = min(rlt, id7(p[i], q[j], q[(j + 1) % m]));
			rlt = min(rlt, id7(q[j], p[i], p[(i + 1) % n]));
		}
	}
	return rlt;
}

int id11(PT *p, int n, PT *q) {
	sort(p, p + n);
	n = unique(p, p + n) - p;
	if (n == 1) {
		q[0] = p[0];
		return 1;
	}
	int m = 0;
	for (int i = 0; i < n; i++) {
		while (m > 1 && vect(q[m - 2], q[m - 1], p[i]) < EPS) m--;
		q[m++] = p[i];
	}
	int k = m;
	for (int i = n - 2; i >= 0; i--) {
		while (m > k && vect(q[m - 2], q[m - 1], p[i]) < EPS) m--;
		q[m++] = p[i];
	}
	return --m;
}

PT innercenter(PT a, PT b, PT c) {
	DB A = dis(b - c);
	DB B = dis(c - a);
	DB C = dis(a - b);
	return PT((A * a.x + B * b.x + C * c.x) / (A + B + C), (A * a.y + B * b.y + C * c.y) / (A + B + C));
}

PT outercenter(PT a, PT b, PT c) {
	DB c1 = (scal(a, a) - scal(b, b)) / 2, c2 = (scal(a, a) - scal(c, c)) / 2;
	DB x0 = (c1 * (a.y - c.y) - c2 * (a.y - b.y)) / vect(a - b, a - c);
	DB y0 = (c1 * (a.x - c.x) - c2 * (a.x - b.x)) / vect(a - c, a - b);
	return PT(x0, y0);
}

const int N = 1100000;
DB v[N];
PT P[N], Q[N], R[] = {PT(0, 0), PT(1e5, 0), PT(1e5, 1e5), PT(0, 1e5)}, T[22], S[22];
int dx[] = {0, 1, 0, -1};
int dy[] = {-1, 0, 1, 0};

void print(PT pt) {
	printf("%d %d\n", (int)round(pt.x), (int)round(pt.y));
}

int main() {


	int n; scanf("%d", &n);
	for (int i = 0; i < n; i++) P[i].in(), scanf("%lf", &v[i]);
	int qn = 0;
	for (int i = 0; i < n; i++) {
		if (v[i] < EPS) {
			Q[qn++] = P[i];
			continue;
		}
		int m = 4;
		for (int j = 0; j < m; j++) T[j] = P[i] + PT(v[i] * dx[j], v[i] * dy[j]);
		for (int j = 0; j < 4; j++) {
			m = cutPolygon(T, m, R[j], R[(j + 1) % 4], S);
			for (int k = 0; k < m; k++) T[k] = S[k];
		}
		for (int j = 0; j < m; j++) Q[qn++] = T[j];
	}
	qn = id11(Q, qn, P);
	P[qn] = P[0], P[qn + 1] = P[1];
	DB ans = 0;
	int cur;
	for (int i = 0; i < qn; i++) {
		DB ang = id0(P[i], P[i + 1], P[i + 2]);
		DB r = dis(P[i + 1], P[i + 2]) / sin(ang);
		if (ans < r) {
			ans = r;
			cur = i;
		}
	}
	for (int i = cur; i < cur + 3; i++) print(P[i]);
}

                                                                                                                                              