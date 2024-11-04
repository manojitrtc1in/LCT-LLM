









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

        if (ind >= parent::size()) {
            throw "Out of bounds";
        }

        return *(parent::_M_impl._M_start + ind);
    }

    T &operator[](size_t ind) {

        if (ind >= parent::size()) {
            throw "Out of bounds";
        }

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

    Vector<bool> &operator=(Vector<bool> &&__x) noexcept {
        parent::operator=(__x);
        return *this;
    }

    Vector<bool> &operator=(const Vector<bool> &__x) {
        parent::operator=(__x);
        return *this;
    }
};







using vi = vec<int>;




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

    arr(int n, const T &init) : n(n) {

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

void id4() {}

template<typename T, class...Vs>
void id4(arr<T> &array, Vs &...vs) {
    int n = array.size();
    for (int i = 0; i < n; ++i) {
        array[i]--;
    }
    id4(vs...);
}

template<typename T, typename U>
void id4(arr<pair<T, U> > &v) {
    for (auto &p : v) {
        p.first--;
        p.second--;
    }
}


template<typename T>
class id3 {
    T *b;
    T *e;
    int d1;
    int d2;
    int sz;

public:
    id3() : b(nullptr), e(nullptr), d1(0), d2(0), sz(0) {}

    id3(int d1, int d2) : d1(d1), d2(d2), sz(d1 * d2) {
        b = new T[sz];
        e = b + sz;
    }

    id3(int d1, int d2, const T &init) : d1(d1), d2(d2), sz(d1 * d2) {
        b = new T[sz];
        e = b + sz;
        fill(b, e, init);
    }

    id3(T *b, int d1, int d2) : b(b), e(b + d1 * d2), d1(d1), d2(d2), sz(d1 * d2) {}

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

    arr<T> operator[](int at) {

        if (at < 0 || at >= d1) {
            throw "Out of bounds";
        }

        return arr<T>(b + at * d2, d2);
    }

    void swap(id3<T> &a) {
        std::swap(b, a.b);
        std::swap(e, a.e);
        std::swap(d1, a.d1);
        std::swap(d2, a.d2);
        std::swap(sz, a.sz);
    }
};

template<typename T>
class id6 {
    T *b;
    T *e;
    int d1;
    int d2;
    int d3;
    int shift;
    int sz;

public:
    id6() : b(nullptr), e(nullptr), d1(0), d2(0), d3(0), shift(0), sz(0) {}

    id6(int d1, int d2, int d3) : d1(d1), d2(d2), d3(d3), shift(d2 * d3), sz(d1 * d2 * d3) {
        b = new T[sz];
        e = b + sz;
    }

    id6(int d1, int d2, int d3, const T &init) : d1(d1), d2(d2), d3(d3), shift(d2 * d3), sz(d1 * d2 * d3) {
        b = new T[sz];
        e = b + sz;
        fill(b, e, init);
    }

    id6(T *b, int d1, int d2, int d3) : b(b), e(b + d1 * d2 * d3), d1(d1), d2(d2), d3(d3), shift(d2 * d3),
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

        if (i1 < 0 || i1 >= d1 || i2 < 0 || i2 >= d2 || i3 < 0 || i3 >= d3) {
            throw "Out of bounds";
        }

        return b[i1 * shift + i2 * d3 + i3];
    }

    const T &operator()(int i1, int i2, int i3) const {

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
};

template<typename T>
class id1 {
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
    id1() : b(nullptr), e(nullptr), d1(0), d2(0), d3(0), d4(0), shift1(0), shift2(0), sz(0) {}

    id1(int d1, int d2, int d3, int d4) : d1(d1), d2(d2), d3(d3), d4(d4), shift1(d2 * d3 * d4), shift2(d3 * d4),
                                            sz(d1 * d2 * d3 * d4) {
        b = new T[sz];
        e = b + sz;
    }

    id1(int d1, int d2, int d3, int d4, const T &init) : d1(d1), d2(d2), d3(d3), d4(d4), shift1(d2 * d3 * d4),
                                                           shift2(d3 * d4), sz(d1 * d2 * d3 * d4) {
        b = new T[sz];
        e = b + sz;
        fill(b, e, init);
    }

    id1(T *b, int d1, int d2, int d3, int d4) : d1(d1), d2(d2), d3(d3), d4(d4), shift1(d2 * d3 * d4), shift2(d3 * d4),
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

        if (i1 < 0 || i1 >= d1 || i2 < 0 || i2 >= d2 || i3 < 0 || i3 >= d3 || i4 < 0 || i4 >= d4) {
            throw "Out of bounds";
        }

        return b[i1 * shift1 + i2 * shift2 + i3 * d4 + i4];
    }

    const T &operator()(int i1, int i2, int i3, int i4) const {

        if (i1 < 0 || i1 >= d1 || i2 < 0 || i2 >= d2 || i3 < 0 || i3 >= d3 || i4 < 0 || i4 >= d4) {
            throw "Out of bounds";
        }

        return b[i1 * shift1 + i2 * shift2 + i3 * d4 + i4];
    }

    id3<T> operator[](int at) {

        if (at < 0 || at >= d1) {
            throw "Out of bounds";
        }

        return id6<T>(b + at * shift1, d2, d3, d4);
    }
};


