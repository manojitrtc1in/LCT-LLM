



#include <cstdio>
#include <cctype>
#include <string>
#include <cstring>


#include <vector>
#include <functional>

using namespace std;

#define all(v) (v).begin(), (v).end()

using ll = long long;
using ull = unsigned long long;
using li = __int128;
using uli = unsigned __int128;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;

#ifdef LOCAL

void signalHandler(int) {
    throw "Abort detected";
}

#endif

void doReplace() {
}

template <typename T, typename U, typename...Vs>
void doReplace(T& t, const U& u, Vs&& ...vs) {
    t = u;
    doReplace(vs...);
}

template <typename T, typename...Us>
T minim(T& was, const T& cand, Us&& ...us) {
    if (was > cand) {
        was = cand;
        doReplace(us...);
    }
    return was;
}

template <typename T, typename...Us>
T maxim(T& was, const T& cand, Us&& ...us) {
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


#include <algorithm>


class NumberIterator : iterator<forward_iterator_tag, int> {
public:
    int v;

    NumberIterator(int v) : v(v) {}

    operator int&() { return v; }

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
#ifdef LOCAL
        if (sz < 0) {
            throw "bad alloc";
        }
#endif
        n = sz;
        if (sz > 0) {
            b = (T*) (::operator new(sz * sizeof(T)));
        } else {
            b = nullptr;
        }
    }

public:
    arr(int n = 0) {
        allocate(n);
#ifdef LOCAL
        view();
#endif
    }

    arr(int n, const T& init) {
        allocate(n);
        for (int i : range(n)) {
            ::new((void*) (b + i)) T(init);
        }
#ifdef LOCAL
        view();
#endif
    }

    arr(initializer_list<T> l) : arr(l.size()) {
        if (n > 0) {
            memcpy(b, l.begin(), n * sizeof(T));
        }
    }

    arr(T* b, int n) : arr(b, b + n) {}

    arr(T* b, T* e) : b(b), n(e - b) {}

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
#ifdef LOCAL
        if (at < 0 || at >= n) {
            throw "Out of bounds";
        }
#endif
        return b[at];
    }

    const T& operator[](int at) const {
#ifdef LOCAL
        if (at < 0 || at >= n) {
            throw "Out of bounds";
        }
#endif
        return b[at];
    }

    bool operator==(const arr& other) const {
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
        return vector<T>(b, b + min(n, 50));
    }
};

typedef arr<int> arri;

void decreaseByOne() {}

template <typename T, class...Vs>
void decreaseByOne(arr<T>& array, Vs& ...vs) {
    int n = array.size();
    for (int i = 0; i < n; ++i) {
        array[i]--;
    }
    decreaseByOne(vs...);
}

template <typename T, typename U>
void decreaseByOne(arr<pair<T, U>>& v) {
    for (auto& p : v) {
        p.first--;
        p.second--;
    }
}


template <typename T>
class arr2d {
    T* b;
    int d1;
    int d2;
    int sz;

    void allocate(int n) {
#ifdef LOCAL
        if (n < 0) {
            throw "bad alloc";
        }
#endif
        if (n > 0) {
            b = (T*) (::operator new(n * sizeof(T)));
        } else {
            b = nullptr;
        }
    }

public:
    arr2d(int d1 = 0, int d2 = 0) : d1(d1), d2(d2), sz(d1 * d2) {
#ifdef LOCAL
        if (d1 < 0 || d2 < 0) {
            throw "bad alloc";
        }
#endif
        allocate(sz);
#ifdef LOCAL
        view();
#endif
    }

    arr2d(int d1, int d2, const T& init) : d1(d1), d2(d2), sz(d1 * d2) {
#ifdef LOCAL
        if (d1 < 0 || d2 < 0) {
            throw "bad alloc";
        }
#endif
        allocate(sz);
        for (int i : range(sz)) {
            ::new((void*) (b + i)) T(init);
        }
#ifdef LOCAL
        view();
#endif
    }

