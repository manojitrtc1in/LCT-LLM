#define DISABLE_PRAGMA_
#ifndef DISABLE_PRAGMA_
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,tune=native")
#endif

#include <bits/stdc++.h>
#ifdef __GNUG__


#endif


template <class Tp>
using pi = std::pair<Tp, Tp>;
template <class Tp>
using pi3 = std::tuple<Tp, Tp, Tp>;
template <class Tp>
using pi4 = std::tuple<Tp, Tp, Tp, Tp>;
template <class Tp>
using vc = std::vector<Tp>;
template <class Tp>
using vvc = std::vector<std::vector<Tp>>;
template <class Tp>
using pq = std::priority_queue<Tp>;
template <class Tp>
using pqg = std::priority_queue<Tp, std::vector<Tp>, std::greater<Tp>>;




struct CustomHash {
    static constexpr uint64_t splitmix64(uint64_t x) {
        

        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    static constexpr size_t append(size_t x, size_t y) { return x ^ (y >> 1) ^ ((y & 1) << (sizeof(size_t) * 8 - 1)); }

    inline size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = std::chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }

    template <class Tp, class Up>
    inline size_t operator()(std::pair<Tp, Up> const &p) const { return append((*this)(p.first), (*this)(p.second)); }

    template <typename... Ts>
    inline size_t operator()(std::tuple<Ts...> const &tp) const {
        size_t ret = 0;
        std::apply([&](Ts const &...targs) { ((ret = append(ret, (*this)(targs))), ...); }, tp);
        return ret;
    }

    template <class Tp, std::enable_if_t<std::is_same_v<decltype(std::declval<Tp>().begin()), typename Tp::iterator> && std::is_same_v<decltype(std::declval<Tp>().end()), typename Tp::iterator>> * = nullptr>
    inline size_t operator()(Tp const &tp) const {
        size_t ret = 0;
        for (auto &&i : tp) ret = append(ret, (*this)(i));
        return ret;
    }
};

template <class Tp, class Hash = CustomHash>
using hset = std::unordered_set<Tp, Hash>;
template <class Key, class Tp, class Hash = CustomHash>
using hmap = std::unordered_map<Key, Tp, Hash>;


using i32 = int32_t;
using u32 = uint32_t;
using i64 = int64_t;
using u64 = uint64_t;
using i128 = __int128_t;
using u128 = __uint128_t;

using compi = std::complex<int>;
using compi64 = std::complex<i64>;
using compd = std::complex<double>;
using pii = pi<int>;
using pii64 = pi<i64>;
using pi3i = pi3<int>;
using pi3i64 = pi3<i64>;
using pi4i = pi4<int>;
using pi4i64 = pi4<i64>;


#define for_(i, l, r, vars...) for (std::make_signed_t<decltype(l + r)> i = (l), i##end = (r), ##vars; i <= i##end; ++i)
#define for_step_(i, l, r, s, vars...) for (std::make_signed_t<decltype(l + r)> i = (l), i##end = (r), ##vars; i <= i##end; i += s)
#define rfor_(i, r, l, vars...) for (std::make_signed_t<decltype(r - l)> i = (r), i##end = (l), ##vars; i >= i##end; --i)
#define rfor_step_(i, r, l, s, vars...) for (std::make_signed_t<decltype(r - l)> i = (r), i##end = (l), ##vars; i >= i##end; i -= s)
#define foreach_val_(i, container) for (auto i : (container))
#define foreach_ref_(i, container) for (auto &i : (container))
#define foreach_cref_(i, container) for (const auto &i : (container))
#define foreach_rref_(i, container) for (auto &&i : (container))
#define foreach_binding_(container, vars...) for (auto &&[vars] : container)
#define foreach_iter_(it, container) for (auto it = (container).begin(); it != (container).end(); ++it)
#define foreach_iter_range_(it, container, l, r) for (auto it = (container).begin() + (l); it != (container).begin() + (r); ++it)
#define foreach_riter_(it, container) for (auto it = (container).rbegin(); it != (container).rend(); ++it)
#define foreach_riter_range_(it, container, l, r) for (auto it = (container).rbegin() + (l); it != (container).rbegin() + (r); ++it)
#define ins_(a) std::inserter((a), (a).begin())
#define all_(a) (a).begin(), (a).end()
#define rall_(a) (a).rbegin(), (a).rend()
#define range_(a, l, r) ((a).begin() + (l)), ((a).begin() + (r))
#define rrange_(a, l, r) ((a).rbegin() + (l)), ((a).rbegin() + (r))
#define set_nul_(a) memset(a, 0, sizeof(a))
#define set_inf_(a) memset(a, 0x3f, sizeof(a))
#define set_nul_n_(a, n) memset(a, 0, sizeof(*(a)) * (n))
#define set_inf_n_(a, n) memset(a, 0x3f, sizeof(*(a)) * (n))
#define run_exec_(expressions, post_process) \
    {                                        \
        expressions;                         \
        post_process;                        \
    }
