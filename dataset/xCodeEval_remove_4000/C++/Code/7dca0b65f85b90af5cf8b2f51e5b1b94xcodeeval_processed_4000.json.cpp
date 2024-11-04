


















    for (auto &x : a)                                                          \
    f







    {                                                                          \
        vector<string> S(1);                                                   \
        int A = 0;                                                             \
        for (auto V : 
            if (V == ',' && !A)                                                \
                S.push_back("");                                               \
            elif (S.back().size() || V != ' ') S.back().push_back(V),          \
                A += map<char, int>{{'(', 1}, {')', -1}}[V];                   \
        }                                                                      \
        cout << "\x1b[33mDebugging @ Line " << __LINE__ << ":\x1b[0m\n";       \
        debu_(S.begin(), __VA_ARGS__);                                         \
    }






using namespace std;
using namespace __gnu_pbds;
template <class I, class T> void debu_(I i, const T &a) {
    cout << "\x1b[33m    " << *i << " = " << a << "\x1b[0m" << endl;
}
template <class I, class A, class... B>
void debu_(I i, const A &a, const B &... b) {
    cout << "\x1b[33m    " << *i << " = " << a << "\x1b[0m" << endl;
    debu_(++i, b...);
}
gene int bcnt(const T &a) { return __builtin_popcount(a); }
template <> int bcnt(const int64_t &a) { return __builtin_popcountll(a); }
gene int blen(const T &a) { return a ? 1 + blen(a / 2) : 0; }
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
gene T rint(T l, T r) { return uniform_int_distribution<T>(l, r)(rng); }
template <class A, class B> B conv(const A &a, B b = B()) {
    stringstream s;
    s << a, s >> b;
    return b;
}
vector<string> spli(const string &s) {
    vector<string> r;
    for (int i = 0, j; i < int(s.size()); ++i)
        if (s[i] != ' ') {
            r.push_back("");
            for (j = i; j < int(s.size()) && s[j] != ' '; ++j)
                r.back().push_back(s[j]);
            i = j - 1;
        }
    return r;
}
template <class T = int> T inf() { return numeric_limits<T>::max() / 2; }
gene T sign(const T &a) { return a == 0 ? 0 : (a < 0 ? -1 : 1); }
gene T floor(const T &a, const T &b) {
    assert(b != 0);
    return sign(a) * sign(b) > 0 ? abs(a) / abs(b)
                                 : -(abs(a) + abs(b) - 1) / abs(b);
}
gene T ceil(const T &a, const T &b) {
    assert(b != 0);
    return sign(a) * sign(b) > 0 ? (abs(a) + abs(b) - 1) / abs(b)
                                 : -abs(a) / abs(b);
}
gene bool tmin(T &a, T b) { return b < a ? a = b, true : false; }
gene bool tmax(T &a, T b) { return b > a ? a = b, true : false; }
gene auto min(const T &a) { return *min_element(rang(a)); }
gene auto max(const T &a) { return *max_element(rang(a)); }
gene auto sum(const T &a) {
    return accumulate(rang(a), (typename T::value_type)0);
}
template <> auto sum(const vector<int> &a) { return accumulate(rang(a), 0ll); }
template <> auto sum(const vector<string> &a) {
    return accumulate(rang(a), string());
}
template <class T, int N, class I>
auto gath(const T (&a)[N], const vector<I> &b) {
    vector<T> r;
    for (auto i : b)
        r.push_back(a[i]);
    return r;
}
template <class T, class I> auto gath(const T &a, const vector<I> &b) {
    vector<typename T::value_type> r;
    for (auto i : b)
        r.push_back(a[i]);
    return r;
}
template <class T, class C = less<typename T::value_type>>
void sort(T &a, C c = C()) {
    sort(rang(a), c);
}
gene void reve(T &a) { reverse(rang(a)); }
gene void uniq(T &a) { sort(a), a.erase(unique(rang(a)), end(a)); }
gene void shuf(T &a) { shuffle(rang(a), rng); }
gene void merg(T l, T m, T r) { inplace_merge(l, m, r); }
gene auto vect(const vector<T> &v, int n) {
    assert(v.size() <= 1);
    return v.size() ? vector<T>(n, v[0]) : vector<T>(n);
}
template <class T, class... D> auto vect(const vector<T> &v, int n, D... m) {
    return vector<decltype(vect(v, m...))>(n, vect(v, m...));
}
template <class F, class S> istream &operator>>(istream &s, pair<F, S> &a) {
    return s >> a.first >> a.second;
}
template <class F, class S>
ostream &operator<<(ostream &s, const pair<F, S> &a) {
    return s << a.first << " " << a.second;
}
gene istream &operator>>(istream &s, vector<T> &a) {
    for (int i = -1; i < 0 && (!a.size() && (cin >> i, a.resize(i), 0), i = 0),
             i < int(a.size());)
        s >> a[i++];
    return s;
}
gene ostream &operator<<(ostream &s, const vector<T> &a) {
    lv(i, a) cout << a[i] << (i + 1 == int(a.size()) ? "" : " ");
    return s;
}
gene T in() {
    T a;
    cin >> a;
    return a;
}
gene void in(T &a) { cin >> a; }
template <class A, class... B> void in(A &a, B &... b) { cin >> a, in(b...); }
void ou() { cout << endl; }
gene void ou(const T &a) { cout << a << endl; }
template <class A, class... B> void ou(const A &a, const B &... b) {
    cout << a << ' ', ou(b...);
}
gene struct hash_safe {};
template <> struct hash_safe<int> {
    size_t operator()(uint64_t a) const {
        static uint64_t d =
            chrono::steady_clock::now().time_since_epoch().count();
        a += d + 0x9e3779b97f4a7c15, a = (a ^ (a >> 30)) * 0xbf58476d1ce4e5b9;
        a = (a ^ (a >> 27)) * 0x94d049bb133111eb;
        return a ^ (a >> 31);
    }
};
template <> struct hash_safe<int64_t> {
    size_t operator()(uint64_t a) const {
        static uint64_t d =
            chrono::steady_clock::now().time_since_epoch().count();
        a += d + 0x9e3779b97f4a7c15, a = (a ^ (a >> 30)) * 0xbf58476d1ce4e5b9;
        a = (a ^ (a >> 27)) * 0x94d049bb133111eb;
        return a ^ (a >> 31);
    }
};
gene using id2 = unordered_set<T, hash_safe<T>>;
gene using id0 = unordered_multiset<T, hash_safe<T>>;
template <class K, class V>
using unordered_map_safe = unordered_map<K, V, hash_safe<K>>;
template <class K, class V>
using unordered_multimap_safe = unordered_multimap<K, V, hash_safe<K>>;




