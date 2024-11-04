
#include <bits/stdc++.h>
using namespace std;
typedef int ALL_OF_YOU_ARE_HANZHONGBALLS;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<ll> vll;
typedef pair<ll,ll> pll;
#define IN inline
#define RE register
#define FI first
#define SE second
#define random(x) (rand()%x)
const int maxn=200005;
int n,tot=0,a[maxn],prv[maxn],f[maxn],hd[maxn],t[maxn],nxt[maxn],qy[maxn],vis[maxn];
deque<int> dq;
inline void add(int u,int v){
	t[++tot]=v;
	nxt[tot]=hd[u];
	hd[u]=tot;
}
inline void dfs(int v){
	vis[v]=1;
	int u,ln=dq.size();
	if(ln==n){
		u=dq.front();
		qy[v]=u;
		dq.pop_front();
		for(int i=hd[v];i;i=nxt[i]){
			dq.push_back(t[i]);
			dfs(t[i]);
			dq.pop_back();
		}
		dq.push_front(u);
		return;
	}
	for(int i=hd[v];i;i=nxt[i]){
		dq.push_back(t[i]);
		dfs(t[i]);
		dq.pop_back();
	}
}
int main(){
	int m,q,t1,t2;
	scanf("%d%d%d",&n,&m,&q);
	for(int i=1;i<=n;i++) scanf("%d",a+i);
	if(n>1) for(int i=1;i<=n;i++) prv[a[i]]=a[(i-2+n)%n+1];
	for(int i=1;i<=m;i++){
		scanf("%d",&t1);
		f[t1]=i;
		if(f[prv[t1]]) add(f[prv[t1]],i);
	}
	for(int i=1;i<=m;i++)if(!vis[i]){
		dq.push_back(i);
		dfs(i);
		dq.pop_back();
	}
	for(int i=1;i<=m;i++) qy[i]=max(qy[i],qy[i-1]);
	for(int i=1;i<=q;i++){
		scanf("%d%d",&t1,&t2);
		if(t1<=qy[t2]) printf("1");
		else printf("0");
	}
	puts("");
	return 0;
}

