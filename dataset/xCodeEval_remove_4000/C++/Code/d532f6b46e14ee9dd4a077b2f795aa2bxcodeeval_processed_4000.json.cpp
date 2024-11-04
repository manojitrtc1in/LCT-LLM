

using namespace std;


























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
vector<vector<int>>adj(2e5+10);
vector<int>visited(1e4+10);
vector<int>d(1e4+10);
vector<int>parent(1e4+10);
set<int>ans;
int dfs(int x)
{
    for(int y:adj[x])
    {
        dfs(y);
    }
    ans.insert(x);
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
void id0(string str,vector<string>&k)
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
struct cmp{
bool operator() (const int &x,const int &y)
   {
   return x>y;
   }
};
void solution()
{ 
   int n;
   cin>>n;
   vector<int>p(n);
  for(int i=1;i<n;i++)
  {
    int x;
    cin>>x;
    p[--x]++;
  }
    p.emplace_back(1);
    sort(all(p));
    reverse(all(p));
    while(!p.empty()&&p.back()<=0)
           p.pop_back();
    multiset<int,cmp>l;
    int ans=p.size();
    

    for(int i=0;i<ans;i++)
    {
         p[i]-=(ans-i);
         

    }
    while(!p.empty()&&p.back()<=0)
           p.pop_back();
       for(int i=0;i<p.size();i++)
          l.insert(p[i]);
while(!l.empty())
{
     int p=*l.begin();
     l.erase(l.begin());
     p--;
     l.insert(p);
     multiset<int,cmp>m;
    for(auto it=l.begin();it!=l.end();it++)
            {
                int h=*it;
                h--;
                m.insert(h);
            }
            l.clear();
            for(auto x:m)
                l.insert(x);
            m.clear();
ans++;
while(!l.empty()&&*l.rbegin()<=0)
           l.erase(prev(l.end()));
} 
cout<<ans<<"\n";
} 
int main() 
{
    ios_base::sync_with_stdio(0), cin.tie(0),cout.tie(0);
    
freopen("input.txt", "r", stdin);;
freopen("output.txt", "w", stdout);




    srand(chrono::high_resolution_clock::now().time_since_epoch().count());
     ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
     int t=1;
     

     

     prepal();
     ci(t);
    

    

    while (t--) {
        solution();
    }
    return 0;
}