

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

const int N = 1000 + 7;
const int M = 100 * 1000 + 13;

int n, m;
int a[N][N];
pt q[M];

bool read () {
	if (scanf("%d%d", &n, &m) != 2)
		return false;
	forn(i, m){
		scanf("%d%d", &q[i].x, &q[i].y);
		--q[i].x, --q[i].y;
	}
	return true;
}

int pr[N][N];

bool check(int x){
	memset(a, 0, sizeof(a));
	forn(i, x) a[q[i].x][q[i].y] = 1;
	forn(i, n) forn(j, n) pr[i + 1][j + 1] = pr[i + 1][j] + pr[i][j + 1] - pr[i][j] + a[i][j];
	fore(i, 2, n) fore(j, 2, n) if (pr[i + 1][j + 1] - pr[i - 2][j + 1] - pr[i + 1][j - 2] + pr[i - 2][j - 2] == 9)
		return true;
	return false;
}

void solve() {
	int l = 0, r = m;
	int res = -1;
	while (l <= r){
		int m = (l + r) / 2;
		if (check(m)){
			r = m - 1;
			res = m;
		}
		else{
			l = m + 1;
		}
	}
	printf("%d\n", res);
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