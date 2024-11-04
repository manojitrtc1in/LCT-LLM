

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
const int MOD = INF + 7;
const ld EPS = 1e-9;
const ld PI = acos(-1.0);

const int N = 1000 * 1000 + 13;
const int LOGN = 17;
const int M = 1 << LOGN;

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

int A[M], B[M], C[M];
int conv[M];
int fib[M];

void trans(int conv[M], int l, int r){
	if (l == r - 1)
		return;
	int m = (l + r) / 2;
	trans(conv, l, m);
	trans(conv, m, r);
	forn(i, m - l){
		int a = conv[l + i];
		int b = conv[m + i];
		conv[l + i] = add(a, b);
		conv[m + i] = add(a, -b);
	}
}

void solve() {
	memset(B, 0, sizeof(B));
	forn(i, n) ++B[a[i]];
	
	memcpy(C, B, sizeof(B));
	trans(C, 0, M);
	forn(i, M) C[i] = mul(C[i], C[i]);
	trans(C, 0, M);
	int rev = binpow(M, MOD - 2);
	forn(i, M) C[i] = mul(C[i], rev);
	
	forn(mask, M){
		A[mask] = mul(B[0], B[mask]);
		for (int pmask = mask; pmask > 0; pmask = (pmask - 1) & mask)
			A[mask] = add(A[mask], mul(B[pmask], B[mask ^ pmask]));
	}
	
	fib[0] = 0, fib[1] = 1;
	fore(i, 2, M) fib[i] = add(fib[i - 1], fib[i - 2]);
	
	forn(i, M){
		A[i] = mul(A[i], fib[i]);
		B[i] = mul(B[i], fib[i]);
		C[i] = mul(C[i], fib[i]);
	}
	
	forn(i, LOGN) for (int mask = M - 1; mask >= 0; --mask) if (!((mask >> i) & 1)){
		A[mask] = add(A[mask], A[mask ^ (1 << i)]);
		B[mask] = add(B[mask], B[mask ^ (1 << i)]);
		C[mask] = add(C[mask], C[mask ^ (1 << i)]);
	}
	
	int ans = 0;
	fore(mask, 1, M){
		int c = __builtin_popcount(mask);
		ans = add(ans, mul(c, mul(mul(A[mask], B[mask]), mul(C[mask], (c & 1) ? 1 : (MOD - 1)))));
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

	while(read()) {	
		solve();
		
#ifdef _DEBUG
	cerr << "TIME = " << clock() - tt << endl;
	tt = clock();
#endif

	}
}