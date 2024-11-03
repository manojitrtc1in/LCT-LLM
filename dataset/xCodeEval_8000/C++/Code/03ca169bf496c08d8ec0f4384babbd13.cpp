

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
#define ff first
#define ss second
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


long long gcd(long long int a, long long int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}


long long lcm(long long a, long long b)
{
    if (a > b)
        return (a / gcd(a, b)) * b;
    else
        return (b / gcd(a, b)) * a;
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

ll KadaneMaxSum(vector<ll> &arr)
{
    ll globalSum = arr[0];
    ll curSum = arr[0];
    int n = arr.size();
    for (int i = 1; i < n; i++)
    {
        curSum = max(arr[i], curSum + arr[i]);
        globalSum = max(globalSum, curSum);
    }
    return globalSum;
}


ll KadaneMinSum(vector<ll> &arr)
{
    ll globalSum = arr[0];
    ll curSum = arr[0];
    int n = arr.size();
    for (int i = 1; i < n; i++)
    {
        curSum = min(arr[i], curSum + arr[i]);
        globalSum = min(globalSum, curSum);
    }
    return globalSum;
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



vl p;
void dv(ll x)
{
    for (ll j = 2; (j * j) <= x; j++)
    {
        if (x % j == 0)
        {
            p.pb(j);
            if (j != (x / j))
                p.pb(x / j);
        }
    }
}


void pf(int n)
{
    while (n % 2 == 0)
    {
        p.pb(2);
        n = n / 2;
    }
    for (int i = 3; i <= sqrt(n); i = i + 2)
    {
        while (n % i == 0)
        {
            p.pb(i);
            n = n / i;
        }
    }
    if (n > 2)
        p.pb(n);
}
const double PI = 3.14159265359, EPS = 1e-9;
const int M = 202, Mod = 1000000007, OO = 1000000000;

const int N = 1e2 + 5;
bool vis[N];














void solve()
{
    int n;
    cin >> n;
    int c = 0;
    vi v(n), ans(n);
    cin >> v;
    ans = v;
    sort(all(ans));
    if (ans == v)
    {
        cout << 0 << endl;
        return;
    }
    else
    {
        if (v[0] == ans[0] || v[n - 1] == ans[n - 1])
        {
            cout << 1 << endl;
        }
        else if (ans[n - 1] == v[0] && ans[0] == v[n - 1])
        {
            cout << 3 << endl;
            return;
        }
        else
        {
            cout << 2 << endl;
        }
    }
}

int main()
{
    fast
        tc
        solve();
}
