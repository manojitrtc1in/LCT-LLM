





















using std::ios;
using std::cin;
using std::cout;
using std::cerr;
using std::endl;

using std::istream;
using std::ostream;
using std::ifstream;
using std::ofstream;

using std::pair;
using std::string;
using std::bitset;
using std::valarray;
using std::make_pair;

using std::array;
using std::vector;
using std::deque;
using std::forward_list;
using std::list;
using std::stack;
using std::queue;
using std::priority_queue;
using std::set;
using std::multiset;
using std::unordered_set;
using std::map;
using std::multimap;
using std::unordered_map;

using std::function;
using std::initializer_list;

using std::all_of;
using std::any_of;
using std::none_of;
using std::for_each;
using std::find_if;
using std::find_if_not;
using std::find_end;
using std::find_first_of;
using std::adjacent_find;
using std::count_if;
using std::mismatch;
using std::is_permutation;
using std::search_n;
using std::copy_n;
using std::copy_if;
using std::copy_backward;
using std::move_backward;
using std::swap;
using std::swap_ranges;
using std::iter_swap;
using std::replace_if;
using std::replace_copy;
using std::replace_copy_if;
using std::fill;
using std::fill_n;
using std::generate_n;
using std::remove_if;
using std::remove_copy;
using std::remove_copy_if;
using std::unique;
using std::unique_copy;
using std::reverse;
using std::reverse_copy;
using std::rotate_copy;
using std::random_shuffle;
using std::is_partitioned;
using std::partition;
using std::stable_partition;
using std::partition_copy;
using std::partition_point;
using std::sort;
using std::stable_sort;
using std::partial_sort;
using std::partial_sort_copy;
using std::is_sorted;
using std::is_sorted_until;
using std::nth_element;
using std::lower_bound;
using std::upper_bound;
using std::equal_range;
using std::binary_search;
using std::inplace_merge;
using std::set_union;
using std::set_intersection;
using std::set_difference;
using std::set_symmetric_difference;
using std::min;
using std::max;
using std::minmax;
using std::min_element;
using std::max_element;
using std::minmax_element;
using std::lexicographical_compare;
using std::next_permutation;
using std::prev_permutation;

using std::accumulate;
using std::adjacent_difference;
using std::inner_product;
using std::partial_sum;
using std::iota;































template<typename T> T& chkmin(T& a, const T& b){    return a>b ? a=b : a;    }
template<typename T> T& chkmax(T& a, const T& b){    return a<b ? a=b : a;    }
template<typename T> T& toabs (T& x){    return x=abs(x);    }
template<typename T> bool id6(const T& a, const T& b){    return a<b;    }
template<typename T> bool id16(const T& a, const T& b){    return b<a;    }
template<typename T> T SQ(const T& x){ return x*x; }

template<typename T1, typename T2, typename T3>
struct tripple
{
	T1 x; T2 y; T3 z;

	constexpr tripple() = default;
	constexpr tripple(const T1 &_x, const T2 &_y, const T3 &_z)
		:x(_x), y(_y), z(_z){}
	constexpr tripple(const tripple<T1, T2, T3> &_t)
		:x(_t.x), y(_t.y), z(_t.z){}
	template<typename U1, typename U2, typename U3>
		constexpr tripple(const tripple<U1, U2, U3> &_t)
			:x(_t.x), y(_t.y), z(_t.z){}
	
	tripple& operator=(const tripple<T1, T2, T3> &_t)
	{
		x=_t.x; y=_t.y; z=_t.z;
		return *this;
	}
	template<typename U1, typename U2, typename U3>
		tripple& operator=(const tripple<U1, U2, U3> &_t)
		{
			x=_t.x; y=_t.y; z=_t.z;
			return *this;
		}

	template<typename U1, typename U2, typename U3>
		tripple operator+(const tripple<U1, U2, U3> &_t)
		{
			return tripple<T1, T2, T3>(x+_t.x, y+_t.y, z+_t.z);
		}

	template<typename U1, typename U2, typename U3>
		tripple operator-(const tripple<U1, U2, U3> &_t)
		{
			return tripple<T1, T2, T3>(x-_t.x, y-_t.y, z-_t.z);
		}

	template<typename U1, typename U2, typename U3>
		tripple operator*(const tripple<U1, U2, U3> &_t)
		{
			return tripple<T1, T2, T3>(x*_t.x, y*_t.y, z*_t.z);
		}

