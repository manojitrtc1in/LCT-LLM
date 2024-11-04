


















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

template <class F, class S> pair<F, S> operator-(pair<F, S> a) {
    a.first = -a.first, a.second = -a.second;
    return a;
}
template <class F, class S>
pair<F, S> operator+(pair<F, S> a, const pair<F, S> &b) {
    a.first += b.first, a.second += b.second;
    return a;
}
template <class F, class S>
pair<F, S> operator-(pair<F, S> a, const pair<F, S> &b) {
    a.first -= b.first, a.second -= b.second;
    return a;
}
template <class F, class S>
pair<F, S> operator*(pair<F, S> a, const pair<F, S> &b) {
    a.first *= b.first, a.second *= b.second;
    return a;
}
template <class F, class S>
pair<F, S> operator/(pair<F, S> a, const pair<F, S> &b) {
    a.first /= b.first, a.second /= b.second;
    return a;
}
template <class F, class S, class T>
pair<F, S> operator*=(pair<F, S> a, const T &b) {
    a.first *= b, a.second *= b;
    return a;
}
template <class F, class S, class T>
pair<F, S> operator/=(pair<F, S> a, const T &b) {
    a.first /= b, a.second /= b;
    return a;
}

template <class F, class S> struct zip_ {
    zip_(F &f_, S &s_) : f(f_), s(s_) {}
    template <class I, class J> struct iterator {
        iterator(I i_, J j_) : i(i_), j(j_) {}
        auto operator++() {
            ++i, ++j;
            return *this;
        }
        bool operator!=(const iterator &a) const {
            assert((i != a.i && j != a.j) || (i == a.i && j == a.j));
            return i != a.i;
        }
        auto operator*() const { return make_pair(*i, *j); }
        I i;
        J j;
    };
    template <class I, class J> auto iterator_(I i, J j) const {
        return iterator<I, J>(i, j);
    }
    auto begin() const { return iterator_(f.begin(), s.begin()); }
    auto end() const { return iterator_(f.end(), s.end()); }
    F &f;
    S &s;
};
template <class F, class S> auto zip(F &f, S &s) { return zip_<F, S>(f, s); }

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
gene using id5 = unordered_multiset<T, hash_safe<T>>;
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
namespace geometry_2d {
template <class T> struct id6 {
    id6(T i = 0, T j = 0) : x(i), y(j) {}
    id6(const vector<T> &v) : x(v[0]), y(v[1]) { assert(v.size() == 2); }
    int dir() const { return x ? x < 0 : (y ? y < 0 : -1); }
    operator vector<T>() const {
        vector<T> v;
        v.push_back(x);
        v.push_back(y);
        return v;
    }
    T x, y;
};
template <class T> double angle(const id6<T> &a) {
    return atan2(double(a.x), double(a.y));
}
template <class T> T id2(const id6<T> &a) {
    return a.x * a.x + a.y * a.y;
}
template <class T> T id3(const id6<T> &a) {
    return sqrt(id2(a));
}
template <class T>
T cross_product(const id6<T> &a, const id6<T> &b) {
    return a.x * b.y - b.x * a.y;
}
template <class T> T dot_product(const id6<T> &a, const id6<T> &b) {
    return a.x * b.x + b.y * a.y;
}
template <class T>
auto operator+(const id6<T> &a, const id6<T> &b) {
    return id6<T>(a.x + b.x, a.y + b.y);
}
template <class T>
auto operator-(const id6<T> &a, const id6<T> &b) {
    return id6<T>(a.x - b.x, a.y - b.y);
}
template <class T> auto operator*(const id6<T> &a, const T &b) {
    return id6<T>(a.x * b, a.y * b);
}
template <class T> auto operator/(const id6<T> &a, const T &b) {
    return id6<T>(a.x / b, a.y / b);
}
template <class T> T operator<(const id6<T> &a, const id6<T> &b) {
    int t = a.dir() - b.dir();
    return t ? (t < 0) : (cross_product(a, b) < 0);
}
template <class T> auto &operator>>(istream &s, id6<T> &a) {
    return s >> a.x >> a.y;
}
template <class T> auto &operator<<(ostream &s, const id6<T> &a) {
    return s << a.x << ' ' << a.y;
}
template <class T> struct id4 {
    id4(const id6<T> &p_, const id6<T> &q_)
        : p(p_), q(q_), a(angle(p - q)) {}
    id6<T> p, q;
    double a;
};
template <class T> auto intersection(const id4<T> &a, const id4<T> &b) {
    double a1 = cross_product(b.p - a.q, b.q - b.p),
           a2 = cross_product(a.p - b.q, b.q - b.p);
    if (abs(a1 + a2) < 1e-8)
        return vector<id6<T>>();
    else
        return vector<id6<T>>(1, (a.p * a1 + a.q * a2) / (a1 + a2));
}
template <class T> struct id1 {
    id1(const id6<T> &p_, const id6<T> &q_)
        : p(p_), q(q_), a(angle(p - q)) {}
    id1(const vector<T> &p_, const vector<T> &q_)
        : p(p_), q(q_), a(angle(p - q)) {}
    operator id4<T>() const { return id4<T>(p, q); }
    id6<T> p, q;
    double a;
};
template <class T>
auto contains(const id1<T> &a, const id6<T> &b) {
    return abs(cross_product(a.q - a.p, b - a.p)) < 1e-8 &&
           dot_product(b - a.p, b - a.q) < 1e-8;
}
template <class T>
auto intersection(const id1<T> &a, const id1<T> &b) {
    auto i = intersection(id4<T>(a), id4<T>(b));
    vector<id6<T>> r, t;
    if (i.size())
        r = i;
    else {
        r.push_back(a.p);
        r.push_back(a.q);
        r.push_back(b.p);
        r.push_back(b.q);
    }
    for (auto p : r)
        if (contains(a, p) && contains(b, p))
            t.push_back(p);
    return t;
}
} 



int main() {
    fast, prec(12);
    int n;
    in(n);
    vector<geometry_2d::id6<ll>> a(n);
    map<pii, int> index;
    in(a);
    lv(i, a) index[{a[i].x, a[i].y}] = i;
    sort(a, [](auto u, auto v) { return u.x < v.x; });
    str d;
    in(d);
    reve(d);
    vector<geometry_2d::id6<ll>> ans;
    ans.push_back(a[0]);
    a.erase(a.begin());
    while (a.size()) {
        int td;
        if (d.empty())
            td = 1;
        elif (d.back() == 'L') td = 1;
        else td = -1;
        if (d.size())
            d.pop_back();
        int cur = 0;
        lv(i, a) {
            if (geometry_2d::cross_product(a[cur] - ans.back(),
                                           a[i] - ans.back()) *
                    td <
                0) {
                cur = i;
            }
        }
        ans.push_back(a[cur]);
        a.erase(a.begin() + cur);
    }
    vi aaa;
    for (auto t : ans)
        aaa.push_back(index[{t.x, t.y}] + 1);
    ou(aaa);
    return 0;
}
