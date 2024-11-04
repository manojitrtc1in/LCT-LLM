#include <cassert>
#include <cctype>


#include <cfloat>


#include <climits>


#include <cmath>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#if __cplusplus >= 201103L
#include <ccomplex>
#include <cfenv>
#include <cinttypes>




#include <cstdint>








#endif 




#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>
#if __cplusplus >= 201103L
#include <array>


#include <chrono>




#include <forward_list>


#include <initializer_list>


#include <random>
#include <ratio>
#include <regex>


#include <system_error>


#include <tuple>


#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#endif 


#if __cplusplus >= 201402L
#include <shared_mutex>
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
using vb = vector<bool>;
using vc = vector<char>;
using vi = vector<int>;
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

template<typename T> class fixed_point
        : T {
public:
    explicit constexpr fixed_point(T &&t) noexcept: T(std::forward<T>(t)) {}
    template<typename... Args> constexpr decltype(auto) operator()(Args &&... args) const { return T::operator()(*this, std::forward<Args>(args)...); }
};
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

template<typename W, typename T> void fill(vector<W> &a, const T &v, int l = -1, ll r = -1) {
    set_lr12(l, r, a.size());
    if constexpr(!is_vector<W>::value) { rep(i, l, r)a[i] = v; } else { rep(i, l, r)fill(a[i], v); }
}
template<class Iterable, require_t(has_value_type_v<Iterable>)> value_type_rec_t<Iterable> sum(const Iterable &a, int l = -1, int r = -1) {
    value_type_rec_t<Iterable> ret = 0;        if constexpr(is_vector_v<Iterable>) { set_lr12(l, r, sz(a));                if constexpr(!has_value_type_v<value_type_t<Iterable>>) { rep(i, l, r) ret += a[i]; } else { rep(i, l, r) ret += sum(a[i]); }} else {                if constexpr(!has_value_type_v<value_type_t<Iterable>>) { for (auto &v : a) { ret += v; }} else { for (auto &v : a) { ret += sum(v); }}}
    return ret;
}
template<class Iterable, require_t(has_value_type_v<Iterable>)> value_type_rec_t<Iterable> min(const Iterable &a, int l = -1, int r = -1) {
    value_type_rec_t<Iterable> ret = MAX<value_type_rec_t<Iterable>>();        if constexpr(is_vector_v<Iterable>) { set_lr12(l, r, sz(a));                if constexpr(!has_value_type_v<value_type_t<Iterable>>) { rep(i, l, r) ret = min(ret, a[i]); } else { rep(i, l, r) ret = min(ret, min(a[i])); }} else {                if constexpr(!has_value_type_v<value_type_t<Iterable>>) { for (auto &v : a) { ret = min(ret, v); }} else { for (auto &v : a) { ret = min(ret, min(v)); }}}
    return ret;
}
template<class Iterable, require_t(has_value_type_v<Iterable>)> value_type_rec_t<Iterable> max(const Iterable &a, int l = -1, int r = -1) {value_type_rec_t<Iterable> ret = MIN<value_type_rec_t<Iterable>>();        if constexpr(is_vector_v<Iterable>) {        set_lr12(l, r, sz(a));                if constexpr(!has_value_type_v<value_type_t<Iterable>>){            rep(i, l, r) ret = max(ret, a[i]);        }else{            rep(i, l, r) ret = max(ret, max(a[i]));        }    }    else {                if constexpr(!has_value_type_v<value_type_t<Iterable>>){            for (auto &v : a) { ret = max(ret, v); }        }else{            for (auto &v : a) { ret = max(ret, max(v)); }        }    }    return ret;}

