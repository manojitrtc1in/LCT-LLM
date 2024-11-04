












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
template <class Tp>
using hset = std::unordered_set<Tp>;
template <class Key, class Tp, class Hash = std::hash<Key>>
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

























    {                                        \
        expressions;                         \
        post_process;                        \
    }






    type name;                \
    std::cin >> name

    type name(size);                      \
    foreach_ref_(i, name) std::cin >> i



    if (expression) throw std::runtime_error("Line " intlt2str_(__LINE__) ": やだもやだ、無理も無理〜")

template <class Tp>
constexpr auto chkmin(Tp &a, Tp b) -> bool { return b < a ? a = b, true : false; };
template <class Tp>
constexpr auto chkmax(Tp &a, Tp b) -> bool { return a < b ? a = b, true : false; };
template <class Tp, class Pred>
inline Tp binary_search(Pred check, Tp ok, Tp ng) {
    REif_(!check(ok));
    while (std::abs(ok - ng) > 1) {
        Tp x = (ng + ok) / 2;
        (check(x) ? ok : ng) = x;
    }
    return ok;
}
template <class Tp, class Pred, std::enable_if_t<std::is_floating_point_v<Tp>> * = nullptr>
inline Tp id5(Pred check, Tp ok, Tp ng, Tp eps) {
    REif_(!check(ok));
    while (std::abs(ok - ng) > eps) {
        Tp x = (ng + ok) / 2;
        (check(x) ? ok : ng) = x;
    }
    return (ng + ok) / 2;
}
template <class Tp>
inline auto id6(Tp &var) -> Tp {
    Tp d__(var);
    std::sort(d__.begin(), d__.end());
    d__.erase(std::unique(d__.begin(), d__.end()), d__.end());
    for (auto &i : var) i = std::distance(d__.begin(), std::lower_bound(d__.begin(), d__.end(), i));
    return d__;
};
template <class Tp>
constexpr auto id4(Tp i) -> bool { return i && (i & -i) == i; }






namespace tuple_detail_ {
template <std::size_t Begin, class Tuple, std::size_t... Is>
constexpr auto id12(Tuple &&t, std::index_sequence<Is...>) { return std::make_tuple(std::get<Is + Begin>(t)...); }
template <class Tuple, class BinOp, std::size_t... Is>
constexpr auto id10(BinOp &&f, Tuple &&lhs, Tuple &&rhs, std::index_sequence<Is...>) { return std::make_tuple(std::forward<BinOp>(f)(std::get<Is>(lhs), std::get<Is>(rhs))...); }
}  



template <std::size_t Begin, std::size_t Len, class Tuple>
constexpr auto subtuple(Tuple &&t) {
    static_assert(Begin <= TPL_SIZE_(Tuple) && Len <= TPL_SIZE_(Tuple) && Begin + Len <= TPL_SIZE_(Tuple), "Out of range");
    return tuple_detail_::id12<Begin>(t, std::make_index_sequence<Len>());
}

template <std::size_t Pos, class Tp, class Tuple>
constexpr auto tuple_push(Tp &&v, Tuple &&t) {
    static_assert(TPL_SIZE_(Tuple) > 0, "Pop from empty tuple");
    return std::tuple_cat(subtuple<0, Pos>(t), std::make_tuple(v), subtuple<Pos, TPL_SIZE_(Tuple) - Pos>(t));
}
template <class Tp, class Tuple>
constexpr auto id9(Tp &&v, Tuple &&t) { return tuple_push<0>(v, t); }
template <class Tp, class Tuple>
constexpr auto id2(Tp &&v, Tuple &&t) { return tuple_push<TPL_SIZE_(Tuple)>(v, t); }


template <std::size_t Pos, class Tuple>
constexpr auto tuple_pop(Tuple &&t) {
    static_assert(TPL_SIZE_(Tuple) > 0, "Pop from empty tuple");
    return std::tuple_cat(subtuple<0, Pos>(t), subtuple<Pos + 1, TPL_SIZE_(Tuple) - Pos - 1>(t));
}
template <class Tuple>
constexpr auto id8(Tuple &&t) { return tuple_pop<0>(t); }
template <class Tuple>
constexpr auto id0(Tuple &&t) { return tuple_pop<TPL_SIZE_(Tuple) - 1>(t); }

template <class Tuple, class BinOp>
constexpr auto apply2(BinOp &&f, Tuple &&lhs, Tuple &&rhs) { return tuple_detail_::id10(f, lhs, rhs, std::make_index_sequence<TPL_SIZE_(Tuple)>()); }


    template <class Tp, class Up>                                                                                                                  \
    constexpr auto operator op(std::pair<Tp, Up> lhs, const std::pair<Tp, Up> &rhs) { return {lhs.first op rhs.first, lhs.second op rhs.second}; } \
    template <class... Ts>                                                                                                                         \
    constexpr auto operator op(std::tuple<Ts...> const &lhs, std::tuple<Ts...> const &rhs) {                                                       \
        return apply2([](auto &&l, auto &&r) { return l op r; }, lhs, rhs);                                                                        \
    }

    OO_PT_(op)                                                                                          \
    template <class Tp, class Up>                                                                       \
    constexpr std::pair<Tp, Up> &operator op
        lhs.first op
        lhs.second op
        return lhs;                                                                                     \
    }                                                                                                   \
    template <class... Ts>                                                                              \
    constexpr auto operator op

