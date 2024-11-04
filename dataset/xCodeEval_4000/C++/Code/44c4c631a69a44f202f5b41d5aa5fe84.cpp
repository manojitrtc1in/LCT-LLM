#define _SOLUTION                                                         \
                                                                          \
                                                                          \
void solve()                                                              \
{                                                                         \
    $I(int, n);                                                           \
    int mi = 0, ma = 0;                                                   \
    $Ixn(int, a, m);                                                      \
    {                                                                     \
        _sort(a);                                                         \
        $$ seq = _cat( _map(a, _segd(_, 1)) );                            \
        mi = _sum(_take(n, seq));                                         \
    }                                                                     \
    {                                                                     \
        _reverse(a);                                                      \
        $$ diffs = _zip(a, _drop(1, a) %lcat IW(0));                      \
        $$ seq = _cat(_mapi(diffs, replelems(i+1, _segd(_.f, _.s + 1)))); \
        ma = _sum(_take(n, seq));                                         \
    }                                                                     \
    _w(ma); _wsp; _w(mi);                                                 \
}                                                                         \
                                                                          \
_END_SOL                                                                  \








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
struct _DummyType {};
template<typename T>
struct ValueType {
	typedef typename remove_reference<T>::type clean_type;
	typedef typename clean_type::value_type type;
};
#define _wsp printf(" ")
#define _wstr(s) printf(s)
#define cmp_a(a) a < other.a
#define cmp_aa(a, b) cmp_a(a) || (a == other.a && b < other.b)
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
	static inline const T& resolve(const vector<T> &a, typename vector<T>::iterator it)
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
	inline int size() const { return b - a; }
    template<typename F>
    inline void process(F f) const
    {
        for (T i = a; i < b; ++i)
            if (!f(i)) break;
    }
	const T a, b;
	ITER_WRITE
};
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
	inline static void write(const double &x) { printf("%.9lf", x); }
};
template<>
struct _io<const double>
{	
	inline static void write(const double &x) { printf("%.9lf", x); }
};
template<>
struct _io<double&>
{
	inline static void read(double &x, int i) { scanf("%lf", &x); }
	inline static void write(const double &x) { printf("%.9lf", x); }
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
#define tup1(name, t1, name1) \
	extend_fieldr(name, tup0, t1, name1) \
		name(t1 name1) : name1(name1) {} \
	_end_extend
#define tup2(name, t1, name1, t2, name2) tup2c(name, t1, name1, t2, name2, false)
#define tup2c(name, t1, name1, t2, name2, cmp) tup2_(STRUCT_NAME, name, t1, name1, t2, name2, cmp)
#define tup2_(bname, name, t1, name1, t2, name2, cmp) \
	tup1(bname, t1, name1); \
	extend_fieldr(name, bname, t2, name2) \
		name(t1 name1, t2 name2) : bname(name1), name2(name2) {} \
		bool operator < (const name &other) const { \
			return cmp; \
		} \
	_end_extend
#define _sort(a) if (a.size() > 0) sort(&a[0], &a[0] + a.size())
#define _reverse(a) if (a.size() > 0) reverse(&a[0], &a[0] + a.size())
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
    tup2(type, T1, f, T2, s);
};
template<typename T, typename F, typename S>
struct MapIWrapper
{
	SEQ_TYPE(T) a; 
	typedef S value_type;
	F f; 
	MapIWrapper(const T &a, F f) : a(a), f(f) {}
	template<typename Ftr>
	inline void process(Ftr ftr) const
	{
		int i = 0;
		xfor(a, x,
			if (!ftr(f(i, x))) xbreak;
			++i;
		);
	}
	inline int size() const { return a.size(); }
	ITER_WRITE
};
template<typename T, typename F>
auto create_mapi(const T &a, F f) -> MapIWrapper<T, F, decltype(f( 0, gcc_typename ValueType<T>::type() ))>
{
	return MapIWrapper<T, F, decltype(f( 0, gcc_typename ValueType<T>::type() ))>(a, f);
}
#define _mapi(a, ...) create_mapi(a, [&](int i, const ValueType<decltype(a)>::type &_) \
	 { return __VA_ARGS__; })
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
template<typename T, typename F>
auto SimpleMapWrapper(const T &a, F f) -> MapWrapper<T, F, decltype(f( gcc_typename ValueType<T>::type() ))>
{
	return MapWrapper<T, F, decltype(f( gcc_typename ValueType<T>::type() ))>(a, f);
}
template<typename T, typename F, typename S>
MapWrapper<T, F, S> ExtMapWrapper(const T &a, F f, const S &dummy)
{
	return MapWrapper<T, F, S>(a, f);
}
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
#define _mapt(ty, a, ...) ExtMapWrapper(a, [&](const ValueType<decltype(a)>::type &_) -> \
	ty { return __VA_ARGS__; }, ty())
#define _mapzipt(ty, a, ...) ExtMapWrapper(a, [&](const ValueType<decltype(a)>::type &__) \
    { return _pair<ValueType<decltype(a)>::type, ty>::type(__, [&](const ValueType<decltype(a)>::type &_) -> \
    ty { return __VA_ARGS__; }(__)); }, _pair<ValueType<decltype(a)>::type, ty>::type())
