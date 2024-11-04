
   








   

   


 








































































































 

#pragma GCC optimize("O3")
#include<bits/stdc++.h>
#include <ext/pb_ds/detail/standard_policies.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace __gnu_pbds;
   
#define ll                  long long
#define ull                 unsigned long long
#define ld                  long double
#define f                   first
#define se                  second
#define SpeedForce          ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define sqr(x)              ((x)*(x))
#define forn(i, n)          for(ll i=0;i<n;++i)
#define forl(i, a, b)       for(ll i=(a);i<=(b);++i)
#define ford(i, a, b)       for(ll i=(a);i>=(b);--i)
#define forg(i, a, b, c)    for(ll i=(a);i<=(b);i += (c))
#define cno                 cout<<"NO";return 0;
#define cye                 cout<<"YES";return 0;
#define pb                  push_back
#define mp                  make_pair
#define fbo                 find_by_order
#define ofk                 order_of_key
#define all(a)              (a).begin(), (a).end()
#define pb1                 pop_back
#define sz(x)               ((int)(x).size())
#define fill(a, x)          memset(a, x, sizeof(a))
#define _read(x)            freopen(x, "r", stdin)
#define _write(x)           freopen(x, "w", stdout)
#define files(x)            _read(x ".in"); _write(x ".out")
#define y1                  qwertytrewq
   
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