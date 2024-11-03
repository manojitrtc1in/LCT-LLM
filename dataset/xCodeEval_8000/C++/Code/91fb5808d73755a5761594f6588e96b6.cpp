#include <bits/stdc++.h>
using namespace std;




#include <cmath>
#include <complex>
#include <regex>

#ifndef DBG_MACRO_DBG_H
#define DBG_MACRO_DBG_H

#if defined(__unix__) || (defined(__APPLE__) && defined(__MACH__))
#define DBG_MACRO_UNIX
#elif defined(_MSC_VER)
#define DBG_MACRO_WINDOWS
#endif

#include <algorithm>
#include <chrono>
#include <ctime>
#include <iomanip>
#include <ios>
#include <iostream>
#include <memory>
#include <sstream>
#include <string>
#include <tuple>
#include <type_traits>
#include <vector>

#ifdef DBG_MACRO_UNIX
#include <unistd.h>
#endif

#if __cplusplus >= 201703L
#define DBG_MACRO_CXX_STANDARD 17
#elif __cplusplus >= 201402L
#define DBG_MACRO_CXX_STANDARD 14
#else
#define DBG_MACRO_CXX_STANDARD 11
#endif

#if DBG_MACRO_CXX_STANDARD >= 17
#include <optional>
#include <variant>
#endif

namespace dbg {

#ifdef DBG_MACRO_UNIX
inline bool isColorizedOutputEnabled() { return isatty(fileno(stderr)); }
#else
inline bool isColorizedOutputEnabled() { return true; }
#endif

struct time {};

namespace pretty_function {






#if defined(__clang__)
#define DBG_MACRO_PRETTY_FUNCTION __PRETTY_FUNCTION__
static constexpr size_t PREFIX_LENGTH =
    sizeof("const char *dbg::type_name_impl() [T = ") - 1;
static constexpr size_t SUFFIX_LENGTH = sizeof("]") - 1;
#elif defined(__GNUC__) && !defined(__clang__)
#define DBG_MACRO_PRETTY_FUNCTION __PRETTY_FUNCTION__
static constexpr size_t PREFIX_LENGTH =
    sizeof("const char* dbg::type_name_impl() [with T = ") - 1;
static constexpr size_t SUFFIX_LENGTH = sizeof("]") - 1;
#elif defined(_MSC_VER)
#define DBG_MACRO_PRETTY_FUNCTION __FUNCSIG__
static constexpr size_t PREFIX_LENGTH =
    sizeof("const char *__cdecl dbg::type_name_impl<") - 1;
static constexpr size_t SUFFIX_LENGTH = sizeof(">(void)") - 1;
#else
#error "This compiler is currently not supported by dbg_macro."
#endif

}  





template <typename T>
struct print_formatted {
  static_assert(std::is_integral<T>::value,
                "Only integral types are supported.");

