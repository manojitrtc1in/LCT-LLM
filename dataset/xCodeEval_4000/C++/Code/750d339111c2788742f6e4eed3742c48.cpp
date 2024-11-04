#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
#define all(x) (x).begin(),(x).end()

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
struct TraitsSumSet {
    

    static Value valueNeutral() { return Value(0); }
    

    static Extra extraNeutral() { return Extra(-1); }
    

    template<typename Node>
    static Value getValue(const Node& src) {
        return src.extra() == extraNeutral() ? src.value() : src.extra() * src.len();
    }
    

    template<typename NodeRoot, typename NodeLt, typename NodeRt>
    static void pull(NodeRoot root, const NodeLt& lt, const NodeRt& rt) {
        root.value() = getValue(lt) + getValue(rt);
    }
    

    template<typename NodeDst, typename NodeSrc>
    static void push(NodeDst dst, const NodeSrc& src) {
        dst.extra() = src.extra();
    }
};


namespace FastIO {
    struct Reader {
        private:
            FILE* file; std::vector<char> buffer; int pos;
            void read();
            bool was;
        public:
            Reader(FILE* file_ = stdin, const int size_ = 1 << 16)
                : file(file_), buffer(size_, '\0'), pos(size_), was(true) { }
            operator bool() const { return was; }
            char getChar();
            std::string getStr();
            std::string getLine();
            template<typename T> T getInt();
            template<typename T> T getReal();
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
            void putChar(char c);
            void putStr(const std::string&);
            template<typename T> void putInt(T value, int width = 0, char fill = ' ');
            template<typename T> void putReal(T value, int precision = 6, int width = 0, char fill = ' ');
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

typedef std::vector<int> vi;
typedef std::vector<vi> vvi;
const int UNDEF = -1;
struct DS {
    static const int gsize = 404;
    vi arr, gset, gsum;
    void build(int n, int v) {
        arr.assign(n, v);
        gset.assign((n + gsize - 1) / gsize, UNDEF);
        gsum.assign((n + gsize - 1) / gsize, 0);
        for (int i = 0; i < n; ++i) { gsum[i / gsize] += arr[i]; }
    }
    void push(int g) {
        if (gset[g] != UNDEF) {
            gsum[g] = 0;
            for (int i = g * gsize; i < std::min((g+1)*gsize, isz(arr)); ++i) {
                gsum[g] += (arr[i] = gset[g]);
            }
            gset[g] = UNDEF;
        }
    }
    void set(int l, int r, int v) {
        const int gl = l / gsize, gr = r / gsize;
        push(gl);
        if (gl == gr) {
            for (int i = l; i <= r; ++i) {
                gsum[gl] += v - arr[i]; arr[i] = v;
            }
        } else {
            for (int i = l; i < (gl + 1) * gsize; ++i) {
                gsum[gl] += v - arr[i]; arr[i] = v;
            }
            push(gr);
            for (int i = gr * gsize; i <= r; ++i) {
                gsum[gr] += v - arr[i]; arr[i] = v;
            }
            for (int g = gl + 1; g < gr; ++g) { gset[g] = v; }
        }
    }
    int get(int l, int r) {
        const int gl = l / gsize, gr = r / gsize;
        push(gl);
        int ret = 0;
        if (gl == gr) {
            for (int i = l; i <= r; ++i) { ret += arr[i]; }
        } else {
            for (int i = l; i < (gl + 1) * gsize; ++i) { ret += arr[i]; }
            push(gr);
            for (int i = gr * gsize; i <= r; ++i) { ret += arr[i]; }
            for (int g = gl + 1; g < gr; ++g) {
                ret += (gset[g] == UNDEF ? gsum[g] : gsize * gset[g]);
            }
        }
        return ret;
    }
};

typedef unsigned long long ull;

struct Edge { int u, v; };
bool operator<(const Edge& a, const Edge& b) {
    return a.u < b.u || (a.u == b.u && a.v < b.v);
}

struct Tree {
    const int n;
    

