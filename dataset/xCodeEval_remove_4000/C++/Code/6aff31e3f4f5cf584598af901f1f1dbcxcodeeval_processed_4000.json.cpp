







using namespace std;

struct initon {
    initon() {
        cin.tie(0);
        ios::sync_with_stdio(false);
        cout.setf(ios::fixed);
        cout.precision(16);
        srand((unsigned) clock() + (unsigned) time(NULL));
    };
} id0;







template<typename T, typename U = typename T::value_type> std::true_type id13(signed);

template<typename T> std::false_type id13(long);
template<typename T> struct has_value_type : decltype(id13<T>(0)) {};
template<class T> inline constexpr bool id2 = has_value_type<T>::value;

template<class T> struct is_vector : std::false_type {};
template<class T> struct is_vector<std::vector<T>> : std::true_type {};
template<class T> inline constexpr bool id10 = is_vector<T>::value;

template<class T1, class T2, bool id3 = (sizeof(T1) > sizeof(T2))> struct max_type { typedef T1 type; };
template<class T1, class T2> struct max_type<T1, T2, false> { typedef T2 type; };



template<class T> using value_type_t = typename T::value_type;


template<class T, bool end = !has_value_type<T>::value> struct value_type_rec { typedef T type; };
template<class T> struct value_type_rec<T, false> { typedef typename value_type_rec<value_type_t<T>>::type type; };
template<class T> using value_type_rec_t = typename value_type_rec<T>::type;



template<class T, bool end = is_same<T, remove_extent_t<T>>::value> struct remove_extent_rec { typedef T type; };
template<class T> struct remove_extent_rec<T, false> { typedef typename remove_extent_rec<remove_extent_t<T>>::type type; };
template<class T> using remove_extent_rec_t = typename remove_extent_rec<T>::type;








template<class T>using V = vector<T>;
using P = pair<int, int >;
using vb = vector<bool>;
using vc = vector<char>;
using vi = vector<int>;
using vp = vector<P>;
using vs = vector<string>;





const double PI = 3.1415926535897932384626433832795029L;
const double eps = 1e-9;
using str = string;
using P = pair<ll, ll>;
using T = tuple<ll, ll, ll>;
using F = tuple<ll, ll, ll, ll>;























































constexpr ll inf = (ll) 1e9 + 100;
constexpr ll linf = (ll) 1e18 + 100;
constexpr double dinf = (double) linf * linf;

template<typename T> class fixed_point: T {public:explicit constexpr fixed_point(T &&t) noexcept: T(std::forward<T>(t)) {}template<typename... Args> constexpr decltype(auto) operator()(Args &&... args) const { return T::operator()(*this, std::forward<Args>(args)...); }};
template<typename T> static inline constexpr decltype(auto) fix(T &&t) noexcept { return fixed_point<T>{std::forward<T>(t)}; }


void id21(int &a, int &b, int n) {        if (b == -1) {
        if (a == -1) {
            a = 0;
            b = n;
        } else {
            b = a;
            a = 0;
        }
    }
}

template<class T, class U> bool chma(T &a, const U &b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}
template<class T, class U> bool chmi(T &a, const U &b) {
    if (b < a) {
        a = b;
        return true;
    }
    return false;
}
template<class T> T MAX() { return numeric_limits<T>::max(); }
template<class T> T MIN() { return numeric_limits<T>::min(); }

