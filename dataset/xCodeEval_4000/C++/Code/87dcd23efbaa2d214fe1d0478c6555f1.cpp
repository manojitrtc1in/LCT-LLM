#include<bits/stdc++.h>
#define int long long 
using namespace std;
int i,n,m,x,y,z,rt,cnt,mod,T,a[500500],f[500500],dep[500500],u[500500],v[500500],id[500500],add[500500],sum[500500],top[500500],size[500500];
vector<int> E[500500]; 
void build(int l,int r,int num){
	if (l==r){sum[num]=abs(a[l]);return ;} 

	int m=(l+r)>>1;
	build(l,m,num<<1);build(m+1,r,num<<1|1);
	sum[num]=sum[num<<1]+sum[num<<1|1];
	return ;
}
void pushdown(int num,int l,int r){
	if (add[num]==0) return ;
	add[num<<1]+=add[num];  add[num<<1|1]+=add[num];
	sum[num<<1]+=add[num]*l;  sum[num<<1|1]+=add[num]*r;
	add[num]=0;return ;
}
void update(int L,int R,int c,int l,int r,int num){
	if (L<=l&&r<=R) {sum[num]+=c*(r-l+1);add[num]+=c;return ;}
	int m=(l+r)>>1;
	pushdown(num,m-l+1,r-m);
	if (L<=m) update(L,R,c,l,m,num<<1);
	if (R>m) update(L,R,c,m+1,r,num<<1|1);    
	sum[num]=sum[num<<1]+sum[num<<1|1];
	return ; 
}
int query(int L,int R,int l,int r,int num){
	if (L<=l&&r<=R) return sum[num];
	int m=(l+r)>>1,ans=0;
	pushdown(num,m-l+1,r-m);
	if (L<=m) ans+=query(L,R,l,m,num<<1);
	if (R>m) ans+=query(L,R,m+1,r,num<<1|1);
	return ans;
}
void dfs1(int t,int w){
	int i,maxn=0,len=E[t].size();
	dep[t]=dep[w]+1;f[t]=w;size[t]=1;
	for (i=0;i<len;i++) 
		if (E[t][i]!=w){
			dfs1(E[t][i],t); 
			size[t]+=size[E[t][i]];
			if (size[E[t][i]]>maxn)
				maxn=size[E[t][i]],u[t]=E[t][i];
		}	
	return ;
}
void dfs2(int t,int w){
	id[t]=++cnt;a[cnt]=v[t];top[t]=w;
	if (!u[t]) return ;
	dfs2(u[t],w);int i,len=E[t].size();
	for (i=0;i<len;i++)
		if (E[t][i]!=f[t]&&E[t][i]!=u[t])
			dfs2(E[t][i],E[t][i]); 
	return ;
}
int Query(int x,int y){
    int ans=0;
    while (top[x]!=top[y]){
        if (dep[top[x]]<dep[top[y]]) swap(x,y);
        ans+=query(id[top[x]],id[x],1,n,1); 
        x=f[top[x]];
    }
    if (dep[x]>dep[y]) swap(x,y);
    ans+=query(id[x],id[y],1,n,1);
    return ans;
}
void Update(int x,int y,int k){
    while (top[x]!=top[y]){
        if(dep[top[x]]<dep[top[y]]) swap(x,y);
        update(id[top[x]],id[x],k,1,n,1);
        x=f[top[x]];
    }
    if(dep[x]>dep[y]) swap(x,y);
    update(id[x],id[y],k,1,n,1);
    return ;
}
signed main(){
	scanf("%lld %lld",&n,&m);
	for (i=1;i<=n;i++) scanf("%lld",&v[i]);
	for (i=1;i<n;i++){
		scanf("%lld %lld",&x,&y);
		E[x].push_back(y);
		E[y].push_back(x);
	}
	dfs1(1,0);dfs2(1,1);build(1,n,1);
	for (i=1;i<=m;i++){
		scanf("%lld %lld %lld",&T,&x,&y);
		if (T==1)  Update(x,x,abs(y)-abs(v[x])),v[x]=y; 

		if (T==2)  printf("%lld\n",Query(x,y)*2-abs(v[x])-abs(v[y]));  

	}
	return 0;
} 

