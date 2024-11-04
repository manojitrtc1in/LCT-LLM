



















using namespace std;







template <class Tuple, size_t I, class = void>
struct ToString {
  static string apply(const Tuple&& tp) {
    return to_string(get<I>(forward<Tuple>(tp))) + ", " + ToString<Tuple, I + 1u>::apply(forward<Tuple>(tp));
  }
};

template <class Tuple, std::size_t I>
struct ToString<Tuple, I, typename enable_if<I == std::tuple_size<typename std::decay<Tuple>::type>::value>::type> {
  static string apply(const Tuple&& tp) { return ""; }
};

template <class ... Ts>
string to_string(const tuple<Ts...> &t) {
  return "{" + ToString<tuple<Ts...>, 0>::apply(t) + "}";
}

template <class T>
string to_string(const T &v) {
  string s = "{";
  for (const auto &e : v) {
    s += to_string(e);
    s += (", ");
  }
  s += "}";

  return s;
}

void debug_out() { cerr << endl; }

template <class Head, class... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}

typedef int_fast8_t i8;
typedef int_fast16_t i16;
typedef int_fast32_t i32;
typedef int_fast64_t i64;
typedef uint_fast8_t u8;
typedef uint_fast16_t u16;
typedef uint_fast32_t u32;
typedef uint_fast64_t u64;
typedef pair<i64, i64> pi64;
typedef vector<i8> vb;
typedef vector<i32> vi32;
typedef vector<i64> vi64;
typedef vector<pi64> vpi64;
typedef vector<vi32> vvi32;
typedef vector<vi64> vvi64;
typedef vector<vector<vi64>> vvvi64;
typedef vector<list<i64>> AdjacencyLists;
typedef vector<list<pair<int, i64>>> WeightedAdjacencyLists;
typedef vvi64 AdjacencyMatrix;

template<class T> inline T sqr(const T &x) { return x * x; }
inline i64 sqr(int x){return sqr<i64>(x);}
template<class T>T binpow(const T &a, i64 n) { return n == T(0) ? T(1) : sqr(binpow(a, n / 2))* (n % 2 ? a : T(1)); }
i64 binpow(i64 a, i64 n, i64 modulo) { return n == 0 ? 1 : sqr(binpow(a, n / 2, modulo)) % modulo * (n % 2 ? a : 1) % modulo;}
constexpr inline i64 phi (i64 n) {
  i64 result = n;
  for (i64 i = 2; i * i <= n; ++i)
    if (n % i == 0) {
        while (n % i == 0)
          n /= i;
        result -= result / i;
    }
  if (n > 1)
    result -= result / n;
  return result;
}

inline vi64 inverseAll(i64 m)
{
  vi64 r(m);
  r[1] = 1;

  for (int i = 2; i < m; ++i)
    r[i] = (m - (m/i) * r[m%i] % m) % m;
  return r;
}
i64 gcd(i64 a, i64 b, i64 &x, i64 &y)
{
  if (a == 0)
  {
    x = 0;
    y = 1;
    return b;
  }
  i64 x1, y1;
  i64 d = gcd(b%a, a, x1, y1);
  x = y1 - (b / a) * x1;
  y = x1;
  return d;
}
inline i64 gcd(i64 a, i64 b) { return gcd(a, b, a, b); }
inline i64 lcm(i64 a, i64 b) { return a / gcd(a, b) * b; }
inline i64 sgn(const i64 &a) { return (a > 0) - (a < 0); }

template<class T, const T id7=-1, class TT=i64>
class IntModulo {
  constexpr static const T order = phi(id7);
  
  T value;
  T _modulo;
public:
  explicit IntModulo(const TT &value = 0, const T &modulo = id7) : value(smart_modulo(value, modulo)), _modulo(modulo) {}
  IntModulo(const IntModulo &i) : IntModulo(i.value, i.modulo()) {}
  
  inline IntModulo& operator = (const IntModulo &i) { value = i.value; _modulo = i.modulo(); }
  
