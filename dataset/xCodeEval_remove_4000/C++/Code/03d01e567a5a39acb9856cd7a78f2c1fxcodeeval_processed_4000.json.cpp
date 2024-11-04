








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
    struct id4 {
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
        id4() : t0(GetMicroSecond()) {}
        void stop() {
            t1 = GetMicroSecond();
            cout << "\ntime cost = " << (t1 - t0) / 10000.0 << " ms\nmemory cost = " << (GetMemory() >> 20) << " MB\n ";
            t0 = t1;
        }
        ~id4() { stop(); }
    };
    return id4();


    return 0;

}();
namespace OY {
    enum AD2d_TYPE {
        AD2D_ANY = 0,
        AD2D_DIFFERENCE = 1,
        AD2D_VALUE = 2,
        AD2D_PRESUM = 3
    };
    template <typename _Tp>
    class id1 {
        std::vector<std::vector<_Tp>> m_values;
        AD2d_TYPE m_state;

    public:
        id1(uint32_t __m, uint32_t __n) : m_values(__m + 2, std::vector<_Tp>(__n + 2)), m_state(AD2D_ANY) {}
        void add(uint32_t __i, uint32_t __j, _Tp __inc) {
            if (m_state == AD2D_DIFFERENCE)
                m_values[__i + 1][__j + 2] -= __inc, m_values[__i + 2][__j + 1] -= __inc, m_values[__i + 1][__j + 1] += __inc, m_values[__i + 2][__j + 2] += __inc;
            else {
                switchTo(AD2D_VALUE);
                m_values[__i + 1][__j + 1] += __inc;
            }
        }
        void add(uint32_t id8, uint32_t id2, uint32_t id5, uint32_t id3, _Tp __inc) {
            switchTo(AD2D_DIFFERENCE);
            m_values[id8 + 1][id3 + 2] -= __inc, m_values[id2 + 2][id5 + 1] -= __inc, m_values[id8 + 1][id5 + 1] += __inc, m_values[id2 + 2][id3 + 2] += __inc;
        }
        _Tp query(uint32_t __i, uint32_t __j) {
            switchTo(AD2D_VALUE);
            return m_values[__i + 1][__j + 1];
        }
        _Tp query(uint32_t id8, uint32_t id2, uint32_t id5, uint32_t id3) {
            switchTo(AD2D_PRESUM);
            return m_values[id2 + 1][id3 + 1] + m_values[id8][id5] - m_values[id8][id3 + 1] - m_values[id2 + 1][id5];
        }
        void switchTo(AD2d_TYPE __type) {
            if (m_state == AD2D_ANY) m_state = __type;
            for (; m_state < __type; m_state = AD2d_TYPE(m_state + 1)) partialSum();
            for (; m_state > __type; m_state = AD2d_TYPE(m_state - 1)) adjacentDiffrence();
        }
        void adjacentDiffrence() {
            for (uint32_t i = m_values.size() - 1; i; i--)
                for (uint32_t j = m_values[0].size() - 1; j; j--) m_values[i][j] += m_values[i - 1][j - 1] - m_values[i][j - 1] - m_values[i - 1][j];
        }
        void partialSum() {
            for (uint32_t i = 1; i < m_values.size(); i++)
                for (uint32_t j = 1; j < m_values[0].size(); j++) m_values[i][j] -= m_values[i - 1][j - 1] - m_values[i][j - 1] - m_values[i - 1][j];
        }
    };
}
namespace OY {
    template <uint32_t _B = 10, uint32_t _W = 6, uint32_t _MAXN = 1 << 5, uint64_t _P = 9223372036737335297, uint64_t _R = 3>
    struct id7 {
        using bint = id7<_B, _W, _MAXN, _P, _R>;
        static constexpr struct _Bases {
            uint64_t val[_W * 2 + 1];
            constexpr _Bases() : val{} {
                for (uint32_t i = 0; i <= _W * 2; i++) val[i] = i ? val[i - 1] * _B : 1;
            }
        } bases{};
        static constexpr uint32_t _N = bases.val[_W], _K = (_MAXN + _W - 1) / _W;
        static inline bint s_divThresh = bint(__int128_t(LLONG_MAX) / _N - 1);
        static inline std::mt19937 s_rander;
        int m_data[_K];
        bool m_negative;
        id7() : m_data{}, m_negative(false) {}
        template <typename _Tp, std::enable_if_t<std::is_integral_v<_Tp> | std::is_same_v<_Tp, __int128_t>, bool> = true>
        explicit id7(_Tp __number) {
            bool neg = false;
            if (__number < _Tp(0)) {
                neg = true;
                __number = -__number;
            }
            static char s_buffer[100], *s_cursor;
            for (s_cursor = s_buffer; __number; __number /= _B) *s_cursor++ = fromInt(__number % _B);
            std::reverse(s_buffer, s_cursor);
            *this = fromString(s_buffer, s_cursor - s_buffer);
            if (neg && bool(*this)) setSign(true);
        }
        explicit id7(const char *__number) : id7(fromString(__number)) {}
        explicit id7(const std::string &__number) : id7(fromString(__number.data(), __number.size())) {}
        static char fromInt(uint32_t __c) {
            if (__c < 10)
                return '0' + __c;
            else if (__c < 36)
                return 'a' + (__c - 10);
            else
                return 'A' + (__c - 36);
        }
        static uint32_t fromChar(char __c) {
            if (__c <= '9')
                return __c - '0';
            else if (__c <= 'Z')
                return __c - 'A' + 36;
            else
                return __c - 'a' + 10;
        }
        static bint fromString(const char *__number) { return fromString(__number, std::strlen(__number)); }
        static bint fromString(const char *__number, uint32_t __length) {
            bint res;
            bool flag = false;
            for (int cursor = __length - 1, end = (__number[0] == '+' || __number[0] == '-' ? 1 : 0), index = 0; cursor >= end && index < _K; cursor -= _W) {
                uint32_t digit = 0;
                for (uint32_t i = std::max(end, cursor - int(_W) + 1); i <= cursor; i++) {
                    digit = digit * _B + fromChar(__number[i]);
                }
                res.m_data[index++] = digit, flag = flag || digit;
            }
            if (__number[0] == '-' && flag) res.m_negative = true;
            return res;
        }
        static bint small(int id6) {
            bint res;
            res.m_data[0] = std::abs(id6);
            if (id6 < 0) res.m_negative = true;
            return res;
        }
        static bint rand(uint32_t __length) {
            if (!__length) return bint();
            bint res;
            auto [quot, rem] = std::div(std::min<uint32_t>(__length, _K * _W), int(_W));
            if (!rem) quot--, rem += _W;
            for (uint32_t i = 0; i < quot; i++) res.m_data[i] = s_rander() % _N;
            res.m_data[quot] = s_rander() % (bases.val[rem] - bases.val[rem - 1]) + bases.val[rem - 1];
            return res;
        }
        static int absCompare(const bint &__a, const bint &__b) {
            for (uint32_t i = _K - 1; ~i; i--)
                if (__a.m_data[i] != __b.m_data[i]) return __a.m_data[i] > __b.m_data[i] ? 1 : -1;
            return 0;
        }
        template <bool _Sign>
        static bint &inc_dec(bint &__a) {
            if (__a.m_negative == _Sign) {
                uint32_t i = 0;
                for (uint32_t i = 0; i < _K; i++) {
                    if (++(__a.m_data[i]) == _N)
                        __a.m_data[i] = 0;
                    else
                        break;
                }
                if constexpr (_Sign) {
                    if (i == _K) __a.setZero();
                }
            } else {
                uint32_t i = 0;
                while (i < _K) {
                    if (__a.m_data[i]--)
                        break;
                    else
                        __a.m_data[i++] = _N - 1;
                }
                if constexpr (_Sign) {
                    if (i == _K) __a = small(-1);
                } else {
                    if (!i) __a.shrink();
                }
            }
            return __a;
        }
        template <typename _Compare>
        static bint &id0(bint &__a, const bint &__b) {
            if (_Compare()(__a.m_negative, __b.m_negative)) {
                uint32_t carry = 0;
                for (uint32_t i = 0; i < _K; i++)
                    if (__a.m_data[i] += __b.m_data[i] + carry; (carry = __a.m_data[i] >= _N)) __a.m_data[i] -= _N;
            } else {
                uint32_t borrow = 0;
                for (uint32_t i = 0; i < _K; i++)
                    if (__a.m_data[i] -= __b.m_data[i] + borrow; (borrow = __a.m_data[i] < 0)) __a.m_data[i] += _N;
                if (borrow)
                    return __a.complement().opposite();
            }
            return __a.shrink();
        }
        static std::pair<bint, long long> div_mod(const bint &__a, long long __b) {
            long long carry = 0;
            bint res;
            bool flag = false;
            if (__b < 0) {
                res.setSign(true);
                __b = -__b;
            }
            for (uint32_t i = __a.highest(); ~i; i--) {
                auto [q, r] = std::div(__a.m_data[i] + carry * _N, __b);
                res.m_data[i] = q, carry = r, flag = flag || q;
            }
            if (flag && __a.m_negative) res.opposite();
            return {res, __a.m_negative ? -carry : carry};
        }
        bint &shrink() {
            if (m_negative && !bool(*this)) m_negative = false;
            return *this;
        }
        bint &complement() {
            uint32_t i = 0;
            while (i < _K && !m_data[i]) i++;
            if (i == _K) return *this;
            m_data[i] = _N - m_data[i];
            while (++i < _K) m_data[i] = _N - 1 - m_data[i];
            return *this;
        }
        bint &opposite() { return setSign(!m_negative); }
        bint &setSign(bool __negative) {
            m_negative = __negative;
            return *this;
        }
        bint &setZero() {
            std::fill_n(m_data, _K, 0);
            return setSign(false);
        }
        bint &operator++() { return inc_dec<false>(*this); }
        bint &operator--() { return inc_dec<true>(*this); }
        uint32_t length() const {
            uint32_t i = highest();
            return ~i ? i * _W + (std::upper_bound(bases.val, bases.val + _W, m_data[i]) - bases.val) : 0;
        }
        uint32_t highest() const {
            uint32_t i = _K - 1;
            while (~i && !m_data[i]) i--;
            return i;
        }
        uint32_t ctz() const {
            uint32_t i = 0, res = 0;
            while (i < _K && !m_data[i]) i++;
            if (i == _K) return 0;
            for (uint32_t digit = m_data[i]; digit && digit % _B == 0; digit /= _B, res++) {}
            return i * _W + res;
        }
        bint inv() const {
            auto dfs = [&](auto self, const bint &_number, uint32_t _length) {
                if (_length == 1)
                    return bint(bases.val[_W * 2] / _number.m_data[0]);
                else if (_length == 2)
                    return bint(__int128_t(bases.val[_W * 2]) * bases.val[_W * 2] / (__int128_t(_number.m_data[1]) * _N + _number.m_data[0]));
                else {
                    bint res((_number >> (_length - 1) / 2 * _W).inv());
                    return ((res + res) << (_length - 1) / 2 * _W) - ((_number * (res * res)) >> (_length / 2 + 1) * 2 * _W);
                }
            };
            return dfs(dfs, *this, highest() + 1);
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
        bint &operator+=(const bint &__other) { return id0<std::equal_to<bool>>(*this, __other); }
        bint &operator-=(const bint &__other) { return id0<std::not_equal_to<bool>>(*this, __other); }
        bint &operator*=(const bint &__other) { return *this = *this * __other; }
        bint &operator*=(long long __other) {
            long long carry = 0;
            bint res;
            bool flag = false;
            if (__other < 0) {
                opposite();
                __other = -__other;
            }
            for (uint32_t i = 0; i < _K; i++) {
                auto [quot, rem] = std::div(m_data[i] * __other + carry, (long long)_N);
                carry = quot, m_data[i] = rem, flag = flag || rem;
            }
            return flag ? *this : setSign(false);
        }
        bint &operator/=(long long __other) {
            long long carry = 0;
            bool flag = false;
            if (__other < 0) {
                opposite();
                __other = -__other;
            }
            for (uint32_t i = highest(); ~i; i--) {
                auto [q, r] = std::div(m_data[i] + carry * _N, __other);
                m_data[i] = q, carry = r, flag = flag || q;
            }
            if (!flag) setSign(false);
            return *this;
        }
        bint &operator%=(long long __other) { return *this = bint(div_mod(*this, __other).second); }
        bint &operator<<=(uint32_t __shift) { return *this = *this << __shift; }
        bint &operator>>=(uint32_t __shift) { return *this = *this >> __shift; }
        bint operator+() const { return *this; }
        bint operator-() const {
            bint res(*this);
            if (res) res.opposite();
            return res;
        }
        bool operator==(const bint &__other) const { return m_negative == __other.m_negative && !absCompare(*this, __other); }
        bool operator!=(const bint &__other) const { return m_negative != __other.m_negative || absCompare(*this, __other); }
        bool operator<(const bint &__other) const { return m_negative == __other.m_negative ? (m_negative ? absCompare(*this, __other) > 0 : absCompare(*this, __other) < 0) : m_negative; }
        bool operator>(const bint &__other) const { return m_negative == __other.m_negative ? (m_negative ? absCompare(*this, __other) < 0 : absCompare(*this, __other) > 0) : !m_negative; }
        bool operator<=(const bint &__other) const { return m_negative == __other.m_negative ? (m_negative ? absCompare(*this, __other) >= 0 : absCompare(*this, __other) <= 0) : m_negative; }
        bool operator>=(const bint &__other) const { return m_negative == __other.m_negative ? (m_negative ? absCompare(*this, __other) <= 0 : absCompare(*this, __other) >= 0) : !m_negative; }
        explicit operator bool() const {
            return std::any_of(m_data, m_data + _K, [](int x) { return x; });
        }
        template <typename _Tp>
        explicit operator _Tp() const {
            _Tp res = 0;
            for (uint32_t i = _K - 1; ~i; i--) res = res * _N + m_data[i];
            return m_negative ? -res : res;
        }
        operator std::string() const {
            uint32_t len = length();
            if (!len) return "0";
            std::string res(len, '0');
            for (uint32_t i = 0; i * _W < len; i++)
                for (uint32_t j = i * _W, digit = m_data[i]; digit; j++, digit /= _B) res[j] = fromInt(digit % _B);
            if (m_negative) res.push_back('-');
            std::reverse(res.begin(), res.end());
            return res;
        }
        friend bint operator+(const bint &__a, const bint &__b) { return bint(__a) += __b; }
        friend bint operator-(const bint &__a, const bint &__b) { return bint(__a) -= __b; }
        friend bint operator*(const bint &__a, const bint &__b) {
            uint32_t ah = __a.highest(), bh = __b.highest();
            if (!~ah || !~bh) return bint();
            bint res;
            bool flag = false;
            long long carry = 0;
            for (uint32_t k = 0; k <= ah + bh && k < _K; k++) {
                for (uint32_t i = k < bh ? 0 : k - bh, iend = std::min(ah, k); i <= iend; i++) carry += (long long)__a.m_data[i] * __b.m_data[k - i];
                auto [quot, rem] = std::div(carry, _N);
                carry = quot, res.m_data[k] = rem, flag = flag || rem;
            }
            if (carry && ah + bh + 1 < _K) res.m_data[ah + bh + 1] = carry, flag = true;
            if (flag && __a.m_negative != __b.m_negative) res.opposite();
            return res;
        }
        friend bint operator*(const bint &__a, long long __b) {
            long long carry = 0;
            bint res;
            bool flag = false;
            if (__b < 0) {
                res.setSign(true);
                __b = -__b;
            }
            for (uint32_t i = 0; i < _K; i++) {
                auto [quot, rem] = std::div(__a.m_data[i] * __b + carry, (long long)_N);
                carry = quot, res.m_data[i] = rem, flag = flag || rem;
            }
            if (flag && __a.m_negative) res.opposite();
            return res;
        }
        friend bint operator/(const bint &__a, long long __b) { return div_mod(__a, __b).first; }
        friend bint operator%(const bint &__a, long long __b) { return div_mod(__a, __b).second; }
        friend bint operator<<(const bint &__a, uint32_t __shift) {
            auto [quot, rem] = std::div((int)__shift, (int)_W);
            bint res;
            bool flag = false;
            for (uint32_t carry = 0, i = 0, j = quot; j < _K; i++, j++) {
                auto [q, r] = std::div((long long)(__a.m_data[i]) * bases.val[rem] + carry, (long long)_N);
                carry = q, res.m_data[j] = r, flag = flag || r;
            }
            if (flag) res.setSign(__a.m_negative);
            return res;
        }
        friend bint operator>>(const bint &__a, uint32_t __shift) {
            auto [quot, rem] = std::div((int)__shift, (int)_W);
            bint res;
            bool flag = false;
            for (int carry = 0, i = _K - 1, j = _K - 1 - quot; j >= 0; i--, j--) {
                auto [q, r] = std::div(__a.m_data[i], int(bases.val[rem]));
                res.m_data[j] = carry * bases.val[_W - rem] + q, carry = r, flag = flag || q;
            }
            if (flag) res.setSign(__a.m_negative);
            return res;
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

using bint = OY::id7<10, 9, 40>;
OY::id1<bint> ad(1005, 1005);
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, q;
        cin >> n >> q;
        std::array<int, 2> P[n];
        for (auto &[h, w] : P) {
            cin >> h >> w;
            ad.add(h, w, bint(h * w));
        }
        for (int i = 0; i < q; i++) {
            int h1, w1, h2, w2;
            cin >> h1 >> w1 >> h2 >> w2;
            if (h1 + 1 >= h2 or w1 + 1 >= w2) {
                cout << "0\n";
                continue;
            }
            cout << ad.query(h1 + 1, h2 - 1, w1 + 1, w2 - 1) << '\n';
        }
        ad.switchTo(OY::AD2D_VALUE);
        for (auto &[h, w] : P) {
            ad.add(h, w, -bint(h * w));
        }
    }
}