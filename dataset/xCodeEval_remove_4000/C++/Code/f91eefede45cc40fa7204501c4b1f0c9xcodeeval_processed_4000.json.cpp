
using namespace std;


int n;
char s[500005];
int sa[500005],rnk[500005],tmp[500005],lcp[500005];
int K;
int qzh[500005];
vector<int> pos[1000005];
int Zero=500000;
int vcl[500005];

bool id0(int a,int b){
	if(rnk[a]!=rnk[b]){
		return rnk[a]<rnk[b];
	}else{
		int ra=(a+K<=n?rnk[a+K]:-1);
		int rb=(b+K<=n?rnk[b+K]:-1);
		return ra<rb;
	}
}

namespace Xianduan_Shoooooooooo{
	int dt[8000005];
	void init(int now=1,int nl=0,int nr=1000000){
		dt[now]=n+1;
		if(nl==nr){
			return;
		}
		int m=(nl+nr)>>1;
		init(now<<1,nl,m);
		init(now<<1|1,m+1,nr);
	}
	void add(int to,int x,int now=1,int nl=0,int nr=1000000){
		if(nl==to&&nr==to){
			dt[now]=x;
			return;
		}
		int m=(nl+nr)>>1;
		if(m>=to){
			add(to,x,now<<1,nl,m);
		}else{
			add(to,x,now<<1|1,m+1,nr);
		}
		dt[now]=min(dt[now<<1],dt[now<<1|1]);
	}
	int qry(int l,int r,int now=1,int nl=0,int nr=1000000){
		if(nl>=l&&nr<=r){
			return dt[now];
		}
		if(nl>r||nr<l){
			return n+1;
		}
		int m=(nl+nr)>>1;
		return min(qry(l,r,now<<1,nl,m),qry(l,r,now<<1|1,m+1,nr));
	}
}

using namespace Xianduan_Shoooooooooo;

int main(){
	scanf("%d",&n);
	scanf("%s",s+1);
	init();
	for(int i=1;i<=n+1;i++){
		sa[i-1]=i;
		rnk[i]=(i<=n?s[i]:-1);
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
	int H=0;
	lcp[0]=0;
	for(int i=1;i<=n;i++){
		int j=sa[rnk[i]-1];
		if(H){
			H--;
		}
		for(;j+H<=n&&i+H<=n;H++){
			if(s[j+H]!=s[i+H]){
				break;
			}
		}
		lcp[rnk[i]-1]=H;
	}
	pos[Zero].push_back(0);
	for(int i=1;i<=n;i++){
		qzh[i]=qzh[i-1]+(s[i]=='('?1:-1);
		pos[qzh[i]+Zero].push_back(i);
	}
	for(int i=n;i>=0;i--){
		vcl[i]=qry(0,qzh[i]+Zero-1);
		add(qzh[i]+Zero,i);
	}
	long long ans=0;
	for(int i=1;i<=n;i++){
		int x=sa[i],y=lcp[i];
		int to=qzh[x-1]+Zero;
		int bg=x+y,en=vcl[x-1];
		bg=min(bg,en);
		ans+=(lower_bound(pos[to].begin(),pos[to].end(),en)-lower_bound(pos[to].begin(),pos[to].end(),bg));
	}
	printf("%lld\n",ans);
	return 0;
}