#define run_exit_(expressions) run_exec_(expressions, exit(0))
#define run_return_(expressions, val) run_exec_(expressions, return val)
#define run_return_void_(expressions) run_exec_(expressions, return )
#define run_break_(expressions) run_exec_(expressions, break)
#define run_continue_(expressions) run_exec_(expressions, continue)
#define read_var_(type, name) \
    type name;                \
    std::cin >> name
#define read_container_(type, name, size) \
    type name(size);                      \
    foreach_ref_(i, name) std::cin >> i
#define intlt2str_(s) STR_____(s)
#define STR_____(s) #s
#define REif_(expression) \
    if (expression) throw std::runtime_error("Line " intlt2str_(__LINE__) ": やだもやだ、無理も無理〜")

template <class Tp>
constexpr auto chkmin(Tp &a, Tp b) -> bool { return b < a ? a = b, true : false; }
template <class Tp>
constexpr auto chkmax(Tp &a, Tp b) -> bool { return a < b ? a = b, true : false; }
template <class Tp>
constexpr auto ispow2(Tp i) -> bool { return i && (i & -i) == i; }




#define TPL_SIZE_(Tuple) std::tuple_size_v<std::remove_reference_t<Tuple>>

namespace tuple_detail_ {
template <std::size_t Begin, class Tuple, std::size_t... Is>
constexpr auto subtuple_impl_(Tuple &&t, std::index_sequence<Is...>) { return std::make_tuple(std::get<Is + Begin>(t)...); }
template <class Tuple, class BinOp, std::size_t... Is>
constexpr auto apply2_impl_(BinOp &&f, Tuple &&lhs, Tuple &&rhs, std::index_sequence<Is...>) { return std::make_tuple(std::forward<BinOp>(f)(std::get<Is>(lhs), std::get<Is>(rhs))...); }
}  



template <std::size_t Begin, std::size_t Len, class Tuple>
constexpr auto subtuple(Tuple &&t) {
    static_assert(Begin <= TPL_SIZE_(Tuple) && Len <= TPL_SIZE_(Tuple) && Begin + Len <= TPL_SIZE_(Tuple), "Out of range");
    return tuple_detail_::subtuple_impl_<Begin>(t, std::make_index_sequence<Len>());
}

template <std::size_t Pos, class Tp, class Tuple>
constexpr auto tuple_push(Tp &&v, Tuple &&t) {
    static_assert(TPL_SIZE_(Tuple) > 0, "Pop from empty tuple");
    return std::tuple_cat(subtuple<0, Pos>(t), std::make_tuple(v), subtuple<Pos, TPL_SIZE_(Tuple) - Pos>(t));
}
template <class Tp, class Tuple>
constexpr auto tuple_push_front(Tp &&v, Tuple &&t) { return tuple_push<0>(v, t); }
template <class Tp, class Tuple>
constexpr auto tuple_push_back(Tp &&v, Tuple &&t) { return tuple_push<TPL_SIZE_(Tuple)>(v, t); }


template <std::size_t Pos, class Tuple>
constexpr auto tuple_pop(Tuple &&t) {
    static_assert(TPL_SIZE_(Tuple) > 0, "Pop from empty tuple");
    return std::tuple_cat(subtuple<0, Pos>(t), subtuple<Pos + 1, TPL_SIZE_(Tuple) - Pos - 1>(t));
}
template <class Tuple>
constexpr auto tuple_pop_front(Tuple &&t) { return tuple_pop<0>(t); }
template <class Tuple>
constexpr auto tuple_pop_back(Tuple &&t) { return tuple_pop<TPL_SIZE_(Tuple) - 1>(t); }

