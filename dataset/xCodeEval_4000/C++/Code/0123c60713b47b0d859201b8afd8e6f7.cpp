#line 1 "main.cpp"



#include <iostream>
#include <algorithm>
#include <utility>
#include <numeric>
#include <vector>
#include <array>
#include <cassert>

#line 2 "/Users/kodamankod/Desktop/Programming/Library/other/chmin_chmax.cpp"

template <class T, class U>
constexpr bool chmin(T &lhs, const U &rhs) {
  if (lhs > rhs) { 
    lhs = rhs; 
    return true; 
  }
  return false;
}

template <class T, class U>
constexpr bool chmax(T &lhs, const U &rhs) {
  if (lhs < rhs) { 
    lhs = rhs; 
    return true; 
  }
  return false;
}


#line 2 "/Users/kodamankod/Desktop/Programming/Library/other/range.cpp"

#line 4 "/Users/kodamankod/Desktop/Programming/Library/other/range.cpp"

class range {
public:
  class iterator {
  private:
    int64_t M_position;

  public:
    constexpr iterator(int64_t position) noexcept: M_position(position) { }
    constexpr void operator ++ () noexcept { ++M_position; }
    constexpr bool operator != (iterator other) const noexcept { return M_position != other.M_position; }
    constexpr int64_t operator * () const noexcept { return M_position; }

  };

  class reverse_iterator {
  private:
    int64_t M_position;
  
  public:
    constexpr reverse_iterator(int64_t position) noexcept: M_position(position) { }
    constexpr void operator ++ () noexcept { --M_position; }
    constexpr bool operator != (reverse_iterator other) const noexcept { return M_position != other.M_position; }
    constexpr int64_t operator * () const noexcept { return M_position; }

  };
  
private:
  const iterator M_first, M_last;

public:
  constexpr range(int64_t first, int64_t last) noexcept: M_first(first), M_last(std::max(first, last)) { }
  constexpr iterator begin() const noexcept { return M_first; }
  constexpr iterator end() const noexcept { return M_last; }
  constexpr reverse_iterator rbegin() const noexcept { return reverse_iterator(*M_last - 1); } 
  constexpr reverse_iterator rend() const noexcept { return reverse_iterator(*M_first - 1); } 

};


#line 2 "/Users/kodamankod/Desktop/Programming/Library/other/rev.cpp"

#include <type_traits>
#include <iterator>
#line 6 "/Users/kodamankod/Desktop/Programming/Library/other/rev.cpp"

template <class T>
class rev_impl {
public:
  using iterator = typename std::decay<T>::type::reverse_iterator;

private:
  const iterator M_begin;
  const iterator M_end;

public:
  constexpr rev_impl(T &&cont) noexcept: M_begin(std::rbegin(cont)), M_end(std::rend(cont)) { }
  constexpr iterator begin() const noexcept { return M_begin; }
  constexpr iterator end() const noexcept { return M_end; }

};

template <class T>
constexpr decltype(auto) rev(T &&cont) {
  return rev_impl<T>(std::forward<T>(cont));
}


#line 2 "/Users/kodamankod/Desktop/Programming/Library/container/lazy_propagation_segment_tree.cpp"

#line 2 "/Users/kodamankod/Desktop/Programming/Library/other/bit_operation.cpp"

#include <cstddef>
#include <cstdint>

constexpr size_t bit_ppc(const uint64_t x) {
  return __builtin_popcountll(x);
}

constexpr size_t bit_ctzr(const uint64_t x) {
  return x == 0 ? 64 : __builtin_ctzll(x);
}

constexpr size_t bit_ctzl(const uint64_t x) {
  return x == 0 ? 64 : __builtin_clzll(x);
}

constexpr size_t bit_width(const uint64_t x) { 
  return 64 - bit_ctzl(x);
}

constexpr uint64_t bit_msb(const uint64_t x) {
  return x == 0 ? 0 : uint64_t(1) << (bit_width(x) - 1);
}

