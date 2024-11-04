#include <bits/stdc++.h>
#define all(x) (x).begin(),(x).end()
#define isz(x) (int)(x).size()
using ll = long long;
using vi = std::vector<int>;
const ll INF = (ll)1e18L;

namespace SegmentTreeLazy {
    
    
    
    
    template<typename Value, typename Extra>
    struct TraitsMinAdd {
        

        static Value valueNeutral() { return std::numeric_limits<Value>::max(); }
        

        static Extra extraNeutral() { return Extra(0); }
        

        template<typename Node>
        static Value getValue(const Node& src) {
            return src.value() + src.extra();
        }
        

        template<typename NodeRoot, typename NodeLt, typename NodeRt>
        static void pull(NodeRoot root, const NodeLt& lt, const NodeRt& rt) {
            root.value() = std::min(getValue(lt), getValue(rt));
        }
        

        template<typename NodeDst, typename NodeSrc>
        static void push(NodeDst dst, const NodeSrc& src) {
            dst.extra() += src.extra();
        }
    };
    
    
    template<typename Value, typename Extra>  struct TraitsMaxAdd;
    
    
    template<typename Value = int64_t, typename Extra = int64_t, typename Traits = TraitsMinAdd<Value, Extra> >
    struct SegmentTree {
        
        
        struct Node {
            Value value;
            
            Extra extra;
            
            Node(Value value_ = Traits::valueNeutral(), Extra extra_ = Traits::extraNeutral())
                : value(value_), extra(extra_) { }
            
            Value getValue(int l, int r) const { return Traits::getValue(NodeWrapper<Node>(l, r, *this)); }
        };
        
        
        template<typename NodeType>
        struct NodeWrapper {
            int l, r;
            NodeType node;
            NodeWrapper(int l_, int r_, NodeType node_)
                : l(l_), r(r_), node(node_) { }
            int  left() const { return l; }
            int right() const { return r; }
            int   mid() const { return (l+r)/2; }
            int   len() const { return r - l + 1; }
            Value& value() { return node.value; }
            Extra& extra() { return node.extra; }
            const Value& value() const { return node.value; }
            const Extra& extra() const { return node.extra; }
        };
        
        
        int n; std::vector<Node> data;
        
        
        
        void resize(int n_) {
            n = n_;
            data.assign(2 * n - 1, Node());
        }
        
        
        void push(int v, int l, int r, int m) {
            if (data[v].extra != Traits::extraNeutral()) {
                Traits::push(
                    NodeWrapper<Node&>(l, m, data[v+1]), 
                    NodeWrapper<const Node&>(l, r, data[v])
                );
                Traits::push(
                    NodeWrapper<Node&>(m+1, r, data[v+2*(m-l+1)]), 
                    NodeWrapper<const Node&>(  l, r, data[v])
                );
                data[v].extra = Traits::extraNeutral();
            }
        }
        
        
        void pull(int v, int l, int r, int m) {
            assert(data[v].extra == Traits::extraNeutral());
            Traits::pull(
                NodeWrapper<Node&>(  l, r, data[v]), 
                NodeWrapper<const Node&>(  l, m, data[v+1]), 
                NodeWrapper<const Node&>(m+1, r, data[v+2*(m-l+1)])
            );
        }
        
        
        template<typename T>
        void build(const std::vector<T>& arr, const int v, const int tl, const int tr) {
            if (tl == tr) {
                data[v] = Node(arr[tl]);
            } else {
                const int tm = (tl + tr) / 2;
                build(arr, v+1,   tl, tm);
                build(arr, v+2*(tm-tl+1), tm+1, tr);
                pull(v, tl, tr, tm);
            }
        }
        
        template<typename T>
        void build(const std::vector<T>& arr) { 
            resize((int)arr.size());
            build(arr, 0, 0, n-1);
        }

        
        Node get(int ql, int qr, const int v, const int tl, const int tr) {
            if (ql == tl && qr == tr) {
                return data[v];
            } else {
                int tm = (tl + tr) / 2;
                push(v, tl, tr, tm);
                Node ret;
                if (qr <= tm) {
                    ret = get(ql, qr, v+1,   tl, tm);
                } else if (ql > tm) {
                    ret = get(ql, qr, v+2*(tm-tl+1), tm+1, tr);
                } else {
                    const auto lt = get(  ql, tm, v+1,   tl, tm);
                    const auto rt = get(tm+1, qr, v+2*(tm-tl+1), tm+1, tr);
                    Traits::pull(
                        NodeWrapper<Node&>(  ql, qr, ret), 
                        NodeWrapper<const Node&>(  ql, tm, lt), 
                        NodeWrapper<const Node&>(tm+1, qr, rt)
                    );
                }
                pull(v, tl, tr, tm);
                return ret;
            }
        }
        
