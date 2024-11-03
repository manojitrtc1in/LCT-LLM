#include <bits/stdc++.h>
using namespace std;
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

#include <algorithm>
#include <cassert>
#include <complex>
#include <cstring>
#include <memory>
#include <string>
#include <vector>

using namespace std;

template <class T> struct is_iterator {
    template <class U, typename enable_if<!is_convertible<U, const char *>::value, int>::type = 0> constexpr static auto has_indirection(int) -> decltype(*declval<U>(), bool()) { return true; }
    template <class> constexpr static bool has_indirection(long) { return false; }
    constexpr static bool value = has_indirection<T>(0);
};

using uint = unsigned int;


const uint BUFFER_SIZE = 1 << 12;




const uint MAX_LENGTH = 1 << 7;

namespace Detail {
struct Width {
    uint value;
};
struct Fill {
    char value;
};
struct Base {
    uint value;
};
struct Precision {
    uint value;
};
struct Delimiter {
    const char *value;
};
} 


Detail::Width setWidth(uint value = 0) { return {value}; }
Detail::Fill setFill(char value = ' ') { return {value}; }
Detail::Base setBase(uint value = 10) {
    assert(2 <= value && value <= 36);
    return {value};
}
Detail::Precision setPrecision(uint value = 9) {
    assert(value < MAX_LENGTH);
    return {value};
}
Detail::Delimiter setDelimiter(const char *value = " ") { return {value}; }


class InputDevice {
  protected:
    const char *head;
    const char *tail;

    InputDevice(const char *head, const char *tail) : head(head), tail(tail), base(setBase().value) {}

    virtual void fillInput() = 0;

    inline char nextChar() {
        if (__builtin_expect(head >= tail, false)) fillInput();
        return *head++;
    }

    template <class I> int readUnsignedIntGeneral(I &arg, char c) {
        I value = 0;
        int length = 0;
        for (;; ++length, c = nextChar()) {
            if (isDigit(c))
                c -= '0';
            else if (isUpper(c))
                c -= 'A' - 10;
            else if (isLower(c))
                c -= 'a' - 10;
            else
                c = base;
            if (c >= base) break;
            value = base * value + c;
        }
        arg = value;
        return --head, length;
    }

    template <class I> inline int readUnsignedInt(I &arg, char c) {
        if (__builtin_expect(base > 10, false)) return readUnsignedIntGeneral(arg, c);
        I value = 0;
        int length = 0;
        for (; static_cast<unsigned char>(c - '0') < base; ++length, c = nextChar()) value = base * value + c - '0';
        arg = value;
        return --head, length;
    }

    template <class I> inline bool readSignedInt(I &arg, char c) {
        bool negative = c == '-';
        if (negative) c = nextChar();
        typename make_unsigned<I>::type unsignedArg;
        if (readUnsignedInt(unsignedArg, c) == 0) return false;
        arg = negative ? ~static_cast<I>(unsignedArg - 1) : static_cast<I>(unsignedArg);
        return true;
    }

