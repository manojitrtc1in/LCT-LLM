































































































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





string a,b;
int n;
int na,nb;
int tr[27][27][27];
int cnt[27][27];
int cana[57][57][27],canb[57][57][27];
int dp[57][57];



int main()
{
	cin>>a>>b;
	na=SZ(a);
	nb=SZ(b);
	cin>>n;
	string S;
	for(int i=0;i<n;i++)
	{
		cin>>S;
		tr[S[3]-'a'][S[4]-'a'][cnt[S[3]-'a'][S[4]-'a']++]=S[0]-'a';
	}
	for(int i=0;i<na;i++)
		cana[i][i][a[i]-'a']=1;
	for(int l=2;l<=na;l++)
		for(int i=0;i<=na-l;i++)
		{
			int j=i+l-1;
			for(int k=i;k<j;k++)
				for(int l1=0;l1<26;l1++)
					if(cana[i][k][l1])
						for(int l2=0;l2<26;l2++)
							if(cana[k+1][j][l2])
								for(int I=0;I<cnt[l1][l2];I++)
									cana[i][j][tr[l1][l2][I]]=1;
		}
	for(int i=0;i<nb;i++)
		canb[i][i][b[i]-'a']=1;
	for(int l=2;l<=nb;l++)
		for(int i=0;i<=nb-l;i++)
		{
			int j=i+l-1;
			for(int k=i;k<j;k++)
				for(int l1=0;l1<26;l1++)
					if(canb[i][k][l1])
						for(int l2=0;l2<26;l2++)
							if(canb[k+1][j][l2])
								for(int I=0;I<cnt[l1][l2];I++)
									canb[i][j][tr[l1][l2][I]]=1;
		}
	FILLBIG(dp);
	for(int i=0;i<na;i++)
		for(int j=0;j<nb;j++)
			for(int c=0;c<26;c++)
			{
				if(cana[0][i][c]&&canb[0][j][c])
					dp[i][j]=1;
				for(int k=1;k<=i;k++)
					if(cana[k][i][c])
						for(int l=1;l<=j;l++)
							if(canb[l][j][c])
								dp[i][j]=min(dp[i][j],dp[k-1][l-1]+1);
			}
	if(dp[na-1][nb-1]==Inf)OVER("-1");
	else OVER("%d\n",dp[na-1][nb-1]);
	return 0;
}