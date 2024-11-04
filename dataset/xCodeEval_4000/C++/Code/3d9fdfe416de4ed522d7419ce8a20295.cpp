#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 

#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

using namespace std;
#define ff                first
#define ss                second
#define int               long long
#define pb                push_back
#define pf                push_front
#define ps(x,y)           fixed<<setprecision(y)<<x
#define w(x)              int x; cin>>x; while(x--)
#define FOR(i,a,b)        for(int i=(a);i<(b);i++)
#define ROF(i,a,b)        for(int i=(a);i>=(b);i--)
#define so(a,n)           sort(a,a+n)
#define rso(a,n)          sort(a,a+n),reverse(a,a+n)
#define all(v)            (v).begin(),(v).end()
#define ps(x,y)           fixed<<setprecision(y)<<x
const int                 maxn = 2e5 + 10;
const int                 modulo = 1000000007;
#define mod               1000000007;
const double              pi = 3.141592653589;
#pragma optimize(Ofast)
#define vv vector<vector<int>>
#define vi vector<int>
typedef pair<int, int>pp;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>pbds;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update>multi_pbds;


typedef tree<pp, null_type, less<pp>, rb_tree_tag, tree_order_statistics_node_update>pair_pbds;


mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());






int printNcR(int n, int r)
{
    if (n < r)return 0;
    long long p = 1, k = 1;
    if (n - r < r)
        r = n - r;
    if (r != 0) {
        while (r) {
            p *= n;
            k *= r;
            long long m = __gcd(p, k);
            p /= m;
            k /= m;

            n--;
            r--;
        }
    }
    else p = 1;
    return p;
}
















const int P = 998244353;
int power(int x, unsigned int y)
{
    int res = 1;
    

    if (x == 0) return 0;
    while (y > 0)
    {
        if (y & 1) res = (res * x);
        y = y >> 1;
        x = (x * x);
    }
    return res;
}
unsigned long long modInverse(unsigned long long n, int p)
{
    return power(n, p - 2);
}






unsigned long long nCrModPFermat(unsigned long long n,
                                 int r, int p)
{
    

    if (n < r)
        return 0;
    

    if (r == 0)
        return 1;

    

    

    

    unsigned long long fac[n + 1];
    fac[0] = 1;
    for (int i = 1; i <= n; i++)
        fac[i] = (fac[i - 1] * i) % p;

    return (fac[n] * modInverse(fac[r], p) % p
            * modInverse(fac[n - r], p) % p)
           % p;
}












































































































































int mceil(int a, int b)
{
    if (a % b == 0)return a / b;
    else return a / b + 1;
}

























































int dr[] = {1, 1, 0, -1, -1, -1, 0, 1};
int dc[] = {0, 1, 1, 1, 0, -1, -1, -1};














































































































































int dx[] = {1, 0, 0, -1};
int dy[] = {0, -1, 1, 0};


























































































































































const int maxi = 1e7 + 5;
int spf[maxi];






void sieve()
{
    spf[1] = 1;
    for (int i = 2; i < maxi; i++)
        spf[i] = i;
    for (int i = 4; i < maxi; i += 2)
        spf[i] = 2;

    for (int i = 3; i * i < maxi; i++)
    {
        if (spf[i] == i)
        {
            for (int j = i * i; j < maxi; j += i)
                if (spf[j] == j)spf[j] = i;
        }
    }
}




































































































































int d[maxi];
int ans[maxi];
void solve()
{
    for (int i = 1; i < 10000005; ++i) {
        for (int j = i; j < 10000005; j += i) {
            d[j] += i;
        }
        if (d[i] <= 10000000 && !ans[d[i]]) {
            ans[d[i]] = i;
        }
    }
    int n = 1;
    scanf("%d", &n);
    FOR(i, 0, n)
    {
        int x;
        scanf("%d", &x);
        if (!ans[x]) printf("-1\n");
        else printf("%d\n", ans[x]);
    }

}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    

    

    

    

    

    

    

    solve();
}