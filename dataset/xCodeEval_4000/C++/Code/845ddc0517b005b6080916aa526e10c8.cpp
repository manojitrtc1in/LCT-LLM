


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
std::ostream& operator<<(std::ostream& os, const std::optional<T>& opt) {
  return opt ? os << *opt : os << "nullopt";
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

template <int I, typename... Ts>
void print_tuple(std::ostream& os, const std::tuple<Ts...>& t) {
  static_assert(0 <= I && I <= sizeof...(Ts));
  if constexpr (I != sizeof...(Ts)) {
    if constexpr (I != 0) {
      os << ", ";
    }
    os << std::get<I>(t);
    print_tuple<I + 1>(os, t);
  }
}

}  


template <typename... Ts>
std::ostream& operator<<(std::ostream& os, const std::tuple<Ts...>& t) {
  os << '{';
  detail::print_tuple<0>(os, t);
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

template <typename... Ts>
void print(int line, std::string_view names, const Ts&... vals) {
  std::cerr << "  " << line << " | ";
  print(names, vals...);
}

}  


#ifdef TYLER
#define debug(...) detail::print(__LINE__, #__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) ((void)0)
#endif

bool better(const pair<long long, vector<int>>& a,
            const pair<long long, vector<int>>& b) {
  return a.first != b.first ? a.first > b.first : a.second < b.second;
}

int main_small() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.precision(12);
  std::cerr.precision(12);
  std::mt19937 rng((std::uint_fast32_t)std::chrono::high_resolution_clock::now()
                       .time_since_epoch()
                       .count());
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  vector<vector<pair<long long, vector<int>>>> dp(
      n + 1, vector<pair<long long, vector<int>>>(n + 1, {0, {}}));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j <= i; ++j) {
      if (better(dp[i][j], dp[i + 1][j])) {
        dp[i + 1][j] = dp[i][j];
      }
      dp[i][j].first += a[i];
      dp[i][j].second.push_back(a[i]);
      if (better(dp[i][j], dp[i + 1][j + 1])) {
        dp[i + 1][j + 1] = dp[i][j];
      }
      dp[i][j].first -= a[i];
      dp[i][j].second.pop_back();
    }
  }
  int m;
  cin >> m;
  for (int i = 0; i < m; ++i) {
    int k, pos;
    cin >> k >> pos;
    cout << dp[n][k].second[pos - 1] << '\n';
  }
  return 0;
}

template <typename Key, typename Compare = std::less<Key>>
class splay_set {
  static_assert(std::is_same_v<
                std::invoke_result_t<Compare, const Key&, const Key&>, bool>);

 public:
  using key_type = Key;
  using value_type = Key;
  using size_type = int;
  using difference_type = int;
  using key_compare = Compare;
  using value_compare = Compare;
  using reference = Key&;
  using const_reference = const Key&;
  using pointer = Key*;
  using const_pointer = const Key*;

 private:
  struct node {
    node *parent, *left, *right;
    const Key key;
    size_type size;

    node(node* _parent, const Key& _key, int _size = 1)
        : parent(_parent),
          left(nullptr),
          right(nullptr),
          key(_key),
          size(_size) {}

    void update() {
      size = 1 + (left == nullptr ? 0 : left->size) +
             (right == nullptr ? 0 : right->size);
    }
  };

 public:
  struct iterator {
   public:
    using iterator_category = std::bidirectional_iterator_tag;
    using value_type = Key;
    using difference_type = int;
    using pointer = const Key*;
    using reference = const Key&;

    iterator& operator++() {
      if (ptr_->right == nullptr) {
        while (ptr_->parent != nullptr && ptr_->parent->right == ptr_) {
          ptr_ = ptr_->parent;
        }
        if ((ptr_ = ptr_->parent) != nullptr) {
          tree_->splay(ptr_);
        }
      } else {
        ptr_ = ptr_->right;
        while (ptr_->left != nullptr) {
          ptr_ = ptr_->left;
        }
        tree_->splay(ptr_);
      }
      return *this;
    }

    iterator operator++(int) {
      iterator t = *this;
      ++*this;
      return t;
    }

