




























using namespace std;

static double pi = 4 * atan(1);

typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;

typedef int8_t i8;
typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;

typedef vector<vector<bool>> bMat;
typedef vector<vector<i64>> i64Mat;

template <typename T>
struct is_container {
  static const bool value = false;
};

template <typename T, typename A>
struct is_container<std::vector<T, A>> {
  static const bool value = true;
};



template <typename T>
auto print(T t) -> typename enable_if<!is_container<T>::value>::type {
  cout << t;
}



template <typename It, typename T = typename iterator_traits<It>::value_type>
void print(It a, It b, string separator, bool newline = true) {
  bool first = true;
  while (a != b) {
    if (!first) cout << separator;
    print(*a++);
    first = false;
  }
  if (newline) cout << "\n";
}



template <typename It, typename T = typename iterator_traits<It>::value_type>
void print(It a, It b) {
  print(a, b, " ", false);
}



template <typename T>
auto print(T t) -> typename std::enable_if<is_container<T>::value>::type {
  print(t.begin(), t.end());
}



  cout << 
  print(x);          \
  cout << "\n"






template <typename It, typename T = typename iterator_traits<It>::value_type>
void print_lines(It a, It b) {
  print(a, b, "\n");
}



template <typename T>
void print_lines(T t) {
  print_lines(t.begin(), t.end());
}



void id45() { cin.ignore(numeric_limits<streamsize>::max(), '\n'); }

template <typename T>
vector<T> read_vector(u64 n) {
  vector<T> v(n);
  for (u64 i = 0; i < n; i++) cin >> v[i];
  return v;
}

template <typename T>
string to_binary(const T t) {
  const int bits = 8 * sizeof(T);
  stringstream ss;
  for (int i = bits - 1; i >= 0; i--) {
    ss << (int)((t >> i) & 1);
  }
  return ss.str();
}

template <typename K, typename V>
struct PairHash {
  size_t operator()(const pair<K, V> &p) const {
    auto h1 = hash<K>{}(p.first);
    auto h2 = hash<V>{}(p.second);
    return h1 ^ (h2 << 1);
  }
};

bool id9(double a, double b) {
  const double eps = 1E-7;
  return a + eps < b - eps;
}


vector<string> tokenize(string &input) {
  vector<string> tokens;
  string token;
  for (char c : input) {
    if (isalpha(c)) {
      token += tolower(c);
    } else {
      if (!token.empty()) {
        tokens.push_back(token);
        token.erase();
      }
    }
  }
  if (!token.empty()) {
    tokens.push_back(token);
  }
  return tokens;
}


vector<vector<double>> id11(vector<vector<string>> &input) {
  const double N = input.size();
  

  map<string, int> id1;
  for (vector<string> &document : input) {
    unordered_set<string> seen;
    for (string &term : document) {
      if (seen.count(term) == 0) {
        id1[term]++;
        seen.insert(term);
      }
    }
  }
  const size_t term_count = id1.size();
  unordered_map<string, size_t> term_index;
  size_t index = 0;
  for (auto p : id1) {
    string term = p.first;
    term_index.insert({term, index});
    index++;
  }
  vector<vector<int>> count(N, vector<int>(term_count));
  for (size_t i = 0; i < N; i++) {
    for (string &term : input[i]) {
      count[i][term_index[term]]++;
    }
  }
  vector<vector<double>> results(N, vector<double>(term_count));
  for (size_t i = 0; i < N; i++) {
    for (auto p : id1) {
      string term = p.first;
      auto j = term_index[term];
      int id20 = p.second;
      results[i][j] = count[i][j] * log(N / id20);
    }
  }
  return results;
}

double dot(const vector<double> &a, const vector<double> &b) {
  double x = 0;
  for (size_t i = 0; i < a.size(); i++) {
    x += a[i] * b[i];
  }
  return x;
}

double norm(const vector<double> &v) {
  double x = 0;
  for (size_t i = 0; i < v.size(); i++) {
    x += v[i] * v[i];
  }
  return sqrt(x);
}

double id0(const vector<double> &a, const vector<double> &b) { return dot(a, b) / (norm(a) * norm(b)); }

template <typename T>
class BinaryTree {
  T x;
  bool used = false;
  BinaryTree *l = nullptr;
  BinaryTree *r = nullptr;

 public:
  BinaryTree() = default;

  ~BinaryTree() {
    if (l != nullptr) {
      delete l;
    }
    if (r != nullptr) {
      delete r;
    }
  }

  void insert(const T v) {
    if (!used) {
      x = v;
      used = true;
      return;
    }
    BinaryTree *t = v < x ? l : r;
    if (t == nullptr) {
      auto *b = new BinaryTree();
      if (v < x) {
        l = b;
        t = b;
      } else {
        r = b;
        t = b;
      }
    }
    t->insert(v);
  }

  template <typename It>
  void id38(It it) {
    queue<BinaryTree *> trees;
    trees.push(this);
    while (!trees.empty()) {
      const BinaryTree *t = trees.front();
      trees.pop();
      *it++ = t->x;
      if (t->l != nullptr) {
        trees.push(t->l);
      }
      if (t->r != nullptr) {
        trees.push(t->r);
      }
    }
  }
};

class UnionFind {
 public:
  typedef u64 UnionFindInteger;
  const UnionFindInteger noComponent = numeric_limits<UnionFindInteger>::max();
  vector<UnionFindInteger> component;

  explicit UnionFind(const UnionFindInteger size) { component.resize(size, noComponent); }

