#include<bits/stdc++.h>
#include<iostream>
using namespace std;
#define gc getchar_unlocked
#define ll long long
#define PI 3.1415926535897932384626
#define si(x) scanf("%d", &x)
#define ci(x) cin>>x
#define ss(s) scanf("%s", s)
#define pi(x) printf("%d\n", x)
#define pl(x) printf("%lld\n", x)
#define ps(s) printf("%s\n", s)
#define br printf("\n")
#define fo(i, n) for(int i=0;i<n;i++)
#define foi(i, n) for(int i=1;i<=n;i++)
#define Fo(i, k, n) for(i=k;k<n?i<n:i>n;k<n?i+=1:i-=1)
#define deb(x) cout << #x << " = " << x << endl;
#define deb2(x, y) cout << #x << " = " << x << ", " << #y << " = " << y << endl
#define deba(i, a, n) fo(i, n){cout << a[i] << " ";}
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define clr(x) memset(x, 0, sizeof(x))
#define sortall(x) sort(all(x))
#define tr(it, x) for(auto it = x.begin(); it != x.end(); it++)
#define trr(it, x) for(auto it = x.rbegin(); it != x.rend(); it+)
typedef pair<int, int> pii;
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<pl> vpl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
int rng(int lim) {
    uniform_int_distribution<int> uid(0, lim - 1);
    return uid(rang);
}
const int mod = 998244353;
const int N = 3e5;
ll gcd(ll a,ll b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
string removeSpaces(string str)
{
    str.erase(remove(str.begin(), str.end(), ' '), str.end());
    return str;
}
vector<vector<int>>adj(3e5+10);
vector<int>visited(3e5+10);
vector<vector<ll>>d(2e5+10,vl(2));
vector<int>child(2e5+10);
vector<int>ans2;
vi xcr;
vi ycr;
vector<vl>dp(2e5+10,vl(2));
vi counte(2e5+10);
void dfs(int x,int p)
{  
    for(int y:adj[x])
       {
        if(y==p)
            continue;
        visited[y]=1;
          dfs(y,x);
          if(counte[y]+1>counte[x])
          counte[x]=max(counte[y]+1,counte[x]),child[x]=y;
          if(d[x][0]<=d[x][1])
            swap(d[x][0],d[x][1]);
         if(d[x][0]<counte[y]+1)
            {swap(d[x][0],d[x][1]);d[x][0]=counte[y]+1;}
        else if(d[x][1]<counte[y]+1)
            d[x][1]=counte[y]+1;
       }
}

map<ll,ll>p;
ll maxp(ll n,ll k)
{
    ll step=0;
    while((long long int )pow(k,step)<=n)
    {
        step++;
    }
    return step-1;
}
bool power(ll n, ll k)
{
    int f=0;
    while(n>0)
    {
        ll s=maxp(n,k);
        p[s]++;
        

        if(p[s]>1)
        {
            f=1;
            break;
        }
        n-=(long long int)pow(k,s);
    }
    if(f==1)
        return false;
    else
        return true;
}

ll modInverse(ll x)
{
    ll p = mod - 2;
    ll res = 1;
    while (p)
    {
        if (p % 2 == 1)
        {
            res = (res * x) % mod;
            p--;
        }
        else
        {
            x = (x * x) % mod;
            p = p / 2;
        }
    }
    return res % mod;
}




bool f(pair<char,int>x,pair<char,int>y)
{
    return x.first<y.first;
}




bool check(ll mid,vpii t)
{
    int j=0;
    int n=t.size();
    fo(i,n)
    {
         int l=t[i].first;
         int r=t[i].second;
         if(l>=mid-j-1 and r>=j)
            j++;
    }
    if(j>=mid)
        return true;
    return false;
}
vector<ll>precalcfac(15,-1);
void preprocessingfac()
{
    precalcfac[0]=1;
    for(int i=1;i<15;i++)
    {
         precalcfac[i]=precalcfac[i-1]*i;
    }
}




vector<int>z(2e5+10);
void z_function(string &s) {
    int n = (int) s.length();
    vector<int>z(n);
    for (int i = 1, l = 0, r = 0; i < n; ++i) {
        if (i <= r)
            z[i] = min (r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            ++z[i];
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }
}
ll power1(ll x,ll y)
{
    if(y==0)
        return 1;
    ll p=x;
    y--;
    for(int i=1;i<=y;i++)
        {x=x*p;
        }
return x;
}
struct cmp{
bool operator() (const pii &x,const pii &y)
   {
   if(x.second-x.first==y.second-y.first)
    return x.first<y.first;
   return x.second-x.first>y.second-y.first;
   }
};
map<int,int>w;
bool comparefn(int x,int y)
{
    return counte[x]>counte[y];
}
vl tempa(1e5+10);
int q;
void dfs2(int x,int p)
{
    for(auto y:adj[x])
    {
        if(child[x]==y)

        {
            if(y==p)
                continue;
            if(d[y][0]<=d[x][1]+1)
            {
               swap(d[y][0],d[y][1]);
               d[y][0]=d[x][1]+1;
               child[y]=x;
            }    
        else
        {
            d[y][1]=max(d[y][1],d[x][1]+1);
        }
      }
        else
        {
             if(d[y][0]<=d[x][0]+1)
             {
                swap(d[y][0],d[y][1]);
                d[y][0]=d[x][0]+1;
                child[y]=x;
             }
             else if(d[y][1]<=d[x][0]+1)
             {
               d[y][1]=d[x][0]+1;
             }
        }
        dfs2(y,x);
    }
}
vector<ll>prefix(2* 1e5 + 10);
vector<ll>bit(2 * 1e5 + 10);
vector<ll>bitc(2 * 1e5 + 10);
vector<ll>ar(2 * 1e5 + 10);
vi arc(2*1e5+10);
vector<ll>prefixc(2* 1e5 + 10);
ll simqueryc(int in, int fin)
{
    return prefixc[fin] - prefixc[in] + arc[in];
}
ll simquery(int in, int fin)
{
    return prefix[fin] - prefix[in] + ar[in];
}
void build(int n)
{
    for (int i = 1; i <= n; i++)
    {
        int m = ~i + 1;
        m = i & m;
        int k = m;
        int in = i - k + 1;
        bit[i]=simquery(in, i);

    }
}

void buildc(int n)
{
    for (int i = 1; i <= n; i++)
    {
        int m = ~i + 1;
        m = i & m;
        int k = m;
        int in = i - k + 1;
        bitc[i]=simqueryc(in, i);

    }
}
void update(int k,int x,int n) 
{
    x = x - ar[k];
    while (k <= n) {
        bit[k]+=x;

        k += k & -k;
    }
}

void updatec(int k,int x,int n) 
{
    x = x - arc[k];
    while (k <= n) {
        bitc[k]+=x;

        k += k & -k;
    }
}
ll query(int k)
{
    ll s=0;
    while (k >= 1)
    {
        s += bit[k];
        k -= k & -k;
    }
    return s;
}

ll queryc(int k)
{
    ll s=0;
    while (k >= 1)
    {
        s += bitc[k];
        k -= k & -k;
    }
    return s;
}
vector<ll>sum;
void precl()
{
    sum.pb(0);
    for(int i=1;i<=2e5;i++)
        {
            ll b=i*1LL*(i+1)/2;
            sum.pb(b);
        }
}
bool loveyou(pii x,pii y)
{
 if(x.first<y.first)
    return true;
 if(x.first==y.first&&x.second<y.second)
    return true;
return false;
}
vector<vi>ansu(2e5+10);
pii largest_subarray(vi a, int n)
{
    

    unordered_map<int, int> index;
    int ans = 0;
    pii range;
    for (int i = 0, j = 0; i < n; i++) {
  
        

        

        j = max(index[a[i]], j);
  
        

        

        if(i-j+1>=ans)
        {
            ans = max(ans, i - j + 1);
            pii k={j,i};
            ansu[ans].pb(2*min(k.first-0,n-1-k.second)+max(k.first-0,n-1-k.second));
            range.first=j;
            range.second=i;
         }
        

        

        index[a[i]] = i + 1;
    }
    

    return range;
}
map<int,int>love;
int  recur(int x)
{
    int a=0;
       for(auto y:adj[x])
       {
          if(!visited[y])
         {visited[y]=1;
          a+=recur(y);}
       }
       return love[x]=a+1;
return 0;
}
int ans=0;
int recur1(int x)
{
    vector<int>y;
    for(auto h:adj[x])
        if(!visited[h])
             y.pb(h);
    if(y.size()==1)
    {
        visited[y[0]]=1;
        ans=max(ans,love[y[0]]-1);
         return love[y[0]]-1;
    }
    if(y.size()==2)
    {
        int first=0;
        visited[y[0]]=1;
        int a=recur1(y[0]);
        visited[y[1]]=1;
        int b=recur1(y[1]);
        a+=love[y[1]]-1;
        b+=love[y[0]]-1;
        ans=max(ans,max(a,b));
        return max(a,b);
    }
    return 0;
}
void solution()
{
    int n;
    cin>>n;
    int l=1;
    int r=n;
    assert(n!=-1);
    while(l<r)
    {
           int mid=(l+r)/2;
        cout<<"?"<<" "<<l<<" "<<mid<<endl;
      int count=0;
      for(int i=0;i<mid-l+1;i++)
        {
            int p;
            cin>>p;
            assert(p!=-1);
            if(p>=l&&p<=mid)
                count++;
        }
         if(count%2)
         {
            r=mid;
         }
         else
            l=mid+1;
    }
    cout<<"! "<<l<<endl;
}
int main() 
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());
     ios_base::sync_with_stdio(0),cin.tie(0);
     

     

     

     int t=1;
     ci(t);
    

    

     q=0;
    while (t--) {
        q++;
        solution();
    }
    return 0;
}