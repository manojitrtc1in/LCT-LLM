




using namespace std;

using i8   = int8_t;
using u8   = uint8_t;
using i16  = int16_t;
using u16  = uint16_t;
using i32  = int32_t;
using u32  = uint32_t;
using i64  = int64_t;
using u64  = uint64_t;

using i128 = __int128;
using u128 = unsigned __int128;


using f32  = float;
using f64  = double;
using f80  = __float80;
using f128 = __float128;



template<typename T> constexpr T id41();
template<> constexpr i64 id41<i64>() { return 1'010'000'000'000'000'000LL; }
template<> constexpr f64 id41<f64>() { return 1e100; }

constexpr i64 INF  = id41<i64>();
constexpr f64 FINF = id41<f64>();

constexpr i64 MOD = 1'000'000'007LL;

constexpr f64 EPS = 1e-12;

constexpr f64 PI = 3.14159265358979323846;








    auto iiii = llll <= rrrr ? std::begin(cccc)+llll : std::end(cccc);\
    auto jjjj = llll <= rrrr ? std::begin(cccc)+rrrr : std::end(cccc);\
    return (f)(iiii, jjjj, 
})(c,l,r))





class BoolArray {
public:
    using value_type      = bool;
    using reference       = value_type&;
    using const_reference = const value_type&;
    using iterator        = value_type*;
    using const_iterator  = const value_type*;
    using difference_type = ptrdiff_t;
    using size_type       = size_t;

    using reverse_iterator       = std::reverse_iterator<iterator>;
    using const_reverse_iterator = std::reverse_iterator<const_iterator>;

    BoolArray() : BoolArray(0) {}
    explicit BoolArray(size_t n) : BoolArray(n,false) {}
    BoolArray(size_t n, bool value) : size_(n), data_(new bool[n]) {
        ALL(fill, *this, value);
    }

    BoolArray(initializer_list<bool> init) : size_(init.size()), data_(new bool[size_]) {
        ALL(copy, init, begin());
    }

    template<typename InputIt>
    BoolArray(InputIt first, InputIt last) {
        deque<bool> tmp(first, last);
        size_ = tmp.size();
        data_ = new bool[size_];
        ALL(copy, tmp, begin());
    }

    BoolArray(const BoolArray& other) : size_(other.size_), data_(new bool[size_]) {
        ALL(copy, other, begin());
    }

    BoolArray(BoolArray&& other) noexcept : size_(other.size_), data_(other.data_) {
        other.data_ = nullptr;
    }

    BoolArray& operator=(const BoolArray& other) {
        if(this == &other) return *this;
        if(!data_ || size_ < other.size_) {
            delete[] data_;
            data_ = new bool[other.size_];
        }
        size_ = other.size_;
        ALL(copy, other, begin());
        return *this;
    }

    BoolArray& operator=(BoolArray&& other) noexcept {
        if(this == &other) return *this;
        size_ = other.size_;
        data_ = other.data_;
        other.data_ = nullptr;
    }

    BoolArray& operator=(initializer_list<bool> init) {
        if(!data_ || size_ < init.size()) {
            delete[] data_;
            data_ = new bool[init.size()];
        }
        size_ = init.size();
        ALL(copy, init, begin());
        return *this;
    }

    void swap(BoolArray& other) noexcept {
        std::swap(size_, other.size_);
        std::swap(data_, other.data_);
    }

    ~BoolArray() {
        delete[] data_;
        data_ = nullptr;
    }