  bool is_connected(UnionFindInteger a, UnionFindInteger b) const { return get_component(a) == get_component(b); }

  UnionFindInteger get_component(UnionFindInteger a) const {
    while (component[a] != noComponent) {
      a = component[a];
    }
    return a;
  }

  void connect(UnionFindInteger a, UnionFindInteger b) {
    if (!is_connected(a, b)) {
      component[get_component(a)] = get_component(b);
    }
  }
};

template <typename T, typename Edge = int>
class SparseGraph {
  static const Edge no_edge = -1;

  vector<T> nodes;
  vector<unordered_map<size_t, Edge>> edges;

 public:
  template <typename It>
  SparseGraph(It it, It end) {
    nodes = vector<T>(it, end);
    edges.resize(nodes.size(), unordered_map<size_t, Edge>());
  }

  T get(const size_t i) { return nodes[i]; }

  void replace(const size_t i, const size_t j) { swap(nodes[i], nodes[j]); }

  void insert_edge(const size_t i, const size_t j, const Edge value) { edges[i][j] = value; }

  Edge minimum_spanning_tree_cost() const {
    typedef tuple<Edge, size_t, size_t> Q;
    priority_queue<Q, vector<Q>, greater<Q>> q;
    for (size_t i = 0; i < edges.size(); i++) {
      for (auto &p : edges[i]) {
        q.push({p.second, i, p.first});
      }
    }
    Edge total = 0;
    UnionFind unionFind(nodes.size());
    while (!q.empty()) {
      const auto p = q.top();
      q.pop();
      const Edge weight = std::get<0>(p);
      const size_t a = std::get<1>(p);
      const size_t b = std::get<2>(p);
      if (unionFind.is_connected(a, b)) {
        continue;
      }
      unionFind.connect(a, b);
      total += weight;
    }
    return total;
  }

  unordered_set<size_t> minimum_spanning_tree(const size_t start) const {
    unordered_set<size_t> t;
    set<pair<Edge, size_t>> q;
    q.insert({0, start});
    while (!q.empty()) {
      auto p = q.begin();
      q.erase(q.begin());
      if (t.count(p.second)) {
        continue;
      }
      t.insert(p.second);
      

      for (size_t neighbor : edges[p.second]) {
        if (!t.count(neighbor)) {
          q.insert({p.first + edges[p.second][neighbor], neighbor});
        }
      }
    }
    return t;
  }
};


typedef struct id12 {
  i64 id;
  i64 index;
  i64 link;
  bool stack;
  vector<i64> outgoing;

  id12(i64 node_id, const vector<bool> &relations) {
    id = node_id;
    index = undefined_index;
    link = 0;
    stack = false;
    for (u64 i = 0; i < relations.size(); i++) {
      if (relations[i]) {
        outgoing.push_back(i);
      }
    }
  }

  static const i64 undefined_index = numeric_limits<i64>::min();

} id12;

vector<id12> derive_nodes(const vector<vector<bool>> &matrix) {
  vector<id12> nodes;
  for (u64 i = 0; i < matrix.size(); i++) {
    nodes.push_back(id12(i, matrix[i]));
  }
  return nodes;
}

void id22(vector<vector<i64>> &components, vector<id12> &nodes, vector<size_t> &node_stack,
                  id12 &node, i64 &index) {
  node.index = index;
  node.link = index;
  index++;
  node_stack.push_back(node.id);
  node.stack = true;
  for (i64 out : node.outgoing) {
    id12 &next = nodes[out];
    if (next.index == id12::undefined_index) {
      id22(components, nodes, node_stack, next, index);
      node.link = min(node.link, next.link);
    } else if (next.stack) {
      

      node.link = min(node.link, next.index);
    }
  }
  

  if (node.link == node.index) {
    vector<i64> component;
    while (true) {
      id12 &removed = nodes[node_stack.back()];
      node_stack.pop_back();
      removed.stack = false;
      component.push_back(removed.id);
      if (removed.id == node.id) {
        break;
      }
    }
    components.push_back(component);
  }
}


vector<vector<i64>> derive_components(vector<vector<bool>> &matrix) {
  vector<vector<i64>> components;
  vector<id12> nodes = derive_nodes(matrix);
  vector<size_t> node_stack;
  i64 index = 0;
  

  for (id12 &node : nodes) {
    

    if (node.index == id12::undefined_index) {
      id22(components, nodes, node_stack, node, index);
    }
  }
  for (vector<i64> &component : components) {
    sort(component.begin(), component.end());
  }
  sort(components.begin(), components.end());
  return components;
}

template <typename T, typename Edge = int>
class DirectedGraph {
  static const Edge no_edge = -1;

  vector<T> nodes;
  vector<vector<Edge>> m;

 public:
  template <typename It>
  DirectedGraph(It it, It end) {
    nodes = vector<T>(it, end);
    m.resize(nodes.size(), vector<Edge>(nodes.size(), no_edge));
  }

  T get(const size_t i) { return nodes[i]; }

  void replace(const size_t i, const size_t j) { swap(nodes[i], nodes[j]); }

