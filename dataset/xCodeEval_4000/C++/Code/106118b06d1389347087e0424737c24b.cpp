#include <string>
#include <stack>
#include <vector>
#include <cstdio>
#include <functional>
#include <iomanip>
#include <cmath>
#include <iostream>
#include <random>
#include <complex>
#include <list>
#include <utility>
#include <limits>
#include <queue>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <memory>

typedef std::vector<int> vi_;
typedef std::vector<size_t> vs_;
typedef std::vector<vi_> vvi_;
typedef std::vector<vs_> vvs_;

template<class Hashable_Type>
inline void hash_combine(size_t &seed, const Hashable_Type &v) {
    static std::hash<Hashable_Type> hash;
    seed ^= hash(v) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
}

namespace std {
    template<class Hashable_First_Type, class Hashable_Second_Type>
    struct hash<std::pair<Hashable_First_Type, Hashable_Second_Type>> {
        inline size_t operator()(
                const std::pair<Hashable_First_Type, Hashable_Second_Type> &pr) const {
            size_t seed = 0;
            ::hash_combine(seed, pr.first);
            ::hash_combine(seed, pr.second);
            return seed;
        }
    };
} 




int CorrectBrackets(const std::string &text) {
    std::stack<size_t> stack;
    for (size_t symbol_index = 0; symbol_index < text.size(); ++symbol_index) {
        auto bracket = text[symbol_index];
        if (bracket == '(' || bracket == '[' || bracket == '{') {
            stack.push(symbol_index);
        } else {
            if (stack.empty()) {
                return static_cast<int> (symbol_index);
            }
            size_t last = stack.top();
            stack.pop();
            if ((bracket == ')' && text[last] != '(') || (bracket == ']' && text[last] != '[') ||
                (bracket == '}' && text[last] != '{')) {
                return static_cast<int> (symbol_index);
            }
        }
    }
    return !stack.empty()
           ? static_cast<int> (text.size())
           : -1;
}

template<typename T_Type, typename Function>
class SparseTable {
private:
    static vs_ log_;
    std::vector<std::vector<T_Type>> sparse_;
    Function func_;

public:
    SparseTable(const std::vector<T_Type> &mass, Function func = Function()) : sparse_(), func_(func) {
        size_t len = mass.size();
        size_t add = log_.back() + 1;
        while (static_cast<size_t> (1 << add) <= len) {
            log_.insert(log_.end(), static_cast<size_t> (1 << add), add);
            ++add;
        }
        sparse_.resize(log_[len] + 1);
        for (size_t pow = 0; pow <= log_[len]; ++pow) {
            sparse_[pow].reserve(len);
            for (size_t j = 0; j < len; ++j) {
                if (pow == 0) {
                    sparse_[pow].emplace_back(func_(mass[j], mass[j]));
                } else {
                    sparse_[pow].emplace_back(func_(sparse_[pow - 1][j],
                                                    sparse_[pow - 1][std::min(j + (1 << (pow - 1)),
                                                                              len - 1)]));
                }
            }
        }
    }

    inline T_Type get(size_t left, size_t right) const {
        return func_(sparse_[log_[right - left]][left],
                     sparse_[log_[right - left]][right - (1 << log_[right - left])]);
    }
};

template<typename T_Type, typename Function> vs_
        SparseTable<T_Type, Function>::log_ {0, 0, 1, 1};



template<typename T_Type>
size_t CommonSubsequence(const std::vector<T_Type> &first_arr,
                         const std::vector<T_Type> &second_arr) {
    vs_ ans {static_cast<size_t> (first_arr[0] == second_arr[0])};
    ans.reserve(second_arr.size());
    for (size_t j = 1; j < second_arr.size(); ++j) {
        ans.push_back(ans.back());
        if (first_arr[0] == second_arr[j]) {
            ++ans.back();
        }
    }

    for (size_t first_pos = 1; first_pos < first_arr.size(); ++first_pos) {
        vs_ prev(ans);
        ans[0] = prev[0];
        if (first_arr[first_pos] == second_arr[0]) {
            ans[0] = 1;
        }
        for (size_t second_pos = 1; second_pos < second_arr.size(); ++second_pos) {
            ans[second_pos] = std::max(prev[second_pos], ans[second_pos - 1]);
            ans[second_pos] = std::max(ans[second_pos], prev[second_pos - 1] +
                                                        (first_arr[first_pos] ==
                                                         second_arr[second_pos]));
        }
    }
    return ans.back();
}