	template<typename U1, typename U2, typename U3>
		tripple operator/(const tripple<U1, U2, U3> &_t)
		{
			return tripple<T1, T2, T3>(x/_t.x, y/_t.y, z/_t.z);
		}

	template<typename U1, typename U2, typename U3>
		tripple operator%(const tripple<U1, U2, U3> &_t)
		{
			return tripple<T1, T2, T3>(x%_t.x, y%_t.y, z%_t.z);
		}

	template<typename U1, typename U2, typename U3>
		tripple operator&(const tripple<U1, U2, U3> &_t)
		{
			return tripple<T1, T2, T3>(x&_t.x, y&_t.y, z&_t.z);
		}

	template<typename U1, typename U2, typename U3>
		tripple operator|(const tripple<U1, U2, U3> &_t)
		{
			return tripple<T1, T2, T3>(x|_t.x, y|_t.y, z|_t.z);
		}

	template<typename U1, typename U2, typename U3>
		tripple operator^(const tripple<U1, U2, U3> &_t)
		{
			return tripple<T1, T2, T3>(x^_t.x, y^_t.y, z^_t.z);
		}

	template<typename U>
		tripple operator+(const U &o)
		{
			return tripple<T1, T2, T3>(x+o, y+o, z+o);
		}

	template<typename U>
		tripple operator-(const U &o)
		{
			return tripple<T1, T2, T3>(x-o, y-o, z-o);
		}
	
	template<typename U>
		tripple operator*(const U &o)
		{
			return tripple<T1, T2, T3>(x*o, y*o, z*o);
		}
	
	template<typename U>
		tripple operator/(const U &o)
		{
			return tripple<T1, T2, T3>(x/o, y/o, z/o);
		}

	template<typename U>
		tripple operator%(const U &o)
		{
			return tripple<T1, T2, T3>(x%o, y%o, z%o);
		}

	template<typename U>
		tripple operator&(const U &o)
		{
			return tripple<T1, T2, T3>(x&o, y&o, z&o);
		}
	
	template<typename U>
		tripple operator|(const U &o)
		{
			return tripple<T1, T2, T3>(x|o, y|o, z|o);
		}
	
	template<typename U>
		tripple operator^(const U &o)
		{
			return tripple<T1, T2, T3>(x^o, y^o, z^o);
		}

	tripple operator~()
	{
		return tripple<T1, T2, T3>(~x, ~y, ~z);
	}

	tripple operator+()
	{
		return *this;
	}

	tripple operator-()
	{
		return tripple<T1, T2, T3>(-x, -y, -z);
	}

	tripple& operator++()
	{
		++x; ++y; ++z;
		return *this;
	}

	tripple& operator--()
	{
		--x; --y; --z;
		return *this;
	}

	tripple operator++(int)
	{
		return tripple<T1, T2, T3>(x++, y++, z++);
	}

	tripple operator--(int)
	{
		return tripple<T1, T2, T3>(x--, y--, z--);
	}

	template<typename U1, typename U2, typename U3>
		tripple& operator+=(const tripple<U1, U2, U3> &_t)
		{
			x+=_t.x; y+=_t.y; z+=_t.z;
			return *this;
		}

	template<typename U1, typename U2, typename U3>
		tripple& operator-=(const tripple<U1, U2, U3> &_t)
		{
			x-=_t.x; y-=_t.y; z-=_t.z;
			return *this;
		}

	template<typename U1, typename U2, typename U3>
		tripple& operator*=(const tripple<U1, U2, U3> &_t)
		{
			x*=_t.x; y*=_t.y; z*=_t.z;
			return *this;
		}

	template<typename U1, typename U2, typename U3>
		tripple& operator/=(const tripple<U1, U2, U3> &_t)
		{
			x/=_t.x; y/=_t.y; z/=_t.z;
			return *this;
		}

	template<typename U1, typename U2, typename U3>
		tripple& operator%=(const tripple<U1, U2, U3> &_t)
		{
			x%=_t.x; y%=_t.y; z%=_t.z;
			return *this;
		}

	template<typename U1, typename U2, typename U3>
		tripple& operator&=(const tripple<U1, U2, U3> &_t)
		{
			x&=_t.x; y&=_t.y; z&=_t.z;
			return *this;
		}

	template<typename U1, typename U2, typename U3>
		tripple& operator|=(const tripple<U1, U2, U3> &_t)
		{
			x|=_t.x; y|=_t.y; z|=_t.z;
			return *this;
		}