inline bool isWhitespace(int c) {
    return isspace(c) || c == EOF;
}

class Input {
private:
    istream &in;
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
                return sgn * res * dPower(10, readInt());
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
                    return sgn * (res + add * dPower(10, -length)) * dPower(10, readInt());
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
            res += add * dPower(10, -length);
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
    void printSingle(const id3<T> &array) {
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


class id0 : public NumberIterator {
public:
    id0(int v) : NumberIterator(v) {}

    id0 &operator++() {
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





class TaskH {
public:
    void solve(istream &inp, ostream &outp) {
        Input in(inp);
        Output out(outp);

        int id5 = 1000;

        int n = in.readInt();
        int q = in.readInt();

        auto a = in.readIntArray(n);

        int parts = (n + id5 - 1) / id5;
        arri st(parts);
        arri end(parts);
        arr<vi> mn(parts);
        arr<vi> mx(parts);
        for (int i : range(parts)) {
            st[i] = i * id5;
            end[i] = min((i + 1) * id5, n);
            mn[i].reserve(end[i] - st[i]);
            mx[i].reserve(end[i] - st[i]);
        }
        auto build = [&](int at) {
            mn[at].clear();
            mx[at].clear();
            for (int j : RevRange(end[at], st[at])) {
                int cMax = a[j];
                int cMin = a[j];
                while (!mn[at].empty() && mx[at].back() > cMin) {
                    maxim(cMax, mx[at].back());
                    minim(cMin, mn[at].back());
                    mx[at].pop_back();
                    mn[at].pop_back();
                }
                mx[at].push_back(cMax);
                mn[at].push_back(cMin);
            }
        };
        for (int i : range(parts)) {
            build(i);
        }
        arri posTo(parts);
        arri posFr(parts);
        vi id;
        id.reserve(2 * parts + 1);
        vi cmn;
        vi cmx;
        cmn.reserve(2 * parts + 1);
        cmx.reserve(2 * parts + 1);
        for (int x : range(q)) {
            int pp = in.readInt() - 1;
            int nVal = in.readInt();
            a[pp] = nVal;
            build(pp / id5);
            id.clear();
            cmn.clear();
            cmx.clear();
            for (int i : RevRange(parts)) {
                posTo[i] = mn[i].size() - 1;
                posFr[i] = 0;
                if (id.empty() || cmx.back() < mn[i][0]) {
                    id.push_back(i);
                    cmn.push_back(mn[i][0]);
                    cmx.push_back(mx[i].back());
                    continue;
                }
                int nmn = mn[i][0];
                int nmx = mx[i][0];
                while (!id.empty()) {
                    if (cmx.back() < nmn) {
                        break;
                    }
                    if (id.back() == -1) {
                        maxim(nmx, cmx.back());
                        minim(nmn, cmn.back());
                        id.pop_back();
                        cmx.pop_back();
                        cmn.pop_back();
                        continue;
                    }
                    if (nmn < mx[id.back()][posFr[id.back()]]) {
                        maxim(nmx, cmx.back());
                        minim(nmn, cmn.back());
                        id.pop_back();
                        cmx.pop_back();
                        cmn.pop_back();
                        continue;
                    }
                    int l = posFr[id.back()];
                    int r = posTo[id.back()] - 1;
                    while (l < r) {
                        int m = (l + r + 1) >> 1;
                        if (mx[id.back()][m] > nmn) {
                            r = m - 1;
                        } else {
                            l = m;
                        }
                    }
                    maxim(nmx, cmx.back());
                    minim(nmn, mn[id.back()][l + 1]);
                    posTo[id.back()] = l;
                    cmx.back() = mx[id.back()][l];
                    break;
                }
                int l = 0;
                int r = mn[i].size() - 1;
                while (l < r) {
                    int m = (l + r + 1) >> 1;
                    if (mn[i][m] > nmx) {
                        r = m - 1;
                    } else {
                        l = m;
                    }
                }
                maxim(nmx, mx[i][l]);
                id.push_back(-1);
                cmx.push_back(nmx);
                cmn.push_back(nmn);
                if (l < mn[i].size() - 1) {
                    posFr[i] = l + 1;
                    id.push_back(i);
                    cmn.push_back(mn[i][l + 1]);
                    cmx.push_back(mx[i].back());
                }
            }
            int answer = 0;
            for (int i : id) {
                if (i == -1) {
                    answer++;
                } else {
                    answer += posTo[i] - posFr[i] + 1;
                }
            }
            out.printLine(answer);
        }
    }
};


int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    TaskH solver;
    std::istream &in(std::cin);
    std::ostream &out(std::cout);
    solver.solve(in, out);
    return 0;
}
