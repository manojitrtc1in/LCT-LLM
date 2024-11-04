





using namespace std;
using namespace __gnu_pbds;
using LL = long long;
using LD = long double;
using PII = pair<int, int>;
using PLI = pair<long long, int>;
using PLL = pair<long long, long long>;
using TI = tuple<int, int, int>;
using TL = tuple<LL, LL, LL>;
mt19937 mrand(random_device{}());
int rnd(int x) { return mrand() % x; }
int bcnt(const int64_t &a) { return __builtin_popcountll(a); }
template <class A, class B> B conv(const A &a, B b = B()) {
    stringstream s;
    s << a, s >> b;
    return b;
}
template <class T> T inf() { return numeric_limits<T>::max() / 2; }
template <class T> T sign(const T &a) { return a == 0 ? 0 : (a < 0 ? -1 : 1); }
template <class T> T floor(const T &a, const T &b) {
    assert(b != 0);
    return sign(a) * sign(b) > 0 ? abs(a) / abs(b) : -(abs(a) + abs(b) - 1) / abs(b);
}
template <class T> T ceil(const T &a, const T &b) {
    assert(b != 0);
    return sign(a) * sign(b) > 0 ? (abs(a) + abs(b) - 1) / abs(b) : -abs(a) / abs(b);
}
template <class T> int lowb(const vector<T>& a, T b) { return lower_bound(ALL(a), b) - a.begin(); }
template <class T> int uppb(const vector<T>& a, T b) { return upper_bound(ALL(a), b) - a.begin(); }
template <class T> bool chmin(T &a, T b) { return b < a ? a = b, true : false; }
template <class T> bool chmax(T &a, T b) { return b > a ? a = b, true : false; }
template <class T> auto min(const T &a) { return *min_element(ALL(a)); } 
template <class T> auto max(const T &a) { return *max_element(ALL(a)); }
template <class T> auto sum(const T &a) { return accumulate(ALL(a), (typename T::value_type)0); }
template <> auto sum(const vector<int> &a) { return accumulate(ALL(a), 0LL); }
template <> auto sum(const vector<string> &a) { return accumulate(ALL(a), string()); }
template <class T> void id9(T &a) { sort(ALL(a)); a.erase(unique(ALL(a)), a.end()); }
template <class T> auto vect(const T &v, int n) { return vector<T>(n, v); }
template <class T, class... D> auto vect(const T& v, int n, D... m) {
    return vector<decltype(vect(v, m...))>(n, vect(v, m...));
}



template <typename T> void in(T &a) { cin >> a; }
template <typename A, typename... B> void in(A &a, B &... b) { in(a), in(b...); }
template <typename A, typename B> void in(pair<A, B> &p) { in(p.first, p.second); }
template <typename A, typename B, typename C> void in(tuple<A, B, C> &p) { in(get<0>(p), get<1>(p), get<2>(p)); }
template <typename T, size_t N> void in(array<T, N> &a) { for (auto &v: a) in(v); }
template <typename T> void in(vector<T> &vec) { for (auto& v: vec) in(v); }
template <typename T, size_t N>
istream& operator >>(istream& inp, array<T, N> &a) {
    for (auto &v: a) inp >> v;
    return inp;
}
template <typename T>
istream& operator >>(istream& inp, vector<T> &a) {
    for (auto &v: a) inp >> v;
    return inp;
}
template <typename A, typename B>
istream& operator >>(istream& inp, pair<A, B> &p) {
    inp >> p.first >> p.second;
    return inp;
}
template <typename A, typename B, typename C>
istream& operator >>(istream& inp, tuple<A, B, C> &p) {
    inp >> get<0>(p) >> get<1>(p) >> get<2>(p);
    return inp;
}
void ou() { cout << '\n'; }
template<typename T> void ou(const T &a) { cout << a << '\n'; }
template <typename A, typename... B> void ou(const A &a, const B &... b) {
    cout << a << ' ', ou(b...);
}
template<typename A, typename B> void ou(const pair<A, B> &p) {
    cout << p.first << ' ' << p.second << '\n';
}
template<typename A, typename B, typename C> void ou(const tuple<A, B, C> &p) {
    cout << get<0>(p) << ' ' << get<1>(p) << ' ' << get<2>(p) << '\n';
}
void ou(const vector<int> &vec) {
    int n = SZ(vec);
    for (int i = 0; i < n; i++) cout << vec[i] << " \n"[i == n - 1];
}
void ou(const vector<LL> &vec) {
    int n = SZ(vec);
    for (int i = 0; i < n; i++) cout << vec[i] << " \n"[i == n - 1];
}
void ou(const vector<double> &vec) {
    int n = SZ(vec);
    for (int i = 0; i < n; i++) cout << vec[i] << " \n"[i == n - 1];
}
template <typename A> void ou(const vector<A> &vec) {
    for (auto &v: vec) ou(v);
}
template<size_t N> void ou(const array<int, N> &a) {
    for (int i = 0; i < N; i++) cout << a[i] << " \n"[i == N - 1];
}
template<class T> inline void YES(T condition) { 
    if(condition) cout << "YES" << '\n';
    else cout << "NO" << '\n';
}
template<class T> inline void Yes(T condition) {
    if(condition) cout << "Yes" << '\n';
    else cout << "No" << '\n';
}









