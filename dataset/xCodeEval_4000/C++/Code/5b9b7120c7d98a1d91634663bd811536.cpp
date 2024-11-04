#pragma GCC optimize("O3")
#include <bits/stdc++.h>
const int debug = false;

namespace FastIO {
    struct Reader {
    private:
        FILE* file; std::vector<char> buffer; int pos; bool was;
        void read() {
            if (!buffer.empty()) {
                buffer.resize(fread(&buffer[0], 1, (int)buffer.size(), file)); pos = 0; 
            }
        }
    public:
        Reader(FILE* file_ = stdin, const int size_ = 1 << 16)
            : file(file_), buffer(size_, '\0'), pos(size_), was(true) { }
        operator bool() const { return was; }
        char getChar() {
            if (pos == (int)buffer.size()) { read(); }
            if (pos == (int)buffer.size()) { was = false; return EOF; } 
            else { was = true; return buffer[pos++]; }
        }
        std::string getStr() {
            char c = ' ';
            while (std::isspace(c)) { c = getChar(); }
            std::string answ;
            while (c != EOF && !std::isspace(c)) { answ.push_back(c); c = getChar(); }
            was = !answ.empty();
            return answ;
        }
        std::string getLine() {
            char c = '\n';
            while (c == '\n') { c = getChar(); }
            std::string answ;
            while (c != '\n' && c != EOF) { answ.push_back(c); c = getChar(); }
            was = !answ.empty();
            return answ;
        }
        template<typename T> T getInt() {
            char c = '?';
            while (!(c == '-' || ('0' <= c && c <= '9') || c == EOF)) { c = getChar(); }
            bool positive = true;
            if (c == '-') { positive = false; c = getChar(); }
            T answ(0);
            bool flag = false;
            while ('0' <= c && c <= '9') { flag = true; (answ *= 10) += (c - '0'); c = getChar(); }
            was = flag;
            return positive ? answ : -answ;
        }
        template<typename T> T getReal() {
            bool flag = false;
            char c = '?';
            while (!(c == '-' || ('0' <= c && c <= '9') || c == EOF)) { c = getChar(); }
            bool positive = (c != '-');
            if (c == '-') { c = getChar(); }
            long long first = 0;
            while ('0' <= c && c <= '9') { flag = true; (first *= 10) += (c - '0'); c = getChar(); }
            was = flag;
            if (c != '.') { return T(positive ? first : -first); }
            c = getChar();
            long long second = 0, pow = 1;
            while ('0' <= c && c <= '9') { (second *= 10) += (c - '0'); c = getChar(); pow *= 10; }
            T answ = first + (T)second / (T)pow;
            return positive ? answ : -answ;
        }
    };
    
    Reader& operator>>(Reader& reader, char& c) { return c = reader.getChar(), reader; }
    
    Reader& operator>>(Reader& reader, std::string& s) { return s = reader.getStr(), reader; }
    
    template<class T> typename std::enable_if<std::is_floating_point<T>::value, Reader&>::type
    operator>>(Reader& reader, T& t) { return t = reader.getReal<T>(), reader; }
    
    template<class T> typename std::enable_if<std::is_integral<T>::value, Reader&>::type
    operator>>(Reader& reader, T& t) { return t = reader.getInt<T>(), reader; }
    
    template<class T> Reader& operator>>(Reader& reader, std::vector<T>& vec) {
        for (auto &it : vec) { reader >> it; }
        return reader;
    }
    
