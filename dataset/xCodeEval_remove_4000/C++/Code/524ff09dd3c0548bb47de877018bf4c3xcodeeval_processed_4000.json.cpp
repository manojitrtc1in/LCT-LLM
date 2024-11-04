


























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
inline void id3(const T &t, F f)
{
	_seq<const T>::template process<F>(t, f);
}


    id3(a, [&](const gcc_typename ValueType<decltype(a)>::type &v) -> bool {


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



	id8(bname, t1, name1); \
	extend_fieldr(name, bname, t2, name2) \
		name(t1 name1, t2 name2) : bname(name1), name2(name2) {} \
		bool operator < (const name &other) const { \
			return cmp; \
		} \
	_end_extend


	id4(bname, t1, name1, t2, name2); \
	extend_fieldr(name, bname, t3, name3) \
		name(t1 name1, t2 name2, t3 name3) : bname(name1, name2), name3(name3) {} \
	_end_extend



template<typename T>
struct _keys
{
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

template<typename T, typename X, typename F>
struct _mapcreatori
{
	typedef _DummyType map_type;
	static map_type create(const T &t, F id2) { return map_type(); }
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
template<
	typename Support, 
	typename Data, 
	typename JoinF 
>
struct id5
{
	typedef typename Support::value_type elem_type;
	typedef id5<Support, Data, JoinF> self_type;
	id0(T, Data, data, int, rank, elem_type, p); 
	struct id6
	{
		id6(const Data &def_value) : def_value(def_value) {}
		T operator() (const elem_type &x) const
		{
			return T(def_value, 0, x);
		}
		Data def_value; 
	};
	typedef _mapcreatori<Support, T, id6> creator_type;
	typedef typename creator_type::map_type map_type;
	map_type m; 
	JoinF f; 
	Data def_value;
	Support sup;
	int id7;
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
		id7--;
		int &ra = get_rank(a), &rb = get_rank(b);
		if (ra < rb)
		{
			get_p(a) = b;
			get_data_raw(b) = f(get_data_raw(b), get_data_raw(a));
		}
		else
		{
			if (ra == rb) ++ra;
			get_p(b) = a;
			get_data_raw(a) = f(get_data_raw(b), get_data_raw(a));
		}
	}
	inline bool same(const elem_type &a, const elem_type &b)
	{
		return get_id(a) == get_id(b);
	}
	Data& get_data(const elem_type &a) 
	{
		return get_data_raw(get_id(a));
	}
	void isolate(const elem_type &a)
	{
		T &tmp = cmap<map_type>::read(m, a);
		elem_type new_parent = get_p(a);
		bool single = new_parent == a;
		tmp.data = def_value;
		tmp.p = a;
		tmp.rank = 0;		
		xforeach(_keys<map_type>::get(m), i,
			if (i != a && this->get_p(i) == a)
			{
				if (new_parent == a) new_parent = i;
				this->get_p(i) = new_parent;
				single = false;
			}
		);
		if (!single) id7++;
	}
	id5(const Support &sup, const Data &def_value, JoinF f) : def_value(def_value), f(f), sup(sup), m(creator_type::create(sup, id6(def_value)))
	{
		id7 = (int)sup.size();
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
	inline Data& get_data_raw(const elem_type &a) { return cmap<map_type>::read(m, a).data; }
};
template<typename Support, typename Data, typename JoinF>
id5<Support, Data, JoinF> id1(const Support &base, const Data &def_value, JoinF f)
{
	return id5<Support, Data, JoinF>(base, def_value, f);
}


	typedef decltype(def_value) T; \
	auto name = id1(base, def_value, [&](const T &_1, const T &_2) { return join_ftr; });

id4(int_xy, int, x, int, y);












void solve()
{
	_inxwn(int_xy, a, n);
	dset0(ds, _rng(n));
	_for(i, n) _for(j, i) if (a[i].x == a[j].x || a[i].y == a[j].y) ds.join(i, j);
	_w(ds.id7 - 1);
}
_END_SOL
