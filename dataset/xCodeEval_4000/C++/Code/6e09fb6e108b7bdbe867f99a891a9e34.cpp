#define _USE_MATH_DEFINES
#include<iostream>
#include<vector>
#include<set>
#include<queue>
#include<map>
#include<algorithm>
#include<cstring>
#include<string>
#include<cassert>
#include<cmath>
#include<climits>
#include<iomanip>
#include<stack>
#include<unordered_map>
#include<bitset>
#include<limits>
#include<array>
using namespace std;
#define MOD 1000000007
#define rep(i,m,n) for(int (i)=(int)(m);i<(int)(n);i++)
#define REP(i,n) rep(i,0,n)
#define FOR(i,c) for(decltype((c).begin())i=(c).begin();i!=(c).end();++i)
#define ll long long
#define ull unsigned long long
#define all(hoge) (hoge).begin(),(hoge).end()
typedef pair<ll, ll> P;
const long long INF = 1LL << 60;
typedef vector<ll> Array;
typedef vector<Array> Matrix;
string operator*(const string& s, int k) {
	if (k == 0) return "";
	string p = (s + s) * (k / 2);
	if (k % 2 == 1) p += s;
	return p;
}



template<class T> inline bool chmin(T& a, T b) {
	if (a > b) {
		a = b;
		return true;
	}
	return false;
}
template<class T> inline bool chmax(T& a, T b) {
	if (a < b) {
		a = b;
		return true;
	}
	return false;
}




struct Edge {

	ll to, cap, rev;
	Edge(ll _to, ll _cap, ll _rev) {
		to = _to; cap = _cap; rev = _rev;
	}
};
typedef vector<Edge> Edges;
typedef vector<Edges> Graph;
void add_edge(Graph& G, ll from, ll to, ll cap, bool revFlag, ll revCap) {

	G[from].push_back(Edge(to, cap, (ll)G[to].size()));
	if (revFlag)G[to].push_back(Edge(from, revCap, (ll)G[from].size() - 1));

}
ll max_flow_dfs(Graph& G, ll v, ll t, ll f, vector<bool>& used)
{
	if (v == t)
		return f;
	used[v] = true;
	for (int i = 0; i < G[v].size(); ++i) {
		Edge& e = G[v][i];
		if (!used[e.to] && e.cap > 0) {
			ll d = max_flow_dfs(G, e.to, t, min(f, e.cap), used);
			if (d > 0) {
				e.cap -= d;
				G[e.to][e.rev].cap += d;
				return d;
			}
		}
	}
	return 0;
}


ll max_flow(Graph& G, ll s, ll t)

{
	ll flow = 0;
	for (;;) {
		vector<bool> used(G.size());
		REP(i, used.size())used[i] = false;
		ll f = max_flow_dfs(G, s, t, INF, used);
		if (f == 0) {
			return flow;
		}
		flow += f;
	}
}
void BellmanFord(Graph& G, ll s, Array& d, Array& negative) {

	d.resize(G.size());
	negative.resize(G.size());
	REP(i, d.size())d[i] = INF;
	REP(i, d.size())negative[i] = false;
	d[s] = 0;
	REP(k, G.size() - 1) {
		REP(i, G.size()) {
			REP(j, G[i].size()) {
				if (d[i] != INF && d[G[i][j].to] > d[i] + G[i][j].cap) {
					d[G[i][j].to] = d[i] + G[i][j].cap;
				}
			}
		}
	}
	REP(k, G.size() - 1) {
		REP(i, G.size()) {
			REP(j, G[i].size()) {
				if (d[i] != INF && d[G[i][j].to] > d[i] + G[i][j].cap) {
					d[G[i][j].to] = d[i] + G[i][j].cap;
					negative[G[i][j].to] = true;
				}
				if (negative[i] == true)negative[G[i][j].to] = true;
			}
		}
	}
}
void Dijkstra(Graph& G, ll s, Array& d) {

	d.resize(G.size());
	REP(i, d.size())d[i] = INF;
	d[s] = 0;
	priority_queue<P, vector<P>, greater<P>> q;
	q.push(make_pair(0, s));
	while (!q.empty()) {
		P a = q.top();
		q.pop();
		if (d[a.second] < a.first)continue;
		REP(i, G[a.second].size()) {
			Edge e = G[a.second][i];
			if (d[e.to] > d[a.second] + e.cap) {
				d[e.to] = d[a.second] + e.cap;
				q.push(make_pair(d[e.to], e.to));
			}
		}
	}
}
void WarshallFloyd(Graph& G, Matrix& d) {

	d.resize(G.size());
	REP(i, d.size())d[i].resize(G.size());
	REP(i, d.size()) {
		REP(j, d[i].size()) {
			d[i][j] = INF;
		}
	}
	REP(i, G.size()) {
		REP(j, G[i].size()) {
			d[i][G[i][j].to] = G[i][j].cap;
		}
	}
	REP(i, G.size()) {
		REP(j, G.size()) {
			REP(k, G.size()) {
				chmin(d[j][k], d[j][i] + d[i][k]);
			}
		}
	}
}
bool tsort(Graph& graph, vector<int>& order) {

	int n = graph.size(), k = 0;
	Array in(n);
	for (auto& es : graph)
		for (auto& e : es)in[e.to]++;
	priority_queue<ll, Array, greater<ll>> que;
	REP(i, n)
		if (in[i] == 0)que.push(i);
	while (que.size()) {
		int v = que.top();
		que.pop();
		order.push_back(v);
		for (auto& e : graph[v])
			if (--in[e.to] == 0)que.push(e.to);
	}
	if (order.size() != n)return false;
	else return true;
}
class lca {
public:
	const int n = 0;
	const int log2_n = 0;
	std::vector<std::vector<int>> parent;
	std::vector<int> depth;

