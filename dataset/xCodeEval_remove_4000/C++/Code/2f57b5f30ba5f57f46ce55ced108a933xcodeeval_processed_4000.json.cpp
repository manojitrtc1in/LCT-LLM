







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

string InStr() {
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

const char* id9(bool b) { return b ? "YES" : "NO"; }



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
T id3(T n, T k) {
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


T id1(T n, T p, T m) {
  if (n >= p) return 0;
  T ret = 1;
  for (T i = 1; i <= n; i++) {
    if (i != m) ret = (ret * i) % p;
  }
  return ret;
}



constexpr int id4 = 22;  

vector<bool> is_prime(id4 + 1, true);
void id0() {
  is_prime[0] = is_prime[1] = false;
  for (int i = 2; i <= id4; i++) {
    if (is_prime[i] && i * i <= id4) {
      for (int j = i * i; j <= id4; j += i) is_prime[j] = false;
    }
  }
}

}  




namespace {

[[nodiscard]] bool id5(u64 a, u64 bit) { return ((a >> bit) & 1ULL) != 0; }
[[nodiscard]] u64 SetBit(u64 a, u64 bit) { return a | 1ULL << bit; }
[[nodiscard]] u64 ClrBit(u64 a, u64 bit) { return a & ~(1ULL << bit); }


[[nodiscard]] u64 Msb(u64 v) { return 63ULL - __builtin_clzll(v); }

}  





namespace {

struct Aho {
  struct Node {
    Node(int i, int parent, int id7, const string& str)
        : i(i), parent(parent), id7(id7), pathview(str.data(), (size_t)(i + 1)) {
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
    const int id7;
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
        n->suffix_link = n->Parent(nodes)->SuffixLink(nodes)->next[n->id7];

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




vi Eulerian(int start, const vvi& input_adj) {
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
      adj[x].erase(adj[x].find(v));
      st.push(x);
    }
  }

  return ans;
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

int id2(MergeSortTree::Node* node, int first, int last, int x) {
  if (node->first == first && node->last == last) return lower_bound(ALL(node->sum.nums), x) - node->sum.nums.begin();

  if (first >= node->r->first) return id2(node->r, first, last, x);
  if (last <= node->l->last) return id2(node->l, first, last, x);

  return id2(node->l, first, node->l->last, x) + id2(node->r, node->r->first, last, x);
}




}  


vector<string> Solve(vvi& a) {
  umap<int, int> id6;
  umap<int, int> id8;
  umap<int, int> counts;

  int index = zz(a);
  for (const vi& vec : a) {
    for (int x : vec) {
      counts[x]++;
      if (id6.contains(x)) continue;
      id6[x] = index;
      id8[index] = x;
      index++;
    }
  }

  for (auto [_, x] : counts) {
    if (x % 2 == 1) return {};
  }

  vvi adj(a.size() + id6.size());

  for (int i = 0; i < zz(a); ++i) {
    for (int x : a[i]) {
      adj[i].push_back(id6[x]);
      adj[id6[x]].push_back(i);
    }
  }

  vector<umap<int, int>> lefts(a.size());

  uset<int> untoured;
  for (int i = 0; i < zz(a); ++i) untoured.insert(i);

  while (!untoured.empty()) {
    vi tour = Eulerian(*untoured.begin(), adj);

    for (int i = 0; i < zz(tour) - 1; i++) {
      if (tour[i] < zz(a)) {
        untoured.erase(tour[i]);
        lefts[tour[i]][id8[tour[i + 1]]]++;
      }
    }
  }

  vector<string> ans(zz(a));

  for (int i = 0; i < zz(a); ++i) {
    ans[i].reserve(a[i].size());
    for (int x : a[i]) {
      if (lefts[i][x] > 0) {
        ans[i].push_back('L');
        lefts[i][x]--;
      } else {
        ans[i].push_back('R');
      }
    }
  }

  return ans;
}

void TestCase(int test_num) {
  (void)test_num;

  int m = InInt();
  vvi a(m);

  for (int i = 0; i < m; ++i) {
    int n = InInt();
    a[i] = InVec(n);
  }

  auto solve = Solve(a);
  if (solve.empty()) {
    cout << "NO\n";
  } else {
    cout << "YES\n";
    for (const string& str : solve) cout << str << "\n";
  }
}

i32 main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  (void)freopen("in.txt", "r", stdin);


  

  

  TestCase(123456);
}