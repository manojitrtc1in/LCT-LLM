

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

const int N = 300 * 1000 + 13;

int n, m;
vector<pt> a[N];
pt q[N];

bool read () {
	if (scanf("%d", &n) != 1)
		return false;
	forn(i, n){
		int k;
		scanf("%d", &k);
		a[i].resize(k);
		forn(j, k)
			scanf("%d%d", &a[i][j].x, &a[i][j].y);
	}
	scanf("%d", &m);
	forn(i, m){
		scanf("%d%d", &q[i].x, &q[i].y);
		--q[i].x, --q[i].y;
	}
	return true;
}

pt operator -(const pt &a, const pt &b){
	return mp(a.x - b.x, a.y - b.y);
}

pt bd[N];
pt b[N];

map<pt, int> cur;
vector<int> t[4 * N];

void build(int v, int l, int r){
	if (l == r - 1){
		int g = __gcd(abs(b[l].x), abs(b[l].y));
		b[l].x /= g;
		b[l].y /= g;
		if (!cur.count(b[l]))
			t[v] = vector<int>(1, -1);
		else
			t[v] = vector<int>(1, cur[b[l]]);
		cur[b[l]] = l;
		return;
	}
	int m = (l + r) / 2;
	build(v * 2, l, m);
	build(v * 2 + 1, m, r);
	t[v].resize(r - l);
	merge(all(t[v * 2]), all(t[v * 2 + 1]), t[v].begin());
}

int get(int v, int l, int r, int L, int R, int val){
	if (L >= R)
		return 0;
	if (l == L && r == R)
		return lower_bound(all(t[v]), val) - t[v].begin();
	int m = (l + r) / 2;
	return get(v * 2, l, m, L, min(m, R), val) + get(v * 2 + 1, m, r, max(m, L), R, val);
}

void solve(){
	int lst = 0;
	forn(i, n){
		bd[i].x = lst;
		forn(j, sz(a[i]))
			b[lst++] = a[i][(j + 1) % sz(a[i])] - a[i][j];
		bd[i].y = lst;
	}
	build(1, 0, lst);
	forn(i, m){
		int l = bd[q[i].x].x;
		int r = bd[q[i].y].y;
		printf("%d\n", get(1, 0, lst, l, r, l));
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