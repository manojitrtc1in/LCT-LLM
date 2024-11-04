










using namespace std;




using ll = long long;
using ull = unsigned long long;
using li = __int128;
using uli = unsigned __int128;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;

void doReplace() {
}

template <typename T, typename U, typename...Vs>
void doReplace(T& t, const U& u, Vs&&...vs) {
    t = u;
    doReplace(vs...);
}

template <typename T, typename...Us>
T minim(T& was, const T& cand, Us&&...us) {
    if (was > cand) {
        was = cand;
        doReplace(us...);
    }
    return was;
}

template <typename T, typename...Us>
T maxim(T& was, const T& cand, Us&&...us) {
    if (was < cand) {
        was = cand;
        doReplace(us...);
    }
    return was;
}





template <typename D>
D dPower(D base, ll exponent) {
    if (exponent < 0) {
        return dPower(1 / base, -exponent);
    }
    if (exponent == 0) {
        return 1;
    }
    if ((exponent & 1) == 1) {
        return dPower(base, exponent - 1) * base;
    } else {
        D res = dPower(base, exponent >> 1);
        return res * res;
    }
}








class NumberIterator : iterator<forward_iterator_tag, int> {
public:
    int v;

    NumberIterator(int v) : v(v) {}

    operator int &() { return v; }

    int operator*() { return v; }
};

class range : pii {
public:
    range(int begin, int end) : pii(begin, max(begin, end)) {}

    range(int n) : pii(0, max(0, n)) {}

    NumberIterator begin() {
        return first;
    }

    NumberIterator end() {
        return second;
    }
};


template <typename T>
class arr {
    T* b;
    int n;

    void allocate(int sz) {

        if (sz < 0) {
            throw "bad alloc";
        }

        n = sz;
        if (sz > 0) {
            b = (T*)(::operator new(sz * sizeof(T)));
        } else {
            b = nullptr;
        }
    }

public:
    arr(int n = 0) {
        allocate(n);

        view();

    }

    arr(int n, const T& init) {
        allocate(n);
        for (int i : range(n)) {
            ::new((void*)(b + i)) T(init);
        }

        view();

    }

    arr(T* b, int n) : arr(b, b + n) {}
    arr(T* b, T* e) : b(b), n(e - b) {}

    arr(initializer_list<T> l) : arr(l.size()) {
        if (n > 0) {
            memcpy(b, l.begin(), n * sizeof(T));
        }
    }

    int size() const {
        return n;
    }

    T* begin() {
        return b;
    }

    const T* begin() const {
        return b;
    }

    T* end() {
        return b + n;
    }

    const T* end() const {
        return b + n;
    }

    arr<T> clone() const {
        arr<T> res(n);
        copy(b, b + n, res.begin());
        return res;
    }

    T& operator[](int at) {

        if (at < 0 || at >= n) {
            throw "Out of bounds";
        }

        return b[at];
    }

    const T& operator[](int at) const {

        if (at < 0 || at >= n) {
            throw "Out of bounds";
        }

        return b[at];
    }

    bool operator ==(const arr& other) const {
        if (n != other.n) {
            return false;
        }
        for (int i : range(n)) {
            if (b[i] != other.b[i]) {
                return false;
            }
        }
        return true;
    }

    vector<T> view() {
        return vector<T>(b, b + n);
    }

    arr<T> subArray(int from, int to) const {
        return arr<T>(b + from, b + to);
    }
};

typedef arr<int> arri;

void id5() {}

template <typename T, class...Vs>
void id5(arr<T>& array, Vs&...vs) {
    int n = array.size();
    for (int i : range(n)) {
        array[i]--;
    }
    id5(vs...);
}







template <typename T>
class id3 {
    T* b;
    int d1;
    int d2;
    int sz;

    void allocate(int n) {

        if (n < 0) {
            throw "bad alloc";
        }

        if (n > 0) {
            b = (T*)(::operator new(n * sizeof(T)));
        } else {
            b = nullptr;
        }
    }

public:
    explicit id3(int d1 = 0, int d2 = 0) : d1(d1), d2(d2), sz(d1 * d2) {

        if (d1 < 0 || d2 < 0) {
            throw "bad alloc";
        }

        allocate(sz);

        view();

    }

