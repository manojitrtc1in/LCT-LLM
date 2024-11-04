










    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    










template <typename T>
void ignore_unused(const T &) {}




using ll = long long;
using ull = unsigned long long;
using ld = long double;

using ulll = __uint128_t;
using lll = __int128;

namespace ExtendedIO {

    std::ostream &operator<<(std::ostream &os, __int128 const &value) {
        static char buffer[64];
        int index = 0;
        __uint128_t T = (value < 0) ? (-(value + 1)) + __uint128_t(1) : value;
        if (value < 0)
            os << '-';
        else if (T == 0)
            return os << '0';
        for (; T > 0; ++index) {
            buffer[index] = static_cast<char>('0' + (T % 10));
            T /= 10;
        }
        while (index > 0) os << buffer[--index];
        return os;
    }
    std::istream &operator>>(std::istream &is, __int128 &T) {
        static char buffer[64];
        is >> buffer;
        std::size_t len = strlen(buffer), index = 0;
        T = 0;
        int mul = 1;
        if (buffer[index] == '-') ++index, mul *= -1;
        for (; index < len; ++index)
            T = T * 10 + static_cast<int>(buffer[index] - '0');
        T *= mul;
        return is;
    }

}  


using namespace ExtendedIO;

namespace Debug {


    template <class, class = void> \
    struct x : std::false_type {}; \
    template <class T>             \
    struct x<T, std::void_t<id5>> : std::true_type {}

    id7(DefaultIO, decltype(std::cout << std::declval<T &>()));
    id7(IsTuple, typename std::tuple_size<T>::type);
    id7(Iterable, decltype(std::begin(std::declval<T>())));

    template <class T>
    constexpr char Space(const T &) {
        return (Iterable<T>::value or IsTuple<T>::value) ? '\n' : ' ';
    }

    template <auto &os>
    struct Writer {
        template <class T>
        void Impl(T const &t) const {
            if constexpr (DefaultIO<T>::value)
                os << t;
            else if constexpr (Iterable<T>::value) {
                int i = 0;
                for (auto &&x : t)
                    ((i++) ? (os << Space(x), Impl(x)) : Impl(x));
            } else if constexpr (IsTuple<T>::value)
                std::apply(
                    [this](auto const &... args) {
                        int i = 0;
                        (((i++) ? (os << ' ', Impl(args)) : Impl(args)), ...);
                    },
                    t);
            else
                static_assert(IsTuple<T>::value, "No matching type for print");
        }
        template <class F, class... Ts>
        auto &operator()(F const &f, Ts const &... ts) const {
            return Impl(f), ((os << ' ', Impl(ts)), ...), os << '\n', *this;
        }
    };

    template <auto &is>
    struct Reader {
        template <class T>
        auto &Rd(T &t) const {
            if constexpr (DefaultIO<T>::value)
                is >> t;
            else if constexpr (Iterable<T>::value)
                for (auto &x : t) Rd(x);
            else if constexpr (IsTuple<T>::value)
                std::apply([this](auto &... args) { (Rd(args), ...); }, t);
            else
                static_assert(IsTuple<T>::value, "No matching type for read");
            return *this;
        }
        template <class T>
        auto operator()(T t) const {
            Rd(t);
            return t;
        }
    };


    
        {                                                \
            std::string _s = 
            replace(_s.begin(), _s.end(), ',', ' ');     \
            std::stringstream _ss(_s);                   \
            std::istream_iterator<std::string> _it(_ss); \
            std::cerr << "Line " << __LINE__ << "\n";    \
            err(_it, args);                              \
        }

    void err(std::istream_iterator<std::string> it) { ignore_unused(it); }

    template <typename T, typename... Args>
    void err(std::istream_iterator<std::string> it, T a, Args... args) {
        std::cerr << "\033[0;31m" << *it << " = ";
        Writer<std::cerr>{}(a);
        std::cerr << "\033[0m";
        err(++it, args...);
    }

    
        if (not(id5)) throw runtime_error(

    
    


    constexpr Writer<std::cout> print;
    constexpr Reader<std::cin> read;

}  


using namespace Debug;

namespace CPPDS {


    



    template <typename T>
    using ordered_set =
        __gnu_pbds::tree<T, __gnu_pbds::null_type, std::less<T>,
                         __gnu_pbds::rb_tree_tag,
                         __gnu_pbds::tree_order_statistics_node_update>;
    template <typename T>
    using ordered_multiset =
        __gnu_pbds::tree<T, __gnu_pbds::null_type, std::less_equal<T>,
                         __gnu_pbds::rb_tree_tag,
                         __gnu_pbds::tree_order_statistics_node_update>;
    template <class key, class value, class cmp = std::less<key>>
    using ordered_map =
        __gnu_pbds::tree<key, value, cmp, __gnu_pbds::rb_tree_tag,
                         __gnu_pbds::tree_order_statistics_node_update>;
    

    

    


