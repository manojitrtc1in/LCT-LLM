#include<bits/stdc++.h>
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
using namespace std;

typedef long long LL;
typedef pair<char,int> pci;
typedef pair<int,char> pic;
typedef pair<LL,int> pli;
typedef pair<int,int> pii;
typedef pair<int, pii > piii;
const LL INF=(LL)2e18;
const int inf=2e9,mod=1e9+7;
const int N=2e5+10,M=1800010;
const LL bas=233,hsmod=(LL)100000000000031;
const int hsmsk=(1<<22)-1;

LL qpow(LL x,LL y) {LL ret=1; for(;y;y>>=1,x=x*x%mod) if(y&1) ret=ret*x%mod; return ret;}

namespace KMP
{
	LL rdown(LL p,LL q){return q<0?rdown(-p,-q):(p>0?p/q:-(-p+q-1)/q);}
	LL rup(LL p,LL q){return -rdown(-p,q);}
	struct sub
	{
		int s,d,cnt;

		sub(int S=0,int D=0,int CNT=0){s=S;d=D;cnt=CNT;}
		int end()const{return s+(cnt-1)*d;}
		bool has(int x)const{return x>=s&&x<=end()&&(x-s)%d==0;}
		int calc(const sub &t)
		{
			if(d==t.d)
			{
				if((s-t.s)%d!=0)return 0;
				else return max(0,(min(end(),t.end())-max(s,t.s))/d+1);
			}
			else if(cnt==1)return t.has(s);
			else return has(t.s);
		}
		sub flip(int x){return sub(x-(s+(cnt-1)*d),d,cnt);}
	};
	vector<int> Fail[N],Slink[N];
	void construct(char s[],int n,int id)
	{
		vector<int> &fail=Fail[id],&slink=Slink[id];
		fail.resize(n+1);
		slink.resize(n+1);
		fail[0]=0;fail[1]=0;
		for(int i=2;i<=n;i++)
		{
			int &p=fail[i];
			p=fail[i-1];
			while(p&&s[p+1]!=s[i])p=fail[p];
			if(s[p+1]==s[i])p++;
		}
		for(int i=1;i<=n;i++)slink[i]=fail[i]==0?0:(i-fail[i]==fail[i]-fail[fail[i]]?slink[fail[i]]:fail[i]);
	}
	vector<sub> extract(int id,int x)
	{
		vector<int> &fail=Fail[id],&slink=Slink[id];
		assert(x<fail.size()&&x<slink.size());
		vector<sub> ret;
		while(x)
		{
			int d=x-fail[x];
			ret.pb(sub(slink[x]+d,d,(x-slink[x])/d));
			x=slink[x];
		}
		reverse(ret.begin(),ret.end());
		if(ret.back().cnt>1)ret.back().cnt--,ret.pb(sub(ret.back().end()+ret.back().d,1,1));
		return ret;
	}
	int query(int x,int xl,int y,int yl,int tot)
	{
		if(xl==0||yl==0||xl+yl<tot)return 0;
		vector<sub> vx=extract(x,xl);
		vector<sub> vy=extract(y,yl);
		for(int i=0;i<vy.size();i++)vy[i]=vy[i].flip(tot);
		reverse(vy.begin(),vy.end());
		int itx=0,ity=0,ret=0;
		while(itx<vx.size()&&ity<vy.size())
		{
			ret+=vx[itx].calc(vy[ity]);
			if(vx[itx].end()<=vy[ity].end())itx++;
			else ity++;
		}
		return ret;
	}
};




struct BIT
{
	int bit_table[M];
	int lowbit(int x) {return x&(-x);}
	void add(int x,int v) {for(;x<M;x+=lowbit(x)) bit_table[x]+=v;}
	int query(int x) {int ret=0;for(;x;x-=lowbit(x)) ret+=bit_table[x];return ret;}
}bit;

struct HashTable
{
	int hs[hsmsk],val[hsmsk];
	HashTable() {memset(hs,-1,sizeof(hs));memset(val,-1,sizeof(val));}
	int getpos(int p) {return ((p<<5)^(p>>3))&hsmsk;}
	int find(int c) {int p=getpos(c);while(~hs[p] && hs[p]^c) p=(p+1)&hsmsk; return val[p];}
	int& get(int c) 
	{
		int p=getpos(c); while(~hs[p] && hs[p]^c) p=(p+1)&hsmsk;
		if(!~hs[p]) hs[p]=c,val[p]=-1; return val[p];
	} 
};