    std::vector<Edge> edges;
    vi left, right, begin, after, parent;
    int time;
    Tree(int n_) : n(n_) {
        

        right.resize(1+n);
        left.resize(1+n);
        parent.resize(1+n);
        begin.assign(1+n, INT_MAX);
        after.assign(1+n, INT_MIN);
        time = 0;
        edges.reserve(2 * n);
    }
    void add_edge(int u, int v) {
        
        edges.push_back(Edge{u,v});
        edges.push_back(Edge{v,u});
    }
    void build() {
        std::sort(all(edges));
        for (int i = 0; i < isz(edges); ++i) {
            const auto &e = edges[i];
            begin[e.u] = std::min(begin[e.u], i);
            after[e.u] = std::max(after[e.u], i+1);
        }
    }
    void euler_tour() {
        std::vector<int> stack{1};
        stack.reserve(1+n);
        std::vector<bool> vis(1+n, false);
        while (!stack.empty()) {
            const auto u = stack.back();
            if (!vis[u]) {
                vis[u] = 1;
                time++;
                left[u] = time - 1;
                const int p = parent[u];
                for (int eid = begin[u]; eid < after[u]; ++eid) {
                    const int v = edges[eid].v;
                    if (v == p) { continue; }
                    assert(!vis[v]);
                    parent[v] = u;
                    stack.push_back(v);
                }
            } else {
                right[u] = time - 1;
                stack.pop_back();
            }
        }
    }
};
int main() {
    FastIO::Reader fin;
    FastIO::Writer fout;
    for (int n; fin >> n;) {
        Tree tree(n);
        for (int i = 1, u, v; i < n; ++i) {
            fin >> u >> v;
            tree.add_edge(u,v);
        }
        tree.build();
        tree.euler_tour();
        SegmentTreeLazy::SegmentTree<int,int,TraitsSumSet<int,int>> subtree;
        subtree.build(std::vector<int>(n,1));
        int q; fin >> q;
        while (q--) {
            int t, v; fin >> t >> v;
            const int lt = tree.left[v], rt = tree.right[v], par = tree.parent[v];
            const int parpos = tree.left[par];
            if (t == 1) {
                int sum = subtree.get(lt, rt);
                subtree.update(lt,rt,0);
                if (sum && par != 0) { subtree.update(parpos,parpos,1); }
            } else if (t == 2) {
                subtree.update(lt,lt,1);
            } else {
                int sum = subtree.get(lt, rt);
                fout << (sum ? "0\n" : "1\n");
            }
        }
    }
    return 0;
}

namespace FastIO {
       
    void Reader::read() {
        if (!buffer.empty()) {
            buffer.resize(fread(&buffer[0], 1, (int)buffer.size(), file)); pos = 0; 
        }
    }
       
    char Reader::getChar() {
        if (pos == (int)buffer.size()) { read(); }
        if (pos == (int)buffer.size()) { was = false; return EOF; } 
        else { was = true; return buffer[pos++]; }
    }
        
    std::string Reader::getStr() {
        char c = ' ';
        while (std::isspace(c)) { c = getChar(); }
        std::string answ;
        while (c != EOF && !std::isspace(c)) { answ.push_back(c); c = getChar(); }
        was = !answ.empty();
        return answ;
    }
    
    std::string Reader::getLine() {
        char c = '\n';
        while (c == '\n') { c = getChar(); }
        std::string answ;
        while (c != '\n' && c != EOF) { answ.push_back(c); c = getChar(); }
        was = !answ.empty();
        return answ;
    }
        
    template<typename T>
    T Reader::getInt() {
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
   
    template<typename T>
    T Reader::getReal() {
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
    
    void Writer::putChar(char c) {
        if (pos == (int)buffer.size() || c == EOF) { 
            fwrite(&buffer[0], 1, pos, file); pos = 0; 
        }
        if (c != EOF) { buffer[pos++] = c; }
    }
    
    void Writer::putStr(const std::string& s) {
        for (auto it : s) { 
            putChar(it); 
        } 
    }
    
    template<typename T>
    void Writer::putInt(T value, int width, char fill) {
        bool positive = !(value < 0);
        if (value < 0) { value = -value; }
        char buf[24]; int p = 0;
        do { buf[p++] = char(value % 10 + '0'); value /= 10; } while (value > 0);
        if (!positive) { buf[p++] = '-'; }
        while (p < width) buf[p++] = fill;
        while (p > 0) putChar(buf[--p]);
    }
    
    template<typename T>
    void Writer::putReal(T value, int precision, int width, char fill) {
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
}