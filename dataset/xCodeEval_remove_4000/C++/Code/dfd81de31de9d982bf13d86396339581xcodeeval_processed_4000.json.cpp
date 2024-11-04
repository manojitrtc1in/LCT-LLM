










using namespace std;
using namespace std::literals;











using namespace atcoder;

using ll= long long;
using ld= long double;
using ull= unsigned long long;
using i128= __int128;
using u128= unsigned __int128;
using str= std::string;
using pll= std::pair<ll, ll>;
template<class T> using vec= std::vector<T>;
template<
    class T, class Container= vec<T>,
    class Compare= std::less<typename Container::value_type>>
using prique= std::priority_queue<T, Container, Compare>;
using vi= vec<int>;
using vl= vec<ll>;
using vd= vec<ld>;
using vs= vec<str>;
using vi128= vec<i128>;
using vpll= vec<pll>;
using vvi= vec<vi>;
using vvl= vec<vl>;
using vvd= vec<vd>;
using vvs= vec<vs>;
using vvi128= vec<vi128>;
using vvpll= vec<vpll>;


using mint= atcoder::modint1000000007;

using mint= atcoder::modint998244353;

using vm= vec<mint>;
using vvm= vec<vm>;


constexpr ll mod= 1000000007ll;

constexpr ll mod= 998244353ll;


















    std::sort(ALL(p)); \
    for(bool(p





template<class T> struct is_pair : std::false_type {};
template<class T1, class T2> struct is_pair<std::pair<T1, T2>> : std::true_type {};
template<class T> inline constexpr bool is_pair_v= is_pair<T>::value;
template<class T> struct is_tuple : std::false_type {};
template<class... Ts> struct is_tuple<std::tuple<Ts...>> : std::true_type {};
template<class T> inline constexpr bool id0= is_tuple<T>::value;
template<class, class= void> inline constexpr bool has_iterator= false;
template<class T>
inline constexpr bool has_iterator<T, std::void_t<typename T::iterator>> = true;
template<class, class= void> inline constexpr bool id5= false;
template<class T>
inline constexpr bool id5<T, std::void_t<typename T::value_type>> = true;

template<class T>
inline constexpr bool is_modint_v= atcoder::internal::is_modint<T>::value;

template<class T> constexpr ll sz(const T &x) {
    return std::size(x);
}
constexpr ll topbit(const ll &t) {
    return (t == 0 ? -1 : 63 - __builtin_clzll(t));
}
constexpr ll bit(const ll &n) noexcept {
    return (1ll << n);
}
template<class T, class U> constexpr T ceil_div(const T &a, const U &b) {
    assert(b != 0);
    if((a < 0) == (b < 0)) {
        return (a + b - (b > 0) + (b < 0)) / b;
    } else {
        return a / b;
    }
}
template<class T, class U> constexpr T floor_div(const T &a, const U &b) {
    assert(b != 0);
    if((a < 0) == (b < 0)) {
        return a / b;
    } else {
        return (a - b + (b > 0) - (b < 0)) / b;
    }
}
str YES(const bool &n) noexcept {
    return (n ? "YES"s : "NO"s);
}
str Yes(const bool &n) noexcept {
    return (n ? "Yes"s : "No"s);
}
str yes(const bool &n) noexcept {
    return (n ? "yes"s : "no"s);
}
template<class T> constexpr void uniq(T &v) {
    v.erase(std::unique(v.begin(), v.end()), v.end());
}
template<class T, class U> constexpr ll lb(const T &v, const U &x) {
    return std::distance(v.begin(), std::lower_bound(v.begin(), v.end(), x));
}
template<class T, class U, class Compare>
constexpr ll lb(const T &v, const U &x, Compare comp) {
    return std::distance(v.begin(), std::lower_bound(v.begin(), v.end(), x, comp));
}
template<class T, class U> constexpr ll ub(const T &v, const U &x) {
    return std::distance(v.begin(), std::upper_bound(v.begin(), v.end(), x));
}
template<class T, class U, class Compare>
constexpr ll ub(const T &v, const U &x, Compare comp) {
    return std::distance(v.begin(), std::upper_bound(v.begin(), v.end(), x, comp));
}
template<class T, class U, class V> constexpr ll er(const T &v, const U &x, const V &y) {
    return std::distance(
        std::lower_bound(v.begin(), v.end(), x), std::upper_bound(v.begin(), v.end(), y));
}
template<class T, class U, class V, class Compare>
constexpr ll er(const T &v, const U &x, const V &y, Compare comp) {
    return std::distance(
        std::lower_bound(v.begin(), v.end(), x, comp),
        std::upper_bound(v.begin(), v.end(), y, comp));
}
template<class T, class U> constexpr bool chmax(T &a, const U &b) noexcept {
    if(a < b) {
        a= b;
        return true;
    }
    return false;
}
template<class T, class U, class Compare>
constexpr bool chmax(T &a, const U &b, Compare comp) noexcept {
    if(comp(a, b)) {
        a= b;
        return true;
    }
    return false;
}
template<class T, class U> constexpr bool chmin(T &a, const U &b) noexcept {
    if(b < a) {
        a= b;
        return true;
    }
    return false;
}
template<class T, class U, class Compare>
constexpr bool chmin(T &a, const U &b, Compare comp) noexcept {
    if(comp(b, a)) {
        a= b;
        return true;
    }
    return false;
}
template<class Container> typename Container::value_type sum(Container &c) {
    return std::accumulate(c.begin(), c.end(), typename Container::value_type());
}
constexpr std::array<pll, 4> dx4{{{1ll, 0ll}, {0ll, 1ll}, {-1ll, 0ll}, {0ll, -1ll}}};
constexpr std::array<pll, 8> dx8{
    {{1ll, 0ll},
     {1ll, 1ll},
     {0ll, 1ll},
     {-1ll, 1ll},
     {-1ll, 0ll},
     {-1ll, -1ll},
     {0ll, -1ll},
     {1ll, -1ll}}};
template<class F> struct rec {
    F f;
    rec(F &&f_) : f(std::forward<F>(f_)) {}
    template<class... Args> auto operator()(Args &&...args) const {
        return f(*this, std::forward<Args>(args)...);
    }
};
template<class T, class U>
constexpr std::pair<T, U> operator+(std::pair<T, U> p, const std::pair<T, U> &q) {
    p+= q;
    return p;
}
template<class T, class U>
constexpr std::pair<T, U> &operator+=(std::pair<T, U> &p, const std::pair<T, U> &q) {
    p.first+= q.first;
    p.second+= q.second;
    return p;
}
template<class T, class U>
constexpr std::pair<T, U> operator-(std::pair<T, U> p, const std::pair<T, U> &q) {
    p-= q;
    return p;
}
template<class T, class U>
constexpr std::pair<T, U> &operator-=(std::pair<T, U> &p, const std::pair<T, U> &q) {
    p.first-= q.first;
    p.second-= q.second;
    return p;
}
template<class T, class U> constexpr std::pair<T, U> operator+(const std::pair<T, U> &p) {
    return p;
}
template<class T, class U> constexpr std::pair<T, U> operator-(const std::pair<T, U> &p) {
    return {-p.first, -p.second};
}
inline i128 parse(str s) {
    std::reverse(s.begin(), s.end());
    i128 ret= 0;
    bool minus= false;
    if(s.back() == '-') {
        minus= true;
        s.pop_back();
    }
    while(!s.empty()) {
        if('0' <= s.back() && s.back() <= '9') {
            ret= ret * 10 + s.back() - '0';
            s.pop_back();
        } else {
            break;
        }
    }
    std::reverse(s.begin(), s.end());
    if(minus) ret*= -1;
    return ret;
}
inline str to_string(i128 val) {
    str ret= ""s;
    bool minus= false;
    if(val < 0) {
        minus= true;
        val*= -1;
    }
    do {
        char digit= static_cast<char>(48 + val % 10);
        ret+= digit;
        val/= 10;
    } while(val != 0);
    if(minus) ret+= "-"s;
    std::reverse(ret.begin(), ret.end());
    return ret;
}
inline str to_string(u128 val) {
    str ret= ""s;
    do {
        char digit= static_cast<char>(48 + val % 10);
        ret+= digit;
        val/= 10;
    } while(val != 0);
    std::reverse(ret.begin(), ret.end());
    return ret;
}

    char id7; \
    input(id7)

    str id7; \
    input(id7)

    ll id7; \
    input(id7)

    ld id7; \
    input(id7)

    i128 id7; \
    input(id7)

    vec<id7> name(size); \
    input(name)

    std::vector name((h), vec<id7>(w)); \
    input(name)

int inline id4() {
    return _getchar_nolock();
}
void inline id1(char c, FILE *stream) {
    _putc_nolock(c, stream);
}

struct in {
    in()= delete;
    static inline void input_impl(char &a) {
        do { a= static_cast<char>(id4()); } while(a == ' ' || a == '\n');
    }
    static inline void input_impl(str &a) {
        a= ""s;
        int c;
        do { c= id4(); } while(c == ' ' || c == '\n');
        do {
            a+= static_cast<char>(c);
            c= id4();
        } while(c != EOF && c != ' ' && c != '\n');
        std::ungetc(c, stdin);
    }
    template<
        class T,
        std::enable_if_t<
            std::is_integral_v<T> || std::is_same_v<i128, T> || std::is_same_v<u128, T>,
            std::nullptr_t> = nullptr>
    static inline void input_impl(T &a) {
        a= 0;
        int c;
        do { c= id4(); } while(c == ' ' || c == '\n');
        bool minus= 0;
        if(c == '-') {
            minus= 1;
            c= id4();
        }
        if(c < '0' || '9' < c) {
            std::ungetc(c, stdin);
            return;
        }
        do {
            (a*= 10)+= c - 48;
            c= id4();
        } while('0' <= c && c <= '9');
        std::ungetc(c, stdin);
        if(minus) a*= -1;
    }
    static inline void input_impl(float &a) {
        std::scanf("%f", &a);
    }
    static inline void input_impl(double &a) {
        std::scanf("%lf", &a);
    }
    static inline void input_impl(ld &a) {
        std::scanf("%Lf", &a);
    }
    template<class T1, class T2> static inline void input_impl(std::pair<T1, T2> &a) {
        input_impl(a.first);
        input_impl(a.second);
    }
    template<class T, std::enable_if_t<id0<T>, std::nullptr_t> = nullptr>
    static inline void input_impl(T &a) {
        if constexpr(std::tuple_size_v<T> != 0) {
            id8(a, std::make_index_sequence<std::tuple_size_v<T>>());
        }
    }
    template<class T, std::enable_if_t<has_iterator<T>, std::nullptr_t> = nullptr>
    static inline void input_impl(T &a) {
        for(auto &&e: a) { input_impl(e); }
    }

   private:
    template<class T, std::size_t... Seq>
    static inline void id8(T &A, std::index_sequence<Seq...>) {
        using swallow= std::initializer_list<int>;
        swallow{(input_impl(std::get<Seq>(A)), 0)...};
    }
};
template<class... Args> inline void input(Args &...args) {
    using swallow= std::initializer_list<int>;
    swallow{(in::input_impl(args), 0)...};
}
template<class, class= std::void_t<>> struct has_print_impl : std::false_type {};
template<class T>
struct has_print_impl<T, std::void_t<decltype(std::declval<T>().print_impl(0))>>
    : std::true_type {};
template<class T> inline constexpr bool id3= has_print_impl<T>::value;
struct out {
    out()= delete;
    static inline void print_impl(FILE *stream, const char *const &a) {
        std::fputs(a, stream);
    }
    template<class T> static inline void print_impl(FILE *stream, T *const &a) {
        std::fprintf(stream, "%p", a);
    }
    static inline void print_impl(FILE *stream, const char &a) {
        id1(a, stream);
    }
    static inline void print_impl(FILE *stream, const str &a) {
        std::fputs(a.c_str(), stream);
    }
    template<std::size_t length>
    static inline void print_impl(FILE *stream, const char (&a)[length]) {
        std::fputs(a, stream);
    }
    static inline void print_impl(FILE *stream, const bool &a) {
        id1('0' + a, stream);
    }
    static inline void print_impl(FILE *stream, const signed char &a) {
        std::fprintf(stream, "%hhd", a);
    }
    static inline void print_impl(FILE *stream, const short &a) {
        std::fprintf(stream, "%hd", a);
    }
    static inline void print_impl(FILE *stream, const int &a) {
        std::fprintf(stream, "%d", a);
    }
    static inline void print_impl(FILE *stream, const long &a) {
        std::fprintf(stream, "%ld", a);
    }
    static inline void print_impl(FILE *stream, const ll &a) {
        std::fprintf(stream, "%lld", a);
    }
    static inline void print_impl(FILE *stream, const i128 &a) {
        std::fputs(to_string(a).c_str(), stream);
    }
    static inline void print_impl(FILE *stream, const unsigned char &a) {
        std::fprintf(stream, "%hhu", a);
    }
    static inline void print_impl(FILE *stream, const unsigned short &a) {
        std::fprintf(stream, "%hu", a);
    }
    static inline void print_impl(FILE *stream, const unsigned int &a) {
        std::fprintf(stream, "%u", a);
    }
    static inline void print_impl(FILE *stream, const unsigned long &a) {
        std::fprintf(stream, "%lu", a);
    }
    static inline void print_impl(FILE *stream, const ull &a) {
        std::fprintf(stream, "%llu", a);
    }
    static inline void print_impl(FILE *stream, const u128 &a) {
        std::fputs(to_string(a).c_str(), stream);
    }
    static inline void print_impl(FILE *stream, const float &a) {
        std::fprintf(stream, "%.15f", a);
    }
    static inline void print_impl(FILE *stream, const double &a) {
        std::fprintf(stream, "%.15lf", a);
    }
    static inline void print_impl(FILE *stream, const ld &a) {
        std::fprintf(stream, "%.15Lf", a);
    }
    static inline void print_impl(FILE *stream, const std::type_info &a) {
        std::fputs(a.name(), stream);
    }
    template<class T1, class T2>
    static inline void print_impl(FILE *stream, const std::pair<T1, T2> &a) {
        print_impl(stream, a.first);
        id1(' ', stream);
        print_impl(stream, a.second);
    }

    static inline void print_impl(FILE *stream, const mint &a) {
        std::fprintf(stream, "%u", a.val());
    }

    template<class T, std::enable_if_t<id0<T>, std::nullptr_t> = nullptr>
    static inline void print_impl(FILE *stream, const T &a) {
        if constexpr(std::tuple_size_v<T> != 0) {
            id6(
                stream, a, std::make_index_sequence<std::tuple_size_v<T> - 1>());
        }
    }
    template<class T, std::enable_if_t<has_iterator<T>, std::nullptr_t> = nullptr>
    static inline void print_impl(FILE *stream, const T &a) {
        if(a.begin() == a.end()) return;
        print_impl(stream, *(a.begin()));
        if constexpr(!id5<T> || !has_iterator<typename T::value_type>) {
            std::for_each(std::next(a.begin()), a.end(), [stream](const auto &value) {
                id1(' ', stream);
                print_impl(stream, value);
            });
        } else if constexpr(
            !id5<typename T::value_type> ||
            !has_iterator<typename T::value_type::value_type>) {
            std::for_each(std::next(a.begin()), a.end(), [stream](const auto &value) {
                id1('\n', stream);
                print_impl(stream, value);
            });
        } else {
            std::for_each(std::next(a.begin()), a.end(), [stream](const auto &value) {
                id1('\n', stream);
                id1('\n', stream);
                print_impl(stream, value);
            });
        }
    }
    template<class T, std::enable_if_t<id3<T>, std::nullptr_t> = nullptr>
    static inline void print_impl(FILE *stream, const T &a) {
        a.print_impl(stream);
    }
    static inline void print_impl(...) {
        print_impl(stderr, "not supported");
    }

   private:
    template<class T, std::size_t... Seq>
    static inline void
    id6(FILE *stream, const T &A, std::index_sequence<Seq...>) {
        print_impl(stream, std::get<0>(A));
        using swallow= std::initializer_list<int>;
        swallow{
            (id1(' ', stream), print_impl(stream, std::get<Seq + 1>(A)), 0)...};
    }
};
inline void print() {
    id1('\n', stdout);
}
template<class Head, class... Tail> inline void print(Head &&H, Tail &&...T) {
    out::print_impl(stdout, std::forward<Head>(H));
    using swallow= std::initializer_list<int>;
    swallow{
        (id1(' ', stdout), out::print_impl(stdout, std::forward<Tail>(T)),
         0)...};
    id1('\n', stdout);
}
template<class... Args> inline void print_flush(Args &&...args) {
    print(std::forward<Args>(args)...);
    std::fflush(stdout);
}
template<class... Args> inline void debug([[maybe_unused]] Args &&...args) {

    print_flush(std::forward<Args>(args)...);

}
inline void print_err() {
    id1('\n', stderr);
}
template<class Head, class... Tail> inline void print_err(Head &&H, Tail &&...T) {
    out::print_impl(stderr, std::forward<Head>(H));
    using swallow= std::initializer_list<int>;
    swallow{
        (id1(' ', stderr), out::print_impl(stderr, std::forward<Tail>(T)),
         0)...};
    id1('\n', stderr);
}
inline void id2() {
    std::fflush(stdout);
}


signed main() {
    setvbuf(stdin, nullptr, _IOFBF, 1 << 17);
    setvbuf(stdout, nullptr, _IOFBF, 1 << 17);
    LL(T);
    REP(T) {
        LL(N, L, R, K);
        VEC(A, N, ll);
        sort(ALL(A));
        ll ans= 0;
        for(auto &&x : A) {
            if(L <= x && x <= R) {
                if(x <= K) {
                    K-= x;
                    ans++;
                }
            }
        }
        print(ans);
    }
}