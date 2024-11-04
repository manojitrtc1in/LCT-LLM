







#include <bits/stdc++.h>

using namespace std;

template<typename T>
class Vector : public vector<T> {
    using parent = vector<T>;
public:
    Vector() : parent() {}

    explicit Vector(size_t __n) : parent(__n) {}

    Vector(size_t __n, const T &__value) : parent(__n, __value) {}

    explicit Vector(const parent &__x) : parent(__x) {}

    Vector(const Vector &__x) : parent(__x) {}

    Vector(Vector &&__x) noexcept : parent(move(__x)) {}

    Vector(initializer_list<T> __l) : parent(__l) {}

    template<typename _InputIterator, typename = std::_RequireInputIter<_InputIterator>>
    Vector(_InputIterator __first, _InputIterator __last) : parent(__first, __last) {}

    const T &operator[](size_t ind) const {
#ifdef LOCAL
        if (ind >= parent::size()) {
            throw "Out of bounds";
        }
#endif
        return *(parent::_M_impl._M_start + ind);
    }

    T &operator[](size_t ind) {
#ifdef LOCAL
        if (ind >= parent::size()) {
            throw "Out of bounds";
        }
#endif
        return *(parent::_M_impl._M_start + ind);
    }

    Vector<T> &operator=(Vector<T> &&__x) noexcept {
        parent::operator=(__x);
        return *this;
    }

    Vector<T> &operator=(const Vector<T> &__x) {
        parent::operator=(__x);
        return *this;
    }
};

template<>
class Vector<bool> : public vector<bool> {
    using parent = vector<bool>;
public:
    Vector() : parent() {}

    explicit Vector(size_t __n) : parent(__n) {}

    Vector(size_t __n, const bool &__value) : parent(__n, __value) {}

    explicit Vector(const parent &__x) : parent(__x) {}

    Vector(const Vector &__x) : parent(__x) {}

    Vector(Vector &&__x) noexcept : parent(move(__x)) {}

    Vector(initializer_list<bool> __l) : parent(__l) {}

    template<typename _InputIterator, typename = std::_RequireInputIter<_InputIterator>>
    Vector(_InputIterator __first, _InputIterator __last) : parent(__first, __last) {}

    parent::const_reference operator[](size_t ind) const {
#ifdef LOCAL
        if (ind >= parent::size()) {
            throw "Out of bounds";
        }
#endif
        return *const_iterator(this->_M_impl._M_start._M_p
                               + ind / int(_S_word_bit), ind % int(_S_word_bit));
    }

    parent::reference operator[](size_t ind) {
#ifdef LOCAL
        if (ind >= parent::size()) {
            throw "Out of bounds";
        }
#endif
        return *iterator(this->_M_impl._M_start._M_p
                         + ind / int(_S_word_bit), ind % int(_S_word_bit));
    }

    Vector<bool> &operator=(Vector<bool> &&__x) noexcept {
        parent::operator=(__x);
        return *this;
    }

    Vector<bool> &operator=(const Vector<bool> &__x) {
        parent::operator=(__x);
        return *this;
    }
};

#ifdef LOCAL
#define vec Vector
#else
#define vec vector
#endif

using vi = vec<int>;


#define all(v) (v).begin(), (v).end()

using ll = long long;
using pii = pair<int, int>;

const double PI = atan(1) * 4;

template<typename T>
T minim(T &was, T cand) {
    return was = min(was, cand);
}

