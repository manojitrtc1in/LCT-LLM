



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
const int MOD = int(1e9) + 7;
const ld EPS = 1e-9;
const ld PI = acos(-1.0);

const int N = 300 * 1000 + 13;

int n, m;
int a[N];
pt q[N];

bool read () {
	if (scanf("%d%d", &n, &m) != 2)
		return false;
	forn(i, n){
		scanf("%d", &a[i]);
		--a[i];
	}
	forn(i, m){
		scanf("%d%d", &q[i].x, &q[i].y);
		q[i].y = n - q[i].y - 1;
	}
	return true;
}

int t[4 * N], ps[4 * N];

void push(int v){
	if (v * 2 + 1 < 4 * N){
		ps[v * 2] += ps[v];
		ps[v * 2 + 1] += ps[v];
	}
	t[v] += ps[v];
	ps[v] = 0;
}

void build(int v, int l, int r){
	t[v] = INF;
	ps[v] = 0;
	if (l == r - 1)
		return;
	int m = (l + r) / 2;
	build(v * 2, l, m);
	build(v * 2 + 1, m, r);
}

void upd(int v, int l, int r, int pos, int val){
	push(v);
	if (l == r - 1){
		t[v] = val;
		return;
	}
	int m = (l + r) / 2;
	push(v * 2);
	push(v * 2 + 1);
	if (pos < m)
		upd(v * 2, l, m, pos, val);
	else
		upd(v * 2 + 1, m, r, pos, val);
	t[v] = min(t[v * 2], t[v * 2 + 1]);
}

void add(int v, int l, int r, int L, int R){
	push(v);
	if (L >= R)
		return;
	if (l == L && r == R){
		--ps[v];
		push(v);
		return;
	}
	int m = (l + r) / 2;
	add(v * 2, l, m, L, min(m, R));
	add(v * 2 + 1, m, r, max(m, L), R);
	t[v] = min(t[v * 2], t[v * 2 + 1]);
}

int get(int v, int l, int r){
	push(v);
	if (l == r - 1)
		return (t[v] <= 0 ? l : -1);
	int m = (l + r) / 2;
	int res = -1;
	push(v * 2);
	push(v * 2 + 1);
	if (t[v * 2] <= 0)
		res = get(v * 2, l, m);
	else if (t[v * 2 + 1] <= 0)
		res = get(v * 2 + 1, m, r);
	t[v] = min(t[v * 2], t[v * 2 + 1]);
	return res;
}

vector<int> qs[N];
int ans[N];

int f[N];

void upd(int x){
	for (int i = x; i < N; i |= i + 1)
		++f[i];
}

int get(int x){
	int res = 0;
	for (int i = x; i >= 0; i = (i & (i + 1)) - 1)
		res += f[i];
	return res;
}

void solve() {
	forn(i, n) a[i] = i - a[i];
	forn(i, n) if (a[i] < 0) a[i] = INF;
	build(1, 0, n);
	memset(f, 0, sizeof(f));
	
	forn(i, n) qs[i].clear();
	forn(i, m) qs[q[i].x].pb(i);
	
	for (int i = n - 1; i >= 0; --i){
		upd(1, 0, n, i, a[i]);
		int x;
		while ((x = get(1, 0, n)) != -1){
			upd(x);
			add(1, 0, n, x, n);
			upd(1, 0, n, x, INF);
		}
		for (auto j : qs[i]){
			ans[j] = get(q[j].y);
		}
	}
	
	forn(i, m) printf("%d\n", ans[i]);
}

int main() {

	freopen("input.txt", "r", stdin);


	
	int tt = clock();
	

	
	cerr.precision(15);
	cout.precision(15);
	cerr << fixed;
	cout << fixed;


	int tc;
	scanf("%d", &tc);
	while(tc--){
		read();

	while(read()) {	

		solve();
		

	cerr << "TIME = " << clock() - tt << endl;
	tt = clock();


	}
}