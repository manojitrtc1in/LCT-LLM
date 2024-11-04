










using namespace std;


int n,m,x,y,z,type;
long long ans;
bitset <N> f[2][65][N],p,q;

int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;++i)
	{
		scanf("%d%d%d",&x,&y,&z);
		f[z][0][x][y]=1;
	}
	for (int i=1;i<=60;++i)
		for (int j=1;j<=n;++j)
			for (int k=1;k<=n;++k)
			{
				if (f[0][i-1][j][k]) f[0][i][j]|=f[1][i-1][k];
				if (f[1][i-1][j][k]) f[1][i][j]|=f[0][i-1][k];
			}
	for (int i=1;i<=n;++i)
		if (f[0][60][1][i])
		{
			puts("-1");
			return 0;
		}
	type=0;ans=0LL;p[1]=1;
	for (int i=60;i>=0;--i)
	{
		q.reset();
		for (int j=1;j<=n;++j) if (p[j]) q|=f[type][i][j];
		if (q.any()) type^=1,ans+=1LL<<i,p=q;
		if (ans>1e18) break;
	}
	if (ans>1e18) puts("-1");
	else printf("%I64d\n",ans);
}