

#include <string>
#include <stack>
#include <vector>
#include <cstdio>
#include <functional>
#include <iomanip>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <random>
#include <ctime>
#include <complex>
#include <list>
#include <utility>
#include <limits>
#include <queue>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>

template <class Hashable_Type>
inline void hash_combine(std::size_t& seed, const Hashable_Type& v) {
    std::hash<Hashable_Type> hasher;
    seed ^= hasher(v) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
}

namespace std {
    template<class Hashable_First_Type, class Hashable_Second_Type>
    struct hash<std::pair<Hashable_First_Type, Hashable_Second_Type>> {
        inline size_t operator()(
            const std::pair<Hashable_First_Type, Hashable_Second_Type>& pr)
        const {
            size_t seed = 0;
            ::hash_combine(seed, pr.first);
            ::hash_combine(seed, pr.second);
            return seed;
        }
    };
} 






int CorrectBrackets(const std::string& text) {
    std::stack<size_t> stack;
    for (size_t symbol_index = 0; symbol_index < text.size(); ++symbol_index) {
        auto bracket = text[symbol_index];
        if (bracket == '(' || bracket == '[' || bracket == '{') {
            stack.push(symbol_index);
        } else {
            if (stack.empty()) {
                return symbol_index;
            }
            size_t last = stack.top();
            stack.pop();
            if ((bracket == ')' && text[last] != '(') ||
                (bracket == ']' && text[last] != '[') ||
                (bracket == '}' && text[last] != '{')) {
                return symbol_index;
            }
        }
    }
    return !stack.empty()
        ? text.size()
        : -1;
}











template <typename T_Type, typename Function_Type>
class SparseTree {
private:
    static std::vector<size_t> log_;
    std::vector<std::vector<T_Type>> sparse_;
    Function_Type& func_;

public:
    SparseTree(const std::vector<T_Type>& mass, Function_Type& func)
        : sparse_(0)
        , func_(func) {
        size_t len = mass.size();
        size_t pow = log_.back() + 1;
        while ((1 << pow) < 5 * len) {
            log_.insert(log_.end(), 1 << pow, pow);
            ++pow;
        }

        for (size_t pow = 0; pow <= log_[len]; ++pow) {
            sparse_.push_back(std::vector<T_Type> (len));
            for (size_t j = 0; j < len; ++j) {
                if (pow == 0) {
                    sparse_[pow][j] = func_(mass[j], mass[j]);
                } else {
                    sparse_[pow][j] = func_(sparse_[pow - 1][j],
                                              sparse_[pow - 1][std::min(j +
                                                  (1 << (pow - 1)),
                                                  len - 1)]);
                }
            }
        }
    }

    inline T_Type GetAns(size_t left, size_t right) const {
        return func_(
            sparse_[log_[right - left]][left],
            sparse_[log_[right - left]][right - (1 << log_[right - left])]
        );
    }
};

template <typename T_Type, typename Function_Type>
std::vector<size_t> SparseTree<T_Type, Function_Type>::log_ {0, 0, 1, 1};



template <typename T_Type>
inline int CommonSubsequence(const std::vector<T_Type>& firstarr,
                             const std::vector<T_Type>& secondarr) {
    std::vector<size_t> ans(secondarr.size(), 0);
    ans[0] = static_cast<size_t>(firstarr[0] == secondarr[0]);
    for (size_t j = 1; j < secondarr.size(); ++j) {
        ans[j] = std::max(ans[j - 1],
                          static_cast<size_t>(firstarr[0] == secondarr[j]));
    }

    for (size_t i = 1; i < firstarr.size(); ++i) {
        auto prev = ans;
        ans[0] = std::max(prev[0],
                          static_cast<size_t>(firstarr[i] == secondarr[0]));
        for (size_t j = 1; j < secondarr.size(); ++j) {
            ans[j] = std::max(prev[j], ans[j - 1]);
            ans[j] = std::max(ans[j], prev[j - 1] +
                              static_cast<size_t>(firstarr[i] == secondarr[j]));
        }
    }

    return ans.back();
}

template <class Iterator, class Compare>
inline Iterator Partition(Iterator first, Iterator last, Compare cmp) {
    static std::mt19937 generator;
    std::uniform_int_distribution<> uid(0, static_cast<int>(last - first - 1));
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
        Iterator bestleft = left - 1;
        while (bestleft > first && !cmp(*(bestleft - 1), pivot_value) &&
                                   !cmp(pivot_value, *(bestleft - 1))) {
            --bestleft;
        }
        std::uniform_int_distribution<> uid_ans(0,
                                        static_cast<size_t>(left - bestleft));
        return uid_ans(generator) + bestleft;
    } else {
        return left;
    }
}

