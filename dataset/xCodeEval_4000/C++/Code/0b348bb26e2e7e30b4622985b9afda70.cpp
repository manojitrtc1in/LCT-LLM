

#include <bits/stdc++.h>

#ifndef _IRACE_S_SHIT_LIKE_HEADER_

    #define _IRACE_S_SHIT_LIKE_HEADER_
    
    using namespace std;
    
    
    #define r(i, j) for (int i = 1; i <= (j); ++i)
    #define r2(i, j, t) for (int i = 1; i <= (j); i += (t))
    #define re(i, j, k) for (int i = (j); i <= (k); ++i)
    #define re2(i, j, k, t) for (int i = (j); i <= (k); i += (t))
    #define rr(i, j) for (int i = (j); i >= 1; --i)
    #define rr2(i, j, t) for (int i = (j); i >= 1; i -= (t))
    #define rre(i, j, k) for (int i = (k); i >= (j); --i)
    #define rre2(i, j, k, t) for (int i = (k); i >= (j); i -= (t))
    #define rgr(i, x, e) for (int i = ((e).h)[x]; i; i = ((e).nxt)[i])
    
    #define fst first
    #define snd second
    #define pb push_back
    #define mp make_pair
    #define ai = {}
    #define Reseti(x) freopen((x), "r", stdin)
    #define Reseto(x) freopen((x), "w", stdout)
    #define Resetio(x) freopen(x".in", "r", stdin), freopen(x".out", "w", stdout)
    #define Optimio ios::sync_with_stdio(false), cin.tie(0)
    #define Pi pair<int, int>
    #define Pl pair<intx, intx>
    #define Pf pair<fltx, fltx>
    #define LB lower_bound
    #define UB upper_bound
    #define lkly(x) __builtin_expect((x), 1)
    #define ulkly(x) __builtin_expect((x), 0)
    #define lwb(x) ((x)&(-(x)))
    #define il [[gnu::always_inline]] inline
    #define noret [[gnu::noreturn]]
    #define sconst static constexpr 
    #define Tname typename
    
    #define puti(x) printf("%d", x)
    #define putis(x) printf("%d ", x)
    #define putie(x) printf("%d\n", x)
    #define putd(x) printf("%lf", x)
    #define putds(x) printf("%lf ", x)
    #define putde(x) printf("%lf\n", x)
    #define putl(x) printf("%lld", x)
    #define putls(x) printf("%lld ", x)
    #define putle(x) printf("%lld\n", x)
    #define pute putchar('\n')
    #define putsp putchar(' ')
    
    #define fmax(a, b) ((a) > (b) ? (a) : (b))
    #define fmin(a, b) ((a) < (b) ? (a) : (b))
    #define fmaximize(a, b) ((a) = (b) > (a) ? (b) : (a))
    #define fminimize(a, b) ((a) = (b) < (a) ? (b) : (a))
    
    
    namespace Ns_fnew {
        
        template <size_t size>
        struct static_memory_alloctor {
            char mem[size];
            size_t p = 0;
            inline void* allocate(size_t n) noexcept {
                void *ptr = mem + p;
                p += n;
                return ptr;
            }
            inline void destroy(void*) noexcept {}
        };
        
        template <size_t ms>
        using static_memory_m = static_memory_alloctor<ms << 20>;
    
    #ifndef PRESERVED_MEM
        #define PRESERVED_MEM 200
    #endif    
    
    #define FNEW_REGISTER_MEMORY(mem) \
        void* operator new(size_t n){return (mem).allocate(n);} \
        void operator delete(void* n)noexcept{return (mem).destroy(n);}
        
    }
    
    Ns_fnew::static_memory_m<PRESERVED_MEM> _preserved_pool;
    FNEW_REGISTER_MEMORY(_preserved_pool)
    
    inline namespace Dev_Ns_Predefs {
        
        #ifndef modn
            #define modn 998244353
        #endif
    
        typedef int64_t intx;
        typedef uint64_t inte;
        typedef long double fltx;
    
        template <Tname T> il void minimize(T &a, T b) { if (b < a) a = b; }
        template <Tname T> il void maximize(T &a, T b) { if (b > a) a = b; }
        template <Tname T> il T& ally_minimize(T& l, const T& r) { return l > r ? l = r : l; }
        template <Tname T> il T& ally_maximize(T& l, const T& r) { return l < r ? l = r : l; }
        template <Tname T> il void __swap_int(T &l, T &r){l ^= r; r ^= l; l ^= r;}
        il void swap(int& l, int &r) {__swap_int(l, r);}
        il void swap(intx& l, intx &r) {__swap_int(l, r);}
        template <Tname T> il void xReplace(T v, T &mx, T &sx) { if (v > mx) sx = mx, mx = v; else if (v > sx) sx = v; }
        template <Tname T> il void nReplace(T v, T &mn, T &sn) { if (v < mn) sn = mn, mn = v; else if (v < sn) sn = v; }
        
        template <Tname T, Tname R = int> il T smod(T x, R p = modn) { return x < 0 ? x + p : x; }
        template <Tname T, Tname R = int> il T amod(T x, R p = modn) { return x >= p ? x - p : x; }
        template <Tname T, Tname A, Tname R = int> il T submod(T &x, A v, R p = modn) { return x = smod(x - v, p); }
        template <Tname T, Tname A, Tname R = int> il T addmod(T &x, A v, R p = modn) { return x = amod(x + v, p); }
       
        template <Tname T> il T Max(T x, T y) { return x > y ? x : y; }
        template <Tname T> il T Min(T x, T y) { return x > y ? y : x; }
        
        const int bufsize = 1 << 23;
    
        char *const inBuf = new char[bufsize];
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
            static int *const st = new int[20];
            int top = 0;
            if (x < 0) putchar('-'), x = -x;
            while (x) st[top++] = x % 10, x /= 10;
            if (!top) st[top++] = 0;
            while (top) putchar('0' + st[--top]);
        }
    
    }
    
    inline namespace Dev_Ns_MathT {
        
        struct Primetown {
            static function<void(int)> default_f1;
            static function<void(int, int)> default_f2;
            vector<bool> mark;
            vector<int> prime;
            int pcnt; size_t size;
            Primetown(size_t _size) : mark(_size), prime(_size),
                pcnt(0), size(_size) {}
            void run(const function<void(int)> f1 = default_f1,
                const function<void(int, int)> f2 = default_f2) {
                re (i, 2, (int)size - 1) {
                    if (!mark[i]) prime[++pcnt] = i, f1(i);
                    r (j, pcnt) {
                        if (1ull * i * prime[j] >= size) break;
                        mark[i * prime[j]] = true, f2(i * prime[j], prime[j]);
                        if (!(i % prime[j])) break;
                    }
                }
            }
        };
        
        constexpr int log2(intx n) {
            return n == 1 ? 0 : log2(n >> 1) + 1;
        }
    }
    
    inline namespace Dev_Ns_Datastructures {
    
        inline namespace Ns_Bint {
        
            struct utype {
                typedef uint64_t _uextend_t;
                typedef uint64_t _udesc_t;
                typedef uint32_t _ubit_t;
            };
            template<Tname T1, Tname T2, bool _cond> struct bindtype { using type = T2; };
            template<Tname T1, Tname T2> struct bindtype<T1, T2, true> { using type = T1; };
            template <utype::_udesc_t D = 10, size_t nsize = 114514u>
            struct uint114514_t {
                typedef uint114514_t<D, nsize> _self_t;
                vector<utype::_ubit_t> bit; size_t len;
                uint114514_t() : len(0), bit(nsize) {}
                uint114514_t(const utype::_uextend_t a) : bit(nsize) {
                    if (!a) len = 0; else _copy(a); }
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
                template <utype::_udesc_t nD, size_t dsize>
                friend void dcast(const _self_t &a, uint114514_t<nD, dsize> &b) {
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
            
        }
        
        struct Ufset {
            vector<int> fa; size_t size;
            Ufset(size_t _size) : fa(_size), size(_size) {}
            void clear() { rre (i, 0, size - 1) fa[i] = i; }
            int top(int x) { return fa[x] == x ? x : fa[x] = top(fa[x]); }
            void merge(int x, int y) { fa[top(x)] = top(y); }
            bool check(int x, int y) { return top(x) == top(y); }
        };
        
        inline namespace Ns_Edgeset {
        
            enum _EEdgeset_Type {
                UNWEIGHTED = 0,
                WEIGHTED = 1,
                FLOW = 2,
                UNWEIGHTED_TREE = 3,
                WEIGHTED_TREE = 4,
            };
            
            template <int mode = UNWEIGHTED>
            struct Edgeset {
                vector<int> h, nxt, to;
                int newp;
                size_t maxp, maxe;
                Edgeset(const size_t _maxp, const size_t _maxe) : h(_maxp), 
                    nxt(_maxe), to(_maxe), newp(1), maxp(_maxp), maxe(_maxe) {}
                Edgeset(const size_t _maxp) : Edgeset(_maxp, _maxp * 2) {}
                void ae(int u, int v) { nxt[++newp] = h[u], to[newp] = v, h[u] = newp; }
                void ae2(int u, int v) { ae(u, v), ae(v, u); }
            };
            
            template <>
            struct Edgeset<WEIGHTED> : public Edgeset<UNWEIGHTED> {
                vector<intx> len;
                Edgeset<WEIGHTED>(const size_t _maxp, const size_t _maxe)
                    : Edgeset<UNWEIGHTED>(_maxp, _maxe), len(_maxe) {}
                Edgeset(const size_t _maxp) : Edgeset(_maxp, _maxp * 2) {}
                void ae(int u, int v, intx w) { Edgeset<UNWEIGHTED>::ae(u, v), len[this->newp] = w; }
                void ae2(int u, int v, intx w) { ae(u, v, w), ae(v, u, w); }
            };
            
            template <>
            struct Edgeset<FLOW> : public Edgeset<WEIGHTED> {
                vector<intx> flow;
                Edgeset<FLOW>(const size_t _maxp, const size_t _maxe)
                    : Edgeset<WEIGHTED>(_maxp, _maxe), flow(_maxe) {}
                Edgeset(const size_t _maxp) : Edgeset(_maxp, _maxp * 2) {}
                void ae(int u, int v, intx w, intx f) { Edgeset<WEIGHTED>::ae(u, v, w),
                    flow[this->newp] = f; }
                void ae2(int u, int v, intx w, intx f) { ae(u, v, w, f), ae(v, u, w, 0); }
            };
            
            template <>
            struct Edgeset<UNWEIGHTED_TREE> : public Edgeset<UNWEIGHTED> {
                vector<vector<int> > fa;
                Edgeset<UNWEIGHTED_TREE>(const size_t _maxp, const size_t _maxe)
                    : Edgeset<UNWEIGHTED>(_maxp, _maxe), fa(maxp, vector<int>(log2(_maxp) + 1)) {}
                Edgeset(const size_t _maxp) : Edgeset(_maxp, _maxp) {}
            };
            
            template <>
            struct Edgeset<WEIGHTED_TREE> : public Edgeset<WEIGHTED> {
                vector<vector<int> > fa;
                vector<vector<intx> > fw;
                Edgeset<WEIGHTED_TREE>(const size_t _maxp, const size_t _maxe)
                    : Edgeset<WEIGHTED>(_maxp, _maxe), fa(maxp, vector<int>(log2(_maxp) + 1)),
                        fw(maxp, vector<intx>(log2(_maxp) + 1)) {}
                Edgeset(const size_t _maxp) : Edgeset(_maxp, _maxp) {}
            };
            
            template <Tname _edgeset_t, typename T = decltype(declval<_edgeset_t>().len)>
            il intx elen(_edgeset_t && a, int b) {
                return a.len[b];
            }
            
            il intx elen(const Edgeset<UNWEIGHTED> &a, int b) {
                return (intx)(bool)a.to[b];
            }
            
            il intx elen(const Edgeset<UNWEIGHTED_TREE> &a, int b) {
                return (intx)(bool)a.to[b];
            }
            
            il istream& undirin(istream & in, Edgeset<UNWEIGHTED> & a) {
                int u, v; in >> u >> v;
                return a.ae2(u, v), in;
            }
            
            il istream& undirin(istream & in, Edgeset<WEIGHTED> & a) {
                int u, v; intx w; in >> u >> v >> w;
                return a.ae2(u, v, w), in;
            }
            
            il istream& dirin(istream & in, Edgeset<UNWEIGHTED> & a) {
                int u, v; in >> u >> v;
                return a.ae(u, v), in;
            }
            
            il istream& dirin(istream & in, Edgeset<WEIGHTED> & a) {
                int u, v; intx w; in >> u >> v >> w;
                return a.ae(u, v, w), in;
            }
            
        }
        
        inline namespace Ns_Linear_DT {
        
            struct Fwt {
                vector<intx> d; size_t size;
                Fwt(size_t _size) : d(_size), size(_size) {}
                void mark(int x, int v) { for (; x < (int)size; x += lwb(x)) d[x] += v; }
                intx pres(int x) { intx ret = 0; for (; x; x -= lwb(x)) ret += d[x]; return ret; }
            };
            
            template <Tname T>
            struct Segment_Traits;
            
            template <Tname T>
            struct Segmenttree {
                int initialL, initialR;
                vector<T> dat;
                Segmenttree(size_t usage) : initialL(1), initialR(usage), dat(usage * 4) {}
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
        
    }
    
    inline namespace Dev_Ns_Algo {
        
        const int _ls_maxcsize = 1 << 17;
        
        template <Tname Iter, Tname T = decay_t<decltype(*Iter{})>, Tname Func>
        il void linear_sort(const Iter _begin, const Iter _end, const Func _index) {
            static vector<int> cnt(_ls_maxcsize);
            vector<T> tmp(distance(_begin, _end));
            
            cnt.clear();
            for_each(_begin, _end, [&](T &a) { ++cnt[_index(a)]; });
            partial_sum(cnt.begin(), cnt.end(), cnt.begin());
            for_each(reverse_iterator<Iter>(_end), reverse_iterator<Iter>(_begin), [&](T &a) {
                tmp[--cnt[_index(a)]] = a;
            });
            
            size_t p = 0;
            for_each(_begin, _end, [&](T &a) { a = tmp[p++]; });
        }
        
        template <Tname _func_t, Tname... _ext_t>
        il auto fcat(_func_t && f, _func_t && g, _ext_t... oth) {
            return fcat([&](auto &&... args) {
                f(std::forward<decltype(args)>(args)...);
                g(std::forward<decltype(args)>(args)...);
            }, oth...);
        }
        
        template <Tname _func_t>
        il auto fcat(_func_t && f) {
            return std::forward<_func_t>(f);
        }
        
        template <Tname _func_t>
        il auto operator |(function<_func_t> && f, function<_func_t> && g) {
            return fcat(f, g);
        }
        
        inline namespace Ns_Dfs {
            
            struct defa {
                static void init() {}
                static bool cond(int) { return true; }
                static void pre(int) {}
                template <Tname _edgeset_t>
                static void prein(int, _edgeset_t&, int) {}
                template <Tname _edgeset_t>
                static void postin(int, _edgeset_t&, int) {}
                static void post(int) {}
            };
            
            template <Tname _edgeset_t>
            void _dfs(_edgeset_t &edg, int x, int lst,
                const function<bool(int)> cond,
                const function<void(int)> prefunc,
                const function<void(int, _edgeset_t&, int)> preinfunc,
                const function<void(int, _edgeset_t&, int)> postinfunc,
                const function<void(int)> postfunc) {
                
                if (!cond(x)) return;
                prefunc(x);
                rgr (i, x, edg) {
                    const int v = edg.to[i];
                    if (v == lst) continue;
                    preinfunc(x, edg, i);
                    _dfs(edg, v, x, cond, prefunc, preinfunc, postinfunc, postfunc);
                    postinfunc(x, edg, i);
                }
                postfunc(x);
            }
            
            template <Tname _edgeset_t>
            il void dfs(_edgeset_t &edg, int x,
                const function<void()> initfunc = defa::init,
                const function<bool(int)> cond = defa::cond,
                const function<void(int)> prefunc = defa::pre,
                const function<void(int, _edgeset_t&, int)> preinfunc = defa::prein<_edgeset_t>,
                const function<void(int, _edgeset_t&, int)> postinfunc = defa::postin<_edgeset_t>,
                const function<void(int)> postfunc = defa::post) {
                initfunc();
                _dfs(edg, x, -1, cond, prefunc, preinfunc, postinfunc, postfunc);
            }
            
            template <int* sz_p>
            struct sizer {
                static void pre(int u) { sz_p[u] = 1; }
                template <Tname _edgeset_t>
                static void postin(int u, _edgeset_t& edg, int id) {
                    sz_p[u] += sz_p[edg.to[id]];
                }
            };
            
            template <intx *dep_p>
            struct deeper {
                template <Tname _edgeset_t>
                static void prein(int u, _edgeset_t& edg, int id) {
                    dep_p[edg.to[id]] = dep_p[u] + elen(edg, id);
                }
            };
            
        }
        
        template <Tname set_t, Tname elem_t>
        il auto previous(const set_t &a, const elem_t &b) {
            auto ret = a.lower_bound(b);
            return ret == a.begin() ? a.end() : --ret;
        }
        
    }

#endif
const int maxn = 3e5 + 4;

int T, n;
map<intx, intx> rec;
intx P, M = 1, ans;

il void solve() {
    cin >> n;
    r (i, n) {
        intx v; cin >> v;
        if (M == 1) {
            while (!rec.empty() && rec.rbegin()->fst + P > v)
                rec.erase(rec.rbegin()->fst);
        } else {
            while (!rec.empty() && rec.begin()->fst * M + P > v)
                rec.erase(rec.begin());
        }
        M = -M, P = v - P, ++rec[(v - P) * M];
        ans += rec[(-P) * M];
        

    }
    cout << ans << endl;
    rec.clear();
    P = ans = 0, M = 1;
}

int main() {
    Optimio, cin >> T;
    r (i, T) solve();
    return 0;
}
