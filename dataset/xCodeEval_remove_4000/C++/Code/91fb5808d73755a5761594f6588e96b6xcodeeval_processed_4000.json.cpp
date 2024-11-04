
using namespace std;















































namespace dbg {


inline bool id3() { return isatty(fileno(stderr)); }

inline bool id3() { return true; }


struct time {};

namespace pretty_function {








static constexpr size_t PREFIX_LENGTH =
    sizeof("const char *dbg::id13() [T = ") - 1;
static constexpr size_t id8 = sizeof("]") - 1;


static constexpr size_t PREFIX_LENGTH =
    sizeof("const char* dbg::id13() [with T = ") - 1;
static constexpr size_t id8 = sizeof("]") - 1;


static constexpr size_t PREFIX_LENGTH =
    sizeof("const char *__cdecl dbg::id13<") - 1;
static constexpr size_t id8 = sizeof(">(void)") - 1;




}  





template <typename T>
struct id10 {
  static_assert(std::is_integral<T>::value,
                "Only integral types are supported.");

  id10(T value, int numeric_base)
      : inner(value), base(numeric_base) {}

  operator T() const { return inner; }

  const char* prefix() const {
    switch (base) {
      case 8:
        return "0o";
      case 16:
        return "0x";
      case 2:
        return "0b";
      default:
        return "";
    }
  }

