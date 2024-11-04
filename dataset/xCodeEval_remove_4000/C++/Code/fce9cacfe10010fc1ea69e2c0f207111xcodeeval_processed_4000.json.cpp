





































  int T;         \
  std::cin >> T; \
  while (T--)



void dbg_out() { std::cerr << std::endl; }
template <typename Head, typename... Tail>
void dbg_out(Head H, Tail... T) {
  std::cerr << " " << H;
  dbg_out(T...);
}




[[noreturn]] void fail_exit(int line) { exit(line); }



using ll = int64_t;
using ull = uint64_t;
using pii = std::pair<int, int>;
using tiii = std::tuple<int, int, int>;


using namespace std::string_literals;
using namespace std::string_view_literals;

namespace OfficialTutorial {


using namespace std;
template <typename T>
void read(T& x) {
  static char c;
  static int f;
  for (c = ch(), f = 1; c < '0' || c > '9'; c = ch())
    if (c == '-') f = -f;
  for (x = 0; c >= '0' && c <= '9'; c = ch()) x = x * 10 + (c & 15);
  x *= f;
}
template <typename T>
void write(T x) {
  static char q[65];
  int cnt = 0;
  if (x < 0) pc('-'), x = -x;
  q[++cnt] = x % 10, x /= 10;
  while (x) q[++cnt] = x % 10, x /= 10;
  while (cnt) pc(q[cnt--] + '0');
}
const int maxn = 100005, maxm = 200005;
int par[maxn];
int AC(int x) { return par[x] == x ? x : par[x] = AC(par[x]); }
struct Edge {
  int v, nt;
  Edge(int v = 0, int nt = 0) : v(v), nt(nt) {}
} e[maxn * 2], es[maxm];
int hd[maxn], num;
void qwq(int u, int v) { e[++num] = Edge(v, hd[u]), hd[u] = num; }
int dp[maxn];
int pa[maxn][20];
void dfs(int u, int p) {
  pa[u][0] = p;
  for (int j = 1; (1 << j) <= dp[u]; ++j) pa[u][j] = pa[pa[u][j - 1]][j - 1];
  for (int i = hd[u]; i; i = e[i].nt) {
    int v = e[i].v;
    if (v == p) continue;
    dp[v] = dp[u] + 1;
    dfs(v, u);
  }
}
int jump(int x, int t) {
  for (int cn = 0; t; t >>= 1, ++cn)
    if (t & 1) x = pa[x][cn];
  return x;
}
int lca(int x, int y) {
  if (dp[x] > dp[y]) x = jump(x, dp[x] - dp[y]);
  if (dp[y] > dp[x]) y = jump(y, dp[y] - dp[x]);
  if (x == y) return x;
  for (int t = 19; t >= 0; --t)
    if (pa[x][t] != pa[y][t]) x = pa[x][t], y = pa[y][t];
  return pa[x][0];
}
int getSon(int u) {
  for (int i = hd[u]; i; i = e[i].nt)
    if (pa[e[i].v][0] != u) return e[i].v;
  assert(false);
}
int vis[maxn];
char s[maxn];
void pushdown(int u, int p) {
  if (vis[u] == 0)
    s[u] = '1';
  else
    s[u] = '0';
  for (int i = hd[u]; i; i = e[i].nt) {
    int v = e[i].v;
    if (v == p) continue;
    vis[v] += vis[u];
    pushdown(v, u);
  }
}
int main(int n, int m) {

  freopen("testdata.in", "r", stdin);

  for (int i = 1; i <= n; ++i) par[i] = i;
  int tp = 0;
  for (int i = 1; i <= m; ++i) {
    int u, v;
    std::cin >> u >> v;
    if (AC(u) == AC(v)) {
      es[++tp] = Edge(u, v);
    } else {
      par[AC(u)] = AC(v);
      qwq(u, v), qwq(v, u);
    }
  }
  int root = 1;
  dfs(root, 0);
  for (int i = 1; i <= tp; ++i) {
    int u = es[i].v, v = es[i].nt;
    if (dp[u] > dp[v]) std::swap(u, v);
    int w = lca(u, v);
    

    if (u == w) {
      --vis[v];
      ++vis[jump(v, dp[v] - dp[u] - 1)];
    } else {
      ++vis[root];
      --vis[u];
      --vis[v];
    }
  }
  pushdown(root, 0);
  s[n + 1] = '\0';
  for (int i = 1; i <= n; ++i) std::cout << s[i];
  std::cout << "\n";
  return 0;
}
}  


