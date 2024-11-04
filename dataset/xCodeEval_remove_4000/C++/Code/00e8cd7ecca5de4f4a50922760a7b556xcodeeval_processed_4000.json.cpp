































































































using namespace std;
typedef pair<int,int> pii;
typedef unsigned long long UINT;
typedef unsigned int uint;
typedef long long INT;
typedef long double ldouble;
typedef pair<INT,INT> PII;
typedef stringstream sst;
typedef istringstream iss;
typedef vector<int> vint;
typedef vector<INT> VINT;
typedef vector<pii> vpii;
typedef vector<PII> VPII;
typedef priority_queue<int> pqi;
typedef priority_queue<INT> PQI;
typedef priority_queue<pii> pqp;
typedef priority_queue<PII> PQP;
typedef priority_queue<int,vint,greater<int> > xqi;
typedef priority_queue<INT,VINT,greater<INT> > XQI;
typedef priority_queue<pii,vpii,greater<pii> > xqp;
typedef priority_queue<PII,VPII,greater<PII> > XQP;
inline int read()
{
	int num=0;
	char c=getchar();
	if(c=='-')return -read();
	while(c>='0'&&c<='9')
	{
		num=(num<<3)+(num<<1)+c-'0';
		c=getchar();
	}
	return num;
}
inline INT READ()
{
	INT num=0;
	char c=getchar();
	if(c=='-')return -READ();
	while(c>='0'&&c<='9')
	{
		num=(num<<3)+(num<<1)+c-'0';
		c=getchar();
	}
	return num;
}





namespace dsu
{
	int fa[100007],hv[100007];
	void init()
	{
		for(int i=0;i<100007;i++)
		{
			fa[i]=i;
			hv[i]=1;
		}
	}
	int root(int x)
	{
		if(fa[x]==x)return x;
		else return fa[x]=root(fa[x]);
	}
	void conn(int x,int y)
	{
		int xx=root(x);
		int yy=root(y);
		if(xx==yy)return;
		fa[yy]=xx;
		hv[xx]+=hv[yy];
	}
}

namespace ycsjuruo
{
	map<int,int> m;
	int dp[100007];
	void upd(int v,int c,int k)
	{
		for(int i=v;i>=c*k;i--)
			dp[i]=min(dp[i],dp[i-c*k]+k);
	}
	bool islucky(int x)
	{
		if(x%10!=4&&x%10!=7)return 0;
		if(x<10)return 1;
		return islucky(x/10);
	}
}

int n,m;

int main()
{
	scanf("%d%d",&n,&m);
	dsu::init();
	for(int i=0;i<m;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		dsu::conn(a-1,b-1);
	}
	for(int i=0;i<n;i++)
		if(dsu::root(i)==i)
			ycsjuruo::m[dsu::hv[i]]++;
	FILLBIG(ycsjuruo::dp);
	ycsjuruo::dp[0]=0;
	foreach(it,ycsjuruo::m)
	{
		int c=it->first,k=it->second;
		while(k)
		{
			ycsjuruo::upd(n,c,(k+1)/2);
			k/=2;
		}
	}
	int ans=Inf;
	for(int i=4;i<=n;i++)
		if(ycsjuruo::islucky(i))
			ans=min(ans,ycsjuruo::dp[i]);
	if(ans==Inf)OVER("-1\n");
	else OVER("%d\n",ans-1);
}
