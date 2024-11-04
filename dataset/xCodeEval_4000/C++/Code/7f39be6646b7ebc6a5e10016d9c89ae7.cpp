#ifdef LOCAL
#include <header.hpp>
#else
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/priority_queue.hpp>
#endif
#define lp(i, l, r) for (auto i = regu(l); i <= decltype(i)(r); ++i)
#define rp(i, r, l) for (auto i = regu(r); i >= decltype(i)(l); --i)
#define lv(i, a) for (int i = 0; i < int(a.size()); ++i)
#define rv(i, a) for (int i = int(a.size()) - 1; i >= 0; --i)
#define lm(i, m) for (auto i = m; i; i = (m) & (i - 1))
#define many for (int C = 1, T = -1; T < 0 && cin >> T, C <= T; ++C)
#define goog "Case #" + to_string(C) + ":"
#define rang(a) begin(a), end(a)
#define elif else if
#ifndef LOCAL
#define endl '\n'
#undef assert
#define assert
#endif
using namespace std;
using namespace __gnu_pbds;
const auto eps = 1e-8, pi = acos(-1);
template <class T> int comp(const T &a, const T &b) {
    return a < b - eps ? -1 : (a > b + eps);
}
#if __cplusplus > 201103L
template <class T> auto regu(const T &a) { return int(a); }
template <> auto regu(const int64_t &a) { return a; }
template <> auto regu(const uint64_t &a) { return int64_t(a); }
#else
template <class T> int64_t regu(const T &a) { return a; }
template <> int64_t regu(const uint32_t &a) { return int(a); }
#endif
template <class T> int barr(const T &a, const int &i) { return a >> i & 1; }
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
#if __cplusplus > 201103L
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
#endif
template <class T, class C = less<typename T::value_type>>
void sort(T &a, C c = C()) {
    sort(rang(a), c);
}
template <class T> void reve(T &a) { reverse(rang(a)); }
template <class T> void uniq(T &a) {
    sort(a), a.erase(unique(rang(a)), end(a));
}
template <class T> void shuf(T &a) { shuffle(rang(a), rng); }
template <class T> void merg(T l, T m, T r) { inplace_merge(l, m, r); }
#if __cplusplus > 201103L
template <class T> auto vect(const vector<T> &v, int n) {
    assert(v.size() <= 1);
    return v.size() ? vector<T>(n, v[0]) : vector<T>(n);
}
template <class T, class... D> auto vect(const vector<T> &v, int n, D... m) {
    return vector<decltype(vect(v, m...))>(n, vect(v, m...));
}
#endif
template <class T> T x(const complex<T> &a) { return a.real(); }
template <class T> T y(const complex<T> &a) { return a.imag(); }
template <class T> complex<T> rota(const complex<T> &p, const T &t) {
    return p * complex<T>(polar(1., -t));
}
template <class T>
complex<T> rota(const complex<T> &p, const complex<T> &a, const T &t) {
    return (p - a) * complex<T>(polar(1., -t)) + a;
}
template <class T>
complex<T> squa_dist(const complex<T> &a, const complex<T> &b) {
    return norm(a - b);
}
template <class T> T dist(const complex<T> &a, const complex<T> &b) {
    return abs(a - b);
}
template <class T> T dot(const complex<T> &a, const complex<T> &b) {
    return x(conj(a) * b);
}
template <class T> T cros(const complex<T> &a, const complex<T> &b) {
    return y(conj(a) * b);
}
template <class T>
T angl(const complex<T> &a, const complex<T> &b, const complex<T> &c) {
    return abs(remainder(arg(a - b) - arg(c - b), 2 * pi));
}
template <class T>
complex<T> inte(const complex<T> &a, const complex<T> &b, const complex<T> &c,
                const complex<T> &d) {
    T u = cros(c - a, b - a), v = cros(d - a, b - a);
    return (u * d - v * c) / (u - v);
}
template <class T> complex<T> proj(const complex<T> &p, const complex<T> &a) {
    return a * dot(p, a) / norm(a);
}
template <class T>
complex<T> proj(const complex<T> &p, const complex<T> &a, const complex<T> &b) {
    return a + (b - a) * dot(p - a, b - a) / norm(b - a);
}
template <class T>
complex<T> refl(const complex<T> &p, const complex<T> &a, const complex<T> &b) {
    return a + conj((p - a) / (b - a)) * (b - a);
}
template <class T> int comp(const complex<T> &a, const complex<T> &b) {
    int t = comp(x(a), x(b));
    if (t)
        return t;
    return comp(y(a), y(b));
}
namespace std {
template <>
bool operator==(const complex<double> &a, const complex<double> &b) {
    return !comp(x(a), x(b));
}
template <>
bool operator!=(const complex<double> &a, const complex<double> &b) {
    return comp(x(a), x(b));
}
template <>
bool operator==(const complex<long double> &a, const complex<long double> &b) {
    return !comp(x(a), x(b));
}
template <>
bool operator!=(const complex<long double> &a, const complex<long double> &b) {
    return comp(x(a), x(b));
}
template <class T> struct less<complex<T>> {
    bool operator()(const complex<T> &a, const complex<T> &b) const {
        return comp(a, b) < 0;
    }
};
} 

