

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

const int N = 1000 * 1000 + 13;

int n, m;
string s;
int a[N];

bool read () {
	if (scanf("%d%d", &n, &m) != 2)
		return false;
	static char buf[N];
	scanf("%s", buf);
	s = buf;
	forn(i, m){
		scanf("%d", &a[i]);
		--a[i];
	}
	return true;
}

vector<int> zf(string &s) {
	int n = (int) s.length();
	vector<int> z (n);
	for (int i=1, l=0, r=0; i<n; ++i) {
		if (i <= r)
			z[i] = min (r-i+1, z[i-l]);
		while (i+z[i] < n && s[z[i]] == s[i+z[i]])
			++z[i];
		if (i+z[i]-1 > r)
			l = i,  r = i+z[i]-1;
	}
	return z;
}

int pos[N];

void solve() {
	memset(pos, -1, sizeof(pos));
	auto z = zf(s);
	
	int k = sz(s);
	forn(i, m){
		int lst = 0;
		if (i > 0 && a[i] - a[i - 1] < k){
			if (z[a[i] - a[i - 1]] < k - (a[i] - a[i - 1])){
				puts("0");
				return;
			}
			lst = k - (a[i] - a[i - 1]);
		}
		fore(j, lst, k){
			pos[a[i] + j] = 0;
		}
	}
	int ans = 1;
	forn(i, n) if (pos[i] == -1)
		ans = (ans * li(26)) % MOD;
	printf("%d\n", ans);
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