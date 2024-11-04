













    && !defined(__NT__) && !defined(__WINDOWS_)






    || defined(__NT__) || defined(__WINDOWS_)
const size_t id2 = 0x01000000;



const size_t id2 = 0x10000000;


char  id9[id2];
char* id11 = id9;
char  id5[id2];
char* id12 = id5;


class fastio_t {
public:
  char buf[2048];
  bool bad{false};
  enum flag_t {
    smart             = 1,
    fixed             = 2,
    scientific        = 4,
    SCIENTIFIC        = 8,
    SMART             = 16,
    getword           = 128,
    getline           = 256,
    getall            = 512,
    cr                = 1024,
    lf                = 2048,
    default_flag      = smart | getword | cr | lf,
    default_precision = 6
  };
  unsigned prec{default_precision}, flag{default_flag};

  template <typename T> T abs(const T& x) const { return (x < 0 ? -x : x); }
  bool isw(int ch) const { return (ch <= ' ' || ch == 0x7f); }
  template <typename T> T fast_pow(T base, int exponent) const {
    T    ans = 1;
    bool r   = exponent < 0;
    if (r) exponent = -exponent;
    while (exponent) {
      if (exponent & 1) ans *= base;
      base *= base;
      exponent >>= 1;
    }
    if (r) return (1.0l / ans);
    return ans;
  }

  fastio_t& operator<<(const char& ch) {
    putchar(ch);
    return *this;
  }
  fastio_t& operator<<(char* str) {
    fputs(str, stdout);
    return *this;
  }
  fastio_t& operator<<(const std::string& str) {
    fputs(str.c_str(), stdout);
    return *this;
  }
  fastio_t& operator<<(const char* const& str) {
    fputs(str, stdout);
    return *this;
  }
  fastio_t& operator>>(std::string& str) {
    int ch;
    bad = true;
    str.clear();
    if (flag & getall) {
      

      while (ch = getchar(), ~ch) {
        str += ch;
        bad = false;
      }
    } else if (flag & getline) {
      

      while (ch = getchar(), ~ch && ch != '\r' && ch != '\n') {
        str += ch;
        bad = false;
      }
    } else {
      

      while (ch = getchar(), ~ch && !isw(ch)) {
        str += ch;
        bad = false;
      }
    }
    unsigned ending = flag & (cr | lf);
    if ((!ending || ending == (cr | lf)) && ch == '\r') getchar();
    return *this;
  }
  fastio_t& operator>>(char* str) {
    int ch;
    bad = true;
    if (flag & getall) {
      

      while (ch = getchar(), ~ch) {
        *str++ = ch;
        bad    = false;
      }
    } else if (flag & getline) {
      

      while (ch = getchar(), ~ch && ch != '\r' && ch != '\n') {
        *str++ = ch;
        bad    = false;
      }
    } else {
      

      while (ch = getchar(), ~ch && !isw(ch)) {
        *str++ = ch;
        bad    = false;
      }
    }
    *str            = '\0';
    unsigned ending = flag & (cr | lf);
    if ((!ending || ending == (cr | lf)) && ch == '\r') getchar();
    return *this;
  }
  fastio_t& operator>>(char& ch) {
    bad = true;
    while (ch = getchar(), ~ch && isw(ch)) { }
    if (~ch) bad = false;
    return *this;
  }
  template <typename T> int id3(T& x, int& sig) {
    x      = 0;
    bad    = true;
    sig    = 1;
    int ch = getchar();
    while (~ch && isw(ch)) ch = getchar();
    if (ch == '+') ch = getchar();
    else if (ch == '-') {
      sig = -1;
      ch  = getchar();
    } else if (!(ch >= '0' && ch <= '9')) return ch;
    while (ch >= '0' && ch <= '9') {
      x *= 10;
      x += ch - '0';
      ch  = getchar();
      bad = false;
    }
    x *= sig;
    return ch;
  }
  template <typename T> int id1(T& x) {
    x                 = 0;
    long double power = 1;
    long long   i     = 0;
    int         sig   = 0;
    int         ch    = id3(i, sig);
    x                 = i;
    if (ch == '.') {
      ch = getchar();
      while (ch >= '0' && ch <= '9') {
        power /= 10;
        x += power * (ch - '0');
        ch  = getchar();
        bad = false;
      }
      if (sig) x *= sig;
    }
    if (ch == 'e' || ch == 'E') {
      if (bad) return ch;
      ch = id3(i, sig);
      if (bad) return ch;
      x *= fast_pow((long double) 10.0, i);
    }
    return ch;
  }
  fastio_t& operator>>(float& x) {
    id1(x);
    return *this;
  }
  fastio_t& operator>>(double& x) {
    id1(x);
    return *this;
  }
  fastio_t& operator>>(long double& x) {
    id1(x);
    return *this;
  }
  unsigned precision(unsigned _prec = default_precision) {
    auto ret = prec;
    prec     = _prec;
    return ret;
  }
  unsigned setf(unsigned flags = default_flag) {
    auto ret = flag;
    flag     = flags;
    return ret;
  }
  template <typename T> void print_real(const T& x, unsigned _prec = 0) {
    char     format[8] = {'%', '.'};
    unsigned t, i = 2;
    if (_prec == 0) _prec = prec;
    if ((t = (_prec / 100) % 10)) format[i++] = t + '0';
    if ((t = (_prec / 10) % 10)) format[i++] = t + '0';
    if ((t = prec % 10)) format[i++] = t + '0';
    if (typeid(T) == typeid(double)) format[i++] = 'l';
    else if (typeid(T) == typeid(long double)) format[i++] = 'L';
    switch (flag & 31) {
      case fixed: format[i++] = 'f'; break;
      case scientific: format[i++] = 'e'; break;
      case SCIENTIFIC: format[i++] = 'E'; break;
      case SMART: format[i++] = 'G'; break;
      default: format[i++] = 'g'; break;
    }
    format[i] = '\0';
    printf(format, x);
  }
  fastio_t& operator<<(const float& x) {
    print_real(x);
    return *this;
  }
  fastio_t& operator<<(const double& x) {
    print_real(x);
    return *this;
  }
  fastio_t& operator<<(const long double& x) {
    print_real(x);
    return *this;
  }