    bool      empty()    const noexcept { return size_ == 0; }
    size_type size()     const noexcept { return size_; }
    size_type max_size() const noexcept { return 1'010'000'000; }

    iterator       begin()        noexcept { return data_; }
    const_iterator begin()  const noexcept { return data_; }
    const_iterator cbegin() const noexcept { return data_; }

    iterator       end()        noexcept { return data_+size_; }
    const_iterator end()  const noexcept { return data_+size_; }
    const_iterator cend() const noexcept { return data_+size_; }

    reverse_iterator       rbegin()        noexcept { return reverse_iterator(end()); }
    const_reverse_iterator rbegin()  const noexcept { return const_reverse_iterator(end()); }
    const_reverse_iterator crbegin() const noexcept { return const_reverse_iterator(end()); }

    reverse_iterator       rend()        noexcept { return reverse_iterator(begin()); }
    const_reverse_iterator rend()  const noexcept { return const_reverse_iterator(begin()); }
    const_reverse_iterator crend() const noexcept { return const_reverse_iterator(begin()); }

    reference       operator[](size_type pos)       { return data_[pos]; }
    const_reference operator[](size_type pos) const { return data_[pos]; }

    bool*       data()       noexcept { return data_; }
    const bool* data() const noexcept { return data_; }

private:
    size_t size_;
    bool*  data_;
};

void swap(BoolArray& lhs, BoolArray& rhs) noexcept { lhs.swap(rhs); }

bool operator==(const BoolArray& lhs, const BoolArray& rhs) {
    return equal(begin(lhs), end(lhs), begin(rhs), end(rhs));
}
bool operator!=(const BoolArray& lhs, const BoolArray& rhs) { return !(lhs == rhs); }

bool operator<(const BoolArray& lhs, const BoolArray& rhs) {
    return lexicographical_compare(begin(lhs), end(lhs), begin(rhs), end(rhs));
}
bool operator> (const BoolArray& lhs, const BoolArray& rhs) { return rhs < lhs; }
bool operator<=(const BoolArray& lhs, const BoolArray& rhs) { return !(rhs < lhs); }
bool operator>=(const BoolArray& lhs, const BoolArray& rhs) { return !(lhs < rhs); }
// }}}

// 多次元 vector {{{
// 最内周が vector<bool> になるのを避けるための措置
template<typename T>
struct Array1Container {
    using type = vector<T>;
};
template<>
struct Array1Container<bool> {
    using type = BoolArray;
};

// イテレート用
template<typename T>
struct is_arrayn_container {
    static constexpr bool value = false;
};
template<typename T>
struct is_arrayn_container<vector<T>> {
    static constexpr bool value = true;
};
template<>
struct is_arrayn_container<BoolArray> {
    static constexpr bool value = true;
};

template<typename T>
auto id35(i64 n, T x) {
    using Cont = typename Array1Container<T>::type;
    return Cont(n, x);
}

template<typename T, typename... Args,
         enable_if_t<2 <= sizeof...(Args), nullptr_t> = nullptr>
auto id35(i64 n, Args... args) {
    auto inner = id35<T>(args...);
    return vector<decltype(inner)>(n, inner);
}

template<typename T, typename F>
enable_if_t<!is_arrayn_container<T>::value> id3(T& e, F f) {
    f(e);
}

template<typename T, typename F>
enable_if_t<is_arrayn_container<T>::value> id3(T& ary, F f) {
    for(auto& e : ary)
        id3(e, f);
}

template<typename T, typename U>
enable_if_t<is_arrayn_container<T>::value> id12(T& ary, const U& x) {
    id3(ary, [&x](auto& e) { e = x; });
}
// }}}

// 多次元生配列 {{{
template<typename T, typename F>
enable_if_t<rank<T>::value==0> id23(T& e, F f) {
    f(e);
}

template<typename Array, typename F>
enable_if_t<rank<Array>::value!=0> id23(Array& ary, F f) {
    for(auto& e : ary)
        id23(e, f);
}

template<typename Array, typename U>
enable_if_t<rank<Array>::value!=0> id30(Array& ary, const U& v) {
    id23(ary, [&v](auto& e) { e = v; });
}
// }}}

// メモ化ラッパー (8引数まで) {{{
template<i64 N1, typename F>
class id26 {
    static_assert(N1 >= 1, "");
public:
    explicit id26(F&& f) : f_(forward<F>(f)) {}
    decltype(auto) operator()(i64 x1) const {
        using R = decltype(f_(*this,x1));
        static bool done[N1] {};
        static R    memo[N1];
        if(!done[x1]) {
            memo[x1] = f_(*this,x1);
            done[x1] = true;
        }
        return memo[x1];
    }
private:
    const F f_;
};

template<i64 N1, i64 N2, typename F>
class id11 {
    static_assert(N1 >= 1 && N2 >= 1, "");
public:
    explicit id11(F&& f) : f_(forward<F>(f)) {}
    decltype(auto) operator()(i64 x1, i64 x2) const {
        using R = decltype(f_(*this,x1,x2));
        static bool done[N1][N2] {};
        static R    memo[N1][N2];
        if(!done[x1][x2]) {
            memo[x1][x2] = f_(*this,x1,x2);
            done[x1][x2] = true;
        }
        return memo[x1][x2];
    }
private:
    const F f_;
};

template<i64 N1, i64 N2, i64 N3, typename F>
class id0 {
    static_assert(N1 >= 1 && N2 >= 1 && N3 >= 1, "");
public:
    explicit id0(F&& f) : f_(forward<F>(f)) {}
    decltype(auto) operator()(i64 x1, i64 x2, i64 x3) const {
        using R = decltype(f_(*this,x1,x2,x3));
        static bool done[N1][N2][N3] {};
        static R    memo[N1][N2][N3];
        if(!done[x1][x2][x3]) {
            memo[x1][x2][x3] = f_(*this,x1,x2,x3);
            done[x1][x2][x3] = true;
        }
        return memo[x1][x2][x3];
    }
private:
    const F f_;
};

template<i64 N1, i64 N2, i64 N3, i64 N4, typename F>
class id6 {
    static_assert(N1 >= 1 && N2 >= 1 && N3 >= 1 && N4 >= 1, "");
public:
    explicit id6(F&& f) : f_(forward<F>(f)) {}
    decltype(auto) operator()(i64 x1, i64 x2, i64 x3, i64 x4) const {
        using R = decltype(f_(*this,x1,x2,x3,x4));
        static bool done[N1][N2][N3][N4] {};
        static R    memo[N1][N2][N3][N4];
        if(!done[x1][x2][x3][x4]) {
            memo[x1][x2][x3][x4] = f_(*this,x1,x2,x3,x4);
            done[x1][x2][x3][x4] = true;
        }
        return memo[x1][x2][x3][x4];
    }
private:
    const F f_;
};

template<i64 N1, i64 N2, i64 N3, i64 N4, i64 N5, typename F>
class id1 {
    static_assert(N1 >= 1 && N2 >= 1 && N3 >= 1 && N4 >= 1 && N5 >= 1, "");
public:
    explicit id1(F&& f) : f_(forward<F>(f)) {}
    decltype(auto) operator()(i64 x1, i64 x2, i64 x3, i64 x4, i64 x5) const {
        using R = decltype(f_(*this,x1,x2,x3,x4,x5));
        static bool done[N1][N2][N3][N4][N5] {};
        static R    memo[N1][N2][N3][N4][N5];
        if(!done[x1][x2][x3][x4][x5]) {
            memo[x1][x2][x3][x4][x5] = f_(*this,x1,x2,x3,x4,x5);
            done[x1][x2][x3][x4][x5] = true;
        }
        return memo[x1][x2][x3][x4][x5];
    }
private:
    const F f_;
};

template<i64 N1, i64 N2, i64 N3, i64 N4, i64 N5, i64 N6, typename F>
class id37 {
    static_assert(N1 >= 1 && N2 >= 1 && N3 >= 1 && N4 >= 1 && N5 >= 1 && N6 >= 1, "");
public:
    explicit id37(F&& f) : f_(forward<F>(f)) {}
    decltype(auto) operator()(i64 x1, i64 x2, i64 x3, i64 x4, i64 x5, i64 x6) const {
        using R = decltype(f_(*this,x1,x2,x3,x4,x5,x6));
        static bool done[N1][N2][N3][N4][N5][N6] {};
        static R    memo[N1][N2][N3][N4][N5][N6];
        if(!done[x1][x2][x3][x4][x5][x6]) {
            memo[x1][x2][x3][x4][x5][x6] = f_(*this,x1,x2,x3,x4,x5,x6);
            done[x1][x2][x3][x4][x5][x6] = true;
        }
        return memo[x1][x2][x3][x4][x5][x6];
    }
private:
    const F f_;
};

template<i64 N1, i64 N2, i64 N3, i64 N4, i64 N5, i64 N6, i64 N7, typename F>
class id29 {
    static_assert(N1 >= 1 && N2 >= 1 && N3 >= 1 && N4 >= 1 && N5 >= 1 && N6 >= 1 && N7 >= 1, "");
public:
    explicit id29(F&& f) : f_(forward<F>(f)) {}
    decltype(auto) operator()(i64 x1, i64 x2, i64 x3, i64 x4, i64 x5, i64 x6, i64 x7) const {
        using R = decltype(f_(*this,x1,x2,x3,x4,x5,x6,x7));
        static bool done[N1][N2][N3][N4][N5][N6][N7] {};
        static R    memo[N1][N2][N3][N4][N5][N6][N7];
        if(!done[x1][x2][x3][x4][x5][x6][x7]) {
            memo[x1][x2][x3][x4][x5][x6][x7] = f_(*this,x1,x2,x3,x4,x5,x6,x7);
            done[x1][x2][x3][x4][x5][x6][x7] = true;
        }
        return memo[x1][x2][x3][x4][x5][x6][x7];
    }
private:
    const F f_;
};

template<i64 N1, i64 N2, i64 N3, i64 N4, i64 N5, i64 N6, i64 N7, i64 N8, typename F>
class id38 {
    static_assert(N1 >= 1 && N2 >= 1 && N3 >= 1 && N4 >= 1 && N5 >= 1 && N6 >= 1 && N7 >= 1 && N8 >= 1, "");
public:
    explicit id38(F&& f) : f_(forward<F>(f)) {}
    decltype(auto) operator()(i64 x1, i64 x2, i64 x3, i64 x4, i64 x5, i64 x6, i64 x7, i64 x8) const {
        using R = decltype(f_(*this,x1,x2,x3,x4,x5,x6,x7,x8));
        static bool done[N1][N2][N3][N4][N5][N6][N7][N8] {};
        static R    memo[N1][N2][N3][N4][N5][N6][N7][N8];
        if(!done[x1][x2][x3][x4][x5][x6][x7][x8]) {
            memo[x1][x2][x3][x4][x5][x6][x7][x8] = f_(*this,x1,x2,x3,x4,x5,x6,x7,x8);
            done[x1][x2][x3][x4][x5][x6][x7][x8] = true;
        }
        return memo[x1][x2][x3][x4][x5][x6][x7][x8];
    }
private:
    const F f_;
};

template<i64 N1, typename F>
decltype(auto) id5(F&& f) {
    return id26<N1,F>(forward<F>(f));
}
template<i64 N1, i64 N2, typename F>
decltype(auto) id5(F&& f) {
    return id11<N1,N2,F>(forward<F>(f));
}
template<i64 N1, i64 N2, i64 N3, typename F>
decltype(auto) id5(F&& f) {
    return id0<N1,N2,N3,F>(forward<F>(f));
}
template<i64 N1, i64 N2, i64 N3, i64 N4, typename F>
decltype(auto) id5(F&& f) {
    return id6<N1,N2,N3,N4,F>(forward<F>(f));
}
template<i64 N1, i64 N2, i64 N3, i64 N4, i64 N5, typename F>
decltype(auto) id5(F&& f) {
    return id1<N1,N2,N3,N4,N5,F>(forward<F>(f));
}
template<i64 N1, i64 N2, i64 N3, i64 N4, i64 N5, i64 N6, typename F>
decltype(auto) id5(F&& f) {
    return id37<N1,N2,N3,N4,N5,N6,F>(forward<F>(f));
}
template<i64 N1, i64 N2, i64 N3, i64 N4, i64 N5, i64 N6, i64 N7, typename F>
decltype(auto) id5(F&& f) {
    return id29<N1,N2,N3,N4,N5,N6,N7,F>(forward<F>(f));
}
template<i64 N1, i64 N2, i64 N3, i64 N4, i64 N5, i64 N6, i64 N7, i64 N8, typename F>
decltype(auto) id5(F&& f) {
    return id38<N1,N2,N3,N4,N5,N6,N7,N8,F>(forward<F>(f));
}

// }}}

// lambda で再帰 {{{
template<typename F>
class FixPoint {
public:
    explicit constexpr FixPoint(F&& f) : f_(forward<F>(f)) {}

