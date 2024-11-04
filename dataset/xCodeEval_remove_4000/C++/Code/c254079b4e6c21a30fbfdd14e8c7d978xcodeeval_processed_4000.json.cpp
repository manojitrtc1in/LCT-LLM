


















inline char gc() {
  static const int L = 233333;
  static char sxd[L], *sss = sxd, *ttt = sxd;
  if (sss == ttt) {
    ttt = (sss = sxd) + fread(sxd, 1, L, stdin);
    if (sss == ttt) {
      return EOF;
    }
  }
  return *sss++;
}






template <class T>
inline bool read(T& x) {
  x = 0;
  char dd;
  bool flg = false;
  for (; !isdigit(c); dd) {
    if (c == '-') {
      flg = true;
    } else if (c == EOF) {
      return false;
    }
  }
  for (; isdigit(c); dd) {
    x = (x * 10) + (c ^ 48);
  }
  if (flg) {
    x = -x;
  }
  return true;
}


template <class T>
inline void write(T x) {
  if (x < 0) {
    x = -x;
    putchar('-');
  }
  if (x > 9) {
    write(x / 10);
    x %= 10;
  }
  putchar(x | 48);
}

template <class T>
inline void writeln(T x) {
  write(x);
  puts("");
}

template <class T>
inline void id1(T x) {
  write(x);
  putchar(' ');
}

const int maxn = 505;

char mp[maxn][maxn];
int a[maxn][maxn];

namespace FLOW {
  const int maxn = ::maxn * 2;
  const int maxm = maxn * maxn;
  const int inf = 0x3f3f3f3f;

  struct Edge {
    int to, nxt;
    int cap;
  } e[maxm << 1];

  int first[maxn << 1];
  int id0[maxn << 1];
  int cnt = -1;
  
  void init() {
    memset(first, 0xff, sizeof(first));
    cnt = -1;
  }

  void add_edge(int u, int v, int cap) {
    

    e[++cnt].nxt = first[u];
    first[u] = cnt;
    e[cnt].to = v;
    e[cnt].cap = cap;
    e[++cnt].nxt = first[v];
    first[v] = cnt;
    e[cnt].to = u;
    e[cnt].cap = 0;
  }

  int dep[maxn];

  bool bfs(int s, int t) {
    

    memcpy(first, id0, sizeof(first));
    std::queue<int> q;
    q.push(s);
    memset(dep, 0x3f, sizeof(dep));
    dep[s] = 0;
    while (!q.empty()) {
      int now = q.front();
      q.pop();
      for (int i = first[now]; ~i; i = e[i].nxt) {
        int to = e[i].to;
        if (e[i].cap && dep[to] >= inf) {
          dep[to] = dep[now] + 1;
          q.push(to);
        }
      }
    }
    return dep[t] < inf;
  }

  int dfs(int now, int t, int lim) {
    if (!lim || now == t) {
      return lim;
    }
    int flow = 0;
    for (int i = first[now]; ~i; i = e[i].nxt) {
      first[now] = i;
      if (dep[e[i].to] == dep[now] + 1) {
        int f = dfs(e[i].to, t, std::min(lim, e[i].cap));
        flow += f;
        lim -= f;
        e[i].cap -= f;
        e[i ^ 1].cap += f;
        if (!lim) {
          break;
        }
      }
    }
    return flow;
  }

  int Dinic(int s, int t) {
    memcpy(id0, first, sizeof(id0));
    int maxflow = 0;
    while (bfs(s, t)) {
      maxflow += dfs(s, t, inf);
    }
    return maxflow;
  }
}

int main() {
  int n, m;
  std::cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    std::cin >> (mp[i] + 1);
  }
  FLOW::init();
  int ans = 0;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      ans += (a[i][j] = bool(mp[i][j] ^ mp[i + 1][j] ^ mp[i][j + 1] ^ mp[i + 1][j + 1]));
    }
  }
  ans -= a[n][m];
  ans += (a[n][m] = mp[n][m] == 'B');
  

  

  

  

  

  

  

  

  for (int i = 1; i < n; ++i) {
    for (int j = 1; j < m; ++j) {
      if (a[i][j] && a[i][m] && a[n][j]) {
        FLOW::add_edge(i, j + n, 1);
      }
    }
  }
  int S = n + m + 1, T = n + m + 2;
  for (int i = 1; i <= n; ++i) {
    FLOW::add_edge(S, i, 1);
  }
  for (int i = 1; i <= m; ++i) {
    FLOW::add_edge(i + n, T, 1);
  }
  int jian = FLOW::Dinic(S, T);
  

  ans -= jian;
  ans -= a[n][m];
  a[n][m] ^= jian & 1;
  ans += a[n][m];
  printf("%d\n", ans);
  return 0;
}