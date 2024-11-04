



#ifndef CORE_DEFS_H
#define CORE_DEFS_H



#ifndef CORE_STD_INCLUDES_H
#define CORE_STD_INCLUDES_H

#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <deque>
#include <queue>

#include <string>
#include <algorithm>
#include <utility>
#include <functional>
#include <numeric>
#include <cassert>

#endif




#ifndef CORE_HASH_H
#define CORE_HASH_H

#include <functional>
#include <tuple>



template <class T>
inline void _hash_combine(std::size_t& seed, T const& v) {
    seed ^= std::hash<T>()(v) + 0x9e3779b9 + (seed<<6) + (seed>>2);
}

template <class TPL, std::size_t IDX = std::tuple_size<TPL>::value - 1>
struct _tuple_hash_impl {
    static void apply(std::size_t& seed, TPL const& tuple) {
        _tuple_hash_impl<TPL, IDX-1>::apply(seed, tuple);
        _hash_combine(seed, std::get<IDX>(tuple));
    }
};

template <class TPL>
struct _tuple_hash_impl<TPL, 0> {
    static void apply(std::size_t& seed, TPL const& tuple) {
        _hash_combine(seed, std::get<0>(tuple));
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

#endif



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

#endif





#ifndef CORE_IO_H
#define CORE_IO_H

#include <iostream>
#include <fstream> 
#include <type_traits>

std::istream *in;
std::ostream *out;

void enable_fast_input() {
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
        enable_fast_input();
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

#define READ_1(tp, var) tp var = read<tp>()
#define READ_2(tp, var_1, var_2) READ_1(tp, var_1); READ_1(tp, var_2)
#define READ_3(tp, var_1, var_2, var_3) READ_2(tp, var_1, var_2); READ_1(tp, var_3)
#define READ_4(tp, var_1, var_2, var_3, var_4) READ_3(tp, var_1, var_2, var_3); READ_1(tp, var_4)
#define READ_5(tp, var_1, var_2, var_3, var_4, var_5) READ_4(tp, var_1, var_2, var_3, var_4); READ_1(tp, var_5)
#define _GET_READ_NAME(_1, _2, _3, _4, _5, _6, NAME, ...) NAME
#define READ(...) _GET_READ_NAME(__VA_ARGS__, READ_5, READ_4, READ_3, READ_2, READ_1)(__VA_ARGS__)
#define READ_VEC(tp, var, sz) std::vector<tp> var = read_vec<tp>(sz)

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

#endif




#ifndef UTILS_VEC_H
#define UTILS_VEC_H


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
vec<vec<T>> group_consec(const vec<T> &a, F take) {
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

#endif




#ifndef UTILS_ITER_H
#define UTILS_ITER_H



#ifndef UTILS_MATH_H
#define UTILS_MATH_H


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

#endif



struct rng_container_iterator {
    i32 val;
    i32 dir;

    rng_container_iterator(i32 val, i32 dir): val(val), dir(dir) {
    }

    rng_container_iterator& operator++() {
        val += dir;
        return *this;
    }

    i32 operator*() const {
        return val;
    }

    bool operator==(const rng_container_iterator& other) const {
        return val == other.val;
    }

    bool operator!=(const rng_container_iterator& other) const {
        return val != other.val;
    }
};

struct rng_container {
    i32 start;
    i32 bound;
    i32 dir;

    rng_container_iterator begin() {
        return rng_container_iterator(start, dir);
    }

    rng_container_iterator end() {
        return rng_container_iterator(bound, dir);
    }
};

rng_container rng(i32 start, i32 bound) {
    return {min(start, bound), bound, 1};
}

rng_container rng(i32 bound) {
    return rng(0, bound);
}

rng_container rng_incl(i32 start, i32 bound) {
    return rng(start, bound+1);
}

rng_container rng_incl(i32 bound) {
    return rng_incl(0, bound);
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

#endif





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






#ifndef UTILS_MACRO_H
#define UTILS_MACRO_H

#define _CONCAT(x, y) x##y
#define CONCAT(x, y) _CONCAT(x,y)

#endif




#define DATACLASS_1(class_name, var_type_1, var_name_1) struct class_name {\
    var_type_1 var_name_1;\
\
    class_name() {\
    }\
\
    class_name(var_type_1 var_name_1): var_name_1(var_name_1) {\
    }\
\
    bool operator==(const class_name& other) const {\
        return var_name_1 == other.var_name_1;\
    }\
\
    bool operator!=(const class_name& other) const {\
        return !(*this == other);\
    }\
\
    bool operator<(const class_name& other) const {\
        if (var_name_1 < other.var_name_1) {\
            return true;\
        }\
        if (var_name_1 > other.var_name_1) {\
            return false;\
        }\
        return false;\
    }\
\
    bool operator>(const class_name& other) const {\
        return *this != other && !(*this < other);\
    }\
}

#define DATACLASS_2(class_name, var_type_1, var_name_1, var_type_2, var_name_2) struct class_name {\
    var_type_1 var_name_1;\
    var_type_2 var_name_2;\
\
    class_name() {\
    }\
\
    class_name(var_type_1 var_name_1, var_type_2 var_name_2): var_name_1(var_name_1), var_name_2(var_name_2) {\
    }\
\
    bool operator==(const class_name& other) const {\
        return var_name_1 == other.var_name_1 && var_name_2 == other.var_name_2;\
    }\
\
    bool operator!=(const class_name& other) const {\
        return !(*this == other);\
    }\
\
    bool operator<(const class_name& other) const {\
        if (var_name_1 < other.var_name_1) {\
            return true;\
        }\
        if (var_name_1 > other.var_name_1) {\
            return false;\
        }\
        if (var_name_2 < other.var_name_2) {\
            return true;\
        }\
        if (var_name_2 > other.var_name_2) {\
            return false;\
        }\
        return false;\
    }\
\
    bool operator>(const class_name& other) const {\
        return *this != other && !(*this < other);\
    }\
}

#define DATACLASS_3(class_name, var_type_1, var_name_1, var_type_2, var_name_2, var_type_3, var_name_3) struct class_name {\
    var_type_1 var_name_1;\
    var_type_2 var_name_2;\
    var_type_3 var_name_3;\
\
    class_name() {\
    }\
\
    class_name(var_type_1 var_name_1, var_type_2 var_name_2, var_type_3 var_name_3): var_name_1(var_name_1), var_name_2(var_name_2), var_name_3(var_name_3) {\
    }\
\
    bool operator==(const class_name& other) const {\
        return var_name_1 == other.var_name_1 && var_name_2 == other.var_name_2 && var_name_3 == other.var_name_3;\
    }\
\
    bool operator!=(const class_name& other) const {\
        return !(*this == other);\
    }\
\
    bool operator<(const class_name& other) const {\
        if (var_name_1 < other.var_name_1) {\
            return true;\
        }\
        if (var_name_1 > other.var_name_1) {\
            return false;\
        }\
        if (var_name_2 < other.var_name_2) {\
            return true;\
        }\
        if (var_name_2 > other.var_name_2) {\
            return false;\
        }\
        if (var_name_3 < other.var_name_3) {\
            return true;\
        }\
        if (var_name_3 > other.var_name_3) {\
            return false;\
        }\
        return false;\
    }\
\
    bool operator>(const class_name& other) const {\
        return *this != other && !(*this < other);\
    }\
}

#define DATACLASS_4(class_name, var_type_1, var_name_1, var_type_2, var_name_2, var_type_3, var_name_3, var_type_4, var_name_4) struct class_name {\
    var_type_1 var_name_1;\
    var_type_2 var_name_2;\
    var_type_3 var_name_3;\
    var_type_4 var_name_4;\
\
    class_name() {\
    }\
\
    class_name(var_type_1 var_name_1, var_type_2 var_name_2, var_type_3 var_name_3, var_type_4 var_name_4): var_name_1(var_name_1), var_name_2(var_name_2), var_name_3(var_name_3), var_name_4(var_name_4) {\
    }\
\
    bool operator==(const class_name& other) const {\
        return var_name_1 == other.var_name_1 && var_name_2 == other.var_name_2 && var_name_3 == other.var_name_3 && var_name_4 == other.var_name_4;\
    }\
\
    bool operator!=(const class_name& other) const {\
        return !(*this == other);\
    }\
\
    bool operator<(const class_name& other) const {\
        if (var_name_1 < other.var_name_1) {\
            return true;\
        }\
        if (var_name_1 > other.var_name_1) {\
            return false;\
        }\
        if (var_name_2 < other.var_name_2) {\
            return true;\
        }\
        if (var_name_2 > other.var_name_2) {\
            return false;\
        }\
        if (var_name_3 < other.var_name_3) {\
            return true;\
        }\
        if (var_name_3 > other.var_name_3) {\
            return false;\
        }\
        if (var_name_4 < other.var_name_4) {\
            return true;\
        }\
        if (var_name_4 > other.var_name_4) {\
            return false;\
        }\
        return false;\
    }\
\
    bool operator>(const class_name& other) const {\
        return *this != other && !(*this < other);\
    }\
}

#define _GET_DATACLASS_NAME(_1, _2, _3, _4, _5, _6, _7, _8, _9, NAME, ...) NAME
#define DATACLASS(...) _GET_DATACLASS_NAME(__VA_ARGS__, DATACLASS_4, DATACLASS_4, DATACLASS_3, DATACLASS_3, DATACLASS_2, DATACLASS_2, DATACLASS_1, DATACLASS_1)(__VA_ARGS__)






i32 multitest_enalbed = 0;
#define ENABLE_MULTITEST i32 multitest_enalbed_ignore = ++multitest_enalbed

void println_yes_no(bool ans) {
    println(ans ? "Yes" : "No");
}

void solve();

i32 main() {
    configure_io();
    if (multitest_enalbed > 0) {
        READ(i32, t);
        for (i32 tc = 0; tc < t; tc++) {
            solve();
        }
    } else {
        solve();
    }
}



ENABLE_MULTITEST;

void solve() {
    READ(i32, n, m, q);
    READ(str, s);
    vec<pair<i64, i64>> st;
    i64 sz = n;
    for (i32 i: rng(m)) {
        READ(i64, l, r);
        l--; r--;
        i64 len = r-l+1;
        st.emplace_back(sz, l);
        sz += len;
    }
    reverse(st);
    for (i32 qi: rng(q)) {
        READ(i64, k);
        k--;
        auto j = k;
        for (auto &p: st) {
            if (p.first <= j) {
                i64 d = j - p.first;
                j = p.second + d;
            }
        }
        

        println(s[j]);
    }
}