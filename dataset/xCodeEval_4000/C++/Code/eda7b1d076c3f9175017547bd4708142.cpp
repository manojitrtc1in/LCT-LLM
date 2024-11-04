


#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <cctype>
#include <chrono>
#include <cmath>
#include <complex>
#include <cstdint>
#include <cstdlib>
#include <deque>
#include <functional>
#include <initializer_list>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <limits>
#include <map>
#include <memory>
#include <numeric>
#include <optional>
#include <queue>
#include <random>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <string_view>
#include <tuple>
#include <type_traits>
#include <utility>
#include <vector>

using namespace std;

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
constexpr std::enable_if_t<std::is_unsigned_v<T>, bool> has_single_bit(
    T x) noexcept {
  return x != 0 && (x & (x - 1)) == 0;
}

template <typename T>
constexpr std::enable_if_t<std::is_unsigned_v<T>, int> countl_zero(
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
constexpr std::enable_if_t<std::is_unsigned_v<T>, int> countr_zero(
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
  return (T)(std::numeric_limits<T>::digits - countl_zero(x));
}

template <typename T>
constexpr std::enable_if_t<std::is_unsigned_v<T>, T> bit_ceil(T x) noexcept {
  return (T)(x <= 1 ? 1 : (T)1 << bit_width((T)(x - 1)));
}

template <typename T>
constexpr std::enable_if_t<std::is_unsigned_v<T>, T> bit_floor(T x) noexcept {
  return (T)(x == 0 ? 0 : (T)1 << (bit_width(x) - 1));
}

template <typename Fun>
class y_combinator_result {
 public:
  template <typename T>
  explicit y_combinator_result(T&& fun) : fun_(std::forward<T>(fun)) {}

  template <typename... Args>
  decltype(auto) operator()(Args&&... args) {
    return fun_(std::ref(*this), std::forward<Args>(args)...);
  }

 private:
  Fun fun_;
};

template <typename Fun>
decltype(auto) y_combinator(Fun&& fun) {
  return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun));
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
    int first = 0, paren = 0;
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
            key_list.push_back(keys.substr(first, i - first));
            first = i;
          }
          break;
      }
    }
    key_list.push_back(keys.substr(first));
    assert(key_list.size() == sizeof...(Ts));
    os << "  " << line << " | ";
    int i = 0;
    ((os << key_list[i++] << " = " << vals), ...);
    os << std::endl;
  }
}

}  


