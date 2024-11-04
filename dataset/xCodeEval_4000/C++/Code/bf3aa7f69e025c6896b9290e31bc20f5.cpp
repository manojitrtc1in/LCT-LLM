#include <bits/stdc++.h>
#ifdef OY_LOCAL
#include <windows.h>


#include <psapi.h>
#endif
#define all(a) std::begin(a), std::end(a)
#define rall(a) std::rbegin(a), std::rend(a)
template <typename _Tp, typename _Fp, typename _Compare = std::less<void>>
bool chmax(_Tp &a, const _Fp &b, _Compare __comp = _Compare()) { return __comp(a, b) ? a = b, true : false; }
template <typename _Tp, typename _Fp, typename _Compare = std::less<void>>
bool chmin(_Tp &a, const _Fp &b, _Compare __comp = _Compare()) { return __comp(b, a) ? a = b, true : false; }
#define YESNO(condition) \
    if (condition)       \
        cout << "YES\n"; \
    else                 \
        cout << "NO\n";
using std::cin, std::cout, std::endl;
auto tam = [] {
    std::ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifdef OY_LOCAL
#define CHECKTIME tam.stop()
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    struct TIME_AND_MEMORY {
        static auto GetMicroSecond() {
            static FILETIME ft;
            GetSystemTimeAsFileTime(&ft);
            return ft.dwLowDateTime;
        };
        static auto GetMemory() {
            PROCESS_MEMORY_COUNTERS pmc;
            GetProcessMemoryInfo(GetCurrentProcess(), &pmc, sizeof(pmc));
            return pmc.WorkingSetSize;
        }
        uint32_t t0, t1;
        TIME_AND_MEMORY() : t0(GetMicroSecond()) {}
        void stop() {
            t1 = GetMicroSecond();
            cout << "\ntime cost = " << (t1 - t0) / 10000.0 << " ms\nmemory cost = " << (GetMemory() >> 20) << " MB\n ";
            t0 = t1;
        }
        ~TIME_AND_MEMORY() { stop(); }
    };
    return TIME_AND_MEMORY();
#else
#define CHECKTIME
    return 0;
#endif
}();
namespace OY {
    template <typename _Tp = int64_t, typename _Operation = std::plus<_Tp>>
    class ZkwTree {
        std::vector<_Tp> m_sub;
        int m_length;
        int m_depth;
        _Operation m_op;
        _Tp m_defaultValue;
        void _check() {
            

        }
        void _update(int cur) {
            m_sub[cur] = m_op(m_sub[cur * 2], m_sub[cur * 2 + 1]);
        }

