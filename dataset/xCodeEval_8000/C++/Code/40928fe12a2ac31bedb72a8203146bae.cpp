#ifndef ATCODER_INTERNAL_BITOP_HPP
#define ATCODER_INTERNAL_BITOP_HPP 1
#ifdef _MSC_VER
#include <intrin.h>
#endif
namespace atcoder {
namespace internal {




int ceil_pow2(int n) {
    int x = 0;
    while ((1U << x) < (unsigned int)(n)) x++;
    return x;
}




int bsf(unsigned int n) {
#ifdef _MSC_VER
    unsigned long index;
    _BitScanForward(&index, n);
    return index;
#else
    return __builtin_ctz(n);
#endif
}
}  

}  

#endif  

#ifndef ATCODER_INTERNAL_MATH_HPP
#define ATCODER_INTERNAL_MATH_HPP 1
#include <utility>
namespace atcoder {
namespace internal {




constexpr long long safe_mod(long long x, long long m) {
    x %= m;
    if (x < 0) x += m;
    return x;
}






struct barrett {
    unsigned int _m;
    unsigned long long im;
    

    barrett(unsigned int m) : _m(m), im((unsigned long long)(-1) / m + 1) {}
    

    unsigned int umod() const { return _m; }
    

    

    

    unsigned int mul(unsigned int a, unsigned int b) const {
        

        

        

        

        

        

        

        

        

        unsigned long long z = a;
        z *= b;
#ifdef _MSC_VER
        unsigned long long x;
        _umul128(z, im, &x);
#else
        unsigned long long x =
            (unsigned long long)(((unsigned __int128)(z)*im) >> 64);
#endif
        unsigned int v = (unsigned int)(z - x * _m);
        if (_m <= v) v += _m;
        return v;
    }
};






constexpr long long pow_mod_constexpr(long long x, long long n, int m) {
    if (m == 1) return 0;
    unsigned int _m = (unsigned int)(m);
    unsigned long long r = 1;
    unsigned long long y = safe_mod(x, m);
    while (n) {
        if (n & 1) r = (r * y) % _m;
        y = (y * y) % _m;
        n >>= 1;
    }
    return r;
}








constexpr bool is_prime_constexpr(int n) {
    if (n <= 1) return false;
    if (n == 2 || n == 7 || n == 61) return true;
    if (n % 2 == 0) return false;
    long long d = n - 1;
    while (d % 2 == 0) d /= 2;
    for (long long a : {2, 7, 61}) {
        long long t = d;
        long long y = pow_mod_constexpr(a, t, n);
        while (t != n - 1 && y != 1 && y != n - 1) {
            y = y * y % n;
            t <<= 1;
        }
        if (y != n - 1 && t % 2 == 0) {
            return false;
        }
    }
    return true;
}
template <int n> constexpr bool is_prime = is_prime_constexpr(n);




constexpr std::pair<long long, long long> inv_gcd(long long a, long long b) {
    a = safe_mod(a, b);
    if (a == 0) return {b, 0};
    

    

    

    

    long long s = b, t = a;
    long long m0 = 0, m1 = 1;
    while (t) {
        long long u = s / t;
        s -= t * u;
        m0 -= m1 * u;  

        

        

        

        

        auto tmp = s;
        s = t;
        t = tmp;
        tmp = m0;
        m0 = m1;
        m1 = tmp;
    }
    

    

    if (m0 < 0) m0 += b / s;
    return {s, m0};
}






constexpr int primitive_root_constexpr(int m) {
    if (m == 2) return 1;
    if (m == 167772161) return 3;
    if (m == 469762049) return 3;
    if (m == 754974721) return 11;
    if (m == 998244353) return 3;
    int divs[20] = {};
    divs[0] = 2;
    int cnt = 1;
    int x = (m - 1) / 2;
    while (x % 2 == 0) x /= 2;
    for (int i = 3; (long long)(i)*i <= x; i += 2) {
        if (x % i == 0) {
            divs[cnt++] = i;
            while (x % i == 0) {
                x /= i;
            }
        }
    }
    if (x > 1) {
        divs[cnt++] = x;
    }
    for (int g = 2;; g++) {
        bool ok = true;
        for (int i = 0; i < cnt; i++) {
            if (pow_mod_constexpr(g, (m - 1) / divs[i], m) == 1) {
                ok = false;
                break;
            }
        }
        if (ok) return g;
    }
}
template <int m> constexpr int primitive_root = primitive_root_constexpr(m);
}  

}  

