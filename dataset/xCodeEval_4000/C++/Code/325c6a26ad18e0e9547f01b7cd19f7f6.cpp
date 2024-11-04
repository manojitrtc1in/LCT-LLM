

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
pt a[N];

bool read () {
	if (scanf("%d", &n) != 1)
		return false;
	forn(i, n)
		scanf("%d%d", &a[i].x, &a[i].y);
	return true;
}

void solve() {
	li ans = INF64;
	
	vector<int> xs;
	forn(i, n) xs.pb(a[i].x), xs.pb(a[i].y);
	sort(all(xs));
	xs.resize(unique(all(xs)) - xs.begin());
	
	for (auto h : xs){
		bool fl = true;
		vector<int> h1;
		vector<pt> h2;
		forn(i, n){
			if (a[i].y > h){
				if (a[i].x > h){
					fl = false;
					break;
				}
				h1.pb(a[i].y);
			}
			else{
				h2.pb(a[i]);
			}
		}
		if (sz(h1) * 2 > n || !fl) continue;
		sort(all(h2), [](const pt &a, const pt &b){
			return a.y - a.x < b.y - b.x;
		});
		li w = 0;
		for (auto it : h2){
			if (it.x <= h && it.y <= h && it.y < it.x && (sz(h1) + 1) * 2 <= n){
				h1.pb(it.y);
			}
			else{
				w += it.x;
			}
		}
		w += accumulate(all(h1), 0ll);
		ans = min(ans, w * h);
	}
	printf("%lld\n", ans);
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