  template <typename T> fastio_t& operator>>(T& x) {
    int sig;
    id3(x, sig);
    return *this;
  }
  template <typename T> fastio_t& operator<<(T x) {
    if (x == 0) {
      putchar('0');
      return *this;
    }
    if (x < 0) {
      putchar('-');
      x = -x;
    }
    char* sp = buf;
    while (x) {
      *sp++ = (x % 10) + '0';
      x /= 10;
    }
    do { putchar(*--sp); } while (sp != buf);
    return *this;
  }
  operator bool() const { return !bad; }
} __fio;





class integer_t {
public:
  std::deque<uint32_t> a;
  bool                 sign = false;

  void simplify() noexcept {
    while (!a.empty() && a.back() == 0) a.pop_back();
    if (a.empty()) sign = false;
  }
  void clear() noexcept {
    sign = false;
    a.clear();
  }

  integer_t& add_eq_usg(const integer_t& that) {
    auto id10 = that.a.size();
    auto siz      = std::max(a.size(), id10);
    if (siz != a.size()) a.resize(siz);
    uint32_t carry = 0;
    size_t   i;
    for (i = 0; i < id10; ++i) {
      uint64_t res_tmp = a[i];
      res_tmp += that.a[i];
      res_tmp += carry;
      carry = res_tmp >> 32;
      a[i]  = res_tmp;
    }
    for (; i < siz && carry; ++i) {
      uint64_t res_tmp = a[i];
      res_tmp += carry;
      carry = res_tmp >> 32;
      a[i]  = res_tmp;
    }
    if (carry) a.push_back(carry);
    simplify();
    return *this;
  }
  integer_t& sub_eq_usg(const integer_t& that) {
    auto id10 = that.a.size();
    auto siz      = std::max(a.size(), id10);
    if (siz != a.size()) a.resize(siz);
    uint32_t       carry = 0;
    const uint64_t base  = (uint64_t) 1 << 32;
    size_t         i;
    for (i = 0; i < id10; ++i) {
      uint64_t res_tmp = base + a[i];
      res_tmp -= that.a[i];
      res_tmp -= carry;
      carry = 1 - (res_tmp >> 32);
      a[i]  = res_tmp;
    }
    for (; i < siz && carry; ++i) {
      uint64_t res_tmp = base + a[i];
      res_tmp -= carry;
      carry = 1 - (res_tmp >> 32);
      a[i]  = res_tmp;
    }
    if (carry) {
      sign = !sign;
      a[0] = base - a[0];
      for (i = 1; i < siz; ++i) a[i] = ~a[i];
    }
    simplify();
    return *this;
  }
  integer_t& operator+=(const integer_t& that) {
    if (sign == that.sign) return add_eq_usg(that);
    return sub_eq_usg(that);
  }
  integer_t& operator-=(const integer_t& that) {
    if (sign == that.sign) return sub_eq_usg(that);
    return add_eq_usg(that);
  }
  integer_t operator+(const integer_t& that) const {
    auto res = *this;
    return res += that;
  }
  integer_t operator-(const integer_t& that) const {
    auto res = *this;
    return res -= that;
  }
  integer_t& operator+=(uint32_t val) {
    return this->operator+=((integer_t) val);
  }
  integer_t& operator-=(uint32_t val) {
    return this->operator-=((integer_t) val);
  }
  integer_t operator+(uint32_t val) const {
    auto res = *this;
    return res += val;
  }
  integer_t operator-(uint32_t val) const {
    auto res = *this;
    return res -= val;
  }
  integer_t& operator+=(int32_t val) {
    return this->operator+=((integer_t) val);
  }
  integer_t& operator-=(int32_t val) {
    return this->operator-=((integer_t) val);
  }
  integer_t operator+(int32_t val) const {
    auto res = *this;
    return res += val;
  }
  integer_t operator-(int32_t val) const {
    auto res = *this;
    return res -= val;
  }

