


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

#if defined(__GNUC__) && !defined(__clang__)

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

template <typename Key, typename Compare = std::less<Key>,
          typename Allocator = std::allocator<Key>>
using ordered_set =
    __gnu_pbds::tree<Key, __gnu_pbds::null_type, Compare,
                     __gnu_pbds::rb_tree_tag,
                     __gnu_pbds::tree_order_statistics_node_update, Allocator>;

template <typename Key, typename T, typename Compare = std::less<Key>,
          typename Allocator = std::allocator<std::pair<const Key, T>>>
using ordered_map =
    __gnu_pbds::tree<Key, T, Compare, __gnu_pbds::rb_tree_tag,
                     __gnu_pbds::tree_order_statistics_node_update, Allocator>;

#endif

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


#ifdef TYLER
#define debug(...) \
  detail::print(std::cerr, __LINE__, #__VA_ARGS__ __VA_OPT__(, ) __VA_ARGS__)
#else
#define debug(...) ((void)0)
#endif

template <typename T>
class fraction {
  static_assert(std::is_integral_v<T>);

 public:
  constexpr fraction(T num = 0) : num_(num), den_(1) {}

  constexpr fraction(T num, T den) {
    assert(den != 0);
    T g = std::gcd(num, den);
    if (den < 0) {
      g = -g;
    }
    num_ = num / g;
    den_ = den / g;
  }

  fraction(const std::vector<T>& cont) : num_(cont.back()), den_(1) {
    for (int i = (int)cont.size() - 2; i >= 0; --i) {
      std::swap(num_, den_);
      num_ += cont[i] * den_;
    }
  }

  constexpr T num() const { return num_; }

  constexpr T den() const { return den_; }

  template <typename U>
  constexpr explicit operator U() const {
    return (U)num_ / (U)den_;
  }

  constexpr fraction& operator+=(const fraction& other) {
    return *this = *this + other;
  }

  constexpr fraction& operator-=(const fraction& other) {
    return *this = *this - other;
  }

  constexpr fraction& operator*=(const fraction& other) {
    T g1 = std::gcd(num_, other.den_), g2 = std::gcd(den_, other.num_);
    num_ = (num_ / g1) * (other.num_ / g2);
    den_ = (den_ / g2) * (other.den_ / g1);
    return *this;
  }

  constexpr fraction& operator/=(const fraction& other) {
    assert(other.num_ != 0);
    T g1 = std::gcd(num_, other.num_), g2 = std::gcd(den_, other.den_);
    if (other.num_ < 0) {
      g1 = -g1;
    }
    num_ = (num_ / g1) * (other.den_ / g2);
    den_ = (den_ / g2) * (other.num_ / g1);
    return *this;
  }

  friend constexpr fraction operator+(fraction f) { return f; }

  friend constexpr fraction operator-(fraction f) {
    f.num_ = -f.num_;
    return f;
  }

  friend constexpr fraction operator+(const fraction& lhs,
                                      const fraction& rhs) {
    T g = std::gcd(lhs.den_, rhs.den_);
    return fraction(rhs.den_ / g * lhs.num_ + lhs.den_ / g * rhs.num_,
                    lhs.den_ / g * rhs.den_);
  }

  friend constexpr fraction operator-(const fraction& lhs,
                                      const fraction& rhs) {
    T g = std::gcd(lhs.den_, rhs.den_);
    return fraction(rhs.den_ / g * lhs.num_ - lhs.den_ / g * rhs.num_,
                    lhs.den_ / g * rhs.den_);
  }

  friend constexpr fraction operator*(fraction lhs, const fraction& rhs) {
    return lhs *= rhs;
  }

  friend constexpr fraction operator/(fraction lhs, const fraction& rhs) {
    return lhs /= rhs;
  }

  friend constexpr bool operator==(const fraction& lhs, const fraction& rhs) {
    return lhs.num_ == rhs.num_ && lhs.den_ == rhs.den_;
  }

  friend constexpr bool operator!=(const fraction& lhs, const fraction& rhs) {
    return !(lhs == rhs);
  }

  friend constexpr bool operator<(const fraction& lhs, const fraction& rhs) {
    return lhs.num_ * rhs.den_ < rhs.num_ * lhs.den_;
  }

  friend constexpr bool operator<=(const fraction& lhs, const fraction& rhs) {
    return lhs.num_ * rhs.den_ <= rhs.num_ * lhs.den_;
  }

  friend constexpr bool operator>(const fraction& lhs, const fraction& rhs) {
    return lhs.num_ * rhs.den_ > rhs.num_ * lhs.den_;
  }

  friend constexpr bool operator>=(const fraction& lhs, const fraction& rhs) {
    return lhs.num_ * rhs.den_ >= rhs.num_ * lhs.den_;
  }

  friend std::ostream& operator<<(std::ostream& os, const fraction& f) {
    return os << f.num_ << '/' << f.den_;
  }

  friend constexpr fraction inv(fraction f) {
    assert(f.num_ != 0);
    if (T t = f.num_; t < 0) {
      f.num_ = -f.den_;
      f.den_ = -t;
    } else {
      f.num_ = f.den_;
      f.den_ = t;
    }
    return f;
  }

  friend std::vector<T> continued(fraction f) {
    T q = f.num_ < 0 ? (f.num_ - f.den_ + 1) / f.den_ : f.num_ / f.den_;
    f.num_ -= q * f.den_;
    std::vector<T> cont = {q};
    while (f.num_ != 0) {
      std::swap(f.num_, f.den_);
      q = f.num_ / f.den_;
      f.num_ -= q * f.den_;
      cont.push_back(q);
    }
    return cont;
  }

 private:
  T num_, den_;
};

template <typename T, int Dim = 2>
struct point;

template <typename T>
struct point<T, 2> {
  T x, y;

  constexpr point(const T& _x = T(), const T& _y = T()) : x(_x), y(_y) {}

  constexpr point& operator+=(const point& other) {
    x += other.x;
    y += other.y;
    return *this;
  }

  constexpr point& operator-=(const point& other) {
    x -= other.x;
    y -= other.y;
    return *this;
  }

  constexpr point& operator*=(const T& val) {
    x *= val;
    y *= val;
    return *this;
  }

  constexpr point& operator/=(const T& val) {
    x /= val;
    y /= val;
    return *this;
  }

  friend constexpr point operator+(const point& p) { return p; }

  friend constexpr point operator-(const point& p) { return point(-p.x, -p.y); }

  friend constexpr point operator+(const point& lhs, const point& rhs) {
    return point(lhs.x + rhs.x, lhs.y + rhs.y);
  }

  friend constexpr point operator-(const point& lhs, const point& rhs) {
    return point(lhs.x - rhs.x, lhs.y - rhs.y);
  }

  friend constexpr point operator*(const point& lhs, const T& val) {
    return point(lhs.x * val, lhs.y * val);
  }

  friend constexpr point operator*(const T& val, const point& rhs) {
    return point(val * rhs.x, val * rhs.y);
  }

  friend constexpr point operator/(const point& lhs, const T& val) {
    return point(lhs.x / val, lhs.y / val);
  }

  friend constexpr bool operator==(const point& lhs, const point& rhs) {
    return lhs.x == rhs.x && lhs.y == rhs.y;
  }

  friend constexpr bool operator!=(const point& lhs, const point& rhs) {
    return !(lhs == rhs);
  }

  friend constexpr bool operator<(const point& lhs, const point& rhs) {
    return lhs.x != rhs.x ? lhs.x < rhs.x : lhs.y < rhs.y;
  }

  friend std::ostream& operator<<(std::ostream& os, const point& p) {
    return os << '(' << p.x << ',' << p.y << ')';
  }

  friend constexpr T norm(const point& p) { return p.x * p.x + p.y * p.y; }

  friend constexpr T dot(const point& lhs, const point& rhs) {
    return lhs.x * rhs.x + lhs.y * rhs.y;
  }

  friend constexpr T cross(const point& lhs, const point& rhs) {
    return lhs.x * rhs.y - lhs.y * rhs.x;
  }
};

template <typename T>
class monotone_hull {
 public:
  monotone_hull() = default;

  monotone_hull(std::vector<point<T, 2>> lines) {
    std::sort(lines.begin(), lines.end());
    for (const point<T, 2>& line : lines) {
      while ((int)lines_.size() >= 2 &&
             cross(lines_.back() - *std::prev(lines_.end(), 2),
                   line - lines_.back()) >= 0) {
        lines_.pop_back();
      }
      lines_.push_back(line);
    }
  }

  void push_back(const point<T, 2>& line) {
    while ((int)lines_.size() >= 2 &&
           cross(lines_.back() - *std::prev(lines_.end(), 2),
                 line - lines_.back()) >= 0) {
      lines_.pop_back();
    }
    lines_.push_back(line);
  }

  void emplace_back(const T& slope, const T& intercept) {
    push_back(point<T, 2>(slope, intercept));
  }

  T linear_max(const T& x) {
    point<T, 2> p(x, 1);
    while ((int)lines_.size() >= 2 && dot(lines_[0], p) < dot(lines_[1], p)) {
      lines_.pop_front();
    }
    return dot(lines_[0], p);
  }

  friend std::ostream& operator<<(std::ostream& os, const monotone_hull& hull) {
    return os << hull.lines();
  }

 private:
  std::deque<point<T, 2>> lines_;
};

template <typename T>
class dynamic_hull {
 public:
  struct line_adaptor {
   public:
    point<T, 2> line;

    friend bool operator<(const line_adaptor& lhs, const line_adaptor& rhs) {
      return lhs.line < rhs.line;
    }

    friend bool operator<(const line_adaptor& lhs, const T& x) {
      return lhs.next != nullptr && dot(lhs.line, point<T, 2>(x, 1)) <
                                        dot(lhs.next->line, point<T, 2>(x, 1));
    }

    friend std::ostream& operator<<(std::ostream& os, const line_adaptor& a) {
      return os << a.line;
    }

   private:
    friend dynamic_hull;

    mutable const line_adaptor* next;

    line_adaptor(const point<T, 2>& _line) : line(_line), next(nullptr) {}
  };

  using iterator = typename std::set<line_adaptor, std::less<void>>::iterator;
  using const_iterator =
      typename std::set<line_adaptor, std::less<void>>::const_iterator;

  dynamic_hull() = default;

  dynamic_hull(const dynamic_hull& other) : lines_(other.lines_) {
    for (auto it = lines_.begin(); std::next(it) != lines_.end(); ++it) {
      it->next = &*std::next(it);
    }
  }

  dynamic_hull(dynamic_hull&&) = default;

  dynamic_hull& operator=(const dynamic_hull& other) {
    lines_ = other.lines_;
    for (auto it = lines_.begin(); std::next(it) != lines_.end(); ++it) {
      it->next = &*std::next(it);
    }
    return *this;
  }

  dynamic_hull& operator=(dynamic_hull&&) = default;

  int size() const { return (int)lines_.size(); }

  iterator begin() { return lines_.begin(); }

  const_iterator begin() const { return lines_.begin(); }

  iterator end() { return lines_.end(); }

  const_iterator end() const { return lines_.end(); }

  void insert(const point<T, 2>& line) {
    auto [it, inserted] = lines_.insert(line);
    if (!inserted) {
      return;
    }
    if (it != lines_.begin() && std::next(it) != lines_.end() &&
        cross(it->line - std::prev(it)->line, std::next(it)->line - it->line) >=
            0) {
      lines_.erase(it);
      return;
    }
    if (it != lines_.begin()) {
      auto left = std::prev(it);
      while (left != lines_.begin() && cross(left->line - std::prev(left)->line,
                                             it->line - left->line) >= 0) {
        left = std::prev(lines_.erase(left));
      }
      left->next = &*it;
    }
    if (auto right = std::next(it); right != lines_.end()) {
      while (std::next(right) != lines_.end() &&
             cross(right->line - it->line,
                   std::next(right)->line - right->line) >= 0) {
        right = lines_.erase(right);
      }
      it->next = &*right;
    }
  }

  void emplace(const T& slope, const T& intercept) {
    insert(point<T, 2>(slope, intercept));
  }

  T linear_max(const T& x) const {
    return dot(lines_.lower_bound(x)->line, point<T, 2>(x, 1));
  }

 private:
  std::set<line_adaptor, std::less<void>> lines_;
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
  vector<array<int, 3>> segs(n);
  for (int i = 0; i < n; ++i) {
    cin >> segs[i][0] >> segs[i][1] >> segs[i][2];
  }
  vector<pair<fraction<long long>, int>> events;
  for (int i = 0; i < n; ++i) {
    const auto& [xli, xri, yi] = segs[i];
    for (int j = i + 1; j < n; ++j) {
      const auto& [xlj, xrj, yj] = segs[j];
      if (yi == yj) {
        continue;
      }
      

      fraction<long long> low(xli - xrj, yj - yi), high(xri - xlj, yj - yi);
      if (low > high) {
        swap(low, high);
      }
      events.emplace_back(low, 1);
      events.emplace_back(high, -1);
    }
  }
  sort(events.begin(), events.end());
  vector<double> cands;
  int cnt = 0;
  for (const auto& [k, v] : events) {
    if (cnt == 0 || cnt + v == 0) {
      cands.push_back((double)k);
    }
    cnt += v;
  }
  if (cands.empty()) {
    cands.push_back(0);
  }
  

  dynamic_hull<double> left_hull, right_hull;
  for (const auto& [xl, xr, y] : segs) {
    left_hull.emplace(-y, -xl);
    right_hull.emplace(y, xr);
  }
  

  double ans = 1e18;
  for (double k : cands) {
    double low = -left_hull.linear_max(k);
    double high = right_hull.linear_max(k);
    ans = min(ans, high - low);
  }
  cout << ans << '\n';
  return 0;
}
