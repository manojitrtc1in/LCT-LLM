#include <stdexcept>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <cassert>
#include <cstring>
#include <cstdarg>
#include <cstdio>
#include <memory>
#include <random>
#include <cmath>
#include <ctime>
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
  inline bool readString(char* arg, int limit, UnaryPredicate isTerminator) {
    skipCharacters(isTerminator);
    

    for (--head, --limit; head < tail; fillInput()) {
      ptrdiff_t chunkSize = find_if(head, min(tail, head + limit), isTerminator) - head;
      arg = copy_n(head, chunkSize, arg);
      head += chunkSize;
      limit -= chunkSize;
      if (chunkSize == 0 || head < tail) break;
    }
    return *arg = '\0', true;
  }

  template <class I> inline bool readUnsignedInt(I& arg) { return readUnsignedInt(arg, skipCharacters()) > 0; }
  template <class I> inline bool readSignedInt(I& arg) { return readSignedInt(arg, skipCharacters()); }
  template <class F> inline bool readFloatingPoint(F& arg) { return readFloatingPoint(arg, skipCharacters()); }
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
  , fill(setFill().value), base(setBase().value), precision(setPrecision().value), delimiter(setDelimiter().value) {}
  OutputDevice(OutputDevice const&) = delete;
  OutputDevice& operator = (OutputDevice const&) = delete;

  virtual void writeToDevice(uint count) = 0;

  inline void flushMaybe() {
    if (__builtin_expect(output >= buffer + BUFFER_SIZE, false)) {
      writeToDevice(BUFFER_SIZE);
      output = copy(buffer + BUFFER_SIZE, output, buffer);
    }
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
      arg -= integerPart;
      for (int i = 0; i < precision; ++i) arg *= base;
      auto fractionalPart = static_cast<unsigned long long>(arg);
      if ((arg - fractionalPart) * 2 >= static_cast<F>(1)) {
        if (precision == 0) ++integerPart;
        else ++fractionalPart;
      }
      if (precision > 0) {
        char* point = last - precision;
        last = writeUnsignedInt(fractionalPart, last);
        ::fill(point, last, '0');
        last = point;
        *--last = '.';
      }
      last = writeUnsignedInt(integerPart, last);
    }
    if (negative) *--last = '-';
    return last;
  }

  inline int writeT(char* first) {
    int delimiterLenght = separate ? writeDelimiter() : 0;
    separate = true;
    int charsWritten = static_cast<int>(end - first);
    if (__builtin_expect(charsWritten < width, false))
      charsWritten += writeFill(width - charsWritten);
    output = copy(first, end, output);
    flushMaybe();
    return delimiterLenght + charsWritten;
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
  string delimiter;

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

  template <class I> inline int writeUnsignedInt(I arg) { return writeT(writeUnsignedInt(arg, end)); }
  template <class I> inline int writeSignedInt(I arg) { return writeT(writeSignedInt(arg, end)); }
  template <class F> inline int writeFloatingPoint(F arg) { return writeT(writeFloatingPoint(arg, end)); }

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
int>::type read(I& arg) { return input->readUnsignedInt(arg); }
template <class I> inline typename enable_if<is_integral<I>::value && is_signed<I>::value,
int>::type read(I& arg) { return input->readSignedInt(arg); }
template <class F> inline typename enable_if<is_floating_point<F>::value,
int>::type read(F& arg) { return input->readFloatingPoint(arg); }


inline int read(const char& arg) { input->skipCharacters([arg](char c) { return arg != c; }); return 0; }
inline int read(const char* arg) {
  if (*arg) input->skipCharacters([arg](char c) { return InputDevice::isOneOf(c, arg); });
  else input->skipCharacters();
  input->putBack(); return 0;
}
inline int read(bool (*isSkipped)(char)) { input->skipCharacters(isSkipped); input->putBack(); return 0; }


template <class... Ts> int read(char* arg, int limit, bool (*isTerminator)(char), Ts&&... args);
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
inline int read(char* arg, int limit, bool (*isTerminator)(char), Ts&&... args) {
  int argsRead = input->readString(arg, limit, isTerminator);
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
inline int write(Detail::Base base) { output->base = base.value; return 0; }
inline int write(Detail::Precision precision) { output->precision = precision.value; return 0; }
inline int write(Detail::Delimiter delimiter) { output->delimiter = delimiter.value; return 0; }


inline int write() { return 0; }
inline int write(char arg) { return output->writeChar(arg); }
template <class I> inline typename enable_if<is_integral<I>::value && is_unsigned<I>::value,
int>::type write(I arg) { return output->writeUnsignedInt(arg); }
template <class I> inline typename enable_if<is_integral<I>::value && is_signed<I>::value,
int>::type write(I arg) { return output->writeSignedInt(arg); }
template <class F> inline typename enable_if<is_floating_point<F>::value,
int>::type write(F arg) { return output->writeFloatingPoint(arg); }


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

template <int V, bool ORIENTED = false>
class GraphUL {
  int n, m;
  vector<int> adjacent[V];

public:
  GraphUL(int newn = 0, int newm = -1) : n(0) { init(newn, newm); }

  void init(int newn, int newm = -1) {
    for (int i = 0; i < n; ++i) vector<int>().swap(adjacent[i]);
    n = newn;
    m = newm >= 0 ? newm : n;
  }

  void addEdge(int u, int v) {
    assert(u < n && v < m);
    adjacent[u].push_back(v);
    if (!ORIENTED && u != v) adjacent[v].push_back(u);
  }

  bool oriented() const { return ORIENTED; }
  int size() const { return n; }
  int size2() const { return m; }
  const vector<int>& operator [] (int v) const { return adjacent[v]; }
};

class CycleFinder {
  vector<int> stack, used;

  template <class G>
  bool dfs(const G& graph, int v) {
    used[v] = static_cast<int>(stack.size());
    stack.push_back(v);
    for (int u : graph[v]) {
      if (used[u] >= 0) {
        stack.erase(stack.begin(), stack.begin() + used[u]);
        return true;
      }
      if (used[u] == -1 && dfs(graph, u)) return true;
    }
    stack.pop_back();
    used[v] = -2;
    return false;
  }

public:
  template <class G>
  const vector<int>& cycle(const G& graph) {
    int n = graph.size();
    stack.clear();
    stack.reserve(n);
    used.assign(n, -1);
    for (int v = 0; v < n; ++v)
      if (used[v] == -1 && dfs(graph, v)) break;
    return stack;
  }
};

template <class C, int N>
class KMP {
public:
  const C* pattern;
  int n, prefixF[N+1] = {-1, 0};

  void build(const C* s, int length) {
    pattern = s;
    n = length;
    for (int i = 1; i < n; ++i) {
      int j = prefixF[i];
      while (j >= 0 && pattern[i] != pattern[j]) j = prefixF[j];
      prefixF[i + 1] = j + 1;
    }
  }

  template <class Visitor>
  int search(const C* text, int length, Visitor visitor) {
    int j = 0;
    for (int i = 0; i < length; ++i) {
      while (j == n || (j >= 0 && pattern[j] != text[i])) j = prefixF[j];
      if (++j == n) visitor(i + 1 - n);
    }
    return j;
  }
};

const int N = 30, L = 1e5+1;
int n, d[N+1], len[N];
char s[L];

GraphUL<L, true> graph;
CycleFinder finder;
KMP<char, L> kmp;

bool ok(int l, int r) {
  graph.init(d[r] + 1);
  FOR(x, l, r) {
    kmp.build(s + d[x], len[x]);
    FOR(y, l, r) {
      int prefix = kmp.search(s + d[y], len[y], [&](int i) {
        int u = i == 0 ? d[l] : d[y] + i;
        int v = i + len[x] == len[y] ? d[l] : d[y] + i + len[x];
        if (u != d[l] || v != d[l]) graph.addEdge(u, v);
      });
      for (; prefix > 0; prefix = kmp.prefixF[prefix])
        if (prefix != len[x])
          graph.addEdge(d[y+1] - prefix, d[x] + prefix);
    }
  }
  return finder.cycle(graph).empty();
}

int main() {
#ifdef LocalHost
  input.reset(new InputFile("input.txt"));
  

  output.reset(new OutputFile());
  

#else
  input.reset(new InputFile(stdin, false));
  

  output.reset(new OutputFile());
#endif

  read(n);
  d[0] = 0;
  REP(i, n) {
    read(s + d[i], L);
    len[i] = static_cast<int>(strlen(s + d[i]));
    d[i+1] = d[i] + len[i];
  }
  int ans = 0;
  for (int l = 0, r = 1; r <= n; ++r) {
    for (; l < r && !ok(l, r); ++l);
    ans += r - l;
  }
  writeln(ans);

#ifdef LocalHost
  flush();
  cerr << endl << endl << static_cast<double>(clock()) / CLOCKS_PER_SEC << endl;
#endif
  return 0;
}