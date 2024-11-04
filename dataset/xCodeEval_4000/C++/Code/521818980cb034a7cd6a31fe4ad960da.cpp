#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/priority_queue.hpp>
#define lp(i, l, r) for (int i = l; i <= int(r); ++i)
#define rp(i, r, l) for (int i = int(r); i >= l; --i)
#define ls(i, s) for (int i = 0; s[i]; ++i)
#define rs(i, s) for (int i = strlen(s) - 1; i >= 0; --i)
#define lv(i, a) for (int i = 0; i < int(a.size()); ++i)
#define rv(i, a) for (int i = int(a.size()) - 1; i >= 0; --i)
#define fast ios::sync_with_stdio(0), cin.tie(0)
#define prec(a) cout << setprecision(a) << fixed
#define many for (int T = -1; T < 0 && cin >> T, T--;)
#define appl(f, a) for (auto i = begin(a); i != end(a); f, ++i)
#define rang(a) begin(a), end(a)
#define tstr(a) to_string(a)
#define gene template <class T>
#ifndef LOCAL
#define endl '\n'
#define assert
#endif
using namespace std;
using namespace __gnu_pbds;
gene T inf() { return numeric_limits<T>::max(); }
gene int tmin(T &a, T b) { return b < a ? a = b, 1 : 0; }
gene int tmax(T &a, T b) { return b > a ? a = b, 1 : 0; }
#if __cplusplus >= 201402L
gene auto min(const T &a) { return *min_element(rang(a)); }
gene auto max(const T &a) { return *max_element(rang(a)); }
gene auto sum(const T &a) { return accumulate(rang(a), 0); }
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
gene void shuf(T &a) { random_shuffle(rang(a)); }
gene void merg(T l, T m, T r) { inplace_merge(l, m, r); }
#if __cplusplus >= 201703L
template <typename... T> void in(T &... a) { ((cin >> a), ...); }
template <typename... T> void ou(T... a) { ((cout << a << ' '), ...) << '\n'; }
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
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vpii;
typedef string str;
namespace modular_arithmetic {
template <class T = long long> struct integer {
    integer() : v(0) {}
    integer(T t) : v(t) { wrap_around(); }
    void wrap_around() {
        if (v < 0)
            v = (v % p + p) % p;
        else if (v >= p)
            v %= p;
    }
    auto operator-() const {
        integer<T> a;
        a.v = (v ? p - v : 0);
        return a;
    }
    auto &operator+=(integer<T> a) { return *this = *this + a; }
    auto &operator-=(integer<T> a) { return *this = *this - a; }
    auto &operator*=(integer<T> a) { return *this = *this * a; }
    auto &operator/=(integer<T> a) { return *this = *this / a; }
    auto &operator<<=(T a) { return *this = *this << a; };
    auto &operator>>=(T a) { return *this = *this >> a; };
    friend auto operator/(integer<T> a, integer<T> b) { return a * inverse(b); }
    friend auto operator+(integer<T> a, integer<T> b) {
        integer<T> c;
        c.v = a.v + b.v;
        if (c.v >= a.p)
            c.v -= a.p;
        return c;
    }
    friend auto operator-(integer<T> a, integer<T> b) {
        integer<T> c;
        c.v = a.v - b.v;
        if (c.v < 0)
            c.v += a.p;
        return c;
    }
    friend auto operator*(integer<T> a, integer<T> b) {
        integer<T> c;
        if (typeid(T) == typeid(long long))
            c.v = (a.v * b.v -
                   (long long)(((long double)a.v * b.v + 0.5) / a.p) * a.p +
                   a.p) %
                  a.p;
        else if (typeid(T) == typeid(int))
            c.v = (long long)a.v * b.v % a.p;
        else
            c.v = a.v * b.v % a.p;
        return c;
    }
    friend auto operator^(integer<T> a, T b) { return pow(a, b); }
    friend bool operator==(integer<T> a, integer<T> b) { return a.v == b.v; }
    friend bool operator!=(integer<T> a, integer<T> b) { return a.v != b.v; }
    friend bool operator<(integer<T> a, integer<T> b) { return a.v < b.v; };
    friend bool operator<=(integer<T> a, integer<T> b) { return a.v <= b.v; };
    friend bool operator>(integer<T> a, integer<T> b) { return a.v > b.v; };
    friend bool operator>=(integer<T> a, integer<T> b) { return a.v >= b.v; };
    T v;
    static T p;
    static mt19937 g_32;
    static mt19937_64 g_64;
    static vector<integer<T>> inverse_cache, factorial_cache;
};
template <class T> T integer<T>::p = 1e9 + 7;
template <class T> mt19937 integer<T>::g_32(random_device{}());
template <class T> mt19937_64 integer<T>::g_64(random_device{}());
template <class T> vector<integer<T>> integer<T>::inverse_cache(2, T(1));
template <class T> vector<integer<T>> integer<T>::factorial_cache(1, T(1));
template <class T> auto &operator>>(istream &s, integer<T> &a) {
    s >> a.v;
    a.wrap_around();
    return s;
}
template <class T> auto &operator<<(ostream &s, integer<T> a) {
    return s << a.v;
}
template <class T> auto pow(integer<T> a, T b) {
    integer<T> r(1);
    for (; b; b >>= 1, a = a * a)
        if (b & 1)
            r = r * a;
    return r;
}
template <class T> integer<T> inverse(T a) { return inverse(integer<T>(a)); }
template <class T> integer<T> inverse(integer<T> a) {
    assert(a.v);
    if (a.v < integer<T>::inverse_cache.size())
        return integer<T>::inverse_cache[a.v];
    return pow(a, a.p - 2);
}
template <class T> auto inverse_cached(T a) {
    return inverse_cached(integer<T>(a));
}
template <class T> auto inverse_cached(integer<T> a) {
    assert(a.v);
    auto &t = integer<T>::inverse_cache;
    while (t.size() <= a.v) {
        t.push_back(integer<T>(-integer<T>::p / T(t.size())) *
                    t[integer<T>::p % t.size()]);
    }
    return t[a.v];
}
template <class T> auto operator<<(integer<T> a, T b) {
    return a * pow(integer<T>(2), b);
}
template <class T> auto operator>>(integer<T> a, T b) {
    return a / pow(integer<T>(2), b);
}


template <class T> auto random() {
    if (typeid(T) == typeid(long long))
        return integer<T>::g_64() % integer<T>::p;
    else if (typeid(T) == typeid(int))
        return integer<T>::g_32() % integer<T>::p;
    else
        assert(0);
}


template <class T> auto sqrt(integer<T> a) {
    vector<integer<T>> r;
    if (!a.v)
        r.push_back(decltype(r)(0));
    else if (pow(a, a.p - 1 >> 1).v == 1) {
        int s = a.p - 1, t = 0;
        integer<T> b = 1;
        for (; pow(b, a.p - 1 >> 1).v != a.p - 1; b = integer<T>::random())
            ;
        for (; s % 2 == 0; ++t, s /= 2)
            ;
        integer<T> x = pow(a, (s + 1) / 2), e = pow(a, s);
        for (int i = 1; i < t; ++i, e = x * x / a)
            if (pow(e, 1 << t - i - 1).v != 1)
                x = x * pow(b, (1 << i - 1) * s);
        r.push_back(x);
        r.push_back(-x);
    }
    return r;
}
template <class T> auto factorial(T a) {
    assert(a >= 0);
    auto &t = integer<T>::factorial_cache;
    while (a >= t.size())
        t.push_back(t.back() * t.size());
    return t[a];
}
template <class T> auto binary_coefficient(T n, T k) {
    assert(n >= 0 && k >= 0);
    if (n < k)
        return integer<T>();
    return factorial(n) / factorial(k) / factorial(n - k);
}
} 

