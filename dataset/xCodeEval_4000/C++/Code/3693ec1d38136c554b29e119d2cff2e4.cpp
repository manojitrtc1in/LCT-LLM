
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
#define N 65
#define mod 998244353
#define INF 0x3f3f3f3f
int t,n,m,f=-1;
char s[N][N];
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;++i){
			scanf("%s",s[i]+1);
		}
		f=0;
		for(int i=1;i<=n;++i)for(int j=1;j<=m;++j)if(s[i][j]=='P'){f=-1;break;}
		if(f==0){puts("0");continue;}
		f=1;
		for(int i=1;i<=m;++i)if(s[1][i]=='P'){f=-1;break;}
		if(f==1){puts("1");continue;}
		f=1; 
		for(int i=1;i<=n;++i)if(s[i][1]=='P'){f=-1;break;}
		if(f==1){puts("1");continue;}
		f=1;
		for(int i=1;i<=m;++i)if(s[n][i]=='P'){f=-1;break;}
		if(f==1){puts("1");continue;}
		f=1;
		for(int i=1;i<=n;++i)if(s[i][m]=='P'){f=-1;break;}
		if(f==1){puts("1");continue;}
		if(s[1][1]=='A'||s[1][m]=='A'||s[n][1]=='A'||s[n][m]=='A'){puts("2");continue;}
		for(int i=1;i<=n;++i){
			f=2;
			for(int j=1;j<=m;++j)if(s[i][j]=='P'){f=-1;break;}
			if(f==2){puts("2");break;}
		}
		if(f==2) continue;
		for(int i=1;i<=m;++i){
			f=2;
			for(int j=1;j<=n;++j)if(s[j][i]=='P'){f=-1;break;}
			if(f==2){puts("2");break;}
		}
		if(f==2) continue;
		f=-1;
		for(int i=1;i<=m;++i)if(s[1][i]=='A'){f=3;break;}
		if(f==3){puts("3");continue;}
		for(int i=1;i<=n;++i)if(s[i][1]=='A'){f=3;break;}
		if(f==3){puts("3");continue;}
		for(int i=1;i<=m;++i)if(s[n][i]=='A'){f=3;break;}
		if(f==3){puts("3");continue;}
		for(int i=1;i<=n;++i)if(s[i][m]=='A'){f=3;break;}
		if(f==3){puts("3");continue;}
		f=-1;
		for(int i=1;i<=n;++i){
			for(int j=1;j<=m;++j)if(s[i][j]=='A'){f=4;puts("4");break;}
			if(f==4) break;
		}
		if(f==4) continue;
		puts("MORTAL");
	}
    return 0;
}