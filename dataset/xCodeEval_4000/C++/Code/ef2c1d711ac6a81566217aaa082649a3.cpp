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
template <class T1, class T2> T1 floor_div(T1 num, T2 den) { return (num > 0 ? num / den : -((-num + den - 1) / den)); }
template <class T1, class T2> std::pair<T1, T2> operator+(const std::pair<T1, T2> &l, const std::pair<T1, T2> &r) { return std::make_pair(l.first + r.first, l.second + r.second); }
template <class T1, class T2> std::pair<T1, T2> operator-(const std::pair<T1, T2> &l, const std::pair<T1, T2> &r) { return std::make_pair(l.first - r.first, l.second - r.second); }
template <class T> std::vector<T> sort_unique(std::vector<T> vec) { sort(vec.begin(), vec.end()), vec.erase(unique(vec.begin(), vec.end()), vec.end()); return vec; }
template <class T> int arglb(const std::vector<T> &v, const T &x) { return std::distance(v.begin(), std::lower_bound(v.begin(), v.end(), x)); }
template <class T> int argub(const std::vector<T> &v, const T &x) { return std::distance(v.begin(), std::upper_bound(v.begin(), v.end(), x)); }
template <class IStream, class T> IStream &operator>>(IStream &is, std::vector<T> &vec) { for (auto &v : vec) is >> v; return is; }

template <class OStream, class T> OStream &operator<<(OStream &os, const std::vector<T> &vec);
template <class OStream, class T, size_t sz> OStream &operator<<(OStream &os, const std::array<T, sz> &arr);
template <class OStream, class T, class TH> OStream &operator<<(OStream &os, const std::unordered_set<T, TH> &vec);
template <class OStream, class T, class U> OStream &operator<<(OStream &os, const pair<T, U> &pa);
template <class OStream, class T> OStream &operator<<(OStream &os, const std::deque<T> &vec);
template <class OStream, class T> OStream &operator<<(OStream &os, const std::set<T> &vec);
template <class OStream, class T> OStream &operator<<(OStream &os, const std::multiset<T> &vec);
template <class OStream, class T> OStream &operator<<(OStream &os, const std::unordered_multiset<T> &vec);
template <class OStream, class T, class U> OStream &operator<<(OStream &os, const std::pair<T, U> &pa);
template <class OStream, class TK, class TV> OStream &operator<<(OStream &os, const std::map<TK, TV> &mp);
template <class OStream, class TK, class TV, class TH> OStream &operator<<(OStream &os, const std::unordered_map<TK, TV, TH> &mp);
template <class OStream, class... T> OStream &operator<<(OStream &os, const std::tuple<T...> &tpl);

template <class OStream, class T> OStream &operator<<(OStream &os, const std::vector<T> &vec) { os << '['; for (auto v : vec) os << v << ','; os << ']'; return os; }
template <class OStream, class T, size_t sz> OStream &operator<<(OStream &os, const std::array<T, sz> &arr) { os << '['; for (auto v : arr) os << v << ','; os << ']'; return os; }
#if __cplusplus >= 201703L
template <class... T> std::istream &operator>>(std::istream &is, std::tuple<T...> &tpl) { std::apply([&is](auto &&... args) { ((is >> args), ...);}, tpl); return is; }
template <class OStream, class... T> OStream &operator<<(OStream &os, const std::tuple<T...> &tpl) { os << '('; std::apply([&os](auto &&... args) { ((os << args << ','), ...);}, tpl); return os << ')'; }
#endif
template <class OStream, class T, class TH> OStream &operator<<(OStream &os, const std::unordered_set<T, TH> &vec) { os << '{'; for (auto v : vec) os << v << ','; os << '}'; return os; }
template <class OStream, class T> OStream &operator<<(OStream &os, const std::deque<T> &vec) { os << "deq["; for (auto v : vec) os << v << ','; os << ']'; return os; }
template <class OStream, class T> OStream &operator<<(OStream &os, const std::set<T> &vec) { os << '{'; for (auto v : vec) os << v << ','; os << '}'; return os; }
template <class OStream, class T> OStream &operator<<(OStream &os, const std::multiset<T> &vec) { os << '{'; for (auto v : vec) os << v << ','; os << '}'; return os; }
template <class OStream, class T> OStream &operator<<(OStream &os, const std::unordered_multiset<T> &vec) { os << '{'; for (auto v : vec) os << v << ','; os << '}'; return os; }
template <class OStream, class T, class U> OStream &operator<<(OStream &os, const std::pair<T, U> &pa) { return os << '(' << pa.first << ',' << pa.second << ')'; }
template <class OStream, class TK, class TV> OStream &operator<<(OStream &os, const std::map<TK, TV> &mp) { os << '{'; for (auto v : mp) os << v.first << "=>" << v.second << ','; os << '}'; return os; }
template <class OStream, class TK, class TV, class TH> OStream &operator<<(OStream &os, const std::unordered_map<TK, TV, TH> &mp) { os << '{'; for (auto v : mp) os << v.first << "=>" << v.second << ','; os << '}'; return os; }
#ifdef HITONANODE_LOCAL
const string COLOR_RESET = "\033[0m", BRIGHT_GREEN = "\033[1;32m", BRIGHT_RED = "\033[1;31m", BRIGHT_CYAN = "\033[1;36m", NORMAL_CROSSED = "\033[0;9;37m", RED_BACKGROUND = "\033[1;41m", NORMAL_FAINT = "\033[0;2m";
#define dbg(x) std::cerr << BRIGHT_CYAN << #x << COLOR_RESET << " = " << (x) << NORMAL_FAINT << " (L" << __LINE__ << ") " << __FILE__ << COLOR_RESET << std::endl
#define dbgif(cond, x) ((cond) ? std::cerr << BRIGHT_CYAN << #x << COLOR_RESET << " = " << (x) << NORMAL_FAINT << " (L" << __LINE__ << ") " << __FILE__ << COLOR_RESET << std::endl : std::cerr)
#else
#define dbg(x) ((void)0)
#define dbgif(cond, x) ((void)0)
#endif

