





using namespace std;

using ll = long long;
using pi = pair<ll, ll>;
using vi = vector<ll>;
using u32 = unsigned int;
using u64 = unsigned long long;
using i128 = __int128;

template <class T>
using vc = vector<T>;
template <class T>
using vvc = vector<vc<T>>;
template <class T>
using vvvc = vector<vvc<T>>;
template <class T>
using vvvvc = vector<vvvc<T>>;
template <class T>
using vvvvvc = vector<vvvvc<T>>;
template <class T>
using pq = priority_queue<T>;
template <class T>
using pqg = priority_queue<T, vector<T>, greater<T>>;



  vector<vector<type>> name(h, vector<type>(id0))

  vector<vector<vector<type>>> name( \
      h, vector<vector<type>>(w, vector<type>(id0)))

  vector<vector<vector<vector<type>>>> name( \
      a, vector<vector<vector<type>>>(       \
             b, vector<vector<type>>(c, vector<type>(id0))))














  id2(id0, FOR4_R, FOR3_R, FOR2_R, FOR1_R)(id0)














ll SUM(vector<int> &A) {
  ll sum = 0;
  for (auto &&a: A) sum += a;
  return sum;
}

template <typename T>
T SUM(vector<T> &A) {
  T sum = T(0);
  for (auto &&a: A) sum += a;
  return sum;
}







int popcnt(int x) { return __builtin_popcount(x); }
int popcnt(u32 x) { return __builtin_popcount(x); }
int popcnt(ll x) { return __builtin_popcountll(x); }
int popcnt(u64 x) { return __builtin_popcountll(x); }


int topbit(int x) { return (x == 0 ? -1 : 31 - __builtin_clz(x)); }
int topbit(u32 x) { return (x == 0 ? -1 : 31 - __builtin_clz(x)); }
int topbit(ll x) { return (x == 0 ? -1 : 63 - __builtin_clzll(x)); }
int topbit(u64 x) { return (x == 0 ? -1 : 63 - __builtin_clzll(x)); }


int lowbit(int x) { return (x == 0 ? -1 : __builtin_ctz(x)); }
int lowbit(u32 x) { return (x == 0 ? -1 : __builtin_ctz(x)); }
int lowbit(ll x) { return (x == 0 ? -1 : __builtin_ctzll(x)); }
int lowbit(u64 x) { return (x == 0 ? -1 : __builtin_ctzll(x)); }

template <typename T, typename U>
T ceil(T x, U y) {
  return (x > 0 ? (x + y - 1) / y : x / y);
}

template <typename T, typename U>
T floor(T x, U y) {
  return (x > 0 ? x / y : (x - y + 1) / y);
}

template <typename T, typename U>
pair<T, T> divmod(T x, U y) {
  T q = floor(x, y);
  return {q, x - q * y};
}

ll binary_search(function<bool(ll)> check, ll ok, ll ng) {
  assert(check(ok));
  while (abs(ok - ng) > 1) {
    auto x = (ng + ok) / 2;
    if (check(x))
      ok = x;
    else
      ng = x;
  }
  return ok;
}

template <typename F>
double id3(F check, double ok, double ng, int iter = 100) {
  FOR(iter) {
    double x = (ok + ng) / 2;
    if (check(x)) {
      ok = x;
    } else {
      ng = x;
    }
  }
  return (ok + ng) / 2;
}

template <class T, class S>
inline bool chmax(T &a, const S &b) {
  return (a < b ? a = b, 1 : 0);
}
template <class T, class S>
inline bool chmin(T &a, const S &b) {
  return (a > b ? a = b, 1 : 0);
}

vi id4(const string &S, char first_char) {
  vi A(S.size());
  FOR(i, S.size()) { A[i] = S[i] - first_char; }
  return A;
}

template <typename T>
vector<T> cumsum(vector<T> &A, int off = 1) {
  int N = A.size();
  vector<T> B(N + 1);
  FOR(i, N) { B[i + 1] = B[i] + A[i]; }
  if (off == 0) B.erase(B.begin());
  return B;
}

template <typename CNT, typename T>
vc<CNT> id6(const vc<T> &A, int size) {
  vc<CNT> C(size);
  for (auto &&x: A) { ++C[x]; }
  return C;
}

template <typename T>
vector<int> argsort(const vector<T> &A) {
  

  vector<int> ids(A.size());
  iota(all(ids), 0);
  sort(all(ids),
       [&](int i, int j) { return A[i] < A[j] || (A[i] == A[j] && i < j); });
  return ids;
}



