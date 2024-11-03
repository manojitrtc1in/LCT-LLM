
































using namespace std;

void swap(int &x, int &y)
{
    int temp = x;
    x = y;
    y = temp;
}





bool funCycle(vector<ll> &vis, vector<ll> &viss, vector<ll> adj[], ll i, ll n)
{
    for (auto x : adj[i])
    {
        if (viss[x])
            return 1;
        if (!vis[x])
        {
            viss[x] = 1;
            vis[x] = 1;
            bool t = funCycle(vis, viss, adj, x, n);
            if (t)
                return 1;
            viss[x] = 0;
        }
    }
    return 0;
}
bool id1(vector<ll> adj[], ll n)
{
    vector<ll> vis(n + 1, 0);
    vector<ll> viss(n + 1, 0);
    for (ll i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            vis[i] = 1;
            viss[i] = 1;
            if (funCycle(vis, viss, adj, i, n))
                return 1;
            viss[i] = 0;
        }
    }
    return 0;
}








void id3(vector<ll> &dp, vector<ll> adj[], ll i, ll n)
{
    if (adj[i].size() == 0)
    {
        dp[i] = 1;
        return;
    }
    for (auto x : adj[i])
    {
        if (dp[x] == 0)
            id3(dp, adj, x, n);
        dp[i] = max(dp[i], dp[x] + 1);
    }
}
ll id0(vector<ll> adj[], ll n)
{
    vector<ll> dp(n + 1, 0);
    ll ans = 0;
    for (ll i = 1; i <= n; i++)
    {
        if (dp[i] == 0)
        {
            id3(dp, adj, i, n);
            ans = max(ans, dp[i]);
        }
    }
    return ans;
}






vector<ll> buildTopo(vector<ll> adj[], ll n, vector<ll> indegree)
{
    vector<ll> topo;
    queue<ll> q;
    for (ll i = 1; i <= n; i++)
    {
        if (indegree[i] == 0)
            q.push(i);
    }
    while (!q.empty())
    {
        ll i = q.front();
        q.pop();
        topo.push_back(i);
        for (auto x : adj[i])
        {
            indegree[x]--;
            if (indegree[x] == 0)
                q.push(x);
        }
    }
    return topo;
}


int XOR(int n)
{
    if (n % 4 == 0)
        return n;
    if (n % 4 == 1)
        return 1;
    if (n % 4 == 2)
        return n + 1;
    return 0;
}



int isPrime(int N)
{
    if (N < 2 || (!(N & 1) && N != 2))
        return 0;
    for (int i = 3; i * i <= N; i += 2)
    {
        if (!(N % i))
            return 0;
    }
    return 1;
}



void id4(vector<int> &prime, int high)
{
    bool ck[high + 1];
    memset(ck, true, sizeof(ck));
    ck[1] = false;
    ck[0] = false;
    for (int i = 2; (i * i) <= high; i++)
    {
        if (ck[i] == true)
        {
            for (int j = i * i; j <= high; j = j + i)
            {
                ck[j] = false;
            }
        }
    }
    for (int i = 2; i * i <= high; i++)
    {
        if (ck[i] == true)
        {
            prime.push_back(i);
        }
    }
}

vector<bool> id2(int low, int high)
{
    vector<bool> prime(high - low + 1, true);
    vector<int> chprime;
    id4(chprime, high);
    for (int i : chprime)
    {
        int lower = (low / i);
        if (lower <= 1)
        {
            lower = i + i;
        }
        else if (low % i)
        {
            lower = (lower * i) + i;
        }
        else
        {
            lower = (lower * i);
        }
        for (int j = lower; j <= high; j = j + i)
        {
            prime[j - low] = false;
        }
    }
    return prime;
}



const double eps = 1e-7;
const ll N = 5e5 + 7, mod = 1e9 + 7;
ll POW(ll a, ll b, ll mod)
{
    a %= mod;
    ll r = 1;
    for (ll i = b; i > 0; i >>= 1)
    {
        if (i & 1)
            r = (r * a) % mod;
        a = (a * a) % mod;
    }
    return r;
}



