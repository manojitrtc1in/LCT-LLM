







using namespace __gnu_pbds;
using namespace std;













const int                 maxn = 2e5 + 10;
const int                 modulo = 1000000007;

const double              pi = 3.141592653589;



typedef pair<int, int>pp;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>pbds;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update>multi_pbds;


typedef tree<pp, null_type, less<pp>, rb_tree_tag, tree_order_statistics_node_update>pair_pbds;


mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());






int id0(int n, int r)
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












































































































































const int N = 4e6 + 5;;
vector<int>v[N];
void solve()
{
    int n; cin >> n;
    int a[n];
    int xo = 0;
    map<int, int>mp;
    FOR(i, 0, n)cin >> a[i];
    for (int i = 0; i <= 30; i++)
    {

        for (int j = 0; j < n; j++)
        {
            if (a[j] & (1 << (i)))mp[i]++;
        }
    }
    
    int d = 0;
    for (int i = 0; i <= 30; i++)d = __gcd(d, mp[i]);
    if (d == 0)for (int i = 1; i <= n; i++)cout << i << ' ';
    else for (int i = 1; i <= n; i++)if (d % i == 0)cout << i << ' ';
    cout << '\n';
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    

    

    

    

    

    

    w(t)
    solve();
}