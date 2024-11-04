

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

const int N = 2000 + 7;

int n;
pt a[N];

bool read () {
	if (scanf("%d", &n) != 1)
		return false;
	forn(i, n){
		scanf("%d%d", &a[i].x, &a[i].y);
		--a[i].x, --a[i].y;
	}
	return true;
}

int dp[N][715][9];

bool comp(const vector<int> &a, const vector<int> &b){
	if (sz(a) != sz(b))
		return sz(a) < sz(b);
	return a < b;
}

void solve() {
	vector<vector<int>> vecs;
	vecs.pb({});
	forn(i, 9){
		vecs.pb({i});
		forn(j, i + 1){
			vecs.pb({j, i});
			forn(k, j + 1){
				vecs.pb({k, j, i});
				forn(t, k + 1){
					vecs.pb({t, k, j, i});
				}
			}
		}
	}
	sort(all(vecs), comp);
	
	forn(i, n + 1) forn(j, sz(vecs)) forn(k, 9)
		dp[i][j][k] = INF;
	dp[0][0][0] = 0;
	forn(i, n + 1) for (int vec = sz(vecs) - 1; vec >= 0; --vec) forn(k, 9) if (dp[i][vec][k] < INF){
		forn(t, sz(vecs[vec])){
			auto nw = vecs[vec];
			nw.erase(nw.begin() + t);
			int nvec = lower_bound(all(vecs), nw, comp) - vecs.begin();
			assert(nvec < vec);
			dp[i][nvec][vecs[vec][t]] = min(dp[i][nvec][vecs[vec][t]], dp[i][vec][k] + abs(vecs[vec][t] - k));
		}
		if (i < n && sz(vecs[vec]) < 4){
			auto nw = vecs[vec];
			nw.insert(lower_bound(all(nw), a[i].y), a[i].y);
			int nvec = lower_bound(all(vecs), nw, comp) - vecs.begin();
			assert(nvec > vec);
			dp[i + 1][nvec][a[i].x] = min(dp[i + 1][nvec][a[i].x], dp[i][vec][k] + abs(k - a[i].x));
		}
	}
	printf("%d\n", *min_element(dp[n][0], dp[n][0] + 9) + 2 * n);
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