id13(+)
id13(-)
id13(*)
id13(/)
id13(%)
id13(&)
id13(|)
id13(^)
id13(<<)
id13(>>)
OO_PT_(==)
OO_PT_(!=)
OO_PT_(<)
OO_PT_(<=)
OO_PT_(>)
OO_PT_(>=)





template <class Tp, class Up>
std::istream &operator>>(std::istream &is, std::pair<Tp, Up> &p) { return is >> p.first >> p.second; }
template <class Tp, class Up>
std::ostream &operator<<(std::ostream &os, const std::pair<Tp, Up> &p) {

    if (&os == &std::cerr)
        return os << '<' << p.first << ", " << p.second << '>';
    else

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

            if (&os == &std::cerr) os << '(';
            if (&os == &std::cerr)
                ((os << targs << (++n != sizeof...(Ts) ? ", " : "")), ...);
            else

                ((os << targs << (++n != sizeof...(Ts) ? " " : "")), ...);

            if (&os == &std::cerr) os << ')';

        },
        p);
    return os;
}

template <class Ch, class Tr, class Ct, std::enable_if_t<std::is_same_v<decltype(std::declval<Ct>().begin()), typename Ct::iterator> && std::is_same_v<decltype(std::declval<Ct>().end()), typename Ct::iterator>> * = nullptr>
std::basic_ostream<Ch, Tr> &operator<<(std::basic_ostream<Ch, Tr> &os, const Ct &x) {

    if (&os == &std::cerr && x.begin() == x.end()) return os << "[]";

    if (x.begin() == x.end()) return os;

    if (&os == &std::cerr) os << '[';
    if (&os == &std::cerr)
        for (auto it = x.begin(); it != x.end() - 1; ++it) os << *it << ", ";
    else

        for (auto it = x.begin(); it != x.end() - 1; ++it) os << *it << ' ';
    os << x.back();

    if (&os == &std::cerr) os << ']';

    return os;
}


template <class Tp>
inline void debug(Tp x) {

    std::cerr << x << std::endl;

}
template <class Tp, class... Ts>
inline void debug(Tp x, Ts... args) {

    std::cerr << x << ' ';
    debug(args...);

}




const u32 OFFSET = 5;
const u32 N = 5e5 + OFFSET;
const u32 M = 2e5 + OFFSET;
const u32 K = 21;
const u32 MOD = 1e9 + 7;
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


inline auto solve([[maybe_unused]] int t_ = 0) -> void {
    id7(int, n);
    id7(int, k);
    vvc<int> g(n + 1);
    vc<i64> s(n + 1);
    hmap<i64, i64> dp;

    for_(i, 2, n, fa) {
        cin >> fa;
        g[fa].push_back(i);
    }
    for_(i, 1, n) cin >> s[i];

    auto encode = [](i64 now, int k) -> i64 { return now << 32 | k; };

    function<i64(int, int)> dfs = [&](int now, int k) {
        auto &now_res = dp[encode(now, k)], &id1 = dp[encode(now, k + 1)];
        if (now_res && id1) return now_res;
        now_res = s[now] * k;
        id1 = s[now] * (k + 1);
        int sz = g[now].size();
        if (!sz) return now_res;
        int d = k / sz, r = k % sz;
        vc<i64> __;
        __.reserve(sz);
        for (auto i : g[now]) {
            i64 _1 = dfs(i, d), _2 = dp[encode(i, d + 1)];
            now_res += _1;
            id1 += _1;
            __.push_back(_2 - _1);
        }
        sort(__.begin(), __.end(), greater<>());
        auto _1 = accumulate(__.begin(), __.begin() + r, i64(0));
        now_res += _1;
        id1 += _1 + __[r];
        return now_res;
    };
    cout << dfs(1, k) << '\n';
}

int main() {

    auto id11 = std::chrono::high_resolution_clock::now();
    std::cerr << std::boolalpha << std::fixed << std::setprecision(6);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int i_ = STATIC__;
    



    int t_ = 0;
    std::cin >> t_;
    for (i_ = 0; i_ < t_; ++i_)

        debug("Case", i_), solve(i_);

    auto id3 = std::chrono::high_resolution_clock::now();
    std::clog << "\n---\nTime used: " << std::chrono::duration_cast<std::chrono::nanoseconds>(id3 - id11).count() * 1e-6l << " ms" << std::endl;

    return 0;
}