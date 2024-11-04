



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
const int MOD = 998244353;
const ld EPS = 1e-9;
const ld PI = acos(-1.0);

const int N = 500 + 7;

int n, m;
int a[N];

bool read () {
	if (scanf("%d%d", &n, &m) != 2)
		return false;
	forn(i, n)
		scanf("%d", &a[i]);
	return true;
}

int add(int a, int b){
	a += b;
	if (a >= MOD)
		a -= MOD;
	if (a < 0)
		a += MOD;
	return a;
}

int mul(int a, int b){
	return  a * li(b) % MOD;
}

int mn[N][N];
int dp[N][N];

int calc(int l, int r){
	if (dp[l][r] != -1)
		return dp[l][r];
	if (l >= r - 1)
		return dp[l][r] = 1;
	
	int pos = mn[l][r];
	int suml = 0, sumr = 0;
	fore(k, l, pos + 1)
		suml = add(suml, mul(calc(l, k), calc(k, pos)));
	fore(k, pos + 1, r + 1)
		sumr = add(sumr, mul(calc(pos + 1, k), calc(k, r)));
	

	return dp[l][r] = mul(suml, sumr);
}

void solve() {
	forn(i, n){
		int cur = INF;
		int pos = -1;
		fore(j, i, n){
			if (a[j] < cur){
				cur = a[j];
				pos = j;
			}
			mn[i][j + 1] = pos;
		}
	}
	memset(dp, -1, sizeof(dp));
	

	

	printf("%d\n", calc(0, n));
	

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