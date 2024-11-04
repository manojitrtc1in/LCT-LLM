









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

        return *(parent::_M_impl._M_start + ind);
    }

    T& operator[](size_t ind) {

        if (ind >= parent::size()) {
            throw "Out of bounds";
        }

        return *(parent::_M_impl._M_start + ind);
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

        return *const_iterator(this->_M_impl._M_start._M_p
                               + ind / int(_S_word_bit), ind % int(_S_word_bit));
    }

    parent::reference operator[](size_t ind) {

        if (ind >= parent::size()) {
            throw "Out of bounds";
        }

        return *iterator(this->_M_impl._M_start._M_p
                         + ind / int(_S_word_bit), ind % int(_S_word_bit));
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
using pii = pair<int, int>;

template <typename T>
T minim(T& was, T cand) {
    return was = min(was, cand);
}

template <typename T>
T maxim(T& was, T cand) {
    return was = max(was, cand);
}



void signalHandler(int) {
    throw "Abort detected";
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
    T* e;
    int n;
public:
    arr() : b(nullptr), e(nullptr), n(0) {}

    arr(int n) : n(n) {

        if (n < 0) {
            throw "bad alloc";
        }

        if (n > 0) {
            b = new T[n];
            e = b + n;
        } else {
            b = e = nullptr;
        }
    }

    arr(int n, const T& init) : n(n) {

        if (n < 0) {
            throw "bad alloc";
        }

        if (n > 0) {
            b = new T[n];
            e = b + n;
            fill(b, e, init);
        } else {
            b = e = nullptr;
        }
    }

    arr(initializer_list<T> l) : n(l.size()) {
        if (n == 0) {
            b = e = nullptr;
        } else {
            b = new T[l.size()];
            e = b + n;
            copy(all(l), b);
        }
    }

    arr(T* b, int n) : b(b), e(b + n), n(n) {}

    arr(T* b, T* e) : b(b), e(e), n(e - b) {}

    size_t size() const {
        return n;
    }

    T* begin() {
        return b;
    }

    const T* begin() const {
        return b;
    }

    T* end() {
        return e;
    }

    const T* end() const {
        return e;
    }

    arr<T> clone() const {
        arr<T> res(n);
        copy(b, e, res.begin());
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
};

typedef arr<int> arri;

void id3() {}

template <typename T, class...Vs>
void id3(arr<T>& array, Vs& ...vs) {
    int n = array.size();
    for (int i = 0; i < n; ++i) {
        array[i]--;
    }
    id3(vs...);
}

template <typename T, typename U>
void id3(arr<pair<T, U>>& v) {
    for (auto& p : v) {
        p.first--;
        p.second--;
    }
}


template <typename T>
class id2 {
    T* b;
    T* e;
    int d1;
    int d2;
    int sz;

public:
    id2() : b(nullptr), e(nullptr), d1(0), d2(0), sz(0) {}

    id2(int d1, int d2) : d1(d1), d2(d2), sz(d1 * d2) {
        b = new T[sz];
        e = b + sz;
    }

    id2(int d1, int d2, const T& init) : d1(d1), d2(d2), sz(d1 * d2) {
        b = new T[sz];
        e = b + sz;
        fill(b, e, init);
    }

    id2(T* b, int d1, int d2) : b(b), e(b + d1 * d2), d1(d1), d2(d2), sz(d1 * d2) {}

    size_t size() const {
        return sz;
    }

    size_t dim1() const {
        return d1;
    }

    size_t dim2() const {
        return d2;
    }

    T* begin() {
        return b;
    }

    T* end() {
        return e;
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

    void swap(id2<T>& a) {
        std::swap(b, a.b);
        std::swap(e, a.e);
        std::swap(d1, a.d1);
        std::swap(d2, a.d2);
        std::swap(sz, a.sz);
    }
};

template <typename T>
class id4 {
    T* b;
    T* e;
    int d1;
    int d2;
    int d3;
    int shift;
    int sz;

public:
    id4() : b(nullptr), e(nullptr), d1(0), d2(0), d3(0), shift(0), sz(0) {}

    id4(int d1, int d2, int d3) : d1(d1), d2(d2), d3(d3), shift(d2 * d3), sz(d1 * d2 * d3) {
        b = new T[sz];
        e = b + sz;
    }

    id4(int d1, int d2, int d3, const T& init) : d1(d1), d2(d2), d3(d3), shift(d2 * d3), sz(d1 * d2 * d3) {
        b = new T[sz];
        e = b + sz;
        fill(b, e, init);
    }

    id4(T* b, int d1, int d2, int d3) : b(b), e(b + d1 * d2 * d3), d1(d1), d2(d2), d3(d3), shift(d2 * d3),
                                          sz(d1 * d2 * d3) {}

    size_t size() const {
        return sz;
    }

    size_t dim1() const {
        return d1;
    }

    size_t dim2() const {
        return d2;
    }

    size_t dim3() const {
        return d3;
    }

    T* begin() {
        return b;
    }

    T* end() {
        return e;
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
};

template <typename T>
class id0 {
    T* b;
    T* e;
    int d1;
    int d2;
    int d3;
    int d4;
    int shift1;
    int shift2;
    int sz;

public:
    id0() : b(nullptr), e(nullptr), d1(0), d2(0), d3(0), d4(0), shift1(0), shift2(0), sz(0) {}

    id0(int d1, int d2, int d3, int d4) : d1(d1), d2(d2), d3(d3), d4(d4), shift1(d2 * d3 * d4), shift2(d3 * d4),
                                            sz(d1 * d2 * d3 * d4) {
        b = new T[sz];
        e = b + sz;
    }

    id0(int d1, int d2, int d3, int d4, const T& init) : d1(d1), d2(d2), d3(d3), d4(d4), shift1(d2 * d3 * d4),
                                                           shift2(d3 * d4), sz(d1 * d2 * d3 * d4) {
        b = new T[sz];
        e = b + sz;
        fill(b, e, init);
    }

    id0(T* b, int d1, int d2, int d3, int d4) : d1(d1), d2(d2), d3(d3), d4(d4), shift1(d2 * d3 * d4), shift2(d3 * d4),
                                                  sz(d1 * d2 * d3 * d4) {}

    size_t size() const {
        return sz;
    }

    size_t dim1() const {
        return d1;
    }

    size_t dim2() const {
        return d2;
    }

    size_t dim3() const {
        return d3;
    }

    size_t dim4() const {
        return d4;
    }

    T* begin() {
        return b;
    }

    T* end() {
        return e;
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

    id2<T> operator[](int at) {

        if (at < 0 || at >= d1) {
            throw "Out of bounds";
        }

        return id4<T>(b + at * shift1, d2, d3, d4);
    }
};


inline bool isWhitespace(int c) {
    return isspace(c) || c == EOF;
}

class Input {
private:
    istream& in;
    bool id1 = false;

    inline int get() {
        if (id1) {

            throw "Input id1";

            return EOF;
        }
        int c = in.get();
        if (c == EOF) {
            id1 = true;
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
            id1 = true;
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
    id2<T> readTable(int rows, int cols) {
        id2<T> result(rows, cols);
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

            throw "Input id1";

            return 0;
        }
        return c;
    }

    bool isExhausted() { return id1; }
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





class TaskD {
public:
    void solve(istream& inp, ostream& outp) {
        Input in(inp);
        Output out(outp);

        int n = in.readInt();
        arri x, v, p;
        in.readArrays(n, x, v, p);
        mod = MODF;
        arr<arr<modint>> pp(4 * n);
        arr<arr<modint>> tmp(4 * n);
        id2<bool> allowed(n, 4, true);
        auto join = [&](arr<modint>& left, arr<modint>& right, arr<modint>& result, int at) {
            fill(all(result), 0);
            for (int i : range(2)) {
                for (int j : range(2)) {
                    for (int k : range(2)) {
                        for (int l : range(2)) {
                            if (allowed(at, 2 * j + k)) {
                                result[i * 2 + l] += left[i * 2 + j] * right[k * 2 + l];
                            }
                        }
                    }
                }
            }
        };
        function<void(int, int, int)> init = [&](int root, int left, int right) {
            pp[root] = arr<modint>(4, 0);
            tmp[root] = arr<modint>(4);
            if (left + 1 == right) {
                pp[root][0] = modint(100 - p[left]) / 100;
                pp[root][3] = 1 - pp[root][0];
            } else {
                int mid = (left + right) / 2;
                init(2 * root + 1, left, mid);
                init(2 * root + 2, mid, right);
                join(pp[2 * root + 1], pp[2 * root + 2], pp[root], mid);
            }
        };
        init(0, 0, n);
        struct Event {
            int type;
            int at;
            int dx;
            int v;

            Event(int type, int at, int dx, int v) : type(type), at(at), dx(dx), v(v) {}

            bool operator<(const Event& b) {
                return ll(dx) * b.v < ll(b.dx) * v;
            }
        };
        vec<Event> events;
        for (int i : range(1, n)) {
            events.emplace_back(2, i, x[i] - x[i - 1], v[i] + v[i - 1]);
            if (v[i] > v[i - 1]) {
                events.emplace_back(0, i, x[i] - x[i - 1], v[i] - v[i - 1]);
            } else if (v[i] < v[i - 1]) {
                events.emplace_back(3, i, x[i] - x[i - 1], v[i - 1] - v[i]);
            }
        }
        sort(all(events));
        function<bool(int, int, int, int, int)> query = [&](int root, int left, int right, int from, int to) -> bool {
            if (left >= to || right <= from) {
                return false;
            }
            if (left >= from && right <= to) {
                copy(all(pp[root]), tmp[root].begin());
                return true;
            }
            int mid = (left + right) / 2;
            bool lRes = query(2 * root + 1, left, mid, from, to);
            bool rRes = query(2 * root + 2, mid, right, from, to);
            if (!lRes) {
                copy(all(tmp[2 * root + 2]), tmp[root].begin());
                return true;
            }
            if (!rRes) {
                copy(all(tmp[2 * root + 1]), tmp[root].begin());
                return true;
            }
            join(tmp[2 * root + 1], tmp[2 * root + 2], tmp[root], mid);
            return true;
        };
        function<void(int, int, int, int)> recalc = [&](int root, int left, int right, int at) {
            if (left >= at || right <= at) {
                return;
            }
            int mid = (left + right) / 2;
            recalc(2 * root + 1, left, mid, at);
            recalc(2 * root + 2, mid, right, at);
            join(pp[2 * root + 1], pp[2 * root + 2], pp[root], mid);
        };
        modint answer = 0;
        for (const auto& e : events) {
            query(0, 0, n, 0, e.at);
            modint left = tmp[0][e.type / 2] + tmp[0][2 + e.type / 2];
            query(0, 0, n, e.at, n);
            modint right = tmp[0][e.type % 2 * 2] + tmp[0][e.type % 2 * 2 + 1];
            answer += modint(e.dx) / e.v * left * right;
            allowed[e.at][e.type] = false;
            recalc(0, 0, n, e.at);
        }
        out.printLine(answer);
    }
};


int main() {

    signal(SIGABRT, &signalHandler);

    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    TaskD solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}