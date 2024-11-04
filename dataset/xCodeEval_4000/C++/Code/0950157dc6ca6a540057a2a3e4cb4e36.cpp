#include <bits/stdc++.h>
#ifndef _LIB_POLYNOMIAL_RING
#define _LIB_POLYNOMIAL_RING
#include <bits/stdc++.h>
#ifndef _LIB_MODULAR_INTEGER
#define _LIB_MODULAR_INTEGER
#include <bits/stdc++.h>
#ifndef _LIB_NUMBER_THEORY
#define _LIB_NUMBER_THEORY
#include <bits/stdc++.h>

namespace lib {
  using namespace std;
namespace nt {
  int64_t inverse(int64_t a, int64_t b) {
    long long b0 = b, t, q;
    long long x0 = 0, x1 = 1;
    if (b == 1) return 1;
    while (a > 1) {
      q = a / b;
      t = b, b = a % b, a = t;
      t = x0, x0 = x1 - q * x0, x1 = t;
    }
    if (x1 < 0) x1 += b0;
    return x1;
  }
}
}  


#endif

#if __cplusplus < 201300
#error required(c++14)
#endif

namespace lib {
  using namespace std;
namespace {
  template<typename T, T ...Mods>
  struct ModularIntegerBase {
    typedef ModularIntegerBase<T, Mods...> type;

    T x[sizeof...(Mods)];
    friend ostream& operator<<(ostream& output, const type& var) {
      output << "(";
      for(int i = 0; i < sizeof...(Mods); i++) {
        if(i) output << ", ";
        output << var.x[i];
      }
      return output << ")";
    }
  };

  template<typename T, T Mod>
  struct ModularIntegerBase<T, Mod> {
    typedef ModularIntegerBase<T, Mod> type;

    T x[1];

    explicit operator int() const { return this->x[0]; }
    explicit operator long long() const { return this->x[0]; }
    explicit operator double() const { return this->x[0]; }
    explicit operator long double() const { return this->x[0]; }
    friend ostream& operator<<(ostream& output, const type& var) {
      return output << var.x[0];
    }
  };


  template<typename T, class Enable, T ...Mods>
  struct ModularIntegerImpl : ModularIntegerBase<T, Mods...> {
    typedef ModularIntegerImpl<T, Enable, Mods...> type;
    typedef T type_int;
    typedef int64_t large_int;
    const static size_t n_mods = sizeof...(Mods);

    struct Less {
      bool operator()(const type& lhs, const type& rhs) const {
        for(size_t i = 0; i < sizeof...(Mods); i++)
          if(lhs.x[i] != rhs.x[i])
            return lhs.x[i] < rhs.x[i];
        return false;
      };
    };
    typedef Less less;

    constexpr static T mods[sizeof...(Mods)] = {Mods...};
    using ModularIntegerBase<T, Mods...>::x;

    ModularIntegerImpl() {
      for(size_t i = 0; i < sizeof...(Mods); i++)
        x[i] = T();
    }
    ModularIntegerImpl(large_int y) {
      for(size_t i = 0; i < sizeof...(Mods); i++) {
        x[i] = y % mods[i];
        if(x[i] < 0) x[i] += mods[i];
      }
    }
    static type with_remainders(T y[sizeof...(Mods)]) {
      type res;
      for(size_t i = 0; i < sizeof...(Mods); i++)
        res.x[i] = y[i];
      res.normalize();
      return res;
    }

    void normalize() {
      for(size_t i = 0; i < sizeof...(Mods); i++)
        if((x[i] %= mods[i]) < 0)
          x[i] += mods[i];
    }

    inline T operator[](int i) const { return x[i]; }

    inline T multiply(T a, T b, T mod) const {
      return (large_int)a*b % mod;
    }

    inline T inv(T a, T mod) const {
      return static_cast<T>(nt::inverse(a, mod));
    }

    type inverse() const {
      T res[sizeof...(Mods)];
      for(size_t i = 0; i < sizeof...(Mods); i++)
        res[i] = inv(x[i], mods[i]);
      return type::with_remainders(res);
    }
    
