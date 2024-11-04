

































using namespace std;

namespace Dev_Ns_Macros {
    
    
    
    
    
    
    
    
    
    

    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    

    
    
    
    
    
    
    
    
    
    
    

    
    
    
    

}

const int modn = 998244353;

namespace Dev_Ns_Predefs {

    typedef int64_t intx;
    typedef uint64_t inte;
    typedef long double fltx;

    template <Tname T> il void minimize(T &a, T b) { if (b < a) a = b; }
    template <Tname T> il void maximize(T &a, T b) { if (b > a) a = b; }
    template <Tname T> il T& id3(T& l, const T& r) { return l > r ? l = r : l; }
    template <Tname T> il T& id1(T& l, const T& r) { return l < r ? l = r : l; }
    template <Tname T> il void id0(T &l, T &r){l ^= r; r ^= l; l ^= r;}
    il void swap(int& l, int &r) {id0(l, r);}
    il void swap(intx& l, intx &r) {id0(l, r);}
    template <Tname T> il void xReplace(T v, T &mx, T &sx) { if (v > mx) sx = mx, mx = v; else if (v > sx) sx = v; }
    template <Tname T> il void nReplace(T v, T &mn, T &sn) { if (v < mn) sn = mn, mn = v; else if (v < sn) sn = v; }
    template <Tname T, Tname R = int> il T smod(T x, R p = modn) { return x < 0 ? x + p : x; }
    template <Tname T, Tname R = int> il T amod(T x, R p = modn) { return x >= p ? x - p : x; }
    template <Tname T, Tname A, Tname R = int> il T submod(T &x, A v, R p = modn) { return x = smod(x - v, p); }
    template <Tname T, Tname A, Tname R = int> il T addmod(T &x, A v, R p = modn) { return x = amod(x + v, p); }
    template <Tname T> il T Max(T x, T y) { return x > y ? x : y; }
    template <Tname T> il T Min(T x, T y) { return x > y ? y : x; }

    const int bufsize = 1<<23;

    char inBuf[bufsize];
    unsigned int pBuf = bufsize;

    il int gchar() { if (pBuf == bufsize) pBuf = 0, fread(inBuf, 1, bufsize, stdin); return inBuf[pBuf++]; }
    il bool misblank(char c) { switch (c) { case ' ': case '\n': return true; default: return false; } }
    inline char opfr(bool(*j)(char) = misblank) { char c = gchar(); while (j(c)) c = gchar(); return c; }

    inline intx specialfr() {
        intx ret = 0, sym = 1; int c = 0;
        while (!isdigit(c)) {
            sym = c == '-' ? -1 : 1, c = gchar();
            if (c == EOF) return EOF;
        }
        while (isdigit(c)) {
            ret = ret * 10 + c - '0', c = gchar();
            if (c == EOF) return EOF;
        }
        return ret * sym;
    }

    inline intx fr() {
        intx ret = 0, sym = 1; int c = 0;
        while (!isdigit(c)) sym = c == '-' ? -1 : 1, c = gchar();
        while (isdigit(c)) ret = ret * 10 + c - '0', c = gchar();
        return ret * sym;
    }
    
    inline void wrtl(intx x) {
        int st[20], top = 0;
        if (x < 0) putchar('-'), x = -x;
        while (x) st[top++] = x % 10, x /= 10;
        if (!top) st[top++] = 0;
        while (top) putchar('0' + st[--top]);
    }

}
using namespace Dev_Ns_Predefs;

namespace Dev_Ns_MathT {
    
    template <size_t esize>
    struct Primetown {
        static function<void(int)> id4;
        static function<void(int, int)> id5;
        bool mark[esize];
        int prime[esize], pcnt;
        void run(const function<void(int)> f1 = id4,
            const function<void(int, int)> f2 = id5) {
            memset(mark, 0, sizeof mark), pcnt = 0;
            re (i, 2, (int)esize - 1) {
                if (!mark[i]) prime[++pcnt] = i, f1(i);
                r (j, pcnt) {
                    if (1ull * i * prime[j] >= esize) break;
                    mark[i * prime[j]] = true, f2(i * prime[j], prime[j]);
                    if (!(i % prime[j])) break;
                }
            }
        }
    };
    
}
using namespace Dev_Ns_MathT;

namespace Dev_Ns_Datastructures {