  inline IntModulo& operator += (const IntModulo &i) { TT tmp = TT(value) + TT(i.value); if (tmp >=_modulo) { tmp -= _modulo; }; value = T(tmp); return *this; }
  inline IntModulo& operator -= (const IntModulo &i) { return *this += -i; }
  inline IntModulo& operator *= (const IntModulo &i) { value = T((TT(value) * TT(i.value)) % _modulo); return *this; }
  inline IntModulo& operator /= (const IntModulo &i) { return *this *= i.inverse(); };
    
  inline IntModulo inverse() const { return binpow(*this, order - 1); };
  inline const T& modulo() const { return _modulo; }
  
  inline operator T() const { return value; }
  
  friend inline IntModulo operator - (const IntModulo &i) { return IntModulo(i._modulo - i.value, i._modulo); }

  friend inline bool operator == (const IntModulo &a, const IntModulo &b) { return a.value == b.value; }
  
  inline T smart_modulo(const TT &value, const T &modulo=id7) {
    if (value < TT(0)) {
      return T(((-value + modulo - TT(1)) / modulo * modulo + value) % modulo);
    }
    
    if (value < modulo) {
      return T(value);
    }
    
    if (value < TT(2) * modulo) {
      return T(value - modulo);
    }
    
    return T(value % modulo);
  }
};

template<class T, const T modulo, class TT=i64>
inline IntModulo<T, modulo, TT> operator + (const IntModulo<T, modulo, TT> &a, const IntModulo<T, modulo, TT> &b) { return IntModulo<T, modulo, TT>(a) += b; }

template<class T, const T modulo, class TT=i64>
inline IntModulo<T, modulo, TT> operator - (const IntModulo<T, modulo, TT> &a, const IntModulo<T, modulo, TT> &b) { return IntModulo<T, modulo, TT>(a) -= b; }

template<class T, const T modulo, class TT=i64>
inline IntModulo<T, modulo, TT> operator * (const IntModulo<T, modulo, TT> &a, const IntModulo<T, modulo, TT> &b) { return IntModulo<T, modulo, TT>(a) *= b; }

template<class T, const T modulo, class TT=i64>
inline IntModulo<T, modulo, TT> operator / (const IntModulo<T, modulo, TT> &a, const IntModulo<T, modulo, TT> &b) { return IntModulo<T, modulo, TT>(a) /= b; }

template<class T, const T modulo, class TT=i64>
inline bool operator != (const IntModulo<T, modulo, TT> &a, const IntModulo<T, modulo, TT> &b) { return !(a == b); }

template<class T, const T modulo, class TT>
string to_string(const IntModulo<T, modulo, TT> &t){
  return "(value=" + to_string(T(t)) + ", modulo=" + to_string(t.modulo()) + ")";
}

template<class T=i64>
class Fraction {
public:
  explicit Fraction(const T &numerator=T(0), const T &denominator=T(1)) : _numerator(numerator), _denominator(denominator) {
    i64 g = gcd(abs(numerator), abs(denominator)) * sgn(denominator);

    if (g != T(0)) {
      _numerator /= g;
      _denominator /= g;
    }
  }

  inline const T& numerator() const { return _numerator; }
  inline const T& denominator() const { return _denominator; }

private:
  T _numerator, _denominator;
};

template<class T=i64>
inline bool operator < (const Fraction<T> &a, const Fraction<T> &b) { return a.numerator() * b.denominator() < b.numerator() * a.denominator(); }

template<class T=i64>
inline bool operator > (const Fraction<T> &a, const Fraction<T> &b) { return b < a; }

template<class T=i64>
inline bool operator >= (const Fraction<T> &a, const Fraction<T> &b) { return !(a < b); }

template<class T=i64>
inline bool operator <= (const Fraction<T> &a, const Fraction<T> &b) { return b <= a; }

template<class T=i64>
inline bool operator == (const Fraction<T> &a, const Fraction<T> &b) { return !(a < b) && !(b < a); }

