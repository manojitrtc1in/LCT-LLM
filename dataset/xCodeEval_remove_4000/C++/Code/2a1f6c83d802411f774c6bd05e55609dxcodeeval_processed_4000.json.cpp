




















using namespace std;
using namespace __gnu_pbds;
const auto eps = 1e-8, pi = acos(-1);
template <class T> int comp(const T &a, const T &b) {
    return a < b - eps ? -1 : (a > b + eps);
}

template <class T> auto regu(const T &a) { return int(a); }
template <> auto regu(const int64_t &a) { return a; }
template <> auto regu(const uint64_t &a) { return int64_t(a); }

template <class T> int64_t regu(const T &a) { return int(a); }
template <> int64_t regu(const int64_t &a) { return a; }
template <> int64_t regu(const uint64_t &a) { return a; }

template <class T> int barr(const T &a, const int &i) {
    return int(a >> i & 1);
}
template <class T> int bcnt(const T &a) { return __builtin_popcount(a); }
template <> int bcnt(const int64_t &a) { return __builtin_popcountll(a); }
template <class T> int blen(const T &a) { return a ? 1 + blen(a / 2) : 0; }
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
template <class T> T rint(T l, T r) {
    return uniform_int_distribution<T>(l, r)(rng);
}
template <class A, class B> B conv(const A &a, B b = B()) {
    stringstream s;
    s << a, s >> b;
    return b;
}
template <class T = int> T inf() { return numeric_limits<T>::max() / 2; }
template <class T> T sign(const T &a) { return a == 0 ? 0 : (a < 0 ? -1 : 1); }
template <class T> T floor(const T &a, const T &b) {
    assert(b != 0);
    return sign(a) * sign(b) > 0 ? abs(a) / abs(b)
                                 : -(abs(a) + abs(b) - 1) / abs(b);
}
template <class T> T ceil(const T &a, const T &b) {
    assert(b != 0);
    return sign(a) * sign(b) > 0 ? (abs(a) + abs(b) - 1) / abs(b)
                                 : -abs(a) / abs(b);
}
template <class T> bool tmin(T &a, T b) { return b < a ? a = b, true : false; }
template <class T> bool tmax(T &a, T b) { return b > a ? a = b, true : false; }

template <class T> auto min(const T &a) { return *min_element(rang(a)); }
template <class T> auto max(const T &a) { return *max_element(rang(a)); }
template <class T> auto sum(const T &a) {
    return accumulate(rang(a), (typename T::value_type)0);
}
template <> auto sum(const vector<int> &a) { return accumulate(rang(a), 0ll); }
template <> auto sum(const vector<string> &a) {
    return accumulate(rang(a), string());
}
template <class C, class V> auto find(C &c, const V &v) {
    return find(rang(c), v);
}
template <class C, class V> auto find(const C &c, const V &v) {
    return find(rang(c), v);
}

template <class T, class C = less<typename T::value_type>>
void sort(T &a, C c = C()) {
    sort(rang(a), c);
}
template <class T, class C> void sork(T &a, C c) {
    sort(a, [&](const typename T::value_type &x,
                const typename T::value_type &y) { return c(x) < c(y); });
}
template <class T> void reve(T &a) { reverse(rang(a)); }
template <class T> void uniq(T &a) {
    sort(a), a.erase(unique(rang(a)), end(a));
}
template <class T> void shuf(T &a) { shuffle(rang(a), rng); }
template <class T> void merg(T l, T m, T r) { inplace_merge(l, m, r); }

