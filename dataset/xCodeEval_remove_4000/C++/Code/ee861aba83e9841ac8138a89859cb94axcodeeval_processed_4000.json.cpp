


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


int topbit(int x) { return 31 - __builtin_clz(x); }
int topbit(u32 x) { return 31 - __builtin_clz(x); }
int topbit(ll x) { return 63 - __builtin_clzll(x); }
int topbit(u64 x) { return 63 - __builtin_clzll(x); }


int lowbit(int x) { return 31 - __builtin_clz(x); }
int lowbit(u32 x) { return 31 - __builtin_clz(x); }
int lowbit(ll x) { return 63 - __builtin_clzll(x); }
int lowbit(u64 x) { return 63 - __builtin_clzll(x); }

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

template <class T, class S>
inline bool chmax(T &a, const S &b) {
  return (a < b ? a = b, 1 : 0);
}
template <class T, class S>
inline bool chmin(T &a, const S &b) {
  return (a > b ? a = b, 1 : 0);
}

vi id2(string S, char first_char = 'a') {
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

template <typename T, typename CNT = int>
vc<CNT> id3(vc<T> &A, int size) {
  vc<CNT> C(size);
  for (auto &&x: A) { ++C[x]; }
  return C;
}

template <typename T>
vector<int> argsort(vector<T> &A) {
  

  vector<int> ids(A.size());
  iota(all(ids), 0);
  sort(all(ids),
       [&](int i, int j) { return A[i] < A[j] || (A[i] == A[j] && i < j); });
  return ids;
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
  FILE* fp;
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
    oss << setprecision(12) << x;
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

vc<ll>& primetable(int LIM) {
  ++LIM;
  const int S = 32768;
  static int done = 2;
  static vc<ll> primes = {2}, sieve(S + 1);

  if(done >= LIM) return primes;
  done  = LIM;

  primes = {2}, sieve.assign(S + 1, 0);
  const int R = LIM / 2;  
  primes.reserve(int(LIM / log(LIM) * 1.1));
  vc<pi> cp;
  for (int i = 3; i <= S; i += 2) {
    if (!sieve[i]) {
      cp.eb(i, i * i / 2);
      for (int j = i * i; j <= S; j += 2 * i) sieve[j] = 1;
    }
  }
  for (int L = 1; L <= R; L += S) {
    array<bool, S> block{};
    for (auto& [p, idx]: cp)
      for (int i = idx; i < S + L; idx = (i += p)) block[i - L] = 1;
    FOR(i, min(S, R - L)) if (!block[i]) primes.eb((L + i) * 2 + 1);
  }
  return primes;
}

template <class X, X ZERO = X(0)>
struct Group_Add {
  using value_type = X;
  static constexpr X op(const X &x, const X &y) noexcept { return x + y; }
  static constexpr X inverse(const X &x) noexcept { return -x; }
  static constexpr X power(const X &x, ll n) noexcept { return n * x; }
  static constexpr X unit = ZERO;
  static constexpr bool commute = true;
};


template <typename Monoid, int LOG>
struct Doubling {
  
  using X = typename Monoid::value_type;
  int N;
  bool id1;
  vvc<int> TO;
  vvc<X> DP;

  Doubling(int N) : N(N), id1(0) {
    TO.assign(LOG, vc<int>(N, -1));
    DP.assign(LOG, vc<X>(N, Monoid::unit));
  }

  void set(int i, int to, X x) {
    assert(!id1);
    assert(-1 <= to && to < N);
    TO[0][i] = to;
    DP[0][i] = x;
  }

  void build() {
    if (id1) return;
    id1 = 1;
    FOR(k, LOG - 1) {
      FOR(v, N) {
        int w = TO[k][v];
        if (w == -1) {
          TO[k + 1][v] = -1;
          DP[k + 1][v] = DP[k][v];
          continue;
        }
        TO[k + 1][v] = TO[k][w];
        DP[k + 1][v] = Monoid::op(DP[k][v], DP[k][w]);
      }
    }
  }

  pair<int, X> calc(int i, int step) {
    assert(id1);
    assert(step < (1 << LOG));
    X x = Monoid::unit;
    FOR(k, LOG) {
      if (i == -1) break;
      if (step && 1 << k) {
        x = Monoid::op(x, DP[k][i]);
        i = TO[k][i];
      }
    }
    return {i, x};
  }

  template <typename F>
  int max_step(F check, int i) {
    assert(id1);
    

    X x = Monoid::unit;
    ll step = 0;
    assert(check(x));
    FOR_R(k, LOG) {
      int j = TO[k][i];
      X y = Monoid::op(x, DP[k][i]);
      if (check(y)) {
        step |= 1 << k;
        i = j;
        x = y;
        assert(i != -1);
      }
    }
    return step;
  }

  void debug() {
    print("TO");
    FOR(k, LOG) print(TO[k]);
    print("DP");
    FOR(k, LOG) print(DP[k]);
  }
};

void solve() {
  LL(N, Q);
  VEC(ll, A, N);
  ll LIM = MAX(A);
  vc<vi> pfs(LIM + 1);
  auto primes = primetable(LIM);
  for (auto&& p: primes) { FOR3(i, 1, LIM / p + 1) pfs[p * i].eb(p); }

  vi CNT(LIM + 1);
  vi to_R(N);
  ll R = 0;
  FOR(L, N) {
    while (R < N) {
      ll a = A[R];
      bool can = 1;
      for (auto&& p: pfs[a])
        if (CNT[p]) can = 0;
      if (!can) break;
      for (auto&& p: pfs[a]) ++CNT[p];
      ++R;
    }
    to_R[L] = R;
    for (auto&& p: pfs[A[L]]) --CNT[p];
  }

  Doubling<Group_Add<ll>, 20> DB(N + 1);
  FOR(i, N) DB.set(i, to_R[i], to_R[i] - i);
  DB.set(N, N, 0);
  DB.build();

  FOR_(Q) {
    LL(l, r);
    --l;
    auto check = [&](ll x) -> bool { return l + x < r; };
    ll ANS = 1 + DB.max_step(check, l);
    print(ANS);
  }
}

signed main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << setprecision(15);

  ll T = 1;
  

  FOR(_, T) solve();

  return 0;
}