    template<typename U>
    T power_(T a, U p, T mod) {
      if(mod == 1) return T();
      if(p < 0) {
        if(a == 0)
          throw domain_error("0^p with negative p is invalid");
        p = -p;
        a = inv(a, mod);
      }
      if(p == 0) return T(1);
      if(p == 1) return a;
      T res = 1;
      while(p > 0) {
        if(p&1)
          res = multiply(res, a, mod);
        p >>= 1;
        a = multiply(a, a, mod);
      }
      return res;
    }
 
    type& operator+=(const type& rhs) {
      for(size_t i = 0; i < sizeof...(Mods); i++)
        (x[i] += rhs.x[i]) %= mods[i];
      return *this;
    }
    type& operator-=(const type& rhs) {
      for(size_t i = 0; i < sizeof...(Mods); i++)
        if((x[i] -= rhs.x[i]) < 0)
          x[i] += mods[i];
      return *this;
    }
    type& operator*=(const type& rhs) {
      for(size_t i = 0; i < sizeof...(Mods); i++)
        x[i] = multiply(x[i], rhs.x[i], mods[i]);
      return *this;
    }
    type& operator/=(const type& rhs) {
      for(size_t i = 0; i < sizeof...(Mods); i++)
        x[i] = multiply(x[i], inv(rhs.x[i], mods[i]), mods[i]);
      return *this;
    }

    type& operator+=(T rhs) {
      for(size_t i = 0; i < sizeof...(Mods); i++)
        x[i] += rhs;
      normalize();
      return *this;
    }
    
    type& operator-=(T rhs) {
      for(size_t i = 0; i < sizeof...(Mods); i++)
        x[i] -= rhs;
      normalize();
      return *this;
    }

    type& operator*=(T rhs) {
      for(size_t i = 0; i < sizeof...(Mods); i++)
        x[i] = multiply(x[i], rhs, mods[i]);
      return *this;
    }

    type& operator/=(T rhs) {
      for(size_t i = 0; i < sizeof...(Mods); i++)
        x[i] = multiply(inv(rhs, mods[i]), x[i], mods[i]);
      return *this;
    }

    type& operator^=(large_int p) {
      for(size_t i = 0; i < sizeof...(Mods); i++)
        x[i] = power_(x[i], p, mods[i]);
      return *this;
    }

    type& operator++() {
      for(size_t i = 0; i < sizeof...(Mods); i++)
        if((++x[i]) >= mods[i])
          x[i] -= mods[i];
      return *this;
    }
    type& operator--() {
      for(size_t i = 0; i < sizeof...(Mods); i++)
        if((--x[i]) < 0)
          x[i] += mods[i];
      return *this;
    }
    type operator++(int unused) { type res = *this; ++(*this); return res; }
    type operator--(int unused) { type res = *this; --(*this); return res; }

    friend type operator+(const type& lhs, const type& rhs) {
      type res = lhs;
      return res += rhs;
    }
    friend type operator-(const type& lhs, const type& rhs) {
      type res = lhs;
      return res -= rhs;
    }
    friend type operator*(const type& lhs, const type& rhs) {
      type res = lhs;
      return res *= rhs;
    }
    friend type operator/(const type& lhs, const type& rhs) {
      type res = lhs;
      return res /= rhs;
    }

    friend type operator+(const type& lhs, T rhs) {
      type res = lhs;
      return res += rhs;
    }
    
    friend type operator-(const type& lhs, T rhs) {
      type res = lhs;
      return res -= rhs;
    }

    friend type operator*(const type& lhs, T rhs) {
      type res = lhs;
      return res *= rhs;
    }
    
    friend type operator/(const type& lhs, T rhs) {
      type res = lhs;
      return res /= rhs;
    }

    friend type operator^(const type& lhs, large_int rhs) {
      type res = lhs;
      return res ^= rhs;
    }

    friend type power(const type& lhs, large_int rhs) {
      return lhs ^ rhs;
    }

