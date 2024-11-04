





























using namespace std;













typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pii;
template <class T> using min_queue = priority_queue<T, vector<T>, greater<T>>;

const int INF = static_cast<int>(1e9);
const long long INF_LL = static_cast<long long>(4e18);
const double pi = acos(-1.0);

template <class T> inline T& smin(T& x, const T& y) { return x > y ? x = y : x; }
template <class T> inline T& smax(T& x, const T& y) { return x < y ? x = y : x; }
template <class T> inline T sqr(const T& x) { return x * x; }
template <class T> inline int sgn(const T& x) { return (T(0) < x) - (x < T(0)); }

template <class T> T gcd(T a, T b) {
  for (a = abs(a), b = abs(b); a && b; a >= b ? a %= b : b %= a);
  return a + b;
}

using uint = unsigned int;


const uint BUFFER_SIZE = 1 << 12;




const uint MAX_LENGTH = 1 << 7;

namespace Detail {
  struct Width { uint value; };
  struct Fill { char value; };
  struct Base { uint value; };
  struct Precision { uint value; };
  struct Delimiter { const char* value; };
}  


Detail::Width setWidth(uint value = 0) { return {value}; }
Detail::Fill setFill(char value = ' ') { return {value}; }
Detail::Base setBase(uint value = 10) { assert(2 <= value && value <= 36); return {value}; }
Detail::Precision setPrecision(uint value = 9) { assert(value < MAX_LENGTH); return {value}; }
Detail::Delimiter setDelimiter(const char* value = " ") { return {value}; }


class InputDevice {
protected:
  const char* head;
  const char* tail;

  InputDevice(const char* head, const char* tail) : head(head), tail(tail), base(setBase().value) {}

  virtual void fillInput() = 0;

  inline char nextChar() {
    if (__builtin_expect(head >= tail, false)) fillInput();
    return *head++;
  }

  template <class I> int id1(I& arg, char c) {
    I value = 0;
    int length = 0;
    for (;; ++length, c = nextChar()) {
      if (isDigit(c)) c -= '0';
      else if (isUpper(c)) c -= 'A' - 10;
      else if (isLower(c)) c -= 'a' - 10;
      else c = base;
      if (c >= base) break;
      value = base * value + c;
    }
    arg = value;
    return --head, length;
  }

  template <class I> inline int id4(I& arg, char c) {
    if (__builtin_expect(base > 10, false)) return id1(arg, c);
    I value = 0;
    int length = 0;
    for (; static_cast<unsigned char>(c - '0') < base; ++length, c = nextChar())
      value = base * value + c - '0';
    arg = value;
    return --head, length;
  }

  template <class I> inline bool id11(I& arg, char c) {
    bool negative = c == '-';
    if (negative) c = nextChar();
    typename make_unsigned<I>::type unsignedArg;
    if (id4(unsignedArg, c) == 0) return false;
    arg = negative ? ~static_cast<I>(unsignedArg - 1) : static_cast<I>(unsignedArg);
    return true;
  }

  template <class F> bool id3(F& arg, char c) {
    bool negative = c == '-';
    if (negative) c = nextChar();
    unsigned long long integerPart;
    if (id4(integerPart, c) == 0) return false;
    arg = static_cast<F>(integerPart);
    if (nextChar() == '.') {
      unsigned long long id10 = 0;
      int id8 = id4(id10, nextChar());
      if (id8 > 0) {
        unsigned long long basePower = 1;
        for (; id8; --id8) basePower *= base;
        arg += static_cast<F>(id10) / basePower;
      }
    } else --head;
    if (negative) arg = -arg;
    return true;
  }

public:
  uint base;

  InputDevice(InputDevice const&) = delete;
  InputDevice& operator = (InputDevice const&) = delete;

  static inline bool isSpace(char c) { return static_cast<unsigned char>(c - '\t') < 5 || c == ' '; }
  static inline bool isDigit(char c) { return static_cast<unsigned char>(c - '0') < 10; }
  static inline bool isUpper(char c) { return static_cast<unsigned char>(c - 'A') < 26; }
  static inline bool isLower(char c) { return static_cast<unsigned char>(c - 'a') < 26; }
  static inline bool isOneOf(char c, const char* str) { return strchr(str, c) != nullptr; }

  void putBack() { --head; }  