    id3(int d1, int d2, const T& init) : d1(d1), d2(d2), sz(d1 * d2) {

        if (d1 < 0 || d2 < 0) {
            throw "bad alloc";
        }

        allocate(sz);
        for (int i : range(sz)) {
            ::new((void*)(b + i)) T(init);
        }

        view();

    }

    id3(T* b, int d1, int d2) : b(b), d1(d1), d2(d2), sz(d1 * d2) {}

    int size() const {
        return sz;
    }

    int dim1() const {
        return d1;
    }

    int dim2() const {
        return d2;
    }

    T* begin() {
        return b;
    }

    T* end() {
        return b + sz;
    }

    T& operator()(int i1, int i2) {

        if (i1 < 0 || i1 >= d1 || i2 < 0 || i2 >= d2) {
            throw "Out of bounds";
        }

        return b[i1 * d2 + i2];
    }

    const T& operator()(int i1, int i2) const {

        if (i1 < 0 || i1 >= d1 || i2 < 0 || i2 >= d2) {
            throw "Out of bounds";
        }

        return b[i1 * d2 + i2];
    }

    T& operator[](const pii& p) {
        return operator()(p.first, p.second);
    }

    const T& operator[](const pii& p) const {
        return operator()(p.first, p.second);
    }

    arr<T> operator[](int at) {

        if (at < 0 || at >= d1) {
            throw "Out of bounds";
        }

        return arr<T>(b + at * d2, d2);
    }

    vector<vector<T>> view() {
        vector<vector<T>> res(min(d1, 50));
        for (int i : range(res.size())) {
            res[i] = (*this)[i].view();
        }
        return res;
    }

};



inline bool isWhitespace(int c) {
    return isspace(c) || c == EOF;
}

class Input {
private:
    bool id2 = false;
    int bufSize = 4096;
    char* buf = new char[bufSize];
    int bufRead = 0;
    int bufAt = 0;

public:
    inline int get() {
        if (id2) {

            throw "Input id2";

            return EOF;
        }
        if (bufRead == bufAt) {
            bufRead = fread(buf, sizeof(char), bufSize, stdin);
            bufAt = 0;
        }
        if (bufRead == bufAt) {
            id2 = true;
            return EOF;
        }
        return buf[bufAt++];
    }

    inline int peek() {
        if (id2) {
            return EOF;
        }
        if (bufRead == bufAt) {
            bufRead = fread(buf, sizeof(char), bufSize, stdin);
            bufAt = 0;
        }
        if (bufRead == bufAt) {
            id2 = true;
            getchar();
            return EOF;
        }
        return buf[bufAt];
    }

private:
    template<typename T>
    inline T readInteger() {
        int c = skipWhitespace();
        int sgn = 1;
        if (c == '-') {
            sgn = -1;
            c = get();
        } else if (c == '+') {
            c = get();
        }
        T res = 0;
        do {
            if (!isdigit(c)) {

                throw "Number format error";

                return sgn * res;
            }
            res *= 10;
            res += c - '0';
            c = get();
        } while (!isWhitespace(c));
        return res * sgn;
    }

    void initArrays(int) {}

    template <typename T, class...Vs>
    void initArrays(int n, arr<T>& array, Vs&...vs) {
        array = arr<T>(n);
        initArrays(n, vs...);
    }

    template <typename T, class...Vs>
    void initArrays(int n, vector<T>&, Vs&...vs) {
        initArrays(n, vs...);
    }

    void readImpl(int) {}

    template <typename T, class...Vs>
    void readImpl(int i, arr<T>& arr, Vs&...vs) {
        arr[i] = readType<T>();
        readImpl(i, vs...);
    }

    template <typename T, class...Vs>
    void readImpl(int i, vector<T>& arr, Vs&...vs) {
        arr.push_back(readType<T>());
        readImpl(i, vs...);
    }

public:
    inline int skipWhitespace() {
        int c;
        while (isWhitespace(c = get()) && c != EOF);
        return c;
    }

    inline int peekNext() {
        while (isWhitespace(peek()) && peek() != EOF) {
            get();
        }
        return peek();
    }

    inline int readInt() {
        return readInteger<int>();
    }

    inline ll readLong() {
        return readInteger<ll>();
    }