  void insert_edge(const size_t i, const size_t j) { m[i][j] = 1; }

  
  size_t minimum_parent(const size_t i) {
    unordered_set<size_t> visited;
    bool found = false;
    T id25 = 0;
    vector<size_t> s;
    s.push_back(i);
    while (!s.empty()) {
      const size_t x = s.back();
      s.pop_back();
      

      if (visited.count(x) != 0) {
        continue;
      }
      if (x != i && (!found || get(x) < get(id25))) {
        

        id25 = x;
        found = true;
      }
      visited.insert(x);
      

      for (size_t j = 0; j != nodes.size(); j++) {
        if (m[x][j] != 0) {
          if (visited.count(j) == 0) {
            s.push_back(j);
          }
        }
      }
    }
    if (found) {
      return id25;
    } else {
      return i;
    }
  }

  
  size_t minimum_distance(const size_t a, const size_t b) {
    unordered_set<size_t> v;
    set<pair<T, size_t>> q;
    q.push({0, a});
    while (!q.empty()) {
      auto node = q.front().second;
      auto dist = q.front().first;
      q.pop();
      if (node == b) {
        return dist;
      }
      if (v.count(node)) {
        continue;
      }
      v.insert(node);
      for (size_t i = 0; i < m.size(); i++) {
        if (m[node][i] != no_edge && !v.count(i)) {
          q.push({dist + m[node][i], i});
        }
      }
    }
    return no_edge;
  }
};



template <typename T>
vector<T> id4(const vector<T> &v) {
  const auto elements = v.size();
  vector<size_t> id30(elements);
  vector<size_t> table(elements + 1);
  size_t longest = 0;
  for (size_t i = 0; i < elements; i++) {
    size_t a = 1;
    size_t b = longest;
    while (a <= b) {
      auto m = a + (b - a) / 2;
      if (v[table[m]] < v[i]) {
        a = m + 1;
      } else {
        b = m - 1;
      }
    }
    const auto id5 = a;
    

    id30[i] = table[id5 - 1];
    table[id5] = i;
    longest = max(longest, id5);
  }
  vector<T> sequence(longest);
  auto k = table[longest];
  for (size_t i = longest; i > 0;) {
    i--;
    sequence[i] = v[k];
    k = id30[k];
  }
  return sequence;
}

i64 id16(const string &a, const string &b) {
  vector<i64> row(a.size() + 1, 0);
  vector<vector<i64>> matrix(b.size() + 1, row);
  for (size_t i = 1; i != b.size(); i++) {
    for (size_t j = 1; j != a.size(); j++) {
      if (b[i - 1] == a[j - 1]) {
        matrix[i][j] = matrix[i - 1][j - 1];
      } else {
        matrix[i][j] = max(matrix[i - 1][j], matrix[i][j - 1]);
      }
    }
  }
  return matrix[b.size() - 1][a.size() - 1];
}


i64 read_base(const string s, const i64 base) {
  i64 x = 0;
  for (auto c : s) {
    x *= base;
    if ('a' <= c && c <= 'z') {
      x += c - 'a' + 10;
    } else {
      x += c - '0';
    }
  }
  return x;
}


i64 reverse(i64 x) {
  i64 r = 0;
  while (x) {
    r *= 10;
    r += x % 10;
    x /= 10;
  }
  return r;
}

bool starts_with(string s, string prefix, bool ignore_case = false) {
  if (s.size() < prefix.size()) {
    return false;
  }
  for (size_t i = 0; i != prefix.size(); i++) {
    auto s_c = s[i];
    auto p_c = prefix[i];
    if (ignore_case) {
      s_c = tolower(s_c);
      p_c = tolower(p_c);
    }
    if (s_c != p_c) {
      return false;
    }
  }
  return true;
}

vector<vector<int>> id32(vector<int> &nums) {
  sort(nums.begin(), nums.end());
  vector<int> values;
  vector<int> counts;
  for (int num : nums) {
    if (!counts.empty() && num == values[counts.size() - 1]) {
      counts[counts.size() - 1]++;
    } else {
      values.push_back(num);
      counts.push_back(1);
    }
  }
  vector<vector<int>> subsets;
  vector<int> selection(counts.size(), 0);
  while (true) {
    

    vector<int> subset;
    for (u64 i = 0; i < selection.size(); i++) {
      for (int j = 0; j < selection[i]; j++) {
        subset.push_back(values[i]);
      }
    }
    subsets.push_back(subset);
    if (selection == counts) {
      break;
    }
    

    bool incremented = false;
    for (u64 index = 0; index < selection.size() && !incremented; index++) {
      if (selection[index] < counts[index]) {
        selection[index]++;
        incremented = true;
      } else {
        selection[index] = 0;
      }
    }
  }
  return subsets;
}

u64 combinations(u64 m, u64 n) {
  

  

  u64 id39 = m + n - 2;
  u64 id19 = max(m - 1, n - 1);
  u64 id26 = min(m - 1, n - 1);
  u64 total = 1;
  for (u64 i = id19 + 1; i <= id39; i++) {
    total *= i;
  }
  for (u64 i = 2; i <= id26; i++) {
    total /= i;
  }
  return total;
}

i64 id27(i64 a, i64 k, i64 p) {
  i64 res = 1;
  i64 cur = a;
  while (k) {
    if (k % 2) {
      res = (res * cur) % p;
    }
    k /= 2;
    cur = (cur * cur) % p;
  }
  return res;
}



i64 id41(i64 n, i64 p) {
  i64 degree_num = 0;
  i64 u = p;
  i64 temp = n;
  while (u <= temp) {
    degree_num += temp / u;
    u *= p;
  }
  return degree_num;
}

