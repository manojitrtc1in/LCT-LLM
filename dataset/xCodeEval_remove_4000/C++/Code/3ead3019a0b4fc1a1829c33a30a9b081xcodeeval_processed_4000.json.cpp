

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<ll> vll;
typedef pair<ll,ll> pll;









using namespace std;



int n,ans[N],t[N],vis[N],used[N];
ll k,jc[55],dp[55];
inline ll badd(ll a,ll b){
	return min(a+b,LINF);
}
inline ll bmul(ll a,ll b){
	return 1.0*a*b>LINF?LINF:a*b;
}
inline int jgc(int u){
	

	if(u==0) return 1;
	if(vis[u]==1) return -1;
	if(vis[u]==2) return 0;
	vis[u]=1;
	int ret=jgc(ans[u]);
	vis[u]=2;
	return ret;
}
inline ll calc(int p){
	int mx=0,mxp=0,cnt=0,gt;
	for(int i=1;i<=p;++i){
		if(mx<ans[i]){mx=ans[i];mxp=i;}
	}
	

	if(mx==p) return dp[n-p];
	for(int i=mxp;i<=mx;++i) vis[i]=0;
	

	

	for(int i=mxp;i<=mx;++i){
		gt=jgc(i);
		if(gt==-1) return 0;
		

		cnt+=gt;
	}
	

	return bmul(jc[cnt-1],dp[n-mx]);
}
inline void dfs(int lv,ll k,int mx){
	if(lv==n+1) return;
	ll gt;
	if(lv>mx){
		for(int i=lv;i<=n;++i){
			ans[lv]=i;
			gt=calc(lv);
			

			if(k<=gt){
				used[i]=1;
				dfs(lv+1,k,i);
				return;
			}
			k-=gt;
		}
		assert(0);
	}
	for(int i=1;i<mx;++i){
		if(!used[i]){
			ans[lv]=i;
			gt=calc(lv);
			

			if(k<=gt){
				used[i]=1;
				dfs(lv+1,k,mx);
				return;
			}
			k-=gt;
		}
	}
	assert(0);
}
int main(){
	int T;
	scanf("%d",&T);
	jc[0]=1;
	for(int i=1;i<N;++i){
		jc[i]=bmul(i,jc[i-1]);
		

	}
	dp[0]=1;
	for(int i=1;i<N;++i){
		dp[i]=dp[i-1];
		for(int j=2;j<=i;++j){
			dp[i]=badd(dp[i],bmul(jc[j-2],dp[i-j]));
		}
		

	}
	while(T--){
		scanf("%d%lld",&n,&k);
		if(calc(0)<k){
			puts("-1");
			continue;
		}
		memset(ans,0,sizeof(ans));
		memset(used,0,sizeof(used));
		dfs(1,k,0);
		for(int i=1;i<=n;++i){
			printf("%d ",ans[i]);
		}
		puts("");
	}
    return 0;
}
