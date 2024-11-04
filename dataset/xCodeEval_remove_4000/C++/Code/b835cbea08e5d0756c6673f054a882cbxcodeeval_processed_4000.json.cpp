



































_L <_T T, typename LESS = std::less<T>> using set2 = __gnu_pbds::tree<T, __gnu_pbds::null_type, LESS, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;
_L <_T T, typename LESS = std::greater<T>> using id14 = __gnu_pbds::tree<T, __gnu_pbds::null_type, LESS, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;
_L <_T T, typename TV, typename LESS = std::less<T>> using map2 = __gnu_pbds::tree<T, TV, LESS, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;
_L <_T T, typename LESS = std::less_equal<T>> using id1 = __gnu_pbds::tree<T, __gnu_pbds::null_type, LESS, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>; 

_L <_T T, typename LESS = std::greater_equal<T>> using id11 = __gnu_pbds::tree<T, __gnu_pbds::null_type, LESS, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>; 

_L <_T T, class LESS = std::less<T>> using pq2 = __gnu_pbds::priority_queue<T, LESS, __gnu_pbds::pairing_heap_tag>; 

_L <_T T> using id16 = pq2<T, std::greater<T>>;




using namespace std;




using INT = int; using DOUBLE = double;

using ll8 = __int128_t; using ld8 = __float128;
istream& operator>>(istream& is, ll8& v) { string s;    is >> s;    v = 0;    for (int i = 0; i < (int)s.size(); i++) { if (isdigit(s[i])) { v = v * 10 + s[i] - '0'; } }    if (s[0] == '-') { v *= -1; }    return is; }
ostream& operator<<(ostream& os, const ll8& v) { if (v == 0) { return (os << "0"); }  ll8 num = v;    if (v < 0) { os << '-';        num = -num; }    string s;    for (; num > 0; num /= 10) { s.push_back((char)(num % 10) + '0'); }    reverse(s.begin(), s.end());    return (os << s); }

using ll = long long int; using ld = long double;

static const ll INF = std::numeric_limits<ll>::max() / 2; 

static const int INFi = std::numeric_limits<int>::max() - 10;

template<typename T> using vec = std::vector<T>;
template<typename T1, typename T2> using vecpair = std::vector<std::pair<T1, T2>>; 

template<typename T> using vecvec = std::vector<std::vector<T>>;


template<typename T> using priority_queue_gr = std::priority_queue<T, std::vector<T>, std::greater<T>>; 

using vecll = vec<ll>; using setll = set<ll>; using mapll = map<ll, ll>; using pairll = std::pair<ll, ll>;
pairll operator+(const pairll& a, const pairll& b) { return { a.first + b.first, a.second + b.second }; }