template<
    typename T 
>
struct TakeWrapper
{
    SEQ_TYPE(T) a;
    int cnt;
    TakeWrapper(int cnt, const T &a) : cnt(cnt), a(a) { assert(cnt >= 0); }
    typedef typename T::value_type value_type;
    template<typename F>
    inline void process(F f) const
    {
		if (cnt <= 0) return;
        int i = 0;
        xforeach(a, x,
            if (!f(x)) xbreak;
			++i;
			if (i >= cnt) xbreak;
        )
    }
    inline int size() const { return min(cnt, (int)a.size()); }
    typedef _DummyType iterator;
	ITER_WRITE
};
template<typename T>
inline TakeWrapper<T> _take(int cnt, const T &a)
{
    return TakeWrapper<T>(cnt, a);
}
template<
    typename T 
>
struct DropWrapper
{
    SEQ_TYPE(T) a;
    int cnt;
    DropWrapper(int cnt, const T &a) : cnt(cnt), a(a) { assert(cnt >= 0); }
    typedef typename T::value_type value_type;
    template<typename F>
    inline void process(F f) const
    {
        int i = 0;
        xforeach(a, x,            
            ++i;
            if (i > cnt)
                if (!f(x)) xbreak;
        )
    }
    inline int size() const { return max(0, (int)a.size() - cnt); }
    typedef _DummyType iterator;
	ITER_WRITE
};
template<typename T>
inline DropWrapper<T> _drop(int cnt, const T &a)
{
    return DropWrapper<T>(cnt, a);
}
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
template<typename T>
CatWrapper<T> _cat(const T &a)
{
	return CatWrapper<T>(a);
}
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
template<typename T>
struct RevRange
{
    T a, b;
    RevRange(T a, T b) : a(a), b(b) {}
    typedef T value_type;
    typedef _DummyType iterator; 
    template<typename F>
    void process(F f) const
    {
        for (T i = b-1; !(i < a); --i)
            if (!f(i)) break;
    }
    inline int size() const { return max(T(0), a - b); }
    ITER_WRITE
};
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
template<typename F, typename A1, typename A2, typename A3>
struct RetType3
{
	typedef typename F::template Sig3<A1, A2, A3> sig_type;
	typedef typename sig_type::ret_type type;
};
struct Arg2
{
	template<typename A1, typename A2>
	struct Sig2 { typedef A2 ret_type; };	
	template<typename A1, typename A2>
	inline A2 operator() (const A1 &arg1, const A2 &arg2) const { return arg2; }
};
template<typename F, typename T1, typename T2, typename T3>
struct Invoke3_
{
	const T1 t1;
	const T2 t2;
	const T3 t3;
	const F f;
	Invoke3_(F f, const T1 &t1, const T2 &t2, const T3 &t3) : f(f), t1(t1), t2(t2), t3(t3) {}
	template<typename A>
	struct Sig
	{
		typedef typename RetType3<F, typename RetType<T1, A>::type, typename RetType<T2, A>::type, typename RetType<T3, A>::type>::type ret_type;
	};
	template<typename A1, typename A2>
	struct Sig2
	{
		typedef typename RetType3<F, typename RetType2<T1, A1, A2>::type, typename RetType2<T2, A1, A2>::type, typename RetType2<T3, A1, A2>::type>::type ret_type;
	};
	template<typename A>
	inline typename Sig<A>::ret_type operator() (const A &arg) const { return f(t1(arg), t2(arg), t3(arg)); }
	template<typename A1, typename A2>
	inline typename Sig2<A1, A2>::ret_type operator() (const A1 &arg1, const A2 &arg2) const { 
		return f(t1(arg1, arg2), t2(arg1, arg2), t3(arg1, arg2));
	}
};
template<typename F, typename T1, typename T2, typename T3>
inline Invoke3_<F, T1, T2, T3> Invoke3(F f, const T1 &t1, const T2 &t2, const T3 &t3)
{
	return Invoke3_<F, T1, T2, T3>(f, t1, t2, t3); 
}
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
struct
{
	inline Range<int> operator() (int a, int b) const
	{
		return Range<int>(a, b+1);
	}
	template<typename T1, typename T2>
	struct Sig2
	{
		typedef Range<int> ret_type;
	};
} _seg;
struct
{
	inline RevRange<int> operator() (int a, int b) const
	{
		return RevRange<int>(b, a+1);
	}
	template<typename T1, typename T2>
	struct Sig2
	{
		typedef RevRange<int> ret_type;
	};
} _segd;
$$ repl = Invoke2( _Map, Invoke2(_seg, ExtVal(1), Arg1()), Invoke1(ExtVal, Arg2()) );
$$ replelems = Invoke1( _Cat, Invoke2( _Map, Arg2(), Invoke3( Invoke2, ExtVal( repl ), Invoke1 ( ExtVal, Arg1() ), ExtVal( Arg1() ) ) ) );
#ifndef ONLINE_JUDGE
#define _open_files(name) freopen(name ".in", "r", stdin); freopen(name ".out", "w", stdout)
#else
#define _open_files(name)
#endif
#define _END_SOL int main() { _open_files("test"); solve(); return 0; }
_SOLUTION
