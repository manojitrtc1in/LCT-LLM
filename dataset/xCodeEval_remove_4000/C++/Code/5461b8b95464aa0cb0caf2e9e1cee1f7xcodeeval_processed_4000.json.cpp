



using namespace std;



    ios::sync_with_stdio(0); \
    cin.tie(0);























    for (int i = 0, entry; i < n and cin >> entry; i++) \
        s.emplace(entry);

    for (auto &i : s) \
        cout << i << " ";

    for (auto &i : d) \
        cin >> i;

    for (auto &i : d)     \
        cout << i << " "; \
    cout << '\n';

    for (auto &[f, s] : mp) \
        cout << f << "  " << s << "\n";

    while (!s.empty())          \
    {                           \
        cout << s.top() << " "; \
        s.pop();                \
    }                           \
    cout << '\n';




    int t;    \
    cin >> t; \
    while (t--)














typedef pair<ll, ll> pll;
typedef vector<ll> vll;
typedef vector<string> vs;
typedef unordered_map<ll, ll> umll;
typedef map<ll, ll> mll;
typedef pair<string, string> pairs;
typedef pair<ll, ll> pii;
template <typename T>
istream &operator>>(istream &in, vector<T> &a)
{
    for (auto &x : a)
        in >> x;
    return in;
};
template <typename T>
ostream &operator<<(ostream &out, vector<T> &a)
{
    for (auto &x : a)
        out << x << ' ';
    return out;
};
template <typename T>
void Unique(T &a) { a.erase(unique(a.begin(), a.end()), a.end()); }


ll gcd(ll a, ll b)
{
    if (a == 0)
        return b;
    gcd(b % a, a);
    return 0;
}


ll lcm(ll a, ll b)
{
    return (a * b) / gcd(a, b);
}







using namespace std;

bool isPrime(ll n)
{
    if (n == 2)
    {
        return true;
    }
    if (n < 2 || n % 2 == 0)
    {
        return false;
    }
    for (ll i = 3; i * i <= n; i += 2)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}


vector<bool> primes((1e6 + 1), true);
void sieven(int n)
{
    primes[0] = primes[1] = false;
    for (ll i = 2; i <= n + 1; i++)
    {
        if (primes[i])
        {
            for (ll j = i * i; j <= n + 1; j += i)
                primes[j] = false;
        }
    }
}

int mod = 1e9 + 7;


long long fastPower(long long a, long long b, long long m)
{
    a %= m;
    long long res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}


long long fastPower(long long a, long long b)
{
    long long res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}


bool id0(int n)
{
    return (ceil(log2(n)) == floor(log2(n)));
}



const int N = 1e5 + 1;
ll dv(ll x)
{
    ll c = 0;
    for (ll j = 1; j * j <= x; j++)
    {
        if (x % j == 0)
        {
            c++;
            if (j != (x / j))
                c++;
        }
    }
    return c;
}


vector<bool> vis(500005, 0);
vector<ll> adj[500005];
ll ans[1000006];

void bfs(ll node)
{
    vector<ll> group;
    queue<int> q;
    q.push(node);
    vis[node] = 1;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        group.pb(node);
        for (auto it : adj[node])
        {
            if (!vis[it])
            {
                q.push(it);
                vis[it] = 1;
            }
        }
    }
}





void solve()
{
    int n, m;
    cin >> n >> m;
    vi cur(n + 1, 0);
    int c = n, u, v;
    fr(i, 0, m)
    {
        cin >> u >> v;
        if (u < v)
        {
            swap(u, v);
        }
        if (!cur[v])
            c--;
        cur[v]++;
    }
    int q;
    cin >> q;
    fr(i, 0, q)
    {
        int x;
        cin >> x;
        if (x == 3)
        {
            cout << c << endl;
            continue;
        }
        cin >> u >> v;
        if (x == 1)
        {
            if (u < v)
            {
                swap(u, v);
            }
            if (!cur[v])
                c--;
            cur[v]++;
        }
        else
        {
            if (u < v)
            {
                swap(u, v);
            }
            cur[v]--;
            if (!cur[v])
                c++;
        }
    }
}
int main()
{
    fast

    solve();
    return 0;
}
