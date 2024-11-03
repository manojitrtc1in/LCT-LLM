







using namespace std;

struct initon {
    initon() {
        cin.tie(0);
        ios::sync_with_stdio(false);
        cout.setf(ios::fixed);
        cout.precision(16);
        srand((unsigned) clock() + (unsigned) time(NULL));
    };
} id0;







template<typename T, typename U = typename T::value_type> std::true_type id12(signed);

template<typename T> std::false_type id12(long);
template<typename T> struct has_value_type : decltype(id12<T>(0)) {};
template<class T> inline constexpr bool id1 = has_value_type<T>::value;

template<class T> struct is_vector : std::false_type {};
template<class T> struct is_vector<std::vector<T>> : std::true_type {};
template<class T> inline constexpr bool id8 = is_vector<T>::value;

template<class T1, class T2, bool id2 = (sizeof(T1) > sizeof(T2))> struct max_type { typedef T1 type; };
template<class T1, class T2> struct max_type<T1, T2, false> { typedef T2 type; };



template<class T> using value_type_t = typename T::value_type;


template<class T, bool end = !has_value_type<T>::value> struct value_type_rec { typedef T type; };
template<class T> struct value_type_rec<T, false> { typedef typename value_type_rec<value_type_t<T>>::type type; };
template<class T> using value_type_rec_t = typename value_type_rec<T>::type;



template<class T, bool end = is_same<T, remove_extent_t<T>>::value> struct remove_extent_rec { typedef T type; };
template<class T> struct remove_extent_rec<T, false> { typedef typename remove_extent_rec<remove_extent_t<T>>::type type; };
template<class T> using remove_extent_rec_t = typename remove_extent_rec<T>::type;








template<class T>using V = vector<T>;
using P = pair<int, int >;
using vb = vector<bool>;
using vc = vector<char>;
using vi = vector<int>;
using vp = vector<P>;
using vs = vector<string>;





const double PI = 3.1415926535897932384626433832795029L;
const double eps = 1e-9;
using str = string;
using P = pair<ll, ll>;
using T = tuple<ll, ll, ll>;
using F = tuple<ll, ll, ll, ll>;























































constexpr ll inf = (ll) 1e9 + 100;
constexpr ll linf = (ll) 1e18 + 100;
constexpr double dinf = (double) linf * linf;

template<typename T> class fixed_point: T {public:explicit constexpr fixed_point(T &&t) noexcept: T(std::forward<T>(t)) {}template<typename... Args> constexpr decltype(auto) operator()(Args &&... args) const { return T::operator()(*this, std::forward<Args>(args)...); }};
template<typename T> static inline constexpr decltype(auto) fix(T &&t) noexcept { return fixed_point<T>{std::forward<T>(t)}; }


void id17(int &a, int &b, int n) {        if (b == -1) {
        if (a == -1) {
            a = 0;
            b = n;
        } else {
            b = a;
            a = 0;
        }
    }
}

template<class T, class U> bool chma(T &a, const U &b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}
template<class T, class U> bool chmi(T &a, const U &b) {
    if (b < a) {
        a = b;
        return true;
    }
    return false;
}
template<class T> T MAX() { return numeric_limits<T>::max(); }
template<class T> T MIN() { return numeric_limits<T>::min(); }

