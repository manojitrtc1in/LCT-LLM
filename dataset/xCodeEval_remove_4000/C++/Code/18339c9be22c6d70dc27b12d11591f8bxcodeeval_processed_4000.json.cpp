



































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
  constexpr static auto id4(int) -> decltype(*declval<U>(), bool()) { return true; }
  template <class> constexpr static bool id4(long) { return false; }
  constexpr static bool value = id4<T>(0);
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

  template <class I> int id2(I& arg, char c) {
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
    if (__builtin_expect(base > 10, false)) return id2(arg, c);
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
  inline int readString(char* arg, int limit, UnaryPredicate id10, bool skip) {
    int charsRead = 0;
    if (skip) skipCharacters(id10), --head;
    

    for (--limit; head < tail; fillInput()) {
      ptrdiff_t chunkSize = find_if(head, min(tail, head + limit - charsRead), id10) - head;
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
  static inline void f(T& dst, const T& lhs, const T& rhs, int lhSize) {
    dst = lhs + (rhs << lhSize);
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
inline void combine(T& dst, const T& lhs, const T& rhs, int lhSize) {
  Combine<T>::f(dst, lhs, rhs, lhSize);
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



template <class T, class M, bool id1>
class id9 {
protected:
  constexpr static const bool COMMUTATIVE = is_commutative<M>::value;

  template <class U, class P> constexpr static auto id3(int)
  -> decltype(U().cascade(true, P()), bool()) { return true; }
  template <class, class>
  constexpr static bool id3(long) { return false; }

  struct Node {
    int left, right;
    T data;
    M delta;
  };

  inline int check(int i) const { ASSERT(0 <= i && i < n); return i; }

  inline void check(int l, int r) const { ASSERT(0 <= l && l < r && r <= n); }

  T& data(int i) { return i < 0 ? leaves[-i - 1] : inner[i].data; }

  int construct(int&& iGlobal, int nodeL, int nodeR) {
    if (nodeL + 1 == nodeR) return -nodeR;
    int i = iGlobal++;
    int nodeM = (nodeL + nodeR) / 2;
    inner[i].left  = construct(move(iGlobal), nodeL, nodeM);
    inner[i].right = construct(move(iGlobal), nodeM, nodeR);
    return i;
  }

  void build(int i, int nodeL, int nodeR, int l, int r) {
    if (i < 0 || l >= r) return;
    Node& node = inner[i];
    int nodeM = (nodeL + nodeR) / 2;
    build(node.left,  nodeL, nodeM, l, min(r, nodeM));
    build(node.right, nodeM, nodeR, max(l, nodeM), r);
    combine(node.data, data(node.left), data(node.right), nodeM - nodeL);
  }

  template <bool BRANCH>
  void apply(int& i, int width, const M& value) {
    if (i < 0) {
      if (BRANCH) {
        leaves.emplace_back(leaves[-i - 1]);
        i = -static_cast<int>(leaves.size());
      }
      ::modify(leaves[-i - 1], value, 1);
    } else {
      if (BRANCH) {
        inner.emplace_back(inner[i]);
        i = static_cast<int>(inner.size()) - 1;
      }
      inner[i].delta += value;
      ::modify(inner[i].data, value, width);
    }
  }

  template <class U = T> typename enable_if<id3<U, M>(0),
  M>::type cascade(Node& node, bool left, const M& value) {
    return node.data.cascade(left, value);
  }
  template <class U = T> typename enable_if<!id3<U, M>(0),
  M>::type cascade(Node& node, bool left, const M& value) { return value; }

  void pushNode(Node& node, int widthL, int widthR) {
    apply<id1>(node.left,  widthL, cascade(node, true,  node.delta));
    apply<id1>(node.right, widthR, cascade(node, false, node.delta));
    node.delta = M();
  }

  int modify(int i, int nodeL, int nodeR, int l, int r, const M& value) {
    if (l >= r) return i;
    if (nodeL == l && nodeR == r) {
      apply<COMMUTATIVE && id1>(i, r - l, value);
    } else {
      Node& node = inner[i];
      int nodeM = (nodeL + nodeR) / 2;
      if (!COMMUTATIVE) pushNode(node, nodeM - nodeL, nodeR - nodeM);
      int left  = modify(node.left,  nodeL, nodeM, l, min(r, nodeM),
                         cascade(node, true,  value));
      int right = modify(node.right, nodeM, nodeR, max(l, nodeM), r,
                         cascade(node, false, value));
      if (COMMUTATIVE && id1) {
        i = static_cast<int>(inner.size());
        inner.emplace_back(Node{left, right, T(), node.delta});
      }
      combine(inner[i].data, data(left), data(right), nodeM - nodeL);
      if (COMMUTATIVE) ::modify(inner[i].data, inner[i].delta, nodeR - nodeL);
    }
    return i;
  }

  template <class... Ps, class U = T>
  auto find(int i, int, Ps&&... params)
  -> decltype(U().find(forward<Ps>(params)...)) {
    return data(i).find(forward<Ps>(params)...);
  }
  M find(int i, long, const M& value) { return value; }

  template <class... Ps>
  void callModify(int i, int l, int r, Ps&&... params) {
    check(l, r);
    if (!COMMUTATIVE && id1) apply<true>(i, 0, M());
    modify(i, 0, n, l, r, find(i, 0, forward<Ps>(params)...));
  }

  template <class R, class P, class U = T>
  typename enable_if<id3<U, P>(0),
  R>::type queryInner(Node& node, int nodeL, int nodeR, int l, int r,
                      bool left, const M& value, int, const P& param) {
    return query<R>(left ? node.left : node.right, nodeL, nodeR, l, r,
                    cascade(node, left, value), node.data.cascade(left, param));
  }
  template <class R, class... Ps>
  R queryInner(Node& node, int nodeL, int nodeR, int l, int r,
               bool left, const M& value, long, Ps&&... params) {
    return query<R>(left ? node.left : node.right, nodeL, nodeR, l, r,
                    cascade(node, left, value), forward<Ps>(params)...);
  }

  template <class R, class... Ps>
  R query(int i, int nodeL, int nodeR, int l, int r, M value, Ps&&... params) {
    R res{};
    if (l >= r) return res;
    if (nodeL == l && nodeR == r) {
      res = ::query<R>(data(i), forward<Ps>(params)...);
      if (id1) ::modify(res, value, r - l);
    } else {
      int nodeM = (nodeL + nodeR) / 2;
      if (id1) value = inner[i].delta + value;
      else pushNode(inner[i], nodeM - nodeL, nodeR - nodeM);
      combine(res, queryInner<R>(inner[i], nodeL, nodeM, l, min(r, nodeM),
                                 true, value, 0, forward<Ps>(params)...),
              queryInner<R>(inner[i], nodeM, nodeR, max(l, nodeM), r,
                            false, value, 0, forward<Ps>(params)...),
              nodeM - l);
    }
    return res;
  }

  template <class R, class... Ps, class U = T>
  auto callQuery(int i, int l, int r, int, Ps&&... params)
  -> decltype(U().find(forward<Ps>(params)...), R()) {
    check(l, r);
    return query<R>(i, 0, n, l, r, M(), data(i).find(forward<Ps>(params)...));
  }

  template <class R, class... Ps>
  R callQuery(int i, int l, int r, long, Ps&&... params) {
    check(l, r);
    return query<R>(i, 0, n, l, r, M(), forward<Ps>(params)...);
  }

  int n;
  vector<int> roots;
  vector<Node> inner;
  vector<T> leaves;

public:
  id9(int size = 0) { init(size); }

  void init(int size) {
    ASSERT(size >= 0);
    n = size;
    leaves.assign(n, T());
    if (n == 0) {
      inner.clear();
      roots.clear();
    } else {
      inner.assign(n - 1, Node());
      roots = {construct(0, 0, n)};
    }
  }

  void clear() {
    roots = {};
    inner = {};
    leaves = {};
  }

  int size() const { return n; }

  T& operator [] (int i) { return leaves[check(i)]; }
  const T& operator [] (int i) const { return leaves[check(i)]; }
};

template <class T, class M = T>
class id12 final : public id9<T, M, false> {
  using Base = id9<T, M, false>;

  void push(int i, int nodeL, int nodeR, int l, int r) {
    if (i < 0 || l >= r) return;
    int nodeM = (nodeL + nodeR) / 2;
    Base::pushNode(Base::inner[i], nodeM - nodeL, nodeR - nodeM);
    push(Base::inner[i].left,  nodeL, nodeM, l, min(r, nodeM));
    push(Base::inner[i].right, nodeM, nodeR, max(l, nodeM), r);
  }

  template <bool id14, class P, class Function>
  int binarySearch(int i, int nodeL, int nodeR, P param, Function f) {
    if (nodeL + 1 == nodeR) return nodeL;
    typename Base::Node& node = Base::inner[i];
    int nodeM = (nodeL + nodeR) / 2;
    Base::pushNode(node, nodeM - nodeL, nodeR - nodeM);
    return id14
    ?  f(param, Base::data(node.left))
    : !f(param, Base::data(node.right))
    ? binarySearch<id14>(node.left,  nodeL, nodeM, param, f)
    : binarySearch<id14>(node.right, nodeM, nodeR, param, f);
  }

public:
  using DataType = T;
  using ModificationType = M;

  id12(int size = 0) : Base(size) {}

  void build(int l, int r) {
    Base::check(l, r);
    Base::build(Base::roots[0], 0, Base::n, l, r);
  }
  void build() { build(0, Base::n); }

  void push(int l, int r) {
    Base::check(l, r);
    push(Base::roots[0], 0, Base::n, l, r);
  }
  void push() { push(0, Base::n); }

  template <class... Ps>
  void modify(int l, int r, Ps&&... params) {
    Base::callModify(Base::roots[0], l, r, forward<Ps>(params)...);
  }

  template <class R, class... Ps>
  R query(int l, int r, Ps&&... params) {
    return Base::template callQuery<R>(Base::roots[0], l, r, 0,
                                       forward<Ps>(params)...);
  }
  template <class... Ps> T query(int l, int r, Ps&&... params) {
    return query<T>(l, r, forward<Ps>(params)...);
  }

  template <class P, class Function>
  int lowerBound(P param, Function f) {
    if (!f(param, Base::data(Base::roots[0]))) return -1;
    return binarySearch<true>(Base::roots[0], 0, Base::n, param, f);
  }

  template <class P, class Function>
  int upperBound(P param, Function f) {
    if (!f(param, Base::data(Base::roots[0]))) return -1;
    return binarySearch<false>(Base::roots[0], 0, Base::n, param, f);
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
  id12<Max<int>, Sum<int>> tree(n);
  REP(i, n) tree[i] = 0;
  tree.build();
  REP(i, n) {
    tree.modify(0, p[i], t[i] == 1 ? 1 : -1);
    int j = tree.upperBound(true, [](bool, Max<int> m) { return m.value >= 1; });
    writeln(j == -1 ? j : x[u[j]]);
  }


  flush();
  cerr << endl << endl << static_cast<double>(clock()) / CLOCKS_PER_SEC << endl;

  return 0;
}
