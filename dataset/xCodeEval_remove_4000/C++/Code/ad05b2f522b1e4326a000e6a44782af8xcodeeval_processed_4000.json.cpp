









using ll = int64_t;
using ull = uint64_t;
using Real = double;
using Complex = std::complex<Real>;
using pi = std::pair<ll, ll>;



const Real eps = 1e-15;










    struct has_impl_
        template <class T>                                               \
        static auto check(T&& x) -> decltype((x.f(), std::true_type{})); \
        template <class T>                                               \
        static auto check(...) -> std::false_type;                       \
    };                                                                   \
    template <class T>                                                   \
    class has_

id3(hasChildV);

template <class T>
class V : private std::vector<T> {
  public:
    using vector = std::vector<T>;
    using vector::allocator_type;
    using vector::assign;
    using vector::at;
    using vector::back;
    using vector::begin;
    using vector::capacity;
    using vector::cbegin;
    using vector::cend;
    using vector::clear;
    using vector::const_iterator;
    using vector::const_pointer;
    using vector::const_reference;
    using vector::const_reverse_iterator;
    using vector::crbegin;
    using vector::crend;
    using vector::data;
    using vector::difference_type;
    using vector::emplace;
    using vector::emplace_back;
    using vector::empty;
    using vector::end;
    using vector::erase;
    using vector::front;
    using vector::get_allocator;
    using vector::insert;
    using vector::iterator;
    using vector::max_size;
    using vector::swap;
    using vector::operator[];
    using vector::pointer;
    using vector::pop_back;
    using vector::push_back;
    using vector::rbegin;
    using vector::reference;
    using vector::rend;
    using vector::reserve;
    using vector::resize;
    using vector::reverse_iterator;
    using vector::shrink_to_fit;
    using vector::size;
    using vector::size_type;
    using vector::value_type;
    using vector::vector;
    using type = T;

    bool hasChildV() const { return false; }

    constexpr T sum() const noexcept {
        T x = 0;
        for (auto&& i : *this) x += i;
        return x;
    }
    constexpr T max() const noexcept {
        T x = std::numeric_limits<T>::min();
        for (auto&& i : *this) chmax(x, i);
        return x;
    }
    constexpr T min() const noexcept {
        T x = std::numeric_limits<T>::max();
        for (auto&& i : *this) chmin(x, i);
        return x;
    }
    V<T>& operator+=(const T x) {
        for (auto& i : *this)
            i += x;
        return *this;
    }
    template <class U>
    V<T>& operator+=(const V<U>& v) {
        for (size_t i = 0; i < std::min(this->size(), v.size()); ++i)
            (*this)[i] += v[i];
        return *this;
    }
    V<T> operator+(const T x) {
        return V<T>(*this) += x;
    }
    template <class U>
    V<T> operator+(const V<U>& v) {
        return V<T>(*this) += v;
    }
    V<T>& operator-=(const T x) {
        for (auto& i : *this)
            i -= x;
        return *this;
    }
    template <class U>
    V<T>& operator-=(const V<U>& v) {
        for (size_t i = 0; i < std::min(this->size(), v.size()); ++i)
            (*this)[i] -= v[i];
        return *this;
    }
    V<T> operator-(const T x) {
        return V<T>(*this) -= x;
    }
    template <class U>
    V<T> operator-(const V<U>& v) {
        return V<T>(*this) -= v;
    }
    V<T>& operator*=(const T x) {
        for (auto& i : *this)
            i *= x;
        return *this;
    }
    template <class U>
    V<T>& operator*=(const V<U>& v) {
        for (size_t i = 0; i < std::min(this->size(), v.size()); ++i)
            (*this)[i] *= v[i];
        return *this;
    }
    V<T> operator*(const T x) {
        return V<T>(*this) *= x;
    }
    template <class U>
    V<T> operator*(const V<U>& v) {
        return V<T>(*this) *= v;
    }
    V<T>& operator/=(const T x) {
        for (auto& i : *this)
            i /= x;
        return *this;
    }
    template <class U>
    V<T>& operator/=(const V<U>& v) {
        for (size_t i = 0; i < std::min(this->size(), v.size()); ++i)
            (*this)[i] /= v[i];
        return *this;
    }
    V<T> operator/(const T x) {
        return V<T>(*this) /= x;
    }
    template <class U>
    V<T> operator/(const V<U>& v) {
        return V<T>(*this) /= v;
    }
};

