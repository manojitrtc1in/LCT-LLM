



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

const int N = 1500 + 7;

int n;
int a[N][N];

bool read () {
	if (scanf("%d", &n) != 1)
		return false;
	forn(i, n) forn(j, n){
		scanf("%d", &a[i][j]);
		--a[i][j];
	}
	return true;
}

pt pos[N * N];
int r[N], c[N];

void solve() {
	forn(i, n) r[i] = c[i] = 0;
	forn(i, n) forn(j, n) pos[a[i][j]] = mp(i, j);
	li ans = 0;
	forn(x, n * n){
		int i = pos[x].x, j = pos[x].y;
		ans += r[i] * li(n - c[j] - 1) + (n - r[i] - 1) * li(c[j]);
		++r[i];
		++c[j];
	}
	assert(ans % 2 == 0);
	printf("%lld\n", ans / 2);
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