    type operator-() const {
      type res = *this;
      for(size_t i = 0; i < sizeof...(Mods); i++)
        if(res.x[i])
          res.x[i] = mods[i] - res.x[i];
      return res;
    }

    friend bool operator==(const type& lhs, const type& rhs) {
      for(size_t i = 0; i < sizeof...(Mods); i++)
        if(lhs.x[i] != rhs.x[i])
          return false;
      return true;
    }
    friend bool operator!=(const type& lhs, const type& rhs) {
      return !(lhs == rhs);
    }
 
    friend istream& operator>>(istream& input, type& var) {
      T y; cin >> y;
      var = y;
      return input;
    }
  };
}

  

  template<typename T, class Enable, T ...Mods>
  constexpr T ModularIntegerImpl<T, Enable, Mods...>::mods[];
 
  template<typename T, T ...Mods>
  using ModularInteger = 
    ModularIntegerImpl<T,
                       typename enable_if<is_integral<T>::value>::type,
                       Mods...>;
 
  template<int32_t ...Mods>
  using Mint32 = ModularInteger<int32_t, Mods...>;

  template<int64_t ...Mods>
  using Mint64 = ModularInteger<int64_t, Mods...>;
}  


#endif
#ifndef _LIB_TRAITS
#define _LIB_TRAITS
#include <bits/stdc++.h>

namespace lib {
  using namespace std;
namespace traits {

  

  template<typename Iterator>
  using IteratorCategory =
    typename iterator_traits<Iterator>::iterator_category;

  

  template<typename Container>
  using IteratorCategoryOf = IteratorCategory<typename Container::iterator>;

  

  template<typename Iterator>
  using IsRandomIterator =
    is_base_of<random_access_iterator_tag, IteratorCategory<Iterator>>;

  

  template<typename Iterator>
  using IsInputIterator =
    is_base_of<input_iterator_tag, IteratorCategory<Iterator>>;

  

  template<typename Iterator>
  using IsBidirectionalIterator =
    is_base_of<bidirectional_iterator_tag, IteratorCategory<Iterator>>;

  

  template<typename Container>
  using HasRandomIterator =
    is_base_of<random_access_iterator_tag, IteratorCategoryOf<Container>>;

  

  template<typename Container>
  using HasInputIterator =
    is_base_of<input_iterator_tag, IteratorCategoryOf<Container>>;

  

  template<typename Container>
  using HasBidirectionalIterator =
    is_base_of<bidirectional_iterator_tag, IteratorCategoryOf<Container>>;
}
}

#endif
#ifndef _LIB_MATH
#define _LIB_MATH
#include <bits/stdc++.h>

namespace lib {
  using namespace std;
namespace math {

  

  template<typename Type>
  struct DefaultPowerOp {
    Type operator()() const { return Type(1); }
    Type operator()(const Type& a) const { return a; }
    void operator()(Type& x, const Type& a, long long cur) const {
      x *= x;
      if(cur & 1)
        x *= a;
    }
  };

  template<typename Type, typename Op>
  Type generic_power(const Type& a, long long n, Op op) {
    if(n == 0) return op();
    Type res = op(a);
    int hi = 63 - __builtin_clzll(n);
    for(int i = hi - 1; ~i; i--) {
      op(res, a, n >> i);
    }
    return res;
  }

  template<typename Type>
  Type generic_power(const Type& a, long long n) {
    return generic_power(a, n, DefaultPowerOp<Type>());
  }
}  

}  


#endif

namespace lib {
  using namespace std;
namespace math {
namespace poly {

  namespace {
    

    using traits::IsInputIterator;
    

    using traits::HasInputIterator;
  } 

  template<typename P>
  struct DefaultPowerOp {
    int mod;
    DefaultPowerOp(int mod) : mod(mod) {}
    P operator()() const { return P(1); }
    P operator()(const P& a) const { return a % mod; }
    void operator()(P& x, const P& a, long long cur) const {
      (x *= x) %= mod;
      if(cur & 1)
        (x *= a) %= mod;
    }
  };