    template <class F> bool readFloatingPoint(F &arg, char c) {
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
        } else
            --head;
        if (negative) arg = -arg;
        return true;
    }

  public:
    uint base;

    InputDevice(InputDevice const &) = delete;
    InputDevice &operator=(InputDevice const &) = delete;

    static inline bool isSpace(char c) { return static_cast<unsigned char>(c - '\t') < 5 || c == ' '; }
    static inline bool isDigit(char c) { return static_cast<unsigned char>(c - '0') < 10; }
    static inline bool isUpper(char c) { return static_cast<unsigned char>(c - 'A') < 26; }
    static inline bool isLower(char c) { return static_cast<unsigned char>(c - 'a') < 26; }
    static inline bool isOneOf(char c, const char *str) { return strchr(str, c) != nullptr; }

    void putBack() { --head; } 


    inline bool readChar(char &arg) {
        if (__builtin_expect(head >= tail, false)) {
            fillInput();
            if (__builtin_expect(head >= tail, false)) return arg = '\0', false;
        }
        return arg = *head++, true;
    }

    template <class UnaryPredicate> inline char skipCharacters(UnaryPredicate isSkipped) {
        char c;
        do { c = nextChar(); } while (isSkipped(c));
        return c;
    }
    inline char skipCharacters() { return skipCharacters(isSpace); }

    template <class UnaryPredicate> inline int readString(char *arg, int limit, UnaryPredicate isTerminator) {
        skipCharacters(isTerminator);
        

        int charsRead = 0;
        for (--head, --limit; head < tail; fillInput()) {
            ptrdiff_t chunkSize = find_if(head, min(tail, head + limit - charsRead), isTerminator) - head;
            arg = copy_n(head, chunkSize, arg);
            head += chunkSize;
            charsRead += chunkSize;
            if (chunkSize == 0 || head < tail) break;
        }
        return *arg = '\0', charsRead;
    }

    inline int readString(char *arg, int limit, const char *terminators) {
        if (!*terminators) return readString(arg, limit, InputDevice::isSpace);
        return readString(arg, limit, [terminators](char c) { return InputDevice::isOneOf(c, terminators); });
    }

    

    inline bool read(Detail::Base newBase) {
        base = newBase.value;
        return true;
    }
    

    inline bool read() { return true; }
    inline bool read(char &arg) { return readChar(arg); }
    template <class I> inline typename enable_if<is_integral<I>::value && is_unsigned<I>::value, bool>::type read(I &arg) { return readUnsignedInt(arg, skipCharacters()) > 0; }
    template <class I> inline typename enable_if<is_integral<I>::value && is_signed<I>::value, bool>::type read(I &arg) { return readSignedInt(arg, skipCharacters()); }
    template <class F> inline typename enable_if<is_floating_point<F>::value, bool>::type read(F &arg) { return readFloatingPoint(arg, skipCharacters()); }
    

    inline bool read(const char &arg) {
        skipCharacters([arg](char c) { return arg != c; });
        return true;
    }
    inline bool read(const char *arg) {
        if (*arg)
            skipCharacters([arg](char c) { return InputDevice::isOneOf(c, arg); });
        else
            skipCharacters();
        return putBack(), true;
    }
    inline bool read(bool (*isSkipped)(char)) {
        skipCharacters(isSkipped);
        putBack();
        return true;
    }
    

    template <class I, class Terminator, class... Ts> inline typename enable_if<is_integral<I>::value, bool>::type read(char *arg, I limit, Terminator terminator, Ts &&... args) {
        readString(arg, static_cast<int>(limit), terminator);
        return read(forward<Ts>(args)...);
    }
    template <class I> inline typename enable_if<is_integral<I>::value, bool>::type read(char *arg, I limit) { return read(arg, limit, ""); }
    template <class... Ts> inline bool read(char *first, char *last, Ts &&... args) { return read(first, static_cast<int>(last - first), forward<Ts>(args)...); }
    template <int N, class... Ts> inline bool read(char (&arg)[N], Ts &&... args) { return read(static_cast<char *>(arg), N, forward<Ts>(args)...); }
    template <class Terminator, class... Ts> inline bool read(string &arg, Terminator terminator, Ts &&... args) {
        for (int length = 16, last = 0;; last += length, length <<= 1) {
            arg.resize(last + length);
            int charsRead = readString(&arg[last], length + 1, terminator);
            if (charsRead < length) {
                arg.resize(last + charsRead);
                return read(forward<Ts>(args)...);
            }
        }
    }
    inline bool read(string &arg) { return read(arg, ""); }
    

    template <class T1, class T2> inline bool read(pair<T1, T2> &arg) { return read(arg.first, arg.second); }
    template <class T> inline bool read(complex<T> &arg) {
        T real, imag;
        if (!read(real, imag)) return false;
        arg.real(real), arg.imag(imag);
        return true;
    }
    template <class T> inline bool read(vector<T> &arg) {
        uint n;
        if (!read(n)) return false;
        arg.resize(n);
        return read(arg.begin(), arg.end());
    }
    template <class Iterator, class... Ts> inline typename enable_if<is_iterator<Iterator>::value, bool>::type read(Iterator first, Iterator last, Ts &&... args) {
        for (; first != last; ++first)
            if (!read(*first)) return false;
        return read(forward<Ts>(args)...);
    }
    template <class Iterator, class I, class... Ts> inline typename enable_if<is_iterator<Iterator>::value && is_integral<I>::value, bool>::type read(Iterator first, I count, Ts &&... args) {
        return read(first, first + count, forward<Ts>(args)...);
    }
    

    template <class T> inline auto read(T &arg) -> decltype(arg.read(*this)) { return arg.read(*this); }
    template <class T0, class T1, class... Ts> inline typename enable_if<!is_iterator<T0>::value && !is_convertible<T0, char *>::value, bool>::type read(T0 &&arg0, T1 &&arg1, Ts &&... args) {
        return read(forward<T0>(arg0)) && read(forward<T1>(arg1), forward<Ts>(args)...);
    }
};

