﻿



































_L <_T T, typename LESS = std::less<T>> using set2 = __gnu_pbds::tree<T, __gnu_pbds::null_type, LESS, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;
_L <_T T, typename LESS = std::greater<T>> using id13 = __gnu_pbds::tree<T, __gnu_pbds::null_type, LESS, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;
_L <_T T, typename TV, typename LESS = std::less<T>> using map2 = __gnu_pbds::tree<T, TV, LESS, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;
_L <_T T, typename LESS = std::less_equal<T>> using id0 = __gnu_pbds::tree<T, __gnu_pbds::null_type, LESS, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>; 

_L <_T T, typename LESS = std::greater_equal<T>> using id10 = __gnu_pbds::tree<T, __gnu_pbds::null_type, LESS, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>; 

_L <_T T, class LESS = std::less<T>> using pq2 = __gnu_pbds::priority_queue<T, LESS, __gnu_pbds::pairing_heap_tag>; 

_L <_T T> using id15 = pq2<T, std::greater<T>>;




using namespace std;




using INT = int;
using DOUBLE = double;


using ll = __int128;

using ll = long long int;



using ld = __float128;

using ld = long double;


using ld_base = long double;

static const ll INF = std::numeric_limits<ll>::max() / 2 - 10; 

static const int INFi = std::numeric_limits<int>::max() - 10;

template<typename T> using vec = std::vector<T>;
template<typename T1, typename T2> using vecpair = std::vector<std::pair<T1, T2>>; 

template<typename T> using vecvec = std::vector<std::vector<T>>;


template<typename T> using priority_queue_gr = std::priority_queue<T, std::vector<T>, std::greater<T>>;
using vecll = vec<ll>; using setll = set<ll>; using mapll = map<ll, ll>; using pairll = std::pair<ll, ll>;






template<typename TVal, int D = 2> class md {
    int koeff[D]; using IterEnd = int;
    auto size_for_level(int lvl) { return lvl - 1 < 0 ? 1 : koeff[lvl] / koeff[lvl - 1]; }
    template<typename T> decltype(auto) __next(T&& t, int ind) { return t[ind]; }
    template<typename T, typename ... Types> decltype(auto) __next(T&& t, int ind, Types... var2) { return __next(t[ind], var2...); }
public:
    std::vector<TVal> vec; 

    template<typename ... Types> constexpr  md(Types... var2) { 

        static_assert(D == sizeof...(var2)); int ind = 0; int id20 = 1; int tmps = 0;
        auto inner = [&](const auto& v) {id20 *= v; koeff[ind++] = id20; };
        ((inner(var2), tmps) = ...); vec.resize(id20);
    }
    void fill(const TVal& val) { std::fill(vec.begin(), vec.end(), val); }
    TVal sum() { return std::accumulate(vec.begin(), vec.end(), TVal(0)); }
    template<typename ... Types> decltype(auto) operator()(Types... var2) { 

        if constexpr (sizeof...(var2) < D) { return __next(*this, var2...); } else {
            static_assert(D == sizeof...(var2)); int ind = D - 2;  TVal& res = vec[((var2 * (ind < 0 ? 1 : koeff[ind--])) + ...)]; return res;
        }
    }
    template<int LEVEL, int DIR = 1> class Iter {
        friend md; int index = 0;  md* p;
        template<class U, int DELT = 0> using ITER = std::enable_if_t< (LEVEL - DELT > -1), U >;
        template<class U, int DELT = 0> using FLAT = std::enable_if_t< (LEVEL - DELT <= -1), U >;
        auto step(int lvl) { return (lvl < 0 ? 1 : p->koeff[lvl]); }
    public:
        auto size() { return p->size_for_level(LEVEL); }
        void advance(int i) { index += step(LEVEL) * i * DIR; }
        Iter& operator++() { advance(1); return *this; }
        bool operator!=(const IterEnd& other) const { return index != other; }
        template<typename U = Iter&> ITER<U> operator*() { return *this; }
        template<typename U = TVal&> FLAT<U> operator*() { return p->vec[index]; }
        template<typename U = Iter<LEVEL - 1>> ITER<U> begin() { Iter<LEVEL - 1> res;  res.p = p; res.index = index; return res; }
        template<typename U = IterEnd> ITER<U> end() { return p->koeff[LEVEL] + index; }
        template<typename U = Iter<LEVEL - 1, -1>> ITER<U> rbegin() { Iter<LEVEL - 1, -1> res;  res.p = p; res.index = index + p->koeff[LEVEL] - step(LEVEL - 1); return res; }
        template<typename U = IterEnd> ITER<U> rend() { auto res = index - step(LEVEL - 1);            return res; }
        template<typename U = Iter<LEVEL - 1>, int d = 1> ITER<U, d> operator[](int i) { auto it = begin(); it.advance(i); return it; }
        template<typename U = TVal&, int d = 1> FLAT<U, d> operator[](int i) { return p->vec[index + i]; }
        template<typename ... Types> decltype(auto) operator()(Types... var2) { static_assert(sizeof...(var2) <= LEVEL + 1); return p->__next(*this, var2...); }
    };
    auto begin() { Iter<D - 2> res; res.p = this; return res; } IterEnd end() { return koeff[D - 1]; }
    auto rbegin() { Iter<D - 2, -1> res; res.p = this; res.index = koeff[D - 1] - koeff[D - 2]; return res; }  IterEnd rend() { return -koeff[D - 2]; }
    auto operator[](int i) { auto it = begin(); it.advance(i); return it; }
    auto size() { return size_for_level(D - 1); }
};








