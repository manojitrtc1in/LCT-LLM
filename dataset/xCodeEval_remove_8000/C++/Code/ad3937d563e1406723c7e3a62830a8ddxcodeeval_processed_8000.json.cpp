

























using namespace std;



using namespace stdext;



using namespace __gnu_cxx;








typedef long long LL;

inline double _randf()
{
    return (rand() * (RAND_MAX + 1) + rand()) / double((RAND_MAX + 1) * (RAND_MAX + 1));
}

inline int _rand(int x)
{
	return int(_randf() * x);
}

template <typename T>
struct Identity { typedef T type; };

struct _DummyType {};

template<typename T>
struct ValueType {
	typedef typename remove_reference<T>::type clean_type;
	typedef typename clean_type::value_type type;
};















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


namespace stdext
{
    template <typename X>
    inline size_t hash_value(const vector<X> &v)
    {
        return _Hash_value(v.begin(), v.end());
    }
}

namespace __gnu_cxx
{
    template<> struct hash<std::string>
    {
        size_t operator() (const std::string &x) const
        {
            return hash<const char*>()( x.c_str() );
        }
    };
    template<typename T> struct hash< std::vector<T> >
    {
        size_t operator() (const std::vector<T> &v) const
        {
            size_t res = 0;
            for (size_t i = 0; i < v.size(); i++)
                res = res * 1235321 + hash<T>()(v[i]);
            return res;
        }
    };
    template<> struct hash<long long>
    {
        size_t operator() (long long x) const
        {
            union { int i[2]; long long l; } tmp;
            tmp.l = x;
            return tmp.i[0] + 1235321 * tmp.i[1];
        }
    };
}


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

template<typename T, typename F>
inline void _seq_process(T &t, F f)
{
    _seq<T>::template process<F>(t, f);
}