  template<typename P>
  struct ModPowerOp {
    const P& mod;
    ModPowerOp(const P& p) : mod(p) {}
    P operator()() const { return P(1); }
    P operator()(const P& a) { return a % mod; }
    void operator()(P& x, const P& a, long long cur) const {
      (x *= x) %= mod;
      if(cur & 1)
        (x *= a) %= mod;
    }
  };

  template<typename P>
  struct ModShiftPowerOp {
    const P& mod;
    ModShiftPowerOp(const P& p) : mod(p) {}
    P operator()() const { return P(1); }
    P operator()(const P& a) { return a % mod; }
    void operator()(P& x, const P& a, long long cur) const {
      

        

      if(cur & 1)
        (x *= (x << 1)) %= mod;
      else
        (x *= x) %= mod;
    }
  };

  struct DefaultDivmod;
  struct NaiveDivmod;

  template<typename Field, typename Mult, typename Divmod = DefaultDivmod>
  struct Polynomial {
    constexpr static bool NaiveMod =
      is_same<Divmod, NaiveDivmod>::value;
    typedef Polynomial<Field, Mult, Divmod> type;
    typedef Field field;
    vector<Field> p;
    
    Polynomial() : p(0) {}
    explicit Polynomial(Field x): p(1, x) {}

    template<
      typename Iterator,
      typename enable_if<IsInputIterator<Iterator>::value>::type* = nullptr>
    Polynomial(Iterator begin, Iterator end) : p(distance(begin, end)) {
      int i = 0;
      for(auto it = begin; it != end; ++it, ++i)
        p[i] = *it;
      normalize();
    }

    template<
      typename Container,
      typename enable_if<HasInputIterator<Container>::value>::type* = nullptr>
    Polynomial(const Container& container) 
      : Polynomial(container.begin(), container.end()) {}

    Polynomial(const initializer_list<Field>& v) 
      : Polynomial(v.begin(), v.end()) {}

    static type from_root(const Field& root) {
      return Polynomial({-root, 1});
    }

    void normalize() const {
      type* self = const_cast<type*>(this);
      int sz = self->p.size();
      while(sz > 0 && self->p[sz-1] == 0) sz--;
      if(sz != (int)self->p.size())
        self->p.resize(sz);
    }

    inline int size() const { return p.size(); }
    inline int degree() const { return max((int)p.size()-1, 0); }
    bool null() const {
      for(Field x : p)
        if(x != 0) return false;
      return true;
    }

    inline Field operator[](const int i) const { 
      if(i >= size())
        return 0;
      return p[i]; 
    }
    inline Field& operator[](const int i) {
      if(i >= size())
        p.resize(i + 1);
      return p[i]; 
    }

    type& operator+=(const type& rhs) {
      if(rhs.size() > size())
        p.resize(rhs.size());
      int sz = size();
      for(int i = 0; i < sz; i++)
        p[i] += rhs[i];
      normalize();
      return *this;
    }

    type& operator-=(const type& rhs) {
      if(rhs.size() > size())
        p.resize(rhs.size());
      int sz = size();
      for(int i = 0; i < sz; i++)
        p[i] -= rhs[i];
      normalize();
      return *this;
    }

    type& operator*=(const type& rhs) {
      p = Mult()(p, rhs.p);
      normalize();
      return *this;
    }

    type& operator*=(const Field& rhs) {
      int sz = size();
      for(int i = 0; i < sz; i++)
        p[i] *= rhs;
      normalize();
      return *this;
    }

    type& operator/=(const Field& rhs) {
      int sz = size();
      for(int i = 0; i < sz; i++)
        p[i] /= rhs;
      normalize();
      return *this;
    }

    type& operator<<=(const int rhs) {
      if(rhs < 0) return *this >>= rhs;
      if(rhs == 0) return *this;
      int sz = size();
      p.resize(sz + rhs);
      for(int i = sz-1; i >= 0; i--)
        p[i + rhs] = p[i];
      fill_n(p.begin(), rhs, 0);
      return *this;
    }