namespace ACM
{
	int tot=1,fa[M],pc[M]; LL hs[M];
	pli hsarr[M]; vector<pci> go[M];
	HashTable mp;
	
	int insert(int p,int c)
	{
		int &q=mp.get(p<<8|c);
		if(q==-1)
		{
			q=++tot;fa[q]=p;pc[q]=c;hs[q]=(hs[p]*bas+c+1)%hsmod;
			go[p].pb(mkp(c,q));
			assert(tot<M);
		}
		return q;
	}	
	
	int ind,fail[M],idfn[M],idfnr[M];
	vector<int> con[M];
	
	void idfs(int x)
	{
		idfn[x]=++ind;
		for(int i=0;i<con[x].size();++i) idfs(con[x][i]);
		idfnr[x]=ind;
	}
	
	int son[M],top[M],dep[M];
	set<int> st[M];
	int dfs1(int x)
	{
		int sz=1,mx=0;
		for(int i=0;i<go[x].size();++i)
		{
			int v=go[x][i].se;dep[v]=dep[x]+1;
			int szv=dfs1(v);sz+=szv;
			if(szv>mx) son[x]=v,mx=szv;
		}
		return sz;
	}
	
	void dfs2(int x,int tp)
	{
		top[x]=tp; if(!son[x]) return;
		dfs2(son[x],tp);
		for(int i=0;i<go[x].size();++i)
		{
			int v=go[x][i].se;
			if(v==son[x]) continue;
			dfs2(v,v);	
		}	
	} 
	
	void construct() {dep[1]=0;dfs1(1);dfs2(1,1);}
	void flip(int x)
	{
		int g=top[x];
		if(st[g].find(dep[x])==st[g].end()) st[g].insert(dep[x]);
		else st[g].erase(dep[x]);
	}
	
	int query(int x)
	{
		while(x)
		{
			if(st[top[x]].size()>0 && *st[top[x]].begin()<=dep[x]) return *(--st[top[x]].lower_bound(dep[x]+1));
			x=fa[top[x]];
		}
		return 0;
	}
	
	int q[M],qn;
	void build()
	{
		construct();
		for(int i=1;i<=tot;++i) hsarr[i]=mkp(hs[i],i);
		sort(hsarr+1,hsarr+tot+1);qn=0;q[qn++]=1;
		for(int i=0;i<qn;++i)
		{
			int x=q[i];
			for(int j=0;j<go[x].size();++j)	q[qn++]=go[x][j].se;
		}
		fail[1]=1;
		for(int i=1;i<qn;++i)
		{
			int x=q[i],&p=fail[x];
			if(fa[x]==1) p=1;
			else
			{
				p=fail[fa[x]];
				while(p^1 && !~mp.find(p<<8|pc[x])) p=fail[p];
				if(~mp.find(p<<8|pc[x])) p=mp.find(p<<8|pc[x]);
			}
			con[fail[x]].pb(x);
		}
		idfs(1);
	}
	
	int qans[M],qans2[M];
	vector<pii> qr[M],qr2[M];
	
	void dfs_solve1(int x)
	{
		bit.add(idfn[x],1);
		for(int i=0;i<qr[x].size();++i)
		{
			int pos=qr[x][i].fi;
			qans[qr[x][i].se]+=bit.query(idfnr[pos])-bit.query(idfn[pos]-1);
		}
		for(int i=0;i<go[x].size();++i) dfs_solve1(go[x][i].se);
		bit.add(idfn[x],-1);
	}
	
	void dfs_solve2(int x,LL hs=0,LL hsbs=1)
	{
		int p=lower_bound(hsarr+1,hsarr+tot+1,mkp(hs,0))-hsarr;
		if(hsarr[p].fi==hs) flip(hsarr[p].se);
		for(int i=0;i<qr2[x].size();++i) qans2[qr2[x][i].se]=query(qr2[x][i].fi);
		for(int i=0;i<go[x].size();++i) dfs_solve2(go[x][i].se,(hs+hsbs*(go[x][i].fi+1))%hsmod,hsbs*bas%hsmod);
		if(hsarr[p].fi==hs) flip(hsarr[p].se);
	}
	
	void add_query(int ui,int vi,int si,int ti,int id)
	{
		qr[ui].pb(mkp(ti,id));qr[vi].pb(mkp(si,id));
		qr2[si].pb(mkp(ui,id<<1));qr2[ti].pb(mkp(vi,id<<1|1));
	}
	
