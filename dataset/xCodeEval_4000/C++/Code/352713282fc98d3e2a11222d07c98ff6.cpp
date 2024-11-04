#include <bits/stdc++.h>
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
template <typename T> bool chmax(T &m, const T q) { if (m < q) {m = q; return true;} else return false; }
template <typename T> bool chmin(T &m, const T q) { if (m > q) {m = q; return true;} else return false; }
template <typename T1, typename T2> pair<T1, T2> operator+(const pair<T1, T2> &l, const pair<T1, T2> &r) { return make_pair(l.first + r.first, l.second + r.second); }
template <typename T1, typename T2> pair<T1, T2> operator-(const pair<T1, T2> &l, const pair<T1, T2> &r) { return make_pair(l.first - r.first, l.second - r.second); }
template <typename T> vector<T> srtunq(vector<T> vec) { sort(vec.begin(), vec.end()), vec.erase(unique(vec.begin(), vec.end()), vec.end()); return vec; }
template <typename T> istream &operator>>(istream &is, vector<T> &vec) { for (auto &v : vec) is >> v; return is; }
template <typename T> ostream &operator<<(ostream &os, const vector<T> &vec) { os << '['; for (auto v : vec) os << v << ','; os << ']'; return os; }
#if __cplusplus >= 201703L
template <typename... T> istream &operator>>(istream &is, tuple<T...> &tpl) { std::apply([&is](auto &&... args) { ((is >> args), ...);}, tpl); return is; }
template <typename... T> ostream &operator<<(ostream &os, const tuple<T...> &tpl) { std::apply([&os](auto &&... args) { ((os << args << ','), ...);}, tpl); return os; }
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
#define dbg(x) (cerr << #x << " = " << (x) << " (L" << __LINE__ << ") " << __FILE__ << endl)
#else
#define dbg(x) {}
#endif



namespace radix_heap {
namespace internal {
template<bool Is64bit> class find_bucket_impl;

template<>
class find_bucket_impl<false> {
 public:
  static inline constexpr size_t find_bucket(uint32_t x, uint32_t last) {
    return x == last ? 0 : 32 - __builtin_clz(x ^ last);
  }
};

template<>
class find_bucket_impl<true> {
 public:
  static inline constexpr size_t find_bucket(uint64_t x, uint64_t last) {
    return x == last ? 0 : 64 - __builtin_clzll(x ^ last);
  }
};

template<typename T>
inline constexpr size_t find_bucket(T x, T last) {
  return find_bucket_impl<sizeof(T) == 8>::find_bucket(x, last);
}

template<typename KeyType, bool IsSigned> class encoder_impl_integer;

template<typename KeyType>
class encoder_impl_integer<KeyType, false> {
 public:
  typedef KeyType key_type;
  typedef KeyType unsigned_key_type;

  inline static constexpr unsigned_key_type encode(key_type x) {
    return x;
  }

  inline static constexpr key_type decode(unsigned_key_type x) {
    return x;
  }
};

template<typename KeyType>
class encoder_impl_integer<KeyType, true> {
 public:
  typedef KeyType key_type;
  typedef typename std::make_unsigned<KeyType>::type unsigned_key_type;

  inline static constexpr unsigned_key_type encode(key_type x) {
    return static_cast<unsigned_key_type>(x) ^
        (unsigned_key_type(1) << unsigned_key_type(std::numeric_limits<unsigned_key_type>::digits - 1));
  }

  inline static constexpr key_type decode(unsigned_key_type x) {
    return static_cast<key_type>
        (x ^ (unsigned_key_type(1) << (std::numeric_limits<unsigned_key_type>::digits - 1)));
  }
};

template<typename KeyType, typename UnsignedKeyType>
class encoder_impl_decimal {
public:
  typedef KeyType key_type;
  typedef UnsignedKeyType unsigned_key_type;

  inline static constexpr unsigned_key_type encode(key_type x) {
    return raw_cast<key_type, unsigned_key_type>(x) ^
        ((-(raw_cast<key_type, unsigned_key_type>(x) >> (std::numeric_limits<unsigned_key_type>::digits - 1))) |
         (unsigned_key_type(1) << (std::numeric_limits<unsigned_key_type>::digits - 1)));
  }

