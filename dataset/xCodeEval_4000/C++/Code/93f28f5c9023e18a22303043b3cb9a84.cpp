#include<bits/stdc++.h>
using namespace std;
#define Fo(i,n) for(int i=0;i<n;i++)
#define fo(i,k,n) for(int i=k;k<n?i<n:i>n;k<n?i+=1:i-=1)
#define ll long long
#define si(x) scanf("%d",&x)
#define sl(x) scanf("%lld",&x)
#define ss(s) scanf("%s",s)
#define pi(x) printf("%d\n",x)
#define pl(x) printf("%lld\n",x)
#define ps(s) printf("%s\n",s)
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define sortall(x) sort(all(x))
#define tr(it, a) for(auto it = a.begin(); it != a.end(); it++)
#define PI 3.1415926535897932384626
typedef pair<int, int>  pii;
typedef pair<ll, ll>  pl;
typedef vector<int>   vi;
typedef vector<ll>    vl;
typedef vector<pii>   vpii;
typedef vector<pl>    vpl;
typedef vector<vi>    vvi;
typedef vector<vl>    vvl;

mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());








ll mpow(ll base, ll exp);
ll power(ll a,ll b);


const ll mod = 1000000007 ;


vi g[1000001];
  

  


  

   

  

  


  

 





















































struct node
{
  set<int> s;
};










struct segTree
{
  ll arr[3001];
  ll res[12003];


  

  ll NO_OPERATION=0;



  


  void init(int x,int lo,int hi)
  {
    

    

    if(lo==hi){
      res[x]=arr[lo];
      return;

    }

    int mid=(lo+hi)/2;
    init(2*x,lo,mid);
    init(2*x+1,mid+1,hi);

    

    
    update_point(x);
  }

  ll merge_operation(ll a,ll b)

  {
    


    return (a^b);
  }


  

  

  

  


  

  

  

  

  


  

  

  

  

  

  

  

  

  

  


  

    
  

  


  ll merge_results(ll a,ll b)
  { 
    return a+b;
  }  


  

  

  

 
  

      
  

  


  

  

 
  

  

 
  

  

  

  

  



  

  

  

  


  

  


  

  

  




  

  

    

  

  


  

  


  

  

      
  

  

  

  




  


  

  


  

  

  


  void point_modify(int x,int lo,int hi,int pos,ll val)
  {
    if(lo==hi)
    {
      res[x]=val;
      return;
    }

    int mid=(lo+hi)/2;


    if(pos<=mid)
      point_modify(2*x,lo,mid,pos,val);
    else
      point_modify(2*x+1,mid+1,hi,pos,val);
    update_point(x);
    

  }

  

  

  

  


  


  

  

  

  


  

  
  

  

  

    
  

  

 
 
 
  

  

 
  

  

  

  

  

  

    
 
  

  


  

  

  

  


  

  


  


  

  

  

  

  


  
  

  

  void update_point(int x)
  {
    res[x]=res[2*x]+res[2*x+1];
  }
  

  ll query(int x,int lo,int hi,int l,int r)
  {
    

    
    if(lo>=l&&hi<=r)
    {
      return res[x];
    }
 
 
 
    int mid=(hi+lo)/2;
    ll res;
 
    if(r<=mid)
       res=query(2*x,lo,mid,l,r);
    else if(l>mid)
      res= query(2*x+1,mid+1,hi,l,r);
    else
      res= merge_results(query(2*x,lo,mid,l,r),query(2*x+1,mid+1,hi,l,r));
    
 
    return res;
 
  }

  

  

  

  


  

  

  


  

  


  

  

  

  

  

  

  

  

  

  


  

  


  

  

  

  

  

  



  

  

  


  

  

  

  

  


  



  

  

  

  

  

  

  

  

  

  

  

  

  


  

  


  

  

  

  

    

  

  

  

  

  

  

  


  

  

  


  
};



struct  FenwickTree
{
  int arr[100];
  int n;

  void update(int i,int delta)
  {
    while(i<=n)
    {
      arr[i]+=delta;
      i=i+(i&(-i));
    }
  }

  int sum(int i)
  {
    if(i==0)
      return 0;
    int res=0;
    while(i>0)
    {
      res=res+arr[i];
      i-=(i&(-i));
    }

    return res;
  }

};



struct dsu
{
  int par[200001+100];
  int size_set[200001+100];

  void init(int n)
  {
    for(int i=0;i<=n;i++)
      par[i]=i,size_set[i]=1;
  }
 
  int get_par(int u)
  {
    vi temp;
    while(par[u]!=u)
    {
      temp.pb(u);
      u=par[u];
    }
 
    for(int i:temp)
      par[i]=u;
 
    return u;
  }
  
 
  void union_set(int a,int b)
  {
    a=get_par(a);
    b=get_par(b);
 
    if(a==b)
      return;
    if(size_set[a]<size_set[b])
    {
      int temp=a;
      a=b;
      b=temp;
    }
    
   

    

    par[b]=a;
    
    
    size_set[a]+=size_set[b];
    

 
    
  }

  int get_size(int u)
  {
    u=get_par(u);
    return size_set[u];
  }
  
  
};



