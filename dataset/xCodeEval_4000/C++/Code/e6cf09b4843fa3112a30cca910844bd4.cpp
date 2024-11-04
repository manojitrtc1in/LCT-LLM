

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

const int N = 41;

int n, m;
string s[N];

bool read () {
	if (scanf("%d%d", &n, &m) != 2)
		return false;
	static char buf[N];
	forn(i, n){
		scanf("%s", buf);
		s[i] = buf;
	}
	return true;
}

string a[N];
string b[N];

int dp[N][N][N][N];

int calc(int x1, int x2, int y1, int y2){
	int& d = dp[x1][x2][y1][y2];
	if (d != -1) return d;
	
	vector<int> vals;
	
	fore(x, x1, x2) fore(y, y1, y2) if (a[x][y] != '.'){
		if (a[x][y] == 'L')
			vals.pb(calc(x1, x, y1, y2) ^ calc(x + 1, x2, y1, y2));
		else if (a[x][y] == 'R')
			vals.pb(calc(x1, x2, y1, y) ^ calc(x1, x2, y + 1, y2));
		else
			vals.pb(calc(x1, x, y1, y) ^ calc(x1, x, y + 1, y2) ^ calc(x + 1, x2, y1, y) ^ calc(x + 1, x2, y + 1, y2));
	}
	
	

	
	sort(all(vals));
	vals.resize(unique(all(vals)) - vals.begin());
	
	forn(i, sz(vals)) if (vals[i] != i)
		return d = i;
	return d = sz(vals);
}

void solve(){
	if (m % 2 == 1){
		forn(i, n) s[i] += '.';
		++m;
	}
	
	if (n % 2 == 1){
		s[n++] = string(m, '.');
	}
	
	forn(i, n + m) a[i] = b[i] = string(n + m, '.');
	
	forn(i, n) forn(j, m){
		int r = (i + j) / 2;
		int c = (i - j + m - 1) / 2;
		if ((i + j) & 1)
			b[r][c] = s[i][j];
		else
			a[r][c] = s[i][j];
	}
	
	memset(dp, -1, sizeof(dp));
	int ans1 = calc(0, (n + m + 1) / 2, 0, (n + m + 1) / 2);
	
	
	
	forn(i, n + m) a[i] = b[i];
	memset(dp, -1, sizeof(dp));
	int ans2 = calc(0, (n + m + 1) / 2, 0, (n + m + 1) / 2);
	
	

	
	puts((ans1 ^ ans2) ? "WIN" : "LOSE");
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