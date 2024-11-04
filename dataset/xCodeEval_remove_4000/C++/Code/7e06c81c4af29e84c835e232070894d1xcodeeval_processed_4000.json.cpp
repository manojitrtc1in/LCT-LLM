
















































































using namespace std;
const int Maxn=500005;
pair<pair<int,int>,pair<int,int> > e[Maxn];
int p[Maxn];
vector<int> used;
void _init(){
	for (int i=0;i<Maxn;i++)p[i]=i;
}
void clear(){
	for (int i=0;i<used.size();i++){
		p[used[i]]=used[i];
	}
	used.clear();
}
int findset(int x){
	return p[x]=(p[x]==x)?x:findset(p[x]);
}
void Union(int x,int y){
	x=findset(x);
	y=findset(y);
	p[x]=y;
	return;
}

vector<int> edges[Maxn];
set<pair<int,int> > col[Maxn];
int ans[Maxn];
long long totcost[Maxn];
long long opt[Maxn];
void Union2(int x,int y,int z){
	x=findset(x);
	y=findset(y);
	if (col[x].size()>col[y].size()) swap(x,y);
	for (set<pair<int,int> >::iterator it=col[x].begin();it!=col[x].end();it++){
		if (col[y].find(*it)!=col[y].end()){
			opt[(*it).first]+=1ll*z;
		}
		else{
			col[y].insert(*it);
		}
	}
	p[x]=y;
	return;
}
int main(){
	_init();
	int n,m;
	scanf("%d %d",&n,&m);
	for (int i=1;i<=m;i++){
		scanf("%d %d %d",&e[i].second.first,&e[i].second.second,&e[i].first.first);
		e[i].first.second=i;
	}
	int q;
	scanf("%d",&q);
	for (int i=0;i<q;i++){
		int k;
		scanf("%d",&k);
		bool flag=true;
		for (int j=0;j<k;j++){
			int id;
			scanf("%d",&id);
			edges[i].pb(id);
			totcost[i]+=1ll*e[id].first.first;
			used.pb(e[id].second.first);
			used.pb(e[id].second.second);
			if (findset(e[id].second.first)==findset(e[id].second.second)){
				flag=false;
			}
			else{
				Union(e[id].second.first,e[id].second.second);
			}
		}
		if (!flag){
			ans[i]=-1;
		}
		else{
			for (int j=0;j<used.size();j++){
				

				col[used[j]].insert(mp(i,findset(used[j])));
			}
		}
		clear();
	}
	sort(e+1,e+m+1);
	_init();
	for (int i=1;i<=m;i++){
		pair<int,int> x=e[i].second;
		if (findset(x.first)!=findset(x.second)){
			Union2(x.first,x.second,e[i].first.first);
		}
	}
	for (int i=0;i<q;i++){
		if (ans[i]==-1){
			printf("NO\n");
		}
		else if (totcost[i]==opt[i]){
			printf("YES\n");
		}
		else{
			

			printf("NO\n");
		}
	}
}