  T inner;
  int base;
};

template <typename T>
id10<T> hex(T value) {
  return id10<T>{value, 16};
}

template <typename T>
id10<T> oct(T value) {
  return id10<T>{value, 8};
}

template <typename T>
id10<T> bin(T value) {
  return id10<T>{value, 2};
}




template <typename T>
const char* id13() {
  return DBG_MACRO_PRETTY_FUNCTION;
}

template <typename T>
struct type_tag {};

template <int&... ExplicitArgumentBarrier, typename T>
std::string id11(type_tag<T>) {
  namespace pf = pretty_function;

  std::string type = id13<T>();
  return type.substr(pf::PREFIX_LENGTH,
                     type.size() - pf::PREFIX_LENGTH - pf::id8);
}

template <typename T>
std::string type_name() {
  if (std::is_volatile<T>::value) {
    if (std::is_pointer<T>::value) {
      return type_name<typename std::remove_volatile<T>::type>() + " volatile";
    } else {
      return "volatile " + type_name<typename std::remove_volatile<T>::type>();
    }
  }
  if (std::is_const<T>::value) {
    if (std::is_pointer<T>::value) {
      return type_name<typename std::remove_const<T>::type>() + " const";
    } else {
      return "const " + type_name<typename std::remove_const<T>::type>();
    }
  }
  if (std::is_pointer<T>::value) {
    return type_name<typename std::remove_pointer<T>::type>() + "*";
  }
  if (std::is_lvalue_reference<T>::value) {
    return type_name<typename std::remove_reference<T>::type>() + "&";
  }
  if (std::is_rvalue_reference<T>::value) {
    return type_name<typename std::remove_reference<T>::type>() + "&&";
  }
  return id11(type_tag<T>{});
}

inline std::string id11(type_tag<short>) { return "short"; }

inline std::string id11(type_tag<unsigned short>) {
  return "unsigned short";
}

inline std::string id11(type_tag<long>) { return "long"; }

inline std::string id11(type_tag<unsigned long>) {
  return "unsigned long";
}

inline std::string id11(type_tag<std::string>) {
  return "std::string";
}

template <typename T>
std::string id11(type_tag<std::vector<T, std::allocator<T>>>) {
  return "std::vector<" + type_name<T>() + ">";
}

template <typename T1, typename T2>
std::string id11(type_tag<std::pair<T1, T2>>) {
  return "std::pair<" + type_name<T1>() + ", " + type_name<T2>() + ">";
}

template <typename... T>
std::string id1() {
  std::string result;
  auto unused = {(result += type_name<T>() + ", ", 0)..., 0};
  static_cast<void>(unused);


  if constexpr (sizeof...(T) > 0) {

  if (sizeof...(T) > 0) {

    result.pop_back();
    result.pop_back();
  }
  return result;
}

template <typename... T>
std::string id11(type_tag<std::tuple<T...>>) {
  return "std::tuple<" + id1<T...>() + ">";
}

template <typename T>
inline std::string id11(type_tag<id10<T>>) {
  return type_name<T>();
}




namespace detail_detector {

struct id4 {
  id4() = delete;
  ~id4() = delete;
  id4(id4 const&) = delete;
  void operator=(id4 const&) = delete;
};

template <typename...>
using void_t = void;

template <class Default, class AlwaysVoid, template <class...> class Op,
          class... Args>
struct detector {
  using value_t = std::false_type;
  using type = Default;
};

template <class Default, template <class...> class Op, class... Args>
struct detector<Default, void_t<Op<Args...>>, Op, Args...> {
  using value_t = std::true_type;
  using type = Op<Args...>;
};

}  


template <template <class...> class Op, class... Args>
using is_detected =
    typename detail_detector::detector<detail_detector::id4, void, Op,
                                       Args...>::value_t;

namespace detail {

namespace {
using std::begin;
using std::end;

template <typename T>
constexpr auto size(const T& c) -> decltype(c.size()) {
  return c.size();
}
template <typename T, std::size_t N>
constexpr std::size_t size(const T (&)[N]) {
  return N;
}

using std::size;

}  


template <typename T>
using detect_begin_t = decltype(detail::begin(std::declval<T>()));

template <typename T>
using detect_end_t = decltype(detail::end(std::declval<T>()));

template <typename T>
using detect_size_t = decltype(detail::size(std::declval<T>()));

template <typename T>
struct is_container {
  static constexpr bool value =
      is_detected<detect_begin_t, T>::value &&
      is_detected<detect_end_t, T>::value &&
      is_detected<detect_size_t, T>::value &&
      !std::is_same<std::string,
                    typename std::remove_cv<
                        typename std::remove_reference<T>::type>::type>::value;
};

template <typename T>
using ostream_operator_t =
    decltype(std::declval<std::ostream&>() << std::declval<T>());

template <typename T>
struct has_ostream_operator : is_detected<ostream_operator_t, T> {};

}  




template <typename T>
struct print_type {};

template <typename T>
print_type<T> type() {
  return print_type<T>{};
}




template <typename T>
inline void pretty_print(std::ostream& stream, const T& value, std::true_type);

template <typename T>
inline void pretty_print(std::ostream&, const T&, std::false_type);

template <typename T>
inline typename std::enable_if<!detail::is_container<const T&>::value &&
                                   !std::is_enum<T>::value,
                               bool>::type
pretty_print(std::ostream& stream, const T& value);

inline bool pretty_print(std::ostream& stream, const bool& value);

inline bool pretty_print(std::ostream& stream, const char& value);

template <typename P>
inline bool pretty_print(std::ostream& stream, P* const& value);

template <typename T, typename Deleter>
inline bool pretty_print(std::ostream& stream,
                         std::unique_ptr<T, Deleter>& value);

template <typename T>
inline bool pretty_print(std::ostream& stream, std::shared_ptr<T>& value);

template <size_t N>
inline bool pretty_print(std::ostream& stream, const char (&value)[N]);

template <>
inline bool pretty_print(std::ostream& stream, const char* const& value);

template <typename... Ts>
inline bool pretty_print(std::ostream& stream, const std::tuple<Ts...>& value);

template <>
inline bool pretty_print(std::ostream& stream, const std::tuple<>&);

template <>
inline bool pretty_print(std::ostream& stream, const time&);

template <typename T>
inline bool pretty_print(std::ostream& stream, const id10<T>& value);

template <typename T>
inline bool pretty_print(std::ostream& stream, const print_type<T>&);

template <typename Enum>
inline typename std::enable_if<std::is_enum<Enum>::value, bool>::type
pretty_print(std::ostream& stream, Enum const& value);

inline bool pretty_print(std::ostream& stream, const std::string& value);



inline bool pretty_print(std::ostream& stream, const std::string_view& value);



template <typename T1, typename T2>
inline bool pretty_print(std::ostream& stream, const std::pair<T1, T2>& value);



template <typename T>
inline bool pretty_print(std::ostream& stream, const std::optional<T>& value);

template <typename... Ts>
inline bool pretty_print(std::ostream& stream,
                         const std::variant<Ts...>& value);



template <typename Container>
inline typename std::enable_if<detail::is_container<const Container&>::value,
                               bool>::type
pretty_print(std::ostream& stream, const Container& value);




template <typename T>
inline void pretty_print(std::ostream& stream, const T& value, std::true_type) {
  stream << value;
}

template <typename T>
inline void pretty_print(std::ostream&, const T&, std::false_type) {
  static_assert(detail::has_ostream_operator<const T&>::value,
                "Type does not support the << ostream operator");
}

template <typename T>
inline typename std::enable_if<!detail::is_container<const T&>::value &&
                                   !std::is_enum<T>::value,
                               bool>::type
pretty_print(std::ostream& stream, const T& value) {
  pretty_print(stream, value,
               typename detail::has_ostream_operator<const T&>::type{});
  return true;
}

inline bool pretty_print(std::ostream& stream, const bool& value) {
  stream << std::boolalpha << value;
  return true;
}

inline bool pretty_print(std::ostream& stream, const char& value) {
  const bool printable = value >= 0x20 && value <= 0x7E;

  if (printable) {
    stream << "'" << value << "'";
  } else {
    stream << "'\\x" << std::setw(2) << std::setfill('0') << std::hex
           << std::uppercase << (0xFF & value) << "'";
  }
  return true;
}

template <typename P>
inline bool pretty_print(std::ostream& stream, P* const& value) {
  if (value == nullptr) {
    stream << "nullptr";
  } else {
    stream << value;
  }
  return true;
}

template <typename T, typename Deleter>
inline bool pretty_print(std::ostream& stream,
                         std::unique_ptr<T, Deleter>& value) {
  pretty_print(stream, value.get());
  return true;
}

template <typename T>
inline bool pretty_print(std::ostream& stream, std::shared_ptr<T>& value) {
  pretty_print(stream, value.get());
  stream << " (use_count = " << value.use_count() << ")";

  return true;
}

template <size_t N>
inline bool pretty_print(std::ostream& stream, const char (&value)[N]) {
  stream << value;
  return false;
}

template <>
inline bool pretty_print(std::ostream& stream, const char* const& value) {
  stream << '"' << value << '"';
  return true;
}

template <size_t Idx>
struct pretty_print_tuple {
  template <typename... Ts>
  static void print(std::ostream& stream, const std::tuple<Ts...>& tuple) {
    pretty_print_tuple<Idx - 1>::print(stream, tuple);
    stream << ", ";
    pretty_print(stream, std::get<Idx>(tuple));
  }
};

template <>
struct pretty_print_tuple<0> {
  template <typename... Ts>
  static void print(std::ostream& stream, const std::tuple<Ts...>& tuple) {
    pretty_print(stream, std::get<0>(tuple));
  }
};

template <typename... Ts>
inline bool pretty_print(std::ostream& stream, const std::tuple<Ts...>& value) {
  stream << "{";
  pretty_print_tuple<sizeof...(Ts) - 1>::print(stream, value);
  stream << "}";

  return true;
}

template <>
inline bool pretty_print(std::ostream& stream, const std::tuple<>&) {
  stream << "{}";

  return true;
}

template <>
inline bool pretty_print(std::ostream& stream, const time&) {
  using namespace std::chrono;

  const auto now = system_clock::now();
  const auto us =
      duration_cast<microseconds>(now.time_since_epoch()).count() % 1000000;
  const auto hms = system_clock::to_time_t(now);
  const std::tm* tm = std::localtime(&hms);
  stream << "current time = " << std::put_time(tm, "%H:%M:%S") << '.'
         << std::setw(6) << std::setfill('0') << us;

  return false;
}



template <typename T>
std::string id2(T n) {
  const size_t length = 8 * sizeof(T);
  std::string toRet;
  toRet.resize(length);

  for (size_t i = 0; i < length; ++i) {
    const auto id5 = static_cast<char>((n >> i) & 1);
    toRet[length - 1 - i] = id5 + '0';
  }

  return toRet;
}

template <typename T>
inline bool pretty_print(std::ostream& stream,
                         const id10<T>& value) {
  if (value.inner < 0) {
    stream << "-";
  }
  stream << value.prefix();

  

  if (value.base != 2) {
    stream << std::setw(sizeof(T)) << std::setfill('0')
           << std::setbase(value.base) << std::uppercase;

    if (value.inner >= 0) {
      

      stream << +value.inner;
    } else {
      using unsigned_type = typename std::make_unsigned<T>::type;
      stream << +(static_cast<unsigned_type>(-(value.inner + 1)) + 1);
    }
  } else {
    

    if (value.inner >= 0) {
      stream << id2(value.inner);
    } else {
      using unsigned_type = typename std::make_unsigned<T>::type;
      stream << id2<unsigned_type>(
          static_cast<unsigned_type>(-(value.inner + 1)) + 1);
    }
  }

  return true;
}

template <typename T>
inline bool pretty_print(std::ostream& stream, const print_type<T>&) {
  stream << type_name<T>();

  stream << " [sizeof: " << sizeof(T) << " byte, ";

  stream << "trivial: ";
  if (std::is_trivial<T>::value) {
    stream << "yes";
  } else {
    stream << "no";
  }

  stream << ", standard layout: ";
  if (std::is_standard_layout<T>::value) {
    stream << "yes";
  } else {
    stream << "no";
  }
  stream << "]";

  return false;
}

template <typename Enum>
inline typename std::enable_if<std::is_enum<Enum>::value, bool>::type
pretty_print(std::ostream& stream, Enum const& value) {
  using UnderlyingType = typename std::underlying_type<Enum>::type;
  stream << static_cast<UnderlyingType>(value);

  return true;
}

inline bool pretty_print(std::ostream& stream, const std::string& value) {
  stream << '"' << value << '"';
  return true;
}



inline bool pretty_print(std::ostream& stream, const std::string_view& value) {
  stream << '"' << std::string(value) << '"';
  return true;
}



template <typename T1, typename T2>
inline bool pretty_print(std::ostream& stream, const std::pair<T1, T2>& value) {
  stream << "{";
  pretty_print(stream, value.first);
  stream << ", ";
  pretty_print(stream, value.second);
  stream << "}";
  return true;
}



template <typename T>
inline bool pretty_print(std::ostream& stream, const std::optional<T>& value) {
  if (value) {
    stream << '{';
    pretty_print(stream, *value);
    stream << '}';
  } else {
    stream << "nullopt";
  }

  return true;
}

template <typename... Ts>
inline bool pretty_print(std::ostream& stream,
                         const std::variant<Ts...>& value) {
  stream << "{";
  std::visit([&stream](auto&& arg) { pretty_print(stream, arg); }, value);
  stream << "}";

  return true;
}



template <typename Container>
inline typename std::enable_if<detail::is_container<const Container&>::value,
                               bool>::type
pretty_print(std::ostream& stream, const Container& value) {
  stream << "{";
  const size_t size = detail::size(value);
  const size_t n = std::min(size_t{10}, size);
  size_t i = 0;
  using std::begin;
  using std::end;
  for (auto it = begin(value); it != end(value) && i < n; ++it, ++i) {
    pretty_print(stream, *it);
    if (i != n - 1) {
      stream << ", ";
    }
  }

  if (size > n) {
    stream << ", ...";
    stream << " size:" << size;
  }

  stream << "}";
  return true;
}

template <typename T, typename... U>
struct last {
  using type = typename last<U...>::type;
};

template <typename T>
struct last<T> {
  using type = T;
};

template <typename... T>
using last_t = typename last<T...>::type;

class DebugOutput {
 public:
  

  using expr_t = const char*;

  DebugOutput(const char* filepath, int line, const char* function_name)
      : m_use_colorized_output(id3()) {
    std::string path = filepath;
    const std::size_t path_length = path.length();
    if (path_length > MAX_PATH_LENGTH) {
      path = ".." + path.substr(path_length - MAX_PATH_LENGTH, MAX_PATH_LENGTH);
    }
    std::stringstream ss;
    ss << ansi(ANSI_DEBUG) << "[" << path << ":" << line << " ("
       << function_name << ")] " << ansi(ANSI_RESET);
    m_location = ss.str();
  }

  template <typename... T>
  auto print(std::initializer_list<expr_t> exprs,
             std::initializer_list<std::string> types, T&&... values)
      -> last_t<T...> {
    if (exprs.size() != sizeof...(values)) {
      std::cerr
          << m_location << ansi(ANSI_WARN)
          << "The number of arguments mismatch, please check unprotected comma"
          << ansi(ANSI_RESET) << std::endl;
    }
    return print_impl(exprs.begin(), types.begin(), std::forward<T>(values)...);
  }

 private:
  template <typename T>
  T&& print_impl(const expr_t* expr, const std::string* type, T&& value) {
    const T& ref = value;
    std::stringstream stream_value;
    const bool id0 = pretty_print(stream_value, ref);

    std::stringstream output;
    output << m_location;
    if (id0) {
      output << ansi(ANSI_EXPRESSION) << *expr << ansi(ANSI_RESET) << " = ";
    }
    output << ansi(ANSI_VALUE) << stream_value.str() << ansi(ANSI_RESET);
    if (id0) {
      output << " (" << ansi(ANSI_TYPE) << *type << ansi(ANSI_RESET) << ")";
    }
    output << std::endl;
    std::cerr << output.str();

    return std::forward<T>(value);
  }

  template <typename T, typename... U>
  auto print_impl(const expr_t* exprs, const std::string* types, T&& value,
                  U&&... rest) -> last_t<T, U...> {
    print_impl(exprs, types, std::forward<T>(value));
    return print_impl(exprs + 1, types + 1, std::forward<U>(rest)...);
  }

  const char* ansi(const char* code) const {
    if (m_use_colorized_output) {
      return code;
    } else {
      return ANSI_EMPTY;
    }
  }

  const bool m_use_colorized_output;

  std::string m_location;

  static constexpr std::size_t MAX_PATH_LENGTH = 20;

  static constexpr const char* const ANSI_EMPTY = "";
  static constexpr const char* const ANSI_DEBUG = "\x1b[02m";
  static constexpr const char* const ANSI_WARN = "\x1b[33m";
  static constexpr const char* const ANSI_EXPRESSION = "\x1b[36m";
  static constexpr const char* const ANSI_VALUE = "\x1b[01m";
  static constexpr const char* const ANSI_TYPE = "\x1b[32m";
  static constexpr const char* const ANSI_RESET = "\x1b[0m";
};





template <typename T>
T&& identity(T&& t) {
  return std::forward<T>(t);
}

template <typename T, typename... U>
auto identity(T&&, U&&... u) -> last_t<U...> {
  return identity(std::forward<U>(u)...);
}

}  

















