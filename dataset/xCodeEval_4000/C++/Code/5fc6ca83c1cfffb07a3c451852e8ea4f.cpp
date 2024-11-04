


























#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;






#define fin cin.ignore(numeric_limits<streamsize>::max(), '\n')
#define fout cout.flush()
#define fill(w, t) memset(w, t, sizeof(w))
#define google cout << "Case #" << countu << ": "
#define S(t) (ll) t.size()
#define bl '\n'
#define nl cout << bl
#define cout1(a) cout << a << bl
#define cout2(a, b) cout << a << " " << b << bl
#define cout3(a, b, c) cout << a << " " << b << " " << c << bl
#define cout4(a, b, c, d) cout << a << " " << b << " " << c << " " << d << bl
#define print(azz, szz, ezz)                                                                                           \
    for (ll i = szz; i <= ezz; i++)                                                                                    \
    {                                                                                                                  \
        cout << azz[i] << " ";                                                                                         \
    }
#define rprint(azz, szz, ezz)                                                                                          \
    for (ll i = szz; i >= ezz; i--)                                                                                    \
    {                                                                                                                  \
        cout << azz[i] << " ";                                                                                         \
    }
#define input(azz, szz, ezz) sfor(pzz, szz, ezz) cin >> azz[pzz]
#define all(v) v.begin(), v.end()
#define int long long
#define ll long long
#define ldb long double
#define db double
#define ull unsigned long long
#define lb lower_bound
#define ub upper_bound
#define pb emplace_back
#define mk make_pair
#define pll pair<ll, ll>
#define pldb pair<ldb, ldb>
#define fi first
#define se second
#define vull vector<ull>
#define vll vector<ll>
#define vb vector<bool>
#define vldb vector<ldb>
#define vpll vector<pll>
#define vpldb vector<pldb>
#define pqmin priority_queue<ll, vector<ll>, greater<ll>>       

#define pq priority_queue<ll>                                   

#define pqpll priority_queue<pll>                               

#define pqpllmin priority_queue<pll, vector<pll>, greater<pll>> 

#define mll map<ll, ll>
#define mldb map<ldb, ldb>
#define umll unordered_map<ll, ll>
#define sll set<ll>
#define usll unordered_set<ll>
#define sfor(i, azz, bzz) for (ll i = (azz); i <= (bzz); ++i)
#define rfor(i, bzz, azz) for (ll i = (bzz); i >= (azz); --i)
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
vll primes1;
void sieve2(ll l, ll r)
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
            primes1.pb(i + l);
    }
}
void primefactorll(ll x, mll &mp)
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

bool primeornot(ll n)
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

void allfactors(vll &v, ll n)
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

bool ispalindrome(string str, ll l, ll r)
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

ll reversenum(ll n)
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
    ll count_after_dot = 0;
    bool dot_seen = false;

    for (ll i = 0; i < n; i++)
    {
        if (str[i] != '.')
        {
            num = num * 10 + (str[i] - '0');
            if (dot_seen == true)
                count_after_dot++;
        }
        else
            dot_seen = true;
    }
    if (dot_seen == false)
    {
        den = 1;
        return;
    }
    ll dem = (ll)pow(10, count_after_dot);
    ll g = __gcd(num, dem);
    num = num / g;
    den = dem / g;
    return;
}

string convert_to_bit(ll a, int bit)
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

ll bit_to_decimal(string &num)
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

ll todecimal(string str)
{
    return stoll(str, nullptr, 10);
}

string tobinary(ll n)
{
    if (n == 0)
        return "0";
    else if (n == 1)
        return "1";
    else if (n % 2 == 0)
        return tobinary(n / 2) + "0";
    else
        return tobinary(n / 2) + "1";
}
#define countsetbit __builtin_popcount
#define pairity _builtin_parity 

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












































void fun(ll countu)
{
    ll n;
    cin >> n;
    ll cn = n;
    sll s;
    sfor(i, 1, n) s.insert(i);
    ll ans[n + 1] = {0};
    ll k;
    while (1)
    {
        if (S(s) == 0)
            break;
        ll pos = *s.rbegin();
        s.erase(pos);
        vll v;
        ll ex = 1;
        do
        {
            ex++;
            if(ex>n) break;
            cout << "? ";
            sfor(i, 1, cn)
            {
                if (pos == i)
                {
                    cout << ex << " ";
                }
                else
                {
                    cout << 1 << " ";
                }
            }
            cout << endl;
            cin >> k;
            if (k != 0 && k != pos)
            {
                s.erase(k);
                v.pb(k);
            }
        } while (k != 0 && k != pos);
        ex--;
        ans[pos] = n - (ex - 1) - (k == pos);
        sfor(i, 0, S(v) - 1)
        {
            ans[v[i]] = ans[pos] + i + 1;
        }
        n = ans[pos];
    }
    cout << "! ";
    print(ans, 1, cn);
    cout << endl;
    cin >> k;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    srand(time(0));
    

    

    ll t = 1;
    

    sfor(i, 1, t) fun(i);

    return 0;
}