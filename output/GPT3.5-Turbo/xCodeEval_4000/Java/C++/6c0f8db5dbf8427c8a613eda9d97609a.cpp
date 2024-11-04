#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <deque>
#include <bitset>
#include <sstream>
#include <fstream>
#include <ctime>
#include <cassert>
#include <list>
#include <iomanip>
#include <climits>
#include <complex>
#include <iterator>
#include <functional>
#include <numeric>
#include <cctype>
#include <array>
#include <tuple>
#include <unordered_set>
#include <unordered_map>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef vector<string> vs;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<char> vc;
typedef vector<vc> vvc;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<vpii> vvpii;
typedef vector<pll> vpll;
typedef vector<vpll> vvpll;

#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i <= (n); ++i)
#define all(c) (c).begin(), (c).end()
#define sz(x) (int)(x).size()
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define fi first
#define se second
#define chmin(x, y) x = min(x, y)
#define chmax(x, y) x = max(x, y)
#define dump(x) cerr << #x << " = " << (x) << endl
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> ostream& operator<<(ostream& os, const vector<T>& t) { rep(i, sz(t)) { os << t[i] << " "; } return os; }
template<class T> ostream& operator<<(ostream& os, const vector<vector<T>>& t) { rep(i, sz(t)) { os << t[i] << endl; } return os; }
template<class S, class T> ostream& operator<<(ostream& os, const pair<S, T>& t) { return os << "(" << t.first << ", " << t.second << ")"; }
template<class S, class T> ostream& operator<<(ostream& os, const map<S, T>& t) { for (auto i = t.begin(); i != t.end(); ++i) { os << *i << " "; } return os; }
template<class S, class T> ostream& operator<<(ostream& os, const unordered_map<S, T>& t) { for (auto i = t.begin(); i != t.end(); ++i) { os << *i << " "; } return os; }
template<class T> ostream& operator<<(ostream& os, const set<T>& t) { for (auto i = t.begin(); i != t.end(); ++i) { os << *i << " "; } return os; }
template<class T> ostream& operator<<(ostream& os, const unordered_set<T>& t) { for (auto i = t.begin(); i != t.end(); ++i) { os << *i << " "; } return os; }
template<class T> inline void output(T t, int n, int m) { rep(i, n) { rep(j, m) { cout << t[i][j] << " "; } cout << endl; } }
template<class T> inline void output(T t, int n) { rep(i, n) { cout << t[i] << endl; } }
template<class T> inline void output(T t) { cout << t << endl; }
template<class T> inline T input() { T res; cin >> res; return res; }
template<class T> inline vector<T> input(int n) { vector<T> res(n); rep(i, n) { res[i] = input<T>(); } return res; }
template<class T> inline vector<vector<T>> input(int n, int m) { vector<vector<T>> res(n); rep(i, n) { res[i] = input<T>(m); } return res; }
template<class T> inline vector<vector<vector<T>>> input(int n, int m, int l) { vector<vector<vector<T>>> res(n); rep(i, n) { res[i] = input<T>(m, l); } return res; }
template<class T> inline vector<vector<vector<vector<T>>>> input(int n, int m, int l, int k) { vector<vector<vector<vector<T>>>> res(n); rep(i, n) { res[i] = input<T>(m, l, k); } return res; }
template<class T> inline vector<vector<vector<vector<vector<T>>>>> input(int n, int m, int l, int k, int o) { vector<vector<vector<vector<vector<T>>>>> res(n); rep(i, n) { res[i] = input<T>(m, l, k, o); } return res; }
template<class T> inline vector<vector<vector<vector<vector<vector<T>>>>>> input(int n, int m, int l, int k, int o, int p) { vector<vector<vector<vector<vector<vector<T>>>>>> res(n); rep(i, n) { res[i] = input<T>(m, l, k, o, p); } return res; }

const ll MOD = 998244353;
const int INF = 1e9;
const ll LINF = 1e18;
const double EPS = 1e-10;
const double PI = acos(-1.0);
mt19937_64 RANDOM(chrono::steady_clock::now().time_since_epoch().count());