#endif  

#ifndef ATCODER_INTERNAL_QUEUE_HPP
#define ATCODER_INTERNAL_QUEUE_HPP 1
#include <vector>
namespace atcoder {
namespace internal {
template <class T> struct simple_queue {
    std::vector<T> payload;
    int pos = 0;
    void reserve(int n) { payload.reserve(n); }
    int size() const { return int(payload.size()) - pos; }
    bool empty() const { return pos == int(payload.size()); }
    void push(const T& t) { payload.push_back(t); }
    T& front() { return payload[pos]; }
    void clear() {
        payload.clear();
        pos = 0;
    }
    void pop() { pos++; }
};
}  

}  

#endif  

#ifndef ATCODER_INTERNAL_SCC_HPP
#define ATCODER_INTERNAL_SCC_HPP 1
#include <algorithm>
#include <utility>
#include <vector>
namespace atcoder {
namespace internal {
template <class E> struct csr {
    std::vector<int> start;
    std::vector<E> elist;
    csr(int n, const std::vector<std::pair<int, E>>& edges)
        : start(n + 1), elist(edges.size()) {
        for (auto e : edges) {
            start[e.first + 1]++;
        }
        for (int i = 1; i <= n; i++) {
            start[i] += start[i - 1];
        }
        auto counter = start;
        for (auto e : edges) {
            elist[counter[e.first]++] = e.second;
        }
    }
};






struct scc_graph {
  public:
    scc_graph(int n) : _n(n) {}
    int num_vertices() { return _n; }
    void add_edge(int from, int to) { edges.push_back({from, {to}}); }
    

    std::pair<int, std::vector<int>> scc_ids() {
        auto g = csr<edge>(_n, edges);
        int now_ord = 0, group_num = 0;
        std::vector<int> visited, low(_n), ord(_n, -1), ids(_n);
        visited.reserve(_n);
        auto dfs = [&](auto self, int v) -> void {
            low[v] = ord[v] = now_ord++;
            visited.push_back(v);
            for (int i = g.start[v]; i < g.start[v + 1]; i++) {
                auto to = g.elist[i].to;
                if (ord[to] == -1) {
                    self(self, to);
                    low[v] = std::min(low[v], low[to]);
                } else {
                    low[v] = std::min(low[v], ord[to]);
                }
            }
            if (low[v] == ord[v]) {
                while (true) {
                    int u = visited.back();
                    visited.pop_back();
                    ord[u] = _n;
                    ids[u] = group_num;
                    if (u == v) break;
                }
                group_num++;
            }
        };
        for (int i = 0; i < _n; i++) {
            if (ord[i] == -1) dfs(dfs, i);
        }
        for (auto& x : ids) {
            x = group_num - 1 - x;
        }
        return {group_num, ids};
    }
    std::vector<std::vector<int>> scc() {
        auto ids = scc_ids();
        int group_num = ids.first;
        std::vector<int> counts(group_num);
        for (auto x : ids.second) counts[x]++;
        std::vector<std::vector<int>> groups(ids.first);
        for (int i = 0; i < group_num; i++) {
            groups[i].reserve(counts[i]);
        }
        for (int i = 0; i < _n; i++) {
            groups[ids.second[i]].push_back(i);
        }
        return groups;
    }
  private:
    int _n;
    struct edge {
        int to;
    };
    std::vector<std::pair<int, edge>> edges;
};
}  

}  

#endif  