template<typename TVal, int D = 2> class md {
    int koeff[D]; int koeff2[D]; using IterEnd = int;
    auto size_for_level(int lvl) { return lvl - 1 < 0 ? 1 : koeff[lvl] / koeff[lvl - 1]; }
    template<typename T> decltype(auto) __next(T&& t, int ind) { return t[ind]; }
    template<typename T, typename ... Types> decltype(auto) __next(T&& t, int ind, Types... var2) { return __next(t[ind], var2...); }
public:
    std::vector<TVal> vec; 

    template<typename ... Types> constexpr  md(Types... var2) { init(var2...); }
    template<typename ... Types> constexpr  md() { }
    template<typename ... Types> constexpr void init(Types... var2) { 

        static_assert(D == sizeof...(var2)); int ind = 0; int id21 = 1; int tmps = 0;
        auto inner = [&](const auto& v) {id21 *= v; koeff2[ind] = v; koeff[ind++] = id21; };
        ((inner(var2), tmps) = ...); vec.resize(id21);
    }
    void fill(const TVal& val) { std::fill(vec.begin(), vec.end(), val); }
    TVal sum() { return std::accumulate(vec.begin(), vec.end(), TVal(0)); }
    template<typename ... Types> decltype(auto) operator()(Types... var2) { 

        if constexpr (sizeof...(var2) < D) { return __next(*this, var2...); } else {
            static_assert(D == sizeof...(var2)); int ind = D - 2;  TVal& res = vec[((var2 * (ind < 0 ? 1 : koeff[ind--])) + ...)]; return res;
        }
    }
    template<typename ... Types> TVal& safe(Types... var2) { static_assert (sizeof...(var2) == D); int dd = D - 1; static TVal fake; if (((var2 < 0 || var2 >= koeff2[dd--]) || ...)) { fake = -1;  return fake; }  return (*this)(var2...); }
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
template <class... T> md(T... t) -> md<ll, sizeof...(T)>;






template<class T> struct id25 {
    using Iter = decltype(std::begin(std::declval<T&>()));
    using Iter_end = decltype(std::end(std::declval<T&>()));
    using IterRef = decltype(*std::declval<Iter&>());
    ll i = 0; Iter iter; Iter next; Iter_end iter_end;
    void init(T& cont) { iter = std::begin(cont); iter_end = std::end(cont); }
    id25(T& cont) { init(cont); }  id25(T&& cont) { init(cont); }
    bool check_last() { next = iter; ++next; return !(next != iter_end); }
    auto& begin() { return *this; } int end() { return 0; }
    void operator++() { iter = next; ++i; }  bool operator!=(int) { return iter != iter_end; }
    std::tuple<IterRef, ll, bool> operator*() { return { *iter, i, check_last() }; }
};
template<class T> struct id10 {
    using Iter = decltype(std::rbegin(std::declval<T&>()));
    using Iter_end = decltype(std::rend(std::declval<T&>()));
    using IterRef = decltype(*std::declval<Iter&>());
    ll i; Iter iter; Iter_end iter_end; ll n;
    void init(T& cont) { iter = cont.rbegin(); iter_end = cont.rend(); n = cont.size(); i = n - 1; }
    id10(T& cont) { init(cont); } id10(T&& cont) { init(cont); }
    auto& begin() { return *this; } int end() { return 0; }
    void operator++() { ++iter; --i; } bool operator!=(int) { return iter != iter_end; }
    std::tuple<IterRef, ll, bool> operator*() { return { *iter, i, i == n - 1 }; }
};
template<> struct id25<ll> {
    ll i; ll n;
    id25(ll c):n(c) { i = 0; }
    auto& begin() { return *this; } int end() { return 0; }
    void operator++() { ++i; } bool operator!=(int) { return i != n; }
    std::tuple<ll, ll, bool> operator*() { return { i, i, i == n - 1 }; }
};
template<> struct id10<ll> {
    ll i; ll n;
    id10(ll c):n(c) { i = n - 1; }
    auto& begin() { return *this; } int end() { return 0; }
    void operator++() { --i; } bool operator!=(int) { return i >= 0; }
    std::tuple<ll, ll, bool> operator*() { return { i, i, i == n - 1 }; }
};
id25(int)->id25<ll>; id10(int)->id10<ll>;
id25(const ll&)->id25<ll>; id10(const ll&)->id10<ll>;



























template<class T> void rem_index(T& cont, int index) { cont.erase(cont.begin() + index); }
template<class T> ll id12(T& cont, const typename T::value_type& val) { auto newEnd = std::remove(all(cont), val); ll cnt = cont.end() - newEnd; cont.erase(newEnd, cont.end()); return cnt; }
template<class T, class V> bool id8(T& cont, const V& val) { auto itr = std::find(cont.begin(), cont.end(), val);  if (itr != cont.end()) { cont.erase(itr); return true; } return false; }
template<class T> void sort(pair<T, T>& p) { if (p.first > p.second) std::swap(p.first, p.second); }


template<class T> void sort(T& v) { std::sort(all(v)); }
template<class T> void stable_sort(T& v) { std::stable_sort(all(v)); }
template<class T> void reverse(T& v) { std::reverse(all(v)); }


template <template<class> class H, class S> auto max(const H<S>& v) { return *std::max_element(all(v)); }
template <template<class> class H, class S> auto min(const H<S>& v) { return *std::min_element(all(v)); }
template <template<class> class H, class S> auto accumulate(const H<S>& v) { return std::accumulate(all(v), (S)0); }
template<class T> void swap_ranges(vec<T>& v, ll start, ll len, ll index2) { assert(index2 + len <= start || index2 >= start + len); assert(start + len <= v.size() && index2 + len <= v.size()); swap_ranges(v.begin() + start, v.begin() + start + len, v.begin() + index2);}
template<class T> void ensure_size(T& v, int sz) { if (v.size() < sz) v.resize(sz); }





template <class T> using set_gr = set<T, greater<T>>;
template <class T> using multiset_gr = multiset<T, greater<T>>; 









template<class T> struct Tracker__ {
    T val; ll index;
    void operator=(const T& v) { val = v; }
    Tracker__():val(0), index(0) {}
    Tracker__(const T& v, ll i):val(v), index(i) {};
    bool operator< (const Tracker__& t) const { return val < t.val; }
    bool operator> (const Tracker__& t) const { return val > t.val; }
};
using Tracker = Tracker__<ll>;
template<class T> auto sort_track(const T& v) { vec<Tracker__<T>> v2; v2.reserve(v.size());  fe(e, v) v2.emplace_back(e, ei); sort(v2); return v2; }




using namespace std::string_literals;
std::string operator*(const std::string& s, ll count) { std::string res; res.reserve(s.size() * count);  while (count-- > 0) { res += s; }  return res; }
static inline void ltrim(std::string& s) { s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](unsigned char ch) { return !std::isspace(ch); })); }
static inline void rtrim(std::string& s) { s.erase(std::find_if(s.rbegin(), s.rend(), [](unsigned char ch) { return !std::isspace(ch); }).base(), s.end()); }
static inline void trim(std::string& s) { ltrim(s);  rtrim(s); }















