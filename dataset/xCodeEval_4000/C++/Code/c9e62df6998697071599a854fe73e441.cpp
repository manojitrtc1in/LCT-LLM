#include <bits/stdc++.h>
 
#include <iostream>
#include <tuple>
#include <utility>
#include <vector>

namespace cplib {
template <typename T, typename U>
std::istream& operator>>(std::istream& is, std::pair<T, U>& pair) {
  is >> pair.first >> pair.second;
  return is;
}

template <typename T>
T read(std::istream& is) {
  T t; is >> t; return t;
}

template <typename... Args>
std::istream& operator>>(std::istream& is, std::tuple<Args...>& tuple) {
  tuple = {read<Args>(is)...};
  return is;
}

template <typename T>
std::istream& operator>>(std::istream& is, std::vector<T>& arr) {
  for (auto& elem : arr) {
    is >> elem;
  }
  return is;
}

template <typename T, typename U>
std::ostream& operator<<(std::ostream& os, const std::pair<T, U>& pair) {
  os << pair.first << " " << pair.second << "\n";
  return os;
}
 
template <typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& arr) {
  for (auto& elem : arr) {
    os << elem << " ";
  }
  os << "\n";
  return os;
}
}  

 

namespace cplib {

}  



#include <cassert>
#include <vector>

namespace cplib {
template <typename T>
class factorial_computer {
  public:
    explicit factorial_computer(int max)
        : max_(max), fact_(max + 1) { }

    void initialize() {
      fact_[0] = 1;
      for (int num = 1; num <= max_; ++num) {
        fact_[num] = fact_[num - 1] * num;
      }
    }

    T compute_factorial(int n) {
      assert (n <= max_);
      return fact_[n];
    }

  private:
    int max_;
    std::vector<T> fact_;
};

template <typename T>
class binomial_computer {
  public:
    explicit binomial_computer(int max)
        : max_(max), fact_(max + 1), invf_(max + 1) { }

    void initialize() {
      fact_[0] = invf_[0] = 1;
      for (int num = 1; num <= max_; ++num) {
        fact_[num] = fact_[num - 1] * num;
        invf_[num] = invf_[num - 1] / num;
      }
    }

    T compute_binomial(int n, int k) {
      if (n < 0 || k < 0 || k > n) {
        return 0;
      } else {
        assert (n <= max_);
        return fact_[n] * invf_[k] * invf_[n - k];
      }
    }

  private:
    int max_;
    std::vector<T> fact_, invf_;
};
}  



namespace cplib {

}  



#include <algorithm>
#include <cassert>
#include <numeric>
#include <map>
#include <vector>

namespace cplib {
class factorizer {
  public:
    explicit factorizer(int max) : max_(max), div_(max + 1) { }

    void initialize() {
      std::iota(div_.begin(), div_.end(), 0);
      for (int div = 2; div * div <= max_; ++div) {
        if (div_[div] == div) {
          for (int mul = div * div; mul <= max_; mul += div) {
            div_[mul] = div;
          }
        }
      }
    }

    bool is_prime(int64_t num) const {
      assert(1 <= num && num <= max_ * 1ll * max_);
      for (int div = 2; div * 1ll * div <= num && max_ < num; ++div) {
        if (num % div == 0) {
          return false;
        }  
      }

      if (max_ < num) {
        return true;
      } else {
        return num != 1 && div_[num] == num;
      }
    }

    std::map<int64_t, int> factorize(int64_t num) const {
      assert(1 <= num && num <= max_ * 1ll * max_);
      std::map<int64_t, int> pow;

      for (int div = 2; div * 1ll * div <= num && max_ < num; ++div) {
        while (num % div == 0) {
          ++pow[div];
          num /= div;
        }
      }

      if (max_ < num) {
        ++pow[num];
      } else {
        while (num > 1) {
          ++pow[div_[num]];
          num /= div_[num];
        }
      }

      return pow;
    }

  private:
    int max_;
    std::vector<int> div_; 
};

std::vector<int> divisors(int num) {
  std::vector<int> divs;
  for (int div = 1; div * div <= num; ++div) {
    if (num % div == 0) {
      divs.push_back(div);
      if (num / div != div) {
        divs.push_back(num / div);
      }
    }
  }
  std::sort(divs.begin(), divs.end());
  return divs;
}

template <int mod>
class static_modint {
    using mint = static_modint;
  
