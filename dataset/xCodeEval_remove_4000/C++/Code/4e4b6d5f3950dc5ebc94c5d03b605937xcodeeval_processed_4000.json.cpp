
                                                                                 \
                                                                                 \
id1(f, int, a, b)                                                              \
{                                                                                \
    return _filter(_.f != _.s, _zip(a, b)).size();                               \
}                                                                                \
                                                                                 \
void solve() {                                                                   \
    $I2(int, n, k);                                                              \
    $I(string, t);                                                               \
    $$ s = t;                                                                    \
    if (k > 2)                                                                   \
    {                                                                            \
        FUN(other) (char c1, char c2) -> char                                    \
        {                                                                        \
            return _last(_take(1, _filter(_ != c1 && _ != c2, _seg('A', 'Z')))); \
        };                                                                       \
        _forseg(i, 1, n-1)                                                       \
            if (s[i] == s[i-1]) s[i] = other(s[i-1], i + 1 < n ? s[i+1] : 'x');  \
    }                                                                            \
    else                                                                         \
    {                                                                            \
        $$ s1 = _take(n, _replinfcat(LI2('A', 'B')));                            \
        $$ s2 = _take(n, _replinfcat(LI2('B', 'A')));                            \
        if (f(t, s1) < f(t, s2)) s = id11(s1); else s = id11(s2);          \
    }                                                                            \
    _w_(f(s, t));                                                                \
    _w(s);                                                                       \
}                                                                                \
                                                                                 \
_END_SOL                                                                         \
                                                                                 \






























using namespace std;

using namespace __gnu_cxx;








struct _DummyType {};
template<typename T>
struct ValueType {
	typedef typename remove_reference<T>::type clean_type;
	typedef typename clean_type::value_type type;
};
template<typename T>
struct _IsIterable { enum { value = 0 }; };





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
inline void id7(const T &t, F f)
{
	_seq<const T>::template process<F>(t, f);
}


    id7(a, [&](const gcc_typename ValueType<decltype(a)>::type &v) -> bool {

    { \
    typedef const gcc_typename ValueType<decltype(a)>::type &_T_; \
    int i = -1; \
    id7(a, [&](_T_ v) -> bool { ++i; return [&]() -> bool {





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
	inline int size(int mx = numeric_limits<int>::max()) const { return b < a ? 0 : b - a; }
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
	inline static void write(const bool &b) { printf("%s", b ? "
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

template<typename T>
struct id6
{
	SEQ_TYPE(T) base;
    id6(const T &base) : base(base) {}
    typedef T value_type;
    template<typename F>
    inline void process(F f) const { f(base); }
	inline int size(int mx = numeric_limits<int>::max()) const { return 1; }
};
template<typename T>
inline id6<T> IW(const T &x) { return id6<T>(x); }

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
void id3(const T &a, Sep sep)
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

	struct name : public base \
	{ \
		type field_name; \
		typedef type field_name
		name() {} \
		inline void __write() const { base::__write(); if (!_is_empty<base>::value) _wsp; \
			_wstr(
		inline void _write() const { __write(); _wstr(")"); } \
		inline void _read(int i) { base::_read(i); _io<type>::read(field_name, i); }




	extend_fieldr(name, tup0, t1, name1) \
		name(t1 name1) : name1(name1) {} \
		_CMP_(name, cmp) \
	_end_extend


	id8(bname, t1, name1); \
	extend_fieldr(name, bname, t2, name2) \
		name(t1 name1, t2 name2) : bname(name1), name2(name2) {} \
		_CMP_(name, cmp) \
	_end_extend




template<typename T>
int xlen(const T &a) { return (int)a.size(); }
template<typename T1, typename T2>
struct _pair
{
    id5(type, T1, f, T2, s, cmp_aa(f, s));
};
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
inline FilterWrapper<T, Filter> id0(const T &t, Filter f)
{
	return FilterWrapper<T, Filter>(t, f);
}

	id0(a, [&](const gcc_typename ValueType<decltype(a)>::type &_) -> bool { return cond; })
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
	ITER_SIZE
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
    ITER_SIZE
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
	template<typename F>    
	void process(F f) const
	{
		for (int i = 0; ; i++) if (!f(i)) break;
	}
    inline int size(int mx = numeric_limits<int>::max()) const { return numeric_limits<int>::max(); }
	ITER_WRITE
    typedef int iterator;
    iterator begin() const { return 0; }
    iterator end() const { return -1; }
    int resolve_iterator(iterator it) const { return it; }
};
template<> struct _IsIterable<NaturalSequence> { enum { value = 1 }; };

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
	typedef _DummyType iterator; 
	ITER_WRITE
};
template<typename T>
struct id9
{
	const T &a;
	id9(const T &a) : a(a) {}
	template<typename T2> inline
		ConcatLists<T, T2> operator % (const T2 &b) const { return ConcatLists<T, T2>(a, b); }
};
struct _lcat {};
template<typename T> inline
	id9<T> operator % (const T &a, _lcat) { return id9<T>(a); }

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
struct id4
{
	T val;
	id4(const T &val) : val(val) {}
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
	struct Sig { typedef id4<T> ret_type; };
	template<typename T>
	inline id4<T> operator() (const T &val) const { return id4<T>(val); }
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
struct id2
{
	const T1 t1;
	const T2 t2;
	const F f;
	id2(F f, const T1 &t1, const T2 &t2) : f(f), t1(t1), t2(t2) {}
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
		typedef id2<F, T1, T2> ret_type;
	};
	template<typename F, typename T1, typename T2>
	inline id2<F, T1, T2> operator () (F f, const T1 &t1, const T2 &t2) const
	{
		return id2<F, T1, T2>(f, t1, t2);
	}
} Invoke2;
template<typename F, typename T>
struct id10
{
	const T t;
	const F f;
	id10(F f, const T &t) : f(f), t(t) {}
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
inline id10<F, T> Invoke1(F f, const T &t)
{
	return id10<F, T>(f, t); 
}
template<typename T>
string id11(const T &a, const string &sep = "")
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

$$ _replinf = Invoke2( _Map, ExtVal(_nat), Invoke1(ExtVal, Arg1()) );
$$ _replinfcat = Invoke1( _Cat, Invoke1(_replinf, Arg1()) );
$$ _last = Invoke2( _Collapse, ExtVal( Arg1() ), Arg1() );






_SOLUTION
