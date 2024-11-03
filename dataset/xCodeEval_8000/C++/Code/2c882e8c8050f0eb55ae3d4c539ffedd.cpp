#include <algorithm>
#include <cmath>
#include <complex>
#include <cstdio>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <memory>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using std::cin;
using std::cout;
using std::istream;
using std::ostream;
using std::pair;
using std::string;
using std::vector;

using vi_ = vector<int>;
using vs_ = vector<size_t>;
using vb_ = vector<bool>;
using vd_ = vector<double>;
using vvi_ = vector<vi_>;
using vvs_ = vector<vs_>;
using vvb_ = vector<vb_>;
using vvd_ = vector<vd_>;



template<typename T, typename ...Args>
std::unique_ptr<T> make_unique(Args &&...args) {
  return std::unique_ptr<T>(new T(std::forward<Args>(args)...));
}

template<class Hashable_Type>
void hash_combine(size_t &seed, const Hashable_Type &v) {
  static std::hash<Hashable_Type> hash;
  seed ^= hash(v) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
}

namespace std {
  template<class Hashable_First_Type, class Hashable_Second_Type>
  struct hash<pair<Hashable_First_Type, Hashable_Second_Type>> {
    inline size_t operator()(const pair<Hashable_First_Type, Hashable_Second_Type> &pr) const {
      size_t seed = 0;
      ::hash_combine(seed, pr.first);
      ::hash_combine(seed, pr.second);
      return seed;
    }
  };
} 


size_t GetMonthIndex(const string &name) {
  static const std::unordered_map<string, size_t> months {
      {"January",   0},
      {"February",  1},
      {"March",     2},
      {"April",     3},
      {"May",       4},
      {"June",      5},
      {"July",      6},
      {"August",    7},
      {"September", 8},
      {"October",   9},
      {"November",  10},
      {"December",  11}
  };
  return months.find(name)->second;
}



size_t StringMismatches(const string &first, const string &second) {
  auto min_size = std::min(first.size(), second.size());
  size_t ans = std::max(first.size(), second.size()) - min_size;
  for (size_t pos = 0; pos < min_size; ++pos) {
    ans += (first[pos] != second[pos]);
  }
  return ans;
}



string CorrectifyBrackets(const string &text) {
  string ans;
  ans.reserve(text.size());
  std::transform(text.rbegin(), text.rend(), std::back_inserter(ans), [](const char &sym) {
    if (sym == '(') {
      return ')';
    } else if (sym == '[') {
      return ']';
    } else {
      return '}';
    }
  });
  return ans;
}



pair<size_t, string> CorrectBracketSequence(const string &text) {
  string stack;
  stack.reserve(text.size());
  for (size_t symbol_index = 0; symbol_index < text.size(); ++symbol_index) {
    auto bracket = text[symbol_index];
    if (bracket == '(' || bracket == '[' || bracket == '{') {
      stack.push_back(bracket);
    } else {
      if (stack.empty()) {
        return std::make_pair(symbol_index, CorrectifyBrackets(stack));
      }
      auto last = stack.back();
      if ((bracket == ')' && last != '(') || (bracket == ']' && last != '[') ||
          (bracket == '}' && last != '{')) {
        return std::make_pair(symbol_index, CorrectifyBrackets(stack));
      }
      stack.pop_back();
    }
  }
  return std::make_pair(text.size(), CorrectifyBrackets(stack));
}

template<typename T_Type, typename Function>
class SparseTable {
private:
  static vs_ log_;
  vector<vector<T_Type>> sparse_;
  Function func_;

public:
  SparseTable(const vector<T_Type> &mass, Function func = Function()) : sparse_(), func_(func) {
    auto len = mass.size();
    log_.reserve(len);
    while (log_.size() <= len) {
      log_.insert(log_.end(), static_cast<size_t> (2 << log_.back()), log_.back() + 1);
    }
    sparse_.resize(log_[len] + 1);
    for (size_t pow = 0; pow <= log_[len]; ++pow) {
      sparse_[pow].reserve(len);
      for (size_t j = 0; j < len; ++j) {
        if (pow == 0) {
          sparse_[pow].push_back(func_(mass[j], mass[j]));
        } else {
          sparse_[pow].push_back(func_(sparse_[pow - 1][j],
                                       sparse_[pow - 1][std::min(j + (1 << (pow - 1)),
                                                                 len - 1)]));
        }
      }
    }
  }

  T_Type get(size_t left, size_t right) const {
    return func_(sparse_[log_[right - left]][left],
                 sparse_[log_[right - left]][right - (1 << log_[right - left])]);
  }
};

template<typename T_Type, typename Function> vs_
    SparseTable<T_Type, Function>::log_ {0, 0, 1, 1};



template<typename T_Type>
size_t CommonSubsequence(const vector<T_Type> &first_arr,
                         const vector<T_Type> &second_arr) {
  if (first_arr.size() < second_arr.size()) {
    return CommonSubsequence(second_arr, first_arr);
  }
  if (second_arr.empty()) {
    return 0;
  }
  vs_ ans(second_arr.size(), 0);

  for (const auto &first_element: first_arr) {
    auto prev(ans);
    ans[0] = std::max(prev[0], static_cast<size_t> (first_element == second_arr[0]));
    for (size_t second_pos = 1; second_pos < second_arr.size(); ++second_pos) {
      ans[second_pos] = std::max(prev[second_pos],
                                 prev[second_pos - 1] + (first_element == second_arr[second_pos]));
    }
  }
  return *std::max_element(ans.begin(), ans.end());
}

template<class Iterator, class Compare>
Iterator Partition(Iterator first, Iterator last, Compare cmp) {
  static std::mt19937 generator;
  std::uniform_int_distribution<> uid(0, static_cast<int> (last - first - 1));
  auto pivot_value = *(first + uid(generator));

  Iterator left = first;
  Iterator right = last - 1;
  while (left < right) {
    while (left <= right && !cmp(pivot_value, *left)) {
      ++left;
    }
    while (right >= left && cmp(pivot_value, *right)) {
      --right;
    }
    if (left < right) {
      std::iter_swap(left, right);
    }
  }

  if (!cmp(*(left - 1), pivot_value) && !cmp(pivot_value, *(left - 1))) {
    Iterator best_left = left - 1;
    while (best_left > first && !cmp(*(best_left - 1), pivot_value) &&
           !cmp(pivot_value, *(best_left - 1))) {
      --best_left;
    }
    std::uniform_int_distribution<> uid_ans(0, static_cast<int> (left - best_left));
    return uid_ans(generator) + best_left;
  } else {
    return left;
  }
}

template<class Iterator, class Compare>
void QuickSort(Iterator first, Iterator last, Compare cmp) {
  if (first + 1 < last) {
    Iterator mid = Partition(first, last, cmp);
    QuickSort(first, mid, cmp);
    QuickSort(mid, last, cmp);
  }
}

