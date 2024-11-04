





























































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define vll vector<ll>
#define vpll vector<pair<ll, ll>>
#define fo(i, k, n) for (ll i = k; i < n; i++)
#define fo1(i, k, n) for (ll i = k; i <= n; i++)
#define rr return
#define ff first
#define ss second
#define Auto auto
#define llmin LONG_MIN
#define llmax LONG_MAX
#define Yes cout << "Yes\n"
#define No cout << "No\n"
#define YES cout << "YES\n"
#define NO cout << "NO\n"
#define yes cout << "yes\n"
#define no cout << "no\n"

#define show(A)           \
    for (auto i : A)      \
        cout << i << " "; \
    cout << '\n';
#define endl "\n"
#define Endl endl
clock_t startTime = clock();
#define setbits(x) __builtin_popcountll(x)
#define zrobits(x) __builtin_ctzll(x)
#define all(v) v.begin(), v.end()
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x << " " << x << endl;
#else
#define debug(x)
#endif
using namespace std;

void io()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    

    

    

    

    

}
double PI = 4 * atan(1);
ll mod = 1e9 + 7, mxn = 3e5 + 5;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
void deb(vector<ll> v)
{
    for (auto t : v)
        cerr << t << " ";
    cerr << "\n";
}
ll mul(ll a, ll b, ll mod)
{
    a %= mod;
    b %= mod;
    a *= b;
    a += mod;
    return a % mod;
}

bool sortbysecdesc(const pair<int, int> &a,
                   const pair<int, int> &b)
{
    return a.second > b.second;
}
vll fact(2e5 + 5, 1);
ll binPow(ll a, ll b)
{
    if (b == 0)
        return 1;
    if (b == 1)
        return a;
    ll ret = binPow(a, b / 2);
    if (b % 2 == 0)
        return (ret * ret) % mod;
    return ((ret * ret) % mod * a) % mod;
}
ll inv(ll a)
{
    return (binPow(a, mod - 2) % mod + mod) % mod;
}
ll binom(ll a, ll b)
{
    

    

    if (b < 0 or a < 0)
        return 0;
    return (((fact[a] * inv(fact[b])) % mod * inv(fact[a - b])) % mod + mod) % mod;
}




vector<int> sieveOfEratosthenes(int N)
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

bool isPrime(ll n)
{
    if (n < 2)
        return false;
    for (ll x = 2; x * x <= n; x++)
    {
        if (n % x == 0)
            return false;
    }
    return true;
}

bool isPowerOfTwo(ll n)
{
    return n && (!(n & (n - 1)));
}










void solve()
{
    int n, u, r, d, l;
    cin >> n >> u >> r >> d >> l;
    int u1 = u;
    int r1 = r;
    int l1 = l;
    int d1 = d;
    if (u == n)
    {
        l1--;
        r1--;
    }
    if (d == n)
    {
        l1--;
        r1--;
    }
    if (l == n)
    {
        d1--;
        u1--;
    }
    if (r == n)
    {
        d1--;
        u1--;
    }

    if (u == n - 1)
    {
        if (l1 > r1)
        {
            l1--;
        }
        else
        {
            r1--;
        }
    }
    if (d == n - 1)
    {
        if (l1 > r1)
        {
            l1--;
        }
        else
        {
            r1--;
        }
    }
    if (l == n - 1)
    {
        if (u1 > d1)
        {
            u1--;
        }
        else
        {
            d1--;
        }
    }
    if (r == n - 1)
    {
        if (u1 > d1)
        {
            u1--;
        }
        else
        {
            d1--;
        }
    }

    

    if (l1 < 0 || u1 < 0 || d1 < 0 || r1 < 0)
    {
        cout << "NO" << endl;
        return;
    }
    cout << "YeS" << endl;
    return;
}
int main()
{
    io();
    

    ll t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    


    


    

    return 0;
}