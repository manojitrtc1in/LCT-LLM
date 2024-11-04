#ifdef AlCash
#define ASSERT(...) assert(__VA_ARGS__)
#else
#define ASSERT(...) true
#endif

#include <stdexcept>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <cassert>
#include <cstdarg>
#include <cstring>
#include <cstdio>
#include <memory>
#include <random>
#include <cmath>
#include <ctime>
#include <unordered_map>
#include <unordered_set>
#include <functional>
#include <algorithm>
#include <complex>
#include <numeric>
#include <limits>
#include <bitset>
#include <vector>
#include <string>
#include <queue>
#include <deque>
#include <array>
#include <list>
#include <map>
#include <set>

using namespace std;

#define all(a) (a).begin(), (a).end()
#define sz(a) static_cast<int>((a).size())
#define FOR(i, a, b) for (int i(a), b_(b); i < b_; ++i)
#define REP(i, n) FOR (i, 0, n)
#define FORD(i, a, b) for (int i(a), b_(b); i >= b_; --i)
#define UNIQUE(a) sort(all(a)), (a).erase(unique(all(a)), (a).end())
#define CL(a, v) memset(a, v, sizeof a)
#define eb emplace_back
#define pb push_back
#define X first
#define Y second

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
  constexpr static auto has_indirection(int) -> decltype(*declval<U>(), bool()) { return true; }
  template <class> constexpr static bool has_indirection(long) { return false; }
  constexpr static bool value = has_indirection<T>(0);
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

  template <class I> int readUnsignedIntGeneral(I& arg, char c) {
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

  template <class I> inline int readUnsignedInt(I& arg, char c) {
    if (__builtin_expect(base > 10, false)) return readUnsignedIntGeneral(arg, c);
    I value = 0;
    int length = 0;
    for (; static_cast<unsigned char>(c - '0') < base; ++length, c = nextChar())
      value = base * value + c - '0';
    arg = value;
    return --head, length;
  }

  template <class I> inline bool readSignedInt(I& arg, char c) {
    bool negative = c == '-';
    if (negative) c = nextChar();
    typename make_unsigned<I>::type unsignedArg;
    if (readUnsignedInt(unsignedArg, c) == 0) return false;
    arg = negative ? ~static_cast<I>(unsignedArg - 1) : static_cast<I>(unsignedArg);
    return true;
  }

  template <class F> bool readFloatingPoint(F& arg, char c) {
    bool negative = c == '-';
    if (negative) c = nextChar();
    unsigned long long integerPart;
    if (readUnsignedInt(integerPart, c) == 0) return false;
    arg = static_cast<F>(integerPart);
    if (nextChar() == '.') {
      unsigned long long fractionalPart = 0;
      int fractionalLength = readUnsignedInt(fractionalPart, nextChar());
      if (fractionalLength > 0) {
        unsigned long long basePower = 1;
        for (; fractionalLength; --fractionalLength) basePower *= base;
        arg += static_cast<F>(fractionalPart) / basePower;
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
  inline int readString(char* arg, int limit, UnaryPredicate isTerminator, bool skip) {
    int charsRead = 0;
    if (skip) skipCharacters(isTerminator), --head;
    

    for (--limit; head < tail; fillInput()) {
      ptrdiff_t chunkSize = find_if(head, min(tail, head + limit - charsRead), isTerminator) - head;
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
  bool>::type read(I& arg) { return readUnsignedInt(arg, skipCharacters()) > 0; }
  template <class I> inline typename enable_if<is_integral<I>::value && is_signed<I>::value,
  bool>::type read(I& arg) { return readSignedInt(arg, skipCharacters()); }
  template <class F> inline typename enable_if<is_floating_point<F>::value,
  bool>::type read(F& arg) { return readFloatingPoint(arg, skipCharacters()); }
  

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

  template <class I> inline char* writeUnsignedInt(I arg, char* last) {
    if (__builtin_expect(arg == 0, false)) *--last = '0';
    if (__builtin_expect(base == 10, true)) {
      for (; arg; arg /= 10) *--last = '0' + arg % 10;
    } else for (; arg; arg /= base) {
      I digit = arg % base;
      *--last = digit < 10 ? '0' + digit : 'A' - 10 + digit;
    }
    return last;
  }

  template <class I> inline char* writeSignedInt(I arg, char* last) {
    auto unsignedArg = static_cast<typename make_unsigned<I>::type>(arg);
    if (arg < 0) {
      last = writeUnsignedInt(~unsignedArg + 1, last);
      *--last = '-';
      return last;
    }
    return writeUnsignedInt(unsignedArg, last);
  }

  template <class F> char* writeFloatingPoint(F arg, char* last) {
    bool negative = signbit(arg);
    if (negative) arg = -arg;
    if (isnan(arg)) for (int i = 0; i < 3; ++i) *--last = i["NaN"];
    else if (isinf(arg)) for (int i = 0; i < 3; ++i) *--last = i["fnI"];
    else {
      auto integerPart = static_cast<unsigned long long>(arg);
      auto fractionalPart = static_cast<unsigned long long>((arg - integerPart) * basePower + F(0.5));
      if (fractionalPart >= basePower) ++integerPart, fractionalPart = 0;
      char* point = last - precision;
      if (precision > 0) {
        ::fill(point, writeUnsignedInt(fractionalPart, last), '0');
        *--point = '.';
      }
      last = writeUnsignedInt(integerPart, point);
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
  int>::type write(I arg) { return writeT(writeUnsignedInt(arg, end)); }
  template <class I> inline typename enable_if<is_integral<I>::value && is_signed<I>::value,
  int>::type write(I arg) { return writeT(writeSignedInt(arg, end)); }
  template <class F> inline typename enable_if<is_floating_point<F>::value,
  int>::type write(F arg) { return writeT(writeFloatingPoint(arg, end)); }
  

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



template<class T, typename Op>
class PersistentSegmentTree {
public:
  PersistentSegmentTree(const Op& op = Op()) : op(op) {}
  PersistentSegmentTree(const T& unit, const Op& op = Op())
  : unit(unit), op(op) {}

  void init(int n_, int m) {
    n = n_;
    for (h = 0; 1<<h < n; ++h); ++h;
    root.reserve(m+1);
    t.reserve(2*n-1 + m*h);
    t.resize(2*n-1);
    f = t.begin();
    root.assign(1, f);
    a.resize(n);
    link(f, 0, n);
  }

  T& operator [](int p) { return *a[p]; }

  void build() {
    for (pNode i = t.end(); i != t.begin(); )
      if ((--i)->l != t.end()) calc(i);
  }

  void reserve(int m) {  }

  void set(int p, const T& newv) {
    pNode v = root.back();
    int tl = 0, tr = n;
    t.resize(f - t.begin() + h+1);
    root.pb(++f);
    while (tl + 1 < tr) {
      int tm = (tl + tr) >> 1;
      if (p < tm) {
        tr = tm;
        f->l = f+1;
        f->r = v->r;
        v = v->l;
      } else {
        tl = tm;
        f->l = v->l;
        f->r = f+1;
        v = v->r;
      }
      ++f;
    }
    f->value = newv;
    a[p] = &f->value;
    for (pNode i = f; i != root.back(); calc(--i));
  }

  T query(int index, int l, int r) {
    return get(root[index], 0, n, l, r);
  }

  T unit;

private:
  struct Node;
  typedef typename vector<Node>::iterator pNode;
  struct Node { T value; pNode l, r; };

  void calc(pNode v) { v->value = op(v->l->value, v->r->value); }

  void link(pNode v, int tl, int tr) {
    if (tl + 1 == tr) {
      v->l = v->r = t.end();
      a[tl] = &v->value;
    } else {
      v->l = ++f;
      v->r = ++f;
      int tm = (tl + tr) >> 1;
      link(v->l, tl, tm);
      link(v->r, tm, tr);
    }
  }

  T get(pNode v, int tl, int tr, int l, int r) {
    while (tl + 1 < tr) {
      int tm = (tl + tr) >> 1;
      if (r <= tm) tr = tm, v = v->l;
      else if (l >= tm) tl = tm, v = v->r;
      else break;
    }
    if (l == tl && r == tr) return v->value;
    T res = unit;
    int tm = (tl + tr) >> 1;
    lget(v->l, tl, tm, l, res);
    rget(v->r, tm, tr, r, res);
    return res;
  }

  void lget(pNode v, int tl, int tr, int l, T& res) {
    while (l != tr) {
      if (tl == l) { res = op(v->value, res); return; }
      int tm = (tl + tr) >> 1;
      if (l < tm) res = op(v->r->value, res), tr = tm, v = v->l;
      else tl = tm, v = v->r;
    }
  }

  void rget(pNode v, int tl, int tr, int r, T& res) {
    while (tl != r) {
      if (r == tr) { res = op(res, v->value); return; }
      int tm = (tl + tr) >> 1;
      if (r >= tm) res = op(res, v->l->value), tl = tm, v = v->r;
      else tr = tm, v = v->l;
    }
  }

  Op op;
  int n, h;

  vector<Node> t;
  vector<T*> a;
  vector<pNode> root;
  pNode f;
};

template<class T>
struct PersistentSegmentTreeF {
  typedef PersistentSegmentTree<T, T (*)(T, T)> val;
  typedef PersistentSegmentTree<T, T (*)(const T&, const T&)> mix;
  typedef PersistentSegmentTree<T, const T& (*)(const T&, const T&)> ref;
};


struct T {
  int len, pref, suf, mx;
  T(bool one = false) : len(1) { pref = suf = mx = one ? len : 0; }
};

T comb(const T& a, const T& b) {
  T c;
  c.len = a.len + b.len;
  c.pref = a.pref == a.len ? a.len + b.pref : a.pref;
  c.suf  = b.suf  == b.len ? b.len + a.suf  : b.suf;
  c.mx = max(max(a.mx, b.mx), a.suf + b.pref);
  return c;
}

const int N = 100011;
int n, m, l, r, w;
pii h[N];

PersistentSegmentTreeF<T>::mix tree(comb);

int main() {
#ifdef AlCash
  input.reset(new InputFile("input.txt"));
  

  output.reset(new OutputFile());
  

#else
  input.reset(new InputFile(stdin, false));
  

  output.reset(new OutputFile());
#endif

  read(n);
  REP(i, n) read(h[i].X), h[i].Y = i;
  sort(h, h+n);
  tree.unit.len = 0;
  tree.init(n, n);
  tree.build();
  tree.reserve(n);
  FORD(i, n-1, 0) tree.set(h[i].Y, true);

  read(m);
  REP(i, m) {
    read(l, r, w);
    --l;
    int a = 0, b = n;
    while (a + 1 < b) {
      int d = (a + b) / 2;
      if (tree.query(d, l, r).mx >= w) b = d;
      else a = d;
    }
    writeln(h[n-b].X);
  }

#ifdef AlCash
  flush();
  cerr << endl << endl << static_cast<double>(clock()) / CLOCKS_PER_SEC << endl;
#endif
  return 0;
}
