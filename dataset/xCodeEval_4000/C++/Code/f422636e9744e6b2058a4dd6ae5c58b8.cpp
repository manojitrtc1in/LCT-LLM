#pragma GCC optimize ("O3", "unroll-loops")






#include "bits/stdc++.h"
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define distinct(x) sort(all(x)); x.resize(unique(all(x))-x.begin())
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define CASE(x) int x; cin >> x; while (x--)
#define CASEt(x) int x; cin >> x; for (int tc = 1; tc <= x; ++tc)
using namespace std;
using namespace __gnu_pbds;
namespace {
	const int MOD107 = 1000000007;
	const int MOD998 = 998244353;
	using ll = long long;
	using ull = unsigned long long;
	using pii = pair<int, int>;
	using pll = pair<ll, ll>;
	template <class T> using ordered_set = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
	template <class T> using minheap = priority_queue<T, vector<T>, greater<T>>;
	template <class T> using maxheap = priority_queue<T, vector<T>, less<T>>;
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());


	struct Modular {
	private:
		long long MODVALUE = 0;
		long long val = 0;

		Modular initModular(long long val) const { return Modular(val, MODVALUE); }

	#ifdef LOCAL
		inline void validate() const {
			assert(MODVALUE != 0);
		}

		inline void validate(const Modular& other) const {
			assert(MODVALUE != 0);
			assert(MODVALUE == other.MODVALUE);
			other.validate();
		}
	#else
		inline void validate() const { }
		inline void validate(const Modular& other) const { }
	#endif

	public:
		explicit operator long long() const { return val; }

		template<class T> Modular& operator = (const T& other) { val = other; return *this; }
		template<class T> void setMod(const T& MOD) { MODVALUE = MOD; }

		bool operator == (const Modular& other) { validate(other); return val == other.val; }
		bool operator != (const Modular& other) { return !(*this == other); }
		template<class T> bool operator == (const T& other) { return *this == initModular(other); }
		template<class T> bool operator != (const T& other) { return *this != initModular(other); }
		template<class T> friend bool operator == (const T& other, const Modular& m) { return m.initModular(other) == m; }
		template<class T> friend bool operator != (const T& other, const Modular& m) { return m.initModular(other) != m; }

		bool operator <  (const Modular& other) { validate(other); return val <  other.val; }
		bool operator <= (const Modular& other) { validate(other); return val <= other.val; }
		bool operator >  (const Modular& other) { validate(other); return val >  other.val; }
		bool operator >= (const Modular& other) { validate(other); return val >= other.val; }
		template<class T> bool operator <  (const T& other) { return *this <  initModular(other); }
		template<class T> bool operator <= (const T& other) { return *this <= initModular(other); }
		template<class T> bool operator >  (const T& other) { return *this >  initModular(other); }
		template<class T> bool operator >= (const T& other) { return *this >= initModular(other); }
		template<class T> friend bool operator <  (const T& other, const Modular& m) { return m.initModular(other) <  m; }
		template<class T> friend bool operator <= (const T& other, const Modular& m) { return m.initModular(other) <= m; }
		template<class T> friend bool operator >  (const T& other, const Modular& m) { return m.initModular(other) >  m; }
		template<class T> friend bool operator >= (const T& other, const Modular& m) { return m.initModular(other) >= m; }

		Modular& operator += (const Modular& other) { validate(other); val += other.val; val %= MODVALUE; return *this; }
		Modular  operator +  (const Modular& other) { Modular tmp = *this; return tmp += other; }
		template<class T> Modular& operator += (const T& other) { return *this += initModular(other); }
		template<class T> Modular  operator +  (const T& other) { return *this +  initModular(other); }


		template<class T> friend Modular operator +  (const T& other, const Modular& m) { return m.initModular(other) +  m; }

		Modular& operator ++()    { return *this += 1; }
		Modular  operator ++(int) { Modular tmp = *this; ++*this; return tmp; }

		Modular  operator -  () const { return initModular(-val); }
		Modular& operator -= (const Modular& other) { validate(other); val -= other.val; val += MODVALUE; val %= MODVALUE; return *this;}
		Modular  operator -  (const Modular& other) { Modular tmp = *this; return tmp -= other; }
		template<class T> Modular& operator -= (const T& other) { return *this -= initModular(other); }
		template<class T> Modular  operator -  (const T& other) { return *this -  initModular(other); }


		template<class T> friend Modular operator -  (const T& other, const Modular& m) { return m.initModular(other) -  m; }

		Modular& operator --()    { return *this -= 1; }
		Modular  operator --(int) { Modular tmp = *this; --*this; return tmp; }

		Modular& operator *= (const Modular& other) { validate(other); val *= other.val; val %= MODVALUE; val += MODVALUE; val %= MODVALUE; return *this; }
		Modular  operator *  (const Modular& other) { Modular tmp = *this; return tmp *= other; }
		template<class T> Modular& operator *= (const T& other) { return *this *= initModular(other); }
		template<class T> Modular  operator *  (const T& other) { return *this *  initModular(other); }


		template<class T> friend Modular operator *  (const T& other, const Modular& m) { return m.initModular(other) *  m; }

		Modular pow(long long power) const {
			Modular m = *this, ans = initModular(1);
			while (power) {
				if (power & 1) ans *= m;
				m *= m;
				power >>= 1;
			}
			return ans;
		}
		Modular pow(const Modular& other) const { return pow(other.val); }
		Modular inv() const { return pow(MODVALUE-2); }

		Modular& operator /= (const Modular& other) { val *= other.inv().val; val %= MODVALUE; return *this; }
		Modular  operator /  (const Modular& other) { Modular tmp = *this; return tmp /= other; }
		template<class T> Modular& operator /= (const T& other) { return *this /= initModular(other); }
		template<class T> Modular  operator /  (const T& other) { return *this /  initModular(other); }


		template<class T> friend Modular operator /  (const T& other, const Modular& m) { return m.initModular(other) /  m; }

		friend istream& operator >> (istream& in, Modular& m) { in >> m.val; m.val %= m.MODVALUE; m.val += m.MODVALUE; m.val %= m.MODVALUE; return in; }
		friend ostream& operator << (ostream& out, const Modular& m) { return out << m.val; }

		Modular() { val = 0; MODVALUE = 0; }
		Modular(long long val, long long MOD) : MODVALUE(MOD), val((val % MOD + MOD) % MOD) { }
	};
	using Mint = Modular;
	inline ll pow(ll b, ll p, ll mod) {
		b %= mod;
		ll ans = 1;
		for (; p > 0; p >>= 1) {
			if (p&1) {ans *= b; ans %= mod;}
			b *= b;
			b %= mod;
		}
		return ans;
	}
	inline ll max(ll a, int b) { return (a > b ? a : b); }
	inline ll max(int a, ll b) { return (a > b ? a : b); }
	inline ll min(ll a, int b) { return (a < b ? a : b); }
	inline ll min(int a, ll b) { return (a < b ? a : b); }
	template <class T> inline bool chkmin(T&x, const T& y) { return x > y ? x = y, 1 : 0; }
	template <class T> inline bool chkmax(T&x, const T& y) { return x < y ? x = y, 1 : 0; }
}
namespace IO {
	template<class T> inline void _R(T &x) {cin >> x;}
	template<class T1, class T2> inline void _R(pair<T1,T2> &x) {_R(x.first); _R(x.second);}
	template<class T> inline void _R(vector<T> &x) {for (auto& i : x) _R(i);}
	template<class T> inline void _R(deque<T> &x) {for (auto& i : x) _R(i);}
	inline void R() {}
	template<class T1, class... T2> inline void R(T1 &x, T2 &...y) { _R(x); R(y...);}

