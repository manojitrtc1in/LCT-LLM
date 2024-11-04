




















































#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define MOD 1000000007
#define MOD1 998244353
#define INF 1000000007
#define nline "\n"
#define pb push_back
#define pf push_front
#define ppb pop_back
#define ff first
#define ss second
#define lb lower_bound
#define ub upper_bound
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vi vector<int>
#define vll vector<ll>
#define PI 3.1415927
#define set_bits __builtin_popcountll
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define Print(arr) for(i=0;i<arr.size();i++)cout<<arr[i]<<" "
#define for_all(arr) for(i=0;i<arr.size();i++)
#define no cout<<"NO\n";
#define yes cout<<"YES\n";
#define bob cout<<"Bob\n"
#define alice cout<<"Alice\n"
#define MAX 1000000006
#define I_love_her  true
#define I_hate_her  false
#define lineBreak cout<<endl;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#define MAXN 10000005
vector<ll>pw;


                                               



                                                                  

bool sortbysec(const pair<int,int> &a,
              const pair<int,int> &b)
{
    return (a.second < b.second);
}
bool my_sort(const pair<int,int> &a,
              const pair<int,int> &b)
{
    if(a.first<b.first)
        return true;
    else if(a.first>b.first)
        return false;
    else return(a.second > b.second);
}
ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
ll mod_sub(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}




int divisors(int n)
{
    int ans=0;
    for (int i=1; i<=sqrt(n); i++)
    {
        if (n%i == 0)
        {
            if (n/i == i)
                ans+=i;

            else
                ans+=(i+n/i);
        }
    }
    return ans;
}

