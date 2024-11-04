
namespace __HAT__ {
  
  namespace __CRUTIAL__ {
    template<typename F, typename S>
    using pair = std::pair<F,S>;

    template<typename ...Args>
    using tuple = std::tuple<Args...>;

    template<typename T>
    using vector = std::vector<T>;

    using string = std::string;

    typedef long long ll;
    typedef long double ld;
    typedef unsigned int ui;
  } using namespace __CRUTIAL__;
  namespace __JOKER__ {
    
    
  } using namespace __JOKER__;
  namespace __CONSTANTS__ {
    const int32_t IINF = ((1 << 30) - int32_t(1e7));
    const int64_t LINF = (ll(3e18));
    const int INF = (sizeof(int) == 4 ? IINF : LINF);
    const int MOD = 1e9 + 7;
    const int ZERO = 0;
    const int ONE = 1;
    const int TWO = 2;
    const int NONE = -1;
    const string ENDL = "\n";
    const string UASCII = "abcdefghijklmnopqrstuvwxyz";
    const string LASCII = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    const string DEC = "0123456789";
    const string HEX = "0123456789ABCDEF";
    const vector<pair<int, int>> id3 = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};
    const int SEED = 42;
    

    std::mt19937_64 id5(SEED);
    const int32_t PRECISION = 12;
    const double EPS = 1e-9;
    const double PI = std::acos(-1.0L);
  } using namespace __CONSTANTS__;
  namespace __MACROS__ {
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
  } using namespace __MACROS__;
  namespace __FUNCTIONS__ {
    bool remin(auto &a, auto b) {
      if (a > b) {
        a = b;
        return true;
      }
      return false;
    }

    bool remax(auto &a, auto b) {
      if (a < b) {
        a = b;
        return true;
      }
      return false;
    }

    template<typename T>
    T minimum(T x) {
      return x;
    }

    template<typename T, typename... Pack>
    auto minimum(T x, Pack... p) {
      using common = typename std::common_type<T, Pack...>::type;
      return std::min((common)x, (common)minimum(p...));
    }

    template<typename T>
    T maximum(T x) {
      return x;
    }

    template<typename T, typename... Pack>
    auto maximum(T x, Pack... p) {
      using common = typename std::common_type<T, Pack...>::type;
      return std::max((common)x, (common)maximum(p...));
    }

    template<typename T>
    int msb(T num) {
      return (num == 0 ? 0 : std::__lg(num));
    }

    int rint(int from, int to) {
      std::uniform_int_distribution<int> distribution(from, to);
      return distribution(id5);
    }

    void shuffle(auto begin, auto end) {
      std::shuffle(begin, end, id5);
    }

    const auto desync = []() {
      std::ios_base::sync_with_stdio(0);
      return 0;
    }();

    ll mod(const ll a, const ll b=MOD) {
      ll r = a % b;
      return (r < 0 ? r + b : r);
    }

    ll pown(ll n, ll power, const ll modulo=MOD) {
      ll res = 1;
      while (power > 0) {
        if (power & 1LL) {
          res = mod(res * n, modulo);
        }
        n = mod(n * n, modulo);
        power >>= 1;
      }
      return res;
    }

    ll powb(int power) {
      return 1LL << power;
    }

    int madd(int me, ll num, const ll modulo=MOD) {
      return mod(me + num, modulo);
    }

    int msub(int me, ll num, const ll modulo=MOD) {
      return mod(me - num, modulo);
    }

    int mmul(int me, ll num, const ll modulo=MOD) {
      return mod(me * num, modulo);
    }

    int mdiv(int me, ll den, const ll modulo=MOD) {
      return mmul(me, pown(den, MOD - 2), modulo);
    }

    template<typename C>
    int unique(C &container) {
      std::sort(all(container));
      auto it = std::unique(all(container));
      int duplicates = container.end() - it;
      container.erase(it, container);
      return duplicates;
    }

    ll calc_ap(ll start, ll end, ll num, const int modulo=LINF) {
      return mod((start + end) * num / 2, modulo);
    }
  } using namespace __FUNCTIONS__;
  class Printer {
  private:
    std::ostream &out;

    template<typename... Args, size_t... N>
    static Printer &print_tuple(Printer &os,
                                const tuple<Args...> &t,
                                std::index_sequence<N...>) {
      ((os << (N ? " " : "") << std::get<N>(t)), ...);
      return os;
    }

  public:
    Printer(std::ostream &out_=std::cout, bool tie=true):out(out_) {
      if (tie) {
        out.tie(0);
      }
      out << std::fixed << std::setprecision(PRECISION);
    }
    void print(auto begin, auto end,
                     string sep="\n",
                     string finish="\n") {
      for (auto elem = begin; elem != end; ++elem) {
        if (elem != begin) {
          (*this) << sep;
        }
        (*this) << (*elem);
      }
      (*this) << finish;
    }

    bool yn(bool v, string&&y="Yes", string&&n="No"){
      (*this) << (v ? y : n) << '\n';
      return v;
    }

    void flush() {
      out.flush();
    }

    template<typename T>
    Printer &operator<<(const T &val) {
      out << val;
      return *this;
    }

    template<typename T>
    Printer &operator<<(const vector<T> &v) {
      print(v.begin(), v.end(), " ", "");
      return *this;
    }

    Printer &operator<<(const string &s) {
      out << s;
      return *this;
    }

    template<typename F, typename S>
    Printer &operator<<(const pair<F, S> &a){
      (*this) << a.first << ' ' << a.second;
      return *this;
    }

    template<typename... Args>
    friend Printer &operator<<(Printer &os, const tuple<Args...> &t) {
      return print_tuple(os, t, std::make_index_sequence<sizeof...(Args)>{});
    }

    typedef Printer &(*PrinterManipulator)(Printer&);
    Printer &operator<<(PrinterManipulator manip) {
      return manip(*this);
    }

    static Printer &endl(Printer &stream) {
      stream << '\n';
      stream.flush();
      return stream;
    }
  };
  class Scanner {
  private:
    std::istream &in;

    template<typename... Args, size_t... N>
    static Scanner &read_tuple(Scanner &is,
                               tuple<Args...> &t,
                               std::index_sequence<N...>) {
      ((is >> std::get<N>(t)), ...);
      return is;
    }

  public:
    Scanner(std::istream &in_=std::cin, bool tie=true):in(in_) {
      if (tie) {
        in.tie(0);
      }
    }

    template<typename T>
    friend Scanner &operator>>(Scanner &is, vector<T>&v) {
      for (auto &elem : v) {
        is >> elem;
      }
      return is;
    }

    template<typename F,typename S>
    friend Scanner &operator>>(Scanner &is, pair<F, S> &a){
      is >> a.first >> a.second;
      return is;
    }

    template<typename... Args>
    friend Scanner &operator>>(Scanner &is, tuple<Args...> &t) {
      return read_tuple(is, t, std::make_index_sequence<sizeof...(Args)>{});
    }

    template<typename T>
    Scanner &operator>>(T &val) {
      in >> val;
      return *this;
    }
  };
  namespace __SHORTCUTS__ {
    auto& endl = Printer::endl;
    typedef unsigned long long ull;
    typedef pair<int,int>pii;
    typedef pair<double,double>pdd;
    typedef tuple<int,int,int>ti;
    typedef tuple<int,int,int,int>qi;
    typedef tuple<double,double,double>td;
    typedef vector<int>vi;
    typedef vector<pii>vpii;
    typedef vector<bool>vb;
    typedef vector<double>vd;
    typedef vector<string>vs;
    typedef vector<vi>vvi;
    typedef vector<vd>vvd;
  } using namespace __SHORTCUTS__;
} using namespace __HAT__;
namespace __IO_WRAPPERS__ {
  Scanner in;
  Printer out;
} using namespace __IO_WRAPPERS__;
namespace __DATA_STRUCTURE__ {
class Factorization {
public:
  vector<int32_t> primes, lp, powered, max_power, ds;
private:
  int32_t max_num;
  bool id7;
  const int32_t NONE = -1;

