




using namespace std;
using db = long long;
using ll = long long;
using ull = unsigned long long; 
using pII = pair <int, int>;
using pLL = pair <ll, ll>;
constexpr int mod = 1e9 + 7;
template <class T1, class T2> inline void chadd(T1 &x, T2 y, int Mod = mod) { x += y; while (x >= Mod) x -= Mod; while (x < 0) x += Mod; } 
template <class T1, class T2> inline void chmax(T1 &x, T2 y) { if (x < y) x = y; }
template <class T1, class T2> inline void chmin(T1 &x, T2 y) { if (x > y) x = y; }
inline int nextInt() { int x; cin >> x; return x; }
void rd() {}
template <class T, class... Ts> void rd(T& arg, Ts&... args) { cin >> arg; rd(args...); }

void err() { cout << "\033[39;0m" << endl; } 
template <class T, class... Ts> void err(const T& arg, const Ts&... args) { cout << arg << ' '; err(args...); }
template <template<typename...> class T, typename t, typename... A> 
void err(const T <t> &arg, const A&... args) { for (auto &v : arg) cout << v << ' '; err(args...); }
void ptt() { cout << endl; }
template <class T, class... Ts> void ptt(const T& arg, const Ts&... args) { cout << ' ' << arg; ptt(args...); }
template <class T, class... Ts> void pt(const T& arg, const Ts&... args) { cout << arg; ptt(args...); }
void pt() {}
template <template<typename...> class T, typename t, typename... A>
void pt(const T <t> &arg, const A&... args) { for (int i = 0, sze = arg.size(); i < sze; ++i) cout << arg[i] << " \n"[i == sze - 1]; pt(args...); }
inline ll qpow(ll base, ll n) { assert(n >= 0); ll res = 1; while (n) { if (n & 1) res = res * base % mod; base = base * base % mod; n >>= 1; } return res; }



const db eps = 1e-10;
const db PI = acos(-1.0); 
int sgn(db x) { if (x == 0) return 0; return x < 0 ? -1 : 1; }

struct Point {
	db x, y;
	Point(db x = 0, db y = 0) : x(x), y(y) {}
	void scan() { rd(x, y); }
	void print() { pt(x, y); }
	bool operator == (const Point &b) const { return sgn(x - b.x) == 0 && sgn(y - b.y) == 0; }
	bool operator < (const Point &b) const { return sgn(x - b.x) == 0 ? sgn(y - b.y) < 0 : x < b.x; }
	Point operator + (const Point &b) const { return Point(x + b.x, y + b.y); }
	Point operator - (const Point &b) const { return Point(x - b.x, y - b.y); }
	Point operator * (const db &b) const { return Point(x * b, y * b); }
	Point operator / (const db &b) const { return Point(x / b, y / b); }
	db operator ^ (const Point &b) const { return x * b.y - y * b.x; }
	db operator * (const Point &b) const { return x * b.x + y * b.y; }
	db len() { return norm(complex<db>(x, y)); }
	db len2() { return x * x + y * y; }
	db dis(Point b) { return norm(complex<db>(x - b.x, y - b.y)); }
	db dis2(Point b) { return (x - b.x) * (x - b.x) + (y - b.y) * (y - b.y); }
	int quad() {
		int _x = sgn(x), _y = sgn(y);
		if (_x > 0 && _y >= 0) return 1;
		if (_x <= 0 && _y > 0) return 2;
		if (_x < 0 && _y <= 0) return 3;
		if (_x >= 0 && _y < 0) return 4;
	}
	

	db getRad(Point a, Point b) {
		Point p = *this;
		return fabs(atan2(fabs((a - p) ^ (b - p)), (a - p) * (b - p)));
	}
	

	Point normal() { return Point(-y, x) / len(); }
	

	Point trunc(db r) {
		db l = len();
		if (!sgn(l)) return *this;
		r /= l;
		return Point(x * r, y * r);
	}
	

	Point rotleft() { return Point(-y, x); }
	

	Point rotright() { return Point(y, -x); }
	

	Point rotate(Point p, db rad) {
		Point v = (*this) - p;
		db c = cos(rad), s = sin(rad);
		return Point(p.x + v.x * c - v.y * s, p.y + v.x * s + v.y * c);
	}
};

