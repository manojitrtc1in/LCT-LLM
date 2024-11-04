
















































































using namespace std;
inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}
const int Maxn=1e5+5;
int n,m;
map<int,int> bit[Maxn];
int dp[Maxn];
int main(){
	scanf("%d %d",&n,&m);
	dp[0]=0;
	int ans=0;
	for (int i=1;i<=m;i++){
		int u,v,w;
		scanf("%d %d %d",&u,&v,&w);
		w++;
		int as=0;
		int nw=w;
		while (w){
			as=max(as,bit[u][w]);
			w-=w&-w;
		}
		dp[i]=as+1;
		while (nw<=100001){
			bit[v][nw]=max(bit[v][nw],dp[i]);
			nw+=nw&-nw;
		}
		ans=max(ans,dp[i]);
	}
	cout<<ans<<endl;
	return 0;
}