template<typename W, typename T> void fill(vector<W> &a, const T &v, int l = -1, ll r = -1) {id21(l, r, a.size());if constexpr(!is_vector<W>::value) { rep(i, l, r)a[i] = v; } else { rep(i, l, r)fill(a[i], v); }}
template<class Iterable, require_t(id2<Iterable>)> value_type_rec_t<Iterable> sum(const Iterable &a, int l = -1, int r = -1) {value_type_rec_t<Iterable> ret = 0;        if constexpr(id10<Iterable>) { id21(l, r, sz(a));                if constexpr(!id2<value_type_t<Iterable>>) { rep(i, l, r) ret += a[i]; } else { rep(i, l, r) ret += sum(a[i]); }} else {                if constexpr(!id2<value_type_t<Iterable>>) { for (auto &v : a) { ret += v; }} else { for (auto &v : a) { ret += sum(v); }}}return ret;}
template<class Iterable, require_t(id2<Iterable>)> value_type_rec_t<Iterable> min(const Iterable &a, int l = -1, int r = -1) {value_type_rec_t<Iterable> ret = MAX<value_type_rec_t<Iterable>>();        if constexpr(id10<Iterable>) { id21(l, r, sz(a));                if constexpr(!id2<value_type_t<Iterable>>) { rep(i, l, r) ret = min(ret, a[i]); } else { rep(i, l, r) ret = min(ret, min(a[i])); }} else {                if constexpr(!id2<value_type_t<Iterable>>) { for (auto &v : a) { ret = min(ret, v); }} else { for (auto &v : a) { ret = min(ret, min(v)); }}}return ret;}
template<class Iterable, require_t(id2<Iterable>)> value_type_rec_t<Iterable> max(const Iterable &a, int l = -1, int r = -1) {value_type_rec_t<Iterable> ret = MIN<value_type_rec_t<Iterable>>();        if constexpr(id10<Iterable>) {        id21(l, r, sz(a));                if constexpr(!id2<value_type_t<Iterable>>){            rep(i, l, r) ret = max(ret, a[i]);        }else{            rep(i, l, r) ret = max(ret, max(a[i]));        }    }    else {                if constexpr(!id2<value_type_t<Iterable>>){            for (auto &v : a) { ret = max(ret, v); }        }else{            for (auto &v : a) { ret = max(ret, max(v)); }        }    }    return ret;}

template<class Array, class T, size_t N> void fill(Array(&a)[N] , const T& v, int l = -1, int r = -1) {    id21(l, r, N);    if constexpr(is_same_v<Array, remove_extent_t<Array>>){        rep(i, l, r) a[i] = v;    }else{        rep(i, l, r) fill(a[i], v);    }}
template<class Array, size_t N> remove_extent_rec_t<Array> sum(const Array(&a)[N] , int l = -1, int r = -1) {    remove_extent_rec_t<Array> ret = 0;    id21(l, r, N);    if constexpr(is_same_v<Array, remove_extent_t<Array>>){        rep(i, l, r) ret += a[i];    }else{        rep(i, l, r) ret += sum(a[i]);    }    return ret;}
template<class Array, size_t N> remove_extent_rec_t<Array> min(const Array(&a)[N] , int l = -1, int r = -1) {    remove_extent_rec_t<Array> ret = MAX<remove_extent_rec_t<Array>>();    id21(l, r, N);    if constexpr(is_same_v<Array, remove_extent_t<Array>>){        rep(i, l, r) ret = std::min(ret, a[i]);    }else{        rep(i, l, r) ret = std::min(ret, min(a[i]));    }    return ret;}
template<class Array, size_t N> remove_extent_rec_t<Array> max(const Array(&a)[N] , int l = -1, int r = -1) {    remove_extent_rec_t<Array> ret = MIN<remove_extent_rec_t<Array>>();    id21(l, r, N);    if constexpr(is_same_v<Array, remove_extent_t<Array>>){        rep(i, l, r) ret = std::max(ret, a[i]);    }else{        rep(i, l, r) ret = std::max(ret, max(a[i]));    }    return ret;}




template<class H, class... T> auto zip_ref(vector<H> &head, vector<T> &...tails) {vector<tuple<H &, T &...>> res;rep(i, sz(head)) { res.emplace_back(head[i], tails[i]...); }return res;}


template<class H, class... T> auto zip(vector<H> &head, vector<T> &...tails) {vector<tuple<H, T...>> res;rep(i, sz(head)) { res.emplace_back(head[i], tails[i]...); }return res;}


template<class H, class... T> auto id18(vector<H> &head, vector<T> &...tails) {    vector<tuple<int, H &, T &...>> res;    rep(i, sz(head)) { res.emplace_back(i, head[i], tails[i]...); }    return res;}
template<class Tup_l, class Tup_r, size_t ... Indicies> auto id8(Tup_l &res, const Tup_r &rhs, index_sequence<Indicies...>) {(..., get<Indicies>(res).emplace_back(get<Indicies>(rhs)));}


template<class... T> tuple<vector<T>...> unzip(const vector<tuple<T&...>> &elems) {tuple<vector<T>...> res;for (auto &&elem : elems) { id8(res, elem, index_sequence_for<T...>{}); }return res;}





















