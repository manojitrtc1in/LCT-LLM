#include<algorithm>
#include<iostream>
#include<assert.h>
#include<cstdio>
#include<vector> 
#include<cmath>
#include<map>
#define poly vector<int>
const int N=1.2e6+5,K=25,mod=998244353;
using namespace std;
struct edge{
	int x,y;
}g[N<<1];
int a[N],k[N],out[N],in[N];
int su=0;
bool vis[N];
vector<int>res;
map<int,int>mp[N];
inline char gc()
{
	static char buf[1<<16],*S,*T;
	if(S==T)
	{
		T=(S=buf)+fread(buf,1,1<<16,stdin);
		if(S==T)return EOF;
	}
	return *(S++);
}
#define getchar gc
inline int read()
{
	char h=getchar();
	int y=0;
	while(h<'0'||h>'9')h=getchar();
	while(h>='0'&&h<='9')y=y*10+h-'0',h=getchar();
	return y;
}
inline int readm()
{
	char h=getchar();
	int y=0;
	while(h<'0'||h>'9')h=getchar();
	while(h>='0'&&h<='9')y=(y*10ll+h-'0')%998244353,h=getchar();
	return y;
}
inline int qpow(int a,int b)
{
	int j=1;
	for(;b;b>>=1,a=1ll*a*a%mod)if(b&1)j=1ll*j*a%mod;
	return j;
}
inline void add(int a,int b){if(mp[a].find(b)!=mp[a].end())return;mp[a][b]=1;g[++su]=(edge){k[a],b};k[a]=su;out[a]++;in[b]++;}
struct Poly{

	int rev[N],invv[N],fra[N],ifra[N];
	vector<int>W[2][K];
	unsigned long long tmp[N];
	static const int mod=998244353,g=3,g2=332748118,I=86583718;


	inline void init(int n)
	{
		invv[1]=fra[0]=ifra[0]=1;
		for(int i=2;i<=n;i++)invv[i]=1ll*(mod-mod/i)*invv[mod%i]%mod;
		for(int i=1;i<=n;i++)fra[i]=1ll*fra[i-1]*i%mod,ifra[i]=1ll*ifra[i-1]*invv[i]%mod;
		for(int t=2,i=1;t<=n;i++,t<<=1)
		{
			W[0][i].resize((t>>1)+1);W[1][i].resize((t>>1)+1);
			W[0][i][0]=W[1][i][0]=1;
			if(t>2)W[0][i][1]=qpow(g,(mod-1)/t),W[1][i][1]=qpow(g2,(mod-1)/t);
			for(int j=2;j<(t>>1);j++)W[0][i][j]=1ll*W[0][i][j-1]*W[0][i][1]%mod,W[1][i][j]=1ll*W[1][i][j-1]*W[1][i][1]%mod;
		}
	}
	inline poly val(int a){poly ans(1,a);return ans;}
	inline void rever(poly &a){reverse(a.begin(),a.end());}
	inline poly cut(poly a,int l){if(a.size()<=l)return a;a.resize(l);return a;}

	inline poly trans(poly a,int l)
	{
		if(l>0)
		{
			a.resize(a.size()+l);
			for(int i=a.size()-1;i>=l;i--)a[i]=a[i-l];
			for(int i=0;i<l;i++)a[i]=0;
		}
		else
		{
			l=-l;
			for(int i=0;i<a.size()-l;i++)a[i]=a[i+l];
			a.resize(max(0,(int)a.size()-l));
		}
		return a;
	} 
	inline poly add(poly a,poly b)
	{
		int n=a.size()-1,m=b.size()-1;
		a.resize(max(n,m)+1);
		for(int i=0;i<=m;i++)a[i]=(a[i]+b[i])%mod;
		return a;
	}
	inline poly dec(poly a,poly b)
	{
		int n=a.size()-1,m=b.size()-1;
		a.resize(max(n,m)+1);
		for(int i=0;i<=m;i++)a[i]=(a[i]-b[i]+mod)%mod;
		return a;
	}
	inline poly times(poly a,int b)
	{
		for(int i=0;i<a.size();i++)a[i]=1ll*a[i]*b%mod;
		return a;
	}
	inline poly deri(poly a)

