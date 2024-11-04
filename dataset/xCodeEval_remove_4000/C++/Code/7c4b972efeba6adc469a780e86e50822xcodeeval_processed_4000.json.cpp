



using namespace std;
















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

constexpr long long id17(long long x, long long n, int m) {
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

constexpr bool id16(int n) {
    if (n <= 1) return false;
    if (n == 2 || n == 7 || n == 61) return true;
    if (n % 2 == 0) return false;
    long long d = n - 1;
    while (d % 2 == 0) d /= 2;
    constexpr long long bases[3] = {2, 7, 61};
    for (long long a : bases) {
        long long t = d;
        long long y = id17(a, t, n);
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
template <int n> constexpr bool is_prime = id16(n);

constexpr std::pair<long long, long long> id1(long long a, long long b) {
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

constexpr int id9(int m) {
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
            if (id17(g, (m - 1) / divs[i], m) == 1) {
                ok = false;
                break;
            }
        }
        if (ok) return g;
    }
}
template <int m> constexpr int primitive_root = id9(m);

unsigned long long id0(unsigned long long n,
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
struct id13 : internal::static_modint_base {
    using mint = id13;

  public:
    static constexpr int mod() { return m; }
    static mint raw(int v) {
        mint x;
        x._v = v;
        return x;
    }

    id13() : _v(0) {}
    template <class T, internal::is_signed_int_t<T>* = nullptr>
    id13(T v) {
        long long x = (long long)(v % (long long)(umod()));
        if (x < 0) x += umod();
        _v = (unsigned int)(x);
    }
    template <class T, internal::is_unsigned_int_t<T>* = nullptr>
    id13(T v) {
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
            auto eg = internal::id1(_v, m);
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

template <int id> struct id12 : internal::modint_base {
    using mint = id12;

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

    id12() : _v(0) {}
    template <class T, internal::is_signed_int_t<T>* = nullptr>
    id12(T v) {
        long long x = (long long)(v % (long long)(mod()));
        if (x < 0) x += mod();
        _v = (unsigned int)(x);
    }
    template <class T, internal::is_unsigned_int_t<T>* = nullptr>
    id12(T v) {
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
        auto eg = internal::id1(_v, mod());
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
template <int id> internal::barrett id12<id>::bt(998244353);

using modint998244353 = id13<998244353>;
using modint1000000007 = id13<1000000007>;
using modint = id12<-1>;

namespace internal {

template <class T>
using is_static_modint = std::is_base_of<internal::static_modint_base, T>;

template <class T>
using is_static_modint_t = std::enable_if_t<is_static_modint<T>::value>;

template <class> struct is_dynamic_modint : public std::false_type {};
template <int id>
struct is_dynamic_modint<id12<id>> : public std::true_type {};

template <class T>
using is_dynamic_modint_t = std::enable_if_t<is_dynamic_modint<T>::value>;

}  


}  

















namespace atcoder {
namespace internal {

template <class E> struct csr {
    std::vector<int> start;
    std::vector<E> elist;
    explicit csr(int n, const std::vector<std::pair<int, E>>& edges)
        : start(n + 1), elist(edges.size()) {
        for (auto e : edges) {
            start[e.first + 1]++;
        }
        for (int i = 1; i <= n; i++) {
            start[i] += start[i - 1];
        }
        auto counter = start;
        for (auto e : edges) {
            elist[counter[e.first]++] = e.second;
        }
    }
};

}  


}  



namespace atcoder {
namespace internal {

struct id11 {
  public:
    explicit id11(int n) : _n(n) {}

    int num_vertices() { return _n; }

    void add_edge(int from, int to) { edges.push_back({from, {to}}); }

    std::pair<int, std::vector<int>> scc_ids() {
        auto g = csr<edge>(_n, edges);
        int now_ord = 0, group_num = 0;
        std::vector<int> visited, low(_n), ord(_n, -1), ids(_n);
        visited.reserve(_n);
        auto dfs = [&](auto self, int v) -> void {
            low[v] = ord[v] = now_ord++;
            visited.push_back(v);
            for (int i = g.start[v]; i < g.start[v + 1]; i++) {
                auto to = g.elist[i].to;
                if (ord[to] == -1) {
                    self(self, to);
                    low[v] = std::min(low[v], low[to]);
                } else {
                    low[v] = std::min(low[v], ord[to]);
                }
            }
            if (low[v] == ord[v]) {
                while (true) {
                    int u = visited.back();
                    visited.pop_back();
                    ord[u] = _n;
                    ids[u] = group_num;
                    if (u == v) break;
                }
                group_num++;
            }
        };
        for (int i = 0; i < _n; i++) {
            if (ord[i] == -1) dfs(dfs, i);
        }
        for (auto& x : ids) {
            x = group_num - 1 - x;
        }
        return {group_num, ids};
    }

    std::vector<std::vector<int>> scc() {
        auto ids = scc_ids();
        int group_num = ids.first;
        std::vector<int> counts(group_num);
        for (auto x : ids.second) counts[x]++;
        std::vector<std::vector<int>> groups(ids.first);
        for (int i = 0; i < group_num; i++) {
            groups[i].reserve(counts[i]);
        }
        for (int i = 0; i < _n; i++) {
            groups[ids.second[i]].push_back(i);
        }
        return groups;
    }

  private:
    int _n;
    struct edge {
        int to;
    };
    std::vector<std::pair<int, edge>> edges;
};

}  


}  



namespace atcoder {

struct id11 {
  public:
    id11() : internal(0) {}
    explicit id11(int n) : internal(n) {}

    void add_edge(int from, int to) {
        int n = internal.num_vertices();
        assert(0 <= from && from < n);
        assert(0 <= to && to < n);
        internal.add_edge(from, to);
    }

    std::vector<std::vector<int>> scc() { return internal.scc(); }

  private:
    internal::id11 internal;
};

}  












namespace atcoder {

namespace internal {

int id4(int n) {
    int x = 0;
    while ((1U << x) < (unsigned int)(n)) x++;
    return x;
}

constexpr int id5(unsigned int n) {
    int x = 0;
    while (!(n & (1 << x))) x++;
    return x;
}

int bsf(unsigned int n) {

    unsigned long index;
    _BitScanForward(&index, n);
    return index;

    return __builtin_ctz(n);

}

}  


}  



namespace atcoder {

template <class S, S (*op)(S, S), S (*e)()> struct id14 {
  public:
    id14() : id14(0) {}
    explicit id14(int n) : id14(std::vector<S>(n, e())) {}
    explicit id14(const std::vector<S>& v) : _n(int(v.size())) {
        log = internal::id4(_n);
        size = 1 << log;
        d = std::vector<S>(2 * size, e());
        for (int i = 0; i < _n; i++) d[size + i] = v[i];
        for (int i = size - 1; i >= 1; i--) {
            update(i);
        }
    }

    void set(int p, S x) {
        assert(0 <= p && p < _n);
        p += size;
        d[p] = x;
        for (int i = 1; i <= log; i++) update(p >> i);
    }

    S get(int p) const {
        assert(0 <= p && p < _n);
        return d[p + size];
    }

    S prod(int l, int r) const {
        assert(0 <= l && l <= r && r <= _n);
        S sml = e(), smr = e();
        l += size;
        r += size;

        while (l < r) {
            if (l & 1) sml = op(sml, d[l++]);
            if (r & 1) smr = op(d[--r], smr);
            l >>= 1;
            r >>= 1;
        }
        return op(sml, smr);
    }

    S all_prod() const { return d[1]; }

    template <bool (*f)(S)> int max_right(int l) const {
        return max_right(l, [](S x) { return f(x); });
    }
    template <class F> int max_right(int l, F f) const {
        assert(0 <= l && l <= _n);
        assert(f(e()));
        if (l == _n) return _n;
        l += size;
        S sm = e();
        do {
            while (l % 2 == 0) l >>= 1;
            if (!f(op(sm, d[l]))) {
                while (l < size) {
                    l = (2 * l);
                    if (f(op(sm, d[l]))) {
                        sm = op(sm, d[l]);
                        l++;
                    }
                }
                return l - size;
            }
            sm = op(sm, d[l]);
            l++;
        } while ((l & -l) != l);
        return _n;
    }

    template <bool (*f)(S)> int min_left(int r) const {
        return min_left(r, [](S x) { return f(x); });
    }
    template <class F> int min_left(int r, F f) const {
        assert(0 <= r && r <= _n);
        assert(f(e()));
        if (r == 0) return 0;
        r += size;
        S sm = e();
        do {
            r--;
            while (r > 1 && (r % 2)) r >>= 1;
            if (!f(op(d[r], sm))) {
                while (r < size) {
                    r = (2 * r + 1);
                    if (f(op(d[r], sm))) {
                        sm = op(d[r], sm);
                        r--;
                    }
                }
                return r + 1 - size;
            }
            sm = op(d[r], sm);
        } while ((r & -r) != r);
        return 0;
    }

  private:
    int _n, size, log;
    std::vector<S> d;

    void update(int k) { d[k] = op(d[2 * k], d[2 * k + 1]); }
};

}  









namespace atcoder {

namespace internal {

std::vector<int> id15(const std::vector<int>& s) {
    int n = int(s.size());
    std::vector<int> sa(n);
    std::iota(sa.begin(), sa.end(), 0);
    std::sort(sa.begin(), sa.end(), [&](int l, int r) {
        if (l == r) return false;
        while (l < n && r < n) {
            if (s[l] != s[r]) return s[l] < s[r];
            l++;
            r++;
        }
        return l == n;
    });
    return sa;
}

std::vector<int> id10(const std::vector<int>& s) {
    int n = int(s.size());
    std::vector<int> sa(n), rnk = s, tmp(n);
    std::iota(sa.begin(), sa.end(), 0);
    for (int k = 1; k < n; k *= 2) {
        auto cmp = [&](int x, int y) {
            if (rnk[x] != rnk[y]) return rnk[x] < rnk[y];
            int rx = x + k < n ? rnk[x + k] : -1;
            int ry = y + k < n ? rnk[y + k] : -1;
            return rx < ry;
        };
        std::sort(sa.begin(), sa.end(), cmp);
        tmp[sa[0]] = 0;
        for (int i = 1; i < n; i++) {
            tmp[sa[i]] = tmp[sa[i - 1]] + (cmp(sa[i - 1], sa[i]) ? 1 : 0);
        }
        std::swap(tmp, rnk);
    }
    return sa;
}

template <int id2 = 10, int id6 = 40>
std::vector<int> sa_is(const std::vector<int>& s, int upper) {
    int n = int(s.size());
    if (n == 0) return {};
    if (n == 1) return {0};
    if (n == 2) {
        if (s[0] < s[1]) {
            return {0, 1};
        } else {
            return {1, 0};
        }
    }
    if (n < id2) {
        return id15(s);
    }
    if (n < id6) {
        return id10(s);
    }

    std::vector<int> sa(n);
    std::vector<bool> ls(n);
    for (int i = n - 2; i >= 0; i--) {
        ls[i] = (s[i] == s[i + 1]) ? ls[i + 1] : (s[i] < s[i + 1]);
    }
    std::vector<int> sum_l(upper + 1), sum_s(upper + 1);
    for (int i = 0; i < n; i++) {
        if (!ls[i]) {
            sum_s[s[i]]++;
        } else {
            sum_l[s[i] + 1]++;
        }
    }
    for (int i = 0; i <= upper; i++) {
        sum_s[i] += sum_l[i];
        if (i < upper) sum_l[i + 1] += sum_s[i];
    }

    auto induce = [&](const std::vector<int>& lms) {
        std::fill(sa.begin(), sa.end(), -1);
        std::vector<int> buf(upper + 1);
        std::copy(sum_s.begin(), sum_s.end(), buf.begin());
        for (auto d : lms) {
            if (d == n) continue;
            sa[buf[s[d]]++] = d;
        }
        std::copy(sum_l.begin(), sum_l.end(), buf.begin());
        sa[buf[s[n - 1]]++] = n - 1;
        for (int i = 0; i < n; i++) {
            int v = sa[i];
            if (v >= 1 && !ls[v - 1]) {
                sa[buf[s[v - 1]]++] = v - 1;
            }
        }
        std::copy(sum_l.begin(), sum_l.end(), buf.begin());
        for (int i = n - 1; i >= 0; i--) {
            int v = sa[i];
            if (v >= 1 && ls[v - 1]) {
                sa[--buf[s[v - 1] + 1]] = v - 1;
            }
        }
    };

    std::vector<int> id8(n + 1, -1);
    int m = 0;
    for (int i = 1; i < n; i++) {
        if (!ls[i - 1] && ls[i]) {
            id8[i] = m++;
        }
    }
    std::vector<int> lms;
    lms.reserve(m);
    for (int i = 1; i < n; i++) {
        if (!ls[i - 1] && ls[i]) {
            lms.push_back(i);
        }
    }

    induce(lms);

    if (m) {
        std::vector<int> id3;
        id3.reserve(m);
        for (int v : sa) {
            if (id8[v] != -1) id3.push_back(v);
        }
        std::vector<int> rec_s(m);
        int rec_upper = 0;
        rec_s[id8[id3[0]]] = 0;
        for (int i = 1; i < m; i++) {
            int l = id3[i - 1], r = id3[i];
            int end_l = (id8[l] + 1 < m) ? lms[id8[l] + 1] : n;
            int end_r = (id8[r] + 1 < m) ? lms[id8[r] + 1] : n;
            bool same = true;
            if (end_l - l != end_r - r) {
                same = false;
            } else {
                while (l < end_l) {
                    if (s[l] != s[r]) {
                        break;
                    }
                    l++;
                    r++;
                }
                if (l == n || s[l] != s[r]) same = false;
            }
            if (!same) rec_upper++;
            rec_s[id8[id3[i]]] = rec_upper;
        }

        auto rec_sa =
            sa_is<id2, id6>(rec_s, rec_upper);

        for (int i = 0; i < m; i++) {
            id3[i] = lms[rec_sa[i]];
        }
        induce(id3);
    }
    return sa;
}

}  


std::vector<int> suffix_array(const std::vector<int>& s, int upper) {
    assert(0 <= upper);
    for (int d : s) {
        assert(0 <= d && d <= upper);
    }
    auto sa = internal::sa_is(s, upper);
    return sa;
}

template <class T> std::vector<int> suffix_array(const std::vector<T>& s) {
    int n = int(s.size());
    std::vector<int> idx(n);
    iota(idx.begin(), idx.end(), 0);
    sort(idx.begin(), idx.end(), [&](int l, int r) { return s[l] < s[r]; });
    std::vector<int> s2(n);
    int now = 0;
    for (int i = 0; i < n; i++) {
        if (i && s[idx[i - 1]] != s[idx[i]]) now++;
        s2[idx[i]] = now;
    }
    return internal::sa_is(s2, now);
}

std::vector<int> suffix_array(const std::string& s) {
    int n = int(s.size());
    std::vector<int> s2(n);
    for (int i = 0; i < n; i++) {
        s2[i] = s[i];
    }
    return internal::sa_is(s2, 255);
}

template <class T>
std::vector<int> id7(const std::vector<T>& s,
                           const std::vector<int>& sa) {
    int n = int(s.size());
    assert(n >= 1);
    std::vector<int> rnk(n);
    for (int i = 0; i < n; i++) {
        rnk[sa[i]] = i;
    }
    std::vector<int> lcp(n - 1);
    int h = 0;
    for (int i = 0; i < n; i++) {
        if (h > 0) h--;
        if (rnk[i] == 0) continue;
        int j = sa[rnk[i] - 1];
        for (; j + h < n && i + h < n; h++) {
            if (s[j + h] != s[i + h]) break;
        }
        lcp[rnk[i] - 1] = h;
    }
    return lcp;
}

std::vector<int> id7(const std::string& s, const std::vector<int>& sa) {
    int n = int(s.size());
    std::vector<int> s2(n);
    for (int i = 0; i < n; i++) {
        s2[i] = s[i];
    }
    return id7(s2, sa);
}

template <class T> std::vector<int> z_algorithm(const std::vector<T>& s) {
    int n = int(s.size());
    if (n == 0) return {};
    std::vector<int> z(n);
    z[0] = 0;
    for (int i = 1, j = 0; i < n; i++) {
        int& k = z[i];
        k = (j + z[j] <= i) ? 0 : std::min(j + z[j] - i, z[i - j]);
        while (i + k < n && s[k] == s[i + k]) k++;
        if (j + z[j] < i + z[i]) j = i;
    }
    z[0] = n;
    return z;
}

std::vector<int> z_algorithm(const std::string& s) {
    int n = int(s.size());
    std::vector<int> s2(n);
    for (int i = 0; i < n; i++) {
        s2[i] = s[i];
    }
    return z_algorithm(s2);
}

}  







namespace atcoder {

struct two_sat {
  public:
    two_sat() : _n(0), scc(0) {}
    explicit two_sat(int n) : _n(n), _answer(n), scc(2 * n) {}

    void add_clause(int i, bool f, int j, bool g) {
        assert(0 <= i && i < _n);
        assert(0 <= j && j < _n);
        scc.add_edge(2 * i + (f ? 0 : 1), 2 * j + (g ? 1 : 0));
        scc.add_edge(2 * j + (g ? 0 : 1), 2 * i + (f ? 1 : 0));
    }
    bool satisfiable() {
        auto id = scc.scc_ids().second;
        for (int i = 0; i < _n; i++) {
            if (id[2 * i] == id[2 * i + 1]) return false;
            _answer[i] = id[2 * i] < id[2 * i + 1];
        }
        return true;
    }
    std::vector<bool> answer() { return _answer; }

  private:
    int _n;
    std::vector<bool> _answer;
    internal::id11 scc;
};

}  


using namespace atcoder;
using ll= long long;
using ld= long double;
using ull= unsigned long long;
using i128= __int128;
using pll= pair<ll, ll>;
using vi= vector<int>;
using vl= vector<ll>;
using vd= vector<ld>;
using vs= vector<string>;
using vi128= vector<i128>;
using vpll= vector<pll>;
using vvi= vector<vi>;
using vvl= vector<vl>;
using vvd= vector<vd>;
using vvs= vector<vs>;
using vvi128= vector<vi128>;
using vvpll= vector<vpll>;

using mint= modint1000000007;


using vm= vector<mint>;
using vvm= vector<vm>;

constexpr ll mod= 1e9 + 7;














    sort(ALL(p)); \
    for(bool(p






template <class T> inline ll SZ(const T &x) { return x.size(); }
ll TOPBIT(const ll &t) { return (t == 0 ? -1 : 63 - __builtin_clzll(t)); }
ll BIT(const ll &n) { return (1LL << n); }
template <class T> inline string YES(const T &n) { return (n ? "YES" : "NO"); }
template <class T> inline string Yes(const T &n) { return (n ? "Yes" : "No"); }
template <class T> inline string yes(const T &n) { return (n ? "yes" : "no"); }
template <class T> inline void UNIQUE(T &v) {
    v.erase(unique(ALL(v)), v.end());
}
template <class T, class U> inline ll LB(const T &v, const U &x) {
    return distance(v.begin(), lower_bound(ALL(v), x));
}
template <class T, class U> inline ll UB(const T &v, const U &x) {
    return distance(v.begin(), upper_bound(ALL(v), x));
}
template <class T> inline bool chmax(T &a, const T &b) {
    if(a < b) {
        a= b;
        return 1;
    }
    return 0;
}
template <class T> inline bool chmin(T &a, const T &b) {
    if(b < a) {
        a= b;
        return 1;
    }
    return 0;
}
const vpll dx4{{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
const vpll dx8{{1, 0},  {1, 1},   {0, 1},  {-1, 1},
               {-1, 0}, {-1, -1}, {0, -1}, {1, -1}};

    vector<__VA_ARGS__> name(size); \
    IN(name)

    vector<vector<__VA_ARGS__>> name((h), vector<__VA_ARGS__>(w)); \
    IN(name)

    ll __VA_ARGS__; \
    IN(__VA_ARGS__)

    string __VA_ARGS__; \
    IN(__VA_ARGS__)

    ld __VA_ARGS__; \
    IN(__VA_ARGS__)

    i128 __VA_ARGS__; \
    IN(__VA_ARGS__)
void _scan() {}
template <class T, class S> void _scan(pair<T, S> &p) {
    _scan(p.fi), _scan(p.se);
}
template <class T> void _scan(T &a) { cin >> a; }
void IN() {}
template <class Head, class... Tail> void IN(Head &head, Tail &...tail) {
    _scan(head);
    IN(tail...);
}

inline ostream &operator<<(ostream &stream, const mint &m) {
    stream << m.val();
    return stream;
}

template <class T> inline istream &operator>>(istream &stream, vector<T> &v) {
    EACH(x, v)
    stream >> x;
    return stream;
}
template <class T>
inline ostream &operator<<(ostream &stream, const vector<T> &v) {
    ll sz= SZ(v);
    REP(i, sz) { stream << v[i] << (i == sz - 1 ? "" : " "); }
    return stream;
}
template <class T>
inline ostream &operator<<(ostream &stream, const vector<vector<T>> &v) {
    ll sz= SZ(v);
    REP(i, sz) { stream << v[i] << (i == sz - 1 ? "" : "\n"); }
    return stream;
}
template <class T, class U>
inline istream &operator>>(istream &stream, pair<T, U> &p) {
    stream >> p.fi >> p.se;
    return stream;
}
template <class T, class U>
inline ostream &operator<<(ostream &stream, const pair<T, U> &p) {
    stream << p.fi << " " << p.se;
    return stream;
}
template <class T, class U>
inline pair<T, U> operator+(pair<T, U> p, const pair<T, U> &q) {
    p+= q;
    return p;
}
template <class T, class U>
inline pair<T, U> &operator+=(pair<T, U> &p, const pair<T, U> &q) {
    p.fi+= q.fi;
    p.se+= q.se;
    return p;
}
template <class T, class U>
inline pair<T, U> operator-(pair<T, U> p, const pair<T, U> &q) {
    p-= q;
    return p;
}
template <class T, class U>
inline pair<T, U> &operator-=(pair<T, U> &p, const pair<T, U> &q) {
    p.fi-= q.fi;
    p.se-= q.se;
    return p;
}
template <class T, class U> inline pair<T, U> operator+(const pair<T, U> &p) {
    return p;
}
template <class T, class U> inline pair<T, U> operator-(const pair<T, U> &p) {
    return mp(-p.fi, -p.se);
}
inline i128 parse(string &s) {
    reverse(ALL(s));
    i128 ret= 0;
    bool minus= 0;
    if(*(s.rbegin()) == '-') {
        minus= 1;
        s.pop_back();
    }
    while(!s.empty()) {
        if('0' <= *(s.rbegin()) && *(s.rbegin()) <= '9') {
            ret= ret * 10 + *(s.rbegin()) - '0';
            s.pop_back();
        } else {
            break;
        }
    }
    reverse(ALL(s));
    if(minus) ret*= -1;
    return ret;
}
inline string to_string(i128 val) {
    string ret= "";
    bool minus= 0;
    if(val < 0) {
        minus= 1;
        val*= -1;
    }
    do {
        int digit= val % 10;
        ret+= to_string(digit);
        val/= 10;
    } while(val != 0);
    if(minus) ret+= "-";
    reverse(ALL(ret));
    return ret;
}
inline istream &operator>>(istream &stream, i128 &val) {
    string str;
    stream >> str;
    val= parse(str);
    while(!str.empty()) {
        stream.putback(*(str.rbegin()));
        str.pop_back();
    }
    return stream;
}
inline ostream &operator<<(ostream &stream, const i128 &val) {
    stream << to_string(val);
    return stream;
}
inline void print() { cout << "\n"; }
template <class Head, class... Tail>
inline void print(const Head &H, const Tail &...T) {
    cout << H;
    (cout << ... << (cout << " ", T));
    cout << endl;
}
inline void debug_out() { cout << "\n"; }
template <class Head, class... Tail>
inline void debug_out(const Head &H, const Tail &...T) {
    cout << H;
    (cout << ... << (cout << " ", T));
    cout << endl;
}







struct S {
    ll l;
    ll r;
    ll lel;
    ll ril;
    ll pe;
    ll lev;
    ll riv;
    ll num;
};

S op(S a, S b) {
    if(a.l == 1145141919810) {
        return b;
    } else if(b.l == 1145141919810) {
        return a;
    }
    if(a.r > b.l) {
        S d= a;
        a= b;
        b= d;
    }
    S c;
    c.l= a.l;
    c.r= b.r;
    c.lev= a.lev;
    c.riv= b.riv;
    c.pe= 0;
    if(a.riv <= b.lev) {
        if(a.pe == 1 && b.pe == 1) {
            c.pe= 1;
            c.lel= a.lel + b.lel;
            c.ril= a.lel + b.lel;
            c.num= a.num + b.num;
        } else if(a.pe == 1 && b.pe == 0) {
            c.lel= a.lel + b.lel;
            c.ril= b.ril;
            c.num= a.num + b.num;
        } else if(a.pe == 0 && b.pe == 1) {
            c.lel= a.lel;
            c.ril= a.ril + b.ril;
            c.num= a.num + b.num;
        } else {
            c.lel= a.lel;
            c.ril= b.ril;
            c.num= a.num + b.num + (a.ril + b.lel) * (a.ril + b.lel + 1) / 2;
        }
    } else {
        if(a.pe == 1 && b.pe == 1) {
            c.lel= a.lel;
            c.ril= b.lel;
            c.num= a.num + b.num;
        } else if(a.pe == 1 && b.pe == 0) {
            c.lel= a.lel;
            c.ril= b.ril;
            c.num= a.num + b.num + b.lel * (b.lel + 1) / 2;
        } else if(a.pe == 0 && b.pe == 1) {
            c.lel= a.lel;
            c.ril= b.ril;
            c.num= a.num + b.num + a.ril * (a.ril + 1) / 2;
        } else {
            c.lel= a.lel;
            c.ril= b.ril;
            c.num= a.num + b.num + a.ril * (a.ril + 1) / 2 +
                   b.lel * (b.lel + 1) / 2;
        }
    }
    return c;
}

S e() { return {1145141919810, 0, 0, 0, 1, 0, 0, 0}; }

signed main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(12);
    LL(N, Q);
    VEC(A, N, ll);
    vector<S> ini(N);
    REP(i, N) {
        S c= {i, i, 1, 1, 1, A[i], A[i], 0};
        ini[i]= c;
    }
    id14<S, op, e> seg(ini);
    REP(Q) {
        LL(T);
        if(T == 1) {
            LL(X, Y);
            --X;
            S c= {X, X, 1, 1, 1, Y, Y, 0};
            seg.set((int)X, c);
        } else {
            LL(L, R);
            --L;
            S c= seg.prod((int)L, (int)R);
            if(c.pe == 0) {
                print(c.lel * (c.lel + 1) / 2 + c.ril * (c.ril + 1) / 2 +
                      c.num);
            } else {
                print(c.lel * (c.lel + 1) / 2);
            }
        }
    }
}