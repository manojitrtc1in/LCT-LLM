

#include <bits/stdc++.h>

using namespace std;




#define x first
#define y second
#define mp make_pair
#define pb push_back
#define sqr(a) ((a) * (a))
#define sz(a) int(a.size())
#define all(a) a.begin(), a.end()
#define forn(i, n) for(int i = 0; i < int(n); i++) 
#define fore(i, l, r) for(int i = int(l); i < int(r); i++)

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

const int N = 300 * 1000 + 13;

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
	return a * li(b) % MOD;
}

int binpow(int a, int b){
	int res = 1;
	while (b){
		if (b & 1)
			res = mul(res, a);
		a = mul(a, a);
		b >>= 1;
	}
	return res;
}

int fact[N], rfact[N];

int cnk(int n, int k){
	if (k < 0 || n < 0 || k > n) return 0;
	return mul(fact[n], mul(rfact[k], rfact[n - k]));
}

void solve() {
	fact[0] = 1;
	fore(i, 1, N) fact[i] = mul(fact[i - 1], i);
	rfact[N - 1] = binpow(fact[N - 1], MOD - 2);
	for (int i = N - 2; i >= 0; --i)
		rfact[i] = mul(rfact[i + 1], i + 1);
	
	li tot = accumulate(a, a + n, 0ll);
	int j = 0;
	int cnt = 0;
	li dist = 0;
	forn(i, n){
		while (dist * 2 < tot){
			dist += a[j];
			j = (j + 1) % n;
		}
		if (dist * 2 == tot){
			++cnt;
		}
		dist -= a[i];
	}
	assert(cnt % 2 == 0);
	cnt /= 2;
	
	int ans = 0;
	forn(i, cnt + 1){
		int cur = mul(cnk(cnt, i), mul(cnk(m, i), fact[i]));
		cur = mul(cur, binpow(mul(m - i, m - i - 1), cnt - i));
		cur = mul(cur, binpow(m - i, n - 2 * cnt));
		ans = add(ans, cur);
	}
	
	printf("%d\n", ans);
}

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);


	
	int tt = clock();
	
#endif
	
	cerr.precision(15);
	cout.precision(15);
	cerr << fixed;
	cout << fixed;

#ifdef MULTITEST
	int tc;
	scanf("%d", &tc);
	while(tc--){
		read();
#else
	while(read()) {	
#endif
		solve();
		
#ifdef _DEBUG
	cerr << "TIME = " << clock() - tt << endl;
	tt = clock();
#endif

	}
}