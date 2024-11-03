




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



template<typename T> constexpr T id55();
template<> constexpr i64 id55<i64>() { return 1'010'000'000'000'000'000LL; }
template<> constexpr f64 id55<f64>() { return 1e100; }

constexpr i64 INF  = id55<i64>();
constexpr f64 FINF = id55<f64>();

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
auto id46(i64 n, T x) {
    using Cont = typename Array1Container<T>::type;
    return Cont(n, x);
}

template<typename T, typename... Args,
         enable_if_t<2 <= sizeof...(Args), nullptr_t> = nullptr>
auto id46(i64 n, Args... args) {
    auto inner = id46<T>(args...);
    return vector<decltype(inner)>(n, inner);
}

template<typename T, typename F>
enable_if_t<!is_arrayn_container<T>::value> id6(T& e, F f) {
    f(e);
}

template<typename T, typename F>
enable_if_t<is_arrayn_container<T>::value> id6(T& ary, F f) {
    for(auto& e : ary)
        id6(e, f);
}

template<typename T, typename U>
enable_if_t<is_arrayn_container<T>::value> id18(T& ary, const U& x) {
    id6(ary, [&x](auto& e) { e = x; });
}
// }}}

// 多次元生配列 {{{
template<typename T, typename F>
enable_if_t<rank<T>::value==0> id33(T& e, F f) {
    f(e);
}

template<typename Array, typename F>
enable_if_t<rank<Array>::value!=0> id33(Array& ary, F f) {
    for(auto& e : ary)
        id33(e, f);
}

template<typename Array, typename U>
enable_if_t<rank<Array>::value!=0> id40(Array& ary, const U& v) {
    id33(ary, [&v](auto& e) { e = v; });
}
// }}}

