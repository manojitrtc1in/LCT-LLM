#include <bits/stdc++.h>
using namespace std;


int fa[25][100005];
int n,m;
vector<int> nei[100005];
int b[100005],e[100005];
int cen[100005];
int tmc=0;
vector<int> ceng[100005];

void dfs(int now,int cng){
	tmc++;
	b[now]=tmc;
	cen[now]=cng;
	ceng[cng].push_back(tmc);
	for(int i=0;i<nei[now].size();i++){
		dfs(nei[now][i],cng+1);
	}
	tmc++;
	e[now]=tmc;
}

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		int x;
		scanf("%d",&x);
		fa[0][i]=x;
		if(x){
			nei[x].push_back(i);
		}
	}
	for(int i=1;i<=n;i++){
		if(!fa[0][i]){
			dfs(i,1);
		}
	}
	for(int i=1;i<=20;i++){
		for(int j=1;j<=n;j++){
			fa[i][j]=fa[i-1][fa[i-1][j]];
		}
	}
	scanf("%d",&m);
	while(m--){
		int x,y;
		scanf("%d%d",&x,&y);
		int cx=cen[x];
		if(cx<=y){
			printf("0 ");
			continue;
		}
		int now=x;
		for(int i=0;i<=20;i++){
			if((y>>i)&1){
				now=fa[i][now];
			}
		}
		int frm=b[now],to=e[now];
		printf("%d ",lower_bound(ceng[cx].begin(),ceng[cx].end(),to)-lower_bound(ceng[cx].begin(),ceng[cx].end(),frm)-1);
	}
	return 0;
}