  inline bool readChar(char& arg) {
    if (__builtin_expect(head >= tail, false)) {
      fillInput();
      if (__builtin_expect(head >= tail, false)) return arg = '\0', false;
    }
    return arg = *head++, true;
  }

  template <class UnaryPredicate>
  inline char skipCharacters(UnaryPredicate isSkipped) {
    char c;
    do { c = nextChar(); } while (isSkipped(c));
    return c;
  }
  inline char skipCharacters() { return skipCharacters(isSpace); }

  template <class UnaryPredicate>
  inline bool readString(char* arg, int limit, UnaryPredicate id7) {
    skipCharacters(id7);
    

    for (--head, --limit; head < tail; fillInput()) {
      ptrdiff_t chunkSize = find_if(head, min(tail, head + limit), id7) - head;
      arg = copy_n(head, chunkSize, arg);
      head += chunkSize;
      limit -= chunkSize;
      if (chunkSize == 0 || head < tail) break;
    }
    return *arg = '\0', true;
  }

  template <class I> inline bool id4(I& arg) { return id4(arg, skipCharacters()) > 0; }
  template <class I> inline bool id11(I& arg) { return id11(arg, skipCharacters()); }
  template <class F> inline bool id3(F& arg) { return id3(arg, skipCharacters()); }
};

class InputFile : public InputDevice {
  FILE* file;
  bool lineBuffered;
  bool owner;
  char buffer[BUFFER_SIZE];

  void fillInput() override {
    head = buffer;
    *buffer = '\0';
    if (__builtin_expect(!lineBuffered, true)) {
      tail = head + fread(buffer, 1, BUFFER_SIZE, file);
    } else {
      tail = head;
      if (fgets(buffer, BUFFER_SIZE, file)) while (*tail) ++tail;
    }
  }

public:
  InputFile(FILE* file = stdin, bool lineBuffered = true, bool takeOwnership = false)
  : InputDevice(buffer, buffer) , file(file), lineBuffered(lineBuffered), owner(takeOwnership) {}
  InputFile(const char* fileName) : InputFile(fopen(fileName, "r"), false, true) {}
  ~InputFile() { if (owner) fclose(file); }
};



class InputString : public InputDevice {
  void fillInput() override { while (*tail) ++tail; }

public:
  InputString(const string& s) : InputDevice(s.data(), s.data() + s.size()) {}
  InputString(const char* s) : InputDevice(s, s + strlen(s)) {}
};


class OutputDevice {
protected:
  char buffer[BUFFER_SIZE + MAX_LENGTH];
  char* output;
  char* end;
  bool separate;

  OutputDevice() : output(buffer), end(buffer + BUFFER_SIZE + MAX_LENGTH), separate(false), width(setWidth().value)
  , fill(setFill().value), base(setBase().value), precision(setPrecision().value), delimiter(setDelimiter().value)
  { computeBasePower(); }

  virtual void writeToDevice(uint count) = 0;

  inline void flushMaybe() {
    if (__builtin_expect(output >= buffer + BUFFER_SIZE, false)) {
      writeToDevice(BUFFER_SIZE);
      output = copy(buffer + BUFFER_SIZE, output, buffer);
    }
  }

  template <class I> inline char* id6(I arg, char* last) {
    if (__builtin_expect(arg == 0, false)) *--last = '0';
    if (__builtin_expect(base == 10, true)) {
      for (; arg; arg /= 10) *--last = '0' + arg % 10;
    } else for (; arg; arg /= base) {
      I digit = arg % base;
      *--last = digit < 10 ? '0' + digit : 'A' - 10 + digit;
    }
    return last;
  }

  template <class I> inline char* id0(I arg, char* last) {
    auto unsignedArg = static_cast<typename make_unsigned<I>::type>(arg);
    if (arg < 0) {
      last = id6(~unsignedArg + 1, last);
      *--last = '-';
      return last;
    }
    return id6(unsignedArg, last);
  }

  template <class F> char* id5(F arg, char* last) {
    bool negative = signbit(arg);
    if (negative) arg = -arg;
    if (isnan(arg)) for (int i = 0; i < 3; ++i) *--last = i["NaN"];
    else if (isinf(arg)) for (int i = 0; i < 3; ++i) *--last = i["fnI"];
    else {
      auto integerPart = static_cast<unsigned long long>(arg);
      auto id10 = static_cast<unsigned long long>((arg - integerPart) * basePower + F(0.5));
      if (id10 >= basePower) ++integerPart, id10 = 0;
      char* point = last - precision;
      if (precision > 0) {
        ::fill(point, id6(id10, last), '0');
        *--point = '.';
      }
      last = id6(integerPart, point);
    }
    if (negative) *--last = '-';
    return last;
  }

