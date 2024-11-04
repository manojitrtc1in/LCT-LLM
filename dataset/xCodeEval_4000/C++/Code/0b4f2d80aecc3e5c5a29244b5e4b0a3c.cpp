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


#pragma region
void ole_rui() {
#ifdef _DEBUG
    cerr << "ole" << endl;
    exit(0);
#endif
    string a = "a";
    rep(i, 30)a += a;
    rep(i, 1 << 17)cout << a << endl;
    cout << "OLE 出力長制限超過" << endl;
    exit(0);
}
template<class T> T INF() { return numeric_limits<T>::max() / 2; }
template<> signed INF() { return inf; }
template<> ll INF() { return linf; }
template<> double INF() { return dinf; }
template<> char INF() { return '{'; }
template<> string INF() { return "{"; }

template<class T> struct ruiC {
    vector<T> rui;
    ruiC(vector<T> &ru) : rui(ru) {}
    
    ruiC() : rui(1, 0) {}
    T operator()(ll l, ll r) {
        if (l > r) {
            cerr << "ruic ";
            deb(l, r);
            assert(0);
        }
        return rui[r] - rui[l];
    }
    T operator()(int r = inf) { return operator()(0, min(r, sz(rui) - 1)); }
    
    


    T operator[](ll i) { return rui[i]; }
    
    void operator+=(T v) { rui.push_back(rui.back() + v); }
    void add(int i, T v) {
        if (sz(rui) - 1 != i)ole_rui();
        operator+=(v);
    }
    T back() { return rui.back(); }
    ll size() { return rui.size(); }
    auto begin() { return rui.begin(); }
    auto end() { return rui.end(); }
};
template<class T> vector<T> ruiv(const vector<T> &a) {
    vector<T> ret(a.size() + 1);
    rep(i, a.size())ret[i + 1] = ret[i] + a[i];
    return ret;
}
template<class T> ruiC<T> ruic(const vector<T> &a) {
    vector<T> ret = ruiv(a);
    return ruiC<T>(ret);
}
template<class T> ruiC<T> ruic() { return ruiC<T>(); }




template<class T> vector<T> imos(const vector<T> &v) {
    vector<T> ret = v;
    rep(i, sz(ret) - 1)ret[i + 1] += ret[i];
    return ret;
}


template<class T, class U> vi imos(const vector<T> &a, U k) {
    vi equ(sz(a));
    rep(i, sz(a)) { equ[i] = a[i] == k; }
    return imos(equ);
}
template<class T> vector<T> imosx(const vector<T> &v) {
    vector<T> ret = v;
    rep(i, sz(ret) - 1)ret[i + 1] ^= ret[i];
    return ret;
}


template<class T> vector<T> imi(const vector<T> &v) {
    vector<T> ret = v;
    rep(i, sz(ret) - 1)chmi(ret[i + 1], ret[i]);
    return ret;
}
template<class T> vector<T> ima(const vector<T> &v) {
    vector<T> ret = v;
    rep(i, sz(ret) - 1)chma(ret[i + 1], ret[i]);
    return ret;
}
template<class T> vector<T> rimi(const vector<T> &v) {
    vector<T> ret = v;
    rer(i, sz(ret) - 1, 1)chmi(ret[i - 1], ret[i]);
    return ret;
}
template<class T> vector<T> rima(const vector<T> &v) {
    vector<T> ret = v;
    rer(i, sz(ret) - 1, 1)chma(ret[i - 1], ret[i]);
    return ret;
}









