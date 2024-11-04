

#include <iostream>
#include <set>
#include <vector>
#include <string>
#include <cmath>
#include <map>
#include <tuple>
#include <algorithm>
#include <functional>
#include <deque>
#include <queue>
#include <cstring>
#include <chrono>
#include <numeric>
#include <cassert>
#include <sstream>
#include <random>

#define _T typename
#define _L template

#ifdef __GNUC__ 
#ifndef NO_ONLINE_J 
#pragma GCC target("avx,avx2,fma") 

#endif
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/priority_queue.hpp>






_L <_T T, typename LESS = std::less<T>> using set2 = __gnu_pbds::tree<T, __gnu_pbds::null_type, LESS, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;
_L <_T T, typename LESS = std::greater<T>> using set2_gr = __gnu_pbds::tree<T, __gnu_pbds::null_type, LESS, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;
_L <_T T, typename TV, typename LESS = std::less<T>> using map2 = __gnu_pbds::tree<T, TV, LESS, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;
_L <_T T, typename LESS = std::less_equal<T>> using multiset2 = __gnu_pbds::tree<T, __gnu_pbds::null_type, LESS, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>; 

_L <_T T, typename LESS = std::greater_equal<T>> using multiset2_gr = __gnu_pbds::tree<T, __gnu_pbds::null_type, LESS, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>; 

_L <_T T, class LESS = std::less<T>> using pq2 = __gnu_pbds::priority_queue<T, LESS, __gnu_pbds::pairing_heap_tag>; 

_L <_T T> using pq2_gr = pq2<T, std::greater<T>>;


#endif

using namespace std;




using INT = int;
using DOUBLE = double;

#if 0
using ll = __int128;
#else
using ll = long long int;
#endif

#if 0
using ld = __float128;
#else
using ld = long double;
#endif

using ld_base = long double;

static const ll INF = std::numeric_limits<ll>::max() / 2 - 10; 

static const int INFi = std::numeric_limits<int>::max() - 10;

template<typename T> using vec = std::vector<T>;
template<typename T1, typename T2> using vecpair = std::vector<std::pair<T1, T2>>; 

template<typename T> using vecvec = std::vector<std::vector<T>>;


template<typename T> using priority_queue_gr = std::priority_queue<T, std::vector<T>, std::greater<T>>; 

using vecll = vec<ll>; using setll = set<ll>; using mapll = map<ll, ll>; using pairll = std::pair<ll, ll>;