  inline static constexpr key_type decode(unsigned_key_type x) {
    return raw_cast<unsigned_key_type, key_type>
        (x ^ (((x >> (std::numeric_limits<unsigned_key_type>::digits - 1)) - 1) |
              (unsigned_key_type(1) << (std::numeric_limits<unsigned_key_type>::digits - 1))));
  }

 private:
  template<typename T, typename U>
  union raw_cast {
   public:
    constexpr raw_cast(T t) : t_(t) {}
    operator U() const { return u_; }

   private:
    T t_;
    U u_;
  };
};

template<typename KeyType>
class encoder : public encoder_impl_integer<KeyType, std::is_signed<KeyType>::value> {};
template<>
class encoder<float> : public encoder_impl_decimal<float, uint32_t> {};
template<>
class encoder<double> : public encoder_impl_decimal<double, uint64_t> {};
}  


template<typename KeyType, typename EncoderType = internal::encoder<KeyType>>
class radix_heap {
 public:
  typedef KeyType key_type;
  typedef EncoderType encoder_type;
  typedef typename encoder_type::unsigned_key_type unsigned_key_type;

  radix_heap() : size_(0), last_(), buckets_() {
    buckets_min_.fill(std::numeric_limits<unsigned_key_type>::max());
  }

  void push(key_type key) {
    const unsigned_key_type x = encoder_type::encode(key);
    assert(last_ <= x);
    ++size_;
    const size_t k = internal::find_bucket(x, last_);
    buckets_[k].emplace_back(x);
    buckets_min_[k] = std::min(buckets_min_[k], x);
  }

  key_type top() {
    pull();
    return encoder_type::decode(last_);
  }

  void pop() {
    pull();
    buckets_[0].pop_back();
    --size_;
  }

  size_t size() const {
    return size_;
  }

  bool empty() const {
    return size_ == 0;
  }

  void clear() {
    size_ = 0;
    last_ = key_type();
    for (auto &b : buckets_) b.clear();
    buckets_min_.fill(std::numeric_limits<unsigned_key_type>::max());
  }

  void swap(radix_heap<KeyType, EncoderType> &a) {
    std::swap(size_, a.size_);
    std::swap(last_, a.last_);
    buckets_.swap(a.buckets_);
    buckets_min_.swap(a.buckets_min_);
  }

 private:
  size_t size_;
  unsigned_key_type last_;
  std::array<std::vector<unsigned_key_type>,
             std::numeric_limits<unsigned_key_type>::digits + 1> buckets_;
  std::array<unsigned_key_type,
             std::numeric_limits<unsigned_key_type>::digits + 1> buckets_min_;

  void pull() {
    assert(size_ > 0);
    if (!buckets_[0].empty()) return;

    size_t i;
    for (i = 1; buckets_[i].empty(); ++i);
    last_ = buckets_min_[i];

    for (unsigned_key_type x : buckets_[i]) {
      const size_t k = internal::find_bucket(x, last_);
      buckets_[k].emplace_back(x);
      buckets_min_[k] = std::min(buckets_min_[k], x);
    }
    buckets_[i].clear();
    buckets_min_[i] = std::numeric_limits<unsigned_key_type>::max();
  }
};

template<typename KeyType, typename ValueType, typename EncoderType = internal::encoder<KeyType>>
class pair_radix_heap {
 public:
  typedef KeyType key_type;
  typedef ValueType value_type;
  typedef EncoderType encoder_type;
  typedef typename encoder_type::unsigned_key_type unsigned_key_type;

  pair_radix_heap() : size_(0), last_(), buckets_() {
    buckets_min_.fill(std::numeric_limits<unsigned_key_type>::max());
  }

  void push(key_type key, const value_type &value) {
    const unsigned_key_type x = encoder_type::encode(key);
    assert(last_ <= x);
    ++size_;
    const size_t k = internal::find_bucket(x, last_);
    buckets_[k].emplace_back(x, value);
    buckets_min_[k] = std::min(buckets_min_[k], x);
  }