#ifndef ATCODER_INTERNAL_TYPE_TRAITS_HPP
#define ATCODER_INTERNAL_TYPE_TRAITS_HPP 1
#include <cassert>
#include <numeric>
#include <type_traits>
namespace atcoder {
namespace internal {
#ifndef _MSC_VER
template <class T>
using is_signed_int128 =
    typename std::conditional<std::is_same<T, __int128_t>::value ||
                                  std::is_same<T, __int128>::value,
                              std::true_type,
                              std::false_type>::type;
template <class T>
using is_unsigned_int128 =
    typename std::conditional<std::is_same<T, __uint128_t>::value ||
                                  std::is_same<T, unsigned __int128>::value,
                              std::true_type,
                              std::false_type>::type;
template <class T>
using make_unsigned_int128 =
    typename std::conditional<std::is_same<T, __int128_t>::value,
                              __uint128_t,
                              unsigned __int128>;
template <class T>
using is_integral = typename std::conditional<std::is_integral<T>::value ||
                                                  is_signed_int128<T>::value ||
                                                  is_unsigned_int128<T>::value,
                                              std::true_type,
                                              std::false_type>::type;
template <class T>
using is_signed_int = typename std::conditional<(is_integral<T>::value &&
                                                 std::is_signed<T>::value) ||
                                                    is_signed_int128<T>::value,
                                                std::true_type,
                                                std::false_type>::type;
template <class T>
using is_unsigned_int =
    typename std::conditional<(is_integral<T>::value &&
                               std::is_unsigned<T>::value) ||
                                  is_unsigned_int128<T>::value,
                              std::true_type,
                              std::false_type>::type;
template <class T>
using to_unsigned = typename std::conditional<
    is_signed_int128<T>::value,
    make_unsigned_int128<T>,
    typename std::conditional<std::is_signed<T>::value,
                              std::make_unsigned<T>,
                              std::common_type<T>>::type>::type;
#else
template <class T> using is_integral = typename std::is_integral<T>;
template <class T>
using is_signed_int =
    typename std::conditional<is_integral<T>::value && std::is_signed<T>::value,
                              std::true_type,
                              std::false_type>::type;
template <class T>
using is_unsigned_int =
    typename std::conditional<is_integral<T>::value &&
                                  std::is_unsigned<T>::value,
                              std::true_type,
                              std::false_type>::type;
template <class T>
using to_unsigned = typename std::conditional<is_signed_int<T>::value,
                                              std::make_unsigned<T>,
                                              std::common_type<T>>::type;
#endif
template <class T>
using is_signed_int_t = std::enable_if_t<is_signed_int<T>::value>;
template <class T>
using is_unsigned_int_t = std::enable_if_t<is_unsigned_int<T>::value>;
template <class T> using to_unsigned_t = typename to_unsigned<T>::type;
}  

}  

#endif  

