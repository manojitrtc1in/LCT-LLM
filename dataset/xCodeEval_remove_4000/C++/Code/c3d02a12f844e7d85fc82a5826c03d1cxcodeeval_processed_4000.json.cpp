

















using i64 = long long;
using ui64 = unsigned long long;


using i128 = __int128;
using ui128 = unsigned __int128;

using i128 = long long;
using ui128 = unsigned long long;

using LD = long double;

using f128 = __float128;

using f128 = long double;




inline namespace {
    class Time {
    public:
        clock_t begin;
        Time(): begin(clock()) {}
        ~Time() {
            double t = (clock() - begin) * 1000.0 / CLOCKS_PER_SEC;
            

            fprintf(stderr, "\033[1;32m");
            if (t >= 60000)
                fprintf(stderr, "%.2lfmin\n", t / 60000.);
            else if (t >= 1000)
                fprintf(stderr, "%.2lfs\n", t / 1000.);
            else
                fprintf(stderr, "%.0lfms\n", t);
            fprintf(stderr, "\033[0m");
        }
    } _;
}  



template <typename T>
struct make_unsigned: public std::make_unsigned<T> {};
template <>
struct make_unsigned<i128> {
    using type = ui128;
};

template <typename T, typename P>
inline constexpr std::common_type_t<T, P> max(const T& x, const P& y) { return x < y ? y : x; }
template <typename T, typename P>
inline constexpr std::common_type_t<T, P> min(const T& x, const P& y) { return x < y ? x : y; }
template <typename T, typename... Args>
inline constexpr std::common_type_t<T, Args...> max(const T& x, const Args&... args) { return max(x, max(args...)); }
template <typename T, typename... Args>
inline constexpr std::common_type_t<T, Args...> min(const T& x, const Args&... args) { return min(x, min(args...)); }
template <typename T>
inline constexpr T max(const T& x) { return x; }
template <typename T>
inline constexpr T min(const T& x) { return x; }
template <typename T, typename... Args>
inline void chkmax(T& d, const Args&... args) { d = max(d, args...); }
template <typename T, typename... Args>
inline void chkmin(T& d, const Args&... args) { d = min(d, args...); }







    type id1; \
    io.read(id1)

std::mt19937 mrand(std::random_device{}());
std::mt19937_64 id0(std::random_device{}());


constexpr std::size_t bufSize = 1 << 22;

class IO;
class In {
    friend class IO;

private:
    FILE* inFile = nullptr;
    bool status = true;

    struct stat st;
    char* ptr;
    int fd;

    char buf[bufSize], *p1, *p2;

public:

    inline int getch() { return fgetc(inFile); }
    inline void putback(char c) { ungetc(c, inFile); }
    inline void input(FILE* f) { inFile = f, setStatus(true); }
    inline void input(const char* str) { inFile = fopen(str, "rb"), setStatus(true); }

    inline int getch() { return *ptr ? *ptr++ : (setStatus(false), EOF); }
    inline void putback(char) { ptr--; }
    inline void input(FILE* f) {
        if ((inFile = f))
            fd = fileno(inFile), fstat(fd, &st), ptr = (char*)mmap(nullptr, st.st_size, PROT_READ, MAP_PRIVATE, fd, 0);
        setStatus(true);
    }
    inline void input(const char* str) { fd = open(str, O_RDONLY), fstat(fd, &st), ptr = (char*)mmap(0, st.st_size, PROT_READ, MAP_PRIVATE, fd, 0), setStatus(true); }

    inline int getch() { return (p1 == p2 ? (p2 = (p1 = buf) + fread(buf, 1, bufSize, inFile)) : 0), (p1 == p2) ? (setStatus(false), EOF) : *p1++; }
    inline void putback(char c) { *(--p1) = c; }
    inline void input(FILE* f) { inFile = f, p1 = p2 = buf, setStatus(true); }
    inline void input(const char* str) { inFile = fopen(str, "rb"), p1 = p2 = buf, setStatus(true); }

    inline void setStatus(bool status) { this->status = status; }
    inline bool getStatus() const { return status; }
};
class Out {
private:
    FILE* outFile = nullptr;

    char pbuf[bufSize], *pp;

public:

    inline void flush() { outFile ? fflush(outFile) : 0; }
    inline void putch(const char c) { fputc(c, outFile); }

    inline void flush() { (outFile ? fwrite(pbuf, 1, pp - pbuf, outFile), fflush(outFile) : 0), pp = pbuf; }
    inline void putch(const char c) { ((pp - pbuf == bufSize) ? fwrite(pbuf, 1, bufSize, outFile), pp = pbuf : 0), *pp++ = c; }

