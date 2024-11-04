



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

const int N = 2000 + 7;

int n, m, r;
pair<pt, int> a[N];

bool read () {
	if (scanf("%d%d%d", &n, &m, &r) != 3)
		return false;
	forn(i, n){
		scanf("%d%d%d", &a[i].x.x, &a[i].x.y, &a[i].y);
		--a[i].x.x, --a[i].x.y;
	}
	return true;
}

int pr[N][N];
bool used[N][N];

int sum(int x1, int y1, int x2, int y2){
	x1 = max(x1, 0), y1 = max(y1, 0);
	x2 = min(x2, N - 1), y2 = min(y2, N - 1);
	return pr[x2][y2] - pr[x1][y2] - pr[x2][y1] + pr[x1][y1];
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

int fact[N], rfact[N];

int ank(int n, int k){
	if (n < 0 || k < 0 || n < k) return 0;
	return mul(fact[n], mul(rfact[k], rfact[n - k]));
}

void solve() {
	memset(used, 0, sizeof(used));
	forn(i, n) used[a[i].x.x][a[i].x.y] =  true;
	forn(i, N - 1) forn(j, N - 1)
		pr[i + 1][j + 1] = pr[i + 1][j] + pr[i][j + 1] - pr[i][j] + used[i][j];
	fact[0] = 1;
	fore(i, 1, N) fact[i] = mul(fact[i - 1], i);
	rfact[N - 1] = binpow(fact[N - 1], MOD - 2);
	for (int i = N - 2; i >= 0; --i)
		rfact[i] = mul(rfact[i + 1], i + 1);
	
	int ans = 0;
	forn(i, n) forn(j, n){
		int xa = a[i].x.x, ya = a[i].x.y;
		int xb = a[j].x.x, yb = a[j].x.y;
		int prod = mul(a[i].y, a[j].y);
		int tota = sum(xa - r, ya - r, xa + r + 1, ya + r + 1);
		int totb = sum(xb - r, yb - r, xb + r + 1, yb + r + 1);
		int cnta = ank(n - tota, m);
		int cntb = ank(n - totb, m);
		int totab = tota + totb;
		int xl = max(xa - r, xb - r), xr = min(xa + r + 1, xb + r + 1);
		int yl = max(ya - r, yb - r), yr = min(ya + r + 1, yb + r + 1);
		if (xl < xr && yl < yr) totab -= sum(xl, yl, xr, yr);
		int cntab = ank(n - totab, m);
		int cnt = ank(n, m);
		

		ans = add(ans, mul(prod, add(add(cnt, -cnta), add(-cntb, cntab))));
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