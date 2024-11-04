








template <typename _Tp, typename _Fp, typename _Compare = std::less<void>>
bool chmax(_Tp &a, const _Fp &b, _Compare __comp = _Compare()) { return __comp(a, b) ? a = b, true : false; }
template <typename _Tp, typename _Fp, typename _Compare = std::less<void>>
bool chmin(_Tp &a, const _Fp &b, _Compare __comp = _Compare()) { return __comp(b, a) ? a = b, true : false; }

    if (condition)       \
        cout << "YES\n"; \
    else                 \
        cout << "NO\n";
using std::cin, std::cout, std::endl;
auto tam = [] {
    std::ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);


    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    struct id6 {
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
        id6() : t0(GetMicroSecond()) {}
        void stop() {
            t1 = GetMicroSecond();
            cout << "\ntime cost = " << (t1 - t0) / 10000.0 << " ms\nmemory cost = " << (GetMemory() >> 20) << " MB\n ";
            t0 = t1;
        }
        ~id6() { stop(); }
    };
    return id6();


    return 0;

}();

namespace OY {
    template <typename _ModType>
    struct Barrett {
        _ModType m_P;
        __uint128_t id8;
        constexpr Barrett() = default;
        constexpr explicit Barrett(_ModType __P) : m_P(__P), id8(-uint64_t(__P) / __P + 1) {}
        constexpr _ModType mod() const { return m_P; }
        constexpr _ModType mod(uint64_t __a) const {
            __a -= uint64_t(id8 * __a >> 64) * m_P + m_P;
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
            return __uint128_t(__a) * __b % m_P;
        }
        constexpr _ModType multiply_ld(uint64_t __a, uint64_t __b) const {
            

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
            _Tp res = id8 * __a >> 64;
            if (__a - res * m_P >= m_P) res++;
            return res;
        }
        template <typename _Tp>
        constexpr std::pair<_Tp, _Tp> divmod(_Tp __a) const {
            _Tp quo = (__a * id8) >> 64, rem = __a - quo * m_P;
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
        static constexpr uint32_t limit = (1u << 31) - 1;
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
        _ModType id8;
        _ModType m_Ninv;
        Barrett<_ModType> m_brt;
        constexpr Montgomery() = default;
        constexpr explicit Montgomery(_ModType __P) : m_P(__P), id8(__P), m_Ninv(-_LongType(__P) % __P), m_brt(__P) {
            for (int i = 0; i < _MontgomeryTag<_ModType>::inv_loop; i++) id8 *= _ModType(2) - __P * id8;
        }
        constexpr _ModType mod() const { return m_brt.mod(); }
        constexpr _ModType mod(uint64_t __a) const { return m_brt.mod(__a); }
        constexpr _FastType init(uint64_t __a) const { return reduce(_LongType(mod(__a)) * m_Ninv); }
        constexpr _FastType raw_init(uint64_t __a) const { return reduce(_LongType(__a) * m_Ninv); }
        constexpr _FastType reduce(_LongType __a) const {
            _FastType res = (__a >> _MontgomeryTag<_ModType>::length) - _ModType(_LongType(_ModType(__a) * id8) * m_P >> _MontgomeryTag<_ModType>::length);
            if (res >= mod()) res += mod();
            return res;
        }
        constexpr _ModType reduce(_FastType __a) const {
            _ModType res = -_ModType(_LongType(__a * id8) * m_P >> _MontgomeryTag<_ModType>::length);
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
    constexpr auto id3 = isPrime<uint32_t>;
    constexpr auto id7 = isPrime<uint64_t>;
}
namespace OY {
    struct Pollard_Rho {
        static constexpr uint64_t batch = 128;
        static inline std::mt19937_64 s_rander;
        template <typename _Elem>
        static _Elem pick(_Elem __n) {
            

            if (__n % 2 == 0) return 2;
            static Montgomery<_Elem> mg;
            if (mg.mod() != __n) mg = Montgomery<_Elem>(__n);
            std::uniform_int_distribution<_Elem> distribute(2, __n - 1);
            _Elem v0, v1 = mg.init(distribute(s_rander)), prod = mg.init(1), c = mg.init(distribute(s_rander));
            for (int i = 1; i < batch; i <<= 1) {
                v0 = v1;
                for (int j = 0; j < i; j++) v1 = mg.multiply(v1, v1) + c;
                for (int j = 0; j < i; j++) {
                    v1 = mg.multiply(v1, v1) + c;
                    prod = mg.multiply(prod, v0 > v1 ? v0 - v1 : v1 - v0);
                    if (!prod) return pick(__n);
                }
                if (_Elem g = std::gcd(prod, __n); g > 1) return g;
            }
            for (int i = batch;; i <<= 1) {
                v0 = v1;
                for (int j = 0; j < i; j++) v1 = mg.multiply(v1, v1) + c;
                for (int j = 0; j < i; j += batch) {
                    for (int k = 0; k < batch; k++) {
                        v1 = mg.multiply(v1, v1) + c;
                        prod = mg.multiply(prod, v0 > v1 ? v0 - v1 : v1 - v0);
                        if (!prod) return pick(__n);
                    }
                    if (_Elem g = std::gcd(prod, __n); g > 1) return g;
                }
            }
            return __n;
        }
        template <typename _Elem>
        static auto id1(_Elem __n) {
            struct node {
                _Elem prime;
                uint32_t count;
            };
            std::vector<node> res;
            auto dfs = [&](auto self, _Elem cur) -> void {
                if (!isPrime<_Elem>(cur)) {
                    _Elem a = pick<_Elem>(cur);
                    self(self, a);
                    self(self, cur / a);
                } else {
                    auto find = std::find_if(res.begin(), res.end(), [cur](auto x) { return x.prime == cur; });
                    if (find == res.end())
                        res.push_back({cur, 1u});
                    else
                        find->count++;
                }
            };
            if (__n % 2 == 0) {
                res.push_back({2, uint32_t(std::__countr_zero(__n))});
                __n >>= std::__countr_zero(__n);
            }
            if (__n > 1) dfs(dfs, __n);
            std::sort(res.begin(), res.end(), [](auto &x, auto &y) { return x.prime < y.prime; });
            return res;
        }
        template <typename _Elem>
        static std::vector<_Elem> getFactors(_Elem __n) {
            auto pf = id1(__n);
            std::vector<_Elem> res;
            _Elem count = 1;
            for (auto [p, c] : pf) count *= c + 1;
            res.reserve(count);
            auto dfs = [&](auto self, int i, _Elem prod) -> void {
                if (i == pf.size())
                    res.push_back(prod);
                else {
                    auto [p, c] = pf[i];
                    self(self, i + 1, prod);
                    while (c--) self(self, i + 1, prod *= p);
                }
            };
            dfs(dfs, 0, 1);
            std::sort(res.begin(), res.end());
            return res;
        }
        template <typename _Elem>
        static _Elem EulerPhi(_Elem __n) {
            for (auto [p, c] : id1(__n)) __n = __n / p * (p - 1);
            return __n;
        }
    };
}
namespace OY {
    template <uint32_t _N, bool _B>
    struct _EratosthenesSieveArray {
        uint32_t data[_N + 1];
        void set(int __i, uint32_t __val) { data[__i] = __val; }
        uint32_t operator[](int __i) const { return data[__i]; }
    };
    template <uint32_t _N>
    struct _EratosthenesSieveArray<_N, false> {
        void set(int __i, uint32_t __val) {}
        uint32_t operator[](int __i) const { return 1; }
    };
    template <uint32_t _N, bool _Prime = true, bool _Phi = false, bool _Small = false, bool _Big = false>
    class id4 {
        static constexpr uint32_t sqrt = [] {
            uint32_t i = 1;
            while (i * i + i * 2 + 1 <= _N) i++;
            return i;
        }();
        _EratosthenesSieveArray<_N, _Small> m_smallestFactor;
        _EratosthenesSieveArray<_N, _Big> m_biggestFactor;
        _EratosthenesSieveArray<_N, _Phi> m_phi;
        _EratosthenesSieveArray<_N >= 1000000 ? _N / 12 : 100000, _Prime> id5;
        std::bitset<_N + 1> m_isp;
        uint32_t m_primeCnt;

    public:
        id4() : m_primeCnt{0} {
            m_isp.set();
            m_isp.reset(1);
            m_smallestFactor.set(1, 1);
            m_biggestFactor.set(1, 1);
            m_phi.set(1, 1);
            m_smallestFactor.set(2, 2);
            m_biggestFactor.set(2, 2);
            m_phi.set(2, 1);
            id5.set(m_primeCnt++, 2);
            for (int i = 3; i <= sqrt; i += 2)
                if (m_isp[i]) {
                    m_smallestFactor.set(i, i);
                    m_phi.set(i, i - 1);
                    id5.set(m_primeCnt++, i);
                    for (int j = i; j <= _N; j += i) m_biggestFactor.set(j, i);
                    for (int j = i * i, k = i; j <= _N; j += i * 2, k += 2) {
                        if (m_isp[j]) {
                            m_isp.reset(j);
                            m_smallestFactor.set(j, i);
                            m_phi.set(j, i);
                            m_phi.set(j + 1, k);
                        }
                    }
                } else
                    m_phi.set(i, m_phi[i + 1] % m_phi[i] ? (m_phi[i] - 1) * m_phi[m_phi[i + 1]] : m_phi[i] * m_phi[m_phi[i + 1]]);
            for (int i = sqrt + sqrt % 2 + 1; i <= _N; i += 2)
                if (m_isp[i]) {
                    m_smallestFactor.set(i, i);
                    m_phi.set(i, i - 1);
                    id5.set(m_primeCnt++, i);
                    for (int j = i; j <= _N; j += i) m_biggestFactor.set(j, i);
                } else
                    m_phi.set(i, m_phi[i + 1] % m_phi[i] ? (m_phi[i] - 1) * m_phi[m_phi[i + 1]] : m_phi[i] * m_phi[m_phi[i + 1]]);
        }
        bool isPrime(uint32_t __i) const { return (__i & 1) || __i == 2 ? m_isp[__i] : false; }
        uint32_t EulerPhi(uint32_t __i) const {
            static_assert(_Phi);
            return __i & 1 ? m_phi[__i] : m_phi[__i >> std::__countr_zero(__i)] << std::__countr_zero(__i) - 1;
        }
        uint32_t querySmallestFactor(uint32_t __i) const {
            static_assert(_Small);
            return __i & 1 ? m_smallestFactor[__i] : 2;
        }
        uint32_t queryBiggestFactor(uint32_t __i) const {
            static_assert(_Big);
            if (__i & 1) return m_biggestFactor[__i];
            __i >>= std::__countr_zero(__i);
            return __i == 1 ? 2 : m_biggestFactor[__i];
        }
        uint32_t queryKthPrime(int __k) const {
            static_assert(_Prime);
            return id5[__k];
        }
        uint32_t count() const { return m_primeCnt; }
        auto id1(uint32_t __n) const {
            static_assert(_Small);
            struct node {
                uint32_t prime, count;
            };
            std::vector<node> res;
            if (__n % 2 == 0) {
                res.push_back({2, uint32_t(std::__countr_zero(__n))});
                __n >>= std::__countr_zero(__n);
            }
            while (__n > 1) {
                uint32_t cur = querySmallestFactor(__n);
                uint32_t num = 0;
                do {
                    __n /= cur;
                    num++;
                } while (querySmallestFactor(__n) == cur);
                res.push_back({cur, num});
            }
            return res;
        }
        std::vector<uint32_t> getFactors(uint32_t __n) const {
            static_assert(_Small);
            auto pf = id1(__n);
            std::vector<uint32_t> res;
            uint32_t count = 1;
            for (auto [p, c] : pf) count *= c + 1;
            res.reserve(count);
            auto dfs = [&](auto self, int i, uint32_t prod) -> void {
                if (i == pf.size())
                    res.push_back(prod);
                else {
                    auto [p, c] = pf[i];
                    self(self, i + 1, prod);
                    while (c--) self(self, i + 1, prod *= p);
                }
            };
            dfs(dfs, 0, 1);
            std::sort(res.begin(), res.end());
            return res;
        }
    };
}
namespace OY {
    template <uint32_t _N, bool _B>
    struct _EulerSieveArray {
        uint32_t data[_N + 1];
        void set(int __i, uint32_t __val) { data[__i] = __val; }
        uint32_t operator[](int __i) const { return data[__i]; }
    };
    template <uint32_t _N>
    struct _EulerSieveArray<_N, false> {
        void set(int __i, uint32_t __val) {}
        uint32_t operator[](int __i) const { return 1; }
    };
    template <uint32_t _N, bool _Phi = false, bool _Small = false, bool _Big = false>
    class id2 {
        _EulerSieveArray<_N + 1, _Phi> m_phi;
        _EulerSieveArray<_N + 1, _Small> m_smallestFactor;
        _EulerSieveArray<_N + 1, _Big> m_biggestFactor;
        std::bitset<_N + 1> m_isp;
        uint32_t id5[_N >= 1000000 ? _N / 12 : 100000];
        uint32_t m_primeCnt;

    public:
        id2() : m_primeCnt{0} {
            m_isp.set();
            m_isp.reset(1);
            m_phi.set(1, 1);
            m_smallestFactor.set(1, 1);
            m_biggestFactor.set(1, 1);
            for (int i = 2; i <= _N; i++) {
                if (m_isp[i]) {
                    m_phi.set(i, i - 1);
                    m_smallestFactor.set(i, i);
                    m_biggestFactor.set(i, i);
                    id5[m_primeCnt++] = i;
                }
                for (uint32_t *it = id5, *end = id5 + m_primeCnt; it < end; ++it) {
                    auto p = *it, q = i * p;
                    if (q > _N) break;
                    m_isp.reset(q);
                    m_smallestFactor.set(q, p);
                    m_biggestFactor.set(q, m_biggestFactor[i]);
                    if (i % p)
                        m_phi.set(q, m_phi[i] * (p - 1));
                    else {
                        m_phi.set(q, m_phi[i] * p);
                        break;
                    }
                }
            }
        }
        bool isPrime(uint32_t __i) const { return (__i & 1) || __i == 2 ? m_isp[__i] : false; }
        uint32_t EulerPhi(uint32_t __i) const {
            static_assert(_Phi);
            return __i & 1 ? m_phi[__i] : m_phi[__i >> std::__countr_zero(__i)] << std::__countr_zero(__i) - 1;
        }
        uint32_t querySmallestFactor(uint32_t __i) const {
            static_assert(_Small);
            return __i & 1 ? m_smallestFactor[__i] : 2;
        }
        uint32_t queryBiggestFactor(uint32_t __i) const {
            static_assert(_Big);
            return m_biggestFactor[__i];
        }
        uint32_t queryKthPrime(int __k) const { return id5[__k]; }
        uint32_t count() const { return m_primeCnt; }
        auto id1(uint32_t __n) {
            struct node {
                uint32_t prime, count;
            };
            std::vector<node> res;
            if (__n % 2 == 0) {
                res.push_back({2, uint32_t(std::__countr_zero(__n))});
                __n >>= std::__countr_zero(__n);
            }
            while (__n > 1) {
                uint32_t cur = querySmallestFactor(__n);
                uint32_t num = 0;
                do {
                    __n /= cur;
                    num++;
                } while (querySmallestFactor(__n) == cur);
                res.push_back({cur, num});
            }
            return res;
        }
        std::vector<uint32_t> getFactors(uint32_t __n) {
            auto pf = id1(__n);
            std::vector<uint32_t> res;
            uint32_t count = 1;
            for (auto [p, c] : pf) count *= c + 1;
            res.reserve(count);
            auto dfs = [&](auto self, int i, uint32_t prod) -> void {
                if (i == pf.size())
                    res.push_back(prod);
                else {
                    auto [p, c] = pf[i];
                    self(self, i + 1, prod);
                    while (c--) self(self, i + 1, prod *= p);
                }
            };
            dfs(dfs, 0, 1);
            std::sort(res.begin(), res.end());
            return res;
        }
    };
}
static constexpr uint32_t N = 2e7;
uint32_t A[N + 1], B[N + 1];
uint64_t dp[N + 1];

OY::id4<N, false, false, true, false> es;
void id0(int x) {
    std::vector<int> div = {1};
    ++B[1];
    while (x > 1) {
        int p = es.querySmallestFactor(x), sz = div.size();
        for (int i = 1, pw = p; !(x % p); ++i, pw *= p, x /= p) {
            for (int j = 0; j < sz; j++) {
                int tmp = div[j] * pw;
                div.emplace_back(tmp);
                ++B[tmp];
            }
        }
    }
}


int main() {
    uint32_t n;
    cin >> n;
    uint32_t mx = 0;
    for (uint32_t i = 0; i < n; i++) {
        uint32_t x;
        cin >> x;
        chmax(mx, x);
        A[x]++;
    }
    for (uint32_t i = mx; i; i--) {
        if (A[i]) {
            auto ret = es.getFactors(i);
            for (auto p : ret) B[p] += A[i];
        }
    }
    dp[1] = n;
    for (uint32_t v = 2; v <= mx; v++)
        if (B[v]) {
            for (auto &&[p, c] : es.id1(v)) {
                uint32_t v2 = v / p;
                chmax(dp[v], dp[v2] + uint64_t(B[v]) * (v - v2));
            }
        }
    cout << *std::max_element(dp, dp + N + 1);
}