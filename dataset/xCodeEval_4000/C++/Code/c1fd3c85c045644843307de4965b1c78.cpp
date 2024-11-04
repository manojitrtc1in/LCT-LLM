


#include<bits/stdc++.h>
using namespace std;
const int INF=0x3f3f3f3f;
bool book[200010];
struct E
{
	int u,v,w;
}sv[200010];
namespace LCA
{
	const int MAXN=200010;
	const int DEG=20;
	struct Edge
	{
		int to,next,w;
	}edge[MAXN*2];
	int head[MAXN],tot;
	void addedge(int u,int v,int w)
	{
		edge[tot].to=v;
		edge[tot].w=w;
		edge[tot].next=head[u];
		head[u]=tot++;
	}
	void init()
	{
		tot=0;
		memset(head,-1,sizeof(head));
	}
	int fa[MAXN][DEG],mx[MAXN][DEG];

	int deg[MAXN];

	void BFS(int root)
	{
		queue<int>que;
		deg[root]=0;
		fa[root][0]=root;
		mx[root][0]=0;
		que.push(root);
		while(!que.empty())
		{
			int tmp=que.front();
			que.pop();
			for(int i=1;i<DEG;i++)
			{
				fa[tmp][i]=fa[fa[tmp][i-1]][i-1];
				mx[tmp][i]=max(mx[fa[tmp][i-1]][i-1],mx[tmp][i-1]);
			}
			for(int i=head[tmp];i!=-1;i=edge[i].next)
			{
				int v=edge[i].to;
				if(v==fa[tmp][0])continue;
				deg[v]=deg[tmp]+1;
				fa[v][0]=tmp;
				mx[v][0]=edge[i].w;
				que.push(v);
			}
		}
	}
	int LCA(int u,int v)
	{
		if(deg[u]>deg[v])swap(u,v);
		int ret=0;
		int hu=deg[u],hv=deg[v];
		int tu=u,tv=v;
		for(int det=hv-hu,i=0;det;det>>=1,i++)
			if(det&1)
			{
				ret=max(mx[tv][i],ret);
				tv=fa[tv][i];
			}
		if(tu==tv)
			return ret;
		for(int i=DEG-1;i>=0;i--)
		{
			if(fa[tu][i]==fa[tv][i])
				continue;
			ret=max(ret,mx[tu][i]);
			ret=max(ret,mx[tv][i]);
			tu=fa[tu][i];
			tv=fa[tv][i];
		}
		return max(ret,max(mx[tu][0],mx[tv][0]));
	}
}
namespace Kruskal
{
	const int MAXN=2e5+5;

	const int MAXM=2e5+5;

	int F[MAXN];

	struct Edge
	{
		int u,v,w,id;
	}edge[MAXM];

	int tol;

	void init()

	{
		tol=0;
		memset(F,-1,sizeof(F));
		memset(edge,0,sizeof(edge));
	}
	void addedge(int u,int v,int w,int id)
	{
		edge[tol].u=u;
		edge[tol].v=v;
		edge[tol].id=id;
		edge[tol++].w=w;
	}
	bool cmp(Edge a,Edge b)

	{
		return a.w<b.w;
	}
	int find(int x)

	{
		if(F[x]==-1)return x;
		else return F[x]=find(F[x]);
	}
}
namespace tree
{
	const int MAXN=200010;
	#define lson l,mid,rt<<1
	#define rson mid+1,r,rt<<1|1
	struct Edge
	{
		int to,next;
	}edge[MAXN*2];
	int head[MAXN],tot;
	int top[MAXN];

	int fa[MAXN]; 

	int deep[MAXN];

	int num[MAXN];

	int p[MAXN];

	int fp[MAXN];

	int son[MAXN];

	int pos;
	void init()
	{
		tot=0;
		memset(head,-1,sizeof(head));
		pos=0;
		memset(son,-1,sizeof(son));
	}
	void addedge(int u,int v)
	{
		edge[tot].to=v;edge[tot].next=head[u];head[u]=tot++;
	}
	void dfs1(int u,int pre,int d) 

	{
		deep[u]=d;
		fa[u]=pre;
		num[u]=1;
		for(int i=head[u];i!=-1;i=edge[i].next)
		{
			int v=edge[i].to;
			if(v!=pre)
			{
				dfs1(v,u,d+1);
				num[u]+=num[v];
				if(son[u]==-1||num[v]>num[son[u]])
					son[u]=v;
			}
		}
	}
	void getpos(int u,int sp) 

	{
		top[u]=sp;
		p[u]=pos++;
		fp[p[u]]=u;
		if(son[u]==-1)
			return;
		getpos(son[u],sp);
		for(int i=head[u];i!=-1;i=edge[i].next)
		{
			int v=edge[i].to;
			if(v!=son[u]&&v!=fa[u])
				getpos(v,v);
		}
	}
	