template<typename W, typename T> void fill(vector<W> &a, const T &v, int l = -1, ll r = -1) {id17(l, r, a.size());if constexpr(!is_vector<W>::value) { rep(i, l, r)a[i] = v; } else { rep(i, l, r)fill(a[i], v); }}
template<class Iterable, require_t(id1<Iterable>)> value_type_rec_t<Iterable> sum(const Iterable &a, int l = -1, int r = -1) {value_type_rec_t<Iterable> ret = 0;        if constexpr(id8<Iterable>) { id17(l, r, sz(a));                if constexpr(!id1<value_type_t<Iterable>>) { rep(i, l, r) ret += a[i]; } else { rep(i, l, r) ret += sum(a[i]); }} else {                if constexpr(!id1<value_type_t<Iterable>>) { for (auto &v : a) { ret += v; }} else { for (auto &v : a) { ret += sum(v); }}}return ret;}
template<class Iterable, require_t(id1<Iterable>)> value_type_rec_t<Iterable> min(const Iterable &a, int l = -1, int r = -1) {value_type_rec_t<Iterable> ret = MAX<value_type_rec_t<Iterable>>();        if constexpr(id8<Iterable>) { id17(l, r, sz(a));                if constexpr(!id1<value_type_t<Iterable>>) { rep(i, l, r) ret = min(ret, a[i]); } else { rep(i, l, r) ret = min(ret, min(a[i])); }} else {                if constexpr(!id1<value_type_t<Iterable>>) { for (auto &v : a) { ret = min(ret, v); }} else { for (auto &v : a) { ret = min(ret, min(v)); }}}return ret;}
template<class Iterable, require_t(id1<Iterable>)> value_type_rec_t<Iterable> max(const Iterable &a, int l = -1, int r = -1) {value_type_rec_t<Iterable> ret = MIN<value_type_rec_t<Iterable>>();        if constexpr(id8<Iterable>) {        id17(l, r, sz(a));                if constexpr(!id1<value_type_t<Iterable>>){            rep(i, l, r) ret = max(ret, a[i]);        }else{            rep(i, l, r) ret = max(ret, max(a[i]));        }    }    else {                if constexpr(!id1<value_type_t<Iterable>>){            for (auto &v : a) { ret = max(ret, v); }        }else{            for (auto &v : a) { ret = max(ret, max(v)); }        }    }    return ret;}

template<class Array, class T, size_t N> void fill(Array(&a)[N] , const T& v, int l = -1, int r = -1) {    id17(l, r, N);    if constexpr(is_same_v<Array, remove_extent_t<Array>>){        rep(i, l, r) a[i] = v;    }else{        rep(i, l, r) fill(a[i], v);    }}
template<class Array, size_t N> remove_extent_rec_t<Array> sum(const Array(&a)[N] , int l = -1, int r = -1) {    remove_extent_rec_t<Array> ret = 0;    id17(l, r, N);    if constexpr(is_same_v<Array, remove_extent_t<Array>>){        rep(i, l, r) ret += a[i];    }else{        rep(i, l, r) ret += sum(a[i]);    }    return ret;}
template<class Array, size_t N> remove_extent_rec_t<Array> min(const Array(&a)[N] , int l = -1, int r = -1) {    remove_extent_rec_t<Array> ret = MAX<remove_extent_rec_t<Array>>();    id17(l, r, N);    if constexpr(is_same_v<Array, remove_extent_t<Array>>){        rep(i, l, r) ret = std::min(ret, a[i]);    }else{        rep(i, l, r) ret = std::min(ret, min(a[i]));    }    return ret;}
template<class Array, size_t N> remove_extent_rec_t<Array> max(const Array(&a)[N] , int l = -1, int r = -1) {    remove_extent_rec_t<Array> ret = MIN<remove_extent_rec_t<Array>>();    id17(l, r, N);    if constexpr(is_same_v<Array, remove_extent_t<Array>>){        rep(i, l, r) ret = std::max(ret, a[i]);    }else{        rep(i, l, r) ret = std::max(ret, max(a[i]));    }    return ret;}




template<class H, class... T> auto zip_ref(vector<H> &head, vector<T> &...tails) {vector<tuple<H &, T &...>> res;rep(i, sz(head)) { res.emplace_back(head[i], tails[i]...); }return res;}


template<class H, class... T> auto zip(vector<H> &head, vector<T> &...tails) {vector<tuple<H, T...>> res;rep(i, sz(head)) { res.emplace_back(head[i], tails[i]...); }return res;}


template<class H, class... T> auto id14(vector<H> &head, vector<T> &...tails) {    vector<tuple<int, H &, T &...>> res;    rep(i, sz(head)) { res.emplace_back(i, head[i], tails[i]...); }    return res;}
template<class Tup_l, class Tup_r, size_t ... Indicies> auto id6(Tup_l &res, const Tup_r &rhs, index_sequence<Indicies...>) {(..., get<Indicies>(res).emplace_back(get<Indicies>(rhs)));}