    struct Writer {
    private:
        FILE* file; std::vector<char> buffer; int pos;
        int defaultPrecision, defaultWidth; char defaultFill;
    public:
        Writer(FILE* file_ = stdout, const int size_ = 1 << 16) 
            : file(file_), buffer(size_, '\0'), pos(0), defaultPrecision(6), defaultWidth(0), defaultFill(' ') { }
        ~Writer() { flush(); }
        void flush() { putChar(EOF); }
        void setprecision(int precision) { defaultPrecision = precision; }
        void setw(int width) { defaultWidth = width; }
        void setfill(char fill) { defaultFill = fill; }
        int getPrecision() const { return defaultPrecision; }
        int getWidth() const { return defaultWidth; }
        char getFill() const { return defaultFill; }
        void putChar(char c) {
            if (pos == (int)buffer.size() || c == EOF) { 
                fwrite(&buffer[0], 1, pos, file); pos = 0; 
            }
            if (c != EOF) { buffer[pos++] = c; }
        }
        void putStr(const std::string& s) { for (auto it : s) putChar(it); }
        template<typename T> void putInt(T value, int width = 0, char fill = ' ') {
            bool positive = !(value < 0);
            if (value < 0) { value = -value; }
            char buf[24]; int p = 0;
            do { buf[p++] = char(value % 10 + '0'); value /= 10; } while (value > 0);
            if (!positive) { buf[p++] = '-'; }
            while (p < width) buf[p++] = fill;
            while (p > 0) putChar(buf[--p]);
        }
        template<typename T> void putReal(T value, int precision = 6, int width = 0, char fill = ' ') {
            putInt((long long)value, width - precision - 1, fill);
            value = std::abs(value-(long long)value);
            if (precision == 0) { return; }
            putChar('.');
            #define PRINT_PART(cnt, pow) \
                while (precision >= cnt) { \
                    value *= pow; \
                    putInt((int)value, cnt, '0'); \
                    value -= (int)value; \
                    precision -= cnt; \
                }
            PRINT_PART(6,1000000)
            PRINT_PART(3,1000)
            PRINT_PART(1,10)
            #undef PRINT_PART
        }
    };
    
    Writer& operator<<(Writer& writer, const char c) { return writer.putChar(c), writer; }
    
    Writer& operator<<(Writer& writer, const std::string& s) { return writer.putStr(s), writer; }
    
    template<class T> typename std::enable_if<std::is_floating_point<T>::value, Writer&>::type
    operator<<(Writer& writer, const T& t) {
        writer.putReal(t, writer.getPrecision(), writer.getWidth(), writer.getFill());
        return writer; 
    }
    
    template<class T> typename std::enable_if<std::is_integral<T>::value, Writer&>::type
    operator<<(Writer& writer, const T& t) { 
        writer.putInt(t, writer.getWidth(), writer.getFill());
        return writer;
    }
}

char heap[200 * 1024 * 1024];
int size;
void * operator new(size_t cnt) {
    size += cnt;
    return heap+(size-cnt);
}
void operator delete(void* ptr) {}


#define isz(x) (int)(x).size()
#define all(x) (x).begin(),(x).end()
#define watchln(x) std::cerr << #x << " = " << x << std::endl
#define cerr cerr && debug && std::cerr




template<class X, class Y> int lowpos(const X& x, Y y) {
    return int(std::lower_bound(all(x), y) - x.begin());
}
template<class X, class Y> int uppos(const X& x, Y y) {
    return int(std::upper_bound(all(x), y) - x.begin());
}

template<class X> void reuniq(X& x) { x.erase(std::unique(all(x)), x.end()); }

using vi = std::vector<int>;
using vvi = std::vector<vi>;
using msi = std::multiset<int>;
using vmsi = std::vector<msi>;
using pii = std::pair<int,int>;
using vpii = std::vector<pii>;

const int INF = (int)1e9+7;

int Log2(int n) {
    int pow = 0;
    while ((1 << (pow+1)) <= n) {
        ++pow;
    }
    return pow;
}

template<typename T>
struct Fenwick {
    
    int size, pow2;
    
    std::vector<T> data;
    
    Fenwick(){}
    
    void build(const int size_) {
        size = size_;
        pow2 = (1 << Log2(size));
        data.assign(size, T());
    }

    

    T operator()(int r) const {
        T result = 0;
        for (; r >= 0; r = (r & (r+1)) - 1) {
            result += data[r];
        }
        return result;
    }

    

