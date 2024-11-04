


































#include<cstdint>
#include<utility>

namespace ab{

typedef int8_t i8;
typedef uint8_t ui8;
typedef int16_t i16;
typedef uint16_t ui16;
typedef int32_t i32;
typedef uint32_t ui32;
typedef int64_t i64;
typedef uint64_t ui64;




typedef i64 ll;
typedef ui64 ull;

typedef std::pair<i32,i32> pii;

typedef unsigned int uint;
typedef unsigned short ushort;
typedef unsigned char uchar;

struct VOID {};


template<typename I>struct FloatFrom{typedef VOID R;};
template<>struct FloatFrom<i32>{typedef double R;};
template<>struct FloatFrom<ui32>{typedef double R;};
template<>struct FloatFrom<i64>{typedef long double R;};
template<>struct FloatFrom<ui64>{typedef long double R;};
template<>struct FloatFrom<i16>{typedef float R;};
template<>struct FloatFrom<ui16>{typedef float R;};
template<>struct FloatFrom<i8>{typedef float R;};
template<>struct FloatFrom<ui8>{typedef float R;};
template<>struct FloatFrom<float>{typedef float R;};
template<>struct FloatFrom<double>{typedef double R;};
template<>struct FloatFrom<long double>{typedef long double R;};

template<typename I>struct Double{typedef VOID R;};
template<>struct Double<i8>{typedef i16 R;};
template<>struct Double<ui8>{typedef ui16 R;};
template<>struct Double<i16>{typedef i32 R;};
template<>struct Double<ui16>{typedef ui32 R;};
template<>struct Double<i32>{typedef i64 R;};
template<>struct Double<ui32>{typedef ui64 R;};

template<>struct Double<float>{typedef float R;};
template<>struct Double<double>{typedef double R;};
template<>struct Double<long double>{typedef long double R;};


#if defined __GNUC__ and ( __WORDSIZE == 64 )
typedef int128_t i128;
typedef uint128_t ui128;
template<>struct Double<i64>{typedef i128 R;};
template<>struct Double<ui64>{typedef ui128 R;};
#endif


}

#define FASTIO

#ifdef NO_FASTIO
#undef FASTIO
#endif

#ifdef DEBUG
#undef NDEBUG
#pragma message "Compiling in DEBUG mode."

#ifdef _WIN32
#include<windows.h>
inline void ec(int a){static HANDLE h=GetStdHandle(-12);SetConsoleTextAttribute(h,a?12:0xf);}
inline void oc(int a){static HANDLE h=GetStdHandle(-11);SetConsoleTextAttribute(h,a?10:0xf);}
#else


#endif

#else
#define NDEBUG
#define ec(x)
#define oc(x)
#endif



#include <cstdio>
#include <cfloat>



#define _CAT(a,b) a##b
#define CAT(a,b) _CAT(a,b)
#define _10TH(a,b,c,d,e,f,g,h,i,CNT,...) CNT
#define VA_CNT(...) _10TH(__VA_ARGS__,9,8,7,6,5,4,3,2,1)
#define VA_SEL(a,...) CAT(a,VA_CNT(__VA_ARGS__))(__VA_ARGS__)

#define _VA_GTONE(...) _10TH(__VA_ARGS__,1,1,1,1,1,1,1,1,0)
#define VA_GTONE(a,...) CAT(a,_VA_GTONE(__VA_ARGS__))(__VA_ARGS__)

#define foreach(e,c) for(auto&e:c)

#define  L0(str) 			fprintf(stderr,"%s:%d - " str "\n",__FILE__,__LINE__)
#define  L1(str,...)		fprintf(stderr,"%s:%d - " str "\n",__FILE__,__LINE__,__VA_ARGS__)

#define L(...) VA_GTONE(L,__VA_ARGS__)

#ifdef NDEBUG

#define D if(0)
#define A(x)
#define TEST_FLOAT(x)
#define ASSERT_FLOAT(x)

#else

#define A(x) assert(x);

#define _TEST_FLOAT(x) ((x) <= LDBL_MAX && (x) >= -LDBL_MAX)
#define ASSERT_FLOAT(f) A(_TEST_FLOAT(f))

