#include "bits/stdc++.h"
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <map>


using namespace __gnu_pbds;
using namespace std;
#define tezi           ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ordered_set    tree<pair<long long, long long>, null_type,less<pair<long long, long long>>, rb_tree_tag,tree_order_statistics_node_update>
#define int            long long
#define ld             long double
#define fo(i,n)        for (int i=0;i<n;i++)
#define fo1(i, n)      for (int i = 1; i < n; i++)
#define MAX(a,b)       (a>b) ? a : b
#define MIN(a,b)       (a>b) ? b : a
#define fi             first
#define nl             "\n"
#define se             second
#define pb             push_back
#define mp             make_pair
#define all(v)         v.begin(), v.end()
#define uniq(v)        v.resize(unique(all(v)) - v.begin())
#define sz(v)          (long long)v.size()
#define pii            pair<int, int>

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x);
#endif

void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(double t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.fi); cerr << ","; _print(p.se); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}



int n,  m, y, e, t, k, q, u1, u2,  w, c, d, x, ans;
const int mx = 400005, mod = 998244353, mx2 = 200005 , mx3 = 100005, INF = 1000000000000000000;
vector<int> prime;
vector<int> spf(10000005, INF);
map<int, int> prime_factor;
vector<int> fact(mx2, 1);
vector<int> BIT(mx2, 0);

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

int modinv(int a) {return fme(a, mod - 2);}

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

void update(int index,  int val) {
  while (index <= 200000) {
    BIT[index] += val;
    index += (index & (-index));
  }
  return;
}

int query(int index) {
  int sum = 0;
  while (index > 0) {
    sum += BIT[index];
    index -= (index & (-index));
  }
  return sum;
}

void solve() {
  cin >> n >> m;
  vector<int> s(n, 0), t(m, 0);
  fo(i, n) cin >> s[i]; fo(i, n) cin >> t[i];
  map<int, int> cnt; fo(i, n) cnt[s[i]]++;
  int val = 1, prod = 1;
  for (auto it : cnt) {
    if (it.se) {
      val = (val * fact[it.se - 1]) % mod;
      prod = (prod * it.se) % mod;
      update(it.fi, it.se);
    }
  }
  

  int start = n - 1, ans = 0;
  fo(i, m) {
    if (i >= n) break;
    int temp = (val * prod) % mod;
    int sm = query(t[i] - 1);
    int vl = fact[start]; start--;
    vl = (vl * modinv(temp)) % mod;
    vl = (vl * sm) % mod;
    ans += vl; ans %= mod;
    if (!cnt[t[i]]) break;
    if (cnt[t[i]] && (i == n - 1) && n < m) ans = (ans + 1) % mod;
    update(t[i], -1);
    if (cnt[t[i]] > 1) {
      prod = (prod * modinv(cnt[t[i]])) % mod; prod = (prod * (cnt[t[i]] - 1)) % mod;
      val = (val * modinv(fact[cnt[t[i]] - 1])) % mod; val = (val * fact[cnt[t[i]] - 2]) % mod;
    }
    cnt[t[i]]--;
    

  }
  cout << ans << nl;
  return;
}

signed main()
{ tezi
# ifndef ONLINE_JUDGE
  

  freopen("input.txt", "r", stdin);
  

  freopen("output.txt", "w", stdout);
  

  freopen("Errors.txt", "w", stderr);
# endif
  for (int i = 1; i < mx2; i++) {
    fact[i] = (fact[i - 1] * i) % mod;
  }
  

  t = 1;
  fo(i, t) solve();
  return 0;
}


