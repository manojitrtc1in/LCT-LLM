

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

const int N = 200 * 1000 + 13;
const int M = 37;

int n, m;
li a[N];

bool read () {
	if (scanf("%d%d", &n, &m) != 2)
		return false;
	forn(i, n)
		scanf("%lld", &a[i]);
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

li bas[M];

bool add(li x){
	for (int i = m - 1; i >= 0; --i) if ((x >> i) & 1){
		if (bas[i] == -1){
			bas[i] = x;
			return true;
		}
		else{
			x ^= bas[i];
		}
	}
	return false;
}

int dp[2][M][1 << 16];

void solve(){
	memset(bas, -1, sizeof(bas));
	int cnt = 1;
	forn(i, n) if (!add(a[i]))
		cnt = add(cnt, cnt);
	
	vector<li> bb;
	vector<int> op, fr;
	for (int i = m - 1; i >= 0; --i) if (bas[i] != -1){
		bb.pb(bas[i]);
		op.pb(i);
	}
	
	n = sz(bb);
	forn(i, m) if (!count(all(op), i)){
		bool ok = false;
		forn(j, n) ok |= (bb[j] >> i) & 1;
		if (ok) fr.pb(i);
	}
	
	forn(i, n) forn(j, i) if ((bb[j] >> op[i]) & 1)
		bb[j] ^= bb[i];
	
	vector<int> ans(m + 1);
	if (n <= 19){
		forn(mask, 1 << n){
			li xr = 0;
			forn(i, n) if ((mask >> i) & 1)
				xr ^= bb[i];
			int x = __builtin_popcountll(xr);
			++ans[x];
		}
		forn(i, m + 1)
			printf("%d ", mul(ans[i], cnt));
		puts("");
		return;
	}
	assert(sz(fr) <= 16);
	
	int t = sz(fr);
	memset(dp, 0, sizeof(dp));
	dp[0][0][0] = 1;
	forn(ii, n){
		int i = ii & 1;
		int ni = i ^ 1;
		memset(dp[ni], 0, sizeof(dp[ni]));
		forn(j, m + 1) forn(mask, 1 << t) if (dp[i][j][mask]){
			dp[ni][j][mask] = add(dp[ni][j][mask], dp[i][j][mask]);
			int nmask = mask;
			forn(k, sz(fr)) if ((bb[ii] >> fr[k]) & 1)
				nmask ^= (1 << k);
			dp[ni][j + 1][nmask] = add(dp[ni][j + 1][nmask], dp[i][j][mask]);
		}
	}
	
	forn(j, m + 1) forn(mask, 1 << t) if (dp[n & 1][j][mask]){
		int x = j + __builtin_popcount(mask);
		ans[x] = add(ans[x], dp[n & 1][j][mask]);
	}
	
	forn(i, m + 1)
		printf("%d ", mul(ans[i], cnt));
	puts("");
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