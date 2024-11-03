







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







template<typename T, typename U = typename T::value_type> std::true_type id18(signed);

template<typename T> std::false_type id18(long);
template<typename T> struct has_value_type : decltype(id18<T>(0)) {};
template<class T> inline constexpr bool id1 = has_value_type<T>::value;

template<class T> struct is_vector : std::false_type {};
template<class T> struct is_vector<std::vector<T>> : std::true_type {};
template<class T> inline constexpr bool id12 = is_vector<T>::value;

template<class T1, class T2, bool id4 = (sizeof(T1) > sizeof(T2))> struct max_type { typedef T1 type; };
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


void id26(int &a, int &b, int n) {        if (b == -1) {
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

template<typename W, typename T> void fill(vector<W> &a, const T &v, int l = -1, ll r = -1) {id26(l, r, a.size());if constexpr(!is_vector<W>::value) { rep(i, l, r)a[i] = v; } else { rep(i, l, r)fill(a[i], v); }}
template<class Iterable, require_t(id1<Iterable>)> value_type_rec_t<Iterable> sum(const Iterable &a, int l = -1, int r = -1) {value_type_rec_t<Iterable> ret = 0;        if constexpr(id12<Iterable>) { id26(l, r, sz(a));                if constexpr(!id1<value_type_t<Iterable>>) { rep(i, l, r) ret += a[i]; } else { rep(i, l, r) ret += sum(a[i]); }} else {                if constexpr(!id1<value_type_t<Iterable>>) { for (auto &v : a) { ret += v; }} else { for (auto &v : a) { ret += sum(v); }}}return ret;}
template<class Iterable, require_t(id1<Iterable>)> value_type_rec_t<Iterable> min(const Iterable &a, int l = -1, int r = -1) {value_type_rec_t<Iterable> ret = MAX<value_type_rec_t<Iterable>>();        if constexpr(id12<Iterable>) { id26(l, r, sz(a));                if constexpr(!id1<value_type_t<Iterable>>) { rep(i, l, r) ret = min(ret, a[i]); } else { rep(i, l, r) ret = min(ret, min(a[i])); }} else {                if constexpr(!id1<value_type_t<Iterable>>) { for (auto &v : a) { ret = min(ret, v); }} else { for (auto &v : a) { ret = min(ret, min(v)); }}}return ret;}
template<class Iterable, require_t(id1<Iterable>)> value_type_rec_t<Iterable> max(const Iterable &a, int l = -1, int r = -1) {value_type_rec_t<Iterable> ret = MIN<value_type_rec_t<Iterable>>();        if constexpr(id12<Iterable>) {        id26(l, r, sz(a));                if constexpr(!id1<value_type_t<Iterable>>){            rep(i, l, r) ret = max(ret, a[i]);        }else{            rep(i, l, r) ret = max(ret, max(a[i]));        }    }    else {                if constexpr(!id1<value_type_t<Iterable>>){            for (auto &v : a) { ret = max(ret, v); }        }else{            for (auto &v : a) { ret = max(ret, max(v)); }        }    }    return ret;}

template<class Array, class T, size_t N> void fill(Array(&a)[N] , const T& v, int l = -1, int r = -1) {    id26(l, r, N);    if constexpr(is_same_v<Array, remove_extent_t<Array>>){        rep(i, l, r) a[i] = v;    }else{        rep(i, l, r) fill(a[i], v);    }}
template<class Array, size_t N> remove_extent_rec_t<Array> sum(const Array(&a)[N] , int l = -1, int r = -1) {    remove_extent_rec_t<Array> ret = 0;    id26(l, r, N);    if constexpr(is_same_v<Array, remove_extent_t<Array>>){        rep(i, l, r) ret += a[i];    }else{        rep(i, l, r) ret += sum(a[i]);    }    return ret;}
template<class Array, size_t N> remove_extent_rec_t<Array> min(const Array(&a)[N] , int l = -1, int r = -1) {    remove_extent_rec_t<Array> ret = MAX<remove_extent_rec_t<Array>>();    id26(l, r, N);    if constexpr(is_same_v<Array, remove_extent_t<Array>>){        rep(i, l, r) ret = std::min(ret, a[i]);    }else{        rep(i, l, r) ret = std::min(ret, min(a[i]));    }    return ret;}
template<class Array, size_t N> remove_extent_rec_t<Array> max(const Array(&a)[N] , int l = -1, int r = -1) {    remove_extent_rec_t<Array> ret = MIN<remove_extent_rec_t<Array>>();    id26(l, r, N);    if constexpr(is_same_v<Array, remove_extent_t<Array>>){        rep(i, l, r) ret = std::max(ret, a[i]);    }else{        rep(i, l, r) ret = std::max(ret, max(a[i]));    }    return ret;}




template<class H, class... T> auto zip_ref(vector<H> &head, vector<T> &...tails) {vector<tuple<H &, T &...>> res;rep(i, sz(head)) { res.emplace_back(head[i], tails[i]...); }return res;}


template<class H, class... T> auto zip(vector<H> &head, vector<T> &...tails) {vector<tuple<H, T...>> res;rep(i, sz(head)) { res.emplace_back(head[i], tails[i]...); }return res;}


template<class H, class... T> auto id22(vector<H> &head, vector<T> &...tails) {    vector<tuple<int, H &, T &...>> res;    rep(i, sz(head)) { res.emplace_back(i, head[i], tails[i]...); }    return res;}
template<class Tup_l, class Tup_r, size_t ... Indicies> auto id9(Tup_l &res, const Tup_r &rhs, index_sequence<Indicies...>) {(..., get<Indicies>(res).emplace_back(get<Indicies>(rhs)));}


template<class... T> tuple<vector<T>...> unzip(const vector<tuple<T&...>> &elems) {tuple<vector<T>...> res;for (auto &&elem : elems) { id9(res, elem, index_sequence_for<T...>{}); }return res;}





















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
    template<class Iterable, class U, class W> value_type_t<Iterable> id29(Iterable &a, U v, W banpei) {
        decltype(a.begin()) it;
        if constexpr (is_vector<Iterable>::value) { it = upper_bound(a.begin(), a.end(), v); } else { it = a.upper_bound(v); }
        if (it == a.begin())return banpei; else { return *(--it); }
    }
    template<class Iterable, class U, class W> value_type_t<Iterable> id5(Iterable &a, U v, W banpei) {
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

    

    

    template<class R, class T> R id30(T t) {    R lt = t;        if constexpr (is_integral_v<R>) {        return lt <= 0 ? 0 : ((1 + lt) * lt) >> 1;    } else {        return ((1 + lt) * lt) / 2;    }}
    template<class R, class T, class U> R id30(T s, U t) {    if (s <= 0) {        return id30<R>(t - s) + s * (t - s + 1);    } else {        return id30<R>(t) - id30<R>(s - 1);    }}
    template<class R, class T> R id21(T t) {return id30(t-1);}
    template<class R, class T, class U> R id21(T s, U t) {return id30(s, t-1);}
    

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
    template<class T, class U> void id15(vector<T> &a, vector<U> &b, ll n) {na2(a, b, n);rep(i, n)a[i]--, b[i]--;}
    template<class T, class U, class W> void na3(vector<T> &a, vector<U> &b, vector<W> &c, ll n) {a.resize(n);b.resize(n);c.resize(n);rep(i, n)cin >> a[i] >> b[i] >> c[i];}
    template<class T, class U, class W> void id7(vector<T> &a, vector<U> &b, vector<W> &c, ll n) {na3(a, b, c, n);rep(i, n)a[i]--, b[i]--, c[i]--;}
    
    
    
    
    
    
    
    

    
    
    
    
    
    
    
    
    


    
    
    
    
    





    template<class Tuple, size_t... Indicies> void id17(istream &iss, Tuple &tup, index_sequence<Indicies...>) { (..., [&](auto &v) { iss >> v; }(get<Indicies>(tup))); }
    template<class... T> istream &operator>>(istream &iss, tuple<T...> &tup) {
        id17(iss, tup, index_sequence_for<T...>{});
        return iss;
    }
    template<class Tuple, size_t... Indicies> void id23(ostream &os, const Tuple &tup, index_sequence<Indicies...>, const string& sep) {
        stringstream ss;
        (..., [&](auto a) { ss << sep << a; }(get<Indicies>(tup)));
        os << ss.str().substr((int)sep.size());
    }
    template<class... T> ostream &operator<<(ostream &os, const tuple<T...> &tup) {
        id23(os, tup, index_sequence_for<T...>{}, " ");
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
        res_mes += id2(head);
        res_mes += "\n";
    }
    template<class T, class... U> void out(T head, U ... tail) {
        cout << head << " ";
        res_mes += id2(head) + " ";
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
string sub(const string &A, int l = -1, int r = -1) {    id26(l, r, sz(A));    assert(0 <= l && l <= r && r <= sz(A));    return A.substr(l, r - l);}template<class T> vector<T> sub(const vector<T> &A, int l = -1, int r = -1) {    id26(l, r, sz(A));    assert(0 <= l && l <= r && r <= sz(A));    vector<T> ret(r - l);    std::copy(A.begin() + l, A.begin() + r, ret.begin());    return ret;} 

constexpr ll bit(ll n) {

    assert(n <= 62);


    return (1LL << (n));
}

constexpr bool bget(ll m, ll keta) {

    assert(keta <= 62);


    return (m >> keta) & 1;
}
ll mask(ll n) { return (1ll << n) - 1; }
vi iota(int s, int t){vi ret(t - s);iota(ALL(ret), s);return ret;}







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



void id19() {

    cerr << "ole" << endl;
    exit(0);

    string a = "a";
    rep(i, 30)a += a;
    rep(i, 1 << 17)cout << a << endl;
    cout << "OLE 出力長制限超過" << endl;
    exit(0);
}
template<class T> T INF() { return numeric_limits<T>::max() / 2; }
template<> signed INF() { return inf; }
template<> ll INF() { return linf; }
template<> double INF() { return dinf; }
template<> char INF() { return '{'; }
template<> string INF() { return "{"; }

template<class T> struct ruiC {
    vector<T> rui;
    ruiC(vector<T> &ru) : rui(ru) {}
    
    ruiC() : rui(1, 0) {}
    T operator()(ll l, ll r) {
        if (l > r) {
            cerr << "ruic ";
            deb(l, r);
            assert(0);
        }
        return rui[r] - rui[l];
    }
    T operator()(int r = inf) { return operator()(0, min(r, sz(rui) - 1)); }
    
    


    T operator[](ll i) { return rui[i]; }
    
    void operator+=(T v) { rui.push_back(rui.back() + v); }
    void add(int i, T v) {
        if (sz(rui) - 1 != i)id19();
        operator+=(v);
    }
    T back() { return rui.back(); }
    ll size() { return rui.size(); }
    auto begin() { return rui.begin(); }
    auto end() { return rui.end(); }
};
template<class T> vector<T> ruiv(const vector<T> &a) {
    vector<T> ret(a.size() + 1);
    rep(i, a.size())ret[i + 1] = ret[i] + a[i];
    return ret;
}
template<class T> ruiC<T> ruic(const vector<T> &a) {
    vector<T> ret = ruiv(a);
    return ruiC<T>(ret);
}
template<class T> ruiC<T> ruic() { return ruiC<T>(); }




template<class T> vector<T> imos(const vector<T> &v) {
    vector<T> ret = v;
    rep(i, sz(ret) - 1)ret[i + 1] += ret[i];
    return ret;
}


template<class T, class U> vi imos(const vector<T> &a, U k) {
    vi equ(sz(a));
    rep(i, sz(a)) { equ[i] = a[i] == k; }
    return imos(equ);
}
template<class T> vector<T> imosx(const vector<T> &v) {
    vector<T> ret = v;
    rep(i, sz(ret) - 1)ret[i + 1] ^= ret[i];
    return ret;
}


template<class T> vector<T> imi(const vector<T> &v) {
    vector<T> ret = v;
    rep(i, sz(ret) - 1)chmi(ret[i + 1], ret[i]);
    return ret;
}
template<class T> vector<T> ima(const vector<T> &v) {
    vector<T> ret = v;
    rep(i, sz(ret) - 1)chma(ret[i + 1], ret[i]);
    return ret;
}
template<class T> vector<T> rimi(const vector<T> &v) {
    vector<T> ret = v;
    rer(i, sz(ret) - 1, 1)chmi(ret[i - 1], ret[i]);
    return ret;
}
template<class T> vector<T> rima(const vector<T> &v) {
    vector<T> ret = v;
    rer(i, sz(ret) - 1, 1)chma(ret[i - 1], ret[i]);
    return ret;
}









template<typename T> struct id6 {
    vector<vector<T> > st;
    vector<int> lookup;
    int qt;
    int n;
    T e;

    id6() {}
    void build(const vector<T> &v, T e_, int qt_) {
        n = (v.size());
        qt = qt_;
        e = e_;
        int b = 0;
        while ((1 << b) <= v.size()) ++b;
        st.assign(b, vector<T>(1 << b));
        for (int i = 0; i < v.size(); i++) { st[0][i] = v[i]; }
        if (qt == minq) for (int i = 1; i < b; i++) { for (int j = 0; j + (1 << i) <= (1 << b); j++) { st[i][j] = min(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]); }} else for (int i = 1; i < b; i++) { for (int j = 0; j + (1 << i) <= (1 << b); j++) { st[i][j] = max(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]); }}
        lookup.resize(v.size() + 1);
        for (int i = 2; i < lookup.size(); i++) { lookup[i] = lookup[i >> 1] + 1; }
    }
    T operator()(int l, int r) {
        if (l < 0)l = 0;
        if (r > n)r = n;
        if (l >= r)return e;
        int b = lookup[r - l];
        if (qt == minq)return min(st[b][l], st[b][r - (1 << b)]); else return max(st[b][l], st[b][r - (1 << b)]);
    }
    T operator()(int r) { return operator()(0, r); }
};
template<class T> struct ruimax {

private:
    vector<T> ve;
    id6<pair<T, int>> spa;
    vector<T> rv;
    vector<int> ri;
    T e;
    bool build = false;
public:
    int n;
    ruimax(vector<T> &a, T e) : ve(a), n(sz(a)), e(e) {
        int index = -1;
        T ma = numeric_limits<T>::min();
        rv.resize(n + 1);
        ri.resize(n + 1);
        rv[0] = e;
        ri[0] = -1;
        rep(i, n) {
            if (chma(ma, a[i])) { index = i; }
            rv[i + 1] = ma;
            ri[i + 1] = index;
        }
    }
    T operator()(int l, int r) {
        if (!(l <= r && 0 <= l && r <= n)) {
            deb(l, r, n);
            assert(0);
        }
        if (l == 0) { return rv[r]; }
        else {
            if (!build) {
                vector<pair<T, int>> v2;
                rep(i, ve.size()) { v2.emplace_back(pair<T, int>(ve[i], i)); }
                spa.build(v2, pair<T, int>(e, -1), maxq), build = true;
            }
            return spa(l, r).first;
        }
    }
    T operator()(int r = inf) { return operator()(0, min(r, n)); }
    T operator[](int r) { return operator()(0, r); }
    T getv(int l, int r) { return operator()(l, r); }
    T getv(int r = inf) { return getv(0, min(r, n)); };
    int geti(int l, int r) {
        assert(l <= r && 0 <= l && r <= n);
        if (l == 0) { return ri[r]; }
        else {
            if (!build)spa.build(ve, e, maxq), build = true;
            return spa.query(l, r).second;
        }
    }
    int geti(int r = inf) { return geti(0, min(r, n)); };
    auto begin() { return rv.begin(); }
    auto end() { return rv.end(); }
};
template<class T> struct ruimin {
private:
    vector<T> ve;
    id6<pair<T, int>> spa;
    vector<T> rv;
    vector<int> ri;
    bool build = false;
    int n;
    T e;
public:
    ruimin(vector<T> &a, T e) : ve(a), n(sz(a)), e(e) {
        int index = -1;
        T mi = numeric_limits<T>::max();
        rv.resize(n + 1);
        ri.resize(n + 1);
        rv[0] = e;
        ri[0] = -1;
        rep(i, n) {
            if (chmi(mi, a[i])) { index = i; }
            rv[i + 1] = mi;
            ri[i + 1] = index;
        }
    }
    T operator()(int l, int r) {
        assert(l <= r && 0 <= l && r <= n);
        if (l == 0) { return rv[r]; }
        else {
            if (!build) {
                vector<pair<T, int>> v2;
                rep(i, ve.size()) { v2.emplace_back(pair<T, int>(ve[i], i)); }
                spa.build(v2, pair<T, int>(e, -1), minq), build = true;
            }
            return spa(l, r).first;
        }
    }
    T operator()(int r = inf) { return operator()(0, min(r, n)); }
    T operator[](int r) { return operator()(0, r); }
    T getv(int l, int r) { return operator()(l, r); }
    T getv(int r = inf) { return getv(0, min(r, n)); };
    int geti(int l, int r) {
        {
            assert(l <= r && 0 <= l && r <= n);
            if (l == 0) { return ri[r]; }
            else {
                if (!build)spa.build(ve, e, minq), build = true;
                return spa.query(l, r).second;
            }
        }
        assert(l <= r && 0 <= l && r <= n);
        if (l == 0) { return ri[r]; }
        else {
            if (!build)spa.build(ve), build = true;
            return spa.query(l, r).second;
        }
    }
    int geti(int r = inf) { return geti(0, min(r, n)); };
    auto begin() { return rv.begin(); }
    auto end() { return rv.end(); }
};

vvi() ruib(vi &a) {    vvi(res, 61, sz(a) + 1);    rep(k, 61) { rep(i, sz(a)) { res[k][i + 1] = res[k][i] + ((a[i] >> k) & 1); }}    return res;}
vector<ruiC<int>> id11(vi &a) {vector<ruiC<int>> ret(61);    vvi(res, 61, sz(a));    rep(k, 61) {        rep(i, sz(a)) { res[k][i] = (a[i] >> k) & 1; }        ret[k] = ruic(res[k]);    }    return ret;}


template<class T, class U> vi ruiv(T &a, U k) {    vi ret(a.size() + 1);    rep(i, a.size())ret[i + 1] = ret[i] + (a[i] == k);    return ret;}
template<class T, class U> ruiC<ll> ruic(T &a, U k) {    vi ret = ruiv(a, k);    return ruiC<ll>(ret);}
template<class T> struct id20 {
    int H;
    vector<ruiC<T>> rui;
    ruiC<T> dummy;

    id20(const vector<vector<T>> &ru) : rui(sz(ru)), H(sz(ru)) {            for (int h = 0; h < H; h++) {                if (sz(ru[h]) == 0)continue;                if (sz(dummy) == 1) dummy = ruic(vector<T>(sz(ru[h])));                rui[h] = ruic(ru[h]);            }        }
    

    vector<T> operator()(ll l, ll r) {            if (l > r) {                cerr << "ruic ";                deb(l, r);                assert(0);            }            vector<T> res(H);            for (int h = 0; h < H; h++)res[h] = rui[h](l, r);            return res;        }
    

    ruiC<T> &operator[](ll h) {

        if (h >= H) {message += "warning ruiC h >= H";}

        if (h >= H || sz(rui[h]) == 1)return dummy;else return rui[h];
    }
    
    

    
    


    








};

template<class U, typename Iterable, class is_Iterable = typename Iterable::value_type>
ruiC<ll> id25(Iterable &a, U b) {    vi cou(sz(a));    rep(i, sz(a)) { cou[i] = a[i] == b; }    return ruic(cou);}

template<class U, typename Iterable, class is_Iterable = typename Iterable::value_type>
vector<ll> id27(Iterable &a, U b) {    vi cou(sz(a));    rep(i, sz(a)) { cou[i] = a[i] == b; }    return ruiv(cou);}









template<typename Iterable, class is_Iterable = typename Iterable::value_type>
id20<ll> id25(const Iterable &a) {        int H = max(a) + 1;        vvi(cou, H);        rep(i, sz(a)) {            if (sz(cou[a[i]]) == 0)cou[a[i]].resize(sz(a));            cou[a[i]][i] = 1;        }        return id20<ll>(cou);    }





template<class T> vector<T> imosh(vector<vector<T>> &v, int w) {    vector<T> ret(sz(v));    rep(h, sz(ret)) { ret[h] = v[h][w]; }    rep(i, sz(ret) - 1) { ret[i + 1] += ret[i]; }    return ret;}
template<class T> vector<T> ruih(vector<vector<T>> &v, int w) {    vector<T> ret(sz(v) + 1);    rep(h, sz(v)) { ret[h + 1] = v[h][w]; }    rep(i, sz(v)) { ret[i + 1] += ret[i]; }    return ret;}
template<class T> ruiC<T> ruihc(vector<vector<T>> &a, int w) {    vector<T> ret = ruih(a, w);    return ruiC<T>(ret);}



template<class T> struct id10 {
    vector<T> rui;
    id10(vector<T> &ru) : rui(ru) {}
    T operator()(ll l, ll r) {        if (l > r) {            cerr << "ruiXc ";            deb(l, r);            assert(0);        }        return rui[r] ^ rui[l];    }
    T operator[](ll i) { return rui[i]; }
    T back() { return rui.back(); }
    ll size() { return rui.size(); }
};
template<class T> vector<T> ruix(vector<T> &a) {    vector<T> ret(a.size() + 1);    rep(i, a.size())ret[i + 1] = ret[i] ^ a[i];    return ret;}
template<class T> id10<ll> id16(vector<T> &a) {    vi ret = ruix(a);    return id10<ll>(ret);}










vi id3(vi &A) {    int N = sz(A);    assert(N);    vi res(N + 1);    res[0] = A[0];    rep(i, 1, N) { res[i] = A[i - 1] ^ A[i]; }    res[N] = A[N - 1];    return res;}

template<class T> vector<T> ruim(vector<T> &a) {    vector<T> res(a.size() + 1, 1);    rep(i, a.size())res[i + 1] = res[i] * a[i];    return res;}


template<class T> vector<T> ruimi(vector<T> &a) {ll n = sz(a);    vector<T> ret(n + 1);    rep(i, 1, n) {        ret[i] = a[i - 1];        chmi(ret[i + 1], ret[i]);    }    return ret;}




template<class T> struct id13 {
    vector<T> rui;
    int n;
    id13(vector<T> &a) : n(sz(a)) {        rui.resize(n + 1);        rer(i, n - 1) { rui[i] = rui[i + 1] + a[i]; }    }
    
    T operator()(int r, int l) {        r++;        l++;        assert(l <= r && l >= 0 && r <= n);        return rui[l] - rui[r];    }
    T operator()(int l) { return operator()(n - 1, l); }
    T operator[](int i) { return operator()(i); }
};


template<class T> id13<T> id8(vector<T> &a) { return id13<T>(a); }



template<class T> struct id14 {
    vector<T> rv;
    int n;
    id14(vector<T> &a) : rv(a), n(sz(a)) {        rv.resize(n + 1);        rv[0] = 1;        rep(i, n) { rv[i + 1] = a[i] * rv[i]; }    }
    id14() : n(0) {        rv.resize(n + 1);        rv[0] = 1;    }
    void operator+=(T v) {        rv.push_back(rv.back() * v);        n++;    }
    T operator()(int l, int r) {        assert(l <= r && 0 <= l && r <= n);        return rv[r] / rv[l];    }
    T operator()(int r = inf) { return operator()(0, min(r, n)); }
    T operator[](int r) { return operator()(0, r); }
    auto begin() { return rv.begin(); }
    auto end() { return rv.end(); }
};
template<class T> id14<T> ruimul(vector<T> &a) { return id14<T>(a); }
template<class T> id14<T> ruimul() {    vector<T> a;    return id14<T>(a);}
template<class T> T *id28(vector<T> &a) {    ll len = a.size();    T *body = (T *) malloc((len + 1) * sizeof(T));    T *res = body + 1;    res[len - 1] = 1;    rer(i, len - 1)res[i - 1] = res[i] * a[i];    return res;}
template<class T, class U, class W> T lowerBound(ruiC <T> &a, U v, W banpei) { return lowerBound(a.rui, v, banpei); }
template<class T, class U, class W> T upperBound(ruiC <T> &a, U v, W banpei) { return upperBound(a.rui, v, banpei); }
template<class T, class U, class W> T id29(ruiC <T> &a, U v, W banpei) { return id29(a.rui, v, banpei); }
template<class T, class U, class W> T id5(ruiC <T> &a, U v, W banpei) { return id5(a.rui, v, banpei); }
template<class T> string id2(const ruiC<T> &a) {return id2(a.rui);}
template<class T> ostream &operator<<(ostream &os, ruiC<T> a) {    fora(v, a.rui){os << v << " "; }   return os;}
template<class T> ostream &operator<<(ostream &os, id13<T> a) {    fora(v, a.rui){os << v << " "; }   return os;}
template<class T> string id2(id13<T> &a) {return id2(a.rui);}

template<class T> struct id24 {
    vector<T> rui;
    vector<T> ruir;

    using F = function<T(T, T)>;
    T e;
    F func;
    int N;
    id24(vector<T> &arg, F f, const T &e) : func(f), e(e) {N = (int) arg.size();rui.resize(N + 1, e);ruir.resize(N + 1, e);for (int i = 0; i < N; i++) {rui[i + 1] = func(rui[i], arg[i]);ruir[N - i - 1] = func(arg[N - i - 1], ruir[N - i]);}deb(rui);deb(ruir);}
    T get() {return rui.back();}
    T getl(int r) {assert(r <= N);return rui[r];}
    T getr(int l) {assert(l >= 0);return ruir[l];}
    

    T get_other(int m) {return func(getl(m), getr(m + 1));}
};


void solve() {
    int Q;
    cin >> Q;
    vi p10(13);
    p10[0]=1;
    rep(i, 12){
        p10[i+1] = p10[i]*10;
    }
    while (Q--) {
        din(N, K);
        string S = to_string(N);
        int keta = sz(S);
        int mi = (pow<int>(10, keta + 1) - 1) / 9;
        rep(mas, 2, bit(10)) {
            if (bcou(mas) != K)continue;
            vc can;
            rep(i, 10)if (bget(mas, i))can += '0'+i;
            

            string maxT = string(keta, can.back());
            if(maxT < S)continue;

            string minT =  string(1,S[0])+ string(keta-1, can[0]);
            if(stoll(minT) > mi)continue;

            int maxTv = stoll(maxT);
            int Sv = stoll(S);
            int tv = 0;
            rep(k, keta) {
                if (bget(mas, S[k] - '0')) {
                    int c = S[k];


                    

                    

                    if (c == S[k] && maxTv / 10 >= Sv % p10[keta - k - 1]) {
                        maxTv /= 10;
                        Sv = Sv % p10[keta - k - 1];
                        tv *= 10;
                        tv += c - '0';
                        continue;
                    }
                }
                {
                    int c = upperBound(can, S[k], -1);
                    tv *= 10;
                    tv += c - '0';
                    rep(nk, k + 1, keta) {
                        tv *= 10;
                        tv += can[0] - '0';
                    }
                    break;


                }
            }
            chmi(mi, tv);
        }
        out(mi);
    }

}

signed main() {
    solve();

    return 0;
}