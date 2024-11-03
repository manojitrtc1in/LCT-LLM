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






#pragma region


#define I_FOR_EACH 

#ifdef I_FOR_EACH

template<typename T, typename F> bool all_of2(const T &v, F f) {
    if constexpr(has_value_type<T>::value) {
        for (auto &&v_ : v) { if (!all_of2(v_, f))return false; }
        return true;
    } else { return f(v); }
}
template<typename T, typename F> bool any_of2(const T &v, F f) {
    if constexpr(has_value_type<T>::value) {
        for (auto &&v_ : v) { if (any_of2(v_, f))return true; }
        return false;
    } else { return f(v); }
}
template<typename T, typename F> bool none_of2(const T &v, F f) { return all_of2(v, [&](auto a) { return !f(a); }); }









template<class T> struct range_now { int l;vector<T> A;range_now(vector<T> &&A, int l) : A(A), l(l) {}};
template<typename T, typename F, require_t(has_value_type<T>::value)> ll find_if2(const T &v, F f) {
    rep(i, sz(v)) { if (f(v[i]))return i; }
    return sz(v);
}
template<typename T, typename F> tuple<int, int> find_if2(const vector<vector<T> > &v, F f) {
    rep(i, sz(v)) { rep(j, sz(v[i])) { if (f(v[i][j])) { return tuple<int, int>(i, j); }}}
    return tuple<int, int>(-1, -1);
}
template<typename T, typename F> auto find_if2(const vector<vector<vector<T> > > &v, F f) {
    rep(i, sz(v)) { if (auto ret = find_if2(v[i], f); get<0>(ret) != -1) { return tuple_cat(tuple<int>(i), ret); }}
    auto bad = tuple_cat(tuple<int>(-1), find_if2(v[0], f));
    return bad;
}
template<class T, class F> auto find_if2(const range_now<T> &v, F f) { return find_if2(v.A, f) + v.l; }








template<typename T, typename F, require_t(has_value_type<T>::value)>
ll rfind_if2(const T &v, F f) {    rer(i, sz(v) - 1) { if (f(v[i]))return i; }    return -1;}
template<typename T, typename F> tuple<int, int> rfind_if2(const vector<vector<T> > &v, F f) {    rer(i, sz(v) - 1) { rer(j, sz(v[i]) - 1) { if (f(v[i][j])) { return tuple<int, int>(i, j); }}}    return tuple<int, int>(-1, -1);}
template<typename T, typename F> auto rfind_if2(const vector<vector<vector<T> > > &v, F f) {    rer(i, sz(v) - 1) { if (auto ret = rfind_if2(v[i], f); get<0>(ret) != -1) { return tuple_cat(tuple<int>(i), ret); }}    auto bad = tuple_cat(tuple<int>(-1), rfind_if2(v[0], f));    return bad;}



template<class SS, class T> bool contains(const SS &S, const T &v) {        for(auto&& s : S){            if(s == v)return true;        }        return false;    }
template<typename T, typename F> bool contains_if2(const vector<T> &v, F f) { return find_if(v.begin(), v.end(), f) != v.end(); }
template<typename T, typename F> ll count_if2(const T &v, F f) {    if constexpr(has_value_type<T>::value) {        ll ret = 0;        for (auto &&v_ : v) { ret += count_if2(v_, f); }        return ret;    } else { return f(v); }}
template<typename T, typename F> void for_each2(T &a, F f) {    if constexpr(has_value_type<T>::value) {        for (auto &&v_ : a)for_each2(v_, f);    } else {        f(a);    }}

template<typename W> ll count_od(const vector<W> &a) { return count_if2(a, [](ll v) { return v & 1; }); }
template<typename W> ll count_ev(const vector<W> &a) { return count_if2(a, [](ll v) { return !(v & 1); }); }


template<typename T, typename F> vector<T> erase_if2(const vector<T> &v, F f) {    vector<T> nv;    rep(i, sz(v)) { if (!f(v[i])) { nv.emplace_back(v[i]); }}    return nv;}
template<typename T, typename F> vector<vector<T>> erase_if2(const vector<vector<T>> &v, F f) {    vector<vector<T>> res;    rep(i, sz(v)) { res[i] = erase_if2(v[i], f); }    return res;}


