
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















































































































































VVI graph(1e3 + 5, VI(1e3 + 5, 0));
void travel(int a, int b) {
    graph[a][b] = 1;
    

    

    

    

    

    REP(i, 4) {
        int x = a + moveX[i];
        int y = b + moveY[i];
        while (max(x, y) <= 1000 && min(x, y) >= 0) {
            if (graph[x][y] == 2) travel(x, y);
            graph[x][y] = 1;
            x += moveX[i];
            y += moveY[i];
        }
    } 
}

void go () {
    int n, a, b, ans = 0, cnt = 0;
    VB x(1e3 + 5, 0), y(1e3 + 5, 0);
    cin >> n;
    VPI nums;
    REP(i, n) {
        cin >> a >> b;
        nums.pb(mp(a, b));
        graph[a][b] = 2;
    }
    for (auto el : nums) {
        int a = el.ff, b = el.ss;
        if (graph[a][b] == 1) continue;
        travel(a, b);
        ans++;
    }
    cout << ans - 1 << '\n';
}







signed main () {



    freopen("in.txt", "r", stdin);



    _upgrade
    int T = 1;
    while(T--) go();
    return 0;
}