template <class Iterator, class Compare>
void QuickSort(Iterator first, Iterator last, Compare cmp) {
    if (first + 1 < last) {
        Iterator mid = Partition(first, last, cmp);
        QuickSort(first, mid, cmp);
        QuickSort(mid, last, cmp);
    }
}

template <class Iterator>
void QuickSort(Iterator first, Iterator last) {
    typedef typename std::iterator_traits<Iterator>::value_type value_type;
    QuickSort(first, last, [] (value_type lhs, value_type rhs) {
        return lhs < rhs;
    });
}

template <class Iterator>
inline void ReorderKth(Iterator first, Iterator last, size_t kth) {
    typedef typename std::iterator_traits<Iterator>::value_type value_type;
    while (first + 1 < last) {
        Iterator mid = Partition(first, last,
            [] (value_type lhs, value_type rhs) {
                return lhs > rhs;
            });
        if (static_cast<size_t>(mid - first) == kth) {
            return;
        } else if (static_cast<size_t>(mid - first) > kth) {
            last = mid;
        } else {
            kth -= (mid - first);
            first = mid;
        }
    }
}





template <typename Iterator>
inline long long MergeTwoParts(Iterator left, Iterator mid, Iterator right,
                        Iterator cache, long long diff) {
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
        *i = *(cache + static_cast<size_t>(i - left));
    }
    return result;
}



template <typename Iterator>
inline long long MergeSort(Iterator left, Iterator right,
                           long long diff = 0, size_t mergesize = 1) {
    typedef typename std::iterator_traits<Iterator>::value_type value_type;
    std::vector<value_type> temparr(static_cast<size_t> (right - left));
    long long result = 0;
    while (mergesize < temparr.size()) {
        Iterator from = left;
        while (from + mergesize < right) {
            result += MergeTwoParts(from, from + mergesize,
                                    std::min(from + 2 * mergesize, right),
                                    temparr.begin(), diff);
            from += 2 * mergesize;
        }
        mergesize *= 2;
    }
    return result;
}

template <typename Compare, typename Function_Type>
inline long double bin_search(long double left, long double right,
                       Function_Type& func,
                       long double searching,
                       Compare comp = std::less<long double>()) {
    while (right - left > 1e-10) {
        long double mid = (left + right) / 2;
        if (comp(func(mid), searching)) {
            left = mid;
        } else {
            right = mid;
        }
    }
    return (left + right) / 2;
}

inline void FFT(std::vector<std::complex<long double>>& arr, bool invert) {
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
        long double ang = 2 * acosl(-1) / len * (invert ? -1 : 1);
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
        for (auto&& element: arr) {
            element /= arr.size();
        }
    }
}

template <typename Input_Type>
inline std::vector<std::complex<long double>> MultiplyPolinoms(
                        const std::vector<Input_Type>& first,
                        const std::vector<Input_Type>& second) {
    size_t degree = 1;
    while (degree < std::max(first.size(), second.size())) {
        degree <<= 1;
    }
    


    std::vector<std::complex<long double>> first_tmp(
        first.begin(), first.end());
    first_tmp.resize(degree);
    FFT(first_tmp, false);
    std::vector<std::complex<long double>> second_tmp(
        second.begin(), second.end());
    second_tmp.resize(degree);
    FFT(second_tmp, false);

    std::vector<std::complex<long double>> complex_ans(degree);
    for (size_t i = 0; i < degree; ++i) {
        complex_ans[i] = first_tmp[i] * second_tmp[i];
    }
    FFT(complex_ans, true);
    return complex_ans;
}

inline std::vector<long long> MultiplyIntPolinoms(
                            const std::vector<int>& first,
                            const std::vector<int>& second) {
    auto ans = MultiplyPolinoms(first, second);
    std::vector<long long> long_ans(ans.size());
    for (size_t i = 0; i < ans.size(); ++i) {
        long_ans[i] = llroundl(ans[i].real());
    }
    return long_ans;
}































template <typename T, class Cmp>
class Heap {
private:
    Cmp cmp_;
    std::vector<T> data_;

public:
    Heap(Cmp cmp = Cmp())
        : cmp_(cmp)
        , data_() {
    }

    inline bool IsEmpty() const {
        return (data_.size() == 0);
    }

    

    inline void UpdateElement(size_t position) {
        if (position < data_.size()) {
            SiftDown(position);
            SiftUp(position);
        }
    }

    inline void DeleteElement(size_t position) {
        Swap(position, data_.size() - 1);
        (*data_[data_.size() - 1]).heap_position = -1;
        data_.pop_back();
        UpdateElement(position);
    }

    inline void AddElement(T key) {
        data_.push_back(key);
        (*key).heap_position = data_.size() - 1;
        SiftUp(data_.size() - 1);
    }

    inline T GetRoot() const {
        return data_[0];
    }

