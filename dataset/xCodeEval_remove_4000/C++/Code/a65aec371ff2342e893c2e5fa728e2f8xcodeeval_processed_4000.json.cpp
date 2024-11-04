















using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3f;










int gcd(int x, int y){
    if (y == 0){
        return x;
    } else {
        return gcd(y, x % y);
    }
}

ll qmi(ll m, ll k, ll p){

    ll res = 1 % p, t = m;
    while (k){
        if (k&1) res = res * t % p;
        t = t * t % p;
        k >>= 1;
    }
    return res;
}

bool cmp(ld x,ld y){
    if (abs(x-y)<=1e-9)
        return true;
    return false;
}


void solve(){
    int n, m;
    cin >> n >> m;
    string a, b;
    cin >> a >> b;
    if (n == 1){
        cout << (a == b ? "YES" : "NO") << endl;
        return;
    }
    int cnt0 = 0, cnt1 = 0;
    string temp, temp1;
    for (int i = n - m + 1; i < n; i++) {
        temp += a[i];
    }
    for (int i = 1; i < m; i++) {
        temp1 += b[i];
    }


    if (temp == temp1 && m != 1 && a[n - m] == b[0]){
        cout << "YES" << endl;
        return;
    }
    int dif = 0;
    for (int i = 0; i < m; i++) {
        if (temp[i] != temp1[i])
            dif++;
    }
    if (dif){
        cout << "NO" << endl;
        return;
    }
    int ok = 0;
    for (int i = 0; i <= n - m; i++) {
        if (a[i] == b[0]){
            ok = 1;
            break;
        }
    }
    cout << (ok ? "YES" : "NO") << endl;










































}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int kase;
    cin >> kase;
    while (kase--) {
        solve();
    }
    return 0;
}