#include<bits/stdc++.h>
 
using namespace std;
 

#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
 

typedef long long ll;
typedef unsigned long long ull;
 
 
#define sci1(a) scanf("%d",&a)
#define sci2(a,b) scanf("%d %d",&a,&b)
#define sc1(a) scanf("%lld",&a)
#define sc2(a,b) scanf("%lld %lld",&a,&b)
#define sc3(a,b,c) scanf("%lld %lld %lld",&a,&b,&c)
 

 

#define for0(num) for(ll i = 0; i < num; i++)
#define for1(num) for(ll i = 1; i <= num; i++)
#define forr(num) for(ll i = num - 1; i >= 0; i--)
#define forin(arr, num) for(ll i = 0; i < num; i++) sc1(arr[i]);
#define vpnt(ans) for(ll i = 0; i < ans.size(); i++) cout << ans[i] << (i + 1 < ans.size() ? ' ' : '\n');
#define apnt(arr, num) for(ll i = 0; i < num; i++) cout << arr[i] << (i + 1 < num ? ' ' : '\n');
 

#define mx 1000000
#define mod 1000000007
#define PI acos(-1.0)
#define eps 1e-7
#define size1 1000010
#define INF 1e15


#define pb                push_back
#define ppb               pop_back
#define pf                push_front
#define ppf               pop_front
#define uniq(v)           (v).erase(unique(all(v)),(v).end())
#define sz(x)             (int)((x).size())
#define fr                first
#define sc                second
#define pii               pair<int,int>
#define REP(i,a,b)        for(int i=a;i<b;i++)
#define mem1(a)           memset(a,-1,sizeof(a))
#define mem0(a)           memset(a,0,sizeof(a))
#define ppc               __builtin_popcount
#define ppcll             __builtin_popcountll

 
#define pb push_back
#define ff first
#define ss second
#define mp make_pair
#define mem(name, value) memset(name, value, sizeof(name))

typedef vector<int> vi;
typedef vector <ll> vll;
typedef set <ll> sll;
typedef multiset <ll> msll;
typedef queue <ll> qll;
typedef map <ll, ll> mll;
typedef pair <ll, ll> pll;
typedef vector <pair <ll , ll> > vpll;

 

#define all(v) (v).begin(), (v).end()
#define rev(v) reverse(all(v))
#define srt(v) sort(all(v))
#define srtGreat(v) sort(all(v), greater<ll>())
inline bool cmp(pll a,pll b){ if(a.ss == b.ss) return a.ff < b.ff; return a.ss < b.ss; }
 

 

int drx[8] = {-2,-2,-1,-1,1,1,2,2};
int dcy[8] = {-1,1,-2,2,-2,2,-1,1};
int dirx[4] = { -1, 0, 1, 0 };
int diry[4] = { 0, -1, 0, 1 };
 
#define en cout << '\n';
#define no cout << "NO" << '\n';
#define yes cout << "YES" << '\n';
#define case cout << "Case " << t++ << ": ";
#define one cout << "-1"<<'\n';
#define ret return 0;

template <class T> inline T gcd(T a,T b){if(b == 0)return a; return gcd(b, a % b);}
template <class T> inline T lcm(T a,T b){return a * b / gcd<T>(a, b);}
template <class T> inline T power(T b,T p){ll ans = 1;while(p--) ans *= b; return ans;}


#define cerr cout
void __print(ll x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}
template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE


#define deb(x...)  _print(x)
#else
#define deb(x...)
#endif


mt19937_64 mt(chrono::steady_clock::now().time_since_epoch().count());
uniform_int_distribution<int> rng(0,1);


