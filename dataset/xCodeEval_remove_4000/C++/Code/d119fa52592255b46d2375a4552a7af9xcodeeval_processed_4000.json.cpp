
using namespace std;




















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


  vi g[1000005];

  


  

   

  

  


  

 





















































struct node
{
  set<int> s;
};










struct segTree
{
  ll arr[301];
  int res[1203];

  ll operation_arr[1203];
  ll NO_OPERATION=0;

  void init(int x,int lo,int hi)
  {
    operation_arr[x]=NO_OPERATION;
    

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

  

  

  

  


  

  

  

  

  


  

  

  

  

  

  

  

  

  

  


  

    
  

  


  int merge_results(int a,int b)
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
  

  int query(int x,int lo,int hi,int l,int r)
  {
    

    
    if(lo>=l&&hi<=r)
    {
      return res[x];
    }
 
 
 
    int mid=(hi+lo)/2;
    int res;
 
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
  int par[1001];
  int size_set[1001];

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
bool id1(ll a,ll b)
{
  ll res=a+b;

  if(res-a==b&&res-b==a)
    return 0;
  return 1;
}
































































int d[200002];
ll N=(200000+1);
vl pr;

void seive(int N)
{
  for(int i=2;i<N;i++)
    d[i]=i;


  for(ll i=2;i<N;i++)
  {
    if(d[i]==i)
      pr.pb(i);

    for(ll j=0;j<(ll)pr.size() && pr[j]<=d[i] && i*pr[j]<N;j++)
      d[i*pr[j]]=pr[j];
  }

}

bool is_prime(int n)
{
  if(d[n]==n)
    return 1;
  return 0;

}
vpii id0(int n)
{
  vpii res;

  while(n>1)
  {
    int k=d[n];

    int cnt=0;
    while(n>1&&k==d[n])
      n/=d[n],cnt++;

    res.pb({k,cnt});
  }

  return res;
}


vpii id2(int n)
{
  vpii res;

  for(int i=2;i*i<=n;i++)
  {
    if(n%i==0)
    {
      int cnt=0;
      while(n%i==0)
        n/=i,cnt++;

      res.pb({i,cnt});
    }
  }

  if(n>1)
    res.pb({n,1});
  return res;
}








































map<int,int> cnt;
vi t[6000001];

vpii sum_pairs[6000001];

void solve()
{     
  vi a;

  int n;
  cin>>n;

  for(int i=0;i<n;i++)
  {
    int u;
    cin>>u;

    a.pb(u);

    if(cnt.find(u)==cnt.end())
      cnt[u]=1;
    else
      cnt[u]++;

    t[u].pb(i+1);
  }

  vi f;
  vi f1;

  for(auto i: cnt)
  {
    if(i.S>=2)
    {
      f.pb(i.F);
      f1.pb(i.S);
    }
  }

  if(f.size()>1)
  {
    cout<<"YES"<<"\n";
    cout<<t[f[0]][0]<<" "<<t[f[1]][0]<<" "<<t[f[0]][1]<<" "<<t[f[1]][1]<<"\n";
    return;
  }
  else if(f.size()==0)
  {
    

    for(int i=0;i<n;i++)
    {
      for(int j=i+1;j<n;j++)
      {
        int s=a[i]+a[j];
        sum_pairs[s].pb({i+1,j+1});

        if(sum_pairs[s].size()>1)
        {
          cout<<"YES"<<"\n";
          cout<<sum_pairs[s][0].F<<" "<<sum_pairs[s][0].S<<" "<<sum_pairs[s][1].F<<" "<<sum_pairs[s][1].S<<"\n";
          return;
        }
      }
    }
  }
  else{
  if(f1[0]>=4)
  {
    cout<<"YES"<<"\n";
    for(int i=0;i<4;i++)
      cout<<t[f[0]][i]<<" ";
    return;
  }
  else
  {
    a.clear();
    for(auto i:cnt)
    {
      a.pb(i.F);
    }

    n=a.size();
    for(int i=0;i<n;i++)
    {
      for(int j=i+1;j<n;j++)
      {
        int s=a[i]+a[j];
        sum_pairs[s].pb({t[a[i]][0],t[a[j]][0]});

        if(sum_pairs[s].size()>1)
        {
          cout<<"YES"<<"\n";
          

          cout<<sum_pairs[s][0].F<<" "<<sum_pairs[s][0].S<<" "<<sum_pairs[s][1].F<<" "<<sum_pairs[s][1].S<<"\n";
          return;
        }
      }
    }

    int s=2*f[0];

    for(int i=0;i<n;i++)
    {
      if(a[i]==f[0])
        continue;

      if(cnt.find(s-a[i])!=cnt.end())
      {
        cout<<"YES"<<"\n";
        for(int j=0;j<2;j++)
        {
          cout<<t[f[0]][j]<<" ";
        }
        cout<<t[a[i]][0]<<" "<<t[s-a[i]][0]<<" ";
        return;
      }
    }

  }
  }
  cout<<"NO"<<"\n";


}   


int main() 
{

   
          freopen("input.txt","r",stdin);
          freopen("output.txt","w",stdout); 
    

    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());
    
    

    

  
    int t = 1;
    

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