  void swap(integer_t& that) noexcept {
    simplify();
    std::swap(sign, that.sign);
    a.swap(that.a);
    simplify();
  }

  integer_t& operator=(const integer_t& that) {
    sign = that.sign;
    a.assign(that.a.begin(), that.a.end());
    simplify();
    return *this;
  }
  template <typename T = int> integer_t& operator=(T _val) {
    a.clear();
    sign         = _val < 0;
    uint64_t val = _val;
    if (sign) val = -((int64_t) _val);
    while (val) {
      a.push_back(val & 0xffffffff);
      val >>= 32;
    }
    return *this;
  }
  template <typename T = int> integer_t(T val = T()) { this->operator=(val); }
  integer_t(const integer_t& that) { this->operator=(that); }

  int compare(const integer_t& that) const noexcept {
    if (sign != that.sign) return (sign ? -1 : 1);
    auto siz      = a.size();
    auto id10 = that.a.size();
    if (siz != id10) return (sign ^ (siz < id10) ? -1 : 1);
    for (auto _i = siz; _i; --_i)

      if (a[i] != that.a[i]) return (sign ^ (a[i] < that.a[i]) ? -1 : 1);

    return 0;
  }
  bool operator==(const integer_t& that) const {
    return compare(that) == 0;
  }
  bool operator!=(const integer_t& that) const {
    return compare(that) != 0;
  }
  bool operator<(const integer_t& that) const {
    return compare(that) < 0;
  }
  bool operator>(const integer_t& that) const {
    return compare(that) > 0;
  }
  bool operator<=(const integer_t& that) const {
    return compare(that) <= 0;
  }
  bool operator>=(const integer_t& that) const {
    return compare(that) >= 0;
  }