template<typename T>
T maxim(T &was, T cand) {
    return was = max(was, cand);
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


template<typename T>
class arr {
    T *b;
    T *e;
    int n;
public:
    arr() : b(nullptr), e(nullptr), n(0) {}

    arr(int n) : n(n) {
#ifdef LOCAL
        if (n < 0) {
            throw "bad alloc";
        }
#endif
        if (n > 0) {
            b = new T[n];
            e = b + n;
        } else {
            b = e = nullptr;
        }
    }

    arr(int n, const T &init) : n(n) {
#ifdef LOCAL
        if (n < 0) {
            throw "bad alloc";
        }
#endif
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

    arr(T *b, int n) : b(b), e(b + n), n(n) {}

    arr(T *b, T *e) : b(b), e(e), n(e - b) {}

    size_t size() const {
        return n;
    }

    T *begin() {
        return b;
    }

    const T *begin() const {
        return b;
    }

    T *end() {
        return e;
    }

    const T *end() const {
        return e;
    }

    arr<T> clone() const {
        arr<T> res(n);
        copy(b, e, res.begin());
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

    void swap(arr<T> &arr) {
        std::swap(b, arr.b);
        std::swap(e, arr.e);
        std::swap(n, arr.n);
    }
};

class BoolIterator : iterator<forward_iterator_tag, bool> {
    unsigned *at;
    unsigned pos;

public:
    BoolIterator(unsigned int *at, unsigned int pos) : at(at), pos(pos) {}

    bool operator*() {
        return (*at >> pos & 1) == 1;
    }

    BoolIterator &operator++() {
        pos++;
        if (pos == 32) {
            pos = 0;
            at++;
        }
        return *this;
    }
};

typedef arr<int> arri;

void decreaseByOne() {}

template<typename T, class...Vs>
void decreaseByOne(arr<T> &array, Vs &...vs) {
    int n = array.size();
    for (int i = 0; i < n; ++i) {
        array[i]--;
    }
    decreaseByOne(vs...);
}

template<typename T, typename U>
void decreaseByOne(arr<pair<T, U> > &v) {
    for (auto &p : v) {
        p.first--;
        p.second--;
    }
}


template<typename T>
class arr2d {
    T *b;
    T *e;
    int d1;
    int d2;
    int sz;

public:
    arr2d() : b(nullptr), e(nullptr), d1(0), d2(0), sz(0) {}

    arr2d(int d1, int d2) : d1(d1), d2(d2), sz(d1 * d2) {
        b = new T[sz];
        e = b + sz;
    }

    arr2d(int d1, int d2, const T &init) : d1(d1), d2(d2), sz(d1 * d2) {
        b = new T[sz];
        e = b + sz;
        fill(b, e, init);
    }

    arr2d(T *b, int d1, int d2) : b(b), e(b + d1 * d2), d1(d1), d2(d2), sz(d1 * d2) {}

    size_t size() const {
        return sz;
    }

    size_t dim1() const {
        return d1;
    }

    size_t dim2() const {
        return d2;
    }

    T *begin() {
        return b;
    }

    T *end() {
        return e;
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

    arr<T> operator[](int at) {
#ifdef LOCAL
        if (at < 0 || at >= d1) {
            throw "Out of bounds";
        }
#endif
        return arr<T>(b + at * d2, d2);
    }

    void swap(arr2d<T> &a) {
        std::swap(b, a.b);
        std::swap(e, a.e);
        std::swap(d1, a.d1);
        std::swap(d2, a.d2);
        std::swap(sz, a.sz);
    }
};

template<typename T>
class arr3d {
    T *b;
    T *e;
    int d1;
    int d2;
    int d3;
    int shift;
    int sz;

public:
    arr3d() : b(nullptr), e(nullptr), d1(0), d2(0), d3(0), shift(0), sz(0) {}

    arr3d(int d1, int d2, int d3) : d1(d1), d2(d2), d3(d3), shift(d2 * d3), sz(d1 * d2 * d3) {
        b = new T[sz];
        e = b + sz;
    }

    arr3d(int d1, int d2, int d3, const T &init) : d1(d1), d2(d2), d3(d3), shift(d2 * d3), sz(d1 * d2 * d3) {
        b = new T[sz];
        e = b + sz;
        fill(b, e, init);
    }

    arr3d(T *b, int d1, int d2, int d3) : b(b), e(b + d1 * d2 * d3), d1(d1), d2(d2), d3(d3), shift(d2 * d3),
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

    T *begin() {
        return b;
    }

    T *end() {
        return e;
    }

    T &operator()(int i1, int i2, int i3) {
#ifdef LOCAL
        if (i1 < 0 || i1 >= d1 || i2 < 0 || i2 >= d2 || i3 < 0 || i3 >= d3) {
            throw "Out of bounds";
        }
#endif
        return b[i1 * shift + i2 * d3 + i3];
    }

    const T &operator()(int i1, int i2, int i3) const {
#ifdef LOCAL
        if (i1 < 0 || i1 >= d1 || i2 < 0 || i2 >= d2 || i3 < 0 || i3 >= d3) {
            throw "Out of bounds";
        }
#endif
        return b[i1 * shift + i2 * d3 + i3];
    }

    arr2d<T> operator[](int at) {
#ifdef LOCAL
        if (at < 0 || at >= d1) {
            throw "Out of bounds";
        }
#endif
        return arr2d<T>(b + at * shift, d2, d3);
    }
};

template<typename T>
class arr4d {
    T *b;
    T *e;
    int d1;
    int d2;
    int d3;
    int d4;
    int shift1;
    int shift2;
    int sz;

public:
    arr4d() : b(nullptr), e(nullptr), d1(0), d2(0), d3(0), d4(0), shift1(0), shift2(0), sz(0) {}

    arr4d(int d1, int d2, int d3, int d4) : d1(d1), d2(d2), d3(d3), d4(d4), shift1(d2 * d3 * d4), shift2(d3 * d4),
                                            sz(d1 * d2 * d3 * d4) {
        b = new T[sz];
        e = b + sz;
    }

    arr4d(int d1, int d2, int d3, int d4, const T &init) : d1(d1), d2(d2), d3(d3), d4(d4), shift1(d2 * d3 * d4),
                                                           shift2(d3 * d4), sz(d1 * d2 * d3 * d4) {
        b = new T[sz];
        e = b + sz;
        fill(b, e, init);
    }

    arr4d(T *b, int d1, int d2, int d3, int d4) : d1(d1), d2(d2), d3(d3), d4(d4), shift1(d2 * d3 * d4), shift2(d3 * d4),
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

    T *begin() {
        return b;
    }

    T *end() {
        return e;
    }

    T &operator()(int i1, int i2, int i3, int i4) {
#ifdef LOCAL
        if (i1 < 0 || i1 >= d1 || i2 < 0 || i2 >= d2 || i3 < 0 || i3 >= d3 || i4 < 0 || i4 >= d4) {
            throw "Out of bounds";
        }
#endif
        return b[i1 * shift1 + i2 * shift2 + i3 * d4 + i4];
    }

    const T &operator()(int i1, int i2, int i3, int i4) const {
#ifdef LOCAL
        if (i1 < 0 || i1 >= d1 || i2 < 0 || i2 >= d2 || i3 < 0 || i3 >= d3 || i4 < 0 || i4 >= d4) {
            throw "Out of bounds";
        }
#endif
        return b[i1 * shift1 + i2 * shift2 + i3 * d4 + i4];
    }

    arr2d<T> operator[](int at) {
#ifdef LOCAL
        if (at < 0 || at >= d1) {
            throw "Out of bounds";
        }
#endif
        return arr3d<T>(b + at * shift1, d2, d3, d4);
    }
};


inline bool isWhitespace(int c) {
    return isspace(c) || c == EOF;
}

class Input {
private:
    istream &in;
    bool exhausted = false;

    inline int get() {
        if (exhausted) {
#ifdef LOCAL
            throw "Input exhausted";
#endif
            return EOF;
        }
        int c = in.get();
        if (c == EOF) {
            exhausted = true;
        }
        return c;
    }

    template<typename T>
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
        array = arr<T>(n);
        initArrays(n, vs...);
    }

    void readImpl(int) {}

    template<typename T, class...Vs>
    void readImpl(int i, arr<T> &arr, Vs &...vs) {
        arr[i] = readType<T>();
        readImpl(i, vs...);
    }

public:
    Input(istream &in) : in(in) {};

    inline void skipWhitespace() {
        int c;
        while (isWhitespace(c = in.peek()) && c != EOF) {
            in.get();
        }
        if (c == EOF) {
            exhausted = true;
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
#ifdef LOCAL
            throw "Input exhausted";
#endif
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
        arr<T> res(n);
        for (int i = 0; i < n; i++) {
            res[i] = readType<T>();
        }
        return res;
    }


    template<class...Vs>
    void readArrays(int n, Vs &...vs) {
        initArrays(n, vs...);
        for (int i = 0; i < n; i++) {
            readImpl(i, vs...);
        }
    }

    template<typename U, typename V>
    arr<pair<U, V> > readArray(int n) {
        arr<pair<U, V> > res(n);
        for (int i = 0; i < n; i++) {
            res[i] = readType<U, V>();
        }
        return res;
    }

    template<typename T>
    arr2d<T> readTable(int rows, int cols) {
        arr2d<T> result(rows, cols);
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
#ifdef LOCAL
            throw "Input exhausted";
#endif
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
                return sgn * res * dPower(10, readInt());
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
                    return sgn * (res + add * dPower(10, -length)) * dPower(10, readInt());
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
            res += add * dPower(10, -length);
        }
        return res * sgn;
    }

    char readChar() {
        skipWhitespace();
        int c = get();
        if (c == EOF) {
#ifdef LOCAL
            throw "Input exhausted";
#endif
            return 0;
        }
        return c;
    }

    bool isExhausted() { return exhausted; }
};

template<>
double Input::readType() {
    return readDouble();
}

template<>
int Input::readType() {
    return readInt();
}

template<>
ll Input::readType() {
    return readLong();
}

template<>
char Input::readType() {
    return readChar();
}

template<>
string Input::readType() {
    return readString();
}


class Output {
private:
    ostream &out;

    template<typename T>
    void printSingle(const T &value) {
        out << value;
    }

    template<typename T>
    void printSingle(const vec<T> &array) {
        size_t n = array.size();
        for (int i = 0; i < n; ++i) {
            out << array[i];
            if (i + 1 != n) {
                out << ' ';
            }
        }
    }

    template<typename T>
    void printSingle(const arr<T> &array) {
        size_t n = array.size();
        for (int i = 0; i < n; ++i) {
            out << array[i];
            if (i + 1 != n) {
                out << ' ';
            }
        }
    }

    template<typename T>
    void printSingle(const arr2d<T> &array) {
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

    template<typename T, typename U>
    void printSingle(const pair<T, U> &value) {
        out << value.first << ' ' << value.second;
    }

public:
    Output(ostream &out) : out(out) {
        out << fixed << setprecision(20);
    }

    void print() {}

    template<typename T, typename...Targs>
    void print(const T &first, const Targs... args) {
        printSingle(first);
        if (sizeof...(args) != 0) {
            out << ' ';
            print(args...);
        }
    }

    template<typename...Targs>
    void printLine(const Targs... args) {
        print(args...);
        out << '\n';
    }

    void flush() {
        out.flush();
    }
};


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
inline void unique(vec<T> &v) {
    v.resize(unique(all(v)) - v.begin());
}

arri createOrder(int n) {
    arri order(n);
    for (int i = 0; i < n; i++) {
        order[i] = i;
    }
    return order;
}

template<class Collection, typename Iterator>
inline void addAll(Collection &v, Iterator begin, Iterator end) {
    v.insert(v.end(), begin, end);
}

template<typename Iterator>
arri getQty(Iterator begin, Iterator end, int length) {
    arri res(length, 0);
    for (Iterator it = begin; it != end; it++) {
        res[*it]++;
    }
    return res;
}

template<typename Iterator>
arri getQty(Iterator begin, Iterator end) {
    return getQty(begin, end, *max_element(begin, end) + 1);
}

template<class Collection>
void collect(Collection &) {}

template<class Collection, class ...Vs>
void collect(Collection &all, Collection &a, Vs &...vs) {
    addAll(all, all(a));
    collect(all, vs...);
}

void replace(const vi &) {}

template<class ...Vs>
void replace(const vi &all, vi &a, Vs &...vs) {
    for (int &i : a) {
        i = lower_bound(all(all), i) - all.begin();
    }
    replace(all, vs...);
}

template<class ...Vs>
void replace(const vi &all, arri &a, Vs &...vs) {
    for (int &i : a) {
        i = lower_bound(all(all), i) - all.begin();
    }
    replace(all, vs...);
}

template<class ...Vs>
vi compress(Vs &...vs) {
    vi vals;
    collect(vals, vs...);
    sort(all(vals));
    unique(vals);
    replace(vals, vs...);
    return vals;
}


class DSU {
    mutable arri id;
    arri sz;
    int count;

public:
    DSU(int n) {
        id = createOrder(n);
        sz = arri(n, 1);
        count = n;
    }

    int get(int i) const {
        if (id[i] == i) {
            return i;
        }
        return id[i] = get(id[i]);
    }

    int operator[](int i) const { return get(i); }

    int size(int i) const { return sz[get(i)]; }

    int setCount() const { return count; }

    bool join(int a, int b) {
        a = get(a);
        b = get(b);
        if (a == b) {
            return false;
        }
        sz[a] += sz[b];
        sz[b] = 0;
        id[b] = a;
        count--;
        return true;
    }
};





arr<ll> q(51, 0);
arr<ll> step(51, 1);
bool first = true;

class TaskE {
public:
    void solve(istream &inp, ostream &outp) {
        Input in(inp);
        Output out(outp);

        int n = in.readInt();
        ll k = in.readLong() - 1;

        if (first) {
            q[0] = 1;
            ll infty = numeric_limits<ll>::max();
            for (int i : range(1, 51)) {
                for (int j : range(1, i)) {
                    if (infty / step[i] < j) {
                        step[i] = infty;
                        break;
                    }
                    step[i] *= j;
                }
                for (int j : range(1, i + 1)) {
                    if ((infty - q[i]) / step[j - 1] < q[i - j]) {
                        q[i] = infty;
                        break;
                    }
                    q[i] += q[i - j] * step[j - 1];
                }
            }
            first = false;
        }

        if (k >= q[n]) {
            out.printLine(-1);
            return;
        }
        vi answer;
        int rem = n;
        int add = 0;
        while (rem > 0) {
            int len;
            for (int i : range(1, rem + 1)) {
                if (k / step[i - 1] < q[rem - i]) {
                    len = i;
                    break;
                } else {
                    k -= step[i - 1] * q[rem - i];
                }
            }
            answer.push_back(len + add);
            arr<bool> iedge(len, false);
            iedge[len - 1] = true;
            DSU dsu(len);
            dsu.join(0, len - 1);
            for (int i : range(1, len)) {
                ll cStep = step[len - i - 1];
                for (int j : range(0, len)) {
                    if (iedge[j] || (dsu[j] == dsu[i] && i + 1 != len)) {
                        continue;
                    }
                    if (k / cStep >= q[rem - len]) {
                        k -= cStep * q[rem - len];
                    } else {
                        answer.push_back(add + j + 1);
                        iedge[j] = true;
                        dsu.join(i, j);
                        break;
                    }
                }
            }
            add += len;
            rem -= len;
        }
        out.printLine(answer);
    }
};


int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    TaskE solver;
    std::istream &in(std::cin);
    std::ostream &out(std::cout);
    int n;
    in >> n;
    for (int i = 0; i < n; ++i) {
        solver.solve(in, out);
    }

    return 0;
}