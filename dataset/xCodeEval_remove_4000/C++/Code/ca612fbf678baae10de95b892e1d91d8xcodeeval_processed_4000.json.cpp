





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

vector<int> BIT(mx, 0);
vector<int> arr(mx, 0);

void update(int index,  int val) {
  while (index <= n) {
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
  cin >> n >> k; vector<int> arr1(n + 1, 0); fo1(i, n + 1) cin >> arr1[i];
  fo(i, n + 1) BIT[i] = 0;
  fo1(i, n + 1) {
    arr[i] = 1;
    update(i, 1);
  }
  vector<int> cnt(n + 1, 0); fo1(i, n + 1) cnt[arr1[i]]++;
  fo1(i, n + 1) cnt[i] += cnt[i - 1];
  

  int comp = n;
  vector<int> store[n + 1];
  fo1(i, n + 1) store[arr1[i]].pb(i);
  int l = *min_element(arr1.begin() + 1, arr1.end()); int r = l;
  int L, R, anss = INF;
  while (l <= r && r <= n) {
    int cur_ans = cnt[r] - cnt[l - 1];
    int rest = n - cur_ans;
    int there = cur_ans - rest;
    

    if (there >= k) {
      if (r - l + 1 < anss) {
        anss = r - l + 1;
        L = l; R = r;
      }
      l++;
    }
    else r++;
  }
  cout << L << " " << R << endl;
  vector<vector<int>> ans;
  int sm = 0, last = 1;
  fo1(i, n + 1) {
    if (k == 1) {
      ans.pb({last, n});
      break;
    }
    sm += (arr1[i] >= L && arr1[i] <= R ? 1 : -1);
    if (sm > 0) {
      sm = 0;
      ans.pb({last, i});
      last = i + 1;
      k--;
    }
  }
  for (auto it : ans) cout << it[0] << " " << it[1] << endl;
  return;
}

signed main()
{ tezi

  

  freopen("input.txt", "r", stdin);
  

  freopen("output.txt", "w", stdout);
  

  freopen("Errors.txt", "w", stderr);

  cin >> t;
  fo(i, t) solve();
  return 0;
}