template<class Iterator>
void QuickSort(Iterator first, Iterator last) {
  using value_type = typename std::iterator_traits<Iterator>::value_type;
  QuickSort(first, last, std::less<value_type>());
}

template<class Iterator>
void ReorderKth(Iterator first, Iterator last, size_t kth) {
  using value_type = typename std::iterator_traits<Iterator>::value_type;
  while (first + 1 < last) {
    Iterator mid = Partition(first, last, [](const value_type &lhs, const value_type &rhs) {
      return lhs > rhs;
    });
    if (static_cast<size_t> (mid - first) == kth) {
      return;
    } else if (static_cast<size_t> (mid - first) > kth) {
      last = mid;
    } else {
      kth -= (mid - first);
      first = mid;
    }
  }
}





template<typename Iterator>
long long MergeTwoParts(Iterator left, Iterator mid, Iterator right, Iterator cache, long long diff) {
  long long result = 0;
  auto sl = left, sr = mid, done = cache, best_right = mid;
  while (sl < mid || sr < right) {
    if (sr == right || (sl < mid && sr < right && *sl < *sr)) {
      while (best_right < right && *best_right - *sl < diff) {
        ++best_right;
      }
      result += static_cast<long long> (right - best_right);
      *done = *(sl++);
    } else {
      *done = *(sr++);
    }
    ++done;
  }
  while (left != right) {
    *left++ = *cache++;
  }
  return result;
}



template<typename Iterator>
long long MergeSort(Iterator left, Iterator right, long long diff = 0, size_t merge_size = 1) {
  using value_type = typename std::iterator_traits<Iterator>::value_type;
  vector<value_type> temp_arr(static_cast<size_t> (right - left));
  long long result = 0;
  while (merge_size < temp_arr.size()) {
    Iterator from = left;
    while (from + merge_size < right) {
      result += MergeTwoParts(from, from + merge_size, std::min(from + 2 * merge_size, right),
                              temp_arr.begin(), diff);
      from += 2 * merge_size;
    }
    merge_size <<= 1;
  }
  return result;
}

template<typename Compare, typename Function>
long double BinSearch(long double left, long double right, long double searching = 0.0,
                      Function func = Function(), Compare comp = std::less<long double>()) {
  while (right - left > 1e-7) {
    long double mid = (left + right) / 2.0;
    if (comp(func(mid), searching)) {
      left = mid;
    } else {
      right = mid;
    }
  }
  return (left + right) / 2.0;
}

using type_fft_ = long double;
using complex_fft_ = std::complex<type_fft_>;
using vector_fft_ = vector<complex_fft_>;

void FFT(vector_fft_ &arr, bool invert) {
  for (size_t i = 1, j = 0; i < arr.size(); ++i) {
    size_t bit = arr.size() >> 1;
    for (; j >= bit; bit >>= 1) {
      j -= bit;
    }
    j += bit;
    if (i < j) {
      std::swap(arr[i], arr[j]);
    }
  }

  for (size_t len = 2; len <= arr.size(); len <<= 1) {
    type_fft_ ang = 2 * acosl(-1) / len * (invert ? -1 : 1);
    complex_fft_ wlen(cosl(ang), sinl(ang));
    for (size_t i = 0; i < arr.size(); i += len) {
      complex_fft_ wlong(1);
      for (size_t j = 0; j < len / 2; ++j) {
        auto ulong = arr[i + j];
        auto vlong = arr[i + j + len / 2] * wlong;
        arr[i + j] = ulong + vlong;
        arr[i + j + len / 2] = ulong - vlong;
        wlong *= wlen;
      }
    }
  }

  if (invert) {
    complex_fft_ arr_size = arr.size();
    for (auto &element: arr) {
      element /= arr_size;
    }
  }
}

template<typename Input_Type>
vector_fft_ ResizeFFT(const vector<Input_Type> &mass, size_t degree) {
  vector_fft_ complex_mass(mass.begin(), mass.end());
  complex_mass.resize(degree, 0.0);
  FFT(complex_mass, false);
  return complex_mass;
}

template<typename Input_Type>
vector_fft_ MultiplyPolynomials(const vector<Input_Type> &first,
                                const vector<Input_Type> &second) {
  size_t degree = 1;
  while (degree < std::max(first.size(), second.size())) {
    degree <<= 1;
  }
  


  auto first_tmp = ResizeFFT(first, degree);
  auto second_tmp = ResizeFFT(second, degree);

  

  

  std::transform(first_tmp.begin(), first_tmp.end(), second_tmp.begin(), second_tmp.begin(),
                 std::multiplies<complex_fft_>());
  FFT(second_tmp, true);
  return second_tmp;
}

vector<long long> MultiplyIntPolynomials(const vi_ &first, const vi_ &second) {
  auto ans = MultiplyPolynomials(first, second);
  vector<long long> long_ans;
  long_ans.reserve(ans.size());
  for (const auto &element: ans) {
    long_ans.push_back(llroundl(element.real()));
  }
  return long_ans;
}




























template<typename T_Type, class Compare>
class Heap {
private:
  Compare cmp_;
  vector<T_Type *> data_;

  void swapInHeap(size_t first, size_t second) {
    std::swap(data_[first], data_[second]);
    data_[first]->heap_position = first;
    data_[second]->heap_position = second;
  }



  void update(size_t position) {
    if (position < data_.size()) {
      siftDown(position);
      siftUp(position);
    }
  }

  void siftUp(size_t current) {
    while (current != 0) {
      if (!cmp_(*data_[(current - 1) / 2], *data_[current])) {
        swapInHeap((current - 1) / 2, current);
        current = (current - 1) / 2;
      } else {
        break;
      }
    }
  }

  void siftDown(size_t current) {
    while (2 * current + 1 < data_.size()) {
      if (2 * current + 2 < data_.size()) {
        if (!cmp_(*data_[current], *data_[2 * current + 1]) ||
            !cmp_(*data_[current], *data_[2 * current + 2])) {
          if (cmp_(*data_[2 * current + 1], *data_[2 * current + 2])) {
            swapInHeap(current, 2 * current + 1);
            current = 2 * current + 1;
          } else {
            swapInHeap(current, 2 * current + 2);
            current = 2 * current + 2;
          }
        } else {
          break;
        }
      } else if (!cmp_(*data_[current], *data_[2 * current + 1])) {
        swapInHeap(current, 2 * current + 1);
        current = 2 * current + 1;
      } else {
        break;
      }
    }
  }

public:
  explicit Heap(Compare cmp = Compare()) : cmp_(cmp), data_() {}

  bool empty() const {
    return data_.empty();
  }

  void remove(size_t position) {
    swapInHeap(position, data_.size() - 1);
    data_.back()->heap_position = -1;
    data_.pop_back();
    update(position);
  }

  void insert(T_Type *key) {
    data_.push_back(key);
    key->heap_position = data_.size() - 1;
    siftUp(data_.size() - 1);
  }