	lca() {}

	lca(const Graph& g, int root)
		: n(g.size()), log2_n(log2(n) + 1), parent(log2_n, std::vector<int>(n)), depth(n) {
		dfs(g, root, -1, 0);
		for (int k = 0; k + 1 < log2_n; k++) {
			for (int v = 0; v < (int)g.size(); v++) {
				if (parent[k][v] < 0)
					parent[k + 1][v] = -1;
				else
					parent[k + 1][v] = parent[k][parent[k][v]];
			}
		}
	}

	void dfs(const Graph& g, int v, int p, int d) {
		parent[0][v] = p;
		depth[v] = d;
		for (auto& e : g[v]) {
			if (e.to != p) dfs(g, e.to, v, d + 1);
		}
	}

	int get(int u, int v) {
		if (depth[u] > depth[v]) std::swap(u, v);
		for (int k = 0; k < log2_n; k++) {
			if ((depth[v] - depth[u]) >> k & 1) {
				v = parent[k][v];
			}
		}
		if (u == v) return u;
		for (int k = log2_n - 1; k >= 0; k--) {
			if (parent[k][u] != parent[k][v]) {
				u = parent[k][u];
				v = parent[k][v];
			}
		}
		return parent[0][u];
	}
};
void visit(const Graph& g, int v, Matrix& scc, stack<ll>& S, Array& inS, Array& low, Array& num, int& time) {
	low[v] = num[v] = ++time;
	S.push(v); inS[v] = true;
	FOR(e, g[v]) {
		int w = e->to;
		if (num[w] == 0) {
			visit(g, w, scc, S, inS, low, num, time);
			low[v] = min(low[v], low[w]);
		}
		else if (inS[w])
			low[v] = min(low[v], num[w]);
	}
	if (low[v] == num[v]) {
		scc.push_back(Array());
		while (1) {
			int w = S.top(); S.pop(); inS[w] = false;
			scc.back().push_back(w);
			if (v == w) break;
		}
	}
}
void stronglyConnectedComponents(const Graph& g, Matrix& scc) {

	const int n = g.size();
	Array num(n), low(n);
	stack<ll> S;
	Array inS(n);
	int time = 0;
	REP(u, n) if (num[u] == 0)
		visit(g, u, scc, S, inS, low, num, time);
}


class UnionFind {
	vector<int> data;
	ll num;
public:
	UnionFind(int size) : data(size, -1), num(size) { }
	bool unite(int x, int y) {

		x = root(x); y = root(y);
		if (x != y) {
			if (data[y] < data[x]) swap(x, y);
			data[x] += data[y]; data[y] = x;
		}
		num -= (x != y);
		return x != y;
	}
	bool findSet(int x, int y) {

		return root(x) == root(y);
	}
	int root(int x) {

		return data[x] < 0 ? x : data[x] = root(data[x]);
	}
	int size(int x) {

		return -data[root(x)];
	}
	int numSet() {

		return num;
	}
};
class SumSegTree {
private:

