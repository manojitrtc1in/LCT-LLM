#include<bits/stdc++.h>
#define ios std::ios::sync_with_stdio(false)
#define sd(n) scanf("%d",&n)
#define sdd(n,m) scanf("%d%d",&n,&m)
#define sddd(n,m,k) scanf("%d%d%d",&n,&m,&k)
#define pd(n) printf("%d\n", (n))
#define pdd(n,m) printf("%d %d\n", n, m)
#define pld(n) printf("%lld\n", n)
#define pldd(n,m) printf("%lld %lld\n", n, m)
#define sld(n) scanf("%lld",&n)
#define sldd(n,m) scanf("%lld%lld",&n,&m)
#define slddd(n,m,k) scanf("%lld%lld%lld",&n,&m,&k)
#define sf(n) scanf("%lf",&n)
#define sff(n,m) scanf("%lf%lf",&n,&m)
#define sfff(n,m,k) scanf("%lf%lf%lf",&n,&m,&k)
#define rep(i,a,n) for (int i=a;i<=n;i++)
#define per(i,n,a) for (int i=n;i>=a;i--)
#define mm(a,n) memset(a, n, sizeof(a))
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define il inline
#define ll long long
#define lson rt << 1
#define rson rt << 1 | 1
#define MOD 1000000007
#define pi 3.14159265358979323
#define debug(x) 			  cout <<#x<<": "<<x<<endl
#define debug2(x, y)          cout <<#x<<": "<<x<<" | "<<#y<<": "<<y<<endl;
#define debug3(x, y, z)       cout <<#x<<": "<<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl;
#define debug4(a, b, c, d)    cout <<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<endl;
using namespace std;
const ll INF (0x3f3f3f3f3f3f3f3fll);
const int inf (0x3f3f3f3f);
template<typename T>void read(T &res)
{
	bool flag=false;
	char ch;
	while(!isdigit(ch=getchar()))(ch=='-')&&(flag=true);
	for(res=ch-48; isdigit(ch=getchar()); res=(res<<1)+(res<<3)+ch - 48);
	flag&&(res=-res);
}
template<typename T>void Out(T x)
{
	if(x<0)putchar('-'),x=-x;
	if(x>9)Out(x/10);
	putchar(x%10+'0');
}
ll gcd(ll a,ll b)
{
	return b?gcd(b,a%b):a;
}
ll lcm(ll a,ll b)
{
	return a*b/gcd(a,b);
}
ll pow_mod(ll x,ll n,ll mod)
{
	ll res=1;
	while(n)
	{
		if(n&1)res=res*x%mod;
		x=x*x%mod;
		n>>=1;
	}
	return res;
}
ll fact_pow(ll n,ll p)
{
	ll res=0;
	while(n)
	{
		n/=p;
		res+=n;
	}
	return res;
}
ll mult(ll a,ll b,ll p)
{
	a%=p;
	b%=p;
	ll r=0,v=a;
	while(b)
	{
		if(b&1)
		{
			r+=v;
			if(r>p)r-=p;
		}
		v<<=1;
		if(v>p)v-=p;
		b>>=1;
	}
	return r;
}
ll quick_pow(ll a,ll b,ll p)
{
	ll r=1,v=a%p;
	while(b)
	{
		if(b&1)r=mult(r,v,p);
		v=mult(v,v,p);
		b>>=1;
	}
	return r;
}
bool CH(ll a,ll n,ll x,ll t)
{
	ll r=quick_pow(a,x,n);
	ll z=r;
	for(ll i=1; i<=t; i++)
	{
		r=mult(r,r,n);
		if(r==1&&z!=1&&z!=n-1)return true;
		z=r;
	}
	return r!=1;
}
bool Miller_Rabin(ll n)
{
	if(n<2)return false;
	if(n==2)return true;
	if(!(n&1))return false;
	ll x=n-1,t=0;
	while(!(x&1))
	{
		x>>=1;
		t++;
	}
	srand(time(NULL));
	ll o=8;
	for(ll i=0; i<o; i++)
	{
		ll a=rand()%(n-1)+1;
		if(CH(a,n,x,t))return false;
	}
	return true;
}

