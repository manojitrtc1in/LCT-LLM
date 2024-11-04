#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <map>


using namespace __gnu_pbds;
using namespace std;
#define tezi           ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ordered_set    tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define int            long long
#define fo(i,n)        for (int i=0;i<n;i++)
#define fo1(i, n)      for (int i = 1; i < n; i++)
#define endl           "\n"
#define MAX(a,b)       (a>b) ? a : b
#define MIN(a,b)       (a>b) ? b : a
#define fi             first
#define se             second
#define pb             push_back
#define mp             make_pair
#define all(v)         v.begin(), v.end()
#define uniq(v)        v.resize(unique(all(v)) - v.begin())
#define sz(v)          v.size()
#define pii            pair<int, int>

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "<< x << endl;
#else
#define debug(x);
#endif

int n,  m, y, e, t, k, q, u1, u2,  w, v, c, d, x, a, b;
const int mx = 400005, mod = 1LL << 32, mx2 = 300005 , mx3 = 100005, INF = 1000000000000000000;
vector<int> prime;
vector<int> spf(100005, INF);
map<int, int> prime_factor;
vector<int> ans(mx2, 0);

int setBit(int n) {
  int count = 0;
  while (n) {n = n & (n - 1); count += 1;}
  return count;
}

int fme(int a, int b) {
  int rest = 1;
  while (b) {
    if (b & 1) rest = ((int)1 * rest * a + mod) % mod;
    a = (a * a) % mod;
    b = b >> 1;
  }
  return rest;
}

int btod(string s) {
  int len = s.length(), cur = 0, ind = 0;
  for (int i = (len - 1); i >= 0; i--) {
    if (s[i] == '1') cur += pow(2, ind);
    ind++;
  }
  return cur;
}

int extended_euclid(int a, int b) {
  if (b > a) swap(a, b);
  if (b == 0) {
    x = 1; y = 0;
    return a;
  }
  int gcd = extended_euclid(b, a % b);
  int lastx = x, lasty = y;
  x = lasty;
  y = lastx - (a / b) * lasty;
  return gcd;
}

void sieve(int mx) { 

  vector<int> v(mx, 1);
  v[0] = 0, v[1] = 0;
  for (int i = 2; i < mx; i++) {
    if (v[i]) {
      for (int j = i * i; j < mx; j += i) v[j] = 0;
    }
  }
  for (int i = 2; i < mx; i++) {
    if (v[i]) prime.pb(i);
  }
  return;
}

void SPF(int mx) { 

  spf[1] = 1;
  for (int i = 2; i < mx; i ++) {
    if (spf[i] == INF) {
      spf[i] = i;
      for (int j = i * i; j < mx; j += i) spf[j] = min(spf[j], i);
    }
  }
}

void prime_factorisation(int num) { 

  while (num > 1) {
    prime_factor[spf[num]]++;
    num /= spf[num];
  }
  return;
}

void prime_factorisation2(int num) { 

  while (num > 1) {
    prime_factor[spf[num]]++;
    num /= spf[num];
  }
  return;
}

bool comp(pair<int, pair<int, char>> p1, pair<int, pair<int, char>> p2) {
  if (p1.se.fi < p2.se.fi) return true;
  return false;
}

bool comp2(pair<int, int> p1, pair<int, int> p2) {
  if (p1.fi < p2.fi) return true;
  return false;
}

void helper(vector<pair<int, pair<int, char>>> &arr) {
  set<pair<int, int>> left, right;
  for (auto it : arr) {
    if (it.se.se == 'R') right.insert({it.se.fi, it.fi});
    else left.insert({it.se.fi, it.fi});
  }
  for (auto it = right.rbegin(); it != right.rend(); it++) {
    auto gt = *it;
    auto it2 = left.lower_bound(gt);
    if (it2 != left.end()) {
      auto gt2 = *it2;
      int time = (gt.fi + gt2.fi) / 2 - gt.fi;
      debug(time)
      ans[gt.se] = time; ans[gt2.se] = time;
      left.erase(it2);
    }
  }
  vector<pair<int, int>> vleft, vright;
  for (auto it : left) vleft.pb(it);
  for (auto it : right) if (ans[it.se] == 0) vright.pb(it);
  sort(all(vleft), comp2); sort(all(vright), comp2);
  for (int i = 0; i < sz(vleft); i += 2) {
    if (i + 1 >= sz(vleft)) break;
    auto pos1 = vleft[i].fi, pos2 = vleft[i + 1].fi;
    pos2 -= pos1; int time = pos1; pos1 = 0;
    time += (pos2 / 2); ans[vleft[i].se] = time; ans[vleft[i + 1].se] = time;
  }

  for (int i = sz(vright) - 2; i >= 0 ; i -= 2) {
    if (i + 1 >= sz(vright)) break;
    auto pos1 = vright[i].fi, pos2 = vright[i + 1].fi;
    pos1 += (m - pos2); int time = (m - pos2); pos2 = m;
    time += ((pos2 + pos1) / 2 - pos1); ans[vright[i].se] = time; ans[vright[i + 1].se] = time;
  }
  if (sz(vleft) % 2 && sz(vright) % 2) {
    auto it1 = vleft[sz(vleft) - 1], it2 = vright[0];
    if (it1.fi >= (m - it2.fi)) {
      int pos1 = 0, time = it1.fi;
      int pos2 = m; int rem = (it1.fi - (m - it2.fi)); pos2 -= rem;
      time += ((pos1 + pos2) / 2 - pos1);
      ans[it1.se] = time; ans[it2.se] = time;
    }
    else {
      int pos2 = m, time = m - it2.fi;
      int pos1 = 0; int rem = ((m - it2.fi) - it1.fi); pos1 += rem;
      time += ((pos1 + pos2) / 2 - pos1);
      ans[it1.se] = time; ans[it2.se] = time;
    }
  }
  else if (sz(vleft) % 2) ans[vleft[sz(vleft) - 1].se] = -1;
  else if (sz(vright) % 2) ans[vright[0].se] = -1;
  return;
}

void solve() {
  cin >> n >> m;
  vector<int> x(n, 0); fo(i, n) cin >> x[i];
  vector<char> move(n, 0); fo(i, n) cin >> move[i];
  vector<pair<int, pair<int, char>>> odd, even;
  fo(i, n) ans[i] = 0;
  fo(i, n) {
    if (x[i] % 2) odd.pb({i, {x[i], move[i]}});
    else even.pb({i, {x[i], move[i]}});
  }
  sort(all(odd), comp); sort(all(even), comp);
  helper(odd); helper(even);
  fo(i, n) cout << ans[i] << " ";
  cout << endl;
  return;
}

signed main()
{ tezi
# ifndef ONLINE_JUDGE
  

  freopen("input.txt", "r", stdin);
  

  freopen("output.txt", "w", stdout);
  

  freopen("Errors.txt", "w", stdout);
# endif
  cin >> t;
  fo(i, t) solve();
  return 0;
}