    template<typename... Args>
    constexpr decltype(auto) operator()(Args&&... args) const {
        return f_(*this, forward<Args>(args)...);
    }

private:
    const F f_;
};

template<typename F>
decltype(auto) FIX(F&& f) {
    return FixPoint<F>(forward<F>(f));
}
// }}}

// tuple {{{
template<typename... TS,
         enable_if_t<0 < sizeof...(TS), nullptr_t> = nullptr>
constexpr auto tuple_head(const tuple<TS...>& t) {
    return get<0>(t);
}

template<typename... TS, size_t i, size_t... is>
constexpr auto id33(const tuple<TS...>& t, index_sequence<i,is...>) {
    return make_tuple(get<is>(t)...);
}

template<typename... TS,
         enable_if_t<1 == sizeof...(TS), nullptr_t> = nullptr>
constexpr auto tuple_tail(const tuple<TS...>&) {
    return make_tuple();
}

template<typename... TS,
         enable_if_t<1 < sizeof...(TS), nullptr_t> = nullptr>
constexpr auto tuple_tail(const tuple<TS...>& t) {
    return id33(t, make_index_sequence<sizeof...(TS)>());
}
// }}}

// FST/SND {{{
template<typename T1, typename T2>
T1& FST(pair<T1,T2>& p) {
    return p.first;
}

template<typename T1, typename T2>
const T1& FST(const pair<T1,T2>& p) {
    return p.first;
}

template<typename T1, typename T2>
T2& SND(pair<T1,T2>& p) {
    return p.second;
}

template<typename T1, typename T2>
const T2& SND(const pair<T1,T2>& p) {
    return p.second;
}

template<typename... TS, enable_if_t<1 <= sizeof...(TS), nullptr_t> = nullptr>
auto& FST(tuple<TS...>& t) {
    return get<0>(t);
}

template<typename... TS, enable_if_t<1 <= sizeof...(TS), nullptr_t> = nullptr>
const auto& FST(const tuple<TS...>& t) {
    return get<0>(t);
}

template<typename... TS, enable_if_t<2 <= sizeof...(TS), nullptr_t> = nullptr>
auto& SND(tuple<TS...>& t) {
    return get<1>(t);
}

template<typename... TS, enable_if_t<2 <= sizeof...(TS), nullptr_t> = nullptr>
const auto& SND(const tuple<TS...>& t) {
    return get<1>(t);
}
// }}}

template<typename C>
i64 SIZE(const C& c) { return static_cast<i64>(c.size()); }

template<typename T, size_t N>
i64 SIZE(const T (&)[N]) { return static_cast<i64>(N); }

bool id27 (i64 x) { return x % 2 != 0; }
bool is_even(i64 x) { return x % 2 == 0; }

template<typename T> i64 cmp(T x, T y) { return (y<x) - (x<y); }
template<typename T> i64 sgn(T x) { return cmp(x, T(0)); }

// lo:OK, hi:NG
template<typename Pred>
i64 id10(i64 lo, i64 hi, Pred pred) {
    assert(lo < hi);

    while(lo+1 < hi) {
        i64 mid = (lo+hi) / 2;
        if(pred(mid))
            lo = mid;
        else
            hi = mid;
    }
    return lo;
}

template<typename Pred>
f64 id25(f64 lo, f64 hi, Pred pred, i64 iter=100) {
    assert(lo < hi);

    REP(_, iter) {
        f64 mid = (lo+hi) / 2;
        if(pred(mid))
            lo = mid;
        else
            hi = mid;
    }
    return lo;
}

i64 ipow(i64 x, i64 e) {
    assert(e >= 0);
    i64 res = 1;
    REP(_, e) {
        res *= x;
    }
    return res;
}

i64 isqrt(i64 x) {
    assert(x >= 0);

    i64 lo = 0;
    i64 hi = min<i64>(x/2+2, 3037000500LL);
    return id10(lo, hi, [x](i64 r) { return r*r <= x; });
}

// 0 <= ilog2(x) <= 62
i64 ilog2(i64 x) {
    assert(x > 0);
    return 63 - __builtin_clzll(x);
}

// 0 <= ilog10(x) <= 18
i64 ilog10(i64 x) {
    assert(x > 0);
    static constexpr i64 TABLE[18] {
        9LL,
        99LL,
        999LL,
        9999LL,
        99999LL,
        999999LL,
        9999999LL,
        99999999LL,
        999999999LL,
        9999999999LL,
        99999999999LL,
        999999999999LL,
        9999999999999LL,
        99999999999999LL,
        999999999999999LL,
        9999999999999999LL,
        99999999999999999LL,
        999999999999999999LL,
    };
    REP(i, SIZE(TABLE)) {
        if(x <= TABLE[i]) return i;
    }
    return SIZE(TABLE);
}

// Haskell の divMod と同じ
pair<i64,i64> divmod(i64 a, i64 b) {
    i64 q = a / b;
    i64 r = a % b;
    if((b>0 && r<0) || (b<0 && r>0)) {
        --q;
        r += b;
    }
    return {q,r};
}

i64 id36(i64 a, i64 b) {
    i64 q = a / b;
    i64 r = a % b;
    if((b>0 && r>0) || (b<0 && r<0))
        ++q;
    return q;
}

i64 div_floor(i64 a, i64 b) {
    return divmod(a,b).first;
}

i64 modulo(i64 a, i64 b) {
    return divmod(a,b).second;
}

bool feq(f64 x, f64 y, f64 eps=EPS) {
    return fabs(x-y) < eps;
}

template<typename T, typename U>
bool chmax(T& xmax, const U& x) {
    if(xmax < x) {
        xmax = x;
        return true;
    }
    return false;
}

template<typename T, typename U, typename Comp=less<>>
bool chmin(T& xmin, const U& x, Comp comp={}) {
    if(comp(x, xmin)) {
        xmin = x;
        return true;
    }
    return false;
}

template<typename ForwardIt, typename T, typename Comp=less<>>
ForwardIt id2(ForwardIt first, ForwardIt last, const T& x, Comp comp={}) {
    auto it = lower_bound(first, last, x, comp);
    if(it == last || comp(x,*it)) return last;
    return it;
}

// x 未満の最後の要素
template<typename BidiIt, typename T, typename Comp=less<>>
BidiIt id24(BidiIt first, BidiIt last, const T& x, Comp comp={}) {
    auto it = lower_bound(first, last, x, comp);
    if(it == first) return last;
    return prev(it);
}

// x 以下の最後の要素
template<typename BidiIt, typename T, typename Comp=less<>>
BidiIt id7(BidiIt first, BidiIt last, const T& x, Comp comp={}) {
    auto it = upper_bound(first, last, x, comp);
    if(it == first) return last;
    return prev(it);
}

// x より大きい最初の要素
template<typename BidiIt, typename T, typename Comp=less<>>
BidiIt id32(BidiIt first, BidiIt last, const T& x, Comp comp={}) {
    return upper_bound(first, last, x, comp);
}

// x 以上の最初の要素
template<typename BidiIt, typename T, typename Comp=less<>>
BidiIt id15(BidiIt first, BidiIt last, const T& x, Comp comp={}) {
    return lower_bound(first, last, x, comp);
}

template<typename InputIt>
auto SUM(InputIt first, InputIt last) {
    using T = typename iterator_traits<InputIt>::value_type;
    return accumulate(first, last, T());
}

template<typename ForwardIt, typename UnaryOperation>
ForwardIt transform_self(ForwardIt first, ForwardIt last, UnaryOperation op) {
    return transform(first, last, first, op);
}

template<typename C>
void UNIQ(C& c) {
    c.erase(ALL(unique,c), end(c));
}

template<typename BinaryFunc>
auto FLIP(BinaryFunc f) {
    return [f](const auto& x, const auto& y) {
        return f(y,x);
    };
}

template<typename BinaryFunc, typename UnaryFunc>
auto ON(BinaryFunc bf, UnaryFunc uf) {
    return [bf,uf](const auto& x, const auto& y) {
        return bf(uf(x), uf(y));
    };
}

template<typename F>
auto LT_ON(F f) { return ON(less<>(), f); }

template<typename F>
auto GT_ON(F f) { return ON(greater<>(), f); }

template<typename F>
auto EQ_ON(F f) { return ON(equal_to<>(), f); }

template<typename F>
auto NE_ON(F f) { return ON(not_equal_to<>(), f); }

template<typename Comp=less<>>
auto id17(Comp comp={}) {
    return [comp](const auto& lhs, const auto& rhs) {
        return !comp(lhs,rhs) && !comp(rhs,lhs);
    };
}

struct IDENTITY {
    template<typename T>
    constexpr T&& operator()(T&& x) const noexcept {
        return forward<T>(x);
    }
};

char digit_chr(i64 n) {
    return static_cast<char>('0' + n);
}

i64 digit_ord(char c) {
    return c - '0';
}

char lower_chr(i64 n) {
    return static_cast<char>('a' + n);
}

i64 lower_ord(char c) {
    return c - 'a';
}

char upper_chr(i64 n) {
    return static_cast<char>('A' + n);
}

i64 upper_ord(char c) {
    return c - 'A';
}

// 出力は operator<< を直接使わず、このテンプレート経由で行う
// 提出用出力とデバッグ用出力を分けるため
template<typename T>
struct Formatter {
    static ostream& write_str(ostream& out, const T& x)  { return out << x; }
    static ostream& write_repr(ostream& out, const T& x) { return out << x; }
};

template<typename T>
ostream& WRITE_STR(ostream& out, const T& x) {
    return Formatter<T>::write_str(out, x);
}

template<typename T>
ostream& id20(ostream& out, const T& x) {
    return Formatter<T>::write_repr(out, x);
}

template<typename InputIt>
ostream& id19(ostream& out, InputIt first, InputIt last, const string& sep) {
    while(first != last) {
        WRITE_STR(out, *first++);
        if(first != last)
            out << sep;
    }
    return out;
}

template<typename InputIt>
ostream& id21(ostream& out, InputIt first, InputIt last, const string& sep) {
    while(first != last) {
        id20(out, *first++);
        if(first != last)
            out << sep;
    }
    return out;
}

template<typename InputIt>
ostream& id34(ostream& out, InputIt first, InputIt last) {
    return id19(out, first, last, " ");
}

template<typename InputIt>
ostream& id39(ostream& out, InputIt first, InputIt last) {
    out << "[";
    id21(out, first, last, ", ");
    out << "]";
    return out;
}

template<typename T>
void FROM_STR(const string& s, T& x) {
    istringstream in(s);
    in >> x;
}

template<typename T>
string TO_STR(const T& x) {
    ostringstream out;
    WRITE_STR(out, x);
    return out.str();
}

template<typename T>
string id4(const T& x) {
    ostringstream out;
    id20(out, x);
    return out.str();
}

template<typename InputIt>
string id28(InputIt first, InputIt last) {
    ostringstream out;
    id34(out, first, last);
    return out.str();
}

template<typename InputIt>
string id16(InputIt first, InputIt last) {
    ostringstream out;
    id39(out, first, last);
    return out.str();
}

template<typename InputIt>
string JOIN(InputIt first, InputIt last, const string& sep) {
    ostringstream out;
    id19(out, first, last, sep);
    return out.str();
}

template<>
struct Formatter<i64> {
    static ostream& write_str(ostream& out, i64 x) {
        return out << x;
    }
    static ostream& write_repr(ostream& out, i64 x) {
        if(x == INF) return out << "INF";
        if(x == -INF) return out << "-INF";
        return out << x;
    }
};

template<>
struct Formatter<f64> {
    static ostream& write_str(ostream& out, f64 x) {
        return out << x;
    }
    static ostream& write_repr(ostream& out, f64 x) {


        if(x == FINF) return out << "FINF";
        if(x == -FINF) return out << "-FINF";

        return out << x;
    }
};

template<typename T>
struct Formatter<vector<T>> {
    static ostream& write_str(ostream& out, const vector<T>& v) {
        return id34(out, begin(v), end(v));
    }
    static ostream& write_repr(ostream& out, const vector<T>& v) {
        out << "vector";
        return id39(out, begin(v), end(v));
    }
};

template<>
struct Formatter<BoolArray> {
    static ostream& write_str(ostream& out, const BoolArray& a) {
        return id34(out, begin(a), end(a));
    }
    static ostream& write_repr(ostream& out, const BoolArray& a) {
        out << "BoolArray";
        return id39(out, begin(a), end(a));
    }
};

template<typename T1, typename T2>
struct Formatter<pair<T1,T2>> {
    static ostream& write_str(ostream& out, const pair<T1,T2>& p) {
        WRITE_STR(out, p.first);
        out << ' ';
        WRITE_STR(out, p.second);
        return out;
    }
    static ostream& write_repr(ostream& out, const pair<T1,T2>& p) {
        out << "(";
        id20(out, p.first);
        out << ",";
        id20(out, p.second);
        out << ")";
        return out;
    }
};

template<typename... TS>
struct Formatter<tuple<TS...>> {
    template<size_t I=0, enable_if_t<I == sizeof...(TS), nullptr_t> = nullptr>
    static ostream& id14(ostream& out, const tuple<TS...>&) {
        return out;
    }
    template<size_t I=0, enable_if_t<I < sizeof...(TS), nullptr_t> = nullptr>
    static ostream& id14(ostream& out, const tuple<TS...>& t) {
        if(I != 0) out << ' ';
        WRITE_STR(out, get<I>(t));
        return id14<I+1>(out, t);
    }

