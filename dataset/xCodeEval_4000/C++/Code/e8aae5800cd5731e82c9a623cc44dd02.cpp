#define _SOLUTION                                                 \
                                                                  \
                                                                  \
void solve()                                                      \
{                                                                 \
    $Ixn(int, a, n);                                              \
    _rsort(a);                                                    \
    $$ res = _sum(_map(_zip(a, _seq_1_m1), PI * sqr(_.f) * _.s)); \
    _w(res);                                                      \
}                                                                 \
                                                                  \
_END_SOL                                                          \








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
#define SEQ_TYPE(x) const x
#define FUNC2(x,y) x##y
#define FUNC1(x,y) FUNC2(x,y)
#define FUNC(x) FUNC1(x,__COUNTER__)
#define STRUCT_NAME FUNC(struct_)
#define __block(...) do { __VA_ARGS__ } while (0)
const double PI = 3.1415926535897932384626433832795;
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
#define _wsp printf(" ")
#define _wstr(s) printf("%s", s)
#define cmp_a(a) this->a < other.a
#define cmp_aa(a, b) cmp_a(a) || (this->a == other.a && this->b < other.b)
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
template<>
struct citerator<string>
{
	static inline char resolve(const string &a, gcc_typename string::const_iterator it)
		{ return *it; }
};
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
#define x_endfe return true; });
#define xforeach(a, v, ...)  xforeach_(a, v) __VA_ARGS__; x_endfe
struct SepComma { inline static void Print() { _wstr(", "); } };
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
template<typename T> inline void _w(const T &a) { _io<T>::write(a); }
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
template<typename T>
inline iterable_wrap<T> IW(const T &x) { return iterable_wrap<T>(x); }
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
#define _sort(a) if (a.size() > 0) sort(&a[0], &a[0] + a.size())
#define _reverse(a) if (a.size() > 0) reverse(&a[0], &a[0] + a.size())
#define _rsort(a) __block( _sort(a); _reverse(a); )
template<typename T, typename F> 
typename T::value_type Fold(const T &a, F f, const typename T::value_type &init_val)
{
	typename T::value_type res = init_val;
	xforeach(a, i, res = f(res, i));
	return res;
}
template<typename T>
struct SumFtr
{
	typedef T res_type;
	inline T operator () (const T &a, const T &b) const { return a + b; }
};
template<typename T>
struct _sum_neutral
{
	static T value() { return T(0); }
};
template<typename T>
typename T::value_type _sum(const T &a)
{
	typedef typename T::value_type X;
	return Fold(a, SumFtr<X>(), _sum_neutral<X>::value());
}
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
template<typename T1, typename T2>
struct _pair
{
    tup2c(type, T1, f, T2, s, cmp_aa(f, s));
};
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
#define _map(a, ...) SimpleMapWrapper(a, [&](const ValueType<decltype(a)>::type &_) \
	 { return __VA_ARGS__; })
struct
{
	template<typename T, typename F> struct Sig2
	{
		typedef typename ValueType<T>::type elem_type;
		typedef typename F::template Sig<elem_type> f_sig;
		typedef MapWrapper<T, F, typename f_sig::ret_type> ret_type;
	};
	template<typename T, typename F>
	inline typename Sig2<T, F>::ret_type operator() (const T &a, const F &f) const
	{
		return typename Sig2<T, F>::ret_type(a, f);
	}
} _Map;
template<
	typename T 
