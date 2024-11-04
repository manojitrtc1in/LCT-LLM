


















int id3(const std::string & text) {
    std::stack<size_t> stack;
    for (size_t curr = 0; curr < text.size(); ++curr) {
        auto id9 = text[curr];
        if (id9 == '(' || id9 == '[' || id9 == '{') {
            stack.push(curr);
        } else {
            if (stack.empty()) {
                return curr;
            }
            size_t last = stack.top();
            stack.pop();
            if ((id9 == ')' && text[last] != '(') ||
                (id9 == ']' && text[last] != '[') ||
                (id9 == '}' && text[last] != '{')) {
                return curr;
            }
        }
    }
    return (stack.size()) ? text.size() : -1;
}











template <typename T_Type, typename Function_Type>
class SparseTree {
private:
    std::vector<int> m_log;
    std::vector<std::vector<T_Type>> m_sparse;
    Function_Type& m_func;

public:
    SparseTree(const std::vector<T_Type>& mass,
               Function_Type& func)
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
inline int Common(const std::vector<T_Type>& firstarr, const std::vector<T_Type>& secondarr) {
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
inline Iterator Partition(Iterator first, Iterator last) {
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
inline void id4(Iterator first, Iterator last, size_t kth) {
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
inline long long id2(Iterator left, Iterator mid, Iterator right,
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
                           long long diff = 0, size_t id8 = 1) {
    typedef typename std::iterator_traits<Iterator>::value_type value_type;
    std::vector<value_type> id6(static_cast<size_t> (right - left));
    long long result = 0;
    while (id8 < id6.size()) {
        Iterator from = left;
        while (from + id8 < right) {
            result += id2(from, from + id8,
                                    std::min(from + 2 * id8, right),
                                    id6.begin(), diff);
            from += 2 * id8;
        }
        id8 *= 2;
    }
    return result;
}

template <typename Compare, typename function_Type>
inline long double bin_search(long double left, long double right,
                       function_Type func,
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
inline std::vector<std::complex<long double>> id5(const std::vector<Input_Type>& first,
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

inline std::vector<int> id0(const std::vector<int>& first,
                                     const std::vector<int>& second) {
    auto ans = id5(first, second);
    std::vector<int> int_ans(ans.size());
    for (size_t i = 0; i < ans.size(); ++i) {
        int_ans[i] = round(ans[i].real());
    }
    return int_ans;
}






























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
inline const T_Type MyMult(const T_Type& lhs, const T_Type& rhs) {
    return lhs * rhs;
}

template <typename T_Type>
inline T_Type BinPow(T_Type base,
              unsigned long long exponent,
              T_Type modulo = std::numeric_limits<T_Type>::max(),
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



inline std::vector<size_t> id1(unsigned long long num) {
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
        auto other = first % second;
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

template <typename T_Type, typename Function_Type, typename MultipleFunction_Type>
class SegmentTree {
private:
    std::vector<T_Type> m_data;
    std::vector<bool> m_has_changed;
    size_t m_real_size;
    Function_Type& m_func;
    MultipleFunction_Type& m_multiple_func;
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

    inline void Update(size_t vertex, size_t left, size_t right) {
        size_t mid = (left + right) / 2;
        m_data[vertex] = m_func(GetData(2 * vertex + 1, left, mid),
                                GetData(2 * vertex + 2, mid, right));
        m_has_changed[vertex] = false;
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
            Update(vertex, left, right);
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
            Update(vertex, left, right);
            return m_func(left_ans, right_ans);
        }
    }

public:
    SegmentTree(const std::vector<T_Type>& data, Function_Type& func,
                MultipleFunction_Type& multiple_func,
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
            std::cout << i << " " << m_data[i] << " " << m_has_changed[i] << " " << std::endl;
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
    auto id10 = [] (int lhs, int rhs) {return lhs + rhs;};
    auto id7 = [] (int val, size_t num) {return val * num;};

    std::vector<SegmentTree<int, decltype(id10), decltype(id7)>> tree;
    for (size_t i = 0; i < 26; i++) {
        tree.emplace_back(v[i], id10, id7);
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
