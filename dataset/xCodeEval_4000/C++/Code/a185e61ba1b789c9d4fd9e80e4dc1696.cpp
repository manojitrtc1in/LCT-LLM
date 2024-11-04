







                                                                                                                                                                      

#include<bits/stdc++.h>





using namespace std;
using namespace chrono;



#define IO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define MOD 1000000007
#define MOD1 998244353
#define INF 1e18
#define nl "\n"
#define nline "\n"
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define ff first
#define ss second
#define PI 3.141592653589793238462
#define set_bits __builtin_popcountll
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define vi  vector<int>
#define vvi vector<vector<int>>
#define vll vector<ll>
#define vvll vector<vector<ll>>
#define umap safe_map
#define uset unordered_set<ll>
#define google(tno) cout<<"Case #"<<tno<<": "
#define NO cout<<"NO";
#define YES cout<<"YES";
#define yes cout<<"yes";
#define no cout<<"no";
#define No cout<<"No";
#define Yes cout<<"Yes";
#define fr(a,b) for(ll i=a;i<b;i++)
#define fo(a,b) for(ll i=a;i<=b;i++)



#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        

        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;

#ifndef ONLINE_JUDGE
    #include "debug.h"
    #define debug(x) cerr << #x<<" "; _print(x); cerr << endl;
#else
    #define debug(x);
#endif




template<typename T,typename V>
using safe_map=unordered_map<T,V,custom_hash>;




template <class T> void cin1(vector <T>& v) {fo (1,sz(v)-1) { cin>>v[i];} }
template <class T> void cout1(vector <T>& v) {fo (1,sz(v)-1) { cout<<v[i]<<" ";} }
template <class T,class V> void amax(T& a,V b){a = a>=b ? a : b ;}
template <class T,class V> void amin(T& a,V b){a = a<b ? a : b ;}


template<typename T1, typename T2> 

istream& operator>>(istream &istream, pair<T1, T2> &p) { return (istream >> p.first >> p.second); }
 
template<typename T> 

istream& operator>>(istream &istream, vector<T> &v)
{
    for (auto &it : v)
        cin >> it;
    return istream;
}
 
template<typename T1, typename T2> 

ostream& operator<<(ostream &ostream, const pair<T1, T2> &p) { return (ostream << p.first << " " << p.second); }
template<typename T> 

ostream& operator<<(ostream &ostream, const vector<T> &c) { for (auto &it : c) cout << it << " "; return ostream; }
 


template <typename T>
void print(T &&t)  { cout << t << "\n"; }
template <typename T, typename... Args>
void print(T &&t, Args &&... args)
{
    cout << t << " ";
    print(forward<Args>(args)...);
}

template <typename T>
int32_t size_i(T &container) { return static_cast<int32_t>(container.size()); }





ll mminvprime(ll,ll);
ll expo(ll,ll,ll);
ll mod_mul(ll,ll,ll);
ll mod_div(ll,ll,ll);



ll harmonic_sum(ll n) {
    ll ans = 0;
    if (n == 1) {
      return 1;
  }
  ans += 1 + n;
  for (ll i = 2; i * i <= n; i++) {
      if (i != n / i) {
        ans += (i + n / i);
    } else {
        ans += i;
    }
    ll l = (n / i) + 1;
    ll h = (n / (i - 1)) - 1;
    if (l <= h) {
        ans += (h-l+1)*(i-1);
    }
 
}
return ans;
}
ll harmonic_util(ll x,ll y) {
    ll ans = 0,n=x;
    if (n == 1) {
      return 1;
  }
  ans += 1;
  for (ll i = 2; i * i <= n; i++) {
      if (i != n / i) {
        if(i>=2 && i<=y+1) ans += i;
        if(n/i>=2 && n/i<=y+1) ans+= n/i;
    } else {
        if(i>=2 && i<=y+1) ans += i;
    }
    ll l = (n / i) + 1;
    ll h = (n / (i - 1)) - 1;
    if (l <= h) {
        ans += (h-l+1)*(i-1);
    }
 
}
return ans;
}
 
ll nCrFermat(ll n, ll r,ll fact[], ll mod){


    if(n<r) return 0;


    if(r==0) return 1;
















    return (fact[n]*((mminvprime(fact[n-r],mod)*mminvprime(fact[r],mod))%mod))%mod;
}

