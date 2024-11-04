#pragma GCC optimize("Ofast")



#include <bits/stdc++.h>

using namespace std;

#define GET_MACRO(_1, _2, _3, _4, NAME, ...) NAME
#define __FOR3(i, a, n, inc) for(int i = (a); (inc) > 0 ? i < (n) : i >= (n); i += (inc))
#define __FOR2(i, a, n) __FOR3(i, a, n, 1)
#define __FOR1(i, n) __FOR2(i, 0, n)
#define FOR(...) GET_MACRO(__VA_ARGS__, __FOR3, __FOR2, __FOR1)(__VA_ARGS__)

#define BOOST 			ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ELO             exit(0)
#define ALL(a) 			(a).begin(), (a).end()
#define SZ(a) 			(int)(a).size()
#define TRAV(a, b) 		for (auto& a : b)
#define REV(a)          reverse(ALL(a))
#define SORT(a)         sort(ALL(a))
#define SORTR(a)        SORT(a), REV(a)
#define PB              push_back
#define F               first
#define S               second
using ll = 				long long;
using ld = 				long double; 

using pii = 			pair<int, int>;
using pll = 			pair<ll, ll>;
using pld =             pair<ld, ld>;
using vi = 				vector<int>;
using vvi =             vector<vi>;
using vll = 			vector<ll>;
using vvll =            vector<vll>;
using vpii = 			vector<pii>;
using vpll = 			vector<pll>;
using vld =             vector<ld>;
using vpld =            vector<pld>;

constexpr int MOD = 1e9 + 7; 

constexpr int MOD1 = 998244353;
constexpr int INF = MOD;
constexpr ll LLINF = 1e18;
const ld PI = acos(-1);

template <class T> inline bool setmin(T& a, T b) {if (a > b) return a = b, 1; return 0; }
template <class T> inline bool setmax(T& a, T b) {if (a < b) return a = b, 1; return 0; }

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template <class key, class cmp = less<key>> using ordered_set = tree<key, null_type, cmp, rb_tree_tag, tree_order_statistics_node_update>;
template <class key, class cmp = less_equal<key>> using ordered_multiset = tree<key, null_type, cmp, rb_tree_tag, tree_order_statistics_node_update>;




template <class key, class value, class cmp = less<key>> using ordered_map = tree<key, value, cmp, rb_tree_tag, tree_order_statistics_node_update>;
using pref_trie = trie<string, null_type, trie_string_access_traits<>, pat_trie_tag, trie_prefix_search_node_update>;



namespace input {
    template <class T> istream &operator>>(istream &os, vector<T> & vec) { for (auto& u : vec) os >> u; return os; }
    template<class T1, class T2> istream& operator>>(istream& os, pair<T1, T2>& p) { return os >> p.first >> p.second; }
    template <class T, size_t N> istream& operator>>(istream& os, array<T, N>& a) { for (auto& u : a) os >> u; return os; }

    void re() {}
    template <typename T, typename... args> void re(T& x, args&... tail) { cin >> x; re(tail...); }
} 

using namespace input;

namespace output {
    template <class T> ostream &operator<<(ostream &os, const vector<T> & vec){for (const auto& u : vec) os << u << " "; return os; }
    template<class T1, class T2> ostream& operator<<(ostream& os, const pair<T1, T2>& p) { return os << p.first << " " << p.second; }
    template <class T> ostream &operator<<(ostream &os, set<T> & con) { for (const auto& u : con) os << u << " "; return os; }
    template <class T, size_t N> ostream& operator<<(ostream& os, array<T, N>& a) { for (const auto& u : a) os << u << " "; return os; }
    
    void pr() {}
    template <typename T> void pr(const T& x) { cout << x; }
    template <typename T, typename... args> void pr(const T& x, const args&... tail) { cout << x << " "; pr(tail...);}
    template <typename T> void prs(const T& x) { cout << x << " "; }
    template <typename T, typename... args> void prs(const T& x, const args&... tail) { cout << x << " "; prs(tail...);}
    template <typename... args> void prln(const args&... tail) { pr(tail...); cout << "\n";}
} 

using namespace output;

namespace pair_magic {
	#define PT1T2 pair<T1,T2>
	#define TT1T2 template<class T1, class T2>
	TT1T2 inline PT1T2 operator+(const PT1T2 &p1, const PT1T2 &p2) { return PT1T2(p1.first + p2.first, p1.second + p2.second); }
	TT1T2 inline PT1T2& operator+=(PT1T2 &p1, const PT1T2 &p2) { p1.first += p2.first, p1.second += p2.second; return p1; }
	TT1T2 inline PT1T2 operator-(const PT1T2 &p1, const PT1T2 &p2) { return PT1T2(p1.first - p2.first, p1.second - p2.second); }
	TT1T2 inline PT1T2& operator-=(PT1T2 &p1, const PT1T2 &p2) { p1.first -= p2.first, p1.second -= p2.second; return p1; }
	#undef PT1T2
	#undef TT1T2
}
using namespace pair_magic;

