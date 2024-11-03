





using namespace :: std;
int color[200100];
int col[200100];
int moalefe[200100];
bool vis[200100];
bool visited[200100];
bool check[200100];
vector <int> v[200100];
vector <int> graph[200100];
int grt = 0, id0 = 0, id1 = 0;
int tabaghe[200100];
int tabaghe2[200100];
bool visited1[200100];
bool visited2[200100];
void dfs(int x)
{
    visited[x] = 1;
    moalefe[x] = grt;
    col[grt] = color[x];
    for (int i = 0; i < graph[x].size(); i++)
    {
        int u = graph[x][i];
        if (!visited[u] && color[u] == color[x])
        {
            dfs(u);
        }
    }
}
void unite(int x)
{
    check[x] = 1;
    for (int i = 0; i < graph[x].size(); i++)
    {
        int u = graph[x][i];
        if (!check[u])
        {
            if (moalefe[u] != moalefe[x])
            {
                v[moalefe[u]].push_back(moalefe[x]);
                v[moalefe[x]].push_back(moalefe[u]);
            }
            unite(u);
        }
    }
}
int bfs(int x)
{
    queue <int> q;
    visited1[x] = 1;
    q.push(x);
    tabaghe[x] = 0;
    int up = x;
    int mx = 0, ans = 0;
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        visited1[x] = 1;
        for (int i = 0; i < v[x].size(); i++)
        {
            if (!visited1[v[x][i]])
            {
                q.push(v[x][i]);
                tabaghe[v[x][i]] = tabaghe[x] + 1;
                

                if (mx < tabaghe[v[x][i]])
                {
                    mx = tabaghe[v[x][i]];
                    up = v[x][i];
                }
            }
        }
    }
    x = up;
    queue <int> q2;
    visited2[x] = 1;
    q2.push(x);
    tabaghe2[x] = 0;
    while (!q2.empty())
    {
        int x = q2.front();
        q2.pop();
        visited2[x] = 1;
        for (int i = 0; i < v[x].size(); i++)
        {
            if (!visited2[v[x][i]])
            {
                q2.push(v[x][i]);
                tabaghe2[v[x][i]] = tabaghe2[x] + 1;
                ans = max(ans, tabaghe2[v[x][i]]);
            }
        }
    }
    return ans;
}
int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long long n;
    cin >> n;
    for (int i = 0; i < n; i++){cin >> color[i];}
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b; a--; b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    for (int i = 0; i < n;)
    {
        dfs(i);
        grt++;
        while(visited[i]){i++;}
    }
    if (grt == 1){cout << 0; return 0;}
    unite(0);
    cout << (bfs(0) + 1) / 2;
    return 0;
}