ll f[N];
void init()
{
    f[0] = 1;
    for (ll i = 1; i < N; i++)
    {
        f[i] = (f[i - 1] * i) % mod;
    }
}
ll nCr(ll n, ll r)
{
    if (n < r)
        return 0;
    return f[n] * POW(f[n - r] * f[r], mod - 2, mod) % mod;
}
ll nPr(ll n, ll r)
{
    return nCr(n, r) * f[r] % mod;
}



vector<ll> getFactors(ll n)
{
    vector<ll> v;
    for (ll i = 1; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            if (n / i == i)
                v.push_back(i);
            else
            {
                v.push_back(i);
                v.push_back(n / i);
            }
        }
    }
    return v;
}



ll p = 1e9 + 7;
ll modadd(ll a, ll b)
{
    a = a % p;
    b = b % p;
    return (((a + b) % p) + p) % p;
}
ll modmul(ll a, ll b)
{
    a = a % p;
    b = b % p;
    return (((a * b) % p) + p) % p;
}
ll modsub(ll a, ll b)
{
    a = a % p;
    b = b % p;
    return (((a - b) % p) + p) % p;
}


typedef unsigned long long ull;
typedef long double lld;

    cout << 
    _print(x);         \
    cout << endl;
void _print(ll t)
{
    cout << t;
}
void _print(int t) { cout << t; }
void _print(string t) { cout << t; }
void _print(char t) { cout << t; }
void _print(lld t) { cout << t; }
void _print(double t) { cout << t; }
void _print(ull t) { cout << t; }
template <class T, class V>
void _print(pair<T, V> p);
template <class T>
void _print(vector<T> v);
template <class T>
void _print(set<T> v);
template <class T, class V>
void _print(map<T, V> v);
template <class T>
void _print(multiset<T> v);
template <class T, class V>
void _print(pair<T, V> p)
{
    cout << '{';
    _print(p.ff);
    cout << ',';
    _print(p.ss);
    cout << '}';
}
template <class T>
void _print(vector<T> v)
{
    cout << '[' << ' ';
    for (T i : v)
    {
        _print(i);
        cout << ' ';
    }
    cout << ']';
}
template <class T>
void _print(set<T> v)
{
    cout << '[' << ' ';
    for (T i : v)
    {
        _print(i);
        cout << ' ';
    }
    cout << ']';
}
template <class T>
void _print(multiset<T> v)
{
    cout << '[' << ' ';
    for (T i : v)
    {
        _print(i);
        cout << ' ';
    }
    cout << ']';
}
template <class T, class V>
void _print(map<T, V> v)
{
    cout << '[' << ' ';
    for (auto i : v)
    {
        _print(i);
        cout << ' ';
    }
    cout << ']';
}









using namespace __gnu_pbds;










int bit[200006];

void update(int i, int x)
{
    for (; i < 200005; i += (i & -i))
        bit[i] += x;
}

int sum(int i)
{
    int ans = 0;
    for (; i > 0; i -= (i & -i))
        ans += bit[i];
    return ans;
}





void solve()
{
    long long int n, count = 0;
    cin >> n;
    long long int a[n];
    for (long long int i = 1; i <= n; i++)
        cin >> a[i];
    long long int b[n];
    for (long long int i = 1; i <= n; i++)
        cin >> b[i];
    vector<pair<long long int, long long int>> umap;
    for (long long int i = 1; i <= n; i++)
        for (long long int j = 1; j < n; j++)
            if (a[j] > a[j + 1] || b[j] > b[j + 1])
            {
                swap(a[j], a[j + 1]);
                swap(b[j], b[j + 1]);
                umap.push_back({j, j + 1});
            }
    for (long long int i = 1; i < n; i++)
        if (a[i] > a[i + 1] || b[i] > b[i + 1])
        {
            cout << -1 << endl;
            return;
        }
    cout << umap.size() << endl;
    for (auto x : umap)
        cout << x.first << " " << x.second << endl;
    return;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
