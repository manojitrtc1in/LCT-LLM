#include <algorithm>
#include <numeric>
#include <string>
#include <cstring>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <iostream>
#include <iterator>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <sstream>
#include <utility>
#include <functional>
#include <bitset>
#include <deque>
#include <tuple>

using namespace std;

typedef long long ll;
typedef vector<int> VI;
typedef vector<vector<int> > VVI;
typedef pair<int, int> pii;

#define FOR(i, x, y) for(ll i=x; i<=y; i++)
#define FORD(i, x, y) for (ll i = x; i >= y; --i)
#define REP(i, n) for(ll i=0; i<n; i++)
#define REPD(i, n) for(ll i = n - 1; i >= 0; --i) 

#define ALL(c) (c).begin(), (c).end()
#define SORT(c) sort(ALL(c))
#define UNIQ(c) SORT(c),(c).resize(unique(ALL(c))-(c).begin())
#define SZ(c) (int)(c).size()
#define CONTAINS(s,obj) (s.find(obj)!=s.end())

#define CLEAR(x) memset(x,0,sizeof x)
#define COPY(from,to) memcpy(to, from, sizeof to)

#define sq(x) ((x)*(x))
#define pb push_back
#define mp make_pair
#define X first
#define Y second

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


