

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

using std::vector;
using std::string;
using std::cin;
using std::cout;
using std::function;
using std::max;


int CorrectBrackets(const std::string & text) {
    std::stack<size_t> stack;
    for (size_t curr = 0; curr < text.size(); ++curr) {
        auto curr_bracket = text[curr];
        if (curr_bracket == '(' || curr_bracket == '[' || curr_bracket == '{') {
            stack.push(curr);
        } else {
            if (stack.empty()) {
                return curr;
            }
            size_t last = stack.top();
            stack.pop();
            if ((curr_bracket == ')' && text[last] != '(') ||
                (curr_bracket == ']' && text[last] != '[') ||
                (curr_bracket == '}' && text[last] != '{')) {
                return curr;
            }
        }
    }
    return (stack.size()) ? text.size() : -1;
}

template <typename T_Type>


const T_Type MyMax(const T_Type& lhs, const T_Type& rhs) {
    return std::max(lhs, rhs);
}



template <typename T_Type>
class SparseTree {
    typedef function<const T_Type(const T_Type&, const T_Type&)> func_type;

private:
    std::vector<int> m_log;
    std::vector<std::vector<T_Type>> m_sparse;
    func_type m_func;

public:
    SparseTree(const std::vector<T_Type>& mass,
               func_type func = MyMax<T_Type>)
        : m_log(2, 0)
        , m_sparse(0)
        , m_func(func) {
        int len = mass.size();
        m_log = {2, 0};
        size_t pow = 1;
        while ((1 << pow) < 5 * len) {
            m_log.insert(m_log.end(), 1 << pow, pow);
            ++pow;
        }

        for (int pow = 0; pow <= m_log[len]; ++pow) {
            m_sparse.push_back(std::vector<T_Type> (len));
            for (int j = 0; j < len; ++j) {
                if (pow == 0) {
                    m_sparse[pow][j] = m_func(mass[j], mass[j]);
                } else {
                    m_sparse[pow][j] = m_func(m_sparse[pow - 1][j],
                                              m_sparse[pow - 1][std::min(j + (1 << (pow - 1)),
                                                                         len - 1)]);
                }
            }
        }
    }

    inline T_Type GetAns(size_t left, size_t right) const {
        return m_func(m_sparse[m_log[right - left]][left],
                      m_sparse[m_log[right - left]][right - (1 << m_log[right - left])]);
    }
};



template <typename T_Type>
int Common(const std::vector<T_Type>& firstarr, const std::vector<T_Type>& secondarr) {
    std::vector<size_t> curr(secondarr.size(), 0);
    curr[0] = static_cast<size_t>(firstarr[0] == secondarr[0]);
    for (size_t j = 1; j < secondarr.size(); ++j) {
        curr[j] = std::max(curr[j - 1], static_cast<size_t>(firstarr[0] == secondarr[j]));
    }

    for (size_t i = 1; i < firstarr.size(); ++i) {
        auto prev = curr;
        curr[0] = std::max(prev[0], static_cast<size_t>(firstarr[i] == secondarr[0]));
        for (size_t j = 1; j < secondarr.size(); ++j) {
            curr[j] = std::max(prev[j], curr[j - 1]);
            curr[j] = std::max(curr[j], prev[j - 1] +
                                        static_cast<size_t>(firstarr[i] == secondarr[j]));
        }
    }

    return curr.back();
}

template <class Iterator>
Iterator Partition(Iterator first, Iterator last) {
    static std::mt19937 generator;
    std::uniform_int_distribution<> uid(0, static_cast<int>(last - first - 1));
    auto pivot_value = *(first + uid(generator));

    Iterator left = first;
    Iterator right = last - 1;
    while (left < right) {
        while (left <= right && *left >= pivot_value) {
            ++left;
        }
        while (right >= left && *right < pivot_value) {
            --right;
        }
        if (left < right) {
            std::iter_swap(left, right);
        }
    }

    if (*(left - 1) == pivot_value) {
        Iterator bestleft = left - 1;
        while (bestleft > first && *(bestleft - 1) == pivot_value) {
            --bestleft;
        }
        std::uniform_int_distribution<> uid_ans(0, static_cast<size_t>(left - bestleft));
        return uid_ans(generator) + bestleft;
    } else {
        return left;
    }
}

template <class Iterator>
void QuickSort(Iterator first, Iterator last) {
    if (first + 1 < last) {
        Iterator mid = Partition(first, last);
        QuickSort(first, mid);
        QuickSort(mid, last);
    }
}