    arr2d(T* b, int d1, int d2) : b(b), d1(d1), d2(d2), sz(d1 * d2) {}

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
#ifdef LOCAL
        if (i1 < 0 || i1 >= d1 || i2 < 0 || i2 >= d2) {
            throw "Out of bounds";
        }
#endif
        return b[i1 * d2 + i2];
    }

    const T& operator()(int i1, int i2) const {
#ifdef LOCAL
        if (i1 < 0 || i1 >= d1 || i2 < 0 || i2 >= d2) {
            throw "Out of bounds";
        }
#endif
        return b[i1 * d2 + i2];
    }

    arr<T> operator[](int at) {
#ifdef LOCAL
        if (at < 0 || at >= d1) {
            throw "Out of bounds";
        }
#endif
        return arr<T>(b + at * d2, d2);
    }

    vector<vector<T>> view() {
        vector<vector<T>> res(min(d1, 50));
        for (int i = 0; i < res.size(); ++i) {
            res[i] = (*this)[i].view();
        }
        return res;
    }

    arr2d<T> clone() {
        arr2d<T> res(d1, d2);
        copy(b, b + sz, res.b);
        return res;
    }
};


inline bool isWhitespace(int c) {
    return isspace(c) || c == EOF;
}

class Input {
private:
    bool exhausted = false;
    int bufSize = 4096;
    char* buf = new char[bufSize];
    int bufRead = 0;
    int bufAt = 0;

    inline int get() {
        if (exhausted) {
#ifdef LOCAL
            throw "Input exhausted";
#endif
            return EOF;
        }
        if (bufRead == bufAt) {
            bufRead = fread(buf, sizeof(char), bufSize, stdin);
            bufAt = 0;
        }
        if (bufRead == bufAt) {
            exhausted = true;
            return EOF;
        }
        return buf[bufAt++];
    }

