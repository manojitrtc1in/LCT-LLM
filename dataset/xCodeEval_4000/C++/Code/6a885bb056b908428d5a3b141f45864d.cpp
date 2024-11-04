#ifdef LOCAL
    #define _GLIBCXX_DEBUG
    #define _GLIBCXX_DEBUG_PEDANTIC
#endif


#ifndef LOCAL
    #pragma GCC optimize("Ofast")
#endif
#pragma GCC target("avx2")




#pragma GCC target("bmi2")
#pragma GCC target("popcnt")
#include <bits/stdc++.h>
#include <immintrin.h>
#ifdef IACA
#include <iacaMarks.h>
#else
#define IACA_START
#define IACA_END
#endif


#ifndef NOGNU
    #include <ext/rope>
    #include <ext/pb_ds/assoc_container.hpp>
#endif 

#define lambda(body, ...) [&](__VA_ARGS__) { return body; }
#define vlambda(body, ...) lambda(body, __VA_ARGS__, auto&&...)
#define all(x) (x).begin(), (x).end()
#define F first
#define S second
#define eb emplace_back
#define unires(x) x.resize(unique(all(x)) - x.begin())
#define ll long long

using ld = long double;
using pii = std::pair<int, int>;
using pll = std::pair<ll, ll>;

const int INF = INT_MAX / 2;
const ll LINF = (ll)2e18 + 666;
const unsigned ll M1 = 4294967291, M2 = 4294967279, M = 998244353;
const ld EPS = 1e-8;

#ifndef M_PI
    const ld M_PI = acos(-1);
#endif 


using namespace std;

#ifndef NOGNU
    using namespace __gnu_cxx;
    using namespace __gnu_pbds;

    template<class K, class T, class Cmp = less<K>>
    using ordered_map = tree<K, T, Cmp, rb_tree_tag, tree_order_statistics_node_update>;

    template<class T, class Cmp = less<T>>
    using ordered_set = ordered_map<T, null_type, Cmp>;
#endif

void run();

template<class T1, class T2>
inline bool mini(T1 &a, T2 b) {
    if (a > b) {
        a = b;
        return 1;
    }
    return 0;
}

template<class T1, class T2>
inline bool maxi(T1 &a, T2 b) {
    if (a < b) {
        a = b;
        return 1;
    }
    return 0;
}

mt19937 rnd(0);

signed main() {
    #if defined FILENAME && !defined STDIO && !defined LOCAL
        freopen(FILENAME".in", "r", stdin);
        freopen(FILENAME".out", "w", stdout);
    #endif 

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #ifndef LOCAL
    rnd.seed(random_device{}());
    #endif
    cout << setprecision(11) << fixed;
    #ifdef PRINTTIME
        auto start = clock();
    #endif
    run();
    #ifdef PRINTTIME
        cout << "\ntime = " << (double)(clock() - start) / CLOCKS_PER_SEC << "\n";
    #endif
    return 0;
}

#define rand rnd

template<class T = uint64_t, T Mod = M>
struct mod {
    T operator()(T x, T y) {
        return x * y % Mod;
    }
};

template<class T, T Mod>
inline T identity_element(mod<T, Mod>) {
    return T(1);
}

template<class T>
struct is_continer {
 private:
    static void detect(...);
    template<class U>
    static decltype(declval<U>().begin()) detect(const U&);
 public:
    static const bool value = !is_same<decltype(detect(declval<T>())), void>::value;
};

template<class T>
struct is_std_array {
    static const bool value = 0;
};

template<class T, size_t sz>
struct is_std_array<array<T, sz>> {
    static const bool value = 1;
};

template<class T>
struct is_tuple_like {
 private:
    static void detect(...);
    template<class U>
    static typename enable_if<(bool) tuple_size<U>::value, int>::type detect(const U&);
 public:
    static const bool value = !is_same<decltype(detect(declval<T>())), void>::value;
};