const int N = 2e5 + 10;
int a[N] , vis[N] , ans[N];
int n;
int dfs(int now)
{
	vis[now] = 1;
	int nex1 = now + a[now];
	int nex2 = now - a[now];
	if(nex1 <= n)
	{
		if((a[now] + a[nex1]) & 1)
		{
			ans[now] = 1;
			if(!vis[nex1])
				dfs(nex1);

			return 1;
		}
		else
		{
			if(vis[nex1])
				ans[now] = min(ans[now] , ans[nex1] + 1);
			else
			{
				vis[nex1] = 1;
				int ha = dfs(nex1);
				ans[now] = min(ha + 1 , ans[now]);
			}
		}
	}
	if(nex2 >= 1)
	{
		if((a[now] + a[nex2]) & 1)
		{
			ans[now] = 1;
			if(!vis[nex2])
				dfs(nex2);
			return 1;
		}
		else
		{
			if(vis[nex2])
				ans[now] = min(ans[now] , ans[nex2] + 1);
			else
			{
				int ha = dfs(nex2);
				ans[now] = min(ha + 1 , ans[now]);
			}
		}
	}
	return ans[now];
}
int dfs1(int now)
{
	vis[now] = 1;
	int nex2 = now + a[now];
	int nex1 = now - a[now];
	if(nex1 >= 1)
	{
		if((a[now] + a[nex1]) & 1)
		{
			ans[now] = 1;
			if(!vis[nex1])
				dfs(nex1);

			return 1;
		}
		else
		{
			if(vis[nex1])
				ans[now] = min(ans[now] , ans[nex1] + 1);
			else
			{
				vis[nex1] = 1;
				int ha = dfs(nex1);
				ans[now] = min(ha + 1 , ans[now]);
			}
		}
	}
	if(nex2 <= n)
	{
		if((a[now] + a[nex2]) & 1)
		{
			ans[now] = 1;
			if(!vis[nex2])
				dfs(nex2);
			return 1;
		}
		else
		{
			if(vis[nex2])
				ans[now] = min(ans[now] , ans[nex2] + 1);
			else
			{
				int ha = dfs(nex2);
				ans[now] = min(ha + 1 , ans[now]);
			}
		}
	}
	return ans[now];
}
int main()
{
	ios;
	rep(i , 1 , N - 10)
	ans[i] = inf;
	cin >> n;
	rep(i , 1 , n)
	cin >> a[i];
	rep(i , 1 , n)
	{
		if(!vis[i])
			dfs(i);
	}
	mm(vis , 0);
	per(i , n , 1)
	{
		if(!vis[i])
			dfs(i);
	}
	mm(vis , 0);
	rep(i , 1 , n)
	{
		if(!vis[i])
			dfs1(i);
	}
	mm(vis , 0);
	per(i , n , 1)
	{
		if(!vis[i])
			dfs1(i);
	}
	mm(vis , 0);
	rep(i , 1 , n)
	if(!vis[i])
		dfs(i);
	mm(vis , 0);
	rep(i , 1 , n)
	if(!vis[i])
		dfs(i);
	mm(vis , 0);
	rep(i , 1 , n)
	if(!vis[i])
		dfs(i);
	mm(vis , 0);
	rep(i , 1 , n)
	if(!vis[i])
		dfs1(i);
	mm(vis , 0);
	rep(i , 1 , n)
	if(!vis[i])
		dfs1(i);
	rep(i , 1 , n)
	if(!vis[i])
		dfs1(i);

	mm(vis , 0);
	rep(i , 1 , n)
	if(!vis[i])
		dfs(i);
	mm(vis , 0);
	rep(i , 1 , n)
	if(!vis[i])
		dfs(i);
	mm(vis , 0);
	rep(i , 1 , n)
	if(!vis[i])
		dfs(i);
	mm(vis , 0);
	rep(i , 1 , n)
	if(!vis[i])
		dfs(i);
	mm(vis , 0);
	rep(i , 1 , n)
	if(!vis[i])
		dfs(i);
	mm(vis , 0);
	rep(i , 1 , n)
	if(!vis[i])
		dfs(i);
	mm(vis , 0);
	rep(i , 1 , n)
	if(!vis[i])
		dfs(i);
	mm(vis , 0);
	rep(i , 1 , n)
	if(!vis[i])
		dfs(i);
	mm(vis , 0);
	rep(i , 1 , n)
	if(!vis[i])
		dfs(i);
	mm(vis , 0);
	rep(i , 1 , n)
	if(!vis[i])
		dfs(i);
	mm(vis , 0);
	rep(i , 1 , n)
	if(!vis[i])
		dfs(i);
	mm(vis , 0);
	rep(i , 1 , n)
	if(!vis[i])
		dfs(i);
	mm(vis , 0);
	rep(i , 1 , n)
	if(!vis[i])
		dfs(i);
	mm(vis , 0);
	rep(i , 1 , n)
	if(!vis[i])
		dfs(i);
	mm(vis , 0);
	rep(i , 1 , n)
	if(!vis[i])
		dfs(i);
	mm(vis , 0);
	rep(i , 1 , n)
	if(!vis[i])
		dfs(i);
	mm(vis , 0);
	rep(i , 1 , n)
	if(!vis[i])
		dfs(i);
	mm(vis , 0);
	rep(i , 1 , n)
	if(!vis[i])
		dfs(i);

	mm(vis , 0);
	rep(i , 1 , n)
	if(!vis[i])
		dfs(i);
	mm(vis , 0);
	rep(i , 1 , n)
	if(!vis[i])
		dfs(i);
	mm(vis , 0);
	rep(i , 1 , n)
	if(!vis[i])
		dfs1(i);
	mm(vis , 0);
	rep(i , 1 , n)
	if(!vis[i])
		dfs1(i);
	mm(vis , 0);
	rep(i , 1 , n)
	if(!vis[i])
		dfs(i);
	mm(vis , 0);
	rep(i , 1 , n)
	if(!vis[i])
		dfs(i);
	mm(vis , 0);
	rep(i , 1 , n)
	if(!vis[i])
		dfs(i);
	mm(vis , 0);
	rep(i , 1 , n)
	if(!vis[i])
		dfs(i);
	mm(vis , 0);
	rep(i , 1 , n)
	if(!vis[i])
		dfs(i);
	mm(vis , 0);
	rep(i , 1 , n)
	if(!vis[i])
		dfs(i);
	mm(vis , 0);
	rep(i , 1 , n)
	if(!vis[i])
		dfs(i);
	mm(vis , 0);
	rep(i , 1 , n)
	if(!vis[i])
		dfs(i);
	mm(vis , 0);
	rep(i , 1 , n)
	if(!vis[i])
		dfs(i);
	mm(vis , 0);
	rep(i , 1 , n)
	if(!vis[i])
		dfs(i);
	mm(vis , 0);
	rep(i , 1 , n)
	if(!vis[i])
		dfs(i);
	mm(vis , 0);
	rep(i , 1 , n)
	if(!vis[i])
		dfs(i);
	mm(vis , 0);
	rep(i , 1 , n)
	if(!vis[i])
		dfs(i);
	mm(vis , 0);
	rep(i , 1 , n)
	if(!vis[i])
		dfs(i);
	mm(vis , 0);
	rep(i , 1 , n)
	if(!vis[i])
		dfs(i);
	mm(vis , 0);
	mm(vis , 0);
	rep(i , 1 , n)
	if(!vis[i])
		dfs(i);
	mm(vis , 0);
	rep(i , 1 , n)
	if(!vis[i])
		dfs1(i);

	mm(vis , 0);
	rep(i , 1 , n)
	if(!vis[i])
		dfs(i);
	mm(vis , 0);
	rep(i , 1 , n)
	if(!vis[i])
		dfs1(i);

	mm(vis , 0);
	rep(i , 1 , n)
	if(!vis[i])
		dfs(i);
	mm(vis , 0);
	rep(i , 1 , n)
	if(!vis[i])
		dfs1(i);

	mm(vis , 0);
	rep(i , 1 , n)
	if(!vis[i])
		dfs(i);
	mm(vis , 0);
	per(i , 1 , n)
	if(!vis[i])
		dfs1(i);

	mm(vis , 0);
	rep(i , 1 , n)
	if(!vis[i])
		dfs(i);
	mm(vis , 0);
	per(i , 1 , n)
	if(!vis[i])
		dfs1(i);

	mm(vis , 0);
	rep(i , 1 , n)
	if(!vis[i])
		dfs(i);
	mm(vis , 0);
	per(i , 1 , n)
	if(!vis[i])
		dfs1(i);

	mm(vis , 0);
	rep(i , 1 , n)
	if(!vis[i])
		dfs(i);
	mm(vis , 0);
	rep(i , 1 , n)
	if(!vis[i])
		dfs(i);
	mm(vis , 0);
	rep(i , 1 , n)
	if(!vis[i])
		dfs(i);
	mm(vis , 0);
	rep(i , 1 , n)
	if(!vis[i])
		dfs(i);
	mm(vis , 0);
	rep(i , 1 , n)
	if(!vis[i])
		dfs(i);
	mm(vis , 0);
	rep(i , 1 , n)
	if(!vis[i])
		dfs(i);
	mm(vis , 0);
	rep(i , 1 , n)
	if(!vis[i])
		dfs(i);
	mm(vis , 0);
	rep(i , 1 , n)
	if(!vis[i])
		dfs(i);
	mm(vis , 0);
	rep(i , 1 , n)
	if(!vis[i])
		dfs(i);
	mm(vis , 0);
	rep(i , 1 , n)
	if(!vis[i])
		dfs(i);
	mm(vis , 0);
	rep(i , 1 , n)
	if(!vis[i])
		dfs(i);
	mm(vis , 0);
	rep(i , 1 , n)
	if(!vis[i])
		dfs(i);
	mm(vis , 0);
	rep(i , 1 , n)
	if(!vis[i])
		dfs(i);
	mm(vis , 0);
	rep(i , 1 , n)
	if(!vis[i])
		dfs(i);
	mm(vis , 0);
	rep(i , 1 , n)
	if(!vis[i])
		dfs(i);
	mm(vis , 0);
	rep(i , 1 , n)
	if(!vis[i])
		dfs(i);


	mm(vis , 0);
	rep(i , 1 , n)
	if(!vis[i])
		dfs(i);
	mm(vis , 0);
	rep(i , 1 , n)
	if(!vis[i])
		dfs(i);
	mm(vis , 0);
	rep(i , 1 , n)
	if(!vis[i])
		dfs(i);
	mm(vis , 0);
	rep(i , 1 , n)
	if(!vis[i])
		dfs(i);
	mm(vis , 0);
	rep(i , 1 , n)
	if(!vis[i])
		dfs(i);
	mm(vis , 0);
	rep(i , 1 , n)
	if(!vis[i])
		dfs(i);
	mm(vis , 0);
	rep(i , 1 , n)
	if(!vis[i])
		dfs(i);
	mm(vis , 0);
	rep(i , 1 , n)
	if(!vis[i])
		dfs(i);
	mm(vis , 0);
	rep(i , 1 , n)
	if(!vis[i])
		dfs(i);
	mm(vis , 0);
	rep(i , 1 , n)
	if(!vis[i])
		dfs(i);
	mm(vis , 0);
	rep(i , 1 , n)
	if(!vis[i])
		dfs(i);
	mm(vis , 0);
	rep(i , 1 , n)
	if(!vis[i])
		dfs(i);
	mm(vis , 0);
	rep(i , 1 , n)
	if(!vis[i])
		dfs(i);
	mm(vis , 0);
	rep(i , 1 , n)
	if(!vis[i])
		dfs(i);
	mm(vis , 0);
	rep(i , 1 , n)
	if(!vis[i])
		dfs(i);
	mm(vis , 0);
	rep(i , 1 , n)
	if(!vis[i])
		dfs(i);
	mm(vis , 0);
	rep(i , 1 , n)
	if(!vis[i])
		dfs(i);
	mm(vis , 0);
	rep(i , 1 , n)
	if(!vis[i])
		dfs(i);
	mm(vis , 0);
	rep(i , 1 , n)
	if(!vis[i])
		dfs(i);
	mm(vis , 0);
	rep(i , 1 , n)
	if(!vis[i])
		dfs(i);
	mm(vis , 0);
	rep(i , 1 , n)
	if(!vis[i])
		dfs(i);
	mm(vis , 0);
	rep(i , 1 , n)
	if(!vis[i])
		dfs(i);
	mm(vis , 0);
	rep(i , 1 , n)
	if(!vis[i])
		dfs(i);
	mm(vis , 0);
	rep(i , 1 , n)
	if(!vis[i])
		dfs(i);
	mm(vis , 0);
	rep(i , 1 , n)
	if(!vis[i])
		dfs(i);
	mm(vis , 0);
	rep(i , 1 , n)
	if(!vis[i])
		dfs(i);

	mm(vis , 0);
	rep(i , 1 , n)
	if(!vis[i])
		dfs(i);
	mm(vis , 0);
	rep(i , 1 , n)
	if(!vis[i])
		dfs(i);
	mm(vis , 0);
	rep(i , 1 , n)
	if(!vis[i])
		dfs(i);
	mm(vis , 0);
	rep(i , 1 , n)
	if(!vis[i])
		dfs(i);
	mm(vis , 0);
	rep(i , 1 , n)
	if(!vis[i])
		dfs(i);
	mm(vis , 0);
	rep(i , 1 , n)
	if(!vis[i])
		dfs(i);
	mm(vis , 0);
	rep(i , 1 , n)
	if(!vis[i])
		dfs(i);
	mm(vis , 0);
	rep(i , 1 , n)
	if(!vis[i])
		dfs(i);
	mm(vis , 0);
	rep(i , 1 , n)
	if(!vis[i])
		dfs(i);
	mm(vis , 0);
	rep(i , 1 , n)
	if(!vis[i])
		dfs(i);
	mm(vis , 0);
	rep(i , 1 , n)
	if(!vis[i])
		dfs(i);
	mm(vis , 0);
	rep(i , 1 , n)
	if(!vis[i])
		dfs(i);
	mm(vis , 0);
	rep(i , 1 , n)
	if(!vis[i])
		dfs(i);
	mm(vis , 0);
	rep(i , 1 , n)
	if(!vis[i])
		dfs(i);
	mm(vis , 0);
	rep(i , 1 , n)
	if(!vis[i])
		dfs(i);


	mm(vis , 0);
	rep(i , 1 , n)
	if(!vis[i])
		dfs(i);

	mm(vis , 0);
	rep(i , 1 , n)
	if(!vis[i])
		dfs(i);

	mm(vis , 0);
	rep(i , 1 , n)
	if(!vis[i])
		dfs(i);
	mm(vis , 0);
	rep(i , 1 , n)
	if(!vis[i])
		dfs(i);
		mm(vis , 0);
	rep(i , 1 , n)
	if(!vis[i])
		dfs(i);	 	
			
					mm(vis , 0);
	rep(i , 1 , n)
	if(!vis[i])
		dfs(i);	 	
			
					mm(vis , 0);
	rep(i , 1 , n)
	if(!vis[i])
		dfs(i);	 	
			
					mm(vis , 0);
	rep(i , 1 , n)
	if(!vis[i])
		dfs(i);	 	
			
					mm(vis , 0);
	rep(i , 1 , n)
	if(!vis[i])
		dfs(i);	 	
			
					mm(vis , 0);
	rep(i , 1 , n)
	if(!vis[i])
		dfs(i);	 	
			
					mm(vis , 0);
	rep(i , 1 , n)
	if(!vis[i])
		dfs(i);	 	
			
					mm(vis , 0);
	rep(i , 1 , n)
	if(!vis[i])
		dfs(i);	 	
			
					mm(vis , 0);
	rep(i , 1 , n)
	if(!vis[i])
		dfs(i);	 	
			
					mm(vis , 0);
	rep(i , 1 , n)
	if(!vis[i])
		dfs(i);	 	
			
					mm(vis , 0);
	rep(i , 1 , n)
	if(!vis[i])
		dfs(i);	 	
			
					mm(vis , 0);
	rep(i , 1 , n)
	if(!vis[i])
		dfs(i);	 	
			
					mm(vis , 0);
	rep(i , 1 , n)
	if(!vis[i])
		dfs(i);	 	
			
					mm(vis , 0);
	rep(i , 1 , n)
	if(!vis[i])
		dfs(i);	 	
			
					mm(vis , 0);
	rep(i , 1 , n)
	if(!vis[i])
		dfs(i);	 	
			
					mm(vis , 0);
	rep(i , 1 , n)
	if(!vis[i])
		dfs(i);	 	
			
					mm(vis , 0);
	rep(i , 1 , n)
	if(!vis[i])
		dfs(i);	 	
			
					mm(vis , 0);
	rep(i , 1 , n)
	if(!vis[i])
		dfs(i);	 	
			
					mm(vis , 0);
	rep(i , 1 , n)
	if(!vis[i])
		dfs(i);	 	
			
					mm(vis , 0);
	rep(i , 1 , n)
	if(!vis[i])
		dfs(i);	 	
			
					mm(vis , 0);
	rep(i , 1 , n)
	if(!vis[i])
		dfs(i);	 	
			
					mm(vis , 0);
	rep(i , 1 , n)
	if(!vis[i])
		dfs(i);	 	
			
					mm(vis , 0);
	rep(i , 1 , n)
	if(!vis[i])
		dfs(i);	 	
			
					mm(vis , 0);
	rep(i , 1 , n)
	if(!vis[i])
		dfs(i);	 	
			
					mm(vis , 0);
	rep(i , 1 , n)
	if(!vis[i])
		dfs(i);	 	
			
			
	mm(vis , 0);
	rep(i , 1 , n)
	if(!vis[i])
		dfs(i);

	mm(vis , 0);
	rep(i , 1 , n)
	if(!vis[i])
		dfs(i);

	mm(vis , 0);
	rep(i , 1 , n)
	if(!vis[i])
		dfs(i);

	mm(vis , 0);
	rep(i , 1 , n)
	if(!vis[i])
		dfs(i);

	mm(vis , 0);
	rep(i , 1 , n)
	if(!vis[i])
		dfs(i);

	mm(vis , 0);
	rep(i , 1 , n)
	if(!vis[i])
		dfs(i);

	mm(vis , 0);
	rep(i , 1 , n)
	if(!vis[i])
		dfs(i);

	mm(vis , 0);
	rep(i , 1 , n)
	if(!vis[i])
		dfs(i);



	mm(vis , 0);
	per(i , 1 , n)
	if(!vis[i])
		dfs1(i);
	mm(vis , 0);
	rep(i , 1 , n)
	if(!vis[i])
		dfs1(i);

	mm(vis , 0);
	rep(i , 1 , n)
	if(!vis[i])
		dfs1(i);
	mm(vis , 0);
	rep(i , 1 , n)
	if(!vis[i])
		dfs1(i);
	mm(vis , 0);
	rep(i , 1 , n)
	if(!vis[i])
		dfs1(i);
	mm(vis , 0);
	rep(i , 1 , n)
	if(!vis[i])
		dfs1(i);
	mm(vis , 0);
	rep(i , 1 , n)
	if(!vis[i])
		dfs1(i);
	mm(vis , 0);
	rep(i , 1 , n)
	if(!vis[i])
		dfs1(i);
	mm(vis , 0);
	rep(i , 1 , n)
	if(!vis[i])
		dfs1(i);
	mm(vis , 0);
	rep(i , 1 , n)
	if(!vis[i])
		dfs1(i);






	rep(i , 1 , n)
	if(!vis[i])
		dfs(i);

	rep(i , 1 , n)
	{
		if(ans[i] == inf)
			cout << -1 << " ";
		else cout << ans[i] << " ";
	}
	return 0;
}









