
using namespace std;


int n;
char s[500005];

namespace Suffixarr{
	int lcp[500005],sa[500005],rnk[500005],tmp[500005];
	int K;
	bool id0(int a,int b){
		if(rnk[a]!=rnk[b]){
			return rnk[a]<rnk[b];
		}else{
			int ra=(a+K<=n?rnk[a+K]:-1);
			int rb=(b+K<=n?rnk[b+K]:-1);
			return ra<rb;
		}
	}
	void getsa(){
		for(int i=0;i<=n;i++){
			sa[i]=i;
			rnk[i]=(i<n?s[i]:-1);
		}
		for(K=1;K<=n;K<<=1){
			sort(sa,sa+n+1,id0);
			tmp[sa[0]]=0;
			for(int i=1;i<=n;i++){
				tmp[sa[i]]=tmp[sa[i-1]]+(id0(sa[i-1],sa[i])?1:0);
			}
			for(int i=0;i<=n;i++){
				rnk[i]=tmp[i];
			}
		}
	}
	void id1(){
		int H=0;
		lcp[0]=0;
		for(int i=0;i<n;i++){
			int j=sa[rnk[i]-1];
			if(H){
				H--;
			}
			for(;j+H<n&&i+H<n;H++){
				if(s[j+H]!=s[i+H]){
					break;
				}
			}
			lcp[rnk[i]-1]=H;
		}
	}
}

using namespace Suffixarr;

int qzh[500005];
vector<int> hv[1000005];
int vcl[500005];
const int o=500000;

int main(){
	scanf("%d",&n);
	scanf("%s",s);
	getsa();
	id1();
	for(int i=0;i<n;i++){
		qzh[i+1]=qzh[i]+(s[i]=='('?1:-1);
	}
	qzh[n+1]=-2*n;
	for(int i=0;i<=n;i++){
		hv[qzh[i]+o].push_back(i);
	}
	stack<int> stk;
	stk.push(n+1);
	for(int i=n;~i;i--){
		while(qzh[i]<=qzh[stk.top()]){
			stk.pop();
		}
		vcl[i]=stk.top();
		stk.push(i);
	}
	long long ans=0;
	for(int I=1;I<=n;I++){
		int i=sa[I]+1;
		int to=qzh[i-1]+o;
		ans+=max(0,(int)(lower_bound(hv[to].begin(),hv[to].end(),vcl[i-1])-lower_bound(hv[to].begin(),hv[to].end(),i+lcp[I])));
	}
	printf("%lld\n",ans);
	return 0;
}