template<typename TVal, int D = 2> class md {
    int koeff[D]; int koeff2[D]; using IterEnd = int;
    auto size_for_level(int lvl) { return lvl - 1 < 0 ? 1 : koeff[lvl] / koeff[lvl - 1]; }
    template<typename T> decltype(auto) __next(T&& t, int ind) { return t[ind]; }
    template<typename T, typename ... Types> decltype(auto) __next(T&& t, int ind, Types... var2) { return __next(t[ind], var2...); }
public:
    std::vector<TVal> vec; 

    template<typename ... Types> constexpr  md(Types... var2) { 

        static_assert(D == sizeof...(var2)); int ind = 0; int curKoeff = 1; int tmps = 0;
        auto inner = [&](const auto& v) {curKoeff *= v; koeff2[ind] = v; koeff[ind++] = curKoeff; };
        ((inner(var2), tmps) = ...); vec.resize(curKoeff);
    }
    void fill(const TVal& val) { std::fill(vec.begin(), vec.end(), val); }
    TVal sum() { return std::accumulate(vec.begin(), vec.end(), TVal(0)); }
    template<typename ... Types> decltype(auto) operator()(Types... var2) { 

        if constexpr (sizeof...(var2) < D) { return __next(*this, var2...); } else {
            static_assert(D == sizeof...(var2)); int ind = D - 2;  TVal& res = vec[((var2 * (ind < 0 ? 1 : koeff[ind--])) + ...)]; return res;
        }
    }
    template<typename ... Types> auto safe(Types... var2) { 

        static_assert (sizeof...(var2) == D); int dd = D-1;
        if (((var2 < 0 || var2 >= koeff2[dd--]) || ...)) {
            return INF;
        }
        auto& v = *this; return v(var2...);
    }
    template<int LEVEL, int DIR = 1> class Iter {
        friend md; int index = 0;  md* p;
        template<class U, int DELT = 0> using ITER = std::enable_if_t< (LEVEL - DELT > -1), U >;
        template<class U, int DELT = 0> using FLAT = std::enable_if_t< (LEVEL - DELT <= -1), U >;
        auto step(int lvl) { return (lvl < 0 ? 1 : p->koeff[lvl]); }
    public:
        auto size() { return p->size_for_level(LEVEL); }
        void advance(int i) { index += step(LEVEL) * i * DIR; }
        Iter& operator++() { advance(1); return *this; }
        bool operator!=(const IterEnd& other) const { return index != other; }
        template<typename U = Iter&> ITER<U> operator*() { return *this; }
        template<typename U = TVal&> FLAT<U> operator*() { return p->vec[index]; }
        template<typename U = Iter<LEVEL - 1>> ITER<U> begin() { Iter<LEVEL - 1> res;  res.p = p; res.index = index; return res; }
        template<typename U = IterEnd> ITER<U> end() { return p->koeff[LEVEL] + index; }
        template<typename U = Iter<LEVEL - 1, -1>> ITER<U> rbegin() { Iter<LEVEL - 1, -1> res;  res.p = p; res.index = index + p->koeff[LEVEL] - step(LEVEL - 1); return res; }
        template<typename U = IterEnd> ITER<U> rend() { auto res = index - step(LEVEL - 1);            return res; }
        template<typename U = Iter<LEVEL - 1>, int d = 1> ITER<U, d> operator[](int i) { auto it = begin(); it.advance(i); return it; }
        template<typename U = TVal&, int d = 1> FLAT<U, d> operator[](int i) { return p->vec[index + i]; }
        template<typename ... Types> decltype(auto) operator()(Types... var2) { static_assert(sizeof...(var2) <= LEVEL + 1); return p->__next(*this, var2...); }
    };
    auto begin() { Iter<D - 2> res; res.p = this; return res; } IterEnd end() { return koeff[D - 1]; }
    auto rbegin() { Iter<D - 2, -1> res; res.p = this; res.index = koeff[D - 1] - koeff[D - 2]; return res; }  IterEnd rend() { return -koeff[D - 2]; }
    auto operator[](int i) { auto it = begin(); it.advance(i); return it; }
    auto size() { return size_for_level(D - 1); }
};
template <class... T> md(T... t) -> md<ll, sizeof...(T)>;






