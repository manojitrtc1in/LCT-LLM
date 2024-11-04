
























template <typename _Tp, typename _Fp, typename _Compare = std::less<void>>
bool chmax(_Tp &a, const _Fp &b, _Compare __comp = _Compare()) { return __comp(a, b) ? a = b, true : false; }
template <typename _Tp, typename _Fp, typename _Compare = std::less<void>>
bool chmin(_Tp &a, const _Fp &b, _Compare __comp = _Compare()) { return __comp(b, a) ? a = b, true : false; }
namespace OY {






    template <uint64_t _BufferSize = 1 << 10, uint64_t _BlockSize = 20>
    class inputHelper {
    public:
        FILE *id10;
        char m_buf[_BufferSize], *m_end, *m_cursor;
        bool m_ok;
        void flush() {
            uint64_t a = m_end - m_cursor;
            if (a >= _BlockSize) return;
            memmove(m_buf, m_cursor, a);
            uint64_t b = fread(m_buf + a, 1, _BufferSize - a, id10);
            m_cursor = m_buf;
            if (a + b < _BufferSize) {
                m_end = m_buf + a + b;
                *m_end = EOF;
            }
        }

    public:
        explicit inputHelper(const char *inputFileName) : m_ok(true) {
            if (!*inputFileName)
                id10 = stdin;
            else
                id10 = fopen(inputFileName, "rt");
            m_end = m_cursor = m_buf + _BufferSize;
        }
        ~inputHelper() { fclose(id10); }
        static inputHelper<_BufferSize, _BlockSize> &getInstance() {

            static inputHelper<_BufferSize, _BlockSize> s_obj("in.txt");

            static inputHelper<_BufferSize, _BlockSize> s_obj("");

            return s_obj;
        }
        static constexpr bool isBlank(char c) { return c == ' ' || c == '\t' || c == '\n' || c == '\r'; }
        static constexpr bool isEndline(char c) { return c == '\n' || c == EOF; }
        const char &getChar_Checked() {
            if (m_cursor < m_end) return *m_cursor;
            uint64_t b = fread(m_buf, 1, _BufferSize, id10);
            m_cursor = m_buf;
            if (b < _BufferSize) {
                m_end = m_buf + b;
                *m_end = EOF;
            }
            return *m_cursor;
        }
        const char &getChar_Unchecked() const { return *m_cursor; }
        void next() { ++m_cursor; }
        void setState(bool _ok) { m_ok = _ok; }
        template <typename _Tp, typename std::enable_if<std::is_signed<_Tp>::value & std::is_integral<_Tp>::value>::type * = nullptr>
        inputHelper<_BufferSize, _BlockSize> &operator>>(_Tp &ret) {
            while (isBlank(getChar_Checked())) next();
            flush();
            if (getChar_Unchecked() == '-') {
                next();
                if (isdigit(getChar_Unchecked())) {
                    ret = -(getChar_Unchecked() - '0');
                    while (next(), isdigit(getChar_Unchecked())) ret = ret * 10 - (getChar_Unchecked() - '0');
                } else
                    m_ok = false;
            } else {
                if (isdigit(getChar_Unchecked())) {
                    ret = getChar_Unchecked() - '0';
                    while (next(), isdigit(getChar_Unchecked())) ret = ret * 10 + (getChar_Unchecked() - '0');
                } else
                    m_ok = false;
            }
            return *this;
        }
        template <typename _Tp, typename std::enable_if<std::is_unsigned<_Tp>::value & std::is_integral<_Tp>::value>::type * = nullptr>
        inputHelper<_BufferSize, _BlockSize> &operator>>(_Tp &ret) {
            while (isBlank(getChar_Checked())) next();
            flush();
            if (isdigit(getChar_Unchecked())) {
                ret = getChar_Unchecked() - '0';
                while (next(), isdigit(getChar_Unchecked())) ret = ret * 10 + (getChar_Unchecked() - '0');
            } else
                m_ok = false;
            return *this;
        }
        template <typename _Tp, typename std::enable_if<std::is_floating_point<_Tp>::value>::type * = nullptr>
        inputHelper<_BufferSize, _BlockSize> &operator>>(_Tp &ret) {
            bool neg = false, integer = false, decimal = false;
            while (isBlank(getChar_Checked())) next();
            flush();
            if (getChar_Unchecked() == '-') {
                neg = true;
                next();
            }
            if (!isdigit(getChar_Unchecked()) && getChar_Unchecked() != '.') {
                m_ok = false;
                return *this;
            }
            if (isdigit(getChar_Unchecked())) {
                integer = true;
                ret = getChar_Unchecked() - '0';
                while (next(), isdigit(getChar_Unchecked())) ret = ret * 10 + (getChar_Unchecked() - '0');
            }
            if (getChar_Unchecked() == '.') {
                next();
                if (isdigit(getChar_Unchecked())) {
                    if (!integer) ret = 0;
                    decimal = true;
                    _Tp unit = 0.1;
                    ret += unit * (getChar_Unchecked() - '0');
                    while (next(), isdigit(getChar_Unchecked())) {
                        unit *= 0.1;
                        ret += unit * (getChar_Unchecked() - '0');
                    }
                }
            }
            if (!integer && !decimal)
                m_ok = false;
            else if (neg)
                ret = -ret;
            return *this;
        }
        inputHelper<_BufferSize, _BlockSize> &operator>>(char &ret) {
            while (isBlank(getChar_Checked())) next();
            ret = getChar_Checked();
            if (ret == EOF)
                m_ok = false;
            else
                next();
            return *this;
        }
        inputHelper<_BufferSize, _BlockSize> &operator>>(std::string &ret) {
            while (isBlank(getChar_Checked())) next();
            if (getChar_Checked() != EOF) {
                ret.clear();
                do {
                    ret += getChar_Checked();
                    next();
                } while (!isBlank(getChar_Checked()) && getChar_Unchecked() != EOF);
            } else
                m_ok = false;
            return *this;
        }
        explicit operator bool() { return m_ok; }
    };
    template <uint64_t _BufferSize = 1 << 20>
    class outputHelper {
        FILE *id10 = nullptr;
        char m_buf[_BufferSize], *m_end, *m_cursor;
        char id6[50], *id1, *id5;
        uint64_t id3, id2;