  void push(key_type key, value_type &&value) {
    const unsigned_key_type x = encoder_type::encode(key);
    assert(last_ <= x);
    ++size_;
    const size_t k = internal::find_bucket(x, last_);
    buckets_[k].emplace_back(x, std::move(value));
    buckets_min_[k] = std::min(buckets_min_[k], x);
  }

  template <class... Args>
  void emplace(key_type key, Args&&... args) {
    const unsigned_key_type x = encoder_type::encode(key);
    assert(last_ <= x);
    ++size_;
    const size_t k = internal::find_bucket(x, last_);
    buckets_[k].emplace_back(std::piecewise_construct,
                             std::forward_as_tuple(x), std::forward_as_tuple(args...));
    buckets_min_[k] = std::min(buckets_min_[k], x);
  }

  key_type top_key() {
    pull();
    return encoder_type::decode(last_);
  }

  value_type &top_value() {
    pull();
    return buckets_[0].back().second;
  }

  void pop() {
    pull();
    buckets_[0].pop_back();
    --size_;
  }

  size_t size() const {
    return size_;
  }

  bool empty() const {
    return size_ == 0;
  }

  void clear() {
    size_ = 0;
    last_ = key_type();
    for (auto &b : buckets_) b.clear();
    buckets_min_.fill(std::numeric_limits<unsigned_key_type>::max());
  }

  void swap(pair_radix_heap<KeyType, ValueType, EncoderType> &a) {
    std::swap(size_, a.size_);
    std::swap(last_, a.last_);
    buckets_.swap(a.buckets_);
    buckets_min_.swap(a.buckets_min_);
  }

 private:
  size_t size_;
  unsigned_key_type last_;
  std::array<std::vector<std::pair<unsigned_key_type, value_type>>,
             std::numeric_limits<unsigned_key_type>::digits + 1> buckets_;
  std::array<unsigned_key_type,
             std::numeric_limits<unsigned_key_type>::digits + 1> buckets_min_;

  void pull() {
    assert(size_ > 0);
    if (!buckets_[0].empty()) return;

    size_t i;
    for (i = 1; buckets_[i].empty(); ++i);
    last_ = buckets_min_[i];

    for (size_t j = 0; j < buckets_[i].size(); ++j) {
      const unsigned_key_type x = buckets_[i][j].first;
      const size_t k = internal::find_bucket(x, last_);
      buckets_[k].emplace_back(std::move(buckets_[i][j]));
      buckets_min_[k] = std::min(buckets_min_[k], x);
    }
    buckets_[i].clear();
    buckets_min_[i] = std::numeric_limits<unsigned_key_type>::max();
  }
};
}  








template <class Cap, class Cost>
struct mcf_graph {
    mcf_graph() {}
    mcf_graph(int n) : _n(n), g(n) {}

    int add_edge(int from, int to, Cap cap, Cost cost) {
        assert(0 <= from && from < _n);
        assert(0 <= to && to < _n);
        assert(0 <= cap);
        assert(0 <= cost);
        int m = int(pos.size());
        pos.push_back({from, int(g[from].size())});
        int from_id = int(g[from].size());
        int to_id = int(g[to].size());
        if (from == to) to_id++;
        g[from].push_back(_edge{to, to_id, cap, cost});
        g[to].push_back(_edge{from, from_id, 0, -cost});
        return m;
    }

    struct edge {
        int from, to;
        Cap cap, flow;
        Cost cost;
    };

    edge get_edge(int i) {
        int m = int(pos.size());
        assert(0 <= i && i < m);
        auto _e = g[pos[i].first][pos[i].second];
        auto _re = g[_e.to][_e.rev];
        return edge{
            pos[i].first, _e.to, _e.cap + _re.cap, _re.cap, _e.cost,
        };
    }
    std::vector<edge> edges() {
        int m = int(pos.size());
        std::vector<edge> result(m);
        for (int i = 0; i < m; i++) {
            result[i] = get_edge(i);
        }
        return result;
    }

