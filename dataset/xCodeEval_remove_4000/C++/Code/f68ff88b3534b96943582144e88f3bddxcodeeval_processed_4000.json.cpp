






























































































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







vector<int> nei[100007];
map<pii, int> xub;
int par[27][100007];
int dep[100007];

void dfs(int v,int p,int d)
{
	par[0][v] = p;
	dep[v] = d;
	for (int i = 0; i < SZ(nei[v]); i++)if(nei[v][i]!=p)
			dfs(nei[v][i], v, d + 1);
}



void init(int all)
{
	dfs(1, -1, 0);
	for (int i = 0; i + 1 < 27; i++)
		for (int j = 1; j <= all; j++)
			if(par[i][j]<0)
				par[i + 1][j] = -1;
			else
				par[i + 1][j] = par[i][par[i][j]];
}



int lca(int a,int b)
{
	if(dep[a]>dep[b])
		swap(a, b);
	for (int i = 0; i < 27; i++)
		if ((dep[a] - dep[b]) >> i & 1)
			b = par[i][b];
	if(a==b)
		return a;
	for (int i = 26; i >= 0; i--)
		if(par[i][a]!=par[i][b])
		{
			a = par[i][a];
			b = par[i][b];
		}
	return par[0][a];
}



int gao1[100007], gao2[100007], gao3[100007];
int n, k;

void killxu(int v,int p)
{
	int sum = gao1[v];
	for (int i = 0; i < SZ(nei[v]); i++)
		if(nei[v][i]!=p)
		{
			killxu(nei[v][i], v);
			sum += gao2[nei[v][i]];
		}
	gao2[v] = sum;
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n - 1; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		nei[a].pb(b);
		nei[b].pb(a);
		xub[mp(a, b)] = i;
		xub[mp(b, a)] = i;
	}
	init(n);
	scanf("%d", &k);
	for (int i = 0; i < k; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		gao1[a]++;
		gao1[b]++;
		gao1[lca(a, b)] -= 2;
	}
	killxu(1, -1);
	for (int i = 2; i <= n; i++)
		gao3[xub[mp(i, par[0][i])]] = gao2[i];
	for (int i = 0; i < n - 1; i++)
		printf("%d%c", gao3[i], i == n - 2 ? '\n' : ' ');
	return 0;
}