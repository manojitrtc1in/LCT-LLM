#include<stdio.h>
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;


#define     UI                      unsigned int
#define     LL                      long long int
#define     LD                      long double
#define     ULL                     unsigned long long int
#define     VI                      vector<int>
#define     VB                      vector<bool>
#define     VLD                     vector<LD>
#define     VLL                     vector<LL>
#define     VULL                    vector<ULL>
#define     VVI                     vector<VI>
#define     VVLL                    vector<VLL>


#define     pii                     pair<int, int>
#define     mp                      make_pair
#define     pb                      push_back
#define     ff                      first
#define     ss                      second
#define     SZ(x)                   (int)x.size()
#define     all(x)                  x.begin(), x.end()


#define     sp(x)                   setprecision(x) << fixed
#define     what_is(x)              cout << #x << " is " << x << endl


#define     PI                      acos(-1.0)
#define     EPS                     1e-12
#define     S_SIZE                  5000010     


const LL inf = 1000000000;
const LL mod = 1000000000 + 7;


inline void IO() { ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); }
template<typename T> inline int dcmp (T x) { const T eps = EPS; return x < -eps ? -1 : (x > eps); }


template<class T> inline int CHECK(T MASK, int i) { return (MASK >> i) & 1; }
template<class T> inline T ON(T MASK, int i) { return MASK | (T(1) << i); }
template<class T> inline T OFF(T MASK, int i) { return MASK & (~(T(1) << i)); }
template<typename T> inline int CNT(T MASK) {
    if (numeric_limits<T>::digits <= numeric_limits<unsigned int>::digits) return __builtin_popcount(MASK);
    else return __builtin_popcountll(MASK);
}
template<class T> inline int RIGHT(T MASK) { return log2(MASK & -MASK); }


int dx4[] = { 0, 0, -1, +1 };
int dy4[] = { +1, -1, 0, 0 };
int dx8[] = { 1, 1, 0, -1, -1, -1, 0, 1, 0 };
int dy8[] = { 0, 1, 1, 1, 0, -1, -1, -1, 0 };
int dx8Knight[] = { +2, +2, +1, -1, -2, -2, -1, +1 };
int dy8Knight[] = { +1, -1, -2, -2, -1, +1, +2, +2 };   


inline void I(int &a) { scanf("%d", &a); }
inline void I(LL &a) { scanf("%lld", &a); }
inline void I(ULL &a) { scanf("%llu", &a); }
inline void I(char *a) { scanf("%s", a); }
char Iarr[S_SIZE]; inline void I(string &a) { scanf("%s", Iarr); a = Iarr; }
inline void I(LD &a) { cin >> a; }
inline void I(double &a) { cin >> a; }
inline void I(bool &a) { int aa; I(aa); a = aa; }
template<typename T1, typename T2> inline void I(pair<T1, T2> &a) { I(a.ff); I(a.ss); }
template<typename T> inline void I(vector<T> &a) { for (T &aa : a) I(aa); }
template<typename T, typename... Args> inline void I(T &a, Args &... args) { I(a); I(args...); }


inline void OUT(const int &a) { printf("%d", a); }
inline void OUT(const LL &a) { printf("%lld", a); }
inline void OUT(const ULL &a) { printf("%llu", a); }
inline void OUT(const char *a) { printf("%s", a); }
inline void OUT(const char &a) { printf("%c", a); }
inline void OUT(const string &a) { for (const char &aa : a) OUT(aa); }
inline void OUT(const bool &a) { printf("%d", a); }
template<typename T1, typename T2> inline void OUT(const pair<T1, T2> &a) { OUT("{"); OUT(a.ff); OUT(", "); OUT(a.ss); OUT("}"); }
template<typename T> inline void OUT(const T &a) { int i = 0; OUT("{"); for (const auto &aa : a) { if (i++) OUT(", "); OUT(aa); } OUT("}"); }
template<typename T, typename... Args> inline void OUT(const T &a, const Args &... args) { OUT(a); OUT(" "); OUT(args...); }
template<typename... Args> inline void O(const Args &... args) { OUT(args...); OUT("\n"); }


