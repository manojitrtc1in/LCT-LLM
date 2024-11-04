







































template <class T>
inline void id0(std::size_t& seed, T const& v) {
    seed ^= std::hash<T>()(v) + 0x9e3779b9 + (seed<<6) + (seed>>2);
}

template <class TPL, std::size_t IDX = std::tuple_size<TPL>::value - 1>
struct _tuple_hash_impl {
    static void apply(std::size_t& seed, TPL const& tuple) {
        _tuple_hash_impl<TPL, IDX-1>::apply(seed, tuple);
        id0(seed, std::get<IDX>(tuple));
    }
};

template <class TPL>
struct _tuple_hash_impl<TPL, 0> {
    static void apply(std::size_t& seed, TPL const& tuple) {
        id0(seed, std::get<0>(tuple));
    }
};

template<typename ... T>
struct std::hash<std::tuple<T...>> {
    std::size_t operator()(std::tuple<T...> const& tuple) const {                                              
        std::size_t seed = 0;                             
        _tuple_hash_impl<std::tuple<T...> >::apply(seed, tuple);    
        return seed;                                 
    }  
};





using i32 = int;
using i64 = long long;
using str = std::string;

template<typename T>
using vec = std::vector<T>;
template<typename K, typename V>
using map = std::map<K, V>;
template<typename K, typename V>
using hash_map = std::unordered_map<K, V>;
template<typename T>
using set = std::set<T>;
template<typename T>
using multiset = std::multiset<T>;
template<typename T>
using hash_set = std::unordered_set<T>;
template<typename T>
using max_queue = std::priority_queue<T>;
template<typename T>
using min_queue = std::priority_queue<T, vec<T>, std::greater<T>>;
template<typename T1, typename T2>
using pair = std::pair<T1, T2>;
template<typename T>
using deque = std::deque<T>;

template<typename T>
using function = std::function<T>;














std::istream *in;
std::ostream *out;

void id1() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
}

void flush_out() {
    out->flush();
}

void configure_io() {
    auto is_local = getenv("LOCAL");
    if (is_local) {
        auto ifs = new std::ifstream();
        ifs->open("input.txt", std::ifstream::in);
        in = ifs;
        auto ofs = new std::ofstream();
        ofs->open("out/output.txt", std::ofstream::out);
        out = ofs;
        atexit(flush_out);
    } else {
        in = &std::cin;
        out = &std::cout;
        id1();
    }
}

template<typename T>
T read() {
    T res;
    *in >> res;
    return res;
}

template<typename T>
std::vector<T> read_vec(int sz) {
    std::vector<T> res(sz);
    for (auto i = 0; i < sz; i++) {
        res[i] = read<T>();
    }
    return res;
}










void _println() {
    *out << "\n";
}

template<typename T>
void _write(std::ostream &os, const T &v) {
    os << v;
}

template<typename T>
void _write(std::ostream &os, const std::vector<T> &a) {
    for (auto i = 0; i < a.size(); i++) {
        if (i > 0) {
            os << " ";
        }
        os << a[i];
    }
}

template<typename T, typename... Args>
void _write(std::ostream &os, const T &v, Args... args) {
    os << v << " ";
    _write(os, args...);
}

void _writeln(std::ostream &os) {
    os << "\n";
}

template<typename T, typename... Args>
void _writeln(std::ostream &os, const T &v, Args... args) {
    _write(os, v, args...);
    _writeln(os);
}

template<typename... Args>
void println(Args... args) {
    _writeln(*out, args...);
}










template<typename T>
void sort(vec<T> &a) {
    std::sort(a.begin(), a.end());
}

template<typename T>
vec<T> sorted(const vec<T> &a) {
    auto b = a;
    sort(b);
    return b;
}

vec<i32> iota(i32 sz, i32 start = 0) {
    vec<i32> res(sz);
    std::iota(res.begin(), res.end(), start);
    return res;
}

template<typename T>
void reverse(vec<T> &a) {
    std::reverse(a.begin(), a.end());
}

template<typename T>
vec<T> reversed(const vec<T> &a) {
    auto b = a;
    reverse(b);
    return b;
}

template<typename T, typename F>
vec<vec<T>> id3(const vec<T> &a, F take) {
    i32 sz = a.size();
    vec<vec<T>> res;
    vec<T> cur = {a[0]};
    for (auto i = 1; i < sz; i++) {
        if (!take(cur.back(), a[i])) {
            res.push_back(move(cur));
            cur = {};
        }
        cur.push_back(a[i]);
    }
    res.push_back(move(cur));
    return res;
}