    struct utype {
        typedef uint64_t _uextend_t;
        typedef uint64_t _udesc_t;
        typedef uint32_t _ubit_t;
    };
    template<Tname T1, Tname T2, bool _cond> struct bindtype { using type = T2; };
    template<Tname T1, Tname T2> struct bindtype<T1, T2, true> { using type = T1; };
    template <size_t nsize = 114514u, utype::_udesc_t D = 10>
    struct id2 {
        typedef id2<nsize, D> _self_t;
        utype::_ubit_t bit[nsize]; size_t len;
        id2() : len(0) {}
        id2(const utype::_uextend_t a) { if (!a) len = 0; else _copy(a); }
        void _clear() { rre (i, 0, len - 1) bit[i] = 0; len = 0; }
        void _copy(utype::_uextend_t a) { for (_clear(); a; a /= D) bit[len++] = a % D; }
        void _detect() { while (len && !bit[len - 1]) --len; }
        void _add(const _self_t &a) {
            utype::_ubit_t adv = 0;
            size_t tlen = Max(len, a.len) + 1;
            for (size_t i = 0; i < tlen; ++i) {
                utype::_ubit_t tb = i < len ? bit[i] : 0;
                utype::_ubit_t rb = i < a.len ? a.bit[i] : 0;
                auto bsum = static_cast<Tname bindtype<utype::_uextend_t, utype::_ubit_t,
                    (D > numeric_limits<utype::_ubit_t>::max() / 2 + 1)>::type>(tb) + rb + adv;
                bit[i] = amod(bsum, D), adv = bsum >= D;
            }
            len = tlen, _detect();
        }
        void _mul(utype::_uextend_t a) {
            utype::_uextend_t adv = 0;
            for (size_t i = 0; i < len; ++i) {
                utype::_ubit_t tb = bit[i];
                bit[i] = (a * tb + adv) % D;
                adv = (a * tb + adv) / D;
            }
            while (adv) bit[len++] = adv % D, adv /= D;
        }
        void serialize(const function<char(utype::_ubit_t)> tr
            = [](const utype::_ubit_t a) { return '0' + a; }) {
            if (!len) putchar(tr(0));
            rre (i, 0, len - 1) putchar(tr(bit[i]));
        }
        template <size_t dsize, utype::_udesc_t nD>
        friend void dcast(const _self_t &a, id2<dsize, nD> &b) {
            b = 0;
            for (_self_t t(a); t; t._detect()) {
                utype::_uextend_t adv = 0;
                rre (i, 0, t.len - 1) {
                    utype::_ubit_t tb = t.bit[i]; adv *= D;
                    t.bit[i] = (adv + tb) / nD;
                    adv = (adv + tb) % nD;
                }
                b.bit[b.len++] = adv;
            }
        }
        operator bool() const { return len; }
        _self_t& operator =(const utype::_uextend_t a) { return !a ? _clear() : _copy(a), *this; }
        _self_t& operator +=(const _self_t &a) { return _add(a), *this; }
        _self_t& operator *=(const utype::_uextend_t a) { return _mul(a), *this; }
        friend _self_t operator +(const _self_t &a, const _self_t &b) { return _self_t(a) += b; }
        friend _self_t operator +(const _self_t &a, int b) { return _self_t(a) += b; }
        friend _self_t operator *(const _self_t &a, int b) { return _self_t(a) *= b; }
    };
    
    template <size_t maxsize>
    struct Ufset {
        int fa[maxsize];
        void clear() { rre (i, 0, maxsize - 1) fa[i] = i; }
        int top(int x) { return fa[x] == x ? x : fa[x] = top(fa[x]); }
        void merge(int x, int y) { fa[top(x)] = top(y); }
        bool check(int x, int y) { return top(x) == top(y); }
    };
    
    template <size_t maxp, size_t maxe, int mode = 0>
    struct Edgeset {
        int h[maxp], nxt[maxe], to[maxe], newp;
        Edgeset() : newp(1) {}
        void ae(int u, int v) { nxt[++newp] = h[u], to[newp] = v, h[u] = newp; }
        void ae2(int u, int v) { ae(u, v), ae(v, u); }
    };
    
    template <size_t maxp, size_t maxe>
    struct Edgeset<maxp, maxe, 1> {
        int h[maxp], nxt[maxe], to[maxe], newp;
        intx len[maxe];
        Edgeset() : newp(1) {}
        void ae(int u, int v, intx w) { nxt[++newp] = h[u],
            to[newp] = v, len[newp] = w, h[u] = newp; }
        void ae2(int u, int v, intx w) { ae(u, v, w), ae(v, u, w); }
    };
    
    template <size_t maxp, size_t maxe>
    struct Edgeset<maxp, maxe, 2> {
        int h[maxp], nxt[maxe], to[maxe], newp;
        intx len[maxe], flow[maxe];
        Edgeset() : newp(1) {}
        void ae(int u, int v, intx w, intx f) { nxt[++newp] = h[u],
            to[newp] = v, len[newp] = w, flow[newp] = f, h[u] = newp; }
        void ae2(int u, int v, intx w, intx f) { ae(u, v, w, f), ae(v, u, w, 0); }
    };
    
