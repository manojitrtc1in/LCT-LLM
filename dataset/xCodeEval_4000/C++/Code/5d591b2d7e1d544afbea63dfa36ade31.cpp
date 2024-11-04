
#ifdef LOCAL


    #define _GLIBCXX_DEBUG  


    #define __clock__
    

#else
    #pragma GCC optimize("Ofast")





    

    

#endif
#define __precision__ 10
#define iostream_untie true
#include <algorithm>
#include <bitset>
#include <cassert>
#include <chrono>
#include <complex>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <valarray>
#define __all(v) std::begin(v), std::end(v)
#define __rall(v) std::rbegin(v), std::rend(v)
#define __popcount(n) __builtin_popcountll(n)
#define __clz32(n) __builtin_clz(n)
#define __clz64(n) __builtin_clzll(n)
#define __ctz32(n) __builtin_ctz(n)
#define __ctz64(n) __builtin_ctzll(n)


namespace std
{
    

    template <class T> size_t hash_combine(size_t seed, T const &key) { return seed ^ (hash<T>()(key) + 0x9e3779b9 + (seed << 6) + (seed >> 2)); }
    template <class T, class U> struct hash<pair<T, U>> { size_t operator()(pair<T, U> const &pr) const { return hash_combine(hash_combine(0, pr.first), pr.second); } };
    template <class tuple_t, size_t index = tuple_size<tuple_t>::value - 1> struct tuple_hash_calc { static size_t apply(size_t seed, tuple_t const &t) { return hash_combine(tuple_hash_calc<tuple_t, index - 1>::apply(seed, t), get<index>(t)); } };
    template <class tuple_t> struct tuple_hash_calc<tuple_t, 0> { static size_t apply(size_t seed, tuple_t const &t) { return hash_combine(seed, get<0>(t)); } };
    template <class... T> struct hash<tuple<T...>> { size_t operator()(tuple<T...> const &t) const { return tuple_hash_calc<tuple<T...>>::apply(0, t); } };
    

    template <class T, class U> istream &operator>>(istream &is, pair<T, U> &p) { return is >> p.first >> p.second; }
    template <class T, class U> ostream &operator<<(ostream &os, const pair<T, U> &p) { return os << p.first << ' ' << p.second; }
    template <class tuple_t, size_t index> struct tupleis { static istream &apply(istream &is, tuple_t &t) { tupleis<tuple_t, index - 1>::apply(is, t); return is >> get<index>(t); } };
    template <class tuple_t> struct tupleis<tuple_t, SIZE_MAX> { static istream &apply(istream &is, tuple_t &t) { return is; } };
    template <class... T> istream &operator>>(istream &is, tuple<T...> &t) { return tupleis<tuple<T...>, tuple_size<tuple<T...>>::value - 1>::apply(is, t); }
    template <> istream &operator>>(istream &is, tuple<> &t) { return is; }
    template <class tuple_t, size_t index> struct tupleos { static ostream &apply(ostream &os, const tuple_t &t) { tupleos<tuple_t, index - 1>::apply(os, t); return os << ' ' << get<index>(t); } };
    template <class tuple_t> struct tupleos<tuple_t, 0> { static ostream &apply(ostream &os, const tuple_t &t) { return os << get<0>(t); } };
    template <class... T> ostream &operator<<(ostream &os, const tuple<T...> &t) { return tupleos<tuple<T...>, tuple_size<tuple<T...>>::value - 1>::apply(os, t); }
    template <> ostream &operator<<(ostream &os, const tuple<> &t) { return os; }
    template <class Container, typename Value = typename Container::value_type, enable_if_t<!is_same<decay_t<Container>, string>::value, nullptr_t> = nullptr>
    istream& operator>>(istream& is, Container &cont) { for(auto&& e : cont) is >> e; return is; }
    template <class Container, typename Value = typename Container::value_type, enable_if_t<!is_same<decay_t<Container>, string>::value, nullptr_t> = nullptr>
    ostream& operator<<(ostream& os, const Container &cont) { bool flag = 1; for(auto&& e : cont) flag ? flag = 0 : (os << ' ', 0), os << e; return os; }
} 


