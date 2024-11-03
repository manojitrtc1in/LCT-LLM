#define _SOLUTION                                                                                                \
                                                                                                                 \
                                                                                                                 \
template<typename T1, typename T2, typename T3, typename T4>                                                     \
void doit(const T1 &a, const T2 &b, const T3 &path, T4 &res, int pos, int vol, int diff)                         \
{                                                                                                                \
    if (pos + 1 >= xlen(path)) return;                                                                           \
    int tgt = path[pos + 1];                                                                                     \
    int before = min(diff, vol - a[tgt]);                                                                        \
    int src = path[pos];                                                                                         \
    if (before > 0) res.push_back(int_abc(src + 1, tgt + 1, before));                                            \
    doit(a, b, path, res, pos + 1, vol, diff);                                                                   \
    int after = diff - before;                                                                                   \
    if (after > 0) res.push_back(int_abc(src + 1, tgt + 1, after));                                              \
}                                                                                                                \
                                                                                                                 \
void solve() {                                                                                                   \
    $I3(int, n, vol, e);                                                                                         \
    $Ix(int, a, n);                                                                                              \
    $Ix(int, b, n);                                                                                              \
    $Ix(int_uv, ee, e);                                                                                          \
                                                                                                                 \
    graph_bi_elist(G, n, ee);                                                                                    \
                                                                                                                 \
    vector<int_uv> ee2;                                                                                          \
    graph_markers(int, G, markers);                                                                              \
    {                                                                                                            \
        CurGraph(G);                                                                                             \
        invoke_dfs(G, G.vertices(), V0, V0, V0, E_(ee2.push_back(int_uv(u+1, e.v+1))), E0, E0, markers);         \
    }                                                                                                            \
                                                                                                                 \
    graph_bi_elist(G2, n, ee2);                                                                                  \
                                                                                                                 \
    vector<int_abc> res;                                                                                         \
    _for(q, n) _for(i, n) if (a[i] != b[i]) {                                                                    \
        vector<int> path;                                                                                        \
        {                                                                                                        \
            CurGraph(G2);                                                                                        \
            if (!path_from(G2, i, [&](int v){ return (a[v] - b[v]) %mul% (a[i] - b[i]) < 0; }, path, markers)) { \
                _w("NO");                                                                                        \
                return;                                                                                          \
            }                                                                                                    \
        }                                                                                                        \
        if (a[path[0]] < b[path[0]]) _reverse(path);                                                             \
                                                                                                                 \
        int src = path[0], tgt = path.back();                                                                    \
        int diff = min(_abs(a[src] - b[src]), _abs(a[tgt] - b[tgt]));                                            \
        doit(a, b, path, res, 0, vol, diff);                                                                     \
        a[src] -= diff;                                                                                          \
        a[tgt] += diff;                                                                                          \
    }                                                                                                            \
    _w_(xlen(res));                                                                                              \
    xfor(res, x, _w3_(x.a, x.b, x.c));                                                                           \
}                                                                                                                \
                                                                                                                 \
_END_SOL                                                                                                         \
                                                                                                                 \








