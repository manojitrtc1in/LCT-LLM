





namespace atcoder {

namespace internal {

template <class T> struct simple_queue {
    std::vector<T> payload;
    int pos = 0;
    void reserve(int n) { payload.reserve(n); }
    int size() const { return int(payload.size()) - pos; }
    bool empty() const { return pos == int(payload.size()); }
    void push(const T& t) { payload.push_back(t); }
    T& front() { return payload[pos]; }
    void clear() {
        payload.clear();
        pos = 0;
    }
    void pop() { pos++; }
};

}  


}  







namespace atcoder {

template <class Cap> struct mf_graph {
  public:
    mf_graph() : _n(0) {}
    mf_graph(int n) : _n(n), g(n) {}

    int add_edge(int from, int to, Cap cap) {
        assert(0 <= from && from < _n);
        assert(0 <= to && to < _n);
        assert(0 <= cap);
        int m = int(pos.size());
        pos.push_back({from, int(g[from].size())});
        int from_id = int(g[from].size());
        int to_id = int(g[to].size());
        if (from == to) to_id++;
        g[from].push_back(_edge{to, to_id, cap});
        g[to].push_back(_edge{from, from_id, 0});
        return m;
    }

    struct edge {
        int from, to;
        Cap cap, flow;
    };

    edge get_edge(int i) {
        int m = int(pos.size());
        assert(0 <= i && i < m);
        auto _e = g[pos[i].first][pos[i].second];
        auto _re = g[_e.to][_e.rev];
        return edge{pos[i].first, _e.to, _e.cap + _re.cap, _re.cap};
    }
    std::vector<edge> edges() {
        int m = int(pos.size());
        std::vector<edge> result;
        for (int i = 0; i < m; i++) {
            result.push_back(get_edge(i));
        }
        return result;
    }
    void change_edge(int i, Cap new_cap, Cap new_flow) {
        int m = int(pos.size());
        assert(0 <= i && i < m);
        assert(0 <= new_flow && new_flow <= new_cap);
        auto& _e = g[pos[i].first][pos[i].second];
        auto& _re = g[_e.to][_e.rev];
        _e.cap = new_cap - new_flow;
        _re.cap = new_flow;
    }

    Cap flow(int s, int t) {
        return flow(s, t, std::numeric_limits<Cap>::max());
    }
    Cap flow(int s, int t, Cap flow_limit) {
        assert(0 <= s && s < _n);
        assert(0 <= t && t < _n);
        assert(s != t);

        std::vector<int> level(_n), iter(_n);
        internal::simple_queue<int> que;

        auto bfs = [&]() {
            std::fill(level.begin(), level.end(), -1);
            level[s] = 0;
            que.clear();
            que.push(s);
            while (!que.empty()) {
                int v = que.front();
                que.pop();
                for (auto e : g[v]) {
                    if (e.cap == 0 || level[e.to] >= 0) continue;
                    level[e.to] = level[v] + 1;
                    if (e.to == t) return;
                    que.push(e.to);
                }
            }
        };
        auto dfs = [&](auto self, int v, Cap up) {
            if (v == s) return up;
            Cap res = 0;
            int level_v = level[v];
            for (int& i = iter[v]; i < int(g[v].size()); i++) {
                _edge& e = g[v][i];
                if (level_v <= level[e.to] || g[e.to][e.rev].cap == 0) continue;
                Cap d =
                    self(self, e.to, std::min(up - res, g[e.to][e.rev].cap));
                if (d <= 0) continue;
                g[v][i].cap += d;
                g[e.to][e.rev].cap -= d;
                res += d;
                if (res == up) break;
            }
            return res;
        };

        Cap flow = 0;
        while (flow < flow_limit) {
            bfs();
            if (level[t] == -1) break;
            std::fill(iter.begin(), iter.end(), 0);
            while (flow < flow_limit) {
                Cap f = dfs(dfs, t, flow_limit - flow);
                if (!f) break;
                flow += f;
            }
        }
        return flow;
    }

    std::vector<bool> min_cut(int s) {
        std::vector<bool> visited(_n);
        internal::simple_queue<int> que;
        que.push(s);
        while (!que.empty()) {
            int p = que.front();
            que.pop();
            visited[p] = true;
            for (auto e : g[p]) {
                if (e.cap && !visited[e.to]) {
                    visited[e.to] = true;
                    que.push(e.to);
                }
            }
        }
        return visited;
    }

  private:
    int _n;
    struct _edge {
        int to, rev;
        Cap cap;
    };
    std::vector<std::pair<int, int>> pos;
    std::vector<std::vector<_edge>> g;
};

}  






