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
#define freo freopen
#define many for (int T = -1; T < 0 && cin >> T, T--;)
#define appl(f, a) for (auto i = begin(a); i != end(a); f, ++i)
#define rang(a) begin(a), end(a)
#define tstr(a) to_string(a)
#define gene template <class T>
#define elif else if
#ifndef LOCAL
#define endl '\n'
#define assert
#endif
using namespace std;
using namespace __gnu_pbds;
template <class T = int> T inf() { return numeric_limits<T>::max(); }
gene bool tmin(T &a, T b) { return b < a ? a = b, true : false; }
gene bool tmax(T &a, T b) { return b > a ? a = b, true : false; }
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
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vpii;
typedef string str;
namespace segment_tree {
template <class T> struct segment_tree {
    struct node {
        node *c[2];
        T s;
        int l, r;
    } * root;
    node *build(const vector<T> &a, int l, int r) {
        node *u = new node;
        if (l == r)
            u->c[0] = u->c[1] = 0, u->s = a[l];
        else {
            int m = (l + r) / 2;
            u->c[0] = build(a, l, m), u->c[1] = build(a, m + 1, r);
            u->s.merge(u->c[0]->s, u->c[1]->s);
        }
        u->l = l, u->r = r;
        return u;
    }
    segment_tree(const vector<T> &a) : root(build(a, 0, int(a.size() - 1))) {}
    void destroy(node *u) {
        if (u) {
            destroy(u->c[0]), destroy(u->c[1]);
            delete u;
        }
    }
    ~segment_tree() { destroy(root); }
    void push(node *u) {
        if (u->c[0])
            u->c[0]->s.tag(u->s.tag()), u->c[1]->s.tag(u->s.tag());
        u->s.push();
    }
    void merge(node *u) { u->s.merge(u->c[0]->s, u->c[1]->s); }
    void modify_single(int p, const T &s, node *u = 0) {
        if (!u)
            u = root;
        push(u);
        if (u->l == u->r) {
            assert(p == u->l);
            u->s = s;
        } else {
            modify_single(p, s, u->c[p > u->c[0]->r]);
            push(u->c[p <= u->c[0]->r]), merge(u);
        }
    }
    template <class A>
    void modify_segment(int l, int r, const A &t, node *u = 0) {
        if (!u)
            u = root;
        assert((u != root || (u->l <= l && u->r >= r)) && l <= r), push(u);
        if (l <= u->l && r >= u->r)
            u->s.tag(t), push(u);
        else {
            if (l <= u->c[0]->r)
                modify_segment(l, r, t, u->c[0]);
            else
                push(u->c[0]);
            if (r >= u->c[1]->l)
                modify_segment(l, r, t, u->c[1]);
            else
                push(u->c[1]);
            merge(u);
        }
    }
    const T &query_single(int p, node *u = 0) {
        if (!u)
            u = root;
        push(u);
        if (u->l == u->r) {
            assert(p == u->l);
            return u->s;
        } else {
            return query_single(p, u->c[p > u->c[0]->r]);
        }
    }
    T query_segment(int l, int r, node *u = 0) {
        if (!u)
            u = root;
        assert((u != root || (u->l <= l && u->r >= r)) && l <= r), push(u);
        if (l <= u->l && r >= u->r)
            return u->s;
        else {
            if (r <= u->c[0]->r)
                return query_segment(l, r, u->c[0]);
            if (l >= u->c[1]->l)
                return query_segment(l, r, u->c[1]);
            T t;
            t.merge(query_segment(l, r, u->c[0]), query_segment(l, r, u->c[1]));
            return t;
        }
    }
};
struct statistic {
    statistic() {}
    void push() {}
    void merge(const statistic &a, const statistic &b) {}
    void tag(int a) {}
    int tag() { return 0; }
};
template <class T> struct add_sum {
    add_sum(T a = 0) : s(a), t(0), l(1) {}
    void push() {
        if (t)
            s += t * l, t = 0;
    }
    void merge(const add_sum &a, const add_sum &b) {
        s = a.s + b.s, l = a.l + b.l;
    }
    void tag(T a) { t += a; }
    T tag() { return t; }
    T s, t;
    int l;
};
} 

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
            c.v = int((long long)a.v * b.v % a.p);
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
    if (a.v < T(integer<T>::inverse_cache.size()))
        return integer<T>::inverse_cache[a.v];
    return pow(a, a.p - 2);
}
template <class T> auto inverse_cached(T a) {
    return inverse_cached(integer<T>(a));
}
template <class T> auto inverse_cached(integer<T> a) {
    assert(a.v);
    auto &t = integer<T>::inverse_cache;
    while (int(t.size()) <= a.v) {
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
template <class T> integer<T> lagrange_interpolation(const vector<T> &y, T x) {
    return lagrange_interpolation(y, integer<T>(x));
}
template <class T>
integer<T> lagrange_interpolation(const vector<T> &y, integer<T> x) {
    vector<integer<T>> t;
    for (auto v : y)
        t.push_back(integer<T>(v));
    return lagrange_interpolation(t, x);
}
template <class T>
integer<T> lagrange_interpolation(const vector<integer<T>> &y, T x) {
    return lagrange_interpolation(y, integer<T>(x));
}
template <class T>
integer<T> lagrange_interpolation(const vector<integer<T>> &y, integer<T> x) {
    vector<integer<T>> f(1, 1), g(y.size(), x), h(y.size(), x);
    for (int i = 1; i < int(y.size()); ++i) {
        f.push_back(f.back() * inverse_cached<T>(i));
        g[i] = h[i] -= i, g[i] *= g[i - 1];
    }
    for (int i = int(y.size()) - 2; i >= 0; --i)
        h[i] *= h[i + 1];
    integer<T> r = 0;
    for (int i = 0; i < int(y.size()); ++i) {
        integer<T> t = f[i] * f[y.size() - 1 - i];
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
} 

using inte = modular_arithmetic::integer<int>;
vvi policy; 

struct statistic {
    statistic(inte pr = 0, int pos = 0) {
        p[0][0] = 1 - pr, p[1][1] = pr;
        l = r = pos;
    }
    void push() {}
    void merge(const statistic &a, const statistic &b) {
        l = a.l;
        r = b.r;
        int m = a.r;
        lp(i, 0, 1) lp(j, 0, 1) {
            p[i][j] = 0;
            lp(k, 0, 1) lp(l, 0, 1) {
                if (k == 0 && l == 1 && policy[m][3])
                    p[i][j] += a.p[i][k] * b.p[l][j];
                elif (k == 0 && l == 0 && policy[m][0]) p[i][j] +=
                    a.p[i][k] * b.p[l][j];
                elif (k == 1 && l == 1 && policy[m][1]) {
                    p[i][j] += a.p[i][k] * b.p[l][j];
                }
                elif (k == 1 && l == 0 && policy[m][2]) p[i][j] +=
                    a.p[i][k] * b.p[l][j];
            }
        }
    }
    void tag(int a) {}
    int tag() { return 0; }
    inte ans() {
        inte tmp = 0;
        lp(i, 0, 1) lp(j, 0, 1) tmp += p[i][j];
        return tmp;
    }
    inte p[2][2];
    int l, r;
};
struct col {
    int i, tp;
    int t1, t2;
    inte ans() { return inte(t1) / t2; }
};
bool operator<(const col &a, const col &b) {
    

    return ll(a.t1) * b.t2 < ll(b.t1) * a.t2;
}
int main() {
    fast, prec(12);
    inte::p = 998244353;
    int n;
    in(n);
    policy = vvi(n - 1, vi(4, 1));
    vector<statistic> s;
    vi x(n), v(n), p(n);
    lp(i, 0, n - 1) in(x[i], v[i], p[i]),
        s.push_back(statistic(inte(p[i]) / 100, i));
    segment_tree::segment_tree tree(s);
    inte ans = 0;
    vector<col> cols;
    lp(i, 0, n - 2) {
        col tmp;
        tmp.i = i;
        tmp.t1 = x[i + 1] - x[i];
        tmp.tp = 2;
        tmp.t2 = v[i] + v[i + 1];
        cols.push_back(tmp);
        if (v[i] > v[i + 1]) {
            tmp.tp = 1;
            tmp.t2 = v[i] - v[i + 1];
            cols.push_back(tmp);
        }
        if (v[i] < v[i + 1]) {
            tmp.tp = 0;
            tmp.t2 = v[i + 1] - v[i];
            cols.push_back(tmp);
        }
    }
    sort(cols);
    for (auto &c : cols) {
        auto old = policy[c.i];
        fill(rang(policy[c.i]), 0);
        policy[c.i][c.tp] = 1;
        tree.modify_single(c.i, statistic(inte(p[c.i]) / 100, c.i));
        ans += tree.root->s.ans() * c.ans();
        policy[c.i] = old;
        policy[c.i][c.tp] = 0;
        tree.modify_single(c.i, statistic(inte(p[c.i]) / 100, c.i));
        if (tree.root->s.ans().v == 0)
            break;
    }
    ou(ans);
    return 0;
}