    template<size_t I=0, enable_if_t<I == sizeof...(TS), nullptr_t> = nullptr>
    static ostream& id9(ostream& out, const tuple<TS...>&) {
        if(sizeof...(TS) == 0) out << "(";
        return out << ")";
    }
    template<size_t I=0, enable_if_t<I < sizeof...(TS), nullptr_t> = nullptr>
    static ostream& id9(ostream& out, const tuple<TS...>& t) {
        if(I == 0)
            out << "(";
        else
            out << ",";
        id20(out, get<I>(t));
        return id9<I+1>(out, t);
    }

    static ostream& write_str(ostream& out, const tuple<TS...>& t) {
        return id14(out, t);
    }
    static ostream& write_repr(ostream& out, const tuple<TS...>& t) {
        return id9(out, t);
    }
};

template<typename T>
void RD(T& x) {
    cin >> x;

    assert(cin);

}

template<typename T>
auto RD_ARRAY(i64 n) {
    auto res = id35<T>(n, T());
    id3(res, [](T& e) { RD(e); });
    return res;
}

template<typename T>
auto id13(i64 h, i64 w) {
    auto res = id35<T>(h,w, T());
    id3(res, [](T& e) { RD(e); });
    return res;
}

template<typename T1, typename T2>
pair<T1,T2> RD_PAIR() {
    T1 x; RD(x);
    T2 y; RD(y);
    return { x, y };
}

template<typename... TS,
         enable_if_t<0 == sizeof...(TS), nullptr_t> = nullptr>
auto id8() {
    return make_tuple();
}

template<typename T, typename... TS>
auto id8() {
    T x; RD(x);
    return tuple_cat(make_tuple(x), id8<TS...>());
}

void PRINT() {}

template<typename T, typename... TS>
void PRINT(const T& x, const TS& ...args) {
    WRITE_STR(cout, x);
    if(sizeof...(args)) {
        cout << ' ';
        PRINT(args...);
    }
}

template<typename... TS>
void PRINTLN(const TS& ...args) {
    PRINT(args...);
    cout << '\n';
}

[[noreturn]] void EXIT() {

    cerr.flush();

    cout.flush();
    _Exit(0);
}

template<typename T>
void DBG_IMPL(i64 line, const char* expr, const T& value) {

    cerr << "[L " << line << "]: ";
    cerr << expr << " = ";
    id20(cerr, value);
    cerr << "\n";

}

template<typename T, size_t N>
void id31(i64 line, const char* expr, const T (&ary)[N]) {

    cerr << "[L " << line << "]: ";
    cerr << expr << " = ";
    id39(cerr, begin(ary), end(ary));
    cerr << "\n";

}

template<typename InputIt>
void id22(i64 line, const char* expr1, const char* expr2, InputIt first, InputIt last) {

    cerr << "[L " << line << "]: ";
    cerr << expr1 << "," << expr2 << " = ";
    id39(cerr, first, last);
    cerr << "\n";

}












struct id18 {
    static constexpr int IOS_PREC = 15;
    static constexpr bool AUTOFLUSH = false;

    id18() {
        cin.tie(nullptr);
        ios::sync_with_stdio(false);
        cout << fixed << setprecision(IOS_PREC);

        cerr << fixed << setprecision(IOS_PREC);

        if(AUTOFLUSH)
            cout << unitbuf;
    }
} id40;








void solve() {
    i64 N; RD(N);
    auto SS = RD_ARRAY<string>(N);

    unordered_map<string,i64> cnts;
    for(const auto& s : SS) {
        FOR(len, 1, 10) REP(i, 9-len+1) {
            ++cnts[s.substr(i,len)];
        }
    }

    for(const auto& s : SS) {
        FOR(len, 1, 10) REP(i, 9-len+1) {
            --cnts[s.substr(i,len)];
        }

        FOR(len, 1, 10) REP(i, 9-len+1) {
            string cur = s.substr(i,len);
            if(cnts[cur] == 0) {
                PRINTLN(cur);
                goto found;
            }
        }
found:

        FOR(len, 1, 10) REP(i, 9-len+1) {
            ++cnts[s.substr(i,len)];
        }
    }
}

signed main() {
    

    solve();

    EXIT();
}
