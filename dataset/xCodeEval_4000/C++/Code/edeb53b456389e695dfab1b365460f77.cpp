

#include <bits/stdc++.h>

using namespace std;
#define edl "\n"
#define fast                 \
    ios::sync_with_stdio(0); \
    cin.tie(0);
#define ll long long
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
#define sz(x) (int)(x).size()
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
#define rep(i, v) for (int i = 0; i < sz(v); ++i)
#define lp(i, n) for (int i = 0; i < (int)(n); ++i)
#define lpi(i, j, n) for (int i = (j); i < (int)(n); ++i)
#define lpd(i, j, n) for (int i = (j); i >= (int)(n); --i)
#define F first
#define S second
#define tc    \
    int t;    \
    cin >> t; \
    while (t--)
#define py cout << "YES\n";
#define pm cout << "-1\n";
#define pn cout << "NO\n";
#define po cout << "0\n";
#define cin_1d(v)     \
    for (auto &i : v) \
        cin >> i;
#define cout_1d(v) for (auto &i : v)  cout << i << " ";
#define cin_2d(v)         \
    for (auto &i : v)     \
        for (auto &j : i) \
            cin >> j;
#define cout_2d(v)           \
    for (auto &i : v)        \
    {                        \
        for (auto &j : i)    \
        {                    \
            cout << j << sp; \
        }                    \
        cnl;                 \
    }
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





int dirx[] = {-1, 0, 1, 0};
int diry[] = {0, 1, 0, -1};
vector<int> dx = {1, 1, -1, -1};
vector<int> dy = {1, -1, 1, -1};


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

vector<tuple<int, int, int>> edges;


vector<vector<int>> adj;
vector<bool> visited;
vector<int> topsort;
vector<int> start, finish;
bool anyCycle = 0;
int timer = 0;










































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
bool compare(ll x, ll y){
    return x%2 < y%2;
}
void solve()
{
    ll n;
    cin >> n;
    vi v(n);
    fr(i, 0, n)
    {
        cin >> v[i];
    }
    int c = 0;
    sort(all(v),compare);
    fr(i, 0, n)
    {
        fr(j, i + 1, n)
        {
            if (__gcd(v[i], (v[j] * 2)) > 1)
            {
                

                c++;
            }
        }
    }
    cout<<c<<endl;
   

}

int main()
{
    fast

   tc solve();
    return 0;
}