namespace lru_cache {
template <class F> struct dense_ {
    dense_(F function) : f(function) {}
    template <class V> auto build(int i) const {
        assert(i == l.size());
        return numeric_limits<V>::min();
    }
    template <class V, class T, class... K>
    auto build(int i, const T &t, const K &...k) const {
        auto u = build<V, K...>(i + 1, k...);
        return vector<decltype(u)>(l[i], u);
    }
    template <class M, class V> V &find(M &m) const { return m; }
    template <class M, class V, class T, class... K>
    V &find(M &m, const T &t, const K &...k) const {
        if (t < m.size())
            return find<decltype(m[t]), V, K...>(m[t], k...);
        return find<decltype(m[t]), V, K...>(m[e = false], k...);
    }
    template <class... K> auto operator()(const K &...k) const {
        typedef decltype(f(*this, k...)) V;
        typedef decltype(build<V, K...>(0, k...)) M;
        if (c) {
            if (p)
                delete (M *)p, p = 0;
            c = false;
        }
        if (!p)
            p = new M(move(build<V, K...>(0, k...)));
        e = true;
        auto &t = find<M, V, K...>(*((M *)p), k...);
        return e ? (t == numeric_limits<V>::min() ? t = f(*this, k...) : t)
                 : f(*this, k...);
    }
    F f;
    static vector<int> l;
    static void *p;
    static bool c, e;
};
template <class F> vector<int> dense_<F>::l;
template <class F> void *dense_<F>::p = 0;
template <class F> bool dense_<F>::c = false;
template <class F> bool dense_<F>::e = false;
template <class F> struct id1 {
    id1(F function) : f(function) {}
    template <class V> auto build() const { return V(); }
    template <class V, class T, class... K>
    auto build(const T &t, const K &...k) const {
        return unordered_map<T, decltype(build<V, K...>(k...))>();
    }
    template <class M, class V> V &find(M &m) const { return m; }
    template <class M, class V, class T, class... K>
    V &find(M &m, const T &t, const K &...k) const {
        auto i = m.find(t);
        if (i != m.end())
            return find<decltype(i->second), V, K...>(i->second, k...);
        e = false;
        return find<decltype(i->second), V, K...>(m[t], k...);
    }
    template <class... K> auto operator()(const K &...k) const {
        typedef decltype(f(*this, k...)) V;
        typedef decltype(build<V, K...>(k...)) M;
        if (c) {
            if (p)
                delete (M *)p, p = 0;
            c = false;
        }
        if (!p)
            p = new M(move(build<V, K...>(k...)));
        e = true;
        auto &t = find<M, V, K...>(*((M *)p), k...);
        return e ? t : t = f(*this, k...);
    }
    F f;
    static void *p;
    static bool c, e;
};
template <class F> void *id1<F>::p = 0;
template <class F> bool id1<F>::e = false;
template <class F> bool id1<F>::c = false;
struct dense {
    auto convert() {}
    template <class T, class... L>
    auto convert(const T &t, const L &...limits) {
        l.push_back(t);
        convert(limits...);
    }
    template <class... L> dense(const L &...limits) { convert(limits...); }
    template <class F> auto operator()(const F &f) const {
        dense_<F>::l = l, dense_<F>::c = true;
        return dense_<F>(f);
    }
    vector<int> l;
};
struct sparse {
    template <class F> auto operator()(const F &f) const {
        id1<F>::c = true;
        return id1<F>(f);
    }
};
} 

template <class T> auto vect(const T &v, int n) { return vector<T>(n, v); }
template <class T, class... D> auto vect(const T &v, int n, D... m) {
    return vector<decltype(vect(v, m...))>(n, vect(v, m...));
}

