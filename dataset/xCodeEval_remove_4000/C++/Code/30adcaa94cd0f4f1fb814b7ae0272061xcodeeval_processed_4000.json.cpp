

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

const int moveY[] = {1, 0, -1, -1, 0, 1};
const int moveX[] = {1, 1, 0, -1, -1, 0};























































































































      


























VI c(6), cost(6);
bool changed;
map <pair <int, int>, int> idx;
void dfs(int y, int x, int moves, int curCost) {
    if (idx.find({y, x}) != idx.end() && curCost < cost[idx[{y, x}]]) {
        changed = 1;
        cost[idx[{y, x}]] = curCost;
    }
    if (moves > 3) return;
    REP(i, 6) {
        int newY = y + moveY[i];
        int newX = x + moveX[i];
        dfs(newY, newX, moves + 1, curCost + c[i]);
    }
}
void go () {
    int a, b;
    changed = 1;
    cin >> a >> b;
    REP(i, 6) {
        cin >> c[i];
        cost[i] = c[i];
    }
    while(changed){
        changed = 0;
        dfs(0, 0, 0, 0);
        REP(i, 6) c[i] = cost[i];
    }
    int ans = 0;
    if (a > 0 && b > 0) {
        int x = min(abs(a), abs(b));
        a -= x;
        b -= x;
        ans += x * min(cost[0], cost[1] + cost[5]);
    }
    if (a < 0 && b < 0) {
        int x = min(abs(a), abs(b));
        a += x;
        b += x;
        ans += x * min(cost[3], cost[4] + cost[2]);
    }

    if (a > 0) ans += abs(a) * cost[5];
    if (b > 0) ans += abs(b) * cost[1];
    if (a < 0) ans += abs(a) * cost[2];
    if (b < 0) ans += abs(b) * cost[4];
    cout << ans << '\n';
}



signed main () {



    freopen("in.txt", "r", stdin);



    _upgrade
    if (1) {
        idx[{1, 1}] = 0;
        idx[{0, 1}] = 1;
        idx[{-1, 0}] = 2;
        idx[{-1, -1}] = 3;
        idx[{0, -1}] = 4;
        idx[{1, 0}] = 5;
    }
    int T = 1;
    cin >> T;
    while(T--) go();
    return 0;
}

