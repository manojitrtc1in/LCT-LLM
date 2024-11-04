

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

const int N = 100 * 1000 + 13;

int n, m;
string s;
pair<int, string> a[N];

bool read () {
	static char buf[N];
	if (scanf("%s", buf) != 1)
		return false;
	s = buf;
	n = sz(s);
	scanf("%d", &m);
	fore(i, 1, m + 1){
		scanf("%s", buf);
		a[i].x = buf[0] - '0';
		a[i].y = buf;
		a[i].y = a[i].y.substr(3);
	}
	return true;
}

int add(int a, int b){
	a += b;
	if (a < 0) a += MOD;
	if (a >= MOD) a -= MOD;
	return a;
}

int mul(int a, int b){
	a = a * li(b) % MOD;
	if (a < 0) a += MOD;
	return a;
}

int binpow(int a, int b){
	int res = 1;
	while (b){
		if (b & 1)
			res = mul(res, a);
		a = mul(a, a);
		b >>= 1;
	}
	return res;
}

pt to[10];

void solve() {
	a[0] = mp(0, s);
	forn(i, 10) to[i] = mp(i, 1);
	for (int i = m; i >= 0; --i){
		int res = 0;
		int pw = 0;
		for (int j = sz(a[i].y) - 1; j >= 0; --j){
			int c = a[i].y[j] - '0';
			res = add(res, mul(to[c].x, binpow(10, pw)));
			pw = (pw + to[c].y) % (MOD - 1);
		}
		to[a[i].x] = mp(res, pw);
	}
	printf("%d\n", to[0].x);
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