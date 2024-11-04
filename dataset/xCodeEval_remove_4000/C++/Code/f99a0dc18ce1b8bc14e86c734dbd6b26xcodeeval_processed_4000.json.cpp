



using namespace std;














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

const int N = 200 + 7;

int n, m;
string s[N];

bool read () {
	if (scanf("%d%d", &n, &m) != 2)
		return false;
	static char buf[N];
	forn(i, n){
		scanf("%s", buf);
		s[i] = buf;
	}
	return true;
}




template<typename T>
struct dinic {
	struct edge {
		int u, rev;
		T cap, flow;
	};
	
	int n, s, t;
	T flow;
	vector<int> lst;
	vector<int> d;
	vector<vector<edge>> g;
	
	T id0;
	bool scaling;
	
	dinic() {}
	
	dinic(int n, int s, int t, bool scaling = false) : n(n), s(s), t(t), scaling(scaling) {
		g.resize(n);
		d.resize(n);
		lst.resize(n);
		flow = 0;
	}
 
	void add_edge(int v, int u, T cap, bool directed = true) {
		g[v].pb({u, sz(g[u]), cap, 0});
		g[u].pb({v, sz(g[v]) - 1, directed ? 0 : cap, 0});
	}
 
	T dfs(int v, T flow) {
		if (v == t)
			return flow;
		if (flow == 0)
			return 0;
		T result = 0;
		for (; lst[v] < sz(g[v]); ++lst[v]) {
			edge& e = g[v][lst[v]];
			if (d[e.u] != d[v] + 1)
				continue;
			T add = dfs(e.u, min(flow, e.cap - e.flow));
			if (add > 0) {
				result += add;
				flow -= add;
				e.flow += add;
				g[e.u][e.rev].flow -= add;
			}
			if (flow == 0)
				break;
		}
		return result;
	}
 
	bool bfs() {
		fill(all(d), -1);
		queue<int> q({s});
		d[s] = 0;
		while (!q.empty() && d[t] == -1) {
			int v = q.front(); q.pop();
 			for (auto& e : g[v]) {
				if (d[e.u] == -1 && e.cap - e.flow >= id0) {
					q.push(e.u);
					d[e.u] = d[v] + 1;
				}
			}
		}
		return d[t] != -1;
	}
 
	T calc() {
		T max_lim = numeric_limits<T>::max() / 2 + 1;
		for (id0 = scaling ? max_lim : 1; id0 > 0; id0 >>= 1) {
			while (bfs()) {
				fill(all(lst), 0);
				T add;
				while((add = dfs(s, numeric_limits<T>::max())) > 0)
				flow += add;
			}
		}	
		return flow;
	}
	
	vector<bool> min_cut() {
		vector<bool> res(n);
		forn(i, n) res[i] = (d[i] != -1);
		return res;
	}
};

void solve() {
	int S = 2 * n * m;
	int T = S + 1;
	dinic<int> mf(T + 1, S, T);
	
	forn(i, 2 * n) forn(j, m){
		if (i & 1)
			mf.add_edge(S, i * m + j, 1);
		else
			mf.add_edge(i * m + j, T, 1);
	}
	
	forn(i, n - 1) forn(j, m - 1) if (s[i][j] == '
		mf.add_edge((2 * i + 1) * m + j, (2 * i) * m + j, 1);
	forn(i, n - 1) fore(j, 1, m) if (s[i][j] == '
		mf.add_edge((2 * i + 1) * m + j, (2 * i) * m + j - 1, 1);
	fore(i, 1, n) fore(j, 1, m) if (s[i][j] == '
		mf.add_edge((2 * i - 1) * m + j, (2 * i) * m + j - 1, 1);
	fore(i, 1, n) forn(j, m - 1) if (s[i][j] == '
		mf.add_edge((2 * i - 1) * m + j, (2 * i) * m + j, 1);
	
	int tot = 0, sum = 0;
	forn(i, n) forn(j, m) if (s[i][j] == '
		++sum;
		if (j < m - 1 && s[i][j + 1] == '
		if (i < n - 1 && s[i + 1][j] == '
	}
	
	int ans = mf.calc();
	printf("%d\n", sum - (tot - ans));
}

int main() {

	freopen("input.txt", "r", stdin);


	
	int tt = clock();
	

	
	cerr.precision(15);
	cout.precision(15);
	cerr << fixed;
	cout << fixed;


	int tc;
	scanf("%d", &tc);
	while(tc--){
		read();

	while(read()) {	

		solve();
		

	cerr << "TIME = " << clock() - tt << endl;
	tt = clock();


	}
}