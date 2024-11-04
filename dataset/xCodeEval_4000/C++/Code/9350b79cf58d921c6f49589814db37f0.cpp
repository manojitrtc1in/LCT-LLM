




























































































































































































#include<bits/stdc++.h>
#define maxn 200005
using namespace std;
int a[maxn],b[maxn];
char s[maxn];
int n,m,k;
int dp[maxn],sum1[maxn],sum2[maxn];

void solve(){
	int ans=0,sum=0,cnt1=0,cnt2=0;scanf("%d%d",&n,&k);
	for(int i=0;i<n;i++){char tmp;cin>>tmp;if(tmp=='0') a[i]=0;else if(tmp=='1') a[i]=1;}
	for(int i=0;i<n;i++) sum+=11*a[i];
	for(int i=0;i<n;i++){if(a[i]==1)break;cnt1++;}
	for(int i=n-1;i>=0;i--){if(a[i]==1)break;cnt2++;}
	for(int i=0;i<n;i++)if(a[i]==1)ans++;
	if(ans==1){
		if(cnt2<=k)puts("1");
		else if(cnt1<=k)puts("10");
		else puts("11");
	}
	else if((cnt1+cnt2)==2*n)puts("0");
	else if((cnt1+cnt2)<=k) printf("%d\n",sum-11);
	else if(cnt2<=k) printf("%d\n",sum-10);
	else if(cnt1<=k) printf("%d\n",sum-1);
	else printf("%d\n",sum);
}
signed main(){
	#ifndef ONLINE_JUDGE
		freopen("1.in","r",stdin);
	#endif
	int t=1;
	cin>>t;
	while(t--)solve();
	
	
	
	return 0;
}