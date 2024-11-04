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
    char b;
    REP(i, n) {
        cin >> b;
        a[i] = b - '0';
    }
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


const int MOD = int(1e9) + 7;
const int INF = INT_MAX;
const ll INFF = INT64_MAX;
const db EPS = 1e-9;
const db PI = acos(-1.0); 

const int moveX[] = {-1, 0, 1, 0};
const int moveY[] = {0, 1, 0, -1};























































































































      

























int n, m;
VVI nums;

void go () {
    cin >> n >> m;
    nums = readVVI(n, m + 2);
    reverse(ALL(nums));
    VVI pos(n, VI(2));
    REP(i, n) {
        int l = m + 1, r = 0;
        REP(j, m + 2) 
        if (nums[i][j]) {
            l = min(l, j);
            r = max(r, j);
        }
        pos[i][0] = m + 1 - l;
        pos[i][1] = r;
    }
    
    

    

    

    

    

    

    VVI dp(n, VI(2, 0)); 

    dp[0][0] = pos[0][1] * 2;
    dp[0][1] = m + 1;
    int h = 0;
    REP(i, n) {
        int sum = 0;
        REP(j, m + 2) sum += nums[i][j];
        if (sum) h = i;
    }
    if (h == 0) {
        cout << (pos[0][1]) << '\n';
        return;
    }
    REP1(i, h) {
        dp[i][0] = min(dp[i - 1][1] + 1 + m + 1, dp[i - 1][0] + 2 * pos[i][1] + 1);
        dp[i][1] = min(dp[i - 1][0] + 1 + m + 1, dp[i - 1][1] + 2 * pos[i][0] + 1);
    }
    dp[h][0] = min(dp[h - 1][1] + 1 + m + 1, dp[h - 1][0] + pos[h][1] + 1);
    dp[h][1] = min(dp[h - 1][0] + 1 + m + 1, dp[h - 1][1] + pos[h][0] + 1);
    

    

    

    

    

    cout << min(dp[h][0], dp[h][1]) << '\n';
}



signed main () {

#ifdef ONLINE_JUDGE
#else
    freopen("in.txt", "r", stdin);


#endif
    _upgrade
    int T = 1;
    while(T--) go();
    return 0;
}