template <class T>
class V<V<T>> : private std::vector<V<T>> {
  public:
    using vector = std::vector<V<T>>;
    using vector::allocator_type;
    using vector::assign;
    using vector::at;
    using vector::back;
    using vector::begin;
    using vector::capacity;
    using vector::cbegin;
    using vector::cend;
    using vector::clear;
    using vector::const_iterator;
    using vector::const_pointer;
    using vector::const_reference;
    using vector::const_reverse_iterator;
    using vector::crbegin;
    using vector::crend;
    using vector::data;
    using vector::difference_type;
    using vector::emplace;
    using vector::emplace_back;
    using vector::empty;
    using vector::end;
    using vector::erase;
    using vector::front;
    using vector::get_allocator;
    using vector::insert;
    using vector::iterator;
    using vector::max_size;
    using vector::swap;
    using vector::operator[];
    using vector::pointer;
    using vector::pop_back;
    using vector::push_back;
    using vector::rbegin;
    using vector::reference;
    using vector::rend;
    using vector::reserve;
    using vector::resize;
    using vector::reverse_iterator;
    using vector::shrink_to_fit;
    using vector::size;
    using vector::size_type;
    using vector::value_type;
    using vector::vector;
    using type = typename V<T>::type;

    bool hasChildV() const { return true; }

    using Ty = type;
    constexpr Ty sum() const noexcept {
        Ty x = 0;
        for (auto&& i : *this) x += i.sum();
        return x;
    }
    constexpr Ty max() const noexcept {
        Ty x = std::numeric_limits<Ty>::min();
        for (auto&& i : *this) {
            

            chmax(x, i.max());
        }
        return x;
    }
    constexpr Ty min() const noexcept {
        Ty x = std::numeric_limits<Ty>::max();
        for (auto&& i : *this) {
            

            chmin(x, i.min());
        }
        return x;
    }
};

template <class T>
using VV = V<V<T>>;

template <class T>
std::ostream& operator<<(std::ostream& os, const V<T>& v) {
    char delimiter = (v.hasChildV() ? '\n' : ' ');
    os << *(v.begin());
    for (auto itr = v.begin() + 1; itr != v.end(); ++itr) {
        os << delimiter << *itr;
    }
    return os;
}

template <class T>
std::istream& operator>>(std::istream& is, V<T>& v) {
    for (auto& i : v) is >> i;
    return is;
}

template <class T, class U>
std::ostream& operator<<(std::ostream& os, const std::pair<T, U>& p) {
    return os << p.first << " " << p.second;
}

template <class T, class U>
std::istream& operator>>(std::istream& is, std::pair<T, U>& p) {
    return is >> p.first >> p.second;
}

void fin(const char* str) {
    std::cout << str << std::endl;
    exit(0);
}


const ll MAX = 510000;
const ll MOD = 1000000007;

ll fac[MAX], finv[MAX], inv[MAX];



void COMinit(ll mod = MOD) {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (ll i = 2; i < MAX; i++) {
        fac[i] = fac[i - 1] * i % mod;
        inv[i] = mod - inv[mod % i] * (mod / i) % mod;
        finv[i] = finv[i - 1] * inv[i] % mod;
    }
}



ll COM(ll n, ll k, ll mod = MOD) {
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % mod) % mod;
}

const ll MAX_C = 1000;
ll Com[MAX_C][MAX_C];

void calc_com() {
    memset(Com, 0, sizeof(Com));
    Com[0][0] = 1;
    for (int i = 1; i < MAX_C; ++i) {
        Com[i][0] = 1;
        for (int j = 1; j < MAX_C; ++j) {
            Com[i][j] = (Com[i - 1][j - 1] + Com[i - 1][j]);
        }
    }
}