  T_Type *getRoot() const {
    return data_[0];
  }
};

template<typename T_Type, typename Function>
T_Type BinPow(T_Type base, T_Type exponent,
              T_Type modulo = std::numeric_limits<T_Type>::max(),
              Function func = std::multiplies<T_Type>(), T_Type default_val = 1) {
  T_Type res = default_val;
  while (exponent) {
    if (exponent & 1) {
      res = func(res, base) % modulo;
    }
    base = func(base, base) % modulo;
    exponent >>= 1;
  }
  return res;
}



template<typename T_Type>
vs_ RepresentInBaseTwo(T_Type num) {
  vs_ ans;
  size_t cur = 0;
  while (num) {
    if (num & 1) {
      ans.push_back(cur);
    }
    num >>= 1;
    ++cur;
  }
  return ans;
}

template<typename T_Type>
const T_Type GCD(T_Type first, T_Type second) {
  first = std::abs(first);
  second = std::abs(second);
  while (first != 0 && second != 0) {
    T_Type other = first % second;
    first = second;
    second = other;
  }
  return first + second;
}

template<typename T_Type>
const T_Type GCDPositive(T_Type first, T_Type second, T_Type &coefficient_first,
                         T_Type &coefficient_second) {
  if (first == 0) {
    coefficient_first = 0;
    coefficient_second = 1;
    return second;
  }
  T_Type ans = GCDPositive(second % first, first, coefficient_first, coefficient_second);
  T_Type other = coefficient_first;
  coefficient_first = coefficient_second - (second / first) * coefficient_first;
  coefficient_second = other;
  return ans;
}

template<typename T_Type>
const T_Type GCD(T_Type first, T_Type second, T_Type &coefficient_first,
                 T_Type &coefficient_second) {
  if (first < 0) {
    T_Type ans = GCD(-first, second, coefficient_first, coefficient_second);
    coefficient_first = -coefficient_first;
    return ans;
  }
  if (second < 0) {
    T_Type ans = GCD(first, -second, coefficient_first, coefficient_second);
    coefficient_second = -coefficient_second;
    return ans;
  }
  return GCDPositive(first, second, coefficient_first, coefficient_second);
}

template<typename T_Type>
const T_Type UnitElement(T_Type remainder, T_Type modulo) {
  T_Type first, second;
  GCD(remainder, modulo, first, second);
  return (first % modulo + modulo) % modulo;
}

template<typename T_Type>
vector<T_Type> InputVector(int len = -1, istream &input = cin) noexcept {
  if (len == -1) {
    input >> len;
  }
  vector<T_Type> arr;
  arr.reserve(static_cast<size_t> (len));
  {
    T_Type element;
    for (int i = 0; i < len; ++i) {
      input >> element;
      arr.push_back(std::move(element));
    }
  }
  return arr;
}

template<typename Container_Type>
void OutputContainer(const Container_Type &container, bool show_len = false, bool with_newline = false,
                     ostream &output = cout) {
  if (show_len) {
    output << container.size() << "\n";
  }
  for (const auto &element: container) {
    output << element;
    output << (with_newline ? "\n" : " ");
  }
}

template<typename T_Type, typename Function, typename Multiple_Function>
class LazySegmentTree {
private:
  struct TreeNode;

  using uniqueNodePtr_ = std::unique_ptr<TreeNode>;
  using nodePtr_ = TreeNode *;

  struct TreeNode {
    T_Type val_;
    bool has_changed_ {true};
    uniqueNodePtr_ left_ {nullptr};
    uniqueNodePtr_ right_ {nullptr};
  };

  uniqueNodePtr_ root_;
  size_t real_size_;
  T_Type default_val_;
  Function func_;
  Multiple_Function multiple_func_;

  void push(nodePtr_ node) {
    if (node->has_changed_) {
      if (node->left_ == nullptr) {
        node->left_ = make_unique<TreeNode>(node->val_, true);
        node->right_ = make_unique<TreeNode>(node->val_, true);
      } else {
        node->left_->val_ = node->right_->val_ = node->val_;
        node->left_->has_changed_ = node->right_->has_changed_ = true;
      }
      node->has_changed_ = false;
    }
  }

  T_Type getData(nodePtr_ node, size_t left, size_t right) const {
    if (node->has_changed_) {
      return multiple_func_(node->val_, right - left);
    } else {
      return node->val_;
    }
  }

  

  

  void setRecursive(nodePtr_ node, size_t left, size_t right, size_t from, size_t to,
                    T_Type val) {
    if (from >= right || left >= to) {
      return;
    }
    if (left == from && right == to) {
      node->val_ = val;
      node->has_changed_ = true;
    } else {
      push(node);
      size_t mid = (left + right) / 2;
      setRecursive(node->left_.get(), left, mid, from, std::min(to, mid), val);
      setRecursive(node->right_.get(), mid, right, std::max(from, mid), to, val);
      node->val_ = func_(getData(node->left_.get(), left, mid),
                         getData(node->right_.get(), mid, right));
    }
  }

  const T_Type getRecursive(nodePtr_ node, size_t left, size_t right, size_t from,
                            size_t to) {
    if (from >= right || left >= to) {
      return default_val_;
    }
    if (left == from && right == to) {
      return getData(node, left, right);
    } else {
      push(node);
      size_t mid = (left + right) / 2;
      T_Type left_ans = getRecursive(node->left_.get(), left, mid, from, std::min(to, mid));
      T_Type right_ans = getRecursive(node->right_.get(), mid, right, std::max(from, mid),
                                      to);
      node->val_ = func_(getData(node->left_.get(), left, mid),
                         getData(node->right_.get(), mid, right));
      return func_(left_ans, right_ans);
    }
  }

public:
  LazySegmentTree(const vector<T_Type> &data, T_Type default_val = T_Type(0), Function func = Function(),
                  Multiple_Function multiple_func = Multiple_Function()) :
      root_(make_unique<TreeNode>(default_val)), real_size_(data.size()),
      default_val_(default_val), func_(func), multiple_func_(multiple_func) {
    for (size_t i = 0; i < real_size_; ++i) {
      set(i, data[i]);
    }
  }

  void set(size_t left, size_t right, T_Type val) {
    setRecursive(root_.get(), 0, real_size_, left, right, val);
  }

  void set(size_t pos, T_Type val) {
    set(pos, pos + 1, val);
  }

  const T_Type get(size_t left, size_t right) {
    return getRecursive(root_.get(), 0, real_size_, left, right);
  }

  const T_Type get(size_t pos) {
    return get(pos, pos + 1);
  }

  const T_Type get() {
    return get(0, real_size_);
  }

  size_t size() const {
    return real_size_;
  }
};

template<typename T_Type, typename Function, typename MultipleFunction>
class SegmentTree {
private:
  vector<T_Type> data_;
  vb_ has_changed_;
  size_t real_size_;
  Function func_;
  MultipleFunction multiple_func_;
  T_Type default_val_;