    iterator& operator--() {
      if (ptr_ == nullptr) {
        ptr_ = tree_->root_;
        while (ptr_->right != nullptr) {
          ptr_ = ptr_->right;
        }
      } else if (ptr_->left == nullptr) {
        while (ptr_->parent->left == ptr_) {
          ptr_ = ptr_->parent;
        }
        ptr_ = ptr_->parent;
      } else {
        ptr_ = ptr_->left;
        while (ptr_->right != nullptr) {
          ptr_ = ptr_->right;
        }
      }
      tree_->splay(ptr_);
      return *this;
    }

    iterator operator--(int) {
      iterator t = *this;
      --*this;
      return t;
    }

    bool operator==(const iterator& other) const { return ptr_ == other.ptr_; }

    bool operator!=(const iterator& other) const { return ptr_ != other.ptr_; }

    reference operator*() const { return ptr_->key; }

   private:
    friend splay_set;

    splay_set* tree_;
    node* ptr_;

    iterator(splay_set* tree, node* ptr) : tree_(tree), ptr_(ptr) {}
  };

  struct const_iterator {
   public:
    using iterator_category = std::bidirectional_iterator_tag;
    using value_type = Key;
    using difference_type = int;
    using pointer = const Key*;
    using reference = const Key&;

    const_iterator(const iterator& it) : tree_(it.tree_), ptr_(it.ptr_) {}

    const_iterator& operator++() {
      if (ptr_->right == nullptr) {
        while (ptr_->parent != nullptr && ptr_->parent->right == ptr_) {
          ptr_ = ptr_->parent;
        }
        ptr_ = ptr_->parent;
      } else {
        ptr_ = ptr_->right;
        while (ptr_->left != nullptr) {
          ptr_ = ptr_->left;
        }
      }
      return *this;
    }

    const_iterator operator++(int) {
      const_iterator t = *this;
      ++*this;
      return t;
    }

    const_iterator& operator--() {
      if (ptr_ == nullptr) {
        ptr_ = tree_->root_;
        while (ptr_->right != nullptr) {
          ptr_ = ptr_->right;
        }
      } else if (ptr_->left == nullptr) {
        while (ptr_->parent->left == ptr_) {
          ptr_ = ptr_->parent;
        }
        ptr_ = ptr_->parent;
      } else {
        ptr_ = ptr_->left;
        while (ptr_->right != nullptr) {
          ptr_ = ptr_->right;
        }
      }
      return *this;
    }

    const_iterator operator--(int) {
      const_iterator t = *this;
      --*this;
      return t;
    }

    bool operator==(const const_iterator& other) const {
      return ptr_ == other.ptr_;
    }

    bool operator!=(const const_iterator& other) const {
      return ptr_ != other.ptr_;
    }

    reference operator*() const { return ptr_->key; }

   private:
    friend splay_set;

    const splay_set* tree_;
    const node* ptr_;

    const_iterator(const splay_set* tree, const node* ptr)
        : tree_(tree), ptr_(ptr) {}
  };

  using reverse_iterator = std::reverse_iterator<iterator>;
  using const_reverse_iterator = std::reverse_iterator<const_iterator>;

  splay_set(const Compare& comp = Compare()) : comp_(comp), root_(nullptr) {}

  splay_set(const splay_set& other) : comp_(other.comp_) {
    if (other.root_ == nullptr) {
      root_ = nullptr;
      return;
    }
    root_ = new node(nullptr, other.root_->key, other.root_->size);
    for (node *x = root_, *y = other.root_;;) {
      if (x->left == nullptr && y->left != nullptr) {
        y = y->left;
        x = x->left = new node(x, y->key, y->size);
      } else if (x->right == nullptr && y->right != nullptr) {
        y = y->right;
        x = x->right = new node(x, y->key, y->size);
      } else {
        if (x->parent == nullptr) {
          return;
        }
        x = x->parent;
        y = y->parent;
      }
    }
  }

  splay_set(splay_set&& other) : comp_(other.comp_), root_(other.root_) {
    other.root_ = nullptr;
  }

  ~splay_set() { clear(); }

  splay_set& operator=(const splay_set& other) {
    return *this = splay_set(other);
  }

