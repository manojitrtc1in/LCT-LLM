


using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;














    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)





    cerr << 
    _print(x);         \
    cerr << endl;


void _print(ll t)
{
    cerr << t;
}
void _print(int t) { cerr << t; }
void _print(string t) { cerr << t; }
void _print(char t) { cerr << t; }
void _print(lld t) { cerr << t; }
void _print(double t) { cerr << t; }
void _print(ull t) { cerr << t; }

template <class T, class V>
void _print(pair<T, V> p);
template <class T>
void _print(vector<T> v);
template <class T>
void _print(set<T> v);
template <class T, class V>
void _print(unordered_set<T> v);
template <class T, class V>
void _print(map<T, V> v);
template <class T, class V>
void _print(unordered_map<T, V> v);
template <class T>
void _print(multiset<T> v);
template <class T, class V>
void _print(pair<T, V> p)
{
    cerr << "{";
    _print(p.ff);
    cerr << ",";
    _print(p.ss);
    cerr << "}";
}
template <class T>
void _print(vector<T> v)
{
    cerr << "[";
    for (T i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T>
void _print(set<T> v)
{
    for (T i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T>
void _print(unordered_set<T> v)
{
    cerr << "[ ";
    for (T i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T>
void _print(multiset<T> v)
{
    cerr << "[ ";
    for (T i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T, class V>
void _print(unordered_map<T, V> v)
{
    cerr << "[ ";
    for (auto i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T, class V>
void _print(map<T, V> v)
{
    cerr << "[ ";
    for (auto i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}

class id0
{
    ll *rank, *parent, n;

public:
    id0(ll n)
    {
        rank = new ll[n];
        parent = new ll[n];
        this->n = n;
        makeSet();
    }
    void makeSet()
    {
        for (ll i = 0; i < n; i++)
        {
            parent[i] = i;
        }
    }
    ll find(ll x)
    {
        if (parent[x] != x)
        {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
    void Union(ll x, ll y)
    {
        ll xset = find(x);
        ll yset = find(y);
        if (xset == yset)
            return;
        if (rank[xset] < rank[yset])
        {
            parent[xset] = yset;
        }
        else if (rank[xset] > rank[yset])
        {
            parent[yset] = xset;
        }
        else
        {
            parent[yset] = xset;
            rank[xset] = rank[xset] + 1;
        }
    }
};
struct hashFunction
{
    size_t operator()(const pair<ll, ll> &x) const
    {
        return x.first ^ x.second;
    }
};
struct custom_hash
{
    static uint64_t splitmix64(uint64_t x)
    {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const
    {
        static const uint64_t id1 = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + id1);
    }
};
void dfs(ll i, map<ll, vector<ll>> &adj, vector<vector<ll>> &dp, vector<ll> &parent, vector<vector<ll>> &range)
{
    if (adj.find(i) == adj.end())
    {
        debug(i);
        return;
    }
    for (auto x : adj[i])
    {
        dfs(x, adj, dp, parent, range);
        dp[i][0] += max(dp[x][0] + abs(range[i][0] - range[x][0]), dp[x][1] + abs(range[i][0] - range[x][1]));
        dp[i][1] += max(dp[x][0] + abs(range[i][1] - range[x][0]), dp[x][1] + abs(range[i][1] - range[x][1]));
    }
    debug(i);
    

}
void id2(ll i, map<ll, vector<ll>> &mmp, vector<bool> &visit, vector<ll> &parent)
{
    visit[i] = true;
    for (auto x : mmp[i])
    {
        if (!visit[x])
        {
            parent[x] = i;
            id2(x, mmp, visit, parent);
        }
    }
}
void solve()
{
    ll n;
    cin >> n;
    vector<vector<ll>> range(n + 1, vector<ll>(2));
    for (ll i = 1; i <= n; i++)
    {
        cin >> range[i][0];
        cin >> range[i][1];
    }
    map<ll, vector<ll>> mmp;
    map<ll, vector<ll>> adj;
    for (ll i = 0; i < n - 1; i++)
    {
        ll f, s;
        cin >> f >> s;
        mmp[f].push_back(s);
        mmp[s].push_back(f);
    }
    vector<ll> parent(n + 1, 0);
    parent[1] = 1;
    vector<bool> visit(n + 1, false);
    id2(1, mmp, visit, parent);
    for (ll i = 2; i <= n; i++)
    {
        adj[parent[i]].push_back(i);
    }
    vector<vector<ll>> dp(n + 1, vector<ll>(2, 0));

    ll ans = id3;
    debug(mmp);
    debug(adj);
    debug(parent);
    

    dfs(1, adj, dp, parent, range);

    debug(dp);

    cout << max(dp[1][0], dp[1][1]) << "\n";
}
int main()
{

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("Error.txt", "w", stderr);

    fastio();
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}