#define D

#endif

#define V(x) (E<<#x<<": "<<(x)<<N)
#define X {E<<"X LINE "<<__LINE__<<N;}

#if defined DEBUG or defined ASSERTS
#undef NDEBUG
#else
#define NDEBUG
#endif

#ifdef _WIN32



#ifndef NO_UNLOCKED
#define NO_UNLOCKED
#endif






#endif



#include<bits/stdc++.h>

#define mp make_pair
#define it iterator
#define be begin()
#define en end()
#define sz size()
#define fi first
#define se second
#define all(x) (x).begin(),(x).end()
#define bs binary_search
#define lb lower_bound
#define ub upper_bound
#define type(x) __typeof(x)

#define fo3(i,a,b) for(int i=(int)(a); i<(int)(b); ++i)
#define of3(i,a,b) for(int i=(int)((b)-1); i>=(int)(a); --i)

#define fo2(i,n) fo3(i,0,n)
#define of2(i,n) of3(i,0,n)

#define fo(...) VA_SEL(fo,__VA_ARGS__)
#define of(...) VA_SEL(of,__VA_ARGS__)

#define inl		inline __attribute__ ((always_inline))
#define ninl	__attribute__ ((noinline))

const char N='\n';
const char S=' ';

using namespace std;
using namespace __gnu_cxx;

namespace ab{}
using namespace ab;



template<class T>inline T cbitl(T x,int i){return (x<<i) ^ (x>>(sizeof(T)*8-i));}

namespace std{


template<>template<class A,class B>struct hash<map<A,B>>{
    size_t operator()(const map<A,B>& m) const{
        size_t r = m.size();
        if(!r)return r;
        auto i=m.be;
        r^=hash<type(i)>()(i);
        ++i;
        r^=cbitl(hash<type(i)>()(*i),sizeof(r)*8/4);
        i=m.end();
        --i;
        r^=cbitl(hash<type(i)>()(*i),sizeof(r)*8/2);
        return r;
    }
};
template<>template<class A, class B>struct hash<pair<A,B>>{
    size_t operator()(const pair<A,B>& p) const{
        return hash<A>()(p.first) ^ cbitl(hash<B>()(p.second),sizeof(size_t)*8/2);
    }
};
}

#define rint _rint()
#define ruint _ruint()
#define rll _rll()
#define rull _rull()
#define rchar _rchar()

#ifndef FASTIO
inline void fin(int){}inline void fout(int){}
#ifdef IOSTREAM
inline int _rint(){int r;cin>>r;return r;}
inline uint _ruint(){uint r;cin>>r;return r;}
inline ull _rull(){ull r;cin>>r;return r;}
inline char _rchar(){return cin.get();}
template<typename T>inline void W(const T& i){cout<<i;}
inline void W(){W('\n');}
#else
inline int _rint(){int r;scanf("%d",&r);return r;}
inline uint _ruint(){uint r;scanf("%u",&r);return r;}
inline ull _rull(){ull r;scanf("%llu",&r);return r;}
inline ull _rll(){ll r;scanf("%lld",&r);return r;}
inline char _rchar(){return getchar();}
inline void W(char a='\n'){printf("%c",a);}
inline void W(int a){printf("%d",a);}
inline void W(uint a){printf("%u",a);}
inline void W(const ull& a){printf("%llu",a);}
inline void W(const ll& a){printf("%lld",a);}
inline void W(const char *str){fputs(str,stdout);}
inline void W(const double& d){printf("%.20f",d);}
inline void W(const long double& d){printf("%.50Lf",d);}
#endif
#else

#ifndef NO_UNLOCKED
#define FREAD fread_unlocked
#define FWRITE fwrite_unlocked
#else
#define FREAD fread
#define FWRITE fwrite
#endif



const int _IB=32768;const int _OB=32768;
char _iB[_IB];int _iP = _IB;char _oB[_OB];int _oP = 0;
inline void fin(int mc){int r=_IB-_iP;if(r>mc)return;fo(i,r)_iB[i]=_iB[i+_iP];
    FREAD(_iB+r,1,_iP,stdin);_iP = 0;}
