







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

















































































































































































































































































































































const int N = 4e6 + 5;;
vector<int>v[N];
void solve()
{
    int n; cin >> n;
    int a[n];
    map<int, int>mp;
    int b[n];
    FOR(i, 0, n)cin >> a[i], mp[a[i]]++, b[i] = a[i];
    int j = 0;
    int ok = 1;
    while (ok)
    {
        ok = 0;
        FOR(i, 0, n)
        {
            if (a[i] != mp[a[i]])a[i] = mp[a[i]], ok = 1;
        }
        FOR(i, 0, n)v[j].pb(a[i]);
        mp.clear();
        FOR(i, 0, n)mp[a[i]]++;
        j++;
    }
    int q; cin >> q;
    FOR(i, 0, q)
    {
        int x, k; cin >> x >> k;
        

        x--;
        

        if (k == 0)cout << b[x] << '\n';
        else if (k >= j)cout << v[j - 1][x] << '\n';
        else cout << v[k - 1][x] << '\n';
    }
    for (int i = 0; i <= j; i++)v[i].clear();
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    

    

    

    

    

    

    w(t)
    solve();
}