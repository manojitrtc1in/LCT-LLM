



















































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
#define PI 3.141592653589793238462
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
#define vpii vector<pii>
#define vpll vector<pll>

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


template<typename T> 

istream& operator>>(istream &istream, vector<T> &v){for (auto &it : v)cin >> it;return istream;}

void printS (multiset<ll>myset)
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
        cout << *it+1<< ' ' ;
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
        cout<<v[i]+1<<" ";
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
void printSP (set<pair<int,int>>v)
{
    for(auto it:v)
        cout<<it.first<<" "<<it.second<<endl;
}
void printA (int v[],int n)
{
    for(int i=0;i<n;i++)
        cout<<v[i]<<" ";
    cout<<endl;
}
void printP(pair<int,int>p)
{
    cout<<p.ff<<" "<<p.ss<<endl;
}
void printP(pair<ll,ll>p)
{
    cout<<p.ff<<" "<<p.ss<<endl;
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
int dist(int x1,int y1,int x2,int y2,vector<int>ps[])
{
    return (ps[x2][y2]-ps[x1-1][y2]-ps[x2][y1-1]+ps[x1-1][y1-1]);
}
void solve(int t)
{
    

    

    

    

    

    

    

    

    int n,i;
    cin>>n;
    vpii a(n),b(n),rev(n);
    map<pii,int>mp;
    map<pii,vi>ok;
    for(i=0;i<n;i++)
        cin>>a[i].ff>>a[i].ss,b[i]=a[i],mp[a[i]]=i,ok[a[i]].pb(i);
    sort(all(b));
    vi ans(n,-2);
    vpii mn(n);
    mn[0]={b[0].ss,0};
    for(i=1;i<n;i++)
    {
        mn[i]=mn[i-1];
        if(mn[i].ff>b[i].ss)
            mn[i]={b[i].ss,i};
    }
    for(i=0;i<n;i++)
    {
        pii curr=b[i];
        curr.ff--;curr.ss--;
        auto it=ub(all(b),curr)-b.begin();
        it--;
        if(it>-1 && mn[it].ff<=curr.ss)
            ans[mp[b[i]]]=mp[b[mn[it].ss]];
        else
        {
            curr={b[i].ss-1,b[i].ff-1};
            auto itr=ub(all(b),curr)-b.begin();
            itr--;
            if(itr>-1 && mn[itr].ff<=curr.ss)
                ans[mp[b[i]]]=mp[b[mn[itr].ss]];
        }
    }
    for(auto it:mp)
    {
        for(auto itr:ok[it.ff])
            ans[itr]=ans[mp[it.ff]];
    }
    printV(ans);
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
        

        solve(i);
    }

    


    return 0;
}






































