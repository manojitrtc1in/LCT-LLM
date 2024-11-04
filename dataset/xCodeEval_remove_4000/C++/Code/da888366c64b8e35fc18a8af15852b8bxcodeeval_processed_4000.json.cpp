







































using pii = std::pair<int, int>;
using pll = std::pair<int64_t, int64_t>;
using pli = std::pair<int64_t, int>;
using tiii = std::tuple<int, int, int>;
using ui = uint32_t;
using ll = int64_t;
using ull = uint64_t;
using vc = std::vector<char>;
using vi = std::vector<int>;
using vll = std::vector<ll>;
using vull = std::vector<ull>;
using GR = std::vector<std::vector<int>>;




































namespace {


std::vector<int> getDigits(int64_t x) {
    if (x == 0) return std::vector<int>{0};
    x = std::abs(x);
    std::vector<int> ans;
    while (x > 0) {
        ans.push_back(x % 10);
        x /= 10;
    }
    return ans;
}

int id0(int64_t x) {


    return getDigits(x).size();
}

int64_t sqrtUp(int64_t k) {
    int64_t t = (int64_t) std::sqrt((double) k);
    while (t * t > k) --t;
    while (t * t < k) ++t;
    return t;
}

int64_t sqrtDown(int64_t k) {
    int64_t t = (int64_t) std::sqrt((double) k);
    while (t * t < k) ++t;
    while (t * t > k) --t;
    return t;
}

bool id10(int64_t x) {
    uint64_t y = static_cast<uint64_t>(std::abs(x));
    return y && (!(y & (y - 1)));
}

bool id2(int64_t x) {
    int64_t y = static_cast<int64_t>(std::round(std::sqrt((double) x)));
    return y * y == x;
}

template<typename T>
T id9(T a, T b) {
    static_assert(std::is_arithmetic<T>::value && !std::is_floating_point<T>::value, "T must be of integer type");
    while (b) {
        a %= b;
        std::swap(a, b);
    }
    return a;
}



template<typename T>
std::tuple<T, T, T> id3(T a, T b) {
    static_assert(std::is_arithmetic<T>::value && !std::is_floating_point<T>::value, "T must be of integer type");
    T x = 1, y = 0;
    T x1 = 0, y1 = 1, a1 = a, b1 = b;
    while (b1) {
        T q = a1 / b1;
        std::tie(x, x1) = std::make_tuple(x1, x - q * x1);
        std::tie(y, y1) = std::make_tuple(y1, y - q * y1);
        std::tie(a1, b1) = std::make_tuple(b1, a1 - q * b1);
    }
    return std::make_tuple(x, y, a1);
}

template<typename T>
T id6(T a, T b) {
    static_assert(std::is_arithmetic<T>::value && !std::is_floating_point<T>::value, "T must be of integer type");
    return a / id9(a, b) * b;
}
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

    

    explicit barrett(unsigned int m) : _m(m), im((unsigned long long) (-1) / m + 1) {}

    

    unsigned int umod() const { return _m; }

    

    

    

    unsigned int mul(unsigned int a, unsigned int b) const {
        

        


        

        

        

        

        

        

        

        unsigned long long z = a;
        z *= b;

        unsigned long long x;
        _umul128(z, im, &x);

        unsigned long long x =
                (unsigned long long) (((unsigned __int128) (z) * im) >> 64);

        unsigned int v = (unsigned int) (z - x * _m);
        if (_m <= v) v += _m;
        return v;
    }
};







constexpr long long id11(long long x, long long n, int m) {
    if (m == 1) return 0;
    unsigned int _m = (unsigned int) (m);
    unsigned long long r = 1;
    unsigned long long y = safe_mod(x, m);
    while (n) {
        if (n & 1) r = (r * y) % _m;
        y = (y * y) % _m;
        n >>= 1;
    }
    return r;
}