namespace atcoder {

namespace internal {





constexpr long long safe_mod(long long x, long long m) {
    x %= m;
    if (x < 0) x += m;
    return x;
}







struct barrett {
    unsigned int _m;
    unsigned long long im;

    

    barrett(unsigned int m) : _m(m), im((unsigned long long)(-1) / m + 1) {}

    

    unsigned int umod() const { return _m; }

    

    

    

    unsigned int mul(unsigned int a, unsigned int b) const {
        

        


        

        

        

        

        

        

        

        unsigned long long z = a;
        z *= b;

        unsigned long long x;
        _umul128(z, im, &x);

        unsigned long long x =
            (unsigned long long)(((unsigned __int128)(z)*im) >> 64);

        unsigned int v = (unsigned int)(z - x * _m);
        if (_m <= v) v += _m;
        return v;
    }
};







constexpr long long id5(long long x, long long n, int m) {
    if (m == 1) return 0;
    unsigned int _m = (unsigned int)(m);
    unsigned long long r = 1;
    unsigned long long y = safe_mod(x, m);
    while (n) {
        if (n & 1) r = (r * y) % _m;
        y = (y * y) % _m;
        n >>= 1;
    }
    return r;
}









constexpr bool id4(int n) {
    if (n <= 1) return false;
    if (n == 2 || n == 7 || n == 61) return true;
    if (n % 2 == 0) return false;
    long long d = n - 1;
    while (d % 2 == 0) d /= 2;
    constexpr long long bases[3] = {2, 7, 61};
    for (long long a : bases) {
        long long t = d;
        long long y = id5(a, t, n);
        while (t != n - 1 && y != 1 && y != n - 1) {
            y = y * y % n;
            t <<= 1;
        }
        if (y != n - 1 && t % 2 == 0) {
            return false;
        }
    }
    return true;
}
template <int n> constexpr bool is_prime = id4(n);





constexpr std::pair<long long, long long> id0(long long a, long long b) {
    a = safe_mod(a, b);
    if (a == 0) return {b, 0};

    

    

    

    

    long long s = b, t = a;
    long long m0 = 0, m1 = 1;

    while (t) {
        long long u = s / t;
        s -= t * u;
        m0 -= m1 * u;  


        

        

        

        


        auto tmp = s;
        s = t;
        t = tmp;
        tmp = m0;
        m0 = m1;
        m1 = tmp;
    }
    

    

    if (m0 < 0) m0 += b / s;
    return {s, m0};
}







constexpr int id1(int m) {
    if (m == 2) return 1;
    if (m == 167772161) return 3;
    if (m == 469762049) return 3;
    if (m == 754974721) return 11;
    if (m == 998244353) return 3;
    int divs[20] = {};
    divs[0] = 2;
    int cnt = 1;
    int x = (m - 1) / 2;
    while (x % 2 == 0) x /= 2;
    for (int i = 3; (long long)(i)*i <= x; i += 2) {
        if (x % i == 0) {
            divs[cnt++] = i;
            while (x % i == 0) {
                x /= i;
            }
        }
    }
    if (x > 1) {
        divs[cnt++] = x;
    }
    for (int g = 2;; g++) {
        bool ok = true;
        for (int i = 0; i < cnt; i++) {
            if (id5(g, (m - 1) / divs[i], m) == 1) {
                ok = false;
                break;
            }
        }
        if (ok) return g;
    }
}
template <int m> constexpr int primitive_root = id1(m);

}  


}  







