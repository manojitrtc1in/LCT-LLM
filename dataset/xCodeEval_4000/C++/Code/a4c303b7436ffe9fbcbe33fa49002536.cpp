

#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <utility>
#include <algorithm>
#include <climits>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

#define ll long long
#define pii pair<int, int>

const int MOD = 998244353;

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
  string str; cin >> str;
  int n = str.size();
  vector<int> fix = {0, 2, 4, 1, 1, 4, 2, 0};
  vector<int> brk = {0, 0, 0, 6, 6, 0, 0, 0};
  vector<ll> dp(64); dp[0] = 1;
  for (int i = 0; i < n; ++i) {
    vector<ll> ndp(64);
    bool bit = str[i] - '0';
    for (int t = 0; t < 8; ++t) {
      if (bit) {
        int flip = t ^ 7;
        for (int l = 0; l < 8; ++l) {
          for (int sat = 0; sat < 8; ++sat) {
            if ((sat & brk[t]) != brk[t]) continue;
            int nw = sat | fix[t];
            int nl = l | flip;
            ndp[(nw << 3) + nl] = (ndp[(nw << 3) + nl] + dp[(sat << 3) + l]) % MOD;
          }
        }
      } else {
        for (int l = 0; l < 8; ++l) {
          if ((t & l) != t) continue;
          for (int sat = 0; sat < 8; ++sat) {
            if ((sat & brk[t]) != brk[t]) continue;
            int nw = sat | fix[t];
            ndp[(nw << 3) + l] = (ndp[(nw << 3) + l] + dp[(sat << 3) + l]) % MOD;
          }
        }
      }
    }
    dp = ndp;
  }
  int add = (7 << 3);
  ll ans = 0;
  for (int i = 0; i < 8; ++i) ans = (ans + dp[add + i]) % MOD;
  ans *= 3;
  cout << ans % MOD << '\n';
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  int t = 1;
  for (int i = 0; i < t; ++i) solve();
  return 0;
}