#if defined(TYLER) && defined(__clang__)
#define debug(...) \
  detail::print(std::cerr, __LINE__, #__VA_ARGS__, ##__VA_ARGS__)
#elif defined(TYLER) && defined(__GNUC__)
#define debug(...) \
  detail::print(std::cerr, __LINE__, #__VA_ARGS__ __VA_OPT__(, ) __VA_ARGS__)
#else
#define debug(...) ((void)0)
#endif

template <typename T>
class bi_tree {
 public:
  bi_tree(int n, const T& val = T()) : data_(n, val) {
    for (int i = 0; i < (int)data_.size(); ++i) {
      if (int j = i | (i + 1); j < (int)data_.size()) {
        data_[j] += data_[i];
      }
    }
  }

  bi_tree(const std::vector<T>& data) : data_(data) {
    for (int i = 0; i < (int)data_.size(); ++i) {
      if (int j = i | (i + 1); j < (int)data_.size()) {
        data_[j] += data_[i];
      }
    }
  }

  int size() const { return (int)data_.size(); }

  void add(int pos, const T& delta) {
    for (; pos < (int)data_.size(); pos |= pos + 1) {
      data_[pos] += delta;
    }
  }

  T get(int pos) const { return get(pos, pos); }

  

  T get(int first, int last) const {
    assert(first <= last);
    --first;
    T sum = T();
    for (; last > first; last = (last & (last + 1)) - 1) {
      sum += data_[last];
    }
    for (; first > last; first = (first & (first + 1)) - 1) {
      sum -= data_[first];
    }
    return sum;
  }

  

  int lower_bound(T val) const {
    int low = -1;
    for (int bit = bit_floor((unsigned)data_.size()); bit != 0; bit >>= 1) {
      if (int mid = low + bit; mid < (int)data_.size() && data_[mid] < val) {
        val -= data_[low = mid];
      }
    }
    return low + 1;
  }

  

  int upper_bound(T val) const {
    int low = -1;
    for (int bit = bit_floor((unsigned)data_.size()); bit != 0; bit >>= 1) {
      if (int mid = low + bit; mid < (int)data_.size() && data_[mid] <= val) {
        val -= data_[low = mid];
      }
    }
    return low + 1;
  }

  friend std::ostream& operator<<(std::ostream& os, const bi_tree& tree) {
    os << '{';
    for (int i = 0; i < tree.size(); ++i) {
      os << (i == 0 ? "" : ", ") << tree.get(i);
    }
    return os << '}';
  }

 private:
  std::vector<T> data_;
};

template <typename T, typename Merge>
class seg_tree {
  static_assert(
      std::is_same_v<std::invoke_result_t<Merge, const T&, const T&>, T>);

 public:
  seg_tree(int n, const T& val = T(), const Merge& merge = Merge())
      : merge_(merge),
        n_(n),
        n_ceil_(bit_ceil((unsigned)n_)),
        data_(n_ceil_ + n_, val) {
    for (int first = n_ceil_, last = n_ceil_ + n_ - 1; first != 1;
         first >>= 1, last >>= 1) {
      data_[last >> 1] = data_[last];
      for (int i = first; i < last; i += 2) {
        data_[i >> 1] = merge_(data_[i], data_[i + 1]);
      }
    }
  }

  seg_tree(const std::vector<T>& data, const Merge& merge = Merge())
      : merge_(merge),
        n_((int)data.size()),
        n_ceil_(bit_ceil((unsigned)n_)),
        data_(n_ceil_ + n_) {
    std::copy(data.begin(), data.end(), data_.begin() + n_ceil_);
    for (int first = n_ceil_, last = n_ceil_ + n_ - 1; first != 1;
         first >>= 1, last >>= 1) {
      data_[last >> 1] = data_[last];
      for (int i = first; i < last; i += 2) {
        data_[i >> 1] = merge_(data_[i], data_[i + 1]);
      }
    }
  }

  int size() const { return n_; }

  template <typename U, typename NodeUpdate>
  void update(int pos, const U& val, NodeUpdate node_update) {
    static_assert(
        std::is_void_v<std::invoke_result_t<NodeUpdate, T&, const U&>>);
    node_update(data_[pos += n_ceil_], val);
    for (int last = n_ceil_ + n_ - 1; last != 1; pos >>= 1, last >>= 1) {
      if ((pos | 1) <= last) {
        data_[pos >> 1] = merge_(data_[pos & ~1], data_[pos | 1]);
      } else {
        data_[pos >> 1] = data_[pos];
      }
    }
  }

  T get(int pos) const { return data_[n_ceil_ + pos]; }

  

  T get(int first, int last) const {
    assert(first <= last);
    std::optional<T> left, right;
    for (first += n_ceil_, last += n_ceil_; first <= last;
         first >>= 1, last >>= 1) {
      if ((first & 1) == 1) {
        left = left ? merge_(*left, data_[first++]) : data_[first++];
      }
      if ((last & 1) == 0) {
        right = right ? merge_(data_[last--], *right) : data_[last--];
      }
    }
    return left ? (right ? merge_(*left, *right) : *left) : *right;
  }

  template <typename Contains>
  int find(T val, Contains contains) const {
    static_assert(
        std::is_same_v<std::invoke_result_t<Contains, const T&, T&>, bool>);
    if (!contains(data_[1], val)) {
      return n_;
    }
    int pos = 1;
    while (pos < n_ceil_) {
      if (contains(data_[2 * pos], val)) {
        pos = 2 * pos;
      } else {
        pos = 2 * pos + 1;
      }
    }
    return pos - n_ceil_;
  }

  template <typename Contains>
  int rfind(T val, Contains contains) const {
    static_assert(
        std::is_same_v<std::invoke_result_t<Contains, const T&, T&>, bool>);
    if (!contains(data_[1], val)) {
      return n_;
    }
    int pos = 1;
    while (pos < n_ceil_) {
      if (2 * pos + 1 < (int)data_.size() &&
          contains(data_[2 * pos + 1], val)) {
        pos = 2 * pos + 1;
      } else {
        pos = 2 * pos;
      }
    }
    return pos - n_ceil_;
  }

  friend std::ostream& operator<<(std::ostream& os, const seg_tree& tree) {
    os << '{';
    for (int i = 0; i < tree.size(); ++i) {
      os << (i == 0 ? "" : ", ") << tree.get(i);
    }
    return os << '}';
  }

 private:
  Merge merge_;
  int n_, n_ceil_;
  std::vector<T> data_;
};

template <typename T, typename Merge>
seg_tree<T, Merge> make_seg_tree(int n, const T& val, const Merge& merge) {
  return seg_tree<T, Merge>(n, val, merge);
}

template <typename T, typename Merge>
seg_tree<T, Merge> make_seg_tree(const std::vector<T>& data,
                                 const Merge& merge) {
  return seg_tree<T, Merge>(data, merge);
}





template <typename T, typename U, typename Merge, typename NodeUpdate,
          typename LazyUpdate>
class lazy_seg_tree {
  static_assert(
      std::is_same_v<std::invoke_result_t<Merge, const T&, const T&>, T>);
  static_assert(
      std::is_void_v<std::invoke_result_t<NodeUpdate, T&, int, const U&>>);
  static_assert(std::is_void_v<std::invoke_result_t<LazyUpdate, U&, const U&>>);

 public:
  lazy_seg_tree(int n, const T& val = T(), const Merge& merge = Merge(),
                const NodeUpdate& node_update = NodeUpdate(),
                const LazyUpdate& lazy_update = LazyUpdate())
      : merge_(merge),
        node_update_(node_update),
        lazy_update_(lazy_update),
        n_(n),
        lazy_(bit_ceil((unsigned)n_), std::nullopt),
        data_(2 * lazy_.size(), val) {
    init(1, 0, n_ - 1);
  }

  lazy_seg_tree(const std::vector<T>& data, const Merge& merge = Merge(),
                const NodeUpdate& node_update = NodeUpdate(),
                const LazyUpdate& lazy_update = LazyUpdate())
      : merge_(merge),
        node_update_(node_update),
        lazy_update_(lazy_update),
        n_((int)data.size()),
        lazy_(bit_ceil((unsigned)n_), std::nullopt),
        data_(2 * lazy_.size()) {
    init(1, 0, n_ - 1, data);
  }

  int size() const { return n_; }

  void update(int pos, const U& val) { update(pos, pos, val); }

  

  void update(int first, int last, const U& val) {
    assert(first <= last);
    update(1, 0, n_ - 1, first, last, val);
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
      if (contains(data_[2 * node], val)) {
        node = 2 * node;
        high = mid;
      } else {
        node = 2 * node + 1;
        low = mid + 1;
      }
    }
    return low;
  }

  template <typename Contains>
  int rfind(T val, Contains contains) {
    static_assert(
        std::is_same_v<std::invoke_result_t<Contains, const T&, T&>, bool>);
    if (!contains(data_[1], val)) {
      return n_;
    }
    int node = 1, low = 0, high = n_ - 1;
    while (low < high) {
      push(node, low, high);
      int mid = (low + high) >> 1;
      if (contains(data_[2 * node + 1], val)) {
        node = 2 * node + 1;
        low = mid + 1;
      } else {
        node = 2 * node;
        high = mid;
      }
    }
    return low;
  }

  friend std::ostream& operator<<(std::ostream& os, lazy_seg_tree tree) {
    os << '{';
    for (int i = 0; i < tree.size(); ++i) {
      os << (i == 0 ? "" : ", ") << tree.get(i);
    }
    return os << '}';
  }

 private:
  Merge merge_;
  NodeUpdate node_update_;
  LazyUpdate lazy_update_;
  int n_;
  std::vector<std::optional<U>> lazy_;
  std::vector<T> data_;

  void init(int node, int low, int high) {
    if (low == high) {
      return;
    }
    int mid = (low + high) >> 1;
    init(2 * node, low, mid);
    init(2 * node + 1, mid + 1, high);
    data_[node] = merge_(data_[2 * node], data_[2 * node + 1]);
  }

  void init(int node, int low, int high, const std::vector<T>& data) {
    if (low == high) {
      data_[node] = data[low];
      return;
    }
    int mid = (low + high) >> 1;
    init(2 * node, low, mid, data);
    init(2 * node + 1, mid + 1, high, data);
    data_[node] = merge_(data_[2 * node], data_[2 * node + 1]);
  }

  void update_node(int node, int low, int high, const U& val) {
    node_update_(data_[node], high - low + 1, val);
    if (low == high) {
      return;
    }
    if (!lazy_[node]) {
      lazy_[node] = val;
      return;
    }
    lazy_update_(*lazy_[node], val);
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

  void update(int node, int low, int high, int first, int last, const U& val) {
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
    data_[node] = merge_(data_[2 * node], data_[2 * node + 1]);
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
    return merge_(get(2 * node, low, mid, first, last),
                  get(2 * node + 1, mid + 1, high, first, last));
  }
};

template <typename T, typename U, typename Merge, typename NodeUpdate,
          typename LazyUpdate>
lazy_seg_tree<T, U, Merge, NodeUpdate, LazyUpdate> make_lazy_seg_tree(
    int n, const T& val, const Merge& merge, const NodeUpdate& node_update,
    const LazyUpdate& lazy_update) {
  return lazy_seg_tree<T, U, Merge, NodeUpdate, LazyUpdate>(
      n, val, merge, node_update, lazy_update);
}

template <typename T, typename U, typename Merge, typename NodeUpdate,
          typename LazyUpdate>
lazy_seg_tree<T, U, Merge, NodeUpdate, LazyUpdate> make_lazy_seg_tree(
    const std::vector<T>& data, const Merge& merge,
    const NodeUpdate& node_update, const LazyUpdate& lazy_update) {
  return lazy_seg_tree<T, U, Merge, NodeUpdate, LazyUpdate>(
      data, merge, node_update, lazy_update);
}

int main_ac() {
  auto start_time = std::chrono::steady_clock::now();
  std::mt19937 thanos(
      (std::uint_fast32_t)start_time.time_since_epoch().count());
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.precision(24);
  int n, q;
  cin >> n >> q;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  vector<vector<pair<int, int>>> queries(n + 1);
  for (int i = 0; i < q; ++i) {
    int x, y;
    cin >> x >> y;
    queries[n - 1 - y].emplace_back(x, i);
  }
  

  auto tree = make_seg_tree<int>(n, 0, plus<int>());
  constexpr auto node_add = [](int& a, int b) { a += b; };
  constexpr auto contains = [](int a, int& b) {
    if (a >= b) {
      return true;
    }
    b -= a;
    return false;
  };
  vector<int> ans(q);
  for (int right = 0; right < n; ++right) {
    if (right + 1 - tree.get(0, right) <= a[right] && a[right] <= right + 1) {
      

      

      

      

      

      

      

      

      

      

      

      

      

      

      int high = min(right, tree.rfind(right + 1 - a[right], contains));
      tree.update(high, 1, node_add);
    }
    for (const auto& [left, i] : queries[right]) {
      ans[i] = tree.get(left, right);
    }
  }
  for (int i = 0; i < q; ++i) {
    cout << ans[i] << '\n';
  }
  return 0;
}

int main() {
  auto start_time = std::chrono::steady_clock::now();
  std::mt19937 thanos(
      (std::uint_fast32_t)start_time.time_since_epoch().count());
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.precision(24);
  int n, q;
  cin >> n >> q;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  vector<vector<pair<int, int>>> queries(n + 1);
  for (int i = 0; i < q; ++i) {
    int x, y;
    cin >> x >> y;
    queries[n - 1 - y].emplace_back(x, i);
  }
  constexpr auto node_add = [](int& a, int k, int b) { a += k * b; };
  constexpr auto lazy_add = [](int& a, int b) { a += b; };
  auto tree =
      make_lazy_seg_tree<int, int>(n, 0, plus<int>(), node_add, lazy_add);
  constexpr auto contains = [](int a, int& b) {
    if (a >= b) {
      return true;
    }
    b -= a;
    return false;
  };
  vector<int> ans(q);
  for (int right = 0; right < n; ++right) {
    if (right + 1 - tree.get(0, right) <= a[right] && a[right] <= right + 1) {
      

      

      

      

      

      

      

      

      

      

      

      

      

      

      int high = min(right, tree.rfind(right + 1 - a[right], contains));
      tree.update(high, 1);
    }
    for (const auto& [left, i] : queries[right]) {
      ans[i] = tree.get(left, right);
    }
  }
  for (int i = 0; i < q; ++i) {
    cout << ans[i] << '\n';
  }
  return 0;
}
