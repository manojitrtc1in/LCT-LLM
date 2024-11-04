




























using namespace std;
typedef pair<int, int> PII;
typedef pair<string, string> PSS;
typedef pair<string, int> PSI;
typedef pair<int, PII> PIP;
typedef long long ll;
typedef pair<int, ll> PIL;
typedef pair<ll, ll> PLL;
typedef pair<double, double> PDD;
typedef pair<ll, PII> PLP;
template<typename T>
inline T id1() {
  T s = 0, f = 1;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    s = (s << 3) + (s << 1) + ch - 48;
    ch = getchar();
  }
  return s * f;
}





template<class TH>
void _dbg(const char *sdbg, TH h) { cerr << sdbg << '=' << h << endl; }
template<class TH, class... TA>
void _dbg(const char *sdbg, TH h, TA... a) {
  while (*sdbg != ',')cerr << *sdbg++;
  cerr << '=' << h << ',';
  _dbg(sdbg + 1, a...);
}
template<class T>
ostream &operator<<(ostream &os, set<T> V) {
  os << "[";
  for (auto vv : V) os << vv << ",";
  return os << "]";
}
template<class T>
ostream &operator<<(ostream &os, multiset<T> V) {
  os << "[";
  for (auto vv : V) os << vv << ",";
  return os << "]";
}
template<class T>
ostream &operator<<(ostream &os, unordered_set<T> V) {
  os << "[";
  for (auto vv : V) os << vv << ",";
  return os << "]";
}
template<class T>
ostream &operator<<(ostream &os, vector<T> V) {
  os << "[";
  for (auto vv : V) os << vv << ",";
  return os << "]";
}
template<class L, class R>
ostream &operator<<(ostream &os, pair<L, R> P) {
  return os << "(" << P.first << "," << P.second << ")";
}








template<class T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;
template<class T>
using max_heap = priority_queue<T>;


ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }

struct PairHash {
  template<typename T1, typename T2>
  std::size_t operator()(const pair<T1, T2> &p) const {
    return hash<T1>()(p.first) ^ hash<T2>()(p.second);
  }
};

template<unsigned MOD_>
struct ModInt {
  static constexpr unsigned MOD = MOD_;
  unsigned x;
  void undef() { x = (unsigned) -1; }
  bool isnan() const { return x == (unsigned) -1; }
  inline int geti() const { return (int) x; }
  ModInt() { x = 0; }
  ModInt(const ModInt &y) { x = y.x; }
  ModInt(int y) {
    if (y < 0 || (int) MOD <= y) y %= (int) MOD;
    if (y < 0) y += MOD;
    x = y;
  }
  ModInt(unsigned y) { if (MOD <= y) x = y % MOD; else x = y; }
  ModInt(long long y) {
    if (y < 0 || MOD <= y) y %= MOD;
    if (y < 0) y += MOD;
    x = y;
  }
  ModInt(unsigned long long y) { if (MOD <= y) x = y % MOD; else x = y; }
  ModInt &operator+=(const ModInt y) {
    if ((x += y.x) >= MOD) x -= MOD;
    return *this;
  }
  ModInt &operator-=(const ModInt y) {
    if ((x -= y.x) & (1u << 31)) x += MOD;
    return *this;
  }
  ModInt &operator*=(const ModInt y) {
    x = (unsigned long long) x * y.x % MOD;
    return *this;
  }
  ModInt &operator/=(const ModInt y) {
    x = (unsigned long long) x * y.inv().x % MOD;
    return *this;
  }
  ModInt operator-() const { return (x ? MOD - x : 0); }

  ModInt inv() const { return pow(MOD - 2); }
  ModInt pow(long long y) const {
    ModInt b = *this, r = 1;
    if (y < 0) {
      b = b.inv();
      y = -y;
    }
    for (; y; y >>= 1) {
      if (y & 1) r *= b;
      b *= b;
    }
    return r;
  }

