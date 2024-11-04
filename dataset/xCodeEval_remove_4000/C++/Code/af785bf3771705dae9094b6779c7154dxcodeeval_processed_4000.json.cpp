









using namespace std;


int n;char s[N];
struct data{char s[10];}str[N][5];
int tot,point[N*2],nxt[N*N*8],v[N*N*8];
int dfn[N*2],low[N*2],stack[N*2],belong[N*2],ch[N*2],last[N*2],top,dfs_clock,scc;
bool flag,vis[N*2];

bool check(char *a,char *b)
{
	for (int i=1;i<=3;++i)
		if (a[i]!=b[i]) return 0;
	return 1;
}
void add(int x,int y)
{


	++tot; nxt[tot]=point[x]; point[x]=tot; v[tot]=y;
}
void tarjan(int x)
{
    dfn[x]=low[x]=++dfs_clock;stack[++top]=x;vis[x]=1;
    for (int i=point[x];i;i=nxt[i])
        if (!dfn[v[i]])
        {
            tarjan(v[i]);
            low[x]=min(low[x],low[v[i]]);
        }
        else if (vis[v[i]])
            low[x]=min(low[x],dfn[v[i]]);
    if (dfn[x]==low[x])
    {
        int now=0;++scc;
        while (now!=x)
        {
            now=stack[top--];
            belong[now]=scc;
            vis[now]=0;
        }
    }
}
void dfs(int x)
{
	vis[x]=1;
	if (ch[x]==-1)
	{
		flag=0;
		return;
	}
	stack[++top]=x;last[x]=ch[x];ch[x]=1;
	if (x<=n) stack[++top]=x+n,last[x+n]=ch[x+n],ch[x+n]=-1;
	else stack[++top]=x-n,last[x-n]=ch[x-n],ch[x-n]=-1;
	for (int i=point[x];i&&flag;i=nxt[i])
		if (!vis[v[i]]) dfs(v[i]);
}
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;++i)
	{
		scanf("%s",s);str[i][1].s[1]=s[0],str[i][1].s[2]=s[1],str[i][1].s[3]=s[2];
		scanf("%s",s);str[i][2]=str[i][1];str[i][2].s[3]=s[0];
	}
	for (int i=1;i<=n;++i)
		for (int j=i+1;j<=n;++j)
		{
			if (check(str[i][1].s,str[j][1].s))
				add(i,n+i),add(j,n+j);
			if (check(str[i][2].s,str[j][2].s))
				add(n+i,j),add(n+j,i);
			if (check(str[i][1].s,str[j][2].s))
				add(i,j),add(n+j,n+i);
			if (check(str[i][2].s,str[j][1].s))
				add(n+i,n+j),add(j,i);
		}
	for (int i=1;i<=n;++i)
		if (!dfn[i]) tarjan(i);
	for (int i=1;i<=n;++i)
		if (belong[i]==belong[n+i])
		{
			puts("NO");
			return 0;
		}
	for (int i=1;i<=n;++i)
	{
		if (ch[i]) continue;
		memset(vis,0,sizeof(vis));
		top=0;
		flag=1;dfs(i);
		if (!flag)
		{
			for (int j=1;j<=top;++j)
				ch[stack[j]]=last[stack[j]];
		}
	}
	puts("YES");
	for (int i=1;i<=n;++i)
	{
		if (ch[i]==1)
			for (int j=1;j<=3;++j) putchar(str[i][1].s[j]);
		else
			for (int j=1;j<=3;++j) putchar(str[i][2].s[j]);
		puts("");
	}
}