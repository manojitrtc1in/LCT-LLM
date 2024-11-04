

















    for (auto &x : a)                                                          \
    f









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
    return (a > 0 && b > 0) || (a < 0 && b < 0)
               ? abs(a) / abs(b)
               : -(abs(a) + abs(b) - 1) / abs(b);
}
gene T ceil(const T &a, const T &b) {
    assert(b != 0);
    return (a > 0 && b > 0) || (a < 0 && b < 0) ? (abs(a) + abs(b) - 1) / abs(b)
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
gene void in(T &a) { cin >> a; }
template <class A, class... B> void in(A &a, B &... b) { cin >> a, in(b...); }
void ou() { cout << endl; }
gene void ou(const T &a) { cout << a << endl; }
template <class A, class... B> void ou(const A &a, const B &... b) {
    cout << a << ' ', ou(b...);
}
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
namespace linear_programming {
template <class T> struct expression;
template <class T = double> struct variable {
    variable(optional<T> _l = optional<T>{}, optional<T> _r = optional<T>{})
        : l(_l), r(_r) {}
    auto operator-() { return -expression<T>(*this); }
    friend auto operator+(variable<T> &a, variable<T> &b) {
        return expression<T>(a) + expression<T>(b);
    }
    friend auto operator+(variable<T> &a, const T &b) {
        return expression<T>(a) + expression<T>(b);
    }
    friend auto operator+(const T &a, variable<T> &b) {
        return expression<T>(a) + expression<T>(b);
    }
    friend auto operator-(variable<T> &a, variable<T> &b) {
        return expression<T>(a) - expression<T>(b);
    }
    friend auto operator-(variable<T> &a, const T &b) {
        return expression<T>(a) - expression<T>(b);
    }
    friend auto operator-(const T &a, variable<T> &b) {
        return expression<T>(a) - expression<T>(b);
    }
    friend auto operator*(variable<T> &a, const T &b) {
        return expression<T>(a) * expression<T>(b);
    }
    friend auto operator*(const T &a, variable<T> &b) {
        return expression<T>(a) * expression<T>(b);
    }
    friend auto operator/(variable<T> &a, const T &b) {
        return expression<T>(a) / expression<T>(b);
    }
    friend auto operator>=(variable<T> &a, const T &b) {
        return expression<T>(a) >= expression<T>(b);
    }
    friend auto operator>=(const T &a, variable<T> &b) {
        return expression<T>(a) >= expression<T>(b);
    }
    friend auto operator<=(variable<T> &a, const T &b) {
        return expression<T>(a) <= expression<T>(b);
    }
    friend auto operator<=(const T &a, variable<T> &b) {
        return expression<T>(a) <= expression<T>(b);
    }
    optional<T> l, r;
    T v;
};
template <class T> auto &operator<<(ostream &s, variable<T> a) {
    return s << a.v;
}
template <class T> struct constraint;
template <class T = double> struct expression {
    expression() {}
    expression(T c) : e{{0, c}} {}
    expression(variable<T> &v) : e{{&v, 1}} {}
    expression(const unordered_map<variable<T> *, T> &_e) : e(_e) {}
    auto operator-() const {
        auto t = *this;
        for (auto &i : t.e)
            i.second *= -1;
        return t;
    }
    friend auto operator+(const expression<T> &a, const expression<T> &b) {
        expression<T> t = a;
        for (auto &i : b.e)
            t.e[i.first] += i.second;
        return t;
    }
    friend auto operator-(const expression<T> &a, const expression<T> &b) {
        expression<T> t = a;
        for (auto &i : b.e)
            t.e[i.first] -= i.second;
        return t;
    }
    friend auto operator*(const expression<T> &a, const expression<T> &b) {
        assert((a.e.size() == 1 && a.e.count(0)) ||
               (b.e.size() == 1 && b.e.count(0)));
        expression<T> t;
        T c;
        if (a.e.size() == 1 && a.e.count(0))
            t.e = b.e, c = a.e.begin()->second;
        else
            t.e = a.e, c = b.e.begin()->second;
        for (auto &i : t.e)
            i.second *= c;
        return t;
    }
    friend auto operator/(const expression<T> &a, const expression<T> &b) {
        assert(b.e.size() == 1 && b.e.count(0));
        expression<T> t = a;
        T c = b.e[0];
        for (auto &i : t.e)
            i.second *= c;
        return t;
    }
    auto &operator+=(const expression<T> &a) { return *this = *this + a; }
    auto &operator-=(const expression<T> &a) { return *this = *this - a; }
    auto &operator*=(const expression<T> &a) { return *this = *this * a; }
    auto &operator/=(const expression<T> &a) { return *this = *this / a; }
    friend auto operator>=(const expression<T> &a, const expression<T> &b) {
        expression<T> t = a - b;
        return constraint<T>(t);
    };
    friend auto operator<=(const expression<T> &a, const expression<T> &b) {
        return -a >= -b;
    };
    unordered_map<variable<T> *, T> e;
};
template <class T = double> struct constraint {
    constraint(const expression<T> &_e) : e(_e) {}
    expression<T> e;
};
template <class T> struct id0;
template <class T, class O = id0<T>>
optional<T> maximize(const expression<T> &target,
                     vector<constraint<T>> constraints) {
    unordered_map<variable<T> *, int> variables;
    for (const auto &i : constraints)
        for (const auto &j : i.e.e)
            if (j.first && !variables.count(j.first))
                variables[j.first] = int(variables.size()) + 1;
    for (const auto &j : target.e)
        if (j.first && !variables.count(j.first))
            variables[j.first] = int(variables.size()) + 1;
    for (auto [v, i] : variables) {
        if (v->l)
            constraints.push_back(*v >= *v->l);
        if (v->r)
            constraints.push_back(*v <= *v->r);
    }
    O optimizer(int(constraints.size()), int(variables.size()));
    for (int i = 0; i < int(constraints.size()); ++i)
        for (const auto &j : constraints[i].e.e) {
            int k = (j.first ? variables[j.first] : 0);
            optimizer.a[i + 1][k] += j.second;
        }
    for (const auto &i : target.e) {
        int j = (i.first ? variables[i.first] : 0);
        optimizer.a[0][j] += i.second;
    }
    auto result = optimizer.run();
    if (result.empty())
        return {};
    for (auto i : variables)
        i.first->v = result[i.second];
    return {result[0]};
}
template <class T, class O = id0<T>>
auto minimize(const expression<T> &target,
              const vector<constraint<T>> &constraints) {
    return maximize<T, O>(-target, constraints);
}
template <class T = double> struct id0 {
    int n, m, p;
    vector<vector<T>> a;
    vector<int> mp, ma, md;
    vector<T> result;
    const T E;
    id0(int _n, int _m)
        : n(_n), m(_m), p(0), a(n + 2, vector<T>(m + 2)), mp(n + 1),
          ma(m + n + 2), md(m + 2), result(m + 1), E(1e-8) {}
    T &operator[](const pair<int, int> &i) {
        return a.at(i.first).at(i.second);
    }
    void pivot(int l, int e) {
        swap(mp[l], md[e]), ma[mp[l]] = l, ma[md[e]] = -1;
        double t = -a[l][e];
        a[l][e] = -1;
        vector<int> qu;
        for (int i = 0; i <= m + 1; ++i)
            if (fabs(a[l][i] /= t) > E)
                qu.push_back(i);
        for (int i = 0; i <= n + 1; ++i)
            if (i != l && fabs(a[i][e]) > E) {
                t = a[i][e];
                a[i][e] = 0;
                for (int j = 0; j < int(qu.size()); ++j)
                    a[i][qu[j]] += a[l][qu[j]] * t;
            }
        if (-p == l)
            p = e;
        else if (p == e)
            p = -l;
    }
    int optimize(int d) {
        for (int l = -1, e = -1;; pivot(l, e), l = -1, e = -1) {
            for (int i = 1; i <= m + 1; ++i)
                if (a[d][i] > E) {
                    e = i;
                    break;
                }
            if (e == -1)
                return 1;
            T t;
            for (int i = 1; i <= n; ++i)
                if (a[i][e] < -E && (l == -1 || a[i][0] / -a[i][e] < t))
                    t = a[i][0] / -a[i][e], l = i;
            if (l == -1)
                return 0;
        }
    }
    vector<T> run() {
        for (int i = 1; i <= m + 1; ++i)
            ma[i] = -1, md[i] = i;
        for (int i = m + 2; i <= m + n + 1; ++i)
            ma[i] = i - (m + 1), mp[i - (m + 1)] = i;
        T t = a[1][0];
        int l = 1;
        for (int i = 2; i <= n; ++i)
            if (a[i][0] < t)
                t = a[i][0], l = i;
        if (t < -E) {
            for (int i = 1; i <= n; ++i)
                a[i][m + 1] = 1;
            a[n + 1][m + 1] = -1, p = m + 1, pivot(l, m + 1);
            if (!optimize(n + 1) || fabs(a[n + 1][0]) > E)
                return vector<T>();
            if (p < 0)
                for (int i = 1; i <= m; ++i)
                    if (fabs(a[-p][i]) > E) {
                        pivot(-p, i);
                        break;
                    }
            for (int i = 0; i <= n; ++i)
                a[i][p] = 0;
        }
        if (!optimize(0))
            return vector<T>();
        result[0] = a[0][0];
        for (int i = 1; i <= m; ++i)
            if (ma[i] != -1)
                result[i] = a[ma[i]][0];
        return result;
    }
};
} 



int main() {
    fast, prec(12);
    vi a;
    in(a);
    vector<linear_programming::variable<>> v(30);
    vector<linear_programming::constraint<>> c;
    lp(i, 0, a.size() - 2) {
        linear_programming::expression<> e;
        lp(j, 0, 29) {
            if ((a[i] >> j) & 1)
                e += (1. - v[j]);
            else
                e += v[j];
            if ((a[i + 1] >> j) & 1)
                e -= (1. - v[j]);
            else
                e -= v[j];
        }
        c.push_back(e >= 0);
        c.push_back(e <= 0);
    }
    lp(i, 0, 29) c.push_back(v[i] >= 0), c.push_back(v[i] <= 1);
    lp(i, 0, 99) {
        linear_programming::expression<> t;
        if (i == 0) {
            lp(j, 0, 29) t += v[j];
        } else
            lp(j, 0, 29) if (rint(0, 1)) t += rint(0, 1) ? v[j] : -v[j];
        if (linear_programming::minimize(t, c)) {
            int x = 0;
            lp(j, 0, 29) {
                if (abs(v[j].v - 1) < 1e-3)
                    x += (1 << j);
                elif (abs(v[j].v) < 1e-3);
                else {
                    goto again;
                }
            }
            ou(x);
            return 0;
        }
    again:
        continue;
    }
    ou(-1);
    return 0;
}
