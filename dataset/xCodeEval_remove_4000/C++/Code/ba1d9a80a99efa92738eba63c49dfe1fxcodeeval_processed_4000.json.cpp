









using namespace std;



template <typename T>
class Vector : public vector<T> {
    using parent = vector<T>;
public:
    Vector() : parent() {}

    explicit Vector(size_t __n) : parent(__n) {}

    Vector(size_t __n, const T& __value) : parent(__n, __value) {}

    explicit Vector(const parent& __x) : parent(__x) {}

    Vector(const Vector& __x) : parent(__x) {}

    Vector(Vector&& __x) noexcept : parent(move(__x)) {}

    Vector(initializer_list<T> __l) : parent(__l) {}

    template <typename _InputIterator, typename = std::_RequireInputIter<_InputIterator>>
    Vector(_InputIterator __first, _InputIterator __last) : parent(__first, __last) {}

    const T& operator[](size_t ind) const {

        if (ind >= parent::size()) {
            throw "Out of bounds";
        }

        return parent::operator[](ind);
    }

    T& operator[](size_t ind) {

        if (ind >= parent::size()) {
            throw "Out of bounds";
        }

        return parent::operator[](ind);
    }

    Vector<T>& operator=(Vector<T>&& __x) noexcept {
        parent::operator=(__x);
        return *this;
    }

    Vector<T>& operator=(const Vector<T>& __x) {
        if (&__x == this) {
            return *this;
        }
        parent::operator=(__x);
        return *this;
    }
};

template <>
class Vector<bool> : public vector<bool> {
    using parent = vector<bool>;
public:
    Vector() : parent() {}

    explicit Vector(size_t __n) : parent(__n) {}

    Vector(size_t __n, const bool& __value) : parent(__n, __value) {}

    explicit Vector(const parent& __x) : parent(__x) {}

    Vector(const Vector& __x) : parent(__x) {}

    Vector(Vector&& __x) noexcept : parent(move(__x)) {}

    Vector(initializer_list<bool> __l) : parent(__l) {}

    template <typename _InputIterator, typename = std::_RequireInputIter<_InputIterator>>
    Vector(_InputIterator __first, _InputIterator __last) : parent(__first, __last) {}

    parent::const_reference operator[](size_t ind) const {

        if (ind >= parent::size()) {
            throw "Out of bounds";
        }

        return parent::operator[](ind);
    }

    parent::reference operator[](size_t ind) {

        if (ind >= parent::size()) {
            throw "Out of bounds";
        }

        return parent::operator[](ind);
    }

    Vector<bool>& operator=(Vector<bool>&& __x) noexcept {
        parent::operator=(__x);
        return *this;
    }

    Vector<bool>& operator=(const Vector<bool>& __x) {
        if (&__x == this) {
            return *this;
        }
        parent::operator=(__x);
        return *this;
    }
};













using vi = vec<int>;




