

 
 
 
  
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
  
 
   





 
using namespace std;
using namespace __gnu_pbds;
 


























 
typedef long long ll;
typedef long long LL;
typedef unsigned long long ull;
typedef pair < long long , long long > pll;
typedef vector < ll > vll;
typedef vector < vll > vvll;
typedef vector < int > vi;
typedef vector < vi > vvi;
typedef vector < pii > vpii;
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
typedef tree<int, null_type,less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
 
const int maxn = 4e3 + 100;
const int inf = 1e9 + 7;
const ll ll_inf = 1e18 + 420;
const double eps = 1e-4;
const int N = 1e6 + 7;
const int MAX = 2e5 + 9;
const int MOD = 1e9 + 7;
const ld pi = 3.14159265359;
 
ll bpow(int a, int b,int mod = 1e9 + 7){
    ll res = a, ret = 1;
    while(b > 0){
        if(b % 2)
            ret = (ret * res) % mod;
        res = (res * res) % mod;
        b /= 2;
    }
    return ret % mod;
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
        ans = (ans * bpow(i,mod - 2)) % mod;
    }
    return ans;
}
 
int n,p,q,ans[N],mx,dp[2][maxn][maxn],c[MAX],h[MAX],t[MAX],a[MAX],b[MAX],sz[MAX],cnt[MAX];
vi ma[MAX],v[MAX];
 
stack < int > st[2];
 
void add(int id,int num){
    sz[num]++;
    st[num].push(id);
    

    

    for(int w = 4000;w >= 0;--w){
        dp[num][sz[num]][w] = dp[num][sz[num] - 1][w];
    }
    

    for(int w = 4000 - c[id];w >= 0;--w){
        dp[num][sz[num]][w + c[id]] = max(dp[num][sz[num]][w + c[id]],dp[num][sz[num] - 1][w] + h[id]);
    }
    for(int w = 1;w <= 4000;++w){
        dp[num][sz[num]][w] = max(dp[num][sz[num]][w],dp[num][sz[num]][w - 1]);
    }
}
 
void del(){
    if(sz[1] == 0){
        while(sz[0] > 1){
            add(st[0].top(),1);
            st[0].pop();
            sz[0]--;
        }
        st[0].pop();
        sz[0]--;
    }
    else{
        st[1].pop();
        sz[1]--;
    }
}
 
int main(){
    IOS;
    Random();
    

    

    cin >> n >> p;
    for(int i = 1;i <= n;++i){
        cin >> c[i] >> h[i] >> t[i];
        cnt[t[i] + p]++;
        v[t[i]].pb(i);
    }
    cin >> q;
    for(int i = 1;i <= q;++i){
        cin >> a[i] >> b[i];
        mx = max(mx,a[i]);
        ma[a[i]].pb(i);
    }
    for(int i = 1;i <= min(p,mx);++i){
        

        for(int to : v[i]){
            

            add(to,0);
        }
        

        for(int to : ma[i]){
            if(sz[1] != 0){
                int mn = 0;
                for(int j = 0;j <= b[to];++j){
                    mn = max(mn,dp[0][sz[0]][j] + dp[1][sz[1]][b[to] - j]);
                }
                ans[to] = mn;
            }
            else{
                ans[to] = dp[0][sz[0]][b[to]];
            }
        }
    }
    

    for(int i = min(mx,p) + 1;i <= mx;++i){
        for(int to : v[i]){
            

            add(to,0);
        }
        for(int h = 1;h <= cnt[i];++h)
            del();
        for(int to : ma[i]){
            if(sz[1] != 0){
                int mn = 0;
                for(int j = 0;j <= b[to];++j){
                    

                    

                    

                    mn = max(mn,dp[0][sz[0]][j] + dp[1][sz[1]][b[to] - j]);
                }
                ans[to] = mn;
            }
            else{
                ans[to] = dp[0][sz[0]][b[to]];
            }
        }
    }
    for(int i = 1;i <= q;++i){
        cout << ans[i] << en;
    }
}
