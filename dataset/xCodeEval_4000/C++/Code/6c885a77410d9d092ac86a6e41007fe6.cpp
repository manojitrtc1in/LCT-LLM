



































namespace ab{
	
struct H{
	static const int mod1 = 1000000007;
	static const int mod2 = 1000000009;
	H(int hh1, int hh2) : h1(hh1), h2(hh2) {}
	H() : h1(0), h2(0) {}
	H(int x) : h1(x%mod1), h2(x%mod2) {}
	int h1,h2;
	H& operator+=(const H& o){
		h1 = (h1+o.h1)%mod1;
		h2 = (h2+o.h2)%mod2;
		return *this;
	}
	H operator+(const H& o)const{
		return H(*this)+=o;
	}
	H& operator-=(const H& o){
		h1 = (mod1+h1-o.h1)%mod1;
		h2 = (mod2+h2-o.h2)%mod2;
		return *this;
	}
	H operator-(const H& o)const{
		return H(*this)-=o;
	}
	H& operator*=(const H& o){
		h1 = (1LL*h1*o.h1)%mod1;
		h2 = (1LL*h2*o.h2)%mod2;
		return *this;
	}
	H operator*(const H& o)const{
		return H(*this)*=o;
	}
	
	bool operator==(const H& o)const{
		return h1==o.h1 and h2==o.h2;
	}
	
	bool operator!=(const H& o)const{
		return !operator==(0);
	}
};

}



#if __cplusplus >= 201103L
#include <unordered_map>
namespace std{
#else
#include <ext/hash_map>
namespace __gnu_cxx{
#endif

template<> struct hash<ab::H>{
	size_t operator()(const ab::H& h)const{
		return h.h1^h.h2;
	}
};

}




#define F(i,n) for(int i=0; i<(int)(n); ++i)
#define FO(i,a,b) for(int i=(a); i<(int)(b); ++i)
#define OF(i,a,b) for(int i=(int)(b)-1;i>=(int)(a);--i)
#define FE(it,c)  for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); ++it)
#define FER(it,c) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); )
#define ALL(c) (c).begin(),(c).end()
#define ZERO(c) memset(c,0,sizeof(c))

#define bac back()
#define fro front()
#define no1 first
#define no2 second
#define siz size()
#define ins insert







#define mp make_pair
#define it iterator
#define be begin()
#define en end()
#define sz size()
#define fi first
#define se second
#define pub push_back
#define puf push_front
#define pob pop_back()
#define pof pop_front()
#define bs binary_search
#define lb lower_bound
#define ub upper_bound

#define si (int)

#define fo3(i,a,b) for(int i=(int)(a); i<(int)(b); ++i)
#define of3(i,a,b) for(int i=(int)((b)-1); i>=(int)(a); --i)

#define fo2(i,n) fo3(i,0,n)
#define of2(i,n) of3(i,0,n)

#define fo(...) VA_SEL(fo,__VA_ARGS__)
#define of(...) VA_SEL(of,__VA_ARGS__)

#define inl		inline __attribute__ ((always_inline))
#define ninl	__attribute__ ((noinline))








#define _CAT(a,b) a##b
#define CAT(a,b) _CAT(a,b)
#define _10TH(a,b,c,d,e,f,g,h,i,CNT,...) CNT
#define VA_CNT(...) _10TH(__VA_ARGS__,9,8,7,6,5,4,3,2,1)
#define VA_SEL(a,...) CAT(a,VA_CNT(__VA_ARGS__))(__VA_ARGS__)

#define _VA_GTONE(...) _10TH(__VA_ARGS__,1,1,1,1,1,1,1,1,0)
#define VA_GTONE(a,...) CAT(a,_VA_GTONE(__VA_ARGS__))(__VA_ARGS__)

#define foreach(e,c) for(__typeof((c).begin())e=(c).begin();e!=(c).end();++e)


#define MIN_GCC(a,b,c) (__GNUC__ > (a) || \
              (__GNUC__ == (a) && (__GNUC_MINOR__ > (b) || \
                                 (__GNUC_MINOR__ == (b) && \
								 __GNUC_PATCHLEVEL__ >= (c)))))



								  
								  




#if MIN_GCC(4,1,3)
#include<bits/stdc++.h>
#else
#include<vector>
#include<map>
#include<queue>
#include<algorithm>
#include<string>
#include<stdint.h>
#include<cstring>
#include<iostream>
#endif






#include<stdint.h>

#include<utility>



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
typedef std::vector<i32> vi;

typedef unsigned int uint;
typedef unsigned short ushort;
typedef unsigned char uchar;