template <typename T, typename E>
struct SegmentTree {
    using F = std::function<T(T, T)>;
    using G = std::function<T(T, E)>;
    int n;
    F f;
    G g;
    T d1;
    E d0;
    std::vector<T> dat;
    SegmentTree(){};
    SegmentTree(int n_, F f, G g, T d1,
                std::vector<T> v = std::vector<T>()) : f(f), g(g), d1(d1) {
        init(n_);
        if (n_ == (int)v.size()) build(n_, v);
    }
    void init(int n_) {
        n = 1;
        while (n < n_) n *= 2;
        dat.clear();
        dat.resize(2 * n - 1, d1);
    }
    void build(int n_, std::vector<T> v) {
        for (int i = 0; i < n_; i++) dat[i + n - 1] = v[i];
        for (int i = n - 2; i >= 0; i--)
            dat[i] = f(dat[i * 2 + 1], dat[i * 2 + 2]);
    }
    void update(int k, E a) {
        k += n - 1;
        dat[k] = g(dat[k], a);
        while (k > 0) {
            k = (k - 1) / 2;
            dat[k] = f(dat[k * 2 + 1], dat[k * 2 + 2]);
        }
    }
    inline T query(int a, int b) {
        T vl = d1, vr = d1;
        for (int l = a + n, r = b + n; l < r; l >>= 1, r >>= 1) {
            if (l & 1) vl = f(vl, dat[(l++) - 1]);
            if (r & 1) vr = f(dat[(--r) - 1], vr);
        }
        return f(vl, vr);
    }
};


ll totient(ll n) {
    ll r = n;
    for (ll i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            r -= r / i;
            while (n % i == 0) n /= i;
        }
    }
    if (n > 1) r -= r / n;
    return r;
}


template <typename T>
T id1(T a, T b, T& x, T& y) {
    T d = a;
    if (b != 0) {
        d = id1(b, a % b, y, x);
        y -= (a / b) * x;
    } else {
        x = 1;
        y = 0;
    }
    return d;
}


ll modinv(ll a, ll m) {
    ll b = m, u = 1, v = 0;
    while (b) {
        ll t = a / b;
        a -= t * b;
        std::swap(a, b);
        u -= t * v;
        std::swap(u, v);
    }
    return (u + m) % m;
}


ll modpow(ll a, ll b, ll p) {
    ll res = 1, k = a;
    if (b < 0) {
        b = -b;
        k = modinv(a, p);
    }
    while (b > 0) {
        if (b % 2) (res *= k) %= p;
        b /= 2;
        (k *= k) %= p;
    }
    return res;
}



ll powint(ll a, ll b) {
    ll res = 1, k = a;
    assert(b >= 0);
    while (b > 0) {
        if (b & 1) (res *= k);
        b /= 2;
        k *= k;
    }
    return res;
}


template <std::uint_fast64_t Modulus>
class modint {
    using u64 = std::uint_fast64_t;

  public:
    u64 a;

    constexpr modint(const u64 x = 0) noexcept : a(x % Modulus) {}
    constexpr u64& value() noexcept { return a; }
    constexpr const u64& value() const noexcept { return a; }
    constexpr modint operator+(const modint rhs) const noexcept {
        return modint(*this) += rhs;
    }
    constexpr modint operator-(const modint rhs) const noexcept {
        return modint(*this) -= rhs;
    }
    constexpr modint operator*(const modint rhs) const noexcept {
        return modint(*this) *= rhs;
    }
    constexpr modint operator/(const modint rhs) const noexcept {
        return modint(*this) /= rhs;
    }
    constexpr modint& operator+=(const modint rhs) noexcept {
        a += rhs.a;
        if (a >= Modulus) {
            a -= Modulus;
        }
        return *this;
    }
    constexpr modint& operator-=(const modint rhs) noexcept {
        if (a < rhs.a) {
            a += Modulus;
        }
        a -= rhs.a;
        return *this;
    }
    constexpr modint& operator*=(const modint rhs) noexcept {
        a = a * rhs.a % Modulus;
        return *this;
    }
    constexpr modint& operator/=(modint rhs) noexcept {
        u64 exp = Modulus - 2;
        while (exp) {
            if (exp % 2) {
                *this *= rhs;
            }
            rhs *= rhs;
            exp /= 2;
        }
        return *this;
    }
    constexpr modint pow(u64 b) {
        modint res = 1, k = a;
        while (b > 0) {
            if (b % 2) res *= k;
            b /= 2;
            k *= k;
        }
        return res;
    }
    bool operator==(const modint& rhs) const {
        return value() == rhs.value();
    }
    bool operator!=(const modint& rhs) const {
        return !(value() == rhs.value());
    }

