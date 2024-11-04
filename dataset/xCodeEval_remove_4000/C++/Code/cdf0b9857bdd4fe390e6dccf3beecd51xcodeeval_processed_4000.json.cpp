

using namespace std;





    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0)

    int t;      \
    cin >> t;   \
    while (t--)






template <typename T1>
void ipt(T1 &a) { cin >> a; }
template <typename T1, typename T2>
void ipt(T1 &a, T2 &b) { cin >> a >> b; }
template <typename T1, typename T2, typename T3>
void ipt(T1 &a, T2 &b, T3 &c) { cin >> a >> b >> c; }
template <typename T1, typename T2, typename T3, typename T4>
void ipt(T1 &a, T2 &b, T3 &c, T4 &d) { cin >> a >> b >> c >> d; }
template <typename T1, typename T2>
void ipt(pair<T1, T2> &p) { ipt(p.first, p.second); }
template <class T>
void ipt(vector<T> &v) { f(i, 0, v.size()) ipt(v[i]); }



ll const MOD = 1000000007;

void solve()
{
    ll n, ans = 0;
    cin >> n;
    vector<ll> v(n);
    f(i, 0, n)
    {
        cin >> v[i];
        ans += v[i];
    }
    sort(all(v));
    ll pos = -1;
    f(i, 1, n)
    {
        while (v[i] > 1 and v[i] % 2 == 0)
        {
            v[0] *= 2;
            v[i] /= 2;
        }
    }
    sort(v.begin() + 1, v.end());
    f(i, 0, n)
    {
        if (v[i] & 1)
            pos = i;
    }
    ll sum = 0;
    f(i, 0, n) sum += v[i];
    ans = max(ans, sum);
    if (pos == -1)
    {
        cout << ans;
        enter;
        return;
    }

    sum = 0;
    f(i, 0, n)
    {
        if (i == pos)
            continue;
        while (v[i] > 1 and v[i] % 2 == 0)
        {
            v[pos] *= 2;
            v[i] /= 2;
        }
    }
    f(i, 0, n) sum += v[i];
    ans = max(ans, sum);
    cout << ans;
    enter;
}

int32_t main()
{
    

    testing
    solve();
    return 0;
}