template <class Tuple, class BinOp>
constexpr auto apply2(BinOp &&f, Tuple &&lhs, Tuple &&rhs) { return tuple_detail_::apply2_impl_(f, lhs, rhs, std::make_index_sequence<TPL_SIZE_(Tuple)>()); }

#define OO_PTEQ_(op)                                                                                                                               \
    template <class Tp, class Up>                                                                                                                  \
    constexpr auto operator op(std::pair<Tp, Up> lhs, const std::pair<Tp, Up> &rhs) { return {lhs.first op rhs.first, lhs.second op rhs.second}; } \
    template <class... Ts>                                                                                                                         \
    constexpr auto operator op(std::tuple<Ts...> const &lhs, std::tuple<Ts...> const &rhs) {                                                       \
        return apply2([](auto &&l, auto &&r) { return l op r; }, lhs, rhs);                                                                        \
    }                                                                                                                                              \
    template <class Tp, class Up>                                                                                                                  \
    constexpr std::pair<Tp, Up> &operator op##=(std::pair<Tp, Up> &lhs, const std::pair<Tp, Up> &rhs) {                                            \
        lhs.first op## = rhs.first;                                                                                                                \
        lhs.second op## = rhs.second;                                                                                                              \
        return lhs;                                                                                                                                \
    }                                                                                                                                              \
    template <class... Ts>                                                                                                                         \
    constexpr auto operator op##=(std::tuple<Ts...> &lhs, const std::tuple<Ts...> &rhs) { return lhs = lhs op rhs; }

OO_PTEQ_(+)
OO_PTEQ_(-)
OO_PTEQ_(*)
OO_PTEQ_(/)
OO_PTEQ_(%)
OO_PTEQ_(&)
OO_PTEQ_(|)
OO_PTEQ_(^)
OO_PTEQ_(<<)
OO_PTEQ_(>>)

#undef OO_PTEQ_
#undef TPL_SIZE_


template <class Tp, class Up>
std::istream &operator>>(std::istream &is, std::pair<Tp, Up> &p) { return is >> p.first >> p.second; }
template <class Tp, class Up>
std::ostream &operator<<(std::ostream &os, const std::pair<Tp, Up> &p) {
#ifdef LOCAL_
    if (&os == &std::cerr)
        return os << '<' << p.first << ", " << p.second << '>';
    else
#endif
        return os << p.first << ' ' << p.second;
}

template <typename... Ts>
std::istream &operator>>(std::istream &is, std::tuple<Ts...> &p) {
    std::apply([&](Ts &...targs) { ((is >> targs), ...); }, p);
    return is;
}
template <typename... Ts>
std::ostream &operator<<(std::ostream &os, const std::tuple<Ts...> &p) {
    std::apply(
        [&](Ts const &...targs) {
            std::size_t n{0};
#ifdef LOCAL_
            if (&os == &std::cerr) os << '(';
            if (&os == &std::cerr)
                ((os << targs << (++n != sizeof...(Ts) ? ", " : "")), ...);
            else
#endif
                ((os << targs << (++n != sizeof...(Ts) ? " " : "")), ...);
#ifdef LOCAL_
            if (&os == &std::cerr) os << ')';
#endif
        },
        p);
    return os;
}

template <class Ch, class Tr, class Ct, std::enable_if_t<std::is_same_v<decltype(std::declval<Ct>().begin()), typename Ct::iterator> && std::is_same_v<decltype(std::declval<Ct>().end()), typename Ct::iterator>> * = nullptr>
std::basic_ostream<Ch, Tr> &operator<<(std::basic_ostream<Ch, Tr> &os, const Ct &x) {
#ifdef LOCAL_
    if (&os == &std::cerr && x.begin() == x.end()) return os << "[]";
#endif
    if (x.begin() == x.end()) return os;
#ifdef LOCAL_
    if (&os == &std::cerr) os << '[';
    if (&os == &std::cerr)
        for (auto it = x.begin(); it != x.end() - 1; ++it) os << *it << ", ";
    else
#endif
        for (auto it = x.begin(); it != x.end() - 1; ++it) os << *it << ' ';
    os << x.back();
#ifdef LOCAL_
    if (&os == &std::cerr) os << ']';
#endif
    return os;
}


template <class Tp>
inline void debug(Tp x) {
#ifdef LOCAL_
    std::cerr << x << std::endl;
#endif
}
template <class Tp, class... Ts>
inline void debug(Tp x, Ts... args) {
#ifdef LOCAL_
    std::cerr << x << ' ';
    debug(args...);
#endif
}
#define debug_line_ (std::cerr << __LINE__ << ' ' << __FUNCTION__ << std::endl)
#define debug_withname_(var) debug(#var, var)


