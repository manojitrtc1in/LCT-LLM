



















using namespace std;
typedef long long ll;
struct edgee
{
	int from, to;
	ll cap,tempcap;
	edgee(int a, int b, ll c) :from(a), to(b), cap(c)
	{}
	edgee()
	{}
};
edgee edge[1010];
int first[1010], nextt[1010];
int id0 = 0;
int h[1010], num[1010],fa[1010],edgenum[1010];
int tfirst[1010];
bool isin[1010];
void addedge(int from, int to, ll cap)
{
	edge[id0] = edgee(from, to, cap);
	nextt[id0] = first[from];
	first[from] = id0++;
	edge[id0] = edgee(to, from, 0);
	nextt[id0] = first[to];
	first[to] = id0++;
}
int n, m, x;
bool endd;
void bfs(int t,int s)
{
	for (int i = 1; i <= n; i++)
		h[i] = 1000000000;
	h[t] = 0;
	num[0] = 1;
	queue<int>que;
	que.push(t);
	while (!que.empty())
	{
		int now = que.front();
		que.pop();
		for (int i = first[now]; i != -1; i = nextt[i])
		{
			int to = edge[i].to;
			if (h[to] != 1000000000)
				continue;
			h[to] =  h[now] + 1;
			num[h[to]]++;
			que.push(to);
		}
	}
}
void augument(int t,ll &mincap)
{
	for (int i = fa[t]; i; i = fa[i])
	{
		edge[edgenum[i]].tempcap -= mincap;
		edge[edgenum[i] ^ 1].tempcap += mincap;
	}
}
ll isap(int s,int t)
{
	int temp = s;
	ll capp = 100000000000000000;
	ll ans = 0;
	while (h[s] <n)
	{
		int tempp = temp;
		if (temp == t)
		{
			augument(temp, capp);
			ans += capp;
			temp =s;
			capp = 100000000000000000;
			continue;
		}
		for (int &i = first[temp]; i != -1; i = nextt[i])
		{
			int to = edge[i].to;
			if (h[to] == h[temp] - 1 && edge[i].tempcap > 0)
			{
				fa[to] = temp;
				edgenum[temp] = i;
				temp = to;
				capp = min(capp, edge[i].tempcap);
				break;
			}
		}
		if (tempp != temp)
			continue;
		num[h[temp]]--;
		if (num[h[temp]] == 0)
			break;
		int minh = 100000000;
		for (int j = tfirst[temp]; j != -1; j = nextt[j])
		{
			int to = edge[j].to;
			if (edge[j].tempcap > 0)
				minh = min(minh, h[to]);
		}
		first[temp] = tfirst[temp];
		if (minh != 100000000)
			h[temp] = minh+1;
		else
			h[temp] = 100000000;
		if (h[temp] != 100000000)
		num[h[temp]]++;
		if (temp != s)
			temp = fa[temp];
	}
	return ans;
}
ll solve(double k)
{
	for (int i = 0; i < id0; i++)
		edge[i].tempcap = (ll)(edge[i].cap / k);
	for (int i = 1; i <= n; i++)
		first[i] = tfirst[i],fa[i]=0,edgenum[i]=0;
	ll ans = 0;
	bfs(n, 1);
	ans += isap(1, n);
	return ans;
}
int main()
{
	scanf("%d%d%d", &n, &m, &x);
	for (int i = 0; i <= n; i++)
		first[i] = -1;
	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		addedge(a, b, c);
	}
	for (int i = 1; i <= n; i++)
		tfirst[i] = first[i];
	double l = 0;
	    double r = 1000000;
		double l1 = 0;
		double r1 = r;
		int t = 0;
	while ((r - l )> (1e-11))
	{
		t++;
		double mid = (l + r) / 2;
		if (solve(mid)>=x)
		{
			l = mid;
			

				

		}
		else
		{
			r = mid;
			

				

		}
		if (t >= 60)
			break;
	}
	printf("%.8lf\n", l*x);
	return 0;
	}
