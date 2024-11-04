#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define int int64_t
#define ALL(x) (x).begin(), (x).end()

using i32 = int32_t;
using i64 = int64_t;
using i128 = __int128_t;

using u32 = uint32_t;
using u64 = uint64_t;
using u128 = __uint128_t;

using namespace std;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using pii = pair<int, int>;
template <typename K, typename V, typename Hash = std::hash<K>>
using umap = unordered_map<K, V, Hash>;
template <typename K, typename Hash = std::hash<K>>
using uset = unordered_set<K, Hash>;

using namespace __gnu_pbds;
template <typename K, typename V>
using ordmap = tree<K, V, less<K>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename K>
using ordset = ordmap<K, null_type>;





namespace {

template <typename T>
int zz(const vector<T>& v) {
  return static_cast<int>(v.size());
}
int zz(const string& v) { return static_cast<int>(v.size()); }

string InStr(int n = 0) {
  (void)n;
  string a;
  cin >> a;
  return a;
}

int InInt() {
  int a;
  cin >> a;
  return a;
}

vi InVec(int n) {
  vi a(n);
  for (int i = 0; i < n; i++) a[i] = InInt();
  return a;
}

int PosInf() { return numeric_limits<int>::max(); }
int NegInf() { return numeric_limits<int>::min(); }

const char* YesOrNo(bool b) { return b ? "YES" : "NO"; }



namespace {

template <typename A, typename B>
ostream& operator<<(ostream& os, const pair<A, B>& p) {
  return os << '(' << p.first << ", " << p.second << ')';
}
template <typename T>
ostream& OutputCollection(ostream& os, const T& collection, char s, char e) {
  os << s;
  string separator;
  for (const auto& x : collection) {
    os << separator << x;
    separator = ", ";
  }
  return os << e;
}

template <typename T>
ostream& operator<<(ostream& os, const vector<T>& v) {
  return OutputCollection(os, v, '[', ']');
}
template <typename T, size_t size>
ostream& operator<<(ostream& os, const array<T, size>& arr) {
  return OutputCollection(os, arr, '[', ']');
}
template <typename T>
ostream& operator<<(ostream& os, const set<T>& s) {
  return OutputCollection(os, s, '{', '}');
}
template <typename T>
ostream& operator<<(ostream& os, const unordered_set<T>& s) {
  return OutputCollection(os, s, '{', '}');
}
template <typename T>
ostream& operator<<(ostream& os, const multiset<T>& s) {
  return OutputCollection(os, s, '{', '}');
}
template <typename T>
ostream& operator<<(ostream& os, const unordered_multiset<T>& s) {
  return OutputCollection(os, s, '{', '}');
}
template <typename K, typename V>
ostream& operator<<(ostream& os, const map<K, V>& m) {
  return OutputCollection(os, m, '{', '}');
}
template <typename K, typename V>
ostream& operator<<(ostream& os, const unordered_map<K, V>& m) {
  return OutputCollection(os, m, '{', '}');
}

template <typename T>
ostream& operator<<(ostream& os, const priority_queue<T>& pq) {
  priority_queue<T> copy = pq;
  vector<T> v;
  while (!copy.empty()) {
    v.push_back(copy.top());
    copy.pop();
  }
  return os << v;
}

}  




namespace {

template <class T>
inline void HashCombine(std::size_t& seed, const T& v) {
  seed ^= std::hash<T>{}(v) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
}

template <typename T, size_t N>
struct ArrayHash {
  size_t operator()(const array<T, N>& a) const {
    size_t seed = 0;
    for (auto e : a) HashCombine(seed, e);
    return seed;
  }
};

struct PairHash {
  size_t operator()(const pii& a) const {
    size_t seed = 0;
    HashCombine(seed, a.first);
    HashCombine(seed, a.second);
    return seed;
  }
};

}  




namespace {

template <typename T>
T nChoosek(T n, T k) {
  if (k > n) return 0;
  if (k == 0 || k == n) return 1;

  if (k > n - k) k = n - k;
  T ret = 1;
  for (T i = 0; i < k; i++) {
    ret *= n - i;
    ret /= i + 1;
  }
  return ret;
}

template <typename T>
T fact(T n) {
  T ret = 1;
  for (T i = 1; i <= n; i++) ret *= i;
  return ret;
}

template <typename T>


T fact_mod(T n, T p) {
  if (n >= p) return 0;
  T ret = 1;
  for (T i = 1; i <= n; i++) ret = (ret * i) % p;
  return ret;
}

template <typename T>


T fact_mod_div(T n, T p, T m) {
  if (n >= p) return 0;
  T ret = 1;
  for (T i = 1; i <= n; i++) {
    if (i != m) ret = (ret * i) % p;
  }
  return ret;
}



constexpr int kMaxPrime = 22;  

vector<bool> is_prime(kMaxPrime + 1, true);
void InitAllIsPrime() {
  is_prime[0] = is_prime[1] = false;
  for (int i = 2; i <= kMaxPrime; i++) {
    if (is_prime[i] && i * i <= kMaxPrime) {
      for (int j = i * i; j <= kMaxPrime; j += i) is_prime[j] = false;
    }
  }
}

}  




namespace {

[[nodiscard]] bool IsBitSet(u64 a, u64 bit) { return ((a >> bit) & 1ULL) != 0; }
[[nodiscard]] u64 SetBit(u64 a, u64 bit) { return a | 1ULL << bit; }
[[nodiscard]] u64 ClrBit(u64 a, u64 bit) { return a & ~(1ULL << bit); }


[[nodiscard]] u64 Msb(u64 v) { return 63ULL - __builtin_clzll(v); }

}  





namespace {

struct Aho {
  struct Node {
    Node(int i, int parent, int curchar, const string& str)
        : i(i), parent(parent), curchar(curchar), pathview(str.data(), (size_t)(i + 1)) {
      fill(ALL(next), -1);
    }