template <class F, class S> istream &operator>>(istream &s, pair<F, S> &a) {
    return s >> a.first >> a.second;
}
template <class F, class S>
ostream &operator<<(ostream &s, const pair<F, S> &a) {
    return s << a.first << " " << a.second;
}
template <class T> istream &operator>>(istream &s, vector<T> &a) {
    for (int i = -1; i < 0 && (!a.size() && (cin >> i, a.resize(i), 0), i = 0),
             i < int(a.size());)
        s >> a[i++];
    return s;
}
template <class T> ostream &operator<<(ostream &s, const vector<T> &a) {
    lv(i, a) cout << a[i] << (i + 1 == int(a.size()) ? "" : " ");
    return s;
}
template <class T> T in() {
    T a;
    cin >> a;
    return a;
}
template <class T> istream &in(T &a) { return cin >> a; }
template <class A, class... B> istream &in(A &a, B &...b) {
    return cin >> a, in(b...);
}
void ou() { cout << endl; }
template <class T> void ou(const T &a) { cout << a << endl; }
template <class A, class... B> void ou(const A &a, const B &...b) {
    cout << a << ' ', ou(b...);
}
bool yep(const bool &a) { return ou(a ? "yes" : "no"), a; }
bool Yep(const bool &a) { return ou(a ? "Yes" : "No"), a; }
bool YEP(const bool &a) { return ou(a ? "YES" : "NO"), a; }
template <class T> struct hash_safe {};
template <> struct hash_safe<int> {
    size_t operator()(unsigned long long a) const {
        static unsigned long long d =
            chrono::steady_clock::now().time_since_epoch().count();
        a += d + 0x9e3779b97f4a7c15, a = (a ^ (a >> 30)) * 0xbf58476d1ce4e5b9;
        a = (a ^ (a >> 27)) * 0x94d049bb133111eb;
        return a ^ (a >> 31);
    }
};
template <> struct hash_safe<long long> {
    size_t operator()(unsigned long long a) const {
        return hash_safe<int>()(a);
    }
};
template <class A, class B> struct hash_safe<pair<A, B>> {
    size_t operator()(pair<A, B> a) const {
        auto h = hash_safe<A>()(a.first), g = hash_safe<B>()(a.second);
        return (h >> 16 << 16) + (g >> 16);
    }
};
template <class T> using unordered_set_safe = unordered_set<T, hash_safe<T>>;
template <class T>
using unordered_multiset_safe = unordered_multiset<T, hash_safe<T>>;
template <class K, class V>
using unordered_map_safe = unordered_map<K, V, hash_safe<K>>;
template <class K, class V>
using unordered_multimap_safe = unordered_multimap<K, V, hash_safe<K>>;




template <class T, class C = less<T>>
using bbst =
    tree<T, null_type, C, rb_tree_tag, tree_order_statistics_node_update>;