    public:
        ZkwTree(int __n = 0, _Operation __op = _Operation(), _Tp __defaultValue = _Tp()) : m_op(__op), m_defaultValue(__defaultValue) {
            _check();
            resize(__n);
        }
        template <typename _Iterator>
        ZkwTree(_Iterator __first, _Iterator __last, _Operation __op = _Operation(), _Tp __defaultValue = _Tp()) : m_op(__op), m_defaultValue(__defaultValue) {
            _check();
            reset(__first, __last);
        }
        void resize(int __n) {
            if (!__n) return;
            m_length = __n;
            m_depth = 32 - (m_length > 1 ? std::__countl_zero<uint32_t>(m_length - 1) : 32);
            m_sub.assign(1 << (m_depth + 1), m_defaultValue);
        }
        template <typename _Iterator>
        void reset(_Iterator __first, _Iterator __last) {
            m_length = __last - __first;
            m_depth = 32 - (m_length > 1 ? std::__countl_zero<uint32_t>(m_length - 1) : 32);
            m_sub.resize(1 << (m_depth + 1));
            std::copy(__first, __last, m_sub.begin() + (1 << m_depth));
            std::fill(m_sub.begin() + (1 << m_depth) + m_length, m_sub.end(), m_defaultValue);
            for (int i = 1 << m_depth; --i;) _update(i);
        }
        void update(int __i, _Tp __val) {
            __i += 1 << m_depth;
            m_sub[__i] = __val;
            while (__i >>= 1) _update(__i);
        }
        void add(int __i, _Tp __inc) {
            __i += 1 << m_depth;
            m_sub[__i] = m_op(m_sub[__i], __inc);
            while (__i >>= 1) _update(__i);
        }
        _Tp query(int __i) const {
            return m_sub[(1 << m_depth) + __i];
        }
        _Tp query(int __left, int __right) const {
            if (__left == __right) return m_sub[(1 << m_depth) + __left];
            __left += 1 << m_depth;
            __right += 1 << m_depth;
            _Tp res = m_sub[__left];
            int j = 31 - std::__countl_zero<uint32_t>(__left ^ __right);
            for (int i = 0; i < j; i++)
                if (!(__left >> i & 1)) res = m_op(res, m_sub[__left >> i ^ 1]);
            for (int i = j - 1; i >= 0; i--)
                if (__right >> i & 1) res = m_op(res, m_sub[__right >> i ^ 1]);
            return m_op(res, m_sub[__right]);
        }
        _Tp queryAll() const {
            return m_sub[1];
        }
        int kth(_Tp __k) const {
            int i = 1;
            while (i < 1 << m_depth)
                if (m_sub[i *= 2] <= __k) __k -= m_sub[i++];
            return i - (1 << m_depth);
        }
    };
    template <typename _Tp = int64_t>
    ZkwTree(int, const _Tp &(*)(const _Tp &, const _Tp &), _Tp = _Tp(), _Tp = _Tp()) -> ZkwTree<_Tp, const _Tp &(*)(const _Tp &, const _Tp &)>;
    template <typename _Tp = int64_t>
    ZkwTree(int, _Tp (*)(_Tp, _Tp), _Tp = _Tp(), _Tp = _Tp()) -> ZkwTree<_Tp, _Tp (*)(_Tp, _Tp)>;
    template <typename _Operation = std::plus<int64_t>, typename _Tp = std::decay_t<typename decltype(std::mem_fn(&_Operation::operator()))::result_type>>
    ZkwTree(int = 0, _Operation = _Operation(), _Tp = _Tp(), _Tp = _Tp()) -> ZkwTree<_Tp, _Operation>;
    template <typename _Iterator, typename _Tp = typename std::iterator_traits<_Iterator>::value_type>
    ZkwTree(_Iterator, _Iterator, const _Tp &(*)(const _Tp &, const _Tp &), _Tp = _Tp(), _Tp = _Tp()) -> ZkwTree<_Tp, const _Tp &(*)(const _Tp &, const _Tp &)>;
    template <typename _Iterator, typename _Tp = typename std::iterator_traits<_Iterator>::value_type>
    ZkwTree(_Iterator, _Iterator, _Tp (*)(_Tp, _Tp), _Tp = _Tp(), _Tp = _Tp()) -> ZkwTree<_Tp, _Tp (*)(_Tp, _Tp)>;
    template <typename _Iterator, typename _Tp = typename std::iterator_traits<_Iterator>::value_type, typename _Operation = std::plus<_Tp>>
    ZkwTree(_Iterator, _Iterator, _Operation = _Operation(), _Tp = _Tp(), _Tp = _Tp()) -> ZkwTree<_Tp, _Operation>;
}
namespace OY {
    template <typename _Tp, typename _Maximum>
    struct STTable {
        std::vector<std::vector<_Tp>> m_sub;
        _Maximum m_maxi;
        int m_length;
        _Tp m_defaultValue;
        void _check() {
            

        }
        STTable(int __n = 0, _Maximum __maxi = std::max<_Tp>, _Tp __defaultValue = _Tp()) : m_maxi(__maxi), m_defaultValue(__defaultValue) {
            _check();
            resize(__n);
        }
        template <typename _Iterator>
        STTable(_Iterator __first, _Iterator __last, _Maximum __maxi = std::max<_Tp>, _Tp __defaultValue = _Tp()) : m_maxi(__maxi), m_defaultValue(__defaultValue) {
            _check();
            reset(__first, __last);
        }
        void resize(int __n) {
            if (!__n) return;
            m_length = __n;
            int d = m_length > 1 ? 32 - std::__countl_zero<uint32_t>(m_length - 1) : 1;
            m_sub.resize(d);
            m_sub[0].assign(__n, m_defaultValue);
            for (int i = 1; i < d; i++) {
                m_sub[i].clear();
                m_sub[i].reserve(m_length - (1 << i) + 1);
                for (int j = 0; j <= m_length - (1 << i); j++)
                    m_sub[i].push_back(m_maxi(m_sub[i - 1][j], m_sub[i - 1][j + (1 << i - 1)]));
            }
        }
        template <typename _Iterator>
        void reset(_Iterator __first, _Iterator __last) {
            m_length = __last - __first;
            int d = m_length > 1 ? 32 - std::__countl_zero<uint32_t>(m_length - 1) : 1;
            m_sub.resize(d);
            m_sub[0].assign(__first, __last);
            for (int i = 1; i < d; i++) {
                m_sub[i].clear();
                m_sub[i].reserve(m_length - (1 << i) + 1);
                for (int j = 0; j <= m_length - (1 << i); j++)
                    m_sub[i].push_back(m_maxi(m_sub[i - 1][j], m_sub[i - 1][j + (1 << i - 1)]));
            }
        }
        void update(int __i, _Tp __val) {
            m_sub[0][__i] = __val;
            for (int i = 1; i < m_sub.size(); i++)
                for (int j = std::max(0, __i - (1 << i) + 1), end = std::min(__i, int(m_sub[i].size() - 1)); j <= end; j++)
                    m_sub[i][j] = m_maxi(m_sub[i - 1][j], m_sub[i - 1][j + (1 << i - 1)]);
        }
        _Tp query(int __i) const {
            return m_sub[0][__i];
        }
        _Tp query(int __left, int __right) const {
            if (__left == __right) return m_sub[0][__left];
            int d = 31 - std::__countl_zero<uint32_t>(__right - __left);
            return m_maxi(m_sub[d][__left], m_sub[d][__right - (1 << d) + 1]);
        }
        _Tp queryAll() const {
            return query(0, m_length - 1);
        }
    };
    template <typename _Tp = int>
    STTable(int = 0, const _Tp &(*)(const _Tp &, const _Tp &) = std::max<_Tp>, _Tp = _Tp()) -> STTable<_Tp, const _Tp &(*)(const _Tp &, const _Tp &)>;
    template <typename _Tp = int>
    STTable(int, _Tp (*)(_Tp, _Tp), _Tp = _Tp()) -> STTable<_Tp, _Tp (*)(_Tp, _Tp)>;
    template <typename _Maximum, typename _Tp = std::decay_t<typename decltype(std::mem_fn(&_Maximum::operator()))::result_type>>
    STTable(int, _Maximum, _Tp = _Tp()) -> STTable<_Tp, _Maximum>;
    template <typename _Iterator, typename _Maximum, typename _Tp = typename std::iterator_traits<_Iterator>::value_type>
    STTable(_Iterator, _Iterator, _Maximum, _Tp = _Tp()) -> STTable<_Tp, _Maximum>;
    template <typename _Iterator, typename _Tp = typename std::iterator_traits<_Iterator>::value_type>
    STTable(_Iterator, _Iterator, const _Tp &(*)(const _Tp &, const _Tp &) = std::max<_Tp>, _Tp = _Tp()) -> STTable<_Tp, const _Tp &(*)(const _Tp &, const _Tp &)>;
    template <typename _Iterator, typename _Tp = typename std::iterator_traits<_Iterator>::value_type>
    STTable(_Iterator, _Iterator, _Tp (*)(_Tp, _Tp), _Tp = _Tp()) -> STTable<_Tp, _Tp (*)(_Tp, _Tp)>;
}
namespace OY {
    template <typename _Tp, typename _Plus = std::plus<_Tp>, typename _Minus = std::minus<_Tp>>
    class BIT {
        std::vector<_Tp> m_sum;
        _Tp m_defaultValue;
        _Plus m_plus;
        _Minus m_minus;
        int m_length;

