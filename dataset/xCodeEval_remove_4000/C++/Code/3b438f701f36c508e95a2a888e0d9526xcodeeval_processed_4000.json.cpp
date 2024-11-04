



















using namespace std;







template <class ... Ts> string to_string(const tuple<Ts...> &t);
template < class T, class TT > string to_string(const pair<T, TT> &p);
string to_string(const char &c) { return string(1, c); }
string to_string(const string &s) { return s; }
string to_string(const char s[]) { return to_string(string(s));}
template <class T> string to_string(const T &v);

template <class Tuple, size_t I, class = void>
struct ToString {
  static string apply(const Tuple& tp) {
    return to_string(get<I>(tp)) + ", " + ToString<Tuple, I + 1u>::apply(tp);
  }
};

template <class Tuple, std::size_t I>
struct ToString<Tuple, I, typename enable_if<I == std::tuple_size<typename std::decay<Tuple>::type>::value>::type> {
  static string apply(const Tuple& tp) { return ""; }
};

template <class ... Ts>
string to_string(const tuple<Ts...> &t) {
  return "{" + ToString<tuple<Ts...>, 0>::apply(t) + "}";
}

template < class T, class TT >
string to_string(const pair<T, TT> &p) { return to_string(make_tuple(p.first, p.second)); }

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

typedef long double ld;
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
typedef vector<vb> vvb;
typedef vector<vi32> vvi32;
typedef vector<vi64> vvi64;
typedef vector<vector<vi64>> vvvi64;
typedef list<pi64> lpi64;
typedef vector<list<i64>> AdjacencyLists;
typedef vector<list<pair<i64, i64>>> WeightedAdjacencyLists;
typedef vvi64 AdjacencyMatrix;

template<class T> inline T sqr(const T &x) { return x * x; }
inline i64 sqr(int x){return sqr<i64>(x);}
template<class T>T binpow(const T &a, i64 n) { return n == 0 ? T(1) : sqr(binpow(a, n / 2))* (n % 2 ? a : T(1)); }
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

template<class T, const T id6=-1, class TT=i64>
class IntModulo {
  constexpr static const T order = phi(id6);

  T value;
  T _modulo;
public:
  explicit IntModulo(const TT &value = 0, const T &modulo = id6) : value(smart_modulo(value, modulo)), _modulo(modulo) {}
  IntModulo(const IntModulo &i) : IntModulo(i.value, i.modulo()) {}

  inline IntModulo& operator = (const IntModulo &i) { value = i.value; _modulo = i.modulo(); return *this; }

  inline IntModulo& operator += (const IntModulo &i) { TT tmp = TT(value) + TT(i.value); if (tmp >=_modulo) { tmp -= _modulo; }; value = T(tmp); return *this; }
  inline IntModulo& operator -= (const IntModulo &i) { return *this += -i; }
  inline IntModulo& operator *= (const IntModulo &i) { value = T((TT(value) * TT(i.value)) % _modulo); return *this; }
  inline IntModulo& operator /= (const IntModulo &i) { return *this *= i.inverse(); };

  inline IntModulo inverse() const { return binpow(*this, order - 1); };
  inline const T& modulo() const { return _modulo; }

  inline operator T() const { return value; }

  friend inline IntModulo operator - (const IntModulo &i) { return IntModulo(i._modulo - i.value, i._modulo); }

  friend inline bool operator == (const IntModulo &a, const IntModulo &b) { return a.value == b.value; }

