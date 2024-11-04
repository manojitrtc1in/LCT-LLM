#include<bits/stdc++.h>
#define ios std::ios::sync_with_stdio(false)
#define rep(i,a,n) for (int i=a;i<=n;i++)
#define per(i,n,a) for (int i=n;i>=a;i--)
#define repp(i,a,b) for(int i=a;i<b;i++)
#define mm(a,n) memset(a, n, sizeof(a))
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define il inline
#define int long long
#define ll long long
#define ull unsigned long long
#define MOD 1000000007
#define pi 3.14159265358979323
#define SZ(x) ((ll)(x).size())
#define debug(x) 		  cout<<#x<<": "<<x<<endl;
#define debug2(x,y)       cout<<#x<<": "<<x<<" | "<<#y<<": "<<y<<endl;
#define debug3(x,y,z)     cout<<#x<<": "<<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl;
#define debug4(a,b,c,d)   cout<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<endl;
#define debug5(a,b,c,d,e) cout<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<<": "<<e<<endl;
using namespace std;
const ll INF (0x3f3f3f3f3f3f3f3fll);
const int inf (0x3f3f3f3f);
template<typename T>void read(T &res){bool flag=false;char ch;while(!isdigit(ch=getchar()))(ch=='-')&&(flag=true);
for(res=ch-48;isdigit(ch=getchar());res=(res<<1)+(res<<3)+ch - 48);flag&&(res=-res);}
template<typename T>void Out(T x){if(x<0)putchar('-'),x=-x;if(x>9)Out(x/10);putchar(x%10+'0');}
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
ll lcm(ll a,ll b){return a*b/gcd(a,b);}
ll pow_mod(ll x,ll n,ll mod){ll res=1;while(n){if(n&1)res=res*x%mod;x=x*x%mod;n>>=1;}return res;}
ll fact_pow(ll n,ll p){ll res=0;while(n){n/=p;res+=n;}return res;}
ll mult(ll a,ll b,ll p){a%=p;b%=p;ll r=0,v=a;while(b){if(b&1){r+=v;if(r>p)r-=p;}v<<=1;if(v>p)v-=p;b>>=1;}return r;}
ll quick_pow(ll a,ll b,ll p){ll r=1,v=a%p;while(b){if(b&1)r=mult(r,v,p);v=mult(v,v,p);b>>=1;}return r;}
bool CH(ll a,ll n,ll x,ll t)
{ll r=quick_pow(a,x,n);ll z=r;for(ll i=1;i<=t;i++){r=mult(r,r,n);if(r==1&&z!=1&&z!=n-1)return true;z=r;}return r!=1;}
bool Miller_Rabin(ll n)
{if(n<2)return false;if(n==2)return true;if(!(n&1))return false;ll x=n-1,t=0;while(!(x&1)){x>>=1;t++;}
srand(time(NULL));ll o=8;for(ll i=0;i<o;i++){ll a=rand()%(n-1)+1;if(CH(a,n,x,t))return false;}return true;}
ll exgcd1(ll a,ll b,ll &x,ll &y){if(!b){x=1,y=0;return a;}ll t=exgcd1(b,a%b,y,x);y-=a/b*x;return t;}
ll get_inv(ll a,ll mod){ll x,y;ll d=exgcd1(a,mod,x,y);return d==1?(x%mod+mod)%mod:-1;}
void exgcd(ll a,ll b ,ll &x,ll &y){if(!b){x=1,y=0;return;}exgcd(b,a%b,x,y);ll t=x;x=y,y=t-(a/b)*y;}
ll INV(ll a,ll b){ll x,y;return exgcd(a,b,x,y),(x%b+b)%b;}
ll crt(ll x,ll p,ll mod){return INV(p/mod,mod)*(p/mod)*x;}
ll FAC(ll x,ll a,ll b)
{if(!x)return 1;ll ans=1;for(ll i=1;i<=b;i++)if(i%a)ans*=i,ans%=b;
ans=pow_mod(ans,x/b,b);for(ll i=1;i<=x%b;i++)if(i%a)ans*=i,ans%=b;return ans*FAC(x/a,a,b)%b;}
ll C(ll n,ll m,ll a,ll b)
{ll N=FAC(n,a,b),M=FAC(m,a,b),Z=FAC(n-m,a,b),sum=0,i;for(i=n;i;i=i/a)sum+=i/a;
for(i=m;i;i=i/a)sum-=i/a;for(i=n-m;i;i=i/a)sum-=i/a;return N*pow_mod(a,sum,b)%b*INV(M,b)%b*INV(Z,b)%b;}
ll exlucas(ll n,ll m,ll p)
{ll t=p,ans=0,i;for(i=2;i*i<=p;i++){ll k=1;while(t%i==0){k*=i,t/=i;}
ans+=crt(C(n,m,i,k),p,k),ans%=p;}if(t>1)ans+=crt(C(n,m,t,t),p,t),ans%=p;return ans % p;}