	ll _sum(ll a, ll b, ll k, ll l, ll r) {
		if (r <= a || b <= l)return 0;    

		if (a <= l && r <= b)return dat[k];   

		else {
			ll s1 = _sum(a, b, 2 * k + 1, l, (l + r) / 2); 

			ll s2 = _sum(a, b, 2 * k + 2, (l + r) / 2, r); 

			return s1 + s2;
		}
	}
public:
	ll n, height;
	vector<ll> dat;

	

	SumSegTree(ll _n) {
		n = 1;
		height = 1;
		while (n < _n) {
			n *= 2;
			height++;
		}
		dat = vector<ll>(2 * n - 1, 0);
	}

	

	void add(ll i, ll x) {
		i += n - 1; 

		dat[i] += x;
		while (i > 0) { 

			i = (i - 1) / 2;
			dat[i] += x;
		}
	}

	

	ll sum(ll a, ll b) {
		return _sum(a, b, 0, 0, n);
	}
};
class RmqTree {
private:

	ll _find(ll a, ll b, ll k, ll l, ll r) {
		if (r <= a || b <= l)return INF;    

		if (a <= l && r <= b)return dat[k];   

		else {
			ll s1 = _find(a, b, 2 * k + 1, l, (l + r) / 2); 

			ll s2 = _find(a, b, 2 * k + 2, (l + r) / 2, r); 

			return min(s1, s2);
		}
	}
public:
	ll n, height;
	vector<ll> dat;

	

	RmqTree(ll _n) {
		n = 1;
		height = 1;
		while (n < _n) {
			n *= 2;
			height++;
		}
		dat = vector<ll>(2 * n - 1, INF);
	}

	

	void update(ll i, ll x) {
		i += n - 1; 

		dat[i] = x;
		while (i > 0) { 

			i = (i - 1) / 2;
			dat[i] = min(dat[i * 2 + 1], dat[i * 2 + 2]);
		}
	}

	

	ll find(ll a, ll b) {
		return _find(a, b, 0, 0, n);
	}
};




void divisor(ll n, vector<ll>& ret) {
	for (ll i = 1; i * i <= n; i++) {
		if (n % i == 0) {
			ret.push_back(i);
			if (i * i != n) ret.push_back(n / i);
		}
	}
	sort(ret.begin(), ret.end());

}

vector<ll> lis_fast(const vector<ll>& a) {

	const ll n = a.size();
	vector<ll> A(n, INT_MAX);
	vector<ll> id(n);
	for (int i = 0; i < n; ++i) {
		id[i] = distance(A.begin(), lower_bound(A.begin(), A.end(), a[i]));
		A[id[i]] = a[i];
	}
	ll m = *max_element(id.begin(), id.end());
	vector<ll> b(m + 1);
	for (int i = n - 1; i >= 0; --i)
		if (id[i] == m) b[m--] = a[i];
	return b;
}

bool z_algorithm(string& str, vector<int>& z, ll s) {

	const int L = str.size();
	z.resize(str.size());
	for (int i = 1, left = 0, right = 0; i < L; i++) {
		if (i > right) {
			left = right = i;
			for (; right < L && str[right - left] == str[right]; right++);
			z[i] = right - left;
			right--;
		}
		else {
			int k = i - left;
			if (z[k] < right - i + 1) {
				z[i] = z[k];
			}
			else {
				left = i;
				for (; right < L && str[right - left] == str[right]; right++);
				z[i] = right - left;
				right--;
			}
		}
		if (z[i] == s)return true;
	}
	return false;
}
bool z_algorithm(string& str, vector<int>& z) {

	const int L = str.size();
	z.resize(str.size());
	for (int i = 1, left = 0, right = 0; i < L; i++) {
		if (i > right) {
			left = right = i;
			for (; right < L && str[right - left] == str[right]; right++);
			z[i] = right - left;
			right--;
		}
		else {
			int k = i - left;
			if (z[k] < right - i + 1) {
				z[i] = z[k];
			}
			else {
				left = i;
				for (; right < L && str[right - left] == str[right]; right++);
				z[i] = right - left;
				right--;
			}
		}
	}
	return true;
}




