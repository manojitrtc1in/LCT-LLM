



















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
typedef list<i64> li64;
typedef vector<pi64> vpi64;
typedef vector<vi32> vvi32;
typedef vector<vi64> vvi64;
typedef vector<vector<vi64>> vvvi64;
typedef vector<li64> vli64;
typedef vector<list<int>> AdjacencyLists;
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

template<class T, const T modulo, class TT=i64>
class IntModulo {
  constexpr static const T order = phi(modulo);
  
  T value;
public:
  explicit IntModulo(const TT &value = 0) : value(T(((abs(value) + modulo - TT(1)) / modulo * modulo + value) % modulo)) {}
  
  inline IntModulo& operator += (const IntModulo &i) { value = T((TT(value) + TT(i.value)) % modulo); return *this; }
  inline IntModulo& operator -= (const IntModulo &i) { return *this += -i; }
  inline IntModulo& operator *= (const IntModulo &i) { value = T((TT(value) * TT(i.value)) % modulo); return *this; }
  inline IntModulo& operator /= (const IntModulo &i) { return *this *= i.inverse(); };
    
  inline IntModulo inverse() const { return binpow(*this, order - 1); };
  
  inline operator T() const { return value; }
  
  friend inline IntModulo operator - (const IntModulo &i) { return IntModulo<T, modulo, TT>(modulo - i.value); }

  friend inline bool operator == (const IntModulo &a, const IntModulo &b) { return a.value == b.value; }
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
  const T &id0;
  const function<T(const T&, const T&)> modification;
  const T &id3;
  
  SegmentTree() {}
  
  SegmentTree(const i64 n,
              Function operation,
              const T &id0=T(),
              Function modification=assign<T>,
              const T &id3=T()
  ) :
    n(n),
    t(n << 1, id0),
    operation(operation),
    id0(id0),
    modification(modification),
    id3(id3)
  {
    build();
  }
    
  template < class Iterator >
  SegmentTree(const Iterator &begin,
              const Iterator &end,
              Function operation,
              const T &id0=T(),
              Function modification=assign<T>,
              const T &id3=T()
  ) : SegmentTree(end - begin,
                  operation,
                  id0,
                  modification,
                  id3)
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

    T res = id0;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
        if (l&1) res = operation(res, t[l++]);
        if (r&1) res = operation(res, t[--r]);
    }
    return res;
  }
};


template < i64 ALPHA >
class id2
{
public:
  static const i64 id1;
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