#define error(args...) { string _s = "[" + string(#args) + "] = ["; OUT(_s); err(args); }
void err() {}
template<typename T, typename... Args>
void err(T a, Args... args) {
	OUT(a), OUT((sizeof...(args) ? ", " : "]\n"));
	err(args...);
}


struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15; x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9; x = (x ^ (x >> 27)) * 0x94d049bb133111eb; return x ^ (x >> 31);
    }
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count(); return splitmix64(x + FIXED_RANDOM);
    }
};
struct custom_hash_pair {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15; x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9; x = (x ^ (x >> 27)) * 0x94d049bb133111eb; return x ^ (x >> 31);
    }
    size_t operator()(pair<uint64_t, uint64_t> x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x.ff + FIXED_RANDOM) * 3 + splitmix64(x.ss + FIXED_RANDOM);
    }
};


inline void faster(auto &unorderedMap, int n) { int num = 2; while (num < n) num *= 2; unorderedMap.reserve(num); unorderedMap.max_load_factor(0.25); }









const int M = 200010; 






struct Node {
	Node *l = 0, *r = 0;
	int lo, hi;
	LL madd = 0, val = 0; 

	inline Node(int lo, int hi) : lo(lo), hi(hi) {} 

	LL query(int L, int R) {
		if (R <= lo || hi <= L) return LLONG_MAX; 

		if (L <= lo && hi <= R) return val;
		push();
		return min(l->query(L, R), r->query(L, R));
	}
	void add(int L, int R, LL x) {
		if (R <= lo || hi <= L) return;
		if (L <= lo && hi <= R) {
			madd += x;
			val += x; 

		}
		else {
			push(), l->add(L, R, x), r->add(L, R, x);
			val = min(l->val, r->val);
		}
	}
	inline void push() {
		if (!l) {
			int mid = lo + (hi - lo)/2;
			l = new Node(lo, mid); r = new Node(mid, hi);
		}
		if (madd)
			l->add(lo,hi,madd), r->add(lo,hi,madd), madd = 0;
	}
};

void clean(Node *root)
{
    if (root->l) clean(root->l);
    if (root->r) clean(root->r);
    delete root;
}



using vi = VI;
template <bool VALS_EDGES> struct HLD {
	int N, tim = 0;
	vector<vi> adj;
	vi par, siz, depth, rt, pos;
	Node *tree;
	HLD(vector<vi> adj_)
		: N(SZ(adj_)), adj(adj_), par(N, -1), siz(N, 1), depth(N),
		  rt(N),pos(N),tree(new Node(0, N)){ dfsSz(),dfsHld();}
	void dfsSz(int v = 0) {
		if (par[v] != -1) adj[v].erase(find(all(adj[v]), par[v]));
		for (int& u : adj[v]) {
			par[u] = v, depth[u] = depth[v] + 1;
			dfsSz(u);
			siz[v] += siz[u];
			if (siz[u] > siz[adj[v][0]]) swap(u, adj[v][0]);
		}
	}
	void dfsHld(int v = 0) {
		pos[v] = tim++;
		for (int u : adj[v]) {
			rt[u] = (u == adj[v][0] ? rt[v] : u);
			dfsHld(u);
		}
	}
	
	template <class B> inline void process(int u, int v, B op) {
		for (; rt[u] != rt[v]; v = par[rt[v]]) {
			if (depth[rt[u]] > depth[rt[v]]) swap(u, v);
			op(pos[rt[v]], pos[v] + 1);
		}
		if (depth[u] > depth[v]) swap(u, v);
		op(pos[u] + VALS_EDGES, pos[v] + 1);
	}
	inline void modifyPath(int u, int v, LL val) {
		process(u, v, [&](int l, int r) { tree->add(l, r, val); });
	}
	inline LL queryPath(int u, int v) { 

		LL res = LLONG_MAX;
		process(u, v, [&](int l, int r) { res = min(res, tree->query(l, r)); });
		return res;
	}
	inline LL querySubtree(int v) { 

		return tree->query(pos[v] + VALS_EDGES, pos[v] + siz[v]);
	}
	inline void modifySubtree(int v, LL x) { 

		tree->add(pos[v] + VALS_EDGES, pos[v] + siz[v], x);
	}
};