void read() {}
template <typename T, typename... Targs>
void read(T& x, Targs&... args) {
  x = 0;
  bool flag = false;
  char ch = char(std::cin.get());
  while (!isdigit(ch)) {
    if (ch == '-') flag = true;
    ch = char(std::cin.get());
  }
  while (isdigit(ch)) {
    x = x * 10 + ch - 48;
    ch = char(std::cin.get());
  }
  if (flag) x *= -1;
  read(args...);
}

template <typename T>
void qprint(T x) {
  if (x < 0) std::cout.put('-'), x = -x;
  if (x > 9) qprint(x / 10);
  std::cout.put(char(x % 10 + 48));
}

template <char end = '\n', typename... Targs>
void print(const Targs&... args) {
  ((qprint(args), std::cout.put(' ')), ...);
  std::cout.put(end);
}



struct Edge {
  int u, v, w, id;
  Edge() = default;
  Edge(int u, int v, int w, int id) : u(u), v(v), w(w), id(id) {}
};

void solution() {
  int n, m;
  read(n, m);
  std::vector<Edge> edges(m + 1);
  for (int i = 1; i <= m; ++i) {
    int u, v;
    read(u, v);
    int w = i;
    edges[i] = Edge(u, v, w, i);
  }
  std::sort(edges.begin() + 1, edges.end(),
            [](const Edge& a, const Edge& b) { return a.w < b.w; });
  std::vector<int> fa(n + 1);
  for (int i = 1; i <= n; ++i) fa[i] = i;
  std::function<int(int)> find = [&](int x) {
    return x == fa[x] ? x : fa[x] = find(fa[x]);
  };
  std::vector<Edge> mstEdges, otherEdges;
  int cnt = 0;
  for (int i = 1; i <= m; ++i) {
    int u = edges[i].u, v = edges[i].v;
    int U = find(u), V = find(v);
    if (U != V) {
      fa[U] = V;
      ++cnt;
      assert(cnt <= n - 1);
      mstEdges.push_back(edges[i]);
      if (cnt > n - 1) assert(false);
    } else {
      otherEdges.push_back(edges[i]);
    }
  }
  std::vector<std::vector<int>> g(n + 1);
  for (auto [u, v, w, id] : mstEdges) {
    g[u].push_back(v);
    g[v].push_back(u);
  }
  logs("kruscal ed");

  const int root = 1;
  std::vector<std::array<int, 21>> parent(n + 1);
  std::vector<int> depth(n + 1);

  std::function<void(int, int)> id0 = [&](int u, int fa) {
    parent[u][0] = fa;
    for (int i = 1; 1 << i <= depth[u]; ++i)
      parent[u][i] = parent[parent[u][i - 1]][i - 1];
    for (auto v : g[u])
      if (v != fa) {
        depth[v] = depth[u] + 1;
        id0(v, u);
      }
  };
  id0(root, -1);
  auto jump = [&](int u, int step) {
    for (int power = 0; step && power <= 20; step >>= 1, ++power)
      if (step & 1) u = parent[u][power];
    return u;
  };
  auto id1 = [&](int u, int v) {
    if (depth[u] > depth[v]) std::swap(u, v);
    for (int i = 20; i >= 0; --i)
      if (depth[v] >= depth[u] + (1 << i)) v = parent[v][i];
    if (u == v) return u;
    for (int i = 20; i >= 0; --i)
      if (parent[u][i] != parent[v][i]) {
        u = parent[u][i];
        v = parent[v][i];
      }
    return parent[u][0];
  };
  logs("inited lca");

  std::vector<int> diff(n + 1);
  for (auto [u, v, w, id] : otherEdges) {
    if (depth[u] > depth[v]) std::swap(u, v);
    int lca = id1(u, v);
    dbg(u, v, lca);
    if (u != lca) {
      ++diff[root];
      --diff[u];
      --diff[v];
    } else {
      --diff[v];
      ++diff[jump(v, depth[v] - depth[u] - 1)];
    }
  }
  logs("inited diff array");

  std::string ans = std::string(n + 1, '?');
  std::vector<int> a(n + 1);
  for (int i = 1; i <= n; ++i) a[i] = diff[i];
  auto pushdown = [&](auto self, int u, int fa) -> void {
    if (fa != -1) diff[u] += diff[fa];
    if (diff[u] == 0)
      ans[u] = '1';
    else
      ans[u] = '0';
    for (auto v : g[u])
      if (v != fa) self(self, v, u);
  };
  pushdown(pushdown, root, -1);
  std::cout << ans.substr(1) << std::endl;
}