gene using bbst =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
gene using heap = __gnu_pbds::priority_queue<T, greater<T>, pairing_heap_tag>;
typedef int64_t ll;
typedef long double ld;
typedef string str;
typedef pair<int, int> pii;
typedef pair<int, ll> pil;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<pil> vpil;
typedef vector<pli> vpli;
typedef vector<pll> vpll;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
namespace number_theoretic_transform {

template <class T> T multiply(T x, T y, const T &z) {
    return T((long long)x * y % z);
}
template <>
long long multiply<long long>(long long a, long long b, const long long &c) {
    ll r = 0;
    for (; b; b & 1 ? r = (r + a) % c : 0, b >>= 1, a = (a + a) % c)
        ;
    return r;
}

template <class T> T multiply(const T &x, const T &y, const T &z) {
    return T((long long)x * y % z);
}
template <>
long long multiply<long long>(const long long &x, const long long &y,
                              const long long &z) {
    return (x * y - (long long)(((long double)x * y + 0.5) / z) * z + z) % z;
}

template <class T> T power(T a, T b, const T &c) {
    T r = 1;
    for (; b; b & 1 ? r = multiply(r, a, c) : 0, b >>= 1, a = multiply(a, a, c))
        ;
    return r;
}
template <class T, T p>
void transform(vector<T> &a, const int &n, const int &s, const vector<int> &r) {
    T g = unordered_map<T, T>{{998244353, 3}}.at(p);
    g = s == 1 ? g : power(g, p - 2, p);
    vector<T> wm;
    for (int i = 0; 1 << i <= n; ++i)
        wm.push_back(power(g, (p - 1) >> i, p));
    for (int i = 0; i < n; ++i)
        if (i < r[i])
            swap(a[i], a[r[i]]);
    for (int i = 1, m = 2; 1 << i <= n; ++i, m <<= 1) {
        vector<T> wmk(m >> 1, 1);
        for (int k = 1; k < (m >> 1); ++k)
            wmk[k] = multiply(wmk[k - 1], wm[i], p);
        for (int j = 0; j < n; j += m)
            for (int k = 0; k < (m >> 1); ++k) {
                T u = a[j + k], v = multiply(wmk[k], a[j + k + (m >> 1)], p);
                a[j + k] = u + v, a[j + k + (m >> 1)] = u - v + p;
                if (a[j + k] >= p)
                    a[j + k] -= p;
                if (a[j + k + (m >> 1)] >= p)
                    a[j + k + (m >> 1)] -= p;
            }
    }
}
auto reverse(const int &n, const int &l) {
    vector<int> r(n);
    for (int i = 0; i < n; ++i)
        r[i] = (r[i >> 1] >> 1) | ((i & 1) << (l - 1));
    return r;
}
template <class T, T p> auto multiply(vector<T> a, vector<T> b) {
    int m = int(a.size() + b.size()) - 1, l = 0, n = 1;
    while (n < m)
        n *= 2, ++l;
    auto r = reverse(n, l);
    a.resize(n), b.resize(n);
    transform<T, p>(a, n, 1, r), transform<T, p>(b, n, 1, r);
    for (int i = 0; i < n; ++i)
        a[i] = multiply(a[i], b[i], p);
    transform<T, p>(a, n, -1, r), n = power(n, p - 2, p);
    for (T &v : a)
        v = multiply(v, n, p);
    return a.resize(m), a;
}
template <class T, T p> auto power(vector<T> a, const T &b) {
    int m = int(a.size() - 1) * b + 1, l = 0, n = 1;
    while (n < m)
        n *= 2, ++l;
    auto r = reverse(n, l);
    a.resize(n), transform<T, p>(a, n, 1, r);
    for (int i = 0; i < n; ++i)
        a[i] = power(a[i], b, p);
    transform<T, p>(a, n, -1, r), n = power(n, p - 2, p);
    for (T &v : a)
        v = multiply(v, n, p);
    return a.resize(m), a;
}
} 


