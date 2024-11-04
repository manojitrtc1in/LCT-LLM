#include<bits/stdc++.h>
#define N 200005
using namespace std;
int n,m,q,len[N];char s[N];
int Nxt[N],Fst[N],Ans[N];

int used[N*2],to[N*2],nxt[N*2],str[N*2],fst[N],l=1;

struct T
{
	int x,y,p;
}Q[N],Q0[N];

int sz[N],Mx[N],blg[N];
struct ACatm
{
	int c[N][26],fail[N],cnt,id[N];
	int s[N][26],st[N],ed[N],ly;
	int q[N];
	vector<int>v[N];
	void clr()
	{
		cnt=1;
	}
	void add(char s[],int len,int k)
	{
		int now=1;
		for (int i=0;i<len;i++)
		{
			if (!c[now][s[i]-'a']) c[now][s[i]-'a']=++cnt;
			now=c[now][s[i]-'a'];
		}
		id[k]=now;
		
	}
	void dfs(int x)
	{
		st[x]=++ly;
		for (int i=0;i<v[x].size();i++)
			dfs(v[x][i]);
		ed[x]=ly;
	}
	void build()
	{
		for (int i=0;i<26;i++)
			c[0][i]=1;
		int l=0,r=1;
		q[1]=1;

		while(l<r)
		{
			int x=q[++l];
			for (int i=0;i<26;i++)
				if (c[x][i])
				{
					q[++r]=c[x][i];
					fail[c[x][i]]=c[fail[x]][i];
				}
				else c[x][i]=c[fail[x]][i];
		}
		for (int i=2;i<=cnt;i++)
			v[fail[i]].push_back(i);
		dfs(1);

	}

	int val[N*4];
	void add(int k,int l,int r,int x,int y)
	{
		val[k]+=y;
		if (l==r) return;
		int mid=l+r>>1;
		if (x<=mid) add(k<<1,l,mid,x,y);
		else add(k<<1|1,mid+1,r,x,y);
	}
	int qry(int k,int l,int r,int x,int y)
	{
		if (x<=l&&r<=y) return val[k];
		int mid=l+r>>1,ans=0;
		if (x<=mid) ans+=qry(k<<1,l,mid,x,y);
		if (y>mid) ans+=qry(k<<1|1,mid+1,r,x,y);
		return ans;
	}
	void add(int x,int y)
	{
		

		

		add(1,1,cnt,st[x],y);
	}
	int qry(int x)
	{
		x=id[x];
		

		

		return qry(1,1,cnt,st[x],ed[x]);
	}
}A1,A2;
struct S
{
	int x,y,flag;
}newS=(S){1,0,0};
struct SAM
{
	int F[N*2],st[N*2],c[N*2][26],cnt;
	int pos[N*2],str[N],ly,s[N*2][26];
	vector<int>v[N];
	int stt[N*2],ed[N*2],hz;
	void clr()
	{
		cnt=1;
	}
	int add(int p,int x,int y)
	{
		int q,np,nq;
		if (c[p][x]&&st[c[p][x]]==st[p]+1)
			return c[p][x];
		st[np=++cnt]=st[p]+1;pos[np]=y;
		while(p&&!c[p][x]) c[p][x]=np,p=F[p];
		if (!p) F[np]=1;
		else if (st[p]+1==st[q=c[p][x]]) F[np]=q;
		else
		{
			if (st[np]==st[p]+1)
			{
				nq=np;st[nq]=st[p]+1;
				for (int i=0;i<26;i++) c[nq][i]=c[q][i];
				F[nq]=F[q];F[q]=nq;
				while(p&&c[p][x]==q) c[p][x]=nq,p=F[p];
			}
			else
			{
				st[nq=++cnt]=st[p]+1;pos[nq]=pos[q];
				for (int i=0;i<26;i++) c[nq][i]=c[q][i];
				F[nq]=F[q];F[q]=F[np]=nq;
				while(p&&c[p][x]==q) c[p][x]=nq,p=F[p];
			}
		}
		return np;
	}
	void add(char s[],int len,int k)
	{
		int now=1;
		for (int i=0;i<len;i++)
		{
			str[++ly]=s[i]-'a';
			now=add(now,s[i]-'a',ly);
		}
	}
	void dfs(int x)
	{
		

		stt[x]=++hz;
		for (int i=0;i<v[x].size();i++)
			dfs(v[x][i]);
		ed[x]=hz;
	}
	void build()
	{
		
		for (int i=2;i<=cnt;i++)
		{
			

			pos[i]=pos[i]-st[F[i]];
			s[F[i]][str[pos[i]]]=i;
			v[F[i]].push_back(i);
		}
		dfs(1);

	}
	S Get(S x,int y)
	{
		if (x.flag==1) return x;
		if (x.y==0)
		{
			

			if (!s[x.x][y]) x.flag=1;
			else x.x=s[x.x][y],x.y=st[x.x]-st[F[x.x]]-1;
		}
		else
		{
			if (str[pos[x.x]-(st[x.x]-st[F[x.x]])+x.y]!=y) x.flag=1;
			else x.y--;
		}
		return x;
	}
}S1,S2;
void link(int x,int y,int z)
{
	to[++l]=y;nxt[l]=fst[x];fst[x]=l;str[l]=z;
	to[++l]=x;nxt[l]=fst[y];fst[y]=l;str[l]=z;
}
void Dfs(int x,int f)
{
	sz[x]=1;Mx[x]=0;
	for (int i=fst[x];i;i=nxt[i])
	if (!used[i]&&to[i]!=f)
	{
		Dfs(to[i],x);
		sz[x]+=sz[to[i]];
		Mx[x]=max(Mx[x],sz[to[i]]);
	}
}
void GetG(int x,int f,int &G,int size)
{
	if (max(Mx[x],size-sz[x])<max(Mx[G],size-sz[G])) G=x;
	for (int i=fst[x];i;i=nxt[i])
		if (!used[i]&&to[i]!=f) GetG(to[i],x,G,size);
}
void dfs(int x,int f,int y)
{
	blg[x]=y;
	for (int i=fst[x];i;i=nxt[i])
		if (!used[i]&&to[i]!=f)
			dfs(to[i],x,y);
}
int FST[N],NXT[N*2];

