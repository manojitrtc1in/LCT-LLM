

















































































using namespace std;
using namespace tr1;
inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}
const int Maxn=500005;
vector<int> M[30];
int n,m;
char tmp[20];
vector<string> pr[15];
string Gt(){
	scanf("%s",&tmp);
	return (string)tmp;
}
string p[16];
int dp[50000][107];
void Cl(){
	for (int i=0;i<(1<<n);i++){
		for (int j=0;j<=n*(n-1)/2;j++){
			dp[i][j]=1e6;
		}
	}
}
int id0(int pos,int v){
	

	if (M[pos].empty()||M[pos].back()<v) return 1e6;
	int ans=M[pos][lower_bound(M[pos].begin(),M[pos].end(),v)-M[pos].begin()];
	return ans;
}
int main(){
	scanf("%d",&n);
	for (int i=0;i<n;i++){
		p[i]=Gt();
	}
	scanf("%d",&m);
	int id=-1,ans=1e9;
	for (int ii=0;ii<m;ii++){
		for (int j=0;j<n;j++){
			M[j].clear();
		}
		int k;
		scanf("%d",&k);
		for (int j=1;j<=k;j++){
			string tt=Gt();
			pr[ii].pb(tt);
			for (int l=0;l<n;l++){
				if (tt==p[l]){
					M[l].pb(j);
				}
			}
		}
	

		Cl();
		dp[0][0]=0;
		for (int i=0;i<(1<<n);i++){
			int cur=0;
			for (int j=0;j<n;j++){
				if (i & (1<<j)) cur++;
			}
			for (int j=0;j<=n*(n-1)/2;j++){
				if (dp[i][j]==1e6) continue;
				if (i==(1<<n)-1){
					if (j<ans){
						ans=j;
						id=ii;
					}
					continue;
				}
				int td=cur;
				for (int k=0;k<n;k++){
					if (i & (1<<k)){
						td--;
						continue;
					}
					dp[i|(1<<k)][j+td]=min(dp[i|(1<<k)][j+td],id0(k,dp[i][j]+1));
				}
			}
		}
	}
	if (id==-1){
		printf("Brand new problem!\n");
	}
	else{
		printf("%d\n[:",id+1);
		for (int i=0;i<(n*(n-1)/2)-ans+1;i++){
			printf("|");
		}
		printf(":]\n");
	}
	return 0;
}
