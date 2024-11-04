



















using namespace std;

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
typedef vector<vi32> vvi32;
typedef vector<vi64> vvi64;
typedef vector<vector<vi64>> vvvi64;
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
  const T &id2;
  const function<T(const T&, const T&)> modification;
  const T &id6;
  
  SegmentTree() {}
  
  SegmentTree(const i64 n,
              Function operation,
              const T &id2=T(),
              Function modification=assign<T>,
              const T &id6=T()
  ) :
    n(n),
    t(n << 1, id2),
    operation(operation),
    id2(id2),
    modification(modification),
    id6(id6)
  {
    build();
  }
    
  template < class Iterator >
  SegmentTree(const Iterator &begin,
              const Iterator &end,
              Function operation,
              const T &id2=T(),
              Function modification=assign<T>,
              const T &id6=T()
  ) : SegmentTree(end - begin,
                  operation,
                  id2,
                  modification,
                  id6)
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

    T res = id2;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
        if (l&1) res = operation(res, t[l++]);
        if (r&1) res = operation(res, t[--r]);
    }
    return res;
  }
};

template < i64 ALPHA >
class id5
{
public:
  static const i64 id3;
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

    Node(i64 parent = id3, i64 parentCharacter = ALPHA) :
    leaf(false),
    parent(parent),
    parentCharacter(parentCharacter),
    link(id3),
    outputFunction(id3)
    {
      fill_n(next, ALPHA, id3);
      fill_n(go, ALPHA, id3);
    }
  };

  vector<Node> tree = vector<Node>(1);

  id5(){}
  id5(i64 id7)
  {
    tree.reserve(id7);
  }

  template < class Iterator >
  i64 add(i64 length, const Iterator begin)
  {
    i64 vertex = ROOT;

    for (i64 i = 0; i < length; ++i)
    {
      if (id3 == tree[vertex].next[begin[i]])
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

    if (id3 == tree[vertex].link)
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

    if (id3 == tree[vertex].go[character])
    {
      if (id3 == tree[vertex].next[character])
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

    if (id3 == tree[vertex].outputFunction)
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

template < i64 ALPHA > const i64 id5<ALPHA>::id3 = -1;
template < i64 ALPHA > const i64 id5<ALPHA>::ROOT = 0;

const i64 ALPHA = 'n' - 'a' + 1;
const char MISSING = '?' - 'a';

string encode(string s) {
  transform(ALL(s), s.begin(), [&](char c) { return c - 'a'; });
  return s;
}

const i64 INF = numeric_limits<i64>::max() / 2;

i64 solve(vector<pair<string, i64>> tc, string s) {
  transform(ALL(tc), tc.begin(), [&](const auto &tc){return make_pair(encode(tc.first), tc.second); });
  s = encode(s);
  
  id5<ALPHA> ac;
  vi64 id8;
  
  for (const auto &[t, c] : tc) {
    auto v = ac.add(SZ(t), t.begin());
    id8.resize(max(1LL + v, SZ(id8)), 0LL);
    id8[v] += c;
  }
  
  vi64 id4(SZ(ac.tree), -INF);
  
  id4[ac.ROOT] = id8[ac.ROOT];
  
  const function<i64(i64)> id0 = [&](const i64 &v) {
    return id4[v] > -INF ? id4[v] : (id4[v] = id8[v] + id0(ac.getLink(v)));
  };
    
  vvi64 id9(1, vi64(SZ(ac.tree), 0LL));
  vvi64 id1(1, vi64(SZ(ac.tree)));
  
  iota(ALL(id1[0]), 0LL);
  
  FI(SZ(s)) {
    if (s[i] == MISSING) {
      id9.push_back(vi64(SZ(ac.tree), 0LL));
      id1.push_back(vi64(SZ(ac.tree)));
      iota(ALL(id1.back()), 0LL);
    } else {
      FOR(j, SZ(ac.tree)) {
        id1.back()[j] = ac.go(id1.back()[j], s[i]);
        id9.back()[j] += id0(id1.back()[j]);
      }
    }
  }
    
  vvvi64 dp(2, vvi64(SZ(ac.tree), vi64(1 << ALPHA, -INF)));

  dp[0][id1[0][ac.ROOT]][0] = id9[0][ac.ROOT];
  
  FI(SZ(id9) - 1) {
    dp[(i + 1) & 1] = vvi64(SZ(ac.tree), vi64(1 << ALPHA, -INF));
    FOR(v, SZ(ac.tree)) {
      FOR(mask, 1 << ALPHA) {
        if (dp[i & 1][v][mask] > -INF) {
          FOR(j, ALPHA) {
            if (!((mask >> j) & 1)) {
              auto next_mask = mask | (1 << j);
              auto u = ac.go(v, j);
              auto w = id1[1 + i][u];
              dp[(i + 1) & 1][w][next_mask] = max(dp[(i + 1) & 1][w][next_mask],
                                            dp[i & 1][v][mask] + id0(u) + id9[i + 1][u]);
            }
          }
        }
      }
    }
  }
  
  i64 answer = -INF;
    
  FOR(v, SZ(ac.tree)) {
    auto current = *max_element(ALL(dp[(SZ(id9) - 1) & 1][v]));
    answer = max(answer, current);
  }
  
  return answer;
}


i64 f(const string &needle, const string &s) {
  i64 answer = 0;
  
  for (i64 pos = s.find(needle); pos != string::npos; pos = s.find(needle, pos + 1)) {
    ++answer;
  }
  
  return answer;
}

i64 aux(const vector<pair<string, i64>> &tc, const string &s) {
  i64 answer = 0;
  
  for(const auto &[t, c] : tc) {
    answer += c * f(t, s);
  }
  
  return answer;
}

i64 bf(const vector<pair<string, i64>> &tc, i64 i, i64 used, string &s) {
  if (i == SZ(s)) {
    return aux(tc, s);
  }
  
  if (s[i] != '?') {
    return bf(tc, i + 1, used, s);
  }
  
  i64 answer = -INF;
  
  FOR(j, ALPHA) {
    if (0 == ((used >> j) & 1)) {
      s[i] = j + 'a';
      answer = max(answer, bf(tc, i, used | (1 << j), s));
    }
  }
  
  s[i] = '?';
  
  return answer;
}

i64 bf(const vector<pair<string, i64>> &tc, string s) {
  auto answer = bf(tc, 0, 0, s);
  return answer;
}

pair<vector<pair<string, i64>>, string> generate() {
  const i64 k = random(1, 3);
  vector<pair<string, i64>> tc(k);
    
  FI(k) {
    string t(random(1, 5), '\0');
    
    FI(SZ(t)) {
      t[i] = random('a', 'e');
    }
    
    tc[i] = {t, random(-10, 10)};
  }
  
  string s(random(1, 5), '\0');
  
  FI(SZ(s)){
    s[i] = random('a', 'f');
    
    if (s[i] == 'f') {
      s[i] = '?';
    }
  }
  
  return {tc, s};
}
void stress() {
  while(true) {
    const auto &[tc, s] = generate();
    const auto a = bf(tc, s);
    const auto o = solve(tc, s);
    assert(a == o);
  }
}



int main(int argc, const char * argv[]) {

  assert(7 == solve({
    {"bc", 7},
    {"a", -9},
  }, "?c"));
assert(5 == bf({
  {"abc", -10},
  {"a", 1},
  {"b", 1},
  {"c", 3},
}, "?b?"));
assert(2 == bf({
  {"a", 1},
  {"a", 1},
}, "?"));
assert(8 == bf({
  {"a", 1},
  {"b", 3},
  {"ab", 4},
}, "ab"));
assert(2 == solve({
  {"a", 1},
  {"a", 1},
}, "?"));
assert(8 == solve({
  {"a", 1},
  {"b", 3},
  {"ab", 4},
}, "ab"));
assert(5 == solve({
  {"abc", -10},
  {"a", 1},
  {"b", 1},
  {"c", 3},
}, "?b?"));
  stress();

  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.precision(13);
  cout.setf(ios::fixed);
  srand((unsigned int)time(NULL));
   
  i64 k;
  
  while (cin >> k) {
    vector<pair<string, i64>> t(k);
    
    FI(k) {
      cin >> t[i].first >> t[i].second;
    }
    
    string s;
    
    cin >> s;
    
    cout << solve(t, s) << endl;
  }
  

  return 0;
}

