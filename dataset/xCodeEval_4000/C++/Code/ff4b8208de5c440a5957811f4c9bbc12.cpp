#include<bits/stdc++.h>
using namespace std;
#define MOD 998244353

namespace polynomial {


const int mod=MOD;
struct Poly {
public:
  using value_type = unsigned int;
  using ptr_type = value_type *;
  using const_ptr_type = value_type const *;
  using cast_type = unsigned long long;
  using size_type = unsigned int;
  using arr_type = value_type[1 << 21];
  using iterator = ptr_type;
  using const_iterator = const_ptr_type;
 
  static constexpr value_type P = MOD, G = 3;
 
private:
  iterator _Start, _Finish, _End;
  static inline arr_type ROOT, IROOT;
 
  Poly &dft(size_type len) { return resize(len), _dft(len, _Start), *this; }
  Poly &idft(size_type len) { return _idft(len, _Start), *this; }
  Poly &revbin() { return _revbin(size(), _Start), *this; }
  value_type horner(value_type x) const {
    value_type res = *(end() - 1);
    for (const_iterator i = end() - 1, e = begin(); i != e; --i)
      res = (static_cast<cast_type>(res) * x + *(i - 1)) % P;
    return res;
  }
  using v_it = std::vector<value_type>::const_iterator;
  static void segment_tree_build(std::vector<Poly> &, size_type, v_it, v_it);
  static void segment_tree_solve(const std::vector<Poly> &, size_type, v_it, v_it, const Poly &,
                                 std::vector<value_type> &);
  static size_type _get_len(size_type);
  static value_type _mod_pow(value_type, long long);
  static value_type _legendre_symbol(value_type);
  static value_type _tonelli_shanks(value_type);
  static void _revbin(size_type, ptr_type);
  static void _dif_ntt(size_type, ptr_type, ptr_type);
  static void _dit_ntt(size_type, ptr_type, ptr_type);
  static void _init_root_of_unity(size_type);
  static void _dft(size_type, ptr_type);
  static void _idft(size_type, ptr_type);
 
public:
  iterator begin() { return _Start; }
  iterator end() { return _Finish; }
  const_iterator begin() const { return const_cast<const_iterator>(_Start); }
  const_iterator end() const { return const_cast<const_iterator>(_Finish); }
  size_type size() const { return _Finish - _Start; }
  size_type capacity() const { return _End - _Start; }
  value_type &operator[](size_type x) { return *(_Start + x); }
  value_type operator[](size_type x) const { return *(_Start + x); }
  Poly &remove_trailing_zeros() {
    while (size() > 1 && *(_Finish - 1) == 0) --_Finish;
    return *this;
  }
  Poly &resize(size_type new_size) {
    assert(new_size > 0);
    if (new_size > capacity()) {
      size_t old_capacity = capacity(), new_capacity = _get_len(new_size);
      _Start = static_cast<iterator>(std::realloc(_Start, sizeof(value_type) * new_capacity));
      assert(_Start != nullptr);
      _End = _Start + new_capacity;
      std::memset(_Start + old_capacity, 0, sizeof(value_type) * (new_capacity - old_capacity));
    } else if (size() > new_size)
      std::memset(_Start + new_size, 0, sizeof(value_type) * (size() - new_size));
    return _Finish = _Start + new_size, *this;
  }
  explicit Poly(size_type _reserved)
      : _Start(static_cast<iterator>(std::calloc(_get_len(_reserved), sizeof(value_type)))),
        _Finish(_Start + _reserved), _End(_Start + _get_len(_reserved)) {
    assert((_reserved > 0 && _Start != nullptr));
  }
  Poly(const_iterator _first, const_iterator _last)
      : _Start(static_cast<iterator>(std::malloc(sizeof(value_type) * _get_len(_last - _first)))),
        _Finish(_Start + (_last - _first)), _End(_Start + _get_len(_last - _first)) {
    assert((_last - _first > 0 && _Start != nullptr));
    std::memcpy(_Start, _first, sizeof(value_type) * (_last - _first));
    std::memset(_Finish, 0, sizeof(value_type) * (_End - _Finish));
  }
  Poly(const Poly &rhs) : Poly(rhs.begin(), rhs.end()) {}
  Poly(Poly &&rhs) : _Start(rhs._Start), _Finish(rhs._Finish), _End(rhs._End) {
    rhs._Start = rhs._Finish = rhs._End = nullptr;
  }
  Poly(std::initializer_list<value_type> l) : Poly(l.begin(), l.end()) {}
  ~Poly() {
    if (_Start != nullptr) std::free(_Start);
  }
  Poly &operator=(const Poly &rhs) {
    if (this == &rhs) return *this;
    return resize(rhs.size()),
           std::memcpy(this->_Start, rhs.begin(), sizeof(value_type) * rhs.size()), *this;
  }
  Poly operator-() const {
    Poly res(*this);
    for (iterator i = res.begin(), e = res.end(); i != e; ++i)
      if (*i != 0) *i = P - *i;
    return res;
  }
  Poly &operator+=(const Poly &rhs) {
    if (size() < rhs.size()) resize(rhs.size());
    for (size_type i = 0, e = rhs.size(); i != e; ++i)
      *(this->_Start + i) = (*(this->_Start + i) + *(rhs._Start + i)) % P;
    return *this;
  }
  Poly &operator-=(const Poly &rhs) {
    if (size() < rhs.size()) resize(rhs.size());
    for (size_type i = 0, e = rhs.size(); i != e; ++i)
      *(this->_Start + i) = (*(this->_Start + i) + P - *(rhs._Start + i)) % P;
    return *this;
  }
  Poly &operator*=(const Poly &);
  Poly &operator/=(const Poly &);
  Poly &operator%=(const Poly &);
  Poly quo(const Poly &) const;
  std::pair<Poly, Poly> quo_with_rem(const Poly &) const;
  Poly deriv() const;
  Poly integr() const;
  Poly inv() const;
  Poly log() const;
  Poly exp() const;
  Poly sqrt() const;
  Poly isqrt() const;
  std::vector<value_type> eval(const std::vector<value_type> &) const;
  static Poly inter(const std::vector<value_type> &, const std::vector<value_type> &);
  friend Poly operator+(const Poly &lhs, const Poly &rhs) { return Poly(lhs) += rhs; }
  friend Poly operator-(const Poly &lhs, const Poly &rhs) { return Poly(lhs) -= rhs; }
  friend Poly operator*(const Poly &lhs, const Poly &rhs) { return Poly(lhs) *= rhs; }
  friend Poly operator/(const Poly &lhs, const Poly &rhs) { return Poly(lhs) /= rhs; }
  friend Poly operator%(const Poly &lhs, const Poly &rhs) { return Poly(lhs) %= rhs; }
  friend void swap(Poly &lhs, Poly &rhs) {
    iterator tmp;
    tmp = lhs._Start, lhs._Start = rhs._Start, rhs._Start = tmp;
    tmp = lhs._Finish, lhs._Finish = rhs._Finish, rhs._Finish = tmp;
    tmp = lhs._End, lhs._End = rhs._End, rhs._End = tmp;
  }
  friend std::istream &operator>>(std::istream &is, Poly &rhs) { 

    for (iterator i = rhs.begin(), e = rhs.end(); i != e; ++i) is >> *i;
    return is;
  }
  friend std::ostream &operator<<(std::ostream &os, const Poly &rhs) { 

    for (const_iterator i = rhs.begin(), e = rhs.end(); i != e; ++i) os << *i << ' ';
    return os;
  }
};
 
Poly::size_type Poly::_get_len(size_type x) {
  size_type res = 1;
  while (res < x) res <<= 1;
  return res;
}
 
Poly::value_type Poly::_mod_pow(value_type x, long long y) {
  if ((y %= static_cast<long long>(P - 1)) < 0) y += P - 1;
  value_type res = 1;
  for (; y; y >>= 1, x = static_cast<cast_type>(x) * x % P)
    if (y & 1) res = static_cast<cast_type>(res) * x % P;
  return res;
}
 
Poly::value_type Poly::_legendre_symbol(value_type x) {
  return x == 0 ? 0 : _mod_pow(x, P - 1 >> 1);
}
 
Poly::value_type Poly::_tonelli_shanks(value_type a) {
  if (_legendre_symbol(a) != 1) return 0;
  value_type q = P - 1, t = 0, n,
             z; 

  while ((q & 1) == 0) q >>= 1, ++t;
  if (t == 1) return _mod_pow(a, P + 1 >> 2);
  for (n = 1; n != P; ++n)
    if (_legendre_symbol(n) == P - 1) {
      z = _mod_pow(n, q);
      break;
    }
  value_type y = z, r = t, x = _mod_pow(a, q - 1 >> 1), b = x;
  x = static_cast<cast_type>(x) * a % P, b = static_cast<cast_type>(x) * b % P;
  while (true) {
    if (b == 1) return x < P - x ? x : P - x;
    value_type m = 1;
    for (; m < r; ++m)
      if (_mod_pow(b, 1 << m) == 1) break;
    value_type v = _mod_pow(y, 1 << r - m - 1);
    y = static_cast<cast_type>(v) * v % P, r = m, x = static_cast<cast_type>(x) * v % P,
    b = static_cast<cast_type>(b) * y % P;
  }
}
 
void Poly::_dif_ntt(size_type n, ptr_type x, ptr_type root) {
  for (size_type i = n; i != 1; i >>= 1)
    for (size_type j = 0, l = i >> 1; j != n; j += i)
      for (size_type k = 0; k != l; ++k) {
        value_type u = *(x + j + k), v = *(x + j + k + l);
        *(x + j + k) = (u + v >= P ? u + v - P : u + v),
                  *(x + j + k + l) = (static_cast<cast_type>(u) + P - v) * *(root + l + k) % P;
      }
}
 
void Poly::_dit_ntt(size_type n, ptr_type x, ptr_type root) {
  for (size_type i = 2; i <= n; i <<= 1)
    for (size_type j = 0, l = i >> 1; j != n; j += i)
      for (size_type k = 0; k != l; ++k) {
        value_type u = *(x + j + k),
                   v = static_cast<cast_type>(*(root + l + k)) * *(x + j + k + l) % P;
        *(x + j + k) = (u + v >= P ? u + v - P : u + v),
                  *(x + j + k + l) = (u >= v ? u - v : u + P - v);
      }
}
 
void Poly::_init_root_of_unity(size_type n) {
  static size_type lim = 1;
  if (lim < n) {
    const size_type l = n >> 1;
    value_type g = _mod_pow(G, (P - 1) / n), ig = _mod_pow(G, -static_cast<int>((P - 1) / n));
    ROOT[l] = IROOT[l] = 1;
    for (size_type i = l + 1; i < n; ++i)
      ROOT[i] = static_cast<cast_type>(ROOT[i - 1]) * g % P,
      IROOT[i] = static_cast<cast_type>(IROOT[i - 1]) * ig % P;
    for (size_type i = l - 1; i >= lim; --i) ROOT[i] = ROOT[i << 1], IROOT[i] = IROOT[i << 1];
    lim = n;
  }
}
 
void Poly::_revbin(size_type n, ptr_type x) {
  for (size_type i = 0, j = 0; i != n; ++i) {
    if (i < j) std::swap(*(x + i), *(x + j));
    for (size_type k = n >> 1; (j ^= k) < k; k >>= 1) {
    }
  }
}
 
void Poly::_dft(size_type n, ptr_type x) { _init_root_of_unity(n), _dif_ntt(n, x, ROOT); }
 
void Poly::_idft(size_type n, ptr_type x) {
  _dit_ntt(n, x, IROOT);
  value_type in = P - (P - 1) / n;
  for (ptr_type i = x, e = x + n; i != e; ++i) *i = static_cast<cast_type>(*i) * in % P;
}
 
Poly &Poly::operator*=(const Poly &rhs) {
  size_type n = size(), m = rhs.size(), len = _get_len(n + m - 1);
  if (n + m - 1 <= 128 || std::min(n, m) <= 8) {
    Poly res(n + m - 1);
    for (size_type i = 0; i != n; ++i)
      for (size_type j = 0; j != m; ++j)
        *(res._Start + i + j) = (*(res._Start + i + j) +
                                 static_cast<cast_type>(*(this->_Start + i)) * *(rhs._Start + j)) %
                                P;
    return this->operator=(res);
  } else {
    Poly rhs_cpy(rhs);
    dft(len), rhs_cpy.dft(len);
    for (size_type i = 0; i != len; ++i)
      *(_Start + i) = static_cast<cast_type>(*(this->_Start + i)) * *(rhs_cpy._Start + i) % P;
    return idft(len).resize(n + m - 1);
  }
}
 
Poly &Poly::operator/=(const Poly &rhs) {
  if (size() < rhs.size()) return this->operator=(Poly{0});
  if (rhs.size() == 1) return this->operator*=(rhs.inv());
  size_type n = size() - rhs.size() + 1;
  Poly rhs_cpy(rhs);
  std::reverse(begin(), end()), std::reverse(rhs_cpy.begin(), rhs_cpy.end());
  Poly res = resize(n).quo(rhs_cpy);
  std::reverse(res.begin(), res.end());
  return this->operator=(res);
}
 
Poly &Poly::operator%=(const Poly &rhs) { return this->operator=(quo_with_rem(rhs).second); }
 
std::pair<Poly, Poly> Poly::quo_with_rem(const Poly &rhs) const {
  if (size() < rhs.size()) return {{0}, *this};
  Poly q = *this / rhs; 

                        

  if (rhs.size() == 1) return {q, {0}};
  size_type len = _get_len(std::max(q.size(), rhs.size()));
  int overlap = static_cast<int>(q.size() + rhs.size() - 1) - len;
  Poly q_cpy(q), rhs_cpy(rhs);
  q_cpy.dft(len), rhs_cpy.dft(len);
  for (size_type i = 0; i != len; ++i)
    *(q_cpy._Start + i) = static_cast<cast_type>(*(q_cpy._Start + i)) * *(rhs_cpy._Start + i) % P;
  q_cpy.idft(len).resize(rhs.size() - 1);
  if (overlap > 0)
    for (size_type i = 0; i != overlap && q_cpy.begin() + i != q_cpy.end(); ++i)
      *(q_cpy._Start + i) = (*(q_cpy._Start + i) + P - this->operator[](len + i)) % P;
  for (size_type i = 0, e = q_cpy.size(); i != e; ++i)
    *(q_cpy._Start + i) = (this->operator[](i) + P - *(q_cpy._Start + i)) % P;
  return {q, q_cpy};
}
 
Poly Poly::deriv() const {
  if (size() == 1) return {0};
  Poly res(size() - 1);
  for (size_type i = 1, len = size(); i != len; ++i)
    *(res._Start + i - 1) = static_cast<cast_type>(this->operator[](i)) * i % P;
  return res;
}
 
Poly Poly::integr() const {
  static size_type lim = 0;
  static arr_type INV{0, 1};
  size_type len = size() + 1;
  Poly res(len);
  if (lim < len)
    for (size_type i = (lim < 2 ? 2 : lim); i < len; ++i)
      INV[i] = static_cast<cast_type>(P - P / i) * INV[P % i] % P;
  for (size_type i = 1; i != len; ++i)
    *(res._Start + i) = static_cast<cast_type>(this->operator[](i - 1)) * INV[i] % P;
  return res;
}
 
Poly Poly::inv() const {
  assert(*begin() != 0);
  size_type len = _get_len(size());
  Poly res(len);
  res[0] = _mod_pow(*this->_Start, -1);
  res.resize(1);
  for (size_type i = 2; i <= len; i <<= 1) {
    Poly cpy(begin(), begin() + i), res_cpy(res);
    res_cpy.dft(i), cpy.dft(i);
    for (size_type j = 0; j != i; ++j)
      *(cpy._Start + j) = static_cast<cast_type>(*(cpy._Start + j)) * *(res_cpy._Start + j) % P;
    cpy.idft(i);
    std::memset(cpy.begin(), 0, sizeof(value_type) * (i >> 1));
    cpy.dft(i);
    for (size_type j = 0; j != i; ++j)
      *(cpy._Start + j) = static_cast<cast_type>(*(cpy._Start + j)) * *(res_cpy._Start + j) % P;
    cpy.idft(i), res.resize(i);
    for (iterator j = cpy.begin() + (i >> 1), e = cpy.end(); j != e; ++j)
      if (*j != 0) *j = P - *j;
    std::memcpy(res.begin() + (i >> 1), cpy.begin() + (i >> 1), sizeof(value_type) * (i >> 1));
  }
  return res.resize(size());
}
 
Poly Poly::quo(const Poly &rhs) const {
  if (size() == 1)
    return Poly{
        static_cast<value_type>(static_cast<cast_type>(*begin()) * _mod_pow(*rhs.begin(), -1) % P)};
  Poly rhs_cpy(rhs);
  size_type len = _get_len(size()), len_2 = len >> 1;
  rhs_cpy.resize(len);
  Poly rhs_inv = Poly(rhs_cpy.begin(), rhs_cpy.begin() + len_2).inv(), q(begin(), begin() + len_2);
  rhs_inv.dft(len), q.dft(len);
  for (size_type i = 0; i != len; ++i)
    *(q._Start + i) = static_cast<cast_type>(*(q._Start + i)) * *(rhs_inv._Start + i) % P;
  q.idft(len).resize(len_2).resize(size());
  Poly q_cpy(q);
  q_cpy.dft(len), rhs_cpy.dft(len);
  for (size_type i = 0; i != len; ++i)
    *(q_cpy._Start + i) = static_cast<cast_type>(*(q_cpy._Start + i)) * *(rhs_cpy._Start + i) % P;
  q_cpy.idft(len);
  std::memset(q_cpy.begin(), 0, sizeof(value_type) * len_2);
  for (size_type i = len_2; i < size() && i != len; ++i)
    *(q_cpy._Start + i) = (*(q_cpy._Start + i) + P - this->operator[](i)) % P;
  q_cpy.dft(len);
  for (size_type i = 0; i != len; ++i)
    *(q_cpy._Start + i) = static_cast<cast_type>(*(q_cpy._Start + i)) * *(rhs_inv._Start + i) % P;
  q_cpy.idft(len);
  for (iterator i = q_cpy.begin() + len_2, e = q_cpy.begin() + size(); i != e; ++i)
    if (*i != 0) *i = P - *i;
  std::memcpy(q.begin() + len_2, q_cpy.begin() + len_2, sizeof(value_type) * (size() - len_2));
  return q;
}
 
Poly Poly::log() const {
  assert(*begin() == 1);
  return deriv().quo(*this).integr();
}
 
Poly Poly::exp() const {
  assert(*begin() == 0);
  if (size() == 1) return {1};
  size_type len = _get_len(size());
  Poly res(len), res_inv(len), der(deriv()), g0(len);
  res.operator=(Poly{1, this->operator[](1)}), res_inv.operator=(res.inv()), g0.operator=(res);
  g0.dft(4);
  for (size_type i = 4; i <= len; i <<= 1) {
    Poly h0(res_inv), g0p(res.deriv()), f0p(der.begin(), der.begin() + (i >> 1) - 1), g0f0p(i);
    h0.dft(i), f0p.dft(i >> 1);
    for (size_type j = 0; j != i >> 1; ++j)
      *(g0f0p._Start + j) = static_cast<cast_type>(*(g0._Start + j)) * *(f0p._Start + j) % P;
    g0f0p.idft(i >> 1).resize(i);
    for (size_type j = 0; j != (i >> 1) - 1; ++j)
      *(g0f0p._Start + j) = (*(g0f0p._Start + j) + P - *(g0p._Start + j)) % P;
    std::memcpy(g0f0p.begin() + (i >> 1), g0f0p.begin(), sizeof(value_type) * ((i >> 1) - 2));
    std::memset(g0f0p.begin(), 0, sizeof(value_type) * ((i >> 1) - 2));
    for (iterator j = g0f0p.begin() + ((i >> 1) - 1), e = g0f0p.end(); j != e; ++j)
      if (*j != 0) *j = P - *j;
    g0f0p.dft(i);
    for (size_type j = 0; j != i; ++j)
      *(g0f0p._Start + j) = static_cast<cast_type>(*(g0f0p._Start + j)) * *(h0._Start + j) % P;
    g0f0p.idft(i);
    Poly imf(g0f0p.resize(i - 1).integr());
    std::memset(imf.begin(), 0, sizeof(value_type) * (i >> 1));
    for (size_type j = i >> 1; j != i; ++j)
      *(imf._Start + j) = (*(imf._Start + j) + P - this->operator[](j)) % P;
    imf.dft(i);
    for (size_type j = 0; j != i; ++j)
      *(imf._Start + j) = static_cast<cast_type>(*(imf._Start + j)) * *(g0._Start + j) % P;
    imf.idft(i), res.resize(i);
    for (iterator j = imf.begin() + (i >> 1), e = imf.end(); j != e; ++j)
      if (*j != 0) *j = P - *j;
    std::memcpy(res.begin() + (i >> 1), imf.begin() + (i >> 1), sizeof(value_type) * (i >> 1));
    if (i != len) {
      g0.operator=(res).dft(i << 1);
      Poly g0_half(i);
      for (size_type j = 0; j != i; ++j)
        *(g0_half._Start + j) = static_cast<cast_type>(*(g0._Start + j)) * *(h0._Start + j) % P;
      g0_half.idft(i);
      std::memset(g0_half.begin(), 0, sizeof(value_type) * (i >> 1));
      g0_half.dft(i);
      for (size_type j = 0; j != i; ++j)
        *(g0_half._Start + j) =
            static_cast<cast_type>(*(g0_half._Start + j)) * *(h0._Start + j) % P;
      g0_half.idft(i), res_inv.resize(i);
      for (iterator j = g0_half.begin() + (i >> 1), e = g0_half.end(); j != e; ++j)
        if (*j != 0) *j = P - *j;
      std::memcpy(res_inv.begin() + (i >> 1), g0_half.begin() + (i >> 1),
                  sizeof(value_type) * (i >> 1));
    }
  }
  return res.resize(size());
}
 
Poly Poly::sqrt() const {
  assert(_legendre_symbol(*begin()) != 0);
  size_type len = _get_len(size());
  Poly res(len), res_inv(len), g0(len);
  res.operator=(Poly{_tonelli_shanks(*begin())}),
  res_inv.operator=(Poly{_mod_pow(res.operator[](0), -1)}), g0.operator=(res);
  g0.dft(2);
  const value_type inv2 = P - (P - 1) / 2;
  for (size_type i = 2; i <= len; i <<= 1) {
    Poly g0_2(i), res_inv_cpy(res_inv);
    for (size_type j = 0; j != i >> 1; ++j)
      *(g0_2._Start + j) = (static_cast<cast_type>(*(g0._Start + j)) * *(g0._Start + j)) % P;
    g0_2.idft(i >> 1).resize(i);
    for (size_type j = 0; j != i >> 1; ++j)
      *(g0_2._Start + j) = (*(g0_2._Start + j) + P - this->operator[](j)) % P;
    std::memcpy(g0_2.begin() + (i >> 1), g0_2.begin(), sizeof(value_type) * ((i >> 1) - 1));
    std::memset(g0_2.begin(), 0, sizeof(value_type) * ((i >> 1) - 1));
    for (size_type j = i >> 1; j != i; ++j)
      *(g0_2._Start + j) = (*(g0_2._Start + j) + P - this->operator[](j)) % P;
    g0_2.dft(i), res_inv_cpy.dft(i);
    for (size_type j = 0; j != i; ++j)
      *(g0_2._Start + j) =
          static_cast<cast_type>(*(g0_2._Start + j)) * *(res_inv_cpy._Start + j) % P;
    g0_2.idft(i), res.resize(i);
    for (iterator j = g0_2.begin() + (i >> 1), e = g0_2.end(); j != e; ++j)
      if (*j != 0) *j = static_cast<cast_type>(P - *j) * inv2 % P;
    std::memcpy(res.begin() + (i >> 1), g0_2.begin() + (i >> 1), sizeof(value_type) * (i >> 1));
    if (i != len) {
      g0.operator=(res).dft(i);
      for (size_type j = 0; j != i; ++j)
        *(g0_2._Start + j) =
            static_cast<cast_type>(*(g0._Start + j)) * *(res_inv_cpy._Start + j) % P;
      g0_2.idft(i);
      std::memset(g0_2.begin(), 0, sizeof(value_type) * (i >> 1));
      g0_2.dft(i);
      for (size_type j = 0; j != i; ++j)
        *(g0_2._Start + j) =
            static_cast<cast_type>(*(g0_2._Start + j)) * *(res_inv_cpy._Start + j) % P;
      g0_2.idft(i), res_inv.resize(i);
      for (iterator j = g0_2.begin() + (i >> 1), e = g0_2.end(); j != e; ++j)
        if (*j != 0) *j = P - *j;
      std::memcpy(res_inv.begin() + (i >> 1), g0_2.begin() + (i >> 1),
                  sizeof(value_type) * (i >> 1));
    }
  }
  return res.resize(size());
}
 
void Poly::segment_tree_build(std::vector<Poly> &vp, size_type pos, v_it left, v_it right) {
  if (right - left == 1) {
    vp[pos] = Poly{*left == 0 ? 0 : P - *left, 1};
    return;
  }
  v_it mid = left + (right - left >> 1);
  segment_tree_build(vp, pos << 1, left, mid), segment_tree_build(vp, pos << 1 | 1, mid, right);
  vp[pos] = vp[pos << 1] * vp[pos << 1 | 1];
}
 
void Poly::segment_tree_solve(const std::vector<Poly> &vp, size_type pos, v_it left, v_it right,
                              const Poly &r, std::vector<value_type> &res) {
  if (right - left <= 128) {
    for (v_it it = left; it != right; ++it) res.push_back(r.horner(*it));
    return;
  }
  v_it mid = left + (right - left >> 1);
  segment_tree_solve(vp, pos << 1, left, mid, r % vp[pos << 1], res),
      segment_tree_solve(vp, pos << 1 | 1, mid, right, r % vp[pos << 1 | 1], res);
}
 
std::vector<Poly::value_type> Poly::eval(const std::vector<value_type> &points) const {
  std::vector<Poly> vp(points.size() << 2, Poly{0});
  segment_tree_build(vp, 1, points.begin(), points.end());
  std::vector<value_type> res;
  segment_tree_solve(vp, 1, points.begin(), points.end(), *this % vp[1], res);
  return res;
}
 
Poly Poly::inter(const std::vector<value_type> &x, const std::vector<value_type> &y) {
  size_type n = x.size();
  assert(y.size() == n);
  std::vector<Poly> vp(n << 2, Poly{0});
  segment_tree_build(vp, 1, x.begin(), x.end());
  std::vector<value_type> v;
  segment_tree_solve(vp, 1, x.begin(), x.end(), vp[1].deriv() % vp[1], v);
  for (size_type i = 0; i != n; ++i) v[i] = _mod_pow(v[i], -1) * static_cast<cast_type>(y[i]) % P;
  std::function<Poly(size_type, v_it, v_it)> inter_rec = [&inter_rec, &vp](size_type pos, v_it left,
                                                                           v_it right) {
    if (right - left == 1) return Poly{*left};
    return inter_rec(pos << 1, left, left + (right - left >> 1)) * vp[pos << 1 | 1] +
           inter_rec(pos << 1 | 1, left + (right - left >> 1), right) * vp[pos << 1];
  };
  return inter_rec(1, v.begin(), v.end());
}
template<typename ty1,typename ty2>
inline int add(ty1 x, ty2 y) {
	if(y>=MOD)y%=MOD;
	if(x>=MOD)x%=MOD;
    x += y; return x < MOD ? x : x - MOD;
}
template<typename ty1,typename ty2>
inline void addto(ty1 &x, ty2 y) {
		  if(y>=MOD)y%=MOD;
		  if(x>=MOD)x%=MOD;
	      x += y; if (x >= MOD) x -= MOD;
}
template<typename ty1,typename ty2>
inline int sub(ty1 x, ty2 y) {
		if(y>=MOD)y%=MOD;
		 if(x>=MOD)x%=MOD;
        x -= y; return x < 0 ? x + MOD : x;
}
template<typename ty1,typename ty2>
inline void subto(ty1 &x, ty2 y) {
	if(y>=MOD)y%=MOD;
	if(x>=MOD)x%=MOD;
    x -= y; if (x < 0) x += MOD;
}
template<typename ty1,typename ty2>
inline int mul(ty1 x, ty2 y) {
        if(y>=MOD)y%=MOD;
		if(x>=MOD)x%=MOD;
        return 1ll * x * y % MOD;
}
template<typename ty1,typename ty2>
void multo(ty1 &x, ty2 y) {
        if(y>=MOD)y%=MOD;
		if(x>=MOD)x%=MOD;
        x=1ll * x * y % MOD;
}
int fpow(int x, int y = mod - 2) {
        int ans = 1;
        while (y) {
            if (y & 1) ans = mul(ans, x);
            y >>= 1; x = mul(x, x);
        }
        return ans;
} 
}
 










