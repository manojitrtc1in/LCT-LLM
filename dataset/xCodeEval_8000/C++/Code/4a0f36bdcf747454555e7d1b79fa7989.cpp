#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

using namespace std;

typedef long long ll;
typedef long double ld;

template<class T> bool uin(T &a, T b)
{
    return a > b ? (a = b, true) : false;
}
template<class T> bool uax(T &a, T b)
{
    return a < b ? (a = b, true) : false;
}

constexpr int32_t modpow(int64_t x, uint64_t k, int32_t MOD) {
    assert(0 <= x && x < MOD);
    int64_t y = 1;
    for (; k; k >>= 1) {
        if (k & 1) (y *= x) %= MOD;
        (x *= x) %= MOD;
    }
    assert(0 <= y && y < MOD);
    return y;
}
int32_t modinv_nocheck(int32_t value, int32_t MOD) {
    assert (0 <= value && value < MOD);
    if (value == 0) return -1;
    int64_t a = value, b = MOD;
    int64_t x = 0, y = 1;
    for (int64_t u = 1, v = 0; a; ) {
        int64_t q = b / a;
        x -= q * u;
        std::swap(x, u);
        y -= q * v;
        std::swap(y, v);
        b -= q * a;
        std::swap(b, a);
    }
    if (!(value * x + MOD * y == b && b == 1)) return -1;
    if (x < 0) x += MOD;
    assert(0 <= x && x < MOD);
    return x;
}
inline int32_t modinv(int32_t x, int32_t MOD) {
    int32_t y = modinv_nocheck(x, MOD);
    assert(y != -1);
    return y;
}

template <int32_t MOD>
struct Mint {
    int32_t value;
    Mint() : value() {}
    Mint(int64_t value_) : value(value_ < 0 ? value_ % MOD + MOD : value_ >= MOD ? value_ % MOD : value_) {}
    Mint(int32_t value_, std::nullptr_t) : value(value_) {}
    explicit operator bool() const {
        return value;
    }
    inline constexpr Mint<MOD> operator + (Mint<MOD> other) const {
        return Mint<MOD>(*this) += other;
    }
    inline constexpr Mint<MOD> operator - (Mint<MOD> other) const {
        return Mint<MOD>(*this) -= other;
    }
    inline constexpr Mint<MOD> operator * (Mint<MOD> other) const {
        return Mint<MOD>(*this) *= other;
    }
    inline constexpr Mint<MOD> & operator += (Mint<MOD> other) {
        this->value += other.value;
        if (this->value >= MOD) this->value -= MOD;
        return *this;
    }
    inline constexpr Mint<MOD> & operator -= (Mint<MOD> other) {
        this->value -= other.value;
        if (this->value <    0) this->value += MOD;
        return *this;
    }
    inline constexpr Mint<MOD> & operator *= (Mint<MOD> other) {
        this->value = (uint_fast64_t)this->value * other.value % MOD;
        return *this;
    }
    inline constexpr Mint<MOD> operator - () const {
        return Mint<MOD>(this->value ? MOD - this->value : 0, nullptr);
    }
    inline constexpr Mint<MOD> pow(uint64_t k) const {
        return Mint<MOD>(modpow(value, k, MOD), nullptr);
    }
    inline Mint<MOD> inv() const {
        return Mint<MOD>(modinv(value, MOD), nullptr);
    }
    inline constexpr Mint<MOD> operator /  (Mint<MOD> other) const {
        return *this *  other.inv();
    }
    inline constexpr Mint<MOD> operator /= (Mint<MOD> other) {
        return *this *= other.inv();
    }
    inline constexpr bool operator == (Mint<MOD> other) const {
        return value == other.value;
    }
    inline constexpr bool operator != (Mint<MOD> other) const {
        return value != other.value;
    }
};
template <int32_t MOD> Mint<MOD> operator * (int64_t value, Mint<MOD> n) {
    return Mint<MOD>(value) * n;
}
template <int32_t MOD> std::istream & operator >> (std::istream & in, Mint<MOD> & n) {
    int64_t value;
    in >> value;
    n = value;
    return in;
}
template <int32_t MOD> std::ostream & operator << (std::ostream & out, Mint<MOD> n) {
    return out << n.value;
}

