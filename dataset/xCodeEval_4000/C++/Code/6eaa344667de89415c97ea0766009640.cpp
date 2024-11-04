#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include<iostream>
#include<string>
#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
#include<functional>
#include<iomanip>
#include<queue>
#include<ciso646>
#include<random>
#include<map>
#include<set>
#include<bitset>
#include<stack>
#include<unordered_map>
#include<unordered_set>
#include<utility>
#include<cassert>
#include<complex>
#include<numeric>
#include<array>
#include<chrono>
using namespace std;



typedef long long ll;

typedef unsigned long long ul;
typedef unsigned int ui;
constexpr ll mod = 998244353;


const ll INF = mod * mod;
typedef pair<int, int>P;

#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
#define all(v) (v).begin(),(v).end()
typedef pair<ll, ll> LP;

template<typename T>
void chmin(T& a, T b) {
	a = min(a, b);
}
template<typename T>
void chmax(T& a, T b) {
	a = max(a, b);
}
template<typename T>
void cinarray(vector<T>& v) {
	rep(i, v.size())cin >> v[i];
}
template<typename T>
void coutarray(vector<T>& v) {
	rep(i, v.size()) {
		if (i > 0)cout << " "; cout << v[i];
	}
	cout << "\n";
}
ll mod_pow(ll x, ll n, ll m = mod) {
	if (n < 0) {
		ll res = mod_pow(x, -n, m);
		return mod_pow(res, m - 2, m);
	}
	if (abs(x) >= m)x %= m;
	if (x < 0)x += m;
	

	ll res = 1;
	while (n) {
		if (n & 1)res = res * x % m;
		x = x * x % m; n >>= 1;
	}
	return res;
}


struct modint {
	int n;
	modint() :n(0) { ; }
	modint(ll m) {
		if (m < 0 || mod <= m) {
			m %= mod; if (m < 0)m += mod;
		}
		n = m;
	}
	operator int() { return n; }
};
bool operator==(modint a, modint b) { return a.n == b.n; }
bool operator<(modint a, modint b) { return a.n < b.n; }
modint operator+=(modint& a, modint b) { a.n += b.n; if (a.n >= mod)a.n -= (int)mod; return a; }
modint operator-=(modint& a, modint b) { a.n -= b.n; if (a.n < 0)a.n += (int)mod; return a; }
modint operator*=(modint& a, modint b) { a.n = ((ll)a.n * b.n) % mod; return a; }
modint operator+(modint a, modint b) { return a += b; }
modint operator-(modint a, modint b) { return a -= b; }
modint operator*(modint a, modint b) { return a *= b; }
modint operator^(modint a, ll n) {
	if (n == 0)return modint(1);
	modint res = (a * a) ^ (n / 2);
	if (n % 2)res = res * a;
	return res;
}

ll inv(ll a, ll p) {
	return (a == 1 ? 1 : (1 - p * inv(p % a, a)) / a + p);
}
modint operator/(modint a, modint b) { return a * modint(inv(b, mod)); }
modint operator/=(modint& a, modint b) { a = a / b; return a; }
const int max_n = 1 << 21;
modint fact[max_n], factinv[max_n];
void init_f() {
	fact[0] = modint(1);
	for (int i = 0; i < max_n - 1; i++) {
		fact[i + 1] = fact[i] * modint(i + 1);
	}
	factinv[max_n - 1] = modint(1) / fact[max_n - 1];
	for (int i = max_n - 2; i >= 0; i--) {
		factinv[i] = factinv[i + 1] * modint(i + 1);
	}
}
modint comb(int a, int b) {
	if (a < 0 || b < 0 || a < b)return 0;
	return fact[a] * factinv[b] * factinv[a - b];
}
modint combP(int a, int b) {
	if (a < 0 || b < 0 || a < b)return 0;
	return fact[a] * factinv[a - b];
}

ll gcd(ll a, ll b) {
	a = abs(a); b = abs(b);
	if (a < b)swap(a, b);
	while (b) {
		ll r = a % b; a = b; b = r;
	}
	return a;
}
using ld = long double;


typedef pair<ld, ld> LDP;
const ld eps = 1e-10;
const ld pi = acosl(-1.0);
template<typename T>
void addv(vector<T>& v, int loc, T val) {
	if (loc >= v.size())v.resize(loc + 1, 0);
	v[loc] += val;
}