    template <class T>
    using min_heap = std::priority_queue<T, std::vector<T>, std::greater<T>>;
}  


using namespace CPPDS;

namespace Utility {

    void setIO(std::string name = "") {
        std::ios_base::sync_with_stdio(0);
        std::cin.tie(0);
        std::cout.tie(0);
        std::cin.exceptions(std::cin.failbit);
        std::cout << std::setprecision(20) << std::fixed;
        if (name.size() == 0) return;
        ignore_unused(freopen((name + ".in").c_str(), "r", stdin));
        ignore_unused(freopen((name + ".out").c_str(), "w", stdout));
    }

    constexpr int mod = int(1e9) + 7;
    constexpr int id11 = 998244353;
    constexpr int inf = int(1e9);
    constexpr ll linf = ll(3e18L);
    constexpr ld eps = 1e-9;
    ld pi = acosl(-1.0);

    std::mt19937 rng(
        std::chrono::steady_clock::now().time_since_epoch().count());

    template <typename C = std::chrono::steady_clock,
              typename T1 = std::chrono::nanoseconds,
              typename T2 = std::chrono::milliseconds>
    struct Stopwatch {
        std::string name;
        std::chrono::time_point<C> id8;
        T1 elapsed_time;
        bool running;
        Stopwatch(const std::string &s) : name(s), running(true) { reset(); }
        Stopwatch() : Stopwatch("Time") {}
        void reset() {
            id8 = C::now();
            elapsed_time = T1::zero();
        }
        void pause() {
            if (!running) return;
            running = false;
            elapsed_time +=
                std::chrono::duration_cast<T1>(C::now() - id8);
        }
        void play() {
            if (running) return;
            running = true;
            id8 = C::now();
        }
        int_fast64_t elapsed() const {
            return std::chrono::duration_cast<T2>(
                       elapsed_time + (running ? std::chrono::duration_cast<T1>(
                                                     C::now() - id8)
                                               : T1::zero()))
                .count();
        }
        void print() const {

            std::cerr << name << ": " << elapsed() << " ms\n";

        }
        ~Stopwatch() { print(); }
    };

    template <class T, class U = T>
    bool ckmin(T &a, U &&b) {
        return b < a ? a = std::forward<U>(b), true : false;
    }

    template <class T, class U = T>
    bool ckmax(T &a, U &&b) {
        return a < b ? a = std::forward<U>(b), true : false;
    }

    template <typename T>
    inline T sq(T a) {
        return a * a;
    }

    template <typename T>
    inline T sq_dist(std::pair<T, T> &a, std::pair<T, T> &b) {
        return sq(a.first - b.first) + sq(a.second - b.second);
    }

    template <typename T>
    inline ld dist(std::pair<T, T> &a, std::pair<T, T> &b) {
        return sqrtl(sq_dist(a, b));
    }

    inline ll isqrt(ll n) {
        ll sq = (ll)sqrtl((ld)n) - 2;
        sq = std::max(sq, ll(0));
        while (sq * sq < n) sq++;
        if ((sq * sq) == n) return sq;
        return sq - 1;
    }

    inline bool is_sq(ll n) {
        ll w = isqrt(n);
        return w * w == n;
    }

    struct custom_hash {
        

        static ull splitmix64(ull x) {
            x += 0x9e3779b97f4a7c15;
            x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
            x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
            return x ^ (x >> 31);
        }

        size_t operator()(ull x) const {
            static const ull id2 =
                std::chrono::steady_clock::now().time_since_epoch().count();
            return splitmix64(x + id2);
        }

        size_t operator()(std::pair<int, int> p) const {
            static const ull id2 =
                std::chrono::steady_clock::now().time_since_epoch().count();
            return splitmix64(p.first * 31 + p.second + id2);
        }
    };

    template <class Fun>
    class id10 {
        Fun fun_;

       public:
        template <class T>
        explicit id10(T &&fun) : fun_(std::forward<T>(fun)) {}
        template <class... Args>
        decltype(auto) operator()(Args &&... args) {
            return fun_(std::ref(*this), std::forward<Args>(args)...);
        }
    };

    template <class Fun>
    decltype(auto) id3(Fun &&fun) {
        return id10<std::decay_t<Fun>>(std::forward<Fun>(fun));
    }

