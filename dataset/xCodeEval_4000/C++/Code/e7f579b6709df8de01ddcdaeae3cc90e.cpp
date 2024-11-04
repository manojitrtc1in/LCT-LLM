#ifdef _DEBUG
#include "C:/Kyopro/kyopro_library/bits_stdc++.h"
#include "my_debug_cf.h"
#else
#include <bits/stdc++.h>
#define deb(...) ;
#endif

using namespace std;

struct initon {
    initon() {
        cin.tie(0);
        ios::sync_with_stdio(false);
        cout.setf(ios::fixed);
        cout.precision(16);
        srand((unsigned) clock() + (unsigned) time(NULL));
    };
} initonv;






#define require_t(bo) enable_if_t<bo>* = nullptr
template<typename T, typename U = typename T::value_type> std::true_type value_type_tester(signed);

template<typename T> std::false_type value_type_tester(long);
template<typename T> struct has_value_type : decltype(value_type_tester<T>(0)) {};
template<class T> inline constexpr bool has_value_type_v = has_value_type<T>::value;

template<class T> struct is_vector : std::false_type {};
template<class T> struct is_vector<std::vector<T>> : std::true_type {};
template<class T> inline constexpr bool is_vector_v = is_vector<T>::value;

template<class T1, class T2, bool t1_bigger = (sizeof(T1) > sizeof(T2))> struct max_type { typedef T1 type; };
template<class T1, class T2> struct max_type<T1, T2, false> { typedef T2 type; };



template<class T> using value_type_t = typename T::value_type;


template<class T, bool end = !has_value_type<T>::value> struct value_type_rec { typedef T type; };
template<class T> struct value_type_rec<T, false> { typedef typename value_type_rec<value_type_t<T>>::type type; };
template<class T> using value_type_rec_t = typename value_type_rec<T>::type;



template<class T, bool end = is_same<T, remove_extent_t<T>>::value> struct remove_extent_rec { typedef T type; };
template<class T> struct remove_extent_rec<T, false> { typedef typename remove_extent_rec<remove_extent_t<T>>::type type; };
template<class T> using remove_extent_rec_t = typename remove_extent_rec<T>::type;






#define int long long
#define ll long long
template<class T>using V = vector<T>;
using P = pair<int, int >;
using vb = vector<bool>;
using vc = vector<char>;
using vi = vector<int>;
using vp = vector<P>;
using vs = vector<string>;
#define sz(a) ((ll)(a).size())
#define k4 10101
#define k5 101010
#define k6 1010101
#define k7 10101010
const double PI = 3.1415926535897932384626433832795029L;
const double eps = 1e-9;
using str = string;
using P = pair<ll, ll>;
using T = tuple<ll, ll, ll>;
using F = tuple<ll, ll, ll, ll>;
#define uset unordered_set
#define mset multiset
#define umap unordered_map
#define mp make_pair
#define mt make_tuple
#define fi first
#define se second
#define pb pop_back
#define maxq 1
#define minq -1

#define lam(v, ret) [&](auto&& v){return ret;}
#define lamr(right) [&](auto&& p328961){return p328961 right;}

#define vvt0(t) vector<vector<t>>
#define vvt1(t, a) vector<vector<t>>a
#define vvt2(t, a, b) vector<vector<t>>a(b)
#define vvt3(t, a, b, c) vector<vector<t>> a(b,vector<t>(c))
#define vvt4(t, a, b, c, d) vector<vector<t>> a(b,vector<t>(c,d))

#define vv(type, ...) over4(__VA_ARGS__,vvt4,vvt3,vvt2 ,vvt1,vvt0)(type,__VA_ARGS__)
#define vvi(...) vv(ll,__VA_ARGS__)
#define vvb(...) vv(bool,__VA_ARGS__)
#define vvs(...) vv(string,__VA_ARGS__)
#define vvd(...) vv(double,__VA_ARGS__)
#define vvc(...) vv(char,__VA_ARGS__)
#define vvp(...) vv(P,__VA_ARGS__)
#define vvt(...) vv(T,__VA_ARGS__)



#define over2(o1, o2, name, ...) name
#define over3(o1, o2, o3, name, ...) name
#define over4(o1, o2, o3, o4, name, ...) name
#define over5(o1, o2, o3, o4, o5, name, ...) name
#define over6(o1, o2, o3, o4, o5, o6, name, ...) name
#define over7(o1, o2, o3, o4, o5, o6, o7, name, ...) name
#define over9(o1, o2, o3, o4, o5, o6, o7, o8, o9, name, ...) name



