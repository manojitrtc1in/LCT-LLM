






using namespace std;
typedef long long ll;







namespace Util {



string ssprintf(const string fmt_str, ...) {
  int final_n, n = ((int)fmt_str.size()) * 2;
  unique_ptr<char[]> formatted;
  va_list ap;
  while (1) {
    formatted.reset(new char[n]);
    strcpy(&formatted[0], fmt_str.c_str());
    va_start(ap, fmt_str);
    final_n = vsnprintf(&formatted[0], n, fmt_str.c_str(), ap);
    va_end(ap);
    if (final_n < 0 || final_n >= n)
      n += abs(final_n - n + 1);
    else
      break;
  }
  return string(formatted.get());
}

template <class T> void assign(T &a, T b) { a = b; }
template <class T, class U> void assign(T &a, U &b, T c, U d) { a = c, b = d; }
template <class T, class U, class V> void assign(T &a, U &b, V &c, T d, U e, V f) { a = d, b = e, c = f; }
template <class T, class U, class V, class W> void assign(T &a, U &b, V &c, W &d, T e, U f, V g, W h) {
  a = e, b = f, c = g, d = h;
}

} 


namespace Math {

ll modpow(ll b, ll p, ll m) {
  ll r = 1;
  for (; p; p >>= 1, b = b * b % m)
    if (p & 1)
      r = r * b % m;
  return r;
}

ll modinv(ll b, ll m) { return modpow(b, m - 2, m); }

ll sumdigit(ll num) {
  ll res = 0;
  while (num) {
    res += num % 10;
    num /= 10;
  }
  return res;
}

ll sumdigit(string num) {
  ll res = 0;
  for (char c : num)
    res += c - '0';
  return res;
}



ll lsb(ll x) { return x & (-x); }

template <class T> const T inf() { return 0; }
template <> const ll inf<ll>() { return 0x3f3f3f3f3f3f3f3fll; }
template <> const int inf<int>() { return 0x3f3f3f3f; }

template <class T> T gcd(T a, T b) { return abs(__gcd(a, b)); }
template <class T> T clamp(T n, T l, T r) { return n < l ? l : n > r ? r : n; }
template <class T> T lcm(T a, T b) { return abs(a / gcd(a, b) * b); }
template <class T> T sgn(T n) { return n == 0 ? 0 : n > 0 ? 1 : -1; }

template <class T, int size> struct Vector;



template <class T, int size_m, int size_n> struct Matrix {
  T val[size_m][size_n];

  Matrix() {
    for (int i = 0; i < size_m; i++)
      for (int j = 0; j < size_n; j++)
        val[i][j] = 0;
  }

  
  template <class U> Matrix(Matrix<U, size_m, size_n> mat) {
    for (int i = 0; i < size_m; i++)
      for (int j = 0; j < size_n; j++)
        val[i][j] = mat.val[i][j];
  }

  
  Matrix(T **arr) {
    for (int i = 0; i < size_m; i++)
      for (int j = 0; j < size_n; j++)
        val[i][j] = arr[i][j];
  }

  
  T &operator()(const int i, const int j) { return val[i][j]; }

  
  template <class U> const Matrix<U, size_m, size_n> convert() { return Matrix<U, size_m, size_n>(*this); }

  const Matrix operator+=(const Matrix<T, size_m, size_n> mat) {
    for (int i = 0; i < size_m; i++)
      for (int j = 0; j < size_n; j++)
        (*this)(i, j) += mat(i, j);
  }

  const Matrix operator-=(const Matrix<T, size_m, size_n> mat) {
    for (int i = 0; i < size_m; i++)
      for (int j = 0; j < size_n; j++)
        (*this)(i, j) -= mat(i, j);
  }

  const Matrix operator+(const Matrix<T, size_m, size_n> mat) {
    Matrix<T, size_m, size_n> res = *this;
    res += mat;
    return res;
  }

  const Matrix operator-(const Matrix<T, size_m, size_n> mat) {
    Matrix<T, size_m, size_n> res = *this;
    res -= mat;
    return res;
  }

  
  template <int size_p> Matrix<T, size_m, size_p> operator*(Matrix<T, size_n, size_p> mat) {
    Matrix<T, size_m, size_p> res;
    for (int i = 0; i < size_m; i++)
      for (int j = 0; j < size_p; j++)
        for (int k = 0; k < size_n; k++)
          res(i, j) += (*this)(i, k) * mat(k, j);
    return res;
  }

  
  Vector<T, size_n> operator*(Vector<T, size_n> vec) {
    Vector<T, size_n> res;
    for (int i = 0; i < size_m; i++)
      for (int j = 0; j < size_n; j++)
        res.val[j] += val[i][j] * vec[j];
    return res;
  }
};



template <class T, int size> struct Vector {
  
  template <class U> static const Vector<U, 2> vec2(U a, U b) {
    Vector<U, 2> vec;
    vec.val[0] = a, vec.val[1] = b;
    return vec;
  }

  
  template <class U> static const Vector<U, 3> vec3(U a, U b, U c) {
    Vector<U, 3> vec;
    vec.val[0] = a, vec.val[1] = b, vec.val[2] = c;
    return vec;
  }

  T val[size];

  
  Vector() {
    for (int i = 0; i < size; i++)
      val[i] = 0;
  }

  
  template <class U> Vector(Vector<U, size> vec) {
    for (int i = 0; i < size; i++)
      val[i] = vec.val[i];
  }

  
  Vector(T *arr) {
    for (int i = 0; i < size; i++)
      val[i] = arr[i];
  }

  
  template <class U> Vector<U, size> convert() { return Vector<U, size>(*this); }

  const Vector operator+(const Vector &vec) const {
    Vector v = *this;
    v += vec;
    return v;
  }
  const Vector operator-(const Vector &vec) const {
    Vector v = *this;
    v -= vec;
    return v;
  }
  const Vector operator*(const Vector &vec) const {
    Vector v = *this;
    v *= vec;
    return v;
  }
  const Vector operator/(const Vector &vec) const {
    Vector v = *this;
    v /= vec;
    return v;
  }

  const Vector operator+=(const Vector &vec) {
    for (int i = 0; i < size; i++)
      val[i] += vec.val[i];
    return *this;
  }
  const Vector operator-=(const Vector &vec) {
    for (int i = 0; i < size; i++)
      val[i] -= vec.val[i];
    return *this;
  }
  const Vector operator*=(const Vector &vec) {
    for (int i = 0; i < size; i++)
      val[i] *= vec.val[i];
    return *this;
  }
  const Vector operator/=(const Vector &vec) {
    for (int i = 0; i < size; i++)
      val[i] /= vec.val[i];
    return *this;
  }

  
  const T dot(const Vector<T, size> vec) {
    T acc = 0;
    for (int i = 0; i < size; i++)
      acc += val[i] * vec.val[i];
    return acc;
  }
};

struct id7 {
  vector<int> val;
  

