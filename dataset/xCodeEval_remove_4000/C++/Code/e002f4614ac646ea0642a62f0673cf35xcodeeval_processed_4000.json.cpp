
                                                                                                 \
                                                                                                 \
void solve() {                                                                                   \
    $I(int, n);                                                                                  \
    $Ix(int_uv, edges, n-1);                                                                     \
    $Tx(vector<int_vw>, e, n);                                                                   \
    xfor(edges, x, e[x.u-1].push_back(int_vw(x.v-1, 1)); e[x.v-1].push_back(int_vw(x.u-1, -1))); \
    GraphALW(g, e, n);                                                                           \
    int w = 0;                                                                                   \
    typedef decltype(g) GraphType;                                                               \
    id9(int, g, f);                                                                    \
    $Tx(int, a, n);                                                                              \
    id8(g, IW(0), V0, V0, V0, E_(if (e.w < 0) ++w), E0, E0, f);                           \
                                                                                                 \
    id8(g, IW(0), V0, V_(a[v] = w), V0, E_(w += e.w), E_(w -= e.w), E0, f);               \
                                                                                                 \
    $$ res = _min(a);                                                                            \
    _w_(res);                                                                                    \
    _wi(_filter(a[_-1] == res, _seg(1, n)));                                                     \
}                                                                                                \
                                                                                                 \
_END_SOL                                                                                         \
                                                                                                 \






























using namespace std;

using namespace __gnu_cxx;








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
	inline int size() const { return b < a ? 0 : b - a; }
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
struct id4
{
	SEQ_TYPE(T) base;
    id4(const T &base) : base(base) {}
    typedef T value_type;
    template<typename F>
    inline void process(F f) const { f(base); }
	inline int size() const { return 1; }
};
template<typename T>
inline id4<T> IW(const T &x) { return id4<T>(x); }

	type name; \
	_io<type>::read(name, 0)

	type *name; \
	name = new type[sz]; \
	for (int __i = 0; __i < sz; __i++) _io<type>::read(name[__i], __i);

	type *name; \
	name = new type[sz];
template<typename I, typename M>
inline void _fillit(const I &keys, M &m, const typename item_type<M>::type &val)
{
	xforeach(keys, i, cmap<M>::write(m, i, val));
}
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
void id1(const T &a, Sep sep)
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



	id7(bname, t1, name1); \
	extend_fieldr(name, bname, t2, name2) \
		name(t1 name1, t2 name2) : bname(name1), name2(name2) {} \
		_CMP_(name, cmp) \
	_end_extend
template<typename T, typename F> 
typename T::value_type Fold(const T &a, F f, const typename T::value_type &init_val)
{
	typename T::value_type res = init_val;
	xforeach(a, i, res = f(res, i));
	return res;
}
template<typename T>
struct MinFtr
{
	typedef T res_type;
	inline T operator () (const T &a, const T &b) const { return min(a, b); }
};
template<typename T>
typename T::value_type _min(const T &a)
{
    typedef typename T::value_type X;
    return Fold(a, MinFtr<X>(), numeric_limits<X>::max());
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

	ArrWrapper<decltype(base)> name(base, n)

	_inx(type, name
	_wrap(name, name

	_tmpx(type, name
	_wrap(name, name
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

	id0(a, [&](const ValueType<decltype(a)>::type &_) -> bool { return cond; })
template<typename T>
inline int _count(const T &a)
{
    int res = 0;
    xforeach(a, i, ++res);
    return res;
}
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
	BeforeTraverseFunctor id10;
	AfterTraverseFunctor id12;
	BackEdgeFunctor back_edge;
	MarkersType &markers;
	typedef typename GraphType::v_type V;
	Dfs(
		GraphType &g, 
		const VertOrderType &order, 
		NewTreeFunctor new_tree, 
		EnterVertexFunctor enter_vertex, 
		LeaveVertexFunctor leave_vertex, 
		BeforeTraverseFunctor id10, 
		AfterTraverseFunctor id12, 
		BackEdgeFunctor back_edge, 
		MarkersType &markers 
	) : g(g), order(order), new_tree(new_tree), enter_vertex(enter_vertex), leave_vertex(leave_vertex),
		id10(id10), id12(id12), back_edge(back_edge),
		markers(markers) {}
	void Do()
	{
		id3(order, i)
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
		id3(g.v_edges(v), e)
		{						
			if (cmap<MarkersType>::read(markers, e.v) == 0)
			{
				if (id10(v, e))
				{
					this->DfsRec(e.v, v);
					id12(v, e);
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
inline void id8(
	GraphType &g,
	const VertOrderType &order, 
	NewTreeFunctor new_tree,
	EnterVertexFunctor enter_vertex, 
	LeaveVertexFunctor leave_vertex, 
	BeforeTraverseFunctor id10,
	AfterTraverseFunctor id12,
	BackEdgeFunctor back_edge,
	MarkersType &markers
	)
{
	_fillit(g.vertices(), markers, 0);
	Dfs<GraphType, VertOrderType, NewTreeFunctor, EnterVertexFunctor, 
		LeaveVertexFunctor, BeforeTraverseFunctor, AfterTraverseFunctor, 
		BackEdgeFunctor, MarkersType>
		X(g, order, new_tree, enter_vertex, leave_vertex, id10, id12, back_edge, markers);
	X.Do();
}
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
    static map_type create(const Range<Ordinal> &t)
    {
        assert(t.a == 0);
        return new X[t.b];
    }
};


    typedef gcc_typename _CleanType<decltype(g)>::type gtype;  \
    auto name = _mapcreator<gcc_typename gtype::v_set_type, T>::create(g.vertices())
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
template<typename VerticesSetType, typename AdjListsType>
struct id11
{
	VerticesSetType &verts; 
	AdjListsType &lists; 
	id11(VerticesSetType &verts, AdjListsType &lists) : verts(verts), lists(lists) {}
	typedef typename item_type<AdjListsType>::type edge_list_type;
	typedef typename edge_list_type::value_type e_type;
	typedef typename VerticesSetType::value_type v_type;
	typedef VerticesSetType v_set_type;
	inline const typename item_type<AdjListsType>::type& v_edges(v_type v) const
		{ return cmap<AdjListsType>::read(lists, v); }
	inline const v_set_type& vertices() const
		{ return verts; }
};
template<typename VerticesSetType, typename AdjListsType>
struct id2 : public id11<VerticesSetType, AdjListsType>
{
	typedef typename id11<VerticesSetType, AdjListsType>::e_type::w_type weight_type;
	id2(VerticesSetType &verts, AdjListsType &lists) : id11<VerticesSetType, AdjListsType>(verts, lists) {}
};
id6(int_uv, int, u, int, v);
id6(int_vw, int, v, int, w);

	Range<int> name_verts(0, n); \
	id2<Range<int>, decltype(lists)> name(name_verts, lists)






_SOLUTION