using ll = long long;
using ld = long double;
using pii = pair<int, int>;

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

        if (sz < 0) {
            throw "bad alloc";
        }

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

        view();

    }

    arr(int n, const T& init) {
        allocate(n);
        for (int i : range(n)) {
            ::new((void*) (b + i)) T(init);
        }

        view();

    }

    arr(initializer_list<T> l) {
        allocate(n);
        if (n > 0) {
            memcpy(b, l.begin(), n * sizeof(T));
        }

        view();

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

void id4() {}

template <typename T, class...Vs>
void id4(arr<T>& array, Vs& ...vs) {
    int n = array.size();
    for (int i = 0; i < n; ++i) {
        array[i]--;
    }
    id4(vs...);
}

template <typename T, typename U>
void id4(arr<pair<T, U>>& v) {
    for (auto& p : v) {
        p.first--;
        p.second--;
    }
}


template <typename T>
class id2 {
    T* b;
    int d1;
    int d2;
    int sz;

    void allocate(int n) {

        if (n < 0) {
            throw "bad alloc";
        }

        if (n > 0) {
            b = (T*) (::operator new(n * sizeof(T)));
        } else {
            b = nullptr;
        }
    }

public:
    id2(int d1 = 0, int d2 = 0) : d1(d1), d2(d2), sz(d1 * d2) {

        if (d1 < 0 || d2 < 0) {
            throw "bad alloc";
        }

        allocate(sz);

        view();

    }

    id2(int d1, int d2, const T& init) : d1(d1), d2(d2), sz(d1 * d2) {

        if (d1 < 0 || d2 < 0) {
            throw "bad alloc";
        }

        allocate(sz);
        for (int i : range(sz)) {
            ::new((void*) (b + i)) T(init);
        }

        view();

    }

    id2(T* b, int d1, int d2) : b(b), d1(d1), d2(d2), sz(d1 * d2) {}

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

    arr<T> operator[](int at) {

        if (at < 0 || at >= d1) {
            throw "Out of bounds";
        }

        return arr<T>(b + at * d2, d2);
    }

    vector<vector<T>> view() {
        vector<vector<T>> res(min(d1, 50));
        for (int i = 0; i < res.size(); ++i) {
            res[i] = (*this)[i].view();
        }
        return res;
    }

    id2<T> clone() {
        id2<T> res(d1, d2);
        copy(b, b + sz, res.b);
        return res;
    }
};

template <typename T>
class id5 {
    T* b;
    int d1;
    int d2;
    int d3;
    int shift;
    int sz;

    void allocate(int n) {

        if (n < 0) {
            throw "bad alloc";
        }

        if (n > 0) {
            b = (T*) (::operator new(n * sizeof(T)));
        } else {
            b = nullptr;
        }
    }

public:
    id5(int d1 = 0, int d2 = 0, int d3 = 0) : d1(d1), d2(d2), d3(d3), shift(d2 * d3), sz(d1 * d2 * d3) {

        if (d1 < 0 || d2 < 0 || d3 < 0) {
            throw "bad alloc";
        }

        allocate(sz);
        for (int i : range(sz)) {
            ::new((void*) (b + i)) T;
        }

        view();

    }

    id5(int d1, int d2, int d3, const T& init) : d1(d1), d2(d2), d3(d3), shift(d2 * d3), sz(d1 * d2 * d3) {

        if (d1 < 0 || d2 < 0 || d3 < 0) {
            throw "bad alloc";
        }

        allocate(sz);
        for (int i : range(sz)) {
            ::new((void*) (b + i)) T(init);
        }

        view();

    }

    id5(T* b, int d1, int d2, int d3) : b(b), d1(d1), d2(d2), d3(d3), shift(d2 * d3), sz(d1 * d2 * d3) {}

    int size() const {
        return sz;
    }

    int dim1() const {
        return d1;
    }

    int dim2() const {
        return d2;
    }

    int dim3() const {
        return d3;
    }

    T* begin() {
        return b;
    }

    T* end() {
        return b + sz;
    }

    T& operator()(int i1, int i2, int i3) {

        if (i1 < 0 || i1 >= d1 || i2 < 0 || i2 >= d2 || i3 < 0 || i3 >= d3) {
            throw "Out of bounds";
        }

        return b[i1 * shift + i2 * d3 + i3];
    }

    const T& operator()(int i1, int i2, int i3) const {

        if (i1 < 0 || i1 >= d1 || i2 < 0 || i2 >= d2 || i3 < 0 || i3 >= d3) {
            throw "Out of bounds";
        }

        return b[i1 * shift + i2 * d3 + i3];
    }

    id2<T> operator[](int at) {

        if (at < 0 || at >= d1) {
            throw "Out of bounds";
        }

        return id2<T>(b + at * shift, d2, d3);
    }

    vector<vector<vector<T>>> view() {
        vector<vector<vector<T>>> res(min(d1, 50));
        for (int i = 0; i < res.size(); ++i) {
            res[i] = (*this)[i].view();
        }
        return res;
    }
};

template <typename T>
class id0 {
    T* b;
    int d1;
    int d2;
    int d3;
    int d4;
    int shift1;
    int shift2;
    int sz;

    void allocate(int n) {

        if (n < 0) {
            throw "bad alloc";
        }

        if (n > 0) {
            b = (T*) (::operator new(n * sizeof(T)));
        } else {
            b = nullptr;
        }
    }

public:
    id0(int d1 = 0, int d2 = 0, int d3 = 0, int d4 = 0) : d1(d1), d2(d2), d3(d3), d4(d4), shift1(d2 * d3 * d4),
                                                            shift2(d3 * d4), sz(d1 * d2 * d3 * d4) {

        if (d1 < 0 || d2 < 0 || d3 < 0) {
            throw "bad alloc";
        }

        allocate(sz);
        for (int i : range(sz)) {
            ::new((void*) (b + i)) T;
        }

        view();

    }

    id0(int d1, int d2, int d3, int d4, const T& init) : d1(d1), d2(d2), d3(d3), d4(d4), shift1(d2 * d3 * d4),
                                                           shift2(d3 * d4), sz(d1 * d2 * d3 * d4) {

        if (d1 < 0 || d2 < 0 || d3 < 0) {
            throw "bad alloc";
        }

        allocate(sz);
        for (int i : range(sz)) {
            ::new((void*) (b + i)) T(init);
        }

        view();

    }

    id0(T* b, int d1, int d2, int d3, int d4) : b(b), d1(d1), d2(d2), d3(d3), d4(d4), shift1(d2 * d3 * d4),
                                                  shift2(d3 * d4), sz(d1 * d2 * d3 * d4) {
    }

    int size() const {
        return sz;
    }

    int dim1() const {
        return d1;
    }

    int dim2() const {
        return d2;
    }

    int dim3() const {
        return d3;
    }

    int dim4() const {
        return d4;
    }

    T* begin() {
        return b;
    }

    T* end() {
        return b + sz;
    }

    T& operator()(int i1, int i2, int i3, int i4) {

        if (i1 < 0 || i1 >= d1 || i2 < 0 || i2 >= d2 || i3 < 0 || i3 >= d3 || i4 < 0 || i4 >= d4) {
            throw "Out of bounds";
        }

        return b[i1 * shift1 + i2 * shift2 + i3 * d4 + i4];
    }

    const T& operator()(int i1, int i2, int i3, int i4) const {

        if (i1 < 0 || i1 >= d1 || i2 < 0 || i2 >= d2 || i3 < 0 || i3 >= d3 || i4 < 0 || i4 >= d4) {
            throw "Out of bounds";
        }

        return b[i1 * shift1 + i2 * shift2 + i3 * d4 + i4];
    }

    id5<T> operator[](int at) {

        if (at < 0 || at >= d1) {
            throw "Out of bounds";
        }

        return id5<T>(b + at * shift1, d2, d3, d4);
    }

    vector<vector<vector<vector<T>>>> view() {
        vector<vector<vector<vector<T>>>> res(min(d1, 50));
        for (int i = 0; i < res.size(); ++i) {
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
    bool id1 = false;
    int bufSize = 4096;
    char* buf = new char[bufSize];
    int bufRead = 0;
    int bufAt = 0;

    inline int get() {
        if (id1) {

            throw "Input id1";

            return EOF;
        }
        if (bufRead == bufAt) {
            bufRead = fread(buf, sizeof(char), bufSize, stdin);
            bufAt = 0;
        }
        if (bufRead == bufAt) {
            id1 = true;
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
    void initArrays(int n, arr<T>& array, Vs& ...vs) {
        array = arr<T>(n);
        initArrays(n, vs...);
    }

    template <typename T, class...Vs>
    void initArrays(int n, vec<T>&, Vs& ...vs) {
        initArrays(n, vs...);
    }

    void readImpl(int) {}

    template <typename T, class...Vs>
    void readImpl(int i, arr<T>& arr, Vs& ...vs) {
        arr[i] = readType<T>();
        readImpl(i, vs...);
    }

    template <typename T, class...Vs>
    void readImpl(int i, vec<T>& arr, Vs& ...vs) {
        arr.push_back(readType<T>());
        readImpl(i, vs...);
    }

public:
    inline int skipWhitespace() {
        int c;
        while (isWhitespace(c = get()) && c != EOF);
        if (c == EOF) {
            id1 = true;
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

            throw "Input id1";

            return "";
        }
        vec<char> res;
        do {
            res.push_back(c);
        } while (!isWhitespace(c = get()));
        return string(all(res));
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
    id2<T> readTable(int rows, int cols) {
        id2<T> result(rows, cols);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                result(i, j) = readType<T>();
            }
        }
        return result;
    }

    id2<int> readIntTable(int rows, int cols) {
        return readTable<int>(rows, cols);
    }

    id2<char> readCharTable(int rows, int cols) {
        return readTable<char>(rows, cols);
    }

    string readLine() {
        int c = get();
        if (c == EOF) {

            throw "Input id1";

            return "";
        }
        vec<char> res;
        do {
            res.push_back(c);
            c = get();
        } while (c != '\n' && c != '\r' && c != EOF);
        return string(all(res));
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

    char readChar() {
        int c = skipWhitespace();
        if (c == EOF) {

            throw "Input id1";

            return 0;
        }
        return c;
    }

    bool isExhausted() { return id1; }

    void setBufSize(int id3) {
        if (id3 > bufSize) {
            char* newBuf = new char[id3];
            memcpy(newBuf, buf, bufSize);
            buf = newBuf;
        }
        bufSize = id3;
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


class Output {
private:
    ostream& out = cout;

    template <typename T>
    void printSingle(const T& value) {
        out << value;
    }

    template <typename T>
    void printSingle(const vec<T>& array) {
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
    void printSingle(const id2<T>& array) {
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


class TaskA {
public:
    void solve() {
        int n = in.readInt();
        arri p, c;
        in.readArrays(n, p, c);

        int lp = 0;
        int lc = 0;
        for (int i : range(n)) {
            if (p[i] < lp || c[i] < lc || p[i] - lp < c[i] - lc) {
                out.printLine("NO");
                return;
            }
            lp = p[i];
            lc = c[i];
        }
        out.printLine("YES");
    }
};


int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    TaskA solver;


    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        solver.solve();
    }

    fflush(stdout);
    return 0;
}