template<class T1, class T2>
constexpr std::common_type_t<T1, T2> min(T1 v1, T2 v2) {
    return v1 < v2 ? v1 : v2;
}

template<class T1, class T2, class T3>
constexpr std::common_type_t<T1, T2, T3> min(T1 v1, T2 v2, T3 v3) {
    return min(v1, min(v2, v3));
}

template<class T1, class T2>
constexpr std::common_type_t<T1, T2> max(T1 v1, T2 v2) {
    return v1 > v2 ? v1 : v2;
}

template<class T1, class T2, class T3>
constexpr std::common_type_t<T1, T2, T3> max(T1 v1, T2 v2, T3 v3) {
    return max(v1, max(v2, v3));
}

template<class T1, class T2>
constexpr std::common_type_t<T1, T2> gcd(T1 v1, T2 v2) {
    return std::gcd(v1, v2);
}

template<class T1, class T2>
constexpr std::common_type_t<T1, T2> lcm(T1 v1, T2 v2) {
    return std::lcm(v1, v2);
}

template<class T>
constexpr T abs(T v) {
    return v > 0 ? v : -v;
}

template<class T1, class T2>
constexpr std::common_type_t<T1, T2> div_up(T1 v, T2 d) {
    return v/d + (v%d > 0 ? 1 : 0);
}





struct id12 {
    i32 val;
    i32 dir;

    id12(i32 val, i32 dir): val(val), dir(dir) {
    }

    id12& operator++() {
        val += dir;
        return *this;
    }

    i32 operator*() const {
        return val;
    }

    bool operator==(const id12& other) const {
        return val == other.val;
    }

    bool operator!=(const id12& other) const {
        return val != other.val;
    }
};

struct rng_container {
    i32 start;
    i32 bound;
    i32 dir;

    id12 begin() {
        return id12(start, dir);
    }

    id12 end() {
        return id12(bound, dir);
    }
};

rng_container rng(i32 start, i32 bound) {
    return {min(start, bound), bound, 1};
}

rng_container rng(i32 bound) {
    return rng(0, bound);
}

rng_container id15(i32 start, i32 bound) {
    return rng(start, bound+1);
}

rng_container id15(i32 bound) {
    return id15(0, bound);
}

rng_container inf_rng() {
    return rng(2e9);
}

rng_container rev(rng_container range) {
    return {range.bound-1, range.start-1, -1};
}

template<typename T>
rng_container indices(const vec<T> &a) {
    return rng(a.size());
}







template<typename T>
T pop_back(vec<T> &a) {
    auto v = a.back();
    a.pop_back();
    return v;
}

template<typename T>
T pop_front(deque<T> &a) {
    auto v = a.front();
    a.pop_front();
    return v;
}

template<typename T, typename CONT, typename CMP>
T pop(std::priority_queue<T, CONT, CMP> &q) {
    auto res = q.top();
    q.pop();
    return res;
}


















    var_type_1 id11;\
\
    class_name() {\
    }\
\
    class_name(var_type_1 id11): id11(id11) {\
    }\
\
    bool operator==(const class_name& other) const {\
        return id11 == other.id11;\
    }\
\
    bool operator!=(const class_name& other) const {\
        return !(*this == other);\
    }\
\
    bool operator<(const class_name& other) const {\
        if (id11 < other.id11) {\
            return true;\
        }\
        if (id11 > other.id11) {\
            return false;\
        }\
        return false;\
    }\
\
    bool operator>(const class_name& other) const {\
        return *this != other && !(*this < other);\
    }\
}


    var_type_1 id11;\
    var_type_2 id13;\
\
    class_name() {\
    }\
\
    class_name(var_type_1 id11, var_type_2 id13): id11(id11), id13(id13) {\
    }\
\
    bool operator==(const class_name& other) const {\
        return id11 == other.id11 && id13 == other.id13;\
    }\
\
    bool operator!=(const class_name& other) const {\
        return !(*this == other);\
    }\
\
    bool operator<(const class_name& other) const {\
        if (id11 < other.id11) {\
            return true;\
        }\
        if (id11 > other.id11) {\
            return false;\
        }\
        if (id13 < other.id13) {\
            return true;\
        }\
        if (id13 > other.id13) {\
            return false;\
        }\
        return false;\
    }\
