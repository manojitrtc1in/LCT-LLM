



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
const int K = 21;

int n, k;
int a[N];

bool read () {
	if (scanf("%d%d", &n, &k) != 2)
		return false;
	forn(i, n)
		scanf("%d", &a[i]);
	return true;
}

li dp[2][N];
int cnt[N];
int cl, cr;
li cur;

void add(int x){
	++cnt[a[x]];
	cur += 2 * cnt[a[x]] - 1;
}

void rem(int x){
	cur -= 2 * cnt[a[x]] - 1;
	--cnt[a[x]];
}

void compute(int i, int l, int r, int optl, int optr){
	if (l > r) return;
	int m = (l + r) / 2;
	li bst = 3 * INF64;
	int opt = -1;
	
	while (cl < min(m, optr) + 1) rem(cl++);
	while (cl > min(m, optr) + 1) add(--cl);
	while (cr < m) add(++cr);
	while (cr > m) rem(cr--);
	
	for (int k = min(m, optr); k >= optl; --k){
		add(k);
		if (dp[i][k] + cur < bst){
			bst = dp[i][k] + cur;
			opt = k;
		}
	}
	fore(k, optl, min(m, optr) + 1){
		rem(k);
	}

    dp[i ^ 1][m + 1] = min(INF64, bst);

    compute(i, l, m - 1, optl, opt);
    compute(i, m + 1, r, opt, optr);
}

void solve() {
	forn(i, 2) forn(j, N)
		dp[i][j] = INF64;
	dp[0][0] = 0;
	cl = 0, cr = -1;
	cur = 0;
	forn(i, k) compute(i & 1, 0, n - 1, 0, n - 1);
	printf("%lld\n", (dp[k & 1][n] - n) / 2);
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