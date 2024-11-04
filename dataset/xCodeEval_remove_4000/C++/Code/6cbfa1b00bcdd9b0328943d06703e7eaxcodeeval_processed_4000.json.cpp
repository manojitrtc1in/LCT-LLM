



































































































































































































using namespace std;
char s[maxn];
int a[maxn],b[maxn],a_[maxn],b_[maxn],c[maxn],vis[maxn]; 
int ans[maxn];
void solve(){
	int n;
	cin>>n;
	int d=lower_bound(ans,ans+maxn,n)-ans;
	printf("%d\n",d);
}
void init(){
	int num[3]={2,1,1};
	memset(ans,0x3f,sizeof(ans));
	ans[0]=0;
	ans[1]=0;
	ans[2]=2;
	ans[3]=6;
	ans[4]=10;
	int cnt=10;
	int i=4;
	for(;cnt<=1e9;i++){
		int sel=i%3;
		cnt+=(num[(sel+1)%3]+num[(sel+2)%3]-2)*2;




		

		cnt+=4;
		num[sel]++;
		

		ans[i+1]=cnt;
	}






} 
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
		freopen("1.in","r",stdin);
	
	int t=1;
	cin>>t;
	init();
	while(t--)solve();
	
	
	
	return 0;
}