template<class T>
using ordered_set = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
template<class T> T lcm(T a, T b){
    return a / gcd(a, b) * b;
}
int dx[8] = {1, 0, -1, 0, 1, 1, -1, -1};
int dy[8] = {0, 1, 0, -1, 1, -1, 1, -1};

















namespace atcoder {

namespace internal {





constexpr long long safe_mod(long long x, long long m) {
    x %= m;
    if (x < 0) x += m;
    return x;
}







struct barrett {
    unsigned int _m;
    unsigned long long im;

    

    explicit barrett(unsigned int m) : _m(m), im((unsigned long long)(-1) / m + 1) {}

    

    unsigned int umod() const { return _m; }

    

    

    

    unsigned int mul(unsigned int a, unsigned int b) const {
        

        


        

        

        

        

        

        

        

        unsigned long long z = a;
        z *= b;

        unsigned long long x;
        _umul128(z, im, &x);

        unsigned long long x =
            (unsigned long long)(((unsigned __int128)(z)*im) >> 64);

        unsigned int v = (unsigned int)(z - x * _m);
        if (_m <= v) v += _m;
        return v;
    }
};







constexpr long long id12(long long x, long long n, int m) {
    if (m == 1) return 0;
    unsigned int _m = (unsigned int)(m);
    unsigned long long r = 1;
    unsigned long long y = safe_mod(x, m);
    while (n) {
        if (n & 1) r = (r * y) % _m;
        y = (y * y) % _m;
        n >>= 1;
    }
    return r;
}









constexpr bool id10(int n) {
    if (n <= 1) return false;
    if (n == 2 || n == 7 || n == 61) return true;
    if (n % 2 == 0) return false;
    long long d = n - 1;
    while (d % 2 == 0) d /= 2;
    constexpr long long bases[3] = {2, 7, 61};
    for (long long a : bases) {
        long long t = d;
        long long y = id12(a, t, n);
        while (t != n - 1 && y != 1 && y != n - 1) {
            y = y * y % n;
            t <<= 1;
        }
        if (y != n - 1 && t % 2 == 0) {
            return false;
        }
    }
    return true;
}
template <int n> constexpr bool is_prime = id10(n);





constexpr std::pair<long long, long long> id1(long long a, long long b) {
    a = safe_mod(a, b);
    if (a == 0) return {b, 0};

    

    

    

    

    long long s = b, t = a;
    long long m0 = 0, m1 = 1;

    while (t) {
        long long u = s / t;
        s -= t * u;
        m0 -= m1 * u;  


        

        

        

        


        auto tmp = s;
        s = t;
        t = tmp;
        tmp = m0;
        m0 = m1;
        m1 = tmp;
    }
    

    

    if (m0 < 0) m0 += b / s;
    return {s, m0};
}







constexpr int id4(int m) {
    if (m == 2) return 1;
    if (m == 167772161) return 3;
    if (m == 469762049) return 3;
    if (m == 754974721) return 11;
    if (m == 998244353) return 3;
    int divs[20] = {};
    divs[0] = 2;
    int cnt = 1;
    int x = (m - 1) / 2;
    while (x % 2 == 0) x /= 2;
    for (int i = 3; (long long)(i)*i <= x; i += 2) {
        if (x % i == 0) {
            divs[cnt++] = i;
            while (x % i == 0) {
                x /= i;
            }
        }
    }
    if (x > 1) {
        divs[cnt++] = x;
    }
    for (int g = 2;; g++) {
        bool ok = true;
        for (int i = 0; i < cnt; i++) {
            if (id12(g, (m - 1) / divs[i], m) == 1) {
                ok = false;
                break;
            }
        }
        if (ok) return g;
    }
}
template <int m> constexpr int primitive_root = id4(m);







unsigned long long id0(unsigned long long n,
                                      unsigned long long m,
                                      unsigned long long a,
                                      unsigned long long b) {
    unsigned long long ans = 0;
    while (true) {
        if (a >= m) {
            ans += n * (n - 1) / 2 * (a / m);
            a %= m;
        }
        if (b >= m) {
            ans += n * (b / m);
            b %= m;
        }

        unsigned long long y_max = a * n + b;
        if (y_max < m) break;
        

        

        n = (unsigned long long)(y_max / m);
        b = (unsigned long long)(y_max % m);
        std::swap(m, a);
    }
    return ans;
}

}  


}  