template<class T> struct id24 {
    using Iter = decltype(std::begin(std::declval<T&>()));
    using Iter_end = decltype(std::end(std::declval<T&>()));
    using IterRef = decltype(*std::declval<Iter&>());
    ll i = 0; Iter iter; Iter next; Iter_end iter_end;
    void init(T& cont) { iter = std::begin(cont); iter_end = std::end(cont); }
    id24(T& cont) { init(cont); }  id24(T&& cont) { init(cont); }
    bool check_last() { next = iter; ++next; return !(next != iter_end); }
    auto& begin() { return *this; } int end() { return 0; }
    void operator++() { iter = next; ++i; }  bool operator!=(int) { return iter != iter_end; }
    std::tuple<IterRef, ll, bool> operator*() { return { *iter, i, check_last() }; }
};
template<class T> struct id9 {
    using Iter = decltype(std::rbegin(std::declval<T&>()));
    using Iter_end = decltype(std::rend(std::declval<T&>()));
    using IterRef = decltype(*std::declval<Iter&>());
    ll i; Iter iter; Iter_end iter_end; ll n;
    void init(T& cont) { iter = cont.rbegin(); iter_end = cont.rend(); n = cont.size(); i = n - 1; }
    id9(T& cont) { init(cont); } id9(T&& cont) { init(cont); }
    auto& begin() { return *this; } int end() { return 0; }
    void operator++() { ++iter; --i; } bool operator!=(int) { return iter != iter_end; }
    std::tuple<IterRef, ll, bool> operator*() { return { *iter, i, i == n - 1 }; }
};
template<> struct id24<ll> {
    ll i; ll n;
    id24(ll c):n(c) { i = 0; }
    auto& begin() { return *this; } int end() { return 0; }
    void operator++() { ++i; } bool operator!=(int) { return i != n; }
    std::tuple<ll, ll, bool> operator*() { return { i, i, i == n - 1 }; }
};
template<> struct id9<ll> {
    ll i; ll n;
    id9(ll c):n(c) { i = n - 1; }
    auto& begin() { return *this; } int end() { return 0; }
    void operator++() { --i; } bool operator!=(int) { return i >= 0; }
    std::tuple<ll, ll, bool> operator*() { return { i, i, i == n - 1 }; }
};
id24(int)->id24<ll>;
id9(int)->id9<ll>;













































