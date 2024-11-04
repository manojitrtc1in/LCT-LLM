

#include <bits/stdc++.h>

using namespace std;




#define x first
#define y second
#define mp make_pair
#define pb push_back
#define sqr(a) ((a) * (a))
#define sz(a) int(a.size())
#define all(a) a.begin(), a.end()
#define forn(i, n) for(int i = 0; i < int(n); i++) 
#define fore(i, l, r) for(int i = int(l); i < int(r); i++)

typedef long long li;
typedef long double ld;
typedef pair<int, int> pt;

template <class A, class B> ostream& operator << (ostream& out, const pair<A, B> &a) {
	return out << "(" << a.x << ", " << a.y << ")";
}

template <class A> ostream& operator << (ostream& out, const vector<A> &v) {
	out << "[";
	forn(i, sz(v)) {
		if(i) out << ", ";
		out << v[i];
	}
	return out << "]";
}

mt19937 rnd(time(NULL));

const int INF = int(1e9);
const li INF64 = li(1e18);
const int MOD = int(1e9) + 7;
const ld EPS = 1e-9;
const ld PI = acos(-1.0);




template<typename T, typename C>
struct mincost {
	const C MAX_COST = numeric_limits<C>::max();

	struct edge {
		int v, u;
		T cap, flow;
		C cost;
	};
	int n, s, t;
	T flow;
	C cost;
	vector<int> p;
	vector<C> d;
	vector<edge> e;
	vector<bool> inq;
	vector<vector<int>> g;
	
	mincost() {}
	
	mincost(int n, int s, int t) : n(n), s(s), t(t) {
		g.resize(n);
		d.resize(n);
		p.resize(n);
		inq.resize(n);
		flow = 0;
		cost = 0;
	}
	
	void add_edge(int v, int u, T cap, C cost) {
		g[v].pb(sz(e));
		e.pb({v, u, cap, 0, cost});
		g[u].pb(sz(e));
		e.pb({u, v, 0, 0, -cost});
	}
	
	T rem(int i) {
		return e[i].cap - e[i].flow;
	}
	
	T push(T lim) {
		fill(all(d), MAX_COST);
		fill(all(p), -1);
		d[s] = 0;
		
		queue<int> q;
		q.push(s);
		
		while (!q.empty()) {
			int v = q.front();
			q.pop();
			inq[v] = false;
			for (int i : g[v]) {
				int u = e[i].u;
				if (rem(i) > 0 && d[u] > d[v] + e[i].cost) {
					d[u] = d[v] + e[i].cost;
					p[u] = i;
					if (!inq[u]) {
                 	   inq[u] = true;
                 	   q.push(u);
                	}
				}
			}
		}
		
		if (d[t] == MAX_COST) {
			return 0;
		}
			
		T cur_flow = lim;
		int v = t;
		while (v != s) {
			cur_flow = min(cur_flow, rem(p[v]));
			v = e[p[v]].v;
		}
		
		v = t;
		while (v != s) {
			e[p[v]].flow += cur_flow;
			e[p[v] ^ 1].flow -= cur_flow;
			v = e[p[v]].v;
		}
		
		return cur_flow;
	}
	
	void calc(T k = numeric_limits<T>::max()) {
		T add = 0;
		while ((add = push(k - flow)) > 0) {
			flow += add;
			cost += d[t] * add;
		}
	}
};

const int N = 1000 + 7;

int n, k;
pair<pt, int> a[N];

bool read () {
	if (scanf("%d%d", &n, &k) != 2)
		return false;
	forn(i, n)
		scanf("%d%d%d", &a[i].x.x, &a[i].x.y, &a[i].y);
	return true;
}

void solve() {
	vector<int> vts;
	vts.pb(0);
	forn(i, n) vts.pb(a[i].x.x), vts.pb(a[i].x.x + a[i].x.y);
	vts.pb(2 * INF + 2);
	sort(all(vts));
	vts.resize(unique(all(vts)) - vts.begin());
	
	int s = 0, t = sz(vts) - 1;
	mincost<int, int> mcmf(sz(vts), s, t);
	forn(i, sz(vts) - 1) mcmf.add_edge(i, i + 1, k, 0);
	forn(i, n) mcmf.add_edge(lower_bound(all(vts), a[i].x.x) - vts.begin(), lower_bound(all(vts), a[i].x.x + a[i].x.y) - vts.begin(), 1, -a[i].y);
	mcmf.calc(k);
	cerr << -mcmf.cost << endl;
	for (int i = 2 * (sz(vts) - 1); i < sz(mcmf.e); i += 2)
		printf("%d ", mcmf.rem(i) == 0);
	puts("");
}

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);


	
	int tt = clock();
	
#endif
	
	cerr.precision(15);
	cout.precision(15);
	cerr << fixed;
	cout << fixed;

#ifdef MULTITEST
	int tc;
	scanf("%d", &tc);
	while(tc--){
		read();
#else
	while(read()) {	
#endif
		solve();
		
#ifdef _DEBUG
	cerr << "TIME = " << clock() - tt << endl;
	tt = clock();
#endif

	}
}