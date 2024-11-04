










using namespace std;












using namespace atcoder;

using ll= long long;
using ld= long double;
using ull= unsigned long long;
using i128= __int128;
using pll= std::pair<ll, ll>;
template <class T> using vec= std::vector<T>;
template <class T, class Container= std::vector<T>,
          class Compare= std::less<typename Container::value_type>>
using prique= std::priority_queue<T, Container, Compare>;
using vi= vec<int>;
using vl= vec<ll>;
using vd= vec<ld>;
using vs= vec<std::string>;
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


constexpr ll mod= 1e9 + 7;

constexpr ll mod= 998244353;















    std::sort(ALL(p)); \
    for(bool(p





template <class T> struct is_pair : std::false_type {};
template <class T1, class T2>
struct is_pair<std::pair<T1, T2>> : std::true_type {};
template <class T> inline constexpr bool is_pair_v= is_pair<T>::value;
template <class T> struct is_tuple : std::false_type {};
template <class... Ts> struct is_tuple<std::tuple<Ts...>> : std::true_type {};
template <class T> inline constexpr bool id0= is_tuple<T>::value;
template <class, class= void> inline constexpr bool has_iterator= false;
template <class T>
inline constexpr bool has_iterator<T, std::void_t<typename T::iterator>> = true;
template <class, class= void> inline constexpr bool id2= false;
template <class T>
inline constexpr bool id2<T, std::void_t<typename T::value_type>> =
    true;

template <class T>
inline constexpr bool is_modint_v= atcoder::internal::is_modint<T>::value;

template <class T> constexpr ll sz(const T &x) {
    return std::size(x);
}
constexpr ll topbit(const ll &t) {
    return (t == 0 ? -1 : 63 - __builtin_clzll(t));
}
constexpr ll bit(const ll &n) noexcept {
    return (1LL << n);
}
template <class T, class U> constexpr T ceil(const T &a, const U &b) {
    assert(b != 0);
    if((a < 0) == (b < 0)) {
        return (a + b - (b > 0) + (b < 0)) / b;
    } else {
        return a / b;
    }
}
template <class T, class U> constexpr T floor(const T &a, const U &b) {
    assert(b != 0);
    if((a < 0) == (b < 0)) {
        return a / b;
    } else {
        return (a - b + (b > 0) - (b < 0)) / b;
    }
}
template <class T> constexpr std::string YES(const T &n) noexcept {
    return (n ? "YES"s : "NO"s);
}
template <class T> constexpr std::string Yes(const T &n) noexcept {
    return (n ? "Yes"s : "No"s);
}
template <class T> constexpr std::string yes(const T &n) noexcept {
    return (n ? "yes"s : "no"s);
}
template <class T> constexpr void uniq(T &v) {
    v.erase(std::unique(v.begin(), v.end()), v.end());
}
template <class T, class U> constexpr ll lb(const T &v, const U &x) {
    return std::distance(v.begin(), std::lower_bound(v.begin(), v.end(), x));
}
template <class T, class U, class Compare>
constexpr ll lb(const T &v, const U &x, Compare comp) {
    return std::distance(v.begin(),
                         std::lower_bound(v.begin(), v.end(), x, comp));
}
template <class T, class U> constexpr ll ub(const T &v, const U &x) {
    return std::distance(v.begin(), std::upper_bound(v.begin(), v.end(), x));
}
template <class T, class U, class Compare>
constexpr ll ub(const T &v, const U &x, Compare comp) {
    return std::distance(v.begin(),
                         std::upper_bound(v.begin(), v.end(), x, comp));
}
template <class T, class U, class V>
constexpr ll er(const T &v, const U &x, const V &y) {
    return std::distance(std::lower_bound(v.begin(), v.end(), x),
                         std::upper_bound(v.begin(), v.end(), y));
}
template <class T, class U, class V, class Compare>
constexpr ll er(const T &v, const U &x, const V &y, Compare comp) {
    return std::distance(std::lower_bound(v.begin(), v.end(), x, comp),
                         std::upper_bound(v.begin(), v.end(), y, comp));
}
template <class T, class U> constexpr bool chmax(T &a, const U &b) noexcept {
    if(a < b) {
        a= b;
        return 1;
    }
    return 0;
}
template <class T, class U, class Compare>
constexpr bool chmax(T &a, const U &b, Compare comp) noexcept {
    if(comp(a, b)) {
        a= b;
        return 1;
    }
    return 0;
}
template <class T, class U> constexpr bool chmin(T &a, const U &b) noexcept {
    if(b < a) {
        a= b;
        return 1;
    }
    return 0;
}
template <class T, class U, class Compare>
constexpr bool chmin(T &a, const U &b, Compare comp) noexcept {
    if(comp(b, a)) {
        a= b;
        return 1;
    }
    return 0;
}
template <class Container> typename Container::value_type sum(Container &c) {
    return std::accumulate(c.begin(), c.end(),
                           typename Container::value_type());
}
const vpll dx4{{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
const vpll dx8{{1, 0},  {1, 1},   {0, 1},  {-1, 1},
               {-1, 0}, {-1, -1}, {0, -1}, {1, -1}};
template <class F> struct rec {
    F f;
    rec(F &&f_) : f(std::forward<F>(f_)) {}
    template <class... Args> decltype(auto) operator()(Args &&...args) const {
        return f(*this, std::forward<Args>(args)...);
    }
};
template <class T, class U>
constexpr std::pair<T, U> operator+(std::pair<T, U> p,
                                    const std::pair<T, U> &q) {
    p+= q;
    return p;
}
template <class T, class U>
constexpr std::pair<T, U> &operator+=(std::pair<T, U> &p,
                                      const std::pair<T, U> &q) {
    p.first+= q.first;
    p.second+= q.second;
    return p;
}
template <class T, class U>
constexpr std::pair<T, U> operator-(std::pair<T, U> p,
                                    const std::pair<T, U> &q) {
    p-= q;
    return p;
}
template <class T, class U>
constexpr std::pair<T, U> &operator-=(std::pair<T, U> &p,
                                      const std::pair<T, U> &q) {
    p.first-= q.first;
    p.second-= q.second;
    return p;
}
template <class T, class U>
constexpr std::pair<T, U> operator+(const std::pair<T, U> &p) {
    return p;
}
template <class T, class U>
constexpr std::pair<T, U> operator-(const std::pair<T, U> &p) {
    return {-p.first, -p.second};
}
inline __int128 parse(std::string s) {
    std::reverse(s.begin(), s.end());
    __int128 ret= 0;
    bool minus= 0;
    if(s.back() == '-') {
        minus= 1;
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
inline std::string to_string(__int128 val) {
    std::string ret= ""s;
    bool minus= 0;
    if(val < 0) {
        minus= 1;
        val*= -1;
    }
    do {
        char digit= '0' + static_cast<char>(val % 10);
        ret+= digit;
        val/= 10;
    } while(val != 0);
    if(minus) ret+= "-"s;
    std::reverse(ret.begin(), ret.end());
    return ret;
}
inline std::string to_string(unsigned __int128 val) {
    std::string ret= ""s;
    do {
        char digit= '0' + static_cast<char>(val % 10);
        ret+= digit;
        val/= 10;
    } while(val != 0);
    std::reverse(ret.begin(), ret.end());
    return ret;
}

    char id5; \
    input(id5)

    std::string id5; \
    input(id5)

    ll id5; \
    input(id5)

    ld id5; \
    input(id5)

    i128 id5; \
    input(id5)

    std::vector<id5> name(size); \
    input(name)

    std::vector name((h), std::vector<id5>(w)); \
    input(name)

int inline id1() {
    return _getchar_nolock();
}
void inline id3(char c) {
    _putchar_nolock(c);
}

inline void input_inner(char &a) {
    do {
        a= static_cast<char>(id1());
    } while(a == ' ' || a == '\n');
}
inline void input_inner(std::string &a) {
    a= ""s;
    int c;
    do { c= id1(); } while(c == ' ' || c == '\n');
    do {
        a+= static_cast<char>(c);
        c= id1();
    } while(c != EOF && c != ' ' && c != '\n');
    std::ungetc(c, stdin);
}
template <class T, std::enable_if_t<std::is_integral_v<T> ||
                                        std::is_same_v<__int128, T> ||
                                        std::is_same_v<unsigned __int128, T>,
                                    std::nullptr_t> = nullptr>
inline void input_inner(T &a) {
    int c;
    do { c= id1(); } while(c == ' ' || c == '\n');
    bool minus= 0;
    if(c == '-') {
        minus= 1;
        c= id1();
    }
    if(c < '0' || '9' < c) {
        std::ungetc(c, stdin);
        return;
    }
    a= 0;
    do {
        a*= 10;
        a+= c - '0';
        c= id1();
    } while(c != EOF && c != ' ' && c != '\n' && '0' <= c && c <= '9');
    std::ungetc(c, stdin);
    if(minus) a*= -1;
}
inline void input_inner(float &a) {
    std::scanf("%f", &a);
}
inline void input_inner(double &a) {
    std::scanf("%lf", &a);
}
inline void input_inner(long double &a) {
    std::scanf("%Lf", &a);
}
template <class T1, class T2> inline void input_inner(std::pair<T1, T2> &a) {
    input_inner(a.first);
    input_inner(a.second);
}
template <class T, std::enable_if_t<has_iterator<T>, std::nullptr_t> = nullptr>
inline void input_inner(T &a) {
    for(auto &&e : a) { input_inner(e); }
}
template <class... Args> inline void input(Args &&...args) {
    using swallow= std::initializer_list<ll>;
    swallow{(input_inner(args), 0)...};
}
template <class T> void print_inner(const T &a);
template <class T, std::size_t... Seq>
void id4(T &A, std::index_sequence<Seq...>) {
    print_inner(std::get<0>(A));
    using swallow= std::initializer_list<ll>;
    swallow{(id3(' '), print_inner(std::get<Seq + 1>(A)), 0)...};
}
template <class T> void print_inner(const T &a) {

    if constexpr(is_modint_v<T>) {
        std::printf("%u", a.val());
        return;
    }

    if constexpr(std::is_pointer_v<T>) {
        std::printf("%p", a);
    } else if constexpr(std::is_same_v<T, char>) {
        id3(a);
    } else if constexpr(std::is_array_v<T> &&
                        is_same_v<std::remove_extent_t<T>, char>) {
        std::printf("%s", a);
    } else if constexpr(std::is_same_v<T, std::string>) {
        std::printf("%s", a.c_str());
    } else if constexpr(std::is_same_v<T, bool>) {
        id3('0' + a);
    } else if constexpr(std::is_same_v<T, signed char>) {
        std::printf("%hhd", a);
    } else if constexpr(std::is_same_v<T, short>) {
        std::printf("%hd", a);
    } else if constexpr(std::is_same_v<T, int>) {
        std::printf("%d", a);
    } else if constexpr(std::is_same_v<T, long>) {
        std::printf("%ld", a);
    } else if constexpr(std::is_same_v<T, long long>) {
        std::printf("%lld", a);
    } else if constexpr(std::is_same_v<T, __int128>) {
        std::printf("%s", to_string(a).c_str());
    } else if constexpr(std::is_same_v<T, unsigned char>) {
        std::printf("%hhu", a);
    } else if constexpr(std::is_same_v<T, unsigned short>) {
        std::printf("%hu", a);
    } else if constexpr(std::is_same_v<T, unsigned int>) {
        std::printf("%u", a);
    } else if constexpr(std::is_same_v<T, unsigned long>) {
        std::printf("%lu", a);
    } else if constexpr(std::is_same_v<T, unsigned long long>) {
        std::printf("%llu", a);
    } else if constexpr(std::is_same_v<T, unsigned __int128>) {
        std::printf("%s", to_string(a).c_str());
    } else if constexpr(std::is_same_v<T, float>) {
        std::printf("%.15f", a);
    } else if constexpr(std::is_same_v<T, double>) {
        std::printf("%.15lf", a);
    } else if constexpr(std::is_same_v<T, long double>) {
        std::printf("%.15Lf", a);
    } else if constexpr(is_pair_v<T>) {
        print_inner(a.first);
        id3(' ');
        print_inner(a.second);
    } else if constexpr(id0<T>) {
        if constexpr(std::tuple_size_v<T> != 0) {
            id4(
                a, std::make_index_sequence<std::tuple_size_v<T> - 1>());
        }
    } else if constexpr(has_iterator<T>) {
        if(a.begin() == a.end()) return;
        print_inner(*(a.begin()));
        if constexpr(!id2<T> ||
                     !has_iterator<typename T::value_type>) {
            std::for_each(std::next(a.begin()), a.end(), [](const auto &value) {
                id3(' ');
                print_inner(value);
            });
        } else if constexpr(!id2<typename T::value_type> ||
                            !has_iterator<typename T::value_type::value_type>) {
            std::for_each(std::next(a.begin()), a.end(), [](const auto &value) {
                id3('\n');
                print_inner(value);
            });
        } else {
            std::for_each(std::next(a.begin()), a.end(), [](const auto &value) {
                id3('\n');
                id3('\n');
                print_inner(value);
            });
        }
    } else {
        std::printf("not supported");
    }
}
inline void print() {
    id3('\n');
}
template <class Head, class... Tail> inline void print(Head &&H, Tail &&...T) {
    print_inner(H);
    using swallow= std::initializer_list<ll>;
    swallow{(id3(' '), print_inner(T), 0)...};
    id3('\n');
}
inline void print_flush() {
    id3('\n');
    fflush(stdout);
}
template <class Head, class... Tail>
inline void print_flush(Head &&H, Tail &&...T) {
    print_inner(H);
    using swallow= std::initializer_list<ll>;
    swallow{(id3(' '), print_inner(T), 0)...};
    id3('\n');
    fflush(stdout);
}
template <class... Args> void debug(Args... args) {

    print_flush(args...);

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