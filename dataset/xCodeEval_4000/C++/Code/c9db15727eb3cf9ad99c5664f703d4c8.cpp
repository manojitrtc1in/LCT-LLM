
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<ll> vll;
typedef pair<ll,ll> pll;
typedef pair<ll,pll> plll;
typedef pair<ll,int> pli;
#define F first
#define S second
#define IN inline
#define RE register
#define random(x) (rand()%x)
#define N 500005
#define SQ 717
#define mod 998244353
#define INF 0x3f3f3f3f
using namespace std;
typedef vector<pli>::iterator IT;
int n,len;
ll a[N],tag[SQ];
vector<pli> v[SQ];
int main(){
	int q,op,l,r,sl,sr,pl,pr,f;
	ll k;
	scanf("%d%d",&n,&q);
	len=(n-1)/SQ+1;
	for(int i=1;i<=n;++i){
		scanf("%lld",a+i);
		v[(i-1)/SQ].push_back(pli(a[i],i));
	}
	for(int i=0;i<len;++i) sort(v[i].begin(),v[i].end());
	while(q--){
		scanf("%d",&op);
		if(op==1){
			scanf("%d%d%lld",&l,&r,&k);
			sl=(l-1)/SQ;sr=(r-1)/SQ;
			if(sl==sr){
				for(int i=0;i<v[sl].size();++i) if(v[sl][i].S>=l&&v[sl][i].S<=r) v[sl][i].F+=k;
				sort(v[sl].begin(),v[sl].end());
			}else{
				for(int i=0;i<v[sl].size();++i) if(v[sl][i].S>=l) v[sl][i].F+=k;
				sort(v[sl].begin(),v[sl].end());
				for(int i=0;i<v[sr].size();++i) if(v[sr][i].S<=r) v[sr][i].F+=k;
				sort(v[sr].begin(),v[sr].end());
				for(int i=sl+1;i<sr;++i) tag[i]+=k;
			}
		}else if(op==2){
			scanf("%lld",&k);
			pl=-1;
			for(int i=0;i<len;++i){
				IT it=lower_bound(v[i].begin(),v[i].end(),pli(k-tag[i],0));
				if(it!=v[i].end()&&it->F==k-tag[i]){
					pl=it->S;
					break;
				}
			}
			if(pl==-1){puts("-1");continue;}
			pr=-1;
			for(int i=len-1;i>=0;--i){
				IT it=lower_bound(v[i].begin(),v[i].end(),pli(k-tag[i]+1,0));
				if(it!=v[i].begin()){
					--it;
					if(it->F==k-tag[i]){
						pr=it->S;
						break;
					}
				}
			}
			printf("%d\n",pr-pl);
		}
	}
	return 0;
}