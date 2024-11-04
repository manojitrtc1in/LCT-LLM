














































using ll = long long;
using ull = unsigned long long;
using ld = long double;
using PLL = std::pair<ll, ll>;
template<class T> using prique = std::priority_queue<T, std::vector<T>, std::greater<T>>;

template<class T> class infinity {
  public:
    static constexpr T value = std::numeric_limits<T>::max() / 2;
    static constexpr T mvalue = std::numeric_limits<T>::min() / 2;
    static constexpr T max = std::numeric_limits<T>::max();
    static constexpr T min = std::numeric_limits<T>::min();
};


template<class T> constexpr T infinity<T>::value;
template<class T> constexpr T infinity<T>::mvalue;
template<class T> constexpr T infinity<T>::max;
template<class T> constexpr T infinity<T>::min;



template<class T> constexpr T INF = infinity<T>::value;


constexpr ll inf = infinity<ll>::value;
constexpr ld EPS = 1e-8;
constexpr ld PI = 3.1415926535897932384626;

template<class T, class U> std::ostream& operator<<(std::ostream& ost, const std::pair<T, U>& p) {
    return ost << p.first << ' ' << p.second;
}
template<class T, class U> std::istream& operator>>(std::istream& ist, std::pair<T, U>& p) {
    return ist >> p.first >> p.second;
}

template<class Container,
        typename std::enable_if<!std::is_same<Container, std::string>::value>::type* = nullptr>
auto operator<<(std::ostream& ost, const Container& cont)
        -> decltype(cont.begin(), cont.end(), ost)
{
    for (auto itr = cont.begin(); itr != cont.end(); ++itr) {
        if (itr != cont.begin()) ost << ' ';
        ost << *itr;
    }
    return ost;
}
template<class Container,
        typename std::enable_if<!std::is_same<Container, std::string>::value>::type* = nullptr>
auto operator>>(std::istream& ist, Container& cont)
        -> decltype(cont.begin(), cont.end(), ist)
{
    for (auto itr = cont.begin(); itr != cont.end(); ++itr) ist >> *itr;
    return ist;
}

template<class T, class U> inline constexpr bool chmin(T &a, const U &b) noexcept {
    return a > b ? a = b, true : false;
}
template<class T, class U> inline constexpr bool chmax(T &a, const U &b) noexcept {
    return a < b ? a = b, true : false;
}

inline CONSTEXPR ll gcd(ll a, ll b) noexcept {
    while (b) {
        const ll c = a;
        a = b;
        b = c % b;
    }
    return a;
}
inline CONSTEXPR ll lcm(ll a, ll b) noexcept {
    return a / gcd(a, b) * b;
}

inline CONSTEXPR bool is_prime(ll N) noexcept {
    if (N <= 1) return false;
    for (ll i = 2; i * i <= N; ++i) {
        if (N % i == 0) return false;
    }
    return true;
}
inline std::vector<ll> prime_factor(ll N) noexcept {
    std::vector<ll> res;
    for (ll i = 2; i * i <= N; ++i) {
        while (N % i == 0) {
            res.push_back(i);
            N /= i;
        }
    }
    if (N != 1) res.push_back(N);
    return res;
}

inline CONSTEXPR ll my_pow(ll a, ll b) noexcept {
    ll res = 1;
    while (b) {
        if (b & 1) res *= a;
        b >>= 1;
        a *= a;
    }
    return res;
}
inline CONSTEXPR ll mod_pow(ll a, ll b, ll mod) noexcept {
    a %= mod;
    ll res = 1;
    while (b) {
        if (b & 1) (res *= a) %= mod;
        b >>= 1;
        (a *= a) %= mod;
    }
    return res;
}