constexpr uint64_t bit_lsb(const uint64_t x) {
  return x & (-x);
}

constexpr uint64_t bit_cover(const uint64_t x) {
  return x == 0 ? 0 : bit_msb(2 * x - 1);
}

constexpr uint64_t bit_rev(uint64_t x) {
  x = ((x >> 1) & 0x5555555555555555) | ((x & 0x5555555555555555) << 1);
  x = ((x >> 2) & 0x3333333333333333) | ((x & 0x3333333333333333) << 2);
  x = ((x >> 4) & 0x0F0F0F0F0F0F0F0F) | ((x & 0x0F0F0F0F0F0F0F0F) << 4);
  x = ((x >> 8) & 0x00FF00FF00FF00FF) | ((x & 0x00FF00FF00FF00FF) << 8);
  x = ((x >> 16) & 0x0000FFFF0000FFFF) | ((x & 0x0000FFFF0000FFFF) << 16);
  x = (x >> 32) | (x << 32);
  return x;
}


#line 2 "/Users/kodamankod/Desktop/Programming/Library/other/monoid.cpp"

#include <type_traits>
#line 5 "/Users/kodamankod/Desktop/Programming/Library/other/monoid.cpp"
#include <stdexcept>

template <class T, class = void>
class has_identity: public std::false_type { };

template <class T>
class has_identity<T, typename std::conditional<false, decltype(T::identity()), void>::type>: public std::true_type { };

template <class T>
constexpr typename std::enable_if<has_identity<T>::value, typename T::type>::type empty_exception() {
  return T::identity();
}
template <class T>
[[noreturn]] constexpr typename std::enable_if<!has_identity<T>::value, typename T::type>::type empty_exception() {
  throw std::runtime_error("type T has no identity");
}

template <class T, bool HasIdentity>
class fixed_monoid_impl: public T {
public:
  static constexpr typename T::type convert(const typename T::type &value) { return value; }
  static constexpr typename T::type revert(const typename T::type &value) { return value; }

};

template <class T>
class fixed_monoid_impl<T, false>: private T {
public:
  class type {
  public:
    typename T::type value;
    bool state;
  
    explicit constexpr type(): value(typename T::type { }), state(false) { }
    explicit constexpr type(const typename T::type &value): value(value), state(true) { }

  };

  static constexpr type convert(const typename T::type &value) { return type(value); }
  static constexpr typename T::type revert(const type &value) { 
    if (!value.state) throw std::runtime_error("attempted to revert identity to non-monoid"); 
    return value.value; 
  }

  static constexpr type identity() { return type(); }
  static constexpr type operation(const type &v1, const type &v2) {
    if (!v1.state) return v2;
    if (!v2.state) return v1;
    return type(T::operation(v1.value, v2.value));
  }

};

template <class T>
using fixed_monoid = fixed_monoid_impl<T, has_identity<T>::value>;

template <class T, bool HasIdentity>
class fixed_combined_monoid_impl {
public:
  using value_structure    = typename T::value_structure;
  using operator_structure = fixed_monoid<typename T::operator_structure>;

  template <class... Args>
  static constexpr typename value_structure::type operation(
    const typename value_structure::type    &val,
    const typename operator_structure::type &op,
    Args&&... args) {
    return T::operation(val, op, std::forward<Args>(args)...);
  }

};

template <class T>
class fixed_combined_monoid_impl<T, false> {
public:
  using value_structure    = typename T::value_structure;
  using operator_structure = fixed_monoid<typename T::operator_structure>;

  template <class... Args>
  static constexpr typename value_structure::type operation(
    const typename value_structure::type    &val,
    const typename operator_structure::type &op,
    Args&&... args) {
    if (!op.state) return val;
    return T::operation(val, op.value, std::forward<Args>(args)...);
  }

};

template <class T>
using fixed_combined_monoid = fixed_combined_monoid_impl<T, has_identity<typename T::operator_structure>::value>;


#line 5 "/Users/kodamankod/Desktop/Programming/Library/container/lazy_propagation_segment_tree.cpp"