template<class T> struct __M_IterWrap {
    using Iter = decltype(std::begin(std::declval<T&>()));
    using Iter_end = decltype(std::end(std::declval<T&>()));
    using IterRef = decltype(*std::declval<Iter&>());
    ll i = 0; Iter iter; Iter next; Iter_end iter_end;
    void init(T& cont) { iter = std::begin(cont); iter_end = std::end(cont); }
    __M_IterWrap(T& cont) { init(cont); }  __M_IterWrap(T&& cont) { init(cont); }
    bool check_last() { next = iter; ++next; return !(next != iter_end); }
    auto& begin() { return *this; } int end() { return 0; }
    void operator++() { iter = next; ++i; }  bool operator!=(int) { return iter != iter_end; }
    std::tuple<IterRef, ll, bool> operator*() { return { *iter, i, check_last() }; }
};
template<class T> struct __M_IterWrap_REV {
    using Iter = decltype(std::rbegin(std::declval<T&>()));
    using Iter_end = decltype(std::rend(std::declval<T&>()));
    using IterRef = decltype(*std::declval<Iter&>());
    ll i; Iter iter; Iter_end iter_end; ll n;
    void init(T& cont) { iter = cont.rbegin(); iter_end = cont.rend(); n = cont.size(); i = n - 1; }
    __M_IterWrap_REV(T& cont) { init(cont); } __M_IterWrap_REV(T&& cont) { init(cont); }
    auto& begin() { return *this; } int end() { return 0; }
    void operator++() { ++iter; --i; } bool operator!=(int) { return iter != iter_end; }
    std::tuple<IterRef, ll, bool> operator*() { return { *iter, i, i == n - 1 }; }
};
template<> struct __M_IterWrap<ll> {
    ll i; ll n;
    __M_IterWrap(ll c):n(c) { i = 0; }
    auto& begin() { return *this; } int end() { return 0; }
    void operator++() { ++i; } bool operator!=(int) { return i != n; }
    std::tuple<ll, ll, bool> operator*() { return { i, i, i == n - 1 }; }
};
template<> struct __M_IterWrap_REV<ll> {
    ll i; ll n;
    __M_IterWrap_REV(ll c):n(c) { i = n - 1; }
    auto& begin() { return *this; } int end() { return 0; }
    void operator++() { --i; } bool operator!=(int) { return i >= 0; }
    std::tuple<ll, ll, bool> operator*() { return { i, i, i == n - 1 }; }
};
__M_IterWrap(int)->__M_IterWrap<ll>;
__M_IterWrap_REV(int)->__M_IterWrap_REV<ll>;



#define fe(e,cont) for(auto&& [e, e ## i, e ## _last] : __M_IterWrap (cont))
#define re(e,cont) for(auto&& [e, e ## i, e ## _last] : __M_IterWrap_REV (cont))






#define all(v) std::begin(v),std::end(v)






#define __get1(a) ll a = get_ll();
#define __get2(a,b) __get1(a) __get1(b)
#define __get3(a,b,c) __get2(a,b) __get1(c)
#define __get4(a,b,c,d) __get3(a,b,c) __get1(d)
#define __get5(a,b,c,d,e) __get4(a,b,c,d) __get1(e)
#define __ld_get1(a) ld a = __get<ld_base>();
#define __ld_get2(a,b) __ld_get1(a) __ld_get1(b)
#define __ld_get3(a,b,c) __ld_get2(a,b) __ld_get1(c)
#define __ld_get4(a,b,c,d) __ld_get3(a,b,c) __ld_get1(d)
#define __ld_get5(a,b,c,d,e) __ld_get4(a,b,c,d) __ld_get1(e)
#define __string_get1(a) auto a = get_string();
#define __string_get2(a,b) __string_get1(a) __string_get1(b)
#define __string_get3(a,b,c) __string_get2(a,b) __string_get1(c)
#define __string_get4(a,b,c,d) __string_get3(a,b,c) __string_get1(d)
#define __string_get5(a,b,c,d,e) __string_get4(a,b,c,d) __string_get1(e)
#define __EXPAND( x ) x
#define __GET_MACRO(_0,_1,_2,_3,_4,_5,NAME,...) NAME
#define geti(...) __EXPAND(__GET_MACRO(_0, __VA_ARGS__, __get5, __get4, __get3, __get2, __get1, __get0)(__VA_ARGS__))
#define getс(с) auto с = __get<char>();
#define geta(n, arr) std::vector<ll> arr(n); for (int i = 0; i < n; i+=1) {arr[i] = get_ll();}
#define getd(...) __EXPAND(__GET_MACRO(_0, __VA_ARGS__, __ld_get5, __ld_get4, __ld_get3, __ld_get2, __ld_get1, __get0)(__VA_ARGS__))
#define gets(...) __EXPAND(__GET_MACRO(_0, __VA_ARGS__, __string_get5, __string_get4, __string_get3, __string_get2, __string_get1, __get0)(__VA_ARGS__))
#define getarr(n, arr) geti(n) geta(n, arr)




