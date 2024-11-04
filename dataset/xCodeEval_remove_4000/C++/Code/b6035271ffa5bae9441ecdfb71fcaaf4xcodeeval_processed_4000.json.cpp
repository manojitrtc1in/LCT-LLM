


























































































































































































using namespace std;

typedef long long ll;
inline ll read(){
	ll x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return x*f;
}
int n,m,T,dfn[N],low[N],num,tot,vis[N];
vector<int> G[N],H[N];
stack<int> st;
void Tarjan(int u){
	low[u]=dfn[u]=++num;
	st.push(u);
	for(auto v:G[u]){
		if(!dfn[v]){
			Tarjan(v);
			low[u]=min(low[u],low[v]);
			if(low[v]>=dfn[u]){
				if(st.top()==v){
					H[u].push_back(v);
					H[v].push_back(u);
					st.pop();
				}
				else{
					++tot;
					int t=0;
					H[tot].push_back(u);
					H[u].push_back(tot);
					while(t^v){
						t=st.top();
						st.pop();
						H[tot].push_back(t);
						H[t].push_back(tot);
					}
				}	
			}
		}
		else{
			low[u]=min(low[u],dfn[v]);
		}
	}
}
vector<pair<int,int> > ans;
pair<int,int> dfs(int u,int fa){
	vis[u]=1;
	vector<pair<int,int> > vec;
	for(auto v:H[u]){
		if(v==fa)continue;
		if(v>n)continue;
		vec.push_back(dfs(v,u));
	}
	if(vec.empty())return make_pair(1,u);
	if((int)vec.size()==1)return make_pair(vec[0].first+1,vec[0].second);
	sort(vec.begin(),vec.end(),greater<pair<int,int> >());
	if(fa && vec.size()%2==0 && vec.back().first==1)vec.pop_back();
	pair<int,int> t=make_pair(0,0);
	for(auto [dep,v]:vec){
		if(!t.first)t=make_pair(dep,v);
		else ans.emplace_back(t.second,v),t=make_pair(0,0);
	}
	if(!t.first)return make_pair(1,u);
	return make_pair(t.first+1,t.second);
}
int qcnt;
void Solve(){
	++qcnt;
	for(int i=1;i<=(n<<1);++i){
		G[i].clear(),H[i].clear();	
		dfn[i]=low[i]=vis[i]=0;
	}
	num=0;
	for(int i=1;i<=m;++i){
		int s=read(),u=0;
		while(s--){
			int v=read();
			if(u){
				G[u].push_back(v);
				G[v].push_back(u);
			}
			u=v;
		}		
	}
	tot=n;
	for(int i=1;i<=n;++i){
		if(!dfn[i])Tarjan(i);
	}
	ans.clear();
	for(int i=1;i<=n;++i){
		if(!vis[i]){
			auto x=dfs(i,0);
			if(x.first>2)ans.emplace_back(i,x.second);
		}
	}
		printf("%d\n",(int)ans.size());
		for(auto [x,y]:ans){
			printf("%d %d\n",x,y);
		}
}
int main(){
	while(n=read(),m=read(),n|m){
		Solve();
	}
	return 0;
}


