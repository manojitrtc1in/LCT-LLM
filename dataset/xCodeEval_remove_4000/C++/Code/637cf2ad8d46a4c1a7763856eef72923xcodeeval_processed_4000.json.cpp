










































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

signed main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout.precision(20), cout.setf(ios::fixed);
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(n));
    for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) cin >> a[i][j];
    vector<int> cntc(n), cntr(n);
    vector<pair<int, pair<int, int>>> pos;
    ll ans = 0;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            pos.pbc({ a[i][j], {i,j} });
        }
    }
    sort(all(pos));
    for (int i = 0; i < pos.size(); ++i)
    {
        int r = pos[i].second.first, c = pos[i].second.second;
        ans += (n - 1 - cntr[r]) * cntc[c];
        ans += (n - 1 - cntc[c]) * cntr[r];
        cntr[r]++;
        cntc[c]++;
    }
    cout << ans / 2;
  

}