using polynomial::Poly;
using polynomial::add;
using polynomial::addto;
using polynomial::sub;
using polynomial::subto;
using polynomial::mul;
using polynomial::fpow;
namespace bm {
    const int maxn = 10000;  

    const int mod = MOD;
    vector<int> r[maxn + 10];
    int rcnt, pos[maxn + 10], w[maxn + 10];
 
    vector<int> main(vector<int> a) {
		rcnt = 0;
        for (int i = 0; i < (int)a.size(); ++i) {
            int delta = a[i];
            for (int j = 0; j < (int)r[rcnt].size(); ++j)
                subto(delta, mul(r[rcnt][j], a[i - j - 1]));
            if (delta) {
                pos[rcnt] = i; w[rcnt] = delta;
                if (!rcnt) {
                    r[++rcnt].clear(); r[rcnt].resize(i + 1);
                } else {
                    int id = 0;
                    for (int j = 1; j < rcnt; ++j)
                        if (i - pos[j] + r[j].size() < i - pos[id] + r[id].size()) id = j;
                    ++rcnt;
                    r[rcnt].resize(max(r[id].size() + i - pos[id], r[rcnt - 1].size()));
                    int t = mul(delta, fpow(w[id], mod - 2));
                    for (int j = 0; j < i - pos[id] - 1; ++j) r[rcnt][j] = 0;
                    r[rcnt][i - pos[id] - 1] = t;
                    for (int j = 0; j < (int)r[id].size(); ++j)
                        r[rcnt][j + i - pos[id]] = mul(sub(0, t), r[id][j]);
                    for (int j = 0; j < (int)r[rcnt - 1].size(); ++j)
                        addto(r[rcnt][j], r[rcnt - 1][j]);
                }
            }
        }
        return r[rcnt];
    }
}
































template<typename ty>
vector<int> kitamasa(vector<ty> B_,long long int k){
	Poly B(B_.size()+1);
	for(int i=0;i<B_.size();i++){
		B[i]=B_[i];
	} 
	for(int i=0;i<B.size();i++){
		B[i]=sub(0,B[i]);
	}
	B[B_.size()]=1;
	

	Poly ans(1);
	ans[0]=1;
	Poly tmp(2);
	tmp[0]=0;
	tmp[1]=1;
	

	while(k){
		if(k&1LL){
			ans=ans*tmp%B;
		}
		k>>=1LL;
		tmp=tmp*tmp%B;
	}
	return ans;
}










#define MAX 100002
#define MAX_M 100002
 
int n;
int m;
 
 
int main(){
	cin>>n>>m;
	int z=1;
	while(z<m+1){
		z*=2;
	}
	Poly v(z);
	v[0]=1;
	for(int i=0;i<n;i++){
		int c;
		scanf("%d",&c);
		if(c<=m){
			v[c]=sub(0,4);
		}
	}
	v=v.sqrt();  
	v[0]=add(v[0],1);
	v=v.inv();
	for(int i=1;i<=m;i++){
		printf("%d\n",mul(2,v[i]));
	}
	return 0;
}