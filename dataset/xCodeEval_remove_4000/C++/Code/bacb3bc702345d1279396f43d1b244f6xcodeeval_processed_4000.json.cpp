



















using namespace std;

typedef long long ll;
typedef vector<int> VI;
typedef vector<vector<int> > VVI;
typedef pair<int, int> pii;





















const double eps = 1.0e-11;
const double pi = acos(-1.0);
const int MOD = 1000000007;
int n, k, x;




bool Do(int& q, int x) {
  if (x == 4) {
    if (q & 2) {
      q = 4;
      return (q & (1<<k));
    }
  }
  q += x;
  return (q & (1<<k));
}

int main() {
  ios_base::sync_with_stdio(0);
  cin >> n >> k;
  map<int, ll> m;
  m[0] = 1;
  ll ans = 0;
  REP(i, n) {
    cin >> x;
    map<int, ll> curr;
    if (x == 0) {
      ans = (2 * ans) % MOD;
      x = 2;
      for (const auto& v : m) {
        auto tmp = v.first;
        if (Do(tmp, x)) ans = (ans + v.second) % MOD;
        else curr[tmp] = (curr[tmp] + v.second) % MOD;
      }
      x = 4;
      for (const auto& v : m) {
        auto tmp = v.first;
        if (Do(tmp, x)) ans = (ans + v.second) % MOD;
        else curr[tmp] = (curr[tmp] + v.second) % MOD;
      }
    } else {
      for (const auto& v : m) {
        auto tmp = v.first;
        if (Do(tmp, x)) ans = (ans + v.second) % MOD;
        else curr[tmp] = (curr[tmp] + v.second) % MOD;
      }
    }
    m = curr;
  }

  cout << ans << endl;
  return 0;
}


