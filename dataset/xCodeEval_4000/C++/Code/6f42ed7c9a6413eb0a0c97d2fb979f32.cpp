

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

const int N = 3000 + 7;

int n;
int a[N];

bool read () {
	if (scanf("%d", &n) != 1)
		return false;
	forn(i, n){
		scanf("%d", &a[i]);
		--a[i];
	}
	return true;
}

ld dp[N * N];

void solve() {
	int cur = 0;
	forn(i, n) forn(j, i) cur += a[j] > a[i];
	forn(i, n * n) dp[i] = INF64;
	dp[cur] = 0;
	for (int i = cur; i > 0; --i){
		if (i == 1){
			dp[i - 1] = min(dp[i - 1], dp[i] + 1);
		}
		else{
			dp[i - 2] = min(dp[i - 2], dp[i] + 2 * 2);
		}
	}
	printf("%.15Lf\n", dp[0]);
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