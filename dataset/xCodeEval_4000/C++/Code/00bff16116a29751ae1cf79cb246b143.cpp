

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
const int MOD = 31607;
const ld EPS = 1e-9;
const ld PI = acos(-1.0);

const int N = 21;

int n;
int a[N][N];

bool read () {
	if (scanf("%d", &n) != 1)
		return false;
	forn(i, n) forn(j, n)
		scanf("%d", &a[i][j]);
	return true;
}

inline void inc(int &x, int y) {
    x += y;
    if (x >= MOD) {
        x -= MOD;
    }
}

inline void dec(int &x, int y) {
    x -= y;
    if (x < 0) {
        x += MOD;
    }
}

int mul(int x, int y) {
    return x * y % MOD;
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

template<bool inv>
void and_convolution(int n, int a[]) {
    if (n == 0) {
        return;
    }
    for (int i = 0; i < n / 2; ++i) {
        if (inv) {
            dec(a[i], a[i + n / 2]);
        } else {
            inc(a[i], a[i + n / 2]);
        }
    }
    and_convolution<inv>(n / 2, a);
    and_convolution<inv>(n / 2, a + n / 2);
}

int lst[1 << 23];
int res[1 << 23], tmp[1 << 21], cur[1 << 23];
int val[N];

void solve() {
	fore(mask, 1, 1 << (n + 2)) lst[mask] = __builtin_ctz(mask);
	memset(res, 0, sizeof(int) * (1 << (n + 2)));
	res[(1 << (n + 2)) - 1] = 1;
	and_convolution<false>(1 << (n + 2), res);
	forn(j, n){
		forn(i, n) val[i] = mul(binpow(10000 - a[i][j], MOD - 2), a[i][j]);
		tmp[0] = 1;
		forn(i, n) tmp[0] = mul(tmp[0], 10000 - a[i][j]);
		tmp[0] = mul(tmp[0], binpow(binpow(10000, MOD - 2), n));
		memset(cur, 0, sizeof(int) * (1 << (n + 2)));
		fore(mask, 1, 1 << n)
			tmp[mask] = mul(tmp[mask ^ (1 << lst[mask])], val[lst[mask]]);
		tmp[(1 << n) - 1] = 0;
		forn(mask, 1 << n){
			int nmask = mask;
			if ((mask >> j) & 1) nmask |= 1 << n;
			if ((mask >> (n - j - 1)) & 1) nmask |= 1 << (n + 1);
			cur[nmask] = tmp[mask];
		}
		and_convolution<false>(1 << (n + 2), cur);
		forn(mask, 1 << (n + 2)){
			res[mask] = mul(res[mask], cur[mask]);
		}
	}
	and_convolution<true>(1 << (n + 2), res);
	int ans = 0;
	int prv = 1;
	forn(j, n){
		int tot = 1;
		forn(i, n) tot = mul(tot, a[i][j]);
		tot = mul(tot, binpow(binpow(10000, MOD - 2), n));
		inc(ans, mul(tot, prv));
		prv = mul(prv, (MOD + 1 - tot) % MOD);
	}
	fore(mask, 1, 1 << (n + 2)){
		inc(ans, res[mask]);
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