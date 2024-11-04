





using namespace std;
vector<int> e[200010];
struct quer
{
	int l,r,id;
}cur;
vector<quer> queries[200010];
struct node
{
	int l,r,num;
}nodes[2000010];
int root[200010],id1;
void ins(int l,int r,int &x,int pos)
{
	if(!x)	x=++id1;
	if(l^r)
	{
		int mid=(l+r)>>1;
		if(pos<=mid)	ins(l,mid,nodes[x].l,pos);
		else	ins(mid+1,r,nodes[x].r,pos);
		nodes[x].num=nodes[nodes[x].l].num+nodes[nodes[x].r].num;
	}
	else	++nodes[x].num;
}
int merge(int l,int r,int x,int y)
{
	if(!x||!y)	return x|y;
	else
	{
		if(l^r)
		{
			int mid=(l+r)>>1;
			nodes[x].l=merge(l,mid,nodes[x].l,nodes[y].l);
			nodes[x].r=merge(mid+1,r,nodes[x].r,nodes[y].r);
			nodes[x].num=nodes[nodes[x].l].num+nodes[nodes[x].r].num;
			return x;
		}
		else
		{
			nodes[x].num+=nodes[y].num;
			return x;
		}
	}
}
int find(int l,int r,int x,int fr,int ba)
{
	if(l>ba||r<fr||!nodes[x].num)	return 0;
	if(l>=fr&&r<=ba)	return nodes[x].num;
	else
	{
		int mid=(l+r)>>1;
		return find(l,mid,nodes[x].l,fr,ba)+find(mid+1,r,nodes[x].r,fr,ba);
	}
}
int n,m,q,u,v,opl,opr,leni[100010],all,ans[100010];
void anfs(int x)
{
	for(int i=0;i<(int)e[x].size();++i)
	{
		int y=e[x][i];
		anfs(y);
		root[x]=merge(1,m,root[x],root[y]);
	}
	for(int i=0;i<(int)queries[x].size();++i)
	{
		cur=queries[x][i];
		ans[cur.id]=find(1,m,root[x],cur.l,cur.r);
	}
}
char w[10],s[100010];
int head[100010],to[200010],nxtt[200010],cntot;
char val[200010];
inline void addedge(int one,int ano,char c)
{
	nxtt[++cntot]=head[one];
	to[cntot]=ano;
	val[cntot]=c;
	head[one]=cntot;
	nxtt[++cntot]=head[ano];
	to[cntot]=one;
	val[cntot]=c;
	head[ano]=cntot;
}
int nxt[100010][26],tot=1,pos[100010];
struct exnode
{
	int ch[26],len,link;
}exnodes[200010];
int totnc=1;
inline int ins(int c,int las)
{
	int now=++totnc;
	exnodes[now].len=exnodes[las].len+1;
	while(las&&!exnodes[las].ch[c])
	{
		exnodes[las].ch[c]=now;
		las=exnodes[las].link;
	}
	if(!las)	exnodes[now].link=1;
	else
	{
		if(exnodes[las].len+1==exnodes[exnodes[las].ch[c]].len)	exnodes[now].link=exnodes[las].ch[c];
		else
		{
			int clone=++totnc;
			exnodes[clone]=exnodes[exnodes[las].ch[c]];
			exnodes[clone].len=exnodes[las].len+1;
			exnodes[exnodes[las].ch[c]].link=clone;
			exnodes[now].link=clone;
			int tmp=exnodes[las].ch[c];
			while(las&&exnodes[las].ch[c]==tmp)
			{
				exnodes[las].ch[c]=clone;
				las=exnodes[las].link;
			}
		}
	}
	return now;
}
queue<int> euq;
void buildfs()
{
	euq.push(1);
	while(!euq.empty())
	{
		int x=euq.front();
		euq.pop();
		for(int i=0;i<26;++i)
		{
			if(nxt[x][i])
			{
				pos[nxt[x][i]]=ins(i,pos[x]);
				euq.push(nxt[x][i]);
			}
		}
	}
}
int fa[100010],dep[100010],siz[100010],son[100010],hb[100010];
char fat[100010];
void dfs1(int x,int las)
{
	fa[x]=las;
	dep[x]=dep[las]+1;
	siz[x]=1;
	for(int i=head[x];i;i=nxtt[i])
	{
		int y=to[i];
		if(y!=las)
		{
			fat[y]=val[i];
			dfs1(y,x);
			siz[x]+=siz[y];
			if(siz[y]>siz[son[x]])	son[x]=y;
		}
	}
}
int id[100010];
vector<int> chain[100010];

