




#ifndef TYPE_HPP
#define TYPE_HPP
#include <type_traits>
template <typename T, typename _ = void> struct is_container : std::false_type
{};
#ifndef __cpp_lib_void_t
namespace std
{
template <typename...> using void_t = void;
}
#endif
template <typename T>
struct is_container<T,
    std::conditional_t<false,
        std::void_t<decltype(std::declval<T>().size()),
            decltype(std::declval<T>().begin()),
            decltype(std::declval<T>().end())>,
        void> > : public std::true_type
{};
#endif
#include <bits/stdc++.h>
#define FORCE_INLINE __inline__ __attribute__((always_inline))
class IO
{
    static const int bufSize = 1 << 18;

    char inBuf[bufSize], outBuf[bufSize];
    char *ip1 = inBuf, *ip2 = inBuf;

    int goodReadBit = 1, op1 = -1, op2 = bufSize - 1;

    FORCE_INLINE int gc()
    {
        return ip1 == ip2
                && (ip2 = (ip1 = inBuf) + fread(inBuf, 1, bufSize, stdin),
                    ip1 == ip2)
            ? EOF
            : *ip1++;
    }
    template <typename T> FORCE_INLINE void __RI(T &x)
    {
        int ch = gc(), neg = 1;
        x = 0;
        for (; !(isdigit(ch) || ch == '-'); ch = gc())
            ;
        if (ch == EOF) {
            goodReadBit = 0;
            return;
        }
        if (ch == '-') neg = -1, ch = gc();
        for (; isdigit(ch); ch = gc()) x = x * 10 + (ch - 48) * neg;
    }
    template <typename T> FORCE_INLINE void __RC(T &x)
    {
        int ch;
        while (isspace(ch = gc()))
            ;
        if (ch == EOF) {
            goodReadBit = 0;
            return;
        }
        x = ch;
    }
    FORCE_INLINE void __RS(std::string &x)
    {
        char ch;
        x.clear();
        for (ch = gc(); isspace(ch); ch = gc())
            ;
        if (ch == EOF) {
            goodReadBit = 0;
            return;
        }
        for (; !isspace(ch) && ch != EOF; ch = gc()) x.push_back(ch);
    }

public:
    

    

    FORCE_INLINE IO &R(char &x) { return __RC(x), (*this); }
    FORCE_INLINE IO &R(unsigned char &x) { return __RC(x), (*this); }
    

    FORCE_INLINE IO &R(std::string &x) { return __RS(x), (*this); }
    

    template <typename T1, typename T2> FORCE_INLINE IO &R(std::pair<T1, T2> &x)
    {
        R(x.first);
        R(x.second);
        return (*this);
    }
    template <typename T, typename... Args> FORCE_INLINE IO &RA(T *a, int n)
    {
        for (int i = 0; i < n; ++i) R(a[i]);
        return (*this);
    }
    template <typename T, typename... Args>
    FORCE_INLINE IO &R(T &x, Args &...args)
    {
        R(x), R(args...);
        return (*this);
    }
    template <typename T, typename... Args>
    FORCE_INLINE IO &RA(T *a, int n, Args... args)
    {
        for (int i = 0; i < n; ++i) RA(a[i], args...);
        return (*this);
    }
    template <typename T> FORCE_INLINE IO &R(T &x)
    {
        static_assert(std::is_integral<T>::value || is_container<T>::value,
            "Unsupported types");
        if constexpr (std::is_integral<T>::value) __RI(x);
        if constexpr (is_container<T>::value) {
            for (auto &i : x) R(i);
        }
        return (*this);
    }

private:
    

    char space;
    FORCE_INLINE void pc(const char &x)
    {
        if (op1 == op2) flush();
        outBuf[++op1] = x;
    }
    template <typename T> FORCE_INLINE void __WI(T x)
    {
        static char buf[64];
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
        W(x), W(space), W(args...), W(space);
        return (*this);
    }
    template <typename... Args> FORCE_INLINE IO &WL(const Args &...args)
    {
        W(args...), W('\n');
        return (*this);
    }
    template <typename T, typename... Args>
    FORCE_INLINE IO &WA(T *a, int n, Args... args)
    {
        for (int i = 0; i < n; i++) WA(a[i], args...);
        return (*this);
    }
    template <typename T> FORCE_INLINE IO &W(const T &x)
    {
        static_assert(std::is_integral<T>::value || is_container<T>::value,
            "Unsupported types");
        if constexpr (std::is_integral<T>::value) __WI(x);
        if constexpr (is_container<T>::value) {
            for (auto &i : x) WS(i);
            WL();
        }
        return (*this);
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
    IO() { space = ' '; }
    ~IO() { flush(); }
} io;
#undef FORCE_INLINE

#ifndef UTIL_HPP
#define UTIL_HPP
#include <bits/stdc++.h>
#define var auto
#define ALL(x) x.begin(), x.end()
const std::int32_t INF = 0x3f3f3f3f;
const std::int64_t INFL = 0x3f3f3f3f3f3f3f3f;
#endif
#include <bits/stdc++.h>
namespace Math
{
const int MOD = 998244353;
template <typename T, typename T2> inline T qpow(T a, T2 b, const int &MOD)
{
    T ans = 1;
    for (; b; b >>= 1) {
        if (b & 1) ans = (a * ans) % MOD;
        a = (a * a) % MOD;
    }
    return ans;
}
template <typename T> inline T exgcd(T l, T r, T &x, T &y)
{
    if (!r) {
        x = 1, y = 0;
        return l;
    } else {
        int d = exgcd(r, l % r, y, x);
        y -= l / r * x;
        return d;
    }
}
template <typename T> inline T inv(T a, const int &MOD)
{
    return qpow(a, MOD - 2, MOD);
}
template <typename T> inline T exinv(T a, const int &MOD)
{
    T x, y;
    exgcd(a, MOD, x, y);
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
using mint = Math::ModInt<int64_t, int64_t(1e9 + 7)>;
using namespace std;
void solve()
{
    int n;
    io >> n;
    vector<int> a(n);
    io >> a;
    vector<int64_t> pre(n + 1);
    for (int i = 0; i < n; i++) { pre[i + 1] = pre[i] + a[i]; }
    mint ans = 1;
    unordered_map<int64_t, mint> dp;
    dp[0] = 1;
    for (int i = 1; i < n; i++) {
        tie(ans, dp[pre[i]]) = make_tuple(ans + ans - dp[pre[i]], ans);
    }
    io.WL(ans.x);
}
int main()
{
    int T;
    io >> T;
    while (T--) solve();
    return 0;
}