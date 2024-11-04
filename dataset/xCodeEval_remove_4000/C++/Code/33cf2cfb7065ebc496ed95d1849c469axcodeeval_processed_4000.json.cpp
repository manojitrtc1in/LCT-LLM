



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

const int N = 100 + 7;
const int M = 1000 * 1000 + 13;

int n, m;
pair<pt, pt> e[M];

bool read () {
	if (scanf("%d%d", &n, &m) != 2)
		return false;
	forn(i, m){
		scanf("%d%d%d%d", &e[i].x.x, &e[i].x.y, &e[i].y.x, &e[i].y.y);
		--e[i].x.x, --e[i].x.y;
	}
	return true;
}

int lst[M];

void init(){
	iota(lst, lst + M, 0);
	for (int i = 2; i < M; ++i){
		if (lst[i] != i) continue;
		for (li j = i * li(i); j < M; j += i)
			lst[j] = i;
	}
}

int a[N], b[N];
vector<pair<int, pt>> g[N];
vector<pair<int, pt>> es[M];

vector<int> cur;

bool fix(int v){
	cur.pb(v);
	bool res = true;
	for (auto it : g[v]){
		int u = it.x;
		if (b[v] != it.y.x && b[v] != it.y.y)
			return false;
		int x = it.y.x, y = it.y.y;
		if (b[v] != x) swap(x, y);
		if (b[u] == -1){
			b[u] = y;
			res &= fix(u);
		}
		else if (b[u] != y){
			res = false;
		}
		if (!res) return false;
	}
	return true;
}

void solve() {
	init();
	forn(i, M)
		es[i].clear();
	forn(i, m){
		int x = e[i].y.x;
		vector<pt> tmpx, tmpy;
		vector<int> tot;
		while (x > 1){
			int t = lst[x];
			int cnt = 0;
			while (x % t == 0){
				++cnt;
				x /= t;
			}
			tot.pb(t);
			tmpx.pb(mp(t, cnt));
		}
		int y = e[i].y.y;
		sort(all(tmpx));
		while (y > 1){
			int t = lst[y];
			int cnt = 0;
			while (y % t == 0){
				++cnt;
				y /= t;
			}
			tot.pb(t);
			tmpy.pb(mp(t, cnt));
		}
		sort(all(tmpy));
		sort(all(tot));
		tot.resize(unique(all(tot)) - tot.begin());
		for (auto it : tot){
			int v1 = lower_bound(all(tmpx), mp(it, -1)) - tmpx.begin();
			if (v1 < sz(tmpx) && tmpx[v1].x == it) v1 = tmpx[v1].y;
			else v1 = 0;
			int v2 = lower_bound(all(tmpy), mp(it, -1)) - tmpy.begin();
			if (v2 < sz(tmpy) && tmpy[v2].x == it) v2 = tmpy[v2].y;
			else v2 = 0;
			es[it].pb(mp(i, mp(v1, v2)));
		}
	}
	
	forn(i, n) a[i] = 1;
	forn(p, M) if (!es[p].empty()){
		forn(i, n) g[i].clear();
		vector<char> used(m);
		for (auto it : es[p]){
			if (it.y.x > it.y.y){
				puts("NO");
				return;
			}
			g[e[it.x].x.x].pb(mp(e[it.x].x.y, it.y));
			g[e[it.x].x.y].pb(mp(e[it.x].x.x, it.y));
			used[it.x] = true;
		}
		

		forn(i, m) if (!used[i]){
			g[e[i].x.x].pb(mp(e[i].x.y, mp(0, 0)));
			g[e[i].x.y].pb(mp(e[i].x.x, mp(0, 0)));
		}
		forn(i, n) b[i] = -1;
		forn(i, n) if (b[i] == -1){
			if (g[i].empty()){
				b[i] = 0;
				continue;
			}
			vector<int> vals({g[i][0].y.x, g[i][0].y.y});
			bool ok = false;
			for (auto it : vals){
				cur.clear();
				b[i] = it;
				if (!fix(i)){
					for (auto v : cur)
						b[v] = -1;
				}
				else{
					ok = true;
					break;
				}
			}
			if (!ok){
				puts("NO");
				return;
			}
		}
		

		

		

		int mx = 0;
		forn(i, n) mx = max(mx, b[i]);
		vector<int> cur(1, 1);
		fore(i, 1, mx + 1) cur.pb(cur.back() * p);
		forn(i, n) a[i] *= cur[b[i]];
	}
	
	forn(i, m){
		int v = e[i].x.x;
		int u = e[i].x.y;
		int g = e[i].y.x;
		int l = e[i].y.y;
		if (__gcd(a[v], a[u]) != g || a[v] * li(a[u]) / __gcd(a[v], a[u]) != l){
			puts("NO");
			return;
		}
	}
	
	puts("YES");
	forn(i, n) printf("%d ", a[i]);
	puts("");
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