    type& operator>>=(const int rhs) {
      if(rhs < 0) return *this <<= rhs;
      if(rhs == 0) return *this;
      int sz = size();
      if(rhs >= sz) {
        p.clear();
        return *this;
      }
      for(int i = rhs; i < sz; i++)
        p[i - rhs] = p[i];
      p.resize(sz - rhs);
      return *this;
    }

    type& operator%=(const int rhs) {
      if(rhs < size())
        p.resize(rhs);
      normalize();
      return *this;
    }

    type& operator/=(const type& rhs) {
      return *this = *this / rhs;
    }

    type operator%=(const type& rhs) {
      return *this = *this % rhs;
    }

    type operator+(const type& rhs) const {
      type res = *this;
      return res += rhs;
    }

    type operator-(const type& rhs) const {
      type res = *this;
      return res -= rhs;
    }

    type operator*(const type& rhs) const {
      return type(Mult()(p, rhs.p));
    }

    type operator*(const Field& rhs) const {
      type res = *this;
      return res *= rhs;
    }

    type operator/(const Field& rhs) const {
      type res = *this;
      return res /= rhs;
    }

    type operator<<(const int rhs) const {
      type res = *this;
      return res <<= rhs;
    }

    type operator>>(const int rhs) const {
      type res = *this;
      return res >>= rhs;
    }

    type operator%(const int rhs) const {
      return Polynomial(p.begin(), p.begin() + min(rhs, size()));
    }

    type operator/(const type& rhs) const {
      return type::divmod(*this, rhs).first;
    }

    type operator%(const type& rhs) const {
      return type::divmod(*this, rhs).second;
    }

    bool operator==(const type& rhs) const {
      normalize();
      rhs.normalize();
      return p == rhs.p;
    }

    type inverse() const {
      int sz = size();
      if(sz == 0)
        return type();
      if(sz == 1) {
        assert(p[0] != 0);
        return type(p[0].inverse());
      }
      type q = (*this % ((sz+1)/2)).inverse();
      q -= (*this * q % sz - type(1)) * q % sz;
      return q % sz;
    }

    type reciprocal() const {
      normalize();
      return type(p.rbegin(), p.rend());
    }

    type integral() const {
      int sz = size();
      if(sz == 0) return {};
      type res = *this;
      for(int i = sz; i; i--) {
        res[i] = res[i-1] / i;
      }
      res[0] = 0;
      res.normalize();
      return res;
    }

    type derivative() const {
      int sz = size();
      if(sz == 0) return {};
      type res = *this;
      for(int i = 0; i + 1 < sz; i++) {
        res[i] = res[i+1] * (i + 1);
      }
      res.p.back() = 0;
      res.normalize();
      return res;
    }

    static pair<type, type> divmod(const type& a, const type& b) {
      if(NaiveMod) return naive_divmod(a, b);
      a.normalize();
      b.normalize();
      int m = a.size();
      int n = b.size();
      if(m < n) return {Polynomial(), a};
      type ar = a.reciprocal();
      type bri = (b.reciprocal() % (m - n + 1)).inverse();
      type q = (ar * bri % (m - n + 1)).reciprocal();
      type r = a - b * q;

      if(r.degree() >= b.degree()) {
        q += divmod(r, b).first;
        r = a - b * q;
      }

      return {q, r};
    }

    static pair<type, type> naive_divmod(const type& a, const type& b) {
      type res = a;
      int a_deg = a.degree();
      int b_deg = b.degree();
      Field normalizer = Field(1) / b[b_deg];
      for(int i = 0; i < a_deg-b_deg+1; i++) {
        Field coef = (res[a_deg - i] *= normalizer);
        if(coef != 0) {
          for(int j = 1; j <= b_deg; j++) {
            res[a_deg - i - j] += -b[b_deg - j] * coef;
          }
        }
      }
      return {res >> b_deg, res % b_deg};
    }

    static type power(const type& a, long long n, const int mod) {
      return math::generic_power<type>(a, n, DefaultPowerOp<type>(mod));
    }