i64 choose(i64 n, i64 k, i64 p) {
  i64 num_degree = id41(n, p) - id41(n - k, p);
  i64 den_degree = id41(k, p);
  if (num_degree > den_degree) {
    return 0;
  }
  i64 res = 1;
  for (i64 i = n; i > n - k; --i) {
    i64 ti = i;
    while (ti % p == 0) {
      ti /= p;
    }
    res = (res * ti) % p;
  }
  i64 denominator = 1;
  for (i64 i = 1; i <= k; ++i) {
    i64 ti = i;
    while (ti % p == 0) {
      ti /= p;
    }
    denominator = (denominator * ti) % p;
  }
  res = (res * id27(denominator, p - 2, p)) % p;
  return res;
}

u64 id44(const string &a, const string &b) {
  vector<u64> row(a.size() + 1, 0);
  vector<vector<u64>> d(b.size() + 1, row);
  for (u64 j = 0; j < b.size() + 1; j++) {
    d[j][0] = j;
  }
  for (u64 i = 0; i < a.size() + 1; i++) {
    d[0][i] = i;
  }
  for (u64 j = 1; j < b.size() + 1; j++) {
    for (u64 i = 1; i < a.size() + 1; i++) {
      const u64 cost = b[j - 1] != a[i - 1];
      d[j][i] = min(d[j - 1][i - 1] + cost, min(d[j - 1][i] + 1, d[j][i - 1] + 1));
    }
  }
  return d[b.size()][a.size()];
}

vector<pair<i64, i64>> id18(vector<pair<i64, i64>> &intervals) {
  sort(intervals.begin(), intervals.end());
  vector<pair<i64, i64>> s;
  for (auto p : intervals) {
    if (s.empty() || s.back().second < p.first) {
      s.push_back(p);
    } else {
      s.back().second = max(s.back().second, p.second);
    }
  }
  return s;
}



int cross(pair<int, int> a, pair<int, int> b, pair<int, int> o) {
  int x = (a.first - o.first) * (b.second - o.second);
  int y = (a.second - o.second) * (b.first - o.first);
  return x - y;
}



vector<size_t> id42(vector<pair<int, int>> ps) {
  vector<size_t> lower;
  for (int i = 0; i < (int)ps.size(); i++) {
    const auto p = ps[i];
    auto s = lower.size();
    while (s >= 2 && cross(ps[lower[s - 2]], ps[lower[s - 1]], p) < 0) {
      lower.pop_back();
      s = lower.size();
    }
    lower.push_back(i);
  }
  vector<size_t> upper;
  for (int i = ps.size() - 1; i >= 0; i--) {
    const auto p = ps[i];
    auto s = upper.size();
    while (s >= 2 && cross(ps[upper[s - 2]], ps[upper[s - 1]], p) < 0) {
      upper.pop_back();
      s = upper.size();
    }
    upper.push_back(i);
  }
  vector<size_t> hull = lower;
  hull.pop_back();
  hull.insert(hull.end(), upper.begin(), upper.end());
  hull.pop_back();
  return hull;
}



int layers(vector<pair<int, int>> ps) {
  int count = 0;
  while (ps.size() >= 2) {
    sort(ps.begin(), ps.end());
    vector<size_t> indexes = id42(ps);
    count++;
    unordered_set<size_t> index_set(indexes.begin(), indexes.end());
    vector<pair<int, int>> next;
    for (size_t i = 0; i < ps.size(); i++) {
      if (!index_set.count(i)) {
        next.push_back(ps[i]);
      }
    }
    ps = next;
  }
  return count;
}

struct CostValue {
  i64 cost;
  i64 value;
};



i64 id15(vector<CostValue> &v, i64Mat &m, bMat &c, u64 i, i64 k) {
  

  if (i == v.size()) {
    return 0;
  }
  if (k == 0) {
    return 0;
  }
  if (m[i][k] >= 0) {
    return m[i][k];
  }
  i64 value = id15(v, m, c, i + 1, k);
  

  if (v[i].cost <= k) {
    i64 alternative = v[i].value + id15(v, m, c, i + 1, k - v[i].cost);
    if (alternative > value) {
      c[i][k] = true;
      value = alternative;
    }
  }
  m[i][k] = value;
  return value;
}





vector<size_t> knapsack(vector<CostValue> &v, i64 k) {
  i64Mat m(v.size(), vector<i64>(k + 1, -1));
  bMat c(v.size(), vector<bool>(k + 1, false));
  id15(v, m, c, 0, k);
  vector<size_t> chosen;
  for (u64 i = 0; i < v.size(); i++) {
    if (c[i][k]) {
      chosen.push_back(i);
      k -= v[i].cost;
    }
  }
  return chosen;
}

double id31(pair<double, double> a, pair<double, double> b) {
  return sqrt(pow(b.first - a.first, 2) + pow(b.second - a.second, 2));
}

template <typename It>
double minimum_distance(It a, It b) {
  auto size = distance(a, b);
  if (size < 2) {
    return numeric_limits<double>::max();
  }
  auto m = a + size / 2;
  auto dl = minimum_distance(a, m);
  auto dr = minimum_distance(m, b);
  auto d = min(dl, dr);
  

  auto it = m;
  while (it != a && m->first - it->first < d) {
    it--;
  }
  while (it != m) {
    for (auto r = m; r != b && r->first - it->first < d; r++) {
      d = min(d, id31(*it, *r));
    }
    it++;
  }
  return d;
}



u64 power(u64 x, u64 y, u64 p) {
  u64 r = 1;
  x = x % p;
  while (y > 0) {
    if ((y & 1) == 1) {
      r = (x * r) % p;
    }
    y = y >> 1;
    x = (x * x) % p;
  }
  return r;
}