template<class T> void rem_index(T& cont, int index) { cont.erase(cont.begin() + index); }
template<class T> ll id11(T& cont, const typename T::value_type& val) { auto newEnd = std::remove(all(cont), val); ll cnt = cont.end() - newEnd; cont.erase(newEnd, cont.end()); return cnt; }
template<class T, class V> bool id7(T& cont, const V& val) { auto itr = std::find(cont.begin(), cont.end(), val);  if (itr != cont.end()) { cont.erase(itr); return true; } return false; }
template<class T> void sort(pair<T, T>& p) { if (p.first > p.second) std::swap(p.first, p.second); }


template<class T> void sort(T& v) { std::sort(all(v)); }
template<class T> void stable_sort(T& v) { std::stable_sort(all(v)); }
template<class T> void reverse(T& v) { std::reverse(all(v)); }
template <template<class> class H, class S> auto max_element(const H<S>& v) { return *std::max_element(all(v)); }
template <template<class> class H, class S> auto min_element(const H<S>& v) { return *std::min_element(all(v)); }
template <template<class> class H, class S> auto accumulate(const H<S>& v) { return std::accumulate(all(v), (S)0); }
template<class T> void swap_ranges(vec<T>& v, ll start, ll len, ll index2) {
    assert(index2 + len <= start || index2 >= start + len); assert(start + len <= v.size() && index2 + len <= v.size());
    swap_ranges(v.begin() + start, v.begin() + start + len, v.begin() + index2);
}








template <class T> using set_gr = set<T, greater<T>>;
template <class T> using multiset_gr = multiset<T, greater<T>>;







using namespace std::string_literals;
std::string operator*(const std::string& s, ll count) { std::string res; res.reserve(s.size() * count);  while (count-- > 0) { res += s; }  return res; }
static inline void ltrim(std::string& s) { s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](unsigned char ch) { return !std::isspace(ch); })); }
static inline void rtrim(std::string& s) { s.erase(std::find_if(s.rbegin(), s.rend(), [](unsigned char ch) { return !std::isspace(ch); }).base(), s.end()); }
static inline void trim(std::string& s) { ltrim(s);  rtrim(s); }















ll ipow(ll v, ll p) { assert(p >= 0); ll res = 1; while (p-- > 0) { res *= v; } return res; }
ll ilog_up(ll n, ll k) { assert(k > 1); ll test = 1; ll cnt = 0; while (test < n) { test *= k;  ++cnt; } return  cnt; } 

ll ilog(ll n, ll k) { assert(k > 1); ll test = 1; ll cnt = 0; while (test < n) { test *= k;  ++cnt; } if (test != n) { cnt--; } return  cnt; } 



ll div_up(ll a, ll b) { ll res = a / b; if (res * b != a) res++; return res; } 

ll id8(ll n) { if (n <= 0) return 0; return (n * n + n) / 2; }






ll round_up(ld val) { return ceill(val); }








ll id3(ll l, ll r, ll x) { assert(x > 1); assert(l >= 0); assert(l <= r); return r / x - (l - 1) / x; }

template<class T> pair<T, T> intersect(const pair<T, T>& a, const pair<T, T>& b) { 

    auto res = std::make_pair(std::max(a.first, b.first), std::min(a.second, b.second)); if (res.second < res.first) { return { INF, INF }; } return res;
}
ll parity(ll a) { return a & 1; }; 

bool id23(ll a, ll b) { return ((a + b) & 1) == 0; }



















ll fact(ll n) { ll res = 1; for (ll i = 2; i <= n; i++) res *= i; return res; }



ll id19(ll n, ll k) { return fact(n) / (fact(k) * fact(n - k)); }



ll id2(ll n, ll k) { return fact(n) / fact(n - k); }






bool s_test(ll s, ll nth) { return (s & (1 << nth)) != 0; }
ll s_bit(ll nth) { return (1 << nth); }; 

void s_on(ll& s, ll nth) { s |= (1 << nth); }
void s_off(ll& s, ll nth) { s &= ~(1 << nth); }

