
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
#define maxn 2005
char s[maxn];
ii ans[maxn];
int main(){
	int T,n,k,f,l,cnt=0;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%s",&n,&k,s);
		f=n/2-k+1;l=n-(k-1)*2;cnt=0;
		for(int i=0;i<n;++i){
			if(i<f||i>=l&&i%2==0){
				for(int j=i;j<n;++j){
					if(s[j]=='('){
						ans[++cnt]=ii(i+1,j+1);
						reverse(s+i,s+j+1);
						break;
					}
				}
			}else{
				for(int j=i;j<n;++j){
					if(s[j]==')'){
						ans[++cnt]=ii(i+1,j+1);
						reverse(s+i,s+j+1);
						break;
					}
				}
			}
		}
		printf("%d\n",cnt);
		for(int i=1;i<=cnt;++i){
			printf("%d %d\n",ans[i].F,ans[i].S);
		}
	}
    return 0;
}