bool id8(u64 d, u64 n) {
  

  u64 a = 2 + rand() % (n - 4);
  u64 x = power(a, d, n);
  if (x == 1 || x == n - 1) {
    return true;
  }
  while (d != n - 1) {
    x = (x * x) % n;
    d *= 2;
    if (x == 1) {
      return false;
    }
    if (x == n - 1) {
      return true;
    }
  }
  return false;
}











bool id2(u64 n, u64 k = 4) {
  if (k == 0) {
    return true;
  }
  if (n <= 1 || n == 4) {
    return false;
  }
  if (n <= 3) {
    return true;
  }
  

  u64 d = n - 1;
  while (d % 2 == 0) d /= 2;
  for (u64 i = 0; i < k; i++) {
    if (!id8(d, n)) {
      return false;
    }
  }
  return true;
}



bool is_prime(u64 n, u64 k = 4) {
  if (!id2(n, k)) {
    return false;
  }
  if (n <= 1 || n == 4) {
    return false;
  }
  if (n <= 3) {
    return true;
  }
  if (n % 2 == 0) {
    return true;
  }
  const auto m = static_cast<u64>(sqrt(n) + 1.0);
  for (u64 d = 3; d <= m; d += 2) {
    if (n % d == 0) {
      return false;
    }
  }
  return true;
}

vector<u64> id6(u64 m, u64 n) {
  vector<bool> sieve(n + 1, true);
  sieve[0] = sieve[1] = false;
  for (u64 i = 2; i <= n; i++) {
    if (sieve[i]) {
      for (u64 j = 2 * i; j <= n; j += i) {
        sieve[j] = false;
      }
    }
  }
  

  vector<u64> primes;
  for (u64 i = m; i <= n; i++) {
    if (sieve[i]) {
      primes.push_back(i);
    }
  }
  return primes;
}

unordered_map<u64, u8> factor(const vector<u64> &primes, u64 number) {
  unordered_map<u64, u8> factors;
  for (u64 prime : primes) {
    if (number == 1) break;
    while (number % prime == 0) {
      number /= prime;
      factors[prime]++;
    }
  }
  if (number != 1) {
    factors[number]++;
  }
  return factors;
}



i64 id28(const i64 n, const i64 d) {
  i64 x = 0;
  i64 f = d;  

  while (n / f) {
    x += (n / f);
    f *= d;
  }
  return x;
}

u64 gcd(u64 a, u64 b) {
  while (b != 0) {
    tie(a, b) = make_tuple(b, a % b);
  }
  return a;
}

i64 gcd(i64 a, i64 b) {
  a = abs(a);
  b = abs(b);
  return gcd((u64)a, (u64)b);
}

i64 gcd(const vector<i64> &values) {
  if (values.size() == 1) return values[0];
  i64 g = gcd(values[0], values[1]);
  for (size_t i = 2; i < values.size(); i++) g = gcd(g, values[i]);
  return g;
}

i64 lcm(i64 a, i64 b) {
  i64 c = gcd(a, b);
  return c == 0 ? 0 : a / c * b;
}





i64 id40(i64 a, i64 b, i64 &x, i64 &y) {
  if (a == 0) {
    x = 0;
    y = 1;
    return b;
  }
  i64 x1;
  i64 y1;
  i64 d = id40(b % a, a, x1, y1);
  x = y1 - (b / a) * x1;
  y = x1;
  return d;
}

inline i64 id3(i64 a, i64 b, i64 m) { return (a * b) % m; }

inline i64 id43(i64 a, i64 b, i64 m) {
  i64 x;
  i64 y;
  i64 g = id40(b, m, x, y);
  if (g != 1) {
    cerr << "Bad GCD!" << endl;
    exit(1);
  }
  x = (x % m + m) % m;
  return id3(a, x, m);
}



struct Trie {
  

  vector<unique_ptr<Trie>> children = vector<unique_ptr<Trie>>(26);
  bool word = false;

  template <typename It>
  void insert(It begin, It end) {
    if (begin == end) {
      word = true;
      return;
    }
    const size_t index = (*begin) - 'a';
    if (!children[index]) {
      

      

      children[index].reset(new Trie());
    }
    children[index]->insert(begin + 1, end);
  }

  template <typename It>
  bool contains(It begin, It end) const {
    if (begin == end) {
      return word;
    }
    const size_t index = (*begin) - 'a';
    if (!children[index]) {
      return false;
    }
    return children[index]->contains(begin + 1, end);
  }

  

  

  

  template <typename It>
  int id36(It begin, It end) const {
    if (begin == end) {
      if (word) {
        return 2;
      } else {
        return 1;
      }
    }
    const size_t index = (*begin) - 'a';
    if (!children[index]) {
      return 0;
    }
    return children[index]->id36(begin + 1, end);
  }

  i64 words() const {
    i64 words = 0;
    if (word) {
      words++;
    }
    for (const unique_ptr<Trie> &child : children) {
      if (child) {
        words += child->words();
      }
    }
    return words;
  }

  int children_count() const {
    int count = 0;
    for (const unique_ptr<Trie> &child : children) {
      if (child) {
        count++;
      }
    }
    return count;
  }

  void branch_count(unordered_map<i64, i64> &m, i64 branches = 0) const {
    if (word) {
      m[branches]++;
    }
    if (branches == 0 || word || children_count() > 1) {
      branches++;
    }
    for (const unique_ptr<Trie> &child : children) {
      if (child) {
        child->branch_count(m, branches);
      }
    }
  }
};