	{
		int n=a.size()-1;
		for(int i=0;i<n;i++)a[i]=1ll*a[i+1]*(i+1)%mod;
		a.resize(n);
		return a;
	}
	inline poly inte(poly a)

	{
		int n=a.size()-1;a.resize(n+2);
		for(int i=n;~i;i--)a[i+1]=1ll*a[i]*invv[i+1]%mod;
		a[0]=0;
		return a;
	}
	inline void ntt(poly &a,int n,int ty)
	{
		for(int i=0;i<n;tmp[i]=a[i],i++)if(i<rev[i])swap(a[i],a[rev[i]]);
		for(int l=1,cnt=1;l<n;l<<=1,cnt++)
		{
			for(int i=0;i<n;i+=(l<<1))
			for(int w=1,j=0;j<l;j++,w=W[ty][cnt][j])
			{
				int y=w*tmp[i+j+l]%mod;
				tmp[i+j+l]=(tmp[i+j]-y+mod);tmp[i+j]+=y;
			}
			if(cnt%18==0)for(int i=0;i<n;i++)tmp[i]=tmp[i]%mod;
		}
		for(int i=0;i<n;i++)a[i]=tmp[i]%mod;
	}
	inline poly mul(poly a,poly b,int l,bool eq)

	{
		int n=a.size()-1,m=b.size()-1,s=1,res=0;
		while(s<=n+m)s<<=1,res++;
		for(int i=0;i<s;i++)rev[i]=(rev[i>>1]>>1)|((i&1)<<(res-1));
		a.resize(s);if(!eq)b.resize(s);
		ntt(a,s,0);if(!eq)ntt(b,s,0);
		if(!eq)for(int i=0;i<s;i++)a[i]=1ll*a[i]*b[i]%mod;
		else for(int i=0;i<s;i++)a[i]=1ll*a[i]*a[i]%mod;
		ntt(a,s,1);
		a.resize(l==-1?n+m+1:l);
		for(int inv=invv[s],i=0;i<a.size();i++)a[i]=1ll*a[i]*inv%mod;
		return a;
	}
	inline poly mult(poly a,poly b)

	{
		int n=a.size()-1,m=b.size()-1;
		rever(b);
		poly res=mul(a,b,-1,0),ans(0);
		for(int i=0;i<=n;i++)ans.push_back(res[i+m]);
		return ans;
	}
	inline poly inv(poly a,int m)

	{
		assert(a[0]!=0);
		poly ans;
		ans.push_back(qpow(a[0],mod-2));
		int si=2;
		while((si>>1)<m)ans=dec(times(ans,2),mul(mul(ans,ans,si,1),cut(a,si),si,0)),si<<=1;
		ans.resize(m);
		return ans;
	}
	inline poly sqr(poly a,int m)

	{
		assert(a[0]==1);
		poly ans;
		ans.push_back(1);
		int si=2;
		while((si>>1)<m)ans=times(add(mul(cut(a,si),inv(ans,si),si,0),ans),invv[2]),si<<=1;
		ans.resize(m);
		return ans;
	}
	inline poly ln(poly a,int m){assert(a[0]==1);return cut(inte(mul(deri(a),inv(a,m),m,0)),m);}
	inline poly exp(poly a,int m)

