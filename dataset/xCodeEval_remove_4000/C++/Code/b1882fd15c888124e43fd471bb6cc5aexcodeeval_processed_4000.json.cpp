
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


const int MOD = 998244353;
const int INF = INT_MAX;
const ll INFF = id1;
const d EPS = 1e-9;
const d PI = acos(-1.0); 

const int moveX[] = {-1, 0, 1, 0};
const int moveY[] = {0, 1, 0, -1};

























































































































































signed main () {



    freopen("in.txt", "r", stdin);



    _upgrade
    int n, m;
    cin >> n >> m;
    VI nums = readVI(n), tars = readVI(m), tmp;
    if (n == m) {
        if (nums == tars) n = 1;
        else n = 0;
        cout << n << '\n';
        return 0;
    }
    map <ll, int> posi;
    REP(i, n) {
        posi[nums[i]] = i;
    }

    int mini = nums[0];
    REP(i, n) mini = min(mini, nums[i]);
    if (mini < tars[0]) {
        cout << 0 << '\n';
        return 0;
    }
    if (m == 1) {
        if (mini == tars[0]) n = 1;
        else n = 0;
        cout << n << '\n';
        return 0;
    }
    for (auto el : tars) tmp.pb(posi[el]);
    tmp.pb(n);
    VPI sizes(m);
    REP(i, m) {
        int st = tmp[i], end = tmp[i + 1] - 1, size1, size2;
        size1 = size2 = 0;
        

        FOR(j, st, end) {
            if (nums[j] < tars[i]) break;
            size1++;
        }
        if (i > 0) st = tmp[i - 1] + 1;
        else st = 0;
        end = tmp[i];

        FORB(j, end, st) {
            if (nums[j] < tars[i]) break;
            size2++;
        }
        sizes[i] = mp(size1, size2);
    }
    ll ans = 1;
    if (sizes[0].ss != tmp[0] + 1 || sizes.back().ff + tmp[m - 1] != n || mini != tars[0]) {
        cout << "0\n";
        return 0;
    }
    REP(i, m - 1) {
        ll cur = sizes[i].ff + sizes[i + 1].ss;
        

        cur = cur - (tmp[i + 1] - tmp[i]) - 1;
        if (cur < 0) {
            

            cout << "0\n";
            return 0;
        }
        

        ans = ans * (cur + 1) % MOD;
    }
    cout << ans << '\n';
    return 0;
}


