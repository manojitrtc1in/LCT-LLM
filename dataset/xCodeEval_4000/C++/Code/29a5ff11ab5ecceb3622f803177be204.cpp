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
namespace OY {
#define cin OY::inputHelper<1 << 10, 20>::getInstance()
#define getchar() ({char c=cin.getChar_Checked();cin.next();c; })
#define cout OY::outputHelper<1 << 20>::getInstance()
#define putchar cout.putChar
#define endl '\n'
#define putlog(...) OY::printLog(", ", __VA_ARGS__)
    template <uint64_t _BufferSize = 1 << 10, uint64_t _BlockSize = 20>
    class inputHelper {
    public:
        FILE *m_filePtr;
        char m_buf[_BufferSize], *m_end, *m_cursor;
        bool m_ok;
        void flush() {
            uint64_t a = m_end - m_cursor;
            if (a >= _BlockSize) return;
            memmove(m_buf, m_cursor, a);
            uint64_t b = fread(m_buf + a, 1, _BufferSize - a, m_filePtr);
            m_cursor = m_buf;
            if (a + b < _BufferSize) {
                m_end = m_buf + a + b;
                *m_end = EOF;
            }
        }

    public:
        explicit inputHelper(const char *inputFileName) : m_ok(true) {
            if (!*inputFileName)
                m_filePtr = stdin;
            else
                m_filePtr = fopen(inputFileName, "rt");
            m_end = m_cursor = m_buf + _BufferSize;
        }
        ~inputHelper() { fclose(m_filePtr); }
        static inputHelper<_BufferSize, _BlockSize> &getInstance() {
#ifdef OY_LOCAL
            static inputHelper<_BufferSize, _BlockSize> s_obj("in.txt");
#else
            static inputHelper<_BufferSize, _BlockSize> s_obj("");
#endif
            return s_obj;
        }
        static constexpr bool isBlank(char c) { return c == ' ' || c == '\t' || c == '\n' || c == '\r'; }
        static constexpr bool isEndline(char c) { return c == '\n' || c == EOF; }
        const char &getChar_Checked() {
            if (m_cursor < m_end) return *m_cursor;
            uint64_t b = fread(m_buf, 1, _BufferSize, m_filePtr);
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
        FILE *m_filePtr = nullptr;
        char m_buf[_BufferSize], *m_end, *m_cursor;
        char m_tempBuf[50], *m_tempBufCursor, *m_tempBufDot;
        uint64_t m_floatReserve, m_floatRatio;

    public:
        outputHelper(const char *outputFileName, int prec = 6) : m_end(m_buf + _BufferSize) {
            if (!*outputFileName)
                m_filePtr = stdout;
            else
                m_filePtr = fopen(outputFileName, "wt");
            m_cursor = m_buf;
            m_tempBufCursor = m_tempBuf;
            precision(prec);
        }
        static outputHelper<_BufferSize> &getInstance() {
#ifdef OY_LOCAL
            static outputHelper<_BufferSize> s_obj("out.txt");
#else
            static outputHelper<_BufferSize> s_obj("");
#endif
            return s_obj;
        }
        ~outputHelper() {
            flush();
            fclose(m_filePtr);
        }
        void precision(int prec) {
            m_floatReserve = prec;
            m_floatRatio = pow(10, prec);
            m_tempBufDot = m_tempBuf + prec;
        }
        outputHelper<_BufferSize> &flush() {
            fwrite(m_buf, 1, m_cursor - m_buf, m_filePtr);
            fflush(m_filePtr);
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
                    *m_tempBufCursor++ = '0' + _ret % 10;
                    _ret /= 10;
                } while (_ret);
                do putChar(*--m_tempBufCursor);
                while (m_tempBufCursor > m_tempBuf);
            } else {
                putChar('-');
                do {
                    *m_tempBufCursor++ = '0' - _ret % 10;
                    _ret /= 10;
                } while (_ret);
                do putChar(*--m_tempBufCursor);
                while (m_tempBufCursor > m_tempBuf);
            }
            return *this;
        }
        template <typename _Tp, typename std::enable_if<std::is_unsigned<_Tp>::value & std::is_integral<_Tp>::value>::type * = nullptr>
        outputHelper<_BufferSize> &operator<<(const _Tp &ret) {
            _Tp _ret = _Tp(ret);
            do {
                *m_tempBufCursor++ = '0' + _ret % 10;
                _ret /= 10;
            } while (_ret);
            do putChar(*--m_tempBufCursor);
            while (m_tempBufCursor > m_tempBuf);
            return *this;
        }
        template <typename _Tp, typename std::enable_if<std::is_floating_point<_Tp>::value>::type * = nullptr>
        outputHelper<_BufferSize> &operator<<(const _Tp &ret) {
            if (ret < 0) {
                putChar('-');
                return *this << -ret;
            }
            _Tp _ret = ret * m_floatRatio;
            uint64_t integer = _ret;
            if (_ret - integer >= 0.4999999999) integer++;
            do {
                *m_tempBufCursor++ = '0' + integer % 10;
                integer /= 10;
            } while (integer);
            if (m_tempBufCursor > m_tempBufDot) {
                do putChar(*--m_tempBufCursor);
                while (m_tempBufCursor > m_tempBufDot);
                putChar('.');
            } else {
                putS("0.");
                for (int i = m_tempBufDot - m_tempBufCursor; i--;) putChar('0');
            }
            do putChar(*--m_tempBufCursor);
            while (m_tempBufCursor > m_tempBuf);
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
#ifdef OY_LOCAL
#define CHECKTIME tam.stop()
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