namespace atcoder {

namespace internal {


template <class T>
using is_signed_int128 =
    typename std::conditional<std::is_same<T, __int128_t>::value ||
                                  std::is_same<T, __int128>::value,
                              std::true_type,
                              std::false_type>::type;

template <class T>
using is_unsigned_int128 =
    typename std::conditional<std::is_same<T, __uint128_t>::value ||
                                  std::is_same<T, unsigned __int128>::value,
                              std::true_type,
                              std::false_type>::type;

template <class T>
using make_unsigned_int128 =
    typename std::conditional<std::is_same<T, __int128_t>::value,
                              __uint128_t,
                              unsigned __int128>;

template <class T>
using is_integral = typename std::conditional<std::is_integral<T>::value ||
                                                  is_signed_int128<T>::value ||
                                                  is_unsigned_int128<T>::value,
                                              std::true_type,
                                              std::false_type>::type;

template <class T>
using is_signed_int = typename std::conditional<(is_integral<T>::value &&
                                                 std::is_signed<T>::value) ||
                                                    is_signed_int128<T>::value,
                                                std::true_type,
                                                std::false_type>::type;

template <class T>
using is_unsigned_int =
    typename std::conditional<(is_integral<T>::value &&
                               std::is_unsigned<T>::value) ||
                                  is_unsigned_int128<T>::value,
                              std::true_type,
                              std::false_type>::type;

template <class T>
using to_unsigned = typename std::conditional<
    is_signed_int128<T>::value,
    make_unsigned_int128<T>,
    typename std::conditional<std::is_signed<T>::value,
                              std::make_unsigned<T>,
                              std::common_type<T>>::type>::type;



template <class T> using is_integral = typename std::is_integral<T>;

template <class T>
using is_signed_int =
    typename std::conditional<is_integral<T>::value && std::is_signed<T>::value,
                              std::true_type,
                              std::false_type>::type;

template <class T>
using is_unsigned_int =
    typename std::conditional<is_integral<T>::value &&
                                  std::is_unsigned<T>::value,
                              std::true_type,
                              std::false_type>::type;

template <class T>
using to_unsigned = typename std::conditional<is_signed_int<T>::value,
                                              std::make_unsigned<T>,
                                              std::common_type<T>>::type;



template <class T>
using is_signed_int_t = std::enable_if_t<is_signed_int<T>::value>;

template <class T>
using is_unsigned_int_t = std::enable_if_t<is_unsigned_int<T>::value>;

template <class T> using to_unsigned_t = typename to_unsigned<T>::type;

}  


}  





