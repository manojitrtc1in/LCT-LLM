








using namespace std;

















void debug_arr(vector<int> &a){
	int len = a.size();
	fr(i,0,len){
		cout<<a[i]<<" ";
	}
	cout<<endl;
}


const int  mod = 1e9 +7;
const int mod1= 998244353;




void solve(){ 
int n; cin>>n;
v(int) a(n);
fr(i,0,n){cin>>a[i];}
v(v(int)) dp(n+1,v(int)(3));


fr(i,0,n){

	dp[i+1][0] = max(dp[i+1][0],dp[i][0] + ((i%2==0)*a[i]));
	if(i+2<=n)
	dp[i+2][1] = max(dp[i+2][1], (max(dp[i][0],dp[i][1]) + (i&1 ? a[i] : a[i+1])));
	dp[i+1][2] = max(dp[i+1][2], (max(dp[i][0],max(dp[i][1],dp[i][2])) + ((i%2==0)*a[i])));
}

cout<<max(dp[n][0],max(dp[n][1],dp[n][2]))<<endl;
 
  
  return;} 




signed main() {
	

	int t; cin>>t; while(t--)
	{solve();}
	
	return 0;
}






















