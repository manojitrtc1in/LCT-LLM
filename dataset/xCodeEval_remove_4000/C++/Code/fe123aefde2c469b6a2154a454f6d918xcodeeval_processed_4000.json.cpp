


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
const int MOD = 998244353;
const int INF = INT_MAX;
const ll INFF = id1;
const db EPS = 1e-9;
const db PI = acos(-1.0); 




























































































































      
























VLL fact;
ll modInverse(ll a) {
    ll ans = 1, pow = MOD - 2;
    a = a % MOD; 
    while (pow > 0) { 
        if (pow & 1) ans = (ans * a) % MOD; 
        pow >>= 1;
        a = (a * a) % MOD; 
    } 
    return ans % MOD; 
}
ll add(ll n, ll r)  { 
    if (r > n) return 0;
    ll a = fact[n];
    ll b = (modInverse(fact[r])) % MOD;
    ll c = (modInverse(fact[n - r])) % MOD;

    a = (a * b) % MOD; 
    a = (a * c) % MOD;
    return a;
        

} 





void go () {
    ll n, m;
    cin >> n >> m;
    VVLL lamps = id0(n, 2); 

    set <ll> nums;
    umap <ll, int> index;
    for (auto el1 : lamps) 
    for (auto el : el1)  nums.insert(el);

    int idx = 0;
    for (auto el : nums) {
        index[el] = idx++;
    }
    n = idx;
    VLL dp(n + 10, 0), reduce(n + 10, 0);
    ll ans = 0;
    fact.resize(1e6);
    fact[1] = fact[0] = 1;
    REP1(i, 1e6) fact[i] = fact[i - 1] * i % MOD;
    
    for (auto el : lamps) {
        dp[index[el[0]]]++, dp[index[el[1]] + 1]--, reduce[index[el[1]] + 1]++;
    }
    REP(i, n - 1) {
        if (i > 0) dp[i] += dp[i - 1];
        if (dp[i] >= m) {
            

            ans = (MOD + add(dp[i], m) - add(dp[i] - reduce[i + 1], m) + ans) % MOD;
        }
    }
    ans = (MOD + ans + add(reduce[n], m)) % MOD;
    cout << ans << '\n';
}



signed main () {



    freopen("in.txt", "r", stdin);



    _upgrade
    int T = 1;
    while(T--) go();
    return 0;
}

