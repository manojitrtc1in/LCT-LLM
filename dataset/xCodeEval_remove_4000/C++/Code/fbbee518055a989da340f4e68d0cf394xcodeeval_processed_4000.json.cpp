








namespace std
{
template <typename...> using void_t = void;
}

template <typename T, typename _ = void> struct is_container : std::false_type
{};
template <typename... Ts> struct is_container_helper
{};
template <typename T>
struct is_container<T,
    typename std::conditional<false,
        is_container_helper<decltype(std::declval<T>().size()),
            decltype(std::declval<T>().begin()),
            decltype(std::declval<T>().end()),
            decltype(std::declval<T>().cbegin()),
            decltype(std::declval<T>().cend())>,
        void>::type> : public std::true_type
{};



class IO
{
    static const int bufSize = 1 << 20;

    char inBuf[bufSize], outBuf[bufSize];
    char *ip1 = inBuf, *ip2 = inBuf;
    int goodReadBit = 1, op1 = -1, op2 = bufSize - 1;
    FORCE_INLINE int gc()
    {
        return ip1 == ip2
                && (ip2 = (ip1 = inBuf) + fread(inBuf, 1, bufSize, stdin),
                    ip1 == ip2)
            ? (goodReadBit = 0, EOF)
            : *ip1++;
    }
    template <typename T> FORCE_INLINE void __RI(T &x)
    {
        int ch = gc(), neg = 1;
        x = 0;
        for (; !(isdigit(ch) || ch == '-' || ch == EOF); ch = gc()) {}
        if (ch == EOF) return;
        if (ch == '-') neg = -1, ch = gc();
        for (; isdigit(ch); ch = gc()) x = x * 10 + (ch - 48) * neg;
    }
    template <typename T> FORCE_INLINE void __RC(T &x)
    {
        int ch;
        while (isspace(ch = gc())) {}
        if (ch == EOF) return;
        x = ch;
    }
    FORCE_INLINE void __RS(std::string &x)
    {
        char ch;
        x.clear();
        for (ch = gc(); isspace(ch); ch = gc()) {}
        if (ch == EOF) return;
        for (; !isspace(ch) && ch != EOF; ch = gc()) x.push_back(ch);
    }

public:
    FORCE_INLINE IO &R(char &x) { return __RC(x), (*this); }
    FORCE_INLINE IO &R(unsigned char &x) { return __RC(x), (*this); }
    FORCE_INLINE IO &R(std::string &x) { return __RS(x), (*this); }
    template <typename T1, typename T2> FORCE_INLINE IO &R(std::pair<T1, T2> &x)
    {
        return R(x.first), R(x.second), (*this);
    }
    template <typename T, typename... Args> FORCE_INLINE IO &RA(T *a, int n)
    {
        for (int i = 0; i < n; ++i) R(a[i]);
        return (*this);
    }
    template <typename T, typename... Args>
    FORCE_INLINE IO &R(T &x, Args &...args)
    {
        return R(x), R(args...), (*this);
    }
    template <typename T, typename... Args>
    FORCE_INLINE IO &RA(T *a, int n, Args... args)
    {
        for (int i = 0; i < n; ++i) RA(a[i], args...);
        return (*this);
    }
    template <typename T>
    FORCE_INLINE typename std::enable_if<std::is_integral<T>::value, IO>::type &
        R(T &x)
    {
        return __RI(x), (*this);
    }
    template <typename T>
    FORCE_INLINE typename std::enable_if<is_container<T>::value, IO>::type &R(
        T &x)
    {
        for (auto &i : x) R(i);
        return (*this);
    }
    template <typename T>
    FORCE_INLINE typename std::enable_if<
        std::is_void<std::void_t<decltype(std::declval<T>().read())>>::value,
        IO>::type &
        R(T &x)
    {
        return x.read(), (*this);
    }

private:
    char space = ' ';
    FORCE_INLINE void pc(const char &x)
    {
        if (op1 == op2) flush();
        outBuf[++op1] = x;
    }
    template <typename T> FORCE_INLINE void __WI(T x)
    {
        static char buf[sizeof(T) * 16 / 5];
        static int len = -1;
        if (x >= 0) {
            do {
                buf[++len] = x % 10 + 48, x /= 10;
            } while (x);
        } else {
            pc('-');
            do {
                buf[++len] = -(x % 10) + 48, x /= 10;
            } while (x);
        }
        while (len >= 0) { pc(buf[len]), --len; }
    }

public:
    FORCE_INLINE void flush() { fwrite(outBuf, 1, op1 + 1, stdout), op1 = -1; }
    FORCE_INLINE IO &W(const char &x) { return pc(x), (*this); }
    FORCE_INLINE IO &W(const char *x)
    {
        while (*x != '\0') pc(*(x++));
        return (*this);
    }
    FORCE_INLINE IO &W(const std::string &x) { return W(x.c_str()), (*this); }
    template <typename T1, typename T2>
    FORCE_INLINE IO &W(const std::pair<T1, T2> &x)
    {
        WS(x.first);
        W(x.second);
        return (*this);
    }
    FORCE_INLINE IO &WL() { return W('\n'), (*this); }
    template <typename T> FORCE_INLINE IO &WL(const T &x)
    {
        return W(x), W('\n'), (*this);
    }
    FORCE_INLINE IO &WS() { return W(space), (*this); }
    template <typename T> FORCE_INLINE IO &WS(const T &x)
    {
        return W(x), W(space), (*this);
    }
    template <typename T> FORCE_INLINE IO &WA(T *a, int n)
    {
        for (int i = 0; i < n; i++) WS(a[i]);
        WL();
        return (*this);
    }
    template <typename T, typename... Args>
    FORCE_INLINE IO &W(const T &x, const Args &...args)
    {
        W(x), W(space), W(args...);
        return (*this);
    }
    template <typename T, typename... Args>
    FORCE_INLINE IO &WS(const T &x, const Args &...args)
    {
        return W(x), W(space), W(args...), W(space), (*this);
    }
    template <typename... Args> FORCE_INLINE IO &WL(const Args &...args)
    {
        return W(args...), W('\n'), (*this);
    }
    template <typename T, typename... Args>
    FORCE_INLINE IO &WA(T *a, int n, Args... args)
    {
        for (int i = 0; i < n; i++) WA(a[i], args...);
        return (*this);
    }
    template <typename T>
    FORCE_INLINE typename std::enable_if<std::is_integral<T>::value, IO>::type &
        W(const T &x)
    {
        return __WI(x), (*this);
    }
    template <typename T>
    FORCE_INLINE typename std::enable_if<is_container<T>::value, IO>::type &W(
        const T &x)
    {

        for (auto &i : x) WS(i);
        WL();
        return (*this);
    }
    template <typename T>
    FORCE_INLINE typename std::enable_if<
        std::is_void<std::void_t<decltype(std::declval<T>().write())>>::value,
        IO>::type &
        W(const T &x)
    {
        return x.write(), (*this);
    }
    template <typename T> FORCE_INLINE IO &operator>>(T &x)
    {
        R(x);
        return (*this);
    }
    template <typename T> FORCE_INLINE IO &operator<<(const T &x)
    {
        W(x);
        return (*this);
    }
    int good() { return goodReadBit; }
    IO() {}
    ~IO() { flush(); }
} io;