namespace atcoder {

namespace internal {

struct modint_base {};
struct static_modint_base : modint_base {};

template <class T> using is_modint = std::is_base_of<modint_base, T>;
template <class T> using is_modint_t = std::enable_if_t<is_modint<T>::value>;

}  


template <int m, std::enable_if_t<(1 <= m)>* = nullptr>
struct id7 : internal::static_modint_base {
    using mint = id7;

  public:
    static constexpr int mod() { return m; }
    static mint raw(int v) {
        mint x;
        x._v = v;
        return x;
    }

    id7() : _v(0) {}
    template <class T, internal::is_signed_int_t<T>* = nullptr>
    id7(T v) {
        long long x = (long long)(v % (long long)(umod()));
        if (x < 0) x += umod();
        _v = (unsigned int)(x);
    }
    template <class T, internal::is_unsigned_int_t<T>* = nullptr>
    id7(T v) {
        _v = (unsigned int)(v % umod());
    }

    unsigned int val() const { return _v; }

    mint& operator++() {
        _v++;
        if (_v == umod()) _v = 0;
        return *this;
    }
    mint& operator--() {
        if (_v == 0) _v = umod();
        _v--;
        return *this;
    }
    mint operator++(int) {
        mint result = *this;
        ++*this;
        return result;
    }
    mint operator--(int) {
        mint result = *this;
        --*this;
        return result;
    }

    mint& operator+=(const mint& rhs) {
        _v += rhs._v;
        if (_v >= umod()) _v -= umod();
        return *this;
    }
    mint& operator-=(const mint& rhs) {
        _v -= rhs._v;
        if (_v >= umod()) _v += umod();
        return *this;
    }
    mint& operator*=(const mint& rhs) {
        unsigned long long z = _v;
        z *= rhs._v;
        _v = (unsigned int)(z % umod());
        return *this;
    }
    mint& operator/=(const mint& rhs) { return *this = *this * rhs.inv(); }

    mint operator+() const { return *this; }
    mint operator-() const { return mint() - *this; }

    mint pow(long long n) const {
        assert(0 <= n);
        mint x = *this, r = 1;
        while (n) {
            if (n & 1) r *= x;
            x *= x;
            n >>= 1;
        }
        return r;
    }
    mint inv() const {
        if (prime) {
            assert(_v);
            return pow(umod() - 2);
        } else {
            auto eg = internal::id1(_v, m);
            assert(eg.first == 1);
            return eg.second;
        }
    }

    friend mint operator+(const mint& lhs, const mint& rhs) {
        return mint(lhs) += rhs;
    }
    friend mint operator-(const mint& lhs, const mint& rhs) {
        return mint(lhs) -= rhs;
    }
    friend mint operator*(const mint& lhs, const mint& rhs) {
        return mint(lhs) *= rhs;
    }
    friend mint operator/(const mint& lhs, const mint& rhs) {
        return mint(lhs) /= rhs;
    }
    friend bool operator==(const mint& lhs, const mint& rhs) {
        return lhs._v == rhs._v;
    }
    friend bool operator!=(const mint& lhs, const mint& rhs) {
        return lhs._v != rhs._v;
    }

