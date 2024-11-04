







using namespace __gnu_pbds;
using namespace std;













const int                 maxn = 2e5 + 10;
const int                 modulo = 1000000007;

const double              pi = 3.14159;


typedef pair<int, int>pp;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>pbds;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update>multi_pbds;


typedef tree<pp, null_type, less<pp>, rb_tree_tag, tree_order_statistics_node_update>pair_pbds;


mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
















































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
    return res ;
}
unsigned long long modInverse(unsigned long long n,
                              int p)
{
    return power(n, p - 2);
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











































































































































































































































































































































































void solve()
{
    set<int>ss;
    int n; cin >> n;
    string s; cin >> s;
    int cnt = 0;
    for (auto it : s)
    {
        if (it == '1')cnt++;
    }
    for (int i = 1; i <= n; i++)
    {
        if (s[i - 1] == '0')ss.insert(i);
    }
    

    if (cnt == 0)
    {
        cout << 1 << ' ' << n << ' ' << 2 << ' ' << n << '\n';
        return;
    }
    else if (s[0] == '1' and s[n - 1] == '0')
    {
        cout << 1 << ' ' << n << ' ' << 1 << ' ' << n - 1 << '\n';
    }
    else if (s[0] == '0' and s[n - 1] == '1')
    {
        cout << 1 << ' ' << n << ' ' << 2 << ' ' << n << '\n';
    }
    else if (s[0] == '0' and s[n - 1] == '0')
    {
        cout << 1 << ' ' << n << ' ' << 2 << ' ' << n << '\n';
    }
    else
    {

        if (n == 3)
        {
            cout << 1 << ' ' << 1 << ' ' << n << ' ' << n << '\n';
            return;
        }
        int suff[n + 2] = {0};
        int pre[n + 2] = {0};
        int ok = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            if (s[i] == '1')suff[i + 1] = 1 + suff[i + 2], pre[i + 1] = 1 + pre[i + 2];
            else suff[i + 1] = 0, pre[i + 1] = pre[i + 2];
        }
        for (int i = 1; i <= n; i++)
        {
            

            if (suff[i] > n / 2)
            {
                cout << i << ' ' << i + n / 2 - 1 << ' ' << i + 1 << ' ' << i + n / 2 << '\n';
                ok = 1;
                return;
            }
            else if (pre[i] > 0 and s[i - 1] == '0' and i <= n / 2)
            {
                cout << i << ' ' << n << ' ' << i + 1 << ' ' <<  n << '\n';
                ok = 1;
                return;
            }
            else if (pre[i] > 0 and s[i - 1] == '1' and i <= n / 2)
            {
                int x = n / 2 + i;
                auto it = ss.upper_bound(x - 1);
                if (it != ss.end())
                {
                    int y = *it;
                    cout << i << ' ' << y << ' ' << i << ' ' << y - 1 << '\n';
                    return;
                }
            }
        }
    }
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    

    

    

    w(t)
    solve();
}