namespace setting
{
    using namespace std;
    using namespace chrono;
    system_clock::time_point start_time, end_time;
    long long get_elapsed_time() { end_time = system_clock::now(); return duration_cast<milliseconds>(end_time - start_time).count(); }
    void print_elapsed_time() { cerr << "\n----- Exec time : " << get_elapsed_time() << " ms -----\n\n"; }
    void buffer_check() { char bufc; if(cin >> bufc) cerr << "\n\033[1;35mwarning\033[0m: buffer not empty.\n"; }
    struct setupper
    {
        setupper()
        {
            if(iostream_untie) ios::sync_with_stdio(false), cin.tie(nullptr);
            cout << fixed << setprecision(__precision__);
    #ifdef stderr_path
            if(freopen(stderr_path, "a", stderr)) cerr << fixed << setprecision(__precision__);
    #endif
    #ifdef LOCAL
            cerr << boolalpha << "\n----- stderr at LOCAL -----\n\n";
    #endif
    #ifdef __buffer_check__
            atexit(buffer_check);
    #endif
    #ifdef __clock__
            start_time = system_clock::now();
            atexit(print_elapsed_time);
    #endif
        }
    } __setupper; 

} 


#ifdef __clock__
    #include "C:\Users\euler\OneDrive\Documents\Competitive_Programming\Library\local\clock.hpp"
#else
    #define build_clock() ((void)0)
    #define set_clock() ((void)0)
    #define get_clock() ((void)0)
#endif

#ifdef LOCAL
    #include "C:\Users\euler\OneDrive\Documents\Competitive_Programming\Library\local\dump.hpp"
#else
    #define dump(...) ((void)0)
#endif


template <class T, class... types> T read(types... args) noexcept { typename std::remove_const<T>::type obj(args...); std::cin >> obj; return obj; }
#define input(type, var, ...) type var{read<type>(__VA_ARGS__)}


template <class T> inline bool chmin(T &x, const T &y) { return x > y ? x = y, true : false; }


template <class T> inline bool chmax(T &x, const T &y) { return x < y ? x = y, true : false; }


template <class iter_type, class pred_type>
iter_type binary(iter_type __ok, iter_type __ng, pred_type pred)
{
    std::ptrdiff_t dist(__ng - __ok);
    while(std::abs(dist) > 1)
    {
        iter_type mid(__ok + dist / 2);
        if(pred(mid)) __ok = mid, dist -= dist / 2;
        else __ng = mid, dist /= 2;
    }
    return __ok;
}


template <class pred_type>
long double binary(long double __ok, long double __ng, const long double eps, pred_type pred)
{
    while(std::abs(__ok - __ng) > eps)
    {
        long double mid{(__ok + __ng) / 2};
        (pred(mid) ? __ok : __ng) = mid;
    }
    return __ok;
}


template <class A, size_t N> size_t size(A (&array)[N]) { return N; }


template <class T, class A, size_t N> void init(A (&array)[N], const T &val) { std::fill((T*)array, (T*)(array + N), val); }



using namespace std;
using i32 = int_least32_t; using i64 = int_least64_t; using u32 = uint_least32_t; using u64 = uint_least64_t;
using p32 = pair<i32, i32>; using p64 = pair<i64, i64>;
template <class T, class Comp = less<T>> using heap = priority_queue<T, vector<T>, Comp>;
template <class T> using hashset = unordered_set<T>;
template <class Key, class Value> using hashmap = unordered_map<Key, Value>;




#include <cassert>
#include <vector>

template <class monoid, class isomorphism>
class lazy_segment_tree
{
    using size_type = typename std::vector<monoid>::size_type;

    size_type size_orig, height, size_ext;
    std::vector<monoid> data;
    std::vector<isomorphism> lazy;

