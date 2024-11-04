




#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define fi first
#define se second
#define w(tc) int tc = in.readInt(); while (tc--)

using ll = long long;
using ull = unsigned long long;
using li = __int128;
using uli = unsigned __int128;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;

void doReplace() {
}

template<typename T, typename U, typename...Vs>
void doReplace(T &t, const U &u, Vs &&...vs) {
    t = u;
    doReplace(vs...);
}

template<typename T, typename...Us>
T minim(T &was, const T &cand, Us &&...us) {
    if (was > cand) {
        was = cand;
        doReplace(us...);
    }
    return was;
}

template<typename T, typename...Us>
T maxim(T &was, const T &cand, Us &&...us) {
    if (was < cand) {
        was = cand;
        doReplace(us...);
    }
    return was;
}


template<typename D>
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


template<typename T>
class arr {
    T *b;
    int n;

    void allocate(int sz) {
#ifdef LOCAL
        if (sz < 0) {
            throw "bad alloc";
        }
#endif
        n = sz;
        if (sz > 0) {
            b = (T *) (::operator new(sz * sizeof(T)));
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

    arr(int n, const T &init) {
        allocate(n);
        for (int i : range(n)) {
            ::new((void *) (b + i)) T(init);
        }
#ifdef LOCAL
        view();
#endif
    }

    arr(int n, arr<T> arr1) {
        allocate(n);
        for (int i : range(n)) {
            b[i] = arr1.b[i];
        }
    }

    arr(initializer_list<T> l) : arr(l.size()) {
        if (n > 0) {
            memcpy(b, l.begin(), n * sizeof(T));
        }
    }

    arr(T *b, int n) : arr(b, b + n) {}

    arr(T *b, T *e) : b(b), n(e - b) {}

    int size() const {
        return n;
    }

    T *begin() {
        return b;
    }

    T *operator+(int x) {
#ifdef LOCAL
        if (x < 0 || x > n)
            throw "Out of bounds";
#endif
        return b + x;
    }

    const T *operator+(int x) const {
#ifdef LOCAL
        if (x < 0 || x > n)
            throw "Out of bounds";
#endif
        return b + x;
    }

    const T *begin() const {
        return b;
    }

    T *end() {
        return b + n;
    }

    const T *end() const {
        return b + n;
    }

    arr<T> clone() const {
        arr<T> res(n);
        copy(b, b + n, res.begin());
        return res;
    }

    T &operator[](int at) {
#ifdef LOCAL
        if (at < 0 || at >= n) {
            throw "Out of bounds";
        }
#endif
        return b[at];
    }

    const T &operator[](int at) const {
#ifdef LOCAL
        if (at < 0 || at >= n) {
            throw "Out of bounds";
        }
#endif
        return b[at];
    }

    bool operator==(const arr &other) const {
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

template<typename T, class...Vs>
void decreaseByOne(arr<T> &array, Vs &...vs) {
    int n = array.size();
    for (int i : range(n)) {
        array[i]--;
    }
    decreaseByOne(vs...);
}

template<typename T, typename U>
void decreaseByOne(arr<pair<T, U>> &v) {
    for (auto &p : v) {
        p.first--;
        p.second--;
    }
}


template<typename T>
class arr2d {
    T *b;
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
            b = (T *) (::operator new(n * sizeof(T)));
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

    arr2d(int d1, int d2, const T &init) : d1(d1), d2(d2), sz(d1 * d2) {
#ifdef LOCAL
        if (d1 < 0 || d2 < 0) {
            throw "bad alloc";
        }
#endif
        allocate(sz);
        for (int i : range(sz)) {
            ::new((void *) (b + i)) T(init);
        }
#ifdef LOCAL
        view();
#endif
    }

    arr2d(T *b, int d1, int d2) : b(b), d1(d1), d2(d2), sz(d1 * d2) {}

    int size() const {
        return sz;
    }

    int dim1() const {
        return d1;
    }

    int dim2() const {
        return d2;
    }

    T *begin() {
        return b;
    }

    T *end() {
        return b + sz;
    }

    T &operator()(int i1, int i2) {
#ifdef LOCAL
        if (i1 < 0 || i1 >= d1 || i2 < 0 || i2 >= d2) {
            throw "Out of bounds";
        }
#endif
        return b[i1 * d2 + i2];
    }

    const T &operator()(int i1, int i2) const {
#ifdef LOCAL
        if (i1 < 0 || i1 >= d1 || i2 < 0 || i2 >= d2) {
            throw "Out of bounds";
        }
#endif
        return b[i1 * d2 + i2];
    }

    T &operator[](const pii &p) {
        return operator()(p.first, p.second);
    }

    const T &operator[](const pii &p) const {
        return operator()(p.first, p.second);
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
        for (int i : range(res.size())) {
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
    char *buf = new char[bufSize];
    int bufRead = 0;
    int bufAt = 0;

public:
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

    inline int peek() {
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

    template<typename T, class...Vs>
    void initArrays(int n, arr<T> &array, Vs &...vs) {
        array = arr<T>(n, T());
        initArrays(n, vs...);
    }

    template<typename T, class...Vs>
    void initArrays(int n, vector<T> &, Vs &...vs) {
        initArrays(n, vs...);
    }

    void readImpl(int) {}

    template<typename T, class...Vs>
    void readImpl(int i, arr<T> &arr, Vs &...vs) {
        arr[i] = readType<T>();
        readImpl(i, vs...);
    }

    template<typename T, class...Vs>
    void readImpl(int i, vector<T> &arr, Vs &...vs) {
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


    template<class...Vs>
    void readArrays(int n, Vs &...vs) {
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
    arr2d<T> readTable(int rows, int cols) {
        arr2d<T> result(rows, cols);
        for (int i : range(rows)) {
            for (int j : range(cols)) {
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

    inline char readChar() {
        int c = skipWhitespace();
        if (c == EOF) {
#ifdef LOCAL
            throw "Input exhausted";
#endif
            return 0;
        }
        return c;
    }

    inline bool isExhausted() { return exhausted; }

    inline void setBufSize(int newBufSize) {
        if (newBufSize > bufSize) {
            char *newBuf = new char[newBufSize];
            memcpy(newBuf, buf, bufSize);
            buf = newBuf;
        }
        bufSize = newBufSize;
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
    ostream *out;

    template<typename T>
    inline void printSingle(const T &value) {
        *out << value;
    }

    template<typename T>
    void printSingle(const vector<T> &array) {
        size_t n = array.size();
        for (int i : range(n)) {
            *out << array[i];
            if (i + 1 != n) {
                *out << ' ';
            }
        }
    }

    template<typename T>
    void printSingle(const arr<T> &array) {
        int n = array.size();
        for (int i : range(n)) {
            *out << array[i];
            if (i + 1 != n) {
                *out << ' ';
            }
        }
    }

    template<typename T>
    void printSingle(const arr2d<T> &array) {
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
    inline void printSingle(const pair<T, U> &value) {
        *out << value.first << ' ' << value.second;
    }

public:
    bool autoflush;

    Output(ostream &out, bool autoflush) : out(&out), autoflush(autoflush) {
        setPrecision(20);
    }

    void setOut(ostream &nOut) {
        out = &nOut;
        setPrecision(20);
    }

    inline void print() {}

    template<typename T, typename...Targs>
    inline void print(const T &first, const Targs... args) {
        printSingle(first);
        if (sizeof...(args) != 0) {
            *out << ' ';
            print(args...);
        }
        if (autoflush) {
            flush();
        }
    }

    template<typename...Targs>
    inline void printLine(const Targs... args) {
        print(args...);
        *out << '\n';
        if (autoflush) {
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


class BHelpKingdomOfFarFarAway2 {
public:
    void solve() {
        string s = in.readString();
        bool minus = false;
        int start = 0;
        if (s[0] == '-') {
            minus = true;
            start = 1;
        }
        vector<char> num;
        for (int i = start; s[i] != '.' && i < (int) s.length(); ++i) {
            num.pb(s[i]);
        }
        string ans;
        int cnt = 0;
        while (!num.empty()) {
            ans += num.back();
            num.pop_back();
            cnt = (cnt + 1) % 3;
            if (!num.empty() && cnt == 0) {
                ans += ',';
            }
        }
        ans += '$';
        if (minus) {
            ans += '(';
        }
        reverse(all(ans));
        ans += '.';
        int idx = -1;
        for (int i : range((int) s.length())) {
            if (s[i] == '.') {
                idx = i;
                break;
            }
        }
        if (idx == -1) {
            ans += "00";
            if (minus) {
                ans += ')';
            }
        } else {
            int d = 0;
            for (int i : range(idx + 1, min(idx + 3, (int) s.length()))) {
                ans += s[i];
                d++;
            }
            if (d < 2) {
                for (int i : range(2 - d)) {
                    ans += "0";
                }
            }
            if (minus) {
                ans += ')';
            }
        }
        out.printLine(ans);
    }
};

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    auto time = clock();
#endif
    BHelpKingdomOfFarFarAway2 solver;
    solver.solve();
    fflush(stdout);
#ifdef LOCAL
    cerr << setprecision(3) << double(clock() - time) / CLOCKS_PER_SEC << endl;
#endif
    return 0;
}