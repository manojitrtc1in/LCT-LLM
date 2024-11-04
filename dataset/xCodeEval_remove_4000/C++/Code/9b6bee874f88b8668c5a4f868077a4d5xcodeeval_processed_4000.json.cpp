





























namespace impl {

using namespace std;
using namespace chrono;
using namespace filesystem;



istream& operator>>(istream& is, __int128& x) {
    string s;
    is >> s;
    x = 0;
    bool neg = false;
    size_t i = 0;
    if (s[i] == '-') {
        neg = true;
        i++;
    }
    if (s[i] == '+')
        i++;
    for (; i < s.size(); i++) {
        if (!isdigit(s[i]))
            throw runtime_error(string("Non-numeric character: ") + s[i]);
        x *= 10;
        x += s[i] - '0';
    }
    if (neg)
        x *= -1;
    return is;
}

ostream& operator<<(ostream& os, __int128 x) {
    if (x < 0) {
        os << "-";
        x *= -1;
    }
    string s;
    do {
        s.push_back('0' + x % 10);
        x /= 10;
    } while (x > 0);
    for (auto it = s.crbegin(); it != s.crend(); it++)
        os << *it;
    return os;
}





istream& operator>>(istream& is, __float128& x) {
    long double d;
    is >> d;
    x = d;
    return is;
}

ostream& operator<<(ostream& os, __float128 x) {
    return os << (long double)x;
}



ostream& log_prefix(ostream& os, const char* file, int line) {

    return os << "[" << relative(path(file)).string() << ":" << line << "]: ";

    return os;

}

using modern_clock = high_resolution_clock;
using time_point = modern_clock::time_point;

struct Timer {
    const char* file;
    int line;
    const char* name;
    time_point start = modern_clock::now();

    template<class Period = ratio<1>>
    [[nodiscard]] double get() const {
        return static_cast<duration<double, Period>>(modern_clock::now() - start).count();
    }

    ~Timer() {

        log_prefix(cout, file, line);
        cout << name << " " << to_string(get()) << " seconds\n";

    }
};