	template<typename U1, typename U2, typename U3>
		tripple& operator^=(const tripple<U1, U2, U3> &_t)
		{
			x^=_t.x; y^=_t.y; z^=_t.z;
			return *this;
		}

	template<typename U>
		tripple& operator+=(const U &o)
		{
			x+=o; y+=o; z+=o;
			return *this;
		}

	template<typename U>
		tripple& operator-=(const U &o)
		{
			x-=o; y-=o; z-=o;
			return *this;
		}
	
	template<typename U>
		tripple& operator*=(const U &o)
		{
			x*=o; y*=o; z*=o;
			return *this;
		}
	
	template<typename U>
		tripple& operator/=(const U &o)
		{
			x/=o; y/=o; z/=o;
			return *this;
		}
	
	template<typename U>
		tripple& operator%=(const U &o)
		{
			x%=o; y%=o; z%=o;
			return *this;
		}
	
	template<typename U>
		tripple& operator&=(const U &o)
		{
			x&=o; y&=o; z&=o;
			return *this;
		}

	template<typename U>
		tripple& operator|=(const U &o)
		{
			x|=o; y|=o; z|=o;
			return *this;
		}
	
	template<typename U>
		tripple& operator^=(const U &o)
		{
			x^=o; y^=o; z^=o;
			return *this;
		}

	template<typename U>
		tripple operator<<(const U &o)
		{
			return tripple<T1, T2, T3>(x<<o, y<<o, z<<o);
		}

	template<typename U>
		tripple operator>>(const U &o)
		{
			return tripple<T1, T2, T3>(x>>o, y>>o, z>>o);
		}

	template<typename U>
		tripple& operator<<=(const U &o)
		{
			x<<=o; y<<=o; z<<=o;
			return *this;
		}

	template<typename U>
		tripple& operator>>=(const U &o)
		{
			x>>=o; y>>=o; z>>=o;
			return *this;
		}

	template<typename U1, typename U2, typename U3>
		tripple operator<<(const tripple<U1, U2, U3> &_t)
		{
			return tripple<T1, T2, T3>(x<<_t.x, y<<_t.y, z<<_t.z);
		}

	template<typename U1, typename U2, typename U3>
		tripple operator>>(const tripple<U1, U2, U3> &_t)
		{
			return tripple<T1, T2, T3>(x>>_t.x, y>>_t.y, z>>_t.z);
		}

	template<typename U1, typename U2, typename U3>
		tripple& operator<<=(const tripple<U1, U2, U3> &_t)
		{
			x<<=_t.x; y<<=_t.y; z<<=_t.z;
			return *this;
		}

	template<typename U1, typename U2, typename U3>
		tripple& operator>>=(const tripple<U1, U2, U3> &_t)
		{
			x>>=_t.x; y>>=_t.y; z>>=_t.z;
			return *this;
		}

	friend ostream& operator<<(ostream &out, const tripple<T1, T2, T3> &t)
	{
		out<<t.x<<" "<<t.y<<" "<<t.z;
		return out;
	}

	friend istream& operator>>(istream &in, tripple<T1, T2, T3> &t)
	{
		in>>t.x>>t.y>>t.z;
		return in;
	}
};

template<typename T1, typename T2, typename T3>
inline bool operator==(const tripple<T1, T2, T3> &a, const tripple<T1, T2, T3> &b)
{
	return a.x==b.x && a.y==b.y && a.z==b.z;
}

template<typename T1, typename T2, typename T3>
inline bool operator<(const tripple<T1, T2, T3> &a, const tripple<T1, T2, T3> &b)
{
	return a.x<b.x || ( !(b.x<a.x) && (b.y<a.y || ( !(b.y<a.y) && a.z<b.z) ) );
}

template<typename T1, typename T2, typename T3>
inline bool operator!=(const tripple<T1, T2, T3> &a, const tripple<T1, T2, T3> &b)
{
	return !(a==b);
}

template<typename T1, typename T2, typename T3>
inline bool operator>(const tripple<T1, T2, T3> &a, const tripple<T1, T2, T3> &b)
{
	return b<a;
}

template<typename T1, typename T2, typename T3>
inline bool operator<=(const tripple<T1, T2, T3> &a, const tripple<T1, T2, T3> &b)
{
	return !(b<a);
}

template<typename T1, typename T2, typename T3>
inline bool operator>=(const tripple<T1, T2, T3> &a, const tripple<T1, T2, T3> &b)
{
	return !(a<b);
}

