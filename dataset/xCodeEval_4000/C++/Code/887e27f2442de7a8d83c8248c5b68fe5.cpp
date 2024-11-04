#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include <algorithm>
#define FAST                      \
ios_base::sync_with_stdio(0); \
cin.tie(0);                   \
cout.tie(0)
#define pb push_back
#define fixx(n) fixed << setprecision(n)
#define ff first
#define MAXN   100001
#define pii pair<int, int>
#define INF 1e18
#define ss second
#define PI 3.14159265358979323846
#define ll long long int
#define ain(a,n) for(ll i=0;i<(n);++i)  cin>>(a)[i];
using namespace std;
using namespace __gnu_pbds;


#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
int spf[MAXN];


typedef unsigned long long ull;
typedef long double lld;
typedef tree<pair<ll,ll>, null_type, less<pair<ll,ll>>, rb_tree_tag, tree_order_statistics_node_update > pbds; 

typedef tree<ll, null_type, greater_equal<ll>, rb_tree_tag, tree_order_statistics_node_update > pbdsg; 

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x<<" "; _print(x); cerr << endl;
#else
#define debug(x);
#endif

void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]"<<endl;}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(unordered_set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
void _print(pbds v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
void _print(pbdsg v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}


const vector<pair<ll,ll>> coords{{1,0},{0,1},{0,-1},{-1,0}};
void sieve()
{
    spf[1] = 1;
    for (int i=2; i<MAXN; i++)
        spf[i] = i;
    for (int i=4; i<MAXN; i+=2)
        spf[i] = 2;

    for (int i=3; i*i<MAXN; i++)
    {
        if (spf[i] == i)
        {
            for (int j=i*i; j<MAXN; j+=i)
                if (spf[j]==j)
                    spf[j] = i;
            }
        }
    }
    ll lis(vector<ll> const& a) {
        ll n = a.size();

        vector<ll> d(n+1, INF);
        d[0] = -INF;

        for (ll i = 0; i < n; i++) {
            ll j = upper_bound(d.begin(), d.end(), a[i]) - d.begin();
            if (d[j-1] <= a[i] && a[i] <= d[j])
                d[j] = a[i];
        }

        ll ans = 0;
        for (ll i = 0; i <= n; i++) {
            if (d[i] < INF)
                ans = i;
        }
        return ans;
    }
    vector<ll> getFact(ll v,vector<ll>&pr)
    {
        vector<ll> ret;
        ll r = v;
        for(auto x:pr){
            if(x*x>v) break;
            while(r%x==0){ 
                ret.pb(x);
                r/=x;
            }
        }
        

        if(r>1) ret.pb(r);
        return ret;
    }
    ll gcd(ll a, ll b)
    {
        if (b > a)
        {
            return gcd(b, a);
        }
        if (b == 0)
        {
            return a;
        }
        return gcd(b, a % b);
    }
    ll expo(ll a, ll b, ll mod)
    {
        ll res = 1;
        while (b > 0)
        {
            if (b & 1)
                res = (res * a) % mod;
            a = (a * a) % mod;
            b = b >> 1;
        }
        return res;
    }
    void extendgcd(ll a, ll b, ll *v)
    {
        if (b == 0)
        {
            v[0] = 1;
            v[1] = 0;
            v[2] = a;
            return;
        }
        extendgcd(b, a % b, v);
        ll x = v[1];
        v[1] = v[0] - v[1] * (a / b);
        v[0] = x;
        return;
} 

ll mminv(ll a, ll b)
{
    ll arr[3];
    extendgcd(a, b, arr);
    return arr[0];
} 

ll mminvprime(ll a, ll b) { return expo(a, b - 2, b); }
bool revsort(ll a, ll b) { return a > b; }
void swap(int &x, int &y)
{
    int temp = x;
    x = y;
    y = temp;
}
ll combination(ll n, ll r, ll m, ll *fact, ll *ifact)
{
    ll val1 = fact[n];
    ll val2 = ifact[n - r];
    ll val3 = ifact[r];
    return (((val1 * val2) % m) * val3) % m;
}
void google(int t) { cout << "Case #" << t << ": "; }
vector<ll> sieve(ll n)
{
    ll *arr = new ll[n + 1]();
    vector<ll> vect;
    for (ll i = 2; i <= n; i++)
        if (arr[i] == 0)
        {
            vect.push_back(i);
            for (ll j = (i * i); j <= n; j += i)
                arr[j] = 1;
        }
        return vect;
    }
    set<ll> sieves(ll n)
    {
        ll *arr = new ll[n + 1]();
        set<ll> s;
        for (ll i = 2; i <= n; i++)
            if (arr[i] == 0)
            {
                s.insert(i);
                for (ll j = (i * i); j <= n; j += i)
                    arr[j] = 1;
            }
            return s;
        }
        ll mod_add(ll a, ll b, ll m)
        {
            a = a % m;
            b = b % m;
            return (((a + b) % m) + m) % m;
        }
        ll mod_mul(ll a, ll b, ll m)
        {
            a = a % m;
            b = b % m;
            return (((a * b) % m) + m) % m;
        }
        ll mod_sub(ll a, ll b, ll m)
        {
            a = a % m;
            b = b % m;
            return (((a - b) % m) + m) % m;
        }
        ll mod_div(ll a, ll b, ll m)
        {
            a = a % m;
            b = b % m;
            return (mod_mul(a, mminvprime(b, m), m) + m) % m;
} 

ll mod_inv(ll a, ll mod){
    return expo(a,mod-2,mod);
} 
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
















    return (fact[n]*((mod_inv(fact[n-r],mod)*mod_inv(fact[r],mod))%mod))%mod;
}
ll phin(ll n)
{
    ll number = n;
    if (n % 2 == 0)
    {
        number /= 2;
        while (n % 2 == 0)
            n /= 2;
    }
    for (ll i = 3; i <= sqrt(n); i += 2)
    {
        if (n % i == 0)
        {
            while (n % i == 0)
                n /= i;
            number = (number / i * (i - 1));
        }
    }
    if (n > 1)
        number = (number / n * (n - 1));
    return number;
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
    pair<ll,ll> getpar(pair<ll,ll> a, vector<vector<pair<ll,ll>>>&par){
        return par[a.ff][a.ss]=(par[a.ff][a.ss]==a)?a:getpar(par[a.ff][a.ss],par);
    }
    void unio(pair<ll,ll> a, pair<ll,ll> b, vector<vector<pair<ll,ll>>>&par, vector<vector<ll>>&rank){
        a=getpar(a,par);
        b=getpar(b,par);
        if(rank[a.ff][a.ss]==rank[b.ff][b.ss]) ++rank[a.ff][a.ss];
        if(rank[a.ff][a.ss]>rank[b.ff][b.ss]) par[a.ff][a.ss]=b;
        else par[b.ff][b.ss]=a;
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
  vector<int> nextSmallerElements(vector<int>&a, int&n){
        vector<int>  nse(n,n);
        stack<int> st;
        for(int i=0;i<n;i++){
            if(st.empty()) st.push(i);
            else{
                if(a[i]>=a[st.top()]){
                    st.push(i);
                }else{
                    while(!st.empty()&&a[i]<a[st.top()]){
                        nse[st.top()] = i;
                        st.pop();
                    }
                    st.push(i);
                }
            }
        }
        return nse;
    }
       vector<int> previousSmallerElements(vector<int>&a, int&n){
        vector<int>  pse(n,-1);
        stack<int> st;
        for(int i=n-1;i>=0;i--){
            if(st.empty()) st.push(i);
            else{
                if(a[i]>=a[st.top()]){
                    st.push(i);
                }else{
                    while(!st.empty()&&a[i]<a[st.top()]){
                        pse[st.top()] = i;
                        st.pop();
                    }
                    st.push(i);
                }
            }
        }
        return pse;
    }
    int maxAreaHistogram(vector<int>&a, int&n){
        vector<int> nse(n), pse(n);
        nse = nextSmallerElements(a,n);
        pse = previousSmallerElements(a,n);
        int maxArea = 0;
        for(int i=0;i<n;i++){
            maxArea = max(maxArea, (nse[i]-pse[i]-1)*a[i]);
        }
        return maxArea;
    }
};
void dfs(ll i, vector<ll> adj[], vector<ll>&vis,vector<ll>&fun,vector<ll>&dp,vector<ll>&lcmv){
   
}
int main()
{
        #ifndef ONLINE_JUDGE



    freopen("input.txt", "r", stdin);


freopen("Error.txt", "w", stderr);


    freopen("output.txt", "w", stdout);
 #endif


    FAST;












 

 

ll t,tn;
cin>>t;
tn = t;
while(t--){
    ll l,r,n,xo=0,xf=0,res=0;
    cin>>l>>r;
    n  = r - l + 1;
    vector<ll> a(n),xors(n),bits(20,0),bitsorg(20,0);
    ain(a,n);
    set<ll> all;
    sort(a.begin(),a.end());
    

     bool b = false;
    for(ll i=l;i<=r;i++){
        if(i!=a[i-l]){
            b=true;
            break;
        }
    }
   if(!b){
    cout<<0<<endl;
    goto label;
   }
    for(ll i=l;i<=r;i++){
        xo=(xo^i);
        xf=(xf^a[i-l]);
        all.insert(i);
    }
    

    
       for(auto x:a){
        ll c=0;
            while(x!=0){
                bits[c++] +=(x&1);
                x>>=1;
            }
       }
       for(ll i=l;i<=r;i++){
        ll x = i;
        ll c=0;
            while(x!=0){
                bits[c++] +=(x&1);
                x>>=1;
            }
       }
       for(ll i=0;i<20;i++){
        if(bits[i]!=bitsorg[i] && bits[i]+bitsorg[i]==n) res += (1<<i);
       }
       cout<<res<<endl;
        label:
        continue;
}
 

 

 

 

 

 

 

 

 

 

 

}