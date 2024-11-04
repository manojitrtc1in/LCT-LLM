




























































































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








int ji[100007],ou[100007];
int n,m;
int num[100007];

int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n+1;i++)
	{
		if(i!=n+1)scanf("%d",num+i);
		else num[i]=m;
		if(i%2==1)ji[(i-1)/2]=num[i]-num[i-1];
		else ou[(i-1)/2]=num[i]-num[i-1];
	}
	int maxv=1,max2;
	for(int i=0;i<=n/2;i++)
		maxv+=ji[i];
	max2=maxv-1;
	int cnt=maxv-1;
	for(int i=n/2;i>=0;i--)
	{
		cnt+=ou[i];
		cnt-=ji[i+1];
		if(ou[i]!=1||ji[i]!=1)maxv=max(maxv,cnt);
	}
	maxv=max(maxv,m-max2);
	printf("%d\n",maxv-1);
	return 0;
}