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
const int mod = 1e9+7;
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
vector<vector<int>>adj(1e5+10);
vector<int>visited(1e5+10);
vector<int>d(1e5+10);
vector<int>parent(1e5+10);
set<int>ans;
vi mark(1e5+10);
ll temp=0;
int fu=0;
void dfs(int x)
{
    for(int y:adj[x])
    {
        if(!visited[y])
        {
            visited[y]=1;
            dfs(y);
        }
    }
     if(mark[x]>=0)
                temp++;
            if(mark[x]==-1)
                {fu=1;}
}
void bfs(int s)
{
queue<int>q;
q.push(s);
visited[s] = true;
parent[s] = -1;
while (!q.empty()) {
    int v = q.front();
    q.pop();
    for (int u : adj[v]) {
        if (!visited[u]) {
            visited[u] = true;
            q.push(u);
            d[u] = d[v] + 1;
            parent[u] = v;
        }
    }
}
}


ll power(long long x, unsigned int y, int p)
{
    int res = 1;
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










vector<int>siz(1e5 + 5, 0);
vector<int>link(1e5 + 5, 0);
vector<int>vis(1e5+5,0);
int para = 0;

int si=0;

int find(int x)
{
    while (link[x] != x)
    {
        x = link[x];
    }
    return x;
}
bool same(int a, int b)
{
    if (find(a) == find(b))
        return true;
    return false;
}
void unite(int a, int b)
{
    if (!same(a, b))
    {
        int g = find(a); int h = find(b);
        if (siz[g] <= siz[h])
        {
            link[g] = b;
            siz[h] += siz[g];
            para -= 1;
            si = max(siz[h],si);
        }
        else
        {
            link[h] = a;
            siz[g] += siz[h];
            para -= 1;
            si = max(siz[g], si);
        }
    }
}


struct node
{   int data;
    struct node *left;
    struct node *right;
};
struct node *Newnode(int data)
{
    struct node *node=(struct node *)malloc(sizeof(struct node));
    node->data=data;
    node->left=NULL;
    node->right=NULL;
   return (node);
}
void inorder(struct node* root)
{
    if(root->left!=NULL)
        inorder(root->left);
    cout<<root->data<<" ";
    if(root->right!=NULL)
        inorder(root->right);
}
bool chbool(vi &t,ll mid,int u)
{
    vector<int>w=t;
    ll c2=mid/2;
    ll ma=u;
    ll c1=mid-c2;
    for(int i=0;i<t.size();i++)
    {
        if(w[i]!=ma)
        {ll y=w[i];
        ll e=ma-y;
        ll p=e/2;
        if(p<=c2)
        {
           c2-=p;
           w[i]+=p*2;
        }
      }
    else
        break;
    }
 for(int i=0;i<t.size();i++)
 {
    if(w[i]==ma)
        continue;
     ll s=ma-w[i];
     if(s>c1)
     return false;
     else
     {
        c1-=s;
        w[i]+=s;
     }
 }
for(int i=0;i<t.size();i++)
{
     if(w[i]!=ma)
     return false;
}
return true;
}
void printSubstrings(string str,vector<string>&k)
{
 
    for (int i = 0; i < str.length(); i++) {
        string subStr;
        for (int j = i; j < str.length(); j++) {
            subStr += str[j];
            k.pb(subStr);
        }
    }
}
vl pal;
vl dp(40000+10);
void prepal()
{
    for(int i=1;i<=40000;i++)
      {
         string y=to_string(i);
         string m=y;
         reverse(all(y));
         if(m==y)
            pal.pb(i);
      }
      dp[0]=1;
      for(int j=0;j<pal.size();j++)
     {
         for(int i=0;i<=40000;i++)
             {
                if(pal[j]<=i)
                {
                    dp[i]+=dp[i-pal[j]];
                    dp[i]%=mod;
                }

             }
     }
}
ll coun=1;
int n,k;
void recur(int plane,int particle,int dir)
{
    if(plane>n||particle<=1||plane<=0)
    {
        return ;
    }
    coun%=mod;
    if(dir==0)

    {coun++;recur(plane-1,particle-1,1);}
    if(dir==1)

        {coun++;recur(plane+1,particle-1,0);}
    recur(plane+1,particle,dir);
}
void solution()
{ 
      int n;
      cin>>n;
       vi a(n);
       vi b(n);
       fo(i,n)
       cin>>a[i];
       fo(i,n)
       cin>>b[i];
       vi d(n);
       fo(i,n)
       cin>>d[i];
       fo(i,n)
       {
         mark[d[i]]=-1;
       }
       
fo(i,n)
{
         if(a[i]!=b[i])
         {
         adj[a[i]].pb(b[i]);
         adj[b[i]].pb(a[i]);
         }
         if(a[i]==b[i])
            visited[a[i]]=1,mark[a[i]]=-1;
}
unsigned int count=0;
for(int i=1;i<=n;i++)
{
   if(!visited[i])
   {
    visited[i]=1;
    dfs(i);
    if(temp>=2&&!fu)
        count++;
    

    

    temp=0;
    fu=0;
   }
}
fo(i,n+1)
adj[i].clear(),visited[i]=0,mark[i]=0;
cout<<power(2LL,count,1e9+7)<<"\n";
} 
int main() 
{
    ios_base::sync_with_stdio(0), cin.tie(0),cout.tie(0);
    #ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);;
freopen("output.txt", "w", stdout);
#else


#endif
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());
     ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
     int t=1;
     

     

     

     ci(t);
    

    

    while (t--) {
        solution();
    }
    return 0;
}