template <class T, class C = greater<T>>
using heap = __gnu_pbds::priority_queue<T, C, pairing_heap_tag>;
using ll = long long;
using ld = long double;
using str = string;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vl = vector<ll>;
using vpii = vector<pii>;
using vpll = vector<pll>;
using vvi = vector<vi>;
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
    integer(int64_t t) {
        if (t < 0)
            v = (t % M + M) % M;
        else if (t >= M)
            v = t % M;
    }
    void wrap_around() {
        if (v < 0)
            v = (v % M + M) % M;
        else if (v >= M)
            v %= M;
    }
    integer<T, M> operator-() const {
        integer<T, M> a;
        a.v = (v ? M - v : 0);
        return a;
    }
    integer<T, M> &operator+=(integer<T, M> a) { return *this = *this + a; }
    integer<T, M> &operator-=(integer<T, M> a) { return *this = *this - a; }
    integer<T, M> &operator*=(integer<T, M> a) { return *this = *this * a; }
    integer<T, M> &operator/=(integer<T, M> a) { return *this = *this / a; }
    integer<T, M> &operator<<=(T a) { return *this = *this << a; };
    integer<T, M> &operator>>=(T a) { return *this = *this >> a; };
    friend integer<T, M> operator/(integer<T, M> a, integer<T, M> b) {
        return a * inverse(b);
    }
    friend integer<T, M> operator+(integer<T, M> a, integer<T, M> b) {
        integer<T, M> c;
        c.v = a.v + b.v;
        if (c.v >= M)
            c.v -= M;
        return c;
    }
    friend integer<T, M> operator-(integer<T, M> a, integer<T, M> b) {
        integer<T, M> c;
        c.v = a.v - b.v;
        if (c.v < 0)
            c.v += M;
        return c;
    }
    friend integer<T, M> operator*(integer<T, M> a, integer<T, M> b) {
        integer<T, M> c;
        c.v = multiply(a.v, b.v, M);
        return c;
    }
    friend integer<T, M> operator^(integer<T, M> a, T b) { return pow(a, b); }
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
    friend istream &operator>>(istream &s, integer<T, M> &a) {
        s >> a.v;
        a.wrap_around();
        return s;
    }
    friend ostream &operator<<(ostream &s, integer<T, M> a) { return s << a.v; }
    friend integer<T, M> operator<<(integer<T, M> a, T b) {
        return a * pow(integer<T, M>(2), b);
    }
    friend integer<T, M> operator>>(integer<T, M> a, T b) {
        return a / pow(integer<T, M>(2), b);
    }
    static integer<T, M> pow(integer<T, M> a, T b) {
        integer<T, M> r(1);
        if (b < 0)
            a = 1 / a, b = -b;
        for (; b; b >>= 1, a = a * a)
            if (b & 1)
                r = r * a;
        return r;
    }
    

    static integer<T, M> sqrt(integer<T, M> a) {
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
    static T extended_euclidean_algorithm(T a, T b, T &x, T &y) {
        if (!b) {
            x = 1, y = 0;
            return a;
        } else {
            T d = extended_euclidean_algorithm(b, a % b, y, x);
            y -= a / b * x;
            return d;
        }
    }
    static integer<T, M> inverse(integer<T, M> a) {
        assert(a.v);
        if (a.v < T(integer<T, M>::inverse_cache.size()))
            return integer<T, M>::inverse_cache[a.v];
        T t;
        extended_euclidean_algorithm(a.v, M, a.v, t);
        if (a.v < 0)
            a.v += M;
        return a;
    }
    static integer<T, M> inverse_cached(const integer<T, M> &a) {
        assert(a.v);
        auto &t = inverse_cache;
        while (int(t.size()) <= a.v) {
            t.push_back(integer<T, M>(-M / T(t.size())) * t[M % t.size()]);
        }
        return t[a.v];
    }
    static integer<T, M> factorial(const T &a) {
        assert(a >= 0);
        auto &t = id2;
        while (a >= int(t.size()))
            t.push_back(t.back() * T(t.size()));
        return t[a];
    }
    static integer<T, M> factorial_inverse(const T &a) {
        assert(a >= 0);
        auto &t = id0;
        while (a >= int(t.size()))
            t.push_back(t.back() * inverse_cached(T(t.size())));
        return t[a];
    }
    static integer<T, M> binary_coefficient(T n, T k) {
        assert(n >= 0 && k >= 0);
        if (n < k)
            return integer<T, M>();
        return factorial(n) * factorial_inverse(k) * factorial_inverse(n - k);
    }
    static integer<T, M> lagrange_interpolation(const vector<integer<T, M>> &y,
                                                integer<T, M> x) {
        vector<integer<T, M>> f(1, 1), g(y.size(), x), h(y.size(), x);
        for (int i = 1; i < int(y.size()); ++i) {
            f.push_back(f.back() * inverse_cached(i));
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
    static integer<T, M> random() {
        return integer<T, M>(uniform_int_distribution<T>(0, M - 1)(generator));
    }
    T v;
    static mt19937_64 generator;
    static vector<integer<T, M>> inverse_cache, id2,
        id0;
};
template <class T, T M>
mt19937_64 integer<T, M>::generator(
    chrono::steady_clock::now().time_since_epoch().count());
template <class T, T M>
vector<integer<T, M>> integer<T, M>::inverse_cache(2, T(1));
template <class T, T M>
vector<integer<T, M>> integer<T, M>::id2(1, T(1));
template <class T, T M>
vector<integer<T, M>> integer<T, M>::id0(1, T(1));
const int candidate = 1073741789;
} 



int main() {
    ios::sync_with_stdio(0);
    cout << setprecision(16) << fixed;
    cin.tie(0);
    many {
        int n, k;
        in(n, k);
        using inte = modular_arithmetic::integer<int, int(1e9 + 7)>;
        inte ans = 1;
        for (int p = 1; n - (k - 1) * (p - 1) >= p; ++p)
            ans += inte::binary_coefficient(n - (k - 1) * (p - 1), p) /
                   inte::binary_coefficient(n, p);
        ou(ans);
    }
    return 0;
}