template<typename T, typename F>
inline void id25(const T &t, F f)
{
	_seq<const T>::template process<F>(t, f);
}





    id25(a, [&](const gcc_typename ValueType<decltype(a)>::type &v) -> bool {



    _seq_process(a, [&](gcc_typename ValueType<decltype(a)>::type &v) -> bool {


    { \
    typedef const gcc_typename ValueType<decltype(a)>::type &_T_; \
    int i = -1; \
    id25(a, [&](_T_ v) -> bool { ++i; return [&]() -> bool {









template<typename T>
inline T id2()
{
	return T(1000000000);
}

template<typename T>
inline T get_zero()
{
	return T(0);
}

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
	inline static void read(double &x, int i) { scanf("%lf", &x); }
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


template<typename T>
struct _io< _Vector_iterator<T> >
{
	inline static void read(_Vector_iterator<T> &x, int i) { assert(0); }
	inline static void write(const _Vector_iterator<T> &x) { printf("Vector_iterator"); }
};


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

template<size_t sz>
void set_clear(bool (&a)[sz]) { memset(a, 0, sizeof(bool) * sz); }

template<size_t sz>
inline bool set_contains(bool (&a)[sz], int x) { return a[x]; }
inline bool set_contains(const bool *a, int x) { return a[x]; }
inline bool set_contains(bool **a, Idx2<int> x) { return a[x.i][x.j]; }

template<size_t sz>
inline void set_insert(bool (&a)[sz], int x) { a[x] = true; }
inline void set_insert(bool *a, int x) { a[x] = true; }
inline void set_insert(bool **a, Idx2<int> x) { a[x.i][x.j] = true; }

template<size_t sz>
inline void id21(bool (&a)[sz], int x) { a[x] = false; }
inline void id21(bool *a, int x) { a[x] = false; }
inline void id21(bool **a, Idx2<int> x) { a[x.i][x.j] = false; }

template<typename T>
struct id17
{
    T &base;
    id17(T &base) : base(base) {}
    typedef T value_type;
    template<typename F>
    inline void process(F f) const { f(base); }
};


	type name; \
	_io<type>::read(name, 0);


	type *name; \
	name = new type[sz]; \
	for (int __i = 0; __i < sz; __i++) _io<type>::read(name[__i], __i);


	type **name; \
	name = new type*[sz1]; \
	for (int i = 0; i < sz1; i++) { \
		name[i] = new type[sz2]; \
		for (int j = 0; j < sz2; j++) _io<type>::read(name[i][j], j); \
	}


	type *name; \
	name = new type[sz];


	type **name; \
	name = new type*[sz1]; \
	for (int i = 0; i < sz1; i++) name[i] = new type[sz2];




	for (int i = 0; i < n; i++) delete [] name[i]; \
	delete [] name; }


	for (int i = 0; i < n; i++) \
		cmap<decltype(name)>::write(name, i, val);


	for (int i = 0; i < n; i++) \
		for (int j = 0; j < m; j++) \
			name[i][j] = val;


	_tmpx(type, name, sz); \
	_fillx(name, sz, val);


	_tmpxx(type, name, sz1, sz2); \
	_fillxx(name, sz1, sz2, val);


	_tmpx(type, name, sz); \
	for (int i = 0; i < n; i++) \
		name[i] = (init_expr)

template<typename I, typename M>
inline void _fillit(const I &keys, M &m, const typename item_type<M>::type &val)
{
	xforeach(keys, i, cmap<M>::write(m, i, val));
}

struct SepSpace
{
	static void Print() { _wsp; }
};

struct SepLF
{
	static void Print() { _wlf; }
};

struct SepComma
{
	static void Print() { _wstr(", "); }
};

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
		bool operator < (const name &other) const { \
			return op; \
		} \
	}


	struct name : public base \
	{ \
		type field_name; \
		typedef type field_name
		name() : field_name(init_value) {} \
		inline void __write() const { base::__write(); if (!_is_empty<base>::value) _wsp; \
			_wstr(
		inline void _write() const { __write(); _wstr(")"); } \
	};


	struct name : public base \
	{ \
		type field_name; \
		typedef type field_name
		name() {} \
		inline void __write() const { base::__write(); if (!_is_empty<base>::value) _wsp; \
			_wstr(
		inline void _write() const { __write(); _wstr(")"); } \
		inline void _read(int i) { base::_read(i); _io<type>::read(field_name, i); }


	struct name : public base \
	{ \
		int idx; \
		typedef int idx_type; \
		name() {} \
		inline void __write() const { base::__write(); if (!_is_empty<base>::value) _wsp; \
			_wstr("idx:"); _io<int>::write(idx); } \
		inline void _write() const { __write(); _wstr(")"); } \
		inline void _read(int i) { base::_read(i); idx = i; }




	id22(name, tup0, t1, name1) \
		name(t1 name1) : name1(name1) {} \
	_end_extend



    tup1(bname, t1, name1); \
    extend_idx(name, bname) \
    bool operator < (const name &other) const { \
			return cmp; \
		} \
    _end_extend



	tup1(bname, t1, name1); \
	id22(name, bname, t2, name2) \
		name(t1 name1, t2 name2) : bname(name1), name2(name2) {} \
	_end_extend



	id26(bname, t1, name1, t2, name2); \
	id22(name, bname, t3, name3) \
		name(t1 name1, t2 name2, t3 name3) : bname(name1, name2), name3(name3) {} \
	_end_extend




	id13(bname, t1, name1, t2, name2, t3, name3); \
	id22(name, bname, t4, name4) \
		name(t1 name1, t2 name2, t3 name3, t4 name4) : bname(name1, name2, name3), name4(name4) {} \
		bool operator < (const name &other) const { \
			return cmp; \
		} \
	_end_extend




template<typename T, typename F>
int id34(T &a, F f)
{
	int res = -1;
	id23(a, i, v,
		if (f(v)) { res = i; xbreak; };
	)
	return res;
}

template<typename T, typename F>
int id18(T &a, F f)
{
	int res = -1;
	id23(a, i, v,
		if (f(v)) res = i;
	)
	return res;
}


	id34(x, [&](const item_type<decltype(x)>::type &_) -> bool { return cond; })


	id18(x, [&](const item_type<decltype(x)>::type &_) -> bool { return cond; })





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
	T operator () (const T &a, const T &b) const { return a + b; }
};

template<typename T>
struct MinFtr
{
	typedef T res_type;
	T operator () (const T &a, const T &b) const { return min(a, b); }
};

template<typename T>
struct MaxFtr
{
	typedef T res_type;
	T operator () (const T &a, const T &b) const { return max(a, b); }
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

template<typename T>
typename T::value_type _min(const T &a)
{
    typedef typename T::value_type X;
    return Fold(a, MinFtr<X>(), numeric_limits<X>::max());
}

template<typename T>
typename T::value_type _max(const T &a)
{
    typedef typename T::value_type X;
    return Fold(a, MaxFtr<X>(), numeric_limits<X>::min());
}


template<typename T, typename F>
void AutoMap(T &a, F f)
{
	xforeachx(a, v, v = f(v));
}

    AutoMap(t, [&](const ValueType<decltype(t)>::type &_) -> ValueType<decltype(t)>::type { return __VA_ARGS__; })




template<typename T>
struct _keys
{
};


    int name
    _wrap(name, name

template<typename T>
inline void swapord(T &a, T &b) { if (b < a) swap(a, b); }

template<typename T>
struct key_type { typedef int type; };

template<typename T>
void id12(T &a, const T &b) { a = min(a, b); }
template<typename T>
void id41(T &a, const T &b) { a = max(a, b); }

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

template<typename T>
struct _keys<ArrWrapper<T> >
{
    typedef Range<int> type;
    static type get(ArrWrapper<T> &t) { return type(0, t.n); }
};


	ArrWrapper<decltype(base)> name(base, n)


	_inx(type, name
	_wrap(name, name


	_tmpx(type, name
	_wrap(name, name

template<typename InIterable, typename F>
struct FoldWrapper
{
	const InIterable a;
	typedef typename F::res_type value_type;
	typedef FoldWrapper<InIterable, F> my_type;
	value_type init_val;
	F f;
	FoldWrapper(const InIterable a, const value_type &init_val, F f) : a(a), init_val(init_val), f(f) {}
	typedef typename InIterable::iterator base_iterator;
	typedef typename InIterable::value_type base_value_type;
	id13(_iterator, base_iterator, it, value_type, val, const my_type&, owner);
	struct iterator : public _iterator
	{		
		iterator(const base_iterator &it, const value_type &val, const my_type &owner) : _iterator(it, val, owner) {}
		inline bool operator != (const iterator &other) const { return _iterator::it != other.it; } 

		inline iterator& operator ++ () { _iterator::val = _iterator::owner.f(citerator<InIterable>::resolve(_iterator::owner.a, _iterator::it), _iterator::val); ++_iterator::it; return *this; }
	};
	inline iterator begin() const { return iterator(a.begin(), init_val, *this); }
	inline iterator end() const { return iterator(a.end(), _null<value_type>::value(), *this); }
	inline int size() const { return a.size(); }
	inline value_type resolve_iterator(const iterator &it) const 
	{ 	
		return f(citerator<InIterable>::resolve(a, it.it), it.val);
	}    
    template<typename Ftr> inline
    void process(Ftr ftr) const
    {
        value_type cur = init_val;
        xforeach(a, x, 
            cur = f(x, cur);
            if (!ftr(cur)) xbreak;
        )
    }
};

template<typename T, typename F> inline
FoldWrapper<T, F> id24(const T a, const typename F::res_type &init_val, F f)
{
    return FoldWrapper<T, F>(a, init_val, f);
}

template<typename T>
struct ProdFolder
{
	typedef T res_type;
	inline T operator () (const T &a, const T &b) const { return a * b; } 
};



	typedef decltype(base) type; \
	FoldWrapper<type, ProdFolder<type::value_type> > name(base, type::value_type(1), ProdFolder<type::value_type>())


template<typename T> \
struct ZeroField_
{ \
    inline static T value() { T res; res.fld = 0; return res; } \
}; \
template<typename T> \
struct SumFolder_
{ \
    typedef T res_type; \
    inline T operator () (const T &a, const T &b) const { T res = a; res.fld = res.fld + b.fld; return res; } \
}; \
template<typename T> inline \
FoldWrapper<T, SumFolder_
{ \
    return id24(a, ZeroField_
}

SumFolder_field_macro(s)

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
MapWrapper<T, F, typename T::value_type> SimpleMapWrapper(const T &a, F f)
{
	return MapWrapper<T, F, typename T::value_type>(a, f);
}

template<typename T, typename F, typename S>
MapWrapper<T, F, S> ExtMapWrapper(const T &a, F f, const S &dummy)
{
	return MapWrapper<T, F, S>(a, f);
}

template<typename T1, typename T2>
struct _pair
{
    id26(type, T1, f, T2, s);
};


	ValueType<decltype(a)>::type { return __VA_ARGS__; })


	ty { return __VA_ARGS__; }, ty())


    { return _pair<ValueType<decltype(a)>::type, ty>::type(__, [&](const ValueType<decltype(a)>::type &_) -> \
    ty { return __VA_ARGS__; }(__)); }, _pair<ValueType<decltype(a)>::type, ty>::type())

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
	template<typename F>
	inline void process(F f) const
	{
		xforeach(a, x, 
			if (filter(x))
				if (!f(x)) xbreak
		)
	}
};

template<typename T, typename Filter>
inline FilterWrapper<T, Filter> id1(const T &t, Filter f)
{
	return FilterWrapper<T, Filter>(t, f);
}


	id1(a, [&](const ValueType<decltype(a)>::type &_) -> bool { return cond; })


	id1(a, [&](const ValueType<decltype(a)>::type &name) -> bool { return cond; })

template<typename T, typename F> inline
bool Any(const T a, F f)
{
    bool res = false;
    xforeach(a, i, 
        if (f(i))
        {
            res = true;
            xbreak;
        }
    )
    return res;
}


    Any(a, [&](const ValueType<decltype(a)>::type &_) -> bool { return f; })

template<
    typename T
>
struct TakeWrapper
{
    const T a;
    int cnt;
    TakeWrapper(int cnt, const T a) : cnt(cnt), a(a) { assert(cnt >= 0); }
    typedef typename T::value_type value_type;
    template<typename F>
    inline void process(F f) const
    {
        int i = 0;
        xforeach(a, x,
            if (i >= cnt) xbreak;
            ++i;
            if (!f(x)) xbreak;
        )
    }
};

template<typename T>
inline TakeWrapper<T> _take(int cnt, const T a)
{
    return TakeWrapper<T>(cnt, a);
}

template<
    typename T,
    typename F
>
struct id16
{
    const T a;
    F f;
    id16(F f, const T a) : a(a), f(f) {}
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
};

template<typename T, typename F>
id16<T, F> id5(F f, const T a)
{
    return id16<T, F>(f, a);
}


    id5([&](const ValueType<decltype(a)>::type &_) -> bool { return f; }, a)

template<typename T>
inline int _count(const T &a)
{
    int res = 0;
    xforeach(a, i, ++res);
    return res;
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
};



template<typename T>
bool _is_prime(T x)
{
	if (x < 2) return false;
	for (T i = 2; i * i <= x; i++)
		if (x % i == 0)
			return false;
	return true;
}



template<
	typename ListType,
	typename SeqType
>
void populate(ListType &lst, SeqType seq)
{
	xforeach(seq, x, lst.push_back(x));
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
};



template<typename S1, typename S2>
struct id31
{
    const S1 &s1;
    const S2 &s2;
    id31(const S1 &s1, const S2 &s2) : s1(s1), s2(s2) {}
    typedef typename S1::value_type s1_type;
    typedef typename S2::value_type s2_type;
    typedef _DummyType iterator;
    id26(value_type, s1_type, f, s2_type, s);
    template<typename F>
    inline void process(F f) const
    {
        typedef value_type f_type;
        auto const &id14 = s1; 

        auto const &id11 = s2; 

        xforeach(id14, a,
            typedef f_type f_type2;
            auto const &id0 = id11; 

            bool stop = false;
            xforeach(id0, b, 
                if (!f(f_type2(a, b)))
                {
                    stop = true;
                    xbreak;
                }
            )            
            if (stop) xbreak;
        )
    }
};

template<typename S1, typename S2>
id31<S1, S2> _cartprod(const S1 &s1, const S2 &s2)
{
    return id31<S1, S2>(s1, s2);
}

template<typename T1, typename T2>
struct ConcatLists
{
    typedef typename T1::value_type value_type;
    const T1 &a;
    const T2 &b;
    ConcatLists(const T1 &a, const T2 &b) : a(a), b(b) {}
    template<typename F>
    inline void process(F f) const
    {
		bool stop = false;
		xforeach(a, i, if (!f(i)) { stop = true; xbreak; } )
        if (!stop) 
			xforeach(b, i, if (!f(i)) xbreak )
    }
};

template<typename T1, typename T2>
ConcatLists<T1, T2> operator % (const T1 &a, const T2 &b)
{
    return ConcatLists<T1, T2>(a, b);
}

template<typename ArrType, typename SeqType>
void apply_perm(ArrType &a, const SeqType &s)
{
    int n = a.size();
    typedef typename item_type<ArrType>::type T;
    vector<T> tmp(n);
    id23(s, i, p, tmp[p] = a[i]; assert(i < n && p < n && p >= 0));
    _for(i, n) a[i] = tmp[i];
}

template<typename ArrType>
struct StackWrapper
{
	ArrType &a;
	int n;
	StackWrapper(ArrType &a) : a(a), n(0) {}	
	typedef typename item_type<ArrType>::type value_type;
	inline void push_back(value_type x) { cmap<ArrType>::write(a, n, x); ++n; }
	inline value_type pop_back() { assert(n > 0); --n; return cmap<ArrType>::read(a, n); }
	inline bool empty() { return n == 0; }
	inline value_type& back() { assert(n > 0); return cmap<ArrType>::read(a, n-1); }
	inline void clear() { n = 0; }
	inline value_type& bback() { assert(n > 1); return cmap<ArrType>::read(a, n-2); }
	inline int size() { return n; }
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
struct Dfs
{
	GraphType &g;
	const VertOrderType &order;
	NewTreeFunctor new_tree;
	EnterVertexFunctor enter_vertex;
	LeaveVertexFunctor leave_vertex;
	BeforeTraverseFunctor id33;
	AfterTraverseFunctor id37;
	BackEdgeFunctor back_edge;
	MarkersType &markers;
	
	typedef typename GraphType::v_type V;

	Dfs(
		GraphType &g,
		const VertOrderType &order,
		NewTreeFunctor new_tree,			
		EnterVertexFunctor enter_vertex,
		LeaveVertexFunctor leave_vertex,
		BeforeTraverseFunctor id33,
		AfterTraverseFunctor id37,
		BackEdgeFunctor back_edge,
		MarkersType &markers
	) : g(g), order(order), new_tree(new_tree), enter_vertex(enter_vertex), leave_vertex(leave_vertex),
		id33(id33), id37(id37), back_edge(back_edge),
		markers(markers) {}

	void Do()
	{
		id15(order, i)
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
		id15(g.v_edges(v), e)
		{						
			if (cmap<MarkersType>::read(markers, e.v) == 0)
			{
				if (id33(v, e))
				{
					this->DfsRec(e.v, v);
					id37(v, e);
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
inline void id27(
	GraphType &g,
	const VertOrderType &order, 
	NewTreeFunctor new_tree,
	EnterVertexFunctor enter_vertex, 
	LeaveVertexFunctor leave_vertex, 
	BeforeTraverseFunctor id33,
	AfterTraverseFunctor id37,
	BackEdgeFunctor back_edge,
	MarkersType &markers
	)
{
	Dfs<GraphType, VertOrderType, NewTreeFunctor, EnterVertexFunctor, 
		LeaveVertexFunctor, BeforeTraverseFunctor, AfterTraverseFunctor, 
		BackEdgeFunctor, MarkersType>
		X(g, order, new_tree, enter_vertex, leave_vertex, id33, id37, back_edge, markers);
	X.Do();
}

namespace DFS
{

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










template<typename GraphType, typename MarkersType,
	typename LevAndDpType>
int id36(GraphType &g, MarkersType &markers, 
	LevAndDpType &lev, LevAndDpType &dp)
{	
	int id29 = 0, bridges = 0;
	id27(
		g, 
		g.vertices(), 
		V0,
		V_( RM(dp, v) = id29; RM(lev, v) = id29++ ),
		V_( --id29 ),
		E0,
		E_( if (RM(lev, u) < RM(dp, e.v)) bridges++; id12(RM(dp, u), RM(dp, e.v)) ),
		E_( id12(RM(dp, u), RM(lev, e.v)) ),
		markers
	);
	return bridges;
}

template<typename GraphType, typename MarkersType, typename CompsType,
	typename ListsType>
int id10(GraphType &g, MarkersType &markers, CompsType &comps,
	ListsType &lists)
{
	int cur = -1;
	_fillit(g.vertices(), markers, 0);
	id27(
		g,
		g.vertices(),
		V_( ++cur; RM(lists, cur).clear() ),
		V_( RM(comps, v) = cur; RM(lists, cur).push_back(v) ),		
		V0,
		E0,
		E0,
		E0,
		markers
	);
	return cur + 1;
}

template<typename GraphType, typename MarkersType, typename ListType>
void id39(GraphType &g, typename GraphType::v_type v0, MarkersType &markers, ListType &list)
{    
    _fillit(g.vertices(), markers, 0);
    id27(
        g,
        id17<typename GraphType::v_type>(v0),
        V0,
		V_( list.push_back(v) ),        
        V0,
        E0,
        E0,
        E0,
        markers
    );
}

template<typename GraphType, typename MarkersType, typename ColType>
bool id28(GraphType &g, MarkersType &markers, ColType &col)
{
	bool res = true;
	_fillit(g.vertices(), markers, 0);	
	vector<typename GraphType::v_type> order;
	xforeach(g.vertices(), i, if (RM(col, i) != -1) order.push_back(i) );
	xforeach(g.vertices(), i, if (RM(col, i) == -1) order.push_back(i) );
	id27(
		g,
		order,
		V_( if (RM(col, v) == -1) RM(col, v) = 0 ),
		V_( assert(RM(col, v) == 0 || RM(col, v) == 1) ),
		V0,
		E_( if (RM(col, e.v) == -1) RM(col, e.v) = 1 - RM(col, u); else if (RM(col, u) == RM(col, e.v)) res = false ),
		E0,
		E_( if (RM(col, u) == RM(col, e.v)) res = false ),
		markers
	);
	return res;
}

template<typename GraphType, typename MarkersType>
bool id38(GraphType &g, typename GraphType::v_type v0, MarkersType &markers)
{
    _fillit(g.vertices(), markers, 0);
    bool res = true;
    id27(
        g,
        id17<typename GraphType::v_type>(v0),
        V0,
        V0,
        V0,
        E0,
        E0,
        E_(res = false),
        markers
    );
    return res;
}

}



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
    inline int size() const { return (b - a) * (d - c); }
};

template<
    typename WeightType,
    typename F
>
struct id9
{
    typedef id9<WeightType, F> graph_type;
    typedef Idx2<int> v_type;
    typedef Range2<int> v_set_type;
    typedef WeightType weight_type;
    struct e_type
    {
        Idx2<int> v;
        WeightType w;
        e_type(const v_type &v, const WeightType &w) : v(v), w(w) {}
    };
    struct id3
    {
        graph_type &g;
        v_type v;
        typedef e_type value_type;
        template<typename Ftr>
        void process(Ftr f) const
        {
            weight_type w(0);

            if (cond) \
                if (g.f(v, v_type(i, j), w)) \
                    if (!f(e_type(v_type(i, j), w))) \
                        return;

            process_dir(v.j + 1 < g.m, v.i, v.j + 1);
            process_dir(v.i + 1 < g.n, v.i + 1, v.j);
            process_dir(v.j > 0, v.i, v.j - 1);
            process_dir(v.i > 0, v.i - 1, v.j);      

        }
        id3(graph_type &g, const v_type &v) : g(g), v(v) {}
    };

    int n, m;
    v_set_type vs;
    F f;

    inline v_set_type& vertices() { return vs; }
    inline id3 v_edges(const v_type &v)
    {
        return id3(*this, v);
    }

    id9(int n, int m, F f) : n(n), m(m), vs(0, n, 0, m), f(f) {}
};

template<typename W, typename F>
id9<W, F> id8(int n, int m, W &dummy_w, F f)
{
    return id9<W, F>(n, m, f);
}


    w_type w_var; \
    auto name = id8(n, m, w_var, [&](Idx2<int> u, Idx2<int> v, w_type &w) -> bool { __VA_ARGS__; return true; })



template<typename T> struct __v_type { typedef typename T::v_type type; };


    vector<__v_type<decltype(g)>::type>

template<typename ArrType>
struct id35
{
	typedef ArrType base_type;
	ArrType &a;
	int n, m;
	id35(ArrType &a, int n, int m) : a(a), n(n), m(m) {}
	typedef typename strict_item_type<ArrType>::type sub_type;	
	typedef typename item_type<ArrType>::type value_type;
	struct iterator
	{
		int i, j, m;
		iterator(int i, int j, int m): i(i), j(j), m(m) {}
		inline bool operator != (const iterator &other) const { return i != other.i || j != other.j; }
		inline iterator& operator ++ () { ++j; if (j == m) j = 0, ++i; return *this; }
	};
	inline iterator begin() const { return iterator(0, 0, m); }
	inline iterator end() const { return iterator(n, 0, m); }
	inline int size() const { return n * m; }
	inline value_type& resolve_iterator(const iterator &it) const
	{
		return a[it.i][it.j];
	}
	inline ArrWrapper<sub_type> operator [](int i)
	{
		return ArrWrapper<sub_type>(a[i], m);
	}
    inline value_type& operator [](Idx2<int> idx)
    {
        return a[idx.i][idx.j];
    }
};

template<typename T>
struct cmap<id35<T> >
{
    typedef Idx2<int> key_type;
	typedef typename id35<T>::value_type V;
	inline static void write(id35<T> &a, key_type i, 
		const V value) { a.a[i.i][i.j] = value; }
	inline static V& read(id35<T> &a, key_type i) { return a.a[i.i][i.j]; }
};


	id35<decltype(base)> name(base, n, m)


	_inxx(type, name
	_wrap2(name, name


	_tmpxx(type, name
	_wrap2(name, name


	foreachx(a, v, _io<decltype(v.fld)>::read(v.fld, 0))

template<typename T>
struct EventAdder
{
	typedef T value_type;
    vector<T> &v;
    EventAdder(vector<T> &v) : v(v) {}
    inline void operator () (const T &e) { v.push_back(e); }
};

template<typename EType, typename F1, typename F2>
int event_system(const EType &dummy, F1 gen, F2 proc)
{
    vector<EType> _evs;
    gen(EventAdder<EType>(_evs));
    sort(_evs.begin(), _evs.end());
    for (auto it = _evs.begin(); it != _evs.end(); it++)
    {
        int tmp = proc(*it);
        if (tmp) return tmp;
    }
    return 0;
}


    event_system(ev_type(), [&](EventAdder<ev_type> $) { typedef ValueType<decltype($)>::type E; gen; }, [&](const ev_type &_) -> int { proc; return 0; })

template<
	typename Arr,
	typename RevArr
>
struct id4
{
	Arr &a;
	RevArr &pos;
	int n;
	typedef typename item_type<Arr>::type kv_pair_type;
	typedef typename kv_pair_type::key_type key_type;
	typedef typename kv_pair_type::value_type value_type;

	inline int size() const { return n; }
	inline const kv_pair_type& top() const { assert(n > 0); return cmap<Arr>::read(a, 0); }

    id4(Arr &a, RevArr &pos) : a(a), pos(pos), n(0) {}

	inline void id30(const key_type &key, const value_type &value)
	{
		int idx = cmap<RevArr>::read(pos, key);
		if (idx == -1)
		{			
			a[n] = kv_pair_type(key, value);
			cmap<RevArr>::write(pos, key, n);
			++n;
			sift_up(n-1);
			return;
		}
		if (value < a[idx].value)
		{
			a[idx].value = value;
			sift_up(idx);
		}
	}

	inline void pop()
	{
		assert(n > 0);
		exchange(0, n-1);
		cmap<RevArr>::write(pos, a[n-1].key, -1);
		n--;
		if (n > 0) sift_down(0);
	}

	inline void exchange(int i, int j)
	{
		int tmp = cmap<RevArr>::read(pos, a[i].key);
		cmap<RevArr>::read(pos, a[i].key) = cmap<RevArr>::read(pos, a[j].key);
		cmap<RevArr>::read(pos, a[j].key) = tmp;
		swap(a[i], a[j]);
	}

	void sift_down(int i)
	{
		while (2*i+1 < n)
		{
			int left_c = 2*i + 1;
			int right_c = left_c + 1;
			int x = (right_c == n || a[left_c].value < a[right_c].value) ? left_c : right_c;
			if (a[i].value > a[x].value)
			{
				exchange(i, x);
				i = x;
			}
            else
            {
                break;
            }
		}
	}

	void sift_up(int i)
	{
		while (i > 0 && a[i].value < a[(i-1)/2].value)
		{
			exchange(i, (i-1)/2);
			i = (i-1)/2;
		}
	}
};

template<typename T, typename S>
inline id4<T, S> id7(T &arr, S &rev_arr)
{
    return id4<T, S>(arr, rev_arr);
}

template<
	typename GraphType,
	typename InitVertsType,
	typename DistsType,
	typename MarkersType,
	typename HeapType
>
void id40(
	GraphType graph,
	InitVertsType v0,
	DistsType &dists,
	MarkersType &markers,
	HeapType &heap
)
{
	typedef typename GraphType::weight_type wt;	
	_fillit(graph.vertices(), markers, false);	
	_fillit(graph.vertices(), dists, id2<wt>());	
	xforeach(v0, i, heap.id30(i, get_zero<wt>()));
	while (heap.size() > 0)
	{
		typename HeapType::kv_pair_type v = heap.top();
		heap.pop();
		cmap<DistsType>::write(dists, v.key, v.value);
		cmap<MarkersType>::write(markers, v.key, true);
		xforeach(graph.v_edges(v.key), e,
			if (!cmap<MarkersType>::read(markers, e.v))
			{
				heap.id30(e.v, v.value + e.w);
			}
        )
	}
}

template<typename T, typename X>
struct _mapcreator
{
    typedef map<typename T::value_type, X> map_type;
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
    typedef X *map_type;
    static map_type create(Range<Ordinal> &t)
    {
        assert(t.a == 0);
        return new X[t.b];
    }
};

template<typename T, typename X, typename F>
struct _mapcreatori
{
	typedef _DummyType map_type;
	static map_type create(const T &t, F init_functor) { return map_type(); }
};

template<typename Ordinal, typename X, typename F>
struct _mapcreatori<Range<Ordinal>, X, F>
{
	typedef ArrWrapper<X*> map_type;
	static map_type create(const Range<Ordinal> &r, F f)
	{
		assert(r.a == 0);		
		X *&res = *(new X*);
		res = new X[r.b];
		for (Ordinal i = 0; i < r.b; i++) res[i] = f(i);
		return map_type(res, r.b);
	}
};





    typedef decltype(g) gtype; \
    id26(name
    _tmpx(name
    _mapcreator<gtype::v_set_type, int>::map_type name
        _mapcreator<gtype::v_set_type, int>::create(g.vertices()); \
    _fillit(g.vertices(), name
    auto name = id7(name




    typedef decltype(g) gtype; \
    auto name = _mapcreator<gtype::v_set_type, T>::create(g.vertices())

struct choose_rand
{
	const int n, k;
	choose_rand(int n, int k) : n(n), k(k) 
	{
		assert(k <= n);
		assert(n >= 0);
	}
    typedef int value_type;
	template <typename F>
	void process(F f) const
	{
		if (k == 0) return;
		int *a = new int[k];
		for (int i = 0; i < k; i++)
		{
			int t = _rand(n - i);
			int j;
			for (j = 0; j < i; j++)
				if (t >= a[j]) t++; else break;
			assert(t < n);
			for (int k = i-1; k >= j; k--)
				a[k+1] = a[k];
            a[j] = t;
		}
        for (int i = 0; i < k; i++)
            if (!f(a[i])) break;
		delete [] a;
	}
};

template<
	typename Support,
	typename Data,
	typename JoinF
>
struct id19
{
	typedef typename Support::value_type elem_type;
	typedef id19<Support, Data, JoinF> self_type;

	id13(T, Data, data, int, rank, elem_type, p);

	struct id20
	{
		id20(const Data &def_value) : def_value(def_value) {}
		T operator() (const elem_type &x) const
		{
			return T(def_value, 0, x);
		}
		Data def_value;
	};

	typedef _mapcreatori<Support, T, id20> creator_type;
	typedef typename creator_type::map_type map_type;

	map_type m;
	JoinF f;
	Data def_value;
	Support sup;

	inline elem_type get_id(const elem_type &x)
	{
		if (get_p(x) == x)
		{
			return x;
		}
		else
		{
			elem_type &tmp = get_p(x);
			return tmp = get_id(tmp);
		}
	}	

	inline void join(elem_type a, elem_type b)
	{
		a = get_id(a);
		b = get_id(b);
		if (a == b) return;
		int &ra = get_rank(a), &rb = get_rank(b);
		if (ra < rb)
		{
			get_p(a) = b;
			id32(b) = f(id32(b), id32(a));
		}
		else
		{
			if (ra == rb) ++ra;
			get_p(b) = a;
			id32(a) = f(id32(b), id32(a));
		}
	}
	
	inline bool same(const elem_type &a, const elem_type &b)
	{
		return get_id(a) == get_id(b);
	}

	Data& get_data(const elem_type &a)
	{
		return id32(get_id(a));
	}

	void isolate(const elem_type &a)
	{
		T &tmp = cmap<map_type>::read(m, a);
		elem_type new_parent = get_p(a);
		tmp.data = def_value;
		tmp.p = a;
		tmp.rank = 0;		
		xforeach(_keys<map_type>::get(m), i,
			if (i != a && this->get_p(i) == a)
			{
				if (new_parent == a) new_parent = i;
				this->get_p(i) = new_parent;
			}
		);
	}

	id19(const Support &sup, const Data &def_value, JoinF f) : def_value(def_value), f(f), sup(sup), m(creator_type::create(sup, id20(def_value)))
	{
	}
	
	struct Enumerator
	{
		typedef elem_type value_type;
		elem_type v;
		self_type &base;
		Enumerator(self_type &base, const elem_type &v) : base(base), v(v) {}
		template<typename F> 
		void process(F f) const
		{
			xforeach(_keys<map_type>::get(base.m), i, 
				if (base.get_id(i) == v)
					if (!f(i))
						xbreak;
			);
		}
	};

	inline Enumerator operator[] (const elem_type &x) { return Enumerator(*this, get_id(x)); }

private:
	inline int& get_rank(const elem_type &a) { return cmap<map_type>::read(m, a).rank; }
	inline elem_type& get_p(const elem_type &a) { return cmap<map_type>::read(m, a).p; }
	inline Data& id32(const elem_type &a) { return cmap<map_type>::read(m, a).data; }
};

template<typename Support, typename Data, typename JoinF>
id19<Support, Data, JoinF> create_disjoint_set(const Support &base, const Data &def_value, JoinF f)
{
	return id19<Support, Data, JoinF>(base, def_value, f);
}



	typedef decltype(def_value) T; \
	auto name = create_disjoint_set(base, def_value, [&](const T &_1, const T &_2) { return join_ftr; });

struct HexField
{
    int n;
    HexField(int n) : n(n) {}
    inline int corner(Idx2<int> p)
    {
        if (p.i == 1)
        {
            if (p.j == 1) return 1;
            if (p.j == n) return 6;
        }
        else if (p.i == n)
        {
            if (p.j == 1) return 2;
            if (p.j == 2*n-1) return 3;
        }
        else if (p.i == 2*n-1)
        {
            if (p.j == n) return 5;
            if (p.j == 2*n-1) return 4;
        }
        return 0;
    }    
    inline bool is_valid(Idx2<int> p)
    {
        if (p.i < 0 || p.i >= 2*n) return false;
        if (p.i <= n)
            return p.j > 0 && p.j < p.i + n;
        else
            return p.j > p.i - n && p.j < 2 * n;
    }    
    inline int edge(Idx2<int> p)
    {
        if (!is_valid(p)) return 0;
        if (p.i == 1) return 1;
        if (p.j - p.i == n - 1) return 2;
        if (p.j == 2 * n - 1) return 3;
        if (p.i == 2 * n - 1) return 4;
        if (p.i - p.j == n - 1) return 5;
        if (p.j == 1) return 6;
        return 0;
    }
    struct Neighbours
    {
        typedef Idx2<int> value_type;
        value_type p;
        Neighbours(const value_type &p) : p(p) {}
        template<typename F> inline
        void process(F f)
        {
            f(II(p.i - 1, p.j - 1));
            f(II(p.i - 1, p.j));
            f(II(p.i, p.j + 1));
            f(II(p.i + 1, p.j + 1));
            f(II(p.i + 1, p.j));
            f(II(p.i, p.j - 1));
        }
    };
    inline Neighbours nb(Idx2<int> p)
    {
        return Neighbours(p);
    }
};

template<typename T>
vector<typename ValueType<T>::type> _unique_circ(const T &a)
{    
    vector< typename ValueType<T>::type > res;
    xforeach(a, x, 
        if (res.empty() || !(res.back() == x)) res.push_back(x);
    );
    while (!res.empty() && res.back() == res.front()) res.pop_back();
    return res;
}

template<typename T>
bool _is_unique(const T &a)
{
    bool res = true;
    set< typename ValueType<T>::type > s;
    xforeach(a, x,
        if (_has(s, x)) { res = false; xbreak; }
        s.insert(x);
    );
    return res;
}

template<typename VerticesSetType, typename AdjListsType>
struct AdjListsGraph
{
	VerticesSetType &verts;
	AdjListsType &lists;

	AdjListsGraph(VerticesSetType &verts, AdjListsType &lists) : verts(verts), lists(lists) {}

	typedef typename item_type<AdjListsType>::type id3;
	typedef typename id3::value_type e_type;
	typedef typename VerticesSetType::value_type v_type;
	typedef VerticesSetType v_set_type;
	inline typename item_type<AdjListsType>::type& v_edges(v_type v)
		{ return cmap<AdjListsType>::read(lists, v); }
	inline v_set_type& vertices()
		{ return verts; }
};

template<typename VerticesSetType, typename AdjListsType>
struct AdjListsWGraph : public AdjListsGraph<VerticesSetType, AdjListsType>
{
	typedef typename AdjListsGraph<VerticesSetType, AdjListsType>::e_type::w_type weight_type;
	AdjListsWGraph(VerticesSetType &verts, AdjListsType &lists) : AdjListsGraph<VerticesSetType, AdjListsType>(verts, lists) {}
};

template<typename V, typename E> inline
AdjListsGraph<V, E> create_adj_lists_graph(V &verts, E &lists)
{
    return AdjListsGraph<V, E>(verts, lists);
}


    auto name
    auto name = create_adj_lists_graph(name

template<typename T>
struct div_op
{
	typedef double type;
	inline static type Do(const T &a, const T &b) { return double(a) / double(b); }
};

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
struct Frac
{
	T num, den;
	typedef typename div_op<T>::type value_type;
	Frac(const T &num, const T &den) : num(num), den(den) {}
	Frac(const T &num) : num(num), den(1) {}
	Frac() : num(0), den(1) {}
	inline value_type value() const { return div_op<T>::Do(num, den); }
	inline bool operator < (const Frac<T> &other) const
	{
		return mul_op<T>::Do(num, other.den) < mul_op<T>::Do(other.num, den);
	}
	inline bool operator <= (const Frac<T> &other) const
	{
		return mul_op<T>::Do(num, other.den) <= mul_op<T>::Do(other.num, den);
	}
	inline bool operator > (const Frac<T> &other) const
	{
		return mul_op<T>::Do(num, other.den) > mul_op<T>::Do(other.num, den);
	}
	inline bool operator >= (const Frac<T> &other) const
	{
		return mul_op<T>::Do(num, other.den) >= mul_op<T>::Do(other.num, den);
	}
	inline bool operator == (const Frac<T> &other) const
	{
		return mul_op<T>::Do(num, other.den) == mul_op<T>::Do(other.num, den);
	}
	inline void _write() const { _io<T>::write(num); _wstr("/"); _io<T>::write(den); }
	inline void _read(int i) { _io<T>::read(num, i); _io<T>::read(den, i); }
};

template<typename T>
inline Frac<T> linear_collide(T c1, T v1, T c2, T v2)
{
	return Frac<T>(c2 - c1, v1 - v2);
}

template<typename T>
inline Frac<T> linear_interpolate(T x1, T x2, T x, T y1, T y2)
{
    return Frac<T>(y1 * (x2 - x1) + (y2 - y1) * (x - x1), x2 - x1);
}

template<typename T>
inline Frac<T> const_acc_pos(T t, T acc, T v0 = T(0))
{
    return Frac<T>(acc * t * t + 2 * v0 * t, 2);
}

template<typename T>
inline typename mul_op<T>::type sqr(const T &a)
{
    return mul_op<T>::Do(a, a);
}

template<typename T1, typename T2>
inline double distance2d(const T1 &a, const T2 &b)
{
    return sqrt(sqr(a.x - b.x) + sqr(a.y - b.y));
}

template<typename T1, typename T2>
inline auto distance2dsq(const T1 &a, const T2 &b) -> typename mul_op<decltype(a.x)>::type
{
    return sqr(a.x - b.x) + sqr(a.y - b.y);
}

template<typename F>
inline double BS_FP(double l, double r, int iters, F f)
{
	for (int it_num = 0; it_num < iters; it_num++)
	{
		double m = (l + r) / 2;
		if (f(m)) r = m; else l = m;
	}
	return (l + r) / 2;
}


	BS_FP(l, r, iters, [&](double name) -> bool { __VA_ARGS__ })








void solve()
{
    id26(Pt, int, x, int, y);
    _in(Pt, a);
    _in(Pt, b);
    _in(int, n);
    id13(Bat, int, x, int, y, int, r);
    _inxw(Bat, bats, n);	

	swapord(a.x, b.x); swapord(a.y, b.y);
    auto g1 = _mapt(Pt, _rngs(a.x, b.x + 1), Pt(_, a.y));
    auto g2 = _mapt(Pt, _rngs(a.x, b.x + 1), Pt(_, b.y));
    auto g3 = _mapt(Pt, _rngs(a.y + 1, b.y), Pt(a.x, _));
    auto g4 = _mapt(Pt, _rngs(a.y + 1, b.y), Pt(b.x, _));
    auto g = g1 % g2 % g3 % g4;
    auto res = _count(g) - _count(_filterN(x, _any( distance2dsq(x, _) <= sqr(_.r), bats ), g));
	_w(res);
}

int main()
{

	freopen("test.in", "r", stdin);
	freopen("test.out", "w", stdout);

	solve();
	return 0;
}