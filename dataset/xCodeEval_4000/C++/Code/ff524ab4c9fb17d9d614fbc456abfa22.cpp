#ifndef COMMON_H
#define COMMON_H

#include <bits/stdc++.h>
#include <algorithm>
#include <chrono>
#include <complex>
#include <ext/rope>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <queue>
#include <random>
#ifndef COMPILER_MACRO_H
#define COMPILER_MACRO_H

#ifndef LOCAL

#pragma GCC diagnostic error "-std=c++14"
#pragma GCC target("avx")
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC target("sse4.2")
#pragma GCC optimize("inline")

#endif

#endif

using __gnu_cxx::rope;
using std::array;
using std::bitset;
using std::cerr;
using std::complex;
using std::deque;
using std::endl;
using std::fill;
using std::function;
using std::ios_base;
using std::istream;
using std::istream_iterator;
using std::iterator;
using std::make_pair;
using std::make_tuple;
using std::map;
using std::max;
using std::min;
using std::numeric_limits;
using std::ostream;
using std::pair;
using std::priority_queue;
using std::queue;
using std::reverse;
using std::rotate;
using std::set;
using std::sort;
using std::string;
using std::stringstream;
using std::swap;
using std::uniform_int_distribution;
using std::uniform_real_distribution;
using std::unique;
using std::unordered_map;
using std::vector;
using std::tuple;
using std::get;
using std::multiset;
using std::multimap;

typedef unsigned int ui;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef unsigned char byte;
std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());

const double E = 2.7182818284590452354;
const double PI = 3.14159265358979323846;

#define mp make_pair

#ifdef LOCAL
#define PREPARE_INPUT                                  \
  {                                                    \
    std::cout << "Input file name:";                   \
    string file;                                       \
    std::cin >> file;                                  \
    if (file != "stdin") {                             \
      file = string(__FILE__) + "/../" + file + ".in"; \
      std::cout << "Open file:" << file << std::endl;  \
      freopen(file.data(), "r", stdin);                \
    }                                                  \
  }
#else
#define PREPARE_INPUT
#endif

#define RUN_ONCE                                    \
  int main() {                                      \
    PREPARE_INPUT;                                  \
    std::ios_base::sync_with_stdio(false);          \
    std::cin.tie(0);                                \
    std::cout << std::setiosflags(std::ios::fixed); \
    std::cout << std::setprecision(15);             \
    solve(1, std::cin, std::cout);                  \
    return 0;                                       \
  }

#define RUN_MULTI                                   \
  int main() {                                      \
    PREPARE_INPUT;                                  \
    std::ios_base::sync_with_stdio(false);          \
    std::cin.tie(0);                                \
    std::cout << std::setiosflags(std::ios::fixed); \
    std::cout << std::setprecision(15);             \
    int t;                                          \
    std::cin >> t;                                  \
    for (int i = 1; i <= t; i++) {                  \
      solve(i, std::cin, std::cout);                \
    }                                               \
    return 0;                                       \
  }

#endif

#define C0(x) memset(x, 0, sizeof(x))
#define C1(x) memset(x, -1, sizeof(x))
#ifndef DEBUG_H
#define DEBUG_H



















#ifndef H_PRETTY_PRINT
#define H_PRETTY_PRINT

#include <cstddef>
#include <iterator>
#include <memory>
#include <ostream>
#include <set>
#include <tuple>
#include <type_traits>
#include <unordered_set>
#include <utility>
#include <valarray>

namespace pretty_print
{
    namespace detail
    {
        


        struct sfinae_base
        {
            using yes = char;
            using no  = yes[2];
        };

        template <typename T>
        struct has_const_iterator : private sfinae_base
        {
        private:
            template <typename C> static yes & test(typename C::const_iterator*);
            template <typename C> static no  & test(...);
        public:
            static const bool value = sizeof(test<T>(nullptr)) == sizeof(yes);
            using type =  T;
        };

        template <typename T>
        struct has_begin_end : private sfinae_base
        {
        private:
            template <typename C>
            static yes & f(typename std::enable_if<
                std::is_same<decltype(static_cast<typename C::const_iterator(C::*)() const>(&C::begin)),
                             typename C::const_iterator(C::*)() const>::value>::type *);

            template <typename C> static no & f(...);

            template <typename C>
            static yes & g(typename std::enable_if<
                std::is_same<decltype(static_cast<typename C::const_iterator(C::*)() const>(&C::end)),
                             typename C::const_iterator(C::*)() const>::value, void>::type*);