template<typename T1, typename T2, typename T3>
void swap(const tripple<T1, T2, T3> &a, const tripple<T1, T2, T3> &b)
{
	swap(a.x,b.x); swap(a.y,b.y); swap(a.z,b.z);
}

using LL   = long long;
using uLL  = unsigned long long;
using uint = unsigned int;
using DB   = double;
using LDB  = long double;
using u32  = unsigned int;
using u16  = unsigned short;
using u64  = unsigned long long;

using PII = pair<int,int>;
using PLI = pair<LL,int>;
using PIL = pair<int,LL>;
using PLL = pair<LL,LL>;

using TIII = tripple<int,int,int>;
using TIIL = tripple<int,int,LL>;
using TILI = tripple<int,LL,int>;
using TILL = tripple<int,LL,LL>;
using TLII = tripple<LL,int,int>;
using TLIL = tripple<LL,int,LL>;
using TLLI = tripple<LL,LL,int>;
using TLLL = tripple<LL,LL,LL>;

using VI  = vector<int>;
using VL  = vector<LL>;
using QI  = queue<int>;
using QL  = queue<LL>;
using STI = stack<int>;
using STL = stack<LL>;
using PQI = priority_queue<int>;
using PQL = priority_queue<LL>;
using DQI = deque<int>;
using DQL = deque<LL>;

using MII = map<int,int>;
using MLI = map<LL,int>;
using MIL = map<int,LL>;
using MLL = map<LL,LL>;
using MSI = map<string,int>;
using MSL = map<string,LL>;
using SI  = set<int>;
using SL  = set<LL>;
using HASHSI  = unordered_set<int>;
using HASHSL  = unordered_set<LL>;
using HASHMII = unordered_map<int,int>;
using HASHMLI = unordered_map<LL,int>;
using HASHMIL = unordered_map<int,LL>;
using HASHMLL = unordered_map<LL,LL>;

const short id10 = 0x7fff;
const u16   id8 = 0xffff;
const int   id17 = 0x7fffffff;
const u32   id11 = 0xffffffff;
const LL    id15 = 0x7fffffffffffffff;
const uLL   id5 = 0xffffffffffffffff;
const u32   RAND_max  = 1u<<31;
const uLL   id14 = 1uLL<<63;

const int Inf    = (1<<30)-1;
const int id18  = 0x3f3f3f3f;
const int id7  = 0x7f7f7f7f;
const LL  lInf   = (1LL<<62)-1;
const LL  id0 = 0x3f3f3f3f3f3f3f3fLL;
const LL  id19 = 0x7f7f7f7f7f7f7f7fLL;
const DB  dInf   = 1e15;

inline int rnd15() {    return rand()&id10;    }
inline int rnd16() {    return rnd15() | (rnd15()&1)<<15;    }
inline int rnd31() {    return rnd15()<<16 | rnd16();    }
inline int rnd32() {    return rnd16()<<16 | rnd16();    }
inline u32 id12(){    return ((u32)rnd16())<<16 | ((u32)rnd16());    }
inline LL  rnd63() {    return ((LL)rnd31())<<32 | ((LL)id12());    }
inline LL  rnd64() {    return ((LL)id12())<<32 | ((LL)id12());    }
inline uLL id2(){    return ((uLL)id12())<<32 | ((uLL)id12());    }
inline int rnd()   {    return rnd31();    }
inline LL  lrnd()  {    return rnd63();    }
inline u32 urnd()  {    return id12();    }
inline uLL ullrnd(){    return id2();    }
inline DB  drnd()  {    return 1.0*lrnd()/id14;    }

inline int rnd(int L, int R){
	return L<0 ? int( lrnd()%((LL)R-L+1)+L ) : rnd()%(R-L+1)+L;
}
inline LL lrnd(LL L, LL R){
	return lrnd()%(R-L+1)+L;
}
inline DB drnd(DB L, DB R){
	return drnd()*(R-L)+L;
}

inline char getch()
{
	static const int Buf=1048576;
	static char buf[Buf+1], *head=buf, *tail=buf;
	if(head==tail) *(tail= (head=buf) + fread(buf,1,Buf,stdin))=0;
	return *head++;
}

inline u32 id21()
{
	u32 ret=0; char ch=getch();
	while(ch<'0' || '9'<ch) ch=getch();
	while('0'<=ch && ch<='9') ret=(ret<<3) + (ret<<1) + ch-'0', ch=getch();
	return ret;
}

