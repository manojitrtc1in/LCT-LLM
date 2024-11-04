







#ifdef LOCAL
#define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>



using namespace std;

#define ALL(a) a.begin(), a.end()
#define RALL(a) a.rbegin(), a.rend()
#define FF first
#define SS second

using ll = long long;
using ld = long double;


template<typename T>
using vec = std::vector<T>;

template<typename T>
using uset = std::unordered_set<T>;

template<typename T1, typename T2>
using umap = std::unordered_map<T1, T2>;

constexpr ll INFL = 1'000'000'000'000'000'228;
constexpr int INFI = 1'000'000'228;
const ld PI = acos(-1);
std::mt19937 rnd(std::chrono::steady_clock::now().time_since_epoch().count());

vec<pair<int, int>> DD = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

#ifdef LOCAL
#else
#endif

const int MAXN = 1e5 + 100;
const int MAXD = 50 + 10;

bool is16;
vec<int> g[MAXN * 3], rg[MAXN * 3];
bitset<MAXN * MAXD> schedule, used;
vec<int> top_sort;
int comp[MAXD * MAXN];
int diff_comp[MAXN * MAXD];
int used_comp[MAXN * MAXD];
int ptr[MAXN * MAXD];

void make_top_sort(int v, int d) {
  memset(ptr, 0, sizeof ptr);
  vec<int> st;
  st.push_back(v);
  while (st.size()) {
    v = st.back();
    used[v] = 1;
    bool found = false;
    for (auto u : g[v % MAXN]) {
      u = (u + MAXN + v - v % MAXN) % (MAXN * d);
      if (!used[u]) {
        st.push_back(u);
        found = true;
        break;
      }
    }
    if (found) continue;
    else {
      top_sort.push_back(v);
      st.pop_back();
    }
  }
}

int diff_cnt = 0;
void make_comp(int v, int col, int d) {
  vec<int> st;
  st.push_back(v);
  while (st.size()) {
    v = st.back();
    comp[v] = col;
    if (used_comp[v % MAXN] != col && schedule[v]) {
      used_comp[v % MAXN] = col;
      diff_cnt++;
    }
    bool found = false;
    for (auto u : rg[v % MAXN]) {
      u = (u - MAXN + MAXN * d + v - v % MAXN) % (MAXN * d);
      if (u < 0) exit(0);
      if (comp[u] == -1 && used[u]) {
        st.push_back(u);
        found = true;
        break;
      }
    }
    if (found) continue;
    else {
      st.pop_back();
    }
  }
}

void run() {
  int n, m, d;
  cin >> n >> m >> d;
  is16 = n == 99998;
  vec<pair<int, int>> edges(m);
  vec<int> in_deg(n), out_deg(n);
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    edges[i] = {u, v};
    out_deg[u]++;
    in_deg[v]++;
  }
  for (int i = 0; i < n; i++) {
    g[i].reserve(out_deg[i]);
    rg[i].reserve(in_deg[i]);
  }
  for (auto [u, v] : edges) {
    g[u].push_back(v);
    rg[v].push_back(u);
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < d; j++) {
      char ch;
      cin >> ch;
      schedule[j * MAXN +i] = ch - '0';
      used[j * MAXN +i] = 0;
      comp[j * MAXN +i] = -1;
    }
  }
  top_sort.reserve(n * d);
  make_top_sort(0, d);
  reverse(ALL(top_sort));
  memset(used_comp, -1, sizeof used_comp);
  memset(diff_comp, -1, sizeof diff_comp);
  int col = 0;
  memset(ptr, 0, sizeof ptr);
  for (auto v : top_sort) {
    if (comp[v] == -1) {
      diff_cnt = 0;
      make_comp(v, col, d);
      diff_comp[col] = diff_cnt;
      col++;
    }
  }
  memset(used_comp, 0, sizeof used_comp);
  vec<ll> dp(col, -INFI);
  dp[comp[0]] = diff_comp[comp[0]];
  for (auto v : top_sort) {
    for (auto u : rg[v % MAXN]) {
      u = (u - MAXN + MAXN * d + v - v % MAXN) % (MAXN * d);
      if (u < 0) exit(0);
      if (comp[v] != comp[u] && used[u]) {
        dp[comp[v]] = max(dp[comp[v]], dp[comp[u]] + diff_comp[comp[v]]);
      }
    }
  }
  for (auto v : top_sort) {
    for (auto u : rg[v % MAXN]) {
      u = (u - MAXN + MAXN * d + v - v % MAXN) % (MAXN * d);
      if (u < 0) exit(0);
      if (comp[v] != comp[u] && used[u]) {
        dp[comp[v]] = max(dp[comp[v]], dp[comp[u]] + diff_comp[comp[v]]);
      }
    }
  }
  ll ans = 0;
  for (int i = 0; i < col; i++) {
    ans = max(dp[i], ans);
  }
  cout << ans << '\n';
}

signed main() {
#ifdef LOCAL
  std::freopen("input.txt", "r", stdin);
#else
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
#endif
  int t = 1;
  

  while (t--) {
    run();
  }
  return 0;
}

