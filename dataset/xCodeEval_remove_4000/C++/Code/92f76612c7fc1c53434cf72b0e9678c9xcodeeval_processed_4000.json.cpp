
                                                                       \
                                                                       \
void solve() {                                                         \
    $I(LL, n);                                                         \
    $I2(int, m, k);                                                    \
    $Ix(string, pairs, k);                                             \
    typedef SMI<1000000007> mint;                                      \
    $Txxi(mint, a, m, m, 1);                                           \
    FUN(f) (char c) { return _is_lower(c) ? c - 'a' : c - 'A' + 26; }; \
    xfor(pairs, p, a[f(p[0])][f(p[1])] = 0);                           \
    $Txi(mint, r0, m, 1);                                              \
    $Tx(mint, r1, m);                                                  \
    $Txx(mint, tmp, m, m);                                             \
    $Txx(mint, a1, m, m);                                              \
    _mat_pow(a, tmp, a1, n-1);                                         \
    _mat_multiply_row_by_mat(r0, a1, r1);                              \
    _w(_sum(r1).x);                                                    \
}                                                                      \
                                                                       \
_END_SOL                                                               \
                                                                       \






























using namespace std;

using namespace __gnu_cxx;


typedef long long LL;
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
inline void id1(const T &t, F f)
{
	_seq<const T>::template process<F>(t, f);
}

	{ \
	const auto &id3 = a; \
    id1(id3, [&](const gcc_typename ValueType<decltype(id3)>::type &v) -> bool {



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

	type name; \
	_io<type>::read(name, 0)


	type *name; \
	name = new type[sz]; \
	for (int __i = 0; __i < sz; __i++) _io<type>::read(name[__i], __i);

	type *name; \
	name = new type[sz];

	type **name; \
	name = new type*[sz1]; \
	for (int i = 0; i < sz1; i++) name[i] = new type[sz2];
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
void id2(const T &a, Sep sep)
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
    inline static void write(const map<T1, T2> &x) { _wstr("{"); id2(x, SepComma()); _wstr("}"); }
};
template<typename T1, typename T2>
struct _io<pair<T1, T2> >
{
    inline static void write(const pair<T1, T2> &x) { _w("("); _w(x.first); _w(", "); _w(x.second); _w(")"); }
};

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
	inline T operator () (const T &a, const T &b) const { return a + b; }
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

template<typename T, typename S>
inline T _ipow(T a, S k)
{
	assert(k >= 0);
	T res = 1;
	while (k > 0)
	{
		if (k % 2) res *= a;
		a *= a;
		k /= 2;
	}
	return res;
}
template<int M>
struct SMI
{
    int x;    
	SMI() : x(0) {}
    SMI(int val) { x = val % M; if (x < 0) x += M; }    
    inline SMI<M>& operator += (int arg) { x += arg; x %= M; if (x < 0) x += M; return *this; }
    inline SMI<M>& operator += (const SMI<M> &arg) { x += arg.x; if (x > M) x -= M; return *this; }
    inline SMI<M> operator + (int arg) const { SMI<M> res(*this); return res += arg; }
    inline SMI<M> operator + (const SMI<M> &arg) const { SMI<M> res(*this); return res += arg; }
    inline SMI<M>& operator -= (int arg) { return operator += (-arg); return *this; }
    inline SMI<M>& operator -= (const SMI<M> &arg) { x -= arg.x; if (x < 0) x += M; return *this; }
    inline SMI<M> operator - (int arg) const { SMI<M> res(*this); return res -= arg; }
    inline SMI<M> operator - (const SMI<M> &arg) const { SMI<M> res(*this); return res -= arg; }
    inline SMI<M>& operator *= (int arg) { x = (LL)x * arg % M; if (x < 0) x += M; return *this; }
    inline SMI<M>& operator *= (const SMI<M> &arg) { x = (LL)x * arg.x % M; return *this; }
    inline SMI<M> operator * (int arg) const { SMI<M> res(*this); return res *= arg; }
    inline SMI<M> operator * (const SMI<M> &arg) const { SMI<M> res(*this); return res *= arg; }
	inline SMI<M>& operator /= (int arg) { return operator /=(SMI<M>(arg)); }
    inline SMI<M>& operator /= (const SMI<M> &arg) { return operator *=(_ipow(arg, M-2)); }
    inline SMI<M> operator / (int arg) const { SMI<M> res(*this); return res /= arg; }
    inline SMI<M> operator / (const SMI<M> &arg) const { SMI<M> res(*this); return res /= arg; }
    inline operator int() const { return x; }
	inline void _write() const { _w(x); _wstr("(mod "); _w(M); _wstr(")"); }
};
template<int M> inline SMI<M> operator + (int arg1, const SMI<M> &arg2) { return arg2 + arg1; }
template<int M> inline SMI<M> operator * (int arg1, const SMI<M> &arg2) { return arg2 * arg1; }
template<int M> inline SMI<M> operator - (int arg1, const SMI<M> &arg2) { return arg2 - arg1; }
template<typename T>
void _mat_identity(T &m)
{
	int n = strictsize(m);
	_for(i, n) _for(j, n) m[i][j] = i == j ? 1 : 0;	
}
template<typename T1, typename T2, typename T3>
void _mat_multiply(const T1 &a, const T2 &b, T3 &res)
{
	int n = strictsize(a), p = strictsize(a[0]);
	int p2 = strictsize(b), m = strictsize(b[0]);
	assert(p == p2);
	assert(strictsize(res) == n);
	assert(strictsize(res[0]) == m);
	_for(i, n) _for(j, m)
	{
		typename T1::value_type tmp(0);
		_for(k, p) tmp = tmp + a[i][k] * b[k][j];
		res[i][j] = tmp;
	}
}
template<typename T1, typename T2>
void _mat_copy(const T1 &src, const T2 &dst)
{
	int n = strictsize(src);
	int m = strictsize(src[0]);
	assert(n == strictsize(dst));
	assert(m == strictsize(dst[0]));
	_for(i, n) _for(j, m) dst[i][j] = src[i][j];
}
template<typename T1, typename T2, typename T3, typename T4>
void _mat_pow(const T1 &a, T2 &tmp, T3 &res, T4 exp)
{
	assert(exp >= 0);
	_mat_identity(res);
	while (exp > 0)
	{
		if (exp % 2)
		{
			_mat_multiply(res, a, tmp);
			_mat_copy(tmp, res);
		}
		if (exp > 1)
		{
			_mat_multiply(a, a, tmp);
			_mat_copy(tmp, a);
		}
		exp /= 2;
	}
}
template<typename T1, typename T2, typename T3>
void _mat_multiply_row_by_mat(const T1 &row, const T2 &mat, T3 &res)
{
	int m = xlen(row);
	int n = strictsize(mat);
	int m2 = strictsize(mat[0]);
	assert(m == n);
	assert(m2 == xlen(res));
	_for(i, m2)
	{
		typename T3::value_type tmp = 0;
		_for(j, n) tmp = tmp + row[j] * mat[j][i];
		res[i] = tmp;
	}
}
template<typename T> struct StrictSize { static int size(const T &a) { return a.size(); } };
template<typename T> int strictsize(const T &a) { return StrictSize<T>::size(a); }
template<typename ArrType>
struct id0
{
	typedef ArrType base_type;
	ArrType &a;
	int n, m;
	id0(ArrType &a, int n, int m) : a(a), n(n), m(m) {}
	typedef typename strict_item_type<ArrType>::type sub_type;	
	typedef typename strict_item_type<sub_type>::type value_type;
	struct iterator
	{
		int i, j, m;
		iterator(int i, int j, int m): i(i), j(j), m(m) {}
		inline bool operator != (const iterator &other) const { return i != other.i || j != other.j; }
		inline iterator& operator ++ () { ++j; if (j == m) j = 0, ++i; return *this; }
	};
	inline iterator begin() const { return iterator(0, 0, m); }
	inline iterator end() const { return iterator(n, 0, m); }
	inline int size(int mx = numeric_limits<int>::max()) const { return n * m; }
	inline value_type& resolve_iterator(const iterator &it) const
	{
		return a[it.i][it.j];
	}
	inline ArrWrapper<sub_type> operator [](int i)
	{
		return ArrWrapper<sub_type>(a[i], m);
	}
	inline ArrWrapper<sub_type> operator [](int i) const
	{
		return ArrWrapper<sub_type>(a[i], m);
	}
    inline value_type& operator [](Idx2<int> idx)
    {
        return a[idx.i][idx.j];
    }
	template<typename F>
    void process(F f) const
    {
        _for(i, n) _for(j, m)
            if (!f(a[i][j])) break;
    }
	void _write() const
	{
		_w_("<");
		_for(i, n) _w_(operator [](i));
		_w(">");
	}	
};
template<typename T> struct StrictSize<id0<T> > { static int size(const id0<T> &a) { return a.n; } };
template<typename T>
struct strict_item_type< id0<T> > { typedef typename id0<T>::sub_type type; };
template<typename T>
struct cmap<id0<T> >
{
    typedef Idx2<int> key_type;
	typedef typename id0<T>::value_type V;
	inline static void write(id0<T> &a, key_type i, 
		const V value) { a.a[i.i][i.j] = value; }
	inline static V& read(id0<T> &a, key_type i) { return a.a[i.i][i.j]; }
};

	id0<decltype(base)> name(base, n, m)

	_tmpxx(type, name
	_wrap2(name, name

inline bool _is_lower(char c)
{
    return c >= 'a' && c <= 'z';
}






_SOLUTION