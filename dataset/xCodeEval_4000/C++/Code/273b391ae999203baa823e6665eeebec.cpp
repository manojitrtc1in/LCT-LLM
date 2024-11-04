#include<bits/stdc++.h>
#define ll long long
#define re register
#define cs const

namespace IO{

inline char gc(){
	static cs int Rlen=1<<22|1;static char buf[Rlen],*p1,*p2;
	return (p1==p2)&&(p2=(p1=buf)+fread(buf,1,Rlen,stdin),p1==p2)?EOF:*p1++;
}template<typename T>T get_integer(){
	char c;bool f=false;while(!isdigit(c=gc()))f=c=='-';T x=c^48;
	while(isdigit(c=gc()))x=((x+(x<<2))<<1)+(c^48);return f?-x:x;
}inline int gi(){return get_integer<int>();}
inline char ga(){char c;while(!isalpha(c=gc()));return c;}
inline int get_s(char *s){
	int len=0;char c;while(isspace(c=gc()));
	while(s[len++]=c,!isspace(c=gc()));return len;
}

char obuf[(int)(1e7+7)],*oh=obuf,ch[23];
template<typename T>void print(T a,char c){
	if(a<0)*oh++='-',a=-a;int tl=0;
	do ch[++tl]=a%10; while(a/=10);
	while(tl)*oh++=ch[tl--]^48;*oh++=c; 
}struct obuf_flusher{~obuf_flusher(){fwrite(obuf,1,oh-obuf,stdout);}}Flusher;

}using IO::gi;
using IO::ga;
using IO::get_s;
using IO::print;

using std::cerr;
using std::cout;

cs int N=2e5+7,M=2e5+7;

cs int M1=1e9+7,M2=1e9+9;
inline int add(int a,int b,int mod){return a+b>=mod?a+b-mod:a+b;}
inline int dec(int a,int b,int mod){return a-b<0?a-b+mod:a-b;}
inline int mul(int a,int b,int mod){ll r=(ll)a*b;return r>=mod?r%mod:r;}
inline void Inc(int &a,int b,int mod){a+=b-mod,a+=a>>31&mod;}
inline void Dec(int &a,int b,int mod){a-=b;a+=a>>31&mod;}
inline void Mul(int &a,int b,int mod){a=mul(a,b,mod);}
inline int power(int a,int b,int mod){
	int r=1;for(;b;b>>=1,Mul(a,a,mod))
	if(b&1)Mul(r,a,mod);return r;
}inline int ex_gcd(int a,int b,int &x,int &y){
	if(!b){x=1,y=0;return a;}
	int g=ex_gcd(b,a%b,y,x);
	y-=a/b*x;return g;
}inline int Inv(int a,int mod){
	int x,y;ex_gcd(mod,a,y,x);return x+(x>>31&mod);
}
int get_gr(cs int M){
	int phi=M-1;std::vector<int> p;
	for(int i=2;i*i<=phi;++i)
		if(phi%i==0){
			p.push_back(i);
			while(phi%i==0)phi/=i;
		}
	if(phi>1)p.push_back(phi),phi=M-1;
	for(int re gr=2;;++gr){
		bool flag=true;
		for(int t:p)
			if(power(gr,phi/t,M)==1)
				{flag=false;break;}
		if(flag)return gr;
	}
}cs int g1=get_gr(M1),g2=get_gr(M2);
class Key{
	private:int x,y;
	public:
		Key(){}Key(int a):x(a),y(a){}Key(int _x,int _y):x(_x),y(_y){}
		friend Key operator+(cs Key &a,cs Key &b){return Key(add(a.x,b.x,M1),add(a.y,b.y,M2));}
		friend Key operator-(cs Key &a,cs Key &b){return Key(dec(a.x,b.x,M1),dec(a.y,b.y,M2));}
		friend Key operator*(cs Key &a,cs Key &b){return Key(mul(a.x,b.x,M1),mul(a.y,b.y,M2));}
		Key &operator+=(cs Key &b){Inc(x,b.x,M1);Inc(y,b.y,M2);return *this;}
		Key &operator-=(cs Key &b){Dec(x,b.x,M1);Dec(y,b.y,M2);return *this;}
		Key &operator*=(cs Key &b){Mul(x,b.x,M1);Mul(y,b.y,M2);return *this;}
		friend bool operator==(cs Key &a,cs Key &b){return a.x==b.x&&a.y==b.y;}
		friend bool operator!=(cs Key &a,cs Key &b){return a.x!=b.x||a.y!=b.y;}
};

