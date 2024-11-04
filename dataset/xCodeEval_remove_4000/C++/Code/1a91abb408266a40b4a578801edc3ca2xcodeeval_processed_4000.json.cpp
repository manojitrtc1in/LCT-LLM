





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

int n,  m, y, e, t, k, q, u1, u2,  w, v, c, d, x, b;
const int mx = 400005, mod = 1LL << 32, mx2 = 200005 , mx3 = 100005, INF = 1000000000000000000;
vector<int> prime;
vector<int> spf(100005, INF);
map<int, int> prime_factor;
int n1, n2, k1, k2;
vector<vector<vector<vector<int>>>> dp(105, vector<vector<vector<int>>> (105, vector<vector<int>> (15, vector<int> (15, -1))));

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

void id0(int num) { 

  while (num > 1) {
    prime_factor[spf[num]]++;
    num /= spf[num];
  }
  return;
}

void solve() {
  cin >> k; string s; cin >> s;
  int n = sz(s); vector<vector<int>> dp(n + 5, vector<int> (2, 0));
  int start = 0, end = ((1 << (k - 1)) - 1), cur = k - 1, prev = 0; int ans = 0;
  int last_start = -1;
  unordered_map<int, int> forward, backward;
  fo(i, n) {
    if (i >= start && i <= end) {
      if (start == 0) {
        forward[i] = -1;
        if (s[i] == '0') dp[i] = {1, 0};
        else if (s[i] == '1') dp[i] = {0, 1};
        else dp[i] = {1, 1};
      }
      else {
        int pos = last_start + (2 * prev);
        forward[i] = pos;
        backward[pos] = i;
        backward[pos + 1] = i;
        debug(pos)
        if (s[i] == '0') {
          dp[i][0] += (dp[pos][0] + dp[pos][1]);
        }
        else if (s[i] == '1') {
          dp[i][1] += (dp[pos + 1][0] + dp[pos + 1][1]);
        }
        else {
          dp[i][0] += (dp[pos][0] + dp[pos][1]);
          dp[i][1] += (dp[pos + 1][0] + dp[pos + 1][1]);
        }
      }
      prev++;
    }
    else {
      cur--; prev = 0;
      last_start = start;
      start = i, end = (i + (1 << cur) - 1);
      int pos = last_start + (2 * prev);
      forward[i] = pos;
      backward[pos] = i;
      backward[pos + 1] = i;
      debug(pos)
      if (s[i] == '0') {
        dp[i][0] += (dp[pos][0] + dp[pos][1]);
      }
      else if (s[i] == '1') {
        dp[i][1] += (dp[pos + 1][0] + dp[pos + 1][1]);
      }
      else {
        dp[i][0] += (dp[pos][0] + dp[pos][1]);
        dp[i][1] += (dp[pos + 1][0] + dp[pos + 1][1]);
      }
      prev = 1;
    }
    debug(start) debug(end)
  }
  fo(i, n) {
    debug(i) debug(dp[i])
  }
  backward[n - 1] = -1;
  cin >> q;
  fo(i, q) {
    cin >> u1; char e; cin >> e; u1--;
    if (s[u1] == e) {
      cout << dp[n - 1][0] + dp[n - 1][1] << endl;
    }
    else {
      s[u1] = e;
      int pos = forward[u1];
      if (pos != -1) {
        if (s[u1] == '0') {
          dp[u1][0] = (dp[pos][0] + dp[pos][1]);
          dp[u1][1] = 0;
        }
        else if (s[u1] == '1') {
          dp[u1][1] = (dp[pos + 1][0] + dp[pos + 1][1]);
          dp[u1][0] = 0;
        }
        else {
          dp[u1][0] = (dp[pos][0] + dp[pos][1]);
          dp[u1][1] = (dp[pos + 1][0] + dp[pos + 1][1]);
        }
      }
      else {
        if (s[u1] == '0') dp[u1] = {1, 0};
        else if (s[u1] == '1') dp[u1] = {0, 1};
        else dp[u1] = {1, 1};
      }
      debug(pos)
      debug(dp[u1])
      int pos2 = backward[u1];
      debug(pos2)
      if (pos2 == -1) {
        cout << dp[n - 1][0] + dp[n - 1][1] << endl;
      }
      else {
        while (pos2 != -1) {
          int pos3 = forward[pos2];
          if (s[pos2] == '0') {
            dp[pos2][0] = (dp[pos3][0] + dp[pos3][1]);
            dp[pos2][1] = 0;
          }
          else if (s[pos2] == '1') {
            dp[pos2][1] = (dp[pos3 + 1][0] + dp[pos3 + 1][1]);
            dp[pos2][0] = 0;
          }
          else {
            dp[pos2][0] = (dp[pos3][0] + dp[pos3][1]);
            dp[pos2][1] = (dp[pos3 + 1][0] + dp[pos3 + 1][1]);
          }
          pos2 = backward[pos2];
        }
        cout << dp[n - 1][0] + dp[n - 1][1] << endl;
      }
      debug(dp[u1])
    }
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


