













































































































































































































































































































































































































































































































































































































































































































































































































































































































































#include<bits/stdc++.h>
#define fastcall __attribute__((optimize("-O3")))
#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
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














































set<int>S[MAXN];int a[MAXN],tag[MAXN];
int n,ans,fa[MAXN];vector<int>G[MAXN];
int find(int x){return x^fa[x]?fa[x]=find(fa[x]):x;}
il bool cmp(int x,int y){return S[x].size()>S[y].size();}
void dfs(int x,int fat){
  for(auto y:G[x])if(y^fat)dfs(y,x);vector<int>Q;
  for(auto y:G[x])if(y^fat)Q.emplace_back(find(y));
  if(Q.empty()){S[x].insert(a[x]);return;}
  sort(Q.begin(),Q.end(),cmp);int p=Q[0];
  for(re int i=1;i<Q.size();++i){
    int q=Q[i];fa[q]=p;
    for(auto t:S[q]){
      t^=tag[q],t^=tag[p];
      if(S[p].count(t^a[x])){++ans;return;}
    }
    for(auto t:S[q])S[p].insert(t^tag[q]^tag[p]);
  }
  if(S[p].count(a[x]^tag[p])){++ans;return;}
  fa[x]=p,S[p].insert(tag[p]),tag[p]^=a[x];
}
il void WORK(){
  read(n);for(re int i=1;i<=n;++i)fa[i]=i,read(a[i]);
  for(re int i=1,x,y;i<n;++i)read(x),read(y),G[x].emplace_back(y),G[y].emplace_back(x);
  dfs(1,0),write(ans);
}






int main(){




	

	srand(time(0));
	re int T=1;






	

	

	for(re int i=0; i<T; ++i)WORK();
	

	

	

	return 0;
}