    Node* Next(vector<Node>& aho_nodes, int c) {
      if (c == -1) return nullptr;
      return &aho_nodes[next[c]];
    }
    Node* Parent(vector<Node>& aho_nodes) {
      if (parent == -1) return nullptr;
      return &aho_nodes[parent];
    }
    Node* SuffixLink(vector<Node>& aho_nodes) {
      if (suffix_link == -1) return nullptr;
      return &aho_nodes[suffix_link];
    }
    Node* DictSuffixLink(vector<Node>& aho_nodes) {
      if (dict_suffix_link == -1) return nullptr;
      return &aho_nodes[dict_suffix_link];
    }

    array<int, 26> next;

    const int i;
    const int parent;
    const int curchar;
    const string_view pathview;  


    int suffix_link = -1;
    int dict_suffix_link = -1;

    bool word_ends_here = false;
  };

  vector<Node> nodes;
  Node* root = nullptr;

  explicit Aho(int max_nodes) {
    nodes.reserve(max_nodes);
    nodes.emplace_back(0, -1, -1, "");  

    root = &nodes[0];
  }

  int Insert(const string& str) {
    Node* n = root;
    for (int i = 0; i < zz(str); i++) {
      int c = str[i] - 'a';
      if (n->next[c] == -1) {
        nodes.emplace_back(nodes.size(), n->i, c, str);
        n->next[c] = nodes.back().i;
      }
      n = n->Next(nodes, c);
    }
    n->word_ends_here = true;
    return n->i;
  }

  void SetSuffixLinks() {
    queue<Node*> q;
    for (int node : root->next) {
      if (node != -1) q.push(&nodes[node]);
    }

    for (int c = 0; c < 26; c++) {
      if (root->next[c] == -1) root->next[c] = root->i;
    }

    while (!q.empty()) {
      Node* n = q.front();
      q.pop();

      for (int child : n->next) {
        if (child != -1) q.push(&nodes[child]);
      }

      if (n->Parent(nodes)->suffix_link == -1)
        n->suffix_link = root->i;
      else
        n->suffix_link = n->Parent(nodes)->SuffixLink(nodes)->next[n->curchar];

      for (int c = 0; c < 26; c++) {
        if (n->next[c] == -1) {
          if (n->suffix_link != -1)
            n->next[c] = n->SuffixLink(nodes)->next[c];
          else
            n->next[c] = root->i;
        }
      }

      if (n->suffix_link != -1 && n->SuffixLink(nodes)->word_ends_here)
        n->dict_suffix_link = n->suffix_link;
      else if (n->suffix_link != -1)
        n->dict_suffix_link = n->SuffixLink(nodes)->dict_suffix_link;
    }
  }
};
}  


struct UnionFind {
  vi parent;
  vi size;

  explicit UnionFind(int n) : parent(n), size(n, 1) {
    for (int i = 0; i < n; i++) parent[i] = i;
  }

  int FindRoot(int i) {
    if (i == parent[i]) return i;
    parent[i] = FindRoot(parent[i]);
    return parent[i];
  }

  void MergeSets(int a, int b) {
    a = FindRoot(a);
    b = FindRoot(b);
    if (a == b) return;

    if (size[a] < size[b]) swap(a, b);
    parent[b] = a;
    size[a] += size[b];
  }