template<class T> void rem_index(T& cont, int index) { cont.erase(cont.begin() + index); }
template<class T> ll rem_val_all(T& cont, const typename T::value_type& val) { auto newEnd = std::remove(all(cont), val); ll cnt = cont.end() - newEnd; cont.erase(newEnd, cont.end()); return cnt; }
template<class T, class V> bool rem_val_one(T& cont, const V& val) { auto itr = std::find(cont.begin(), cont.end(), val);  if (itr != cont.end()) { cont.erase(itr); return true; } return false; }
template<class T> void sort(pair<T, T>& p) { if (p.first > p.second) std::swap(p.first, p.second); }


template<class T> void sort(T& v) { std::sort(all(v)); }
template<class T> void stable_sort(T& v) { std::stable_sort(all(v)); }
template<class T> void reverse(T& v) { std::reverse(all(v)); }
template <template<class> class H, class S> auto max_element(const H<S>& v) { return *std::max_element(all(v)); }
template <template<class> class H, class S> auto min_element(const H<S>& v) { return *std::min_element(all(v)); }
template <template<class> class H, class S> auto accumulate(const H<S>& v) { return std::accumulate(all(v), (S)0); }
template<class T> void swap_ranges(vec<T>& v, ll start, ll len, ll index2) {
    assert(index2 + len <= start || index2 >= start + len); assert(start + len <= v.size() && index2 + len <= v.size());
    swap_ranges(v.begin() + start, v.begin() + start + len, v.begin() + index2);
}








template <class T> using set_gr = set<T, greater<T>>;
template <class T> using multiset_gr = multiset<T, greater<T>>; 








using namespace std::string_literals;
std::string operator*(const std::string& s, ll count) { std::string res; res.reserve(s.size() * count);  while (count-- > 0) { res += s; }  return res; }
static inline void ltrim(std::string& s) { s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](unsigned char ch) { return !std::isspace(ch); })); }
static inline void rtrim(std::string& s) { s.erase(std::find_if(s.rbegin(), s.rend(), [](unsigned char ch) { return !std::isspace(ch); }).base(), s.end()); }
static inline void trim(std::string& s) { ltrim(s);  rtrim(s); }















ll ipow(ll v, ll p) { assert(p >= 0); ll res = 1; while (p-- > 0) { res *= v; } return res; }
ll ilog_up(ll n, ll k) { assert(k > 1); ll test = 1; ll cnt = 0; while (test < n) { test *= k;  ++cnt; } return  cnt; } 

ll ilog(ll n, ll k) { assert(k > 1); ll test = 1; ll cnt = 0; while (test < n) { test *= k;  ++cnt; } if (test != n) { cnt--; } return  cnt; } 



ll div_up(ll a, ll b) { ll res = a / b; if (res * b != a) res++; return res; } 

ll sum_1_n(ll n) { if (n <= 0) return 0; return (n * n + n) / 2; }






ll round_up(ld val) { return ceill(val); }
# define sqrt(x) sqrtl(x)
# define round(x) roundl(x)






ll count_mult_of(ll l, ll r, ll x) { assert(x > 1); assert(l >= 0); assert(l <= r); return r / x - (l - 1) / x; }

template<class T> pair<T, T> intersect(const pair<T, T>& a, const pair<T, T>& b) { 

    auto res = std::make_pair(std::max(a.first, b.first), std::min(a.second, b.second)); if (res.second < res.first) { return { INF, INF }; } return res;
}
ll parity(ll a) { return a & 1; }; 

bool same_parity(ll a, ll b) { return ((a + b) & 1) == 0; }



















ll fact(ll n) { ll res = 1; for (ll i = 2; i <= n; i++) res *= i; return res; }



ll C_KOMB(ll n, ll k) { return fact(n) / (fact(k) * fact(n - k)); }



ll A_KOMB(ll n, ll k) { return fact(n) / fact(n - k); }






bool s_test(ll s, ll nth) { return (s & (1 << nth)) != 0; }
ll s_bit(ll nth) { return (1 << nth); }; 

void s_on(ll& s, ll nth) { s |= (1 << nth); }
void s_off(ll& s, ll nth) { s &= ~(1 << nth); }

