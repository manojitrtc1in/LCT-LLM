




























































































































































































































































































































































































































































































































































































































































































































































































































































    for (auto i : A)      \
        cout << i << " "; \
    cout << '\n';


clock_t startTime = clock();









using namespace std;

typedef vector<vector<long long>> vvint;

void fast()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    

    

    

    

    

}
double PI = 4 * atan(1);
int mod = 1e9 + 7, mxn = 3e5 + 5;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
void deb(vector<int> v)
{
    for (auto t : v)
        cerr << t << " ";
    cerr << "\n";
}
int mul(int a, int b, int mod)
{
    a %= mod;
    b %= mod;
    a *= b;
    a += mod;
    return a % mod;
}

bool id0(const pair<int, int> &a,
                   const pair<int, int> &b)
{
    return a.second > b.second;
}
string id3(int n)
{
    string s = "";
    int i = 0;
    while (n > 0)
    {
        s = to_string(n % 2) + s;
        n = n / 2;
        i++;
    }
    return s;
}
vint fact(2e5 + 5, 1);
int binPow(int a, int b)
{
    if (b == 0)
        return 1;
    if (b == 1)
        return a;
    int ret = binPow(a, b / 2);
    if (b % 2 == 0)
        return (ret * ret) % mod;
    return ((ret * ret) % mod * a) % mod;
}
int inv(int a)
{
    return (binPow(a, mod - 2) % mod + mod) % mod;
}
int binom(int a, int b)
{
    

    

    if (b < 0 or a < 0)
        return 0;
    return (((fact[a] * inv(fact[b])) % mod * inv(fact[a - b])) % mod + mod) % mod;
}




vector<int> id2(int N)
{
    bool primes[N + 1];
    memset(primes, true, sizeof(primes));
    vector<int> arr;

    for (int i = 2; i * i <= N; i++)
        if (primes[i] == true)
        {
            for (int j = i * i; j <= N; j += i)
                primes[j] = false;
        }

    for (int i = 2; i <= N; i++)
        if (primes[i])
            arr.emplace_back(i);

    return arr;
}
vector<int> primeFactors(int n)
{
    vector<int> f;
    for (int x = 2; x * x <= n; x++)
    {
        while (n % x == 0)
        {
            f.push_back(x);
            n /= x;
        }
    }
    if (n > 1)
        f.push_back(n);
    return f;
}

bool isPrime(int n)
{
    if (n < 2)
        return false;
    for (int x = 2; x * x <= n; x++)
    {
        if (n % x == 0)
            return false;
    }
    return true;
}

bool id1(int n)
{
    return n && (!(n & (n - 1)));
}






























vll v;

class segTree
{
public:
    vll a, seg;
    segTree(ll n)
    {
        

        

        a.resize(n + 2, 0);
        seg.resize(4 * n + 14, 0);
        

    }

    void build(ll si, ll ss, ll se)
    {
        if (ss == se)
        {
            seg[si] = a[ss];
            return;
        }
        ll mid = (ss + se) / 2;

        build(2 * si, ss, mid);
        build(2 * si + 1, mid + 1, se);

        seg[si] = (seg[2 * si] + seg[2 * si + 1]);
    }

    void update(ll si, ll ss, ll se, ll qi, ll val)
    {
        if (qi < ss || qi > se)
        {
            return;
        }
        if (ss == se)
        {
            seg[si] = val;
            a[ss] = val;
            return;
        }
        int mid = (ss + se) / 2;

        

        update(2 * si, ss, mid, qi, val);
        

        update(2 * si + 1, mid + 1, se, qi, val);

        seg[si] = (seg[2 * si] + seg[2 * si + 1]);
        return;
    }
    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    


    

    

    

    

    

    ll query(ll si, ll ss, ll se, ll l, ll r)
    {
        

        

        

        

        

        

        

        

        

        

        if (ss > r || se < l)
        {
            return 0;
        }
        if (ss >= l && se <= r)
        {
            return seg[si];
        }

        

        ll mid = (ss + se) / 2;
        return (query(2 * si, ss, mid, l, r) +
                query(2 * si + 1, mid + 1, se, l, r));
    }
};































































































































void solve()
{
    ll n, q;
    cin >> n >> q;
    v.resize(n + 2, 0);
    segTree row(n);
    segTree col(n);
    vll rows, cols;
    rows.assign(n + 1, 0);
    cols.assign(n + 1, 0);
    for (ll i = 0; i < q; i++)
    {
        ll x;
        cin >> x;

        if (x == 1)
        {
            ll i, j;
            cin >> i >> j;
            v[i] = j;
            rows[i]++;
            cols[j]++;
            if (rows[i])
                row.update(1, 1, n, i, 1);
            if (cols[j])
                col.update(1, 1, n, j, 1);
            continue;
        }
        if (x == 2)
        {
            ll i, j;
            cin >> i >> j;
            rows[i]--;
            cols[j]--;
            if (rows[i] == 0)
                row.update(1, 1, n, i, 0);
            if (cols[j] == 0)
                col.update(1, 1, n, j, 0);
            

            continue;
        }
        if (x == 3)
        {
            

            


            

            

            

            

            

            

            

            

            

            

            

            ll x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;
            

            

            

            

            ll a = row.query(1, 1, n, x1, x2), b = col.query(1, 1, n, y1, y2);
            

            

            if (a == (x2 - x1 + 1) || b == (y2 - y1 + 1))
            {
                cout << "Yes\n";
            }
            else
                cout << "No\n";
        }
    }
}
signed main()
{
    fast();
    

    int t = 1;
    

    while (t--)
    {
        v.clear();
        solve();
    }
    


    


    

    return 0;
}