  bool IsFullyMerged() {
    int i = 0;
    while (parent[i] != i) i = parent[i];
    return size[i] == zz(size);
  }
};



namespace {

void dfs1(const vvi& adj, int v, vector<bool>& visited, vi& order) {
  if (visited[v]) return;
  visited[v] = true;
  for (int u : adj[v]) dfs1(adj, u, visited, order);
  order.push_back(v);
}

bool dfs2(const vvi& adj_rev, int v, int c, vi& component) {
  if (component[v] != -1) return false;
  component[v] = c;
  for (auto u : adj_rev[v]) dfs2(adj_rev, u, c, component);
  return true;
}

vvi AdjRev(const vvi& adj) {
  vvi adj_rev(adj.size());
  for (int i = 0; i < zz(adj); i++) {
    for (int v : adj[i]) adj_rev[v].push_back(i);
  }
  return adj_rev;
}





vi StrongComponents(const vvi& adj) {
  vi reverse_order = [&adj]() {
    vector<bool> visited(adj.size(), false);
    vi order;
    for (int i = 0; i < zz(adj); i++) dfs1(adj, i, visited, order);
    reverse(ALL(order));
    return order;
  }();

  vvi adj_rev = AdjRev(adj);
  vi component(adj.size(), -1);
  int c = 0;
  for (int v : reverse_order) c += dfs2(adj_rev, v, c, component);
  return component;
}

}  




bool IsBipartite(const vvi& adj) {
  int n = zz(adj);
  vector<int> side(n, -1);
  bool is_bipartite = true;
  queue<int> q;
  for (int st = 0; st < n; ++st) {
    if (side[st] == -1) {
      q.push(st);
      side[st] = 0;
      while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int u : adj[v]) {
          if (side[u] == -1) {
            side[u] = side[v] ^ 1;
            q.push(u);
          } else {
            is_bipartite &= side[u] != side[v];
          }
        }
      }
    }
  }
  return is_bipartite;
}



vi EulerTrailOrCircuitHelper(int start, const vvi& input_adj, bool is_directed) {
  vector<unordered_multiset<int>> adj(input_adj.size());
  for (int i = 0; i < zz(input_adj); ++i) adj[i] = {input_adj[i].begin(), input_adj[i].end()};

  stack<int> st;
  st.push(start);
  vi ans;
  ans.reserve(adj.size());

  while (!st.empty()) {
    int v = st.top();
    if (adj[v].empty()) {
      ans.push_back(v);
      st.pop();
    } else {
      int x = *adj[v].begin();
      adj[v].erase(adj[v].find(x));
      if (!is_directed) adj[x].erase(adj[x].find(v));
      st.push(x);
    }
  }
  

  if (is_directed) reverse(ALL(ans));

  return ans;
}









optional<vi> EulerTrailOrCircuit(const vvi& adj, int circuit_start_point, bool is_directed) {
  optional<int> start;
  optional<int> end;

  if (is_directed) {
    vvi rev_adj(adj.size());
    for (int i = 0; i < zz(adj); ++i) {
      for (int x : adj[i]) rev_adj[x].push_back(i);
    }

    for (int i = 0; i < zz(adj); ++i) {
      int outdeg = zz(adj[i]);
      int indeg = zz(rev_adj[i]);

      if (outdeg == indeg) continue;

      if (outdeg - indeg == 1) {
        if (start.has_value()) return nullopt;
        start = i;
      } else if (indeg - outdeg == 1) {
        if (end.has_value()) return nullopt;
        end = i;
      } else {
        return nullopt;
      }
    }
  } else {
    for (int i = 0; i < zz(adj); ++i) {
      if (adj[i].size() % 2 == 0) continue;
      if (start.has_value() && end.has_value()) return nullopt;

      if (!start.has_value()) {
        start = i;
      } else {
        end = i;
      }
    }
  }

  

  if (!start.has_value() && !end.has_value() && !is_directed) {
    return EulerTrailOrCircuitHelper(circuit_start_point, adj, is_directed);
  }
  if (!start.has_value() && !end.has_value()) {
    start = circuit_start_point;
    end = circuit_start_point;
    

  }

  if (start.has_value() && end.has_value()) {
    

    

    

    vvi adj_copy = adj;
    if (start != end) {
      if (is_directed) {
        adj_copy[*end].push_back(*start);
      } else {
        adj_copy[*end].push_back(*start);
        adj_copy[*start].push_back(*end);
      }
    }
    vi circuit = EulerTrailOrCircuitHelper(*start, adj_copy, true);

    vector<bool> found(adj.size(), false);
    for (int x : circuit) found[x] = true;
    for (bool b : found) {
      if (!b) return nullopt;
    }
    return EulerTrailOrCircuitHelper(*start, adj, true);
  }

  return nullopt;
}

template <typename Sum>
class SegTree {
  using Container = typename Sum::ContainerType;
  using ValType = typename Sum::ValType;

 public:
  struct Node {
    int first = -1;
    int last = -1;

    Sum sum;

    Node* l = nullptr;
    Node* r = nullptr;
  };

  Node* root = nullptr;

  explicit SegTree(const Container& c) {
    nodes_.reserve(2 * c.size());
    root = Build(0, c.size() - 1, c);
  }

