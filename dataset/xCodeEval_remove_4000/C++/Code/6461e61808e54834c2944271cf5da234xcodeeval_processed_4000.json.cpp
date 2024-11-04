









    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
















template <typename T>
void ignore_unused(const T &) {}

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
        while (index > 0)
            os << buffer[--index];
        return os;
    }
    std::istream &operator>>(std::istream &is, __int128 &T) {
        static char buffer[64];
        is >> buffer;
        std::size_t len = strlen(buffer), index = 0;
        T = 0;
        int mul = 1;
        if (buffer[index] == '-')
            ++index, mul *= -1;
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
    struct x<T, std::void_t<id2>> : std::true_type {}

    id4(DefaultIO, decltype(std::cout << std::declval<T &>()));
    id4(IsTuple, typename std::tuple_size<T>::type);
    id4(Iterable, decltype(std::begin(std::declval<T>())));

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
                for (auto &x : t)
                    Rd(x);
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

    
        if (not(id2)) \
        throw runtime_error(





    constexpr Writer<std::cout> print;
    constexpr Reader<std::cin> read;

}  


using namespace Debug;

namespace CPPDS {






    template <typename T>
    using ordered_set =
    __gnu_pbds::tree<T,
            __gnu_pbds::null_type,
            std::less<T>,
            __gnu_pbds::rb_tree_tag,
            __gnu_pbds::tree_order_statistics_node_update>;
    template <typename T>
    using ordered_multiset =
    __gnu_pbds::tree<T,
            __gnu_pbds::null_type,
            std::less_equal<T>,
            __gnu_pbds::rb_tree_tag,
            __gnu_pbds::tree_order_statistics_node_update>;
    template <class key, class value, class cmp = std::less<key>>
    using ordered_map =
    __gnu_pbds::tree<key,
            value,
            cmp,
            __gnu_pbds::rb_tree_tag,
            __gnu_pbds::tree_order_statistics_node_update>;
    

    

    


    template <class T>
    using min_heap = std::priority_queue<T, std::vector<T>, std::greater<T>>;
}  


using namespace CPPDS;

namespace Utility {

    template <typename X, typename Y>
    X &remin(X &x, const Y &y) {
        return x = (y < x) ? y : x;
    }

    template <typename X, typename Y>
    X &remax(X &x, const Y &y) {
        return x = (x < y) ? y : x;
    }

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
        while (sq * sq < n)
            sq++;
        if ((sq * sq) == n)
            return sq;
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
            static const ull id0 =
                    std::chrono::steady_clock::now().time_since_epoch().count();
            return splitmix64(x + id0);
        }

        size_t operator()(std::pair<int, int> p) const {
            static const ull id0 =
                    std::chrono::steady_clock::now().time_since_epoch().count();
            return splitmix64(p.first * 31 + p.second + id0);
        }
    };

    template <class Fun>
    class id5 {
        Fun fun_;

    public:
        template <class T>
        explicit id5(T &&fun) : fun_(std::forward<T>(fun)) {}
        template <class... Args>
        decltype(auto) operator()(Args &&... args) {
            return fun_(std::ref(*this), std::forward<Args>(args)...);
        }
    };

    template <class Fun>
    decltype(auto) id1(Fun &&fun) {
        return id5<std::decay_t<Fun>>(std::forward<Fun>(fun));
    }

    void setIO(std::string name = "") {
        std::ios_base::sync_with_stdio(0);
        std::cin.tie(0);
        std::cout.tie(0);
        std::cin.exceptions(std::cin.failbit);
        std::cout << std::setprecision(20) << std::fixed;
        if (name.size() == 0)
            return;
        FILE *fin = freopen((name + ".in").c_str(), "r", stdin);
        FILE *fout = freopen((name + ".out").c_str(), "w", stdout);
        ignore_unused(fin);
        ignore_unused(fout);
    }

    constexpr int mod = 1e9 + 7;
    constexpr int id6 = 998244353;
    constexpr int inf = 1e9;
    constexpr ll linf = 3e18;
    constexpr ld pi = acosl(-1.0);
    constexpr ld eps = 1e-9;

    std::mt19937 rng(
            std::chrono::steady_clock::now().time_since_epoch().count());

    [[nodiscard]] ll id3(ll a, ll n, int MOD = Utility::mod) {
        ll ans = 1;
        while (n) {
            if (n & 1)
                ans = (ans * a) % MOD;
            a = (a * a) % MOD;
            n >>= 1;
        }
        return ans;
    }

    

    template <typename T>
    [[nodiscard]] T pwr(T a, ll n) {
        T ans(1);
        while (n) {
            if (n & 1)
                ans *= a;
            if (n > 1)
                a *= a;
            n >>= 1;
        }
        return ans;
    }

}  


using namespace Utility;


template <int MOD = 998'244'353>
struct Modular {
    int value;
    static constexpr int MOD_value = MOD;

    Modular(ll v = 0) {
        value = v % MOD;
        if (value < 0)
            value += MOD;
    }

