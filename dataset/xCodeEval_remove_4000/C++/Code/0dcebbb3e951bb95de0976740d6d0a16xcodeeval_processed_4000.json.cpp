

























using namespace std;
using namespace __gnu_pbds; 
template <typename T> 
void id4(vt<T> a)
{
	f(i,0,a.size())cout<<a[i]<<" ";
	cout<<"\n";
}
 
int op(int a, int b){
  return __gcd(a,b);
};
 
inline int id2(int n) {
	int res = 0;
	while ((1 << res) < n) {
		res++;
	}
	return res;
}
 
class id1 {
	private:
		int n, lg;
		vector<int> v;
		vector<int> clz;
		vector<int> layers;
		vector<int> onLayer;
		vector< vector<int> > pref;
		vector< vector<int> > suf;
		vector< vector<int> > between;
		
		void build(int layer, int lBound, int rBound) {
			if (layer >= (int)layers.size()) {
				return;
			}
			int id0 = (layers[layer]+1) >> 1;
			int id5 = layers[layer] >> 1;
			int bSz = 1 << id0;
			int bCnt = 0;
			for (int l = lBound; l < rBound; l += bSz) {
				bCnt++;
				int r = min(l + bSz, rBound);
				pref[layer][l] = v[l];
				for (int i = l+1; i < r; i++) {
					pref[layer][i] = op(pref[layer][i-1], v[i]);
				}
				suf[layer][r-1] = v[r-1];
				for (int i = r-2; i >= l; i--) {
					suf[layer][i] = op(v[i], suf[layer][i+1]);
				}
				build(layer+1, l, r);
			}
			for (int i = 0; i < bCnt; i++) {
				int ans = 0;
				for (int j = i; j < bCnt; j++) {
					int add = suf[layer][lBound + (j << id0)];
					ans = (i == j) ? add : op(ans, add);
					between[layer][lBound + (i << id5) + j] = ans;
				}
			}
		}
	public:
		inline int query(int l, int r) {
			if (l == r) {
				return v[l];
			}
			if (l + 1 == r) {
				return op(v[l], v[r]);
			}
			int layer = onLayer[clz[l ^ r]];
			int id0 = (layers[layer]+1) >> 1;
			int id5 = layers[layer] >> 1;
			int lBound = (l >> layers[layer]) << layers[layer];
			int lBlock = ((l - lBound) >> id0) + 1;
			int rBlock = ((r - lBound) >> id0) - 1;
			int ans = suf[layer][l];
			if (lBlock <= rBlock) {
				ans = op(ans, between[layer][lBound + (lBlock << id5) + rBlock]);
			}
			ans = op(ans, pref[layer][r]);
			return ans;
		}
		