constexpr bool id5(int n) {
    if (n <= 1) return false;
    if (n == 2 || n == 7 || n == 61) return true;
    if (n % 2 == 0) return false;
    long long d = n - 1;
    while (d % 2 == 0) d /= 2;
    constexpr long long bases[3] = {2, 7, 61};
    for (long long a: bases) {
        long long t = d;
        long long y = id11(a, t, n);
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

template<int n> constexpr bool is_prime = id5(n);





constexpr std::pair<long long, long long> id7(long long a, long long b) {
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







constexpr int id8(int m) {
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
    for (int i = 3; (long long) (i) * i <= x; i += 2) {
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
            if (id11(g, (m - 1) / divs[i], m) == 1) {
                ok = false;
                break;
            }
        }
        if (ok) return g;
    }
}

template<int m> constexpr int primitive_root = id8(m);







unsigned long long id4(unsigned long long n,
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
        

        

        n = (unsigned long long) (y_max / m);
        b = (unsigned long long) (y_max % m);
        std::swap(m, a);
    }
    return ans;
}

}  


}  










namespace atcoder {

namespace internal {


template<class T>
using is_signed_int128 =
typename std::conditional<std::is_same<T, __int128_t>::value ||
                          std::is_same<T, __int128>::value,
        std::true_type,
        std::false_type>::type;

template<class T>
using is_unsigned_int128 =
typename std::conditional<std::is_same<T, __uint128_t>::value ||
                          std::is_same<T, unsigned __int128>::value,
        std::true_type,
        std::false_type>::type;

template<class T>
using make_unsigned_int128 =
typename std::conditional<std::is_same<T, __int128_t>::value,
        __uint128_t,
        unsigned __int128>;

template<class T>
using is_integral = typename std::conditional<std::is_integral<T>::value ||
                                              is_signed_int128<T>::value ||
                                              is_unsigned_int128<T>::value,
        std::true_type,
        std::false_type>::type;

template<class T>
using is_signed_int = typename std::conditional<(is_integral<T>::value &&
                                                 std::is_signed<T>::value) ||
                                                is_signed_int128<T>::value,
        std::true_type,
        std::false_type>::type;

template<class T>
using is_unsigned_int =
typename std::conditional<(is_integral<T>::value &&
                           std::is_unsigned<T>::value) ||
                          is_unsigned_int128<T>::value,
        std::true_type,
        std::false_type>::type;

template<class T>
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



template<class T>
using is_signed_int_t = std::enable_if_t<is_signed_int<T>::value>;

template<class T>
using is_unsigned_int_t = std::enable_if_t<is_unsigned_int<T>::value>;

template<class T> using to_unsigned_t = typename to_unsigned<T>::type;

}  


}  






namespace atcoder {

namespace internal {

struct modint_base {
};
struct static_modint_base : modint_base {
};

template<class T> using is_modint = std::is_base_of<modint_base, T>;
template<class T> using is_modint_t = std::enable_if_t<is_modint<T>::value>;

}  


template<int m, std::enable_if_t<(1 <= m)> * = nullptr>
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

template<class T, internal::is_signed_int_t<T> * = nullptr>
id1(T v) {
    long long x = (long long) (v % (long long) (umod()));
    if (x < 0) x += umod();
    _v = (unsigned int) (x);
}

template<class T, internal::is_unsigned_int_t<T> * = nullptr>
id1(T v) {
    _v = (unsigned int) (v % umod());
}

unsigned int val() const { return _v; }

mint &operator++() {
    _v++;
    if (_v == umod()) _v = 0;
    return *this;
}

mint &operator--() {
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

mint &operator+=(const mint &rhs) {
    _v += rhs._v;
    if (_v >= umod()) _v -= umod();
    return *this;
}

mint &operator-=(const mint &rhs) {
    _v -= rhs._v;
    if (_v >= umod()) _v += umod();
    return *this;
}

mint &operator*=(const mint &rhs) {
    unsigned long long z = _v;
    z *= rhs._v;
    _v = (unsigned int) (z % umod());
    return *this;
}

mint &operator/=(const mint &rhs) { return *this = *this * rhs.inv(); }

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
        auto eg = internal::id7(_v, m);
        assert(eg.first == 1);
        return eg.second;
    }
}

friend mint operator+(const mint &lhs, const mint &rhs) {
    return mint(lhs) += rhs;
}

friend mint operator-(const mint &lhs, const mint &rhs) {
    return mint(lhs) -= rhs;
}

