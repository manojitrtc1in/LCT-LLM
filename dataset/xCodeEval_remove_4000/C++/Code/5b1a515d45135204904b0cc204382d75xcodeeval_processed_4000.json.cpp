




using namespace std;










using i8  = int8_t;
using u8  = uint8_t;
using i16 = int16_t;
using u16 = uint16_t;
using i32 = int32_t;
using u32 = uint32_t;
using i64 = int64_t;
using u64 = uint64_t;

using f32 = float;
using f64 = double;
using f80 = __float80;



constexpr i64 INF  = INT64_C(1'010'000'000'000'000'017);
constexpr f64 FINF = 1e100;

constexpr i64 MOD = INT64_C(1'000'000'007);
//constexpr i64 MOD = INT64_C(998'244'353);

constexpr f64 EPS = 1e-12;

constexpr f64 PI = 3.14159265358979323846;

// util {{{







template<typename C>
constexpr i64 SIZE(const C& c) noexcept { return static_cast<i64>(c.size()); }

template<typename T, size_t N>
constexpr i64 SIZE(const T (&)[N]) noexcept { return static_cast<i64>(N); }

template<typename T, SFINAE(is_signed<T>::value)>
constexpr T ABS(T x) noexcept {
    return x < 0 ? -x : x;
}

template<typename T>
constexpr i64 CMP(T x, T y) noexcept { return (y<x) - (x<y); }

template<typename T>
constexpr i64 SGN(T x) noexcept { return CMP(x,T(0)); }

template<typename T, typename U, typename Comp=less<>>
constexpr bool chmax(T& xmax, const U& x, Comp comp={}) noexcept {
    if(comp(xmax, x)) {
        xmax = x;
        return true;
    }
    return false;
}

template<typename T, typename U, typename Comp=less<>>
constexpr bool chmin(T& xmin, const U& x, Comp comp={}) noexcept {
    if(comp(x, xmin)) {
        xmin = x;
        return true;
    }
    return false;
}

template<typename BinaryFunc, typename UnaryFunc>
auto ON(BinaryFunc&& bf, UnaryFunc&& uf) {
    return [bf=forward<BinaryFunc>(bf),uf=forward<UnaryFunc>(uf)](const auto& x, const auto& y) {
        return bf(uf(x), uf(y));
    };
}

template<typename F>
auto LT_ON(F&& f) {
    return ON(less<>{}, forward<F>(f));
}

template<typename F>
auto GT_ON(F&& f) {
    return ON(greater<>{}, forward<F>(f));
}

template<typename F>
auto EQ_ON(F&& f) {
    return ON(equal_to<>{}, forward<F>(f));
}

template<typename F>
auto NE_ON(F&& f) {
    return ON(not_equal_to<>{}, forward<F>(f));
}

// tuple {{{
template<i64 I=0, typename F, typename... TS, SFINAE(sizeof...(TS) == I)>
void id10(tuple<TS...>&, F&&) {}

template<i64 I=0, typename F, typename... TS, SFINAE(sizeof...(TS) > I)>
void id10(tuple<TS...>& t, F&& f) {
    f(I, get<I>(t));
    id10<I+1>(t, forward<F>(f));
}

template<i64 I=0, typename F, typename... TS, SFINAE(sizeof...(TS) == I)>
void id10(const tuple<TS...>&, F&&) {}

template<i64 I=0, typename F, typename... TS, SFINAE(sizeof...(TS) > I)>
void id10(const tuple<TS...>& t, F&& f) {
    f(I, get<I>(t));
    id10<I+1>(t, forward<F>(f));
}
// }}}

// container {{{
template<typename T> struct is_container : false_type {};
template<typename T, size_t N> struct is_container<array<T,N>> : true_type {};
template<typename... Args> struct is_container<vector<Args...>> : true_type {};
template<typename... Args> struct is_container<deque<Args...>> : true_type {};
template<typename... Args> struct is_container<list<Args...>> : true_type {};
template<typename... Args> struct is_container<forward_list<Args...>> : true_type {};
template<typename... Args> struct is_container<set<Args...>> : true_type {};
template<typename... Args> struct is_container<multiset<Args...>> : true_type {};
template<typename... Args> struct is_container<unordered_set<Args...>> : true_type {};
template<typename... Args> struct is_container<unordered_multiset<Args...>> : true_type {};
template<typename... Args> struct is_container<map<Args...>> : true_type {};
template<typename... Args> struct is_container<multimap<Args...>> : true_type {};
template<typename... Args> struct is_container<unordered_map<Args...>> : true_type {};
template<typename... Args> struct is_container<unordered_multimap<Args...>> : true_type {};

template<typename T, typename Enable=void>
struct ProconHash {
    size_t operator()(const T& x) const noexcept {
        return hash<T>{}(x);
    }
};

template<typename T>
size_t id4(const T& x) noexcept {
    return ProconHash<T>{}(x);
}

size_t id0(size_t h1, size_t h2) noexcept {
    constexpr size_t M = UINT64_C(0xc6a4a7935bd1e995);
    constexpr int    R = 47;

    h2 *= M;
    h2 ^= h2 >> R;
    h2 *= M;

    h1 ^= h2;
    h1 *= M;

    h1 += 0xe6546b64;

    return h1;
}

template<typename T1, typename T2>
struct ProconHash<pair<T1,T2>> {
    size_t operator()(const pair<T1,T2>& p) const noexcept {
        size_t h1 = id4(p.first);
        size_t h2 = id4(p.second);
        return id0(h1, h2);
    }
};

template<typename... TS>
struct ProconHash<tuple<TS...>> {
    size_t operator()(const tuple<TS...>& t) const noexcept {
        size_t h = 0;
        id10(t, [&h](i64, const auto& e) {
            h = id0(h, id4(e));
        });
        return h;
    }
};

template<typename C>
struct ProconHash<C,enable_if_t<is_container<C>::value>> {
    size_t operator()(const C& c) const noexcept {
        size_t h = 0;
        for(const auto& e : c)
            h = id0(h, id4(e));
        return h;
    }
};

template<typename T, typename Hash=ProconHash<T>, typename Eq=equal_to<T>>
using HashSet = unordered_set<T,Hash,Eq>;
template<typename K, typename V, typename Hash=ProconHash<K>, typename Eq=equal_to<K>>
using HashMap = unordered_map<K,V,Hash,Eq>;
template<typename T, typename Hash=ProconHash<T>, typename Eq=equal_to<T>>
using HashMultiset = unordered_multiset<T,Hash,Eq>;
template<typename K, typename V, typename Hash=ProconHash<K>, typename Eq=equal_to<K>>
using HashMultimap = unordered_multimap<K,V,Hash,Eq>;

template<typename T>
auto vec_make(i64 n, T x) {
    return vector<T>(n, x);
}

template<typename T, typename... Args, SFINAE(sizeof...(Args) >= 2)>
auto vec_make(i64 n, Args... args) {
    auto inner = vec_make<T>(args...);
    return vector<decltype(inner)>(n, inner);
}

template<typename T>
auto id21(i64 cap) {
    vector<T> res;
    res.reserve(cap);
    return res;
}

template<typename T=i64>
auto id26(i64 n, T init={}) {
    vector<i64> res(n);
    ALL(iota, res, init);
    return res;
}

template<typename T, typename Comp, typename Cont=vector<T>>
auto id2(const Comp& comp, Cont&& cont={}) {
    return priority_queue<T,remove_reference_t<Cont>,Comp>(comp, forward<Cont>(cont));
}

template<typename T, typename Comp>
auto id15(const Comp& comp, i64 cap) {
    return priority_queue<T,vector<T>,Comp>(comp, id21<T>(cap));
}

template<typename T, size_t N, size_t... NS>
struct ArrayType {
    using type = array<typename ArrayType<T,NS...>::type,N>;
};

template<typename T, size_t N>
struct ArrayType<T,N> {
    using type = array<T,N>;
};

template<typename T, size_t... NS>
using Array = typename ArrayType<T,NS...>::type;

template<typename T, size_t N>
T& array_at(Array<T,N>& ary, i64 i) {
    return ary[i];
}

template<typename T, size_t N, size_t... NS, typename... Args>
T& array_at(Array<T,N,NS...>& ary, i64 i, Args... args) {
    return array_at<T,NS...>(ary[i], args...);
}

template<typename T, size_t N>
const T& array_at(const Array<T,N>& ary, i64 i) {
    return ary[i];
}

template<typename T, size_t N, size_t... NS, typename... Args>
const T& array_at(const Array<T,N,NS...>& ary, i64 i, Args... args) {
    return array_at<T,NS...>(ary[i], args...);
}

template<typename T, typename C>
T POP(stack<T,C>& stk) {
    T x = stk.top(); stk.pop();
    return x;
}

template<typename T, typename C>
T POP(queue<T,C>& que) {
    T x = que.front(); que.pop();
    return x;
}

template<typename T, typename C, typename Comp>
T POP(priority_queue<T,C,Comp>& que) {
    T x = que.top(); que.pop();
    return x;
}
// }}}

// fixpoint {{{
template<typename F>
class FixPoint {
public:
    explicit constexpr FixPoint(F&& f) : f_(forward<F>(f)) {}

    template<typename... Args>
    constexpr decltype(auto) operator()(Args&&... args) const {
        return f_(*this, forward<Args>(args)...);
    }

private:
    F f_;
};

template<typename F>
constexpr decltype(auto) FIX(F&& f) {
    return FixPoint<F>(forward<F>(f));
}

template<typename F, size_t... NS>
class id5 {
public:
    explicit id5(F&& f) : f_(forward<F>(f)) {}

    template<typename... Args>
    decltype(auto) operator()(Args... args) const {
        using R = decltype(f_(*this,args...));
        static Array<bool,NS...> done {};
        static Array<R,NS...>    memo;

        if(!array_at<bool,NS...>(done,args...)) {
            array_at<R,NS...>(memo,args...) = f_(*this,args...);
            array_at<bool,NS...>(done,args...) = true;
        }
        return array_at<R,NS...>(memo,args...);
    }

private:
    F f_;
};

template<size_t... NS, typename F>
decltype(auto) id1(F&& f) {
    return id5<F,NS...>(forward<F>(f));
}
// }}}

// math {{{
/*constexpr*/ i64 GCD(i64 a, i64 b) noexcept {
    /*constexpr*/ auto id12 = FIX([](auto&& self, i64 aa, i64 bb) {
        if(bb == 0) return aa;
        return self(bb, aa%bb);
    });
    return id12(ABS(a), ABS(b));
}

/*constexpr*/ i64 LCM(i64 a, i64 b) noexcept {
    ASSERT(a != 0 && b != 0);
    /*constexpr*/ auto id12 = FIX([](auto&& self, i64 aa, i64 bb) {
        if(bb == 0) return aa;
        return self(bb, aa%bb);
    });
    a = ABS(a);
    b = ABS(b);
    return a / id12(a,b) * b;
}

/*constexpr*/ tuple<i64,i64,i64> id16(i64 a, i64 b) noexcept {
    /*constexpr*/ auto impl = FIX([](auto&& self, i64 aa, i64 bb) -> tuple<i64,i64,i64> {
        if(bb == 0) return make_tuple(aa, 1, 0);
        i64 g,x,y; tie(g,x,y) = self(bb, aa%bb);
        return make_tuple(g, y, x-(aa/bb)*y);
    });
    i64 g,x,y; tie(g,x,y) = impl(ABS(a), ABS(b));
    x *= SGN(a);
    y *= SGN(b);
    return make_tuple(g, x, y);
}
// }}}

// string {{{
auto id20(i64 cap) {
    string res;
    res.reserve(cap);
    return res;
}
// }}}

// input {{{
template<typename T, typename Enable=void>
struct Scan {
    static T scan(istream& in) {
        T res;
        in >> res;
        return res;
    }
};

template<typename T, typename Enable=void>
struct Scan1;

template<typename T>
struct Scan1<T,enable_if_t<is_integral<T>::value && !is_same<T,bool>::value>> {
    static T scan1(istream& in) {
        return Scan<T>::scan(in) - 1;
    }
};

template<typename T1, typename T2>
struct Scan<pair<T1,T2>> {
    static pair<T1,T2> scan(istream& in) {
        T1 x = Scan<T1>::scan(in);
        T2 y = Scan<T2>::scan(in);
        return {x,y};
    }
};

template<typename T1, typename T2>
struct Scan1<pair<T1,T2>> {
    static pair<T1,T2> scan1(istream& in) {
        T1 x = Scan1<T1>::scan1(in);
        T2 y = Scan1<T2>::scan1(in);
        return {x,y};
    }
};

template<typename... TS>
struct Scan<tuple<TS...>> {
    static tuple<TS...> scan(istream& in) {
        return scan_impl<0>(in);
    }
private:
    template<i64 I, SFINAE(sizeof...(TS) == I)>
    static auto scan_impl(istream&) {
        return make_tuple();
    }
    template<i64 I, SFINAE(sizeof...(TS) > I)>
    static auto scan_impl(istream& in) {
        using T = tuple_element_t<I,tuple<TS...>>;
        auto head = make_tuple(Scan<T>::scan(in));
        return tuple_cat(head, scan_impl<I+1>(in));
    }
};

template<typename... TS>
struct Scan1<tuple<TS...>> {
    static tuple<TS...> scan1(istream& in) {
        return id6<0>(in);
    }
private:
    template<i64 I, SFINAE(sizeof...(TS) == I)>
    static auto id6(istream&) {
        return make_tuple();
    }
    template<i64 I, SFINAE(sizeof...(TS) > I)>
    static auto id6(istream& in) {
        using T = tuple_element_t<I,tuple<TS...>>;
        auto head = make_tuple(Scan1<T>::scan1(in));
        return tuple_cat(head, id6<I+1>(in));
    }
};

template<typename T=i64>
T RD() {
    return Scan<T>::scan(cin);
}

template<typename T=i64>
T RD1() {
    return Scan1<T>::scan1(cin);
}

template<typename T=i64>
auto RD_VEC(i64 n) {
    auto res = id21<T>(n);
    REP(_, n) {
        res.emplace_back(RD<T>());
    }
    return res;
}

template<typename T=i64>
auto id3(i64 n) {
    auto res = id21<T>(n);
    REP(_, n) {
        res.emplace_back(RD1<T>());
    }
    return res;
}

template<typename T=i64>
auto id18(i64 h, i64 w) {
    auto res = id21<vector<T>>(h);
    REP(_, h) {
        res.emplace_back(RD_VEC<T>(w));
    }
    return res;
}

template<typename T=i64>
auto id28(i64 h, i64 w) {
    auto res = id21<vector<T>>(h);
    REP(_, h) {
        res.emplace_back(id3<T>(w));
    }
    return res;
}
// }}}

// output {{{
template<typename T, typename Enable=void>
struct Fmt {
    static void fmt(ostream& out, const T& x) { out << x; }
};

template<typename T>
void fmt_write(ostream& out, const T& x) {
    Fmt<T>::fmt(out, x);
}

template<typename... TS>
struct Fmt<tuple<TS...>> {
    static void fmt(ostream& out, const tuple<TS...>& t) {
        id10(t, [&out](i64 i, const auto& e) {
            if(i != 0) out << ' ';
            fmt_write(out, e);
        });
    }
};

template<typename T1, typename T2>
struct Fmt<pair<T1,T2>> {
    static void fmt(ostream& out, const pair<T1,T2>& p) {
        return fmt_write(out, make_tuple(p.first,p.second));
    }
};

template<typename C>
struct Fmt<C,enable_if_t<is_container<C>::value>> {
    static void fmt(ostream& out, const C& c) {
        for(auto it = begin(c); it != end(c); ++it) {
            if(it != begin(c)) out << ' ';
            fmt_write(out, *it);
        }
    }
};

void PRINT() {}

template<typename T, typename... TS>
void PRINT(const T& x, const TS&... args) {
    fmt_write(cout, x);
    if(sizeof...(args) > 0) {
        cout << ' ';
        PRINT(args...);
    }
}

template<typename... TS>
void PRINTLN(const TS&... args) {
    PRINT(args...);
    cout << '\n';
}
// }}}

// debug {{{
template<typename T, typename Enable=void>
struct Dbg {
    static void dbg(ostream& out, const T& x) { out << x; }
};

template<typename T>
void dbg_write(ostream& out, const T& x) {
    return Dbg<T>::dbg(out, x);
}

template<>
struct Dbg<i64> {
    static void dbg(ostream& out, i64 x) {
        if(x == INF)
            out << "INF";
        else if(x == -INF)
            out << "-INF";
        else
            out << x;
    }
};

template<>
struct Dbg<f64> {
    static void dbg(ostream& out, f64 x) {


        if(x == FINF)
            out << "FINF";
        else if(x == -FINF)
            out << "-FINF";
        else
            out << x;

    }
};

template<typename T, size_t N>
struct Dbg<T[N]> {
    static void dbg(ostream& out, const T (&ary)[N]) {
        out << "[";
        REP(i, N) {
            if(i != 0) out << ",";
            dbg_write(out, ary[i]);
        }
        out << "]";
    }
};

template<typename... TS>
struct Dbg<tuple<TS...>> {
    static void dbg(ostream& out, const tuple<TS...>& t) {
        out << "(";
        id10(t, [&out](i64 i, const auto& e) {
            if(i != 0) out << ",";
            dbg_write(out, e);
        });
        out << ")";
    }
};

template<typename T1, typename T2>
struct Dbg<pair<T1,T2>> {
    static void dbg(ostream& out, const pair<T1,T2>& p) {
        return dbg_write(out, make_tuple(p.first,p.second));
    }
};

template<typename C>
struct Dbg<C,enable_if_t<is_container<C>::value>> {
    static void dbg(ostream& out, const C& c) {
        out << "[";
        for(auto it = begin(c); it != end(c); ++it) {
            if(it != begin(c)) out << ",";
            dbg_write(out, *it);
        }
        out << "]";
    }
};

template<typename T, typename C>
struct Dbg<stack<T,C>> {
    static void dbg(ostream& out, stack<T,C> stk) {
        out << "[";
        while(!stk.empty()) {
            dbg_write(out,stk.top()); stk.pop();
            if(!stk.empty()) out << ",";
        }
        out << "]";
    }
};

template<typename T, typename C>
struct Dbg<queue<T,C>> {
    static void dbg(ostream& out, queue<T,C> que) {
        out << "[";
        while(!que.empty()) {
            dbg_write(out,que.front()); que.pop();
            if(!que.empty()) out << ",";
        }
        out << "]";
    }
};

template<typename T, typename C, typename Comp>
struct Dbg<priority_queue<T,C,Comp>> {
    static void dbg(ostream& out, priority_queue<T,C,Comp> que) {
        out << "[";
        while(!que.empty()) {
            dbg_write(out,que.top()); que.pop();
            if(!que.empty()) out << ",";
        }
        out << "]";
    }
};

template<typename T>
void DBG_IMPL(i64 line, const char* expr, const T& value) {
    cerr << "[L " << line << "]: ";
    cerr << expr << " = ";
    dbg_write(cerr, value);
    cerr << "\n";
}

void id8() {}

template<typename T, typename... TS>
void id8(const T& x, const TS&... args) {
    dbg_write(cerr, x);
    if(sizeof...(args) > 0) {
        cerr << ",";
        id8(args...);
    }
}

template<typename... TS>
void DBG_IMPL(i64 line, const char* expr, const TS&... value) {
    cerr << "[L " << line << "]: ";
    cerr << "(" << expr << ") = (";
    id8(value...);
    cerr << ")\n";
}

template<size_t N, typename T, SFINAE(rank<T>::value == 0)>
void id27(ostream& out, const T& x, const array<i64,N>&, const array<i64,N>&) {
    dbg_write(out, x);
}

template<size_t N, typename T, SFINAE(rank<T>::value > 0)>
void id27(ostream& out, const T& x, const array<i64,N>& sizes, const array<i64,N>& offs) {
    i64 k   = N - rank<T>::value;
    i64 off = offs[k];
    i64 siz = sizes[k];
    if(siz == 0) siz = extent<T>::value - off;

    out << "[";
    FOR(i, off, off+siz) {
        if(i != off) out << ",";
        id27(out, x[i], sizes, offs);
    }
    out << "]";
}

template<typename T, SFINAE(rank<T>::value > 0)>
void id7(i64 line, const char* expr, const T& dp,
                 const array<i64,rank<T>::value>& sizes={},
                 const array<i64,rank<T>::value>& offs={})
{
    cerr << "[L " << line << "]: ";
    cerr << expr << " = ";
    id27<rank<T>::value>(cerr, dp, sizes, offs);
    cerr << "\n";
}

template<typename T>
void id19(i64 line, const char* expr, const vector<T>& grid) {
    cerr << "[L " << line << "]: ";
    cerr << expr << ":\n";
    for(const auto& row : grid) {
        dbg_write(cerr, row);
        cerr << "\n";
    }
    cerr << "\n";
}


    
    
    

    
    
    

// }}}

// modint {{{
template<i64 M>
struct id14 {
    static_assert(M >= 2, "");
    i64 v_;  // [0,M)

    id14() : v_(0) {}
    id14(i64 v) {
        i64 r = v % M;
        v_ = r >= 0 ? r : r+M;
    }

    id14 operator-() const {
        return id14(-v_);
    }
    id14& operator+=(id14 rhs) {
        v_ += rhs.v_;
        v_ %= M;
        return *this;
    }
    id14& operator-=(id14 rhs) {
        v_ += M;
        v_ -= rhs.v_;
        v_ %= M;
        return *this;
    }
    id14& operator*=(id14 rhs) {
        v_ *= rhs.v_;
        v_ %= M;
        return *this;
    }

    id14& operator++() {
        return *this += 1;
    }
    id14& operator--() {
        return *this -= 1;
    }
    id14 operator++(int) {
        return exchange(*this, *this+1);
    }
    id14 operator--(int) {
        return exchange(*this, *this-1);
    }

    explicit operator i64() const { return v_; }

    id14 inv() const {
        i64 g,x; tie(g,x,ignore) = id16(v_, M);
        ASSERT(g == 1);
        return id14(x);
    }
};

template<i64 M>
id14<M> operator+(id14<M> lhs, id14<M> rhs) { return id14<M>(lhs) += rhs; }
template<i64 M>
id14<M> operator+(id14<M> lhs, i64 rhs) { return id14<M>(lhs) += rhs; }
template<i64 M>
id14<M> operator+(i64 lhs, id14<M> rhs) { return id14<M>(rhs) += lhs; }
template<i64 M>
id14<M> operator-(id14<M> lhs, id14<M> rhs) { return id14<M>(lhs) -= rhs; }
template<i64 M>
id14<M> operator-(id14<M> lhs, i64 rhs) { return id14<M>(lhs) -= rhs; }
template<i64 M>
id14<M> operator-(i64 lhs, id14<M> rhs) { return id14<M>(rhs) -= lhs; }
template<i64 M>
id14<M> operator*(id14<M> lhs, id14<M> rhs) { return id14<M>(lhs) *= rhs; }
template<i64 M>
id14<M> operator*(id14<M> lhs, i64 rhs) { return id14<M>(lhs) *= rhs; }
template<i64 M>
id14<M> operator*(i64 lhs, id14<M> rhs) { return id14<M>(rhs) *= lhs; }

template<i64 M>
bool operator==(id14<M> lhs, id14<M> rhs) { return lhs.v_ == rhs.v_; }
template<i64 M>
bool operator==(id14<M> lhs, i64 rhs) { return lhs == id14<M>(rhs); }
template<i64 M>
bool operator==(i64 lhs, id14<M> rhs) { return id14<M>(lhs) == rhs; }
template<i64 M>
bool operator!=(id14<M> lhs, id14<M> rhs) { return !(lhs == rhs); }
template<i64 M>
bool operator!=(id14<M> lhs, i64 rhs) { return !(lhs == rhs); }
template<i64 M>
bool operator!=(i64 lhs, id14<M> rhs) { return !(lhs == rhs); }

template<i64 M>
struct Scan<id14<M>> {
    static id14<M> scan(istream& in) {
        return Scan<i64>::scan(in);
    }
};

template<i64 M>
struct Fmt<id14<M>> {
    static void fmt(ostream& out, id14<M> x) {
        fmt_write(out, x.v_);
    }
};

template<i64 M>
struct Dbg<id14<M>> {
    static void dbg(ostream& out, id14<M> x) {
        dbg_write(out, x.v_);
    }
};

using ModInt = id14<MOD>;
// }}}
// }}}

// init {{{
struct id11 {
    static constexpr int IOS_PREC = 15;
    static constexpr bool AUTOFLUSH = true;

    id11() {
        cin.tie(nullptr);
        ios::sync_with_stdio(false);
        cin.exceptions(ios::failbit | ios::badbit);
        cout << fixed << setprecision(IOS_PREC);

        cerr << fixed << setprecision(2);

        if(AUTOFLUSH)
            cout << unitbuf;
    }
} id25;
// }}}

//--------------------------------------------------------------------

bool query(i64 y1, i64 x1, i64 y2, i64 x2) {
    PRINTLN('?', y1+1, x1+1, y2+1, x2+1);  // 1-based
    i64 res = RD();
    DBG(y1,x1,y2,x2,res);
    if(res == -1) exit(0);
    return res == 1;
}

void answer(const vector<vector<i64>>& ans) {
    i64 n = SIZE(ans);
    PRINTLN('!');
    REP(y, n) {
        REP(x, n) {
            PRINT(ans[y][x]);
        }
        PRINTLN();
    }
}

pair<i64,i64> id24(i64 i) {
    return { i/3, i%3 };
}

i64 id23(i64 y, i64 x) {
    return 3*y + x;
}

i64 board_get(i64 board, i64 i) {
    return (board&(1LL<<i)) ? 1 : 0;
}

i64 board_get(i64 board, i64 y, i64 x) {
    return board_get(board, id23(y,x));
}

bool id13(const vector<i64>& v) {
    auto rev(v);
    ALL(reverse, rev);
    return v == rev;
}

bool id17(i64 board, i64 sy, i64 sx, i64 gy, i64 gx) {
    auto dfs = FIX([board,gy,gx](auto&& self, i64 y, i64 x, vector<i64>& trace) -> bool {
        constexpr i64 DY[2] { 0, 1 };
        constexpr i64 DX[2] { 1, 0 };

        trace.emplace_back(board_get(board,y,x));
        if(y == gy && x == gx) {
            

            bool res = id13(trace);
            trace.pop_back();
            return res;
        }

        REP(i, 2) {
            i64 yy = y+DY[i];
            i64 xx = x+DX[i];
            if(yy >= 3 || xx >= 3) continue;
            if(self(yy, xx, trace)) return true;
        }

        trace.pop_back();

        return false;
    });

    vector<i64> trace;
    return dfs(sy,sx,trace);
}

constexpr pair<pair<i64,i64>,pair<i64,i64>> QS[6] {
    { {0,0}, {1,2} },
    { {0,0}, {2,1} },
    { {0,1}, {2,2} },
    { {0,1}, {1,2} },
    { {0,1}, {2,1} },
    { {1,0}, {1,2} },
};

bool is_ok(i64 board, i64 mask) {
    REP(i, SIZE(QS)) {
        i64 sy,sx; tie(sy,sx) = QS[i].first;
        i64 gy,gx; tie(gy,gx) = QS[i].second;
        bool expect = mask&(1LL<<i);
        bool actual = id17(board, sy, sx, gy, gx);
        if(expect != actual) return false;
    }
    return true;
}

auto id9(const vector<vector<i64>>& grid, i64 k) {
    auto cands = id21<i64>(1LL<<4);
    {
        i64 b0 = grid[k][k];
        i64 b2 = grid[k][k+2];
        i64 b4 = grid[k+1][k+1];
        i64 b6 = grid[k+2][k];
        i64 b8 = grid[k+2][k+2];
        REP(i, 1LL<<4) {
            i64 cand = b0 | (b2<<2) | (b4<<4) | (b6<<6) | (b8<<8) |
                       ((i&1)<<1) | ((i&2)<<2) | ((i&4)<<3) | ((i&8)<<4);
            cands.emplace_back(cand);
        }
    }

    vector<vector<i64>> sols(1LL<<SIZE(QS));  

    REP(i, 1LL<<SIZE(QS)) {
        for(const auto& cand : cands) {
            if(is_ok(cand,i))
                sols[i].emplace_back(cand);
        }
    }
    DBG(sols);

    bool ok = ALL(all_of, sols, [](const auto& e) { return SIZE(e) <= 1; });
    DBG(ok);
    ASSERT(ok);

    i64 mask = 0;
    REP(i, SIZE(QS)) {
        i64 y1,x1; tie(y1,x1) = QS[i].first;
        i64 y2,x2; tie(y2,x2) = QS[i].second;
        bool b = query(y1+k, x1+k, y2+k, x2+k);
        if(b) mask |= 1LL<<i;
    }

    ASSERT(!sols[mask].empty());
    i64 sol = sols[mask][0];

    vector<i64> res;
    res.emplace_back((sol&(1LL<<1)) ? 1 : 0);
    res.emplace_back((sol&(1LL<<3)) ? 1 : 0);
    res.emplace_back((sol&(1LL<<5)) ? 1 : 0);
    res.emplace_back((sol&(1LL<<7)) ? 1 : 0);
    return res;
}

void solve() {
    i64 N = RD();

    auto ans = vec_make<i64>(N,N, -1);
    ans[0][0] = 1;
    ans[N-1][N-1] = 0;

    auto spread = [&ans](i64 y1, i64 x1, i64 y2, i64 x2) {
        ASSERT(ABS(y1-y2)+ABS(x1-x2) == 2);
        i64 sy = y1;
        i64 sx = x1;
        i64 gy = y2;
        i64 gx = x2;
        if(sy > gy || sx > gx) {
            swap(sy, gy);
            swap(sx, gx);
        }
        bool same = query(sy, sx, gy, gx);
        ans[y2][x2] = same ? ans[y1][x1] : (ans[y1][x1]^1);
    };

    auto id22 = [N,&ans,&spread](i64 sy, i64 sx) {
        constexpr i64 DY[6] { -2, -1,  0, 0, 1, 2 };
        constexpr i64 DX[6] {  0, -1, -2, 2, 1, 0 };

        queue<pair<i64,i64>> que;
        que.emplace(sy,sx);

        while(!que.empty()) {
            i64 y,x; tie(y,x) = POP(que);

            REP(i, 6) {
                i64 toy = y+DY[i];
                i64 tox = x+DX[i];
                DBG(toy,tox);
                if(toy < 0 || N <= toy || tox < 0 || N <= tox) continue;
                if(ans[toy][tox] != -1) continue;
                spread(y, x, toy, tox);
                que.emplace(toy,tox);
            }
        }
    };

    id22(0,0);

    REP(i, N-2) {
        if(ans[i][i] == 1 && ans[i+2][i+2] == 0) {
            auto v = id9(ans, i);
            ans[i][i+1]   = v[0];
            ans[i+1][i]   = v[1];
            ans[i+1][i+2] = v[2];
            ans[i+2][i+1] = v[3];
            id22(i,i+1);
            id22(i+1,i);
            id22(i+1,i+2);
            id22(i+2,i+1);
            break;
        }
    }

    answer(ans);
}

signed main() {
    

    solve();

    return 0;
}