    template <typename T>
    struct Range {
        struct It {
            T i;
            const T skip;
            void operator++() { i += skip; }
            T operator*() const { return i; }
            bool operator!=(It o) const {
                return (skip >= 0) ? (i < *o) : (i > *o);
            }
        };
        const T l_, r_, skip_;
        Range(T l, T r, T skip = 1) : l_(l), r_(r), skip_(skip) {

            assert(skip != 0);

        }
        Range(T n) : Range(T(0), n, T(1)) {}
        It begin() const {
            return (skip_ >= 0) ? It{l_, skip_} : It{r_ - 1, skip_};
        }
        It end() const {
            return (skip_ >= 0) ? It{r_, skip_} : It{l_ - 1, skip_};
        }
    };

    

    template <typename T>
    [[nodiscard]] T pwr(T a, ll n) {
        T ans(1);
        while (n) {
            if (n & 1) ans *= a;
            if (n > 1) a *= a;
            n >>= 1;
        }
        return ans;
    }

    template <typename I, typename P, bool b>
    I id0(I l, I r, const P &predicate) {
        --l, ++r;
        while (r - l > 1) {
            

            auto mid = l + (r - l) / 2;
            if (predicate(mid))
                r = mid;
            else
                l = mid;
        }
        if constexpr (b)
            return r;
        else
            return l;
    }

    

    template <typename I, typename P>
    I first_true(I l, I r, const P &p) {
        return id0<I, P, true>(l, r, p);
    }

    

    template <typename I, typename P>
    I last_false(I l, I r, const P &p) {
        return id0<I, P, false>(l, r, p);
    }

}  


using namespace Utility;



template <uint32_t Modulus>
class Modular {
    using M = Modular;

   public:
    static_assert(int(Modulus) >= 1, "Modulus must be in the range [1, 2^31)");
    static constexpr int modulus() { return Modulus; }
    static M raw(uint32_t v) { return *reinterpret_cast<M *>(&v); }
    Modular() : v_(0) {}
    Modular(int64_t v) : v_((v %= Modulus) < 0 ? v + Modulus : v) {}
    template <class T>
    explicit operator T() const {
        return v_;
    }
    M &operator++() { return v_ = ++v_ == Modulus ? 0 : v_, *this; }
    M &operator--() { return --(v_ ? v_ : v_ = Modulus), *this; }
    M &operator*=(M o) { return v_ = uint64_t(v_) * o.v_ % Modulus, *this; }
    M &operator/=(M o) {
        auto [inv, gcd] = extgcd(o.v_, Modulus);
        assert(gcd == 1);
        return *this *= inv;
    }
    M &operator+=(M o) {
        return v_ = int(v_ += o.v_ - Modulus) < 0 ? v_ + Modulus : v_, *this;
    }
    M &operator-=(M o) {
        return v_ = int(v_ -= o.v_) < 0 ? v_ + Modulus : v_, *this;
    }
    friend M operator++(M &a, int) { return exchange(a, ++M(a)); }
    friend M operator--(M &a, int) { return exchange(a, --M(a)); }
    friend M operator+(M a) { return a; }
    friend M operator-(M a) { return a.v_ = a.v_ ? Modulus - a.v_ : 0, a; }
    friend M operator*(M a, M b) { return a *= b; }
    friend M operator/(M a, M b) { return a /= b; }
    friend M operator+(M a, M b) { return a += b; }
    friend M operator-(M a, M b) { return a -= b; }
    friend std::istream &operator>>(std::istream &is, M &x) {
        int64_t v;
        return is >> v, x = v, is;
    }
    friend std::ostream &operator<<(std::ostream &os, M x) {
        return os << x.v_;
    }
    friend bool operator==(M a, M b) { return a.v_ == b.v_; }
    friend bool operator!=(M a, M b) { return a.v_ != b.v_; }

   private:
    static std::pair<int, int> extgcd(int a, int b) {
        std::array<int, 2> x{1, 0};
        while (b) std::swap(x[0] -= a / b * x[1], x[1]), std::swap(a %= b, b);
        return {x[0], a};
    }
    uint32_t v_;
};

using mint = Modular<mod>;



using namespace std;
using namespace __gnu_pbds;





template <bool is_lazy = true>
struct id6 {
    struct node_t {
        int e;
        int freq;
    };

    using base_t = int;
    using update_t = int;

    

    node_t combine(const node_t &n1, const node_t &n2) {
        if (n1.e == n2.e) return {n1.e, n1.freq + n2.freq};
        else if (n1.freq > n2.freq) return {n1.e, n1.freq - n2.freq};
        else return {n2.e, n2.freq - n1.freq};
    }

    

    node_t make_node(const base_t &val, int l, int r) { return {val, 1}; }

    

    node_t id_node() { return {0, 0}; }

    

    node_t apply_update_single(const update_t &u, const node_t &nd) {
        

        return {};
    }

    

    update_t id_update() { return -1; }

    

    node_t apply_update(const update_t &u, const node_t &nd) {
        if (u == id_update()) return nd;  

        return {u * nd.sz, nd.sz};
    }

    