template<class... T> tuple<vector<T>...> unzip(const vector<tuple<T&...>> &elems) {tuple<vector<T>...> res;for (auto &&elem : elems) { id6(res, elem, index_sequence_for<T...>{}); }return res;}





















template<class Iterable, class is_Iterable = value_type_t<Iterable>> void sort(Iterable &a) { sort(a.begin(), a.end()); }
template<class Iterable, class is_Iterable = value_type_t<Iterable>> void rsort(Iterable &a) { sort(a.rbegin(), a.rend()); }









template<class H, class... T> auto zip_ref(vector<H> &head, vector<T> &...tails) {
    vector<tuple<H &, T &...>> res;
    rep(i, sz(head)) { res.emplace_back(head[i], tails[i]...); }
    return res;
}


template<class H, class... T> auto zip(vector<H> &head, vector<T> &...tails) {
    vector<tuple<H, T...>> res;
    rep(i, sz(head)) { res.emplace_back(head[i], tails[i]...); }
    return res;
}
template<class H, class T> auto zip_pair(vector<H> &head, vector<T> &tail) {
    vector<pair<H, T>> res;
    rep(i, sz(head)) { res.emplace_back(head[i], tail[i]); }
    return res;
}


template<class H, class... T> auto id14(vector<H> &head, vector<T> &...tails) {
    vector<tuple<int, H &, T &...>> res;
    rep(i, sz(head)) { res.emplace_back(i, head[i], tails[i]...); }
    return res;
}
template<class H, class... T> auto indexed_zip(vector<H> &head, vector<T> &...tails) {
    vector<tuple<int, H, T...>> res;
    rep(i, sz(head)) { res.emplace_back(i, head[i], tails[i]...); }
    return res;
}
template<class Tup_l, class Tup_r, size_t ... Indicies> auto id6(Tup_l &res, const Tup_r &rhs, index_sequence<Indicies...>) { (..., get<Indicies>(res).emplace_back(get<Indicies>(rhs))); }


template<class... T> tuple<vector<T>...> unzip(const vector<tuple<T &...>> &elems) {
    tuple<vector<T>...> res;
    for (auto &&elem : elems) { id6(res, elem, index_sequence_for<T...>{}); }
    return res;
}
template<class... T> tuple<vector<T>...> unzip(const vector<tuple<T...>> &elems) {
    tuple<vector<T>...> res;
    for (auto &&elem : elems) { id6(res, elem, index_sequence_for<T...>{}); }
    return res;
}




template<class T> T sorted(const T &A) {
    T ret = A;
    sort(ret);
    return ret;
}
template<class T> T rsorted(const T &A) {
    T ret = A;
    rsort(ret);
    return ret;
}



enum tuple_comparator {       fisi = 0,
    fisd,
    fdsi,
    fdsd,
    sifi,
    sifd,
    sdfi,
    sdfd,
    fisiti,
    fisitd,
    fisdti,
    fisdtd,
    fdsiti,
    fdsitd,
    fdsdti,
    fdsdtd,
    fitisi,
    fitisd,
    fitdsi,
    fitdsd,
    fdtisi,
    fdtisd,
    fdtdsi,
    fdtdsd,
    sifiti,
    sifitd,
    sifdti,
    sifdtd,
    sdfiti,
    sdfitd,
    sdfdti,
    sdfdtd,
    sitifi,
    sitifd,
    sitdfi,
    sitdfd,
    sdtifi,
    sdtifd,
    sdtdfi,
    sdfdfd,
    tifisi,
    tifisd,
    tifdsi,
    tifdsd,
    tdfisi,
    tdfisd,
    tdfdsi,
    tdfdsd,
    tisifi,
    tisifd,
    tisdfi,
    tisdfd,
    tdsifi,
    tdsifd,
    tdsdfi,
    tdsdfd
};







