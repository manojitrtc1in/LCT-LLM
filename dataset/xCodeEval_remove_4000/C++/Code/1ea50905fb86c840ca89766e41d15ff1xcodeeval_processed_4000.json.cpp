












using   namespace            std;
typedef long long             ll;
typedef unsigned long long   llu;
typedef pair<int, int>       pii;
const long long MAXN = 2e5 + 99, INF = 0x3f3f3f3f, MAXP = 1e4;
ll HASHprime = 1333331;


int f_edge[MAXN];
int edges_cnt = 0;
struct edge
{
	int s, e, value, next;
	edge()
	{

	}
	edge(int ss, int ee, int vv, int nn)
	{
		s = ss;
		e = ee;
		value = vv;
		next = nn;
	}
}edges[MAXN];
void addedge(int s, int e, int v)
{
	edges[edges_cnt] = edge(s, e, v, f_edge[s]);
	f_edge[s] = edges_cnt++;
}
int flag = 0;
int vis[MAXN];
void dfs(int star)
{
	if (flag)
		return;
	vis[star] = 1;
	for (int s = f_edge[star]; ~s; s = edges[s].next)
	{
		int next = edges[s].e;
		if (vis[next] == 0)
			dfs(next);
		else if (vis[next] == 1)
		{
			flag = 1;
			return;
		}
	}
	vis[star] = -1;
}
int main()
{
	

	memset(f_edge, -1, sizeof(f_edge));
	int n, m, v[MAXN];
	scanf("%d%d", &n, &m);
	for (int i = 0, star, end; i < m; i++)
	{
		scanf("%d%d", &star, &end);
		v[i] = (star > end) + 1;
		addedge(star, end, 0);
	}
	for (int i = 1; i <= n && flag==0; ++i)
	{
		if(!vis[i])
			dfs(i);
	}
	cout << flag + 1 << endl;
	for (int i = 0; i < m; i++)
		cout << (flag ? v[i] : 1) << " ";
}

