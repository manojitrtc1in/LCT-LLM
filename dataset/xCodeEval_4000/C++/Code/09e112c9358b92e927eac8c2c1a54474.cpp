

#include <bits/stdc++.h>
using namespace std;


using u64 = uint64_t;
using u32 = uint32_t;
using i64 = int64_t;
using i32 = int32_t;
const i64 inf = (1ll << 62);
const i64 imax = numeric_limits<i64>::max();
const i64 umax = numeric_limits<u64>::max();
void merror(string msg, i64 line_number) { cerr << "assert >> " << line_number << ": " << msg << endl; exit(42); }
#define massert(c, msg) do { if (!(c)) merror(msg, __LINE__); } while(0)
#define massert2(c) massert(c, "")
template <typename C> i64 isize(const C& c) { return static_cast<i64>(c.size()); }
template <typename T, size_t N> i64 isize(const array<T, N>& = {}) { return static_cast<i64>(N); }
template <typename It, typename Cont> bool it_last(It it, const Cont& c) { return ++it == c.cend(); }




namespace fun {
template <typename T> const auto identity = [](const T& t) -> const T& { return t; };
template <typename T> const auto first = [](const T& t) { return t.first; };
template <typename T> const auto second = [](const T& t) { return t.second; };
template <typename T, u32 n> const auto nth = [](const T& t) { return get<n>(t); };
template <typename TOut, typename F, typename TIn> vector<TOut> transf(const TIn& in, F f) { vector<TOut> v; transform(in.begin(), in.end(), back_inserter(v), f); return v; }
template <typename F, typename T> void sort(T& v, F f) { sort(v.begin(), v.end(), f); }
template <typename TOut, typename F, typename TIn> vector<TOut> sorted(const TIn& in, F f) { vector<TOut> v(in.begin(), in.end()); sort(v, f); return v; }
} 





template<class...> using void_t = void;
template <class, class = void> struct has_repr : false_type {};
template <class T> struct has_repr<T, void_t<decltype(declval<T>()._repr())>> : true_type {};
template <class, class = void> struct has_str : false_type {};
template <class T> struct has_str<T, void_t<decltype(declval<T>()._str())>> : true_type {};
template <class, class = void> struct has_read : false_type {};
template <class T> struct has_read<T, void_t<decltype(declval<T>()._read())>> : true_type {};
template <class, class = void> struct is_map : false_type {};
template <class T> struct is_map<T, void_t<typename T::key_type, typename T::mapped_type>> : true_type {};
template <class, class = void> struct is_set : false_type {};
template <class T> struct is_set<T, void_t<typename T::key_type>> : true_type {};




template <typename T, class = void> struct _Str { string operator()(const T& t) { return to_string(t); } };
template <> struct _Str<string> { string operator()(const string& t) { return t; } };
template <> struct _Str<const char*> { string operator()(const char* t) { return t; } };
template <typename T> string str(const T& t) { return _Str<T>()(t); }
template <typename T> struct _Str<T, enable_if_t<has_str<T>::value>> { string operator()(const T& t) {
    return t._str();
} };
template <typename T>
struct _Str<vector<T>> {
    string operator()(const vector<T>& t) {
        string s = "";
        for (i64 i = 0; i < isize(t); i++) {
            s += str(t[i]);
            if (i != isize(t) - 1)
                s += ' ';
        }
        return s;
    }
};




template <i32 rev_index, typename T> struct _StrTuple { string operator() (const T& tpl) {
    return str(get<tuple_size<T>::value - rev_index>(tpl)) + ' ' + _StrTuple<rev_index - 1, T>()(tpl);
} };
template <typename T> struct _StrTuple<1, T> { string operator()(const T& t) {
    return str(get<tuple_size<T>::value - 1>(t));
} };
template <> struct _StrTuple<0, tuple<>> { string operator()(const tuple<>&) { return ""; } };
template <typename ...Ts> struct _Str<tuple<Ts...>> { string operator()(const tuple<Ts...>& t) {
    using T = tuple<Ts...>;
    return _StrTuple<tuple_size<T>::value, T>()(t);
} };
template <class T1, class T2> struct _Str<pair<T1, T2>> { string operator()(const pair<T1, T2>& p) {
    return str(make_tuple(p.first, p.second));
} };




