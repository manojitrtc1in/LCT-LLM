



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

const int N = 2000 + 7;

int n, m;
pt a[N], b[N];

bool read () {
	if (scanf("%d%d", &n, &m) != 2)
		return false;
	forn(i, n)
		scanf("%d%d", &a[i].x, &a[i].y);
	forn(i, m)
		scanf("%d%d", &b[i].x, &b[i].y);
	return true;
}

int d[N][N];
vector<int> xs, ys;

struct line{
	li A, B, C;
	line(const pt &a, const pt &b){
		A = a.y - b.y;
		B = b.x - a.x;
		C = -A * a.x - B * a.y;
	}
};

li det(li a, li b, li c, li d){
	return a * d - b * c;
}

int dist[N * 2];
int p[2 * N];
vector<pt> g[N * 2];

void Dijkstra(int s, int &bst){
	forn(i, sz(xs) + sz(ys))
		dist[i] = INF;
	dist[s] = 0;
	p[s] = -1;
	set<pt> q;
	q.insert(mp(0, s));
	while (!q.empty()){
		int v = q.begin()->y;
		q.erase(q.begin());
		if (bst <= dist[v])
			return;
		for (auto it : g[v]){
			int u = it.x;
			int w = it.y;
			if (u != p[v])
				bst = min(bst, max({dist[v], dist[u], w}));
			if (dist[u] > max(dist[v], w)){
				if (q.count(mp(dist[u], u)))
					q.erase(mp(dist[u], u));
				dist[u] = max(dist[v], w);
				q.insert(mp(dist[u], u));
				p[u] = v;
			}
		}
	}
}

void solve(){
	xs.clear();
	ys.clear();
	forn(i, n) xs.pb(a[i].x + a[i].y);
	sort(all(xs));
	xs.resize(unique(all(xs)) - xs.begin());
	forn(i, m) ys.pb(b[i].x - b[i].y);
	sort(all(ys));
	ys.resize(unique(all(ys)) - ys.begin());
	
	if (sz(xs) < 2 || sz(ys) < 2){
		puts("Poor Sereja!");
		return;
	}
	
	forn(i, sz(xs)) forn(j, sz(ys)) d[i][j] = INF;
	forn(i, n) forn(j, m){
		line l1(mp(a[i].x - 1, a[i].y + 1), mp(a[i].x + 1, a[i].y - 1));
		line l2(mp(b[j].x + 1, b[j].y + 1), mp(b[j].x - 1, b[j].y - 1));
		li Dx = det(l1.C, l1.B, l2.C, l2.B);
		li D  = det(l1.A, l1.B, l2.A, l2.B);
		int x = lower_bound(all(xs), a[i].x + a[i].y) - xs.begin();
		int y = lower_bound(all(ys), b[j].x - b[j].y) - ys.begin();
		d[x][y] = min(d[x][y], int((max(abs(-Dx * 2 / D - a[i].x * 2), abs(-Dx * 2 / D - b[j].x * 2)) + 1) / 2));
	}
	
	forn(i, sz(xs) + sz(ys))
		g[i].clear();
	forn(i, sz(xs)) forn(j, sz(ys)){
		g[i].pb(mp(sz(xs) + j, d[i][j]));
		g[sz(xs) + j].pb(mp(i, d[i][j]));
	}
	
	int ans = INF;
	forn(i, n) Dijkstra(i, ans);
	printf("%d\n", ans);
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