ll s_cnt_of_1(ll s) { return __builtin_popcountll(s); }             

ll s_create_1(ll count) { return (1 << (count)) - 1; }       

ll s_fill_spaces(ll val) { ll c = 1; while (c <= val) c <<= 1; c--; return c; } 













template <typename First, typename... T> bool is_in(const First&& first, const T&&... t) { return ((first == t) || ...); }
_L <_T L, _T... R> L min(const L& l, R&&... right) { L a = l; auto f = [&a](const auto& v) {if (v < a) a = v; }; ((f(right)), ...); return a; }
_L <_T L, _T... R> L max(const L& l, R&&... right) { L a = l; auto f = [&a](const auto& v) {if (v > a) a = v; }; ((f(right)), ...); return a; }
_L <_T L, _T... R> const L& min2(L& l, R&&... right) { auto f = [&l](const auto& v) {if (v < l) l = v; }; ((f(right)), ...); return l; }
_L <_T L, _T... R> const L& max2(L& l, R&&... right) { auto f = [&l](const auto& v) {if (v > l) l = v; }; ((f(right)), ...); return l; }




namespace __rnd { std::random_device rd1; std::default_random_engine e2(rd1());   }



ll rand(ll min, ll max) { std::uniform_int_distribution<ll> d(min, max); return d(__rnd::e2); }



template<class bidiiter> void rand_choose_n(bidiiter begin, bidiiter end, size_t num_random) {
    size_t left = std::distance(begin, end);
    assert(left >= num_random);
    while (num_random--) {
        bidiiter r = begin;
        std::advance(r, rand(0, left - 1)); std::swap(*begin, *r);     ++begin;     --left;
    }
}

auto rand_prob() { std::uniform_real_distribution<ld_base> d(0, 1); return d(__rnd::e2); }






struct Tokenizer {
    std::stringstream iss;
    void add();
    string res() { return iss.str(); }
    template<class ... Types> void add(Types ... vars) { (add(vars), ...); }
    template<class T> void add(T&& v) { iss << v << "_"; }
    template<class ... Types> void addline(Types ... v) { add(v...); iss << "|"; }
};



class Timer {
    using sc = std::chrono::steady_clock;  sc::time_point start;
public:
    Timer():start(sc::now()) {}
    ll elapsedMs() { return std::chrono::duration_cast<std::chrono::milliseconds>(sc::now() - start).count(); }
};




class bs {
    using tfunc = const std::function<bool(ll)>;
    using tfunc_range = const std::function<bool(ll, ll)>;
    static ll __find_first(ll l, ll r, tfunc& f) {
        if (l >= r) return f(l) ? l : l + 1;
        ll mid = (r + l) / 2;
        if (f(mid)) return __find_first(l, mid - 1, f);
        else return __find_first(mid + 1, r, f);
    }
public:
    static ll find_first(ll l, ll r, tfunc& f) { 

        assert(l <= r);
        auto i = __find_first(l, r, f);
        return i == r + 1 ? INF : i;
    }
    static ll find_last(ll l, ll r, tfunc& f) { 

        assert(l <= r);
        tfunc f_rev = [&f](ll i) {return !f(i); };
        auto i = __find_first(l, r, f_rev) - 1;
        return i == l - 1 ? INF : i;
    }
    static ll find_check_range(ll l, ll r, tfunc_range& f) {  

        assert(l <= r);
        if (l >= r) { return (f(l, l) ? l : INF); }
        ll mid = (r + l) / 2;
        if (f(l, mid)) return find_check_range(l, mid, f);
        else return find_check_range(mid + 1, r, f);
    }
};