    void recalc(const size_type node) { data[node] = data[node << 1] + data[node << 1 | 1]; }

    void apply(size_type index, const isomorphism &iso)
    {
        iso.apply(data[index]);
        if(index < size_ext) lazy[index] *= iso;
    }

    void push(size_type index)
    {
        if(index >= size_ext) return;
        apply(index << 1, lazy[index]);
        apply(index << 1 | 1, lazy[index]);
        lazy[index] = isomorphism{};
    }

    template <class pred_type>
    size_type left_search_subtree(size_type index, const pred_type pred, monoid mono)
    {
        assert(index);
        while(index < size_ext)
        {
            push(index);
            const monoid tmp = data[(index <<= 1) | 1] + mono;
            if(pred(tmp)) mono = tmp;
            else ++index;
        }
        return ++index -= size_ext;
    }

    template <class pred_type>
    size_type right_search_subtree(size_type index, const pred_type pred, monoid mono)
    {
        assert(index);
        while(index < size_ext)
        {
            push(index);
            const monoid tmp = mono + data[index <<= 1];
            if(pred(tmp)) ++index, mono = tmp;
        }
        return (index -= size_ext) < size_orig ? index : size_orig;
    }

public:
    lazy_segment_tree(const size_type n = 0) : size_orig{n}, height(n > 1 ? 32 - __builtin_clz(n - 1) : 0), size_ext{1u << height}, data(size_ext << 1), lazy(size_ext) {}

    lazy_segment_tree(const size_type n, const monoid &init) : lazy_segment_tree(n)
    {
        std::fill(std::next(std::begin(data), size_ext), std::end(data), init);
        for(size_type i{size_ext}; --i; ) recalc(i);
    }

    template <class iter_type, class value_type = typename std::iterator_traits<iter_type>::value_type>
    lazy_segment_tree(iter_type first, iter_type last)
        : size_orig(std::distance(first, last)), height(size_orig > 1 ? 32 - __builtin_clz(size_orig - 1) : 0), size_ext{1u << height}, data(size_ext << 1), lazy(size_ext)
    {
        static_assert(std::is_constructible<monoid, value_type>::value, "monoid(iter_type::value_type) is not constructible.");
        for(auto iter{std::next(std::begin(data), size_ext)}; iter != std::end(data) && first != last; ++iter, ++first) *iter = monoid(*first);
        for(size_type i{size_ext}; --i; ) recalc(i);
    }

    template <class container_type, typename = typename container_type::value_type>
    lazy_segment_tree(const container_type &cont) : lazy_segment_tree(std::begin(cont), std::end(cont)) {}

    size_type size() const { return size_orig; }
    size_type capacity() const { return size_ext; }

    monoid operator[](size_type index) { return fold(index, index + 1); }

    void update(const size_type index, const isomorphism &iso) { update(index, index + 1, iso); }

    void update(size_type first, size_type last, const isomorphism &iso)
    {
        assert(last <= size_orig);
        if(first >= last) return;
        first += size_ext, last += size_ext - 1;
        for(size_type i = height; i; --i) push(first >> i), push(last >> i);
        for(size_type l = first, r = last + 1; last; l >>= 1, r >>= 1)
        {
            if(l < r)
            {
                if(l & 1) apply(l++, iso);
                if(r & 1) apply(--r, iso);
            }
            if(first >>= 1, last >>= 1)
            {
                recalc(first), recalc(last);
            }
        }
    }

    monoid fold() { return fold(0, size_orig); }

    monoid fold(size_type first, size_type last)
    {
        assert(last <= size_orig);
        if(first >= last) return monoid{};
        first += size_ext, last += size_ext - 1;
        monoid left_val{}, right_val{};
        for(size_type l = first, r = last + 1; last; l >>= 1, r >>= 1)
        {
            if(l < r)
            {
                if(l & 1) left_val = left_val + data[l++];
                if(r & 1) right_val = data[--r] + right_val;
            }
            if(first >>= 1, last >>= 1)
            {
                lazy[first].apply(left_val);
                lazy[last].apply(right_val);
            }
        }
        return left_val + right_val;
    }

