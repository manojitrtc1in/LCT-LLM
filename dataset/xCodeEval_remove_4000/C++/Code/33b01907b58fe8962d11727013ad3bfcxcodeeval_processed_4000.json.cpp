



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
const int P = 350;

int n;
pt a[N];

bool read () {
	if (scanf("%d", &n) != 1)
		return false;
	forn(i, n)
		scanf("%d%d", &a[i].x, &a[i].y);
	return true;
}

vector<int> pts[N];
vector<int> hv;

void solve() {
	forn(i, N) pts[i].clear();
	sort(a, a + n);
	forn(i, n) pts[a[i].x].pb(a[i].y);
	hv.clear();
	forn(x, N) if (sz(pts[x]) > P)
		hv.pb(x);
	int cnt = 0;
	forn(x, N) if (sz(pts[x]) <= P){
		forn(i, sz(pts[x])) forn(j, i){
			int dx = pts[x][i] - pts[x][j];
			if (x - dx >= 0 && binary_search(all(pts[x - dx]), pts[x][j]) && binary_search(all(pts[x - dx]), pts[x][i]))
				++cnt;
			if (x + dx < N && sz(pts[x + dx]) > P && binary_search(all(pts[x + dx]), pts[x][j]) && binary_search(all(pts[x + dx]), pts[x][i]))
				++cnt;
		}
	}
	forn(ir, sz(hv)){
		int xr = hv[ir];
		for (auto y : pts[xr]) forn(il, ir){
			int xl = hv[il];
			if (!binary_search(all(pts[xl]), y))
				continue;
			int dy = xr - xl;
			if (y - dy >= 0 && binary_search(all(pts[xl]), y - dy) && binary_search(all(pts[xr]), y - dy))
				++cnt;
		}
	}
	printf("%d\n", cnt);
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