

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

mt19937 rnd(42);

const li INF = int(1e9);
const li INF64 = li(1e18);
const int MOD = int(1e9) + 7;
const ld EPS = 1e-9;
const ld PI = acos(-1.0);

const int N = 20;
const int AL = 26;

int n, m;
string s[N];
int a[N][N];

bool read () {
	if (scanf("%d%d", &n, &m) != 2)
		return false;
	static char buf[N + 5];
	forn(i, n){
		scanf("%s", buf);
		s[i] = buf;
	}
	forn(i, n) forn(j, m)
		scanf("%d", &a[i][j]);
	return true;
}

int dp[1 << N];
int pr[1 << N];
int cor[N];

void solve() {
	forn(mask, 1 << n)
		dp[mask] = INF;
	dp[0] = 0;
	forn(i, m){
		vector<int> ord(n);
		iota(all(ord), 0);
		sort(all(ord), [&](int x, int y){
			return s[x][i] < s[y][i];
		});
		
		forn(mask, 1 << n)
			pr[mask] = INF;
		forn(j, n){
			int k = j - 1;
			int sum = 0;
			int mx = 0;
			int mask = 0;
			while (k + 1 < n && s[ord[k + 1]][i] == s[ord[j]][i]){
				++k;
				mask |= 1 << ord[k];
				sum += a[ord[k]][i];
				mx = max(mx, a[ord[k]][i]);
			}
			pr[mask] = sum - mx;
			fore(t, j, k + 1)
				cor[ord[t]] = mask;
			j = k;
		}
		
		forn(mask, 1 << n) if (dp[mask] < INF){
			forn(j, n) dp[mask | (1 << j)] = min(dp[mask | (1 << j)], dp[mask] + a[j][i]);
			forn(j, n) dp[mask | cor[j]] = min(dp[mask | cor[j]], dp[mask] + pr[cor[j]]);
		}
	}
	printf("%d\n", dp[(1 << n) - 1]);
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