cs Key bse(g1,g2);
cs Key ibs(Inv(g1,M1),Inv(g2,M2));
Key pw[N],ip[N];

struct AC_auto{
	int son[N][26];int tot;
	int fa[N],el[N],ps[M],nxt[N];
	int in[N],ou[N],tr[N],dfc;
	void ins(char *s,int len,int id){
		int u=0;
		for(int re i=1;i<=len;++i){
			int c=s[i]-'a';
			if(!son[u][c])son[u][c]=++tot;
			u=son[u][c];
		}ps[id]=u;
	}void build_ac(){
		std::queue<int> q;
		for(int re i=0;i<26;++i)
			if(son[0][i])q.push(son[0][i]);
		while(!q.empty()){
			int u=q.front();q.pop();
			for(int re c=0;c<26;++c)
				son[u][c]?
					(q.push(son[u][c]),fa[son[u][c]]=son[fa[u]][c]):
					(son[u][c]=son[fa[u]][c]);
		}for(int re i=1;i<=tot;++i)
			nxt[i]=el[fa[i]],el[fa[i]]=i;
		dfs(0);
	}void dfs(int u){in[u]=++dfc;for(int v=el[u];v;v=nxt[v])dfs(v);ou[u]=dfc;}
	int nx(int p,int c){return son[p][c];}
	void add(int p){for(p=in[p];p;p&=p-1)++tr[p];}
	void dec(int p){for(p=in[p];p;p&=p-1)--tr[p];}
	int qy(int p){p=ps[p];
		int l=in[p],r=ou[p]+1,res=0;
		for(;l<=dfc;l+=l&-l)res+=tr[l];
		for(;r<=dfc;r+=r&-r)res-=tr[r];
		return res;
	}
};

struct atom{int l,r,d;};
struct KMP{
	int *nx,*d,*up,len;
	void build(char *s,int n){
		nx=new int[n+1];d=new int[n+1];up=new int[n+1];
		nx[0]=d[0]=up[0]=0;nx[1]=0,up[1]=1,d[1]=1;len=n;
		for(int re i=2,j=0;i<=len;++i){
			while(j&&s[j+1]!=s[i])j=nx[j];
			if(s[j+1]==s[i])++j;nx[i]=j,d[i]=i-j;
			if(d[i]==d[nx[i]])up[i]=up[nx[i]];else up[i]=i;
		}
	}
};
struct SA{
	int *sa,len;Key *vl;char *s;
	void build(char *s,int n){
		static int x[N],y[N];
		len=n;sa=new int[len+1];vl=new Key[len+1];vl[0]=Key(0);sa[0]=0;
		for(int re i=1;i<=n;++i)
			vl[i]=vl[i-1]+Key(s[i])*pw[i],x[i]=s[i],y[i]=i;
		for(int re i=1;i<=n;++i)x[i+n]=y[i+n]=0;
		int m=128;radix_sort(x,y,m,n);
		for(int re i=1,ct=0;ct<n;i<<=1){
			ct=0;for(int re j=n-i+1;j<=n;++j)y[++ct]=j;
			for(int re j=1;j<=n;++j)
				if(sa[j]>i)y[++ct]=sa[j]-i;
			radix_sort(x,y,m,n);y[sa[1]]=ct=1;
			for(int re i=1;i<=n;++i)std::swap(x[i],y[i]);
			for(int re j=2;j<=n;++j)
				x[sa[j]]=(y[sa[j]]==y[sa[j-1]]&&y[sa[j]+i]==y[sa[j-1]+i])?ct:++ct;
			m=ct;
		}this->s=new char[len+1];
		for(int re i=1;i<=len;++i)
			this->s[i]=s[i];
	}void radix_sort(int *x,int *y,int m,int n){
		static int bin[N];memset(bin+1,0,sizeof(int)*m);
		for(int re i=1;i<=n;++i)++bin[x[i]];
		for(int re i=1;i<=m;++i)bin[i]+=bin[i-1];
		for(int re i=n;i;--i)sa[bin[x[y[i]]]--]=y[i];
	}Key get(int l,int r){return (vl[r]-vl[l-1])*ip[l];}
	int lcp(int,int,int);bool chk(int,int,int);
	std::vector<atom> get(int,int,cs KMP &);
};