  private:
    unsigned int _v;
    static constexpr unsigned int umod() { return m; }
    static constexpr bool prime = internal::is_prime<m>;
};

template <int id> struct id5 : internal::modint_base {
    using mint = id5;

  public:
    static int mod() { return (int)(bt.umod()); }
    static void set_mod(int m) {
        assert(1 <= m);
        bt = internal::barrett(m);
    }
    static mint raw(int v) {
        mint x;
        x._v = v;
        return x;
    }

    id5() : _v(0) {}
    template <class T, internal::is_signed_int_t<T>* = nullptr>
    id5(T v) {
        long long x = (long long)(v % (long long)(mod()));
        if (x < 0) x += mod();
        _v = (unsigned int)(x);
    }
    template <class T, internal::is_unsigned_int_t<T>* = nullptr>
    id5(T v) {
        _v = (unsigned int)(v % mod());
    }

    unsigned int val() const { return _v; }

    mint& operator++() {
        _v++;
        if (_v == umod()) _v = 0;
        return *this;
    }
    mint& operator--() {
        if (_v == 0) _v = umod();
        _v--;
        return *this;
    }
    mint operator++(int) {
        mint result = *this;
        ++*this;
        return result;
    }
    mint operator--(int) {
        mint result = *this;
        --*this;
        return result;
    }

    mint& operator+=(const mint& rhs) {
        _v += rhs._v;
        if (_v >= umod()) _v -= umod();
        return *this;
    }
    mint& operator-=(const mint& rhs) {
        _v += mod() - rhs._v;
        if (_v >= umod()) _v -= umod();
        return *this;
    }
    mint& operator*=(const mint& rhs) {
        _v = bt.mul(_v, rhs._v);
        return *this;
    }
    mint& operator/=(const mint& rhs) { return *this = *this * rhs.inv(); }

    mint operator+() const { return *this; }
    mint operator-() const { return mint() - *this; }

    mint pow(long long n) const {
        assert(0 <= n);
        mint x = *this, r = 1;
        while (n) {
            if (n & 1) r *= x;
            x *= x;
            n >>= 1;
        }
        return r;
    }
    mint inv() const {
        auto eg = internal::id1(_v, mod());
        assert(eg.first == 1);
        return eg.second;
    }

    friend mint operator+(const mint& lhs, const mint& rhs) {
        return mint(lhs) += rhs;
    }
    friend mint operator-(const mint& lhs, const mint& rhs) {
        return mint(lhs) -= rhs;
    }
    friend mint operator*(const mint& lhs, const mint& rhs) {
        return mint(lhs) *= rhs;
    }
    friend mint operator/(const mint& lhs, const mint& rhs) {
        return mint(lhs) /= rhs;
    }
    friend bool operator==(const mint& lhs, const mint& rhs) {
        return lhs._v == rhs._v;
    }
    friend bool operator!=(const mint& lhs, const mint& rhs) {
        return lhs._v != rhs._v;
    }

  private:
    unsigned int _v;
    static internal::barrett bt;
    static unsigned int umod() { return bt.umod(); }
};
template <int id> internal::barrett id5<id>::bt(998244353);

using modint998244353 = id7<998244353>;
using modint1000000007 = id7<1000000007>;



namespace internal {

template <class T>
using is_static_modint = std::is_base_of<internal::static_modint_base, T>;

template <class T>
using is_static_modint_t = std::enable_if_t<is_static_modint<T>::value>;

template <class> struct is_dynamic_modint : public std::false_type {};
template <int id>
struct is_dynamic_modint<id5<id>> : public std::true_type {};

template <class T>
using is_dynamic_modint_t = std::enable_if_t<is_dynamic_modint<T>::value>;

}  


}  





using mint = atcoder::modint1000000007;
ostream& operator <<(ostream& out, const mint& a) {
    out << a.val(); return out;
}
const int maxn = 10000;
mint fac[maxn + 5];
mint invfac[maxn + 5];
void init() {
    fac[0] = 1;
    for (int i = 1; i <= maxn; i++) fac[i] = fac[i - 1] * mint::raw(i);
    invfac[maxn] = fac[maxn].inv();
    for (int i = maxn - 1; i >= 0; i--) invfac[i] = invfac[i + 1] * mint::raw(i + 1);
}
mint C(int n, int k) {
    assert(n >= 0 && 0 <= k && n >= k);
    return fac[n] * invfac[k] * invfac[n - k];
}

