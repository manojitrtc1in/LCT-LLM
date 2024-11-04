

 
 
 
  
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
  
 
   





 
using namespace std;
using namespace __gnu_pbds;
 



























 
typedef long long ll;
typedef long long LL;
typedef long double ld;
typedef unsigned long long ull;
typedef pair < long long , long long > pll;
typedef vector < ll > vll;
typedef vector < vll > vvll;
typedef vector < int > vi;
typedef vector < vi > vvi;
typedef vector < pii > vpii;
typedef vector < pll > vpll;
typedef pair < pii , pii > ppiipii;
typedef long double ld;
typedef map < int , int > mii;
typedef map < ll , ll > mll;
typedef set < int > si;
typedef set < ll > sll;
typedef set < ull > sull;
typedef set < string > ss;
typedef set < pii > spii;
typedef set < pll > spll;
typedef multiset < int > msi;
typedef map < pii , int > mpiii;
typedef map < int , pii > mipii;
typedef vector < pair < int , pair < int , int > > > vpipii;
template <typename T> using ordered_set = tree <T, null_type, less <T>, rb_tree_tag, tree_order_statistics_node_update>;
 
const int maxn = int(1.5 * 1e7);
const int inf = 1e9 + 7;
const ll ll_inf = 1e18 + 420;
const double eps = 1e-9;
const int N = 1e6 + 7;
const int MAX = 5e5 + 9;
const int MOD = 998244353;
const ld pi = 3.14159265359;
 
ll bpow(ll x, ll y,ll mod = MOD) {
    ll res = 1;
    x = x % mod;
    while(y > 0) {
        if(y & 1)
            res = (res * x) % mod;
        y = y >> 1;
        x = (x * x) % mod;
    }
    return res;
}
 
void Random(){
    unsigned int seed;
    asm("rdtsc" : "=A" (seed));
    srand(seed);
}
 
ll fact(ll n,int mod = 1e9 + 7){
    int fuc = 1;
    for(int i = 2;i <= n;++i){
        fuc = fuc * i % mod;
    }
    return fuc;
}
 
ll Cnk(ll n, ll r,int mod = 1e9 + 7){
    r = min(r,n - r);
    ll ans = 1;
    for(int i = n;i >= (n - r + 1);--i){
        ans = (ans * i) % mod;
    }
    for(int i = 1;i <= r;++i){
        ans = (ans * bpow(i,mod - 2,mod)) % mod;
    }
    return ans;
}

int n,m,ans[N];
pair < pii , int > a[N];
vector < ppiipii > v;
set < pii > s;

int main(){
    IOS;
    Random();
    

    

    cin >> n;
    for(int i = 1,x,y;i <= n;++i){
        cin >> x >> y;
        v.pb(mp(mp(x,inf),mp(y,i)));
    }
    cin >> m;
    for(int i = 1,x,y,z;i <= m;++i){
        cin >> a[i].f.f >> a[i].f.se >> a[i].se;
        v.pb(mp(mp(a[i].f.f,i),mp(a[i].f.se,0)));
    }
    sort(v.begin(),v.end());
    for(int i = 0;i < v.size();++i){
        if(v[i].f.se == inf){
            if(s.lwb(mp(v[i].se.f,0)) == s.end())
                continue;
            pii x = *s.lwb(mp(v[i].se.f,0));
            if(a[x.se].se == 1){
                s.erase(s.lwb(mp(v[i].se.f,0)));
            }
            a[x.se].se--;
            ans[v[i].se.se] = x.se;
        }
        else{
            s.insert(mp(v[i].se.f,v[i].f.se));
        }
    }
    bool q = 1;
    for(int i = 1;i <= n;++i){
        if(ans[i] == 0){
            q = 0;
        }
    }
    if(!q){
        cout << "NO";
        return 0;
    }
    cout << "YES" << en;
    for(int i = 1;i <= n;++i){
        cout << ans[i] << " ";
    }
}
 
 
 
 
 
 
 
 
 
 
 
 