template <class T> istream &operator>>(istream &s, complex<T> &a) {
    T x, y;
    return s >> x >> y, a.real(x), a.imag(y), s;
}
template <class T> ostream &operator<<(ostream &s, const complex<T> &a) {
    return s << x(a) << " " << y(a);
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
template <class T> istream &operator>>(istream &s, valarray<T> &a) {
    for (int i = -1; i < 0 && (!a.size() && (cin >> i, a.resize(i), 0), i = 0),
             i < int(a.size());)
        s >> a[i++];
    return s;
}
template <class T> ostream &operator<<(ostream &s, const valarray<T> &a) {
    lv(i, a) cout << a[i] << (i + 1 == int(a.size()) ? "" : " ");
    return s;
}
template <class T> T in() {
    T a;
    cin >> a;
    return a;
}
template <class T> void in(T &a) { cin >> a; }
template <class A, class... B> void in(A &a, B &... b) { cin >> a, in(b...); }
void ou() { cout << endl; }
template <class T> void ou(const T &a) { cout << a << endl; }
template <class A, class... B> void ou(const A &a, const B &... b) {
    cout << a << ' ', ou(b...);
}
bool yep(const bool &a) { return ou(a ? "yes" : "no"), a; }
bool Yep(const bool &a) { return ou(a ? "Yes" : "No"), a; }
bool YEP(const bool &a) { return ou(a ? "YES" : "NO"), a; }
template <class T> struct hash_safe {};
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
    size_t operator()(uint64_t a) const { return hash_safe<int>()(a); }
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
#define unordered_set unordered_set_safe
#define unordered_multiset unordered_multiset_safe
#define unordered_map unordered_map_safe
#define unordered_multimap unordered_multimap_safe
template <class T, class C = less<T>>
using bbst =
    tree<T, null_type, C, rb_tree_tag, tree_order_statistics_node_update>;
template <class T, class C = greater<T>>
using heap = __gnu_pbds::priority_queue<T, C, pairing_heap_tag>;
using ll = int64_t;
using ld = long double;
using str = string;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pt = complex<double>;
using vi = vector<int>;
using vl = vector<ll>;
using vai = valarray<int>;
using val = valarray<ll>;
using vpii = vector<pii>;
using vpll = vector<pll>;
using vvi = vector<vi>;
#include <bits/stdc++.h>
using namespace std;
namespace geometry_2d {
template <class T, int E> struct real_number {
    real_number() : v(0) {}
    real_number(const T &v_) : v(v_) {}
    operator T() const { return v; }
    auto operator-() const { return real_number<T, E>(-v); }
    auto &operator+=(const real_number<T, E> &a) {
        v += a.v;
        return *this;
    }
    auto &operator-=(const real_number<T, E> &a) {
        v -= a.v;
        return *this;
    }
    auto &operator*=(const real_number<T, E> &a) {
        v *= a.v;
        return *this;
    }
    auto &operator/=(const real_number<T, E> &a) {
        v /= a.v;
        return *this;
    }
    friend auto operator+(const real_number<T, E> &a,
                          const real_number<T, E> &b) {
        return real_number<T, E>(a.v + b.v);
    }
    friend auto operator-(const real_number<T, E> &a,
                          const real_number<T, E> &b) {
        return real_number<T, E>(a.v - b.v);
    }
    friend auto operator*(const real_number<T, E> &a,
                          const real_number<T, E> &b) {
        return real_number<T, E>(a.v * b.v);
    }
    friend auto operator/(const real_number<T, E> &a,
                          const real_number<T, E> &b) {
        return real_number<T, E>(a.v / b.v);
    }
    friend auto operator==(const real_number<T, E> &a,
                           const real_number<T, E> &b) {
        return abs(a.v - b.v) < T(1) / E;
    }
    friend auto operator!=(const real_number<T, E> &a,
                           const real_number<T, E> &b) {
        return abs(a.v - b.v) > T(1) / E;
    }
    friend auto operator<(const real_number<T, E> &a,
                          const real_number<T, E> &b) {
        return a.v + T(1) / E < b.v;
    };
    friend auto operator<=(const real_number<T, E> &a,
                           const real_number<T, E> &b) {
        return a.v <= b.v + T(1) / E;
    };
    friend auto operator>(const real_number<T, E> &a,
                          const real_number<T, E> &b) {
        return a.v > b.v + T(1) / E;
    };
    friend auto operator>=(const real_number<T, E> &a,
                           const real_number<T, E> &b) {
        return a.v + T(1) / E >= b.v;
    };
    friend auto sqrt(const real_number<T, E> &a) {
        return real_number<T, E>(sqrt(a.v));
    }
    friend auto abs(const real_number<T, E> &a) {
        return real_number<T, E>(abs(a.v));
    }
    friend auto atan2(const real_number<T, E> &a, const real_number<T, E> &b) {
        return real_number<T, E>(atan2(a.v, b.v));
    }
    friend auto min(const real_number<T, E> &a, const real_number<T, E> &b) {
        return real_number<T, E>(min(a.v, b.v));
    }
    friend auto max(const real_number<T, E> &a, const real_number<T, E> &b) {
        return real_number<T, E>(max(a.v, b.v));
    }
    friend istream &operator>>(istream &s, real_number<T, E> &a) {
        return s >> a.v;
    }
    friend ostream &operator<<(ostream &s, const real_number<T, E> &a) {
        return s << a.v;
    }
    T v;
};
using integer = int64_t;
template <class T = real_number<double, int(1e8)>> struct point {
    point(T i = 0, T j = 0) : x(i), y(j) {}
    int dir() const { return x ? x < 0 : (y ? y < 0 : -1); }
    auto &operator+=(const point<T> &a) {
        x += a.x, y += a.y;
        return *this;
    }
    auto &operator-=(const point<T> &a) {
        x -= a.x, y -= a.y;
        return *this;
    }
    operator vector<T>() const {
        vector<T> v;
        v.push_back(x);
        v.push_back(y);
        return v;
    }
    T x, y;
};
template <class T> auto angle(const point<T> &a) { return atan2(a.x, a.y); }
template <> auto angle<int>(const point<int> &a) {
    return atan2(double(a.x), double(a.y));
}
template <> auto angle<int64_t>(const point<int64_t> &a) {
    return atan2((long double)(a.x), (long double)(a.y));
}
template <class T> T squared_euclidean_norm(const point<T> &a) {
    return a.x * a.x + a.y * a.y;
}
template <class T> auto euclidean_norm(const point<T> &a) {
    return sqrt(squared_euclidean_norm(a));
}
template <> auto euclidean_norm<int>(const point<int> &a) {
    return sqrt(double(squared_euclidean_norm(a)));
}
template <> auto euclidean_norm<int64_t>(const point<int64_t> &a) {
    return sqrt((long double)(squared_euclidean_norm(a)));
}
template <class T> T cross_product(const point<T> &a, const point<T> &b) {
    return a.x * b.y - b.x * a.y;
}
template <class T> T dot_product(const point<T> &a, const point<T> &b) {
    return a.x * b.x + b.y * a.y;
}
template <class T> auto operator+(const point<T> &a, const point<T> &b) {
    return point<T>(a.x + b.x, a.y + b.y);
}
template <class T> auto operator-(const point<T> &a, const point<T> &b) {
    return point<T>(a.x - b.x, a.y - b.y);
}
template <class T> auto operator*(const point<T> &a, const T &b) {
    return point<T>(a.x * b, a.y * b);
}
template <class T> auto operator/(const point<T> &a, const T &b) {
    return point<T>(a.x / b, a.y / b);
}
template <class T> T operator<(const point<T> &a, const point<T> &b) {
    int t = a.dir() - b.dir();
    return t ? (t < 0) : (cross_product(a, b) < T(0));
}
template <class T> auto &operator>>(istream &s, point<T> &a) {
    return s >> a.x >> a.y;
}
template <class T> auto &operator<<(ostream &s, const point<T> &a) {
    return s << a.x << ' ' << a.y;
}
template <class T = real_number<double, int(1e8)>> struct line {
    line(const point<T> &p_, const point<T> &q_)
        : p(p_), q(q_), a(angle(p - q)) {}
    point<T> p, q;
    T a;
};
template <class T> auto intersection(const line<T> &a, const point<T> &b) {
    if (abs(cross_product(a.q - a.p, b - a.p)) == T(0))
        return vector<point<T>>(1, b);
    else
        return vector<point<T>>();
}
template <class T> auto intersection(const line<T> &a, const line<T> &b) {
    T u = cross_product(b.p - a.q, b.q - b.p),
      v = cross_product(a.p - b.q, b.q - b.p);
    if (u + v == T(0))
        return vector<point<T>>();
    else
        return vector<point<T>>(1, (a.p * u + a.q * v) / (u + v));
}
template <class T = real_number<double, int(1e8)>> struct segment {
    segment(const point<T> &p_, const point<T> &q_)
        : p(p_), q(q_), a(angle(p - q)) {}
    operator line<T>() const { return line<T>(p, q); }
    point<T> p, q;
    T a;
};
template <class T> auto intersection(const segment<T> &a, const point<T> &b) {
    if (cross_product(a.q - a.p, b - a.p) == T(0) &&
        dot_product(b - a.p, b - a.q) <= T(0))
        return vector<point<T>>(1, b);
    else
        return vector<point<T>>();
}
template <class T> bool intersects(const segment<T> &a, const line<T> &b) {
    auto u = cross_product(a.p - b.p, b.p - b.q),
         v = cross_product(a.q - b.p, b.p - b.q);
    return (u <= T(0) && v >= T(0)) || (u >= T(0) && v <= T(0));
}
template <class T> bool intersects(const segment<T> &a, const segment<T> &b) {
    if (max(min(a.p.x, a.q.x), min(b.p.x, b.q.x)) >
        min(max(a.p.x, a.q.x), max(b.p.x, b.q.x)))
        return false;
    if (max(min(a.p.y, a.q.y), min(b.p.y, b.q.y)) >
        min(max(a.p.y, a.q.y), max(b.p.y, b.q.y)))
        return false;
    return intersects(a, line<T>(b)) && intersects(b, line<T>(a));
}
template <class T> auto intersection(const segment<T> &a, const segment<T> &b) {
    auto i = intersection(line<T>(a), line<T>(b));
    vector<point<T>> r, t;
    if (i.size())
        r = i;
    else {
        r.push_back(a.p);
        r.push_back(a.q);
        r.push_back(b.p);
        r.push_back(b.q);
    }
    for (auto p : r)
        if (intersection(a, p).size() && intersection(b, p).size())
            t.push_back(p);
    return t;
}
} 



struct node {
    int idx;
    int tp;
    ld x;
};
bool operator<(node a, node b) {
    if (a.x == b.x)
        return a.idx < b.idx;
    return a.x < b.x;
}
int main() {
    ios::sync_with_stdio(!cin.tie(0));
    cout << setprecision(16) << fixed;
    int n;
    in(n);
    vi xt(n), yt(n), dx(n), dy(n), s(n);
    vector<double> ddx(n), ddy(n);
    lp(i, 0, n - 1) {
        in(xt[i], yt[i], dx[i], dy[i], s[i]);
        double t = sqrt(dx[i] * dx[i] + dy[i] * dy[i]);
        ddx[i] = s[i] * dx[i] / t;
        ddy[i] = s[i] * dy[i] / t;
    }
    auto check = [&](double t) {
        vector<pair<complex<ld>, complex<ld>>> a;
        vector<node> b;
        lp(i, 0, n - 1) {
            if (ddx[i] > 0)
                a.push_back(
                    {{xt[i], yt[i]}, {xt[i] + ddx[i] * t, yt[i] + ddy[i] * t}});
            else {
                a.push_back(
                    {{xt[i] + ddx[i] * t, yt[i] + ddy[i] * t}, {xt[i], yt[i]}});
            }
            node tt;
            tt.idx = i;
            tt.tp = 0;
            tt.x = x(a.back().first);
            b.push_back(tt);
            tt.tp = 1;
            tt.x = x(a.back().second);
            b.push_back(tt);
        }
        sort(b);
        set<node> c;
        for (auto i : b) {
            

            if (i.tp == 0) {
                i.x = y(a[i.idx].first);
                auto tmp = c.insert(i).first;
                if (tmp != c.begin()) {
                    --tmp;
                    int i1 = i.idx;
                    int i2 = tmp->idx;
                    auto inte = geometry_2d::intersects(
                        geometry_2d::segment<
                            geometry_2d::real_number<ld, int(1e8)>>(
                            {x(a[i1].first), y(a[i1].first)},
                            {x(a[i1].second), y(a[i1].second)}),
                        geometry_2d::segment<
                            geometry_2d::real_number<ld, int(1e8)>>(
                            {x(a[i2].first), y(a[i2].first)},
                            {x(a[i2].second), y(a[i2].second)}));
                    if (inte) {
                        return 1;
                    }
                    ++tmp;
                }
                ++tmp;
                if (tmp != c.end()) {
                    int i1 = i.idx;
                    int i2 = tmp->idx;
                    auto inte = geometry_2d::intersects(
                        geometry_2d::segment<
                            geometry_2d::real_number<ld, int(1e8)>>(
                            {x(a[i1].first), y(a[i1].first)},
                            {x(a[i1].second), y(a[i1].second)}),
                        geometry_2d::segment<
                            geometry_2d::real_number<ld, int(1e8)>>(
                            {x(a[i2].first), y(a[i2].first)},
                            {x(a[i2].second), y(a[i2].second)}));
                    if (inte) {
                        return 1;
                    }
                }
            } else {
                i.x = y(a[i.idx].first);
                auto tmp = c.find(i);
                if (tmp != c.begin()) {
                    --tmp;
                    int i1 = i.idx;
                    int i2 = tmp->idx;
                    auto inte = geometry_2d::intersects(
                        geometry_2d::segment<
                            geometry_2d::real_number<ld, int(1e8)>>(
                            {x(a[i1].first), y(a[i1].first)},
                            {x(a[i1].second), y(a[i1].second)}),
                        geometry_2d::segment<
                            geometry_2d::real_number<ld, int(1e8)>>(
                            {x(a[i2].first), y(a[i2].first)},
                            {x(a[i2].second), y(a[i2].second)}));
                    if (inte) {
                        return 1;
                    }
                    ++tmp;
                }
                ++tmp;
                if (tmp != c.end()) {
                    int i1 = i.idx;
                    int i2 = tmp->idx;
                    auto inte = geometry_2d::intersects(
                        geometry_2d::segment<
                            geometry_2d::real_number<ld, int(1e8)>>(
                            {x(a[i1].first), y(a[i1].first)},
                            {x(a[i1].second), y(a[i1].second)}),
                        geometry_2d::segment<
                            geometry_2d::real_number<ld, int(1e8)>>(
                            {x(a[i2].first), y(a[i2].first)},
                            {x(a[i2].second), y(a[i2].second)}));
                    if (inte) {
                        return 1;
                    }
                }
                --tmp;
                c.erase(tmp);
            }
        }
        return 0;
    };
    double l = 0, r = 1;
    while (!check(r) && r < 1e10)
        r *= 2;
    if (r >= 1e10) {
        ou("No show :(");
        return 0;
    }
    while ((r - l) / max(1., r) > eps) {
        double m = (l + r) / 2;
        if (check(m))
            r = m;
        else
            l = m;
    }
    ou((l + r) / 2);
    return 0;
}