    template <typename T>
    inline T readInteger() {
        int c = skipWhitespace();
        int sgn = 1;
        if (c == '-') {
            sgn = -1;
            c = get();
        }
        T res = 0;
        do {
            if (!isdigit(c)) {
#ifdef LOCAL
                throw "Number format error";
#endif
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
    void initArrays(int n, arr<T>& array, Vs& ...vs) {
        array = arr<T>(n, T());
        initArrays(n, vs...);
    }

    template <typename T, class...Vs>
    void initArrays(int n, vector<T>&, Vs& ...vs) {
        initArrays(n, vs...);
    }

    void readImpl(int) {}

    template <typename T, class...Vs>
    void readImpl(int i, arr<T>& arr, Vs& ...vs) {
        arr[i] = readType<T>();
        readImpl(i, vs...);
    }

    template <typename T, class...Vs>
    void readImpl(int i, vector<T>& arr, Vs& ...vs) {
        arr.push_back(readType<T>());
        readImpl(i, vs...);
    }

public:
    inline int skipWhitespace() {
        int c;
        while (isWhitespace(c = get()) && c != EOF);
        if (c == EOF) {
            exhausted = true;
        }
        return c;
    }

    inline int readInt() {
        return readInteger<int>();
    }

    ll readLong() {
        return readInteger<ll>();
    }

    string readString() {
        int c = skipWhitespace();
        if (c == EOF) {
#ifdef LOCAL
            throw "Input exhausted";
#endif
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

    template <typename T>
    T readType() {
        throw "Operation not supported";
    }

    template <typename U, typename V>
    pair<U, V> readType() {
        U first = readType<U>();
        V second = readType<V>();
        return make_pair(first, second);
    }

    template <typename T>
    arr<T> readArray(int n) {
        arr<T> res(n, T());
        for (int i = 0; i < n; i++) {
            res[i] = readType<T>();
        }
        return res;
    }


    template <class...Vs>
    void readArrays(int n, Vs& ...vs) {
        initArrays(n, vs...);
        for (int i = 0; i < n; i++) {
            readImpl(i, vs...);
        }
    }

    template <typename U, typename V>
    arr<pair<U, V>> readArray(int n) {
        arr<pair<U, V>> res(n);
        for (int i = 0; i < n; i++) {
            res[i] = readType<U, V>();
        }
        return res;
    }

    template <typename T>
    arr2d<T> readTable(int rows, int cols) {
        arr2d<T> result(rows, cols);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                result(i, j) = readType<T>();
            }
        }
        return result;
    }

    arr2d<int> readIntTable(int rows, int cols) {
        return readTable<int>(rows, cols);
    }

    arr2d<char> readCharTable(int rows, int cols) {
        return readTable<char>(rows, cols);
    }

    string readLine() {
        int c = get();
        if (c == EOF) {
#ifdef LOCAL
            throw "Input exhausted";
#endif
            return "";
        }
        string res;
        do {
            res.push_back(c);
            c = get();
        } while (c != '\n' && c != '\r' && c != EOF);
        return res;
    }

    double readDouble() {
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
#ifdef LOCAL
                throw "Number format error";
#endif
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
#ifdef LOCAL
                    throw "Number format error";
#endif
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

    char readChar() {
        int c = skipWhitespace();
        if (c == EOF) {
#ifdef LOCAL
            throw "Input exhausted";
#endif
            return 0;
        }
        return c;
    }

    bool isExhausted() { return exhausted; }

    void setBufSize(int newBufSize) {
        if (newBufSize > bufSize) {
            char* newBuf = new char[newBufSize];
            memcpy(newBuf, buf, bufSize);
            buf = newBuf;
        }
        bufSize = newBufSize;
    }
};

template <>
double Input::readType() {
    return readDouble();
}

template <>
int Input::readType() {
    return readInt();
}

template <>
ll Input::readType() {
    return readLong();
}

template <>
char Input::readType() {
    return readChar();
}

template <>
string Input::readType() {
    return readString();
}

Input in;


#include <iostream>
#include <iomanip>


class Output {
private:
    ostream& out = cout;

    template <typename T>
    void printSingle(const T& value) {
        out << value;
    }

    template <typename T>
    void printSingle(const vector<T>& array) {
        size_t n = array.size();
        for (int i = 0; i < n; ++i) {
            out << array[i];
            if (i + 1 != n) {
                out << ' ';
            }
        }
    }

    template <typename T>
    void printSingle(const arr<T>& array) {
        size_t n = array.size();
        for (int i = 0; i < n; ++i) {
            out << array[i];
            if (i + 1 != n) {
                out << ' ';
            }
        }
    }

    template <typename T>
    void printSingle(const arr2d<T>& array) {
        size_t n = array.dim1();
        size_t m = array.dim2();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                out << array(i, j);
                if (j + 1 != m) {
                    out << ' ';
                }
            }
            if (i + 1 != n) {
                out << '\n';
            }
        }
    }

    template <typename T, typename U>
    void printSingle(const pair<T, U>& value) {
        out << value.first << ' ' << value.second;
    }

public:
    Output() {

        out << fixed << setprecision(20);
    }

    void print() {}

    template <typename T, typename...Targs>
    void print(const T& first, const Targs... args) {
        printSingle(first);
        if (sizeof...(args) != 0) {
            out << ' ';
            print(args...);
        }
    }

    template <typename...Targs>
    void printLine(const Targs... args) {
        print(args...);
        out << '\n';
    }

    void flush() {
        out.flush();
    }

    void setPrecision(int digs) {
        out << fixed << setprecision(digs);
    }
};

Output out;


#include <random>


#include <ostream>
#include <unordered_map>


const int MOD7 = 1000000007;
const int MOD9 = 1000000009;
const int MODF = 998244353;

int mod = MOD7;

template <typename T>
T gcd(T a, T b, T& x, T& y) {
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

    modint& operator+=(const modint& other) {
#ifdef LOCAL
        if (n == -1 || other.n == -1) {
            throw "Illegal state";
        }
#endif
        n += other.n;
        if (n >= mod) {
            n -= mod;
        }
        return *this;
    }

    modint& operator-=(const modint& other) {
#ifdef LOCAL
        if (n == -1 || other.n == -1) {
            throw "Illegal state";
        }
#endif
        n -= other.n;
        if (n < 0) {
            n += mod;
        }
        return *this;
    }

    modint& operator*=(const modint& other) {
#ifdef LOCAL
        if (n == -1 || other.n == -1) {
            throw "Illegal state";
        }
#endif
        n = ll(n) * other.n % mod;
        return *this;
    }

    modint& operator/=(const modint& other) {
#ifdef LOCAL
        if (other.n == 0) {
            throw "Division by zero";
        }
        if (n == -1 || other.n == -1) {
            throw "Illegal state";
        }
#endif
        return *this *= other.inverse();
    }

    modint operator-() {
#ifdef LOCAL
        if (n == -1) {
            throw "Illegal state";
        }
#endif
        if (n == 0) {
            return 0;
        }
        return modint(mod - n);
    }

    modint inverse() const {
#ifdef LOCAL
        if (n == -1) {
            throw "Illegal state";
        }
#endif
        ll x, y;
        ll g = gcd(ll(n), ll(mod), x, y);
#ifdef LOCAL
        if (g != 1) {
            throw "not inversable";
        }
#endif
        return x;
    }

    int log(modint alpha);
};

modint nullModint(-1, true);

modint operator+(const modint& a, const modint& b) {
    return modint(a) += b;
}

modint operator-(const modint& a, const modint& b) {
    return modint(a) -= b;
}

modint operator*(const modint& a, const modint& b) {
    return modint(a) *= b;
}

modint operator/(const modint& a, const modint& b) {
    return modint(a) /= b;
}

ostream& operator<<(ostream& out, const modint& val) {
    return out << val.n;
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
        size_t operator()(const modint& n) const {
            return n.n;
        }
    };
}

int modint::log(modint alpha) {
#ifdef LOCAL
    if (n == -1 || alpha.n == -1) {
        throw "Illegal state";
    }
#endif
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
    for (int i = 1;; i++) {
        if (base.count(pow)) {
            return exp * i + base[pow];
        }
        pow *= step;
    }
}


vector<bool> primalityTable(int n) {
    vector<bool> res(n, true);
    if (n > 0) {
        res[0] = false;
    }
    if (n > 1) {
        res[1] = false;
    }
    for (int i = 2; i * i < n; i++) {
        if (res[i]) {
            for (int j = i * i; j < n; j += i) {
                res[j] = false;
            }
        }
    }
    return res;
}

arri divisorTable(int n) {
    arri res(n, 0);
    if (n > 1) {
        res[1] = 1;
    }
    for (int i = 2; i < n; i++) {
        if (res[i] == 0) {
            res[i] = i;
            if (ll(i) * i < n) {
                for (int j = i * i; j < n; j += i) {
                    res[j] = i;
                }
            }
        }
    }
    return res;
}

vi primes(int n) {
    auto isPrime = primalityTable(n);
    vi res;
    for (int i = 0; i < n; ++i) {
        if (isPrime[i]) {
            res.push_back(i);
        }
    }
    return res;
}

bool isPrime(long n) {
    if (n < 2) {
        return false;
    }
    for (long i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

ll nextPrime(ll n) {
    if (n <= 2) {
        return 2;
    }
    n += 1 - (n & 1);
    while (!isPrime(n)) {
        n += 2;
    }
    return n;
}


namespace string_hash {
    bool initDone = false;
    int firstMod;
    int secondMod;
    modint multiplier;
    modint firstRevMultiplier;
    modint secondRevMultiplier;

    void stringHashInit() {
        int wasMod = mod;
        random_device rd;
        mt19937_64 gen(rd());
        firstMod = nextPrime(500000000 + gen() % 500000000);
        secondMod = nextPrime(500000000 + gen() % 500000000);
        mod = firstMod;
        multiplier = 257 + gen() % (500000000 - 257);
        firstRevMultiplier = multiplier.inverse();
        mod = secondMod;
        secondRevMultiplier = multiplier.inverse();
        mod = wasMod;
        initDone = true;
    }


    vector<modint> firstRevPow;
    vector<modint> secondRevPow;
    vector<modint> firstPower;
    vector<modint> secondPower;

    void ensureCapacity(int n) {
        int wasMod = mod;
        mod = firstMod;
        while (firstRevPow.size() < n) {
            if (firstRevPow.empty()) {
                firstRevPow.push_back(1);
            } else {
                firstRevPow.push_back(firstRevPow.back() * firstRevMultiplier);
            }
        }
        while (firstPower.size() < n) {
            if (firstPower.empty()) {
                firstPower.push_back(1);
            } else {
                firstPower.push_back(firstPower.back() * multiplier);
            }
        }
        mod = secondMod;
        while (secondRevPow.size() < n) {
            if (secondRevPow.empty()) {
                secondRevPow.push_back(1);
            } else {
                secondRevPow.push_back(secondRevPow.back() * secondRevMultiplier);
            }
        }
        while (secondPower.size() < n) {
            if (secondPower.empty()) {
                secondPower.push_back(1);
            } else {
                secondPower.push_back(secondPower.back() * multiplier);
            }
        }
        mod = wasMod;
    }
}

class StringHash {
    arr<modint> firstHash;
    arr<modint> secondHash;

    template <typename Collection>
    void doPower(arr<modint>& hash, int cMod, const Collection& str) {
        using namespace string_hash;
        int wasMod = mod;
        mod = cMod;
        hash = arr<modint>(str.size() + 1);
        hash[0] = 0;
        modint power = 1;
        for (int i : range(str.size())) {
            hash[i + 1] = hash[i] + str[i] * power;
            power *= multiplier;
        }
        mod = wasMod;
    }

public:
    template <typename Collection>
    explicit StringHash(const Collection& str) {
        using namespace string_hash;
        if (!initDone) {
            stringHashInit();
        }
        ensureCapacity(str.size() + 1);
        doPower(firstHash, firstMod, str);
        doPower(secondHash, secondMod, str);
    }

    ll hash(int from, int to) const {
#ifdef LOCAL
        if (from < 0 || to < from || to > length()) {
            throw "Out of bounds";
        }
#endif
        using namespace string_hash;
        int wasMod = mod;
        mod = firstMod;
        ll first = ((firstHash[to] - firstHash[from]) * firstRevPow[from]).n;
        mod = secondMod;
        ll second = ((secondHash[to] - secondHash[from]) * secondRevPow[from]).n;
        mod = wasMod;
        return (first << 32) + second;
    }

    int length() const {
        return firstHash.size() - 1;
    }

    ll hash(int from) const {
        return hash(from, length());
    }
};

template <class Hash>
struct SubstringHash {
    const Hash& base;
    const int from;
    const int to;

    SubstringHash(const Hash& base, int from, int to) : base(base), from(from), to(to) {}

    SubstringHash(const Hash& base, int from) : SubstringHash(base, from, base.length()) {}

    ll hash(int from, int to) const {
#ifdef LOCAL
        if (from < 0 || to < from || to > length()) {
            throw "Out of bounds";
        }
#endif
        return base.hash(from + this->from, to + this->to);
    }

    int length() const {
        return to - from;
    }

    ll hash(int from) const {
        return hash(from, length());
    }
};

template <class Hash>
SubstringHash<Hash> substringHash(const Hash& base, int from, int to) {
    return SubstringHash<Hash>(base, from, to);
}

template <class Hash>
SubstringHash<Hash> substringHash(const Hash& base, int from) {
    return SubstringHash<Hash>(base, from);
}

template <class Hash1, class Hash2>
struct CompositeHash {
    const Hash1& base1;
    const Hash2& base2;

    CompositeHash(const Hash1& base1, const Hash2& base2) : base1(base1), base2(base2) {
        using namespace string_hash;
        ensureCapacity(base1.length() + 1);
    }

    ll hash(int from, int to) {
#ifdef LOCAL
        if (from < 0 || to < from || to > length()) {
            throw "Out of bounds";
        }
#endif
        using namespace string_hash;
        if (to <= base1.length()) {
            return base1.hash(from, to);
        }
        if (from >= base1.length()) {
            return base2.hash(from - base1.length(), to - base1.length());
        }
        ll h1 = base1.hash(from);
        ll h2 = base2.hash(0, to - base1.length());
        int wasMod = mod;
        mod = firstMod;
        ll first = (modint(h1 >> 32) * firstPower[base1.length() - from] + modint(h2 >> 32)).n;
        mod = secondMod;
        ll second = (modint(h1 & numeric_limits<unsigned>::max()) * firstPower[base1.length() - from] +
                     modint(h2 & numeric_limits<unsigned>::max())).n;
        mod = wasMod;
        return (first << 32) + second;
    }

    int length() const {
        return base1.length() + base2.length();
    }

    ll hash(int from) const {
        return hash(from, length());
    }
};

template <class Hash1, class Hash2>
CompositeHash<Hash1, Hash2> compositeHash(const Hash1& base1, const Hash2& base2) {
    return CompositeHash<Hash1, Hash2>(base1, base2);
}


class TaskF {
public:
    void solve() {
        int n = in.readInt();
        int k = in.readInt();
        auto s = in.readIntArray(n);

        using namespace string_hash;

        stringHashInit();
        ensureCapacity(n + 1);
        struct part {
            int from;
            int to;
            arri& arr;
            bool isBad;
            vector<modint> inHash1;
            vector<modint> inHash2;
            vector<modint> outHash1;
            vector<modint> outHash2;

            modint getIn1(int f, int t) {
                mod = firstMod;
                return (inHash1[t] - inHash1[f]) * firstRevPow[f];
            }

            modint getIn2(int f, int t) {
                mod = secondMod;
                return (inHash2[t] - inHash2[f]) * secondRevPow[f];
            }

            modint getOut1(int f, int t) {
                mod = firstMod;
                return (outHash1[t] - firstPower[t - f] * outHash1[f]);
            }

            modint getOut2(int f, int t) {
                mod = secondMod;
                return (outHash2[t] - secondPower[t - f] * outHash2[f]);
            }

            void rebuild() {
                inHash1.resize(1);
                inHash2.resize(1);
                outHash1.resize(1);
                outHash2.resize(1);
                isBad = false;
                for (int i : range(from, to)) {
                    if (arr[i] > 0) {
                        mod = firstMod;
                        inHash1.push_back(inHash1.back() + firstPower[inHash1.size() - 1] * arr[i]);
                        mod = secondMod;
                        inHash2.push_back(inHash2.back() + secondPower[inHash2.size() - 1] * arr[i]);
                    } else {
                        if (inHash1.size() > 1) {
                            modint last1 = getIn1(inHash1.size() - 2, inHash1.size() - 1);
                            modint last2 = getIn2(inHash2.size() - 2, inHash2.size() - 1);
                            if (last1.n != -arr[i] || last2.n != -arr[i]) {
                                isBad = true;
                                return;
                            }
                            inHash1.pop_back();
                            inHash2.pop_back();
                        } else {
                            mod = firstMod;
                            outHash1.push_back(outHash1.back() * multiplier - arr[i]);
                            mod = secondMod;
                            outHash2.push_back(outHash2.back() * multiplier - arr[i]);
                        }
                    }
                }
            }

            part(int from, int to, arri& arr) : from(from), to(to), arr(arr) {
                rebuild();
            }

            bool match(vector<pair<part*, int>>& cur) {
                if (isBad) {
                    return false;
                }
                int outAt = 0;
                while (outAt + 1 < outHash1.size()) {
                    if (cur.empty()) {
                        return false;
                    }
                    if (cur.back().first == nullptr) {
                        int expected = cur.back().second;
                        cur.pop_back();
                        int a1 = getOut1(outAt, outAt + 1).n;
                        int a2 = getOut2(outAt, outAt + 1).n;
                        if (a1 != expected || a2 != expected) {
                            return false;
                        }
                        outAt++;
                        continue;
                    }
                    if (cur.back().second > outHash1.size() - 1 - outAt) {
                        int len = outHash1.size() - 1 - outAt;
                        if (cur.back().first->getIn1(cur.back().second - len, cur.back().second) !=
                            getOut1(outAt, outAt + len) ||
                            cur.back().first->getIn2(cur.back().second - len, cur.back().second) !=
                            getOut2(outAt, outAt + len)) {
                            return false;
                        }
                        cur.back().second -= len;
                        outAt += len;
                    } else {
                        int len = cur.back().second;
                        if (cur.back().first->getIn1(0, cur.back().second) != getOut1(outAt, outAt + len) ||
                            cur.back().first->getIn2(0, cur.back().second) != getOut2(outAt, outAt + len)) {
                            return false;
                        }
                        cur.pop_back();
                        outAt += len;
                    }
                }
                if (inHash1.size() > 1) {
                    cur.emplace_back(this, inHash1.size() - 1);
                }
                return true;
            }
        };
        vector<part> parts;
        int buben = 300;
        for (int i = 0; i <= n; i += buben) {
            parts.emplace_back(i, min(i + buben, n), s);
        }

        int q = in.readInt();
        for (int x : range(q)) {
            int type = in.readInt();
            if (type == 1) {
                int id = in.readInt() - 1;
                int val = in.readInt();
                s[id] = val;
                parts[id / buben].rebuild();
            } else {
                int l = in.readInt() - 1;
                int r = in.readInt();
                int frPart = l / buben;
                int toPart = r / buben;
                if (frPart == toPart) {
                    vi cur;
                    bool good = true;
                    for (int i : range(l, r)) {
                        if (s[i] > 0) {
                            cur.push_back(s[i]);
                        } else if (!cur.empty() && cur.back() == -s[i]) {
                            cur.pop_back();
                        } else {
                            good = false;
                            break;
                        }
                    }
                    if (good && cur.empty()) {
                        out.printLine("Yes");
                    } else {
                        out.printLine("No");
                    }
                    continue;
                }
                vector<pair<part*, int>> cur;
                bool good = true;
                for (int i : range(l, (frPart + 1) * buben)) {
                    if (s[i] > 0) {
                        cur.emplace_back(nullptr, s[i]);
                    } else if (!cur.empty() && cur.back().second == -s[i]) {
                        cur.pop_back();
                    } else {
                        good = false;
                        break;
                    }
                }
                if (!good) {
                    out.printLine("No");
                    continue;
                }
                for (int i : range(frPart + 1, toPart)) {
                    if (!parts[i].match(cur)) {
                        good = false;
                        break;
                    }
                }
                if (!good) {
                    out.printLine("No");
                    continue;
                }
                for (int i : range(toPart * buben, r)) {
                    if (s[i] > 0) {
                        cur.emplace_back(nullptr, s[i]);
                    } else {
                        if (cur.empty()) {
                            good = false;
                            break;
                        }
                        if (cur.back().first == nullptr) {
                            if (cur.back().second != -s[i]) {
                                good = false;
                                break;
                            }
                            cur.pop_back();
                        } else {
                            if (cur.back().first->getIn1(cur.back().second - 1, cur.back().second).n != -s[i] ||
                                cur.back().first->getIn2(cur.back().second - 1, cur.back().second).n != -s[i]) {
                                good = false;
                                break;
                            }
                            cur.back().second--;
                            if (cur.back().second == 0) {
                                cur.pop_back();
                            }
                        }
                    }
                }
                if (good && cur.empty()) {
                    out.printLine("Yes");
                } else {
                    out.printLine("No");
                }
            }
        }
    }
};


int main() {
#ifdef LOCAL
    signal(SIGABRT, &signalHandler);
#endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    TaskF solver;


    solver.solve();
    fflush(stdout);
    return 0;
}