template<class... T, class U=tuple<T...>> function<bool(U, U)> id9(const vector<tuple<T...>> &a, tuple_comparator Compare) {
    if constexpr(sizeof...(T) >= 2) {
        int type = Compare;
        if (type == 0) return set_4(0, 1, <, <);
        if (type == 1) return set_4(0, 1, <,>);
        if (type == 2) return set_4(0, 1, >, <);
        if (type == 3) return set_4(0, 1, >, >);
        if (type == 4) return set_4(1, 0, <, <);
        if (type == 5) return set_4(1, 0, <,>);
        if (type == 6) return set_4(1, 0, >, <);
        if (type == 7) return set_4(1, 0, >, >);
    }
    if constexpr(sizeof...(T) >= 3) {
        int type = Compare - 8;
        if (type == 0) return set_6(0, 1, 2, <, <, <);
        else if (type == 1) return set_6(0, 1, 2, <, <,>);
        else if (type == 2) return set_6(0, 1, 2, <,>, <);
        else if (type == 3) return set_6(0, 1, 2, <,>, >);
        else if (type == 4) return set_6(0, 1, 2, >, <, <);
        else if (type == 5) return set_6(0, 1, 2, >, <,>);
        else if (type == 6) return set_6(0, 1, 2, >, >, <);
        else if (type == 7) return set_6(0, 1, 2, >, >, >);
        else if (type == 8) return set_6(0, 2, 1, <, <, <);
        else if (type == 9) return set_6(0, 2, 1, <, <,>);
        else if (type == 10) return set_6(0, 2, 1, <,>, <);
        else if (type == 11) return set_6(0, 2, 1, <,>, >);
        else if (type == 12) return set_6(0, 2, 1, >, <, <);
        else if (type == 13) return set_6(0, 2, 1, >, <,>);
        else if (type == 14) return set_6(0, 2, 1, >, >, <);
        else if (type == 15) return set_6(0, 2, 1, >, >, >);
        else if (type == 16) return set_6(1, 0, 2, <, <, <);
        else if (type == 17) return set_6(1, 0, 2, <, <,>);
        else if (type == 18) return set_6(1, 0, 2, <,>, <);
        else if (type == 19) return set_6(1, 0, 2, <,>, >);
        else if (type == 20) return set_6(1, 0, 2, >, <, <);
        else if (type == 21) return set_6(1, 0, 2, >, <,>);
        else if (type == 22) return set_6(1, 0, 2, >, >, <);
        else if (type == 23) return set_6(1, 0, 2, >, >, >);
        else if (type == 24) return set_6(1, 2, 0, <, <, <);
        else if (type == 25) return set_6(1, 2, 0, <, <,>);
        else if (type == 26) return set_6(1, 2, 0, <,>, <);
        else if (type == 27) return set_6(1, 2, 0, <,>, >);
        else if (type == 28) return set_6(1, 2, 0, >, <, <);
        else if (type == 29) return set_6(1, 2, 0, >, <,>); else if (type == 30) return set_6(1, 2, 0, >, >, <); else if (type == 31) return set_6(1, 2, 0, >, >, >); else if (type == 32) return set_6(2, 0, 1, <, <, <); else if (type == 33) return set_6(2, 0, 1, <, <,>); else if (type == 34) return set_6(2, 0, 1, <,>, <); else if (type == 35) return set_6(2, 0, 1, <,>, >); else if (type == 36) return set_6(2, 0, 1, >, <, <); else if (type == 37) return set_6(2, 0, 1, >, <,>); else if (type == 38) return set_6(2, 0, 1, >, >, <); else if (type == 39) return set_6(2, 0, 1, >, >, >); else if (type == 40) return set_6(2, 1, 0, <, <, <); else if (type == 41) return set_6(2, 1, 0, <, <,>); else if (type == 42) return set_6(2, 1, 0, <,>, <); else if (type == 43) return set_6(2, 1, 0, <,>, >); else if (type == 44) return set_6(2, 1, 0, >, <, <); else if (type == 45) return set_6(2, 1, 0, >, <,>); else if (type == 46) return set_6(2, 1, 0, >, >, <); else if (type == 47) return set_6(2, 1, 0, >, >, >);
    }
    return [&](U l, U r) { return true; };
}
template<class A, class B, class U=pair<A, B>> function<bool(U, U)> id9(const vector<pair<A, B>> &a, tuple_comparator Compare) {
    int type = Compare;
    if (type == 0) return set_4(0, 1, <, <);
    if (type == 1) return set_4(0, 1, <,>);
    if (type == 2) return set_4(0, 1, >, <);
    if (type == 3) return set_4(0, 1, >, >);
    if (type == 4) return set_4(1, 0, <, <);
    if (type == 5) return set_4(1, 0, <,>);
    if (type == 6) return set_4(1, 0, >, <);
    if (type == 7) return set_4(1, 0, >, >);
    else {
        cerr << "error id9 pair<> sort" << endl;
        return [&](U l, U r) { return true; };
    }
}
template<tuple_comparator Compare = fisi, class... T> void sort(vector<tuple<T...>> &a) {
    auto f = id9(a, Compare);
    std::sort(a.begin(), a.end(), f);
}
template<tuple_comparator Compare = fisi, class... T> void sort(vector<pair<T...>> &a) {
    auto f = id9(a, Compare);
    std::sort(a.begin(), a.end(), f);
}