ll gcd(ll a, ll b){
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
ll extgcd(ll a,ll b,ll& x,ll& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    ll x1, y1;
    ll d = extgcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}
bool isPrime(ll n){
    if (n <= 1) 
        return false; 
    if (n <= 3) 
        return true; 
    if (n % 2 == 0 || n % 3 == 0) 
        return false; 
    for (ll i = 5; i * i <= n; i = i + 6) 
        if (n % i == 0 || n % (i + 2) == 0) 
            return false; 
    return true; 
}
bool isPowerOfTwo(ll n) { 
   if(n==0) 
   return false; 
   return (((ll)ceil(log2(n)) == (ll)floor(log2(n)))+1); 
}
 
ll powm(ll a,ll b) {
    ll res = 1;
    while (b) {
        if (b & 1)
            res = (res * a) % mod;
        a = (a * a) % mod;
        b /= 2;
    }
    return res;
}
ll divide(ll a,ll b) {
    return (a % mod) * powm(b, mod - 2) % mod;
}
ll mul(ll a,ll b) {
    return ((a % mod) * (b % mod)) % mod;
}
 
ll add(ll a,ll b) {
    return (a % mod + b % mod) % mod;
}
ll Totfun(ll n){
    ll z=n;
    if(n%2==0){
        while(n%2==0){
            n/=2;
        }
        z/=2;
    }
    for(ll i=3;i*i<=n;i+=2){
        if(isPrime(i)&&n%i==0){
          while(n%i==0){
            n/=i;
          }
        z-=z/i;  
        }
    }
    if(n>1){
        z-=z/n;
    }
    return z;
}
ll fact[mx];
ll nCr(ll n,ll r){
    if(r>n||r<0) return 0;
    ll z=fact[n];
    z=mul(z,powm(fact[n-r],mod-2));
    z=mul(z,powm(fact[r],mod-2));
    return z;
}


 

 int SieveOfEratosthenes(int n)
{
    

    

    

    

    

    

    bool prime[n + 1];
    memset(prime, true, sizeof(prime));
 
    for (int p = 2; p * p <= n; p++)
    {
        

        

        if (prime[p] == true)
        {
            

            

            

            

            

            

            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
    int ans;
    

    for (int p = 2; p <= n; p++)
        if (prime[p]){
            ans=p;
            break;
        }
    
    return ans;
}
 
int powerof(int n , int m){
    int count=0;
    while(n%m==0){
        count++;
        n=n/m;
    }
    return count;
}
ll factorial(ll n){
    if(n==0 || n==1) return 1;
    ll ans=n*factorial(n-1);
    return ans;
}
vector<ll> primetilln(ll n){
    vector<ll>v;
    for(ll i=2; i<=n; i++){
        if(isPrime(i)){
            v.pb(i);
        }
    }
    return v;
}
vector<ll> primeFactors(ll n)
{
    vector<ll>v;
    
    while (n % 2 == 0)
    {
        v.pb(2);
        n = n/2;
    }
 
    

    

    for (int i = 3; i <= sqrt(n); i = i + 2)
    {
        
        while (n % i == 0)
        {
            v.pb(i);
            n = n/i;
        }
    }
 
    
    if (n > 2)
        v.pb(n);

    return v;
}
int balancedBTs(int h) {
    

    ll dp[h + 1]; 
    

    dp[0] = dp[1] = 1; 
    for(int i = 2; i <= h; i++) { 
        dp[i] = (dp[i - 1] * ((2 * dp [i - 2])%mod + dp[i - 1])%mod) % mod; 
    } 
    return dp[h];
}

bool ispal(string s){
    bool flag=true;
    int n=s.size();
    for(int i=0; i<n; i++){
        if(s[i]!=s[n-1-i]) {
            flag=false;
            break;
        } 
    }
    return flag;
}



int min(vector<int> a, int b){
    int as=a.size();
    return min(as,b);
}

void addedge(vector<int> vec[], int u, int v)
{
    vec[u].push_back(v);
    vec[v].push_back(u);
}
int binomialCoeff(int n, int k)
{
    

    if (k > n)
        return 0;
    if (k == 0 || k == n)
        return 1;

    

    return binomialCoeff(n - 1, k - 1)
           + binomialCoeff(n - 1, k);
}




bool arraySortedOrNot(int arr[], int n)
{
    if (n == 1 || n == 0)
        return 1;

    if (arr[n ] < arr[n - 1])
        return 0;

    return arraySortedOrNot(arr, n - 1);
}

int main(){
    #ifndef ONLINE_JUDGE
        clock_t tStart = clock();
        freopen("input.txt", "r", stdin);
        freopen("output.txt","w",stdout);
    #endif
 
   ios_base::sync_with_stdio(false); 
   cin.tie(NULL);
   cout.tie(NULL);
   cout<<fixed<<setprecision(20);
   
   int test=1;
   cin>>test; 
   
   while(test--){
       int n;
       cin>>n;
       int v[n+1];
       for(int i=1; i<=n; i++) cin>>v[i];
       if(arraySortedOrNot(v,n)){
           cout<<0;
           en
        }
        else{
       
        for(int i=1;i<=1000000;i++){
            if(i%2==1){
                for(int j=1;j<n-1; j+=2 ){
                    if(v[j]>v[j+1]){
                        int temp=v[j];
                        v[j]=v[j+1];
                        v[j+1]=temp;
                    }
                }
            }
            else{
                for(int j=2;j<n; j+=2 ){
                    if(v[j]>v[j+1]){
                        int temp=v[j];
                        v[j]=v[j+1];
                        v[j+1]=temp;
                    }
                }
            }
        
            if(arraySortedOrNot(v,n)){
                cout<<i;
                en
                break;
            }
        }
        }
	}
   
#ifndef ONLINE_JUDGE
    printf("\nRun Time -> %.10fs\n", (double)(clock() - tStart) / CLOCKS_PER_SEC);
#endif
   return 0;
}