const int N = 5e5 + 10;
struct Edge{
	int nex , to;
}edge[N << 1];
int head[N] , tot;
int dep[N] , f[N][30] , sz[N];
void add_edge(int u , int v)
{
	edge[++ tot].nex = head[u];
	edge[tot].to = v;
	head[u] = tot;
}
void dfs(int u , int far)
{
	sz[u] = 1;
	dep[u] = dep[far] + 1;
	f[u][0] = far;
	for(int i = 1 ; (1 << i) <= dep[u] ; i ++)	
		f[u][i] = f[f[u][i - 1]][i - 1];
	for(int i = head[u] ; i ; i = edge[i].nex)
	{
		int v = edge[i].to;
		if(v == far) continue ;		
		dfs(v , u);
		sz[u] += sz[v];
	}
} 
int lca(int x , int y)
{
	if(dep[x] < dep[y]) swap(x , y);
	per(i , 20 , 0)
	{
		if(dep[f[x][i]] >= dep[y]) x = f[x][i];
		if(x == y) return x;
	}
	per(i , 20 , 0)
		if(f[x][i] != f[y][i])
			x = f[x][i] , y = f[y][i];
	return f[x][0];
}
int ans[N];

void init(int n)
{
	tot = 0;
	rep(i , 0 , n) 
	{
		head[i] = 0 , ans[i] = 0 , sz[i] = 0 , dep[i] = 0;
		rep(j , 0 , 21) f[i][j] = 0;
	}
}
signed main()
{
	ios;
	int n , T = 1;
	cin >> T;
	while(T --)
	{
		cin >> n;
		init(n + 1);
		int sum = n * (n - 1) / 2;
		rep(i , 1 , n - 1)
		{
			int u , v;
			cin >> u >> v;
			add_edge(u , v) , add_edge(v , u);
		}
		dfs(0 , 0);
		ans[0] = sum;
		int far_1 = -1;
		for(int i = head[0] ; i ; i = edge[i].nex)
		{
			int v = edge[i].to;
			if(lca(v , 1) == v) {
				far_1 = v;
			}
			ans[0] -= sz[v] * (sz[v] - 1) / 2;
		}
		ans[1] = (sz[0] - sz[far_1]) * sz[1];
		int L = 0 , R = 1;
		int SL = sz[0] - sz[far_1] , SR = sz[1];
		rep(i , 2 , n)
		{
			if(lca(i , L) != i && lca(i , L) != L && lca(i , L) != 0) break ;
			if(lca(i , R) != i && lca(i , R) != R && lca(i , R) != 0) break ; 
			
			if(lca(i , L) == i || lca(i , R) == i)
			{
				ans[i] = ans[i - 1];
			}
			else if(lca(i , R) == R)
			{	
				SR = sz[i] , R = i;
				ans[i] = SL * SR;
			}
			else if(lca(i , L) == L)
			{
				SL = sz[i] , L = i;
				ans[i] = SL * SR;
			}
			if(!ans[i]) break ;
		}
		int pre = sum;
		rep(i , 0 , n) {
			cout << pre - ans[i] << " ";
			pre = ans[i];
		}
		cout << '\n';
	}
	return 0;
}