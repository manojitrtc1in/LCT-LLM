





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



int n,  m, y, e, t, k, q, u1, u2,  w, c, d, x, ans;
const int mx = 400005, mod = 998244353, mx2 = 200005 , mx3 = 100005, INF = 1000000000000000000;
vector<int> prime;
vector<int> spf(10000005, INF);
map<int, int> prime_factor;
vector<int> fact(1005, 1);
vector<int> adj[mx];
vector<int> num_vertex(mx, 1);
vector<pair<int, int>> dp(mx, {0, 0});

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

int binomial(int n, int r) {return (fact[n] * modinv(fact[r]) % mod * modinv(fact[n - r]) % mod) % mod;} 


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

void id0(int num) { 

  while (num > 1) {
    prime_factor[spf[num]]++;
    num /= spf[num];
  }
  return;
}

vector<pii> tre(3000005, {0, 0});


vector<int> a(300005, 0);

void buildTree(int tl, int tr, int treeNode) {
  if (tl == tr) {tre[treeNode] = {a[tl], a[tl]}; return;}
  int tm = (tl + tr) / 2;
  buildTree(tl, tm, 2 * treeNode);
  buildTree((tm + 1), tr, 2 * treeNode + 1);
  tre[treeNode].fi = max(tre[2 * treeNode].fi, tre[2 * treeNode + 1].fi);
  tre[treeNode].se = min(tre[2 * treeNode].se, tre[2 * treeNode + 1].se);
  return;
}

pii query(int tl, int tr, int treeNode, int left, int right) {
  if (left > right) return {0, INF};
  if (left == tl && right == tr) return {tre[treeNode].fi, tre[treeNode].se};
  int tm = (tl + tr) / 2;
  auto ans1 = query(tl, tm, 2 * treeNode, left, min(right, tm));
  auto ans2 = query(tm + 1, tr, 2 * treeNode + 1, max(left, tm + 1), right);
  return {max(ans1.fi, ans2.fi), min(ans1.se, ans2.se)};
}





































void solve() {
  cin >> n; fo(i, n) cin >> a[i];
  

  buildTree(0, n - 1, 1);
  int ind = 0, mov = 0;
  vector<int> index(n + 1, 0);
  fo(i, n) index[a[i]] = i;
  

  

  

  stack<pii> st; vector<int> firstMin(n, n), firstMax(n, n);
  fo(i, n) {
    while (!st.empty() && (st.top().fi > a[i])) {
      firstMin[st.top().se] = i;
      st.pop();
    }

    st.push({a[i], i});
  }

  while (!st.empty()) st.pop();
  fo(i, n) {
    while (!st.empty() && (st.top().fi < a[i])) {
      firstMax[st.top().se] = i;
      st.pop();
    }
    st.push({a[i], i});
  }
  debug(firstMin) debug(firstMax)
  

  

  while (ind < n - 1) {
    int low = ind + 1, high = n - 1, mx_ind = ind, mn_ind = ind;
    if (a[ind] < a[ind + 1]) {
      int pos = firstMin[ind];
      

      auto [mx, mn] = query(0, n - 1, 1, ind, pos - 1);
      

      mx_ind = max(mx_ind, index[mx]);
    }
    else {
      int pos = firstMax[ind];
      

      auto [mx, mn] = query(0, n - 1, 1, ind, pos - 1);
      mn_ind = max(mn_ind, index[mn]);
    }
    int pos = max(mx_ind, mn_ind);
    

    

    

    

    ind = pos;
    mov++;
  }
  cout << mov << nl;
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


