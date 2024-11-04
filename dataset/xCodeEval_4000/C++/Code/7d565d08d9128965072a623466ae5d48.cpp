#define _SOLUTION                                                     \
                                                                      \
                                                                      \
void solve() {                                                        \
    $I(int, n); $I(string, s);                                        \
    $$ lens = _if(_odd(n), IW(3), EmptySeq<int>()) %lcat _replinf(2); \
    $$ t = _map(_cut(s, lens), sjoinch(_));                           \
    _wi_s(t, "-");                                                    \
}                                                                     \
                                                                      \
_END_SOL                                                              \
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
#define gcc_typename typename
using namespace __gnu_cxx;
#define LL_SPEC "%I64d"
#define ITER_WRITE inline void _write() const { _wstr("["); write_iterable(*this, SepComma()); _wstr("]"); }
#define ITER_SIZE inline int size(int mx = numeric_limits<int>::max()) const { return _count(_take(mx, *this)); }
#define SEQ_TYPE(x) const x
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
template<typename T>
struct _ConstIterator { typedef typename T::iterator type; };
template<typename T>
struct _ConstIterator<vector<T> > { typedef typename vector<T>::const_iterator type; };
template<>
struct _ConstIterator<string> { typedef gcc_typename string::const_iterator type; };
#define _wstr(s) printf("%s", s)
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
#define xforeachi_(a, i, v) \
    { \
	const auto &__a__ = a; \
    typedef const gcc_typename ValueType<decltype(__a__)>::type &_T_; \
    int i = -1; \
    _seq_process_c(__a__, [&](_T_ v) -> bool { ++i; return [&]() -> bool {
#define x_endfe return true; }); }
#define x_endfei return true; }(); }); }
#define xforeach(a, v, ...)  xforeach_(a, v) __VA_ARGS__; x_endfe
#define xforeachi(a, i, v, ...) xforeachi_(a, i, v) __VA_ARGS__; x_endfei
#define xfor(a, v, ...) xforeach(a, v, __VA_ARGS__)
struct SepComma { inline static void Print() { _wstr(", "); } };
struct SepCustom {
	const string s;
	SepCustom(const string &s) : s(s) {}
	void Print() const { _wstr(s.c_str()); }
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
template<typename T>
struct iterable_wrap
{
	SEQ_TYPE(T) base;
    iterable_wrap(const T &base) : base(base) {}
    typedef T value_type;
    template<typename F>
    inline void process(F f) const { f(base); }
	inline int size(int mx = numeric_limits<int>::max()) const { return 1; }
    inline T operator [] (int idx) const { assert(idx == 0); return base; }
};
template<typename T>
inline iterable_wrap<T> IW(const T &x) { return iterable_wrap<T>(x); }
#define $I(type, name) \
	type name; \
	_io<type>::read(name, 0)
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
#define _wi_s(a, sep) write_iterable(a, SepCustom(sep))
#define _for(i, n) for (int i = 0; i < n; i++)
#define $$ auto
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
	S operator [] (int i) const { return f(a[i]); }
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
	value_type operator [] (int i) const { assert(i < cnt); return a[i]; }
    typedef _DummyType iterator;
	ITER_WRITE
};
template<typename T>
inline TakeWrapper<T> _take(int cnt, const T &a)
{
    return TakeWrapper<T>(cnt, a);
}
template<typename T1, typename T2>
struct IfWrapper
{
    typedef typename T1::value_type value_type;
    typedef _DummyType iterator;
    SEQ_TYPE(T1) a;
    SEQ_TYPE(T2) b;
    bool cond;
    IfWrapper(const T1 &a, const T2 &b, bool cond) : a(a), b(b), cond(cond) {}
    template<typename F>
    void process(F f) const
    {
        if (cond) _seq_process_c(a, f); else _seq_process_c(b, f);
    }
	value_type operator [] (int i) const { return cond ? a[i] : b[i]; }
    int size(int mx = numeric_limits<int>::max()) const { if (cond) return a.size(mx); else return b.size(mx); }
    ITER_WRITE
};
template<typename T1, typename T2>
IfWrapper<T1, T2> _if(bool cond, const T1 &a, const T2 &b)
{
    return IfWrapper<T1, T2>(a, b, cond);
}
template<typename T1>
struct SubList
{
    typedef typename _ConstIterator<T1>::type t1_it;        
    const T1 &a;
    t1_it it0; 
    int k; 
    SubList(const T1 &a, const t1_it &it0, int k) : a(a), it0(it0), k(k) {}
    typedef typename T1::value_type value_type;
    template<typename F>
    void process(F f) const
    {
        t1_it it = it0;
        _for(i, k)
        {
            if (!f(citerator<T1>::resolve(a, it))) return;
            ++it;
        }
    }
    int size(int mx = numeric_limits<int>::max()) const { return k; }
    typedef _DummyType iterator;
    ITER_WRITE
};
template<typename T1, typename T2>
struct CutWrapper
{    
    typedef SubList<T1> value_type;
    typedef _DummyType iterator;
    SEQ_TYPE(T1) a;
    SEQ_TYPE(T2) b;
    CutWrapper(const T1 &a, const T2 &b) : a(a), b(b) {}
    template<typename F>
    void process(F f) const
    {
        auto it = a.begin();
        typedef value_type f_type; 
        xforeach(b, x,
            assert(x >= 0);
            auto st = it;
            _for(i, x)
            {
                if (!(it != a.end())) 
                {
                    if (i > 0) f(f_type(a, st, i));
                    xbreak;
                }
                ++it;
            }
            if (!f(f_type(a, st, x))) xbreak;            
        );
    }
    ITER_SIZE
	ITER_WRITE
};
template<typename T1, typename T2>
CutWrapper<T1, T2> _cut(const T1 &a, const T2 &b)
{
    return CutWrapper<T1, T2>(a, b);
}
struct NaturalSequence
{
	typedef int value_type;
	template<typename F>    
	void process(F f) const
	{
		for (int i = 0; ; i++) if (!f(i)) break;
	}
    inline int size(int mx = numeric_limits<int>::max()) const { return numeric_limits<int>::max(); }
	value_type operator [] (int i) const { return i; }
	ITER_WRITE
    typedef int iterator;
    iterator begin() const { return 0; }
    iterator end() const { return -1; }
    int resolve_iterator(iterator it) const { return it; }
};
template<> struct _IsIterable<NaturalSequence> { enum { value = 1 }; };
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
    inline int size(int mx = numeric_limits<int>::max()) const { 
		int t = a.size(mx);
		mx -= max(mx, t);
		return t + b.size(mx);
	}
    inline value_type operator [] (int idx) const
    {
        int t = a.size(idx + 1);
        if (t > idx) return a[idx];
        return b[idx - t];
    }
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
#define _MR_
template<typename T>
struct ExtVal_
{
	const T val;
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
struct Arg2
{
	template<typename A1, typename A2>
	struct Sig2 { typedef A2 ret_type; };	
	template<typename A1, typename A2>
	inline A2 operator() (const A1 &arg1, const A2 &arg2) const { return arg2; }
};
template<typename F, typename T1, typename T2>
struct Invoke2_
{
	const T1 _MR_ t1;
	const T2 _MR_ t2;
	const F _MR_ f;
	Invoke2_(const F &f, const T1 &t1, const T2 &t2) : f(f), t1(t1), t2(t2) {}
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
	inline Invoke2_<F, T1, T2> operator () (const F &f, const T1 &t1, const T2 &t2) const
	{
		return Invoke2_<F, T1, T2>(f, t1, t2);
	}
} Invoke2;
template<typename F, typename T>
struct XInvoke1_
{
	const T _MR_ t;
	const F _MR_ f;
	XInvoke1_(const F &f, const T &t) : f(f), t(t) {}
	template<typename A>
	struct Sig
	{
		typedef typename RetType<typename RetType<F, A>::type, typename RetType<T, A>::type>::type ret_type;
	};
	template<typename A1, typename A2>
	struct Sig2
	{
		typedef typename RetType<typename RetType2<F, A1, A2>::type, typename RetType2<T, A1, A2>::type>::type ret_type;
	};
	template<typename A>
	inline typename Sig<A>::ret_type operator() (const A &arg) const { return f(arg)(t(arg)); }
	template<typename A1, typename A2>
	inline typename Sig2<A1, A2>::ret_type operator() (const A1 &arg1, const A2 &arg2) const { 
		return f(arg1, arg2)(t(arg1, arg2));
	}
};
template<typename F, typename T>
struct Invoke1_
{
	const T _MR_ t;
	const F _MR_ f;
	Invoke1_(const F &f, const T &t) : f(f), t(t) {}
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
struct
{
	template<typename F, typename T1>
	struct Sig2
	{
		typedef Invoke1_<F, T1> ret_type;
	};
	template<typename F, typename T1>
	inline Invoke1_<F, T1> operator () (const F &f, const T1 &t1) const
	{
		return Invoke1_<F, T1>(f, t1);
	}
} Invoke1;
template<typename T>
string sjoinch(const T &a, const string &sep = "")
{
	string res;
	if (sep.empty())
	{
		res.resize(a.size());
		xforeachi(a, i, c, res[i] = c)
	}
	else
	{		
		int n = a.size();
		res.resize(n + xlen(sep) * (n - 1));
		int pos = 0;
		xfor(a, c,
			if (pos > 0) xfor(sep, _, res[pos++] = _);			
			res[pos++] = c;
		)
	}
	return res;
}
template<typename T> inline
bool _odd(const T &x)
{
    return x % 2 != 0;
}
template<typename T>
struct EmptySeq
{
	typedef T value_type;
	int size(int mx = 0) const { return 0; }
	template<typename F>
	inline void process(F f) const {  }
	typedef _DummyType iterator;
	ITER_WRITE
};
#define I1 Invoke1
#define I2 Invoke2
#define A1 Arg1 ()
#define A2 Arg2 ()
#define E ExtVal
$$ _replinf = I2 (_Map, E (_nat), I1 (E, A1));
#undef I1
#undef I2
#undef A1
#undef A2
#undef E
#ifndef ONLINE_JUDGE
#define _open_files(name) freopen(name ".in", "r", stdin); freopen(name ".out", "w", stdout)
#else
#define _open_files(name)
#endif
#define _END_SOL int main() { _open_files("test"); solve(); return 0; }
_SOLUTION
