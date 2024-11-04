

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
const int MOD = INF + 7;
const ld EPS = 1e-9;
const ld PI = acos(-1.0);

const int N = 1000 * 1000 + 13;

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

li dp[N][6];

void solve() {
	memset(dp, 0, sizeof(dp));
	
	li ans = 0;
	forn(i, n + 1) dp[i][0] = 1;
	forn(i, n){
		if (isalpha(s[i]))
			dp[i + 1][1] += dp[i][0];
		if (isalpha(s[i]) || isdigit(s[i]) || s[i] == '_')
			dp[i + 1][1] += dp[i][1];
		if (s[i] == '@')
			dp[i + 1][2] += dp[i][1];
		if (isalpha(s[i]) || isdigit(s[i]))
			dp[i + 1][3] += dp[i][2] + dp[i][3];
		if (s[i] == '.')
			dp[i + 1][4] += dp[i][3];
		if (isalpha(s[i]))
			dp[i + 1][5] += dp[i][4] + dp[i][5];
		ans += dp[i][5];
		

	}
	
	printf("%lld\n", ans + dp[n][5]);
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