template <int32_t PRIME> struct proth_prime {};
template <> struct proth_prime<1224736769> {
    static constexpr int a =             73, b = 24, g =  3;
};
template <> struct proth_prime<1053818881> {
    static constexpr int a =     3 * 5 * 67, b = 20, g =  7;
};
template <> struct proth_prime<1051721729> {
    static constexpr int a =        17 * 59, b = 20, g =  6;
};
template <> struct proth_prime<1045430273> {
    static constexpr int a =            997, b = 20, g =  3;
};
template <> struct proth_prime<1012924417> {
    static constexpr int a =     3 * 7 * 23, b = 21, g =  5;
};
template <> struct proth_prime<1007681537> {
    static constexpr int a =        31 * 31, b = 20, g =  3;
};
template <> struct proth_prime<1004535809> {
    static constexpr int a =            479, b = 21, g =  3;
};
template <> struct proth_prime< 998244353> {
    static constexpr int a =         7 * 17, b = 23, g =  3;
};
template <> struct proth_prime< 985661441> {
    static constexpr int a =         5 * 47, b = 22, g =  3;
};
template <> struct proth_prime< 976224257> {
    static constexpr int a =     7 * 7 * 19, b = 20, g =  3;
};
template <> struct proth_prime< 975175681> {
    static constexpr int a =     3 * 5 * 31, b = 21, g = 17;
};
template <> struct proth_prime< 962592769> {
    static constexpr int a = 3 * 3 * 3 * 17, b = 21, g =  7;
};
template <> struct proth_prime< 950009857> {
    static constexpr int a =        4 * 151, b = 21, g =  7;
};
template <> struct proth_prime< 943718401> {
    static constexpr int a =  3 * 3 * 5 * 5, b = 22, g =  7;
};
template <> struct proth_prime< 935329793> {
    static constexpr int a =            223, b = 22, g =  3;
};
template <> struct proth_prime< 924844033> {
    static constexpr int a =  3 * 3 * 7 * 7, b = 21, g =  5;
};
template <> struct proth_prime< 469762049> {
    static constexpr int a =              7, b = 26, g =  3;
};
template <> struct proth_prime< 167772161> {
    static constexpr int a =              5, b = 25, g =  3;
};

struct is_proth_prime_impl
{
    template <int32_t PRIME, class T> static auto check(T *) -> decltype(proth_prime<PRIME>::g, std::true_type());
    template <int32_t PRIME, class T> static auto check(...) -> std::false_type;
};
template <int32_t PRIME>
struct is_proth_prime : decltype(is_proth_prime_impl::check<PRIME, std::nullptr_t>(nullptr)) {};