    void inc(int p, T delta) {
        for (; p < size; p = (p | (p+1))) {
            data[p] += delta;
        }
    }

    

    T operator()(int l, int r) const {
        return (*this)(r) - (*this)(l-1);
    }
    
    T operator[](int p) const { return (*this)(p,p); }
    
    

    int lower_bound(T s) const {
        int pos = 0;
        for (int p = pow2; p >= 1; p /= 2) {
            if (pos + p - 1 < size && data[pos + p - 1] < s) {
                s -= data[pos + p - 1];
                pos += p;
            }
        }
        return pos;
    }
    
    int upper_bound(T s) const {
        int pos = 0;
        for (int p = pow2; p >= 1; p /= 2) {
            if (pos + p - 1 < size && data[pos + p - 1] <= s) {
                s -= data[pos + p - 1];
                pos += p;
            }
        }
        return pos;
    }
};


struct Node {
    vi data;
    Fenwick<int> fenw;
    Node(){}
    void build(const std::vector<pii>& queries, int begin, int after) {
        data.reserve(after-begin);
        for (int i = begin; i < after; i++) {
            data.push_back(queries[i].second);
        }
        std::sort(all(data));
        reuniq(data);
        fenw.build(isz(data));
    }
    void insert(int x) {
        int i = lowpos(data, x);
        assert(0 <= i && i < isz(data));
        fenw.inc(i,+1);
    }
    void erase(int x) {
        int i = lowpos(data, x);
        assert(0 <= i && i < isz(data));
        fenw.inc(i,-1);
    }
    int min(int x) const {
        int i = uppos(data, x);
        if (i == isz(data)) return INF;
        assert(0 <= i && i < isz(data));
        

        

        int prev = fenw(i-1);
        int curr = fenw(i);
        int j = (curr == prev) ? fenw.upper_bound(curr) : i;
        return (j == isz(data) ? INF : data[j]);
    }
};

std::ostream& operator<<(std::ostream& os, const Node& node) {
    os << "{";
    for (int i = 0; i < isz(node.data); i++) {
        if (i > 0) os << ", ";
        os << "{" << node.data[i] << ": " << node.fenw[i] << "}";
    }
    return os << "}";
}

std::ostream& operator<<(std::ostream& os, const pii node) {
    return os << "{fi=" << node.first << ",se = " << node.second << "}";
}
template<typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& vec) {
    os << "{";
    for (int i = 0; i < isz(vec); i++) {
        if (i > 0) os << ", ";
        os << vec[i];
    }
    return os << "}";
}

struct SegTree {
    std::vector<Node> data;
    SegTree(const int n, const std::vector<pii>& queries) {
        data.resize(4 * n);
        build(0, 0, n, queries, 0, isz(queries));
    }
    inline void build(int v, int l, int r, const std::vector<pii>& queries, int begin, int after) {
        std::cerr << "build " << v << ' ' << l << ' ' << r << std::endl;
        watchln(vpii(queries.begin()+begin, queries.begin() + after));
        data[v].build(queries, begin, after);
        if (l+1 >= r) return;
        const int m = (l + r) / 2;
        auto it = int(std::lower_bound(queries.begin()+begin, queries.begin()+after, pii(m,0))-queries.begin());
        build(2*v+1, l, m, queries, begin, it);
        build(2*v+2, m, r, queries, it, after);
    }
    inline void insert(int v, int l, int r, int p, int x) {
        if (p < l || p >= r) return;
        std::cerr << "insert " << v << ' ' << l << ' ' << r << ' ' << p << ' ' << x << std::endl;
        watchln(data[v]);
        data[v].insert(x);
        watchln(data[v]);
        if (l + 1 == r) return;
        int m = (l + r) / 2;
        if (p < m) { insert(2*v+1,l,m,p,x); }
        else { insert(2*v+2,m,r,p,x); }
    }
    inline void insert(int p, int x) { insert(0, 0, isz(data) / 4, p, x); }
    inline void erase(int v, int l, int r, int p, int x) {
        if (p < l || p >= r) return;
        std::cerr << "erase " << v << ' ' << l << ' ' << r << ' ' << p << ' ' << x << std::endl;
        watchln(data[v]);
        data[v].erase(x);
        watchln(data[v]);
        if (l + 1 == r) return;
        int m = (l + r) / 2;
        if (p < m) { erase(2*v+1,l,m,p,x); }
        else { erase(2*v+2,m,r,p,x); }
    }
    inline void erase(int p, int x) { erase(0, 0, isz(data) / 4, p, x); }
    inline int min(int v, int l, int r, int ql, int qr, int x) {
        if (qr <= l || r <= ql) { return INF; } 
        std::cerr << "min " << v << ' ' << l << ' ' << r << ' ' << ql << ' ' << qr << ' ' << x << std::endl;
        if (ql <= l && r <= qr) {
            watchln(data[v]);
            int answ = data[v].min(x);
            std::cerr << "answ = " << (answ == INF ? "INF" : std::to_string(answ)) << std::endl;
            return answ;
        }
        const int m = (l + r) / 2;
        assert(r - l >= 2);
        return std::min(min(2*v+1,l,m,ql,qr,x),min(2*v+2,m,r,ql,qr,x));
    }
    inline int min(int ql, int qr, int x) {
        return min(0,0,isz(data)/4,ql,qr,x);
    }
};