  public:
    static_modint() : val_(0) { }

    template <typename T>
    static_modint(T val) {
      val %= mod;
      if (val < 0) {
        val += mod;
      }
      val_ = val;
    }

    int val() const {
      return val_;
    }

    mint& operator++() {
      ++val_;
      if (val_ == mod) {
        val_ = 0;
      }
      return *this;
    }
    mint& operator--() {
      if (val_ == 0) {
        val_ = mod;
      }
      --val_;
      return *this;
    }
    mint operator++(int) {
      mint result = *this;
      ++*this;
      return result;
    }
    mint operator--(int) {
      mint result = *this;
      --*this;
      return result;
    }

    mint& operator+=(const mint& rhs) {
      val_ += rhs.val_;
      if (val_ >= mod) {
        val_ -= mod;
      }
      return *this;
    }
    mint& operator-=(const mint& rhs) {
      val_ -= rhs.val_;
      if (val_ < 0) {
        val_ += mod;
      }
      return *this;
    }
    mint& operator*=(const mint& rhs) {
      int64_t prod = val_ * 1ull * rhs.val_;
      val_ = prod % mod;
      return *this;
    }
    mint& operator/=(const mint& rhs) {
      return *this = *this * rhs.inv();
    }

    mint operator+() const {
      return *this;
    }
    mint operator-() const {
      return mint() - *this;
    }

    mint pow(int64_t exponent) const {
      assert(0 <= exponent);
      mint base = *this, result = 1;
      while (exponent) {
        if (exponent & 1) {
          result *= base;
        }
        base *= base;
        exponent >>= 1;
      }
      return result;
    }
    mint inv() const {
      assert(val_);
      return pow(mod - 2);
    }

    friend mint operator+(const mint& lhs, const mint& rhs) {
      return mint(lhs) += rhs;
    }
    friend mint operator-(const mint& lhs, const mint& rhs) {
      return mint(lhs) -= rhs;
    }
    friend mint operator*(const mint& lhs, const mint& rhs) {
      return mint(lhs) *= rhs;
    }
    friend mint operator/(const mint& lhs, const mint& rhs) {
      return mint(lhs) /= rhs;
    }
    friend bool operator==(const mint& lhs, const mint& rhs) {
      return lhs.val_ == rhs.val_;
    }
    friend bool operator!=(const mint& lhs, const mint& rhs) {
      return lhs.val_ != rhs.val_;
    }

  private:
    int val_;
};

using modint998244353 = static_modint<998244353>;
using modint1000000007 = static_modint<1000000007>;
}  


 
#include <cassert>
#include <deque>
#include <functional>
#include <optional>
#include <vector>
 
