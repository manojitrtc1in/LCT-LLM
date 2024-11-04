#include <bits/stdc++.h>
#define lli long long int
#define pb push_back
#define mod2 1000000007
#pragma GCC optimize ("-O2")
#define mod 998244353
#define MAXN 1000000000
#define v32 vector<int>
#define v64 vector<lli>
#define v1024 vector <vector <int>>
#define v4096 vector <vector <lli>>
#define vt vector
#define f(x, y, z) for (lli x = y; x < z; x++)
#define fd(x, y, z) for (lli x = y; x > z; x--)
#define lb lower_bound
#define ld long double
#define m64 map<lli,lli>
#define m32 map<int,int>
#define m64it map<lli,lli>::iterator
#define m32it map<int,int>::iterator
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define ist insert
#define endl "\n"
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ordered_set tree<pair<int,int>, null_type,less<pair<int,int>>, rb_tree_tag,tree_order_statistics_node_update> 
#define p_q priority_queue 
#define min_p_q priority_queue <pair<lli,int>,vt <pair<lli,int>>,greater <pair<lli,int>>>
using namespace std;
using namespace __gnu_pbds; 



lli tmod(lli x,lli m=mod){return (x%m+m)%m;}
class ConvexHullOptimization{
    public:
    struct line{
        lli m,c;    

    };
    deque <line> STACK;
    vt <ld> points;
    ld IntersectionOfLines(line X,line Y){
        if(X.m==Y.m)return MAXN;
        return ((ld)(Y.c-X.c))/((ld)(X.m-Y.m));
    }
    lli evaluate(lli x,line X){
        return X.m*x+X.c;
    }
    void addline(line X){
        if(STACK.size()==0){
            STACK.push_back(X);
            return;
        }
        if(STACK.size()==1){
            points.push_back(IntersectionOfLines(X,STACK.back()));
            STACK.push_back(X);
            return;
        }
        while(points.size()){
                line l1=STACK.back();  

                STACK.pop_back();
                line l2=STACK.back();  

                if(points.back()<IntersectionOfLines(l1,X)){
                    STACK.push_back(l1);
                    break;
                }
                else{
                    points.pop_back();
                }
        }
            points.push_back(IntersectionOfLines(STACK.back(),X));
            STACK.push_back(X);
    }
    lli FindBest(lli x){
        int id=lower_bound(points.begin(),points.end(),x)-points.begin();
        return evaluate(x,STACK[id]);
    }
};

class RMQv 

{
    public:
	struct node
    {
	int mn,mx,l,r; 
    };
	v32 h;
	vt <node> st;
	RMQv(v32 a)
	{
       h=a;
       st.resize(4*h.size());
       build(0,h.size()-1);
	}
	void build(int l,int r,int k=0)
	{
		st[k].l=l,st[k].r=r;
	    if(l==r)
		   {st[k].mx=st[k].mn=h[l];
             return;
		   }
	    build(l,(l+r)>>1,2*k+1);
	    build(((l+r)>>1)+1,r,2*k+2);
      st[k].mx=max(st[2*k+1].mx,st[2*k+2].mx); 
	}
	int maxquery(int l,int r,int k=0)
    {
       if(l>r)return -MAXN;
       int ll=st[k].l,rr=st[k].r,mid=(ll+rr)>>1;
       if(r<ll || l>rr)return -MAXN;
       if(ll>=l && rr<=r)
          return st[k].mx;
   	   int ans=-MAXN;   
   	   ans=maxquery(l,r,2*k+1);
   	   ans=max(ans,maxquery(l,r,2*k+2));
   	   return ans;     
    }
    void update(int id,int val,int k=0)
    {
        int l=st[k].l,r=st[k].r,mid=(l+r)>>1;
        if(id<l || id>r)return;
        if(l==r)
        {
            st[k].mx=val;
            return;
        }
        update(id,val,2*k+1);
        update(id,val,2*k+2);
        st[k].mx=max(st[2*k+1].mx,st[2*k+2].mx); 
    }
};