using namespace std;
namespace modular_arithmetic {

template <class T> T multiply(T x, T y, const T &z) {
    return T((long long)x * y % z);
}
template <>
long long multiply<long long>(long long a, long long b, const long long &c) {
    ll r = 0;
    for (; b; b & 1 ? r = (r + a) % c : 0, b >>= 1, a = (a + a) % c)
        ;
    return r;
}

template <class T> T multiply(const T &x, const T &y, const T &z) {
    return T((long long)x * y % z);
}
template <>
long long multiply<long long>(const long long &x, const long long &y,
                              const long long &z) {
    return (x * y - (long long)(((long double)x * y + 0.5) / z) * z + z) % z;
}

template <class T = int, T M = 998244353> struct integer {
    integer() : v(0) {}
    
    integer(T t) : v(t) { wrap_around(); }
    void wrap_around() {
        if (v < 0)
            v = (v % M + M) % M;
        else if (v >= M)
            v %= M;
    }
    auto operator-() const {
        integer<T, M> a;
        a.v = (v ? M - v : 0);
        return a;
    }
    auto &operator+=(integer<T, M> a) { return *this = *this + a; }
    auto &operator-=(integer<T, M> a) { return *this = *this - a; }
    auto &operator*=(integer<T, M> a) { return *this = *this * a; }
    auto &operator/=(integer<T, M> a) { return *this = *this / a; }
    auto &operator<<=(T a) { return *this = *this << a; };
    auto &operator>>=(T a) { return *this = *this >> a; };
    friend auto operator/(integer<T, M> a, integer<T, M> b) {
        return a * inverse(b);
    }
    friend auto operator+(integer<T, M> a, integer<T, M> b) {
        integer<T, M> c;
        c.v = a.v + b.v;
        if (c.v >= M)
            c.v -= M;
        return c;
    }
    friend auto operator-(integer<T, M> a, integer<T, M> b) {
        integer<T, M> c;
        c.v = a.v - b.v;
        if (c.v < 0)
            c.v += M;
        return c;
    }
    friend auto operator*(integer<T, M> a, integer<T, M> b) {
        integer<T, M> c;
        c.v = multiply(a.v, b.v, M);
        return c;
    }
    friend auto operator^(integer<T, M> a, T b) { return pow(a, b); }
    friend bool operator==(integer<T, M> a, integer<T, M> b) {
        return a.v == b.v;
    }
    friend bool operator!=(integer<T, M> a, integer<T, M> b) {
        return a.v != b.v;
    }
    friend bool operator<(integer<T, M> a, integer<T, M> b) {
        return a.v < b.v;
    };
    friend bool operator<=(integer<T, M> a, integer<T, M> b) {
        return a.v <= b.v;
    };
    friend bool operator>(integer<T, M> a, integer<T, M> b) {
        return a.v > b.v;
    };
    friend bool operator>=(integer<T, M> a, integer<T, M> b) {
        return a.v >= b.v;
    };
    static auto factorial(T a) {
        assert(a >= 0);
        auto &t = id1;
        while (a >= int(t.size()))
            t.push_back(t.back() * T(t.size()));
        return t[a];
    }
    static auto binary_coefficient(T n, T k) {
        assert(n >= 0 && k >= 0);
        if (n < k)
            return integer<T, M>();
        return factorial(n) / factorial(k) / factorial(n - k);
    }
    static auto random() {
        return integer<T, M>(uniform_int_distribution<T>(0, M - 1)(generator));
    }
    T v;
    static mt19937_64 generator;
    static vector<integer<T, M>> inverse_cache, id1;
};
template <class T, T M>
mt19937_64 integer<T, M>::generator(
    chrono::steady_clock::now().time_since_epoch().count());
template <class T, T M>
vector<integer<T, M>> integer<T, M>::inverse_cache(2, T(1));
template <class T, T M>
vector<integer<T, M>> integer<T, M>::id1(1, T(1));
template <class T, T M> auto &operator>>(istream &s, integer<T, M> &a) {
    s >> a.v;
    a.wrap_around();
    return s;
}
template <class T, T M> auto &operator<<(ostream &s, integer<T, M> a) {
    return s << a.v;
}
template <class T, T M> auto pow(integer<T, M> a, T b) {
    integer<T, M> r(1);
    if (b < 0)
        a = 1 / a, b = -b;
    for (; b; b >>= 1, a = a * a)
        if (b & 1)
            r = r * a;
    return r;
}
template <class T, T M> integer<T, M> inverse(T a) {
    return inverse(integer<T, M>(a));
}
template <class T, T M> integer<T, M> inverse(integer<T, M> a) {
    assert(a.v);
    if (a.v < T(integer<T, M>::inverse_cache.size()))
        return integer<T, M>::inverse_cache[a.v];
    return pow(a, M - 2);
}
template <class T, T M> auto inverse_cached(T a) {
    return inverse_cached(integer<T, M>(a));
}
template <class T, T M> auto inverse_cached(integer<T, M> a) {
    assert(a.v);
    auto &t = integer<T, M>::inverse_cache;
    while (int(t.size()) <= a.v) {
        t.push_back(integer<T, M>(-M / T(t.size())) * t[M % t.size()]);
    }
    return t[a.v];
}
template <class T, T M> auto operator<<(integer<T, M> a, T b) {
    return a * pow(integer<T, M>(2), b);
}
template <class T, T M> auto operator>>(integer<T, M> a, T b) {
    return a / pow(integer<T, M>(2), b);
}


template <class T, T M> auto sqrt(integer<T, M> a) {
    vector<integer<T, M>> r;
    if (!a.v)
        r.push_back(decltype(r)(0));
    else if (pow(a, M - 1 >> 1).v == 1) {
        int s = M - 1, t = 0;
        integer<T, M> b = 1;
        for (; pow(b, M - 1 >> 1).v != M - 1; b = integer<T, M>::random())
            ;
        for (; s % 2 == 0; ++t, s /= 2)
            ;
        integer<T, M> x = pow(a, (s + 1) / 2), e = pow(a, s);
        for (int i = 1; i < t; ++i, e = x * x / a)
            if (pow(e, 1 << t - i - 1).v != 1)
                x = x * pow(b, (1 << i - 1) * s);
        r.push_back(x);
        r.push_back(-x);
    }
    return r;
}
template <class T, T M>
integer<T, M> id3(const vector<T> &y, T x) {
    return id3(y, integer<T, M>(x));
}
template <class T, T M>
integer<T, M> id3(const vector<T> &y, integer<T, M> x) {
    vector<integer<T, M>> t;
    for (auto v : y)
        t.push_back(integer<T, M>(v));
    return id3(t, x);
}
template <class T, T M>
integer<T, M> id3(const vector<integer<T, M>> &y, T x) {
    return id3(y, integer<T, M>(x));
}
template <class T, T M>
integer<T, M> id3(const vector<integer<T, M>> &y,
                                     integer<T, M> x) {
    vector<integer<T, M>> f(1, 1), g(y.size(), x), h(y.size(), x);
    for (int i = 1; i < int(y.size()); ++i) {
        f.push_back(f.back() * inverse_cached<T, M>(i));
        g[i] = h[i] -= i, g[i] *= g[i - 1];
    }
    for (int i = int(y.size()) - 2; i >= 0; --i)
        h[i] *= h[i + 1];
    integer<T, M> r = 0;
    for (int i = 0; i < int(y.size()); ++i) {
        integer<T, M> t = f[i] * f[y.size() - 1 - i];
        if (i)
            t *= g[i - 1];
        if (i + 1 != int(y.size()))
            t *= h[i + 1];
        if (int(y.size() - i - 1) % 2)
            t = -t;
        r += t * y[i];
    }
    return r;
}
const int candidate = 1073741789;
} 



