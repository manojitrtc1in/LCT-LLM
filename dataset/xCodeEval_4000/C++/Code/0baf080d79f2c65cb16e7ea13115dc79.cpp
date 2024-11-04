

#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<vector>






#include<algorithm>
#include<stdlib.h>
using namespace std;

int n,m,lq;
#define maxn 200011
struct Edge{int to,next; char v;}edge[maxn<<1]; int first[maxn],le=2;
void in(int x,int y,char v) {Edge &e=edge[le]; e.to=y; e.v=v; e.next=first[x]; first[x]=le++;}
void insert(int x,int y,char v) {in(x,y,v); in(y,x,v);}

struct Ques{int x,y,z,id,col,ps1,ps2;}q[maxn];
bool cmp(const Ques &a,const Ques &b) {return a.col<b.col;}
int ans[maxn];

struct AC
{
	int ch[maxn][26],size,pos[maxn];
	AC() {size=0; le=2; Time=0;}
	int idx(char c) {return c-'a';}
	void insert(int who,char *s)
	{
		int len=strlen(s),now=0;
		for (int i=0;i<len;i++)
		{
			int id=idx(s[i]);
			if (!ch[now][id])
			{
				size++;
				ch[now][id]=size;
			}
			now=ch[now][id];
		}
		pos[who]=now;
	}
	int fail[maxn];
	int que[maxn],head,tail;
	void makefail()
	{
		head=tail=0;
		for (int i=0;i<26;i++) if (ch[0][i])
		{
			fail[ch[0][i]]=0;
			que[tail++]=ch[0][i];
		}
		while (head!=tail)
		{
			int now=que[head++];
			for (int i=0;i<26;i++)
			{
				if (!ch[now][i]) {ch[now][i]=ch[fail[now]][i]; continue;}
				que[tail++]=ch[now][i];
				fail[ch[now][i]]=ch[fail[now]][i];
			}
		}
	}
	Edge edge[maxn<<1]; int first[maxn],le;
	void in(int x,int y) {Edge &e=edge[le]; e.to=y; e.next=first[x]; first[x]=le++;}
	int ll[maxn],rr[maxn],Time;
	void predfs(int x)
	{
		ll[x]=++Time;
		for (int i=first[x];i;i=edge[i].next)
		{
			Edge &e=edge[i];
			predfs(e.to);
		}
		rr[x]=Time;
	}
	void predfs()
	{
		for (int i=1;i<=size;i++) in(fail[i],i);
		predfs(0);
	}


















}a1,a2;
vector<char> ss[maxn],fs[maxn];
struct SAM
{
	struct Node{int ch[26],pos,pre,who,Max;}a[maxn<<1];
	int size,last;
	SAM() {a[0].pre=-1; size=last=0; le=2; Time=0;}
	int idx(char c) {return c-'a';}
	void insert(int who,char c,int pos)
	{
		int id=idx(c);
		if (a[last].ch[id])
		{
			if (a[a[last].ch[id]].Max==a[last].Max+1) last=a[last].ch[id];
			else
			{
				int z=a[last].ch[id],w=++size; a[w]=a[z]; a[w].Max=a[last].Max+1; a[w].pos=pos; a[w].who=who;
				a[z].pre=w;
				for (int y=last;~y && a[y].ch[id]==z;y=a[y].pre) a[y].ch[id]=w;
				last=w;
			}
		}
		else
		{
			int x=++size; a[x].pos=pos; a[x].who=who; a[x].Max=a[last].Max+1;
			int y=last; last=x;
			for (;~y && !a[y].ch[id];y=a[y].pre) a[y].ch[id]=x;
			if (!~y) a[x].pre=0;
			else if (a[a[y].ch[id]].Max==a[y].Max+1) a[x].pre=a[y].ch[id];
			else
			{
				int z=a[y].ch[id],w=++size; a[w]=a[z]; a[w].pos=pos; a[w].Max=a[y].Max+1; a[w].who=who;
				a[z].pre=a[x].pre=w;
				for (;~y && a[y].ch[id]==z;y=a[y].pre) a[y].ch[id]=w;
			}
		}
	}
	Edge edge[maxn<<2]; int first[maxn<<1],le;
	void in(int x,int y) {Edge &e=edge[le]; e.to=y; e.next=first[x]; first[x]=le++;}
	int ll[maxn],rr[maxn],Time;
	void predfs(int x)
	{
		ll[x]=++Time;
		for (int i=first[x];i;i=edge[i].next)
		{
			Edge &e=edge[i];
			predfs(e.to);
		}
		rr[x]=Time;
	}
	void predfs() {for (int i=1;i<=size;i++) in(a[i].pre,i); predfs(0);}
	bool go(int &x,int &son,int &pos,char c,vector<char> *s)
	{
		if (!son)
		{
			for (int i=first[x];i;i=edge[i].next)
			{
				Edge &e=edge[i]; Node &now=a[e.to];


				if (s[now.who][now.pos+a[x].Max]==c)
				{
					son=e.to;
					pos=now.pos+a[x].Max+1;
					break;
				}
			}
			if (!son) return 0;
		}
		else if (s[a[son].who][pos]==c) pos++; else return 0;
		if (pos==a[son].pos+a[son].Max) {x=son; son=pos=0;}
		return 1;
	}
















}s1,s2;
struct BIT
{
	int a[maxn<<1],n;
	void clear(int m) {n=m;}
	void add(int x,int v) {for (;x<=n;x+=x&-x) a[x]+=v;}
	int query(int x) {int ans=0; for (;x;x-=x&-x) ans+=a[x]; return ans;}
}ta1,ta2,ts;

