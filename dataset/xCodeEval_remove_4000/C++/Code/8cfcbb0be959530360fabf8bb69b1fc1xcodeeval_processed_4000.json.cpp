
                                                                \
                                                                \
void solve() {                                                  \
    $I(string, s);                                              \
    bool minus = false;                                         \
    if (s[0] == '-') { s = s.substr(1); minus = true; }         \
    expand2( ssplit(s, '.'), a, b);                             \
                                                                \
    _reverse(a);                                                \
    a = id5( _map(_cut(a, _replinf(3)), id1(_)), "," ); \
    _reverse(a);                                                \
    b = sprefix(b + "00", 2);                                   \
    $$ res = "$" + a + "." + b;                                 \
    if (minus) res = "(" + res + ")";                           \
    _w(res);                                                    \
}                                                               \
                                                                \
_END_SOL                                                        \
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
inline void id3(const T &t, F f)
{
	_seq<const T>::template process<F>(t, f);
}


	{ \
	const auto &id7 = a; \
    id3(id7, [&](const gcc_typename ValueType<decltype(id7)>::type &v) -> bool {

    { \
	const auto &id7 = a; \
    typedef const gcc_typename ValueType<decltype(id7)>::type &_T_; \
    int i = -1; \
    id3(id7, [&](_T_ v) -> bool { ++i; return [&]() -> bool {





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
void id6(const T &a, Sep sep)
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
int xlen(const T &a, int mx = numeric_limits<int>::max()) { return xlen_<T>::size(a, mx); }
template<typename T, int sz>
struct FixArray
{
	T data[sz];
	typedef T value_type;
	typedef int iterator;
	iterator begin() const { return 0; }
	iterator end() const { return sz; }
	T& resolve_iterator(const iterator &it) const { return data[it]; }
	T& operator [] (int i) { return data[i]; }
	template<typename F> void process(F f) const { _for(i, sz) if (!f(data[i])) break; }
	template<typename F> void process(F f) { _for(i, sz) if (!f(data[i])) break; }
	int size(int mx = numeric_limits<int>::max()) const { return sz; }
	void _read(int idx) { _for(i, sz) _io<T>::read(data[i], i); }
	ITER_WRITE
};
template<typename T, int sz> struct _IsIterable<FixArray<T, sz> > { enum { value = 1 }; };






template < typename T > T&& declval();

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





template<typename T, typename F>
auto id10(const T &a, F f) -> MapWrapper<T, F, zzz>
{
	return MapWrapper<T, F, zzz>(a, f);
}


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
    typedef _DummyType iterator;
	ITER_WRITE
};
template<typename T>
inline TakeWrapper<T> _take(int cnt, const T &a)
{
    return TakeWrapper<T>(cnt, a);
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
	ITER_WRITE
    typedef int iterator;
    iterator begin() const { return 0; }
    iterator end() const { return -1; }
    int resolve_iterator(iterator it) const { return it; }
};
template<> struct _IsIterable<NaturalSequence> { enum { value = 1 }; };

template<typename T>
inline int _count(const T &a)
{
    int res = 0;
    xforeach(a, i, ++res);
    return res;
}


	const auto &seqref = seq; \
	typedef gcc_typename ValueType<decltype(seqref)>::type t; \
	FixArray<t, 2> arr; \
	id8(arr, _take(2, seqref)); \
	t a = arr[0], b = arr[1]
template<typename T1, typename T2>
void id8(T1 &dst, const T2 &src)
{
	xforeachi(src, i, x, dst[i] = x);
}

template<typename T>
struct id0
{
	const T val;
	id0(const T &val) : val(val) {}
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
	struct Sig { typedef id0<T> ret_type; };
	template<typename T>
	inline id0<T> operator() (const T &val) const { return id0<T>(val); }
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
struct id4
{
	const T1 _MR_ t1;
	const T2 _MR_ t2;
	const F _MR_ f;
	id4(const F &f, const T1 &t1, const T2 &t2) : f(f), t1(t1), t2(t2) {}
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
		typedef id4<F, T1, T2> ret_type;
	};
	template<typename F, typename T1, typename T2>
	inline id4<F, T1, T2> operator () (const F &f, const T1 &t1, const T2 &t2) const
	{
		return id4<F, T1, T2>(f, t1, t2);
	}
} Invoke2;
template<typename F, typename T>
struct id11
{
	const T _MR_ t;
	const F _MR_ f;
	id11(const F &f, const T &t) : f(f), t(t) {}
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
struct id2
{
	const T _MR_ t;
	const F _MR_ f;
	id2(const F &f, const T &t) : f(f), t(t) {}
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
		typedef id2<F, T1> ret_type;
	};
	template<typename F, typename T1>
	inline id2<F, T1> operator () (const F &f, const T1 &t1) const
	{
		return id2<F, T1>(f, t1);
	}
} Invoke1;
inline string sprefix(const string &s, int len)
{
    assert(len >= 0);
    return s.substr(0, len);
}
inline int slen(const string &s)
{
    return s.size();
}
template<typename T>
string id5(const T &a, const string &sep = "")
{
    int cur = 0;
    bool f = false;
    FUN(add)(const string &s)
    {
        memcpy(__strbuf + cur, s.c_str(), slen(s));
        cur += slen(s);
    };
    xforeach(a, s, 
        if (f) add(sep);
        add(s);
        f = true;
    );
    __strbuf[cur] = 0;
    return string(__strbuf);
}
template<typename T>
string id1(const T &a, const string &sep = "")
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
struct SSplit
{
	const string &s;
	const char sep;
	const bool allow_empty;
	SSplit(const string &s, char sep, bool allow_empty = true) : s(s), sep(sep), allow_empty(allow_empty) {}
	typedef string value_type;
	template<typename F>
	void process(F f) const
	{
		string cur;
		int n = slen(s);
		for (int i = 0; i < n; i++)
		{
			if (s[i] == sep)
			{
				if (cur.empty())
				{
					if (allow_empty) if (!f(cur)) return;
				}
				else
				{
					if (!f(cur)) return;
					cur.clear();
				}
			}
			else
			{
				cur += s[i];
			}
		}
		if (!cur.empty() || allow_empty) f(cur);
	}
	ITER_SIZE
	typedef _DummyType iterator;
	ITER_WRITE
};
struct id9
{
	const string &s;
	const string &sep;
	const bool allow_empty;
	id9(const string &s, const string &sep, bool allow_empty = true) : s(s), sep(sep), allow_empty(allow_empty) 
		{ assert(!sep.empty()); }
	typedef string value_type;
	template<typename F>
	void process(F f) const
	{
		string cur;
		int n = slen(s);
		int m = slen(sep);
		if (m == 0) return;
		auto check = [&](int i) -> bool
		{
			if (i + m > n) return false;
			_for(j, m) if (s[i+j] != sep[j]) return false;
			return true;
		};
		for (int i = 0; i < n; i++)
		{
			if (check(i))
			{
				if (cur.empty())
				{
					if (allow_empty) if (!f(cur)) return;
				}
				else
				{
					if (!f(cur)) return;
					cur.clear();
				}
				i += m - 1;
			}
			else
			{
				cur += s[i];
			}
		}
		if (!cur.empty() || allow_empty) f(cur);
	}
	ITER_SIZE
	typedef _DummyType iterator;
	ITER_WRITE
};
inline SSplit ssplit(const string &s, char sep, bool allow_empty = true)
{
	return SSplit(s, sep, allow_empty);
}
inline id9 ssplit(const string &s, const string &sep, bool allow_empty = true)
{
	return id9(s, sep, allow_empty);
}





$$ _replinf = I2 (_Map, E (_nat), I1 (E, A1));











_SOLUTION
