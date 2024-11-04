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
const int                 modulo1 = 998244353;
const double              pi = 3.141592653589;
#pragma optimize(Ofast)
#define vv vector<vector<int>>
#define vi vector<int>
typedef pair<int, int>pp;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>pbds;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update>multi_pbds;


typedef tree<pp, null_type, less<pp>, rb_tree_tag, tree_order_statistics_node_update>pair_pbds;


mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());




















































int calculate(int p, int q)
{

    int expo = modulo - 2;
    while (expo)
    {
        if (expo & 1)
        {
            p = (p * q) % modulo;
        }
        q = (q * q) % modulo;
        expo >>= 1;
    }
    return p;
}
















int power(int x, unsigned int y)
{
    int res = 1;
    x = x % modulo;
    if (x == 0) return 0;
    while (y > 0)
    {
        if (y & 1) res = (res * x) % modulo;
        y = y >> 1;
        x = (x * x) % modulo;
    }
    return res;
}


















































































































































const int NN = 1000000;
std::vector<int>primes;
bool IsPrime[NN];
void SieveOfEratosthenes()
{
    

    memset(IsPrime, true, sizeof(IsPrime));
    IsPrime[1] = false;
    IsPrime[0] = false;
    for (int p = 2; p * p < NN; p++) {
        if (IsPrime[p] == true) {
            for (int i = p * p; i < NN; i += p)
                IsPrime[i] = false;
        }
    }
    for (int p = 2; p < NN; p++)
        if (IsPrime[p] == true)
            primes.push_back(p);
}


int mceil(int a, int b)
{
    if (a % b == 0)return a / b;
    else return a / b + 1;
}

























































int dr[] = {1, 1, 0, -1, -1, -1, 0, 1};
int dc[] = {0, 1, 1, 1, 0, -1, -1, -1};

































































































































































































































































































































































const int N = 2e5 + 10;
int a[N];
struct  FenwickTree
{
    vector<int> bit;  

    int n;
    FenwickTree(int n) {
        this->n = n;
        bit.assign(n, 0);
    }
    void update(int val, int id)
    {
        for (++id; id < n; id += (id & -id))bit[id] += val;
    }
    int get(int r)
    {
        int sum = 0;
        for (++r; r > 0; r -= (r & -r))sum += bit[r];
        return sum;
    }
};
















































const int INF = 1e18;
int dx[] = { -1, 0, 0, 1};
int dy[] = { 0, -1, 1, 0};







































































std::vector<int> v[N];
int vis[N];
int vis1[N];
int par[N];
int ans = -1, ans2;
int dp[N];
void dfs(int u, int p, int col)
{
    vis[u] = 1;
    par[u] = p;
    dp[u] = col;
    for (auto it : v[u])
    {
        if (vis[it] == 0)dfs(it, u, col);
        else if (vis[it] == 1 and col != dp[it] and dp[it])
        {
            ans = it;
            ans2 = u;
            return;
        }
    }
}
void solve()
{
    int n, m, s; cin >> n >> m >> s;
    FOR(i, 0, m)
    {
        int x, y; cin >> x >> y;
        if (y != s)v[x].pb(y);
    }
    par[s] = s;
    if (v[s].size() == 1)
    {
        cout << "Impossible\n";
        return;
    }

    int col = 0;




    for (auto it : v[s])
    {
        if (vis[it] == 0)
        {
            par[it] = s;
            dfs(it, s, ++col);
        }
        else
        {
            ans = it;
            ans2 = s;
        }
        if (ans != -1)break;
    }
    if (ans == -1)
    {
        cout << "Impossible\n";
        return;
    }
    else
    {
        cout << "Possible\n";
        std::vector<int> v1, v2;
        int xv = ans;
        v1.pb(ans);
        ans = par[ans];
        while (ans != s)
        {
            v1.pb(ans);
            ans = par[ans];
        }
        v1.pb(ans);


        reverse(all(v1));


        v2.pb(xv);
        xv = ans2;
        while (xv != s)
        {
            v2.pb(xv);
            xv = par[xv];
        }
        v2.pb(xv);
        reverse(all(v2));


        cout << v1.size() << '\n';
        for (auto it : v1)cout << it << ' ';
        cout << '\n';
        cout << v2.size() << '\n';
        for (auto it : v2)cout << it << ' ';
        cout << '\n';
    }



}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    

    

    

    

    

    



    solve();
}