template<class Array, class T, size_t N> void fill(Array(&a)[N] , const T& v, int l = -1, int r = -1) {    set_lr12(l, r, N);    if constexpr(is_same_v<Array, remove_extent_t<Array>>){        rep(i, l, r) a[i] = v;    }else{        rep(i, l, r) fill(a[i], v);    }}
template<class Array, size_t N> remove_extent_rec_t<Array> sum(const Array(&a)[N] , int l = -1, int r = -1) {    remove_extent_rec_t<Array> ret = 0;    set_lr12(l, r, N);    if constexpr(is_same_v<Array, remove_extent_t<Array>>){        rep(i, l, r) ret += a[i];    }else{        rep(i, l, r) ret += sum(a[i]);    }    return ret;}
template<class Array, size_t N> remove_extent_rec_t<Array> min(const Array(&a)[N] , int l = -1, int r = -1) {    remove_extent_rec_t<Array> ret = MAX<remove_extent_rec_t<Array>>();    set_lr12(l, r, N);    if constexpr(is_same_v<Array, remove_extent_t<Array>>){        rep(i, l, r) ret = std::min(ret, a[i]);    }else{        rep(i, l, r) ret = std::min(ret, min(a[i]));    }    return ret;}
template<class Array, size_t N> remove_extent_rec_t<Array> max(const Array(&a)[N] , int l = -1, int r = -1) {    remove_extent_rec_t<Array> ret = MIN<remove_extent_rec_t<Array>>();    set_lr12(l, r, N);    if constexpr(is_same_v<Array, remove_extent_t<Array>>){        rep(i, l, r) ret = std::max(ret, a[i]);    }else{        rep(i, l, r) ret = std::max(ret, max(a[i]));    }    return ret;}
template<class T> void na(vector<T> &A, int N) {A.resize(N);for (int i = 0; i < N; i++) { cin >> A[i]; }}
#define fora(a, A) for(auto& a : A)
#define ALL(A) (A).begin(), (A).end()

template<class T, class U> pair<T, U> operator+=(pair<T,U> &a, const pair<T,U> & b) {a.fi+=b.fi;a.se+=b.se; return a;}
template<class T, class U> pair<T, U> operator+(const pair<T, U> &a, const pair<T, U> &b) { pair<T, U> c = a;c += b;return c;}

template<class T, class U> pair<T, U> operator-=(pair<T,U> &a, const pair<T,U> & b) {a.fi-=b.fi;a.se-=b.se; return a;}
template<class T, class U> pair<T, U> operator-(const pair<T, U> &a, const pair<T, U> &b) { pair<T, U> c = a;c -= b;return c;}

template<class T, class U, class V> pair<T, U> operator*=(pair<T, U> &a, const V& b) { a.fi*=b;a.se*=b; return a;}
template<class T, class U, class V> pair<T, U> operator*(const pair<T, U> &a, const V& b) { pair<T, U> c = a;c *= b;return c; }

template<class T, class U, class V> pair<T, U> operator/=(pair<T, U> &a, const V& b) { a.fi/=b;a.se/=b; return a;}
template<class T, class U, class V> pair<T, U> operator/(const pair<T, U> &a, const V& b) { pair<T, U> c = a;c /= b;return c; }

template<class T, class U> pair<T, U> operator-(const pair<T, U> &a) { return pair<T, U>(-a.first, -a.second); }


#define deb(...)
#define endl '\n'








template<class Iterable, class T = typename Iterable::value_type>
vector<pair<T, signed>> run_length(const Iterable &a) {
    vector<pair<T, signed>> ret;
    ret.emplace_back(a[0], 1);
    for (signed i = 1; i < (signed) a.size(); i++) {
        if (ret.back().first == a[i]) {
            ret.back().second++;
        } else {
            ret.emplace_back(a[i], 1);
        }
    }
    return ret;
}


signed main() {
    int Q;
    cin >> Q;
    while (Q--) {
        int N, K, X;
        cin >> N >> K >> X;
        string S;
        cin >> S;
        

        auto run = run_length(S);
        X--;
        string res;
        vi muls(sz(run) + 100);
        muls[sz(run)] = 1;
        int last_ast = -1;
        

        rer(i, sz(run) - 1, 0) {
            if (muls[i + 1] >= linf) {
                muls[i] = linf;
            } else if (run[i].first == 'a') {
                muls[i] = muls[i + 1];
            } else {
                double cal = (double)muls[i + 1] * (run[i].second * K + 1);;
                muls[i] = cal > linf ? linf : muls[i + 1] * (run[i].second * K + 1);;
            }
            chmi(muls[i], linf);
            if (run[i].first == '*') {
                chma(last_ast, i);
            }
        }
        if(X==0){
            string T;
            for(auto& s : S){
                if(s =='a')T += s;
            }
            cout << T << endl;;
            continue;
        }
        rep(i, sz(run)) {
            auto[c, cou] = run[i];
            if(cou==0)continue;
            if (c == '*') {
                if(muls[i+1] >= linf)continue;
                if (muls[i + 1] <= X) {
                    if(muls[i + 1] == 0)continue;
                    int use = min(cou * K, X / muls[i + 1]);
                    if(use<=0)continue;
                    res += string(use, 'b');
                    X -= use * muls[i + 1];
                }
            } else {
                res += string(cou, 'a');
            }
        }
        cout << res << endl;
    }


    return 0;
}