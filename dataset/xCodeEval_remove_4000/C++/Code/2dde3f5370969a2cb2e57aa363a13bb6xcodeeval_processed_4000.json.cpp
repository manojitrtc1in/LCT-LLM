





using namespace std;
inline void read(int &hhh)
{
	int x=0;
	char c=getchar();
	while(c<'0'||c>'9')	c=getchar();
	while(c<='9'&&c>='0')
	{
		x=(x<<1)+(x<<3)+(c^'0');
		c=getchar();
	}
	hhh=x;
}
void writing(int x)
{
	if(!x)	return;
	writing(x/10);
	putchar((x%10)^'0');
}
inline void write(int x)
{
	if(!x)
	{
		putchar('0');
		putchar('\n');
		return;
	}
	writing(x);
	putchar('\n');
}
int exhead[200010],exto[200010],exnxt[200010],id4;
void id1(int one,int ano)
{
	exnxt[++id4]=exhead[one];
	exto[id4]=ano;
	exhead[one]=id4;
}
struct quer
{
	int l,r,id;
}cur;
vector<quer> queries[200010];
struct node
{
	int l,r,num;
}nodes[2000010];
int root[200010],id2;
void ins(int l,int r,int &x,int pos)
{
	if(!x)	x=++id2;
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
	for(int i=exhead[x];i;i=exnxt[i])
	{
		int y=exto[i];
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
int euq[200010],enowl,id3;
void buildfs()
{
	euq[enowl=id3=1]=1;
	while(enowl<=id3)
	{
		int x=euq[enowl++];
		for(int i=0;i<26;++i)
		{
			if(nxt[x][i])
			{
				pos[nxt[x][i]]=ins(i,pos[x]);
				euq[++id3]=nxt[x][i];
			}
		}
	}
}
int fa[100010],dep[100010],siz[100010],son[100010],hb[100010],fat[100010];
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
			fat[y]=val[i]-'a';
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
int sson[200010],ssfa[200010],deg[200010],star[200010];
long long insiz[200010],outsiz[200010];
bool vis[200010];
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
				star[x]=i;
			}
			dfs3(y);
		}
	}
}
int sshd[200010],di[200010];
vector<int> exchain[200010];

char S[400010];
int len,sa[400010],ton[400010],stot,vals,rk[400010],ht[400010];
inline void getsa()

{
	vals=200;
	for(int i=1;i<=len;++i)	++ton[rk[i]=S[i]];
	for(int i=1;i<=vals;++i)	ton[i]+=ton[i-1];
	for(int i=1;i<=len;++i)	sa[ton[rk[i]]--]=i;
	for(int z=1;z<len;z<<=1)
	{
		stot=0;
		for(int i=len-z+1;i<=len;++i)	ht[++stot]=i;
		for(int i=1;i<=len;++i)
		{
			if(sa[i]>z)	ht[++stot]=sa[i]-z;
		}
		for(int i=1;i<=vals;++i)	ton[i]=0;
		for(int i=1;i<=len;++i)	++ton[rk[i]];
		for(int i=1;i<=vals;++i)	ton[i]+=ton[i-1];
		for(int i=len;i>=1;--i)	sa[ton[rk[ht[i]]]--]=ht[i];
		swap(rk,ht);
		rk[sa[1]]=vals=1;
		for(int i=2;i<=len;++i)
		{
			if(ht[sa[i]]==ht[sa[i-1]]&&(sa[i]+z<=len?ht[sa[i]+z]:-1)==(sa[i-1]+z<=len?ht[sa[i-1]+z]:-1))	rk[sa[i]]=vals;
			else	rk[sa[i]]=++vals;
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
			ht[rk[i]]=k=0;
			continue;
		}
		if(k)	--k;
		while(i+k<=len&&sa[rk[i]-1]+k<=len&&S[i+k]==S[sa[rk[i]-1]+k])	++k;
		ht[rk[i]]=k;
	}
}
int st[19][400010];
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
int xfa[410],xx[410],xtot,yfa[410],yx[410],ytot;
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
			int lcp=min(id0(samp[now],trsuf[X]),min(id[X]-id[F],(int)exchain[sshd[now]].size()-1-di[now]));
			X=chain[HB][id[X]-lcp];
			now=exchain[sshd[now]][di[now]+lcp];
			if(X!=F)
			{
				now=exnodes[now].ch[fat[X]];
				if(!now)	return;
				X=fa[X];
			}
		}
		if(i!=xtot)
		{
			now=exnodes[now].ch[fat[X]];
			if(!now)	return;
		}
	}
	if(xtot&&ytot&&dep[x]>=dep[y])
	{
		now=exnodes[now].ch[fat[yfa[ytot]]];
		if(!now)	return;
	}
	else if(xtot&&ytot&&dep[x]<dep[y])
	{
		now=exnodes[now].ch[fat[xfa[xtot]]];
		if(!now)	return;
	}
	for(int i=ytot;i>=1;--i)
	{
		int F=yfa[i],X=yx[i],HB=hb[X];
		while(F!=X)
		{
			int lcp=min(id0(samp[now],trpre[F]),min(id[X]-id[F],(int)exchain[sshd[now]].size()-1-di[now]));
			F=chain[HB][id[F]+lcp];
			now=exchain[sshd[now]][di[now]+lcp];
			if(X!=F)
			{
				now=exnodes[now].ch[fat[son[F]]];
				if(!now)	return;
				F=son[F];
			}
		}
		if(i!=1)
		{
			now=exnodes[now].ch[fat[yfa[i-1]]];
			if(!now)	return;
		}
	}
	queries[now].push_back(cur);
}
int main()
{
	read(n);
	read(m);
	read(q);
	for(int i=1;i<n;++i)
	{
		read(u);
		read(v);
		scanf("%s",w+1);
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
	euq[enowl=id3=1]=1;
	while(enowl<=id3)
	{
		int now=euq[enowl++];
		for(int i=0;i<26;++i)
		{
			int y=exnodes[now].ch[i];
			if(y)
			{
				insiz[y]+=insiz[now];
				--deg[y];
				if(!deg[y])	euq[++id3]=y;
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
		if(chain[i].size()>1)
		{
			for(int j=0;j<(int)chain[i].size()-1;++j)
			{
				S[++len]=fat[chain[i][j+1]];
				trpre[chain[i][j]]=len;
			}
			for(int j=chain[i].size()-1;j>=1;--j)
			{
				S[++len]=fat[chain[i][j]];
				trsuf[chain[i][j]]=len;
			}
		}
	}
	for(int i=1;i<=totnc;++i)
	{
		if(exchain[i].size()>1)
		{
			for(int j=0;j<(int)exchain[i].size()-1;++j)
			{
				S[++len]=star[exchain[i][j]];
				samp[exchain[i][j]]=len;
			}
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
		read(u);
		read(v);
		read(opl);
		read(opr);
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
	for(int i=2;i<=totnc;++i)	id1(exnodes[i].link,i);
	anfs(1);
	for(int i=1;i<=q;++i)	write(ans[i]);
	return 0;
}