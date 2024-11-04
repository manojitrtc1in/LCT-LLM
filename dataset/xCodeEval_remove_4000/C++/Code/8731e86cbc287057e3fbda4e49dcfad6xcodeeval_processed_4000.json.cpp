






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

const int INF = int(1e9) + 7;
const li INF64 = li(1e18);
const int MOD = INF + 7;
const ld EPS = 1e-9;
const ld PI = acos(-1.0);

const int N = 1000 * 1000 + 13;

int n;
int a[N];

bool read () {
	if (scanf("%d", &n) != 1)
		return false;
	forn(i, n)
		scanf("%d", &a[i]);
	return true;
}

li t[4 * N];
li ps[4 * N];

void push(int v){
	if (ps[v] == 0)
		return;
	if (v * 2 + 1 < 4 * N){
		ps[v * 2] += ps[v];
		ps[v * 2 + 1] += ps[v];
	}
	t[v] += ps[v];
	ps[v] = 0;
}

void upd(int v, int l, int r, int L, int R, int val){
	push(v);
	if (L >= R)
		return;
	if (l == L && r == R){
		ps[v] += val;
		push(v);
		return;
	}
	int m = (l + r) / 2;
	upd(v * 2, l, m, L, min(m, R), val);
	upd(v * 2 + 1, m, r, max(m, L), R, val);
	t[v] = max(t[v * 2], t[v * 2 + 1]);
}

void upd(int v, int l, int r, int pos, li val){
	push(v);
	if (l == r - 1){
		t[v] = val;
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
	t[v] = max(t[v * 2], t[v * 2 + 1]);
}

li get(int v, int l, int r, int L, int R){
	push(v);
	if (L >= R)
		return -INF64;
	if (l == L && r == R)
		return t[v];
	int m = (l + r) / 2;
	li res = max(get(v * 2, l, m, L, min(m, R)), get(v * 2 + 1, m, r, max(m, L), R));
	t[v] = max(t[v * 2], t[v * 2 + 1]);
	return res;
}

li dp[N];

void solve() {
	vector<pt> stmn, stmx;
	stmx.pb(mp(INF, 0));
	stmn.pb(mp(-INF, 0));
	dp[0] = 0;
	upd(1, 0, n + 1, 0, 0);
	forn(i, n){
		while (stmx.back().x < a[i]){
			int x = stmx.back().x;
			int lst = stmx.back().y;
			stmx.pop_back();
			upd(1, 0, n + 1, stmx.back().y, lst, -x);
		}
		upd(1, 0, n + 1, stmx.back().y, i + 1, a[i]);
		stmx.pb(mp(a[i], i + 1));
		
		while (stmn.back().x > a[i]){
			int x = stmn.back().x;
			int lst = stmn.back().y;
			stmn.pop_back();
			upd(1, 0, n + 1, stmn.back().y, lst, x);
		}
		upd(1, 0, n + 1, stmn.back().y, i + 1, -a[i]);
		stmn.pb(mp(a[i], i + 1));
		
		dp[i + 1] = get(1, 0, n + 1, 0, i + 1);
		upd(1, 0, n + 1, i + 1, dp[i + 1]);
	}
	printf("%lld\n", dp[n]);
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