ll powmod(ll a, ll b) {
	ll res = 1;
	while (b > 0) {
		if (b & 1) res = res * a % MOD;
		a = a * a % MOD;
		b >>= 1;
	}
	return res;
}

ll inv(ll a) {
	return powmod(a, MOD - 2);
}

ll C(int n, int r, vector<vector<ll>>& fif) {
	if (n < 0 || r < 0 || r > n) return 0;
	return fif[0][n] * fif[1][r] % MOD * fif[1][n - r] % MOD;
}

vector<vector<ll>> enumFIF(int n) {
	vector<ll> f(n + 1), invf(n + 1);
	f[0] = 1;
	for (int i = 1; i <= n; i++) {
		f[i] = f[i - 1] * i % MOD;
	}
	invf[n] = inv(f[n]);
	for (int i = n - 1; i >= 0; i--) {
		invf[i] = invf[i + 1] * (i + 1) % MOD;
	}
	return { f, invf };
}

void solve() {
	int n = input<int>();
	vi a = input<int>(26);
	ll all = 26 * 26 * powmod(25, n - 2) % MOD;

	vector<vector<vector<ll>>> dp(3, vector<vector<ll>>(n + 1, vector<ll>(n + 1)));
	dp[0][1][0] = 1;
	dp[1][0][1] = 1;
	dp[2][0][0] = 1;
	for (int i = 0; i < n - 1; i++) {
		vector<vector<vector<ll>>> ndp(3, vector<vector<ll>>(n + 1, vector<ll>(n + 1)));
		if (i == (n + 1) / 2 - 1) {
			for (int j = 0; j <= n; j++) {
				for (int k = 0; j + k <= n; k++) {
					if (j + 1 <= n) {
						ndp[0][j + 1][k] += dp[0][j][k] + dp[1][j][k] + dp[2][j][k] * 24;
						ndp[0][j + 1][k] %= MOD;
					}
					if (k + 1 <= n) {
						ndp[1][j][k + 1] += dp[0][j][k] + dp[1][j][k] + dp[2][j][k] * 24;
						ndp[1][j][k + 1] %= MOD;
					}
					ndp[2][j][k] += dp[0][j][k] + dp[1][j][k] + dp[2][j][k] * 24;
					ndp[2][j][k] %= MOD;
				}
			}
		}
		else {
			for (int j = 0; j <= n; j++) {
				for (int k = 0; j + k <= n; k++) {
					if (j + 1 <= n) {
						ndp[0][j + 1][k] += dp[1][j][k] + dp[2][j][k] * 24;
						ndp[0][j + 1][k] %= MOD;
					}
					if (k + 1 <= n) {
						ndp[1][j][k + 1] += dp[0][j][k] + dp[2][j][k] * 24;
						ndp[1][j][k + 1] %= MOD;
					}
					ndp[2][j][k] += dp[0][j][k] + dp[1][j][k] + dp[2][j][k] * 23;
					ndp[2][j][k] %= MOD;
				}
			}
		}
		dp = ndp;
	}

	vector<ll> sdp(n + 1);
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= n; j++) {
			sdp[i] += dp[0][i][j] + dp[1][i][j] + dp[2][i][j] * 24;
		}
		sdp[i] %= MOD;
	}

	for (int i = 0; i < 26; i++) {
		for (int k = a[i] + 1; k <= n; k++) {
			all -= sdp[k];
		}
	}

	for (int i = 0; i < 26; i++) {
		for (int j = i + 1; j < 26; j++) {
			for (int k = a[i] + 1; k <= n; k++) {
				for (int l = a[j] + 1; l + k <= n; l++) {
					all += (dp[0][k][l] + dp[1][k][l] + dp[2][k][l] * 24);
				}
			}
			all %= MOD;
		}
	}
	all %= MOD;

	if (all < 0) all += MOD;
	cout << all << endl;
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cout << fixed << setprecision(10);
	solve();
	return 0;
}