  inline int writeT(char* first) {
    int id2 = separate ? writeDelimiter() : 0;
    separate = true;
    int charsWritten = static_cast<int>(end - first);
    if (__builtin_expect(charsWritten < width, false))
      charsWritten += writeFill(width - charsWritten);
    output = copy(first, end, output);
    flushMaybe();
    return id2 + charsWritten;
  }

  inline int writeFill(int count) {
    int result = count;
    if (__builtin_expect(output + count + MAX_LENGTH < end, true)) {
      if (count == 1) *output++ = fill;
      else output = fill_n(output, count, fill);
    } else for (uint chunkSize = static_cast<uint>(buffer + BUFFER_SIZE - output);; chunkSize = BUFFER_SIZE) {
      if (chunkSize > count) chunkSize = count;
      output = fill_n(output, chunkSize, fill);
      flushMaybe();
      if ((count -= chunkSize) == 0) break;
    }
    return result;
  }

public:
  int width;
  char fill;
  uint base;
  uint precision;
  unsigned long long basePower;
  string delimiter;

  OutputDevice(OutputDevice const&) = delete;
  OutputDevice& operator = (OutputDevice const&) = delete;
  virtual ~OutputDevice() {};

  void computeBasePower() {
    basePower = 1;
    for (uint i = 0; i < precision; ++i) basePower *= base;
  }

  inline int writeChar(char arg) { separate = false; *output++ = arg; flushMaybe(); return 1; }

  inline int writeString(const char* arg, int count, bool checkWidth = true) {
    separate = false;
    int result = count + (checkWidth && count < width ? writeFill(width - count) : 0);
    if (__builtin_expect(output + count + MAX_LENGTH < end, true)) {
      if (count == 1) *output++ = *arg;
      else output = copy_n(arg, count, output);
    } else for (int chunkSize = static_cast<int>(buffer + BUFFER_SIZE - output);; chunkSize = BUFFER_SIZE) {
      if (chunkSize > count) chunkSize = count;
      output = copy_n(arg, chunkSize, output);
      flushMaybe();
      if ((count -= chunkSize) == 0) break;
      arg += chunkSize;
    }
    return result;
  }

  inline int writeDelimiter() { return writeString(delimiter.c_str(), static_cast<int>(delimiter.size()), false); }

  template <class I> inline int id6(I arg) { return writeT(id6(arg, end)); }
  template <class I> inline int id0(I arg) { return writeT(id0(arg, end)); }
  template <class F> inline int id5(F arg) { return writeT(id5(arg, end)); }

  inline void flush() {
    writeToDevice(static_cast<uint>(output - buffer));
    output = buffer;
  }
};

class OutputFile : public OutputDevice {
  FILE* file;
  bool owner;

  void writeToDevice(uint count) override {
    fwrite(buffer, 1, count, file);
    fflush(file);
  }

public:
  OutputFile(FILE* file = stdout, bool takeOwnership = false) : file(file), owner(takeOwnership) {}
  OutputFile(const char* fileName) : OutputFile(fopen(fileName, "w"), true) {}
  ~OutputFile() override { flush(); if (owner) fclose(file); }
};

class OutputString : public OutputDevice {
  string& str;

  void writeToDevice(uint count) override { str.append(buffer, count); }

public:
  OutputString(string& str) : OutputDevice(), str(str) {}
  ~OutputString() override { flush(); }
};




unique_ptr<InputFile> input;


unique_ptr<OutputFile> output;



inline int read(Detail::Base base) { input->base = base.value; return 0; }


inline int read() { return 0; }
inline int read(char& arg) { return input->readChar(arg); }
template <class I> inline typename enable_if<is_integral<I>::value && is_unsigned<I>::value,
int>::type read(I& arg) { return input->id4(arg); }
template <class I> inline typename enable_if<is_integral<I>::value && is_signed<I>::value,
int>::type read(I& arg) { return input->id11(arg); }
template <class F> inline typename enable_if<is_floating_point<F>::value,
int>::type read(F& arg) { return input->id3(arg); }