int size[maxn];
int col[maxn]; bool vis[maxn];
void getsize(int x,int fa)
{
	size[x]=1;
	for (int i=first[x];i;i=edge[i].next)
	{
		Edge &e=edge[i]; if (e.to==fa || vis[e.to]) continue;
		getsize(e.to,x); size[x]+=size[e.to];
	}
}
int getroot(int x,int fa,int tot)
{
	for (int i=first[x];i;i=edge[i].next)
	{
		Edge &e=edge[i]; if (e.to==fa || vis[e.to]) continue;
		if (size[e.to]*2>tot) return getroot(e.to,x,tot);
	}
	return x;
}

void paint(int x,int fa,int c)
{
	col[x]=c;
	for (int i=first[x];i;i=edge[i].next)
	{
		Edge &e=edge[i]; if (e.to==fa || vis[e.to]) continue;
		paint(e.to,x,c);
	}
}
struct Eve{int to,type,next;}eve[maxn<<1]; int feve[maxn],leve=2;
void ineve(int x,int y,int type) {Eve &e=eve[leve]; e.to=y; e.type=type; e.next=feve[x]; feve[x]=leve++;}
void Dfs(int x,int fa,int pa1,int pa2,int ps1,bool die1,int son1,int pos1,int ps2,bool die2,int son2,int pos2)
{


	ta1.add(a1.ll[pa1],1); ta2.add(a2.ll[pa2],1);


	for (int i=feve[x];i;i=eve[i].next)
	{
		Eve &e=eve[i];
		if (e.type==1)
		{


			ans[q[e.to].id]+=ta2.query(a2.rr[a2.pos[q[e.to].z]])-ta2.query(a2.ll[a2.pos[q[e.to].z]]-1);
			q[e.to].ps1=ps1;
		}
		else
		{
			ans[q[e.to].id]+=ta1.query(a1.rr[a1.pos[q[e.to].z]])-ta1.query(a1.ll[a1.pos[q[e.to].z]]-1);
			q[e.to].ps2=ps2;
		}
	}
	for (int i=first[x];i;i=edge[i].next)
	{
		Edge &e=edge[i]; if (e.to==fa || vis[e.to]) continue;
		int id=e.v-'a';
		int nps1=ps1,npos1=pos1,nson1=son1,nps2=ps2,npos2=pos2,nson2=son2; bool nd1=die1,nd2=die2;
		if (die1) nps1=ps1,nson1=0,npos1=0,nd1=1;
		else nd1=!s1.go(nps1,nson1,npos1,e.v,fs);
		if (die2) nps2=ps2,nson2=0,npos2=0,nd2=1;
		else nd2=!s2.go(nps2,nson2,npos2,e.v,ss);
		Dfs(e.to,x,a1.ch[pa1][id],a2.ch[pa2][id],nps1,nd1,nson1,npos1,nps2,nd2,nson2,npos2);
	}
	ta1.add(a1.ll[pa1],-1); ta2.add(a2.ll[pa2],-1);
}
		
