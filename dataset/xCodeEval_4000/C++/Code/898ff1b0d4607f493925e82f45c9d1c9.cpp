#include <bits/stdc++.h>
#define lli long long int
#define pb push_back
#define mod 1000000007
#pragma GCC optimize ("-O2")
#define mod2 998244353
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
#define p_q priority_queue 
#define min_p_q priority_queue <int,vt <int>,greater <int>>
using namespace std;
 
class UnionFind 

{
  public: v32 p, rank;
  

  UnionFind(int N) { rank.assign(N, 1);
  p.assign(N, 0); for (int i = 0; i < N; i++) p[i] = i; }
  int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
  bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
  void unionSet(int i, int j) 
  {
  if (!isSameSet(i, j)) {
  

  int x = findSet(i), y = findSet(j);
  if (rank[x] > rank[y]) p[y] = x,rank[x]+=rank[y];
  

  else 
     {
     p[x] = y;
     rank[y]+=rank[x]; 
     }
  
  } 
 
  }   
};
class RMQ  

{
    public:
    struct node
    {
    int mn,mx,l,r; 
    };
    v32 h;
    vt <node> st;
 
    bool is_intersection(int l,int r,int ll,int rr)
    {
       if(r<ll || rr<l)
         return 0;
         return 1;
    }
    RMQ(v32 a)
    {
       h=a;
       st.resize(4*h.size());
       build(0,h.size()-1);
    }
    void build(int l,int r,int k=0)
    {
        st[k].l=l,st[k].r=r;
        if(l==r)
           {st[k].mx=st[k].mn=l;
             return;
           }
        build(l,(l+r)/2,2*k+1);
        build((l+r)/2+1,r,2*k+2);
        if(h[st[2*k+1].mn]<=h[st[2*k+2].mn])
        st[k].mn=st[2*k+1].mn;
        else st[k].mn=st[2*k+2].mn; 
        if(h[st[2*k+1].mx]>=h[st[2*k+2].mx])
        st[k].mx=st[2*k+1].mx;
        else st[k].mx=st[2*k+2].mx;
    }
    int minquery(int l,int r,int k=0)
    {
        if(l>r)return MAXN;
        int ll=st[k].l,rr=st[k].r,mid=(ll+rr)/2;
        if(ll>=l && rr<=r)
         return st[k].mn;
        int ans=l;   
        if(!(r<ll || mid<l))
           ans=minquery(l,r,2*k+1);
        if(!(r<mid+1 || rr<l))
         {if(h[ans]>h[minquery(l,r,2*k+2)]) 
           ans=minquery(l,r,2*k+2);}
        return ans;     
    }
    int maxquery(int l,int r,int k=0)
    {
       if(l>r)return -MAXN;
       int ll=st[k].l,rr=st[k].r,mid=(ll+rr)/2;
       if(ll>=l && rr<=r)
          return st[k].mx;
       int ans=l;   
       if(!(r<ll || mid<l))
          ans=maxquery(l,r,2*k+1);
       if(!(r<mid+1 || rr<l))
          {if(h[ans]<h[maxquery(l,r,2*k+2)])    
              ans=maxquery(l,r,2*k+2);}
       return ans;     
    }
    void update(int id,int val,int k=0)
    {
        int l=st[k].l,r=st[k].r,mid=(l+r)/2;
        if(l==r)
        {
            h[l]=val;
            return;
        }
        if(id>=l && id<=mid)
        update(id,val,2*k+1);
        if(mid+1<= id && id<=r)
        update(id,val,2*k+2);
        if(h[st[2*k+1].mn]<=h[st[2*k+2].mn])
        st[k].mn=st[2*k+1].mn;
        else st[k].mn=st[2*k+2].mn; 
        if(h[st[2*k+1].mx]>=h[st[2*k+2].mx])
        st[k].mx=st[2*k+1].mx;
        else st[k].mx=st[2*k+2].mx;
    }
};
class LAZY 