#ifndef ATCODER_MODINT_HPP
#define ATCODER_MODINT_HPP 1
#include <cassert>
#include <numeric>
#include <type_traits>
#ifdef _MSC_VER
#include <intrin.h>
#endif
namespace atcoder {
namespace internal {
struct modint_base {};
struct static_modint_base : modint_base {};
template <class T> using is_modint = std::is_base_of<modint_base, T>;
template <class T> using is_modint_t = std::enable_if_t<is_modint<T>::value>;
}  

template <int m, std::enable_if_t<(1 <= m)>* = nullptr>
struct static_modint : internal::static_modint_base {
    using mint = static_modint;
  public:
    static constexpr int mod() { return m; }
    static mint raw(int v) {
        mint x;
        x._v = v;
        return x;
    }
    static_modint() : _v(0) {}
    template <class T, internal::is_signed_int_t<T>* = nullptr>
    static_modint(T v) {
        long long x = (long long)(v % (long long)(umod()));
        if (x < 0) x += umod();
        _v = (unsigned int)(x);
    }
    template <class T, internal::is_unsigned_int_t<T>* = nullptr>
    static_modint(T v) {
        _v = (unsigned int)(v % umod());
    }
    static_modint(bool v) { _v = ((unsigned int)(v) % umod()); }
    unsigned int val() const { return _v; }
    mint& operator++() {
        _v++;
        if (_v == umod()) _v = 0;
        return *this;
    }
    mint& operator--() {
        if (_v == 0) _v = umod();
        _v--;
        return *this;
    }
    mint operator++(int) {
        mint result = *this;
        ++*this;
        return result;
    }
    mint operator--(int) {
        mint result = *this;
        --*this;
        return result;
    }
    mint& operator+=(const mint& rhs) {
        _v += rhs._v;
        if (_v >= umod()) _v -= umod();
        return *this;
    }
    mint& operator-=(const mint& rhs) {
        _v -= rhs._v;
        if (_v >= umod()) _v += umod();
        return *this;
    }
    mint& operator*=(const mint& rhs) {
        unsigned long long z = _v;
        z *= rhs._v;
        _v = (unsigned int)(z % umod());
        return *this;
    }
    mint& operator/=(const mint& rhs) { return *this = *this * rhs.inv(); }
    mint operator+() const { return *this; }
    mint operator-() const { return mint() - *this; }
    mint pow(long long n) const {
        assert(0 <= n);
        mint x = *this, r = 1;
        while (n) {
            if (n & 1) r *= x;
            x *= x;
            n >>= 1;
        }
        return r;
    }
    mint inv() const {
        if (prime) {
            assert(_v);
            return pow(umod() - 2);
        } else {
            auto eg = internal::inv_gcd(_v, m);
            assert(eg.first == 1);
            return eg.second;
        }
    }
    friend mint operator+(const mint& lhs, const mint& rhs) {
        return mint(lhs) += rhs;
    }
    friend mint operator-(const mint& lhs, const mint& rhs) {
        return mint(lhs) -= rhs;
    }
    friend mint operator*(const mint& lhs, const mint& rhs) {
        return mint(lhs) *= rhs;
    }
    friend mint operator/(const mint& lhs, const mint& rhs) {
        return mint(lhs) /= rhs;
    }
    friend bool operator==(const mint& lhs, const mint& rhs) {
        return lhs._v == rhs._v;
    }
    friend bool operator!=(const mint& lhs, const mint& rhs) {
        return lhs._v != rhs._v;
    }
  private:
    unsigned int _v;
    static constexpr unsigned int umod() { return m; }
    static constexpr bool prime = internal::is_prime<m>;
};
template <int id> struct dynamic_modint : internal::modint_base {
    using mint = dynamic_modint;
  public:
    static int mod() { return (int)(bt.umod()); }
    static void set_mod(int m) {
        assert(1 <= m);
        bt = internal::barrett(m);
    }
    static mint raw(int v) {
        mint x;
        x._v = v;
        return x;
    }
    dynamic_modint() : _v(0) {}
    template <class T, internal::is_signed_int_t<T>* = nullptr>
    dynamic_modint(T v) {
        long long x = (long long)(v % (long long)(mod()));
        if (x < 0) x += mod();
        _v = (unsigned int)(x);
    }
    template <class T, internal::is_unsigned_int_t<T>* = nullptr>
    dynamic_modint(T v) {
        _v = (unsigned int)(v % mod());
    }
    dynamic_modint(bool v) { _v = ((unsigned int)(v) % mod()); }
    unsigned int val() const { return _v; }
    mint& operator++() {
        _v++;
        if (_v == umod()) _v = 0;
        return *this;
    }
    mint& operator--() {
        if (_v == 0) _v = umod();
        _v--;
        return *this;
    }
    mint operator++(int) {
        mint result = *this;
        ++*this;
        return result;
    }
    mint operator--(int) {
        mint result = *this;
        --*this;
        return result;
    }
    mint& operator+=(const mint& rhs) {
        _v += rhs._v;
        if (_v >= umod()) _v -= umod();
        return *this;
    }
    mint& operator-=(const mint& rhs) {
        _v += mod() - rhs._v;
        if (_v >= umod()) _v -= umod();
        return *this;
    }
    mint& operator*=(const mint& rhs) {
        _v = bt.mul(_v, rhs._v);
        return *this;
    }
    mint& operator/=(const mint& rhs) { return *this = *this * rhs.inv(); }
    mint operator+() const { return *this; }
    mint operator-() const { return mint() - *this; }
    mint pow(long long n) const {
        assert(0 <= n);
        mint x = *this, r = 1;
        while (n) {
            if (n & 1) r *= x;
            x *= x;
            n >>= 1;
        }
        return r;
    }
    mint inv() const {
        auto eg = internal::inv_gcd(_v, mod());
        assert(eg.first == 1);
        return eg.second;
    }
    friend mint operator+(const mint& lhs, const mint& rhs) {
        return mint(lhs) += rhs;
    }
    friend mint operator-(const mint& lhs, const mint& rhs) {
        return mint(lhs) -= rhs;
    }
    friend mint operator*(const mint& lhs, const mint& rhs) {
        return mint(lhs) *= rhs;
    }
    friend mint operator/(const mint& lhs, const mint& rhs) {
        return mint(lhs) /= rhs;
    }
    friend bool operator==(const mint& lhs, const mint& rhs) {
        return lhs._v == rhs._v;
    }
    friend bool operator!=(const mint& lhs, const mint& rhs) {
        return lhs._v != rhs._v;
    }
  private:
    unsigned int _v;
    static internal::barrett bt;
    static unsigned int umod() { return bt.umod(); }
};
template <int id> internal::barrett dynamic_modint<id>::bt = 998244353;
using modint998244353 = static_modint<998244353>;
using modint1000000007 = static_modint<1000000007>;
using modint = dynamic_modint<-1>;
namespace internal {
template <class T>
using is_static_modint = std::is_base_of<internal::static_modint_base, T>;
template <class T>
using is_static_modint_t = std::enable_if_t<is_static_modint<T>::value>;
template <class> struct is_dynamic_modint : public std::false_type {};
template <int id>
struct is_dynamic_modint<dynamic_modint<id>> : public std::true_type {};
template <class T>
using is_dynamic_modint_t = std::enable_if_t<is_dynamic_modint<T>::value>;
}  

}  