const u32 OFFSET = 5;
const u32 N = 5e5 + OFFSET;
const u32 M = 2e5 + OFFSET;
const u32 K = 21;


const i64 MOD = 1e9 + 7;
const double EPS = 1e-6;
const i32 INF = 0x3f3f3f3f;
const i64 INF64 = 0x3f3f3f3f3f3f3f3f;
const double PI = acos(-1.0);
const char DIR_DRUL[4] = {'D', 'R', 'U', 'L'};
const char DIR_SENW[4] = {'S', 'E', 'N', 'W'};
const pii DIR4[4] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
const pii DIR8[8] = {{1, 0}, {1, 1}, {0, 1}, {-1, 1}, {-1, 0}, {-1, -1}, {0, -1}, {1, -1}};
const std::string RES_YN[2] = {"NO", "YES"};
const std::string RES_Yn[2] = {"No", "Yes"};
const std::string RES_yn[2] = {"no", "yes"};
const std::string RES_POSS[2] = {"IMPOSSIBLE", "POSSIBLE"};
const std::string RES_Poss[2] = {"Impossible", "Possible"};
const std::string RES_poss[2] = {"impossible", "possible"};
const std::string RES_Ab[2] = {"Bob", "Alice"};





template <size_t N_>
constexpr int64_t EXP10_impl_() { return EXP10_impl_<N_ - 1>() * 10; }
template <>
constexpr int64_t EXP10_impl_<0>() { return 1; }
template <size_t N_>
constexpr int64_t EXP10 = EXP10_impl_<N_>();

template <size_t N_>
constexpr int64_t FACT10_impl_() { return FACT10_impl_<N_ - 1>() * N_; }
template <>
constexpr int64_t FACT10_impl_<0>() { return 1; }
template <size_t N_>
constexpr int64_t FACT = FACT10_impl_<N_>();


using namespace std;


const auto STATIC__ = []() {
    return 0;
}();


namespace Bucket_detail__ {
template <class Tp, typename Ext>
struct BlockInfo final {
    using self = BlockInfo<Tp, Ext>;

    const size_t l, r;
    Tp result;
    const std::function<void(self &, std::vector<Tp> &)> bfunc;
    Ext ext;

    

    

    BlockInfo(size_t l, size_t r, std::vector<Tp> &data, std::function<void(self &, std::vector<Tp> &)> bfunc): l(l), r(r), result(), bfunc(bfunc), ext() { bfunc(*this, data); }

    inline void refresh(std::vector<Tp> &data) { bfunc(*this, data); }
};

template <class Tp>
struct BlockInfo<Tp, void> final {
    using self = BlockInfo<Tp, void>;

    const size_t l, r;
    Tp result;
    const std::function<void(self &, std::vector<Tp> &)> bfunc;

    

    

    BlockInfo(size_t l, size_t r, std::vector<Tp> &data, std::function<void(self &, std::vector<Tp> &)> bfunc): l(l), r(r), result(), bfunc(bfunc) { bfunc(*this, data); }

    inline void refresh(std::vector<Tp> &data) { bfunc(*this, data); }
};






template <typename Tp, typename Ext = void>
class Bucket {
  public:
    using self = Bucket<Tp, Ext>;
    using BInfo = BlockInfo<Tp, Ext>;

  protected:
    const size_t bsize;

  protected:
    std::vector<Tp> data;
    std::vector<BInfo> blk;

  public:
    

    Bucket(
        size_t bsize,
        std::vector<Tp> const &data_,
        std::function<void(BInfo &, std::vector<Tp> const &)> bfunc): bsize(bsize), data(data_), blk() {
        assert(data.size() > 0);
        size_t _ = (data.size() + bsize - 1) / bsize;
        blk.reserve(_);
        for (size_t i = 0; i < _; ++i) blk.emplace_back(i * bsize, std::min(data.size(), (i + 1) * bsize) - 1, data, bfunc);
    }

    

    

    

