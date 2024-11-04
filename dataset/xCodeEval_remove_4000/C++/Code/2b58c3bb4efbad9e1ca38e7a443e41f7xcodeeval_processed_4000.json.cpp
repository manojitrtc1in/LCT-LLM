






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

        if (sz < 0) {
            throw "bad alloc";
        }

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

        view();

    }

    arr(int n, const T &init) {
        allocate(n);
        for (int i : range(n)) {
            ::new((void *) (b + i)) T(init);
        }

        view();

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

        if (at < 0 || at >= n) {
            throw "Out of bounds";
        }

        return b[at];
    }

    const T &operator[](int at) const {

        if (at < 0 || at >= n) {
            throw "Out of bounds";
        }

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

void id1() {}

template<typename T, class...Vs>
void id1(arr<T> &array, Vs &...vs) {
    int n = array.size();
    for (int i : range(n)) {
        array[i]--;
    }
    id1(vs...);
}

template<typename T, typename U>
void id1(arr<pair<T, U>> &v) {
    for (auto &p : v) {
        p.first--;
        p.second--;
    }
}


template<typename T>
class id4 {
    T *b;
    int d1;
    int d2;
    int sz;

    void allocate(int n) {

        if (n < 0) {
            throw "bad alloc";
        }

        if (n > 0) {
            b = (T *) (::operator new(n * sizeof(T)));
        } else {
            b = nullptr;
        }
    }

public:
    id4(int d1 = 0, int d2 = 0) : d1(d1), d2(d2), sz(d1 * d2) {

        if (d1 < 0 || d2 < 0) {
            throw "bad alloc";
        }

        allocate(sz);

        view();

    }

    id4(int d1, int d2, const T &init) : d1(d1), d2(d2), sz(d1 * d2) {

        if (d1 < 0 || d2 < 0) {
            throw "bad alloc";
        }

        allocate(sz);
        for (int i : range(sz)) {
            ::new((void *) (b + i)) T(init);
        }

        view();

    }

    id4(T *b, int d1, int d2) : b(b), d1(d1), d2(d2), sz(d1 * d2) {}

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

        if (i1 < 0 || i1 >= d1 || i2 < 0 || i2 >= d2) {
            throw "Out of bounds";
        }

        return b[i1 * d2 + i2];
    }

    const T &operator()(int i1, int i2) const {

        if (i1 < 0 || i1 >= d1 || i2 < 0 || i2 >= d2) {
            throw "Out of bounds";
        }

        return b[i1 * d2 + i2];
    }

    T &operator[](const pii &p) {
        return operator()(p.first, p.second);
    }

    const T &operator[](const pii &p) const {
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

    id4<T> clone() {
        id4<T> res(d1, d2);
        copy(b, b + sz, res.b);
        return res;
    }
};


inline bool isWhitespace(int c) {
    return isspace(c) || c == EOF;
}

class Input {
private:
    bool id3 = false;
    int bufSize = 4096;
    char *buf = new char[bufSize];
    int bufRead = 0;
    int bufAt = 0;

public:
    inline int get() {
        if (id3) {

            throw "Input id3";

            return EOF;
        }
        if (bufRead == bufAt) {
            bufRead = fread(buf, sizeof(char), bufSize, stdin);
            bufAt = 0;
        }
        if (bufRead == bufAt) {
            id3 = true;
            return EOF;
        }
        return buf[bufAt++];
    }

    inline int peek() {
        if (id3) {

            throw "Input id3";

            return EOF;
        }
        if (bufRead == bufAt) {
            bufRead = fread(buf, sizeof(char), bufSize, stdin);
            bufAt = 0;
        }
        if (bufRead == bufAt) {
            id3 = true;
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

            throw "Input id3";

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
    id4<T> readTable(int rows, int cols) {
        id4<T> result(rows, cols);
        for (int i : range(rows)) {
            for (int j : range(cols)) {
                result(i, j) = readType<T>();
            }
        }
        return result;
    }

    id4<int> readIntTable(int rows, int cols) {
        return readTable<int>(rows, cols);
    }

    id4<char> readCharTable(int rows, int cols) {
        return readTable<char>(rows, cols);
    }

    string readLine() {
        int c = get();
        if (c == EOF) {

            throw "Input id3";

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

            throw "Input id3";

            return 0;
        }
        return c;
    }

    inline bool isExhausted() { return id3; }

    inline void setBufSize(int id0) {
        if (id0 > bufSize) {
            char *newBuf = new char[id0];
            memcpy(newBuf, buf, bufSize);
            buf = newBuf;
        }
        bufSize = id0;
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
    void printSingle(const id4<T> &array) {
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
    bool id2;

    Output(ostream &out, bool id2) : out(&out), id2(id2) {
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
        if (id2) {
            flush();
        }
    }

    template<typename...Targs>
    inline void printLine(const Targs... args) {
        print(args...);
        *out << '\n';
        if (id2) {
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


class AVasyaAndDigitalRoot {
public:
    void solve() {
        int k = in.readInt(), d = in.readInt();
        if (d == 0 && k != 1) {
            out.printLine("No solution");
            return;
        }
        out.print(d);
        for (int i : range(k - 1))
            out.print(0);
    }
};

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    auto time = clock();

    AVasyaAndDigitalRoot solver;
    solver.solve();
    fflush(stdout);

    cerr << setprecision(3) << double(clock() - time) / CLOCKS_PER_SEC << endl;

    return 0;
}
