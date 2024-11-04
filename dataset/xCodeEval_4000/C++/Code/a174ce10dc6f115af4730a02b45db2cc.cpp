

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <random>

#ifndef LX_DEBUG


#endif

#if defined(__unix__) && !defined(LX_DEBUG) && !defined(LX_LOCAL)
#define USE_MMAP 1
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#else
#define USE_MMAP 0
#endif

using LL = long long;
using ULL = unsigned long long;
#ifdef __SIZEOF_INT128__
#define USE_INT128
using LLL = __int128;
using ULLL = unsigned __int128;
#else
using LLL = long long;
using ULLL = unsigned long long;
#endif
using LD = long double;
#if defined(__SIZEOF_FLOAT128__) && !defined(LX_LOCAL)
using LLD = __float128;
#else
using LLD = long double;
#endif

namespace std {
#define def(type) \
    void swap(type& x, type& y) { x ^= y, y ^= x, x ^= y; }
    def(char);
    def(signed char);
    def(unsigned char);
    def(short);
    def(unsigned short);
    def(int);
    def(unsigned int);
    def(LL);
    def(ULL);
#ifdef __SIZEOF_INT128__
    def(LLL);
    def(ULLL);
#endif
#undef def
};  


#ifdef LX_LOCAL
#include <ctime>
class Time {
public:
    clock_t begin;
    Time() { begin = clock(); }
    ~Time() {
        double t = (clock() - begin) * 1000.0 / static_cast<double>(CLOCKS_PER_SEC);
        fprintf(stderr, "Time used = ");
        if (t >= 60000)
            fprintf(stderr, "%.2lfmin\n", t / 60000.0);
        else if (t >= 1000)
            fprintf(stderr, "%.2lfs\n", t / 1000.0);
        else
            fprintf(stderr, "%.0lfms\n", t);
    }
} timeout;
#endif

template <typename T>
struct make_unsigned : public std::make_unsigned<T> {};
template <>
struct make_unsigned<LLL> { typedef ULLL type; };

using std::swap;
#if __cplusplus >= 201402L
template <typename T, typename P>
inline constexpr auto max(const T& x, const P& y) { return x < y ? y : x; }
template <typename T, typename P>
inline constexpr auto min(const T& x, const P& y) { return x < y ? x : y; }
template <typename T, typename... Args>
inline constexpr auto max(const T& x, const Args&... args) { return max(x, max(args...)); }
template <typename T, typename... Args>
inline constexpr auto min(const T& x, const Args&... args) { return min(x, min(args...)); }
#else
template <typename T, typename P>
inline constexpr auto max(const T& x, const P& y) -> decltype(x < y ? y : x) { return x < y ? y : x; }
template <typename T, typename P>
inline constexpr auto min(const T& x, const P& y) -> decltype(x < y ? x : y) { return x < y ? x : y; }
template <typename T, typename... Args>
inline constexpr auto max(const T& x, const Args&... args) -> decltype(max(x, max(args...))) { return max(x, max(args...)); }
template <typename T, typename... Args>
inline constexpr auto min(const T& x, const Args&... args) -> decltype(min(x, min(args...))) { return min(x, min(args...)); }
#endif
template <typename T>
inline constexpr T max(const T& x) { return x; }
template <typename T>
inline constexpr T min(const T& x) { return x; }
template <typename T, typename... Args>
inline void chkmax(T& d, const Args&... args) { d = max(d, args...); }
template <typename T, typename... Args>
inline void chkmin(T& d, const Args&... args) { d = min(d, args...); }

#define lc (o << 1)
#define rc (o << 1 | 1)
#define lowbit(x) ((x) & (-(x)))
#define ALL(x) std::begin(x), std::end(x)
#define SZ(x) int(x.size())
#define dR(type, ...) \
    type __VA_ARGS__; \
    io.read(__VA_ARGS__)

std::mt19937 mrand(std::random_device{}());
std::mt19937_64 mrand64(std::random_device{}());

#pragma region IO
constexpr size_t bufSize = 1 << 20;

