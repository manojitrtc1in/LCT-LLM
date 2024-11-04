#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2")
#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <climits>
#include <cmath>
#include <functional>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <sstream>
#include <stack>
#include <string.h>
#include <type_traits>
#include <unordered_map>
#if __cplusplus < 201703L
namespace std {
template <typename _Tp>
  constexpr bool is_void_v = is_void<_Tp>::value;
template <typename _Tp>
  constexpr bool is_null_pointer_v = is_null_pointer<_Tp>::value;
template <typename _Tp>
  constexpr bool is_integral_v = is_integral<_Tp>::value;
template <typename _Tp>
  constexpr bool is_floating_point_v = is_floating_point<_Tp>::value;
template <typename _Tp>
  constexpr bool is_array_v = is_array<_Tp>::value;
template <typename _Tp>
  constexpr bool is_pointer_v = is_pointer<_Tp>::value;
template <typename _Tp>
  constexpr bool is_lvalue_reference_v =
    is_lvalue_reference<_Tp>::value;
template <typename _Tp>
  constexpr bool is_rvalue_reference_v =
    is_rvalue_reference<_Tp>::value;
template <typename _Tp>
  constexpr bool is_member_object_pointer_v =
    is_member_object_pointer<_Tp>::value;
template <typename _Tp>
  constexpr bool is_member_function_pointer_v =
    is_member_function_pointer<_Tp>::value;
template <typename _Tp>
  constexpr bool is_enum_v = is_enum<_Tp>::value;
template <typename _Tp>
  constexpr bool is_union_v = is_union<_Tp>::value;
template <typename _Tp>
  constexpr bool is_class_v = is_class<_Tp>::value;
template <typename _Tp>
  constexpr bool is_function_v = is_function<_Tp>::value;
template <typename _Tp>
  constexpr bool is_reference_v = is_reference<_Tp>::value;
template <typename _Tp>
  constexpr bool is_arithmetic_v = is_arithmetic<_Tp>::value;
template <typename _Tp>
  constexpr bool is_fundamental_v = is_fundamental<_Tp>::value;
template <typename _Tp>
  constexpr bool is_object_v = is_object<_Tp>::value;
template <typename _Tp>
  constexpr bool is_scalar_v = is_scalar<_Tp>::value;
template <typename _Tp>
  constexpr bool is_compound_v = is_compound<_Tp>::value;
template <typename _Tp>
  constexpr bool is_member_pointer_v = is_member_pointer<_Tp>::value;
template <typename _Tp>
  constexpr bool is_const_v = is_const<_Tp>::value;
template <typename _Tp>
  constexpr bool is_volatile_v = is_volatile<_Tp>::value;
template <typename _Tp>
  constexpr bool is_trivial_v = is_trivial<_Tp>::value;
template <typename _Tp>
  constexpr bool is_trivially_copyable_v =
    is_trivially_copyable<_Tp>::value;
template <typename _Tp>
  constexpr bool is_standard_layout_v = is_standard_layout<_Tp>::value;
template <typename _Tp>
  constexpr bool is_pod_v = is_pod<_Tp>::value;
template <typename _Tp>
  constexpr bool is_literal_type_v = is_literal_type<_Tp>::value;
template <typename _Tp>
  constexpr bool is_empty_v = is_empty<_Tp>::value;
template <typename _Tp>
  constexpr bool is_polymorphic_v = is_polymorphic<_Tp>::value;
template <typename _Tp>
  constexpr bool is_abstract_v = is_abstract<_Tp>::value;
template <typename _Tp>
  constexpr bool is_final_v = is_final<_Tp>::value;
template <typename _Tp>
  constexpr bool is_signed_v = is_signed<_Tp>::value;
template <typename _Tp>
  constexpr bool is_unsigned_v = is_unsigned<_Tp>::value;
template <typename _Tp, typename... _Args>
  constexpr bool is_constructible_v =
    is_constructible<_Tp, _Args...>::value;
template <typename _Tp>
  constexpr bool is_default_constructible_v =
    is_default_constructible<_Tp>::value;
template <typename _Tp>
  constexpr bool is_copy_constructible_v =
    is_copy_constructible<_Tp>::value;
template <typename _Tp>
  constexpr bool is_move_constructible_v =
    is_move_constructible<_Tp>::value;
template <typename _Tp, typename _Up>
  constexpr bool is_assignable_v = is_assignable<_Tp, _Up>::value;
template <typename _Tp>
  constexpr bool is_copy_assignable_v = is_copy_assignable<_Tp>::value;
template <typename _Tp>
  constexpr bool is_move_assignable_v = is_move_assignable<_Tp>::value;
template <typename _Tp>
  constexpr bool is_destructible_v = is_destructible<_Tp>::value;
template <typename _Tp, typename... _Args>
  constexpr bool is_trivially_constructible_v =
    is_trivially_constructible<_Tp, _Args...>::value;
template <typename _Tp>
  constexpr bool is_trivially_default_constructible_v =
    is_trivially_default_constructible<_Tp>::value;
template <typename _Tp>
  constexpr bool is_trivially_copy_constructible_v =
    is_trivially_copy_constructible<_Tp>::value;
template <typename _Tp>
  constexpr bool is_trivially_move_constructible_v =
    is_trivially_move_constructible<_Tp>::value;
template <typename _Tp, typename _Up>
  constexpr bool is_trivially_assignable_v =
    is_trivially_assignable<_Tp, _Up>::value;
template <typename _Tp>
  constexpr bool is_trivially_copy_assignable_v =
    is_trivially_copy_assignable<_Tp>::value;
template <typename _Tp>
  constexpr bool is_trivially_move_assignable_v =
    is_trivially_move_assignable<_Tp>::value;
template <typename _Tp>
  constexpr bool is_trivially_destructible_v =
    is_trivially_destructible<_Tp>::value;
template <typename _Tp, typename... _Args>
  constexpr bool is_nothrow_constructible_v =
    is_nothrow_constructible<_Tp, _Args...>::value;
template <typename _Tp>
  constexpr bool is_nothrow_default_constructible_v =
    is_nothrow_default_constructible<_Tp>::value;
template <typename _Tp>
  constexpr bool is_nothrow_copy_constructible_v =
    is_nothrow_copy_constructible<_Tp>::value;
template <typename _Tp>
  constexpr bool is_nothrow_move_constructible_v =
    is_nothrow_move_constructible<_Tp>::value;
template <typename _Tp, typename _Up>
  constexpr bool is_nothrow_assignable_v =
    is_nothrow_assignable<_Tp, _Up>::value;
template <typename _Tp>
  constexpr bool is_nothrow_copy_assignable_v =
    is_nothrow_copy_assignable<_Tp>::value;
template <typename _Tp>
  constexpr bool is_nothrow_move_assignable_v =
    is_nothrow_move_assignable<_Tp>::value;
template <typename _Tp>
  constexpr bool is_nothrow_destructible_v =
    is_nothrow_destructible<_Tp>::value;
template <typename _Tp>
  constexpr bool has_virtual_destructor_v =
    has_virtual_destructor<_Tp>::value;
template <typename _Tp>
  constexpr size_t alignment_of_v = alignment_of<_Tp>::value;
template <typename _Tp>
  constexpr size_t rank_v = rank<_Tp>::value;
template <typename _Tp, unsigned _Idx = 0>
  constexpr size_t extent_v = extent<_Tp, _Idx>::value;
#ifdef _GLIBCXX_BUILTIN_IS_SAME_AS
template <typename _Tp, typename _Up>
  constexpr bool is_same_v = _GLIBCXX_BUILTIN_IS_SAME_AS(_Tp, _Up);
#else
template <typename _Tp, typename _Up>
  constexpr bool is_same_v = std::is_same<_Tp, _Up>::value;
#endif
template <typename _Base, typename _Derived>
  constexpr bool is_base_of_v = is_base_of<_Base, _Derived>::value;
template <typename _From, typename _To>
  constexpr bool is_convertible_v = is_convertible<_From, _To>::value;
}
#endif
namespace OY {
#define cin OY::inputHelper<1024, 20>::getInstance()
#define getchar() ({char c=cin.getChar_Checked();cin.next();c;})
#define cout OY::outputHelper<1048576>::getInstance()
#define putchar cout.putChar
#define endl '\n'
#define putlog(...) OY::printLog(", ", __VA_ARGS__)
    template <uint64_t _BufferSize = 1024, uint64_t _BlockSize = 20>
    class inputHelper {
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
        template <typename _Tp, std::enable_if_t<std::is_signed_v<_Tp> & std::is_integral_v<_Tp>> * = nullptr>
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
        template <typename _Tp, std::enable_if_t<std::is_unsigned_v<_Tp> & std::is_integral_v<_Tp>> * = nullptr>
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
        template <typename _Tp, std::enable_if_t<std::is_floating_point_v<_Tp>> * = nullptr>
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
    template <uint64_t _BufferSize = 1048576>
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
        template <typename _Tp, std::enable_if_t<std::is_signed_v<_Tp> & std::is_integral_v<_Tp>> * = nullptr>
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
        template <typename _Tp, std::enable_if_t<std::is_unsigned_v<_Tp> & std::is_integral_v<_Tp>> * = nullptr>
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
        template <typename _Tp, std::enable_if_t<std::is_floating_point_v<_Tp>> * = nullptr>
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
            ih.setState(0);
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
        if (sizeof...(rest) > 0) {
            cout << delim;
            printLog(delim, rest...);
        }
    }
}
using OY::getline;
const int N = 3e5;
int fa[N];
long long a[N];
std::vector<std::vector<int>> seg;