    Node(i64 parent = id1, i64 parentCharacter = ALPHA) :
    leaf(false),
    parent(parent),
    parentCharacter(parentCharacter),
    link(id1),
    outputFunction(id1)
    {
      fill_n(next, ALPHA, id1);
      fill_n(go, ALPHA, id1);
    }
  };

  vector<Node> tree = vector<Node>(1);

  id2(){}
  id2(i64 id4)
  {
    tree.reserve(id4);
  }

  template < class Iterator >
  i64 add(i64 length, const Iterator begin)
  {
    i64 vertex = ROOT;

    for (i64 i = 0; i < length; ++i)
    {
      if (id1 == tree[vertex].next[begin[i]])
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

    if (id1 == tree[vertex].link)
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

    if (id1 == tree[vertex].go[character])
    {
      if (id1 == tree[vertex].next[character])
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

    if (id1 == tree[vertex].outputFunction)
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


struct BinarySearchIterator : public std::iterator<std::random_access_iterator_tag, bool>
{
  i64 value;

  typename iterator_traits<BinarySearchIterator>::difference_type operator - (const BinarySearchIterator &it) const { return value - it.value; }

  BinarySearchIterator& operator ++() { return *this += 1; }

  BinarySearchIterator& operator +=(typename iterator_traits<BinarySearchIterator>::difference_type n) { value += n; return *this;}

  bool operator != (const BinarySearchIterator &it) const { return value != it.value; }

  bool operator*() const {
    
    return true;
  }
};

i64 solve(vi64 a) {
  set<pair<i64, i64>> ai;
  
  FI(SZ(a)) {
    ai.emplace(a[i], i);
  }
  
  i64 value = 0;
  i64 i = -1;
  i64 answer = 0;
  
  vi64 ones(SZ(a) * 2, 1LL);
  SegmentTree<i64> st(ALL(ones), plus<i64>());
  
  while (SZ(ai)) {
    const auto it = ai.lower_bound({value, 0});
    assert(it != ai.end());
    auto jt = ai.lower_bound({it->first, i + 1});
    
    if (jt == ai.end() || jt->first > it->first) {
      jt = it;
    }
    
    assert(jt->second < SZ(a));
    
    i64 from = i;
    i64 to = jt->second;
    
    if (to < from) {
      to += SZ(a);
    }
    
    assert(to >= 0);
    i64 current = st.query(1 + from, 1 + to); 

    debug(from, to, current);
    answer += current;
    
    tie(value, i) = *jt;
    
    ai.erase(jt);
    st.modify(i, 0LL);
    st.modify(i + SZ(a), 0LL);
  }
  
  debug(answer);
  
  return answer;
}


i64 bf(const vi64 &aaa) {
  i64 answer = 1;
  li64 a(ALL(aaa));
  
  while (SZ(a) > 1) {
    i64 aa = a.front();
    a.pop_front();
    ++answer;
    
    if (aa > *min_element(ALL(a))) {
      a.push_back(aa);
    }
  }
  
  return answer;
}
vi64 generate() {
  i64 n = random(1, 4);
  vi64 a(n);
  
  FI(n) {
    a[i] = random(1, 2 * n);
  }
  
  return a;
}
void stress() {
  while(true) {
    const auto a = generate();
    const auto ans = bf(a);
    const auto out = solve(a);
    debug(a);
    debug(ans, out);
    assert(ans == out);
  }
}


int main(int argc, const char * argv[]) {

  assert(solve({4, 3, 2, 1}) == 10);
  assert(solve({2, 1, 2}) == 4);
  assert(solve({7, 1, 5, 1}) == 7);
  assert(bf({1, 3, 2, 4}) == 6);
  assert(bf({4, 3, 2, 1}) == 10);
  assert(bf({3, 2, 1}) == 6);
  assert(bf({6,3,1,2}) == 7);
  assert(bf({12, 2, 2, 10, 12, 1, 5, 9, 15, 2, 4, 7, 7, 14, 8, 10, 1, 6, 7, 6, 13, 15, 10, 6, 2, 11, 13, 1, 15, 14, 8, 8, 4, 7, 11, 12, 3, 15, 9, 2, 13, 1, 7, 11, 2, 1, 13, 11, 8, 14, 2, 2, 12, 7, 13, 4, 13, 3, 13, 3, 11, 1, 7, 13, 15, 8, 12, 4, 12, 4, 1, 4, 9, 3, 13, 12, 10, 15, 14, 10, 7, 7, 7, 2, 7, 6, 10}) == 580);
  assert(solve({1, 3, 2, 4}) == 6);
  assert(solve({3, 2, 1}) == 6);
  assert(solve({6,3,1,2}) == 7);
  stress();
  assert(solve({12, 2, 2, 10, 12, 1, 5, 9, 15, 2, 4, 7, 7, 14, 8, 10, 1, 6, 7, 6, 13, 15, 10, 6, 2, 11, 13, 1, 15, 14, 8, 8, 4, 7, 11, 12, 3, 15, 9, 2, 13, 1, 7, 11, 2, 1, 13, 11, 8, 14, 2, 2, 12, 7, 13, 4, 13, 3, 13, 3, 11, 1, 7, 13, 15, 8, 12, 4, 12, 4, 1, 4, 9, 3, 13, 12, 10, 15, 14, 10, 7, 7, 7, 2, 7, 6, 10}) == 580);

  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.precision(13);
  cout.setf(ios::fixed);
  srand((unsigned int)time(NULL));
   
  i64 n;
  
  while(cin >> n) {
    vi64 a(n);
    
    FI(n) {
      cin >> a[i];
    }
    
    cout << solve(a) << endl;
  }


  return 0;
}