    const ::impl::Timer name { __FILE__, __LINE__, 

TIMER(timer);

namespace rng {

thread_local mt19937_64 mt(modern_clock::now().time_since_epoch().count());

template<class T>
enable_if_t<is_integral_v<T>, T> get(T a, T b) {
    uniform_int_distribution<T> dist(a, b);
    return dist(mt);
}

template<class T>
enable_if_t<is_integral_v<T>, T> get() {
    uniform_int_distribution<T> dist(0, numeric_limits<T>::max());
    return dist(mt);
}

template<class T>
enable_if_t<is_floating_point_v<T>, T> get(T a, T b) {
    uniform_real_distribution<T> dist(a, b);
    return dist(mt);
}

template<class T>
enable_if_t<is_floating_point_v<T>, T> get() {
    uniform_real_distribution<T> dist(0, 1);
    return dist(mt);
}

} 


[[nodiscard]] constexpr unsigned long long id0(unsigned long long x) {
    x += 0x9e3779b97f4a7c15;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
    return x ^ (x >> 31);
}

struct CustomHash {
    template<class T>
    size_t operator()(const T& x) const {
        static const unsigned long long id3 = modern_clock::now().time_since_epoch().count();
        return static_cast<size_t>(id0(hash<T>()(x) + id3));
    }

    template<class T>
    inline void id5(size_t& seed, const T& v) const {
        seed ^= operator()(v) + 0x9e3779b9 + (seed<<6) + (seed>>2);
    }

    template<class T1, class T2>
    size_t operator()(const pair<T1, T2>& p) const {
        size_t seed = operator()(p.first);
        id5(seed, p.second);
        return seed;
    }
};



using namespace __gnu_pbds;

template<typename Key, typename Cmp_Fn = less<Key>>
using tree_set = tree<Key, null_type, Cmp_Fn, rb_tree_tag, tree_order_statistics_node_update>;

template<typename Key, typename Mapped, typename Cmp_Fn = less<Key>>
using tree_map = tree<Key, Mapped, Cmp_Fn, rb_tree_tag, tree_order_statistics_node_update>;

template<typename Key>
using hash_set = gp_hash_table<Key, null_type, CustomHash>;

template<typename Key, typename Mapped>
using hash_map = gp_hash_table<Key, Mapped, CustomHash>;



template<typename Key>
using hash_set = unordered_set<Key, CustomHash>;

template<typename Key, typename Mapped>
using hash_map = unordered_map<Key, Mapped, CustomHash>;



template<size_t N>
struct rank : rank<N - 1> {};

template<>
struct rank<0> {};

template<class T>
struct is_sequence : false_type {};

template<class T, size_t N>
struct is_sequence<array<T, N>> : true_type {};

template<class T, class Allocator>
struct is_sequence<vector<T, Allocator>> : true_type {};

template<class T, class Allocator>
struct is_sequence<deque<T, Allocator>> : true_type {};

template<class T, class Allocator>
struct is_sequence<forward_list<T, Allocator>> : true_type {};

template<class T, class Allocator>
struct is_sequence<list<T, Allocator>> : true_type {};

template<class T>
struct is_set : false_type {};

template<class Key, class Compare, class Allocator>
struct is_set<set<Key, Compare, Allocator>> : true_type {};

template<class Key, class Compare, class Allocator>
struct is_set<multiset<Key, Compare, Allocator>> : true_type {};

template<class Key, class Hash, class KeyEqual, class Allocator>
struct is_set<unordered_set<Key, Hash, KeyEqual, Allocator>> : true_type {};

template<class Key, class Hash, class KeyEqual, class Allocator>
struct is_set<unordered_multiset<Key, Hash, KeyEqual, Allocator>> : true_type {};

template<class T>
struct is_map : false_type {};

template<class Key, class T, class Compare, class Allocator>
struct is_map<map<Key, T, Compare, Allocator>> : true_type {};

template<class Key, class T, class Compare, class Allocator>
struct is_map<multimap<Key, T, Compare, Allocator>> : true_type {};

template<class Key, class T, class Hash, class KeyEqual, class Allocator>
struct is_map<unordered_map<Key, T, Hash, KeyEqual, Allocator>> : true_type {};

template<class Key, class T, class Hash, class KeyEqual, class Allocator>
struct is_map<unordered_multimap<Key, T, Hash, KeyEqual, Allocator>> : true_type {};

template<class T>
struct is_adaptor : false_type {};

template<class T, class Container>
struct is_adaptor<stack<T, Container>> : true_type {};

template<class T, class Container>
struct is_adaptor<queue<T, Container>> : true_type {};

template<class T, class Container, class Compare>
struct is_adaptor<priority_queue<T, Container, Compare>> : true_type {};

template<class Adaptor>
const typename Adaptor::container_type& get_container(const Adaptor& a) {
    struct hack : Adaptor {
        static const typename Adaptor::container_type& get(const Adaptor& a) { return a.*&hack::c; }
    };

    return hack::get(a);
}

template<class Adaptor>
typename Adaptor::container_type& get_container(Adaptor& a) {
    struct hack : Adaptor {
        static typename Adaptor::container_type& get(Adaptor& a) { return a.*&hack::c; }
    };

    return hack::get(a);
}



template<typename Key, typename Cmp_Fn, typename Tag,
         template<typename Const_Node_Iterator, typename Node_Iterator, typename Cmp_Fn_, typename Allocator_>
         class Node_Update,
         typename Allocator>
struct is_set<tree<Key, null_type, Cmp_Fn, Tag, Node_Update, Allocator>> : true_type {};

template<typename Key, typename Hash_Fn, typename Eq_Fn, typename Comp_Probe_Fn, typename Probe_Fn,
         typename Resize_Policy, bool id8, typename Allocator>
struct is_set<
    gp_hash_table<Key, null_type, Hash_Fn, Eq_Fn, Comp_Probe_Fn, Probe_Fn, Resize_Policy, id8, Allocator>>
    : true_type {};

template<typename Key, typename Cmp_Fn, typename Tag,
         template<typename Const_Node_Iterator, typename Node_Iterator, typename Cmp_Fn_, typename Allocator_>
         class Node_Update,
         typename Allocator>
struct is_map<tree<Key, null_type, Cmp_Fn, Tag, Node_Update, Allocator>> : false_type {};

template<typename Key, typename Hash_Fn, typename Eq_Fn, typename Comp_Probe_Fn, typename Probe_Fn,
         typename Resize_Policy, bool id8, typename Allocator>
struct is_map<
    gp_hash_table<Key, null_type, Hash_Fn, Eq_Fn, Comp_Probe_Fn, Probe_Fn, Resize_Policy, id8, Allocator>>
    : false_type {};

template<typename Key, typename Mapped, typename Cmp_Fn, typename Tag,
         template<typename Const_Node_Iterator, typename Node_Iterator, typename Cmp_Fn_, typename Allocator_>
         class Node_Update,
         typename Allocator>
struct is_map<tree<Key, Mapped, Cmp_Fn, Tag, Node_Update, Allocator>> : true_type {};

template<typename Key, typename Mapped, typename Hash_Fn, typename Eq_Fn, typename Comp_Probe_Fn, typename Probe_Fn,
         typename Resize_Policy, bool id8, typename Allocator>
struct is_map<gp_hash_table<Key, Mapped, Hash_Fn, Eq_Fn, Comp_Probe_Fn, Probe_Fn, Resize_Policy, id8, Allocator>>
    : true_type {};



template<class T>
inline constexpr bool id2 = is_sequence<T>::value;

template<class T>
inline constexpr bool id9 = is_set<T>::value;

template<class T>
inline constexpr bool id7 = is_map<T>::value;

template<class T>
inline constexpr bool id1 = is_adaptor<T>::value;

template<class T1, class T2>
istream& operator>>(istream& is, pair<T1, T2>& p) {
    return is >> p.first >> p.second;
}

template<class... Types, size_t... Is>
istream& scan_tuple(istream& is, tuple<Types...>& t, index_sequence<Is...>) {
    auto scan_elem = [&](auto& x) { is >> x; };
    (scan_elem(get<Is>(t)), ...);
    return is;
}

template<class... Types>
istream& operator>>(istream& is, tuple<Types...>& t) {
    return scan_tuple(is, t, make_index_sequence<sizeof...(Types)>{});
}

template<class T>
enable_if_t<id2<T>, istream&> operator>>(istream& is, T& t) {
    for (auto& x : t)
        is >> x;
    return is;
}

struct Fmt {
    string open;
    string sep;
    string close;
};

struct DictFmt : Fmt {
    string key_val_sep;
};

struct Printer {
    Fmt tuple_fmt;
    Fmt list_fmt;
    DictFmt dict_fmt;

    template<class T>
    ostream& print(ostream& os, const T& x) {
        return print(os, x, rank<1>());
    }
  private:
    template<class T>
    ostream& print(ostream& os, const T& x, rank<0>) {
        return os << x;
    }

    template<class T1, class T2>
    ostream& print(ostream& os, const pair<T1, T2>& p, rank<1>) {
        os << tuple_fmt.open;
        print(os, p.first);
        os << tuple_fmt.sep;
        print(os, p.second);
        return os << tuple_fmt.close;
    }

    template<class... Types, size_t... Is>
    ostream& print(ostream& os, const tuple<Types...>& t, index_sequence<Is...>) {
        bool print_sep = false;
        auto print_elem = [&](const auto& x) {
            if (print_sep)
                os << tuple_fmt.sep;
            print(os, x);
            print_sep = true;
        };
        os << tuple_fmt.open;
        (print_elem(get<Is>(t)), ...);
        return os << tuple_fmt.close;
    }

    template<class... Types>
    ostream& print(ostream& os, const tuple<Types...>& t, rank<1>) {
        return print(os, t, make_index_sequence<sizeof...(Types)>{});
    }

    template<class T>
    enable_if_t<id2<T>, ostream&> print(ostream& os, const T& l, rank<1>) {
        os << list_fmt.open;
        bool print_sep = false;
        for (auto it = l.begin(); it != l.end(); ++it) {
            if (print_sep)
                os << list_fmt.sep;
            print(os, *it);
            print_sep = true;
        }
        return os << list_fmt.close;
    }

    template<class T>
    enable_if_t<id9<T>, ostream&> print(ostream& os, const T& s, rank<1>) {
        os << dict_fmt.open;
        bool print_sep = false;
        for (auto it = s.begin(); it != s.end(); ++it) {
            if (print_sep)
                os << dict_fmt.sep;
            print(os, *it);
            print_sep = true;
        }
        return os << dict_fmt.close;
    }

    template<class T>
    enable_if_t<id7<T>, ostream&> print(ostream& os, const T& d, rank<1>) {
        os << dict_fmt.open;
        bool print_sep = false;
        for (auto it = d.begin(); it != d.end(); ++it) {
            if (print_sep)
                os << dict_fmt.sep;
            print(os, it->first);
            os << dict_fmt.key_val_sep;
            print(os, it->second);
            print_sep = true;
        }
        return os << dict_fmt.close;
    }

    template<class T>
    enable_if_t<id1<T>, ostream&> print(ostream& os, const T& a, rank<1>) {
        return print(os, get_container(a));
    }
};

DictFmt plain{"", " ", "", " "};
Printer printer{plain, plain, plain};
Printer pprinter{{"(", ", ", ")"}, {"[", ", ", "]"}, {"{", ", ", "}", ": "}};

template<class T1, class T2>
ostream& operator<<(ostream& os, const pair<T1, T2>& p) {
    return printer.print(os, p);
}

template<class... Types>
ostream& operator<<(ostream& os, const tuple<Types...>& t) {
    return printer.print(os, t);
}

template<class T>
enable_if_t<id2<T>, ostream&> operator<<(ostream& os, const T& l) {
    return printer.print(os, l);
}

template<class T>
enable_if_t<id9<T>, ostream&> operator<<(ostream& os, const T& s) {
    return printer.print(os, s);
}

template<class T>
enable_if_t<id7<T>, ostream&> operator<<(ostream& os, const T& d) {
    return printer.print(os, d);
}

template<class T>
enable_if_t<id1<T>, ostream&> operator<<(ostream& os, const T& a) {
    return printer.print(os, a);
}

[[nodiscard]] constexpr bool id6(char c) {
    switch (c) {
    case ' ':
    case '\n':
    case '\r':
    case '\f':
    case '\v':
    case '\t':
        return true;
    default:
        return false;
    }
}

[[nodiscard]] constexpr bool is_quote(char c) { return c == '\'' || c == '"'; }

constexpr void match_quote(string_view s, int& i, char c) {
    ++i;
    while (s[i] != c)
        ++i;
}

constexpr void id4(string_view s, int& i) {
    ++i;
    while (s[i] != ')') {
        if (is_quote(s[i]))
            match_quote(s, i, s[i]);
        else if (s[i] == '(')
            id4(s, i);
        ++i;
    }
}

template<class InputIt, class UnaryPredicate>
constexpr bool all_of(InputIt first, InputIt last, UnaryPredicate p) {
    for (; first != last; ++first)
        if (!p(*first))
            return false;
    return true;
}

[[nodiscard]] constexpr size_t count_args(string_view s) {
    if (::impl::all_of(s.begin(), s.end(), id6))
        return 0;
    int i = 0;
    size_t count = 1;
    while (i < s.size()) {
        if (is_quote(s[i]))
            match_quote(s, i, s[i]);
        else if (s[i] == '(')
            id4(s, i);
        else if (s[i] == ',')
            ++count;
        ++i;
    }
    return count;
}

template<size_t N>
[[nodiscard]] constexpr array<string_view, N> split_args(string_view s) {
    array<string_view, N> args;
    int i = -1;
    for (int ai = 0; ai < N; ++ai) {
        int j = i + 1;
        while (j < s.size() && s[j] != ',') {
            if (is_quote(s[j]))
                match_quote(s, j, s[j]);
            else if (s[j] == '(')
                id4(s, j);
            ++j;
        }
        string_view arg = s.substr(i + 1, j - i - 1);
        while (id6(arg.front()))
            arg.remove_prefix(1);
        while (id6(arg.back()))
            arg.remove_suffix(1);
        args.at(ai) = arg;
        i = j;
    }
    return args;
}

template<size_t N, typename... Args>
ostream& log(ostream& os, const char* file, int line, const array<string_view, N>& arg_names, const Args&... args) {
    log_prefix(os, file, line);
    int index = 0;
    auto log_pair = [&](const auto& x) {
        if (index)
            os << ", ";
        os << arg_names[index] << " = ";
        pprinter.print(os, x);
        ++index;
    };
    (log_pair(args), ...);
    return os;
}



    [&]() {                                                                                                            \
        constexpr auto x = (expr);                                                                                     \
        return x;                                                                                                      \
    }()

    ::impl::log(::std::cout, __FILE__, __LINE__,                                                                              \
                FORCE_CONSTEXPR(::impl::split_args<::impl::count_args(
        << '\n'                                                                                                        \
        << ::std::flush




} 


using impl::timer;

namespace rng {

using impl::rng::get;
using impl::rng::mt;

} 




using impl::tree_map;
using impl::tree_set;



using impl::hash_map;
using impl::hash_set;

using impl::operator>>;
using impl::DictFmt;
using impl::Fmt;
using impl::Printer;
using impl::operator<<;

template<class T>
using min_heap = std::priority_queue<T, std::vector<T>, std::greater<T>>;

template<class T>
using max_heap = std::priority_queue<T>;

template<class T>
constexpr T& min_assign(T& lhs, const T& rhs) {
    if (lhs > rhs)
        lhs = rhs;
    return lhs;
}

template<class T>
constexpr T& max_assign(T& lhs, const T& rhs) {
    if (lhs < rhs)
        lhs = rhs;
    return lhs;
}

template <class T>
constexpr int sgn(T x) {
    return (x > 0) - (x < 0);
}

template<class T>
constexpr T floor_div(T a, T b) {
    T d = a / b;
    T r = a % b;
    return r ? (d - ((a < 0) ^ (b < 0))) : d;
}

template<class T>
constexpr T ceil_div(T a, T b) {
    T d = a / b;
    T r = a % b;
    return r ? (d + ((a > 0) ^ (b < 0))) : d;
}

constexpr long long sq(long long x) {
    return x * x;
}

constexpr long double sq(long double x) {
    return x * x;
}

constexpr int INF = 1e9;
constexpr long long LLINF = 1e18;













 
using namespace std;
 
using pi = pair<int, int>;
using vi = vector<int>;
using vpi = vector<pi>;
using vvi = vector<vi>;
using ll = long long;
using pll = pair<ll, ll>;
using vll = vector<ll>;
using vpll = vector<pll>;
using vvll = vector<vll>;
using ld = long double;
using ull = unsigned long long;
using vc = vector<char>;
using vvc = vector<vc>;
 
int main(int argc, char** argv) {

    ios::sync_with_stdio(0);
    cin.tie(0);

    cout << setprecision(numeric_limits<long double>::max_digits10) << fixed;
    cout << boolalpha;
 
    int ts;
    cin >> ts;
    while (ts--) {
        int n;
        cin >> n;

        vvi a(1, vi(n)), b(1, vi(n)), na, nb;
        cin >> a >> b;

        int res = 0;
        ROF (i, 30, 0) {
            bool ok = true;
            FOR (j, 0, a.size()) {
                int ca = 0;
                int cb = 0;
                FOR (k, 0, a[j].size()) {
                    ca += (a[j][k] >> i) & 1;
                    cb += (b[j][k] >> i) & 1;
                }
                if (ca != a[j].size() - cb) {
                    ok = false;
                    break;
                }
            }

            if (ok) {
                res |= (1 << i);
                na.clear();
                nb.clear();
                FOR (j, 0, a.size()) {
                    vi oa, za, ob, zb;
                    FOR (k, 0, a[j].size()) {
                        if ((a[j][k] >> i) & 1)
                            oa.PB(a[j][k]);
                        else
                            za.PB(a[j][k]);
                        
                        if ((b[j][k] >> i) & 1)
                            ob.PB(b[j][k]);
                        else
                            zb.PB(b[j][k]);
                    }

                    if (!oa.empty()) {
                        na.PB(oa);
                        nb.PB(zb);
                    }
                    if (!za.empty()) {
                        na.PB(za);
                        nb.PB(ob);
                    }
                }

                swap(a, na);
                swap(b, nb);
            }
        }

        cout << res << '\n';
    }
}