    public:
        outputHelper(const char *outputFileName, int prec = 6) : m_end(m_buf + _BufferSize) {
            if (!*outputFileName)
                id10 = stdout;
            else
                id10 = fopen(outputFileName, "wt");
            m_cursor = m_buf;
            id1 = id6;
            precision(prec);
        }
        static outputHelper<_BufferSize> &getInstance() {

            static outputHelper<_BufferSize> s_obj("out.txt");

            static outputHelper<_BufferSize> s_obj("");

            return s_obj;
        }
        ~outputHelper() {
            flush();
            fclose(id10);
        }
        void precision(int prec) {
            id3 = prec;
            id2 = pow(10, prec);
            id5 = id6 + prec;
        }
        outputHelper<_BufferSize> &flush() {
            fwrite(m_buf, 1, m_cursor - m_buf, id10);
            fflush(id10);
            m_cursor = m_buf;
            return *this;
        }
        void putChar(const char &c) {
            if (m_cursor == m_end) flush();
            *m_cursor++ = c;
        }
        void putS(const char *c) {
            while (*c) putChar(*c++);
        }
        template <typename _Tp, typename std::enable_if<std::is_signed<_Tp>::value & std::is_integral<_Tp>::value>::type * = nullptr>
        outputHelper<_BufferSize> &operator<<(const _Tp &ret) {
            _Tp _ret = _Tp(ret);
            if (_ret >= 0) {
                do {
                    *id1++ = '0' + _ret % 10;
                    _ret /= 10;
                } while (_ret);
                do putChar(*--id1);
                while (id1 > id6);
            } else {
                putChar('-');
                do {
                    *id1++ = '0' - _ret % 10;
                    _ret /= 10;
                } while (_ret);
                do putChar(*--id1);
                while (id1 > id6);
            }
            return *this;
        }
        template <typename _Tp, typename std::enable_if<std::is_unsigned<_Tp>::value & std::is_integral<_Tp>::value>::type * = nullptr>
        outputHelper<_BufferSize> &operator<<(const _Tp &ret) {
            _Tp _ret = _Tp(ret);
            do {
                *id1++ = '0' + _ret % 10;
                _ret /= 10;
            } while (_ret);
            do putChar(*--id1);
            while (id1 > id6);
            return *this;
        }
        template <typename _Tp, typename std::enable_if<std::is_floating_point<_Tp>::value>::type * = nullptr>
        outputHelper<_BufferSize> &operator<<(const _Tp &ret) {
            if (ret < 0) {
                putChar('-');
                return *this << -ret;
            }
            _Tp _ret = ret * id2;
            uint64_t integer = _ret;
            if (_ret - integer >= 0.4999999999) integer++;
            do {
                *id1++ = '0' + integer % 10;
                integer /= 10;
            } while (integer);
            if (id1 > id5) {
                do putChar(*--id1);
                while (id1 > id5);
                putChar('.');
            } else {
                putS("0.");
                for (int i = id5 - id1; i--;) putChar('0');
            }
            do putChar(*--id1);
            while (id1 > id6);
            return *this;
        }
        outputHelper<_BufferSize> &operator<<(const char &ret) {
            putChar(ret);
            return *this;
        }
        outputHelper<_BufferSize> &operator<<(const std::string &ret) {
            putS(ret.data());
            return *this;
        }
    };
    template <uint64_t _BufferSize, uint64_t _BlockSize>
    inputHelper<_BufferSize, _BlockSize> &getline(inputHelper<_BufferSize, _BlockSize> &ih, std::string &ret) {
        ret.clear();
        if (ih.getChar_Checked() == EOF)
            ih.setState(false);
        else {
            while (!inputHelper<_BufferSize, _BlockSize>::isEndline(ih.getChar_Checked())) {
                ret += ih.getChar_Unchecked();
                ih.next();
            }
            ih.next();
        }
        return ih;
    }
    template <typename D, typename T, typename... S>
    void printLog(D delim, const T &x, S... rest) {
        cout << x;
        if constexpr (sizeof...(rest) > 0) {
            cout << delim;
            printLog(delim, rest...);
        }
    }
}
using OY::getline;
auto tam = [] {


    struct id7 {
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
        id7() : t0(GetMicroSecond()) {}
        void stop() {
            t1 = GetMicroSecond();
            cout << "\ntime cost = " << (t1 - t0) / 10000.0 << " ms\nmemory cost = " << (GetMemory() >> 20) << " MB\n ";
            t0 = t1;
        }
        ~id7() { stop(); }
    };
    return id7();


    return 0;

}();