ll ipow(ll v, ll p) { assert(p >= 0); ll res = 1; while (p-- > 0) { res *= v; } return res; }
ll ilog_up(ll n, ll k) { assert(k > 1); ll test = 1; ll cnt = 0; while (test < n) { test *= k;  ++cnt; } return  cnt; } 

ll ilog(ll n, ll k) { assert(k > 1); ll test = 1; ll cnt = 0; while (test < n) { test *= k;  ++cnt; } if (test != n) { cnt--; } return  cnt; } 



ll div_up(ll a, ll b) { ll res = a / b; if (res * b != a) res++; return res; } 

ll id9(ll n) { if (n <= 0) return 0; return (n * n + n) / 2; }






ll round_up(ld val) { return ceill(val); }








ll id5(ll l, ll r, ll x) { assert(x > 1); assert(l >= 0); assert(l <= r); return r / x - (l - 1) / x; }

template<class T> pair<T, T> intersect(const pair<T, T>& a, const pair<T, T>& b) { 

    auto res = std::make_pair(std::max(a.first, b.first), std::min(a.second, b.second)); if (res.second < res.first) { return { INF, INF }; } return res;
}
ll parity(ll a) { return a & 1; }; 

bool id24(ll a, ll b) { return ((a + b) & 1) == 0; }
























ll fact(ll n) { ll res = 1; for (ll i = 2; i <= n; i++) res *= i; return res; }



ll id4(ll n, ll k) { assert(k <= n); ll res = 1; while (k > 0) { res *= n; n--; k--; } return res; }



ll id20(ll n, ll k) { return id4(n, k) / fact(k); }






bool s_test(ll s, ll nth) { return (s & (1 << nth)) != 0; }
ll s_bit(ll nth) { return (1 << nth); }; 

void s_on(ll& s, ll nth) { s |= (1 << nth); }
void s_off(ll& s, ll nth) { s &= ~(1 << nth); }