  void push(size_t vertex) {
    if (has_changed_[vertex]) {
      data_[2 * vertex + 1] = data_[2 * vertex + 2] = data_[vertex];
      has_changed_[2 * vertex + 1] = has_changed_[2 * vertex + 2] = true;
      has_changed_[vertex] = false;
    }
  }

  T_Type getData(size_t vertex, size_t left, size_t right) const {
    if (has_changed_[vertex]) {
      return multiple_func_(data_[vertex], right - left);
    } else {
      return data_[vertex];
    }
  }

  

  

  void setRecursive(size_t vertex, size_t left, size_t right,
                    size_t from, size_t to, T_Type val) {
    if (from >= right || left >= to) {
      return;
    }
    if (left == from && right == to) {
      data_[vertex] = val;
      has_changed_[vertex] = true;
    } else {
      push(vertex);
      size_t mid = (left + right) / 2;
      setRecursive(2 * vertex + 1, left, mid,
                   from, std::min(to, mid), val);
      setRecursive(2 * vertex + 2, mid, right,
                   std::max(from, mid), to, val);
      data_[vertex] = func_(
          getData(2 * vertex + 1, left, mid),
          getData(2 * vertex + 2, mid, right)
      );
    }
  }

  T_Type getRecursive(size_t vertex, size_t left, size_t right,
                      size_t from, size_t to) {
    if (from >= right || left >= to) {
      return default_val_;
    }
    if (left == from && right == to) {
      return getData(vertex, left, right);
    } else {
      push(vertex);
      size_t mid = (left + right) / 2;
      T_Type left_ans = getRecursive(2 * vertex + 1, left, mid,
                                     from, std::min(to, mid));
      T_Type right_ans = getRecursive(2 * vertex + 2, mid, right,
                                      std::max(from, mid), to);
      data_[vertex] = func_(
          getData(2 * vertex + 1, left, mid),
          getData(2 * vertex + 2, mid, right)
      );
      return func_(left_ans, right_ans);
    }
  }

  void buildRecursive(size_t vertex, size_t left, size_t right,
                      const vector<T_Type> &data) {
    if (left + 1 == right) {
      data_[vertex] = data[left];
    } else {
      size_t mid = (left + right) / 2;
      buildRecursive(2 * vertex + 1, left, mid, data);
      buildRecursive(2 * vertex + 2, mid, right, data);
      data_[vertex] = func_(data_[2 * vertex + 1],
                            data_[2 * vertex + 2]
      );
    }
  }

public:
  SegmentTree(const vector<T_Type> &data, Function func = Function(),
              MultipleFunction multiple_func = MultipleFunction(),
              T_Type default_val = T_Type(0))
      : data_(), has_changed_(), real_size_(data.size()), func_(func), multiple_func_(multiple_func),
        default_val_(default_val) {
    size_t good_size = 1;
    while (good_size < 2 * real_size_) {
      good_size <<= 1;
    }
    data_.resize(good_size, default_val_);
    has_changed_.resize(good_size, false);

    buildRecursive(0, 0, real_size_, data);
  }

  void set(size_t left, size_t right, T_Type val) {
    setRecursive(0, 0, real_size_, left, right, val);
  }

  void set(size_t pos, T_Type val) {
    set(pos, pos + 1, val);
  }

  const T_Type get(size_t left, size_t right) {
    return getRecursive(0, 0, real_size_, left, right);
  }

  const T_Type get(size_t pos) {
    return get(pos, pos + 1);
  }

  const T_Type get() {
    return get(0, real_size_);
  }

  size_t size() const {
    return real_size_;
  }
};

namespace geometry {
  using ld_ = long double;
  const ld_ EPS_ = 1e-7;
  using namespace std::rel_ops;

  class Point {
  private:
    ld_ first_;
    ld_ second_;

  public:
    constexpr Point(ld_ first = 0.0, ld_ second = 0.0) : first_(first), second_(second) {
    }

    friend Point &operator+=(Point &lhs, const Point &rhs) {
      lhs.first_ += rhs.first_;
      lhs.second_ += rhs.second_;
      return lhs;
    }

    friend Point operator+(Point lhs, const Point &rhs) {
      lhs += rhs;
      return lhs;
    }

    friend Point &operator-=(Point &lhs, const Point &rhs) {
      lhs.first_ -= rhs.first_;
      lhs.second_ -= rhs.second_;
      return lhs;
    }

    friend Point operator-(Point lhs, const Point &rhs) {
      lhs -= rhs;
      return lhs;
    }

    ld_ length() const {
      return sqrtl(first_ * first_ + second_ * second_);
    }

    friend ld_ distance(const Point &lhs, const Point &rhs) {
      return (rhs - lhs).length();
    }

    friend ld_ scalar(const Point &lhs, const Point &rhs) {
      return lhs.first_ * rhs.first_ + lhs.second_ * rhs.second_;
    }

    friend ld_ oriented_square(const Point &lhs, const Point &rhs) {
      return (lhs.first_ * rhs.second_ - rhs.first_ * lhs.second_) / 2.0;
    }

    friend ld_ square(const Point &lhs, const Point &rhs) {
      return std::abs(oriented_square(lhs, rhs));
    }

    friend ld_ oriented_square(const Point &first, const Point &second,
                               const Point &third) {
      return oriented_square(second - first, third - first);
    }

    friend ld_ square(const Point &first, const Point &second, const Point &third) {
      return square(second - first, third - first);
    }

    friend ld_ angle(const Point &lhs, const Point &rhs) {
      return acosl(scalar(lhs, rhs) / lhs.length() / rhs.length());
    }

    

    bool operator==(const Point &rhs) const {
      return std::abs(first_ - rhs.first_) < EPS_ &&
             std::abs(second_ - rhs.second_) < EPS_;
    }

    friend bool operator<(const Point &lhs, const Point &rhs) {
      return (lhs.first_ - rhs.first_ < -EPS_) ||
             (lhs.first_ - rhs.first_ < EPS_ && lhs.second_ < rhs.second_ - EPS_);
    }

    constexpr ld_ get_first() const {
      return first_;
    }

    constexpr ld_ get_second() const {
      return second_;
    }

    friend istream &operator>>(istream &input, Point &pt) {
      input >> pt.first_ >> pt.second_;
      return input;
    }

    friend ostream &operator<<(ostream &output, const Point &pt) {
      output << pt.first_ << " " << pt.second_;
      return output;
    }
  };

  class Line {
  private:
    ld_ first_;
    ld_ second_;
    ld_ free_;

    void normalize() {
      ld_ norm = sqrtl(first_ * first_ + second_ * second_);
      if (first_ < -EPS_) {
        norm = -norm;
      } else if (first_ < EPS_) {
        norm = second_;
      }
      first_ /= norm;
      second_ /= norm;
      free_ /= norm;
    }

