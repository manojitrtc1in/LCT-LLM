






























































































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





bool lie[37];
int n,m;

int main()
{
	scanf("%d%d",&m,&n);
	for(int i=0;i<n;i++)
	{
		printf("1\n");
		fflush(stdout);
		int x;
		scanf("%d",&x);
		if(x==-2)return 0;
		if(x==0)return 0;
		if(x==1)lie[i]=0;
		else lie[i]=1;
	}
	int l=2,r=m,cnt=0;
	while(l<=r)
	{
		int m=(l+r)/2;
		printf("%d\n",m);
		fflush(stdout);
		int x;
		scanf("%d",&x);
		if(x==-2)return 0;
		if(x==0)return 0;
		if(lie[cnt%n])x=-x;
		if(x==1)l=m+1;
		else r=m-1;
		cnt++;
	}
	return 0;
}