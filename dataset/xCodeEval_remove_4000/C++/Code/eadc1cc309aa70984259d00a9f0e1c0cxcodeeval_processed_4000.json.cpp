













































































































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






template<typename T, typename U = typename T::value_type> std::true_type id3(signed);

template<typename T> std::false_type id3(long);
template<typename T> struct has_value_type : decltype(id3<T>(0)) {};
template<class T> inline constexpr bool id1 = has_value_type<T>::value;

template<class T> struct is_vector : std::false_type {};
template<class T> struct is_vector<std::vector<T>> : std::true_type {};
template<class T> inline constexpr bool id5 = is_vector<T>::value;

template<class T1, class T2, bool id2 = (sizeof(T1) > sizeof(T2))> struct max_type { typedef T1 type; };
template<class T1, class T2> struct max_type<T1, T2, false> { typedef T2 type; };



template<class T> using value_type_t = typename T::value_type;


template<class T, bool end = !has_value_type<T>::value> struct value_type_rec { typedef T type; };
template<class T> struct value_type_rec<T, false> { typedef typename value_type_rec<value_type_t<T>>::type type; };
template<class T> using value_type_rec_t = typename value_type_rec<T>::type;



template<class T, bool end = is_same<T, remove_extent_t<T>>::value> struct remove_extent_rec { typedef T type; };
template<class T> struct remove_extent_rec<T, false> { typedef typename remove_extent_rec<remove_extent_t<T>>::type type; };
template<class T> using remove_extent_rec_t = typename remove_extent_rec<T>::type;








using vb = vector<bool>;
using vc = vector<char>;
using vi = vector<int>;
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

template<typename T> class fixed_point
        : T {
public:
    explicit constexpr fixed_point(T &&t) noexcept: T(std::forward<T>(t)) {}
    template<typename... Args> constexpr decltype(auto) operator()(Args &&... args) const { return T::operator()(*this, std::forward<Args>(args)...); }
};
template<typename T> static inline constexpr decltype(auto) fix(T &&t) noexcept { return fixed_point<T>{std::forward<T>(t)}; }