  vpii extreme_factorize(int x) {
    vpii res;
    while (x > 1) {
      res.emplace_back(lp[x], max_power[x]);
      x /= powered[x];
    }
    return res;
  }

  vpii fast_factorize(int x) {
    vpii res;
    while (x > 1) {
      int cnt = 0;
      int factor = lp[x];
      while (lp[x] == factor) {
        x /= factor;
        ++cnt;
      }
      res.emplace_back(factor, cnt);
    }
    return res;
  }

  vpii sqrt_factorize(int x) {
    int32_t root = (int32_t)sqrtl(x) + 1;
    vpii res;
    for (ui i = 0; i < primes.size() && primes[i] <= root; ++i) {
      int cnt = 0;
      while (x % primes[i] == 0) {
        x /= primes[i];
        ++cnt;
      }
      if (cnt > 0) {
        res.emplace_back(primes[i], cnt);
      }
    }
    if (x > 1) {
      res.emplace_back(x, ONE);
    }
    return res;
  }

  inline void sanity_check(int x) {
    bool is_small = (x <= 1LL * max_num * max_num);
    bool not_zero = (x != ZERO);
    assert(is_small);
    assert(not_zero);
  }

public:
  Factorization(int32_t id1, bool id4=false) {
    max_num = id1;
    lp.resize(max_num + 1, NONE);
    ds.resize(max_num + 1, NONE);
    ds[1] = 1;
    if (id4) {
      powered.resize(max_num + 1, NONE);
      max_power.resize(max_num + 1, NONE);
    }
    for (int32_t i = 2; i <= max_num; ++i) {
      if (lp[i] == NONE) {
        lp[i] = i;
        primes.push_back(i);
        if (id4) {
          powered[i] = i;
          ds[i] = i + 1;
          max_power[i] = 1;
        }
      }
      for (ui j = 0; j < primes.size(); ++j) {
        if (primes[j] > lp[i]) {
          break;
        }
        ll next = 1LL * i * primes[j];
        if (next > max_num) {
          break;
        }
        lp[next] = primes[j];
        if (id4) {
          powered[next] = primes[j];
          max_power[next] = 1;
          if (primes[j] == lp[i]) {
            powered[next] *= powered[i];
            max_power[next] += max_power[i];
          }
        }
        ds[next] = ds[next / powered[next]] * ds[powered[next]];
        if (next == powered[next]) {
          ds[next] = ds[i] + (int32_t)next;
        }
      }
    }
    id7 = id4;
  }