  bool operator==(uint32_t val) const {
    return compare((integer_t) val) == 0;
  }
  bool operator!=(uint32_t val) const {
    return compare((integer_t) val) != 0;
  }
  bool operator<(uint32_t val) const {
    return compare((integer_t) val) < 0;
  }
  bool operator>(uint32_t val) const {
    return compare((integer_t) val) > 0;
  }
  bool operator<=(uint32_t val) const {
    return compare((integer_t) val) <= 0;
  }
  bool operator>=(uint32_t val) const {
    return compare((integer_t) val) >= 0;
  }
  bool operator==(int32_t val) const {
    return compare((integer_t) val) == 0;
  }
  bool operator!=(int32_t val) const {
    return compare((integer_t) val) != 0;
  }
  bool operator<(int32_t val) const {
    return compare((integer_t) val) < 0;
  }
  bool operator>(int32_t val) const {
    return compare((integer_t) val) > 0;
  }
  bool operator<=(int32_t val) const {
    return compare((integer_t) val) <= 0;
  }
  bool operator>=(int32_t val) const {
    return compare((integer_t) val) >= 0;
  }

  integer_t& mul_eq_u32(uint32_t val = 0) {
    if (val) simplify();
    else clear();
    if (!val || val == 1 || a.empty()) return *this;
    uint32_t carry = 0;
    for (auto& e : a) {
      uint64_t res_tmp = e;
      res_tmp *= val;
      res_tmp += carry;
      e     = res_tmp;
      carry = res_tmp >> 32;
    }
    if (carry) a.push_back(carry);
    return *this;
  }
  integer_t& mul_eq_i32(int32_t val = 0) {
    mul_eq_u32(std::abs((int64_t) val));
    sign ^= val < 0;
    return *this;
  }
  integer_t& shift_left_32(size_t id0) {
    simplify();
    if (a.empty()) return *this;
    for (size_t i = 0; i < id0; ++i) a.push_front(0);
    return *this;
  }
  integer_t& shift_right_32(size_t id0) {
    simplify();
    if (a.empty()) return *this;
    for (size_t i = 0; i < id0 && !a.empty(); ++i) a.pop_front();
    return *this;
  }

  integer_t& operator*=(uint32_t val) {
    return mul_eq_u32(val);
  }
  integer_t operator*(uint32_t val) const {
    auto res = *this;
    return res *= val;
  }
  integer_t& operator*=(int32_t val) {
    return mul_eq_i32(val);
  }
  integer_t operator*(int32_t val) const {
    auto res = *this;
    return res *= val;
  }
  integer_t mul(const integer_t& that) const {
    integer_t res = 0;
    res.sign      = sign ^ that.sign;
    for (size_t i = 0; i < a.size(); ++i) res += (that * a[i]).shift_left_32(i);
    return res;
  }
  integer_t operator*(const integer_t& that) const {
    return mul(that);
  }
  integer_t& operator*=(const integer_t& that) {
    return *this = mul(that);
  }

  integer_t& div_eq_mod_u32(uint32_t val, uint32_t& modulo) {
    if (!val) throw std::domain_error("divided by zero");
    modulo = 0;
    simplify();
    if (val == 1 || a.empty()) return *this;
    uint64_t mod = 0;
    for (auto _i = a.size(); _i; --_i) {

      mod  = (mod << 32) + a[i];
      a[i] = mod / val;
      mod %= val;

    }
    modulo = mod;
    simplify();
    return *this;
  }
  integer_t& operator/=(uint32_t val) {
    uint32_t mod;
    return div_eq_mod_u32(val, mod);
  }
  integer_t operator/(uint32_t val) const {
    auto res = *this;
    return res /= val;
  }
  integer_t& operator%=(uint32_t val) {
    uint32_t mod;
    div_eq_mod_u32(val, mod);
    this->operator=(mod);
    return *this;
  }
  uint32_t operator%(uint32_t val) const {
    auto     res = *this;
    uint32_t mod;
    res.div_eq_mod_u32(val, mod);
    return mod;
  }
  integer_t& operator/=(int32_t val) {
    uint32_t mod;
    uint32_t _val = std::abs((int64_t) val);
    sign ^= val < 0;
    return div_eq_mod_u32(_val, mod);
  }
  integer_t operator/(int32_t val) const {
    auto res = *this;
    return res /= val;
  }

