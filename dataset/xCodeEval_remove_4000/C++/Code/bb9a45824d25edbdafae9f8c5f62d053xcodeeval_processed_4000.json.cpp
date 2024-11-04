






















 
using namespace std;
template<typename T1, typename T2> inline void chkmin(T1 &a, T2 b) {if (a > b) a = b;}
template<typename T1, typename T2> inline void chkmax(T1 &a, T2 b) {if (a < b) a = b;}












using ll = long long;
using ld = long double; 
const string FILENAME = "input";
const int Mod = 1000000007;


int sum(int a, int b) {
    return (a + b >= Mod ? a + b - Mod: a + b);
}


int mul(int a, int b) {
    return ((ll)a * b) % Mod;
}


int powm(int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1) {
            res = mul(res, a);
        }
        a = mul(a, a);
        b >>= 1;
    }
    return res;
}


int inv(int a) {
    return powm(a, Mod - 2);
}


const int MAXN = 100228;


int phi[MAXN];
ll pref[MAXN];
ll dp[MAXN][17];


void calcphi() {
    for (int i = 1; i < MAXN; i++) {
        phi[i] = i;
    }
    for (int i = 2; i < MAXN; i++) {
        if (phi[i] == i) {
            for (int j = i; j < MAXN; j += i) {
                phi[j] -= phi[j] / i;
            }
        }
    }
    for (int i = 1; i < MAXN; i++) {
        pref[i] = pref[i - 1] + phi[i];
    }   
}


ll calc(int l, int r) {
    if (l > r) {
        return 1e18;
    }
    ll ans = 0;
    while (l <= r) {  
        int f = r / l;
        int nl = r / f + 1;
        int len = nl - l;
        ans += pref[f] * len;
        l = nl;
    }
    return ans;
}


void id0(int k, int l, int r, int optl, int optr) {
    if (l > r) {
        return;
    }
    int mid = (l + r) >> 1;
    dp[mid][k] = 1e18;
    int optm = optl;
    ll add = calc(min(mid, optr) + 1, mid);
    for (int i = min(mid, optr); i >= optl; i--) {
        ll val = dp[i][k - 1] + add;
        if (val <= dp[mid][k]) {
            dp[mid][k] = val;
            optm = i;
        }
        if (i <= mid) {
            if (add > 1e17) {
                add = pref[mid / i];
            } else {
                add += pref[mid / i];
            }
        }
    }
    id0(k, l, mid - 1, optl, optm);
    id0(k, mid + 1, r, optm, optr);
}   


void precalc() {
    calcphi();
    dp[0][0] = 0;
    for (int i = 1; i < MAXN; i++) {
        dp[i][0] = 1e18;
    }
    for (int i = 1; i < MAXN; i++) {
        dp[i][1] = (ll)i * (i + 1) / 2;
    }
    for (int k = 2; k <= 16; k++) {
        id0(k, 1, MAXN - 1, 1, MAXN - 1);
    }
}


void solve() {
    int n, k;
    cin >> n >> k;
    if (k > 16) {
        cout << n << '\n';
        return;
    }
    if (!(n >> k)) {
        cout << n << '\n';
        return;
    } 
    cout << dp[n][k] << '\n';
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    

    precalc();
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
