
using namespace std;












  OVERLOAD(_0, 

  OVERLOAD(_0, 
















using LL = long long;
using LD = long double;
using PII = pair<int, int>;

using VI = vector<int>;
using VLL = vector<LL>;
using id0 = vector<PII>;

using DI = deque<int>;
using DLL = deque<LL>;
using id2 = deque<PII>;






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

void _P() { cerr << endl; }
template <class ARG, class... ARGS> void _P(ARG &&arg, ARGS &&...args) {
  cerr << std::forward<ARG>(arg) << " ";
  _P(std::forward<ARGS>(args)...);
}


  {                                                                            \
    cerr << indent;                                                            \
    _P(__VA_ARGS__);                                                           \
  }









struct Indenter {
  Indenter() { FOR(INDENT_SIZE) indent.push_back(' '); }
  ~Indenter() { FOR(INDENT_SIZE) indent.pop_back(); }
};


  {                                                                            \
    cerr << "ASSERT FAILED   " << str << "   " << __FILE__ << ':' << __LINE__  \
         << endl;                                                              \
    print_trace();                                                             \
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

auto PERM(int n) {
  VI v(n);
  FOR(i, n) v[i] = i;
  return v;
}



template <class V> auto esort(const V &v) {
  auto perm = PERM(SZ(v));
  sort(ALL(perm), [&](int a, int b) { return v[a] < v[b]; });
  return perm;
}

template <class V> auto remap(const V &v) {
  umap<typename V::value_type, int> r;
  int nxt = 0;
  for (auto &e : v)
    if (r.emplace(e, nxt).second)
      ++nxt;
  return r;
}

template <class A, class B> auto divup(A a, B b) { return (a + b - 1) / b; }

template <class T> T read() {
  T x;
  cin >> x;
  return x;
}



template <class V> auto &print_vector(ostream &os, V &v) {
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

template <class T> auto &operator<<(ostream &os, vector<T> &v) {
  return print_vector(os, v);
}

template <class T> auto &operator<<(ostream &os, deque<T> &v) {
  return print_vector(os, v);
}

template <class A, class B> auto &operator<<(ostream &os, pair<A, B> &p) {
  return os << "{" << p.first << " " << p.second << "}";
}



int msb(int x) {
  CHECK_GT(x, 0)
  return 31 - __builtin_clz(x);
}

int msb(LL x) {
  CHECK_GT(x, 0)
  return 31 - __builtin_clzll(x);
}

int lsb(int x) {
  CHECK_GT(x, 0)
  return __builtin_ctz(x);
}

int lsb(LL x) {
  CHECK_GT(x, 0)
  return __builtin_ctzll(x);
}

int popcount(int x) { return __builtin_popcount(x); }
int popcount(LL x) { return __builtin_popcountll(x); }


  for (auto m = mask, bit = lsb(m); m; m ^= (1 << b), bit = lsb(m))


  for (auto s = mask; s; s = (s - 1) & mask) 


auto round_up_pow2(int x) { return 1 << (msb(x - 1) + 1); }


  {                                                                            \
    SORT(c);                                                                   \
    c.erase(unique(ALL(c)), c.end());                                          \
  }




struct Mod {};

struct Agg {
  

  int size = 0;

  void apply(const Mod &mod) {
    UNUSED(mod)
    

  }
};

Agg combine(const Agg &a, const Agg &b) {
  Agg r;
  

  r.size = a.size + b.size;
  return r;
}

Mod combine(const Mod &a, const Mod &b) {
  UNUSED(a, b)
  Mod r;
  

  return r;
}



template <class AGG, class MOD> struct Splay {

  int index_of(int v) {
    splay(v);
    return vs[v].c[0] ? vs[vs[v].c[0]].agg.size : 0;
  }
  int ith(int v, int ith) {
    return find_first(v, [&](auto &agg, auto &) {
      

      return agg.size >= ith;
    });
  }

  struct SplayNode {
    

    AGG val;
    AGG agg;
    MOD mod;
    

    

    

    


    int c[2] = {0, 0}; 

    int p = 0;         


    void print() {
      P("SplayNode")
      INDENT
      V(val.id, val.size, agg.size)
    }
  };

  

  void aggregate(int v) {
    auto &vv = vs[v];
    vv.agg = vv.val;

    auto l = vv.c[0];
    if (l)
      vv.agg = combine(vs[l].agg, vv.agg);

    auto r = vv.c[1];
    if (r)
      vv.agg = combine(vv.agg, vs[r].agg);

    

    

  }

  

  void propagate(int v) {
    auto &vv = vs[v];
    FOR(c, 2) if (vv.c[c]) {
      auto &cc = vs[vv.c[c]];
      cc.mod = combine(cc.mod, vv.mod);
      cc.agg.apply(vv.mod);
    }
    vv.mod = MOD();
  }

  vector<SplayNode> vs;

  Splay() : vs(1) {}
  Splay(int size) : vs(1) { FOR(i, size) insert(); }

  int is_ith(int v) const { return vs[vs[v].p].c[1] == v; }

  void rotate(int v) {
    CHECK_GT(v, 0)
    if (!vs[v].p) {
      return;
    }

    int ith = is_ith(v);
    int p = vs[v].p;       

    int g = vs[p].p;       

    int i = vs[v].c[!ith]; 


    

    


    propagate(p);
    propagate(v);

    vs[v].p = g;
    if (g) {
      vs[g].c[is_ith(p)] = v;
    }

    vs[v].c[!ith] = p;
    vs[p].p = v;

    vs[p].c[ith] = i;
    vs[i].p = p;

    aggregate(p);
    aggregate(v);
  }

  void link(int c, int p, int ith) {
    CHECK_NE(c, p)
    CHECK(!vs[c].p);
    CHECK(!vs[p].c[ith]);
    propagate(p);
    vs[c].p = p;
    vs[p].c[ith] = c;
    aggregate(p);
  }

  void unlink(int c) {
    CHECK(c);
    CHECK(vs[c].p);
    int p = vs[c].p;
    propagate(p);
    int ith = is_ith(c);
    vs[c].p = 0;
    vs[p].c[ith] = 0;
    aggregate(p);
  }

  int merge(int a, int b) {
    CHECK_NE(a, b)
    CHECK(!same(a, b))
    a = last(a);
    b = first(b);

    link(a, b, 0);
    return b;
  }

  int cut_after(int v, bool after = true) {
    splay(v);
    int c = vs[v].c[after];
    if (!c)
      return 0;
    unlink(c);
    return c;
  }

  int cut_before(int v) { return cut_after(v, false); }

  void splay(int v) {
    CHECK_GT(v, 0)
    for (;;) {
      int p = vs[v].p; 

      if (!p)
        break;

      int g = vs[p].p;
      if (!g) {
        rotate(v);
        break;
      }

      if (is_ith(v) == is_ith(p)) {
        rotate(p);
        rotate(v);
      } else {
        rotate(v);
        rotate(v);
      }
    }
    CHECK_EQ(vs[v].p, 0)
  }

  

  int next(int v, bool forward = true) {
    propagate(v);
    if (vs[v].c[forward]) {
      v = vs[v].c[forward];
      propagate(v);
      while (vs[v].c[!forward]) {
        v = vs[v].c[!forward];
        propagate(v);
      }
      return v;
    } else
      for (;;) {
        int p = vs[v].p;
        if (!p)
          return 0;

        if (is_ith(v) != forward)
          return p;
        v = p;
        propagate(v);
      }
  }

  

  int prev(int x) { return next(x, false); }

  int last(int v, bool forward = true) {
    splay(v);
    while (vs[v].c[forward])
      v = vs[v].c[forward];
    splay(v);
    return v;
  }

  int first(int v) { return last(v, false); }

  int insert() {
    vs.emplace_back();
    vs.back().val.size = 1;
    

    aggregate(SZ(vs) - 1);
    return SZ(vs) - 1;
  }

  int insert_after(int v) {
    int vv = insert();
    splay(v);
    if (!vs[v].c[1])
      link(vv, v, 1);
    else {
      v = next(v);
      link(vv, v, 0);
    }
    splay(vv);
    return vv;
  }

  int insert_before(int v) {
    int vv = insert();
    splay(v);
    if (!vs[v].c[0])
      link(vv, v, 0);
    else {
      v = prev(v);
      link(vv, v, 1);
    }
    splay(vv);
    return vv;
  }

  AGG &agg(int v) {
    splay(v);
    return vs[v].agg;
  }

  bool same(int a, int b) {
    if (a == b)
      return true;
    splay(a);
    splay(b);
    return vs[a].p;
  }

  

  template <class PRED> int find_first(int v, const PRED &pred) {
    CHECK(v)
    splay(v);

    int last = 0;
    int cand = 0;

    AGG agg0;

    for (;;) {
      last = v;
      propagate(v);
      AGG agg1 = agg0;
      int l = vs[v].c[0];
      if (l)
        agg1 = combine(agg0, vs[l].agg);
      bool op_result = pred(agg1, vs[v].val);

      if (op_result) {
        cand = v;
        v = vs[v].c[0];
        if (!v)
          break;
      } else {
        agg0 = combine(agg1, vs[v].val);
        v = vs[v].c[1];
        if (!v)
          break;
      }
    }

    if (last)
      splay(last);

    if (cand)
      splay(cand);

    return cand;
  }

  void print(int v = 1) {

    CHECK(v)
    if (!v)
      P("Splay empty")
    else {
      vs[v].print();

      P("|")
      P("+- CHILD L")
      if (vs[v].c[0]) {
        INDENT
        print(vs[v].c[0]);
      }

      P("|")
      P("+- CHILD R")
      if (vs[v].c[1]) {
        INDENT
        print(vs[v].c[1]);
      }
    }

  }

  

  SplayNode &operator[](int v) { return vs[v]; }
};

using Tree = Splay<Agg, Mod>;



const bool id1 = false;

void clear() {
  

  

}

void test_case() {
  int n, q;
  cin >> n >> q;

  Tree tree(n);

  FOR(i, 1, n + 1) {
    int p;
    cin >> p;

    if (tree.same(i, p))
      continue;

    tree.merge(i, p);
  }

  FOR(qq, q) {
    int type, a, b;
    cin >> type >> a >> b;

    if (type == 1) {
      bool same = tree.same(a, b);

      int aa = tree.cut_after(a);
      int bb = tree.cut_after(b);

      if (same) {
        if (aa && bb) {
          if (tree.same(aa, b))
            tree.merge(bb, a);
          else
            tree.merge(aa, b);
        }
      } else {
        if (aa)
          tree.merge(aa, a);

        if (bb)
          tree.merge(bb, b);

        tree.merge(a, b);
      }
    } else {
      tree.splay(a);
      int aa = tree.index_of(a);
      int sz = tree.agg(a).size;

      


      


      aa = (aa + b) % sz;

      int r = tree.ith(a, aa);
      tree.splay(r);

      cout << r << endl;
    }
  }
}




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
    P()
    P("TEST CASE", i + 1)
    INDENT
    clear();
    test_case();
  }

  return 0;
}