#line 10 "/Users/kodamankod/Desktop/Programming/Library/container/lazy_propagation_segment_tree.cpp"

template <class CombinedMonoid>
class lazy_propagation_segment_tree {
public:
  using structure       = CombinedMonoid;
  using value_monoid    = typename CombinedMonoid::value_structure;
  using operator_monoid = typename CombinedMonoid::operator_structure;
  using value_type      = typename CombinedMonoid::value_structure::type;
  using operator_type   = typename CombinedMonoid::operator_structure::type;
  using size_type       = size_t;

private:
  using fixed_structure       = fixed_combined_monoid<structure>;
  using fixed_operator_monoid = typename fixed_structure::operator_structure;
  using fixed_operator_type   = typename fixed_operator_monoid::type;

  class node_type {
  public:
    value_type    value;
    fixed_operator_type lazy;
    node_type(
      const value_type    &value = value_monoid::identity(),
      const fixed_operator_type &lazy  = fixed_operator_monoid::identity()
    ): value(value), lazy(lazy) { }
  };

  static void S_apply(node_type &node, const fixed_operator_type &op, const size_type length) {
    node.value = fixed_structure::operation(node.value, op, length);
    node.lazy  = fixed_operator_monoid::operation(node.lazy, op);
  }

  void M_propagate(const size_type index, const size_type length) {
    S_apply(M_tree[index << 1 | 0], M_tree[index].lazy, length);
    S_apply(M_tree[index << 1 | 1], M_tree[index].lazy, length);
    M_tree[index].lazy = fixed_operator_monoid::identity();
  }
  void M_fix_change(const size_type index) {
    M_tree[index].value = 
      value_monoid::operation(M_tree[index << 1 | 0].value, M_tree[index << 1 | 1].value);
  }

  void M_pushdown(const size_type index) {
    const size_type lsb = bit_ctzr(index);
    for (size_type story = bit_width(index); story != lsb; --story) {
      M_propagate(index >> story, 1 << (story - 1));
    }
  }
  void M_pullup(size_type index) {
    index >>= bit_ctzr(index);
    while (index != 1) {
      index >>= 1;
      M_fix_change(index);
    }
  }

  std::vector<node_type> M_tree;

public:
  lazy_propagation_segment_tree() = default;
  explicit lazy_propagation_segment_tree(const size_type size) { initialize(size); }
  template <class InputIterator>
  explicit lazy_propagation_segment_tree(InputIterator first, InputIterator last) { construct(first, last); }

  void initialize(const size_type size) {
    clear();
    M_tree.assign(size << 1, node_type());
  }

  template <class InputIterator>
  void construct(InputIterator first, InputIterator last) {
    clear();
    const size_type size = std::distance(first, last);
    M_tree.reserve(size << 1);
    M_tree.assign(size, node_type());
    for (; first != last; ++first) {
      M_tree.emplace_back(*first, fixed_operator_monoid::identity());
    }
    for (size_type index = size - 1; index != 0; --index) {
      M_fix_change(index);
    }
  }

  value_type fold(size_type first, size_type last) {
    first += size();
    last  += size();
    M_pushdown(first);
    M_pushdown(last);
    value_type fold_l = value_monoid::identity();
    value_type fold_r = value_monoid::identity();
    while (first != last) {
      if (first & 1) {
        fold_l = value_monoid::operation(fold_l, M_tree[first].value);
        ++first;
      }
      if (last & 1) {
        --last;
        fold_r = value_monoid::operation(M_tree[last].value, fold_r);
      }
      first >>= 1;
      last  >>= 1;
    }
    return value_monoid::operation(fold_l, fold_r);
  }

  void operate(size_type first, size_type last, const operator_type &op_) {
    const auto op = fixed_operator_monoid::convert(op_);
    first += size();
    last  += size();
    M_pushdown(first);
    M_pushdown(last);
    const size_type first_c = first;
    const size_type last_c  = last;
    for (size_type story = 0; first != last; ++story) {
      if (first & 1) {
        S_apply(M_tree[first], op, 1 << story);
        ++first;
      }
      if (last & 1) {
        --last;
        S_apply(M_tree[last], op, 1 << story);
      }
      first >>= 1;
      last  >>= 1;
    }
    M_pullup(first_c);
    M_pullup(last_c);
  }

