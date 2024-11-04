



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





    for (auto &i : v) \
        cin >> i;


    for (auto &i : v)     \
        for (auto &j : i) \
            cin >> j;

    for (auto &i : v)        \
    {                        \
        for (auto &j : i)    \
        {                    \
            cout << j << sp; \
        }                    \
        cnl;                 \
    }









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

bool id0(int n)
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