  splay_set& operator=(splay_set&& other) {
    clear();
    comp_ = other.comp_;
    root_ = other.root_;
    other.root_ = nullptr;
    return *this;
  }

  iterator begin() {
    if (root_ == nullptr) {
      return iterator(this, nullptr);
    }
    node* x = root_;
    while (x->left != nullptr) {
      x = x->left;
    }
    splay(x);
    return iterator(this, x);
  }

  const_iterator begin() const {
    if (root_ == nullptr) {
      return const_iterator(this, nullptr);
    }
    node* x = root_;
    while (x->left != nullptr) {
      x = x->left;
    }
    return const_iterator(this, x);
  }

  const_iterator cbegin() const { return begin(); }

  iterator end() { return iterator(this, nullptr); }

  const_iterator end() const { return const_iterator(this, nullptr); }

  const_iterator cend() const { return end(); }

  reverse_iterator rbegin() { return reverse_iterator(end()); }

  const_reverse_iterator rbegin() const {
    return const_reverse_iterator(end());
  }

  const_reverse_iterator crbegin() const { return rbegin(); }

  reverse_iterator rend() { return reverse_iterator(begin()); }

  const_reverse_iterator rend() const {
    return const_reverse_iterator(begin());
  }

  const_reverse_iterator crend() const { return rend(); }

  bool empty() const { return root_ == nullptr; }

  size_type size() const { return root_ == nullptr ? 0 : root_->size; }

  void clear() {
    if (root_ == nullptr) {
      return;
    }
    for (node* x = root_;;) {
      if (x->left != nullptr) {
        x = x->left;
      } else if (x->right != nullptr) {
        x = x->right;
      } else {
        if (x->parent == nullptr) {
          root_ = nullptr;
          delete x;
          return;
        }
        node* y = x;
        x = x->parent;
        if (x->left == y) {
          x->left = nullptr;
        } else {
          x->right = nullptr;
        }
        delete y;
      }
    }
  }

  std::pair<iterator, bool> insert(const Key& key) {
    if (root_ == nullptr) {
      root_ = new node(nullptr, key);
      return std::pair(iterator(this, root_), true);
    }
    for (node* x = root_;;) {
      if (comp_(key, x->key)) {
        if (x->left == nullptr) {
          x = x->left = new node(x, key);
          splay(x);
          return std::pair(iterator(this, x), true);
        }
        x = x->left;
      } else if (comp_(x->key, key)) {
        if (x->right == nullptr) {
          x = x->right = new node(x, key);
          splay(x);
          return std::pair(iterator(this, x), true);
        }
        x = x->right;
      } else {
        splay(x);
        return std::pair(iterator(this, x), false);
      }
    }
  }

  iterator erase(iterator pos) {
    node *x = pos.ptr_, *y, *z;
    if (x->right == nullptr) {
      y = x;
      while (y->parent != nullptr && y->parent->right == y) {
        y = y->parent;
      }
      y = y->parent;
      if ((z = x->left) != nullptr) {
        z->parent = x->parent;
      }
    } else {
      y = x->right;
      y->parent = nullptr;
      while (y->left != nullptr) {
        y = y->left;
      }
      splay(z = y);
      if (x->left != nullptr) {
        y->left = x->left;
        y->left->parent = y;
        y->update();
      }
      y->parent = x->parent;
    }
    if (x->parent == nullptr) {
      root_ = z;
    } else {
      if (x->parent->left == x) {
        x->parent->left = z;
      } else {
        x->parent->right = z;
      }
      x->parent->update();
      splay(x->parent);
    }
    delete x;
    return iterator(this, y);
  }

  size_type erase(const Key& key) {
    if (root_ == nullptr) {
      return 0;
    }
    node* x = root_;
    while (true) {
      if (comp_(key, x->key)) {
        if (x->left == nullptr) {
          splay(x);
          return 0;
        }
        x = x->left;
      } else if (comp_(x->key, key)) {
        if (x->right == nullptr) {
          splay(x);
          return 0;
        }
        x = x->right;
      } else {
        break;
      }
    }
    node* y;
    if (x->right == nullptr) {
      if ((y = x->left) != nullptr) {
        y->parent = x->parent;
      }
    } else {
      y = x->right;
      if (x->left != nullptr) {
        y->parent = nullptr;
        while (y->left != nullptr) {
          y = y->left;
        }
        splay(y);
        y->left = x->left;
        y->left->parent = y;
        y->update();
      }
      y->parent = x->parent;
    }
    if (x->parent == nullptr) {
      root_ = y;
    } else {
      if (x->parent->left == x) {
        x->parent->left = y;
      } else {
        x->parent->right = y;
      }
      x->parent->update();
      splay(x->parent);
    }
    delete x;
    return 1;
  }