    template <class pred_type>
    size_type left_search(size_type right, const pred_type pred)
    {
        assert(right <= size_orig);
        right += size_ext - 1;
        for(size_type i{height}; i; --i) push(right >> i);
        ++right;
        monoid mono{};
        for(size_type left{size_ext}; left != right; left >>= 1, right >>= 1)
        {
            if((left & 1) != (right & 1))
            {
                const monoid tmp = data[--right] + mono;
                if(!pred(tmp)) return left_search_subtree(right, pred, mono);
                mono = tmp;
            }
        }
        return 0;
    }

    template <class pred_type>
    size_type right_search(size_type left, const pred_type pred)
    {
        assert(left <= size_orig);
        left += size_ext;
        for(size_type i{height}; i; --i) push(left >> i);
        monoid mono{};
        for(size_type right{size_ext << 1}; left != right; left >>= 1, right >>= 1)
        {
            if((left & 1) != (right & 1))
            {
                const monoid tmp = mono + data[left];
                if(!pred(tmp)) return right_search_subtree(left, pred, mono);
                mono = tmp;
                ++left;
            }
        }
        return size_orig;
    }
}; 


#ifndef Modint_hpp
#define Modint_hpp
#include <cassert>
#include <iostream>

template <int mod>
class modint
{
    int val;
public:
    constexpr modint() noexcept : val{0} {}
    constexpr modint(long long x) noexcept : val((x %= mod) < 0 ? mod + x : x) {}
    constexpr long long value() const noexcept { return val; }
    constexpr modint operator++(int) noexcept { modint t = *this; return ++val, t; }
    constexpr modint operator--(int) noexcept { modint t = *this; return --val, t; }
    constexpr modint &operator++() noexcept { return ++val, *this; }
    constexpr modint &operator--() noexcept { return --val, *this; }
    constexpr modint operator-() const noexcept { return modint(-val); }
    constexpr modint &operator+=(const modint &other) noexcept { return (val += other.val) < mod ? 0 : val -= mod, *this; }
    constexpr modint &operator-=(const modint &other) noexcept { return (val += mod - other.val) < mod ? 0 : val -= mod, *this; }
    constexpr modint &operator*=(const modint &other) noexcept { return val = (long long)val * other.val % mod, *this; }
    constexpr modint &operator/=(const modint &other) noexcept { return *this *= inverse(other); }
    constexpr modint operator+(const modint &other) const noexcept { return modint(*this) += other; }
    constexpr modint operator-(const modint &other) const noexcept { return modint(*this) -= other; }
    constexpr modint operator*(const modint &other) const noexcept { return modint(*this) *= other; }
    constexpr modint operator/(const modint &other) const noexcept { return modint(*this) /= other; }
    constexpr bool operator==(const modint &other) const noexcept { return val == other.val; }
    constexpr bool operator!=(const modint &other) const noexcept { return val != other.val; }
    constexpr bool operator!() const noexcept { return !val; }
    friend constexpr modint operator+(long long x, modint y) noexcept { return modint(x) + y; }
    friend constexpr modint operator-(long long x, modint y) noexcept { return modint(x) - y; }
    friend constexpr modint operator*(long long x, modint y) noexcept { return modint(x) * y; }
    friend constexpr modint operator/(long long x, modint y) noexcept { return modint(x) / y; }
    static constexpr modint inverse(const modint &other) noexcept
    {
        assert(other != 0);
        int a{mod}, b{other.val}, u{}, v{1}, t{};
        while(b) t = a / b, a ^= b ^= (a -= t * b) ^= b, u ^= v ^= (u -= t * v) ^= v;
        return {u};
    }
    static constexpr modint pow(modint other, long long e) noexcept
    {
        if(e < 0) e = e % (mod - 1) + mod - 1;
        modint res{1};
        while(e) { if(e & 1) res *= other; other *= other, e >>= 1; }
        return res;
    }
    friend std::ostream &operator<<(std::ostream &os, const modint &other) noexcept { return os << other.val; }
    friend std::istream &operator>>(std::istream &is, modint &other) noexcept { long long val; other = {(is >> val, val)}; return is; }
}; 