#define rep(i, a, b) for(int i = a; i < (b); ++i)

template<class T>
struct RMQ {
	vector<vector<T>> jmp;

	RMQ(const vector<T>& V) : jmp(1, V) {
		for (int pw = 1, k = 1; pw * 2 <= SZ(V); pw *= 2, ++k) {
			jmp.emplace_back(SZ(V) - pw * 2 + 1);
			rep(j, 0, SZ(jmp[k]))
				jmp[k][j] = min(jmp[k - 1][j], jmp[k - 1][j + pw]);
		}
	}

	inline T query(int a, int b) {
		assert(a < b); 

		int dep = 31 - __builtin_clz(b - a);
		return min(jmp[dep][a], jmp[dep][b - (1 << dep)]);
	}
};

struct LCA {
	int T = 0;
	VI time, path, ret;
	VLL dist;
	RMQ<int> rmq;

	LCA(vector<vector<pii>>& C) : dist(SZ(C)), time(SZ(C)), rmq((dfs(C, 0, -1, 0), ret)) {}

	void dfs(vector<vector<pii>> &C, int v, int par, LL curr_sum) {
		time[v] = T++;
		dist[v] = curr_sum;
		for (pii p : C[v]) {
            int w = p.ss, y = p.ff;
            if (y != par) {
                path.push_back(v), ret.push_back(time[v]);
                dfs(C, y, v, curr_sum + w);
            }
		}
	}

	inline int lca(int a, int b) {
		if (a == b) return a;
		tie(a, b) = minmax(time[a], time[b]);
		return path[rmq.query(a, b)];
	}

	inline int distt(int a, int b) { return dist[a] + dist[b] - 2 * dist[lca(a,b)]; }
	
};

void _dfs(int u, int p, VLL &weight, vector<vector<pii>> &gg, LL curr)
{
    weight[u] += curr;
    for (auto pp : gg[u]) {
        if (pp.ff != p) {
            _dfs(pp.ff, u, weight, gg, curr + pp.ss);
        }
    }
}

int main()
{
    int n, q;
    I(n, q);
    VVI e;
    for (int i = 0; i < 2 * n - 2; i++) {
        int u, v, w;
        I(u, v, w);
        u--; v--;
        e.pb({u, v, w});
    }
    VVI g(n);
    vector<vector<pii>> gg(n);
    for (int i = 0; i < n - 1; i++) {
        int u = e[i][0];
        int v = e[i][1];
        int w = e[i][2];
        g[u].pb(v);
        g[v].pb(u);
        gg[u].pb({v, w});
        gg[v].pb({u, w});
    }
    HLD<0> hld(g);
    LCA lca(gg);
    VI in(n);
    VLL weight(n);
    for (int i = 0; i < SZ(e); i++) {
        if (i >= n - 1) {
            int u = e[i][0];
            in[u] = i;
            weight[u] = e[i][2];
        }
    }
    _dfs(0, -1, weight, gg, 0);
    for (int i = 0; i < n; i++) {
        hld.modifyPath(i, i, weight[i]);
    }
    while (q--) {
        int a, b, c;
        I(a, b, c);
        if (a == 1) {
            b--;
            if (b < n - 1) {
                int u = e[b][0];
                int v = e[b][1];
                hld.modifySubtree(v, c - e[b][2]);
                e[b][2] = c;
            }
            else {
                hld.modifyPath(e[b][0], e[b][0], c - e[b][2]);
                e[b][2] = c;
            }
        }
        else {
            b--;
            c--;
            int l = lca.lca(b, c);
            LL d = hld.queryPath(b, b);
            if (b) d -= e[in[b]][2];
            hld.modifySubtree(b, -d);
            if (l == b) {
                LL ans = hld.queryPath(c, c);
                if (c) ans -= e[in[c]][2];
                O(ans);
            }
            else {
                LL ans = hld.querySubtree(b);
                ans += hld.queryPath(c, c);
                if (c) ans -= e[in[c]][2];
                O(ans);
            }
            hld.modifySubtree(b, d);
        }
    }


    return 0;
}
