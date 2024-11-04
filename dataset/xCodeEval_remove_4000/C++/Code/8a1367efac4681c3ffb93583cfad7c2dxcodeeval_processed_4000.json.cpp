

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























































































































      






















VVI dp(1e5 + 5, VI(15, -1));


int n, m;

int myFind(int st, int j, int st1, VVI&nums) {
    if (st >= n || st1 >= n) return 0;
    if (nums[0][st] != nums[j][st1]) return 0;
    if (dp[nums[0][st]][j] != -1) return dp[nums[0][st]][j];
    return dp[nums[0][st]][j] = 1 + myFind(st + 1, j, st1 + 1, nums);
}

void go () {
    cin >> n >> m;
    VVI nums = id2(m, n), pos(m + 5, VI(n + 5));
    REP(j, m) {
        REP(i, n) {
            pos[j][nums[j][i]] = i;
        }
    }
    if (m == 1) {
        cout << (n * (n + 1)) / 2 << '\n';
        return;
    }
    int ans = 0;
    REP1 (i, n + 1) {
        int st = pos[0][i], Len = n;
        

        REP1 (j, m) {
            

            

            

            

            

            

            int len = myFind(st, j, pos[j][i], nums);
            Len = min(len, Len);
        }
        

        ans += (Len);
    }
    cout << ans << '\n';
}



signed main () {



    freopen("in.txt", "r", stdin);



    _upgrade
    int T = 1;
    while(T--) go();
    return 0;
}