  void swap(splay_set& other) {
    std::swap(comp_, other.comp_);
    std::swap(root_, other.root_);
  }

  size_type count(const Key& key) { return find(key) == end() ? 0 : 1; }

  iterator find(const Key& key) {
    if (root_ == nullptr) {
      return iterator(this, nullptr);
    }
    for (node* x = root_;;) {
      if (comp_(key, x->key)) {
        if (x->left == nullptr) {
          splay(x);
          return iterator(this, nullptr);
        }
        x = x->left;
      } else if (comp_(x->key, key)) {
        if (x->right == nullptr) {
          splay(x);
          return iterator(this, nullptr);
        }
        x = x->right;
      } else {
        splay(x);
        return iterator(this, x);
      }
    }
  }

  std::pair<iterator, iterator> equal_range(const Key& key) {
    return std::pair(lower_bound(key), upper_bound(key));
  }

  iterator lower_bound(const Key& key) {
    if (root_ == nullptr) {
      return iterator(this, nullptr);
    }
    for (node *x = root_, *y = nullptr;;) {
      if (comp_(key, x->key)) {
        if (x->left == nullptr) {
          splay(x);
          return iterator(this, x);
        }
        y = x;
        x = x->left;
      } else if (comp_(x->key, key)) {
        if (x->right == nullptr) {
          splay(x);
          return iterator(this, y);
        }
        x = x->right;
      } else {
        splay(x);
        return iterator(this, x);
      }
    }
  }

  iterator upper_bound(const Key& key) {
    if (root_ == nullptr) {
      return iterator(this, nullptr);
    }
    for (node *x = root_, *y = nullptr;;) {
      if (comp_(key, x->key)) {
        if (x->left == nullptr) {
          splay(x);
          return iterator(this, x);
        }
        y = x;
        x = x->left;
      } else {
        if (x->right == nullptr) {
          splay(x);
          return iterator(this, y);
        }
        x = x->right;
      }
    }
  }

  iterator find_by_order(size_type order) {
    if (root_ == nullptr || order >= root_->size) {
      return iterator(this, nullptr);
    }
    for (node* x = root_;;) {
      if (size_type left_size = x->left == nullptr ? 0 : x->left->size;
          order < left_size) {
        x = x->left;
      } else if (order > left_size) {
        order -= left_size + 1;
        x = x->right;
      } else {
        splay(x);
        return iterator(this, x);
      }
    }
  }

  size_type order_of_key(const Key& key) {
    if (root_ == nullptr) {
      return 0;
    }
    int order = 0;
    for (node* x = root_;;) {
      if (comp_(key, x->key)) {
        if (x->left == nullptr) {
          splay(x);
          return order;
        }
        x = x->left;
      } else if (order += x->left == nullptr ? 0 : x->left->size;
                 comp_(x->key, key)) {
        ++order;
        if (x->right == nullptr) {
          splay(x);
          return order;
        }
        x = x->right;
      } else {
        splay(x);
        return order;
      }
    }
  }

  Compare key_comp() const { return comp_; }

  Compare value_comp() const { return comp_; }

  friend void swap(splay_set& lhs, splay_set& rhs) { lhs.swap(rhs); }

 private:
  Compare comp_;
  node* root_;

  void rotate_left(node* y) {
    node* x = y->right;
    if (y->parent != nullptr) {
      if (y->parent->left == y) {
        y->parent->left = x;
      } else {
        y->parent->right = x;
      }
    }
    if ((y->right = x->left) != nullptr) {
      y->right->parent = y;
    }
    x->left = y;
    x->parent = y->parent;
    y->parent = x;
    y->update();
    x->update();
  }