template <typename T, class = void> struct _Repr { string operator()(const T& t) { return str(t); } };
template <typename T> string repr(const T& t) { return _Repr<T>()(t); }
template <> struct _Repr<string> { string operator()(const string& t) { return '"' + t + '"'; } };
template <> struct _Repr<const char*> { string operator()(const char* const& t) { return repr(string(t)); } };
template <typename T> struct _Repr<T, enable_if_t<has_repr<T>::value>> { string operator()(const T& t) {
    return t._repr();
} };
template <typename T>
struct _Repr<vector<T>> {
    string operator()(const vector<T>& t) {
        string s = "[";
        for (i64 i = 0; i < isize(t); i++) {
            s += repr(t[i]);
            if (i != isize(t) - 1)
                s += ',';
        }
        s += ']';
        return s;
    }
};
template <typename T>
struct _Repr<T, enable_if_t<is_set<T>::value && !is_map<T>::value>> {
    string operator()(const T& t) {
        string s = "{";
        for (auto it = t.cbegin(); it != t.cend(); it++) {
            s += repr(*it);
            if (!it_last(it, t))
                s += ',';
        }
        s += '}';
        return s;
    }
};
template <typename T>
struct _Repr<T, enable_if_t<is_map<T>::value>> {
    string operator()(const T& t) {
        string s = "{";
        for (auto it = t.cbegin(); it != t.cend(); it++) {
            s += repr(it->first) + ':' + repr(it->second);
            if (!it_last(it, t))
                s += ',';
        }
        s += '}';
        return s;
    }
};




string _repr_helper(i64 i, const vector<string>& header) {
    massert(i == isize(header), "header too long");
    return "";
}
template <typename T, typename ...Ts>
string _repr_helper(i64 i, const vector<string>& header, const T& t, const Ts&... ts) {
    massert(i < isize(header), "header too short");
    auto s = header[i] + "=" + repr(t);
    if (i < isize(header) - 1)
        s += "," + _repr_helper(i + 1, header, ts...);
    return s;
}
template <typename ...Ts>
string make_repr(string classname, const vector<string>& header, const Ts&... ts) {
    return classname + '(' + _repr_helper(0, header, ts...) + ')';
}




template <i32 rev_index, typename T> struct _ReprTuple { string operator() (const T& tpl) {
    return repr(get<tuple_size<T>::value - rev_index>(tpl)) + ',' + _ReprTuple<rev_index - 1, T>()(tpl);
} };
template <typename T> struct _ReprTuple<1, T> { string operator()(const T& t) {
    return repr(get<tuple_size<T>::value - 1>(t));
} };
template <> struct _ReprTuple<0, tuple<>> { string operator()(const tuple<>&) { return ""; } };
template <typename ...Ts> struct _Repr<tuple<Ts...>> { string operator()(const tuple<Ts...>& t) {
    using T = tuple<Ts...>;
    return '(' + _ReprTuple<tuple_size<T>::value, T>()(t) + ')';
} };
template <class T1, class T2> struct _Repr<pair<T1, T2>> { string operator()(const pair<T1, T2>& p) {
    return repr(make_tuple(p.first, p.second));
} };




template <typename It> void _print_collection(ostream& os, It begin, It end) { os << "["; while (begin != end) { os << *(begin++); if (begin != end) os << ','; } os << "]"; }
#define MAKE_PRINTER_1(container) template <typename T> ostream& operator<<(ostream& os, const container<T>& t) { _print_collection(os, t.begin(), t.end()); return os; }
#define MAKE_PRINTER_2(container) template <typename T1, typename T2> ostream& operator<<(ostream& os, const container<T1, T2>& t) { _print_collection(os, t.begin(), t.end()); return os; }
MAKE_PRINTER_1(vector)
MAKE_PRINTER_2(map)
MAKE_PRINTER_1(set)
MAKE_PRINTER_2(unordered_map)
MAKE_PRINTER_1(unordered_set)
#undef MAKE_PRINTER_1
#undef MAKE_PRINTER_2




template <typename T, enable_if_t<!has_read<T>::value, int> = 0> T read() { T e; cin >> e; return e; }
template <typename T, enable_if_t<has_read<T>::value, int> = 0> T read() { T t; t._read(); return t; }
void read() {}
template <typename T, typename ...Ts> void read(T& v, Ts& ...ts) { v = read<T>(); read(ts...); }
template <typename T> vector<T> readv(i64 n) { vector<T> v; readv(n, v); return v; }
template <typename T> void readv(i64 n, vector<T>& v) { for (i64 i = 0; i < n; i++) v.push_back(read<T>()); }
#define PRINTERS(FNAME, OUTP) \
    void FNAME() {} \
    template <typename T> void FNAME(const T& t) { OUTP << t; } \
    template <typename T1, typename T2, typename ...Ts> \
    void FNAME(const T1& t1, const T2& t2, const Ts& ...ts) { OUTP << t1 << ' '; FNAME(t2, ts...); } \
    template <typename ...Ts> \
    void FNAME##ln(const Ts& ...ts) { FNAME(ts...); FNAME('\n'); } \
    template <typename T, typename F> void FNAME##v(const T& t, F f) { for (i64 i = 0; i < isize(t); i++) if (i == isize(t) - 1) FNAME(f(t[i])); else FNAME(f(t[i]), ""); FNAME##ln(); } \
    template <typename T> void FNAME##v(const T& t) { FNAME##v(t, fun::identity<typename T::value_type>); }
