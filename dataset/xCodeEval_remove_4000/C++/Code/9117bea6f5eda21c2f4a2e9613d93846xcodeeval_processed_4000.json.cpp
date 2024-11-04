
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
int rng(int lim) {
  uniform_int_distribution<int> uid(0, lim - 1);
  return uid(rang);
}
ll mpow(ll base, ll exp);
ll power(ll a,ll b);


const ll mod = 1e9+7;


  

  

  

  

  


  

 




struct node
{
  set<int> s;
};








struct segTree
{
  int arr[2001];
  int res[8003];

  

  int NO_OPERATION=0;

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

  

  

  

  

  


  

  

  

  

  


  ll merge_results(ll a, ll b)
  {
    return a+b;
  }  


  

  

  


  

  

  

  


  



  

  


  

  

    

    
  

  

  

  

  

  


  

  


  

  

  


  

  

  

  

  

  

  


  



  

  

  

  

  

  





  void update_point(int x)
  {
    res[x]=min(res[2*x],res[2*x+1]);
  }

  int query(int x,int lo,int hi,int l,double val)
  {
    

    
    
    if(hi<l)
      return 0;
    

    if(res[x]>=val)
      return 0;

    if(lo==hi)
      return lo;

    int mid=(hi+lo)/2;
    
    int r1=query(2*x,lo,mid,l,val);

    if(r1!=0)
      return r1;
    return query(2*x+1,mid+1,hi,l,val);

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
  
  
};







  



  





































































    




























bool id0(vpl t2,int n,double x,double t,vl prefix,vl suffix,vl id1,vl id3,vl id2)
{
  double s1=0,s2=0;
  double rem1=x,rem2=x;



  int res1=upper_bound(prefix.begin(),prefix.end(),x)-prefix.begin();
  int res2=upper_bound(id1.begin(),id1.end(),x)-id1.begin();
  res2=n-1-res2;


  if(res1>=1)
    s1=s1+id3[res1-1],rem1-=prefix[res1-1];



  if(res1!=n)
  { 
    double k=min(1.0*t2[res1].S,rem1);
    s1=s1+k*t2[res1].F,rem1-=k;
    

  }
  

  if(res2+1<n)
    s2=s2+id2[res2+1],rem2-=suffix[res2+1];

  if(res2!=n)
  {
    double k=min(1.0*t2[res2].S,rem2);
    s2=s2+k*t2[res2].F,rem2-=k;
    

  }
  








  

  

  

  

  

  

  

  

  

  

  

  


  

  

  

  

  

  

  

  

  


  

  

  


  


  double eps=0.000001;
  if(abs(rem1)<=eps&&abs(rem2)<=0&&s1<=t*x&&s2>=t*x)
    return 1;

  return 0;
}
void solve()
{
  int n;double t;
  cin>>n>>t;


  double a[n],temp[n];vi a1;
  double sum=0;

  for(int i=0;i<n;i++){
    int u;
    cin>>u;

    a[i]=u,sum+=a[i];
    a1.pb(u);
  }

  vpl t2;
  vl v2;

  double mx_temp=-1,mn_temp=INT_MAX;

  for(int i=0;i<n;i++){
    int u;
    cin>>u;

    temp[i]=u,mx_temp=max(mx_temp,temp[i]),mn_temp=min(mn_temp,temp[i]);
    t2.pb(mp(u,a1[i]));


  }

  sortall(t2);

  for(int i=0;i<n;i++)
    v2.pb(t2[i].F*t2[i].S);

  ll pre=0,suf=0;

  vl prefix;
  vl suffix(n);

  vl id1;

  for(int i=0;i<n;i++)
  {
    pre+=t2[i].S;
    prefix.pb(pre);
  }


  for(int i=n-1;i>=0;i--)
  {
    suf+=t2[i].S;
    suffix[i]=suf;
  }

  for(int i=n-1;i>=0;i--)
    id1.pb(suffix[i]);

  

  

  

  



  vl id3,id2(n);

  pre=0,suf=0;

  for(int i=0;i<n;i++)
  {
    pre+=v2[i];
    id3.pb(pre);
  }

  for(int i=n-1;i>=0;i--)
  {
    suf+=v2[i];
    id2[i]=suf;
  }



  if(t>mx_temp||t<mn_temp)
  {
    cout<<"0"<<"\n";
    return;
  }


  



  

  

  

  

  


  


  

  


  


  

  

  

  


  

  

  


  


  

  

  

  


  

  

  



  


  

  



  

  



  

  

  


  double res=0,l=0,r=sum;
  double eps=0.000002;


  int cn=0;
  bool b=0;
  while(r-l>eps&&cn<300)
  { 
    cn++;
    

    double mid=l+(r-l)/2.0;

    if(id0(t2,n,mid,t,prefix,suffix,id1,id3,id2))
    {
      l=mid;b=1;
    }
    else
      r=mid;
  }

  if(b==0)
  {
    cout<<"0"<<"\n";
    return;
  }

  res=l+(r-l)/2;

  cout<<fixed<<setprecision(11)<<res<<"\n";
  

  

}




int main()
{

    

    
          freopen("input.txt","r",stdin);
          freopen("output.txt","w",stdout);
    

    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());
    


   
    int t = 1;
    

    while(t--)
    {
        solve();
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
      a=a*a;
    }
    else
    {
      res=res*a;
      b--;
    }
  }
  return res;
}