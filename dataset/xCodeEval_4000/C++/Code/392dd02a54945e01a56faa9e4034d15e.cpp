

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

const int N = 20;

int n, m, q, s;

bool read () {
	if (scanf("%d%d%d", &n, &m, &q) != 3)
		return false;
	s = n * m;
	return true;
}

typedef array<array<int, N>, N> mat;

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

mat operator *(const mat &a, const mat &b){
	mat c;
	forn(i, s) forn(j, s) c[i][j] = 0;
	forn(i, s) forn(j, s) forn(k, s)
		c[i][j] = add(c[i][j], mul(a[i][k], b[k][j]));
	return c;
}

mat binpow(mat a, int b){
	mat res;
	forn(i, s) forn(j, s) res[i][j] = i == j;
	while (b){
		if (b & 1)
			res = res * a;
		a = a * a;
		b >>= 1;
	}
	return res;
}

int dx[] = {-1, 0, 1, 0, 0};
int dy[] = {0, 1, 0, -1, 0};

bool in(int x, int y){
	return 0 <= x && x < n && 0 <= y && y < m;
}

void solve() {
	int lst = 1;
	mat cur;
	forn(i, s) forn(j, s) cur[i][j] = 0;
	forn(i, n) forn(j, m) forn(k, 5){
		int ni = i + dx[k];
		int nj = j + dy[k];
		if (in(ni, nj))
			cur[i * m + j][ni * m + nj] = add(cur[i * m + j][ni * m + nj], 1);
	}
	mat ways;
	forn(i, s) forn(j, s) ways[i][j] = 0;
	ways[0][0] = 1;
	forn(i, q){
		int tp, x, y, t;
		scanf("%d%d%d%d", &tp, &x, &y, &t);
		--x, --y;
		ways = ways * binpow(cur, t - lst);
		lst = t;
		if (tp == 1)
			printf("%d\n", ways[0][x * m + y]);
		else if (tp == 2){
			forn(k, 5){
				int nx = x + dx[k];
				int ny = y + dy[k];
				if (in(nx, ny))
					cur[nx * m + ny][x * m + y] = add(cur[nx * m + ny][x * m + y], -1);
			}
			forn(i, s){
				ways[i][x * m + y] = 0;
			}
		}
		else{
			forn(k, 5){
				int nx = x + dx[k];
				int ny = y + dy[k];
				if (in(nx, ny))
					cur[nx * m + ny][x * m + y] = add(cur[nx * m + ny][x * m + y], 1);
			}
		}
		
	}
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