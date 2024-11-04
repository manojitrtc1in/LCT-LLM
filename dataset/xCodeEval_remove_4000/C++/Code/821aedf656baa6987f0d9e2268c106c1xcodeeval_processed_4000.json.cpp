



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
const int K = 3;

int n;
li a[N];

bool read () {
	if (scanf("%d", &n) != 1)
		return false;
	forn(i, n)
		scanf("%lld", &a[i]);
	return true;
}

inline int add(int a, int b){
	a += b;
	if (a >= MOD) a -= MOD;
	return a;
}

inline int mul(int a, int b){
	return (a * li(b)) % MOD;
}

struct mat{
	int a[K][K];
	mat(){
		memset(a, 0, sizeof(a));
	};
	int* operator [](int x){
		return a[x];
	}
};

mat operator *(mat a, mat b){
	mat c;
	forn(i, K) forn(j, K) forn(k, K)
		c[i][j] = add(c[i][j], mul(a[i][k], b[k][j]));
	return c;
}

inline mat binpow(mat a, li b){
	mat res;
	forn(i, K) res[i][i] = 1;
	while (b){
		if (b & 1)
			res = res * a;
		a = a * a;
		b >>= 1;
	}
	return res;
}

inline int binpow(int a, li b){
	int res = 1;
	while (b){
		if (b & 1)
			res = mul(res, a);
		a = mul(a, a);
		b >>= 1;
	}
	return res;
}

void solve() {
	int pw = 1;
	forn(i, n) pw = (pw * li(a[i] % (MOD - 1))) % (MOD - 1);
	
	if (pw == 0)
		pw = MOD - 1;
	
	mat dp;
	dp[1][0] = 1;
	dp[2][1] = 1;
	dp[1][2] = 2;
	dp[2][2] = 1;
	dp = binpow(dp, pw);
	
	mat tmp;
	tmp[0][2] = 1;
	tmp = tmp * dp;
	
	int p2 = 2;
	p2 = binpow(p2, (pw + (MOD - 2)) % (MOD - 1));
	
	printf("%d/%d\n", tmp[0][0], p2);
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