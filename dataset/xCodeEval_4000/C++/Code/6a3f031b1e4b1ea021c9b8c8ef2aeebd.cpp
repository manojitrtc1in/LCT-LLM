#include<bits/stdc++.h>
using namespace std;
const int N=4e5+7,M=26,K=1e6+3e5+7;
int n,m,lst,nxt,tot,cnt,ft,op[N],fs[N],fa[N],lp[N],tp[N],pts[N],dfs[N],dfn[N],dft[N],res[N],len[N],dep[N],siz[N],ch[N][M];
struct delic {int x,t;}fh[N],gh[N];
struct quert {int ql,l,c,p;}e[N];
struct node  {int x,y,c;}sf[N];
struct query {int l,r;}q[N]; vector<int>vt[N],v[N],ve[N],vp[N],vh[N],vw[N]; char s[N];
#define int long long
long long ret[K],rap[K],ptc[K],opq[K],opf[K],opk[K],val[K<<2],ans[K<<2],opt[K<<2],tag[K<<2],oph[K<<2];
long long suma[K],sumb[K],sumc[K],sumq[K],sumx[K];
inline int read(){
	int num=0; char g=getchar(); while(g<48||57<g) g=getchar();
	while(47<g&&g<58) num=(num<<1)+(num<<3)+g-48,g=getchar(); return num;
}
inline void write(long long u){
	if(u>9) write(u/10); putchar(u%10+'0');
}
inline void ins(int u){
	int p=lst,np=++nxt; len[np]=len[p]+1; lst=nxt;
	while(!ch[p][u]&&p) ch[p][u]=np,p=fa[p]; if(!p) {fa[np]=1; return;}
	int q=ch[p][u]; if(len[q]==len[p]+1) {fa[np]=q; return;}
	int nq=++nxt; memcpy(ch[nq],ch[q],sizeof(ch[q])),fa[nq]=fa[q],fa[np]=nq,fa[q]=nq;
	len[nq]=len[p]+1; while(ch[p][u]==q) ch[p][u]=nq,p=fa[p];
}
inline void find(int u){
	ch[u][0]=fa[u],siz[u]=1; int z=1;
	while((1<<z)<dep[u]) ch[u][z]=ch[ch[u][z-1]][z-1],z++;
	for(int i=0;i<lp[u];i++){
		dep[v[u][i]]=dep[u]+1,find(v[u][i]),dfn[u]=dfn[v[u][i]],siz[u]+=siz[v[u][i]];
		if(siz[fs[u]]<siz[v[u][i]]) fs[u]=v[u][i];
	}
}
inline void search(int u){
	if(!tp[u]) tp[u]=u; dfs[u]=dfn[u]=++cnt,dft[cnt]=u;


	if(fs[u]) tp[fs[u]]=tp[u],search(fs[u]),dfn[u]=dfn[fs[u]];
	for(int i=0;i<lp[u];i++){
		int x=v[u][i]; if(fs[u]==x) continue; search(x),dfn[u]=dfn[x];
	}
}
inline void build(int l,int r,int t){
	if(l==r) {val[t]=op[l]; return;} int d=(l+r)>>1;
	build(l,d,t<<1),build(d+1,r,t<<1|1),val[t]=val[t<<1]+val[t<<1|1];
}
inline void pushdown(int u){
	if(tag[u]) tag[u<<1]+=tag[u],tag[u<<1|1]+=tag[u],ans[u<<1]+=tag[u]*val[u<<1],ans[u<<1|1]+=tag[u]*val[u<<1|1],tag[u]=0;
}
inline void addit(int ql,int qr,int t,int l,int r){
	 if(l==ql&&r==qr) {tag[t]++,ans[t]+=val[t]; pushdown(t); return;} pushdown(t);
	int d=(l+r)>>1;
	if(ql<=d) addit(ql,min(qr,d),t<<1,l,d);
	if(d<qr)  addit(max(d+1,ql),qr,t<<1|1,d+1,r);
	ans[t]=ans[t<<1]+ans[t<<1|1];
}
inline void addsum(int ql,int qr,int t,int l,int r){
	opt[t]++; if(l==ql&&r==qr) {oph[t]+=rap[dft[l]]; return;}
	int d=(l+r)>>1;
	if(ql<=d) addsum(ql,min(qr,d),t<<1,l,d);
	if(d<qr)  addsum(max(d+1,ql),qr,t<<1|1,d+1,r);
	oph[t]=oph[t<<1]+oph[t<<1|1];
}
inline long long getsum(int ql,int qr,int t,int l,int r){
	 if(l==ql&&r==qr) return ans[t]; pushdown(t);
	int d=(l+r)>>1; long long val=0;
	if(ql<=d) val+=getsum(ql,min(qr,d),t<<1,l,d);
	if(d<qr)  val+=getsum(max(d+1,ql),qr,t<<1|1,d+1,r);
	return val;
}
inline long long getsiz(int ql,int qr,int t,int l,int r){
	if(l==ql&&r==qr) return opt[t];
	int d=(l+r)>>1; int siz=0;
	if(ql<=d) siz+=getsiz(ql,min(qr,d),t<<1,l,d);
	if(d<qr)  siz+=getsiz(max(d+1,ql),qr,t<<1|1,d+1,r);
	return siz;
}
inline long long getoph(int ql,int qr,int t,int l,int r){
	if(l==ql&&r==qr) return oph[t];
	int d=(l+r)>>1; int siz=0;
	if(ql<=d) siz+=getoph(ql,min(qr,d),t<<1,l,d);
	if(d<qr)  siz+=getoph(max(d+1,ql),qr,t<<1|1,d+1,r);
	return siz;
}
inline void access(int u){
	while(u>0) addit(dfs[tp[u]],dfs[u],1,1,nxt),u=fa[tp[u]];
}
inline long long getopv(int u){
	long long ans=0; while(u>0) ans+=getsum(dfs[tp[u]],dfs[u],1,1,nxt),u=fa[tp[u]]; return ans;
}
inline int getfa(int u,int k){
	for(int i=18;i>=0;i--) if(len[ch[u][i]]>=k) u=ch[u][i]; return u;
}
inline int getpa(int u,int k){
	for(int i=18;i>=0;i--) if(k&(1<<i)) u=ch[u][i]; return u;
}
inline int lca(int u,int v){
	if(dep[u]<dep[v]) swap(v,u); int z=dep[u]-dep[v];
	for(int i=18;i>=0;i--) if(z&(1<<i)) u=ch[u][i]; if(u==v) return u;
	for(int i=18;i>=0;i--) if(ch[u][i]!=ch[v][i]) u=ch[u][i],v=ch[v][i]; return ch[u][0];
}
inline void suspend(int u){
	int c=u; ve[tp[c]].push_back(u),vp[tp[c]].push_back(0),c=tp[c];
	while(fa[c]>0)
		ve[tp[fa[c]]].push_back(u),vp[tp[fa[c]]].push_back(c),c=tp[fa[c]];
}
inline void addquery(int u){
	int c=pts[u];
	vh[tp[c]].push_back(u),vw[tp[c]].push_back(0),c=tp[c];
	while(fa[c]>0)
		vh[tp[fa[c]]].push_back(u),vw[tp[fa[c]]].push_back(c),c=tp[fa[c]];
}
inline int lowbit(int u){
	return (u&(-u));
}
inline void adda(int u,long long k){
	while(u<=nxt) suma[u]+=k,u+=lowbit(u);
}
inline void addb(int u,long long k){
	while(u<=nxt) sumb[u]+=k,u+=lowbit(u);
}
inline void addc(int u,long long k){
	while(u<=nxt) sumc[u]+=k,u+=lowbit(u);
}
inline long long searcha(int u){
	long long val=0; while(u>0) val+=suma[u],u-=lowbit(u); return val;
}
inline long long searchb(int u){
	long long val=0; while(u>0) val+=sumb[u],u-=lowbit(u); return val;
}
inline long long searchc(int u){
	long long val=0; while(u>0) val+=sumc[u],u-=lowbit(u); return val;
}
inline bool cmp(delic a,delic b){
	return a.t<b.t;
}
inline void addopf(int u){
	if(vp[ft][u]){
		sumq[vp[ft][u]]++,sumx[vp[ft][u]]+=rap[ve[ft][u]];
		adda(dep[fa[vp[ft][u]]]-dep[ft]+1,len[fa[vp[ft][u]]]);
		addb(dep[fa[vp[ft][u]]]-dep[ft]+1,rap[ve[ft][u]]);
		addc(dep[fa[vp[ft][u]]]-dep[ft]+1,1);	
	}
	else{
		adda(dep[ve[ft][u]]-dep[ft]+1,len[ve[ft][u]]);
		addb(dep[ve[ft][u]]-dep[ft]+1,rap[ve[ft][u]]);
		addc(dep[ve[ft][u]]-dep[ft]+1,1);
	}
}
inline void cutopf(int u){
	if(vp[ft][u]){
		sumq[vp[ft][u]]--,sumx[vp[ft][u]]-=rap[ve[ft][u]];
		adda(dep[fa[vp[ft][u]]]-dep[ft]+1,-len[fa[vp[ft][u]]]);
		addb(dep[fa[vp[ft][u]]]-dep[ft]+1,-rap[ve[ft][u]]);
		addc(dep[fa[vp[ft][u]]]-dep[ft]+1,-1);	
	}
	else{
		adda(dep[ve[ft][u]]-dep[ft]+1,-len[ve[ft][u]]);
		addb(dep[ve[ft][u]]-dep[ft]+1,-rap[ve[ft][u]]);
		addc(dep[ve[ft][u]]-dep[ft]+1,-1);
	}
}
inline void getopf(int u){
	int c=vh[ft][u];
	if(!vw[ft][u]){
		int x=pts[c]; int xf=ptc[c];
		if(xf!=x&&tp[xf]!=tp[x]){
			opq[c]-=sumq[xf]*len[x];
			opk[c]-=sumx[xf];
			opf[c]-=sumq[xf];
		}
		opq[c]+=searcha(dep[pts[c]]-dep[ft]+1);
		opk[c]+=searchb(dep[pts[c]]-dep[ft]+1);
		opf[c]+=searchc(dep[pts[c]]-dep[ft]+1);
	}
	else{
		int x=fa[vw[ft][u]];
		opq[c]+=searcha(dep[x]-dep[ft]+1)-sumq[vw[ft][u]]*len[x];
		opk[c]+=searchb(dep[x]-dep[ft]+1)-sumx[vw[ft][u]];
		opf[c]+=searchc(dep[x]-dep[ft]+1)-sumq[vw[ft][u]];
	}
}
inline bool bmp(quert a,quert b){
	return a.l<b.l;
}
inline bool tmp(node a,node b){
	return a.x<b.x;
}
inline void delit(int u){
	ft=u; int ts=0,te=0;
	int lenf=ve[u].size(),leng=vw[u].size();
	for(int i=0;i<lenf;i++)
		if(!vp[u][i])
			fh[i+1].t=len[ve[u][i]]+rap[ve[u][i]]-1,fh[i+1].x=i;
		else 
			fh[i+1].t=len[fa[vp[u][i]]]+rap[ve[u][i]]-1,fh[i+1].x=i;
	for(int i=0;i<leng;i++){
		gh[i+1].t=q[vh[u][i]].r,gh[i+1].x=i;
	}
	sort(fh+1,fh+lenf+1,cmp),sort(gh+1,gh+leng+1,cmp); int la=1,lb=1;
	while(la<=lenf&&lb<=leng){
		if(fh[la].t<=gh[lb].t) addopf(fh[la].x),la++;
		else getopf(gh[lb].x),lb++;
	}
	while(la==lenf+1&&lb<=leng) getopf(gh[lb].x),lb++;
	for(int i=1;i<la;i++) cutopf(fh[i].x);
	for(int i=0;i<lenf;i++){
		ts++,sf[ts].y=rap[ve[ft][i]];
		if(!vp[ft][i]) sf[ts].x=dep[ve[ft][i]]-dep[ft]+1;
		else sf[ts].x=dep[fa[vp[ft][i]]]-dep[ft]+1;
	}
	for(int i=0;i<leng;i++){
		int x=vh[ft][i],h;
		if(!vw[ft][i]){
			if(tp[ptc[x]]==tp[pts[x]]) continue;
			h=pts[x];
		}
		else h=fa[vw[ft][i]];
		te++,e[te].c=x,e[te].ql=q[x].r-len[h]+1,e[te].l=dep[h]-dep[ft]+1,e[te].p=h;
	}
	sort(e+1,e+te+1,bmp),sort(sf+1,sf+ts+1,tmp);
	la=1,lb=1;
	while(la<=ts&&lb<=te){
		if(sf[la].x<=e[lb].l){
			adda(sf[la].y,1);
			addb(sf[la].y,sf[la].y); la++;
		}
		else{
			int c=e[lb].c;
			opq[c]-=len[e[lb].p]*searcha(e[lb].ql);
			opf[c]-=searcha(e[lb].ql);
			opk[c]-=searchb(e[lb].ql);
			lb++;
		}
	}
	while(lb<=te){
		int c=e[lb].c;
		opq[c]-=len[e[lb].p]*searcha(e[lb].ql);
		opf[c]-=searcha(e[lb].ql);
		opk[c]-=searchb(e[lb].ql);
		lb++;
	}
	while(la<=ts){
		adda(sf[la].y,1);
		addb(sf[la].y,sf[la].y); la++;
	}
	for(int i=1;i<=te;i++){
		int c=e[i].c;
		opq[c]+=len[e[i].p]*searcha(e[i].ql);
		opf[c]+=searcha(e[i].ql);
		opk[c]+=searchb(e[i].ql);
	}
	for(int i=1;i<la;i++){
		adda(sf[i].y,-1);
		addb(sf[i].y,-sf[i].y);
	}
}
inline long long retit(long long x){
	return x*(x+1)/2;
}
signed main(){
    scanf("%s",s+1),n=strlen(s+1),lst=1,nxt=1;
    for(int i=n;i>0;i--) res[i]=nxt+1,rap[nxt+1]=i,ins(s[i]-'a');


    for(int i=2;i<=nxt;i++){
		v[fa[i]].push_back(i),lp[fa[i]]++;


	}
	
    memset(ch,0,sizeof(ch)),dep[1]=1,find(1),search(1);
	m=read(); for(int i=1;i<=m;i++) q[i].l=read(),q[i].r=read(),vt[q[i].l-1].push_back(i);
	for(int i=1;i<=nxt;i++) op[dfs[i]]=len[i]-len[fa[i]]; nxt+=10; build(1,nxt,1); 
	for(int i=1;i<=n;i++){
		access(res[i]),addsum(dfs[res[i]],dfs[res[i]],1,1,nxt); int l=vt[i].size();
		for(int x=0;x<l;x++){
			int u=vt[i][x],c=getfa(res[q[u].l],q[u].r-q[u].l+1),f=q[u].r-q[u].l+1;
		long long sum=getopv(fa[c])-getsiz(dfs[c],dfn[c],1,1,nxt)*len[fa[c]];
			opq[u]-=sum,opf[u]=getsiz(dfs[c],dfn[c],1,1,nxt),opk[u]=getoph(dfs[c],dfn[c],1,1,nxt);
		}
	}
	for(int i=1;i<=m;i++){
		pts[i]=fa[getfa(res[q[i].l],q[i].r-q[i].l+1)],ptc[i]=getfa(res[q[i].l],q[i].r-q[i].l+1);
		addquery(i);
	}
	
	for(int i=1;i<=n;i++) suspend(res[i]);
	for(int i=1;i<=nxt;i++) if(i==tp[i]) delit(i);
	for(int i=1;i<=m;i++){
		write(opq[i]+(q[i].r-opf[i])*(q[i].r+1)-retit(q[i].r)+opk[i]),putchar('\n');
	}
	return 0;
}





