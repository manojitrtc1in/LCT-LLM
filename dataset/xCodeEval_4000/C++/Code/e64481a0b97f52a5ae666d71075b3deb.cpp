

 
#include<bits/stdc++.h>
 
using namespace std;
 
#define ll long long int
#define ini(arr, val) memset(arr, (val), sizeof(arr))
 
#define loop(i,n)  for(ll i=0; i<n; i++)
#define loop1(i,n)  for(ll i=1; i<=n; i++)
 
#define all(a)      (a).begin(),(a).end()
#define exist(s,e)  (s.find(e)!=s.end())
#define dbg(x)  cout << #x << " = " << x << endl
#define pt(x) cout<<x<<"\n"
#define pts(x) cout<<x<<" "
 
#define mp make_pair
#define pb push_back
#define F first
#define S second
 
 
#define inf (int)1e9
#define infll 1e18
#define eps 1e-9
#define PI 3.1415926535897932384626433832795
#define mod 1000000007
 
 
#define fast   ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define test   ll t; cin>>t; while(t--)
 
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<pii> vpii;
typedef vector<vi> vvi;
typedef map<int, int> mii;
typedef set<int> si;
 
typedef pair<ll, ll> pll;
typedef vector<ll> vl;
typedef vector<string> vs;
typedef vector<pll> vpll;
typedef vector<vl> vvl;
typedef map<ll, ll> mll;
typedef set<ll> sl;
 
 
int dirx[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int diry[] = { -1, 0, 1, -1, 1, -1, 0, 1 };
 
 
 
 
 






 
void dfs(vector<int> adj[], map<pair<int, int>, int> &ans, int u, int p, int curr = 2)
{
    for (auto v : adj[u])
        if (v != p)
        {
            ans[ {v, u}] = curr;
            ans[ {u, v}] = curr;
            dfs(adj, ans, v, u, 5 - curr);
        }
}
 
 
vector<ll>P;
void SieveOfEratosthenes(int n)
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
    for (int p = 2; p <= n; p++)
        if (prime[p])
            P.pb(p);
}
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 int LCSLength(string X, string Y)
{
    int m = X.length(), n = Y.length();
 
    

    

    

    int lookup[m + 1][n + 1];
 
    

    for (int i = 0; i <= m; i++) {
        lookup[i][0] = 0;
    }
 
    

    for (int j = 0; j <= n; j++) {
        lookup[0][j] = 0;
    }
 
    

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            

            if (X[i - 1] == Y[j - 1]) {
                lookup[i][j] = lookup[i - 1][j - 1] + 1;
            }
            

            else  {
                lookup[i][j] = max(lookup[i - 1][j], lookup[i][j - 1]);
            }
        }
    }
 
    

    return lookup[m][n];
}
 
 
int LCSubStr(string X, string Y )
{
    int m = X.length(), n = Y.length();
   
 
    int LCSuff[m + 1][n + 1];
    int result = 0; 
    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
        
            if (i == 0 || j == 0)
                LCSuff[i][j] = 0;
 
            else if (X[i - 1] == Y[j - 1]) {
                LCSuff[i][j] = LCSuff[i - 1][j - 1] + 1;
                result = max(result, LCSuff[i][j]);
            }
            else
                LCSuff[i][j] = 0;
        }
    }
    return result;
}
 
int checkCycle(int node, vector<int>&vis, vector<int>adj[], int dfsVis[]){
    vis[node] = 1;
    dfsVis[node] = 1;
 
    for(auto i:adj[node]){
        if(vis[i]==0){
            if(checkCycle(i,vis,adj,dfsVis)) return true;
        }
        else if(dfsVis[i]==1){
            return true;
        }
    }
    dfsVis[node] = 0;
    return false;
}
 
int n = 4;
 
    int dist[10][10] = {
        {0,20,42,25},
        {20,0,30,34},
        {42,30,0,10},
        {25,34,10,0}
};
 
int visited = (1<<n) -1;


 








 


 


 
















 
int dfss( int i, int j,int n, int m){
 
    if(i<0 || i>=n || j<0 || j>=m){
        return 0;
    }
    return 1;
 
    

    

    

 
    

    

    

    

    

 
}
 
vector<int>adj[200005];
 int nn,m;
 
set<int>st;
int res = -200009;
 
int depth(int src, int par, int *d){
    for(auto i:adj[src]){
        if(i!=par){
            d[i] = 1+d[src];
            depth(i,src,d);
        }
    }
}
 
 
 
ll sortbysec(pair<int,int> a,pair<int,int> b)
{
    return (a.second < b.second);
}
 
int v[1001][1001] = {0};
char a[1001][1001];
char c[1001][1001];
vector<char>path;
 
int possible( int i, int j){
    if(i<0 || i>=nn || j<0 || j>=m || (v[i][j]==1) || a[i][j]=='#'){
        return 0;
    }
    return 1;
}
 


 
























































 
 
int bfs(int ax,int ay){
    queue<pair<int,int>>q;
    q.push({ax,ay});
    v[ax][ay] = 1;
    while(!q.empty()){
        int x = q.front().first,y = q.front().second;
        q.pop();
 
        if(a[x][y]=='B'){
 
            while(1){
                path.pb(c[x][y]);
                if(path.back() == 'L') y++;
                if(path.back() == 'R') y--;
                if(path.back() == 'U') x++;
                if(path.back() == 'D') x--;
                if(ax == x && ay == y)
                break;
            }
            return 1;
        }
 
        if(possible(x,y-1)){
            q.push({x,y-1}); v[x][y-1] = 1; c[x][y-1] = 'L';
        }
 
        if(possible(x,y+1)){
            q.push({x,y+1}); v[x][y+1] = 1; c[x][y+1] = 'R';
        }
        if(possible(x-1,y)){
            q.push({x-1,y}); v[x-1][y] = 1; c[x-1][y] = 'U';
        }
        if(possible(x+1,y)){
            q.push({x+1,y}); v[x+1][y] = 1; c[x+1][y] = 'D';
        }
    }
    return 0;
}
 
