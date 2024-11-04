
                                                                                    \
                                                                                    \
void solve() {                                                                      \
    $Ixn(int, a, n);                                                                \
    if (n == 1) { _w(-1); return; }                                                 \
    $$ t = id12(a);                                                         \
    $$ indices = LI2(0, 1) %lcat _fold_sum(_map(t, _.s));                           \
    $$ i3 = _take(4, _filter(_ < n, indices));                                      \
    $$ pairs = _filter(_.f < _.s, _cartprod(i3, i3));                               \
                                                                                    \
    xfor(pairs, p, if (a[p.f] != a[p.s]) {                                          \
        swap(a[p.f], a[p.s]);                                                       \
        if (!_is_sorted(a) && !_is_sorted(_rev(a))) { _w2(p.f+1, p.s+1); exit(0); } \
        swap(a[p.f], a[p.s]);                                                       \
    });                                                                             \
    _w(-1);                                                                         \
}                                                                                   \
                                                                                    \
_END_SOL                                                                            \
                                                                                    \






























using namespace std;

using namespace __gnu_cxx;








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
inline void id13(const T &t, F f)
{
	_seq<const T>::template process<F>(t, f);
}


	{ \
	const auto &id18 = a; \
    id13(id18, [&](const gcc_typename ValueType<decltype(id18)>::type &v) -> bool {



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
	inline static void write(const bool &b) { printf("%s", b ? "
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
struct id9
{
	SEQ_TYPE(T) base;
    id9(const T &base) : base(base) {}
    typedef T value_type;
    template<typename F>
    inline void process(F f) const { f(base); }
	inline int size(int mx = numeric_limits<int>::max()) const { return 1; }
    inline T operator [] (int idx) const { assert(idx == 0); return base; }
};
template<typename T>
inline id9<T> IW(const T &x) { return id9<T>(x); }

	type name; \
	_io<type>::read(name, 0)

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
void id4(const T &a, Sep sep)
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
    inline static void write(const map<T1, T2> &x) { _wstr("{"); id4(x, SepComma()); _wstr("}"); }
};
template<typename T1, typename T2>
struct _io<pair<T1, T2> >
{
    inline static void write(const pair<T1, T2> &x) { _w("("); _w(x.first); _w(", "); _w(x.second); _w(")"); }
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
		inline bool operator == (const name &other) const { \
			return base::operator == (*(const base*)&other) && field_name == other.field_name; \
		}




	extend_fieldr(name, tup0, t1, name1) \
		name(t1 name1) : name1(name1) {} \
		_CMP_(name, cmp) \
	_end_extend



	id15(bname, t1, name1); \
	extend_fieldr(name, bname, t2, name2) \
		name(t1 name1, t2 name2) : bname(name1), name2(name2) {} \
		_CMP_(name, cmp) \
	_end_extend



	id14(bname, t1, name1, t2, name2); \
	extend_fieldr(name, bname, t3, name3) \
		name(t1 name1, t2 name2, t3 name3) : bname(name1, name2), name3(name3) {} \
		_CMP_(name, cmp) \
	_end_extend

template<typename T>
struct SumFtr
{
	typedef T res_type;
	inline T operator () (const T &a, const T &b) const { return a + b; }
};

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
struct RevWrapper
{
    T &a;
    int n;
    typedef typename strict_item_type<T>::type value_type;
    RevWrapper(T &a) : a(a) { n = a.size(); }
    inline int size(int mx = numeric_limits<int>::max()) const { return n; }
	inline value_type& operator [] (int i) { return a[n-i-1]; }
	template<typename F>
    void process(F f) const { for (int i = n-1; i >= 0; i--) if (!f(a[i])) return; }
	ITER_WRITE
};
template<typename T> inline
	RevWrapper<T> _rev(T &a) { return RevWrapper<T>(a); }
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
	id6(_iterator, base_iterator, it, S, val, const my_type&, owner);
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
FoldWrapper<T, S, F> id11(const T &a, const S &init_val, F f)
{
    return FoldWrapper<T, S, F>(a, init_val, f);
}
template<typename T> inline
FoldWrapper<T, typename T::value_type, SumFtr<typename T::value_type> > _fold_sum(const T &a)
{
    return id11(a, typename T::value_type(0), SumFtr<typename T::value_type>());
}
template<typename T1, typename T2>
struct _pair
{
    id7(type, T1, f, T2, s, cmp_aa(f, s));
};






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
	S operator [] (int i) const { return f(a[i]); }
	ITER_WRITE
};
template<typename A, typename B, typename C> struct _IsIterable<MapWrapper<A, B, C> > { enum { value = 1 }; };





template<typename T, typename F>
auto id10(const T &a, F f) -> MapWrapper<T, F, zzz>
{
	return MapWrapper<T, F, zzz>(a, f);
}


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
inline FilterWrapper<T, Filter> id2(const T &t, Filter f)
{
	return FilterWrapper<T, Filter>(t, f);
}

	id2(a, [&](const gcc_typename ValueType<decltype(a)>::type &_) -> bool { return cond; })
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
struct
{
    template<typename T> struct Sig
	{
        typedef typename T::value_type ret_type;
    };
    template<typename T>
    typename T::value_type operator() (const T &a) const
    {
	    typename T::value_type res;
	    bool ok = false;
	    xfor(a, x, res = x; ok = true; xbreak);
	    assert(ok);
	    return res;
    }
} _head;
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
    inline int size(int mx = numeric_limits<int>::max()) const 
	{ 
		int id3 = mx + cnt;
		if (id3 < 0) id3 = numeric_limits<int>::max(); 
		return max(0, a.size(id3) - cnt);
	}
    typedef _DummyType iterator;
	ITER_WRITE
};
struct
{
    template<typename F, typename T> struct Sig2
	{
        typedef DropWrapper<T> ret_type;
    };
    template<typename F, typename T>
    inline DropWrapper<T> operator() (F cnt, const T &a) const
    {
        return DropWrapper<T>(cnt, a);
    }
} _drop;
template<typename S1, typename S2>
struct id17
{
    SEQ_TYPE(S1) s1;
    SEQ_TYPE(S2) s2;
    id17(const S1 &s1, const S2 &s2) : s1(s1), s2(s2) {}
    typedef typename S1::value_type s1_type;
    typedef typename S2::value_type s2_type;
    typedef _DummyType iterator; 
    typedef typename _pair<s1_type, s2_type>::type value_type;    
    template<typename F>
    inline void process(F f) const
    {
        typedef value_type f_type; 
        auto const &id8 = s1; 
        auto const &id5 = s2; 
        xforeach(id8, a,
            typedef f_type f_type2; 
            auto const &id0 = id5; 
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
    inline int size(int mx = numeric_limits<int>::max()) const { return s1.size(mx) * s2.size(mx); }
	ITER_WRITE
};
template<typename S1, typename S2>
id17<S1, S2> _cartprod(const S1 &s1, const S2 &s2)
{
    return id17<S1, S2>(s1, s2);
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
struct id16
{
	const T &a;
	id16(const T &a) : a(a) {}
	template<typename T2> inline
		ConcatLists<T, T2> operator % (const T2 &b) const { return ConcatLists<T, T2>(a, b); }
};
struct _lcat {};
template<typename T> inline
	id16<T> operator % (const T &a, _lcat) { return id16<T>(a); }

template<typename T>
inline int _count(const T &a)
{
    int res = 0;
    xforeach(a, i, ++res);
    return res;
}
template<typename T>
struct id1
{
	SEQ_TYPE(T) a;
	typedef typename _pair<typename T::value_type, int>::type value_type;
	id1(const T &a) : a(a) {}
	template<typename F>
	inline void process(F f) const
	{
		int k = 0;
		bool stop = false;
		typedef value_type VT;
		typename T::value_type cur;
		xforeach(a, x,
			if (k == 0) cur = x;
			else if (!(cur == x))			
			{
				if (!f(VT(cur, k))) { stop = true; xbreak; }
				cur = x;
				k = 0;
			}
			++k;
		);
		if (!stop && k > 0) f(value_type(cur, k));
	}
    ITER_SIZE
    typedef _DummyType iterator;
	ITER_WRITE
};
template<typename T>
id1<T> id12(const T &a)
{
	return id1<T>(a);
}

template<typename T> bool _is_sorted(const T &a)
{    
    $$ prev = _head(a);
    bool res = true;
    xfor(_drop(1, a), cur,
        if (cur < prev) { res = false; xbreak; }
        prev = cur
    );
    return res;
}






_SOLUTION
