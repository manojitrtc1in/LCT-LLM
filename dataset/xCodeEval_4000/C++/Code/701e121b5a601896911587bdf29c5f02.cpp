

#include <bits/stdc++.h>

using namespace std;

#define MULTITEST

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

const int N = 200 * 1000 + 13;

int n;
string s, t;

bool read () {
	if (scanf("%d", &n) != 1)
		return false;
	static char buf[N];
	scanf("%s", buf);
	s = buf;
	scanf("%s", buf);
	t = buf;
	return true;
}

void solve() {
	vector<pt> pts;
	forn(i, n) pts.pb(mp(s[i], t[n - i - 1]));
	forn(i, n) if (pts[i].x > pts[i].y) swap(pts[i].x, pts[i].y);
	sort(all(pts));
	bool mid = false;
	forn(i, n){
		int j = i;
		while (j + 1 < n && pts[j + 1] == pts[i])
			++j;
		int len = j - i + 1;
		if (len % 2 != 0){
			if (mid){
				puts("NO");
				return;
			}
			if (pts[i].x != pts[i].y){
				puts("NO");
				return;
			}
			mid = true;
		}
		i = j;
	}
	puts("YES");
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