  operator bool() const {
    return !a.empty();
  }

  integer_t operator-() const {
    auto res = *this;
    res.sign = !res.sign;
    return res;
  }

  std::string str() const {
    std::string res;
    auto        tmp = *this;
    uint32_t    mod = 0;
    if (a.empty()) {
      res = "0";
      goto LOC_STR_END;
    }
    while (tmp) {
      tmp.div_eq_mod_u32(10, mod);
      res += (char) mod + '0';
    }
    if (sign) res += '-';
    std::reverse(res.begin(), res.end());
LOC_STR_END:
    return res;
  }

  void from_str(char* str) {
    this->clear();
    sign = *str == '-' ? ++str, true : false;
    for (; *str >= '0' && *str <= '9'; ++str) {
      this->operator*=(10u);
      this->operator+=(static_cast<unsigned>(*str - '0'));
    }
  }
  void from_str(const char* const __str) {
    from_str(const_cast<char*>(__str));
  }
  void from_str(const std::string& str) {
    from_str(str.c_str());
  }

  friend bool& signbit(integer_t& bint) {
    return bint.sign;
  }
  friend bool signbit(const integer_t& bint) {
    return bint.sign;
  }
  friend void abs(integer_t& bint) {
    bint.sign = false;
  }
  friend integer_t abs(integer_t bint) {
    bint.sign = false;
    return bint;
  }
  friend integer_t operator+(uint32_t val, const integer_t& bint) {
    return bint + val;
  }
  friend integer_t operator-(uint32_t val, const integer_t& bint) {
    return -(bint - val);
  }
  friend integer_t operator*(uint32_t val, const integer_t& bint) {
    return bint * val;
  }
  friend integer_t operator+(int32_t val, const integer_t& bint) {
    return bint + val;
  }
  friend integer_t operator-(int32_t val, const integer_t& bint) {
    return -(bint - val);
  }
  friend integer_t operator*(int32_t val, const integer_t& bint) {
    return bint * val;
  }
  friend bool operator==(uint32_t val, const integer_t& bint) {
    return bint.compare((integer_t) val) == 0;
  }
  friend bool operator!=(uint32_t val, const integer_t& bint) {
    return bint.compare((integer_t) val) != 0;
  }
  friend bool operator<(uint32_t val, const integer_t& bint) {
    return bint.compare((integer_t) val) > 0;
  }
  friend bool operator>(uint32_t val, const integer_t& bint) {
    return bint.compare((integer_t) val) < 0;
  }
  friend bool operator<=(uint32_t val, const integer_t& bint) {
    return bint.compare((integer_t) val) >= 0;
  }
  friend bool operator>=(uint32_t val, const integer_t& bint) {
    return bint.compare((integer_t) val) <= 0;
  }

  friend bool operator==(int32_t val, const integer_t& bint) {
    return bint.compare((integer_t) val) == 0;
  }
  friend bool operator!=(int32_t val, const integer_t& bint) {
    return bint.compare((integer_t) val) != 0;
  }
  friend bool operator<(int32_t val, const integer_t& bint) {
    return bint.compare((integer_t) val) > 0;
  }
  friend bool operator>(int32_t val, const integer_t& bint) {
    return bint.compare((integer_t) val) < 0;
  }
  friend bool operator<=(int32_t val, const integer_t& bint) {
    return bint.compare((integer_t) val) >= 0;
  }
  friend bool operator>=(int32_t val, const integer_t& bint) {
    return bint.compare((integer_t) val) <= 0;
  }
};

