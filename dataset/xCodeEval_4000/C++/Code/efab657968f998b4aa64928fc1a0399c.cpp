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
using LL = long long;
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
    template <typename _Tp, template <typename...> typename _Solver = STTable>
    struct FirstLastBiggerSmaller2 {
        _Solver<_Tp, const _Tp &(*)(const _Tp &, const _Tp &)> m_maxSolver, m_minSolver;
        template <typename _Iterator>
        FirstLastBiggerSmaller2(_Iterator __first, _Iterator __last) : m_maxSolver(__first, __last, std::max<_Tp>), m_minSolver(__first, __last, std::min<_Tp>) {}
        uint32_t queryLastBigger(uint32_t __left, uint32_t __right, _Tp __item) const {
            if (__left == __right) return m_maxSolver.m_sub[0][__right] > __item ? __right : -1;
            int d = 31 - std::__countl_zero<uint32_t>(__right - __left);
            if (__right-=(1<<d)-1;m_maxSolver.m_sub[d][__right] <= __item && m_maxSolver.m_sub[d][__right=__left] <= __item) return -1;
            while (d--)
                if (m_maxSolver.m_sub[d][__right+(1<<d)] > __item) __right += 1 << d;
            return __right;
        }
        uint32_t queryFirstSmaller(uint32_t __left, uint32_t __right, _Tp __item) const {
            if (__left == __right) return m_minSolver.m_sub[0][__left] < __item ? __left : -1;
            int d = 31 - std::__countl_zero<uint32_t>(__right - __left);
            if (m_minSolver.m_sub[d][__left] >= __item && m_minSolver.m_sub[d][__left = __right - (1 << d) + 1] >= __item) return -1;
            while (d--)
                if (m_minSolver.m_sub[d][__left] >= __item) __left += 1 << d;
            return __left;
        }
        uint32_t queryFirstBigger(uint32_t __left, uint32_t __right, _Tp __item) const {
            if (__left == __right) return m_maxSolver.m_sub[0][__left] > __item ? __left : -1;
            int d = 31 - std::__countl_zero<uint32_t>(__right - __left);
            if (m_maxSolver.m_sub[d][__left] <= __item && m_maxSolver.m_sub[d][__left = __right - (1 << d) + 1] <= __item) return -1;
            while (d--)
                if (m_maxSolver.m_sub[d][__left] <= __item) __left += 1 << d;
            return __left;
        }
    };
}

int main() {
    int t;
    cin >> t;
    for (int cc = 1; cc <= t; cc++) {
        int n, k;
        cin >> n >> k;
        LL A[n + 1];
        for (int i = 1; i <= n; i++) cin >> A[i];
        LL S[n + 1];
        for (int i = 0; i <= n; i++) S[i] = i ? S[i - 1] + A[i] : 0;
        OY::FirstLastBiggerSmaller2<LL> fbs(S, S + n + 1);

        int indexes[n + 1];
        std::iota(indexes, indexes + n + 1, 0);
        auto get_max = [&](int x, int y) {
            if (S[x] != S[y])
                return S[x] < S[y] ? y : x;
            else
                return x < y ? y : x;
        };
        OY::ZkwTree T(indexes, indexes + n + 1, get_max);
        auto get_min = [&](int x, int y) {
            if (S[x] != S[y])
                return S[x] < S[y] ? x : y;
            else
                return x < y ? x : y;
        };
        OY::ZkwTree T2(indexes, indexes + n + 1, get_min);

        int l = k, r = k, stop = 0;
        while (true) {
            if (l == 1 or r == n) break;
            int r_bound = fbs.queryFirstSmaller(r + 1, n, S[l - 1]);
            if (!~r_bound) {
                r = n;
                break;
            }
            if (r_bound > r + 1) {
                int r2 = T.query(r + 1, r_bound - 1);
                if (S[r2] < S[r]) r2 = r;
                if (r != r2) {
                    r = r2;
                    stop = 0;
                } else if (++stop == 2)
                    break;
            } else if (++stop == 2)
                break;

            int l_bound = fbs.queryLastBigger(0, l - 2, S[r]);
            if (!~l_bound) {
                l = 1;
                break;
            }
            if (l_bound < l - 2) {
                int l2 = T2.query(l_bound + 1, l - 2);
                if (S[l2] > S[l - 1]) l2 = l - 1;
                if (l != l2 + 1) {
                    l = l2 + 1;
                    stop = 0;
                } else if (++stop == 2)
                    break;
            } else if (++stop == 2)
                break;
        }
        YESNO(l == 1 or r == n);
    }
}