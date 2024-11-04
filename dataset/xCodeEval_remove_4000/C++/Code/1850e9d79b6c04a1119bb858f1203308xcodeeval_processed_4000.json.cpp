











































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
const ld EPS = 1e-15;
const ld PI = acos(-1.0);
int mod = 1000000007;
const ll INF = 1e18;
signed main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);  
    cout.precision(3), cout.setf(ios::fixed);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        vin(a);
        vector<int> pref(n);
        for (int i = 0; i < n; ++i)
        {
            pref[i] = a[i];
            if (i) pref[i] ^= pref[i - 1];
        }
        vector<int> dp(n + 2, inf);
        dp[n] = 0;
        map<int, int> last;
        for (int i = n - 1; i >= 0; --i)
        {
            int go = (i==0 ? 0 : pref[i-1]);
            last[pref[i]] = i;

            if (last.count(go))
            {
                dp[i] = min(dp[i], dp[last[go] + 1] + last[go] - i);
            }
            dp[i] = min(dp[i], dp[i + 1] + 1);
        }
        cout << dp[0] << '\n';
    }
    

}