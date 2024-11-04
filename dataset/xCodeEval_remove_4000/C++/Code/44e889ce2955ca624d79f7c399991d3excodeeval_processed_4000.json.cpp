






























































































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
const int id0 = 250;
int n, d;
int cnt[30007];

int dfs(int now, int dis)
{
	if (dis < -id0 || dis > id0)
		return 0;
	int &x = dp[now][dis + id0];
	if (x == -1)
	{
		x = 0;
		if (now + d + dis - 1 <= 30000 && d + dis - 1 > 0)
			x = max(x, dfs(now + d + dis - 1, dis - 1));
		if (now + d + dis <= 30000 && d + dis > 0)
			x = max(x, dfs(now + d + dis, dis));
		if (now + d + dis + 1 <= 30000 && d + dis + 1 > 0)
			x = max(x, dfs(now + d + dis + 1, dis + 1));
		x += cnt[now];
	}
	return x;
}

int main()
{
	scanf("%d%d", &n, &d);
	for(int i=0;i<n;i++)
	{
		int x;
		scanf("%d", &x);
		cnt[x]++;
	}
	FILL1(dp);
	printf("%d\n", dfs(d, 0));
	return 0;
}