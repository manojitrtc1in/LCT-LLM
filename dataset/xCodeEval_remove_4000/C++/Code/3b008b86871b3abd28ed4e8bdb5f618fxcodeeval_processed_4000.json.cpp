



































template <class C>
constexpr auto ssize(const C& c)
    -> std::common_type_t<std::ptrdiff_t,
                          std::make_signed_t<decltype(c.size())>> {
  using R = std::common_type_t<std::ptrdiff_t,
                               std::make_signed_t<decltype(c.size())>>;
  return (R)c.size();
}

template <class T, std::ptrdiff_t N>
constexpr std::ptrdiff_t ssize(const T (&)[N]) noexcept {
  return N;
}

template <typename T>
constexpr std::enable_if_t<std::is_unsigned_v<T>, bool> id3(
    T x) noexcept {
  return x != 0 && (x & (x - 1)) == 0;
}

template <typename T>
constexpr std::enable_if_t<std::is_unsigned_v<T>, int> id5(
    T x) noexcept {
  if constexpr (sizeof(T) <= sizeof(unsigned)) {
    return __builtin_clz(x) - (std::numeric_limits<unsigned>::digits -
                               std::numeric_limits<T>::digits);
  } else if constexpr (sizeof(T) <= sizeof(unsigned long)) {
    return __builtin_clzl(x) - (std::numeric_limits<unsigned long>::digits -
                                std::numeric_limits<T>::digits);
  } else {
    static_assert(sizeof(T) <= sizeof(unsigned long long));
    return __builtin_clzll(x) -
           (std::numeric_limits<unsigned long long>::digits -
            std::numeric_limits<T>::digits);
  }
}

template <typename T>
constexpr std::enable_if_t<std::is_unsigned_v<T>, int> id2(
    T x) noexcept {
  if constexpr (sizeof(T) <= sizeof(unsigned)) {
    return __builtin_ctz(x);
  } else if constexpr (sizeof(T) <= sizeof(unsigned long)) {
    return __builtin_ctzl(x);
  } else {
    static_assert(sizeof(T) <= sizeof(unsigned long long));
    return __builtin_ctzll(x);
  }
}

template <typename T>
constexpr std::enable_if_t<std::is_unsigned_v<T>, int> popcount(T x) noexcept {
  if constexpr (sizeof(T) <= sizeof(unsigned)) {
    return __builtin_popcount(x);
  } else if constexpr (sizeof(T) <= sizeof(unsigned long long)) {
    return __builtin_popcountl(x);
  } else {
    static_assert(sizeof(T) <= sizeof(unsigned long long));
    return __builtin_popcountll(x);
  }
}

template <typename T>
constexpr std::enable_if_t<std::is_unsigned_v<T>, T> bit_width(T x) noexcept {
  return (T)(std::numeric_limits<T>::digits - id5(x));
}

template <typename T>
constexpr std::enable_if_t<std::is_unsigned_v<T>, T> id0(T x) noexcept {
  return (T)(x <= 1 ? 1 : (T)1 << bit_width((T)(x - 1)));
}

template <typename T>
constexpr std::enable_if_t<std::is_unsigned_v<T>, T> bit_floor(T x) noexcept {
  return (T)(x == 0 ? 0 : (T)1 << (bit_width(x) - 1));
}

template <typename Fun>
class id4 {
 public:
  template <typename T>
  explicit id4(T&& fun) : fun_(std::forward<T>(fun)) {}

  template <typename... Args>
  decltype(auto) operator()(Args&&... args) {
    return fun_(std::ref(*this), std::forward<Args>(args)...);
  }

 private:
  Fun fun_;
};

template <typename Fun>
decltype(auto) id6(Fun&& fun) {
  return id4<std::decay_t<Fun>>(std::forward<Fun>(fun));
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const std::optional<T>& opt);

template <typename T1, typename T2>
std::ostream& operator<<(std::ostream& os, const std::pair<T1, T2>& p);

