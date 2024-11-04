#pragma GCC optimize(3, "Ofast", "inline")
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
using std::cin, std::cout, std::endl;
namespace OY {
    template <typename _Sequence>
    struct SiftGetter {
        _Sequence &m_sequence;
        SiftGetter(_Sequence &__sequence) : m_sequence(__sequence) {}
        auto &operator()(uint32_t __index) const { return m_sequence[__index]; }
    };
    template <typename _Mapping, typename _Compare = std::less<void>>
    struct SiftHeap {
        std::vector<uint32_t> m_heap;
        std::vector<uint32_t> m_pos;
        _Mapping m_map;
        _Compare m_comp;
        SiftHeap(uint32_t __n, _Mapping __map, _Compare __comp = _Compare()) : m_pos(__n, -1), m_map(__map), m_comp(__comp) { m_heap.reserve(__n); }
        void siftUp(uint32_t __i) {
            uint32_t curpos = m_pos[__i];
            auto curvalue = m_map(__i);
            for (uint32_t p; curpos && m_comp(m_map(p = m_heap[curpos - 1 >> 1]), curvalue); curpos = curpos - 1 >> 1) m_heap[m_pos[p] = curpos] = p;
            m_heap[m_pos[__i] = curpos] = __i;
        }
        void siftDown(uint32_t __i) {
            uint32_t curpos = m_pos[__i];
            auto curvalue = m_map(__i);
            for (uint32_t c; (c = curpos * 2 + 1) < m_heap.size(); curpos = c) {
                if (c + 1 < m_heap.size() && m_comp(m_map(m_heap[c]), m_map(m_heap[c + 1]))) c++;
                if (!m_comp(curvalue, m_map(m_heap[c]))) break;
                m_pos[m_heap[curpos] = m_heap[c]] = curpos;
            }
            m_heap[m_pos[__i] = curpos] = __i;
        }
        void push(uint32_t __i) {
            if (!~m_pos[__i]) {
                m_pos[__i] = m_heap.size();
                m_heap.push_back(__i);
            }
            siftUp(__i);
        }
        uint32_t top() const { return m_heap.front(); }
        void pop() {
            m_pos[m_heap.front()] = -1;
            if (m_heap.size() > 1) {
                m_pos[m_heap.back()] = 0;
                m_heap.front() = m_heap.back();
                m_heap.pop_back();
                siftDown(m_heap.front());
            } else
                m_heap.pop_back();
        }
        bool empty() const { return m_heap.empty(); }
        uint32_t size() const { return m_heap.size(); }
    };
    template <typename _Tp, typename _Compare>
    SiftHeap(uint32_t, std::vector<_Tp> &, _Compare) -> SiftHeap<SiftGetter<std::vector<_Tp>>, _Compare>;
    template <typename _Tp, uint32_t _N, typename _Compare>
    SiftHeap(uint32_t, _Tp (&)[_N], _Compare) -> SiftHeap<SiftGetter<_Tp[_N]>, _Compare>;
}
auto tam = [] {
#ifdef OY_LOCAL
#define CHECKTIME tam.stop()
    std::ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
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
    template <typename _ModType, _ModType _P>
    struct Modular {
        static constexpr _ModType mod() { return _P; }
        static constexpr _ModType mod(uint64_t __a) { return __a % _P; }
        static constexpr _ModType plus(_ModType __a, _ModType __b) {
            if (__a += __b; __a >= _P) __a -= _P;
            return __a;
        }
        static constexpr _ModType minus(_ModType __a, _ModType __b) {
            if (__a += _P - __b; __a >= _P) __a -= _P;
            return __a;
        }
        static constexpr _ModType multiply(uint64_t __a, uint64_t __b) {
            if constexpr (std::is_same_v<_ModType, uint64_t>)
                return multiply_ld(__a, __b);
            else
                return multiply_64(__a, __b);
        }
        static constexpr _ModType multiply_64(uint64_t __a, uint64_t __b) {
            

            return mod(__a * __b);
        }
        static constexpr _ModType multiply_128(uint64_t __a, uint64_t __b) { return __uint128_t(__a) * __b % _P; }
        static constexpr _ModType multiply_ld(uint64_t __a, uint64_t __b) {
            

            if (std::__countl_zero(__a) + std::__countl_zero(__b) >= 64) return multiply_64(__a, __b);
            int64_t res = __a * __b - uint64_t(1.L / _P * __a * __b) * _P;
            if (res < 0)
                res += _P;
            else if (res >= _P)
                res -= _P;
            return res;
        }
        static constexpr _ModType pow(uint64_t __a, uint64_t __n) {
            if constexpr (std::is_same_v<_ModType, uint64_t>)
                return pow_ld(__a, __n);
            else
                return pow_64(__a, __n);
        }
        static constexpr _ModType pow_64(uint64_t __a, uint64_t __n) {
            

            _ModType res = 1, b = mod(__a);
            while (__n) {
                if (__n & 1) res = multiply_64(res, b);
                b = multiply_64(b, b);
                __n >>= 1;
            }
            return res;
        }
        static constexpr _ModType pow_128(uint64_t __a, uint64_t __n) {
            _ModType res = 1, b = mod(__a);
            while (__n) {
                if (__n & 1) res = multiply_128(res, b);
                b = multiply_128(b, b);
                __n >>= 1;
            }
            return res;
        }
        static constexpr _ModType pow_ld(uint64_t __a, uint64_t __n) {
            _ModType res = 1, b = mod(__a);
            while (__n) {
                if (__n & 1) res = multiply_ld(res, b);
                b = multiply_ld(b, b);
                __n >>= 1;
            }
            return res;
        }
        template <typename _Tp>
        static constexpr _Tp divide(_Tp __a) { return __a / _P; }
        template <typename _Tp>
        static constexpr std::pair<_Tp, _Tp> divmod(_Tp __a) {
            _Tp quo = __a / _P, rem = __a - quo * _P;
            return {quo, rem};
        }
    };
    template <uint32_t _P>
    using Modular32 = Modular<uint32_t, _P>;
    template <uint64_t _P>
    using Modular64 = Modular<uint64_t, _P>;
}
namespace OY {
    template <typename _ModType>
    struct Barrett {
        _ModType m_P;
        __uint128_t m_Pinv;
        constexpr Barrett() = default;
        constexpr explicit Barrett(_ModType __P) : m_P(__P), m_Pinv(-uint64_t(__P) / __P + 1) {}
        constexpr _ModType mod() const { return m_P; }
        constexpr _ModType mod(uint64_t __a) const {
            __a -= uint64_t(m_Pinv * __a >> 64) * m_P + m_P;
            if (__a >= m_P) __a += m_P;
            return __a;
        }
        constexpr _ModType plus(_ModType __a, _ModType __b) {
            if (__a += __b; __a >= m_P) __a -= m_P;
            return __a;
        }
        constexpr _ModType minus(_ModType __a, _ModType __b) {
            if (__a += m_P - __b; __a >= m_P) __a -= m_P;
            return __a;
        }
        constexpr _ModType multiply(uint64_t __a, uint64_t __b) const {
            if constexpr (std::is_same_v<_ModType, uint64_t>)
                return multiply_ld(__a, __b);
            else
                return multiply_64(__a, __b);
        }
        constexpr _ModType multiply_64(uint64_t __a, uint64_t __b) const {
            

            return mod(__a * __b);
        }
        constexpr _ModType multiply_128(uint64_t __a, uint64_t __b) const {
            if (std::__countl_zero(__a) + std::__countl_zero(__b) >= 64) return multiply_64(__a, __b);
            return __uint128_t(__a) * __b % m_P;
        }
        constexpr _ModType multiply_ld(uint64_t __a, uint64_t __b) const {
            

            if (std::__countl_zero(__a) + std::__countl_zero(__b) >= 64) return multiply_64(__a, __b);
            int64_t res = __a * __b - uint64_t(1.L / m_P * __a * __b) * m_P;
            if (res < 0)
                res += m_P;
            else if (res >= m_P)
                res -= m_P;
            return res;
        }
        constexpr _ModType pow(uint64_t __a, uint64_t __n) const {
            if constexpr (std::is_same_v<_ModType, uint64_t>)
                return pow_ld(__a, __n);
            else
                return pow_64(__a, __n);
        }
        constexpr _ModType pow_64(uint64_t __a, uint64_t __n) const {
            

            _ModType res = 1, b = mod(__a);
            while (__n) {
                if (__n & 1) res = multiply_64(res, b);
                b = multiply_64(b, b);
                __n >>= 1;
            }
            return res;
        }
        constexpr _ModType pow_128(uint64_t __a, uint64_t __n) const {
            _ModType res = 1, b = mod(__a);
            while (__n) {
                if (__n & 1) res = multiply_128(res, b);
                b = multiply_128(b, b);
                __n >>= 1;
            }
            return res;
        }
        constexpr _ModType pow_ld(uint64_t __a, uint64_t __n) const {
            _ModType res = 1, b = mod(__a);
            while (__n) {
                if (__n & 1) res = multiply_ld(res, b);
                b = multiply_ld(b, b);
                __n >>= 1;
            }
            return res;
        }
        template <typename _Tp>
        constexpr _Tp divide(_Tp __a) const {
            if (__a < m_P) return 0;
            _Tp res = m_Pinv * __a >> 64;
            if (__a - res * m_P >= m_P) res++;
            return res;
        }
        template <typename _Tp>
        constexpr std::pair<_Tp, _Tp> divmod(_Tp __a) const {
            _Tp quo = (__a * m_Pinv) >> 64, rem = __a - quo * m_P;
            if (rem >= m_P) {
                quo++;
                rem -= m_P;
            }
            return {quo, rem};
        }
    };
    using Barrett32 = Barrett<uint32_t>;
    using Barrett64 = Barrett<uint64_t>;
}
namespace OY {
    template <typename _ModType>
    struct _MontgomeryTag;
    template <>
    struct _MontgomeryTag<uint32_t> {
        using long_type = uint64_t;
        static constexpr uint32_t limit = (1u << 30) - 1;
        static constexpr uint32_t inv_loop = 4;
        static constexpr uint32_t length = 32;
    };
    template <>
    struct _MontgomeryTag<uint64_t> {
        using long_type = __uint128_t;
        static constexpr uint64_t limit = (1ull << 63) - 1;
        static constexpr uint32_t inv_loop = 5;
        static constexpr uint32_t length = 64;
    };
    template <typename _ModType>
    struct Montgomery {
        using _FastType = _ModType;
        using _LongType = typename _MontgomeryTag<_ModType>::long_type;
        _ModType m_P;
        _ModType m_Pinv;
        _ModType m_Ninv;
        Barrett<_ModType> m_brt;
        constexpr Montgomery() = default;
        constexpr explicit Montgomery(_ModType __P) : m_P(__P), m_Pinv(__P), m_Ninv(-_LongType(__P) % __P), m_brt(__P) {
            for (int i = 0; i < _MontgomeryTag<_ModType>::inv_loop; i++) m_Pinv *= _ModType(2) - __P * m_Pinv;
        }
        constexpr _ModType mod() const { return m_brt.mod(); }
        constexpr _ModType mod(uint64_t __a) const { return m_brt.mod(__a); }
        constexpr _FastType init(uint64_t __a) const { return reduce(_LongType(mod(__a)) * m_Ninv); }
        constexpr _FastType raw_init(uint64_t __a) const { return reduce(_LongType(__a) * m_Ninv); }
        constexpr _FastType reduce(_LongType __a) const {
            _FastType res = (__a >> _MontgomeryTag<_ModType>::length) - _ModType(_LongType(_ModType(__a) * m_Pinv) * m_P >> _MontgomeryTag<_ModType>::length);
            if (res >= mod()) res += mod();
            return res;
        }
        constexpr _ModType reduce(_FastType __a) const {
            _ModType res = -_ModType(_LongType(__a * m_Pinv) * m_P >> _MontgomeryTag<_ModType>::length);
            if (res >= mod()) res += mod();
            return res;
        }
        constexpr _FastType plus(_FastType __a, _FastType __b) const {
            if (__a += __b; __a >= m_P) __a -= m_P;
            return __a;
        }
        constexpr _FastType minus(_FastType __a, _FastType __b) const {
            if (__a += m_P - __b; __a >= m_P) __a -= m_P;
            return __a;
        }
        constexpr _FastType multiply(_FastType __a, _FastType __b) const { return reduce(_LongType(__a) * __b); }
        constexpr _FastType pow(_FastType __a, uint64_t __n) const {
            _FastType res = reduce(_LongType(1) * m_Ninv);
            while (__n) {
                if (__n & 1) res = multiply(res, __a);
                __a = multiply(__a, __a);
                __n >>= 1;
            }
            return res;
        }
        template <typename _Tp>
        constexpr _Tp divide(_Tp __a) const { return m_brt.divide(__a); }
        template <typename _Tp>
        constexpr std::pair<_Tp, _Tp> divmod(_Tp __a) const { return m_brt.divmod(__a); }
    };
    using Montgomery32 = Montgomery<uint32_t>;
    using Montgomery64 = Montgomery<uint64_t>;
}
namespace OY {
    template <typename _Elem>
    constexpr bool isPrime(_Elem n) {
        if (std::is_same_v<_Elem, uint32_t> || n <= UINT32_MAX) {
            if (n <= 1) return false;
            if (n == 2 || n == 7 || n == 61) return true;
            if (n % 2 == 0) return false;
            Barrett32 brt(n);
            uint32_t d = (n - 1) >> std::__countr_zero(n - 1);
            for (auto &&a : {2, 7, 61}) {
                uint32_t s = d, y = brt.pow_64(a, s);
                while (s != n - 1 && y != 1 && y != n - 1) {
                    y = brt.multiply_64(y, y);
                    s <<= 1;
                }
                if (y != n - 1 && s % 2 == 0) return false;
            }
            return true;
        } else {
            

            if (n % 2 == 0) return false;
            Montgomery64 mg(n);
            uint64_t d = (n - 1) >> std::__countr_zero(n - 1), one = mg.init(1);
            for (auto &&a : {2, 325, 9375, 28178, 450775, 9780504, 1795265022}) {
                uint64_t s = d, y = mg.pow(mg.init(a), s), t = mg.init(n - 1);
                while (s != n - 1 && y != one && y != t) {
                    y = mg.multiply(y, y);
                    s <<= 1;
                }
                if (y != t && s % 2 == 0) return false;
            }
            return true;
        }
    }
    constexpr auto isPrime32 = isPrime<uint32_t>;
    constexpr auto isPrime64 = isPrime<uint64_t>;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, q;
        cin >> n >> q;
        int A[n];
        for (auto &a : A) cin >> a;
        std::vector<int> B;
        B.reserve(n);
        for (int i = 2; i <= n; i++)
            if (n % i == 0 and OY::isPrime32(i)) B.push_back(n/i);
        std::vector<std::vector<long long>> S;
        S.reserve(B.size());
        std::multiset<long long> T;
        for (int d : B) {
            S.push_back({});
            S.back().reserve(d);
            for (int i = 0; i < d; i++) {
                long long k = 0;
                for (int j = i; j < n; j += d) k += A[j];
                S.back().push_back(k * d);
            }
            T.insert(all(S.back()));
        }

        for (int i = 0; i <= q; i++) {
            if (i) {
                int idx, val;
                cin >> idx >> val;
                idx--;
                long long inc = val - A[idx];
                A[idx] = val;
                for (int i = 0; i < B.size(); i++) {
                    int d = B[i];
                    long long &cur = S[i][idx % d];
                    T.erase(T.find(cur));
                    cur += inc * d;
                    T.insert(cur);
                }
            }
            cout << *T.rbegin() << '\n';
        }
    }

    CHECKTIME;
}