template<class Iterable, class is_Iterable = value_type_t<Iterable>> void sort(Iterable &a) { sort(a.begin(), a.end()); }
template<class Iterable, class is_Iterable = value_type_t<Iterable>> void rsort(Iterable &a) { sort(a.rbegin(), a.rend()); }










    
    
    
    

    template<class Iterable, class U, class W> value_type_t<Iterable> lowerBound(Iterable &a, U v, W banpei) {
        decltype(a.begin()) it;
        if constexpr (is_vector<Iterable>::value) { it = lower_bound(a.begin(), a.end(), v); } else { it = a.lower_bound(v); }
        if (it == a.end())return banpei; else return *it;
    }
    template<class Iterable, class U, class W> value_type_t<Iterable> upperBound(Iterable &a, U v, W banpei) {
        decltype(a.begin()) it;
        if constexpr (is_vector<Iterable>::value) { it = upper_bound(a.begin(), a.end(), v); } else { it = a.upper_bound(v); }
        if (it == a.end())return banpei; else return *it;
    }
    template<class Iterable, class U, class W> value_type_t<Iterable> id22(Iterable &a, U v, W banpei) {
        decltype(a.begin()) it;
        if constexpr (is_vector<Iterable>::value) { it = upper_bound(a.begin(), a.end(), v); } else { it = a.upper_bound(v); }
        if (it == a.begin())return banpei; else { return *(--it); }
    }
    template<class Iterable, class U, class W> value_type_t<Iterable> id4(Iterable &a, U v, W banpei) {
        decltype(a.begin()) it;
        if constexpr (is_vector<Iterable>::value) { it = lower_bound(a.begin(), a.end(), v); } else { it = a.lower_bound(v); }
        if (it == a.begin())return banpei; else { return *(--it); }
    }


    
    
    

    

    ll mod(ll a, ll m) {if (m < 0) m *= -1;if (a >= 0) {if (a < m) return a;return a % m;} else {if (a >= -m) return a + m;return a % m + m;}}
    ll ceil(ll a, ll b) {if (b == 0) {cerr<<"ceil"<<endl;deb(a, b);return -1;} else if (a < 0) { return 0; } else { return (a + b - 1) / b; }}

    template<class T, class U, class V = typename max_type<T, U>::type>
    V gcd(T a_, U b_) {    V a = a_;    V b = b_;    while (b) a %= b, swap(a, b);    return abs(a);}

    template<class T, class U, class V = typename max_type<T, U>::type>
    V lcm(T a, U b) { return a / gcd(a, b) * b; }

    template<class T>T gcd(const vector<T>& b) {    T res = b[0];    rep(i, 1, sz(b))res = gcd(b[i], res);    return res;}
    template<class T>T lcm(const vector<T>& a) {    T res = a[0];    rep(i, 1, sz(a))res = lcm(a[i], res);    return res;}

    

    

    template<class R, class T> R id23(T t) {    R lt = t;        if constexpr (is_integral_v<R>) {        return lt <= 0 ? 0 : ((1 + lt) * lt) >> 1;    } else {        return ((1 + lt) * lt) / 2;    }}
    template<class R, class T, class U> R id23(T s, U t) {    if (s <= 0) {        return id23<R>(t - s) + s * (t - s + 1);    } else {        return id23<R>(t) - id23<R>(s - 1);    }}
    template<class R, class T> R id17(T t) {return id23(t-1);}
    template<class R, class T, class U> R id17(T s, U t) {return id23(s, t-1);}
    

    template<class T = int, class A, class B = int>T my_pow(A a, B b = 2) {
            if(b < 0)return (T)1 / my_pow<T>(a, -b);
    
            if constexpr(is_floating_point<T>::value) { return pow((T) a, (T) b); }
            else if constexpr(is_floating_point<A>::value) {
    
                assert2(0, "pow <not dou>(dou, )");
    
            }else if constexpr(is_floating_point<B>::value) {
    
                assert2(0, "pow <not dou>(, dou)");
    
            }else {
    
                T ret = 1;        T bek = a;        while (b) {            if (b & 1)ret *= bek;            bek *= bek;            b >>= 1;        }        return ret;
    
            }
    
    }
    template<typename W, typename H> void resize(W &vec_, const H head) { vec_.resize(head); }
    template<typename W, typename H, typename ... T> void resize(W &vec_, const H &head, const T ... tail) {
        vec_.resize(head);
        for (auto &v: vec_)resize(v, tail...);
    } 




    template<class T=int> T in() {T ret;cin >> ret;return ret;}
    template<class T> void in(T &head) { cin >> head; }
    template<class T, class... U> void in(T &head, U &... tail) {cin >> head;in(tail...);}
    template<class T> void na(vector<T> &A, int N) {A.resize(N);rep(i, N) { cin >> A[i]; }}
    template<class T> void nad(vector<T> &A, ll N) {na(A, N);rep(i, N)A[i]--;}
    template<class T, class U> void na2(vector<T> &a, vector<U> &b, ll n) {a.resize(n);b.resize(n);rep(i, n)cin >> a[i] >> b[i];}
    template<class T, class U> void id11(vector<T> &a, vector<U> &b, ll n) {na2(a, b, n);rep(i, n)a[i]--, b[i]--;}
    template<class T, class U, class W> void na3(vector<T> &a, vector<U> &b, vector<W> &c, ll n) {a.resize(n);b.resize(n);c.resize(n);rep(i, n)cin >> a[i] >> b[i] >> c[i];}
    template<class T, class U, class W> void id7(vector<T> &a, vector<U> &b, vector<W> &c, ll n) {na3(a, b, c, n);rep(i, n)a[i]--, b[i]--, c[i]--;}
    
    
    
    
    
    
    
    

    
    
    
    
    
    
    
    
    


    
    
    
    
    





    template<class Tuple, size_t... Indicies> void id12(istream &iss, Tuple &tup, index_sequence<Indicies...>) { (..., [&](auto &v) { iss >> v; }(get<Indicies>(tup))); }
    template<class... T> istream &operator>>(istream &iss, tuple<T...> &tup) {
        id12(iss, tup, index_sequence_for<T...>{});
        return iss;
    }
    template<class Tuple, size_t... Indicies> void id20(ostream &os, const Tuple &tup, index_sequence<Indicies...>, const string& sep) {
        stringstream ss;
        (..., [&](auto a) { ss << sep << a; }(get<Indicies>(tup)));
        os << ss.str().substr((int)sep.size());
    }
    template<class... T> ostream &operator<<(ostream &os, const tuple<T...> &tup) {
        id20(os, tup, index_sequence_for<T...>{}, " ");
        return os;
    }
    


    template<typename T> ostream &operator<<(ostream &os, const vector<vector<T>> &vec_) {
        for (ll i = 0; i < vec_.size(); ++i) {
            for (ll j = 0; j < vec_[i].size(); ++j) { os << vec_[i][j] << " "; }
            os << endl;
        }
        return os;
    }
    template<typename T> ostream &operator<<(ostream &os, const vector<T> &vec_) {
        for (ll i = 0; i < vec_.size(); ++i)os << vec_[i] << (i + 1 == vec_.size() ? "" : " ");
        return os;
    }





    ostream &operator<<(ostream &os, const vector<vector<char>> &vec_) {
        rep(h, sz(vec_)) {
            rep(w, sz(vec_[0])) { os << vec_[h][w]; }
            if(h < sz(vec_)-1)os << endl;
        }
        return os;
    }

    
    template<class T> void out(T head) {
        cout << head << endl;
        res_mes += deb_tos(head);
        res_mes += "\n";
    }
    template<class T, class... U> void out(T head, U ... tail) {
        cout << head << " ";
        res_mes += deb_tos(head) + " ";
        out(tail...);
    }
    void out() { cout << "" << endl; }
    
    template<class T> void out(T head) {cout << head << endl;}
            template<class T, class... U> void out(T head, U ... tail) {cout << head << " ";out(tail...);}
            void out() { cout << "" << endl; }
    


    template<class H, class ...T> void outl(vector<H> &head, vector<T> &...tails) {
        rep(i, sz(head)) {
            cout << head[i];
            auto f = [&](auto &v) { cout << " " << v; };
            (..., f(tails[i]));
            cout << endl;
        }
    }
    template<class... T> void fin(T... s) {
        out(s...);
        exit(0);
    }





