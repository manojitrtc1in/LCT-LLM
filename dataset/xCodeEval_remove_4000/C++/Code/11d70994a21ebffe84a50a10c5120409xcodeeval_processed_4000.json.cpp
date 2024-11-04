





















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
gene bool tmin(T &a, T b) { return b < a ? a = b, true : false; }
gene bool tmax(T &a, T b) { return b > a ? a = b, true : false; }

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

template <class T, class C = less<typename T::value_type>>
void sort(T &a, C c = C()) {
    sort(rang(a), c);
}
gene void reve(T &a) { reverse(rang(a)); }
gene void uniq(T &a) { sort(a), a.erase(unique(rang(a)), end(a)); }
gene void shuf(T &a) { shuffle(rang(a), rng); }
gene void merg(T l, T m, T r) { inplace_merge(l, m, r); }

template <typename... T> void in(T &... a) { ((cin >> a), ...); }
template <typename A, typename... B> void ou(const A &a, const B &... b) {
    cout << a, ((cout << ' ' << b), ...), cout << endl;
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
namespace id2 {
const int SIZE = 1 << 16;
uint8_t table[SIZE];
bool WasInitialized() { return table[2]; }
bool Init() {
    for (int i = 1; i < SIZE; ++i) {
        for (uint8_t pow = 0; pow < 16; ++pow) {
            if ((i >> pow) & 1) {
                table[i] = pow;
            }
        }
    }
    return true;
}
int Get(int value) {
    return WasInitialized() || Init(), table[value & (SIZE - 1)];
}
struct id2 {
    uint64_t high, low;
    id2(uint64_t high_, uint64_t low_) : high(high_), low(low_) {}
    id2(uint64_t low_ = 0) : high(0), low(low_) {}
};
bool operator==(id2 lhs, id2 rhs) {
    return lhs.low == rhs.low && lhs.high == rhs.high;
}
bool operator<=(id2 lhs, id2 rhs) {
    return lhs.high < rhs.high || (lhs.high == rhs.high && lhs.low <= rhs.low);
}
bool operator>=(id2 lhs, id2 rhs) { return rhs <= lhs; }
bool operator!=(id2 lhs, id2 rhs) { return !(lhs == rhs); }
bool operator<(id2 lhs, id2 rhs) { return !(lhs >= rhs); }
bool operator>(id2 lhs, id2 rhs) { return !(lhs <= rhs); }
int id1(uint32_t value) {
    return (value >> 16) ? Get(value >> 16) + 16 : Get(value);
}
int id5(uint64_t value) {
    return (value >> 32) ? id1(uint32_t(value >> 32)) + 32
                         : id1(value & ~uint32_t(0));
}
int id0(id2 value) {
    return value.high ? id5(value.high) + 64
                      : id5(value.low);
}
id2 operator+(id2 lhs, id2 rhs) {
    id2 ret(lhs.high + rhs.high, lhs.low + rhs.low);
    ret.high += (ret.low < lhs.low);
    return ret;
}
id2 operator-(id2 lhs, id2 rhs) {
    id2 ret(lhs.high - rhs.high, lhs.low - rhs.low);
    ret.high -= (lhs.low < ret.low);
    return ret;
}
id2 &operator+=(id2 &lhs, id2 rhs) { return lhs = lhs + rhs; }
id2 &operator-=(id2 &lhs, id2 rhs) { return lhs = lhs - rhs; }
id2 operator<<(id2 lhs, int cnt) {
    if (cnt == 0) {
        return lhs;
    }
    if (cnt >= 64) {
        return id2(lhs.low << (cnt - 64), 0);
    }
    return id2((lhs.high << cnt) | (lhs.low >> (64 - cnt)),
                     lhs.low << cnt);
}
id2 operator>>(id2 lhs, int cnt) {
    if (cnt == 0) {
        return lhs;
    }
    if (cnt >= 64) {
        return id2(lhs.high >> (cnt - 64));
    }
    return id2(lhs.high >> cnt,
                     (lhs.low >> cnt) | (lhs.high << (64 - cnt)));
}
id2 &operator>>=(id2 &lhs, int cnt) { return lhs = lhs >> cnt; }
id2 &operator<<=(id2 &lhs, int cnt) { return lhs = lhs << cnt; }
id2 operator*(id2 lhs, id2 rhs) {
    uint64_t a32 = lhs.low >> 32, a00 = lhs.low & 0xffffffff;
    uint64_t b32 = rhs.low >> 32, b00 = rhs.low & 0xffffffff;
    id2 ret(lhs.high * rhs.low + lhs.low * rhs.high + a32 * b32,
                  a00 * b00);
    return ret + (id2(a32 * b00) << 32) + (id2(a00 * b32) << 32);
}
void DivMod(id2 a, id2 b, id2 &q, id2 &r) {
    assert(b.low | b.high);
    if (a < b) {
        q = 0, r = a;
        return;
    }
    if (a == b) {
        q = 1, r = 0;
        return;
    }
    const int shift = id0(a) - id0(b);
    q = 0, r = a, b <<= shift;
    for (int i = 0; i <= shift; ++i) {
        q <<= 1;
        if (r >= b) {
            r -= b;
            q.low |= 1;
        }
        b >>= 1;
    }
}
id2 operator/(id2 lhs, id2 rhs) {
    id2 div, rem;
    return DivMod(lhs, rhs, div, rem), div;
}
id2 operator%(id2 lhs, id2 rhs) {
    id2 div, rem;
    return DivMod(lhs, rhs, div, rem), rem;
}
id2 &operator/=(id2 &lhs, id2 rhs) { return lhs = lhs / rhs; }
id2 &operator%=(id2 &lhs, id2 rhs) { return lhs = lhs % rhs; }
} 

namespace id3 {
struct id3 {
    id3(int n_)
        : n(n_), size(n), max_size(n), parent(n), in_left(n), to(n) {}
    void add_edge(int u, int v) { to[u].push_back(v), to[v].push_back(u); }
    void dfs(int u, int p) {
        size[u] = 1, max_size[u] = 0, parent[u] = p;
        for (auto v : to[u])
            if (v != p) {
                dfs(v, u), size[u] += size[v];
                max_size[u] = max(max_size[u], size[v]);
            }
    }
    void partition(int u, int p, int d, vector<int> &left, vector<int> &right) {
        if (d <= 0)
            left.push_back(u);
        if (d >= 0)
            right.push_back(u);
        if (d == -1)
            in_left[u] = true;
        for (auto v : to[u])
            if (v != p)
                partition(v, u, d ? d : (in_left[v] ? -1 : 1), left, right);
    }
    template <class T> void run(const vector<int> &nodes, T solve) {
        if (nodes.size() <= 2) {
            for (auto u : nodes)
                in_left[u] = false;
            solve(nodes, to, nodes[0], in_left);
            return;
        }
        dfs(nodes[0], -1);
        int root = nodes[0];
        for (auto u : nodes) {
            max_size[u] = max(max_size[u], int(nodes.size() - size[u]));
            if (max_size[u] < max_size[root])
                root = u;
            in_left[u] = false;
        }
        int id7 = to[root][0], left_size = 0;
        for (auto v : to[root]) {
            if (left_size + size[v] <= int(nodes.size() / 2))
                left_size += size[v], in_left[v] = true;
            if (size[v] > size[id7])
                id7 = v;
        }
        if (parent[root] != -1 && n - size[root] > size[id7])
            id7 = parent[root];
        if (left_size < (id7 == parent[root]
                             ? n - size[root]
                             : size[id7])) {
            for (auto u : nodes)
                in_left[u] = false;
            in_left[id7] = true;
        }
        vector<int> left, right;
        left.reserve(nodes.size()), right.reserve(nodes.size());
        partition(root, -1, 0, left, right);
        solve(nodes, to, root, in_left);
        vector<int> old = to[root], right_edges;
        right_edges.reserve(old.size()), to[root].clear();
        for (auto v : old)
            if (in_left[v])
                to[root].push_back(v);
            else
                right_edges.push_back(v);
        run(left, solve), to[root] = right_edges;
        run(right, solve), to[root] = old;
    }
    template <class T> void run(T solve) {
        vector<int> nodes(n);
        for (int i = 0; i < n; ++i)
            nodes[i] = i;
        run(nodes, solve);
    }
    int n;
    vector<int> size, max_size, parent;
    vector<bool> in_left;
    vector<vector<int>> to;
};
} 

  

int n, id6;
vi a;
ll ans = 0;
vpll left_front, left_back, right_front, right_back, qu;
vl id4;
void init() {
    n = 0;
    id6 = 0;
    a.clear();
    ans = 0;
    left_front.clear();
    left_back.clear();
    right_front.clear();
    right_back.clear();
    qu.clear();
    id4.clear();
}
void calc(vpll &f, vpll &b) {
    id4.clear();
    int max_l = 0;
    lv(i, f) tmax(max_l, int(f[i].second));
    id4.resize(max_l + 1);
    lp(i, 0, max_l) id4[i] = -1;
    lv(i, f) tmax(id4[f[i].second], f[i].first);
    sort(b);
    qu.clear();
    auto check = [](const pll &x, const pll &y, const pll &z) {
        ll x1 = y.first - x.first, y1 = y.second - x.second;
        ll x2 = z.first - y.first, y2 = z.second - y.second;
        

        

        

        

        if (y2 >= 0 && y1 >= 0)
            return id2::id2(x1) * y2 >=
                   id2::id2(x2) * y1;
        if (y2 <= 0 && y1 <= 0)
            return id2::id2(x1) * (-y2) <=
                   id2::id2(x2) * (-y1);
        if (y2 <= 0 && y1 >= 0)
            return (x1 == 0 || y2 == 0) && (x2 == 0 || y1 == 0);
        if (y2 >= 0 && y1 <= 0)
            return true;
        

    };
    for (auto &p : b) {
        while (qu.size() >= 2 && check(qu[qu.size() - 2], qu.back(), p))
            qu.pop_back();
        qu.push_back(p);
    }
    

    int ptr = 0;
    lp(i, 0, max_l) {
        while (ptr + 1 < qu.size() &&
               i * qu[ptr].first + qu[ptr].second <=
                   i * qu[ptr + 1].first + qu[ptr + 1].second)
            ++ptr;
        tmax(ans, i * qu[ptr].first + qu[ptr].second + id4[i]);
    }
}
void dfs(int u, int p, const vvi &to, const vector<bool> &in_left, vpll &f,
         vpll &b, ll cur_dep, ll cur_sum, ll cur_back, bool dir) {
    cur_dep += 1;
    cur_sum += a[u];
    cur_back += cur_dep * a[u];
    int nc = 0;
    for (auto v : to[u])
        if (v != p)
            if ((!dir && in_left[v]) || (dir && !in_left[v])) {
                dfs(v, u, to, in_left, f, b, cur_dep, cur_sum, cur_back, dir);
                ++nc;
            }
    if (nc == 0) {
        b.emplace_back(cur_sum, cur_back);
        f.emplace_back((cur_dep + 1) * cur_sum - cur_back -
                           cur_dep * a[id6],
                       cur_dep - 1);
    }
}
void solve(const vi &nodes, const vvi &to, int root,
           const vector<bool> &in_left) {
    

    id6 = root;
    left_front.clear();
    left_back.clear();
    right_front.clear();
    right_back.clear();
    dfs(root, -1, to, in_left, left_front, left_back, 0, 0, 0, 0);
    dfs(root, -1, to, in_left, right_front, right_back, 0, 0, 0, true);
    calc(left_front, right_back);
    calc(right_front, left_back);
}
ll bf_ans = 0;
vvi bf_to;
void bf_init() {
    bf_ans = 0;
    bf_to.clear();
}
void bf(int u, int p, ll d, ll cur) {
    cur += d * a[u];
    tmax(bf_ans, cur);
    for (auto v : bf_to[u])
        if (v != p) {
            bf(v, u, d + 1, cur);
        }
}
int main_() {
    for (int I = 1;; ++I) {
        

        srand(I);
        init();
        bf_init();
        n = rand() % 100 + 1;
        ou(n);
        id3::id3 tdc(n);
        bf_to.resize(n);
        lp(i, 1, n - 1) {
            int u = i, v = rand() % i;
            tdc.add_edge(u, v);
            bf_to[u].push_back(v);
            bf_to[v].push_back(u);
            ou(u, v);
        }
        a.resize(n);
        lv(i, a) a[i] = rand() % 100;
        ou(a);
        tdc.run(solve);
        lp(r, 0, n - 1) bf(r, -1, 1, 0);
        ou(I, ans, bf_ans);
        assert(ans == bf_ans);
        ou("");
    }
}
int main() {
    fast, prec(12);
    in(n);
    id3::id3 tdc(n);
    lp(i, 1, n - 1) {
        int u, v;
        in(u, v);
        --u, --v;
        tdc.add_edge(u, v);
    }
    a.resize(n);
    in(a);
    left_front.reserve(n);
    left_back.reserve(n);
    right_front.reserve(n);
    right_back.reserve(n);
    tdc.run(solve);
    ou(ans);
    return 0;
}