	{
		assert(a[0]==0);
		a[0]++;
		poly ans(1,1);
		int si=2;
		while((si>>1)<m)ans=mul(ans,dec(cut(a,si),ln(ans,si)),si,0),si<<=1;
		ans.resize(m);
		return ans;
	}
	inline poly pqpow(poly a,int m,int b){return exp(times(ln(a,m),b),m);}
	inline poly npqpow(poly a,int m,int b,int b2)
	{
		int w=-1,n=a.size()-1;
		for(int i=0;i<=n;i++)if(a[i]){w=i;break;}
		if(w==-1)return a;
		if(1ll*w*b>=m){poly res(m,0);return res;}
		a=trans(a,-w);
		int v=qpow(a[0],b2),inv=qpow(a[0],mod-2);w*=b;
		a=trans(times(exp(times(ln(times(a,inv),m-w),b),m-w),v),w);
		return a;
	}
	inline poly sin(poly a,int m){a=exp(times(a,I),m);return times(dec(a,inv(a,m)),qpow(2*I,mod-2));}
	inline poly cos(poly a,int m){a=exp(times(a,I),m);return times(add(a,inv(a,m)),invv[2]);}
	inline poly asin(poly a,int m){return cut(inte(mul(deri(a),inv(sqr(dec(val(1),mul(a,a,m,1)),m),m),m,0)),m);}
	inline poly atan(poly a,int m){return cut(inte(mul(deri(a),inv(add(val(1),mul(a,a,m,1)),m),m,0)),m);}
	poly Q;
	inline poly div(poly a,poly b)
	{
		int n=a.size(),m=b.size();
		rever(a);rever(b);
		Q=mul(a,inv(b,n-m+1),n-m+1,0);
		rever(Q);rever(b);rever(a);
		return cut(dec(a,mul(b,Q,-1,0)),m);
	}
	inline poly comp(poly a,poly b)

	{
		int n=a.size()-1,m=b.size()-1,l=sqrt(n)+1;
		a.resize(l*l+1);
		poly G1[l+1],G2[l],res(1,1),ans;
		G1[0]=G2[0]=res;
		for(int i=1;i<=l;i++)G1[i]=mul(G1[i-1],b,n+1,0);
		for(int i=1;i<l;i++)G2[i]=mul(G2[i-1],G1[l],n+1,0);
		for(int i=0;i<l;i++)
		{
			poly tmp(n+1);
			for(int j=0;j<l;j++)
			for(int x=a[i*l+j],k=0;k<G1[j].size();k++)tmp[k]=(tmp[k]+1ll*G1[j][k]*x)%mod;
			ans=add(ans,mul(tmp,G2[i],n+1,0));
		}
		return ans;
	}
	inline poly cinv(poly a)

	{
		int n=a.size(),l=sqrt(n)+1;
		poly b1[l+1],b2[l+1];
		for(int i=0;i<n-1;i++)a[i]=a[i+1];
		a.resize(n-1);a=inv(a,n);
		poly ans(n);
		b1[0].resize(n);b1[0][0]=1;b2[0].resize(n);b2[0][0]=1;
		for(int i=1;i<=l;i++)b1[i]=mul(b1[i-1],a,n,0);
		for(int i=1;i<=l;i++)b2[i]=mul(b2[i-1],b1[l],n,0);
		for(int i=0;i<l;i++)
		for(int j=1;j<=l;j++)if(i*l+j<n)
		{
			int x=i*l+j;
			for(int k=0;k<=x-1;k++)ans[x]=(ans[x]+1ll*b1[j][k]*b2[i][x-1-k])%mod;
			ans[x]=1ll*ans[x]*invv[x]%mod;
		}
		return ans;
	}
	