  public:
    Line(ld_ first, ld_ second, ld_ free) : first_(first), second_(second), free_(free) {
      normalize();
    }

    ld_ operator()(const Point &pt) const {
      return first_ * pt.get_first() + second_ * pt.get_second() + free_;
    }

    friend bool parallel(const Line &lhs, const Line &rhs) {
      return std::abs(lhs.first_ - rhs.first_) < EPS_ &&
             std::abs(lhs.second_ - rhs.second_) < EPS_;
    }

    friend bool operator==(const Line &lhs, const Line &rhs) {
      return std::abs(lhs.first_ - rhs.first_) < EPS_ &&
             std::abs(lhs.second_ - rhs.second_) < EPS_ &&
             std::abs(lhs.free_ - rhs.free_) < EPS_;
    }

    friend istream &operator>>(istream &input, Line &ln) {
      input >> ln.first_ >> ln.second_ >> ln.free_;
      return input;
    }

    friend ostream &operator<<(ostream &output, const Line &ln) {
      output << ln.first_ << " " << ln.second_ << ln.free_;
      return output;
    }
  };

  

  class Segment {
  private:
    Point first_;
    Point second_;

  public:
    Segment(const Point &first, const Point &second) : first_(first), second_(second) {
    }

    ld_ length() const {
      return distance(first_, second_);
    }

    friend bool operator==(const Segment &lhs, const Segment &rhs) {
      return lhs.first_ == rhs.first_ && lhs.second_ == rhs.second_;
      

      

      

      

    }

    friend bool operator<(const Segment &lhs, const Segment &rhs) {
      return std::make_pair(lhs.first_, lhs.second_) <
             std::make_pair(rhs.first_, rhs.second_);
    }

    Line make_line() const {
      Point difference = first_ - second_;
      ld_ coefficient_first = difference.get_second();
      ld_ coefficient_second = -difference.get_first();
      ld_ coefficient_free = 0.0 - coefficient_first * first_.get_first() -
                             coefficient_second * first_.get_second();
      return Line(coefficient_first, coefficient_second, coefficient_free);
    }

    Point get_first() const {
      return first_;
    }

    Point get_second() const {
      return second_;
    }

    friend istream &operator>>(istream &input, Segment &sgm) {
      input >> sgm.first_ >> sgm.second_;
      return input;
    }

    friend ostream &operator<<(ostream &output, const Segment &sgm) {
      output << sgm.first_ << " " << sgm.second_;
      return output;
    }
  };

  ld_ DistanceFromPointToLine(const Point &pt, const Line &line) {
    return std::abs(line(pt));
  }

  ld_ DistanceFromPointToSegment(const Point &pt, const Segment &sgm) {
    Point first = sgm.get_first();
    Point second = sgm.get_second();
    if (scalar(second - first, pt - first) > EPS_ &&
        scalar(first - second, pt - second) > EPS_) {
      return DistanceFromPointToLine(pt, sgm.make_line());
    } else {
      return std::min(distance(first, pt), distance(second, pt));
    }
  }

  class Triangle {
  private:
    Point first_;
    Point second_;
    Point third_;

  public:
    Triangle(const Point &first, const Point &second, const Point &third) : first_(first), second_(second),
                                                                            third_(third) {
    }

    friend ld_ square(const Triangle &lhs) {
      return square(lhs.first_, lhs.second_, lhs.third_);
    }

    friend ld_ oriented_square(const Triangle &lhs) {
      return oriented_square(lhs.first_, lhs.second_, lhs.third_);
    }

    friend istream &operator>>(istream &input, Triangle &tri) {
      input >> tri.first_ >> tri.second_ >> tri.third_;
      return input;
    }

    friend ostream &operator<<(ostream &output, const Triangle &tri) {
      output << tri.first_ << " " << tri.second_ << " " << tri.third_;
      return output;
    }
  };

  class Polygon {
  private:
    vector<Point> points_;

  public:
    explicit Polygon(const vector<Point> &points = vector<Point>(0)) : points_(points) {
    }

    size_t size() const {
      return points_.size();
    }

    bool empty() const {
      return points_.empty();
    }

    ld_ perimeter() {
      if (empty()) {
        return 0.0;
      }
      ld_ ans = distance(points_[0], points_.back());
      for (size_t i = 0; i + 1 < size(); ++i) {
        ans += distance(points_[i], points_[i + 1]);
      }
      return ans;
    }

    friend ld_ square(const Polygon &lhs) {
      if (lhs.size() < 3) {
        return 0.0;
      }
      ld_ ans = 0.0;
      for (size_t i = 2; i < lhs.size(); ++i) {
        ans += square(lhs.points_[0], lhs.points_[1], lhs.points_[i]);
      }
      return ans;
    }

    vs_ convex() const {
      if (empty()) {
        return vs_(0);
      }
      size_t min_pt = static_cast<size_t>(std::min_element(points_.begin(), points_.end()) - points_.begin());
      vs_ indexes(size());
      std::iota(indexes.begin(), indexes.end(), 0);
      std::sort(indexes.begin(), indexes.end(), [&](const size_t &lhs, const size_t &rhs) {
        ld_ sq = oriented_square(points_[min_pt], points_[lhs], points_[rhs]);
        return (sq > EPS_) || (sq >= -EPS_ && distance(points_[min_pt], points_[lhs]) <
                                              distance(points_[min_pt], points_[rhs]));
      });
      vs_ ans {min_pt};
      for (const auto &point_num: indexes) {
        while (ans.size() > 1 &&
               oriented_square(points_[ans.rbegin()[1]], points_[ans.rbegin()[0]],
                               points_[point_num]) < EPS_) {
          ans.pop_back();
        }
        if (points_[ans.back()] != points_[point_num]) {
          ans.push_back(point_num);
        }
      }
      return ans;
    }

    Polygon convex_polygon() const {
      vs_ indexes = convex();
      vector<Point> convex_points;
      convex_points.reserve(indexes.size());
      for (const auto &index: indexes) {
        convex_points.push_back(points_[index]);
      }
      return Polygon(convex_points);
    }

    friend istream &operator>>(istream &input, Polygon &poly) {
      poly.points_ = InputVector<Point>(-1, input);
      return input;
    }

    friend ostream &operator<<(ostream &output, const Polygon &poly) {
      OutputContainer(poly.points_, false, false, output);
      return output;
    }
  };
} 





class HashNum {
private:
  using ll_ = long long;

  void normalize() {
    a_ = (a_ % MA + MA) % MA;
    b_ = (b_ % MB + MB) % MB;
  }

public:
  int a_, b_;
  static const int MA = 1000000007, MB = 1000000009;

  HashNum(int num = 0) : a_(num), b_(num) {
    normalize();
  }

  HashNum(int first, int second) : a_(first), b_(second) {
    normalize();
  }

