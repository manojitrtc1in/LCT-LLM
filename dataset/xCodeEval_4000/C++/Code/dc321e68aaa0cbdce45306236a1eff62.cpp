

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
const int MOD = 95542721;
const ld EPS = 1e-9;
const ld PI = acos(-1.0);

const int N = 100 * 1000 + 13;
const int K = 48;

struct query{
	int t, l, r;
};

int n, m;
int a[N];
query q[N];

bool read () {
	if (scanf("%d", &n) != 1)
		return false;
	forn(i, n){
		scanf("%d", &a[i]);
		a[i] %= MOD;
	}
	scanf("%d", &m);
	forn(i, m){
		scanf("%d%d%d", &q[i].t, &q[i].l, &q[i].r);
		--q[i].l;
	}
	return true;
}

inline int add(int a, int b){
	a += b;
	if (a >= MOD)
		a -= MOD;
	return a;
}

inline int mul(int a, int b){
	return a * li(b) % MOD;
}

inline int binpow(int a, int b){
	int res = 1;
	while (b){
		if (b & 1)
			res = mul(res, a);
		a = mul(a, a);
		b >>= 1;
	}
	return res;
}

inline int pw3(int a){
	return mul(mul(a, a), a);
}

struct node{
	int ps;
	int val[K];
	int& operator [](int x){
		return val[x];
	}
};

int pw[K];
node t[4 * N];

void push(int v){
	t[v].ps %= K;
	if (t[v].ps == 0)
		return;
	if (v * 2 + 1 < 4 * N){
		t[v * 2].ps += t[v].ps;
		t[v * 2 + 1].ps += t[v].ps;
	}
	rotate(t[v].val, t[v].val + t[v].ps, t[v].val + K);
	t[v].ps = 0;
}

void build(int v, int l, int r){
	t[v].ps = 0;
	if (l == r - 1){
		t[v][0] = a[l];
		fore(i, 1, K) t[v][i] = pw3(t[v][i - 1]);
		return;
	}
	int m = (l + r) / 2;
	build(v * 2, l, m);
	build(v * 2 + 1, m, r);
	forn(i, K) t[v][i] = add(t[v * 2][i], t[v * 2 + 1][i]);
}

void upd(int v, int l, int r, int L, int R){
	push(v);
	if (L >= R)
		return;
	if (l == L && r == R){
		++t[v].ps;
		push(v);
		return;
	}
	int m = (l + r) / 2;
	upd(v * 2, l, m, L, min(m, R));
	upd(v * 2 + 1, m, r, max(m, L), R);
	forn(i, K) t[v][i] = add(t[v * 2][i], t[v * 2 + 1][i]);
}

int get(int v, int l, int r, int L, int R){
	push(v);
	if (L >= R)
		return 0;
	if (l == L && r == R)
		return t[v][0];
	int m = (l + r) / 2;
	int res = add(get(v * 2, l, m, L, min(m, R)), get(v * 2 + 1, m, r, max(m, L), R));
	forn(i, K) t[v][i] = add(t[v * 2][i], t[v * 2 + 1][i]);
	return res;
}

void solve() {
	build(1, 0, n);
	forn(i, m){
		if (q[i].t == 2)
			upd(1, 0, n, q[i].l, q[i].r);
		else
			printf("%d\n", get(1, 0, n, q[i].l, q[i].r));
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

	while(read()) {	
		solve();
		
#ifdef _DEBUG
	cerr << "TIME = " << clock() - tt << endl;
	tt = clock();
#endif

	}
}