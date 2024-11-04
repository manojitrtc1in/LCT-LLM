
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<ll> vll;
typedef pair<ll,ll> pll;
#define IN inline
#define RE register
#define F first
#define S second 
#define FF fflush(stdout)
#define random(x) (rand()%x)
#define LOG(m,n) 1.0*log(n)/log(m)
#define lc(p) (p<<1)
#define rc(p) (p<<1|1)
using namespace std;
#define N 205
#define mod 998244353
#define INF 0x3f3f3f3f
int n,m,l[N],r[N],dp[N][N],ls[N];
inline void add(int &a,int b){a+=b;if(a>=mod) a-=mod;}
inline void sub(int &a,int b){a-=b;if(a<0) a+=mod;}
inline int inv(int a,int p){return a==1?1:p-1ll*p*inv(p%a,a)/a;}
int main(){
	int ans,len;
    scanf("%d",&n);
    for(int i=1;i<=n;++i){
        scanf("%d%d",l+i,r+i);++r[i];
        ls[m++]=l[i];ls[m++]=r[i];
    }
    sort(ls,ls+m);
    m=unique(ls,ls+m)-ls;
    for(int i=1;i<=n;++i){
    	l[i]=lower_bound(ls,ls+m,l[i])-ls;
        r[i]=lower_bound(ls,ls+m,r[i])-ls;
	}
	for(int i=0;i<=m;++i) dp[0][i]=1;
    for(int i=1;i<=n;++i){
        for(int j=0;j<m;++j){
            if(l[i]>j||r[i]<=j) continue;
            ans=1;len=ls[j+1]-ls[j];
            for(int k=i;k;--k){
                if(l[k]>j||r[k]<=j) break;
                ans=1ll*ans*(len+i-k)%mod*inv(i-k+1,mod)%mod;
                add(dp[i][j],1ll*ans*dp[k-1][j+1]%mod);
            }
        }
        for(int j=m;j;--j) add(dp[i][j-1],dp[i][j]);
    }
    ans=dp[n][0];
    for(int i=1;i<=n;++i){
    	ans=1ll*ans*inv(ls[r[i]]-ls[l[i]],mod)%mod;
	}
    printf("%d\n",ans);
}