template <typename T>
vc<T> id5(const vc<T> &A, const vc<int> &I) {
  int n = len(I);
  vc<T> B(n);
  FOR(i, n) B[i] = A[I[i]];
  return B;
}





namespace detail {
template <typename T, decltype(&T::is_modint) = &T::is_modint>
std::true_type check_value(int);
template <typename T>
std::false_type check_value(long);
} 


template <typename T>
struct is_modint : decltype(detail::check_value<T>(0)) {};
template <typename T>
using is_modint_t = enable_if_t<is_modint<T>::value>;
template <typename T>
using is_not_modint_t = enable_if_t<!is_modint<T>::value>;

struct Scanner {
  FILE *fp;
  char line[(1 << 15) + 1];
  size_t st = 0, ed = 0;
  void reread() {
    memmove(line, line + st, ed - st);
    ed -= st;
    st = 0;
    ed += fread(line + ed, 1, (1 << 15) - ed, fp);
    line[ed] = '\0';
  }
  bool succ() {
    while (true) {
      if (st == ed) {
        reread();
        if (st == ed) return false;
      }
      while (st != ed && isspace(line[st])) st++;
      if (st != ed) break;
    }
    if (ed - st <= 50) {
      bool sep = false;
      for (size_t i = st; i < ed; i++) {
        if (isspace(line[i])) {
          sep = true;
          break;
        }
      }
      if (!sep) reread();
    }
    return true;
  }
  template <class T, enable_if_t<is_same<T, string>::value, int> = 0>
  bool read_single(T &ref) {
    if (!succ()) return false;
    while (true) {
      size_t sz = 0;
      while (st + sz < ed && !isspace(line[st + sz])) sz++;
      ref.append(line + st, sz);
      st += sz;
      if (!sz || st != ed) break;
      reread();
    }
    return true;
  }
  template <class T, enable_if_t<is_integral<T>::value, int> = 0>
  bool read_single(T &ref) {
    if (!succ()) return false;
    bool neg = false;
    if (line[st] == '-') {
      neg = true;
      st++;
    }
    ref = T(0);
    while (isdigit(line[st])) { ref = 10 * ref + (line[st++] & 0xf); }
    if (neg) ref = -ref;
    return true;
  }
  template <class T, is_modint_t<T> * = nullptr>
  bool read_single(T &ref) {
    long long val = 0;
    bool f = read_single(val);
    ref = T(val);
    return f;
  }
  bool read_single(double &ref) {
    string s;
    if (!read_single(s)) return false;
    ref = std::stod(s);
    return true;
  }
  bool read_single(char &ref) {
    string s;
    if (!read_single(s) || s.size() != 1) return false;
    ref = s[0];
    return true;
  }
  template <class T>
  bool read_single(vector<T> &ref) {
    for (auto &d: ref) {
      if (!read_single(d)) return false;
    }
    return true;
  }
  template <class T, class U>
  bool read_single(pair<T, U> &p) {
    return (read_single(p.first) && read_single(p.second));
  }
  template <class A, class B, class C>
  bool read_single(tuple<A, B, C> &p) {
    return (read_single(get<0>(p)) && read_single(get<1>(p))
            && read_single(get<2>(p)));
  }
  template <class A, class B, class C, class D>
  bool read_single(tuple<A, B, C, D> &p) {
    return (read_single(get<0>(p)) && read_single(get<1>(p))
            && read_single(get<2>(p)) && read_single(get<3>(p)));
  }
  void read() {}
  template <class H, class... T>
  void read(H &h, T &... t) {
    bool f = read_single(h);
    assert(f);
    read(t...);
  }
  Scanner(FILE *fp) : fp(fp) {}
};

struct Printer {
  Printer(FILE *_fp) : fp(_fp) {}
  ~Printer() { flush(); }