#endif  

#ifndef ATCODER_MATH_HPP
#define ATCODER_MATH_HPP 1
#include <algorithm>
#include <cassert>
#include <tuple>
#include <vector>
namespace atcoder {
long long pow_mod(long long x, long long n, int m) {
    assert(0 <= n && 1 <= m);
    if (m == 1) return 0;
    internal::barrett bt((unsigned int)(m));
    unsigned int r = 1, y = (unsigned int)(internal::safe_mod(x, m));
    while (n) {
        if (n & 1) r = bt.mul(r, y);
        y = bt.mul(y, y);
        n >>= 1;
    }
    return r;
}
long long inv_mod(long long x, long long m) {
    assert(1 <= m);
    auto z = internal::inv_gcd(x, m);
    assert(z.first == 1);
    return z.second;
}


std::pair<long long, long long> crt(const std::vector<long long>& r,
                                    const std::vector<long long>& m) {
    assert(r.size() == m.size());
    int n = int(r.size());
    

    long long r0 = 0, m0 = 1;
    for (int i = 0; i < n; i++) {
        assert(1 <= m[i]);
        long long r1 = internal::safe_mod(r[i], m[i]), m1 = m[i];
        if (m0 < m1) {
            std::swap(r0, r1);
            std::swap(m0, m1);
        }
        if (m0 % m1 == 0) {
            if (r0 % m1 != r1) return {0, 0};
            continue;
        }
        

        

        

        

        

        

        

        

        long long g, im;
        std::tie(g, im) = internal::inv_gcd(m0, m1);
        long long u1 = (m1 / g);
        

        if ((r1 - r0) % g) return {0, 0};
        

        long long x = (r1 - r0) / g % u1 * im % u1;
        

        

        

        

        r0 += x * m0;
        m0 *= u1;  

        if (r0 < 0) r0 += m0;
    }
    return {r0, m0};
}
long long floor_sum(long long n, long long m, long long a, long long b) {
    long long ans = 0;  
    if (a >= m) {
        ans += (n - 1) * n * (a / m) / 2;
        a %= m;
    }
    if (b >= m) {
        ans += n * (b / m);
        b %= m;
    }
    long long y_max = (a * n + b) / m, x_max = (y_max * m - b);
    if (y_max == 0) return ans;
    ans += (n - (x_max + a - 1) / a) * y_max;
    ans += floor_sum(y_max, a, m, (a - x_max % a) % a);
    return ans;
}
}  

#endif  


#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
#include <iostream>
#include <limits>
#include <numeric>
#include <type_traits>
#include <bitset>
#include <map>
#include <set>
#include <list>

using namespace atcoder;
using namespace std;

#define rep(i,n,m) for(ll (i)=(n);(i)<(m);(i)++)
#define rrep(i,n,m) for(ll (i)=(n);(i)>(m);(i)--)
using ll = long long;
const ll inf = 1e9;
const ll INF = 1e18;
using mint = modint998244353;



struct ModFac{
    private:
        int n;
        vector<mint> facs,invs;

    public:
        ModFac(int x){
            n = x;
            facs.resize(n+1);
            invs.resize(n+1);

            mint f = 1;
            facs[0] = f;
            for (int i = 1 ; i < n+1 ; i++){
                f *= i;
                facs[i] = f;
            }

            mint g = f.inv();
            invs[n] = g ; invs[0] = 1;
            for (int i = n; i > 1 ; i--){
                g *= i;
                invs[i-1] = g;
            }
        }

        mint getfac(int n){
            return facs[n];
        }

        mint getinv(int n){
            return invs[n];
        }

