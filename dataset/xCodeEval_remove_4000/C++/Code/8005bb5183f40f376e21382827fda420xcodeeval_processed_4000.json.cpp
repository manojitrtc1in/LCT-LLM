



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

const int N = 100 * 1000 + 13;

int n;
int a[6];
int b[N];

bool read () {
	if (scanf("%d", &a[0]) != 1)
		return false;
	fore(i, 1, 6)
		scanf("%d", &a[i]);
	scanf("%d", &n);
	forn(i, n)
		scanf("%d", &b[i]);
	return true;
}

vector<int> xs;
vector<pt> upd[N * 6];
int val[N][6];

void solve() {
	sort(a, a + 6);
	int m = unique(a, a + 6) - a;
	sort(b, b + n);
	
	xs.clear();
	forn(i, n) forn(j, m) xs.pb(b[i] - a[j]);
	sort(all(xs));
	xs.resize(unique(all(xs)) - xs.begin());
	forn(i, n) forn(j, m) val[i][j] = lower_bound(all(xs), b[i] - a[j]) - xs.begin();
	
	int ans = INF;
	
	forn(i, sz(xs)) upd[i].clear();
	int mx = 0;
	forn(i, n){
		upd[val[i][m - 1]].pb(mp(i, m - 1));
		mx = max(mx, xs[val[i][m - 1]]);
	}
	
	forn(i, sz(xs)){
		ans = min(ans, mx - xs[i]);
		bool ok = true;
		for (auto it : upd[i]){
			if (it.y == 0){
				ok = false;
				break;
			}
			--it.y;
			mx = max(mx, xs[val[it.x][it.y]]);
			upd[val[it.x][it.y]].pb(it);
		}
		if (!ok) break;
	}
	printf("%d\n", ans);
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