    template <class USFunc = std::function<void(BInfo &, std::vector<Tp> &, size_t, size_t)>, class UBFunc = std::function<void(BInfo &, std::vector<Tp> &)>>
    inline self &update(size_t l, size_t r, USFunc usfunc, UBFunc ubfunc) {
        ptrdiff_t bl = (l + bsize - 1) / bsize, br = (r + 1) / bsize - 1;
        for (ptrdiff_t i = bl; i <= br; ++i) ubfunc(blk[i], data);
        if (r < bl * bsize) {
            usfunc(blk[bl - 1], data, l, r);
        } else {
            if (l < bl * bsize) usfunc(blk[bl - 1], data, l, bl * bsize - 1);
            if ((br + 1) * bsize <= r) usfunc(blk[br + 1], data, (br + 1) * bsize, r);
        }
        return *this;
    }
};
}  

using Bucket_detail__::Bucket;





std::vector<uint64_t> factors(uint64_t n) {
    vector<uint64_t> ret;
    ret.reserve((size_t)sqrtl(n) * 2);
    for (uint64_t i = 1; i * i <= n; ++i) {
        if (n % i) continue;
        ret.push_back(i);
        if (uint64_t j = n / i; i != j) ret.push_back(j);
    }
    return ret;
}

struct ExtData {
    vc<u32> mp;
    u32 x;

    ExtData(): mp(50001), x(0) {}
};




inline auto solve([[maybe_unused]] int t_ = 0) -> void {
    int n, q;
    cin >> n >> q;
    read_container_(vc<u32>, a, n);
    read_container_(vc<u32>, b, n);

    Bucket<u32, ExtData> bucket(
        200,
        a,
        [&](auto &blk, auto &data) {
            blk.result = numeric_limits<decltype(blk.result)>::max();
            for_(i, blk.l, blk.r) chkmin(blk.result, lcm(data[i], b[i]) / gcd(data[i], b[i]));
        });
    bucket.update(
        0,
        n - 1,
        [&](auto &blk, auto &data, size_t xl, size_t xr) {},
        [&](auto &blk, auto &data) {
            for_(i, blk.l, blk.r) {
                auto _ = factors(b[i]);
                for (u32 f : _) {
                    auto &__ = blk.ext.mp[f];
                    __ = __ ? min(__, b[i]) : b[i];
                }
            }
        });

    for_(i, 1, q, tp, l, r) {
        cin >> tp >> l >> r;
        --l;
        --r;
        if (tp == 1) {
            read_var_(u32, x);
            auto _ = factors(x);
            bucket.update(
                l,
                r,
                [&](auto &blk, auto &data, size_t xl, size_t xr) {
                    if (blk.ext.x) {
                        for_(i, blk.l, blk.r) data[i] = blk.ext.x;
                        blk.ext.x = 0;
                    }
                    for_(i, xl, xr) data[i] = x;
                    blk.refresh(data);
                },
                [&](auto &blk, auto &data) {
                    blk.result = numeric_limits<decltype(blk.result)>::max();
                    blk.ext.x = x;
                    for (u32 f : _)
                        if (u32 __ = blk.ext.mp[f]; __) chkmin(blk.result, x / f * (__ / f));
                });
        } else {
            u32 ans = numeric_limits<u32>::max();
            bucket.update(
                l,
                r,
                [&](auto &blk, auto &data, size_t xl, size_t xr) {
                    if (blk.ext.x) {
                        for_(i, blk.l, blk.r) data[i] = blk.ext.x;
                        blk.ext.x = 0;
                    }
                    for_(i, xl, xr) chkmin(ans, lcm(data[i], b[i]) / gcd(data[i], b[i]));
                },
                [&](auto &blk, auto &data) {
                    chkmin(ans, blk.result);
                });
            cout << ans << '\n';
        }
    }
}

int main() {
#ifdef LOCAL_
    auto CLOCK_ST_ = std::chrono::high_resolution_clock::now();
    std::cerr << std::boolalpha << std::fixed << std::setprecision(6);
#endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int i_ = STATIC__;
    


#ifdef MULTI_CASES
    int t_ = 0;
    std::cin >> t_;
    for (i_ = 0; i_ < t_; ++i_)
#endif
        debug("Case", i_), solve(i_);
#ifdef LOCAL_
    auto CLOCK_ED_ = std::chrono::high_resolution_clock::now();
    std::clog << "\n---\nTime used: " << std::chrono::duration_cast<std::chrono::nanoseconds>(CLOCK_ED_ - CLOCK_ST_).count() * 1e-6l << " ms" << std::endl;
#endif
    return 0;
}