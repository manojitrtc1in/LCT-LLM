









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
        for (int i : range(n)) {
            ::new((void*) (b + i)) T;
        }

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
            b = (T*) (::operator new(n * sizeof(T)));
        } else {
            b = nullptr;
        }
    }

public:
    id3(int d1 = 0, int d2 = 0) : d1(d1), d2(d2), sz(d1 * d2) {

        if (d1 < 0 || d2 < 0) {
            throw "bad alloc";
        }

        allocate(sz);
        for (int i : range(sz)) {
            ::new((void*) (b + i)) T;
        }

        view();

    }

    id3(int d1, int d2, const T& init) : d1(d1), d2(d2), sz(d1 * d2) {

        if (d1 < 0 || d2 < 0) {
            throw "bad alloc";
        }

        allocate(sz);
        for (int i : range(sz)) {
            ::new((void*) (b + i)) T(init);
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

    id3<T> clone() {
        id3<T> res(d1, d2);
        copy(b, b + sz, res.b);
        return res;
    }
};

template <typename T>
class id6 {
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
    id6(int d1 = 0, int d2 = 0, int d3 = 0) : d1(d1), d2(d2), d3(d3), shift(d2 * d3), sz(d1 * d2 * d3) {

        if (d1 < 0 || d2 < 0 || d3 < 0) {
            throw "bad alloc";
        }

        allocate(sz);
        for (int i : range(sz)) {
            ::new((void*) (b + i)) T;
        }

        view();

    }

    id6(int d1, int d2, int d3, const T& init) : d1(d1), d2(d2), d3(d3), shift(d2 * d3), sz(d1 * d2 * d3) {

        if (d1 < 0 || d2 < 0 || d3 < 0) {
            throw "bad alloc";
        }

        allocate(sz);
        for (int i : range(sz)) {
            ::new((void*) (b + i)) T(init);
        }

        view();

    }

    id6(T* b, int d1, int d2, int d3) : b(b), d1(d1), d2(d2), d3(d3), shift(d2 * d3), sz(d1 * d2 * d3) {}

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

    id3<T> operator[](int at) {

        if (at < 0 || at >= d1) {
            throw "Out of bounds";
        }

        return id3<T>(b + at * shift, d2, d3);
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
class id1 {
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
    id1(int d1 = 0, int d2 = 0, int d3 = 0, int d4 = 0) : d1(d1), d2(d2), d3(d3), d4(d4), shift1(d2 * d3 * d4),
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

    id1(int d1, int d2, int d3, int d4, const T& init) : d1(d1), d2(d2), d3(d3), d4(d4), shift1(d2 * d3 * d4),
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

    id1(T* b, int d1, int d2, int d3, int d4) : b(b), d1(d1), d2(d2), d3(d3), d4(d4), shift1(d2 * d3 * d4),
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

    id6<T> operator[](int at) {

        if (at < 0 || at >= d1) {
            throw "Out of bounds";
        }

        return id6<T>(b + at * shift1, d2, d3, d4);
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
    istream& in;
    bool id2 = false;

    inline int get() {
        if (id2) {

            throw "Input id2";

            return EOF;
        }
        int c = in.get();
        if (c == EOF) {
            id2 = true;
        }
        return c;
    }

    template <typename T>
    inline T readInteger() {
        skipWhitespace();
        int c = get();
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
    Input(istream& in) : in(in) {};

    inline void skipWhitespace() {
        int c;
        while (isWhitespace(c = in.peek()) && c != EOF) {
            in.get();
        }
        if (c == EOF) {
            id2 = true;
        }
    }

    inline int readInt() {
        return readInteger<int>();
    }

    ll readLong() {
        return readInteger<ll>();
    }

    string readString() {
        skipWhitespace();
        int c = get();
        if (c == EOF) {

            throw "Input id2";

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
        arr<T> res(n);
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
    id3<T> readTable(int rows, int cols) {
        id3<T> result(rows, cols);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                result(i, j) = readType<T>();
            }
        }
        return result;
    }

    string readLine() {
        int c = get();
        if (c == EOF) {

            throw "Input id2";

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
        skipWhitespace();
        int c = get();
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
        skipWhitespace();
        int c = get();
        if (c == EOF) {

            throw "Input id2";

            return 0;
        }
        return c;
    }

    bool isExhausted() { return id2; }
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


class Output {
private:
    ostream& out;

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
    void printSingle(const id3<T>& array) {
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
    Output(ostream& out) : out(out) {
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
};


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

    modint(ll n) {
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
        n += other.n;
        if (n >= mod) {
            n -= mod;
        }
        return *this;
    }

    modint& operator-=(const modint& other) {
        n -= other.n;
        if (n < 0) {
            n += mod;
        }
        return *this;
    }

    modint& operator*=(const modint& other) {
        n = ll(n) * other.n % mod;
        return *this;
    }

    modint& operator/=(const modint& other) {

        if (other.n == 0) {
            throw "Division by zero";
        }

        return *this *= other.inverse();
    }

    modint operator-() {
        if (n == 0) {
            return 0;
        }
        return modint(mod - n);
    }

    modint inverse() const {
        ll x, y;
        ll g = gcd(ll(n), ll(mod), x, y);

        if (g != 1) {
            throw "not inversable";
        }

        return x;
    }

    int log(modint alpha);
};

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


template <typename T>
inline void unique(vec<T>& v) {
    v.resize(unique(all(v)) - v.begin());
}

arri createOrder(int n) {
    arri order(n);
    for (int i = 0; i < n; i++) {
        order[i] = i;
    }
    return order;
}

arri inverse(const arri& p) {
    arri res(p.size());
    for (int i : range(p.size())) {
        res[p[i]] = i;
    }
    return res;
}

template <typename T, typename Iterator>
inline void addAll(vec<T>& v, Iterator begin, Iterator end) {
    v.insert(v.end(), begin, end);
}

template <class Collection, typename Iterator>
inline void addAll(Collection& v, Iterator begin, Iterator end) {
    v.insert(begin, end);
}

template <typename Iterator>
arri getQty(Iterator begin, Iterator end, int length) {
    arri res(length, 0);
    for (Iterator it = begin; it != end; it++) {
        res[*it]++;
    }
    return res;
}

template <typename Iterator>
arri getQty(Iterator begin, Iterator end) {
    return getQty(begin, end, *max_element(begin, end) + 1);
}

template <class Collection>
void collect(Collection&) {}

template <class Collection, class Other, class ...Vs>
void collect(Collection& all, Other& a, Vs& ...vs) {
    addAll(all, all(a));
    collect(all, vs...);
}

void replace(const vi&) {}

template <class ...Vs>
void replace(const vi& all, vi& a, Vs& ...vs) {
    for (int& i : a) {
        i = lower_bound(all(all), i) - all.begin();
    }
    replace(all, vs...);
}

template <class ...Vs>
void replace(const vi& all, arri& a, Vs& ...vs) {
    for (int& i : a) {
        i = lower_bound(all(all), i) - all.begin();
    }
    replace(all, vs...);
}

template <class ...Vs>
vi compress(Vs& ...vs) {
    vi vals;
    collect(vals, vs...);
    sort(all(vals));
    unique(vals);
    replace(vals, vs...);
    return vals;
}


template <typename T>
T gcd(T a, T b) {
    a = abs(a);
    b = abs(b);
    while (b != 0) {
        a = a % b;
        swap(a, b);
    }
    return a;
}

template <typename T>
T lcm(T a, T b) {
    return a / gcd(a, b) * b;
}

template <typename T>
T power(const T& a, ll b) {
    if (b == 0) {
        return 1;
    }
    if ((b & 1) == 0) {
        T res = power(a, b >> 1);
        return res * res;
    } else {
        return power(a, b - 1) * a;
    }
}

template <typename T>
T factorial(int n) {
    T result = 1;
    for (int i = 2; i <= n; i++) {
        result *= i;
    }
    return result;
}

template <typename T>
arr<T> factorials(int length) {
    arr<T> result(length);
    if (length > 0) {
        result[0] = 1;
    }
    for (int i = 1; i < length; i++) {
        result[i] = result[i - 1] * i;
    }
    return result;
}

arr<modint> id5(int length) {
    arr<modint> result(length);
    if (length > 1) {
        result[1] = 1;
    }
    for (int i = 2; i < length; i++) {
        result[i] = -(mod / i) * result[mod % i];
    }
    return result;
}

template <typename T>
arr<T> powers(T base, int length) {
    arr<T> result(length);
    if (length > 0) {
        result[0] = 1;
    }
    for (int i = 1; i < length; i++) {
        result[i] = result[i - 1] * base;
    }
    return result;
}

arr<modint> id0(int length) {
    auto result = id5(length);
    if (length > 0) {
        result[0] = 1;
    }
    for (int i = 1; i < length; i++) {
        result[i] *= result[i - 1];
    }
    return result;
}

class Combinations {
private:
    arr<modint> fact;
    arr<modint> id7;

public:
    Combinations(int length) {
        fact = factorials<modint>(length);
        id7 = id0(length);
    }

public:
    modint c(int n, int k) const {
        if (k < 0 || k > n) {
            return 0;
        }
        return fact[n] * id7[k] * id7[n - k];
    }

    modint operator()(int n, int k) const {
        return c(n, k);
    }

    modint factorial(int n) const {
        return fact[n];
    }

    modint inverseFactorial(int n) const {
        return id7[n];
    }
};


class TaskF {
public:
    void solve(istream& inp, ostream& outp) {
        Input in(inp);
        Output out(outp);

        int n = in.readInt();
        auto p = in.readIntArray(n);
        int q = in.readInt();
        arri id, x;
        in.readArrays(q, id, x);
        id4(id);

        int len = n + q;
        arr<modint> val(4 * len);
        arr<modint> lVal(4 * len);
        arr<modint> rVal(4 * len);
        arri enabled(4 * len);
        vi allVal(all(p));
        addAll(allVal, all(x));
        auto order = createOrder(len);
        sort(all(order), [&](int a, int b) -> bool {
            return allVal[a] < allVal[b];
        });
        sort(all(allVal));
        auto pos = inverse(order);
        auto cid = createOrder(n);
        arr<bool> isEnabled(len, false);
        for (int i : range(n)) {
            isEnabled[pos[i]] = true;
        }
        auto pw = powers(modint(1) / 2, len);
        auto join = [&](int root) {
            enabled[root] = enabled[2 * root + 1] + enabled[2 * root + 2];
            val[root] = val[2 * root + 1] + val[2 * root + 2] + lVal[2 * root + 1] * rVal[2 * root + 2];
            lVal[root] = lVal[2 * root + 2] + lVal[2 * root + 1] * pw[enabled[2 * root + 2]];
            rVal[root] = rVal[2 * root + 1] + rVal[2 * root + 2] * pw[enabled[2 * root + 1]];
        };
        auto leaf = [&](int root, int left) {
            enabled[root] = isEnabled[left] ? 1 : 0;
            val[root] = 0;
            lVal[root] = rVal[root] = isEnabled[left] ? modint(allVal[left]) / 2 : 0;
        };
        function<void(int, int, int)> init = [&](int root, int left, int right) {
            if (left + 1 == right) {
                leaf(root, left);
                return;
            }
            int mid = (left + right) / 2;
            init(2 * root + 1, left, mid);
            init(2 * root + 2, mid, right);
            join(root);
        };
        init(0, 0, len);
        out.printLine(val[0]);
        function<void(int, int, int, int)> change = [&](int root, int left, int right, int pos) {
            if (left > pos || right <= pos) {
                return;
            }
            if (left + 1 == right) {
                leaf(root, left);
                return;
            }
            int mid = (left + right) / 2;
            change(2 * root + 1, left, mid, pos);
            change(2 * root + 2, mid, right, pos);
            join(root);
        };
        for (int i : range(q)) {
            isEnabled[pos[cid[id[i]]]] = false;
            change(0, 0, len, pos[cid[id[i]]]);
            cid[id[i]] = i + n;
            isEnabled[pos[i + n]] = true;
            change(0, 0, len, pos[i + n]);
            out.printLine(val[0]);
        }
    }
};


int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    TaskF solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}