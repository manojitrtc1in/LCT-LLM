

















using namespace std;
















int DX[4] = { 0, 1, 0, -1 };
int DY[4] = { -1, 0, 1, 0 };

ll Q, N, M, K, L;

template <typename T, unsigned int MAX_N, int MIN_VALUE>
struct FastMaxableSegmentTree {
  T t[MAX_N * 2];

  void init(T* arr) {
    for (int i = 0; i < MAX_N; i++) {
      t[MAX_N + i] = arr[i];
    }
    for (int i = MAX_N - 1; i > 0; i--) {
      t[i] = max(t[i << 1], t[i << 1 | 1]);
    }
  }

  void init() {
    for (int i = 0; i < MAX_N * 2; i++) {
      t[i] = MIN_VALUE;
    }
  }

  int query(int l, int r) {
    int ans = MIN_VALUE;
    for (l += MAX_N, r += MAX_N; l < r; l >>= 1, r >>= 1) {
      if (l & 1) ans = max(ans, t[l++]);
      if (r & 1) ans = max(ans, t[--r]);
    }
    return ans;
  }

  void update(int pos, T val) {
    t[pos + MAX_N] = val;
    for (pos += MAX_N; pos > 1; pos >>= 1) {
      t[pos >> 1] = max(t[pos], t[pos ^ 1]);
    }
  }
};

template <typename T, unsigned int MAX_N>
struct FastSummableSegmentTree {
  T t[MAX_N * 2];

  void init(T* arr) {
    for (int i = 0; i < MAX_N; i++) {
      t[MAX_N + i] = arr[i];
    }
    for (int i = MAX_N - 1; i > 0; i--) {
      t[i] = t[i << 1] + t[i << 1 | 1];
    }
  }

  void init() {
    for (int i = 0; i < MAX_N * 2; i++) {
      t[i] = 0;
    }
  }

  int query(int l, int r) {
    int ans = 0;
    for (l += MAX_N, r += MAX_N; l < r; l >>= 1, r >>= 1) {
      if (l & 1) ans += t[l++];
      if (r & 1) ans += t[--r];
    }
    return ans;
  }

  void update(int pos, T val) {
    t[pos + MAX_N] = val;
    for (pos += MAX_N; pos > 1; pos >>= 1) {
      t[pos >> 1] = t[pos] + t[pos ^ 1];
    }
  }
};

template <typename T>
struct SummableSegmentTree {

  int n;
  T *arr, *lazy;

  void init(int _n) {
    n = _n;
    int siz = pow(2, (int)log2(n) + 2);
    arr = (T *)malloc(siz * sizeof(T));
    lazy = (T *)malloc(siz * sizeof(T));
    memset(arr, 0, siz * sizeof arr);
    memset(lazy, 0, siz * sizeof lazy);
  }

  void _updateLazy(int node, int lo, int hi) {
    if (lazy[node]) {
      arr[node] += (hi - lo + 1) * lazy[node];
      if (lo != hi) {
        lazy[node * 2] += lazy[node];
        lazy[node * 2 + 1] += lazy[node];
      }
      lazy[node] = 0;
    }
  }

  void _update(int node, int lo, int hi, int left, int right, T dif) {
    _updateLazy(node, lo, hi);
    if (hi < left || right < lo) return;
    if (left <= lo && hi <= right) {
      arr[node] += (hi - lo + 1) * dif;
      if (lo != hi) {
        lazy[node * 2] += dif;
        lazy[node * 2 + 1] += dif;
      }
      return;
    }
    int mid = (lo + hi) / 2;
    _update(node * 2, lo, mid, left, right, dif);
    _update(node * 2 + 1, mid + 1, hi, left, right, dif);
    arr[node] = arr[node * 2] + arr[node * 2 + 1];
  }

  void update(int left, int right, T dif) {
    _update(1, 0, n - 1, left, right, dif);
  }

  ll _sum(int node, int lo, int hi, int left, int right) {
    _updateLazy(node, lo, hi);
    if (hi < left || right < lo) return 0;
    if (left <= lo && hi <= right) return arr[node];
    int mid = (lo + hi) / 2;
    return _sum(node * 2, lo, mid, left, right) + _sum(node * 2 + 1, mid + 1, hi, left, right);
  }

  ll sum(int left, int right) {
    return _sum(1, 0, n - 1, left, right);
  }
};

template <typename T, int MIN>
struct MaxableSegmentTree {

  int n;
  T *arr, *lazy;
  bool *used;

  void init(int _n) {
    n = _n;
    int siz = pow(2, (int)log2(n) + 2);
    arr = (T *)malloc(siz * sizeof(T));
    lazy = (T *)malloc(siz * sizeof(T));
    used = (bool *)malloc(siz * sizeof(bool));
    memset(arr, 0, sizeof(T) * siz);
    memset(lazy, 0, sizeof(T) * siz);
    memset(used, 0, sizeof(bool) * siz);
  }