void cd(int x,int ql,int qr)
{


	vis[x]=1; col[x]=0;
	if (ql>qr) return;
	bool flag=0; int tot=0;
	for (int i=first[x];i;i=edge[i].next)
	{
		Edge &e=edge[i]; if (vis[e.to]) continue;
		paint(e.to,0,++tot);
	}
	for (int i=ql;i<=qr;i++)
	{
		if (col[q[i].x]==col[q[i].y]) q[i].col=col[q[i].x];
		else flag=1,q[i].col=0;
	}
	sort(q+ql,q+qr+1,cmp);
	int j;
	for (j=ql;j<=qr && q[j].col==0;j++)
	{


		ineve(q[j].x,j,1);
		ineve(q[j].y,j,0);
	}
	if (flag) Dfs(x,0,0,0,0,0,0,0,0,0,0,0);
	for (int k=ql;k<j;k++) feve[q[k].x]=feve[q[k].y]=0; leve=2;
	for (int i=first[x];i;i=edge[i].next)
	{
		Edge &e=edge[i]; if (vis[e.to]) continue;
		int tj=j; while (j<=qr && q[j].col==col[e.to]) j++;
		getsize(e.to,0); cd(getroot(e.to,0,size[e.to]),tj,j-1);
	}
}

struct Bre{int tx,ty,tz,type,isq;}bre[maxn],ff[maxn<<2]; int lbre=0,lff=0;
void inbre(int x,int y,int t) {bre[++lbre]=(Bre){x,y,0,t};}

char s[maxn]; int br[maxn];
bool cmpff(const Bre &a,const Bre &b) {return a.type<b.type || (a.type==b.type && a.tx<b.tx)
|| (a.type==b.type && a.tx==b.tx && a.isq<b.isq);}
int main()
{
	scanf("%d%d%d",&n,&m,&lq);
	char c;
	for (int i=1,x,y;i<n;i++)
	{
		scanf("%d%d",&x,&y); while ((c=getchar())<'a' || c>'z');
		insert(x,y,c);
	}
	for (int i=1;i<=m;i++)
	{
		s1.last=s2.last=0;
		scanf("%s",s); int len=strlen(s);
		ss[i].push_back('$'); for (int j=0;j<len;j++) ss[i].push_back(s[j]);
		a1.insert(i,s); for (int j=0;j<len;j++) s1.insert(i,s[j],len-j),br[j]=s1.last;
		for (int j=0,to=len>>1;j<to;j++) s[j]^=s[len-j-1]^=s[j]^=s[len-j-1];
		fs[i].push_back('$'); for (int j=0;j<len;j++) fs[i].push_back(s[j]);
		a2.insert(i,s); for (int j=0;j<len-1;j++) s2.insert(i,s[j],len-j),inbre(br[len-j-2],s2.last,i); s2.insert(i,s[len-1],1);


	}
	for (int i=1;i<=lq;i++) scanf("%d%d%d",&q[i].x,&q[i].y,&q[q[i].id=i].z);
	
	ta1.clear(a1.size+3); ta2.clear(a2.size+3);
	a1.makefail(); a2.makefail();


	a1.predfs(); a2.predfs(); s1.predfs(); s2.predfs();


	getsize(1,0); cd(getroot(1,0,size[1]),1,lq);
	


	for (int i=1;i<=lbre;i++)
	{
		ff[++lff]=(Bre){s1.ll[bre[i].tx],bre[i].ty,1,bre[i].type,0};
		ff[++lff]=(Bre){s1.rr[bre[i].tx]+1,bre[i].ty,-1,bre[i].type,0};
	}
	for (int i=1;i<=lq;i++) ff[++lff]=(Bre){s1.ll[q[i].ps1],s2.ll[q[i].ps2],q[i].id,q[i].z,1};
	sort(ff+1,ff+1+lff,cmpff);


	ts.clear(s2.size+3);


	for (int k=1;k<=lff;k++)
	{
		if (ff[k].isq==0) ts.add(s2.ll[ff[k].ty],ff[k].tz),ts.add(s2.rr[ff[k].ty]+1,-ff[k].tz);
		else ans[ff[k].tz]+=ts.query(ff[k].ty);
	}
	
	for (int i=1;i<=lq;i++) printf("%d\n",ans[i]);
	return 0;
}

 