template<tuple_comparator Compare = fisi, class H, class... Ts> void sortt(vector<H> &head, vector<Ts> &...tails) {
    vector<tuple<H, Ts...>> zipped = zip(head, tails...);
    sort<Compare>(zipped);
    tie(head, tails...) = unzip(zipped);
}


template<class H, class... Ts> void id4(vector<H> &head, vector<Ts> &...tails) {
    vector<tuple<H, Ts...>> zipped = zip(head, tails...);
    rsort(zipped);tie(head, tails...) = unzip(zipped);
}


template<class F, class H, class... Ts> void id7(F func, H &head, Ts &...tails) {
    auto zipped = zip(head, tails...);
    std::sort(zipped.begin(), zipped.end(), [&](auto &a, auto &b) { return func(a, b); });
    tie(head, tails...) = unzip(zipped);
}



template<class F, class H, class... Ts> void sorttf(F func, H &head, Ts &...tails) { id7([&](auto &a, auto &b) { return func(a) < func(b); }, head, tails...); }
template<class F, class H, class... Ts> void id15(F func, H &head, Ts &...tails) { id7([&](auto &a, auto &b) { return func(a) > func(b); }, head, tails...); }



template<class T> vi sorti(const vector<T> &a) {
    auto b = a;
    vi ind(sz(b));
    iota(ind.begin(), ind.end(), 0);
    sortt(b, ind);
    return ind;
}
template<class T> vi rsorti(const vector<T> &a) {
    auto b = a;
    vi ind(sz(b));
    iota(ind.begin(), ind.end(), 0);
    id4(b, ind);
    return ind;
}


template<tuple_comparator Compare = fisi, class H, class... Ts> vi sortti(vector<H> head, vector<Ts>... tails) {
    vi ind(sz(head));
    iota(ind.begin(), ind.end(), 0);
    sortt<Compare>(head, tails..., ind);
    return ind;
}
template<class H, class... Ts> vi id18(vector<H> head, vector<Ts>... tails) {
    vi ind(sz(head));
    iota(ind.begin(), ind.end(), 0);
    id4(head, tails..., ind);
    return ind;
}
















template<class Iterable, class U, class W> value_type_t<Iterable> lowerBound(Iterable &a, U v, W banpei) {
    decltype(a.begin()) it;
    if constexpr (is_vector<Iterable>::value) { it = lower_bound(a.begin(), a.end(), v); } else { it = a.lower_bound(v); }
    if (it == a.end())return banpei; else return *it;
}
template<class Iterable, class U, class W> value_type_t<Iterable> upperBound(Iterable &a, U v, W banpei) {
    decltype(a.begin()) it;
    if constexpr (is_vector<Iterable>::value) { it = upper_bound(a.begin(), a.end(), v); } else { it = a.upper_bound(v); }
    if (it == a.end())return banpei; else return *it;
}
template<class Iterable, class U, class W> value_type_t<Iterable> id19(Iterable &a, U v, W banpei) {
    decltype(a.begin()) it;
    if constexpr (is_vector<Iterable>::value) { it = upper_bound(a.begin(), a.end(), v); } else { it = a.upper_bound(v); }
    if (it == a.begin())return banpei; else { return *(--it); }
}
template<class Iterable, class U, class W> value_type_t<Iterable> id3(Iterable &a, U v, W banpei) {
    decltype(a.begin()) it;
    if constexpr (is_vector<Iterable>::value) { it = lower_bound(a.begin(), a.end(), v); } else { it = a.lower_bound(v); }
    if (it == a.begin())return banpei; else { return *(--it); }
}