template<class T>
typename enable_if<is_continer<T>::value && !is_same<T, string>::value
#ifndef NOGNU
    && !is_same<T, rope<char>>::value
#endif
, ostream>::type&
operator<<(ostream &out, const T &arr) {
    bool first = 1;
    for (const auto &x : arr) {
        if (!first) {
            if constexpr (
                (is_continer<typename T::value_type>::value && !is_same<typename T::value_type, string>::value)
                || is_tuple_like<typename T::value_type>::value) {
                out << '\n';
            } else {
                out << ' ';
            }
        } else {
            first = 0;
        }
        out << x;
    }
    return out;
}

template<class T>
typename enable_if<is_continer<T>::value && !is_same<T, string>::value
#ifndef NOGNU
    && !is_same<T, rope<char>>::value
#endif
, istream>::type&
operator>>(istream &in, T &arr) {
    for (auto &x : arr)
        in >> x;
    return in;
}

template<class T, size_t pos>
void read_tuple(istream &in, T &x) {
    if constexpr (pos == tuple_size<T>::value)
        return;
    else {
        in >> get<pos>(x);
        read_tuple<T, pos + 1>(in, x);
    }
}

template<class T, size_t pos = 0>
typename enable_if<is_tuple_like<T>::value && !is_std_array<T>::value, istream>::type&
operator>>(istream &in, T &x) {
    read_tuple<T, 0>(in, x);
    return in;
}

template<class T, size_t pos>
void write_tuple(ostream &out, const T &x) {
    if constexpr (pos == tuple_size<T>::value)
        return;
    else {
        if constexpr (pos != 0)
            out << " ";
        out << get<pos>(x);
        write_tuple<T, pos + 1>(out, x);
    }
}

template<class T>
typename enable_if<is_tuple_like<T>::value && !is_std_array<T>::value, ostream>::type&
operator<<(ostream &out, const T &x) {
    write_tuple<T, 0>(out, x);
    return out;
}

template<class T>
T input() {
    T x;
    cin >> x;
    return x;
}



#if !defined NODEBUG && defined LOCAL

template<class T>
void debug(const T &x) {
    cout << x << endl;
}

template<class T, class... Args>
void debug(const T &x, const Args & ...args) {
    cout << x << " ";
    debug(args...);
}

template<class T>
void debugs(const T &x) {
    cout << x << " ";
}

template<class T, class... Args>
void debugs(const T &x, const Args & ...args) {
    cout << x << " ";
    debugs(args...);
}

#else
#define debug(...)
#define debugs(...)
#endif

#define named(x) #x, "=", x

