







































template <class T>
inline void id1(std::size_t& seed, T const& v) {
    seed ^= std::hash<T>()(v) + 0x9e3779b9 + (seed<<6) + (seed>>2);
}

template <class TPL, std::size_t IDX = std::tuple_size<TPL>::value - 1>
struct _tuple_hash_impl {
    static void apply(std::size_t& seed, TPL const& tuple) {
        _tuple_hash_impl<TPL, IDX-1>::apply(seed, tuple);
        id1(seed, std::get<IDX>(tuple));
    }
};

template <class TPL>
struct _tuple_hash_impl<TPL, 0> {
    static void apply(std::size_t& seed, TPL const& tuple) {
        id1(seed, std::get<0>(tuple));
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

void id2() {
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
        id2();
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
vec<vec<T>> id7(const vec<T> &a, F take) {
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





struct id0 {
    i32 val;
    i32 dir;

    id0(i32 val, i32 dir): val(val), dir(dir) {
    }

    id0& operator++() {
        val += dir;
        return *this;
    }

    i32 operator*() const {
        return val;
    }

    bool operator==(const id0& other) const {
        return val == other.val;
    }

    bool operator!=(const id0& other) const {
        return val != other.val;
    }
};

struct rng_container {
    i32 start;
    i32 bound;
    i32 dir;

    id0 begin() {
        return id0(start, dir);
    }

    id0 end() {
        return id0(bound, dir);
    }
};

rng_container rng(i32 start, i32 bound) {
    return {min(start, bound), bound, 1};
}

rng_container rng(i32 bound) {
    return rng(0, bound);
}

rng_container id6(i32 start, i32 bound) {
    return rng(start, bound+1);
}

rng_container id6(i32 bound) {
    return id6(0, bound);
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


















    var_type_1 id9;\
\
    class_name() {\
    }\
\
    class_name(var_type_1 id9): id9(id9) {\
    }\
\
    bool operator==(const class_name& other) const {\
        return id9 == other.id9;\
    }\
\
    bool operator!=(const class_name& other) const {\
        return !(*this == other);\
    }\
\
    bool operator<(const class_name& other) const {\
        if (id9 < other.id9) {\
            return true;\
        }\
        if (id9 > other.id9) {\
            return false;\
        }\
        return false;\
    }\
\
    bool operator>(const class_name& other) const {\
        return *this != other && !(*this < other);\
    }\
}


    var_type_1 id9;\
    var_type_2 id3;\
\
    class_name() {\
    }\
\
    class_name(var_type_1 id9, var_type_2 id3): id9(id9), id3(id3) {\
    }\
\
    bool operator==(const class_name& other) const {\
        return id9 == other.id9 && id3 == other.id3;\
    }\
\
    bool operator!=(const class_name& other) const {\
        return !(*this == other);\
    }\
\
    bool operator<(const class_name& other) const {\
        if (id9 < other.id9) {\
            return true;\
        }\
        if (id9 > other.id9) {\
            return false;\
        }\
        if (id3 < other.id3) {\
            return true;\
        }\
        if (id3 > other.id3) {\
            return false;\
        }\
        return false;\
    }\
\
    bool operator>(const class_name& other) const {\
        return *this != other && !(*this < other);\
    }\
}


    var_type_1 id9;\
    var_type_2 id3;\
    var_type_3 id8;\
\
    class_name() {\
    }\
\
    class_name(var_type_1 id9, var_type_2 id3, var_type_3 id8): id9(id9), id3(id3), id8(id8) {\
    }\
\
    bool operator==(const class_name& other) const {\
        return id9 == other.id9 && id3 == other.id3 && id8 == other.id8;\
    }\
\
    bool operator!=(const class_name& other) const {\
        return !(*this == other);\
    }\
\
    bool operator<(const class_name& other) const {\
        if (id9 < other.id9) {\
            return true;\
        }\
        if (id9 > other.id9) {\
            return false;\
        }\
        if (id3 < other.id3) {\
            return true;\
        }\
        if (id3 > other.id3) {\
            return false;\
        }\
        if (id8 < other.id8) {\
            return true;\
        }\
        if (id8 > other.id8) {\
            return false;\
        }\
        return false;\
    }\
\
    bool operator>(const class_name& other) const {\
        return *this != other && !(*this < other);\
    }\
}


    var_type_1 id9;\
    var_type_2 id3;\
    var_type_3 id8;\
    var_type_4 id5;\
\
    class_name() {\
    }\
\
    class_name(var_type_1 id9, var_type_2 id3, var_type_3 id8, var_type_4 id5): id9(id9), id3(id3), id8(id8), id5(id5) {\
    }\
\
    bool operator==(const class_name& other) const {\
        return id9 == other.id9 && id3 == other.id3 && id8 == other.id8 && id5 == other.id5;\
    }\
\
    bool operator!=(const class_name& other) const {\
        return !(*this == other);\
    }\
\
    bool operator<(const class_name& other) const {\
        if (id9 < other.id9) {\
            return true;\
        }\
        if (id9 > other.id9) {\
            return false;\
        }\
        if (id3 < other.id3) {\
            return true;\
        }\
        if (id3 > other.id3) {\
            return false;\
        }\
        if (id8 < other.id8) {\
            return true;\
        }\
        if (id8 > other.id8) {\
            return false;\
        }\
        if (id5 < other.id5) {\
            return true;\
        }\
        if (id5 > other.id5) {\
            return false;\
        }\
        return false;\
    }\
\
    bool operator>(const class_name& other) const {\
        return *this != other && !(*this < other);\
    }\
}









i32 id10 = 0;


void id4(bool ans) {
    println(ans ? "Yes" : "No");
}

void solve();

i32 main() {
    configure_io();
    if (id10 > 0) {
        READ(i32, t);
        for (i32 tc = 0; tc < t; tc++) {
            solve();
        }
    } else {
        solve();
    }
}



ENABLE_MULTITEST;

const i32 INF = 1e9;
const i32 MX = 100009;

void solve() {
    READ(i32, n, k);
    READ_VEC(i32, a, n);
    i32 sz = a[0]+1;
    vec<i32> b(sz);
    auto upd = [&] (i32 j, i32 v) {
        if (j < sz) {
            b[j] = max(b[j], v);
        }
    };
    for (i32 v: a) {
        i32 prev = INF;
        for (i32 d = 1; d <= min(k, v); d = v/(v/d)+1) {
            i32 pv = v/d;
            upd(pv+1, prev);
            prev = pv;
        }
        upd(0, prev);
    }
    i32 mx = 0;
    i32 ans = INF;
    for (i32 mn: rng(sz)) {
        mx = max(mx, b[mn]);
        ans = min(ans, mx - mn);
    }
    println(ans);
}