inline PLL id1(ll a, ll b) noexcept {
    const ll n = a, m = b;
    ll x = 1, y = 0, u = 0, v = 1;
    ll t;
    while (b) {
        t = a / b;
        std::swap(a -= t * b, b);
        std::swap(x -= t * u, u);
        std::swap(y -= t * v, v);
    }
    if (x < 0) {
        x += m;
        y -= n;
    }
    return {x, y};
}
inline ll mod_inv(ll a, ll mod) noexcept {
    ll b = mod;
    ll x = 1, u = 0;
    ll t;
    while (b) {
        t = a / b;
        std::swap(a -= t * b, b);
        std::swap(x -= t * u, u);
    }
    if (x < 0) x += mod;
    assert(a == 1);
    return x;
}
inline PLL id4(ll b1, ll m1, ll b2, ll m2) noexcept {
    const PLL p = id1(m1, m2);
    const ll g = p.first * m1 + p.second * m2;
    const ll l = m1 / g * m2;
    if ((b2 - b1) % g != 0) return PLL{-1, -1};
    const ll x = (b2 - b1) / g * p.first % (m2 / g);
    return {(x * m1 + b1 + l) % l, l};
}
PLL id3(const std::vector<ll>& b, const std::vector<ll>& m) noexcept {
    PLL res{0, 1};
    rep (i, b.size()) {
        res = id4(res.first, res.second, b[i], m[i]);
        if (res.first == -1) return res;
    }
    return res;
}

template<class F> class RecLambda {
  private:
    F f;
  public:
    explicit constexpr RecLambda(F&& f_) : f(std::forward<F>(f_)) {}
    template<class... Args> constexpr auto operator()(Args&&... args) const
            -> decltype(f(*this, std::forward<Args>(args)...)) {
        return f(*this, std::forward<Args>(args)...);
    }
};

template<class F> inline constexpr RecLambda<F> rec_lambda(F&& f) {
    return RecLambda<F>(std::forward<F>(f));
}

template<class Head, class... Tail> struct multi_dim_vector {
    using type = std::vector<typename multi_dim_vector<Tail...>::type>;
};
template<class T> struct multi_dim_vector<T> {
    using type = T;
};

template<class T, class Arg> constexpr std::vector<T> make_vec(int n, Arg&& arg) {
    return std::vector<T>(n, std::forward<Arg>(arg));
}
template<class T, class... Args>
constexpr typename multi_dim_vector<Args..., T>::type make_vec(int n, Args&&... args) {
    return typename multi_dim_vector<Args..., T>::type (n, make_vec<T>(std::forward<Args>(args)...));
}

inline CONSTEXPR int popcnt(ull x) {

    return std::popcount(x);

    x = (x & 0x5555555555555555) + ((x >> 1 ) & 0x5555555555555555);
    x = (x & 0x3333333333333333) + ((x >> 2 ) & 0x3333333333333333);
    x = (x & 0x0f0f0f0f0f0f0f0f) + ((x >> 4 ) & 0x0f0f0f0f0f0f0f0f);
    x = (x & 0x00ff00ff00ff00ff) + ((x >> 8 ) & 0x00ff00ff00ff00ff);
    x = (x & 0x0000ffff0000ffff) + ((x >> 16) & 0x0000ffff0000ffff);
    return (x & 0x00000000ffffffff) + ((x >> 32) & 0x00000000ffffffff);
}

template<class T, class Comp = std::less<T>> class presser {
  protected:
    std::vector<T> dat;
    Comp cmp;
    bool sorted = false;
  public:
    presser() : presser(Comp()) {}
    presser(const Comp& cmp) : cmp(cmp) {}
    presser(const std::vector<T>& vec, const Comp& cmp = Comp()) : dat(vec), cmp(cmp) {}
    presser(std::vector<T>&& vec, const Comp& cmp = Comp()) : dat(std::move(vec)), cmp(cmp) {}
    presser(std::initializer_list<T> il, const Comp& cmp = Comp()) : dat(il.begin(), il.end()), cmp(cmp) {}
    void reserve(int n) {
        assert(!sorted);
        dat.reserve(n);
    }
    void push_back(const T& v) {
        assert(!sorted);
        dat.push_back(v);
    }
    void push_back(T&& v) {
        assert(!sorted);
        dat.push_back(std::move(v));
    }
    void push(const std::vector<T>& vec) {
        assert(!sorted);
        const int n = dat.size();
        dat.resize(n + vec.size());
        rep (i, vec.size()) dat[n + i] = vec[i];
    }
    int build() {
        assert(!sorted); sorted = true;
        std::sort(all(dat), cmp);
        dat.erase(std::unique(all(dat), [&](const T& a, const T& b) -> bool {
            return !cmp(a, b) && !cmp(b, a);
        }), dat.end());
        return dat.size();
    }
    const T& operator[](int k) const& {
        assert(sorted);
        assert(0 <= k && k < (int)dat.size());
        return dat[k];
    }
    T operator[](int k) && {
        assert(sorted);
        assert(0 <= k && k < (int)dat.size());
        return std::move(dat[k]);
    }
    int get_index(const T& val) const {
        assert(sorted);
        return static_cast<int>(std::lower_bound(all(dat), val, cmp) - dat.begin());
    }
    std::vector<int> pressed(const std::vector<T>& vec) const {
        assert(sorted);
        std::vector<int> res(vec.size());
        rep (i, vec.size()) res[i] = get_index(vec[i]);
        return res;
    }
    void press(std::vector<T>& vec) const {
        static_assert(std::is_integral<T>::value, "template argument must be convertible from int type");
        assert(sorted);
        each_for (i : vec) i = get_index(i);
    }
    int size() const {
        assert(sorted);
        return dat.size();
    }
    const std::vector<T>& data() const& { return dat; }
    std::vector<T> data() && { return std::move(dat); }
};




