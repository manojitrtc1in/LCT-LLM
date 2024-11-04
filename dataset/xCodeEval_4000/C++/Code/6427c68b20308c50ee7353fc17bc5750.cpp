#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define mod 1000000007 

#include<string.h>
#define inf 1000000000000000000
#define maxn 200002
typedef pair<ll,ll> pll;
typedef pair<int,int> pint;
#define endl '\n'
#define mapint_iterator map<int,int> :: iterator
#define mapll_iterator map<ll,ll> :: iterator
#define setint_iterator set<int> :: iterator
#define setll_iterator set<ll> :: iterator
#define setpint_iterator set<pint> :: iterator
#define setpll_iterator set<pll> :: iterator
#define trace(x) cout<<#x<<": "<<x<<" "<<endl
#define trace2(x,y) cout<<#x<<": "<<x<<" | "<<#y<<": "<<y<<endl
#define trace3(x,y,z) cout<<#x<<":" <<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl
#define trace4(a,b,c,d) cout<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<endl
#define cout1(a) cout<<a<<endl
#define cout2(a,b) cout<<a<<" "<<b<<endl
#define cout3(a,b,c) cout<<a<<" "<<b<<" "<<c<<endl
#define cout4(a,b,c,d) cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl
#define vcout(v,i) cout<<v[i].fi<<" "<<v[i].se<<endl
typedef priority_queue<ll,vector<ll>,greater<ll> > pqset;
typedef priority_queue<pint,vector<pint>,greater<pint> > pqset_ll;
#define pb push_back
#define fi first
#define vi vector<ll>
#define vv vector<vector<ll> > 
#define vb vector<bool> 
#define vp vector<pll>
#define se second
#define mp make_pair
#define acc (ios::sync_with_stdio(false),cin.tie(0))
#define rep(i,n) for(ll i=0;i<n;i++)
#define per(i,n) for(ll i=n-1;i>=0;i--)
#define rep1(i,n) for(ll i=1;i<=n;i++)
#define per1(i,n) for(ll i=n;i>0;i--)
#define repeat(i,start,n) for(ll i=start;i<n;i++)
#define print(a,n) for(ll i=0;i<n;i++){ cout<<a[i]<<" ";}
#define all(v) v.begin(),v.end()
ll ll_max(ll a,ll b,ll c){return max(a,max(b,c));}
int int_max(int a,int b,int c){return max(a,max(b,c));}
ll ll_min(ll a,ll b,ll c){return min(a,min(b,c));}
int int_min(int a,int b,int c){return min(a,min(b,c));}
ll max(int a,ll b){ return max((ll)a,b);}
ll min(int a,ll b){ return min((ll)a,b);}
ll min(ll a,int b){ return min(a,(ll)b);}
ll max(ll a,int b){ return max(a,(ll)b);}
bool prime[maxn];
ll fact[maxn];
ll Tree[maxn];
pll Tree1[maxn];
ll dx[]={0,0,1,-1};
ll dy[]={1,-1,0,0};
struct Tnode{ long long sum, maxprefix, maxsuffix, maxsum; } T[4*maxn];
Tnode combine(Tnode &node1, Tnode &node2){
    Tnode resnode;
    resnode.sum = node1.sum + node2.sum;
    resnode.maxprefix = max(node1.maxprefix, node1.sum + node2.maxprefix);
    resnode.maxsuffix = max(node1.maxsuffix + node2.sum, node2.maxsuffix);
    resnode.maxsum = max((node1.maxsuffix + node2.maxprefix), max(node1.maxsum , node2.maxsum));
    return resnode;
}
void BuildTree(int v,int tl,int tr,ll a[]){
    if(tl==tr){
        T[v] = { a[tl], a[tl], a[tl], a[tl] }; 

        return;
    }
    int tm = (tl+tr)/2;
    BuildTree(2*v+1, tl, tm,a);
    BuildTree(2*v+2, tm+1, tr,a);
    T[v] = combine(T[2*v+1],T[2*v+2]);
}
void modify(int v, int tl, int tr, int x, ll val,ll a[]) {
    if(x < tl || tr < x) return;
    if(tl==tr){
        T[v]={ val, val, val, val };
        return;
    }
    int tm=(tl+tr)/2;
    modify(2*v+1, tl, tm, x, val,a);
    modify(2*v+2, tm+1, tr, x, val,a);
    T[v] = combine(T[2*v+1],T[2*v+2]);
}
Tnode getquery(int v,int tl,int tr,int L,int R) {
    if(R < tl || tr < L||L>R) return {0,-inf,-inf,-inf};
    if(L <= tl && tr <= R) {
        return T[v];
    }
    int tm = (tl+tr)/2;
    Tnode node1 = getquery(2*v+1, tl, tm, L, R);
    Tnode node2 = getquery(2*v+2, tm+1, tr, L, R);
    return combine(node1, node2);
}
void build_max(int node,int start,int end,ll a[]){
	if(start==end){
		Tree[node]=a[start];
		return;
	}
	int mid=((start+end)>>1);
	build_max(2*node+1,start,mid,a);
	build_max(2*node+2,mid+1,end,a);
	

	Tree[node]=max(Tree[2*node+1],Tree[2*node+2]);
}
void update_max(int node,int start,int end,ll a[],int i,ll val){
	if(start==end){
		Tree[node]=val;
		return;
	}
	int mid=((start+end)>>1);
	if(i<=mid)
		update_max(2*node+1,start,mid,a,i,val);
	else
		update_max(2*node+2,mid+1,end,a,i,val);
	

	Tree[node]=max(Tree[2*node+1],Tree[2*node+2]);
}
ll query_max(int node,int start,int end,int l,int r){ 
	if(start>end||end<l||start>r)
		return 0;

	if(start>=l&&end<=r)
		return(Tree[node]);
	int mid = (start+end)/2 ; 
	ll p1 = query_max(node*2+1, start, mid, l,r);
	ll p2 = query_max(node*2+2, mid+1, end , l,r);
	return max(p1,p2);
}
void build_min(int node,int start,int end,ll a[]){
	if(start==end){
		Tree1[node]={a[start],start};
		return;
	}
	int mid=((start+end)>>1);
	build_min(2*node+1,start,mid,a);
	build_min(2*node+2,mid+1,end,a);
	

	Tree1[node]=min(Tree1[2*node+1],Tree1[2*node+2]);
}
void update_min(int node,int start,int end,ll a[],int i,ll val){
	if(start==end){
		Tree1[node]={val,i};
		return;
	}
	int mid=((start+end)>>1);
	if(i<=mid)
		update_min(2*node+1,start,mid,a,i,val);
	else
		update_min(2*node+2,mid+1,end,a,i,val);
	

	Tree1[node]=min(Tree1[2*node+1],Tree1[2*node+2]);
}
pll query_min(int node,int start,int end,int l,int r){ 
	if(start>end||end<l||start>r)
		return {1e9,1e9};

	if(start>=l&&end<=r)
		return(Tree1[node]);
	int mid = (start+end)/2 ; 
	pll p1 = query_min(node*2+1, start, mid, l,r);
	pll p2 = query_min(node*2+2, mid+1, end , l,r);
	return min(p1,p2);
}
void dfs_connected(int i,vector<int> v[],bool visited[],vector<int> &v3){
	visited[i]=true;
	v3.pb(i);
	rep(j,v[i].size()){
		if(visited[v[i][j]]==false){
			visited[v[i][j]]=true;
			dfs_connected(v[i][j],v,visited,v3);
		}
	}
}
void dfs_connected1(int i,vector<int> v[],bool visited[],stack<int> &s){
	visited[i]=true;
	rep(j,v[i].size()){
		if(visited[v[i][j]]==false){
			visited[v[i][j]]=true;
			dfs_connected1(v[i][j],v,visited,s);
		}
	}
	s.push(i);
}
void StronglyConnectedComponents(vector<int> v[],vector<int> v1[],vector<vector<int> > &v2,int n){
	stack<int> s;
	bool visited1[n+1]={false};
	repeat(i,1,n+1){
		if(visited1[i]==false)
			dfs_connected1(i,v,visited1,s);
	}
	bool visited[n+1]={0};
	while(!s.empty()){
		while(visited[s.top()]){
			s.pop();
			if(s.size()==0)
				return;
		}
		int a=s.top();
		s.pop();
		vector<int> v3;
		dfs_connected(a,v1,visited,v3);
		v2.pb(v3);
	}
}
void sieve(ll n){
    memset(prime,true,sizeof(prime));
	prime[1]=false; 
    for (ll p=2;p*p<=n;p++){
        if (prime[p]){  
            for (ll i=p*p;i<=n;i+=p)
                prime[i]=false;
        }
    }
}
ll phi(ll n){
	ll result=n;
	for(ll i=2;i*i<=n;i++){
		if(n%i==0){
			while(n%i==0)
				n/=i;
			result-=(result)/i;
		}
	}
	if(n>1)
		result-=result/n;
	return result;
}
bool compare_string(pair<string,int> a,pair<string,int> b){
	if(a.fi.size()<b.fi.size())
		return true;
	else if(a.fi.size()==b.fi.size()){
		if(a.fi<b.fi)
			return true;
		else
			return false;
	}
	else
		return false;
}
bool compare_string1(string a,string b){
	if(a.size()<b.size())
		return true;
	else if(a.size()==b.size()){
		if(a<b)
			return true;
		else
			return false;
	}
	else
		return false;
}
bool compare(pair<ll,ll> a,pair<ll,ll> b){
	if(a.first<b.first)
		return true;
	else if(a.first==b.first){
		if(a.se>b.se)
			return true;
		else
			return false;
	}
	else
		return false;
}
bool sortbysec(const pair<int,int> &a,const pair<int,int> &b){
	if(a.se==b.se)
		return a.fi<b.fi;
    return (a.second<b.second); 
}
ll power(ll a,ll b){
	if(a==1)
		return 1;
	if(b==0)
		return 1;
	ll c=power(a,b/2);
	ll res=1;
	if(b%2){
		res=(c*c)%mod;
		res*=a;
		res%=mod;
	}
	else
		res=((c*c)%mod);
	return res;
}
ll pow(int a,int b){
	if(a==1)
		return 1;
	if(b==0)
		return 1;
	ll c=pow(a,b/2);
	ll res=1;
	if(b%2){
		res=(c*c);
		res*=(ll)a;
	}
	else
		res=((c*c));
	return res;
}
void dfs_topological(int i,vector<int> v[],bool visited[],int finish[],int &t){
	visited[i]=true;
	rep(j,v[i].size()){
		if(visited[v[i][j]]==false){
			visited[v[i][j]]=true;
			dfs_topological(v[i][j],v,visited,finish,++t);
		}
	}
	finish[i]=(++t);
}
void topologicalSort(vector<int> v[],stack<int> &s,int n){
	int finish[n+1]={0};
	int t=0;
	bool visited[n+1]={0};
	repeat(i,1,n+1){
		if(visited[i]==false)
			dfs_topological(i,v,visited,finish,t);
	}
	vector<pint> v1;
	repeat(i,1,n+1)
		v1.pb({finish[i],i});
	sort(v1.begin(),v1.end());
	rep(i,v1.size())
		s.push(v1[i].se);
}
void bfs(vector<int> v[],int o,int n,int dp[]){
	queue<int> q;
	q.push(o);
	dp[o]=0;
	bool visited[n+1]={0};
	visited[o]=true;
	while(q.empty()==false){
		int a=q.front();
		q.pop();
		for(int i=0;i<v[a].size();i++){
			if(visited[v[a][i]]==false){
				visited[v[a][i]]=true;
				q.push(v[a][i]);
				dp[v[a][i]]=dp[a]+1;
			}
		}
	}
}
void multi_bfs(vector<int> v[],vector<int> v1,int n,int dp[]){
	queue<int> q;
	bool visited[n+1]={0};
	rep(i,v1.size()){
		q.push(v1[i]);
		dp[v1[i]]=0;
		visited[v1[i]]=true;
	}
	while(q.empty()==false){
		int a=q.front();
		q.pop();
		for(int i=0;i<v[a].size();i++){
			if(visited[v[a][i]]==false){
				visited[v[a][i]]=true;
				q.push(v[a][i]);
				dp[v[a][i]]=dp[a]+1;
			}
		}
	}
}
ll modInv(ll a){return power(a,mod-2)%mod;}
ll ncr(ll n,ll r){
	ll b=modInv(fact[n-r]);
	ll c=modInv(fact[r]);
	ll a=fact[n]*b;
	a%=mod;
	a*=c;
	a%=mod;
	return a;
}
int binary_Search(int l,int h){
	int low=l;int high=h;int ans=h;
	while(low <= high){
        int mid = (low+high)/2;
        if(1){
            ans = mid;
            high = mid-1;
        }else low = mid+1;
    }
    return ans;
}
void dfs(int i,vector<int> v[],bool visited[],int dp[],vector<pint> &v3,int u){
	visited[i]=true;
	rep(j,v[i].size()){
		if(visited[v[i][j]]==false&&dp[v[i][j]]==u){
			visited[v[i][j]]=true;
			v3.pb({min(i,v[i][j]),max(i,v[i][j])});
			dfs(v[i][j],v,visited,dp,v3,u-1);
		}
	}
}
void factorial(ll n){
	fact[0]=1;
	for(ll i=1;i<=n;i++){
		fact[i]=fact[i-1]*i;
		fact[i]%=mod;
	}
}
ll lcm(ll a,ll b){return a*b/__gcd(a,b);}
int find(int x,int a[]){
	if(a[x]==-1)
		return x;
	return find(a[x],a);
}
void dfs_array(int i,int j,int count,bool visited[][1000],int pos[],queue<pint> &q,int n,int m,int k){
	if(count==0){
		q.push({i,j});
		visited[i][j]=1;
		return;
	}
	pos[k]++;
	visited[i][j]=1;
	rep(l,4){
		int h=i+dx[l];
		int h1=j+dy[l];
		if(h<0||h1<0||h>=n||h1>=m)
			continue;
		if(visited[h][h1])
			continue;
		if(k==0)
			cout3(h,h1,count);
		visited[h][h1]=1;
		dfs_array(h,h1,count-1,visited,pos,q,n,m,k);
	}
}
void insert(int x,int y,int a[],int size[]){
	if(size[x]>=size[y]){
		size[y]+=size[x]+1;
		a[x]=y;
		return;
	}
	size[x]+=size[y]+1;
	a[y]=x;
}
string convert_to_bit(ll a,int bit){
	string s;
	while(a>0){
		s+=(a%2)+48;
		a/=2;
	}
	while(s.size()<bit)
		s+='0';
	reverse(s.begin(),s.end());
	return s;
}
void map_insertrange(pll a1,map<ll,ll> &mp){
	ll a=a1.first;
	mapll_iterator it=mp.upper_bound(a);
	if(it==mp.end())
		mp[a]=a1.se;
	else if(it->fi<=a1.se){
		mp[a]=max(a1.se,it->se);
		mp.erase(it);
	}
	it=mp.lower_bound(a);
	if(it!=mp.begin()){
		it--;
		if(it->se>=a-1){
			mp[it->fi]=mp[a];
			mp.erase(a);
		}
	}
}
bool map_checkrange(ll a,map<ll,ll> &mp){
	mapll_iterator it=mp.upper_bound(a);
	if(it==mp.begin())
		return false;
	it--;
	if(a>=(it->fi)&&a<=(it->se))
		return true;
	return false;
}