    friend std::istream& operator>>(std::istream& is, modint<Modulus>& mi) {
        u64 k;
        is >> k;
        mi = k;
        return is;
    }
    friend std::ostream& operator<<(std::ostream& os, const modint<Modulus>& mi) {
        return os << mi.value();
    }
};


template <bool id2>
class id4 {
    using u64 = std::uint_fast64_t;

    static u64& mod() {
        static u64 mod_ = 0;
        return mod_;
    }

  public:
    u64 a;

    id4(const u64 x = 0, const u64 m = 2) {
        a = x;
        set_mod(m);
        a %= get_mod();
    }
    template <bool B>
    id4(const id4<B>& x, const u64 m = 2) {
        a = x.value();
        set_mod(m);
        a %= get_mod();
    }
    u64& value() noexcept { return a; }
    const u64& value() const noexcept { return a; }
    id4 operator+(const id4 rhs) const {
        return id4(*this) += rhs;
    }
    id4 operator-(const id4 rhs) const {
        return id4(*this) -= rhs;
    }
    id4 operator*(const id4 rhs) const {
        return id4(*this) *= rhs;
    }
    id4 operator/(const id4 rhs) const {
        return id4(*this) /= rhs;
    }
    id4& operator+=(const id4 rhs) {
        a += rhs.a;
        if (a >= get_mod()) {
            a -= get_mod();
        }
        return *this;
    }
    id4& operator-=(const id4 rhs) {
        if (a < rhs.a) {
            a += get_mod();
        }
        a -= rhs.a;
        return *this;
    }
    id4& operator*=(const id4 rhs) {
        a = a * rhs.a % get_mod();
        return *this;
    }
    id4& operator/=(id4 rhs) {
        u64 exp = (id2 ? get_mod() - 1 : get_tot()) - 1;
        while (exp) {
            if (exp % 2) {
                *this *= rhs;
            }
            rhs *= rhs;
            exp /= 2;
        }
        return *this;
    }
    bool operator==(const id4& rhs) const {
        return value() == rhs.value();
    }
    bool operator!=(const id4& rhs) const {
        return !(value() == rhs.value());
    }

    static void set_mod(const u64 x) { mod() = x; }
    static u64 get_mod() { return mod(); }

    static u64 get_tot() {
        static u64 tot = 0;
        if (tot == 0) tot = totient(get_mod());
        return tot;
    }

    friend std::istream& operator>>(std::istream& is, id4& mi) {
        u64 k;
        is >> k;
        mi = k;
        return is;
    }
    friend std::ostream& operator<<(std::ostream& os, const id4& mi) {
        return os << mi.value();
    }
};

V<ll> divisor(ll N) {
    V<ll> res;
    for (ll i = 1; i * i <= N; ++i) {
        if (N % i == 0) {
            res.push_back(i);
            if (N / i != i) res.push_back(N / i);
        }
    }
    sort(all(res));
    return res;
}



struct UnionFind {
    V<int> data;
    UnionFind(int size) : data(size, -1) {}
    bool unite(int x, int y) {
        x = root(x);
        y = root(y);
        if (x != y) {
            if (data[y] < data[x]) std::swap(x, y);
            data[x] += data[y];
            data[y] = x;
        }
        return x != y;
    }
    bool find(int x, int y) {
        return root(x) == root(y);
    }
    int root(int x) {
        return data[x] < 0 ? x : data[x] = root(data[x]);
    }
    int size(int x) {
        return -data[root(x)];
    }
};


template <class T = int>
class Rng {
    std::mt19937 mt;
    std::random_device rnd;
    std::uniform_int_distribution<> uid;
    bool initialized;

  public:
    Rng(){
        mt.seed(rnd());
        initialized = false;
    }
    Rng(T l, T r) {
        mt.seed(rnd());
        uid = std::uniform_int_distribution<>(l, r);
        initialized = true;
    }
    T rand() {
        return (initialized ? uid(mt) : mt());
    }
    T rand(T l, T r){
        return std::uniform_int_distribution<>(l, r)(mt);
    }
};
template <>
class Rng<Real> {
    std::mt19937 mt;
    std::random_device rnd;
    std::uniform_real_distribution<> urd;
    bool initialized = false;

