

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
const int MOD = int(1e9) + 7;
const ld EPS = 1e-9;
const ld PI = acos(-1.0);

const int N = 5000 + 7;

int n;
li a[N];

bool read () {
	if (scanf("%d", &n) != 1)
		return false;
	forn(i, n)
		scanf("%lld", &a[i]);
	return true;
}

int dp[N], cx[N];

inline int distmn(li x, li y, int cntx, int cnty){
	if (x == y && x % 2 == 0)
		return INF;
	if (cnty <= cntx)
		return (x != y) + cnty;
	else if ((y >> cnty) % (x >> cntx) != 0)
		return max(1, cnty - cntx);
	else
		return cnty - cntx;
}

inline int distmx(li x, li y, int cntx, int cnty){
	if (x == y)
		return (x % 2 == 1 ? 0 : cnty + 1);
	if (cntx == 0 && y % x == 0)
		return cnty;
	return 1 + cnty;
}

li f[N];

void solve(){
	

	

	
	forn(i, n) cx[i] = __builtin_ctzll(a[i]);
	forn(i, n) dp[i] = i;
	forn(i, n) fore(j, i + 1, n){
		if ((a[i] >> cx[i]) % (a[j] >> cx[j]) != 0) continue;
		int md1 = distmn(a[i], a[j], cx[i], cx[j]);
		if (md1 == j - i) dp[j] = min(dp[j], dp[i] + j - i - 1);
		int md2 = distmx(a[i], a[j], cx[i], cx[j]);
		if (md2 <= j - i) dp[j] = min(dp[j], dp[i] + j - i - 1);
	}
	int ans = n;
	forn(i, n) ans = min(ans, dp[i] + (n - i - 1));
	printf("%d\n", ans);
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

	if(read()) {	
		solve();
		
#ifdef _DEBUG
	cerr << "TIME = " << clock() - tt << endl;
	tt = clock();
#endif

	}
}