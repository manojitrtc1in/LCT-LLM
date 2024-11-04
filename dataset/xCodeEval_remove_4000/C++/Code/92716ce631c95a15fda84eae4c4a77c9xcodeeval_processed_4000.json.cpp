
                                                          \
                                                          \
void solve() {                                            \
    LL res = 0, heavy = 0;                                \
    $I(string, s);                                        \
    string h = "heavy", m = "metal";                      \
    _for(i, xlen(s))                                      \
    {                                                     \
        if (h %sequal _slice(s, i, 5)) heavy++;           \
        else if (m %sequal _slice(s, i, 5)) res += heavy; \
    }                                                     \
    _w(res);                                              \
}                                                         \
                                                          \
_END_SOL                                                  \
                                                          \






























using namespace std;


using namespace stdext;



using namespace __gnu_cxx;









typedef long long LL;
struct _DummyType {};
template<typename T>
struct ValueType {
    typedef typename remove_reference<T>::type clean_type1;
	typedef typename remove_const<clean_type1>::type clean_type;
	typedef typename clean_type::value_type type;
};
template<typename T>
struct _CleanType {
	typedef typename remove_const<T>::type __type;
    typedef typename remove_reference<__type>::type _type;
    typedef typename remove_const<_type>::type type;
};
template<typename T>
struct _IsIterable { enum { value = 0 }; };




template<typename T>
struct strict_item_type { typedef typename ValueType<T>::type type; };
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
template<typename IterableType>
struct citerator
{
	typedef typename IterableType::value_type value_type;
	static inline value_type resolve(const IterableType &a, typename IterableType::iterator it)
		{ return a.resolve_iterator(it); }
	static inline value_type& xresolve(IterableType &a, typename IterableType::iterator it)
		{ return a.resolve_iterator(it); }
	static void advance(const IterableType &a, typename IterableType::iterator &it)
		{ a.advance_iterator(it); }
};
template <typename T, typename I>
inline void adv_it(const T &a, I &it) { citerator<T>::advance(a, it); }
template<typename T>
struct citerator<vector<T> >
{
	static inline const T& resolve(const vector<T> &a, typename vector<T>::const_iterator it)
		{ return *it; }
	static void advance(const vector<T> &a, typename vector<T>::const_iterator &it)
		{ ++it; }
};
template<typename T> struct _IsIterable<vector<T> > { enum { value = 1 }; };
template<>
struct citerator<string>
{
	static inline char resolve(const string &a, gcc_typename string::const_iterator it)
		{ return *it; }
	static void advance(const string &a, gcc_typename string::const_iterator &it)
		{ ++it; }
};
template<> struct _IsIterable<string> { enum { value = 1 }; };
template<typename T>
struct citerator<set<T> >
{
	static inline const T& resolve(const set<T> &a, typename set<T>::const_iterator it)
		{ return *it; }
	static void advance(const set<T> &a, typename set<T>::const_iterator &it)
		{ ++it; }
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
inline void id3(const T &t, F f)
{
	_seq<const T>::template process<F>(t, f);
}