struct RollingHash {
	static const int base1 = 1007, base2 = 2009;
	static const int mod1 = 1000000007, mod2 = 1000000009;
	vector<long long> hash1, hash2, power1, power2;

	

	RollingHash(const string& S) {
		int n = (int)S.size();
		hash1.assign(n + 1, 0);
		hash2.assign(n + 1, 0);
		power1.assign(n + 1, 1);
		power2.assign(n + 1, 1);
		for (int i = 0; i < n; ++i) {
			hash1[i + 1] = (hash1[i] * base1 + S[i]) % mod1;
			hash2[i + 1] = (hash2[i] * base2 + S[i]) % mod2;
			power1[i + 1] = (power1[i] * base1) % mod1;
			power2[i + 1] = (power2[i] * base2) % mod2;
		}
	}

	

	inline pair<long long, long long> get(int l, int r) const {
		long long res1 = hash1[r] - hash1[l] * power1[r - l] % mod1;
		if (res1 < 0) res1 += mod1;
		long long res2 = hash2[r] - hash2[l] * power2[r - l] % mod2;
		if (res2 < 0) res2 += mod2;
		return { res1, res2 };
	}

	

	inline int getLCP(int a, int b) const {
		int len = min((int)hash1.size() - a, (int)hash1.size() - b);
		int low = 0, high = len;
		while (high - low > 1) {
			int mid = (low + high) >> 1;
			if (get(a, a + mid) != get(b, b + mid)) high = mid;
			else low = mid;
		}
		return low;
	}
};


ll mod_pow(ll x, ll n, ll mod) {
	ll res = 1LL;
	while (n > 0) {
		if (n & 1) res = res * x % mod;
		x = x * x % mod;
		n >>= 1;
	}
	return res;
}

ll mod_inv(ll x, ll mod) {
	return mod_pow(x, mod - 2, mod);
}


class Combination {
public:
	Array fact;
	Array inv;
	ll mod;
	ll mod_inv(ll x) {
		ll n = mod - 2LL;
		ll res = 1LL;
		while (n > 0) {
			if (n & 1) res = res * x % mod;
			x = x * x % mod;
			n >>= 1;
		}
		return res;
	}
	ll nCr(ll n, ll r) {
		return ((fact[n] * inv[r] % mod) * inv[n - r]) % mod;
	}
	ll nPr(ll n, ll r) {
		return (fact[n] * inv[n - r]) % mod;
	}
	ll nHr(ll n, ll r) {
		return nCr(r + n - 1, r);
	}
	Combination(ll n, ll _mod) {
		mod = _mod;
		fact.resize(n + 1);
		fact[0] = 1;
		REP(i, n) {
			fact[i + 1] = (fact[i] * (i + 1LL)) % mod;
		}
		inv.resize(n + 1);
		inv[n] = mod_inv(fact[n]);
		for (int i = n; i > 0; i--) {
			inv[i - 1] = inv[i] * i % mod;
		}
	}
};


ll gcd(ll m, ll n) {
	if (n == 0)return m;
	return gcd(n, m % n);
}


ll lcm(ll m, ll n) {
	return m / gcd(m, n) * n;
}


Matrix mIdentity(ll n) {
	Matrix A(n, Array(n));
	for (int i = 0; i < n; ++i) A[i][i] = 1;
	return A;
}

Matrix mMul(const Matrix& A, const Matrix& B) {
	Matrix C(A.size(), Array(B[0].size()));
	for (int i = 0; i < C.size(); ++i)
		for (int j = 0; j < C[i].size(); ++j)
			for (int k = 0; k < A[i].size(); ++k)
				(C[i][j] += (A[i][k] % MOD) * (B[k][j] % MOD)) %= MOD;
	return C;
}


Matrix mPow(const Matrix& A, ll e) {
	return e == 0 ? mIdentity(A.size()) :
		e % 2 == 0 ? mPow(mMul(A, A), e / 2) : mMul(A, mPow(A, e - 1));
}