ll u0(ll a) { return a < 0 ? 0 : a; }
string sub(const string &A, int l = -1, int r = -1) {    id21(l, r, sz(A));    assert(0 <= l && l <= r && r <= sz(A));    return A.substr(l, r - l);}template<class T> vector<T> sub(const vector<T> &A, int l = -1, int r = -1) {    id21(l, r, sz(A));    assert(0 <= l && l <= r && r <= sz(A));    vector<T> ret(r - l);    std::copy(A.begin() + l, A.begin() + r, ret.begin());    return ret;} 

constexpr ll bit(ll n) {

    assert(n <= 62);


    return (1LL << (n));
}

constexpr bool bget(ll m, ll keta) {

    assert(keta <= 62);


    return (m >> keta) & 1;
}
ll mask(ll n) { return (1ll << n) - 1; }








vb::reference operator|=(vb::reference a, bool b) { return a = a | b; }
vb::reference operator&=(vb::reference a, bool b) { return a = a & b; }
template<class T, class U> vector<T> &operator+=(vector<T> &a, const U &v) {a.emplace_back(v);return a;}
template<class T> vector<T> &operator+=(vector<T> &a, const vector<T> &b) {rep(i, sz(b)) {a.emplace_back(b[i]); }return a;}
template<class T, class U> void operator+=(queue<T> &a, const U &v) { a.push(v); }
template<class T, class U> priority_queue<T, vector<T>, greater<T>> &operator+=(priority_queue<T, vector<T>, greater<T>> &a, const U &v) {a.push(v);return a;}
template<class T, class U> priority_queue<T> &operator+=(priority_queue<T> &a, const U &v) {a.push(v);return a;}
template<class T, class U> auto operator+=(set<T> &a, const U &v) { return a.insert(v); }
template<class T, class U> auto operator-=(set<T> &a, const U &v) { return a.erase(v); }
template<class T, class U> auto operator+=(mset<T> &a, const U &v) { return a.insert(v); }
template<class T, class U> set<T, greater<T>> &operator+=(set<T, greater<T>> &a, const U &v) {a.insert(v);return a;}
template<class T> vector<T> operator+(const vector<T> &a, const vector<T> &b) {vector<T> ret;ret = a;fora(v, b) { ret += v; }return ret;}