ll id19(ll s) { return __builtin_popcountll(s); }             

ll id15(ll count) { return (1 << (count)) - 1; }       

ll id26(ll val) { ll c = 1; while (c <= val) c <<= 1; c--; return c; } 













template <typename First, typename... T> bool is_in(const First&& first, const T&&... t) { return ((first == t) || ...); }
_L <_T L, _T R1, _T... R> L min(const L& l, R1&& r, R&&... right) { L a = l; auto f = [&a](const auto& v) {if (v < a) a = v; }; f(r); ((f(right)), ...); return a; }
_L <_T L, _T R1, _T... R> L max(const L& l, R1&& r, R&&... right) { L a = l; auto f = [&a](const auto& v) {if (v > a) a = v; }; f(r); ((f(right)), ...); return a; }
_L <_T L, _T... R> void min2(L& l, R&&... right) { auto f = [&l](const auto& v) {if (v < l) l = v; }; ((f(right)), ...); }
_L <_T L, _T... R> void max2(L& l, R&&... right) { auto f = [&l](const auto& v) {if (v > l) l = v; }; ((f(right)), ...); }




namespace __rnd {
    std::random_device rd1;

    std::default_random_engine e2(123);  

    std::default_random_engine e2(rd1());  

}



ll rand(ll min, ll max) { std::uniform_int_distribution<ll> d(min, max); return d(__rnd::e2); }



template<class bidiiter> void id22(bidiiter begin, bidiiter end, size_t num_random) {
    size_t left = std::distance(begin, end);
    assert(left >= num_random);
    while (num_random--) {
        bidiiter r = begin;
        std::advance(r, rand(0, left - 1)); std::swap(*begin, *r);     ++begin;     --left;
    }
}

auto rand_prob() { std::uniform_real_distribution<ld> d(0, 1); return d(__rnd::e2); }




class Timer { using sc = std::chrono::steady_clock;  sc::time_point start; public: Timer():start(sc::now()) {} ll elapsedMs() { return std::chrono::duration_cast<std::chrono::milliseconds>(sc::now() - start).count(); }};

template<class T> ll inv_cnt(const T& arr) { 

    id1<ll> check;  ll sum = 0;
    re(e, arr) { check.insert(e);  sum += check.order_of_key(e); }  return sum;
}




class bs {
    using tfunc = const std::function<bool(ll)>;
    using tfunc_range = const std::function<bool(ll, ll)>;
    static ll __find_first(ll l, ll r, tfunc& f) { if (l >= r) return f(l) ? l : l + 1; ll mid = (r + l) / 2; if (f(mid)) return __find_first(l, mid - 1, f); else return __find_first(mid + 1, r, f); }
public:
    

    static ll find_first(ll l, ll r, tfunc& f) { assert(l <= r); auto i = __find_first(l, r, f); return i == r + 1 ? INF : i; }
    

    static ll find_last(ll l, ll r, tfunc& f) { assert(l <= r); tfunc f_rev = [&f](ll i) {return !f(i); }; auto i = __find_first(l, r, f_rev) - 1; return i == l - 1 ? INF : i; }
    

    static ll find_check_range(ll l, ll r, tfunc_range& f) { assert(l <= r); if (l >= r) { return (f(l, l) ? l : INF); } ll mid = (r + l) / 2; if (f(l, mid)) return find_check_range(l, mid, f); else return find_check_range(mid + 1, r, f); }
};