class LAZY 
{
   public:
   struct node{
    lli l,r,lazy=0;lli lazyval=0,sum=0;
    pair<lli,lli> maxel={-1,-MAXN};
    pair<lli,lli> minel={-1,MAXN};
   };	
   vt <node> st;v64 h;
   LAZY(v64 a)
   { 
   	  h=a;
   	  st.resize(4*h.size());
   	  cst(0,h.size()-1);
   }	
   void cst(int l,int r,int k=0)
   {
    st[k].l=l,st[k].r=r;
    if(l==r)
        { 
          st[k].sum=h[l];
          st[k].maxel={l,h[l]};
          st[k].minel={l,h[l]};    
          return;
        }
    cst(l,(l+r)/2,2*k+1);
    cst((l+r)/2+1,r,2*k+2);
    st[k].sum=st[2*k+1].sum+st[2*k+2].sum; 
    if(st[2*k+1].maxel.second>=st[2*k+2].maxel.second)st[k].maxel=st[2*k+1].maxel;
    else st[k].maxel=st[2*k+2].maxel;
    if(st[2*k+1].minel.second<=st[2*k+2].minel.second)st[k].minel=st[2*k+1].minel;
    else st[k].minel=st[2*k+2].minel;
   }
   void shift(int k)
   {
    st[k].sum+=(st[k].r-st[k].l+1)*st[k].lazyval;
    st[k].maxel.second+=st[k].lazyval;
    st[k].minel.second+=st[k].lazyval;
    if(st[k].l!=st[k].r){
      st[2*k+1].lazyval+=st[k].lazyval;
      st[2*k+2].lazyval+=st[k].lazyval;
      st[2*k+1].lazy=st[2*k+2].lazy=1;
    }
    st[k].lazyval=0;
    st[k].lazy=0;      
   }
   lli query(int l,int r,int k=0){
	if(st[k].lazy!=0)
       shift(k);
    int ll=st[k].l,rr=st[k].r,mid=(ll+rr)/2;
    if(l>rr || ll>r)return 0;
    if(ll>=l && rr<=r)
       return st[k].sum;
       return query(l,r,2*k+1)+query(l,r,2*k+2);     
   }
   pair<lli,lli> maxquery(int l,int r,int k=0)
   {
	   if(st[k].lazy!=0)
       shift(k);
     int ll=st[k].l,rr=st[k].r,mid=(ll+rr)/2;
     if(ll>r || l>rr)return {-1,-MAXN*1000000ll};
     if(ll>=l && rr<=r)
       return st[k].maxel;
       pair<lli,lli> ans=maxquery(l,r,2*k+1),ans2=maxquery(l,r,2*k+2);
       if(ans.second>=ans2.second)return ans;
       return ans2;
   }
   pair<lli,lli> minquery(int l,int r,int k=0)
   {
	   if(st[k].lazy!=0)
       shift(k);
       int ll=st[k].l,rr=st[k].r,mid=(ll+rr)/2;
       if(ll>r || l>rr)return {-1,MAXN*1000000ll};
       if(ll>=l && rr<=r) return st[k].minel;
       pair<lli,lli> ans=minquery(l,r,2*k+1),ans2=minquery(l,r,2*k+2);
       if(ans.second<=ans2.second)return ans;
       return ans2;     
   }
   void update(int l,int r,lli x,int k=0)
   {
	  if(l>r)
		return;
   int ll=st[k].l,rr=st[k].r,mid=(ll+rr)/2;
   if(ll>r || l>rr)return;
   if(ll>=l && rr<=r)
         {st[k].lazyval+=x;
          st[k].lazy=1;      
         return;}
         if(st[k].lazy!=0)
           shift(k);
        

      update(l,r,x,2*k+1);
      update(l,r,x,2*k+2);
      if(st[2*k+1].lazy!=0)
       shift(2*k+1);
       if(st[2*k+2].lazy!=0)
       shift(2*k+2);
    st[k].sum=st[2*k+1].sum+st[2*k+2].sum; 
    if(st[2*k+1].maxel.second>=st[2*k+2].maxel.second)st[k].maxel=st[2*k+1].maxel;
    else st[k].maxel=st[2*k+2].maxel;
    if(st[2*k+1].minel.second<=st[2*k+2].minel.second)st[k].minel=st[2*k+1].minel;
    else st[k].minel=st[2*k+2].minel;             
   }
};




template <typename T> 
void DEBUG_ARR(vt<T> a,char c)
{
	f(i,0,a.size())cout<<a[i]<<c;
	cout<<"\n";
}



lli power(lli x, lli y,lli m=mod) 
{
    lli res = 1;  
   
    while (y > 0) 
    { 
        if (y & 1) 
            res = (res*x)%m; 
        y = y>>1; 
        x = (x*x)%m;  
    }
    if(res<0)
       res+=m; 
    return res; 
}

lli fact[2000009];
lli ncr(lli n,lli r){
    lli ans=fact[n];
    if(r>n)return 1;
    if(r<0)return 0;
    if(n<0)return 0;
    ans=(ans*power(fact[n-r],mod-2))%mod;
    ans=(ans*power(fact[r],mod-2))%mod;
    return ans;
}
void normalize(lli &a,lli &b){
    if(a==0 && b==0)return;
    if(a<0){
        a=-a;
        b=-b;
    }
    else if(a==0){
        if(b<0)b=-b;
    }
    lli g=__gcd(abs(a),abs(b));
    if(g!=0){
        a/=g;
        b/=g;
    }
}

