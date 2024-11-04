








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
    struct id10 {
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
        id10() : t0(GetMicroSecond()) {}
        void stop() {
            t1 = GetMicroSecond();
            cout << "\ntime cost = " << (t1 - t0) / 10000.0 << " ms\nmemory cost = " << (GetMemory() >> 20) << " MB\n ";
            t0 = t1;
        }
        ~id10() { stop(); }
    };
    return id10();


    return 0;

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
        __uint128_t id12;
        constexpr Barrett() = default;
        constexpr explicit Barrett(_ModType __P) : m_P(__P), id12(-uint64_t(__P) / __P + 1) {}
        constexpr _ModType mod() const { return m_P; }
        constexpr _ModType mod(uint64_t __a) const {
            __a -= uint64_t(id12 * __a >> 64) * m_P + m_P;
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
            _Tp res = id12 * __a >> 64;
            if (__a - res * m_P >= m_P) res++;
            return res;
        }
        template <typename _Tp>
        constexpr std::pair<_Tp, _Tp> divmod(_Tp __a) const {
            _Tp quo = (__a * id12) >> 64, rem = __a - quo * m_P;
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
        _ModType id12;
        _ModType m_Ninv;
        Barrett<_ModType> m_brt;
        constexpr Montgomery() = default;
        constexpr explicit Montgomery(_ModType __P) : m_P(__P), id12(__P), m_Ninv(-_LongType(__P) % __P), m_brt(__P) {
            for (int i = 0; i < _MontgomeryTag<_ModType>::inv_loop; i++) id12 *= _ModType(2) - __P * id12;
        }
        constexpr _ModType mod() const { return m_brt.mod(); }
        constexpr _ModType mod(uint64_t __a) const { return m_brt.mod(__a); }
        constexpr _FastType init(uint64_t __a) const { return reduce(_LongType(mod(__a)) * m_Ninv); }
        constexpr _FastType raw_init(uint64_t __a) const { return reduce(_LongType(__a) * m_Ninv); }
        constexpr _FastType reduce(_LongType __a) const {
            _FastType res = (__a >> _MontgomeryTag<_ModType>::length) - _ModType(_LongType(_ModType(__a) * id12) * m_P >> _MontgomeryTag<_ModType>::length);
            if (res >= mod()) res += mod();
            return res;
        }
        constexpr _ModType reduce(_FastType __a) const {
            _ModType res = -_ModType(_LongType(__a * id12) * m_P >> _MontgomeryTag<_ModType>::length);
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
    template <typename _ModType, _ModType _P, bool _IsPrime = false>
    struct id11 {
        using mint = id11<_ModType, _P, _IsPrime>;
        _ModType m_val;
        static_assert(_P > 1 && _P < 1ull << 63);
        constexpr id11() : m_val(0) {}
        template <typename _Tp, std::enable_if_t<std::is_signed_v<_Tp>, bool> = true>
        constexpr id11(_Tp __val) : m_val(0) {
            int64_t x = int64_t(__val) % int64_t(mod());
            if (x < 0) x += mod();
            m_val = x;
        }
        template <typename _Tp, std::enable_if_t<std::is_unsigned_v<_Tp>, bool> = true>
        constexpr id11(_Tp __val) : m_val(__val % mod()) {}
        static constexpr mint raw(_ModType __val) {
            mint res;
            res.m_val = __val;
            return res;
        }
        static constexpr _ModType mod() { return _P; }
        constexpr _ModType val() const { return m_val; }
        constexpr mint pow(uint64_t __n) const { return Modular<_ModType, _P>::pow(m_val, __n); }
        constexpr mint inv() const {
            if constexpr (_IsPrime)
                return inv_Fermat();
            else
                return inv_exgcd();
        }
        constexpr mint inv_exgcd() const {
            _ModType x = mod(), y = m_val, m0 = 0, m1 = 1;
            while (y) {
                _ModType z = x / y;
                x -= y * z;
                m0 -= m1 * z;
                std::swap(x, y);
                std::swap(m0, m1);
            }
            if (m0 >= mod()) m0 += mod() / x;
            return raw(m0);
        }
        constexpr mint inv_Fermat() const { return pow(mod() - 2); }
        constexpr mint &operator++() {
            if (++m_val == mod()) m_val = 0;
            return *this;
        }
        constexpr mint &operator--() {
            if (m_val == 0) m_val = mod();
            m_val--;
            return *this;
        }
        constexpr mint operator++(int) {
            mint old(*this);
            ++*this;
            return old;
        }
        constexpr mint operator--(int) {
            mint old(*this);
            --*this;
            return old;
        }
        constexpr mint &operator+=(const mint &__other) {
            m_val = Modular<_ModType, _P>::plus(m_val, __other.m_val);
            return *this;
        }
        constexpr mint &operator-=(const mint &__other) {
            m_val = Modular<_ModType, _P>::minus(m_val, __other.m_val);
            return *this;
        }
        constexpr mint &operator*=(const mint &__other) {
            m_val = Modular<_ModType, _P>::multiply(m_val, __other.m_val);
            return *this;
        }
        constexpr mint &operator/=(const mint &__other) { return *this *= __other.inv(); }
        constexpr mint operator+() const { return *this; }
        constexpr mint operator-() const { return raw(m_val ? mod() - m_val : 0); }
        constexpr bool operator==(const mint &__other) const { return m_val == __other.m_val; }
        constexpr bool operator!=(const mint &__other) const { return m_val != __other.m_val; }
        constexpr bool operator<(const mint &__other) const { return m_val < __other.m_val; }
        constexpr bool operator>(const mint &__other) const { return m_val > __other.m_val; }
        constexpr bool operator<=(const mint &__other) const { return m_val <= __other.m_val; }
        constexpr bool operator>=(const mint &__other) const { return m_val <= __other.m_val; }
        template <typename _Tp>
        constexpr explicit operator _Tp() const { return _Tp(m_val); }
        constexpr friend mint operator+(const mint &a, const mint &b) { return mint(a) += b; }
        constexpr friend mint operator-(const mint &a, const mint &b) { return mint(a) -= b; }
        constexpr friend mint operator*(const mint &a, const mint &b) { return mint(a) *= b; }
        constexpr friend mint operator/(const mint &a, const mint &b) { return mint(a) /= b; }
        template <typename _Istream>
        friend _Istream &operator>>(_Istream &is, mint &self) { return is >> self.m_val; }
        template <typename _Ostream>
        friend _Ostream &operator<<(_Ostream &os, const mint &self) { return os << self.m_val; }
    };
    template <uint32_t _P, bool _IsPrime>
    using StaticModInt32 = id11<uint32_t, _P, _IsPrime>;
    template <uint64_t _P, bool _IsPrime>
    using StaticModInt64 = id11<uint64_t, _P, _IsPrime>;
}
namespace OY {
    template <typename _ModType, _ModType _P>
    struct id5 {
        std::vector<_ModType> m_factorial;
        std::vector<_ModType> m_factorialInv;
        id5(uint32_t __n) {
            m_factorial.reserve(__n + 1);
            m_factorialInv.reserve(__n + 1);
            m_factorial.push_back(1);
            m_factorialInv.push_back(1);
            m_factorialInv.push_back(1);
            for (uint32_t i = 1; i <= __n; i++) m_factorial.push_back(Modular<_ModType, _P>::multiply(m_factorial.back(), i));
            for (uint32_t i = 2; i <= __n; i++) {
                _ModType q = _P / i, r = _P - q * i;
                m_factorialInv.push_back(Modular<_ModType, _P>::multiply(_P - q, m_factorialInv[r]));
            }
            for (uint32_t i = 1; i <= __n; i++) m_factorialInv[i] = Modular<_ModType, _P>::multiply(m_factorialInv[i - 1], m_factorialInv[i]);
        }
        _ModType comb(_ModType __n, _ModType __m) const {
            if (__n < __m) return 0;
            if (__n == __m) return 1;
            return Modular<_ModType, _P>::multiply(m_factorial[__n], Modular<_ModType, _P>::multiply(m_factorialInv[__m], m_factorialInv[__n - __m]));
        }
        _ModType perm(_ModType __n) const { return m_factorial[__n]; }
        _ModType perm(_ModType __n, _ModType __m) const {
            if (__n < __m) return 0;
            if (__n == __m) return m_factorial[__n];
            return Modular<_ModType, _P>::multiply(m_factorial[__n], m_factorialInv[__n - __m]);
        }
        template <typename _Tp>
        _ModType perm(const std::vector<_Tp> &__ns) const {
            _ModType res = m_factorial[std::accumulate(__ns.begin(), __ns.end(), _ModType(0))];
            for (_Tp n : __ns) res = Modular<_ModType, _P>::multiply(res, m_factorialInv[n]);
            return res;
        }
        _ModType nonadjacentComb(_ModType __n, _ModType __m) const {
            if (__n < __m) return 0;
            return comb(__n - __m + 1, __m);
        }
        _ModType staggeredComb(_ModType __n) const {
            static std::vector<_ModType> s_res{1, 0};
            while (s_res.size() < __n + 1) s_res.push_back(Modular<_ModType, _P>::multiply(s_res[s_res.size() - 2] + s_res.back(), s_res.size() - 1));
            return s_res[__n];
        }
        _ModType circularPerm(_ModType __n) const { return m_factorial[__n - 1]; }
        _ModType circularPerm(_ModType __n, _ModType __m) const {
            if (!__m) return 1;
            return Modular<_ModType, _P>::multiply(comb(__n, __m), m_factorial[__m - 1]);
        }
    };
    template <uint32_t _P>
    using StaticCombinationTable32 = id5<uint32_t, _P>;
    template <uint64_t _P>
    using StaticCombinationTable64 = id5<uint64_t, _P>;
}
namespace OY {
    template <typename _Tp, uint32_t _MAXN = 1 << 22>
    struct NTTPolynomial : std::vector<_Tp> {
        using poly = NTTPolynomial<_Tp, _MAXN>;
        using std::vector<_Tp>::vector, std::vector<_Tp>::begin, std::vector<_Tp>::end, std::vector<_Tp>::rbegin, std::vector<_Tp>::rend, std::vector<_Tp>::size, std::vector<_Tp>::back, std::vector<_Tp>::empty, std::vector<_Tp>::clear, std::vector<_Tp>::pop_back, std::vector<_Tp>::resize, std::vector<_Tp>::push_back;
        static inline _Tp s_dftRoots[_MAXN], s_dftBuffer[_MAXN * 2], s_inverse[_MAXN + 1], s_primitiveRoot, s_treeBuffer[_MAXN * 2 * (std::__countr_zero(_MAXN))];
        static inline uint32_t s_dftBin[_MAXN * 2], id2 = 1, id0 = 0;
        static inline poly s_treeSum;
        static void prepareDFT(uint32_t __length) {
            if (__length == 1 || s_dftBin[__length + 1]) return;
            if (id2 == 1) s_dftRoots[id2++] = _Tp(1);
            while (id2 < __length) {
                const _Tp wn = s_primitiveRoot.pow((_Tp::mod() - 1) / (id2 * 2));
                for (uint32_t i = id2; i < id2 * 2; i += 2) {
                    s_dftRoots[i] = s_dftRoots[i / 2];
                    s_dftRoots[i + 1] = s_dftRoots[i / 2] * wn;
                }
                id2 *= 2;
            }
            for (uint32_t i = 0; i < __length; i += 2) {
                s_dftBin[__length + i] = s_dftBin[__length + i / 2] / 2;
                s_dftBin[__length + i + 1] = s_dftBin[__length + i / 2] / 2 + __length / 2;
            }
        }
        template <typename _Iterator>
        static _Iterator id3(_Iterator __iter, uint32_t __length) {
            for (uint32_t i = 0; i < __length; i++)
                if (uint32_t j = s_dftBin[__length + i]; i < j) std::swap(__iter[i], __iter[j]);
            for (uint32_t h = 2; h <= __length; h *= 2)
                for (uint32_t j = 0; j < __length; j += h)
                    for (uint32_t k = j; k < j + h / 2; k++) {
                        _Tp x = __iter[k], y = __iter[k + h / 2] * s_dftRoots[h / 2 + k - j];
                        __iter[k] += y;
                        __iter[k + h / 2] = x - y;
                    }
            return __iter;
        }
        template <typename _Iterator>
        static _Iterator id1(_Iterator __iter, uint32_t __length) { return std::fill_n(__iter + __length / 2, __length / 2, 0) - __length; }
        template <typename _Iterator>
        static _Iterator dft(_Iterator __iter, uint32_t __length) {
            prepareDFT(__length);
            return id3(__iter, __length);
        }
        template <typename _Iterator, typename _Iterator2>
        static _Iterator dft(_Iterator __iter, uint32_t id7, _Iterator2 __source, uint32_t id8) { return dft(std::fill_n(std::copy_n(__source, id8, __iter), id7 - id8, 0) - id7, id7); }
        template <typename _Iterator>
        static _Iterator idft(_Iterator __iter, uint32_t __length) {
            id3(__iter, __length);
            std::reverse(__iter + 1, __iter + __length);
            const _Tp inv = _Tp(__length).inv();
            for (uint32_t i = 0; i < __length; i++) __iter[i] *= inv;
            return __iter;
        }
        template <typename _Iterator, typename _Iterator2, typename _Operation = std::multiplies<_Tp>>
        static _Iterator transform(_Iterator id9, _Iterator2 id4, uint32_t __length, _Operation __op = _Operation()) { return std::transform(id9, id9 + __length, id4, id9, __op) - __length; }
        static void prepareInverse(uint32_t __length) {
            if (id0 > __length) return;
            if (!id0) s_inverse[0] = s_inverse[++id0] = 1;
            const auto P = _Tp::mod();
            for (uint32_t i = id0 + 1; i <= __length; i++) {
                auto q = P / i, r = P - q * i;
                s_inverse[i] = s_inverse[r] * _Tp(P - q);
            }
            id0 = __length;
        }
        template <typename _Iterator>
        static void derivate(_Iterator __iter, uint32_t __length) {
            for (uint32_t i = 0; i + 1 < __length; i++) __iter[i] = __iter[i + 1] * (i + 1);
            __iter[__length - 1] = 0;
        }
        template <typename _Iterator>
        static void integrate(_Iterator __iter, uint32_t __length) {
            if (!__length) return;
            prepareInverse(__length);
            for (uint32_t i = __length; i; i--) __iter[i] = __iter[i - 1] * s_inverse[i];
            __iter[0] = 0;
        }
        static void initTree(const poly &__xs, uint32_t __length) {
            _Tp *it = s_treeBuffer + __length * 2 * std::__countr_zero(__length / 2);
            for (uint32_t i = 0; i < __length; i++) *it++ = 1, *it++ = -__xs.at(i);
            for (uint32_t h = 2; h < __length; h *= 2) {
                _Tp *it = s_treeBuffer + __length * 2 * std::__countr_zero(__length / 2 / h);
                for (uint32_t i = 0; i < __length; i += h, it += h * 2) {
                    idft(std::fill_n(std::transform(dft(it + __length * 2, h), it + __length * 2 + h, dft(it + __length * 2 + h, h), it, std::multiplies<_Tp>()), h, 0) - h * 2, h);
                    it[h] = it[0] - 1, it[0] = 1;
                }
            }
            idft(std::transform(dft(s_treeBuffer, __length), s_treeBuffer + __length, dft(s_treeBuffer + __length, __length), s_treeSum.sizeTo(__length * 2).begin(), std::multiplies<_Tp>()) - __length, __length);
            s_treeSum[__length] = s_treeSum[0] - 1;
            s_treeSum[0] = 1;
        }
        static poly calcTree(const poly &__f, uint32_t id13) {
            uint32_t length = std::__bit_ceil(std::max<uint32_t>(__f.size(), s_treeSum.size() / 2));
            poly res(length);
            std::copy_n(__f.div(s_treeSum.reverse()).reverse().begin(), __f.size(), res.begin() + length - __f.size());
            for (uint32_t h = length / 2; h; h >>= 1)
                for (_Tp *it = res.data(), *end = res.data() + id13, *it2 = s_treeBuffer + length * 2 * std::__countr_zero(length / 2 / h); it < end; it += h * 2, it2 += h * 4) std::copy_n(s_dftBuffer + h, h, std::copy_n(idft(transform(idft(transform(std::copy_n(it2 + h * 2, h * 2, std::copy_n(it2, h * 2, s_dftBuffer)) - h * 4, dft(it, h * 2), h * 2), h * 2) + h * 2, it, h * 2), h * 2) + h, h, it));
            return res.sizeTo(id13);
        }
        static poly product(const poly &__a, const poly &__b, uint32_t __length) {
            if (__a.empty() || __b.empty()) return {};
            idft(transform(dft(s_dftBuffer, __length, __a.begin(), std::min<uint32_t>(__length, __a.size())), dft(s_dftBuffer + __length, __length, __b.begin(), std::min<uint32_t>(__length, __b.size())), __length), __length);
            return poly(s_dftBuffer, s_dftBuffer + __length);
        }
        static poly fromPoints(const poly &__xs, const poly &__ys) {
            if (__xs.size() <= 1) return __ys;
            uint32_t length = std::__bit_ceil(__xs.size());
            initTree(__xs, length);
            poly res = calcTree(poly(s_treeSum).sizeTo(__xs.size() + 1).reverse().derivate(), __xs.size()).sizeTo(length);
            for (uint32_t i = 0; i < __ys.size(); i++) res[i] = __ys[i] / res[i];
            for (uint32_t h = 1; h < length; h *= 2)
                for (_Tp *it = res.data(), *end = res.data() + __xs.size(), *it2 = s_treeBuffer + length * 2 * std::__countr_zero(length / 2 / h); it < end; it += h * 2, it2 += h * 4) {
                    dft(dft(s_dftBuffer, h * 2, it, h) + h * 2, h * 2, it + h, h);
                    for (uint32_t i = 0; i < h * 2; i++) it[i] = s_dftBuffer[i] * it2[h * 2 + i] + s_dftBuffer[h * 2 + i] * it2[i];
                    idft(it, h * 2);
                }
            return res.sizeTo(__xs.size()).reverse();
        }
        poly &shrink() {
            while (size() && !back()) pop_back();
            return *this;
        }
        poly &reverse() {
            std::reverse(begin(), end());
            return *this;
        }
        poly &sizeTo(uint32_t __size) {
            resize(__size);
            return *this;
        }
        poly &derivate() {
            derivate(begin(), size());
            pop_back();
            return *this;
        }
        poly &integrate() {
            push_back(0);
            integrate(begin(), size() - 1);
            return *this;
        }
        _Tp at(uint32_t __i) const { return __i < size() ? (*this)[__i] : 0; }
        poly &operator+=(const poly &__other) {
            transform(sizeTo(std::max<uint32_t>(size(), __other.size())).begin(), __other.begin(), __other.size(), std::plus<_Tp>());
            return shrink();
        }
        poly &operator-=(const poly &__other) {
            transform(sizeTo(std::max<uint32_t>(size(), __other.size())).begin(), __other.begin(), __other.size(), std::minus<_Tp>());
            return shrink();
        }
        poly &operator*=(_Tp __other) {
            if (!__other)
                clear();
            else
                for (auto &a : *this) a *= __other;
            return *this;
        }
        poly &operator*=(const poly &__other) { return (*this = product(*this, __other, std::__bit_ceil(size() + __other.size() - 1))).shrink(); }
        poly &operator/=(_Tp __other) {
            for (auto &a : *this) a /= __other;
            return *this;
        }
        poly operator+() const { return *this; }
        poly operator-() const {
            poly res(*this);
            std::transform(res.begin(), res.end(), res.begin(), std::negate<_Tp>());
            return res;
        }
        friend poly operator+(const poly &__a, const poly &__b) { return poly(__a) += __b; }
        friend poly operator-(const poly &__a, const poly &__b) { return poly(__a) -= __b; }
        friend poly operator*(const poly &__a, _Tp __b) { return poly(__a) *= __b; }
        friend poly operator*(const poly &__a, const poly &__b) { return (product(__a, __b, std::__bit_ceil(__a.size() + __b.size() - 1))).shrink(); }
        friend poly operator/(const poly &__a, _Tp __b) { return poly(__a) /= __b; }
        template <typename _Istream>
        friend _Istream &operator>>(_Istream &__is, poly &__self) {
            for (auto &a : __self) __is >> a;
            return __is;
        }
        template <typename _Ostream>
        friend _Ostream &operator<<(_Ostream &__os, const poly &__self) {
            for (auto &a : __self) __os << a << ' ';
            return __os;
        }
        poly ChirpZ(_Tp __x, uint32_t __n) const {
            if (empty()) return poly(__n, 0);
            uint32_t length = std::__bit_ceil(size() + __n - 1);
            const _Tp inv = __x.inv();
            _Tp cur = 1, pow = 1;
            for (uint32_t i = 0; i < size() + __n - 1; i++, cur *= pow, pow *= __x) s_dftBuffer[i] = cur;
            cur = 1, pow = 1;
            for (uint32_t i = size() - 1; ~i; i--, cur *= pow, pow *= inv) s_dftBuffer[length + i] = (*this)[size() - 1 - i] * cur;
            idft(transform(dft(std::fill_n(s_dftBuffer + size() + __n - 1, length - size() - __n + 1, 0) - length, length), dft(std::fill_n(s_dftBuffer + length + size(), length - size(), 0) - length, length), length), length);
            cur = _Tp(1).inv(), pow = 1;
            for (uint32_t i = size() - 1, j = 0; j < __n; i++, j++, cur *= pow, pow *= inv) s_dftBuffer[i] *= cur;
            return poly(s_dftBuffer + size() - 1, s_dftBuffer + size() - 1 + __n);
        }
        _Tp calc(_Tp __x) const {
            _Tp res = 0;
            for (uint32_t i = size() - 1; ~i; i--) res = res * __x + (*this)[i];
            return res;
        }
        poly inv() const {
            static constexpr uint32_t R = 16;
            uint32_t Block = std::__bit_ceil((size() - 1) / R + 1);
            _Tp f[R * Block * 2], g[R * Block * 2], res[(R + 1) * Block];
            res[0] = (*this)[0].inv();
            auto dfs = [&](auto self, uint32_t n) -> void {
                if (n == 1) return;
                uint32_t block = std::__bit_ceil((n - 1) / R + 1);
                self(self, block);
                dft(f, block * 2, begin(), block);
                for (uint32_t k = 1; k * block < n; k++) {
                    dft(f + k * 2 * block, block * 2, begin() + k * block, k * block < size() ? std::min<uint32_t>(size() - k * block, block) : 0);
                    dft(std::copy_n(std::fill_n(res + k * block, block * 2, 0) - 3 * block, block * 2, g + (k - 1) * 2 * block) - block * 2, block * 2);
                    for (uint32_t j = 0; j < k; j++)
                        for (_Tp *it = res + k * block, *it1 = g + j * 2 * block, *it2 = f + (k - j) * 2 * block, *it3 = f + (k - j - 1) * 2 * block, *end = res + (k + 2) * block; it != end;) *it++ -= *it1++ * (*it2++ + *it3++), *it++ -= *it1++ * (*it2++ - *it3++);
                    idft(transform(dft(id1(idft(res + k * block, block * 2), block * 2), block * 2), g, block * 2), block * 2);
                }
            };
            dfs(dfs, size());
            return poly(res, res + size());
        }
        poly sqrt(_Tp id6 = 1) const {
            static constexpr uint32_t R = 16;
            const _Tp inv2 = _Tp(_Tp::mod() / 2 + 1);
            uint32_t Block = std::__bit_ceil((size() - 1) / R + 1);
            _Tp g[R * Block * 2], h[Block * 2], res[(R + 1) * Block];
            res[0] = id6;
            auto dfs = [&](auto self, uint32_t n) {
                if (n == 1) return;
                uint32_t block = std::__bit_ceil((n - 1) / R + 1);
                self(self, block);
                dft(h, block * 2, poly(res, res + block).inv().begin(), block);
                std::fill_n(g, R * block * 2, 0);
                for (uint32_t k = 1; k * block < n; k++) {
                    dft(std::copy_n(std::fill_n(res + k * block, block * 2, 0) - 3 * block, block * 2, g + (k - 1) * 2 * block) - block * 2, block * 2);
                    for (uint32_t j = 0; j < k; j++)
                        for (_Tp *it = res + k * block, *it1 = g + j * 2 * block, *it2 = g + (k - j) * 2 * block, *it3 = g + (k - j - 1) * 2 * block, *end = res + (k + 2) * block; it != end;) *it++ -= *it1++ * (*it2++ + *it3++), *it++ -= *it1++ * (*it2++ - *it3++);
                    id1(idft(res + k * block, block * 2), block * 2);
                    for (uint32_t i = k * block, iend = (k + 1) * block; i < iend; i++) res[i] += at(i);
                    idft(transform(dft(res + k * block, block * 2), h, block * 2), block * 2);
                    for (uint32_t i = k * block, iend = (k + 1) * block; i < iend; i++) res[i] *= inv2;
                }
            };
            dfs(dfs, size());
            return poly(res, res + size());
        }
        std::pair<poly, poly> divmod(const poly &__other) const {
            poly x = div(__other, size() - __other.size() + 1);
            return {x, *this - x * __other};
        }
        poly div(const poly &__other, uint32_t __length = -1) const {
            chmin(__length, size());
            static constexpr uint32_t R = 16;
            uint32_t Block = std::__bit_ceil((__length - 1) / R + 1);
            _Tp f[R * Block * 2], g[R * Block * 2], h[Block * 2], a[R * Block], b[R * Block], res[(R + 1) * Block];
            poly binv = poly(__other).reverse().sizeTo(Block).inv();
            std::fill(std::copy_n(rbegin(), __length, a), a + R * Block, 0);
            std::fill(std::copy_n(__other.rbegin(), std::min<uint32_t>(__length, __other.size()), b), b + R * Block, 0);
            res[0] = a[0] * b[0].inv();
            auto dfs = [&](auto self, uint32_t n) -> void {
                if (n == 1) return;
                uint32_t block = std::__bit_ceil((n - 1) / R + 1);
                self(self, block);
                dft(h, block * 2, binv.begin(), block);
                dft(f, block * 2, b, block);
                for (uint32_t k = 1; k * block < n; k++) {
                    dft(f + k * 2 * block, block * 2, b + k * block, block);
                    dft(std::copy_n(std::fill_n(res + k * block, block * 2, 0) - 3 * block, block * 2, g + (k - 1) * 2 * block) - block * 2, block * 2);
                    for (uint32_t j = 0; j < k; j++)
                        for (_Tp *it = res + k * block, *it1 = g + j * 2 * block, *it2 = f + (k - j) * 2 * block, *it3 = f + (k - j - 1) * 2 * block, *end = res + (k + 2) * block; it != end;) *it++ -= *it1++ * (*it2++ + *it3++), *it++ -= *it1++ * (*it2++ - *it3++);
                    idft(transform(dft(transform(id1(idft(res + k * block, block * 2), block * 2), a + k * block, block, std::plus<_Tp>()), block * 2), h, block * 2), block * 2);
                }
            };
            dfs(dfs, __length);
            return poly(res, res + __length).reverse();
        }
        poly mod(const poly &__other) const { return divmod(__other).second; }
        poly logarithm() const {
            prepareInverse(size());
            poly f(*this);
            for (uint32_t i = 0; i < size(); i++) f[i] *= i;
            f = f.reverse().div(poly(*this).reverse()).reverse();
            for (uint32_t i = 1; i < size(); i++) f[i] *= s_inverse[i];
            return f;
        }
        poly exponent() const {
            static constexpr uint32_t R = 16;
            uint32_t Block = std::__bit_ceil((size() - 1) / R + 1);
            _Tp f[R * Block * 2], g[R * Block * 2], h[Block * 2], a[R * Block], res[(R + 1) * Block];
            std::fill(std::copy_n(begin(), size(), a), a + R * Block, 0);
            for (uint32_t i = 0; i < size(); i++) a[i] *= i;
            res[0] = 1;
            prepareInverse((R + 1) * Block);
            auto dfs = [&](auto self, uint32_t n) -> void {
                if (n == 1) return;
                uint32_t block = std::__bit_ceil((n - 1) / R + 1);
                self(self, block);
                dft(h, block * 2, poly(res, res + block).inv().begin(), block);
                dft(f, block * 2, a, block);
                for (uint32_t k = 1; k * block < n; k++) {
                    dft(f + k * 2 * block, block * 2, a + k * block, block);
                    dft(std::copy_n(std::fill_n(res + k * block, block * 2, 0) - 3 * block, block * 2, g + (k - 1) * 2 * block) - block * 2, block * 2);
                    for (uint32_t j = 0; j < k; j++)
                        for (_Tp *it = res + k * block, *it1 = g + j * 2 * block, *it2 = f + (k - j) * 2 * block, *it3 = f + (k - j - 1) * 2 * block, *end = res + (k + 2) * block; it != end;) *it++ += *it1++ * (*it2++ + *it3++), *it++ += *it1++ * (*it2++ - *it3++);
                    idft(transform(dft(transform(id1(idft(transform(dft(id1(idft(res + k * block, block * 2), block * 2), block * 2), h, block * 2), block * 2), block * 2), s_inverse + k * block, block), block * 2), g, block * 2), block * 2);
                }
            };
            dfs(dfs, size());
            return poly(res, res + size());
        }
        poly calc(const poly &__xs) const {
            initTree(__xs, std::__bit_ceil(std::max<uint32_t>(__xs.size(), size())));
            return calcTree(*this, __xs.size());
        }
    };
}

using mint = OY::StaticModInt32<998244353, true>;
using poly = OY::NTTPolynomial<mint, 1 << 20>;
OY::StaticCombinationTable32<998244353> table(1000000);
int main() {
    poly::s_primitiveRoot = 3;

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        poly A(n + 1), B(n + 1);
        for (int four_pairs = 0; four_pairs * 4 <= n; four_pairs++) {
            A[four_pairs * 4] = mint(table.m_factorial[n - four_pairs * 2]) / table.m_factorial[four_pairs];
        }
        for (int two_pairs = 0; two_pairs * 2 <= n; two_pairs++) {
            B[two_pairs * 2] = mint(1) / table.m_factorial[two_pairs] / mint(2).pow(two_pairs);
        }
        poly C = A * B;

        mint ans = 0;
        for (int i = 0; i <= n; i++) ans += C.at(i) * mint(1) / table.m_factorial[n - i];
        cout << ans << '\n';
    }
}