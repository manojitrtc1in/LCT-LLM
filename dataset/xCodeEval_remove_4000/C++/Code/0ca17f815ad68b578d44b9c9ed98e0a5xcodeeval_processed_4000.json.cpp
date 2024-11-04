



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

const int N = 200 * 1000 + 13;

int n, a, b;
int p[N];

bool read () {
	if (scanf("%d%d%d", &n, &a, &b) != 3)
		return false;
	--a, --b;
	forn(i, n) scanf("%d", &p[i]);
	return true;
}

pt t1[4 * N], t2[4 * N];

void build(int v, int l, int r){
	if (l == r - 1){
		t1[v] = mp(l + p[l], l);
		t2[v] = mp(-(l - p[l]), l);
		return;
	}
	int m = (l + r) / 2;
	build(v * 2, l, m);
	build(v * 2 + 1, m, r);
	t1[v] = max(t1[v * 2], t1[v * 2 + 1]);
	t2[v] = max(t2[v * 2], t2[v * 2 + 1]);
}

void upd(int v, int l, int r, int pos){
	if (l == r - 1){
		t1[v] = mp(-INF, -1);
		t2[v] = mp(-INF, -1);
		return;
	}
	int m = (l + r) / 2;
	if (pos < m)
		upd(v * 2, l, m, pos);
	else
		upd(v * 2 + 1, m, r, pos);
	t1[v] = max(t1[v * 2], t1[v * 2 + 1]);
	t2[v] = max(t2[v * 2], t2[v * 2 + 1]);
}

pt get(pt t[4 * N], int v, int l, int r, int L, int R){
	if (L >= R)
		return mp(-INF, -1);
	if (l == L && r == R)
		return t[v];
	int m = (l + r) / 2;
	return max(get(t, v * 2, l, m, L, min(m, R)), get(t, v * 2 + 1, m, r, max(m, L), R));
}

int d[N];

void solve() {
	build(1, 0, n);
	forn(i, n) d[i] = INF;
	d[a] = 0;
	upd(1, 0, n, a);
	queue<int> q;
	q.push(a);
	while (!q.empty()){
		int v = q.front();
		q.pop();
		while (true){
			auto res = get(t1, 1, 0, n, max(0, v - p[v]), v);
			if (res.x < v) break;
			int u = res.y;
			upd(1, 0, n, u);
			d[u] = d[v] + 1;
			q.push(u);
		}
		while (true){
			auto res = get(t2, 1, 0, n, v + 1, min(n, v + p[v] + 1));
			if (-res.x > v) break;
			int u = res.y;
			upd(1, 0, n, u);
			d[u] = d[v] + 1;
			q.push(u);
		}
	}
	printf("%d\n", d[b]);
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