  friend ModInt operator+(ModInt x, const ModInt y) { return x += y; }
  friend ModInt operator-(ModInt x, const ModInt y) { return x -= y; }
  friend ModInt operator*(ModInt x, const ModInt y) { return x *= y; }
  friend ModInt operator/(ModInt x, const ModInt y) { return x *= y.inv(); }
  friend bool operator<(const ModInt x, const ModInt y) { return x.x < y.x; }
  friend bool operator==(const ModInt x, const ModInt y) { return x.x == y.x; }
  friend bool operator!=(const ModInt x, const ModInt y) { return x.x != y.x; }
};

const unsigned int mod = 1e9 + 7;
typedef ModInt<mod> mod_int;

template<class M>
struct ModCombination {
 public:
  ModCombination() {}
  ModCombination(int n) : n_(n), fac_(n + 1), facinv_(n + 1) {
    assert(1 <= n);
    fac_[0] = 1;
    for (int i = 1; i <= n; i++) fac_[i] = fac_[i - 1] * i;
    facinv_[n] = M(1) / fac_[n];
    for (int i = n; i >= 1; i--) facinv_[i - 1] = facinv_[i] * i;
  }

  M fac(int k) const {
    assert(0 <= k and k <= n_);
    return fac_[k];
  }
  M facinv(int k) const {
    assert(0 <= k and k <= n_);
    return facinv_[k];
  }
  M inv(int k) const {
    assert(1 <= k and k <= n_);
    return facinv_[k] * fac_[k - 1];
  }

  M P(int n, int k) const {
    if (k < 0 or k > n) return M(0);
    assert(n <= n_);
    return fac_[n] * facinv_[n - k];
  }
  M C(int n, int k) const {
    if (k < 0 or k > n) return M(0);
    assert(n <= n_);
    return fac_[n] * facinv_[n - k] * facinv_[k];
  }
  M H(int n, int k) const {
    if (n == 0 and k == 0) return M(1);
    return C(n + k - 1, n);
  }
  M catalan(int n) const {
    if (n == 0) return M(1);
    return C(2 * n, n) - C(2 * n, n - 1);
  }

 private:
  int n_;
  vector<M> fac_, facinv_;
};

template<typename flow_t = int, typename cost_t = long long>
struct id2 {
  int N;
  std::vector<std::vector<int>> adj;
  struct edge_t {
    int dest;
    flow_t cap;
    cost_t cost;
  };
  std::vector<edge_t> edges;

  std::vector<char> seen;
  std::vector<cost_t> pi;
  std::vector<int> prv;

  explicit id2(int N_) : N(N_), adj(N), pi(N, 0), prv(N) {}

  void addEdge(int from, int to, flow_t cap, cost_t cost) {
    

    assert(cap >= 0);
    assert(cost >= 0); 

    int e = int(edges.size());
    edges.emplace_back(edge_t{to, cap, cost});
    edges.emplace_back(edge_t{from, 0, -cost});
    adj[from].push_back(e);
    adj[to].push_back(e + 1);
  }

  const cost_t INF_COST = std::numeric_limits<cost_t>::max() / 4;
  const flow_t INF_FLOW = std::numeric_limits<flow_t>::max() / 4;
  std::vector<cost_t> dist;
  __gnu_pbds::priority_queue<std::pair<cost_t, int>> q;
  std::vector<typename decltype(q)::point_iterator> its;
  void path(int s) {
    dist.assign(N, INF_COST);
    dist[s] = 0;

    its.assign(N, q.end());
    its[s] = q.push({0, s});

    while (!q.empty()) {
      int i = q.top().second;
      q.pop();
      cost_t d = dist[i];
      for (int e : adj[i]) {
        if (edges[e].cap) {
          int j = edges[e].dest;
          cost_t nd = d + edges[e].cost;
          if (nd < dist[j]) {
            dist[j] = nd;
            prv[j] = e;
            if (its[j] == q.end()) {
              its[j] = q.push({-(dist[j] - pi[j]), j});
            } else {
              q.modify(its[j], {-(dist[j] - pi[j]), j});
            }
          }
        }
      }
    }

    swap(pi, dist);
  }