template <class TData = ll, class Packet = ll> class Cartesian {
    using TRnd = uint32_t;
    struct Node { int cnt = 1; TData node; Node* left = nullptr; Node* right = nullptr; Packet pack; bool haspack = false; TData common; bool reversy = false; TRnd prior; Node(const TData& nd):node(nd), common(nd) {} ~Node() { delete left; delete right; } };
public:
    using item = Node; using pitem = item*;
    using App = function<void(TData& a, const TData& b)>;  App append;
    function<void(Packet& a, const Packet& b)> merge_pac = [](Packet& a, const Packet& b) {a = b; };
    function<void(TData& a, const Packet& b)> apply = [](TData& a, const Packet& b) { a = b; };
    int cnt = 1; 

private:
    static TRnd rand_prior() { std::uniform_int_distribution<TRnd> d; auto res = d(__rnd::e2); return res; }
    static int cnt_safe(pitem it) { return it ? it->cnt : 0; }
    static void upd_cnt2(pitem it) { it->cnt = cnt_safe(it->left) + cnt_safe(it->right) + 1; }
    void _apply(pitem t, const Packet& pack) { cnt = t->cnt; if (t->haspack) { merge_pac(t->pack, pack); } else { t->pack = pack; t->haspack = true; } apply(t->common, t->pack); cnt = 1; apply(t->node, t->pack); }
    void push_rev(pitem t) { if (t->reversy) { swap(t->left, t->right); if (t->left) t->left->reversy ^= 1; if (t->right) t->right->reversy ^= 1; t->reversy = false; } }
    void push(pitem t) {  push_rev(t); if (t->haspack) { if (t->left) _apply(t->left, t->pack); if (t->right) _apply(t->right, t->pack); t->haspack = false; } }
    void upd(pitem t) { if (!append) { upd_cnt2(t); return; } if (t->left) { t->common = t->left->common; append(t->common, t->node); t->cnt = t->left->cnt + 1; } else { t->common = t->node; t->cnt = 1; } if (t->right) { append(t->common, t->right->common); t->cnt += t->right->cnt; } }
    pitem merge(pitem left, pitem right) { if (!left) { return right; } if (!right) { return left; } if (left->prior > right->prior) { push(left); left->right = merge(left->right, right); upd(left); return left; } push(right); right->left = merge(left, right->left); upd(right); return right; }
    void split_raw(pitem t, pitem& left, pitem& right, int key, int add = 0) { if (!t) return void(left = right = 0); push(t); int cur_key = add + cnt_safe(t->left); if (key <= cur_key) split_raw(t->left, left, t->left, key, add), right = t; else split_raw(t->right, t->right, right, key, add + 1 + cnt_safe(t->left)), left = t; upd(t); }
    void left_to_right(pitem t, function<void(const TData&)> f) { if (!t) return; push(t); left_to_right(t->left, f); f(t->node); left_to_right(t->right, f); }
    void check_tree(pitem t) { if (!t) return; check_tree(t->left); check_tree(t->right); if (t->cnt != cnt_safe(t->left) + cnt_safe(t->right) + 1) { throw "bad cnt"; } if ((t->left && t->prior < t->left->prior) || (t->right && t->prior < t->right->prior)) { throw "bad prior"; } }
    template <class TT> static void modify(pitem t, int key, const TT& val) { push(t); auto cur = t->cnt - cnt_safe(t->right); if (key == cur) t->node = val; else if (key < cur) modify(t->left, key, val); else modify(t->right, key - cur, val); upd(t); }
    TData query_one(pitem t, int key) { while (true) { push(t); auto cur = t->cnt - cnt_safe(t->right); if (key == cur) return t->node; if (key < cur) t = t->left; else { t = t->right; key -= cur; } } }
    auto split(int key) { pitem left; pitem right; split_raw(root, left, right, key); return make_pair(left, right); }
    void print_tree_raw(pitem t, int h = 0, int root = 0, int i = 0) { if (!t) return; fe(e, h) std::cout << " "; char r = 'r'; if (root < 0) r = 'l'; else if (root > 0) r = 'r'; line(r, "cnt", t->cnt, "val", t->node, "common", t->common, "prior", t->prior, "has", t->haspack, "reverse", t->reversy, "i", i + cnt_safe(t->left)); print_tree_raw(t->left, h + 1, -1, i); print_tree_raw(t->right, h + 1, 1, t->cnt - cnt_safe(t->left)); }
    void ranged_set3(pitem t, int l, int r, const Packet& pack) { if (l <= 0 && r >= t->cnt) { _apply(t, pack); return; } push(t); int l_cnt; if (t->left) { l_cnt = t->left->cnt; if (l < l_cnt) { ranged_set3(t->left, l, r, pack); } } else { l_cnt = 0; } if (l <= l_cnt && r > l_cnt) { apply(t->node, pack); } if (r > ++l_cnt && t->right) { ranged_set3(t->right, l - l_cnt, r - l_cnt, pack); } upd(t); }
    TData query3(pitem t, int l, int r) { if (l <= 0 && r >= t->cnt) { return t->common; } push(t); int l_cnt = 0; if (t->left) { l_cnt = t->left->cnt; if (l < l_cnt) { auto res = query3(t->left, l, r); if (r > l_cnt) append(res, t->node); if (r > ++l_cnt && t->right) { append(res, query3(t->right, l - l_cnt, r - l_cnt)); } return res; } } if (l <= l_cnt) { auto res = t->node; if (r > ++l_cnt && t->right) { append(res, query3(t->right, l - l_cnt, r - l_cnt)); } return res; } if (r > ++l_cnt && t->right) { return query3(t->right, l - l_cnt, r - l_cnt); } return {}; }
    pitem root = nullptr;
public:
    void reverse(int l, int r) { assert(l <= r); if (l == r) return; pitem t2, t3; split_raw(root, root, t2, l); split_raw(t2, t2, t3, r - l + 1); t2->reversy ^= 1; root = merge(merge(root, t2), t3); }
    TData query(int l, int r) { assert(l <= r); return query3(root, l, r + 1); } 

    void print_tree() { print_tree_raw(root); }
    int size() { return cnt_safe(root); }
    TData query(int i) { assert(i >= 0 && i < size()); return query_one(root, i + 1); }
    void ranged_set(int l, int r, const Packet& pack) { assert(l <= r); ranged_set3(root, l, r + 1, pack); }
    template <class TT> void modify(int i, const TT& val) { assert(i >= 0 && i < size()); modify(root, i + 1, val); }
    void push_back(const TData& val) { insert(numeric_limits<int>::max(), val); }
    template<class T> auto insert(int pos, const T& node) { auto nitem = new item(node); nitem->prior = rand_prior(); if (!root) { root = nitem; return; } if (pos <= 0) { root = merge(nitem, root); return; } if (pos >= root->cnt) { root = merge(root, nitem); return; } auto [left, right] = split(pos); root = merge(merge(left, nitem), right); }
    void left_to_right(function<void(TData&)> f) { left_to_right(root, f); }
    void check_tree() { return check_tree(root); }
private:    

    struct Empty {};
    template<class T> pitem build(const T* a, int n, TRnd step) { if (n == 0) return nullptr; int mid = n / 2; pitem t; if constexpr (!is_same<T, Empty>::value) t = new item(a[mid]); else t = new item({}); t->prior = (mid + 1) * step; t->left = build<T>(a, mid, step); t->right = build<T>(a + mid + 1, n - mid - 1, step); upd(t); return t; }
    template<class T> void init_raw(int n, const T* a) { delete root; root = build<T>(a, n, std::max(numeric_limits<TRnd>::max() / (TRnd)(n + 3), (TRnd)1)); }
public:
    Cartesian() {} ~Cartesian() { delete root; }
    template <class T> void init(const vec<T>& vals) { init_raw<T>(vals.size(), &vals[0]); }
    template <class T> void init(int n) { init_raw<Empty>(n, nullptr); }
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
    static void set2(ll mod = 998'244'353) { __MOD = mod; }
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
    llmod operator+(const llmod& rhs) const { return llmod(val + rhs.val + __MOD); }
    llmod operator-(const llmod& rhs) const { return llmod(val - rhs.val + __MOD); }
    llmod operator*(const llmod& rhs) const { return llmod(val * rhs.val); }
    llmod operator/(const llmod& rhs) const { llmod tmp(*this); tmp /= rhs; return tmp; }
};
std::ostream& operator<<(std::ostream& stream, const llmod& val) { stream << val.val;    return stream; }

