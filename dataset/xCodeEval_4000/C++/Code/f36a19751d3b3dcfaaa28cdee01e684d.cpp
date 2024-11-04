#ifdef LOCAL
    #define _GLIBCXX_DEBUG
    #define __clock__
#else
    #pragma GCC optimize("Ofast")
    

#endif


#define __precision__ 10
#define iostream_untie true
#define debug_stream std::cerr

#include <algorithm>
#include <bitset>
#include <cassert>
#include <chrono>
#include <complex>
#include <cstring>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>

#define all(v) std::begin(v), std::end(v)
#define rall(v) std::rbegin(v), std::rend(v)
#define odd(n) ((n) & 1)
#define even(n) (not __odd(n))
#define __popcount(n) __builtin_popcountll(n)
#define __clz32(n) __builtin_clz(n)
#define __clz64(n) __builtin_clzll(n)
#define __ctz32(n) __builtin_ctz(n)
#define __ctz64(n) __builtin_ctzll(n)

using i32 = int_least32_t; using i64 = int_least64_t; using u32 = uint_least32_t; using u64 = uint_least64_t;
using pii = std::pair<i32, i32>; using pll = std::pair<i64, i64>;
template <class T> using heap = std::priority_queue<T>;
template <class T> using rheap = std::priority_queue<T, std::vector<T>, std::greater<T>>;
template <class T> using hashset = std::unordered_set<T>;
template <class Key, class Value> using hashmap = std::unordered_map<Key, Value>;

namespace setting
{
    using namespace std::chrono;
    system_clock::time_point start_time, end_time;
    long long get_elapsed_time() { end_time = system_clock::now(); return duration_cast<milliseconds>(end_time - start_time).count(); }
    void print_elapsed_time() { debug_stream << "\n----- Exec time : " << get_elapsed_time() << " ms -----\n"; }
    void buffer_check()
    {
        char bufc;
        if(std::cin >> bufc) debug_stream << "\n\033[1;35mwarning\033[0m: buffer not empty.\n";
    }
    struct setupper
    {
        setupper()
        {
            if(iostream_untie) std::ios::sync_with_stdio(false), std::cin.tie(nullptr);
            std::cout << std::fixed << std::setprecision(__precision__);
    #ifdef stderr_path
            if(freopen(stderr_path, "a", stderr))
            {
                std::cerr << std::fixed << std::setprecision(__precision__);
            }
    #endif
    #ifdef stdout_path
            if(not freopen(stdout_path, "w", stdout))
            {
                freopen("CON", "w", stdout);
                debug_stream << "\n\033[1;35mwarning\033[0m: failed to open stdout file.\n";
            }
            std::cout << "";
    #endif
    #ifdef stdin_path
            if(not freopen(stdin_path, "r", stdin))
            {
                freopen("CON", "r", stdin);
                debug_stream << "\n\033[1;35mwarning\033[0m: failed to open stdin file.\n";
            }
    #endif
    #ifdef LOCAL
            debug_stream << "----- stderr at LOCAL -----\n\n";
            atexit(print_elapsed_time);
    #endif
    #ifdef __buffer_check__
            atexit(buffer_check);
    #endif
    #if defined(__clock__) || defined(LOCAL)
            start_time = system_clock::now();
    #endif
        }
    } __setupper; 

} 

#ifdef __clock__
class
{
    std::chrono::system_clock::time_point built_pt, last_pt; int built_ln, last_ln;
    std::string built_func, last_func; bool is_built = false;
  public:
    void build(int crt_ln, const std::string &crt_func)
    {
        is_built = true, last_pt = built_pt = std::chrono::system_clock::now(),  last_ln = built_ln = crt_ln, last_func = built_func = crt_func;
    }
    void set(int crt_ln, const std::string &crt_func)
    {
        if(is_built) last_pt = std::chrono::system_clock::now(), last_ln = crt_ln, last_func = crt_func;
        else debug_stream << "[ " << crt_ln << " : " << crt_func << " ] " << "myclock_t::set failed (yet to be built!)\n";
    }
    void get(int crt_ln, const std::string &crt_func)
    {
        if(is_built)
        {
            std::chrono::system_clock::time_point crt_pt(std::chrono::system_clock::now());
            long long diff = std::chrono::duration_cast<std::chrono::milliseconds>(crt_pt - last_pt).count();
            debug_stream << diff << " ms elapsed from" << " [ " << last_ln << " : " << last_func << " ]";
            if(last_ln == built_ln) debug_stream << " (when built)";
            debug_stream << " to" << " [ " << crt_ln << " : " << crt_func << " ]" << "\n";
            last_pt = built_pt, last_ln = built_ln, last_func = built_func;
        }
        else
        {
            debug_stream << "[ " << crt_ln << " : " << crt_func << " ] " << "myclock_t::get failed (yet to be built!)\n";
        }
    }
} myclock; 

    #define build_clock() myclock.build(__LINE__, __func__)
    #define set_clock() myclock.set(__LINE__, __func__)
    #define get_clock() myclock.get(__LINE__, __func__)