struct Line {
	Point s, e;
	Line() {}
	Line(Point s, Point e) : s(s), e(e) {}
	void scan() { s.scan(); e.scan(); }
	void print() { s.print(); e.print(); }
	bool operator == (const Line &b) const { return s == b.s && e == b.e; }
	

	Line(Point p, db rad) {
		s = p;
		if (sgn(rad - PI / 2) == 0) {
			e = (s + Point(0, 1));
		} else {
			e = (s + Point(1, tan(rad)));
		}
	}
	

	Line(db a, db b, db c) {
		if (sgn(a) == 0) {
			s = Point(0, -c / b);
			e = Point(1, -c / b);
		} else if (sgn(b) == 0) {
			s = Point(-c / a, 0);
			e = Point(-c / a, 1);
		} else {
			s = Point(0, -c / b);
			e = Point(1, (-c - a) / b);
		}
	}
	void adjust() { if (e < s) swap(s, e); }
	db length() { return s.dis(e); }
	

	db getAngle() {
		db k = atan2(e.y - s.y, e.x - s.x);
		if (sgn(k) < 0) k += PI;
		if (sgn(k - PI) == 0) k -= PI;
		return k;
	}
	

	

	

	

	int relationPoint(Point p) {
		int c = sgn((p - s) ^ (e - s));
		if (c < 0) return 1;
		if (c > 0) return 2;	
		return 3;
	}
	

	bool pointOnSeg(Point p) { return sgn((p - s) ^ (e - s)) == 0 && sgn((p - s) * (p - e)) <= 0; }
	

	bool parallel(Line b) { return sgn((e - s) ^ (b.e - b.s)) == 0; }
	

	

	

	

	int segCrossSeg(Line b) {
		int d1 = sgn((e - s) ^ (b.s - s));
		int d2 = sgn((e - s) ^ (b.e - s));
		int d3 = sgn((b.e - b.s) ^ (s - b.s));
		int d4 = sgn((b.e - b.s) ^ (e - b.s));
		if ((d1 ^ d2) == -2 && (d3 ^ d4) == -2) return 2;
		return ((d1 == 0 && sgn((b.s - s) * (b.s - e)) <= 0) ||
				(d2 == 0 && sgn((b.e - s) * (b.e - e)) <= 0) ||
				(d3 == 0 && sgn((s - b.s) * (s - b.e)) <= 0) ||
				(d4 == 0 && sgn((e - b.s) * (e - b.e)) <= 0));
	}
	

	

	

	

	int lineCrossSeg(Line b) {
		int d1 = sgn((e - s) ^ (b.s - s));
		int d2 = sgn((e - s) ^ (b.e - s));
		if ((d1 ^ d2) == -2) return 2;
		return (d1 == 0 || d2 == 0);
	}
	

	

	

	

	int lineCrossLine(Line b) {
		if ((*this).parallel(b)) return b.relationPoint(s) == 3;
		return 2;
	}
	

	

	Point crossPoint(Line b) {
		db a1 = (b.e - b.s) ^ (s - b.s);
		db a2 = (b.e - b.s) ^ (e - b.s);
		return Point((s.x * a2 - e.x * a1) / (a2 - a1), (s.y * a2 - e.y * a1) / (a2 - a1));
	}
	

	db disPointToLine(Point p) { return fabs((p - s) ^ (e - s)) / length(); } 
	

	db disPointToSeg(Point p) {
		if (sgn((p - s) * (e - s)) < 0 || sgn((p - e) * (s - e)) < 0)
			return min(p.dis(s), p.dis(e));
		return disPointToLine(p);
	}
	

	

	db disSegToSeg(Line b) {
		return min(min(disPointToSeg(b.s), disPointToSeg(b.e)),
				   min(b.disPointToSeg(s), b.disPointToSeg(e)));
	}
	

	Point lineProg(Point p) { return s + (((e - s) * ((e - s) * (p - s))) / ((e - s).len2())); }
	

	Point symmetryPoint(Point p) {
		Point q = lineProg(p);
		return Point(q.x * 2 - p.x, q.y * 2 - p.y);
	}
};

