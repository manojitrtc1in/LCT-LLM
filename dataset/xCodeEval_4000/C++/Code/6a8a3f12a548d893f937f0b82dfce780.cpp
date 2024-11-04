#include <bits/stdc++.h>
using namespace std;

int n;
int a[1005];
int qzh[1005][8];
int whr[1005][8];
int dp[1005][265];

int check(int m){
	memset(dp,0,sizeof(dp));
	dp[0][0]=1;
	for(int i=0;i<n;i++){
		for(int j=0;j<256;j++){
			if(dp[i][j]){
				dp[i+1][j]=1;
				for(int k=0;k<8;k++){
					if(!((j>>k)&1)){
						if(whr[qzh[i][k]+m][k]){
							dp[whr[qzh[i][k]+m][k]][(j|(1<<k))]=1;
						}
					}
				}
			}
		}
	}
	return dp[n][255];
}

int recheck(int m){
	memset(dp,-1,sizeof(dp));
	dp[0][0]=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<256;j++){
			if(dp[i][j]!=-1){
				dp[i+1][j]=max(dp[i+1][j],dp[i][j]);
				for(int k=0;k<8;k++){
					if(!m){
						dp[i][j|(1<<k)]=max(dp[i][j|(1<<k)],dp[i][j]);
					}
					if(!((j>>k)&1)){
						if(m&&whr[qzh[i][k]+m][k]){
							dp[whr[qzh[i][k]+m][k]][(j|(1<<k))]=max(dp[whr[qzh[i][k]+m][k]][(j|(1<<k))],dp[i][j]);
						}
						if(whr[qzh[i][k]+m+1][k]){
							dp[whr[qzh[i][k]+m+1][k]][(j|(1<<k))]=max(dp[whr[qzh[i][k]+m+1][k]][(j|(1<<k))],dp[i][j]+1);
						}
					}
				}
			}
		}
	}
	return dp[n][255];
}

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",a+i);
		a[i]--;
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<8;j++){
			qzh[i][j]=qzh[i-1][j]+(a[i]==j);
		}
		whr[qzh[i][a[i]]][a[i]]=i;
	}
	int l=0,r=125;
	while(r-l>1){
		int m=(l+r)>>1;
		if(check(m)){
			l=m;
		}else{
			r=m;
		}
	}
	printf("%d\n",l*8+recheck(l));
	return 0;
}