template <typename... Ts>
std::ostream& operator<<(std::ostream& os, const std::tuple<Ts...>& t);

template <typename Container,
          std::enable_if_t<!std::is_convertible_v<Container, std::string_view>,
                           typename Container::const_iterator>* = nullptr>
std::ostream& operator<<(std::ostream& os, const Container& c);

template <typename ContainerAdaptor,
          typename ContainerAdaptor::container_type* = nullptr>
std::ostream& operator<<(std::ostream& os, const ContainerAdaptor& a);

template <typename T>
std::ostream& operator<<(std::ostream& os, const std::optional<T>& opt) {
  return opt ? os << *opt : os << "nullopt";
}

template <typename T1, typename T2>
std::ostream& operator<<(std::ostream& os, const std::pair<T1, T2>& p) {
  return os << '{' << p.first << ", " << p.second << '}';
}

template <typename... Ts>
std::ostream& operator<<(std::ostream& os, const std::tuple<Ts...>& t) {
  return std::apply(
      [&os](const Ts&... args) -> std::ostream& {
        os << '{';
        int i = 0;
        ((os << (i++ == 0 ? "" : ", ") << args), ...);
        return os << '}';
      },
      t);
}

template <typename Container,
          std::enable_if_t<!std::is_convertible_v<Container, std::string_view>,
                           typename Container::const_iterator>*>
std::ostream& operator<<(std::ostream& os, const Container& c) {
  os << '{';
  for (auto it = c.begin(); it != c.end(); ++it) {
    os << (it == c.begin() ? "" : ", ") << *it;
  }
  return os << '}';
}

template <typename ContainerAdaptor, typename ContainerAdaptor::container_type*>
std::ostream& operator<<(std::ostream& os, const ContainerAdaptor& a) {
  class subadaptor : public ContainerAdaptor {
   public:
    const auto& c() const { return ContainerAdaptor::c; }
  };
  return os << static_cast<const subadaptor&>(a).c();
}