	piii get_query(int id) {return mkp(qans[id],mkp(qans2[id<<1],qans2[id<<1|1]));}
	
	void solve()
	{
		memset(qans,0,sizeof(qans));
		dfs_solve1(1);dfs_solve2(1);
	}
};

namespace solution
{
	int n,m,q,cur_rt,cur_dp,an;
	int qu[N],qv[N],qx[N],uid[N],vid[N];
	int dp[N],siz[N],arr[N],gr[N],id[N];
	char s[N];
	vector<pic>con[N]; vector<pii>qr[N]; vector<int> sid[N];
	
	void pdfs(int x,int f=-1)
	{
		siz[x]=1;arr[an++]=x;dp[x]=cur_dp+1;
		for(int i=0;i<con[x].size();++i)
		{
			int v=con[x][i].fi;
			if(v==f || dp[v]<cur_dp) continue;
			pdfs(v,x);siz[x]+=siz[v];
		}
	}
	
	int findroot(int x)
	{
		an=0;pdfs(x); int ret=x;
		for(int i=0;i<an;++i) if(siz[arr[i]]*2>=siz[x] && siz[arr[i]]<siz[ret]) ret=arr[i];
		return ret;
	}
	
	void dfs(int x,int f,int g)
	{
		gr[x]=g;
		for(int i=0;i<con[x].size();++i)
		{
			int v=con[x][i].fi;
			if(v==f || dp[v]<cur_dp) continue;
			id[v]=ACM::insert(id[x],con[x][i].se-'a');
			dfs(v,x,f==-1?v:g);
		}
	}
	
	void solve(int X,int d)
	{
		cur_dp=d;int rt=findroot(X);cur_rt=rt;
		dp[rt]=d;id[rt]=1;dfs(rt,-1,rt);
		static bool vis[N];
		for(int i=0;i<an;++i) vis[arr[i]]=1;
		for(int i=0;i<an;++i)
		{
			int x=arr[i];
			for(int j=0;j<qr[x].size();++j)
			{
				int y=qr[x][j].fi;
				if(vis[y] && gr[y]^gr[x]) uid[qr[x][j].se]=id[x],vid[qr[x][j].se]=id[y];
			}
		}
		for(int i=0;i<an;++i) vis[arr[i]]=0;
		for(int i=0;i<con[rt].size();++i)
		{
			int v=con[rt][i].fi;
			if(dp[v]<d) continue;
			solve(v,d+1);
		}
	}
	
	void end_of_the_world()
	{
		scanf("%d%d%d",&n,&m,&q);
		for(int i=1;i<n;++i)
		{
			int u,v;char c[2]; scanf("%d%d%s",&u,&v,c);
			con[u].pb(mkp(v,c[0]));con[v].pb(mkp(u,c[0]));
		}
		for(int i=1;i<=m;++i)
		{
			scanf("%s",s+1);int l=strlen(s+1),p=1; sid[i].pb(1);
			for(int j=1;j<=l;++j) p=ACM::insert(p,s[j]-'a'),sid[i].pb(p);
			KMP::construct(s,l,i); 
			reverse(s+1,s+l+1);p=1;sid[i+m].pb(1);
			for(int j=1;j<=l;++j) p=ACM::insert(p,s[j]-'a'),sid[i+m].pb(p);
			KMP::construct(s,l,i+m);
		}
		for(int i=1;i<=q;++i)
		{
			int u,v,x;scanf("%d%d%d",&u,&v,&x);
			qr[u].pb(mkp(v,i));qu[i]=u;qv[i]=v;qx[i]=x;
		}
		solve(1,0);
		ACM::build();
		for(int i=1;i<=q;++i) ACM::add_query(uid[i],vid[i],sid[qx[i]].back(),sid[qx[i]+m].back(),i);
		ACM::solve();
		for(int i=1;i<=q;++i) piii pp=ACM::get_query(i);
		for(int i=1;i<=q;++i)
		{
			piii pp=ACM::get_query(i);int ans=pp.fi;
			ans+=KMP::query(qx[i],pp.se.fi,qx[i]+m,pp.se.se,sid[qx[i]].size()-1);
			printf("%d\n",ans);
		}
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("CF917E.in","r",stdin);
	freopen("CF917E.out","w",stdout);
#endif
	solution::end_of_the_world();

	return 0;
}