    public:
        BIT(int __n = 0, _Plus __plus = _Plus(), _Minus __minus = _Minus(), _Tp __defaultValue = _Tp()) : m_plus(__plus), m_minus(__minus), m_defaultValue(__defaultValue) { resize(__n); }
        template <typename _Iterator>
        BIT(_Iterator __first, _Iterator __last, _Plus __plus = _Plus(), _Minus __minus = _Minus(), _Tp __defaultValue = _Tp()) : m_plus(__plus), m_minus(__minus), m_defaultValue(__defaultValue) { reset(__first, __last); }
        void resize(int __n) {
            m_length = __n > 1 ? 1 << (32 - std::__countl_zero<uint32_t>(__n - 1)) : 1;
            m_sum.assign(m_length, m_defaultValue);
        }
        template <typename _Iterator>
        void reset(_Iterator __first, _Iterator __last) {
            m_length = (__last - __first) > 1 ? 1 << (32 - std::__countl_zero<uint32_t>((__last - __first) - 1)) : 1;
            m_sum.resize(m_length);
            std::copy(__first, __last, m_sum.begin());
            std::fill(m_sum.begin() + (__last - __first), m_sum.end(), m_defaultValue);
            for (int i = 0; i < m_length; i++)
                if (int j = i + (1 << std::__countr_zero<uint32_t>(i + 1)); j < m_length) m_sum[j] = m_plus(m_sum[j], m_sum[i]);
        }
        void add(int i, _Tp __inc) {
            while (i < m_length) {
                m_sum[i] = m_plus(m_sum[i], __inc);
                i += 1 << std::__countr_zero<uint32_t>(i + 1);
            }
        }
        _Tp presum(int i) const {
            _Tp ret = m_defaultValue;
            while (i >= 0) {
                ret = m_plus(ret, m_sum[i]);
                i -= 1 << std::__countr_zero<uint32_t>(i + 1);
            }
            return ret;
        }
        _Tp query(int i) const { return m_minus(presum(i), presum(i - 1)); }
        _Tp query(int __left, int __right) const { return m_minus(presum(__right), presum(__left - 1)); }
        _Tp queryAll() const { return presum(m_length - 1); }
        int kth(_Tp __k) const {
            int cursor = -1;
            for (int d = m_length / 2; d; d >>= 1)
                if (m_sum[cursor + d] <= __k) __k -= m_sum[cursor += d];
            return cursor + 1;
        }
    };
    template <typename _Tp = int, typename _Plus = std::plus<_Tp>, typename _Minus = std::minus<_Tp>>
    BIT(int, _Plus = _Plus(), _Minus = _Minus(), _Tp = _Tp()) -> BIT<_Tp, _Plus, _Minus>;
    template <typename _Iterator, typename _Tp = typename std::iterator_traits<_Iterator>::value_type, typename _Plus = std::plus<_Tp>, typename _Minus = std::minus<_Tp>>
    BIT(_Iterator, _Iterator, _Plus = _Plus(), _Minus = _Minus(), _Tp = _Tp()) -> BIT<_Tp, _Plus, _Minus>;

