




























using namespace std;

template <typename T1, typename T2>
std::ostream& operator<<(std::ostream& os, const std::pair<T1, T2>& p) {
  return os << '{' << p.first << ", " << p.second << '}';
}

template <typename Container,
          std::enable_if_t<!std::is_convertible_v<Container, std::string_view>,
                           typename Container::const_iterator>* = nullptr>
std::ostream& operator<<(std::ostream& os, const Container& c) {
  os << '{';
  for (auto it = c.begin(); it != c.end(); ++it) {
    if (it != c.begin()) {
      os << ", ";
    }
    os << *it;
  }
  return os << '}';
}

namespace detail {

template <typename T>
void print(std::string_view name, const T& val) {
  std::cerr << name << " = " << val << std::endl;
}

template <typename T1, typename... Ts>
void print(std::string_view names, const T1& val1, const Ts&... vals) {
  for (int i = 0, paren = 0; i < (int)names.size(); ++i) {
    if (names[i] == '(' || names[i] == '{') {
      ++paren;
    } else if (names[i] == ')' || names[i] == '}') {
      --paren;
    } else if (names[i] == ',' && paren == 0) {
      std::cerr << names.substr(0, i) << " = " << val1 << ',';
      return print(names.substr(i + 1), vals...);
    }
  }
}

}  




  do {                                        \
    std::cerr << "  " << __LINE__ << " | ";   \
    detail::print(
  } while (false)


























































































































































































































































































































































































































































































































































































template <typename T, typename JoinFn, typename UpdateFn>
class id1 {
 public:
  id1(int n, const T& zero = T(), const JoinFn& join_fn = JoinFn(),
                const UpdateFn& update_fn = UpdateFn())
      : join_fn_(join_fn),
        id0(update_fn),
        n_(n),
        data_(2 * id2(n_) - 1, zero),
        lazy_(data_.size(), std::nullopt) {}

  id1(const std::vector<T>& data, const JoinFn& join_fn = JoinFn(),
                const UpdateFn& update_fn = UpdateFn())
      : join_fn_(join_fn),
        id0(update_fn),
        n_((int)data.size()),
        data_(2 * id2(n_) - 1),
        lazy_(data_.size(), std::nullopt) {
    init(0, 0, n_ - 1, data);
  }

  int size() const { return n_; }

  void update(int pos, const T& val) { return update(pos, pos, val); }

  void update(int first, int last, const T& val) {
    return update(0, 0, n_ - 1, first, last, val);
  }

  T query(int pos) { return query(pos, pos); }

  

  T query(int first, int last) { return query(0, 0, n_ - 1, first, last); }

  

  template <typename ContainsFn>
  int find(T val, ContainsFn contains_fn) {
    if (!contains_fn(data_[0], val)) {
      return n_;
    }
    return find(0, 0, n_ - 1, val, contains_fn);
  }

  friend std::ostream& operator<<(std::ostream& os, id1 tree) {
    os << '{';
    for (int i = 0; i < tree.size(); ++i) {
      if (i != 0) {
        os << ", ";
      }
      os << tree.query(i);
    }
    return os << '}';
  }

 private:
  JoinFn join_fn_;
  UpdateFn id0;
  const int n_;
  std::vector<T> data_;
  std::vector<std::optional<T>> lazy_;

  static constexpr int id2(int x) {
    --x;
    x |= x >> 1;
    x |= x >> 2;
    x |= x >> 4;
    x |= x >> 8;
    x |= x >> 16;
    return ++x;
  }

  void init(int node, int t_first, int t_last, const std::vector<T>& data) {
    if (t_first == t_last) {
      data_[node] = data[t_first];
      return;
    }
    int t_mid = (t_first + t_last) >> 1;
    init(2 * node + 1, t_first, t_mid, data);
    init(2 * node + 2, t_mid + 1, t_last, data);
    data_[node] = join_fn_(data_[2 * node + 1], data_[2 * node + 2]);
  }

  void push(int node, int t_first, int t_last) {
    if (!lazy_[node]) {
      return;
    }
    id0(data_[node], *lazy_[node]);
    if (t_first != t_last) {
      int left = 2 * node + 1, right = 2 * node + 2;
      lazy_[left] =
          lazy_[left] ? join_fn_(*lazy_[left], *lazy_[node]) : *lazy_[node];
      lazy_[right] =
          lazy_[right] ? join_fn_(*lazy_[right], *lazy_[node]) : *lazy_[node];
    }
    lazy_[node].reset();
  }

  void update(int node, int t_first, int t_last, int first, int last,
              const T& val) {
    push(node, t_first, t_last);
    if (first <= t_first && t_last <= last) {
      id0(data_[node], val);
      if (t_first != t_last) {
        lazy_[2 * node + 1] =
            lazy_[2 * node + 1] ? join_fn_(*lazy_[2 * node + 1], val) : val;
        lazy_[2 * node + 2] =
            lazy_[2 * node + 2] ? join_fn_(*lazy_[2 * node + 2], val) : val;
      }
      return;
    }
    int t_mid = (t_first + t_last) >> 1;
    if (first <= t_mid) {
      update(2 * node + 1, t_first, t_mid, first, last, val);
    }
    if (t_mid < last) {
      update(2 * node + 2, t_mid + 1, t_last, first, last, val);
    }
    data_[node] = join_fn_(data_[2 * node + 1], data_[2 * node + 2]);
  }

  T query(int node, int t_first, int t_last, int first, int last) {
    push(node, t_first, t_last);
    if (first <= t_first && t_last <= last) {
      return data_[node];
    }
    int t_mid = (t_first + t_last) >> 1;
    if (last <= t_mid) {
      return query(2 * node + 1, t_first, t_mid, first, last);
    }
    if (t_mid < first) {
      return query(2 * node + 2, t_mid + 1, t_last, first, last);
    }
    return join_fn_(query(2 * node + 1, t_first, t_mid, first, last),
                    query(2 * node + 2, t_mid + 1, t_last, first, last));
  }

  template <typename ContainsFn>
  int find(int node, int t_first, int t_last, T& val, ContainsFn contains_fn) {
    push(node, t_first, t_last);
    if (t_first == t_last) {
      return t_first;
    }
    int t_mid = (t_first + t_last) >> 1;
    if (contains_fn(data_[2 * node + 1], val)) {
      return find(2 * node + 1, t_first, t_mid, val, contains_fn);
    } else {
      return find(2 * node + 2, t_mid + 1, t_last, val, contains_fn);
    }
  }
};



int main() {
  std::mt19937 rng(
      std::chrono::high_resolution_clock::now().time_since_epoch().count());
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout << std::boolalpha;
  std::cerr << std::boolalpha;
  int n, k;
  cin >> n >> k;
  vector<vector<int>> a(n, vector<int>(k));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < k; ++j) {
      cin >> a[i][j];
    }
  }
  auto join = [](const pair<int, int>& a, const pair<int, int>& b) {
    return pair(min(a.first, b.first), max(a.second, b.second));
  };
  auto update = [](pair<int, int>& a, const pair<int, int>& b) { a = b; };
  vector<id1<pair<int, int>, decltype(join), decltype(update)>> trees(
      1 << k, id1<pair<int, int>, decltype(join), decltype(update)>(
                  n, {1e9, -1e9}, join, update));
  for (int mask = 0; mask < (1 << k); ++mask) {
    for (int i = 0; i < n; ++i) {
      int val = 0;
      for (int j = 0; j < k; ++j) {
        if (mask & (1 << j)) {
          val += a[i][j];
        } else {
          val -= a[i][j];
        }
      }
      trees[mask].update(i, {val, val});
    }
  }
  int q;
  cin >> q;
  while (q--) {
    int type;
    cin >> type;
    if (type == 1) {
      int i;
      cin >> i;
      --i;
      vector<int> b(k);
      for (int j = 0; j < k; ++j) {
        cin >> b[j];
      }
      for (int mask = 0; mask < (1 << k); ++mask) {
        int val = 0;
        for (int j = 0; j < k; ++j) {
          if (mask & (1 << j)) {
            val += b[j];
          } else {
            val -= b[j];
          }
        }
        trees[mask].update(i, {val, val});
      }
    } else {
      int l, r;
      cin >> l >> r;
      --l, --r;
      int ans = -1e9;
      for (int mask = 0; mask < (1 << k); ++mask) {
        auto a = trees[mask].query(l, r);
        ans = max(ans, a.second - a.first);
      }
      cout << ans << '\n';
    }
  }
  debug(trees);
  return 0;
}