ll mod(ll a, ll m) {
    if (m < 0) m *= -1;
    if (a >= 0) {
        if (a < m) return a;
        return a % m;
    } else {
        if (a >= -m) return a + m;
        return a % m + m;
    }
}
ll ceil(ll a, ll b) {
    if (b == 0) {
        cerr << "ceil" << endl;
        deb(a, b);
        return -1;
    } else if (a < 0) { return 0; } else { return (a + b - 1) / b; }
}

template<class T, class U, class V = typename max_type<T, U>::type>
V gcd(T a_, U b_) {
    V a = a_;
    V b = b_;
    while (b) a %= b, swap(a, b);
    return abs(a);
}

template<class T, class U, class V = typename max_type<T, U>::type>
V lcm(T a, U b) { return a / gcd(a, b) * b; }

template<class T> T gcd(const vector<T> &b) {
    T res = b[0];
    rep(i, 1, sz(b))res = gcd(b[i], res);
    return res;
}
template<class T> T lcm(const vector<T> &a) {
    T res = a[0];
    rep(i, 1, sz(a))res = lcm(a[i], res);
    return res;
}





template<class R, class T> R id20(T t) { R lt = t;        if constexpr (is_integral_v<R>) { return lt <= 0 ? 0 : ((1 + lt) * lt) >> 1; } else { return ((1 + lt) * lt) / 2; }}
template<class R, class T, class U> R id20(T s, U t) { if (s <= 0) { return id20<R>(t - s) + s * (t - s + 1); } else { return id20<R>(t) - id20<R>(s - 1); }}
template<class R, class T> R id13(T t) { return id20(t - 1); }
template<class R, class T, class U> R id13(T s, U t) { return id20(s, t - 1); }


template<class T = int, class A, class B = int> T my_pow(A a, B b = 2) {
    if (b < 0)return (T) 1 / my_pow<T>(a, -b);

    if constexpr(is_floating_point<T>::value) { return pow((T) a, (T) b); }
    else if constexpr(is_floating_point<A>::value) {

        assert2(0, "pow <not dou>(dou, )");

    } else if constexpr(is_floating_point<B>::value) {

        assert2(0, "pow <not dou>(, dou)");

    } else {

        T ret = 1;
        T bek = a;
        while (b) {
            if (b & 1)ret *= bek;
            bek *= bek;
            b >>= 1;
        }
        return ret;

    }

}
template<typename W, typename H> void resize(W &vec_, const H head) { vec_.resize(head); }
template<typename W, typename H, typename ... T> void resize(W &vec_, const H &head, const T ... tail) {
    vec_.resize(head);
    for (auto &v: vec_)resize(v, tail...);
} 




template<class T=int> T in() {
    T ret;
    cin >> ret;
    return ret;
}
template<class T> void in(T &head) { cin >> head; }
template<class T, class... U> void in(T &head, U &... tail) {
    cin >> head;
    in(tail...);
}
template<class T> void na(vector<T> &A, int N) {
    A.resize(N);
    rep(i, N) { cin >> A[i]; }
}
template<class T> void nad(vector<T> &A, ll N) {
    na(A, N);
    rep(i, N)A[i]--;
}
template<class T, class U> void na2(vector<T> &a, vector<U> &b, ll n) {
    a.resize(n);
    b.resize(n);
    rep(i, n)cin >> a[i] >> b[i];
}
template<class T, class U> void id10(vector<T> &a, vector<U> &b, ll n) {
    na2(a, b, n);
    rep(i, n)a[i]--, b[i]--;
}
template<class T, class U, class W> void na3(vector<T> &a, vector<U> &b, vector<W> &c, ll n) {
    a.resize(n);
    b.resize(n);
    c.resize(n);
    rep(i, n)cin >> a[i] >> b[i] >> c[i];
}
template<class T, class U, class W> void id5(vector<T> &a, vector<U> &b, vector<W> &c, ll n) {
    na3(a, b, c, n);
    rep(i, n)a[i]--, b[i]--, c[i]--;
}






