AC_auto S,T;
KMP ori[M],rev[M]; 
SA sa_ori[M],sa_rev[M];

int n,m,Q;
char s[N],t[N];int st[M],ed[M];
int el[N],nx[N+N],to[N+N],w[N+N],ec;
Key vl[N];int fa[N],d[N],top[N],pre[N];
int sz[N],son[N],dfn[N],ps[N],dfc;
void dfs1(int u,int p){
	d[u]=d[p]+1,fa[u]=p;sz[u]=1;
	for(int re e=el[u];e;e=nx[e])
		if(to[e]!=p){
			vl[to[e]]=Key(w[e])*pw[d[u]]+vl[u];
			dfs1(to[e],u),sz[u]+=sz[to[e]];pre[to[e]]=w[e];
			if(sz[to[e]]>sz[son[u]])son[u]=to[e];
		}
}void dfs2(int u,int tp){
	top[u]=tp,dfn[u]=++dfc,ps[dfn[u]]=u;
	if(son[u])dfs2(son[u],tp);
	for(int re e=el[u];e;e=nx[e])
		if(to[e]!=fa[u]&&to[e]!=son[u])
			dfs2(to[e],to[e]);
}Key tget(int u,int p){
	return (vl[u]-vl[p])*ip[d[p]];
}int jump(int u,int k){
	assert(k<d[u]);
	while(k>d[u]-d[top[u]]){
		k-=d[u]-d[top[u]]+1;
		u=fa[top[u]];
	}return ps[dfn[u]-k];
}int LCA(int u,int v){
	while(top[u]!=top[v])
		d[top[u]]<d[top[v]]?v=fa[top[v]]:u=fa[top[u]];
	return d[u]<d[v]?u:v;
}

void str_build(char *s,AC_auto &S,KMP ori[],SA sa_ori[]){
	for(int re i=1;i<=m;++i){
		S.ins(s+st[i],ed[i]-st[i],i);
		ori[i].build(s+st[i],ed[i]-st[i]);
		sa_ori[i].build(s+st[i],ed[i]-st[i]);
	}S.build_ac();
}

int U[M],V[M],P[M],id[M],ans[M];
struct Qry{int t,id;};
std::vector<Qry> vec[N];

int sign(int x){
	return x<0?-1:(x>0?1:0);
}
void dfs_solve(int u,int p,int p1,int p2){
	S.add(p1),T.add(p2);
	for(auto t:vec[u])switch(std::abs(t.t)){
		case 1:ans[t.id]+=sign(t.t)*S.qy(id[t.id]);break;
		case 2:ans[t.id]+=sign(t.t)*T.qy(id[t.id]);break;
	}for(int re e=el[u];e;e=nx[e])if(to[e]!=p)
		dfs_solve(to[e],u,S.nx(p1,w[e]-'a'),T.nx(p2,w[e]-'a'));
	S.dec(p1),T.dec(p2);	
}


int solve(cs atom &v1,cs atom &v2,int len){
	if(v1.l+v2.l>len||v1.r+v2.r<len)return 0;
	int t1=(v1.r-v1.l)/(v1.d),t2=(v2.r-v2.l)/(v2.d);
	int x1,x2,y=len-v1.l-v2.l;
	int d1=v1.d,d2=v2.d,d=ex_gcd(d1,d2,x1,x2);
	if(y%d)return 0;
	int dt1=d2/d,dt2=d1/d;x1*=y/d,x2*=y/d;
	if(x1<0){
		int t=(-x1+dt1-1)/dt1;
		x1+=t*dt1;x2-=t*dt2;
	}else {
		int t=x1/dt1;
		x1-=t*dt1,x2+=t*dt2;
	}if(x1>t1||x2<0)return 0;
	int l1=0,r1=(t1-x1)/dt1,l2,r2=x2/dt2;
	if(x2-t2<0)l2=0;else l2=(x2-t2+dt2-1)/dt2;
	if(l1>r1||l2>r2||r1<l2||r2<l1)return 0;
	return std::min(r1,r2)-std::max(l1,l2)+1;
}


