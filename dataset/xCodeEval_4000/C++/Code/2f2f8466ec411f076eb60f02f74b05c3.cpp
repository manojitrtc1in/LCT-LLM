


#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <cctype>
#include <chrono>
#include <cmath>
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
#include <stack>
#include <string>
#include <string_view>
#include <tuple>
#include <type_traits>
#include <utility>
#include <vector>

using namespace std;

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
constexpr std::enable_if_t<std::is_unsigned_v<T>, int> popcount(
    T x) noexcept {  

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
constexpr std::enable_if_t<std::is_unsigned_v<T>, T> bit_width(
    T x) noexcept {  

  return (T)(std::numeric_limits<T>::digits - countl_zero(x));
}

template <typename T>
constexpr std::enable_if_t<std::is_unsigned_v<T>, T> bit_ceil(
    T x) noexcept {  

  return (T)(x <= 1 ? 1 : (T)1 << bit_width((T)(x - 1)));
}

template <typename T>
constexpr std::enable_if_t<std::is_unsigned_v<T>, T> bit_floor(
    T x) noexcept {  

  return (T)(x == 0 ? 0 : (T)1 << (bit_width(x) - 1));
}

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


#ifdef TYLER
#define debug(...)                            \
  do {                                        \
    std::cerr << "  " << __LINE__ << " | ";   \
    detail::print(#__VA_ARGS__, __VA_ARGS__); \
  } while (false)
#else
#define debug(...) ((void)0)
#endif

template <typename T>
class fenwick_tree {
 public:
  fenwick_tree(int n) : h1b_(highest_one_bit(n)), data_(n) {}

  fenwick_tree(const std::vector<T>& data)
      : h1b_(highest_one_bit((int)data.size())), data_(data) {
    for (int i = 0; i < (int)data_.size(); ++i) {
      if (int j = i | (i + 1); j < (int)data_.size()) {
        data_[j] += data_[i];
      }
    }
  }

  int size() const { return (int)data_.size(); }

  void add(int pos, T delta) {
    for (; pos < (int)data_.size(); pos |= pos + 1) {
      data_[pos] += delta;
    }
  }

  T get(int pos) const { return get(pos, pos); }

  

  T get(int first, int last) const {
    T sum{};
    for (--first; last > first; last = (last & (last + 1)) - 1) {
      sum += data_[last];
    }
    for (; first > last; first = (first & (first + 1)) - 1) {
      sum -= data_[first];
    }
    return sum;
  }

  int lower_bound(T val) const {
    int low = -1;
    for (int mask = h1b_; mask != 0; mask >>= 1) {
      if (int mid = low + mask; mid < (int)data_.size() && data_[mid] < val) {
        val -= data_[low = mid];
      }
    }
    return low + 1;
  }

  int upper_bound(T val) const {
    int low = -1;
    for (int mask = h1b_; mask != 0; mask >>= 1) {
      if (int mid = low + mask; mid < (int)data_.size() && data_[mid] <= val) {
        val -= data_[low = mid];
      }
    }
    return low + 1;
  }

  friend std::ostream& operator<<(std::ostream& os, const fenwick_tree& tree) {
    os << '{';
    for (int i = 0; i < tree.size(); ++i) {
      if (i != 0) {
        os << ", ";
      }
      os << tree.get(i);
    }
    return os << '}';
  }

 private:
  const int h1b_;
  std::vector<T> data_;

  static constexpr int highest_one_bit(int x) {
    x |= x >> 1;
    x |= x >> 2;
    x |= x >> 4;
    x |= x >> 8;
    x |= x >> 16;
    return x - (x >> 1);
  }
};



template <typename T, typename Join>
class seg_tree {
  static_assert(
      std::is_same_v<std::invoke_result_t<Join, const T&, const T&>, T>);

 public:
  seg_tree(int n, const T& val = T(), const Join& join = Join())
      : join_(join),
        n_(n),
        n_ceil_(bit_ceil((unsigned)n_)),
        data_(2 * n_ceil_, val) {
    for (int first = n_ceil_, last = n_ceil_ + n_ - 1; first != 1;
         first >>= 1, last >>= 1) {
      data_[last >> 1] = data_[last];
      for (int i = first; i < last; i += 2) {
        data_[i >> 1] = join_(data_[i], data_[i + 1]);
      }
    }
  }

  seg_tree(const std::vector<T>& data, const Join& join = Join())
      : join_(join),
        n_((int)data.size()),
        n_ceil_(bit_ceil((unsigned)n_)),
        data_(2 * n_ceil_) {
    std::copy(data.begin(), data.end(), data_.begin() + n_ceil_);
    for (int first = n_ceil_, last = n_ceil_ + n_ - 1; first != 1;
         first >>= 1, last >>= 1) {
      data_[last >> 1] = data_[last];
      for (int i = first; i < last; i += 2) {
        data_[i >> 1] = join_(data_[i], data_[i + 1]);
      }
    }
  }

  int size() const { return n_; }

  template <typename NodeUpdate>
  void update(int pos, const T& val, NodeUpdate node_update) {
    static_assert(
        std::is_void_v<std::invoke_result_t<NodeUpdate, T&, const T&>>);
    node_update(data_[pos += n_ceil_], val);
    for (int last = n_ceil_ + n_ - 1; last != 1; pos >>= 1, last >>= 1) {
      if ((pos | 1) <= last) {
        data_[pos >> 1] = join_(data_[pos & ~1], data_[pos | 1]);
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
        left = left ? join_(*left, data_[first++]) : data_[first++];
      }
      if ((last & 1) == 0) {
        right = right ? join_(data_[last--], *right) : data_[last--];
      }
    }
    return left ? (right ? join_(*left, *right) : *left) : *right;
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
      if (!contains(data_[pos <<= 1], val)) {
        ++pos;
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
  Join join_;
  int n_, n_ceil_;
  std::vector<T> data_;
};

struct sum_fn {
  constexpr int operator()(int a, int b) const { return a + b; }
};

constexpr bool contains(int left, int& val) {
  if (left >= val) {
    return true;
  } else {
    val -= left;
    return false;
  }
}

constexpr void update(int& a, int b) { a += b; }













int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.precision(12);
  std::cerr.precision(12);
  std::mt19937 rng(
      (std::uint_fast32_t)(std::uintptr_t)std::make_unique<bool>().get());
  int n, m, q;
  cin >> n >> m >> q;
  vector<long long> cnt(m);
  for (int i = 0; i < n; ++i) {
    int a;
    cin >> a;
    --a;
    ++cnt[a];
  }
  vector<vector<int>> mp(n + 1);
  for (int i = 0; i < m; ++i) {
    mp[cnt[i]].push_back(i);
  }
  vector<pair<long long, int>> ks(q);
  for (int i = 0; i < q; ++i) {
    cin >> ks[i].first;
    ks[i].second = i;
  }
  sort(ks.begin(), ks.end());
  vector<long long> ans(q);
  seg_tree<int, sum_fn> tree(m, 0);
  long long total = n, sz = 0;
  int cur = 0;
  for (int i = 0; i <= n; ++i) {
    for (int x : mp[i]) {
      

      tree.update(x, 1, update);
      ++sz;
    }
    while (cur < q && ks[cur].first <= total + sz) {
      ans[ks[cur].second] = tree.find(ks[cur].first - total, contains);
      ++cur;
    }
    total += sz;
  }
  while (cur < q) {
    ans[ks[cur].second] =
        tree.find((ks[cur].first - total - 1) % m + 1, contains);
    ++cur;
  }
  for (long long a : ans) {
    cout << a + 1 << '\n';
  }
  return 0;
}

int main_ac() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.precision(12);
  std::cerr.precision(12);
  std::mt19937 rng(
      (std::uint_fast32_t)(std::uintptr_t)std::make_unique<bool>().get());
  int n, m, q;
  cin >> n >> m >> q;
  vector<long long> cnt(m);
  for (int i = 0; i < n; ++i) {
    int a;
    cin >> a;
    --a;
    ++cnt[a];
  }
  vector<pair<long long, int>> ps(m);
  for (int i = 0; i < m; ++i) {
    ps[i] = {cnt[i], i};
  }
  sort(ps.begin(), ps.end());
  vector<pair<long long, int>> qs(m);
  qs[0] = {0, ps[0].second};
  for (int i = 1; i < m; ++i) {
    qs[i].first = qs[i - 1].first + (ps[i].first - ps[i - 1].first) * i;
    qs[i].second = ps[i].second;
  }
  vector<pair<long long, int>> ks(q);
  for (int i = 0; i < q; ++i) {
    cin >> ks[i].first;
    ks[i].second = i;
  }
  sort(ks.begin(), ks.end());
  vector<long long> ans(q);
  fenwick_tree<long long> tree(m);
  int cur = 0;
  for (auto [k, i] : ks) {
    while (cur < m && k > n + qs[cur].first) {
      tree.add(qs[cur].second, 1);
      ++cur;
    }
    ans[i] = tree.lower_bound((k - qs[cur - 1].first - n - 1) % cur + 1) + 1;
  }
  for (long long a : ans) {
    cout << a << '\n';
  }
  return 0;
}