friend mint operator*(const mint &lhs, const mint &rhs) {
    return mint(lhs) *= rhs;
}

friend mint operator/(const mint &lhs, const mint &rhs) {
    return mint(lhs) /= rhs;
}

friend bool operator==(const mint &lhs, const mint &rhs) {
    return lhs._v == rhs._v;
}

friend bool operator!=(const mint &lhs, const mint &rhs) {
    return lhs._v != rhs._v;
}

private:
unsigned int _v;

static constexpr unsigned int umod() { return m; }

static constexpr bool prime = internal::is_prime<m>;
};

template<int id>
struct id12 : internal::modint_base {
using mint = id12;

public:
static int mod() { return (int) (bt.umod()); }

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

template<class T, internal::is_signed_int_t<T> * = nullptr>
id12(T v) {
    long long x = (long long) (v % (long long) (mod()));
    if (x < 0) x += mod();
    _v = (unsigned int) (x);
}

template<class T, internal::is_unsigned_int_t<T> * = nullptr>
id12(T v) {
    _v = (unsigned int) (v % mod());
}

unsigned int val() const { return _v; }

mint &operator++() {
    _v++;
    if (_v == umod()) _v = 0;
    return *this;
}

mint &operator--() {
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

mint &operator+=(const mint &rhs) {
    _v += rhs._v;
    if (_v >= umod()) _v -= umod();
    return *this;
}

mint &operator-=(const mint &rhs) {
    _v += mod() - rhs._v;
    if (_v >= umod()) _v -= umod();
    return *this;
}

mint &operator*=(const mint &rhs) {
    _v = bt.mul(_v, rhs._v);
    return *this;
}

mint &operator/=(const mint &rhs) { return *this = *this * rhs.inv(); }

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
    auto eg = internal::id7(_v, mod());
    assert(eg.first == 1);
    return eg.second;
}

friend mint operator+(const mint &lhs, const mint &rhs) {
    return mint(lhs) += rhs;
}

friend mint operator-(const mint &lhs, const mint &rhs) {
    return mint(lhs) -= rhs;
}

friend mint operator*(const mint &lhs, const mint &rhs) {
    return mint(lhs) *= rhs;
}

friend mint operator/(const mint &lhs, const mint &rhs) {
    return mint(lhs) /= rhs;
}

friend bool operator==(const mint &lhs, const mint &rhs) {
    return lhs._v == rhs._v;
}

friend bool operator!=(const mint &lhs, const mint &rhs) {
    return lhs._v != rhs._v;
}

private:
unsigned int _v;
static internal::barrett bt;

static unsigned int umod() { return bt.umod(); }
};

template<int id> internal::barrett id12<id>::bt(998244353);

using modint998244353 = id1<998244353>;
using modint1000000007 = id1<1000000007>;
using modint = id12<-1>;

namespace internal {

template<class T>
using is_static_modint = std::is_base_of<internal::static_modint_base, T>;

template<class T>
using is_static_modint_t = std::enable_if_t<is_static_modint<T>::value>;

template<class>
struct is_dynamic_modint : public std::false_type {
};
template<int id>
struct is_dynamic_modint<id12<id>> : public std::true_type {
};

template<class T>
using is_dynamic_modint_t = std::enable_if_t<is_dynamic_modint<T>::value>;

}  


}  






using namespace std;

class CStrangeFunction {

public:

using mint = atcoder::modint1000000007;

void solveOne(std::istream &in, std::ostream &out) {
    ll n;
    in >> n;
    ll l = 1;
    mint ans = 0;
    FOR(i, 1, n + 1) {
        l = id6(l, (ll) i);
        if (l > n) break;
        ans += n / l;
    }
    ans += n;
    out << ans.val() << ENDL;
}

void solve(std::istream &in, std::ostream &out) {
    int TestsCount = 1;
    in >> TestsCount;
    for (int i = 1; i <= TestsCount; ++i) {
        solveOne(in, out);
    }
}
};


int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    CStrangeFunction solver;
    std::istream &in(std::cin);
    std::ostream &out(std::cout);
    solver.solve(in, out);
    fflush(stdout);
    return 0;
}
