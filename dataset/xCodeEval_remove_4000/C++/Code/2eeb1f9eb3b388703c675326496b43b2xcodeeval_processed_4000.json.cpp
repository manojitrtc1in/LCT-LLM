















using namespace std;












    for (ll i = szz; i <= ezz; i++)                                                                                    \
    {                                                                                                                  \
        cout << azz[i] << " ";                                                                                         \
    }

    for (ll i = szz; i >= ezz; i--)                                                                                    \
    {                                                                                                                  \
        cout << azz[i] << " ";                                                                                         \
    }



































const ll mod = 1e9 + 7;


const ll maxn = 1e6 + 1;
const ll llmax = (1ll << 60);
const int intmax = (1 << 30);
const ldb PI = 3.14159265358979323846264338327950288419716939937510582097494459230781640628620899863;
vll fact, ifact;
vll primes;
vll spf;
void sieve()
{
    spf.resize(maxn + 1, 0);
    spf[0] = 0;
    spf[1] = 1;
    for (ll i = 2; i <= maxn; i++)
    {
        if (spf[i])
            continue;
        spf[i] = i;
        for (ll j = i * i; j <= maxn; j += i)
        {
            if (spf[j] == 0)
                spf[j] = i;
        }
    }
    for (ll p = 2; p <= maxn; p++)
        if (spf[p] == p)
            primes.pb(p);
}
vll id7;
void id10(ll l, ll r)
{
    vb isprime(r - l + 1, 1);

    if (l == 1)
        isprime[0] = false;
    ll base;
    for (ll i = 0; primes[i] * primes[i] <= r; i++)
    {
        base = (l / primes[i]) * primes[i];
        if (base < l)
        {
            base += primes[i];
        }
        for (long long j = base; j <= r; j += primes[i])
        {
            isprime[j - l] = false;
        }
        if (base == primes[i])
        {
            isprime[base - l] = true;
        }
    }
    for (int i = 0; i < r - l + 1; i++)
    {
        if (isprime[i])
            id7.pb(i + l);
    }
}
void id2(ll x, mll &mp)
{
    for (ll i = 0; primes[i] * primes[i] <= x; i++)
    {
        while (x % primes[i] == 0)
        {
            mp[primes[i]]++;
            x /= primes[i];
        }
    }
    if (x != 1)
    {
        mp[x]++;
    }
}
void primefactor(ll n, mll &mp)
{
    while (n != 1)
    {
        mp[spf[n]]++;
        n /= spf[n];
    }
}

bool id5(ll n)
{
    for (ll i = 0; primes[i] * primes[i] <= n; i++)
    {
        if (n % primes[i] == 0)
        {
            return false;
        }
    }
    return true;
}

void id1(vll &v, ll n)
{
    for (ll i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            v.pb(i);
            if (i * i != n)
            {
                v.pb(n / i);
            }
        }
    }
    sort(v.begin(), v.end());
}

ll power(ll a, ll n)
{
    ll res = 1;
    while (n)
    {
        if (n % 2)
        {
            res = (res * a);
            if (res >= mod)
                res %= mod;
        }
        a = (a * a);
        if (a >= mod)
            a %= mod;
        n /= 2;
    }
    if (res >= mod)
        res %= mod;
    return res;
}

ll modInv(ll a)
{
    ll res = power(a, mod - 2);
    if (res >= mod)
        res %= mod;
    return res;
}

void modFact()
{
    ll n = maxn;
    ifact.resize(n + 1);
    fact.resize(n + 1);
    fact[0] = fact[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        fact[i] = (i * fact[i - 1]);
        if (fact[i] >= mod)
        {
            fact[i] %= mod;
        }
    }
    ifact[n] = modInv(fact[n]);
    for (int i = n - 1; i >= 0; i--)
    {
        ifact[i] = ((i + 1) * ifact[i + 1]);
        if (ifact[i] >= mod)
        {
            ifact[i] %= mod;
        }
    }
}

ll ncr(ll n, ll r)
{
    if (n < r || r < 0)
        return 0;
    ll ans = fact[n];
    ans *= ifact[r];
    if (ans >= mod)
        ans %= mod;
    ans *= ifact[n - r];
    if (ans >= mod)
        ans %= mod;
    return ans;
}

ll npr(ll n, ll r)
{
    if (n < r || r < 0)
        return 0;
    ll ans = fact[n];
    ans *= ifact[n - r];
    if (ans >= mod)
        ans %= mod;
    return ans;
}

ll lcm(ll a, ll b)
{
    ll x = __gcd(a, b);
    a /= x;
    b /= x;
    ll sum = a * b * x;
    return sum;
}

bool id6(string str, ll l, ll r)
{
    while (l <= r)
    {
        if (str[l] != str[r])
            return false;
        l++;
        r--;
    }
    return true;
}

ll id4(ll n)
{
    ll ans = 0;
    while (n)
    {
        ans = (ans * 10) + n % 10;
        n /= 10;
    }
    return ans;
}

void fraction(string &str, ll &num, ll &den)
{
    ll n = str.length();
    ll id3 = 0;
    bool dot_seen = false;

    for (ll i = 0; i < n; i++)
    {
        if (str[i] != '.')
        {
            num = num * 10 + (str[i] - '0');
            if (dot_seen == true)
                id3++;
        }
        else
            dot_seen = true;
    }
    if (dot_seen == false)
    {
        den = 1;
        return;
    }
    ll dem = (ll)pow(10, id3);
    ll g = __gcd(num, dem);
    num = num / g;
    den = dem / g;
    return;
}

string id11(ll a, int bit)
{
    string s;
    while (a > 0)
    {
        s += (a % 2) + 48;
        a /= 2;
    }
    while (S(s) < bit)
        s += '0';
    reverse(s.begin(), s.end());
    return s;
}