struct rand_int_ {
    using lint = long long;
    std::mt19937 mt;
    rand_int_() : mt(std::chrono::steady_clock::now().time_since_epoch().count()) {}
    lint operator()(lint x) { return this->operator()(0, x); } 

    lint operator()(lint l, lint r) {
        std::uniform_int_distribution<lint> d(l, r - 1);
        return d(mt);
    }
} rnd;



template <class T> struct BIT {
    int n;
    std::vector<T> data;
    BIT(int len = 0) : n(len), data(len) {}
    void reset() { std::fill(data.begin(), data.end(), T(0)); }
    void add(int pos, T v) { 

        pos++;
        while (pos > 0 and pos <= n) data[pos - 1] += v, pos += pos & -pos;
    }
    T sum(int k) const { 

        T res = 0;
        while (k > 0) res += data[k - 1], k -= k & -k;
        return res;
    }

    T sum(int l, int r) const { return sum(r) - sum(l); } 


    template <class OStream> friend OStream &operator<<(OStream &os, const BIT &bit) {
        T prv = 0;
        os << '[';
        for (int i = 1; i <= bit.n; i++) {
            T now = bit.sum(i);
            os << now - prv << ',', prv = now;
        }
        return os << ']';
    }
};

#ifndef ATCODER_INTERNAL_BITOP_HPP
#define ATCODER_INTERNAL_BITOP_HPP 1

#ifdef _MSC_VER
#include <intrin.h>
#endif

namespace atcoder {

namespace internal {





int ceil_pow2(int n) {
    int x = 0;
    while ((1U << x) < (unsigned int)(n)) x++;
    return x;
}





int bsf(unsigned int n) {
#ifdef _MSC_VER
    unsigned long index;
    _BitScanForward(&index, n);
    return index;
#else
    return __builtin_ctz(n);
#endif
}

} 


} 


#endif 


#ifndef ATCODER_SEGTREE_HPP
#define ATCODER_SEGTREE_HPP 1

#include <algorithm>
#include <cassert>
#include <vector>




