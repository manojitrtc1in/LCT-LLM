
using namespace std;


int n;
vector<int> nei[100005];
int fa[25][100005];
int tmc;
int pos[100005];

struct node{
	int idx,tmc,dep;
	node(){}
	node(int idx,int tmc,int dep):idx(idx),tmc(tmc),dep(dep){}
	bool operator<(const node& f)const{
		if(dep!=f.dep){
			return dep<f.dep;
		}else{
			return tmc<f.tmc;
		}
	}
}nds[100005];

int getfa(int now,int dep){
	for(int i=0;i<=20;i++){
		if((dep>>i)&1){
			now=fa[i][now];
		}
	}
	return now;
}

void dfs(int now,int dep){
	nds[now].dep=dep;
	nds[now].tmc=++tmc;
	for(int i:nei[now]){
		dfs(i,dep+1);
	}
}

bool id0(int a,int b,int dep){
	if(a<=0||a>n||b<=0||b>n){
		return 0;
	}
	int c=getfa(a,dep),d=getfa(b,dep);
	

	if(c&&c==d){
		return 1;
	}
	return 0;
}

int bsearch(int v,int nv,int now,int dep){
	while(abs(v-nv)>1){
		int m=(v+nv)>>1;
		

		if(id0(now,nds[m].idx,dep)){
			v=m;
		}else{
			nv=m;
		}
	}
	return v;
}

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",fa[0]+i);
		nei[fa[0][i]].push_back(i);
	}
	for(int i=1;i<=20;i++){
		for(int j=1;j<=n;j++){
			fa[i][j]=fa[i-1][fa[i-1][j]];
		}
	}
	for(int i=1;i<=n;i++){
		nds[i].idx=i;
	}
	dfs(0,0);
	sort(nds+1,nds+1+n);
	for(int i=1;i<=n;i++){
		pos[nds[i].idx]=i;
		

	}
	int q;
	scanf("%d",&q);
	while(q--){
		int now,dep;
		scanf("%d%d",&now,&dep);
		int L=bsearch(pos[now],0,now,dep);
		int R=bsearch(pos[now],n+1,now,dep);
		

		printf("%d%c",R-L,q?' ':'\n');
	}
	return 0;
}