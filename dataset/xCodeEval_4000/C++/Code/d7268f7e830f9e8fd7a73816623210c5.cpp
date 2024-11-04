#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <chrono>
#include <cmath>
#include <complex>
#include <deque>
#include <forward_list>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
using namespace std;
using lint = long long;
using pint = pair<int, int>;
using plint = pair<lint, lint>;
struct fast_ios { fast_ios(){ cin.tie(nullptr), ios::sync_with_stdio(false), cout << fixed << setprecision(20); }; } fast_ios_;
#define ALL(x) (x).begin(), (x).end()
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define IFOR(i, begin, end) for(int i=(end)-1,i##_begin_=(begin);i>=i##_begin_;i--)
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)
template <typename T, typename V>
void ndarray(vector<T>& vec, const V& val, int len) { vec.assign(len, val); }
template <typename T, typename V, typename... Args> void ndarray(vector<T>& vec, const V& val, int len, Args... args) { vec.resize(len), for_each(begin(vec), end(vec), [&](T& v) { ndarray(v, val, args...); }); }
template <typename T> bool chmax(T &m, const T q) { return m < q ? (m = q, true) : false; }
template <typename T> bool chmin(T &m, const T q) { return m > q ? (m = q, true) : false; }
int floor_lg(long long x) { return x <= 0 ? -1 : 63 - __builtin_clzll(x); }
template <typename T1, typename T2> pair<T1, T2> operator+(const pair<T1, T2> &l, const pair<T1, T2> &r) { return make_pair(l.first + r.first, l.second + r.second); }
template <typename T1, typename T2> pair<T1, T2> operator-(const pair<T1, T2> &l, const pair<T1, T2> &r) { return make_pair(l.first - r.first, l.second - r.second); }
template <typename T> vector<T> sort_unique(vector<T> vec) { sort(vec.begin(), vec.end()), vec.erase(unique(vec.begin(), vec.end()), vec.end()); return vec; }
template <typename T> int arglb(const std::vector<T> &v, const T &x) { return std::distance(v.begin(), std::lower_bound(v.begin(), v.end(), x)); }
template <typename T> int argub(const std::vector<T> &v, const T &x) { return std::distance(v.begin(), std::upper_bound(v.begin(), v.end(), x)); }
template <typename T> istream &operator>>(istream &is, vector<T> &vec) { for (auto &v : vec) is >> v; return is; }
template <typename T> ostream &operator<<(ostream &os, const vector<T> &vec) { os << '['; for (auto v : vec) os << v << ','; os << ']'; return os; }
template <typename T, size_t sz> ostream &operator<<(ostream &os, const array<T, sz> &arr) { os << '['; for (auto v : arr) os << v << ','; os << ']'; return os; }
#if __cplusplus >= 201703L
template <typename... T> istream &operator>>(istream &is, tuple<T...> &tpl) { std::apply([&is](auto &&... args) { ((is >> args), ...);}, tpl); return is; }
template <typename... T> ostream &operator<<(ostream &os, const tuple<T...> &tpl) { os << '('; std::apply([&os](auto &&... args) { ((os << args << ','), ...);}, tpl); return os << ')'; }
#endif
template <typename T> ostream &operator<<(ostream &os, const deque<T> &vec) { os << "deq["; for (auto v : vec) os << v << ','; os << ']'; return os; }
template <typename T> ostream &operator<<(ostream &os, const set<T> &vec) { os << '{'; for (auto v : vec) os << v << ','; os << '}'; return os; }
template <typename T, typename TH> ostream &operator<<(ostream &os, const unordered_set<T, TH> &vec) { os << '{'; for (auto v : vec) os << v << ','; os << '}'; return os; }
template <typename T> ostream &operator<<(ostream &os, const multiset<T> &vec) { os << '{'; for (auto v : vec) os << v << ','; os << '}'; return os; }
template <typename T> ostream &operator<<(ostream &os, const unordered_multiset<T> &vec) { os << '{'; for (auto v : vec) os << v << ','; os << '}'; return os; }
template <typename T1, typename T2> ostream &operator<<(ostream &os, const pair<T1, T2> &pa) { os << '(' << pa.first << ',' << pa.second << ')'; return os; }
template <typename TK, typename TV> ostream &operator<<(ostream &os, const map<TK, TV> &mp) { os << '{'; for (auto v : mp) os << v.first << "=>" << v.second << ','; os << '}'; return os; }
template <typename TK, typename TV, typename TH> ostream &operator<<(ostream &os, const unordered_map<TK, TV, TH> &mp) { os << '{'; for (auto v : mp) os << v.first << "=>" << v.second << ','; os << '}'; return os; }
#ifdef HITONANODE_LOCAL
const string COLOR_RESET = "\033[0m", BRIGHT_GREEN = "\033[1;32m", BRIGHT_RED = "\033[1;31m", BRIGHT_CYAN = "\033[1;36m", NORMAL_CROSSED = "\033[0;9;37m", RED_BACKGROUND = "\033[1;41m", NORMAL_FAINT = "\033[0;2m";
#define dbg(x) cerr << BRIGHT_CYAN << #x << COLOR_RESET << " = " << (x) << NORMAL_FAINT << " (L" << __LINE__ << ") " << __FILE__ << COLOR_RESET << endl
#define dbgif(cond, x) ((cond) ? cerr << BRIGHT_CYAN << #x << COLOR_RESET << " = " << (x) << NORMAL_FAINT << " (L" << __LINE__ << ") " << __FILE__ << COLOR_RESET << endl : cerr)
#else
#define dbg(x) (x)
#define dbgif(cond, x) 0
#endif