template<typename T> struct sparse_rui {
    vector<vector<T> > st;
    vector<int> lookup;
    int qt;
    int n;
    T e;

    sparse_rui() {}
    void build(const vector<T> &v, T e_, int qt_) {
        n = (v.size());
        qt = qt_;
        e = e_;
        int b = 0;
        while ((1 << b) <= v.size()) ++b;
        st.assign(b, vector<T>(1 << b));
        for (int i = 0; i < v.size(); i++) { st[0][i] = v[i]; }
        if (qt == minq) for (int i = 1; i < b; i++) { for (int j = 0; j + (1 << i) <= (1 << b); j++) { st[i][j] = min(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]); }} else for (int i = 1; i < b; i++) { for (int j = 0; j + (1 << i) <= (1 << b); j++) { st[i][j] = max(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]); }}
        lookup.resize(v.size() + 1);
        for (int i = 2; i < lookup.size(); i++) { lookup[i] = lookup[i >> 1] + 1; }
    }
    T operator()(int l, int r) {
        if (l < 0)l = 0;
        if (r > n)r = n;
        if (l >= r)return e;
        int b = lookup[r - l];
        if (qt == minq)return min(st[b][l], st[b][r - (1 << b)]); else return max(st[b][l], st[b][r - (1 << b)]);
    }
    T operator()(int r) { return operator()(0, r); }
};
template<class T> struct ruimax {

private:
    vector<T> ve;
    sparse_rui<pair<T, int>> spa;
    vector<T> rv;
    vector<int> ri;
    T e;
    bool build = false;
public:
    int n;
    ruimax(vector<T> &a, T e) : ve(a), n(sz(a)), e(e) {
        int index = -1;
        T ma = numeric_limits<T>::min();
        rv.resize(n + 1);
        ri.resize(n + 1);
        rv[0] = e;
        ri[0] = -1;
        rep(i, n) {
            if (chma(ma, a[i])) { index = i; }
            rv[i + 1] = ma;
            ri[i + 1] = index;
        }
    }
    T operator()(int l, int r) {
        if (!(l <= r && 0 <= l && r <= n)) {
            deb(l, r, n);
            assert(0);
        }
        if (l == 0) { return rv[r]; }
        else {
            if (!build) {
                vector<pair<T, int>> v2;
                rep(i, ve.size()) { v2.emplace_back(pair<T, int>(ve[i], i)); }
                spa.build(v2, pair<T, int>(e, -1), maxq), build = true;
            }
            return spa(l, r).first;
        }
    }
    T operator()(int r = inf) { return operator()(0, min(r, n)); }
    T operator[](int r) { return operator()(0, r); }
    T getv(int l, int r) { return operator()(l, r); }
    T getv(int r = inf) { return getv(0, min(r, n)); };
    int geti(int l, int r) {
        assert(l <= r && 0 <= l && r <= n);
        if (l == 0) { return ri[r]; }
        else {
            if (!build)spa.build(ve, e, maxq), build = true;
            return spa.query(l, r).second;
        }
    }
    int geti(int r = inf) { return geti(0, min(r, n)); };
    auto begin() { return rv.begin(); }
    auto end() { return rv.end(); }
};
template<class T> struct ruimin {
private:
    vector<T> ve;
    sparse_rui<pair<T, int>> spa;
    vector<T> rv;
    vector<int> ri;
    bool build = false;
    int n;
    T e;
public:
    ruimin(vector<T> &a, T e) : ve(a), n(sz(a)), e(e) {
        int index = -1;
        T mi = numeric_limits<T>::max();
        rv.resize(n + 1);
        ri.resize(n + 1);
        rv[0] = e;
        ri[0] = -1;
        rep(i, n) {
            if (chmi(mi, a[i])) { index = i; }
            rv[i + 1] = mi;
            ri[i + 1] = index;
        }
    }
    T operator()(int l, int r) {
        assert(l <= r && 0 <= l && r <= n);
        if (l == 0) { return rv[r]; }
        else {
            if (!build) {
                vector<pair<T, int>> v2;
                rep(i, ve.size()) { v2.emplace_back(pair<T, int>(ve[i], i)); }
                spa.build(v2, pair<T, int>(e, -1), minq), build = true;
            }
            return spa(l, r).first;
        }
    }
    T operator()(int r = inf) { return operator()(0, min(r, n)); }
    T operator[](int r) { return operator()(0, r); }
    T getv(int l, int r) { return operator()(l, r); }
    T getv(int r = inf) { return getv(0, min(r, n)); };
    int geti(int l, int r) {
        {
            assert(l <= r && 0 <= l && r <= n);
            if (l == 0) { return ri[r]; }
            else {
                if (!build)spa.build(ve, e, minq), build = true;
                return spa.query(l, r).second;
            }
        }
        assert(l <= r && 0 <= l && r <= n);
        if (l == 0) { return ri[r]; }
        else {
            if (!build)spa.build(ve), build = true;
            return spa.query(l, r).second;
        }
    }
    int geti(int r = inf) { return geti(0, min(r, n)); };
    auto begin() { return rv.begin(); }
    auto end() { return rv.end(); }
};

vvi() ruib(vi &a) {    vvi(res, 61, sz(a) + 1);    rep(k, 61) { rep(i, sz(a)) { res[k][i + 1] = res[k][i] + ((a[i] >> k) & 1); }}    return res;}
vector<ruiC<int>> ruibc(vi &a) {vector<ruiC<int>> ret(61);    vvi(res, 61, sz(a));    rep(k, 61) {        rep(i, sz(a)) { res[k][i] = (a[i] >> k) & 1; }        ret[k] = ruic(res[k]);    }    return ret;}