ll id16(ll s) { return __builtin_popcountll(s); }             

ll id14(ll count) { return (1 << (count)) - 1; }       

ll id25(ll val) { ll c = 1; while (c <= val) c <<= 1; c--; return c; } 













template <typename First, typename... T> bool is_in(const First&& first, const T&&... t) { return ((first == t) || ...); }
_L <_T L, _T... R> L min(const L& l, R&&... right) { L a = l; auto f = [&a](const auto& v) {if (v < a) a = v; }; ((f(right)), ...); return a; }
_L <_T L, _T... R> L max(const L& l, R&&... right) { L a = l; auto f = [&a](const auto& v) {if (v > a) a = v; }; ((f(right)), ...); return a; }
_L <_T L, _T... R> const L& min2(L& l, R&&... right) { auto f = [&l](const auto& v) {if (v < l) l = v; }; ((f(right)), ...); return l; }
_L <_T L, _T... R> const L& max2(L& l, R&&... right) { auto f = [&l](const auto& v) {if (v > l) l = v; }; ((f(right)), ...); return l; }




namespace __rnd { std::random_device rd1; std::default_random_engine e2(rd1());   }



ll rand(ll min, ll max) { std::uniform_int_distribution<ll> d(min, max); return d(__rnd::e2); }



template<class bidiiter> void id22(bidiiter begin, bidiiter end, size_t num_random) {
    size_t left = std::distance(begin, end);
    assert(left >= num_random);
    while (num_random--) {
        bidiiter r = begin;
        std::advance(r, rand(0, left - 1)); std::swap(*begin, *r);     ++begin;     --left;
    }
}

auto rand_prob() { std::uniform_real_distribution<ld_base> d(0, 1); return d(__rnd::e2); }






struct Tokenizer {
    string s;
    template<class ... Types> void add(Types ... vars) { (add(vars), ...); }
    template<class T> void add(T&& v) { s += to_string(v);  s += "_"; }
    void addline() { s += "|"; }
};



class Timer {
    using sc = std::chrono::steady_clock;  sc::time_point start;
public:
    Timer():start(sc::now()) {}
    ll elapsedMs() { return std::chrono::duration_cast<std::chrono::milliseconds>(sc::now() - start).count(); }
};




class bs {
    using tfunc = const std::function<bool(ll)>;
    using tfunc_range = const std::function<bool(ll, ll)>;
    static ll __find_first(ll l, ll r, tfunc& f) {
        if (l >= r) return f(l) ? l : l + 1;
        ll mid = (r + l) / 2;
        if (f(mid)) return __find_first(l, mid - 1, f);
        else return __find_first(mid + 1, r, f);
    }
public:
    static ll find_first(ll l, ll r, tfunc& f) { 

        assert(l <= r);
        auto i = __find_first(l, r, f);
        return i == r + 1 ? INF : i;
    }
    static ll find_last(ll l, ll r, tfunc& f) { 

        assert(l <= r);
        tfunc f_rev = [&f](ll i) {return !f(i); };
        auto i = __find_first(l, r, f_rev) - 1;
        return i == l - 1 ? INF : i;
    }
    static ll find_check_range(ll l, ll r, tfunc_range& f) {  

        assert(l <= r);
        if (l >= r) { return (f(l, l) ? l : INF); }
        ll mid = (r + l) / 2;
        if (f(l, mid)) return find_check_range(l, mid, f);
        else return find_check_range(mid + 1, r, f);
    }
};