    update_t compose_updates(const update_t &u, const update_t &v) {
        if (u == id_update()) return v;
        return u;
    }

    std::vector<node_t> t;
    std::vector<update_t> lazy;
    int n;

    id6(std::vector<base_t> &a) {
        this->n = a.size();
        if (this->n == 0) return;
        this->t.assign(4 * a.size(), id_node());
        if constexpr (is_lazy) {
            this->lazy.assign(2 * a.size(), id_update());
        }
        _build(1, 0, n, a);
    }

    

    void update(int l, int r, const update_t &u) {
        if constexpr (!is_lazy) assert(l == r - 1);
        _update(1, 0, n, l, r, u);
    }
    node_t query(int l, int r) { return _query(1, 0, n, l, r); }

    

    

    

    

    template <bool b = is_lazy, typename F>
    int id9(int l, const F &f) {
        auto acc = id_node();
        assert(f(acc));
        auto i = id1<b, F>(1, 0, n, l, n, f, acc);
        if (i == -1) return n;
        return i;
    }

    

    void _pullUp(int v) { t[v] = combine(t[2 * v], t[2 * v + 1]); }
    void _updateNode(int v, const update_t &u) {
        if constexpr (is_lazy) {
            t[v] = apply_update(u, t[v]);
            if (v < (int)lazy.size()) lazy[v] = compose_updates(u, lazy[v]);
        } else
            t[v] = apply_update_single(u, t[v]);
    }
    void _pushDown(int v) {
        if constexpr (is_lazy) {
            

            if (lazy[v] == id_update()) return;
            _updateNode(2 * v, lazy[v]);
            _updateNode(2 * v + 1, lazy[v]);
            lazy[v] = id_update();
        }
    }

    

    void _build(int v, int l, int r, const std::vector<base_t> &a) {
        if (l == r - 1) {
            t[v] = make_node(a[l], l, r);
            return;
        }
        int mid = (l + r) / 2;
        _build(2 * v, l, mid, a);
        _build(2 * v + 1, mid, r, a);
        _pullUp(v);
    }

    void _update(int v, int l, int r, int ql, int qr, const update_t &u) {
        if (qr <= l || r <= ql) return;  

        if (ql <= l && r <= qr) {        

            _updateNode(v, u);
            return;
        }
        _pushDown(v);
        int mid = (l + r) / 2;
        _update(2 * v, l, mid, ql, qr, u);
        _update(2 * v + 1, mid, r, ql, qr, u);
        _pullUp(v);
    }

    node_t _query(int v, int l, int r, int ql, int qr) {
        if (qr <= l || r <= ql) return id_node();  

        if (ql <= l && r <= qr) return t[v];       

        _pushDown(v);
        int mid = (l + r) / 2;
        return combine(_query(2 * v, l, mid, ql, qr),
                       _query(2 * v + 1, mid, r, ql, qr));
    }

    

    

    

    

    template <bool b = true, typename F>
    int id1(int v, int l, int r, int ql, int qr, const F &f,
                           node_t &acc) {
        if (r <= ql) return -1;
        if (qr <= l) return l;
        auto new_acc = combine(acc, t[v]);
        if (ql <= l && r <= qr && f(new_acc)) {
            acc = new_acc;
            return -1;
        }
        if (l == r - 1) return l;
        if constexpr (b) _pushDown(v);
        int mid = (r + l) / 2;
        auto res = id1<b, F>(2 * v, l, mid, ql, qr, f, acc);
        if (res != -1)
            return res;
        else
            return id1<b, F>(2 * v + 1, mid, r, ql, qr, f, acc);
    }
};

auto main() -> signed {

    IO::IOinit();

    setIO();

    int TESTS = 1;
    


    auto precompute = [&]() -> void {
    };

    auto solve = [&](int) -> void {
        Stopwatch stopwatch;
        int n, q;
        cin >> n >> q;
        vector<int> a(n);
        for (auto &x : a) cin >> x;
        vector<vector<int>> loc(1 + *max_element(begin(a), end(a)));
        for (auto i : Range(n)) loc[a[i]].push_back(i);
        auto get_freq = [&](int x, int l, int r) {
            return int(lower_bound(begin(loc[x]), end(loc[x]), r) -
                       lower_bound(begin(loc[x]), end(loc[x]), l));
        };
        id6<false> st(a);
        for (int i = 0; i < q; ++i) {
            int l, r;
            cin >> l >> r;
            --l;
            int id4 = st.query(l, r).e;
            cout << max(1, 2 * get_freq(id4, l, r) - r + l) << '\n';
        }
    };

    auto brute = [&]() -> void {
    };

    ignore_unused(brute);
    precompute();
    for (int _t = 1; _t <= TESTS; ++_t) {
        

        solve(_t);
        

    }
    return 0;
}
