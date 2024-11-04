#include <bits/stdc++.h>
using namespace std;






































































































































int binpow (int a, int n) {
	if (n == 0)
		return 1;
	if (n % 2 == 1)
		return binpow (a, n-1) * a;
	else {
		int b = binpow (a, n/2);
		return b * b;
	}
}
#define pb push_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define fr first
#define sc second
#define int long long
int sol(int n){
	int cnt=-1;
	while(n>0){
		n/=2;
		cnt++;
	}
	return cnt;
}
int dp[200001][20];
int a,b,c,n,m,i,j,k,x,y,cnt=0,sum=0,res=0;
void solve(){
	int l,r;
	cin>>l>>r;
	vector<int> vec(20);
	int mx=0;
	for(i=0;i<20;i++)
		mx=max(mx,dp[r][i]-dp[l-1][i]);
	cout<<(r-l+1-mx)<<endl;
		
}
main(){
	for(i=0;i<200001;i++){
		int check=i,id=0;
		while(check){
			if(check%2==1)
				dp[i][id]++;
			check/=2;
			id++;
		}
		for(j=0;j<20;j++)
			dp[i][j]+=dp[i-1][j];
	}
	int T=1;
	cin>>T;
	while(T--){
		solve();
	}
}