  inline T smart_modulo(const TT &value, const T &modulo=id6) {
    if (value < TT(0)) {
      return ((-value + modulo - TT(1)) / modulo * modulo + value) % modulo;
    }

    if (value < modulo) {
      return (T)value;
    }

    if (value < TT(2) * modulo) {
      return T(value - modulo);
    }

    return value % modulo;
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
  explicit constexpr Fraction(const T &numerator=T(0), const T &denominator=T(1)) : _numerator(numerator), _denominator(denominator) {
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
  set < pair<i64, int> > q;
  
  d[s] = 0;
  q.emplace(0, s);
  
  while (!q.empty()) {










    int v = q.begin()->second;
    
    q.erase(q.begin());
    
    for (const auto &cw : g[v])
    {
      if (d[v] + cw.second < d[cw.first])
      {
        q.erase({d[cw.first], cw.first});
        d[cw.first] = d[v] + cw.second;
        q.emplace(d[cw.first], cw.first);
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

void DFS(i64 v, const AdjacencyLists &g, vi64 &colors, i64 color, vi64 &time_in, vi64 &time_out,  i64 &time, vi64 &vertex_in, vi64 &vertex_out) {
  colors[v] = color;
  time_in[v] = time++;
  vertex_in.push_back(v);

  for (const auto &c : g[v]) {
    if (-1 == colors[c]) {
      DFS(c, g, colors, color, time_in, time_out, time, vertex_in, vertex_out);
    }
  }

  time_out[v] = time++;
  vertex_out.push_back(v);
}

tuple<vi64, vi64, vi64, vi64, vi64> DFS(const AdjacencyLists &g, const vi64 &order) {
  const auto n = SZ(g);

  vi64 colors(n, -1);
  i64 color = 0;
  vi64 time_in(n, -1);
  vi64 time_out(n, -1);
  i64 time = 0;
  vi64 vertex_in;
  vi64 vertex_out;
  vertex_in.reserve(n);
  vertex_out.reserve(n);

  for (const auto &v : order) {
    if (-1 == colors[v]) {
      DFS(v, g, colors, color, time_in, time_out, time, vertex_in, vertex_out);
      ++color;
    }
  }

  return {colors, time_in, time_out, vertex_in, vertex_out};
}

tuple<vi64, vi64, vi64, vi64, vi64> DFS(const AdjacencyLists &g) {
  vi64 order(SZ(g));
  iota(ALL(order), 0);

  return DFS(g, order);
}

vi64 id0(const AdjacencyLists &g) {
  

  vi64 order = get<4>(DFS(g));
  reverse(ALL(order));

  return order;
}

AdjacencyLists transpose(const AdjacencyLists &g) {
  AdjacencyLists gt(SZ(g));

  FOR(v, SZ(g)) {
    for (const auto &c : g[v]) {
      gt[c].push_back(v);
    }
  }

  return gt;
}

pair<AdjacencyLists, vi64> SCC(const AdjacencyLists &g) {
  vi64 order = id0(g);
  const auto gt = transpose(g);
  const vi64 colors = get<0>(DFS(gt, order));

  set < pi64 > edges;
  AdjacencyLists gc(1 + *max_element(ALL(colors)));

  FI(SZ(g)) {
    for (const auto &c : g[i]) {
      if (colors[i] != colors[c] && !edges.count({colors[i], colors[c]})) {
        gc[colors[i]].push_back(colors[c]);
        edges.emplace(colors[i], colors[c]);
      }
    }
  }

  return {gc, colors};
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
  const T &id4;
  
  SegmentTree() {}
  
  SegmentTree(const i64 n,
              Function operation,
              const T &id1=T(),
              Function modification=assign<T>,
              const T &id4=T()
  ) :
    n(n),
    t(n << 1, id1),
    operation(operation),
    id1(id1),
    modification(modification),
    id4(id4)
  {
    build();
  }
    
  template < class Iterator >
  SegmentTree(const Iterator &begin,
              const Iterator &end,
              Function operation,
              const T &id1=T(),
              Function modification=assign<T>,
              const T &id4=T()
  ) : SegmentTree(end - begin,
                  operation,
                  id1,
                  modification,
                  id4)
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


template <class T>
struct SparseTable {
  typedef function<T(T, T)> Function;
  
  vector<vector<T>> t;
  const function<T(const T&, const T&)> operation;
  const T &id1;

  SparseTable(const vector<T> &a, Function operation, const T &id1 = T()) :
      operation(operation),
      id1(id1) {
    const i64 n = SZ(a);
    t.push_back(vi64(n));
    
    FI(n) {
        t[0][i] = a[i];
    }
    
    for (int j = 0; (1 << j) < n; ++j) {
        t.push_back(vi64(n));
        
        for (int i = 0; i + (1 << j) < SZ(t[j]); ++i) {
            t[1 + j][i] = operation(t[j][i], t[j][i + (1 << j)]);
        }
    }
  }
    
  i64 query(i64 begin, i64 end) {
      if (begin >= end) {
          return id1;
      }
      
      i64 length = end - begin;
      i64 j = 0;
      
      while ((1 << (j + 1)) <= length) {
          ++j;
      }
      
      auto answer = operation(t[j][begin], t[j][end - (1 << j)]);
            
      return answer;
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
  id3(i64 id5)
  {
    tree.reserve(id5);
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


struct BinarySearchIterator : public iterator<random_access_iterator_tag, bool>
{
  i64 value;

  typename iterator_traits<BinarySearchIterator>::difference_type operator - (const BinarySearchIterator &it) const { return value - it.value; }

  BinarySearchIterator& operator ++() { return *this += 1; }

  BinarySearchIterator& operator --() { return *this += -1; } 


  BinarySearchIterator& operator +=(typename iterator_traits<BinarySearchIterator>::difference_type n) { value += n; return *this;}

  bool operator != (const BinarySearchIterator &it) const { return value != it.value; }

  bool operator*() const {
    
    return true;
  }
};


int main(int argc, const char * argv[]) {

  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.precision(13);
  cout.setf(ios::fixed);
  srand((unsigned int)time(NULL));
   
  i64 n, m;
  
  while (cin >> n >> m) {
    vi64 distance2(n, numeric_limits<i64>::max() / 2);
    WeightedAdjacencyLists g(4 * n);
    
    for (i64 i = 0; i < m; ++i) {
      i64 u, v, w;
      cin >> u >> v >> w;
      --u; --v;
    
      if (u > v) {
        swap(u, v);
      }
      
      if (u == 0) {
        distance2[v] = min(distance2[v], w);
      }
      
      for (i64 removed = 0; removed <= 1; ++removed) {
        for (i64 added = 0; added <= 1; ++added) {
          i64 uu = u + added * n + removed * 2 * n;
          i64 vv = v + added * n + removed * 2 * n;
          
          g[uu].emplace_back(vv, w);
          g[vv].emplace_back(uu, w);
          
          if (added == 0) {
            g[uu].emplace_back(vv + 1 * n, 2 * w);
            g[vv].emplace_back(uu + 1 * n, 2 * w);
          }
          
          if (removed == 0) {
            g[uu].emplace_back(vv + 2 * n, 0);
            g[vv].emplace_back(uu + 2 * n, 0);
          }
        }
      }
    }
    
    auto distance = Dijkstra(g, 0);
        
    FORS(i, 1, n) {
      cout << min(distance2[i], distance[i + 1 * n + 2 * n]) << ' ';
    }
    cout << endl;
  }


  return 0;
}