int SA::lcp(int ps,int u,int p){
	if(u==p)return 0;int v=jump(u,d[u]-d[p]-1);
	if(d[u]-d[p]>len-sa[ps]+1)u=jump(u,d[u]-(d[p]+len-sa[ps]+1));
	int ct=0;
	while(u!=p){
		int up=d[top[u]]>d[v]?top[u]:v;
		if(tget(up,p)!=get(sa[ps],sa[ps]+d[up]-d[p]-1))u=fa[up];
		else break;
	}if(u==p)return 0;
	int up=d[top[u]]>d[v]?top[u]:v;
	int l=0,r=d[u]-d[up];
	while(l<r){
		int mid=(l+r)>>1;
		int q=::ps[dfn[u]-mid];
		if(tget(q,p)!=get(sa[ps],sa[ps]+d[q]-d[p]-1))l=mid+1;
		else r=mid;
	}return d[u]-d[p]-r;
}bool SA::chk(int ps,int u,int p){
	int l=lcp(ps,u,p);if(l==len)return false;
	if(l==len-sa[ps]+1)return true;
	if(l==d[u]-d[p])return false;
	return pre[jump(u,d[u]-d[p]-l-1)]>this->s[sa[ps]+l];
}std::vector<atom> SA::get(int u,int p,cs KMP &t){
	int l=1,r=len,ps=0;
	while(l<=r){
		int mid=(l+r)>>1;
		if(chk(mid,u,p))
			ps=mid,l=mid+1;
		else r=mid-1;
	}if(!ps)return {};
	l=lcp(ps,u,p);if(l==len-sa[ps]+1)ps=l;
	else {
		ps=sa[ps];ps=len-ps+1;
		while(ps>l)
			if(t.up[ps]>l)ps=t.nx[t.up[ps]];
			else {
				ps=t.up[ps]+(l-t.up[ps])/t.d[ps]*t.d[ps];
			}
	}
	std::vector<atom> vec;
	while(ps){
		vec.push_back({t.up[ps],ps,t.d[ps]});
		ps=t.nx[t.up[ps]];
	}return vec;
}
void Main(){
	n=gi();m=gi(),Q=gi();
	assert(m<=1e5); 
	for(int re i=1;i<n;++i){
		int u=gi(),v=gi(),c=ga();
		nx[++ec]=el[u],el[u]=ec,to[ec]=v,w[ec]=c;
		nx[++ec]=el[v],el[v]=ec,to[ec]=u,w[ec]=c;
	}for(int re i=1;i<=m;++i){
		st[i]=ed[i-1]+1;ed[i]=st[i]+get_s(s+st[i]+1);
		std::reverse_copy(s+st[i]+1,s+ed[i]+1,t+st[i]+1);
	}pw[0]={1,1},ip[0]={1,1};
	for(int re i=1;i<=n;++i)
		pw[i]=pw[i-1]*bse,ip[i]=ip[i-1]*ibs;
	dfs1(1,0);dfs2(1,1);
	str_build(s,S,ori,sa_ori);str_build(t,T,rev,sa_rev);
	for(int re i=1;i<=Q;++i){
		int u=U[i]=gi(),v=V[i]=gi(),t=id[i]=gi();
		int p=P[i]=LCA(U[i],V[i]);
		if(d[u]-d[p]>=ed[t]-st[t]){
			vec[u].push_back({2,i});
			vec[jump(u,d[u]-d[p]-ed[t]+st[t]+1)].push_back({-2,i});
		}if(d[v]-d[p]>=ed[t]-st[t]){
			vec[v].push_back({1,i});
			vec[jump(v,d[v]-d[p]-ed[t]+st[t]+1)].push_back({-1,i});
		}
	}dfs_solve(1,0,0,0);
	for(int re i=1;i<=Q;++i){
		auto v1=sa_rev[id[i]].get(U[i],P[i],ori[id[i]]);
		auto v2=sa_ori[id[i]].get(V[i],P[i],rev[id[i]]);
		for(auto t1:v1)for(auto t2:v2)ans[i]+=solve(t1,t2,ed[id[i]]-st[id[i]]);
		print(ans[i],'\n');
	}
}

inline void file(){
#ifdef zxyoi
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
#endif	
}signed main(){file();Main();return 0;}