  static constexpr size_t SIZE = 1 << 15;
  FILE *fp;
  char line[SIZE], small[50];
  size_t pos = 0;
  void flush() {
    fwrite(line, 1, pos, fp);
    pos = 0;
  }
  void write(const char &val) {
    if (pos == SIZE) flush();
    line[pos++] = val;
  }
  template <class T, enable_if_t<is_integral<T>::value, int> = 0>
  void write(T val) {
    if (pos > (1 << 15) - 50) flush();
    if (val == 0) {
      write('0');
      return;
    }
    if (val < 0) {
      write('-');
      val = -val; 

    }
    size_t len = 0;
    while (val) {
      small[len++] = char(0x30 | (val % 10));
      val /= 10;
    }
    for (size_t i = 0; i < len; i++) { line[pos + i] = small[len - 1 - i]; }
    pos += len;
  }
  void write(const string &s) {
    for (char c: s) write(c);
  }
  void write(const char *s) {
    size_t len = strlen(s);
    for (size_t i = 0; i < len; i++) write(s[i]);
  }
  void write(const double &x) {
    ostringstream oss;
    oss << fixed << setprecision(15) << x;
    string s = oss.str();
    write(s);
  }
  void write(const long double &x) {
    ostringstream oss;
    oss << fixed << setprecision(15) << x;
    string s = oss.str();
    write(s);
  }
  template <class T, is_modint_t<T> * = nullptr>
  void write(T &ref) {
    write(ref.val);
  }
  template <class T>
  void write(const vector<T> &val) {
    auto n = val.size();
    for (size_t i = 0; i < n; i++) {
      if (i) write(' ');
      write(val[i]);
    }
  }
  template <class T, class U>
  void write(const pair<T, U> &val) {
    write(val.first);
    write(' ');
    write(val.second);
  }
  template <class A, class B, class C>
  void write(const tuple<A, B, C> &val) {
    auto &[a, b, c] = val;
    write(a), write(' '), write(b), write(' '), write(c);
  }
  template <class A, class B, class C, class D>
  void write(const tuple<A, B, C, D> &val) {
    auto &[a, b, c, d] = val;
    write(a), write(' '), write(b), write(' '), write(c), write(' '), write(d);
  }
  template <class A, class B, class C, class D, class E>
  void write(const tuple<A, B, C, D, E> &val) {
    auto &[a, b, c, d, e] = val;
    write(a), write(' '), write(b), write(' '), write(c), write(' '), write(d), write(' '), write(e);
  }
  template <class A, class B, class C, class D, class E, class F>
  void write(const tuple<A, B, C, D, E, F> &val) {
    auto &[a, b, c, d, e, f] = val;
    write(a), write(' '), write(b), write(' '), write(c), write(' '), write(d), write(' '), write(e), write(' '), write(f);
  }
  template <class T, size_t S>
  void write(const array<T, S> &val) {
    auto n = val.size();
    for (size_t i = 0; i < n; i++) {
      if (i) write(' ');
      write(val[i]);
    }
  }
  void write(i128 val) {
    string s;
    bool negative = 0;
    if(val < 0){
      negative = 1;
      val = -val;
    }
    while (val) {
      s += '0' + int(val % 10);
      val /= 10;
    }
    if(negative) s += "-";
    reverse(all(s));
    if (len(s) == 0) s = "0";
    write(s);
  }
};

Scanner scanner = Scanner(stdin);
Printer printer = Printer(stdout);

void flush() { printer.flush(); }
void print() { printer.write('\n'); }
template <class Head, class... Tail>
void print(Head &&head, Tail &&... tail) {
  printer.write(head);
  if (sizeof...(Tail)) printer.write(' ');
  print(forward<Tail>(tail)...);
}

void read() {}
template <class Head, class... Tail>
void read(Head &head, Tail &... tail) {
  scanner.read(head);
  read(tail...);
}


  int id0; \
  read(id0)

  ll id0; \
  read(id0)

  string id0; \
  read(id0)

  char id0; \
  read(id0)

  double id0; \
  read(id0)


  vector<type> name(size);    \
  read(name)

  vector<vector<type>> name(h, vector<type>(w)); \
  read(name)

void YES(bool t = 1) { print(t ? "YES" : "NO"); }
void NO(bool t = 1) { YES(!t); }
void Yes(bool t = 1) { print(t ? "Yes" : "No"); }
void No(bool t = 1) { Yes(!t); }
void yes(bool t = 1) { print(t ? "yes" : "no"); }
void no(bool t = 1) { yes(!t); }

template <typename Cap>
struct id1 {
  struct Edge {
    int to, rev;
    Cap cap;
  };

  const Cap INF;
  int N;
  vvc<Edge> G;
  vc<int> prog, level;
  Cap flow_ans;
  bool calculated;

  id1(int N, Cap INF) : INF(INF), N(N), calculated(0) {}