void dfs2(int x,int las,bool heavy)
{
	if(heavy)	hb[x]=hb[las];
	else	hb[x]=x;
	id[x]=chain[hb[x]].size();
	chain[hb[x]].push_back(x);
	if(son[x])
	{
		dfs2(son[x],x,1);
		for(int i=head[x];i;i=nxtt[i])
		{
			int y=to[i];
			if(y!=las&&y!=son[x])	dfs2(y,x,0);
		}
	}
}
int sson[200010],ssfa[200010],deg[200010];
long long insiz[200010],outsiz[200010];
char star[200010];
bool vis[200010];
queue<int> que;
void getout(int x)
{
	if(outsiz[x])	return;
	outsiz[x]=1;
	for(int i=0;i<26;++i)
	{
		if(exnodes[x].ch[i])
		{
			getout(exnodes[x].ch[i]);
			outsiz[x]+=outsiz[exnodes[x].ch[i]];
		}
	}
}
void dfs3(int x)
{
	if(vis[x])	return;
	vis[x]=1;
	for(int i=0;i<26;++i)
	{
		int y=exnodes[x].ch[i];
		if(y)
		{
			if((insiz[x]<<1)>insiz[y]&&outsiz[x]<(outsiz[y]<<1))
			{
				sson[x]=y;
				ssfa[y]=x;
				star[x]=i+'a';
			}
			dfs3(y);
		}
	}
}
int sshd[200010],di[200010];
vector<int> exchain[200010];

