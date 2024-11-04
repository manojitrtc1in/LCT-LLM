#include<bits/stdc++.h>
#define int long long
#define rep(i,n) for(int i=0;i<n;i++)
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
#define inf 10000000000000
#define mod 1000000007
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl '\n'
using namespace std;
int power(int x, unsigned int y){int res = 1;while (y > 0){ if (y & 1){res = res*x;} y = y>>1;x = x*x;}return res;}
int powermod(int x, unsigned int y, int p){int res = 1;x = x % p;while (y > 0){if (y & 1){res = (res*x) % p;}y = y>>1; x = (x*x) % p;}return res;}
int Mod(int x, int m){ return (x%m+m)%m;}
int min(int a,int b){return a<b?a:b;}
int max(int a,int b){return a>b?a:b;}
int dp[4005][4005];
int32_t main()
{

    fastio;
    int t;
    cin>>t;
    while(t--)
    {
       int n,m;
       cin>>n;
       int arr[2*n];
       for(int i=0;i<2*n+5;i++){
       	for(int j=0;j<2*n+5;j++){
       		dp[i][j] = 0;
		   }
	   }
       
       for(int i=0;i<2*n;i++){
         	cin>>arr[i];
	   }
	   set<int,greater<int>>s;
	   for(int i=1;i<=2*n;i++){
	   	  s.insert(i);
	   }
	   vector<int>v;
	   int sz = 0;
	   
	   
	   for(int i=2*n-1;i>=0;i--){
	   	     int x = arr[i];
	   	     if(*s.begin()==x){
	   	        sz++;
	   	        s.erase(s.begin());
	   	        v.pb(sz);
	   	        sz = 0;
			 }
			 else{
			 	sz++;
			 	s.erase(x);
			 }
	   }
	   m = v.size();
	   for(int i=0;i<=n;i++){
	      for(int j=0;j<=m;j++){
	   	   	if(i==0){
	   	      dp[i][j] =1;		
		   }
		   if(j==0){
		   	  continue;
		   }
		   else if(v[j-1]>i){
		   	  dp[i][j] = dp[i][j-1];
		   }
		   else{
		   	dp[i][j] = dp[i][j-1]||dp[i-v[j-1]][j-1];
		   }
			  
		}
	}
	   if(dp[n][m]){
	   	cout<<"YES\n";
	   }
	   else{
	   	cout<<"NO\n";
	   }
    }
  return 0;


}







