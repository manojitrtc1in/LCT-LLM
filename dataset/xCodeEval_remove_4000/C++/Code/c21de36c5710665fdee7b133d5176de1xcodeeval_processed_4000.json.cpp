


















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
gene using id0 = unordered_set<T, hash_safe<T>>;
gene using id1 = unordered_multiset<T, hash_safe<T>>;
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
namespace segment_tree {
template <class T> struct segment_tree {
    struct node {
        node *c[2];
        T s;
    } * root;
    int n;
    node *build(const vector<T> &a, int l, int r) {
        node *u = new node;
        if (l == r)
            u->c[0] = u->c[1] = 0, u->s = a[l];
        else {
            int m = (l + r) / 2;
            u->c[0] = build(a, l, m), u->c[1] = build(a, m + 1, r);
            u->s = T::merge(u->c[0]->s, u->c[1]->s);
        }
        return u;
    }
    void build(const vector<T> &a) {
        root = build(a, 0, int(a.size() - 1)), n = int(a.size());
    }
    segment_tree() : root(0), n(0) {}
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
    void modify_single(int p, const T &s, node *u = 0, int l = -1, int r = -1) {
        if (!u)
            u = root, l = 0, r = n - 1;
        if (l == r) {
            assert(p == l);
            u->s = s;
        } else {
            int m = (l + r) / 2;
            if (p <= m)
                modify_single(p, s, u->c[0], l, m);
            else
                modify_single(p, s, u->c[1], m + 1, r);
            merge(u);
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
    T query_segment(int a, int b, node *u = 0, int l = -1, int r = -1) {
        if (!u)
            u = root, l = 0, r = n - 1;
        assert(a >= 0 && b < n && a <= b);
        if (a <= l && b >= r)
            return u->s;
        else {
            int m = (l + r) / 2;
            if (b <= m)
                return query_segment(a, b, u->c[0], l, m);
            if (a > m)
                return query_segment(a, b, u->c[1], m + 1, r);
            return T::merge(query_segment(a, b, u->c[0], l, m),
                            query_segment(a, b, u->c[1], m + 1, r));
        }
    }
};
} 

namespace statistic {
struct statistic {
    statistic() {}
    statistic(const vi &t) { lv(i, t) mx[i] = mi[i] = t[i]; }
    int modification() { return 0; }
    void modify() {}
    void resverse() {}
    static statistic merge(const statistic &a, const statistic &b) {
        statistic t = a;
        lp(i, 0, 31) {
            t.mx[i] = max(t.mx[i], b.mx[i]);
            t.mi[i] = min(t.mi[i], b.mi[i]);
        }
        return t;
    }
    static void push(statistic &a, int &t) {}
    int mx[32], mi[32];
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



vi aswe;
void generate(vi p) {
    lp(i, 0, (1 << p.size()) - 1) {
        int s = 0;
        lv(j, p) {
            if ((i >> j) & 1)
                s += p[j];
            else
                s -= p[j];
        }
        aswe[i] = s;
    }
}

using namespace std;
namespace fast_io {


struct reader {
    FILE *f;
    char *p, *e;
    vector<char> v;
    void ipt() {
        for (int i = 1, t;; i <<= 1) {
            v.resize(v.size() + i);
            if (i != (t = int(fread(&v[0] + v.size() - i, 1, i, f)))) {
                p = &v[0], e = p + v.size() - i + t;
                break;
            }
        }
    }
    void ign() {
        while (p != e && isspace(*p))
            ++p;
    }
    int isc() { return p != e && !isspace(*p); }
    int isd() { return p != e && isdigit(*p); }
    reader(FILE *_f = stdin) : f(_f) { ipt(); }
    reader(string _f) : f(fopen(_f.c_str(), "r")) { ipt(); }
    ~reader() { fclose(f); }
    template <class T> reader &operator>>(T &a) {
        int n = 1;
        ign();
        if (*p == '-')
            n = -1, ++p;
        for (a = 0; isd();)
            a = (a << 3) + (a << 1) + *p++ - '0';
        a *= n;
        return *this;
    }
    auto &operator>>(char &a) {
        ign();
        a = *p++;
        return *this;
    }
    auto &operator>>(char *a) {
        for (ign(); isc();)
            *a++ = *p++;
        *a = 0;
        return *this;
    }
    char get() { return *p++; }
};
struct writer {
    FILE *f;
    vector<char> p;
    writer(FILE *_f = stdout) : f(_f) {}
    writer(string _f) : f(fopen(_f.c_str(), "w")) {}
    ~writer() {
        if (p.size())
            fwrite(&p[0], 1, p.size(), f);
        fclose(f);
    }
    auto &operator<<(char a) {
        p.push_back(a);
        return *this;
    }
    auto &operator<<(const char *a) {
        while (*a)
            p.push_back(*a++);
        return *this;
    }
    template <class T> auto &operator<<(T a) {
        if (a < 0)
            p.push_back('-'), a = -a;
        static char t[19];
        char *q = t;
        do {
            T b = a / 10;
            *q++ = char(a - b * 10 + '0'), a = b;
        } while (a);
        while (q > t)
            p.push_back(*--q);
        return *this;
    }
};
} 

int main() {
    fast, prec(12);
    auto reader = fast_io::reader();
    auto writer = fast_io::writer();
    int n, k;
    reader >> n >> k;
    auto a = vect<statistic::statistic>({}, n);
    aswe.resize(1 << k);
    vi ttp(k);
    lp(i, 1, n) {
        lv(j, ttp) reader >> ttp[j];
        generate(ttp);
        a[i - 1] = statistic::statistic(aswe);
    }
    segment_tree::segment_tree<statistic::statistic> tree(a);
    int q;
    reader >> q;
    lp(ii, 1, q) {
        int t;
        reader >> t;
        if (t == 1) {
            int i;
            reader >> i;
            lv(j, ttp) reader >> ttp[j];
            --i;
            generate(ttp);
            tree.modify_single(i, statistic::statistic(aswe));
        } else {
            int l, r;
            reader >> l >> r;
            int ans = 0;
            auto tmp = tree.query_segment(l - 1, r - 1);
            lv(j, aswe) tmax(ans, tmp.mx[j] - tmp.mi[j]);
            writer << ans << '\n';
        }
    }
    return 0;
}