// -------------------------- primes
ll id23 = 0;  vector<ll> id17, primes;
void id18(ll n = 1e6 + 5) { // 1e8 -> 500 msec of work!
    if (id23 >= n) return; id23 = n;
    id17.clear(); primes.clear(); id17.resize(n + 1); primes.reserve(78500);
    for (ll i = 2; i <= n; i++) {
        if (id17[i] == 0) primes.push_back(i), id17[i] = i; for (auto p : primes) { if (i * p > n || p > id17[i]) break; id17[i * p] = p; }
    }
}
bool is_prime(ll v) { // sqrt(n)/ln(sqrt(n)), up to 10e12 
    id18(); assert(primes.back() * primes.back() >= v); if (v < id17.size()) return id17[v] == v;
    fe(e, primes) { if (e * e > v) break; if (v % e == 0) return false; } return true;
}
auto factorize(ll n) { // sqrt(n)/ln(sqrt(n)), up to 10e12, result sorted.
    id18(); assert(primes.back() * primes.back() >= n); map<ll, ll> res; if (n <= 1) return res;
    fe(e, primes) { if (e * e > n) break; while (true) { ll cur = n / e;  if (cur * e != n) break; res[e]++; n = cur; } }
    if (n > 1) { res[n]++; } return res;
}
auto id0(const map<ll, ll>& pr) { // 10^12 -> 4000, up to 10e12, result NOT sorted.  ALL POSSIBLE COMBINATION OF ALL PRIMES
    vec<ll> res; function<void(map<ll, ll>::const_iterator it, ll x)> ch = [&](map<ll, ll>::const_iterator it, ll x) {
        if (it == pr.end()) { res.push_back(x); return; }
        auto tmp = it; tmp++; ch(tmp, x); fe(k, it->second) { x *= it->first; ch(tmp, x); }
    };  ch(pr.begin(), 1); return res;
}
auto id0(ll n) { return id0(factorize(n)); }

