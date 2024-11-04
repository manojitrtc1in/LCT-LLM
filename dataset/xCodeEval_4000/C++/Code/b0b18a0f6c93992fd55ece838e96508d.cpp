





#include <bits/stdc++.h>
#define ff                 first
#define ss                 second
#define ll                 long long
#define ii                 int, int
#define pii                pair<ii>
#define vi                 vector<int>
#define vvi                vector<vi>
#define si                 set<int>
#define vpii               vector<pii>
#define vs                 vector<string>
#define gi                 greater<int>
#define mii                map<ii>
#define maxheap            priority_queue<int>
#define minheap            priority_queue<int, vi, gi>
#define all(x)             x.begin(), x.end()
#define reverse(a)         reverse(all(a))
#define setbits(x)         __builtin_popcountll(x)
#define zrobits(x)         __builtin_ctzll(x)
#define gcd                __gcd
#define PI                 3.14159265358979323846264338
#define inf                LONG_LONG_MAX
#define pcs(x,y)           fixed << setprecision(y) << x
#define lower(s)           transform(all(s), s.begin(),::tolower)
#define upper(s)           transform(all(s), s.begin(),::toupper)
#define FI(i,x,y,inc)      for(int i = x; i < y; i += inc)
#define F(i,x)             FI(i,0,x,1)
#define RF(i,n)            for(int i=n-1;i>=0;i--)
using namespace std;


void swap(int &x, int &y) {int temp = x; x = y; y = temp;}

int XOR(int n)
{
  if (n % 4 == 0)
    return n;
  if (n % 4 == 1)
    return 1;
  if (n % 4 == 2)
    return n + 1;
  return 0;
}




int isPrime(int N){
 if(N<2 || (!(N&1) && N!=2))
      return 0;
  for(int i=3; i*i<=N; i+=2){
     if(!(N%i))
         return 0;
 }
  return 1;
}




void fillPrimes(vector<int>& prime, int high)
{
    bool ck[high + 1];
    memset(ck, true, sizeof(ck));
    ck[1] = false;
    ck[0] = false;
    for (int i = 2; (i * i) <= high; i++) {
        if (ck[i] == true) {
            for (int j = i * i; j <= high; j = j + i) {
                ck[j] = false;
            }
        }
   }
    for (int i = 2; i * i <= high; i++) {
        if (ck[i] == true) {
            prime.push_back(i);
        }
    }
}

vector<bool> segmentedSieve(int low, int high)
{
    vector<bool>prime(high-low+1,true);
    vector<int> chprime;
    fillPrimes(chprime, high);
    for (int i : chprime) {
        int lower = (low / i);     
        if (lower <= 1) {
            lower = i + i;
        }
        else if (low % i) {
            lower = (lower * i) + i;
        }
        else {
            lower = (lower * i);
        }
        for (int j = lower; j <= high; j = j + i) {
            prime[j - low] = false;
        }
    }
    return prime;
}




const double eps = 1e-7;
const ll N = 5e5 + 7, mod = 1e9 + 7;
ll POW(ll a, ll b, ll mod)
{
    a %= mod;
    ll r = 1;
    for(ll i = b; i > 0; i >>= 1)
    {
        if(i & 1)
            r = (r * a) % mod;
        a = (a * a) % mod;
    }
    return r;
}




ll f[N];
void init(){
  f[0] = 1;
  for(ll  i = 1; i < N; i++)
  {
      f[i] = (f[i - 1] * i) % mod;
  }
}
ll nCr(ll n, ll r)
{
    if(n < r)
        return 0;
    return f[n] * POW(f[n - r] * f[r], mod - 2, mod) % mod;
}
ll nPr(ll n, ll r)
{
    return nCr(n, r) * f[r] % mod;
}




vector<ll> getFactors(ll n)
{
    vector<ll>v;
    for (ll i=1; i<=sqrt(n); i++)
    {
        if (n%i == 0)
        {
            if (n/i == i) v.push_back(i);
            else {v.push_back(i); v.push_back(n/i);}    
        }
    }
    return v;
}




ll p=1e9+7;
ll modadd(ll a, ll b) {a = a % p; b = b % p; return (((a + b) % p) + p) % p;}
ll modmul(ll a, ll b) {a = a % p; b = b % p; return (((a * b) % p) + p) % p;}
ll modsub(ll a, ll b) {a = a % p; b = b % p; return (((a - b) % p) + p) % p;}





typedef unsigned long long ull;
typedef long double lld;
#define debug(x) cout << #x<<' '; _print(x); cout << endl;
void _print(ll t) {cout << t;}
void _print(int t) {cout << t;}
void _print(string t) {cout << t;}
void _print(char t) {cout << t;}
void _print(lld t) {cout << t;}
void _print(double t) {cout << t;}
void _print(ull t) {cout << t;}
template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cout << '{'; _print(p.ff); cout << ','; _print(p.ss); cout << '}';}
template <class T> void _print(vector <T> v) {cout << '['<<' '; for (T i : v) {_print(i); cout << ' ';} cout << ']';}
template <class T> void _print(set <T> v) {cout << '['<<' '; for (T i : v) {_print(i); cout << ' ';} cout << ']';}
template <class T> void _print(multiset <T> v) {cout << '['<<' '; for (T i : v) {_print(i); cout << ' ';} cout << ']';}
template <class T, class V> void _print(map <T, V> v) {cout << '['<<' '; for (auto i : v) {_print(i); cout << ' ';} cout << ']';}

















void solve() {


    ll n;
    cin>>n;
    ll a[n],b[n];
    F(i,n) cin>>a[i];
    F(i,n) cin>>b[i];
    ll f1=0;
    if(n==1){
        cout<<0<<endl; 
        return;
    }
    else{
    F(i,n){
        f1+=a[i]*a[i];
        f1+=b[i]*b[i];
    }
    f1*=(n-2);
    vector<vector<ll>>dp(n+1,vector<ll> (10001, 0));
    dp[0][0]=1;
    dp[1][a[0]]=1;
    dp[1][b[0]]=1;
    
    ll s=0;
    F(i,n){
        s+=a[i]; s+=b[i];
    }
    for(ll i=1;i<n+1;i++){
        for (ll j=1;j<10001;j++){
                if(j-a[i-1]>=0 && dp[i-1][j-a[i-1]]==1) dp[i][j]=1;
                if(j-b[i-1]>=0 && dp[i-1][j-b[i-1]]==1) dp[i][j]=1;
        }
    }
    ll ans=INT_MAX;
    F(i,10001){
        if(dp[n][i]==1) ans=min(ans,((s-i)*(s-i))+(i*i));
    }
    ans+=f1;
    cout<<ans<<endl;
    }



    return;


}




signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}