        Value get(const int ql, const int qr) { return get(ql, qr, 0, 0, n-1).getValue(ql, qr); }
        
        
        void update(const int ql, const int qr, const Extra& extra, const int v, const int tl, const int tr) {
            if (ql == tl && tr == qr) {
                Traits::push(
                    NodeWrapper<Node&>(tl, tr, data[v]),
                    NodeWrapper<Node>(ql, qr, Node(Traits::valueNeutral(), extra))
                );
            } else {
                int tm = (tl + tr) / 2;
                push(v, tl, tr, tm);
                if (qr <= tm) {
                    update(ql, qr, extra, v+1, tl, tm);
                } else if (ql > tm) {
                    update(ql, qr, extra, v+2*(tm-tl+1),tm+1,tr);
                } else {
                    update(ql, tm, extra, v+1,   tl, tm);
                    update(tm+1, qr, extra, v+2*(tm-tl+1), tm+1, tr);
                }
                pull(v, tl, tr, tm);
            }
        }

        void update(const int ql, const int qr, const Extra& extra) {
            update(ql, qr, extra, 0, 0, n-1); 
        }

    };
    
    
    template<typename Value, typename Extra>
    struct TraitsMaxAdd {
        

        static Value valueNeutral() { return std::numeric_limits<Value>::min(); }
        

        static Extra extraNeutral() { return Extra(0); }
        

        template<typename Node>
        static Value getValue(const Node& src) {
            return src.value() + src.extra();
        }
        

        template<typename NodeRoot, typename NodeLt, typename NodeRt>
        static void pull(NodeRoot root, const NodeLt& lt, const NodeRt& rt) {
            root.value() = std::max(getValue(lt), getValue(rt));
        }
        

        template<typename NodeDst, typename NodeSrc>
        static void push(NodeDst dst, const NodeSrc& src) {
            dst.extra() += src.extra();
        }
    };   
}
using SegTree = SegmentTreeLazy::SegmentTree<ll,ll,SegmentTreeLazy::TraitsMinAdd<ll,ll>>;
ll solve(const int n, const vi& p, const vi& w) {
    SegTree keepMin;
    keepMin.build(vi(n+1,0));
    for (int i = 0; i < n; i++) { keepMin.update(p[i],n,w[i]); }
    ll answ = INF;
    for (int i = 0; i + 1 < n; i++) {
        keepMin.update(p[i],n,-w[i]);
        keepMin.update(0,p[i]-1,+w[i]);
        answ = std::min(answ, keepMin.get(0, n));
    }
    return answ;
}



using namespace std;



#define pb push_back
#define eb emplace_back
#define mp make_pair
#define mt make_tuple
#define lb lower_bound
#define ub upper_bound
#define f first
#define s second
#define resz resize

#define sz(x) int((x).size())



#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define FORd(i, a, b) for (int i = (b)-1; i >= (a); i--)
#define F0Rd(i, a) for (int i = (a)-1; i >= 0; i--)
#define trav(a, x) for (auto& a : x)

#define sort_by(x, y) sort(all(x), [&](const auto& a, const auto& b) { return y; })





using vvi = vector<vi>;
using vll = vector<ll>;
using vvll = vector<vll>;
using vb = vector<bool>;
using vd = vector<double>;
using vs = vector<string>;

using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pdd = pair<double, double>;

using vpii = vector<pii>;
using vvpii = vector<vpii>;
using vpll = vector<pll>;
using vvpll = vector<vpll>;
using vpdd = vector<pdd>;
using vvpdd = vector<vpdd>;

template<typename T> void ckmin(T& a, const T& b) { a = min(a, b); }
template<typename T> void ckmax(T& a, const T& b) { a = max(a, b); }

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

namespace __input {
    template<class T1, class T2> void re(pair<T1,T2>& p);
    template<class T> void re(vector<T>& a);
    template<class T, size_t SZ> void re(array<T,SZ>& a);

    template<class T> void re(T& x) { cin >> x; }
    void re(double& x) { string t; re(t); x = stod(t); }
    template<class Arg, class... Args> void re(Arg& first, Args&... rest) {
        re(first); re(rest...);
    }

    template<class T1, class T2> void re(pair<T1,T2>& p) { re(p.f,p.s); }
    template<class T> void re(vector<T>& a) { F0R(i,sz(a)) re(a[i]); }
    template<class T, size_t SZ> void re(array<T,SZ>& a) { F0R(i,SZ) re(a[i]); }
}
using namespace __input;