template <int md> struct ModInt {
#if __cplusplus >= 201402L
#define MDCONST constexpr
#else
#define MDCONST
#endif
    using lint = long long;
    MDCONST static int mod() { return md; }
    static int get_primitive_root() {
        static int primitive_root = 0;
        if (!primitive_root) {
            primitive_root = [&]() {
                std::set<int> fac;
                int v = md - 1;
                for (lint i = 2; i * i <= v; i++)
                    while (v % i == 0) fac.insert(i), v /= i;
                if (v > 1) fac.insert(v);
                for (int g = 1; g < md; g++) {
                    bool ok = true;
                    for (auto i : fac)
                        if (ModInt(g).pow((md - 1) / i) == 1) {
                            ok = false;
                            break;
                        }
                    if (ok) return g;
                }
                return -1;
            }();
        }
        return primitive_root;
    }
    int val;
    MDCONST ModInt() : val(0) {}
    MDCONST ModInt &_setval(lint v) { return val = (v >= md ? v - md : v), *this; }
    MDCONST ModInt(lint v) { _setval(v % md + md); }
    MDCONST explicit operator bool() const { return val != 0; }
    MDCONST ModInt operator+(const ModInt &x) const { return ModInt()._setval((lint)val + x.val); }
    MDCONST ModInt operator-(const ModInt &x) const { return ModInt()._setval((lint)val - x.val + md); }
    MDCONST ModInt operator*(const ModInt &x) const { return ModInt()._setval((lint)val * x.val % md); }
    MDCONST ModInt operator/(const ModInt &x) const { return ModInt()._setval((lint)val * x.inv() % md); }
    MDCONST ModInt operator-() const { return ModInt()._setval(md - val); }
    MDCONST ModInt &operator+=(const ModInt &x) { return *this = *this + x; }
    MDCONST ModInt &operator-=(const ModInt &x) { return *this = *this - x; }
    MDCONST ModInt &operator*=(const ModInt &x) { return *this = *this * x; }
    MDCONST ModInt &operator/=(const ModInt &x) { return *this = *this / x; }
    friend MDCONST ModInt operator+(lint a, const ModInt &x) { return ModInt()._setval(a % md + x.val); }
    friend MDCONST ModInt operator-(lint a, const ModInt &x) { return ModInt()._setval(a % md - x.val + md); }
    friend MDCONST ModInt operator*(lint a, const ModInt &x) { return ModInt()._setval(a % md * x.val % md); }
    friend MDCONST ModInt operator/(lint a, const ModInt &x) {
        return ModInt()._setval(a % md * x.inv() % md);
    }
    MDCONST bool operator==(const ModInt &x) const { return val == x.val; }
    MDCONST bool operator!=(const ModInt &x) const { return val != x.val; }
    MDCONST bool operator<(const ModInt &x) const { return val < x.val; } 

    friend std::istream &operator>>(std::istream &is, ModInt &x) {
        lint t;
        return is >> t, x = ModInt(t), is;
    }
    MDCONST friend std::ostream &operator<<(std::ostream &os, const ModInt &x) { return os << x.val; }
    MDCONST ModInt pow(lint n) const {
        ModInt ans = 1, tmp = *this;
        while (n) {
            if (n & 1) ans *= tmp;
            tmp *= tmp, n >>= 1;
        }
        return ans;
    }

    static std::vector<ModInt> facs, facinvs, invs;
    MDCONST static void _precalculation(int N) {
        int l0 = facs.size();
        if (N > md) N = md;
        if (N <= l0) return;
        facs.resize(N), facinvs.resize(N), invs.resize(N);
        for (int i = l0; i < N; i++) facs[i] = facs[i - 1] * i;
        facinvs[N - 1] = facs.back().pow(md - 2);
        for (int i = N - 2; i >= l0; i--) facinvs[i] = facinvs[i + 1] * (i + 1);
        for (int i = N - 1; i >= l0; i--) invs[i] = facinvs[i] * facs[i - 1];
    }
    MDCONST lint inv() const {
        if (this->val < std::min(md >> 1, 1 << 21)) {
            while (this->val >= int(facs.size())) _precalculation(facs.size() * 2);
            return invs[this->val].val;
        } else {
            return this->pow(md - 2).val;
        }
    }
    MDCONST ModInt fac() const {
        while (this->val >= int(facs.size())) _precalculation(facs.size() * 2);
        return facs[this->val];
    }
    MDCONST ModInt facinv() const {
        while (this->val >= int(facs.size())) _precalculation(facs.size() * 2);
        return facinvs[this->val];
    }
    MDCONST ModInt doublefac() const {
        lint k = (this->val + 1) / 2;
        return (this->val & 1) ? ModInt(k * 2).fac() / (ModInt(2).pow(k) * ModInt(k).fac())
                               : ModInt(k).fac() * ModInt(2).pow(k);
    }
    MDCONST ModInt nCr(const ModInt &r) const {
        return (this->val < r.val) ? 0 : this->fac() * (*this - r).facinv() * r.facinv();
    }
    MDCONST ModInt nPr(const ModInt &r) const {
        return (this->val < r.val) ? 0 : this->fac() * (*this - r).facinv();
    }

    ModInt sqrt() const {
        if (val == 0) return 0;
        if (md == 2) return val;
        if (pow((md - 1) / 2) != 1) return 0;
        ModInt b = 1;
        while (b.pow((md - 1) / 2) == 1) b += 1;
        int e = 0, m = md - 1;
        while (m % 2 == 0) m >>= 1, e++;
        ModInt x = pow((m - 1) / 2), y = (*this) * x * x;
        x *= (*this);
        ModInt z = b.pow(m);
        while (y != 1) {
            int j = 0;
            ModInt t = y;
            while (t != 1) j++, t *= t;
            z = z.pow(1LL << (e - j - 1));
            x *= z, z *= z, y *= z;
            e = j;
        }
        return ModInt(std::min(x.val, md - x.val));
    }
};
template <int md> std::vector<ModInt<md>> ModInt<md>::facs = {1};
template <int md> std::vector<ModInt<md>> ModInt<md>::facinvs = {1};
template <int md> std::vector<ModInt<md>> ModInt<md>::invs = {0};
using mint = ModInt<998244353>;