    inline void output(const char* str) { flush(), outFile = fopen(str, "wb"); }
    inline void output(FILE* f) { flush(), outFile = f; }
};
class IO: public In, public Out {
private:
    long double eps = 1e-8L;
    i128 pow10 = 1000000;
    std::size_t precision = 6;

public:
    IO(FILE* = nullptr, FILE* = nullptr);
    ~IO();
    inline void flush();
    inline static constexpr bool blank(char);
    template <typename T, typename... Args>
    IO& read(T&, Args&...);
    template <typename T>
        requires(std::is_signed_v<T> && std::is_integral_v<T>) || std::is_same_v<std::remove_cv_t<T>, i128>
    IO& read(T&);
    template <typename T>
        requires(std::is_unsigned_v<T> && std::is_integral_v<T>) || std::is_same_v<std::remove_cv_t<T>, ui128>
    IO& read(T&);
    template <typename T>
        requires std::is_floating_point_v<T>
    IO& read(T&);
    template <typename T>
        requires std::is_arithmetic_v<T> || std::is_same_v<std::remove_cv_t<T>, i128> || std::is_same_v<std::remove_cv_t<T>, ui128>
    T read();
    IO& read(char&);
    IO& read(char*);
    IO& readline(char*);
    inline void setprecision(std::size_t = 6u);
    template <typename T, typename... Args>
    void write(const T&, const Args&...);
    inline void write() const {}
    template <typename T>
        requires(std::is_signed_v<T> && std::is_integral_v<T>) || std::is_same_v<std::remove_cv_t<T>, i128>
    void write(T);
    template <typename T>
        requires(std::is_unsigned_v<T> && std::is_integral_v<T>) || std::is_same_v<std::remove_cv_t<T>, ui128>
    void write(T);
    inline void write(char);
    template <typename T>
        requires std::is_floating_point_v<T>
    T write(T);
    inline void write(bool);
    void write(char*);
    void write(const char*);
    template <typename... Args>
    void writeln(Args...);
    template <std::input_iterator Iter>
    IO& readArray(Iter, Iter);
    template <std::ranges::input_range Range>
    IO& readArray(Range&&);
    template <std::input_iterator Iter>
    void displayArray(Iter, Iter, char = ' ');
    template <std::ranges::input_range Range>
    void displayArray(Range&&, char = ' ');
    operator bool() const { return getStatus(); }
} io(stdin, stdout), err(nullptr, stderr);
template <typename Func>
void multipleTests(Func&&, IO& = io);
template <typename... Args>
inline void writeln(Args... x) { io.write(x...), io.putch('\n'); }



int main() {
    multipleTests([&]() {
        dR(int, n);
        dR(i64, h);
        std::vector<i64> a(n);
        io.readArray(a);
        std::ranges::sort(a);
        auto absorb = [&](int& L, i64& h) {
            if (L >= n)
                return;
            auto check = [&](i64 x) {
                i64 _h = h;
                for (int i = L; i < x; i++) {
                    if (a[i] >= _h)
                        return false;
                    _h += a[i] / 2;
                }
                return true;
            };
            i64 l = L, r = n;
            while (l < r) {
                i64 m = (l + r + 1) >> 1;
                if (check(m))
                    l = m;
                else
                    r = m - 1;
            }
            if (!l)
                return; 
            for (int i = L; i < l; i++) h += a[i] / 2;
            L = l;
        };
        std::vector<int> p{2, 2, 3};
        int ans = 0;
        do {
            int L = 0;
            i64 _h = h;
            absorb(L, h);
            for (auto x: p)
                h *= x, absorb(L, h);
            h = _h;
            chkmax(ans, L);
        } while (std::next_permutation(p.begin(), p.end()));
        std::cout << ans << "\n";
    });
    return 0;
}


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
    requires(std::is_signed_v<T> && std::is_integral_v<T>) || std::is_same_v<std::remove_cv_t<T>, i128>
IO& IO::read(T& x) {
    static typename make_unsigned<T>::type _tmp;
    bool sign = false;

    int ch = getch();
    while (!isdigit(ch) && ~ch)
        sign = (ch == '-'), ch = getch();
    if (ch == -1)
        return setStatus(false), *this;
    _tmp = 0;
    while (isdigit(ch))
        _tmp = _tmp * 10 + (ch - '0'), ch = getch();

    static constexpr auto n = []() {
        std::array<unsigned, 0x10000> n{};
        for (int i = 0; i != 0x10000; i++)
            n[i] = -1;
        constexpr unsigned e0 = '\0\1', e1 = '\1\0';
        int x = 0;
        for (unsigned i = 0, c0 = '00'; i != 10; i++, c0 += e0)
            for (unsigned j = 0, c1 = c0; j != 10; j++, c1 += e1)
                n[c1] = x++;
        return n;
    }();
    while (!isdigit(*ptr) && *ptr)
        sign = *ptr++ == '-';
    if (!*ptr)
        return setStatus(false), *this;
    _tmp = *ptr++ - '0';
    while (~n[*reinterpret_cast<std::uint16_t*&>(ptr)])
        _tmp = _tmp * 100 + n[*reinterpret_cast<std::uint16_t*&>(ptr)++];
    if (isdigit(*ptr))
        _tmp = _tmp * 10 + (*ptr++ - '0');

    x = sign ? (~_tmp + 1) : _tmp;
    return *this;
}
template <typename T>
    requires(std::is_unsigned_v<T> && std::is_integral_v<T>) || std::is_same_v<std::remove_cv_t<T>, ui128>