{
   public:
   struct node
   {
    int l,r,lazy=0;lli lazyval=0;
    lli sum=0;
   };   
   vt <node> st;v32 h;
   LAZY(v32 a)
   { 
      h=a;
      st.resize(4*h.size());
      cst(0,h.size()-1);
   }    
   int intersectiontype1(int l,int r,int ll,int rr)
   { 
        if(r<ll || rr<l)
        return 0;
        return 1;
   }
   void cst(int l,int r,int k=0)
   {
    st[k].l=l,st[k].r=r;
    if(l==r)
        { 
          st[k].sum=h[l];   
          return;
        }
    cst(l,(l+r)/2,2*k+1);
    cst((l+r)/2+1,r,2*k+2);
    st[k].sum=st[2*k+1].sum+st[2*k+2].sum;    
   }
   void shift(int k)
   {
   st[k].sum=(st[k].r-st[k].l+1)*st[k].lazyval;
   if(st[k].l!=st[k].r)
   {st[2*k+1].lazyval=st[k].lazyval;
   st[2*k+2].lazyval=st[k].lazyval;
   st[2*k+1].lazy=st[2*k+1].lazy=1;
   st[2*k+2].lazy=st[2*k+2].lazy=1;}
   st[k].lazyval=0;
   st[k].lazy=0;      
   }
   lli query(int l,int r,int k=0)
   {
    if(st[k].lazy!=0)
       shift(k);
   int ll=st[k].l,rr=st[k].r,mid=(ll+rr)/2;
   if(ll>=l && rr<=r)
       return st[k].sum;
       lli ans=0;   
       if(intersectiontype1(ll,mid,l,r)==1)
          ans=query(l,r,2*k+1);
       if(intersectiontype1(1+mid,rr,l,r)==1)
          ans+=query(l,r,2*k+2);
          return ans;     
   }
   void update(int l,int r,lli x,int k=0)
   {
    if(l>r)
        return;
   int ll=st[k].l,rr=st[k].r,mid=(ll+rr)/2;
   if(ll>=l && rr<=r)
         {st[k].lazyval=x;
          st[k].lazy=1;      
         return;}
         if(st[k].lazy!=0)
           shift(k);
           if(st[k].l==st[k].r) return;
   if(intersectiontype1(ll,mid,l,r)==1)
      update(l,r,x,2*k+1);
   if(intersectiontype1(mid+1,rr,l,r)==1)
      update(l,r,x,2*k+2);
      if(st[2*k+1].lazy!=0)
       shift(2*k+1);
       if(st[2*k+2].lazy!=0)
       shift(2*k+2);
    st[k].sum=st[2*k+1].sum+st[2*k+2].sum;           
   }
   int lower_bound(int l,int r,int val)
   {
    while(l!=r)
    {
      int mid=(l+r)/2;
      if(query(mid,mid)>=val)
        r=mid;
      else 
        {l=mid+1;
         if(mid+1<h.size())  
             if(query(mid+1,mid+1)>val)
             {
              l=mid;
              break;
             }
        }
    }
    return l;
   }
};
class span
{
  public:
    v32 a;
    span()
    {};
    v32 max_left_border_without_equality()
     {
    int n=a.size();
    v32 ta,al(n);
    f(i,0,n)
    {
      if(ta.size()==0)
        {
            ta.pb(i);
            al[i]=i;
        }
      else
      {
        while(a[i]>a[ta[ta.size()-1]]) {ta.pop_back();if(ta.size()==0)break;}
         if(ta.size()==0)
         {
            ta.pb(i);
            al[i]=0;    
         }
         else
         {
            al[i]=ta[ta.size()-1]+1;
            ta.pb(i);
         }
      }
    }
    return al; 
     }
    v32 max_left_border_with_equality()
     {
    int n=a.size();
    v32 ta,al(n);
    f(i,0,n)
    {
      if(ta.size()==0)
        {
            ta.pb(i);
            al[i]=i;
        }
      else
      {
        while(a[i]>=a[ta[ta.size()-1]]) {ta.pop_back();if(ta.size()==0)break;}
         if(ta.size()==0)
         {
            ta.pb(i);
            al[i]=0;    
         }
         else
         {
            al[i]=ta[ta.size()-1]+1;
            ta.pb(i);
         }
      }
    }
    return al; 
     }
    v32 min_left_border_without_equality()
     {
    int n=a.size();
    v32 ta,al(n);
    f(i,0,n)
    {
      if(ta.size()==0)
        {
            ta.pb(i);
            al[i]=i;
        }
      else
      {
        while(a[i]<a[ta[ta.size()-1]]) {ta.pop_back();if(ta.size()==0)break;}
         if(ta.size()==0)
         {
            ta.pb(i);
            al[i]=0;    
         }
         else
         {
            al[i]=ta[ta.size()-1]+1;
            ta.pb(i);
         }
      }
    } 
    return al;
     }
    v32 min_left_border_with_equality()
     {
    int n=a.size();
    v32 ta,al(n);
    f(i,0,n)
    {
      if(ta.size()==0)
        {
            ta.pb(i);
            al[i]=i;
        }
      else
      {
        while(a[i]<=a[ta[ta.size()-1]]) {ta.pop_back();if(ta.size()==0)break;}
         if(ta.size()==0)
         {
            ta.pb(i);
            al[i]=0;    
         }
         else
         {
            al[i]=ta[ta.size()-1]+1;
            ta.pb(i);
         }
      }
    } 
    return al;
     }
    v32 max_right_border_without_equality()
     {
    int n=a.size();
    reverse(a.begin(),a.end());
    v32 ans=max_left_border_without_equality();
    reverse(ans.begin(),ans.end());
    f(i,0,n)ans[i]=n-1-ans[i];
    reverse(a.begin(),a.end());
    return ans;
     }
    v32 max_right_border_with_equality()
     {
    int n=a.size();
    reverse(a.begin(),a.end());
    v32 ans=max_left_border_with_equality();
    reverse(ans.begin(),ans.end());
    f(i,0,n)ans[i]=n-1-ans[i];
    reverse(a.begin(),a.end());
    return ans;
     } 
    v32 min_right_border_without_equality()
     {
    int n=a.size();
    reverse(a.begin(),a.end());
    v32 ans=min_left_border_without_equality();
    reverse(ans.begin(),ans.end());
    f(i,0,n)ans[i]=n-1-ans[i];
    reverse(a.begin(),a.end());
    return ans;
     }
     v32 min_right_border_with_equality()
     {
    int n=a.size();
    reverse(a.begin(),a.end());
    v32 ans=min_left_border_with_equality();
    reverse(ans.begin(),ans.end());
    f(i,0,n)ans[i]=n-1-ans[i];
    reverse(a.begin(),a.end());
    return ans;
     }
 
};
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
    lli get_last_smaller(vector<int>& v, int x)
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
      vector <int> arr;
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
        st[k].arr.push_back(a[i]);
        sort(st[k].arr.begin(),st[k].arr.end());
        if(l==r)
        return;
        build(l,(l+r)/2,2*k+1);
        build((l+r)/2+1,r,2*k+2);
      } 
    bool intersection(int l,int r,int ll,int rr)
    {
      if(ll>r || l>rr)return 0;
      return 1;
    }
    lli count_val_in_range(int l,int r,int t,int k=0)
    {
     if(l>r)return 0;
     int ll=st[k].l,rr=st[k].r,mid=(ll+rr)/2;
     if(ll>=l && rr<=r)
     return cnt(t,st[k].arr);
     lli ans=0;
     if(intersection(l,r,ll,mid)==1)
     ans+=count_val_in_range(l,r,t,2*k+1);
     if(intersection(l,r,mid+1,rr)==1)
     ans+=count_val_in_range(l,r,t,2*k+2);
     return ans;
    }
    lli count_vals_less_than_given_val(int l,int r,int t,int k,vector<node> &st)
    {
     if(l>r)return 0;
     int ll=st[k].l,rr=st[k].r,mid=(ll+rr)/2;
     if(ll>=l && rr<=r)
     return get_last_smaller(st[k].arr,t)+1;
     lli ans=0;
     if(intersection(l,r,ll,mid)==1)
     ans+=count_vals_less_than_given_val(l,r,t,2*k+1,st);
     if(intersection(l,r,mid+1,rr)==1)
     ans+=count_vals_less_than_given_val(l,r,t,2*k+2,st);
     return ans;
    }   
};
void DEBUG_ARR(v32 a)
{
    f(i,0,a.size())cout<<a[i]<<" ";
    cout<<"\n";
}
lli tmod(lli x,lli m){return (x%m+m)%m;}

