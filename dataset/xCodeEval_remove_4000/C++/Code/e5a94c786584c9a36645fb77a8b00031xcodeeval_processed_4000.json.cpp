





























using namespace std;
using lint = long long;
using pint = pair<int, int>;
using plint = pair<lint, lint>;
struct fast_ios { fast_ios(){ cin.tie(nullptr), ios::sync_with_stdio(false), cout << fixed << setprecision(20); }; } id0;





template <typename T, typename V>
void ndarray(vector<T>& vec, const V& val, int len) { vec.assign(len, val); }
template <typename T, typename V, typename... Args> void ndarray(vector<T>& vec, const V& val, int len, Args... args) { vec.resize(len), for_each(begin(vec), end(vec), [&](T& v) { ndarray(v, val, args...); }); }
template <typename T> bool chmax(T &m, const T q) { return m < q ? (m = q, true) : false; }
template <typename T> bool chmin(T &m, const T q) { return m > q ? (m = q, true) : false; }
int id5(long long x) { return x <= 0 ? -1 : 63 - __builtin_clzll(x); }
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

template <class... T> std::istream &operator>>(std::istream &is, std::tuple<T...> &tpl) { std::apply([&is](auto &&... args) { ((is >> args), ...);}, tpl); return is; }
template <class OStream, class... T> OStream &operator<<(OStream &os, const std::tuple<T...> &tpl) { os << '('; std::apply([&os](auto &&... args) { ((os << args << ','), ...);}, tpl); return os << ')'; }

template <class OStream, class T, class TH> OStream &operator<<(OStream &os, const std::unordered_set<T, TH> &vec) { os << '{'; for (auto v : vec) os << v << ','; os << '}'; return os; }
template <class OStream, class T> OStream &operator<<(OStream &os, const std::deque<T> &vec) { os << "deq["; for (auto v : vec) os << v << ','; os << ']'; return os; }
template <class OStream, class T> OStream &operator<<(OStream &os, const std::set<T> &vec) { os << '{'; for (auto v : vec) os << v << ','; os << '}'; return os; }
template <class OStream, class T> OStream &operator<<(OStream &os, const std::multiset<T> &vec) { os << '{'; for (auto v : vec) os << v << ','; os << '}'; return os; }
template <class OStream, class T> OStream &operator<<(OStream &os, const std::unordered_multiset<T> &vec) { os << '{'; for (auto v : vec) os << v << ','; os << '}'; return os; }
template <class OStream, class T, class U> OStream &operator<<(OStream &os, const std::pair<T, U> &pa) { return os << '(' << pa.first << ',' << pa.second << ')'; }
template <class OStream, class TK, class TV> OStream &operator<<(OStream &os, const std::map<TK, TV> &mp) { os << '{'; for (auto v : mp) os << v.first << "=>" << v.second << ','; os << '}'; return os; }
template <class OStream, class TK, class TV, class TH> OStream &operator<<(OStream &os, const std::unordered_map<TK, TV, TH> &mp) { os << '{'; for (auto v : mp) os << v.first << "=>" << v.second << ','; os << '}'; return os; }

const string COLOR_RESET = "\033[0m", id7 = "\033[1;32m", id8 = "\033[1;31m", id6 = "\033[1;36m", id2 = "\033[0;9;37m", RED_BACKGROUND = "\033[1;41m", id4 = "\033[0;2m";














namespace atcoder {

namespace internal {





int id3(int n) {
    int x = 0;
    while ((1U << x) < (unsigned int)(n)) x++;
    return x;
}





int bsf(unsigned int n) {

    unsigned long index;
    _BitScanForward(&index, n);
    return index;

    return __builtin_ctz(n);

}

} 


} 















namespace atcoder {

template <class S, S (*op)(S, S), S (*e)(), class F, S (*mapping)(F, S), F (*composition)(F, F),
          F (*id)()>
struct id9 {
public:
    id9() : id9(0) {}
    explicit id9(int n) : id9(std::vector<S>(n, e())) {}
    explicit id9(const std::vector<S> &v) : _n(int(v.size())) {
        log = internal::id3(_n);
        size = 1 << log;
        d = std::vector<S>(2 * size, e());
        lz = std::vector<F>(size, id());
        for (int i = 0; i < _n; i++) d[size + i] = v[i];
        for (int i = size - 1; i >= 1; i--) { update(i); }
    }