\
    bool operator>(const class_name& other) const {\
        return *this != other && !(*this < other);\
    }\
}


    var_type_1 id11;\
    var_type_2 id13;\
    var_type_3 id4;\
\
    class_name() {\
    }\
\
    class_name(var_type_1 id11, var_type_2 id13, var_type_3 id4): id11(id11), id13(id13), id4(id4) {\
    }\
\
    bool operator==(const class_name& other) const {\
        return id11 == other.id11 && id13 == other.id13 && id4 == other.id4;\
    }\
\
    bool operator!=(const class_name& other) const {\
        return !(*this == other);\
    }\
\
    bool operator<(const class_name& other) const {\
        if (id11 < other.id11) {\
            return true;\
        }\
        if (id11 > other.id11) {\
            return false;\
        }\
        if (id13 < other.id13) {\
            return true;\
        }\
        if (id13 > other.id13) {\
            return false;\
        }\
        if (id4 < other.id4) {\
            return true;\
        }\
        if (id4 > other.id4) {\
            return false;\
        }\
        return false;\
    }\
\
    bool operator>(const class_name& other) const {\
        return *this != other && !(*this < other);\
    }\
}


    var_type_1 id11;\
    var_type_2 id13;\
    var_type_3 id4;\
    var_type_4 id10;\
\
    class_name() {\
    }\
\
    class_name(var_type_1 id11, var_type_2 id13, var_type_3 id4, var_type_4 id10): id11(id11), id13(id13), id4(id4), id10(id10) {\
    }\
\
    bool operator==(const class_name& other) const {\
        return id11 == other.id11 && id13 == other.id13 && id4 == other.id4 && id10 == other.id10;\
    }\
\
    bool operator!=(const class_name& other) const {\
        return !(*this == other);\
    }\
\
    bool operator<(const class_name& other) const {\
        if (id11 < other.id11) {\
            return true;\
        }\
        if (id11 > other.id11) {\
            return false;\
        }\
        if (id13 < other.id13) {\
            return true;\
        }\
        if (id13 > other.id13) {\
            return false;\
        }\
        if (id4 < other.id4) {\
            return true;\
        }\
        if (id4 > other.id4) {\
            return false;\
        }\
        if (id10 < other.id10) {\
            return true;\
        }\
        if (id10 > other.id10) {\
            return false;\
        }\
        return false;\
    }\
\
    bool operator>(const class_name& other) const {\
        return *this != other && !(*this < other);\
    }\
}









i32 id6 = 0;


void id14(bool ans) {
    println(ans ? "Yes" : "No");
}

void solve();

i32 main() {
    configure_io();
    if (id6 > 0) {
        READ(i32, t);
        for (i32 tc = 0; tc < t; tc++) {
            solve();
        }
    } else {
        solve();
    }
}








struct id7 {
    i32 n;
    vec<i32> p;

    id7(i32 n): n(n), p(iota(n)) {
    }

    i32 parent(i32 v) {
        if (p[v] != v) {
            p[v] = parent(p[v]);
        }
        return p[v];
    }

    bool join(i32 v, i32 u) {
        i32 pv = parent(v);
        i32 pu = parent(u);
        p[pv] = pu;
        return pu != pv;
    }
};











template <typename FUNC>
struct return_of;

template <typename RT, typename... AT>
struct return_of<RT(*)(AT...)> {
    using type = RT;
};

template <typename FUNC>
using return_of_t = typename return_of<FUNC>::type;

template <typename FUNC>
struct second_arg_of;

template <typename RT, typename A1T, typename A2T, typename... AT>
struct second_arg_of<RT(*)(A1T, A2T, AT...)> {
    using type = A2T;
};

template <typename FUNC>
using second_arg_of_t = typename second_arg_of<FUNC>::type;







template<typename OPS>
class id2 {
public:
    using T = return_of_t<decltype(&OPS::combine)>;
    using U = second_arg_of_t<decltype(&OPS::update)>;

    id2(i32 n): _data(4*n), _n(n) {
    }

    id2(const vec<T> &a): id2(a.size()) {
        _bld(a, 1, 0, _n-1);
    }

    T get(i32 l, i32 r) {
        return _get(l, r, 1, 0, _n-1);
    }

    void upd(i32 i, U val) {
        _upd(i, val, 1, 0, _n-1);
    }

private:
    i32 _n;
    vec<T> _data;

