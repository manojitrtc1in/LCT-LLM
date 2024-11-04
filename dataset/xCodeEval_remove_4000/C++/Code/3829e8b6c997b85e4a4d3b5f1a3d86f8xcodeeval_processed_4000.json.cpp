



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

const int N = 32;

li n;
int k;

bool read () {
	if (scanf("%lld%d", &n, &k) != 2)
		return false;
	return true;
}

int add(int a, int b){
	a += b;
	if (a >= MOD)
		a -= MOD;
	return a;
}

int mul(int a, int b){
	return a * li(b) % MOD;
}

typedef array<array<int, N>, N> mat;

mat operator *(const mat &a, const mat &b){
	mat c;
	forn(i, k + 1) forn(j, k + 1) c[i][j] = 0;
	forn(i, k + 1) forn(j, k + 1) forn(t, k + 1) c[i][j] = add(c[i][j], mul(a[i][t], b[t][j]));
	return c;
}

mat amat[62][N];

void solve(){
	vector<int> num;
	while (n > 0){
		num.pb(n % k);
		n /= k;
	}
	
	forn(d, k){
		forn(i, k + 1) forn(j, k + 1)
			amat[0][d][i][j] = 0;
		forn(i, k + 1)
			amat[0][d][i][i] = 1;
		forn(i, k + 1)
			amat[0][d][i][d] = 1;
	}
	
	fore(r, 1, sz(num)){
		vector<mat> pr;
		pr.pb(mat());
		forn(i, k + 1) forn(j, k + 1)
			pr[0][i][j] = i == j;
		forn(i, k)
			pr.pb(pr.back() * amat[r - 1][i]);
		forn(sh, k){
			amat[r][sh] = pr[0];
			forn(i, k - sh)
				amat[r][sh] = amat[r][sh] * amat[r - 1][(i + sh) % k];
			amat[r][sh] = amat[r][sh] * pr[sh];
		}
	}
	
	mat dp;
	forn(i, k + 1) forn(j, k + 1)
		dp[i][j] = 0;
	dp[0][k] = 1;
	
	int rem = 0;
	for (int i = sz(num) - 1; i >= 0; --i){
		while (num[i] > 0){
			dp = dp * amat[i][rem];
			rem = (rem + 1) % k;
			--num[i];
		}
	}
	
	int ans = 0;
	forn(i, k + 1)
		ans = add(ans, dp[0][i]);
	printf("%d\n", ans);
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