template<class Tuple, size_t... Indicies> void id11(istream &iss, Tuple &tup, index_sequence<Indicies...>) { (..., [&](auto &v) { iss >> v; }(get<Indicies>(tup))); }
template<class... T> istream &operator>>(istream &iss, tuple<T...> &tup) {
    id11(iss, tup, index_sequence_for<T...>{});
    return iss;
}
template<class Tuple, size_t... Indicies> void id16(ostream &os, const Tuple &tup, index_sequence<Indicies...>, const string &sep) {
    stringstream ss;
    (..., [&](auto a) { ss << sep << a; }(get<Indicies>(tup)));
    os << ss.str().substr((int) sep.size());
}
template<class... T> ostream &operator<<(ostream &os, const tuple<T...> &tup) {
    id16(os, tup, index_sequence_for<T...>{}, " ");
    return os;
}



template<typename T> ostream &operator<<(ostream &os, const vector<vector<T>> &vec_) {
    for (ll i = 0; i < vec_.size(); ++i) {
        for (ll j = 0; j < vec_[i].size(); ++j) { os << vec_[i][j] << " "; }
        os << endl;
    }
    return os;
}
template<typename T> ostream &operator<<(ostream &os, const vector<T> &vec_) {
    for (ll i = 0; i < vec_.size(); ++i)os << vec_[i] << (i + 1 == vec_.size() ? "" : " ");
    return os;
}





ostream &operator<<(ostream &os, const vector<vector<char>> &vec_) {
    rep(h, sz(vec_)) {
        rep(w, sz(vec_[0])) { os << vec_[h][w]; }
        if (h < sz(vec_) - 1)os << endl;
    }
    return os;
}


template<class T> void out(T head) {
    cout << head << endl;
    res_mes += deb_tos(head);
    res_mes += "\n";
}
template<class T, class... U> void out(T head, U ... tail) {
    cout << head << " ";
    res_mes += deb_tos(head) + " ";
    out(tail...);
}
void out() { cout << "" << endl; }

template<class T> void out(T head) {cout << head << endl;}
        template<class T, class... U> void out(T head, U ... tail) {cout << head << " ";out(tail...);}
        void out() { cout << "" << endl; }



template<class H, class ...T> void outl(vector<H> &head, vector<T> &...tails) {
    rep(i, sz(head)) {
        cout << head[i];
        auto f = [&](auto &v) { cout << " " << v; };
        (..., f(tails[i]));
        cout << endl;
    }
}
template<class... T> void fin(T... s) {
    out(s...);
    exit(0);
}





ll u0(ll a) { return a < 0 ? 0 : a; }
string sub(const string &A, int l = -1, int r = -1) {
    id17(l, r, sz(A));
    assert(0 <= l && l <= r && r <= sz(A));
    return A.substr(l, r - l);
}
template<class T> vector<T> sub(const vector<T> &A, int l = -1, int r = -1) {
    id17(l, r, sz(A));
    assert(0 <= l && l <= r && r <= sz(A));
    vector<T> ret(r - l);
    std::copy(A.begin() + l, A.begin() + r, ret.begin());
    return ret;
} 

constexpr ll bit(ll n) {

    assert(n <= 62);


    return (1LL << (n));
}

constexpr bool bget(ll m, ll keta) {

    assert(keta <= 62);


    return (m >> keta) & 1;
}
ll mask(ll n) { return (1ll << n) - 1; }








