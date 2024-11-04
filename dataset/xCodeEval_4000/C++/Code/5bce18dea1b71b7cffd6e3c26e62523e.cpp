

#include <bits/stdc++.h>

using namespace std;

#define x first
#define y second
#define mp make_pair
#define pb push_back
#define sqr(a) ((a) * (a))
#define sz(a) int(a.size())
#define all(a) a.begin(), a.end()
#define forn(i, n) for(int i = 0; i < int(n); i++) 
#define fore(i, l, r) for(int i = int(l); i < int(r); i++)

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

const int N = 50 + 7;
const int M = 3000 + 7;

int n, m;
int a[N], w[N];

bool read () {
	if (scanf("%d%d", &n, &m) != 2)
		return false;
	forn(i, n)
		scanf("%d", &a[i]);
	forn(i, n)
		scanf("%d", &w[i]);
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

int inv(int x){
	return binpow(x, MOD - 2);
}

int dp[N][N][2 * N];
int rev[M];

void solve(){
	int sum = accumulate(w, w + n, 0);
	int neg = 0;
	forn(i, n) if (a[i] == 0) neg += w[i];
	forn(i, M) rev[i] = inv(i);
	
	forn(z, n){
		memset(dp, 0, sizeof(dp));
		dp[0][0][w[z]] = 1;
		forn(i, m) forn(pos, i + 1) forn(val, 2 * N) if (dp[i][pos][val]){
			int p = mul(val, rev[sum + pos - (i - pos)]);
			int pneg = mul(neg - (a[z] == 0 ? val : 0) - (i - pos), rev[sum + pos - (i - pos)]);
			int ppos = add(1, -add(p, pneg));
			if (a[z] == 0 && val > 0)
				dp[i + 1][pos][val - 1] = add(dp[i + 1][pos][val - 1], mul(dp[i][pos][val], p));
			if (a[z] == 1)
				dp[i + 1][pos + 1][val + 1] = add(dp[i + 1][pos + 1][val + 1], mul(dp[i][pos][val], p));
			dp[i + 1][pos + 1][val] = add(dp[i + 1][pos + 1][val], mul(dp[i][pos][val], ppos));
			dp[i + 1][pos][val] = add(dp[i + 1][pos][val], mul(dp[i][pos][val], pneg));
		}
		int ans = 0;
		forn(pos, m + 1) forn(val, 2 * N) if (dp[m][pos][val])
			ans = add(ans, mul(dp[m][pos][val], val));
		printf("%d\n", ans);
	}
}

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);


	
	int tt = clock();
	
#endif
	
	cerr.precision(15);
	cout.precision(15);
	cerr << fixed;
	cout << fixed;

	while(read()) {	
		solve();
		
#ifdef _DEBUG
	cerr << "TIME = " << clock() - tt << endl;
	tt = clock();
#endif

	}
}