    inline unsigned readUnsigned() {
        return readInteger<unsigned>();
    }

    string readString() {
        int c = skipWhitespace();
        if (c == EOF) {

            throw "Input id2";

            return "";
        }
        string res;
        do {
            res.push_back(c);
        } while (!isWhitespace(c = get()));
        return res;
    }

    arri readIntArray(int size) {
        return readArray<int>(size);
    }

    arr<ll> readLongArray(int size) {
        return readArray<ll>(size);
    }

    arr<double> readDoubleArray(int size) {
        return readArray<double>(size);
    }

    arr<string> readStringArray(int size) {
        return readArray<string>(size);
    }

    arr<char> readCharArray(int size) {
        return readArray<char>(size);
    }

    template<typename T>
    T readType() {
        throw "Operation not supported";
    }

    template<typename U, typename V>
    pair<U, V> readType() {
        U first = readType<U>();
        V second = readType<V>();
        return make_pair(first, second);
    }

    template<typename T>
    arr<T> readArray(int n) {
        arr<T> res(n, T());
        for (int i : range(n)) {
            res[i] = readType<T>();
        }
        return res;
    }



    template <class...Vs>
    void readArrays(int n, Vs&...vs) {
        initArrays(n, vs...);
        for (int i : range(n)) {
            readImpl(i, vs...);
        }
    }

    template<typename U, typename V>
    arr<pair<U, V> > readArray(int n) {
        arr<pair<U, V> > res(n);
        for (int i : range(n)) {
            res[i] = readType<U, V>();
        }
        return res;
    }

    template<typename T>
    id3<T> readTable(int rows, int cols) {
        id3<T> result(rows, cols);
        for (int i : range(rows)) {
            for (int j : range(cols)) {
                result(i, j) = readType<T>();
            }
        }
        return result;
    }

    id3<int> readIntTable(int rows, int cols) {
        return readTable<int>(rows, cols);
    }

    id3<char> readCharTable(int rows, int cols) {
        return readTable<char>(rows, cols);
    }

    string readLine() {
        int c = get();
        if (c == EOF) {

            throw "Input id2";

            return "";
        }
        string res;
        while (c != '\n' && c != '\r' && c != EOF) {
            res.push_back(c);
            c = get();
        }
        if (c == '\r' && peek() == '\n') {
            get();
        }
        return res;
    }

    inline double readDouble() {
        int c = skipWhitespace();
        int sgn = 1;
        if (c == '-') {
            sgn = -1;
            c = get();
        }
        double res = 0;
        do {
            if (tolower(c) == 'e') {
                return sgn * res * dPower(double(10), readInt());
            }
            if (!isdigit(c)) {

                throw "Number format error";

                return sgn * res;
            }
            res *= 10;
            res += c - '0';
            c = get();
        } while (!isWhitespace(c) && c != '.');
        if (c == '.') {
            double add = 0;
            int length = 0;
            c = get();
            do {
                if (tolower(c) == 'e') {
                    return sgn * (res + add * dPower(double(10), -length)) * dPower(double(10), readInt());
                }
                if (!isdigit(c)) {

                    throw "Number format error";

                    res += add * dPower(10, -length);
                    return res * sgn;
                }
                add *= 10;
                add += c - '0';
                length++;
                c = get();
            } while (!isWhitespace(c));
            res += add * dPower(double(10), -length);
        }
        return res * sgn;
    }

    inline char readChar() {
        int c = skipWhitespace();
        if (c == EOF) {

            throw "Input id2";

            return 0;
        }
        return c;
    }

    inline bool isExhausted() { return id2; }

    inline void setBufSize(int id4) {
        if (id4 > bufSize) {
            char* newBuf = new char[id4];
            memcpy(newBuf, buf, bufSize);
            buf = newBuf;
        }
        bufSize = id4;
    }
};

template<>
inline double Input::readType() {
    return readDouble();
}

template<>
inline int Input::readType() {
    return readInt();
}

template<>
inline ll Input::readType() {
    return readLong();
}

template<>
inline unsigned Input::readType() {
    return readUnsigned();
}

template<>
inline char Input::readType() {
    return readChar();
}

template<>
inline string Input::readType() {
    return readString();
}

Input in;