  void rotate_right(node* y) {
    node* x = y->left;
    if (y->parent != nullptr) {
      if (y->parent->left == y) {
        y->parent->left = x;
      } else {
        y->parent->right = x;
      }
    }
    if ((y->left = x->right) != nullptr) {
      y->left->parent = y;
    }
    x->right = y;
    x->parent = y->parent;
    y->parent = x;
    y->update();
    x->update();
  }

  void splay(node* x) {
    while (x->parent != nullptr) {
      if (x->parent->left == x) {
        if (x->parent->parent == nullptr) {
          rotate_right(x->parent);
        } else if (x->parent->parent->left == x->parent) {
          rotate_right(x->parent->parent);
          rotate_right(x->parent);
        } else {
          rotate_right(x->parent);
          rotate_left(x->parent);
        }
      } else {
        if (x->parent->parent == nullptr) {
          rotate_left(x->parent);
        } else if (x->parent->parent->right == x->parent) {
          rotate_left(x->parent->parent);
          rotate_left(x->parent);
        } else {
          rotate_left(x->parent);
          rotate_right(x->parent);
        }
      }
    }
    root_ = x;
  }
};

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

template <typename Key, typename Compare = std::less<Key>,
          typename Allocator = std::allocator<Key>>
using ordered_set =
    __gnu_pbds::tree<Key, __gnu_pbds::null_type, Compare,
                     __gnu_pbds::rb_tree_tag,
                     __gnu_pbds::tree_order_statistics_node_update, Allocator>;

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.precision(12);
  std::cerr.precision(12);
  std::mt19937 rng((std::uint_fast32_t)std::chrono::high_resolution_clock::now()
                       .time_since_epoch()
                       .count());
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  vector<pair<int, int>> sorted;
  sorted.reserve(n);
  for (int i = 0; i < n; ++i) {
    sorted.emplace_back(a[i], i);
  }
  sort(sorted.begin(), sorted.end(),
       [](const pair<int, int>& p, const pair<int, int>& q) {
         return p.first != q.first ? p.first > q.first : p.second < q.second;
       });
  int m;
  cin >> m;
  vector<vector<pair<int, int>>> query(n);
  for (int i = 0; i < m; ++i) {
    int k, pos;
    cin >> k >> pos;
    query[k - 1].emplace_back(i, pos - 1);
  }
  vector<int> ans(m);
  splay_set<int> act;
  for (int i = 0; i < n; ++i) {
    act.insert(sorted[i].second);
    for (auto& [j, pos] : query[i]) {
      ans[j] = *act.find_by_order(pos);
    }
  }
  for (int i : ans) {
    cout << a[i] << '\n';
  }
  return 0;
}

template <typename T>
class bi_tree {
 public:
  bi_tree(int n) : h1b_(highest_one_bit(n)), data_(n) {}

  bi_tree(const std::vector<T>& data)
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

  friend std::ostream& operator<<(std::ostream& os, const bi_tree& tree) {
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

int main_large() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.precision(12);
  std::cerr.precision(12);
  std::mt19937 rng((std::uint_fast32_t)std::chrono::high_resolution_clock::now()
                       .time_since_epoch()
                       .count());
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  vector<pair<int, int>> sorted;
  sorted.reserve(n);
  for (int i = 0; i < n; ++i) {
    sorted.emplace_back(a[i], i);
  }
  sort(sorted.begin(), sorted.end(),
       [](const pair<int, int>& p, const pair<int, int>& q) {
         return p.first != q.first ? p.first > q.first : p.second < q.second;
       });
  int m;
  cin >> m;
  vector<vector<pair<int, int>>> query(n);
  for (int i = 0; i < m; ++i) {
    int k, pos;
    cin >> k >> pos;
    query[k - 1].emplace_back(i, pos - 1);
  }
  vector<int> ans(m);
  bi_tree<int> act(n);
  for (int i = 0; i < n; ++i) {
    act.add(sorted[i].second, 1);
    for (auto& [j, pos] : query[i]) {
      ans[j] = act.upper_bound(pos);
    }
  }
  for (int i : ans) {
    cout << a[i] << '\n';
  }
  return 0;
}