void id4(int &a, int &b, int n) {        if (b == -1) {
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

template<typename W, typename T> void fill(vector<W> &a, const T &v, int l = -1, ll r = -1) {
    id4(l, r, a.size());
    if constexpr(!is_vector<W>::value) { rep(i, l, r)a[i] = v; } else { rep(i, l, r)fill(a[i], v); }
}
template<class Iterable, require_t(id1<Iterable>)> value_type_rec_t<Iterable> sum(const Iterable &a, int l = -1, int r = -1) {
    value_type_rec_t<Iterable> ret = 0;        if constexpr(id5<Iterable>) { id4(l, r, sz(a));                if constexpr(!id1<value_type_t<Iterable>>) { rep(i, l, r) ret += a[i]; } else { rep(i, l, r) ret += sum(a[i]); }} else {                if constexpr(!id1<value_type_t<Iterable>>) { for (auto &v : a) { ret += v; }} else { for (auto &v : a) { ret += sum(v); }}}
    return ret;
}
template<class Iterable, require_t(id1<Iterable>)> value_type_rec_t<Iterable> min(const Iterable &a, int l = -1, int r = -1) {
    value_type_rec_t<Iterable> ret = MAX<value_type_rec_t<Iterable>>();        if constexpr(id5<Iterable>) { id4(l, r, sz(a));                if constexpr(!id1<value_type_t<Iterable>>) { rep(i, l, r) ret = min(ret, a[i]); } else { rep(i, l, r) ret = min(ret, min(a[i])); }} else {                if constexpr(!id1<value_type_t<Iterable>>) { for (auto &v : a) { ret = min(ret, v); }} else { for (auto &v : a) { ret = min(ret, min(v)); }}}
    return ret;
}
template<class Iterable, require_t(id1<Iterable>)> value_type_rec_t<Iterable> max(const Iterable &a, int l = -1, int r = -1) {value_type_rec_t<Iterable> ret = MIN<value_type_rec_t<Iterable>>();        if constexpr(id5<Iterable>) {        id4(l, r, sz(a));                if constexpr(!id1<value_type_t<Iterable>>){            rep(i, l, r) ret = max(ret, a[i]);        }else{            rep(i, l, r) ret = max(ret, max(a[i]));        }    }    else {                if constexpr(!id1<value_type_t<Iterable>>){            for (auto &v : a) { ret = max(ret, v); }        }else{            for (auto &v : a) { ret = max(ret, max(v)); }        }    }    return ret;}

template<class Array, class T, size_t N> void fill(Array(&a)[N] , const T& v, int l = -1, int r = -1) {    id4(l, r, N);    if constexpr(is_same_v<Array, remove_extent_t<Array>>){        rep(i, l, r) a[i] = v;    }else{        rep(i, l, r) fill(a[i], v);    }}
template<class Array, size_t N> remove_extent_rec_t<Array> sum(const Array(&a)[N] , int l = -1, int r = -1) {    remove_extent_rec_t<Array> ret = 0;    id4(l, r, N);    if constexpr(is_same_v<Array, remove_extent_t<Array>>){        rep(i, l, r) ret += a[i];    }else{        rep(i, l, r) ret += sum(a[i]);    }    return ret;}
template<class Array, size_t N> remove_extent_rec_t<Array> min(const Array(&a)[N] , int l = -1, int r = -1) {    remove_extent_rec_t<Array> ret = MAX<remove_extent_rec_t<Array>>();    id4(l, r, N);    if constexpr(is_same_v<Array, remove_extent_t<Array>>){        rep(i, l, r) ret = std::min(ret, a[i]);    }else{        rep(i, l, r) ret = std::min(ret, min(a[i]));    }    return ret;}
template<class Array, size_t N> remove_extent_rec_t<Array> max(const Array(&a)[N] , int l = -1, int r = -1) {    remove_extent_rec_t<Array> ret = MIN<remove_extent_rec_t<Array>>();    id4(l, r, N);    if constexpr(is_same_v<Array, remove_extent_t<Array>>){        rep(i, l, r) ret = std::max(ret, a[i]);    }else{        rep(i, l, r) ret = std::max(ret, max(a[i]));    }    return ret;}
template<class T> void na(vector<T> &A, int N) {A.resize(N);for (int i = 0; i < N; i++) { cin >> A[i]; }}



template<class T, class U> pair<T, U> operator+=(pair<T,U> &a, const pair<T,U> & b) {a.fi+=b.fi;a.se+=b.se; return a;}
template<class T, class U> pair<T, U> operator+(const pair<T, U> &a, const pair<T, U> &b) { pair<T, U> c = a;c += b;return c;}

template<class T, class U> pair<T, U> operator-=(pair<T,U> &a, const pair<T,U> & b) {a.fi-=b.fi;a.se-=b.se; return a;}
template<class T, class U> pair<T, U> operator-(const pair<T, U> &a, const pair<T, U> &b) { pair<T, U> c = a;c -= b;return c;}

template<class T, class U, class V> pair<T, U> operator*=(pair<T, U> &a, const V& b) { a.fi*=b;a.se*=b; return a;}
template<class T, class U, class V> pair<T, U> operator*(const pair<T, U> &a, const V& b) { pair<T, U> c = a;c *= b;return c; }

template<class T, class U, class V> pair<T, U> operator/=(pair<T, U> &a, const V& b) { a.fi/=b;a.se/=b; return a;}
template<class T, class U, class V> pair<T, U> operator/(const pair<T, U> &a, const V& b) { pair<T, U> c = a;c /= b;return c; }

template<class T, class U> pair<T, U> operator-(const pair<T, U> &a) { return pair<T, U>(-a.first, -a.second); }












template<class Iterable, class T = typename Iterable::value_type>
vector<pair<T, signed>> run_length(const Iterable &a) {
    vector<pair<T, signed>> ret;
    ret.emplace_back(a[0], 1);
    for (signed i = 1; i < (signed) a.size(); i++) {
        if (ret.back().first == a[i]) {
            ret.back().second++;
        } else {
            ret.emplace_back(a[i], 1);
        }
    }
    return ret;
}


signed main() {
    int Q;
    cin >> Q;
    while (Q--) {
        int N, K, X;
        cin >> N >> K >> X;
        X--;
        string S;
        cin >> S;
        

        auto run = run_length(S);
        string res;
        rer(i, sz(run) - 1) {
            auto[c, cou] = run[i];
            if (c == 'a') {
                res += string(cou, 'a');
            } else {
                int k = cou * K + 1;
                res += string(X % k, 'b');
                X /= k;
            }
        }
        reverse(ALL(res));
        cout << res << endl;
    }


    return 0;
}