class Output {
private:
    ostream* out;

    template<typename T>
    inline void printSingle(const T& value) {
        *out << value;
    }

    template<typename T>
    void printSingle(const vector<T>& array) {
        size_t n = array.size();
        for (int i : range(n)) {
            *out << array[i];
            if (i + 1 != n) {
                *out << ' ';
            }
        }
    }

    template<typename T>
    void printSingle(const arr<T>& array) {
        int n = array.size();
        for (int i : range(n)) {
            *out << array[i];
            if (i + 1 != n) {
                *out << ' ';
            }
        }
    }

    template<typename T>
    void printSingle(const id3<T>& array) {
        size_t n = array.dim1();
        size_t m = array.dim2();
        for (int i : range(n)) {
            for (int j : range(m)) {
                *out << array(i, j);
                if (j + 1 != m) {
                    *out << ' ';
                }
            }
            if (i + 1 != n) {
                *out << '\n';
            }
        }
    }

    template<typename T, typename U>
    inline void printSingle(const pair<T, U>& value) {
        *out << value.first << ' ' << value.second;
    }

public:
    bool id11;

    Output(ostream& out, bool id11) : out(&out), id11(id11) {
        setPrecision(20);
    }

    void setOut(ostream& nOut) {
        out = &nOut;
        setPrecision(20);
    }

    inline void print() {}

    template<typename T, typename...Targs>
    inline void print(const T& first, const Targs... args) {
        printSingle(first);
        if (sizeof...(args) != 0) {
            *out << ' ';
            print(args...);
        }
        if (id11) {
            flush();
        }
    }

    template<typename...Targs>
    inline void printLine(const Targs... args) {
        print(args...);
        *out << '\n';
        if (id11) {
            flush();
        }
    }

    inline void flush() {
        out->flush();
    }

    inline void setPrecision(int digs) {
        *out << fixed << setprecision(digs);
    }
};

Output out(cout, false);
Output err(cerr, true);











const int MOD7 = 1000000007;
const int MOD9 = 1000000009;
const int MODF = 998244353;

int mod = MOD7;

ll gcd(ll a, ll b, ll& x, ll& y) {
    if (a == 0) {
        x = 0;
        y = 1;
        return b;
    }
    int d = gcd(b % a, a, y, x);
    x -= (b / a) * y;
    return d;
}

class modint {
public:
    int n;
    modint() : n(0) {}
    modint(ll n, bool special = false) {
        if (special) {
            this->n = -1;
            return;
        }
        if (n >= 0 && n < mod) {
            this->n = n;
            return;
        }
        n %= mod;
        if (n < 0) {
            n += mod;
        }
        this->n = n;
    }
    modint& operator +=(const modint& other) {

        if (n == -1 || other.n == -1) {
            throw "Illegal state";
        }

        n += other.n;
        if (n >= mod) {
            n -= mod;
        }
        return *this;
    }
    modint& operator -=(const modint& other) {

        if (n == -1 || other.n == -1) {
            throw "Illegal state";
        }

        n -= other.n;
        if (n < 0) {
            n += mod;
        }
        return *this;
    }
    modint& operator *=(const modint& other) {

        if (n == -1 || other.n == -1) {
            throw "Illegal state";
        }

        n = ll(n) * other.n % mod;
        return *this;
    }
    modint& operator /=(const modint& other) {

        if (other.n == 0) {
            throw "Division by zero";
        }
        if (n == -1 || other.n == -1) {
            throw "Illegal state";
        }

        return *this *= other.inverse();
    }
    modint operator -() {

        if (n == -1) {
            throw "Illegal state";
        }

        if (n == 0) {
            return 0;
        }
        return modint(mod - n);
    }
    modint inverse() const {

        if (n == -1) {
            throw "Illegal state";
        }

        ll x, y;
        ll g = gcd(ll(n), ll(mod), x, y);

        if (g != 1) {
            throw "not inversable";
        }

        return x;
    }
    int log(modint alpha);
};

modint id9(-1, true);

modint operator +(const modint& a, const modint& b) {
    return modint(a) += b;
}

modint operator -(const modint& a, const modint& b) {
    return modint(a) -= b;
}

modint operator *(const modint& a, const modint& b) {
    return modint(a) *= b;
}