template <class T>class RectangleSum {
public:
	vector<vector<T>> sum;
	T GetSum(int left, int right, int top, int bottom) { 

		T res = sum[bottom][right];
		if (left > 0) res -= sum[bottom][left - 1];
		if (top > 0) res -= sum[top - 1][right];
		if (left > 0 && top > 0) res += sum[top - 1][left - 1];
		return res;
	}
	RectangleSum(const vector<vector<T>>& s, int h, int w) {
		sum.resize(h);
		for (int i = 0; i < h; i++) sum[i].resize(w, 0);
		for (int y = 0; y < h; y++) {
			for (int x = 0; x < w; x++) {
				sum[y][x] = s[y][x];
				if (y > 0) sum[y][x] += sum[y - 1][x];
				if (x > 0) sum[y][x] += sum[y][x - 1];
				if (y > 0 && x > 0) sum[y][x] -= sum[y - 1][x - 1];
			}
		}
	}
};



ll _garner(Array& xs, Array& mods) {
	int M = xs.size();

	Array coeffs(M, 1), constants(M, 0);

	for (int i = 0; i < M - 1; ++i) {
		ll mod_i = mods[i];
		

		ll v = (xs[i] - constants[i] + mod_i) % mod_i;
		v = (v * mod_pow(coeffs[i], mod_i - 2, mod_i)) % mod_i;

		for (int j = i + 1; j < M; j++) {
			ll mod_j = mods[j];
			constants[j] = (constants[j] + coeffs[j] * v) % mod_j;
			coeffs[j] = (coeffs[j] * mod_i) % mod_j;
		}
	}

	return constants.back();
}


template<typename T>
inline void bit_reverse(vector<T>& a) {
	int n = a.size();
	int i = 0;
	for (int j = 1; j < n - 1; ++j) {
		for (int k = n >> 1; k > (i ^= k); k >>= 1);
		if (j < i) swap(a[i], a[j]);
	}
}

template<long long mod, long long primitive_root>
class NTT {
public:
	long long get_mod() { return mod; }

	void _ntt(vector<long long>& a, int sign) {
		const int n = a.size();
		assert((n ^ (n & -n)) == 0); 


		const long long g = primitive_root; 


		long long tmp = (mod - 1) * mod_pow(n, mod - 2, mod) % mod; 

		long long h = mod_pow(g, tmp, mod); 

		if (sign == -1) h = mod_pow(h, mod - 2, mod);

		bit_reverse(a);

		for (int m = 1; m < n; m <<= 1) {
			const int m2 = 2 * m;
			long long _base = mod_pow(h, n / m2, mod);
			long long _w = 1;
			for (int x = 0; x < m; ++x) {
				for (int s = x; s < n; s += m2) {
					long long u = a[s];
					long long d = (a[s + m] * _w) % mod;
					a[s] = (u + d) % mod;
					a[s + m] = (u - d + mod) % mod;
				}
				_w = (_w * _base) % mod;
			}
		}
	}
	void ntt(vector<long long>& input) {
		_ntt(input, 1);
	}
	void intt(vector<long long>& input) {
		_ntt(input, -1);

		const long long n_inv = mod_pow(input.size(), mod - 2, mod);
		for (auto& x : input) x = (x * n_inv) % mod;
	}

	

	vector<long long> convolution(const vector<long long>& a, const vector<long long>& b) {
		int result_size = a.size() + b.size() - 1;
		int n = 1; while (n < result_size) n <<= 1;

		vector<long long> _a = a, _b = b;
		_a.resize(n, 0);
		_b.resize(n, 0);

		ntt(_a);
		ntt(_b);
		for (int i = 0; i < n; ++i) _a[i] = (_a[i] * _b[i]) % mod;
		intt(_a);

		_a.resize(result_size);
		return _a;
	}
};

vector<long long> convolution_ntt(vector<long long>& a, vector<long long>& b, long long mod = 1224736769LL) {
	for (auto& x : a) x %= mod;
	for (auto& x : b) x %= mod;

	ll maxval = max(a.size(), b.size()) * *max_element(a.begin(), a.end()) * *max_element(b.begin(), b.end());
	if (maxval < 1224736769) {
		NTT<1224736769, 3> ntt3;
		return ntt3.convolution(a, b);
	}

	NTT<167772161, 3> ntt1;
	NTT<469762049, 3> ntt2;
	NTT<1224736769, 3> ntt3;

	vector<long long> x1 = ntt1.convolution(a, b);
	vector<long long> x2 = ntt2.convolution(a, b);
	vector<long long> x3 = ntt3.convolution(a, b);

	vector<long long> ret(x1.size());
	vector<long long> mods{ 167772161, 469762049, 1224736769, mod };
	for (int i = 0; i < x1.size(); ++i) {
		vector<long long> xs{ x1[i], x2[i], x3[i], 0 };
		ret[i] = _garner(xs, mods);
	}

	return ret;
}