template<typename T, typename F> vector<T> entry_if2(const vector<T> &v, F f) {vector<T> nv;rep(i, sz(v)) { if (f(v[i])) { nv.emplace_back(v[i]); }}return nv;}
template<typename T, typename F> vector<vector<T>> entry_if2(const vector<vector<T>> &v, F f) {vector<vector<T>> res;rep(i, sz(v)) { res[i] = entry_if2(v[i], f); }return res;}







#define all_of__2(a, right) all_of2(a,lamr(right))
#define all_of__3(a, v, siki) all_of2(a,[&](auto v){return siki;})
#define all_of(...) over3(__VA_ARGS__,all_of__3,all_of__2)(__VA_ARGS__)

#define any_of__2(a, right) any_of2(a,lamr(right))
#define any_of__3(a, v, siki) any_of2(a,[&](auto v){return siki;})
#define any_of(...) over3(__VA_ARGS__,any_of__3,any_of__2)(__VA_ARGS__)

#define none_of__2(a, right) none_of2(a,lamr(right))
#define none_of__3(a, v, siki) none_of2(a,[&](auto v){return siki;})
#define none_of(...) over3(__VA_ARGS__,none_of__3,none_of__2)(__VA_ARGS__)

#define find_if__2(a, right) find_if2(a,lamr(right))
#define find_if__3(a, v, siki) find_if2(a,[&](auto v){return siki;})
#define find_if__4(a, l, v, siki) (find_if2(decltype(a)(a.begin()+l , a.end()),[&](auto v){return siki;}) + l)
#define find_if(...) over4(__VA_ARGS__,find_if__4, find_if__3,find_if__2)(__VA_ARGS__)

#define rfind_if__2(a, right) rfind_if2(a,lamr(right))
#define rfind_if__3(a, v, siki) rfind_if2(a,[&](auto v){return siki;})
#define rfind_if(...) over3(__VA_ARGS__,rfind_if__3,rfind_if__2)(__VA_ARGS__)

#define count_if__2(a, right) count_if2(a,lamr(right))
#define count_if__3(a, v, siki) count_if2(a,[&](auto v){return siki;})
#define count_if(...) over3(__VA_ARGS__,count_if__3,count_if__2)(__VA_ARGS__)

#define erase_if__2(a, right) erase_if2(a,lamr(right))
#define erase_if__3(a, v, siki) erase_if2(a,[&](auto v){return siki;})
#define erase_if(...) over3(__VA_ARGS__,erase_if__3,erase_if__2)(__VA_ARGS__)

#define entry_if__2(a, right) entry_if2(a,lamr(right))
#define entry_if__3(a, v, siki) entry_if2(a,[&](auto v){return siki;})
#define entry_if(...) over3(__VA_ARGS__,entry_if__3,entry_if__2)(__VA_ARGS__)

#define for_each__2(a, right) for_each2(a,lamr(right))
#define for_each__3(a, v, shori) for_each2(a,[&](auto& v){shori;})
#define for_each(...) over3(__VA_ARGS__,for_each__3,for_each__2)(__VA_ARGS__)

template<class T, class F> vector<T> help_for_eached(const vector<T> &A, F f) {    vector<T> ret = A;    for_each(ret, v, f(v));    return ret;}
#define for_eached__2(a, right) help_for_eached(a, lamr(right))
#define for_eached__3(a, v, shori) help_for_eached(a, lam(v, shori))
#define for_eached(...) over3(__VA_ARGS__,for_eached__3,for_eached__2)(__VA_ARGS__)
#endif  