		id1( vector<int>& v)
			: n((int)v.size()), lg(id2(n)), v(v), clz(1 << lg), onLayer(lg+1) {
			clz[0] = 0;
			for (int i = 1; i < (int)clz.size(); i++) {
				clz[i] = clz[i >> 1] + 1;
			}
			int tlg = lg;
			while (tlg > 1) {
				onLayer[tlg] = (int)layers.size();
				layers.push_back(tlg);
				tlg = (tlg+1) >> 1;
			}
			for (int i = lg-1; i >= 0; i--) {
				onLayer[i] = max(onLayer[i], onLayer[i+1]);
			}
			pref.assign(layers.size(), vector<int>(n));
			suf.assign(layers.size(), vector<int>(n));
			between.assign(layers.size(), vector<int>(1 << lg));
			build(0, 0, n);
		}
};
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
class id3 

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
	id3(v32 a)
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
	    build(l,(l+r)/2,2*k+1);
	    build((l+r)/2+1,r,2*k+2);
        st[k].mx=max(st[2*k+1].mx,st[2*k+2].mx); 
	}
	int maxquery(int l,int r,int k=0)
    {
       if(l>r)return -MAXN;
       int ll=st[k].l,rr=st[k].r,mid=(ll+rr)/2;
       if(ll>=l && rr<=r)
          return st[k].mx;
   	   int ans=0;   
   	   if(!(r<ll || mid<l))
   	      ans=maxquery(l,r,2*k+1);
   	   if(!(r<mid+1 || rr<l))
   	          ans=max(ans,maxquery(l,r,2*k+2));
   	   return ans;     
    }
    void update(int id,int val,int k=0)
    {
        int l=st[k].l,r=st[k].r,mid=(l+r)/2;
        if(l==r)
        {
            st[k].mx=val;
            return;
        }
        if(id>=l && id<=mid)
        update(id,val,2*k+1);
        if(mid+1<= id && id<=r)
        update(id,val,2*k+2);
        st[k].mx=max(st[2*k+1].mx,st[2*k+2].mx); 
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
class id6
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
      vector <pair<int,int>> arr;
      v32 arr2;
    };
	v32 a;
    vt <node> st; 
	
    id6(v32 b)
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
     return cnt(t,st[k].arr2);
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
     return get_last_smaller(st[k].arr2,t)+1;
     lli ans=0;
     if(intersection(l,r,ll,mid)==1)
     ans+=count_vals_less_than_given_val(l,r,t,2*k+1,st);
     if(intersection(l,r,mid+1,rr)==1)
     ans+=count_vals_less_than_given_val(l,r,t,2*k+2,st);
     return ans;
    }	
    int find(int l,int r,int x,int k=0)
    {
     if(l>r)return -1;
     int ll=st[k].l,rr=st[k].r,mid=(ll+rr)/2;
     if(ll>=l && rr<=r)
       { 
         int p=lower_bound(st[k].arr2.begin(), st[k].arr2.end(), x)-st[k].arr2.begin();
         if(p==st[k].arr2.size())return -1;
         if(st[k].arr2[p]==x)return st[k].arr[p].second;
         return -1;
       }
       int ans=-1;
     if(intersection(l,r,ll,mid)==1)
     ans=find(l,r,x,2*k+1);
     if(ans==-1 && intersection(l,r,mid+1,rr)==1)
     ans=find(l,r,x,2*k+2);
     return ans;
    }
};
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
vt <string> mat(1000);
int n,m;
v32 graph[1000000];
int mark[1000000];
int dp[1000000];
int dx[]={0,0,-1,1};
int dy[]={1,-1,0,0};
v32 id7(1000000);
bool iscycle=0;
void dfs(int u){ 
  if(mark[u]==0)
  {
    mark[u]=1;
    id7[u]=1;
    for(auto x:graph[u]){
        if(!mark[x]) dfs(x);
        else if(id7[x])
          iscycle=1;
    }
  }
  id7[u]=0;
}
void solve(int u){
  for(auto x:graph[u]){
    if(mark[x]==0){
      mark[x]=1;
      solve(x);
      dp[u]=max(dp[x]+1,dp[u]);
    }
    else dp[u]=max(dp[u],1+dp[x]);
  }
}
int main() 
{ 
  fastio;
  cin>>n>>m;
  map <char,char> next;
  next.insert({'A','D'});
  next.insert({'D','I'});
  next.insert({'M','A'});
  next.insert({'I','M'});
  f(i,0,n)cin>>mat[i];
  f(i,0,n){
    f(j,0,m){
      f(k,0,4){
        int nx=i+dx[k],ny=j+dy[k];
        if(0<=nx && nx<=n-1 && 0<=ny && ny<=m-1 && next[mat[i][j]]==mat[nx][ny]){
            graph[m*i+j].pb(m*nx+ny);
        }
      }
    }
  }
  f(i,0,n){
    f(j,0,m){
      if(mark[m*i+j]==0){
        dfs(m*i+j);
        if(iscycle){
          cout<<"Poor Inna!\n";
          return 0;
        }
      }
    }
  }
  f(i,0,n)f(j,0,m)mark[m*i+j]=0;
  f(i,0,n)f(j,0,m)if(mat[i][j]=='A' && graph[m*i+j].size()==0){dp[m*i+j]=1;mark[m*i+j]=1;}
  f(i,0,n)f(j,0,m){
    if(mark[m*i+j]==0){
      mark[m*i+j]=1;
      solve(m*i+j);
    }
  }
  int ans=0;
  f(i,0,n)f(j,0,m)if(mat[i][j]=='D')ans=max(ans,dp[m*i+j]);
  if(ans/4==0){
    cout<<"Poor Dima!\n";
  }
  else cout<<ans/4;
  return 0; 	
}