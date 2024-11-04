#pragma GCC optimize("Ofast")
#pragma GCC target("avx,tune=native")
#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; (i) < (int)(n); ++ (i))
#define REP3(i, m, n) for (int i = (m); (i) < (int)(n); ++ (i))
#define REP_R(i, n) for (int i = (int)(n) - 1; (i) >= 0; -- (i))
#define REP3R(i, m, n) for (int i = (int)(n) - 1; (i) >= (int)(m); -- (i))
#define ALL(x) std::begin(x), std::end(x)
using namespace std;

inline constexpr int32_t modpow(uint_fast64_t x, uint64_t k, int32_t MOD) {
    assert (0 <= x and x < MOD);
    uint_fast64_t y = 1;
    for (; k; k >>= 1) {
        if (k & 1) (y *= x) %= MOD;
        (x *= x) %= MOD;
    }
    assert (0 <= y and y < MOD);
    return y;
}
inline int32_t modinv(int32_t value, int32_t MOD) {
    assert (0 <= value and value < MOD);
    assert (value != 0);
    int64_t a = value, b = MOD;
    int64_t x = 0, y = 1;
    for (int64_t u = 1, v = 0; a; ) {
        int64_t q = b / a;
        x -= q * u; std::swap(x, u);
        y -= q * v; std::swap(y, v);
        b -= q * a; std::swap(b, a);
    }
    assert (value * x + MOD * y == b and b == 1);
    if (x < 0) x += MOD;
    assert (0 <= x and x < MOD);
    return x;
}

template <int32_t MOD>
struct mint {
    int32_t value;
    mint() : value() {}
    mint(int64_t value_) : value(value_ < 0 ? value_ % MOD + MOD : value_ >= MOD ? value_ % MOD : value_) {}
    mint(int32_t value_, std::nullptr_t) : value(value_) {}
    explicit operator bool() const { return value; }
    inline constexpr mint<MOD> operator + (mint<MOD> other) const { return mint<MOD>(*this) += other; }
    inline constexpr mint<MOD> operator - (mint<MOD> other) const { return mint<MOD>(*this) -= other; }
    inline constexpr mint<MOD> operator * (mint<MOD> other) const { return mint<MOD>(*this) *= other; }
    inline constexpr mint<MOD> & operator += (mint<MOD> other) { this->value += other.value; if (this->value >= MOD) this->value -= MOD; return *this; }
    inline constexpr mint<MOD> & operator -= (mint<MOD> other) { this->value -= other.value; if (this->value <    0) this->value += MOD; return *this; }
    inline constexpr mint<MOD> & operator *= (mint<MOD> other) { this->value = (uint_fast64_t)this->value * other.value % MOD; return *this; }
    inline constexpr mint<MOD> operator - () const { return mint<MOD>(this->value ? MOD - this->value : 0, nullptr); }
    inline constexpr mint<MOD> pow(uint64_t k) const { return mint<MOD>(modpow(value, k, MOD), nullptr); }
    inline mint<MOD> inv() const { return mint<MOD>(modinv(value, MOD), nullptr); }
    inline constexpr mint<MOD> operator /  (mint<MOD> other) const { return *this *  other.inv(); }
    inline constexpr mint<MOD> operator /= (mint<MOD> other)       { return *this *= other.inv(); }
    inline constexpr bool operator == (mint<MOD> other) const { return value == other.value; }
    inline constexpr bool operator != (mint<MOD> other) const { return value != other.value; }
};
template <int32_t MOD> mint<MOD> operator * (int64_t value, mint<MOD> n) { return mint<MOD>(value) * n; }
template <int32_t MOD> std::istream & operator >> (std::istream & in, mint<MOD> & n) { int64_t value; in >> value; n = value; return in; }
template <int32_t MOD> std::ostream & operator << (std::ostream & out, mint<MOD> n) { return out << n.value; }

