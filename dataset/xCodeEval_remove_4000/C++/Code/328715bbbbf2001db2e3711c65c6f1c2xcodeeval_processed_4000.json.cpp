






























































































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





int dp[30007][507];
int n, d;
int p[30007];
int tr[30007];
int ans = 0;

int main()
{
	scanf("%d%d", &n, &d);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", p + i);
		tr[p[i]]++;
	}
	for (int i = 0; i <= 30000; i++)
		for (int j = 0; j <= 500; j++)
			dp[i][j] = -Inf;
	dp[d][250] = tr[d];
	ans = dp[d][250];
	for (int i = d + 1; i <= 30000; i++)
		for (int j = -250; j <= 250; j++)
		{
			if (d + j > 0 && j >= -249 && i - d - j >= 0 && i - d - j <= 30000)
				dp[i][250 + j] = max(dp[i][250 + j], dp[i - d - j][249 + j] + tr[i]);
			if (d + j > 0 && i - d - j >= 0 && i - d - j <= 30000)
				dp[i][250 + j] = max(dp[i][250 + j], dp[i - d - j][250 + j] + tr[i]);
			if (d + j > 0 && j <= 249 && i - d - j >= 0 && i - d - j <= 30000)
				dp[i][250 + j] = max(dp[i][250 + j], dp[i - d - j][251 + j] + tr[i]);
			ans = max(ans, dp[i][250 + j]);
		}
	printf("%d\n", ans);
	return 0;
}