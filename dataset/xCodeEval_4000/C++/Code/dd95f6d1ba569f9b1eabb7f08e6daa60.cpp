

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

int n, m, k;
int a[N], b[N];

bool read () {
	if (scanf("%d%d%d", &n, &m, &k) != 3)
		return false;
	forn(i, n)
		scanf("%d", &a[i]);
	forn(i, m)
		scanf("%d", &b[i]);
	return true;
}

int cnt[N];

void solve() {
	vector<int> xs;
	forn(i, n) xs.pb(a[i]);
	forn(i, m) xs.pb(b[i]);
	sort(all(xs));
	xs.resize(unique(all(xs)) - xs.begin());
	forn(i, n) a[i] = lower_bound(all(xs), a[i]) - xs.begin();
	forn(i, m) b[i] = lower_bound(all(xs), b[i]) - xs.begin();
	memset(cnt, 0, sizeof(cnt));
	forn(i, n) ++cnt[a[i]];
	forn(i, m) --cnt[b[i]];
	int sum = 0;
	for (int i = sz(xs) - 1; i >= 0; --i){
		sum += cnt[i];
		if (sum > 0){
			puts("YES");
			return;
		}
	}
	puts("NO");
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