  friend HashNum &operator+=(HashNum &lhs, const HashNum &rhs) {
    lhs.a_ += rhs.a_;
    lhs.b_ += rhs.b_;
    lhs.normalize();
    return lhs;
  }

  friend HashNum operator+(HashNum lhs, const HashNum &rhs) {
    lhs += rhs;
    return lhs;
  }

  friend HashNum &operator-=(HashNum &lhs, const HashNum &rhs) {
    lhs.a_ -= rhs.a_;
    lhs.b_ -= rhs.b_;
    lhs.normalize();
    return lhs;
  }

  friend HashNum operator-(HashNum lhs, const HashNum &rhs) {
    lhs -= rhs;
    return lhs;
  }

  friend HashNum &operator*=(HashNum &lhs, const HashNum &rhs) {
    lhs.a_ = static_cast<int>((static_cast<ll_> (lhs.a_) * rhs.a_) % MA);
    lhs.b_ = static_cast<int>((static_cast<ll_> (lhs.b_) * rhs.b_) % MB);
    return lhs;
  }

  friend HashNum operator*(HashNum lhs, const HashNum &rhs) {
    lhs *= rhs;
    return lhs;
  }

  friend bool operator==(const HashNum &lhs, const HashNum &rhs) {
    return lhs.a_ == rhs.a_ && lhs.b_ == rhs.b_;
  }

  friend bool operator<(const HashNum &lhs, const HashNum &rhs) {
    return std::make_pair(lhs.a_, lhs.b_) < std::make_pair(rhs.a_, rhs.b_);
  }

  explicit operator ll_() const {
    return static_cast<ll_> (a_) * MB + b_ + 1;
  }

  friend ostream &operator<<(ostream &output, const HashNum &hash) {
    output << hash.a_ << " " << hash.b_;
    return output;
  }
};










template<class Hash_Type>
class StrComparator {
private:
  static const int VAR_;
  static vector<Hash_Type> deg_;
  string text_;
  vector<Hash_Type> hash_;

public:
  explicit StrComparator(const string &text) : text_(text), hash_ {Hash_Type(0)} {
    hash_.reserve(text_.size() + 1);
    for (const auto &symbol: text_) {
      hash_.push_back(hash_.back() * VAR_ + Hash_Type(symbol));
    }
    deg_.reserve(text_.size() + 2);
    while (deg_.size() <= text_.size()) {
      deg_.push_back(deg_.back() * VAR_);
    }
  }

  Hash_Type substr(size_t pos, size_t len) const {
    return hash_[pos + len] - hash_[pos] * deg_[len];
  }

  size_t size() const {
    return text_.size();
  }

  size_t lcp(size_t lhs, size_t rhs) const {
    size_t left = 0, right = text_.size() - std::max(lhs, rhs);
    while (left < right) {
      size_t mid = (left + right + 1) / 2;
      if (substr(lhs, mid) == substr(rhs, mid)) {
        left = mid;
      } else {
        right = mid - 1;
      }
    }
    return left;
  }

  bool cmp(size_t lhs, size_t rhs) const {
    size_t len = text_.size() - std::max(lhs, rhs);
    size_t lcp_length = lcp(lhs, rhs);
    return lcp_length < len
           ? text_[lhs + lcp_length] < text_[rhs + lcp_length]
           : rhs < lhs;
  }

  Hash_Type operator()() const {
    return substr(0, size());
  }
};

template<class Hash_Type> vector<Hash_Type>
    StrComparator<Hash_Type>::deg_ {Hash_Type(1)};
template<class Hash_Type> const int
    StrComparator<Hash_Type>::VAR_ = std::max(239, rand());

template<class Hash_Type>
vs_ SuffixArray(const StrComparator<Hash_Type> &hash) {
  vs_ suffix_array(hash.size());
  std::iota(suffix_array.begin(), suffix_array.end(), 0);
  std::sort(suffix_array.begin(), suffix_array.end(), [&](size_t lhs, size_t rhs) {
    return hash.cmp(lhs, rhs);
  });
  return suffix_array;
}

vs_ SuffixArray(const string &text) {
  return SuffixArray(StrComparator<HashNum>(text));
}

string LowerString(string text) {
  std::transform(text.begin(), text.end(), text.begin(), ::tolower);
  return text;
}

string UpperString(string text) {
  std::transform(text.begin(), text.end(), text.begin(), ::toupper);
  return text;
}

string ReverseString(string text) {
  std::reverse(text.begin(), text.end());
  return text;
}

vi_ TextAsSumOfSamples(const string &text, const vector<string> &samples) {
  std::unordered_map<long long, size_t> samples_hashes;
  size_t max_length = 0;
  for (size_t i = 0; i < samples.size(); ++i) {
    auto hash = StrComparator<HashNum>(samples[i]);
    samples_hashes[static_cast<long long>(hash())] = i;
    max_length = std::max(max_length, samples[i].size());
  }
  auto text_hash = StrComparator<HashNum>(text);
  vi_ prev(text.size(), -1);
  for (size_t current_pos = 0; current_pos < text.size(); ++current_pos) {
    for (int j = std::max(static_cast<int> (current_pos) - static_cast<int> (max_length), 0) - 1;
         j < static_cast<int> (current_pos); ++j) {
      if (j == -1 || prev[static_cast<size_t> (j)] != -1) {
        auto it = samples_hashes.find(static_cast<long long>(text_hash.substr(static_cast<size_t> (j + 1),
                                                                              current_pos -  static_cast<size_t> (j))));
        if (it != samples_hashes.end()) {
          prev[current_pos] = static_cast<int> (it->second);
          break;
        }
      }
    }
  }
  return prev;
}



class FenwickTree {
public:
  

  using Index = int;

  explicit FenwickTree(size_t size) : sums_(size, 0) {}

  

  void initialize(vi_ numbers) {
    

    std::partial_sum(numbers.begin(), numbers.end(), numbers.begin());
    sums_.reserve(numbers.size());
    for (Index i = 0; i < size(); ++i) {
      sums_.push_back(numbers[static_cast<size_t> (i)]);
      Index previousI = previousIndex(i);
      if (previousI > 0) {
        sums_[static_cast<size_t> (i)] -= numbers[static_cast<size_t> (previousI - 1)];
      }
    }
  }

  void add(Index index, int value) {
    while (index < size()) {
      sums_[static_cast<size_t> (index)] += value;
      index |= (index + 1);
    }
  }

  int sum(Index firstIndex, Index lastIndex) const {
    return sum(lastIndex) - sum(firstIndex - 1);
  }

  int at(Index index) const {
    return sum(index, index);
  }

  Index size() const {
    return static_cast<Index>(sums_.size());
  }

private:
  int sum(Index lastIndex) const {
    return lastIndex >= 0
           ? sums_[static_cast<size_t> (lastIndex)] + sum(previousIndex(lastIndex) - 1)
           : 0;
  }

  

  

  static Index previousIndex(Index index) {
    return index & (index + 1);
  }