class InputFile : public InputDevice {
    FILE *file;
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
            if (fgets(buffer, BUFFER_SIZE, file))
                while (*tail) ++tail;
        }
    }

  public:
    InputFile(FILE *file = stdin, bool lineBuffered = true, bool takeOwnership = false) : InputDevice(buffer, buffer), file(file), lineBuffered(lineBuffered), owner(takeOwnership) {}
    InputFile(const char *fileName) : InputFile(fopen(fileName, "r"), false, true) {}
    ~InputFile() {
        if (owner) fclose(file);
    }
};



class InputString : public InputDevice {
    void fillInput() override {
        while (*tail) ++tail;
    }

  public:
    InputString(const string &s) : InputDevice(s.data(), s.data() + s.size()) {}
    InputString(const char *s) : InputDevice(s, s + strlen(s)) {}
};


class OutputDevice {
  protected:
    char buffer[BUFFER_SIZE + MAX_LENGTH];
    char *output;
    char *end;
    bool separate;

    OutputDevice()
        : output(buffer), end(buffer + BUFFER_SIZE + MAX_LENGTH), separate(false), width(setWidth().value), fill(setFill().value), base(setBase().value), precision(setPrecision().value),
          delimiter(setDelimiter().value) {
        computeBasePower();
    }

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

    template <class I> inline char *writeUnsignedInt(I arg, char *last) {
        if (__builtin_expect(arg == 0, false)) *--last = '0';
        if (__builtin_expect(base == 10, true)) {
            for (; arg; arg /= 10) *--last = '0' + arg % 10;
        } else
            for (; arg; arg /= base) {
                I digit = arg % base;
                *--last = digit < 10 ? '0' + digit : 'A' - 10 + digit;
            }
        return last;
    }

    template <class I> inline char *writeSignedInt(I arg, char *last) {
        auto unsignedArg = static_cast<typename make_unsigned<I>::type>(arg);
        if (arg < 0) {
            last = writeUnsignedInt(~unsignedArg + 1, last);
            *--last = '-';
            return last;
        }
        return writeUnsignedInt(unsignedArg, last);
    }

    template <class F> char *writeFloatingPoint(F arg, char *last) {
        bool negative = signbit(arg);
        if (negative) arg = -arg;
        if (isnan(arg))
            for (int i = 0; i < 3; ++i) *--last = i["NaN"];
        else if (isinf(arg))
            for (int i = 0; i < 3; ++i) *--last = i["fnI"];
        else {
            auto integerPart = static_cast<unsigned long long>(arg);
            auto fractionalPart = static_cast<unsigned long long>((arg - integerPart) * basePower + F(0.5));
            if (fractionalPart >= basePower) ++integerPart, fractionalPart = 0;
            char *point = last - precision;
            if (precision > 0) {
                ::fill(point, writeUnsignedInt(fractionalPart, last), '0');
                *--point = '.';
            }
            last = writeUnsignedInt(integerPart, point);
        }
        if (negative) *--last = '-';
        return last;
    }

    inline int writeT(char *first) {
        int delimiterLenght = separate ? writeDelimiter() : 0;
        separate = true;
        uint charsWritten = static_cast<uint>(end - first);
        if (__builtin_expect(charsWritten < width, false)) charsWritten += writeFill(width - charsWritten);
        output = copy(first, end, output);
        flushMaybe();
        return delimiterLenght + static_cast<int>(charsWritten);
    }

