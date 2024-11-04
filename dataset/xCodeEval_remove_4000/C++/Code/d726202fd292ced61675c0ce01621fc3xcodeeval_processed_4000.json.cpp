






using namespace std;



const int N = 1e6 + 10, mod = 998244353;
vector<int> g[N];
int c[N], mx[N][2], s[N];
struct node {
    int l, r;
    int v;
}tr[N * 4];

void push_up(int u)
{
    tr[u].v = max(tr[u << 1].v, tr[u << 1 | 1].v);
}

void build(int u, int l, int r)

{
    tr[u] = { l,r };
    if (l == r) return;
    int mid = (l + r) >> 1;
    build(u << 1, l, mid);
    build(u << 1 | 1, mid + 1, r);
}
int query(int u, int l, int r)
{
    if (tr[u].l >= l && tr[u].r <= r) return tr[u].v;
    int mid = tr[u].l + tr[u].r >> 1;
    int v = 0;
    if (mid >= l)
    {
        v = max(v, query(u << 1, l, r));
    }
    if (r > mid)
    {
        v = max(v, query(u << 1 | 1, l, r));
    }
    return v;
}




































































































































































































































































































































void dfs1(int u, int fa)
{
	if (g[u].size() - (u==1?0:1) == 0) return;
	for (int &v : g[u]) 
	{
		if (v != fa) 
		{
			c[v] = c[u] / (g[u].size() - 1 + (u == 1));
			dfs1(v, u);
		}
	}
}











































































































































































































































void dfs2(int u, int fa) {
    if (g[u].size() - (u == 1 ? 0 : 1) == 0) {
        mx[u][0] = c[u] * s[u];
        mx[u][1] = (c[u] + 1) * s[u];
        return;
    }
    int z = g[u].size() - (u == 1 ? 0 : 1);
    vector<int> a, b;
    int s1 = 0;
    for (int v : g[u]) {
        if (v != fa) {
            dfs2(v, u);
            a.push_back(mx[v][0]);
            b.push_back(mx[v][1]);
            s1 += mx[v][0];
        }
    }
    vector<int> s2(z + 1, 0);
    for (int i = 0; i < z; i++) {
        b[i] -= a[i];
    }
    sort(b.begin(), b.end(), greater<int>());
    for (int i = 1; i <= z; i++) {
        s2[i] = s2[i - 1] + b[i - 1];
    }
    int y = c[u] % z;
    

    mx[u][0] = s1 + s2[y] + s[u] * c[u];
    mx[u][1] = s1 + s2[y + 1] + s[u] * (c[u] + 1);
}
signed main()
{


































































































































































































































































































	int t; cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		for (int i = 1; i <= n; i++) {
			g[i].clear();
		}
		for (int i = 2; i <= n; i++)
		{
			int x; cin >> x;
			g[x].push_back(i);
			g[i].push_back(x);
		}
		for (int i = 1; i <= n; i++) {
			cin >> s[i];
		}
		c[1] = k;
        dfs1(1, 0);
        dfs2(1, 0);
        cout << mx[1][0] << "\n";
	}
}