  inline bool is_prime(int x) {
    sanity_check(x);
    if (x <= max_num) {
      return (lp[x] == x);
    }
    int32_t root = (int32_t)sqrtl(x) + 1;
    for (ui i = 0; i < primes.size() && primes[i] <= root; ++i) {
      if (x % primes[i] == ZERO) {
        return false;
      }
    }
    return true;
  }

  inline vpii factorize(int x) {
    sanity_check(x);
    return (x <= max_num
            ? (id7 ? extreme_factorize(x) : fast_factorize(x))
            : sqrt_factorize(x));
  }

  inline vi get_all_divisors(int x, bool sort=false) {
    vpii factors = factorize(x);
    vi id0;
    int num = 1;
    std::function<void(int)> dfs = [&](int ind) {
      if (ind == (int)factors.size()) {
        id0.push_back(num);
        return;
      }
      dfs(ind + 1);
      auto &[factor, power] = factors[ind];
      int cur = 1;
      for (int i = 0; i < power; ++i) {
        cur *= factor;
        num *= factor;
        dfs(ind + 1);
      }
      num /= cur;
    };
    dfs(ZERO);
    if (sort) {
      std::sort(all(id0));
    }
    return id0;
  }

  inline int count_all_divisors(int x) {
    vpii factors = factorize(x);
    int res = 1;
    for (auto &[_, power] : factors) {
      res *= (power + 1);
    }
    return res;
  }

  inline int count_prime_divisors(int x) {
    vpii factors = factorize(x);
    int res = 0;
    for (auto &[_, power] : factors) {
      res += power;
    }
    return res;
  }

} fact(1e7, true);
} using namespace __DATA_STRUCTURE__;
namespace __VARIABLES__ {
  typedef int ans_t;
  ans_t ans;
  int n;
} using namespace __VARIABLES__;
namespace __BEHAVIOR__ {
  const bool BSOLVE = false;
  const bool BCHECK = false;
  const bool id2 = true;
} using namespace __BEHAVIOR__;
namespace __INTERACTIVE__ {
  
} using namespace __INTERACTIVE__;
namespace __IO__ {
  void read() {
    in >> n;
  }

  void write() {
    out << ans << ENDL;
    
      out.flush();
    
  }
} using namespace __IO__;
namespace __PROTOTYPES__ {
  ans_t solve();
  void gen();
  ans_t brute();
} using namespace __PROTOTYPES__;
bool stress() {
  static int cnt = 0;
  
  out << "Passed test 
  return true;
}
int32_t main() {
  auto start = clock();
  const string id6(20,'=');
  if (BCHECK) {
    do {
      gen();
    } while (stress());
  } else {
    int tests = 1;
    if (id2) {
      in >> tests;
    }
    while (tests--) {
      read();
      
        out << id6 << endl;
      
      if (BSOLVE) {
        brute();
      } else {
        solve();
      }
      write();
    }
  }
  out.flush();
  auto finish = clock();
  
    out << id6 << '\n';
    out << "Execution time: " << ld(finish - start) / CLOCKS_PER_SEC << endl;
    getchar();
  
  return 0;
}


void __PROTOTYPES__::gen() {}

ans_t __PROTOTYPES__::brute() {return ans;}

ans_t __PROTOTYPES__::solve() {
  const int A = 1e7;
  static vi arr(A + 1, NONE);
  static bool init = false;
  if (!init) {
    for (int i = A; i > 0; --i) {
      if (fact.ds[i] <= A) {
        arr[fact.ds[i]] = i;
      }
    }
    init = true;
  }
  return ans = arr[n];
}