namespace random_nsp {
	thread_local std::mt19937 gen{std::random_device{}()};
	template <typename T>T random(T min, T max){using dist = std::conditional_t<std::is_integral<T>::value, std::uniform_int_distribution<T>, std::uniform_real_distribution<T>>;return dist{min, max}(gen);}
	template <typename T> T randomINT(T min, T max) { return std::uniform_int_distribution<T>{min, max}(gen); }
}
using namespace random_nsp;

namespace triple {
	#define TT1T2T3 template<class T1, class T2, class T3>
	#define TRT1T2T3  triple<T1, T2, T3>
	TT1T2T3 struct triple { T1 a; T2 b; T3 c; triple() : a(T1()), b(T2()), c(T3()) {}; triple(T1 _a, T2 _b, T3 _c) :a(_a), b(_b), c(_c) {} };
	TT1T2T3 bool operator<(const TRT1T2T3&t1, const TRT1T2T3&t2) { if (t1.a != t2.a)return t1.a < t2.a; else if (t1.b != t2.b)return t1.b < t2.b; else return t1.c < t2.c; }
	TT1T2T3 bool operator>(const TRT1T2T3&t1, const TRT1T2T3&t2) { if (t1.a != t2.a)return t1.a > t2.a; else if (t1.b != t2.b)return t1.b > t2.b; else return t1.c > t2.c; }
	TT1T2T3 bool operator==(const TRT1T2T3&t1, const TRT1T2T3&t2) { return (t1.a == t2.a && t1.b == t2.b && t1.c == t2.c); }
	TT1T2T3 inline istream& operator >> (istream& os, triple<T1, T2, T3>& t) { return os >> t.a >> t.b >> t.c; }
	TT1T2T3 ostream& operator << (ostream& os, const triple<T1, T2, T3>& t) { return os << t.a << " " << t.b << " " << t.c; }
	#undef TRT1T2T3
	#undef TT1T2T3
	using tri =  triple<int, int, int>;
	using trll = triple<ll, ll, ll>;
	using vtri = vector<tri>;
    using vtrll = vector<trll>;
}
using namespace triple;

template <class T> T invGeneral(T a, T b) { 

    a %= b;
    if (a == 0) return b == 1 ? 0 : -1;
    T x = invGeneral(b, a); 
    return x == -1 ? -1 : ((1-(ll)b * x) / a + b) % b;
}

template<class T> struct modular {
	T val; 
	explicit operator T() const { return val; }
	modular() { val = 0; }
	modular(const ll& v) { 
		val = (-MOD <= v && v <= MOD) ? v : v % MOD;
		if (val < 0) val += MOD;
	}
	
	friend ostream& operator<<(ostream& os, const modular& a) { return os << a.val; }
	friend void pr(const modular& a) { pr(a.val); }
	friend void re(modular& a) { ll x; re(x); a = modular(x); }
   
	friend bool operator==(const modular& a, const modular& b) { return a.val == b.val; }
	friend bool operator!=(const modular& a, const modular& b) { return !(a == b); }
	friend bool operator<(const modular& a, const modular& b) { return a.val < b.val; }
 
	modular operator-() const { return modular(-val); }
	modular& operator+=(const modular& m) { if ((val += m.val) >= MOD) val -= MOD; return *this; }
	modular& operator-=(const modular& m) { if ((val -= m.val) < 0) val += MOD; return *this; }
	modular& operator*=(const modular& m) { val = (ll)val*m.val%MOD; return *this; }
	friend modular pow(modular a, ll p) {
		modular ans = 1; for (; p; p /= 2, a *= a) if (p&1) ans *= a;
		return ans;
	}
	friend modular inv(const modular& a) { 
		auto i = invGeneral(a.val,MOD); assert(i != -1);
		return i;
	} 

	modular& operator/=(const modular& m) { return (*this) *= inv(m); }
	
	friend modular operator+(modular a, const modular& b) { return a += b; }
	friend modular operator-(modular a, const modular& b) { return a -= b; }
	friend modular operator*(modular a, const modular& b) { return a *= b; }
	friend modular operator/(modular a, const modular& b) { return a /= b; }
};
 