static ll __MOD = 1'000'000'007;
class llmod {
    static ll pow_r(ll base, ll exp) {
        base = mod(base);
        ll result = 1;
        for (; exp > 0; exp >>= 1) { if (exp & 1) result = mod(result * base); base = mod(base * base); }
        return result;
    }
    static ll mod(ll v) { if (v >= __MOD) return v % __MOD; return v; }
    static ll inv(ll a) { assert(a != 0); return pow_r(a, __MOD - 2); } // work only with MOD = prime    
    static ll fact_r(ll n) { ll res = 1; for (ll i = 2; i <= n; i++) { res = mod(res * i); } return res; }
public:
    static void set2() { __MOD = 998'244'353; }
    static llmod c_komb(ll n, ll k) {  // work only with MOD = prime (ksandr1v)
        if (n < k) return 0;
        return fact_r(n) * mod(pow_r(fact_r(k), __MOD - 2) * pow_r(fact_r(n - k), __MOD - 2));
    }
    static llmod pow(ll base, ll exp) { return pow_r(base, exp); }
    static llmod fact(ll n) { return fact_r(n); }
    ll val = 0;
    llmod(ll v): val(mod(v)) {}    llmod() {}
    llmod& operator+=(const llmod& rhs) { *this = *this + rhs; return *this; }
    llmod& operator-=(const llmod& rhs) { *this = *this - rhs; return *this; }
    llmod& operator*=(const llmod& rhs) { *this = *this * rhs; return *this; }
    llmod& operator/=(const llmod& rhs) { llmod v = inv(rhs.val); return(*this) *= v; }
    llmod operator+(const llmod& rhs) { return llmod(val + rhs.val + __MOD); }
    llmod operator-(const llmod& rhs) { return llmod(val - rhs.val + __MOD); }
    llmod operator*(const llmod& rhs) { return llmod(val * rhs.val); }
    llmod operator/(const llmod& rhs) { llmod tmp(*this); tmp /= rhs; return tmp; }
};
std::ostream& operator<<(std::ostream& stream, const llmod& val) { stream << val.val;    return stream; }

// ---------------------- CORE

extern const char* INPUT_DATA;


class InnerReader {
    std::istringstream iss; std::string input;
public:
    InnerReader(const char* rawInput): input(rawInput) { trim(input);  iss = std::istringstream(input); }
    bool hasInput() { return !input.empty() && !iss.eof(); }
    int pos() { return iss.tellg(); }
    template<class T> T getNext() { assert(hasInput()); T val; iss >> val; return val; }
};
InnerReader __reader(INPUT_DATA);


bool id5 = false;
template<class T> T id1() { T val; std::cin >> val; return val; }
template<class T> T __get() {

    if (id5) return id1<T>();
    return __reader.getNext<T>();

    return id1<T>();

}

ll get_ll() { return __get<ll>(); }
std::string get_string() { return __get<std::string>(); }

template<class T> void print(const T& val);
void endl() { std::cout << "\n"; }
void space() { std::cout << ' '; }
void flush() { std::cout << std::flush; }

template<class T, class Q> std::ostream& operator<<(std::ostream& stream, const pair<T, Q>& val) {
    print(val.first);    space();    print(val.second); return stream;
}
template<class T> std::ostream& operator<<(std::ostream& stream, const std::vector<T>& v) {
    fe(e, v) { print(e);  if (!e_last) { space(); } } return stream;
}
template<class T> void print(const T& val) { std::cout << val; }
template<class T> void print_sp(const T& val) { print(val); space(); }
template<class T, class ... Types> void print(const T& var, const Types&...var2) { print(var); space(); print(var2...); }
template<class T, class ... Types> void line(const T& var, const Types&...var2) { print(var, var2...); endl(); }








ll id18 = 1;
void onetime(); void prepare();
void task();
void __task() { try { task(); } catch (int& a) {} }
void tcase() {

    if (!id5 && !__reader.hasInput()) __task();
    else {

        id18 = get_ll(); while (id18 > 0) { __task(); id18--; };

    }

}

void done() { throw 1; } 

template<class T, class ... Types> void done(const T& var, const Types&...var2) { line(var, var2...); done(); }





extern bool id12;
int main(int argc, char* argv[]) {

    if (argc > 1) { freopen(argv[1], "r", stdin); id5 = true; } else if (id5) { freopen("in.txt", "r", stdin); }


    bool isDebug = false;

    isDebug = true;

    line("--------------------", isDebug ? "" : "RELEASE");
    Timer timer;

    prepare(); onetime();
    if (id12) tcase(); else __task();

    while (!id5 && __reader.hasInput()) { int curp = __reader.pos(); __task(); if (__reader.pos() == curp) break; }
    line("\nExecution time:", timer.elapsedMs());

    return 0;
}

