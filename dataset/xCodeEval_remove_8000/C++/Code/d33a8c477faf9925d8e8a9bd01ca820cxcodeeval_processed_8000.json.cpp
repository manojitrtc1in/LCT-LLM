



 





using namespace std;
const int inf=1<<30;
int dp[100010];
vector<int> g[100010];
bool used[100010];
int num[100010];
bool lucky[100010];
int n,m; 
int dfs(int x){
	used[x]=true;
	int re=1;
	for(int i=0;i<g[x].size();i++){
		if(!used[g[x][i]])re+=dfs(g[x][i]);
	}
	return re;
}
void func(int v,int c,int k){
	for(int i=v;i>=c*k;i--){
		dp[i]=min(dp[i],dp[i-c*k]+k); 
	}
	return;
}
void id0(int x){
	if(x>=100010)return;
	lucky[x]=true;
	id0(x*10+4);
	id0(x*10+7);
}
int main(){
	cin>>n>>m;
	for(int i=0;i<m;i++){
		int a,b;
		cin>>a>>b;
		a--;b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	for(int i=0;i<n;i++){
		if(!used[i])num[dfs(i)]++;
	}
	for(int i=0;i<100010;i++)dp[i]=inf;
	dp[0]=0;
	for(int i=1;i<=n;i++){
		int k=num[i];
		while(k>0){
			func(n,i,(k+1)/2);
			k/=2;
		}
	}
	id0(4);
	id0(7);
	int ans=inf;
	

	for(int i=1;i<=n;i++){
		if(lucky[i])ans=min(dp[i],ans);
	}
	if(ans==inf){
		cout<<-1;
	}
	else{
		cout<<ans-1<<endl;
	}
	return 0;
}