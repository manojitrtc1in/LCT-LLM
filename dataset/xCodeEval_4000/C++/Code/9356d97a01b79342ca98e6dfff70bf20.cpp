#include <bits/stdc++.h>
using namespace std;


int fa[20][100005];
vector<int> nei[100005];
int dep[100005];
int L[100005],R[100005];
int tmc;
vector<int> t[262199];
const int faq=1<<17;

void dfs(int now,int lst){
	L[now]=tmc++;
	dep[now]=dep[lst]+1;
	t[L[now]+faq].push_back(dep[now]);
	for(int i=1;i<=16;i++){
		fa[i][now]=fa[i-1][fa[i-1][now]];
	}
	for(int i:nei[now]){
		dfs(i,now);
	}
	R[now]=tmc-1;
}

int get(int l,int r,int now,int nl,int nr,int x){
	if(nr<l||nl>r){
		return 0;
	}
	if(nl>=l&&nr<=r){
		return upper_bound(t[now].begin(),t[now].end(),x)-lower_bound(t[now].begin(),t[now].end(),x);
	}
	int m=(nl+nr)>>1;
	return get(l,r,now<<1,nl,m,x)+get(l,r,now<<1|1,m+1,nr,x);
}

int n;

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",fa[0]+i);
		nei[fa[0][i]].push_back(i);
	}
	dep[0]=-1;
	dfs(0,0);
	for(int i=faq-1;i>0;i--){
		t[i].resize(t[i<<1].size()+t[i<<1|1].size());
		merge(t[i<<1].begin(),t[i<<1].end(),t[i<<1|1].begin(),t[i<<1|1].end(),t[i].begin());
	}
	int m;
	scanf("%d",&m);
	while(m--){
		int now,len;
		scanf("%d%d",&now,&len);
		int de=dep[now];
		for(int i=0;i<=16;i++){
			if((len>>i)&1){
				now=fa[i][now];
			}
		}
		printf("%d%c",(!!now)*(get(L[now]+1,R[now]+1,1,1,faq,de)-1),m?' ':'\n');
	}
	return 0;
}