template <int32_t PRIME>
void ntt_inplace(std::vector<Mint<PRIME> > & a, bool inverse) {
    const int n = a.size();
    const int log2_n = __builtin_ctz(n);
    assert(n == 1 << log2_n);
    assert(log2_n <= proth_prime<PRIME>::b);

    

    std::vector<Mint<PRIME> > ep, iep;
    while ((int)ep.size() <= log2_n) {
        ep.push_back(Mint<PRIME>(proth_prime<PRIME>::g).pow(Mint<PRIME>(-1).value / (1 << ep.size())));
        iep.push_back(ep.back().inv());
    }

    

    std::vector<Mint<PRIME> > b(n);
    for (int i = 1; i <= log2_n; i++) {
        int w = 1 << (log2_n - i);
        Mint<PRIME> base = (inverse ? iep : ep)[i];
        Mint<PRIME> now = 1;
        for (int y = 0; y < n / 2; y += w) {
            for (int x = 0; x < w; x++) {
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
        auto n_inv = Mint<PRIME>(n).inv();
        for (int i = 0; i < n; i++) a[i] *= n_inv;
    }
}


template <int32_t PRIME>
typename std::enable_if<is_proth_prime<PRIME>::value, std::vector<Mint<PRIME> > >::type fft_convolution(const std::vector<Mint<PRIME> > & a_, const std::vector<Mint<PRIME> > & b_) {
    if (a_.empty() || b_.empty()) return {};














    int m = a_.size() + b_.size() - 1;
    int n = (m == 1 ? 1 : 1 << (32 - __builtin_clz(m - 1)));
    auto a = a_;
    auto b = b_;
    a.resize(n);
    b.resize(n);
    ntt_inplace(a, false);
    ntt_inplace(b, false);
    for (int i = 0; i < n; i++) a[i] *= b[i];
    ntt_inplace(a, true);
    a.resize(m);
    return a;
}

template <class T, int32_t MOD1, int32_t MOD2, int32_t MOD3>
T garner_algorithm_template(Mint<MOD1> a1, Mint<MOD2> a2, Mint<MOD3> a3) {
    static const auto r12 = Mint<MOD2>(MOD1).inv();
    static const auto r13 = Mint<MOD3>(MOD1).inv();
    static const auto r23 = Mint<MOD3>(MOD2).inv();
    a2 = (a2 - a1.value) * r12;
    a3 = (a3 - a1.value) * r13;
    a3 = (a3 - a2.value) * r23;
    return T(a1.value) + a2.value * T(MOD1) + a3.value * (T(MOD1) * T(MOD2));
}

template <class T, int32_t MOD0, int32_t MOD1, int32_t MOD2, int32_t MOD3, int32_t MOD4>
T garner_algorithm_template(Mint<MOD0> a0, Mint<MOD1> a1, Mint<MOD2> a2, Mint<MOD3> a3, Mint<MOD4> a4) {
    static const auto INV_M0_M1 = Mint<MOD1>(MOD0).inv();
    static const auto INV_M0M1_M2 = (Mint<MOD2>(MOD0) * MOD1).inv();
    static const auto INV_M0M1M2_M3 = (Mint<MOD3>(MOD0) * MOD1 * MOD2).inv();
    static const auto INV_M0M1M2M3_M4 = (Mint<MOD4>(MOD0) * MOD1 * MOD2 * MOD3).inv();
    const Mint<MOD1> b1 = INV_M0_M1 * (a1 - a0.value);
    const Mint<MOD2> b2 = INV_M0M1_M2 * (a2 - (Mint<MOD2>(b1.value) * MOD0 + a0.value));
    const Mint<MOD3> b3 = INV_M0M1M2_M3 * (a3 - ((Mint<MOD3>(b2.value) * MOD1 + b1.value) * MOD0 + a0.value));
    const Mint<MOD4> b4 = INV_M0M1M2M3_M4 * (a4 - (((Mint<MOD4>(b3.value) * MOD2 + b2.value) * MOD1 + b1.value) * MOD0 + a0.value));
    return (((T(b4.value) * MOD3 + b3.value) * MOD2 + b2.value) * MOD1 + b1.value) * MOD0 + a0.value;
}


template <int32_t MOD>
typename std::enable_if<!is_proth_prime<MOD>::value, std::vector<Mint<MOD> > >::type fft_convolution(const std::vector<Mint<MOD> > & a, const std::vector<Mint<MOD> > & b)
{
    if (a.empty() || b.empty()) return {};














    constexpr int PRIMES[3] = { 1004535809, 998244353, 985661441 };
    std::vector<Mint<PRIMES[0]> > x0(a.size());
    std::vector<Mint<PRIMES[1]> > x1(a.size());
    std::vector<Mint<PRIMES[2]> > x2(a.size());
    for (int i = 0; i < (int)a.size(); i++) {
        x0[i] = a[i].value;
        x1[i] = a[i].value;
        x2[i] = a[i].value;
    }
    std::vector<Mint<PRIMES[0]> > y0(b.size());
    std::vector<Mint<PRIMES[1]> > y1(b.size());
    std::vector<Mint<PRIMES[2]> > y2(b.size());
    for (int j = 0; j < (int)b.size(); j++) {
        y0[j] = b[j].value;
        y1[j] = b[j].value;
        y2[j] = b[j].value;
    }
    std::vector<Mint<PRIMES[0]> > z0 = fft_convolution<PRIMES[0]>(x0, y0);
    std::vector<Mint<PRIMES[1]> > z1 = fft_convolution<PRIMES[1]>(x1, y1);
    std::vector<Mint<PRIMES[2]> > z2 = fft_convolution<PRIMES[2]>(x2, y2);
    std::vector<Mint<MOD> > c(z0.size());
    for (int k = 0; k < (int)z0.size(); k++) {
        c[k] = garner_algorithm_template<Mint<MOD>>(z0[k], z1[k], z2[k]);
    }
    return c;
}


std::vector<uint64_t> fft_convolution(const std::vector<uint64_t> &a, const std::vector<uint64_t> &b)
{
    if (a.empty() || b.empty()) return {};
    constexpr int PRIMES[] = { 1004535809, 998244353, 985661441, 943718401, 935329793 };
    std::vector<Mint<PRIMES[0]> > x0(a.size());
    std::vector<Mint<PRIMES[1]> > x1(a.size());
    std::vector<Mint<PRIMES[2]> > x2(a.size());
    std::vector<Mint<PRIMES[3]> > x3(a.size());
    std::vector<Mint<PRIMES[4]> > x4(a.size());
    for (int i = 0; i < (int)a.size(); i++) {
        x0[i] = a[i];
        x1[i] = a[i];
        x2[i] = a[i];
        x3[i] = a[i];
        x4[i] = a[i];
    }
    std::vector<Mint<PRIMES[0]> > y0(b.size());
    std::vector<Mint<PRIMES[1]> > y1(b.size());
    std::vector<Mint<PRIMES[2]> > y2(b.size());
    std::vector<Mint<PRIMES[3]> > y3(b.size());
    std::vector<Mint<PRIMES[4]> > y4(b.size());
    for (int j = 0; j < (int)b.size(); j++) {
        y0[j] = b[j];
        y1[j] = b[j];
        y2[j] = b[j];
        y3[j] = b[j];
        y4[j] = b[j];
    }
    std::vector<Mint<PRIMES[0]> > z0 = fft_convolution<PRIMES[0]>(x0, y0);
    std::vector<Mint<PRIMES[1]> > z1 = fft_convolution<PRIMES[1]>(x1, y1);
    std::vector<Mint<PRIMES[2]> > z2 = fft_convolution<PRIMES[2]>(x2, y2);
    std::vector<Mint<PRIMES[3]> > z3 = fft_convolution<PRIMES[3]>(x3, y3);
    std::vector<Mint<PRIMES[4]> > z4 = fft_convolution<PRIMES[4]>(x4, y4);
    std::vector<uint64_t> c(z0.size());
    for (int k = 0; k < (int)z0.size(); k++) {
        c[k] = garner_algorithm_template<uint64_t>(z0[k], z1[k], z2[k], z3[k], z4[k]);
    }
    return c;
}

template<typename T>
T bpow(T x, size_t n) {
    return n ? n % 2 ? x * bpow(x, n - 1) : bpow(x * x, n / 2) : T(1);
}
template<typename T>
T bpow(T x, size_t n, T m) {
    return n ? n % 2 ? x * bpow(x, n - 1, m) % m : bpow(x * x % m, n / 2, m) : T(1);
}

template<typename T>
struct Poly {
    static const int magic = 500;
    static const int inf = 1e9;
    std::vector<T> a;

    

    void normalize() {
        while(!a.empty() && a.back() == T(0)) {
            a.pop_back();
        }
    }

    Poly() {}
    Poly(T a0) : a{a0} {
        normalize();
    }
    Poly(std::vector<T> t) : a(t) {
        normalize();
    }

    Poly operator += (const Poly &t) {
        a.resize(max(a.size(), t.a.size()));
        for(size_t i = 0; i < t.a.size(); i++) {
            a[i] += t.a[i];
        }
        normalize();
        return *this;
    }
    Poly operator -= (const Poly &t) {
        a.resize(max(a.size(), t.a.size()));
        for(size_t i = 0; i < t.a.size(); i++) {
            a[i] -= t.a[i];
        }
        normalize();
        return *this;
    }
    Poly operator + (const Poly &t) const {
        return Poly(*this) += t;
    }
    Poly operator - (const Poly &t) const {
        return Poly(*this) -= t;
    }

    

    Poly mod_xk(size_t k) const {
        k = std::min(k, a.size());
        return std::vector<T>(a.begin(), a.begin() + k);
    }
    

    Poly mul_xk(size_t k) const {
        Poly res(*this);
        res.a.insert(res.a.begin(), k, 0);
        return res;
    }
    

    Poly div_xk(size_t k) const {
        k = std::min(k, a.size());
        return std::vector<T>(a.begin() + k, a.end());
    }
    

    Poly substr(size_t l, size_t r) const {
        l = std::min(l, a.size());
        r = std::min(r, a.size());
        return std::vector<T>(a.begin() + l, a.begin() + r);
    }
    

    Poly inv(size_t n) const {
        assert(!is_zero());
        Poly ans = a[0].inv();
        size_t a = 1;
        while(a < n) {
            Poly C = (ans * mod_xk(2 * a)).substr(a, 2 * a);
            ans -= (ans * C).mod_xk(a).mul_xk(a);
            a *= 2;
        }
        return ans.mod_xk(n);
    }

    Poly operator *= (const Poly &t) {
        a = fft_convolution(a, t.a);
        normalize();
        return *this;
    }
    Poly operator * (const Poly &t) const {
        return Poly(*this) *= t;
    }

    

    Poly reverse(size_t n, bool rev = 0) const {
        Poly res(*this);
        

        if(rev) res.a.resize(max(n, res.a.size()));
        std::reverse(res.a.begin(), res.a.end());
        return res.mod_xk(n);
    }

    

    std::pair<Poly, Poly> divmod_slow(const Poly &b) const {
        std::vector<T> A(a);
        std::vector<T> res;
        while(A.size() >= b.a.size()) {
            res.push_back(A.back() / b.a.back());
            if(res.back() != T(0)) {
                for(size_t i = 0; i < b.a.size(); i++) {
                    A[A.size() - i - 1] -= res.back() * b.a[b.a.size() - i - 1];
                }
            }
            A.pop_back();
        }
        std::reverse(res.begin(), res.end());
        return {res, A};
    }

    

    std::pair<Poly, Poly> divmod(const Poly &b) const {
        if(deg() < b.deg()) return {Poly{0}, *this};
        int d = deg() - b.deg();
        if(std::min(d, b.deg()) < magic) return divmod_slow(b);
        Poly D = (reverse(d + 1) * b.reverse(d + 1).inv(d + 1)).mod_xk(d + 1).reverse(d + 1, 1);
        return {D, *this - D * b};
    }

    Poly operator / (const Poly &t) const {
        return divmod(t).first;
    }
    Poly operator % (const Poly &t) const {
        return divmod(t).second;
    }
    Poly operator /= (const Poly &t) {
        return *this = divmod(t).first;
    }
    Poly operator %= (const Poly &t) {
        return *this = divmod(t).second;
    }
    Poly operator *= (const T &x) {
        for(auto &it: a) it *= x;
        normalize();
        return *this;
    }
    Poly operator /= (const T &x) {
        for(auto &it: a) it /= x;
        normalize();
        return *this;
    }
    Poly operator * (const T &x) const {
        return Poly(*this) *= x;
    }
    Poly operator / (const T &x) const {
        return Poly(*this) /= x;
    }

    void print() const {
        for(auto it: a) std::cout << it << ' ';
        std::cout << std::endl;
    }
    

    T eval(T x) const {
        T res(0);
        for(int i = int(a.size()) - 1; i >= 0; i--) {
            res *= x;
            res += a[i];
        }
        return res;
    }

    

    T& lead() {
        return a.back();
    }
    

    int deg() const {
        return a.empty() ? -inf : a.size() - 1;
    }
    

    bool is_zero() const {
        return a.empty();
    }
    T operator [](int idx) const {
        return idx >= (int)a.size() || idx < 0 ? T(0) : a[idx];
    }

    

    T& coef(size_t idx) {
        return a[idx];
    }
    bool operator == (const Poly &t) const {
        return a == t.a;
    }
    bool operator != (const Poly &t) const {
        return a != t.a;
    }

    

    Poly deriv() {
        std::vector<T> res;
        for(int i = 1; i <= deg(); i++) res.push_back(T(i) * a[i]);
        return res;
    }
    

    Poly integr() {
        std::vector<T> res = {0};
        for(int i = 0; i <= deg(); i++) res.push_back(a[i] / T(i + 1));
        return res;
    }
    

    size_t leading_xk() const {
        if(is_zero()) return inf;
        int res = 0;
        while(a[res] == T(0)) res++;
        return res;
    }
    

    Poly log(size_t n) {
        assert(a[0] == T(1));
        return (deriv().mod_xk(n) * inv(n)).integr().mod_xk(n);
    }
    

    Poly exp(size_t n) {
        if(is_zero()) return T(1);
        assert(a[0] == T(0));
        Poly ans = T(1);
        size_t a = 1;
        while(a < n) {
            Poly C = ans.log(2 * a).div_xk(a) - substr(a, 2 * a);
            ans -= (ans * C).mod_xk(a).mul_xk(a);
            a *= 2;
        }
        return ans.mod_xk(n);
    }
    

    Poly pow_slow(size_t k, size_t n) {
        return k ? k % 2 ? (*this * pow_slow(k - 1, n)).mod_xk(n) : (*this * *this).mod_xk(n).pow_slow(k / 2, n) : T(1);
    }
    

    Poly pow(size_t k, size_t n) {
        if(is_zero()) return *this;
        if(k < magic) return pow_slow(k, n);
        int i = leading_xk();
        T j = a[i];
        Poly t = div_xk(i) / j;
        return bpow(j, k) * (t.log(n) * T(k)).exp(n).mul_xk(i * k).mod_xk(n);
    }
    

    Poly mulx(T x) {
        T cur = 1;
        Poly res(*this);
        for(int i = 0; i <= deg(); i++) {
            res.coef(i) *= cur;
            cur *= x;
        }
        return res;
    }
    

    Poly mulx_sq(T x) {
        T cur = x;
        T total = 1;
        T xx = x * x;
        Poly res(*this);
        for(int i = 0; i <= deg(); i++) {
            res.coef(i) *= total;
            total *= cur;
            cur *= xx;
        }
        return res;
    }
    

    std::vector<T> chirpz_even(T z, int n) {
        int m = deg();
        if(is_zero()) return std::vector<T>(n, 0);
        std::vector<T> vv(m + n);
        T zi = z.inv();
        T zz = zi * zi;
        T cur = zi;
        T total = 1;
        for(int i = 0; i <= std::max(n - 1, m); i++) {
            if(i <= m) vv[m - i] = total;
            if(i < n) vv[m + i] = total;
            total *= cur;
            cur *= zz;
        }
        Poly w = (mulx_sq(z) * vv).substr(m, m + n).mulx_sq(z);
        std::vector<T> res(n);
        for(int i = 0; i < n; i++) res[i] = w[i];
        return res;
    }
    

    std::vector<T> chirpz(T z, int n) {
        auto even = chirpz_even(z, (n + 1) / 2);
        auto odd = mulx(z).chirpz_even(z, n / 2);
        std::vector<T> ans(n);
        for(int i = 0; i < n / 2; i++) {
            ans[2 * i] = even[i];
            ans[2 * i + 1] = odd[i];
        }
        if(n % 2 == 1) ans[n - 1] = even.back();
        return ans;
    }
    

    template<typename iter>
    std::vector<T> eval(std::vector<Poly> &tree, int v, iter l, iter r) {
        if(r - l == 1) return {eval(*l)};
        else {
            auto m = l + (r - l) / 2;
            auto A = (*this % tree[2 * v]).eval(tree, 2 * v, l, m);
            auto B = (*this % tree[2 * v + 1]).eval(tree, 2 * v + 1, m, r);
            A.insert(A.end(), B.begin(), B.end());
            return A;
        }
    }
    

    std::vector<T> eval(std::vector<T> x) {
        int n = x.size();
        if(is_zero()) return std::vector<T>(n, T(0));
        std::vector<Poly> tree(4 * n);
        build(tree, 1, x.begin(), x.end());
        return eval(tree, 1, x.begin(), x.end());
    }
    

    template<typename iter>
    Poly inter(std::vector<Poly> &tree, int v, iter l, iter r, iter ly, iter ry) {
        if(r - l == 1) return {*ly / a[0]};
        else {
            auto m = l + (r - l) / 2;
            auto my = ly + (ry - ly) / 2;
            auto A = (*this % tree[2 * v]).inter(tree, 2 * v, l, m, ly, my);
            auto B = (*this % tree[2 * v + 1]).inter(tree, 2 * v + 1, m, r, my, ry);
            return A * tree[2 * v + 1] + B * tree[2 * v];
        }
    }
};

template<typename T>
Poly<T> operator * (const T& a, const Poly<T>& b) {
    return b * a;
}

template<typename T>
Poly<T> xk(int k) { 

    return Poly<T>{1}.mul_xk(k);
}

template<typename T>
T resultant(Poly<T> a, Poly<T> b) { 

    if(b.is_zero()) {
        return 0;
    } else if(b.deg() == 0) {
        return bpow(b.lead(), a.deg());
    } else {
        int pw = a.deg();
        a %= b;
        pw -= a.deg();
        T mul = bpow(b.lead(), pw) * T((b.deg() & a.deg() & 1) ? -1 : 1);
        T ans = resultant(b, a);
        return ans * mul;
    }
}
template<typename iter>
Poly<typename iter::value_type> kmul(iter L, iter R) { 

    if(R - L == 1) {
        return vector<typename iter::value_type>{-*L, 1};
    } else {
        iter M = L + (R - L) / 2;
        return kmul(L, M) * kmul(M, R);
    }
}
template<typename T, typename iter>
Poly<T> build(vector<Poly<T>> &res, int v, iter L, iter R) { 

    if(R - L == 1) {
        return res[v] = vector<T>{-*L, 1};
    } else {
        iter M = L + (R - L) / 2;
        return res[v] = build(res, 2 * v, L, M) * build(res, 2 * v + 1, M, R);
    }
}


template<typename T>
Poly<T> inter(vector<T> x, vector<T> y) {
    int n = x.size();
    vector<Poly<T>> tree(4 * n);
    return build(tree, 1, begin(x), end(x)).deriv().inter(tree, 1, begin(x), end(x), begin(y), end(y));
}

mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

const int maxN = 3e5 + 10;
using mint = Mint<998244353>;

int n;
vector<int> adj[maxN], vec;
mint fact[maxN];

vector<mint> build(int lo, int hi)
{
    if (lo == hi) {
        return {1, vec[lo]};
    }
    int mid = (lo + hi) / 2;
    auto L = build(lo, mid);
    auto R = build(mid + 1, hi);
    return fft_convolution(L, R);
}

void dfs(int u, int p)
{
    int cnt = 0;
    for (auto &v: adj[u]) {
        if (v == p) {
            continue;
        }
        cnt++;
        dfs(v, u);
    }
    if (cnt) {
        vec.push_back(cnt);
    }
}

void solve()
{
    cin >> n;
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, 0);
    auto f = build(0, (int)vec.size() - 1);
    fact[0] = 1;
    for (int i = 1; i <= n; i++) {
        fact[i] = fact[i - 1] * i;
    }
    mint ans(0);
    for (int k = 0; k < (int)f.size(); k++) {
        ans += (k % 2 ? -1 : 1) * f[k] * fact[n - k];
    }
    cout << ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;


    while (T--)
    {
        solve();
    }
    return 0;
}