void work(int x,int n1,int n2,S m1,S m2,int f)
{
	

	

	A1.add(n1,1);
	A2.add(n2,1);

	for (int i=FST[x];i;i=NXT[i])
	{
		

		if (i&1)
		{
			Ans[i/2]+=A1.qry(Q[i/2].p);
			Q0[i/2].y=m2.y?S2.F[m2.x]:m2.x;
			

		}
		else
		{
			Ans[i/2]+=A2.qry(Q[i/2].p);
			Q0[i/2].x=m1.y?S1.F[m1.x]:m1.x;
			

		}
	}

	for (int i=fst[x];i;i=nxt[i])
	if (!used[i]&&to[i]!=f)
	{
		

		work(to[i],A1.c[n1][str[i]],A2.c[n2][str[i]],S1.Get(m1,str[i]),S2.Get(m2,str[i]),x);
	}

	A1.add(n1,-1);
	A2.add(n2,-1);
}
void clrFST(int x,int f)
{
	FST[x]=0;
	for (int i=fst[x];i;i=nxt[i])
		if (!used[i]&&to[i]!=f)
			clrFST(to[i],x);
}
void solve(int x)
{
	int G=x;
	Dfs(x,0);
	GetG(x,0,G,sz[x]);
	


	for (int i=fst[G];i;i=nxt[i])
	if (!used[i])
		dfs(to[i],G,to[i]);
	swap(Fst[G],Fst[x]);
	for (int i=Fst[G],tmp;i;i=tmp)
	{
		

		tmp=Nxt[i];
		if (Q[i].x==G||Q[i].y==G)
		{
			

			if (Q[i].x!=G) NXT[i*2]=FST[Q[i].x],FST[Q[i].x]=i*2;

			if (Q[i].y!=G) NXT[i*2+1]=FST[Q[i].y],FST[Q[i].y]=i*2+1;

			continue;
		}
		

		if (blg[Q[i].x]==blg[Q[i].y])
		{
			

			Nxt[i]=Fst[blg[Q[i].x]];
			Fst[blg[Q[i].x]]=i;
		}
		else
		{
			
			

			NXT[i*2]=FST[Q[i].x];FST[Q[i].x]=i*2;

			NXT[i*2+1]=FST[Q[i].y];FST[Q[i].y]=i*2+1;


			
		}
	}
	
	work(G,1,1,newS,newS,0);
	
	clrFST(G,0);
	


	for (int i=fst[G];i;i=nxt[i])
	if (!used[i])
	{
		used[i]=used[i^1]=1;
		solve(to[i]);
	}
}
struct Md
{
	int x,l,r,p;
}md[N*2];
bool operator<(T a,T b){return a.x<b.x;}
bool operator<(Md a,Md b){return a.x<b.x;}
vector<T>v[N];
int val[N*8];
void mdy(int k,int l,int r,int x,int y,int p)
{
	if (x<=l&&r<=y)
	{
		val[k]+=p;
		return;
	}
	int mid=l+r>>1;
	if (x<=mid) mdy(k<<1,l,mid,x,y,p);
	if (y>mid) mdy(k<<1|1,mid+1,r,x,y,p);
}
int qry(int k,int l,int r,int x)
{
	if (l==r) return val[k];
	int mid=l+r>>1;
	if (x<=mid) return val[k]+qry(k<<1,l,mid,x);
	return val[k]+qry(k<<1|1,mid+1,r,x);
}
int main()
{
	scanf("%d%d%d",&n,&m,&q);
	for (int i=1;i<n;i++)
	{
		int x,y;
		scanf("%d%d%s",&x,&y,s);
		link(x,y,s[0]-'a');
	}

	int sta[N],ly=0,strr[N];
	
	A1.clr();S1.clr();
	A2.clr();S2.clr();

	for (int i=1;i<=m;i++)
	{
		scanf("%s",s);

		len[i]=strlen(s);

		sta[i]=ly+1;
		for (int j=0;j<len[i];j++)
		strr[++ly]=s[j]-'a';

		
		S1.add(s,len[i],i);
		
		A1.add(s,len[i],i);

		reverse(s,s+len[i]);
		
		S2.add(s,len[i],i);
		
		A2.add(s,len[i],i);


	}

	A1.build();S1.build();
	

	A2.build();S2.build();

	for (int i=1;i<=q;i++)
	{
		scanf("%d%d%d",&Q[i].x,&Q[i].y,&Q[i].p);
		Nxt[i]=i-1;
	}
	Fst[1]=q;

	solve(1);

	

	
	for (int i=1;i<=q;i++)
	{
		

		if (S1.stt[Q0[i].x]&&S2.stt[Q0[i].y])
			v[Q[i].p].push_back((T){S1.stt[Q0[i].x],S2.stt[Q0[i].y],i});
	}
	int tmpx[N],tmpy[N];
	for (int i=1;i<=m;i++)
	{
		int m1=1,m2=1;
		for (int j=0;j<len[i];j++)
		{
			m1=S1.c[m1][strr[sta[i]+j]];
			tmpx[j+1]=m1;
		}
		for (int j=len[i]-1;j>=0;j--)
		{
			m2=S2.c[m2][strr[sta[i]+j]];
			tmpy[j]=m2;
		}
		int ly=0;
		

		md[++ly]=(Md){0,1,S2.cnt,0};
		md[++ly]=(Md){S1.cnt+1,1,S2.cnt,0};
		

		for (int j=1;j<len[i];j++)
		{
			md[++ly]=(Md){S1.stt[tmpx[j]],S2.stt[tmpy[j]],S2.ed[tmpy[j]],1};
			md[++ly]=(Md){S1.ed[tmpx[j]]+1,S2.stt[tmpy[j]],S2.ed[tmpy[j]],-1};


		}
		sort(md+1,md+ly+1);
		sort(v[i].begin(),v[i].end());
		for (int j=1,k=0;j<=ly;)
		{
			int tmp=md[j].x;
			while(k<v[i].size()&&v[i][k].x<tmp)
				Ans[v[i][k].p]+=qry(1,1,S2.cnt,v[i][k].y),k++;
			while(j<=ly&&md[j].x==tmp)
				mdy(1,1,S2.cnt,md[j].l,md[j].r,md[j].p),j++;
		}
	}
	for (int i=1;i<=q;i++)
	{
		printf("%d\n",Ans[i]);
		


	}
	

	

}