    static type power(const type& a, long long n, const type& mod) {
      return math::generic_power<type>(a, n, ModPowerOp<type>(mod));
    }

    static type kth(int K) {
      return type(1) << K;
    }

    static type kth(long long K, const type& mod) {
      return math::generic_power<type>(type(1) << 1, K, ModShiftPowerOp<type>(mod));
    }

    friend ostream& operator<<(ostream& output, const type& var) {
      output << "[";
      int sz = var.size();
      for(int i = sz-1; i >= 0; i--) {
        output << var[i];
        if(i) output << " ";
      }
      return output << "]";
    }
  };
}  



using poly::Polynomial;
}  

}  


#endif
#ifndef _LIB_LINEAR_RECURRENCE
#define _LIB_LINEAR_RECURRENCE
#include <bits/stdc++.h>

namespace lib {
  using namespace std;
namespace linalg {
  namespace {
    using traits::IsRandomIterator;
    using traits::HasRandomIterator;
  }

  template<typename P>
  struct BMSolver {
    typedef BMSolver<P> type;
    typedef typename P::field field_type;
    typedef P poly_type;

    vector<field_type> base;
    vector<field_type> T;
    
    template<
      typename Iterator,
      typename enable_if<IsRandomIterator<Iterator>::value>::type* = nullptr>
    void solve(Iterator begin, Iterator end) {
      auto get = [begin](int i) { return *(begin + i); };

      int n = distance(begin, end);
      
      vector<field_type> C = {1}, B = {1};
      field_type b = 1;
      int L = 0;

      for(int i = 0, x = 1; i < n; i++, x++) {
        

        field_type d = 0;
        for(size_t j = 0; j < C.size(); j++)
          d += get(i-j) * C[j];
        if(d == 0) continue;
        if(2 * L <= i) {
          auto tmp = C;
          if(C.size() < B.size() + x)
            C.resize(B.size() + x);
          field_type coef = d / b;
          for(size_t j = 0; j < B.size(); j++)
            C[j + x] -= coef * B[j];
          L = i + 1 - L;
          B = tmp;
          b = d;
          x = 0;
        } else {
          if(C.size() < B.size() + x)
            C.resize(B.size() + x);
          field_type coef = d / b;
          for(size_t j = 0; j < B.size(); j++)
            C[j + x] -= coef * B[j];
        }
      }

      T = vector<field_type>((int)C.size() - 1);
      for(size_t i = 0; i < T.size(); i++) T[i] = -C[i+1];
      base = vector<field_type>(begin, end);
    }

    template<
      typename Container,
      typename enable_if<HasRandomIterator<Container>::value>::type* = nullptr>
    void solve(const Container& container) {
      solve(container.begin(), container.end());
    }

    void solve(const initializer_list<field_type>& l) {
      solve(l.begin(), l.end());
    }

    bool solved() const {
      return T.size() > 0 && base.size() >= T.size();
    }

    void ensure(int nsz) const {
      auto* self = const_cast<type*>(this);
      for(int j = base.size(); j < nsz; j++) {
        field_type acc = 0;
        for(int i = 0; i < (int)T.size(); i++)
          acc += base[j - i - 1] * T[i];
        self->base.push_back(acc);
      }
    }

    poly_type mod_function() const {
      poly_type res;
      int m = T.size();
      res[m] = 1;
      for(int i = 0; i < m; i++)
        res[i] = -T[m-i-1];
      return res;
    }