    template <typename _Tp = int64_t>
    class BIT_ex {
        struct _TpArray {
            _Tp val[2];
            _TpArray(_Tp __val = _Tp(0)) {
                val[0] = __val;
                val[1] = 0;
            }
            _TpArray(_Tp __val0, _Tp __val1) {
                val[0] = __val0;
                val[1] = __val1;
            }
            _TpArray &operator+=(const _TpArray &other) {
                val[0] += other.val[0];
                val[1] += other.val[1];
                return *this;
            }
        };
        std::vector<_TpArray> m_sum;
        int m_length;
        void _add(int i, _Tp __inc) {
            _TpArray inc(__inc, __inc * i);
            while (i < m_length) {
                m_sum[i] += inc;
                i += 1 << std::__countr_zero<uint32_t>(i + 1);
            }
        }

    public:
        BIT_ex(int __n) { resize(__n); }
        template <typename _Iterator>
        BIT_ex(_Iterator __first, _Iterator __last) { reset(__first, __last); }
        void resize(int __n) {
            m_length = __n > 1 ? 1 << (32 - std::__countl_zero<uint32_t>(__n - 1)) : 1;
            m_sum.assign(m_length, _Tp(0));
        }
        template <typename _Iterator>
        void reset(_Iterator __first, _Iterator __last) {
            m_length = (__last - __first) > 1 ? 1 << (32 - std::__countl_zero<uint32_t>((__last - __first) - 1)) : 1;
            m_sum.resize(m_length);
            std::adjacent_difference(__first, __last, m_sum.begin());
            std::fill(m_sum.begin() + (__last - __first), m_sum.end(), _Tp(0));
            for (int i = 0; i < m_length; i++) m_sum[i].val[1] = m_sum[i].val[0] * i;
            for (int i = 0; i < m_length; i++)
                if (int j = i + (1 << std::__countr_zero<uint32_t>(i + 1)); j < m_length) m_sum[j] += m_sum[i];
        }
        void add(int i, _Tp __inc) {
            _add(i, __inc);
            _add(i + 1, -__inc);
        }
        void add(int __left, int __right, _Tp __inc) {
            _add(__left, __inc);
            _add(__right + 1, -__inc);
        }
        _Tp presum(int i) {
            _TpArray ret;
            for (int j = i; j >= 0; j -= 1 << std::__countr_zero<uint32_t>(j + 1)) ret += m_sum[j];
            return ret.val[0] * (i + 1) - ret.val[1];
        }
        _Tp query(int i) {
            _Tp ret(0);
            for (int j = i; j >= 0; j -= 1 << std::__countr_zero<uint32_t>(j + 1)) ret += m_sum[j].val[0];
            return ret;
        }
        _Tp query(int __left, int __right) { return presum(__right) - presum(__left - 1); }
        _Tp queryAll() { return presum(m_length - 1); }
        int kth(_Tp __k) {
            int cursor = -1;
            _TpArray cur;
            for (int d = m_length / 2; d; d >>= 1)
                if ((cur.val[0] + m_sum[cursor + d].val[0]) * (cursor + d + 1) - (cur.val[1] + m_sum[cursor + d].val[1]) <= __k) cur += m_sum[cursor += d];
            return cursor + 1;
        }
    };
    template <typename _Tp = int64_t>
    BIT_ex(int) -> BIT_ex<_Tp>;
    template <typename _Iterator, typename _Tp = typename std::iterator_traits<_Iterator>::value_type>
    BIT_ex(_Iterator, _Iterator) -> BIT_ex<_Tp>;
}

