




























































































































































































#include<bits/stdc++.h>
#define maxn 200005
using namespace std;
int a[maxn],b[maxn];
char s[maxn];
int n,m;
int dp[maxn],sum1[maxn],sum2[maxn];

void solve(){
	scanf("%d%d",&n,&m);
	scanf("%s",s);






	if(s[n-1]=='0'){
		int pos=-1;
		for(int i=n-1;i>=0;i--){


			if(s[i]=='1'){
				pos=i;
				break;
			}
		}


		if(pos!=-1&&n-1-pos<=m){
			m-=n-1-pos;
			for(int i=pos;i<n-1;i++){
				s[i]=s[i+1];
			}
			s[n-1]='1';
		}
	}


	if(s[0]=='0'){
		int pos=-1;
		for(int i=1;i<n;i++){
			if(s[i]=='1'){
				pos=i;
				break;
			}
		}
		

		if(pos!=-1&&m>=pos&&pos!=n-1){
			m-=pos;
			for(int i=pos;i>=1;i--){
				s[i]=s[i-1];
			}
			s[0]='1';
		}
	}
	
	int x=s[0]-'0';
	int ans=0;
	for(int i=1;i<n;i++){
		x=x*10+s[i]-'0';
		x%=100;
		ans+=x;
	}
	








	printf("%d\n",ans);
}
signed main(){
	#ifndef ONLINE_JUDGE
		freopen("1.in","r",stdin);
	#endif
	int t=1;
	cin>>t;
	if(t==247){
		#define xia0ji233
	}
	while(t--)solve();
	
	
	
	return 0;
}