










































using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;










template<typename T1, typename T2>
inline void chkmin(T1& x, const T2& y)
{
    if (y < x) x = y;
}

template<typename T1, typename T2>
inline void chkmax(T1& x, const T2& y)
{
    if (x < y) x = y;
}
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
ld id0 = 0;
double getTime() { return (clock() - id0) / (double)CLOCKS_PER_SEC; }
pair<int, int> operator-(pair<int, int> a, pair<int, int> b)
{
    return { a.first - b.first, a.second - b.second };
}
pair<int, int> operator+(pair<int, int> a, pair<int, int> b)
{
    return { a.first + b.first, a.second + b.second };
}







































const int inf = 1e16 + 228;
using namespace chrono;
const ld EPS = 1e-12;
const ld PI = acos(-1.0);
const int mod = 1000000007;
const ll INF = 1e12;
const int MAXN = 10e3 + 228;
struct edge
{
    int a, b, cap;
};
vector<edge> e;
vector<int> g[MAXN];
int d[MAXN];
void addedge(int a, int b, int cap)
{
    g[a].pbc(e.size());
    e.pbc({ a,b,cap });
    g[b].pbc(e.size());
    e.pbc({ b,a,0 });
}
int s, t;
bool bfs()
{
    fill(d, d + MAXN, inf);
    d[s] = 0;
    queue<int> q;
    q.push(s);
    while (q.size())
    {
        int v = q.front();
        q.pop();
        for (int i : g[v])
        {
            if (e[i].cap > 0)
            {
                int b = e[i].b;
                if (d[b] > d[v] + 1)
                {
                    d[b] = d[v] + 1;
                    q.push(b);
                }
            }
        }
    }
    return d[t] != inf;
}
int ptr[MAXN];
int dfs(int v, int flow)
{
    if (v == t) return flow;
    if (!flow) return 0;
    int sum = 0;
    for (; ptr[v] < g[v].size(); ++ptr[v])
    {
        int b = e[g[v][ptr[v]]].b;
        int cap = e[g[v][ptr[v]]].cap;
        if (cap <= 0)continue;
        if (d[b] != d[v] + 1) continue;
        int x = dfs(b, min(flow, cap));
        int id = g[v][ptr[v]];
        e[id].cap -= x;
        e[id ^ 1].cap += x;
        flow -= x;
        sum += x;
    }
    return sum;
}
int dinic()
{
    int ans = 0;
    while (1)
    {
        if (!bfs()) break;

        fill(ptr, ptr + MAXN, 0);
        int x = dfs(s, 1e9);
        if (!x)break;
        ans += x;
    }
    return ans;
}
signed main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout.precision(15), cout.setf(ios::fixed);
    int n;
    cin >> n;
    vector<int>a(n);
    vin(a);
    vector<int> b(n);
    vin(b);
    s = MAXN - 1, t = MAXN - 2;
    for (int i = 0; i < n; ++i)
    {
        if (b[i] > 0)
        {
            addedge(s, i, b[i]);
        }
        else
        {
            addedge(i, t, -b[i]);
        }
    }
    for (int i = 0; i < n; ++i)
    {
        map<int, vector<int>> pos;
        for (int j = 0; j < i; ++j)
        {
            pos[a[j]].pbc(j);
        }
        for (auto j : pos)
        {
            if (a[i] % j.first == 0)
            {
                addedge(i, j.second.back(), 1e18);
            }
        }
    }
    int sm = -dinic();
    for (int i = 0; i < n; ++i) sm += max(b[i], 0ll);
    cout << sm;
    

}