signed main() {

  logs(std::string_view(__FILE__).substr(
      std::string_view(__FILE__).rfind("\\") + 1));
  freopen("testdata.in", "r", stdin);
  



  freopen("testdata.log", "w", stderr);

  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  solution();

  std::clog << "\ntime: " << std::fixed << std::setprecision(3)
            << clock() * 1000.0 / CLOCKS_PER_SEC << "ms\n";

}

const std::string picture = R"(
 *  ┌───┐   ┌───┬───┬───┬───┐ ┌───┬───┬───┬───┐ ┌───┬───┬───┬───┐ ┌───┬───┬───┐
 *  │Esc│   │ F1│ F2│ F3│ F4│ │ F5│ F6│ F7│ F8│ │ F9│F10│F11│F12│ │P/S│S L│P/B│  ┌┐    ┌┐    ┌┐
 *  └───┘   └───┴───┴───┴───┘ └───┴───┴───┴───┘ └───┴───┴───┴───┘ └───┴───┴───┘  └┘    └┘    └┘
 *  ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┐ ┌───┬───┬───┐ ┌───┬───┬───┬───┐
 *  │~ `│! 1│@ 2│
 *  ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┤ ├───┼───┼───┤ ├───┼───┼───┼───┤
 *  │ Tab │ Q │ W │ E │ R │ T │ Y │ U │ I │ O │ P │{ [│} ]│ | \ │ │Del│End│PDn│ │ 7 │ 8 │ 9 │   │
 *  ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┤ └───┴───┴───┘ ├───┼───┼───┤ + │
 *  │ Caps │ A │ S │ D │ F │ G │ H │ J │ K │ L │: ;│" '│ Enter  │               │ 4 │ 5 │ 6 │   │
 *  ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────────┤     ┌───┐     ├───┼───┼───┼───┤
 *  │ Shift  │ Z │ X │ C │ V │ B │ N │ M │< ,│> .│? /│  Shift   │     │↑ │     │ 1 │ 2 │ 3 │   │
 *  ├─────┬──┴─┬─┴──┬┴───┴───┴───┴───┴───┴──┬┴───┼───┴┬────┬────┤ ┌───┼───┼───┐ ├───┴───┼───┤ E││
 *  │ Ctrl│    │Alt │         Space         │ Alt│    │    │Ctrl│ │← │↓ │→ │ │   0   │ . │←┘│
 *  └─────┴────┴────┴───────────────────────┴────┴────┴────┴────┘ └───┴───┴───┘ └───────┴───┴───┘
)";