    inline void Swap(size_t first, size_t second) {
        std::swap(data_[first], data_[second]);
        (*data_[first]).heap_position = first;
        (*data_[second]).heap_position = second;
    }

    inline void SiftUp(size_t current) {
        while (current != 0) {
            if (!cmp_(*data_[(current - 1) / 2], *data_[current])) {
                Swap((current - 1) / 2, current);
                current = (current - 1) / 2;
            } else {
                break;
            }
        }
    }

    inline void SiftDown(size_t current) {
        while (2 * current + 1 < data_.size()) {
            if (2 * current + 2 < data_.size()) {
                if (!cmp_(*data_[current], *data_[2 * current + 1]) ||
                    !cmp_(*data_[current], *data_[2 * current + 2])) {
                    if (cmp_(*data_[2 * current + 1],
                              *data_[2 * current + 2])) {
                        Swap(current, 2 * current + 1);
                        current = 2 * current + 1;
                    } else {
                        Swap(current, 2 * current + 2);
                        current = 2 * current + 2;
                    }
                } else {
                    break;
                }
            } else if (!cmp_(*data_[current], *data_[2 * current + 1])) {
                Swap(current, 2 * current + 1);
                current = 2 * current + 1;
            } else {
                break;
            }
        }
    }
};

template <typename T_Type>
inline const T_Type MyMult(const T_Type& lhs, const T_Type& rhs) {
    return lhs * rhs;
}

