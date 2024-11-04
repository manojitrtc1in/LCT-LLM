


















using namespace std;










std::mt19937 rnd((int)std::chrono::steady_clock::now().time_since_epoch().count());
typedef long long ll;
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }

const int MAXN = 100000;

struct Frac {
	ll num, den;
	Frac() :num(0), den(1) {}
	Frac(ll _num) :num(_num), den(1) {}
	Frac(ll _num, ll _den) { num = _num, den = _den; if (den < 0) num = -num, den = -den; ll g = gcd(abs(num), den); num /= g, den /= g; }
	void print() const { printf("%lld", num); if (den != 1) printf("/%lld", den); }
};
Frac operator+(const Frac& a, const Frac& b) { ll g = gcd(a.den, b.den); return Frac(a.num * (b.den / g) + b.num * (a.den / g), a.den * (b.den / g)); }
Frac operator-(const Frac& a, const Frac& b) { ll g = gcd(a.den, b.den); return Frac(a.num * (b.den / g) - b.num * (a.den / g), a.den * (b.den / g)); }
Frac operator*(const Frac& a, const Frac& b) { ll g1 = gcd(abs(a.num), b.den); ll g2 = gcd(abs(b.num), a.den); return Frac((a.num / g1) * (b.num / g2), (a.den / g2) * (b.den / g1)); }
Frac operator/(const Frac& a, const Frac& b) { return Frac(a.num * b.den, a.den * b.num); }
bool operator<(const Frac& a, const Frac& b) { return a.num * b.den < b.num * a.den; }
bool operator>(const Frac& a, const Frac& b) { return a.num * b.den > b.num * a.den; }
bool operator!=(const Frac& a, const Frac& b) { return a.num != b.num || a.den != b.den; }

struct P { Frac x, y; P() {} P(Frac x, Frac y) :x(x), y(y) {} void print() const { printf("("); x.print(); printf(","); y.print(); printf(")"); } };
P operator+(const P& a, const P& b) { return P(a.x + b.x, a.y + b.y); }
P operator*(const Frac& a, const P& b) { return P(a * b.x, a * b.y); }
P operator-(const P& a, const P& b) { return P(a.x - b.x, a.y - b.y); }
bool operator!=(const P& a, const P& b) { return a.x != b.x || a.y != b.y; }

P calcx(const P& a, const P& b, int x) { return a + (x - a.x) * (1 / (b.x - a.x) * (b - a)); }
P calcy(const P& a, const P& b, int y) { return a + (y - a.y) * (1 / (b.y - a.y) * (b - a)); }


struct Hull {
	int t; ll dx,dy;
	deque<P> q; 

	Hull() { t = 0; dx = dy = 0; }

	P tocurrent(const P& a) {
		

		ll xwhole = a.x.num / a.x.den, ywhole = a.y.num / a.y.den;
		Frac xfrac = a.x - xwhole, yfrac = a.y - ywhole;
		return P((xwhole + t * ywhole + dx) + (xfrac + t * yfrac), a.y + dy);
	}
	P tostored(const P& a) { 
		

		ll xwhole = a.x.num / a.x.den, ywhole = a.y.num / a.y.den;
		Frac xfrac = a.x - xwhole, yfrac = a.y - ywhole;
		

		

		

		

		

		P ret = P((xfrac - t * yfrac) + (xwhole + t * dy - dx - t * ywhole), a.y - dy);
		

		

		return ret;
	}

	void removefirst() { assert(!q.empty()); q.pop_front(); }
	void removelast() { assert(!q.empty()); q.pop_back(); }
	P first() { assert(!q.empty()); return tocurrent(q.front()); }
	P last() { assert(!q.empty()); return tocurrent(q.back()); }
	Frac ymax() { return last().y; }
	Frac ymin() { return first().y; }
	Frac xmax() { return last().x; }
	Frac xmin() { return first().x; }

	void prepend(const P& p) { if (q.empty() || first() != p) q.push_front(tostored(p)); }
	void append(const P& p) { if (q.empty() || last() != p) q.push_back(tostored(p)); }

	void cutbelow(int y) {
		P p = first();
		while (p.y < y) {
			removefirst();
			P q = first();
			if (q.y > y) { prepend(calcy(p, q, y)); break; }
			p = q;
		}
	}
	void cutabove(int y) {
		P p = last();
		while (p.y > y) {
			removelast();
			P q = last();
			if (q.y < y) { append(calcy(q, p, y)); break; }
			p = q;
		}
	}
	void cutleft(int x) {
		P p = first();
		while (p.x < x) {
			removefirst();
			P q = first();
			if (q.x > x) { prepend(calcx(p, q, x)); break; }
			p = q;
		}
	}
	void cutright(int x) {
		P p = last();
		while (p.x > x) {
			removelast();
			P q = last();
			if (q.x < x) { append(calcx(q, p, x)); break; }
			p = q;
		}
	}
	void transform() {
		

		++t, dx += dy;
	}
	void translate(int z) {
		

		dx += z, dy += z;
	}