struct Query {
    int t, x, y; 
};

const int ADD = 0, REM = 1, GET = 2;

std::mt19937 gen;
std::uniform_int_distribution<int> dist(1, (int)1e9);
const bool STRESS = 0;
int main() {
    FastIO::Reader cin;
    FastIO::Writer cout;
    

    

    int nQ = 200000; 
    if (!STRESS) cin >> nQ;
    std::vector<Query> queries(nQ);
    vi x, y; std::string s;
    for (auto &it : queries) {
        s = "add";
        if (!STRESS) cin >> s;
        if (s[0] == 'a') { it.t = ADD; }
        else if (s[0] == 'r') { it.t = REM; }
        else if (s[0] == 'f') { it.t = GET; }
        it.x = dist(gen);
        it.y = dist(gen);
        if (!STRESS) cin >> it.x >> it.y;
        x.push_back(it.x);
        y.push_back(it.y);
        std::cerr << "x = " << it.x << " y = " << it.y << std::endl;
    }
    std::sort(all(x));
    reuniq(x);
    std::sort(all(y));
    reuniq(y);
    std::vector<pii> points;
    for (auto &q : queries) {
        q.x = lowpos(x, q.x);
        q.y = lowpos(y, q.y);
        points.push_back(pii(q.y, q.x));
    }
    std::sort(all(points));
    reuniq(points);
    SegTree segtree(isz(y), points);
    vmsi pts(isz(x));
    for (const auto & q : queries) {
        std::cerr << "query " << q.t << " " << q.x << " " << q.y << std::endl;
        if (q.t == ADD) {
            segtree.insert(q.y, q.x);
            pts[q.x].insert(q.y);
        }
        if (q.t == REM) {
            

            assert(!pts[q.x].empty());
            auto it = pts[q.x].lower_bound(q.y);
            assert(it != pts[q.x].end() && *it == q.y);
            pts[q.x].erase(it);
            

            segtree.erase(q.y, q.x);
        }
        if (q.t == GET) {
            

            std::cerr << "min query on segment [" << q.y+1 << ", " << isz(y) << ") on value " << q.x << std::endl;
            int min = segtree.min(q.y+1, isz(y), q.x);
            std::cerr << "result is " << min << std::endl;
            if (min == INF) { cout << "-1\n"; }
            else {
                int x_ = x[min];
                assert(!pts[min].empty());
                auto up = pts[min].upper_bound(q.y);
                assert(up != pts[min].end());
                int y_ = y[*up];
                cout << x_ << ' ' << y_ << '\n';
            }
        }
    }
    return 0;
}