template <typename T_Type>
inline T_Type BinPow(T_Type base,
        unsigned long long exponent,
        T_Type modulo = std::numeric_limits<T_Type>::max(),
        std::function<const T_Type(const T_Type&, const T_Type&)>&
        func = MyMult<T_Type>,
        T_Type default_val = 1) {
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



inline std::vector<size_t> RepresentInBaseTwo(unsigned long long num) {
    std::vector<size_t> ans;
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

template <typename T_Type>
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

template <typename T_Type>
inline std::vector<T_Type> InputVector() {
    size_t len;
    std::cin >> len;
    std::vector<T_Type> arr(len);
    for (size_t i = 0; i < len; ++i) {
        std::cin >> arr[i];
    }
    return arr;
}




















template <typename T_Type, typename Function_Type,
          typename MultipleFunction_Type>
class SegmentTree {
    struct TreeNode {
        T_Type val_;
        bool has_changed_;
        TreeNode* left_;
        TreeNode* right_;

        TreeNode(T_Type val, bool has_changed = true, TreeNode* left = 0, TreeNode* right = 0)
            : val_(val)
            , has_changed_(has_changed)
            , left_(left)
            , right_(right)
        {}
    };

private:
    TreeNode* root_;
    size_t real_size_;
    Function_Type& func_;
    MultipleFunction_Type& multiple_func_;
    T_Type default_val_;

    inline T_Type GetData(TreeNode* node, size_t left, size_t right) const {
        if (node->has_changed_) {
            return multiple_func_(node->val_, right - left);
        } else {
            return node->val_;
        }
    }

    inline void Push(TreeNode* node) {
        if (node->has_changed_) {
            if (node->left_ == 0) {
                node->left_ = new TreeNode(node->val_, true);
                node->right_ = new TreeNode(node->val_, true);
            } else {
                node->left_->val_ = node->right_->val_ = node->val_;
                node->left_->has_changed_ = node->right_->has_changed_ = true;
            }
            node->has_changed_ = false;
        }
    }

    inline void Update(TreeNode* node, size_t left, size_t right) {
        size_t mid = (left + right) / 2;
        node->val_ = func_(GetData(node->left_, left, mid),
                           GetData(node->right_, mid, right));
        node->has_changed_ = false;
    }

    

    

    T_Type SetOrGetRecursive(TreeNode* node, size_t left, size_t right,
                      size_t from, size_t to, bool to_set, T_Type val) {
        if (from >= right || left >= to) {
            return default_val_;
        }
        if (left == from && right == to) {
            if (to_set) {
                node->val_ = val;
                node->has_changed_ = true;
            }
            return GetData(node, left, right);
        } else {
            Push(node);
            size_t mid = (left + right) / 2;
            T_Type left_ans = SetOrGetRecursive(node->left_, left, mid,
                         from, std::min(to, mid), to_set, val);
            T_Type right_ans = SetOrGetRecursive(node->right_, mid, right,
                         std::max(from, mid), to, to_set, val);
            Update(node, left, right);
            return func_(left_ans, right_ans);
        }
    }

public:
    SegmentTree(size_t num, Function_Type& func,
                MultipleFunction_Type& multiple_func,
                T_Type default_val = T_Type(0))
        : root_(new TreeNode(default_val))
        , real_size_(num)
        , func_(func)
        , multiple_func_(multiple_func)
        , default_val_(default_val) {
    }

    SegmentTree(const std::vector<T_Type>& data, Function_Type& func,
                MultipleFunction_Type& multiple_func,
                T_Type default_val = T_Type(0))
        : root_(new TreeNode(default_val))
        , real_size_(data.size())
        , func_(func)
        , multiple_func_(multiple_func)
        , default_val_(default_val) {
        Initialize(data);
    }

    void Initialize(const std::vector<T_Type>& data) {
        for (size_t i = 0; i < data.size(); ++i) {
            Set(i, data[i]);
        }
    }

    inline void Set(size_t left, size_t right, T_Type val) {
        SetOrGetRecursive(root_, 0, real_size_, left, right, true, val);
    }

    inline void Set(size_t pos, T_Type val) {
        Set(pos, pos + 1, val);
    }

    inline const T_Type Get(size_t left, size_t right) {
        return SetOrGetRecursive(root_, 0, real_size_, left, right, false, default_val_);
    }

    inline const T_Type Get(size_t pos) {
        return Get(pos, pos + 1);
    }

    inline const T_Type Get() {
        return Get(0, real_size_);
    }
};



class Point {
    typedef long double ld;

private:
    ld first_;
    ld second_;
    static constexpr ld EPS = 3 * std::numeric_limits<double>::epsilon();

public:
    Point (ld first = 0.0, ld second = 0.0)
        : first_(first)
        , second_(second) {
    }

    inline Point& operator +=(const Point& rhs) {
        first_ += rhs.first_;
        second_ += rhs.second_;
        return *this;
    }

    inline Point operator +(const Point& rhs) const {
        Point ans(*this);
        ans += rhs;
        return ans;
    }

    inline Point& operator -=(const Point& rhs) {
        first_ -= rhs.first_;
        second_ -= rhs.second_;
        return *this;
    }

    inline Point operator -(const Point& rhs) const {
        Point ans(*this);
        ans -= rhs;
        return ans;
    }

    inline ld length() const {
        return sqrtl(first_ * first_ + second_ * second_);
    }

    inline friend ld distance(const Point& lhs, const Point& rhs) {
        return (lhs - rhs).length();
    }

    inline friend ld scalar(const Point& lhs, const Point& rhs) {
        return lhs.first_ * rhs.first_ + lhs.second_ * rhs.second_;
    }

    inline friend ld oriented_triangle_on_vectors_square(const Point& lhs,
                                                         const Point& rhs) {
        return (lhs.first_ * rhs.second_ -
                        rhs.first_ * lhs.second_) / 2.0;
    }

    inline friend ld triangle_on_vectors_square(const Point& lhs,
                                                const Point& rhs) {
        return std::abs(oriented_triangle_on_vectors_square(lhs, rhs));
    }

    inline friend ld triangle_on_points_square(const Point& first,
            const Point& second, const Point& third) {
        return triangle_on_vectors_square(second - first, third - first);
    }

    inline bool operator ==(const Point& rhs) const {
        return distance(*this, rhs) < EPS;
    }

    inline friend bool operator <(const Point& lhs, const Point& rhs) {
        if (lhs.first_ < rhs.first_ - EPS) {
            return true;
        } else if (std::abs(lhs.first_ - rhs.first_) < EPS) {
            return lhs.second_ < rhs.second_ - EPS;
        } else {
            return false;
        }
    }

    inline ld get_first() const {
        return first_;
    }

    inline ld get_second() const {
        return second_;
    }

    friend std::istream& operator >>(std::istream& input, Point& pt) {
        input >> pt.first_ >> pt.second_;
        return input;
    }

    friend std::ostream& operator <<(std::ostream& output, const Point& pt) {
        output << pt.first_ << " " << pt.second_;
        return output;
    }
};

class Line {
    typedef long double ld;
    static constexpr ld EPS = 3 * std::numeric_limits<double>::epsilon();

private:
    ld first_;
    ld second_;
    ld free_;

    inline void normalize() {
        ld norm = sqrtl(first_ * first_ + second_ * second_);
        if (first_ < -EPS) {
            norm = -norm;
        } else if (first_ < EPS) {
            norm = second_;
        }
        first_ /= norm;
        second_ /= norm;
        free_ /= norm;
    }

public:
    Line (ld first, ld second, ld free)
        : first_(first)
        , second_(second)
        , free_(free) {
            normalize();
    }

    inline ld operator() (const Point& pt) const {
        return first_ * pt.get_first() + second_ * pt.get_second() + free_;
    }

    inline bool operator ==(const Line& rhs) const {
        return std::abs(this->first_ - rhs.first_) < EPS &&
               std::abs(this->second_ - rhs.second_) < EPS &&
               std::abs(this->free_ - rhs.free_) < EPS;
    }

    friend std::istream& operator >>(std::istream& input, Line& ln) {
        input >> ln.first_ >> ln.second_ >> ln.free_;
        return input;
    }

    friend std::ostream& operator <<(std::ostream& output, const Line& ln) {
        output << ln.first_ << " " << ln.second_ << ln.free_;
        return output;
    }
};



class Segment {
    typedef long double ld;

private:
    Point first_;
    Point second_;

public:
    Segment (const Point& first, const Point& second)
        : first_(first)
        , second_(second) {
    }

    inline ld length() const {
        return distance(first_, second_);
    }

    inline bool operator ==(const Segment& rhs) const {
        return (first_ == rhs.first_ && second_ == rhs.second_);
        

        

    }

    inline bool operator <(const Segment& rhs) const {
        return std::make_pair(first_, second_) <
               std::make_pair(rhs.first_, rhs.second_);
    }

    inline Line make_line() const {
        Point difference = first_ - second_;
        ld coeff_first = difference.get_second();
        ld coeff_second = -difference.get_first();
        ld coeff_free = 0.0 - coeff_first * first_.get_first() -
                        coeff_second * first_.get_second();
        return Line(coeff_first, coeff_second, coeff_free);
    }

    inline Point get_first() const {
        return first_;
    }

    inline Point get_second() const {
        return second_;
    }

    friend std::istream& operator >>(std::istream& input, Segment& sgm) {
        input >> sgm.first_ >> sgm.second_;
        return input;
    }

    friend std::ostream& operator <<(std::ostream& output, const Segment& sgm) {
        output << sgm.first_ << " " << sgm.second_;
        return output;
    }
};

long double DistanceFromPointToLine(const Point& pt, const Line& line) {
    return line(pt);
}

long double DistanceFromPointToSegment(const Point& pt, const Segment& sgm) {
    static constexpr long double EPS =
        3 * std::numeric_limits<double>::epsilon();
    Point first = sgm.get_first();
    Point second = sgm.get_second();
    if (scalar(second - first, pt - first) > EPS &&
        scalar(first - second, pt - second) > EPS) {
        return DistanceFromPointToLine(pt, sgm.make_line());
    } else {
        return std::min(distance(first, pt), distance(second, pt));
    }
}

class Triangle {
    typedef long double ld;

private:
    Point first_;
    Point second_;
    Point third_;

public:
    Triangle (const Point& first, const Point& second, const Point& third)
        : first_(first)
        , second_(second)
        , third_(third) {
    }

    inline ld triangle_square() const {
        return triangle_on_points_square(first_, second_, third_);
    }

    friend std::istream& operator >>(std::istream& input, Triangle& tri) {
        input >> tri.first_ >> tri.second_ >> tri.third_;
        return input;
    }

    friend std::ostream& operator <<(std::ostream& output, const Triangle& tri) {
        output << tri.first_ << " " << tri.second_ << " " << tri.third_;
        return output;
    }
};

class Polygon {
    typedef long double ld;

private:
    std::vector<Point> points_;
    static constexpr long double EPS =
        3 * std::numeric_limits<double>::epsilon();

public:
    explicit Polygon (const std::vector<Point>& points = std::vector<Point> (0))
        : points_(points) {}

    inline ld polygon_square() const {
        ld ans = 0.0;
        for (size_t i = 2; i < points_.size(); ++i) {
            ans += Triangle(points_[0], points_[1], points_[i]).triangle_square();
        }
        return ans;
    }

    

    

    

    

    

    

    

    

    

    

    

    

    

            

            

            

            

            

            

            

    

    

    

    

    


    friend std::istream& operator >>(std::istream& input, Polygon& poly) {
        size_t num;
        input >> num;
        poly.points_.resize(num);
        for (auto&& pt: poly.points_) {
            input >> pt;
        }
        return input;
    }

    friend std::ostream& operator <<(std::ostream& output, const Polygon& poly) {
        

        for (auto&& pt: poly.points_) {
            output << pt << "\n";
        }
        return output;
    }
};

class HashNum {
    typedef long long ll;
    typedef unsigned long long ull;

private:
    int a_, b_;
    static constexpr int MA = 1e9 + 7, MB = 1e9 + 9;

public:
    explicit HashNum()
        : a_(0)
        , b_(0) {}

    explicit HashNum(int num)
        : a_(num)
        , b_(num) {}

    HashNum(int first, int second)
        : a_(first)
        , b_(second) {}

    inline HashNum operator +(const HashNum& rhs) const {
        return HashNum((a_ + rhs.a_) % MA, (b_ + rhs.b_) % MB);
    }

    inline HashNum operator -(const HashNum& rhs) const {
        return HashNum((a_ - rhs.a_ + MA) % MA, (b_ - rhs.b_ + MB) % MB);
    }

    inline HashNum operator *(int num) const {
        HashNum ans(*this);
        ans = ans * HashNum(num);
        return ans;
    }

    inline HashNum operator *(const HashNum& rhs) const {
        return HashNum(((ll)a_ * rhs.a_) % MA, ((ll)b_ * rhs.b_) % MB);
    }

    inline bool operator == (const HashNum& rhs) const {
        return a_ == rhs.a_ && b_ == rhs.b_;
    }

    inline bool operator < (const HashNum& rhs) const {
        return std::make_pair(a_, b_) < std::make_pair(rhs.a_, rhs.b_);
    }

    inline explicit operator ll () const {
        return (ll)a_ * MB + b_ + 1;
    } 


    

    

    

    

    


    friend std::ostream& operator <<(std::ostream& output, const HashNum& hash) {
        output << hash.a_ << " " << hash.b_;
        return output;
    }
};


























template <class Hash_Type>
class StrComparator {
private:
    static const int VAR_;
    static std::vector<Hash_Type> deg_;
    std::string text_;
    std::vector<Hash_Type> hash_;

public:
    explicit StrComparator(const std::string& str)
        : text_(str)
        , hash_(1, Hash_Type(0)) {
        hash_.reserve(text_.size() + 1);
        for (size_t i = 0; i < text_.size(); ++i) {
            hash_[i + 1] = hash_[i] * VAR_ + HashNum(text_[i]);
        }
        deg_.reserve(text_.size());
        while (deg_.size() <= text_.size()) {
            deg_.push_back(deg_.back() * VAR_);
        }
    }

    Hash_Type substr(size_t pos, size_t len) const {
        return hash_[pos + len] - hash_[pos] * deg_[len];
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
        return lcp_length < len ? text_[lhs + lcp_length] < text_[rhs + lcp_length] : rhs < lhs;
    }

    inline HashNum operator() () const {
        return substr(0, text_.size());
    }
};

template <class Hash_Type> std::vector<Hash_Type>
    StrComparator<Hash_Type>::deg_(1, Hash_Type(1));
template <class Hash_Type> const int
    StrComparator<Hash_Type>::VAR_ = std::max(239, rand());

inline std::vector<size_t> SuffixArray(const std::string& str) {
    StrComparator<HashNum> hash(str);
    std::vector<size_t> suffix_array(str.size());
    std::iota(suffix_array.begin(), suffix_array.end(), 0);
    std::sort(suffix_array.begin(), suffix_array.end(), [&] (size_t lhs, size_t rhs) {
        return hash.cmp(lhs, rhs);
    });
    return suffix_array;
}

void LowerString(std::string& text) {
    std::transform(text.begin(), text.end(), text.begin(), ::tolower);
}

void UpperString(std::string& text) {
    std::transform(text.begin(), text.end(), text.begin(), ::toupper);
}

void ReverseString(std::string& text) {
    std::reverse(text.begin(), text.end());
}

std::vector<int> TextIsSumOfOthers(const std::string& text,
                                   const std::vector<std::string>& samples) {
    std::unordered_map<long long, size_t> samples_hashes;
    size_t max_length = 0;
    for (size_t i = 0; i < samples.size(); ++i) {
        auto hash = StrComparator<HashNum>(samples[i]);
        samples_hashes[static_cast<long long>(hash())] = i;
        max_length = std::max(max_length, samples[i].size());
    }
    auto text_hash = StrComparator<HashNum> (text);
    std::vector<int> prev(text.size(), -1);
    for (size_t current_pos = 0; current_pos < text.size(); ++current_pos) {
        for (int j = std::max(static_cast<int>(current_pos) -
                              static_cast<int>(max_length), 0) - 1;
                              j < static_cast<int>(current_pos); ++j) {
            if (j == -1 || prev[j] != -1) {
                auto it = samples_hashes.find(
                    static_cast<long long>(text_hash.substr(j + 1, current_pos - j)));
                if (it != samples_hashes.end()) {
                    prev[current_pos] = it->second;
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

    explicit FenwickTree(Index size)
        : sums_(size, 0)
    {}

    

    void initialize(std::vector<int> numbers) {
        

        std::partial_sum(numbers.begin(), numbers.end(), numbers.begin());
        sums_.resize(numbers.size());
        for (Index i = 0; i < size(); ++i) {
            sums_[i] = numbers[i];
            Index previousI = previousIndex(i);
            if (previousI > 0) {
                sums_[i] -= numbers[previousI - 1];
            }
        }
    }

    void add(Index index, int value) {
        while (index < size()) {
            sums_[index] += value;
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
            ? sums_.at(lastIndex) + sum(previousIndex(lastIndex) - 1)
            : 0;
    }

    

    

    static Index previousIndex(Index index) {
        return index & (index + 1);
    }

    std::vector<int> sums_;
};

std::vector<size_t> GetPrefixFunction(const std::string& str) {
    std::vector<size_t> ans(str.size(), 0);
    for (size_t index = 1; index < ans.size(); ++index) {
        size_t cur = ans[index - 1];
        while (cur > 0 && str[index] != str[cur]) {
            cur = ans[cur - 1];
        }
        ans[index] = cur + (str[index] == str[cur]);
    }
    return ans;
}

std::vector<size_t> GetZFunction(const std::string& str) {
    std::vector<size_t> ans(str.size(), str.size());

    size_t left = 0;
    size_t right = 0;

    for (size_t index = 1; index < ans.size(); ++index) {
        size_t checked = 0;
        if (index <= right) {
            checked = std::min(ans[index - left], right - index + 1);
        }
        while (index + checked < str.size() && str[index + checked] == str[checked]) {
            ++checked;
        }
        ans[index] = checked;
        if (index + ans[index] - 1 >= right) {
            left = index;
            right = index + ans[index] - 1;
        }
    }

    return ans;
}

bool IsPeriodic(const std::string& str, size_t check) {
    for (size_t index = 0; index < str.size(); ++index) {
        if (str[index] != str[index % check]) {
            return false;
        }
    }
    return true;
}

size_t MinPeriod(const std::string& str) {
    for (size_t i = 1; i <= str.size(); ++i) {
        if (str.size() % i == 0 && IsPeriodic(str, i)) {
            return i;
        }
    }
    return str.size();
}

class Graph {
private:
    std::vector<std::vector<size_t>> outgoing_edges_;
    std::vector<std::vector<size_t>> layernet_edges_;
    std::vector<std::vector<size_t>> capacity_matrix_;
    std::vector<size_t> source_distance_;
    std::vector<std::pair<size_t*, size_t>> changes_buffer_;

    static const long long LONGINF;
    static const size_t INF;

    bool BuildLayernet(size_t source, size_t target, size_t min_capacity) {
        source_distance_.assign(GetVerticesNum(), INF);
        std::queue<size_t> bfs_queue;
        source_distance_[source] = 0;
        bfs_queue.push(source);
        while (!bfs_queue.empty()) {
            size_t from = bfs_queue.front();
            for (auto to : outgoing_edges_[from]) {
                if (source_distance_[to] == INF && capacity_matrix_[from][to] >= min_capacity) {
                    source_distance_[to] = source_distance_[from] + 1;
                    bfs_queue.push(to);
                }
            }
            bfs_queue.pop();
        }
        if (source_distance_[target] == INF) {
            return false;
        }
        for (size_t from = 0; from < GetVerticesNum(); ++from) {
            layernet_edges_[from].clear();
            for (auto to : outgoing_edges_[from]) {
                if (source_distance_[from] + 1 == source_distance_[to] &&
                    capacity_matrix_[from][to] >= min_capacity) {
                    layernet_edges_[from].push_back(to);
                }
            }
        }
        return true;
    }

    long long FindBlockingFlow (size_t vertex, size_t target, long long flow) {
        if (vertex == target) {
            return flow;
        }
        long long total_flow = 0;
        while (!layernet_edges_[vertex].empty()) {
            size_t to = layernet_edges_[vertex].back();
            long long push = FindBlockingFlow(to, target,
                std::min(flow, static_cast<long long>(capacity_matrix_[vertex][to])));
            if (push > 0) {
                total_flow += push;
                flow -= push;
                capacity_matrix_[vertex][to] -= static_cast<size_t>(push);
                changes_buffer_.emplace_back(&capacity_matrix_[to][vertex], push);
            }
            if (flow == 0) {
                return total_flow;
            } else {
                layernet_edges_[vertex].pop_back();
            }
        }
        return total_flow;
    }

    long long DinicIteration(size_t source, size_t target, size_t min_capacity) {
        long long ans = 0;
        while (BuildLayernet(source, target, min_capacity)) {
            ans += FindBlockingFlow(source, target, LONGINF);
            while (!changes_buffer_.empty()) {
                size_t* dest;
                size_t delta;
                std::tie(dest, delta) = changes_buffer_.back();
                *dest += delta;
                changes_buffer_.pop_back();
            }
        }
        return ans;
    }

public:
    explicit Graph (size_t num = 0)
        : outgoing_edges_(num, std::vector<size_t> (0))
        , layernet_edges_(0)
        , capacity_matrix_(0)
        , source_distance_(0)
        , changes_buffer_(0) {
    }

    void InitFlowSearch() {
        size_t num = GetVerticesNum();
        layernet_edges_.assign(num, std::vector<size_t> (0));
        capacity_matrix_.assign(num, std::vector<size_t> (num, 0));
    }

    size_t GetVerticesNum() const {
        return outgoing_edges_.size();
    }

    void AddEdge(size_t from, size_t to, size_t capacity) {
        outgoing_edges_[from].push_back(to);
        capacity_matrix_[from][to] = capacity;
    }

    void AddEdge(size_t from, size_t to) {
        outgoing_edges_[from].push_back(to);
    }

    size_t Degree(size_t vertex) const {
        return outgoing_edges_[vertex].size();
    }

    const std::vector<size_t>& GetAdjacentVertices(size_t vertex) const {
        return outgoing_edges_[vertex];
    }

    long long FindMaxFlow(size_t source, size_t target, bool scaling) {
        long long ans = 0;
        if (scaling) {
            size_t max_capacity = 0;
            for (size_t from = 0; from < GetVerticesNum(); ++from) {
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
                ans += DinicIteration(source, target, push_capacity);
            }
        } else {
            ans = DinicIteration(source, target, 1);
        }
        return ans;
    }
};

const long long Graph::LONGINF(std::numeric_limits<long long>::max());
const size_t Graph::INF(std::numeric_limits<size_t>::max());

Graph ReadGraph(std::istream& input_stream) {
    size_t vertices_num, edges_num;
    input_stream >> vertices_num >> edges_num;
    Graph ans(vertices_num);
    ans.InitFlowSearch();
    for (size_t i = 0; i < edges_num; ++i) {
        size_t first, second, result;
        input_stream >> first >> second >> result;
        --first;
        --second;
        ans.AddEdge(second, first, result);
        ans.AddEdge(first, second, result);
    }
    return ans;
}



Graph ReverseEdges(const Graph& graph) {
    Graph ans(graph.GetVerticesNum());
    for (size_t from = 0; from < graph.GetVerticesNum(); ++from) {
        for (auto to : graph.GetAdjacentVertices(from)) {
            ans.AddEdge(to, from);
        }
    }
    return ans;
}





template <class AnyGraph, class Vertex, class Callback>
void DFS(const AnyGraph& graph, const Vertex& vertex,
    std::vector<bool>& visited_vertices, Callback call) {
    visited_vertices[vertex] = true;
    for (const auto& to : graph.GetAdjacentVertices(vertex)) {
        if (!visited_vertices[to]) {
            DFS(graph, to, visited_vertices, call);
        }
    }
    call(vertex);
}



Graph FindCondensation(const Graph& graph, std::vector<size_t>& equals_num) {
    std::vector<bool> visited_vertices(graph.GetVerticesNum(), false);
    std::stack<size_t> vertices_sorted_by_finish;
    for (size_t i = 0; i < graph.GetVerticesNum(); ++i) {
        if (!visited_vertices[i]) {
            DFS(graph, i, visited_vertices, [&](size_t cur_vertex) {
                vertices_sorted_by_finish.push(cur_vertex);
            });
        }
    }
    std::fill(visited_vertices.begin(), visited_vertices.end(), false);
    Graph reoriented_graph = ReverseEdges(graph);
    size_t components_num = 0;
    std::vector<size_t> equality_class(graph.GetVerticesNum());
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
    for (size_t from = 0; from < graph.GetVerticesNum(); ++from) {
        for (size_t to : graph.GetAdjacentVertices(from)) {
            if (equality_class[from] != equality_class[to]) {
                ans.AddEdge(equality_class[from], equality_class[to]);
            }
        }
    }
    return ans;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cout << std::fixed << std::setprecision(7);
    size_t n, q;
    std::cin >> n >> q;
    std::string s;
    std::cin >> s;
    std::vector<std::vector<int>> v(26, std::vector<int> (n, 0));
    for (size_t i = 0; i < n; i++) {
        ++v[s[i] - 'a'][i];
    }
    auto TwoIntsSum = [] (int lhs, int rhs) {return lhs + rhs;};
    auto EqualIntsSum = [] (int val, size_t num) {return val * num;};

    std::vector<SegmentTree<int, decltype(TwoIntsSum), decltype(EqualIntsSum)>> tree;
    for (size_t i = 0; i < 26; i++) {
        tree.emplace_back(v[i], TwoIntsSum, EqualIntsSum);
    }

    for (size_t l = 0; l < q; ++l) {
        size_t left, right, ty;
        std::cin >> left >> right >> ty;
        --left;
        std::vector<int> a(26, 0);
        for (size_t j = 0; j < 26; j++) {
            a[j] = tree[j].Get(left, right);
            tree[j].Set(left, right, 0);
        }
        if (ty) {
            for (size_t j = 0; j < 26; j++) {
                tree[j].Set(left, left + a[j], 1);
                left += a[j];
            }
        } else {
            for (size_t j = 0; j < 26; j++) {
                tree[25 - j].Set(left, left + a[25 - j], 1);
                left += a[25 - j];
            }
        }
    }

    for (size_t i = 0; i < 26; i++) {
        for (size_t j = 0; j < n; j++) {
            if (tree[i].Get(j) == 1) {
                s[j] = i + 'a';
            }
        }
    }
    std::cout << s << std::endl;

    return 0;
}