// ------------------------ iprob 

_L <_T T> struct id3 {
    using THIS = id3;  T a = 0; T b = 1; id3() {}
    id3(ll v) { a = v; } id3(ll v, ll q) { a = v; b = q; }
    id3(T v) { a = v; }  id3(T v, T q) { a = v; b = q; }
    id3 operator+(const id3& rhs) { return id3(a * rhs.b + b * rhs.a, b * rhs.b); }
    id3 operator-(const id3& rhs) { return id3(a * rhs.b - b * rhs.a, b * rhs.b); }
    id3 operator*(const id3& rhs) { return id3(a * rhs.a, b * rhs.b); }
    THIS& operator+=(const THIS& rhs) { *this = *this + rhs; return *this; }
    THIS& operator-=(const THIS& rhs) { *this = *this - rhs; return *this; }
    THIS& operator*=(const THIS& rhs) { *this = *this * rhs; return *this; }
    id3 rev() { return id3(b - a, b); } // 1-p.
    id3 expect() { THIS v = *this;  swap(v.a, v.b); return v; } // мат. ожидание кол-ва бросков, чтобы эта вероятность сработа.
    T calc() const { return a / b; }
};
using iprob = id3<llmod>;
std::ostream& operator<<(std::ostream& stream, const iprob& val) { stream << val.calc();    return stream; }

// ---------------------- CORE

extern const char* INPUT_DATA;


class InnerReader {
    std::istringstream iss; std::string input;
public:
    InnerReader(const char* rawInput): input(rawInput) { trim(input);  iss = std::istringstream(input); }
    bool hasInput() { return !input.empty() && !iss.eof() && pos() < input.size(); }
    int pos() { return iss.tellg(); }
    template<class T> T getNext() { assert(hasInput()); T val; iss >> val; return val; }
};
InnerReader __reader(INPUT_DATA);


