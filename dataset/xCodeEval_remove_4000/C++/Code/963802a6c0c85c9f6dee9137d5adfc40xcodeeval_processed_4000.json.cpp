


using namespace std;


using u64 = uint64_t;
using u32 = uint32_t;
using i64 = int64_t;
using i32 = int32_t;
using i16 = int16_t;
using i8 = int8_t;
template <typename ...Ts>
using vt = std::vector<Ts...>;
template <typename ...Ts>
using mp = std::map<Ts...>;
template <typename ...Ts>
using um = std::unordered_map<Ts...>;
template <typename ...Ts>
using st = std::set<Ts...>;
template <typename ...Ts>
using us = std::unordered_set<Ts...>;
const i64 inf = (1ll << 62);
const i64 imin = std::numeric_limits<i64>::min();
const i64 imax = std::numeric_limits<i64>::max();
const i64 umax = std::numeric_limits<u64>::max();
template <typename T> T abs_m(T a) { return a >= 0 ? a : -a; }
auto maxi(i64 a, i64 b) { return a > b ? a : b; }
auto maxu(u64 a, u64 b) { return a > b ? a : b; }
auto minu(u64 a, u64 b) { return a < b ? a : b; }
auto mini(i64 a, i64 b) { return a < b ? a : b; }
void merror(std::string msg, i64 line_number) { std::cerr << "assert >> " << line_number << ": " << msg << std::endl; exit(42); }







template <typename C> i64 isize(const C& c) { return static_cast<i64>(c.size()); }
template <typename T, size_t N> i64 isize(const std::array<T, N>& = {}) { return static_cast<i64>(N); }
template <typename It, typename Cont> bool it_last(It it, const Cont& c) { return ++it == c.end(); }




namespace fun {
template <class Cont, class Fun>
auto map(Cont const& c, Fun const& f) {
    std::vector<std::decay_t<decltype(f(*c.begin()))>> v;
    v.reserve(isize(c));
    std::transform(c.begin(), c.end(),
            std::back_inserter(v),
            f);
    return v;
}
template <class Cont, class Fun>
void id1(Cont & c, Fun const& f) {
    std::transform(c.begin(), c.end(),
            c.begin(),
            f);
}
template <class Cont1, class Cont2>
auto merge(Cont1 const& range1, Cont2 const& range2) {
    std::vector<std::decay_t<decltype(*range1.begin())>> v;
    v.reserve(isize(range1) + isize(range2));
    std::merge(range1.begin(), range1.end(),
            range2.begin(), range2.end(),
            std::back_inserter(v));
    return v;
}
template <class Cont, class ...Args>
void sort(Cont & cont, Args && ...args) {
    std::sort(cont.begin(), cont.end(),
            std::forward<Args>(args)...);
}
template <class Cont, class ...Args>
auto sorted(Cont cont, Args && ...args) {
    sort(cont, std::forward<Args>(args)...);
    return cont;
}
template <class Cont>
void reverse(Cont & cont) {
    std::reverse(cont.begin(), cont.end());
}
template <class Cont>
auto reversed(Cont cont) {
    reverse(cont);
    return cont;
}
template <class Cont, class ...Args>
auto count(Cont cont, Args && ...args) {
    return std::count(cont.begin(), cont.end(), args...);
}
template <class Cont>
auto min_element(Cont const& cont) {
    return std::min_element(cont.begin(), cont.end());
}

auto lex_compare = [](auto const& r1, auto const& r2)
    { return std::lexicographical_compare(r1.begin(), r1.end(), r2.begin(), r2.end()); };

auto first = [](auto const& e) { return e.first; };
auto second = [](auto const& e) { return e.second; };
template <std::size_t n> auto nth = [](auto const& e) { return std::get<n>(e); };

auto surround = [](auto const& a, char b, char c = '\0') { return b + a + (c ? c : b); };
template <typename T> const auto identity = [](const T& t) -> const T& { return t; };
auto join = [](auto const& container, auto const& separator, auto const& mapper) {
    std::string s;
    for (auto it = container.begin(); it != container.end(); it++) {
        if (it != container.begin())
            s += separator;
        s += mapper(*it);
    }
    return s;
};
} 

template <class T> auto vector_less(T const& a, T const& b) { return fun::lex_compare(a, b); }




template<class F, class T, int id6>
struct TupleForeach { auto operator()(F const& f, T const& t) {
    auto static constexpr n = static_cast<int>(std::tuple_size<T>::value) - id6 - 1;
    f(n, std::get<n>(t));
    TupleForeach<F, T, id6 - 1>()(f, t);
}};
template<class F, class T>
struct TupleForeach<F, T, -1> { auto operator()(F const&, T const&) {
}};
template <class F, class T> void id7(F const& f, T const& t)
    { TupleForeach<F, T, std::tuple_size<T>::value - 1>()(f, t); }
