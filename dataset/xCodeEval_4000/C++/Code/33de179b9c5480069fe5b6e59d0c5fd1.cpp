

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
const li INF64 = li(2e18);
const int MOD = int(1e9) + 7;
const ld EPS = 1e-9;
const ld PI = acos(-1.0);

const int N = 300 * 1000 + 13;
const int M = 6;

int n, c, m;
int a[N];
pair<int, li> q[N];

bool read () {
	if (scanf("%d%d%d", &n, &c, &m) != 3)
		return false;
	forn(i, n)
		scanf("%d", &a[i]);
	forn(i, m){
		scanf("%d%lld", &q[i].x, &q[i].y);
		--q[i].x, --q[i].y;
	}
	return true;
}

li C[N][M];

li calc(int n, int c){
	if (n == 0) return 1;
	li res = 0;
	forn(i, min(n, c + 1)) res += C[n - 1][i];
	return res;
}

int ans[N];

void precalc(){
	forn(i, N){
		C[i][0] = 1;
		if (i < M) C[i][i] = 1;
		fore(j, 1, min(i, M))
			C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
	}
}

void solve() {
	vector<pair<pt, int>> qs;
	memset(ans, -1, sizeof(int) * m);
	forn(i, m) if (q[i].y < calc(n, c))
		qs.pb(mp(mp(c, 0), i));
	for (int nc = c; nc >= 0; --nc){
		sort(all(qs), greater<pair<pt, int>>());
		int j = 0;
		set<pair<li, pt>> prs;
		li add = 0;
		vector<pair<pt, int>> nqs;
		auto apply = [&](int pos){
			while (j < sz(qs) && qs[j].x.x == nc && qs[j].x.y == pos){
				int i = qs[j].y;
				auto it = *(--prs.lower_bound(mp(q[i].y - add, mp(INF, -1))));
				if (q[i].x < it.y.x)
					ans[i] = a[q[i].x];
				else if (q[i].x <= it.y.y)
					ans[i] = a[it.y.y - (q[i].x - it.y.x)];
				else{
					q[i].y -= it.x + add;
					nqs.pb(mp(mp(nc - (it.y.y - it.y.x), it.y.y + 1), i));
				}
				++j;
			}
		};
		prs.insert(mp(0, mp(n, n)));
		apply(n);
		for (int i = n - 1; i >= 0; --i){
			vector<pt> st;
			li tmp = 0;
			fore(j, i, min(n, i + nc + 1))
				st.pb(mp(a[j], j));
			sort(all(st));
			for (auto it : st){
				int j = it.y;
				li nw = calc(n - j - 1, nc - (j - i));
				if (it.x < a[i])
					add += nw;
			}
			for (auto it : st){
				int j = it.y;
				li nw = calc(n - j - 1, nc - (j - i));
				if (j != i)
					prs.insert(mp(tmp - add, mp(i, j)));
				tmp += nw;
			}
			apply(i);
		}
		while (j < sz(qs)){
			nqs.pb(qs[j++]);
		}
		qs = nqs;
	}
	assert(qs.empty());
	forn(i, m) printf("%d\n", ans[i]);
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

	precalc();
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