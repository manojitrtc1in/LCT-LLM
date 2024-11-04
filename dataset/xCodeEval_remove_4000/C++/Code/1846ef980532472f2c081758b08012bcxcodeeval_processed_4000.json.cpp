































































































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





int ppos[1000007];
int pnxtx[1000007],pprex[1000007],cntx=0,nowp=0;
int n;
char s[1000007];
int dp[1000007];

int qzh[1000007];

bool hvstr(int a,int b)
{
	return a<b?0:qzh[a]-qzh[b];
}

bool check(int m)
{
	FILL0(dp);
	for(int i=1;i<=nowp;i++)
	{
		dp[i]=dp[i-1];
		if(i>=2&&(!hvstr(ppos[i]-m-1,dp[i-2])))dp[i]=max(dp[i],min(n,ppos[i-1]+m));
		if(!hvstr(ppos[i]-m-1,dp[i-1]))dp[i]=max(dp[i],ppos[i]);
		if(!hvstr(ppos[i],dp[i-1]))dp[i]=max(dp[i],min(n,ppos[i]+m));
	}
	if(!hvstr(n,dp[nowp]))return 1;
	else return 0;
}

int main()
{
	scanf("%d",&n);
	scanf("%s",s+1);
	FILL1(pnxtx);
	FILL1(pprex);
	for(int i=1;i<=n;i++)
	{
		if(s[i]=='*')
		{
			pnxtx[nowp]=i;
			cntx++;
		}
		else if(s[i]=='P')
		{
			nowp++;
			ppos[nowp]=i;
		}
	}
	int id0=nowp+1;
	for(int i=n;i>=1;i--)
	{
		if(s[i]=='*')pprex[id0]=i;
		else if(s[i]=='P')
			id0--;
	}
	if(!cntx)OVER("0 0\n");
	if(nowp==1)
	{
		int cnt1=0,cnt2=0;
		for(int i=1;i<ppos[1];i++)
			if(s[i]=='*')
				cnt1++;
		for(int i=ppos[1]+1;i<=n;i++)
			if(s[i]=='*')
				cnt2++;
		if(cnt1>cnt2)
			printf("%d %d\n",cnt1,ppos[1]-pprex[1]);
		else printf("%d %d\n",cnt2,pnxtx[1]-ppos[1]);
		return 0;
	}
	qzh[0]=0;
	for(int i=1;i<=n;i++)
		qzh[i]=qzh[i-1]+(s[i]=='*');
	int l=0,r=1e6+5;
	while(r-l>1)
	{
		int m=(l+r)/2;
		if(check(m))r=m;
		else l=m;
	}
	printf("%d %d\n",cntx,r);
	return 0;
}