template <int32_t PRIME> struct proth_prime {};
template <> struct proth_prime<1224736769> { static constexpr int a =             73, b = 24, g =  3; };
template <> struct proth_prime<1053818881> { static constexpr int a =     3 * 5 * 67, b = 20, g =  7; };
template <> struct proth_prime<1051721729> { static constexpr int a =        17 * 59, b = 20, g =  6; };
template <> struct proth_prime<1045430273> { static constexpr int a =            997, b = 20, g =  3; };
template <> struct proth_prime<1012924417> { static constexpr int a =     3 * 7 * 23, b = 21, g =  5; };
template <> struct proth_prime<1007681537> { static constexpr int a =        31 * 31, b = 20, g =  3; };
template <> struct proth_prime<1004535809> { static constexpr int a =            479, b = 21, g =  3; };
template <> struct proth_prime< 998244353> { static constexpr int a =         7 * 17, b = 23, g =  3; };
template <> struct proth_prime< 985661441> { static constexpr int a =         5 * 47, b = 22, g =  3; };
template <> struct proth_prime< 976224257> { static constexpr int a =     7 * 7 * 19, b = 20, g =  3; };
template <> struct proth_prime< 975175681> { static constexpr int a =     3 * 5 * 31, b = 21, g = 17; };
template <> struct proth_prime< 962592769> { static constexpr int a = 3 * 3 * 3 * 17, b = 21, g =  7; };
template <> struct proth_prime< 950009857> { static constexpr int a =        4 * 151, b = 21, g =  7; };
template <> struct proth_prime< 943718401> { static constexpr int a =  3 * 3 * 5 * 5, b = 22, g =  7; };
template <> struct proth_prime< 935329793> { static constexpr int a =            223, b = 22, g =  3; };
template <> struct proth_prime< 924844033> { static constexpr int a =  3 * 3 * 7 * 7, b = 21, g =  5; };
template <> struct proth_prime< 469762049> { static constexpr int a =              7, b = 26, g =  3; };
template <> struct proth_prime< 167772161> { static constexpr int a =              5, b = 25, g =  3; };

struct is_proth_prime_impl {
    template <int32_t PRIME, class T> static auto check(T *) -> decltype(proth_prime<PRIME>::g, std::true_type());
    template <int32_t PRIME, class T> static auto check(...) -> std::false_type;
};
template <int32_t PRIME>
struct is_proth_prime : decltype(is_proth_prime_impl::check<PRIME, std::nullptr_t>(nullptr)) {
};


template <int32_t PRIME>
void ntt_inplace(std::vector<mint<PRIME> > & a, bool inverse) {
    const int n = a.size();
    const int log2_n = __builtin_ctz(n);
    assert (n == 1 << log2_n);
    assert (log2_n <= proth_prime<PRIME>::b);

    

    std::vector<mint<PRIME> > ep, iep;
    while ((int)ep.size() <= log2_n) {
        ep.push_back(mint<PRIME>(proth_prime<PRIME>::g).pow(mint<PRIME>(-1).value / (1 << ep.size())));
        iep.push_back(ep.back().inv());
    }

    

    std::vector<mint<PRIME> > b(n);
    REP3 (i, 1, log2_n + 1) {
        int w = 1 << (log2_n - i);
        mint<PRIME> base = (inverse ? iep : ep)[i];
        mint<PRIME> now = 1;
        for (int y = 0; y < n / 2; y += w) {
            REP (x, w) {
                auto l = a[y << 1 | x];
                auto r = now * a[y << 1 | x | w];
                b[y | x] = l + r;
                b[y | x | n >> 1] = l - r;
            }
            now *= base;
        }
        std::swap(a, b);
    }

    

    if (inverse) {
        auto n_inv = mint<PRIME>(n).inv();
        REP (i, n) {
            a[i] *= n_inv;
        }
    }
}


template <int32_t MOD, int32_t MOD1, int32_t MOD2, int32_t MOD3>
mint<MOD> garner_algorithm(mint<MOD1> a1, mint<MOD2> a2, mint<MOD3> a3) {
    static const auto r12 = mint<MOD2>(MOD1).inv();
    static const auto r13 = mint<MOD3>(MOD1).inv();
    static const auto r23 = mint<MOD3>(MOD2).inv();
    a2 = (a2 - a1.value) * r12;
    a3 = (a3 - a1.value) * r13;
    a3 = (a3 - a2.value) * r23;
    return a1.value + a2.value * mint<MOD>(MOD1) + a3.value * (mint<MOD>(MOD1) * mint<MOD>(MOD2));
}