template<class T=i64>
inline bool operator != (const Fraction<T> &a, const Fraction<T> &b) { return !(a == b); }

template<class T=i64>
string to_string(const Fraction<T> &a) { return to_string(a.numerator()) + "/" + to_string(a.denominator()); }

mt19937_64 rng(

               0LL

               chrono::steady_clock::now().time_since_epoch().count()

               );
inline i64 random(i64 low, i64 high) { return uniform_int_distribution<i64>(low, high)(rng); }
inline i64 random(i64 high=numeric_limits<i64>::max()) { return random(0, high); }



struct Dinic {
  struct Edge {
    int u, v;
    i64 cap, flow;
    Edge() {}
    Edge(int u, int v, i64 cap): u(u), v(v), cap(cap), flow(0) {}
  };
  
  int N;
  vector<Edge> E;
  vector<vector<int>> g;
  vector<int> d, pt;
  
  Dinic(int N): N(N), E(0), g(N), d(N), pt(N) {}
  
  void AddEdge(int u, int v, i64 cap) {
    if (u != v) {
      E.emplace_back(Edge(u, v, cap));
      g[u].emplace_back(E.size() - 1);
      E.emplace_back(Edge(v, u, 0));
      g[v].emplace_back(E.size() - 1);
    }
  }
  
  bool BFS(int S, int T) {
    queue<int> q({S});
    fill(d.begin(), d.end(), N + 1);
    d[S] = 0;
    while(!q.empty()) {
      int u = q.front(); q.pop();
      if (u == T) break;
      for (int k: g[u]) {
        Edge &e = E[k];
        if (e.flow < e.cap && d[e.v] > d[e.u] + 1) {
          d[e.v] = d[e.u] + 1;
          q.emplace(e.v);
        }
      }
    }
    return d[T] != N + 1;
  }
  
  i64 DFS(int u, int T, i64 flow = -1) {
    if (u == T || flow == 0) return flow;
    for (int &i = pt[u]; i < g[u].size(); ++i) {
      Edge &e = E[g[u][i]];
      Edge &oe = E[g[u][i]^1];
      if (d[e.v] == d[e.u] + 1) {
        i64 amt = e.cap - e.flow;
        if (flow != -1 && amt > flow) amt = flow;
        if (i64 pushed = DFS(e.v, T, amt)) {
          e.flow += pushed;
          oe.flow -= pushed;
          return pushed;
        }
      }
    }
    return 0;
  }
  
  i64 MaxFlow(int S, int T) {
    i64 total = 0;
    while (BFS(S, T)) {
      fill(pt.begin(), pt.end(), 0);
      while (i64 flow = DFS(S, T))
        total += flow;
    }
    return total;
  }
};

vi64 Dijkstra(const WeightedAdjacencyLists &g, int s) {
  vi64 d(SZ(g), numeric_limits<i64>::max() / 2LL);
  priority_queue < pair<i64, int> > q;
  
  d[s] = 0;
  q.emplace(-0, s);
  
  while (!q.empty()) {
    if (q.top().first > d[q.top().second]) {
      q.pop();
      
      continue;
    }
    int v = q.top().second;
    
    q.pop();
    
    for (const auto &cw : g[v])
    {
      if (d[v] + cw.second < d[cw.first])
      {
        d[cw.first] = d[v] + cw.second;
        q.emplace(-d[cw.first], cw.first);
      }
    }
  }
  
  return d;
}

vi64 BFS(const AdjacencyLists &g, i64 s) {
  vi64 d(SZ(g), SZ(g));
  queue<i64> q;
  
  d[s] = 0;
  q.emplace(s);
  
  while (SZ(q)) {
    const auto v = q.front();
    
    q.pop();
    
    for (const auto &c : g[v]) {
      if (d[c] > d[v]) {
        d[c] = d[v] + 1;
        q.emplace(c);
      }
    }
  }
  
  return d;
}