  vi_ sums_;
};

vs_ PrefixFunction(const string &text) {
  vs_ ans {0};
  ans.reserve(text.size());
  for (size_t index = 1; index < ans.size(); ++index) {
    auto cur = ans.back();
    while (cur > 0 && text[index] != text[cur]) {
      cur = ans[cur - 1];
    }
    ans.push_back(cur + (text[index] == text[cur]));
  }
  return ans;
}

vs_ ZFunction(const string &text) {
  vs_ ans {text.size()};
  ans.reserve(text.size());
  size_t left = 0;
  size_t right = 0;

  for (size_t index = 1; index < ans.size(); ++index) {
    size_t checked = 0;
    if (index <= right) {
      checked = std::min(ans[index - left], right - index + 1);
    }
    while (index + checked < text.size() && text[index + checked] == text[checked]) {
      ++checked;
    }
    ans.push_back(checked);
    if (index + ans.back() - 1 >= right) {
      left = index;
      right = index + ans.back() - 1;
    }
  }
  return ans;
}





vs_ PrimeDividers(size_t num) {
  vs_ ans;
  for (size_t i = 2; i * i <= num; ++i) {
    if (num % i == 0) {
      ans.push_back(i);
      while (num % i == 0) {
        num /= i;
      }
    }
  }
  if (num > 1) {
    ans.push_back(num);
  }
  return ans;
}



vs_ Dividers(size_t num) {
  vs_ ans;
  for (size_t i = 1; i * i <= num; ++i) {
    if (num % i == 0) {
      ans.push_back(i);
      if (i * i != num) {
        ans.push_back(num / i);
      }
    }
  }
  std::sort(ans.begin(), ans.end());
  return ans;
}

bool IsPeriodic(const string &text, size_t check) {
  for (size_t index = check; index < text.size(); ++index) {
    if (text[index] != text[index - check]) {
      return false;
    }
  }
  return true;
}

size_t MinPeriod(const string &text) {
  auto dividers = Dividers(text.size());
  for (const auto &divider: dividers) {
    if (IsPeriodic(text, divider)) {
      return divider;
    }
  }
  

  return text.size();
}

class Graph {
private:
  using ll_ = long long;

  vvs_ outgoing_edges_;
  vvs_ level_graph_edges_;
  vvs_ capacity_matrix_;
  vector<pair<size_t *, size_t>> buffer_changes_;

  static constexpr ll_ LONGINF_ {std::numeric_limits<ll_>::max()};
  static constexpr size_t INF_ {std::numeric_limits<size_t>::max()};

  bool buildLevelGraph(size_t source, size_t target, size_t min_capacity) {
    vs_ source_distance(size(), INF_);
    source_distance[source] = 0;
    std::queue<size_t> bfs_queue;
    bfs_queue.push(source);
    while (!bfs_queue.empty()) {
      auto from = bfs_queue.front();
      for (const auto &to : outgoing_edges_[from]) {
        if (source_distance[to] == INF_ && capacity_matrix_[from][to] >= min_capacity) {
          source_distance[to] = source_distance[from] + 1;
          bfs_queue.push(to);
        }
      }
      bfs_queue.pop();
    }
    if (source_distance[target] == INF_) {
      return false;
    }
    for (size_t from = 0; from < size(); ++from) {
      level_graph_edges_[from].clear();
      for (const auto &to : outgoing_edges_[from]) {
        if (source_distance[from] + 1 == source_distance[to] &&
            capacity_matrix_[from][to] >= min_capacity) {
          level_graph_edges_[from].push_back(to);
        }
      }
    }
    return true;
  }

  ll_ findBlockingFlow(size_t vertex, size_t target, ll_ flow) {
    if (vertex == target) {
      return flow;
    }
    ll_ total_flow = 0;
    while (!level_graph_edges_[vertex].empty()) {
      auto to = level_graph_edges_[vertex].back();
      ll_ push = findBlockingFlow(
          to, target,
          std::min(flow, static_cast<ll_>(capacity_matrix_[vertex][to]))
      );
      if (push > 0) {
        total_flow += push;
        flow -= push;
        capacity_matrix_[vertex][to] -= static_cast<size_t> (push);
        buffer_changes_.emplace_back(&capacity_matrix_[to][vertex], push);
      }
      if (flow == 0) {
        return total_flow;
      } else {
        level_graph_edges_[vertex].pop_back();
      }
    }
    return total_flow;
  }

  ll_ dinicIteration(size_t source, size_t target, size_t min_capacity) {
    ll_ ans = 0;
    while (buildLevelGraph(source, target, min_capacity)) {
      ans += findBlockingFlow(source, target, LONGINF_);
      while (!buffer_changes_.empty()) {
        size_t *destination;
        size_t delta;
        std::tie(destination, delta) = buffer_changes_.back();
        *destination += delta;
        buffer_changes_.pop_back();
      }
    }
    return ans;
  }

public:
  explicit Graph(size_t num = 0) : outgoing_edges_(num), level_graph_edges_(0), capacity_matrix_(0),
                                   buffer_changes_(0) {
  }

  void initCapacityMatrix() {
    capacity_matrix_.assign(size(), vs_(size(), 0));
  }

  size_t size() const {
    return outgoing_edges_.size();
  }

  void addEdge(size_t from, size_t to, size_t capacity) {
    outgoing_edges_[from].push_back(to);
    capacity_matrix_[from][to] = capacity;
  }

  void addEdge(size_t from, size_t to) {
    outgoing_edges_[from].push_back(to);
  }

  size_t degree(size_t vertex) const {
    return outgoing_edges_[vertex].size();
  }

  const vs_ &getAdjacentVertices(size_t vertex) const {
    return outgoing_edges_[vertex];
  }

  ll_ findMaxFlow(size_t source, size_t target, bool scaling) {
    level_graph_edges_.assign(size(), vs_(0));
    ll_ ans = 0;
    if (scaling) {
      size_t max_capacity = 0;
      for (size_t from = 0; from < size(); ++from) {
        max_capacity = std::max(max_capacity, *std::max_element(capacity_matrix_[from].begin(),
                                                                capacity_matrix_[from].end()));
      }
      size_t push_capacity = 1;
      while (push_capacity <= max_capacity) {
        push_capacity <<= 1;
      }
      while (push_capacity > 1) {
        push_capacity >>= 1;
        ans += dinicIteration(source, target, push_capacity);
      }
    } else {
      ans = dinicIteration(source, target, 1);
    }
    level_graph_edges_.clear();
    return ans;
  }
};

Graph ReadGraph(istream &input = cin) {
  size_t vertices_num, edges_num;
  input >> vertices_num >> edges_num;
  Graph ans(vertices_num);
  ans.initCapacityMatrix();
  for (size_t i = 0; i < edges_num; ++i) {
    size_t first, second, capacity;
    input >> first >> second >> capacity;
    --first;
    --second;
    ans.addEdge(second, first, capacity);
    ans.addEdge(first, second, capacity);
  }
  return ans;
}



