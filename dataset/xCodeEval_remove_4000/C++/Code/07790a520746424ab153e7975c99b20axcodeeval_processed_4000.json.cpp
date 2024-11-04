



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

int n;
pt a[N];

bool read () {
	if (scanf("%d", &n) != 1)
		return false;
	forn(i, n){
		scanf("%d", &a[i].x);
		--a[i].x;
	}
	forn(i, n){
		scanf("%d", &a[i].y);
	}
	return true;
}

li t[4 * N];
li ps[4 * N];

void push(int v){
	if (v * 2 + 1 < 4 * N){
		ps[v * 2] += ps[v];
		ps[v * 2 + 1] += ps[v];
	}
	t[v] += ps[v];
	ps[v] = 0;
}

void add(int v, int l, int r, int L, int R, li val){
	push(v);
	if (L >= R)
		return;
	if (l == L && r == R){
		ps[v] += val;
		push(v);
		return;
	}
	int m = (l + r) / 2;
	add(v * 2, l, m, L, min(m, R), val);
	add(v * 2 + 1, m, r, max(m, L), R, val);
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
	int m = n + 1;
	forn(i, 4 * N) t[i] = ps[i] = 0;
	dp[0] = 0;
	vector<pt> cur(1, mp(-INF, -1));
	forn(i, n){
		while (cur.back().x > a[i].x){
			int j = cur.back().y;
			cur.pop_back();
			add(1, 0, m, cur.back().y + 1, j + 1, -a[j].y);
		}
		add(1, 0, m, cur.back().y + 1, i + 1, a[i].y);
		cur.pb(mp(a[i].x, i));
		dp[i + 1] = get(1, 0, m, 0, i + 1);
		add(1, 0, m, i + 1, i + 2, dp[i + 1]);
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


	int tc;
	scanf("%d", &tc);
	while(tc--){
		read();

	if(read()) {	

		solve();
		

	cerr << "TIME = " << clock() - tt << endl;
	tt = clock();


	}
}