ll id8(string &num)
{
    

    ll dec_value = 0;
    ll base = 1;
    ll len = num.length();
    for (ll i = len - 1; i >= 0; i--)
    {
        if (num[i] == '1')
            dec_value += base;
        base = base * 2;
    }
    return dec_value;
}

ll id0(string str)
{
    return stoll(str, nullptr, 10);
}

string id9(ll n)
{
    if (n == 0)
        return "0";
    else if (n == 1)
        return "1";
    else if (n % 2 == 0)
        return id9(n / 2) + "0";
    else
        return id9(n / 2) + "1";
}



ll countbit(ll n)
{
    return (ll)log2(n) + 1;
}

ll setbit(ll n, ll k)
{
    return (n | (1 << (k - 1))); 

}

ll clearbit(ll n, ll k)
{
    return (n & (~(1 << (k - 1))));
}

ll togglebit(ll n, ll k)
{
    return (n ^ (1 << (k - 1)));
}

ll findpivot(vll &arr, ll low, ll high)
{
    while (low < high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] == arr[high])
            high--;
        else if (arr[mid] > arr[high])
            low = mid + 1;
        else
            high = mid;
    }
    return high;
}

void cbr()
{
    ll x1 = 0, y1 = 0, x2 = 0, y2 = 0;
    ll x = 0, y = 0;
    ll w = 0, h = 0;
    double w1 = x1 - 0;
    double w2 = x - x2;
    double h1 = y1 - 0;
    double h2 = y - y2;
    if (w1 >= w || w2 >= w || h1 >= h || h2 >= h)
    {
        x1 = 0;
    }
    else if (w1 + w2 >= w && h1 + h2 >= h)
    {
        double ans1 = min(w - w1, w - w2);
        double ans2 = min(h - h1, h - h2);
        double ans = min(ans1, ans2);
    }
    else if (w1 + w2 >= w)
    {
        double ans = min(w - w1, w - w2);
    }
    else if (h1 + h2 >= h)
    {
        double ans = min(h - h1, h - h2);
    }
    if (w1 >= w || w2 >= w || h1 >= h || h2 >= h)
    {
        x1 = 0;
    }
    else if (w1 + w2 >= w && h1 + h2 >= h)
    {
        double ans1 = min(w - w1, w - w2);
        double ans2 = min(h - h1, h - h2);
        double ans = min(ans1, ans2);
    }
    else if (w1 + w2 >= w)
    {
        double ans = min(w - w1, w - w2);
    }
    else if (h1 + h2 >= h)
    {
        double ans = min(h - h1, h - h2);
    }
    if (w1 >= w || w2 >= w || h1 >= h || h2 >= h)
    {
        x1 = 0;
    }
    else if (w1 + w2 >= w && h1 + h2 >= h)
    {
        double ans1 = min(w - w1, w - w2);
        double ans2 = min(h - h1, h - h2);
        double ans = min(ans1, ans2);
    }
    else if (w1 + w2 >= w)
    {
        double ans = min(w - w1, w - w2);
    }
    else if (h1 + h2 >= h)
    {
        double ans = min(h - h1, h - h2);
    }
    if (w1 >= w || w2 >= w || h1 >= h || h2 >= h)
    {
        x1 = 0;
    }
    else if (w1 + w2 >= w && h1 + h2 >= h)
    {
        double ans1 = min(w - w1, w - w2);
        double ans2 = min(h - h1, h - h2);
        double ans = min(ans1, ans2);
    }
    else if (w1 + w2 >= w)
    {
        double ans = min(w - w1, w - w2);
    }
    else if (h1 + h2 >= h)
    {
        double ans = min(h - h1, h - h2);
    }
}











































class BIT
{
  public:
    vll bit;
    vll vis;
    ll si;
    ll count;

    BIT(ll n)
    {
        si = n + 1;
        si = pow(2, ((ll)log2(si) + 1));
        bit.assign(si + 1, 0);
        vis.assign(si + 1, 0);
        count = 0;
    }

    void update(ll idx, ll inc)
    {
        

        

        

        

        

        

        

        

        count += inc;
        vis[idx] += inc;
        

        while (idx <= si)
        {
            

            bit[idx] += inc;
            idx += (idx & (-idx));
        }
    }
    

    ll query(ll k)
    {
        if (k > count || k <= 0)
        {
            return -1;
        }
        

        

        ll l = 0, r = si / 2;
        

        ll ans = 0;
        while (r)
        {
            

            if (bit[l + r] == k)
            {
                ans = l + r;
            }
            if (bit[l + r] >= k)
            {
                r /= 2;
            }
            else if (bit[l + r] < k)
            {
                k -= bit[l + r];
                l += r;
                r /= 2;
            }
        }
        return ans;
    }
    

    ll sum(ll idx)
    {
        ll x = 0;
        while (idx > 0)
        {
            

            x += bit[idx];
            idx -= (idx & (-idx));
        }
        return x;
    }
};

void fun(ll countu)
{
    ll n, m;
    cin >> n >> m;
    ll a[m];
    BIT o(m + 5);
    ll ans = 0;
    vll x;
    sfor(i, 0, m - 1)
    {
        cin >> a[i];
        x.pb(a[i]);
    }
    sort(all(x));
    mll mp;
    ll id = 1;
    sfor(i, 0, m - 1)
    {
        mp[x[i]] = id;
        id++;
    }
    sfor(i, 0, m - 1)
    {
        

        

        ans += o.sum(mp[a[i]] - 1);
        o.update(mp[a[i]], 1);
    }
    cout << ans << bl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    srand(time(0));
    

    

    ll t = 1;
    cin >> t;
    sfor(i, 1, t) fun(i);

    return 0;
}