            template <typename C> static no & g(...);

        public:
            static bool const beg_value = sizeof(f<T>(nullptr)) == sizeof(yes);
            static bool const end_value = sizeof(g<T>(nullptr)) == sizeof(yes);
        };

    }  



    


    template <typename TChar>
    struct delimiters_values
    {
        using char_type = TChar;
        const char_type * prefix;
        const char_type * delimiter;
        const char_type * postfix;
    };


    


    template <typename T, typename TChar>
    struct delimiters
    {
        using type = delimiters_values<TChar>;
        static const type values; 
    };


    

    

    


    template <typename T,
              typename TChar = char,
              typename TCharTraits = ::std::char_traits<TChar>,
              typename TDelimiters = delimiters<T, TChar>>
    struct print_container_helper
    {
        using delimiters_type = TDelimiters;
        using ostream_type = std::basic_ostream<TChar, TCharTraits>;

        template <typename U>
        struct printer
        {
            static void print_body(const U & c, ostream_type & stream)
            {
                using std::begin;
                using std::end;

                auto it = begin(c);
                const auto the_end = end(c);

                if (it != the_end)
                {
                    for ( ; ; )
                    {
                        stream << *it;

                    if (++it == the_end) break;

                    if (delimiters_type::values.delimiter != NULL)
                        stream << delimiters_type::values.delimiter;
                    }
                }
            }
        };

        print_container_helper(const T & container)
        : container_(container)
        { }

        inline void operator()(ostream_type & stream) const
        {
            if (delimiters_type::values.prefix != NULL)
                stream << delimiters_type::values.prefix;

            printer<T>::print_body(container_, stream);

            if (delimiters_type::values.postfix != NULL)
                stream << delimiters_type::values.postfix;
        }

    private:
        const T & container_;
    };

    


    template <typename T, typename TChar, typename TCharTraits, typename TDelimiters>
    template <typename T1, typename T2>
    struct print_container_helper<T, TChar, TCharTraits, TDelimiters>::printer<std::pair<T1, T2>>
    {
        using ostream_type = typename print_container_helper<T, TChar, TCharTraits, TDelimiters>::ostream_type;

        static void print_body(const std::pair<T1, T2> & c, ostream_type & stream)
        {
            stream << c.first;
            if (print_container_helper<T, TChar, TCharTraits, TDelimiters>::delimiters_type::values.delimiter != NULL)
                stream << print_container_helper<T, TChar, TCharTraits, TDelimiters>::delimiters_type::values.delimiter;
            stream << c.second;
        }
    };

    


    template <typename T, typename TChar, typename TCharTraits, typename TDelimiters>
    template <typename ...Args>
    struct print_container_helper<T, TChar, TCharTraits, TDelimiters>::printer<std::tuple<Args...>>
    {
        using ostream_type = typename print_container_helper<T, TChar, TCharTraits, TDelimiters>::ostream_type;
        using element_type = std::tuple<Args...>;

        template <std::size_t I> struct Int { };

        static void print_body(const element_type & c, ostream_type & stream)
        {
            tuple_print(c, stream, Int<0>());
        }

        static void tuple_print(const element_type &, ostream_type &, Int<sizeof...(Args)>)
        {
        }

        static void tuple_print(const element_type & c, ostream_type & stream,
                                typename std::conditional<sizeof...(Args) != 0, Int<0>, std::nullptr_t>::type)
        {
            stream << std::get<0>(c);
            tuple_print(c, stream, Int<1>());
        }

        template <std::size_t N>
        static void tuple_print(const element_type & c, ostream_type & stream, Int<N>)
        {
            if (print_container_helper<T, TChar, TCharTraits, TDelimiters>::delimiters_type::values.delimiter != NULL)
                stream << print_container_helper<T, TChar, TCharTraits, TDelimiters>::delimiters_type::values.delimiter;

            stream << std::get<N>(c);

            tuple_print(c, stream, Int<N + 1>());
        }
    };

    


    template<typename T, typename TChar, typename TCharTraits, typename TDelimiters>
    inline std::basic_ostream<TChar, TCharTraits> & operator<<(
        std::basic_ostream<TChar, TCharTraits> & stream,
        const print_container_helper<T, TChar, TCharTraits, TDelimiters> & helper)
    {
        helper(stream);
        return stream;
    }


    