const string COLOR_RESET = "\033[0m";
const string id8 = "\033[1;32m";
const string id11 = "\033[1;31m";
const string id6 = "\033[1;36m";
const string id2 = "\033[0;9;37m";
const string RED_BACKGROUND = "\033[1;41m";
const string id3 = "\033[0;2m";
template<class A, class B> ostream& operator <<(ostream& out, const pair<A, B> &p) {
    return out << "(" << p.first << ", " << p.second << ")";
}
template<class A, class B, class C> ostream& operator <<(ostream& out, const tuple<A, B, C> &p) {
    return out << "(" << get<0>(p) << ", " << get<1>(p) << ", " << get<2>(p) << ")";
}
template <typename T, size_t N>
ostream& operator <<(ostream& out, const array<T, N>& a) {
    out << "["; for (int i = 0; i < (int)N; i++) out << a[i] << (i == N - 1 ? "]" : ", "); return out;
}
template <typename T>
ostream& operator <<(ostream& out, const vector<T>& a) {
    out << "["; for (int i = 0; i < (int)(a.size()); i++) out << a[i] << (i == (int)(a.size()) - 1 ? "]" : ", "); return out;
}
template <typename T>
ostream& operator <<(ostream& out, const deque<T>& a) {
    out << "["; for (int i = 0; i < (int)(a.size()); i++) out << a[i] << (i == (int)(a.size()) - 1 ? "]" : ", "); return out;
}
template <typename T, class Cmp>
ostream& operator <<(ostream& out, const set<T, Cmp>& a) {
    out << "{"; for (auto it = a.begin(); it != a.end(); it++) out << *it << (it == --a.end() ? "}" : ", "); return out;
}
template <typename T, class Cmp>
ostream& operator <<(ostream &out, const multiset<T, Cmp>& a) {
    out << "{"; for (auto it = a.begin(); it != a.end(); it++) out << *it << (it == --a.end() ? "}" : ", "); return out;
}
template <typename T>
ostream& operator <<(ostream& out, const unordered_set<T>& a) {
    out << "{"; for (auto it = a.begin(); it != a.end(); it++) out << *it << (it == --a.end() ? "}" : ", "); return out;
}
template <typename U, typename T, class Cmp>
ostream& operator <<(ostream& out, const map<U, T, Cmp>& a) {
    out << "{"; for (auto it = a.begin(); it != a.end(); it++) out << it->first << ":" << it->second << (it == --a.end() ? "}" : ", "); return out;
}
template <typename U, class Cmp>
ostream& operator <<(ostream& out, priority_queue<U, vector<U>, Cmp>& a) {
    out << "{"; bool first = true;
    priority_queue<U, vector<U>, Cmp> tmp;
    while (!a.empty()) { out << (first ? "" : ", "); out << a.top(); tmp.emplace(a.top()); a.pop(); first = 0; } out << "}";
    a = move(tmp);
    return out;
}


 


template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
    cerr << id6 << name << COLOR_RESET << ": " << arg1 << COLOR_RESET << endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
    const char* comma = strchr(names + 1, ',');
    cerr << id6;
    cerr.write(names, comma - names) << COLOR_RESET << ": " << arg1 << ' ';
    cerr << id11 << "| " << COLOR_RESET;
    __f(comma + 1, args...);
}




int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(10);










    init();

    int n; cin >> n;
    LL L, R, X; cin >> L >> R >> X;
    const int B = 60;

    auto solve = [&](LL r) -> mint {
        auto dp = vect<mint>(0, B + 1, n + 1);
        dp[B][0] = 1;
        for (int b = B - 1; b >= 0; b--) {
            int st = X >> b & 1;
            for (int x = 0; x <= n; x++) if (dp[b + 1][x].val()) {
                int y = 2 * x + (r >> b & 1);
                for (int t = st; t <= n && t <= y; t += 2) {
                    dp[b][min(n, y - t)] += dp[b + 1][x] * C(n, t);
                }
            }
            if (b <= 2) trace(r, b, dp[b]);
        }
        return accumulate(ALL(dp[0]), mint(0));
    };
    mint ans = solve(R) - solve(L - 1);
    ou(ans.val());










    return 0;
}