void prepare() {

    std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr);  std::cout.tie(nullptr);

    std::cout.precision(17);
}









void onetime() {
}

bool id12 = false;


template <class tnode, class tpacket>
class id17 {
    int n; int htree;
    std::vector<tnode> tree; std::vector<tpacket> packets; std::vector<uint8_t> has;
    tnode& ref(int p) { return tree[p]; }
    tnode join(const tnode& left, const tnode& right) { tnode res = left; res.append(right); return res; }
    tnode join(int p1, int p2) { return join(ref(p1), ref(p2)); }
    void pull(int p) { ref(p) = join(p << 1, p << 1 | 1); }
    using tfind = const std::function<bool(const tnode&)>;
    int calc_h_for_childs(int p) {
        int h = -1;
        for (; p < n; p <<= 1, h++);
        return h;
    }
    int find_first_in_perfect(int p, tfind& f) {
        int h = calc_h_for_childs(p);
        for (; p < n; h--) {
            droptochilds(p, h);
            p <<= 1;
            if (!f(ref(p))) { p += 1;  if (!f(ref(p))) return -1; }
        }
        return p - n;
    }
    void apply(int p, const tpacket& value, int h) {
        if (p < n) {
            int l = (p << h) - n;
            int k = 1 << h;
            if (has[p]) {
                const tpacket& old = packets[p];
                packets[p] = ref(p).apply_join_packet(old, value, l, k);
            } else {
                ref(p).apply(value, l, k);
                packets[p] = value;
                has[p] = true;
            }
        } else {
            assert(h == 0);
            ref(p).apply(value, p - n, 1);
        }
    }
    void droptochilds(int p, int h) {
        if (has[p]) {
            apply(p << 1, packets[p], h);
            apply(p << 1 | 1, packets[p], h);
            has[p] = false;
        }
    }
    void push(int p) { for (int s = htree; s > 0; --s) { droptochilds(p >> s, s - 1); } }
    void push_range(int l, int r) { push(l); if (l != r - 1) { push(r - 1); } }
    void build(int p) { while (p > 1) { p >>= 1;  if (!has[p]) { pull(p); } } }
    void build_range(int l, int r) { build(l);  if (l != r - 1)  build(r - 1); }
    