  public:
    Rng(Real l, Real r) {
        mt.seed(rnd());
        urd = std::uniform_real_distribution<>(l, r);
        initialized = true;
    }
    Real rand() {
        if (!initialized) {
            urd = std::uniform_real_distribution<>(0, 1);
            initialized = true;
        }
        return urd(mt);
    }
};









using namespace std;
const ll mod = 1e9 + 7;


const int N = 10;
template <class T>
void prod(V<T>& c, V<T>& a, V<T>& b) {
    const int blk = 5;

    int i1, i2, i3, i4, k1, k2, k3, k4, j1;
    for (int i = 0; i < N; i += blk) {
        i1 = i + 1;
        i2 = i + 2;
        i3 = i + 3;
        i4 = i + 4;

        for (int k = 0; k < N; k += blk) {
            k1 = k + 1;
            k2 = k + 2;
            k3 = k + 3;
            k4 = k + 4;
            for (int j = 0; j < N; j += 2) {
                j1 = j + 1;
                c[i * N + j] += a[i * N + k] * b[k * N + j] % mod;
                c[i * N + j] += a[i * N + k1] * b[k1 * N + j] % mod;
                c[i * N + j] += a[i * N + k2] * b[k2 * N + j] % mod;
                c[i * N + j] += a[i * N + k3] * b[k3 * N + j] % mod;
                c[i * N + j] += a[i * N + k4] * b[k4 * N + j] % mod;
                c[i * N + j] %= mod;

                c[i1 * N + j] += a[i1 * N + k] * b[k * N + j] % mod;
                c[i1 * N + j] += a[i1 * N + k1] * b[k1 * N + j] % mod;
                c[i1 * N + j] += a[i1 * N + k2] * b[k2 * N + j] % mod;
                c[i1 * N + j] += a[i1 * N + k3] * b[k3 * N + j] % mod;
                c[i1 * N + j] += a[i1 * N + k4] * b[k4 * N + j] % mod;
                c[i1 * N + j] %= mod;

                c[i2 * N + j] += a[i2 * N + k] * b[k * N + j] % mod;
                c[i2 * N + j] += a[i2 * N + k1] * b[k1 * N + j] % mod;
                c[i2 * N + j] += a[i2 * N + k2] * b[k2 * N + j] % mod;
                c[i2 * N + j] += a[i2 * N + k3] * b[k3 * N + j] % mod;
                c[i2 * N + j] += a[i2 * N + k4] * b[k4 * N + j] % mod;
                c[i2 * N + j] %= mod;

                c[i3 * N + j] += a[i3 * N + k] * b[k * N + j] % mod;
                c[i3 * N + j] += a[i3 * N + k1] * b[k1 * N + j] % mod;
                c[i3 * N + j] += a[i3 * N + k2] * b[k2 * N + j] % mod;
                c[i3 * N + j] += a[i3 * N + k3] * b[k3 * N + j] % mod;
                c[i3 * N + j] += a[i3 * N + k4] * b[k4 * N + j] % mod;
                c[i3 * N + j] %= mod;

                c[i4 * N + j] += a[i4 * N + k] * b[k * N + j] % mod;
                c[i4 * N + j] += a[i4 * N + k1] * b[k1 * N + j] % mod;
                c[i4 * N + j] += a[i4 * N + k2] * b[k2 * N + j] % mod;
                c[i4 * N + j] += a[i4 * N + k3] * b[k3 * N + j] % mod;
                c[i4 * N + j] += a[i4 * N + k4] * b[k4 * N + j] % mod;
                c[i4 * N + j] %= mod;

                

                c[i * N + j1] += a[i * N + k] * b[k * N + j1] % mod;
                c[i * N + j1] += a[i * N + k1] * b[k1 * N + j1] % mod;
                c[i * N + j1] += a[i * N + k2] * b[k2 * N + j1] % mod;
                c[i * N + j1] += a[i * N + k3] * b[k3 * N + j1] % mod;
                c[i * N + j1] += a[i * N + k4] * b[k4 * N + j1] % mod;
                c[i * N + j1] %= mod;

                c[i1 * N + j1] += a[i1 * N + k] * b[k * N + j1] % mod;
                c[i1 * N + j1] += a[i1 * N + k1] * b[k1 * N + j1] % mod;
                c[i1 * N + j1] += a[i1 * N + k2] * b[k2 * N + j1] % mod;
                c[i1 * N + j1] += a[i1 * N + k3] * b[k3 * N + j1] % mod;
                c[i1 * N + j1] += a[i1 * N + k4] * b[k4 * N + j1] % mod;
                c[i1 * N + j1] %= mod;

                c[i2 * N + j1] += a[i2 * N + k] * b[k * N + j1] % mod;
                c[i2 * N + j1] += a[i2 * N + k1] * b[k1 * N + j1] % mod;
                c[i2 * N + j1] += a[i2 * N + k2] * b[k2 * N + j1] % mod;
                c[i2 * N + j1] += a[i2 * N + k3] * b[k3 * N + j1] % mod;
                c[i2 * N + j1] += a[i2 * N + k4] * b[k4 * N + j1] % mod;
                c[i2 * N + j1] %= mod;

                c[i3 * N + j1] += a[i3 * N + k] * b[k * N + j1] % mod;
                c[i3 * N + j1] += a[i3 * N + k1] * b[k1 * N + j1] % mod;
                c[i3 * N + j1] += a[i3 * N + k2] * b[k2 * N + j1] % mod;
                c[i3 * N + j1] += a[i3 * N + k3] * b[k3 * N + j1] % mod;
                c[i3 * N + j1] += a[i3 * N + k4] * b[k4 * N + j1] % mod;
                c[i3 * N + j1] %= mod;

                c[i4 * N + j1] += a[i4 * N + k] * b[k * N + j1] % mod;
                c[i4 * N + j1] += a[i4 * N + k1] * b[k1 * N + j1] % mod;
                c[i4 * N + j1] += a[i4 * N + k2] * b[k2 * N + j1] % mod;
                c[i4 * N + j1] += a[i4 * N + k3] * b[k3 * N + j1] % mod;
                c[i4 * N + j1] += a[i4 * N + k4] * b[k4 * N + j1] % mod;
                c[i4 * N + j1] %= mod;
            }
        }
    }
}