    template <size_t maxsize>
    struct Fwt {
        intx d[maxsize];
        void mark(int x, int v) { for (; x < (int)maxsize; x += lwb(x)) d[x] += v; }
        intx pres(int x) { intx ret = 0; for (; x; x -= lwb(x)) ret += d[x]; return ret; }
    };
    
    template <Tname T>
    struct Segment_Traits;
    
    template <Tname T, size_t usage>
    struct Segmenttree {
        T dat[usage * 4];
        int initialL, initialR;
        Segmenttree(int L = 1, int R = usage) : initialL(L), initialR(R) {}
        void _build(int k, int L, int R, const function<void(T&, int)> initializer) {
            if (L == R) initializer(dat[k], L);
            else {
                int mid = (L + R)>>1;
                _build(k<<1, L, mid, initializer);
                _build(k<<1|1, mid + 1, R, initializer);
                dat[k] = Segment_Traits<T>::merge(dat[k<<1], dat[k<<1|1]);
            }
        }
        void _pushdown(int k) {
            Segment_Traits<T>::pushdown(dat[k], dat[k<<1]);
            Segment_Traits<T>::pushdown(dat[k], dat[k<<1|1]);
            Segment_Traits<T>::cleartag(dat[k]);
        }
        void _update(int k, int L, int R, int x, int y, const function<void(T&)> painter) {
            if (L > y || R < x) return;
            else if (L >= x && R <= y) painter(dat[k]);
            else {
                int mid = (L + R)>>1; _pushdown(k);
                if (y <= mid) _update(k<<1, L, mid, x, y, painter);
                else if (x > mid) _update(k<<1|1, mid + 1, R, x, y, painter);
                else _update(k<<1, L, mid, x, y, painter),
                    _update(k<<1|1, mid + 1, R, x, y, painter);
                dat[k] = Segment_Traits<T>::merge(dat[k<<1], dat[k<<1|1]);
            }
        }
        void _modify(int k, int L, int R, int x, const function<void(T&)> modifier) {
            if (L == R) modifier(dat[k]);
            else {
                int mid = (L + R)>>1; _pushdown(k);
                if (x <= mid) _modify(k<<1, L, mid, x, modifier);
                else _modify(k<<1|1, mid + 1, R, x, modifier);
                dat[k] = Segment_Traits<T>::merge(dat[k<<1], dat[k<<1|1]);
            }
        }
        T _query(int k, int L, int R, int x, int y) {
            if (L >= x && R <= y) return dat[k];
            else {
                int mid = (L + R)>>1; _pushdown(k);
                if (y <= mid) return _query(k<<1, L, mid, x, y);
                else if (x > mid) return _query(k<<1|1, mid + 1, R, x, y);
                return Segment_Traits<T>::merge(_query(k<<1, L, mid, x, y),
                    _query(k<<1|1, mid + 1, R, x, y));
            }
        }
        
        void setbound(int L, int R) { initialL = L, initialR = R; }
        void build(const function<void(T&, int)> initializer) {
            _build(1, initialL, initialR, initializer); }
        void update(int x, int y, const function<void(T&)> painter) {
            _update(1, initialL, initialR, x, y, painter); }
        void modify(int x, const function<void(T&)> modifier) {
            _modify(1, initialL, initialR, x, modifier); }
        T query(int x, int y) { return _query(1, initialL, initialR, x, y); }
    };

    template <Tname T>
    struct Segment_Traits {
        static T merge(const T&, const T&) {}
        static void pushdown(const T&, T&) {}
        static void cleartag(T&) {}
    };
    
}
using namespace Dev_Ns_Datastructures;

const int maxn = 1e5 + 4;

il int kasumi(int a, int b) {
    int r = 1; a %= modn;
    for (; b; a = 1ll * a * a % modn, b >>= 1) if (b&1) r = 1ll * r * a % modn;
    return r;
}

int f[maxn], inf[maxn];
int T, n;

il int C(int a, int b) {
    if (a < b) return 0;
    return 1ll * f[a] * inf[b] % modn * inf[a - b] % modn;
}

il void solve() {
    n = fr();
    int z = 0, l = 0, c = 0;
    r (i, n) {
        if (opfr() == '1') {
            if (l) ++c, l = 0;
            else l = 1;
        } else ++z, l = 0;
    }
    putie(C(z + c, c));
}

int main() {
    f[0] = 1;
    r (i, maxn - 1) f[i] = 1ll * f[i - 1] * i % modn;
    inf[maxn - 1] = kasumi(f[maxn - 1], modn - 2);
    rre (i, 0, maxn - 2) inf[i] = 1ll * inf[i + 1] * (i + 1) % modn;
    T = fr();
    while (T--) solve();
    return 0;
}