    template <typename T>
    struct is_container : public std::integral_constant<bool,
                                                        detail::has_const_iterator<T>::value &&
                                                        detail::has_begin_end<T>::beg_value  &&
                                                        detail::has_begin_end<T>::end_value> { };

    template <typename T, std::size_t N>
    struct is_container<T[N]> : std::true_type { };

    template <std::size_t N>
    struct is_container<char[N]> : std::false_type { };

    template <typename T>
    struct is_container<std::valarray<T>> : std::true_type { };

    template <typename T1, typename T2>
    struct is_container<std::pair<T1, T2>> : std::true_type { };

    template <typename ...Args>
    struct is_container<std::tuple<Args...>> : std::true_type { };


    


    template <typename T> struct delimiters<T, char> { static const delimiters_values<char> values; };
    template <typename T> const delimiters_values<char> delimiters<T, char>::values = { "[", ", ", "]" };
    template <typename T> struct delimiters<T, wchar_t> { static const delimiters_values<wchar_t> values; };
    template <typename T> const delimiters_values<wchar_t> delimiters<T, wchar_t>::values = { L"[", L", ", L"]" };


    


    template <typename T, typename TComp, typename TAllocator>
    struct delimiters< ::std::set<T, TComp, TAllocator>, char> { static const delimiters_values<char> values; };

    template <typename T, typename TComp, typename TAllocator>
    const delimiters_values<char> delimiters< ::std::set<T, TComp, TAllocator>, char>::values = { "{", ", ", "}" };

    template <typename T, typename TComp, typename TAllocator>
    struct delimiters< ::std::set<T, TComp, TAllocator>, wchar_t> { static const delimiters_values<wchar_t> values; };

    template <typename T, typename TComp, typename TAllocator>
    const delimiters_values<wchar_t> delimiters< ::std::set<T, TComp, TAllocator>, wchar_t>::values = { L"{", L", ", L"}" };

    template <typename T, typename TComp, typename TAllocator>
    struct delimiters< ::std::multiset<T, TComp, TAllocator>, char> { static const delimiters_values<char> values; };

    template <typename T, typename TComp, typename TAllocator>
    const delimiters_values<char> delimiters< ::std::multiset<T, TComp, TAllocator>, char>::values = { "{", ", ", "}" };

    template <typename T, typename TComp, typename TAllocator>
    struct delimiters< ::std::multiset<T, TComp, TAllocator>, wchar_t> { static const delimiters_values<wchar_t> values; };

    template <typename T, typename TComp, typename TAllocator>
    const delimiters_values<wchar_t> delimiters< ::std::multiset<T, TComp, TAllocator>, wchar_t>::values = { L"{", L", ", L"}" };

    template <typename T, typename THash, typename TEqual, typename TAllocator>
    struct delimiters< ::std::unordered_set<T, THash, TEqual, TAllocator>, char> { static const delimiters_values<char> values; };

    template <typename T, typename THash, typename TEqual, typename TAllocator>
    const delimiters_values<char> delimiters< ::std::unordered_set<T, THash, TEqual, TAllocator>, char>::values = { "{", ", ", "}" };

    template <typename T, typename THash, typename TEqual, typename TAllocator>
    struct delimiters< ::std::unordered_set<T, THash, TEqual, TAllocator>, wchar_t> { static const delimiters_values<wchar_t> values; };

    template <typename T, typename THash, typename TEqual, typename TAllocator>
    const delimiters_values<wchar_t> delimiters< ::std::unordered_set<T, THash, TEqual, TAllocator>, wchar_t>::values = { L"{", L", ", L"}" };

    template <typename T, typename THash, typename TEqual, typename TAllocator>
    struct delimiters< ::std::unordered_multiset<T, THash, TEqual, TAllocator>, char> { static const delimiters_values<char> values; };

    template <typename T, typename THash, typename TEqual, typename TAllocator>
    const delimiters_values<char> delimiters< ::std::unordered_multiset<T, THash, TEqual, TAllocator>, char>::values = { "{", ", ", "}" };

    template <typename T, typename THash, typename TEqual, typename TAllocator>
    struct delimiters< ::std::unordered_multiset<T, THash, TEqual, TAllocator>, wchar_t> { static const delimiters_values<wchar_t> values; };