  print_formatted(T value, int numeric_base)
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
print_formatted<T> hex(T value) {
  return print_formatted<T>{value, 16};
}

template <typename T>
print_formatted<T> oct(T value) {
  return print_formatted<T>{value, 8};
}

template <typename T>
print_formatted<T> bin(T value) {
  return print_formatted<T>{value, 2};
}




template <typename T>
const char* type_name_impl() {
  return DBG_MACRO_PRETTY_FUNCTION;
}

template <typename T>
struct type_tag {};

template <int&... ExplicitArgumentBarrier, typename T>
std::string get_type_name(type_tag<T>) {
  namespace pf = pretty_function;

  std::string type = type_name_impl<T>();
  return type.substr(pf::PREFIX_LENGTH,
                     type.size() - pf::PREFIX_LENGTH - pf::SUFFIX_LENGTH);
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
  return get_type_name(type_tag<T>{});
}

inline std::string get_type_name(type_tag<short>) { return "short"; }

inline std::string get_type_name(type_tag<unsigned short>) {
  return "unsigned short";
}

inline std::string get_type_name(type_tag<long>) { return "long"; }

inline std::string get_type_name(type_tag<unsigned long>) {
  return "unsigned long";
}

inline std::string get_type_name(type_tag<std::string>) {
  return "std::string";
}

template <typename T>
std::string get_type_name(type_tag<std::vector<T, std::allocator<T>>>) {
  return "std::vector<" + type_name<T>() + ">";
}

template <typename T1, typename T2>
std::string get_type_name(type_tag<std::pair<T1, T2>>) {
  return "std::pair<" + type_name<T1>() + ", " + type_name<T2>() + ">";
}

template <typename... T>
std::string type_list_to_string() {
  std::string result;
  auto unused = {(result += type_name<T>() + ", ", 0)..., 0};
  static_cast<void>(unused);

#if DBG_MACRO_CXX_STANDARD >= 17
  if constexpr (sizeof...(T) > 0) {
#else
  if (sizeof...(T) > 0) {
#endif
    result.pop_back();
    result.pop_back();
  }
  return result;
}

template <typename... T>
std::string get_type_name(type_tag<std::tuple<T...>>) {
  return "std::tuple<" + type_list_to_string<T...>() + ">";
}

template <typename T>
inline std::string get_type_name(type_tag<print_formatted<T>>) {
  return type_name<T>();
}




namespace detail_detector {

struct nonesuch {
  nonesuch() = delete;
  ~nonesuch() = delete;
  nonesuch(nonesuch const&) = delete;
  void operator=(nonesuch const&) = delete;
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
    typename detail_detector::detector<detail_detector::nonesuch, void, Op,
                                       Args...>::value_t;

namespace detail {

namespace {
using std::begin;
using std::end;
#if DBG_MACRO_CXX_STANDARD < 17
template <typename T>
constexpr auto size(const T& c) -> decltype(c.size()) {
  return c.size();
}
template <typename T, std::size_t N>
constexpr std::size_t size(const T (&)[N]) {
  return N;
}
#else
using std::size;
#endif
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
inline bool pretty_print(std::ostream& stream, const print_formatted<T>& value);

template <typename T>
inline bool pretty_print(std::ostream& stream, const print_type<T>&);

template <typename Enum>
inline typename std::enable_if<std::is_enum<Enum>::value, bool>::type
pretty_print(std::ostream& stream, Enum const& value);

inline bool pretty_print(std::ostream& stream, const std::string& value);

#if DBG_MACRO_CXX_STANDARD >= 17

inline bool pretty_print(std::ostream& stream, const std::string_view& value);

#endif

template <typename T1, typename T2>
inline bool pretty_print(std::ostream& stream, const std::pair<T1, T2>& value);

#if DBG_MACRO_CXX_STANDARD >= 17

template <typename T>
inline bool pretty_print(std::ostream& stream, const std::optional<T>& value);

template <typename... Ts>
inline bool pretty_print(std::ostream& stream,
                         const std::variant<Ts...>& value);

#endif

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
std::string decimalToBinary(T n) {
  const size_t length = 8 * sizeof(T);
  std::string toRet;
  toRet.resize(length);

  for (size_t i = 0; i < length; ++i) {
    const auto bit_at_index_i = static_cast<char>((n >> i) & 1);
    toRet[length - 1 - i] = bit_at_index_i + '0';
  }

  return toRet;
}

template <typename T>
inline bool pretty_print(std::ostream& stream,
                         const print_formatted<T>& value) {
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
      stream << decimalToBinary(value.inner);
    } else {
      using unsigned_type = typename std::make_unsigned<T>::type;
      stream << decimalToBinary<unsigned_type>(
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

#if DBG_MACRO_CXX_STANDARD >= 17

inline bool pretty_print(std::ostream& stream, const std::string_view& value) {
  stream << '"' << std::string(value) << '"';
  return true;
}

#endif

template <typename T1, typename T2>
inline bool pretty_print(std::ostream& stream, const std::pair<T1, T2>& value) {
  stream << "{";
  pretty_print(stream, value.first);
  stream << ", ";
  pretty_print(stream, value.second);
  stream << "}";
  return true;
}

#if DBG_MACRO_CXX_STANDARD >= 17

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

#endif

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
      : m_use_colorized_output(isColorizedOutputEnabled()) {
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
    const bool print_expr_and_type = pretty_print(stream_value, ref);

    std::stringstream output;
    output << m_location;
    if (print_expr_and_type) {
      output << ansi(ANSI_EXPRESSION) << *expr << ansi(ANSI_RESET) << " = ";
    }
    output << ansi(ANSI_VALUE) << stream_value.str() << ansi(ANSI_RESET);
    if (print_expr_and_type) {
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


#ifndef DBG_MACRO_DISABLE







#define DBG_IDENTITY(x) x
#define DBG_CALL(fn, args) DBG_IDENTITY(fn args)

#define DBG_CAT_IMPL(_1, _2) _1##_2
#define DBG_CAT(_1, _2) DBG_CAT_IMPL(_1, _2)

#define DBG_16TH_IMPL(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, \
                      _14, _15, _16, ...)                                     \
  _16
#define DBG_16TH(args) DBG_CALL(DBG_16TH_IMPL, args)
#define DBG_NARG(...) \
  DBG_16TH((__VA_ARGS__, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0))



#define DBG_VARIADIC_CALL(fn, data, ...) \
  DBG_CAT(fn##_, DBG_NARG(__VA_ARGS__))(data, (__VA_ARGS__))



#define DBG_HEAD_IMPL(_1, ...) _1
#define DBG_HEAD(args) DBG_CALL(DBG_HEAD_IMPL, args)



#define DBG_TAIL_IMPL(_1, ...) (__VA_ARGS__)
#define DBG_TAIL(args) DBG_CALL(DBG_TAIL_IMPL, args)

#define DBG_MAP_1(fn, args) DBG_CALL(fn, args)
#define DBG_MAP_2(fn, args) fn(DBG_HEAD(args)), DBG_MAP_1(fn, DBG_TAIL(args))
#define DBG_MAP_3(fn, args) fn(DBG_HEAD(args)), DBG_MAP_2(fn, DBG_TAIL(args))
#define DBG_MAP_4(fn, args) fn(DBG_HEAD(args)), DBG_MAP_3(fn, DBG_TAIL(args))
#define DBG_MAP_5(fn, args) fn(DBG_HEAD(args)), DBG_MAP_4(fn, DBG_TAIL(args))
#define DBG_MAP_6(fn, args) fn(DBG_HEAD(args)), DBG_MAP_5(fn, DBG_TAIL(args))
#define DBG_MAP_7(fn, args) fn(DBG_HEAD(args)), DBG_MAP_6(fn, DBG_TAIL(args))
#define DBG_MAP_8(fn, args) fn(DBG_HEAD(args)), DBG_MAP_7(fn, DBG_TAIL(args))
#define DBG_MAP_9(fn, args) fn(DBG_HEAD(args)), DBG_MAP_8(fn, DBG_TAIL(args))
#define DBG_MAP_10(fn, args) fn(DBG_HEAD(args)), DBG_MAP_9(fn, DBG_TAIL(args))
#define DBG_MAP_11(fn, args) fn(DBG_HEAD(args)), DBG_MAP_10(fn, DBG_TAIL(args))
#define DBG_MAP_12(fn, args) fn(DBG_HEAD(args)), DBG_MAP_11(fn, DBG_TAIL(args))
#define DBG_MAP_13(fn, args) fn(DBG_HEAD(args)), DBG_MAP_12(fn, DBG_TAIL(args))
#define DBG_MAP_14(fn, args) fn(DBG_HEAD(args)), DBG_MAP_13(fn, DBG_TAIL(args))
#define DBG_MAP_15(fn, args) fn(DBG_HEAD(args)), DBG_MAP_14(fn, DBG_TAIL(args))
#define DBG_MAP_16(fn, args) fn(DBG_HEAD(args)), DBG_MAP_15(fn, DBG_TAIL(args))



#define DBG_MAP(fn, ...) DBG_VARIADIC_CALL(DBG_MAP, fn, __VA_ARGS__)

#define DBG_STRINGIFY_IMPL(x) #x
#define DBG_STRINGIFY(x) DBG_STRINGIFY_IMPL(x)

#define DBG_TYPE_NAME(x) dbg::type_name<decltype(x)>()

#define dbg(...)                                    \
  dbg::DebugOutput(__FILE__, __LINE__, __func__)    \
      .print({DBG_MAP(DBG_STRINGIFY, __VA_ARGS__)}, \
             {DBG_MAP(DBG_TYPE_NAME, __VA_ARGS__)}, __VA_ARGS__)
#else
#define dbg(...) dbg::identity(__VA_ARGS__)
#endif  


#endif  










#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i <= n; ++i)
#define reps(i, s, e) for (int i = s; i < e; ++i)
#define rrep(i, n) for (int i = n - 1; 0 <= i; --i)
#define fore(i, a) for (auto& i : a)
#define cina(a) cin >> a;
#define cinb(a, b) cin >> a >> b;
#define cinc(a, b, c) cin >> a >> b >> c;
#define cind(a, b, c, d) cin >> a >> b >> c >> d;
#define cine(a, b, c, d, e) cin >> a >> b >> c >> d >> e;
#define cendl std::cout << endl;
#define forcin(a) \
  for (auto& it : a) cin >> it;
#define p(ans) std::cout << ans << endl;
#define p2(ans, ans2) std::cout << ans << " " << ans2 << endl;
#define p3(ans, ans2, ans3) \
  std::cout << ans << " " << ans2 << " " << ans3 << endl;
#define p4(ans, ans2, ans3, ans4) \
  std::cout << ans << " " << ans2 << " " << ans3 << " " << ans4 << endl;
#define dd(arg) cerr << " | " << #arg << " = | " << arg << " | " << endl;
#define dd2(arg, arg2)                                                    \
  cerr << "| " << #arg << " = " << arg << " | " << #arg2 << " = " << arg2 \
       << " | " << endl;
#define dd3(arg, arg2, arg3)                                              \
  cerr << "| " << #arg << " = " << arg << " | " << #arg2 << " = " << arg2 \
       << " | " << #arg3 << " = " << arg3 << " | " << endl;
#define dd4(arg, arg2, arg3, arg4)                                           \
  cerr << "| " << #arg << " = " << arg << " | " << #arg2 << " = " << arg2    \
       << " | " << #arg3 << " = " << arg3 << " | " << #arg4 << " = " << arg4 \
       << " | " << endl;
#define dl(n, l)                       \
  {                                    \
    cerr << " | " << #l << " = ";      \
    for (int z = 0; z < n; ++z) {      \
      if (z == n - 1) {                \
        cerr << l[z] << " | " << endl; \
      } else {                         \
        cerr << l[z] << " ";           \
      }                                \
    }                                  \
  };

#define pl(n, l)                  \
  {                               \
    for (int z = 0; z < n; ++z) { \
      if (z == n - 1) {           \
        cout << l[z] << endl;     \
      } else {                    \
        cout << l[z] << " ";      \
      }                           \
    }                             \
  };

#define pb push_back
#define all(v) v.begin(), v.end()
#define allr(v) v.rbegin(), v.rend()
#define endl '\n'
#define posl(vec, elm) lower_bound(vec.begin(), vec.end(), elm) - vec.begin()
#define posu(vec, elm) upper_bound(vec.begin(), vec.end(), elm) - vec.begin()

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

vi prime_factors(ll n) {
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

map<ll, int> prime_factorize_count(ll n) {
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

vector<P> dydx = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

vi enum_divisors(ll N) {
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