template<class T, class U> vi ruiv(T &a, U k) {    vi ret(a.size() + 1);    rep(i, a.size())ret[i + 1] = ret[i] + (a[i] == k);    return ret;}
template<class T, class U> ruiC<ll> ruic(T &a, U k) {    vi ret = ruiv(a, k);    return ruiC<ll>(ret);}
template<class T> struct ruiC2 {
    int H;
    vector<ruiC<T>> rui;
    ruiC<T> dummy;

    ruiC2(const vector<vector<T>> &ru) : rui(sz(ru)), H(sz(ru)) {            for (int h = 0; h < H; h++) {                if (sz(ru[h]) == 0)continue;                if (sz(dummy) == 1) dummy = ruic(vector<T>(sz(ru[h])));                rui[h] = ruic(ru[h]);            }        }
    

    vector<T> operator()(ll l, ll r) {            if (l > r) {                cerr << "ruic ";                deb(l, r);                assert(0);            }            vector<T> res(H);            for (int h = 0; h < H; h++)res[h] = rui[h](l, r);            return res;        }
    

    ruiC<T> &operator[](ll h) {
#ifdef _DEBUG
        if (h >= H) {message += "warning ruiC h >= H";}
#endif
        if (h >= H || sz(rui[h]) == 1)return dummy;else return rui[h];
    }
    
    

    
    


    








};

template<class U, typename Iterable, class is_Iterable = typename Iterable::value_type>
ruiC<ll> ruicou(Iterable &a, U b) {    vi cou(sz(a));    rep(i, sz(a)) { cou[i] = a[i] == b; }    return ruic(cou);}

template<class U, typename Iterable, class is_Iterable = typename Iterable::value_type>
vector<ll> ruivcou(Iterable &a, U b) {    vi cou(sz(a));    rep(i, sz(a)) { cou[i] = a[i] == b; }    return ruiv(cou);}









template<typename Iterable, class is_Iterable = typename Iterable::value_type>
ruiC2<ll> ruicou(const Iterable &a) {        int H = max(a) + 1;        vvi(cou, H);        rep(i, sz(a)) {            if (sz(cou[a[i]]) == 0)cou[a[i]].resize(sz(a));            cou[a[i]][i] = 1;        }        return ruiC2<ll>(cou);    }





template<class T> vector<T> imosh(vector<vector<T>> &v, int w) {    vector<T> ret(sz(v));    rep(h, sz(ret)) { ret[h] = v[h][w]; }    rep(i, sz(ret) - 1) { ret[i + 1] += ret[i]; }    return ret;}
template<class T> vector<T> ruih(vector<vector<T>> &v, int w) {    vector<T> ret(sz(v) + 1);    rep(h, sz(v)) { ret[h + 1] = v[h][w]; }    rep(i, sz(v)) { ret[i + 1] += ret[i]; }    return ret;}
template<class T> ruiC<T> ruihc(vector<vector<T>> &a, int w) {    vector<T> ret = ruih(a, w);    return ruiC<T>(ret);}



template<class T> struct ruixC {
    vector<T> rui;
    ruixC(vector<T> &ru) : rui(ru) {}
    T operator()(ll l, ll r) {        if (l > r) {            cerr << "ruiXc ";            deb(l, r);            assert(0);        }        return rui[r] ^ rui[l];    }
    T operator[](ll i) { return rui[i]; }
    T back() { return rui.back(); }
    ll size() { return rui.size(); }
};
template<class T> vector<T> ruix(vector<T> &a) {    vector<T> ret(a.size() + 1);    rep(i, a.size())ret[i + 1] = ret[i] ^ a[i];    return ret;}
template<class T> ruixC<ll> ruixc(vector<T> &a) {    vi ret = ruix(a);    return ruixC<ll>(ret);}










vi ruix_diff(vi &A) {    int N = sz(A);    assert(N);    vi res(N + 1);    res[0] = A[0];    rep(i, 1, N) { res[i] = A[i - 1] ^ A[i]; }    res[N] = A[N - 1];    return res;}

template<class T> vector<T> ruim(vector<T> &a) {    vector<T> res(a.size() + 1, 1);    rep(i, a.size())res[i + 1] = res[i] * a[i];    return res;}


template<class T> vector<T> ruimi(vector<T> &a) {ll n = sz(a);    vector<T> ret(n + 1);    rep(i, 1, n) {        ret[i] = a[i - 1];        chmi(ret[i + 1], ret[i]);    }    return ret;}




template<class T> struct rruiC {
    vector<T> rui;
    int n;
    rruiC(vector<T> &a) : n(sz(a)) {        rui.resize(n + 1);        rer(i, n - 1) { rui[i] = rui[i + 1] + a[i]; }    }
    
    T operator()(int r, int l) {        r++;        l++;        assert(l <= r && l >= 0 && r <= n);        return rui[l] - rui[r];    }
    T operator()(int l) { return operator()(n - 1, l); }
    T operator[](int i) { return operator()(i); }
};

#define rrui rruic
template<class T> rruiC<T> rruic(vector<T> &a) { return rruiC<T>(a); }