PRINTERS(print, cout)
#ifdef DEBUG_PRINTS
    PRINTERS(dprint, cerr)
#else
# define dprint(...)
# define dprintv(...)
# define dprintln(...)
#endif




template <i64 p_>
struct ValModulo {
    ValModulo(i64 v = 0, bool can_modulo = false) : can_modulo_(can_modulo), res_(v) {}
    void operator=(i64 v) { res_ = v; }
    ValModulo<p_>& operator=(const ValModulo<p_>& v) = default;
    void operator+=(i64 v) { assert(v >= 0); if (imax - res_ < v) mod_(); res_ += v; }
    void operator*=(i64 v) { assert(v >= 0); if (imax / res_ < v) mod_(); res_ *= v; }
    void operator-=(i64 v) { assert(v <= res_); res_ -= v; }
    void operator/=(i64 v) { assert(v > 0); massert(res_ % v == 0 || can_total_div_, "not divisible values"); massert(!can_modulo_, "can't divide after mod operation"); res_ /= v; }
    i64 get() const { return res_; }
    i64 getmod() const { return res_ % p_; }
    operator i64() const { return res_; }
    friend ostream& operator<<(ostream& os, const ValModulo& v) { return os << v.res_; }
    void enable_modulo() { can_modulo_ = true; }
    void enable_total_div() { can_total_div_ = true; }
    bool try_divide(i64 v) { if (res_ % v == 0) { *this /= v; return true; } return false; }
private:
    void mod_() { massert(can_modulo_ && res_ >= p_, "overflow"); res_ %= p_; }
    bool can_modulo_ = false;
    bool can_total_div_ = false;
    i64 res_;
public:
    string _repr() const { return repr(res_); }
    string _str() const { return str(res_); }
    void _read() { read(res_); }
};
template <i64 p>
i64 num_of_subsets(i64 set_size, i64 subset_size) {
    using Val = ValModulo<p>;
    assert(subset_size >= 0 && subset_size <= 4);
    if (subset_size > set_size)
        return 0;
    if (subset_size == 0 || subset_size == set_size)
        return 1;
    if (subset_size == 0)
        return 0;
    if (subset_size == 1)
        return set_size;
    Val res1 = set_size, res2 = set_size - 1;
    if (subset_size >= 2)
        res1.try_divide(2) || res2.try_divide(2);
    if (subset_size >= 3) {
        res1 *= set_size - 2;
        res1.try_divide(3) || res2.try_divide(3);
    }
    if (subset_size >= 4) {
        res2 *= set_size - 3;
        res1.try_divide(4) || res2.try_divide(4);
    }
    res1.enable_modulo();
    res1 *= res2;
    return res1.getmod();
}


u64 fast_pow(u64 x, u64 pw, u64 modp) {
    u64 r = 1;
    if (pw % 2)
        r = x % modp;
    if (pw > 1) {
        u64 prev = fast_pow(x, pw / 2, modp);
        r = ((r * prev) % modp) * prev % modp;
    }
    return r;
}


struct Rng {
    u64 l;
    u64 r;
    u64 len() const { assert(r >= l); return r - l + 1; }
    bool belongs(u64 l0) const { return l0 >= l && l0 <= r; }
};

struct StupidVal {
    Rng rng;
    u64 value;
};

