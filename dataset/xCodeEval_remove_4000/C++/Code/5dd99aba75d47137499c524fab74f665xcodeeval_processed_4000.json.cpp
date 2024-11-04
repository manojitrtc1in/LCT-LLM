
   








   

   


 








































































































 






 
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

int n, m, k, d[N][2], a[N], id = N, id1;
vi g[N];
map < pii, bool > ma;

int main(){
    SpeedForce
    cin >> n >> m >> k;
    for(int i = 1; i <= k; i++) cin >> a[i], id = min(id, a[i]), id1 = max(id1, a[i]);
    for(int i = 1; i <= m; i++){
        int u, v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
        ma[{u, v}] = 1;
        ma[{v, u}] = 1;
    }
    fill(d, mod);
    d[1][0] = 0;
    set < int > q;
    q.insert(1);
    while(!q.empty()){
        int v = *q.begin();
        q.erase(q.begin());
        for(auto to: g[v]){
            if(d[v][0] + 1 < d[to][0]){
                q.erase(to);
                d[to][0] = d[v][0] + 1;
                q.insert(to);
            }
        }
    }
    int le = d[n][0];
    d[n][1] = 0;
    q.insert(n);
    while(!q.empty()){
        int v = *q.begin();
        q.erase(q.begin());
        for(auto to: g[v]){
            if(d[v][1] + 1 < d[to][1]){
                q.erase(to);
                d[to][1] = d[v][1] + 1;
                q.insert(to);
            }
        }
    }
    
    vector<pii> v;
    for(int i = 1; i <= k; i++){
        v.pb({d[a[i]][1], a[i]});
    }
    sort(all(v));
    int mx = 0;
    for(int i = 1; i <= k; i++){
        int x = lower_bound(all(v), mp(le - d[a[i]][0], 0)) - v.begin();
        x--;
        x = max(x, 0);
        x = v[x].se;
        if(x == a[i]) continue;
        mx = max(mx, min(d[a[i]][0] + 1 + d[x][1], d[x][0] + 1 + d[a[i]][1]));
        

        

    }
    cout << min(mx, le);
    return (!false && !true) || ((ll)((ll)(1713 + 2377 + 1464) * (ll)(1713 + 2377 + 1464) * (ll)(1713 + 2377 + 1464)) != (ll)(171323771464));
}