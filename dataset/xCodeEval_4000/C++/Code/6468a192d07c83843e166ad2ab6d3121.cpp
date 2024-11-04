



#include <bits/stdc++.h>
#include "complex"
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
template <class T>
using o_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;




#define int long long
typedef pair<int, int> II;
typedef vector<II> VII;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef long long LL;
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define SZ(a) (int)(a.size())
#define ALL(a) a.begin(), a.end()
#define SET(a, b) memset(a, b, sizeof(a))
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define si(n) scanf("%d", &n)
#define dout(n) printf("%d\n", n)
#define sll(n) scanf("%lld", &n)
#define lldout(n) printf("%lld\n", n)
#define fast_io                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define endl "\n"
const long long mod = 998244353;
int fact[101];
void prec()
{
    fact[0] = 1;
    for (int i = 1; i < 101; i++)
    {
        fact[i] = i * fact[i - 1];
        fact[i] %= mod;
    }
}
int power(long long x, unsigned int y, int p)
{
    

    int res = 1;
    x = x % p;
    if (x == 0)
        return 0;
    while (y > 0)
    {
        if (y & 1)
        {
            res = (res * x) % p;
        }
        y = y >> 1;
        x = (x * x) % p;
    }
    return res;
}
int ncr(int n, int k)
{
    int v = power(fact[k], mod - 2, mod) * power(fact[n - k], mod - 2, mod);
    v %= mod;
    return (v * fact[n]) % mod;
}
int dist(pair<int, int> a, pair<int, int> b)
{
    return abs(a.first - b.first) + abs(a.second - b.second);
}
struct DSU
{
    vector<int> e;
    DSU(int N) { e = vector<int>(N, -1); }

    

    int get(int x) { return e[x] < 0 ? x : e[x] = get(e[x]); }

    bool same_set(int a, int b) { return get(a) == get(b); }

    int size(int x) { return -e[get(x)]; }

    bool unite(int x, int y)
    { 

        x = get(x), y = get(y);
        if (x == y)
            return false;
        if (e[x] > e[y])
            swap(x, y);
        e[x] += e[y];
        e[y] = x;
        return true;
    }
    

    

};

void solve()
{
    


    int n;
    cin >> n;
    vector<pair<int, int>> A(n);
    for (int i = 0; i < n; i++)
    {
        cin >> A[i].first >> A[i].second;
    }
    int d[n];
    vector<int> comp[n];
    for (int i = 0; i < n; i++)
    {
        d[i] = mod;

        for (int j = 0; j < n; j++)
        {
            if (i == j)
            {
                continue;
            }
            d[i] = min(d[i], dist(A[i], A[j]));
        }
        comp[i].PB(i);
        for (int j = 0; j < n; j++)
        {
            if (i == j)
            {
                continue;
            }
            int dd = dist(A[i], A[j]);
            if (dd == d[i])
            {
                comp[i].PB(j);
            }
        }
        sort(comp[i].begin(), comp[i].end());
        

    }

    


    vector<pair<vector<int>, int>> final;
    bool over[n];
    memset(over, 0, sizeof(over));
    for (int p = 0; p < n; p++)
    {
        if (over[p])
        {
            continue;
        }
        int sz = comp[p].size();
        bool ok = true;
        for (int i = 0; i < sz; i++)
        {
            

            if (comp[p] != comp[comp[p][i]])
            {
                ok = false;
                break;
            }
        }
        if (ok && sz != 1)
        {
            final.PB({comp[p], 1});
            for (int j = 0; j < sz; j++)
            {
                over[comp[p][j]] = true;
            }
        }
        else
        {
            final.PB({{p}, 0});
        }
    }
    int ss[5];
    memset(ss, 0, sizeof(ss));
    

    

    

    

    

    

    

    

    

    

    


    

    int dp[n + 1][n + 1];
    dp[0][0] = 1;
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    


    for (int i = 0; i < final.size(); i++)
    {
        int sz = final[i].first.size();

        if (final[i].second == 0)
        {
            

            for (int j = 1; j <= n; j++)
            {
                if (j < sz)
                {
                    continue;
                }
                int v = dp[i][j - sz];
                int used = j - sz;
                v *= ncr(n - used, sz);
                v %= mod;
                v *= fact[sz];
                v %= mod;
                dp[i + 1][j] += v;
                dp[i + 1][j] %= mod;
            }
        }
        else
        {
            for (int j = 1; j <= n; j++)
            {
                if (j < sz)
                {
                    continue;
                }
                int v = dp[i][j - sz];
                int used = j - sz;
                v *= ncr(n - used, sz);
                v %= mod;
                v *= fact[sz];
                v %= mod;
                dp[i + 1][j] += v;
                dp[i + 1][j] %= mod;
            }
            

            for (int j = 1; j <= n; j++)
            {
                int v = dp[i][j - 1];
                v *= (n - j + 1);
                v %= mod;
                dp[i + 1][j] += v;
                dp[i + 1][j] %= mod;
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ans += dp[final.size()][i];
    }
    cout << ans%mod << endl;
}

signed main()
{
    fast_io;
    prec();
    

    

    int totalTests = 1;
    

    for (int testNo = 1; testNo <= totalTests; testNo++)
    {
        

        solve();
    }
    return 0;
}













































































































































































































































































































































































































































































































































