    template <typename T, typename THash, typename TEqual, typename TAllocator>
    const delimiters_values<wchar_t> delimiters< ::std::unordered_multiset<T, THash, TEqual, TAllocator>, wchar_t>::values = { L"{", L", ", L"}" };


    


    template <typename T1, typename T2> struct delimiters<std::pair<T1, T2>, char> { static const delimiters_values<char> values; };
    template <typename T1, typename T2> const delimiters_values<char> delimiters<std::pair<T1, T2>, char>::values = { "(", ", ", ")" };
    template <typename T1, typename T2> struct delimiters< ::std::pair<T1, T2>, wchar_t> { static const delimiters_values<wchar_t> values; };
    template <typename T1, typename T2> const delimiters_values<wchar_t> delimiters< ::std::pair<T1, T2>, wchar_t>::values = { L"(", L", ", L")" };

    template <typename ...Args> struct delimiters<std::tuple<Args...>, char> { static const delimiters_values<char> values; };
    template <typename ...Args> const delimiters_values<char> delimiters<std::tuple<Args...>, char>::values = { "(", ", ", ")" };
    template <typename ...Args> struct delimiters< ::std::tuple<Args...>, wchar_t> { static const delimiters_values<wchar_t> values; };
    template <typename ...Args> const delimiters_values<wchar_t> delimiters< ::std::tuple<Args...>, wchar_t>::values = { L"(", L", ", L")" };


    

    

    


    struct custom_delims_base
    {
        virtual ~custom_delims_base() { }
        virtual std::ostream & stream(::std::ostream &) = 0;
        virtual std::wostream & stream(::std::wostream &) = 0;
    };

    template <typename T, typename Delims>
    struct custom_delims_wrapper : custom_delims_base
    {
        custom_delims_wrapper(const T & t_) : t(t_) { }

        std::ostream & stream(std::ostream & s)
        {
            return s << print_container_helper<T, char, std::char_traits<char>, Delims>(t);
        }

        std::wostream & stream(std::wostream & s)
        {
            return s << print_container_helper<T, wchar_t, std::char_traits<wchar_t>, Delims>(t);
        }

    private:
        const T & t;
    };

    template <typename Delims>
    struct custom_delims
    {
        template <typename Container>
        custom_delims(const Container & c) : base(new custom_delims_wrapper<Container, Delims>(c)) { }

        std::unique_ptr<custom_delims_base> base;
    };

    template <typename TChar, typename TCharTraits, typename Delims>
    inline std::basic_ostream<TChar, TCharTraits> & operator<<(std::basic_ostream<TChar, TCharTraits> & s, const custom_delims<Delims> & p)
    {
        return p.base->stream(s);
    }


    

    


    template<typename T>
    struct array_wrapper_n
    {
        typedef const T * const_iterator;
        typedef T value_type;

        array_wrapper_n(const T * const a, size_t n) : _array(a), _n(n) { }
        inline const_iterator begin() const { return _array; }
        inline const_iterator end() const { return _array + _n; }

    private:
        const T * const _array;
        size_t _n;
    };


    

    


    template <typename T>
    struct bucket_print_wrapper
    {
        typedef typename T::const_local_iterator const_iterator;
        typedef typename T::size_type size_type;

        const_iterator begin() const
        {
            return m_map.cbegin(n);
        }

        const_iterator end() const
        {
            return m_map.cend(n);
        }

        bucket_print_wrapper(const T & m, size_type bucket) : m_map(m), n(bucket) { }

    private:
        const T & m_map;
        const size_type n;
    };

}   






template<typename T>
inline pretty_print::array_wrapper_n<T> pretty_print_array(const T * const a, size_t n)
{
    return pretty_print::array_wrapper_n<T>(a, n);
}

template <typename T> pretty_print::bucket_print_wrapper<T>
bucket_print(const T & m, typename T::size_type n)
{
    return pretty_print::bucket_print_wrapper<T>(m, n);
}







namespace std
{
    


    template<typename T, typename TChar, typename TCharTraits>
    inline typename enable_if< ::pretty_print::is_container<T>::value,
                              basic_ostream<TChar, TCharTraits> &>::type
    operator<<(basic_ostream<TChar, TCharTraits> & stream, const T & container)
    {
        return stream << ::pretty_print::print_container_helper<T, TChar, TCharTraits>(container);
    }
}



#endif  


