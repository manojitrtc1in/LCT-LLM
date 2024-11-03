













































































































































































































































































































































































































































































































































































































































































































































































































































































































































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














































int n,m,a[100005];
int b[100005];
vector<int>q[100005];
int BL,S[100005],B[100005],F[320];
il int findmn(){
  re int i;for(i=0;!F[i];++i);
  for(i=i*BL;!S[i];++i);
  return i;
}
il int findmx(){
  re int i;for(i=B[a[n]];!F[i];--i);
  for(i=min(a[n],(i+1)*BL-1);!S[i];--i);
  return i;
}
il void add(int x){if(!S[x]++)++F[B[x]];}
il void del(int x){if(!--S[x])--F[B[x]];}
il void WORK(){
  scanf("%d%d",&n,&m);for(re int i=1;i<=n;++i)scanf("%d",&a[i]);
  n=unique(a+1,a+1+n)-a-1;BL=sqrt(a[n]);
  for(re int i=0;i<=a[n];++i)B[i]=i/BL,S[i]=0;


  for(re int i=0;i<=B[a[n]];++i)F[i]=0;
  if(m>a[n]){printf("0\n");return;}
  for(re int i=0;i<=a[n];++i)q[i].clear(),q[i].shrink_to_fit();
  for(re int i=1;i<=n;++i)b[i]=1,q[a[i]].emplace_back(i),add(a[i]);
  int ans=a[n];
  for(re int k=a[n];k>=0;--k){
    if(!q[k].size())continue;
    ans=min(ans,findmx()-findmn());


    if(!k)break;
    for(auto y:q[k]){
      int t=a[y]/b[y],r=a[y]/t;
      if(r+1>m)continue;b[y]=++r,r=a[y]/b[y];
      del(t),add(r),q[r].emplace_back(y);
    }
    q[k].clear(),q[k].shrink_to_fit();
  }
  printf("%d\n",ans);
}






int main(){






	

	srand(time(0));
	re int T=1;
  scanf("%d",&T);




	

	

	for(re int i=0; i<T; ++i)WORK();
	

	

	

	return 0;
}