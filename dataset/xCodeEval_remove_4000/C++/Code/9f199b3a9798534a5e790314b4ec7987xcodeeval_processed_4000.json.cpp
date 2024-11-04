



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
const int MOD = 998244353;
const ld EPS = 1e-9;
const ld PI = acos(-1.0);

const int N = 200 * 1000 + 13;
const int M = 20;

int n, m;
vector<int> g[N], tg[N];

bool read () {
	if (scanf("%d%d", &n, &m) != 2)
		return false;
	forn(i, n)
		g[i].clear(), tg[i].clear();
	forn(i, m){
		int v, u;
		scanf("%d%d", &v, &u);
		--v, --u;
		g[v].pb(u);
		tg[u].pb(v);
	}
	return true;
}

li d[N][M];

void id0(){
	set<pair<li, pt>> q;
	forn(i, n) forn(j, M) d[i][j] = INF64;
	d[0][0] = 0;
	q.insert(mp(d[0][0], mp(0, 0)));
	while (!q.empty()){
		int v = q.begin()->y.x;
		int cnt = q.begin()->y.y;
		q.erase(q.begin());
		if (cnt + 1 < M && d[v][cnt + 1] > d[v][cnt] + (1ll << cnt)){
			if (q.count(mp(d[v][cnt + 1], mp(v, cnt + 1))))
				q.erase(mp(d[v][cnt + 1], mp(v, cnt + 1)));
			d[v][cnt + 1] = d[v][cnt] + (1ll << cnt);
			q.insert(mp(d[v][cnt + 1], mp(v, cnt + 1)));
		}
		if (cnt & 1){
			for (int u : tg[v]) if (d[u][cnt] > d[v][cnt] + 1){
				if (q.count(mp(d[u][cnt], mp(u, cnt))))
					q.erase(mp(d[u][cnt], mp(u, cnt)));
				d[u][cnt] = d[v][cnt] + 1;
				q.insert(mp(d[u][cnt], mp(u, cnt)));
			}
		}
		else{
			for (int u : g[v]) if (d[u][cnt] > d[v][cnt] + 1){
				if (q.count(mp(d[u][cnt], mp(u, cnt))))
					q.erase(mp(d[u][cnt], mp(u, cnt)));
				d[u][cnt] = d[v][cnt] + 1;
				q.insert(mp(d[u][cnt], mp(u, cnt)));
			}
		}
	}
}

pair<int, li> d2[N][2];
int pw[N];

void id1(){
	set<pair<pair<int, li>, pt>> q;
	forn(i, n) forn(j, 2){
		if (d[i][M - (2 - j)] == INF64)
			d2[i][j] = mp(INF, INF64);
		else
			d2[i][j] = mp(M - (2 - j), d[i][M - (2 - j)] - ((1ll << (M - (2 - j))) - 1));
		q.insert(mp(d2[i][j], mp(i, j)));
	}
	while (!q.empty()){
		int v = q.begin()->y.x;
		int cnt = q.begin()->y.y;
		q.erase(q.begin());
		if (d2[v][cnt ^ 1] > mp(d2[v][cnt].x + 1, d2[v][cnt].y)){
			q.erase(mp(d2[v][cnt ^ 1], mp(v, cnt ^ 1)));
			d2[v][cnt ^ 1] = mp(d2[v][cnt].x + 1, d2[v][cnt].y);
			q.insert(mp(d2[v][cnt ^ 1], mp(v, cnt ^ 1)));
		}
		if (cnt){
			for (int u : tg[v]) if (d2[u][cnt] > mp(d2[v][cnt].x, d2[v][cnt].y + 1)){
				q.erase(mp(d2[u][cnt], mp(u, cnt)));
				d2[u][cnt] = mp(d2[v][cnt].x, d2[v][cnt].y + 1);
				q.insert(mp(d2[u][cnt], mp(u, cnt)));
			}
		}
		else{
			for (int u : g[v]) if (d2[u][cnt] > mp(d2[v][cnt].x, d2[v][cnt].y + 1)){
				q.erase(mp(d2[u][cnt], mp(u, cnt)));
				d2[u][cnt] = mp(d2[v][cnt].x, d2[v][cnt].y + 1);
				q.insert(mp(d2[u][cnt], mp(u, cnt)));
			}
		}
	}
}

void solve() {
	id0();
	id1();
	pw[0] = 1;
	fore(i, 1, N) pw[i] = pw[i - 1] * 2 % MOD;
	pair<int, li> ans = min(d2[n - 1][0], d2[n - 1][1]);
	forn(i, M) if (d[n - 1][i] != INF64 && (ans.x > M || d[n - 1][i] < ((1ll << ans.x) - 1) + ans.y))
		ans = mp(i, d[n - 1][i] - ((1ll << i) - 1));
	int res = (pw[ans.x] + ans.y % MOD) % MOD;
	res = (res - 1 + MOD) % MOD;
	printf("%d\n", res);
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