#ifdef LOCAL
#define dbg(args...)                         \
  {                                          \
    string _s = #args;                       \
    replace(_s.begin(), _s.end(), ',', ' '); \
    stringstream _ss(_s);                    \
    istream_iterator<string> _it(_ss);       \
    err(_it, args);                          \
  }
void err(std::istream_iterator<string> it) {}
template <typename T, typename... Args>
void err(std::istream_iterator<string> it, T a, Args... args) {
  cerr << *it << " = " << a << endl;
  err(++it, args...);
}
#define dbg2(x) cerr << #x << "=" << (x) << endl
#else
#define dbg(args...) 42
#define dbg2(x) 42
#endif

#endif

#ifndef DECIMAL_H
#define DECIMAL_H

namespace decimal {

ll Merge(int a, int b) {
  static ll mask = (1ll << 32) - 1;
  return ((ll)a << 32) | ((ll)b & mask);
}

template <class T>
T CeilDiv(T a, T b) {
  if (b < 0) {
    a = -a;
    b = -b;
  }
  T div = a / b;
  if (b * div < a) {
    div++;
  }
  return div;
}

template <class T>
T FloorDiv(T a, T b) {
  if (b < 0) {
    a = -a;
    b = -b;
  }
  T div = a / b;
  if (b * div > a) {
    div--;
  }
  return div;
}

template <class T>
T RoundToInt(double x) {
  return x >= 0 ? x + 0.5 : x - 0.5;
}
template <class T>
int Sign(T x) {
  return x < 0 ? -1 : x > 0 ? 1 : 0;
}
template <class T>
bool IsPlusOverflow(T a, T b) {
  if (Sign(a) != Sign(b)) {
    return false;
  }
  if (a < 0) {
    return a + b > 0;
  } else {
    return a + b < 0;
  }
}
template <class T>
bool IsMultiplicationOverflow(T a, T b, T limit) {
  if (limit < 0) {
    limit = -limit;
  }
  if (a < 0) {
    a = -a;
  }
  if (b < 0) {
    b = -b;
  }
  if (a == 0 || b == 0) {
    return false;
  }
  

  return a > limit / b;
}
}  


#endif
#ifndef HASH_H
#define HASH_H


#ifndef MODULAR_H
#define MODULAR_H


#ifndef GCD_H
#define GCD_H



namespace gcd {
template <typename T>
T Gcd0(T a, T b) {
  return b ? Gcd0(b, a % b) : a;
}

template <typename T>
T Gcd(T a, T b) {
  if (a < b) {
    swap(a, b);
  }
  return Gcd0(a, b);
}

template <typename T>
T Extgcd0(T a, T b, T &x, T &y) {
  if (!b) {
    x = 1;
    y = 0;
    return a;
  }
  T ans = Extgcd0(b, a % b, y, x);
  y = y - x * (a / b);
  return ans;
}


template <typename T>
T Extgcd(T a, T b, T &x, T &y) {
  if (a >= b) {
    return Extgcd0(a, b, x, y);
  }
  return Extgcd0(b, a, y, x);
}


template <class T>
T Extgcd(vector<T> &arg, vector<T> &coes) {
  int n = arg.size();
  if (n == 0) {
    return 0;
  }
  coes.resize(n);
  vector<T> gs(n);
  gs[0] = arg[0];
  for (int i = 1; i < n; i++) {
    gs[i] = Gcd(gs[i - 1], arg[i]);
  }
  T prod = 1;
  for (int i = n - 1; i >= 1; i--) {
    T a, b;
    Extgcd0(gs[i - 1], arg[i], a, b);
    coes[i] = b * prod;
    prod *= a;
  }
  coes[0] = prod;
  return gs[n - 1];
}

}  


#endif