template<class T, class U> pair<T, U> operator+=(pair<T,U> &a, const pair<T,U> & b) {a.fi+=b.fi;a.se+=b.se; return a;}
template<class T, class U> pair<T, U> operator+(const pair<T, U> &a, const pair<T, U> &b) { pair<T, U> c = a;c += b;return c;}

template<class T, class U> pair<T, U> operator-=(pair<T,U> &a, const pair<T,U> & b) {a.fi-=b.fi;a.se-=b.se; return a;}
template<class T, class U> pair<T, U> operator-(const pair<T, U> &a, const pair<T, U> &b) { pair<T, U> c = a;c -= b;return c;}

template<class T, class U, class V> pair<T, U> operator*=(pair<T, U> &a, const V& b) { a.fi*=b;a.se*=b; return a;}
template<class T, class U, class V> pair<T, U> operator*(const pair<T, U> &a, const V& b) { pair<T, U> c = a;c *= b;return c; }

template<class T, class U, class V> pair<T, U> operator/=(pair<T, U> &a, const V& b) { a.fi/=b;a.se/=b; return a;}
template<class T, class U, class V> pair<T, U> operator/(const pair<T, U> &a, const V& b) { pair<T, U> c = a;c /= b;return c; }

template<class T, class U> pair<T, U> operator-(const pair<T, U> &a) { return pair<T, U>(-a.first, -a.second); }


int yn_v = 0;
void yn(bool a) { assert_yn(yn_v, 1);if (a)cout << "yes" << endl; else cout << "no" << endl; }
void fyn(bool a) {    assert_yn(yn_v, 1);yn(a);    exit(0);}

void Yn(bool a) { assert_yn(yn_v, 2);if (a)cout << "Yes" << endl; else cout << "No" << endl; }
void fYn(bool a) {    assert_yn(yn_v, 2);Yn(a);    exit(0);}

void YN(bool a) { assert_yn(yn_v, 3);if (a)cout << "YES" << endl; else cout << "NO" << endl; }
void fYN(bool a) {    assert_yn(yn_v, 3);YN(a);    exit(0);}













vvc (ba);
ll N, M, H, W;
vi A, B, C;

namespace pnumber_tools {

