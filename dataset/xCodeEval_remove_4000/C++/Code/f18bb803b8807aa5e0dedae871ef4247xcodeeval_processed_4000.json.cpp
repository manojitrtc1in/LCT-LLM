































































































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





int n;

struct B1T
{
	INT bit[100007];
	const int n=100007;
	void add(int djg,int x)
	{
		while(djg<=n)
		{
			bit[djg]+=x;
			djg+=(djg&-djg);
		}
	}
	INT sum(int djg)
	{
		INT id0=0;
		while(djg)
		{
			id0+=bit[djg];
			djg-=(djg&-djg);
		}
		return id0;
	}
}bit;

double x[100007],y[100007];
int w;
map<double,int> cnt;
double as[100007];
int cnta;
pair<double,int> bs[100007];

int main()
{
	scanf("%d%d",&n,&w);
	for(int i=0;i<n;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		x[i]=1.00*a/(b+w);
		y[i]=1.00*a/(b-w);
		cnt[y[i]]++;
	}
	INT ans=0;
	for(int i=0;i<n;i++)
		ans+=cnt[y[i]]-1;
	ans/=2;
	for(int i=0;i<n;i++)
		as[i]=x[i];
	sort(as,as+n);
	cnta=unique(as,as+n)-as;
	for(int i=0;i<n;i++)
		bs[i]=mp(y[i],i);
	sort(bs,bs+n);
	int now=0;
	for(int i=0;i<n;i++)
	{
		while(bs[now].first<bs[i].first)
		{
			int id=lower_bound(as,as+cnta,x[bs[now].second])-as;
			bit.add(100006-id,1);
			now++;
		}
		int id=lower_bound(as,as+cnta,x[bs[i].second])-as;
		ans+=bit.sum(100006-id);
	}
	
	printf("%I64d\n",ans);
	
	printf("%lld\n",ans);
	
	return 0;
}