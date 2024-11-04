



#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>
#include<set>
#include<map>
#include<stack>
#include<time.h>
#include<cstdlib>
#include<cmath>
#include<list>
using namespace std;
#define MAXN 10000006
#define eps 1e-9
#define For(i,a,b) for(int i=a;i<=b;i++)
#define Fore(i,a,b) for(int i=a;i>=b;i--)
#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
#define mkp make_pair
#define pb push_back
#define cr clear()
#define sz size()
#define met(a,b) memset(a,b,sizeof(a))
#define iossy ios::sync_with_stdio(false)
#define fr freopen
#define pi acos(-1.0)
#define Vector Point
#define fir first
#define sec second
#define it_s_too_hard main
const int maxn=2000006;
const long long linf=1LL<<62;
const int iinf=1<<30;
const double dinf=1e17;
const int Mod=1e9+7;
typedef long long ll;
typedef long double ld;
const long long md=1000000007;
int n,m,k,v[200005],u[200005];
vector<int>eg[200005];
int mp[200005],ans[200005];
set<pair<int,int> >s;
set<pair<int,int> >::iterator it;
int nx[200005],nd[200005],rt,fom;
bool vis[200005];
map<pair<int,int>,int>mpp;
void del(int x){
	For(i,1,eg[x].sz){
		fom=eg[x][i-1];
		if(vis[mpp[mkp(x,fom)]]){
			vis[mpp[mkp(x,fom)]]=0;
			s.erase(mkp(mp[fom],fom));
			mp[fom]--;
			s.insert(mkp(mp[fom],fom));
		}
	}
}
void I_can_t_solve_it(){
	cin>>n>>m>>k;met(mp,0);s.clear();mpp.clear();met(vis,0);
	For(i,1,n) eg[i].clear();
	For(i,1,m){
		scanf("%d%d",&u[i],&v[i]);
		mp[u[i]]++;
		mp[v[i]]++;
		eg[u[i]].pb(v[i]);eg[v[i]].pb(u[i]);
		mpp[mkp(u[i],v[i])]=i;
		mpp[mkp(v[i],u[i])]=i;vis[i]=1;
	}
	For(i,1,n) s.insert(mkp(mp[i],i));
	Fore(i,m,1){
		while(1){
			rt=0;it=s.begin();
			while(it!=s.end()){
				nx[rt]=(*it).first;
				if(nx[rt]<k) nd[rt++]=(*it).second;
				else break;
				it++;
			}
			if(rt==0) break;
			For(j,0,rt-1) s.erase(mkp(mp[nd[j]],nd[j])),del(nd[j]);
		}
		ans[i]=s.sz;
		if(vis[i]){
			s.erase(mkp(mp[u[i]],u[i]));
			s.erase(mkp(mp[v[i]],v[i]));
			mp[u[i]]--;mp[v[i]]--;
			s.insert(mkp(mp[u[i]],u[i]));
			s.insert(mkp(mp[v[i]],v[i]));
			vis[i]=0;
		}
	}
	For(i,1,m) printf("%d\n",ans[i]);
}
int it_s_too_hard(){
	int t=1;
	while(t--) I_can_t_solve_it();
	return 0;
}