namespace ab{


struct Void {};


template<typename I>struct FloatFrom{typedef Void R;};
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

template<typename I>struct Double{typedef Void R;};
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
#undef FASTIO

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



#define  L0(str) 			fprintf(stderr,"%s:%d - " str "\n",__FILE__,__LINE__)
#define  L1(str,...)		fprintf(stderr,"%s:%d - " str "\n",__FILE__,__LINE__,__VA_ARGS__)

#define L(...) VA_GTONE(L,__VA_ARGS__)

#ifdef NDEBUG

#define DE if(0)
#define ASS(x)
#define FLOAT_OK(x)
#define ASSERT_FLOAT(x)

#else

#include<cassert>
#define ASS(x) assert(x);

#define FLOAT_OK(x) ((x) <= LDBL_MAX && (x) >= -LDBL_MAX)
#define ASSERT_FLOAT(f) A(FLOAT_OK(f))

#define DE

#endif

#define V(x) (E<<#x<<": "<<(x)<<N)
#define XX {E<<"XX LINE "<<__LINE__<<N;}

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

#define TYP(x) __typeof(x)

const char N='\n';
const char S=' ';

using namespace std;
using namespace __gnu_cxx;

namespace ab{}
using namespace ab;



template<class T>inline T cbitl(T x,int i){return (x<<i) ^ (x>>(sizeof(T)*8-i));}



#if __cplusplus >= 201103L
namespace std{
#else
#include <ext/hash_map>
namespace __gnu_cxx{
template<class K, class V> class unordered_map : public hash_map<K,V>{
public:
	typename hash_map<K,V>::iterator erase(const typename hash_map<K,V>::iterator& it){
		typename hash_map<K,V>::iterator r = it;
		++r;
		if(r!=hash_map<K,V>::en){
			K key = r->fi;
			hash_map<K,V>::erase(it);
			return hash_map<K,V>::find(key);
		}
		else{
			hash_map<K,V>::erase(it);
			return r;
		}
	}
	typename hash_map<K,V>::size_type erase(const K& key){
		return hash_map<K,V>::erase(key);
	}
};
#endif





template<>template<class A,class B>struct hash<map<A,B> >{
    size_t operator()(const map<A,B>& m) const{
        size_t r = m.size();
        if(!r)return 0;
        TYP(m.be) i=m.be;
        r^=hash<TYP(i)>()(i);
        ++i;
        r^=cbitl(hash<TYP(i)>()(*i),sizeof(r)*8/4);
        i=m.end();
        --i;
        r^=cbitl(hash<TYP(i)>()(*i),sizeof(r)*8/2);
        return r;
    }
};
template<>template<class A, class B>struct hash<pair<A,B> >{
    size_t operator()(const pair<A,B>& p) const{
        return hash<A>()(p.first) ^ cbitl(hash<B>()(p.second),sizeof(size_t)*8/2);
    }
};
}

#define ri _rint()
#define rui _ruint()
#define rll _rll()
#define rull _rull()
#define rchar _rchar()
#define rstr _rstr()

#ifndef FASTIO
inline void _fin(int){}
inline void _fout(int){}
#ifdef IOSTREAM
inline int _rint(){int r;cin>>r;return r;}
inline uint _ruint(){uint r;cin>>r;return r;}
inline ull _rull(){ull r;cin>>r;return r;}
inline char _rchar(){return cin.get();}
inline string _rstr(){string s;cin>>s;return s;}
template<typename T>inline void W(const T& i){cout<<i;}
inline void W(){W('\n');}
#else
inline int _rint(){int r;scanf("%d",&r);return r;}
inline uint _ruint(){uint r;scanf("%u",&r);return r;}
inline ull _rull(){ull r;scanf("%llu",&r);return r;}
inline ull _rll(){ll r;scanf("%lld",&r);return r;}
inline char _rchar(){return getchar();}
inline string _rstr(){
	string s;
	char c=rchar;
	while(c!=-1 && !isgraph(c))c=rchar;
	for(;;){
		if(!isgraph(c))break;
		s+=c;
		c=rchar;
	}
	return s;
}
inline void W(char a='\n'){printf("%c",a);}
inline void W(const string&s){printf("%s",s.c_str());}
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
char _iB[_IB];int _iP = _IB;
char _oB[_OB];int _oP = 0;
inline void _fin(int mc){
	int r=_IB-_iP;
	if(r>mc)return;
	F(i,r) _iB[i]=_iB[i+_iP];	

    int rd=FREAD(_iB+r,1,_iP,stdin);
	if(rd!=_iP) _iB[r+rd]=0;
	_iP = 0;
}
inline void _fout(int mc){
	if(_OB-_oP>mc)return;
	FWRITE(_oB,1,_oP,stdout);
	_oP = 0;
}
inline void _W(char c='\n'){_oB[_oP++]=c;} 

inline char _rc(){return _iB[_iP++];}
inline char _rchar(){_fin(1);return _rc();}
inline string _rstr(){
	string s;
	for(;;){
		char c=rchar;
		if(!isprint(c)||isspace(c))break;
		s+=c;
	}
	return s;
}
template<class T>inline T _rur(){ 

    T r=0;char c=_rc();
    do c-='0',r=r*10+c,c=_rc();while(c>='0');
    return r;}
template<class T>inline T _rsi(){ 

	char c=_rc();
	while(c<'-')c=_rc();
	if(c=='-')return -_rur<T>();
	else{--_iP;return _rur<T>();}}
template<class T>inline T _ru(){  

	while(_rc()<'0');--_iP;
	return _rur<T>();
}

inline int _rint(){_fin(15);return _rsi<int>();}
inline uint _ruint(){_fin(15);return _ru<uint>();}
inline ll _rll(){_fin(25);return _rsi<ll>();}
inline ull _rull(){_fin(25);return _ru<ull>();}

const int _rs = 20; char _r[_rs];
template<class T>inline void _w(T i){	

	if(numeric_limits<T>::is_signed and i<0) _W('-'), i=-i;
	else if(i==0){_W('0'); return;}
	int pos = _rs;
	do _r[--pos]='0'+i%10, i/=10; while(i);
	do _W(_r[pos++]); while(pos<_rs);
}
inline void W(const char c){_fout(2);_W(c);}
inline void W(const int32_t& i){_fout(15);_w(i);}
inline void W(const uint32_t& i){_fout(15);_w(i);}
inline void W(const int64_t& i){_fout(25);_w(i);}
inline void W(const uint64_t& i){_fout(25);_w(i);}
inline void W(const char*str, int l){
	for(int b=0; b<l; b+=_OB){
		int num = min(_OB,l-b);
		_fout(num);
		memcpy(&_oB[_oP], str+b, num);
		_oP+=num;
	}
}
inline void W(const char*str){W(str,strlen(str));}
inline void W(const string&s){W(s.c_str(),s.siz);}
inline void W(double d){_fout(50);_oP+=sprintf(&_oB[_oP],"%.20f",d);}	

#endif
template<class A,class B>inline void W(const A&a,const B&b){W(a);W(b);}
template<class A,class B,class C>
inline void W(const A&a,const B&b,const C&c){W(a);W(b);W(c);}
template<class A,class B,class C,class DD>
inline void W(const A&a,const B&b,const C&c,const DD&dd){W(a);W(b);W(c);W(dd);}
template<class T>inline void sortall(T&t){sort(t.be,t.en);}
template<class T>inline void uniqall(T&t){t.resize(unique(t.be,t.en)-t.be);}

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
template<class A,class B>inline ostream&operator<<(ostream&o,const map<A,B>&m){o<<N;FE(k,m)o<<"map["<<k->fi<<"] -> "<<k->se<<N;return o;}
template<class A>inline ostream&operator<<(ostream&o,const vector<A>&_v){o<<N;fo(i,_v.sz)o<<"vector["<<i<<"] = "<<_v[i]<<N;return o;}

struct _O{template<class T>_O&operator<(const T&_t){oc(1);W(_t);oc(0);return*this;}}O;
struct _I{
	_I&operator>(int32_t&_t){_t=ri;return*this;}
	_I&operator>(uint32_t&_t){_t=rui;return*this;}
	_I&operator>(int64_t&_t){_t=rll;return*this;}
	_I&operator>(uint64_t&_t){_t=rull;return*this;}
	_I&operator>(char&_t){_t=rchar;return*this;}
	_I&operator>(string&_t){_t=rstr;return*this;}
}I;

struct _E{template<class T>_E&operator<(const T&t){DE{ec(1);cerr<<t;ec(0);}return*this;}}E;



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






vi operator*(const vi& a, const vi& b){
	vi r(a);
	F(i,a.siz) r[i] = a[b[i]];
	return r;
}

vi fpow(vi a, int e){
	vi r;
	F(i,a.siz)r.pub(i);
	while(e)if(e%2==0)a=a*a,e/=2;
	else r=r*a,--e;
	return r;
}

void tc(){

	string s = rstr;
	int n=s.siz;
	
	vi sperm;
	F(i,n-1)sperm.pub(i+1);
	sperm.pub(0);
	
	int m = ri;
	F(i,m){
		int k=ri;
		int d=ri;
		
		vi perm;
		F(j,k)perm.pub(j);
		sort(ALL(perm),[&](int a, int b){int aa=a%d; int bb=b%d; if(aa!=bb)return aa<bb; return a<b;});
		FO(j,k,n)perm.pub(j);
		
		vi res = perm * fpow(sperm*perm, n-k+1-1) * fpow(sperm,k);
		string ss(s);
		F(j,n)ss[j]=s[res[j]];
		s=ss;
		O<s<N;
	}
}


