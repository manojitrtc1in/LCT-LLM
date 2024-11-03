













































































































































































































































































































































































































































































































































































































































































































































































































































































































































#include<bits/stdc++.h>




































































































#define db double
#define il inline
#define re register
#define ldb long db
#define ll long long


#define ui unsigned int
#define ull unsigned ll
#define i128 __int128
#define fi first
#define se second
#define pll pair<long long,long long>
#define pil pair<int,ll>
#define pli pair<ll,int>
#define pii pair<int,int>
#define MP(x,y) make_pair(x,y)
#define lowbit(x) ((x)&(~(x)+1))
#define iL (1<<20)
#define TEM template<class T>il void
#define Write(x,LC) write((x)),*iter++=LC
#define Writeneg(x,LC) writeneg((x)),*iter++=LC
#define flush() fwrite(Out,1,iter-Out,stdout),iter=Out
#define gc() ((iS==iT)?(iT=(iS=ibuf)+fread(ibuf,1,iL,stdin),(iS==iT)?EOF:*iS++):*iS++)
using namespace std;
namespace IO {
	char ibuf[iL],*iS=ibuf+iL,*iT=ibuf+iL,Out[iL],*iter=Out;
	TEM Readneg(re T &x) {
		re char c;
		re bool f;
		for(f=false,c=getchar(); !isdigit(c); f|=c=='-',c=getchar());
		for(x=0; isdigit(c); x=(x<<1)+(x<<3)+(c^48),c=getchar());
		if(f)x=~x+1;
	}
	TEM readneg(re T &x) {
		re char c;
		re bool f;
		for(f=false,c=gc(); !isdigit(c); f|=c=='-',c=gc());
		for(x=0; isdigit(c); x=(x<<1)+(x<<3)+(c^48),c=gc());
		if(f)x=~x+1;
	}
	TEM writeneg(re T x) {
		if(x<0)*iter++='-',x=~x+1;
		re T c[35],l;
		for(l=0; !l || x; c[l]=x%10,++l,x/=10);
		for(; l; --l,*iter++=c[l]+'0');
		flush();
	}
	TEM Read(re T &x) {
		re char c;
		for(c=getchar(); !isdigit(c); c=getchar());
		for(x=0; isdigit(c); x=(x<<1)+(x<<3)+(c^48),c=getchar());
	}
	TEM read(re T &x) {
		re char c;
		for(c=gc(); !isdigit(c); c=gc());
		for(x=0; isdigit(c); x=(x<<1)+(x<<3)+(c^48),c=gc());
	}
	TEM write(re T x) {
		re T c[35],l;
		for(l=0; !l||x; c[l++]=x%10,x/=10);
		for(; l; *iter++=c[--l]+'0');
		flush();
	}
}
using namespace IO;
#define MAXL 20
#define MAXB 450
#define MAXA 1000005


#define MAXN 300005
#define MAXW 500005
#define MAXC 500005
#define MAXM 5005
#define MAXQ 500005
#define MAXK 5
#define MAXS 500005
#define MAXT 500005


#define mod 1000000007
#define inv2 499122177
#define BS 1919810
#define mod1 1000000007
#define mod2 1000000009
#define eps 1e-8
#define begT 232542
#define endT 1e-10
#define chgT 0.9260871
















































#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define N 200010
int n;
il int work(){
  int ans=0;
  for(re int i=1;i<=n;++i){
    for(re int j=1;j<=n;++j){
      for(re int k=1;k<=n;++k){
        int x=i^j,y=i^k,z=j^k;
        if(x+y>z&&x+z>y&&y+z>x)++ans;
      }
    }
  }
  return ans;
}
int a[N],b[N],px[N],py[N],m;
ll sx[N],sy[N];
int tx,ty;
ll xsum(int l,int r){return sx[r]-sx[l-1];}
ll sum(int x,int y,bool cut)
{
    int res=0;
    if(px[x]<y)
    {
        if(cut)
        {
            if(tx>x && ty>y) res=1;
            if(tx<=x && ty<=y && ty<=px[tx]) res=1;
        }
        int l=py[y];
        return 1ll*l*y+xsum(l+1,x)+1ll*(n-x)*(m-y)-res;
    }
    if(cut)
    {
        if(tx<=x && ty<=y) res=1;
        if(tx>x && ty>y && ty>px[tx]) res=1;
    }
    int r=py[y];
    return 1ll*x*y+(1ll*(r-x)*m-xsum(x+1,r))+1ll*(n-r)*(m-y)-res;
}
bool check(int x)
{
    px[0]=m;
    for(int i=1;i<=n;i++)
        for(px[i]=px[i-1];px[i] && a[i]+b[px[i]]>x;px[i]--);
    for(int i=1;i<=n;i++) sx[i]=sx[i-1]+px[i];
    py[0]=n;
    for(int i=1;i<=m;i++)
        for(py[i]=py[i-1];py[i] && a[py[i]]+b[i]>x;py[i]--);
    ll a0=max(xsum(1,n),1ll*n*m-xsum(1,n)),a1=max(xsum(1,n)-(ty<=px[tx]),1ll*n*m-xsum(1,n)-(ty>px[tx]));
    int p=1;
    for(int i=1;i<=n;i++)
    {
        while(p<m && sum(i,p,0)<=sum(i,p+1,0)) p++;
        a0=max(a0,sum(i,p,0));
    }
    

    

    

    p=1;
    for(int i=1;i<=n;i++)
    {
        while(p<m && sum(i,p,1)<=sum(i,p+1,1)) p++;
        a1=max(a1,sum(i,p,1));
    }
    

    

    return a0!=a1+1;
}
int ans[105];
il void WORK(){
  for(n=1;n<=100;++n)ans[n]=work();
  scanf("%d%d",&n,&m);
  for(int i=1;i<=n;i++) scanf("%d",&a[i]);
  for(int i=1;i<=m;i++) scanf("%d",&b[i]);
  tx=a[1],ty=b[1];
  sort(a+1,a+n+1);sort(b+1,b+m+1);
  tx=lower_bound(a+1,a+n+1,tx)-a,ty=lower_bound(b+1,b+m+1,ty)-b;
  int l=a[1]+b[1],r=a[tx]+b[ty],res=a[tx]+b[ty];
  while(l<=r)
  {
      int mid=(l+r)>>1;
      if(check(mid)) r=mid-1,res=mid;
      else l=mid+1;
  }
  printf("%d\n",res);




}
int fac[5000005],ifac[5000005],pw[5000005];
il int QP(int p,int n){re int ans=1;for(;n;n&1?ans=1ll*ans*p%mod:0,p=1ll*p*p%mod,n>>=1);return ans;}
il int C(int n,int m){return n<m?0:1ll*fac[n]*ifac[m]%mod*ifac[n-m]%mod;}
int main(){


	fac[0]=pw[0]=1;for(re int i=1;i<5000001;++i)fac[i]=1ll*fac[i-1]*i%mod,pw[i]=(pw[i-1]+pw[i-1])%mod;
	ifac[5000000]=QP(fac[5000000],mod-2);for(re int i=4999999;~i;--i)ifac[i]=1ll*ifac[i+1]*(i+1)%mod;
	

	srand(time(0));
	re int T=1;






	

	

	for(re int i=0; i<T; ++i)WORK();
	

	

	

	return 0;
}