inline void fout(int mc){if(_OB-_oP>mc)return;FWRITE(_oB,1,_oP,stdout);_oP = 0;}
inline void W(char c='\n'){_oB[_oP++]=c;}
inline char _rchar(){return _iB[_iP++];}
template<class T>inline T _rur(){
    T r=0;char c=rchar;
    do c-='0',r=r*10+c,c=rchar;while(c>='0');
    return r;}
template<class T>inline T _rsi(){
	char c=rchar;
	while(c<'-')c=rchar;
	if(c=='-')return -_rur<T>();
	else{--_iP;return _rur<T>();}}
template<class T>inline T _ru(){while(rchar<'0');--_iP;return _rur<T>();}

inline int _rint(){fin(15);return _rsi<int>();}
inline uint _ruint(){fin(15);return _ru<uint>();}
inline ll _rll(){fin(25);return _rsi<ll>();}
inline ull _rull(){fin(25);return _ru<ull>();}

const int _rs = 20;char _r[_rs];
template<class T>inline void _w(T i){
	if(numeric_limits<T>::is_signed && i<0)W('-'),i=-i;
	else if(i==0){W('0');return;}
	int pos = _rs;
	do{_r[--pos]='0'+i%10;i/=10;}while(i);
	do W(_r[pos]),++pos;while(pos<_rs);}
inline void W(const int32_t& i){fout(15);_w(i);}
inline void W(const uint32_t& i){fout(15);_w(i);}
inline void W(const int64_t& i){fout(25);_w(i);}
inline void W(const uint64_t& i){fout(25);_w(i);}
inline void W(const char*str){int l=strlen(str);fout(l);memcpy(&_oB[_oP],str,l);_oP+=l;}
inline void W(double d){fout(50);_oP+=sprintf(&_oB[_oP],"%.20f",d);}	

#endif
template<class A,class B>inline void W(const A&a,const B&b){W(a);W(b);}
template<class A,class B,class C>
inline void W(const A&a,const B&b,const C&c){W(a);W(b);W(c);}
template<class A,class B,class C,class DD>
inline void W(const A&a,const B&b,const C&c,const DD&dd){W(a);W(b);W(c);W(dd);}
template<class T>inline void sortall(T&t){sort(t.be,t.en);}
template<class T>inline void uniqueall(T&t){t.resize(unique(t.be,t.en));}

inline int count1(uint i){return __builtin_popcount(i);}
inline int count1(ull i){return __builtin_popcountll(i);}
inline int parity(uint i){return __builtin_parity(i);}
inline int parity(ull i){return __builtin_parityll(i);}
inline int ilog(uint i){return 31-__builtin_clz(i);} 

inline int ilog(ull i){return 63-__builtin_clzll(i);}
#define powerof2(x) !(x&(x-1))
#define subset(a,b) (a&b==a)
#define kbegin(k) ((1<<k)-1)
#define kend(k,n) ((kbegin(k)<<n-k)+1)
inline uint knext(uint a){uint b=(a|(a-1))+1;return b|((a^b)>>(__builtin_ctz(a)+2));}
#define fors(x,k,n) for(uint x=kbegin(k);x<kend(k,n);x=knext(x))


template<class A,class B>inline ostream&operator<<(ostream&o,const pair<A,B>&p){o<<'<'<<p.fi<<", "<<p.se<<'>';return o;}
template<class A,class B>inline ostream&operator<<(ostream&o,const map<A,B>&m){o<<N;for(auto&k:m)o<<"map["<<k.fi<<"] -> "<<k.se<<N;return o;}
template<class A>inline ostream&operator<<(ostream&o,const vector<A>&v){o<<N;fo(i,v.sz)o<<"vector["<<i<<"] = "<<v[i]<<N;return o;}

struct _O{template<class T>_O&operator<<(const T&t){oc(1);W(t);oc(0);return*this;}}O;
struct _I{
	_I&operator>>(int32_t&t){t=rint;return*this;}
	_I&operator>>(uint32_t&t){t=ruint;return*this;}
	_I&operator>>(int64_t&t){t=rll;return*this;}
	_I&operator>>(uint64_t&t){t=rull;return*this;}
}I;