char S[800010];
int len,sa[800010],ton[800010],x[800010],y[800010],stot,vals,rk[800010],ht[800010];
inline void getsa()
{
	vals=200;
	for(int i=1;i<=len;++i)	++ton[x[i]=S[i]];
	for(int i=1;i<=vals;++i)	ton[i]+=ton[i-1];
	for(int i=1;i<=len;++i)	sa[ton[x[i]]--]=i;
	for(int z=1;z<len;z<<=1)
	{
		stot=0;
		for(int i=len-z+1;i<=len;++i)	y[++stot]=i;
		for(int i=1;i<=len;++i)
		{
			if(sa[i]>z)	y[++stot]=sa[i]-z;
		}
		for(int i=1;i<=vals;++i)	ton[i]=0;
		for(int i=1;i<=len;++i)	++ton[x[i]];
		for(int i=1;i<=vals;++i)	ton[i]+=ton[i-1];
		for(int i=len;i>=1;--i)	sa[ton[x[y[i]]]--]=y[i];
		swap(x,y);
		x[sa[1]]=vals=1;
		for(int i=2;i<=len;++i)
		{
			if(y[sa[i]]==y[sa[i-1]]&&(sa[i]+z<=len?y[sa[i]+z]:-1)==(sa[i-1]+z<=len?y[sa[i-1]+z]:-1))	x[sa[i]]=vals;
			else	x[sa[i]]=++vals;
		}
		if(vals==len)	break;
	}
}
inline void getht()
{
	for(int i=1;i<=len;++i)	rk[sa[i]]=i;
	for(int i=1,k=0;i<=len;++i)
	{
		if(rk[i]==1)
		{
			k=0;
			continue;
		}
		if(k)	--k;
		while(i+k<=len&&sa[rk[i]-1]+k<=len&&S[i+k]==S[sa[rk[i]-1]+k])	++k;
		ht[rk[i]]=k;
	}
}
int st[20][800010];
inline int find(int l,int r)
{
	int t=31-__builtin_clz(r-l+1);
	return min(st[t][l],st[t][r-(1<<t)+1]);
}
inline int id0(int x,int y)
{
	if(!x||!y)	return 0;
	if(rk[x]>rk[y])	swap(x,y);
	return find(rk[x]+1,rk[y]);
}
int trpre[100010],trsuf[100010],samp[200010];
int xfa[110],xx[110],xtot,yfa[110],yx[110],ytot;
inline void solve(int x,int y)
{
	xtot=ytot=0;
	int fx=hb[x],fy=hb[y];
	while(fx^fy)
	{
		if(dep[fx]>dep[fy])
		{
			xfa[++xtot]=fx;
			xx[xtot]=x;
			x=fa[fx];
			fx=hb[x];
		}
		else
		{
			yfa[++ytot]=fy;
			yx[ytot]=y;
			y=fa[fy];
			fy=hb[y];
		}
	}
	if(dep[x]<dep[y])
	{
		yfa[++ytot]=x;
		yx[ytot]=y;
	}
	else
	{
		xfa[++xtot]=y;
		xx[xtot]=x;
	}
	int now=1;
	for(int i=1;i<=xtot;++i)
	{
		int F=xfa[i],X=xx[i],HB=hb[X];
		while(F!=X)
		{
			int lcp=min(id0(samp[now],trsuf[X]),id[X]-id[F]);






			X=chain[HB][id[X]-lcp];
			now=exchain[sshd[now]][di[now]+lcp];
			if(X!=F)
			{
				char id2=fat[X];
				now=exnodes[now].ch[id2-'a'];
				if(!now)	return;
				X=fa[X];
			}
		}
		if(i!=xtot)
		{
			char id2=fat[X];
			now=exnodes[now].ch[id2-'a'];
			if(!now)	return;
		}
	}
	if(xtot&&ytot&&dep[x]>=dep[y])
	{
		char id2=fat[yfa[ytot]];
		now=exnodes[now].ch[id2-'a'];
		if(!now)	return;
	}
	else if(xtot&&ytot&&dep[x]<dep[y])
	{
		char id2=fat[xfa[xtot]];
		now=exnodes[now].ch[id2-'a'];
		if(!now)	return;
	}
	for(int i=ytot;i>=1;--i)
	{
		int F=yfa[i],X=yx[i],HB=hb[X];
		while(F!=X)
		{
			int lcp=min(id0(samp[now],trpre[F]),id[X]-id[F]);
			F=chain[HB][id[F]+lcp];
			now=exchain[sshd[now]][di[now]+lcp];
			if(X!=F)
			{
				char id2=fat[son[F]];
				now=exnodes[now].ch[id2-'a'];
				if(!now)	return;
				F=son[F];
			}
		}
		if(i!=1)
		{
			char id2=fat[yfa[i-1]];
			now=exnodes[now].ch[id2-'a'];
			if(!now)	return;
		}
	}
	queries[now].push_back(cur);
}
int main()
{




	scanf("%d %d %d",&n,&m,&q);
	for(int i=1;i<n;++i)
	{
		scanf("%d %d %s",&u,&v,w+1);
		addedge(u,v,w[1]);
	}
	dfs1(1,1);
	dfs2(1,1,0);
	for(int i=1;i<=m;++i)
	{
		scanf("%s",s+all+1);
		leni[i]=strlen(s+all+1);
		int now=1;
		for(int j=all+1;j<=all+leni[i];++j)
		{
			if(!nxt[now][s[j]-'a'])	nxt[now][s[j]-'a']=++tot;
			now=nxt[now][s[j]-'a'];
		}
		all+=leni[i];
	}
	pos[1]=1;
	buildfs();
	for(int i=1;i<=totnc;++i)
	{
		for(int j=0;j<26;++j)
		{
			if(exnodes[i].ch[j])	++deg[exnodes[i].ch[j]];
		}
	}
	insiz[1]=1;
	que.push(1);
	while(!que.empty())
	{
		int now=que.front();
		que.pop();
		for(int i=0;i<26;++i)
		{
			int y=exnodes[now].ch[i];
			if(y)
			{
				insiz[y]+=insiz[now];
				--deg[y];
				if(!deg[y])	que.push(y);
			}
		}
	}
	getout(1);
	dfs3(1);
	for(int i=1;i<=totnc;++i)
	{
		if(!ssfa[i])
		{
			int tmp=i;
			while(tmp)
			{
				sshd[tmp]=i;
				di[tmp]=exchain[i].size();
				exchain[i].push_back(tmp);
				tmp=sson[tmp];
			}
		}
	}
	for(int i=1;i<=n;++i)
	{
		if(!chain[i].empty())
		{
			for(int j=0;j<(int)chain[i].size()-1;++j)
			{
				S[++len]=fat[chain[i][j+1]];
				trpre[chain[i][j]]=len;
			}
			S[++len]='
			for(int j=chain[i].size()-1;j>=1;--j)
			{
				S[++len]=fat[chain[i][j]];
				trsuf[chain[i][j]]=len;
			}
			S[++len]='
		}
	}
	S[++len]='^';
	for(int i=1;i<=totnc;++i)
	{
		if(!exchain[i].empty())
		{
			for(int j=0;j<(int)exchain[i].size()-1;++j)
			{
				S[++len]=star[exchain[i][j]];
				samp[exchain[i][j]]=len;
			}
			S[++len]='*';
		}
	}
	getsa();
	getht();
	for(int i=1;i<=len;++i)	st[0][i]=ht[i];
	for(int i=1,j=2;j<=len;++i,j<<=1)
	{
		for(int l=1;l+j-1<=len;++l)	st[i][l]=min(st[i-1][l],st[i-1][l+(j>>1)]);
	}
	for(int i=1;i<=q;++i)
	{
		scanf("%d %d %d %d",&u,&v,&opl,&opr);
		cur.id=i;
		cur.l=opl;
		cur.r=opr;
		solve(u,v);
	}
	all=0;
	for(int i=1;i<=m;++i)
	{
		int now=1;
		for(int j=all+1;j<=all+leni[i];++j)
		{
			now=exnodes[now].ch[s[j]-'a'];
			ins(1,m,root[now],i);
		}
		all+=leni[i];
	}
	for(int i=1;i<=totnc;++i)	e[exnodes[i].link].push_back(i);
	anfs(1);
	for(int i=1;i<=q;++i)	printf("%d\n",ans[i]);
	return 0;
}