inline int read(const char& arg) { input->skipCharacters([arg](char c) { return arg != c; }); return 0; }
inline int read(const char* arg) {
  if (*arg) input->skipCharacters([arg](char c) { return InputDevice::isOneOf(c, arg); });
  else input->skipCharacters();
  input->putBack(); return 0;
}
inline int read(bool (*isSkipped)(char)) { input->skipCharacters(isSkipped); input->putBack(); return 0; }


template <class... Ts> int read(char* arg, int limit, bool (*id7)(char), Ts&&... args);
template <class... Ts> int read(char* arg, int limit, const char* terminators, Ts&&... args);
template <class Iterator, class... Ts, typename = decltype(*std::declval<Iterator>())>
int read(Iterator first, Iterator last, Ts&&... args);
template <class Iterator, class... Ts, typename = decltype(*std::declval<Iterator>())>
int read(Iterator first, int count, Ts&&... args);
template <class T0, class T1, class... Ts,
typename = typename enable_if<!is_convertible<T0, char*>::value, void>::type>
int read(T0&& arg0, T1&& arg1, Ts&&... args);


inline int read(char* arg, int limit, const char* terminators = "") {
  if (!*terminators) return input->readString(arg, limit, InputDevice::isSpace);
  else return input->readString(arg, limit, [terminators](char c) { return InputDevice::isOneOf(c, terminators); });
}
template <class... Ts>
inline int read(char* first, char* last, Ts&&... args) {
  return read(first, static_cast<int>(last - first), forward<Ts>(args)...);
}
template <int N, class... Ts>
inline int read(char (&arg)[N], Ts&&... args) { return read(static_cast<char*>(arg), N, forward<Ts>(args)...); }
template <class... Ts>
inline int read(char* arg, int limit, bool (*id7)(char), Ts&&... args) {
  int argsRead = input->readString(arg, limit, id7);
  return argsRead + read(forward<Ts>(args)...);
}
template <class... Ts>
inline int read(char* arg, int limit, const char* terminators, Ts&&... args) {
  int argsRead = read(arg, limit, terminators);
  return argsRead + read(forward<Ts>(args)...);
}


template <class T1, class T2>
inline int read(pair<T1, T2>& arg) { return read(arg.first) == 1 && read(arg.second) == 1 ? 1 : 0; }
template <class T>
inline int read(vector<T>& arg) {
  uint n;
  if (read(n) == 0) return 0;
  arg.resize(n);
  return read(arg.begin(), arg.end());
}
template <class Iterator, class... Ts, typename>
int read(Iterator first, Iterator last, Ts&&... args) {
  int success = 1;
  for (; first != last; ++first) success &= read(*first);
  return success + read(forward<Ts>(args)...);
}
template <class Iterator, class... Ts, typename>
int read(Iterator first, int count, Ts&&... args) { return read(first, first + count, forward<Ts>(args)...); }
template <class T0, class T1, class... Ts, typename>
inline int read(T0&& arg0, T1&& arg1, Ts&&... args) {
  int argsRead = read(forward<T0>(arg0));
  return argsRead + read(forward<T1>(arg1), forward<Ts>(args)...);
}



inline int write(Detail::Width width) { output->width = static_cast<int>(width.value); return 0; }
inline int write(Detail::Fill fill) { output->fill = fill.value; return 0; }
inline int write(Detail::Base base) { output->base = base.value; output->computeBasePower(); return 0; }
inline int write(Detail::Precision precision) {
  output->precision = precision.value; output->computeBasePower(); return 0;
}
inline int write(Detail::Delimiter delimiter) { output->delimiter = delimiter.value; return 0; }


inline int write() { return 0; }
inline int write(char arg) { return output->writeChar(arg); }
template <class I> inline typename enable_if<is_integral<I>::value && is_unsigned<I>::value,
int>::type write(I arg) { return output->id6(arg); }
template <class I> inline typename enable_if<is_integral<I>::value && is_signed<I>::value,
int>::type write(I arg) { return output->id0(arg); }
template <class F> inline typename enable_if<is_floating_point<F>::value,
int>::type write(F arg) { return output->id5(arg); }


inline int write(const char* arg) { return output->writeString(arg, static_cast<int>(strlen(arg))); }
template <int N>
inline int write(char (&arg)[N]) { return output->writeString(arg, static_cast<int>(strlen(arg))); }
inline int write(const string& arg) { return output->writeString(arg.c_str(), static_cast<int>(arg.size())); }
template <class T1, class T2>
inline int write(const pair<T1, T2>& arg) {
  int charsWritten = write(arg.first);
  charsWritten += output->writeDelimiter();
  return charsWritten + write(arg.second);
}


