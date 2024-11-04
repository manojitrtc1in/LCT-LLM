
#pragma GCC optimize("Ofast,unroll-loops")


#include <bits/stdc++.h>
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









#define isz(x) (int)(x).size()


using ll = long long;
template<int mod>
struct IntMod {
    static int add(int a, int b) { return (a += b) >= mod ? a -= mod : a; }
    static int sub(int a, int b) { return (a -= b) < 0 ? a += mod : a; }
    int value;
    IntMod(ll value_ = 0)
    {
        if (value_ < 0) { value = int(mod - (-value_) % mod); }
        else if (value_ >= mod) { value = int(value_ % mod); }
        else { value = (int)value_; }
    }
    IntMod pow(ll n) const {
        if (n == 0) { return IntMod(1); }
        else if (n < 0) { return (IntMod(1) / *this).pow(-n); }
        if (value <= 1) { return *this; }
        IntMod r = 1, a = *this;
        while (n > 0) {
            if (n & 1) {
                r *= a;
            }
            a *= a;
            n >>= 1;
        }
        return r;
    }
    IntMod operator-() const { return IntMod(mod-value); }
    IntMod operator*(IntMod other) const { return IntMod(value * 1LL * other.value); }
    IntMod operator/(IntMod other) const { return *this * other.pow(mod-2); }
    IntMod operator+(IntMod other) const { return IntMod(add(value, other.value)); }
    IntMod operator-(IntMod other) const { return IntMod(sub(value, other.value)); }
    IntMod& operator*=(IntMod other) { return *this = *this * other; }
    IntMod& operator/=(IntMod other) { return *this = *this / other; }
    IntMod& operator+=(IntMod other) { return *this = *this + other; }
    IntMod& operator-=(IntMod other) { return *this = *this - other; }
    bool operator<(IntMod other) const { return value < other.value; }
};
template<int Mod> IntMod<Mod> pow(IntMod<Mod> v, ll n) { return v.pow(n); }
const int mod = 998244353;
using Int = IntMod<mod>;
template<typename T>
struct PrefixProduct {
    std::vector<T> data;
    template<typename T2>
    PrefixProduct(const std::vector<T2>& arr) {
        data.assign(isz(arr)+1, T(1));
        for (int i = 0; i < isz(arr); i++) {
            data[i+1] = data[i] * arr[i];
        }
    }
    T operator()(const int begin, const int after) const { return data[after] / data[begin]; }
};
template<typename T>
struct SD {
    const int gsize = 512;
    std::vector<T> data, gsum, gmul;
    SD(const std::vector<T>& data_) : data(data_) {
        gsum.resize((isz(data) + gsize - 1) / gsize, 0);
        gmul.resize((isz(data) + gsize - 1) / gsize, 1);
        for (int i = 0; i < isz(data); i++) {
            gsum[i / gsize] += data[i];
        }
    }
    void push(int g) {
        if (gmul[g] == T(1)) return;
        const auto coeff = gmul[g];
        gmul[g] = 1;
        const int begin = g * gsize, after = std::min(isz(data), (g+1) * gsize);
        for (int i = begin; i < after; i++) {
            data[i] *= coeff;
        }
    }
    T sum(int l, int r) {
        const int gl = l / gsize, gr = r / gsize;
        T res(0);
        if (gl == gr) {
            push(gl);
            for (int i = l; i <= r; i++) {
                res += data[i];
            }
        } else {
            push(gl);
            push(gr);
            for (int i = l; i < (gl + 1) * gsize; i++) {
                res += data[i];
            }
            for (int g = gl+1; g < gr; g++) {
                res += gsum[g];
            }
            for (int i = gr * gsize; i <= r; i++) {
                res += data[i];
            }
        }
        return res;
    }
    void mul(int l, int r, T coeff) {
        const int gl = l / gsize, gr = r / gsize;
        if (gl == gr) {
            push(gl);
            for (int i = l; i <= r; i++) {
                gsum[gl] -= data[i];
                data[i] *= coeff;
                gsum[gl] += data[i];
            }
        } else {
            push(gl);
            push(gr);
            for (int i = l; i < (gl + 1) * gsize; i++) {
                gsum[gl] -= data[i];
                data[i] *= coeff;
                gsum[gl] += data[i];
            }
            for (int g = gl+1; g < gr; g++) {
                gsum[g] *= coeff;
                gmul[g] *= coeff;
            }
            for (int i = gr * gsize; i <= r; i++) {
                gsum[gr] -= data[i];
                data[i] *= coeff;
                gsum[gr] += data[i];
            }
        }
    }
};
template<typename T> bool operator>(const T& a, const T& b) { return b < a; }
template<typename T> bool operator>=(const T& a, const T& b) { return !(a < b); }
template<typename T> bool operator<=(const T& a, const T& b) { return !(a > b); }
template<typename T> bool operator!=(const T& a, const T& b) { return a < b || b < a; }
template<typename T> bool operator==(const T& a, const T& b) { return !(a != b); }
const bool debug = 0;
namespace SegmentTreeLazy {
    
    
    
    
    template<typename Value, typename Extra>
    struct TraitsMinAdd {
        