	struct Node
	{
		int Min,lazy;
	}segTree[MAXN*4];
	void build(int i,int l,int r)
	{
		segTree[i].Min=INF;
		segTree[i].lazy=0;
		if(l==r)
			return;
		int mid=(l+r)>>1;
		build(i<<1,l,mid);
		build((i<<1)|1,mid+1,r);
	}
	void push_up(int i)
	{
		segTree[i].Min=max(segTree[i<<1].Min,segTree[(i<<1)|1].Min);
	}
	void push_down(int i)
	{
		if(segTree[i].lazy)
		{
			segTree[i<<1].Min=min(segTree[i<<1].Min,segTree[i].lazy);
			segTree[i<<1|1].Min=min(segTree[i<<1|1].Min,segTree[i].lazy);
			if(segTree[i<<1].lazy==0)
				segTree[i<<1].lazy=segTree[i].lazy;
			else
				segTree[i<<1].lazy=min(segTree[i<<1].lazy,segTree[i].lazy);
			if(segTree[i<<1|1].lazy==0)
				segTree[i<<1|1].lazy=segTree[i].lazy;
			else
				segTree[i<<1|1].lazy=min(segTree[i<<1|1].lazy,segTree[i].lazy);
			segTree[i].lazy=0;
		}
	}
	void update(int L,int R,int val,int l,int r,int rt)
	{
		if(L<=l&&r<=R)
		{
			segTree[rt].Min=min(segTree[rt].Min,val);
			if(segTree[rt].lazy==0)
				segTree[rt].lazy=val;
			else
				segTree[rt].lazy=min(segTree[rt].lazy,val);
			return;
		}
		push_down(rt);
		int mid=(l+r)>>1;
		if(L<=mid)
			update(L,R,val,lson);
		if(mid<R)
			update(L,R,val,rson);
		

		segTree[rt].Min=min(segTree[rt<<1].Min,segTree[(rt<<1)|1].Min);
	}
	int query(int pos,int l,int r,int rt)
	{
		if(l==r)
			return segTree[rt].Min;
		int mid=(l+r)>>1;
		push_down(rt);
		if(pos<=mid)
			return query(pos,lson);
		if(mid<pos)
			return query(pos,rson);
	}
	void upd(int u,int v,int val)
	{
		int f1=top[u],f2=top[v];
		while(f1!=f2)
		{
			if(deep[f1]<deep[f2])
			{
				swap(f1,f2);
				swap(u,v);
			}
			update(p[f1],p[u],val,0,pos-1,1);
			u=fa[f1];f1=top[u];
		}
		if(u==v)
			return ;
		if(deep[u]>deep[v])
			swap(u,v);
		update(p[son[u]],p[v],val,0,pos-1,1);
	}
	int find(int u,int v)

	{
		if(deep[u]>deep[v])
			swap(u,v);
		return query(p[v],0,pos-1,1);
	}
}
void Kru(int n)

{
	using namespace Kruskal;
	memset(F,-1,sizeof(F));
	sort(edge,edge+tol,cmp);
	int cnt=0;

	for(int i=0;i<tol;i++)
	{
		int u=edge[i].u;
		int v=edge[i].v;
		int w=edge[i].w;
		int id=edge[i].id;
		int t1=find(u);
		int t2=find(v);
		if(t1!=t2)
		{
			F[t1]=t2;
			book[id]=true;
			cnt++;
			tree :: addedge(u,v);tree :: addedge(v,u);
			LCA :: addedge(u,v,w);LCA :: addedge(v,u,w);
		}
		if(cnt==n-1)
			break;
	}
}
int main()
{
	

	

	tree :: init();
	LCA :: init();
	Kruskal :: init();
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&sv[i].u,&sv[i].v,&sv[i].w);
		Kruskal :: addedge(sv[i].u,sv[i].v,sv[i].w,i);
	}
	Kru(n);
	LCA :: BFS(1);
	tree :: dfs1(1,0,0);
	tree :: getpos(1,0);
	tree :: build(1,0,tree :: pos-1);
	for(int i=1;i<=m;i++)
	{
		int u=sv[i].u,v=sv[i].v,w=sv[i].w;
		if(!book[i])
			tree :: upd(u,v,w);
	}
	for(int i=1;i<=m;i++)
	{
		int u=sv[i].u,v=sv[i].v;
		if(!book[i])
		{
			int ret=LCA :: LCA(u,v);
			printf("%d ",ret-1);
		}
		else
		{
			int ret=tree :: find(u,v);
			if(ret==INF)
				printf("-1 ");
			else
				printf("%d ",ret-1);
		}
	}
	printf("\n");
	return 0;
}
