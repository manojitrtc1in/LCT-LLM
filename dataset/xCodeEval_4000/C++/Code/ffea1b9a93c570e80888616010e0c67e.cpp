#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/priority_queue.hpp>
#define lp(i, l, r) for (int i = int(l); i <= int(r); ++i)
#define rp(i, r, l) for (int i = int(r); i >= int(l); --i)
#define ls(i, s) for (int i = 0; s[i]; ++i)
#define rs(i, s) for (int i = strlen(s) - 1; i >= 0; --i)
#define lv(i, a) for (int i = 0; i < int(a.size()); ++i)
#define rv(i, a) for (int i = int(a.size()) - 1; i >= 0; --i)
#define fast ios::sync_with_stdio(0), cin.tie(0)
#define prec(a) cout << setprecision(a) << fixed
#define freo freopen
#define many for (int T = -1; T < 0 && cin >> T, T--;)
#define appl(f, a) for (auto i = begin(a); i != end(a); f, ++i)
#define rang(a) begin(a), end(a)
#define gene template <class T>
#define elif else if
#define intm modular_arithmetic::integer
#ifndef LOCAL
#define endl '\n'
#define assert
#endif
using namespace std;
using namespace __gnu_pbds;
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
template <class T = int> T inf() { return numeric_limits<T>::max(); }
gene T floor(const T &a, const T &b) {
    assert(b != 0);
    return (a > 0 && b > 0 || a < 0 && b < 0) ? abs(a) / abs(b)
                                              : -(abs(a) + abs(b) - 1) / abs(b);
}
gene T ceil(const T &a, const T &b) {
    assert(b != 0);
    return (a > 0 && b > 0 || a < 0 && b < 0) ? (abs(a) + abs(b) - 1) / abs(b)
                                              : -abs(a) / abs(b);
}
gene bool tmin(T &a, T b) { return b < a ? a = b, true : false; }
gene bool tmax(T &a, T b) { return b > a ? a = b, true : false; }
#if __cplusplus >= 201402L
gene auto min(const T &a) { return *min_element(rang(a)); }
gene auto max(const T &a) { return *max_element(rang(a)); }
gene auto sum(const T &a) {
    return accumulate(rang(a), (typename T::value_type)0);
}
template <> auto sum(const vector<int> &a) { return accumulate(rang(a), 0ll); }
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
#endif
template <class T, class C = less<typename T::value_type>>
void sort(T &a, C c = C()) {
    sort(rang(a), c);
}
gene void reve(T &a) { reverse(rang(a)); }
gene void uniq(T &a) { sort(a), a.erase(unique(rang(a)), end(a)); }
gene void shuf(T &a) { shuffle(rang(a), rng); }
gene void merg(T l, T m, T r) { inplace_merge(l, m, r); }
#if __cplusplus >= 201703L
template <typename... T> void in(T &... a) { ((cin >> a), ...); }
template <typename A, typename... B> void ou(const A &a, const B &... b) {
    cout << a, ((cout << ' ' << b), ...), cout << endl;
}
#endif
template <class F, class S> istream &operator>>(istream &s, pair<F, S> &a) {
    return s >> a.first >> a.second;
}
template <class F, class S>
ostream &operator<<(ostream &s, const pair<F, S> &a) {
    return s << '(' << a.first << ", " << a.second << ')';
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
gene using bbst =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
gene using heap = __gnu_pbds::priority_queue<T, greater<T>, pairing_heap_tag>;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef string str;
namespace modular_arithmetic {
#ifdef LOCAL
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
#else
template <class T> T multiply(const T &x, const T &y, const T &z) {
    return T((long long)x * y % z);
}
template <>
long long multiply<long long>(const long long &x, const long long &y,
                              const long long &z) {
    return (x * y - (long long)(((long double)x * y + 0.5) / z) * z + z) % z;
}
#endif
template <class T = int, T M = T(1e9 + 7)> struct integer {
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
    T v;
    static mt19937_64 generator;
    static vector<integer<T, M>> inverse_cache, factorial_cache;
};
template <class T, T M>
mt19937_64 integer<T, M>::generator(
    chrono::steady_clock::now().time_since_epoch().count());
template <class T, T M>
vector<integer<T, M>> integer<T, M>::inverse_cache(2, T(1));
template <class T, T M>
vector<integer<T, M>> integer<T, M>::factorial_cache(1, T(1));
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


template <class T, T M> auto random() {
    integer<T, M>(
        uniform_int_distribution<T>(0, M - 1)(integer<T, M>::generator));
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
template <class T, T M> auto factorial(T a) {
    assert(a >= 0);
    auto &t = integer<T, M>::factorial_cache;
    while (a >= t.size())
        t.push_back(t.back() * t.size());
    return t[a];
}
template <class T, T M> auto binary_coefficient(T n, T k) {
    assert(n >= 0 && k >= 0);
    if (n < k)
        return integer<T, M>();
    return factorial(n) / factorial(k) / factorial(n - k);
}
template <class T, T M>
integer<T, M> lagrange_interpolation(const vector<T> &y, T x) {
    return lagrange_interpolation(y, integer<T, M>(x));
}
template <class T, T M>
integer<T, M> lagrange_interpolation(const vector<T> &y, integer<T, M> x) {
    vector<integer<T, M>> t;
    for (auto v : y)
        t.push_back(integer<T, M>(v));
    return lagrange_interpolation(t, x);
}
template <class T, T M>
integer<T, M> lagrange_interpolation(const vector<integer<T, M>> &y, T x) {
    return lagrange_interpolation(y, integer<T, M>(x));
}
template <class T, T M>
integer<T, M> lagrange_interpolation(const vector<integer<T, M>> &y,
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
    int n;
    in(n);
    vi l(n), r(n);
    in(l, r);
    intm<> e = n;
    e *= n;
    vector<intm<>> p(n - 1), s(n - 1);
    lp(i, 0, n - 2) {
        s[i] = p[i] =
            intm<>(max(min(r[i], r[i + 1]) - max(l[i], l[i + 1]) + 1, 0)) /
            (intm<>(r[i] - l[i] + 1) * intm<>(r[i + 1] - l[i + 1] + 1));
        if (i)
            s[i] += s[i - 1];
    }
    lp(i, 0, n - 2) e -= 2 * n * p[i];
    lp(i, 0, n - 2) {
        e += p[i];
        if (i) {
            int nl = max(vi{l[i - 1], l[i], l[i + 1]});
            int nr = min(vi{r[i - 1], r[i], r[i + 1]});
            int len = max(nr - nl + 1, 0);
            e += 2 * len /
                 (intm<>(r[i - 1] - l[i - 1] + 1) * intm<>(r[i] - l[i] + 1) *
                  intm<>(r[i + 1] - l[i + 1] + 1));
        }
        if (i - 2 >= 0) {
            e += 2 * s[i - 2] * p[i];
        }
    }
    ou(e);
    return 0;
}