template <int LEN, class S, S (*op)(S, S), class F, S (*reversal)(S), S (*mapping)(F, S), F (*composition)(F, F), F (*id)()>
struct lazy_rbst {
    

    inline uint32_t _rand() { 

        static uint32_t x = 123456789, y = 362436069, z = 521288629, w = 88675123;
        uint32_t t = x ^ (x << 11);
        x = y;
        y = z;
        z = w;
        return w = (w ^ (w >> 19)) ^ (t ^ (t >> 8));
    }

    struct Node {
        Node *l, *r;
        S val, sum;
        F lz;
        bool is_reversed;
        int sz;
        Node(const S &v) : l(nullptr), r(nullptr), val(v), sum(v), lz(id()), is_reversed(false), sz(1) {}
        Node() : l(nullptr), r(nullptr), lz(id()), is_reversed(false), sz(0) {}
        template <class OStream> friend OStream &operator<<(OStream &os, const Node &n) {
            os << '[';
            if (n.l) os << *(n.l) << ',';
            os << n.val << ',';
            if (n.r) os << *(n.r);
            return os << ']';
        }
    };
    using Nptr = Node *;
    std::array<Node, LEN> data;
    int d_ptr;

    int size(Nptr t) const { return t != nullptr ? t->sz : 0; }