template<typename T>
auto prev_itr(set<T>& st, T val) {
	auto res = st.lower_bound(val);
	if (res == st.begin())return st.end();
	res--; return res;
}



template<typename T>
auto next_itr(set<T>& st, T val) {
	auto res = st.lower_bound(val);
	return res;
}
using mP = pair<modint, modint>;
mP operator+(mP a, mP b) {
	return { a.first + b.first,a.second + b.second };
}
mP operator+=(mP& a, mP b) {
	a = a + b; return a;
}
mP operator-(mP a, mP b) {
	return { a.first - b.first,a.second - b.second };
}
mP operator-=(mP& a, mP b) {
	a = a - b; return a;
}
LP operator+(LP a, LP b) {
	return { a.first + b.first,a.second + b.second };
}
LP operator+=(LP& a, LP b) {
	a = a + b; return a;
}
LP operator-(LP a, LP b) {
	return { a.first - b.first,a.second - b.second };
}
LP operator-=(LP& a, LP b) {
	a = a - b; return a;
}

mt19937 mt(time(0));

const string drul = "DRUL";
string senw = "SENW";


int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };



using ar = array<int, 5>;
struct SegT {
private:
	int sz; vector<array<int,5>> node;
	const ar init_c = { -1,-1,-1,-1,-1 };
public:
	SegT(int n) {
		sz = 1;
		while (sz < n)sz *= 2;
		node.resize(2 * sz - 1, init_c);
	}
	SegT();
	ar f(ar a, ar b) {
		if (a[0] < 0)return b;
		if (b[0] < 0)return a;
		ar res;
		res[0] = b[0];
		if (b[1] == a[0]) {
			res[1] = a[1];
			res[3] = b[3] + a[3];
		}
		else {
			res[1] = a[2];
			res[3] = b[3] + a[4];
		}
		if (b[2] == a[0]) {
			res[2] = a[1];
			res[4] = b[4] + a[3];
		}
		else {
			res[2] = a[2];
			res[4] = b[4] + a[4];
		}
		return res;
	}
	void update(int k, ar a) {
		k += sz - 1;
		node[k] = a;
		while (k > 0) {
			k = (k - 1) / 2;
			node[k] = f(node[k * 2 + 1], node[k * 2 + 2]);
		}
	}
	ar query(int a, int b, int k = 0, int l = 0, int r = -1) {
		chmin(b, sz);
		if (r < 0)r = sz;
		if (r <= a || b <= l)return init_c;
		else if (a <= l && r <= b)return node[k];
		else {
			ar vl = query(a, b, k * 2 + 1, l, (l + r) / 2);
			ar vr = query(a, b, k * 2 + 2, (l + r) / 2, r);
			return f(vl, vr);
		}
	}
};
P calc_val(ar a, int b) {
	if (b == a[0]) {
		return { a[1],a[3] };
	}
	return { a[2],a[4] };
}

int cnt[1 << 19][21];
int par[1 << 19];
ar getcur(int id) {
	int pre = -1;
	ar res; res[0] = -1;
	rep(i, 21) {
		if (cnt[id][i] == 0) {
			if (pre < 0) {
				pre = i;
			}
			else {
				res = { pre,i,pre,i,pre };
				break;
			}
		}
	}
	assert(res[0] >= 0);
	return res;
}
struct edge {
	int to;
};
using edges = vector<edge>;
using Graph = vector<edges>;
struct HLDecomposition {
	struct Chain {
		int depth;
		P parent;

		vector<P> child;

		vector<int> mapfrom;
		SegT stree;

		Chain() { ; }
		Chain(int n) :stree(n) { ; }
	};
	Graph baseG;
	vector<Chain> chains;
	vector<P> mapto;

	vector<vector<int>> mapfrom;