const std::int32_t INF = 0x3f3f3f3f;
const std::int64_t INFL = 0x3f3f3f3f3f3f3f3f;


template <class T, int... Ns> struct BIT
{
    T val = 0;
    void upd(T v) { val += v; }
    T query() { return val; }
};
template <typename T, int N, int... Ns> struct BIT<T, N, Ns...>
{
    BIT<T, Ns...> bit[N + 1];
    template <typename... Args> void upd(int pos, Args... args)
    {
        for (; pos; pos -= (pos & -pos)) bit[pos].upd(args...);
    }
    template <typename... Args> T sum(int r, Args... args)
    {
        T res = 0;
        for (; r <= N; r += (r & -r)) res += bit[r].query(args...);
        return res;
    }
    template <typename... Args> T query(int l, int r, Args... args)
    {
        return sum(r, args...) - sum(l - 1, args...);
    }
};
namespace Math
{
template <typename T, typename T2> T qpow(T a, T2 b, const int &MOD)
{
    T ans = 1;
    for (; b; b >>= 1) {
        if (b & 1) ans = (a * ans) % MOD;
        a = (a * a) % MOD;
    }
    return ans;
}
template <typename T> T id0(T l, T r, T &x, T &y)
{
    if (!r) {
        x = 1, y = 0;
        return l;
    } else {
        int d = id0(r, l % r, y, x);
        y -= l / r * x;
        return d;
    }
}
template <typename T> T inv(T a, const int &MOD)
{
    return qpow(a, MOD - 2, MOD);
}
template <typename T> T exinv(T a, const int &MOD)
{
    T x, y;
    id0(a, MOD, x, y);
    x %= MOD;
    return x + ((x >> (sizeof(T) * 8 - 1)) & MOD);
}


template <typename T, T MOD> struct ModInt
{
    T x;
    ModInt(T x = 0)
        : x(x)
    {
        while (x < 0) x += MOD;
    }
    ModInt<T, MOD> operator+=(const ModInt<T, MOD> &y)
    {
        x += y.x - MOD;
        x += (x >> (sizeof(T) * 8 - 1)) & MOD;
        return (*this);
    }
    ModInt<T, MOD> operator-=(const ModInt<T, MOD> &y)
    {
        x = x - y.x;
        x += (x >> (sizeof(T) * 8 - 1)) & MOD;
        return (*this);
    }
    ModInt<T, MOD> operator*=(const ModInt<T, MOD> &y)
    {
        x = x * y.x % MOD;
        return (*this);
    }
    ModInt<T, MOD> operator/=(const ModInt<T, MOD> &y)
    {
        x = x * inv(y.x, MOD) % MOD;
        return (*this);
    }
    ModInt<T, MOD> pow(int64_t p) { return x = qpow(x, p, MOD), *this; }
    void write() const { io.W(x); }
};
template <typename T, T MOD>
ModInt<T, MOD> operator+(ModInt<T, MOD> a, const ModInt<T, MOD> &b)
{
    a += b;
    return a;
}
template <typename T, T MOD>
ModInt<T, MOD> operator-(ModInt<T, MOD> a, const ModInt<T, MOD> &b)
{
    a -= b;
    return a;
}
template <typename T, T MOD>
ModInt<T, MOD> operator*(ModInt<T, MOD> a, const ModInt<T, MOD> &b)
{
    a *= b;
    return a;
}
template <typename T, T MOD>
ModInt<T, MOD> operator/(ModInt<T, MOD> a, const ModInt<T, MOD> &b)
{
    a /= b;
    return a;
}
template <typename T, T MOD>
bool operator==(const ModInt<T, MOD> &a, const ModInt<T, MOD> &b)
{
    return a.x == b.x;
}
}
using mint = Math::ModInt<int64_t, int(1e9 + 7)>;
const int MAXN = 5e5;
using namespace std;
BIT<mint, MAXN> bit;
int main()
{
    int n;
    io >> n;
    vector<pair<int, int>> a(n);
    io >> a;
    vector<int> b(n);
    for (int i = 0; i < n; i++) {
        swap(a[i].first, a[i].second);
        b[i] = a[i].first;
    }
    sort(ALL(a));
    int m;
    io >> m;
    vector<int> v(m);
    io >> v;
    vector<int> x(n);
    for (auto i : v) {
        x[lower_bound(ALL(a), pair{ b[i - 1], 0 }) - a.begin()] = 1;
    }
    vector<mint> dp(n);
    bit.upd(2 * n, 1);
    for (int i = 0; i < n; i++) {
        bit.upd(a[i].second, dp[i] = bit.sum(a[i].second));
    }
    int p = 1;
    mint ans = 0;
    for (int i = n - 1; i >= 0; i--) {
        bit.upd(a[i].second, mint(0) - dp[i]);
        if (x[i] && a[i].second >= p) {
            ans += bit.sum(p);
            p = a[i].second;
        }
    }
    io.WL(ans);
    return 0;
}