int32_t garner_algorithm(std::vector<std::pair<int32_t, int32_t> > eqns, int32_t MOD) {
    eqns.emplace_back(0, MOD);
    std::vector<int64_t> k(eqns.size(), 1);
    std::vector<int64_t> c(eqns.size(), 0);
    REP (i, eqns.size() - 1) {
        int32_t a_i, m_i; std::tie(a_i, m_i) = eqns[i];

        int32_t x = (a_i - c[i]) * modinv(k[i], m_i) % m_i;
        if (x < 0) x += m_i;
        assert (a_i == (k[i] * x + c[i]) % m_i);

        REP3 (j, i + 1, eqns.size()) {
            int32_t a_j, m_j; std::tie(a_j, m_j) = eqns[j];
            (c[j] += k[j] * x) %= m_j;
            (k[j] *= m_i) %= m_j;
        }
    }
    return c.back();
}

template <int32_t MOD>
std::vector<mint<MOD> > ntt_convolution_small(const std::vector<mint<MOD> > & a, const std::vector<mint<MOD> > & b) {
    std::vector<mint<MOD> > c(a.size() + b.size() - 1);
    REP (i, a.size()) {
        REP (j, b.size()) {
            c[i + j] += a[i] * b[j];
        }
    }
    return c;
}


template <int32_t PRIME>
typename std::enable_if<is_proth_prime<PRIME>::value, std::vector<mint<PRIME> > >::type ntt_convolution(const std::vector<mint<PRIME> > & a_, const std::vector<mint<PRIME> > & b_) {
    if (a_.size() <= 8 or b_.size() <= 8) return ntt_convolution_small(a_, b_);
    int m = a_.size() + b_.size() - 1;
    int n = (m == 1 ? 1 : 1 << (32 - __builtin_clz(m - 1)));
    auto a = a_;
    auto b = b_;
    a.resize(n);
    b.resize(n);
    ntt_inplace(a, false);
    ntt_inplace(b, false);
    REP (i, n) {
        a[i] *= b[i];
    }
    ntt_inplace(a, true);
    return a;
}

template <int32_t MOD>
typename std::enable_if<not is_proth_prime<MOD>::value, std::vector<mint<MOD> > >::type ntt_convolution(const std::vector<mint<MOD> > & a, const std::vector<mint<MOD> > & b) {
    if (a.size() <= 8 or b.size() <= 8) return ntt_convolution_small(a, b);
    constexpr int PRIMES[3] = { 1004535809, 998244353, 985661441 };
    std::vector<mint<PRIMES[0]> > x0(a.size());
    std::vector<mint<PRIMES[1]> > x1(a.size());
    std::vector<mint<PRIMES[2]> > x2(a.size());
    REP (i, a.size()) {
        x0[i] = a[i].value;
        x1[i] = a[i].value;
        x2[i] = a[i].value;
    }
    std::vector<mint<PRIMES[0]> > y0(b.size());
    std::vector<mint<PRIMES[1]> > y1(b.size());
    std::vector<mint<PRIMES[2]> > y2(b.size());
    REP (j, b.size()) {
        y0[j] = b[j].value;
        y1[j] = b[j].value;
        y2[j] = b[j].value;
    }
    std::vector<mint<PRIMES[0]> > z0 = ntt_convolution<PRIMES[0]>(x0, y0);
    std::vector<mint<PRIMES[1]> > z1 = ntt_convolution<PRIMES[1]>(x1, y1);
    std::vector<mint<PRIMES[2]> > z2 = ntt_convolution<PRIMES[2]>(x2, y2);
    std::vector<mint<MOD> > c(z0.size());
    REP (k, z0.size()) {
        c[k] = garner_algorithm<MOD>(z0[k], z1[k], z2[k]);
    }
    return c;
}


template <class T>
struct formal_power_series {
    std::vector<T> a;

    inline size_t size() const { return a.size(); }
    inline bool empty() const { return a.empty(); }
    inline T at(int i) const { return (i < size() ? a[i] : T(0)); }
    inline std::vector<T> & data() { return a; }

    formal_power_series() = default;
    formal_power_series(const std::vector<T> & a_) : a(a_) { shrink(); }
    formal_power_series(const std::initializer_list<T> & init) : a(init) { shrink(); }
    template <class Iterator>
    formal_power_series(Iterator first, Iterator last) : a(first, last) { shrink(); }
    void shrink() { while (not a.empty() and a.back().value == 0) a.pop_back(); }