// メモ化ラッパー (8引数まで) {{{
template<i64 N1, typename F>
class id36 {
    static_assert(N1 >= 1, "");
public:
    explicit id36(F&& f) : f_(forward<F>(f)) {}
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
class id17 {
    static_assert(N1 >= 1 && N2 >= 1, "");
public:
    explicit id17(F&& f) : f_(forward<F>(f)) {}
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
class id10 {
    static_assert(N1 >= 1 && N2 >= 1 && N3 >= 1 && N4 >= 1, "");
public:
    explicit id10(F&& f) : f_(forward<F>(f)) {}
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
class id4 {
    static_assert(N1 >= 1 && N2 >= 1 && N3 >= 1 && N4 >= 1 && N5 >= 1, "");
public:
    explicit id4(F&& f) : f_(forward<F>(f)) {}
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
class id48 {
    static_assert(N1 >= 1 && N2 >= 1 && N3 >= 1 && N4 >= 1 && N5 >= 1 && N6 >= 1, "");
public:
    explicit id48(F&& f) : f_(forward<F>(f)) {}
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
class id39 {
    static_assert(N1 >= 1 && N2 >= 1 && N3 >= 1 && N4 >= 1 && N5 >= 1 && N6 >= 1 && N7 >= 1, "");
public:
    explicit id39(F&& f) : f_(forward<F>(f)) {}
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
class id50 {
    static_assert(N1 >= 1 && N2 >= 1 && N3 >= 1 && N4 >= 1 && N5 >= 1 && N6 >= 1 && N7 >= 1 && N8 >= 1, "");
public:
    explicit id50(F&& f) : f_(forward<F>(f)) {}
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
decltype(auto) id8(F&& f) {
    return id36<N1,F>(forward<F>(f));
}
template<i64 N1, i64 N2, typename F>
decltype(auto) id8(F&& f) {
    return id17<N1,N2,F>(forward<F>(f));
}
template<i64 N1, i64 N2, i64 N3, typename F>
decltype(auto) id8(F&& f) {
    return id0<N1,N2,N3,F>(forward<F>(f));
}
template<i64 N1, i64 N2, i64 N3, i64 N4, typename F>
decltype(auto) id8(F&& f) {
    return id10<N1,N2,N3,N4,F>(forward<F>(f));
}
template<i64 N1, i64 N2, i64 N3, i64 N4, i64 N5, typename F>
decltype(auto) id8(F&& f) {
    return id4<N1,N2,N3,N4,N5,F>(forward<F>(f));
}
template<i64 N1, i64 N2, i64 N3, i64 N4, i64 N5, i64 N6, typename F>
decltype(auto) id8(F&& f) {
    return id48<N1,N2,N3,N4,N5,N6,F>(forward<F>(f));
}
template<i64 N1, i64 N2, i64 N3, i64 N4, i64 N5, i64 N6, i64 N7, typename F>
decltype(auto) id8(F&& f) {
    return id39<N1,N2,N3,N4,N5,N6,N7,F>(forward<F>(f));
}
template<i64 N1, i64 N2, i64 N3, i64 N4, i64 N5, i64 N6, i64 N7, i64 N8, typename F>
decltype(auto) id8(F&& f) {
    return id50<N1,N2,N3,N4,N5,N6,N7,N8,F>(forward<F>(f));
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
constexpr auto id43(const tuple<TS...>& t, index_sequence<i,is...>) {
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
    return id43(t, make_index_sequence<sizeof...(TS)>());
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

bool id37 (i64 x) { return x % 2 != 0; }
bool is_even(i64 x) { return x % 2 == 0; }

template<typename T> i64 cmp(T x, T y) { return (y<x) - (x<y); }
template<typename T> i64 sgn(T x) { return cmp(x, T(0)); }

// lo:OK, hi:NG
template<typename Pred>
i64 id16(i64 lo, i64 hi, Pred pred) {
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
f64 id35(f64 lo, f64 hi, Pred pred, i64 iter=100) {
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
    return id16(lo, hi, [x](i64 r) { return r*r <= x; });
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

i64 id47(i64 a, i64 b) {
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
ForwardIt id5(ForwardIt first, ForwardIt last, const T& x, Comp comp={}) {
    auto it = lower_bound(first, last, x, comp);
    if(it == last || comp(x,*it)) return last;
    return it;
}

// x 未満の最後の要素
template<typename BidiIt, typename T, typename Comp=less<>>
BidiIt id34(BidiIt first, BidiIt last, const T& x, Comp comp={}) {
    auto it = lower_bound(first, last, x, comp);
    if(it == first) return last;
    return prev(it);
}

// x 以下の最後の要素
template<typename BidiIt, typename T, typename Comp=less<>>
BidiIt id12(BidiIt first, BidiIt last, const T& x, Comp comp={}) {
    auto it = upper_bound(first, last, x, comp);
    if(it == first) return last;
    return prev(it);
}

// x より大きい最初の要素
template<typename BidiIt, typename T, typename Comp=less<>>
BidiIt id42(BidiIt first, BidiIt last, const T& x, Comp comp={}) {
    return upper_bound(first, last, x, comp);
}

// x 以上の最初の要素
template<typename BidiIt, typename T, typename Comp=less<>>
BidiIt id21(BidiIt first, BidiIt last, const T& x, Comp comp={}) {
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
auto id24(Comp comp={}) {
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
ostream& id28(ostream& out, const T& x) {
    return Formatter<T>::write_repr(out, x);
}

template<typename InputIt>
ostream& id27(ostream& out, InputIt first, InputIt last, const string& sep) {
    while(first != last) {
        WRITE_STR(out, *first++);
        if(first != last)
            out << sep;
    }
    return out;
}

template<typename InputIt>
ostream& id29(ostream& out, InputIt first, InputIt last, const string& sep) {
    while(first != last) {
        id28(out, *first++);
        if(first != last)
            out << sep;
    }
    return out;
}

template<typename InputIt>
ostream& id44(ostream& out, InputIt first, InputIt last) {
    return id27(out, first, last, " ");
}

template<typename InputIt>
ostream& id51(ostream& out, InputIt first, InputIt last) {
    out << "[";
    id29(out, first, last, ", ");
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
string id7(const T& x) {
    ostringstream out;
    id28(out, x);
    return out.str();
}

template<typename InputIt>
string id38(InputIt first, InputIt last) {
    ostringstream out;
    id44(out, first, last);
    return out.str();
}

template<typename InputIt>
string id22(InputIt first, InputIt last) {
    ostringstream out;
    id51(out, first, last);
    return out.str();
}

template<typename InputIt>
string JOIN(InputIt first, InputIt last, const string& sep) {
    ostringstream out;
    id27(out, first, last, sep);
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
        return id44(out, begin(v), end(v));
    }
    static ostream& write_repr(ostream& out, const vector<T>& v) {
        out << "vector";
        return id51(out, begin(v), end(v));
    }
};

template<>
struct Formatter<BoolArray> {
    static ostream& write_str(ostream& out, const BoolArray& a) {
        return id44(out, begin(a), end(a));
    }
    static ostream& write_repr(ostream& out, const BoolArray& a) {
        out << "BoolArray";
        return id51(out, begin(a), end(a));
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
        id28(out, p.first);
        out << ",";
        id28(out, p.second);
        out << ")";
        return out;
    }
};

template<typename... TS>
struct Formatter<tuple<TS...>> {
    template<size_t I=0, enable_if_t<I == sizeof...(TS), nullptr_t> = nullptr>
    static ostream& id20(ostream& out, const tuple<TS...>&) {
        return out;
    }
    template<size_t I=0, enable_if_t<I < sizeof...(TS), nullptr_t> = nullptr>
    static ostream& id20(ostream& out, const tuple<TS...>& t) {
        if(I != 0) out << ' ';
        WRITE_STR(out, get<I>(t));
        return id20<I+1>(out, t);
    }

    template<size_t I=0, enable_if_t<I == sizeof...(TS), nullptr_t> = nullptr>
    static ostream& id14(ostream& out, const tuple<TS...>&) {
        if(sizeof...(TS) == 0) out << "(";
        return out << ")";
    }
    template<size_t I=0, enable_if_t<I < sizeof...(TS), nullptr_t> = nullptr>
    static ostream& id14(ostream& out, const tuple<TS...>& t) {
        if(I == 0)
            out << "(";
        else
            out << ",";
        id28(out, get<I>(t));
        return id14<I+1>(out, t);
    }

    static ostream& write_str(ostream& out, const tuple<TS...>& t) {
        return id20(out, t);
    }
    static ostream& write_repr(ostream& out, const tuple<TS...>& t) {
        return id14(out, t);
    }
};

template<typename T>
void RD(T& x) {
    cin >> x;

    assert(cin);

}

template<typename T>
auto RD_ARRAY(i64 n) {
    auto res = id46<T>(n, T());
    id6(res, [](T& e) { RD(e); });
    return res;
}

template<typename T>
auto id19(i64 h, i64 w) {
    auto res = id46<T>(h,w, T());
    id6(res, [](T& e) { RD(e); });
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
auto id13() {
    return make_tuple();
}

template<typename T, typename... TS>
auto id13() {
    T x; RD(x);
    return tuple_cat(make_tuple(x), id13<TS...>());
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
    id28(cerr, value);
    cerr << "\n";

}

template<typename T, size_t N>
void id41(i64 line, const char* expr, const T (&ary)[N]) {

    cerr << "[L " << line << "]: ";
    cerr << expr << " = ";
    id51(cerr, begin(ary), end(ary));
    cerr << "\n";

}

template<typename InputIt>
void id30(i64 line, const char* expr1, const char* expr2, InputIt first, InputIt last) {

    cerr << "[L " << line << "]: ";
    cerr << expr1 << "," << expr2 << " = ";
    id51(cerr, first, last);
    cerr << "\n";

}







// }}}

// init {{{
struct id26 {
    static constexpr int IOS_PREC = 15;
    static constexpr bool AUTOFLUSH = false;

    id26() {
        cin.tie(nullptr);
        ios::sync_with_stdio(false);
        cout << fixed << setprecision(IOS_PREC);

        cerr << fixed << setprecision(IOS_PREC);

        if(AUTOFLUSH)
            cout << unitbuf;
    }
} id53;
// }}}

// container {{{

// hash {{{
template<typename T>
struct procon_hash {
    size_t operator()(const T& x) const {
        return hash<T>()(x);
    }
};

template<typename T>
size_t id11(const T& x) {
    return procon_hash<T>()(x);
}

template<typename T>
void id3(size_t& seed, const T& x) {
    seed ^= id11(x) + 0x9e3779b9 + (seed<<6) + (seed>>2);
}

template<typename InputIt>
void id45(size_t& seed, InputIt first, InputIt last) {
    for(; first != last; ++first)
        id3(seed, *first);
}

template<typename InputIt>
size_t id45(InputIt first, InputIt last) {
    size_t seed = 0;
    id45(seed, first, last);
    return seed;
}

template<typename... TS, enable_if_t<0 == sizeof...(TS), nullptr_t> = nullptr>
void id15(size_t&, const tuple<TS...>&) {}

template<typename... TS, enable_if_t<0 < sizeof...(TS), nullptr_t> = nullptr>
void id15(size_t& seed, const tuple<TS...>& t) {
    id3(seed, tuple_head(t));
    id15(seed, tuple_tail(t));
}

template<typename T>
struct procon_hash<vector<T>> {
    size_t operator()(const vector<T>& v) const {
        return ALL(id45, v);
    }
};

template<typename T1, typename T2>
struct procon_hash<pair<T1,T2>> {
    size_t operator()(const pair<T1,T2>& p) const {
        size_t seed = 0;
        id3(seed, p.first);
        id3(seed, p.second);
        return seed;
    }
};

template<typename... TS>
struct procon_hash<tuple<TS...>> {
    size_t operator()(const tuple<TS...>& t) const {
        size_t seed = 0;
        id15(seed, t);
        return seed;
    }
};

template<typename T, typename Eq=equal_to<T>>
using HashSet = unordered_set<T,procon_hash<T>,Eq>;

template<typename K, typename V, typename Eq=equal_to<K>>
using HashMap = unordered_map<K,V,procon_hash<K>,Eq>;

template<typename T, typename Eq=equal_to<T>>
using HashMultiset = unordered_multiset<T,procon_hash<T>,Eq>;

template<typename K, typename V, typename Eq=equal_to<K>>
using HashMultimap = unordered_multimap<K,V,procon_hash<K>,Eq>;
// }}}

template<typename T>
using MaxHeap = priority_queue<T, vector<T>, less<T>>;
template<typename T>
using MinHeap = priority_queue<T, vector<T>, greater<T>>;

// set/map/multiset/multimap search {{{
// set {{{
template<typename T, typename Comp>
auto id25(set<T,Comp>& s, const T& x) {
    auto it = s.lower_bound(x);
    if(it == begin(s)) return end(s);
    return prev(it);
}

template<typename T, typename Comp>
auto id25(const set<T,Comp>& s, const T& x) {
    auto it = s.lower_bound(x);
    if(it == begin(s)) return end(s);
    return prev(it);
}

template<typename T, typename Comp>
auto id23(set<T,Comp>& s, const T& x) {
    auto it = s.upper_bound(x);
    if(it == begin(s)) return end(s);
    return prev(it);
}

template<typename T, typename Comp>
auto id23(const set<T,Comp>& s, const T& x) {
    auto it = s.upper_bound(x);
    if(it == begin(s)) return end(s);
    return prev(it);
}

template<typename T, typename Comp>
auto id54(set<T,Comp>& s, const T& x) {
    return s.upper_bound(x);
}

template<typename T, typename Comp>
auto id54(const set<T,Comp>& s, const T& x) {
    return s.upper_bound(x);
}

template<typename T, typename Comp>
auto id2(set<T,Comp>& s, const T& x) {
    return s.lower_bound(x);
}

template<typename T, typename Comp>
auto id2(const set<T,Comp>& s, const T& x) {
    return s.lower_bound(x);
}
// }}}
// map {{{
template<typename K, typename V, typename Comp>
auto id9(map<K,V,Comp>& m, const K& x) {
    auto it = m.lower_bound(x);
    if(it == begin(m)) return end(m);
    return prev(it);
}

template<typename K, typename V, typename Comp>
auto id9(const map<K,V,Comp>& m, const K& x) {
    auto it = m.lower_bound(x);
    if(it == begin(m)) return end(m);
    return prev(it);
}

template<typename K, typename V, typename Comp>
auto id1(map<K,V,Comp>& m, const K& x) {
    auto it = m.upper_bound(x);
    if(it == begin(m)) return end(m);
    return prev(it);
}

template<typename K, typename V, typename Comp>
auto id1(const map<K,V,Comp>& m, const K& x) {
    auto it = m.upper_bound(x);
    if(it == begin(m)) return end(m);
    return prev(it);
}

template<typename K, typename V, typename Comp>
auto id49(map<K,V,Comp>& m, const K& x) {
    return m.upper_bound(x);
}

template<typename K, typename V, typename Comp>
auto id49(const map<K,V,Comp>& m, const K& x) {
    return m.upper_bound(x);
}

template<typename K, typename V, typename Comp>
auto id52(map<K,V,Comp>& m, const K& x) {
    return m.lower_bound(x);
}

template<typename K, typename V, typename Comp>
auto id52(const map<K,V,Comp>& m, const K& x) {
    return m.lower_bound(x);
}
// }}}
// multiset {{{
template<typename T, typename Comp>
auto id25(multiset<T,Comp>& s, const T& x) {
    auto it = s.lower_bound(x);
    if(it == begin(s)) return end(s);
    return prev(it);
}

template<typename T, typename Comp>
auto id25(const multiset<T,Comp>& s, const T& x) {
    auto it = s.lower_bound(x);
    if(it == begin(s)) return end(s);
    return prev(it);
}

template<typename T, typename Comp>
auto id23(multiset<T,Comp>& s, const T& x) {
    auto it = s.upper_bound(x);
    if(it == begin(s)) return end(s);
    return prev(it);
}

template<typename T, typename Comp>
auto id23(const multiset<T,Comp>& s, const T& x) {
    auto it = s.upper_bound(x);
    if(it == begin(s)) return end(s);
    return prev(it);
}

template<typename T, typename Comp>
auto id54(multiset<T,Comp>& s, const T& x) {
    return s.upper_bound(x);
}

template<typename T, typename Comp>
auto id54(const multiset<T,Comp>& s, const T& x) {
    return s.upper_bound(x);
}

template<typename T, typename Comp>
auto id2(multiset<T,Comp>& s, const T& x) {
    return s.lower_bound(x);
}

template<typename T, typename Comp>
auto id2(const multiset<T,Comp>& s, const T& x) {
    return s.lower_bound(x);
}
// }}}
// multimap {{{
template<typename K, typename V, typename Comp>
auto id9(multimap<K,V,Comp>& m, const K& x) {
    auto it = m.lower_bound(x);
    if(it == begin(m)) return end(m);
    return prev(it);
}

template<typename K, typename V, typename Comp>
auto id9(const multimap<K,V,Comp>& m, const K& x) {
    auto it = m.lower_bound(x);
    if(it == begin(m)) return end(m);
    return prev(it);
}

template<typename K, typename V, typename Comp>
auto id1(multimap<K,V,Comp>& m, const K& x) {
    auto it = m.upper_bound(x);
    if(it == begin(m)) return end(m);
    return prev(it);
}

template<typename K, typename V, typename Comp>
auto id1(const multimap<K,V,Comp>& m, const K& x) {
    auto it = m.upper_bound(x);
    if(it == begin(m)) return end(m);
    return prev(it);
}

template<typename K, typename V, typename Comp>
auto id49(multimap<K,V,Comp>& m, const K& x) {
    return m.upper_bound(x);
}

template<typename K, typename V, typename Comp>
auto id49(const multimap<K,V,Comp>& m, const K& x) {
    return m.upper_bound(x);
}

template<typename K, typename V, typename Comp>
auto id52(multimap<K,V,Comp>& m, const K& x) {
    return m.lower_bound(x);
}

template<typename K, typename V, typename Comp>
auto id52(const multimap<K,V,Comp>& m, const K& x) {
    return m.lower_bound(x);
}
// }}}
// }}}

template<typename T, typename Comp>
bool set_contains(const set<T,Comp>& s, const typename set<T,Comp>::key_type& x) {
    return s.find(x) != end(s);
}

template<typename T, typename Hash, typename Eq>
bool set_contains(const unordered_set<T,Hash,Eq>& s, const typename unordered_set<T,Hash,Eq>::key_type& x) {
    return s.find(x) != end(s);
}

template<typename T, typename Comp>
bool set_contains(const multiset<T,Comp>& s, const typename multiset<T,Comp>::key_type& x) {
    return s.find(x) != end(s);
}

template<typename T, typename Hash, typename Eq>
bool set_contains(const unordered_multiset<T,Hash,Eq>& s, const typename unordered_multiset<T,Hash,Eq>::key_type& x) {
    return s.find(x) != end(s);
}

template<typename K, typename V, typename Comp>
bool map_contains(const map<K,V,Comp>& m, const typename map<K,V,Comp>::key_type& k) {
    return m.find(k) != end(m);
}

template<typename K, typename V, typename Hash, typename Eq>
bool map_contains(const unordered_map<K,V,Hash,Eq>& m, const typename unordered_map<K,V,Hash,Eq>::key_type& k) {
    return m.find(k) != end(m);
}

template<typename K, typename V, typename Comp>
bool map_contains(const multimap<K,V,Comp>& m, const typename map<K,V,Comp>::key_type& k) {
    return m.find(k) != end(m);
}

template<typename K, typename V, typename Hash, typename Eq>
bool map_contains(const unordered_multimap<K,V,Hash,Eq>& m, const typename unordered_map<K,V,Hash,Eq>::key_type& k) {
    return m.find(k) != end(m);
}

template<typename K, typename Comp>
bool id31(multiset<K,Comp>& m, const typename multiset<K,Comp>::key_type& k) {
    auto it = m.find(k);
    if(it == end(m)) return false;
    m.erase(it);
    return true;
}

template<typename K, typename Hash, typename Eq>
bool id31(unordered_multiset<K,Hash,Eq>& m, const typename unordered_multiset<K,Hash,Eq>::key_type& k) {
    auto it = m.find(k);
    if(it == end(m)) return false;
    m.erase(it);
    return true;
}

// POP() 系 {{{
// 効率は悪い
template<typename T>
T POP_FRONT(vector<T>& v) {
    T x = v.front(); v.erase(begin(v));
    return x;
}

template<typename T>
T POP_BACK(vector<T>& v) {
    T x = v.back(); v.pop_back();
    return x;
}

template<typename T>
T POP_FRONT(deque<T>& v) {
    T x = v.front(); v.pop_front();
    return x;
}

template<typename T>
T POP_BACK(deque<T>& v) {
    T x = v.back(); v.pop_back();
    return x;
}

template<typename T>
T POP_FRONT(forward_list<T>& ls) {
    T x = ls.front(); ls.pop_front();
    return x;
}

template<typename T>
T POP_FRONT(list<T>& ls) {
    T x = ls.front(); ls.pop_front();
    return x;
}

template<typename T>
T POP_BACK(list<T>& ls) {
    T x = ls.back(); ls.pop_back();
    return x;
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

// bimap {{{
template<typename T1, typename T2>
struct BiHashMap {
    HashMap<T1,T2> fwd_;
    HashMap<T2,T1> rev_;

    void insert(const T1& x, const T2& y) {
        auto id32 = fwd_.find(x);
        if(id32 == end(fwd_)) {
            fwd_.insert(id32, make_pair(x,y));
            rev_.insert(end(rev_), make_pair(y,x));
        }
        else {
            assert(y == id32->second);
        }
    }

    bool contains_fwd(const T1& x) const {
        return map_contains(fwd_, x);
    }

    bool contains_rev(const T2& y) const {
        return map_contains(rev_, y);
    }

    const T2& at_fwd(const T1& x) const {
        auto it = fwd_.find(x);
        assert(it != end(fwd_));
        return it->second;
    }

    const T1& at_rev(const T2& y) const {
        auto it = rev_.find(y);
        assert(it != end(rev_));
        return it->second;
    }

    size_t size() const { return fwd_.size(); }
};
// }}}

// Formatter {{{
template<typename T, size_t N>
struct Formatter<array<T,N>> {
    static ostream& write_str(ostream& out, const array<T,N>& a) {
        return id44(out, begin(a), end(a));
    }
    static ostream& write_repr(ostream& out, const array<T,N>& a) {
        out << "array";
        return id51(out, begin(a), end(a));
    }
};

template<typename T>
struct Formatter<deque<T>> {
    static ostream& write_str(ostream& out, const deque<T>& deq) {
        return id44(out, begin(deq), end(deq));
    }
    static ostream& write_repr(ostream& out, const deque<T>& deq) {
        out << "deque";
        return id51(out, begin(deq), end(deq));
    }
};

template<typename T>
struct Formatter<forward_list<T>> {
    static ostream& write_str(ostream& out, const forward_list<T>& ls) {
        return id44(out, begin(ls), end(ls));
    }
    static ostream& write_repr(ostream& out, const forward_list<T>& ls) {
        out << "forward_list";
        return id51(out, begin(ls), end(ls));
    }
};

template<typename T>
struct Formatter<list<T>> {
    static ostream& write_str(ostream& out, const list<T>& ls) {
        return id44(out, begin(ls), end(ls));
    }
    static ostream& write_repr(ostream& out, const list<T>& ls) {
        out << "list";
        return id51(out, begin(ls), end(ls));
    }
};

template<typename T, typename Comp>
struct Formatter<set<T,Comp>> {
    static ostream& write_str(ostream& out, const set<T,Comp>& s) {
        return id44(out, begin(s), end(s));
    }
    static ostream& write_repr(ostream& out, const set<T,Comp>& s) {
        out << "set";
        return id51(out, begin(s), end(s));
    }
};

template<typename T, typename Comp>
struct Formatter<multiset<T,Comp>> {
    static ostream& write_str(ostream& out, const multiset<T,Comp>& s) {
        return id44(out, begin(s), end(s));
    }
    static ostream& write_repr(ostream& out, const multiset<T,Comp>& s) {
        out << "multiset";
        return id51(out, begin(s), end(s));
    }
};

template<typename T, typename Hash, typename Eq>
struct Formatter<unordered_set<T,Hash,Eq>> {
    static ostream& write_str(ostream& out, const unordered_set<T,Hash,Eq>& s) {
        return id44(out, begin(s), end(s));
    }
    static ostream& write_repr(ostream& out, const unordered_set<T,Hash,Eq>& s) {
        out << "unordered_set";
        return id51(out, begin(s), end(s));
    }
};

template<typename T, typename Hash, typename Eq>
struct Formatter<unordered_multiset<T,Hash,Eq>> {
    static ostream& write_str(ostream& out, const unordered_multiset<T,Hash,Eq>& s) {
        return id44(out, begin(s), end(s));
    }
    static ostream& write_repr(ostream& out, const unordered_multiset<T,Hash,Eq>& s) {
        out << "unordered_multiset";
        return id51(out, begin(s), end(s));
    }
};

template<typename K, typename V, typename Comp>
struct Formatter<map<K,V,Comp>> {
    static ostream& write_str(ostream& out, const map<K,V,Comp>& m) {
        return id44(out, begin(m), end(m));
    }
    static ostream& write_repr(ostream& out, const map<K,V,Comp>& m) {
        out << "map";
        return id51(out, begin(m), end(m));
    }
};

template<typename K, typename V, typename Comp>
struct Formatter<multimap<K,V,Comp>> {
    static ostream& write_str(ostream& out, const multimap<K,V,Comp>& m) {
        return id44(out, begin(m), end(m));
    }
    static ostream& write_repr(ostream& out, const multimap<K,V,Comp>& m) {
        out << "multimap";
        return id51(out, begin(m), end(m));
    }
};

template<typename K, typename V, typename Hash, typename Eq>
struct Formatter<unordered_map<K,V,Hash,Eq>> {
    static ostream& write_str(ostream& out, const unordered_map<K,V,Hash,Eq>& m) {
        return id44(out, begin(m), end(m));
    }
    static ostream& write_repr(ostream& out, const unordered_map<K,V,Hash,Eq>& m) {
        out << "unordered_map";
        return id51(out, begin(m), end(m));
    }
};

template<typename K, typename V, typename Hash, typename Eq>
struct Formatter<unordered_multimap<K,V,Hash,Eq>> {
    static ostream& write_str(ostream& out, const unordered_multimap<K,V,Hash,Eq>& m) {
        return id44(out, begin(m), end(m));
    }
    static ostream& write_repr(ostream& out, const unordered_multimap<K,V,Hash,Eq>& m) {
        out << "unordered_multimap";
        return id51(out, begin(m), end(m));
    }
};

template<typename T, typename C>
struct Formatter<stack<T,C>> {
    static ostream& write_str(ostream& out, const stack<T,C>& orig) {
        stack<T,C> stk(orig);
        while(!stk.empty()) {
            WRITE_STR(out, stk.top()); stk.pop();
            if(!stk.empty()) out << ' ';
        }
        return out;
    }
    static ostream& write_repr(ostream& out, const stack<T,C>& orig) {
        stack<T,C> stk(orig);
        out << "stack[";
        while(!stk.empty()) {
            id28(out, stk.top()); stk.pop();
            if(!stk.empty()) out << ", ";
        }
        out << "]";
        return out;
    }
};

template<typename T, typename C>
struct Formatter<queue<T,C>> {
    static ostream& write_str(ostream& out, const queue<T,C>& orig) {
        queue<T,C> que(orig);
        while(!que.empty()) {
            WRITE_STR(out, que.front()); que.pop();
            if(!que.empty()) out << ' ';
        }
        return out;
    }
    static ostream& write_repr(ostream& out, const queue<T,C>& orig) {
        queue<T,C> que(orig);
        out << "queue[";
        while(!que.empty()) {
            id28(out, que.front()); que.pop();
            if(!que.empty()) out << ", ";
        }
        out << "]";
        return out;
    }
};

template<typename T, typename C, typename Comp>
struct Formatter<priority_queue<T,C,Comp>> {
    static ostream& write_str(ostream& out, const priority_queue<T,C,Comp>& orig) {
        priority_queue<T,C,Comp> que(orig);
        while(!que.empty()) {
            WRITE_STR(out, que.top()); que.pop();
            if(!que.empty()) out << ' ';
        }
        return out;
    }
    static ostream& write_repr(ostream& out, const priority_queue<T,C,Comp>& orig) {
        priority_queue<T,C,Comp> que(orig);
        out << "priority_queue[";
        while(!que.empty()) {
            id28(out, que.top()); que.pop();
            if(!que.empty()) out << ", ";
        }
        out << "]";
        return out;
    }
};
// }}}

// }}}

// rolling_hash {{{

struct RollingHash {
    static constexpr pair<i64,i64> BMS_DEF[] {
        {  9973,   999'999'937 },
        { 10007, 1'000'000'007 },
    };

    vector<pair<i64,i64>> bms_;
    vector<vector<i64>> hs_;
    vector<vector<i64>> bpows_;

    template<typename ForwardIt>
    RollingHash(ForwardIt first, ForwardIt last) : RollingHash(first,last,{begin(BMS_DEF),end(BMS_DEF)}) {}

    template<typename ForwardIt>
    RollingHash(ForwardIt first, ForwardIt last, const vector<pair<i64,i64>>& bms)
        : bms_(bms),
          hs_(SIZE(bms),vector<i64>(distance(first,last)+1,0)),
          bpows_(SIZE(bms),vector<i64>(distance(first,last)+1,1))
    {
        REP(i, SIZE(bms_)) {
            i64 b,m; tie(b,m) = bms_[i];
            auto& h    = hs_[i];
            auto& bpow = bpows_[i];
            auto it = first;
            REP(j, distance(first,last)) {
                auto e = *it++;
                h[j+1]    = modulo(e + h[j]*b, m);
                bpow[j+1] = modulo(bpow[j]*b, m);
            }
        }
    }

    vector<i64> get(i64 j, i64 n) const {
        vector<i64> res(SIZE(bms_));
        REP(i, SIZE(bms_)) {
            i64 m; tie(ignore,m) = bms_[i];
            const auto& h    = hs_[i];
            const auto& bpow = bpows_[i];
            res[i] = modulo(h[j+n] - h[j]*bpow[n], m);
        }
        return res;
    }
};
constexpr pair<i64,i64> RollingHash::BMS_DEF[];









void solve() {
    i64 N; RD(N);
    auto SS = RD_ARRAY<string>(N);

    vector<RollingHash> hs;
    hs.reserve(N);
    HashMap<vector<i64>,i64> cnts;
    for(const auto& s : SS) {
        RollingHash h(begin(s), end(s));
        hs.emplace_back(h);
        FOR(len, 1, 10) REP(i, 9-len+1) {
            ++cnts[h.get(i,len)];
        }
    }

    REP(i, N) {
        const auto& s = SS[i];
        const auto& h = hs[i];

        FOR(len, 1, 10) REP(j, 9-len+1) {
            --cnts[h.get(j,len)];
        }

        FOR(len, 1, 10) REP(j, 9-len+1) {
            if(cnts[h.get(j,len)] == 0) {
                string ans = s.substr(j,len);
                PRINTLN(ans);
                goto found;
            }
        }
found: ;

        FOR(len, 1, 10) REP(j, 9-len+1) {
            ++cnts[h.get(j,len)];
        }
    }
}

signed main() {
    

    solve();

    EXIT();
}