#define over4(o1, o2, o3, o4, name, ...) name
#define rep1(n) for(ll rep1i = 0,rep1lim=n; rep1i < rep1lim ; ++rep1i)
#define rep2(i, n) for(ll i = 0,i##rep2lim=n; i < i##rep2lim ; ++i)
#define rep3(i, m, n) for(ll i = m,i##rep3lim=n; i < i##rep3lim ; ++i)
#define rep4(i, m, n, ad) for(ll i = m,i##rep4lim=n; i < i##rep4lim ; i+= ad)
#define rep(...) over4(__VA_ARGS__,rep4,rep3,rep2,rep1)(__VA_ARGS__)



#define rer2(i, n) for(ll i = n; i >= 0 ; i--)
#define rer3(i, m, n) for(ll i = m,i##rer3lim=n; i >= i##rer3lim ; i--)
#define rer4(i, m, n, dec) for(ll i = m,i##rer4lim=n; i >= i##rer4lim ; i-=dec)
#define rer(...) over4(__VA_ARGS__,rer4,rer3,rer2,)(__VA_ARGS__)

constexpr ll inf = (ll) 1e9 + 100;
constexpr ll linf = (ll) 1e18 + 100;
constexpr double dinf = (double) linf * linf;

template<typename T> class fixed_point: T {public:explicit constexpr fixed_point(T &&t) noexcept: T(std::forward<T>(t)) {}template<typename... Args> constexpr decltype(auto) operator()(Args &&... args) const { return T::operator()(*this, std::forward<Args>(args)...); }};
template<typename T> static inline constexpr decltype(auto) fix(T &&t) noexcept { return fixed_point<T>{std::forward<T>(t)}; }


