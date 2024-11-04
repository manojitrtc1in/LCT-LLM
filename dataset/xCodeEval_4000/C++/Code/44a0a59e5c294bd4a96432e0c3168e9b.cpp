

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
typedef unsigned long long uli;
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

const int INF = int(2e9) + 5;
const li INF64 = li(1e18);
const int MOD = int(1e9) + 7;
const ld EPS = 1e-9;
const ld PI = acos(-1.0);

const int N = 100 * 1000 + 13;
const int M = 5;

int n, m;
int a[N][M];
int w[N];
int b[N][M];

bool read () {
	if (scanf("%d%d", &n, &m) != 2)
		return false;
	forn(i, n){
		forn(j, m)
			scanf("%d", &a[i][j]);
		scanf("%d", &w[i]);
	}
	return true;
}

uli mask[N * M];

void solve() {
        for(int j=0;j<N*M;j++){
                mask[j]=-1;
        }
	vector<int> xs;
	forn(i, n) forn(j, m) xs.pb(a[i][j]);
	sort(all(xs));
	xs.resize(unique(all(xs)) - xs.begin());
	forn(i, n) forn(j, m) a[i][j] = lower_bound(all(xs), a[i][j]) - xs.begin();

	vector<int> ord(n);
	iota(all(ord), 0);
	sort(all(ord), [](int x, int y){
		return w[x] < w[y];
	});

	forn(i, n) memcpy(b[i], a[ord[i]], sizeof(b[i]));
	forn(i, n) memcpy(a[i], b[i], sizeof(a[i]));
	sort(w, w + n);

	int ans = INF;
	for (int l = 0; l < n; l += 64){
		int r = min(n, l + 64);
		fore(i, l, r) forn(j, m) mask[a[i][j]] ^= 1ull << (i - l);
		uli gd=0;
		for(int j=l;j<=r;j++){
                        gd|=(1ull<<(j-l));
		}
		forn(i, n){
			uli res = gd;
			forn(j, m) res &= mask[a[i][j]];
			if(res){
                                int pos = __builtin_ctzll(res) + l;
                                if (pos < n) ans = min(ans, w[i] + w[pos]);
			}
		}
		fore(i, l, r) forn(j, m) mask[a[i][j]] = -1;
	}

	printf("%d\n", ans == INF ? -1 : ans);
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
