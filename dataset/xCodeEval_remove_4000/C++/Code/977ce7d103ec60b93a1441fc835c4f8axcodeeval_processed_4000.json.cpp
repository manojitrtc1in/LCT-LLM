





using namespace __gnu_pbds;
using namespace std;
























void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(double t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.fi); cerr << ","; _print(p.se); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}



int n,  m, y, e, t, k, q, u1, u2,  w, c, d, x;
const int mx = 400005, mod = 1000000007, mx2 = 200005 , mx3 = 100005, INF = 1000000000000000000;
vector<int> prime;
vector<int> spf(10000005, INF);
map<int, int> prime_factor;
vector<int> adj[mx2];
vector<int> range[mx2];
int ans = 0;

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

int id1(int a, int b) {
  if (b > a) swap(a, b);
  if (b == 0) {
    x = 1; y = 0;
    return a;
  }
  int gcd = id1(b, a % b);
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

void id2(int num) { 

  while (num > 1) {
    prime_factor[spf[num]]++;
    num /= spf[num];
  }
  return;
}

map<int, int> id0(int x) {
  int num = x;
  map<int, int> store;
  for (int i = 2; i <= sqrt(x); i++) {
    int cnt = 0;
    while ((num % i) == 0) {
      num /= i;
      cnt++;
    }
    if (cnt) store[i] = cnt;
  }
  if (num > 1) store[num]++;
  return store;
}


void solve() {
  cin >> n;
  vector<int> v(n, 0); fo(i, n) cin >> v[i];
  vector<int> pref(n, 0); pref[0] = v[0];
  fo1(i, n) pref[i] = (pref[i - 1] + v[i]);
  cin >> q;
  debug(pref)
  vector<int> dp(n + 1, 0);
  

  dp[0] = v[0];
  fo1(i, n) {
    int excess = (dp[i - 1] * i - pref[i - 1]);
    if (excess >= v[i]) dp[i] = dp[i - 1];
    else {
      excess += dp[i - 1];
      if (excess >= v[i]) dp[i] = dp[i - 1];
      else {
        int rem = v[i] - excess;
        int add = ((rem + i) / (i + 1));
        dp[i] = dp[i - 1] + add;
      }
    }
  }
  debug(dp)
  vector<int> dp2(n, INF);
  

  fo(i, n) {
    int low = dp[i], high = 1e9;
    while (low <= high) {
      int mid = (low + high) / 2;
      int rem = pref[n - 1] - pref[i];
      int excess = excess = ((i + 1) * mid - pref[i]);
      

      if (excess >= rem) {
        high = mid - 1;
        dp2[i] = min(dp2[i], mid);
      }
      else low = mid + 1;
    }
  }
  debug(dp2)
  fo(i, q) {
    cin >> x;
    int low = 0, high = n - 1;
    int ans = INF;
    while (low <= high) {
      int mid = (low + high) / 2;
      if (dp2[mid] > x) low = mid + 1;
      else {
        ans = min(ans, mid + 1);
        high = mid - 1;
      }
    }
    if (ans == INF) ans = -1;
    cout << ans << nl;
  }
  return;
}

signed main()
{ tezi

  

  freopen("input.txt", "r", stdin);
  

  freopen("output.txt", "w", stdout);
  

  freopen("Errors.txt", "w", stderr);

  

  t = 1;
  fo(i, t) solve();
  return 0;
}


