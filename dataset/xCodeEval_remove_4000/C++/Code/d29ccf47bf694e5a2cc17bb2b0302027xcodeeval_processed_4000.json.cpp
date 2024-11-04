



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

const int N = 100 + 7;

int n, m;
vector<pt> a[N];

bool read () {
	if (scanf("%d%d", &n, &m) != 2)
		return false;
	forn(i, n){
		int k;
		scanf("%d", &k);
		a[i].resize(k);
		forn(j, k){
			scanf("%d%d", &a[i][j].x, &a[i][j].y);
			--a[i][j].x;
		}
	}
	return true;
}

int dp[N][N];
int num[N][N];

int calc(int l, int r){
	if (dp[l][r] != -1)
		return dp[l][r];
	if (l == r)
		return dp[l][r] = 0;
	dp[l][r] = 0;
	fore(m, l, r){
		int cnt = 0;
		forn(i, n)
			cnt += l <= a[i][num[i][m]].x && a[i][num[i][m]].y <= r;
		dp[l][r] = max(dp[l][r], calc(l, m) + calc(m + 1, r) + sqr(cnt));
	}
	return dp[l][r];
}

void solve(){
	forn(i, n) forn(j, sz(a[i])) fore(k, a[i][j].x, a[i][j].y)
		num[i][k] = j;
	memset(dp, -1, sizeof(dp));
	printf("%d\n", calc(0, m));
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