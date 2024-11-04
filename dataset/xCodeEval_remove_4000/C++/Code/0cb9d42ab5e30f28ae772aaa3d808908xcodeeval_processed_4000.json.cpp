



































































































































































































using namespace std;
int a[maxn][maxn],b[maxn];
int dp[maxn][maxn][maxn];
set<int>s;
int gcd(int a,int b){
	if(a%b==0)return b;
	return gcd(b,a%b);
}
void cal(int n){
	s.insert(n);
	

	for(int i=2;i*i<=n;i++){
		if(n%i==0){
			s.insert(i);
			s.insert(n/i);
		}
	}
}
void solve(){
	int n,m;
	set<int>().swap(s);
	cin>>n>>m;
	s.insert(1);
	s.insert(2);
	cal(gcd(n-1,m-1));
	cal(gcd(n-2,m));
	cal(gcd(n,m-2));
	
	printf("%d ",s.size());
	for(auto i=s.begin();i!=s.end();i++){
		printf("%d ",*i);
	}putchar(10);
	
}
void init(){
	
} 
signed main(){
	

		

	

	int t=1;
	cin>>t;
	init();
	while(t--)solve();
	 
	
	
	return 0;
}