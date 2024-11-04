

























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

ll zxc = 1, x[N];

void solve() {
    ll n, a, c, ans = 0;
    cin >> n;
    for(ll i = 3; i <= n; i += 2) {
        a = i, c = (sq(i) + 1) / 2;
        if(c > n) break;
        else ans++;
    }
    cout << ans << "\n";
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




     			   	 	  			 	 	 				 		