#pragma endregion


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

    

    ll mod(ll a, ll m) {if (m < 0) m *= -1;if (a >= 0) {if (a < m) return a;return a % m;} else {if (a >= -m) return a + m;return a % m + m;}}
    ll ceil(ll a, ll b) {if (b == 0) {cerr<<"ceil"<<endl;deb(a, b);return -1;} else if (a < 0) { return 0; } else { return (a + b - 1) / b; }}

    template<class T, class U, class V = typename max_type<T, U>::type>
    V gcd(T a_, U b_) {    V a = a_;    V b = b_;    while (b) a %= b, swap(a, b);    return abs(a);}

    template<class T, class U, class V = typename max_type<T, U>::type>
    V lcm(T a, U b) { return a / gcd(a, b) * b; }

    template<class T>T gcd(const vector<T>& b) {    T res = b[0];    rep(i, 1, sz(b))res = gcd(b[i], res);    return res;}
    template<class T>T lcm(const vector<T>& a) {    T res = a[0];    rep(i, 1, sz(a))res = lcm(a[i], res);    return res;}

    

    

    template<class R, class T> R sig0_hei(T t) {    R lt = t;        if constexpr (is_integral_v<R>) {        return lt <= 0 ? 0 : ((1 + lt) * lt) >> 1;    } else {        return ((1 + lt) * lt) / 2;    }}
    template<class R, class T, class U> R sig0_hei(T s, U t) {    if (s <= 0) {        return sig0_hei<R>(t - s) + s * (t - s + 1);    } else {        return sig0_hei<R>(t) - sig0_hei<R>(s - 1);    }}
    template<class R, class T> R sig0_kai(T t) {return sig0_hei(t-1);}
    template<class R, class T, class U> R sig0_kai(T s, U t) {return sig0_hei(s, t-1);}
    

    template<class T = int, class A, class B = int>T my_pow(A a, B b = 2) {
            if(b < 0)return (T)1 / my_pow<T>(a, -b);
    #if __cplusplus >= 201703L
            if constexpr(is_floating_point<T>::value) { return pow((T) a, (T) b); }
            else if constexpr(is_floating_point<A>::value) {
    #ifdef _DEBUG
                assert2(0, "pow <not dou>(dou, )");
    #endif
            }else if constexpr(is_floating_point<B>::value) {
    #ifdef _DEBUG
                assert2(0, "pow <not dou>(, dou)");
    #endif
            }else {
    #endif
                T ret = 1;        T bek = a;        while (b) {            if (b & 1)ret *= bek;            bek *= bek;            b >>= 1;        }        return ret;
    #if __cplusplus >= 201703L
            }
    #endif
    }
    template<typename W, typename H> void resize(W &vec_, const H head) { vec_.resize(head); }
    template<typename W, typename H, typename ... T> void resize(W &vec_, const H &head, const T ... tail) {
        vec_.resize(head);
        for (auto &v: vec_)resize(v, tail...);
    } 




    template<class T=int> T in() {T ret;cin >> ret;return ret;}
    template<class T> void in(T &head) { cin >> head; }
    template<class T, class... U> void in(T &head, U &... tail) {cin >> head;in(tail...);}
    template<class T> void na(vector<T> &A, int N) {A.resize(N);rep(i, N) { cin >> A[i]; }}
    template<class T> void nad(vector<T> &A, ll N) {na(A, N);rep(i, N)A[i]--;}
    template<class T, class U> void na2(vector<T> &a, vector<U> &b, ll n) {a.resize(n);b.resize(n);rep(i, n)cin >> a[i] >> b[i];}
    template<class T, class U> void na2d(vector<T> &a, vector<U> &b, ll n) {na2(a, b, n);rep(i, n)a[i]--, b[i]--;}
    template<class T, class U, class W> void na3(vector<T> &a, vector<U> &b, vector<W> &c, ll n) {a.resize(n);b.resize(n);c.resize(n);rep(i, n)cin >> a[i] >> b[i] >> c[i];}
    template<class T, class U, class W> void na3d(vector<T> &a, vector<U> &b, vector<W> &c, ll n) {na3(a, b, c, n);rep(i, n)a[i]--, b[i]--, c[i]--;}
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
    template<class Tuple, size_t... Indicies> void helper_os_tuple(ostream &os, const Tuple &tup, index_sequence<Indicies...>, const string& sep) {
        stringstream ss;
        (..., [&](auto a) { ss << sep << a; }(get<Indicies>(tup)));
        os << ss.str().substr((int)sep.size());
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
            if(h < sz(vec_)-1)os << endl;
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
string sub(const string &A, int l = -1, int r = -1) {    set_lr12(l, r, sz(A));    assert(0 <= l && l <= r && r <= sz(A));    return A.substr(l, r - l);}template<class T> vector<T> sub(const vector<T> &A, int l = -1, int r = -1) {    set_lr12(l, r, sz(A));    assert(0 <= l && l <= r && r <= sz(A));    vector<T> ret(r - l);    std::copy(A.begin() + l, A.begin() + r, ret.begin());    return ret;} 
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
vi iota(int s, int t){vi ret(t - s);iota(ALL(ret), s);return ret;}







vb::reference operator|=(vb::reference a, bool b) { return a = a | b; }
vb::reference operator&=(vb::reference a, bool b) { return a = a & b; }
template<class T, class U> vector<T> &operator+=(vector<T> &a, const U &v) {a.emplace_back(v);return a;}
template<class T> vector<T> &operator+=(vector<T> &a, const vector<T> &b) {rep(i, sz(b)) {a.emplace_back(b[i]); }return a;}
template<class T, class U> void operator+=(queue<T> &a, const U &v) { a.push(v); }
template<class T, class U> priority_queue<T, vector<T>, greater<T>> &operator+=(priority_queue<T, vector<T>, greater<T>> &a, const U &v) {a.push(v);return a;}
template<class T, class U> priority_queue<T> &operator+=(priority_queue<T> &a, const U &v) {a.push(v);return a;}
template<class T, class U> auto operator+=(set<T> &a, const U &v) { return a.insert(v); }
template<class T, class U> auto operator-=(set<T> &a, const U &v) { return a.erase(v); }
template<class T, class U> auto operator+=(mset<T> &a, const U &v) { return a.insert(v); }
template<class T, class U> set<T, greater<T>> &operator+=(set<T, greater<T>> &a, const U &v) {a.insert(v);return a;}
template<class T> vector<T> operator+(const vector<T> &a, const vector<T> &b) {vector<T> ret;ret = a;fora(v, b) { ret += v; }return ret;}

template<class T, class U> pair<T, U> operator+=(pair<T,U> &a, const pair<T,U> & b) {a.fi+=b.fi;a.se+=b.se; return a;}
template<class T, class U> pair<T, U> operator+(const pair<T, U> &a, const pair<T, U> &b) { pair<T, U> c = a;c += b;return c;}

template<class T, class U> pair<T, U> operator-=(pair<T,U> &a, const pair<T,U> & b) {a.fi-=b.fi;a.se-=b.se; return a;}
template<class T, class U> pair<T, U> operator-(const pair<T, U> &a, const pair<T, U> &b) { pair<T, U> c = a;c -= b;return c;}

template<class T, class U, class V> pair<T, U> operator*=(pair<T, U> &a, const V& b) { a.fi*=b;a.se*=b; return a;}
template<class T, class U, class V> pair<T, U> operator*(const pair<T, U> &a, const V& b) { pair<T, U> c = a;c *= b;return c; }

template<class T, class U, class V> pair<T, U> operator/=(pair<T, U> &a, const V& b) { a.fi/=b;a.se/=b; return a;}
template<class T, class U, class V> pair<T, U> operator/(const pair<T, U> &a, const V& b) { pair<T, U> c = a;c /= b;return c; }

template<class T, class U> pair<T, U> operator-(const pair<T, U> &a) { return pair<T, U>(-a.first, -a.second); }

#define assert_yn(yn_v, v); assert(yn_v == 0 || yn_v == v);yn_v = v;
int yn_v = 0;
void yn(bool a) { assert_yn(yn_v, 1);if (a)cout << "yes" << endl; else cout << "no" << endl; }
void fyn(bool a) {    assert_yn(yn_v, 1);yn(a);    exit(0);}

void Yn(bool a) { assert_yn(yn_v, 2);if (a)cout << "Yes" << endl; else cout << "No" << endl; }
void fYn(bool a) {    assert_yn(yn_v, 2);Yn(a);    exit(0);}

void YN(bool a) { assert_yn(yn_v, 3);if (a)cout << "YES" << endl; else cout << "NO" << endl; }
void fYN(bool a) {    assert_yn(yn_v, 3);YN(a);    exit(0);}


#define endl '\n'








#define unique(v) v.erase( unique(v.begin(), v.end()), v.end() );

vvc (ba);
ll N, M, H, W;
vi A, B, C;

void solve() {
    int Q;
    cin >> Q;
    while (Q--) {
        din(N, K);
        string S = to_string(N);
        int sn = sz(S);
        string res;
        

        auto check = [&](string T) {
            int cou = 0;
            vi use(10);
            rep(i, sz(T)) {
                if (++use[T[i] - '0'] == 1)cou++;
            }
            if (cou > K)return false;
            int maxv = cou == K ? rfind_if(use, >0) : 9;
            while (sz(T) < sz(S))T += '0' + maxv;
            return T >= S;
        };
        

        rep(i, sn) {
            rep(v, 10) {
                string now = res + string(1, '0' + v);
                if (check(now)) {
                    res = now;
                    break;
                }
            }
        }
        out(res);
    }

}

signed main() {
    solve();

    return 0;
}