template <class F, class S, class ...Ts>
auto join_tuple(std::tuple<Ts...> const& tpl, S const& separator, F const& mapper) {
    std::string res;
    id7([&](i64 num, auto const& e) {
        if (num != 0) res += separator;
        res += mapper(e);
    }, tpl);
    return res;
}




template<class...> using void_t = void;
template <class, class = void> struct has_repr : std::false_type {};
template <class T> struct has_repr<T, void_t<decltype(std::declval<T>()._repr())>> : std::true_type {};
template <class, class = void> struct has_str : std::false_type {};
template <class T> struct has_str<T, void_t<decltype(std::declval<T>()._str())>> : std::true_type {};
template <class, class = void> struct has_read : std::false_type {};
template <class T> struct has_read<T, void_t<decltype(std::declval<T>()._read())>> : std::true_type {};
template <class, class = void> struct is_map : std::false_type {};
template <class T> struct is_map<T, void_t<typename T::key_type, typename T::mapped_type>> : std::true_type {};
template <class, class = void> struct is_set : std::false_type {};
template <class T> struct is_set<T, void_t<typename T::key_type>> : std::true_type {};
template <class T> constexpr bool id3()
    { return std::is_same<std::decay_t<T>, char*>::value || std::is_same<std::decay_t<T>, const char*>::value; }
template <class, class = void> struct is_ptr : std::false_type {};
template <class ...Ts> struct is_ptr<std::shared_ptr<Ts...>> : std::true_type {};
template <class ...Ts> struct is_ptr<std::unique_ptr<Ts...>> : std::true_type {};
template <class ...Ts> struct is_ptr<std::weak_ptr<Ts...>> : std::true_type {};
template <class T> struct is_ptr<T, void_t<std::enable_if_t<std::is_pointer<T>::value && !id3<T>()>>>
    : std::true_type {};




template <class T, class = void> struct _Str { auto operator()(const T& t)
    { return std::to_string(t); }};
template <class T> std::string str(const T& t)
    { return _Str<T>()(t); }
template <> struct _Str<std::string> { auto operator()(const std::string& t)
    { return t; }};
template <class T> struct _Str<T, std::enable_if_t<id3<T>()>> { auto operator()(T const& t)
    { return std::string(t); }};
template <> struct _Str<char> { auto operator()(char const& t)
    { return std::string(1, t); }};
template <class T> struct _Str<T, std::enable_if_t<is_ptr<T>::value>> { auto operator()(T const& t)
    { return t ? str(*t) : str("(nullptr)"); }};
template <class T> struct _Str<T, std::enable_if_t<has_str<T>::value>> { auto operator()(T const& t)
    { return t._str(); }};
template <class T> struct _Str<std::reference_wrapper<T>> { auto operator()(T const& t)
    { return str(t.get()); }};
struct StrFunctor { template <class T> auto operator()(T const& t) const; };
template <class T, std::size_t N> struct _Str<std::array<T, N>> { auto operator()(std::array<T, N> const& t)
    { return fun::join(t, ' ', StrFunctor()); }};
template <class T> struct _Str<std::vector<T>> { auto operator()(std::vector<T> const& t)
    { return fun::join(t, ' ', StrFunctor()); }};
template <class T> struct _Str<T, std::enable_if_t<is_set<T>::value && !is_map<T>::value>>
        { auto operator()(T const& t)
    { return fun::join(t, ' ', StrFunctor()); }};
template <class T> struct _Str<T, std::enable_if_t<is_map<T>::value>> { auto operator()(T const& t)
    { return fun::join(t, ' ', StrFunctor()); }};
template <class ...Ts> struct _Str<std::tuple<Ts...>> { auto operator()(std::tuple<Ts...> const& t)
    { return join_tuple(t, ' ', StrFunctor()); }};
template <class T1, class T2> struct _Str<std::pair<T1, T2>> { auto operator()(const std::pair<T1, T2>& p)
    { return str(std::make_tuple(p.first, p.second)); }};
template <class T> auto StrFunctor::operator()(T const& t) const
    { return str(t); }




template <class T, class = void> struct _Repr { auto operator()(T const& t)
    { return str(t); }};
template <class T> std::string repr(const T& t)
    { return _Repr<T>()(t); }
template <> struct _Repr<std::string> { auto operator()(const std::string& t)
    { return fun::surround(str(t), '"'); }};
template <> struct _Repr<char> { auto operator()(char const& t)
    { return fun::surround(str(t), '\''); }};
template <class T> struct _Repr<T, std::enable_if_t<id3<T>()>> { auto operator()(T const& t)
    { return fun::surround(str(t), '"'); }};
template <class T> struct _Repr<T, std::enable_if_t<is_ptr<T>::value>> { auto operator()(T const& t)
    { return t ? repr(*t) : str(t); }};
template <class T> struct _Repr<T, std::enable_if_t<has_repr<T>::value>> { auto operator()(T const& t)
    { return t._repr(); }};