namespace atcoder {

namespace internal {


template <class T>
using is_signed_int128 =
    typename std::conditional<std::is_same<T, __int128_t>::value ||
                                  std::is_same<T, __int128>::value,
                              std::true_type,
                              std::false_type>::type;

template <class T>
using is_unsigned_int128 =
    typename std::conditional<std::is_same<T, __uint128_t>::value ||
                                  std::is_same<T, unsigned __int128>::value,
                              std::true_type,
                              std::false_type>::type;

template <class T>
using make_unsigned_int128 =
    typename std::conditional<std::is_same<T, __int128_t>::value,
                              __uint128_t,
                              unsigned __int128>;

template <class T>
using is_integral = typename std::conditional<std::is_integral<T>::value ||
                                                  is_signed_int128<T>::value ||
                                                  is_unsigned_int128<T>::value,
                                              std::true_type,
                                              std::false_type>::type;

template <class T>
using is_signed_int = typename std::conditional<(is_integral<T>::value &&
                                                 std::is_signed<T>::value) ||
                                                    is_signed_int128<T>::value,
                                                std::true_type,
                                                std::false_type>::type;

template <class T>
using is_unsigned_int =
    typename std::conditional<(is_integral<T>::value &&
                               std::is_unsigned<T>::value) ||
                                  is_unsigned_int128<T>::value,
                              std::true_type,
                              std::false_type>::type;

template <class T>
using to_unsigned = typename std::conditional<
    is_signed_int128<T>::value,
    make_unsigned_int128<T>,
    typename std::conditional<std::is_signed<T>::value,
                              std::make_unsigned<T>,
                              std::common_type<T>>::type>::type;



template <class T> using is_integral = typename std::is_integral<T>;

template <class T>
using is_signed_int =
    typename std::conditional<is_integral<T>::value && std::is_signed<T>::value,
                              std::true_type,
                              std::false_type>::type;

template <class T>
using is_unsigned_int =
    typename std::conditional<is_integral<T>::value &&
                                  std::is_unsigned<T>::value,
                              std::true_type,
                              std::false_type>::type;

template <class T>
using to_unsigned = typename std::conditional<is_signed_int<T>::value,
                                              std::make_unsigned<T>,
                                              std::common_type<T>>::type;



template <class T>
using is_signed_int_t = std::enable_if_t<is_signed_int<T>::value>;

template <class T>
using is_unsigned_int_t = std::enable_if_t<is_unsigned_int<T>::value>;

template <class T> using to_unsigned_t = typename to_unsigned<T>::type;

}  


}  










namespace atcoder
{

    namespace internal
    {

        struct modint_base
        {
        };
        struct static_modint_base : modint_base
        {
        };

        template <class T>
        using is_modint = std::is_base_of<modint_base, T>;
        template <class T>
        using is_modint_t = std::enable_if_t<is_modint<T>::value>;

    } 


    template <int m, std::enable_if_t<(1 <= m)> * = nullptr>
    struct id3 : internal::static_modint_base
    {
        using mint = id3;

    public:
        static constexpr int mod() { return m; }
        static mint raw(int v)
        {
            mint x;
            x._v = v;
            return x;
        }

        id3() : _v(0) {}
        template <class T, internal::is_signed_int_t<T> * = nullptr>
        id3(T v)
        {
            long long x = (long long)(v % (long long)(umod()));
            if (x < 0)
                x += umod();
            _v = (unsigned int)(x);
        }
        template <class T, internal::is_unsigned_int_t<T> * = nullptr>
        id3(T v)
        {
            _v = (unsigned int)(v % umod());
        }
        id3(bool v) { _v = ((unsigned int)(v) % umod()); }

        unsigned int val() const { return _v; }

        mint &operator++()
        {
            _v++;
            if (_v == umod())
                _v = 0;
            return *this;
        }
        mint &operator--()
        {
            if (_v == 0)
                _v = umod();
            _v--;
            return *this;
        }
        mint operator++(int)
        {
            mint result = *this;
            ++*this;
            return result;
        }
        mint operator--(int)
        {
            mint result = *this;
            --*this;
            return result;
        }

        mint &operator+=(const mint &rhs)
        {
            _v += rhs._v;
            if (_v >= umod())
                _v -= umod();
            return *this;
        }
        mint &operator-=(const mint &rhs)
        {
            _v -= rhs._v;
            if (_v >= umod())
                _v += umod();
            return *this;
        }
        mint &operator*=(const mint &rhs)
        {
            unsigned long long z = _v;
            z *= rhs._v;
            _v = (unsigned int)(z % umod());
            return *this;
        }
        mint &operator/=(const mint &rhs) { return *this = *this * rhs.inv(); }

        mint operator+() const { return *this; }
        mint operator-() const { return mint() - *this; }

        mint pow(long long n) const
        {
            assert(0 <= n);
            mint x = *this, r = 1;
            while (n)
            {
                if (n & 1)
                    r *= x;
                x *= x;
                n >>= 1;
            }
            return r;
        }
        mint inv() const
        {
            if (prime)
            {
                assert(_v);
                return pow(umod() - 2);
            }
            else
            {
                auto eg = internal::id0(_v, m);
                assert(eg.first == 1);
                return eg.second;
            }
        }

        friend mint operator+(const mint &lhs, const mint &rhs)
        {
            return mint(lhs) += rhs;
        }
        friend mint operator-(const mint &lhs, const mint &rhs)
        {
            return mint(lhs) -= rhs;
        }
        friend mint operator*(const mint &lhs, const mint &rhs)
        {
            return mint(lhs) *= rhs;
        }
        friend mint operator/(const mint &lhs, const mint &rhs)
        {
            return mint(lhs) /= rhs;
        }
        friend bool operator==(const mint &lhs, const mint &rhs)
        {
            return lhs._v == rhs._v;
        }
        friend bool operator!=(const mint &lhs, const mint &rhs)
        {
            return lhs._v != rhs._v;
        }