template <typename T>
typename std::enable_if<std::is_arithmetic<T>::value, T>::type fast_pow(
  T base, int exponent) {
  T    ans = 1;
  bool r   = exponent < 0;
  if (r) exponent = -exponent;
  while (exponent) {
    if (exponent & 1) ans *= base;
    base *= base;
    exponent >>= 1;
  }
  if (r) return (1.0l / ans);
  return ans;
}



void id7() {
  fread(id9, sizeof(char), id2, stdin);
}

void id6() {
  if (id12 > id5)
    fwrite(id5, sizeof(char), id12 - id5, stdout);
}

char peek() {
  return *id11;
}

int readchar() {
  return *id11 ? *id11++ : EOF;
}

void read(char& ch) {
  while (*id11 && *id11 <= 32 || *id11 >= 127) ++id11;
  ch = (*id11 > 32 && *id11 < 127) ? *id11++ : 0;
}

void read(char* str) {
  while (*id11 && *id11 <= 32 || *id11 >= 127) ++id11;
  while (*id11 > 32 && *id11 < 127) *str++ = *id11++;
  *str = '\0';
}

void readline(char* str) {
  for (; *id11 && *id11 != '\n'; ++id11)
    if (*id11 >= 32 && *id11 < 127 || *id11 == '\t')
      *str++ = *id11;
  while (*id11 && *id11 <= 32 || *id11 >= 127) ++id11;
  *str = '\0';
}

void readline(std::string& str) {
  auto   bak = id11;
  size_t sz  = 0;
  for (; *id11 && *id11 != '\n'; ++id11)
    if (*id11 >= 32 && *id11 < 127 || *id11 == '\t') ++sz;
  str.resize(sz);
  auto it = str.begin();
  for (id11 = bak; *id11 && *id11 != '\n'; ++id11)
    if (*id11 >= 32 && *id11 < 127 || *id11 == '\t')
      *it++ = *id11;
  while (*id11 && *id11 <= 32 || *id11 >= 127) ++id11;
}

template <typename T>
typename std::enable_if<std::is_integral<T>::value>::type read(T& __integer) {
  while (*id11 && *id11 <= 32 || *id11 >= 127) ++id11;
  bool sign = *id11 == '-' ? ++id11, true : false;
  for (__integer = T(); *id11 >= '0' && *id11 <= '9'; ++id11)
    __integer = (__integer * 10) + (*id11 - '0');
  if (sign) __integer = -__integer;
}

int read() {
  int ret;
  read(ret);
  return ret;
}

template <typename T>
typename std::enable_if<std::is_floating_point<T>::value>::type read(
  T& __float) {
  long long __integer;
  read(__integer);
  __float  = __integer;
  auto bak = id11;
  auto ch  = *id11++;
  read(__integer);
  if (ch == '.') {
    if (__integer < 0) id11 = bak;
    else {
      T factor = 1.0;
      for (auto i = __integer; i; i /= 10000) {
        if (i < 10) factor *= 0.1;
        else if (i < 100) factor *= 0.01;
        else if (i < 1000) factor *= 0.001;
        else factor *= 0.0001;
      }
      __float += __integer * factor;
    }
  } else if (ch == 'e' || ch == 'E')
    __float *= fast_pow(static_cast<T>(10.0), __integer);
}

template <typename T, typename... Ts> void read(T& first, Ts&... rest) {
  read(first), read(rest...);
}

void print(char ch = '\n') {
  *id12++ = ch;
}

void print(char* str) {
  while (*str) *id12++ = *str++;
}

void print(const char* const __str) {
  print(const_cast<char*>(__str));
}

void print(const std::string& str) {
  for (auto ch : str) *id12++ = ch;
}

