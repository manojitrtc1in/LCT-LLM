
















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

    

    explicit barrett(unsigned int m) : _m(m), im((unsigned long long)(-1) / m + 1) {}

    

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







constexpr long long id8(long long x, long long n, int m) {
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
        long long y = id8(a, t, n);
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





constexpr std::pair<long long, long long> id5(long long a, long long b) {
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







constexpr int id6(int m) {
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
            if (id8(g, (m - 1) / divs[i], m) == 1) {
                ok = false;
                break;
            }
        }
        if (ok) return g;
    }
}
template <int m> constexpr int primitive_root = id6(m);







unsigned long long id3(unsigned long long n,
                                      unsigned long long m,
                                      unsigned long long a,
                                      unsigned long long b) {
    unsigned long long ans = 0;
    while (true) {
        if (a >= m) {
            ans += n * (n - 1) / 2 * (a / m);
            a %= m;
        }
        if (b >= m) {
            ans += n * (b / m);
            b %= m;
        }

        unsigned long long y_max = a * n + b;
        if (y_max < m) break;
        

        

        n = (unsigned long long)(y_max / m);
        b = (unsigned long long)(y_max % m);
        std::swap(m, a);
    }
    return ans;
}

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


namespace atcoder {

namespace internal {

struct modint_base {};
struct static_modint_base : modint_base {};

template <class T> using is_modint = std::is_base_of<modint_base, T>;
template <class T> using is_modint_t = std::enable_if_t<is_modint<T>::value>;

}  


template <int m, std::enable_if_t<(1 <= m)>* = nullptr>
struct id1 : internal::static_modint_base {
    using mint = id1;

  public:
    static constexpr int mod() { return m; }
    static mint raw(int v) {
        mint x;
        x._v = v;
        return x;
    }

    id1() : _v(0) {}
    template <class T, internal::is_signed_int_t<T>* = nullptr>
    id1(T v) {
        long long x = (long long)(v % (long long)(umod()));
        if (x < 0) x += umod();
        _v = (unsigned int)(x);
    }
    template <class T, internal::is_unsigned_int_t<T>* = nullptr>
    id1(T v) {
        _v = (unsigned int)(v % umod());
    }

    unsigned int val() const { return _v; }

    mint& operator++() {
        _v++;
        if (_v == umod()) _v = 0;
        return *this;
    }
    mint& operator--() {
        if (_v == 0) _v = umod();
        _v--;
        return *this;
    }
    mint operator++(int) {
        mint result = *this;
        ++*this;
        return result;
    }
    mint operator--(int) {
        mint result = *this;
        --*this;
        return result;
    }

    mint& operator+=(const mint& rhs) {
        _v += rhs._v;
        if (_v >= umod()) _v -= umod();
        return *this;
    }
    mint& operator-=(const mint& rhs) {
        _v -= rhs._v;
        if (_v >= umod()) _v += umod();
        return *this;
    }
    mint& operator*=(const mint& rhs) {
        unsigned long long z = _v;
        z *= rhs._v;
        _v = (unsigned int)(z % umod());
        return *this;
    }
    mint& operator/=(const mint& rhs) { return *this = *this * rhs.inv(); }

    mint operator+() const { return *this; }
    mint operator-() const { return mint() - *this; }

    mint pow(long long n) const {
        assert(0 <= n);
        mint x = *this, r = 1;
        while (n) {
            if (n & 1) r *= x;
            x *= x;
            n >>= 1;
        }
        return r;
    }
    mint inv() const {
        if (prime) {
            assert(_v);
            return pow(umod() - 2);
        } else {
            auto eg = internal::id5(_v, m);
            assert(eg.first == 1);
            return eg.second;
        }
    }

    friend mint operator+(const mint& lhs, const mint& rhs) {
        return mint(lhs) += rhs;
    }
    friend mint operator-(const mint& lhs, const mint& rhs) {
        return mint(lhs) -= rhs;
    }
    friend mint operator*(const mint& lhs, const mint& rhs) {
        return mint(lhs) *= rhs;
    }
    friend mint operator/(const mint& lhs, const mint& rhs) {
        return mint(lhs) /= rhs;
    }
    friend bool operator==(const mint& lhs, const mint& rhs) {
        return lhs._v == rhs._v;
    }
    friend bool operator!=(const mint& lhs, const mint& rhs) {
        return lhs._v != rhs._v;
    }