bool id6 = false;
template<class T> T id2() { T val; std::cin >> val; return val; }
template<class T> T id7() { // все падают сюда

    if (id6) return id2<T>();  return __reader.getNext<T>();

    return id2<T>();

}
template<class T> T scan() { return id7<T>(); }
template<> char scan() { while (true) { auto c = id7<char>(); return c; } }
template<class T> void scan2(T& val) { val = scan<T>(); }
void __IN() {} template <class Head, class... Tail> void __IN(Head& head, Tail &...tail) { scan2(head); __IN(tail...); }

template<class T> void print(const T& val); void endl() { std::cout << "\n"; } void space() { std::cout << ' '; } void flush() { std::cout << std::flush; }
template<class T, class Q> std::ostream& operator<<(std::ostream& stream, const pair<T, Q>& val) { print(val.first);    space();    print(val.second); return stream; }
template<class T> std::ostream& operator<<(std::ostream& stream, const std::vector<T>& v) { fe(e, v) { print(e);  if (!e_last) { space(); } } return stream; }
template<class T> void print(const T& val) { std::cout << val; }
template<class ... T> void print_sp(T&&... var2) { ((print(var2), space()), ...); }
template<class T, class ... Types> void print(const T& var, const Types&...var2) { print(var); space(); print(var2...); }
template<class T, class ... Types> void line(const T& var, const Types&...var2) { print(var, var2...); endl(); }








ll TASK__ = 1;
void onetime(); void prepare();
void task();
void __task() { try { task(); } catch (int& a) {} }
void tcase() {

    if (!id6 && !__reader.hasInput()) __task();
    else {

        ll num_task = scan<ll>(); for (TASK__ = 1; TASK__ <= num_task; TASK__++) { __task(); };

    }

}

void done() { throw 1; } 

template<class T, class ... Types> void done(const T& var, const Types&...var2) { line(var, var2...); done(); }





extern bool id13;
int main(int argc, char* argv[]) {

    if (argc > 1) { freopen(argv[1], "r", stdin); id6 = true; } else if (id6) { freopen("in.txt", "r", stdin); }


    bool isDebug = false;

    isDebug = true;

    line("--------------------", isDebug ? "" : "RELEASE");
    Timer timer;

    prepare(); 

    if (id13) tcase(); else __task();

    while (!id6 && __reader.hasInput()) { int curp = __reader.pos(); __task(); if (__reader.pos() == curp) break; }
    line("\nExecution time:", timer.elapsedMs());

    return 0;
}

void prepare() {

    std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr);  std::cout.tie(nullptr);

    std::cout.precision(17);
}









bool id13 = true;
const char* INPUT_DATA = R"(
0

3 3 2 2 3

3 3
1 3 2
4 2
2 2 2 2
6 9
6 9 6 9 6 9
9 100
10 40 20 20 100 60 80 60 60

)";





void task() {
    
    geti(n, m);
    geta(n, arr);

    Cartesian<Tracker> cr;
    cr.append = [&](auto& a, auto b) { max2(a, b); };
    fe(e, arr) cr.push_back( Tracker(e,ei));

    function<vec<llmod>(int, int)> f = [&](int a, int b) {
        vec<llmod> cur(m, 1);
        auto i = cr.query(a, b).index;
        auto left = i - 1;
        auto right = i + 1;
        if (left >= a) {
            auto res = f(a, left);
            llmod acc = 0;
            fe(e, res) { cur[ei] *= acc; acc += e; }
        }
        if (right <= b) {
            auto res = f(right, b);
            llmod acc = 0;
            fe(e, res) { acc += e; cur[ei] *= acc; }
        }
        return cur;
    };

    auto res = f(0, n - 1);
    llmod answ = 0;
    fe(e, res) answ += e;
    line(answ);
}