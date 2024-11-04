

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

const int INF = int(1e9) + 10;
const li INF64 = li(1e18);
const int MOD = int(1e9) + 7;
const ld EPS = 1e-9;
const ld PI = acos(-1.0);

const int N = 600 * 1000 + 13;
const int LOGN = 20;

int n, m, k;
int a[N];
pt q[N];

bool read () {
	if (scanf("%d%d%d", &n, &m, &k) != 3)
		return false;
	forn(i, n)
		scanf("%d", &a[i]);
	forn(i, m){
		scanf("%d%d", &q[i].x, &q[i].y);
		--q[i].x, --q[i].y;
	}
	return true;
}

int st[N][LOGN];
int pw[N];

void build(int n){
	forn(i, n) st[i][0] = a[i];
	fore(j, 1, LOGN){
		forn(i, n){
			st[i][j] = st[i][j - 1];
			if (i + (1 << (j - 1)) < n)
				st[i][j] = min(st[i][j], st[i + (1 << (j - 1))][j - 1]);
		}
	}
	pw[0] = pw[1] = 0;
	fore(i, 2, n + 1) pw[i] = pw[i / 2] + 1;
}

int get(int l, int r){
	int len = pw[r - l];
	return min(st[l][len], st[r - (1 << len)][len]);
}

vector<int> bls[N];
vector<pt> stk;
int tot;

li t[4 * N];
int ps[4 * N];

void build(int v, int l, int r){
	ps[v] = -1;
	if (l == r - 1){
		t[v] = INF;
		return;
	}
	int m = (l + r) / 2;
	build(v * 2, l, m);
	build(v * 2 + 1, m, r);
	t[v] = t[v * 2] + t[v * 2 + 1];
}

void push(int v, int l, int r){
	if (ps[v] == -1)
		return;
	if (l != r - 1){
		ps[v * 2] = ps[v];
		ps[v * 2 + 1] = ps[v];
	}
	t[v] = ps[v] * li(r - l);
	ps[v] = -1;
}

void upd(int v, int l, int r, int L, int R, int val){
	push(v, l, r);
	if (L >= R)
		return;
	if (l == L && r == R){
		ps[v] = val;
		push(v, l, r);
		return;
	}
	int m = (l + r) / 2;
	upd(v * 2, l, m, L, min(m, R), val);
	upd(v * 2 + 1, m, r, max(m, L), R, val);
	t[v] = t[v * 2] + t[v * 2 + 1];
}

li get(int v, int l, int r, int L, int R){
	push(v, l, r);
	if (L >= R)
		return 0;
	if (l == L && r == R)
		return t[v];
	int m = (l + r) / 2;
	li res = get(v * 2, l, m, L, min(m, R)) + get(v * 2 + 1, m, r, max(m, L), R);
	t[v] = t[v * 2] + t[v * 2 + 1];
	return res;
}

void add(int x, int val){
	while (stk.back().y >= val)
		stk.pop_back();
	upd(1, 0, tot, x, stk.back().x, val);
	stk.pb(mp(x, val));
}

li ans[N];

void solve() {
	forn(i, n) a[n + i] = INF;
	build(2 * n);
	forn(i, k) bls[i].clear();
	forn(i, m) bls[q[i].x % k].pb(i);
	tot = n / k + 3;
	forn(rem, k){
		sort(all(bls[rem]), [](int x, int y){
			return q[x].x < q[y].x;
		});
		vector<pt> tmp;
		for (int i = rem; i < n; i += k)
			tmp.pb(mp(i, get(i + 1, i + 1 + k)));
		stk.clear();
		stk.pb(mp(tot, -INF));
		build(1, 0, tot);
		while (!tmp.empty()){
			add(tmp.back().x / k + 1, tmp.back().y);
			add(tmp.back().x / k, a[tmp.back().x]);
			while (!bls[rem].empty()){
				int j = bls[rem].back();
				int l = q[j].x, r = q[j].y;
				if (l != tmp.back().x) break;
				int len = r - l;
				ans[j] = get(1, 0, tot, l / k, l / k + len / k + 1);
				bls[rem].pop_back();
			}
			tmp.pop_back();
		}
	}
	forn(i, m) printf("%lld\n", ans[i]);
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