int n;
vvi to, id, vis;
vi pid;
void build_pid(int u, int p) {
    lv(i, to[u]) {
        int v = to[u][i], w = id[u][i];
        if (v != p) {
            pid[v] = w;
            build_pid(v, u);
        }
    }
}
using inte = modular_arithmetic::integer<int>;
vector<vector<inte>> me;
inte dfs(int u, int p, int s) {
    auto &f = me[u][s];
    if (vis[u][s])
        return f;
    vis[u][s] = 1;
    

    

    

    

    

    

    int num_child = 0;
    lv(i, to[u]) {
        int v = to[u][i], w = id[u][i];
        if (v != p) {
            ++num_child;
        }
    }
    if (num_child == 0) {
        if (s == 0 || s == 1 || s == 3)
            f = 1;
        else {
            assert(s == 2);
            f = 0;
        }
    } else if (s == 0) {
        f = 0;
        

        inte pi = 1;
        lv(i, to[u]) {
            int v = to[u][i], w = id[u][i];
            if (v != p) {
                pi *= dfs(v, u, 1) + dfs(v, u, 2);
            }
        }
        f += pi;
        

        vector<inte> prefix, suffix;
        lv(i, to[u]) {
            int v = to[u][i], w = id[u][i];
            if (v != p) {
                prefix.push_back(dfs(v, u, 1) + dfs(v, u, 2));
                suffix.push_back(dfs(v, u, 0));
            }
        }
        for (int i = 1; i < prefix.size(); ++i)
            prefix[i] *= prefix[i - 1];
        for (int i = suffix.size() - 2; i >= 0; --i)
            suffix[i] *= suffix[i + 1];
        int cur = 0;
        lv(i, to[u]) {
            int v = to[u][i], w = id[u][i];
            if (v != p) {
                inte tmp = dfs(v, u, 3);
                if (cur)
                    tmp *= prefix[cur - 1];
                if (cur != suffix.size() - 1)
                    tmp *= suffix[cur + 1];
                f += tmp;
                ++cur;
            }
        }
    } else if (s == 1) {
        f = 1;
        lv(i, to[u]) {
            int v = to[u][i], w = id[u][i];
            if (v != p) {
                if (w < pid[u]) {
                    f *= dfs(v, u, 1) + dfs(v, u, 2);
                } else {
                    f *= dfs(v, u, 0);
                }
            }
        }
    } else if (s == 2) {
        f = 0;
        vector<inte> prefix, suffix;
        lv(i, to[u]) {
            int v = to[u][i], w = id[u][i];
            if (v != p) {
                prefix.push_back(dfs(v, u, 1) + dfs(v, u, 2));
                suffix.push_back(dfs(v, u, 0));
            }
        }
        for (int i = 1; i < prefix.size(); ++i)
            prefix[i] *= prefix[i - 1];
        for (int i = suffix.size() - 2; i >= 0; --i)
            suffix[i] *= suffix[i + 1];
        int cur = 0;
        lv(i, to[u]) {
            int v = to[u][i], w = id[u][i];
            if (v != p) {
                if (w < pid[u]) {
                    inte tmp = dfs(v, u, 3);
                    if (cur)
                        tmp *= prefix[cur - 1];
                    if (cur != suffix.size() - 1)
                        tmp *= suffix[cur + 1];
                    f += tmp;
                }
                ++cur;
            }
        }
    } else {
        assert(s == 3);
        f = 0;
        

        inte pi = 1;
        lv(i, to[u]) {
            int v = to[u][i], w = id[u][i];
            if (v != p) {
                pi *= dfs(v, u, 1) + dfs(v, u, 2);
            }
        }
        f += pi;
        

        vector<inte> prefix, suffix;
        lv(i, to[u]) {
            int v = to[u][i], w = id[u][i];
            if (v != p) {
                prefix.push_back(dfs(v, u, 1) + dfs(v, u, 2));
                suffix.push_back(dfs(v, u, 0));
            }
        }
        for (int i = 1; i < prefix.size(); ++i)
            prefix[i] *= prefix[i - 1];
        for (int i = suffix.size() - 2; i >= 0; --i)
            suffix[i] *= suffix[i + 1];
        int cur = 0;
        lv(i, to[u]) {
            int v = to[u][i], w = id[u][i];
            if (v != p) {
                if (w > pid[u]) {
                    inte tmp = dfs(v, u, 3);
                    if (cur)
                        tmp *= prefix[cur - 1];
                    if (cur != suffix.size() - 1)
                        tmp *= suffix[cur + 1];
                    f += tmp;
                }
                ++cur;
            }
        }
    }
    

    return f;
}
int main() {
    fast, prec(12);
    modular_arithmetic::integer<int>::p = 998244353;
    cin >> n;
    to.resize(n), id.resize(n), me.resize(n), pid = vi(n, -1), vis.resize(n);
    lp(i, 0, n - 1) me[i].resize(4), vis[i].resize(4);
    lp(i, 1, n - 1) {
        int u, v;
        in(u, v);
        --u, --v;
        to[u].push_back(v), to[v].push_back(u);
        id[u].push_back(i), id[v].push_back(i);
    }
    build_pid(0, -1);
    ou(dfs(0, -1, 0));
    return 0;
}