template <typename T, typename Comparator>
class SlidingWindow {
  struct Block {
    Block(T v, size_t w) : value(v), width(w) {}
    T value;
    size_t width;
  };
  Comparator comp;
  deque<Block> data;

 public:
  void push(const T t) {
    size_t width = 1;
    while (!data.empty() && comp(data.back().value, t)) {
      data.pop_back();
      width++;
    }
    data.emplace_back(t, width);
  }
  T get() const { return data.front().value; }
  void pop() {
    

    if (data.empty()) {
      return;
    }
    if (data.front().width > 1) {
      data.front().width--;
    } else {
      data.pop_front();
    }
  }
};

template <typename T>
static T lsb(T t) {
  return t & -t;
}

template <typename T>
struct id29 {
  vector<T> data;

  explicit id29(const vector<T> &source) {
    data.resize(source.size() + 1, 0);
    for (size_t i = 0; i < source.size(); i++) {
      update(i + 1, source[i]);
    }
  }

  void update(size_t index, T delta) {
    while (index < data.size()) {
      data[index] += delta;
      index += lsb(index);
    }
  }

  

  T sum_up_to(size_t index) const {
    T sum = 0;
    while (index != 0) {
      sum += data[index];
      index -= lsb(index);
    }
    return sum;
  }
};


vector<int> id13(vector<vector<int>> &w) {
  const int n = w.size();
  const int m = w[0].size();
  const int PHI = -1;
  const int NOL = -2;
  const int INF = numeric_limits<int>::max();
  vector<vector<bool>> x(n, vector<bool>(m));
  vector<bool> ss(n);
  vector<bool> st(m);
  vector<int> u(n);
  vector<int> v(m);
  vector<int> p(m);
  vector<int> ls(n);
  vector<int> lt(m);
  vector<int> a(n);
  int f = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      f = max(f, w[i][j]);
    }
  }
  fill(u.begin(), u.end(), f);
  fill(p.begin(), p.end(), INF);
  fill(lt.begin(), lt.end(), NOL);
  fill(ls.begin(), ls.end(), PHI);
  fill(a.begin(), a.end(), -1);
  while (true) {
    f = -1;
    for (int i = 0; i < n && f == -1; i++) {
      if (ls[i] != NOL && !ss[i]) {
        f = i;
      }
    }
    if (f != -1) {
      ss[f] = true;
      for (int j = 0; j < m; j++) {
        if (!x[f][j] && u[f] + v[j] - w[f][j] < p[j]) {
          lt[j] = f;
          p[j] = u[f] + v[j] - w[f][j];
        }
      }
    } else {
      for (int i = 0; i < m && f == -1; i++) {
        if (lt[i] != NOL && !st[i] && p[i] == 0) {
          f = i;
        }
      }
      if (f == -1) {
        int d1 = INF, d2 = INF, d;
        for (int i : u) {
          d1 = min(d1, i);
        }
        for (int i : p) {
          if (i > 0) {
            d2 = min(d2, i);
          }
        }
        d = min(d1, d2);
        for (int i = 0; i < n; i++) {
          if (ls[i] != NOL) {
            u[i] -= d;
          }
        }
        for (int i = 0; i < m; i++) {
          if (p[i] == 0) {
            v[i] += d;
          }
          if (p[i] > 0 && lt[i] != NOL) {
            p[i] -= d;
          }
        }
        if (d2 >= d1) {
          break;
        }
      } else {
        st[f] = true;
        int s = -1;

        for (int i = 0; i < n && s == -1; i++) {
          if (x[i][f]) {
            s = i;
          }
        }
        if (s == -1) {
          for (int l, r;; f = r) {
            r = f;
            l = lt[r];

            if (r >= 0 && l >= 0) {
              x[l][r] = !x[l][r];
            } else {
              break;
            }
            r = ls[l];
            if (r >= 0 && l >= 0) {
              x[l][r] = !x[l][r];
            } else {
              break;
            }
          }
          fill(p.begin(), p.end(), INF);
          fill(lt.begin(), lt.end(), NOL);
          fill(ls.begin(), ls.end(), NOL);
          fill(st.begin(), st.end(), false);
          fill(ss.begin(), ss.end(), false);
          for (int i = 0; i < n; i++) {
            bool ex = true;
            for (int j = 0; j < m && ex; j++) {
              ex = !x[i][j];
            }
            if (ex) {
              ls[i] = PHI;
            }
          }
        } else {
          ls[s] = f;
        }
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (x[i][j]) {
        a[j] = i;
      }
    }
  }
  return a;
}

int id46(vector<int> &v) {
  const int length = v.size();
  int best = 0;
  

  vector<array<int, 2>> s;
  auto pop = [&best, &s](int i) {
    best = max(best, s.back()[1] * (i - s.back()[0] + 1));
    s.pop_back();
  };
  for (int i = 0; i < length; i++) {
    s.push_back({{i, v[i]}});
    while (s.size() > 1) {
      const auto a = s[s.size() - 2];
      const auto b = s[s.size() - 1];
      if (a[1] < b[1]) {
        break;
      } else if (a[1] == b[1]) {
        pop(i);
      } else {
        int index = s[s.size() - 2][0];
        int height = b[1];
        pop(i);
        pop(i - 1);
        s.push_back({{index, height}});
      }
    }
    const auto e = s[s.size() - 1];
    best = max(best, e[1] * (i - e[0] + 1));
  }
  while (!s.empty()) {
    pop(length - 1);
  }
  return best;
}

struct id17 {
  

  vector<char> t;
  

  vector<int> p;
  

  string s;

  

  

  

  