template<class T> struct ruimulC {
    vector<T> rv;
    int n;
    ruimulC(vector<T> &a) : rv(a), n(sz(a)) {        rv.resize(n + 1);        rv[0] = 1;        rep(i, n) { rv[i + 1] = a[i] * rv[i]; }    }
    ruimulC() : n(0) {        rv.resize(n + 1);        rv[0] = 1;    }
    void operator+=(T v) {        rv.push_back(rv.back() * v);        n++;    }
    T operator()(int l, int r) {        assert(l <= r && 0 <= l && r <= n);        return rv[r] / rv[l];    }
    T operator()(int r = inf) { return operator()(0, min(r, n)); }
    T operator[](int r) { return operator()(0, r); }
    auto begin() { return rv.begin(); }
    auto end() { return rv.end(); }
};
template<class T> ruimulC<T> ruimul(vector<T> &a) { return ruimulC<T>(a); }
template<class T> ruimulC<T> ruimul() {    vector<T> a;    return ruimulC<T>(a);}
template<class T> T *rruim(vector<T> &a) {    ll len = a.size();    T *body = (T *) malloc((len + 1) * sizeof(T));    T *res = body + 1;    res[len - 1] = 1;    rer(i, len - 1)res[i - 1] = res[i] * a[i];    return res;}
template<class T, class U, class W> T lowerBound(ruiC <T> &a, U v, W banpei) { return lowerBound(a.rui, v, banpei); }
template<class T, class U, class W> T upperBound(ruiC <T> &a, U v, W banpei) { return upperBound(a.rui, v, banpei); }
template<class T, class U, class W> T rlowerBound(ruiC <T> &a, U v, W banpei) { return rlowerBound(a.rui, v, banpei); }
template<class T, class U, class W> T rupperBound(ruiC <T> &a, U v, W banpei) { return rupperBound(a.rui, v, banpei); }
template<class T> string deb_tos(const ruiC<T> &a) {return deb_tos(a.rui);}
template<class T> ostream &operator<<(ostream &os, ruiC<T> a) {    fora(v, a.rui){os << v << " "; }   return os;}
template<class T> ostream &operator<<(ostream &os, rruiC<T> a) {    fora(v, a.rui){os << v << " "; }   return os;}
template<class T> string deb_tos(rruiC<T> &a) {return deb_tos(a.rui);}

template<class T> struct ruimono {
    vector<T> rui;
    vector<T> ruir;

    using F = function<T(T, T)>;
    T e;
    F func;
    int N;
    ruimono(vector<T> &arg, F f, const T &e) : func(f), e(e) {N = (int) arg.size();rui.resize(N + 1, e);ruir.resize(N + 1, e);for (int i = 0; i < N; i++) {rui[i + 1] = func(rui[i], arg[i]);ruir[N - i - 1] = func(arg[N - i - 1], ruir[N - i]);}deb(rui);deb(ruir);}
    T get() {return rui.back();}
    T getl(int r) {assert(r <= N);return rui[r];}
    T getr(int l) {assert(l >= 0);return ruir[l];}
    

    T get_other(int m) {return func(getl(m), getr(m + 1));}
};

#pragma endregion
void solve() {
    int Q;
    cin >> Q;
    vi p10(13);
    p10[0]=1;
    rep(i, 12){
        p10[i+1] = p10[i]*10;
    }
    while (Q--) {
        din(N, K);
        string S = to_string(N);
        int keta = sz(S);
        int mi = (pow<int>(10, keta + 1) - 1) / 9;
        rep(mas, 2, bit(10)) {
            if (bcou(mas) != K)continue;
            vc can;
            rep(i, 10)if (bget(mas, i))can += '0'+i;
            

            string maxT = string(keta, can.back());
            if(maxT < S)continue;

            string minT =  string(1,S[0])+ string(keta-1, can[0]);
            if(stoll(minT) > mi)continue;

            int maxTv = stoll(maxT);
            int Sv = stoll(S);
            int tv = 0;
            rep(k, keta) {
                if (bget(mas, S[k] - '0')) {
                    int c = S[k];


                    

                    

                    if (c == S[k] && maxTv / 10 >= Sv % p10[keta - k - 1]) {
                        maxTv /= 10;
                        Sv = Sv % p10[keta - k - 1];
                        tv *= 10;
                        tv += c - '0';
                        continue;
                    }
                }
                {
                    int c = upperBound(can, S[k], -1);
                    tv *= 10;
                    tv += c - '0';
                    rep(nk, k + 1, keta) {
                        tv *= 10;
                        tv += can[0] - '0';
                    }
                    break;


                }
            }
            chmi(mi, tv);
        }
        out(mi);
    }

}

signed main() {
    solve();

    return 0;
}