inline int rdint()
{
	int ret=0, sign=0; char ch=getch();
	while(ch!='-' && (ch<'0' || '9'<ch)) ch=getch();
	if(ch=='-') sign=1, ch=getch();
	while('0'<=ch && ch<='9') ret=(ret<<3) + (ret<<1) + ch-'0', ch=getch();
	if(sign) ret=-ret;
	return ret;
}

inline uLL id13()
{
	uLL ret=0; char ch=getch();
	while(ch<'0' || '9'<ch) ch=getch();
	while('0'<=ch && ch<='9') ret=(ret<<3) + (ret<<1) + ch-'0', ch=getch();
	return ret;
}

inline LL rdLL()
{
	LL ret=0; int sign=0; char ch=getch();
	while(ch!='-' && (ch<'0' || '9'<ch)) ch=getch();
	if(ch=='-') sign=1, ch=getch();
	while('0'<=ch && ch<='9') ret=(ret<<3) + (ret<<1) + ch-'0', ch=getch();
	if(sign) ret=-ret;
	return ret;
}

inline char rdch()
{
	char ch=getch();
	while(ch<33 || 126<ch) ch=getch();
	return ch;
}

inline int  read()   {    return rdint();    }
inline u32  readu()  {    return id21();    }
inline LL   readll() {    return rdLL();    }
inline uLL  readull(){    return id13();    }
inline char readc()  {    return rdch();    }

inline void putch(char ch, int flag=0)
{
	static const int Buf=1048576;
	static char buf[Buf+1], *head=buf, *tail=buf+Buf;
	if(head==tail || flag) fwrite(buf,1,head-buf,stdout), head=buf;
	*head++=ch;
}

void write(char ch)
{
	putch(ch);
}

void write(const string &s)
{
	for(int i=0; i<int(s.size()); i++) putch(s[i]);
}

void write(int x)
{
	static int a[13],len=0,sign=0;
	if(x==0){ putch('0'); return; }
	len=0; sign= x<0 ? 1 : 0; toabs(x);
	while(x) a[++len]=x%10, x/=10;
	if(sign) putch('-');
	while(len) putch(a[len--]+'0');
}

void write(u32 x)
{
	static int a[13],len=0;
	if(x==0){ putch('0'); return; }
	len=0;
	while(x) a[++len]=x%10, x/=10;
	while(len) putch(a[len--]+'0');
}

void write(LL x)
{
	static int a[26],len=0,sign=0;
	if(x==0){ putch('0'); return; }
	len=0; sign= x<0 ? 1 : 0; toabs(x);
	while(x) a[++len]=x%10, x/=10;
	if(sign) putch('-');
	while(len) putch(a[len--]+'0');
}

void write(uLL x)
{
	static int a[26],len=0;
	if(x==0){ putch('0'); return; }
	len=0;
	while(x) a[++len]=x%10, x/=10;
	while(len) putch(a[len--]+'0');
}

inline void flushbuf(){    putch(0,1);    }
inline void id1(){    putch('\n'); putch(0,1);    }
template<typename T> inline void writeln(T x)  {    write(x); putch('\n');    }
template<typename T> inline void id20(T x){    write(x); putch('\n'); putch(0,1);    }

const int USEFILE = 0;
const int id9 = 1;
const int id4 = 0;

void usefile()
{
	freopen(".in", "r", stdin);
	freopen(".out", "w", stdout);
}

void INIT()
{
	
	return;
}

int id3()
{
	LL n,K;
	cin>>n>>K;
	VL a(n+10,0), sum(n+10,0);
	for(int i=1; i<=n; i++) cin>>a[i];
	partial_sum(a.begin(), a.end(), sum.begin());

	LL tot=sum[n-1];
	for(int i=n; i>1; i--)
	{


		if(tot < (100*a[i]+K-1)/K)
		{
			sum[1]+=(100*a[i]+K-1)/K - tot;
			tot=(100*a[i]+K-1)/K;
		}
		tot-=a[i-1];
	}

	cout<<sum[1]-a[1]<<endl;

	return 0;
}

int main()
{
	ios::sync_with_stdio(false);
	srand((uLL)(new char));

	INIT();

	if(USEFILE) usefile();

	int T=id4 ? Inf : 1;
	if(id9) cin>>T;
	while(T-- && id3()==0);

	return 0;
}