  int pmax = 0;

  id7() {
    val.resize(1);
    val[0] = -1;
  }

  int get(int n) {
    if (n >= val.size()) {
      eprintf("Error: request log2[%d] but is not computed yet\n", n);
      exit(1);
    }

    return val[n];
  }

  void require(int n) {
    if (n < pmax)
      return;
    val.resize(n + 1);

    for (int i = 0; i < 30; i++)
      for (int j = max(1 << i, pmax + 1); j < min(1 << (i + 1), n + 1); j++)
        val[j] = i;

    pmax = n;
  }
};

id7 id0;



template <int MOD, typename IntType = int> struct id3 {
  IntType val;

  id3() : val(0) {}
  id3(int v, bool safe = false) { val = safe ? v : ((v % MOD) + MOD) % MOD; }
  id3(ll v, bool safe = false) { val = safe ? v : ((v % MOD) + MOD) % MOD; }

  explicit operator bool() const { return val != 0; }
  const bool operator==(const id3 &g) const { return val == g.val; }
  const bool operator!=(const id3 &g) const { return val != g.val; }
  const id3 operator+=(const id3 &g) { return *this = *this + g; }
  const id3 operator-=(const id3 &g) { return *this = *this - g; }
  const id3 operator*=(const id3 &g) { return *this = *this * g; }
  const id3 operator/=(const id3 &g) { return *this = *this / g; }
  const id3 operator^=(const id3 &g) { return *this = *this ^ g; }
  const id3 operator-() const { return id3(val == 0 ? 0 : MOD - val, true); }
  const id3 operator+(const id3 &g) const {
    ll newval = val + g.val;
    if (newval >= MOD)
      newval -= MOD;
    return id3(newval, true);
  }
  const id3 operator-(const id3 &g) const { return *this + (-g); }
  const id3 operator*(const id3 &g) const { return id3(1ll * val * g.val); }
  const id3 operator/(const id3 &g) const { return *this * g.inv(); }
  template <class T> const id3 operator^(const T t) const { return id3(modpow(val, t, MOD)); }
  const id3 inv() const { return id3(modinv(val, MOD)); }
};

using Modint = id3<1000000007>;

} 


