





























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

  template <class I> inline bool id10(I& arg, char c) {
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
      unsigned long long id9 = 0;
      int id8 = id4(id9, nextChar());
      if (id8 > 0) {
        unsigned long long basePower = 1;
        for (; id8; --id8) basePower *= base;
        arg += static_cast<F>(id9) / basePower;
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
  template <class I> inline bool id10(I& arg) { return id10(arg, skipCharacters()); }
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
      auto id9 = static_cast<unsigned long long>((arg - integerPart) * basePower + F(0.5));
      if (id9 >= basePower) ++integerPart, id9 = 0;
      char* point = last - precision;
      if (precision > 0) {
        ::fill(point, id6(id9, last), '0');
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
int>::type read(I& arg) { return input->id10(arg); }
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



const int N = 1011, C = N * N / 4;
int h, w, m, k;
char s[N][N];
int c[N][N], cc = 0;
pii q[N*N], a[10];

vi adj[C], e[C+10];
bool vis[C+10];
vi qh, qw;

inline bool check(int x, int y) { return 0 <= x && x <= h && 0 <= y && y <= w; }

void clear() {
  REP(i, k) {
    for (int x : e[cc + i]) if (x < cc) e[x].clear();
    e[cc + i].clear();
  }
  for (int x : qh) vis[x] = false;
  for (int x : qw) vis[x] = false;
  qh.clear();
  qw.clear();
}

void bfs(int v, vi& q) {
  q = {v};
  vis[v] = true;
  for (int qa = 0; qa < sz(q); ++qa) {
    v = q[qa];
    for (int u : e[v]) if (!vis[u]) {
      vis[u] = true;
      q.pb(u);
    }
  }
}

bool close(int u, int v) {
  if (u > v) swap(u, v);
  if (v < cc) {
    if (sz(adj[u]) < sz(adj[v])) swap(u, v);
    auto it = lower_bound(all(adj[v]), u);
    return it != adj[v].end() && *it == u;
  } else {
    if (u < cc) {
      FOR(dx, -2, 3) FOR(dy, -2, 3) {
        int x = a[v-cc].X + dx;
        int y = a[v-cc].Y + dy;
        if (check(x, y) && s[x][y] == '
      }
    } else {
      return abs(a[u-cc].X - a[v-cc].X) < 3 && abs(a[u-cc].Y - a[v-cc].Y) < 3;
    }
  }
  return false;
}

bool solve() {
  REP(i, k) {
    vi& touch = e[cc + i];
    FOR(dx, -1, 2) FOR(dy, -1, 2) {
      int x = a[i].X + dx, y = a[i].Y + dy;
      if (check(x, y) && s[x][y] == '
    }
    UNIQUE(touch);
    for (int x : touch) e[x].pb(cc + i);
  }
  REP(i, k) FOR(j, i+1, k)
  if (abs(a[i].X - a[j].X) < 2 && abs(a[i].Y - a[j].Y) < 2) {
    e[cc + i].pb(cc + j);
    e[cc + j].pb(cc + i);
  }

  bfs(c[h][0], qh);
  if (vis[c[0][w]]) {
    clear();
    return false;
  }
  bfs(c[0][w], qw);





  bool ok = true;
  for (int u : qh) {
    for (int v : qw) if (close(u, v)) {
      ok = false;
      break;
    }
    if (!ok) break;
  }
  clear();
  return ok;
}

int main() {

  input.reset(new InputFile("input.txt"));
  

  output.reset(new OutputFile());
  


  

  input.reset(new InputFile());
  output.reset(new OutputFile());


  read(h, w, m);
  ++h, ++w;
  FOR(i, 1, h) read(s[i]+1, N);
  s[1][1] = s[h-1][w-1] = '!';
  FOR(i, 2, h+1) s[i][0] = '
  FOR(j, 2, w+1) s[0][j] = '
  REP(i, h-1) s[i][w] = '
  REP(j, w-1) s[h][j] = '
  REP(i, h+1) REP(j, w+1) if (!s[i][j]) s[i][j] = '+';



  CL(c, -1);
  REP(i, h+2) REP(j, w+2) if (s[i][j] == '
    q[0] = {i, j};
    c[i][j] = cc;
    int qa = 0, qb = 1;
    for (; qa < qb; ++qa) {
      int x0 = q[qa].X, y0 = q[qa].Y;
      FOR(dx, -1, 2) FOR(dy, -1, 2) {
        int x = x0 + dx, y = y0 + dy;
        if (check(x, y) && s[x][y] == '
          q[qb++] = {x, y};
          c[x][y] = cc;
        }
      }
    }
    vi near;
    REP(u, qb) {
      int x0 = q[u].X, y0 = q[u].Y;
      FOR(dxx, -1, 2) FOR(dyy, -1, 2) {
        int xx = x0 + dxx, yy = y0 + dyy;
        if (check(xx, yy) && s[xx][yy] == '.' && c[xx][yy] != cc) {
          c[xx][yy] = cc;
          FOR(dx, -1, 2) FOR(dy, -1, 2) {
            int x = xx + dx, y = yy + dy;
            if (check(x, y) && s[x][y] == '
              near.pb(c[x][y]);
          }
        }
      }
    }
    UNIQUE(near);
    for (int v : near) adj[v].pb(cc);
    adj[cc].swap(near);
    ++cc;
  }





















  REP(u, m) {
    read(k, a, k);
    writeln(solve() ? "YES" : "NO");
    flush();
  }


  flush();
  cerr << endl << endl << static_cast<double>(clock()) / CLOCKS_PER_SEC << endl;

  return 0;
}
