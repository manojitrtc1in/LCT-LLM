













































































































































































































































































































































































































































































































































































































































































































































































































































































































































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


#define MAXN 200005
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














































int n,m,l[MAXN],r[MAXN],fa[MAXN];ll a[MAXN],b[MAXN];bool vis[MAXN];
il int find(int x){


return x^fa[x]?fa[x]=find(fa[x]):x;}
vector<int>G[MAXN];il void add(int x,int y){G[x].emplace_back(y);}
il void WORK(){


  read(n),read(m);




  for(re int i=1;i<=n;++i)read(a[i]);
  for(re int i=1;i<=n;++i)read(b[i]);
  for(re int i=1;i<=n;++i)a[i]+=a[i-1]-b[i],fa[i]=i;


  for(re int i=1;i<=m;++i)read(l[i]),read(r[i]);
  queue<int>q;fa[0]=0,fa[n+1]=n+1;




  for(re int i=1;i<=m;++i){






    add(l[i]-1,r[i]),add(r[i],l[i]-1);


    if(!a[l[i]-1]&&!a[r[i]]){
      if(!vis[l[i]-1])vis[l[i]-1]=1,q.emplace(l[i]-1),fa[l[i]-1]=l[i];
      if(!vis[r[i]])vis[r[i]]=1,q.emplace(r[i]),fa[r[i]]=r[i]+1;
    }
  }






  for(re int x;!q.empty();q.pop()){
    x=q.front();
    for(re int i=0;i<G[x].size();++i){


re int y=G[x][i];
      if(a[y])continue;if(!vis[y])vis[y]=1,q.emplace(y);
      re int L=min(x,y),R=max(x,y);
      for(L=find(L);L<=R;L=find(L)){


        a[L]=0,fa[L]=L+1;if(!vis[L])vis[L]=1,q.emplace(L);
      }
    }
  }
  re bool fl=1;for(re int i=1;i<=n;++i)fl&=!a[i];


  printf(fl?"YES\n":"NO\n"),memset(a,0,sizeof(ll)*(n+1)),memset(vis,0,sizeof(bool)*(n+1));
  for(re int i=0;i<=n;++i)G[i].resize(0);
}






int main(){






	

	srand(time(0));
	re int T=1;


	 read(T);


	

	

	for(re int i=0; i<T; ++i)WORK();
	

	

	

	return 0;
}