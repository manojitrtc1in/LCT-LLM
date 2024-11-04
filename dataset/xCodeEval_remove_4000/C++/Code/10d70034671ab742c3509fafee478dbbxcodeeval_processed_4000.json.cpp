



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

const int N = 2000 + 7;

int n;
string s;

bool read () {
	static char buf[N];
	if (scanf("%s", buf) != 1)
		return false;
	s = buf;
	n = sz(s);
	return true;
}

int dp[N][N];
int pr[N];
int pw[N];

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

int calc(int l, int r){
	if (dp[l][r] != -1)
		return dp[l][r];
	dp[l][r] = 0;
	if (l == r)
		return dp[l][r];
	if (s[l] != '(')
		dp[l][r] = add(dp[l][r], calc(l + 1, r));
	if (s[r - 1] != ')')
		dp[l][r] = add(dp[l][r], calc(l, r - 1));
	if (s[l] != '(' && s[r - 1] != ')' && l < r - 1)
		dp[l][r] = add(dp[l][r], -calc(l + 1, r - 1));
	if (s[l] != ')' && s[r - 1] != '(' && l < r - 1)
		dp[l][r] = add(dp[l][r], add(pw[pr[r - 1] - pr[l + 1]], calc(l + 1, r - 1)));
	return dp[l][r];
}

void solve() {
	memset(dp, -1, sizeof(dp));
	forn(i, n) pr[i + 1] = pr[i] + (s[i] == '?');
	pw[0] = 1;
	fore(i, 1, n + 1) pw[i] = mul(pw[i - 1], 2);
	printf("%d\n", calc(0, n));
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