namespace __output {
    template<class T1, class T2> void pr(const pair<T1,T2>& x);
    template<class T, size_t SZ> void pr(const array<T,SZ>& x);
    template<class T> void pr(const vector<T>& x);
    template<class T> void pr(const deque<T>& x);
    template<class T> void pr(const set<T>& x);
    template<class T1, class T2> void pr(const map<T1,T2>& x);

    template<class T> void pr(const T& x) { cout << x; }
    template<class Arg, class... Args> void pr(const Arg& first, const Args&... rest) {
        pr(first); pr(rest...);
    }

    template<class T1, class T2> void pr(const pair<T1,T2>& x) {
        pr("{",x.f,", ",x.s,"}");
    }
    template<class T, bool pretty = true> void prContain(const T& x) {
        if (pretty) pr("{");
        bool fst = 1; for (const auto& a: x) pr(!fst?pretty?", ":" ":"",a), fst = 0;
        if (pretty) pr("}");
    }
    template<class T> void pc(const T& x) { prContain<T, false>(x); pr("\n"); }
    template<class T, size_t SZ> void pr(const array<T,SZ>& x) { prContain(x); }
    template<class T> void pr(const vector<T>& x) { prContain(x); }
    template<class T> void pr(const deque<T>& x) { prContain(x); }
    template<class T> void pr(const set<T>& x) { prContain(x); }
    template<class T1, class T2> void pr(const map<T1,T2>& x) { prContain(x); }

    void ps() { pr("\n"); }
    template<class Arg> void ps(const Arg& first) {
        pr(first); ps();
    }
    template<class Arg, class... Args> void ps(const Arg& first, const Args&... rest) {
        pr(first," "); ps(rest...);
    }
}
using namespace __output;

#define TRACE(x) x
#define __pn(x) pr(#x, " = ")
#define pd(...) __pn((__VA_ARGS__)), ps(__VA_ARGS__), cout << flush

namespace __algorithm {
    template<typename T> void dedup(vector<T>& v) {
        sort(all(v)); v.erase(unique(all(v)), v.end());
    }
    template<typename T> typename vector<T>::iterator find(vector<T>& v, const T& x) {
        auto it = lower_bound(all(v), x); return it != v.end() && *it == x ? it : v.end();
    }
    template<typename T> size_t index(vector<T>& v, const T& x) {
        auto it = find(v, x); assert(it != v.end() && *it == x); return it - v.begin();
    }
    template<typename C, typename T, typename OP> vector<T> prefixes(const C& v, T id, OP op) {
        vector<T> r(sz(v)+1, id); F0R (i, sz(v)) r[i+1] = op(r[i], v[i]); return r;
    }
    template<typename C, typename T, typename OP> vector<T> suffixes(const C& v, T id, OP op) {
        vector<T> r(sz(v)+1, id); F0Rd (i, sz(v)) r[i] = op(v[i], r[i+1]); return r;
    }
}
using namespace __algorithm;

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-parameter"
struct monostate {
    friend istream& operator>>(istream& is, const monostate& ms) { return is; }
    friend ostream& operator<<(ostream& os, const monostate& ms) { return os; }
    friend monostate operator+(const monostate& a, const monostate& b) { return a; }
} ms;
#pragma GCC diagnostic pop

namespace __io {
    void setIn(string s) { freopen(s.c_str(),"r",stdin); }
    void setOut(string s) { freopen(s.c_str(),"w",stdout); }
    void setIO(string s = "") {
        ios_base::sync_with_stdio(0); cin.tie(0);
        cout << fixed << setprecision(15);
        if (sz(s)) { setIn(s+".in"), setOut(s+".out"); }
    }
}
using namespace __io;





template<typename T, typename U, typename TT, typename UU, typename UT>
struct segment_tree_lazy {
    int SZ;
    T tid; U uid; TT tt; UU uu; UT ut;
    vector<T> table;
    vb has; vector<U> ops;

    segment_tree_lazy() {}
    segment_tree_lazy(int _SZ, T _tid, U _uid, TT _tt, UU _uu, UT _ut)
            : tid(_tid), uid(_uid), tt(_tt), uu(_uu), ut(_ut) {
        init(_SZ);
    }
    void init(int _SZ) {
        SZ = _SZ;
        table.resize(2 * SZ, tid), has.resize(SZ), ops.resize(SZ, uid);
    }
    template<typename L> void set_leaves(L create) {
        F0R (i, SZ) table[SZ + i] = create(i);
        FORd (i, 1, SZ) table[i] = tt(table[2 * i], table[2 * i + 1]);
    }

