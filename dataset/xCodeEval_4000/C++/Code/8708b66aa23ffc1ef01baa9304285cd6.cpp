#include <algorithm>
#include <array>
#include <atomic>
#include <bitset>
#include <deque>
#include <forward_list>
#include <functional>
#include <initializer_list>
#include <iostream>
#include <iterator>
#include <limits>
#include <list>
#include <map>
#include <memory>
#include <numeric>
#include <optional>
#include <ostream>
#include <queue>
#include <random>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <string_view>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <valarray>
#include <variant>
#include <vector>

#define int long long int
#define ALL(x) (x).begin(), (x).end()

using i32 = int32_t;

using namespace std;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using pii = pair<int, int>;
template <typename K, typename V, typename Hash = std::hash<K>>
using umap = unordered_map<K, V, Hash>;
template <typename K, typename Hash = std::hash<K>>
using uset = unordered_set<K, Hash>;



namespace {



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
    if (is_prime[i] && (long long)i * i <= kMaxPrime) {
      for (int j = i * i; j <= kMaxPrime; j += i) is_prime[j] = false;
    }
  }
}

}  




namespace {

int IsBitSet(int a, int bit) { return ((a >> bit) & 1); }



uint64_t Msb64(uint64_t v) {
#if defined(_MSC_VER)
  return 63ULL - __lzcnt64(v);
#else
  return 63ULL - __builtin_clzll(v);
#endif
}
uint32_t Msb32(uint32_t v) {
#if defined(_MSC_VER)
  return 31U - __lzcnt(v);
#else
  return 31U - __builtin_clzll(v);
#endif
}

}  





namespace {

struct Aho {
  struct Node {
    Node(int i, int parent, int curchar, const string& str)
        : i(i), parent(parent), curchar(curchar), pathview(&str[0], (size_t)(i + 1)) {
      fill(ALL(next), -1);
    }

    Node* Next(vector<Node>& nodes, int c) {
      if (c == -1) return nullptr;
      return &nodes[next[c]];
    }
    Node* Parent(vector<Node>& nodes) {
      if (parent == -1) return nullptr;
      return &nodes[parent];
    }
    Node* SuffixLink(vector<Node>& nodes) {
      if (suffix_link == -1) return nullptr;
      return &nodes[suffix_link];
    }
    Node* DictSuffixLink(vector<Node>& nodes) {
      if (dict_suffix_link == -1) return nullptr;
      return &nodes[dict_suffix_link];
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
    for (int i = 0; i < str.length(); i++) {
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
    return size[i] == size.size();
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
  for (int i = 0; i < adj.size(); i++) {
    for (int v : adj[i]) adj_rev[v].push_back(i);
  }
  return adj_rev;
}





vi StrongComponents(const vvi& adj) {
  vi reverse_order = [&adj]() {
    vector<bool> visited(adj.size(), false);
    vi order;
    for (int i = 0; i < adj.size(); i++) dfs1(adj, i, visited, order);
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




}  


struct Node {
  int i = -1;
  int left = -1;
  int right = -1;

  int succ = -1;
  bool wants_double = false;

  bool chosen = false;
};

void InOrder(int i, const vector<Node>& nodes, vector<int>& order) {
  if (nodes[i].left >= 0) InOrder(nodes[i].left, nodes, order);
  order.push_back(i);
  if (nodes[i].right >= 0) InOrder(nodes[i].right, nodes, order);
}

void WantDouble(int i, vector<Node>& nodes, const string& c) {
  Node& n = nodes[i];
  if (n.succ >= 0 && c[n.i] < c[n.succ]) n.wants_double = true;
  if (n.succ >= 0 && c[n.i] == c[n.succ]) {
    int s = n.succ;
    while (s >= 0 && c[n.i] == c[s]) s = nodes[s].succ;

    if (s >= 0 && c[n.i] < c[s]) n.wants_double = true;
  }
  if (n.left >= 0) WantDouble(n.left, nodes, c);
  if (n.right >= 0) WantDouble(n.right, nodes, c);
}

bool Choose(int i, vector<Node>& nodes, int& k, int depth, int& chosecount) {
  Node& n = nodes[i];
  if (n.left >= 0) {
    n.chosen |= Choose(n.left, nodes, k, depth + 1, chosecount);
  }
  if (!n.chosen && depth <= k && n.wants_double) {
    n.chosen = true;
    k -= depth;
  }
  if (n.chosen) {
    chosecount++;
    depth = 0;
  }

  if (n.chosen && n.right >= 0) Choose(n.right, nodes, k, depth + 1, chosecount);

  return n.chosen;
}

void FinalInOrder(int i, const vector<Node>& nodes, const string& c, string& order) {
  if (nodes[i].left >= 0) FinalInOrder(nodes[i].left, nodes, c, order);

  order.push_back(c[i]);
  if (nodes[i].chosen) order.push_back(c[i]);

  if (nodes[i].right >= 0) FinalInOrder(nodes[i].right, nodes, c, order);
}

string Solve(vector<Node>& nodes, const string& c, const int k) {
  vector<int> order;
  InOrder(0, nodes, order);
  for (int i = 0; i < order.size() - 1; i++) {
    nodes[order[i]].succ = order[i + 1];
  }
  for (int i = order.size() - 2; i >= 0; i--) {
    nodes[order[i]].wants_double = c[nodes[order[i]].i] < c[nodes[order[i + 1]].i] ||
                                   c[nodes[order[i]].i] == c[nodes[order[i + 1]].i] && nodes[order[i + 1]].wants_double;
  }

  


  int kk = k;
  int chosecount = 0;
  Choose(0, nodes, kk, 1, chosecount);

  string s;
  FinalInOrder(0, nodes, c, s);
  return s;
}

i32 main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#ifndef ONLINE_JUDGE
  (void)freopen("in.txt", "r", stdin);
#endif

  int t = 1;
  

  while (t--) {
    int n;
    cin >> n;
    int k;
    cin >> k;
    string c;
    cin >> c;

    vector<Node> nodes(n);
    for (int i = 0; i < n; i++) {
      nodes[i].i = i;
      cin >> nodes[i].left;
      cin >> nodes[i].right;
      nodes[i].left--;
      nodes[i].right--;
    }

    cout << Solve(nodes, c, k) << "\n";
  }
}
