
    
    




    


















    
    











using ld = long double;
using pii = std::pair<int, int>;
using pll = std::pair<ll, ll>;

const int INF = INT_MAX / 2;
const ll LINF = (ll)2e18 + 666;
const unsigned ll M1 = 4294967291, M2 = 4294967279, M = 1e9 + 7;
const ld EPS = 1e-8;


    const ld M_PI = acos(-1);



using namespace std;


    using namespace __gnu_cxx;
    using namespace __gnu_pbds;

    template<class K, class T, class Cmp = less<K>>
    using ordered_map = tree<K, T, Cmp, rb_tree_tag, tree_order_statistics_node_update>;

    template<class T, class Cmp = less<T>>
    using ordered_set = ordered_map<T, null_type, Cmp>;


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
    
        freopen(FILENAME".in", "r", stdin);
        freopen(FILENAME".out", "w", stdout);
    

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    rnd.seed(random_device{}());
    
    cout << setprecision(11) << fixed;
    
        auto start = clock();
    
    run();
    
        cout << "\ntime = " << (double)(clock() - start) / CLOCKS_PER_SEC << "\n";
    
    return 0;
}



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

    && !is_same<T, rope<char>>::value

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

    && !is_same<T, rope<char>>::value

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








namespace segtree {





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
id4(F &f, Res &res, Args&&... args) {
    f(res, forward<Args>(args)...);
}

template<class F, class Res, class... Args>
inline 
typename enable_if<
    !is_void_v<decltype(declval<F>()(declval<Args>()...))>,
    void
>::type
id4(F &f, Res &res, Args&&... args) {
    res = f(forward<Args>(args)...);
}

template<int priority, class calc_t, class recalc_t, class join_t, class Self>
struct id8 {
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
    id8(Policy policy)
        : calc(select<calc_t>(policy))
        , recalc(select<recalc_t>(policy))
        , join(select<join_t>(policy)) {}
    id8(const id8 &) = default;
    template<class... Args>
    void upd_impl(size_t p, size_t v, size_t l, size_t r, Args&&... args) {
        auto self = static_cast<Self *>(this);
        self->push(v, l, r);
        id4(recalc, self->get_val(self->a[v]), forward<Args>(args)..., l, r);
        if (r - l == 1) {
            id4(calc, self->get_val(self->a[v]), forward<Args>(args)..., l, r);
            return;
        }
        size_t c = (l + r) / 2;
        size_t left = self->get_left(v, l, r);
        size_t right = self->get_right(v, l, r);
        if (p < c)
            upd_impl(p, left, l, c, forward<Args>(args)...);
        else
            upd_impl(p, right, c, r, forward<Args>(args)...);
        id4(
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
struct id7 {
    recalc_t recalc;
    template<class T>
    T get() {
        return recalc;
    }
    id7(recalc_t recalc): recalc(recalc) {}
    template<class Self>
    using type = id8<
        priority,
        DoNothingFunc,
        recalc_t,
        DoNothingFunc,
        Self
    >;
};

template<class join_t, class convert_t, int priority = 0>
struct id3 {
    join_t join;
    convert_t convert;
    template<class T>
    T get() {
        if constexpr (is_same_v<T, join_t>)
            return T(join);
        else
            return T(convert);
    }
    id3(join_t join, convert_t convert): join(join), convert(convert) {}
    template<class Self>
    using type = id8<
        priority,
        convert_t,
        DoNothingFunc,
        join_t,
        Self
    >;
};

template<int priority, class gen_t, class Self>
struct id10 {
    static constexpr int init_priority = priority;
    static constexpr int update_priority = numeric_limits<int>::min();
    void push(size_t, size_t, size_t) {}
    gen_t gen;
    template<class Policy>
    id10(Policy policy): gen(policy.template get<gen_t>()) {}
    void build(size_t v, size_t l, size_t r) {
        auto self = static_cast<Self *>(this);
        if (r - l == 1) {
            self->get_val(self->a[v]) = init(l, r);
        } else {
            size_t c = (l + r) / 2;
            auto left = self->get_left(v, l, r);
            auto right = self->get_right(v, l, r);
            build(left, l, c);
            build(right, c, r);
            self->join(self->get_val(self->a[v]), self->get_val(self->a[left]), self->get_val(self->a[right]));
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
    using type = id10<0, gen_t, Self>;
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
        : public id8<
            -1,
            AssignFunc,
            DoNothingFunc,
            join_t,
            Self
        >
        , public id10<-1, identity_t, Self>
    {
        static constexpr int init_priority = -1;
        static constexpr int update_priority = -1;
        GetPolicy policy;
        type(GetPolicy policy)
            : id8<
                -1,
                AssignFunc,
                DoNothingFunc,
                join_t,
                Self
            >(policy)
            , id10<-1, identity_t, Self>(policy)
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
struct id6 {
    push_t push;
    balance_t balance;
    calc_t calc;
    id6(push_t push, balance_t balance, calc_t calc):
        push(push),
        balance(balance),
        calc(calc) {}
    template<class Self>
    struct type {
        static constexpr int init_priority = numeric_limits<int>::min();
        static constexpr int update_priority = numeric_limits<int>::min();
        id6 policy;
        type(id6 policy): policy(policy) {}
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
        void id2(size_t ql, size_t qr, size_t v, size_t l, size_t r, Args&... args) {
            auto self = static_cast<Self *>(this);
            if (qr <= l || r <= ql)
                return;
            self->push(v, l, r);
            if (ql <= l && r <= qr) {
                policy.calc(self->get_val(self->a[v]), args..., l, r);
                return;
            }
            size_t c = (l + r) / 2;
            id2(ql, qr, self->get_left(v, l, r), l, c, args...);
            id2(ql, qr, self->get_right(v, l, r), c, r, args...);
            auto left = self->get_left(v, l, r);
            auto right = self->get_right(v, l, r);
            self->join(self->get_val(self->a[v]), self->get_val(self->a[left]), self->get_val(self->a[right]));
        }
        template<class... Args>
        void id5(size_t ql, size_t qr, Args&... args) {
            auto self = static_cast<Self *>(this);
            id2(ql, qr, self->get_root(), 0, self->n, args...);
        }
    };
};

struct BaseSegTree {
    void init() {}
    template<class... Args>
    void upd(Args&&...) {}
    DoNothingFunc join;
};


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
        (id4( \
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
SegTree<T, Policies::template type...> id0(size_t n, Policies... policies) {
    return SegTree<T, Policies::template type...>(
        n,
        typename Policies::template type<SegTree<T, Policies::template type...>>(policies)...
    );
}

template<class T, template<class> class... Policies>
struct id9: BaseSegTree, public Policies<id9<T, Policies...>>... {
    struct Node {
        constexpr static unsigned NULL_NODE = numeric_limits<unsigned>::max();
        unsigned left = NULL_NODE, right = NULL_NODE;
        T val;
        Node(T &&val): val(val) {}
    };
    size_t n;
    vector<Node> a;
    id9(size_t n, Policies<id9<T, Policies...>>... policies)
        : Policies<id9<T, Policies...>>(policies)...
        , n(n)
    {}
    T &get_val(Node &node) {
        return node.val;
    }
    size_t get_left(size_t v, size_t l, size_t r) {
        if (a[v].left == Node::NULL_NODE) {
            a[v].left = a.size();
            a.pb(init(l, r));
        }
        return a[v].left;
    }
    size_t get_right(size_t v, size_t l, size_t r) {
        if (a[v].right == Node::NULL_NODE) {
            a[v].right = a.size();
            a.pb(init(l, r));
        }
        return a[v].right;
    }
    size_t get_root() {
        if (a.empty())
            a.pb(init(0, n));
        return 0;
    }
    SEG_TREE_HELPERS(id9)
};

template<class T, class... Policies>
id9<T, Policies::template type...> id1(size_t n, Policies... policies) {
    return id9<T, Policies::template type...>(
        n,
        typename Policies::template type<id9<T, Policies::template type...>>(policies)...
    );
}







};







const int N = 1e5 + 100;

int b[N], mem[N];

void run() {
    int n;
    
        rnd.seed(42);
        cin >> n;
    
        n = 1e5;
    
    for (int i = 0; i < n; ++i) {
        mem[i] = -1;
        
            cin >> b[i];
        
            b[i] = rnd() % (unsigned) (i + 1);
        
        b[i] = i - b[i];
    }
    int q;
    
        cin >> q;
    
        q = 1e5;
    
    while (q--) {
        int t, i;
        
            cin >> t >> i;
        
            t = 1;
            i = n;
        
        --i;
        if (t == 1) {
            int x;
            
                cin >> x;
            
                x = rnd() % (unsigned) (i + 1);
            
            b[i] = i - x;
            memset(mem, -1, (i + 1) * sizeof(mem[0]));
        } else {
            if (mem[i] != -1) {
                cout << mem[i] << "\n";
                continue;
            }
            int ans = b[i];
            for (int j = i + 1; j < n; ++j) {
                ans += (b[j] <= ans);
            }
            mem[i] = ans + 1;
            cout << ans + 1 << "\n";
        }
    }
}
