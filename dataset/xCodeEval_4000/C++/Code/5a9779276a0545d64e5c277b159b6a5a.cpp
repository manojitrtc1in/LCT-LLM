

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

const int N = 300 * 1000 + 13;
const int M = 5000 + 7;

int n, k;
int a[N];

bool read (){
	if (scanf("%d%d", &n, &k) != 2)
		return false;
	forn(i, n)
		scanf("%d", &a[i]);
	return true;
}

li dp[M][M];

void solve() {
	int p1 = n / k;
	int cnt1 = k - n % k;
	int p2 = (n + k - 1) / k;
	int cnt2 = n % k;
	sort(a, a + n);
	forn(i, M) forn(j, M)
		dp[i][j] = INF64;
	dp[0][0] = 0;
	forn(i, cnt1 + 1) forn(j, cnt2 + 1) if (dp[i][j] < INF64){
		int l = i * p1 + j * p2;
		if (i < cnt1)
			dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + a[l + p1 - 1] - a[l]);
		if (j < cnt2)
			dp[i][j + 1] = min(dp[i][j + 1], dp[i][j] + a[l + p2 - 1] - a[l]);
	}
	printf("%lld\n", dp[cnt1][cnt2]);
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

#ifdef MULTITEST
	int tc;
	scanf("%d", &tc);
	while(tc--){
		read();
#else
	while(read()) {	
#endif
		solve();
		
#ifdef _DEBUG
	cerr << "TIME = " << clock() - tt << endl;
	tt = clock();
#endif

	}
}