#else
    #define build_clock() ((void)0)
    #define set_clock() ((void)0)
    #define get_clock() ((void)0)
#endif

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
    template <class tuple_t> struct tupleis<tuple_t, ~0> { static istream &apply(istream &is, tuple_t &t) { return is; } };
    template <class... T> istream &operator>>(istream &is, tuple<T...> &t)  { return tupleis<tuple<T...>, tuple_size<tuple<T...>>::value - 1>::apply(is, t); }
    template <> istream &operator>>(istream &is, tuple<> &t) { return is; }
    template <class tuple_t, size_t index> struct tupleos { static ostream &apply(ostream &os, const tuple_t &t) { tupleos<tuple_t, index - 1>::apply(os, t); return os << ' ' << get<index>(t); } };
    template <class tuple_t> struct tupleos<tuple_t, 0> { static ostream &apply(ostream &os, const tuple_t &t) { return os << get<0>(t); } };
    template <class... T> ostream &operator<<(ostream &os, const tuple<T...> &t)  { return tupleos<tuple<T...>, tuple_size<tuple<T...>>::value - 1>::apply(os, t); }
    template <> ostream &operator<<(ostream &os, const tuple<> &t) { return os; }
    template <class Container, typename Value = typename Container::value_type, enable_if_t<!is_same<decay_t<Container>, string>::value, nullptr_t> = nullptr>
    istream& operator>>(istream& is, Container &cont) { for(auto&& e : cont) is >> e; return is; }
    template <class Container, typename Value = typename Container::value_type, enable_if_t<!is_same<decay_t<Container>, string>::value, nullptr_t> = nullptr>
    ostream& operator<<(ostream& os, const Container &cont) { bool flag = 1; for(auto&& e : cont) flag ? flag = 0 : (os << ' ', 0), os << e; return os; }
} 


