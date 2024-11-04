































































































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





int dpa[57][57],dpb[57][57],dp[57][57];
int trn[27][27];
int k;
string A,B;
string s;
int a[57],b[57];

int main()
{
	cin>>A>>B;
	int n=SZ(A),m=SZ(B);
	for(int i=1;i<=n;i++)
	{
		a[i]=A[i-1]-'a';
		dpa[i][i]|=MASK(a[i]);
	}
	for(int j=1;j<=m;j++)
	{
		b[j]=B[j-1]-'a';
		dpb[j][j]|=MASK(b[j]);
	}
	cin>>k;
	for(int i=0;i<k;i++)
	{
		cin>>s;
		trn[s[3]-'a'][s[4]-'a']|=MASK(s[0]-'a');
	}
	for(int i=1;i<=n;i++)
		for(int j=0;j<26;j++)
			if(BIT(trn[a[i]][a[i+1]],j))
				dpa[i][i+1]|=MASK(j);
	for(int i=1;i<=m;i++)
		for(int j=0;j<26;j++)
			if(BIT(trn[b[i]][b[i+1]],j))
				dpb[i][i+1]|=MASK(j);
	

	for(int len=3;len<=n;len++)
		for(int i=1;i<=n-len+1;i++)
		{
			int j=i+len-1;
			for(int k=i;k<j;k++)
				for(int l1=0;l1<26;l1++)if(BIT(dpa[i][k],l1))
					for(int l2=0;l2<26;l2++)if(BIT(dpa[k+1][j],l2))
						dpa[i][j]|=trn[l1][l2];
		}
	for(int len=3;len<=m;len++)
		for(int i=1;i<=m-len+1;i++)
		{
			int j=i+len-1;
			for(int k=i;k<j;k++)
				for(int l1=0;l1<26;l1++)if(BIT(dpb[i][k],l1))
					for(int l2=0;l2<26;l2++)if(BIT(dpb[k+1][j],l2))
						dpb[i][j]|=trn[l1][l2];
		}
	

	FILLBIG(dp);
	dp[0][0]=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			for(int a=0;a<i;a++)
				for(int b=0;b<j;b++)
					if(dpa[a+1][i]&dpb[b+1][j])
						dp[i][j]=min(dp[i][j],dp[a][b]+1);
	if(dp[n][m]==Inf)OVER("-1");
	else OVER("%d\n",dp[n][m]);
	return 0;
}