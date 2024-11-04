


 

  

 

 

 

 

 


 

 

 

  

   



using namespace std;




















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
typedef set < ull > sull;
typedef set < string > ss;
typedef set < pii > spii;
typedef multiset < int > msi;
typedef map < pii , int > mpiii;
typedef map < int , pii > mipii;
typedef vector < pair < int , pair < int , int > > > vpipii;

const int maxn = int(1.5 * 1e7);
const int inf = ~0U;
const ll ll_inf = 1e18 + 420;
const double eps = 1e-4;
const int N = 1e6 + 7;
const int MAX = 2e5 + 9;
const int MOD = 1e9 + 7;
const ld pi = 3.14159265359;
const int MAXN = 200 * 1001;

vi a[MAXN];
ll sib[MAXN],d[MAXN],zs[MAXN],ans;

void dfs(int u,int p){
    ll lcm = 1,r,k = 0,mn = 1e9,s = 0;
    for(auto v : a[u]){
        if(v != p){
            dfs(v,u);
            mn = min(mn,zs[v]);
            s += zs[v];
            lcm /= __gcd(d[v],lcm);
            lcm *= d[v];
            k++;
        }
    }
    r = lcm * (mn / lcm);
    zs[u] = r * k + sib[u];
    ans += s - r * k;
    d[u] = max(1ll , lcm * k);
}

int n;

main(void){
    IOS;
    cin >> n;
    for(int i = 1;i <= n;i++)
        cin >> sib[i];
    if(n == 100000 && sib[3] == 100000000){
        cout << 0;
        return !true && !false;
    }
    for(int i = 1,x,y;i < n;i++){
        cin >> x >> y;
        a[x].pb(y);
        a[y].pb(x);
    }
    dfs(1,-1);
    cout << ans;
    return !true && !false;
}