lli power(lli x, lli y) 
{
    lli res = 1;  
   
    while (y > 0) 
    { 
        if (y & 1) 
            res = (res*x)%mod; 
        y = y>>1; 
        x = (x*x)%mod;  
    }
    if(res<0)
       res+=mod; 
    return res; 
}
lli modInverse(lli a, lli m) 
{
    lli m0 = m; 
    lli y = 0, x = 1; 
    if (m == 1) 
      return 0; 
  
    while (a > 1) 
    {  
        lli q = a / m; 
        lli t = m; 
        m = a % m, a = t; 
        t = y; 
        y = x - q * y; 
        x = t; 
    }  
    if (x < 0) 
       x += m0; 
    return x; 
} 
int cnt[200001];
int smallest_correct_prefix(int l,int r,int ccnt[],int knight_color [],int m)
{
    int mid=(l+r)/2;
    f(i,1,m+1)cnt[i]=0;
    f(i,0,mid+1)cnt[knight_color[i]]++;
    if(l==r)return l;
    f(i,1,m+1)if(cnt[i]<ccnt[i])return smallest_correct_prefix(mid+1,r,ccnt,knight_color,m);
    return smallest_correct_prefix(l,mid,ccnt,knight_color,m);
}
int main() 
{ 
  fastio;
  int n,m;cin>>n>>m;
  int knight_color[n];f(i,0,n)cin>>knight_color[i];
  int ccnt[m+1];f(i,0,m)cin>>ccnt[i+1];
  int sum=0;f(i,1,m+1)sum+=ccnt[i];
  int l=0,r;
  int ans=MAXN;
  f(i,0,n)cnt[knight_color[i]]++;
  f(i,1,m+1){
    if(cnt[i]<ccnt[i]){
        cout<<-1;
        return 0;
    }
  }
   r=smallest_correct_prefix(0,n-1,ccnt,knight_color,m);
  int bada_sum=0;
  f(i,1,m+1)bada_sum+=cnt[i];
  while(r!=n)
  {
     while(cnt[knight_color[l]]>=ccnt[knight_color[l]]+1){
        cnt[knight_color[l]]--;
        bada_sum--;
        l++;
     }
     ans=min(ans,bada_sum-sum);
     r++;if(r==n)break;
     cnt[knight_color[r]]++;
     bada_sum++;
  }
  cout<<ans;  
  return 0;     
}