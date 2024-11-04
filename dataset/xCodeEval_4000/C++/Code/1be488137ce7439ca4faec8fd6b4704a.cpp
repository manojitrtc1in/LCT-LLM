

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

const int N = 100 * 1000 + 13;
const int LOGN = 30;

int n;
pt a[N];
int m;
int q[N];

bool read () {
	if (scanf("%d", &n) != 1)
		return false;
	forn(i, n)
		scanf("%d%d", &a[i].x, &a[i].y);
	scanf("%d", &m);
	forn(i, m)
		scanf("%d", &q[i]);
	return true;
}

int ans[LOGN];

void solve() {
	forn(z, LOGN){
		int len = 1 << z;
		vector<pt> ev;
		forn(i, n){
			if (a[i].y - a[i].x + 1 >= len)
				ev.pb(mp(0, 1));
			else{
				int l = a[i].x % len;
				int r = a[i].y % len;
				if (l <= r){
					ev.pb(mp(l, 1));
					ev.pb(mp(r + 1, -1));
				}
				else{
					ev.pb(mp(l, 1));
					ev.pb(mp(0, 1));
					ev.pb(mp(r + 1, -1));
				}
			}
		}
		sort(all(ev));
		int bal = 0;
		int res = 0;
		forn(i, sz(ev)){
			int j = i - 1;
			while (j + 1 < sz(ev) && ev[j + 1].x == ev[i].x){
				++j;
				bal += ev[j].y;
			}
			res = max(res, bal);
			i = j;
		}
		ans[z] = res;
	}
	forn(i, m){
		printf("%d\n", ans[__builtin_ctz(q[i])]);
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