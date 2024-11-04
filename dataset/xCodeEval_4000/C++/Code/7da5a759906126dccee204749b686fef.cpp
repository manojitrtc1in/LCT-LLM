#define _SOLUTION                                       \
                                                        \
                                                        \
void solve() {                                          \
    $Ix(int, a, 5);                                     \
    $Ixn(string, s, k);                                 \
    $$ S = _yay(LIS5("S", "M", "L", "XL", "XXL"));      \
    xfor(s, t, {                                        \
        int sz = _firstidx(S, _ == t);                  \
        $$ have = _filter(a[_] > 0, _rng(5));           \
        tup2c(F, int, sz, int, dist, cmp_ad(dist, sz)); \
        $$ have2 = _map(have, F(_, abs(sz - _)));       \
        $$ res = _minc(have2).sz;                       \
        _w_(S[res]);                                    \
        a[res]--;                                       \
    });                                                 \
}                                                       \
                                                        \
_END_SOL                                                \
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
#include <limits>
#include <hash_map>
#include <hash_set>
#include <functional>
using namespace std;
#define gcc_typename typename
using namespace __gnu_cxx;
#define LL_SPEC "%I64d"
#define ITER_WRITE inline void _write() const { _wstr("["); write_iterable(*this, SepComma()); _wstr("]"); }
#define ITER_SIZE inline int size() const { return _count(*this); }
#define SEQ_TYPE(x) const x
#define FUNC2(x,y) x##y
#define FUNC1(x,y) FUNC2(x,y)
#define FUNC(x) FUNC1(x,__COUNTER__)
#define STRUCT_NAME FUNC(struct_)
struct _DummyType {};
template<typename T>
struct ValueType {
	typedef typename remove_reference<T>::type clean_type;
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
#define cmp_ad(a, b) cmp_a(a) || (this->a == other.a && this->b > other.b)
template<typename T>
struct strict_item_type { typedef typename T::value_type type; };
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
struct _null { inline static T value() { return T(-1); } };
template<typename IterableType>
struct citerator
{
	typedef typename IterableType::value_type value_type;
	static inline value_type resolve(const IterableType &a, typename IterableType::iterator it)
		{ return a.resolve_iterator(it); }
	static inline value_type& xresolve(IterableType &a, typename IterableType::iterator it)
		{ return a.resolve_iterator(it); }
};
template<typename T>
struct citerator<vector<T> >
{
	static inline const T& resolve(const vector<T> &a, typename vector<T>::const_iterator it)
		{ return *it; }
};
template<typename T> struct _IsIterable<vector<T> > { enum { value = 1 }; };
template<>
struct citerator<string>
{
	static inline char resolve(const string &a, gcc_typename string::const_iterator it)
		{ return *it; }
};
template<> struct _IsIterable<string> { enum { value = 1 }; };
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
    _seq_process_c(a, [&](const gcc_typename ValueType<decltype(a)>::type &v) -> bool {
#define xforeachi_(a, i, v) \
    { \
    typedef const gcc_typename ValueType<decltype(a)>::type &_T_; \
    int i = -1; \
    _seq_process_c(a, [&](_T_ v) -> bool { ++i; return [&]() -> bool {
#define x_endfe return true; });
#define x_endfei return true; }(); }); }
#define xforeach(a, v, ...)  xforeach_(a, v) __VA_ARGS__; x_endfe
#define xforeachi(a, i, v, ...) xforeachi_(a, i, v) __VA_ARGS__; x_endfei
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
	inline int size() const { return b < a ? 0 : b - a; }
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
struct _io<int&>
{
	inline static void read(int &x, int i) { scanf("%d", &x); }
	inline static void write(const int &x) { printf("%d", x); }
};
template<>
struct _io<const int&>
{	
	inline static void write(const int &x) { printf("%d", x); }
};
template<>
struct _io<long long>
{
	inline static void read(long long &x, int i) { scanf(LL_SPEC, &x); }
	inline static void write(const long long &x) { printf(LL_SPEC, x); }
};
template<>
struct _io<long long&>
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
struct _io<const double>
{	
	inline static void write(const double &x) { printf("%.9f", x); }
};
template<>
struct _io<double&>
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
template<>
struct _io<const string>
{    
    inline static void write(const string &s) { printf("%s", s.c_str()); }
};
template<size_t x>
struct _io<const char[x]>
{
	inline static void write(const char s[x]) { printf("%s", s); }
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
template<typename T> inline void _w(const T &a) { _io<T>::write(a); }
#define _w_(x) _w(x); _wlf
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
template<typename T>
struct iterable_wrap
{
	SEQ_TYPE(T) base;
    iterable_wrap(const T &base) : base(base) {}
    typedef T value_type;
    template<typename F>
    inline void process(F f) const { f(base); }
	inline int size() const { return 1; }
};
iterable_wrap<string> IWS(const string &s) { return iterable_wrap<string>(s); }
#define $I(type, name) \
	type name; \
	_io<type>::read(name, 0)
#define _inx(type, name, sz) \
	type *name; \
	name = new type[sz]; \
	for (int __i = 0; __i < sz; __i++) _io<type>::read(name[__i], __i);
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
		inline void _read(int i) { base::_read(i); _io<type>::read(field_name, i); }
#define _end_extend }
#define _CMP_(name, cmp) bool operator < (const name &other) const { return cmp; }
#define tup1(name, t1, name1) tup1c(name, t1, name1, false)
#define tup1c(name, t1, name1, cmp) \
	extend_fieldr(name, tup0, t1, name1) \
		name(t1 name1) : name1(name1) {} \
		_CMP_(name, cmp) \
	_end_extend
#define tup2c(name, t1, name1, t2, name2, cmp) tup2c_(STRUCT_NAME, name, t1, name1, t2, name2, cmp)
#define tup2c_(bname, name, t1, name1, t2, name2, cmp) \
	tup1(bname, t1, name1); \
	extend_fieldr(name, bname, t2, name2) \
		name(t1 name1, t2 name2) : bname(name1), name2(name2) {} \
		_CMP_(name, cmp) \
	_end_extend
#define seqvec(name, a) \
	const auto &name##_tmp = a; \
	vector<gcc_typename ValueType<decltype(name##_tmp)>::type> name; \
	populate(name, name##_tmp)
template<typename T, typename F>
int FindFirstI(const T &a, F f)
{
	int res = -1;
	xforeachi(a, i, v,
		if (f(v)) { res = i; xbreak; };
	)
	return res;
}
#define _firstidx(x, cond) \
	FindFirstI(x, [&](const item_type<typename _CleanType<decltype(x)>::type>::type &_) -> bool { return cond; })
template<typename T>
struct MinFtr
{
	typedef T res_type;
	inline T operator () (const T &a, const T &b) const { return min(a, b); }
};
template<typename T>
typename T::value_type _minc(const T &a)
{
    typedef typename T::value_type X;
	return _Collapse(MinFtr<X>(), a);
}
#define _rng(n) Range<int>(0, n)
#define $$ auto
template<typename T>
struct key_type { typedef int type; };
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
	inline int size() const { return n; }
	inline value_type& resolve_iterator(const iterator &it) const
	{
		return cmap<ArrType>::read(a, it);
	}
	inline value_type& operator [] (int i) { return a[i]; }
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
#define _wrap(name, base, n) \
	ArrWrapper<decltype(base)> name(base, n)
#define $Ix(type, name, n) \
	_inx(type, name##_base, n); \
	_wrap(name, name##_base, n)
#define $Ixn(type, name, n) $I(int, n); $Ix(type, name, n)
#ifdef _MSC_VER
#if _MSC_VER <= 1600
#define OLD_VS
#endif
#endif
#ifdef OLD_VS
template < typename T > T&& declval();
#endif
template<typename T, typename F, typename S>
struct MapWrapper
{
	SEQ_TYPE(T) a; 
	typedef S value_type;
	F f; 
	MapWrapper(const T &a, F f) : a(a), f(f) {}
	typedef typename T::iterator iterator;
	inline iterator begin() const { return a.begin(); }
	inline iterator end() const { return a.end(); }
	inline int size() const { return a.size(); }
	inline S resolve_iterator(const iterator &it) const 
	{ 
		return f(citerator<T>::resolve(a, it));
	}
    template<typename Ftr>
    inline void process(Ftr ftr) const
    {
        xforeach(a, x, 
            if (!ftr(f(x))) xbreak
        );
    }
	ITER_WRITE
};
template<typename A, typename B, typename C> struct _IsIterable<MapWrapper<A, B, C> > { enum { value = 1 }; };
#ifdef OLD_VS
#define zzz typename _CleanType<decltype(f(declval<typename T::value_type>()))>::type
#else
#define zzz typename result_of<F( typename ValueType<T>::type )>::type
#endif
template<typename T, typename F>
auto SimpleMapWrapper(const T &a, F f) -> MapWrapper<T, F, zzz>
{
	return MapWrapper<T, F, zzz>(a, f);
}
#undef zzz
#define _map(a, ...) SimpleMapWrapper(a, [&](const gcc_typename ValueType<decltype(a)>::type &_) \
	 { return __VA_ARGS__; })
template<
	typename T, 
	typename Filter  
>
struct FilterWrapper
{
	SEQ_TYPE(T) a;
	Filter filter;
	FilterWrapper(const T &a, Filter filter) : a(a), filter(filter) {}
	typedef typename T::value_type value_type;
	template<typename F>
	inline void process(F f) const
	{
		xforeach(a, x, 
			if (filter(x))
				if (!f(x)) xbreak
		)
	}
	ITER_SIZE
	ITER_WRITE
    typedef FilterWrapper<T, Filter> self_type;
    struct iterator
    {
        typedef typename T::iterator it_type;
        it_type it;
        const self_type &owner;
        iterator(const it_type &it, const self_type &owner) : it(it), owner(owner) {}
        void adjust() { while (it != owner.a.end() && !owner.filter(citerator<T>::resolve(owner.a, it))) ++it; }
		inline bool operator != (const iterator &other) const { return it != other.it; } 
		inline iterator& operator ++ () { ++it; adjust(); return *this; }
        value_type get_value() const { return citerator<T>::resolve(owner.a, it); }
    };
    iterator begin() const { iterator it(a.begin(), *this); it.adjust(); return it; }
    iterator end() const { return iterator(a.end(), *this); }
    value_type resolve_iterator(const iterator &it) const { return it.get_value(); }
};
template<typename A, typename B> struct _IsIterable<FilterWrapper<A, B> > { enum { value = 1 }; };
template<typename T, typename Filter>
inline FilterWrapper<T, Filter> CreateFilterWrapper(const T &t, Filter f)
{
	return FilterWrapper<T, Filter>(t, f);
}
#define _filter(cond, a) \
	CreateFilterWrapper(a, [&](const ValueType<decltype(a)>::type &_) -> bool { return cond; })
template<
	typename ListType, 
	typename SeqType 
>
void populate(ListType &lst, const SeqType &seq)
{
	xforeach(seq, x, lst.push_back(x));
}
template<typename T1, typename T2>
struct ConcatLists
{
    typedef typename T1::value_type value_type;
    SEQ_TYPE(T1) a;
    SEQ_TYPE(T2) b;
    ConcatLists(const T1 &a, const T2 &b) : a(a), b(b) {}
    template<typename F>
    inline void process(F f) const
    {
		bool stop = false;
		xforeach(a, i, if (!f(i)) { stop = true; xbreak; } )
        if (!stop) xforeach(b, i, if (!f(i)) xbreak )
    }
    inline int size() const { return a.size() + b.size(); }
	typedef _DummyType iterator; 
	ITER_WRITE
};
template<typename T>
struct __lcat
{
	const T &a;
	__lcat(const T &a) : a(a) {}
	template<typename T2> inline
		ConcatLists<T, T2> operator % (const T2 &b) const { return ConcatLists<T, T2>(a, b); }
};
struct _lcat {};
template<typename T> inline
	__lcat<T> operator % (const T &a, _lcat) { return __lcat<T>(a); }
#define lcat _lcat() %
template<typename T>
inline int _count(const T &a)
{
    int res = 0;
    xforeach(a, i, ++res);
    return res;
}
struct 
{
	template<typename F, typename T>
	struct Sig2 { typedef typename T::value_type ret_type; };
	template<typename F, typename T>
	inline typename T::value_type operator () (F f, const T &a) const
	{
		typedef typename T::value_type S;
		S res;
		bool first = true;
		xfor(a, x,
			if (first)
			{
				res = x;
				first = false;
			}
			else
			{
				res = f(x, res);
			}
		);
		return res;
	}
} _Collapse;
template<typename T>
struct TrivialEnsurer
{
	T operator () (const T &a) const { return a; }
};
template<typename T>
struct VectorEnsurer
{
	typedef typename T::value_type S;
	vector<S> operator () (const T &a) const { seqvec(v, a); return v; }
};
template<typename T>
struct _EnsuredIterable
{
	typedef typename conditional<_IsIterable<T>::value, T, vector<typename T::value_type> >::type type;
	typedef typename conditional<_IsIterable<T>::value, TrivialEnsurer<T>, VectorEnsurer<T> >::type ensurer;
};
template<typename T>
typename _EnsuredIterable<T>::type _ensure_iterable(const T &a)
{
	return typename _EnsuredIterable<T>::ensurer()(a);
}
#define _yay(x) _ensure_iterable(x)
#define LIS5(a1, a2, a3, a4, a5) (IWS(a1) %lcat IWS(a2) %lcat IWS(a3) %lcat IWS(a4) %lcat IWS(a5))
#ifndef ONLINE_JUDGE
#define _open_files(name) freopen(name ".in", "r", stdin); freopen(name ".out", "w", stdout)
#else
#define _open_files(name)
#endif
#define _END_SOL int main() { _open_files("test"); solve(); return 0; }
_SOLUTION