    inline formal_power_series<T> operator + (const formal_power_series<T> & other) const {
        return formal_power_series<T>(a) += other;
    }
    inline formal_power_series<T> operator - (const formal_power_series<T> & other) const {
        return formal_power_series<T>(a) -= other;
    }
    inline formal_power_series<T> & operator += (const formal_power_series<T> & other) {
        if (a.size() < other.a.size()) a.resize(other.a.size(), T(0));
        REP (i, other.a.size()) a[i] += other.a[i];
        return *this;
    }
    inline formal_power_series<T> & operator -= (const formal_power_series<T> & other) {
        if (a.size() < other.a.size()) a.resize(other.a.size(), T(0));
        REP (i, other.a.size()) a[i] -= other.a[i];
        return *this;
    }
    inline formal_power_series<T> operator * (const formal_power_series<T> & other) const {
        return formal_power_series<T>(ntt_convolution(a, other.a));
    }
    inline formal_power_series<T> operator * (T b) {
        return formal_power_series<T>(a) *= b;
    }
    inline formal_power_series<T> & operator *= (T b) {
        REP (i, size()) a[i] *= b;
        return *this;
    }

    inline formal_power_series<T> integral() const {
        std::vector<T> b(size() + 1);
        REP (i, size()) {
            b[i + 1] = a[i] / (i + 1);
        }
        return b;
    }
    inline formal_power_series<T> differential() const {
        if (empty()) return *this;
        std::vector<T> b(size() - 1);
        REP (i, size() - 1) {
            b[i] = a[i + 1] * (i + 1);
        }
        return b;
    }
    inline formal_power_series<T> modulo_x_to(int k) const {
        return formal_power_series<T>(a.begin(), a.begin() + std::min<int>(size(), k));
    }
    inline void resize(int k) {
        a.resize(std::min<int>(size(), k));
    }

    formal_power_series<T> inv(int n) const {
        assert (at(0) != 0);
        formal_power_series<T> res { at(0).inv() };
        for (int i = 1; i < n; i *= 2) {
            res = (res * T(2) - res * res * modulo_x_to(2 * i)).modulo_x_to(2 * i);
        }
        return res.modulo_x_to(n);
    }
    formal_power_series<T> exp(int n) const {
        formal_power_series<T> f{ 1 };
        formal_power_series<T> g{ 1 };
        for (int i = 1; i < n; i *= 2) {
            g = (g * 2 - f * g * g).modulo_x_to(i);
            formal_power_series<T> q = differential().modulo_x_to(i - 1);
            formal_power_series<T> w = (q + g * (f.differential() - f * q)).modulo_x_to(2 * i - 1);
            f = (f + f * (*this - w.integral()).modulo_x_to(2 * i)).modulo_x_to(2 * i);
        }
        return f.modulo_x_to(n);
    }
    inline formal_power_series<T> log(int n) const {
        assert (at(0) == 1);
        return (this->differential() * this->inv(n - 1)).modulo_x_to(n - 1).integral();
    }
    inline formal_power_series<T> pow(int k, int n) const {
        return (this->log(n) * k).exp(n);
    }
};

constexpr int MOD = 998244353;
mint<MOD> solve(int n, const vector<int> & p) {
    map<int, int> cnt;
    for (int p_i : p) {
        ++ cnt[p_i];
    }
    map<int, int> cnt2;
    for (auto it : cnt) {
        ++ cnt2[it.second];
    }
    multimap<int, formal_power_series<mint<MOD> > > que;
    for (auto it : cnt2) {
        formal_power_series<mint<MOD> > f(vector<mint<MOD> >(it.first + 1, 1));
        REP (i, it.second) {
            que.emplace(f.size(), f);
        }
    }
    while (que.size() >= 2) {
        auto f = que.begin()->second;
        que.erase(que.begin());
        auto g = que.begin()->second;
        que.erase(que.begin());
        que.emplace(f.size() + g.size(), f * g);
    }
    auto f = que.begin()->second;
    return f.data()[n / 2];
}

int main() {
    int n; cin >> n;
    vector<int> p(n);
    REP (i, n) {
        cin >> p[i];
    }
    cout << solve(n, p) << endl;
    return 0;
}