  void _updateLazy(int node, int lo, int hi) {
    if (lazy[node]) {
      arr[node] += lazy[node];
      used[node] = true;
      if (lo != hi) {
        lazy[node * 2] += lazy[node];
        lazy[node * 2 + 1] += lazy[node];
        used[node * 2] = true;
        used[node * 2 + 1] = true;
      }
      lazy[node] = 0;
    }
  }

  void _update(int node, int lo, int hi, int left, int right, T dif) {
    _updateLazy(node, lo, hi);
    if (hi < left || right < lo) return;
    if (left <= lo && hi <= right) {
      arr[node] += dif;
      used[node] = true;
      if (lo != hi) {
        lazy[node * 2] += dif;
        lazy[node * 2 + 1] += dif;
        used[node * 2] = true;
        used[node * 2 + 1] = true;
      }
      return;
    }
    int mid = (lo + hi) / 2;
    _update(node * 2, lo, mid, left, right, dif);
    _update(node * 2 + 1, mid + 1, hi, left, right, dif);
    arr[node] = std::max(arr[node * 2], arr[node * 2 + 1]);
    used[node] = true;
  }

  void update(int left, int right, T dif) {
    _update(1, 0, n - 1, left, right, dif);
  }

  ll _max(int node, int lo, int hi, int left, int right) {
    _updateLazy(node, lo, hi);
    if (hi < left || right < lo) return MIN;
    if (left <= lo && hi <= right) {
      if (!used[node]) return MIN;
      return arr[node];
    }
    int mid = (lo + hi) / 2;
    return std::max(_max(node * 2, lo, mid, left, right), _max(node * 2 + 1, mid + 1, hi, left, right));
  }

  ll max(int left, int right) {
    return _max(1, 0, n - 1, left, right);
  }
};

template<unsigned int MAX_N, unsigned int MAX_DEPTH>
struct LCA {
  int arr[MAX_N][MAX_DEPTH];
  int depth[MAX_N];
  void build(int n, int p, vector<int>* G) {
    arr[n][0] = p;
    depth[n] = depth[p] + 1;
    for (int i = 1; i < MAX_DEPTH; i++) {
      arr[n][i] = arr[arr[n][i - 1]][i - 1];
    }
    for (int next : G[n]) {
      if (next == p) continue;
      build(next, n, G);
    }
  }

  int get(int u, int v) {
    if (depth[u] != depth[v]) {
      if (depth[u] < depth[v]) std::swap(u, v);
      for (int i = MAX_DEPTH - 1; i >= 0; i--) {
        if (depth[v] <= depth[arr[u][i]]) u = arr[u][i];
      }
    }
    int ret = u;
    if (u != v) {
      for (int i = MAX_DEPTH - 1; i >= 0; i--) {
        if (arr[u][i] != arr[v][i]) {
          u = arr[u][i];
          v = arr[v][i];
        }
        ret = arr[u][i];
      }
    }
    return ret;
  }

  int get(int r, int u, int v) {
    int a = get(r, u);
    int b = get(r, v);
    int c = get(u, v);
    if (a == b) return c;
    if (a == c) return b;
    if (b == c) return a;
  }
};

template <unsigned int N>
struct ArticulationPoint {
  int discovered[N + 2];
  bool is_cut[N + 2];
  int number;
  vector<int> points;

  void build(vector<int>* G, int n) {
    for (int i = 0; i < n; i++) {
      if (!discovered[i]) {
        _dfs(i, true, G);
      }
    }
    for (int i = 0; i < n; i++) {
      if (is_cut[i]) points.push_back(i);
    }
  }

  int _dfs(int cur, bool is_root, vector<int>* G) {
    discovered[cur] = ++number;
    int ret = discovered[cur];
    int child = 0;

    for (int i = 0; i < G[cur].size(); i++) {
      int next = G[cur][i];
      if (discovered[next]) {
        ret = min(ret, discovered[next]);
        continue;
      }
      child++;
      int prev = _dfs(next, false, G);

      if (!is_root && prev >= discovered[cur]) {
        is_cut[cur] = true;
      }

      ret = min(ret, prev);
    }

    if (is_root) {
      is_cut[cur] = (child >= 2);
    }
    return ret;
  }
};

template <unsigned int MAXN>
struct TarjanSCC {

  int N;
  int _time;
  stack<int> _st;

  

  int size;
  

  int SCC[MAXN];
  int CHK[MAXN];
  

  vector< vector<int> > SCCG;
  

  vector< vector <int> > SCCGG;

  void build(int n, vector<int>* G) {
    N = n;
    memset(SCC, -1, sizeof(int) * n);
    memset(CHK, -1, sizeof(int) * n);

    _time = 0;
    for (int i = 0; i < N; i++) {
      if (SCC[i] != -1) continue;
      _dfs(i, G);
    }
    size = SCCG.size();
    _makeGraph(G);
  }