namespace DS {





template <class T, class Combiner> struct SparseTable {
  int n, nlog, base;
  vector<vector<T>> st;
  Combiner combiner;

  SparseTable(int n, T *t, int base = 0) : n(n), base(base) {
    Math::id0.require(n);

    nlog = Math::id0.get(n);

    st.resize(nlog + 1);
    for (int i = 0; i <= nlog; i++)
      st[i].resize(n + base);

    for (int j = 0; j < n + base; j++)
      st[0][j] = t[j];
    for (int i = 1; i <= nlog; i++)
      for (int j = 0; j + (1 << (i - 1)) < n; j++)
        st[i][j] = combiner(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
  }

  T query(int l, int r) {
    if (l > r) {
      eprintf("Error: sparse table query (L, R) = (%d, %d).\n", l, r);
      exit(1);
    }

    l = Math::clamp(l, 0, n - 1);
    r = Math::clamp(r, 0, n - 1);

    int len = Math::id0.get(r - l + 1);
    T val = st[len][l];
    l += 1 << len;

    if (l <= r)
      val = combiner(val, query(l, r));

    return val;
  }
};

template <class T> struct SparseTableCombinerSample {
  const T operator()(const T &a, const T &b) { return a + b; }
};

struct DSU {
  int size;
  vector<int> dsu, block;

  DSU() {}
  DSU(int size) { init(size); }

  void init(int new_size) {
    size = new_size;
    dsu.resize(size + 1);
    block.resize(size + 1);
    for (int i = 0; i <= size; i++)
      dsu[i] = i, block[i] = 1;
  }

  int find(int u) { return u == dsu[u] ? u : dsu[u] = find(dsu[u]); }
  bool same_component(int u, int v) { return find(u) == find(v); }
  void merge(int u, int v) {
    if (!same_component(u, v)) {
      block[find(u)] += block[find(v)];
      dsu[find(v)] = find(u);
    }
  }
  int block_size(int u) { return block[find(u)]; }
};

} 


namespace Graph {

const int id2 = 1;
const int id5 = -1;

template <typename LenType> struct Edge {
  int from, to;
  LenType len;

  Edge(int from, int to, LenType len) : from(from), to(to), len(len) {}
};



template <typename LenType> struct Graph {
  using edge = Edge<LenType>;

  vector<vector<edge>> G;
  int n, lo;

  Graph() {}
  Graph(int size, int node_lo = id2) { resize(size, node_lo); }

  void resize(int new_size, int node_lo = id2) {
    n = new_size;
    lo = node_lo;
    G.resize(n + 1);
  }

  void add_edge(int from, int to, LenType len = 1) { G[from].push_back(edge(from, to, len)); }
  void add_bidir_edge(int u, int v, LenType len = 1) { add_edge(u, v, len), add_edge(v, u, len); }
};

template <typename LenType> struct id6 {
  bool success = true;
  vector<int> color;

  id6(Graph<LenType> G) {
    color = vector<int>(G.n + 1, 0);

    queue<int> Q;
    Q.push(G.lo);
    color[G.lo] = 1;

    while (!Q.empty()) {
      int node = Q.front();
      Q.pop();
      for (Edge<LenType> edge : G.G[node]) {
        if (color[edge.to] == color[edge.from]) {
          success = false;
          return;
        }

        if (!color[edge.to]) {
          color[edge.to] = color[edge.from] != 1 ? 1 : 2;
          Q.push(edge.to);
        }
      }
    }
  }
};

template <typename LenType> struct id4 {
  vector<vector<LenType>> dist;

  id4(Graph<LenType> G) {
    dist = vector<vector<LenType>>(G.n + 1, vector<LenType>(G.n + 1, Math::inf<LenType>()));

    for (int i = G.lo; i < G.lo + G.n; i++)
      dist[i][i] = 0;

    for (int i = G.lo; i < G.lo + G.n; i++)
      for (Edge<LenType> edge : G.G[i])
        dist[edge.from][edge.to] = edge.len;

    for (int k = G.lo; k < G.lo + G.n; k++)
      for (int i = G.lo; i < G.lo + G.n; i++)
        for (int j = G.lo; j < G.lo + G.n; j++)
          dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
  }
};

template <typename LenType> struct Tree : public Graph<LenType> {
  using edge = typename Graph<LenType>::edge;
  using Graph<LenType>::n;
  using Graph<LenType>::G;

  int root;
  vector<LenType> depth, parent;

  Tree() : Graph<LenType>() {}
  Tree(int size) : Graph<LenType>(size) {}

  void init_dfs(int n, int p = id5) {
    typename vector<edge>::iterator it_parent = G[n].end();
    parent[n] = p;

    for (typename vector<edge>::iterator it = G[n].begin(); it != G[n].end(); it++) {
      if (it->to == p) {
        it_parent = it;
      } else {
        depth[it->to] = depth[n] + it->len;
        init_dfs(it->to, n);
      }
    }
  }

  void init_tree(int new_root = 1, int root_depth = 0) {
    root = new_root;

    depth.resize(n + 1);
    parent.resize(n + 1);

    depth[root] = root_depth;

    init_dfs(root);
  }
};

using UnweightedTree = Tree<int>;

struct LCA {
  int n, nlog;
  vector<int> depth;
  vector<vector<int>> jump_table;