struct Polygon {
	vector <Point> p;
	Polygon() { p.clear(); }
	Polygon(int n) { p.clear(); p.resize(n); }
	int sze() { return p.size(); }
	Point& operator[](int x) { return p[(x + sze()) % sze()]; }
	void add(Point q) { p.push_back(q); }
	void scan(int n = -1) { if (n == -1) scanf("%d", &n); (*this) = Polygon(n); for (int i = 0; i < n; ++i) p[i].scan(); }
	vector<Line> getline() { 
		vector <Line> l(sze());
		for (int i = 0; i < sze(); ++i) {
			int j = (i + 1) % sze();
			l[i] = Line(p[i], p[j]);
		}
		return l;
	}
	

	void getUpDownHull(Polygon &upHull, Polygon &downHull) { 
		sort(p.begin(), p.end());
		upHull.p.clear(); downHull.p.clear();
		for (int i = 0; i < sze(); ++i) {
			while (upHull.sze() > 1 && sgn((p[i] - upHull[-1]) ^ (upHull[-2] - upHull[-1])) >= 0) upHull.p.pop_back();
			upHull.add(p[i]);
			while (downHull.sze() > 1 && sgn((p[i] - downHull[-1]) ^ (downHull[-2] - downHull[-1])) <= 0) downHull.p.pop_back();
			downHull.add(p[i]);
		}
	}
	

	

	

	

	

	db querySlopeMax(Point b) {
		if (sze() == 0) return -9e18;
		int l = 1, r = sze() - 1, pos = 0;
		while (r - l >= 0) {
			int mid = (l + r) >> 1;
			if (b * p[mid] > b * p[mid - 1]) {
				pos = mid;
				l = mid + 1;
			} else {
				r = mid - 1;
			}
		}
		return b * p[pos];
	}
};

constexpr int N = 3e5 + 10; 
int n; 

struct SEG {
	Polygon t[N << 2], upHull[N << 2], downHull[N << 2]; 
	void build(int id, int l, int r) {
		t[id].p.clear();
		if (l == r) return;
		int mid = (l + r) >> 1;
		build(id << 1, l, mid);
		build(id << 1 | 1, mid + 1, r);
	}
	void ins(int id, int l, int r, int ql, int qr, Point q) {
		if (l >= ql && r <= qr) return t[id].add(q);
		int mid = (l + r) >> 1;
		if (ql <= mid) ins(id << 1, l, mid, ql, qr, q);
		if (qr > mid) ins(id << 1 | 1, mid + 1, r, ql, qr, q);
	}
	void buildConvex(int id, int l, int r) {
		t[id].getUpDownHull(upHull[id], downHull[id]);
		if (l == r) return;
		int mid = (l + r) >> 1;
		buildConvex(id << 1, l, mid);
		buildConvex(id << 1 | 1, mid + 1, r);
	}
	db query(int id, int l, int r, int pos, Point q) { 
		db Max = -9e18;
		if (q.y > 0) Max = max(Max, upHull[id].querySlopeMax(q));
		else Max = max(Max, downHull[id].querySlopeMax(q));
		if (l == r) return Max;
		int mid = (l + r) >> 1;
		if (pos <= mid) Max = max(Max, query(id << 1, l, mid, pos, q));
		else Max = max(Max, query(id << 1 | 1, mid + 1, r, pos, q));
		return Max;
	}
}seg;

struct E { int op, l, r; Point q; ll ans; }e[N];  

void run() {
	int has = 0;
	for (int i = 1; i <= n; ++i) {
		rd(e[i].op);
		if (e[i].op == 1) {
			e[i].q.scan();
			e[i].l = i;
			e[i].r = n;
			++has;
		} else if (e[i].op == 2) {
			int x; rd(x);
			e[x].r = i;
			--has;
		} else {
			rd(e[i].q.x);
			e[i].q.y = 1;
			if (!has) e[i].op = 4;
		}
	}
	seg.build(1, 1, n);
	for (int i = 1; i <= n; ++i) {
		if (e[i].op == 1) {
			seg.ins(1, 1, n, e[i].l, e[i].r, e[i].q);
		} 
	}
	seg.buildConvex(1, 1, n);
	for (int i = 1; i <= n; ++i) {
		if (e[i].op == 4) pt("EMPTY SET");
		else if (e[i].op == 3) {
			db res = seg.query(1, 1, n, i, e[i].q);
			pt(res);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	cout << fixed << setprecision(20);
	while (cin >> n) run();
	return 0;
}