  void _makeGraph(vector<int>* G) {
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < G[i].size(); j++) {
        int g = G[i][j];
        if (SCC[i] == SCC[g]) continue;
        SCCG[SCC[i]].push_back(SCC[g]);
      }
    }
    for (int i = 0; i < size; i++) {
      std::sort(SCCG[i].begin(), SCCG[i].end());
      std::unique(SCCG[i].begin(), SCCG[i].end());
    }
  }

  int _dfs(int cur, vector<int>* G) {
    _st.push(cur);
    CHK[cur] = _time++;

    int lowlink = CHK[cur];
    for (int i = 0; i < G[cur].size(); i++) {
      int next = G[cur][i];
      if (CHK[next] == -1) {
        int nlo = _dfs(next, G);
        lowlink = min(lowlink, nlo);
      }
      else if (SCC[next] == -1) {
        lowlink = min(lowlink, CHK[next]);
      }
    }
    if (lowlink == CHK[cur]) {
      SCCG.push_back(vector<int>());
      SCCGG.push_back(vector<int>());
      while (true) {
        int now = _st.top();
        _st.pop();
        SCC[now] = SCCG.size() - 1;
        SCCGG[SCCGG.size() - 1].push_back(now);
        if (now == cur) break;
      }
    }
    return lowlink;
  }
};

template <unsigned int MAXN>
struct Maxflow {
  struct edg { int pos, cap, rev; };
  vector<edg> gph[MAXN];
  int src, dst;

  void init(int _src, int _dst) {
    src = _src;
    dst = _dst;
    for (int i = 0; i < MAXN; i++) gph[i].clear();
  }

  void add_edge(int s, int e, int x) {
    gph[s].push_back({ e, x, (int)gph[e].size() });
    gph[e].push_back({ s, 0, (int)gph[s].size() - 1 });
  }

  int pa[MAXN], pe[MAXN];

  bool bfs() {
    bool vis[MAXN] = {};
    queue<int> que;
    que.push(src);
    vis[src] = 1;
    while (!que.empty() && !vis[dst]) {
      int x = que.front();
      que.pop();
      for (int i = 0; i < gph[x].size(); i++) {
        edg e = gph[x][i];
        if (e.cap > 0 && !vis[e.pos]) {
          vis[e.pos] = 1;
          pa[e.pos] = x;
          pe[e.pos] = i;
          que.push(e.pos);
        }
      }
    }
    return vis[dst];
  }

  int match() {
    int ret = 0;
    while (bfs()) {
      int minv = 1e9;
      for (int pos = dst; pos != src; pos = pa[pos]) {
        minv = min(minv, gph[pa[pos]][pe[pos]].cap);
      }
      for (int pos = dst; pos != src; pos = pa[pos]) {
        int rev = gph[pa[pos]][pe[pos]].rev;
        gph[pa[pos]][pe[pos]].cap -= minv;
        gph[pos][rev].cap += minv;
      }
      ret += minv;
    }
    return ret;
  }

  int getcap(int x, int y) {
    for (auto &i : gph[x]) {
      if (i.pos == y) return i.cap;
    }
    return 0;
  }
};

template <unsigned int MAX_N>
struct BipartiteMatching {
  int visited[MAX_N];
  int match[MAX_N];
  int cnt;

  bool dfs(int cur, vector<int>* G) {
    if (visited[cur] == cnt) return false;
    visited[cur] = cnt;
    for (int i = 0; i < G[cur].size(); i++) {
      int next = G[cur][i];
      if (match[next] == -1 || dfs(match[next], G)) {
        match[cur] = next;
        match[next] = cur;
        return true;
      }
    }
    return false;
  }

  int build(vector<int>* G) {
    int ret = 0;
    memset(visited, 0, sizeof visited);
    memset(match, -1, sizeof match);
    cnt = 0;
    for (int i = 0; i < MAX_N; i++) {
      cnt++;
      if (dfs(i, G)) ret++;
    }
    return ret;
  }
};

string A, B;
int AA[33], BB[33];

int main() {
  cin >> Q;
  while (Q--) {
    cin >> N >> M;
    cin >> A >> B;
    for (int i = 0; i < 26; i++) {
      AA[i] = BB[i] = 0;
    }
    for (int i = 0; i < N; i++) {
      AA[A[i] - 'a'] ++;
      BB[B[i] - 'a'] ++;
    }
    bool x = true;
    for (int i = 0; i < 26; i++) {
      if (AA[i] != BB[i]) x = false;
    }
    if (x) {
      cout << "Yes" << endl;
      continue;
    }
    if (AA['z' - 'a'] > BB['z' - 'a']) {
      cout << "No" << endl;
      continue;
    }
    bool r = true;
    for (int i = 0; i < 26; i++) {
      int k = AA[i] - BB[i];
      AA[i] -= BB[i];
    }
    for (int i = 0; i < 26; i++) {
      if (AA[i] < 0) {
        cout << "No" << endl;
        r = false;
        break;
      }
      else {
        if (AA[i] % M != 0) {
          cout << "No" << endl;
          r = false;
          break;
        }
        AA[i + 1] += AA[i];
      }
    }
    if (r) {
      cout << "Yes" << endl;
    }
  }
}