VV<ll> dbl;
int id0 = 0;

inline void init() {
    dbl = VV<ll>(id0, V<ll>(100, 0));
    for (int i = 0; i <= 8; ++i) dbl[0][i * N + i + 1] = 1;
    dbl[0][9 * N + 1] = dbl[0][9 * N + 0] = 1;
    for (int p = 1; p < id0; ++p) {
        prod(dbl[p], dbl[p - 1], dbl[p - 1]);
    }
}

inline void solve(ll n, ll m) {
    V<ll> A(N * N, 0);
    for (int i = 0; i < N; ++i) A[i * N + i] = 1;

    for (int p = 0, tm = m; p < 20 && tm > 0; ++p, tm /= 2) {
        if (tm % 2 == 0) continue;
        V<ll> B(N * N, 0);
        prod(B, dbl[p], A);
        A = B;
    }

    V<ll> v(N, 0), w(N, 0);
    while (n > 0) v[n % N] += 1, n /= N;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            w[i] += A[j * N + i] * v[j] % mod;
            w[i] %= mod;
        }
    }
    cout << w.sum() % mod << endl;
}

using mint = modint<mod>;
int solution() {
    V<mint> dp(2e5 + 1, 0);
    for (int i = 0; i <= 8; ++i) dp[i] = 2;
    dp[9] = 3;
    for (int i = 10; i <= 2e5; ++i) dp[i] = dp[i - 9] + dp[i - 10];
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        ll n, m;
        cin >> n >> m;
        string s = to_string(n);
        mint ans = 0;
        for (int i = 0; i < s.size(); ++i) {
            int k = m + s[i] - '0';
            if (k < 10)
                ans += 1;
            else
                ans += dp[k - 10];
        }
        cout << ans << endl;
    }
    exit(0);
}

int main() {
    solution();

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    V<ll> i_n(t), i_m(t);
    for (int i = 0; i < t; ++i) cin >> i_n[i] >> i_m[i];
    int k = i_m.max();
    while ((1 << id0) < k) ++id0;
    init();
    for (int i = 0; i < t; ++i) solve(i_n[i], i_m[i]);
}
