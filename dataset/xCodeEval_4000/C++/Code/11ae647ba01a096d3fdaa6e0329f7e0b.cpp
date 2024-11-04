

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

const int N = 600 * 1000 + 13;

int n, m;
int a[N];
pt q[N];

bool read () {
	if (scanf("%d", &n) != 1)
		return false;
	forn(i, n)
		scanf("%d", &a[i]);
	scanf("%d", &m);
	forn(i, m){
		scanf("%d%d", &q[i].x, &q[i].y);
		--q[i].x;
	}
	return true;
}

int add(int a, int b){
	a += b;
	if (a >= MOD)
		a -= MOD;
	if (a < 0)
		a += MOD;
	return a;
}

int mul(int a, int b){
	return a * li(b) % MOD;
}

struct node{
	int val, cnt;
	int ps;
};

node merge(const node &a, const node &b){
	node c;
	c.ps = 1;
	c.val = add(a.val, b.val);
	c.cnt = a.cnt + b.cnt;
	return c;
}

struct segtree{
	node t[4 * N];
	
	int add(int a, int b){
		a += b;
		if (a >= MOD)
			a -= MOD;
		if (a < 0)
			a += MOD;
		return a;
	}
	
	int mul(int a, int b){
		return a * li(b) % MOD;
	}
	
	void push(int v){
		if (t[v].ps == 1)
			return;
		if (v * 2 + 1 < 4 * N){
			t[v * 2].ps = mul(t[v * 2].ps, t[v].ps);
			t[v * 2 + 1].ps = mul(t[v * 2 + 1].ps, t[v].ps);
		}
		t[v].val = mul(t[v].val, t[v].ps);
		t[v].ps = 1;
	}
	
	void upd(int v, int l, int r, int pos, int val){
		push(v);
		if (l == r - 1){
			t[v].cnt = val > 0;
			t[v].val = val;
			return;
		}
		int m = (l + r) / 2;
		if (pos < m){
			upd(v * 2, l, m, pos, val);
			push(v * 2 + 1);
		}
		else{
			upd(v * 2 + 1, m, r, pos, val);
			push(v * 2);
		}
		t[v] = merge(t[v * 2], t[v * 2 + 1]);
	}
	
	void mul(int v, int l, int r, int L, int R, int val){
		push(v);
		if (L >= R)
			return;
		if (l == L && r == R){
			t[v].ps = val;
			push(v);
			return;
		}
		int m = (l + r) / 2;
		mul(v * 2, l, m, L, min(m, R), val);
		mul(v * 2 + 1, m, r, max(m, L), R, val);
		t[v] = merge(t[v * 2], t[v * 2 + 1]);
	}
	
	int getval(int v, int l, int r, int L, int R){
		push(v);
		if (L >= R)
			return 0;
		if (l == L && r == R)
			return t[v].val;
		int m = (l + r) / 2;
		int res = add(getval(v * 2, l, m, L, min(m, R)), getval(v * 2 + 1, m, r, max(m, L), R));
		t[v] = merge(t[v * 2], t[v * 2 + 1]);
		return res;
	}
	
	int getcnt(int v, int l, int r, int L, int R){
		push(v);
		if (L >= R)
			return 0;
		if (l == L && r == R)
			return t[v].cnt;
		int m = (l + r) / 2;
		int res = getcnt(v * 2, l, m, L, min(m, R)) + getcnt(v * 2 + 1, m, r, max(m, L), R);
		t[v] = merge(t[v * 2], t[v * 2 + 1]);
		return res;
	}
};

segtree pr, su;

const int inv2 = (MOD + 1) / 2;
int pw[N];

vector<pt> xs;
int ans;

void add(int x){
	int lval = pr.getval(1, 0, sz(xs), 0, x);
	int rval = su.getval(1, 0, sz(xs), x + 1, sz(xs));
	int lcnt = pr.getcnt(1, 0, sz(xs), 0, x);
	int rcnt = add(pr.getcnt(1, 0, sz(xs), 0, sz(xs)), -lcnt);
	
	

	

	

	
	ans = mul(ans, 2);
	ans = add(ans, -mul(lval, rval));
	ans = add(ans, mul(xs[x].x, mul(pw[rcnt], lval)));
	ans = add(ans, mul(xs[x].x, mul(pw[lcnt], rval)));
	
	

	
	pr.mul(1, 0, sz(xs), x + 1, sz(xs), 2);
	su.mul(1, 0, sz(xs), 0, x, 2);
	pr.upd(1, 0, sz(xs), x, mul(xs[x].x, pw[lcnt]));
	su.upd(1, 0, sz(xs), x, mul(xs[x].x, pw[rcnt]));
}

void rem(int x){
	pr.mul(1, 0, sz(xs), x + 1, sz(xs), inv2);
	su.mul(1, 0, sz(xs), 0, x, inv2);
	pr.upd(1, 0, sz(xs), x, 0);
	su.upd(1, 0, sz(xs), x, 0);
	
	int lval = pr.getval(1, 0, sz(xs), 0, x);
	int rval = su.getval(1, 0, sz(xs), x + 1, sz(xs));
	int lcnt = pr.getcnt(1, 0, sz(xs), 0, x);
	int rcnt = add(pr.getcnt(1, 0, sz(xs), 0, sz(xs)), -lcnt);
	
	ans = add(ans, -mul(xs[x].x, mul(pw[lcnt], rval)));
	ans = add(ans, -mul(xs[x].x, mul(pw[rcnt], lval)));
	ans = add(ans, mul(lval, rval));
	ans = mul(ans, inv2);
}

pt b[N];

void solve() {
	pw[0] = 1;
	fore(i, 1, N) pw[i] = add(pw[i - 1], pw[i - 1]);
	ans = 0;
	forn(i, n) b[i] = mp(a[i], i);
	xs.clear();
	forn(i, n) xs.pb(b[i]);
	forn(i, m) xs.pb(mp(q[i].y, n + i));
	sort(all(xs));
	
	forn(i, 4 * sz(xs)) pr.t[i] = su.t[i] = {0, 0, 1};
	
	int dv = 1;
	forn(_, n) dv = mul(dv, inv2);
	
	forn(i, n) add(lower_bound(all(xs), b[i]) - xs.begin());
	printf("%d\n", mul(ans, dv));
	
	forn(j, m){
		int i = q[j].x;
		rem(lower_bound(all(xs), b[i]) - xs.begin());
		b[i] = mp(q[j].y, n + j);
		add(lower_bound(all(xs), b[i]) - xs.begin());
		printf("%d\n", mul(ans, dv));
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