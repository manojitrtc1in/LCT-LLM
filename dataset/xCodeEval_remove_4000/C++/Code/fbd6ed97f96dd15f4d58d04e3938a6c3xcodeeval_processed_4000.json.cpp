







using namespace __gnu_pbds;
using namespace std;













const int                 maxn = 1e3 + 5;
const int                 modulo = 1000000007;

const double              pi = 3.14159;
typedef pair<int, int>pp;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>pbds;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update>multi_pbds;


typedef tree<pp, null_type, less<pp>, rb_tree_tag, tree_order_statistics_node_update>pair_pbds;



















































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
    return res ;
}



































































































































































































int mceil(int a, int b)
{
    if (a % b == 0)return a / b;
    else return a / b + 1;
}
























































































































































































































































































































































































int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };






































































int invertBits(int n)
{
    

    int x = log2(n) ;
    int m = 1 << x;
    m = m | m - 1;
    n = n ^ m;
    return n;
}
void solve()
{
    int n; cin >> n;
    int a[n];
    set<int>s, s1;

    FOR(i, 0, n)cin >> a[i], s.insert(a[i]), s1.insert(i + 1);
    int b[n];
    if (n - s.size() <= 1)
    {
        for (int i = n - 1; i >= 0; i--)
        {
            if (s1.find(a[i]) != s1.end())
            {
                s1.erase(a[i]);
                b[i] = a[i];
            }
            else b[i] = 0;
        }
        for (int i = n - 1; i >= 0; i--)
        {
            if (b[i] == 0)
            {
                int x = *s1.begin();
                b[i] = x;
                s1.erase(x);

            }
        }
        int ok = 0;
        for (int i = 0; i < n; i++)
        {
            if (b[i] == i + 1)
            {
                for (int j = i + 1; j < n; j++)
                {
                    if (a[i] == a[j])
                    {
                        swap(b[j], b[i]);
                        ok = 1;
                        break;
                    }
                }
                if (ok)break;
            }
        }

    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            if (s1.find(a[i]) != s1.end())b[i] = a[i], s1.erase(a[i]);
            else b[i] = 0;
        }
        for (int i = 0; i < n; i++)
        {
            if (b[i] == 0)
            {
                int x = *s1.rbegin();
                b[i] = x;
                s1.erase(x);
            }
        }
        int ok = 0;
        for (int i = 0; i < n; i++)
        {
            if (b[i] == i + 1)
            {
                for (int j = 0; j < n; j++)
                {
                    if (((b[j] == j + 1) || (a[j] != b[j])) && i != j)
                    {
                        swap(b[j], b[i]);
                        ok = 1;
                        break;
                    }
                }
                if (ok)break;
            }
        }
    }
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == b[i])cnt++;
    }
    cout << cnt << '\n';
    FOR(i, 0, n)cout << b[i] << ' ';
    cout << '\n';
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    

    

    

    w(t)
    solve();
}