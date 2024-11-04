

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

const int N = 100 + 7;

int n, x;
int a[100001];

bool read () {
	if (scanf("%d%d", &n, &x) != 2)
		return false;
	forn(i, n)
		scanf("%d", &a[i]);
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

typedef array<array<int, N>, N> mat;

mat operator *(const mat &a, const mat &b){
	mat c;
	forn(i, N) forn(j, N) c[i][j] = 0;
	forn(i, N) forn(j, N) forn(k, N) c[i][j] = add(c[i][j], mul(a[i][k], b[k][j]));
	return c;
}

mat binpow(mat a, int b){
	mat res;
	forn(i, N) forn(j, N)
		res[i][j] = i == j;
	while (b){
		if (b & 1)
			res = res * a;
		a = a * a;
		b >>= 1;
	}
	return res;
}

int cnt[N];

void solve() {
	memset(cnt, 0, sizeof(cnt));
	forn(i, n) ++cnt[a[i]];
	
	mat init;
	forn(i, N) forn(j, N)
		init[i][j] = 0;
	fore(i, 1, N - 1)
		init[0][i - 1] = add(init[0][i - 1], cnt[i]);
	fore(i, 1, N - 1)
		init[i][i - 1] = add(init[i][i - 1], 1);
	init[0][N - 1] = 1;
	init[N - 1][N - 1] = 1;
	
	init = binpow(init, x + 1);
	printf("%d\n", init[0][N - 1]);
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