
using namespace std;
const int N=2e5+7,M=30,pa=998244353,pb=1e9+7; char p[N]; vector<int>vc[N]; bool fk[N];
int n,m,q,l,x,y,sn,l1[N],l2[N],w1[N],w2[N],st[N],qt[N],val[N],vaw[N],les[N],tot,ret,res,ght,pot,vac,leng,of[N],f[N],p1[N],p2[N],ft[N],op[N],oq[N],cnt[N],dfa[N],dfb[N],dfc[N],dep[N],siz[N],ans[N],ch[N][M],e[N][M],a1[N][M],a2[N][M],p3[N][M],p4[N][M],fa[N]; vector<int>v[N],vt[N]; vector<char>s[N],c[N];
struct note{
	int t,k,w,a,b;
}g[N<<1];
struct node{
	int a,b;
}lg[N];
struct query{
	int a,b,c,d;
}wn[N];
struct noti{
	int l,r,k;
}s1[M],s2[M];
inline int read(){
	int num=0; char g=getchar(); while(g<48||57<g) g=getchar();
	while(47<g&&g<58) num=(num<<1)+(num<<3)+g-48,g=getchar(); return num;
}
inline int getfa(int u,int k){
	if(u==0) return 1;
	while(!ch[u][k]){
		if(u==1) return u; u=fa[u];
	}
	return ch[u][k];
}
inline void getit(){
	qt[qt[0]=1]=1;
	int l=1;
	while(l<=qt[0]){
		int u=qt[l++];
		for(int x=0;x<=25;x++)
			if(ch[u][x]) fa[ch[u][x]]=getfa(fa[u],x),qt[++qt[0]]=ch[u][x];
	}
}
inline void add(int u,int x){
	pot=u; if(x>l) return;
	if(!ch[u][p[x]-'a']){
		tot++,ch[u][p[x]-'a']=tot;
	}
	add(ch[u][p[x]-'a'],x+1);
}
inline void search(int u){
	if(!oq[u]) oq[u]=u; dfc[u]=++res;
	if(op[u]) oq[op[u]]=oq[u],search(op[u]);
	for(int i=0;i<v[u].size();i++){
		int x=v[u][i]; if(ft[u]==x||op[u]==x) continue;
		search(x);
	}
}
inline int getopt(int u,int x){
	if(u==1&&!ch[u][x]) return u;
	if(ch[u][x]) return ch[u][x];
	return ch[u][x]=getopt(fa[u],x);
}
inline int lca(int u,int t){
	if(dep[u]<dep[t]) swap(u,t); int z=dep[u]-dep[t];
	for(int i=18;i>=0;i--) if(z&(1<<i)) u=e[u][i]; if(u==t) return u;
	for(int i=18;i>=0;i--) if(e[u][i]!=e[t][i]) u=e[u][i],t=e[t][i]; return e[u][0];
}
inline int jup(int u,int t){
	for(int i=18;i>=0;i--) if(t&(1<<i)) u=e[u][i]; return u;
}
inline void dfs(int u){
	e[u][0]=ft[u],siz[u]=1,p3[u][0]=of[u],p4[u][0]=of[u];
	for(int i=1;i<=18;i++) e[u][i]=e[e[u][i-1]][i-1];
	for(int i=1;i<=18;i++){
		p3[u][i]=(1ll*w1[i-1]*p3[u][i-1]+p3[e[u][i-1]][i-1])%pa;
		p4[u][i]=(1ll*w2[i-1]*p4[u][i-1]+p4[e[u][i-1]][i-1])%pb;
	}
	for(int i=0;i<v[u].size();i++){
		int x=v[u][i]; if(ft[u]==x) continue;
		dep[x]=dep[u]+1,of[x]=s[u][i]-'a';
		cnt[x]=getopt(cnt[u],of[x]);
		ft[x]=u; dfs(x),siz[u]+=siz[x];
		if(siz[op[u]]<siz[x]) op[u]=x;
	}
}
inline void dft(int u){
	dfa[u]=dfb[u]=++ret;
	for(int i=0;i<vt[u].size();i++){
		int x=vt[u][i]; dft(x),dfb[u]=dfb[x];
	}
}
inline bool cmp(note a,note b){
	return a.t<b.t;
}
inline bool tmp(node a,node b){
	return a.a<b.a;
}
inline int lowbit(int u){
	return u&(-u);
}
inline void adds(int u){
	while(u<=n) f[u]++,u+=lowbit(u);
}
inline int getans(int u){
	int ans=0;
	while(u>0) ans+=f[u],u-=lowbit(u); return ans;
}
inline int toget(int a,int b,int c,int d){
	swap(a,b);
	int u=a,x=1,len=0; c=p1[c];
	while(a!=d){
		x=getopt(x,of[a]),a=ft[a];
		if(dfa[c]<=dfa[x]&&dfa[x]<=dfb[c]) len++;
	}
	st[0]=0;
	while(b!=d) st[++st[0]]=b,b=ft[b];
	for(int i=st[0];i>=1;i--){
		x=getopt(x,of[st[i]]);
		if(dfa[c]<=dfa[x]&&dfa[x]<=dfb[c]) len++;
	}
	return len;
}
inline int getsum(int l,int r){
	return getans(r)-getans(l-1);
}
inline void dfs1(int u){
	vaw[u]=dep[u]-val[u],a1[u][0]=vaw[u];
	for(int x=1;x<=18;x++)
		a1[u][x]=min(a1[u][x-1],a1[e[u][x-1]][x-1]);
	for(int i=0;i<v[u].size();i++){
		int x=v[u][i]; if(ft[u]==x) continue; dfs1(x);
	}
}
inline void dfs2(int u){
	vaw[u]=dep[u]-val[u],a2[u][0]=vaw[u];
	for(int x=1;x<=18;x++)
		a2[u][x]=min(a2[u][x-1],a2[e[u][x-1]][x-1]);
	for(int i=0;i<v[u].size();i++){
		int x=v[u][i]; if(ft[u]==x) continue; dfs2(x);
	}
}
inline int get1(int u,int k){
	for(int x=18;x>=0;x--) if(a1[u][x]>k) u=e[u][x];
	return u;
}
inline int get2(int u,int k){
	for(int x=18;x>=0;x--) if(a2[u][x]>k) u=e[u][x];
	return u;
}
inline int gcd(int a,int b){
	if(!b) return a; return gcd(b,a%b);
}
inline long long lcm(int a,int b){
	return 1ll*a*b/gcd(a,b);
}
inline void id0(int a,int b){
	if(b==0){
		x=1,y=0; return;
	}
	id0(b,a%b);
	int xa=y,ya=x-(a/b)*y;
	x=xa,y=ya;
}
inline int getinv(int a,int b){
	id0(a,b); return x;
}
inline long long getret(long long a,long long b){
	if(a>=0) return a;
	long long c=(-a)/b;
	a+=c*b;
	while(a<0) a+=b; return a;
}
inline long long getin(long long a,long long b,long long c){
	a+=((b-a)/c)*c;
	while(a-c>=b) a-=c;
	while(a<b) a+=c;
	return a;
}
inline int getval(int u){
	int z=dep[u],l=0,s1=0,s2=0;
	for(int x=18;x>=0;x--){
		if((1<<x)+l>=z) continue;
		if((1ll*s1*w1[x]+p3[u][x])%pa!=l1[l+(1<<x)]) continue;
		if((1ll*s2*w2[x]+p4[u][x])%pb!=l2[l+(1<<x)]) continue;
		s1=(1ll*s1*w1[x]+p3[u][x])%pa;
		s2=(1ll*s2*w2[x]+p4[u][x])%pb;
		l+=(1<<x),u=e[u][x];
	}
	return l;
}
int main(){
	n=read(),m=read(),q=read(),sn=1e3,dep[1]=1; int u,t; char w;
	w1[0]=26,w2[0]=26;
	for(int i=1;i<=20;i++){
		w1[i]=1ll*w1[i-1]*w1[i-1]%pa;
		w2[i]=1ll*w2[i-1]*w2[i-1]%pb;
	}
	for(int i=1;i<n;i++){
		u=read(),t=read(); w=getchar();
		while(w<'a'||'z'<w) w=getchar();
		v[u].push_back(t),v[t].push_back(u);
		s[u].push_back(w),s[t].push_back(w);
	}
	tot=1;
	for(int i=1;i<=m;i++){
		scanf("%s",p+1),l=strlen(p+1);
		c[i].resize(l);
		for(int x=1;x<=l;x++) c[i][x-1]=p[x];
		add(1,1),p1[i]=pot;
		for(int x=1;x<=l/2;x++) swap(p[x],p[l-x+1]);
		add(1,1),p2[i]=pot;
	}
	getit();
	for(int i=2;i<=tot;i++) vt[fa[i]].push_back(i);
	cnt[1]=1,dfs(1),dft(1),search(1);
	int a,b,f,d;
	for(int x=0;x<=18;x++) a1[0][x]=a2[0][x]=1e9;
	for(int i=1;i<=q;i++){
		a=read(),b=read(),f=read(),d=lca(a,b),swap(a,b);
		wn[i].a=a,wn[i].b=b,wn[i].c=f,wn[i].d=d,les[f]++;
	}
	for(int i=1;i<=m;i++)
		if(1ll*les[i]*c[i].size()>n*40) fk[i]=1;
	for(int i=1;i<=q;i++){
		a=wn[i].a,b=wn[i].b,f=wn[i].c,d=wn[i].d;
		int xt=c[f].size();
		if(-dep[d]+dep[a]-xt>=0&&a!=d){
			leng++,g[leng].k=-1,g[leng].t=dfa[p1[f]]-1;
			g[leng].a=a,g[leng].b=jup(a,-dep[d]+dep[a]-xt),g[leng].w=i;
			leng++,g[leng].k=1,g[leng].t=dfb[p1[f]];
			g[leng].a=a,g[leng].b=jup(a,-dep[d]+dep[a]-xt),g[leng].w=i;
		}
		if(-dep[d]+dep[b]-xt>=0&&b!=d){
			leng++,g[leng].k=-1,g[leng].t=dfa[p2[f]]-1;
			g[leng].a=b,g[leng].b=jup(b,-dep[d]+dep[b]-xt),g[leng].w=i;
			leng++,g[leng].k=1,g[leng].t=dfb[p2[f]];
			g[leng].a=b,g[leng].b=jup(b,-dep[d]+dep[b]-xt),g[leng].w=i;
		}
		int x=jup(a,max(-dep[d]+dep[a]-xt+1,0));
		int y=jup(b,max(-dep[d]+dep[b]-xt+1,0));
		if(!fk[f]) ans[i]+=toget(x,y,f,d);
		else vc[f].push_back(i),wn[i].a=x,wn[i].b=y;
	}
	sort(g+1,g+leng+1,cmp);
	for(int i=1;i<=n;i++) vac++,lg[vac].a=dfa[cnt[i]],lg[vac].b=dfc[i];
	sort(lg+1,lg+vac+1,tmp); int tp=0;
	for(int i=1;i<=leng;i++){
		while(tp+1<=vac&&lg[tp+1].a<=g[i].t)
			adds(lg[tp+1].b),tp++;
		int u=g[i].a,sum=0;
		while(oq[u]!=oq[g[i].b])
			sum+=getsum(dfc[oq[u]],dfc[u]),u=ft[oq[u]];
		sum+=getsum(dfc[g[i].b],dfc[u]);
		ans[g[i].w]+=sum*g[i].k;
	}




	for(int i=1;i<=m;i++){
		if(vc[i].size()==0) continue;
		for(int x=1;x<=tot;x++) val[x]=0;
		int u=1,len=0,l=c[i].size();
		for(int x=1;x<=l;x++) p[x]=c[i][x-1];
		for(int x=1;x<=l;x++){
			l1[x]=(p[x]-'a'+l1[x-1]*26ll)%pa;
			l2[x]=(p[x]-'a'+l2[x-1]*26ll)%pb;
		}
		for(int x=1;x<=n;x++) val[x]=getval(x);
		




		dfs1(1);


		for(int x=1;x<=l;x++) if(x<=l/2) swap(p[x],p[l-x+1]);


		for(int x=1;x<=l;x++){
			l1[x]=(p[x]-'a'+l1[x-1]*26ll)%pa;
			l2[x]=(p[x]-'a'+l2[x-1]*26ll)%pb;
		}
		for(int x=1;x<=n;x++) val[x]=getval(x);




		dfs2(1);
		for(int z=0;z<vc[i].size();z++){
			int x=vc[i][z];
			int a=wn[x].a,b=wn[x].b,d=wn[x].d,q1=0,q2=0;
			swap(a,b);
			while(1){
				a=get1(a,dep[d]);
				int s=get1(ft[a],dep[d]);
				if(dep[a]<dep[d]) break;
				if(dep[s]<dep[d]){
					q1++,s1[q1].l=dep[a]-dep[d];
					s1[q1].r=s1[q1].l;
					s1[q1].k=s1[q1].l+1;
					break;
				}
				q1++,s1[q1].l=dep[a]-dep[d];
				s1[q1].k=dep[a]-dep[s];
				s1[q1].r=s1[q1].l%s1[q1].k;
				a=jup(a,s1[q1].l-s1[q1].r+1);
			}
			a=b;
			while(1){
				a=get2(a,dep[d]);
				int s=get2(ft[a],dep[d]);
				if(dep[a]<dep[d]) break;
				if(dep[s]<dep[d]){
					q2++,s2[q2].l=dep[a]-dep[d];
					s2[q2].r=s2[q2].l;
					s2[q2].k=s2[q2].l+1;
					break;
				}
				q2++,s2[q2].l=dep[a]-dep[d];
				s2[q2].k=dep[a]-dep[s];
				s2[q2].r=s2[q2].l%s2[q2].k;
				a=jup(a,s2[q2].l-s2[q2].r+1);
			}
			for(int x=1;x<=q1;x++) swap(s1[x].l,s1[x].r);
			for(int x=1;x<=q2;x++) s2[x].l=l-s2[x].l,s2[x].r=l-s2[x].r;




			for(int x=1;x<=q1;x++)
				for(int y=1;y<=q2;y++){
					if(s1[x].r<s2[y].l) continue;
					if(s2[x].r<s1[y].l) continue;
					long long s=lcm(s1[x].k,s2[y].k),w=gcd(s1[x].k,s2[y].k);
					if(s1[x].l%w!=s2[y].l%w) continue;
					long long a=(s2[y].l-s1[x].l)/w;
					long long b=1ll*a*getinv(s1[x].k/w,s2[y].k/w)%(s2[y].k/w);


					long long t=s1[x].l+getret(b*s1[x].k,s);
					
					t=getin(t,max(s1[x].l,s2[y].l),s);


					if(t>min(s1[x].r,s2[y].r)) continue;
					int sum=(min(s1[x].r,s2[y].r)-t)/s+1;
					ans[vc[i][z]]+=sum;
				}
		}
	}
	for(int i=1;i<=q;i++) printf("%d\n",ans[i]);
	
	return 0;
}



















