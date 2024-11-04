
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
#define F first
#define S second
#define random(x) (rand()%x)
const int maxn=3005;
int tot=0,vis[maxn],hd[maxn],t[5005],nxt[5005],cnt[maxn][maxn],bk[3][maxn],ft[3][maxn];
inline void add(int u,int v){
	t[++tot]=v;
	nxt[tot]=hd[u];
	hd[u]=tot;
}
void bfs(int u){
	queue<int> q;
	cnt[u][u]=0;
	vis[u]=1;
	q.push(u);
	int v;
	while(!q.empty()){
		v=q.front();
		q.pop();
		for(int i=hd[v];i;i=nxt[i]){
			if(vis[t[i]]) continue;
			cnt[u][t[i]]=cnt[u][v]+1;
			vis[t[i]]=1;
			q.push(t[i]);
		}
	}
}
int main(){
	int n,m,t1,t2,t3,t4,t5,ans=0,v1=0,v2=0,v3=0,v4=0;
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++){
		scanf("%d%d",&t1,&t2);
		add(t1,t2);
	}
	memset(cnt,-1,sizeof(cnt));
	for(int i=1;i<=n;i++){
		memset(vis,0,sizeof(vis));
		bfs(i);
		for(int j=1;j<=n;j++){
			if(i==j) continue;
			if(cnt[i][j]>cnt[i][ft[0][i]])ft[2][i]=ft[1][i],ft[1][i]=ft[0][i],ft[0][i]=j;
			else if(cnt[i][j]>cnt[i][ft[1][i]])ft[2][i]=ft[1][i],ft[1][i]=j;
			else if(cnt[i][j]>cnt[i][ft[2][i]])ft[2][i]=j;
			if(cnt[i][j]>cnt[bk[0][j]][j])bk[2][j]=bk[1][j],bk[1][j]=bk[0][j],bk[0][j]=i;
			else if(cnt[i][j]>cnt[bk[1][j]][j])bk[2][j]=bk[1][j],bk[1][j]=i;
			else if(cnt[i][j]>cnt[bk[2][j]][j])bk[2][j]=i;
		}
	}
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++){
		if(cnt[i][j]<=0) continue;
		t1=0;t2=0;t3=1;t4=1;t5=cnt[i][j];
		if(bk[t1][i]==j) t1++;
		if(ft[t2][j]==i) t2++;
		if(bk[t1][i]==ft[t2][j]){
			if(bk[t1+t3][i]==j) t3++;
			if(ft[t2+t4][j]==i) t4++;
			if(cnt[bk[t1][i]][i]>0&&cnt[j][ft[t2+t4][j]]>0&&t5+cnt[bk[t1][i]][i]+cnt[j][ft[t2+t4][j]]>ans){
				ans=t5+cnt[bk[t1][i]][i]+cnt[j][ft[t2+t4][j]];
				v1=bk[t1][i];v2=i;v3=j;v4=ft[t2+t4][j];
			}
			if(cnt[bk[t1+t3][i]][i]>0&&cnt[j][ft[t2][j]]>0&&t5+cnt[bk[t1+t3][i]][i]+cnt[j][ft[t2][j]]>ans){
				ans=t5+cnt[bk[t1+t3][i]][i]+cnt[j][ft[t2][j]];
				v1=bk[t1+t3][i];v2=i;v3=j;v4=ft[t2][j];
			}
		}else{
			if(cnt[bk[t1][i]][i]<=0||cnt[j][ft[t2][j]]<=0) continue;
			t5+=cnt[bk[t1][i]][i]+cnt[j][ft[t2][j]];
			if(t5>ans){ans=t5;v1=bk[t1][i];v2=i;v3=j;v4=ft[t2][j];}
		}
	}
	printf("%d %d %d %d\n",v1,v2,v3,v4);
	return 0;
}