	HLDecomposition() { ; }
	HLDecomposition(const Graph &g) {
		baseG = g;
		const int n = baseG.size();
		mapto = vector<P>(n, P{ -1,-1 });
		mapfrom.clear();
		vector<int> sz(n, 0);
		int start = 0;
		

		

		

		size_check_bfs(start, sz);
		decomposition(start, start, 0, 0, 0, sz);
	}
	int depth(int t) {
		return chains[mapto[t].first].depth;
	}

private:
	void size_check_bfs(int start, vector<int> &sz) {
		const int n = baseG.size();
		queue<P> que;
		que.push({ start,start });
		int cnt = 0; vector<int> ord(n, -1);
		while (!que.empty()) {
			int from, parent;
			tie(from, parent) = que.front(); que.pop();
			ord[cnt++] = from;
			for (edge e : baseG[from]) {
				if (e.to == parent)continue;
				que.push({ e.to,from });
			}
		}
		

		reverse(all(ord));
		rep(i, n) {
			int from = ord[i];
			sz[from] = 1; for (edge e : baseG[from])sz[from] += sz[e.to];
		}
	}
	int decomposition(int from, int parent, int depth, int pnumber, int pindex, const vector<int> &sz) {
		vector<int> seq;
		bfs(from, parent, seq, sz);
		const int c = chains.size();
		chains.push_back(Chain((int)seq.size()));
		

		chains[c].depth = depth;
		chains[c].parent = { pnumber,pindex };
		rep(i, seq.size()) {
			mapto[seq[i]] = { c,i };
			chains[c].mapfrom.push_back(seq[i]);
		}
		mapfrom.push_back(chains[c].mapfrom);
		rep(i, seq.size()) {
			for (edge e : baseG[seq[i]]) {
				if (mapto[e.to].first != -1)continue;
				int nc = decomposition(e.to, seq[i], depth + 1, c, i, sz);
				chains[c].child.push_back({ nc,i });
			}
		}
		return c;
	}
	void bfs(int from, int parent, vector<int> &seq, const vector<int> &sz) {
		for (;;) {
			seq.push_back(from);
			int best = -1, next = -1;
			for (edge e : baseG[from]) {
				if (e.to == parent)continue;
				if (best < sz[e.to]) {
					best = sz[e.to]; next = e.to;
				}
			}
			if (next == -1)break;
			parent = from; from = next;
		}
	}

public:
	int calcsum(int a) {
		int res = 0;
		int cur = a;
		while (true) {
			int id = mapto[cur].first;
			int loc = mapto[cur].second;
			ar z = chains[id].stree.query(0, loc + 1);
			P p = calc_val(z, 21);
			res += p.second;
			if (id == 0)break;
			P par = chains[id].parent;
			cur = mapfrom[par.first][par.second];
		}
		return res;
	}
	int add(int a) {
		int res = 0;
		int id = mapto[a].first;
		int loc = mapto[a].second;
		int val = 0;
		int preval = 21;
		chains[id].stree.update(loc, { 0,1,0,1,0 });
		if (a == 0)return 0;
		if (loc > 0) {
			ar z = chains[id].stree.query(0, loc);
			P p = calc_val(z, 21);
			res -= p.second;
			preval = p.first;
			z = chains[id].stree.query(0, loc + 1);
			p = calc_val(z, 21);
			res += p.second;
			val = p.first;
		}
		else {

		}
		if (id == 0)return res;
		P par = chains[id].parent;
		int cur = mapfrom[par.first][par.second];
		

		while (true) {
			int id = mapto[cur].first;
			int loc = mapto[cur].second;
			if (preval < 21) {
				cnt[cur][preval]--;
			}
			cnt[cur][val]++;
			ar nw = getcur(cur);

			ar z = chains[id].stree.query(0, 1<<20);
			P p = calc_val(z, 21);
			res -= p.second;
			preval = p.first;

			

			

			
			chains[id].stree.update(loc, nw);
			z = chains[id].stree.query(0, 1<<20);
			p = calc_val(z, 21);
			res += p.second;
			val = p.first;
			if (id == 0)break;
			P par = chains[id].parent;
			cur = mapfrom[par.first][par.second];
		}
		return res;
	}
};
void solve() {
	int q; cin >> q;
	int n = q + 1;
	Graph G(n);
	rep(i, q) {
		int p; cin >> p; p--;
		par[i + 1] = p;
		G[p].push_back({ i + 1 });
		G[i + 1].push_back({ p });
	}
	HLDecomposition hld(G);
	hld.add(0);
	int ans = 0;
	

	rep1(i, q) {
		ans += hld.add(i);
		cout << ans << "\n";
	}
}


signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	

	

	

	

	

	

	solve();
	return 0;
}