    void fullbuild() {
        

        for (int p = n - 1; p > 0; --p) { pull(p); }
    }
public:
    struct Iter {
        id17<tnode, tpacket>* parent;
        int cur = 0;
        bool operator!=(int v) { return cur < v; }
        void operator++() { cur++; }
        tnode operator*() { return parent->query(cur); }
    };
    Iter begin() { return { this }; }
    int end() { return size(); }
    bool debug_check_nodes() {
        for (int p = n - 1; p > 0; --p) {
            if (!has[p]) {
                auto tmp = join(p << 1, p << 1 | 1);
                if (tmp != ref(p)) { return false; }
            } else {
                auto p1 = ref(p << 1);
                auto p2 = ref(p << 1 | 1);
                int h = calc_h_for_childs(p);
                p1.apply(packets[p], h);
                p2.apply(packets[p], h);
                auto tmp = tnode::join(p1, p2);
                auto our = ref(p);
                if (tmp != our) { return false; }
            }
        }
        return true;
    }
    int find_first(int l, int r, tfind& f) { 

        r++;
        assert(r <= n && l <= r && l >= 0);
        if (l == r) return -1;
        l += n; r += n;
        push_range(l, r);
        int rarr[32];
        int ind = 0;
        for (; l < r; l >>= 1, r >>= 1) {
            if (l & 1) {
                if (f(ref(l))) { return find_first_in_perfect(l, f); }
                l++;
            }
            if (r & 1) { r--; rarr[ind++] = r; }
        }
        for (; ind > 0; --ind) {
            int r = rarr[ind - 1];
            if (f(ref(r)))
                return find_first_in_perfect(r, f);
        }
        return -1;
    }
    size_t size() { return n; }
    id17(int n_, bool id6 = true):htree(0), n(n_) {
        if (id6) { n = 1;   while (n < n_) n <<= 1; }
        for (int i = n; i > 1; i >>= 1) htree++;
        tree.resize(n * 2ll);
        packets.resize(n);
        has.resize(n);
        fullbuild();
    }
    void modify(int p, tnode val) {
        assert(p >= 0 && p < n);
        p += n;
        push(p);
        ref(p) = std::move(val);
        build(p);
    }
    tnode query(int i) { return query(i, i); }
    tnode query(int l, int r) { 

        r++;
        assert(r <= n && l <= r && l >= 0);
        l += n; r += n;
        tnode resl;
        tnode resr;
        bool has_l = false;
        bool has_r = false;
        if (l == r) return tnode();
        push_range(l, r);
        for (; l < r; l >>= 1, r >>= 1) {
            if (l & 1) {
                if (has_l)
                    resl.append(ref(l++));
                else {
                    has_l = true;
                    resl = ref(l++);
                }
            }
            if (r & 1) {
                if (has_r)
                    resr = join(ref(--r), resr);
                else {
                    has_r = true;
                    resr = ref(--r);
                }
            }
        }
        if (!has_l) {
            return resr;
        }
        if (has_r)
            resl.append(resr);
        return resl;
    }
    void ranged_set(int l, int r, const tpacket& value) { 

        r++;
        assert(r <= n && l <= r && l >= 0);
        if (l == r) return;
        l += n; r += n;
        int l0 = l, r0 = r;
        push_range(l, r);
        for (int h = 0; l < r; l >>= 1, r >>= 1, h++) {
            if (l & 1) apply(l++, value, h);
            if (r & 1) apply(--r, value, h);
        }
        build_range(l0, r0);
    }
    

    template<class... Args> void id21(int p, int h, Args&&... args) {
        

        

        

        

        auto& cur = ref(p); bool isleaf = p >= n;
        

        if (isleaf) return;
        int pl = p << 1;  int pr = p << 1 | 1;   auto& left = ref(pl);  auto& right = ref(pr);
        id21(pl, h - 1, args...);   id21(pr, h - 1, args...);
    }
    template<class... Args> void travel(int l, int r, Args&&... args) {
        l += n; r += n;
        for (int h = 0; l < r; l >>= 1, r >>= 1, h++) {
            if (l & 1) id21(l++, h, args...);
            if (r & 1) id21(--r, h, args...);
        }
    }
    template<class... Args>  void id4(Args&&... args) {
        assert((n & (n - 1)) == 0); id21(1, htree, args...);
    }
};

namespace op {
    using packet = ll;
    struct node { 

        ll val = 0;
        void append(const node& b) {
        }
        void apply(const packet& nw, int l, int k) {
            val = nw;
        }
        packet apply_join_packet(const packet& old, const packet& nw, int l, int k) {
            apply(nw, l, k);
            return nw;
        }
    };
}

using segtree = id17<op::node, op::packet>;

const char* INPUT_DATA = R"(

23
2 11
2 7
4 13
0 3
2 2
2 11
6 8
3 5
1 1
0 6
9 14
1 8
5 9
8 10
6 9
9 16
8 17
0 2
4 7
3 7
4 8
0 1
3 3


)";




void task() {
    geti(n);

    llmod::set2();

    segtree st(300005);

    fe(e, n) {
        geti(l, r);
        st.ranged_set(l, r, ei+1);
    }

    llmod res;
    fe(e, st) {
        if (e.val > 0) {
            auto top = n - e.val;
            ll k = top + 1;
            if (e.val == 1)
                k--;
            auto c = llmod::pow(2, k) * llmod::pow(3, n - 1-k);
            res += c;
        }
    }

    line(res);

}