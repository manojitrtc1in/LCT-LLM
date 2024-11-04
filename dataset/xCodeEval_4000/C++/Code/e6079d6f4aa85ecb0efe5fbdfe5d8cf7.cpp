#include<bits/stdc++.h>
using namespace std;

typedef long double DB;
const DB PI = acos(DB(-1));
const DB INF = 1e10;
const DB EPS = 1e-10;

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

DB getAngle180(PT p, PT p1, PT p2) {
	return acos(scal(p, p1, p2) / dis(p, p1) / dis(p, p2));
}

DB disToLine(PT p, PT p1, PT p2) {
	return fabs(vect(p, p1, p2)) / dis(p1, p2);
}

DB disToSeg(PT p, PT p1, PT p2) {
	if (scal(p1, p, p2) < 0) return dis(p, p1);
	if (scal(p2, p, p1) < 0) return dis(p, p2);
	return disToLine(p, p1, p2);
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
	return a + (a - b) * scal(p - a, a - b) / dis2(a - b);
}

int posLineLine(PT p1, PT p2, PT p3, PT p4, PT& p) {
	DB s1 = vect(p1, p2, p3), s2 = vect(p1, p2, p4);
	if (fabs(s1 - s2) < EPS) {
		if (fabs(s1) < EPS) return 2;
		return 0;
	}
	p = p3 + (p4 - p3) * s1 / (s1 - s2);
	return 1;
}

int posCirLine(PT p, DB r, PT p1, PT p2, PT *q) {
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

int posCirCir(PT p1, DB r1, PT p2, DB r2, PT *q) {
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

bool inCPolygon(PT *p, int n, PT q) {
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

bool contact_convex(PT *p, int n, PT P, int &L, int &R) {
	if (inCPolygon(p, n, P)) return 0;
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

int posLineSegEx(PT p1, PT p2, PT p3, PT p4, PT& p) {
	DB s1 = vect(p1, p2, p3), s2 = vect(p1, p2, p4);
	if (s1 * s2 > -EPS) return 0;
	p = p3 + (p4 - p3) * s1 / (s1 - s2);
	return 1;
}

int cutPolygon(PT *p, int n, PT p1, PT p2, PT *q) {
	int m = 0;
	for (int i = 0; i < n; i++) {
		if (vect(p[i], p1, p2) > -EPS) q[m++] = p[i];
		if (posLineSegEx(p1, p2, p[i], p[(i + 1) % n], q[m])) m++;
	}
	return m;
}

DB disToPolygon(PT p, PT *q, int m) {
	if (inPolygon(p, q, m)) return 0;
	DB rlt = INF;
	for (int i = 0; i < m; i++) rlt = min(rlt, disToSeg(p, q[i], q[(i + 1) % m]));
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
			rlt = min(rlt, disToSeg(p[i], q[j], q[(j + 1) % m]));
			rlt = min(rlt, disToSeg(q[j], p[i], p[(i + 1) % n]));
		}
	}
	return rlt;
}

int convex_hull(PT *p, int n, PT *q, int sig = 1) {
	sort(p, p + n);
	n = unique(p, p + n) - p;
	if (n == 1) {
		q[0] = p[0];
		return 1;
	}
	int m = 0;
	for (int i = 0; i < n; i++) {
		while (m > 1 && vect(q[m - 2], q[m - 1], p[i]) < EPS * sig) m--;
		q[m++] = p[i];
	}
	int k = m;
	for (int i = n - 2; i >= 0; i--) {
		while (m > k && vect(q[m - 2], q[m - 1], p[i]) < EPS * sig) m--;
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

const int N = 1100;
const DB RAD = 100;
int rn, bn;
PT R[N], B[N], _R[N], _B[N + N], P[N], Q[N + N];
int cnt[N + N], chk[N];

PT trans(PT O, DB r, PT A){
	DB d2 = dis2(O, A);
	if (fabs(d2) < EPS) return PT(INF, INF);
	return O + (A - O) * sqr(r) / d2;
}

void init(PT P) {
	memcpy(_R, R, sizeof R);
	memcpy(_B, B, sizeof B);
	for (int j = 0; j < rn; j++) _R[j] = trans(P, RAD, R[j]);
	for (int j = 0; j < bn; j++) _B[j] = trans(P, RAD, B[j]);
}

int main() {
	scanf("%d%d", &rn, &bn);
	for (int i = 0; i < rn; i++) R[i].in();
	for (int i = 0; i < bn; i++) B[i].in();
	if (bn <= 2) return puts("-1"), 0;
	DB ans = INF;
	for (int i = 0; i < rn; i++) {
		init(R[i]);
		int m = convex_hull(_B, bn, P);
		if (inPolygon(R[i], P, m) != 1) return puts("-1"), 0;
		for (int j = 0; j < m; j++) ans = min(ans, disToLine(R[i], P[j], P[(j + 1) % m]));
	}
	for (int i = 0; i < bn; i++) {
		init(B[i]);
		swap(_B[i], _B[bn - 1]);
		int m = convex_hull(_B, bn - 1, P);
		if (m == 2) {
			if (onLine(B[i], P[0], P[1])) return puts("-1"), 0;
			int flg = 0;
			for (int j = 0; j < rn; j++) {
				if (vect(B[i], P[0], P[1]) * vect(R[j], P[0], P[1]) < EPS) {
					flg = 1;
					break;
				}
			}
			if (flg) ans = min(ans, disToLine(B[i], P[0], P[1]));
			continue;
		}
		memset(cnt, 0, sizeof cnt);
		memset(chk, 0, sizeof chk);
		vector<PT> rest;
		for (int j = 0; j < rn; j++) {
			int a, b;
			if (contact_convex(P, m, _R[j], a, b)) {
				if (b < a) b += m;
				if (vect(_R[j], P[(a - 1 + m) % m], P[a % m]) < EPS) --a;
				if (vect(_R[j], P[b % m], P[(b + 1) % m]) > EPS) --b;
				if (a >= 0) {
					cnt[a]++;
					cnt[b + 1]--;
				} else {
					cnt[0]++;
					cnt[b + 1]--;
					cnt[m - 1]++;
					cnt[m]--;
				}
			} else rest.push_back(_R[j]);
		}
		for (int j = 1; j <= m + m; j++) cnt[j] += cnt[j - 1];
		for (int j = m; j <= m + m; j++) cnt[j % m] += cnt[j];
		int sz = rest.size();
		for (int j = 0; j < m; j++) _B[j] = P[j];
		for (int j = 0; j < sz; j++) _B[m + j] = rest[j];
		int m1 = convex_hull(_B, m + sz, Q, -1);
		int from;
		for (int j = 0; j < m1; j++) {
			if (Q[j] == P[0]) {
				from = j;
				break;
			}
		}
		int k = 0;
		for (int j = from; j < from + m1; j++) {
			if (onLine(Q[j % m1], Q[(j - 1 + m1) % m1], Q[(j + 1) % m1])) {
				chk[k - 1] = 1;
			} else ++k;
		}
		for (int j = 0; j < m; j++) {
			if (!cnt[j] && !chk[j]) continue;
			if (!onLine(B[i], P[j], P[(j + 1) % m])) {
				if (vect(B[i], P[j], P[(j + 1) % m]) > EPS) ans = min(ans, disToLine(B[i], P[j], P[(j + 1) % m]));
			} else return puts("-1"), 0;
		}
	}
	printf("%.10lf\n", (double)(RAD * RAD / ans / 2));
}

                                                                                                                              