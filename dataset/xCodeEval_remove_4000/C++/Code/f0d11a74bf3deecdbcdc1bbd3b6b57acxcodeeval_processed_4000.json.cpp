





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



int n,  m, y, e, t, k, q, u1, u2,  w, c, d, x, mx_ind;
const int mx = 400005, mod = 1000000007, mx2 = 200005 , mx3 = 100005, INF = 1000000000000000000;
vector<int> prime;
vector<int> spf(10000005, INF);
map<int, int> prime_factor;
vector<int> dp2(mx, INF);

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

int id0(int a, int b) {
  if (b > a) swap(a, b);
  if (b == 0) {
    x = 1; y = 0;
    return a;
  }
  int gcd = id0(b, a % b);
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

void id1(int num) { 

  while (num > 1) {
    prime_factor[spf[num]]++;
    num /= spf[num];
  }
  return;
}

vector<int> tre(1000005, 0);
vector<int> a(200005, 0);

void buildTree(int tl, int tr, int treeNode) {
  if (tl == tr) {tre[treeNode] = a[tl]; return;}
  int tm = (tl + tr) / 2;
  buildTree(tl, tm, 2 * treeNode);
  buildTree((tm + 1), tr, 2 * treeNode + 1);
  tre[treeNode] = __gcd(tre[2 * treeNode], tre[2 * treeNode + 1]);
  return;
}

int query(int tl, int tr, int treeNode, int left, int right) {
  if (left > right) return 0;
  if (left == tl && right == tr) return tre[treeNode];
  int tm = (tl + tr) / 2;
  int ans1 = query(tl, tm, 2 * treeNode, left, min(right, tm));
  int ans2 = query(tm + 1, tr, 2 * treeNode + 1, max(left, tm + 1), right);
  return __gcd(ans1, ans2);
}

void solve() {
  cin >> n; fo(i, n) cin >> a[i];
  buildTree(0, n - 1, 1);
  int right = -1; vector<int> ans(n, 0);
  fo(i, n) {
    if (i > right) {
      int low = i, high = n - 1;
      while (low <= high) {
        int mid = (low + high) / 2;
        int gcd = query(0, n - 1, 1, i, mid);
        if (gcd == (mid - i + 1)) {
          right = mid;
          break;
        }
        else if (gcd > (mid - i + 1)) low = mid + 1;
        else high = mid - 1;
      }
      if (i > right) {
        if (i > 0) ans[i] = ans[i - 1];
        right = i;
      }
      else {
        ans[right] = 1;
        if (i > 0) ans[i] += ans[i - 1];
      }
    }
    else ans[i] += ans[i - 1];
  }
  fo(i, n) cout << ans[i] << " ";
  cout << endl;
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


