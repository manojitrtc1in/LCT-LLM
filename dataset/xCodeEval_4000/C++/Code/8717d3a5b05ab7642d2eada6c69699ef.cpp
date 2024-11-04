















































































































































































#include <bits/stdc++.h>
using namespace std;



#define pb      push_back
#define mp      make_pair
#define sz(a) (int)a.size()
#define endl    '\n'
#define all(a)  a.begin(),a.end()
#define rep(i, n) for(int i = 0; i < int(n); i++)
#define drep(i, n) for(int i = int(n) - 1; i >= 0; i--)
#define Rep(i, a, b) for(int i = int(a); i <= int(b); i++)
#define dRep(i, a, b) for (int i = int(a); i >= int(b); i--)
#define mst(a, x) memset(a, x, sizeof a)

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> VI;
typedef vector<ll> VL;

const int MAX = 1e5 + 5;
const int MOD = 1e9 + 7;
const double PI = acos(-1.0);
const int INF = 0x3f3f3f3f;
const double eps = 1e-8;
const int Move[][3] = { { 0, 0 },{ 1, 0 },{ 0, 1 },{ 0, -1 },{ -1, 0 },{ 1, 1 },{ 1, -1 },{ -1, 1 },{ -1, -1 } };

inline ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }
inline ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }
inline ll sqr(ll x) { return x * x; }
ll qpow(ll a, ll t) { a %= MOD; ll b = 1; for (; t; t >>= 1, (a *= a) %= MOD) if (t & 1) (b *= a) %= MOD; return b; }
template <class T> inline bool chkmax(T& a, T b) { return (a < b) ? (a = b, 1) : 0; }
template <class T> inline bool chkmin(T& a, T b) { return (a > b) ? (a = b, 1) : 0; }



int v[1005], inc[1005];
ll dp[1005][10];

int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n; cin >> n;
    rep(i, n) {
        cin >> v[i];
        char s[10]; cin >> s;
        for (int j = strlen(s) - 1; j >= 0; j--) {
            if (s[j] == 'A') inc[i] |= 1;
            else if (s[j] == 'B') inc[i] |= 2;
            else if (s[j] == 'C') inc[i] |= 4;
        }
    }
    


    rep(i, n) Rep(j, 1, 7) dp[i][j] = 0x3f3f3f3f3f3f3f3f;

    dp[0][inc[0]] = v[0];

    rep(i, n - 1) {
        rep(j, 8) dp[i + 1][j] = dp[i][j];
        rep(j, 8) {
            chkmin(dp[i + 1][j | inc[i + 1]], dp[i][j] + v[i + 1]);
        }
    }
    if (dp[n - 1][7] != 0x3f3f3f3f3f3f3f3f) cout << dp[n - 1][7] << endl;
    else cout << -1 << endl;
}