void primeFactors(int n)
{
    while (n % 2 == 0)
    {
        cout << 2 << " ";
        n = n/2;
    }
    for (int i = 3; i <= sqrt(n); i = i + 2)
    {
        while (n % i == 0)
        {
            cout << i << " ";
            n = n/i;
        }
    }
    if (n > 2)
        cout << n << " ";
}
ll factorial(ll n)
{
     ll M = 998244353;

     ll f = 1;
    for (ll i = 1; i <= n; i++)
        f = (f*i) % M;  

                        

    return f;
}
bool isPrime(ll n)
{
    

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

void printS (multiset<int>myset)
{
    for (auto it = myset.begin(); it !=
                             myset.end(); ++it)
        cout << *it<< ' ' ;
    cout<<endl;
}
void printS (set<int>myset)
{
    for (auto it = myset.begin(); it !=
                             myset.end(); ++it)
        cout << *it<< ' ' ;
    cout<<endl;
}
void printS (set<char>myset)
{
    for (auto it = myset.begin(); it !=
                             myset.end(); ++it)
        cout << *it<< ' ' ;
    cout<<endl;
}
void printS (set<ll>myset)
{
    for (auto it = myset.begin(); it !=
                             myset.end(); ++it)
        cout << *it<< ' ' ;
    cout<<endl;
}
void printSS (set<string>myset)
{
    for (auto it = myset.begin(); it !=
                             myset.end(); ++it)
        cout << *it<< ' ' ;
    cout<<endl;
}
void printV (vector<int>v)
{
    for(int i=0;i<v.size();i++)
        cout<<v[i]<<" ";
    cout<<endl;
}
void printV (vector<ll>v)
{
    for(int i=0;i<v.size();i++)
        cout<<v[i]<<" ";
    cout<<endl;
}
void printMii (map<ll,ll>mp)
{
    for(auto it:mp)
        cout<<it.first<<" "<<it.second<<endl;
}
void printMii (map<int,int>mp)
{
    for(auto it:mp)
        cout<<it.first<<" "<<it.second<<endl;
}
void printVP (vector<pair<ll,ll>>v)
{
    for(ll i=0;i<v.size();i++)
        cout<<v[i].first<<" "<<v[i].second<<endl;
}
void printVP (vector<pair<int,int>>v)
{
    for(int i=0;i<v.size();i++)
        cout<<v[i].first<<" "<<v[i].second<<endl;
}
void printA (int v[],int n)
{
    for(int i=0;i<n;i++)
        cout<<v[i]<<" ";
    cout<<endl;
}
void printA (ll v[],ll n)
{
    for(ll i=0;i<n;i++)
        cout<<v[i]<<" ";
    cout<<endl;
}
mt19937 rng;
ll getRandomNumber(ll l, ll r)
{
    uniform_int_distribution<ll> dist(l, r);
    return dist(rng);
}
ll power(ll x, ll y, ll p)
{
    ll res = 1;     


    x = x % p; 

                


    if (x == 0) return 0; 


    while (y > 0)
    {
        

        if (y & 1)
            res = (res*x) % p;

        

        y = y>>1; 

        x = (x*x) % p;
    }
    return res;
}
ll power(ll x, ll y)
{
    ll res = 1;     


     

                


    if (x == 0) return 0; 


    while (y > 0)
    {
        

        if (y & 1)
            res = (res*x) ;

        

        y = y>>1; 

        x = (x*x) ;
    }
    return res;
}
bool isPal(string s)
{
    int i,n=s.size();
    for(i=0;i<n/2;i++)
        if(s[i]!=s[n-1-i])
            return false;
    return true;
}

void sieve(vector<ll>&v)       

{
    for (int i = 1; i < v.size(); ++i) {
        for (int j = i; j < v.size(); j += i)
            v[j]+=i;
    }
}
int dfs(int root,vector<bool>&vis,vector<int>adj[],vector<int>&val,int ev)
{
    

    

    vis[root]=true;
    int temp=val[root];
    for(auto it:adj[root])
    {
        if(!vis[it])
        {
            temp^=dfs(it,vis,adj,val,ev);
        }
    }
    if(temp==ev)
    {
        

        temp=0;
    }
    return temp;
}
bool isValid()
{
    return true;
}
bool comp(pair<ll,ll> &a,pair<ll,ll> &b){
    if(a.second==b.second){
        return a.first<b.first;
    }
    return a.second<b.second;
}
bool isBipartite(int V, vector<int> adj[])
{
    vector<int> col(V, -1);
    queue<pair<int, int> > q;
    for (int i = 0; i < V; i++) {
        if (col[i] == -1) {
            q.push({ i, 0 });
            col[i] = 0;
            while (!q.empty()) {
                pair<int, int> p = q.front();
                q.pop();
                int v = p.first;
                int c = p.second;
                for (int j : adj[v]) {
                    if (col[j] == c)
                        return 0;
                    if (col[j] == -1) {
                        col[j] = (c) ? 0 : 1;
                        q.push({ j, col[j] });
                    }
                }
            }
        }
    }
    return 1;
}
ll dfsc(ll curr,vector<bool>&vis,vector<pll>&r,vector<ll>adj[],ll *ans)
{
    vis[curr]=true;
    ll x=0;
    for(auto it:adj[curr])
    {
        if(!vis[it])
            x+=dfsc(it,vis,r,adj,ans);
    }
    if(x<r[curr].ff)
    {
        *ans=*ans+1;
        return r[curr].ss;
    }
    return min(x,r[curr].ss);
}
void solve()
{
    

    

    

    

    

    

    

    

    ll i,n,u,v;
    cin>>n;
    vector<ll>adj[n+1];
    for(i=2;i<=n;i++)
    {
        cin>>u;
        adj[i].pb(u);
        adj[u].pb(i);
    }
    vector<pll>r;
    r.pb({-1,-1});
    for(i=0;i<n;i++)
    {
        cin>>u>>v;
        r.pb({u,v});
    }
    ll ans=0;
    vector<bool>vis(n+1,false);
    ll x=dfsc(1,vis,r,adj,&ans);
    cout<<ans<<endl;
    return;
}
int main()
{
    ios::sync_with_stdio(false);
    

    

    

    

    

    

    

    

    

    

    

    int t;
    t=1;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        

        solve();
        cout<<endl;
        cout<<endl;
    }

    


    return 0;
}






