IO& IO::read(T& x) {

    int ch = getch();
    while (!isdigit(ch) && ~ch)
        ch = getch();
    if (ch == -1)
        return setStatus(false), *this;
    x = 0;
    while (isdigit(ch))
        x = (x << 1) + (x << 3) + (ch ^ '0'), ch = getch();

    static constexpr auto n = []() {
        std::array<unsigned, 0x10000> n{};
        for (int i = 0; i != 0x10000; i++)
            n[i] = -1;
        constexpr unsigned e0 = '\0\1', e1 = '\1\0';
        int x = 0;
        for (unsigned i = 0, c0 = '00'; i != 10; i++, c0 += e0)
            for (unsigned j = 0, c1 = c0; j != 10; j++, c1 += e1)
                n[c1] = x++;
        return n;
    }();
    while (!isdigit(*ptr) && *ptr)
        ptr++;
    if (!*ptr)
        return setStatus(false), *this;
    x = *ptr++ - '0';
    while (~n[*reinterpret_cast<std::uint16_t*&>(ptr)])
        x = x * 100 + n[*reinterpret_cast<std::uint16_t*&>(ptr)++];
    if (isdigit(*ptr))
        x = x * 10 + (*ptr++ - '0');

    return *this;
}
template <typename T>
    requires std::is_floating_point_v<T>
IO& IO::read(T& x) {
    x = 0;
    T tmp = 1;
    bool sign = false;
    int ch = getch();
    while (!isdigit(ch) && ~ch)
        sign = (ch == '-'), ch = getch();
    if (ch == -1)
        return setStatus(false), *this;
    while (isdigit(ch))
        x = (x << 1) + (x << 3) + (ch ^ '0'), ch = getch();
    if (ch == '.')
        for (ch = getch(); isdigit(ch); ch = getch())
            x += (tmp /= 10.0) * (ch ^ '0');
    x = sign ? (-x) : x;
    return *this;
}
template <typename T>
    requires std::is_arithmetic_v<T> || std::is_same_v<std::remove_cv_t<T>, i128> || std::is_same_v<std::remove_cv_t<T>, ui128>
T IO::read() {
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
inline void IO::setprecision(std::size_t n) {
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
    requires(std::is_signed_v<T> && std::is_integral_v<T>) || std::is_same_v<std::remove_cv_t<T>, i128>
void IO::write(T x) {
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
    requires(std::is_unsigned_v<T> && std::is_integral_v<T>) || std::is_same_v<std::remove_cv_t<T>, ui128>
void IO::write(T x) {
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
    requires std::is_floating_point_v<T>
T IO::write(T x) {
    if (x == 0) {
        putch('0'), putch('.');
        for (std::size_t i = 0; i < precision; i++)
            putch('0');
        return;
    }
    if (x < 0)
        putch('-'), x = -x;
    T res = (i128)(x * pow10 + 0.5) / (pow10 * 1.0);
    i128 y = i128(res * pow10 + eps) % pow10;
    write(i128(res + eps));
    if (precision) {
        putch('.');
        static std::size_t sta[100], p = 0;
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
template <std::input_iterator Iter>
IO& IO::readArray(Iter first, Iter last) {
    bool f = true;
    std::ranges::for_each(first, last, [&](auto& x) { f &= read(x); });
    if (!f)
        setStatus(false);
    return *this;
}
template <std::ranges::input_range Range>
IO& IO::readArray(Range&& r) {
    return readArray(std::ranges::begin(r), std::ranges::end(r));
}
template <std::input_iterator Iter>
void IO::displayArray(Iter first, Iter last, char delim) {
    if (first == last)
        return putch('\n');
    write(*first++);
    for (; first != last; ++first) {
        putch(delim);
        write(*first);
    }
    putch('\n');
}
template <std::ranges::input_range Range>
void IO::displayArray(Range&& r, char delim) {
    return displayArray(std::ranges::begin(r), std::ranges::end(r), delim);
}
template <typename Func>
void multipleTests(Func&& f, IO& _io) {
    int q;
    _io.read(q);
    while (q--)
        f();
}
