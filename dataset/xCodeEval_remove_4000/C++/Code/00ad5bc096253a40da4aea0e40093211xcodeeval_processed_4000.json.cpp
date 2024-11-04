














using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
const LL mod = 1e9 + 7;

  if ((bool)x) printf("YES"); \
  else printf("NO");




int dfn;
vector<int> G1[MX], G2[MX];
vector<int> vis, lev, rv, rl;

void dfs2(int u) {
  ++dfn;
  vis[u] = dfn;
  rv[dfn] = u;
  for (auto v : G2[u]) {
    dfs2(v);
  }
  ++dfn;
  lev[u] = dfn;
  rl[dfn] = u;
}

int curr = 0;
int ans = 0;
set<int> in, out;

void dfs(int u) {
  auto itl = in.insert(vis[u]).first;
  auto itr = out.insert(lev[u]).first;
  int recl = 0, recr = 0;

  ++curr;
  ++itr;
  if (itl != in.begin() && itr != out.end()) {
    itl--;
    if (rv[*itl] == rl[*itr]) {
      recl = *itl;
      recr = *itr;
      in.erase(itl);
      out.erase(itr);
      --curr;
    }
  }
  ans = max(ans, curr);
  for (auto v : G1[u]) {
    dfs(v);
  }
  in.erase(vis[u]);
  out.erase(lev[u]);
  --curr;
  if (recl) {
    in.insert(recl);
    out.insert(recr);
    ++curr;
  }
}

void solve() {
  int n;
  cin >> n;
  in.clear();
  out.clear();
  for (int i = 1; i <= n; ++i) {
    G1[i].clear();
    G2[i].clear();
  }
  lev = vector<int>(n + 1);
  vis = vector<int>(n + 1);
  rv = vector<int>(2 * n + 1);
  rl = vector<int>(2 * n + 1);;
  dfn = ans = 0;
  for (int i = 2; i <= n; ++i) {
    int t;
    cin >> t;
    G1[t].push_back(i);
  }
  for (int i = 2; i <= n; ++i) {
    int t;
    cin >> t;
    G2[t].push_back(i);
  }
  dfs2(1);
  dfs(1);
  cout << ans << endl;
}

int main() {
  int T = 1;
  cin >> T;
  while (T--)
    solve();
  return 0;
}


