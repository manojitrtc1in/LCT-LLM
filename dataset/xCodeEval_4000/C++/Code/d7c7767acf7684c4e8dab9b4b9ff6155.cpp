













































































































































































































































































































































































































































































































































































































































































































































































































































































































































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


#define MAXN 500005
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
namespace FHQ_Treap{
	int rt,cnt,son[MAXN][2],sz[MAXN],val[MAXN],rp[MAXN];
	il int NewNode(int value){
		sz[++cnt]=1,val[cnt]=value,rp[cnt]=rand();
		return cnt;
	}
	il void Pushup(int x){
		sz[x]=sz[son[x][0]]+sz[son[x][1]]+1;
	}
	void Split(int x,int &ls,int &rs,int k){
		if(!x){ls=rs=0;return;}
		if(sz[son[x][0]]+1<=k)Split(son[ls=x][1],son[x][1],rs,k-sz[son[x][0]]-1);
		else Split(son[rs=x][0],ls,son[x][0],k);
		Pushup(x);
	}
	il int Merge(int x,int y){
		if(!x||!y)return x|y;int rot;
		if(rp[x]<rp[y])son[rot=x][1]=Merge(son[x][1],y);
		else son[rot=y][0]=Merge(x,son[y][0]);
		Pushup(rot);return rot;
	}
}


int n,m,ans;
char b[MAXN];
struct node{int l,id;il bool operator<(const node&tmp)const{return l<tmp.l;}}a[MAXN];
il int query(){printf("? %s\n",b+1);fflush(stdout);re int t;scanf("%d",&t);return t;}
il void WORK(){
  scanf("%d%d",&n,&m);for(re int i=1;i<=m;++i)b[i]='0';
  for(re int i=1;i<=m;++i)b[i]='1',a[i]={query(),i},ans+=a[i].l,b[i]='0';sort(a+1,a+1+m);
  for(re int i=1,x=0,y;i<=m;++i){b[a[i].id]='1',x+=a[i].l,y=query();if(x!=y)x-=a[i].l,b[a[i].id]='0',ans-=a[i].l;}
  printf("! %d\n",ans);fflush(stdout);
}






int main(){






	

	srand(time(0));
	re int T=1;






	

	

	for(re int i=0; i<T; ++i)WORK();
	

	

	

	return 0;
}