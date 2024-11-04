

#include <bits/stdc++.h>

using namespace std;

#define MULTITEST

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

const int N = 200 * 1000 + 13;

int n;
int a[N];

bool read () {
	if (scanf("%d", &n) != 1)
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

int get(int n, int m){
	return add(cnk(n + m, n), -1);
}

void solve() {
	int ans = 0;
	int cur = 1, l = 0, r = n;
	li prl = 0, prr = 0;
	forn(i, n){
		int l0 = l, r0 = r;
		while (l0 < r0 && a[l0] == 0) ++l0;
		while (l0 < r0 && a[r0 - 1] == 0) --r0;
		

		if (l0 == r0){
			if (l == 0)
				ans = add(ans, mul(cur, binpow(2, r - l - 1)));
			else
				ans = add(ans, mul(cur, add(binpow(2, r - l + 1), -1)));
			

			break;
		}
		int L = l0 - l, R = r - r0;
		if (l == 0)
			ans = add(ans, add(1, get(L, R)));
		else
			ans = add(ans, mul(cur, get(L + 1, R + 1)));
		

		if (l == 0)
			cur = add(1, get(L, R));
		else
			cur = add(cur, mul(cur, get(L + 1, R + 1)));
		l = l0, r = r0;
		prl += a[l];
		++l;
		while (l < r && prl != prr){
			if (prl < prr){
				prl += a[l];
				++l;
			}
			else{
				--r;
				prr += a[r];
			}
		}
		if (l > r || prl != prr) break;
	}
	printf("%d\n", ans);
}

void init(){
	fact[0] = 1;
	fore(i, 1, N) fact[i] = mul(fact[i - 1], i);
	rfact[N - 1] = binpow(fact[N - 1], MOD - 2);
	for (int i = N - 2; i >= 0; --i)
		rfact[i] = mul(rfact[i + 1], i + 1);
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

	init();
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