namespace segtree {

#ifdef LOCAL
#pragma GCC diagnostic ignored "-Winaccessible-base"
#endif

struct DoNothingFunc {
    template<class... Args>
    void operator()(Args&&... args) const {}
};

struct AssignFunc {
    template<class T, class U, class... Args>
    void operator()(T &x, U &&y, Args&...) const {
        x = forward<U>(y);
    }
};

template<class F, class Res, class... Args>
inline 
typename enable_if<
    is_void_v<decltype(declval<F>()(declval<Res&>(), declval<Args>()...))>,
    void
>::type
assign_or_call(F &f, Res &res, Args&&... args) {
    f(res, forward<Args>(args)...);
}

template<class F, class Res, class... Args>
inline 
typename enable_if<
    !is_void_v<decltype(declval<F>()(declval<Args>()...))>,
    void
>::type
assign_or_call(F &f, Res &res, Args&&... args) {
    res = f(forward<Args>(args)...);
}

template<int priority, class calc_t, class recalc_t, class join_t, class Self>
struct PointUpdatePolicyType {
    static constexpr int update_priority = priority;
    static constexpr int init_priority = numeric_limits<int>::min();
    calc_t calc;
    recalc_t recalc;
    join_t join;
    template<class F, class Policy>
    static auto select(Policy policy) {
        if constexpr (is_default_constructible<F>::value)
            return F();
        else
            return policy.template get<F>();
    }
    template<class Policy>
    PointUpdatePolicyType(Policy policy)
        : calc(select<calc_t>(policy))
        , recalc(select<recalc_t>(policy))
        , join(select<join_t>(policy)) {}
    PointUpdatePolicyType(const PointUpdatePolicyType &) = default;
    template<class... Args>
    void upd_impl(size_t p, size_t v, size_t l, size_t r, Args&&... args) {
        auto self = static_cast<Self *>(this);
        self->push(v, l, r);
        assign_or_call(recalc, self->get_val(self->a[v]), forward<Args>(args)..., l, r);
        if (r - l == 1) {
            assign_or_call(calc, self->get_val(self->a[v]), forward<Args>(args)..., l, r);
            return;
        }
        size_t c = (l + r) / 2;
        size_t left = self->get_left(v, l, r);
        size_t right = self->get_right(v, l, r);
        if (p < c)
            upd_impl(p, left, l, c, forward<Args>(args)...);
        else
            upd_impl(p, right, c, r, forward<Args>(args)...);
        assign_or_call(
            join,
            self->get_val(self->a[v]),
            self->get_val(self->a[left]),
            self->get_val(self->a[right]),
            forward<Args>(args)...,
            l, r
        );
    }
    template<class... Args>
    void upd(size_t p, Args&&... args) {
        auto self = static_cast<Self *>(this);
        upd_impl(p, self->get_root(), 0, self->n, forward<Args>(args)...);
    }
    void push(size_t, size_t, size_t) {}
};

template<class recalc_t, int priority = 0>
struct PathUpdatePolicy {
    recalc_t recalc;
    template<class T>
    T get() {
        return recalc;
    }
    PathUpdatePolicy(recalc_t recalc): recalc(recalc) {}
    template<class Self>
    using type = PointUpdatePolicyType<
        priority,
        DoNothingFunc,
        recalc_t,
        DoNothingFunc,
        Self
    >;
};

template<class join_t, class convert_t, int priority = 0>
struct JoinUpdatePolicy {
    join_t join;
    convert_t convert;
    template<class T>
    T get() {
        if constexpr (is_same_v<T, join_t>)
            return T(join);
        else
            return T(convert);
    }
    JoinUpdatePolicy(join_t join, convert_t convert): join(join), convert(convert) {}
    template<class Self>
    using type = PointUpdatePolicyType<
        priority,
        convert_t,
        DoNothingFunc,
        join_t,
        Self
    >;
};

template<int priority, class gen_t, class Self>
struct SegTreeInitType {
    static constexpr int init_priority = priority;
    static constexpr int update_priority = numeric_limits<int>::min();
    void push(size_t, size_t, size_t) {}
    gen_t gen;
    template<class Policy>
    SegTreeInitType(Policy policy): gen(policy.template get<gen_t>()) {}
    void build(size_t v, size_t l, size_t r) {
        auto self = static_cast<Self *>(this);
        if constexpr (is_invocable_v<gen_t, size_t, size_t>) {
            self->get_val(self->a[v]) = init(l, r);
        }
        if (r - l == 1) {
            if constexpr (!is_invocable_v<gen_t, size_t, size_t>) {
                self->get_val(self->a[v]) = gen(l);
            }
        } else {
            size_t c = (l + r) / 2;
            auto left = self->get_left(v, l, r);
            auto right = self->get_right(v, l, r);
            build(left, l, c);
            build(right, c, r);
            if constexpr (!is_invocable_v<gen_t, size_t, size_t>) {
                self->join(
                    self->get_val(self->a[v]), self->get_val(self->a[left]),
                    self->get_val(self->a[right])
                );
            }
        }
    }
    void init() {
        auto self = static_cast<Self *>(this);
        build(self->get_root(), 0, self->n);
    }
    auto init(size_t l, size_t r) {
        if constexpr (is_invocable_v<gen_t, size_t, size_t>)
            return gen(l, r);
        else
            return gen();
    }
};

template<class gen_t>
struct InitPolicy {
    gen_t gen;
    InitPolicy(gen_t gen): gen(gen) {}
    template<class T>
    T get() {
        return gen;
    }
    template<class Self>
    using type = SegTreeInitType<0, gen_t, Self>;
};

struct IdentityFunc {
    template<class T, class... Args>
    const T &operator()(const T &x, Args&...) {
        return x;
    }
};

template<class join_t, class identity_t, class convert_t = IdentityFunc>
struct GetPolicy {
    join_t join;
    identity_t identity;
    convert_t convert;
    template<class T>
    T get() {
        if constexpr (is_same_v<T, join_t>)
            return join;
        else if constexpr (is_same_v<T, identity_t>)
            return identity;
    }
    GetPolicy(join_t join, identity_t identity, convert_t convert = convert_t()):
        join(join),
        identity(identity),
        convert(convert) {}
    template<class Self>
    struct type
        : public PointUpdatePolicyType<
            -1,
            AssignFunc,
            DoNothingFunc,
            join_t,
            Self
        >
        , public SegTreeInitType<-1, identity_t, Self>
    {
        static constexpr int init_priority = -1;
        static constexpr int update_priority = -1;
        GetPolicy policy;
        type(GetPolicy policy)
            : PointUpdatePolicyType<
                -1,
                AssignFunc,
                DoNothingFunc,
                join_t,
                Self
            >(policy)
            , SegTreeInitType<-1, identity_t, Self>(policy)
            , policy(policy) {}
        template<class... Args>
        auto get_impl(size_t ql, size_t qr, size_t v, size_t l, size_t r, const Args&... args) {
            auto self = static_cast<Self *>(this);
            if (qr <= l || r <= ql)
                return policy.identity(args..., l, r);
            self->push(v, l, r);
            if (ql <= l && r <= qr)
                return policy.convert(self->get_val(self->a[v]), args..., l, r);
            size_t c = (l + r) / 2;
            return policy.join(
                get_impl(ql, qr, self->get_left(v, l, r), l, c, args...),
                get_impl(ql, qr, self->get_right(v, l, r), c, r, args...),
                args..., l, r
            );
        }
        template<class... Args>
        auto get(size_t ql, size_t qr, const Args&... args) {
            auto self = static_cast<Self *>(this);
            return get_impl(ql, qr, self->get_root(), 0, self->n, args...);
        }
        void push(size_t, size_t, size_t) {}
    };
};

template<class push_t, class balance_t, class calc_t>
struct MassUpdatePolicy {
    push_t push;
    balance_t balance;
    calc_t calc;
    MassUpdatePolicy(push_t push, balance_t balance, calc_t calc):
        push(push),
        balance(balance),
        calc(calc) {}
    template<class Self>
    struct type {
        static constexpr int init_priority = numeric_limits<int>::min();
        static constexpr int update_priority = numeric_limits<int>::min();
        MassUpdatePolicy policy;
        type(MassUpdatePolicy policy): policy(policy) {}
        void push(size_t v, size_t l, size_t r) {
            auto self = static_cast<Self *>(this);
            if (r - l != 1) {
                auto left = self->get_left(v, l, r);
                auto right = self->get_right(v, l, r);
                size_t c = (l + r) / 2;
                policy.push(self->get_val(self->a[left]), l, c, self->get_val(self->a[v]), l, r);
                policy.push(self->get_val(self->a[right]), c, r, self->get_val(self->a[v]), l, r);
            }
            policy.balance(self->get_val(self->a[v]), l, r);
        }
        template<class... Args>
        void mass_upd_impl(size_t ql, size_t qr, size_t v, size_t l, size_t r, Args&... args) {
            auto self = static_cast<Self *>(this);
            if (qr <= l || r <= ql)
                return;
            self->push(v, l, r);
            if (ql <= l && r <= qr) {
                policy.calc(self->get_val(self->a[v]), args..., l, r);
                return;
            }
            size_t c = (l + r) / 2;
            mass_upd_impl(ql, qr, self->get_left(v, l, r), l, c, args...);
            mass_upd_impl(ql, qr, self->get_right(v, l, r), c, r, args...);
            auto left = self->get_left(v, l, r);
            auto right = self->get_right(v, l, r);
            self->join(self->get_val(self->a[v]), self->get_val(self->a[left]), self->get_val(self->a[right]));
        }
        template<class... Args>
        void mass_upd(size_t ql, size_t qr, Args&... args) {
            auto self = static_cast<Self *>(this);
            mass_upd_impl(ql, qr, self->get_root(), 0, self->n, args...);
        }
    };
};

struct BaseSegTree {
    void init() {}
    template<class... Args>
    void upd(Args&&...) {}
    DoNothingFunc join;
};

#define SEG_TREE_HELPERS(SegTree) \
    void push(size_t v, size_t l, size_t r) { \
        (Policies<SegTree<T, Policies...>>::push(v, l, r), ...); \
    } \
    template<class... Args> \
    void upd(size_t p, Args&&... args) { \
        constexpr int max_prior = max({Policies<SegTree<T, Policies...>>::update_priority...}); \
        auto select = []<class X>(X x) { \
            if constexpr (X::update_priority >= max_prior) { \
                return x; \
            } else { \
                return BaseSegTree(); \
            } \
        }; \
        (decltype(select(declval<Policies<SegTree<T, Policies...>>>()))::upd(p, forward<Args>(args)...), ...); \
    } \
    template<class P> \
    typename P::template type<SegTree<T, Policies...>> &as(const P&) { \
        return static_cast<typename P::template type<SegTree<T, Policies...>> &>(*this); \
    } \
    void join(T &res, const T &a, const T &b, auto&... args) { \
        constexpr auto max_prior = max({Policies<SegTree<T, Policies...>>::update_priority...}); \
        auto select = []<class X>(X x) { \
            if constexpr (X::update_priority >= max_prior) { \
                return x; \
            } else { \
                return BaseSegTree(); \
            } \
        }; \
        (assign_or_call( \
            static_cast<decltype(select(declval<Policies<SegTree<T, Policies...>>>())) *>(this)->join, \
            res, a, b, args... \
        ), ...); \
    } \
    auto init(size_t l, size_t r) { \
        constexpr int max_prior = max({Policies<SegTree<T, Policies...>>::init_priority...}); \
        auto select = []<class X, class... Args>(auto select, X x, Args... args) { \
            if constexpr (X::init_priority >= max_prior) { \
                return x; \
            } else { \
                return select(select, args...); \
            } \
        }; \
        return decltype(select(select, declval<Policies<SegTree<T, Policies...>>>()...))::init(l, r); \
    } \

template<class T, template<class> class... Policies>
struct SegTree: BaseSegTree, public Policies<SegTree<T, Policies...>>... {
    size_t n;
    vector<T> a;
    SegTree(size_t n, Policies<SegTree<T, Policies...>>... policies)
        : Policies<SegTree<T, Policies...>>(policies)...
        , n(n)
        , a(n * 4)
    {
        constexpr int max_prior = max({Policies<SegTree<T, Policies...>>::init_priority...});
        auto select = []<class X>(X x) {
            if constexpr (X::init_priority >= max_prior) {
                return x;
            } else {
                return BaseSegTree();
            }
        };
        (decltype(select(policies))::init(), ...);
    }
    T &get_val(T &x) {
        return x;
    }
    size_t get_left(size_t v, size_t, size_t) const {
        return v * 2 + 1;
    }
    size_t get_right(size_t v, size_t, size_t) const {
        return v * 2 + 2;
    }
    size_t get_root() const {
        return 0;
    }
    SEG_TREE_HELPERS(SegTree)
};

template<class T, class... Policies>
SegTree<T, Policies::template type...> make_segtree(size_t n, Policies... policies) {
    return SegTree<T, Policies::template type...>(
        n,
        typename Policies::template type<SegTree<T, Policies::template type...>>(policies)...
    );
}

template<class T, template<class> class... Policies>
struct LazySegTree: BaseSegTree, public Policies<LazySegTree<T, Policies...>>... {
    struct Node {
        constexpr static unsigned NULL_NODE = numeric_limits<unsigned>::max();
        unsigned left = NULL_NODE, right = NULL_NODE;
        T val;
        Node(T &&val): val(val) {}
    };
    size_t n;
    vector<Node> a;
    LazySegTree(size_t n, Policies<LazySegTree<T, Policies...>>... policies)
        : Policies<LazySegTree<T, Policies...>>(policies)...
        , n(n)
    {}
    T &get_val(Node &node) {
        return node.val;
    }
    size_t get_left(size_t v, size_t l, size_t r) {
        if (a[v].left == Node::NULL_NODE) {
            a[v].left = a.size();
            a.eb(init(l, r));
        }
        return a[v].left;
    }
    size_t get_right(size_t v, size_t l, size_t r) {
        if (a[v].right == Node::NULL_NODE) {
            a[v].right = a.size();
            a.eb(init(l, r));
        }
        return a[v].right;
    }
    size_t get_root() {
        if (a.empty())
            a.eb(init(0, n));
        return 0;
    }
    SEG_TREE_HELPERS(LazySegTree)
};

template<class T, class... Policies>
LazySegTree<T, Policies::template type...> make_lazy_segtree(size_t n, Policies... policies) {
    return LazySegTree<T, Policies::template type...>(
        n,
        typename Policies::template type<LazySegTree<T, Policies::template type...>>(policies)...
    );
}

#undef SEG_TREE_HELPERS

#ifdef LOCAL
#pragma GCC diagnostic pop
#endif

};







