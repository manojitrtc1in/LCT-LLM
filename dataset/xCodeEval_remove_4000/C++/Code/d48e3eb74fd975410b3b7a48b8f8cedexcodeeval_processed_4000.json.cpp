


















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

	
		inline void validate() const {
			assert(MODVALUE != 0);
		}

		inline void validate(const Modular& other) const {
			assert(MODVALUE != 0);
			assert(MODVALUE == other.MODVALUE);
			other.validate();
		}
	
		inline void validate() const { }
		inline void validate(const Modular& other) const { }
	

	public:
		explicit operator long long() const { return val; }

		template<class T> Modular& operator = (const T& other) { val = other; return *this; }
		template<class T> void setMod(const T& MOD) { MODVALUE = MOD; }







































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
	inline string Case(int tc) {return "Case 
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

struct SegTree {
	struct node {
		int val;
		int pos;
	} nullNode;
	
	vector<node> segtree;
	
	void pull(int id) {
		segtree[id].val = min(segtree[id << 1].val, segtree[id << 1 | 1].val);
		segtree[id].pos = (segtree[id << 1].val < segtree[id << 1 | 1].val ? segtree[id << 1].pos : segtree[id << 1 | 1].pos);
	}
	
	void update(int id, int l, int r, int q, int val) {
		if (l == r) {
			segtree[id].val = val;
			segtree[id].pos = q;
			return;
		}
		int mid = (l+r)>>1;
		if (q <= mid)
			update(id<<1, l, mid, q, val);
		else
			update(id<<1|1, mid+1, r, q, val);
			
		pull(id);
	}
	
	void update2(int id, int l, int r, int q) {
		if (l == r) {
			segtree[id].val--;
			return;
		}
		int mid = (l+r)>>1;
		if (q <= mid)
			update2(id<<1, l, mid, q);
		else
			update2(id<<1|1, mid+1, r, q);

		pull(id);
	}

	SegTree(int size) {
		segtree.resize(size<<2);
	}
};

int main() {
	CASE(t) {
		int n,m,k; R(n,m,k);
		vector<vector<int>> g(n + 1);
		for (int i = 0; i < m; i++) {
			int u,v; R(u,v);
			g[u].pb(v);
			g[v].pb(u);
		}
		
		for (int i = 1; i <= n; i++)
			sort(all(g[i]));
		
		const int THRES = 1000000000;
		auto solve1 = [&]() {
			SegTree st(n + 1);
			st.update(1, 0, n, 0, INT_MAX);
			for (int i = 1; i <= n; i++)
				st.update(1, 0, n, i, g[i].size());

			vector<bool> is(n + 1, true);
			is[0] = false;
			int sz = n;
			bool flag = 0;
			
			while (true) {
				int minv = st.segtree[1].val;
				int minp = st.segtree[1].pos;

				if (minv >= THRES)
					break;

				if (minv >= k) {
					flag = 1;
					break;
				}

				is[minp] = 0;
				sz--;
				st.update(1, 0, n, minp, INT_MAX);
				for (auto& j : g[minp])
					st.update2(1, 0, n, j);
			}
			
			if (flag) {
				W(1, sz);
				
				vector<int> ans;
				for (int i = 1; i <= n; i++) {
					if (is[i])
						ans.pb(i);
				}

				assert((int)ans.size() == sz);
				W(ans);
				return true;
			} else {
				return false;
			}
		};
		
		auto solve2 = [&]() {
			SegTree st(n + 1);
			st.update(1, 0, n, 0, INT_MAX);
			for (int i = 1; i <= n; i++)
				st.update(1, 0, n, i, g[i].size());

			vector<bool> is(n + 1, true);
			is[0] = false;
			int sz = n;
			
			while (true) {
				int minv = st.segtree[1].val;
				int minp = st.segtree[1].pos;

				if (minv >= THRES)
					break;
					
				if (minv >= k - 1) {
					vector<int> ans;
					ans.reserve(k);
					
					ans.pb(minp);
					for (auto& i : g[minp])
						if (is[i])
							ans.pb(i);
							
					assert((int)ans.size() == k);
					
					bool isC = 1;
					for (int i = 0; i < k; i++)
						for (int j = i + 1; j < k; j++) {
							auto it = lower_bound(all(g[ans[i]]), ans[j]);
							if (it == g[ans[i]].end() || *it != ans[j]) {
								isC = 0;
								break;
							}
						}
							
					if (isC) {
						W(2);
						W(ans);
						return true;
					}
				}

				is[minp] = 0;
				sz--;
				st.update(1, 0, n, minp, INT_MAX);
				for (auto& j : g[minp])
					st.update2(1, 0, n, j);
			}
			
			return false;
		};
		
		if (solve1())
			continue;
		else if (solve2())
			continue;
			
		W(-1);
	}
	
	return 0;
}

static auto id0 = [](){

	ios::sync_with_stdio(false);
	cin.tie(0);

	cout << fixed << setprecision(10);
	return 42;
}();