    std::pair<Cap, Cost> flow(int s, int t) {
        return flow(s, t, std::numeric_limits<Cap>::max());
    }
    std::pair<Cap, Cost> flow(int s, int t, Cap flow_limit) {
        return slope(s, t, flow_limit).back();
    }
    std::vector<std::pair<Cap, Cost>> slope(int s, int t) {
        return slope(s, t, std::numeric_limits<Cap>::max());
    }

    std::vector<Cost> dual, dist;
    std::vector<int> pv, pe;
    std::vector<bool> vis;
    bool _dual_ref(int s, int t) {
        std::fill(dist.begin(), dist.end(), std::numeric_limits<Cost>::max());
        std::fill(pv.begin(), pv.end(), -1);
        std::fill(pe.begin(), pe.end(), -1);
        std::fill(vis.begin(), vis.end(), false);
        struct Q {
            Cost key;
            int to;
            bool operator<(Q r) const { return key > r.key; }
            bool operator<=(Q r) const { return key >= r.key; }
        };
        radix_heap::pair_radix_heap<Cost, int> que;
        dist[s] = 0;
        que.push(0, s);
        while (!que.empty()) {
            int v = que.top_value();
            que.pop();
            if (vis[v]) continue;
            vis[v] = true;
            if (v == t) break;
            

            

            

            for (int i = 0; i < int(g[v].size()); i++) {
                auto e = g[v][i];
                if (vis[e.to] || !e.cap) continue;
                

                

                Cost cost = e.cost - dual[e.to] + dual[v];
                if (dist[e.to] - dist[v] > cost) {
                    dist[e.to] = dist[v] + cost;
                    pv[e.to] = v;
                    pe[e.to] = i;
                    que.push(dist[e.to], e.to);
                }
            }
        }
        if (!vis[t]) {
            return false;
        }

        for (int v = 0; v < _n; v++) {
            if (!vis[v]) continue;
            

            

            

            

            dual[v] -= dist[t] - dist[v];
        }
        return true;
    }

    std::vector<std::pair<Cap, Cost>> slope(int s, int t, Cap flow_limit) {
        assert(0 <= s && s < _n);
        assert(0 <= t && t < _n);
        assert(s != t);
        

        

        

        dual.assign(_n, 0), dist.assign(_n, 0);
        pv.assign(_n, 0), pe.assign(_n, 0);
        vis.assign(_n, false);
        Cap flow = 0;
        Cost cost = 0, prev_cost_per_flow = -1;
        std::vector<std::pair<Cap, Cost>> result;
        result.push_back({flow, cost});
        while (flow < flow_limit) {
            if (!_dual_ref(s, t)) break;
            Cap c = flow_limit - flow;
            for (int v = t; v != s; v = pv[v]) {
                c = std::min(c, g[pv[v]][pe[v]].cap);
            }
            for (int v = t; v != s; v = pv[v]) {
                auto& e = g[pv[v]][pe[v]];
                e.cap -= c;
                g[v][e.rev].cap += c;
            }
            Cost d = -dual[s];
            flow += c;
            cost += c * d;
            if (prev_cost_per_flow == d) {
                result.pop_back();
            }
            result.push_back({flow, cost});
            prev_cost_per_flow = d;
        }
        return result;
    }

    struct _edge {
        int to, rev;
        Cap cap;
        Cost cost;
    };

    int _n;
    std::vector<std::pair<int, int>> pos;
    std::vector<std::vector<_edge>> g;
};

template <typename CAP, typename COST>
struct B_Flow
{
    int N, E;
    COST cost_bias;
    bool infeasible;
    mcf_graph<CAP, COST> mcf;
    std::vector<CAP> b;
    std::vector<CAP> fbias;
    std::vector<int> fdir;
    std::vector<CAP> f;
    const std::vector<COST> &potential;

    B_Flow(int N = 0) : N(N), E(0), cost_bias(0), infeasible(false), mcf(N + 2), b(N), potential(mcf.dual) {}