	template<class T> inline void _W(const T& x);
	template<class T1, class T2> inline void _W(const pair<T1,T2>& p);
	template<class... T> inline void _W(const vector<T...>& x);
	template<class... T> inline void _W(const deque<T...>& x);
	template<class... T> inline void _W(const forward_list<T...>& x);
	template<class... T> inline void _W(const list<T...>& x);
	template<class... T> inline void _W(const set<T...>& x);
	template<class... T> inline void _W(const multiset<T...>& x);
	template<class... T> inline void _W(const unordered_set<T...>& x);
	template<class... T> inline void _W(const unordered_multiset<T...>& x);
	template<class... T> inline void _W(const map<T...>& x);
	template<class... T> inline void _W(const multimap<T...>& x);
	template<class... T> inline void _W(const unordered_map<T...>& x);
	template<class... T> inline void _W(const unordered_multimap<T...>& x);

	template<class T> inline void _W(const ordered_set<T>& x);

	template<class Container> inline void printContainer(const Container& x) { bool isFirst = 1; for (auto i : x) { if (!isFirst) cout << ' '; isFirst = 0; _W(i); } }

	template<class T> inline void _W(const T& x) {cout << x;}
	template<class T1, class T2> inline void _W(const pair<T1,T2>& p) {_W(p.first); _W(' '); _W(p.second);}
	template<class... T> inline void _W(const vector<T...>& x) { printContainer(x); }
	template<class... T> inline void _W(const deque<T...>& x) { printContainer(x); }
	template<class... T> inline void _W(const forward_list<T...>& x) { printContainer(x); }
	template<class... T> inline void _W(const list<T...>& x) { printContainer(x); }
	template<class... T> inline void _W(const set<T...>& x) { printContainer(x); }
	template<class... T> inline void _W(const multiset<T...>& x) { printContainer(x); }
	template<class... T> inline void _W(const unordered_set<T...>& x) { printContainer(x); }
	template<class... T> inline void _W(const unordered_multiset<T...>& x) { printContainer(x); }
	template<class... T> inline void _W(const map<T...>& x) { printContainer(x); }
	template<class... T> inline void _W(const multimap<T...>& x) { printContainer(x); }
	template<class... T> inline void _W(const unordered_map<T...>& x) { printContainer(x); }
	template<class... T> inline void _W(const unordered_multimap<T...>& x) { printContainer(x); }

