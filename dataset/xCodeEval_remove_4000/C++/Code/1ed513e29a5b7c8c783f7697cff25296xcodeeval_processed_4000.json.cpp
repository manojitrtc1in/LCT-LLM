
using namespace std;














  OVERLOAD(_0 id0(, )
  (__VA_ARGS__)


  OVERLOAD(_0 id0(, )
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



















using ll = long long;
using ld = long double;
using pii = pair<int, int>;

using di = deque<int>;
using dll = deque<ll>;
using dpii = deque<pii>;











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


string indent;

void _E() { cerr << endl; }
template <class ARG, class... ARGS> void _E(ARG &&arg, ARGS &&...args) {
  cerr << std::forward<ARG>(arg) << " ";
  _E(std::forward<ARGS>(args)...);
}


  {                                                                            \
    cerr << indent << "[" << __LINE__ << "] ";                                 \
    _E(__VA_ARGS__);                                                           \
  }









struct Indenter {
  Indenter() { FOR(INDENT_SIZE) indent.push_back(' '); }
  ~Indenter() { FOR(INDENT_SIZE) indent.pop_back(); }
};


  {                                                                            \
    cerr << "ASSERT FAILED   " << str << "   " << __FILE__ << ':' << __LINE__  \
         << endl;                                                              \
    abort();                                                                   \
  }







  {}

  {}

  {}





  if (!(cond))                                                                 \
  FAIL(


  if (!(res))                                                                  \
  FAIL(









  if (!(a <= x && x < b))                                                      \
  FAIL(

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


  for (auto m = mask, bit = lsb(m); m; m ^= (1 << b), bit = lsb(m))


  for (auto s = mask; s; s = (s - 1) & mask) 


template <class T> int log2up(T x) { return x <= 1 ? 0 : msb(x - 1) + 1; }

default_random_engine RNG(123);




template <class T> T read() {
  T x;
  cin >> x;
  return x;
}



void _I() {}
template <class ARG, class... ARGS> void _I(ARG &&arg, ARGS &&...args) {
  cin >> arg;
  _I(forward<ARGS>(args)...);
}




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


























































































const bool id1 = 1;

struct id2 {
  struct Pt {
    array<int, 2> x;
    int c;
    bool operator<(const Pt &o) const { return x < o.x; }
  };
  deq<Pt> pts;

  ll n, m, k, q;
  dll in;

  struct V {
    struct VE {
      int dest;
      int orig;
    };
    struct VE2 {
      int dest;
      int w;
    };
    vec<VE> out;
    vec<VE2> out2;
    int w = -1;
  };
  vec<V> vs;

  vector<bool> vis;

  bool dfs(int v) {
    if (vis[v])
      return true;

    vis[v] = 1;

    if (vs[v].w == -1)
      vs[v].w = 0;

    for (auto ve : vs[v].out2) {
      int want = vs[v].w ^ ve.w;
      if (vs[ve.dest].w > -1 && vs[ve.dest].w != want)
        return false;

      vs[ve.dest].w = want;
      auto r = dfs(ve.dest);
      if (!r)
        return false;
    }

    return 1;
  }

  void dfs_print(int v, int p) {
    for (auto ve : vs[v].out)
      if (ve.dest != p) {
        OO(v + 1, ve.dest + 1)
        if (ve.orig > -1)
          O(ve.orig)
        else
          O(vs[ve.dest].w ^ vs[v].w);
        dfs_print(ve.dest, v);
      }
  }

  id2() {
    I(n, m)
    

    vs.resize(n);
    vis.resize(n);

    auto add = [&](int a, int b, int w) {
      w = popcount(w) % 2;
      vs[a].out2.push({b, w});
      vs[b].out2.push({a, w});
    };

    FOR(n - 1) {
      int a = II - 1;
      int b = II - 1;
      int w = II;
      vs[a].out.push({b, w});
      vs[b].out.push({a, w});
      if (w > -1) {
        add(a, b, w);
      }
    }

    FOR(m) {
      int a = II - 1;
      int b = II - 1;
      int w = II;
      add(a, b, w);
    }
    


    bool good = true;

    FOR(i, n) if (!dfs(i)) good = false;

    if (good) {
      O("YES")
      dfs_print(0, -1);
    } else
      O("NO")
  }

  int yes = -1;
};


















int main() {

  signal(SIGSEGV, handler);
  signal(SIGABRT, handler);

  ios_base::sync_with_stdio(0);
  cout.precision(20);
  cout << fixed;

  int num_cases = 1;
  if (id1)
    cin >> num_cases;

  FOR(i, num_cases) {
    E()
    E("TEST CASE", i + 1)
    INDENT
    id2 tc;
    if (tc.yes != -1)
      O(tc.yes ? "YES" : "NO")
  }

  return 0;
}