void precision(int a) { cout << setprecision(a) << fixed; }
vector<ll> sosq(ll n){
    ll chk = n*n;
    unordered_set<ll> s;
    vector<ll> res;
    for(ll i=1;i<n;i++){
        s.insert(i*i);
        if(s.find(chk-i*i)!=s.end()){
            res.pb(sqrt(chk-i*i));
            res.pb(i);
            return res;
        }
    }
    return res;
}
bool nc(string a,string b){
    if(a.length()==b.length()) return (a.compare(b)>=0);
    return a.length()>b.length();
}
string maxnum(string a, string b){
    vector<ll> v;
    for(ll i=0;i<a.length();i++) v.pb(a[i]-'0');
        for(ll i=0;i<b.length();i++) v.pb(b[i]-'0');
            sort(v.rbegin(),v.rend());
        string res="";
        for(ll i=0;i<v.size();i++) res+=(v[i]+'0');
            return res;
    }


    char retrand(char a, char b){
        if(a==b) return (a=='z')?'y':(char)a+1;
        else if(a==b+1){
            return (a=='z')?'x':(char)a+1;
        }else if(b==a+1) return (b=='z')?'x':(char)b+1;
        else return (char)((a+b)/2);
    }
ll mod =1e9+7;
ll modp=998244353;
    ll getqb(ll n){
        ll f=0,c=0;
        while(n>0){
            f+=((n&1)*expo(10,c,mod));
            n>>=1;
            ++c;
        }
        return f;
    }


    ll po2(ll n){
        ll c=0;
        while(n>1){
            n>>=1;
            ++c;
        }
        return c;
    }
    ll ncr(ll n, ll r, ll m){
        r=min(n-r,r);
        if(r==0) return 1;
        return mod_div(mod_mul(n-r+1,ncr(n,r-1,m),m),r,m);
    }
    ll get(vector<ll>&p,ll a){
        return p[a]=((p[a]==a)?a:get(p,p[a]));
    }
void topoSort(ll i, set<ll> adj[], vector<ll>&vis, stack<ll>&st){
    vis[i]=1;
    for(auto x:adj[i]){
        if(!vis[x]) topoSort(x,adj,vis,st);
    }
    st.push(i);
}

void getScc(ll i, set<ll> adj[] ,vector<ll>&vis, set<ll>&s){
    

    

    

    

    vis[i]=1;
    for(auto x:adj[i]){
        if(!vis[x]) getScc(x,adj,vis,s);
    }
    s.insert(i);
}
class Histogram{
public:
    vector<ll> hist;
  vector<ll> nextSmallerElements(vector<ll>&a, ll&n){
        vector<ll>  nse(n,n);
        stack<ll> st;
        for(ll i=0;i<n;i++){
            if(st.empty()) st.push(i);
            else{
                if(a[i]>a[st.top()]){
                    st.push(i);
                }else{
                    while(!st.empty()&&a[i]<=a[st.top()]){
                        nse[st.top()] = i;
                        st.pop();
                    }
                    st.push(i);
                }
            }
        }
        return nse;
    }
    vector<ll> nextGreaterElements(vector<ll>&a, ll&n){
        vector<ll>  nge(n,n);
        stack<ll> st;
        for(ll i=0;i<n;i++){
            if(st.empty()) st.push(i);
            else{
                if(a[i]<a[st.top()]){
                    st.push(i);
                }else{
                    while(!st.empty()&&a[i]>=a[st.top()]){
                        nge[st.top()] = i;
                        st.pop();
                    }
                    st.push(i);
                }
            }
        }
        return nge;
    }
       vector<ll> previousSmallerElements(vector<ll>&a, ll&n){
        vector<ll>  pse(n,-1);
        stack<ll> st;
        for(ll i=n-1;i>=0;i--){
            if(st.empty()) st.push(i);
            else{
                if(a[i]>a[st.top()]){
                    st.push(i);
                }else{
                    while(!st.empty()&&a[i]<=a[st.top()]){
                        pse[st.top()] = i;
                        st.pop();
                    }
                    st.push(i);
                }
            }
        }
        return pse;
    }
    vector<ll> previousGreaterElements(vector<ll>&a, ll&n){
        vector<ll>  pse(n,-1);
        stack<ll> st;
        for(ll i=n-1;i>=0;i--){
            if(st.empty()) st.push(i);
            else{
                if(a[i]<=a[st.top()]){
                    st.push(i);
                }else{
                    while(!st.empty()&&a[i]>a[st.top()]){
                        pse[st.top()] = i;
                        st.pop();
                    }
                    st.push(i);
                }
            }
        }
        return pse;
    }
    ll maxAreaHistogram(vector<ll>&a, ll&n){
        vector<ll> nse(n), pse(n);
        nse = nextSmallerElements(a,n);
        pse = previousSmallerElements(a,n);
        ll maxArea = 0;
        for(ll i=0;i<n;i++){
            maxArea = max(maxArea, (nse[i]-pse[i]-1)*a[i]);
        }
        return maxArea;
    }
};
void bip(ll i , vector<pair<ll , ll>> adj[] , vector<ll> &vis , vector<ll> &clr , ll &cnt){
    ++cnt;
    vis[i] = 1;
    for(auto &x : adj[i]){
        if(!vis[x.ff])
            bip(x.ff , adj , vis , clr , cnt);
    }
}

