

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

const int N = 90;

li x;

bool read () {
	if (scanf("%lld", &x) != 1)
		return false;
	return true;
}

li fib[N];

void init(){
	fib[0] = 1;
	fib[1] = 2;
	fore(i, 2, N) fib[i] = fib[i - 1] + fib[i - 2];
}

int d[N];
li dp[N][2];
int nxt[N];

void solve() {
	memset(d, 0, sizeof(d));
	memset(dp, 0, sizeof(dp));
	for (int i = N - 1; i >= 0; --i) if (x >= fib[i]){
		d[i] = 1;
		x -= fib[i];
	}
	nxt[0] = -1;
	nxt[1] = -1;
	fore(i, 2, N){
		if (d[i - 2] == 0)
			nxt[i] = i - 2;
		else
			nxt[i] = nxt[i - 2];
	}
	dp[N - 1][0] = 1;
	for (int i = N - 1; i > 0; --i){
		dp[i - 1][d[i - 1]] += dp[i][0] + dp[i][1];
		if (d[i - 1] == 0 && nxt[i] != -1) dp[nxt[i]][1] += dp[i][1];
	}
	printf("%lld\n", dp[0][0] + dp[0][1]);
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

	init();
	int tc;
	scanf("%d", &tc);
	while(tc--){
		read();
		solve();
		
#ifdef _DEBUG
	cerr << "TIME = " << clock() - tt << endl;
	tt = clock();
#endif

	}
}