        static Value valueNeutral() { return std::numeric_limits<Value>::max(); }
        

        static Extra extraNeutral() { return Extra(0); }
        

        template<typename Node>
        static Value getValue(const Node& src) {
            return src.value() + src.extra();
        }
        

        template<typename NodeRoot, typename NodeLt, typename NodeRt>
        static void pull(NodeRoot root, const NodeLt& lt, const NodeRt& rt) {
            root.value() = std::min(getValue(lt), getValue(rt));
        }
        

        template<typename NodeDst, typename NodeSrc>
        static void push(NodeDst dst, const NodeSrc& src) {
            dst.extra() += src.extra();
        }
    };
    
    
    template<typename Value, typename Extra>  struct TraitsMaxAdd;
    
    
    template<typename Value = int64_t, typename Extra = int64_t, typename Traits = TraitsMinAdd<Value, Extra> >
    struct SegmentTree {
        
        
        struct Node {
            Value value;
            
            Extra extra;
            
            Node(Value value_ = Traits::valueNeutral(), Extra extra_ = Traits::extraNeutral())
                : value(value_), extra(extra_) { }
            
            Value getValue(int l, int r) const { return Traits::getValue(NodeWrapper<Node>(l, r, *this)); }
        };
        
        
        template<typename NodeType>
        struct NodeWrapper {
            int l, r;
            NodeType node;
            NodeWrapper(int l_, int r_, NodeType node_)
                : l(l_), r(r_), node(node_) { }
            int  left() const { return l; }
            int right() const { return r; }
            int   mid() const { return (l+r)/2; }
            int   len() const { return r - l + 1; }
            Value& value() { return node.value; }
            Extra& extra() { return node.extra; }
            const Value& value() const { return node.value; }
            const Extra& extra() const { return node.extra; }
        };
        
        
        int n; std::vector<Node> data;
        
        
        
        void resize(int n_) {
            n = n_;
            data.assign(2 * n - 1, Node());
        }
        
        
        void push(int v, int l, int r, int m) {
            if (data[v].extra != Traits::extraNeutral()) {
                Traits::push(
                    NodeWrapper<Node&>(l, m, data[v+1]), 
                    NodeWrapper<const Node&>(l, r, data[v])
                );
                Traits::push(
                    NodeWrapper<Node&>(m+1, r, data[v+2*(m-l+1)]), 
                    NodeWrapper<const Node&>(  l, r, data[v])
                );
                data[v].extra = Traits::extraNeutral();
            }
        }
        
        
        void pull(int v, int l, int r, int m) {
            assert(data[v].extra == Traits::extraNeutral());
            Traits::pull(
                NodeWrapper<Node&>(  l, r, data[v]), 
                NodeWrapper<const Node&>(  l, m, data[v+1]), 
                NodeWrapper<const Node&>(m+1, r, data[v+2*(m-l+1)])
            );
        }
        
        
        template<typename T>
        void build(const std::vector<T>& arr, const int v, const int tl, const int tr) {
            if (tl == tr) {
                data[v] = Node(arr[tl]);
            } else {
                const int tm = (tl + tr) / 2;
                build(arr, v+1,   tl, tm);
                build(arr, v+2*(tm-tl+1), tm+1, tr);
                pull(v, tl, tr, tm);
            }
        }
        
        template<typename T>
        void build(const std::vector<T>& arr) { 
            resize((int)arr.size());
            build(arr, 0, 0, n-1);
        }

        
        Node get(int ql, int qr, const int v, const int tl, const int tr) {
            if (ql == tl && qr == tr) {
                return data[v];
            } else {
                int tm = (tl + tr) / 2;
                push(v, tl, tr, tm);
                Node ret;
                if (qr <= tm) {
                    ret = get(ql, qr, v+1,   tl, tm);
                } else if (ql > tm) {
                    ret = get(ql, qr, v+2*(tm-tl+1), tm+1, tr);
                } else {
                    const auto lt = get(  ql, tm, v+1,   tl, tm);
                    const auto rt = get(tm+1, qr, v+2*(tm-tl+1), tm+1, tr);
                    Traits::pull(
                        NodeWrapper<Node&>(  ql, qr, ret), 
                        NodeWrapper<const Node&>(  ql, tm, lt), 
                        NodeWrapper<const Node&>(tm+1, qr, rt)
                    );
                }
                pull(v, tl, tr, tm);
                return ret;
            }
        }
        