template <>
class modint<2>
{
    bool val;
public:
    constexpr modint(bool x = false) noexcept : val{x} {}
    constexpr modint(int x) noexcept : val(x & 1) {}
    constexpr modint(long long x) noexcept : val(x & 1) {}
    constexpr operator bool() const noexcept { return val; }
    constexpr bool value() const noexcept { return val; }
    constexpr modint &operator+=(const modint &other) noexcept { return val ^= other.val, *this; }
    constexpr modint &operator-=(const modint &other) noexcept { return val ^= other.val, *this; }
    constexpr modint &operator*=(const modint &other) noexcept { return val &= other.val, *this; }
    constexpr modint &operator/=(const modint &other) noexcept { assert(other.val); return *this; }
    constexpr modint operator!() const noexcept { return !val; }
    constexpr modint operator-() const noexcept { return *this; }
    constexpr modint operator+(const modint &other) const noexcept { return val != other.val; }
    constexpr modint operator-(const modint &other) const noexcept { return val != other.val; }
    constexpr modint operator*(const modint &other) const noexcept { return val && other.val; }
    constexpr modint operator/(const modint &other) const noexcept { assert(other.val); return *this; }
    constexpr bool operator==(const modint &other) const noexcept { return val == other.val; }
    constexpr bool operator!=(const modint &other) const noexcept { return val != other.val; }
    friend constexpr modint operator+(long long x, modint y) noexcept { return x & 1 ? !y : y; }
    friend constexpr modint operator-(long long x, modint y) noexcept { return x & 1 ? !y : y; }
    friend constexpr modint operator*(long long x, modint y) noexcept { return x & 1 ? y : modint<2>{0}; }
    friend constexpr modint operator/(long long x, modint y) noexcept { assert(y.val); return x & 1 ? y : modint<2>{0}; }
    friend std::ostream &operator<<(std::ostream &os, const modint &other) noexcept { return os << other.val; }
    friend std::istream &operator>>(std::istream &is, modint &other) noexcept { long long val; other.val = (is >> val, val & 1); return is; }
}; 


#endif 






template <class T> void _main();
struct solver;
int main() { _main<solver>(); }

template <class solver>
void _main()
{
    unsigned t;
#ifdef LOCAL
    t = 1;
#else
    t = 1; 

#endif
    

    


    while(t--) solver();
}

using mint=modint<998244353>;

struct solver
{

    solver()
    {
        int n,k,m; cin>>n>>k>>m;
        vector<vector<p32>> cond(n);
        for(int i=0; i<m; ++i)
        {
            int l,r,x; cin>>l>>r>>x; --l,--r;
            cond[r].emplace_back(l,x);
        }

        mint ans=1;
        for(int b=0; b<k; ++b)
        {
            vector<int> ncond(n,-1);
            vector<int> aldy(n);

            for(int i=0;i<n;++i)
            {
                for(auto [l,x] : cond[i])
                {
                    if(x>>b&1)
                    {
                        aldy[l]++;
                        if(i+1<n) aldy[i+1]--;
                    }
                    else
                    {
                        chmax(ncond[i],l);
                    }
                }
            }
            for(int i=0;i+1<n;++i)
            {
                aldy[i+1]+=aldy[i];
            }

            vector<mint> dp(n+1);
            dp[0]=1;
            mint crt=1;

            for(int i=0,j=0;i<n;++i)
            {
                mint tmp;
                if(!aldy[i])
                {
                    tmp=crt;
                }
                dp[i+1]=tmp;
                crt+=tmp;
                for(;j<=ncond[i];++j)
                {
                    crt-=dp[j];
                }
            }

            ans*=crt;
        }

        cout << ans << "\n";
    }
};