class In {
private:
    FILE* inFile = nullptr;
    bool status = true;
#if USE_MMAP
    struct stat st;
    char* ptr;
    int fd;
    size_t pos;
#elif !defined(LX_DEBUG)
    char buf[bufSize], *p1, *p2;
#endif
public:
#ifdef LX_DEBUG
    inline int getch() { return fgetc(inFile); }
    inline void putback(char c) { ungetc(c, inFile); }
    inline void input(FILE* f) { inFile = f, setStatus(true); }
    inline void input(const char* str) { inFile = fopen(str, "rb"), setStatus(true); }
#elif USE_MMAP
    inline int getch() { return *(ptr + pos) ? *(ptr + (pos++)) : (setStatus(false), EOF); }
    inline void putback(char) { pos--; }
    inline void input(FILE* f) {
        if ((inFile = f))
            fd = fileno(inFile), fstat(fd, &st), ptr = (char*)mmap(0, st.st_size, PROT_READ, MAP_PRIVATE, fd, 0), pos = 0;
        setStatus(true);
    }
    inline void input(const char* str) { fd = open(str, O_RDONLY), fstat(fd, &st), ptr = (char*)mmap(0, st.st_size, PROT_READ, MAP_PRIVATE, fd, 0), pos = 0, setStatus(true); }
#else
    inline int getch() { return (p1 == p2 ? (p2 = (p1 = buf) + fread(buf, 1, bufSize, inFile)) : 0), (p1 == p2) ? (setStatus(false), EOF) : *p1++; }
    inline void putback(char c) { *(--p1) = c; }
    inline void input(FILE* f) { inFile = f, p1 = p2 = buf, setStatus(true); }
    inline void input(const char* str) { inFile = fopen(str, "rb"), p1 = p2 = buf, setStatus(true); }
#endif
    inline void setStatus(bool status) { this->status = status; }
    inline bool getStatus() const { return status; }
};
class Out {
private:
    FILE* outFile = nullptr;
#ifndef LX_DEBUG
    char pbuf[bufSize], *pp;
#endif
public:
#ifdef LX_DEBUG
    inline void flush() { outFile ? fflush(outFile) : 0; }
    inline void putch(const char c) { fputc(c, outFile); }
#else
    inline void flush() { (outFile ? fwrite(pbuf, 1, pp - pbuf, outFile), fflush(outFile) : 0), pp = pbuf; }
    inline void putch(const char c) { ((pp - pbuf == bufSize) ? fwrite(pbuf, 1, bufSize, outFile), pp = pbuf : 0), *pp++ = c; }
#endif
    inline void output(const char* str) { flush(), outFile = fopen(str, "wb"); }
    inline void output(FILE* f) { flush(), outFile = f; }
};
class IO : public In, public Out {
private:
    long double eps = 1e-8L;
    LLL pow10 = 1000000;
    size_t precision = 6;

public:
    IO(FILE* = nullptr, FILE* = nullptr);
    ~IO();
    inline void flush();
    inline static constexpr bool blank(char);
    template <typename T, typename... Args>
    IO& read(T&, Args&...);
    template <typename T>
    typename std::enable_if<(std::is_signed<T>::value && std::is_integral<T>::value) || std::is_same<typename std::remove_cv<T>::type, LLL>::value, IO&>::type read(T&);
    template <typename T>
    typename std::enable_if<(std::is_unsigned<T>::value && std::is_integral<T>::value) || std::is_same<typename std::remove_cv<T>::type, ULLL>::value, IO&>::type read(T&);
    template <typename T>
    typename std::enable_if<std::is_floating_point<T>::value, IO&>::type read(T&);
    template <typename T>
    typename std::enable_if<std::is_integral<T>::value || std::is_floating_point<T>::value || std::is_same<typename std::remove_cv<T>::type, LLL>::value || std::is_same<typename std::remove_cv<T>::type, ULLL>::value, T>::type read();
    IO& read(char&);
    IO& read(char*);
    IO& readline(char*);
    inline void setprecision(size_t = 6u);
    template <typename T, typename... Args>
    void write(const T&, const Args&...);
    inline void write() const {}
    template <typename T>
    typename std::enable_if<(std::is_signed<T>::value && std::is_integral<T>::value) || std::is_same<T, LLL>::value, void>::type write(T);
    template <typename T>
    typename std::enable_if<(std::is_unsigned<T>::value && std::is_integral<T>::value) || std::is_same<T, ULLL>::value, void>::type write(T);
    inline void write(char);
    template <typename T>
    typename std::enable_if<std::is_floating_point<T>::value, void>::type write(T);
    inline void write(bool);
    void write(char*);
    void write(const char*);
    template <typename... Args>
    void writeln(Args...);
    template <typename Iter>
    IO& readArray(Iter, Iter);
    template <typename Iter>
    void displayArray(Iter, Iter, char = ' ');
    operator bool() const { return getStatus(); }
} io(stdin, stdout), err(nullptr, stderr);
template <typename Func>
void multipleTests(Func&&, IO& = io);
template <typename... Args>
inline void writeln(Args... x) { io.write(x...), io.putch('\n'); }
#define dbg(x) err.write(#x " = "), err.writeln(x)
#pragma endregion IO
constexpr int maxn = 500005, SIZE = 710;