	{ \
	const auto &id7 = a; \
    id3(id7, [&](const gcc_typename ValueType<decltype(id7)>::type &v) -> bool {


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
template<typename T1, typename T2>
struct _io<map<T1, T2> >
{
    inline static void write(const map<T1, T2> &x) { _wstr("{"); id6(x, SepComma()); _wstr("}"); }
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


	id9(bname, t1, name1); \
	extend_fieldr(name, bname, t2, name2) \
		name(t1 name1, t2 name2) : bname(name1), name2(name2) {} \
		_CMP_(name, cmp) \
	_end_extend

	const auto &name
	vector<gcc_typename ValueType<decltype(name
	populate(name, name


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
template<typename T>
struct SliceWrapper
{
    T a;
	typedef typename _CleanType<T>::type T2;
    int p0, n;
    typedef typename strict_item_type<T2>::type value_type;
    SliceWrapper(T a, int p0, int n) : a(a), p0(p0), n(n) { n = min(n, xlen(a) - p0); }
    inline int size(int mx = numeric_limits<int>::max()) const { return n; }	
	inline value_type operator [] (int i) const { return a[i+p0]; }
	template<typename F>
    void process(F f) const { _for(i, n) if (!f(a[i+p0])) return; }
	ITER_WRITE
};
template<typename T> inline
	SliceWrapper<T> _slice(T &&a, int p0, int k) { return SliceWrapper<T>(a, p0, k); }
template<typename T1, typename T2>
struct _pair
{
    id1(type, T1, f, T2, s, cmp_aa(f, s));
};
template<
    typename T 
>
struct TakeWrapper
{
	W_TYPE(T, a);
    int cnt;
    TakeWrapper(int cnt, T a) : cnt(cnt), a(a) { assert(cnt >= 0); }
    typedef typename T2::value_type value_type;
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
inline TakeWrapper<T> _take(int cnt, T &&a)
{
    return TakeWrapper<T>(cnt, a);
}
template<
    typename T, 
    typename F 
>
struct id4
{
	W_TYPE(T, a);
    F f;
    id4(F f, T a) : a(a), f(f) {}
    typedef typename T2::value_type value_type;
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
id4<T, F> id5(F f, T &&a)
{
    return id4<T, F>(f, a);
}

    id5([&](const gcc_typename ValueType<decltype(a)>::type &_) -> bool { return f; }, a)
template<typename T1, typename T2>
struct ZipWrapper
{
	W_TYPE(T1, a);
	W_TYPE(T2, b);
    typedef typename _pair<typename T12::value_type, typename T22::value_type>::type value_type;
    typedef _DummyType iterator;
    ZipWrapper(T1 a, T2 b) : a(a), b(b) {}
    template<typename F>
    void process(F f) const
    {
		static_assert(_IsIterable<T12>::value == 1, "ZipWrapper: T1 must be iterable");
        auto it = a.begin();
        typedef value_type f_type; 
        xforeach(b, x,
            if (it == a.end()) xbreak;
            if (!f(f_type(citerator<typename _CleanType<T1>::type>::resolve(a, it), x))) xbreak;
            adv_it(a, it);
        );
    }
	value_type operator [] (int i) const { return value_type(a[i], b[i]); }
    ITER_SIZE
	ITER_WRITE
};
template<typename T1, typename T2>
ZipWrapper<T1, T2> _zip(T1 &&a, T2 &&b) 
{
    return ZipWrapper<T1, T2>(a, b);
}
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
template<typename T1, typename T2>
int id8(const T1 &a, const T2 &b)
{
	return _takewhile(_.f == _.s, _zip(a, b)).size();
}
template<typename T>
struct TrivialEnsurer
{
	T operator () (T a) const { return a; }
};
template<typename T>
struct VectorEnsurer
{
	typedef typename ValueType<T>::type S;
	vector<S> operator () (T a) const { seqvec(v, a); return v; }
};
template<typename T>
struct _EnsuredIterable
{
	typedef typename _CleanType<T>::type TC;
	typedef typename ValueType<TC>::type VT;
	typedef typename conditional<_IsIterable<TC>::value, T, vector<VT> >::type type;
	typedef typename conditional<_IsIterable<TC>::value, TrivialEnsurer<T>, VectorEnsurer<T> >::type ensurer;
};
template<typename T>
typename _EnsuredIterable<T>::type id0(T &&a)
{
	return typename _EnsuredIterable<T>::ensurer()(a);
}
template<typename T1, typename T2>
bool _seqeq(const T1 &a, const T2 &b)
{
	int n1 = a.size(), n2 = b.size();
	if (n1 != n2) return false;
	$$ a_ = id0(a);
	return id8(a_, b) == n1;
}
template<typename T>
struct id2
{
	const T a;
	id2(T a) : a(a) {}
	template<typename T2> inline
		bool operator % (const T2 &b) const { return _seqeq(a, b); }
};
struct _sequal {};
template<typename T> inline
	id2<T> operator % (T &&a, _sequal) { return id2<T>(a); }







_SOLUTION
