#include <bits/stdc++.h>
using namespace std;


int n,m;
vector<int> nei[200005];
int L[200005],R[200005],tmc,dep[200005],wht[200005];
int stklen,stk[200005];

void dfs(int now){
	dep[now]=stklen;
	stklen++;
	L[now]=++tmc;
	wht[tmc]=now;
	for(int i:nei[now]){
		dfs(i);
	}
	R[now]=++tmc;
	wht[tmc]=now;
	stklen--;
}

int qry[200005],qdep[200005];

vector<int> q[200005];
vector<pair<int,int> > q2[200005];

void dfs2(int now){
	stk[stklen]=now;
	for(int i:q[now]){
		if(qdep[i]>=stklen){
			continue;
		}
		int pt=stk[stklen-qdep[i]];
		q2[L[pt]-1].push_back(make_pair(i,-1));
		q2[R[pt]].push_back(make_pair(i,1));
	}
	stklen++;
	for(int i:nei[now]){
		dfs2(i);
	}
	stklen--;
}

int h[200005],ans[200005];

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		int x;
		scanf("%d",&x);
		nei[x].push_back(i);
	}
	dfs(0);
	scanf("%d",&m);
	for(int i=0;i<m;i++){
		scanf("%d%d",qry+i,qdep+i);
		q[qry[i]].push_back(i);
	}
	dfs2(0);
	for(int i=1;i<tmc;i++){
		h[dep[wht[i]]]++;
		for(pair<int,int> j:q2[i]){
			ans[j.first]+=h[dep[qry[j.first]]]*j.second;
		}
	}
	for(int i=0;i<m;i++){
		if(i){
			printf(" ");
		}
		printf("%d",max(ans[i]/2-1,0));
	}
	return 0;
}