struct UnionFind {
    vi64 parent;
    vi64 rank;
    UnionFind(i64 n) : parent(n), rank(n) {
        for (i64 i = 0; i < n; ++i) {
            parent[i] = i;
            rank[i] = 0;
        }
    }
    i64 find_set (i64 v) {
        if (v == parent[v])
            return v;
        return parent[v] = find_set (parent[v]);
    }
    void union_sets (i64 a, i64 b) {
        a = find_set (a);
        b = find_set (b);
        if (a != b) {
            if (rank[a] < rank[b])
                swap (a, b);
            parent[b] = a;
            if (rank[a] == rank[b])
                ++rank[a];
        }
    }
};



template < class T >
const T assign(const T& a, const T& b) { return b; }

template< class T >
const T& my_min(const T& a, const T& b) { return a < b ? a : b; }

template< class T>
struct SegmentTree {
  typedef function<T(T, T)> Function;

  const i64 n;
  vector<T> t;
  const function<T(const T&, const T&)> operation;
  const T &id1;
  const function<T(const T&, const T&)> modification;
  const T &id5;
  
  SegmentTree() {}
  
  SegmentTree(const i64 n,
              Function operation,
              const T &id1=T(),
              Function modification=assign<T>,
              const T &id5=T()
  ) :
    n(n),
    t(n << 1, id1),
    operation(operation),
    id1(id1),
    modification(modification),
    id5(id5)
  {
    build();
  }
    
  template < class Iterator >
  SegmentTree(const Iterator &begin,
              const Iterator &end,
              Function operation,
              const T &id1=T(),
              Function modification=assign<T>,
              const T &id5=T()
  ) : SegmentTree(end - begin,
                  operation,
                  id1,
                  modification,
                  id5)
  {
    copy(begin, end, t.begin() + n);
    build();
  }
  
  void build() {
    for (i64 i = n - 1; i > 0; --i) t[i] = operation(t[i<<1], t[i<<1|1]);
  }
  
  void modify(i64 p, const T &value) {
    p += n;
    
    for (t[p] = modification(t[p], value); p > 1; p >>= 1) t[p>>1] = operation(t[p], t[p^1]);
  }
  
  T query(i64 l, i64 r) const {  

    T res = id1;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
        if (l&1) res = operation(res, t[l++]);
        if (r&1) res = operation(res, t[--r]);
    }
    return res;
  }
};


template < i64 ALPHA >
class id3
{
public:
  static const i64 id2;
  static const i64 ROOT;

  struct Node
  {
    bool leaf;
    i64 parent;
    i64 parentCharacter;
    i64 link;

    i64 next[ALPHA];
    i64 go[ALPHA];
    i64 outputFunction;

    Node(i64 parent = id2, i64 parentCharacter = ALPHA) :
    leaf(false),
    parent(parent),
    parentCharacter(parentCharacter),
    link(id2),
    outputFunction(id2)
    {
      fill_n(next, ALPHA, id2);
      fill_n(go, ALPHA, id2);
    }
  };

  vector<Node> tree = vector<Node>(1);

  id3(){}
  id3(i64 id6)
  {
    tree.reserve(id6);
  }

  template < class Iterator >
  i64 add(i64 length, const Iterator begin)
  {
    i64 vertex = ROOT;

    for (i64 i = 0; i < length; ++i)
    {
      if (id2 == tree[vertex].next[begin[i]])
      {
        tree[vertex].next[begin[i]] = SZ(tree);
        tree.push_back(Node(vertex, begin[i]));
      }

      vertex = tree[vertex].next[begin[i]];
    }

    tree[vertex].leaf = true;

    return vertex;
  }

  i64 getLink(i64 vertex)
  {
    assert(0 <= vertex && vertex < tree.size());

    if (id2 == tree[vertex].link)
    {
      if (ROOT == vertex || ROOT == tree[vertex].parent)
      {
        tree[vertex].link = ROOT;
      }
      else
      {
        tree[vertex].link = go(getLink(tree[vertex].parent), tree[vertex].parentCharacter);
      }
    }

    return tree[vertex].link;
  }

