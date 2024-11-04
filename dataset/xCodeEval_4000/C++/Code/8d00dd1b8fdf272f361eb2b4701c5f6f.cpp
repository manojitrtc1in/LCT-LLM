#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;
typedef long long ll;
const int N=600005,K=400005,E=55;
int n,m,q,tot,tou,tod,tol,tor,ton;
int xa[N],ya[N],xb[N],yb[N],x[N],y[N],now[K],f[E][N];
ll fs[E][N];
ll t[N];
char c[N],tc[N];
struct node
{
	int x,ql,qr,id;
}nu[N],nd[N],nl[N],nr[N],nm[N];
bool cmpr(node a,node b)
{
	if(a.x==b.x)
		return a.id>b.id;
	return a.x>b.x;
}
bool cmpl(node a,node b)
{
	if(a.x==b.x)
		return a.id>b.id;
	return a.x<b.x;
}
bool cmpu(node a,node b)
{
	if(a.x==b.x)
		return a.id>b.id;
	return a.x>b.x;
}
bool cmpd(node a,node b)
{
	if(a.x==b.x)
		return a.id>b.id;
	return a.x<b.x;
}
template <class I>
inline void get(I &a)
{
	char c=getchar();
	a=0;
	for(;c<'0'||c>'9';c=getchar());
	for(;c>='0'&&c<='9';c=getchar())
		a=a*10+c-'0';
}
inline void get(char &a)
{
	char c=getchar();
	a=0;
	for(;c<'A'||c>'Z';c=getchar());
	a=c;
}
inline int dist(int xa,int ya,int xb,int yb)
{
	return abs(xa-xb)+abs(ya-yb);
}
inline void addedge(int u,int v)
{
	f[0][u]=v;
	fs[0][u]=dist(xb[u],yb[u],xb[v],yb[v]);
}
#define lc (p<<1)
#define rc ((p<<1)^1)
#define mid ((l+r)>>1)
void build(int p,int l,int r,int dlt)
{
	now[p]=0;
	if(l==r)
	{
		now[p]=l+dlt;
		return;
	}
	build(lc,l,mid,dlt);
	build(rc,mid+1,r,dlt);
}
inline void pushdown(int p)
{
	if(now[p]==0)
		return;
	now[lc]=now[rc]=now[p];
	now[p]=0;
}
void che(int p,int l,int r,int ql,int qr,int x)
{
	if(ql<=l&&r<=qr)
	{
		now[p]=x;
		return;
	}
	pushdown(p);
	if(l<=qr&&ql<=mid)
		che(lc,l,mid,ql,qr,x);
	if(mid+1<=qr&&ql<=r)
		che(rc,mid+1,r,ql,qr,x);
}
int query(int p,int l,int r,int q)
{
	if(l==r)
		return now[p];
	pushdown(p);
	if(q<=mid)
		return query(lc,l,mid,q);
	else
		return query(rc,mid+1,r,q);
}
#undef lc
#undef rc
#undef mid
int main()
{
	get(n);get(m);
	for(int i=1;i<=n;i++)
	{
		get(xa[i]);get(ya[i]);get(xb[i]);get(yb[i]);
		if(xa[i]==xb[i])
			if(ya[i]<yb[i])
			{
				nu[++tou]=(node){xa[i],ya[i],yb[i],i};
				tc[i]='U';
			}
			else
			{
				nd[++tod]=(node){xa[i],yb[i],ya[i],i};
				tc[i]='D';
			}
		else
			if(xa[i]<xb[i])
			{
				nr[++tor]=(node){ya[i],xa[i],xb[i],i};
				tc[i]='R';
			}
			else
			{
				nl[++tol]=(node){ya[i],xb[i],xa[i],i};
				tc[i]='L';
			}
	}
	get(q);
	for(int i=1;i<=q;i++)
	{
		get(x[i]);get(y[i]);get(c[i]);get(t[i]);
		xb[i+n]=x[i];
		yb[i+n]=y[i];
	}
	ton=n+q;
	for(int i=ton+1;i<=ton+m+1;i++)
	{
		xb[i]=m;
		yb[i]=i-ton-1;
		f[0][i]=i;
	}
	build(1,0,m,ton+1);
	tot=0;
	for(int i=1;i<=tou;i++)
		nm[++tot]=(node){nu[i].x,nu[i].ql,nu[i].qr,nu[i].id};
	for(int i=1;i<=tod;i++)
		nm[++tot]=(node){nd[i].x,nd[i].ql,nd[i].qr,nd[i].id};
	for(int i=1;i<=tol;i++)
		nm[++tot]=(node){nl[i].qr,nl[i].x,nl[i].x,nl[i].id};
	for(int i=1;i<=tor;i++)
		nm[++tot]=(node){nr[i].qr,nr[i].x,nr[i].x,-nr[i].id};
	sort(nm+1,nm+1+tot,cmpr);
	for(int i=1;i<=tot;i++)
	{
		if(nm[i].id>0)
			che(1,0,m,nm[i].ql,nm[i].qr,nm[i].id);
		else
		{
			int t=query(1,0,m,nm[i].ql);
			addedge(-nm[i].id,t);
			che(1,0,m,nm[i].ql,nm[i].qr,-nm[i].id);
		}
	}
	tot=0;
	for(int i=1;i<=tou;i++)
		nm[++tot]=(node){nu[i].x,nu[i].ql,nu[i].qr,nu[i].id};
	for(int i=1;i<=tod;i++)
		nm[++tot]=(node){nd[i].x,nd[i].ql,nd[i].qr,nd[i].id};
	for(int i=1;i<=tol;i++)
		nm[++tot]=(node){nl[i].qr,nl[i].x,nl[i].x,nl[i].id};
	for(int i=1;i<=tor;i++)
		nm[++tot]=(node){nr[i].qr,nr[i].x,nr[i].x,nr[i].id};
	for(int i=1;i<=q;i++)
		if(c[i]=='R')
			nm[++tot]=(node){x[i],y[i],y[i],-i-n};
	sort(nm+1,nm+1+tot,cmpr);
	build(1,0,m,ton+1);
	for(int i=1;i<=tot;i++)
	{
		if(nm[i].id>0)
			che(1,0,m,nm[i].ql,nm[i].qr,nm[i].id);
		else
		{
			int t=query(1,0,m,nm[i].ql);
			addedge(-nm[i].id,t);
		}
	}
	ton+=m+1;
	for(int i=ton+1;i<=ton+m+1;i++)
	{
		xb[i]=0;
		yb[i]=i-ton-1;
		f[0][i]=i;
	}
	build(1,0,m,ton+1);
	tot=0;
	for(int i=1;i<=tou;i++)
		nm[++tot]=(node){nu[i].x,nu[i].ql,nu[i].qr,nu[i].id};
	for(int i=1;i<=tod;i++)
		nm[++tot]=(node){nd[i].x,nd[i].ql,nd[i].qr,nd[i].id};
	for(int i=1;i<=tol;i++)
		nm[++tot]=(node){nl[i].ql,nl[i].x,nl[i].x,-nl[i].id};
	for(int i=1;i<=tor;i++)
		nm[++tot]=(node){nr[i].ql,nr[i].x,nr[i].x,nr[i].id};
	sort(nm+1,nm+1+tot,cmpl);
	for(int i=1;i<=tot;i++)
	{
		if(nm[i].id>0)
			che(1,0,m,nm[i].ql,nm[i].qr,nm[i].id);
		else
		{
			int t=query(1,0,m,nm[i].ql);
			addedge(-nm[i].id,t);
			che(1,0,m,nm[i].ql,nm[i].qr,-nm[i].id);
		}
	}
	tot=0;
	for(int i=1;i<=tou;i++)
		nm[++tot]=(node){nu[i].x,nu[i].ql,nu[i].qr,nu[i].id};
	for(int i=1;i<=tod;i++)
		nm[++tot]=(node){nd[i].x,nd[i].ql,nd[i].qr,nd[i].id};
	for(int i=1;i<=tol;i++)
		nm[++tot]=(node){nl[i].ql,nl[i].x,nl[i].x,nl[i].id};
	for(int i=1;i<=tor;i++)
		nm[++tot]=(node){nr[i].ql,nr[i].x,nr[i].x,nr[i].id};
	for(int i=1;i<=q;i++)
		if(c[i]=='L')
			nm[++tot]=(node){x[i],y[i],y[i],-i-n};
	sort(nm+1,nm+1+tot,cmpl);
	build(1,0,m,ton+1);
	for(int i=1;i<=tot;i++)
	{
		if(nm[i].id>0)
			che(1,0,m,nm[i].ql,nm[i].qr,nm[i].id);
		else
		{
			int t=query(1,0,m,nm[i].ql);
			addedge(-nm[i].id,t);
		}
	}
	ton+=m+1;
	for(int i=ton+1;i<=ton+m+1;i++)
	{
		yb[i]=m;
		xb[i]=i-ton-1;
		f[0][i]=i;
	}
	build(1,0,m,ton+1);
	tot=0;
	for(int i=1;i<=tor;i++)
		nm[++tot]=(node){nr[i].x,nr[i].ql,nr[i].qr,nr[i].id};
	for(int i=1;i<=tol;i++)
		nm[++tot]=(node){nl[i].x,nl[i].ql,nl[i].qr,nl[i].id};
	for(int i=1;i<=tod;i++)
		nm[++tot]=(node){nd[i].qr,nd[i].x,nd[i].x,nd[i].id};
	for(int i=1;i<=tou;i++)
		nm[++tot]=(node){nu[i].qr,nu[i].x,nu[i].x,-nu[i].id};
	sort(nm+1,nm+1+tot,cmpu);
	for(int i=1;i<=tot;i++)
	{
		if(nm[i].id>0)
			che(1,0,m,nm[i].ql,nm[i].qr,nm[i].id);
		else
		{
			int t=query(1,0,m,nm[i].ql);
			addedge(-nm[i].id,t);
			che(1,0,m,nm[i].ql,nm[i].qr,-nm[i].id);
		}
	}
	tot=0;
	for(int i=1;i<=tor;i++)
		nm[++tot]=(node){nr[i].x,nr[i].ql,nr[i].qr,nr[i].id};
	for(int i=1;i<=tol;i++)
		nm[++tot]=(node){nl[i].x,nl[i].ql,nl[i].qr,nl[i].id};
	for(int i=1;i<=tod;i++)
		nm[++tot]=(node){nd[i].qr,nd[i].x,nd[i].x,nd[i].id};
	for(int i=1;i<=tou;i++)
		nm[++tot]=(node){nu[i].qr,nu[i].x,nu[i].x,nu[i].id};
	for(int i=1;i<=q;i++)
		if(c[i]=='U')
			nm[++tot]=(node){y[i],x[i],x[i],-i-n};
	sort(nm+1,nm+1+tot,cmpu);
	build(1,0,m,ton+1);
	for(int i=1;i<=tot;i++)
	{
		if(nm[i].id>0)
			che(1,0,m,nm[i].ql,nm[i].qr,nm[i].id);
		else
		{
			int t=query(1,0,m,nm[i].ql);
			addedge(-nm[i].id,t);
		}
	}
	ton+=m+1;
	for(int i=ton+1;i<=ton+m+1;i++)
	{
		yb[i]=0;
		xb[i]=i-ton-1;
		f[0][i]=i;
	}
	build(1,0,m,ton+1);
	tot=0;
	for(int i=1;i<=tor;i++)
		nm[++tot]=(node){nr[i].x,nr[i].ql,nr[i].qr,nr[i].id};
	for(int i=1;i<=tol;i++)
		nm[++tot]=(node){nl[i].x,nl[i].ql,nl[i].qr,nl[i].id};
	for(int i=1;i<=tod;i++)
		nm[++tot]=(node){nd[i].ql,nd[i].x,nd[i].x,-nd[i].id};
	for(int i=1;i<=tou;i++)
		nm[++tot]=(node){nu[i].ql,nu[i].x,nu[i].x,nu[i].id};
	sort(nm+1,nm+1+tot,cmpd);
	for(int i=1;i<=tot;i++)
	{
		if(nm[i].id>0)
			che(1,0,m,nm[i].ql,nm[i].qr,nm[i].id);
		else
		{
			int t=query(1,0,m,nm[i].ql);
			addedge(-nm[i].id,t);
			che(1,0,m,nm[i].ql,nm[i].qr,-nm[i].id);
		}
	}
	tot=0;
	for(int i=1;i<=tor;i++)
		nm[++tot]=(node){nr[i].x,nr[i].ql,nr[i].qr,nr[i].id};
	for(int i=1;i<=tol;i++)
		nm[++tot]=(node){nl[i].x,nl[i].ql,nl[i].qr,nl[i].id};
	for(int i=1;i<=tod;i++)
		nm[++tot]=(node){nd[i].ql,nd[i].x,nd[i].x,nd[i].id};
	for(int i=1;i<=tou;i++)
		nm[++tot]=(node){nu[i].ql,nu[i].x,nu[i].x,nu[i].id};
	for(int i=1;i<=q;i++)
		if(c[i]=='D')
			nm[++tot]=(node){y[i],x[i],x[i],-i-n};
	sort(nm+1,nm+1+tot,cmpd);
	build(1,0,m,ton+1);
	for(int i=1;i<=tot;i++)
	{
		if(nm[i].id>0)
			che(1,0,m,nm[i].ql,nm[i].qr,nm[i].id);
		else
		{
			int t=query(1,0,m,nm[i].ql);
			addedge(-nm[i].id,t);
		}
	}
	ton+=m+1;
	for(int i=1;i<=50;i++)
		for(int j=1;j<=ton;j++)
		{
			f[i][j]=f[i-1][f[i-1][j]];
			fs[i][j]=min(10000000000000000ll,fs[i-1][j]+fs[i-1][f[i-1][j]]);
		}
	for(int i=1;i<=q;i++)
	{
		int now=i+n;
		ll b=t[i];
		for(int j=50;j>=0;j--)
		{
			if(b<fs[j][now])
				continue;
			b-=fs[j][now];
			now=f[j][now];
		}
		if(now>n+q)
		{
			printf("%d %d\n",xb[now],yb[now]);
			continue;
		}
		else
		{
			if(now>n)
			{
				if(c[i]=='L'||c[i]=='R')
				{
					if(b<=abs(xb[now]-xb[f[0][now]]))
					{
						if(xb[f[0][now]]<xb[now])
							printf("%lld %d\n",xb[now]-b,yb[now]);
						else
							printf("%lld %d\n",xb[now]+b,yb[now]);
					}
					else
					{
						b-=abs(xb[now]-xb[f[0][now]]);
						if(yb[f[0][now]]<yb[now])
							printf("%d %lld\n",xb[f[0][now]],yb[now]-b);
						else
							printf("%d %lld\n",xb[f[0][now]],yb[now]+b);
					}
				}
				else
				{
					if(b<=abs(yb[now]-yb[f[0][now]]))
					{
						if(yb[f[0][now]]<yb[now])
							printf("%d %lld\n",xb[now],yb[now]-b);
						else
							printf("%d %lld\n",xb[now],yb[now]+b);
					}
					else
					{
						b-=abs(yb[now]-yb[f[0][now]]);
						if(xb[f[0][now]]<xb[now])
							printf("%lld %d\n",xb[now]-b,yb[f[0][now]]);
						else
							printf("%lld %d\n",xb[now]+b,yb[f[0][now]]);
					}
				}
			}
			else
			{
				if(tc[now]=='L'||tc[now]=='R')
				{
					if(b<=abs(xb[now]-xb[f[0][now]]))
					{
						if(xb[f[0][now]]<xb[now])
							printf("%lld %d\n",xb[now]-b,yb[now]);
						else
							printf("%lld %d\n",xb[now]+b,yb[now]);
					}
					else
					{
						b-=abs(xb[now]-xb[f[0][now]]);
						if(yb[f[0][now]]<yb[now])
							printf("%d %lld\n",xb[f[0][now]],yb[now]-b);
						else
							printf("%d %lld\n",xb[f[0][now]],yb[now]+b);
					}
				}
				else
				{
					if(b<=abs(yb[now]-yb[f[0][now]]))
					{
						if(yb[f[0][now]]<yb[now])
							printf("%d %lld\n",xb[now],yb[now]-b);
						else
							printf("%d %lld\n",xb[now],yb[now]+b);
					}
					else
					{
						b-=abs(yb[now]-yb[f[0][now]]);
						if(xb[f[0][now]]<xb[now])
							printf("%lld %d\n",xb[now]-b,yb[f[0][now]]);
						else
							printf("%lld %d\n",xb[now]+b,yb[f[0][now]]);
					}
				}
			}
		}
	}
	return 0;
}