    void _bld(const vec<T> &a, i32 v, i32 from, i32 to) {
        if (from == to) {
            _data[v] = a[from];
        } else {
            i32 mid = (from+to)/2;
            _bld(a, 2*v, from, mid);
            _bld(a, 2*v+1, mid+1, to);
            _recalc(v);
        }
    }

    void _upd(i32 i, U val, i32 v, i32 from, i32 to) {
        if (from < to) {
            i32 mid = (from+to)/2;
            if (i <= mid) {
                _upd(i, val, 2*v, from, mid);
            } else {
                _upd(i, val, 2*v+1, mid+1, to);
            }
            _recalc(v);
        } else {
            _data[v] = OPS::update(_data[v], val);
        }
    }

    T _get(i32 l, i32 r, i32 v, i32 from, i32 to) {
        if (l <= from && to <= r) {
            return _data[v];
        }

        i32 mid = (from+to)/2;
        if (l > mid) {
            return _get(l, r, 2*v+1, mid+1, to);
        }
        if (mid+1 > r) {
            return _get(l, r, 2*v, from, mid);
        }
        return OPS::combine(_get(l, r, 2*v, from, mid), _get(l, r, 2*v+1, mid+1, to));
    }

    void _recalc(i32 v) {
        _data[v] = OPS::combine(_data[2*v], _data[2*v+1]);
    }
};



ENABLE_MULTITEST;

struct max_ops {
    static i32 combine(i32 a, i32 b) {
        return max(a, b);
    }

    static i32 update(i32 cur, i32 val) {
        throw "kek";
    }
};

DATACLASS(edge, i32, to, i32, w);
DATACLASS(path, i32, to, i32, max_w);

void solve() {
    READ(i32, n, m, q);
    id7 dsu(n);
    vec<vec<edge>> g(n);
    for (i32 i: rng(m)) {
        READ(i32, u, v);
        u--; v--;
        if (!dsu.join(u, v)) {
            continue;
        }
        i32 w = i+1;
        g[v].emplace_back(u, w);
        g[u].emplace_back(v, w);
    }
    vec<vec<path>> pss(n);
    function<void(i32, i32, i32)> dfs;
    vec<pair<i32, i32>> c(n);
    i32 tm = 0;
    dfs = [&] (i32 v, i32 p, i32 w) {
        c[v].first = tm++;
        auto &ps = pss[v];
        i32 cur_p = p;
        i32 id8 = w;
        while (cur_p != -1) {
            i32 pw = ps.size();
            assert(pw < 30);
            ps.emplace_back(cur_p, id8);
            auto &id9 = pss[cur_p];
            if (pw < id9.size()) {
                auto pth = id9[pw];
                cur_p = pth.to;
                id8 = max(pth.max_w, id8);
            } else {
                cur_p = -1;
            }
        }
        for (auto e: g[v]) {
            if (e.to != p) {
                dfs(e.to, v, e.w);
            }
        }
        c[v].second = tm;
    };
    dfs(0, -1, 0);
    auto id5 = [&] (i32 p, i32 v) {
        i32 tm_v = c[v].first;
        return c[p].first <= tm_v && tm_v < c[p].second;
    };
    auto lift = [&] (i32 v, i32 u) -> i32 {
        if (id5(v, u)) {
            return 0;
        }
        i32 cur = v;
        i32 max_w = 0;
        for (i32 pw: rev(rng(pss[v].size()))) {
            auto &ps = pss[cur];
            if (ps.size() <= pw) {
                continue;
            }
            auto pth = ps[pw];
            if (id5(pth.to, u)) {
                continue;
            }
            cur = pth.to;
            max_w = max(max_w, pth.max_w);
        }
        assert(!id5(cur, u));
        auto last_link = pss[cur][0];
        assert(id5(last_link.to, u));
        return max(max_w, last_link.max_w);
    };
    auto path_w = [&] (i32 v, i32 u) {
        return max(lift(v, u), lift(u, v));
    };
    vec<i32> a(n-1);
    for (i32 i: rng(n-1)) {
        a[i] = path_w(i, i+1);
    }
    vec<vec<path>>().swap(pss);
    id2<max_ops> st(a);

    vec<i32> res;
    for (i32 qi: rng(q)) {
        READ(i32, l, r);
        l--; r--;
        i32 ans = l == r ? 0 : st.get(l, r-1);
        res.push_back(ans);
    }
    println(res);
}