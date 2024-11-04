

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

const int N = 128;

int n, x;
ld p[N];

bool read () {
	if (scanf("%d%d", &n, &x) != 2)
		return false;
	++x;
	forn(i, x)
		scanf("%Lf", &p[i]);
	return true;
}

typedef array<array<ld, N>, N> mat;

mat operator *(const mat &a, const mat &b){
	mat c;
	forn(i, N) forn(j, N) c[i][j] = 0;
	forn(i, N) forn(j, N) forn(k, N) c[i][j] += a[i][k] * b[k][j];
	return c;
}

mat binpow(mat a, int b){
	mat res;
	forn(i, N) forn(j, N) res[i][j] = i == j;
	while (b){
		if (b & 1)
			res = res * a;
		a = a * a;
		b >>= 1;
	}
	return res;
}

void solve() {
	mat tran;
	forn(i, N) forn(j, N)
		tran[i][j] = 0;
	forn(i, N) forn(j, N) if (j < x)
		tran[i][i ^ j] += p[j];
	tran = binpow(tran, n);
	printf("%.15Lf\n", 1 - tran[0][0]);
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