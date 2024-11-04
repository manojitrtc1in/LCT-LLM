
































































































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





int dp[107][107][107],dp2[107][107],dp3[107][10807];
int n,m;
int x[107][107],len[107];

int main()
{
	n=read();
	m=read();
	for(int i=1;i<=n;i++)
	{
		len[i]=read();
		for(int j=1;j<=len[i];j++)
			x[i][j]=read();
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=len[i];j++)
			for(int k=0;j+k<=len[i];k++)
			{
				dp[i][j][k]=max(dp[i][j][k],max(k!=0?dp[i][j][k-1]+x[i][len[i]-k+1]:0,j!=0?dp[i][j-1][k]+x[i][j]:0));
				dp2[i][j+k]=max(dp2[i][j+k],dp[i][j][k]);
			}
	}
	for(int i=0;i<n;i++)
		for(int j=0;j<=m;j++)
			for(int k=0;k<=len[i+1];k++)
				dp3[i+1][j+k]=max(dp3[i+1][j+k],dp3[i][j]+dp2[i+1][k]);
	printf("%d\n",dp3[n][m]);
	return 0;
}