    void add_supply(int v, CAP supply) { b[v] += supply; }
    void add_demand(int v, CAP demand) { b[v] -= demand; }
    void add_edge(int s, int t, CAP lower_cap, CAP upper_cap, COST cost) {
        assert(s >= 0 and s < N);
        assert(t >= 0 and t < N);
        if (lower_cap > upper_cap) {
            infeasible = true;
            return;
        }
        E++;
        if (s == t) {
            if (cost > 0) upper_cap = lower_cap;
            else lower_cap = upper_cap;
        }
        if (cost < 0) {
            fbias.emplace_back(lower_cap);
            fdir.emplace_back(-1);
            cost_bias += cost * upper_cap;
            b[s] -= upper_cap;
            b[t] += upper_cap;
            mcf.add_edge(t, s, upper_cap - lower_cap, -cost);
        } else {
            fbias.emplace_back(upper_cap);
            fdir.emplace_back(1);
            if (lower_cap < 0) {
                cost_bias += cost * lower_cap, b[s] -= lower_cap, b[t] += lower_cap;
                upper_cap -= lower_cap, lower_cap = 0;
            }
            if (lower_cap > 0) {
                cost_bias += cost * lower_cap;
                b[s] -= lower_cap;
                b[t] += lower_cap;
                upper_cap -= lower_cap;
            }
            mcf.add_edge(s, t, upper_cap, cost);
        }
    }

    std::pair<bool, COST> solve() {
        if (infeasible) {
            return std::make_pair(false, 0);
        }
        CAP bsum = 0, bsum_negative = 0;
        for (int i = 0; i < N; i++) {
            if (b[i] > 0) {
                mcf.add_edge(N, i, b[i], 0), bsum += b[i];
            }
            if (b[i] < 0) {
                mcf.add_edge(i, N + 1, -b[i], 0), bsum_negative -= b[i];
            }
        }
        if (bsum != bsum_negative) {
            return std::make_pair(false, 0);
        }
        std::fill(b.begin(), b.end(), 0);
        auto ret = mcf.flow(N, N + 1, bsum);
        COST cost_ret = cost_bias + ret.second;
        cost_bias = 0;
        bool succeeded = (ret.first == bsum);
        f = fbias;
        for (int i = 0; i < E; i++) {
            const std::pair<int, int> &p = mcf.pos[i];
            f[i] -= fdir[i] * mcf.g[p.first][p.second].cap;
        }
        return std::make_pair(succeeded, cost_ret);
    }
};
array<int, 4> dx { 1, -1, 0, 0 };
array<int, 4> dy { 0, 0, 1, -1 };
int main()
{
    int N;
    cin >> N;
    vector A(N, vector<int>(N));
    cin >> A;
    B_Flow<lint, lint> flow(N * N);

    auto ij2v = [&](int i, int j) {
        return i * N + j;
    };
    auto adddiff = [&](int i1, int j1, int i2, int j2) {
        int v1 = ij2v(i1, j1);
        int v2 = ij2v(i2, j2);
        flow.add_edge(v1, v2, 0, 1, 0);
        flow.add_edge(v2, v1, 0, 1, 0);
    };
    auto add1 = [&](int i, int j, lint val) {
        int v = ij2v(i, j);
        flow.add_edge(0, v, 0, 1, -val);
        flow.add_edge(v, 0, 0, 1, val);
    };
    REP(i, N) REP(j, N) if (A[i][j] == 0)
    {
        if (A[i + 1][j] == 0) {
            adddiff(i, j, i + 1, j);
        }
        if (A[i][j + 1] == 0) {
            adddiff(i, j, i, j + 1);
        }
        REP(d, 4) {
            int a = A[i + dx[d]][j + dy[d]];
            if (a > 0) add1(i, j, a);
        }
    }

    auto [cap, cost] = flow.solve();
    dbg(flow.potential);
    dbg(cap);
    dbg(cost);
    lint ret = 0;
    REP(i, N) REP(j, N - 1) if (A[i][j] > 0 and A[i][j + 1] > 0) ret += abs(A[i][j] - A[i][j + 1]);
    REP(i, N - 1) REP(j, N) if (A[i][j] > 0 and A[i + 1][j] > 0) ret += abs(A[i][j] - A[i + 1][j]);
    cout << -cost + ret << '\n';
}