int add(int a, int b) {
	a += b;
	if (a >= mod) a -= mod;
	if (a < 0) a += mod;
	return a;
}

int mul(int a, int b) {
	return a * 1ll * b % mod;
}

vector<ll> gao(vector<int> a) {
    int n = a.size();
    vector<ll> res(n + 1);
    int i = 0;
    while (i < n) {
        if (a[i] == 0) {
            i++;
            continue;
        }

        int j = i;
        while (j < n && a[j] == 1) {
            j++;
        }
        for (int len = 1; len <= j - i; len++) {
            res[len] += j - i - len + 1;
        }
        i = j;
    }

    return res;
}

ll isPowerof2(ll x) 
{ 
    return (x && !(x & x-1)); 
} 

ll dsu[101];
ll get_par(ll a){
	if(a==dsu[a]) return a;
	return dsu[a]=get_par(dsu[a]);
}
void unite(ll a,ll b){
	ll pa,pb;
	pa= get_par(a);
	pb= get_par(b);
	dsu[pb] =pa;
}

void solve()
{
	ll n;
	cin>>n;
	vi a(n-1),b(n-1),t(n);
	rep(i,n-1)
	{
		cin>>a[i];
	}
	rep(i,n-1)
	{
		cin>>b[i];
	}
	bool f=false;
	for(ll i=0;i<4;i++)
	{
		t[0] = i;
		for(ll j=1;j<n;j++)
		{
			f=false;
			for(ll jj=0;jj<4;jj++)
			{
				if(((t[j-1]|jj)==a[j-1])&&((t[j-1]&jj)==b[j-1]))
				{
					t[j] = jj;
					f=true;
					break;
				}
			}
			if(!f) break;
		}
		if(f) break;
	}
	if(f)
	{
		cout<<"YES"<<endl;
		print(t,n);
		cout<<endl;
	}
	else
	{
		cout<<"NO"<<endl;
	}
	return;
}
int main()
{
	acc;
    ll t=1;
	while(t--)
	{
    	solve();
    }
}