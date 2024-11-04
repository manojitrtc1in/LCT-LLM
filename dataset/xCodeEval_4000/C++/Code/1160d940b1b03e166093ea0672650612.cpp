#include <bits/stdc++.h>
using namespace std;


struct prob{
	long long ss,ts,sl,tl,ps;
	long double prs;
	void read(){
		scanf("%lld%lld%lld%lld%Lf",&ss,&sl,&ts,&tl,&prs);
		prs=1-prs;
		ps=prs*1000000+1e-10;
	}
	bool operator<(const prob& p){
		return tl*p.ps*(1-prs)<p.tl*ps*(1-p.prs);
	}
};

struct DP{
	long long score;
	long double time;
	bool operator<(const DP& d){
		if(score!=d.score){
			return score<d.score;
		}else{
			return time>d.time;
		}
	}
};

DP dp[1565];
prob pr[1005];
DP ans;
int n,t;

int main(){
	scanf("%d%d",&n,&t);
	for(int i=1;i<=n;i++){
		pr[i].read();
	}
	sort(pr+1,pr+n+1);
	for(int i=1;i<=n;i++){
		for(int j=t;j>=0;j--){
			if(j>=pr[i].ts+pr[i].tl){
				DP now;
				now.score=dp[j-pr[i].ts-pr[i].tl].score+1000000*pr[i].ss+pr[i].ps*pr[i].sl;
				now.time=(1-pr[i].prs)*(dp[j-pr[i].ts-pr[i].tl].time+pr[i].ts)+pr[i].prs*j;
				if(dp[j]<now){
					dp[j]=now;
				}
			}
			if(j>=pr[i].ts){
				DP now;
				now.score=dp[j-pr[i].ts].score+1000000*pr[i].ss;
				now.time=dp[j-pr[i].ts].time+pr[i].ts;
				if(dp[j]<now){
					dp[j]=now;
				}
			}
		}
	}
	for(int i=0;i<=t;i++){
		if(ans<dp[i]){
			ans=dp[i];
		}
	}
	printf("%.10Lf %.10Lf\n",ans.score/(long double)1000000.0,ans.time);
	return 0;
}