    inline int writeFill(uint count) {
        int charsWritten = static_cast<int>(count);
        if (__builtin_expect(output + count + MAX_LENGTH < end, true)) {
            if (count == 1)
                *output++ = fill;
            else
                output = fill_n(output, count, fill);
        } else
            for (uint chunkSize = static_cast<uint>(buffer + BUFFER_SIZE - output);; chunkSize = BUFFER_SIZE) {
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

    OutputDevice(OutputDevice const &) = delete;
    OutputDevice &operator=(OutputDevice const &) = delete;
    virtual ~OutputDevice(){};

    inline int writeChar(char arg) {
        separate = false;
        *output++ = arg;
        flushMaybe();
        return 1;
    }

    inline int writeString(const char *arg, size_t length, bool checkWidth = true) {
        separate = false;
        uint count = static_cast<uint>(length);
        int charsWritten = static_cast<int>(count) + (checkWidth && count < width ? writeFill(width - count) : 0);
        if (__builtin_expect(output + count + MAX_LENGTH < end, true)) {
            if (count == 1)
                *output++ = *arg;
            else
                output = copy_n(arg, count, output);
        } else
            for (uint chunkSize = static_cast<uint>(buffer + BUFFER_SIZE - output);; chunkSize = BUFFER_SIZE) {
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

    

    inline int write(Detail::Width newWidth) {
        width = newWidth.value;
        return 0;
    }
    inline int write(Detail::Fill newFill) {
        fill = newFill.value;
        return 0;
    }
    inline int write(Detail::Base newBase) {
        base = newBase.value;
        computeBasePower();
        return 0;
    }
    inline int write(Detail::Precision newPrecision) {
        precision = newPrecision.value;
        computeBasePower();
        return 0;
    }
    inline int write(Detail::Delimiter newDelimiter) {
        delimiter = newDelimiter.value;
        return 0;
    }
    

    inline int write() { return 0; }
    inline int write(char arg) { return writeChar(arg); }
    template <class I> inline typename enable_if<is_integral<I>::value && is_unsigned<I>::value, int>::type write(I arg) { return writeT(writeUnsignedInt(arg, end)); }
    template <class I> inline typename enable_if<is_integral<I>::value && is_signed<I>::value, int>::type write(I arg) { return writeT(writeSignedInt(arg, end)); }
    template <class F> inline typename enable_if<is_floating_point<F>::value, int>::type write(F arg) { return writeT(writeFloatingPoint(arg, end)); }
    

    inline int write(const char *arg) { return writeString(arg, strlen(arg)); }
    template <int N> inline int write(char (&arg)[N]) { return writeString(arg, strlen(arg)); }
    inline int write(const string &arg) { return writeString(arg.c_str(), arg.size()); }
    template <class T1, class T2> inline int write(const pair<T1, T2> &arg) {
        int charsWritten = write(arg.first);
        charsWritten += writeDelimiter();
        return charsWritten + write(arg.second);
    }
    template <class T> inline int write(const complex<T> &arg) { return write(real(arg), imag(arg)); }
    

    template <class Iterator, class... Ts> inline typename enable_if<is_iterator<Iterator>::value, int>::type write(Iterator first, Iterator last, Ts &&... args) {
        int charsWritten = 0;
        for (; first != last; charsWritten += ++first == last ? 0 : writeDelimiter()) charsWritten += write(*first);
        return charsWritten + write(forward<Ts>(args)...);
    }
    template <class Iterator, class I, class... Ts> inline typename enable_if<is_iterator<Iterator>::value && is_integral<I>::value, int>::type write(Iterator first, I count, Ts &&... args) {
        return write(first, first + count, forward<Ts>(args)...);
    }
    

    template <class T> inline auto write(const T &arg) -> decltype(arg.write(*this)) { return arg.write(*this); }
    template <class T0, class T1, class... Ts> inline typename enable_if<!is_iterator<T0>::value, int>::type write(T0 &&arg0, T1 &&arg1, Ts &&... args) {
        int charsWritten = write(forward<T0>(arg0));
        return charsWritten + write(forward<T1>(arg1), forward<Ts>(args)...);
    }
};

class OutputFile : public OutputDevice {
    FILE *file;
    bool owner;

    void writeToDevice(uint count) override {
        fwrite(buffer, 1, count, file);
        fflush(file);
    }

  public:
    OutputFile(FILE *file = stdout, bool takeOwnership = false) : file(file), owner(takeOwnership) {}
    OutputFile(const char *fileName) : OutputFile(fopen(fileName, "w"), true) {}
    ~OutputFile() override {
        flush();
        if (owner) fclose(file);
    }
};

class OutputString : public OutputDevice {
    string &str;

    void writeToDevice(uint count) override { str.append(buffer, count); }

  public:
    OutputString(string &str) : OutputDevice(), str(str) {}
    ~OutputString() override { flush(); }
};

unique_ptr<InputDevice> input;
unique_ptr<OutputDevice> output;

template <class... Ts> inline bool read(Ts &&... args) { return input->read(forward<Ts>(args)...); }
template <class... Ts> inline int write(Ts &&... args) { return output->write(forward<Ts>(args)...); }
template <class... Ts> inline int writeln(Ts &&... args) { return write(forward<Ts>(args)..., '\n'); }
void flush() { output->flush(); }



#define SOMET         template <typename T>
#define ARGS          template <typename... Args>
#define KV            template <typename K, typename V>
#define TARGS         template <typename T, typename... Args>
#define SQ(x)         ((x) * (x))
#define PCT           __builtin_popcount
#define CTZ           __builtin_ctz
#define CLZ           __builtin_clz
#define ALL(x)        (x).begin(), (x).end()
#define LLA(x)        (x).rbegin(), (x).rend()
#define MEM(x, val)   fill(&x[0], &x[0] + sizeof(x) / sizeof(x[0]), (val));
#define MEM2D(x, val) fill(&x[0][0], &x[0][0] + sizeof(x) / sizeof(x[0][0]), (val));
#define MEM3D(x, val) fill(&x[0][0][0], &x[0][0][0] + sizeof(x) / sizeof(x[0][0][0]), (val));


#ifdef JJ
#define deb(...) cout << fmt("#%d:|%s| = ", __LINE__, #__VA_ARGS__);debug().write(__VA_ARGS__);
#define pvec(x) cout << fmt("%s= \n", #x);pmat_impl<vector<decltype(x)>>({x});
#define pmat(x) cout << fmt("%s= \n", #x);pmat_impl(x);
#else 
#define deb(...) 9;
#define pvec(x)  9;
#define pmat(x) 9;
#endif
#define div_ceil(x, y) (x/y + (x % y != 0))
#define rechar(...) char __VA_ARGS__; read(__VA_ARGS__);
#define reint(...) int __VA_ARGS__; read(__VA_ARGS__);
#define relld(...) int64_t __VA_ARGS__; read(__VA_ARGS__);
#define restring(...) string __VA_ARGS__; read(__VA_ARGS__);
#define renvec(n, a) int n; read(n); vector<int> a(n); for(int _ = 0; _ < n; ++_) read(a[_]);
#define renvec_lld(n, a) int n; read(n); vector<int64_t> a(n); for(int _ = 0; _ < n; ++_) read(a[_]);
#define revec(n, a) vector<int> a(n); for(int _ = 0; _ < n; ++_) read(a[_]);
#define revec_lld(n, a) vector<int64_t> a(n); for(int _ = 0; _ < n; ++_) read(a[_]);


SOMET using COUPLE = array<T, 2>;
SOMET using TRIPLE = array<T, 3>;
SOMET using QUAD = array<T, 4>;

using Byte = uint8_t;
using LLD = int64_t;
using ULLD = uint64_t;
using UINT = uint32_t;
using PII = pair<int, int>;
using VI = vector<int>;
using VVI = vector<VI>;
using VPII = vector<PII>;
using MII = map<int, int>;
using SI = set<int>;
using VVP = vector<VPII>;
using PLLD = pair<LLD, LLD>;
using VLLD = vector<LLD>;
using VVLLD = vector<VLLD>;
using VPLLD = vector<PLLD>;
using VB = vector<bool>;
using VVB = vector<VB>;
using VCh = vector<char>;
using VVCh = vector<VCh>;
using CI = COUPLE<int>;
using TI = TRIPLE<int>;
using QI = QUAD<int>;
using VCI = vector<CI>;
using VTI = vector<TI>;
using VQI = vector<QI>;

const VPII dirs = {{-1, 0}, {1, 0}, {0, -1}, {-1, 0}};
const int INF = 2147483647 / 2;
const LLD LLDINF = INT64_MAX / 2;















SOMET void dedup(vector<T> &s) {
    sort(ALL(s));
    s.erase(unique(ALL(s)), s.end());
}
template <int D, typename T> struct Vecnd : public vector<Vecnd<D - 1, T>> {
    ARGS Vecnd(int n, Args... args) : vector<Vecnd<D - 1, T>>(n, Vecnd<D - 1, T>(args...)) {}
};
SOMET struct Vecnd<1, T> : public vector<T> {
    Vecnd(int n, const T &val = T()) : vector<T>(n, val) {}
};
SOMET using Vec1d = Vecnd<1, T>;
SOMET using Vec2d = Vecnd<2, T>;
SOMET using Vec3d = Vecnd<3, T>;

SOMET using min_heap = priority_queue<T, vector<T>, greater<T>>;
SOMET using max_heap = priority_queue<T, vector<T>, less<T>>;

#define eni(F, op, ret) SOMET typename enable_if<sizeof(F<T>(0)) op 1, ret>::type
SOMET auto is_streamable(T *ptr) -> decltype(cout << *ptr, 0);
SOMET char is_streamable(...);
struct debug {
    ~debug() {}
    eni(is_streamable, !=, debug &) operator<<(const T &v) { return cout << v, *this; }
    eni(is_streamable, ==, debug &) operator<<(const T &v) {
        *this << "[";
        for (auto it = v.begin(); it != v.end(); ++it) {
            *this << *it;
            if (next(it) != v.end()) *this << ", ";
        }
        return *this << "]";
    }
    KV debug &operator<<(const pair<K, V> &p) { return *this << "(" << p.first << ", " << p.second << ")"; }
    TARGS void write(const T &head, const Args&... tail) { *this << head << " ", write(tail...); }
    void write() { cout << endl; }
};
SOMET auto has_size(T *ptr) -> decltype(ptr->size(), 0);
SOMET char has_size(...);
eni(has_size, !=, int) operator~(const T &container) { return (int)container.size(); }

int log2_floor(uint32_t n) { return 31 - CLZ(n); }
int log2_ceil(uint32_t n) { return log2_floor(n) + !!(n & (n - 1)); }
#define Fn(name, ret, ...) function<ret(__VA_ARGS__)> name = [&](__VA_ARGS__) -> ret
class Rng {
    mt19937 mtgen;
    uniform_int_distribution<int> dist_;

  public:
    Rng(int min, int max, size_t seed = random_device()()) : mtgen(seed), dist_(min, max) {}
    int operator()() { return dist_(mtgen); }
};

SOMET void pmat_impl(const T &v) {
    int h = v.size(), w = v[0].size(), z = 3;
    for (int i = 0; i < h; ++i) { w = max(w, (int)v[i].size()); }
    cout << "\n" << setw(z) << "+";
    for (int j = 0; j < w; ++j) cout << setw(z) << j << " \n"[j == (w - 1)];
    for (int i = 0; i < h; ++i) {
        cout << setw(z) << i;
        for (int j = 0; j < v[i].size(); ++j) cout << setw(z) << v[i][j] << " \n"[j == (v[i].size() - 1)];
    }
    cout << "\n";
}
ARGS string fmt(const string &format, const Args &... args) {
    size_t size = snprintf(nullptr, 0, format.c_str(), args...) + 1;
    if (size <= 0) { throw runtime_error("Error during formatting."); }

    unique_ptr<char[]> buf(new char[size]);
    snprintf(buf.get(), size, format.c_str(), args...);
    return string(buf.get(), buf.get() + size - 1);
}
SOMET void read(T &x) { cin >> x; }
template <typename T, typename... Args> void read(T &head, Args &... tail) { read(head), read(tail...); }





#define OTC

struct Fenw {
    int n;
    vector<int> bit;
    Fenw(int _n) : n(_n + 1) { bit.resize(n, 0); }
    void add(int idx, int val) {
        for (++idx; idx < n; idx += idx & (-idx)) { bit[idx] += val; }
    }
    int sum(int r) {
        int res = 0;
        for (++r; r > 0; r -= r & -r) { res += bit[r]; }
        return res;
    }
    int sum(int l, int r) { return sum(r) - sum(l - 1); }
};

const int mx = 1e6 + 1;
using FValT = int;
int bit[mx + 1]; 
struct FenwickTree {
    

    int n;
    FenwickTree(int _n) : n(_n + 1) {}
    FenwickTree(vector<FValT> &A) : FenwickTree(A.size()) {
        for (int i = 0; i < A.size(); ++i) add(i, A[i]);
    }
    FValT sum(int idx) {
        FValT ret = 0;
        for (++idx; idx > 0; idx -= idx & -idx) ret += bit[idx];
        return ret;
    }
    FValT sum(int l, int r) { return sum(r) - sum(l - 1); }
    void add(int idx, FValT delta) {
        for (++idx; idx < n; idx += idx & -idx) bit[idx] += delta;
    }
    int lower_bound(FValT val) {
        int logn = 31 - __builtin_clz(n), p = 0;
        for (int i = logn; i >= 0; --i) {
            int q = p | (1 << i);
            if (q < n and bit[q] < val) { p = q, val -= bit[q]; }
        }
        return p + 1;
    }
};

static char ibuf[1<<20|1], *p1 = ibuf, *p2 = ibuf;
inline void fastscan(int &x)
{
    bool neg = false;
    int c;
    x = 0;
    c = getchar();
    if (c == '-') {
        neg = true;
        c = getchar();
    }
    for (; (c > 47 && c < 58); c = getchar()) x = (x << 1) + (x << 3) + c - 48;
    if (neg) x *= -1;
}

struct IO {
    inline char gc() { return p1 == p2 && (p2 = (p1 = ibuf) + fread(ibuf, 1, 1 << 20 | 1, stdin), p1 == p2) ? EOF : *p1++; }

    template <typename T> inline IO operator>>(T &n) {
        n = 0;
        bool s = 0;
        char c = gc();
        while (c < '0' || c > '9') s |= c == '-', c = gc();
        while (c >= '0' && c <= '9') n = n * 10 + (c ^ 48), c = gc();
        s && (n = -n);
        return *this;
    }
} fcin;
int A[mx], X[mx]; 

void soln(int __ntc, int __tc) {
    int n, q;
    

    fcin >> n >> q;
    FenwickTree ft(mx);
    for (int i = 0; i < n; ++i) {
        

        fcin >> A[i];
    }
    for(int i = 0; i< q; ++i){
        

        fcin >> X[i];
    }
    for (int i = 0; i < n; ++i) {
        ft.add(A[i], 1);
    }
    for(int i = 0; i< q; ++i){
        int k = X[i];
        if (k > 0) {
            ft.add(k, 1);
        } else {
            k = -k;
            int z = ft.lower_bound(k);
            ft.add(z-1, -1);
        }
    }
    int idx = ft.lower_bound(1);
    if (idx == ft.n) {
        cout << 0 << '\n';
    } else {
        cout << idx-1 << '\n';
    }
}

int Solver() {
#ifndef JJ
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#endif
#ifdef OTC
    soln(1, 1);
#else
    int tc;
    cin >> tc;
    for (int i = 0; i < tc; ++i) {
#ifdef JJ
        cout << fmt("Test case=%d/%d", i+1, tc) << endl;
#endif
        soln(tc, i + 1);
    }
#endif
    return 0;
}

#ifndef HEADLESS
signed main() { Solver(); }
#endif





