













using namespace std;




const int MOD = 1000000007;

inline ll p(ll x, ll y) {
  x %= MOD;
  ll ans = 1;
  while (y) {
    if (y & 1) ans = ans * x % MOD;
    x = x * x % MOD;
    y >>= 1;
  }
  return ans;
}

inline ll inv(ll x) {
  return p(x, MOD - 2);
}

inline void solve() {
  int n; cin >> n;
  vector<int> arr(n); for (int i = 0; i < n; ++i) cin >> arr[i];
  int ans = 0, last = -1;
  for (int i = 0; i < n; ++i) {
    int _xor = 0;
    for (int j = i - 1; j > last; --j) {
      if (_xor == arr[i]) {
        last = i;
        break;
      }
      _xor ^= arr[j];
    }
    if (last == i) continue;
    if (_xor == arr[i]) {
      last = i;
      continue;
    }
    ++ans;
  }
  cout << ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  int t = 1;
  cin >> t;
  for (int i = 0; i < t; ++i) solve();
  return 0;
}