    void set(int p, S x) {
        assert(0 <= p && p < _n);
        p += size;
        for (int i = log; i >= 1; i--) push(p >> i);
        d[p] = x;
        for (int i = 1; i <= log; i++) update(p >> i);
    }

    S get(int p) const {
        assert(0 <= p && p < _n);
        p += size;
        for (int i = log; i >= 1; i--) push(p >> i);
        return d[p];
    }

    S prod(int l, int r) const {
        assert(0 <= l && l <= r && r <= _n);
        if (l == r) return e();

        l += size;
        r += size;

        for (int i = log; i >= 1; i--) {
            if (((l >> i) << i) != l) push(l >> i);
            if (((r >> i) << i) != r) push((r - 1) >> i);
        }

        S sml = e(), smr = e();
        while (l < r) {
            if (l & 1) sml = op(sml, d[l++]);
            if (r & 1) smr = op(d[--r], smr);
            l >>= 1;
            r >>= 1;
        }

        return op(sml, smr);
    }

    S all_prod() const { return d[1]; }

    void apply(int p, F f) {
        assert(0 <= p && p < _n);
        p += size;
        for (int i = log; i >= 1; i--) push(p >> i);
        d[p] = mapping(f, d[p]);
        for (int i = 1; i <= log; i++) update(p >> i);
    }
    void apply(int l, int r, F f) {
        assert(0 <= l && l <= r && r <= _n);
        if (l == r) return;

        l += size;
        r += size;

        for (int i = log; i >= 1; i--) {
            if (((l >> i) << i) != l) push(l >> i);
            if (((r >> i) << i) != r) push((r - 1) >> i);
        }

        {
            int l2 = l, r2 = r;
            while (l < r) {
                if (l & 1) all_apply(l++, f);
                if (r & 1) all_apply(--r, f);
                l >>= 1;
                r >>= 1;
            }
            l = l2;
            r = r2;
        }

        for (int i = 1; i <= log; i++) {
            if (((l >> i) << i) != l) update(l >> i);
            if (((r >> i) << i) != r) update((r - 1) >> i);
        }
    }