namespace modular {
template <class T>
inline T Mod(T x, T m) {
  x %= m;
  if (x < 0) {
    x += m;
  }
  return x;
}

template <class T>
inline T Modmul(T a, T b, T m) {
  T k = (T)((long double)a / m * b + 0.5);
  return Mod<T>(a * b - k * m, m);
}

template <>
inline int Modmul<int>(int a, int b, int m) {
  return Mod<long long>((long long)a * b, m);
}

template <class T>
inline T Modpow(T x, long long n, T m) {
  if (n == 0) {
    return Mod<T>(1, m);
  }
  T ans = Modpow<T>(x, n >> 1, m);
  ans = Modmul<T>(ans, ans, m);
  if (n & 1) {
    ans = Modmul<T>(ans, x, m);
  }
  return ans;
}

template <typename T>
T Inverse(T a, T m) {
  int x, y;
  gcd::Extgcd(a, m, x, y);
  return Mod(x, m);
}


template <class T>
T Extgcd(vector<T> &arg, vector<T> &coes, T mod) {
  int n = arg.size();
  if (n == 0) {
    return 0;
  }
  coes.resize(n);
  vector<T> gs(n);
  gs[0] = arg[0];
  for (int i = 1; i < n; i++) {
    gs[i] = gcd::Gcd(gs[i - 1], arg[i]);
  }
  T prod = 1;
  for (int i = n - 1; i >= 1; i--) {
    T a, b;
    gcd::Extgcd0(gs[i - 1], arg[i], a, b);
    coes[i] = Modmul(b, prod, mod);
    prod = Modmul(prod, a, mod);
  }
  coes[0] = prod;
  return gs[n - 1];
}


template <class T>
void InverseRange(vector<T> &vec, T mod) {
  int n = vec.size();
  if (n <= 1) {
    return;
  }
  vec[1] = 1;
  for (int i = 2; i < n; i++) {
    T k = mod / i;
    T r = mod % i;
    vec[i] = Modmul(-k, vec[r], mod);
  }
}

template <class T, T M>
class Modular {
 public:
  Modular() { set(0); }
  Modular(const T &val) { set(val); }
  void set(const T &x) { _v = Mod(x, M); }
  Modular(const Modular<T, M> &val) { _v = val._v; }
  Modular<T, M> &operator=(const Modular<T, M> &y) {
    _v = y._v;
    return *this;
  }
  const T &operator()() const { return _v; }
  T &operator()() { return _v; }
  Modular<T, M> &operator-=(const Modular<T, M> &y) {
    _v = Mod(_v - y._v, M);
    return *this;
  }
  Modular<T, M> &operator+=(const Modular<T, M> &y) {
    _v = Mod(_v + y._v, M);
    return *this;
  }

  Modular<T, M> &operator*=(const Modular<T, M> &y) {
    _v = Modmul(_v, y._v, M);
    return *this;
  }
  Modular<T, M> &operator/=(const Modular<T, M> &y) {
    (*this) *= y.inverse();
    return *this;
  }
  Modular<T, M> pow(long long exp) const { return Modpow(_v, exp, M); }
  Modular<T, M> inverse() const { return modular::Inverse(_v, M); }

 private:
  T _v;
};

template <class T, T M>
Modular<T, M> operator+(const Modular<T, M> &a, const Modular<T, M> &b) {
  Modular<T, M> ans = a;
  ans += b;
  return ans;
}
template <class T, T M>
Modular<T, M> operator+(const T &a, const Modular<T, M> &b) {
  Modular<T, M> ans = a;
  ans += b;
  return ans;
}
template <class T, T M>
Modular<T, M> operator+(const Modular<T, M> &a, const T &b) {
  Modular<T, M> ans = a;
  ans += b;
  return ans;
}
template <class T, T M>
Modular<T, M> operator-(const Modular<T, M> &a, const Modular<T, M> &b) {
  Modular<T, M> ans = a;
  ans -= b;
  return ans;
}
template <class T, T M>
Modular<T, M> operator-(const T &a, const Modular<T, M> &b) {
  Modular<T, M> ans = a;
  ans -= b;
  return ans;
}
template <class T, T M>
Modular<T, M> operator-(const Modular<T, M> &a, const T &b) {
  Modular<T, M> ans = a;
  ans -= b;
  return ans;
}
template <class T, T M>
Modular<T, M> operator*(const Modular<T, M> &a, const Modular<T, M> &b) {
  Modular<T, M> ans = a;
  ans *= b;
  return ans;
}
template <class T, T M>
Modular<T, M> operator*(const T &a, const Modular<T, M> &b) {
  Modular<T, M> ans = a;
  ans *= b;
  return ans;
}
template <class T, T M>
Modular<T, M> operator*(const Modular<T, M> &a, const T &b) {
  Modular<T, M> ans = a;
  ans *= b;
  return ans;
}
template <class T, T M>
Modular<T, M> operator/(const Modular<T, M> &a, const Modular<T, M> &b) {
  Modular<T, M> ans = a;
  ans /= b;
  return ans;
}
template <class T, T M>
Modular<T, M> operator/(const T &a, const Modular<T, M> &b) {
  Modular<T, M> ans = a;
  ans /= b;
  return ans;
}
template <class T, T M>
Modular<T, M> operator/(const Modular<T, M> &a, const T &b) {
  Modular<T, M> ans = a;
  ans /= b;
  return ans;
}
template <class T, T M>
Modular<T, M> operator==(const Modular<T, M> &a, const Modular<T, M> &b) {
  return a() == b();
}
template <class T, T M>
Modular<T, M> operator==(const Modular<T, M> &a, const T &b) {
  return a() == Modular<T, M>(b);
}
template <class T, T M>
Modular<T, M> operator==(const T &a, const Modular<T, M> &b) {
  return Modular<T, M>(a) == b;
}
template <class T, T M>
Modular<T, M> operator!=(const Modular<T, M> &a, const Modular<T, M> &b) {
  return a() != b();
}
template <class T, T M>
Modular<T, M> operator!=(const Modular<T, M> &a, const T &b) {
  return a() != Modular<T, M>(b);
}
template <class T, T M>
Modular<T, M> operator!=(const T &a, const Modular<T, M> &b) {
  return Modular<T, M>(a) != b;
}
template <class T, T M>
std::ostream &operator<<(std::ostream &out, const Modular<T, M> &v) {
  return out << v();
}
template <class T, T M>
std::istream &operator>>(std::istream &in, const Modular<T, M> &v) {
  T x;
  in >> x;
  v.set(x);
  return in;
}
}  