namespace cplib {
using graph_t = std::vector<std::vector<int>>;
 
enum class dfs_color {
  k_white = 0,
  k_gray = 1,
  k_black = 2,
};

class dfs_visitor {
  public:
    virtual void initialize_vertex(int, const graph_t&) { };
    virtual void discover_vertex(int, const graph_t&) { };
    virtual void examine_edge(int, int, const graph_t&) { };
    virtual void tree_edge_preorder(int, int, const graph_t&) { };
    virtual void tree_edge_postorder(int, int, const graph_t&) { };
    virtual void back_edge(int, int, const graph_t&) { };
    virtual void forward_or_cross_edge(int, int, const graph_t&) { };
    virtual void finish_edge(int, int, const graph_t&) { };
    virtual void finish_vertex(int, const graph_t&) { };
};
 
template <class DFSVisitor>
void depth_first_search(const graph_t& graph, DFSVisitor& visitor) {
  const int len = graph.size();
  std::vector<dfs_color> color(len, dfs_color::k_white);

  std::function<void(int)> dfs_visit = [&] (int v) {
    visitor.discover_vertex(v, graph);
    color[v] = dfs_color::k_gray;
 
    for (auto u : graph[v]) {
      visitor.examine_edge(v, u, graph);
      if (color[u] == dfs_color::k_white) {
        visitor.tree_edge_preorder(v, u, graph);
        dfs_visit(u);
        visitor.tree_edge_postorder(v, u, graph);
      } else if (color[u] == dfs_color::k_gray) {
        visitor.back_edge(v, u, graph);
      } else {
        assert(color[u] == dfs_color::k_black);
        visitor.forward_or_cross_edge(v, u, graph);
      }
      visitor.finish_edge(v, u, graph);
    }
    
    color[v] = dfs_color::k_black;
    visitor.finish_vertex(v, graph);
  };
 
  for (int v = 0; v < len; ++v) {
    visitor.initialize_vertex(v, graph);
  }
 
  for (int v = 0; v < len; ++v) {
    if (color[v] == dfs_color::k_white) {
      dfs_visit(v);
    }
  }
}
 
enum class bfs_color {
  k_white = 0,
  k_gray = 1,
  k_black = 2,
};

class bfs_visitor {
  public:
    virtual bool initialize_vertex(int, const graph_t&) { return false; };
    virtual void discover_vertex(int, const graph_t&) { };
    virtual void examine_vertex(int, int, const graph_t&) { };
    virtual void examine_edge(int, int, const graph_t&) { };
    virtual void tree_edge(int, int, const graph_t&) { };
    virtual void non_tree_edge(int, int, const graph_t&) { };
    virtual void gray_target(int, int, const graph_t&) { };
    virtual void black_target(int, int, const graph_t&) { };
    virtual void finish_vertex(int, const graph_t&) { };
};

template <class BFSVisitor>
void breadth_first_search(const graph_t& graph,
                          BFSVisitor& visitor,
                          int start) {
  const int len = graph.size();
  std::vector<bfs_color> color(len, bfs_color::k_white);
 
  std::deque<int> queue;
  
  for (int v = 0; v < len; ++v) {
    if (visitor.initialize_vertex(v, graph)) {
      color[start] = bfs_color::k_gray;
      visitor.discover_vertex(start, graph);
      queue.push_back(start);
    }
  }

  while (!queue.empty()) {
    auto v = queue.front();
    visitor.examine_vertex(v, graph);
    queue.pop_front();

    for (auto u : graph[v]) {
      visitor.examine_edge(u, v, graph);

      if (color[u] == bfs_color::k_white) {
        visitor.tree_edge(v, u, graph);
        color[u] = bfs_color::k_gray;
        visitor.discover_vertex(u);
        queue.push_back(u);
      } else {
        visitor.non_tree_edge(v, u, graph);
        if (color[u] == bfs_color::k_gray) {
          visitor.gray_target(v, u, graph);
        } else {
          assert(color[u] == bfs_color::k_black);
          visitor.black_target(v, u, graph);
        }
      }
    }

    color[v] = bfs_color::k_black;
    visitor.finish_vertex(v, graph);
  }
}

std::optional<std::vector<int>> toposort(const graph_t& graph) {
  const int len = graph.size();
  std::vector<int> in_deg(len);
  for (int v = 0; v < len; ++v) {
    for (auto u : graph[v]) {
      ++in_deg[u];
    }
  }

  std::deque<int> bfs;
  for (int v = 0; v < len; ++v) {
    if (!in_deg[v]) {
      bfs.push_back(v);
    }
  }

  std::vector<int> order;
  while (!bfs.empty()) {
    auto v = bfs.front();
    bfs.pop_front();

    order.push_back(v);
    for (auto u : graph[v]) {
      --in_deg[u];
      if (!in_deg[u]) {
        bfs.emplace_back(u);
      }
    }
  }

  if (order.size() == len) {
    return order;
  } else {
    return std::nullopt;
  }
}
}  

 



 
#include <algorithm>
#include <functional>
#include <limits>
#include <utility>
#include <vector>
#include <queue>