    private:
        unsigned int _v;
        static constexpr unsigned int umod() { return m; }
        static constexpr bool prime = internal::is_prime<m>;
    };

    template <int id>
    struct id2 : internal::modint_base
    {
        using mint = id2;

    public:
        static int mod() { return (int)(bt.umod()); }
        static void set_mod(int m)
        {
            assert(1 <= m);
            bt = internal::barrett(m);
        }
        static mint raw(int v)
        {
            mint x;
            x._v = v;
            return x;
        }

        id2() : _v(0) {}
        template <class T, internal::is_signed_int_t<T> * = nullptr>
        id2(T v)
        {
            long long x = (long long)(v % (long long)(mod()));
            if (x < 0)
                x += mod();
            _v = (unsigned int)(x);
        }
        template <class T, internal::is_unsigned_int_t<T> * = nullptr>
        id2(T v)
        {
            _v = (unsigned int)(v % mod());
        }
        id2(bool v) { _v = ((unsigned int)(v) % mod()); }

        unsigned int val() const { return _v; }

        mint &operator++()
        {
            _v++;
            if (_v == umod())
                _v = 0;
            return *this;
        }
        mint &operator--()
        {
            if (_v == 0)
                _v = umod();
            _v--;
            return *this;
        }
        mint operator++(int)
        {
            mint result = *this;
            ++*this;
            return result;
        }
        mint operator--(int)
        {
            mint result = *this;
            --*this;
            return result;
        }

        mint &operator+=(const mint &rhs)
        {
            _v += rhs._v;
            if (_v >= umod())
                _v -= umod();
            return *this;
        }
        mint &operator-=(const mint &rhs)
        {
            _v += mod() - rhs._v;
            if (_v >= umod())
                _v -= umod();
            return *this;
        }
        mint &operator*=(const mint &rhs)
        {
            _v = bt.mul(_v, rhs._v);
            return *this;
        }
        mint &operator/=(const mint &rhs) { return *this = *this * rhs.inv(); }

        mint operator+() const { return *this; }
        mint operator-() const { return mint() - *this; }

        mint pow(long long n) const
        {
            assert(0 <= n);
            mint x = *this, r = 1;
            while (n)
            {
                if (n & 1)
                    r *= x;
                x *= x;
                n >>= 1;
            }
            return r;
        }
        mint inv() const
        {
            auto eg = internal::id0(_v, mod());
            assert(eg.first == 1);
            return eg.second;
        }

        friend mint operator+(const mint &lhs, const mint &rhs)
        {
            return mint(lhs) += rhs;
        }
        friend mint operator-(const mint &lhs, const mint &rhs)
        {
            return mint(lhs) -= rhs;
        }
        friend mint operator*(const mint &lhs, const mint &rhs)
        {
            return mint(lhs) *= rhs;
        }
        friend mint operator/(const mint &lhs, const mint &rhs)
        {
            return mint(lhs) /= rhs;
        }
        friend bool operator==(const mint &lhs, const mint &rhs)
        {
            return lhs._v == rhs._v;
        }
        friend bool operator!=(const mint &lhs, const mint &rhs)
        {
            return lhs._v != rhs._v;
        }

    private:
        unsigned int _v;
        static internal::barrett bt;
        static unsigned int umod() { return bt.umod(); }
    };
    template <int id>
    internal::barrett id2<id>::bt = 998244353;

    using modint998244353 = id3<998244353>;
    using modint1000000007 = id3<1000000007>;
    using modint = id2<-1>;

    namespace internal
    {

        template <class T>
        using is_static_modint = std::is_base_of<internal::static_modint_base, T>;

        template <class T>
        using is_static_modint_t = std::enable_if_t<is_static_modint<T>::value>;

        template <class>
        struct is_dynamic_modint : public std::false_type
        {
        };
        template <int id>
        struct is_dynamic_modint<id2<id>> : public std::true_type
        {
        };

        template <class T>
        using is_dynamic_modint_t = std::enable_if_t<is_dynamic_modint<T>::value>;

    } 


} 


using namespace std;
const uint64_t seed = std::chrono::system_clock::now().time_since_epoch().count();
mt19937_64 rnd(seed);
const int MOD = 998244353;
const char NL = '\n';