class RangesRange {
private:
    template <typename It>
    It find_best_(It it, u64 l) {
        while (it->first >= l)
            it--;
        while (it->first < l)
            it++;
        return it;
    }
    template <typename It>
    It put_in_(It it, StupidVal val) {
        it = find_best_(it, val.rng.l);
        if (it->first == val.rng.l)
            it->second = val;
        else
            it = ranges_.insert(it, make_pair(val.rng.l, val));
        return it;
    }
    auto prepare_border_(u64 l) {
        auto it = --ranges_.upper_bound(l);
        if (it->second.rng.l == l) return it;
        const auto value = it->second.value;
        const Rng rng1{it->second.rng.l, l - 1};
        const Rng rng2{l, it->second.rng.r};
        it = put_in_(it, StupidVal{rng1, value});
        return put_in_(it, StupidVal{rng2, value});
    }
public:
    RangesRange(std::map<u64, StupidVal>& ranges, u64 l, u64 r) : ranges_(ranges), rng_{l, r} {}
    auto begin() {
        auto it = prepare_border_(rng_.l);
        prepare_border_(rng_.r + 1);
        return find_best_(it, rng_.l);
    }
    template <typename It>
    It next(It it) {
        return ++it;
    }
    template <typename It>
    bool end(It it) {
        return it->first > rng_.r;
    }
    auto erase_all() {
        auto it1 = prepare_border_(rng_.l);
        auto it2 = prepare_border_(rng_.r + 1);
        it1 = find_best_(it1, rng_.l);
        it2 = find_best_(it2, rng_.r + 1);
        return ranges_.erase(it1, it2);
    }
    auto set_value(u64 value) {
        auto it = erase_all();


        return put_in_(it, StupidVal{rng_, value});
    }
private:
    std::map<u64, StupidVal>& ranges_;
    Rng rng_;
};

class NewStupidThing {
public:
    NewStupidThing(vector<u64> init_vals) {
        init_vals.insert(init_vals.begin(), 0);
        init_vals.insert(init_vals.end(), 0);
        for (u64 i = 0; i < init_vals.size(); i++)
            ranges_.insert(ranges_.end(), make_pair(i, StupidVal{Rng{i, i}, init_vals[i]}));
    }
    void add_x(u64 l, u64 r, u64 x) {
        RangesRange rr(ranges_, l, r);
        auto it = rr.begin();
        while (!rr.end(it)) {
            it->second.value += x;
            it = rr.next(it);
        }
    }
    void assign_x(u64 l, u64 r, u64 x) {
        RangesRange rr(ranges_, l, r);
        rr.set_value(x);
    }
    u64 get_kth(u64 l, u64 r, u64 k) {
        RangesRange rr(ranges_, l, r);
        auto it = rr.begin();
        vector<StupidVal> vals;
        while (!rr.end(it)) {
            vals.push_back(it->second);
            it = rr.next(it);
        }
        sort(vals.begin(), vals.end(), [](auto& v1, auto& v2) { return v1.value < v2.value; });
        for (auto& val : vals) {
            auto len = val.rng.len();
            if (len >= k)
                return val.value;
            k -= len;
        }
        assert(false);
        return 0;
    }
    u64 get_sum_of_powers(u64 l, const u64 r, u64 modp, u64 pw) {
        RangesRange rr(ranges_, l, r);
        u64 res = 0;
        auto it = rr.begin();
        while (!rr.end(it)) {
            res = (res + ((it->second.rng.len() % modp) * fast_pow(it->second.value, pw, modp) % modp) ) % modp;
            it = rr.next(it);
        }
        return res;
    }
    void debug_print() {
        for (auto e : ranges_) {
            dprintln("stupidval", e.second.rng.l, e.second.rng.r, e.second.value);
        }
    }
private:
    std::map<u64, StupidVal> ranges_;
};

u64 n, m, seed, vmax;
u64 rnd() {
    auto ret = seed;
    seed = (seed * 7 + 13) % (1000 * 1000 * 1000 + 7);
    return ret;
}

void go() {












    read(n, m, seed, vmax);
    vector<u64> v;
    for (u64 i = 1; i <= n; i++)
        v.push_back((rnd() % vmax) + 1);
    NewStupidThing thing(v);
    thing.debug_print();
    for (u64 i = 1; i <= m; i++) {
        auto op = rnd() % 4 + 1;
        auto l = rnd() % n + 1;
        auto r = rnd() % n + 1;
        if (l > r)
            swap(l, r);
        if (op == 1) {
            auto x = rnd() % vmax + 1;
            thing.add_x(l, r, x);
            dprintln("add x", l, r, x);
        } else if (op == 2) {
            auto x = rnd() % vmax + 1;
            thing.assign_x(l, r, x);
            dprintln("assign x", l, r, x);
        } else if (op == 3) {
            auto k = rnd() % (r - l + 1) + 1;
            dprintln("get kth", l, r, k);
            println(thing.get_kth(l, r, k));
        } else if (op == 4) {
            auto pw = rnd() % vmax + 1;
            auto modulo_p = rnd() % vmax + 1;
            dprintln("get sum", l, r, modulo_p, pw);
            println(thing.get_sum_of_powers(l, r, modulo_p, pw));
        }
        thing.debug_print();
    }
}


int main () { 

    ios_base::sync_with_stdio(0);
    go();
} 

