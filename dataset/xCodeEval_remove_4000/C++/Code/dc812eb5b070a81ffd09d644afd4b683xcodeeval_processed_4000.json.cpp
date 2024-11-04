









































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
using namespace chrono;
const ld EPS = 1e-25;
const ld PI = acos(-1.0);
const int mod = 1000000007;
const int MAXN = 1e6 + 20;
int mul(int a, int b)
{
    return 1ll * a * b % mod;
}
int add(int a, int b)
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
int fact[MAXN]; int rfact[MAXN];
int cnk(int n, int k)
{
    if (k<0 || k>n) return 0;
    return mul(fact[n], mul(rfact[k], rfact[n - k]));
}

void init()
{
    fact[0] = 1;
    for (int i = 1; i < MAXN; ++i) fact[i] = mul(fact[i - 1], i);
    rfact[MAXN - 1] = inv(fact[MAXN - 1]);
    for (int i = MAXN - 2; i >= 0; --i)rfact[i] = mul(rfact[i + 1], i + 1);
}
int n, m, k;
int calc(int x, int y)
{
    if (x == y)
    {
        return mul(y, k);
    }
    int res = 0;
    for (int j = y; j >= 1; --j)
    {
        int rofl = cnk(x - j - 1, y - j);
        rofl = mul(rofl, mul(j, k));
        int dv = binpow(2, x - j);
        dv = inv(dv);
        rofl = mul(rofl, dv);
        res = add(res, rofl);
    }
    return res;
}
signed main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout.precision(20), cout.setf(ios::fixed);
    init();
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n >> m >> k;
        if (n == m)
        {
            cout << mul(m, k) << '\n';
            continue;
        }
        int res = add(calc(n - 1, m - 1), calc(n - 1, m));
        res = mul(res, inv(2));
        cout << res << '\n';
    }
   

}