    lazy_rbst() : d_ptr(0) {}

protected:
    Nptr update(Nptr t) {
        t->sz = 1;
        t->sum = t->val;
        if (t->l) {
            t->sz += t->l->sz;
            t->sum = op(t->l->sum, t->sum);
        }
        if (t->r) {
            t->sz += t->r->sz;
            t->sum = op(t->sum, t->r->sum);
        }
        return t;
    }

    void all_apply(Nptr t, F f) {
        t->val = mapping(f, t->val);
        t->sum = mapping(f, t->sum);
        t->lz = composition(f, t->lz);
    }
    void _toggle(Nptr t) {
        auto tmp = t->l;
        t->l = t->r, t->r = tmp;
        t->sum = reversal(t->sum);
        t->is_reversed ^= true;
    }

    void push(Nptr &t) {
        _duplicate_node(t);
        if (t->lz != id()) {
            if (t->l) {
                _duplicate_node(t->l);
                all_apply(t->l, t->lz);
            }
            if (t->r) {
                _duplicate_node(t->r);
                all_apply(t->r, t->lz);
            }
            t->lz = id();
        }
        if (t->is_reversed) {
            if (t->l) _toggle(t->l);
            if (t->r) _toggle(t->r);
            t->is_reversed = false;
        }
    }

    virtual void _duplicate_node(Nptr &) {}

    Nptr _make_node(const S &val) {
        if (d_ptr >= LEN) throw;
        return &(data[d_ptr++] = Node(val));
    }

public:
    Nptr new_tree() { return nullptr; } 


    int mem_used() const { return d_ptr; }
    bool empty(Nptr t) const { return t == nullptr; }

    

    Nptr merge(Nptr l, Nptr r) {
        if (l == nullptr or r == nullptr) return l != nullptr ? l : r;
        if (_rand() % uint32_t(l->sz + r->sz) < uint32_t(l->sz)) {
            push(l);
            l->r = merge(l->r, r);
            return update(l);
        } else {
            push(r);
            r->l = merge(l, r->l);
            return update(r);
        }
    }

    

    

    std::pair<Nptr, Nptr> split(Nptr &root, int k) { 

        if (root == nullptr) return std::make_pair(nullptr, nullptr);
        push(root);
        if (k <= size(root->l)) { 

            auto p = split(root->l, k);
            root->l = p.second;
            return std::make_pair(p.first, update(root));
        } else {
            auto p = split(root->r, k - size(root->l) - 1);
            root->r = p.first;
            return std::make_pair(update(root), p.second);
        }
    }

    

