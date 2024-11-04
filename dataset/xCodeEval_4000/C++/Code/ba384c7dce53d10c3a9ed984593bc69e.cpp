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
















int power(int x, unsigned int y, int p)
{
    int res = 1;
    x = x % p;
    if (x == 0) return 0;
    while (y > 0)
    {
        if (y & 1) res = (res * x) % p;
        y = y >> 1;
        x = (x * x) % p;
    }
    return res;
}
unsigned long long modInverse(unsigned long long n, int p)
{
    return power(n, p - 2, p);
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





































































































const int NN = 1000006;
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
    

    

    

}


int mceil(int a, int b)
{
    if (a % b == 0)return a / b;
    else return a / b + 1;
}

























































int dr[] = {1, 1, 0, -1, -1, -1, 0, 1};
int dc[] = {0, 1, 1, 1, 0, -1, -1, -1};


















































































































































int dx[] = { -1, 0, 0, 1};
int dy[] = { 0, -1, 1, 0};





























































































































































































































const int N = 2e5 + 5;
const int INF = 1e18;
std::vector<int>v[N];
int si[N];
int par[N];
int vis[N];


































































































































































int query(int a, int b, int c) {
    cout << "? " << a  << ' ' << b << ' ' << c << endl;
    int ret;
    cin >> ret;
    return ret;
}
void solve()
{


    int n; cin >> n;
    int imp = -1;
    int u = n / 3;
    int v = 2 * u;
    int crew = -1;
    std::vector<int> v1;
    v1.pb(0);
    for (int i = 1; i <= n; i++)v1.pb(i);
    for (int i = 1; i <= n; i++)v1.pb(i);

    std::vector<int> vec1;
    for (int i = 1; i <= n + 3; i++)
    {
        cout << "? " << v1[i] << ' ' << v1[i + 1] << ' ' << v1[i + 2] << endl;
        cout << flush;
        int x; cin >> x;
        vec1.pb(x);
        if (vec1.size() > 1)
        {
            int m = vec1.size();
            if (vec1[m - 1] + vec1[m - 2] == 1)break;
        }
    }
    for (int i = 0; i < vec1.size() - 1; i++)
    {
        if (vec1[i] == 0 and vec1[i + 1] == 1)
        {
            imp = v1[i + 1];
            crew = (v1[i + 2] + 2);
            if (crew > n)crew -= n;
            break;
        }
        else if (vec1[i] == 1 and vec1[i + 1] == 0)
        {
            crew = v1[i + 1];
            imp = v1[i + 2] + 2;
            if (imp > n)imp -= n;
            break;
        }
    }




    std::vector<int> vec;
    vec.pb(imp);
    for (int i = 1; i <= n; i++)
    {
        if (i != imp and i != crew)
        {
            cout << "? " << imp << ' ' << crew << ' ' << i << endl;
            cout << flush;
            int x; cin >> x;
            if (x == 0)
            {
                vec.pb(i);
                

            }
        }
    }
    cout << "! " << vec.size() << ' ';
    for (auto it : vec)cout << it << ' ';
    cout << endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    

    

    

    

    

    

    w(t)
    solve();
}