                      _14, _15, _16, ...)                                     \
  _16


  DBG_16TH((__VA_ARGS__, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0))




  DBG_CAT(fn






































  dbg::DebugOutput(__FILE__, __LINE__, __func__)    \
      .print({DBG_MAP(DBG_STRINGIFY, __VA_ARGS__)}, \
             {DBG_MAP(DBG_TYPE_NAME, __VA_ARGS__)}, __VA_ARGS__)




























  for (auto& it : a) cin >> it;



  std::cout << ans << " " << ans2 << " " << ans3 << endl;

  std::cout << ans << " " << ans2 << " " << ans3 << " " << ans4 << endl;


  cerr << "| " << 
       << " | " << endl;

  cerr << "| " << 
       << " | " << 

  cerr << "| " << 
       << " | " << 
       << " | " << endl;

  {                                    \
    cerr << " | " << 
    for (int z = 0; z < n; ++z) {      \
      if (z == n - 1) {                \
        cerr << l[z] << " | " << endl; \
      } else {                         \
        cerr << l[z] << " ";           \
      }                                \
    }                                  \
  };


  {                               \
    for (int z = 0; z < n; ++z) { \
      if (z == n - 1) {           \
        cout << l[z] << endl;     \
      } else {                    \
        cout << l[z] << " ";      \
      }                           \
    }                             \
  };








template <class T>
inline bool chmax(T& a, T b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
template <class T>
inline bool chmin(T& a, T b) {
  if (a > b) {
    a = b;
    return 1;
  }
  return 0;
}
template <class T>
inline bool pmap(T& mp) {
  cerr << "| ";
  for (auto itr = mp.begin(); itr != mp.end(); ++itr) {
    cerr << "key: " << itr->first << ", val: " << itr->second << " | ";
  }
  cerr << endl;
  return 0;
}

using ll = long long;
using Real = long double;
using CP = complex<Real>;
using P = pair<ll, ll>;
using st = string;
using vs = vector<string>;
using vvi = vector<vector<ll>>;
using vi = vector<ll>;
const ll MOD1 = 1000000007;
const ll MOD2 = 998244353;
const ll LINF = (1LL << 60);
const int INF = (1000000007);
const Real EPS = 1e-10;
const long double PI = 3.141592653589793238462643383279502884L;




ll lcm(ll x, ll y) { return ll(x / gcd(x, y)) * y; }

bool isprime(ll n) {
  if (n == 2) return true;
  if (n < 2 || !(n & 1)) return false;

  ll i = 3;
  while (i <= sqrt(n)) {
    if (n % i == 0) return false;
    i += 2;
  }
  return true;
}

vi id9(ll n) {
  ll rem = n;
  vi p;
  for (ll i = 2; i * i <= n; i++) {
    while (rem % i == 0) {
      rem /= i;
      p.pb(i);
    }
  }
  if (rem != 1LL) p.pb(rem);
  return p;
}

map<ll, int> id12(ll n) {
  map<ll, int> V;
  for (ll i = 2; i * i <= n; i++)
    while (n % i == 0) V[i]++, n /= i;
  if (n > 1) V[n]++;
  return V;
}

ll modpow(ll a, ll n, ll mod) {
  ll res = 1;
  while (n > 0) {
    if (n & 1) res = res * a % mod;
    a = a * a % mod;
    n >>= 1;
  }
  return res;
}

ll nck(ll n, ll k, ll modd) {
  ll p = 1, q = 1;
  for (ll i = 0; i < k; i++) {
    p = p * (n - i) % modd;
    q = q * (i + 1) % modd;
  }
  return p * modpow(q, modd - 2, modd) % modd;
}
ll dx[4] = {-1, 0, 1, 0};
ll dy[4] = {0, 1, 0, -1};

vector<P> id6 = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

vi id7(ll N) {
  vi res;
  for (ll i = 1; i * i <= N; ++i) {
    if (N % i == 0) {
      res.push_back(i);
      if (N / i != i) res.push_back(N / i);
    }
  }
  sort(res.begin(), res.end());
  return res;
}

const int mod = MOD1;

struct mint {
  ll x;
  mint(ll x = 0) : x((x % mod + mod) % mod) {}
  mint operator-() const { return mint(-x); }
  mint& operator+=(const mint a) {
    if ((x += a.x) >= mod) x -= mod;
    return *this;
  }
  mint& operator-=(const mint a) {
    if ((x += mod - a.x) >= mod) x -= mod;
    return *this;
  }
  mint& operator*=(const mint a) {
    (x *= a.x) %= mod;
    return *this;
  }
  mint operator+(const mint a) const { return mint(*this) += a; }
  mint operator-(const mint a) const { return mint(*this) -= a; }
  mint operator*(const mint a) const { return mint(*this) *= a; }
  mint pow(ll t) const {
    if (!t) return 1;
    mint a = pow(t >> 1);
    a *= a;
    if (t & 1) a *= *this;
    return a;
  }
  mint inv() const { return pow(mod - 2); }
  mint& operator/=(const mint a) { return *this *= a.inv(); }
  mint operator/(const mint a) const { return mint(*this) /= a; }
};

istream& operator>>(istream& is, mint& a) { return is >> a.x; }
ostream& operator<<(ostream& os, const mint& a) { return os << a.x; }

struct combination {
  vector<mint> fact, ifact;
  combination(int n) : fact(n + 1), ifact(n + 1) {
    assert(n < mod);
    fact[0] = 1;
    for (int i = 1; i <= n; ++i) fact[i] = fact[i - 1] * i;
    ifact[n] = fact[n].inv();
    for (int i = n; i >= 1; --i) ifact[i - 1] = ifact[i] * i;
  }
  mint operator()(int n, int k) {
    if (k < 0 || k > n) return 0;
    return fact[n] * ifact[k] * ifact[n - k];
  }
};

void init() {
  cin.tie(0);
  std::cout.tie(0);
  ios_base::sync_with_stdio(false);
}

void _main();
int main() {
  init();
  _main();
};











void solve() {
  st s;
  cin >> s;

  rep(i, 8) {
    ll sum = 0, f = 1;
    rep(j, s.size()) {
      if ((i >> (s[j] - 'A')) & 1) {
        sum++;
      } else {
        sum--;
      }
      if (sum < 0) f = 0;
    }
    if (f && sum == 0) {
      p("YES");
      return;
    }
  }
  p("NO");
}

void _main() {
  ll t;
  cin >> t;

  while (t--) {
    solve();
  }
}