namespace atcoder {

template <class S, S (*op)(S, S), S (*e)()> struct segtree {
public:
    segtree() : segtree(0) {}
    explicit segtree(int n) : segtree(std::vector<S>(n, e())) {}
    explicit segtree(const std::vector<S> &v) : _n(int(v.size())) {
        log = internal::ceil_pow2(_n);
        size = 1 << log;
        d = std::vector<S>(2 * size, e());
        for (int i = 0; i < _n; i++) d[size + i] = v[i];
        for (int i = size - 1; i >= 1; i--) { update(i); }
    }

    void set(int p, S x) {
        assert(0 <= p && p < _n);
        p += size;
        d[p] = x;
        for (int i = 1; i <= log; i++) update(p >> i);
    }

    S get(int p) const {
        assert(0 <= p && p < _n);
        return d[p + size];
    }

    S prod(int l, int r) const {
        assert(0 <= l && l <= r && r <= _n);
        S sml = e(), smr = e();
        l += size;
        r += size;

        while (l < r) {
            if (l & 1) sml = op(sml, d[l++]);
            if (r & 1) smr = op(d[--r], smr);
            l >>= 1;
            r >>= 1;
        }
        return op(sml, smr);
    }

    S all_prod() const { return d[1]; }

    template <bool (*f)(S)> int max_right(int l) const {
        return max_right(l, [](S x) { return f(x); });
    }
    template <class F> int max_right(int l, F f) const {
        assert(0 <= l && l <= _n);
        assert(f(e()));
        if (l == _n) return _n;
        l += size;
        S sm = e();
        do {
            while (l % 2 == 0) l >>= 1;
            if (!f(op(sm, d[l]))) {
                while (l < size) {
                    l = (2 * l);
                    if (f(op(sm, d[l]))) {
                        sm = op(sm, d[l]);
                        l++;
                    }
                }
                return l - size;
            }
            sm = op(sm, d[l]);
            l++;
        } while ((l & -l) != l);
        return _n;
    }

    template <bool (*f)(S)> int min_left(int r) const {
        return min_left(r, [](S x) { return f(x); });
    }
    template <class F> int min_left(int r, F f) const {
        assert(0 <= r && r <= _n);
        assert(f(e()));
        if (r == 0) return 0;
        r += size;
        S sm = e();
        do {
            r--;
            while (r > 1 && (r % 2)) r >>= 1;
            if (!f(op(d[r], sm))) {
                while (r < size) {
                    r = (2 * r + 1);
                    if (f(op(d[r], sm))) {
                        sm = op(d[r], sm);
                        r--;
                    }
                }
                return r + 1 - size;
            }
            sm = op(d[r], sm);
        } while ((r & -r) != r);
        return 0;
    }

private:
    int _n, size, log;
    std::vector<S> d;

    void update(int k) { d[k] = op(d[2 * k], d[2 * k + 1]); }
};

} 


#endif 






lint op(lint l, lint r) { return l ^ r; }
lint e() { return 0; }

int main() {

    

    

    

    

    

    auto START = std::chrono::system_clock::now();

    int N, Q;
    cin >> N >> Q;
    vector<int> A(N);
    cin >> A;

    vector<int> zs = A;

    vector<tuple<int, int, int, int>> qs;

    vector<int> ret;
    REP(q, Q) {
        int tp;
        cin >> tp;
        if (tp == 1) {
            int i, x;
            cin >> i >> x;
            --i;
            qs.emplace_back(tp, i, x, -1);
            zs.push_back(x);
        } else {
            int l, r, k;
            cin >> l >> r >> k;
            --l;
            qs.emplace_back(tp, l, r, k);
            ret.push_back((r - l) % k == 0);
        }
    }
    zs = sort_unique(zs);

    const int D = zs.size();

    for (auto &a : A) a = arglb(zs, a);

    for(auto &[tp, i, x, minus1] : qs) {
        if (tp == 1) x = arglb(zs, x);
    }

    vector<lint> vec(N);
    vector<lint> hash(D);

    {
        for (auto &x : hash) x = rnd(0, 1e12);
        REP(i, N) vec[i] = hash[A[i]];
        atcoder::segtree<lint, op, e> tree(vec);
        int qid = 0;
        for (auto [tp, l, r, k] : qs) {
            if (tp == 1) {
                int i = l, x = r;
                auto diff = hash[x] - vec[i];
                vec[i] += diff;
                tree.set(i, vec[i]);
            } else {
                if (tp == 2 and k == 2) {
                    auto sum = tree.prod(l, r);
                    if (sum) chmin(ret[qid], 0);
                }
                ++qid;
            }
        }
    }

    REP(_, 100) {
        int64_t spent_ms = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now() - START).count();
        if (spent_ms > 2800) break;

        for (auto &x : hash) x = rnd(0, 1e12);
        REP(i, N) vec[i] = hash[A[i]];

        BIT<lint> bit(N);
        REP(i, N) bit.add(i, vec[i]);

        int qid = 0;
        for (auto [tp, l, r, k] : qs) {
            if (tp == 1) {
                int i = l, x = r;
                auto diff = hash[x] - vec[i];
                vec[i] += diff;
                bit.add(i, diff);
            } else {
                auto sum = bit.sum(l, r);
                if (sum % k != 0) {
                    chmin(ret[qid], 0);
                }
                ++qid;
            }
        }
    }

    for (auto x : ret) cout << (x ? "YES" : "NO") << '\n';
}