int A[maxn], cnt[maxn], ans[maxn];
int st[maxn], pos[maxn], bl[maxn], top;
struct Query {
    int l, r, id;
    bool operator<(const Query& rhs) const {
        if (bl[l] ^ bl[rhs.l])
            return l < rhs.l;
        return bl[l] & 1 ? r < rhs.r : r > rhs.r;
    }
} qu[maxn];

inline void add(int p) {
    if (!cnt[p])
        st[++top] = p, pos[p] = top;
    else if (cnt[p] == 1) {
        st[pos[p]] = st[top];
        pos[st[top]] = pos[p];
        st[top--] = pos[p] = 0;
    }
    cnt[p]++;
}
inline void del(int p) {
    cnt[p]--;
    if (!cnt[p]) {
        st[pos[p]] = st[top];
        pos[st[top]] = pos[p];
        st[top--] = pos[p] = 0;
    }
    else if (cnt[p] == 1)
        st[++top] = p, pos[p] = top;
}
int main() {
    dR(int, n).readArray(A + 1, A + n + 1);
    dR(int, q);
    for (int i = 1; i <= q; i++)
        io.read(qu[i].l, qu[i].r), qu[i].id = i, bl[i] = i / SIZE+1;
    std::sort(qu + 1, qu + q + 1);
    int l = 1, r = 0;
    for (int i = 1; i <= q; i++) {
        const auto& q = qu[i];
        while (r < q.r)
            add(A[++r]);
        while (r > q.r)
            del(A[r--]); 
        while (l < q.l) 
            del(A[l++]);
        while (l > q.l)
            add(A[--l]);
        ans[q.id] = st[top];
    }
    io.displayArray(ans + 1, ans + q + 1, '\n');
    return 0;
}