  std::pair<flow_t, cost_t> maxflow(int s, int t) {
    assert(s != t);
    flow_t totFlow = 0;
    cost_t totCost = 0;
    while (path(s), pi[t] < INF_COST) {
      flow_t curFlow = std::numeric_limits<flow_t>::max();
      for (int cur = t; cur != s;) {
        int e = prv[cur];
        int nxt = edges[e ^ 1].dest;
        curFlow = std::min(curFlow, edges[e].cap);
        cur = nxt;
      }
      totFlow += curFlow;
      totCost += pi[t] * curFlow;
      for (int cur = t; cur != s;) {
        int e = prv[cur];
        int nxt = edges[e ^ 1].dest;
        edges[e].cap -= curFlow;
        edges[e ^ 1].cap += curFlow;
        cur = nxt;
      }
    }
    return {totFlow, totCost};
  }
};

void update(int &v, int nv) {
  if (v < 0 || nv >= 0 && v > nv) v = nv;
}
void update_max(int &v, int nv) {
  v = max(v, nv);
}

void pre_calc() {
}

const int N = 100010;
char s[N];

bool okay(int len, int k) {
  if (len == 0) return true;
  if (k == 0) return false;
  if (len < 2) return false;
  if (k == 1) return len % 2 == 0;
  if (len == 1) return false;
  return true;
}
vector<int> a;
void put(int len, int kk) {
  if (len == 0) return;
  if (len % 2 == 1) {
    a.push_back(2);
    len -= 3;
  }
  for (int i = 0; i < len; i += 2) {
    a.push_back(1);
  }
}

void solve(int ncase) {
  scanf("%s", s);
  int n = strlen(s);
  vector<PII> v;
  for (int i = 0; i < n; i++) {
    if (v.size() && v.back().second == s[i]) {
      v.back().first++;
    } else {
      v.push_back({1, s[i]});
    }
  }
  if (v.size() == 1) {
    if (v[0].second == '
      printf("%d\n%d\n", 1, n);
    } else {
      printf("0\n\n");
    }
    return;
  }
  if (v.back().second == '
    v.push_back({0, '_'});
  }
  int k = n;
  for (int i = 0; i < v.size(); i++) {
    if (v[i].second == '_') {
      if (i == 0 || i + 1 == v.size()) {
        k = min(v[i].first, k);
      } else {
        k = min(v[i].first - 1, k);
      }
    }
  }

  for (int kk = 0; kk <= 4 && kk <= k; kk++) {
    bool flag = true;
    for (int i = 0; i < v.size() && flag; i++) {
      if (v[i].second == '_') {
        if (i == 0 || i + 1 == v.size()) {
          if (!okay(v[i].first - kk, kk)) flag = false;
        } else {
          if (!okay(v[i].first - kk - 1, kk)) flag = false;
        }
      }
    }
    if (!flag) continue;
    a = vector<int>();
    for (int i = 0; i < v.size(); i++) {
      if (v[i].second == '_') {
        if (i == 0 || i + 1 == v.size()) {
          put(v[i].first - kk, kk);
        } else {
          put(v[i].first - kk - 1, kk);
        }
      } else {
        a.push_back(v[i].first + kk);
      }
    }
    printf("%d\n", a.size());
    for (int i = 0; i < a.size(); i++) {
      printf("%d%c", a[i], " \n"[i + 1 == a.size()]);
    }
    return;
  }
  printf("-1\n");
}

void id0() {
  int T = 1;
  

  

  

  int ncase = 0;
  pre_calc();
  while (T--) {
    solve(++ncase);
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cout << std::fixed;
  cout << setprecision(9);

  

  freopen("C:\\Users\\grain\\Desktop\\in.txt", "r", stdin);
  

  

  auto start_time = clock();

  

  id0();
  


  cout << (clock() - start_time) * 1.0 / CLOCKS_PER_SEC << " seconds" << endl;

}

