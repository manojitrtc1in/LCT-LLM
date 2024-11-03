



































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

template <class T> struct is_commutative { constexpr static bool value = true; };

template <class T> struct is_iterator {
  template <class U, typename enable_if<!is_convertible<U, const char*>::value, int>::type = 0>
  constexpr static auto id3(int) -> decltype(*declval<U>(), bool()) { return true; }
  template <class> constexpr static bool id3(long) { return false; }
  constexpr static bool value = id3<T>(0);
};

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

  template <class I> inline int id6(I& arg, char c) {
    if (__builtin_expect(base > 10, false)) return id1(arg, c);
    I value = 0;
    int length = 0;
    for (; static_cast<unsigned char>(c - '0') < base; ++length, c = nextChar())
      value = base * value + c - '0';
    arg = value;
    return --head, length;
  }

  template <class I> inline bool id15(I& arg, char c) {
    bool negative = c == '-';
    if (negative) c = nextChar();
    typename make_unsigned<I>::type unsignedArg;
    if (id6(unsignedArg, c) == 0) return false;
    arg = negative ? ~static_cast<I>(unsignedArg - 1) : static_cast<I>(unsignedArg);
    return true;
  }

  template <class F> bool id5(F& arg, char c) {
    bool negative = c == '-';
    if (negative) c = nextChar();
    unsigned long long integerPart;
    if (id6(integerPart, c) == 0) return false;
    arg = static_cast<F>(integerPart);
    if (nextChar() == '.') {
      unsigned long long id13 = 0;
      int id11 = id6(id13, nextChar());
      if (id11 > 0) {
        unsigned long long basePower = 1;
        for (; id11; --id11) basePower *= base;
        arg += static_cast<F>(id13) / basePower;
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
  inline int readString(char* arg, int limit, UnaryPredicate id9, bool skip) {
    int charsRead = 0;
    if (skip) skipCharacters(id9), --head;
    

    for (--limit; head < tail; fillInput()) {
      ptrdiff_t chunkSize = find_if(head, min(tail, head + limit - charsRead), id9) - head;
      arg = copy_n(head, chunkSize, arg);
      head += chunkSize;
      charsRead += chunkSize;
      if (chunkSize == 0 || head < tail) break;
    }
    return *arg = '\0', charsRead;
  }

  inline int readString(char* arg, int limit, const char* terminators, bool skip) {
    if (!*terminators) return readString(arg, limit, InputDevice::isSpace, skip);
    return readString(arg, limit, [terminators](char c) { return InputDevice::isOneOf(c, terminators); }, skip);
  }

  

  inline bool read(Detail::Base newBase) { base = newBase.value; return true; }
  

  inline bool read() { return true; }
  inline bool read(char& arg) { return readChar(arg); }
  template <class I> inline typename enable_if<is_integral<I>::value && is_unsigned<I>::value,
  bool>::type read(I& arg) { return id6(arg, skipCharacters()) > 0; }
  template <class I> inline typename enable_if<is_integral<I>::value && is_signed<I>::value,
  bool>::type read(I& arg) { return id15(arg, skipCharacters()); }
  template <class F> inline typename enable_if<is_floating_point<F>::value,
  bool>::type read(F& arg) { return id5(arg, skipCharacters()); }
  

  inline bool read(const char& arg) { skipCharacters([arg](char c) { return arg != c; }); return true; }
  inline bool read(const char* arg) {
    if (*arg) skipCharacters([arg](char c) { return InputDevice::isOneOf(c, arg); });
    else skipCharacters();
    return putBack(), true;
  }
  inline bool read(bool (*isSkipped)(char)) { skipCharacters(isSkipped); putBack(); return true; }
  

  template <class I, class Terminator, class... Ts> inline typename enable_if<is_integral<I>::value,
  bool>::type read(char* arg, I limit, Terminator terminator, Ts&&... args) {
    readString(arg, static_cast<int>(limit), terminator, true);
    return read(forward<Ts>(args)...);
  }
  template <class I> inline typename enable_if<is_integral<I>::value,
  bool>::type read(char* arg, I limit) { return read(arg, limit, ""); }
  template <class... Ts>
  inline bool read(char* first, char* last, Ts&&... args) {
    return read(first, static_cast<int>(last - first), forward<Ts>(args)...);
  }
  template <int N, class... Ts>
  inline bool read(char (&arg)[N], Ts&&... args) { return read(static_cast<char*>(arg), N, forward<Ts>(args)...); }
  template <class Terminator, class... Ts>
  inline bool read(string& arg, Terminator terminator, Ts&&... args) {
    for (int length = max(16, static_cast<int>(arg.capacity())), last = 0;; length = last += length) {
      arg.resize(last + length);
      int charsRead = readString(&arg[last], length + 1, terminator, last == 0);
      if (charsRead < length) {
        arg.resize(last + charsRead);
        return read(forward<Ts>(args)...);
      }
    }
  }
  inline bool read(string& arg) { return read(arg, ""); }
  

  template <class T1, class T2>
  inline bool read(pair<T1, T2>& arg) { return read(arg.first, arg.second); }
  template <class T>
  inline bool read(complex<T>& arg) {
    T real, imag;
    if (!read(real, imag)) return false;
    arg.real(real), arg.imag(imag);
    return true;
  }
  template <class T>
  inline bool read(vector<T>& arg) {
    uint n;
    if (!read(n)) return false;
    arg.resize(n);
    return read(arg.begin(), arg.end());
  }
  template <class Iterator, class... Ts> inline typename enable_if<is_iterator<Iterator>::value,
  bool>::type read(Iterator first, Iterator last, Ts&&... args) {
    for (; first != last; ++first) if (!read(*first)) return false;
    return read(forward<Ts>(args)...);
  }
  template <class Iterator, class I, class... Ts>
  inline typename enable_if<is_iterator<Iterator>::value && is_integral<I>::value,
  bool>::type read(Iterator first, I count, Ts&&... args) { return read(first, first + count, forward<Ts>(args)...); }
  

  template <class T>
  inline auto read(T& arg) -> decltype(arg.read(*this)) { return arg.read(*this); }
  template <class T0, class T1, class... Ts>
  inline typename enable_if<!is_iterator<T0>::value && !is_convertible<T0, char*>::value,
  bool>::type read(T0&& arg0, T1&& arg1, Ts&&... args) {
    return read(forward<T0>(arg0)) && read(forward<T1>(arg1), forward<Ts>(args)...);
  }
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

  OutputDevice() : output(buffer), end(buffer + BUFFER_SIZE + MAX_LENGTH), separate(false)
  , width(setWidth().value), fill(setFill().value), base(setBase().value), precision(setPrecision().value)
  , delimiter(setDelimiter().value) { computeBasePower(); }

  virtual void writeToDevice(uint count) = 0;

  inline void flushMaybe() {
    if (__builtin_expect(output >= buffer + BUFFER_SIZE, false)) {
      writeToDevice(BUFFER_SIZE);
      output = copy(buffer + BUFFER_SIZE, output, buffer);
    }
  }

  void computeBasePower() {
    basePower = 1;
    for (uint i = 0; i < precision; ++i) basePower *= base;
  }

  template <class I> inline char* id8(I arg, char* last) {
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
      last = id8(~unsignedArg + 1, last);
      *--last = '-';
      return last;
    }
    return id8(unsignedArg, last);
  }

  template <class F> char* id7(F arg, char* last) {
    bool negative = signbit(arg);
    if (negative) arg = -arg;
    if (isnan(arg)) for (int i = 0; i < 3; ++i) *--last = i["NaN"];
    else if (isinf(arg)) for (int i = 0; i < 3; ++i) *--last = i["fnI"];
    else {
      auto integerPart = static_cast<unsigned long long>(arg);
      auto id13 = static_cast<unsigned long long>((arg - integerPart) * basePower + F(0.5));
      if (id13 >= basePower) ++integerPart, id13 = 0;
      char* point = last - precision;
      if (precision > 0) {
        ::fill(point, id8(id13, last), '0');
        *--point = '.';
      }
      last = id8(integerPart, point);
    }
    if (negative) *--last = '-';
    return last;
  }

  inline int writeT(char* first) {
    int delimiterLength = separate ? writeDelimiter() : 0;
    separate = true;
    uint charsWritten = static_cast<uint>(end - first);
    if (__builtin_expect(charsWritten < width, false))
      charsWritten += writeFill(width - charsWritten);
    output = copy(first, end, output);
    flushMaybe();
    return delimiterLength + static_cast<int>(charsWritten);
  }

  inline int writeFill(uint count) {
    int charsWritten = static_cast<int>(count);
    if (__builtin_expect(output + count + MAX_LENGTH < end, true)) {
      if (count == 1) *output++ = fill;
      else output = fill_n(output, count, fill);
    } else for (uint chunkSize = static_cast<uint>(buffer + BUFFER_SIZE - output);; chunkSize = BUFFER_SIZE) {
      if (chunkSize > count) chunkSize = count;
      output = fill_n(output, chunkSize, fill);
      flushMaybe();
      if ((count -= chunkSize) == 0) break;
    }
    return charsWritten;
  }

public:
  uint width;
  char fill;
  uint base;
  uint precision;
  unsigned long long basePower;
  string delimiter;

  OutputDevice(OutputDevice const&) = delete;
  OutputDevice& operator = (OutputDevice const&) = delete;
  virtual ~OutputDevice() {};

  inline int writeChar(char arg) { separate = false; *output++ = arg; flushMaybe(); return 1; }

  inline int writeString(const char* arg, size_t length, bool checkWidth = true) {
    separate = false;
    uint count = static_cast<uint>(length);
    int charsWritten = static_cast<int>(count) + (checkWidth && count < width ? writeFill(width - count) : 0);
    if (__builtin_expect(output + count + MAX_LENGTH < end, true)) {
      if (count == 1) *output++ = *arg;
      else output = copy_n(arg, count, output);
    } else for (uint chunkSize = static_cast<uint>(buffer + BUFFER_SIZE - output);; chunkSize = BUFFER_SIZE) {
      if (chunkSize > count) chunkSize = count;
      output = copy_n(arg, chunkSize, output);
      flushMaybe();
      if ((count -= chunkSize) == 0) break;
      arg += chunkSize;
    }
    return charsWritten;
  }

  inline int writeDelimiter() { return writeString(delimiter.c_str(), delimiter.size(), false); }

  inline void flush() {
    writeToDevice(static_cast<uint>(output - buffer));
    output = buffer;
  }

  

  inline int write(Detail::Width newWidth) { width = newWidth.value; return 0; }
  inline int write(Detail::Fill newFill) { fill = newFill.value; return 0; }
  inline int write(Detail::Base newBase) { base = newBase.value; computeBasePower(); return 0; }
  inline int write(Detail::Precision newPrecision) {
    precision = newPrecision.value; computeBasePower(); return 0;
  }
  inline int write(Detail::Delimiter newDelimiter) { delimiter = newDelimiter.value; return 0; }
  

  inline int write() { return 0; }
  inline int write(char arg) { return writeChar(arg); }
  template <class I> inline typename enable_if<is_integral<I>::value && is_unsigned<I>::value,
  int>::type write(I arg) { return writeT(id8(arg, end)); }
  template <class I> inline typename enable_if<is_integral<I>::value && is_signed<I>::value,
  int>::type write(I arg) { return writeT(id0(arg, end)); }
  template <class F> inline typename enable_if<is_floating_point<F>::value,
  int>::type write(F arg) { return writeT(id7(arg, end)); }
  

  inline int write(const char* arg) { return writeString(arg, strlen(arg)); }
  template <int N>
  inline int write(char (&arg)[N]) { return writeString(arg, strlen(arg)); }
  inline int write(const string& arg) { return writeString(arg.c_str(), arg.size()); }
  template <class T1, class T2>
  inline int write(const pair<T1, T2>& arg) {
    int charsWritten = write(arg.first);
    charsWritten += writeDelimiter();
    return charsWritten + write(arg.second);
  }
  template <class T>
  inline int write(const complex<T>& arg) { return write(real(arg), imag(arg)); }
  

  template <class Iterator, class... Ts> inline typename enable_if<is_iterator<Iterator>::value,
  int>::type write(Iterator first, Iterator last, Ts&&... args) {
    int charsWritten = 0;
    for (; first != last; charsWritten += ++first == last ? 0 : writeDelimiter()) charsWritten += write(*first);
    return charsWritten + write(forward<Ts>(args)...);
  }
  template <class Iterator, class I, class... Ts>
  inline typename enable_if<is_iterator<Iterator>::value && is_integral<I>::value,
  int>::type write(Iterator first, I count, Ts&&... args) { return write(first, first + count, forward<Ts>(args)...); }
  

  template <class T>
  inline auto write(const T& arg) -> decltype(arg.write(*this)) { return arg.write(*this); }
  template <class T0, class T1, class... Ts> inline typename enable_if<!is_iterator<T0>::value,
  int>::type write(T0&& arg0, T1&& arg1, Ts&&... args) {
    int charsWritten = write(forward<T0>(arg0));
    return charsWritten + write(forward<T1>(arg1), forward<Ts>(args)...);
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

template <class... Ts> inline bool read(Ts&&... args) { return input->read(forward<Ts>(args)...); }
template <class... Ts> inline int write(Ts&&... args) { return output->write(forward<Ts>(args)...); }
template <class... Ts> inline int writeln(Ts&&... args) { return write(forward<Ts>(args)..., '\n'); }
void flush() { output->flush(); }



template <class T> struct Shift {
  static inline T f(const T& x, int offset) { return x; }
};
template <class T> struct Combine {
  static inline T f(const T& lhs, const T& rhs, int lhSize, int rhSize) {
    return lhs + (rhs << lhSize);
  }
};
template <class T> struct Reverse {
  static inline void f(T& dst, int size) {};
};
template <class T, class M> struct Modify {
  static inline void f(T& dst, const M& src, int factor) { dst += src; }
};
template <class R, class T> struct Query {
  static inline R f(T& x) { return static_cast<R>(x); }
};

template <class T>
inline T operator << (const T& x, int offset) { return Shift<T>::f(x, offset); }
template <class T>
inline T combine(const T& lhs, const T& rhs, int lhSize, int rhSize) {
  return Combine<T>::f(lhs, rhs, lhSize, rhSize);
}
template <class T>
inline void reverse(T& dst, int size) { Reverse<T>::f(dst, size); }
template <class T, class M>
inline void modify(T& dst, const M& src, int factor) {
  Modify<T, M>::f(dst, src, factor);
}
template <class R, class T>
inline R query(T& x) { return Query<R, T>::f(x); }


template <class T> struct Name; \
namespace std { \
template <class T> struct numeric_limits<Name<T>> { \
constexpr static T max() { return maxValue; } \
}; \
} \
template <class T> struct Name { \
T value; \
constexpr inline Name(const T& value = defaultValue) : value(value) {} \
explicit inline operator T() const { return value; } \
explicit inline operator bool() const { return value != defaultValue; } \
inline bool read(InputDevice& input) { return input.read(value); } \
inline int write(OutputDevice& output) const { return output.write(value); } \
friend inline bool operator == (const Name& lhs, const Name& rhs) { \
return lhs.value == rhs.value; } \
friend inline bool operator != (const Name& lhs, const Name& rhs) { \
return lhs.value != rhs.value; }

WRAPPER(Sum, 0, numeric_limits<T>::max() / 2)
friend inline bool operator < (const Sum& lhs, const Sum& rhs) {
  return lhs.value < rhs.value; }
inline void operator += (const Sum& other) { value += other.value; }
inline void operator -= (const Sum& other) { value -= other.value; }
friend inline Sum operator + (const Sum& lhs, const Sum& rhs) {
  return lhs.value + rhs.value; }
friend inline Sum operator - (const Sum& lhs, const Sum& rhs) {
  return lhs.value - rhs.value; }
};

WRAPPER(Max, -numeric_limits<T>::max(), numeric_limits<T>::max())
friend inline bool operator < (const Max& lhs, const Max& rhs) {
  return lhs.value < rhs.value; }
inline void operator += (const Max& other) { smax(value, other.value); }
inline void operator += (const Sum<T>& other) { value += other.value; }
friend inline Max operator + (const Max& lhs, const Max& rhs) {
  return max(lhs.value, rhs.value); }
};



template <class T, class M>
class id10 {

  template <class U, class P> constexpr static auto id2(int)
  -> decltype(U().cascade(true, P()), bool()) { return true; }
  template <class, class>
  constexpr static bool id2(long) { return false; }

  constexpr static const bool CASCADE_M = id2<T, M>(0);
  constexpr static const bool COMMUTATIVE = is_commutative<M>::value;

  int n;       

  int height;  

  int width;   

  vector<T> data;
  vector<M> delta;

  inline int check(int i) const {
    ASSERT(0 <= i && i < n);
    return i + (1 << height);
  }

  template <bool id12> inline void check(int& l, int& r) const {
    ASSERT(0 <= l && l < r && r <= n);
    if (id12) l += 1 << height, r += (1 << height) - 1;
  }

  inline int child(int i, int right) const { return i << 1 | right; }
  

  

  


  template <class P, class U = T> typename enable_if<id2<U, P>(0),
  void>::type inline id4(int i, int right, int lhSize, P& param) {
    data[i].cascade(right, param);
  }
  void inline id4(int i, int right, long lhSize, M& value) {
    if (right) value = value << static_cast<int>(lhSize);
  }
  template <class P>
  void inline id4(int i, int right, long, P&& param) {}

  template <class P, class U = T>
  typename enable_if<id2<U, P>(0) || is_same<P, M>::value, P>::type
  inline cascade(int i, int right, int lhSize, P param) {
    id4(i, right, lhSize, param);
    return param;
  }
  template <class P>
  inline auto cascade(int i, int right, long lhSize, P&& param) ->
  decltype(forward<P>(param)) { return forward<P>(param); }

  inline void leaveNode(int& i, int right, int lhSize) {
    i = child(i, right);
  }
  template <class P, class... Ps>
  inline void leaveNode(int& i, int right, int lhSize, P&& p, Ps&&... params) {
    id4(i, right, lhSize, p);
    leaveNode(i, right, lhSize, forward<Ps>(params)...);
  }

  inline void compute(int i) {
    data[i] = combine(data[child(i, 0)], data[child(i, 1)], width, width);
    if (COMMUTATIVE && !CASCADE_M) ::modify(data[i], delta[i], width << 1);
  }

  

  inline void computePath(int i, int i0) {
    for (; i != i0; compute(i >>= 1), width <<= 1);
  }

  inline void apply(int i, const M& value) {
    ::modify(data[i], value, width);
    if (i < static_cast<int>(delta.size())) delta[i] += value;
  }

  

  inline void pushNode(int i) {
    apply(child(i, 0), cascade(i, 0, width, delta[i]));
    apply(child(i, 1), cascade(i, 1, width, delta[i]));
    delta[i] = M();
  }

  void modifyPoint(int i, const M& value) {  

    for (i = check(i); i; i >>= 1) ::modify(data[i], value, 1);
  }

  void modifyPoint(int i, const T& value) {  

    for (::modify(data[i = check(i)], value, 1); i >>= 1; compute(i));
  }

  void modifyRight(int i, int h, int r, M value) {
    int i0 = i;
    for (; !((r + 1) >> h--); r &= ~(1 << h)) {
      width >>= 1, pushNode(i);
      if (r >> h) apply(child(i, 0), cascade(i, 0, width, value));
      leaveNode(i, r >> h, width, value);
    }
    apply(i, value);
    computePath(i, i0);
  }

  template <int id14, class Compare, class... Ps>
  int binarySearch(Compare compare, Ps&&... params) {
    int i = 1;
    if (!compare(data[i], forward<Ps>(params)...)) return -1;
    for (width = height == 0 ? 0 : 1 << (height - 1); width; width >>= 1) {
      pushNode(i);
      leaveNode(i, compare(data[child(i, id14)], forward<Ps>(params)...)
                == id14, width, forward<Ps>(params)...);
    }
    return i - (1 << height);
  }

public:
  using DataType = T;
  using ModificationType = M;

  id10(int size = 0) { init(size); }

  void init(int size) {
    n = size;
    height = n == 0 ? 0 : sizeof(n) * 8 - __builtin_clz(n - 1);
    int nodeCount = (1 << height) + n + (n & 1);
    data.assign(nodeCount, T());
    delta.assign((nodeCount + (nodeCount & 2)) / 2, M());
  }

  void clear() {
    data = {};
    delta = {};
  }

  int size() const { return n; }

  T& operator [] (int i) { return data[check(i)]; }
  const T& operator [] (int i) const { return data[check(i)]; }

  void build(int l, int r) {
    check<true>(l, r);
    for (width = 1; r >>= 1, l >>= 1; width <<= 1)
      for (int i = r; i >= l; --i) compute(i);
  }
  void build() { build(0, n); }

  template <bool RANGE = true>
  void push(int l, int r) {
    check<true>(l, r);
    int h = height;
    for (width = 1 << (h - 1); h; --h, width >>= 1) {
      if (RANGE) {
        for (int i = l >> h; i <= r >> h; ++i) pushNode(i);
      } else {
        pushNode(l >> h);
        if ((l ^ r) >> h) pushNode(r >> h);
      }
    }
  }
  void push() { push<true>(0, n); }

  void modify(int l, int r, M value) {
    check<false>(l, r);
    int i = 1, i0 = i, h = height;  

    for (--r, width = 1 << h; h --> 0 && !((l ^ r) >> h);) {
      width >>= 1, pushNode(i);
      leaveNode(i, l >> h, 0, value);
      if (l >> h) l ^= 1 << h, r ^= 1 << h;
    }
    if (r - l + 1 == width) apply(i, value);
    else {
      width >>= 1, pushNode(i);
      modifyRight(child(i, 1), h, r ^ 1 << h, cascade(i, 1, (1 << h) - l, value));
      leaveNode(i, 0, 0, value);
      for (; --h, l; l &= ~(1 << h)) {
        width >>= 1, pushNode(i);
        if (!(l >> h)) apply(child(i, 1), cascade(i, 1, (i << h) - l, value));
        leaveNode(i, l >> h, 0, value);
      }
      apply(i, value);
    }
    computePath(i, i0);
  }






  template <class Compare, class... Ps>
  int lowerBound(Compare compare, Ps&&... params) {
    return binarySearch<0>(compare, forward<Ps>(params)...);
  }

  template <class Compare, class... Ps>
  int upperBound(Compare compare, Ps&&... params) {
    return binarySearch<1>(compare, forward<Ps>(params)...);
  }
};

int main() {

  input.reset(new InputFile("input.txt"));
  

  output.reset(new OutputFile());
  


  input.reset(new InputFile(stdin, false));
  

  output.reset(new OutputFile());


  int n;
  read(n);
  vector<int> p(n), t(n), x(n), u(n);
  REP(i, n) {
    read(p[i], t[i]);
    if (t[i] == 1) read(x[i]);
    u[p[i] - 1] = i;
  }
  id10<Max<int>, Sum<int>> tree(n);
  REP(i, n) tree[i] = 0;
  tree.build();
  REP(i, n) {
    tree.modify(0, p[i], t[i] == 1 ? 1 : -1);
    int j = tree.upperBound([](Max<int> m) { return m.value >= 1; });
    writeln(j == -1 ? j : x[u[j]]);
  }


  flush();
  cerr << endl << endl << static_cast<double>(clock()) / CLOCKS_PER_SEC << endl;

  return 0;
}
