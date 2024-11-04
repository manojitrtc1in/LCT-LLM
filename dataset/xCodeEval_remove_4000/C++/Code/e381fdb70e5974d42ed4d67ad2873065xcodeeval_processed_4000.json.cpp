



























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
  InputDevice(InputDevice const&) = delete;
  InputDevice& operator = (InputDevice const&) = delete;

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

  template <class I> inline bool id12(I& arg, char c) {
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
      unsigned long long id11 = 0;
      int id10 = id6(id11, nextChar());
      if (id10 > 0) {
        unsigned long long basePower = 1;
        for (; id10; --id10) basePower *= base;
        arg += static_cast<F>(id11) / basePower;
      }
    } else --head;
    if (negative) arg = -arg;
    return true;
  }

public:
  static inline bool isSpace(char c) { return static_cast<unsigned char>(c - '\t') < 5 || c == ' '; }
  static inline bool isDigit(char c) { return static_cast<unsigned char>(c - '0') < 10; }
  static inline bool isUpper(char c) { return static_cast<unsigned char>(c - 'A') < 26; }
  static inline bool isLower(char c) { return static_cast<unsigned char>(c - 'a') < 26; }
  static inline bool isOneOf(char c, const char* str) { return strchr(str, c) != nullptr; }

  uint base;
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
  inline bool readString(char* arg, int limit, UnaryPredicate id9) {
    skipCharacters(id9);
    

    for (--head, --limit; head < tail; fillInput()) {
      ptrdiff_t chunkSize = find_if(head, min(tail, head + limit), id9) - head;
      arg = copy_n(head, chunkSize, arg);
      head += chunkSize;
      limit -= chunkSize;
      if (chunkSize == 0 || head < tail) break;
    }
    return *arg = '\0', true;
  }

  template <class I> inline bool id6(I& arg) { return id6(arg, skipCharacters()) > 0; }
  template <class I> inline bool id12(I& arg) { return id12(arg, skipCharacters()); }
  template <class F> inline bool id5(F& arg) { return id5(arg, skipCharacters()); }
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
  OutputDevice(OutputDevice const&) = delete;
  OutputDevice& operator = (OutputDevice const&) = delete;

  virtual void writeToDevice(uint count) = 0;

  inline void flushMaybe() {
    if (__builtin_expect(output >= buffer + BUFFER_SIZE, false)) {
      writeToDevice(BUFFER_SIZE);
      output = copy(buffer + BUFFER_SIZE, output, buffer);
    }
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
      auto id11 = static_cast<unsigned long long>((arg - integerPart) * basePower + F(0.5));
      if (id11 >= basePower) ++integerPart, id11 = 0;
      char* point = last - precision;
      if (precision > 0) {
        ::fill(point, id8(id11, last), '0');
        *--point = '.';
      }
      last = id8(integerPart, point);
    }
    if (negative) *--last = '-';
    return last;
  }

  inline int writeT(char* first) {
    int id4 = separate ? writeDelimiter() : 0;
    separate = true;
    int charsWritten = static_cast<int>(end - first);
    if (__builtin_expect(charsWritten < width, false))
      charsWritten += writeFill(width - charsWritten);
    output = copy(first, end, output);
    flushMaybe();
    return id4 + charsWritten;
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

  template <class I> inline int id8(I arg) { return writeT(id8(arg, end)); }
  template <class I> inline int id0(I arg) { return writeT(id0(arg, end)); }
  template <class F> inline int id7(F arg) { return writeT(id7(arg, end)); }

  inline void flush() {
    writeToDevice(static_cast<uint>(output - buffer));
    output = buffer;
  }
  virtual ~OutputDevice() {};
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
int>::type read(I& arg) { return input->id6(arg); }
template <class I> inline typename enable_if<is_integral<I>::value && is_signed<I>::value,
int>::type read(I& arg) { return input->id12(arg); }
template <class F> inline typename enable_if<is_floating_point<F>::value,
int>::type read(F& arg) { return input->id5(arg); }


inline int read(const char& arg) { input->skipCharacters([arg](char c) { return arg != c; }); return 0; }
inline int read(const char* arg) {
  if (*arg) input->skipCharacters([arg](char c) { return InputDevice::isOneOf(c, arg); });
  else input->skipCharacters();
  input->putBack(); return 0;
}
inline int read(bool (*isSkipped)(char)) { input->skipCharacters(isSkipped); input->putBack(); return 0; }


template <class... Ts> int read(char* arg, int limit, bool (*id9)(char), Ts&&... args);
template <class... Ts> int read(char* arg, int limit, const char* terminators, Ts&&... args);
template <class Iterator, class... Ts, typename = decltype(*std::declval<Iterator>())>
int read(Iterator first, Iterator last, Ts&&... args);
template <class Iterator, class... Ts, typename = decltype(*std::declval<Iterator>())>
int read(Iterator first, int count, Ts&&... args);
template <class T, class... Ts, typename = typename enable_if<!is_convertible<T, char*>::value, void>::type>
int read(T&& arg1, Ts&&... args);


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
inline int read(char* arg, int limit, bool (*id9)(char), Ts&&... args) {
  int argsRead = input->readString(arg, limit, id9);
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
template <class T, class... Ts, typename>
inline int read(T&& arg1, Ts&&... args) {
  int argsRead = read(forward<T>(arg1));
  return argsRead + read(forward<Ts>(args)...);
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
int>::type write(I arg) { return output->id8(arg); }
template <class I> inline typename enable_if<is_integral<I>::value && is_signed<I>::value,
int>::type write(I arg) { return output->id0(arg); }
template <class F> inline typename enable_if<is_floating_point<F>::value,
int>::type write(F arg) { return output->id7(arg); }


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

template <class F>
struct Point {
  F x, y;
  Point() : x(0), y(0) {}
  Point(const F& x, const F& y) : x(x), y(y) {}

  void swap(Point& other) { using std::swap; swap(x, other.x); swap(y, other.y); }
  template <class F1> explicit operator Point<F1> () const {
    return Point<F1>(static_cast<F1>(x), static_cast<F1>(y)); }
  template <class F1> Point& operator = (const Point<F1>& other) {
    x = other.x; y = other.y; return *this; }
  template <class F1> Point& operator += (const Point<F1>& other) {
    x += other.x; y += other.y; return *this; }
  template <class F1> Point& operator -= (const Point<F1>& other) {
    x -= other.x; y -= other.y; return *this; }
  template <class F1> Point& operator *= (const F1& factor) {
    x *= factor; y *= factor; return *this; }
  template <class F1> Point& operator /= (const F1& factor) {
    x /= factor; y /= factor; return *this; }
};

template <class F> int read(Point<F>& point) { return read(point.x, point.y) / 2; }
template <class F> int write(const Point<F>& point) { return write(point.x, point.y); }

template <class F> istream& operator >> (istream& is, Point<F>& point) {
  return is >> point.x >> point.y; }
template <class F> ostream& operator << (ostream& os, const Point<F>& point) {
  return os << point.x << ' ' << point.y; }

template <class F> inline Point<F> makePoint(const F& x, const F& y) { return Point<F>(x, y); }
template <class F> void swap(Point<F>& lhs, Point<F>& rhs) { lhs.swap(rhs); }


template <class F> inline auto name(const arg) -> decltype(expr) { return expr; }

template <class F1, class F2> \
inline auto name(const arg1, const arg2) -> decltype(expr) { return expr; }

template <class F1, class F2, class F3> \
inline auto name(const arg1, const arg2, const arg3) -> decltype(expr) { return expr; }

FUNC1(operator -, Point<F>& point, makePoint(-point.x, -point.y))
FUNC2(operator +, Point<F1>& lhs, Point<F2>& rhs, makePoint(lhs.x + rhs.x, lhs.y + rhs.y))
FUNC2(operator -, Point<F1>& lhs, Point<F2>& rhs, makePoint(lhs.x - rhs.x, lhs.y - rhs.y))
FUNC2(operator *, F1& factor, Point<F2>& rhs, makePoint(factor * rhs.x, factor * rhs.y))
FUNC2(operator *, Point<F1>& lhs, F2& factor, makePoint(lhs.x * factor, lhs.y * factor))
FUNC2(operator /, Point<F1>& lhs, F2& factor, makePoint(lhs.x / factor, lhs.y / factor))

FUNC2(operator *, Point<F1>& lhs, Point<F2>& rhs, lhs.x * rhs.x + lhs.y * rhs.y)
FUNC2(operator ^, Point<F1>& lhs, Point<F2>& rhs, lhs.x * rhs.y - lhs.y * rhs.x)



FUNC2(ccw, Point<F1>& lhs, Point<F2>& rhs, rhs ^ lhs)
FUNC3(ccw, Point<F1>& lhs, Point<F2>& rhs, Point<F3>& origin, ccw(lhs - origin, rhs - origin))

FUNC2(operator ==, Point<F1>& lhs, Point<F2>& rhs, lhs.x == rhs.x && lhs.y == rhs.y)
FUNC2(operator !=, Point<F1>& lhs, Point<F2>& rhs, !(lhs == rhs))


FUNC2(operator v, Point<F1>& lhs, Point<F2>& rhs, \
lhs.y v rhs.y || (lhs.y == rhs.y && lhs.x v rhs.x))
COMPARE(<) COMPARE(>) COMPARE(<=) COMPARE(>=)




FUNC1(angle, Point<F>& point, atan2(point.y, point.x))
FUNC2(angle, Point<F1>& lhs, Point<F2>& rhs, atan2(lhs ^ rhs, lhs * rhs))
FUNC3(angle, Point<F1>& lhs, Point<F2>& rhs, Point<F3>& origin,
      angle(lhs - origin, rhs - origin))
FUNC3(rotate, Point<F1>& point, F2& angleSin, F3& angleCos,
      makePoint(angleCos * point.x - angleSin * point.y,
                angleSin * point.x + angleCos * point.y))
FUNC2(rotate, Point<F1>& point, F2& angle, rotate(point, sin(angle), cos(angle)))
FUNC3(rotate, Point<F1>& point, F2& angle, Point<F3>& origin,
      origin + rotate(point - origin, angle))
FUNC1(perp, Point<F>& point, makePoint(-point.y, point.x))



FUNC1(abs, Point<F>& point, point * point)
FUNC1(norm, Point<F>& point, sqrt(abs(point)))
FUNC2(dist, Point<F1>& lhs, Point<F2>& rhs, norm(lhs - rhs))
FUNC2(dist2, Point<F1>& lhs, Point<F2>& rhs, abs(lhs - rhs))
FUNC2(bisector, Point<F1>& lhs, Point<F2>& rhs, lhs * norm(rhs) + rhs * norm(lhs))





template <class F1, class F2> using distF = decltype(sqrt(F1() + F2()));

template <class F>
struct Line {
  Point<F> a, ab;
  Line() : a(), ab() {}
  Line(const Point<F>& a, const Point<F>& b, bool twoPoints = true)
  : a(a), ab(twoPoints ? b - a : b) {}
  Line(const F& xa, const F& ya, const F& xb, const F& yb)
  : a(xa, ya), ab(xb - xa, yb - ya) {}

  void swap(Line& other) { using std::swap; swap(a, other.a); swap(ab, other.ab); }
  template <class F1> explicit operator Line<F1> () const {
    return Line<F1>(Point<F1>(a), Point<F1>(ab), false); }
  template <class F1> Line& operator = (const Line<F1>& other) {
    a = other.a; ab = other.ab; return *this; }

  Point<F> b() const { return a + ab; }
  operator bool () const { return ab != Point<F>(); }
};

template <class F> int read(Line<F>& line) {
  int res = read(line.a, line.ab) / 2;
  return line.ab -= line.a, res;
}

template <class F>
inline Line<F> makeLine(const Point<F>& a, const Point<F>& b, bool twoPoints = true) {
  return Line<F>(a, b, twoPoints);
}

template <class F> void swap(Line<F>& lhs, Line<F>& rhs) { lhs.swap(rhs); }

template <class F> using Polygon = vector<Point<F>>;
inline int prev(int i, int n) { return i == 0 ? n-1 : i-1; }
inline int next(int i, int n) { return i == n-1 ? 0 : i+1; }

template <class F> bool orientation(const Polygon<F>& poly) {
  int n = static_cast<int>(poly.size());
  int i = static_cast<int>(min_element(begin(poly), end(poly)) - begin(poly));
  return ccw(poly[prev(i, n)], poly[next(i, n)], poly[i]) > 0;
}

template <class F1, class F2>
distF<F1, F2> id1(const Line<F1>& line, const Polygon<F2>& poly) {
  using F = distF<F1, F2>;
  F res = F();
  int n = static_cast<int>(poly.size());
  auto id3 = [&line, &poly](int i) { return sgn(line.ab ^ (poly[i] - line.a)); };
  int sprev = id3(n - 1), si = id3(0), snext;
  for (int i = 0; i < n; ++i, sprev = si, si = snext) {
    snext = id3(next(i, n));
    if (si == 0) {
      F t = static_cast<F>((poly[i] - line.a) * line.ab) / abs(line.ab);
      if (sprev == 0) {
        if (snext != 0 && snext == sgn((poly[i] - poly[prev(i, n)]) * line.ab))
          res += snext * t;
      } else {
        if ((snext != 0 && snext != sprev) ||
            (snext == 0 && sprev == sgn((poly[next(i, n)] - poly[i]) * line.ab)))
          res -= sprev * t;
      }
    } else if (snext == -si) {
      auto vect = poly[next(i, n)] - poly[i];
      res += snext * static_cast<F>((poly[i] - line.a) ^ vect) / (line.ab ^ vect);
    }
  }
  return res * norm(line.ab);
}

inline int read(Point<ll>& point) {
  double x, y;
  read(x, y);
  point.x = static_cast<ll>(x * 100 + sgn(x) * 0.5);
  point.y = static_cast<ll>(y * 100 + sgn(y) * 0.5);
  return 1;
}

int main() {

  input.reset(new InputFile("input.txt"));
  

  output.reset(new OutputFile());
  


  input.reset(new InputFile(stdin, false));
  

  output.reset(new OutputFile());


  int n, m;
  read(n, m);
  Polygon<ll> poly(n);
  read(all(poly));
  if (!orientation(poly)) reverse(poly.begin() + 1, poly.end());
  REP(i, m) {
    Line<ll> line;
    read(line);
    writeln(id1(line, poly) / 100);
  }


  flush();
  cerr << endl << endl << static_cast<double>(clock()) / CLOCKS_PER_SEC << endl;

  return 0;
}