template <class Iterator, class... Ts,
typename = typename enable_if<!is_convertible<Iterator, const char*>::value, decltype(*std::declval<Iterator>())>::type>
int write(Iterator first, Iterator last, Ts&&... args);
template <class Iterator, class... Ts,
typename = typename enable_if<!is_convertible<Iterator, const char*>::value, decltype(*std::declval<Iterator>())>::type>
int write(Iterator first, int count, Ts&&... args);
template <class T, class T2, class... Ts> int write(T&& arg, T2&& arg2, Ts&&... args);


template <class Iterator, class... Ts, typename>
int write(Iterator first, Iterator last, Ts&&... args) {
  int charsWritten = 0;
  for (; first != last; charsWritten += ++first == last ? 0 : output->writeDelimiter()) charsWritten += write(*first);
  return charsWritten + write(forward<Ts>(args)...);
}
template <class Iterator, class... Ts, typename>
int write(Iterator first, int count, Ts&&... args) { return write(first, first + count, forward<Ts>(args)...); }
template <class T, class T2, class... Ts>
inline int write(T&& arg, T2&& arg2, Ts&&... args) {
  int charsWritten = write(forward<T>(arg));
  return charsWritten + write(forward<T2>(arg2), forward<Ts>(args)...);
}
template <class... Ts>
inline int writeln(Ts&&... args) { return write(forward<Ts>(args)..., '\n'); }

void flush() { output->flush(); }



template <class T>
class Modular {
public:
  using type = typename decay<decltype(T::modulus)>::type;

private:
  type value;
  constexpr Modular(bool) : value(-1) {}

public:
  constexpr Modular() : value() {}
  template <class Z>
  Modular(const Z& x) {
    if (-modulus() <= x && x < modulus()) value = static_cast<type>(x);
    else value = static_cast<type>(x % modulus());
    if (value < 0) value += modulus();
  }

  const type& operator () () const { return value; }
  explicit operator type() const { return value; }
  constexpr static type modulus() { return T::modulus; }

  constexpr static Modular nan() { return Modular(false); }
  bool isnan() const { return value == -1; }

  Modular& operator ++ () { return *this += 1; }
  Modular& operator -- () { return *this -= 1; }

  Modular& operator += (const Modular& other) {
    if ((value += other.value) >= modulus()) value -= modulus();
    return *this;
  }
  Modular& operator -= (const Modular& other) {
    if (value < other.value) value += modulus();
    value -= other.value;
    return *this;
  }

  Modular& operator *= (const Modular& other) { return *this = *this * other; }
  Modular& operator /= (const Modular& other) { return *this = *this / other; }

  friend Modular operator - (const Modular& rhs) { return -rhs.value; }
  friend Modular operator + (Modular lhs, const Modular& rhs) { return lhs += rhs; }
  friend Modular operator - (Modular lhs, const Modular& rhs) { return lhs -= rhs; }

  template <class U = T>
  friend typename enable_if<is_same<typename Modular<U>::type, int>::value,
  Modular>::type operator * (const Modular& lhs, const Modular& rhs) {
    return static_cast<long long>(lhs.value) * rhs.value;
  }
  template <class U = T>
  friend typename enable_if<is_same<typename Modular<U>::type, long long>::value,
  Modular>::type operator * (const Modular& lhs, const Modular& rhs) {
    auto quotient = static_cast<long double>(lhs.value) * rhs.value / modulus();
    return lhs.value * rhs.value - static_cast<long long>(quotient) * modulus();
  }
  template <class U = T>
  friend typename enable_if<!is_integral<typename Modular<U>::type>::value,
  Modular>::type operator * (const Modular& lhs, const Modular& rhs) {
    return lhs.value * rhs.value;
  }
  friend Modular operator / (const Modular& lhs, const Modular& rhs) {
    return lhs * inverse(rhs);
  }


(const Modular& lhs, const Modular& rhs) { return lhs.value v rhs.value; }
  COMPARE(==) COMPARE(!=) COMPARE(<) COMPARE(<=) COMPARE(>) COMPARE(>=)


