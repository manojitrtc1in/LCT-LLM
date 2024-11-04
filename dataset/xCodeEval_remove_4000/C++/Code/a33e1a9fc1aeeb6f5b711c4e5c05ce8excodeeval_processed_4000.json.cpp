



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

const int N = 4000 + 7;

int n;
int a[N];

bool read () {
	if (scanf("%d", &n) != 1)
		return false;
	forn(i, n)
		scanf("%d", &a[i]);
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

int dif[N];
int len[N];

int dpo[2][N][11], dpe[2][N][11];

void calc(const vector<int> &a, int dp[2][N][11]){
	forn(i, 2) forn(j, sz(a) + 1) forn(k, 11)
		dp[i][j][k] = 0;
	dp[0][0][0] = 1;
	forn(ii, sz(a)){
		int i = ii & 1;
		int ni = i ^ 1;
		forn(j, sz(a) + 1) forn(k, 11)
			dp[ni][j][k] = 0;
		forn(j, ii + 1) forn(k, 11) if (dp[i][j][k]){
			dp[ni][j][(k + a[ii] + 11) % 11] = add(dp[ni][j][(k + a[ii] + 11) % 11], dp[i][j][k]);
			dp[ni][j + 1][(k - a[ii] + 11) % 11] = add(dp[ni][j + 1][(k - a[ii] + 11) % 11], dp[i][j][k]);
		}
	}
}

int fact[N];
int rfact[N];

int cnk(int n, int k){
	if (k == n) return 1;
	if (k < 0 || n < 0 || k > n) return 0;
	return mul(fact[n], mul(rfact[n - k], rfact[k]));
}

int snb(int pos, int cnt){
	return cnk(cnt + pos - 1, pos - 1);
}

void solve() {
	fact[0] = 1;
	fore(i, 1, N) fact[i] = mul(fact[i - 1], i);
	rfact[N - 1] = binpow(fact[N - 1], MOD - 2);
	for (int i = N - 2; i >= 0; --i)
		rfact[i] = mul(rfact[i + 1], i + 1);
	
	vector<int> o, e;
	forn(i, n){
		int fl = 1;
		dif[i] = 0;
		while (a[i] > 0){
			dif[i] += fl * (a[i] % 10);
			a[i] /= 10;
			fl = -fl;
		}
		dif[i] %= 11;
		if (dif[i] < 0)
			dif[i] += 11;
		len[i] = fl == -1;
		if (len[i])
			o.pb(dif[i]);
		else
			e.pb(dif[i]);
	}
	
	calc(o, dpo);
	calc(e, dpe);
	
	int ans = 0;
	forn(i, sz(e) + 1) forn(j, 11){
		int pt1 = mul(dpe[sz(e) & 1][i][j], dpo[sz(o) & 1][sz(o) / 2][(11 - j) % 11]);
		int pt2 = mul(snb((sz(o) + 1) / 2, i), snb(sz(o) / 2 + 1, sz(e) - i));
		int pt3 = mul(fact[i], fact[sz(e) - i]);
		int pt4 = mul(fact[sz(o) / 2], fact[sz(o) - sz(o) / 2]);
		ans = add(ans, mul(mul(pt1, pt2), mul(pt3, pt4)));
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