Graph ReverseEdges(const Graph &graph) {
  Graph ans(graph.size());
  for (size_t from = 0; from < graph.size(); ++from) {
    for (const auto &to : graph.getAdjacentVertices(from)) {
      ans.addEdge(to, from);
    }
  }
  return ans;
}





template<class AnyGraph, class Callback>
void DFS(const AnyGraph &graph, size_t vertex, vb_ &visited_vertices,
         Callback&& call_on_exit) {
  visited_vertices[vertex] = true;
  for (const auto &to : graph.getAdjacentVertices(vertex)) {
    if (!visited_vertices[to]) {
      DFS(graph, to, visited_vertices, call_on_exit);
    }
  }
  call_on_exit(vertex);
}





template<class AnyGraph, class Callback>
vi_ BFS(const AnyGraph &graph, size_t start_vertex, Callback&& call_on_add) {
  vi_ rank(graph.size(), -1);
  rank[start_vertex] = 0;
  std::queue<size_t> vertices_queue;
  while (!vertices_queue.empty()) {
    auto vertex = vertices_queue.front();
    vertices_queue.pop();
    for (const auto &to : graph.getAdjacentVertices(vertex)) {
      if (rank[to] != -1) {
        rank[to] = rank[vertex] + 1;
        vertices_queue.push(to);
        call_on_add(to);
      }
    }
  }
  return rank;
}

template<class AnyGraph, class Vertex>
vi_ BFS(const AnyGraph &graph, const Vertex &start_vertex) {
  

  return BFS(graph, start_vertex, [](size_t cur_vertex) {
  });
}

bool isConnected(const Graph &graph) {
  vb_ visited_vertices(graph.size(), false);
  std::stack<size_t> vertices_sorted_by_finish;
  DFS(graph, 0, visited_vertices, [&](size_t cur_vertex) {
    vertices_sorted_by_finish.push(cur_vertex);
  });
  return vertices_sorted_by_finish.size() == graph.size();
}



pair<Graph, vs_> FindCondensation(const Graph &graph) {
  vb_ visited_vertices(graph.size(), false);
  std::stack<size_t> vertices_sorted_by_finish;
  for (size_t i = 0; i < graph.size(); ++i) {
    if (!visited_vertices[i]) {
      DFS(graph, i, visited_vertices, [&](size_t cur_vertex) {
        vertices_sorted_by_finish.push(cur_vertex);
      });
    }
  }

  std::fill(visited_vertices.begin(), visited_vertices.end(), false);
  Graph reoriented_graph = ReverseEdges(graph);
  size_t components_num = 0;
  vs_ equals_num;
  vs_ equality_class(graph.size());
  while (!vertices_sorted_by_finish.empty()) {
    auto vertex = vertices_sorted_by_finish.top();
    vertices_sorted_by_finish.pop();
    if (!visited_vertices[vertex]) {
      equals_num.push_back(0);
      DFS(reoriented_graph, vertex, visited_vertices, [&](size_t cur_vertex) {
        equality_class[cur_vertex] = components_num;
        ++equals_num[components_num];
      });
      ++components_num;
    }
  }

  Graph ans(components_num);
  for (size_t from = 0; from < graph.size(); ++from) {
    for (size_t to : graph.getAdjacentVertices(from)) {
      if (equality_class[from] != equality_class[to]) {
        ans.addEdge(equality_class[from], equality_class[to]);
      }
    }
  }
  return std::make_pair(ans, equals_num);
}




void checkSegmentTree() {
  constexpr size_t NUM26 = 26;
  size_t length;
  int queries;
  string text;
  cin >> length >> queries >> text;
  vvs_ letters_pos(NUM26, vs_(length, 0));
  for (size_t i = 0; i < length; ++i) {
    letters_pos[static_cast<size_t> (text[i] - 'a')][i] = 1;
  }

  vector<SegmentTree<size_t, std::plus<size_t>, std::multiplies<size_t>>> trees;
  for (const auto &vec: letters_pos) {
    trees.emplace_back(vec);
  }

  while (queries--) {
    size_t left, right, type;
    cin >> left >> right >> type;
    --left;
    vs_ letters_count;
    letters_count.reserve(NUM26);
    for (auto &tree: trees) {
      letters_count.push_back(tree.get(left, right));
      tree.set(left, right, 0);
    }
    if (type) {
      for (size_t j = 0; j < NUM26; ++j) {
        trees[j].set(left, left + letters_count[j], 1);
        left += letters_count[j];
      }
    } else {
      for (size_t j = 0; j < NUM26; ++j) {
        trees.rbegin()[static_cast<int> (j)].set(left, left + letters_count.rbegin()[static_cast<int> (j)], 1);
        left += letters_count.rbegin()[static_cast<int> (j)];
      }
    }
  }

  for (size_t i = 0; i < NUM26; ++i) {
    for (size_t j = 0; j < length; ++j) {
      if (trees[i].get(j) == 1) {
        text[j] = static_cast<char> ('a' + i);
      }
    }
  }
  cout << text << "\n";
}

struct Query {
  size_t left;
  size_t right;
};

using Queries = vector<Query>;

vs_ MoSort(Queries queries, size_t max_size) {
  vs_ ans(queries.size());
  std::iota(ans.begin(), ans.end(), 0);
  size_t size_square_root = static_cast<size_t> (std::lround(sqrt(static_cast<double> (max_size))));
  std::sort(ans.begin(), ans.end(), [&] (size_t lhs, size_t rhs) {
    if (queries[lhs].left / size_square_root != queries[rhs].left / size_square_root) {
      return queries[lhs].left < queries[rhs].left;
    } else {
      return queries[lhs].right < queries[rhs].right;
    }
  });
  return ans;
}

void MoAdd(std::unordered_multiset<int>& status, const vi_& arr, size_t pos) {
  status.insert(arr[pos]);
}

void MoDelete(std::unordered_multiset<int>& status, const vi_& arr, size_t pos) {
  status.erase(status.find(arr[pos]));
}

void MoProcess(Queries queries, vi_& arr) {
  size_t prev_left = 0, prev_right = 0;
  std::unordered_multiset<int> status;

  for (const auto& query: queries) {
    auto left = query.left;
    auto right = query.right;

    while (prev_left < left) {
      MoDelete(status, arr, prev_left++);
    }
    while (prev_left > left) {
      MoAdd(status, arr, --prev_left);
    }

    while (prev_right < right) {
      MoAdd(status, arr, prev_right++);
    }
    while (prev_right > right) {
      MoDelete(status, arr, --prev_right);
    }
  }
}

void solve();

int main() {
  std::ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << std::fixed << std::setprecision(7);

  int test_num = 1;
  

  while (test_num--) {
    solve();
  }

  return 0;
}

void solve() {
  checkSegmentTree();
}
