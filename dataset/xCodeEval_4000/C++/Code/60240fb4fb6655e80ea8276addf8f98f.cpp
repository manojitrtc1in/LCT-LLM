
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
using namespace std;
#define maxn 300005
int n,tot=0,x[maxn],y[maxn],lst[maxn],ans[maxn];
vi ad[maxn];
vii qry[maxn];
map<ii,int> hh;
struct BIT{
	int a[maxn];
	inline int lowbit(int x){return x&(-x);}
	inline void update(int p,int v){while(p<=n){a[p]+=v;p+=lowbit(p);}}
	inline int query(int p){
		int res=0;
		while(p){res+=a[p];p-=lowbit(p);}
		return res;
	}
	inline int query(int l,int r){return query(r)-query(l-1);}
}bt;
int main(){
	int k,q,t1,t2,t3;
	ii tmp;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&k);
		for(int j=0;j<k;j++) scanf("%d%d",x+j,y+j);
		for(int j=0;j<k;j++){
			t1=x[(j+1)%k]-x[j];t2=y[(j+1)%k]-y[j];t3=__gcd(abs(t1),abs(t2));
			t1/=t3;t2/=t3;
			tmp=ii(t1,t2);
			if(hh.find(tmp)==hh.end()) hh[tmp]=++tot;
			ad[i].push_back(hh[tmp]);
		}
	}
	scanf("%d",&q);
	for(int i=1;i<=q;i++){
		scanf("%d%d",&t1,&t2);
		qry[t2].push_back(ii(i,t1));
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<ad[i].size();j++){
			t1=ad[i][j];
			if(lst[t1]) bt.update(lst[t1],-1);
			bt.update(i,1);
			lst[t1]=i;
		}
		for(int j=0;j<qry[i].size();j++){
			tmp=qry[i][j];
			ans[tmp.F]=bt.query(tmp.S,i);
		}
	}
	for(int i=1;i<=q;i++) printf("%d\n",ans[i]);
    return 0;
}