  private:
    unsigned int _v;
    static constexpr unsigned int umod() { return m; }
    static constexpr bool prime = internal::is_prime<m>;
};

template <int id> struct id9 : internal::modint_base {
    using mint = id9;

  public:
    static int mod() { return (int)(bt.umod()); }
    static void set_mod(int m) {
        assert(1 <= m);
        bt = internal::barrett(m);
    }
    static mint raw(int v) {
        mint x;
        x._v = v;
        return x;
    }

    id9() : _v(0) {}
    template <class T, internal::is_signed_int_t<T>* = nullptr>
    id9(T v) {
        long long x = (long long)(v % (long long)(mod()));
        if (x < 0) x += mod();
        _v = (unsigned int)(x);
    }
    template <class T, internal::is_unsigned_int_t<T>* = nullptr>
    id9(T v) {
        _v = (unsigned int)(v % mod());
    }

    unsigned int val() const { return _v; }

    mint& operator++() {
        _v++;
        if (_v == umod()) _v = 0;
        return *this;
    }
    mint& operator--() {
        if (_v == 0) _v = umod();
        _v--;
        return *this;
    }
    mint operator++(int) {
        mint result = *this;
        ++*this;
        return result;
    }
    mint operator--(int) {
        mint result = *this;
        --*this;
        return result;
    }

    mint& operator+=(const mint& rhs) {
        _v += rhs._v;
        if (_v >= umod()) _v -= umod();
        return *this;
    }
    mint& operator-=(const mint& rhs) {
        _v += mod() - rhs._v;
        if (_v >= umod()) _v -= umod();
        return *this;
    }
    mint& operator*=(const mint& rhs) {
        _v = bt.mul(_v, rhs._v);
        return *this;
    }
    mint& operator/=(const mint& rhs) { return *this = *this * rhs.inv(); }

    mint operator+() const { return *this; }
    mint operator-() const { return mint() - *this; }

    mint pow(long long n) const {
        assert(0 <= n);
        mint x = *this, r = 1;
        while (n) {
            if (n & 1) r *= x;
            x *= x;
            n >>= 1;
        }
        return r;
    }
    mint inv() const {
        auto eg = internal::id5(_v, mod());
        assert(eg.first == 1);
        return eg.second;
    }

    friend mint operator+(const mint& lhs, const mint& rhs) {
        return mint(lhs) += rhs;
    }
    friend mint operator-(const mint& lhs, const mint& rhs) {
        return mint(lhs) -= rhs;
    }
    friend mint operator*(const mint& lhs, const mint& rhs) {
        return mint(lhs) *= rhs;
    }
    friend mint operator/(const mint& lhs, const mint& rhs) {
        return mint(lhs) /= rhs;
    }
    friend bool operator==(const mint& lhs, const mint& rhs) {
        return lhs._v == rhs._v;
    }
    friend bool operator!=(const mint& lhs, const mint& rhs) {
        return lhs._v != rhs._v;
    }

  private:
    unsigned int _v;
    static internal::barrett bt;
    static unsigned int umod() { return bt.umod(); }
};
template <int id> internal::barrett id9<id>::bt(998244353);

using modint998244353 = id1<998244353>;
using modint1000000007 = id1<1000000007>;
using modint = id9<-1>;

namespace internal {

template <class T>
using is_static_modint = std::is_base_of<internal::static_modint_base, T>;

template <class T>
using is_static_modint_t = std::enable_if_t<is_static_modint<T>::value>;

template <class> struct is_dynamic_modint : public std::false_type {};
template <int id>
struct is_dynamic_modint<id9<id>> : public std::true_type {};

template <class T>
using is_dynamic_modint_t = std::enable_if_t<is_dynamic_modint<T>::value>;

}  


}  


using mint = atcoder::modint998244353;

std::istream& operator>>(std::istream& in, mint &a) {
    long long e; in >> e; a = e;
    return in;
}

std::ostream& operator<<(std::ostream& out, const mint &a) {
    out << a.val();
    return out;
}