  void assign(size_type index, const value_type &val) {
    index += size();
    for (size_type story = bit_width(index) - 1; story != 0; --story) {
      M_propagate(index >> story, 1 << (story - 1));
    }
    M_tree[index].value = val;
    M_tree[index].lazy  = fixed_operator_monoid::identity();
    while (index != 1) {
      index >>= 1;
      M_fix_change(index);
    }
  }

  void clear() {
    M_tree.clear();
    M_tree.shrink_to_fit();
  }

  size_type size() const { 
    return M_tree.size() >> 1;
  }

};


#line 18 "main.cpp"

using i32 = int32_t;
using i64 = int64_t;
using u32 = uint32_t;
using u64 = uint64_t;

constexpr i32 inf32 = (i32(1) << 30) - 1;
constexpr i64 inf64 = (i64(1) << 62) - 1;

struct lst_monoid {
  struct value_structure {
    using type = std::pair<i64, i32>;
    static type identity() { return std::make_pair(std::numeric_limits<i64>::min(), -1); }
    static type operation(const type& v1, const type& v2) { 
      return v1 > v2 ? v1 : v2;
    }
  };
  struct operator_structure {
    using type = i64;
    static type identity() { return 0; }
    static type operation(const type& v1, const type& v2) { 
      return v1 + v2;
    }
  };
  static typename value_structure::type operation(
    const typename value_structure::type    &val,
    const typename operator_structure::type &op,
    const size_t = 1) {
    return val.second == -1 ? val : std::make_pair(val.first + op, val.second);
  }
};

int main() {
  i32 N, K, B, C;
  std::cin >> N >> K >> B >> C;
  std::vector<i32> A(N);
  for (auto &x: A) {
    std::cin >> x;
  }
  std::sort(A.begin(), A.end());
  if (B >= 5 * C) {
    std::vector<i64> sum(N + 1);
    for (auto i: range(0, N)) {
      sum[i + 1] = sum[i] + A[i];
    }
    i64 ans = inf64;
    for (auto i: range(K, N + 1)) {
      chmin(ans, ((i64) K * A[i - 1] - (sum[i] - sum[i - K])) * C);
    }
    std::cout << ans << '\n';
  }
  else {
    auto solve = [&](const std::vector<i32> &val, const std::vector<i32> &cost) {
      i64 cur = 0, res = inf64;
      lazy_propagation_segment_tree<lst_monoid> seg(N);
      for (auto i: range(0, K - 1)) {
        i64 tmp = (i64) (val[K - 2] - val[i]) / 5 * B + cost[i];
        assert(tmp >= 0);
        cur += tmp;
        seg.assign(i, { tmp, i });
      }
      for (auto i: range(K - 1, N)) {
        i64 tmp = (i64) (val[i] - val[i - 1]) / 5 * B;
        assert(tmp >= 0);
        seg.operate(0, i, tmp);
        cur += tmp * (K - 1) + cost[i];
        seg.assign(i, { cost[i], i });
        chmin(res, cur);
        auto [v, j] = seg.fold(0, i + 1);
        cur -= v;
        seg.assign(j, lst_monoid::value_structure::identity());
      }
      return res;
    };
    i64 ans = inf64;
    for (auto rem: range(0, 5)) {
      std::vector<i32> val(N), cost(N);
      for (auto i: range(0, N)) {
        i32 tmp = (rem - (A[i] % 5 + 5) + 10) % 5;
        if (tmp < 0) {
          tmp += 5;
        }
        val[i] = A[i] + tmp;
        cost[i] = tmp * C;
      }
      chmin(ans, solve(val, cost));
    }
    std::cout << ans << '\n';
  }
  return 0;
}
