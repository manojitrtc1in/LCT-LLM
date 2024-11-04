




















using namespace std;
using namespace __gnu_pbds;
const auto eps = 1e-8, pi = acos(-1);
template <class T> int comp(const T &a, const T &b) {
    return a < b - eps ? -1 : (a > b + eps);
}

template <class T> auto regu(const T &a) { return int(a); }
template <> auto regu(const long long &a) { return a; }
template <> auto regu(const unsigned long long &a) {
    return (unsigned long long)a;
}

template <class T> int barr(const T &a, const int &i) {
    return int(a >> i & 1);
}
template <class T> int bcnt(const T &a) { return __builtin_popcount(a); }
template <> int bcnt(const long long &a) { return __builtin_popcountll(a); }
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
template <class T> void reve(T &a) { reverse(rang(a)); }
template <class T> void uniq(T &a) {
    sort(a), a.erase(unique(rang(a)), end(a));
}
template <class T> void shuf(T &a) { shuffle(rang(a), rng); }
template <class T> void merg(T l, T m, T r) { inplace_merge(l, m, r); }

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
            u->s = T::merge(u->c[0]->s, u->c[1]->s);
        }
        u->l = l, u->r = r;
        return u;
    }
    void build(const vector<T> &a) { root = build(a, 0, int(a.size() - 1)); }
    segment_tree() : root(0) {}
    segment_tree(const vector<T> &a) { build(a); }
    void destroy(node *u) {
        if (u) {
            destroy(u->c[0]), destroy(u->c[1]);
            delete u;
        }
    }
    ~segment_tree() { destroy(root); }
    void modify(node *u) {
        auto t = u->s.modification();
        if (u->c[0])
            T::push(u->c[0]->s, t), T::push(u->c[1]->s, t);
        u->s.modify();
    }
    void merge(node *u) { u->s = T::merge(u->c[0]->s, u->c[1]->s); }
    void modify_single(int p, const T &s, node *u = 0) {
        u = u ? u : root;
        modify(u);
        if (u->l == u->r) {
            assert(p == u->l);
            u->s = s;
        } else {
            modify_single(p, s, u->c[p > u->c[0]->r]);
            modify(u->c[p <= u->c[0]->r]), merge(u);
        }
    }
    template <class A> void modify_segment(int l, int r, A &t, node *u = 0) {
        u = u ? u : root;
        assert((u != root || (u->l <= l && u->r >= r)) && l <= r), modify(u);
        if (l <= u->l && r >= u->r)
            T::push(u->s, t), modify(u);
        else {
            if (l <= u->c[0]->r)
                modify_segment(l, r, t, u->c[0]);
            else
                modify(u->c[0]);
            if (r >= u->c[1]->l)
                modify_segment(l, r, t, u->c[1]);
            else
                modify(u->c[1]);
            merge(u);
        }
    }
    const T &query_single(int p, node *u = 0) {
        u = u ? u : root, modify(u);
        if (u->l == u->r) {
            assert(p == u->l);
            return u->s;
        } else {
            return query_single(p, u->c[p > u->c[0]->r]);
        }
    }
    T query_segment(int l, int r, node *u = 0) {
        u = u ? u : root, modify(u);
        assert((u != root || (u->l <= l && u->r >= r)) && l <= r);
        if (l <= u->l && r >= u->r)
            return u->s;
        else {
            if (r <= u->c[0]->r)
                return query_segment(l, r, u->c[0]);
            if (l >= u->c[1]->l)
                return query_segment(l, r, u->c[1]);
            return T::merge(query_segment(l, r, u->c[0]),
                            query_segment(l, r, u->c[1]));
        }
    }
};
} 