int find(int x) {
    return (fa[x] == x ? fa[x] : fa[x] = find(fa[x]));
}

std::deque<int> q;

void solve() {
    int n, m, l, r;
    long long x;
    cin >> n >> m;
    fa[0] = a[0] = 0;
    seg.resize(n + 5);
    for (int i = 1; i <= n; ++i) {
        fa[i] = i;
        cin >> a[i];
    }
    fa[n + 1] = n + 1;
    for (int i = 1; i <= n; ++i) {
        cin >> x;
        a[i] += a[i - 1]  - x;
    }
    for (int i = 0; i <= n; ++i) {
        if (!a[i]) {
            fa[i] = i + 1;
            q.push_back(i);
        }
    }
    

    for (int i = 1; i <= m; ++i) {
        cin >> l >> r;
        seg[l - 1].push_back(r);
        seg[r].push_back(l - 1);
    }
    while (!q.empty()) {
        int u = q.front();
        q.pop_front();
        for (int v : seg[u]) {
            if (a[v]) continue;
            l = std::min(v, u), r = std::max(v, u);
            int now = l;
            while (now <= r) {
                if (a[now]) {
                    a[now] = 0;
                    q.push_back(now);
                }
                now = fa[now] = find(now + 1);
            }
        }
    }
    bool pd = true;
    for (int i = 0; i <= n; ++i) {
        if (a[i]) {
            pd = false;
            break;
        }
    }
    if (pd) cout << "YES\n";
    else cout << "NO\n";
    q.clear();
    seg.clear();
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
}