int main() {
    fast, prec(12);
    vector<intm<>> val(26);
    vi perm(26);
    lv(i, val) val[i] = intm<>::random();
    lp(i, 0, 25) {
        int t;
        in(t), --t, perm[t] = i;
    }
    vector<intm<>> a, b, c;
    str t;
    in(t);
    intm c4;
    for (auto i : t)
        c.push_back(val[i - 'a']);
    for (auto i : c)
        c4 += i * i * i * i;
    reve(c);
    in(t);
    for (auto i : t)
        a.push_back(val[i - 'a']), b.push_back(val[perm[i - 'a']]);
    vector<intm<>> ab4;
    lv(i, a) {
        ab4.push_back(a[i] * a[i] * b[i] * b[i]);
        if (i)
            ab4[i] += ab4[i - 1];
    }
    vector<intm<>> result(a.size() + c.size() - 1);
    auto solve = [&](auto t1, auto t2) {
        vi x, y;
        lv(i, a) { x.push_back(t1(i).v); }
        lv(i, c) y.push_back(t2(i).v);
        auto res = number_theoretic_transform::multiply<int, 998244353>(x, y);
        lv(i, res) result[i] += res[i];
    };
    

    

    solve(
        [&](int i) { return -2 * a[i] * a[i] * b[i] - 2 * a[i] * b[i] * b[i]; },
        [&](int i) { return c[i]; });
    solve([&](int i) { return a[i] * a[i] + 4 * a[i] * b[i] + b[i] * b[i]; },
          [&](int i) { return c[i] * c[i]; });
    solve([&](int i) { return -2 * a[i] - 2 * b[i]; },
          [&](int i) { return c[i] * c[i] * c[i]; });
    

    

    lv(i, result) result[i] += c4;
    lp(i, 0, a.size() - c.size()) {
        result[i + c.size() - 1] += ab4[i + c.size() - 1];
        if (i)
            result[i + c.size() - 1] -= ab4[i - 1];
    }
    lp(i, c.size() - 1, a.size() - 1) cout << !bool(result[i].v);
    cout << endl;
    return 0;
}