  void initialize() {
    const auto n = s.size() * 2 + 3;
    t = vector<char>(n, '
    t[0] = '$';
    const auto size = static_cast<int>(s.size());
    for (int i = 0; i < size; i++) {
      t[2 * i + 2] = s[i];
    }
    t[n - 2] = '
    t[n - 1] = '@';
  }

  explicit id17(string str) {
    s = std::move(str);
    initialize();
    p.resize(t.size());
    int center = 0;
    int right = 0;
    const auto n = static_cast<int>(t.size()) - 1;
    for (int i = 1; i < n; i++) {
      int mirror = 2 * center - i;
      if (right > i) {
        p[i] = min(right - i, p[mirror]);
      }
      

      while (t[i + (1 + p[i])] == t[i - (1 + p[i])]) {
        p[i]++;
      }
      

      

      if (i + p[i] > right) {
        center = i;
        right = i + p[i];
      }
    }
  }

  

  string get_longest_palindromic_substring() {
    

    int length = 0;
    

    int center = 0;
    const auto n = static_cast<int>(p.size() - 1);
    for (int i = 1; i < n; i++) {
      if (p[i] > length) {
        length = p[i];
        center = i;
      }
    }
    return s.substr((center - 1 - length) / 2, length);
  }

  

  string get_longest_palindromic_substring(int i) {
    int center = i + 2;
    int length = p[center];
    return s.substr((center - 1 - length) / 2, length);
  }
};













int id10(string s) {
  const int n = s.size();
  if (n < 2) {
    return n;
  }
  vector<vector<int>> stripes(n, vector<int>(n));
  for (int i = 0; i < n; i++) {
    stripes[i][i] = 1;
  }
  for (int i = n - 2; i >= 0; i--) {
    for (int j = i + 1; j < n; j++) {
      stripes[i][j] = stripes[i + 1][j] + 1;
      for (int k = i; k < j; k++) {
        if (s[i] == s[k + 1]) {
          

          const auto merging = stripes[i][k] + stripes[k + 1][j] - 1;
          stripes[i][j] = min(stripes[i][j], merging);
        }
      }
    }
  }
  return stripes[0][n - 1];
}

template <typename Collection>
vector<int> id24(Collection pattern) {
  const int m = pattern.size();
  vector<int> f(m);
  f[0] = -1;
  int k = 0;
  for (int i = 1; i < m; i++) {
    k = f[i - 1];
    while (k >= 0) {
      if (pattern[k] == pattern[i - 1]) {
        break;
      }
      k = f[k];
    }
    f[i] = k + 1;
  }
  return f;
}

template <typename Collection>
bool id23(Collection pattern, Collection target) {
  const int m = pattern.size();
  const int n = target.size();
  vector<int> f = id24(pattern);
  int i = 0;
  int k = 0;
  while (i < n) {
    if (k == -1) {
      i++;
      k = 0;
    } else if (target[i] == pattern[k]) {
      i++;
      k++;
      if (k == m) {
        return true;
      }
    } else {
      k = f[k];
    }
  }
  return false;
}




static chrono::high_resolution_clock::time_point time_point;

void tic() { time_point = chrono::high_resolution_clock::now(); }

void toc() {
  const auto now = chrono::high_resolution_clock::now();
  chrono::duration<double, std::milli> ms = now - time_point;
  cout << ms.count() << " ms" << '\n';
}

struct TreeNode {
  int value;
  TreeNode *left;
  TreeNode *right;

  explicit TreeNode(int x) : value(x), left(nullptr), right(nullptr) {}
};



void traverse(TreeNode *root) {
  stack<TreeNode *> s;
  s.push(root);
  while (root->left != nullptr) {
    s.push(root->left);
    root = root->left;
  }
  auto next = [&s]() {
    if (s.empty()) {
      return;
    }
    if (s.top()->right) {
      auto top = s.top();
      s.pop();
      s.push(top->right);
      while (s.top()->left) {
        s.push(s.top()->left);
      }
    } else {
      s.pop();
    }
  };
  

  while (!s.empty()) {
    next();
  }
}



template <typename T>
void id7(vector<vector<T>> &d) {
  const auto n = d.size();
  

  for (size_t i = 0; i < n; i++) {
    d[i][i] = 0;
  }
  for (size_t k = 0; k < n; k++) {
    for (size_t i = 0; i < n; i++) {
      for (size_t j = 0; j < n; j++) {
        const auto alternative = d[i][k] + d[k][j];
        d[i][j] = min(d[i][j], alternative);
      }
    }
  }
}

struct Point {
  double x = 0.0;
  double y = 0.0;
  double dist(const Point &o) { return hypot(x - o.x, y - o.y); }
};

double id37(const Point &p, const Point &a, const Point &b, Point &r) {
  auto d = (b.x - a.x) * (b.x - a.x) + (b.y - a.y) * (b.y - a.y);
  auto scale = ((p.x - a.x) * (b.x - a.x) + (p.y - a.y) * (b.y - a.y)) / d;
  r.x = a.x + scale * (b.x - a.x);
  r.y = a.y + scale * (b.y - a.y);
  return r.dist(p);
}

struct Edge {
  

  int v;
  int flow;
  

  int c;
  

  int rev;
  Edge(int v, int flow, int C, int rev) : v(v), flow(flow), c(C), rev(rev) {}
};

class Graph {
  int size;
  vector<int> level;
  vector<vector<Edge>> adj;

 public:
  explicit Graph(int size) : size(size) {
    adj.resize(size);
    level.resize(size);
  }