vector<int> coloring(int n) {
    if (n == 1) {
        return {0, 0};
    } else {
        auto sub = coloring(n >> 1);
        vector<int> ans(1 << n);
        int sz = 1 << (n >> 1);
        for (int i = 0; i < 1 << n; ++i) {
            int cn = i >> (n >> 1);
            ans[i] = (sub[i & (sz - 1)] + sub[cn]) & ((n >> 1) - 1);
            if (__builtin_popcount(cn) & 1)
                ans[i] += n >> 1;
        }
        return ans;
    }
}

void run() {
    #ifdef LOCAL
    for (int n = 1; n <= 16; n *= 2) {
        auto c = coloring(n);
        debug(named(n));
        for (int i = 0; i < 1 << n; ++i) {
            map<int, int> u;
            for (int j = 0; j < n; ++j) {
                u[c[i ^ (1 << j)]]++;
            }
            if ((int) u.size() != n) {
                debug(c);
                debug(i);
                debug(u);
                assert(0);
            }
        }
    }
    #endif
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> g(1 << n);
        for (auto &v : g) {
            v.reserve(n);
        }
        for (int i = 0; i < n * (1 << n - 1); ++i) {
            int a, b;
            cin >> a >> b;
            g[a].eb(b);
            g[b].eb(a);
        }
        vector<int> q, p(1 << n), c(1 << n, -1);
        c[0] = 0;
        p[0] = 0;
        for (int i = 0; i < n; ++i) {
            c[g[0][i]] = 1 << i;
            p[1 << i] = g[0][i];
            q.eb(g[0][i]);
        }
        size_t cur = 0;
        while (cur < q.size()) {
            auto v = q[cur++];
            for (auto x : g[v]) {
                if (c[x] > -1) {
                    c[v] |= c[x];
                } else {
                    c[x] = 0;
                    q.eb(x);
                }
            }
            p[c[v]] = v;
        }
        cout << p << "\n";
        if (n & (n - 1)) {
            cout << "-1\n";
        } else {
            auto col = coloring(n);
            for (auto x : c) {
                cout << col[x] << " ";
            }
            cout << "\n";
        }
    }
}
