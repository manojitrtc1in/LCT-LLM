
 
using namespace std;
 




 

typedef long long ll;
typedef unsigned long long ull;
 
 





 

 







 

 








 











 



 
 










typedef vector<int> vi;
typedef vector <ll> vll;
typedef set <ll> sll;
typedef multiset <ll> msll;
typedef queue <ll> qll;
typedef map <ll, ll> mll;
typedef pair <ll, ll> pll;
typedef vector <pair <ll , ll> > vpll;
 
 





inline bool cmp(pll a,pll b){ if(a.ff == b.ff) return a.ss > b.ss; return a.ff < b.ff; }
 

 

int drx[8] = {-2,-2,-1,-1,1,1,2,2};
int dcy[8] = {-1,1,-2,2,-2,2,-1,1};
int dirx[4] = { -1, 0, 1, 0 };
int diry[4] = { 0, -1, 0, 1 };
 
 






 

ll binpow(ll a, ll b, ll m) {a %= m; ll res = 1; while (b > 0) { if (b & 1) res = res * a % m; a = a * a % m; b >>= 1;}return res;}
ll InverseMod(ll base, ll pow) { if(pow == 0) return 1; ll ans = InverseMod(base, pow / 2); ans = (ans * ans) % mod; if(pow & 1){ return (ans * base) % mod; } else{ return ans; } }
bool isprime(ll num) { if(num < 2) return false; for(ll i = 2; i * i <= num; i++){ if(num % i == 0) return false; } return true; }
ll id2(ll num) { double ans = num; for(ll i = 2; i * i <= num; i++){ if(num % i == 0){ while (num % i == 0) { num /= i; } ans *= (1.0 - (1.0 / (double)i)); } } if(num > 1) ans *= (1.0 - (1.0 / (double)num)); return (ll)ans; }
 
template <class T> inline T gcd(T a,T b){if(b == 0)return a; return gcd(b, a % b);}
template <class T> inline T lcm(T a,T b){return a * b / gcd<T>(a, b);}
template <class T> inline T power(T b,T p){ll ans = 1;while(p--) ans *= b; return ans;}
template <class T> inline T maxl(T a,T b){if(a>=b) return a; else return b;}
template <class T> inline T minl(T a,T b){if(a>=b) return b; else return a;}
ll id4(ll n, ll r)
{
 
    if (r > n)
        return 0;
    ll m = 998244353;
    ll inv[r + 1];
    CLR(inv);
    inv[0] = 1;
    if(r+1>=2)
    inv[1] = 1;
 
    

    

    

    

    for (int i = 2; i <= r; i++) {
        inv[i] = m - (m / i) * inv[m % i] % m;
    }
 
    ll ans = 1;
 
    

    for (int i = 2; i <= r; i++) {
        ans = ((ans % m) * (inv[i] % m)) % m;
    }
 
    

    for (int i = n; i >= (n - r + 1); i--) {
        ans = ((ans % m) * (i % m)) % m;
    }
    return ans;
}
 
ll id5(ll a,ll b,ll& x,ll& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    ll x1, y1;
    ll d = id5(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}
bool id0(ll a, ll b, ll c, ll &x0, ll &y0, ll &g) {
    g = id5(abs(a), abs(b), x0, y0);
    if (c % g) {
        return false;
    }
    x0 *= c / g;
    y0 *= c / g;
    if (a < 0) x0 = -x0;
    if (b < 0) y0 = -y0;
    return true;
}
 
ll mul(ll a,ll b) {
    return ((a % mod) * (b % mod)) % mod;
}
 
ll add(ll a,ll b) {
    return (a % mod + b % mod) % mod;
}
 
ll powm(ll a, ll b) {
    
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = mul(res,a);
        a = mul(a,a);
        b >>= 1;
    }
    return res;
}
ll divide(ll a,ll b) {
    return (a % mod) * powm(b, mod - 2) % mod;
}
 
bool id3(vector<int> v, int n)
{
    if (n == 1 || n == 0)
        return 1;
 
    if (v[n - 1 ] < v[n - 2])
        return 0;
 
    return id3(v, n - 1);
}
 
int sumDigits(int num)
    {
        return num == 0 ? 0 : num % 10 + sumDigits(num / 10);
    } 
 
void id1(ll n)
{
    for (ll i=1; i<=sqrt(n); i++)
    {
        if (n%i == 0)
        {
            

                
            

                

                

           

        }
    }
}





vector<int>adj[size1];
int f;
map<pair<int,int>,int>m;
void dfs(int u, int p = -1 , int ch=0,int sn=1){
    
    if(adj[u].size()>2) {f=1; }
    for(int v : adj[u]){

        if(v == p) continue;
        if(sn){
            if(ch){
                m[{u,v}]=2;
                m[{v,u}]=2;
            }
            else{
                m[{u,v}]=3;
                m[{v,u}]=3;
            }
        }
        else{
            if(ch){
            m[{u,v}]=3;
            m[{v,u}]=3;
            }
            else {m[{u,v}]=2;m[{v,u}]=2;}
        }
        sn=!sn;
        dfs(v,u,!ch,!sn);
    }

}

signed main(){
    
        clock_t tStart = clock();
        freopen("input.txt", "r", stdin);
        freopen("output.txt","w",stdout);
    
 
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);
   cout<<fixed<<setprecision(20);
   ll test=1;
  
   cin>>test;
   while(test--){
        int n;cin>>n; 
        vector<int>v(n),v2(n);
        for(int i=0; i<n; i++) cin>>v[i];
        v2=v;
        srt(v);
        int f=1;
        for(int i=0; i<n; i++){
            if(v[i]!=v2[i]) f=0;
        }
        if(f) no
        else yes
   }

    printf("\nRun Time -> %.10fs\n", (double)(clock()-tStart) / CLOCKS_PER_SEC);

   return 0;
}