template <class T> struct _Repr<std::reference_wrapper<T>> { auto operator()(T const& t)
    { return repr(t.get()); }};
struct ReprFunctor { template <class T> auto operator()(T const& t) const; };
template <class T, std::size_t N> struct _Repr<std::array<T, N>> { auto operator()(std::array<T, N> const& t)
    { return fun::surround(fun::join(t, ',', ReprFunctor()), '[', ']'); }};
template <class T> struct _Repr<std::vector<T>> { auto operator()(std::vector<T> const& t)
    { return fun::surround(fun::join(t, ',', ReprFunctor()), '[', ']'); }};
template <class T> struct _Repr<T, std::enable_if_t<is_set<T>::value && !is_map<T>::value>>
        { auto operator()(T const& t)
    { return fun::surround(fun::join(t, ',', ReprFunctor()), '{', '}'); }};
auto id2 = [](auto const& item) { return join_tuple(std::make_tuple(item.first, item.second), ':', ReprFunctor()); };
template <class T> struct _Repr<T, std::enable_if_t<is_map<T>::value>> { auto operator()(T const& t)
    { return fun::surround(fun::join(t, ',', id2), '{', '}'); }};
template <class ...Ts> struct _Repr<std::tuple<Ts...>> { auto operator()(std::tuple<Ts...> const& t)
    { return fun::surround(join_tuple(t, ',', ReprFunctor()), '(', ')'); }};
template <class T1, class T2> struct _Repr<std::pair<T1, T2>> { auto operator()(const std::pair<T1, T2>& p)
    { return repr(std::make_tuple(p.first, p.second)); }};
template <class T> auto ReprFunctor::operator()(T const& t) const
    { return repr(t); }
template <class ...Ts>
auto make_repr(std::string classname, const std::vector<std::string>& header, Ts &&... ts) {
    massert(isize(header) == sizeof...(ts), "header wrong length");
    std::string res;
    id7([&](auto i, auto const& v) {
        if (i != 0) res += ',';
        res += header[i] + "=" + repr(v);
    }, std::make_tuple(std::forward<Ts>(ts)...));
    return classname + fun::surround(res, '(', ')');
}




template <class T>
struct Reader { T operator()()
    { T e = {}; std::cin >> e; return e; }};
template <class T> T read()
    { return Reader<T>()(); }
template <class T, std::size_t N> struct Reader<std::array<T, N>> { std::array<T, N> operator()()
    { std::array<T, N> res = {}; for (std::size_t i = 0; i < N; i++) res[i] = read<T>(); return res; }};
void read() {}
template <class T, class ...Ts> void read(T& v, Ts& ...ts)
    { v = read<T>(); read(ts...); }
template <class T> void readv(i64 n, std::vector<T>& v)
    { std::generate_n(std::back_inserter(v), n, [](){ return read<T>(); }); }
template <class T> std::vector<T> readv(i64 n)
    { std::vector<T> v; readv(n, v); return v; }




template <char c> struct Printer {
    template <class ...Ts> void operator()(Ts const&... ts)
        { outp << str(std::forward_as_tuple(ts...)) << c; }
    std::ostream& outp;
};
auto print = Printer<' '>{std::cout};
auto println = Printer<'\n'>{std::cout};
auto lprint = Printer<' '>{std::cerr};
auto lprintln = Printer<'\n'>{std::cerr};

auto dprint = Printer<' '>{std::cerr};
auto dprintln = Printer<'\n'>{std::cerr};








size_t id4() { return 1241245u; }
template <class T, class ...Ts>
size_t id4(T const& t, Ts const&... ts) {
    return (std::hash<T>()(t) + 12431u) ^ id4(ts...);
}






void go() {
    i64 n;
    read(n);
    vt<i64> v, t;
    readv(n, v);
    readv(n, t);

    vt<i64> ts;
    ts.push_back(t[0]);
    for (i64 i = 1; i < isize(t); i++)
        ts.push_back(t[i] + ts[i - 1]);
    vt<i64> intervals(n, 0);
    vt<i64> id5(n, 0);
    for (i64 i = 0; i < isize(v); i++) {
        if (v[i] == 0)
            continue;
        i64 const id0 = (i == 0 ? 0 : ts[i - 1]);
        i64 const j = lower_bound(ts.begin(), ts.end(), v[i] + id0) - ts.begin();
        dprintln("i:", i, "j:", j);
        if (j < isize(ts)) {
            i64 const tsinterval = (j == 0 ? 0 : ts[j - 1] - id0);
            dprintln("tsinterval:", tsinterval);
            id5[j] += v[i] - tsinterval;
            --intervals[j];
        }
        ++intervals[i];
    }
    i64 opens = 0;
    for (i64 i = 0; i < n; i++) {
        opens += intervals[i];
        id5[i] += opens * t[i];
    }
    println(id5);

}


int main () { 

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    go();
} 

