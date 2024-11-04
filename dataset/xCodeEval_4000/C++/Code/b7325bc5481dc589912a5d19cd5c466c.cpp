







#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long 
#define fr(i,s,e) for(int i=s;i<e;++i)
#define fr1(i,s,e) for(int i=s;i>e;--i)
#define p0(a) cout << a <<" "
#define p1(a) cout << a << endl
#define p2(a, b) cout << a << " " << b << endl
#define p3(a, b, c) cout << a << " " << b << " " << c << endl
#define p4(a, b, c, d) cout << a << " " << b << " " << c << " " << d << endl
#define INF (ll)1e18 + 100
#define v(d) vector<d>
#define pr pair<int, int>
#define pr1(d1,d2) pair<d1,d2>
#define pb push_back
#define f first
#define s second
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);	
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
	

	fast
	int t; cin>>t; while(t--)
	{solve();}
	
	return 0;
}






















