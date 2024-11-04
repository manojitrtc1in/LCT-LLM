



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
const int M = 21;
const int LOGN = 18;

int n, m, d;
vector<int> a[N];

bool read () {
	if (scanf("%d%d%d", &n, &m, &d) != 3)
		return false;
	forn(i, m){
		int k;
		scanf("%d", &k);
		a[i].resize(k);
		forn(j, k){
			scanf("%d", &a[i][j]);
			--a[i][j];
		}
	}
	return true;
}

int vals[N];
int st[LOGN][N];
int pw[N];

void init(){
	forn(i, n) st[0][i] = vals[i];
	fore(j, 1, LOGN) forn(i, n){
		st[j][i] = st[j - 1][i];
		if (i + (1 << (j - 1)) < n)
			st[j][i] |= st[j - 1][i + (1 << (j - 1))];
	}
	pw[0] = pw[1] = 0;
	fore(i, 2, N) pw[i] = pw[i / 2] + 1;
}

int get(int l, int r){
	if (l >= r) return 0;
	int len = pw[r - l];
	return st[len][l] | st[len][r - (1 << len)];
}

int clr[N];
int needl[N], needr[N];
int tot[1 << M][M];

void solve() {
	forn(i, m) for (auto x : a[i]){
		clr[x] = i;
		vals[x] = 1 << i;
	}
	init();
	forn(i, n){
		needl[i] = get(max(0, i - d), i);
		needr[i] = get(i + 1, min(n, i + d + 1));
		if (i - d < 0) needl[i] |= (1 << m);
		if (i + d >= n) needr[i] |= (1 << m);
	}
	
	memset(tot, 0, sizeof(tot));
	int fl = 1 << (m + 1);
	forn(i, n){
		++tot[(~needl[i]) & (fl - 1)][clr[i]];
		++tot[(~needr[i]) & (fl - 1)][clr[i]];
	}
	forn(i, m + 1) for (int mask = fl - 1; mask >= 0; --mask) if ((mask >> i) & 1) forn(j, m + 1){
		tot[mask ^ (1 << i)][j] += tot[mask][j];
	}
	
	int ans = m + 1;
	forn(mask, 1 << (m + 1)){
		if (mask == 0 || mask == (1 << m))
			continue;
		bool ok = true;
		
		forn(i, m + 1) ok &= tot[mask][i] == 0;
		if (ok) ans = min(ans, __builtin_popcount(mask));
	}
	printf("%d\n", ans - 1);
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