#define isdigit(x) (x >= '0' && x <= '9')
IO::IO(FILE* in, FILE* out) { input(in), output(out); }
IO::~IO() { flush(); }
inline void IO::flush() { Out::flush(); }
inline constexpr bool IO::blank(char ch) { return ch == ' ' || ch == '\n' || ch == '\r' || ch == '\t'; }
template <typename T, typename... Args>
IO& IO::read(T& x, Args&... args) {
    if (read(x))
        return sizeof...(args) ? read(args...) : *this;
    return *this;
}
template <typename T>
typename std::enable_if<(std::is_signed<T>::value && std::is_integral<T>::value) || std::is_same<typename std::remove_cv<T>::type, LLL>::value, IO&>::type IO::read(T& x) {
    static typename make_unsigned<T>::type _tmp;
    bool sign = false;
    int ch = getch();
    while (!isdigit(ch) && ~ch)
        sign = (ch == '-'), ch = getch();
    if (!(~ch))
        return setStatus(false), *this;
    _tmp = 0;
    while (isdigit(ch))
        _tmp = (_tmp << 1) + (_tmp << 3) + (ch ^ '0'), ch = getch();
    if (~ch)
        putback(ch);
    x = sign ? (~_tmp + 1) : _tmp;
    return *this;
}
template <typename T>
typename std::enable_if<(std::is_unsigned<T>::value && std::is_integral<T>::value) || std::is_same<typename std::remove_cv<T>::type, ULLL>::value, IO&>::type IO::read(T& x) {
    int ch = getch();
    while (!isdigit(ch) && ~ch)
        ch = getch();
    if (!(~ch))
        return setStatus(false), *this;
    x = 0;
    while (isdigit(ch))
        x = (x << 1) + (x << 3) + (ch ^ '0'), ch = getch();
    if (~ch)
        putback(ch);
    return *this;
}
template <typename T>
typename std::enable_if<std::is_floating_point<T>::value, IO&>::type IO::read(T& x) {
    x = 0;
    T tmp = 1;
    bool sign = false;
    int ch = getch();
    while (!isdigit(ch) && ~ch)
        sign = (ch == '-'), ch = getch();
    if (!(~ch))
        return setStatus(false), *this;
    while (isdigit(ch))
        x = x * 10 + (ch ^ '0'), ch = getch();
    if (ch == '.')
        for (ch = getch(); isdigit(ch); ch = getch())
            x += (tmp /= 10.0) * (ch ^ '0');
    if (~ch)
        putback(ch);
    x = sign ? (-x) : x;
    return *this;
}
template <typename T>
typename std::enable_if<std::is_integral<T>::value || std::is_floating_point<T>::value || std::is_same<typename std::remove_cv<T>::type, LLL>::value || std::is_same<typename std::remove_cv<T>::type, ULLL>::value, T>::type IO::read() {
    static typename std::remove_cv<T>::type x;
    return read(x), x;
}
IO& IO::read(char& ch) {
    do
        ch = getch();
    while (blank(ch) && ~ch);
    if (ch == -1)
        setStatus(false);
    return *this;
}
IO& IO::read(char* s) {
    int ch = getch();
    while (blank(ch))
        ch = getch();
    if (!(~ch))
        return setStatus(false), *this;
    while (!blank(ch) && ~ch)
        *s++ = ch, ch = getch();
    *s = 0;
    if (~ch)
        putback(ch);
    return *this;
}
IO& IO::readline(char* s) {
    int ch = getch();
    while (blank(ch) && (ch ^ '\n'))
        ch = getch();
    if (!(~ch))
        return setStatus(false), *this;
    while ((ch ^ '\n') && ~ch)
        *s++ = ch, ch = getch();
    *s = 0;
    return *this;
}
inline void IO::setprecision(size_t n) {
    precision = n;
    eps = powl(10.0L, -int(precision) - 2);
    pow10 = powl(10.0L, precision) + eps;
}
template <typename T, typename... Args>
void IO::write(const T& x, const Args&... args) {
    write(x);
    if (sizeof...(args))
        write(args...);
}
template <typename T>
typename std::enable_if<(std::is_signed<T>::value && std::is_integral<T>::value) || std::is_same<T, LLL>::value, void>::type IO::write(T x) {
    if (x < 0)
        x = ~x + 1, putch('-');
    static int sta[40], top = 0;
    do
        sta[top++] = x % 10, x /= 10;
    while (x);
    while (top)
        putch(sta[--top] ^ '0');
}
template <typename T>
typename std::enable_if<(std::is_unsigned<T>::value && std::is_integral<T>::value) || std::is_same<T, ULLL>::value, void>::type IO::write(T x) {
    static int sta[40], top = 0;
    do
        sta[top++] = x % 10, x /= 10;
    while (x);
    while (top)
        putch(sta[--top] ^ '0');
}
inline void IO::write(bool x) { putch(x ^ 48); }
inline void IO::write(char c) { putch(c); }
template <typename T>
typename std::enable_if<std::is_floating_point<T>::value>::type IO::write(T x) {
    if (x == 0) {
        putch('0'), putch('.');
        for (size_t i = 1; i <= precision; i++)
            putch('0');
        return;
    }
    if (x < 0)
        putch('-'), x = -x;
    T res = (LLL)(x * pow10 + 0.5) / (pow10 * 1.0);
    LLL y = LLL(res * pow10 + eps) % pow10;
    write(LLL(res + eps));
    if (precision) {
        putch('.');
        static size_t sta[100], p = 0;
        while (p < precision && y)
            sta[++p] = y % 10, y /= 10;
        while (p < precision)
            sta[++p] = 0;
        while (p)
            putch(sta[p--] ^ 48);
    }
}
void IO::write(char* s) {
    while (*s)
        putch(*s++);
}
void IO::write(const char* s) {
    while (*s)
        putch(*s++);
}
template <typename... Args>
void IO::writeln(Args... x) { write(x...), putch('\n'); }
template <typename Iter>
IO& IO::readArray(Iter first, Iter last) {
    if (first == last)
        return *this;
    Iter cur = first;
    bool r = true;
    while (cur != last && r)
        r &= read(*cur++);
    if (!r)
        setStatus(false);
    return *this;
}
template <typename Iter>
void IO::displayArray(Iter first, Iter last, char delim) {
    if (first == last)
        return putch('\n');
    for (Iter cur = first; cur != last;) {
        write(*cur);
        if (++cur != last)
            putch(delim);
    }
    putch('\n');
}
template <typename Func>
void multipleTests(Func&& f, IO& _io) {
    int q;
    _io.read(q);
    for (int i = 1; i <= q; i++)
        f();
}
#undef isdigit