    void _apply(int i, const U &op) {
        table[i] = ut(op, table[i]);
        if (i < SZ) has[i] = true, ops[i] = uu(op, ops[i]);
    }
    void _rebuild(int i) {
        for (i /= 2; i; i /= 2)
            table[i] = ut(ops[i], tt(table[2 * i], table[2 * i + 1]));
    }
    void _propagate(int i) {
        for (int j = 31 - __builtin_clz(i); j > 0; j--) {
            int k = i >> j;
            if (has[k]) {
                _apply(2 * k, ops[k]);
                _apply(2 * k + 1, ops[k]);
                has[k] = false, ops[k] = uid;
            }
        }
    }

    

    void replace(int i, T v) {
        i += SZ;
        _propagate(i);
        table[i] = v;
        _rebuild(i);
    }

    

    void operator()(int i, int j, U op) {
        i += SZ, j += SZ;
        _propagate(i), _propagate(j - 1);
        for (int l = i, r = j; l < r; l /= 2, r /= 2) {
            if (l&1) _apply(l++, op);
            if (r&1) _apply(--r, op);
        }
        _rebuild(i), _rebuild(j - 1);
    }

    

    const T& operator[](int i) {
        i += SZ;
        _propagate(i);
        return table[i];
    }

    

    T operator()(int i, int j) {
        i += SZ, j += SZ;
        _propagate(i), _propagate(j - 1);
        T left = tid, right = tid;
        for (; i < j; i /= 2, j /= 2) {
            if (i&1) left = tt(left, table[i++]);
            if (j&1) right = tt(table[--j], right);
        }
        return tt(left, right);
    }
};



ll correct(const int N, vi p, vi a) {
    


    trav (e, p) --e;

    const ll INF = LLONG_MAX / 4;

    using nv_t = ll;
    struct n { nv_t lo;  };
    using u = nv_t;
    auto nn = [](n a, n b) { return n{ min(a.lo, b.lo) };  };
    auto uu = plus<nv_t>();
    auto un = [](u U, n N) { N.lo += U; return N; };

    segment_tree_lazy st(N + 1, n{INF}, 0ll, nn, uu, un);

    vll costs(N); F0R (i, N) costs[p[i]] = a[i];
    vll cost_pref = prefixes(costs, 0ll, plus<ll>());

    

    st.set_leaves([&](int cutoff){
        

        return n{cost_pref[cutoff]};
    });

    ll ans = INF;
    F0R (i, N - 1) {
        

        int val = p[i];
        

        st(val+1, st.SZ, -costs[val]);
        

        st(0, val+1, +costs[val]);

        ckmin(ans, st(0, st.SZ).lo);
    }
    return ans;
}




ll slow(const int n, const vi& p, const vi& w) {
    vi pos(1+n);
    for (int i = 0; i < isz(p); i++) pos[p[i]] = i;
    ll answ = INF;
    for (int last = 0; last < n-1; last++) {
        for (int max = 1; max <= n; max++) {
            ll curr = 0;
            for (int item = 1; item <= n; item++) {
                if (item <= max) {
                    if (pos[item] > last) curr += w[pos[item]];
                }
                if (item > max) {
                    if (pos[item] <= last) curr += w[pos[item]];
                }
            }
            answ = std::min(answ, curr);
        }
    }
    return answ;
}

void test() {
    for (int len = 2; len <= 10; len++) {
        vi p(len);
        for (int i = 0; i < len; i++) p[i] = i+1;
        do {
            vi w(len);
            const int limit = std::pow(10LL, len);
            for (int mask = 0; mask < limit; mask++) {
                for (int temp = mask, bit = 0; bit < len; bit++) {
                    w[bit] = temp % 10 + 1;
                    temp /= 10;
                }
                auto ft = solve(len,p,w);
                auto sl = correct(len,p,w);
                if (ft != sl) {
                    std::cout << "len = " << len << std::endl;
                    std::cout << "ft = " << ft << std::endl;
                    std::cout << "sl = " << sl << std::endl;
                    for (int i = 0; i < len; i++) {
                        std::cout << p[i] << ' ';
                    }
                    std::cout << std::endl;
                    for (int i = 0; i < len; i++) {
                        std::cout << w[i] << ' ';
                    }
                    std::cout << std::endl;
                    std::exit(0);
                }
            }
        } while (std::next_permutation(all(p)));
        std::cout << "len = " << len << ", OK" << std::endl;
    }
    std::exit(0);
}

int main() {
    

    std::ios_base::sync_with_stdio(false); std::cin.tie(0);
    for (int n; std::cin >> n; ) {
        vi p(n); for (auto &it : p) std::cin >> it;
        vi w(n); for (auto &it : w) std::cin >> it;
        std::cout << solve(n,p,w) << std::endl;
    }
    return 0;
}