#pragma comment(linker, "/STACK:32000000")
#define _CRT_SECURE_NO_DEPRECATE
#include <sstream>
#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <stack>
#include <cstdio>
#include <cmath>
#include <stdarg.h>
#include <memory.h>
#include <string.h>
#include <assert.h>
#include <type_traits>
#include <climits>
#include <hash_map>
#include <hash_set>
#include <functional>
using namespace std;
#ifdef _MSC_VER
#define gcc_typename
using namespace stdext;
#define LL_SPEC "%I64d"
#else
#define gcc_typename typename
using namespace __gnu_cxx;
#define LL_SPEC "%I64d"
#endif
#define ITER_WRITE inline void _write() const { _wstr("["); write_iterable(*this, SepComma()); _wstr("]"); }
#define TRIVIAL_ADVANCE void advance_iterator(iterator &it) const { ++it; }
#define FUNC2(x,y) x##y
#define FUNC1(x,y) FUNC2(x,y)
#define FUNC(x) FUNC1(x,__COUNTER__)
#define STRUCT_NAME FUNC(struct_)
struct _DummyType {};
template<typename T>
struct ValueType {
    typedef typename remove_const<T>::type clean_type1;
	typedef typename remove_reference<clean_type1>::type clean_type;
	typedef typename clean_type::value_type type;
};
template<typename T>
struct _CleanType {
    typedef typename remove_const<T>::type _type;
    typedef typename remove_reference<_type>::type type;
};
template<typename T>
struct _IsIterable { enum { value = 0 }; };
#define _wsp printf(" ")
#define _wlf printf("\n")
#define _wstr(s) printf("%s", s)
#define cmp_a(a) this->a < other.a
#define cmp_aa(a, b) cmp_a(a) || (this->a == other.a && this->b < other.b)
#define cmp_aaa(a, b, c) cmp_aa(a, b) || (a == other.a && b == other.b && c < other.c)
template<typename T>
struct strict_item_type { typedef typename ValueType<T>::type type; };
template<typename T>
struct strict_item_type<T*> { typedef T type; };
template<typename T, size_t sz>
struct strict_item_type<T[sz]> { typedef T type; };
template<typename T, size_t sz>
struct strict_item_type<T(&)[sz]> { typedef T type; };
template<typename T>
struct strict_item_type<T*&> { typedef T type; };
template<typename T>
struct item_type { typedef typename T::value_type type; };
template<typename T>
struct item_type<T*> { typedef T type; };
template<typename T, size_t sz>
struct item_type<T[sz]> { typedef T type; };
template<typename T, size_t sz>
struct item_type<T(&)[sz]> { typedef T type; };
template<typename T>
struct item_type<T*&> { typedef T type; };
template<typename T>
struct item_type<T**> { typedef T type; };
template<typename T>
struct item_type<T**&> { typedef T type; };
template<typename T>
struct _null { static T value() { return T(); } };
template<>
struct _null<int> { static int value() { return -1; } };
template<typename T>
struct _seq
{
    template<typename F>
    static inline void process(T &t, F f) { t.process(f); }
};
template<typename T>
struct _seq<const T>
{
	template<typename F>
	static inline void process(const T &t, F f) { t.process(f); }
};
template<typename T>
struct _seq<vector<T> >
{
    template<typename F>
    static void process(vector<T> &t, F f)
    {
        for (typename vector<T>::iterator it = t.begin(); it != t.end(); ++it)
            if (!f(*it)) break;
    }
};
template<typename T>
struct _seq<const vector<T> >
{
    template<typename F>
    static void process(const vector<T> &t, F f)
    {
        for (typename vector<T>::const_iterator it = t.begin(); it != t.end(); ++it)
            if (!f(*it)) break;
    }
};
template<typename T>
struct _seq<set<T> >
{
    template<typename F>
    static void process(set<T> &t, F f)
    {
        for (typename set<T>::iterator it = t.begin(); it != t.end(); ++it)
            if (!f(*it)) break;
    }
};
template<typename T>
struct _seq<const set<T> >
{
    template<typename F>
    static void process(const set<T> &t, F f)
    {
        for (typename set<T>::const_iterator it = t.begin(); it != t.end(); ++it)
            if (!f(*it)) break;
    }
};
template<typename T1, typename T2>
struct _seq<const map<T1, T2> >
{
    template<typename F>
    static void process(const map<T1, T2> &t, F f)
    {
        for (typename map<T1, T2>::const_iterator it = t.begin(); it != t.end(); ++it)
            if (!f(*it)) break;
    }
};
template<>
struct _seq<string>
{
    template<typename F>
    static void process(string &s, F f)
    {
        for (size_t i = 0; i < s.length(); i++)
            if (!f(s[i])) break;
    }
};
template<>
struct _seq<const string>
{
    template<typename F>
    static void process(const string &s, F f)
    {
        for (size_t i = 0; i < s.length(); i++)
            if (!f(s[i])) break;
    }
};
template<typename T, typename F>
inline void _seq_process_c(const T &t, F f)
{
	_seq<const T>::template process<F>(t, f);
}
#define xbreak return false
#define xforeach_(a, v) \
	{ \
	const auto &__a__ = a; \
    _seq_process_c(__a__, [&](const gcc_typename ValueType<decltype(__a__)>::type &v) -> bool {
#define x_endfe return true; }); }
#define xforeach(a, v, ...)  xforeach_(a, v) __VA_ARGS__; x_endfe
#define xfor(a, v, ...) xforeach(a, v, __VA_ARGS__)
struct SepComma { inline static void Print() { _wstr(", "); } };
template<typename T>
struct Range
{
	typedef T iterator;
	typedef T value_type;
	Range(T a, T b) : a(a), b(b) {}
	inline iterator begin() const { return a; }
	inline iterator end() const { return b; }
	inline value_type resolve_iterator(const iterator &it) const { return it; }
	TRIVIAL_ADVANCE
	inline int size(int mx = numeric_limits<int>::max()) const { return b < a ? 0 : b - a; }
	value_type operator [] (int i) const { return a + i; }
    template<typename F>
    inline void process(F f) const
    {
        for (T i = a; i < b; ++i)
            if (!f(i)) break;
    }
	Range<T> isect(const Range<T> other)
	{
		return Range<T>(max(a, other.a), min(b, other.b));
	}
	const T a, b;
	ITER_WRITE
};
template<typename T> struct _IsIterable<Range<T> > { enum { value = 1 }; };
static char __strbuf[1000001];
template<typename T>
struct _io
{
	inline static void read(T &x, int i) { x._read(i); }
	inline static void write(const T &x) { x._write(); }
};
template<>
struct _io<int>
{
	inline static void read(int &x, int i) { scanf("%d", &x); }
	inline static void write(const int &x) { printf("%d", x); }
};
template<>
struct _io<long long>
{
	inline static void read(long long &x, int i) { scanf(LL_SPEC, &x); }
	inline static void write(const long long &x) { printf(LL_SPEC, x); }
};
template<>
struct _io<double>
{
	inline static void read(double &x, int i) { scanf("%lf", &x); }
	inline static void write(const double &x) { printf("%.9f", x); }
};
template<>
struct _io<char>
{
	inline static void read(char &c, int i) { char buf[3]; scanf("%s", buf); c = buf[0]; }
	inline static void write(const char &c) { printf("%c", c); }
};
template<>
struct _io<bool>
{
	inline static void read(bool &b, int i) { int t; scanf("%d", &t); b = t != 0; }
	inline static void write(const bool &b) { printf("%s", b ? "#t" : "#f"); }
};
template<>
struct _io<string>
{
    inline static void read(string &s, int i) { scanf("%s", __strbuf); s = string(__strbuf); }
    inline static void write(const string &s) { printf("%s", s.c_str()); }
};
template<size_t x>
struct _io<char[x]>
{
	inline static void write(const char s[x]) { printf("%s", s); }
};
template<>
struct _io<const char*>
{
    inline static void write(const char *s) { printf("%s", s); }
};
template<typename T> inline void _w(const T &a) { _io<typename _CleanType<T>::type>::write(a); }
#define _w_(x) { _w(x); _wlf; }
#define _w2(a, b) { _w(a); _wsp; _w(b); }
#define _w3(a, b, c) { _w2(a, b); _wsp; _w(c); }
#define _w3_(a, b, c) { _w3(a, b, c); _wlf; }
template<typename T>
struct Idx2
{
    T i, j;
    Idx2(T i, T j) : i(i), j(j) {}
    Idx2() : i(-1), j(-1) {}
    inline void _write() const { _wstr("("); _io<T>::write(i); _wstr(", "); _io<T>::write(j); _wstr(")"); }
    inline void _read(int idx) { _io<T>::read(i, idx); _io<T>::read(j, idx); }
	inline bool operator == (const Idx2<T> &other) const { return i == other.i && j == other.j; }
	inline bool operator < (const Idx2<T> &other) const { return cmp_aa(i, j); }
};
template<typename T>
struct _null<Idx2<T> > { inline static Idx2<T> value() { return Idx2<T>(-1, -1); } };
template<typename T>
struct cmap
{
	typedef int key_type;
	typedef typename strict_item_type<T>::type Y;
	inline static Y& read(T &a, int i) { return a[i]; }
};
template<typename Y> 
struct cmap<Y**>
{
	typedef Idx2<int> key_type;
	inline static void write(Y **a, key_type i, const Y &value) { a[i.i][i.j] = value; }
	inline static Y& read(Y **a, key_type i) { return a[i.i][i.j]; }
};
template<typename Y> 
struct cmap<Y**&>
{
	typedef Idx2<int> key_type;
	inline static void write(Y **&a, key_type i, const Y &value) { a[i.i][i.j] = value; }
	inline static Y& read(Y **&a, key_type i) { return a[i.i][i.j]; }
};
template<typename Y, int sz> 
struct cmap<Y [sz]>
{
	typedef int key_type;
	inline static void write(Y a[sz], int i, const Y &value) { a[i] = value; }
	inline static Y& read(Y a[sz], int i) { return a[i]; }
};
template<typename Y, int sz> 
struct cmap<Y (&)[sz]>
{
	typedef int key_type;
	inline static void write(Y (&a)[sz], int i, const Y &value) { a[i] = value; }
	inline static Y& read(Y (&a)[sz], int i) { return a[i]; }
};
template<typename Y> 
struct cmap<Y*>
{
	typedef int key_type;
	inline static void write(Y *a, int i, const Y &value) { a[i] = value; }
	inline static Y& read(Y *a, int i) { return a[i]; }
};
template<typename Y> 
struct cmap<Y*&>
{
	typedef int key_type;
	inline static void write(Y *&a, int i, const Y &value) { a[i] = value; }
	inline static Y& read(Y *&a, int i) { return a[i]; }
};
#define $I(type, name) \
	type name; \
	_io<type>::read(name, 0)
#define $I2(type, name1, name2) $I(type, name1); $I(type, name2)
#define $I3(type, name1, name2, name3) $I2(type, name1, name2); $I(type, name3)
#define _inx(type, name, sz) \
	type *name; \
	name = new type[sz]; \
	for (int __i = 0; __i < sz; __i++) _io<type>::read(name[__i], __i);
template<typename I, typename M>
inline void _fillit(const I &keys, M &m, const typename item_type<M>::type &val)
{
	xforeach(keys, i, cmap<M>::write(m, i, val));
}
template<typename T, typename sep>
void write_array(const T &a, int n)
{
	typedef typename item_type<T>::type X;
	for (int i = 0; i + 1 < n; i++)
	{
		_io<X>::write(a[i]);
		sep::Print();
	}
	if (n > 0) _io<X>::write(a[n-1]);
}
template<typename T, typename Sep>
void write_iterable(const T &a, Sep sep)
{
	bool first = true;
    typedef typename T::value_type i_type;
	xforeach(a, i,
		if (!first) sep.Print();
		_io<i_type>::write(i);
		first = false;
	)
}
template<typename T>
struct _io<vector<T> >
{
	inline static void read(vector<T> &x, int idx)
    {
        int sz;
        _io<int>::read(sz, 0);
        assert(sz >= 0);
        x.resize(sz);
        for (int i = 0; i < sz; i++) _io<T>::read(x[i], i);
    }
	inline static void write(const vector<T> &x) { _wstr("["); write_array<vector<T>, SepComma>(x, x.size()); _wstr("]"); }
};
template<typename T1, typename T2>
struct _io<map<T1, T2> >
{
    inline static void write(const map<T1, T2> &x) { _wstr("{"); write_iterable(x, SepComma()); _wstr("}"); }
};
template<typename T1, typename T2>
struct _io<pair<T1, T2> >
{
    inline static void write(const pair<T1, T2> &x) { _w("("); _w(x.first); _w(", "); _w(x.second); _w(")"); }
};
struct tup0 {
	inline void _read(int i) {}
	inline void __write() const { _wstr("("); }
	inline void _write() const { __write(); _wstr(")"); }
	template<typename T> inline bool operator == (const T &other) const { return true; }
};
template<typename T>
struct _is_empty { enum { value = 0 }; };
template<>
struct _is_empty<tup0> { enum { value = 1 }; };
#define extend_fieldr(name, base, type, field_name) \
	struct name : public base \
	{ \
		type field_name; \
		typedef type field_name##_type; \
		name() {} \
		inline void __write() const { base::__write(); if (!_is_empty<base>::value) _wsp; \
			_wstr(#field_name ":"); _io<type>::write(field_name); } \
		inline void _write() const { __write(); _wstr(")"); } \
		inline void _read(int i) { base::_read(i); _io<type>::read(field_name, i); } \
		inline bool operator == (const name &other) const { \
			return base::operator == (*(const base*)&other) && field_name == other.field_name; \
		}
#define _end_extend }
#define _CMP_(name, cmp) bool operator < (const name &other) const { return cmp; }
#define tup1(name, t1, name1) tup1c(name, t1, name1, false)
#define tup1c(name, t1, name1, cmp) \
	extend_fieldr(name, tup0, t1, name1) \
		name(t1 name1) : name1(name1) {} \
		_CMP_(name, cmp) \
	_end_extend
#define tup2(name, t1, name1, t2, name2) tup2c(name, t1, name1, t2, name2, false)
#define tup2c(name, t1, name1, t2, name2, cmp) tup2c_(STRUCT_NAME, name, t1, name1, t2, name2, cmp)
#define tup2c_(bname, name, t1, name1, t2, name2, cmp) \
	tup1(bname, t1, name1); \
	extend_fieldr(name, bname, t2, name2) \
		name(t1 name1, t2 name2) : bname(name1), name2(name2) {} \
		_CMP_(name, cmp) \
	_end_extend
#define tup3c(name, t1, name1, t2, name2, t3, name3, cmp) tup3_(STRUCT_NAME, name, t1, name1, t2, name2, t3, name3, cmp)
#define tup3_(bname, name, t1, name1, t2, name2, t3, name3, cmp) \
	tup2(bname, t1, name1, t2, name2); \
	extend_fieldr(name, bname, t3, name3) \
		name(t1 name1, t2 name2, t3 name3) : bname(name1, name2), name3(name3) {} \
		_CMP_(name, cmp) \
	_end_extend
#define _reverse(a) if (a.size() > 0) reverse(&a[0], &a[0] + a.size())
#define _for(i, n) for (int i = 0; i < n; i++)
#define _rng(n) Range<int>(0, n)
template<typename T>
struct _keys
{
};
template<typename T>
struct xlen_
{
	static int size(const T &a, int mx) { return a.size(mx); }
};
template<>
struct xlen_<string>
{
	static int size(const string &s, int mx) { return (int)s.size(); }
};
template<typename T>
struct xlen_<vector<T> >
{
	static int size(const vector<T> &v, int mx) { return (int)v.size(); }
};
template<typename T>
struct xlen_<set<T> >
{
    static int size(const set<T> &s, int mx) { return (int)s.size(); }
};
template<typename T, typename S>
struct xlen_<map<T, S> >
{
    static int size(const map<S, T> &m, int mx) { return (int)m.size(); }
};
template<typename T>
int xlen(const T &a, int mx = numeric_limits<int>::max()) { return xlen_<T>::size(a, mx); }
template<typename T1, typename T2>
struct MapKeys
{
	const map<T1, T2> &m;
	typedef T1 value_type;
	typedef _DummyType iterator;
	MapKeys(const map<T1, T2> &m) : m(m) {}
	template<typename F>
	void process(F f) const { xfor(m, x, if (!f(x.first)) xbreak); }
	int size(int mx = 0) const { return (int)m.size(); }
	ITER_WRITE
};
template<typename T1, typename T2>
struct ANMap
{
	map<T1, T2> m;
	typedef T2 value_type;
	T2& operator [] (const T1 &idx) { return m[idx]; }
	void _write() const { _w(m); }
};
template<typename T1, typename T2>
struct _keys<ANMap<T1, T2> >
{
    typedef MapKeys<T1, T2> type;
    static type get(const ANMap<T1, T2> &t) { return type(t.m); }
};
template<typename T1, typename T2>
struct cmap<ANMap<T1, T2> >
{
	inline static void write(ANMap<T1, T2> &a, const T1 &i, 
		const T2 value) { a[i] = value; }
	inline static T2& read(ANMap<T1, T2> &a, const T1 &i) { return a[i]; }
};
template<typename ArrType>
struct ArrWrapper
{
	typedef ArrType base_type;
	ArrType &a;
	int n;
	ArrWrapper(ArrType &a, int n) : a(a), n(n) {}
	typedef typename item_type<ArrType>::type value_type;
	typedef int iterator;
	inline iterator begin() const { return 0; }
	inline iterator end() const { return n; }
	TRIVIAL_ADVANCE
	inline int size(int mx = numeric_limits<int>::max()) const { return n; }
	inline value_type& resolve_iterator(const iterator &it) const
	{
		return cmap<ArrType>::read(a, it);
	}
	inline value_type& operator [] (int i) { return a[i]; }
	inline const value_type& operator [] (int i) const { return a[i]; }
	void erase(int p)
	{
		assert(p < n);
		for (int i = p + 1; i < n; ++i) a[i-1] = a[i];
		--n;
	}
    template<typename F>
    void process(F f) const
    {
        for (int i = 0; i < n; i++)
            if (!f(a[i])) break;
    }
	ITER_WRITE
};
template<typename T> struct _IsIterable<ArrWrapper<T> > { enum { value = 1 }; };
template<typename T>
struct cmap<ArrWrapper<T> >
{
	typedef typename ArrWrapper<T>::value_type V;
	inline static void write(ArrWrapper<T> &a, int i, 
		const V value) { a.a[i] = value; }
	inline static V& read(ArrWrapper<T> &a, int i) { return a.a[i]; }
};
template<typename T>
struct _keys<ArrWrapper<T> >
{
    typedef Range<int> type;
    static type get(ArrWrapper<T> &t) { return type(0, t.n); }
};
#define _wrap(name, base, n) \
	ArrWrapper<decltype(base)> name(base, n)
#define $Ix(type, name, n) \
	_inx(type, name##_base, n); \
	_wrap(name, name##_base, n)
template<
	typename GraphType,
	typename VertOrderType,
	typename NewTreeFunctor,
	typename EnterVertexFunctor,
	typename LeaveVertexFunctor,
	typename BeforeTraverseFunctor,
	typename AfterTraverseFunctor,
	typename BackEdgeFunctor,
	typename MarkersType
>
struct Dfs
{
	GraphType &g;
	const VertOrderType &order;
	NewTreeFunctor new_tree;
	EnterVertexFunctor enter_vertex;
	LeaveVertexFunctor leave_vertex;
	BeforeTraverseFunctor before_traverse;
	AfterTraverseFunctor after_traverse;
	BackEdgeFunctor back_edge;
	MarkersType &markers;
	typedef typename GraphType::v_type V;
	Dfs(
		GraphType &g, 
		const VertOrderType &order, 
		NewTreeFunctor new_tree, 
		EnterVertexFunctor enter_vertex, 
		LeaveVertexFunctor leave_vertex, 
		BeforeTraverseFunctor before_traverse, 
		AfterTraverseFunctor after_traverse, 
		BackEdgeFunctor back_edge, 
		MarkersType &markers 
	) : g(g), order(order), new_tree(new_tree), enter_vertex(enter_vertex), leave_vertex(leave_vertex),
		before_traverse(before_traverse), after_traverse(after_traverse), back_edge(back_edge),
		markers(markers) {}
	void Do()
	{
		xforeach_(order, i)
		{
			if (cmap<MarkersType>::read(markers, i) == 0)
			{
				new_tree(i);
				this->DfsRec(i, _null<V>::value());
			}
		} x_endfe
	}
	void DfsRec(V v, V parent)
	{			
		cmap<MarkersType>::write(markers, v, 1); 
		enter_vertex(v);
		xforeach_(g.v_edges(v), e)
		{						
			if (cmap<MarkersType>::read(markers, e.v) == 0)
			{
				if (before_traverse(v, e))
				{
					this->DfsRec(e.v, v);
					after_traverse(v, e);
				}
			}
			else
			{
				if (!(parent == e.v))
					back_edge(v, e);
			}
		} x_endfe
		leave_vertex(v);
	}
};
template<
	typename GraphType,
	typename VertOrderType,
	typename NewTreeFunctor,
	typename EnterVertexFunctor,
	typename LeaveVertexFunctor,
	typename BeforeTraverseFunctor,
	typename AfterTraverseFunctor,
	typename BackEdgeFunctor,
	typename MarkersType
>
inline void invoke_dfs(
	GraphType &g,
	const VertOrderType &order, 
	NewTreeFunctor new_tree,
	EnterVertexFunctor enter_vertex, 
	LeaveVertexFunctor leave_vertex, 
	BeforeTraverseFunctor before_traverse,
	AfterTraverseFunctor after_traverse,
	BackEdgeFunctor back_edge,
	MarkersType &markers
	)
{
	_fillit(g.vertices(), markers, 0);
	Dfs<GraphType, VertOrderType, NewTreeFunctor, EnterVertexFunctor, 
		LeaveVertexFunctor, BeforeTraverseFunctor, AfterTraverseFunctor, 
		BackEdgeFunctor, MarkersType>
		X(g, order, new_tree, enter_vertex, leave_vertex, before_traverse, after_traverse, back_edge, markers);
	X.Do();
}
template<typename VType>
struct EmptyFtr
{
	typedef VType v_type;
	inline void operator () (const VType &v) {}
};
template<typename G>
EmptyFtr<typename G::v_type> _V0(G &g) { return EmptyFtr<typename G::v_type>(); }
template<typename VType, typename EType>
struct EmptyFtrVE
{
	typedef VType v_type;
	typedef EType e_type;
	inline bool operator () (const VType &v, const EType &e) { return true; }
};
template<typename G>
EmptyFtrVE<typename G::v_type, typename G::e_type> _E0(G &g) { return EmptyFtrVE<typename G::v_type, typename G::e_type>(); }
#define V0 _V0(g)
#define E0 _E0(g)
#define _E_(G, ...) [&](const gcc_typename G::v_type &u, const gcc_typename G::e_type e) -> bool { __VA_ARGS__; return true; }
#define E_(...) _E_(GraphType, __VA_ARGS__)
#define CurGraph(graph) auto &__tmp__ = graph; auto &g = __tmp__; typedef gcc_typename _CleanType<decltype(g)>::type GraphType
template<typename T>
struct Range2
{
    T a, b, c, d;
    Range2(const T &a, const T &b, const T &c, const T &d) : a(a), b(b), c(c), d(d) {}
    typedef Idx2<T> value_type;
    template<typename F>
    void process(F f) const
    {
        for (T i = a; i < b; i++)
            for (T j = c; j < d; j++)
                if (!f(Idx2<T>(i, j)))
                    return;
    }
    inline int size(int mx = numeric_limits<int>::max()) const { return (b - a) * (d - c); }
};
template<typename T, typename X>
struct _mapcreator
{
	typedef ANMap<typename T::value_type, X> map_type;
    static map_type create(const T &t) { return map_type(); }
};
template<typename Ordinal, typename X>
struct _mapcreator<Range2<Ordinal>, X>
{
    typedef X **map_type;
    static map_type create(const Range2<Ordinal> &t)
    {
        assert(t.a == 0 && t.c == 0);
        map_type res = new X* [t.b];
        for (int i = 0; i < t.b; i++) res[i] = new X[t.d];
        return res;
    }
};
template<typename Ordinal, typename X>
struct _mapcreator<Range<Ordinal>, X>
{
	typedef ArrWrapper<X*> map_type;
    static map_type create(const Range<Ordinal> &t)
    {
        assert(t.a == 0);
		X *&res = *(new X*);
		res = new X[t.b];
		return map_type(res, t.b);
    }
};
#define graph_markers(T, g, name) graph_markers_(STRUCT_NAME, T, g, name)
#define graph_markers_(gtype, T, g, name) \
    typedef gcc_typename _CleanType<decltype(g)>::type gtype;  \
    auto name = _mapcreator<gcc_typename gtype::v_set_type, T>::create(g.vertices())
template<typename T>
T _abs(const T &x) { return x < 0 ? -x : x; }
template<typename T>
struct mul_op
{
	typedef T type;
	inline static type Do(const T &a, const T &b) { return a * b; }
};
template<>
struct mul_op<int>
{
	typedef long long type;
	inline static type Do(int a, int b) { return (long long)a * b; }
};
struct Mul {} mul;
template<typename T> struct _mul
{
	T a;
	_mul(T a) : a(a) {}
	inline typename mul_op<T>::type operator % (const T &b) { return mul_op<T>::Do(a, b); }
};
template<typename T> inline _mul<T> operator % (const T &a, Mul) { return _mul<T>(a); }
template<typename VerticesSetType, typename AdjListsType>
struct AdjListsGraph
{
	VerticesSetType &verts; 
	AdjListsType &lists; 
	AdjListsGraph(VerticesSetType &verts, AdjListsType &lists) : verts(verts), lists(lists) {}
	typedef typename item_type<AdjListsType>::type edge_list_type;
	typedef typename edge_list_type::value_type e_type;
	typedef typename VerticesSetType::value_type v_type;
	typedef VerticesSetType v_set_type;
	inline const typename item_type<AdjListsType>::type& v_edges(v_type v) const
		{ return lists[v]; }
	inline const v_set_type& vertices() const
		{ return verts; }
	void _write() const { _w("<<AdjListsGraph with "); _w(xlen(verts)); _w(" vertices>>"); }
};
tup2(int_uv, int, u, int, v);
tup3c(int_abc, int, a, int, b, int, c, cmp_aaa(a, b, c));
#define BiBuildAdjLists_macro(name, eu_expr, ev_expr) \
template<\
	typename SrcType,\
	typename DstType\
>\
void name(\
	const SrcType &src, \
	DstType &dst \
	)\
{\
	typedef gcc_typename item_type<DstType>::type::value_type dst_type;\
	xfor(src, e,\
		dst[eu_expr].push_back(dst_type(ev_expr)); \
		dst[ev_expr].push_back(dst_type(eu_expr)); \
	); \
}
BiBuildAdjLists_macro  (BiBuildAdjLists_m1,   e.u - 1, e.v - 1)
#define adj_lists_bi(n, e_raw, e_out) _adj_lists_generic(BiBuildAdjLists_m1,   _rng(n), e_raw, e_out)
#define _adj_lists_generic(list_builder, n, e_raw, e_out) \
	\
	_adj_lists_generic__(STRUCT_NAME, STRUCT_NAME, list_builder, n, e_raw, e_out)
#define _adj_lists_generic__(s_name, v_name, list_builder, n, e_raw, e_out) \
	\
	typedef item_type<decltype(e_raw)>::type::v_type v_name; \
	tup1(s_name, v_name, v); \
	\
	auto e_out = _mapcreator<decltype(n), vector<s_name> >::create(n); \
	\
	list_builder(e_raw, e_out)
#define graph_al(name, lists) \
	auto name##_verts = _keys<decltype(lists)>::get(lists); \
	AdjListsGraph<decltype(name##_verts), decltype(lists)> name(name##_verts, lists)
#define graph_bi_elist(name, n, edges) \
	adj_lists_bi(n, edges, name##_adjlists); \
	graph_al(name, name##_adjlists);
template<typename G, typename MarkersType, typename F, typename ListType>
struct PathFinder
{
	typedef typename G::v_type v_type;
	const G &g; 
	F f; 
	ListType &path; 
	MarkersType &markers; 
	v_type v0;
	PathFinder(const G &g, v_type v0, F f, ListType &path, MarkersType &markers)
		: g(g), v0(v0), f(f), path(path), markers(markers) {}
	bool dfs(v_type v)
	{
		if (f(v)) {
			path.push_back(v);
			return true;
		}
		markers[v] = 1;
		bool res = false;
		xfor(g.v_edges(v), e, {
			if (!markers[e.v] && this->dfs(e.v))
			{
				path.push_back(v);
				res = true;
				xbreak;
			}
		})
		return res;
	}
	bool Do()
	{
		_fillit(g.vertices(), markers, 0); 
		return dfs(v0);
	}	
};
template<typename G, typename MarkersType, typename F, typename ListType>
bool path_from(const G &g, typename G::v_type v0, F f, ListType &path, MarkersType &markers) {
	PathFinder<G, MarkersType, F, ListType> x(g, v0, f, path, markers);
	return x.Do();
}
#ifdef LOCAL_TEST
#define _open_files(name) freopen(name ".in", "r", stdin); freopen(name ".out", "w", stdout)
#else
#define _open_files(name)
#endif
#define _END_SOL int main() { _open_files("test"); solve(); return 0; }
_SOLUTION