  LCA(const UnweightedTree &tree) { init(tree); }
  void init(const UnweightedTree &tree) {
    n = tree.n;
    depth = tree.depth;

    Math::id0.require(n);
    nlog = Math::id0.get(n);

    jump_table.resize(nlog + 1);
    for (int i = 0; i <= nlog; i++)
      jump_table[i].resize(n + 1);
    for (int i = 0; i <= n; i++)
      jump_table[0][i] = tree.parent[i];
    for (int i = 1; i <= nlog; i++)
      for (int j = 0; j <= n; j++)
        jump_table[i][j] = jump_table[i - 1][j] == id5 ? id5 : jump_table[i - 1][jump_table[i - 1][j]];
  }

  int up(int node_id, int level) {
    for (int i = nlog; i >= 0; i--)
      if ((level >> i) & 1)
        node_id = jump_table[i][node_id];
    return node_id;
  }

  int lca(int u, int v) {
    if (depth[u] > depth[v])
      swap(u, v);
    v = up(v, depth[v] - depth[u]);
    if (u == v)
      return u;
    for (int i = nlog; i >= 0; i--)
      if (jump_table[i][u] != jump_table[i][v])
        u = jump_table[i][u], v = jump_table[i][v];
    return jump_table[0][u];
  }

  int dist(int u, int v) {
    int l = lca(u, v);
    return depth[u] + depth[v] - 2 * depth[l];
  }

  int furthest_node(int node, int node_lo, int node_hi) {
    int furthest = node, id1 = 0;
    for (int i = node_lo; i <= node_hi; i++)
      if (i != node) {
        int new_dist = dist(node, i);
        if (new_dist > id1)
          furthest = i, id1 = new_dist;
      }
    return furthest;
  }

  int diameter(int node_lo, int node_hi) {
    int node1 = furthest_node(node_lo, node_lo, node_hi);
    int node2 = furthest_node(node1, node_lo, node_hi);
    return dist(node1, node2);
  }
};

} 


namespace Regex {

bool match(string regex_rule, string content) {
  regex r(regex_rule);
  return regex_match(content, r);
}

} 


template <int MOD> ostream &operator<<(ostream &out, const Math::id3<MOD> m) {
  out << m.val;
  return out;
}

template <class T> ostream &operator<<(ostream &out, const vector<T> v) {
  out << "[";
  for (typename vector<T>::iterator it = v.begin(); it != v.end(); it++) {
    out << *it;
    if (next(it) != v.end())
      out << ", ";
  }
  out << "]";
  return out;
}

template <class T, class U> ostream &operator<<(ostream &out, const map<T, U> m) {
  out << "{";
  for (typename map<T, U>::const_iterator it = m.begin(); it != m.end(); it++) {
    out << it->first << " -> " << it->second;
    if (next(it) != m.end())
      out << ", ";
  }
  out << "}";
}

template <class T> ostream &operator<<(ostream &out, const set<T> s) {
  out << "(";
  for (typename set<T>::iterator it = s.begin(); it != s.end(); it++) {
    out << *it;
    if (next(it) != s.end())
      out << ", ";
  }
  out << ")";
}

template <class T, class U> ostream &operator<<(ostream &out, const pair<T, U> p) {
  out << "(" << p.first << ", " << p.second << ")";
  return out;
}



int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  typedef Math::Matrix<Math::Modint, 101, 101> M;

  M mat;

  ll n, k;
  cin >> n >> k;
  vector<ll> v(n + 1);

  for (int i = 1; i <= n; i++) cin >> v[i];
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      mat.val[i][j] = __builtin_popcountll(v[i] ^ v[j]) % 3 == 0;
  
  if (k == 1) {
    cout << n << endl;
  } else {
    M res;
    for (int i = 1; i <= 100; i++) res.val[i][i] = 1;
    ll p = k - 1;
    for (; p; p >>= 1, mat = mat * mat)
      if (p & 1)
        res = res * mat;
    Math::Modint ans = 0;
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= n; j++)
        ans += res.val[i][j];
    cout << ans << endl;
  }
}