static ll __MOD = 1'000'000'007;
class llmod {
    static ll pow_r(ll base, ll exp) {
        base = mod(base);
        ll result = 1;
        for (; exp > 0; exp >>= 1) { if (exp & 1) result = mod(result * base); base = mod(base * base); }
        return result;
    }
    static ll mod(ll v) { if (v >= __MOD) return v % __MOD; return v; }
    static ll inv(ll a) { assert(a != 0); return pow_r(a, __MOD - 2); } // work only with MOD = prime    
    static ll fact_r(ll n) { ll res = 1; for (ll i = 2; i <= n; i++) { res = mod(res * i); } return res; }
public:
    static void set2() { __MOD = 998'244'353; }
    static llmod c_komb(ll n, ll k) {  // work only with MOD = prime (ksandr1v)
        if (n < k) return 0;
        return fact_r(n) * mod(pow_r(fact_r(k), __MOD - 2) * pow_r(fact_r(n - k), __MOD - 2));
    }
    static llmod pow(ll base, ll exp) { return pow_r(base, exp); }
    static llmod fact(ll n) { return fact_r(n); }
    ll val = 0;
    llmod(ll v): val(mod(v)) {}    llmod() {}
    llmod& operator+=(const llmod& rhs) { *this = *this + rhs; return *this; }
    llmod& operator-=(const llmod& rhs) { *this = *this - rhs; return *this; }
    llmod& operator*=(const llmod& rhs) { *this = *this * rhs; return *this; }
    llmod& operator/=(const llmod& rhs) { llmod v = inv(rhs.val); return(*this) *= v; }
    llmod operator+(const llmod& rhs) { return llmod(val + rhs.val + __MOD); }
    llmod operator-(const llmod& rhs) { return llmod(val - rhs.val + __MOD); }
    llmod operator*(const llmod& rhs) { return llmod(val * rhs.val); }
    llmod operator/(const llmod& rhs) { llmod tmp(*this); tmp /= rhs; return tmp; }
};
std::ostream& operator<<(std::ostream& stream, const llmod& val) { stream << val.val;    return stream; }

// ---------------------- CORE

extern const char* INPUT_DATA;

#ifdef DEBUG_INPUT
class InnerReader {
    std::istringstream iss; std::string input;
public:
    InnerReader(const char* rawInput): input(rawInput) { trim(input);  iss = std::istringstream(input); }
    bool hasInput() {
        return !input.empty() && !iss.eof();
    }
    int pos() { return iss.tellg(); }
    template<class T> T getNext() {
        if (!hasInput()) {
            int f = 0;
        }
        T val; iss >> val; return val;
    }
};
InnerReader __reader(INPUT_DATA);
#endif

bool __useFile = false;
template<class T> T __get_from_stdin() { T val; std::cin >> val; return val; }
template<class T> T __get() {
#ifdef DEBUG_INPUT    
    if (__useFile) return __get_from_stdin<T>();
    return __reader.getNext<T>();
#else
    return __get_from_stdin<T>();
#endif
}

ll get_ll() { return __get<ll>(); }
char get_char() { return __get<char>(); }
std::string get_string() { return __get<std::string>(); }

template<class T> void print(const T& val);
void endl() { std::cout << "\n"; }
void space() { std::cout << ' '; }
void flush() { std::cout << std::flush; }

template<class T, class Q> std::ostream& operator<<(std::ostream& stream, const pair<T, Q>& val) {
    print(val.first);    space();    print(val.second); return stream;
}
template<class T> std::ostream& operator<<(std::ostream& stream, const std::vector<T>& v) {
    fe(e, v) { print(e);  if (!e_last) { space(); } } return stream;
}
template<class T> void print(const T& val) { std::cout << val; }
template<class T> void print_sp(const T& val) { print(val); space(); }
template<class T, class ... Types> void print(const T& var, const Types&...var2) { print(var); space(); print(var2...); }
template<class T, class ... Types> void line(const T& var, const Types&...var2) { print(var, var2...); endl(); }
//template< template<class> class T, class V> void print(const T<V>& v) { fe(e, v) { print(e);  if (!e_last) { space(); } } }
//template< template<class> class T, class V> void line(const T<V>& v) { print(v);  endl(); }
//template<class T> void print(const std::vector<T>& v) { fe(e, v) { print(e);  if (!e_last) { space(); } } }
//template<class T> void line(const std::vector<T>& v) { print(v);  endl(); }
ll __CUR_TASK = 1;
void onetime(); void prepare();
void task();
void __task() { try { task(); } catch (int& a) {} }
void tcase() {
#ifdef DEBUG_INPUT 
    if (!__useFile && !__reader.hasInput()) __task();
    else {
#endif
        __CUR_TASK = get_ll(); while (__CUR_TASK > 0) { __task(); __CUR_TASK--; };
#ifdef DEBUG_INPUT
    }
#endif
}