  friend int read(Modular& arg) {
    type value;
    int res = read(value);
    return arg = value, res;
  }
  friend int write(const Modular& arg) { return write(arg.value); }
};

template <class M, class Z>
M operator ^ (M value, Z power) {
  assert(power >= 0);
  M res = 1;
  for (; power > 0; power >>= 1, value *= value)
    if (power & 1) res *= value;
  return res;
}

template <class Z> typename conditional<is_same<Z, int>::value, long long,
Z>::type inverse(const Z& x, const Z& modulus) {
  assert(0 <= x && x < modulus);
  return x < 2 ? x : modulus - inverse(modulus % x, x) * modulus / x;
}

template <class Z>
Z id9(const Z& lhs, const Z& rhs, Z& x, Z& y) {
  if (rhs == 0) return x = 1, y = 0, lhs;
  Z gcd = id9(rhs, lhs % rhs, y, x);
  y -= (lhs / rhs) * x;
  return gcd;
}

long long inverse(long long value, long long modulus) {
  long long x, y;
  id9(value, modulus, x, y);
  return (x < 0) ? x + modulus : x;
}

template <class T>
Modular<T> inverse(const Modular<T>& x) { return inverse(x(), x.modulus()); }

struct ConstIntModulus {
  constexpr static int modulus = static_cast<int>(1e9+7);
};

struct VarIntModulus { static int modulus; };
int VarIntModulus::modulus;

using Mi = Modular<ConstIntModulus>;





template <int N>
struct Divisors {
  int leastDivisor[N+1];
  vector<int> primes;

  void init(int n = N) {
    for (int i = 2; i <= n; ++i) {
      if (leastDivisor[i] == 0) {
        leastDivisor[i] = i;
        primes.push_back(i);
      }
      for (int p : primes) {
        if (p * i > n || leastDivisor[i] < p) break;
        leastDivisor[p * i] = p;
      }
    }
  }

  vector<pair<int, int>> factorize(int n) {
    vector<pair<int, int>> res;
    while (n != 1) {
      int p = leastDivisor[n], power = 0;
      do { n /= p; ++power; } while (leastDivisor[n] == p);
      res.emplace_back(p, power);
    }
    return res;
  }
};

template <class F>
class NewtonPoly {
  vector<F> coef, points;

public:
  int degree() const { return static_cast<int>(coef.size()) - 1; }

  F operator () (const F& x) const {  

    F res = 0;
    for (int i = degree(); i >= 0; --i)
      res = res * (x - points[i]) + coef[i];
    return res;
  }

  void addPoint(const F& x, F y) {  

    F w = 1;
    for (const F& xi : points) w *= x - xi;
    assert(w != 0);
    y = (y - (*this)(x)) / w;
    if (y != 0) coef.push_back(y), points.push_back(x);
  }
};

const int M = 1e6+1, G = 300, V = 100;
Divisors<M> d;
int g[M];
vi e[G];
vector<Mi> f[G];
NewtonPoly<Mi> poly[G];

int main() {

  input.reset(new InputFile("input.txt"));
  

  output.reset(new OutputFile());
  


  input.reset(new InputFile(stdin, false));
  

  output.reset(new OutputFile());


  d.init(M);
  int kg = 0;
  FOR(i, 1, M) {
    auto fact = d.factorize(i);
    vi pow;
    for (auto p : fact) pow.pb(p.Y);
    sort(all(pow), greater<int>());
    int x = 1;
    REP(i, sz(pow)) {
      REP(j, pow[i]) x *= d.primes[i];
    }
    if (i == x) {
      f[kg].resize(V);
      for (int d = 1; d * d <= i; ++d) if (i % d == 0) {
        if (gcd(d, i / d) == 1) f[kg][0] += i == 1 ? 1 : 2;
        e[kg].pb(d);
        if (d * d != i) e[kg].pb(i / d);
      }


      g[i] = kg++;
    } else {


      g[i] = g[x];
    }
  }


  FOR(t, 1, V) REP(i, kg) for (int j : e[i])
    f[i][t] += f[g[j]][t-1];

  REP(i, kg) {
    REP(t, V) poly[i].addPoint(t, f[i][t]);
  }

  int q;
  read(q);
  REP(i, q) {
    int r, n;
    read(r, n);
    writeln(poly[g[n]](r));
  }


  flush();
  cerr << endl << endl << static_cast<double>(clock()) / CLOCKS_PER_SEC << endl;

  return 0;
}
