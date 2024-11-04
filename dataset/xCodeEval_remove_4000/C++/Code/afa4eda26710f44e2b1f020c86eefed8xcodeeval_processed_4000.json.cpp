





















using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef string str;








ll mod = 1e9 + 7;

ll mex(string &s) {
    ll res = 0, i, j;
    for (i = 0; i < s.size(); i++) {
        if (s[i] == '0') {
            res = res |= 1;
        }
        else {
            res = res |= 2;
        }
    }
    if (res == 3) {
        return 2;
    }
    else if (res == 1) {
        return 1;
    }
    else {
        return 0;
    }
}

signed main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t;
    cin >> t;
    while (t--) {
        ll n, k, i, j;
        cin >> n >> k;
        ll p = 1;
        ll ans = 0;
        for (j = 0; j < 30; j++) {
            if (k & (1 << j)) {
                ans = (ans + p) % mod;
            }
            p *= n;
            p %= mod;
        }
        cout << ans << endl;
    }
}