namespace cplib {
template <typename T>
int sgn(T x) {
  return (x > 0) - (x < 0);
}

template <typename T, typename U>
T ckmin(T& lhs, U rhs) {
  return lhs = std::min<T>(lhs, rhs);
}

template <typename T, typename U>
T ckmax(T& lhs, U rhs) {
  return lhs = std::max<T>(lhs, rhs);
}

template <typename T> 
bool supmask(T lhs, T rhs) {
  return (lhs | rhs) == lhs;
}

template <typename T> 
bool submask(T lhs, T rhs) {
  return (lhs & rhs) == lhs;
}

template <typename T, class ForwardIt>
T max_subarray_sum(ForwardIt begin, ForwardIt end) {
  T ps = 0, min_ps = 0, max_ss = std::numeric_limits<T>::min();
  for (auto it = begin; it != end; ++it) {
    ps += *it;
    max_ss = std::max(max_ss, ps - min_ps);
    min_ps = std::min(min_ps, ps);
  }
  return max_ss;
}
 
template <typename T>
class window_slider {
  public:
    virtual void push_back(T) { }
    virtual bool predicate() const { return false; }
    virtual void pop_front() { }
    virtual void finish_item(int, int) { }
};
 
template <class ForwardIt, class WindowSlider>
void sliding_window(ForwardIt begin, ForwardIt end, WindowSlider& slider) {
  int left = 0, right = 0;
  for (auto it = begin; it != end; ++it) {
    slider.push_back(*it), ++right;
    while (!slider.predicate()) {
      slider.pop_front(), ++left;
    }
    slider.finish_item(left, right);
  }
}
 
template <typename T>
class mo_slider {
  public:
    virtual void push_back(T) { }
    virtual void push_front(T) { }
    virtual void pop_front() { }
    virtual void pop_back() { }
    virtual void finish_item(int, int) { }
};
 
template <class ForwardElemIt, class ForwardQueryIt, class MoSlider>
void mo_algorithm(ForwardElemIt elems_begin, ForwardElemIt elems_end,
                  ForwardQueryIt queries_begin, ForwardQueryIt queries_end,
                  MoSlider& slider) {
  int left = 0, right = 0;
  auto left_it = elems_begin, right_it = elems_begin;

  for (auto query_it = queries_begin; query_it != queries_end; ++query_it) {
    while (left > query_it->first) {
      --left, --left_it;
      slider.push_front(*left_it);
    }

    while (right < query_it->second) {
      slider.push_back(*right_it);
      ++right, ++right_it;
    }

    while (left < query_it->first) {
      slider.pop_front();
      ++left, ++left_it;
    }

    while (right > query_it->second) {
      --right, --right_it;
      slider.pop_back();
    }

    slider.finish_item(query_it->first, query_it->second);
  }
}

template <typename T>
using max_heap = std::priority_queue<T>;

template <typename T>
using min_heap = std::priority_queue<T, std::vector<T>, std::greater<T>>;

template <typename T>
T binary_search(T lo, T hi, const std::function<bool(T)>& pred) {
  while (hi - lo > 1) {
    T mi = lo + (hi - lo) / 2;
    if (pred(mi)) {
      lo = mi;
    } else {
      hi = mi;
    }
  }
  return hi;
}

template <class K, class V>
class static_map {
  public:
    explicit static_map(int size_hint) {
      data_.reserve(size_hint);
    }

    void emplace(K key, V val) {
      data_.emplace_back(key, val);
    }

    void initialize() {
      std::sort(data_.begin(), data_.end());
    }

    auto lower_bound(K key) {
      return std::lower_bound(data_.begin(), data_.end(), std::make_pair(key, V()));
    }

  private:
    std::vector<std::pair<K, V>> data_;
};
}  


using namespace std;
using namespace cplib;

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int t; cin >> t; while (t--) {
    int n;
    string s;
    cin >> n >> s;
    assert(s.length() == n);

    vector<vector<int>> kd(2, vector<int>(n + 1));
    for (int i = 0; i < n; ++i) {
      kd[0][i + 1] = kd[0][i];
      kd[1][i + 1] = kd[1][i];

      if (s[i] == 'K') {
        ++kd[0][i + 1];
      } else {
        assert(s[i] == 'D');
        ++kd[1][i + 1];
      }
    }

    
    vector<int> dp(n + 1);
    for (int i = 0; i < n; ++i) {
      dp[i + 1] = 1;
      int g = gcd(kd[0][i + 1], kd[1][i + 1]);
      if (g) {
        int len = (i + 1) / g;
        for (int j = i + 1 - len; j >= 0; j -= len) {
          if ((kd[0][i + 1] - kd[0][j]) * 1ll * kd[1][i + 1] ==
              (kd[1][i + 1] - kd[1][j]) * 1ll * kd[0][i + 1]) {
            ckmax(dp[i + 1], dp[j] + 1);
            break;
          }
        }
      } else {
        dp[i + 1] = i + 1;
      }
    }

    for (int i = 0; i < n; ++i) {
      cout << dp[i + 1] << " ";
    }
    cout << "\n";
  }

  return 0;
}