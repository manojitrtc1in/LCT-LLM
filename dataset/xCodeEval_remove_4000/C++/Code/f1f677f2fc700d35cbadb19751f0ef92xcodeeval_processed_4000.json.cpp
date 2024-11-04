
                                                    \
                                                    \
void solve()                                        \
{                                                   \
    $I(int, n);                                     \
    $$ s = _fold(x, MI(n, 0), x + _, _seg(1, n-1)); \
    _wi(_map(s, _.x + 1));                          \
}                                                   \
                                                    \
_END_SOL                                            \





























using namespace std;

using namespace __gnu_cxx;







typedef long long LL;
template<typename T>
struct ValueType {
	typedef typename remove_reference<T>::type clean_type;
	typedef typename clean_type::value_type type;
};


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
inline void id2(const T &t, F f)
{
	_seq<const T>::template process<F>(t, f);
}


    id2(a, [&](const gcc_typename ValueType<decltype(a)>::type &v) -> bool {


struct SepSpace { inline static void Print() { _wsp; } };
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
	inline static void write(const bool &b) { printf("%s", b ? "
};
template<>
struct _io<string>
{
    inline static void read(string &s, int i) { scanf("%s", __strbuf); s = string(__strbuf); }
    inline static void write(const string &s) { printf("%s", s.c_str()); }
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
		inline void _read(int i) { base::_read(i); _io<type>::read(field_name, i); } \
		template<typename T> \
		inline bool operator == (const T &other) const { return base::operator == (other) && field_name == other.field_name; }




	extend_fieldr(name, tup0, t1, name1) \
		name(t1 name1) : name1(name1) {} \
		_CMP_(name, cmp) \
	_end_extend



	id6(bname, t1, name1); \
	extend_fieldr(name, bname, t2, name2) \
		name(t1 name1, t2 name2) : bname(name1), name2(name2) {} \
		_CMP_(name, cmp) \
	_end_extend


	id4(bname, t1, name1, t2, name2); \
	extend_fieldr(name, bname, t3, name3) \
		name(t1 name1, t2 name2, t3 name3) : bname(name1, name2), name3(name3) {} \
	_end_extend

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
	id0(_iterator, base_iterator, it, S, val, const my_type&, owner);
	struct iterator : public _iterator
	{		
		iterator(const base_iterator &it, const S &val, const my_type &owner) : _iterator(it, val, owner) {}
		inline bool operator != (const iterator &other) const { return _iterator::it != other.it; } 
		inline iterator& operator ++ () { _iterator::val = _iterator::owner.f(citerator<InIterable>::resolve(_iterator::owner.a, _iterator::it), _iterator::val); ++_iterator::it; return *this; }
	};
	inline iterator begin() const { return iterator(a.begin(), init_val, *this); }
	inline iterator end() const { return iterator(a.end(), _null<S>::value(), *this); }
	inline int size() const { return a.size(); }
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
template<typename T, typename S, typename F> inline
FoldWrapper<T, S, F> id1(const T &a, const S &init_val, F f)
{
    return FoldWrapper<T, S, F>(a, init_val, f);
}

	id1(seq, a0, [&](const gcc_typename ValueType<decltype(seq)>::type &_, const decltype(a0) &name) { return ftr; })
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
auto id5(const T &a, F f) -> MapWrapper<T, F, decltype(f( gcc_typename ValueType<T>::type() ))>
{
	return MapWrapper<T, F, decltype(f( gcc_typename ValueType<T>::type() ))>(a, f);
}

	 { return __VA_ARGS__; })
struct MI
{
    int x;
    int mod;
	MI() : x(-1), mod(-1) {}
    MI(int mod, int val) : mod(mod) { x = val % mod; if (x < 0) x += mod; }
    explicit MI(int mod) : mod(mod), x(0) {}
    inline MI& operator += (int arg) { x += arg; x %= mod; if (x < 0) x += mod; return *this; }
    inline MI& operator += (const MI &arg) { assert(mod == arg.mod); x += arg.x; if (x > mod) x -= mod; return *this; }
    inline MI operator + (int arg) const { MI res(*this); return res += arg; }
    inline MI operator + (const MI &arg) const { MI res(*this); return res += arg; }
    inline MI& operator -= (int arg) { return operator += (-arg); return *this; }
    inline MI& operator -= (const MI &arg) { assert(mod == arg.mod); x -= arg.x; if (x < 0) x += mod; return *this; }
    inline MI operator - (int arg) const { MI res(*this); return res -= arg; }
    inline MI operator - (const MI &arg) const { MI res(*this); return res -= arg; }
    inline MI& operator *= (int arg) { x = (LL)x * arg % mod; if (x < 0) x += mod; return *this; }
    inline MI& operator *= (const MI &arg) { assert(mod == arg.mod); x = (LL)x * arg.x % mod; return *this; }
    inline MI operator * (int arg) const { MI res(*this); return res *= arg; }
    inline MI operator * (const MI &arg) const { MI res(*this); return res *= arg; }
    inline operator int() const { return x; }
	inline void _write() const { _w(x); _wstr("(mod "); _w(mod); _wstr(")"); }
};
inline MI operator + (int arg1, const MI &arg2) { return arg2 + arg1; }
inline MI operator * (int arg1, const MI &arg2) { return arg2 * arg1; }
inline MI operator - (int arg1, const MI &arg2) { return arg2 - arg1; }
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






_SOLUTION
