

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

const int N = 200 * 1000 + 13;

int n, m;
li a[N], b[N];

bool read () {
	if (scanf("%d%d", &n, &m) != 2)
		return false;
	forn(i, n)
		scanf("%lld", &a[i]);
	forn(i, m)
		scanf("%lld", &b[i]);
	return true;
}

void solve() {
	vector<pair<li, int>> ev;
	sort(b, b + m);
	forn(i, m) b[i] *= 2;
	forn(i, n){
		li pos = i * 200;
		li dist = INF64;
		auto it = lower_bound(b, b + m, pos);
		if (it != b + m)
			dist = min(dist, *it - pos);
		if (it != b){
			--it;
			dist = min(dist, pos - *it);
		}
		ev.pb(mp(pos - dist + 1, a[i]));
		ev.pb(mp(pos + dist, -a[i]));
	}
	sort(all(ev));
	li ans = 0, cur = 0;
	forn(i, sz(ev)){
		int j = i - 1;
		while (j + 1 < sz(ev) && ev[j + 1].x == ev[i].x){
			++j;
			cur += ev[j].y;
		}
		ans = max(ans, cur);
		i = j;
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