int popcount3(int x) {
	x = (x & 0x55555555) + (x >> 1 & 0x55555555);
	x = (x & 0x33333333) + (x >> 2 & 0x33333333);
	x = (x & 0x0F0F0F0F) + (x >> 4 & 0x0F0F0F0F);
	x = (x & 0x00FF00FF) + (x >> 8 & 0x00FF00FF);
	x = (x & 0x0000FFFF) + (x >> 16 & 0x0000FFFF);

	return x;
}

template<typename T>
void rowReduction(vector<T> mat, vector<T>& basis) {

	for (auto e : mat) {
		for (auto b : basis)
			chmin(e, e ^ b);
		if (e)
			basis.push_back(e);
	}
	sort(all(basis), greater<T>());
}


struct SegT {
private:
	int n; vector<ll> node, lazy;
	const ll init_c = 0;
public:
	SegT(int sz) {
		n = 1;
		while (n < sz)n <<= 1;
		node.resize(2 * n - 1, 0);
		lazy.resize(2 * n - 1, 0);
	}
	ll f(ll a, ll b) {
		return max(a, b);
	}
	void eval(int k, int l, int r) {
		node[k] += lazy[k];
		if (r - l > 1) {
			lazy[2 * k + 1] += lazy[k];
			lazy[2 * k + 2] += lazy[k];
		}
		lazy[k] = 0;
	}
	void add(ll x, int a, int b, int k = 0, int l = 0, int r = -1) {
		if (r < 0)r = n;
		eval(k, l, r);
		if (r <= a || b <= l)return;
		if (a <= l && r <= b) {
			lazy[k] += x; eval(k, l, r);
		}
		else {
			add(x, a, b, k * 2 + 1, l, (l + r) / 2);
			add(x, a, b, k * 2 + 2, (l + r) / 2, r);
			node[k] = f(node[k * 2 + 1], node[k * 2 + 2]);
		}
	}
	ll query(int a, int b, int k = 0, int l = 0, int r = -1) {
		if (r < 0)r = n;
		eval(k, l, r);
		if (r <= a || b <= l)return init_c;
		if (a <= l && r <= b)return node[k];
		else {
			ll vl = query(a, b, k * 2 + 1, l, (l + r) / 2);
			ll vr = query(a, b, k * 2 + 2, (l + r) / 2, r);
			return f(vl, vr);
		}
	}
};



int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	ll n;
	cin >> n;
	Array a(101010,0);
	ll ans = 0;
	REP(i, n) {
		ll temp;
		cin >> temp;
		chmax(ans, temp);
		a[temp] = 1;
	}
	Array prime(101010, 1);
	Array u(101010, 1);
	Matrix div(101010,Array(1,1));
	rep(i, 2, 101010) {
		for (int j = i; j < 101010; j += i)div[j].push_back(i);
		if (prime[i] == 0)continue;
		u[i] = -1;
		for (int j = i * 2; j < 101010; j += i)prime[j] = 0, u[j] *= -1;
		for (ll j =(ll) i * i; j < 101010; j +=(ll) i * i) u[j] = 0;
	}
	Array d(101010, 0);
	
	
	rep(g, 1, 101010) {
		Array temp;
		for (int i = g; i < 101010; i += g)if (a[i] == 1)temp.push_back(i/g);
		stack<ll> sta;
		while (temp.size()) {
			ll num = temp.back();
			temp.pop_back();
			ll cnt = 0;
			for (auto i : div[num])cnt += u[i] * d[i], d[i]++;
			while (cnt) {
				ll t = sta.top();
				sta.pop();
				for (auto i : div[t])d[i]--;
				if (gcd(t, num) == 1)chmax(ans, t * num * g), cnt--;
			}
			sta.push(num);
		}
		while (sta.size()) {
			ll t = sta.top();
			sta.pop();
			for (auto i : div[t])d[i]--;
		}
	}
	
	cout << ans << "\n";




	return 0;
}