modint operator /(const modint& a, const modint& b) {
    return modint(a) /= b;
}

ostream& operator <<(ostream& out, const modint& v) {
    return out << v.n;
}

bool operator==(const modint& a, const modint& b) {
    return a.n == b.n;
}

bool operator!=(const modint& a, const modint& b) {
    return a.n != b.n;
}

namespace std {
    template <>
    struct hash<modint> {
        size_t operator ()(const modint& n) const {
            return n.n;
        }
    };
}

int modint::log(modint alpha) {

    if (n == -1 || alpha.n == -1) {
        throw "Illegal state";
    }

    unordered_map<modint, int> base;
    int exp = 0;
    modint pow = 1;
    modint inv = *this;
    modint alInv = alpha.inverse();
    while (exp * exp < mod) {
        if (inv == 1) {
            return exp;
        }
        base[inv] = exp++;
        pow *= alpha;
        inv *= alInv;
    }
    modint step = pow;
    for (int i = 1; ; i++) {
        if (base.count(pow)) {
            return exp * i + base[pow];
        }
        pow *= step;
    }
}





inline bool isSubset(unsigned set, unsigned subSet) {
    return (set & subSet) == subSet;
}

inline int bitCount(unsigned x) {
    return __builtin_popcount(x);
}

inline int bitCount(ull x) {
    return __builtin_popcountll(x);
}

inline int bitCount(uli x) {
    return __builtin_popcountll(x) + __builtin_popcountll(x >> 64);
}

inline int binaryDigits(unsigned x) {
    return 32 - __builtin_clz(x | 1);
}

inline ull setBit(ull mask, int bit) {

    if (bit < 0 || bit >= 64) {
        throw "Bad index";
    }

    mask |= ull(1) << bit;
    return mask;
}

inline unsigned setBit(unsigned mask, int bit) {

    if (bit < 0 || bit >= 32) {
        throw "Bad index";
    }

    mask |= unsigned(1) << bit;
    return mask;
}

inline uli setBit(uli mask, int bit) {

    if (bit < 0 || bit >= 128) {
        throw "Bad index";
    }

    mask |= uli(1) << bit;
    return mask;
}

inline ull unsetBit(ull mask, int bit) {

    if (bit < 0 || bit >= 64) {
        throw "Bad index";
    }

    mask &= ~(ull(1) << bit);
    return mask;
}

inline unsigned unsetBit(unsigned mask, int bit) {

    if (bit < 0 || bit >= 32) {
        throw "Bad index";
    }

    mask &= ~(unsigned(1) << bit);
    return mask;
}

inline uli unsetBit(uli mask, int bit) {

    if (bit < 0 || bit >= 128) {
        throw "Bad index";
    }

    mask &= ~(uli(1) << bit);
    return mask;
}

inline bool isSet(ull mask, int bit) {

    if (bit < 0 || bit >= 64) {
        throw "Bad index";
    }

    return mask >> bit & 1;
}

inline bool isSet(unsigned mask, int bit) {

    if (bit < 0 || bit >= 32) {
        throw "Bad index";
    }

    return mask >> bit & 1;
}

inline bool isSet(uli mask, int bit) {

    if (bit < 0 || bit >= 128) {
        throw "Bad index";
    }

    return mask >> bit & 1;
}

inline unsigned allBits(int n) {

    if (n < 0 || n >= 32) {
        throw "Bad index";
    }

    return (1u << n) - 1;
}

inline ull id6(int n) {

    if (n < 0 || n >= 64) {
        throw "Bad index";
    }

    return (1ull << n) - 1;
}

inline ull id10(int n) {

    if (n < 0 || n >= 128) {
        throw "Bad index";
    }

    return (uli(1) << n) - 1;
}

inline int id8(unsigned n) {
    return n == 0 ? 32 : __builtin_ctz(n);
}

inline int id7(unsigned n) {
    return id8(~n);
}

inline int id1(unsigned n) {
    return n == 0 ? 32 : __builtin_clz(n);
}

inline int id1(ull n) {
    return n == 0 ? 32 : __builtin_clzl(n);
}

inline int id13(unsigned n) {
    return id1(~n);
}

inline int id13(ull n) {
    return id1(~n);
}