int dp[1000001] = {0};


 
 
int solve(int a,int b,int ar[]){
    if(b==0){
        return 0;
    }
 
    if(dp[b]!=1000009){
        return dp[b];
    }
 
    int ans =1000009;
 
    loop(i,a){
        

 
        if(b-ar[i]>=0){
            int sub_prob = 1 + solve(a,b-ar[i],ar);
            

 
            if(sub_prob < ans){
            ans = sub_prob;
            

 
        } 
        }
 
        
    }
    return dp[b] = ans;
}
 
#define mod1 1000000007;
int ans1 = -1,ans2 = -1;
vector<int>ans(100001),visi(100001,0),pare(100001);
 
vector<int>adj1[100001];
bool dfs(int u, int v){
    

    visi[u] = 1;
    pare[u] = v;
    for(auto i:adj1[u]){
        if(i==v){
            continue;
        }
        if(visi[i]==1){
            ans1 = i;
            ans2 = u;
            return true;
           
        }
        if(visi[i]==0){
            if(dfs(i,u)){
                return true;
            }
            

                

            

        }
    }
   
    return false;
}
 
bool visit_all(int aa)
{
    for(int i = 0; i < aa; ++i)
    {
        if(!visi[i])
            if(dfs(i,-1)) return true;
    }
    return false;
}
 
vector<int>vv[100005];
vector<int>vis(100001);
 
int val[100001] = {0};
vector<int>an;
 
int dfs(int x){
    if(vis[x]==0){
        vis[x]=1;
        ans.pb(x);
        for(auto i:vv[x]){
        dfs(x);
    
        }
        

    }
}
 
int v1[100005] = {0};
bool cycle(int s){
    v1[s]=1;
    for (auto i: vv[s]){
        if (v1[i]==0){
            if (cycle(i)) return 1;
        }
        else if (v1[i]==1) return 1;
    }
    v1[s] = 2;
    return 0;
}
 
stack<int>stac;
 
void d(int s){
    if (!vis[s]) {
        vis[s]=1;
    for (auto i: vv[s]) 
    {
        d(i);
    }
    stac.push(s);

    }
    }

    ll binpow(ll x, ll y){
        if(y==0){
            return 1;
        }
        if(y==1){
            return x;
        }
        ll ans = binpow(x,y/2);
        if(y%2==0){
            return ans*ans;
        }
        return ans*ans*x;
    }





const int md = 1e9 + 7;
const int N = 40000;
vector<int>ok;
int dpp[N+1][500];
int x(int a,int b){
    return a<b;
}

const int sz = 100005;
int par[sz];
int sze[sz];

void initialize(int n){
    for(int i = 1;i<=n;i++){
        par[i] = i;
        sze[i] = 1;
    }
}

int find(int a){
    if(par[a]==a){
        return a;
    }
    else{
        return par[a] = find(par[a]);
    }
}

void merge(int a, int b){
    a = find(a);
    b = find(b);
    if(a==b){
        return;
    }
    if(sze[a]<sze[b])
        swap(a,b);

        par[b] = a;
        sze[a]+=sze[b];
    
}


ll power(ll v,ll B,ll C)
{
    if (v == 0)
        return 0;
    if (B == 0)
        return 1;
    ll y;
    if (B % 2 == 0)
    {
        y = power(v, B / 2, C);
        y = (y * y) % C;
    }
    else
    {
        y = v % C;
        y = (y * power(v, B - 1, C) % C) % C;
    }
    return (ll)((y + C) % C);
}


const ll modd = 1e9+7;








 void findAIsland(vector<vector<int>>& grid,int i,int j,int& ok,map<int,int>&mp,int& cnt){
        if(grid[i][j]==0 || grid[i][j]>1){
            return;
        }
        int n = grid.size();
        grid[i][j]=ok;cnt++;
        if(i>0) findAIsland(grid,i-1,j,ok,mp,cnt);
        if(j>0) findAIsland(grid,i,j-1,ok,mp,cnt);
        if(i<n-1) findAIsland(grid,i+1,j,ok,mp,cnt);
        if(j<n-1) findAIsland(grid,i,j+1,ok,mp,cnt);

    }


    int get(int l,int r,int x,vector<vector<int>>&p){
        if(l==0) return p[x][r];
        return p[x][r]-p[x][l-1];
    }





   
 
int main()
{
    

#ifndef ONLINE_JUDGE
    

    freopen("input.txt", "r", stdin);
    

    freopen("output.txt", "w", stdout);
#endif
    

    


    int t;
    cin>>t;
    while(t--){
        int n,need;
        cin>>n>>need;
        int a[n];
        loop(i,n){
            cin>>a[i];
        }

        map<int,int>m;
        m[0] = 0;
        int sum = 0,ans = 0;
        loop(i,n){
            sum+=a[i];
            

            

            

            

            

            

            

            

            

            if(m.count(sum - need)){
                if(ans < (i-m[sum - need] + 1)){
                    ans = i-m[sum - need] + 1;
                    

                }
            }
            if(!m.count(sum)){
                m[sum] = i+1;
            }
        }

        


        if(ans == 0){
            cout<<-1<<endl;
        }
        else{
            cout<<n-ans<<endl;
        }
    }
}

















