template <typename T>
typename std::enable_if<std::is_integral<T>::value>::type print(T __integer) {
  if (__integer == 0) {
    *id12++ = '0';
    return;
  } else if (__integer < 0) {
    *id12++ = '-';
    __integer      = -__integer;
  }
  char* i = id12;
  for (; __integer; __integer /= 10) *id12++ = (__integer % 10) + '0';
  for (char* j = id12 - 1; i < j; ++i, --j) std::iter_swap(i, j);
}

void print(float __float) {
  id12 += sprintf(id12, "%f", __float);
}

void print(double __double) {
  id12 += sprintf(id12, "%lf", __double);
}

void print(long double id8) {
  id12 += sprintf(id12, "%Lf", id8);
}

void print(bool bol) {
  bol ? print("true") : print("false");
}

template <typename T, typename... Ts> void print(T first, Ts... rest) {
  print(first), print(rest...);
}

template <typename... Ts> void printline(Ts... args) {
  print(args...), print();
}

void id4() {
  id7();
  atexit(id6);
}



template <typename T> class matrix_t {
public:
  matrix_t() noexcept { n = m = 0; }
  matrix_t(size_t x, size_t y = 1) noexcept {
    n = m = 0;
    this->resize(x, y);
  }
  matrix_t(const matrix_t<T>& other) noexcept { this->operator=(other); }
  matrix_t(matrix_t<T>&& other) noexcept { this->swap(other); }

  matrix_t<T>& operator=(const matrix_t<T>& other) noexcept {
    if (n != other.n || m != other.m) {
      n = other.n;
      m = other.m;
      if (n && m) arr.reset(new T[n * m]);
      else arr.release();
    }
    if (n && m && this != &other)
      for (size_t i = 0; i < n * m; ++i) arr.get()[i] = other.arr.get()[i];
  }
  matrix_t<T>& operator=(matrix_t<T>&& other) noexcept { this->swap(other); }

  void swap(matrix_t<T>& other) noexcept {
    std::swap(n, other.n);
    std::swap(m, other.m);
    arr.swap(other.arr);
  }

  size_t resize(size_t x, size_t y = 1) noexcept {
    if (n == x && m == y && n && m)
      for (size_t i = 0; i < n * m; ++i) arr.get()[i] = T();
    else {
      n = x;
      m = y;
      if (n && m) arr.reset(new T[n * m]());
      else arr.release();
    }
    return n * m;
  }

  void clear() noexcept {
    n = m = 0;
    arr.release();
  }

  size_t size() const noexcept { return n * m; }
  size_t row() const noexcept { return n; }
  size_t col() const noexcept { return m; }

  T& operator()(size_t x, size_t y = 1) {
    return arr.get()[(x - 1) * m + y - 1];
  }
  T operator()(size_t x, size_t y = 1) const {
    return arr.get()[(x - 1) * m + y - 1];
  }

  size_t             n = 0, m = 0;
  std::unique_ptr<T> arr;
};
using namespace std;

void   __solve();
signed main() {

  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);

  int T = 1;

  id4();
  read(T);

  cin >> T;

  while (T--) __solve();
}






const auto         pi_ld    = acos(-1.0l);
const auto         e_ld     = exp(1.0l);
constexpr auto     eps      = 1e-8l;
constexpr uint64_t base10[] = {1ul,
                               10ul,
                               100ul,
                               1000ul,
                               10000ul,
                               100000ul,
                               1000000ul,
                               10000000ul,
                               100000000ul,
                               1000000000ul,
                               10000000000ul,
                               100000000000ul,
                               1000000000000ul,
                               10000000000000ul,
                               100000000000000ul,
                               1000000000000000ul,
                               10000000000000000ul,
                               100000000000000000ul,
                               1000000000000000000ul,
                               10000000000000000000ul};

void __solve() {
  int n, x;
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> x;
  cout << x << endl;
}