void set_lr12(int &a, int &b, int n) {        if (b == -1) {
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

template<typename W, typename T> void fill(vector<W> &a, const T &v, int l = -1, ll r = -1) {set_lr12(l, r, a.size());if constexpr(!is_vector<W>::value) { rep(i, l, r)a[i] = v; } else { rep(i, l, r)fill(a[i], v); }}
template<class Iterable, require_t(has_value_type_v<Iterable>)> value_type_rec_t<Iterable> sum(const Iterable &a, int l = -1, int r = -1) {value_type_rec_t<Iterable> ret = 0;        if constexpr(is_vector_v<Iterable>) { set_lr12(l, r, sz(a));                if constexpr(!has_value_type_v<value_type_t<Iterable>>) { rep(i, l, r) ret += a[i]; } else { rep(i, l, r) ret += sum(a[i]); }} else {                if constexpr(!has_value_type_v<value_type_t<Iterable>>) { for (auto &v : a) { ret += v; }} else { for (auto &v : a) { ret += sum(v); }}}return ret;}
template<class Iterable, require_t(has_value_type_v<Iterable>)> value_type_rec_t<Iterable> min(const Iterable &a, int l = -1, int r = -1) {value_type_rec_t<Iterable> ret = MAX<value_type_rec_t<Iterable>>();        if constexpr(is_vector_v<Iterable>) { set_lr12(l, r, sz(a));                if constexpr(!has_value_type_v<value_type_t<Iterable>>) { rep(i, l, r) ret = min(ret, a[i]); } else { rep(i, l, r) ret = min(ret, min(a[i])); }} else {                if constexpr(!has_value_type_v<value_type_t<Iterable>>) { for (auto &v : a) { ret = min(ret, v); }} else { for (auto &v : a) { ret = min(ret, min(v)); }}}return ret;}
template<class Iterable, require_t(has_value_type_v<Iterable>)> value_type_rec_t<Iterable> max(const Iterable &a, int l = -1, int r = -1) {value_type_rec_t<Iterable> ret = MIN<value_type_rec_t<Iterable>>();        if constexpr(is_vector_v<Iterable>) {        set_lr12(l, r, sz(a));                if constexpr(!has_value_type_v<value_type_t<Iterable>>){            rep(i, l, r) ret = max(ret, a[i]);        }else{            rep(i, l, r) ret = max(ret, max(a[i]));        }    }    else {                if constexpr(!has_value_type_v<value_type_t<Iterable>>){            for (auto &v : a) { ret = max(ret, v); }        }else{            for (auto &v : a) { ret = max(ret, max(v)); }        }    }    return ret;}

template<class Array, class T, size_t N> void fill(Array(&a)[N] , const T& v, int l = -1, int r = -1) {    set_lr12(l, r, N);    if constexpr(is_same_v<Array, remove_extent_t<Array>>){        rep(i, l, r) a[i] = v;    }else{        rep(i, l, r) fill(a[i], v);    }}
template<class Array, size_t N> remove_extent_rec_t<Array> sum(const Array(&a)[N] , int l = -1, int r = -1) {    remove_extent_rec_t<Array> ret = 0;    set_lr12(l, r, N);    if constexpr(is_same_v<Array, remove_extent_t<Array>>){        rep(i, l, r) ret += a[i];    }else{        rep(i, l, r) ret += sum(a[i]);    }    return ret;}
template<class Array, size_t N> remove_extent_rec_t<Array> min(const Array(&a)[N] , int l = -1, int r = -1) {    remove_extent_rec_t<Array> ret = MAX<remove_extent_rec_t<Array>>();    set_lr12(l, r, N);    if constexpr(is_same_v<Array, remove_extent_t<Array>>){        rep(i, l, r) ret = std::min(ret, a[i]);    }else{        rep(i, l, r) ret = std::min(ret, min(a[i]));    }    return ret;}
template<class Array, size_t N> remove_extent_rec_t<Array> max(const Array(&a)[N] , int l = -1, int r = -1) {    remove_extent_rec_t<Array> ret = MIN<remove_extent_rec_t<Array>>();    set_lr12(l, r, N);    if constexpr(is_same_v<Array, remove_extent_t<Array>>){        rep(i, l, r) ret = std::max(ret, a[i]);    }else{        rep(i, l, r) ret = std::max(ret, max(a[i]));    }    return ret;}
#ifndef M_MAKE_VECTOR_TUPLE
#define M_MAKE_VECTOR_TUPLE


template<class H, class... T> auto zip_ref(vector<H> &head, vector<T> &...tails) {vector<tuple<H &, T &...>> res;rep(i, sz(head)) { res.emplace_back(head[i], tails[i]...); }return res;}


template<class H, class... T> auto zip(vector<H> &head, vector<T> &...tails) {vector<tuple<H, T...>> res;rep(i, sz(head)) { res.emplace_back(head[i], tails[i]...); }return res;}


template<class H, class... T> auto indexed_zip_ref(vector<H> &head, vector<T> &...tails) {    vector<tuple<int, H &, T &...>> res;    rep(i, sz(head)) { res.emplace_back(i, head[i], tails[i]...); }    return res;}
template<class Tup_l, class Tup_r, size_t ... Indicies> auto helper_unzip(Tup_l &res, const Tup_r &rhs, index_sequence<Indicies...>) {(..., get<Indicies>(res).emplace_back(get<Indicies>(rhs)));}


template<class... T> tuple<vector<T>...> unzip(const vector<tuple<T&...>> &elems) {tuple<vector<T>...> res;for (auto &&elem : elems) { helper_unzip(res, elem, index_sequence_for<T...>{}); }return res;}
#endif 


#define fora_2(a, A) for(auto&& a : A)
#if __cplusplus >= 201703L
#define fora_3(i, a, A) for(auto&&[i, a] : indexed_zip_ref(A))
#define fora_4(a, b, A, B) for(auto&&[a, b] : zip_ref(A, B))
#define fora_5(i, a, b, A, B)  for(auto&&[i, a, b] : indexed_zip_ref(A, B))
#define fora_6(a, b, c, A, B, C)  for(auto&&[a, b, c] : zip_ref(A, B, C))
#define fora_7(i, a, b, c, A, B, C)  for(auto&&[i, a, b, c] : indexed_zip_ref(A, B, C))
#define fora_8(a, b, c, d, A, B, C, D) for(auto&&[a, b, c, d] : zip_ref(A, B, C, D))
#define fora_9(i, a, b, c, d, A, B, C, D) for(auto&&[i, a, b, c, d] : indexed_zip_ref(A, B, C, D))
#endif  


#define fora(...) over9(__VA_ARGS__, fora_9, fora_8, fora_7, fora_6, fora_5, fora_4, fora_3, fora_2)(__VA_ARGS__)



#define ALL(A) (A).begin(), (A).end()

template<class Iterable, class is_Iterable = value_type_t<Iterable>> void sort(Iterable &a) { sort(a.begin(), a.end()); }
template<class Iterable, class is_Iterable = value_type_t<Iterable>> void rsort(Iterable &a) { sort(a.rbegin(), a.rend()); }





#ifndef M_MAKE_VECTOR_TUPLE
#define M_MAKE_VECTOR_TUPLE


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


template<class H, class... T> auto indexed_zip_ref(vector<H> &head, vector<T> &...tails) {
    vector<tuple<int, H &, T &...>> res;
    rep(i, sz(head)) { res.emplace_back(i, head[i], tails[i]...); }
    return res;
}
template<class H, class... T> auto indexed_zip(vector<H> &head, vector<T> &...tails) {
    vector<tuple<int, H, T...>> res;
    rep(i, sz(head)) { res.emplace_back(i, head[i], tails[i]...); }
    return res;
}
template<class Tup_l, class Tup_r, size_t ... Indicies> auto helper_unzip(Tup_l &res, const Tup_r &rhs, index_sequence<Indicies...>) { (..., get<Indicies>(res).emplace_back(get<Indicies>(rhs))); }


template<class... T> tuple<vector<T>...> unzip(const vector<tuple<T &...>> &elems) {
    tuple<vector<T>...> res;
    for (auto &&elem : elems) { helper_unzip(res, elem, index_sequence_for<T...>{}); }
    return res;
}
template<class... T> tuple<vector<T>...> unzip(const vector<tuple<T...>> &elems) {
    tuple<vector<T>...> res;
    for (auto &&elem : elems) { helper_unzip(res, elem, index_sequence_for<T...>{}); }
    return res;
}
#endif  



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
#define I_SORTT 

#ifdef I_SORTT
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



#if __cplusplus >= 201703L
#define set_4(i0, i1, o0, o1) [&](U l, U r) { return get<i0>(l) != get<i0>(r) ? get<i0>(l) o0 get<i0>(r) : get<i1>(l) o1 get<i1>(r) ;}
#define set_6(i0, i1, i2, o0, o1, o2) [&](U l, U r) { return get<i0>(l) != get<i0>(r) ? get<i0>(l) o0 get<i0>(r) : get<i1>(l) != get<i1>(r) ? get<i1>(l) o1 get<i1>(r) : get<i2>(l) o2 get<i2>(r); }

template<class... T, class U=tuple<T...>> function<bool(U, U)> get_function2(const vector<tuple<T...>> &a, tuple_comparator Compare) {
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
template<class A, class B, class U=pair<A, B>> function<bool(U, U)> get_function2(const vector<pair<A, B>> &a, tuple_comparator Compare) {
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
        cerr << "error get_function2 pair<> sort" << endl;
        return [&](U l, U r) { return true; };
    }
}
template<tuple_comparator Compare = fisi, class... T> void sort(vector<tuple<T...>> &a) {
    auto f = get_function2(a, Compare);
    std::sort(a.begin(), a.end(), f);
}
template<tuple_comparator Compare = fisi, class... T> void sort(vector<pair<T...>> &a) {
    auto f = get_function2(a, Compare);
    std::sort(a.begin(), a.end(), f);
}
#undef set_4
#undef set_6

template<tuple_comparator Compare = fisi, class H, class... Ts> void sortt(vector<H> &head, vector<Ts> &...tails) {
    vector<tuple<H, Ts...>> zipped = zip(head, tails...);
    sort<Compare>(zipped);
    tie(head, tails...) = unzip(zipped);
}


template<class H, class... Ts> void rsortt(vector<H> &head, vector<Ts> &...tails) {
    vector<tuple<H, Ts...>> zipped = zip(head, tails...);
    rsort(zipped);tie(head, tails...) = unzip(zipped);
}


template<class F, class H, class... Ts> void sorttf2(F func, H &head, Ts &...tails) {
    auto zipped = zip(head, tails...);
    std::sort(zipped.begin(), zipped.end(), [&](auto &a, auto &b) { return func(a, b); });
    tie(head, tails...) = unzip(zipped);
}



template<class F, class H, class... Ts> void sorttf(F func, H &head, Ts &...tails) { sorttf2([&](auto &a, auto &b) { return func(a) < func(b); }, head, tails...); }
template<class F, class H, class... Ts> void rsorttf(F func, H &head, Ts &...tails) { sorttf2([&](auto &a, auto &b) { return func(a) > func(b); }, head, tails...); }

#endif 

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
    rsortt(b, ind);
    return ind;
}

#if __cplusplus >= 201703L
template<tuple_comparator Compare = fisi, class H, class... Ts> vi sortti(vector<H> head, vector<Ts>... tails) {
    vi ind(sz(head));
    iota(ind.begin(), ind.end(), 0);
    sortt<Compare>(head, tails..., ind);
    return ind;
}
template<class H, class... Ts> vi rsortti(vector<H> head, vector<Ts>... tails) {
    vi ind(sz(head));
    iota(ind.begin(), ind.end(), 0);
    rsortt(head, tails..., ind);
    return ind;
}

#endif 

#endif 




#define I_BINARY_SERACH 

#ifdef I_BINARY_SERACH
#define lowerIndex(a, v) (lower_bound(ALL(a),v)-a.begin())
#define upperIndex(a, v) (upper_bound(ALL(a),v)-a.begin())
#define rlowerIndex(a, v) (upper_bound(ALL(a),v)-a.begin()-1)
#define rupperIndex(a, v) (lower_bound(ALL(a),v)-a.begin()-1)

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
template<class Iterable, class U, class W> value_type_t<Iterable> rlowerBound(Iterable &a, U v, W banpei) {
    decltype(a.begin()) it;
    if constexpr (is_vector<Iterable>::value) { it = upper_bound(a.begin(), a.end(), v); } else { it = a.upper_bound(v); }
    if (it == a.begin())return banpei; else { return *(--it); }
}
template<class Iterable, class U, class W> value_type_t<Iterable> rupperBound(Iterable &a, U v, W banpei) {
    decltype(a.begin()) it;
    if constexpr (is_vector<Iterable>::value) { it = lower_bound(a.begin(), a.end(), v); } else { it = a.lower_bound(v); }
    if (it == a.begin())return banpei; else { return *(--it); }
}
#endif 

#define pow my_pow
#define gcd my_gcd
#define lcm my_lcm



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





template<class R, class T> R sig0_hei(T t) { R lt = t;        if constexpr (is_integral_v<R>) { return lt <= 0 ? 0 : ((1 + lt) * lt) >> 1; } else { return ((1 + lt) * lt) / 2; }}
template<class R, class T, class U> R sig0_hei(T s, U t) { if (s <= 0) { return sig0_hei<R>(t - s) + s * (t - s + 1); } else { return sig0_hei<R>(t) - sig0_hei<R>(s - 1); }}
template<class R, class T> R sig0_kai(T t) { return sig0_hei(t - 1); }
template<class R, class T, class U> R sig0_kai(T s, U t) { return sig0_hei(s, t - 1); }


template<class T = int, class A, class B = int> T my_pow(A a, B b = 2) {
    if (b < 0)return (T) 1 / my_pow<T>(a, -b);
#if __cplusplus >= 201703L
    if constexpr(is_floating_point<T>::value) { return pow((T) a, (T) b); }
    else if constexpr(is_floating_point<A>::value) {
#ifdef _DEBUG
        assert2(0, "pow <not dou>(dou, )");
#endif
    } else if constexpr(is_floating_point<B>::value) {
#ifdef _DEBUG
        assert2(0, "pow <not dou>(, dou)");
#endif
    } else {
#endif
        T ret = 1;
        T bek = a;
        while (b) {
            if (b & 1)ret *= bek;
            bek *= bek;
            b >>= 1;
        }
        return ret;
#if __cplusplus >= 201703L
    }
#endif
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
template<class T, class U> void na2d(vector<T> &a, vector<U> &b, ll n) {
    na2(a, b, n);
    rep(i, n)a[i]--, b[i]--;
}
template<class T, class U, class W> void na3(vector<T> &a, vector<U> &b, vector<W> &c, ll n) {
    a.resize(n);
    b.resize(n);
    c.resize(n);
    rep(i, n)cin >> a[i] >> b[i] >> c[i];
}
template<class T, class U, class W> void na3d(vector<T> &a, vector<U> &b, vector<W> &c, ll n) {
    na3(a, b, c, n);
    rep(i, n)a[i]--, b[i]--, c[i]--;
}
#define nt(a, h, w) resize(a,h,w);rep(nthi,h)rep(ntwi,w) cin >> a[nthi][ntwi];
#define dnt(a, h, w) vector<vector<int>> a; nt(a, h, w)
#define dna(a, n) vi a; na(a, n);
#define dnad(a, n) vi a; nad(a, n);
#define dna2(a, b, n) vi a,b; na2(a,b,n);
#define dna2d(a, b, n) vi a, b; na2d(a, b, n)
#define dna3(a, b, c, n) vi a,b,c; na3(a,b,c,n);
#define dna3d(a, b, c, n) vi a,b,c; na3d(a,b,c,n);

#define din_t2(type, a) type a;cin>>a
#define din_t3(type, a, b) type a,b;cin>>a>> b
#define din_t4(type, a, b, c) type a,b,c;cin>>a>>b>>c
#define din_t5(type, a, b, c, d) type a,b,c,d;cin>>a>>b>>c>>d
#define din_t6(type, a, b, c, d, e) type a,b,c,d,e;cin>>a>>b>>c>>d>>e
#define din_t7(type, a, b, c, d, e, f) type a,b,c,d,e,f;cin>>a>>b>>c>>d>>e>>f
#define din_t(...) over7(__VA_ARGS__,din_t7,din_t6,din_t5,din_t4,din_t3 ,din_t2)(__VA_ARGS__)
#define din(...) din_t(int,__VA_ARGS__)
#define dins(...) din_t(string,__VA_ARGS__)


#define din1d(a) din_t2(int, a);a--
#define din2d(a, b) din_t3(int, a,b);a--,b--
#define din3d(a, b, c) din_t4(int, a,b,c);a--,b--,c--
#define din4d(a, b, c, d) din_t5(int, a,b,c,d);a--,b--,c--,d--
#define dind(...) over4(__VA_ARGS__,din4d,din3d,din2d ,din1d)(__VA_ARGS__)




#if __cplusplus >= 201703L
template<class Tuple, size_t... Indicies> void helper_iss_tuple(istream &iss, Tuple &tup, index_sequence<Indicies...>) { (..., [&](auto &v) { iss >> v; }(get<Indicies>(tup))); }
template<class... T> istream &operator>>(istream &iss, tuple<T...> &tup) {
    helper_iss_tuple(iss, tup, index_sequence_for<T...>{});
    return iss;
}
template<class Tuple, size_t... Indicies> void helper_os_tuple(ostream &os, const Tuple &tup, index_sequence<Indicies...>, const string &sep) {
    stringstream ss;
    (..., [&](auto a) { ss << sep << a; }(get<Indicies>(tup)));
    os << ss.str().substr((int) sep.size());
}
template<class... T> ostream &operator<<(ostream &os, const tuple<T...> &tup) {
    helper_os_tuple(os, tup, index_sequence_for<T...>{}, " ");
    return os;
}
#endif 


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

#ifdef _DEBUG
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
#else
template<class T> void out(T head) {cout << head << endl;}
        template<class T, class... U> void out(T head, U ... tail) {cout << head << " ";out(tail...);}
        void out() { cout << "" << endl; }
#endif 


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
    set_lr12(l, r, sz(A));
    assert(0 <= l && l <= r && r <= sz(A));
    return A.substr(l, r - l);
}
template<class T> vector<T> sub(const vector<T> &A, int l = -1, int r = -1) {
    set_lr12(l, r, sz(A));
    assert(0 <= l && l <= r && r <= sz(A));
    vector<T> ret(r - l);
    std::copy(A.begin() + l, A.begin() + r, ret.begin());
    return ret;
} 
#define bcou __builtin_popcountll
constexpr ll bit(ll n) {
#ifdef _DEBUG
    assert(n <= 62);

#endif
    return (1LL << (n));
}

constexpr bool bget(ll m, ll keta) {
#ifdef _DEBUG
    assert(keta <= 62);

#endif
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

#define assert_yn(yn_v, v); assert(yn_v == 0 || yn_v == v);yn_v = v;
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


#define endl '\n'








#define unique(v) v.erase( unique(v.begin(), v.end()), v.end() );

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