>
struct CatWrapper
{
	typedef typename ValueType<typename T::value_type>::type value_type;
	typedef _DummyType iterator;
	SEQ_TYPE(T) a;
    CatWrapper(const T &a) : a(a) {}
	template<typename F>
	void process(F f) const
	{
		bool stop = false;
		xforeach(a, x,
			xforeach(x, y, 
				if (!f(y))
				{
					stop = true;
					xbreak;
				}
			);
			if (stop) xbreak;
		)
	}
	inline int size() const { return _count(*this); }
	ITER_WRITE
};
struct
{
	template<typename A>
	struct Sig { typedef CatWrapper<A> ret_type; };
	template<typename A>
	inline CatWrapper<A> operator() (const A &a) const { return CatWrapper<A>(a); }
} _Cat;
template<typename T1, typename T2>
struct ZipWrapper
{
    typedef typename _pair<typename T1::value_type, typename T2::value_type>::type value_type;
    typedef _DummyType iterator;
    SEQ_TYPE(T1) a;
    SEQ_TYPE(T2) b;
    ZipWrapper(const T1 &a, const T2 &b) : a(a), b(b) {}
    template<typename F>
    void process(F f) const
    {
        auto it = a.begin();
        typedef value_type f_type; 
        xforeach(b, x,
            if (it == a.end()) xbreak;
            if (!f(f_type(citerator<T1>::resolve(a, it), x))) xbreak;
            ++it;
        );
    }
    inline int size() const { return _count(*this); }
	ITER_WRITE
};
template<typename T1, typename T2>
ZipWrapper<T1, T2> _zip(const T1 &a, const T2 &b) 
{
    return ZipWrapper<T1, T2>(a, b);
}
struct NaturalSequence
{
	typedef int value_type;
    typedef _DummyType iterator; 
	template<typename F>    
	void process(F f) const
	{
		for (int i = 0; ; i++) if (!f(i)) break;
	}
    inline int size() const { return numeric_limits<int>::max(); }
	ITER_WRITE
};
#define _nat NaturalSequence()
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
template<typename T>
struct mul_op
{
	typedef double type;
	inline static type Do(const T &a, const T &b) { return double(a) * double(b); }
};
template<>
struct mul_op<int>
{
	typedef long long type;
	inline static type Do(int a, int b) { return (long long)a * b; }
};
template<typename T>
inline typename mul_op<T>::type sqr(const T &a)
{
    return mul_op<T>::Do(a, a);
}
template<typename T>
struct ExtVal_
{
	T val;
	ExtVal_(const T &val) : val(val) {}
	template<typename A>
	struct Sig { typedef T ret_type; };
	template<typename A1, typename A2>
	struct Sig2 { typedef T ret_type; };
	template<typename A> inline
		T operator() (const A&) const { return val; }
	template<typename A1, typename A2> inline
		T operator() (const A1&, const A2&) const { return val; }
};
struct
{
	template<typename T>
	struct Sig { typedef ExtVal_<T> ret_type; };
	template<typename T>
	inline ExtVal_<T> operator() (const T &val) const { return ExtVal_<T>(val); }
} ExtVal;
struct Arg1
{
	template<typename A>
	struct Sig { typedef A ret_type; };
	template<typename A1, typename A2>
	struct Sig2 { typedef A1 ret_type; };
	template<typename A>
	inline A operator() (const A &arg) const { return arg; }
	template<typename A1, typename A2>
	inline A1 operator() (const A1 &arg1, const A2 &arg2) const { return arg1; }
};
template<typename F, typename A>
struct RetType
{
	typedef typename F::template Sig<A> sig_type;
	typedef typename sig_type::ret_type type;
};
template<typename F, typename A1, typename A2>
struct RetType2
{
	typedef typename F::template Sig2<A1, A2> sig_type;
	typedef typename sig_type::ret_type type;
};
template<typename F, typename T1, typename T2>
struct Invoke2_
{
	const T1 t1;
	const T2 t2;
	const F f;
	Invoke2_(F f, const T1 &t1, const T2 &t2) : f(f), t1(t1), t2(t2) {}
	template<typename A>
	struct Sig
	{
		typedef typename RetType2<F, typename RetType<T1, A>::type, typename RetType<T2, A>::type>::type ret_type;
	};
	template<typename A1, typename A2>
	struct Sig2
	{
		typedef typename RetType2<F, typename RetType2<T1, A1, A2>::type, typename RetType2<T2, A1, A2>::type>::type ret_type;
	};
	template<typename A>
	inline typename Sig<A>::ret_type operator() (const A &arg) const { return f(t1(arg), t2(arg)); }
	template<typename A1, typename A2>
	inline typename Sig2<A1, A2>::ret_type operator() (const A1 &arg1, const A2 &arg2) const { 
		return f(t1(arg1, arg2), t2(arg1, arg2));
	}
};
struct 
{
	template<typename F, typename T1, typename T2>
	struct Sig3
	{
		typedef Invoke2_<F, T1, T2> ret_type;
	};
	template<typename F, typename T1, typename T2>
	inline Invoke2_<F, T1, T2> operator () (F f, const T1 &t1, const T2 &t2) const
	{
		return Invoke2_<F, T1, T2>(f, t1, t2);
	}
} Invoke2;
template<typename F, typename T>
struct Invoke1_
{
	const T t;
	const F f;
	Invoke1_(F f, const T &t) : f(f), t(t) {}
	template<typename A>
	struct Sig
	{
		typedef typename RetType<F, typename RetType<T, A>::type>::type ret_type;
	};
	template<typename A1, typename A2>
	struct Sig2
	{
		typedef typename RetType<F, typename RetType2<T, A1, A2>::type>::type ret_type;
	};
	template<typename A>
	inline typename Sig<A>::ret_type operator() (const A &arg) const { return f(t(arg)); }
	template<typename A1, typename A2>
	inline typename Sig2<A1, A2>::ret_type operator() (const A1 &arg1, const A2 &arg2) const { 
		return f(t(arg1, arg2));
	}
};
template<typename F, typename T>
inline Invoke1_<F, T> Invoke1(F f, const T &t)
{
	return Invoke1_<F, T>(f, t); 
}
$$ _replinf = Invoke2( _Map, ExtVal(_nat), Invoke1(ExtVal, Arg1()) );
$$ _replinfcat = Invoke1( _Cat, Invoke1(_replinf, Arg1()) );
$$ _seq_1_m1 = _replinfcat(IW(1) %lcat IW(-1));
#ifndef ONLINE_JUDGE
#define _open_files(name) freopen(name ".in", "r", stdin); freopen(name ".out", "w", stdout)
#else
#define _open_files(name)
#endif
#define _END_SOL int main() { _open_files("test"); solve(); return 0; }
_SOLUTION
