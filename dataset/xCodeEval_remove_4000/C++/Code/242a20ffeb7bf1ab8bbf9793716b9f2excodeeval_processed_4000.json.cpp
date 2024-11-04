



 
using namespace std;
 









 
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
 
const int N = 100 * 1000 + 13;
 
int n, m;
int a[N];
pair<pt, pt> q[N];
 
bool read () {
	if (scanf("%d%d", &n, &m) != 2)
		return false;
	forn(i, n)
		scanf("%d", &a[i]);
	static char buf[5];
	forn(i, m){
		scanf("%s%d%d%d", buf, &q[i].y.x, &q[i].y.y, &q[i].x.y);
		q[i].x.x = (buf[0] == '=' ? 1 : 2);
		--q[i].y.x;
	}
	return true;
}
 
int add(int a, int b){
	a += b;
	if (a >= MOD)
		a -= MOD;
	return a;
}
 
int mul(int a, int b){
	if (a == 0 || b == 0) return 0;
	if (a == 1) return b;
	if (b == 1) return a;
	li r = a * li(b);
	if (r >= MOD) r %= MOD;
	return r;
}
 
struct poly{
	int a[6], siz;
	int& operator [](int x){
		return a[x];
	}
};
 
poly polys[] = {{1, 0, 0, 0, 0, 0, 1}, 
				{1, MOD - 1, 0, 0, 0, 0, 2}, 
				{1, MOD - 2, 1, 0, 0, 0, 3}, 
				{1, MOD - 3, 3, MOD - 1, 0, 0, 4}, 
				{1, MOD - 4, 6, MOD - 4, 1, 0, 5}, 
				{1, MOD - 5, 10, MOD - 10, 5, MOD - 1, 6}};
 
inline poly operator +(const poly &a, const poly &b){
	poly c;
	c.siz = a.siz;
	forn(i, a.siz) c[i] = add(a.a[i], b.a[i]);
	return c;
}
 
inline poly operator /(const poly &a, int x){
	poly c;
	c.siz = a.siz;
	int cur = 1;
	forn(i, a.siz){
		c[a.siz - i - 1] = mul(a.a[a.siz - i - 1], cur);
		cur = mul(cur, x);
	}
	return c;
}
 
inline poly operator %(const poly &a, int x){
	poly c;
	c.siz = a.siz;
	int cur = 1;
	forn(i, a.siz){
		c[i] = mul(a.a[i], cur);
		cur = mul(cur, x);
	}
	return c;
}
 
inline poly operator *(const poly &a, int x){
	poly c;
	c.siz = a.siz;
	forn(i, a.siz) c[i] = mul(a.a[i], x);
	return c;
}
 
inline int get(const poly &a){
	int sum = 0;
	forn(i, a.siz) sum = add(sum, a.a[i]);
	return sum;
}
 
poly t[4 * N][6];
poly t2[4 * N][6];
int ps[4 * N];
 
void build(int v, int l, int r){
	ps[v] = -1;
	if (l == r - 1){
		forn(i, 6){
			t[v][i] = polys[i] / (l + 1) * a[l];
			t2[v][i] = polys[i] / (l + 1);
		}
		return;
	}
	int m = (l + r) / 2;
	build(v * 2, l, m);
	build(v * 2 + 1, m, r);
	forn(i, 6){
		t[v][i] = t[v * 2][i] + t[v * 2 + 1][i];
		t2[v][i] = t2[v * 2][i] + t2[v * 2 + 1][i];
	}
}
 
inline void push(int v){
	if (ps[v] == -1) return;
	if (v * 2 + 1 < 4 * N){
		ps[v * 2] = ps[v];
		ps[v * 2 + 1] = ps[v];
	}
	forn(i, 6) t[v][i] = t2[v][i] * ps[v];
	ps[v] = -1;
}
 
void upd(int v, int l, int r, int L, int R, int val){
	push(v);
	if (L >= R)
		return;
	if (l == L && r == R){
		ps[v] = val;
		push(v);
		return;
	}
	int m = (l + r) / 2;
	upd(v * 2, l, m, L, min(m, R), val);
	upd(v * 2 + 1, m, r, max(m, L), R, val);
	forn(i, 6) t[v][i] = t[v * 2][i] + t[v * 2 + 1][i];
}
 
int get(int v, int l, int r, int L, int R, int val, int k){
	push(v);
	if (L >= R)
		return 0;
	if (l == L && r == R)
		return get(t[v][k] % val);
	int m = (l + r) / 2;
	int res = add(get(v * 2, l, m, L, min(m, R), val, k), get(v * 2 + 1, m, r, max(m, L), R, val, k));
	forn(i, 6) t[v][i] = t[v * 2][i] + t[v * 2 + 1][i];
	return res;
}
 
void solve(){
	build(1, 0, n);
	forn(i, m){
		int l = q[i].y.x;
		int r = q[i].y.y;
		int x = q[i].x.y;
		if (q[i].x.x == 1)
			upd(1, 0, n, l, r, x);
		else
			printf("%d\n", get(1, 0, n, l, r, l, x));
	}
}
 
int main() {

	freopen("input.txt", "r", stdin);


	
	int tt = clock();
	

	
	cerr.precision(15);
	cout.precision(15);
	cerr << fixed;
	cout << fixed;
 
	while(read()) {	
		solve();
		

	cerr << "TIME = " << clock() - tt << endl;
	tt = clock();

 
	}
}