vb::reference operator|=(vb::reference a, bool b) { return a = a | b; }
vb::reference operator&=(vb::reference a, bool b) { return a = a & b; }
template<class T, class U> vector<T> &operator+=(vector<T> &a, const U &v) {
    a.emplace_back(v);
    return a;
}
template<class T> vector<T> &operator+=(vector<T> &a, const vector<T> &b) {
    rep(i, sz(b)) { a.emplace_back(b[i]); }
    return a;
}
template<class T, class U> void operator+=(queue<T> &a, const U &v) { a.push(v); }
template<class T, class U> priority_queue<T, vector<T>, greater<T>> &operator+=(priority_queue<T, vector<T>, greater<T>> &a, const U &v) {
    a.push(v);
    return a;
}
template<class T, class U> priority_queue<T> &operator+=(priority_queue<T> &a, const U &v) {
    a.push(v);
    return a;
}
template<class T, class U> auto operator+=(set<T> &a, const U &v) { return a.insert(v); }
template<class T, class U> auto operator-=(set<T> &a, const U &v) { return a.erase(v); }
template<class T, class U> auto operator+=(mset<T> &a, const U &v) { return a.insert(v); }
template<class T, class U> set<T, greater<T>> &operator+=(set<T, greater<T>> &a, const U &v) {
    a.insert(v);
    return a;
}
template<class T> vector<T> operator+(const vector<T> &a, const vector<T> &b) {
    vector<T> ret;
    ret = a;
    fora(v, b) { ret += v; }
    return ret;
}

template<class T, class U> pair<T, U> operator+=(pair<T, U> &a, const pair<T, U> &b) {
    a.fi += b.fi;
    a.se += b.se;
    return a;
}
template<class T, class U> pair<T, U> operator+(const pair<T, U> &a, const pair<T, U> &b) {
    pair<T, U> c = a;
    c += b;
    return c;
}

template<class T, class U> pair<T, U> operator-=(pair<T, U> &a, const pair<T, U> &b) {
    a.fi -= b.fi;
    a.se -= b.se;
    return a;
}
template<class T, class U> pair<T, U> operator-(const pair<T, U> &a, const pair<T, U> &b) {
    pair<T, U> c = a;
    c -= b;
    return c;
}

template<class T, class U, class V> pair<T, U> operator*=(pair<T, U> &a, const V &b) {
    a.fi *= b;
    a.se *= b;
    return a;
}
template<class T, class U, class V> pair<T, U> operator*(const pair<T, U> &a, const V &b) {
    pair<T, U> c = a;
    c *= b;
    return c;
}

template<class T, class U, class V> pair<T, U> operator/=(pair<T, U> &a, const V &b) {
    a.fi /= b;
    a.se /= b;
    return a;
}
template<class T, class U, class V> pair<T, U> operator/(const pair<T, U> &a, const V &b) {
    pair<T, U> c = a;
    c /= b;
    return c;
}

template<class T, class U> pair<T, U> operator-(const pair<T, U> &a) { return pair<T, U>(-a.first, -a.second); }


int yn_v = 0;
void yn(bool a) {
    assert_yn(yn_v, 1);
    if (a)cout << "yes" << endl; else cout << "no" << endl;
}
void fyn(bool a) {
    assert_yn(yn_v, 1);
    yn(a);
    exit(0);
}

void Yn(bool a) {
    assert_yn(yn_v, 2);
    if (a)cout << "Yes" << endl; else cout << "No" << endl;
}
void fYn(bool a) {
    assert_yn(yn_v, 2);
    Yn(a);
    exit(0);
}

void YN(bool a) {
    assert_yn(yn_v, 3);
    if (a)cout << "YES" << endl; else cout << "NO" << endl;
}
void fYN(bool a) {
    assert_yn(yn_v, 3);
    YN(a);
    exit(0);
}













vvc (ba);
ll N, M, H, W;
vi A, B, C;

void solve() {
    int Q;
    cin >> Q;
    while (Q--) {
        in(N);
        dna3(A, B, M, N);
        vp S;
        unordered_map<int, V<T>> segs;
        fora(i, a, b, m, A, B, M) {
            

            int la = a - min(a, m);
            int ra = a - (m - min(b, m));
            segs[a + b - m] += mt(ra, la, i);
        }
        int types = 0;
        for (auto it = segs.begin(); it != segs.end(); it++) {
            sort(it->se);
            int pl = -1;
            for (auto&[r, l, i] : it->se) {
                

                auto set = [&](int i, int a) {
                    int dec = A[i] - a;
                    A[i] = dec;
                    B[i] = (M[i] - dec);
                };
                if (pl < l) {
                    pl = r;
                    types++;
                }
                set(i, pl);
            }
        }
        out(types);
        fora(a, b, A, B){
            out(a,b);
        }
    }
}

signed main() {
    solve();

    return 0;
}