  i64 go(i64 vertex, i64 character)
  {
    assert(0 <= character && character < ALPHA);
    assert(0 <= vertex && vertex < tree.size());

    if (id2 == tree[vertex].go[character])
    {
      if (id2 == tree[vertex].next[character])
      {
        tree[vertex].go[character] = ROOT == vertex ? ROOT : go(getLink(vertex), character);
      }
      else
      {
        tree[vertex].go[character] = tree[vertex].next[character];
      }
    }

    return tree[vertex].go[character];
  }

  i64 getOutputFunction(i64 vertex)
  {
    assert(0 <= vertex && vertex < tree.size());

    if (id2 == tree[vertex].outputFunction)
    {
      if (tree[vertex].leaf || ROOT == vertex)
      {
        tree[vertex].outputFunction = vertex;
      }
      else
      {
        tree[vertex].outputFunction = getOutputFunction(getLink(vertex));
      }
    }

    return tree[vertex].outputFunction;
  }
};

struct id4 : public iterator<random_access_iterator_tag, bool>
{
  i64 value;
  
  id4(const i64 &value) : value(value) {}

  typename iterator_traits<id4>::difference_type operator - (const id4 &it) const { return value - it.value; }

  id4& operator ++() { return *this += 1; }

  id4& operator --() { return *this += -1; } 


  id4& operator +=(typename iterator_traits<id4>::difference_type n) { value += n; return *this;}

  bool operator != (const id4 &it) const { return value != it.value; }

  bool operator*() const {
        
    return true;
  }
};

typedef IntModulo<i64> Int;

i64 solve(const i64 &k, const vpi64 &ab) {
  
  const i64 n = SZ(ab);
  const i64 INF = numeric_limits<i64>::max() / 2;
  Int id0(0, k);
  
  vvi64 dp(2, vi64(1 + k, -INF));
  
  dp[0][0] = 0;
  
  FI(n) {
    const auto id8 = id0;
    id0 += Int(ab[i].first + ab[i].second, k);
        
    FOR(previous_a, k) {
      if (dp[i & 1][previous_a] >= 0) {
        Int &&previous_b = id8 - Int(previous_a, k);
        
        FOR(next_a, k) {
          Int &&next_b = id0 - Int(next_a, k);
          debug(id0 - Int(next_a, k));
          debug(next_b);
          
          i64 delta_a = Int(next_a, k) - Int(previous_a, k);
          i64 delta_b = next_b - previous_b;
          
          if (delta_a <= ab[i].first && delta_b <= ab[i].second) {

            assert((ab[i].first + ab[i].second - delta_a - delta_b) % k == 0);

            i64 change = (next_a < previous_a) + (next_b < previous_b) + (ab[i].first + ab[i].second - delta_a - delta_b) / k;
            dp[(i + 1) & 1][next_a] = max(dp[(i + 1) & 1][next_a], dp[i & 1][previous_a] + change);
          }
        }
      }
    }

    debug(i, dp[(i+1) & 1]);
    fill_n(dp[i & 1].begin(), k, -INF);
  }
  
  
  i64 answer = *max_element(ALL(dp[n & 1]));
  
  return answer;
}







int main(int argc, const char * argv[]) {

  assert(Int(3, 5) == -Int(2, 5));
  assert(Int(1, 5) == Int(3, 5) - Int(2, 5));
  assert(0 == solve(5, {
    {2, 1},
    {1, 3},
  }));
  assert(2 == solve(4, {
    {5, 2},
    {2, 1}
  }));
  assert(1 == solve(5, {{2, 3}}));
  assert(500000000 == solve(2, {{1000000000, 1}}));

  
  i64 n, k;
  while(cin >> n >> k){
    vpi64 ab(n);
    FI(n) {
      cin >> ab[i].first >> ab[i].second;
    }
    cout << solve(k, ab) << endl;
  }

  return 0;
}

