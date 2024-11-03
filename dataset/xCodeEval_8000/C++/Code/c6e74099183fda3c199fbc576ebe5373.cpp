#include<cmath>
#include<math.h>
#include<ctype.h>
#include<algorithm>
#include<bitset>
#include<cassert>
#include<cctype>
#include<cerrno>
#include<cfloat>
#include<ciso646>
#include<climits>
#include<clocale>
#include<complex>
#include<csetjmp>
#include<csignal>
#include<cstdarg>
#include<cstddef>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<ctime>
#include<cwchar>
#include<cwctype>
#include<deque>
#include<exception>
#include<fstream>
#include<functional>
#include<iomanip>
#include<ios>
#include<iosfwd>
#include<iostream>
#include<istream>
#include<iterator>
#include<limits>
#include<list>
#include<locale>
#include<map>
#include<memory>
#include<new>
#include<numeric>
#include<ostream>
#include<queue>
#include<set>
#include<sstream>
#include<stack>
#include<stdexcept>
#include<streambuf>
#include<string>
#include<typeinfo>
#include<utility>
#include<valarray>
#include<vector>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#define LL long long
#define ll   long long
#define ull unsigned long long
#define ULL ull
#define mp make_pair
#define pii pair<int,int>
#define piii pair<int, pii >
#define pll pair <ll,ll>
#define pb push_back
#define PB pop_back
#define p push
#define P pop
#define INF 2147483647
#define ull unsigned long long
#define vi vector < int >
#define vpii vector < pii >
#define pq priority_queue
#define rep(i,n) for (int (i)=0;(i)<n;(i)++)
#define End return 0
#define mi multiset <int>
#define si set <int>
#define sll set<ll>
#define mll multiset<ll>
#define vll vector <ll>
#define Rep(i,a,b) for (int (i)=(a);(i)<=(b);(i)++)







using namespace std;
const int Maxn=200005;
inline void cmax(int &a,int b){
	a=max(a,b);
}
inline void cmin(int &a,int b){
	a=min(a,b);
}
vector<int> G[Maxn];
char ch[Maxn];
int vs[Maxn];
struct node{
	int val,tm;
	node* nxt;
	node(){
		val=0,tm=0;
		nxt=NULL;
	}
};
int siz[Maxn];
LL ans[Maxn];
LL num[Maxn];
bool ban[Maxn];
int use[2000000];
void bs(int x,int p){
	siz[x]=1;
	

	for (int i=0;i<G[x].size();i++){
		if (!ban[G[x][i]] && G[x][i]!=p){
			bs(G[x][i],x);
			siz[x]+=siz[G[x][i]];
		}
	}
}
int nr;
int findc(int x,int p){
	int Mx=0,Mxi=-1;
	for (int i=0;i<G[x].size();i++)	{
		if (G[x][i]!=p && !ban[G[x][i]]){
			if (siz[G[x][i]]>Mx){
				Mx=siz[G[x][i]];
				Mxi=G[x][i];
			}
		}
	}
	if (Mx*2<=siz[nr]) return x;
	return findc(Mxi,x);
}
void dfs2(int x,int p,int dd,vector<pair<int,int> > & tt){
	tt.pb(mp(dd,x));
	for (int i=0;i<G[x].size();i++){
		int v=G[x][i];
		if (!ban[v] && v!=p){
			dfs2(v,x,dd^vs[v],tt);
		}
	}
}
void dfs3(int x,int p){
	for (int i=0;i<G[x].size();i++){
		int v=G[x][i];
		if (!ban[v] && v!=p){
			dfs3(v,x);
			num[x]+=num[v];
			num[v]=0;
		}
	}
	ans[x]+=num[x];
}
int nowtm[2000000];
void solve(int x){
	bs(x,-1);
	nr=x;
	x=findc(x,-1);
	ban[x]=true;
	vector<vector<pair<int,int> > > mss;
	mss.resize(G[x].size());
	for (int i=0;i<G[x].size();i++){
		int v=G[x][i];
		if (!ban[v]){
			solve(v);
			dfs2(v,-1,vs[v],mss[i]);
		}
	}


	use[0]=1;
	vector<int> vvv;
	for (int i=0;i<G[x].size();i++){
		int v=G[x][i];
		if (!ban[v]){
			for (int j=0;j<mss[i].size();j++){
				use[mss[i][j].first]++;
				vvv.pb(mss[i][j].first);
			

			}
		

		}
	}
	vvv.pb(0);
	sort(vvv.begin(),vvv.end());
	vvv.resize(unique(vvv.begin(),vvv.end())-vvv.begin());
	

	

	

	LL delta=0;
	for (int i=0;i<G[x].size();i++){
		int v=G[x][i];
		if (!ban[v]){
			for (int j=0;j<mss[i].size();j++){
				use[mss[i][j].first]--;
			}
			for (int j=0;j<mss[i].size();j++){
				

				for (int k=-1;k<20;k++){
					int tar=mss[i][j].first^((k==-1)?0:(1<<k))^vs[x];
					

					num[mss[i][j].second]+=use[tar];
					if (tar!=0)delta+=use[tar];
					else delta+=use[tar]-1,ans[x]++;
					

					

				}
				

			}
			for (int j=0;j<mss[i].size();j++){
				use[mss[i][j].first]++;
			}
		}
	}
	ans[x]+=delta/2;
	
	

	

	

	for (int i=0;i<G[x].size();i++){
		int v=G[x][i];
		if (!ban[v]){
			dfs3(v,x);
			num[v]=0;
		

		}
	}
	

	
	use[0]=0;
	for (int i=0;i<G[x].size();i++){
		int v=G[x][i];
		if (!ban[v]){
			for (int j=0;j<mss[i].size();j++){
				use[mss[i][j].first]=0;
			}
		}
	}
	ban[x]=false;
}
int main(){
	int n;
	scanf("%d",&n);
	for (int i=1;i<=n-1;i++){
		int u,v;
		scanf("%d %d",&u,&v);
		G[u].pb(v);
		G[v].pb(u);
	}
	scanf("%s",ch+1);
	for (int i=1;i<=n;i++){
		vs[i]=1<<(ch[i]-'a');
	}
	solve(1);
	for (int i=1;i<=n;i++){
		printf("%I64d ",ans[i]+1);
	}
	printf("\n");
}