struct _E{template<class T>_E&operator<<(const T&t){D{ec(1);cerr<<t;ec(0);}return*this;}}E;



inline void tc();
int main()
{
#ifdef FASTIO
    setvbuf(stdin,0,_IONBF,0);setvbuf(stdout,0,_IONBF,0);
#elif defined IOSTREAM
	ios_base::sync_with_stdio(0);cin.tie(0);cout.precision(99);cout.setf(ios::fixed,ios::floatfield);
#endif

#ifdef DEBUG
#ifdef _WIN32
	ec(0);
	oc(0);
#else


#endif
#endif
	
#ifdef READ_NUM_TEST_CASES
	int nz=rint;fo(i,nz)
#endif
	tc();
#ifdef FASTIO
    FWRITE(_oB,1,_oP,stdout);
#endif
	return 0;
}








#include<type_traits>

namespace ab{


template<bool xsorted, class ITER>
auto closest2d(const ITER& begin, const ITER& end) -> typename FloatFrom<decltype(begin->second)>::R
{
	typedef typename std::remove_reference<decltype(*begin)>::type Point;
	if(!xsorted) sort(begin,end,[](const Point& p1, const Point& p2){return p1.first < p2.first;});
	
	uint size = end-begin;
	vector<Point> temp(size);
	
	typedef decltype(Point::first) F;
	typename FloatFrom<F>::R result = numeric_limits<typename FloatFrom<F>::R>::max();
	
	for(uint d=1; d<size; d<<=1){
		for(uint ii=0; ii+d<size; ii+=2*d){
			auto i0 = begin + ii;
			auto i1 = i0 + d;
			auto i2 = min(i1 + d,end);
			
			auto i = i0;
			auto j = i1;
			
			F a = (j-1)->first;
			F b = (j)->first;
			
			typename Double<F>::R best = numeric_limits<typename Double<F>::R>::max();
			
			

			auto emin = numeric_limits<F>::max();
			auto emax = -numeric_limits<F>::max();	

			
			

			for(; i!=i1 && i->second != numeric_limits<F>::max(); ++i){
				emin = min(emin,i->first);
				if(i->first < b-result)continue;
				while(j!=i2 && j->second != numeric_limits<F>::max() && (j)->second + result < (i)->second){
					emax = max(emax, j->first);
					++j;
				}
				for(auto jj=j; jj!=i2 && jj->second!=numeric_limits<F>::max() && (jj)->second - result <= (i)->second; ++jj){
					if(jj->first > a+result)continue;
					typename Double<F>::R dy = (jj)->second - (i)->second;
					typename Double<F>::R dx = (jj)->first - (i)->first;
					typename Double<F>::R cand2 = dy*dy + dx*dx;
					best = min(best,cand2);
				}
			}
			while(j!=i2 && j->second != numeric_limits<F>::max()){
				emax = max(emax, j->first);
				++j;
			}
			result = min(result, sqrt(best));
			
			

			i=i0;
			j=i1;
			auto t=temp.begin();
			for(;;){
				if(i->first > emin+result){
					++i;
				} else if(j->first < emax-result){
					++j;
				} else if((i)->second < (j)->second) *(t++) = *(i++);
				else *(t++)=*(j++);
				if(i==i1 || i->second==numeric_limits<F>::max()){
					while(j!=i2 && j->second!=numeric_limits<F>::max())*(t++)=*(j++);
					break;
				} else if(j==i2 || j->second==numeric_limits<F>::max()){
					while(i!=i1 && i->second!=numeric_limits<F>::max())*(t++)=*(i++);
					break;
				}
			}
			copy(temp.begin(), t, i0);
			if(t-temp.begin()<2*d) (i0+(t-temp.begin()))->second = numeric_limits<F>::max();
		}
	}
	return result;
}


}

int n;

pair<i32,i32> tab[100009];

inline void tc()
{
	I>>n;
	int sum=0;
	fo(i,n){
		int val = rint;
		sum += val;
		tab[i].first = i;
		tab[i].second = sum;
	}
	
	auto result = closest2d<true>(tab+0,tab+n);
	
	int r = result*result+0.5;
	
	O<<r<<N;
}