	poly QQ[N<<2],P[K],ans;
	int w[N];
	#define lc (x<<1)
	#define rc ((x<<1)|1)
	void build(int x,int l,int r)
	{
		if(l==r)return (void)(QQ[x].clear(),QQ[x].push_back(1),QQ[x].push_back(mod-w[l]));
		int m=(l+r)>>1;
		build(lc,l,m);build(rc,m+1,r);
		QQ[x]=mul(QQ[lc],QQ[rc],-1,0);
	}
	void query(int x,int l,int r,int d)
	{
		P[d].resize(r-l+1);
		if(l==r)return (void)(ans[l]=P[d][0]);
		int m=(l+r)>>1;
		P[d+1]=mult(P[d],QQ[rc]);query(lc,l,m,d+1);
		P[d+1]=mult(P[d],QQ[lc]);query(rc,m+1,r,d+1);
	}
	inline poly eval(poly a,poly x)
	{
		ans.resize(x.size());
		for(int i=0;i<x.size();i++)w[i]=x[i];
		build(1,0,x.size()-1);
		P[0]=mult(a,inv(QQ[1],max(a.size(),x.size())));
		query(1,0,x.size()-1,0);
		return ans;
	}
	
	

	poly rq[N<<2];
	inline void calc(int x,int l,int r,poly &v)
	{
		if(l==r)return (void)(rq[x].push_back(mod-v[l]),rq[x].push_back(1));
		int m=(l+r)>>1;
		calc(lc,l,m,v);calc(rc,m+1,r,v);
		rq[x]=mul(rq[lc],rq[rc],-1,0);
	}
	inline poly solve(int x,int l,int r,poly &v)
	{
		if(l==r)return val(v[l]);
		int m=(l+r)>>1;
		return add(mul(solve(lc,l,m,v) ,rq[rc],-1,0),mul(solve(rc,m+1,r,v),rq[lc],-1,0));
	}
	inline poly lag(poly x,poly y)
	{
		int n=x.size();
		calc(1,0,n-1,x);
		poly v=eval(deri(rq[1]),x);
		for(int i=0;i<n;i++)y[i]=1ll*y[i]*qpow(v[i],mod-2)%mod;
		return solve(1,0,n-1,y);
	}
	
	

	int cm[N];
	inline poly move(poly x,int m)
	{
		int n=x.size()-1;
		poly a,b;
		for(int i=0;i<=n;i++)a.push_back(1ll*x[i]*ifra[i]%mod*ifra[n-i]%mod*((n-i)&1?mod-1:1)%mod);
		for(int i=0;i<=n<<1;i++)b.push_back(qpow((m-n+i+mod)%mod,mod-2));
		poly res=mul(a,b,-1,0),ans;
		cm[0]=1;
		for(int i=0;i<=n;i++)cm[0]=1ll*cm[0]*(m-i)%mod;
		for(int i=1;i<=n;i++)cm[i]=1ll*cm[i-1]*(m+i)%mod*qpow(m+i-n-1,mod-2)%mod;
		for(int i=0;i<=n;i++)ans.push_back(1ll*res[i+n]*cm[i]%mod);
		return ans;
	}
}P;
poly operator+(poly a,poly b){return P.add(a,b);}
poly operator-(poly a,poly b){return P.dec(a,b);}
poly operator*(poly a,int b){return P.times(a,b);}
void dfs(int x)
{
	vis[x]=1;res.push_back(x);
	for(int i=k[x];i;i=g[i].x)if(!vis[g[i].y])dfs(g[i].y);
}
signed main()
{
	int n=read(),m=read(),k=read();
	for(int i=1;i<=n;i++)
	{
		int s=read();
		for(int j=1;j<=s;j++)a[j]=read();
		for(int j=2;j<=s;j++)add(a[j-1],a[j]);
	}
	P.init(m<<2);
	poly a(m+1);
	for(int i=1;i<=k;i++)if(!vis[i]&&in[i]==0)
	{
		res.clear();dfs(i);int cnt1=0,cnt2=0;
		for(int j=0;j<res.size();j++)cnt1+=in[res[j]]>1?N:in[res[j]],cnt2+=out[res[j]]>1?N:out[res[j]];
		if((cnt1==res.size()-1&&cnt2==res.size()-1)&&res.size()<=m)a[res.size()]=(a[res.size()]-1+mod)%mod;

	}
	a[0]++;
	a=P.inv(a,m+1);
	cout<<a[m]<<"\n";
}