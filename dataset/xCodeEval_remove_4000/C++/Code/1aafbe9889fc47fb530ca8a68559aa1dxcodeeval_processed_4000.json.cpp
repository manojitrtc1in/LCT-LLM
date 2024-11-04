
   








   

   


 








































































































 






 
using namespace std;
using namespace __gnu_pbds;
   

























   
typedef pair < int, int > pii;
typedef pair < char, int > pci;
typedef pair < pii, int > ppii;
typedef pair < ll, ll > pll;
typedef pair < ull, ull > puu;
typedef pair < int, string > pis;
typedef pair < string, int > psi;
typedef map < int, int > mii;
typedef map < int, int > mii;
typedef map < int, char > mic;
typedef map < string, int > msi;
typedef map < string, string > mss;
typedef map < char, int > mci;
typedef map < char, ll > mcl;
typedef map < ll, ll > mll;
typedef map < pii, int > mpii;
typedef vector < int > vi;
typedef vector < vi > vvi;
typedef vector < char > vc;
typedef vector < ll > vll;
typedef vector < pii > vpii;
typedef vector < pll > vpll;
typedef vector < pis > vpis;
typedef map < int, vpii > mivpi;
typedef set < int > si;
typedef set < char > sc;
typedef set < ll > sll;
typedef set< pair < ull, ull > > spuu;
typedef set< pii > spii;
typedef priority_queue< ll > pqll;
   
const int N = 1e6+7;
const int M = 60;
const int MAXK = 1e5+3;
const int Candy = 1e6+3;
const int mod = 1e9 + 7;




const ll INF = 1e18;
const double PI = 3.1415926535897932384626433;
const ld EPS = 1e-12;
   
   
template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
   
template <typename T> int sgn(T val) {
    return (T(0) < val) - (val < T(0));
}
   
char getChar() { char c = 0; while (c <= ' ') cin >> c; return c; }
   
inline ll fast_pow(ll a, ll b){
    ll res = a, ret = 1;
    while(b>0){
        if(b%2)
            ret = (ret*res)%mod;
        res = (res*res)%mod;
        b/=2;
    }
    return ret;
}
   
inline ll fact(ll n){
    int f = 1;
    forl(i, 2, n) f = f * i % mod;
    return f;
}
   
 
 
   
inline ll factmod(ll n, ll p) {
    ll res = 1;
    while(n > 1){
        res = (res * ((n / p) % 2 ? p - 1 : 1)) % p;
        for(ll i = 2; i <= n % p; ++i)
            res = (res * i) % p;
        n /= p;
    }
    return res % p;
}
   
inline ll Cnk(ll n, ll r){
    r = min(r, n - r);
    ll ans = 1;
    ford(i, n, n - r + 1) ans = (ans * i) % mod;
    forl(i, 1, r) ans = (ans * fast_pow(i, mod - 2)) % mod;
    return ans;
}
 
ll n, m, a[N], f[N], mn1[N], mn2[N], ans[N];
pll p[N];

int find(int v){
    if(v == f[v]) return f[v];
    return f[v] = find(f[v]);
}

bool cmp(pll b, pll c){
    return a[(b.f - 1) * m + b.se] < a[(c.f - 1) * m + c.se];
}

int main(){
    SpeedForce
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> a[(i - 1) * m + j];
            p[(i - 1) * m + j].f = i;
            p[(i - 1) * m + j].se = j;
            f[(i - 1) * m + j] = (i - 1) * m + j;
        }
    }
    sort(p + 1, p + 1 + m * n, cmp);
    for(int i = 1; i <= m * n; i++){
        int x = p[i].f, y = p[i].se, px = find(mn1[x]), py = find(mn2[y]);
        int pos = (x - 1) * m + y;
        ans[pos] = max(ans[px] + (a[pos] > a[px]), ans[py] + (a[pos] > a[py]));
        if(a[pos] == a[px]) f[px] = pos;
        if(a[pos] == a[py]) f[py] = pos;
        mn1[x] = mn2[y] = pos;
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cout << ans[find((i - 1) * m + j)] << ' ';
        }
        cout << '\n';
    }
    return (!false && !true) || ((ll)((ll)(1713 + 2377 + 1464) * (ll)(1713 + 2377 + 1464) * (ll)(1713 + 2377 + 1464)) != (ll)(171323771464));
}