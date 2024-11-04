

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

const int N = 5000 + 7;

int n;
int a[N];

bool read () {
	if (scanf("%d", &n) != 1)
		return false;
	forn(i, n)
		scanf("%d", &a[i]);
	return true;
}

int dp[N][N];
int dp2[N];

void solve() {
	forn(i, n) forn(j, n) dp[i][j] = -INF;
	dp2[0] = 0;
	forn(m, n){
		int suml = 0, sumr = 0;
		int l = m;
		int dpmx = (m == 0 ? 0 : -INF);
		fore(r, m, n){
			sumr += a[r];
			while (l - 1 >= 0 && suml + a[l - 1] <= sumr){
				--l;
				suml += a[l];
				dpmx = max(dpmx, dp[l][m - 1]);
			}
			dp[m][r] = dpmx + 1;
		}
		dp2[m + 1] = -INF;
		forn(l, m + 1){
			dp2[m + 1] = max(dp2[m + 1], dp[l][m]);
		}
	}
	printf("%d\n", n - dp2[n]);
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