constexpr int RED = 0;
constexpr int BLUE = 1;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int l, r, m;
    std::cin >> l >> r >> m;

    std::vector<int> p(l + r, -1);
    std::vector<mint> sum(l + r, 0);
    std::vector<mint> red_sum(l + r, 0);
    std::vector<int> col(l + r, -1);
    std::vector<std::deque<int>> path(l + r);

    std::vector<int> red_edges;

    auto id2 = [&](int i) -> bool { return p[i] >= 0; };

    mint ans = 0;

    auto add_edge = [&](int u, int v, int edge_id) {
        mint edge_hash = mint(2).pow(edge_id);
        if (id2(u) and id2(v)) {
            if (p[u] == v) {
                assert(p[v] == u);
                assert(col[u] == col[v]);
                int edge_color = col[u] ^ RED ^ BLUE;
                if (edge_color == RED) ans += edge_hash;

                if (path[u].empty()) {
                    path[v].push_back(edge_id);
                    int cur = col[v];
                    for (int e : path[v]) {
                        if (cur == RED) {
                            red_edges.push_back(e);
                            cur = BLUE;
                        } else {
                            cur = RED;
                        }
                    }
                } else {
                    path[u].push_back(edge_id);
                    int cur = col[u];
                    for (int e : path[u]) {
                        if (cur == RED) {
                            red_edges.push_back(e);
                            cur = BLUE;
                        } else {
                            cur = RED;
                        }
                    }
                }

                p[u] = p[v] = -1;
                sum[u] = sum[v] = 0;
                red_sum[u] = red_sum[v] = 0;
                col[u] = col[v] = -1;
                path[u] = {};
                path[v] = {};
            } else {
                if (col[u] != col[v]) {
                    ans -= red_sum[v];
                    red_sum[p[v]] = red_sum[v] = sum[v] - red_sum[v];
                    ans += red_sum[v];
                    col[v] = col[v] ^ RED ^ BLUE;
                    col[p[v]] = col[p[v]] ^ RED ^ BLUE;
                }
                int edge_color = col[u] ^ RED ^ BLUE;
                if (edge_color == RED) ans += edge_hash;
                mint id0 = sum[u] + sum[v] + edge_hash;
                mint id7 = red_sum[u] + red_sum[v] + (edge_color == RED ? edge_hash : 0);

                p[p[u]] = p[v], p[p[v]] = p[u];
                sum[p[u]] = sum[p[v]] = id0;
                red_sum[p[u]] = red_sum[p[v]] = id7;

                if (path[u].empty() and path[v].empty()) {
                    if (path[p[u]].size() > path[p[v]].size()) {
                        path[p[u]].push_back(edge_id);
                        for (auto it = path[p[v]].rbegin(); it != path[p[v]].rend(); ++it) {
                            path[p[u]].push_back(*it);
                        }
                        path[p[v]].clear();
                    } else {
                        path[p[v]].push_back(edge_id);
                        for (auto it = path[p[u]].rbegin(); it != path[p[u]].rend(); ++it) {
                            path[p[v]].push_back(*it);
                        }
                        path[p[u]].clear();
                    }
                } else if (path[u].empty()) {
                    if (path[p[u]].size() > path[v].size()) {
                        path[p[u]].push_back(edge_id);
                        for (int id : path[v]) path[p[u]].push_back(id);
                    } else {
                        path[v].push_front(edge_id);
                        for (auto it = path[p[u]].rbegin(); it != path[p[u]].rend(); ++it) {
                            path[v].push_front(*it);
                        }
                        path[p[u]] = std::move(path[v]);
                    }
                } else if (path[v].empty()) {
                    if (path[p[v]].size() > path[u].size()) {
                        path[p[v]].push_back(edge_id);
                        for (int id : path[u]) path[p[v]].push_back(id);
                    } else {
                        path[u].push_front(edge_id);
                        for (auto it = path[p[v]].rbegin(); it != path[p[v]].rend(); ++it) {
                            path[u].push_front(*it);
                        }
                        path[p[v]] = std::move(path[u]);
                    }
                } else {
                    if (path[u].size() > path[v].size()) {
                        path[u].push_front(edge_id);
                        for (auto it = path[v].begin(); it != path[v].end(); ++it) {
                            path[u].push_front(*it);
                        }
                        path[p[v]] = std::move(path[u]);
                    } else {
                        path[v].push_front(edge_id);
                        for (auto it = path[u].begin(); it != path[u].end(); ++it) {
                            path[v].push_front(*it);
                        }
                        path[p[u]] = std::move(path[v]);
                    }
                }

                p[u] = p[v] = -1;
                sum[u] = sum[v] = 0;
                red_sum[u] = red_sum[v] = 0;
                col[u] = col[v] = -1;
                path[u] = {};
                path[v] = {};
            }
        } else if (id2(u) or id2(v)) {
            if (id2(u)) std::swap(u, v);

            int edge_color = col[v] ^ RED ^ BLUE;
            if (edge_color == RED) ans += edge_hash;

            p[p[v]] = u, p[u] = p[v];
            mint id0 = sum[v] + edge_hash;
            mint id7 = red_sum[v] + (edge_color == RED ? edge_hash : 0);

            sum[p[v]] = sum[u] = id0;
            red_sum[p[v]] = red_sum[u] = id7;
            col[u] = edge_color;

            if (path[v].empty()) {
                path[p[v]].push_back(edge_id);
            } else {
                path[u] = std::move(path[v]);
                path[u].push_front(edge_id);
                path[v] = {};
            }

            p[v] = -1;
            sum[v] = red_sum[v] = 0;
            col[v] = -1;
        } else {
            

            p[u] = v, p[v] = u;
            sum[u] = sum[v] = edge_hash;
            red_sum[u] = red_sum[v] = edge_hash;
            col[u] = col[v] = RED;
            path[u] = { edge_id };

            ans += edge_hash;
        }
    };

    int edge_id = 1;
    for (int i = 0; i < m; ++i) {
        int u, v;
        std::cin >> u >> v;
        --u, --v;
        add_edge(u, v + l, edge_id++);
    }

    int q;
    std::cin >> q;
    while (q --> 0) {
        int qt;
        std::cin >> qt;
        if (qt == 1) {
            int u, v;
            std::cin >> u >> v;
            --u, --v;
            add_edge(u, v + l, edge_id++);
            std::cout << ans.val() << '\n';
        } else {
            std::vector<int> res;
            for (int e : red_edges) res.push_back(e);
            for (int i = 0; i < l + r; ++i) {
                int cur = col[i];
                for (int e : path[i]) {
                    if (cur == RED) {
                        res.push_back(e);
                        cur = BLUE;
                    } else {
                        cur = RED;
                    }
                }
            }
            std::cout << res.size();
            for (int e : res) std::cout << ' ' << e;
            std::cout << '\n';
        }
        std::cout.flush();
    }
    return 0;
}

