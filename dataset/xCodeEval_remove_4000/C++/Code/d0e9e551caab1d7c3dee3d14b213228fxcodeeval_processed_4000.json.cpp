


























using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef string str;







const ll inf = (ll)1e18 + 7;
ld eps = 1e-9;
ll mod = 1e9 + 7;

signed main() {

    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t;
    cin >> t;
    while (t--) {
        ll n, d, i, j, last = -1, ans = 0, sup = inf;
        cin >> n >> d;
        vector <ll> a(n + 2);
        a[0] = 0;
        a[n + 1] = d + 1;
        multiset <pair <ll, ll> > kurwa;
        for (i = 1; i <= n; i++) {
            cin >> a[i];
            kurwa.insert({ a[i] - a[i - 1] - 1, i });
        }
        

        for (i = 1; i < n; i++) {
            kurwa.erase({ a[i] - a[i - 1] - 1,i });
            kurwa.erase({ a[i + 1] - a[i] - 1,i + 1 });
            kurwa.insert({ a[i + 1] - a[i - 1] - 1, inf });
            ans = max(ans, min(kurwa.begin()->first, max(((kurwa.rbegin()->first - 1) / 2), d - a[n] - 1)));
            kurwa.erase({ a[i + 1] - a[i - 1] - 1, inf });
            kurwa.insert({ a[i] - a[i - 1] - 1,i });
            kurwa.insert({ a[i + 1] - a[i] - 1,i + 1 });
        }
        kurwa.erase({ a[n] - a[n - 1] - 1,n });
        ans = max(ans, min(kurwa.begin()->first, max(d - a[n - 1] - 1, (kurwa.rbegin()->first - 1) / 2)));
        
        cout << ans << endl;
    }
    

}