	void print(char* s) {
		printf("%s:", s); id3(i, q) { printf(" "); tocurrent(q[i]).print(); } puts("");
	}
};



int n;
int xlo[MAXN], xhi[MAXN];
int ylo[MAXN], yhi[MAXN];
int zlo[MAXN], zhi[MAXN];

bool solve() {
	Hull lo;
	Hull hi;


	auto empty = [&]() {
		return lo.q.empty() || hi.q.empty();
	};
	auto clear = [&]() {
		lo.q.clear();
		hi.q.clear();
	};
	auto cutbelow = [&](int y) {
		if (empty()) return;
		if (lo.ymax() < y) return clear();
		lo.cutbelow(y);
		hi.cutbelow(y);
		lo.prepend(hi.first());
	};
	auto cutabove = [&](int y) {
		if (empty()) return;
		if (lo.ymin() > y) return clear();
		lo.cutabove(y);
		hi.cutabove(y);
		hi.append(lo.last());
	};
	auto cutleft = [&](int x) {
		if (empty()) return;
		if (lo.xmax() < x) return clear();
		lo.cutleft(x);
		hi.cutleft(x);
		hi.prepend(lo.first());
	};
	auto cutright = [&](int x) {
		if (empty()) return;
		if (lo.xmin() > x) return clear();
		lo.cutright(x);
		hi.cutright(x);
		lo.append(hi.last());
	};
	auto transform = [&]() {
		if (empty()) return;
		lo.transform();
		hi.transform();
	};
	auto translate = [&](int lz,int hz) {
		if (empty()) return;
		lo.translate(lz);
		hi.translate(hz);
		lo.append(hi.last());
		hi.prepend(lo.first());
	};

	P llo(xlo[1], xlo[1] - xhi[0]);
	P rlo(xhi[1], xhi[1] - xhi[0]);
	P lhi(xlo[1], xlo[1] - xlo[0]);
	P rhi(xhi[1], xhi[1] - xlo[0]);
	lo.append(llo);
	lo.append(rlo);
	lo.append(rhi);
	hi.append(llo);
	hi.append(lhi);
	hi.append(rhi);
	cutbelow(ylo[1]);
	cutabove(yhi[1]);
	

	


	FOR(i, 2, n) {
		transform();
		translate(zlo[i], zhi[i]);
		cutleft(xlo[i]);
		cutright(xhi[i]);
		cutbelow(ylo[i]);
		cutabove(yhi[i]);
	}
	

	


	return !empty();
}

void run(int id5) {
	scanf("%d", &n);
	REP(i, n) scanf("%d%d", &xlo[i], &xhi[i]);
	FOR(i, 1, n) scanf("%d%d", &ylo[i], &yhi[i]);
	FOR(i, 2, n) scanf("%d%d", &zlo[i], &zhi[i]);
	if (false) {
		printf("n=%d\n", n);
		REP(i, n) { if (i - 2 >= 0 && xlo[i] == xlo[i - 2] && xhi[i] == xhi[i - 2]) continue; printf("x[%d]=(%d,%d)\n", i, xlo[i], xhi[i]); }
		FOR(i, 1, n) { if (i - 2 >= 1 && ylo[i] == ylo[i - 2] && yhi[i] == yhi[i - 2]) continue; printf("y[%d]=(%d,%d)\n", i, ylo[i], yhi[i]); }
		FOR(i, 2, n) { if (i - 2 >= 2 && zlo[i] == zlo[i - 2] && zhi[i] == zhi[i - 2]) continue; printf("z[%d]=(%d,%d)\n", i, zlo[i], zhi[i]); }
		exit(0);
	}
	printf("%s\n", solve() ? "YES" : "NO");
}

void stress() {
	const int id0 = -1e8, id4 = +1e8;
	auto genval = [&]() { return rnd() % (id4/4 - id0/4 + 1) + id0/4; };
	auto id1 = [&](int x) { x = min(x, id4); assert(x >= id0); return rnd() % (x - id0 + 1) + id0; };
	auto id2 = [&](int x) { x = max(x, id0); assert(x <= id4); return rnd() % (id4 - x + 1) + x; };

	REP(rep, 1) {
		n = MAXN;
		vector<ll> ans(n); REP(i, n) ans[i] = genval();

		

		

		

		

		bool res = solve();
		printf("%s\n", res ? "YES" : "NO");
	}
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run(i);
	

	return 0;
}
