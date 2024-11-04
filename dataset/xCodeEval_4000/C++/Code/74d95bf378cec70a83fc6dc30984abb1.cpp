

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

const int N = 1500 + 7;

int n;
int a[N][N];

bool read () {
	if (scanf("%d", &n) != 1)
		return false;
	forn(i, n) forn(j, n){
		scanf("%d", &a[i][j]);
		--a[i][j];
	}
	return true;
}

pt pos[N * N];
int r[N], c[N];

void solve() {
	forn(i, n) r[i] = c[i] = 0;
	forn(i, n) forn(j, n) pos[a[i][j]] = mp(i, j);
	li ans = 0;
	forn(x, n * n){
		int i = pos[x].x, j = pos[x].y;
		ans += r[i] * li(n - c[j] - 1) + (n - r[i] - 1) * li(c[j]);
		++r[i];
		++c[j];
	}
	assert(ans % 2 == 0);
	printf("%lld\n", ans / 2);
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