class ModIntBase {};
class StaticModIntBase : ModIntBase {};
class DynamicModIntBase : ModIntBase {};

template<class T> using is_ModInt = std::is_base_of<ModIntBase, T>;
template<class T> using is_StaticModInt = std::is_base_of<StaticModIntBase, T>;
template<class T> using is_DynamicModInt = std::is_base_of<DynamicModIntBase, T>;

template<ll mod> class id0 : StaticModIntBase {
  protected:
    ll val;
    static constexpr ll inv1000000007[] = {-1, 1, 500000004, 333333336, 250000002,
            400000003, 166666668, 142857144, 125000001, 111111112, 700000005};
    static constexpr ll inv998244353 [] = {-1, 1, 499122177, 332748118, 748683265,
            598946612, 166374059, 855638017, 873463809, 443664157, 299473306};
  public:
    id0() : id0(0) {}
    template<class T, typename std::enable_if<std::is_integral<T>::value>::type* = nullptr> id0(T v) : val(v) {
        val %= mod;
        if (val < 0) val += mod;
    }
    ll get() const { return val; }
    static ll get_mod() { return mod; }
    static id0 raw(ll v) {
        id0 res;
        res.val = v;
        return res;
    }
    id0 inv() const {
        if IF_CONSTEXPR (mod == 1000000007) {
            if (val <= 10) return inv1000000007[val];
        }
        else if IF_CONSTEXPR (mod == 998244353) {
            if (val <= 10) return inv998244353[val];
        }
        return mod_inv(val, mod);
    }
    id0& operator++() {
        ++val;
        if (val == mod) val = 0;
        return *this;
    }
    id0 operator++(int) {
        id0 res = *this;
        ++ *this;
        return res;
    }
    id0& operator--() {
        if (val == 0) val = mod;
        --val;
        return *this;
    }
    id0 operator--(int) {
        id0 res = *this;
        -- *this;
        return res;
    }
    id0& operator+=(const id0& other) {
        val += other.val;
        if (val >= mod) val -= mod;
        return *this;
    }
    id0& operator-=(const id0& other) {
        val -= other.val;
        if (val < 0) val += mod;
        return *this;
    }
    id0& operator*=(const id0& other) {
        (val *= other.val) %= mod;
        return *this;
    }
    id0& operator/=(const id0& other) {
        (val *= other.inv().get()) %= mod;
        return *this;
    }
    friend id0 operator+(const id0& lhs, const id0& rhs) {
        return id0(lhs) += rhs;
    }
    friend id0 operator-(const id0& lhs, const id0& rhs) {
        return id0(lhs) -= rhs;
    }
    friend id0 operator*(const id0& lhs, const id0& rhs) {
        return id0(lhs) *= rhs;
    }
    friend id0 operator/(const id0& lhs, const id0& rhs) {
        return id0(lhs) /= rhs;
    }
    id0 operator+() const {
        return id0(*this);
    }
    id0 operator-() const {
        return id0(0) - *this;
    }
    friend bool operator==(const id0& lhs, const id0& rhs) {
        return lhs.val == rhs.val;
    }
    friend bool operator!=(const id0& lhs, const id0& rhs) {
        return lhs.val != rhs.val;
    }
    id0 pow(ll a) const {
        id0 v = *this, res = 1;
        while (a) {
            if (a & 1) res *= v;
            a >>= 1;
            v *= v;
        }
        return res;
    }
    friend std::ostream& operator<<(std::ostream& ost, const id0& sm) {
        return ost << sm.val;
    }
    friend std::istream& operator>>(std::istream& ist, id0& sm) {
        ll v; ist >> v;
        sm = v;
        return ist;
    }
};


