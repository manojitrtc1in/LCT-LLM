
using std::cin;
using std::cout;
using std::vector;
using std::copy;
using std::reverse;
using std::sort;
using std::get;
using std::unique;
using std::swap;
using std::array;
using std::cerr;
using std::function;
using std::map;
using std::set;
using std::pair;
using std::mt19937;
using std::make_pair;
using std::tuple;
using std::make_tuple;
using std::uniform_int_distribution;
using ll = long long;
namespace qwq {
	mt19937 eng;
	void init(int Seed) { return eng.seed(Seed); }
	int rnd(int l = 1, int r = 1000000000) { return uniform_int_distribution<int> (l, r)(eng); }
}
template <typename T>
inline T min(const T &x, const T &y) { return x < y ? x : y; }
template<typename T>
inline T max(const T &x, const T &y) { return x > y ? x : y; }
template <typename T>
inline void read(T &x) {
	x = 0;
	bool f = 0;
	char ch = getchar();
	while (!isdigit(ch)) f = ch == '-', ch = getchar();
	while (isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
	if (f) x = -x;
}
template<typename T, typename ...Arg>
inline void read(T &x, Arg &... y) {
	read(x);
	read(y...);
}

const double Pi = acos(-1);
const int MAXN = 524288, MOD = 998244353, inv2 = (MOD + 1) / 2, id1 = 0x3f3f3f3f;
const long long id2 = 0x3f3f3f3f3f3f3f3f;
auto Ksm = [] (int x, int y) -> int {
	if (y < 0) {
		y %= MOD - 1;
		y += MOD - 1;
	}
	int ret = 1;
	for (; y; y /= 2, x = (long long) x * x % MOD) if (y & 1) ret = (long long) ret * x % MOD;
	return ret;
};
auto Mod = [] (int x) -> int {
	if (x >= MOD) return x - MOD;
	else if (x < 0) return x + MOD;
	else return x;
};
inline int ls(int k) { return k << 1; }
inline int rs(int k) { return k << 1 | 1; }
int fac[MAXN], ifac[MAXN];
namespace POLY {
int SZ, R[MAXN], W[MAXN], INV[MAXN + 1];
void id0() {
	INV[1] = 1;
	for (int i = 2; i <= MAXN; ++i) INV[i] = (long long) (MOD - MOD / i) * INV[MOD % i] % MOD;
}
void INIT(int len) {
	if (SZ == len) return;
	SZ = len;
	for (int i = 1; i < len; ++i) R[i] = (R[i >> 1] >> 1) | (i & 1 ? (len >> 1) : 0);
	int wn = Ksm(3, (MOD - 1) / len);
	W[len >> 1] = 1;
	for (int i = (len >> 1) + 1; i < len; ++i) W[i] = (long long) W[i - 1] * wn % MOD;
	for (int i = (len >> 1) - 1; i > 0; --i) W[i] = W[i << 1];
}
void Ntt(vector<int>& F, int limit, int type) {
	static unsigned long long c[MAXN];
	copy(F.begin(), F.begin() + limit, c);
	for (int i = 1; i < limit; ++i) if (i < R[i]) swap(c[i], c[R[i]]);
	for (int o = 2, j = 1; o <= limit; o <<= 1, j <<= 1) {
		for (int i = 0; i < limit; i += o) {
			for (int k = 0; k < j; ++k) {
				unsigned long long OI = c[i + j + k] * W[k + j] % MOD;
				c[i + j + k] = c[i + k] + MOD - OI;
				c[i + k] += OI;
			}
		}
	}
	if (type == -1) {
		reverse(c + 1, c + limit);
		int inv = INV[limit];
		for (int i = 0; i < limit; ++i) c[i] = c[i] % MOD * inv % MOD;
	}
	for (int i = 0; i < limit; ++i) F[i] = c[i] % MOD;
}
int w;
typedef std::pair<int, int> complex;
complex operator + (complex &x, complex &y) {
	return std::make_pair((x.first + y.first) % MOD, (x.second + y.second) % MOD);
}
complex operator - (complex &x, complex &y) {
	return std::make_pair((x.first - y.first + MOD) % MOD, (x.second - y.second + MOD) % MOD);
}
complex operator * (complex &x, complex &y) {
	return std::make_pair(((long long) x.first * y.first + (long long) w * x.second % MOD * y.second) % MOD, ((long long) x.first * y.second + (long long) y.first * x.second) % MOD);
}
complex ksm(complex x, int y) {
	complex res(1, 0);
	for (; y; y /= 2, x = x * x) if (y & 1) res = res * x;
	return res;
}
bool check(int x) { return Ksm(x, (MOD - 1) / 2) == 1; }
int Sqrt(int x) {
	if (!x) return x;
	else {
		int a = qwq::rnd() % MOD;
		while (check(((long long) a * a + MOD - x) % MOD)) a = qwq::rnd() % MOD;
		w = ((long long) a * a + MOD - x) % MOD;
		complex b(a, 1);
		int ans1(ksm(b, (MOD + 1) / 2).first);
		return min(ans1, MOD - ans1);
	}
}
struct Poly {
	vector<int> v;
	int& operator [] (const int &pos) { return v[pos]; }
	int len() { return v.size(); }
	void set(int l) { return v.resize(l); }
	void adjust() { while (v.size() > 1 && !v.back()) v.pop_back(); }
	void rev() { reverse(v.begin(), v.end()); }
	void Ntt(int L, int type) {
		int limit = 1 << L;
		INIT(limit);
		set(limit);
		POLY::Ntt(v, limit, type);
	}
	void Squ() {
		int L = ceil(log2(len())) + 1, limit = 1 << L;
		Ntt(L, 1);
		for (int i = 0; i < limit; ++i) v[i] = (long long) v[i] * v[i] % MOD;
		Ntt(L, -1);
		adjust();
	}
	void operator += (Poly &x) {
		if (len() < x.len()) set(x.len());
		for (int i = 0; i < x.len(); ++i)
			v[i] = Mod(v[i] + x[i]);
		adjust();
	}
	void operator -= (Poly &x) {
		if (len() < x.len()) set(x.len());
		for (int i = 0; i < x.len(); ++i) v[i] = Mod(v[i] - x[i]);
		adjust();
	}
	Poly operator * (Poly &x) {
		Poly ret, tmp0 = *this, tmp1 = x;
		int L = ceil(log2(tmp0.len() + tmp1.len() - 1)), n = 1 << L;
		Ntt(L, 1);
		x.Ntt(L, 1);
		ret.set(n);
		for (int i = 0; i < n; ++i) ret[i] = (long long) x[i] * v[i] % MOD;
		ret.Ntt(L, -1);
		ret.adjust();
		*this = tmp0;
		x = tmp1;
		return ret;
	}
	Poly operator - (Poly &x) {
		Poly ret;
		ret.set(max(len(), x.len()));
		for (int i = 0; i < len(); ++i) ret[i] = v[i];
		for (int i = 0; i < x.len(); ++i) ret[i] = Mod(ret[i] - x[i]);
		return ret;
	}
	Poly operator + (Poly &x) {
		Poly ret;
		ret.set(max(len(), x.len()));
		for (int i = 0; i < len(); ++i) ret[i] = v[i];
		for (int i = 0; i < x.len(); ++i) ret[i] = Mod(ret[i] + x[i]);
		return ret;
	}
	void operator *= (Poly &x) {
		Poly tmp = x;
		int L = ceil(log2(len() + x.len() - 1)), n = 1 << L;
		Ntt(L, 1);
		x.Ntt(L, 1);
		for (int i = 0; i < n; ++i) v[i] = (long long) v[i] * x[i] % MOD;
		Ntt(L, -1);
		adjust();
		x = tmp;
	}
	Poly GetInv(int deg = -1) {
		if (deg == 1) return {{Ksm(v[0], MOD - 2)}};
		Poly ret = GetInv((deg + 1) / 2), tmp;
		int L = ceil(log2(deg)) + 1, n = 1 << L, mx = min(len(), deg);
		tmp.set(deg);
		for (int i = 0; i < mx; ++i) tmp[i] = v[i];
		tmp.Ntt(L, 1);
		ret.Ntt(L, 1);
		for (int i = 0; i < n; ++i) ret[i] = (2 - (long long) tmp[i] * ret[i] % MOD + MOD) * ret[i] % MOD;
		ret.Ntt(L, -1);
		ret.set(deg);
		return ret;
	}
	pair<Poly, Poly> operator % (Poly &x) {
		if (x.len() > len()) return {{{0}}, *this};
		Poly tmp0 = *this, tmp1 = x;
		tmp0.rev();
		tmp1.rev();
		tmp1 = tmp1.GetInv(len() - x.len() + 1);
		tmp0 *= tmp1;
		tmp0.set(len() - x.len() + 1);
		tmp0.rev();
		tmp1 = tmp0 * x;
		Poly ret = *this - tmp1;
		ret.set(x.len() - 1);
		return {tmp0, ret};
	}
	vector<int> getmulpointvalue(vector<int> &x) {
		static Poly tmp[MAXN * 4];
		function<void(int, int, int)> get = [&] (int u, int l, int r) -> void {
			if (l == r) {
				tmp[u] = {{Mod(-x[l]), 1}};
				return;
			}
			int mid = (l + r) / 2;
			get(ls(u), l, mid);
			get(rs(u), mid + 1, r);
			tmp[u] = tmp[ls(u)] * tmp[rs(u)];
		};
		get(1, 0, x.size() - 1);
		vector<int> ret(x.size());
		function<void(int, int, Poly, int)> solve = [&] (int l, int r, Poly f, int u) -> void {
			if (l == r) {
				ret[l] = f[0];
				return;
			}
			int mid = (l + r) / 2;
			solve(l, mid, (f % tmp[ls(u)]).second, ls(u));
			solve(mid + 1, r, (f % tmp[rs(u)]).second, rs(u));
		};
		solve(0, x.size() - 1, (*this % tmp[1]).second, 1);
		return ret;
	}
	Poly Dif(int deg = -1) {
		Poly tmp;
		tmp.set(max(len() - 1, 1));
		for (int i = 0; i < len() - 1; ++i) tmp[i] = v[i + 1] * (i + 1LL) % MOD;
		if (~deg) tmp.set(deg);
		return tmp;
	}
	Poly GetSqrt(int deg = -1) {
		if (deg == 1) return {{POLY::Sqrt(v[0])}};
		Poly ret = GetSqrt((deg + 1) / 2), tmp0 = ret.GetInv(deg), tmp1;
		int L = ceil(log2(deg)) + 1, mx = min(len(), deg);
		tmp1.set(deg);
		for (int i = 0; i < mx; ++i) tmp1[i] = v[i];
		tmp0 *= tmp1;
		tmp0.set(deg);
		ret += tmp0;
		for (auto &i: ret.v) i = (long long) i * inv2 % MOD;
		return ret;
	}
	Poly Int(int deg = -1) {
		Poly tmp;
		tmp.set(len() + 1);
		for (int i = 1; i < tmp.len(); ++i) tmp[i] = (long long) v[i - 1] * INV[i] % MOD;
		if (~deg) tmp.set(deg);
		return tmp;
	}
	Poly GetLn(int deg = -1) {
		Poly tmp0 = Dif(deg), tmp1 = GetInv(deg);
		tmp0 *= tmp1;
		tmp0.set(deg);
		return tmp0.Int(deg);
	}
	Poly GetExp(int deg = -1) {
		if (deg == 1) return {{1}};
		Poly tmp0 = GetExp((deg + 1) / 2), tmp1 = tmp0.GetLn(deg);
		for (int i = 0; i < deg; ++i) tmp1[i] = Mod(v[i] - tmp1[i]);
		tmp1[0] = Mod(tmp1[0] + 1);
		tmp0 *= tmp1;
		tmp0.set(deg);
		return tmp0;
	}
	Poly GetKsm(int deg, int K) {
		Poly tmp0 = GetLn(deg);
		for (auto &i: tmp0.v) i = (long long) i * K % MOD;
		return tmp0.GetExp(deg);
	}
};
vector<int> Interpolation(vector<pair<int, int>> &x) {
	static Poly tmp[MAXN * 4];
	vector<int> tmpx;
	for (auto &i: x) tmpx.push_back(i.first);
	function<void(int, int, int)> get = [&] (int u, int l, int r) -> void {
		if (l == r) {
			tmp[u] = {{Mod(-tmpx[l]), 1}};
			return;
		}
		int mid = (l + r) / 2;
		get(ls(u), l, mid);
		get(rs(u), mid + 1, r);
		tmp[u] = tmp[ls(u)] * tmp[rs(u)];
	};
	get(1, 0, tmpx.size() - 1);
	Poly ret = tmp[1];
	ret = ret.Dif();
	vector<int> tmpy = ret.getmulpointvalue(tmpx);
	for (int i = 0; i < x.size(); ++i) tmpy[i] = (long long) Ksm(tmpy[i], MOD - 2) * x[i].second % MOD;
	function<Poly(int, int, int)> solve = [&] (int u, int l, int r) -> Poly {
		if (l == r) return {{tmpy[l]}};
		int mid = (l + r) / 2;
		Poly tmp0 = solve(ls(u), l, mid) * tmp[rs(u)];
		Poly tmp1 = solve(rs(u), mid + 1, r) * tmp[ls(u)];
		return tmp0 + tmp1;
	};
	return solve(1, 0, x.size() - 1).v;
}
}
using namespace POLY;
Poly f, p, q;
int N, dp[MAXN], ans[MAXN];
int main() {
	

	qwq::init(20041222);
	

	id0();
	fac[0] = 1;
	for (int i = 1; i < MAXN; ++i) fac[i] = (ll) i * fac[i - 1] % MOD;
	ifac[MAXN - 1] = Ksm(fac[MAXN - 1], MOD - 2);
	for (int i = MAXN - 2; i >= 0; --i) ifac[i] = (i + 1LL) * ifac[i + 1] % MOD;
	read(N);
	int S = (N - 1) / 2;
	q.set(N);
	p.set(N);
	for (int i = 0; i < N; ++i) p[i] = ifac[i];
	for (int i = S; i < N - 1; ++i) q[i] = fac[N - i - 2];
	f = p * q;
	for (int i = 2; i <= N; ++i) dp[i] = f[N - i] * (i - 1LL) % MOD * fac[N - i] % MOD;
	dp[1] = fac[N - 1];
	

	

	

	for (int i = N, s = 0; i; --i) {
		ans[i] = Mod(dp[i] - (ll) INV[i] * s % MOD);
		s = Mod(s + ans[i]);
	}
	for (int i = 1; i <= N; ++i) printf("%d ", ans[i]);
	putchar('\n');
	return 0;
}
