





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



int n,  m, y, e, t, k, q, u1, u2,  w, c, d, x, bgans = 1000000000000000000;
const int mx = 400005, mod = 1000000007, mx2 = 200005 , mx3 = 100005, INF = 1000000000000000000;

int cost = 0;
vector<int> prime;
vector<int> spf(10000005, INF);
map<int, int> prime_factor;
vector<int> adj[mx2];

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

int dfs(int v, int p, int mx, int lvl) {
  int nxt = lvl + 1;
  int leaf = 1;
  int cnt1 = 0, cnt2 = 0, mxx = 0;
  for (auto it : adj[v]) {
    if (it != p) {
      leaf = 0;
      cnt1++;
      int ret = dfs(it, v, mx, lvl + 1);
      

      if ((ret - lvl) > mx || ((ret - lvl) == mx && v != 1)) {
        

        cost += 1;
        cnt2++;
      }
      else mxx = max(mxx, ret);
    }
  }
  

  if (leaf) return lvl;
  if (cnt1 == cnt2) return lvl;
  else return mxx;
}

void solve() {
  cin >> n; vector<int> arr(n, 0); fo(i, n) cin >> arr[i];
  vector<int> cnt(3, 0);
  fo(i, n) {
    int val = (arr[i] * arr[i]) % 3;
    cnt[val]++;
  }
  int cnt2 = 0;
  fo(i, 3) {
    if (cnt[i]) cnt2++;
  }
  if (cnt2 == 1) {
    cout << 1 << nl;
    fo(i, n / 2) cout << 1;
    fo(i, n / 2) cout << 0;
    cout << nl;
  }
  else {
    int x = -1, y = -1;
    fo(i, 3) {
      if (cnt[i]) {
        if (x == -1) x = i;
        else y = i;
      }
    }
    if (cnt[y] > cnt[x]) swap(x, y);
    

    if (x == 1) cout << 0 << nl;
    else cout << 2 << nl;
    cnt2 = n / 2;
    fo(i, n) {
      int val = (arr[i] * arr[i]) % 3;
      if (val == x) {
        if (cnt2) {
          cout << 1; cnt2--;
        }
        else cout << 0;
      }
      else cout << 0;
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