    vector<field_type> compute(long long K, int n) {
      assert(n > 0);
      assert(solved());
      vector<field_type> res;
      int N = T.size();
      int cons = min(n, N);

      if(K < (int)base.size()) {
        for(int j = 0; j < n && K + j < (int)base.size(); j++)
          res.push_back({base[K + j]});

        while((int)res.size() < cons) {
          field_type acc = 0;
          int sz = res.size();
          int mid = min(sz, N);
          for(int i = 0; i < mid; i++)
            acc += res[sz - i - 1] * T[i];
          sz = base.size();
          for(int i = mid; i < N; i++)
            acc += base[sz - 1 - (i - mid)] * T[i];
          res.push_back(acc);
        }
      } else {
        ensure(cons + N - 1);

        poly_type x = poly_type::kth(K, mod_function());

        for(int j = 0; j < cons; j++) {
          field_type acc = 0;
            for(int i = 0; i < N; i++)
              acc += x[i] * base[i + j];
          res.push_back(acc);
        }
      }

      for(int j = res.size(); j < n; j++) {
        field_type acc = 0;
        for(int i = 0; i < N; i++)
          acc += res[j - i - 1] * T[i];
        res.push_back(acc);
      }
      return res;
    }

    field_type compute(long long K) {
      return compute(K, 1)[0];
    }
  };
}  

}  


#endif
#ifndef _LIB_LONG_MULTIPLICATION
#define _LIB_LONG_MULTIPLICATION
#include <bits/stdc++.h>

namespace lib {
  using namespace std;
namespace math {
  struct NaiveMultiplication {
    template<typename Field>
    vector<Field> operator()(const vector<Field>& a, const vector<Field>& b) const {
      vector<Field> res(a.size() + b.size());
      for(size_t i = 0; i < a.size(); i++) {
        for(size_t j = 0; j < b.size(); j++) {
          res[i + j] += a[i] * b[j];
        }
      }
      return res;
    }
  };

  template<typename Mult, typename Field>
  vector<Field> shift_conv(const vector<Field>& a, const vector<Field> b) {
    if(b.empty()) return {};
    reverse(b.begin(), b.end());
    int n = a.size();
    int m = b.size();

    auto res = Mult()(a, b);
    return vector<Field>(res.begin() + m - 1, res.end());
  }
}  

}  


#endif
using namespace std;

#define mp make_pair
#define mt make_tuple
#define pb push_back
#define ms(v, x) memset((v), (x), sizeof(v))
#define all(v) (v).begin(), (v).end()
#define ff first
#define ss second
#define iopt ios::sync_with_stdio(false); cin.tie(0)

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a%b); }
int power(int x, int p, int MOD) {
    if(p == 0) return 1%MOD;
    if(p == 1) return x%MOD;
    int res = power(x, p/2, MOD);
    res = (long long)res*res%MOD;
    if(p&1) res = (long long)res*x%MOD;
    return res;
}

typedef pair<int, int> ii;
typedef long double LD;
typedef vector<int> vi;

using namespace lib;

const int MOD = (int)10007;
using Field = Mint32<MOD>;
using Poly = math::Polynomial<Field, math::NaiveMultiplication, math::poly::NaiveDivmod>;

const int N = 202;
Field dp[N][N][10*N];
bool ok[N][N][10*N];
string s;

Field go(int left, int right, int i) {
  if(i < 0) return 0;
  if(i == 0 && left >= right) return 1;
  Field & res = dp[left][right][i];
  if(ok[left][right][i]) return res;
  res = 0;

  if(left >= right) {
    res += go(left, right, max(i - 2, 0)) * 26;
  } else if (left + 1 == right) {
    if(i == 0) res += go(left + 1, right - 1, i);
    else res += go(left + 1, right, i - 1);
    res += go(left, right, i - 2) * 25;
  } else {
    if(s[left] == s[right - 1]) {
      res += go(left + 1, right - 1, i);
      res += go(left, right, i - 2) * 25;
    } else {
      res += go(left + 1, right, i - 1);
      res += go(left, right - 1, i - 1);
      res += go(left, right, i - 2) * 24;
    }
  }

  ok[left][right][i] = true;
  return res;
}

int32_t main(){
  linalg::BMSolver<Poly> solver;
  vector<Field> base;
  cin >> s;
  int n;
  cin >> n;

  for(size_t i = 0; i < 10 * s.size(); i++) {
    base.pb(go(0, s.size(), i));
  }

  solver.solve(base);
  cout << solver.compute(n) << endl;
}
