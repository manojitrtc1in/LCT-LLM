

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

const int N = 1000 + 7;

int n;
string a[N];

bool read () {
	if (scanf("%d", &n) != 1)
		return false;
	static char buf[N];
	forn(i, n){
		scanf("%s", buf);
		a[i] = buf;
	}
	return true;
}

int cntr[N][N][4], cntc[N][N][4], cntd1[N][N][4], cntd2[N][N][4];
int nu[N][N], nr[N][N], nd[N][N], nl[N][N];
int nur[N][N], ndr[N][N], ndl[N][N], nul[N][N];

void upd(pt &a, const pt &b){
	if (a.x >= b.x && a.y >= b.y)
		return;
	if (a.x <= b.x && a.y <= b.y){
		a = b;
		return;
	}
	int p2 = abs(a.x - b.x);
	int p3 = abs(a.y - b.y);
	if (a.x < b.x && logl(2) * p2 > logl(3) * p3)
		a = b;
	else if (a.y < b.y && logl(2) * p2 < logl(3) * p3)
		a = b;
}

void solve() {
	forn(i, n) forn(j, n){
		int c = a[i][j] - '0';
		forn(k, 4) cntr[i][j + 1][k] = cntr[i][j][k];
		++cntr[i][j + 1][c];
		forn(k, 4) cntc[i + 1][j][k] = cntc[i][j][k];
		++cntc[i + 1][j][c];
		forn(k, 4) cntd1[i + 1][j + 1][k] = cntd1[i][j][k];
		++cntd1[i + 1][j + 1][c];
	}
	forn(i, n) for (int j = n - 1; j >= 0; --j){
		int c = a[i][j] - '0';
		forn(k, 4) cntd2[i + 1][j + 1][k] = cntd2[i][j + 2][k];
		++cntd2[i + 1][j + 1][c];
	}
	forn(i, n) forn(j, n){
		nl[i][j] = (j == 0 ? 1 : nl[i][j - 1] + 1);
		nu[i][j] = (i == 0 ? 1 : nu[i - 1][j] + 1);
		nul[i][j] = (i == 0 || j == 0 ? 1 : nul[i - 1][j - 1] + 1);
		if (a[i][j] == '0') nl[i][j] = nu[i][j] = nul[i][j] = 0;
	}
	for (int i = n - 1; i >= 0; --i) for (int j = n - 1; j >= 0; --j){
		nr[i][j] = (j == n - 1 ? 1 : nr[i][j + 1] + 1);
		nd[i][j] = (i == n - 1 ? 1 : nd[i + 1][j] + 1);
		ndr[i][j] = (i == n - 1 || j == n - 1 ? 1 : ndr[i + 1][j + 1] + 1);
		if (a[i][j] == '0') nr[i][j] = nd[i][j] = ndr[i][j] = 0;
	}
	forn(i, n) for (int j = n - 1; j >= 0; --j){
		nur[i][j] = (i == 0 || j == n - 1 ? 1 : nur[i - 1][j + 1] + 1);
		if (a[i][j] == '0') nur[i][j] = 0;
	}
	for (int i = n - 1; i >= 0; --i) forn(j, n){
		ndl[i][j] = (i == n - 1 || j == 0 ? 1 : ndl[i + 1][j - 1] + 1);
		if (a[i][j] == '0') ndl[i][j] = 0;
	}
	
	bool ok = false;
	forn(i, n) ok |= count(all(a[i]), '0') != n;
	if (!ok){
		puts("0");
		return;
	}
	
	pt ans = mp(0, 0);
	forn(i, n) forn(j, n){
		int len, p2, p3;
		
		len = min({nu[i][j], nr[i][j], nd[i][j], nl[i][j]});
		p2 = 0;
		p2 += cntc[i + len][j][2] - cntc[i - len + 1][j][2];
		p2 += cntr[i][j + len][2] - cntr[i][j - len + 1][2];
		p2 -= a[i][j] == '2';
		p3 = 0;
		p3 += cntc[i + len][j][3] - cntc[i - len + 1][j][3];
		p3 += cntr[i][j + len][3] - cntr[i][j - len + 1][3];
		p3 -= a[i][j] == '3';
		upd(ans, mp(p2, p3));
		
		

		
		len = min({nur[i][j], nul[i][j], ndr[i][j], ndl[i][j]});
		p2 = 0;
		p2 += cntd1[i + len][j + len][2] - cntd1[i - len + 1][j - len + 1][2];
		p2 += cntd2[i + len][j - len + 2][2] - cntd2[i - len + 1][j + len + 1][2];
		p2 -= a[i][j] == '2';
		p3 = 0;
		p3 += cntd1[i + len][j + len][3] - cntd1[i - len + 1][j - len + 1][3];
		p3 += cntd2[i + len][j - len + 2][3] - cntd2[i - len + 1][j + len + 1][3];
		p3 -= a[i][j] == '3';
		upd(ans, mp(p2, p3));
	}
	
	int res = 1;
	forn(i, ans.x) res = res * 2ll % MOD;
	forn(i, ans.y) res = res * 3ll % MOD;
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

	while(read()) {	
		solve();
		
#ifdef _DEBUG
	cerr << "TIME = " << clock() - tt << endl;
	tt = clock();
#endif

	}
}