class id0 : public NumberIterator {
public:
    id0(int v) : NumberIterator(v) {}

    id0& operator++() {
        --v;
        return *this;
    }
};

class RevRange : pii {
public:
    RevRange(int begin, int end) : pii(begin - 1, min(begin, end) - 1) {}

    RevRange(int n) : pii(n - 1, min(n, 0) - 1) {}

    id0 begin() {
        return first;
    }

    id0 end() {
        return second;
    }
};


class FBingo {
public:
    void solve() {
        int n = in.readInt();
        auto a = in.readIntTable(n, n);

        mod = 31607;
        int x = modint(10000).inverse().n;
        arri hor(n, 1);
        id3<int> rev(n, n);
        for (int i : range(n)) {
            for (int j : range(n)) {
                a(i, j) *= x;
                a(i, j) %= mod;
                hor[i] *= a(i, j);
                hor[i] %= mod;
                rev(i, j) = modint(a(i, j)).inverse().n;
            }
        }
        int answer = 1;
        arri id12(n + 1);
        arri pMain(n + 1);
        arri pOther(n + 1);
        arri pBoth(n + 1);
        id3<int> vert(1 << n, n, 1);
        for (unsigned j : range(1, 1 << n)) {
            int oneBit;
            for (int i : range(n)) {
                if (isSet(j, i)) {
                    oneBit = i;
                    break;
                }
            }
            for (int i : range(n)) {
                vert(j, i) = vert(unsetBit(j, oneBit), i) * a(oneBit, i) % mod;
            }
        }
        for (unsigned i : range(1 << n)) {
            int base = 1;
            int cnt = 0;
            int baseMain = 1;
            int baseOther = 1;
            int baseBoth = 1;
            for (int j : range(n)) {
                if (isSet(i, j)) {
                    cnt++;
                    base *= hor[j];
                    base %= mod;
                } else {
                    baseMain *= a(j, j);
                    baseMain %= mod;
                    baseBoth *= a(j, j);
                    baseBoth %= mod;
                    baseOther *= a(j, n - j - 1);
                    baseOther %= mod;
                    if (2 * j + 1 != n) {
                        baseBoth *= a(j, n - j - 1);
                        baseBoth %= mod;
                    }
                }
            }
            id12[0] = base;
            pMain[0] = baseMain * base % mod;
            pOther[0] = baseOther * base % mod;
            pBoth[0] = baseBoth * base % mod;
            int other = allBits(n) - i;
            for (int j : range(n)) {
                id12[j + 1] = 0;
                pMain[j + 1] = 0;
                pOther[j + 1] = 0;
                pBoth[j + 1] = 0;
                int cur = vert(other, j);
                int curMain = isSet(i, j) ? cur : cur * rev(j, j) % mod;
                int curOther = isSet(i, n - j - 1) ? cur : cur * rev(n - j - 1, j) % mod;
                int curBoth = isSet(i, j) ? cur : cur * rev(j, j) % mod;
                if (2 * j + 1 != n && !isSet(i, n - j - 1)) {
                    curBoth *= rev(n - j - 1, j);
                    curBoth %= mod;
                }






                for (int k : RevRange(j + 1)) {
                    id12[k + 1] += id12[k] * cur;
                    id12[k + 1] %= mod;
                    pMain[k + 1] += pMain[k] * curMain;
                    pMain[k + 1] %= mod;




                    pOther[k + 1] += pOther[k] * curOther;
                    pOther[k + 1] %= mod;




                    pBoth[k + 1] += pBoth[k] * curBoth;
                    pBoth[k + 1] %= mod;




                }
            }
            for (int j : range(n + 1)) {
                if (((cnt + j) & 1) == 1) {
                    answer += id12[j] + pBoth[j] - pMain[j] - pOther[j];
                } else {
                    answer -= id12[j] + pBoth[j] - pMain[j] - pOther[j];
                }
            }
            answer %= mod;
        }
        if (answer < 0) {
            answer += mod;
        }
        out.printLine(answer);
    }
};


int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    auto time = clock();

    FBingo solver;


    solver.solve();
    fflush(stdout);

    cerr << setprecision(3) << double(clock() - time) / CLOCKS_PER_SEC << endl;

    return 0;
}