    template <bool (*g)(S)> int max_right(int l) const {
        return max_right(l, [](S x) { return g(x); });
    }
    template <class G> int max_right(int l, G g) const {
        assert(0 <= l && l <= _n);
        assert(g(e()));
        if (l == _n) return _n;
        l += size;
        for (int i = log; i >= 1; i--) push(l >> i);
        S sm = e();
        do {
            while (l % 2 == 0) l >>= 1;
            if (!g(op(sm, d[l]))) {
                while (l < size) {
                    push(l);
                    l = (2 * l);
                    if (g(op(sm, d[l]))) {
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

    template <bool (*g)(S)> int min_left(int r) const {
        return min_left(r, [](S x) { return g(x); });
    }
    template <class G> int min_left(int r, G g) const {
        assert(0 <= r && r <= _n);
        assert(g(e()));
        if (r == 0) return 0;
        r += size;
        for (int i = log; i >= 1; i--) push((r - 1) >> i);
        S sm = e();
        do {
            r--;
            while (r > 1 && (r % 2)) r >>= 1;
            if (!g(op(d[r], sm))) {
                while (r < size) {
                    push(r);
                    r = (2 * r + 1);
                    if (g(op(d[r], sm))) {
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

protected:
    int _n, size, log;
    mutable std::vector<S> d;
    mutable std::vector<F> lz;

    void update(int k) const { d[k] = op(d[2 * k], d[2 * k + 1]); }
    virtual void all_apply(int k, F f) const {
        d[k] = mapping(f, d[k]);
        if (k < size) lz[k] = composition(f, lz[k]);
    }
    void push(int k) const {
        all_apply(2 * k, lz[k]);
        all_apply(2 * k + 1, lz[k]);
        lz[k] = id();
    }
};
} 















lint op(lint l, lint r) { return min(l, r); }
constexpr lint INF = 1LL << 60;
lint e() { return INF; }
using F = lint;
lint mapping(lint f, lint x) { return (f != INF ? f : x); }
F id() { return INF; }
F composition(F f, F g) { return f == id() ? g : f; }

vector<plint> merge_ranges(vector<plint> id1) {
    sort(ALL(id1));
    vector<plint> optimals;
    for (auto [l, r] : id1) {
        if (optimals.size() and optimals.back().second >= l) {
            chmax(optimals.back().second, r);
        } else {
            optimals.emplace_back(l, r);
        }
    }
    return optimals;
}

int main() {
    int N;
    lint T;
    cin >> N >> T;

    auto normalize = [&](plint x) -> vector<plint> {
        lint l = x.first, r = x.second;
        while (l >= T) l -= T, r -= T;
        while (l < 0) l += T, r += T;
        vector<plint> ret;
        if (r >= T) {
            ret.emplace_back(l, T);
            if (r - T > 0) ret.emplace_back(0, r - T);
        } else {
            if (l < r) ret.emplace_back(l, r);
        }
        return ret;
    };

    auto intersect = [&](plint a, plint b) -> plint {
        lint l = max(a.first, b.first);
        lint r = min(a.second, b.second);
        return plint(l, r);
    };

    auto shift = [&](plint range, lint val) -> vector<plint> {
        lint l = range.first + val, r = range.second + val;
        if (l >= T) {
            return {plint(l - T, r - T)};
        } else if (r <= T) {
            return {plint(l, r)};
        } else {
            vector<plint> ret;
            if (r - T > 0) ret.emplace_back(0, r - T);
            if (l < T) ret.emplace_back(l, T);
            return ret;
        }
    };

    vector<lint> G(N), C(N);
    REP(i, N) cin >> G[i] >> C[i];
    vector<lint> D(N - 1);
    cin >> D;
    vector<lint> Dcs(N);
    REP(i, D.size()) Dcs[i + 1] = (Dcs[i] + D[i]) % T;
    dbg(D);
    dbg(Dcs);

    REP(i, N) C[i] = (C[i] + Dcs[i]) % T;

    vector<lint> zs{0, T};

    REP(i, N) {
        lint gs = -C.at(i) + T, gt = gs + G.at(i);
        auto wins = normalize(plint(gs, gt));
        for (auto [a, b] : wins) {
            zs.push_back(a);
            zs.push_back(b);
            zs.push_back((b + T - 1) % T);
        }
    }
    zs = sort_unique(zs);
    vector<lint> init;
    for (auto x : zs) init.push_back(-x);
    init.back() = INF - 1;
    atcoder::id9<lint, op, e, F, mapping, composition, id> tree(init);

    REP(i, N) {
        lint gs = -C.at(i) + T, gt = gs + G.at(i);
        auto wins = normalize(plint(gs, gt));
        sort(ALL(wins));
        dbg(make_tuple(gs, gt, wins));
        
        vector<plint> updator;

        for (auto [a, b] : wins) {
            int ia = arglb(zs, a);
            int ib = arglb(zs, b);
            updator.emplace_back(ia, tree.prod(0, ia + 1) + a - a);
            updator.emplace_back(ia, tree.prod(ia, zs.size()) + a + T - a);
        }

        dbg(updator);

        int l = 0;
        for (auto [a, b] : wins) {
            int ia = arglb(zs, a);
            int ib = arglb(zs, b);
            if (l < ia) tree.apply(l, ia, INF - 1);
            l = ib;
        }
        if (l < zs.size()) tree.apply(l, zs.size(), INF - 1);

        {
            

            

            

        }

        for (auto [i, v] : updator) {
            if (tree.get(i) > v) tree.set(i, v);
        }

        {
            

            

            

        }
    }

    lint ret = INF;
    REP(i, zs.size()) chmin(ret, tree.get(i) + zs.at(i));
    cout << ret + accumulate(ALL(D), 0LL) << endl;
}