bool kmp(string &a,string &b)
{
    vll pre(b.size());
 
    ll i=1,j=0;
 
    while(i<b.size())
    {
        if(b[i]==b[j])
        {
            j++;
            pre[i++] = j;
        }else
        {
            if(j!=0)
            {
                j = pre[j-1];
            }else
            {
                pre[i++] = 0;
            }
        }
    }
 
    i=0;
    j=0;
 
    while(i<a.size())
    {
        if(a[i]==b[j])
        {
            i++,j++;
        }else
        {
            if(j!=0)
            {
                j = pre[j-1];
            }else
            {
                i++;
            }
        }
 
        if(j==b.size())
        {
            return 1;
        }
    }
 
    return 0;
}

class dsu
{
    vector<int> rank,parent;
     
    public:

    int distinctcomponents;
    
    dsu(int n)
    {
        distinctcomponents = n;
        rank.resize(n+1);
        parent.resize(n+1);
        iota(begin(parent),end(parent),0);
    }
    
    bool unioner(int a,int b)
    {
        a = findparent(a);
        b = findparent(b);
        
        if(a==b)
            return 0;
        
        distinctcomponents--;
        
        if(rank[a]>=rank[b])
        {
            if(rank[a]==rank[b])
                rank[a]++;

            parent[b]=a;
        }else if(rank[a]<rank[b])
        {
            parent[a]=b;
        }
        
        return 1;
    }
    
    int findparent(int a)
    {
        if(parent[a]==a)
            return a;
        
        return parent[a] = findparent(parent[a]);
    }
    
    bool isSingle()
    {
        return distinctcomponents==1;
    }
};

ll gcd(ll a, ll b) {if (b > a) {return gcd(b, a);} if (b == 0) {return a;} return gcd(b, a % b);}
ll expo(ll a, ll b, ll mod) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
void extendgcd(ll a, ll b, ll*v) {if (b == 0) {v[0] = 1; v[1] = 0; v[2] = a; return ;} extendgcd(b, a % b, v); ll x = v[1]; v[1] = v[0] - v[1] * (a / b); v[0] = x; return;} 

ll mminv(ll a, ll b) {ll arr[3]; extendgcd(a, b, arr); return arr[0];} 

ll mminvprime(ll a, ll b) {return expo(a, b - 2, b);}
bool revsort(ll a, ll b) {return a > b;}
void swap(int &x, int &y) {int temp = x; x = y; y = temp;}
ll combination(ll n, ll r, ll m, ll *fact, ll *ifact) {ll val1 = fact[n]; ll val2 = ifact[n - r]; ll val3 = ifact[r]; return (((val1 * val2) % m) * val3) % m;}
vector<ll> sieve(int n) {int*arr = new int[n + 1](); vector<ll> vect; for (int i = 2; i <= n; i++)if (arr[i] == 0) {vect.push_back(i); for (int j = 2 * i; j <= n; j += i)arr[j] = 1;} return vect;}
ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
ll mod_sub(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
ll mod_div(ll a, ll b, ll m) {a = a % m; b = b % m; return (mod_mul(a, mminvprime(b, m), m) + m) % m;}  

ll phin(ll n) {ll number = n; if (n % 2 == 0) {number /= 2; while (n % 2 == 0) n /= 2;} for (ll i = 3; i <= sqrt(n); i += 2) {if (n % i == 0) {while (n % i == 0)n /= i; number = (number / i * (i - 1));}} if (n > 1)number = (number / n * (n - 1)) ; return number;} 

vll prefixSum(vll &A){vll res(A.size());res[0]=A[0];for(int i=1;i<A.size();i++){res[i]=A[i]+res[i-1];} return res;}


ll dp[2010][2010];

ll solve(ll l,ll r,vll& a)
{
    if(l==r)
    {
        return 0;
    }
    
    if(l+1==r)
    {
        return a[r] - a[l];
    }
    
    if(dp[l][r]!=-1)
        return dp[l][r];
        
    return dp[l][r] = a[r] - a[l] + min(solve(l+1,r,a),solve(l,r-1,a));
}

void solve() {
    
    ll n;
    cin>>n;
    
    vll a(n);
    cin>>a;
    
    memset(dp,-1,sizeof(dp));
    sort(all(a));
    
    cout<<solve(0,n-1,a);
    

    
}


int32_t main() {
#ifndef ONLINE_JUDGE
    freopen("Error.txt", "w", stderr);
#endif
    IO
    auto start1 = high_resolution_clock::now();
    ll t=1LL;
    


    while(t--)
    {
        solve();
        cout<<'\n';
    }
    auto stop1 = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop1 - start1);
#ifndef ONLINE_JUDGE
    cerr << "Time: " << duration . count() / 1000 << endl;
#endif

    return 0;   
}