        Value get(const int ql, const int qr) { return get(ql, qr, 0, 0, n-1).getValue(ql, qr); }
        
        
        void update(const int ql, const int qr, const Extra& extra, const int v, const int tl, const int tr) {
            if (ql == tl && tr == qr) {
                Traits::push(
                    NodeWrapper<Node&>(tl, tr, data[v]),
                    NodeWrapper<Node>(ql, qr, Node(Traits::valueNeutral(), extra))
                );
            } else {
                int tm = (tl + tr) / 2;
                push(v, tl, tr, tm);
                if (qr <= tm) {
                    update(ql, qr, extra, v+1, tl, tm);
                } else if (ql > tm) {
                    update(ql, qr, extra, v+2*(tm-tl+1),tm+1,tr);
                } else {
                    update(ql, tm, extra, v+1,   tl, tm);
                    update(tm+1, qr, extra, v+2*(tm-tl+1), tm+1, tr);
                }
                pull(v, tl, tr, tm);
            }
        }

        void update(const int ql, const int qr, const Extra& extra) {
            update(ql, qr, extra, 0, 0, n-1); 
        }

    };
    
    
    template<typename Value, typename Extra>
    struct TraitsMaxAdd {
        

        static Value valueNeutral() { return std::numeric_limits<Value>::min(); }
        

        static Extra extraNeutral() { return Extra(0); }
        

        template<typename Node>
        static Value getValue(const Node& src) {
            return src.value() + src.extra();
        }
        

        template<typename NodeRoot, typename NodeLt, typename NodeRt>
        static void pull(NodeRoot root, const NodeLt& lt, const NodeRt& rt) {
            root.value() = std::max(getValue(lt), getValue(rt));
        }
        

        template<typename NodeDst, typename NodeSrc>
        static void push(NodeDst dst, const NodeSrc& src) {
            dst.extra() += src.extra();
        }
    };   
}
template<typename Value, typename Extra>
struct TraitsSumMul {
    

    static Value valueNeutral() { return Value(0); }
    

    static Extra extraNeutral() { return Extra(1); }
    

    template<typename Node>
    static Value getValue(const Node& src) {
        return src.value() * src.extra();
    }
    

    template<typename NodeRoot, typename NodeLt, typename NodeRt>
    static void pull(NodeRoot root, const NodeLt& lt, const NodeRt& rt) {
        root.value() = getValue(lt) + getValue(rt);
    }
    

    template<typename NodeDst, typename NodeSrc>
    static void push(NodeDst dst, const NodeSrc& src) {
        dst.extra() *= src.extra();
    }
};
using SegTree = SegmentTreeLazy::SegmentTree<Int, Int, TraitsSumMul<Int,Int>>;
int main() {
    FastIO::Reader cin(stdin);
    FastIO::Writer cout(stdout);
    for (int n, q; cin >> n >> q; ) {
        std::vector<Int> p(n);
        for (int i = 0, tmp; i < n; i++) {
            cin >> tmp;
            p[i] = Int(tmp) / 100;
        }
        PrefixProduct<Int> prod(p);
        std::vector<Int> temp(n);
        for (int i = 0; i < n; i++) {
            temp[i] = prod(0, i);
        }
        

        SegTree segtree;
        segtree.build(temp);
        std::set<int> mirrors;
        mirrors.insert(n);
        mirrors.insert(0);
        

        segtree.update(0,n-1,Int(1)/prod(0, n));
        while (q--) {
            int v; cin >> v; v--;
            auto it = mirrors.find(v);
            if (it == mirrors.end()) {
                auto curr = mirrors.insert(v).first;
                auto prev = std::prev(curr);
                auto next = std::next(curr);
                

                const auto rightProd = prod(*curr, *next);
                

                segtree.update(*prev,*curr-1,rightProd);
                

            } else {
                auto curr = it;
                auto prev = std::prev(curr);
                auto next = std::next(curr);
                

                const auto rightProd = prod(*curr, *next);
                

                segtree.update(*prev, *curr-1, Int(1)/rightProd);
                

                mirrors.erase(it);
            }
            cout << (segtree.get(0, n-1)).value << '\n';
        }
    }
    return 0;
}