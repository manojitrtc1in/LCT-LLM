

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
const int MOD = INF + 7;
const ld EPS = 1e-9;
const ld PI = acos(-1.0);

const int N = 1000 * 1000 + 13;

int cnt;
int n, m;
vector<pt> g[N];

void add_edge(int v, int u, int w){
	g[v].pb(mp(u, w));
}

void add(int v, int u, int x){
	while (x){
		add_edge((x < 10 ? v : cnt), u, x % 10);
		x /= 10;
		if (x){
			u = cnt;
			++cnt;
		}
	}
}

bool read () {
	if (scanf("%d%d", &n, &m) != 2)
		return false;
	forn(i, N)
		g[i].clear();
	cnt = n;
	forn(i, m){
		int v, u;
		scanf("%d%d", &v, &u);
		--v, --u;
		add(v, u, i + 1);
		add(u, v, i + 1);
	}
	return true;
}

struct dist{
	int l, p, ans;
	dist(){}
	dist(int l, int p, int ans) : l(l), p(p), ans(ans) {}
};

ostream& operator << (ostream& out, const dist &a) {
	return out << "(" << a.l << ", " << a.p << ", " << a.ans << ")";
}

int add(int a, int b){
	a += b;
	if (a >= MOD)
		a -= MOD;
	return a;
}

int mul(int a, int b){
	return a * li(b) % MOD;
}

bool operator <(const dist &a, const dist &b){
	if (a.l != b.l)
		return a.l < b.l;
	if (a.p != b.p)
		return a.p < b.p;
	return a.ans < b.ans;
}

dist d[N];
int cl[N];

void Dijkstra(){
	forn(i, cnt)
		d[i] = dist(INF, INF, INF);
	
	set<pair<dist, int>> q;
	d[0] = dist(0, 0, 0);
	q.insert(mp(d[0], 0));
	int prv = -1;
	while (!q.empty()){
		int v = q.begin()->y;
		q.erase(q.begin());
		
		if (prv == -1) cl[v] = 0;
		else cl[v] = cl[prv] + (d[prv] < d[v]);
		prv = v;
		
		for (auto it : g[v]){
			int u = it.x;
			int w = it.y;
			dist nd(d[v].l + 1, cl[v], add(w, mul(10, d[v].ans)));
			if (nd < d[u]){
				if (q.count(mp(d[u], u)))
					q.erase(mp(d[u], u));
				d[u] = nd;
				q.insert(mp(d[u], u));
			}
		}
	}
}

void solve(){
	Dijkstra();
	fore(i, 1, n) printf("%d\n", d[i].ans);
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

	if(read()) {	
		solve();
		
#ifdef _DEBUG
	cerr << "TIME = " << clock() - tt << endl;
	tt = clock();
#endif

	}
}