	template<class T> inline void _W(const ordered_set<T>& x) { printContainer(x); }

 	inline void W() {cout << '\n';}
	template<class T> inline void W(const T &x) {_W(x); W();}
	template<class T1, class... T2> inline void W(const T1 &x, const T2 &...y) { _W(x); _W(' '); W(y...);}
} using namespace IO;
namespace outputFormat{
	inline string Case(int tc) {return "Case #" + to_string(tc) + ':';}
	inline string YN(bool b) {return b ? "Yes" : "No";}
} using namespace outputFormat;
namespace std {
    template <class T1, class T2> struct hash<pair<T1,T2>> {
    	std::size_t operator()(pair<T1,T2> _) const {
        	return hash<T1>{}(_.first) ^ hash<T2>{}(_.second);
    	}
    };
}
const Mint ZERO = Mint(0, MOD998);


const int IMP = -1e8;
const int MAXN = 1048576;
struct Segtree {
	struct Node {
		int dep;
		int wdep;
		int tag = 0;

		int dp[5][2];

		Node merge(const Node& other) {
			Node ans;

			ans.dp[1][0] = max(dp[1][0], other.dp[1][0]);
			for (int i = 0; i < 2; i++) {
				ans.dp[0][i] = max(dp[0][i], other.dp[0][i]);
				ans.dp[2][i] = max({dp[2][i], other.dp[2][i], dp[0][i] + other.dp[1][0]});
				ans.dp[3][i] = max({dp[3][i], other.dp[3][i], dp[1][0] + other.dp[0][i]});
				ans.dp[4][i] = max({dp[4][i], other.dp[4][i], dp[2][i] + other.dp[0][i], dp[0][i] + other.dp[3][i]});
			}

			return ans;
		}