namespace statistic {
struct statistic {
    statistic(int x_ = -1, int y_ = 0) : x(x_), y(y_) {}
    int modification() { return 0; }
    void modify() {}
    void resverse() {}
    static statistic merge(const statistic &a, const statistic &b) {
        return statistic(a.x + b.x, max(a.y + b.x, b.y));
    }
    static void push(statistic &a, int &t) {}
    int answer() { return max(x, y); }
    int x, y;
};
template <class T> struct add_min {
    int i;
    T v, d;
    add_min() {}
    add_min(T _v, int _i) : i(_i), v(_v), d(0) {}
    T modification() { return d; }
    void modify() { v += d, d = 0; }
    void reverse() {}
    static add_min merge(const add_min &a, const add_min &b) {
        assert(!a.d && !b.d);
        if (a.v < b.v)
            return a;
        else
            return b;
    }
    static void push(add_min &a, T &d) { a.d += d; }
};
template <class T> struct add_sum {
    int l;
    T s, d;
    add_sum() {}
    add_sum(T _s, int _l = 1) : l(_l), s(_s), d(0) {}
    T modification() { return d; }
    void modify() { s += d * l, d = 0; }
    void reverse() {}
    static add_sum merge(const add_sum &a, const add_sum &b) {
        return add_sum(a.s + b.s, a.l + b.l);
    }
    static void push(add_sum &a, T &d) { a.d += d; }
};
} 



struct gift {
    int n, k, m;
    vpii c;
};
gift generate() {
    gift t;
    t.n = rint(1, 10);
    t.k = rint(1, t.n);
    t.m = rint(1, 10);
    lp(i, 1, t.m) t.c.push_back({rint(1, t.n), rint(1, t.n)});
    return t;
}
gift id1() {
    gift t;
    in(t.n, t.k, t.m);
    lp(i, 1, t.m) {
        int x, y;
        in(x, y);
        t.c.push_back({x, y});
    }
    return t;
}
vi id2(gift g) {
    int n, k, m;
    n = g.n, k = g.k, m = g.m;
    vector<statistic::statistic> a(2 * n + m);
    segment_tree::segment_tree<statistic::statistic> tree(a);
    unordered_set<pii> current;
    vi answer;
    multiset<int> right;
    right.insert(n - 1);
    lp(i, 1, m) {
        int x, y;
        x = g.c[i - 1].first, y = g.c[i - 1].second;
        int p = y + abs(x - k) - 1;
        if (current.count({x, y})) {
            tree.modify_single(
                p, statistic::statistic(tree.query_single(p).x - 1, 0));
            right.erase(right.find(p));
            current.erase({x, y});
        } else {
            tree.modify_single(
                p, statistic::statistic(tree.query_single(p).x + 1, 0));
            right.insert(p);
            current.insert({x, y});
        }
        int l = *right.rbegin() - 1, r = a.size() - 1;
        while (l + 1 < r) {
            int m = (l + r) / 2;
            if (tree.query_segment(0, m).answer() == 0)
                r = m;
            else
                l = m;
        }
        answer.push_back(r + 1 - n);
    }
    return answer;
}
vi id0(gift g) {
    int n, k, m;
    n = g.n, k = g.k, m = g.m;
    unordered_set<pii> current;
    vi answer, count(2 * n + m, -1);
    lp(i, 1, m) {
        int x, y;
        x = g.c[i - 1].first, y = g.c[i - 1].second;
        int p = y + abs(x - k) - 1;
        if (current.count({x, y})) {
            --count[p];
            current.erase({x, y});
        } else {
            ++count[p];
            current.insert({x, y});
        }
        int t = 0, l = n - 1;
        lv(j, count) {
            if (count[j] == 0 || t == 1)
                tmax(l, j);
            t = max(t + count[j], 0);
        }
        answer.push_back(max((l + 1) - n, 0));
    }
    return answer;
}
int main() {
    ios::sync_with_stdio(0);
    cout << setprecision(16) << fixed;
    cin.tie(0);
    for (auto v : id2(id1()))
        ou(v);
    return 0;
    for (int i = 1;; ++i) {
        auto g = generate();
        assert(id2(g) == id0(g));
        ou(i);
    }
    return 0;
}
