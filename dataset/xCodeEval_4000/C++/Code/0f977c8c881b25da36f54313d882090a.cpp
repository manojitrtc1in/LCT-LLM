

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

const int N = 4 * 1000 * 1000 + 13;

int n, mod;

bool read () {
	if (scanf("%d%d", &n, &mod) != 2)
		return false;
	return true;
}

int dp[N];
int pr[N];

int add(int a, int b){
	a += b;
	if (a >= mod)
		a -= mod;
	if (a < 0)
		a += mod;
	return a;
}

int mul(int a, int b){
	return a * li(b) % mod;
}

void solve() {
	memset(dp, 0, sizeof(dp));
	memset(pr, 0, sizeof(pr));
	pr[1] = 1;
	pr[2] = mod - 1;
	fore(i, 1, n + 1){
		dp[i] = pr[i];
		pr[i + 1] = add(pr[i + 1], dp[i]);
		for (int j = 2; j * i <= n; ++j){
			pr[j * i] = add(pr[j * i], dp[i]);
			if (j * (i + 1) < N)
				pr[j * (i + 1)] = add(pr[j * (i + 1)], -dp[i]);
		}
		pr[i + 1] = add(pr[i + 1], pr[i]);
	}
	printf("%d\n", dp[n]);
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