    class Eratosthenes { public:virtual void initialize() {} virtual void generate(const int64_t x) = 0; virtual void generate(const int64_t from, const int64_t to) = 0; virtual int64_t count() = 0; virtual bool prime(int x) = 0; virtual int32_t version() = 0; inline uint64_t PopCnt(uint64_t); inline int BitToIndex(uint8_t); };    uint64_t Eratosthenes::PopCnt(uint64_t bits) {        bits = (bits & 0x5555555555555555ULL) + ((bits >> 1) & 0x5555555555555555ULL);        bits = (bits & 0x3333333333333333ULL) + ((bits >> 2) & 0x3333333333333333ULL);        bits = (bits & 0x0f0f0f0f0f0f0f0fULL) + ((bits >> 4) & 0x0f0f0f0f0f0f0f0fULL);        return (bits * 0x0101010101010101ULL) >> (64 - 8);    }    int Eratosthenes::BitToIndex(uint8_t b) {        switch (b) {            case 1 << 0:                return 0;            case 1 << 1:                return 1;            case 1 << 2:                return 2;            case 1 << 3:                return 3;            case 1 << 4:                return 4;            case 1 << 5:                return 5;            case 1 << 6:                return 6;            case 1 << 7:                return 7;        }        return -1;    }    namespace {        constexpr uint64_t id14 = 1000000;        constexpr int32_t kMod30[] = {1, 7, 11, 13, 17, 19, 23, 29};        constexpr int C1[] = {6, 4, 2, 4, 2, 4, 6, 2};        constexpr int C0[][8] = {{0, 0, 0, 0, 0, 0, 0, 1},                             {1, 1, 1, 0, 1, 1, 1, 1},                             {2, 2, 0, 2, 0, 2, 2, 1},                             {3, 1, 1, 2, 1, 1, 3, 1},                             {3, 3, 1, 2, 1, 3, 3, 1},                             {4, 2, 2, 2, 2, 2, 4, 1},                             {5, 3, 1, 4, 1, 3, 5, 1},                             {6, 4, 2, 4, 2, 4, 6, 1},};        constexpr uint8_t kMask[][8] = {{0xfe, 0xfd, 0xfb, 0xf7, 0xef, 0xdf, 0xbf, 0x7f},                                    {0xfd, 0xdf, 0xef, 0xfe, 0x7f, 0xf7, 0xfb, 0xbf},                                    {0xfb, 0xef, 0xfe, 0xbf, 0xfd, 0x7f, 0xf7, 0xdf},                                    {0xf7, 0xfe, 0xbf, 0xdf, 0xfb, 0xfd, 0x7f, 0xef},                                    {0xef, 0x7f, 0xfd, 0xfb, 0xdf, 0xbf, 0xfe, 0xf7},                                    {0xdf, 0xf7, 0x7f, 0xfd, 0xbf, 0xfe, 0xef, 0xfb},                                    {0xbf, 0xfb, 0xf7, 0x7f, 0xfe, 0xef, 0xdf, 0xfd},                                    {0x7f, 0xbf, 0xdf, 0xef, 0xf7, 0xfb, 0xfd, 0xfe},};        constexpr int64_t kSievedPrimes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23};        constexpr int64_t id16 = 7 * 11 * 13 * 17 * 19 * 23;        constexpr int imap[] = {-1, 0, -1, -1, -1, -1, -1, 1, -1, -1, -1, 2, -1, 3, -1, -1, -1, 4, -1, 5, -1, -1, -1, 6, -1, -1, -1, -1, -1, 7};        class Eratosthenes2 final                : public Eratosthenes {        public:            void generate(const int64_t x) override;            void generate(const int64_t, const int64_t) override { assert(false); }            bool prime(int x) override;            int64_t count() override;            int32_t version() override { return 2; }            vector<uint8_t> flags_;        };        void Eratosthenes2::generate(const int64_t x) {            flags_.clear();            if (x > 10000000000) return;            int64_t size = x / 30 + (x % 30 != 0);            flags_.resize(size, 0xff);            if (int r = x % 30) { if (r <= 1) flags_[size - 1] = 0x0; else if (r <= 7) flags_[size - 1] = 0x1; else if (r <= 11) flags_[size - 1] = 0x3; else if (r <= 13) flags_[size - 1] = 0x7; else if (r <= 17) flags_[size - 1] = 0xf; else if (r <= 19) flags_[size - 1] = 0x1f; else if (r <= 23) flags_[size - 1] = 0x3f; else if (r <= 29) flags_[size - 1] = 0x7f; }            flags_[0] = 0xfe;            const uint64_t sqrt_x = std::ceil(std::sqrt(x) + 0.1);            const uint64_t id15 = sqrt_x / 30 + 1;            for (uint64_t i = 0; i < id15; ++i) {                for (uint8_t flags = flags_[i]; flags; flags &= flags - 1) {                    uint8_t lsb = flags & (-flags);                    int ibit = BitToIndex(lsb);                    const int32_t m = kMod30[ibit];                    int32_t pm = 30 * i + 2 * m;                    for (uint64_t j = i * pm + (m * m) / 30, k = ibit; j < flags_.size(); j += i * C1[k] + C0[ibit][k], k = (k + 1) & 7) { flags_[j] &= kMask[ibit][k]; }                }            }        }        int64_t Eratosthenes2::count() {            if (flags_.empty()) return -1;            int64_t ret = 3;            for (uint8_t f : flags_) { ret += PopCnt(f); }            return ret;        }        inline bool Eratosthenes2::prime(int x) {            if (x == 2 || x == 3 || x == 5)return true; else if (!(x & 1) || x % 3 == 0 || x % 5 == 0)return false;            return (flags_[x / 30] >> imap[x % 30]) & 1;        }    }
    Eratosthenes2 era;
    int prime_len = 3e6;
    vector<int> primes;
    void setprime(int size = 3e6) {        prime_len = size;        era.generate(size);        primes = {2, 3, 5};        int nums[129] = {};        nums[1] = 1;        nums[2] = 7;        nums[4] = 11;        nums[8] = 13;        nums[16] = 17;        nums[32] = 19;        nums[64] = 23;        nums[128] = 29;                int j = 0;        int id19 = era.flags_.size();        int i30 = 0;        for (int i = 0; i < id19; i++, i30 += 30) {            uint8_t m = era.flags_[i];            while (m) {                j = m & -m;                primes.push_back(i30 + nums[j]);                m ^= j;            }        }    }
    
    vi id1(int v) {        vi res;        double lim = std::sqrt(v);        for (int i = 1; i <= lim; ++i) {            if (v % i == 0) { res.push_back(i);            }        }        rer(i, sz(res) - 1) {            if (res[i] != v / res[i])res.push_back(v / res[i]);        }        return res;    }
    
    vp factorization(int v) {        assert(v);        int tv = v;        vp res;        if (!sz(primes))setprime();        for (auto &&p :primes) {            if (v % p == 0)res.emplace_back(p, 0);            while (v % p == 0) {                v /= p;                res.back().second++;            }            if (v == 1 || p * p > tv)break;        }        if (v > 1)res.emplace_back(v, 1);        return res;    }
    map<int, int> id6(int v) {        assert(v);        int tv = v;        vp res;        if (!sz(primes))setprime();        for (auto &&p :primes) {            if (v % p == 0)res.emplace_back(p, 0);            while (v % p == 0) {                v /= p;                res.back().second++;            }            if (v == 1 || p * p > tv)break;        }        if (v > 1)res.emplace_back(v, 1);        map<int,int> nres;        fora(r,res){            nres[r.fi]=r.se;        }        return nres;    }
}
using namespace pnumber_tools;
struct id9 { id9() { setprime(); }} id5;