ll gcd(ll a, ll b)
{
  if(a==0)
    return b;

    if (b == 0)
        return a;
    return gcd(b, a % b); 
     
}

















































































bool contains_dup(string s)
{
  int cnt[26];
  memset(cnt,0,sizeof(cnt));

  for(int i=0;i<s.size();i++)
  {
    cnt[s[i]-'a']++;
    if(cnt[s[i]-'a']>1)
      return 1;
  }
  return 0;
}

































































bool isOverflow(long long a, long long b) 
{ 
    

    if (a == 0 || b == 0)  
        return false; 
      
    

    if (a <= LLONG_MAX / b) 
        return false; 
    else
        return true; 
} 
bool isOverflow_add(ll a,ll b)
{
  ll res=a+b;

  if(res-a==b&&res-b==a)
    return 0;
  return 1;
}





























































































































































































































class Node{
public:
  int val;
  int end_cnt;
  Node* ptrs[2];

public:
  Node(){
    val=-1;
    end_cnt=0;
    ptrs[0]=NULL;
    ptrs[1]=NULL;
  }
};

class Trie{

  Node* root;

public:
  Trie(){
    root=new Node();
  }

  void insert(string s){

    int n=s.size();

    Node* curr=root;

    for(int i=0;i<s.size();i++){
      int v=s[i]-'0';

      if(curr->ptrs[v]==NULL){
        


        Node* new_nd=new Node();
        new_nd->val=v;

        if(i==s.size()-1){
          new_nd->end_cnt++;
        }
        curr->ptrs[v]=new_nd;
        curr=new_nd;
      }
      else{
        curr=curr->ptrs[v];

        if(i==s.size()-1){
          curr->end_cnt++;
        }
      }
    }

  }

  int find(string s){

    int n=s.size();

    Node* curr=root;
    for(int i=0;i<n;i++){
      int v=s[i]-'0';

      if(curr->ptrs[v]==NULL)
        return 0;
      curr=curr->ptrs[v];

      if(i==s.size()-1){
        if(curr->end_cnt==0){
          return 0;
        }
      }
    }

    return 1;
  }
};


void map_ins(ll u,map<ll,ll> &cnt)
{
  if(cnt.find(u)==cnt.end())
    {
      cnt[u]=1;
    }
    else
    {
      cnt[u]++;
    }
}
void map_rmv(ll u,map<ll,ll> &cnt)
{
  if(cnt.find(u)==cnt.end())
    return;
  else
  {
    cnt[u]--;
    if(cnt[u]==0)
      cnt.erase(u);
  }
}

ll get_cnt(ll u,map<ll,ll> &cnt)
{
  if(cnt.find(u)==cnt.end())
    return 0;
  return cnt[u];

}

int n,m;

vector<pair<pii,ll>> w;
vector<pair<pii,ll>> w1;

int vis[200001];

void dfs(int u)
{
  vis[u]=1;

  for(int i:g[u])
  {
    if(vis[i]==0)
      dfs(i);
  }
}

void solve()
{     
  cin>>n>>m;
  w.clear();


  for(int i=1;i<=m;i++)
  {
    ll u,v,wt;
    cin>>u>>v>>wt;

    w.pb({{u,v},wt});
    
  }


  ll res=0;


  for(ll i=31;i>=0;i--)
  {
    


    ll v1=(1LL<<i);

    

    for(int j=1;j<=n;j++)
      g[j].clear();

    for(auto e:w)
    {
      ll u,v,wt;
      u=e.F.F;
      v=e.F.S;

      wt=e.S;

      

      


      if((wt&v1)==0)

      {
        g[u].pb(v);
        g[v].pb(u);
      }
    }


   
    for(int j=1;j<=n;j++)
      vis[j]=0;

    dfs(1);


    bool b=1;

    for(int j=1;j<=n;j++)
    {
      if(vis[j]==0)
        b=0;
    }


    if(b)
    {
      w1.clear();
      for(auto e:w)
      {
        ll u,v,wt;
        u=e.F.F;
        v=e.F.S;

        wt=e.S;

        if((wt&v1)==0)

        {
          w1.pb({{u,v},wt});
        }
      }

      w=w1;
    }
    else
    {
      res+=v1;
    }

  }

  cout<<res<<"\n";



}


int main() 
{

   #ifndef ONLINE_JUDGE
          freopen("input.txt","r",stdin);
          freopen("output.txt","w",stdout); 
    #endif

    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());
    
    

    

    
    int t = 1;
    cin >> t;
    int t1=1;
    while(t--)
    {
        solve();
        t1++;
    }

    return 0;
}


ll mpow(ll base, ll exp)
{
    base %= mod;
    ll result = 1;
    while (exp > 0)
    {
        if (exp & 1)
          result = ((ll)result * base) % mod;
        base = ((ll)base * base) % mod;
        exp >>= 1;
  }
  return result;
}



ll power(ll a,ll b)
{
  ll res=1;
  while(b>0)
  {
    if(b%2==0)
    {
      b/=2;

      if(isOverflow(a,a))
        return LLONG_MAX;
      a=a*a;
    }
    else
    {
      if(isOverflow(res,a))
        return LLONG_MAX;
      res=res*a;
      b--;
    }
  }
  return res;
}