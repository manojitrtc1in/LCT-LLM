



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

    for (auto &i : v) \
        cout << i << " ";

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

template <typename T1, typename T2>


istream &operator>>(istream &istream, pair<T1, T2> &p)
{
    return (istream >> p.first >> p.second);
}

template <typename T>


istream &operator>>(istream &istream, vector<T> &v)
{
    for (auto &it : v)
        cin >> it;
    return istream;
}

template <typename T1, typename T2>


ostream &operator<<(ostream &ostream, const pair<T1, T2> &p)
{
    return (ostream << p.first << " " << p.second);
}

template <typename T>


ostream &operator<<(ostream &ostream, const vector<T> &c)
{
    for (auto &it : c)
        cout << it << " ";
    return ostream;
}



long long gcd(long long a, long long b)
{
    if (min(a, b) == 0)
        return max(a, b);
    else
        return gcd(b, a % b);
}

long long lcm(long long a, long long b)
{
    return a / gcd(a, b) * b;
}





int dirx[] = {-1, 0, 1, 0};
int diry[] = {0, 1, 0, -1};
vector<int> dx = {1, 1, -1, -1};
vector<int> dy = {1, -1, 1, -1};


ll id1(vector<ll> &arr)
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


ll id2(vector<ll> &arr)
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



bool id0(ll n)
{
    return (ceil(log2(n)) == floor(log2(n)));
}

































































































































































void solve()
{
    ll n, k, x;
    cin >> n >> k >> x;
    vl v(n);
    vl req;
    fr(i, 0, n)
    {
        cin >> v[i];
    }
    sort(all(v));
    ll ans = n;
    for (int i = 0; i < n - 1; i++)
    {
     ll d = v[i+1]-v[i];
     if(d<=x){
        ans--;
     }
     else {
        req.pb((d-1)/x);
     }
    }
    sort(all(req));
    for(ll it : req){
    if(k>=it){
        k-=it;
        ans--;
    }
}
    cout<<ans<<endl;
}
int main()
{
    fast
    solve();
    return 0;
}


