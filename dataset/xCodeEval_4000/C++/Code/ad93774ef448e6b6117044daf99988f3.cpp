#include <bits/stdc++.h>
using namespace std;

int n,m;
char s[25][25];
int c[25][25];
int chs[1<<21];
int dp[1<<21];
vector<int> hv;

int main(){
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;++i){
		scanf("%s",s[i]);
	}
	for(int i=0;i<n;++i){
		for(int j=0;j<m;++j){
			scanf("%d",c[i]+j);
		}
	}
	memset(chs,0x3f,sizeof(chs));
	for(int i=0;i<n;++i){
		hv.push_back(1<<i);
		for(int j=0;j<m;++j){
			chs[1<<i]=min(chs[1<<i],c[i][j]);
		}
	}
	for(int i=0;i<m;++i){
		for(int j=0;j<26;++j){
			int num=0,maxx=0,sum=0;
			for(int k=0;k<n;++k){
				if(s[k][i]==j+'a'){
					num|=1<<k;
					maxx=max(maxx,c[k][i]);
					sum+=c[k][i];
				}
			}
			if(!num){
				continue;
			}
			if(chs[num]==0x3f3f3f3f){
				hv.push_back(num);
			}
			chs[num]=min(chs[num],sum-maxx);
		}
	}
	memset(dp,0x3f,sizeof(dp));
	dp[0]=0;
	for(int i=0;i<(1<<n)-1;++i){
		for(int j:hv){
			dp[i|j]=min(dp[i|j],dp[i]+chs[j]);
		}
	}
	printf("%d\n",dp[(1<<n)-1]);
	return 0;
}