  void Update(int k, ValType val) { UpdateHelper(root, k, val); }

  Sum GetSum(int first, int last) { return GetSumHelper(root, first, last); }

 private:
  vector<Node> nodes_;

  void UpdateHelper(Node* node, int k, ValType val) {
    if (k == node->first && k == node->last) {
      node->sum = Sum::Init(val);
      return;
    }
    if (k <= node->l->last)
      UpdateHelper(node->l, k, val);
    else
      UpdateHelper(node->r, k, val);

    node->sum = Sum::Combine(node->l->sum, node->r->sum);
  }

  Sum GetSumHelper(Node* node, int first, int last) {
    if (node->first == first && node->last == last) return node->sum;

    if (first >= node->r->first) return GetSumHelper(node->r, first, last);
    if (last <= node->l->last) return GetSumHelper(node->l, first, last);

    return Sum::Combine(GetSumHelper(node->l, first, node->l->last), GetSumHelper(node->r, node->r->first, last));
  }

  Node* Build(int first, int last, const Container& c) {
    nodes_.emplace_back();
    Node* node = &nodes_.back();
    node->first = first;
    node->last = last;

    int sz = last - first + 1;

    if (sz == 1) {
      node->sum = Sum::Init(c[first]);
      return node;
    }

    int lsz = (sz + 1) / 2;
    int rsz = sz / 2;

    node->l = Build(first, first + lsz - 1, c);
    node->r = Build(first + lsz, first + lsz + rsz - 1, c);

    node->sum = Sum::Combine(node->l->sum, node->r->sum);

    return node;
  }
};

struct MergeSortSeg {
  using ContainerType = vi;
  using ValType = ContainerType::value_type;

  vi nums;

  static MergeSortSeg Init(ValType a) {
    MergeSortSeg node;
    node.nums.push_back(a);
    return node;
  }

  static MergeSortSeg Combine(const MergeSortSeg& l, const MergeSortSeg& r) {
    MergeSortSeg s;
    s.nums = vi(l.nums.size() + r.nums.size());
    merge(ALL(l.nums), ALL(r.nums), s.nums.begin());
    return s;
  }
};

using MergeSortTree = SegTree<MergeSortSeg>;

int CountSmaller(MergeSortTree::Node* node, int first, int last, int x) {
  if (node->first == first && node->last == last) return lower_bound(ALL(node->sum.nums), x) - node->sum.nums.begin();

  if (first >= node->r->first) return CountSmaller(node->r, first, last, x);
  if (last <= node->l->last) return CountSmaller(node->l, first, last, x);

  return CountSmaller(node->l, first, node->l->last, x) + CountSmaller(node->r, node->r->first, last, x);
}



array<pii, 4> neighbors(int x, int y) { return {pii{x, y + 1}, {x, y - 1}, {x + 1, y}, {x - 1, y}}; }



int DivCeil(int p, int q) { return p / q + (p % q != 0); }




}  


struct Rect {
  int h;
  int w;
};

struct Query {
  int hs;
  int ws;
  int hb;
  int wb;
};

vi Solve(vector<Rect>& rects, vector<Query>& queries) {
  vvi ps(1001, vi(1001, 0));
  for (const auto& r : rects) {
    ps[r.w][r.h] += r.w * r.h;
  }

  for (int i = 1; i <= 1000; ++i) {
    for (int j = 1; j <= 1000; ++j) {
      ps[i][j] += ps[i - 1][j];
      ps[i][j] += ps[i][j - 1];
      ps[i][j] -= ps[i - 1][j - 1];
    }
  }

  vi ans(queries.size(), 0);
  for (int i = 0; i < zz(queries); ++i) {
    const auto& q = queries[i];
    ans[i] += ps[q.wb - 1][q.hb - 1];
    ans[i] -= ps[q.ws][q.hb - 1];
    ans[i] -= ps[q.wb - 1][q.hs];
    ans[i] += ps[q.ws][q.hs];
  }
  return ans;
}

void TestCase(int test_num) {
  (void)test_num;

  int n = InInt();
  int q = InInt();

  vector<Rect> rects(n);
  vector<Query> queries(q);
  for (int i = 0; i < n; ++i) {
    rects[i].h = InInt();
    rects[i].w = InInt();
  }
  for (int i = 0; i < q; ++i) {
    queries[i].hs = InInt();
    queries[i].ws = InInt();
    queries[i].hb = InInt();
    queries[i].wb = InInt();
  }

  auto solve = Solve(rects, queries);
  for (int x : solve) cout << x << "\n";
}

i32 main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#ifndef ONLINE_JUDGE
  (void)freopen("in.txt", "r", stdin);
#endif

  int t = InInt();
  for (int i = 0; i < t; ++i) TestCase(i);
}