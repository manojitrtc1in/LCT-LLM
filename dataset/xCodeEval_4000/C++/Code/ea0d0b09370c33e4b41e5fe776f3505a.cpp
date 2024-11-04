#include <bits/stdc++.h>
using namespace std;


#define int long long
const int N=400005;
int a[N],b[N];
int frm[N],to[N],wei[N];
int fa[N],fwei[N];
vector<int> nei[N];
vector<int> cyc;
bool incyc[N];

inline int other(int now,int e){
	return frm[e]^to[e]^now;
}

bool findcyc(int now,int lst,int frm=-1,int Wei=0){
	if(~fa[now]){
		return 1;
	}
	fa[now]=lst;
	fwei[now]=Wei;
	for(int i:nei[now]){
		if(frm!=i&&findcyc(other(now,i),now,i,wei[i])&&!cyc.size()){
			int to=other(now,i),Now=now;
			while(Now!=to){
				b[cyc.size()]=fwei[Now];
				cyc.push_back(Now);
				Now=fa[Now];
			}
			b[cyc.size()]=wei[i];
			cyc.push_back(to);
			for(int j:cyc){
				incyc[j]=1;
			}
		}
	}
	return 0;
}

int root[N],dep[N],dp[N];
int sz[N];

void dfsdown(int now,int lst){
	sz[now]=1;
	for(int i:nei[now]){
		if(!incyc[other(now,i)]&&lst!=other(now,i)){
			int to=other(now,i),w=wei[i];
			dep[to]=dep[now]+w;
			root[to]=root[now];
			dfsdown(to,now);
			sz[now]+=sz[to];
			dp[now]+=sz[to]*w+dp[to];
		}
	}
}

int ans[N];

void dfsup(int now,int lst,int val=0){
	int n=sz[root[now]],sum=0;
	ans[now]+=val;
	ans[now]+=dp[now];
	for(int i:nei[now]){
		if(!incyc[other(now,i)]&&lst!=other(now,i)){
			int to=other(now,i),w=wei[i];
			dfsup(to,now,val+dp[now]-dp[to]-w*sz[to]+w*(n-sz[to]));
		}
	}
}

int hdres[N],rescyc[N],cnt[N],ps[N];

void Handle(int n,int add=0){
	int sum=a[n];
	int m=0;
	for(int i=0;i<2*n;i++){
		ps[i+1]=ps[i]+(cnt[i]-(i!=0?cnt[i-1]:0))*a[i];
	}
	for(int l=0;l<n;l++){
		int r=l+n;
		while(a[r]-a[m]>=a[m]-a[l]+add){
			m++;
		}
		hdres[l]=ps[m]-ps[l+1]-a[l]*((m!=0?cnt[m-1]:0)-cnt[l]);
	}
}

void getrescyc(){
	int n=cyc.size();
	for(int i=1;i<=2*n;i++){
		a[i]=a[i-1]+b[(i-1)%n];
	}
	for(int i=0;i<2*n;i++){
		cnt[i]=sz[cyc[i%n]];
		if(i){
			cnt[i]+=cnt[i-1];
		}
	}
	Handle(n);
	for(int i=0;i<n;i++){
		rescyc[cyc[i]]+=hdres[i];
	}
	for(int i=0;i<=2*n;i++){
		a[i]=a[2*n]-a[i];
	}
	reverse(a,a+2*n);
	for(int i=0;i<2*n;i++){
		cnt[i]=sz[cyc[n-(i%n)-1]];
		if(i){
			cnt[i]+=cnt[i-1];
		}
	}
	memset(hdres,0,sizeof(hdres));
	Handle(n,1);
	reverse(hdres,hdres+n);
	for(int i=0;i<n;i++){
		rescyc[cyc[i]]+=hdres[i];
	}
}

int sumdep[N];

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	memset(fa,-1,sizeof(fa));
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>frm[i]>>to[i]>>wei[i];
		frm[i]--;to[i]--;
		nei[frm[i]].push_back(i);
		nei[to[i]].push_back(i);
	}
	findcyc(0,0);
	for(int i:cyc){
		root[i]=i;
		dfsdown(i,i);
		dfsup(i,i);
	}
	int sumall=0;
	for(int i=0;i<n;i++){
		sumdep[root[i]]+=dep[i];
		sumall+=dep[i];
	}
	for(int i=0;i<n;i++){
		ans[i]+=sumall-sumdep[root[i]];
		ans[i]+=dep[i]*(n-sz[root[i]]);
	}
	getrescyc();
	for(int i=0;i<n;i++){
		ans[i]+=rescyc[root[i]];
		cout<<ans[i]<<' ';
	}
	cout<<endl;
	return 0;
}