#ifdef LOCAL
    #define dump(...)                                                              \
        debug_stream << "[ " << __LINE__ << " : " << __FUNCTION__ << " ]\n",       \
            dump_func(#__VA_ARGS__, __VA_ARGS__)
    template <class T> void dump_func(const char *ptr, const T &x)
    {
        debug_stream << '\t';
        for(char c = *ptr; c != '\0'; c = *++ptr) if(c != ' ') debug_stream << c;
        debug_stream << " : " << x << '\n';
    }
    template <class T, class... rest_t> void dump_func(const char *ptr, const T &x, rest_t... rest)
    {
        debug_stream << '\t';
        for(char c = *ptr; c != ','; c = *++ptr) if(c != ' ') debug_stream << c;
        debug_stream << " : " << x << ",\n"; dump_func(++ptr, rest...);
    }
#else
    #define dump(...) ((void)0)
#endif
template <class P> void read_range(P __first, P __second) { for(P i = __first; i != __second; ++i) std::cin >> *i; }
template <class P> void write_range(P __first, P __second) { for(P i = __first; i != __second; std::cout << (++i == __second ? '\n' : ' ')) std::cout << *i; }



template <class T> inline bool sbmin(T &x, const T &y) { return x > y ? x = y, true : false; }


template <class T> inline bool sbmax(T &x, const T &y) { return x < y ? x = y, true : false; }


i64 bin(const std::function<bool(i64)> &pred, i64 ok, i64 ng)
{
    while(std::abs(ok - ng) > 1) { i64 mid = (ok + ng) / 2; (pred(mid) ? ok : ng) = mid; }
    return ok;
}
double bin(const std::function<bool(double)> &pred, double ok, double ng, const double eps)
{
    while(std::abs(ok - ng) > eps) { double mid = (ok + ng) / 2; (pred(mid) ? ok : ng) = mid; }
    return ok;
}


template <class T, class A, size_t N> void init(A (&array)[N], const T &val) { std::fill((T *)array, (T *)(array + N), val); }


template <class A> void reset(A &array) { memset(array, 0, sizeof(array)); }




#ifndef SEGMENT_TREE_HPP
#define SEGMENT_TREE_HPP
template <class Monoid>
class segment_tree
{
    class uniqueue
    {
        size_t *const que, *qbegin, *qend;
        bool *const inque;
      public:
        uniqueue(size_t n) : que(new size_t[n]), qbegin(que), qend(que), inque(new bool[n]{}) {}
        ~uniqueue() { delete[] que; delete[] inque; }
      	void clear() { qbegin = qend = que; }
        bool empty() const { return qbegin == qend; }
        bool push(size_t x)
        {
            if(inque[x]) return false;
            return inque[*qend++ = x] = true;
        }
        size_t pop()
        {
            const size_t res{*qbegin++};
            inque[res] = false;
          	if(empty()) clear();
            return res;
        }
    }; 


    using value_type = typename Monoid::value_type;
    Monoid monoid;
    const size_t orig_n, ext_n;
    std::vector<value_type> data;
    uniqueue que;

    void rebuild()
    {
        while(!que.empty())
        {
            const size_t f = que.pop(), p = f >> 1;
            if(p && que.push(p)) data[p] = monoid(data[f], data[f ^ 1]);
        }
    }

    void left_bound(size_t idx, const std::function<bool(const value_type &)> &pred,
                    size_t k, size_t l, size_t r, value_type &now, size_t &res)
    {
        if(idx <= l || r < res) return;
        if(r <= idx)
        {
            value_type nxt = monoid(data[k], now);
            if(pred(nxt))
            {
                res = l, now = nxt;
                return;
            }
        }
        if(r - l > 1)
        {
            left_bound(idx, pred, k << 1 ^ 1, (l + r) >> 1, r, now, res);
            left_bound(idx, pred, k << 1, l, (l + r) >> 1, now, res);
        }
    }

    void right_bound(size_t idx, const std::function<bool(const value_type &)> &pred,
                     size_t k, size_t l, size_t r, value_type &now, size_t &res)
    {
        if(idx >= r || l > res) return;
        if(l >= idx)
        {
            value_type nxt = monoid(now, data[k]);
            if(pred(nxt))
            {
                res = r, now = nxt;
                return;
            }
        }
        if(r - l > 1)
        {
            right_bound(idx, pred, k << 1, l, (l + r) >> 1, now, res);
            right_bound(idx, pred, k << 1 ^ 1, (l + r) >> 1, r, now, res);
        }
    }

  public:
    segment_tree(size_t n, Monoid _monoid = Monoid()) : monoid{_monoid}, orig_n{n}, ext_n(n > 1 ? 1 << (32 - __builtin_clz(n - 1)) : 1), data(ext_n << 1, monoid.identity()), que(ext_n << 1) {}

    void build(value_type *__first, value_type *__last)
    {
        std::copy(__first, __last, &data[ext_n]);
        for(size_t i = ext_n; i; --i) data[i] = monoid(data[i * 2], data[i * 2 + 1]);
        que.clear();
    }

    template <class iterator>
    void build(iterator __first, iterator __last)
    {
        static_assert(std::is_same<typename std::iterator_traits<iterator>::value_type, value_type>::value, "iterator's value_type should be equal to Monoid's");
        std::copy(__first, __last, &data[ext_n]);
        for(size_t i = ext_n - 1; i; --i) data[i] = monoid(data[i * 2], data[i * 2 + 1]);
        que.clear();
    }

    value_type fold(size_t l, size_t r)
    {
        rebuild();
        value_type leftval = monoid.identity(), rightval = monoid.identity();
        l += ext_n, r += ext_n;
        while(l < r)
        {
            if(l & 1) leftval = monoid(leftval, data[l++]);
            if(r & 1) rightval = monoid(rightval, data[--r]);
            l >>= 1, r >>= 1;
        }
        return monoid(leftval, rightval);
    }

    value_type &operator[](size_t i) { return que.push(i += ext_n), data[i]; }

    size_t left_bound(size_t i, const std::function<bool(const value_type &)> &pred)
    {
        assert(i <= orig_n), rebuild();
        size_t res = i;
        value_type now = monoid.identity();
        left_bound(i, pred, 1, 0, ext_n, now, res);
        return res;
    }

    size_t right_bound(size_t i, const std::function<bool(const value_type &)> &pred)
    {
        assert(i < orig_n), rebuild();
        size_t res = i;
        value_type now = monoid.identity();
        right_bound(i, pred, 1, 0, ext_n, now, res);
        return res < orig_n ? res : orig_n;
    }
}; 

#endif

#ifndef LAZY_SEGMENT_TREE_HPP
#define LAZY_SEGMENT_TREE_HPP
template <class Monoid, class Actor>
class lazy_segment_tree
{
    using value_type = typename Monoid::value_type;
    using actor_value_type = typename Actor::value_type;
    Monoid monoid; Actor actor;
    const size_t orig_n, ext_n;
    std::vector<value_type> data;
    std::vector<actor_value_type> lazy;
    bool *const flag;

    void eval(size_t k, size_t l, size_t r)
    {
        if(!flag[k]) return;
        actor.act(data[k], lazy[k]);
        if(r - l > 1)
        {
            actor(lazy[k * 2], lazy[k]);
            actor(lazy[k * 2 + 1], lazy[k]);
            flag[k * 2] = flag[k * 2 + 1] = true;
        }
        lazy[k] = actor.identity(), flag[k] = false;
    }

    void update(size_t a, size_t b, const actor_value_type &x, size_t k, size_t l, size_t r)
    {
        eval(k, l, r);
        if(b <= l || r <= a) return;
        if(a <= l && r <= b)
        {
            actor(lazy[k], x);
            flag[k] = true;
            eval(k, l, r);
        }
        else
        {
            update(a, b, x, k * 2, l, (l + r) >> 1);
            update(a, b, x, k * 2 + 1, (l + r) >> 1, r);
            data[k] = monoid(data[k * 2], data[k * 2 + 1]);
        }
    }

    value_type fold(size_t a, size_t b, size_t k, size_t l, size_t r)
    {
        if(b <= l || r <= a) return monoid.identity();
        eval(k, l, r);
        if(a <= l && r <= b) return data[k];
        return monoid(fold(a, b, k * 2, l, (l + r) >> 1), fold(a, b, k * 2 + 1, (l + r) >> 1, r));
    }

    void left_bound(size_t idx, const std::function<bool(const value_type &)> &pred,
                    size_t k, size_t l, size_t r, value_type &now, size_t &res)
    {
        if(idx <= l || r < res) return;
        eval(k, l, r);
        if(r <= idx)
        {
            value_type nxt = monoid(data[k], now);
            if(pred(nxt))
            {
                res = l, now = nxt;
                return;
            }
        }
        if(r - l > 1)
        {
            left_bound(idx, pred, k << 1 ^ 1, (l + r) >> 1, r, now, res);
            left_bound(idx, pred, k << 1, l, (l + r) >> 1, now, res);
        }
    }

    void right_bound(size_t idx, const std::function<bool(const value_type &)> &pred,
                     size_t k, size_t l, size_t r, value_type &now, size_t &res)
    {
        if(idx >= r || l > res) return;
        eval(k, l, r);
        if(l >= idx)
        {
            value_type nxt = monoid(now, data[k]);
            if(pred(nxt))
            {
                res = r, now = nxt;
                return;
            }
        }
        if(r - l > 1)
        {
            right_bound(idx, pred, k << 1, l, (l + r) >> 1, now, res);
            right_bound(idx, pred, k << 1 ^ 1, (l + r) >> 1, r, now, res);
        }
    }

  public:
    lazy_segment_tree(size_t n, Monoid _monoid = Monoid(), Actor _actor = Actor())
        : monoid{_monoid}, actor(_actor), orig_n{n}, ext_n(n > 1 ? 1 << (32 - __builtin_clz(n - 1)) : 1),
          data(ext_n << 1, monoid.identity()), lazy(ext_n << 1, actor.identity()), flag(new bool[ext_n << 1])
    {}
    ~lazy_segment_tree() { delete[] flag; }

    value_type operator[](size_t i) { return fold(i, i + 1); }

    void build(value_type *__first, value_type *__last)
    {
        std::copy(__first, __last, &data[ext_n]);
        for(size_t i = ext_n; i; --i) data[i] = monoid(data[i * 2], data[i * 2 + 1]);
    }

    template <class iterator>
    void build(iterator __first, iterator __last)
    {
        static_assert(std::is_same<typename std::iterator_traits<iterator>::value_type, value_type>::value, "iterator's value_type should be equal to Monoid's");
        std::copy(__first, __last, &data[ext_n]);
        for(size_t i = ext_n - 1; i; --i) data[i] = monoid(data[i * 2], data[i * 2 + 1]);
    }

    void init(const value_type &x)
    {
        for(size_t i = 0; i < ext_n; ++i) data[i + ext_n] = x;
        for(size_t i = ext_n - 1; i; --i) data[i] = monoid(data[i * 2], data[i * 2 + 1]);
    }

    void update(size_t a, const actor_value_type &x) { update(a, a + 1, x); }

    void update(size_t a, size_t b, const actor_value_type &x) { update(a, b, x, 1, 0, ext_n); }

    value_type fold(size_t a, size_t b) { return fold(a, b, 1, 0, ext_n); }

    size_t left_bound(size_t i, const std::function<bool(const value_type &)> &pred)
    {
        assert(i <= orig_n);
        size_t res = i;
        value_type now = monoid.identity();
        left_bound(i, pred, 1, 0, ext_n, now, res);
        return res;
    }

    size_t right_bound(size_t i, const std::function<bool(const value_type &)> &pred)
    {
        assert(i < orig_n);
        size_t res = i;
        value_type now = monoid.identity();
        right_bound(i, pred, 1, 0, ext_n, now, res);
        return res < orig_n ? res : orig_n;
    }
}; 

#endif

template <class T>
struct plus_monoid
{
    using value_type = T;
    T identity()
    {
        return T(0);
    }
    T operator()(const T &x, const T &y)
    {
        return x+y;
    }
};

template <class T>
struct plus_len_monoid
{
    struct value_type
    {
        size_t len;
        T val;
    };
    value_type identity()
    {
        return {0,0};
    }
    value_type operator()(const value_type &x, const value_type &y)
    {
        return {x.len + y.len, x.val + y.val};
    }
};

struct acv
{
    bool flag;
    i64 v;
};

struct actor
{
    using value_type = acv;
    value_type identity()
    {
        return acv{true,0};
    }
    void operator()(value_type &x, const value_type &y)
    {
        x.flag&=y.flag;
        x.v+=y.v;
    }
    template <class other>
    void act(other &x, const value_type &y)
    {
        if(y.flag)
        {
            x.val+=y.v*x.len;
        }
        else
        {
            x.val=0;
            x.len=0;
        }
    }
};

using namespace std;

struct solver
{
    solver()
    {
        int n; cin>>n;
        vector<int> pos(n);
        for(int i=0; i<n; ++i)
        {
            int a; cin>>a; --a; pos[a]=i;
        }

        lazy_segment_tree<plus_len_monoid<i64>,actor> lseg(n),rseg(n);

        segment_tree<plus_monoid<i64>> seg1(n);

        int l=n,r=0;
        i64 flip=0;

        {
            vector<plus_len_monoid<i64>::value_type> init(n,{1,0});
            lseg.build(all(init));
            rseg.build(all(init));
        }

        int now=1;
        for(int i: pos)
        {
            sbmin(l,i);
            sbmax(r,i);

            flip+=seg1.fold(i,n);
            seg1[i]=1;

            i64 ans=flip;

            lseg.update(i,{0,0});
            rseg.update(i,{0,0});

            lseg.update(i,n,{1,1});
            rseg.update(0,i,{1,1});

            auto f=[&](i64 x)->bool
            {
                return x*2<=now;
            };
            int mid=seg1.right_bound(l,f);
            dump(i,mid);

            ans+=lseg.fold(l,mid).val;
            ans+=rseg.fold(mid,r+1).val;
            cout << ans << " ";
            now++;
        }
        cout << "\n";
    }
};

main()
{
    u32 t = 1;
#ifdef LOCAL

#endif
    

    

    while(t--) solver();
}