void solve() {
    int Q;
    cin >> Q;

    while (Q--) {
        

        

        

        auto getv = [&](int i) {
            return i + k6_;
        };


        vi cou(k6_ * 2);
        in(N);
        na(A, N);
        fora(a, A)cou[getv(a)]++;
        



        vv(signed, dp, k6_ * 2);
        bool zero = false;
        vi uA = A;
        rsort(uA);
        unique(uA);


        

        

        int best = 0;


        fora (ui, v, uA) {
            for (auto &v2 : uA) {
                if (v != v2 && cou[getv(v)] + cou[getv(v2)] >= N / 2) {
                    chma(best, abs(v2 - v));
                }
            }


            if (cou[getv(v)] >= N / 2) {
                zero = true;
                break;
            }
            dp[getv(v)].resize(k6_);
            int co = cou[getv(v)];
            

            

            rep(uj, ui) {
                int v2 = uA[uj];
                int diff = v2 - v;
                auto divs = id1(diff);
                fora(k, divs) {
                    if (k >= k6_)continue;
                    if (dp[getv(v2)].size() == 0)continue;
                    chma(dp[getv(v)][k], co + dp[getv(v2)][k]);
                    chma(dp[getv(v)][k], co + cou[getv(v2)]);
                }
            }
        }
        if (zero) {
            out(-1);
            continue;
        }


        for (auto &v : uA) {
            rer(k, k6_ - 1, 1) {
                if (k < best)break;
                if (dp[getv(v)][k] >= N / 2) {
                    chma(best, k);
                    break;
                }
            }
        }
        out(best);
    }

}

signed main() {
    solve();

    return 0;
}