template<ll mod> constexpr ll id0<mod>::inv1000000007[];
template<ll mod> constexpr ll id0<mod>::inv998244353 [];


using modint1000000007 = id0<1000000007>;
using modint998244353  = id0<998244353>;

template<int id> class id2 : DynamicModIntBase {
  protected:
    ll val;
    static ll mod;
  public:
    id2() : id2(0) {}
    template<class T, typename std::enable_if<std::is_integral<T>::value>::type* = nullptr> id2(T v) : val(v) {
        val %= mod;
        if (val < 0) val += mod;
    }
    ll get() const { return val; }
    static ll get_mod() { return mod; }
    static void set_mod(ll v) { mod = v; }
    static id2 raw(ll v) {
        id2 res;
        res.val = v;
        return res;
    }
    id2 inv() const { return mod_inv(val, mod); }
    id2& operator++() {
        ++val;
        if (val == mod) val = 0;
        return *this;
    }
    id2 operator++(int) {
        id2 res = *this;
        ++ *this;
        return res;
    }
    id2& operator--() {
        if (val == 0) val = mod;
        --val;
        return *this;
    }
    id2 operator--(int) {
        id2 res = *this;
        -- *this;
        return res;
    }
    id2& operator+=(const id2& other) {
        val += other.val;
        if (val >= mod) val -= mod;
        return *this;
    }
    id2& operator-=(const id2& other) {
        val -= other.val;
        if (val < 0) val += mod;
        return *this;
    }
    id2& operator*=(const id2& other) {
        (val *= other.val) %= mod;
        return *this;
    }
    id2& operator/=(const id2& other) {
        (val *= other.inv().get()) %= mod;
        return *this;
    }
    friend id2 operator+(const id2& lhs, const id2& rhs) {
        return id2(lhs) += rhs;
    }
    friend id2 operator-(const id2& lhs, const id2& rhs) {
        return id2(lhs) -= rhs;
    }
    friend id2 operator*(const id2& lhs, const id2& rhs) {
        return id2(lhs) *= rhs;
    }
    friend id2 operator/(const id2& lhs, const id2& rhs) {
        return id2(lhs) /= rhs;
    }
    id2 operator+() const {
        return id2(*this);
    }
    id2 operator-() const {
        return id2(0) - *this;
    }
    friend bool operator==(const id2& lhs, const id2& rhs) {
        return lhs.val == rhs.val;
    }
    friend bool operator!=(const id2& lhs, const id2& rhs) {
        return lhs.val != rhs.val;
    }
    id2 pow(ll a) const {
        id2 v = *this, res = 1;
        while (a) {
            if (a & 1) res *= v;
            a >>= 1;
            v *= v;
        }
        return res;
    }
    friend std::ostream& operator<<(std::ostream& ost, const id2& dm) {
        return ost << dm.val;
    }
    friend std::istream& operator>>(std::istream& ist, id2& dm) {
        ll v; ist >> v;
        dm = v;
        return ist;
    }
};

template<int id> ll id2<id>::mod = 1000000007;

using modint = id2<-1>;




using namespace std;

using mint = modint998244353;

void solve();

int main() {
    int t; scanf("%d", &t);
    rep (t) solve();
}

void solve() {
    int n, k; scanf("%d%d", &n, &k);
    vector<int> a(n);
    rep (i, n) scanf("%d", &a[i]);
    rep (i, k) {
        if (a[n - 1 - i] > 0) {
            puts("0");
            return;
        }
    }
    rep (i, n) {
        if (a[i] > i) {
            puts("0");
            return;
        }
    }
    rrep (i, n, k) a[i] = a[i - k];
    rrep (i, k) a[i] = 0;
    mint ans = 1;
    rep (i, n) {
        if (a[i] == 0) ans *= min<ll>(i + 1, k + 1);
        else if (a[i] == -1) ans *= i + 1;
    }
    printf("%d\n", ans.get());
}