template <typename T>
ostream &operator<<(ostream &os, const vector<T> &v)
{
    os << "{";
    for (typename vector<T>::const_iterator vi = v.begin(); vi != v.end(); ++vi)
    {
        if (vi != v.begin())
            os << ", ";
        os << *vi;
    }
    os << "}";
    return os;
}
template <typename A, typename B>
ostream &operator<<(ostream &os, const vector<pair<A, B>> &v)
{
    os << "{";
    for (typename vector<pair<A, B>>::const_iterator vi = v.begin(); vi != v.end(); ++vi)
    {
        if (vi != v.begin())
            os << ", ";
        os << '(' << vi->first << " " << vi->second << ")";
    }
    os << "}";
    return os;
}

template <typename A, typename B>
ostream &operator<<(ostream &os, const pair<A, B> &p)
{
    os << '(' << p.first << ", " << p.second << ')';
    return os;
}

void dbg_out() { cerr << endl; }
template <typename Head, typename... Tail>
void dbg_out(Head H, Tail... T)
{
    cerr << ' ' << H;
    dbg_out(T...);
}




using LL = long long;

using mint = atcoder::modint1000000007;

void solve(int caseNum)
{
    int n, m;
    cin >> n >> m;
    vector<int> s(n), a(n);
    for (int i = 0; i < n; i++)
        cin >> s[i];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    vector<pair<int, int>> ee;
    atcoder::mf_graph<LL> g(n + 4);
    vector<int> de(n, 0);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;
        ee.push_back({u, v});
        g.add_edge(u, v, 1);
        g.add_edge(v, u, 1);
        de[u]++;
        de[v]++;
    }
    LL t1 = 0, t2 = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 1)
        {
            if ((a[i] - de[i]) % 2 != 0)
            {
                cout << "NO" << NL;
                return;
            }
            if (a[i] > 0)
            {
                g.add_edge(i, n + 1, a[i]);
                t1 += a[i];
            }
            else if (a[i] < 0)
            {
                g.add_edge(n, i, -a[i]);
                t2 += -a[i];
            }
        }
        else
        {
            g.add_edge(n + 2, i, m);
            g.add_edge(i, n + 3, m);
        }
    }

    LL f = g.flow(n, n + 1);
    LL f2 = g.flow(n + 2, n + 1);
    LL f3 = g.flow(n, n + 3);
    dbg(t1, t2, f, f2, f3);
    if (t1 != f + f2 || t2 != f + f3)
    {
        cout << "NO" << NL;
        return;
    }
    cout << "YES" << NL;
    vector<pair<int, int>> res;
    vector<vector<int>> gg(n);
    vector<int> st(m, -1);
    for (int i = 0; i < m; i++)
    {
        auto e1 = g.get_edge(i * 2), e2 = g.get_edge(i * 2 + 1);
        int f = e1.flow - e2.flow;
        if (f > 0)
        {
            st[i] = 0;
        }
        else if (f < 0)
        {
            st[i] = 1;
        }
        else
        {
            gg[ee[i].first].push_back(i);
            gg[ee[i].second].push_back(i);
        }
    }
    vector<int> pos(n, 0);
    vector<int> d(n, 0);
    queue<int> qq;
    for (int i = 0; i < m; i++)
    {
        if (st[i] != -1)
            continue;
        st[i] = 0;
        d[ee[i].first]--;
        d[ee[i].second]++;
        if (s[ee[i].first] == 1)
            qq.push(ee[i].first);
        if (s[ee[i].second] == 1)
            qq.push(ee[i].second);
        while (qq.size())
        {
            int p = qq.front();
            qq.pop();
            if (d[p] == 0)
                continue;
            else
            {
                while (st[gg[p][pos[p]]] != -1)
                    pos[p]++;
                int ei = gg[p][pos[p]];
                pos[p]++;
                if ((ee[ei].first == p && d[p] > 0) || (ee[ei].second == p && d[p] < 0))
                {
                    st[ei] = 0;
                    d[ee[ei].first]--;
                    d[ee[ei].second]++;
                }
                else
                {
                    st[ei] = 1;
                    d[ee[ei].first]++;
                    d[ee[ei].second]--;
                }

                if (s[ee[ei].first] == 1)
                    qq.push(ee[ei].first);
                if (s[ee[ei].second] == 1)
                    qq.push(ee[ei].second);
            }
        }
    }
    for (int i = 0; i < m; i++)
    {
        if (st[i] == 0)
            cout << ee[i].first + 1 << ' ' << ee[i].second + 1 << NL;
        else
            cout << ee[i].second + 1 << ' ' << ee[i].first + 1 << NL;
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(20);
    int T = 1;
    

    for (int i = 1; i <= T; i++)
    {
        solve(i);
    }
    cout.flush();
    return 0;
}