        mint nCr(int n,int r){
            if (n < r) return (mint)0;
            return facs[n] * invs[n-r] * invs[r];
        }
};

void pline(vector<ll> lis){
    rep(i,0,lis.size()){
        printf ("%lld",lis[i]);
        if (i != lis.size()-1) printf(" ");
        else printf("");
    }
}

void pline(vector<mint> lis){
    rep(i,0,lis.size()){
        printf ("%lld",lis[i].val());
        if (i != lis.size()-1) printf(" ");
        else printf("\n");
    }
}


mint nCr(ll n,ll r){
    if (n < r){
        mint ret = 0;
        return ret;
    }
    mint p = 1 , c = 1;
    rep(i,1,r+1){
        c *= i;
        p *= (n-i+1);
    }
    return p * c.inv();
}

mint fac(ll n){
    mint ret = 1;
    rep(i,1,n+1){
        ret *= i;
    }
    return ret;
}



using S = ll;
S op(S a , S b){
    return a+b;
}
S e(){
    return (ll)0;
}

int main(){

    ll k,A,h;
    scanf("%lld%lld%lld",&k,&A,&h);

    ll n = 1<<k;
    ll hn = 1<<(k-1);

    vector<ll> winjuni(hn);
    if (k == 1){
            winjuni = {1};
    }else if (k == 2){
            winjuni = {3,1};
    }else if (k == 3){
            winjuni = {5,5,3,1};
    }else if (k == 4){
            winjuni = {9,9,9,9,5,5,3,1};
    }else{
            winjuni = {17,17,17,17,17,17,17,17,9,9,9,9,5,5,3,1};
    }

    vector<ll> losjuni(hn);
    if (k == 1){
            losjuni = {2};
    }else if (k == 2){
            losjuni = {3,2};
    }else if (k == 3){
            losjuni = {5,5,3,2};
    }else if (k == 4){
            losjuni = {9,9,9,9,5,5,3,2};
    }else{
            losjuni = {17,17,17,17,17,17,17,17,9,9,9,9,5,5,3,2};
    }
    

    

    {
        map<ll,ll> win; 

        map<ll,ll> lose;

        rep(i,0,1<<(hn-1)){

            vector<ll> wlis(hn);
            list<ll> torn;

            rep(j,0,hn){
                torn.push_back(j);
            }

            rep(j,0,hn-1){
                ll u = torn.front();
                torn.pop_front();
                ll v = torn.front();
                torn.pop_front();
                if (((1<<j) & (i)) > 0){
                    wlis[u] = winjuni[j];
                    torn.push_back(v);
                }else{
                    wlis[v] = winjuni[j];
                    torn.push_back(u);
                }
            }

            ll rem = torn.front();
            wlis[rem] = winjuni[hn-1];

            mint hh = 0;
            rep(j,0,hn){
                hh += (j+1) * ( ((mint)A).pow(wlis[j]) );
            }

            win[hh.val()] = i;

        }

        rep(i,0,1<<(hn-1)){

            vector<ll> wlis(hn);
            list<ll> torn;

            rep(j,0,hn){
                torn.push_back(j);
            }

            rep(j,0,hn-1){
                ll u = torn.front();
                torn.pop_front();
                ll v = torn.front();
                torn.pop_front();
                if (((1<<j) & (i)) > 0){
                    wlis[u] = losjuni[j];
                    torn.push_back(v);
                }else{
                    wlis[v] = losjuni[j];
                    torn.push_back(u);
                }
            }

            ll rem = torn.front();
            wlis[rem] = losjuni[hn-1];

            mint hh = 0;
            rep(j,0,hn){
                hh += (j+hn+1) * ( ((mint)A).pow(wlis[j]) );
            }

            lose[hh.val()] = i;
        }

        for(auto wp : win){
            ll wh = wp.first;
            ll lh = ((mint)h - (mint)wh).val();
            if (lose.count(lh) > 0){
                {
                    ll i = win[wh];
                    vector<ll> wlis(hn);
                    list<ll> torn;
                    rep(j,0,hn){
                        torn.push_back(j);
                    }
                    rep(j,0,hn-1){
                        ll u = torn.front();
                        torn.pop_front();
                        ll v = torn.front();
                        torn.pop_front();
                        if (((1<<j) & (i)) > 0){
                            wlis[u] = winjuni[j];
                            torn.push_back(v);
                        }else{
                            wlis[v] = winjuni[j];
                            torn.push_back(u);
                        }
                    }
                    ll rem = torn.front();
                    wlis[rem] = winjuni[hn-1];
                    pline(wlis);
                    cout << " ";
                }
                {
                    ll i = lose[lh];
                    vector<ll> wlis(hn);
                    list<ll> torn;
                    rep(j,0,hn){
                        torn.push_back(j);
                    }
                    rep(j,0,hn-1){
                        ll u = torn.front();
                        torn.pop_front();
                        ll v = torn.front();
                        torn.pop_front();
                        if (((1<<j) & (i)) > 0){
                            wlis[u] = losjuni[j];
                            torn.push_back(v);
                        }else{
                            wlis[v] = losjuni[j];
                            torn.push_back(u);
                        }
                    }
                    ll rem = torn.front();
                    wlis[rem] = losjuni[hn-1];
                    pline(wlis);
                    cout << "\n";
                }

                return 0;
            }
        }

    }


    {
        map<ll,ll> win; 

        map<ll,ll> lose;

        rep(i,0,1<<(hn-1)){

            vector<ll> wlis(hn);
            list<ll> torn;

            rep(j,0,hn){
                torn.push_back(j);
            }

            rep(j,0,hn-1){
                ll u = torn.front();
                torn.pop_front();
                ll v = torn.front();
                torn.pop_front();
                if (((1<<j) & (i)) > 0){
                    wlis[u] = winjuni[j];
                    torn.push_back(v);
                }else{
                    wlis[v] = winjuni[j];
                    torn.push_back(u);
                }
            }

            ll rem = torn.front();
            wlis[rem] = winjuni[hn-1];

            mint hh = 0;
            rep(j,0,hn){
                hh += (hn+j+1) * ( ((mint)A).pow(wlis[j]) );
            }

            win[hh.val()] = i;

        }

        rep(i,0,1<<(hn-1)){

            vector<ll> wlis(hn);
            list<ll> torn;

            rep(j,0,hn){
                torn.push_back(j);
            }

            rep(j,0,hn-1){
                ll u = torn.front();
                torn.pop_front();
                ll v = torn.front();
                torn.pop_front();
                if (((1<<j) & (i)) > 0){
                    wlis[u] = losjuni[j];
                    torn.push_back(v);
                }else{
                    wlis[v] = losjuni[j];
                    torn.push_back(u);
                }
            }

            ll rem = torn.front();
            wlis[rem] = losjuni[hn-1];

            mint hh = 0;
            rep(j,0,hn){
                hh += (j+1) * ( ((mint)A).pow(wlis[j]) );
            }

            lose[hh.val()] = i;
        }

        for(auto wp : win){
            ll wh = wp.first;
            ll lh = ((mint)h - (mint)wh).val();
            if (lose.count(lh) > 0){
                
                {
                    ll i = lose[lh];
                    vector<ll> wlis(hn);
                    list<ll> torn;
                    rep(j,0,hn){
                        torn.push_back(j);
                    }
                    rep(j,0,hn-1){
                        ll u = torn.front();
                        torn.pop_front();
                        ll v = torn.front();
                        torn.pop_front();
                        if (((1<<j) & (i)) > 0){
                            wlis[u] = losjuni[j];
                            torn.push_back(v);
                        }else{
                            wlis[v] = losjuni[j];
                            torn.push_back(u);
                        }
                    }
                    ll rem = torn.front();
                    wlis[rem] = losjuni[hn-1];
                    pline(wlis);
                    cout << " ";
                }

                {
                    ll i = win[wh];
                    vector<ll> wlis(hn);
                    list<ll> torn;
                    rep(j,0,hn){
                        torn.push_back(j);
                    }
                    rep(j,0,hn-1){
                        ll u = torn.front();
                        torn.pop_front();
                        ll v = torn.front();
                        torn.pop_front();
                        if (((1<<j) & (i)) > 0){
                            wlis[u] = winjuni[j];
                            torn.push_back(v);
                        }else{
                            wlis[v] = winjuni[j];
                            torn.push_back(u);
                        }
                    }
                    ll rem = torn.front();
                    wlis[rem] = winjuni[hn-1];
                    pline(wlis);
                    cout << "\n";
                }

                return 0;
            }
        }

    }

    cout << -1 << endl;
}



