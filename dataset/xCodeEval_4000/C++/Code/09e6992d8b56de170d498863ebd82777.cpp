#include <bits/stdc++.h>
using namespace std;



#define FOR_3(i, a, b) for (int i = (a), bb##i = (b); i < bb##i; ++i)
#define FORR_3(i, a, b) for (int i = (b)-1, aa##i = (a); i >= aa##i; --i)

#define FOR_2(i, n) FOR_3(i, 0, n)
#define FORR_2(i, n) FORR_3(i, 0, n)

#define FOR_1(n) FOR_2(_i##__LINE__, n)
#define FOR_0() for (;;)

#define OVERLOAD(_0, _1, _2, _3, NAME, ...) NAME
#define FOR(...)                                                               \
  OVERLOAD(_0 __VA_OPT__(, )##__VA_ARGS__, FOR_3, FOR_2, FOR_1, FOR_0)         \
  (__VA_ARGS__)

#define FORR(...)                                                              \
  OVERLOAD(_0 __VA_OPT__(, )##__VA_ARGS__, FORR_3, FORR_2, FORR_1, FOR_0)      \
  (__VA_ARGS__)




template <class T> auto min(T &&t) { return move(t); };
template <class T, class... TS> auto min(T &&t, TS &&...ts) {
  auto rest = min(forward<TS>(ts)...);
  return t < rest ? t : rest;
}

template <class T> auto max(T &&t) { return move(t); };
template <class T, class... TS> auto max(T &&t, TS &&...ts) {
  auto rest = max(forward<TS>(ts)...);
  return t > rest ? t : rest;
}

#define REMIN(a, b) ((a) = min(a, b));
#define REMAX(a, b) ((a) = max(a, b));



#define ALL(c) (c).begin(), (c).end()
#define SZ(x) int((x).size())
#define ZERO(x) memset(x, 0, sizeof(x));



#define UNUSED(...) (void)(__VA_ARGS__);



#define umap unordered_map
#define vec vector
#define deq deque
using ll = long long;
using ld = long double;
using pii = pair<int, int>;

using vi = vec<int>;
using vll = vec<ll>;
using vpii = vec<pii>;
using vb = vec<bool>;

using di = deq<int>;
using dll = deq<ll>;
using dpii = deq<pii>;



#define push push_back
#define pop pop_back
#define CMP bool operator<(const auto &o) const



#define SORT(v) sort(ALL(v));
#define UNIQUE(c)                                                              \
  {                                                                            \
    SORT(c);                                                                   \
    c.erase(unique(ALL(c)), c.end());                                          \
  }

auto PERM(int n) {
  di v(n);
  FOR(i, n) v[i] = i;
  return v;
}

template <class V> auto esort(const V &v) {
  auto perm = PERM(SZ(v));
  sort(ALL(perm), [&](int a, int b) { return v[a] < v[b]; });
  return perm;
}

template <class V> auto eremap(V &&vv) {
  auto v = move(vv);
  SORT(v);
  umap<typename V::value_type, int> r;
  int nxt = 0;
  for (auto &e : v)
    if (r.emplace(e, nxt).second)
      ++nxt;
  return r;
}

template <class X, class FR, class TO>
bool range(const X &x, const FR &fr, const TO &to) {
  return !(x < fr) && x < to;
}

#ifdef LOCAL
#include <sys/prctl.h>
#include <sys/wait.h>
#include <unistd.h>

void print_trace() {
  char pid_buf[30];
  sprintf(pid_buf, "%d", getpid());
  char name_buf[512];
  name_buf[readlink("/proc/self/exe", name_buf, 511)] = 0;
  prctl(PR_SET_PTRACER, PR_SET_PTRACER_ANY, 0, 0, 0);
  int child_pid = fork();
  if (!child_pid) {
    dup2(2, 1); 

    execl("/usr/bin/gdb", "gdb", "--batch", "-n", "-ex", "thread", "-ex", "bt",
          name_buf, pid_buf, NULL);
    abort(); 
  } else {
    waitpid(child_pid, NULL, 0);
  }
}

extern const char *const sys_siglist[];

void handler(int sig) {
  cerr << "SIGNAL " << sig << " (" << sys_siglist[sig] << ")" << endl;
  print_trace();
  exit(1);
}

#define INDENT_SIZE 2
string indent;

void _E() { cerr << endl; }
template <class ARG, class... ARGS> void _E(ARG &&arg, ARGS &&...args) {
  cerr << std::forward<ARG>(arg) << " ";
  _E(std::forward<ARGS>(args)...);
}

#define ERR(...)                                                               \
  {                                                                            \
    cerr << indent << "[" << __LINE__ << "] ";                                 \
    _E(__VA_ARGS__);                                                           \
  }

#define _V5(x) #x, "==", (x)
#define _V4(x, ...) #x, "==", (x)__VA_OPT__(, "|", _V5(__VA_ARGS__))
#define _V3(x, ...) #x, "==", (x)__VA_OPT__(, "|", _V4(__VA_ARGS__))
#define _V2(x, ...) #x, "==", (x)__VA_OPT__(, "|", _V3(__VA_ARGS__))
#define _V1(x, ...) #x, "==", (x)__VA_OPT__(, "|", _V2(__VA_ARGS__))
#define ERRV(...) ERR(_V1(__VA_ARGS__))
#define INDENT auto _indenter = Indenter();

struct Indenter {
  Indenter() { FOR(INDENT_SIZE) indent.push_back(' '); }
  ~Indenter() { FOR(INDENT_SIZE) indent.pop_back(); }
};

#define FAIL(str)                                                              \
  {                                                                            \
    cerr << "ASSERT FAILED   " << str << "   " << __FILE__ << ':' << __LINE__  \
         << endl;                                                              \
    abort();                                                                   \
  }

#define SLEEP this_thread::sleep_for(100ms);

#else
#define INDENT
#define SLEEP
#define FAIL(x)                                                                \
  {}
#define ERR(...)                                                               \
  {}
#define ERRV(...)                                                              \
  {}
#endif



#define CHECK(cond)                                                            \
  if (!(cond))                                                                 \
  FAIL(#cond)

#define CHECK_OP(op, a, b, res)                                                \
  if (!(res))                                                                  \
  FAIL(#a " " op " " #b "   (" + to_string(a) + " vs " + to_string(b) + ")")

#define CHECK_EQ(a, b) CHECK_OP("==", a, b, (a) == (b))
#define CHECK_NE(a, b) CHECK_OP("!=", a, b, (a) != (b))
#define CHECK_LE(a, b) CHECK_OP("<=", a, b, (a) <= (b))
#define CHECK_GE(a, b) CHECK_OP(">=", a, b, (a) >= (b))
#define CHECK_LT(a, b) CHECK_OP("<", a, b, (a) < (b))
#define CHECK_GT(a, b) CHECK_OP(">", a, b, (a) > (b))

#define CHECK_RANGE(x, a, b)                                                   \
  if (!(a <= x && x < b))                                                      \
  FAIL(#x " in [" #a "," #b ")")

template <class A, class B> auto divup(A a, B b) { return (a + b - 1) / b; }



int msb(int x) {
  CHECK_GT(x, 0)
  return 31 - __builtin_clz(x);
}

int msb(ll x) {
  CHECK_GT(x, 0)
  return 63 - __builtin_clzll(x);
}

int lsb(int x) {
  CHECK_GT(x, 0)
  return __builtin_ctz(x);
}

int lsb(ll x) {
  CHECK_GT(x, 0)
  return __builtin_ctzll(x);
}

int popcount(int x) { return __builtin_popcount(x); }
int popcount(ll x) { return __builtin_popcountll(x); }

#define FORB(b, mask)                                                          \
  for (auto m = mask, bit = lsb(m); m; m ^= (1 << b), bit = lsb(m))

#define FORS(s, mask)                                                          \
  for (auto s = mask; s; s = (s - 1) & mask) 


template <class T> int log2up(T x) { return x <= 1 ? 0 : msb(x - 1) + 1; }

default_random_engine RNG(123);
#define SHUFFLE(c) shuffle(ALL(c), RNG);



template <class T> T read() {
  T x;
  cin >> x;
  return x;
}
#define II read<int>()
#define ILL read<ll>()

void _I() {}
template <class ARG, class... ARGS> void _I(ARG &&arg, ARGS &&...args) {
  cin >> arg;
  _I(forward<ARGS>(args)...);
}
#define I(...) _I(__VA_ARGS__);



template <class T> void _print(T x) {
  cout << x;
  bool space = true;
  if constexpr (is_same_v<T, char>) {
    if (x == '\n')
      space = false;
  }
  if (space)
    cout << " ";
}
template <class T> void _print(deq<T> &d) {
  for (auto &e : d)
    cout << e << " ";
}
void _O() {}
template <class ARG, class... ARGS> void _O(ARG &&arg, ARGS &&...args) {
  _print(arg);
  _O(forward<ARGS>(args)...);
}
#define O(...) _O(__VA_ARGS__ __VA_OPT__(, ) '\n');
#define OO(...) _O(__VA_ARGS__);



template <class T> auto &operator<<(ostream &os, deq<T> &v) {
  os << "{";
  bool first = true;
  for (auto &e : v) {
    if (first)
      first = false;
    else
      os << " ";
    os << e;
  }
  return os << "}";
}

template <class A, class B> auto &operator<<(ostream &os, pair<A, B> &p) {
  return os << "{" << p.first << " " << p.second << "}";
}










template <class V, class _E> struct Graph {
  Graph() : _p_vs(make_shared<vec<V>>()), vs(*_p_vs) {}
  template <class _EE> Graph(Graph<V, _EE> &o) : _p_vs(o._p_vs), vs(*_p_vs) {}

  shared_ptr<vec<V>> _p_vs;
  vec<V> &vs;
  vec<vi> ves;
  auto &operator[](int i) {
    CHECK_GT(i, 0);
    while (i >= SZ(vs))
      vs.emplace_back();
    while (i >= SZ(ves))
      ves.emplace_back();
    return ves[i];
  }
  int size() { return SZ(vs); }

  struct E : _E {
    E(_E &&e = _E()) : _E(move(e)) {}

    struct EV {
      int dest = -1;
      int ith = -1;
    };

    array<EV, 2> ev;
    auto &operator[](int i) { return ev[i]; }
  };
  vec<E> es;

  int dest(int v, int ve) {
    int e = ves[v][ve];
    int ith = es[e][1].dest != v;
    return es[e][ith].dest;
  }

  void e(int a, int b, _E &&_e = _E()) {
    CHECK_NE(a, b);
    operator[](a);
    operator[](b);
    ves[a].push(SZ(es));
    ves[b].push(SZ(es));
    es.emplace_back(move(_e));
    es.back()[0] = {a, SZ(ves[a]) - 1};
    es.back()[1] = {b, SZ(ves[b]) - 1};
  }
};

struct V {
  int w = -1;
};
struct E {
  int w = -1;
  int orig = -1;
};

using G = Graph<V, E>;



template <class GG> struct DFS {
  struct S {
    int v;
    int ve;
  };

  virtual void visit(GG &, int) {}
  virtual bool visit(GG &, int, int, int) { return true; }

  vb vis;

  void run(GG &g) { FOR(i, 1, SZ(g)) run(g, i); }

  void run(GG &g, int v0) {
    vis.resize(SZ(g));
    if (vis[v0])
      return;

    vec<S> s;

    s.push({v0, 0});
    vis[v0] = 1;
    visit(g, v0);

    while (!s.empty()) {
      auto [v, ve] = s.back();
      if (ve >= SZ(g[v])) {
        s.pop();
        continue;
      }
      s.back().ve++;

      int e = g.ves[v][ve];
      int dest = g.dest(v, ve);

      int p = 0;
      if (SZ(s) - 2 >= 0)
        p = s[SZ(s) - 2].v;

      if (dest != p && visit(g, v, dest, e) && !vis[dest]) {
        s.push({dest, 0});
        vis[dest] = 1;
        visit(g, dest);
      }
    }
  }
};


























































































const bool MULTIPLE_TEST_CASES = 1;

struct Dfs : DFS<G> {
  bool good = true;

  void visit(G &g, int v) {
    if (g.vs[v].w == -1)
      g.vs[v].w = 0;
  }

  bool visit(G &g, int p, int v, int e) {
    ERRV(p, v, e)
    int want = g.vs[p].w ^ g.es[e].w;
    if (g.vs[v].w > -1 && g.vs[v].w != want)
      good = false;
    g.vs[v].w = want;
    return true;
  }
};

struct Dfs_print : DFS<G> {
  bool visit(G &g, int p, int v, int e) {
    OO(p, v)
    int w = g.es[e].orig;
    if (w == -1)
      w = g.vs[v].w ^ g.vs[p].w;
    O(w)
    return true;
  }
};

struct Test_Case {
  struct Pt {
    array<int, 2> x;
    int c;
    bool operator<(const Pt &o) const { return x < o.x; }
  };
  deq<Pt> pts;

  ll n, m, k, q;
  dll in;

  Test_Case() {
    I(n, m)
    


    G g, g2(g);

    auto add = [&](int a, int b, int w) {
      w = popcount(w) % 2;
      g2.e(a, b, {w});
    };

    FOR(n - 1) {
      int a = II;
      int b = II;
      int w = II;
      g.e(a, b, {w, w});
      if (w > -1) {
        add(a, b, w);
      }
    }

    FOR(m) {
      int a = II;
      int b = II;
      int w = II;
      add(a, b, w);
    }
    


    Dfs dfs;
    dfs.run(g2);

    if (dfs.good) {
      O("YES")
      Dfs_print().run(g);
    } else
      O("NO")
  }

  int yes = -1;
};


















int main() {
#ifdef LOCAL
  signal(SIGSEGV, handler);
  signal(SIGABRT, handler);
#endif
  ios_base::sync_with_stdio(0);
  cout.precision(20);
  cout << fixed;

  int num_cases = 1;
  if (MULTIPLE_TEST_CASES)
    cin >> num_cases;

  FOR(i, num_cases) {
    ERR()
    ERR("TEST CASE", i + 1)
    INDENT
    Test_Case tc;
    if (tc.yes != -1)
      O(tc.yes ? "YES" : "NO")
  }

  return 0;
}