void done() { throw 1; } // quick exit
template<class T, class ... Types> void done(const T& var, const Types&...var2) { line(var, var2...); done(); }

#define BREAK goto __label_break // ease break from many loops
#define LABEL __label_break:

extern bool hasTestCase;
int main(int argc, char* argv[]) {
#ifdef NO_ONLINE_J
    if (argc > 1) { freopen(argv[1], "r", stdin); __useFile = true; } else if (__useFile) { freopen("in.txt", "r", stdin); }
#endif
#ifdef DEBUG_INPUT
    bool isDebug = false;
#ifdef MY_DEBUG
    isDebug = true;
#endif      
    line("--------------------", isDebug ? "" : "RELEASE");
    Timer timer;
#endif        
    prepare(); onetime();
    if (hasTestCase) tcase(); else __task();
#ifdef DEBUG_INPUT
    while (!__useFile && __reader.hasInput()) {
        int curp = __reader.pos(); __task(); if (__reader.pos() == curp) break;
    }
    line("\nExecution time:", timer.elapsedMs());
#endif
    return 0;
}

void prepare() {
#ifndef NO_ONLINE_J   
    std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr);  std::cout.tie(nullptr);
#endif    
    std::cout.precision(17);
}



#define int ll
#define double ld;
//-------------------------------------------------------------


void onetime() {
}

bool hasTestCase = true;
const char* INPUT_DATA = R"(
1
4 4
....
....
..#.
.#..


)";

pairll operator+(const pairll& a, const pairll& b) {    return {a.first+b.first, a.second+b.second};}

void task() {

    
    geti(n, m);
    md data(n, m);
    fe(e, n) {
        gets(s);
        fe(k, s) {
            data(ei, ki) = k == '#' ? 1 : 0;
        }
    }

    md vis(n, m);
    map<pairll, pairll> path;

    priority_queue_gr<tuple<ll, ll, ll, ll, ll>> pq;

    pq.emplace(0, INF, INF, INF, INF);

    vec<pairll> pp = { {1,-1}, {1,1}, {-1,-1}, {-1,1} };

    pairll hh;
    ll hmin = INF;

    while (!pq.empty()) {
        auto [cost0, i0, j0, iss, jss] = pq.top();
        pq.pop();

        if (i0 != INF) {
            if (vis(i0, j0))  continue;
            vis(i0, j0) = 1;
        }

        if (j0 == m - 1 && cost0 < hmin) {
            hmin = cost0;
            hh = { i0,j0 };
        }

        path[{i0, j0}] = { iss,jss };

        auto vv = [&](int i, int j) {
            ll cost = 0;
            if (data.safe(i, j) == 0) {
                if (data.safe(i + 1, j) == 1 || data.safe(i - 1, j) == 1 || data.safe(i, j + 1) == 1 || data.safe(i, j - 1) == 1) {
                    return;
                }
                cost++;
            } else if (data.safe(i, j) != 1)
                return;
            pq.emplace(cost0+cost, i, j, i0, j0);
        };

        if (i0 == INF) fe(e, n)  vv(e, 0);
        else fe(e, pp) vv(i0 + e.first, j0 + e.second);
    }


    if (hmin == INF) {
        line("NO");
    }
    else {
        line("YES");
        while (hh.first != INF) {
            data(hh.first, hh.second) = 1;
            hh = path[hh];
        }
        fe(e, data) {
            fe(k, e) {
                print(k == 1 ? '#' : '.');
            }
            endl();
        }
        endl();
    }

    
}