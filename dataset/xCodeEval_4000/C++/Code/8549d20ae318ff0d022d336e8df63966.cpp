#include <bits/stdc++.h>
using namespace std;


int dp[4005][4005];
int n;
map<int,int> ff;
vector<int> bg[4005];
int go[4005][4005];
int xx[4005][4005];

struct cr{
	int c,x;
	int l,r;
	cr(){}
	cr(int c,int x):c(c),x(x){
		l=c-x;
		r=c+x;
	}
	void read(){
		scanf("%d%d",&c,&x);
		l=c-x;
		r=c+x;
	}
	bool operator<(const cr &x)const{
		return l<x.l;
	}
}f[2005];

int dfs(int l,int r){
	if(l>r){
		return 0;
	}
	if(dp[l][r]!=-1){
		return dp[l][r];
	}
	int &ans=dp[l][r];
	ans=dfs(l+1,r);
	go[l][r]=0;
	for(int i:bg[l]){
		if(f[i].r<r&&dfs(l,f[i].r)+dfs(f[i].r,r)>ans){
			

			ans=dfs(l,f[i].r)+dfs(f[i].r,r);
			go[l][r]=i;
		}
	}
	ans+=!!xx[l][r];
	

	return ans;
}

void ahh(int l,int r){
	if(l>r){
		return;
	}
	if(!go[l][r]){
		ahh(l+1,r);
	}else{
		
		

		ahh(l,f[go[l][r]].r);
		ahh(f[go[l][r]].r,r);
	}
	if(xx[l][r]){
		printf("%d ",xx[l][r]);
	}
}

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		f[i].read();
		ff[f[i].l];
		ff[f[i].r];
	}
	

	int cnt=0;
	for(auto &i:ff){
		

		i.second=++cnt;
	}
	for(int i=1;i<=n;i++){
		f[i].l=ff[f[i].l];
		f[i].r=ff[f[i].r];
		xx[f[i].l][f[i].r]=i;
		

		bg[f[i].l].push_back(i);
	}
	memset(dp,-1,sizeof(dp));
	printf("%d\n",dfs(1,cnt+1));
	ahh(1,cnt+1);
	return 0;
}