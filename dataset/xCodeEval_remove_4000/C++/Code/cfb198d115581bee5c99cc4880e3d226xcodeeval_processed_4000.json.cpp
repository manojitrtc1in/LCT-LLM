










































using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;










template<typename T1, typename T2>
inline void chkmin(T1& x, const T2& y)
{
    if (y < x) x = y;
}

template<typename T1, typename T2>
inline void chkmax(T1& x, const T2& y)
{
    if (x < y) x = y;
}
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
ld id0 = 0;
double getTime() { return (clock() - id0) / (double)CLOCKS_PER_SEC; }
pair<int, int> operator-(pair<int, int> a, pair<int, int> b)
{
    return { a.first - b.first, a.second - b.second };
}
pair<int, int> operator+(pair<int, int> a, pair<int, int> b)
{
    return { a.first + b.first, a.second + b.second };
}


const int inf = 1e9 + 228;
const ld EPS = 1e-9;
const ld PI = acos(-1.0);
const int mod = 998244353;
const ld INF = 1e18;
inline int mul(int a, int b)
{
    return 1ll * a * b % mod;
}
inline int add(int a, int b)
{
    if (a + b >= mod) return a + b - mod;
    return a + b;
}
int sub(int a, int b)
{
    if (a - b < 0) return a - b + mod;
    return a - b;
}
int binpow(int a, int b)
{
    int res = 1;
    while (b)
    {
        if (b & 1)res = mul(res, a);
        a = mul(a, a);
        b >>= 1;
    }
    return res;
}
int inv(int x)
{
    return binpow(x, mod - 2);
}
vector<vector<int>> mult(vector<vector<int>> a, vector<vector<int>> b)
{
    vector<vector<int>> res(a.size(), vector<int>(b[0].size()));

    for (int k = 0; k < a[0].size(); ++k)
    {
        for (int i = 0; i < a.size(); ++i)
        {
            for (int j = 0; j < b[0].size(); ++j)
            {
                res[i][j] = add(res[i][j], mul(a[i][k], b[k][j]));
            }
        }
    }
    return res;
}
vector<vector<int>>binpow(vector<vector<int>> a, int b)
{
    vector<vector<int>> res(a.size(), vector<int>(a.size()));
    for (int i = 0; i < a.size(); ++i) res[i][i] = 1;
    while (b)
    {
        if (b & 1)res = mult(res, a);
        a = mult(a, a);
        b >>= 1;
    }
    return res;
}
signed main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout.precision(20), cout.setf(ios::fixed);
    int n, m, k;
    cin >> n >> m >> k;
    vector<pair<int, int>> e;
    vector<vector<int>> d(n, vector<int>(n));
    vector<vector<int>> A(n, vector<int>(n));
    for (int i = 0; i < m; ++i)
    {
        int a, b;
        cin >> a >> b;
        --a; --b;
        e.pbc({ a,b });
        d[a][a]++;
        A[a][b]++;
        A[b][a]++;
        d[b][b]++;
    }
    vector<vector<int>> go(2 * n, vector<int>(2 * n));
    for (int i = 0; i < n; ++i)
    {
        go[i][i + n] = 1;
    }
    for (int i = n; i < 2 * n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            go[i][j] = sub((i - n == j), d[i - n][j]);
        }
    }
    for (int i = n; i < 2 * n; ++i)
    {
        for (int j = n; j < 2 * n; ++j)
        {
            go[i][j] = A[i - n][j - n];
        }
    }
    if (k == 1)
    {
        cout << 0;
        return 0;
    }
    auto tgo = binpow(go, k - 2);
    vector<vector<int>> vec(2 * n, vector<int>(n));
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            vec[i][j] = A[i][j];
        }
    }
    auto ta = mult(A, A);
    for (int i = n; i < 2 * n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            vec[i][j] = sub(ta[i - n][j], d[i - n][j]);
        }
    }
    vec = mult(tgo, vec);
    int res = 0;
    for (int i = 0; i < n; ++i) res = add(res, vec[i + n][i]);
    cout << res;
    

}