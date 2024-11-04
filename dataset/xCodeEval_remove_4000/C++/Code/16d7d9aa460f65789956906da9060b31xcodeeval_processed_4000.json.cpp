
using namespace std;



















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
VVI id2(int n, int m) {
    VVI a(n, VI(m));
    REP(i, n) a[i] = readVI(m);
    return a;
}
VLL id3(ll n) {
    VLL a(n);
    REP(i, n) cin >> a[i];
    return a;
}
VVLL id0(ll n, ll m) {
    VVLL a(n, VLL(m));
    REP(i, n) a[i] = id3(m);
    return a;
}


const int MOD = int(1e9) + 7;
const int INF = INT_MAX;
const ll INFF = id1;
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



    freopen("in.txt", "r", stdin);



    _upgrade
    int T;
    cin >> T;
    while(T--) go();
    return 0;
}



