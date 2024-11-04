#pragma GCC optimize("Ofast")
#pragma GCC target("avx")
#pragma GCC optimize("unroll-loops")

#define BITSET64 0

#if BITSET64
    #include <bits/cxxabi_forced.h>
    #include <bits/functexcept.h>
    #include <bits/functional_hash.h>
    #include <iosfwd>
    #include <string>
    #pragma push_macro("__SIZEOF_LONG__")
    #pragma push_macro("__cplusplus")
    #define __SIZEOF_LONG__ __SIZEOF_LONG_LONG__
    #define unsigned unsigned long
    #define __cplusplus 201102L
    #define __builtin_popcountl __builtin_popcountll
    #define __builtin_ctzl __builtin_ctzll
    #include <bitset>
    #pragma pop_macro("__cplusplus")
    #pragma pop_macro("__SIZEOF_LONG__")
    #undef unsigned
    #undef __builtin_popcountl
    #undef __builtin_ctzl
#endif

#include "bits/stdc++.h"
#include "ext/pb_ds/assoc_container.hpp"
#include "ext/pb_ds/tree_policy.hpp"



#define int int_fast32_t


#define ll int_fast64_t
#define ull uint_fast64_t
#define ld long double
#define ulll __uint128_t
#define lll __int128

template <typename T>
void ignore_unused(const T &) {}

namespace ExtendedIO {
#ifdef __SIZEOF_INT128__
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
#endif
}  


using namespace ExtendedIO;

namespace Debug {

#define SFINAE(x, ...)             \
    template <class, class = void> \
    struct x : std::false_type {}; \
    template <class T>             \
    struct x<T, std::void_t<__VA_ARGS__>> : std::true_type {}

    SFINAE(DefaultIO, decltype(std::cout << std::declval<T &>()));
    SFINAE(IsTuple, typename std::tuple_size<T>::type);
    SFINAE(Iterable, decltype(std::begin(std::declval<T>())));

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

#ifdef DEBUG
    #define debug(args...)                               \
        {                                                \
            std::string _s = #args;                      \
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

    #define ASSERT(...)       \
        if (not(__VA_ARGS__)) \
        throw runtime_error(#__VA_ARGS__)
#else
    #define debug(...) 0
    #define ASSERT(...) 0
#endif

    constexpr Writer<std::cout> print;
    constexpr Reader<std::cin> read;

}  


using namespace Debug;

namespace CPPDS {

#ifdef PB_DS_ASSOC_CNTNR_HPP
    #define unordered_map gp_hash_table
#endif

#ifdef PB_DS_TREE_POLICY_HPP
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
    

    

    

#endif
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
            static const ull FIXED_RANDOM =
                std::chrono::steady_clock::now().time_since_epoch().count();
            return splitmix64(x + FIXED_RANDOM);
        }

        size_t operator()(std::pair<int, int> p) const {
            static const ull FIXED_RANDOM =
                std::chrono::steady_clock::now().time_since_epoch().count();
            return splitmix64(p.first * 31 + p.second + FIXED_RANDOM);
        }
    };

    template <class Fun>
    class y_combinator_result {
        Fun fun_;

       public:
        template <class T>
        explicit y_combinator_result(T &&fun) : fun_(std::forward<T>(fun)) {}
        template <class... Args>
        decltype(auto) operator()(Args &&... args) {
            return fun_(std::ref(*this), std::forward<Args>(args)...);
        }
    };

    template <class Fun>
    decltype(auto) y_combinator(Fun &&fun) {
        return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun));
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
    constexpr int nttmod = 998244353;
    constexpr int inf = 1e9;
    constexpr ll linf = 3e18;
    constexpr ld pi = acosl(-1.0);
    constexpr ld eps = 1e-9;

    std::mt19937 rng(
        std::chrono::steady_clock::now().time_since_epoch().count());

    [[nodiscard]] ll pwr_mod(ll a, ll n, int MOD = Utility::mod) {
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





auto main() -> signed {
    setIO();
    int TESTS = 1;
    


    auto precompute = [&]() -> void {};

    auto solve = [&](int t) -> void {
        ignore_unused(t);
        int n, q;
        cin >> n >> q;
        vector<int> a(n);
        for (auto &x : a)
            cin >> x;

        struct node {
            int val, freq, l, r;
            bool operator==(node n) {
                return n.val == val && n.freq == freq && n.l == l && n.r == r;
            }
        };

        struct SegTree {
            using T = int;
            


            node ID = {-1, -1, -1, -1};

            vector<vector<int>> loc;

            int get_freq(int id, int l, int r) {
                return lower_bound(begin(loc[id]), end(loc[id]), r + 1) -
                       lower_bound(begin(loc[id]), end(loc[id]), l);
            };

            node combine(node n1, node n2) {
                if (n1 == ID)
                    return n2;
                if (n2 == ID)
                    return n1;
                int l = n1.l;
                int r = n2.r;
                if (n1.val == n2.val)
                    return {n1.val, n1.freq + n2.freq, l, r};
                n1.l = l;
                n2.l = l;
                n1.r = r;
                n2.r = r;
                n1.freq = get_freq(n1.val, l, r);
                n2.freq = get_freq(n2.val, l, r);
                if (n1.freq > n2.freq)
                    return n1;
                return n2;
            }

            node make_node(T val, int i) { return {val, 1, i, i}; }

            vector<node> t;
            int n;

            SegTree(vector<T> &a) {
                this->n = a.size();
                this->loc.resize(n + 1);
                for (int i = 0; i < this->n; ++i)
                    this->loc[a[i]].push_back(i);
                this->t.resize(4 * a.size() + 4);
                _build(1, 0, n - 1, a);
            }

            void update(int i, T val) { _update(1, 0, n - 1, i, val); }
            node query(int l, int r) { return _query(1, 0, n - 1, l, r); }

            void _build(int v, int l, int r, vector<T> &a) {
                if (l == r) {
                    t[v] = make_node(a[l], l);
                    return;
                }
                int mid = (l + r) >> 1;
                _build(v << 1, l, mid, a);
                _build((v << 1) | 1, mid + 1, r, a);
                t[v] = combine(t[(v << 1)], t[(v << 1) | 1]);
            }

            void _update(int v, int l, int r, int idx, T val) {
                if (l == r) {
                    t[v] = make_node(val, l);
                    return;
                }
                int mid = (l + r) >> 1;
                if (idx <= mid)
                    _update(v << 1, l, mid, idx, val);
                else
                    _update((v << 1) | 1, mid + 1, r, idx, val);
                t[v] = combine(t[v << 1], t[(v << 1) | 1]);
            }

            node _query(int v, int tl, int tr, int l, int r) {
                if (l == tl && r == tr)
                    return t[v];
                int tm = (tl + tr) >> 1;
                if (l > tm)
                    return _query((v << 1) | 1, tm + 1, tr, l, r);
                if (tm + 1 > r)
                    return _query(v << 1, tl, tm, l, r);
                return combine(_query(v << 1, tl, tm, l, tm),
                               _query((v << 1) | 1, tm + 1, tr, tm + 1, r));
            }
        };

        SegTree st(a);

        for (int i = 0; i < q; ++i) {
            int l, r;
            cin >> l >> r;
            --l, --r;
            node nd = st.query(l, r);
            int len = r - l + 1;
            if (nd.freq <= (len + 1) / 2) {
                cout << 1 << '\n';
            } else {
                cout << 2 * nd.freq - len << '\n';
            }
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