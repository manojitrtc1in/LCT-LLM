#include <bits/stdc++.h>
using namespace std;



#define _upgrade ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define FOR(i, a, b) for (int i = a; i < b; i++)
#define FORB(i, a, b) for (int i = a - 1; i >= b; i--)
#define REP(i, a) for (int i = 0; i < a; i++)
#define REP1(i, a) for (int i = 1; i < a; i++)
#define REPB(i, a) for (int i = a - 1; i >= 0; i--)
#define ALL(A) A.begin(), A.end()
#define LLA(A) A.rbegin(), A.rend()
#define umap unordered_map
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define PQ priority_queue
#define Q queue

typedef long long ll;
typedef double d;
typedef unsigned uint;
typedef unsigned long long ull;
typedef unordered_map<int, int> umapII;


typedef vector<int> VI;
typedef vector<char> VC;
typedef vector<string> VS;
typedef vector<bool> VB;
typedef vector<umapII> VumapII;
typedef vector<ll> VLL;
typedef vector<VLL> VVLL;
typedef vector<d> VD;
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


const int MOD = int(1e9) + 7;
const int INF = INT_MAX;
const ll INFF = INT64_MAX;
const d EPS = 1e-9;
const d PI = acos(-1.0); 

const int moveX[] = {-1, 0, 1, 0};
const int moveY[] = {0, 1, 0, -1};







































































































































string res[] = {"Ayush", "Ashish"};

int solve(vector<vector<int> >& paths, int cur, int par) {
    if (paths[cur].size() == 1) return 1;
    int ans = 0;
    REP(i, paths[cur].size()) {
        if (paths[cur][i] == par) continue;
        ans += solve(paths, paths[cur][i], cur);
    }
    return ans + 1;
}


void go () {
    int n, m, par;
    cin >> n >> m;
    vector<vector<int> > paths(n + 1);
    REP(i, n - 1) {
        int a, b;
        cin >> a >> b;
        paths[a].pb(b);
        paths[b].pb(a);
    }
    par = -1;
    if (paths[m].size() <= 1) {
        cout << res[0] << '\n';
        return;
    }
    int val = solve(paths, m, par);
    cout << res[val % 2] << '\n';
}







signed main () {

#ifdef ONLINE_JUDGE
#else
    freopen("in.txt", "r", stdin);


#endif
    _upgrade
    int T;
    cin >> T;
    while(T--) go();
    return 0;
}