#endif

namespace hash {
struct CustomHash {
  static uint64_t splitmix64(uint64_t x) {
    

    x += 0x9e3779b97f4a7c15;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
    return x ^ (x >> 31);
  }

  size_t operator()(uint64_t x) const {
    static const uint64_t FIXED_RANDOM =
        std::chrono::steady_clock::now().time_since_epoch().count();
    return splitmix64(x + FIXED_RANDOM);
  }
};

template <int N, int X>
struct HashData {
  using Mint = modular::Modular<int, (int)1e9 + 7>;
  Mint inv[N + 1];
  Mint pow[N + 1];
  HashData() {
    pow[0] = inv[0] = 1;
    Mint x(X);
    Mint invX = 1 / x;
    for (int i = 1; i <= N; i++) {
      inv[i] = inv[i - 1] * invX;
      pow[i] = pow[i - 1] * x;
    }
  }
};

template <int N, int M, int X>
class PartialHash {
 private:
  using Mint = modular::Modular<int, (int)1e9 + 7>;
  Mint _h[N + 1];
  const HashData<M, X> &_hd;

 public:
  PartialHash(const HashData<M, X> &hd) : _hd(hd) { assert(N <= M); }

  void reset(const function<int(int)> &func, int l, int r) {
    assert(l <= r);
    if (l > 0) {
      _h[l - 1] = 0;
    }
    Mint x = _h[l] = func(l) * _hd.pow[l];
    for (int i = l + 1; i <= r; i++) {
      _h[i] = _h[i - 1] + func(i) * _hd.pow[i];
    }
  }

  int hash(int l, int r, bool verbose = false) {
    Mint h = _h[r];
    if (l > 0) {
      h -= _h[l - 1];
      h *= _hd.inv[l];
    }
    if (verbose) {
      h += _hd.pow[r - l + 1];
    }
    return h();
  }
};

template <int N, int M, int X>
class RollingHash {
 private:
  using Mint = modular::Modular<int, (int)1e9 + 7>;
  deque<int> _dq;
  Mint _h;
  const HashData<M, X> &_hd;

 public:
  RollingHash(const HashData<M, X> &hd) : _hd(hd) { assert(N <= M); }

  void reset() {
    _h = 0;
    _dq.clear();
  }

  void pop() {
    _h -= _dq.front();
    _h *= _hd.inv[1];
    _dq.pop_front();
  }

  void push(int v) {
    _h += _hd.pow[_dq.size()] * v;
    _dq.push_back(v);
  }

  int hash(bool verbose = false) {
    Mint h = _h;
    if (verbose) {
      h += _hd.pow[_dq.size()];
    }
    return h();
  }
};

template <int N, int M, int X>
class ModifiableHash {
 private:
  using Mint = modular::Modular<int, (int)1e9 + 7>;
  Mint _vals[N];
  Mint _h;
  const HashData<M, X> &_hd;

 public:
  ModifiableHash(const HashData<M, X> &hd) : _hd(hd) {}