namespace detail {

template <typename... Ts>
void print(std::ostream& os, int line, std::string_view keys,
           const Ts&... vals) {
  if constexpr (sizeof...(Ts) == 0) {
    os << "  " << line << " |" << std::endl;
  } else {
    std::vector<std::string_view> key_list;
    key_list.reserve(sizeof...(Ts));
    int start = 0, paren = 0;
    for (int i = 0; i < (int)keys.size(); ++i) {
      switch (keys[i]) {
        case '(':
        case '[':
        case '{':
          ++paren;
          break;
        case ')':
        case ']':
        case '}':
          --paren;
          break;
        case ',':
          if (paren == 0) {
            key_list.push_back(keys.substr(start, i - start));
            start = i;
          }
          break;
      }
    }
    key_list.push_back(keys.substr(start));
    assert(key_list.size() == sizeof...(Ts));
    os << "  " << line << " | ";
    int i = 0;
    ((os << key_list[i++] << " = " << vals), ...);
    os << std::endl;
  }
}

}  




  detail::print(std::cerr, __LINE__, 








template <typename T, typename Join, typename NodeUpdate>
class id1 {
  static_assert(
      std::is_same_v<std::invoke_result_t<Join, const T&, const T&>, T>);
  static_assert(
      std::is_void_v<std::invoke_result_t<NodeUpdate, T&, int, const T&>>);

 public:
  id1(int n, const T& val = T(), const Join& join = Join(),
                const NodeUpdate& node_update = NodeUpdate())
      : join_(join),
        node_update_(node_update),
        n_(n),
        lazy_(id0((unsigned)n_), std::nullopt),
        data_(2 * lazy_.size(), val) {
    init(1, 0, n_ - 1);
  }

  id1(const std::vector<T>& data, const Join& join = Join(),
                const NodeUpdate& node_update = NodeUpdate())
      : join_(join),
        node_update_(node_update),
        n_((int)data.size()),
        lazy_(id0((unsigned)n_), std::nullopt),
        data_(2 * lazy_.size()) {
    init(1, 0, n_ - 1, data);
  }

  int size() const { return n_; }

  void update(int pos, const T& val) { return update(pos, pos, val); }

  

  void update(int first, int last, const T& val) {
    assert(first <= last);
    return update(1, 0, n_ - 1, first, last, val);
  }

  T get(int pos) { return get(pos, pos); }

  

  T get(int first, int last) {
    assert(first <= last);
    return get(1, 0, n_ - 1, first, last);
  }

  template <typename Contains>
  int find(T val, Contains contains) {
    static_assert(
        std::is_same_v<std::invoke_result_t<Contains, const T&, T&>, bool>);
    if (!contains(data_[1], val)) {
      return n_;
    }
    int node = 1, low = 0, high = n_ - 1;
    while (low < high) {
      push(node, low, high);
      int mid = (low + high) >> 1;
      if (contains(data_[node], val)) {
        node = 2 * node;
        high = mid;
      } else {
        node = 2 * node + 1;
        low = mid + 1;
      }
    }
    return low;
  }

  friend std::ostream& operator<<(std::ostream& os, id1 tree) {
    os << '{';
    for (int i = 0; i < tree.size(); ++i) {
      os << (i == 0 ? "" : ", ") << tree.get(i);
    }
    return os << '}';
  }

 private:
  Join join_;
  NodeUpdate node_update_;
  int n_;
  std::vector<std::optional<T>> lazy_;
  std::vector<T> data_;

  void init(int node, int low, int high) {
    if (low == high) {
      return;
    }
    int mid = (low + high) >> 1;
    init(2 * node, low, mid);
    init(2 * node + 1, mid + 1, high);
    data_[node] = join_(data_[2 * node], data_[2 * node + 1]);
  }

  void init(int node, int low, int high, const std::vector<T>& data) {
    if (low == high) {
      data_[node] = data[low];
      return;
    }
    int mid = (low + high) >> 1;
    init(2 * node, low, mid, data);
    init(2 * node + 1, mid + 1, high, data);
    data_[node] = join_(data_[2 * node], data_[2 * node + 1]);
  }

  void update_node(int node, int low, int high, const T& val) {
    node_update_(data_[node], high - low + 1, val);
    if (low == high) {
      return;
    }
    if (lazy_[node]) {
      node_update_(*lazy_[node], 1, val);
    } else {
      lazy_[node] = val;
    }
  }

  void push(int node, int low, int high) {
    if (!lazy_[node]) {
      return;
    }
    int mid = (low + high) >> 1;
    update_node(2 * node, low, mid, *lazy_[node]);
    update_node(2 * node + 1, mid + 1, high, *lazy_[node]);
    lazy_[node].reset();
  }

  void update(int node, int low, int high, int first, int last, const T& val) {
    if (first <= low && high <= last) {
      update_node(node, low, high, val);
      return;
    }
    push(node, low, high);
    int mid = (low + high) >> 1;
    if (first <= mid) {
      update(2 * node, low, mid, first, last, val);
    }
    if (mid < last) {
      update(2 * node + 1, mid + 1, high, first, last, val);
    }
    data_[node] = join_(data_[2 * node], data_[2 * node + 1]);
  }

  T get(int node, int low, int high, int first, int last) {
    if (first <= low && high <= last) {
      return data_[node];
    }
    push(node, low, high);
    int mid = (low + high) >> 1;
    if (last <= mid) {
      return get(2 * node, low, mid, first, last);
    }
    if (mid < first) {
      return get(2 * node + 1, mid + 1, high, first, last);
    }
    return join_(get(2 * node, low, mid, first, last),
                 get(2 * node + 1, mid + 1, high, first, last));
  }
};





template <typename T, typename Join, typename NodeUpdate>
class heavy_light {
  static_assert(
      std::is_same_v<std::invoke_result_t<Join, const T&, const T&>, T>);
  static_assert(
      std::is_void_v<std::invoke_result_t<NodeUpdate, T&, int, const T&>>);

 public:
  heavy_light(const std::vector<std::vector<int>>& graph, int root,
              const Join& join = Join(),
              const NodeUpdate& node_update = NodeUpdate())
      : join_(join),
        tree_((int)graph.size(), T(), join, node_update),
        parent_(graph.size(), -1),
        depth_(graph.size(), 0),
        head_(graph.size(), root),
        pos_(graph.size()),
        last_(graph.size()) {
    std::vector<int> heavy(graph.size(), -1);
    dfs1(root, graph, heavy);
    int index = 0;
    dfs2(root, graph, heavy, index);
  }

  void update(int u, const T& val) { tree_.update(pos_[u], val); }

  void update(int u, int v, const T& val) {
    while (head_[u] != head_[v]) {
      if (depth_[head_[u]] > depth_[head_[v]]) {
        std::swap(u, v);
      }
      tree_.update(pos_[head_[v]], pos_[v], val);
      v = parent_[head_[v]];
    }
    if (depth_[u] > depth_[v]) {
      std::swap(u, v);
    }
    tree_.update(pos_[u], pos_[v], val);
  }

  void update_children(int u, const T& val) {
    tree_.update(pos_[u], last_[u], val);
  }

  T get(int u) { return tree_.get(pos_[u]); }

  T get(int u, int v) {
    std::optional<T> val;
    while (head_[u] != head_[v]) {
      if (depth_[head_[u]] > depth_[head_[v]]) {
        std::swap(u, v);
      }
      T t = tree_.get(pos_[head_[v]], pos_[v]);
      val = val ? join_(*val, t) : t;
      v = parent_[head_[v]];
    }
    if (depth_[u] > depth_[v]) {
      std::swap(u, v);
    }
    T t = tree_.get(pos_[u], pos_[v]);
    return val ? join_(*val, t) : t;
  }

 private:
  Join join_;
  id1<T, Join, NodeUpdate> tree_;
  std::vector<int> parent_, depth_, head_, pos_, last_;

  int dfs1(int u, const std::vector<std::vector<int>>& graph,
           std::vector<int>& heavy) {
    int u_size = 1, heavy_size = 0;
    for (int v : graph[u]) {
      if (v == parent_[u]) {
        continue;
      }
      parent_[v] = u;
      depth_[v] = depth_[u] + 1;
      int v_size = dfs1(v, graph, heavy);
      u_size += v_size;
      if (v_size > heavy_size) {
        heavy_size = v_size;
        heavy[u] = v;
      }
    }
    return u_size;
  }

  void dfs2(int u, const std::vector<std::vector<int>>& graph,
            const std::vector<int>& heavy, int& index) {
    last_[u] = pos_[u] = index++;
    if (heavy[u] != -1) {
      head_[heavy[u]] = head_[u];
      dfs2(heavy[u], graph, heavy, index);
      last_[u] = last_[heavy[u]];
    }
    for (int v : graph[u]) {
      if (v == parent_[u] || v == heavy[u]) {
        continue;
      }
      head_[v] = v;
      dfs2(v, graph, heavy, index);
      last_[u] = last_[v];
    }
  }
};

int main() {
  using namespace std;
  auto start_time = std::chrono::steady_clock::now();
  std::mt19937 thanos(
      (std::uint_fast32_t)start_time.time_since_epoch().count());
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.precision(24);
  int n;
  cin >> n;
  vector<vector<int>> graph(n);
  for (int i = 0; i < n - 1; ++i) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    graph[u].push_back(v);
    graph[v].push_back(u);
  }
  constexpr auto update = [](int& a, int, int b) { a = b; };
  heavy_light<int, plus<int>, decltype(update)> hld(graph, 0, plus<int>(),
                                                    update);
  int q;
  cin >> q;
  while (q--) {
    int type, u;
    cin >> type >> u;
    --u;
    if (type == 1) {
      hld.update_children(u, 1);
    } else if (type == 2) {
      hld.update(0, u, 0);
    } else {
      cout << hld.get(u) << '\n';
    }
  }
  return 0;
}
