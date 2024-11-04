
using namespace std;





























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
 

int id3(string&a) {
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
VVI id2(int n, int m) {
    VVI a(n, VI(m));
    REP(i, n) a[i] = readVI(m);
    return a;
}
VLL id4(ll n) {
    VLL a(n);
    REP(i, n) cin >> a[i];
    return a;
}
VVLL id0(ll n, ll m) {
    VVLL a(n, VLL(m));
    REP(i, n) a[i] = id4(m);
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
const ll INFF = id1;
const db EPS = 1e-9;
const db PI = acos(-1.0); 

const int moveX[] = {-1, 0, 1, 0};
const int moveY[] = {0, 1, 0, -1};























































































































      




























void go () {
    int n, m, cnt = 0;
    cin >> n >> m;
    VVI nums = id2(n, m), ans(n, VI(m, 0));
    VI cntRow(n, 0), cntCol(m, 0);
    VB row(n, 0), col(m, 0);
    REP(i, n)
    REP(j, m) {
        if (!nums[i][j]) continue;
        cntRow[i]++;
        cntCol[j]++;
        cnt++;
    }
    if (cnt == 0) {
        cout << "YES\n";
        for (auto el : ans) {
            for (auto num: el) cout << num << ' ';
            cout << '\n';
        }
        return;
    }
    REP(i, n) {
        if (cntRow[i] == m) {
            break;
        }
        if (i == n - 1) {
            cout << "NO\n";
            return;
        }
    }
    REP(i, m) {
        if (cntCol[i] == n) {
            break;
        }
        if (i == m - 1) {
            cout << "NO\n";
            return;
        }
    }
    REP(i, n)
    REP(j, m) {
        if (nums[i][j] && (cntRow[i] != m && cntCol[j] != n)) {
            cout << "NO\n";
            return;
        }
    }
    
    REP(i, n) 
    REP(j, m){
        if (cntRow[i] == m && cntCol[j] == n) ans[i][j] = 1;
    }
    cout << "YES\n";
    for (auto el : ans) {
        for (auto num: el) cout << num << ' ';
        cout << '\n';
    }
}

signed main () {



    freopen("in.txt", "r", stdin);



    _upgrade
    int T = 1;
    while(T--) go();
    return 0;
}