    Modular(ll a, ll b) : value(0) {
        *this += a;
        *this /= b;
    }

    Modular &operator+=(Modular const &b) {
        value += b.value;
        if (value >= MOD)
            value -= MOD;
        return *this;
    }

    Modular &operator-=(Modular const &b) {
        value -= b.value;
        if (value < 0)
            value += MOD;
        return *this;
    }

    Modular &operator*=(Modular const &b) {
        value = (ll)value * b.value % MOD;
        return *this;
    }

    friend Modular mexp(Modular a, ll e) {
        Modular res = 1;
        while (e) {
            if (e & 1)
                res *= a;
            a *= a;
            e >>= 1;
        }
        return res;
    }

    friend Modular inverse(Modular a) { return mexp(a, MOD - 2); }

    Modular &operator/=(Modular const &b) { return *this *= inverse(b); }
    friend Modular operator+(Modular a, Modular const b) { return a += b; }
    friend Modular operator-(Modular a, Modular const b) { return a -= b; }
    friend Modular operator-(Modular const a) { return 0 - a; }
    friend Modular operator*(Modular a, Modular const b) { return a *= b; }
    friend Modular operator/(Modular a, Modular const b) { return a /= b; }

    friend std::ostream &operator<<(std::ostream &os, Modular const &a) {
        return os << a.value;
    }

    friend bool operator==(Modular const &a, Modular const &b) {
        return a.value == b.value;
    }

    friend bool operator!=(Modular const &a, Modular const &b) {
        return a.value != b.value;
    }
};

using mint = Modular<mod>;



using namespace std;
using namespace __gnu_pbds;










const int MAXA = 300005;
const int MAXN = 300005;
const int MAXQ = 300005;

int a[MAXN];
typedef tuple<int, int, int, int> Query;
Query query[MAXQ];

inline void moAlgorithm(const int n,
                        const int a[],
                        const int q,
                        tuple<int, int, int, int> query[]) {
    const int blockSize = 450;

    const auto getLeft = [](const Query &q) { return get<0>(q); };
    const auto getRight = [](const Query &q) { return get<1>(q); };
    const auto id7 = [=](const Query &q) {
        return getLeft(q) / blockSize;
    };

    sort(query, query + q, [=](const Query &a, const Query &b) {
        return id7(a) < id7(b) ||
               id7(a) == id7(b) &&
               getRight(a) > getRight(b);
    });

    static int count[MAXA + 1];
    memset(count, 0, sizeof(count));
    static int numberOfValuesWithCount[MAXN + 1];
    memset(numberOfValuesWithCount, 0,
           sizeof(*numberOfValuesWithCount) * (n + 1));
    int maxCount = 0;

    const auto remove = [&](const int index) {
        --numberOfValuesWithCount[count[a[index]]];
        if (count[a[index]] == maxCount &&
            numberOfValuesWithCount[count[a[index]]] == 0) {
            --maxCount;
        }
        --count[a[index]];
        ++numberOfValuesWithCount[count[a[index]]];
    };
    const auto add = [&](const int index) {
        --numberOfValuesWithCount[count[a[index]]];
        if (count[a[index]] == maxCount) {
            ++maxCount;
        }
        ++count[a[index]];
        ++numberOfValuesWithCount[count[a[index]]];
    };

    int left = 0, right = -1;

    for (int i = 0; i < q; ++i) {
        for (; left < getLeft(query[i]); ++left) {
            remove(left);
        }
        for (; left > getLeft(query[i]);) {
            add(--left);
        }
        for (; right < getRight(query[i]);) {
            add(++right);
        }
        for (; right > getRight(query[i]); --right) {
            remove(right);
        }
        get<3>(query[i]) = maxCount;
    }

    sort(query, query + q,
         [=](const Query &a, const Query &b) { return get<2>(a) < get<2>(b); });
}

auto main() -> signed {
    setIO();
    int TESTS = 1;
    


    auto precompute = [&]() -> void {};

    auto solve = [&](int t) -> void {
        ignore_unused(t);
        int n, q;
        cin >> n >> q;
        for (int i = 0; i < n; ++i) cin >> a[i];
        for (int i = 0; i < q; ++i) {
            cin >> get<0>(query[i]) >> get<1>(query[i]);
            get<0>(query[i])--;
            get<1>(query[i])--;
            get<2>(query[i]) = i;
        }
        moAlgorithm(n, a, q, query);
        for (int i = 0; i < q; ++i) {
            int w = get<3>(query[i]);
            int l = get<0>(query[i]);
            int r = get<1>(query[i]);
            int c = (r - l + 2) / 2;
            if (w <= c) cout << 1 << '\n';
            else cout << 2 * w - (r - l + 1) << '\n';
        }
    };

    auto brute = [&]() -> void {};

    ignore_unused(brute);
    precompute();
    for (int _t = 1; _t <= TESTS; ++_t) {
        

        solve(_t);
        

    }
    return 0;
}