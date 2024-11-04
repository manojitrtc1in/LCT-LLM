



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

const int N = 3600 + 7;

int n, m, k;
pair<pt, pt> a[N];

bool read () {
	if (scanf("%d%d%d", &n, &m, &k) != 3)
		return false;
	forn(i, k){
		scanf("%d%d%d%d", &a[i].x.x, &a[i].x.y, &a[i].y.x, &a[i].y.y);
		--a[i].x.x, --a[i].x.y, --a[i].y.x, --a[i].y.y;
	}
	return true;
}

int add(int a, int b){
	a += b;
	if (a >= MOD)
		a -= MOD;
	if (a < 0)
		a += MOD;
	return a;
}

int mul(int a, int b){
	return a * li(b) % MOD;
}

int binpow(int a, int b){
	int res = 1;
	while (b){
		if (b & 1)
			res = mul(res, a);
		a = mul(a, a);
		b >>= 1;
	}
	return res;
}

int dpn[N], dpm[N];
bool used[N];

void calc(int res[N], int n){
	static int dp[N][N];
	memset(dp, 0, sizeof(dp));
	dp[0][0] = 1;
	forn(i, n) forn(j, i + 1) if (dp[i][j]){
		dp[i + 1][j] = add(dp[i + 1][j], dp[i][j]);
		if (i + 2 <= n && !used[i] && !used[i + 1])
			dp[i + 2][j + 1] = add(dp[i + 2][j + 1], dp[i][j]);
	}
	forn(i, N){
		res[i] = dp[n][i];
	}
}

int fact[N], rfact[N];

int ank(int n, int k){
	return mul(fact[n], rfact[n - k]);
}

void solve(){
	memset(used, 0, sizeof(used));
	forn(i, k) used[a[i].x.x] = used[a[i].y.x] = true;
	int totn = 0;
	forn(i, n) totn += !used[i];
	calc(dpn, n);
	memset(used, 0, sizeof(used));
	forn(i, k) used[a[i].x.y] = used[a[i].y.y] = true;
	int totm = 0;
	forn(i, m) totm += !used[i];
	calc(dpm, m);
	
	fact[0] = 1;
	fore(i, 1, N) fact[i] = mul(fact[i - 1], i);
	rfact[N - 1] = binpow(fact[N - 1], MOD - 2);
	for (int i = N - 2; i >= 0; --i)
		rfact[i] = mul(rfact[i + 1], i + 1);
	
	int ans = 0;
	forn(h, N) forn(w, N) if (totn - 2 * h >= w && totm - 2 * w >= h)
		ans = add(ans, mul(mul(dpn[h], dpm[w]), mul(ank(totn - 2 * h, w), ank(totm - 2 * w, h))));
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