namespace OY {
    template <typename _ModType>
    struct Barrett {
        _ModType m_P;
        __uint128_t id9;
        constexpr Barrett() = default;
        constexpr explicit Barrett(_ModType __P) : m_P(__P), id9(-uint64_t(__P) / __P + 1) {}
        constexpr _ModType mod() const { return m_P; }
        constexpr _ModType mod(uint64_t __a) const {
            __a -= uint64_t(id9 * __a >> 64) * m_P + m_P;
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
            _Tp res = id9 * __a >> 64;
            if (__a - res * m_P >= m_P) res++;
            return res;
        }
        template <typename _Tp>
        constexpr std::pair<_Tp, _Tp> divmod(_Tp __a) const {
            _Tp quo = (__a * id9) >> 64, rem = __a - quo * m_P;
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
        _ModType id9;
        _ModType m_Ninv;
        Barrett<_ModType> m_brt;
        constexpr Montgomery() = default;
        constexpr explicit Montgomery(_ModType __P) : m_P(__P), id9(__P), m_Ninv(-_LongType(__P) % __P), m_brt(__P) {
            for (int i = 0; i < _MontgomeryTag<_ModType>::inv_loop; i++) id9 *= _ModType(2) - __P * id9;
        }
        constexpr _ModType mod() const { return m_brt.mod(); }
        constexpr _ModType mod(uint64_t __a) const { return m_brt.mod(__a); }
        constexpr _FastType init(uint64_t __a) const { return reduce(_LongType(mod(__a)) * m_Ninv); }
        constexpr _FastType raw_init(uint64_t __a) const { return reduce(_LongType(__a) * m_Ninv); }
        constexpr _FastType reduce(_LongType __a) const {
            _FastType res = (__a >> _MontgomeryTag<_ModType>::length) - _ModType(_LongType(_ModType(__a) * id9) * m_P >> _MontgomeryTag<_ModType>::length);
            if (res >= mod()) res += mod();
            return res;
        }
        constexpr _ModType reduce(_FastType __a) const {
            _ModType res = -_ModType(_LongType(__a * id9) * m_P >> _MontgomeryTag<_ModType>::length);
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
    constexpr auto id4 = isPrime<uint32_t>;
    constexpr auto id8 = isPrime<uint64_t>;
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
        static auto id0(_Elem __n) {
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
            auto pf = id0(__n);
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
            for (auto [p, c] : id0(__n)) __n = __n / p * (p - 1);
            return __n;
        }
    };
}
static constexpr uint32_t N = 2e7;
uint32_t A[N + 1], B[N + 1];
uint64_t dp[N + 1];





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
        if (uint32_t a = A[i]) {
            for (auto f : OY::Pollard_Rho::getFactors<uint32_t>(i)) B[f] += a;
        }
    }
    dp[1] = n;
    auto getdp = [&](auto self, uint32_t x) {
        if (dp[x]) return dp[x];
        for (auto &&[p, c] : OY::Pollard_Rho::id0<uint32_t>(x)) {
            uint32_t v2 = x / p;
            chmax(dp[x], self(self, v2) + uint64_t(B[x]) * (x - v2));
        }
        return dp[x];
    };
    long long ans = n;
    for (uint32_t v = 1; v <= mx; v++)
        if (A[v]) {
            chmax(ans, getdp(getdp, v));
        }
    cout << ans;
    CHECKTIME;
}