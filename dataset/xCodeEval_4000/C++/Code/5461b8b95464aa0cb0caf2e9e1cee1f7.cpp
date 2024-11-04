

#include <bits/stdc++.h>

using namespace std;
#define endl "\n"
#define sp ' '
#define fast                 \
    ios::sync_with_stdio(0); \
    cin.tie(0);
#define ll long long
#define ll1 unsigned long long
#define ld long double
#define pb push_back
#define ifc(b, s1, otherwise) (b) ? cout << s1 << endl : cout << otherwise << endl
#define fs(n) fixed << setprecision(n)
#define asort(a) sort(a, a + n)
#define vi vector<int>
#define vld vector<ld>
#define vd vector<double>
#define qu queue<int>
#define de deque<int>
#define pqi priority_queue<int>
#define pql priority_queue<long long>
#define dl deque<long long>
#define ql queue<long long>
#define vl vector<long long>
#define vc vector<char>
#define inf 0x3f3f3f3f
#define allr(x) (x).rbegin(), (x).rend()
#define all(x) (x).begin(), (x).end()
#define dsort(a) sort(a, a + n, greater<int>())
#define cin_set(s)                                      \
    for (int i = 0, entry; i < n and cin >> entry; i++) \
        s.emplace(entry);
#define cout_set(s)   \
    for (auto &i : s) \
        cout << i << " ";
#define cin_deque(d)  \
    for (auto &i : d) \
        cin >> i;
#define cout_deque(d)     \
    for (auto &i : d)     \
        cout << i << " "; \
    cout << '\n';
#define cout_map(mp)        \
    for (auto &[f, s] : mp) \
        cout << f << "  " << s << "\n";
#define cout_stack(s)           \
    while (!s.empty())          \
    {                           \
        cout << s.top() << " "; \
        s.pop();                \
    }                           \
    cout << '\n';
#define clr(v, d) memset(v, d, sizeof(v))
#define F first
#define S second
#define tc    \
    int t;    \
    cin >> t; \
    while (t--)
#define sy cout << "YES\n";
#define sm cout << "-1\n";
#define sn cout << "NO\n";
#define so cout << "0\n";

#define Time cerr << "Time Taken: " << (float)clock() / CLOCKS_PER_SEC << " secs\n";
#define sum_N(n) (n * (n + 1) / 2)
#define sumL_R(L, R) (R * (R + 1) / 2) - ((L - 1) * ((L - 1) + 1) / 2)
#define sz(v) ((int)((v).size()))
#define rep1(i, m, n) for (int i = m; i <= n; i++)
#define CC(x) cout << (x) << endl
#define fr(i, x, y) for (ll i = (ll)x; i < (ll)y; ++i)
#define fr1(i, x, y) for (ll i = (ll)x; i <= (ll)y; ++i)
#define fra(x) for (auto &i : x)
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


bool isPowerOfTwo(int n)
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
