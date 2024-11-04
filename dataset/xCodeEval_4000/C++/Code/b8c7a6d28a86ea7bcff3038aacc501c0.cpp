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
#include<complex>
#include<array>
#include<numeric>
#include<functional>
#include<random>


using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i,m,n) for(ll (i)=(ll)(m);i<(ll)(n);i++)
#define REP(i,n) rep(i,0,n)
#define all(hoge) (hoge).begin(),(hoge).end()
typedef pair<ll, ll> P;


constexpr long double m_pi = 3.1415926535897932L;
constexpr ll MOD = 1000000007;
constexpr ll INF = 1LL << 61;
constexpr long double EPS = 1e-10;
template<typename T> using vector2 = vector<vector<T>>;
template<typename T> using vector3 = vector<vector2<T>>;
typedef vector<ll> Array;
typedef vector<Array> Matrix;
string operator*(const string& s, int k) {
	if (k == 0) return "";
	string p = (s + s) * (k / 2);
	if (k % 2 == 1) p += s;
	return p;
}

template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; }return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; }return false; }

struct Edge {

	int to, rev; ll cap;
	Edge(int _to, ll _cap, int _rev) {
		to = _to; cap = _cap; rev = _rev;
	}
};
typedef vector<Edge> Edges;
typedef vector<Edges> Graph;
void add_edge(Graph& G, int from, int to, ll cap, bool revFlag, ll revCap) {

	G[from].push_back(Edge(to, cap, (ll)G[to].size() + (from == to)));
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
			d[i][j] = ((i != j) ? INF : 0);
		}
	}
	REP(i, G.size()) {
		REP(j, G[i].size()) {
			chmin(d[i][G[i][j].to], G[i][j].cap);
		}
	}
	REP(i, G.size()) {
		REP(j, G.size()) {
			REP(k, G.size()) {
				if (d[j][i] != INF && d[i][k] != INF)chmin(d[j][k], d[j][i] + d[i][k]);
			}
		}
	}
}
bool tsort(Graph& graph, vector<int>& order) {

	int n = graph.size(), k = 0;
	vector<int> in(n);
	for (auto& es : graph)
		for (auto& e : es)in[e.to]++;
	priority_queue<int, vector<int>, greater<int>> que;
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
class Lca {
public:
	const int n = 0;
	const int log2_n = 0;
	std::vector<std::vector<int>> parent;
	std::vector<int> depth;

	Lca() {}

	Lca(const Graph& g, int root)
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

class UnionFind {
	vector<int> data;
	int n;
public:
	UnionFind(int size) : data(size, -1), n(size) { }
	bool merge(int x, int y) {

		x = root(x); y = root(y);
		if (x != y) {
			if (data[y] < data[x]) swap(x, y);
			data[x] += data[y]; data[y] = x;
		}
		n -= (x != y);
		return x != y;
	}
	bool same(int x, int y) {

		return root(x) == root(y);
	}
	int root(int x) {

		return data[x] < 0 ? x : data[x] = root(data[x]);
	}
	int size(int x) {

		return -data[root(x)];
	}
	int num() {

		return n;
	}
};

template<typename T, typename F>
class SegmentTree {
private:
	T identity;
	F merge;
	ll n;
	vector<T> dat;
public:
	SegmentTree(F f, T id, vector<T> v) :merge(f), identity(id) {
		int _n = v.size();
		n = 1;
		while (n < _n)n *= 2;
		dat.resize(2 * n - 1, identity);
		REP(i, _n)dat[n + i - 1] = v[i];
		for (int i = n - 2; i >= 0; i--)dat[i] = merge(dat[i * 2 + 1], dat[i * 2 + 2]);
	}
	SegmentTree(F f, T id, int _n) :merge(f), identity(id) {
		n = 1;
		while (n < _n)n *= 2;
		dat.resize(2 * n - 1, identity);
	}
	void set_val(int i, T x) {
		i += n - 1;
		dat[i] = x;
		while (i > 0) {
			i = (i - 1) / 2;
			dat[i] = merge(dat[i * 2 + 1], dat[i * 2 + 2]);
		}
	}
	T query(int l, int r) {
		T left = identity, right = identity;
		l += n - 1; r += n - 1;
		while (l < r) {
			if ((l & 1) == 0)left = merge(left, dat[l]);
			if ((r & 1) == 0)right = merge(dat[r - 1], right);
			l = l / 2;
			r = (r - 1) / 2;
		}
		return merge(left, right);
	}
};


template< typename T >
class FenwickTree {
	vector< T > data;
	int n;
	int p;
public:
	FenwickTree(int n) :n(n) {
		data.resize(n + 1LL, 0);
		p = 1;
		while (p < data.size())p *= 2;
	}
	T sum(int k) {
		T ret = 0;
		for (; k > 0; k -= k & -k) ret += data[k];
		return (ret);
	}

	T sum(int a, int b) { return sum(b) - sum(a); }


	void add(int k, T x) {
		for (++k; k <= n; k += k & -k) data[k] += x;
	}

	int lower_bound(ll w) {
		if (w <= 0)return -1;
		int x = 0;
		for (int k = p / 2; k > 0; k /= 2) {
			if (x + k <= n && data[x + k] < w)w -= data[x + k], x += k;
		}
		return x;
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

void prime_factorization(ll n, vector<P>& ret) {
	for (ll i = 2; i * i <= n; i++) {
		if (n % i == 0) {
			ret.push_back({ i,0 });
			while (n % i == 0) {
				n /= i;
				ret[ret.size() - 1].second++;
			}
		}
	}
	if (n != 1)ret.push_back({ n,1 });
}

inline ll mod_pow(ll x, ll n, ll mod) {
	ll res = 1;
	while (n > 0) {
		if (n & 1) res = res * x % mod;
		x = x * x % mod;
		n >>= 1;
	}
	return res;
}

inline ll mod_inv(ll x, ll mod) {
	return mod_pow(x, mod - 2, mod);
}

class Combination {
public:
	Array fact;
	Array fact_inv;
	ll mod;
	

	ll nCr(ll n, ll r) {
		if (n < r)return 0;
		if (n < mod)return ((fact[n] * fact_inv[r] % mod) * fact_inv[n - r]) % mod;

		ll ret = 1;
		while (n || r) {
			ll _n = n % mod, _r = r % mod;
			n /= mod; r /= mod;
			(ret *= nCr(_n, _r)) %= mod;
		}
		return ret;
	}
	ll nPr(ll n, ll r) {
		return (fact[n] * fact_inv[n - r]) % mod;
	}
	ll nHr(ll n, ll r) {
		return nCr(r + n - 1, r);
	}
	Combination(ll _n, ll _mod) {
		mod = _mod;
		ll n = min(_n + 1, mod);
		fact.resize(n);
		fact[0] = 1;
		REP(i, n - 1) {
			fact[i + 1] = (fact[i] * (i + 1LL)) % mod;
		}
		fact_inv.resize(n);
		fact_inv[n - 1] = mod_inv(fact[n - 1], mod);
		for (int i = n - 1; i > 0; i--) {
			fact_inv[i - 1] = fact_inv[i] * i % mod;
		}
	}
};

ll popcount(ll x) {
	x = (x & 0x5555555555555555) + (x >> 1 & 0x5555555555555555);
	x = (x & 0x3333333333333333) + (x >> 2 & 0x3333333333333333);
	x = (x & 0x0F0F0F0F0F0F0F0F) + (x >> 4 & 0x0F0F0F0F0F0F0F0F);
	x = (x & 0x00FF00FF00FF00FF) + (x >> 8 & 0x00FF00FF00FF00FF);
	x = (x & 0x0000FFFF0000FFFF) + (x >> 16 & 0x0000FFFF0000FFFF);
	x = (x & 0x00000000FFFFFFFF) + (x >> 32 & 0x00000000FFFFFFFF);

	return x;
}

constexpr ll mod = 998244353;



std::vector<int> sa_naive(const std::vector<int>& s) {
	int n = int(s.size());
	std::vector<int> sa(n);
	std::iota(sa.begin(), sa.end(), 0);
	std::sort(sa.begin(), sa.end(), [&](int l, int r) {
		if (l == r) return false;
		while (l < n && r < n) {
			if (s[l] != s[r]) return s[l] < s[r];
			l++;
			r++;
		}
		return l == n;
		});
	return sa;
}

std::vector<int> sa_doubling(const std::vector<int>& s) {
	int n = int(s.size());
	std::vector<int> sa(n), rnk = s, tmp(n);
	std::iota(sa.begin(), sa.end(), 0);
	for (int k = 1; k < n; k *= 2) {
		auto cmp = [&](int x, int y) {
			if (rnk[x] != rnk[y]) return rnk[x] < rnk[y];
			int rx = x + k < n ? rnk[x + k] : -1;
			int ry = y + k < n ? rnk[y + k] : -1;
			return rx < ry;
		};
		std::sort(sa.begin(), sa.end(), cmp);
		tmp[sa[0]] = 0;
		for (int i = 1; i < n; i++) {
			tmp[sa[i]] = tmp[sa[i - 1]] + (cmp(sa[i - 1], sa[i]) ? 1 : 0);
		}
		std::swap(tmp, rnk);
	}
	return sa;
}









template <int THRESHOLD_NAIVE = 10, int THRESHOLD_DOUBLING = 40>
std::vector<int> sa_is(const std::vector<int>& s, int upper) {
	int n = int(s.size());
	if (n == 0) return {};
	if (n == 1) return { 0 };
	if (n == 2) {
		if (s[0] < s[1]) {
			return { 0, 1 };
		}
		else {
			return { 1, 0 };
		}
	}
	if (n < THRESHOLD_NAIVE) {
		return sa_naive(s);
	}
	if (n < THRESHOLD_DOUBLING) {
		return sa_doubling(s);
	}

	std::vector<int> sa(n);
	std::vector<bool> ls(n);
	for (int i = n - 2; i >= 0; i--) {
		ls[i] = (s[i] == s[i + 1]) ? ls[i + 1] : (s[i] < s[i + 1]);
	}
	std::vector<int> sum_l(upper + 1), sum_s(upper + 1);
	for (int i = 0; i < n; i++) {
		if (!ls[i]) {
			sum_s[s[i]]++;
		}
		else {
			sum_l[s[i] + 1]++;
		}
	}
	for (int i = 0; i <= upper; i++) {
		sum_s[i] += sum_l[i];
		if (i < upper) sum_l[i + 1] += sum_s[i];
	}

	auto induce = [&](const std::vector<int>& lms) {
		std::fill(sa.begin(), sa.end(), -1);
		std::vector<int> buf(upper + 1);
		std::copy(sum_s.begin(), sum_s.end(), buf.begin());
		for (auto d : lms) {
			if (d == n) continue;
			sa[buf[s[d]]++] = d;
		}
		std::copy(sum_l.begin(), sum_l.end(), buf.begin());
		sa[buf[s[n - 1]]++] = n - 1;
		for (int i = 0; i < n; i++) {
			int v = sa[i];
			if (v >= 1 && !ls[v - 1]) {
				sa[buf[s[v - 1]]++] = v - 1;
			}
		}
		std::copy(sum_l.begin(), sum_l.end(), buf.begin());
		for (int i = n - 1; i >= 0; i--) {
			int v = sa[i];
			if (v >= 1 && ls[v - 1]) {
				sa[--buf[s[v - 1] + 1]] = v - 1;
			}
		}
	};

	std::vector<int> lms_map(n + 1, -1);
	int m = 0;
	for (int i = 1; i < n; i++) {
		if (!ls[i - 1] && ls[i]) {
			lms_map[i] = m++;
		}
	}
	std::vector<int> lms;
	lms.reserve(m);
	for (int i = 1; i < n; i++) {
		if (!ls[i - 1] && ls[i]) {
			lms.push_back(i);
		}
	}

	induce(lms);

	if (m) {
		std::vector<int> sorted_lms;
		sorted_lms.reserve(m);
		for (int v : sa) {
			if (lms_map[v] != -1) sorted_lms.push_back(v);
		}
		std::vector<int> rec_s(m);
		int rec_upper = 0;
		rec_s[lms_map[sorted_lms[0]]] = 0;
		for (int i = 1; i < m; i++) {
			int l = sorted_lms[i - 1], r = sorted_lms[i];
			int end_l = (lms_map[l] + 1 < m) ? lms[lms_map[l] + 1] : n;
			int end_r = (lms_map[r] + 1 < m) ? lms[lms_map[r] + 1] : n;
			bool same = true;
			if (end_l - l != end_r - r) {
				same = false;
			}
			else {
				while (l < end_l) {
					if (s[l] != s[r]) {
						break;
					}
					l++;
					r++;
				}
				if (l == n || s[l] != s[r]) same = false;
			}
			if (!same) rec_upper++;
			rec_s[lms_map[sorted_lms[i]]] = rec_upper;
		}

		auto rec_sa =
			sa_is<THRESHOLD_NAIVE, THRESHOLD_DOUBLING>(rec_s, rec_upper);

		for (int i = 0; i < m; i++) {
			sorted_lms[i] = lms[rec_sa[i]];
		}
		induce(sorted_lms);
	}
	return sa;
}


std::vector<int> suffix_array(const std::vector<int>& s, int upper) {
	assert(0 <= upper);
	for (int d : s) {
		assert(0 <= d && d <= upper);
	}
	auto sa = sa_is(s, upper);
	return sa;
}

template <class T> std::vector<int> suffix_array(const std::vector<T>& s) {
	int n = int(s.size());
	std::vector<int> idx(n);
	iota(idx.begin(), idx.end(), 0);
	sort(idx.begin(), idx.end(), [&](int l, int r) { return s[l] < s[r]; });
	std::vector<int> s2(n);
	int now = 0;
	for (int i = 0; i < n; i++) {
		if (i && s[idx[i - 1]] != s[idx[i]]) now++;
		s2[idx[i]] = now;
	}
	return sa_is(s2, now);
}

std::vector<int> suffix_array(const std::string& s) {
	int n = int(s.size());
	std::vector<int> s2(n);
	for (int i = 0; i < n; i++) {
		s2[i] = s[i];
	}
	return sa_is(s2, 255);
}









template <class T>
std::vector<int> lcp_array(const std::vector<T>& s,
	const std::vector<int>& sa) {
	int n = int(s.size());
	assert(n >= 1);
	std::vector<int> rnk(n);
	for (int i = 0; i < n; i++) {
		rnk[sa[i]] = i;
	}
	std::vector<int> lcp(n - 1);
	int h = 0;
	for (int i = 0; i < n; i++) {
		if (h > 0) h--;
		if (rnk[i] == 0) continue;
		int j = sa[rnk[i] - 1];
		for (; j + h < n && i + h < n; h++) {
			if (s[j + h] != s[i + h]) break;
		}
		lcp[rnk[i] - 1] = h;
	}
	return lcp;
}



std::vector<int> lcp_array(const std::string& s, const std::vector<int>& sa) {
	int n = int(s.size());
	std::vector<int> s2(n);
	for (int i = 0; i < n; i++) {
		s2[i] = s[i];
	}
	return lcp_array(s2, sa);
}


int main() {
	ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);

	ll n;
	cin >> n;
	string s, t;
	cin >> s >> t;
	reverse(all(s));
	reverse(all(t));
	auto sa = suffix_array(s);
	auto lcp = lcp_array(s, sa);
	ll ans = 0;
	REP(i, n)if (t[i] == '0')chmax(ans, n - i);
	auto f = [](int a, int b) {return min(a, b); };
	SegmentTree seg(f, INT_MAX, lcp);
	Array use;
	REP(i, n) if (t[sa[i]] == '0')use.push_back(i);
	if (use.size() < 2) {
		cout << ans << "\n";
		return 0;
	}
	Array use_lcp(use.size() - 1);
	REP(i, use.size() - 1) use_lcp[i] = seg.query(use[i], use[i + 1]);
	stack<P> st;
	st.push({ 0,-1 });
	REP(i, use_lcp.size()) {
		ll j = i;
		while (st.top().first > use_lcp[i]) {
			chmax(ans, (i - st.top().second + 1) * st.top().first);
			j = st.top().second;
			st.pop();
		}
		if(st.top().first != use_lcp[i])st.push({ use_lcp[i],j });
	}
	while (st.top().first != 0) {
		chmax(ans, (ll)(use_lcp.size() - st.top().second + 1)* st.top().first);
		st.pop();
	}
	cout << ans << "\n";

	return 0;
}