using mi = modular<int>;
using pmi = pair<mi,mi>;
using vmi = vector<mi>; 
using vpmi = vector<pmi>;

namespace debug {
    template < typename _T > inline void _debug(const char *s, _T x) { cerr << s << " = " << x << "\n"; }
    template < typename _T, typename... args > void _debug(const char *s, _T x, args... a) { while(*s != ',') cerr << *s++; cerr << " = " << x << ','; _debug(s + 1, a...); }
    
    #if 0
        #define debug(...) _debug(#__VA_ARGS__, __VA_ARGS__)
        #define cerr cout
    #else
        #define debug(...) 1999
        #define cerr if(0) cout
    #endif
} 

using namespace debug;




template <typename T, typename F> 
void fwt (T a[], int n, F f)  {
	for(int d = 1; d < n; d *= 2) {
		for(int i = 0, t = d * 2; i < n; i += t) {
			for(int j = 0; j < d; j++) {
				f(a[i + j], a[i + j + d]);
			}
		}
	}
}
   
void XOR(pii& a, pii& b) {
    pii x = a, y = b;
    a.F = (x.F + y.F);
	if(a.F >= MOD) a.F -= MOD;
    b.F = (x.F - y.F + MOD);
	if(b.F >= MOD) b.F -= MOD;
	
    a.S = (x.S + y.S);
	if(a.S >= MOD1) a.S -= MOD1;
    b.S = (x.S - y.S + MOD1);
	if(b.S >= MOD1) b.S -= MOD1;
}

const int R = 1 << 17;
const int N = 1e5 + 7;

vpii graf[N];
int n, m;
int wszy = 0;

pii babel[42][R];
int cnt = 0;

vi temp[45];
int cnt2 = 0;

bitset<N> naStacku, vis;
stack<int> S;

void dfs(int u, int p = -1) {
	vis[u] = naStacku[u] = true;
	debug(u);
	S.push(u);
	for(auto& [v, w] : graf[u]) {
		if(v != p) {
			if(!vis[v]) {
				dfs(v, u);
			} else if(naStacku[v]) {
				int x = v;
				while(S.top() != v) {
					debug(S.top());
					temp[cnt2].PB(S.top());
					naStacku[S.top()] = false;
					S.pop();
				}
				temp[cnt2].PB(v);
				naStacku[v] = false;
				S.pop();
				cnt2++;
			}
		}
	}

	if(naStacku[u]) {
		S.pop();
		naStacku[u] = false;
	}
}

int main() {
    BOOST;
	re(n, m);
	map<pii, int> M;
	FOR(i, m) {
		int a, b, c; re(a, b, c);
		a--, b--;
		wszy ^= c;
		M[{min(a, b), max(a, b)}] = c;
		graf[a].PB({b, c});
		graf[b].PB({a, c});
	}

	dfs(0);

	FOR(i, cnt2) {
		FOR(j, 1, SZ(temp[i])) {
			int a = temp[i][j - 1], b = temp[i][j];
			int w = M[{min(a, b), max(a, b)}];
			babel[cnt][w].F++;
			babel[cnt][w].S++;
		}

		int a = temp[i][0], b = temp[i].back();
		int w = M[{min(a, b), max(a, b)}];
		babel[cnt][w].F++;
		babel[cnt][w].S++;
		cnt++;
	}


	if(cnt == 0) {
		prln(wszy, 1);
		ELO;
	}
	
	FOR(i, 1, cnt) {
		fwt(babel[i - 1], R, XOR);
		fwt(babel[i], R, XOR);
		FOR(j, R) {
			babel[i][j].F = (1ll * babel[i][j].F * babel[i - 1][j].F) % MOD;
			babel[i][j].S = (1ll * babel[i][j].S * babel[i - 1][j].S) % MOD1;
		}
		fwt(babel[i], R, XOR);
		FOR(j, R) {
			babel[i][j].F = (1ll * babel[i][j].F * 742744451) % MOD;
			babel[i][j].S = (1ll * babel[i][j].S * 742744451) % MOD1;
		}
	}

	pll res{LLINF, 0};
	FOR(i, R) {
		if(babel[cnt - 1][i].F or babel[cnt - 1][i].S) {
			int nowyK = wszy ^ i;
			if(nowyK < res.F) {
				res.F = nowyK;
				res.S = babel[cnt - 1][i].F;
			} else if(nowyK == res.F) {
				res.S = res.S + babel[cnt - 1][i].F;
				if(res.S >= MOD) res.S -= MOD;
			}
		}
	}
	prln(res);
}

