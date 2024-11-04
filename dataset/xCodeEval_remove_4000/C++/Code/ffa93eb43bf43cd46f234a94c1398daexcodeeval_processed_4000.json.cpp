









using namespace std;



vector<pair<int, pair<int,int> > >edges;
int n,m,k,w;
vector<bool> tk;
vector<int> p;
vector<vector<int> > g;
int find(int i)
{
	if (p[i] == -1) return i;
	return p[i] = find(p[i]);
}
int un(int i, int j)
{
	int a,b;
	a = find(i);
	b = find(j);
	p[a] = b;
}
bool con(int i, int j)
{
	return find(i) == find(j);
}
vector<pair<int,int> > res;
void dfs(int i, int par)
{
	if (tk[i]) return;
	tk[i] = true;
	if (par==-1) res.push_back(make_pair(i+1,0));
	else res.push_back(make_pair(i+1,par+1));
	for (int j = 0; j < g[i].size(); j++) dfs(g[i][j], i);
}
int main()
{
	cin>>n>>m>>k>>w;
	p = vector<int> (k,-1);
	vector<vector<string> > a(k, vector<string> (n));
	for (int i = 0; i < k; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin>>a[i][j];
		}
	}
	for (int i = 0; i < k; i++)
	{
		for (int j = i+1; j < k; j++)
		{
			int cnt = 0;
			for (int x = 0; x < n; x++)
			{
				for (int y = 0;y < m; y++)
				{
					if (a[i][x][y] != a[j][x][y]) cnt++;
				}
			}
			edges.push_back(make_pair(cnt, make_pair(i, j)));
		}
	}
	sort(edges.begin(), edges.end());
	g=vector<vector<int> > (k);
	int r = 0;
	for (int i = 0; i < edges.size(); i++)
	{
		if (edges[i].first*w >= n*m) break;
		if (con(edges[i].second.first, edges[i].second.second)) continue;
		r += edges[i].first*w;
		un(edges[i].second.first, edges[i].second.second);
		g[(edges[i].second.first)].push_back(edges[i].second.second);
		g[(edges[i].second.second)].push_back(edges[i].second.first);
	}
	tk = vector<bool>(k, false);
	
	for (int i = 0; i < k; i++)
	{
		if (tk[i] == false) r += n*m;
		dfs(i,-1);
	}
	cout<<r<<endl;
	for (int i = 0; i < res.size(); i++)
		cout<<res[i].first<<" "<<res[i].second<<endl;
}