




using namespace std;






namespace FF {
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

    InputDevice(const char* head_, const char* tail_) : head(head_), tail(tail_), base(setBase().value) {}

    virtual void fillInput() = 0;

    inline char nextChar() {
        if (__builtin_expect(head >= tail, false)) fillInput();
            return *head++;
    }

    template <class I> int id2(I& arg, char c) {
        I value = 0;
        int length = 0;
        for (;; ++length, c = nextChar()) {
            if(isDigit(c)) c -= '0';
            else if (isUpper(c)) c -= 'A' - 10;
            else if (isLower(c)) c -= 'a' - 10;
            else c = base;
            if (c >= base) break;
            value = base * value + c;
        }
        arg = value;
        return --head, length;
    }

    template <class I> inline int id7(I& arg, char c) {
        if (__builtin_expect(base > 10, false)) return id2(arg, c);
            I value = 0;
            int length = 0;
            for (; static_cast<unsigned char>(c - '0') < base; ++length, c = nextChar())
                value = base * value + c - '0';
            arg = value;
        return --head, length;
    }

    template <class I> inline bool id14(I& arg, char c) {
        bool negative = c == '-';
        if (negative) c = nextChar();
        typename make_unsigned<I>::type unsignedArg;
        if (id7(unsignedArg, c) == 0) return false;
        arg = negative ? ~static_cast<I>(unsignedArg - 1) : static_cast<I>(unsignedArg);
        return true;
    }

template <class F> bool id6(F& arg, char c) {
bool negative = c == '-';
if (negative) c = nextChar();
unsigned long long integerPart;
if (id7(integerPart, c) == 0) return false;
arg = static_cast<F>(integerPart);
if (nextChar() == '.') {
  unsigned long long id13 = 0;
  int id11 = id7(id13, nextChar());
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
inline int readString(char* arg, int limit, UnaryPredicate id10) {
skipCharacters(id10);


int charsRead = 0;
for (--head, --limit; head < tail; fillInput()) {
  ptrdiff_t chunkSize = find_if(head, min(tail, head + limit - charsRead), id10) - head;
  arg = copy_n(head, chunkSize, arg);
  head += chunkSize;
  charsRead += chunkSize;
  if (chunkSize == 0 || head < tail) break;
}
return *arg = '\0', charsRead;
}

inline int readString(char* arg, int limit, const char* terminators) {
if (!*terminators) return readString(arg, limit, InputDevice::isSpace);
return readString(arg, limit, [terminators](char c) { return InputDevice::isOneOf(c, terminators); });
}



inline bool read(Detail::Base newBase) { base = newBase.value; return true; }


inline bool read() { return true; }
inline bool read(char& arg) { return readChar(arg); }
template <class I> inline typename enable_if<is_integral<I>::value && is_unsigned<I>::value,
bool>::type read(I& arg) { return id7(arg, skipCharacters()) > 0; }
template <class I> inline typename enable_if<is_integral<I>::value && is_signed<I>::value,
bool>::type read(I& arg) { return id14(arg, skipCharacters()); }
template <class F> inline typename enable_if<is_floating_point<F>::value,
bool>::type read(F& arg) { return id6(arg, skipCharacters()); }


inline bool read(const char& arg) { skipCharacters([arg](char c) { return arg != c; }); return true; }
inline bool read(const char* arg) {
if (*arg) skipCharacters([arg](char c) { return InputDevice::isOneOf(c, arg); });
else skipCharacters();
return putBack(), true;
}
inline bool read(bool (*isSkipped)(char)) { skipCharacters(isSkipped); putBack(); return true; }


template <class I, class Terminator, class... Ts> inline typename enable_if<is_integral<I>::value,
bool>::type read(char* arg, I limit, Terminator terminator, Ts&&... args) {
readString(arg, static_cast<int>(limit), terminator);
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
for (int length = 16, last = 0;; last += length, length <<= 1) {
  arg.resize(last + length);
  int charsRead = readString(&arg[last], length + 1, terminator);
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
    InputFile(FILE* file_ = stdin, bool id5 = true, bool takeOwnership = false) :
        InputDevice(buffer, buffer),
        file(file_),
        lineBuffered(id5),
        owner(takeOwnership) {}
    InputFile(const char* fileName) : InputFile(fopen(fileName, "r"), false, true) {}

    ~InputFile() {
        if(owner)
            fclose(file);
    }
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

template <class I> inline char* id9(I arg, char* last) {
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
  last = id9(~unsignedArg + 1, last);
  *--last = '-';
  return last;
}
return id9(unsignedArg, last);
}

template <class F> char* id8(F arg, char* last) {
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
    ::fill(point, id9(id13, last), '0');
    *--point = '.';
  }
  last = id9(integerPart, point);
}
if (negative) *--last = '-';
return last;
}

inline int writeT(char* first) {
int id3 = separate ? writeDelimiter() : 0;
separate = true;
uint charsWritten = static_cast<uint>(end - first);
if (__builtin_expect(charsWritten < width, false))
  charsWritten += writeFill(width - charsWritten);
output = copy(first, end, output);
flushMaybe();
return id3 + static_cast<int>(charsWritten);
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
int>::type write(I arg) { return writeT(id9(arg, end)); }
template <class I> inline typename enable_if<is_integral<I>::value && is_signed<I>::value,
int>::type write(I arg) { return writeT(id0(arg, end)); }
template <class F> inline typename enable_if<is_floating_point<F>::value,
int>::type write(F arg) { return writeT(id8(arg, end)); }


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
    OutputFile(FILE* file_ = stdout, bool takeOwnership = false) : file(file_), owner(takeOwnership) {}
    OutputFile(const char* fileName) : OutputFile(fopen(fileName, "w"), true) {}
    ~OutputFile() override {
        flush();
        if(owner)
            fclose(file);
    }
};

class OutputString : public OutputDevice {
    string& str;

    void writeToDevice(uint count) override {
        str.append(buffer, count);
    }

public:
    OutputString(string& str_) : OutputDevice(), str(str_) {}
    ~OutputString() override {
        flush();
    }
};

unique_ptr<InputDevice> input;
unique_ptr<OutputDevice> output;

template <class... Ts> inline bool read(Ts&&... args) { return input->read(forward<Ts>(args)...); }
template <class... Ts> inline int write(Ts&&... args) { return output->write(forward<Ts>(args)...); }
template <class... Ts> inline int writeln(Ts&&... args) { return write(forward<Ts>(args)..., '\n'); }
void flush() { output->flush(); }
}
using namespace FF;



typedef long long ll;
typedef pair<int, int> ii;

int N, K;
vector<int> cnt_up, cnt_down, up_mark, down_mark, traverse, t, h, id1, xxx, p;
vector<ii> edges;
vector<vector<ii>> g;

void dfs1(const int &v, const int &parent = -1, const int &edge = -1) {
    p[v] = parent;
    id1[v] = traverse.size();
    traverse.push_back(v);
    for(const ii &to : g[v])
        if(to.X != parent) {
            h[to.X] = h[v] + 1;
            dfs1(to.X, v, to.Y);
            traverse.push_back(v);
        }
}

void dfs2(const int &v, const int &parent = -1) {
    for(const ii &to : g[v])
        if(to.X != parent) {
            dfs2(to.X, v);
            up_mark[v] += up_mark[to.X];
            down_mark[v] += down_mark[to.X];
        }
    for(const ii &to : g[v])
        if(to.X != parent) {
            cnt_up[to.Y] = up_mark[to.X];
            cnt_down[to.Y] = down_mark[to.X];
        }
}

void build(const int &v, const int &tl, const int &tr) {
    if(tl == tr) {
        t[v] = traverse[tl];
        return;
    }
    int tm = (tl + tr) / 2;
    build(v * 2, tl, tm);
    build(v * 2 + 1, tm + 1, tr);
    t[v] = (h[t[v * 2]] < h[t[v * 2 + 1]] ? t[v * 2] : t[v * 2 + 1]);
}

int get(const int &v, const int &tl, const int &tr, const int &l, const int &r) {
    if(l <= tl && tr <= r)
        return t[v];
    if(l > tr || r < tl)
        return -1;
    int tm = (tl + tr) / 2;
    int i1 = get(v * 2, tl, tm, l, r);
    int i2 = get(v * 2 + 1, tm + 1, tr, l, r);
    if(i1 == -1) return i2;
    if(i2 == -1) return i1;
    return (h[i1] < h[i2] ? i1 : i2);
}

void build_tree() {
    t.resize(4 * traverse.size());
    build(1, 0, traverse.size() - 1);
}

int lca(const int &v1, const int &v2) {
    int i1 = id1[v1], i2 = id1[v2];
    if(i1 > i2)
        swap(i1, i2);
    return get(1, 0, traverse.size() - 1, i1, i2);
}

void solve() {
    read(N);
    id1.resize(N, -1);
    up_mark.resize(N, 0);
    down_mark.resize(N, 0);
    p.resize(N);
    h.resize(N);
    g.resize(N);
    cnt_up.resize(N - 1);
    cnt_down.resize(N - 1);
    for(int i = 0;i < N - 1;i++) {
        int u, v, x;
        read(u, v, x);
        u--;v--;
        edges.push_back(ii(u, v));
        if(x == 1)
            xxx.push_back(i);
        g[u].push_back(ii(v, i));
        g[v].push_back(ii(u, i));
    }
    h[0] = 0;
    dfs1(0);
    build_tree();
    read(K);
    int S1 = 1, S2;
    for(int i = 1;i <= K;i++) {
        read(S2);
        int v1 = S1 - 1, v2 = S2 - 1;
        int id12 = lca(v1, v2);
        if(id12 != v1 && id12 != v2) {
            up_mark[v1]++;
            up_mark[id12]--;
            down_mark[v2]++;
            down_mark[id12]--;
        } else if(id12 == v1) {
            down_mark[v1]--;
            down_mark[v2]++;
        } else if(id12 == v2) {
            up_mark[v1]++;
            up_mark[v2]--;
        }
        S1 = S2;
    }
    up_mark[0] = 0;
    down_mark[0] = 0;
    dfs2(0);
    int MOD = 1000000007, ans = 0;
    vector<int> pow2(1000020);
    pow2[0] = 1;
    for(int i = 1;i < pow2.size();i++)
        pow2[i] = (pow2[i - 1] * 2) % MOD;
    for(const int &i : xxx) {
        if(p[edges[i].X] == edges[i].Y)
            ans = (ans + pow2[cnt_down[i]] - 1) % MOD;
        else
            ans = (ans + pow2[cnt_up[i]] - 1) % MOD;
    }
    write(ans);
}

int main() {
    if(ONLINE_JUDGE) { 

        input.reset(new InputFile(stdin, false));

        

        

        output.reset(new OutputFile());
    } else { 

            input.reset(new InputFile("input.txt"));
        output.reset(new OutputFile());


    }













    solve();
    return 0;
}