template <class Iterator>
void ReorderKth(Iterator first, Iterator last, size_t kth) {
    while (first + 1 < last) {
        Iterator mid = Partition(first, last);
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
long long MergeTwoParts(Iterator left, Iterator mid, Iterator right,
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
long long MergeSort(Iterator left, Iterator right, long long diff = 0, size_t mergesize = 1) {
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
long double bin_search(long double left, long double right,
                       Function_Type func,
                       long double searching, Compare comp = std::less<long double>()) {
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

void FFT(std::vector<std::complex<long double>>& arr, bool invert) {
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
std::vector<std::complex<long double>> MultiplyPolinoms(const std::vector<Input_Type>& first,
                                                   const std::vector<Input_Type>& second) {
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

std::vector<int> MultiplyIntPolinoms(const std::vector<int>& first,
                                     const std::vector<int>& second) {
    auto ans = MultiplyPolinoms(first, second);
    std::vector<int> int_ans(ans.size());
    for (size_t i = 0; i < ans.size(); ++i) {
        int_ans[i] = round(ans[i].real());
    }
    return int_ans;
}



struct Segment {
    int left;
    int right;
    int heap_position;
};

class Cmp {
public:
    bool operator() (const Segment& lhs, const Segment& rhs) {
        return (lhs.right - lhs.left > rhs.right - rhs.left ||
                (lhs.right - lhs.left == rhs.right - rhs.left && lhs.left < rhs.left));
    }
};

template <typename T, class Cmp>
class Heap {
private:
    Cmp m_cmp;
    std::vector<T> m_data;

public:
    Heap(Cmp cmp = Cmp())
        : m_cmp(cmp)
        , m_data() {
    }

    inline bool IsEmpty() const {
        return (m_data.size() == 0);
    }

    

    inline void UpdateElement(size_t position) {
        if (position < m_data.size()) {
            SiftDown(position);
            SiftUp(position);
        }
    }

    inline void DeleteElement(int position) {
        Swap(position, m_data.size() - 1);
        (*m_data[m_data.size() - 1]).heap_position = -1;
        m_data.pop_back();
        UpdateElement(position);
    }

    inline void AddElement(T key) {
        m_data.push_back(key);
        (*key).heap_position = m_data.size() - 1;
        SiftUp(m_data.size() - 1);
    }

    inline T GetRoot() const {
        return m_data[0];
    }

    inline void Swap(int first, int second) {
        std::swap(m_data[first], m_data[second]);
        (*m_data[first]).heap_position = first;
        (*m_data[second]).heap_position = second;
    }

    inline void SiftUp(int current) {
        while (current != 0) {
            if (!m_cmp(*m_data[(current - 1) / 2], *m_data[current])) {
                Swap((current - 1) / 2, current);
                current = (current - 1) / 2;
            } else {
                break;
            }
        }
    }

    inline void SiftDown(size_t current) {
        while (2 * current + 1 < m_data.size()) {
            if (2 * current + 2 < m_data.size()) {
                if (!m_cmp(*m_data[current], *m_data[2 * current + 1]) ||
                    !m_cmp(*m_data[current], *m_data[2 * current + 2])) {
                    if (m_cmp(*m_data[2 * current + 1], *m_data[2 * current + 2])) {
                        Swap(current, 2 * current + 1);
                        current = 2 * current + 1;
                    } else {
                        Swap(current, 2 * current + 2);
                        current = 2 * current + 2;
                    }
                } else {
                    break;
                }
            } else if (!m_cmp(*m_data[current], *m_data[2 * current + 1])) {
                Swap(current, 2 * current + 1);
                current = 2 * current + 1;
            } else {
                break;
            }
        }
    }
};

template <typename T_Type>
const T_Type MyMult(const T_Type& lhs, const T_Type& rhs) {
    return lhs * rhs;
}

template <typename T_Type>
T_Type BinPow(T_Type base,
              unsigned long long exponent,
              T_Type modulo,
              std::function<const T_Type(const T_Type&, const T_Type&)> func = MyMult<T_Type>,
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



std::vector<size_t> RepresentInBaseTwo(unsigned long long num) {
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
const T_Type GCD(T_Type first, T_Type second) {
    first = std::abs(first);
    second = std::abs(second);
    while (first != 0 && second != 0) {
        auto other = first % second;
        first = second;
        second = other;
    }
    return first + second;
}

template <typename T_Type>
const std::vector<T_Type> InputVector() {
    size_t len;
    std::cin >> len;
    std::vector<T_Type> arr(len);
    for (size_t i = 0; i < len; ++i) {
        std::cin >> arr[i];
    }
    return arr;
}



template <typename T_Type>
inline const T_Type MySum(const T_Type& lhs, const T_Type& rhs) {
    return lhs + rhs;
}



template <typename T_Type>
inline const T_Type MyMultipleSum(const T_Type& val, size_t num) {
    return val * num;
}

template <typename T_Type>
class SegmentTree {
    typedef function<const T_Type(const T_Type&, const T_Type&)> func_type;
    typedef function<const T_Type(const T_Type&, size_t)> multiple_func_type;
private:
    std::vector<T_Type> m_data;
    std::vector<bool> m_has_changed;
    size_t m_real_size;
    func_type m_func;
    multiple_func_type m_multiple_func;
    T_Type m_default_val;

    inline T_Type GetData(size_t vertex, size_t left, size_t right) const {
        if (m_has_changed[vertex]) {
            return m_multiple_func(m_data[vertex], right - left);
        } else {
            return m_data[vertex];
        }
    }

    inline void Push(size_t vertex) {
        if (m_has_changed[vertex]) {
            m_data[2 * vertex + 1] = m_data[2 * vertex + 2] = m_data[vertex];
            m_has_changed[vertex] = false;
            m_has_changed[2 * vertex + 1] = m_has_changed[2 * vertex + 2] = true;
        }
    }

    void BuildRecursive(const std::vector<T_Type>& data, size_t vertex,
                        size_t left, size_t right) {
        if (left + 1 == right) {
            m_data[vertex] = data[left];
        } else {
            size_t mid = (left + right) / 2;
            BuildRecursive(data, 2 * vertex + 1, left, mid);
            BuildRecursive(data, 2 * vertex + 2, mid, right);
            m_data[vertex] = m_func(m_data[2 * vertex + 1], m_data[2 * vertex + 2]);
        }
    }

    

    

    void SetRecursive(size_t vertex, size_t left, size_t right,
                      size_t from, size_t to, T_Type val) {
        if (from >= right || left >= to) {
            return;
        }
        if (left == from && right == to) {
            m_data[vertex] = val;
            m_has_changed[vertex] = true;
        } else {
            Push(vertex);
            size_t mid = (left + right) / 2;
            SetRecursive(2 * vertex + 1, left, mid, from, std::min(to, mid), val);
            SetRecursive(2 * vertex + 2, mid, right, std::max(from, mid), to, val);
            m_data[vertex] = m_func(GetData(2 * vertex + 1, left, mid),
                                    GetData(2 * vertex + 2, mid, right));
        }
    }

    T_Type GetRecursive(size_t vertex, size_t left, size_t right,
                        size_t from, size_t to) {
        if (from >= right || left >= to) {
            

            return m_default_val;
        }
        if (left == from && right == to) {
            

            return GetData(vertex, left, right);
        } else {
            Push(vertex);
            size_t mid = (left + right) / 2;
            

            T_Type left_ans = GetRecursive(2 * vertex + 1, left, mid, from, std::min(to, mid));
            T_Type right_ans = GetRecursive(2 * vertex + 2, mid, right, std::max(from, mid), to);
            m_data[vertex] = m_func(GetData(2 * vertex + 1, left, mid),
                                    GetData(2 * vertex + 2, mid, right));
            return m_func(left_ans, right_ans);
        }
    }

public:
    SegmentTree(const std::vector<T_Type>& data, func_type func = MySum<T_Type>,
                multiple_func_type multiple_func = MyMultipleSum<T_Type>,
                T_Type default_val = T_Type(0))
        : m_data()
        , m_has_changed()
        , m_real_size(data.size())
        , m_func(func)
        , m_multiple_func(multiple_func)
        , m_default_val(default_val) {
        size_t good_size = 1;
        while (good_size < m_real_size) {
            good_size <<= 1;
        }
        m_data.resize(2 * good_size, m_default_val);
        m_has_changed.resize(2 * good_size, false);
        BuildRecursive(data, 0, 0, m_real_size);
    }

    inline void Print() {
        for (size_t i = 0; i < m_data.size(); ++i) {
            std::cout << i << " " << m_data[i] << " "<< m_has_changed[i] << " " << std::endl;
        }
        std::cout << std::endl << std::endl;
    }

    

    inline void Set(size_t left, size_t right, T_Type val) {
        SetRecursive(0, 0, m_real_size, left, right, val);
    }

    inline void Set(size_t pos, T_Type val) {
        Set(pos, pos + 1, val);
    }

    inline const T_Type Get(size_t left, size_t right) {
        return GetRecursive(0, 0, m_real_size, left, right);
    }

    inline const T_Type Get(size_t pos) {
        return Get(pos, pos + 1);
    }

    inline const T_Type Get() {
        return GetRecursive(0, 0, m_real_size, 0, m_real_size);
    }
};

int main() {
    

    

    size_t n, q;
    std::cin >> n >> q;
    std::string s;
    std::cin >> s;
    std::vector<std::vector<int>> v(26, std::vector<int> (n, 0));
    for (size_t i = 0; i < n; i++) {
        ++v[s[i] - 'a'][i];
    }
    std::vector<SegmentTree<int>> tree;
    for (size_t i = 0; i < 26; i++) {
        tree.emplace_back(SegmentTree<int> (v[i]));
    }

    for (size_t l = 0; l < q; ++l) {
        int left, right, ty;
        scanf("%d%d%d", &left, &right, &ty);
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
    cout << s << std::endl;

    return 0;
}
