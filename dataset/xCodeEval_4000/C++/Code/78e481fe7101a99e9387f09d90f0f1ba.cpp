

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

const int N = 50 + 7;
const int M = 1000 + 7;
 
int n, k;
int a[N][N];
 
bool read () {
	if (scanf("%d%d", &n, &k) != 2)
		return false;
	forn(i, n) forn(j, n)
		scanf("%d", &a[i][j]);
	return true;
}
 
struct edge{
	int v, u, nxt, cap, flow, cost;
	edge(){}
	edge(int v, int u, int nxt, int cap, int flow, int cost = 0) : v(v), u(u), nxt(nxt), cap(cap), flow(flow), cost(cost) {}
};
 
int lst[N];
vector<edge> e;
 
void add_edge(int v, int u, int cap){
	e.pb({v, u, lst[v], cap, 0});
	lst[v] = sz(e) - 1;
	e.pb({u, v, lst[u], 0, 0});
	lst[u] = sz(e) - 1;
}
 
int rem(int x){
	return e[x].cap - e[x].flow;
}
 
void build(){
	memset(lst, -1, sizeof(lst));
	e.clear();
	forn(i, n) forn(j, n) if (i != j)
		add_edge(i, j, a[i][j]);
}
 
int p[N], d[N], fl[N];
 
int bfs(){
	queue<int> q;
	forn(i, n) d[i] = INF;
	d[0] = 0;
	p[0] = -1;
	fl[0] = INF;
	fl[n - 1] = 0;
	q.push(0);
	
	while (!q.empty()){
		int v = q.front();
		q.pop();
		for (int it = lst[v]; it != -1; it = e[it].nxt){
			int u = e[it].u;
			if (rem(it) && d[u] > d[v] + 1){
				d[u] = d[v] + 1;
				fl[u] = min(fl[v], rem(it));
				p[u] = it;
				q.push(u);
			}
		}
	}
	
	if (fl[n - 1] == 0)
		return 0;
	
	int val = fl[n - 1];
	int v = n - 1;
	while (p[v] != -1){
		e[p[v]].flow += val;
		e[p[v] ^ 1].flow -= val;
		v = e[p[v]].v;
	}
	
	return val;
}

int rm[N][N];

void add_edge(int v, int to, int cap, int cost) {
	e.pb({v, to, lst[v], cap, 0, cost});
	lst[v] = sz(e) - 1;
	e.pb({to, v, lst[to], 0, 0, -cost});
	lst[to] = sz(e) - 1;
}

void build2(){
	memset(lst, -1, sizeof(lst));
	e.clear();
	forn(i, n) forn(j, n) if (a[i][j] != 0){
		add_edge(i, j, a[i][j], 0);
		add_edge(i, j, INF, 1);
	}
}

int push() {
	int s = 0, t = n - 1;
	forn(i, N) {
		d[i] = INF;
		p[i] = -1;
	}
	d[s] = 0;
	set<pt> st;
	st.insert(mp(d[s], s));
	while(!st.empty()) {
		int v = st.begin()->y;
		st.erase(st.begin());
		for(int i = lst[v]; i != -1; i = e[i].nxt) {
			if(rem(i) && d[e[i].u] > d[v] + e[i].cost) {
				auto it = st.find(mp(d[e[i].u], e[i].u));
				if(it != st.end()) st.erase(it);
				d[e[i].u] = d[v] + e[i].cost;
				p[e[i].u] = i;
				st.insert(mp(d[e[i].u], e[i].u));
			}
		}
	}
	
	if(d[t] == INF)
		return 0;
	
	int flow = INF;
	int v = t;
	while(v != s) {
		flow = min(flow, rem(p[v]));
		v = e[p[v]].v;
	}
	
	v = t;
	while(v != s) {
		e[p[v]].flow += flow;
		e[p[v] ^ 1].flow -= flow;
		v = e[p[v]].v;
	}
	
	return flow;
}

void solve(){
	
	
	build2();
	int tmp, flow = 0;
	while (true){
		tmp = push();
		int x = min(tmp, d[n - 1] == 0 ? INF : k / d[n - 1]);
		flow += x;
		k -= x * d[n - 1];
		if (x == 0) break;
	}
	
	printf("%d\n", flow);
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