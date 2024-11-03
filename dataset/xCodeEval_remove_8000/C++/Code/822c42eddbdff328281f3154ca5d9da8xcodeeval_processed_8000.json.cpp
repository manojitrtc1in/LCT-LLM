

























template <typename _Tp, typename _Fp, typename _Compare = std::less<void>>
bool chmax(_Tp &a, const _Fp &b, _Compare __comp = _Compare()) { return __comp(a, b) ? a = b, true : false; }
template <typename _Tp, typename _Fp, typename _Compare = std::less<void>>
bool chmin(_Tp &a, const _Fp &b, _Compare __comp = _Compare()) { return __comp(b, a) ? a = b, true : false; }
using std::cin, std::cout, std::endl;
int _IO = [] {std::ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);

    freopen("in.txt","r",stdin);freopen("out.txt","w",stdout);

return 0; }();
auto tam = [] {


    struct id13 {static auto GetMicroSecond() {static FILETIME ft;GetSystemTimeAsFileTime(&ft);return ft.dwLowDateTime;};static auto GetMemory() {PROCESS_MEMORY_COUNTERS pmc;GetProcessMemoryInfo(GetCurrentProcess(), &pmc, sizeof(pmc));return pmc.WorkingSetSize;}uint32_t t0, t1;id13() : t0(GetMicroSecond()) {}void stop() {t1 = GetMicroSecond();cout << "\ntime cost = " << (t1 - t0) / 10000.0 << " ms\nmemory cost = " << (GetMemory() >> 20) << " MB\n ";t0 = t1;}~id13() { stop(); }};return id13();


    return 0;

}();
namespace OY {
    template <typename _ModType>
    struct Barrett {
        _ModType m_P;
        __uint128_t id14;
        constexpr Barrett() = default;
        constexpr explicit Barrett(_ModType __P) : m_P(__P), id14(-uint64_t(__P) / __P + 1) {}
        constexpr _ModType mod() const { return m_P; }
        constexpr _ModType mod(uint64_t __a) const {
            __a -= uint64_t(id14 * __a >> 64) * m_P + m_P;
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
            _Tp res = id14 * __a >> 64;
            if (__a - res * m_P >= m_P) res++;
            return res;
        }
        template <typename _Tp>
        constexpr std::pair<_Tp, _Tp> divmod(_Tp __a) const {
            _Tp quo = (__a * id14) >> 64, rem = __a - quo * m_P;
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
        _ModType id14;
        _ModType m_Ninv;
        Barrett<_ModType> m_brt;
        constexpr Montgomery() = default;
        constexpr explicit Montgomery(_ModType __P) : m_P(__P), id14(__P), m_Ninv(-_LongType(__P) % __P), m_brt(__P) {
            for (int i = 0; i < _MontgomeryTag<_ModType>::inv_loop; i++) id14 *= _ModType(2) - __P * id14;
        }
        constexpr _ModType mod() const { return m_brt.mod(); }
        constexpr _ModType mod(uint64_t __a) const { return m_brt.mod(__a); }
        constexpr _FastType init(uint64_t __a) const { return reduce(_LongType(mod(__a)) * m_Ninv); }
        constexpr _FastType raw_init(uint64_t __a) const { return reduce(_LongType(__a) * m_Ninv); }
        constexpr _FastType reduce(_LongType __a) const {
            _FastType res = (__a >> _MontgomeryTag<_ModType>::length) - _ModType(_LongType(_ModType(__a) * id14) * m_P >> _MontgomeryTag<_ModType>::length);
            if (res >= mod()) res += mod();
            return res;
        }
        constexpr _ModType reduce(_FastType __a) const {
            _ModType res = -_ModType(_LongType(__a * id14) * m_P >> _MontgomeryTag<_ModType>::length);
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
    template <typename _ModType, _ModType _Id>
    struct id1 {
        using mint = id1<_ModType, _Id>;
        using _FastType = typename Montgomery<_ModType>::_FastType;
        static inline Montgomery<_ModType> id3 = Montgomery<_ModType>(_Id);
        static inline bool id16 = true;
        _FastType m_val;
        constexpr id1() = default;
        template <typename _Tp, std::enable_if_t<std::is_signed_v<_Tp>, bool> = true>
        constexpr id1(_Tp __val) : m_val(0) {
            int64_t x = int64_t(__val) % int64_t(mod());
            if (x < 0) x += mod();
            m_val = id3.init(x);
        }
        template <typename _Tp, std::enable_if_t<std::is_unsigned_v<_Tp>, bool> = true>
        constexpr id1(_Tp __val) : m_val(id3.init(__val)) {}
        static constexpr mint raw(_FastType __val) {
            mint res;
            res.m_val = __val;
            return res;
        }
        static constexpr void setMod(_ModType __P, bool id12 = false) {
            assert(__P % 2 == 1 && __P > 1 && __P < _MontgomeryTag<_ModType>::limit);
            id3 = Montgomery<_ModType>(__P);
            id16 = id12;
        }
        static constexpr _ModType mod() { return id3.mod(); }
        constexpr _ModType val() const { return id3.reduce(m_val); }
        constexpr mint pow(uint64_t __n) const { return raw(id3.pow(m_val, __n)); }
        constexpr mint inv() const { return id16 ? inv_Fermat() : inv_exgcd(); }
        constexpr mint inv_exgcd() const {
            _ModType x = mod(), y = val(), m0 = 0, m1 = 1;
            while (y) {
                _ModType z = x / y;
                x -= y * z;
                m0 -= m1 * z;
                std::swap(x, y);
                std::swap(m0, m1);
            }
            if (m0 >= mod()) m0 += mod() / x;
            return m0;
        }
        constexpr mint inv_Fermat() const { return pow(mod() - 2); }
        constexpr mint &operator++() {
            (*this) += raw(id3.raw_init(1));
            return *this;
        }
        constexpr mint &operator--() {
            (*this) += raw(id3.raw_init(mod() - 1));
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
            m_val = id3.plus(m_val, __other.m_val);
            return *this;
        }
        constexpr mint &operator-=(const mint &__other) {
            m_val = id3.minus(m_val, __other.m_val);
            return *this;
        }
        constexpr mint &operator*=(const mint &__other) {
            m_val = id3.multiply(m_val, __other.m_val);
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
        constexpr explicit operator _Tp() const { return _Tp(id3.reduce(m_val)); }
        constexpr friend mint operator+(const mint &a, const mint &b) { return mint(a) += b; }
        constexpr friend mint operator-(const mint &a, const mint &b) { return mint(a) -= b; }
        constexpr friend mint operator*(const mint &a, const mint &b) { return mint(a) *= b; }
        constexpr friend mint operator/(const mint &a, const mint &b) { return mint(a) /= b; }
        template <typename _Istream>
        friend _Istream &operator>>(_Istream &is, mint &self) {
            _ModType x;
            is >> x;
            self = mint(x);
            return is;
        }
        template <typename _Ostream>
        friend _Ostream &operator<<(_Ostream &os, const mint &self) { return os << self.val(); }
    };
    template <uint32_t _Id>
    using DynamicMontgomeryModInt32 = id1<uint32_t, _Id>;
    template <uint64_t _Id>
    using DynamicMontgomeryModInt64 = id1<uint64_t, _Id>;
}
namespace OY {
    template <typename _Tp, uint32_t _MAXN = 1 << 22>
    struct NTTPolynomial : std::vector<_Tp> {
        using poly = NTTPolynomial<_Tp, _MAXN>;
        using std::vector<_Tp>::vector, std::vector<_Tp>::begin, std::vector<_Tp>::end, std::vector<_Tp>::rbegin, std::vector<_Tp>::rend, std::vector<_Tp>::size, std::vector<_Tp>::back, std::vector<_Tp>::empty, std::vector<_Tp>::clear, std::vector<_Tp>::pop_back, std::vector<_Tp>::resize, std::vector<_Tp>::push_back;
        static inline _Tp s_dftRoots[_MAXN], s_dftBuffer[_MAXN * 2], s_inverse[_MAXN + 1], s_primitiveRoot, s_treeBuffer[_MAXN * 2 * (std::__countr_zero(_MAXN))];
        static inline uint32_t s_dftBin[_MAXN * 2], id4 = 1, id0 = 0;
        static inline poly s_treeSum;
        static void prepareDFT(uint32_t __length) {
            if (__length == 1 || s_dftBin[__length + 1]) return;
            if (id4 == 1) s_dftRoots[id4++] = _Tp(1);
            while (id4 < __length) {
                const _Tp wn = s_primitiveRoot.pow((_Tp::mod() - 1) / (id4 * 2));
                for (uint32_t i = id4; i < id4 * 2; i += 2) {
                    s_dftRoots[i] = s_dftRoots[i / 2];
                    s_dftRoots[i + 1] = s_dftRoots[i / 2] * wn;
                }
                id4 *= 2;
            }
            for (uint32_t i = 0; i < __length; i += 2) {
                s_dftBin[__length + i] = s_dftBin[__length + i / 2] / 2;
                s_dftBin[__length + i + 1] = s_dftBin[__length + i / 2] / 2 + __length / 2;
            }
        }
        template <typename _Iterator>
        static _Iterator id5(_Iterator __iter, uint32_t __length) {
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
        static _Iterator id2(_Iterator __iter, uint32_t __length) { return std::fill_n(__iter + __length / 2, __length / 2, 0) - __length; }
        template <typename _Iterator>
        static _Iterator dft(_Iterator __iter, uint32_t __length) {
            prepareDFT(__length);
            return id5(__iter, __length);
        }
        template <typename _Iterator, typename _Iterator2>
        static _Iterator dft(_Iterator __iter, uint32_t id8, _Iterator2 __source, uint32_t id9) { return dft(std::fill_n(std::copy_n(__source, id9, __iter), id8 - id9, 0) - id8, id8); }
        template <typename _Iterator>
        static _Iterator idft(_Iterator __iter, uint32_t __length) {
            id5(__iter, __length);
            std::reverse(__iter + 1, __iter + __length);
            const _Tp inv = _Tp(__length).inv();
            for (uint32_t i = 0; i < __length; i++) __iter[i] *= inv;
            return __iter;
        }
        template <typename _Iterator, typename _Iterator2, typename _Operation = std::multiplies<_Tp>>
        static _Iterator transform(_Iterator id11, _Iterator2 id6, uint32_t __length, _Operation __op = _Operation()) { return std::transform(id11, id11 + __length, id6, id11, __op) - __length; }
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
        static poly calcTree(const poly &__f, uint32_t id17) {
            uint32_t length = std::__bit_ceil(std::max<uint32_t>(__f.size(), s_treeSum.size() / 2));
            poly res(length);
            std::copy_n(__f.div(s_treeSum.reverse()).reverse().begin(), __f.size(), res.begin() + length - __f.size());
            for (uint32_t h = length / 2; h; h >>= 1)
                for (_Tp *it = res.data(), *end = res.data() + id17, *it2 = s_treeBuffer + length * 2 * std::__countr_zero(length / 2 / h); it < end; it += h * 2, it2 += h * 4) std::copy_n(s_dftBuffer + h, h, std::copy_n(idft(transform(idft(transform(std::copy_n(it2 + h * 2, h * 2, std::copy_n(it2, h * 2, s_dftBuffer)) - h * 4, dft(it, h * 2), h * 2), h * 2) + h * 2, it, h * 2), h * 2) + h, h, it));
            return res.sizeTo(id17);
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
                    idft(transform(dft(id2(idft(res + k * block, block * 2), block * 2), block * 2), g, block * 2), block * 2);
                }
            };
            dfs(dfs, size());
            return poly(res, res + size());
        }
        poly sqrt(_Tp id7 = 1) const {
            static constexpr uint32_t R = 16;
            const _Tp inv2 = _Tp(_Tp::mod() / 2 + 1);
            uint32_t Block = std::__bit_ceil((size() - 1) / R + 1);
            _Tp g[R * Block * 2], h[Block * 2], res[(R + 1) * Block];
            res[0] = id7;
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
                    id2(idft(res + k * block, block * 2), block * 2);
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
                    idft(transform(dft(transform(id2(idft(res + k * block, block * 2), block * 2), a + k * block, block, std::plus<_Tp>()), block * 2), h, block * 2), block * 2);
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
                    idft(transform(dft(transform(id2(idft(transform(dft(id2(idft(res + k * block, block * 2), block * 2), block * 2), h, block * 2), block * 2), block * 2), s_inverse + k * block, block), block * 2), g, block * 2), block * 2);
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
namespace OY {

    template <uint32_t _B = 10, uint32_t _W = 6, uint32_t _MAXN = 1 << 22, uint64_t _P = 9223372036737335297, uint64_t _R = 3>
    struct BigInt {
        using bint = BigInt<_B, _W, _MAXN, _P, _R>;
        static constexpr struct _Bases {
            uint64_t val[_W * 2 + 1];
            constexpr _Bases() : val{} {
                val[0] = 1;
                for (uint32_t i = 1; i <= _W * 2; i++) val[i] = val[i - 1] * _B;
            }
        } bases{};
        static constexpr uint32_t _N = bases.val[_W];
        int *m_data;
        uint32_t m_length;
        bool m_negative;
        BigInt() = default;
        template <typename _Tp, std::enable_if_t<std::is_integral_v<_Tp>, bool> = true>
        explicit BigInt(_Tp __number) : BigInt(fromString(std::to_string(__number).data())) {}
        explicit BigInt(__int128_t __number) : m_length(0) {
            static char s_buffer[40], *s_cursor;
            for (s_cursor = s_buffer; __number; __number /= 10) *s_cursor++ = '0' + __number % 10;
            std::reverse(s_buffer, s_cursor);
            *this = fromString(s_buffer, s_cursor - s_buffer);
        }
        BigInt(const char *__number) : BigInt(fromString(__number)) {}
        BigInt(const std::string &__number) : BigInt(fromString(__number.data(), __number.size())) {}
        BigInt(bint &&__other) : m_data(__other.m_data), m_length(__other.m_length), m_negative(__other.m_negative) { __other.m_length = 0; }
        BigInt(const bint &__other) : m_length(__other.m_length), m_negative(__other.m_negative) {
            if (m_length) std::copy_n(__other.m_data, m_length, m_data = new int[m_length]);
        }
        ~BigInt() {
            if (m_length) delete[] m_data;
        }
        static bint fromString(const char *__number) { return fromString(__number, std::strlen(__number)); }
        static bint fromString(const char *__number, uint32_t length) {
            bint res;
            uint32_t cursor = 0;
            if (__number[0] == '-') {
                res.m_negative = true;
                cursor++;
            } else {
                res.m_negative = false;
                if (__number[0] == '+') cursor++;
            }
            while (cursor < length && __number[cursor] == '0') cursor++;
            if (res.m_length = (length - cursor + _W - 1) / _W; !res.m_length) return res;
            res.m_data = new int[res.m_length]{};
            uint32_t i = res.m_length - 1;
            if (uint32_t rest = (length - cursor) % _W; rest) {
                uint32_t digit = 0;
                while (rest--) digit = digit * _B + (__number[cursor++] - '0');
                res.m_data[i--] = digit;
            }
            while (cursor < length) {
                uint32_t digit = 0;
                for (uint32_t j = _W; j--;) digit = digit * _B + (__number[cursor++] - '0');
                res.m_data[i--] = digit;
            }
            return res;
        }
        static bint zero() { return empty(0, false); }
        static bint small(int id15) {
            bint res = empty(1, id15 < 0);
            res.m_data[0] = std::abs(id15);
            return res;
        }
        static bint rand(uint32_t __length) {
            if (!__length) return zero();
            static std::mt19937 id10;
            bint res(empty(__length, false));
            for (uint32_t i = 0; i < __length; i++) res.m_data[i] = id10() % _N;
            while (!res.m_data[res.m_length - 1]) res.m_data[res.m_length - 1] = id10() % _N;
            return res;
        }
        static bint empty(uint32_t __length, bool __negative) {
            bint res;
            if (__length) res.m_data = new int[__length];
            res.m_length = __length;
            res.m_negative = __negative;
            return res;
        }
        static int absCompare(const bint &__a, const bint &__b) {
            if (__a.m_length != __b.m_length) return __a.m_length > __b.m_length ? 1 : -1;
            for (uint32_t i = __a.m_length - 1; ~i; i--)
                if (__a.m_data[i] != __b.m_data[i]) return __a.m_data[i] > __b.m_data[i] ? 1 : -1;
            return 0;
        }
        static std::pair<bint, bint> divmod(const bint &__a, const bint &__b) {
            int comp = absCompare(__a, __b);
            if (comp < 0) return {zero(), __a};
            if (comp == 0) return {small(__a.m_negative == __b.m_negative ? 1 : -1), zero()};
            uint32_t shift = __a.m_length > __b.m_length * 2 ? __a.m_length - __b.m_length * 2 : 0, n = __a.m_length + shift, m = __b.m_length + shift;
            bint a(__a << shift * _W), b(__b << shift * _W);
            a.m_negative = b.m_negative = false;
            bint bi(b.inv()), prod(b * bi), ans(0);
            if (prod.m_length >= m * 2) prod -= b, --bi;
            while (b <= a) {
                bint c = a * bi >> (m * 2 * _W);
                if (!c.m_length) break;
                a -= b * c, ans += c;
            }
            while (b <= a) a -= b, ++ans;
            ans.m_negative = __a.m_negative != __b.m_negative;
            return {ans, shift ? a >> shift * _W : a};
        }
        static bint div(const bint &__a, const bint &__b) {
            int comp = absCompare(__a, __b);
            if (comp < 0) return zero();
            if (comp == 0) return small(__a.m_negative == __b.m_negative ? 1 : -1);
            uint32_t shift = __a.m_length > __b.m_length * 2 ? __a.m_length - __b.m_length * 2 : 0, n = __a.m_length + shift, m = __b.m_length + shift;
            bint a(__a << shift * _W), b(__b << shift * _W);
            a.m_negative = b.m_negative = false;
            bint bi(b.inv()), prod(b * bi), ans(0);
            if (prod.m_length >= m * 2) prod -= b, --bi;
            while (b <= a) {
                bint c = a * bi >> (m * 2 * _W);
                if (!c.m_length) break;
                a -= b * c, ans += c;
            }
            while (b <= a) a -= b, ++ans;
            ans.m_negative = __a.m_negative != __b.m_negative;
            return ans;
        }
        bint &shrink() {
            if (!m_length) return *this;
            while (m_length && !m_data[m_length - 1]) m_length--;
            if (m_length) return *this;
            delete[] m_data;
            m_negative = false;
            return *this;
        }
        bint &opposite() {
            if (m_length) m_negative = !m_negative;
            return *this;
        }
        bint &operator=(bint &&__other) {
            if (m_length) delete[] m_data;
            m_length = __other.m_length;
            m_negative = __other.m_negative;
            m_data = __other.m_data;
            __other.m_length = 0;
            return *this;
        }
        bint &operator=(const bint &__other) {
            if (m_length) delete[] m_data;
            m_length = __other.m_length;
            m_negative = __other.m_negative;
            if (m_length) std::copy_n(__other.m_data, m_length, m_data = new int[m_length]);
            return *this;
        }
        bint &operator++() {
            if (!m_negative) {
                uint32_t i = 0;
                while (i < m_length && ++m_data[i] == _N) m_data[i++] = 0;
                if (i < m_length) return *this;
                bint res(empty(m_length + 1, false));
                std::fill_n(res.m_data, res.m_length - 1, 0);
                res.m_data[res.m_length - 1] = 1;
                return *this = res;
            } else {
                uint32_t i = 0;
                while (i < m_length && !m_data[i]--) m_data[i++] = _N - 1;
                if (!m_data[m_length - 1] && !--m_length) {
                    delete[] m_data;
                    m_negative = false;
                }
                return *this;
            }
        }
        bint &operator--() {
            if (m_negative) {
                uint32_t i = 0;
                while (i < m_length && ++m_data[i] == _N) m_data[i++] = 0;
                if (i < m_length) return *this;
                bint res(empty(m_length + 1, true));
                std::fill_n(res.m_data, res.m_length - 1, 0);
                res.m_data[res.m_length - 1] = 1;
                return *this = res;
            } else {
                if (!m_length) return *this = small(-1);
                uint32_t i = 0;
                while (i < m_length && !m_data[i]--) m_data[i++] = _N - 1;
                if (!m_data[m_length - 1] && !--m_length) delete[] m_data;
                return *this;
            }
        }
        bint inv() const {
            if (m_length == 1)
                return bint(bases.val[_W * 2] / m_data[0]);
            else if (m_length == 2)
                return bint(__int128_t(bases.val[_W * 2]) * bases.val[_W * 2] / (__int128_t(m_data[1]) * _N + m_data[0]));
            else {
                bint res((*this >> (m_length - 1) / 2 * _W).inv());
                return ((res + res) << (m_length - 1) / 2 * _W) - ((*this * res * res) >> (m_length / 2 + 1) * 2 * _W);
            }
        }
        bint operator++(int) {
            bint old(*this);
            ++*this;
            return old;
        }
        bint operator--(int) {
            bint old(*this);
            --*this;
            return old;
        }
        bint &operator+=(const bint &__other) {
            if (!__other.m_length) return *this;
            if (m_negative == __other.m_negative) {
                if (__other.m_length <= m_length && m_data[__other.m_length - 1] + __other.m_data[__other.m_length - 1] < _N) {
                    for (uint32_t i = 0, carry = 0; i < __other.m_length; i++)
                        if (m_data[i] += __other.m_data[i] + carry; carry = m_data[i] >= _N) m_data[i] -= _N;
                    return *this;
                }
                bint res(empty(std::max(m_length, __other.m_length) + 1, m_negative));
                for (uint32_t i = 0, carry = 0; i < res.m_length; i++)
                    if (res.m_data[i] = (i < m_length ? m_data[i] : 0) + (i < __other.m_length ? __other.m_data[i] : 0) + carry; carry = res.m_data[i] >= _N) res.m_data[i] -= _N;
                if (!res.m_data[res.m_length - 1] && !--res.m_length) delete[] res.m_data;
                return *this = res;
            } else {
                if (int comp = absCompare(*this, __other); comp > 0) {
                    for (uint32_t i = 0, borrow = 0; i < m_length; i++)
                        if (m_data[i] -= (i < __other.m_length ? __other.m_data[i] : 0) + borrow; borrow = m_data[i] < 0) m_data[i] += _N;
                    return (*this).shrink();
                } else if (comp < 0) {
                    bint res(empty(__other.m_length, __other.m_negative));
                    for (uint32_t i = 0, borrow = 0; i < res.m_length; i++)
                        if (res.m_data[i] = __other.m_data[i] - (i < m_length ? m_data[i] : 0) - borrow; borrow = res.m_data[i] < 0) res.m_data[i] += _N;
                    return (*this = res).shrink();
                } else
                    return *this = zero();
            }
        }
        bint &operator-=(const bint &__other) {
            if (!__other.m_length) return *this;
            if (m_negative != __other.m_negative) {
                if (__other.m_length <= m_length && m_data[__other.m_length - 1] < __other.m_data[__other.m_length - 1]) {
                    for (uint32_t i = 0, carry = 0; i < __other.m_length; i++)
                        if (m_data[i] += __other.m_data[i] + carry; carry = m_data[i] >= _N) m_data[i] -= _N;
                    return *this;
                }
                bint res(empty(std::max(m_length, __other.m_length) + 1, m_negative));
                for (uint32_t i = 0, carry = 0; i < res.m_length; i++)
                    if (res.m_data[i] = (i < m_length ? m_data[i] : 0) + (i < __other.m_length ? __other.m_data[i] : 0) + carry; carry = res.m_data[i] >= _N) res.m_data[i] -= _N;
                if (!res.m_data[res.m_length - 1]) res.m_length--;
                return *this = res;
            } else {
                if (int comp = absCompare(*this, __other); comp > 0) {
                    for (uint32_t i = 0, borrow = 0; i < m_length; i++)
                        if (m_data[i] -= (i < __other.m_length ? __other.m_data[i] : 0) + borrow; borrow = m_data[i] < 0) m_data[i] += _N;
                    return (*this).shrink();
                } else if (comp < 0) {
                    bint res(empty(__other.m_length, __other.m_negative));
                    for (uint32_t i = 0, borrow = 0; i < res.m_length; i++)
                        if (res.m_data[i] = __other.m_data[i] - (i < m_length ? m_data[i] : 0) - borrow; borrow = res.m_data[i] < 0) res.m_data[i] += _N;
                    return (*this = res).shrink();
                } else
                    return *this = zero();
            }
        }
        bint &operator*=(const bint &__other) { return *this = *this * __other; }
        bint &operator/=(const bint &__other) { return *this = *this / __other; }
        bint &operator%=(const bint &__other) { return *this = *this % __other; }
        bint &operator<<=(uint32_t __shift) { return *this = *this << __shift; }
        bint &operator>>=(uint32_t __shift) {
            auto [quot, rem] = std::div((int)__shift, (int)_W);
            if (quot >= m_length || (quot == m_length - 1 && m_data[m_length - 1] < bases.val[rem])) return *this = zero();
            std::copy_n(m_data + quot, m_length -= quot, m_data);
            if (!rem) return *this;
            uint64_t carry = 0;
            for (uint32_t i = m_length - 1; ~i; i--) {
                auto [q, r] = std::div(m_data[i], int(bases.val[rem]));
                m_data[i] = carry * bases.val[_W - rem] + q;
                carry = r;
            }
            return shrink();
        }
        bint operator+() const { return *this; }
        bint operator-() const { return bint(*this).opposite(); }
        bool operator==(const bint &__other) const { return m_negative == __other.m_negative && !absCompare(*this, __other); }
        bool operator!=(const bint &__other) const { return m_negative != __other.m_negative && absCompare(*this, __other); }
        bool operator<(const bint &__other) const { return m_negative == __other.m_negative ? (m_negative ? absCompare(*this, __other) > 0 : absCompare(*this, __other) < 0) : m_negative; }
        bool operator>(const bint &__other) const { return m_negative == __other.m_negative ? (m_negative ? absCompare(*this, __other) < 0 : absCompare(*this, __other) > 0) : !m_negative; }
        bool operator<=(const bint &__other) const { return m_negative == __other.m_negative ? (m_negative ? absCompare(*this, __other) >= 0 : absCompare(*this, __other) <= 0) : m_negative; }
        bool operator>=(const bint &__other) const { return m_negative == __other.m_negative ? (m_negative ? absCompare(*this, __other) <= 0 : absCompare(*this, __other) >= 0) : !m_negative; }
        explicit operator bool() const { return m_length; }
        operator std::string() const {
            if (!m_length) return "0";
            std::string res(m_length * _W, '0');
            for (uint32_t i = 0; i < m_length; i++)
                for (uint32_t j = i * _W, digit = m_data[i]; digit; j++, digit /= _B) res[j] = '0' + digit % _B;
            while (res.size() && res.back() == '0') res.pop_back();
            if (m_negative) res.push_back('-');
            std::reverse(res.begin(), res.end());
            return res;
        }
        friend bint operator+(const bint &__a, const bint &__b) {
            if (!__a.m_length) return __b;
            if (!__b.m_length) return __a;
            if (__a.m_negative == __b.m_negative) {
                bint res(empty(std::max(__a.m_length, __b.m_length) + 1, __a.m_negative));
                for (uint32_t i = 0, carry = 0; i < res.m_length; i++)
                    if (res.m_data[i] = (i < __a.m_length ? __a.m_data[i] : 0) + (i < __b.m_length ? __b.m_data[i] : 0) + carry; carry = res.m_data[i] >= _N) res.m_data[i] -= _N;
                return res.shrink();
            } else {
                if (int comp = absCompare(__a, __b); comp > 0) {
                    bint res(empty(__a.m_length, __a.m_negative));
                    for (uint32_t i = 0, borrow = 0; i < res.m_length; i++)
                        if (res.m_data[i] = __a.m_data[i] - (i < __b.m_length ? __b.m_data[i] : 0) - borrow; borrow = res.m_data[i] < 0) res.m_data[i] += _N;
                    return res.shrink();
                } else if (comp < 0) {
                    bint res(empty(__b.m_length, __b.m_negative));
                    for (uint32_t i = 0, borrow = 0; i < res.m_length; i++)
                        if (res.m_data[i] = __b.m_data[i] - (i < __a.m_length ? __a.m_data[i] : 0) - borrow; borrow = res.m_data[i] < 0) res.m_data[i] += _N;
                    return res.shrink();
                } else
                    return zero();
            }
        }
        friend bint operator-(const bint &__a, const bint &__b) {
            if (!__a.m_length) return -__b;
            if (!__b.m_length) return __a;
            if (__a.m_negative != __b.m_negative) {
                bint res(empty(std::max(__a.m_length, __b.m_length) + 1, __a.m_negative));
                for (uint32_t i = 0, carry = 0; i < res.m_length; i++)
                    if (res.m_data[i] = (i < __a.m_length ? __a.m_data[i] : 0) + (i < __b.m_length ? __b.m_data[i] : 0) + carry; carry = res.m_data[i] >= _N) res.m_data[i] -= _N;
                return res.shrink();
            } else {
                if (int comp = absCompare(__a, __b); comp > 0) {
                    bint res(empty(__a.m_length, __a.m_negative));
                    for (uint32_t i = 0, borrow = 0; i < res.m_length; i++)
                        if (res.m_data[i] = __a.m_data[i] - (i < __b.m_length ? __b.m_data[i] : 0) - borrow; borrow = res.m_data[i] < 0) res.m_data[i] += _N;
                    return res.shrink();
                } else if (comp < 0) {
                    bint res(empty(__b.m_length, !__a.m_negative));
                    for (uint32_t i = 0, borrow = 0; i < res.m_length; i++)
                        if (res.m_data[i] = __b.m_data[i] - (i < __a.m_length ? __a.m_data[i] : 0) - borrow; borrow = res.m_data[i] < 0) res.m_data[i] += _N;
                    return res.shrink();
                } else
                    return zero();
            }
        }
        friend bint operator*(const bint &__a, const bint &__b) {
            if (!__a.m_length || !__b.m_length) return zero();
            using poly = NTTPolynomial<DynamicMontgomeryModInt64<_P>, _MAXN>;
            poly::s_primitiveRoot = _R;
            uint32_t length = std::__bit_ceil(__a.m_length + __b.m_length - 1);
            poly::idft(poly::transform(poly::dft(poly::s_dftBuffer, length, __a.m_data, __a.m_length), poly::dft(poly::s_dftBuffer + length, length, __b.m_data, __b.m_length), length), length);
            bint res(empty(__a.m_length + __b.m_length, __a.m_negative != __b.m_negative));
            long long carry = 0;
            for (uint32_t i = 0; i + 1 < res.m_length; i++) {
                auto [quot, rem] = std::div((long long)(poly::s_dftBuffer[i].val() + carry), (long long)_N);
                carry = quot;
                res.m_data[i] = rem;
            }
            if (carry)
                res.m_data[res.m_length - 1] = carry;
            else
                res.m_length--;
            return res;
        }
        friend bint operator/(const bint &__a, const bint &__b) { return div(__a, __b); }
        friend bint operator%(const bint &__a, const bint &__b) { return divmod(__a, __b).second; }
        friend bint operator<<(const bint &__a, uint32_t __shift) {
            auto [quot, rem] = std::div((int)__shift, (int)_W);
            bint res(empty(__a.m_length + quot + (rem > 0), __a.m_negative));
            std::copy_n(__a.m_data, __a.m_length, std::fill_n(res.m_data, quot, 0));
            if (!rem) return res;
            uint64_t carry = 0;
            for (uint32_t i = quot; i + 1 < res.m_length; i++) {
                auto [q, r] = std::div((long long)(res.m_data[i]) * bases.val[rem] + carry, (long long)_N);
                carry = q;
                res.m_data[i] = r;
            }
            if (carry)
                res.m_data[res.m_length - 1] = carry;
            else
                res.m_length--;
            return res;
        }
        friend bint operator>>(const bint &__a, uint32_t __shift) {
            auto [quot, rem] = std::div((int)__shift, (int)_W);
            if (quot >= __a.m_length || (quot == __a.m_length - 1 && __a.m_data[__a.m_length - 1] < bases.val[rem])) return zero();
            bint res(empty(__a.m_length - quot, __a.m_negative));
            std::copy_n(__a.m_data + quot, __a.m_length - quot, res.m_data);
            if (!rem) return res;
            uint64_t carry = 0;
            for (uint32_t i = res.m_length - 1; ~i; i--) {
                auto [q, r] = std::div(res.m_data[i], int(bases.val[rem]));
                res.m_data[i] = carry * bases.val[_W - rem] + q;
                carry = r;
            }
            return res.shrink();
        }
        template <typename _Istream>
        friend _Istream &operator>>(_Istream &is, bint &self) {
            std::string number;
            is >> number;
            self = fromString(number.data(), number.size());
            return is;
        }
        template <typename _Ostream>
        friend _Ostream &operator<<(_Ostream &os, const bint &self) { return os << std::string(self); }
    };

}


using bint = OY::BigInt<10,8,1<<7>;
struct node {
    bint start, length;
    node():start(0),length(0){}
    node(bint _x,bint _y):start(_x),length(_y){}
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        std::vector<node> come[n];
        for (int i = 0; i < n; i++) {
            bint x(0);
            cin >> x;
            if(x)come[i].push_back({bint(0), x});
        }
        int indeg[n];
        memset(indeg, 0, sizeof(indeg));
        std::vector<int> adj[n];
        for (int i = 0; i < m; i++) {
            int x, y;
            cin >> x >> y;
            adj[x - 1].push_back(y - 1);
            indeg[y - 1]++;
        }

        std::queue<int> Q;
        for (int i = 0; i < n; i++)
            if (!indeg[i]) Q.push(i);
        bint ans(0);
        while (Q.size()) {
            auto p = Q.front();
            Q.pop();
            std::sort(all(come[p]), [](auto &x, auto &y) { return x.start < y.start; });
            std::vector<node> go;
            bint cur(0), now(0);
            for (auto &[start, len] : come[p]) {
                if (!now) {
                    cur = start;
                    now = len;
                } else if (start <= cur + now) {
                    now += len;
                } else {
                    go.push_back({cur + bint(1), now});
                    cur = start;
                    now = len;
                }
            }
            if (now) go.push_back({cur + bint(1), now});
            chmax(ans, cur + now);
            for (int a : adj[p]) {
                come[a].insert(come[a].end(), all(go));
                if (!--indeg[a]) Q.push(a);
            }
        }
        cout << ans % bint(998244353) << '\n';
    }
}
