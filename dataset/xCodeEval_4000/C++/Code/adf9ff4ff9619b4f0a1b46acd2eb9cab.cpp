




#ifndef MULTIVECTOR_HPP
#define MULTIVECTOR_HPP
#include <vector>
template <typename T, int Dimension>
struct MultiVector : public std::vector<MultiVector<T, Dimension - 1>>
{
    MultiVector(std::size_t n = 0)
        : std::vector<MultiVector<T, Dimension - 1>>(
            n, MultiVector<T, Dimension - 1>())
    {}
    template <typename... Args>
    MultiVector(std::size_t n, const Args &...args)
        : std::vector<MultiVector<T, Dimension - 1>>(
            n, MultiVector<T, Dimension - 1>(args...))
    {}
    template <typename... Args> void resize(std::size_t n, const Args &...args)
    {
        std::vector<MultiVector<T, Dimension - 1>>::resize(n);
        for (auto &i : (*this)) i.resize(args...);
    }
    void resize() {}
    template <typename... Args> void assign(std::size_t n, const Args &...args)
    {
        std::vector<MultiVector<T, Dimension - 1>>::resize(n);
        for (auto &i : (*this)) i.assign(args...);
    }
};
template <typename T> struct MultiVector<T, 1> : public std::vector<T>
{
    MultiVector(std::size_t n = 0)
        : std::vector<T>(n)
    {}
    MultiVector(std::size_t n, const T &x)
        : std::vector<T>(n, x)
    {}
    void resize(std::size_t n = 0) { std::vector<T>::resize(n); }
    void resize(std::size_t n, const T &x) { std::vector<T>::resize(n, x); }
};
#endif
#ifndef TYPE_HPP
#define TYPE_HPP
#include <type_traits>
#ifndef __cpp_lib_void_t
namespace std
{
template <typename...> using void_t = void;
}
#endif
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
#endif
#include <bits/stdc++.h>
#define FORCE_INLINE __inline__ __attribute__((always_inline))
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
        if (ch == EOF) [[unlikely]]
            return;
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
    const char space = ' ';
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
#undef FORCE_INLINE

#ifndef UTIL_HPP
#define UTIL_HPP
#include <bits/stdc++.h>
#define var auto
#define ALL(x) x.begin(), x.end()
const std::int32_t INF = 0x3f3f3f3f;
const std::int64_t INFL = 0x3f3f3f3f3f3f3f3f;
#define If(x, y, z) ((x) ? (y) : (z))
#define FILEIO(x)                                                              \
    do {                                                                       \
        freopen(#x ".in", "r", stdin);                                         \
        freopen(#x ".out", "w", stdout);                                       \
    } while (0)

#endif

using namespace std;
MultiVector<int, 3> pos;
MultiVector<string, 2> dp;
string f(int c, int mask)
{
    if (dp[c][mask] != "") return dp[c][mask];
    string &res = dp[c][mask];
    for (int x = 'A'; x <= 'Z'; x++) {
        int nmask = 0;
        bool ok = 1;
        for (int i = 0; i < pos.size(); i++) {
            if (pos[i][x].size() == 0) {
                ok = 0;
                break;
            }
            if (pos[i][c][!!(mask & (1 << i))] >= pos[i][x].back()) {
                ok = 0;
                break;
            }
            if (pos[i][c][!!(mask & (1 << i))] >= pos[i][x].front())
                nmask |= (1 << i);
        }
        if (ok) {
            auto t = f(x, nmask);
            if (t.size() > res.size()) res = t;
        }
    }
    for (int x = 'a'; x <= 'z'; x++) {
        int nmask = 0;
        bool ok = 1;
        for (int i = 0; i < pos.size(); i++) {
            if (pos[i][x].size() == 0) {
                ok = 0;
                break;
            }
            if (pos[i][c][!!(mask & (1 << i))] >= pos[i][x].back()) {
                ok = 0;
                break;
            }
            if (pos[i][c][!!(mask & (1 << i))] >= pos[i][x].front())
                nmask |= (1 << i);
        }
        if (ok) {
            auto t = f(x, nmask);
            if (t.size() > res.size()) res = t;
        }
    }
    res += c;
    return res;
}
void solve()
{
    int n;
    io >> n;
    vector<string> vs(n);
    io >> vs;
    pos.clear();
    pos.resize(n);
    for (int i = 0; i < n; i++) {
        pos[i].resize(128);
        for (int j = 0; j < vs[i].size(); j++) {
            pos[i][vs[i][j]].push_back(j);
        }
    }
    dp.clear();
    dp.resize(128, 1 << n);
    string ans;
    for (int j = 'A'; j <= 'Z'; j++) {
        bool ok = 1;
        for (int i = 0; i < n; i++)
            if (pos[i][j].size() == 0) ok = 0;
        if (ok) {
            auto res = f(j, 0);
            if (res.size() > ans.size()) ans = res;
        }
        

    }
    for (int j = 'a'; j <= 'z'; j++) {
        bool ok = 1;
        for (int i = 0; i < n; i++)
            if (pos[i][j].size() == 0) ok = 0;
        if (ok) {
            auto res = f(j, 0);
            if (res.size() > ans.size()) ans = res;
        }
        

    }
    reverse(ALL(ans));
    io.WL(ans.size()).WL(ans);
}
int main()
{
    int T;
    io >> T;
    while (T--) solve();
    return 0;
}