    void insert(Nptr &root, int pos, const S &x) {
        auto p = split(root, pos);
        root = merge(p.first, merge(_make_node(x), p.second));
    }

    

    void erase(Nptr &root, int pos) {
        auto p = split(root, pos);
        auto p2 = split(p.second, 1);
        root = merge(p.first, p2.second);
    }

    

    void set(Nptr &root, int pos, const S &x) {
        auto p = split(root, pos);
        auto p2 = split(p.second, 1);
        _duplicate_node(p2.first);
        *p2.first = Node(x);
        root = merge(p.first, merge(p2.first, p2.second));
    }

    

    void apply(Nptr &root, int l, int r, const F &f) {
        auto p = split(root, l);
        auto p2 = split(p.second, r - l);
        all_apply(p2.first, f);
        root = merge(p.first, merge(p2.first, p2.second));
    }

    

    S prod(Nptr &root, int l, int r) {
        auto p = split(root, l);
        auto p2 = split(p.second, r - l);
        if (p2.first != nullptr) push(p2.first);
        S res = p2.first->sum;
        root = merge(p.first, merge(p2.first, p2.second));
        return res;
    }

    S get(Nptr &root, int pos) { return prod(root, pos, pos + 1); }

    void reverse(Nptr &root) { _duplicate_node(root), _toggle(root); }
    void reverse(Nptr &root, int l, int r) {
        auto p2 = split(root, r);
        auto p1 = split(p2.first, l);
        reverse(p1.second);
        root = merge(merge(p1.first, p1.second), p2.second);
    }

    

    void assign(Nptr &root, const std::vector<S> &init) {
        d_ptr = 0;
        int N = init.size();
        root = N ? _assign_range(0, N, init) : new_tree();
    }
    Nptr _assign_range(int l, int r, const std::vector<S> &init) {
        if (r - l == 1) {
            Nptr t = _make_node(init[l]);
            return update(t);
        }
        return merge(_assign_range(l, (l + r) / 2, init), _assign_range((l + r) / 2, r, init));
    }

    

    void dump(Nptr &t, std::vector<S> &vec) {
        if (t == nullptr) return;
        push(t);
        dump(t->l, vec);
        vec.push_back(t->val);
        dump(t->r, vec);
    }

    

    void re_alloc(Nptr &root) {
        std::vector<S> mem;
        dump(root, mem);
        assign(root, mem);
    }
};

using S = int;
S op(S l, S r) { return l > r ? l : r; }
using F = pair<bool, int>;
S reversal(S x) { return x; }
S mapping(F f, S x) { return f.first ? f.second + x : x; }
F composition(F f, F g) {
    if (!f.first) return g;
    if (!g.first) return f;
    return {true, f.second + g.second};
}
F id() { return {false, 0}; }

lazy_rbst<2000000, S, op, F, reversal, mapping, composition, id> tree;
mint solve() {
    int N, M;
    cin >> N >> M;
    vector<pint> xy(M);
    for (auto &[x, y] : xy) cin >> x >> y;
    auto root = tree.new_tree();
    tree.assign(root, {0});
    for (auto [x, y] : xy) {
        const int len = root->sz;
        int lo = 1, hi = len + 1;
        while (hi - lo > 1) {
            int c = (lo + hi) / 2;
            (tree.prod(root, 0, c) < y - 1 ? lo : hi) = c;
        }
        if (lo == len) {
            tree.insert(root, len, y);
        } else if (tree.get(root, lo) == y - 1) {
            tree.apply(root, lo, len, {true, 1});
        } else {
            tree.apply(root, lo, len, {true, 1});
            tree.insert(root, lo, y);
        }
    }
    int sz = root->sz;
    if (tree.get(root, 0) == 0) sz--;
    sz = N - 1 - sz;
    return mint(N + sz).nCr(sz);
}

int main() {
    int T;
    cin >> T;
    while (T--) cout << solve() << '\n';
}
