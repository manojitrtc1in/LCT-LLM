







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







const std::int32_t INF = 0x3f3f3f3f;
const std::int64_t INFL = 0x3f3f3f3f3f3f3f3f;



using namespace std;
const int MAXN = 3e5;
vector<int> G[MAXN], ans;
vector<pair<int, int>> queries[MAXN];
struct State
{

    int x; 

    int y; 

    int m_ratio;
    State(int x = 0, int y = 1) : x(x), y(y) { m_ratio = y / x; }
    int ratio() { return m_ratio; }
    State &operator+=(const State &o)
    {
        x += o.x;
        y += o.y;
        m_ratio = y / x;
        return (*this);
    }
};
vector<State> dp[MAXN];
void dfs(int u, int p)
{
    for (auto v : G[u]) {
        if (v == p) continue;
        dfs(v, u);
        vector<State> t;
        swap(t, dp[u]);
        for (int i = 0, j = 0; i < t.size() || j < dp[v].size();) {
            if (j == dp[v].size()
                || (i < t.size() && t[i].ratio() <= dp[v][j].ratio()))
                dp[u].push_back(t[i++]);
            else if (i && dp[u].back().ratio() == dp[v][j].ratio())
                dp[u].back() += dp[v][j++];
            else
                dp[u].push_back(dp[v][j++]);
        }
    }
    for (auto [k, i] : queries[u]) {
        State res{ 0, 0 };
        for (auto i : dp[u])
            if (i.ratio() >= k) res += i;
        ans[i] = res.y + G[u].size() - (!!u) - k * res.x;
    }
    State s{ 1, G[u].size() - (!!u) - 1 };
    while (dp[u].size() && s.ratio() <= dp[u].back().ratio())
        s += dp[u].back(), dp[u].pop_back();
    if (s.y > 0) dp[u].push_back(s);
}
int main()
{
    int n;
    io >> n;
    for (int i = 1; i < n; i++) {
        int x, y;
        io >> x >> y;
        --x, --y;
        G[x].push_back(y);
        G[y].push_back(x);
    }
    int q;
    io >> q;
    ans.resize(q);
    for (int i = 0; i < q; i++) {
        int x, y;
        io.R(x, y);
        --x;
        queries[x].emplace_back(y, i);
    }
    dfs(0, 0);
    for (auto i : ans) io.WL(i);
    return 0;
}