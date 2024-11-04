#define _SOLUTION                                           \
                                                            \
                                                            \
void solve() {                                              \
    $I4(int, n, d, a, b);                                   \
    $Ix(int_abi, q, n);                                     \
    seqvec(x, _map(q, PAIR(_.a %mul% a + _.b * b, _.idx))); \
    _sort(x);                                               \
    $$ res = _takewhile(_.f <= d, _foldsum_f(x));           \
    _w_(res.size());                                        \
    _wi(_map(res, _.s + 1));                                \
}                                                           \
                                                            \
_END_SOL                                                    \
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
#define ITER_SIZE inline int size(int mx = numeric_limits<int>::max()) const { return _count(_take(mx, *this)); }
#define SEQ_TYPE(x) const x
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
struct citerator<set<T> >
{
	static inline const T& resolve(const set<T> &a, typename set<T>::const_iterator it)
		{ return *it; }
};
template<typename T> struct _IsIterable<set<T> > { enum { value = 1 }; };
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
struct SepSpace { inline static void Print() { _wsp; } };
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
#define $I4(type, name1, name2, name3, name4) $I3(type, name1, name2, name3); $I(type, name4)
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
#define _wi(a) write_iterable(a, SepSpace())
struct tup0 {
	inline void _read(int i) {}
	inline void __write() const { _wstr("("); }
	inline void _write() const { __write(); _wstr(")"); }
	template<typename T> inline bool operator == (const T &other) const { return true; }
};
struct tup0i {
	int idx;
	inline void _read(int i) { idx = i; }
	inline void __write() const { _wstr("(idx: "); _io<int>::write(idx); }
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
#define tup1i(name, t1, name1) tup1ic(name, t1, name1, false)
#define tup1ic(name, t1, name1, cmp) \
	extend_fieldr(name, tup0i, t1, name1) \
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
#define tup2ic(name, t1, name1, t2, name2, cmp) tup2ic_(STRUCT_NAME, name, t1, name1, t2, name2, cmp)
#define tup2ic_(bname, name, t1, name1, t2, name2, cmp) \
	tup1i(bname, t1, name1); \
	extend_fieldr(name, bname, t2, name2) \
		name(t1 name1, t2 name2) : bname(name1), name2(name2) {} \
		_CMP_(name, cmp) \
	_end_extend
#define tup3(name, t1, name1, t2, name2, t3, name3) tup3c(name, t1, name1, t2, name2, t3, name3, false)
#define tup3c(name, t1, name1, t2, name2, t3, name3, cmp) tup3_(STRUCT_NAME, name, t1, name1, t2, name2, t3, name3, cmp)
#define tup3_(bname, name, t1, name1, t2, name2, t3, name3, cmp) \
	tup2(bname, t1, name1, t2, name2); \
	extend_fieldr(name, bname, t3, name3) \
		name(t1 name1, t2 name2, t3 name3) : bname(name1, name2), name3(name3) {} \
		_CMP_(name, cmp) \
	_end_extend
#define seqvec(name, a) \
	const auto &name##_tmp = a; \
	vector<gcc_typename ValueType<decltype(name##_tmp)>::type> name; \
	populate(name, name##_tmp)
#define _sort(a) if (a.size() > 0) sort(&a[0], &a[0] + a.size())
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
#define _wrap(name, base, n) \
	ArrWrapper<decltype(base)> name(base, n)
#define $Ix(type, name, n) \
	_inx(type, name##_base, n); \
	_wrap(name, name##_base, n)
template<typename InIterable, typename S, typename F>
struct FoldWrapper
{
	SEQ_TYPE(InIterable) a; 
	typedef S value_type;
	typedef FoldWrapper<InIterable, S, F> my_type;
	S init_val;
	F f; 
	FoldWrapper(const InIterable &a, const S &init_val, F f) : a(a), init_val(init_val), f(f) {}
	typedef typename InIterable::iterator base_iterator;
	typedef typename InIterable::value_type base_value_type;
	tup3(_iterator, base_iterator, it, S, val, const my_type&, owner);
	struct iterator : public _iterator
	{		
		iterator(const base_iterator &it, const S &val, const my_type &owner) : _iterator(it, val, owner) {}
		inline bool operator != (const iterator &other) const { return _iterator::it != other.it; } 
		inline iterator& operator ++ () { _iterator::val = _iterator::owner.f(citerator<InIterable>::resolve(_iterator::owner.a, _iterator::it), _iterator::val); ++_iterator::it; return *this; }
	};
	inline iterator begin() const { return iterator(a.begin(), init_val, *this); }
	inline iterator end() const { return iterator(a.end(), _null<S>::value(), *this); }
	inline int size(int mx = numeric_limits<int>::max()) const { return a.size(mx); }
	inline S resolve_iterator(const iterator &it) const 
	{ 	
		return f(citerator<InIterable>::resolve(a, it.it), it.val);
	}
    template<typename Ftr> inline
    void process(Ftr ftr) const
    {
        S cur = init_val;
        xforeach(a, x, 
            cur = f(x, cur);
            if (!ftr(cur)) xbreak;
        )
    }
	ITER_WRITE
};
template<typename A, typename B, typename C> struct _IsIterable<FoldWrapper<A, B, C> > { enum { value = 1 }; };
template<typename T, typename S, typename F> inline
FoldWrapper<T, S, F> create_fold_wrapper(const T &a, const S &init_val, F f)
{
    return FoldWrapper<T, S, F>(a, init_val, f);
}
#define SumFolder_field_macro(fld) \
template<typename T> \
struct ZeroField_##fld \
{ \
    inline static T value() { T res; res.fld = 0; return res; } \
}; \
template<typename T> \
struct SumFolder_##fld \
{ \
    typedef T res_type; \
    \
    inline T operator () (const T &a, const T &b) const { T res = a; res.fld = res.fld + b.fld; return res; } \
}; \
template<typename T> inline \
FoldWrapper<T, typename T::value_type, SumFolder_##fld<typename T::value_type> > _foldsum_##fld(const T a) \
{ \
    return create_fold_wrapper(a, ZeroField_##fld<typename T::value_type>::value(), SumFolder_##fld<typename T::value_type>()); \
}
SumFolder_field_macro(f)
template<typename T1, typename T2>
struct _pair
{
    tup2c(type, T1, f, T2, s, cmp_aa(f, s));
};
template<typename T1, typename T2>
typename _pair<T1, T2>::type PAIR(const T1 &f, const T2 &s)
{
	return typename _pair<T1, T2>::type(f, s);
}
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
	inline int size(int mx = numeric_limits<int>::max()) const { return a.size(mx); }
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
#define zzz typename _CleanType<typename result_of<F( typename ValueType<T>::type )>::type>::type
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
    inline int size(int mx = numeric_limits<int>::max()) const { return min(cnt, (int)a.size(min(cnt, mx))); }
    typedef _DummyType iterator;
	ITER_WRITE
};
template<typename T>
inline TakeWrapper<T> _take(int cnt, const T &a)
{
    return TakeWrapper<T>(cnt, a);
}
template<
    typename T, 
    typename F 
>
struct TakeWhileWrapper
{
    SEQ_TYPE(T) a;
    F f;
    TakeWhileWrapper(F f, const T &a) : a(a), f(f) {}
    typedef typename T::value_type value_type;
    typedef _DummyType iterator; 
    template<typename Ftr>
    inline void process(Ftr ftr) const
    {
        xforeach(a, x,
            if (!f(x)) xbreak;
            if (!ftr(x)) xbreak;
        );
    }
    ITER_SIZE
	ITER_WRITE
};
template<typename T, typename F>
TakeWhileWrapper<T, F> create_take_while(F f, const T &a)
{
    return TakeWhileWrapper<T, F>(f, a);
}
#define _takewhile(f, a) \
    create_take_while([&](const gcc_typename ValueType<decltype(a)>::type &_) -> bool { return f; }, a)
template<
	typename ListType, 
	typename SeqType 
>
void populate(ListType &lst, const SeqType &seq)
{
	xforeach(seq, x, lst.push_back(x));
}
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
tup2ic(int_abi, int, a, int, b, cmp_aa(a, b));
#ifndef ONLINE_JUDGE
#define _open_files(name) freopen(name ".in", "r", stdin); freopen(name ".out", "w", stdout)
#else
#define _open_files(name)
#endif
#define _END_SOL int main() { _open_files("test"); solve(); return 0; }
_SOLUTION