class merge_sort_tree
{
  public:
	lli cnt(lli x,vector <int> &arr)
    {
     lli n=arr.size();
     vector<int>::iterator low,high;
     low = lower_bound(arr.begin(), arr.end(), x);
     if (low == (arr.end()) || *low != x)
     return 0;
     high = upper_bound(low, arr.end(), x);
     return high - low;
    }
    lli get_last_smvalaller(vector<int>& v, int x)
    {
     lli first = 0, last = v.size()-1;
     while (first <= last)
     {
       lli mid = (first + last) / 2;
       if (v[mid] >= x)
       last = mid - 1;
       else
       first = mid + 1;
     }
  return first - 1 < 0 ? -1 : first - 1;
    }
	struct node
    {
      int l,r;
      vector <pair<int,int>> arr;
      v32 arr2;
    };
	v32 a;
    vt <node> st; 
	
    merge_sort_tree(v32 b)
    {
      st.resize(4*b.size());
      a=b;
      build(0,b.size()-1);
    }
     void build(int l,int r,int k=0)
      {
        st[k].l=l,st[k].r=r;
        for(int i=l;i<r+1;i++)
        st[k].arr.push_back({a[i],i});
        sort(st[k].arr.begin(),st[k].arr.end());
        f(i,0,st[k].arr.size())st[k].arr2.pb(st[k].arr[i].first);
        if(l==r)
        return;
        build(l,(l+r)/2,2*k+1);
        build((l+r)/2+1,r,2*k+2);
      }
    lli count_val_in_range(int l,int r,int t,int k=0)
    {
     if(l>r)return 0;
     int ll=st[k].l,rr=st[k].r,mid=(ll+rr)/2;
     if(ll>r || l>rr)return 0;
     if(ll>=l && rr<=r) return cnt(t,st[k].arr2);
     return count_val_in_range(l,r,t,2*k+1)+count_val_in_range(l,r,t,2*k+2);
    }
    lli count_vals_less_than_given_val(int l,int r,int t,int k=0)
    {
     if(l>r)return 0;
     int ll=st[k].l,rr=st[k].r,mid=(ll+rr)/2;
     if(l>rr || ll>r)return 0;
     if(ll>=l && rr<=r) return get_last_smvalaller(st[k].arr2,t)+1;
     lli ans=0;
     return count_vals_less_than_given_val(l,r,t,2*k+1)+count_vals_less_than_given_val(l,r,t,2*k+2);   
    }	
    int find(int l,int r,int x,int k=0)
    {
     if(l>r)return -1;
     int ll=st[k].l,rr=st[k].r,mid=(ll+rr)/2;
     if(l>rr || ll>r)return -1;
     if(ll>=l && rr<=r)
       { 
         int p=lower_bound(st[k].arr2.begin(), st[k].arr2.end(), x)-st[k].arr2.begin();
         if(p==st[k].arr2.size())return -1;
         if(st[k].arr2[p]==x)return st[k].arr[p].second;
         return -1;
       }
     int x2,y2;
     x2=find(l,r,x,2*k+1);
     y2=find(l,r,x,2*k+2);
     if(x2==-1)return y2;
     if(y2==-1)return x2;
     return x2;
    }
};
class matrix
{
public:
  v4096 m;
  v4096 I;
  matrix(v4096 x){
    m=x;
    I=x;
    f(i,0,m.size())I[i][i]=1;
    f(i,0,x.size())f(j,0,x.size())if(i!=j)I[i][j]=0;
  };
  v4096 multiply(v4096 m1,v4096 m2)
  {
    v4096 m3=m1;
    f(i,0,m2.size())
      {
          f(j,0,m2[0].size())
          {    
            m3[i][j]=0;
            f(k,0,m1[0].size()) m3[i][j]=(m3[i][j]+m1[i][k]*m2[k][j])%mod;
          }
      }
      return m3;
  }
  v4096 exp(lli p)
   {
    v4096 res;
   if(p==1)
      return m;
   if(p==0) return I;
      if(p%2==0)
      {
          res=exp(p/2);
          res=multiply(res,res);
      }
      else
      {
          res=exp(p/2);
          res=multiply(res,res);
          res=multiply(res,m);
      }
   return res;
   }
};
const int N=1e5+5;
v32 graph[N];
int parent[N];
int dist[N];
pair <int,int> non_dtree_edge={-1,-1};
void dfs(int u,int p){
    if(parent[u]!=-1){
        non_dtree_edge={u,p};
        return;
    }
    parent[u]=p;
    dist[u]=1+dist[p];
    for(auto x:graph[u])if(x!=p)dfs(x,u);
}


int main() 
{ 
    

    

    fastio;
    int t;
    

    t=1;
    

    

	while(t--){
        

        

        

        lli n,k,p;
        cin>>n>>k>>p;
        lli a[n],b[k];
        f(i,0,n)cin>>a[i];
        f(i,0,k)cin>>b[i];
        sort(a,a+n);
        sort(b,b+k);
        lli ans=((1ll)<<60);
        f(i,0,k-n+1){
            lli temp=abs(a[0]-b[i])+abs(p-b[i]);
            f(j,1,n){
                temp=max(temp,abs(a[j]-b[i+j])+abs(p-b[i+j]));
            }
            ans=min(ans,temp);
        }
        cout<<ans<<"\n";
        

    }   
    return 0; 	
}