template<class Iterator, class Compare>
inline Iterator Partition(Iterator first, Iterator last, Compare cmp) {
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
    typedef typename std::iterator_traits<Iterator>::value_type value_type;
    QuickSort(first, last, [](const value_type &lhs, const value_type &rhs) {
        return lhs < rhs;
    });
}

template<class Iterator>
void ReorderKth(Iterator first, Iterator last, size_t kth) {
    typedef typename std::iterator_traits<Iterator>::value_type value_type;
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
inline long long MergeTwoParts(Iterator left, Iterator mid, Iterator right, Iterator cache,
                               long long diff) {
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
    for (auto i = left; i < right; ++i) {
        *i = *(cache + static_cast<size_t> (i - left));
    }
    return result;
}



template<typename Iterator>
long long MergeSort(Iterator left, Iterator right, long long diff = 0, size_t merge_size = 1) {
    typedef typename std::iterator_traits<Iterator>::value_type value_type;
    std::vector<value_type> temp_arr(static_cast<size_t> (right - left));
    long long result = 0;
    while (merge_size < temp_arr.size()) {
        Iterator from = left;
        while (from + merge_size < right) {
            result += MergeTwoParts(from, from + merge_size, std::min(from + 2 * merge_size, right),
                                    temp_arr.begin(), diff);
            from += 2 * merge_size;
        }
        merge_size *= 2;
    }
    return result;
}

template<typename Compare, typename Function>
inline long double BinSearch(long double left, long double right, long double searching = 0.0,
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

inline void FFT(std::vector<std::complex<long double>> &arr, bool invert) {
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
        long double ang = 2 * acosl(-1) / len * (invert
                                                 ? -1
                                                 : 1);
        std::complex<long double> wlen(cosl(ang), sinl(ang));
        for (size_t i = 0; i < arr.size(); i += len) {
            std::complex<long double> wlong(1);
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
        for (auto &&element: arr) {
            element /= arr.size();
        }
    }
}

template<typename Input_Type>
std::vector<std::complex<long double>> MultiplyPolynomials(const std::vector<Input_Type> &first,
                                                           const std::vector<Input_Type> &second) {
    size_t degree = 1;
    while (degree < std::max(first.size(), second.size())) {
        degree <<= 1;
    }
    


    std::vector<std::complex<long double>> first_tmp(first.begin(), first.end());
    first_tmp.resize(degree);
    FFT(first_tmp, false);
    std::vector<std::complex<long double>> second_tmp(second.begin(), second.end());
    second_tmp.resize(degree);
    FFT(second_tmp, false);

    std::vector<std::complex<long double>> complex_ans(degree);
    for (size_t i = 0; i < degree; ++i) {
        complex_ans[i] = first_tmp[i] * second_tmp[i];
    }
    FFT(complex_ans, true);
    return complex_ans;
}

std::vector<long long> MultiplyIntPolynomials(const vi_ &first, const vi_ &second) {
    auto ans = MultiplyPolynomials(first, second);
    std::vector<long long> long_ans;
    long_ans.reserve(ans.size());
    for (auto &&element: ans) {
        long_ans.push_back(llroundl(element.real()));
    }
    return long_ans;
}






























template<typename T_Type, class Compare>
class Heap {
private:
    Compare cmp_;
    std::vector<T_Type> data_;

    inline void swapInHeap(size_t first, size_t second) {
        std::swap(data_[first], data_[second]);
        (*data_[first]).heap_position = first;
        (*data_[second]).heap_position = second;
    }



    inline void update(size_t position) {
        if (position < data_.size()) {
            siftDown(position);
            siftUp(position);
        }
    }

    inline void siftUp(size_t current) {
        while (current != 0) {
            if (!cmp_(*data_[(current - 1) / 2], *data_[current])) {
                swapInHeap((current - 1) / 2, current);
                current = (current - 1) / 2;
            } else {
                break;
            }
        }
    }

    inline void siftDown(size_t current) {
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
    explicit Heap(Compare cmp = Compare()) : cmp_(cmp), data_() { }

    inline bool empty() const {
        return data_.empty();
    }

    inline void remove(size_t position) {
        swapInHeap(position, data_.size() - 1);
        (*data_[data_.size() - 1]).heap_position = -1;
        data_.pop_back();
        update(position);
    }

    inline void insert(T_Type key) {
        data_.push_back(key);
        (*key).heap_position = data_.size() - 1;
        siftUp(data_.size() - 1);
    }

    inline T_Type getRoot() const {
        return data_[0];
    }
};


template<typename T_Type, typename Function>
inline T_Type BinPow(T_Type base, T_Type exponent,
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
inline vs_ RepresentInBaseTwo(T_Type num) {
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
inline const T_Type GCD(T_Type first, T_Type second) {
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
    if (first == 0) {
        coefficient_first = 0;
        coefficient_second = 1;
        return second;
    }
    T_Type ans = GCD(second % first, first, coefficient_first, coefficient_second);
    T_Type other = coefficient_first;
    coefficient_first = coefficient_second - (second / first) * coefficient_first;
    coefficient_second = other;
    return ans;
}

template<typename T_Type>
inline const T_Type UnitElement(T_Type remainder, T_Type modulo) {
    T_Type first, second;
    GCD(remainder, modulo, first, second);
    return (first % modulo + modulo) % modulo;
}

template<typename T_Type>
std::vector<T_Type> InputVector(std::istream &input_stream = std::cin) {
    size_t len;
    std::cin >> len;
    std::vector<T_Type> arr;
    arr.reserve(len);
    {
        T_Type element;
        for (size_t i = 0; i < len; ++i) {
            input_stream >> element;
            arr.emplace_back(element);
        }
    }
    return arr;
}

template<typename T_Type>
void OutputVector(const std::vector<T_Type> &arr, bool show_len = false, bool with_newline = false,
                  std::ostream &output_stream = std::cout) {
    if (show_len) {
        output_stream << arr.size() << "\n";
    }
    for (auto &&element: arr) {
        output_stream << element;
        if (with_newline) {
            output_stream << "\n";
        } else {
            output_stream << " ";
        }
    }
}

template<typename T_Type, typename Function, typename Multiple_Function>
class SegmentTreeLazy {
    struct TreeNode;
    typedef std::unique_ptr<TreeNode> uniqueNodePtr_;
    typedef TreeNode *nodePtr_;

    struct TreeNode {
        T_Type val_;
        bool has_changed_;
        uniqueNodePtr_ left_;
        uniqueNodePtr_ right_;

        TreeNode(T_Type val, bool has_changed = true) : val_(val), has_changed_(has_changed), left_(
                nullptr), right_(nullptr) {
        }
    };

private:
    uniqueNodePtr_ root_;
    size_t real_size_;
    T_Type default_val_;
    Function func_;
    Multiple_Function multiple_func_;

    inline void push(nodePtr_ node) {
        if (node->has_changed_) {
            if (node->left_ == nullptr) {
                node->left_ = uniqueNodePtr_(new TreeNode(node->val_, true));
                node->right_ = uniqueNodePtr_(new TreeNode(node->val_, true));
            } else {
                node->left_->val_ = node->right_->val_ = node->val_;
                node->left_->has_changed_ = node->right_->has_changed_ = true;
            }
            node->has_changed_ = false;
        }
    }

    inline T_Type getData(nodePtr_ node, size_t left, size_t right) const {
        if (node->has_changed_) {
            return multiple_func_(node->val_, right - left);
        } else {
            return node->val_;
        }
    }

    

    

    inline void setRecursive(nodePtr_ node, size_t left, size_t right, size_t from, size_t to,
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

    inline const T_Type getRecursive(nodePtr_ node, size_t left, size_t right, size_t from,
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
    SegmentTreeLazy(const std::vector<T_Type> &data, T_Type default_val = T_Type(0), Function func = Function(),
                    Multiple_Function multiple_func = Multiple_Function()) :
            root_(uniqueNodePtr_(new TreeNode(default_val))), real_size_(data.size()),
            default_val_(default_val), func_(func), multiple_func_(multiple_func) {
        for (size_t i = 0; i < real_size_; ++i) {
            set(i, data[i]);
        }
    }

    inline void set(size_t left, size_t right, T_Type val) {
        setRecursive(root_.get(), 0, real_size_, left, right, val);
    }

    inline void set(size_t pos, T_Type val) {
        set(pos, pos + 1, val);
    }

    inline const T_Type get(size_t left, size_t right) {
        return getRecursive(root_.get(), 0, real_size_, left, right);
    }

    inline const T_Type get(size_t pos) {
        return get(pos, pos + 1);
    }

    inline const T_Type get() {
        return get(0, real_size_);
    }
};

template<typename T_Type, typename Function, typename MultipleFunction>
class SegmentTree {
private:
    std::vector<T_Type> data_;
    std::vector<bool> has_changed_;
    size_t real_size_;
    Function func_;
    MultipleFunction multiple_func_;
    T_Type default_val_;

    inline void push(size_t vertex) {
        if (has_changed_[vertex]) {
            data_[2 * vertex + 1] = data_[2 * vertex + 2] = data_[vertex];
            has_changed_[2 * vertex + 1] = has_changed_[2 * vertex + 2] = true;
            has_changed_[vertex] = false;
        }
    }

    inline T_Type getData(size_t vertex, size_t left, size_t right) const {
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
                        const std::vector<T_Type> &data) {
        if (left + 1 == right) {
            data_[vertex] = data[left];
        } else {
            size_t mid = (left + right) / 2;
            buildRecursive(2 * vertex + 1, left, mid, data);
            buildRecursive(2 * vertex + 2, mid, right, data);
            data_[vertex] = func_(
                    data_[2 * vertex + 1],
                    data_[2 * vertex + 2]
            );
        }
    }

public:
    SegmentTree(const std::vector<T_Type> &data, Function func = Function(),
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

    inline void set(size_t left, size_t right, T_Type val) {
        setRecursive(0, 0, real_size_, left, right, val);
    }

    inline void set(size_t pos, T_Type val) {
        set(pos, pos + 1, val);
    }

    inline const T_Type get(size_t left, size_t right) {
        return getRecursive(0, 0, real_size_, left, right);
    }

    inline const T_Type get(size_t pos) {
        return get(pos, pos + 1);
    }

    inline const T_Type get() {
        return get(0, real_size_);
    }
};

namespace geometry {
    typedef long double ld_;
    const ld_ EPS_ = 1e-7;
    using namespace std::rel_ops;

    

    class Point {
    private:
        ld_ first_;
        ld_ second_;

    public:
        Point(ld_ first = 0.0, ld_ second = 0.0) : first_(first), second_(second) {
        }

        friend inline Point &operator+=(Point &lhs, const Point &rhs) {
            lhs.first_ += rhs.first_;
            lhs.second_ += rhs.second_;
            return lhs;
        }

        friend inline Point operator+(const Point &lhs, const Point &rhs) {
            return Point(lhs.first_ + rhs.first_, lhs.second_ + rhs.second_);
        }

        friend inline Point &operator-=(Point &lhs, const Point &rhs) {
            lhs.first_ -= rhs.first_;
            lhs.second_ -= rhs.second_;
            return lhs;
        }

        friend inline Point operator-(const Point &lhs, const Point &rhs) {
            return Point(lhs.first_ - rhs.first_, lhs.second_ - rhs.second_);
        }

        inline ld_ length() const {
            return sqrtl(first_ * first_ + second_ * second_);
        }

        inline friend ld_ distance(const Point &lhs, const Point &rhs) {
            return (rhs - lhs).length();
        }

        inline friend ld_ scalar(const Point &lhs, const Point &rhs) {
            return lhs.first_ * rhs.first_ + lhs.second_ * rhs.second_;
        }

        inline friend ld_ oriented_square(const Point &lhs, const Point &rhs) {
            return (lhs.first_ * rhs.second_ - rhs.first_ * lhs.second_) / 2.0;
        }

        inline friend ld_ square(const Point &lhs, const Point &rhs) {
            return std::abs(oriented_square(lhs, rhs));
        }

        inline friend ld_ oriented_square(const Point &first, const Point &second,
                                          const Point &third) {
            return oriented_square(second - first, third - first);
        }

        inline friend ld_ square(const Point &first, const Point &second, const Point &third) {
            return square(second - first, third - first);
        }

        inline friend ld_ angle(const Point &lhs, const Point &rhs) {
            return acosl(scalar(lhs, rhs) / lhs.length() / rhs.length());
        }

        inline bool operator==(const Point &rhs) const {
            return std::abs(first_ - rhs.first_) < EPS_ && std::abs(second_ - rhs.second_) < EPS_;
        }

        inline friend bool operator<(const Point &lhs, const Point &rhs) {
            return (lhs.first_ - rhs.first_ < -EPS_) ||
                   (lhs.first_ - rhs.first_ < EPS_ && lhs.second_ < rhs.second_ - EPS_);
        }

        inline ld_ get_first() const {
            return first_;
        }

        inline ld_ get_second() const {
            return second_;
        }

        friend std::istream &operator>>(std::istream &input, Point &pt) {
            input >> pt.first_ >> pt.second_;
            return input;
        }

        friend std::ostream &operator<<(std::ostream &output, const Point &pt) {
            output << pt.first_ << " " << pt.second_;
            return output;
        }
    };

    class Line {
    private:
        ld_ first_;
        ld_ second_;
        ld_ free_;

        inline void normalize() {
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

        inline ld_ operator()(const Point &pt) const {
            return first_ * pt.get_first() + second_ * pt.get_second() + free_;
        }

        friend inline bool operator==(const Line &lhs, const Line &rhs) {
            return std::abs(lhs.first_ - rhs.first_) < EPS_ &&
                   std::abs(lhs.second_ - rhs.second_) < EPS_ &&
                   std::abs(lhs.free_ - rhs.free_) < EPS_;
        }

        friend std::istream &operator>>(std::istream &input, Line &ln) {
            input >> ln.first_ >> ln.second_ >> ln.free_;
            return input;
        }

        friend std::ostream &operator<<(std::ostream &output, const Line &ln) {
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

        inline ld_ length() const {
            return distance(first_, second_);
        }

        friend inline bool operator==(const Segment &lhs, const Segment &rhs) {
            return lhs.first_ == rhs.first_ && lhs.second_ == rhs.second_;
            

            

            

            

        }

        friend inline bool operator<(const Segment &lhs, const Segment &rhs) {
            return std::make_pair(lhs.first_, lhs.second_) <
                   std::make_pair(rhs.first_, rhs.second_);
        }

        inline Line make_line() const {
            Point difference = first_ - second_;
            ld_ coefficient_first = difference.get_second();
            ld_ coefficient_second = -difference.get_first();
            ld_ coefficient_free = 0.0 - coefficient_first * first_.get_first() -
                                   coefficient_second * first_.get_second();
            return Line(coefficient_first, coefficient_second, coefficient_free);
        }

        inline Point get_first() const {
            return first_;
        }

        inline Point get_second() const {
            return second_;
        }

        friend std::istream &operator>>(std::istream &input, Segment &sgm) {
            input >> sgm.first_ >> sgm.second_;
            return input;
        }

        friend std::ostream &operator<<(std::ostream &output, const Segment &sgm) {
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

        inline friend ld_ square(const Triangle &lhs) {
            return square(lhs.first_, lhs.second_, lhs.third_);
        }

        inline friend ld_ oriented_square(const Triangle &lhs) {
            return oriented_square(lhs.first_, lhs.second_, lhs.third_);
        }

        friend std::istream &operator>>(std::istream &input, Triangle &tri) {
            input >> tri.first_ >> tri.second_ >> tri.third_;
            return input;
        }

        friend std::ostream &operator<<(std::ostream &output, const Triangle &tri) {
            output << tri.first_ << " " << tri.second_ << " " << tri.third_;
            return output;
        }
    };

    class Polygon {
    private:
        std::vector<Point> points_;

    public:
        explicit Polygon(const std::vector<Point> &points = std::vector<Point>(0)) : points_(points) {
        }

        inline size_t size() const {
            return points_.size();
        }

        inline bool empty() const {
            return points_.empty();
        }

        inline ld_ perimeter() {
            if (empty()) {
                return 0.0;
            }
            ld_ ans = distance(points_[0], points_.back());
            for (size_t i = 0; i + 1 < size(); ++i) {
                ans += distance(points_[i], points_[i + 1]);
            }
            return ans;
        }

        friend inline ld_ square(const Polygon &lhs) {
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
            size_t min_pt = 0;
            for (size_t i = 0; i < points_.size(); ++i) {
                if (points_[i] < points_[min_pt]) {
                    min_pt = i;
                }
            }
            vs_ indexes(size());
            std::iota(indexes.begin(), indexes.end(), 0);
            std::sort(indexes.begin(), indexes.end(), [&](const size_t &lhs, const size_t &rhs) {
                ld_ sq = oriented_square(points_[min_pt], points_[lhs], points_[rhs]);
                return (sq > EPS_) || (sq >= -EPS_ && distance(points_[min_pt], points_[lhs]) <
                                                      distance(points_[min_pt], points_[rhs]));
            });
            vs_ ans {min_pt};
            for (auto &&point_num: indexes) {
                while (ans.size() > 1 &&
                       oriented_square(points_[ans[ans.size() - 2]], points_[ans[ans.size() - 1]],
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
            std::vector<Point> convex_points;
            convex_points.reserve(indexes.size());
            for (auto &&index: indexes) {
                convex_points.emplace_back(points_[index]);
            }
            return Polygon(convex_points);
        }

        friend std::istream &operator>>(std::istream &input, Polygon &poly) {
            poly.points_ = InputVector<Point>();
            return input;
        }

        friend std::ostream &operator<<(std::ostream &output, const Polygon &poly) {
            OutputVector(poly.points_);
            return output;
        }
    };
} 





class HashNum {
    typedef long long ll_;

private:
    inline void normalize() {
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

    friend inline HashNum &operator+=(HashNum &lhs, const HashNum &rhs) {
        lhs.a_ += rhs.a_;
        lhs.b_ += rhs.b_;
        lhs.normalize();
        return lhs;
    }

    friend inline HashNum operator+(const HashNum &lhs, const HashNum &rhs) {
        return HashNum(lhs.a_ + rhs.a_, lhs.b_ + rhs.b_);
    }

    friend inline HashNum &operator-=(HashNum &lhs, const HashNum &rhs) {
        lhs.a_ -= rhs.a_;
        lhs.b_ -= rhs.b_;
        lhs.normalize();
        return lhs;
    }

    friend inline HashNum operator-(const HashNum &lhs, const HashNum &rhs) {
        return HashNum(lhs.a_ - rhs.a_, lhs.b_ - rhs.b_);
    }

    friend inline HashNum &operator*=(HashNum &lhs, const HashNum &rhs) {
        lhs.a_ = static_cast<int>((static_cast<ll_> (lhs.a_) * rhs.a_) % MA);
        lhs.b_ = static_cast<int>((static_cast<ll_> (lhs.b_) * rhs.b_) % MB);
        return lhs;
    }

    friend inline HashNum operator*(const HashNum &lhs, const HashNum &rhs) {
        HashNum ans(lhs);
        ans *= rhs;
        return ans;
    }

    friend inline bool operator==(const HashNum &lhs, const HashNum &rhs) {
        return lhs.a_ == rhs.a_ && lhs.b_ == rhs.b_;
    }

    friend inline bool operator<(const HashNum &lhs, const HashNum &rhs) {
        return std::make_pair(lhs.a_, lhs.b_) < std::make_pair(rhs.a_, rhs.b_);
    }

    inline explicit operator ll_() const {
        return static_cast<ll_> (a_) * MB + b_ + 1;
    }

    friend std::ostream &operator<<(std::ostream &output, const HashNum &hash) {
        output << hash.a_ << " " << hash.b_;
        return output;
    }
};










template<class Hash_Type>
class StrComparator {
private:
    static const int VAR_;
    static std::vector<Hash_Type> deg_;
    std::string text_;
    std::vector<Hash_Type> hash_;

public:
    explicit StrComparator(const std::string &text) : text_(text), hash_ {Hash_Type(0)} {
        hash_.reserve(text_.size() + 1);
        for (auto &&symbol: text_) {
            hash_.emplace_back(hash_.back() * VAR_ + Hash_Type(symbol));
        }
        deg_.reserve(text_.size() + 2);
        while (deg_.size() <= text_.size()) {
            deg_.emplace_back(deg_.back() * VAR_);
        }
    }

    Hash_Type substr(size_t pos, size_t len) const {
        return hash_[pos + len] - hash_[pos] * deg_[len];
    }

    inline size_t size() const {
        return text_.size();
    }

    inline size_t lcp(size_t lhs, size_t rhs) const {
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

    inline bool cmp(size_t lhs, size_t rhs) const {
        size_t len = text_.size() - std::max(lhs, rhs), lcp_length = lcp(lhs, rhs);
        return lcp_length < len
               ? text_[lhs + lcp_length] < text_[rhs + lcp_length]
               : rhs < lhs;
    }

    inline Hash_Type operator()() const {
        return substr(0, size());
    }
};

template<class Hash_Type> std::vector<Hash_Type>
        StrComparator<Hash_Type>::deg_ {Hash_Type(1)};
template<class Hash_Type> const int
        StrComparator<Hash_Type>::VAR_ = std::max(239, rand());

template<class Hash_Type>
inline vs_ SuffixArray(const StrComparator<Hash_Type> &hash) {
    vs_ suffix_array(hash.size());
    std::iota(suffix_array.begin(), suffix_array.end(), 0);
    std::sort(suffix_array.begin(), suffix_array.end(), [&](size_t lhs, size_t rhs) {
        return hash.cmp(lhs, rhs);
    });
    return suffix_array;
}

vs_ SuffixArray(const std::string &text) {
    return SuffixArray(StrComparator<HashNum>(text));
}

inline void LowerString(std::string &text) {
    std::transform(text.begin(), text.end(), text.begin(), ::tolower);
}

inline void UpperString(std::string &text) {
    std::transform(text.begin(), text.end(), text.begin(), ::toupper);
}

inline void ReverseString(std::string &text) {
    std::reverse(text.begin(), text.end());
}

vi_ TextAsSumOfSamples(const std::string &text, const std::vector<std::string> &samples) {
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
            if (j == -1 || prev[j] != -1) {
                auto it = samples_hashes.find(
                        static_cast<long long>(text_hash.substr(static_cast<size_t> (j + 1),
                                                                current_pos - j)));
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
    

    typedef int Index;

    explicit FenwickTree(size_t size) : sums_(size, 0) { }

    

    void initialize(vi_ numbers) {
        

        std::partial_sum(numbers.begin(), numbers.end(), numbers.begin());
        sums_.reserve(numbers.size());
        for (Index i = 0; i < size(); ++i) {
            sums_.push_back(numbers[i]);
            Index previousI = previousIndex(i);
            if (previousI > 0) {
                sums_[i] -= numbers[previousI - 1];
            }
        }
    }

    inline void add(Index index, int value) {
        while (index < size()) {
            sums_[index] += value;
            index |= (index + 1);
        }
    }

    inline int sum(Index firstIndex, Index lastIndex) const {
        return sum(lastIndex) - sum(firstIndex - 1);
    }

    inline int at(Index index) const {
        return sum(index, index);
    }

    inline Index size() const {
        return static_cast<Index>(sums_.size());
    }

private:
    inline int sum(Index lastIndex) const {
        return lastIndex >= 0
               ? sums_[static_cast<size_t> (lastIndex)] + sum(previousIndex(lastIndex) - 1)
               : 0;
    }

    

    

    inline static Index previousIndex(Index index) {
        return index & (index + 1);
    }

    vi_ sums_;
};

vs_ PrefixFunction(const std::string &text) {
    vs_ ans {0};
    ans.reserve(text.size());
    for (size_t index = 1; index < ans.size(); ++index) {
        size_t cur = ans.back();
        while (cur > 0 && text[index] != text[cur]) {
            cur = ans[cur - 1];
        }
        ans.push_back(cur + (text[index] == text[cur]));
    }
    return ans;
}

vs_ ZFunction(const std::string &text) {
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

bool IsPeriodic(const std::string &text, size_t check) {
    for (size_t index = check; index < text.size(); ++index) {
        if (text[index] != text[index % check]) {
            return false;
        }
    }
    return true;
}

size_t MinPeriod(const std::string &text) {
    for (size_t i = 1; 2 * i <= text.size(); ++i) {
        if (text.size() % i == 0 && IsPeriodic(text, i)) {
            return i;
        }
    }
    return text.size();
}

class Graph {
    typedef long long ll_;

private:
    vvs_ outgoing_edges_;
    vvs_ level_graph_edges_;
    vvs_ capacity_matrix_;
    vs_ source_distance_;
    std::vector<std::pair<size_t *, size_t>> buffer_changes_;

    static const ll_ LONGINF_;
    static const size_t INF_;

    bool buildLevelGraph(size_t source, size_t target, size_t min_capacity) {
        source_distance_.assign(size(), INF_);
        source_distance_[source] = 0;
        std::queue<size_t> bfs_queue;
        bfs_queue.push(source);
        while (!bfs_queue.empty()) {
            size_t from = bfs_queue.front();
            for (auto to : outgoing_edges_[from]) {
                if (source_distance_[to] == INF_ && capacity_matrix_[from][to] >= min_capacity) {
                    source_distance_[to] = source_distance_[from] + 1;
                    bfs_queue.push(to);
                }
            }
            bfs_queue.pop();
        }
        if (source_distance_[target] == INF_) {
            return false;
        }
        for (size_t from = 0; from < size(); ++from) {
            level_graph_edges_[from].clear();
            for (auto to : outgoing_edges_[from]) {
                if (source_distance_[from] + 1 == source_distance_[to] &&
                    capacity_matrix_[from][to] >= min_capacity) {
                    level_graph_edges_[from].push_back(to);
                }
            }
        }
        return true;
    }

    inline ll_ findBlockingFlow(size_t vertex, size_t target, ll_ flow) {
        if (vertex == target) {
            return flow;
        }
        ll_ total_flow = 0;
        while (!level_graph_edges_[vertex].empty()) {
            size_t to = level_graph_edges_[vertex].back();
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

    inline ll_ dinicIteration(size_t source, size_t target, size_t min_capacity) {
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
                                     source_distance_(0), buffer_changes_(0) {
    }

    void initFlowSearch() {
        size_t num = size();
        level_graph_edges_.assign(num, vs_(0));
        capacity_matrix_.assign(num, vs_(num, 0));
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
        ll_ ans = 0;
        if (scaling) {
            size_t max_capacity = 0;
            for (size_t from = 0; from < size(); ++from) {
                for (auto to : outgoing_edges_[from]) {
                    max_capacity = std::max(max_capacity, capacity_matrix_[from][to]);
                }
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
        return ans;
    }
};

const long long Graph::LONGINF_(std::numeric_limits<long long>::max());
const size_t Graph::INF_(std::numeric_limits<size_t>::max());

Graph ReadGraph(std::istream &input_stream = std::cin) {
    size_t vertices_num, edges_num;
    input_stream >> vertices_num >> edges_num;
    Graph ans(vertices_num);
    ans.initFlowSearch();
    for (size_t i = 0; i < edges_num; ++i) {
        size_t first, second, capacity;
        input_stream >> first >> second >> capacity;
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
        for (auto to : graph.getAdjacentVertices(from)) {
            ans.addEdge(to, from);
        }
    }
    return ans;
}





template<class AnyGraph, class Vertex, class Callback>
void DFS(const AnyGraph &graph, const Vertex &vertex, std::vector<bool> &visited_vertices,
         Callback call_on_exit) {
    visited_vertices[vertex] = true;
    for (const auto &to : graph.getAdjacentVertices(vertex)) {
        if (!visited_vertices[to]) {
            DFS(graph, to, visited_vertices, call_on_exit);
        }
    }
    call_on_exit(vertex);
}



Graph FindCondensation(const Graph &graph, vs_ &equals_num) {
    std::vector<bool> visited_vertices(graph.size(), false);
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
    vs_ equality_class(graph.size());
    while (!vertices_sorted_by_finish.empty()) {
        size_t vertex = vertices_sorted_by_finish.top();
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
    return ans;
}

template<typename T_Type>
struct TwoVarSum {
    inline T_Type operator()(const T_Type &lhs, const T_Type &rhs) const {
        return lhs + rhs;
    }
};

void checkSegmentTree() {
    size_t n, q;
    std::string s;
    std::cin >> n >> q >> s;
    vvi_ v(26, vi_(n, 0));
    for (size_t i = 0; i < n; ++i) {
        ++v[s[i] - 'a'][i];
    }

    std::vector<SegmentTree<int, TwoVarSum<int>, std::multiplies<int>>> tree;
    for (auto &&vec: v) {
        tree.emplace_back(vec);
    }

    for (size_t l = 0; l < q; ++l) {
        size_t left, right, ty;
        std::cin >> left >> right >> ty;
        --left;
        vi_ a;
        a.reserve(26);
        for (auto &&tr: tree) {
            a.emplace_back(tr.get(left, right));
            tr.set(left, right, 0);
        }
        if (ty) {
            for (size_t j = 0; j < 26; ++j) {
                tree[j].set(left, left + a[j], 1);
                left += a[j];
            }
        } else {
            for (size_t j = 0; j < 26; ++j) {
                tree[25 - j].set(left, left + a[25 - j], 1);
                left += a[25 - j];
            }
        }
    }

    for (size_t i = 0; i < 26; ++i) {
        for (size_t j = 0; j < n; ++j) {
            if (tree[i].get(j) == 1) {
                s[j] = static_cast<char> (i + 'a');
            }
        }
    }
    std::cout << s << "\n";
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cout << std::fixed << std::setprecision(7);

    

    checkSegmentTree();

    return 0;
}