  void add(int frm, int to, Cap cap) {
    assert(0 <= frm && frm < N);
    assert(0 <= to && to < N);
    assert(Cap(0) <= cap);
    if (len(G) < N) G.resize(N);
    G[frm].eb(Edge{to, (int)G[to].size(), cap});
    G[to].eb(Edge{frm, (int)G[frm].size() - 1, 0});
  }

  Cap flow(int source, int sink) {
    if (calculated) return flow_ans;
    calculated = true;
    chmax(N, source + 1);
    chmax(N, sink + 1);
    G.resize(N);
    flow_ans = 0;
    while (set_level(source, sink)) {
      fill(all(prog), 0);
      prog.assign(N, 0);
      while (1) {
        Cap x = flow_dfs(source, sink, INF);
        if (x == 0) break;
        flow_ans += x;
        chmin(flow_ans, INF);
        if (flow_ans == INF) return flow_ans;
      }
    }
    return flow_ans;
  }

  

  pair<Cap, vc<int>> cut(int source, int sink) {
    Cap f = flow(source, sink);
    vc<int> res(N);
    FOR(v, N) res[v] = (level[v] >= 0 ? 0 : 1);
    return {f, res};
  }

  

  vc<tuple<int, int, Cap>> get_edges() {
    vc<tuple<int, int, Cap>> edges;
    FOR(v, N) for (auto&& e: G[v]) { edges.eb(v, e.to, e.cap); }
    return edges;
  }

private:
  bool set_level(int source, int sink) {
    level.assign(N, -1);
    level[source] = 0;
    queue<int> que;
    que.push(source);
    while (!que.empty()) {
      int v = que.front();
      que.pop();
      for (auto&& e: G[v]) {
        if (e.cap > 0 && level[e.to] == -1) {
          level[e.to] = level[v] + 1;
          if (e.to == sink) return true;
          que.push(e.to);
        }
      }
    }
    return false;
  }

  Cap flow_dfs(int v, int sink, Cap lim) {
    if (v == sink) return lim;
    Cap res = 0;
    for (int& i = prog[v]; i < (int)G[v].size(); ++i) {
      auto& e = G[v][i];
      if (e.cap > 0 && level[e.to] == level[v] + 1) {
        Cap a = flow_dfs(e.to, sink, min(lim, e.cap));
        if (a > 0) {
          e.cap -= a;
          G[e.to][e.rev].cap += a;
          res += a;
          lim -= a;
          if (lim == 0) break;
        }
      }
    }
    return res;
  }
};


void solve() {
  LL(N, M);

  const ll INF = 1LL << 30;
  id1<ll> G(M + N + 3, INF);

  int source = 0;
  int t = N + M + 1;
  int sink = N + M + 2;

  auto eid = [&](int i) -> int { return 1 + i; };
  auto vid = [&](int i) -> int { return 1 + M + i; };

  VEC(ll, S, N);
  VEC(ll, A, N);
  vi deg(N);
  VEC(pi, E, M);
  for (auto&& [a, b]: E) --a, --b;
  for (auto&& [a, b]: E) deg[a]++, deg[b]++;

  

  vi indeg(N);

  FOR(i, N) {
    if (S[i] == 0) continue;
    if ((deg[i] + A[i]) % 2 == 1) return NO();
    indeg[i] = (deg[i] + A[i]) / 2;
    if (indeg[i] > deg[i]) return NO();
    if (indeg[i] < 0) return NO();
  }

  ll K = M - SUM(indeg);
  if (K < 0) return NO();

  G.add(t, sink, K);
  FOR(v, N) {
    if (S[v] == 1) { G.add(vid(v), sink, indeg[v]); }
    if (S[v] == 0) { G.add(vid(v), t, K); }
  }
  FOR(i, M) G.add(source, eid(i), 1);
  FOR(i, M) {
    auto [a, b] = E[i];
    G.add(eid(i), vid(a), 1);
    G.add(eid(i), vid(b), 1);
  }

  auto f = G.flow(source, sink);
  if (f != M) return NO();
  YES();
  for (auto&& [frm, to, cap]: G.get_edges()) {
    if (cap) continue;
    if (eid(0) <= frm && frm < eid(M) && vid(0) <= to && to < vid(N)) {
      auto [a, b] = E[frm - 1];
      to -= vid(0);
      assert(a == to || b == to);
      ll x = a + b - to;
      ll y = to;
      print(x + 1, y + 1);
    }
  }
}

signed main() {
  cout << fixed << setprecision(15);

  ll T = 1;
  

  FOR(T) solve();

  return 0;
}
