#include"bits/stdc++.h"
#include <ext/pb_ds/assoc_container.hpp> 

#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define ff                first
#define ss                second
#define MM                998244353
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
#define mod               1000000009;
const double              pi = 3.141592653589;
#pragma optimize(Ofast)
#define vv vector<vector<int>>
#define vi vector<int>
typedef pair<int, int>pp;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>pbds;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update>multi_pbds;


typedef tree<pp, null_type, less<pp>, rb_tree_tag, tree_order_statistics_node_update>pair_pbds;


mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());






const int P = 998244353;
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
















int power(int x, unsigned int y)
{
    int res = 1;
    

    if (x == 0) return 0;
    while (y > 0)
    {
        if (y & 1) res = (res * x);
        y = y >> 1;
        

    }
    return res;
}
unsigned long long modInverse(unsigned long long n, int p)
{
    return power(n, p - 2);
}

















































































































































































int mceil(int a, int b)
{
    if (a % b == 0)return a / b;
    else return a / b + 1;
}















































































































































































































int dx[] = { -1, 0, 0, 1};
int dy[] = { 0, -1, 1, 0};
























































































































































const int maxi = 1e5 + 5;
int spf[maxi];


































































const int N = 3e5 + 5;
const int INF = 1e18;
std::vector<int> adj[N];
































































































































































int a[N];
int cnt[N];
int nearest(int u)
{
    int i = 0;
    while (pow(2, i) < u)i++;

    return pow(2, i) - u;
}
void solve()
{
    int n; cin >> n;
    for (int i = 0; i <= n + 10; i++)cnt[i] = 0;
    FOR(i, 0, n)
    {
        cin >> a[i];
        cnt[a[i]]++;
    }
    int ans = INF;
    for (int light = 1; light <= n; light *= 2)
    {
        for (int medium = 1; medium <= n; medium *= 2)
        {
            int li = 0, mi = 0, hi = 0, sum = 0;
            int i = 1;
            for (; i <= n; i++)
            {
                if (li + cnt[i] <= light)li += cnt[i];
                else break;
            }
            sum += (light - li);

            for (; i <= n; i++)
            {
                if (mi + cnt[i] <= medium)mi += (cnt[i]);
                else break;
            }
            sum += (medium - mi);
            for (; i <= n; i++)
            {
                hi += cnt[i];
            }
            sum += nearest(hi);
            ans = min(ans, sum);
        }
    }
    cout << ans << '\n';
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    

    

    

    

    

    

    w(t)
    solve();
}