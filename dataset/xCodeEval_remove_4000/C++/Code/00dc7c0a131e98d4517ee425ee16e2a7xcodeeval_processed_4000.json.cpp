

























using namespace std;
typedef long long ll;



const long double Pi = acos(-1.0);
const ll dx[] = {0,0,1,-1};
const ll dy[] = {1,-1,0,0};
const ll N = (ll) 1e6 + 17;
const ll M = (ll) 5e3 + 69;
const ll inf = (ll) 1e14 + 3;
const ll mod = (ll) 1e9 + 7;
ll sq(ll x) { return x * x; }

ll zxc = 1, a[N];

ll f(ll x) {
    ll pw = 1;
    while(pw <= x) pw *= 10;
    return pw / 10;
}

void solve() {
    ll n, s;
    cin >> s >> n;
    s -= n;
    for(ll i = 1; i <= n; i++) {
        s++, a[i] = f(s), s -= f(s);
    }
    a[1] += s;
    for(ll i = 1; i <= n; i++) cout << a[i] << " ";
    cout << "\n";
}

int main() {
ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> zxc;
    while(zxc--) {
        solve();
    }
  	return 0;
}


