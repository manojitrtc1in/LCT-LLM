



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
const int LOGN = 35;

int n;
int p[N];
int a[N];

bool read () {
	if (scanf("%d", &n) != 1)
		return false;
	forn(i, n){
		scanf("%d", &p[i]);
		--p[i];
	}
	forn(i, n){
		scanf("%d", &a[i]);
		--a[i];
	}
	return true;
}

int up[N][LOGN];

int get(int v, li k){
	forn(i, LOGN) if ((k >> i) & 1)
		v = up[v][i];
	return v;
}

vector<int> init[N];
int ans[N];
int mx[N];

bool in[N];

void solve() {
	memset(in, 0, sizeof(in));
	forn(i, n) in[p[i]] = true;
	int cntmx = 0;
	forn(i, n) cntmx += !in[i];
	int cnt = (*max_element(a, a + n) - (n - 1)) / cntmx;
	cerr << cnt << endl;
	forn(i, n) up[i][0] = p[i];
	fore(j, 1, LOGN) forn(i, n)
		up[i][j] = up[up[i][j - 1]][j - 1];
	forn(i, n) init[i].clear();
	forn(i, n) init[get(i, cnt)].pb(i);
	memset(ans, -1, sizeof(ans));
	forn(i, n) if (!init[i].empty()){
		sort(all(init[i]));
		ans[init[i][0]] = a[i];
		for (int v : init[i]) mx[v] = a[i];
	}
	set<int> lft;
	forn(i, n) lft.insert(i);
	forn(i, n) if (ans[i] != -1) lft.erase(ans[i]);
	forn(i, n) if (ans[i] == -1){
		auto it = lft.lower_bound(mx[i]);
		assert(it != lft.end());
		ans[i] = *it;
		lft.erase(it);
	}
	forn(i, n) printf("%d ", ans[i] + 1);
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