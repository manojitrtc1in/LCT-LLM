
















































































using namespace std;
const int Maxn=100005;
inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}
int n,m;
vector<int> G[Maxn];
vector<int> t;
int vis[Maxn][2];
int pre[Maxn][2];
bool cyc;
void dfs(int x,int f){
	if (vis[x][f]==1 || vis[x][1-f]==1) cyc=true;
	if (vis[x][f]) return;
	vis[x][f]=1;
	for (int i=0;i<G[x].size();i++){
		if (pre[G[x][i]][1-f]==0) pre[G[x][i]][1-f]=x;
		dfs(G[x][i],1-f);
	}
	vis[x][f]=2;
}
int main(){
	scanf("%d %d",&n,&m);
	for (int i=1;i<=n;i++){
		int x;
		x=read();if (!x) t.pb(i);
		while (x--){
			int y;
			y=read();
			G[i].pb(y);
		}
		
	}
	int s;
	scanf("%d",&s);
	dfs(s,0);
	for (int i=0;i<t.size();i++){
	

		if (vis[t[i]][1]){
			printf("Win\n");
			vector<int> ans;
			int nx=t[i];
			int ff=1; 
			while (nx!=s || ff!=0){
				ans.pb(nx);
				nx=pre[nx][ff];
				ff=1-ff;
			}
			ans.pb(s);
			reverse(ans.begin(),ans.end());
			for (int i=0;i<ans.size();i++){
				printf("%d ",ans[i]);
			} 
			printf("\n");
			return 0;
		}
	}
	if (cyc){
		printf("Draw\n");
		return 0;
	}
	printf("Lose\n");
	return 0;
}