int main() {
    int n;
    cin >> n;
    int A[n];
    for (int i = 0; i < n; i++) cin >> A[i];
    std::vector<int> right_bound(n), second_right_bound(n), left_bound(n);
    for (int i = 0, j = 0, k = 0; i < n; i++) {
        while (j < n and A[j] - j >= 1 - i) {
            left_bound[j] = i;
            j++;
        }
        chmax(k, std::min(j + 1, n));
        while (k < n and A[k] - k >= 1 - i) {
            k++;
        }
        right_bound[i] = j - 1;
        second_right_bound[i] = k - 1;
    }
    

    

    


    std::vector<int> pairs(n);
    for (int i = 0; i < n; i++) pairs[i] = right_bound[i] - i + 1;
    OY::BIT<long long> S(all(pairs));

    std::vector<int> second_pairs(n);
    for (int i = 0; i < n; i++) second_pairs[i] = second_right_bound[i] - i + 1;
    OY::BIT<long long> S2(all(second_pairs));

    std::vector<int> dif(n);
    for (int i = 0; i < n; i++) dif[i] = A[i] - i;
    OY::STTable st(all(dif), std::min<int>);

    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        int p, x;
        cin >> p >> x;
        p--;
        if (x < A[p]) {
            int now = std::max(left_bound[p], p - x + 1);
            long long dec = now == left_bound[p] ? 0 : S.query(left_bound[p], now - 1) - 1ll * ((p - now + 1) + (p - left_bound[p])) * (now - left_bound[p]) / 2;
            cout << S.queryAll() - dec << '\n';
        } else if (x > A[p]) {
            int now = std::max<int>(std::lower_bound(all(right_bound), p - 1) - right_bound.begin(), p - x + 1);
            long long inc = now == left_bound[p] ? 0 : S2.query(now, left_bound[p] - 1) - S.query(now, left_bound[p] - 1);
            cout << S.queryAll() + inc << '\n';
        } else
            cout << S.queryAll() << '\n';
    }
}



