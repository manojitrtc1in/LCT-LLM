


























using namespace std;

using namespace __gnu_cxx;





struct _DummyType {};
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
	static inline const T& resolve(const vector<T> &a, typename vector<T>::iterator it)
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
inline void id5(const T &t, F f)
{
	_seq<const T>::template process<F>(t, f);
}


    id5(a, [&](const gcc_typename ValueType<decltype(a)>::type &v) -> bool {


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

template<typename T>
struct _io< _Vector_iterator<T> >
{
	inline static void read(_Vector_iterator<T> &x, int i) { assert(0); }
	inline static void write(const _Vector_iterator<T> &x) { printf("Vector_iterator"); }
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

	type name; \
	_io<type>::read(name, 0)

	type *name; \
	name = new type[sz]; \
	for (int __i = 0; __i < sz; __i++) _io<type>::read(name[__i], __i);
template<typename I, typename M>
inline typename item_type<M>::type _sumit(const I &keys, M &m)
{
    typename item_type<M>::type res(0);
    xforeach(keys, i, res = res + cmap<M>::read(m, i));
    return res;
}
struct SepComma { inline static void Print() { _wstr(", "); } };
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
	_end_extend



	id9(bname, t1, name1); \
	extend_fieldr(name, bname, t2, name2) \
		name(t1 name1, t2 name2) : bname(name1), name2(name2) {} \
		bool operator < (const name &other) const { \
			return cmp; \
		} \
	_end_extend
template<typename T, typename F> 
typename T::value_type Fold(const T &a, F f, const typename T::value_type &init_val)
{
	typename T::value_type res = init_val;
	xforeach(a, i, res = f(res, i));
	return res;
}
template<typename T>
struct MaxFtr
{
	typedef T res_type;
	T operator () (const T &a, const T &b) const { return max(a, b); }
};
template<typename T>
typename T::value_type _max(const T &a)
{
    typedef typename T::value_type X;
    return Fold(a, MaxFtr<X>(), numeric_limits<X>::min());
}


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
};
template<typename T>
struct cmap<ArrWrapper<T> >
{
	typedef typename ArrWrapper<T>::value_type V;
	inline static void write(ArrWrapper<T> &a, int i, 
		const V value) { a.a[i] = value; }
	inline static V& read(ArrWrapper<T> &a, int i) { return a.a[i]; }
};

	ArrWrapper<decltype(base)> name(base, n)

	_inx(type, name
	_wrap(name, name

template<typename T1, typename T2>
struct _pair
{
    id6(type, T1, f, T2, s);
};
template<typename Seq, typename F, typename R>
struct id0
{
    const Seq &a; 
    F f;
    typedef typename _pair<typename Seq::value_type, typename R::value_type>::type value_type;
    id0(const Seq &a, F f) : a(a), f(f) {}
    template<typename Ftr>
    inline void process(Ftr ftr) const
    {        
        typedef value_type f_type; 
        bool stop = false;
        xforeach(a, x,
            typedef f_type ff_type; 
            const auto &subseq = f(x);
            xforeach(subseq, y, 
                if (!ftr( ff_type(x, y) )) 
                {
                    stop = true;
                    xbreak;
                }
            );
            if (stop) xbreak;
        );        
    }
    inline int size() const { return _count(*this); }
    typedef _DummyType iterator;
};
template<typename Seq, typename F>
inline auto id2(const Seq &a, F _ftr) -> id0<Seq, F, decltype(_ftr( gcc_typename Seq::value_type() ))>
{
    return id0<Seq, F, decltype(_ftr( gcc_typename Seq::value_type() ) )>(a, _ftr);
}

    id2(seq, [&](const ValueType<decltype(seq)>::type &_) { return ftr; })
template<typename T, typename F, typename S>
struct MapWrapper
{
	const T &a; 
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
};
template<typename T, typename F>
auto id8(const T &a, F f) -> MapWrapper<T, F, decltype(f( gcc_typename ValueType<T>::type() ))>
{
	return MapWrapper<T, F, decltype(f( gcc_typename ValueType<T>::type() ))>(a, f);
}

	 { return __VA_ARGS__; })
template<
	typename T, 
	typename Filter  
>
struct FilterWrapper
{
	const T &a;
	Filter filter;
	FilterWrapper(const T &a, Filter filter) : a(a), filter(filter) {}
	typedef typename T::value_type value_type;
	typedef _DummyType iterator;
	template<typename F>
	inline void process(F f) const
	{
		xforeach(a, x, 
			if (filter(x))
				if (!f(x)) xbreak
		)
	}
    inline int size() const { return _count(*this); }
};
template<typename T, typename Filter>
inline FilterWrapper<T, Filter> id1(const T &t, Filter f)
{
	return FilterWrapper<T, Filter>(t, f);
}

	id1(a, [&](const ValueType<decltype(a)>::type &_) -> bool { return cond; })
template<typename T>
inline int _count(const T &a)
{
    int res = 0;
    xforeach(a, i, ++res);
    return res;
}

struct _divu {};
template<typename T> struct id7
{
	T a;
	id7(T a) : a(a) {}
	template<typename S> inline T operator / (S b) { assert(b > 0); T res = a / b; if (a % b > 0) res++; return res; }
};
template<typename T> inline id7<T> operator / (T a, _divu) { return id7<T>(a); }
struct id4
{
	const int n;
	typedef int value_type;
	id4(int n) : n(n) {}
	template<typename F> inline
		void process(F f) const
	{
		for (int i = 1; i * i <= n; i++) if (n % i == 0)
		{
			if (!f(i)) return;
			if (i * i != n) if (!f(n / i)) return;
		}
	}
	inline int size() const { return _count(*this); }
};
struct _arpx
{
    const int a0, d, lim;
    _arpx(int a0, int d, int lim) : a0(a0), d(d), lim(lim) { assert(d != 0); }
    typedef int value_type;
    inline int size() const 
    {  
        if (d > 0)        
            return lim <= a0 ? 0 : (lim - a0) divu d;
        else
            return lim >= a0 ? 0 : (a0 - lim) divu -d;
    }
    template<typename F>
    inline void process(F f) const
    {
        if (d > 0) 
        {
            for (int i = a0; i < lim; i += d) if (!f(i)) break;
        }
        else
        {
            for (int i = a0; i > lim; i += d) if (!f(i)) break;
        }
    }
};












void solve() {
    id3(int, t, n);
    $$ divs = _filter(_ <= n / 3, id4(n)); 
    $$ ways = _mapzipcat( divs, _rng(_) ); 
    $$ res = _max( _map( ways, _sumit( _arpx(_.s, _.f, n), t ) ) );
    _w(res);
}
_END_SOL