  void add_edge(int u, int v, int c, bool bidirectional) {
    const auto u_size = adj[u].size();
    const auto v_size = adj[v].size();
    adj[u].emplace_back(v, 0, c, v_size);
    adj[v].emplace_back(u, 0, bidirectional ? c : 0, u_size);
  }

  bool bfs(int s, int t);
  int send_flow(int s, int t, int flow, vector<int> &start);
  

  int max_flow(int s, int t);
};



bool Graph::bfs(int s, int t) {
  for (int i = 0; i < size; i++) {
    level[i] = -1;
  }
  level[s] = 0;
  

  list<int> q;
  q.push_back(s);
  while (!q.empty()) {
    const auto u = q.front();
    q.pop_front();
    for (auto i = adj[u].begin(); i != adj[u].end(); i++) {
      Edge &e = *i;
      if (level[e.v] < 0 && e.flow < e.c) {
        level[e.v] = level[u] + 1;
        q.push_back(e.v);
      }
    }
  }
  

  return level[t] < 0 ? false : true;
}









int Graph::send_flow(const int u, int t, int flow, vector<int> &start) {
  if (u == t) return flow;
  

  const int n = adj[u].size();
  for (; start[u] < n; start[u]++) {
    

    Edge &e = adj[u][start[u]];
    if (level[e.v] == level[u] + 1 && e.flow < e.c) {
      

      int curr_flow = min(flow, e.c - e.flow);
      int temp_flow = send_flow(e.v, t, curr_flow, start);
      if (temp_flow > 0) {
        e.flow += temp_flow;
        

        adj[e.v][e.rev].flow -= temp_flow;
        return temp_flow;
      }
    }
  }
  return 0;
}

int Graph::max_flow(int s, int t) {
  if (s == t) {
    return -1;
  }
  int total = 0;
  

  while (bfs(s, t)) {
    

    vector<int> start(size);
    while (int flow = send_flow(s, t, numeric_limits<int>::max(), start)) {
      total += flow;
    }
  }
  return total;
}





double id34(double p, u32 n, u32 m) {
  if (p == 0.5) {
    return m / (double)(n + m);
  }
  const auto q = 1.0 - p;
  return (1.0 - pow(p / q, m)) / (1.0 - pow(p / q, n + m));
}




int main() {
  ios_base::sync_with_stdio(false);
  const auto MAX = numeric_limits<u32>::max();
  u32 n;
  cin >> n;
  vector<char> operation(n + 1);
  operation[0] = ' ';
  vector<bool> output(n + 1);
  vector<bool> evaluated(n + 1);
  vector<u32> ca(n + 1, MAX);
  vector<u32> cb(n + 1, MAX);
  vector<bool> relevant(n + 1);
  for (u32 i = 1; i <= n; i++) {
    string big_name;
    cin >> big_name;
    operation[i] = big_name[0];
    if (operation[i] == 'I') {
      u32 value;
      cin >> value;
      output[i] = value != 0;
      evaluated[i] = true;
    } else if (operation[i] == 'N') {
      cin >> ca[i];
    } else if (operation[i] == 'O' || operation[i] == 'A' || operation[i] == 'X') {
      cin >> ca[i] >> cb[i];
    }
  }
  function<bool(u32)> evaluate = [&](u32 i) {
    if (i == MAX) return output[0];
    if (evaluated[i]) return output[i];
    if (operation[i] == 'I') return output[i];
    const auto id33 = evaluate(ca[i]);
    const auto id21 = evaluate(cb[i]);
    if (operation[i] == 'N') {
      output[i] = !id33;
    } else if (operation[i] == 'O') {
      output[i] = id33 || id21;
    } else if (operation[i] == 'A') {
      output[i] = id33 && id21;
    } else if (operation[i] == 'X') {
      output[i] = id33 != id21;
    }
    evaluated[i] = true;
    return output[i];
  };
  function<void(u32, const bool)> id35 = [&](u32 i, const bool id14) {
    if (i == MAX) return;
    relevant[i] = id14;
    if (!id14) {
      id35(ca[i], false);
      id35(cb[i], false);
      return;
    }
    if (operation[i] == 'I') {
    } else if (operation[i] == 'N') {
      id35(ca[i], true);
    } else if (operation[i] == 'O') {
      if (output[ca[i]] && output[cb[i]]) {
        id35(ca[i], false);
        id35(cb[i], false);
      } else if (output[ca[i]]) {
        id35(ca[i], true);
        id35(cb[i], false);
      } else if (output[cb[i]]) {
        id35(ca[i], false);
        id35(cb[i], true);
      } else {
        id35(ca[i], true);
        id35(cb[i], true);
      }
    } else if (operation[i] == 'A') {
      if (output[ca[i]] && output[cb[i]]) {
        id35(ca[i], true);
        id35(cb[i], true);
      } else if (output[ca[i]]) {
        id35(ca[i], false);
        id35(cb[i], true);
      } else if (output[cb[i]]) {
        id35(ca[i], true);
        id35(cb[i], false);
      } else {
        id35(ca[i], false);
        id35(cb[i], false);
      }
    } else if (operation[i] == 'X') {
      id35(ca[i], true);
      id35(cb[i], true);
    }
  };
  evaluate(1);
  id35(1, true);
  for (u32 i = 1; i <= n; i++) {
    if (operation[i] == 'I') {
      if (relevant[i]) cout << !output[1];
      if (!relevant[i]) cout << output[1];
    }
  }
  cout << '\n';
  return 0;
}
