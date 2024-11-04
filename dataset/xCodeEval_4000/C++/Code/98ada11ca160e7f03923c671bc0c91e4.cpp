#include <bits/stdc++.h>
using namespace std;



#define _upgrade ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define FORB(i, a, b) for (int i = a; i >= b; i--)
#define REP(i, a) for (int i = 0; i < a; i++)
#define REP1(i, a) for (int i = 1; i < a; i++)
#define REPB(i, a) for (int i = a - 1; i >= 0; i--)
#define TRAV(a,x) for (auto& a: x)
#define ALL(A) A.begin(), A.end()
#define LLA(A) A.rbegin(), A.rend()
#define II <int, int>
#define Q queue
#define ff first
#define bk back()
#define ss second
#define rs resize
#define ins insert 
#define fr front() 
#define ts to_string
#define pb push_back
#define mp make_pair
#define lb lower_bound 
#define ub upper_bound 
#define PQ priority_queue
#define umap unordered_map
#define sz(x) (int)x.size()

typedef long long ll;
typedef double db;
typedef unsigned uint;
typedef unsigned long long ull;
typedef unordered_map<int, int> umapII;


typedef vector<int> VI;
typedef vector<char> VC;
typedef vector<string> VS;
typedef vector<bool> VB;
typedef vector<VB> VVB;
typedef vector<VVB> VVVB;
typedef vector<umapII> VumapII;
typedef vector<ll> VLL;
typedef vector<VLL> VVLL;
typedef vector<VVLL> VVVLL;
typedef vector<VVVLL> VVVVLL;
typedef vector<db> VD;
typedef set<int> SI;
typedef set<string> SS;
typedef map<int, int> MII;
typedef map<string, int> MSI;
typedef pair<int, int> PII;
typedef pair<ll, ll> PLL;
typedef vector<PII> VPI;
typedef vector<VPI> VVPI;
typedef vector<VI> VVI;
typedef vector<VVI> VVVI;
typedef vector<VVVI> VVVVI;
typedef vector<VVVVI> VVVVVI;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 

int strToInt(string&a) {
    stringstream x(a);
    int b;
    x >> b;
    return b;
}
void readI(int& a) {
    cin >> a;
}
void readI(int& a, int&b) {
    cin >> a >> b;
}
void readI(int& a, int&b, int&c) {
    cin >> a >> b >> c;
}
VI readVI(int n) {
    VI a(n);
    REP(i, n) cin >> a[i];
    return a;
}
VVI readVVI(int n, int m) {
    VVI a(n, VI(m));
    REP(i, n) a[i] = readVI(m);
    return a;
}
VLL readVLL(ll n) {
    VLL a(n);
    REP(i, n) cin >> a[i];
    return a;
}
VVLL readVVLL(ll n, ll m) {
    VVLL a(n, VLL(m));
    REP(i, n) a[i] = readVLL(m);
    return a;
}

void print(VI& a) {
    for (auto el : a) {
        cout << el << ' ';
    }
    cout << '\n';
}

void print(VI& a, int n) {
    int cnt = 0;
    for (auto el : a) {
        if (cnt++ == n) break;
        cout << el << ' ';
    }
    cout << '\n';
}
const int MOD = 1e9 + 7;
const int INF = INT_MAX;
const ll INFF = INT64_MAX;
const db EPS = 1e-9;
const db PI = acos(-1.0); 

const int moveX[] = {-1, 0, 1, 0};
const int moveY[] = {0, 1, 0, -1};























































































































      



























void go () {
    string s;
    ll n, strs = 1;
    cin >> n >> s;
    s = 'z' + s;
    VVLL dp(n + 5, VLL(3, 0));
    REP1(i, n + 1) {
        REP(k, 3) dp[i][k] = dp[i - 1][k];
        if (s[i] == '?') {
            dp[i][0] = (dp[i - 1][0] * 3 + strs) % MOD;
            dp[i][1] = (dp[i - 1][1] * 3 + dp[i - 1][0]) % MOD;
            dp[i][2] = (dp[i - 1][2] * 3 + dp[i - 1][1]) % MOD;
            strs = (strs * 3) % MOD;
        } else {
            int idx = s[i] - 'a';
            if (idx == 0) {
                dp[i][0] = (dp[i][0] + strs) % MOD;
            } else {
                dp[i][idx] = (dp[i][idx] + dp[i - 1][idx - 1]) % MOD;
            }
        }
        

    }
    

    

    

    

    cout << dp[n][2] % MOD << '\n';
}



signed main () {

#ifdef LOCAL_DEBUG
    freopen("in.txt", "r", stdin);


#endif
    _upgrade
    int T = 1;
    while(T--) go();
    return 0;
}

