



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
const int MOD = INF + 7;
const ld EPS = 1e-9;
const ld PI = acos(-1.0);

const int N = 100 * 1000 + 13;

int n, m, c, q;

bool read () {
	if (scanf("%d%d%d%d", &n, &m, &c, &q) != 4)
		return false;
	return true;
}

set<pair<int, int>> g[N];

int p[N];
set<int> out[N];

int getP(int a){
	return (a == p[a] ? a : p[a] = getP(p[a]));
}

void unite(int a, int b){
	a = getP(a), b = getP(b);
	if (a == b) return;
	if (sz(out[a]) < sz(out[b])) swap(a, b);
	p[b] = a;
	for (auto it : out[b])
		out[a].insert(it);
}

void add(int v, int u, int w){
	auto it = g[v].lower_bound(mp(w, -1));
	if (it != g[v].end() && it->x == w)
		unite(u, it->y);
	else
		g[v].insert(mp(w, u));
	it = g[u].lower_bound(mp(w, -1));
	if (it != g[u].end() && it->x == w)
		unite(v, it->y);
	else
		g[u].insert(mp(w, v));
	out[getP(v)].insert(u);
	out[getP(u)].insert(v);
}

bool ask(int v, int u){
	if (getP(v) == getP(u))
		return true;
	if (out[getP(v)].count(u))
		return true;
	return false;
}

void solve() {
	forn(i, n) p[i] = i;
	forn(i, n) g[i].clear(), out[i].clear();
	
	forn(i, m){
		int v, u, w;
		scanf("%d%d%d", &v, &u, &w);
		add(v - 1, u - 1, w);
	}
	
	forn(i, q){
		static char buf[10];
		scanf("%s", buf);
		if (buf[0] == '+'){
			int v, u, w;
			scanf("%d%d%d", &v, &u, &w);
			add(v - 1, u - 1, w);
		}
		else{
			int v, u;
			scanf("%d%d", &v, &u);
			puts(ask(v - 1, u - 1) ? "Yes" : "No");
		}
	}
}

int main() {

	freopen("input.txt", "r", stdin);


	
	int tt = clock();
	

	
	cerr.precision(15);
	cout.precision(15);
	cerr << fixed;
	cout << fixed;

	while(read()) {	
		solve();
		

	cerr << "TIME = " << clock() - tt << endl;
	tt = clock();


	}
}