  void reset() {
    for (int i = 0; i < N; i++) {
      _vals[i] = 0;
    }
    _h = 0;
  }

  void set(int i, int x) {
    _h += (x - _vals[i]) * _hd.pow[i];
    _vals[i] = x;
  }

  int hash() { return _h(); }
};

}  


#endif
#ifndef VERSION_ARRAY_H
#define VERSION_ARRAY_H



namespace version_array {
template <class T, int N>
class VersionArray {
 private:
  T _data[N];
  int _version[N];
  T _def;
  int _now;
  inline void access(int i) {
    if (_version[i] != _now) {
      _version[i] = _now;
      _data[i] = _def;
    }
  }

 public:
  VersionArray(const T &def = 0) : _def(def), _now(0) { C0(_version); }
  inline void clear() { _now++; }
  inline T &operator[](int i) {
    access(i);
    return _data[i];
  }
};
}  


#endif

using decimal::Merge;

int va[3][5];
hash::HashData<30, 31> hd31;
hash::HashData<30, 61> hd61;
hash::RollingHash<30, 30, 31> rh31(hd31);
hash::RollingHash<30, 30, 61> rh61(hd61);

int Mex(int i) {
  int ans = 0;
  while (va[i][ans]) {
    ans++;
  }
  return ans;
}

int Sg(vector<int> &sg, int pBegin, int pLen, ll n) {
  if (n >= pBegin) {
    n = pBegin + (n - pBegin) % pLen;
  }
  return sg[n];
}

void solve(int testId, istream &in, ostream &out) {
  int n, x, y, z;
  in >> n >> x >> y >> z;
  vector<vector<int>> sg(3);
  rh31.reset();
  rh61.reset();
  unordered_map<ll, int, hash::CustomHash> umap;
  for (int i = 0; i < 3; i++) {
    sg[i].push_back(0);
  }
  for (int i = 1; i < 5; i++) {
    C0(va);
    for (int j = 0; j < 3; j++) {
      va[j][sg[0][max(0, i - x)]]++;
    }
    va[0][sg[1][max(0, i - y)]]++;
    va[2][sg[1][max(0, i - y)]]++;
    va[0][sg[2][max(0, i - z)]]++;
    va[1][sg[2][max(0, i - z)]]++;

    for (int j = 0; j < 3; j++) {
      sg[j].push_back(Mex(j));
    }
  }

  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 3; j++) {
      rh31.push(sg[j][i]);
      rh61.push(sg[j][i]);
    }
  }

  int periodBegin = -1;
  int periodLength = -1;
  for (int i = 5;; i++) {
    ll key = Merge(rh31.hash(), rh61.hash());
    if (umap.find(key) != umap.end()) {
      periodBegin = umap[key];
      periodLength = i - periodBegin;
      break;
    }
    umap[key] = i;

    for (int j = 0; j < 3; j++) {
      rh31.pop();
      rh61.pop();
    }

    C0(va);
    for (int j = 0; j < 3; j++) {
      va[j][sg[0][i - x]]++;
    }
    va[0][sg[1][i - y]]++;
    va[2][sg[1][i - y]]++;
    va[0][sg[2][i - z]]++;
    va[1][sg[2][i - z]]++;

    for (int j = 0; j < 3; j++) {
      sg[j].push_back(Mex(j));
      rh31.push(sg[j][i]);
      rh61.push(sg[j][i]);
    }
  }

  dbg(periodBegin, periodLength);
  dbg(sg);
  int sum = 0;
  vector<ll> a(n);
  for (int i = 0; i < n; i++) {
    in >> a[i];
    sum ^= Sg(sg[0], periodBegin, periodLength, a[i]);
  }

  int ans = 0;
  for (int i = 0; i < n; i++) {
    int tmp = sum ^ Sg(sg[0], periodBegin, periodLength, a[i]);
    if ((tmp ^ Sg(sg[0], periodBegin, periodLength, max<ll>(0, a[i] - x))) ==
        0) {
      ans++;
    }
    if ((tmp ^ Sg(sg[1], periodBegin, periodLength, max<ll>(0, a[i] - y))) ==
        0) {
      ans++;
    }
    if ((tmp ^ Sg(sg[2], periodBegin, periodLength, max<ll>(0, a[i] - z))) ==
        0) {
      ans++;
    }
  }

  out << ans << endl;
}

RUN_MULTI