		void swap() {
			for (int i = 0; i < 5; i++) {
				if (i == 1) continue;
				std::swap(dp[i][0], dp[i][1]);
			}
		}
	};

	vector<Node> tree = vector<Node>(MAXN << 1);

	void upd(int id, int l, int r, int ql, int qr) {
		if (ql <= l && r <= qr) {
			tree[id].tag ^= 1;
			tree[id].swap();
			return;
		}

		if (tree[id].tag) {
			tree[id << 1].tag ^= 1;
			tree[id << 1].swap();
			tree[id << 1 ^ 1].tag ^= 1;
			tree[id << 1 ^ 1].swap();
			tree[id].tag ^= 1;
		}

		int mid = l + r >> 1;
		if (ql <= mid)
			upd(id << 1, l, mid, ql, qr);

		if (qr > mid)
			upd(id << 1 ^ 1, mid + 1, r, ql, qr);

		tree[id] = tree[id << 1].merge(tree[id << 1 ^ 1]);
	}
} st;

int main() {
	int n; R(n);
	vector<vector<pii>> g(n + 1);
	vector<pii> e(n - 1);
	vector<int> w(n - 1);

	for (int i = 0; i < n - 1; i++) {
		int u,v,t; R(u,v,t);
		g[u].pb({v, i});
		g[v].pb({u, i});
		e[i] = {u, v};
		w[i] = t;
	}

	vector<int> dep(n + 1), wdep(n + 1);
	function<void(int, int, int)> dfs1 = [&](int u, int p, int pe) {
		dep[u] = p == -1 ? 0 : dep[p] + 1;
		wdep[u] = p == -1 ? 0 : wdep[p] ^ w[pe];
		if (pe != -1 && e[pe].F == u)
			swap(e[pe].F, e[pe].S);

		for (auto& e : g[u]) {
			if (e.F != p) {
				dfs1(e.F, u, e.S);
			}
		}
	};

	dfs1(1, -1, -1);

	vector<int> in(n + 1), out(n + 1);
	vector<int> euler;
	function<void(int, int)> dfs_euler = [&](int u, int p) {
		in[u] = (int)euler.size();
		euler.pb(u);

		for (auto& e : g[u]) {
			if (e.F != p) {
				dfs_euler(e.F, u);
				euler.pb(u);
			}
		}

		out[u] = (int)euler.size() - 1;
	};

	dfs_euler(1, -1);
	assert((int)euler.size() == 2 * n - 1);
	
	for (int i = MAXN; i < MAXN << 1; i++) {
		for (int j = 0; j < 5; j++) {
			for (int k = 0; k < 2; k++) {
				st.tree[i].dp[j][k] = IMP;
			}
		}
	}

	for (int i = 0; i < (int)euler.size(); i++) {
		int id = i + MAXN;
		st.tree[id].dep = dep[euler[i]];
		st.tree[id].wdep = wdep[euler[i]];

		st.tree[id].dp[0][wdep[euler[i]]] = dep[euler[i]];
		st.tree[id].dp[1][0] = -2 * dep[euler[i]];
		st.tree[id].dp[2][wdep[euler[i]]] = -dep[euler[i]];
		st.tree[id].dp[3][wdep[euler[i]]] = -dep[euler[i]];
		st.tree[id].dp[4][wdep[euler[i]]] = 0;
	}
	

	for (int i = MAXN - 1; i >= 1; i--)
		st.tree[i] = st.tree[i << 1].merge(st.tree[i << 1 ^ 1]);

	CASE(m) {
		int id; R(id);
		int root = e[--id].S;

		st.upd(1, 0, MAXN - 1, in[root], out[root]);
		W(max(st.tree[1].dp[4][0], st.tree[1].dp[4][1]));
	}

	return 0;
}

static auto __init__ = [](){
#ifndef LOCAL
	ios::sync_with_stdio(false);
	cin.tie(0);
#endif
	cout << fixed << setprecision(10);
	return 42;
}();
